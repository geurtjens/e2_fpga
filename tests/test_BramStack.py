import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
from cocotb_tools.runner import get_runner
import random

# ── Parameters — must match runner.build parameters below ─────
N           = 4
CC          = 6
STACK_DEPTH = 40

# ── Derived geometry (mirrors BramStack localparam) ────────────
V           = N * N
V_INTERIOR  = (N - 2) * (N - 2)
V_BORDER    = 4 * N - 4
DOMAIN_BITS = V_INTERIOR * 4 * V + V_BORDER * 1 * V
COLOUR_BITS = 4 * V * CC
MASK_BITS   = 2 * V
VAR_BITS    = (V - 1).bit_length()
FRAME_BITS  = DOMAIN_BITS + COLOUR_BITS + MASK_BITS + VAR_BITS
FRAME_MASK  = (1 << FRAME_BITS) - 1

print(f"Geometry: V={V} VAR_BITS={VAR_BITS} FRAME_BITS={FRAME_BITS}")

# ── Helpers ───────────────────────────────────────────────────

def make_frame(seed=None):
    """Generate a random non-zero FRAME_BITS wide frame value."""
    rng = random.Random(seed)
    return rng.randint(1, FRAME_MASK)

def pack_frame(state_bits, chosen_var):
    """Pack state + chosen_var into a frame word.
    chosen_var occupies [VAR_BITS-1:0], state above that.
    """
    assert 0 <= chosen_var < V
    assert state_bits < (1 << (FRAME_BITS - VAR_BITS))
    return (state_bits << VAR_BITS) | chosen_var

def unpack_frame(frame):
    """Return (state_bits, chosen_var) from a frame word."""
    chosen_var = frame & ((1 << VAR_BITS) - 1)
    state_bits = frame >> VAR_BITS
    return state_bits, chosen_var

async def do_reset(dut):
    """Apply synchronous reset for 2 cycles."""
    dut.rst.value  = 1
    dut.push.value = 0
    dut.pop.value  = 0
    dut.din.value  = 0
    await ClockCycles(dut.clk, 2)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

async def do_push(dut, frame):
    """Push one frame onto the stack.

    Timing:
      cycle 0 — push=1, din valid; frame written and depth increments on edge
      cycle 1 — push=0; depth output stable
    """
    assert not dut.full.value, "Attempted push on full stack"
    dut.din.value  = frame
    dut.push.value = 1
    await RisingEdge(dut.clk)   # frame written, depth increments
    dut.push.value = 0
    dut.din.value  = 0
    await RisingEdge(dut.clk)   # depth output stable

async def do_pop(dut):
    """Pop one frame from the stack. Returns dout value.

    Timing (confirmed by cycle trace):
      cycle 0 — pop=1; read_addr_r captures depth-1; depth decrements on edge
      cycle 1 — pop_d1 high; RAM read issued to read_addr_r
      cycle 2 — valid=1; dout stable  ← sample here
    """
    assert not dut.empty.value, "Attempted pop on empty stack"
    dut.pop.value = 1
    await RisingEdge(dut.clk)   # cycle 0: depth decrements, addr captured
    dut.pop.value = 0
    await RisingEdge(dut.clk)   # cycle 1: RAM read issued
    assert dut.valid.value == 0, \
        "valid should be low on cycle 1 after pop"
    await RisingEdge(dut.clk)   # cycle 2: dout stable, valid high
    assert dut.valid.value == 1, \
        "valid should be high on cycle 2 after pop"
    return int(dut.dout.value)

# ── Tests ─────────────────────────────────────────────────────

@cocotb.test()
async def test_reset(dut):
    """After reset: empty=1, full=0, valid=0."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    assert dut.empty.value == 1, "empty should be 1 after reset"
    assert dut.full.value  == 0, "full should be 0 after reset"
    assert dut.valid.value == 0, "valid should be 0 after reset"
    cocotb.log.info("reset ✓")

@cocotb.test()
async def test_push_pop_single(dut):
    """Push one frame, pop it back — verify frame is identical."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    frame = make_frame(seed=1)
    await do_push(dut, frame)

    assert dut.empty.value == 0, "stack should not be empty after push"

    readback = await do_pop(dut)
    assert readback == frame, \
        f"Frame mismatch:\n  pushed: {frame:#x}\n  popped: {readback:#x}"

    assert dut.empty.value == 1, "stack should be empty after pop"
    cocotb.log.info(f"push/pop single ✓ frame={frame:#x}")

