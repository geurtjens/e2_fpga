import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N         = 4
V         = N * N
ALL_VARS  = (1 << V) - 1

def not_first_col():
    mask = 0
    for r in range(N):
        for c in range(1, N):
            mask |= 1 << (r * N + c)
    return mask

def not_last_col():
    mask = 0
    for r in range(N):
        for c in range(0, N-1):
            mask |= 1 << (r * N + c)
    return mask

NOT_FIRST_COL = not_first_col()
NOT_LAST_COL  = not_last_col()

def vid(x, y): return y * N + x

def popcount(x): return bin(x).count('1')

def reference(singletons, unassigned):
    expanded = (
        ((singletons >> N) & ALL_VARS) |
        ((singletons << N) & ALL_VARS) |
        (((singletons & NOT_FIRST_COL) >> 1) & ALL_VARS) |
        (((singletons & NOT_LAST_COL)  << 1) & ALL_VARS)
    )
    return expanded & ALL_VARS & unassigned

async def check(dut, singletons, unassigned):
    dut.in_singletons.value          = singletons
    dut.in_not_first_col.value       = NOT_FIRST_COL
    dut.in_not_last_col.value        = NOT_LAST_COL
    dut.in_unassignedVariables.value = unassigned
    await Timer(1, unit="ns")
    exp = reference(singletons, unassigned)
    act = int(dut.out_candidates.value)
    assert act == exp, \
        f"singletons={singletons:#x} unassigned={unassigned:#x}\n" \
        f"  got={act:#x}\n" \
        f"  exp={exp:#x}"

@cocotb.test()
async def test_no_singletons(dut):
    """No singletons — no candidates."""
    await check(dut, 0, ALL_VARS)
    assert int(dut.out_candidates.value) == 0
    cocotb.log.info("no singletons → no candidates ✓")

@cocotb.test()
async def test_var0_singleton(dut):
    """Var 0 singleton — neighbours are var 1 (right) and var N (below)."""
    await check(dut, 1, ALL_VARS & ~1)
    act = int(dut.out_candidates.value)
    assert (act >> 1) & 1, "var 1 should be candidate"
    assert (act >> N) & 1, "var N should be candidate"
    cocotb.log.info("var 0 expands correctly ✓")

@cocotb.test()
async def test_no_right_wrap(dut):
    """Right edge singleton does not wrap to next row."""
    singleton = 1 << (N - 1)
    await check(dut, singleton, ALL_VARS & ~singleton)
    act = int(dut.out_candidates.value)
    assert not (act & 1), "var 0 should not be candidate — no row wrap"
    cocotb.log.info("no right-edge row wraparound ✓")

@cocotb.test()
async def test_no_left_wrap(dut):
    """Left edge singleton does not wrap to previous row's right end."""
    singleton = 1 << vid(0, 1)  # left edge, row 1
    await check(dut, singleton, ALL_VARS & ~singleton)
    act = int(dut.out_candidates.value)
    assert not (act >> vid(N-1, 0)) & 1, "no wrap from left edge to previous row right"
    cocotb.log.info("no left-edge row wraparound ✓")

@cocotb.test()
async def test_centre_singleton(dut):
    """Centre variable — all four neighbours should be candidates."""
    cx, cy = N // 2, N // 2
    singleton = 1 << vid(cx, cy)
    unassigned = ALL_VARS & ~singleton
    await check(dut, singleton, unassigned)
    act = int(dut.out_candidates.value)
    assert (act >> vid(cx,   cy-1)) & 1, "up neighbour should be candidate"
    assert (act >> vid(cx,   cy+1)) & 1, "down neighbour should be candidate"
    assert (act >> vid(cx-1, cy))   & 1, "left neighbour should be candidate"
    assert (act >> vid(cx+1, cy))   & 1, "right neighbour should be candidate"
    cocotb.log.info(f"centre singleton candidates={act:#x} ✓")

@cocotb.test()
async def test_already_assigned_neighbour_excluded(dut):
    """Already assigned neighbours should not appear in candidates."""
    singletons = (1 << vid(1, 1)) | (1 << vid(2, 1))
    unassigned = ALL_VARS & ~singletons
    await check(dut, singletons, unassigned)
    act = int(dut.out_candidates.value)
    assert not (act >> vid(1, 1)) & 1, "singleton itself not a candidate"
    assert not (act >> vid(2, 1)) & 1, "singleton itself not a candidate"
    cocotb.log.info("assigned neighbours excluded ✓")

@cocotb.test()
async def test_top_row_no_up_neighbour(dut):
    """Singleton on top row — up neighbour is out of bounds."""
    singleton = 1 << vid(2, 0)
    unassigned = ALL_VARS & ~singleton
    await check(dut, singleton, unassigned)
    act = int(dut.out_candidates.value)
    assert popcount(act) <= 3, \
        f"top row singleton has at most 3 neighbours, got {popcount(act)}"
    cocotb.log.info("top row — no up neighbour ✓")

@cocotb.test()
async def test_bottom_row_no_down_neighbour(dut):
    """Singleton on bottom row — down neighbour is out of bounds."""
    singleton = 1 << vid(2, N-1)
    unassigned = ALL_VARS & ~singleton
    await check(dut, singleton, unassigned)
    act = int(dut.out_candidates.value)
    assert popcount(act) <= 3, \
        f"bottom row singleton has at most 3 neighbours, got {popcount(act)}"
    cocotb.log.info("bottom row — no down neighbour ✓")

@cocotb.test()
async def test_all_assigned(dut):
    """All variables assigned — no unassigned candidates."""
    await check(dut, ALL_VARS, 0)
    assert int(dut.out_candidates.value) == 0
    cocotb.log.info("all assigned → no candidates ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(11)
    for _ in range(50):
        unassigned = random.randint(0, ALL_VARS)
        singletons = ALL_VARS & ~unassigned
        await check(dut, singletons, unassigned)
    cocotb.log.info("50 random tests ✓")

def test_ChooseNextVariable_ExpandSingletons():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/ChooseNextVariable_ExpandSingletons.sv"],
        hdl_toplevel="ChooseNextVariable_ExpandSingletons",
        parameters={"N": N, "V": V},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="ChooseNextVariable_ExpandSingletons",
        test_module="test_ChooseNextVariable_ExpandSingletons",
    )