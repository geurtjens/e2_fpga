import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
from cocotb_tools.runner import get_runner
import random

# ── Parameters — must match runner.build parameters below ─────
N             = 4
V             = N * N
VAR_BITS      = (V - 1).bit_length()   # $clog2(V) = 4 for N=4
FRAME_BITS    = VAR_BITS * V           # 4 * 16 = 64 bits
MAX_SOLUTIONS = 9                      # known upper bound for N=4

# ── Helpers ───────────────────────────────────────────────────

def pack_solution(tile_ids):
    """Pack a list of V tile IDs into a FRAME_BITS wide integer.
    Variable i occupies bits [(i+1)*VAR_BITS-1 : i*VAR_BITS].
    """
    assert len(tile_ids) == V
    frame = 0
    for i, tid in enumerate(tile_ids):
        assert 0 <= tid < V, f"tile_id {tid} out of range for VAR_BITS={VAR_BITS}"
        frame |= (tid & ((1 << VAR_BITS) - 1)) << (i * VAR_BITS)
    return frame

def unpack_solution(frame):
    """Unpack a FRAME_BITS integer into a list of V tile IDs."""
    mask = (1 << VAR_BITS) - 1
    return [(frame >> (i * VAR_BITS)) & mask for i in range(V)]

def make_solution(seed=None):
    """Generate a random valid solution — a permutation of tile IDs 0..V-1."""
    rng = random.Random(seed)
    tiles = list(range(V))
    rng.shuffle(tiles)
    return tiles

async def do_reset(dut):
    """Apply synchronous reset for 2 cycles."""
    dut.rst.value        = 1
    dut.store.value      = 0
    dut.wdata.value      = 0
    dut.read_en.value    = 0
    dut.read_index.value = 0
    await ClockCycles(dut.clk, 2)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

async def store_solution(dut, tile_ids):
    """Store a solution — pulse store high for one cycle.
    Waits an extra cycle after the pulse so solution_count
    has settled before the caller samples it.
    """
    dut.wdata.value = pack_solution(tile_ids)
    dut.store.value = 1
    await RisingEdge(dut.clk)   # store is registered on this edge
    dut.store.value = 0
    dut.wdata.value = 0
    await RisingEdge(dut.clk)   # counter output now stable

async def read_solution(dut, index):
    """Read solution at index. Returns tile_ids after one cycle M10K latency."""
    dut.read_index.value = index
    dut.read_en.value    = 1
    await RisingEdge(dut.clk)   # address registered on this edge
    dut.read_en.value = 0
    await RisingEdge(dut.clk)   # M10K registered output now stable
    assert dut.read_valid.value == 1, "read_valid did not pulse on expected cycle"
    return unpack_solution(int(dut.rdata.value))

# ── Tests ─────────────────────────────────────────────────────

@cocotb.test()
async def test_reset(dut):
    """After reset: counter is 0, not full, read_valid low."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    assert int(dut.solution_count.value) == 0, "solution_count should be 0 after reset"
    assert int(dut.store_full.value)     == 0, "store_full should be 0 after reset"
    assert int(dut.read_valid.value)     == 0, "read_valid should be 0 after reset"
    cocotb.log.info("reset ✓")

@cocotb.test()
async def test_store_single(dut):
    """Store one solution and read it back — verify all tile IDs match."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    tile_ids = make_solution(seed=42)
    await store_solution(dut, tile_ids)

    assert int(dut.solution_count.value) == 1, "solution_count should be 1"
    assert int(dut.store_full.value)     == 0, "store should not be full after 1 solution"

    readback = await read_solution(dut, 0)
    assert readback == tile_ids, \
        f"Tile ID mismatch:\n  wrote: {tile_ids}\n  read:  {readback}"
    cocotb.log.info(f"store single ✓ tile_ids={tile_ids}")

@cocotb.test()
async def test_store_multi(dut):
    """Store several solutions and verify each reads back correctly."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    solutions = [make_solution(seed=i) for i in range(5)]
    for s in solutions:
        await store_solution(dut, s)

    assert int(dut.solution_count.value) == 5

    for idx, expected in enumerate(solutions):
        readback = await read_solution(dut, idx)
        assert readback == expected, \
            f"Solution {idx} mismatch:\n  wrote: {expected}\n  read:  {readback}"
        cocotb.log.info(f"  solution[{idx}] ✓ {readback}")

    cocotb.log.info("store multi ✓")

@cocotb.test()
async def test_store_full(dut):
    """Fill store, then overflow — count increments but RAM unchanged."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    solutions = [make_solution(seed=i) for i in range(MAX_SOLUTIONS)]
    for s in solutions:
        await store_solution(dut, s)

    assert int(dut.solution_count.value) == MAX_SOLUTIONS
    assert int(dut.store_full.value)     == 1, "store_full should be set"

    # Store two more — count increments but RAM must not change
    overflow = make_solution(seed=999)
    await store_solution(dut, overflow)
    await store_solution(dut, overflow)

    assert int(dut.solution_count.value) == MAX_SOLUTIONS + 2, \
        "Counter should reflect all solutions including overflows"

    # Verify stored solutions are unchanged
    for idx, expected in enumerate(solutions):
        readback = await read_solution(dut, idx)
        assert readback == expected, \
            f"Solution {idx} was overwritten — expected {expected}, got {readback}"

    cocotb.log.info(f"store full ✓ count={int(dut.solution_count.value)} stored={MAX_SOLUTIONS}")

@cocotb.test()
async def test_read_latency(dut):
    """read_valid is low the cycle after read_en, high exactly one cycle later."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    await store_solution(dut, make_solution(seed=7))

    dut.read_index.value = 0
    dut.read_en.value    = 1
    await RisingEdge(dut.clk)   # address registered on this edge
    dut.read_en.value = 0

    # read_valid tracks read_en delayed by one cycle —
    # must still be low here (data not yet out of RAM)
    assert int(dut.read_valid.value) == 0, \
        "read_valid should be low one cycle after read_en (M10K latency)"

    await RisingEdge(dut.clk)   # RAM output now stable
    assert int(dut.read_valid.value) == 1, \
        "read_valid should be high exactly one cycle after read_en"

    cocotb.log.info("read latency ✓")

@cocotb.test()
async def test_tile_id_extraction(dut):
    """tile_id[i] == i for all variables — verifies pack/unpack per variable."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    tile_ids = list(range(V))   # tile_id[i] = i
    await store_solution(dut, tile_ids)

    readback = await read_solution(dut, 0)
    for i in range(V):
        assert readback[i] == tile_ids[i], \
            f"Variable {i}: expected tile_id={tile_ids[i]}, got {readback[i]}"

    cocotb.log.info(f"tile ID extraction ✓ all {V} variables verified")

@cocotb.test()
async def test_consecutive_reads(dut):
    """Read multiple solutions back to back — no cross-contamination."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    solutions = [make_solution(seed=100+i) for i in range(3)]
    for s in solutions:
        await store_solution(dut, s)

    for idx in range(3):
        readback = await read_solution(dut, idx)
        assert readback == solutions[idx], \
            f"Consecutive read {idx} failed:\n  expected {solutions[idx]}\n  got      {readback}"

    cocotb.log.info("consecutive reads ✓")

# ── Runner ────────────────────────────────────────────────────

def test_SolutionStore():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/SolutionStore.sv",
        ],
        hdl_toplevel="SolutionStore",
        parameters={
            "N":             N,
            "MAX_SOLUTIONS": MAX_SOLUTIONS,
        },
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="SolutionStore",
        test_module="test_SolutionStore",
    )