@cocotb.test()
async def test_lifo_ordering(dut):
    """Push multiple frames, verify LIFO order on pop."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    frames = [make_frame(seed=i) for i in range(8)]
    for f in frames:
        await do_push(dut, f)

    for expected in reversed(frames):
        readback = await do_pop(dut)
        assert readback == expected, \
            f"LIFO violation:\n  expected: {expected:#x}\n  got:      {readback:#x}"

    assert dut.empty.value == 1, "stack should be empty after all pops"
    cocotb.log.info("LIFO ordering ✓")

@cocotb.test()
async def test_full_flag(dut):
    """Push STACK_DEPTH frames — full flag asserts, overflow push ignored."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    frames = [make_frame(seed=100 + i) for i in range(STACK_DEPTH)]
    for f in frames:
        assert dut.full.value == 0, "full asserted too early"
        await do_push(dut, f)

    assert dut.full.value  == 1, "full should be asserted"
    assert dut.empty.value == 0

    # Overflow push — should be silently ignored
    overflow = make_frame(seed=999)
    dut.din.value  = overflow
    dut.push.value = 1
    await RisingEdge(dut.clk)
    dut.push.value = 0
    dut.din.value  = 0
    await RisingEdge(dut.clk)

    assert dut.full.value == 1, "full should still be asserted"

    # Top frame must be the last legitimately pushed frame
    readback = await do_pop(dut)
    assert readback == frames[-1], \
        f"Top frame corrupted by overflow push:\n  expected: {frames[-1]:#x}\n  got:      {readback:#x}"

    cocotb.log.info("full flag ✓")

@cocotb.test()
async def test_empty_flag(dut):
    """Pop on empty stack is ignored — no underflow, valid never pulses."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    assert dut.empty.value == 1

    dut.pop.value = 1
    await RisingEdge(dut.clk)
    dut.pop.value = 0
    await ClockCycles(dut.clk, 3)

    assert dut.empty.value == 1, "empty should still be asserted"
    assert dut.valid.value == 0, "valid should not pulse on empty pop"
    cocotb.log.info("empty flag ✓")

@cocotb.test()
async def test_pop_latency(dut):
    """valid is low on cycles 1 and 2 after pop, high on cycle 3, dout held on cycle 4.

    do_push waits an extra settle cycle after the push edge, so the
    pop fires one cycle later relative to a raw push. The confirmed
    latency from the debug trace is:
      cycle 1 — valid low  (depth decrementing, addr captured)
      cycle 2 — valid low  (RAM read issued)
      cycle 3 — valid high (dout stable)
      cycle 4 — valid low  (dout held stable)
    """
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    frame = make_frame(seed=42)
    await do_push(dut, frame)  # includes one extra settle cycle

    # Cycle 0 — assert pop
    dut.pop.value = 1
    await RisingEdge(dut.clk)
    dut.pop.value = 0

    # Cycles 1 and 2 — valid must be low
    assert dut.valid.value == 0, "valid should be low on cycle 1 after pop"
    await RisingEdge(dut.clk)
    assert dut.valid.value == 0, "valid should be low on cycle 2 after pop"
    await RisingEdge(dut.clk)

    # Cycle 3 — valid high, dout correct
    assert dut.valid.value == 1, "valid should be high on cycle 3 after pop"
    assert int(dut.dout.value) == frame, \
        f"dout wrong on valid cycle: {int(dut.dout.value):#x} != {frame:#x}"
    await RisingEdge(dut.clk)

    # Cycle 4 — valid gone, dout held stable
    assert dut.valid.value == 0, "valid should be low on cycle 4"
    assert int(dut.dout.value) == frame, "dout should be held stable after valid"

    cocotb.log.info("pop latency ✓")

@cocotb.test()
async def test_chosen_var_field(dut):
    """Pack/unpack chosen_var field — verify it survives push/pop intact."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    test_vars = [0, 1, V // 2, V - 1]
    frames = []
    for var in test_vars:
        state = make_frame(seed=var) >> VAR_BITS
        frame = pack_frame(state, var)
        frames.append((frame, var, state))
        await do_push(dut, frame)

    for expected_frame, expected_var, expected_state in reversed(frames):
        readback = await do_pop(dut)
        rb_state, rb_var = unpack_frame(readback)
        assert rb_var == expected_var, \
            f"chosen_var mismatch: expected {expected_var}, got {rb_var}"
        assert rb_state == expected_state, \
            f"state mismatch: expected {expected_state:#x}, got {rb_state:#x}"

    cocotb.log.info("chosen_var field ✓")

@cocotb.test()
async def test_interleaved_push_pop(dut):
    """Interleave pushes and pops — verify stack depth and values are consistent."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await do_reset(dut)

    reference = []

    for i in range(4):
        f = make_frame(seed=200 + i)
        await do_push(dut, f)
        reference.append(f)

    for _ in range(2):
        expected = reference.pop()
        readback = await do_pop(dut)
        assert readback == expected, \
            f"Interleaved pop mismatch: expected {expected:#x}, got {readback:#x}"

    for i in range(3):
        f = make_frame(seed=300 + i)
        await do_push(dut, f)
        reference.append(f)

    while reference:
        expected = reference.pop()
        readback = await do_pop(dut)
        assert readback == expected, \
            f"Interleaved pop mismatch: expected {expected:#x}, got {readback:#x}"

    assert dut.empty.value == 1
    cocotb.log.info("interleaved push/pop ✓")

# ── Runner ────────────────────────────────────────────────────

def test_BramStack():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/BramStack.sv",
        ],
        hdl_toplevel="BramStack",
        parameters={
            "N":           N,
            "CC":          CC,
            "STACK_DEPTH": STACK_DEPTH,
        },
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="BramStack",
        test_module="test_BramStack",
    )
