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

# Serves as the ground truth - a simple easy to read python implementation of what the hardware should do
# Once we trust the reference model, we can use it to automatically check the hardware output for any input we throw at it
# The random test particularly relies on it
def reference(unassigned):
    singletons = ALL_VARS & ~unassigned
    expanded = (
        ((singletons >> N) & ALL_VARS) |
        ((singletons << N) & ALL_VARS) |
        (((singletons & NOT_FIRST_COL) >> 1) & ALL_VARS) |
        (((singletons & NOT_LAST_COL)  << 1) & ALL_VARS)
    )
    return expanded & ALL_VARS & unassigned

# async keyword means its a coroutine - it can pause and resume which is needed because we have to wait for simulation time to pass
# dut is device under test (the hardware module)
# unassigned is the bitmask we want to test with
async def check(dut, unassigned):
    #sets the hardware input signal to our test value
    dut.in_unassignedVariables.value = unassigned
    # wait one nanosecond for the results to settle.  The simulator advances time by 1 nanosecond.  The await suspends the coroutine until that time has elapsed.  
    # This is necessary because the hardware is combinational - even though there is no clock, Verilator still needs a moment to propogate the input through all the logic and compute the output.  Without this wait the output might still reflect the previous input
    await Timer(1, unit="ns")
    # This calls our python reference model with the same input to compute what the correct answer should be
    exp = reference(unassigned)
    # reads the hardware output signal.  The .value gives a cocotb Logic object so we can cast it to int to get a plain python integer we can compare
    act = int(dut.out_candidates.value)
    # Compares actual hardware output against expected Python output.  If they differ the test fails and cocotb reports which test failed and what the values where.
    assert act == exp, \
        f"unassigned={unassigned:#x}\n" \
        f"  got={act:#x}\n" \
        f"  exp={exp:#x}"

@cocotb.test()
async def test_no_singletons(dut):
    """No singletons — no candidates."""
    # passes ALL_VARS as the unassigned input, every bit set means every variable is unassigned
    await check(dut, ALL_VARS)
    assert int(dut.out_candidates.value) == 0
    cocotb.log.info("no singletons → no candidates ✓")

@cocotb.test()
async def test_var0_singleton(dut):
    """Var 0 singleton — neighbours are var 1 (right) and var N (below)."""
    unassigned = ALL_VARS & ~1 # var 0 placed
    await check(dut, unassigned)
    act = int(dut.out_candidates.value)
    assert (act >> 1) & 1, "var 1 should be candidate"
    assert (act >> N) & 1, "var N should be candidate"
    cocotb.log.info("var 0 expands correctly ✓")

@cocotb.test()
async def test_no_right_wrap(dut):
    """Right edge singleton does not wrap to next row."""
    unassigned = ALL_VARS & ~(1 << (N-1))  # var N-1 placed 
    await check(dut, unassigned)
    act = int(dut.out_candidates.value)
    assert not (act & 1), "var 0 should not be candidate — no row wrap"
    cocotb.log.info("no right-edge row wraparound ✓")

@cocotb.test()
async def test_no_left_wrap(dut):
    """Left edge singleton does not wrap to previous row's right end."""
    unassigned = ALL_VARS & ~(1 << vid(0, 1))  # left edge row 1 placed
    await check(dut, unassigned)
    act = int(dut.out_candidates.value)
    assert not (act >> vid(N-1, 0)) & 1, "no wrap from left edge to previous row right"
    cocotb.log.info("no left-edge row wraparound ✓")

@cocotb.test()
async def test_centre_singleton(dut):
    """Centre variable — all four neighbours should be candidates."""
    cx, cy = N // 2, N // 2
    unassigned = ALL_VARS & ~(1 << vid(cx, cy))
    await check(dut, unassigned)
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
    await check(dut, unassigned)
    act = int(dut.out_candidates.value)
    assert not (act >> vid(1, 1)) & 1, "singleton itself not a candidate"
    assert not (act >> vid(2, 1)) & 1, "singleton itself not a candidate"
    cocotb.log.info("assigned neighbours excluded ✓")

@cocotb.test()
async def test_top_row_no_up_neighbour(dut):
    """Singleton on top row — up neighbour is out of bounds."""
    singleton = 1 << vid(2, 0)
    unassigned = ALL_VARS & ~singleton
    await check(dut, unassigned)
    act = int(dut.out_candidates.value)
    assert popcount(act) <= 3, \
        f"top row singleton has at most 3 neighbours, got {popcount(act)}"
    cocotb.log.info("top row — no up neighbour ✓")

@cocotb.test()
async def test_bottom_row_no_down_neighbour(dut):
    """Singleton on bottom row — down neighbour is out of bounds."""
    singleton = 1 << vid(2, N-1)
    unassigned = ALL_VARS & ~singleton
    await check(dut, unassigned)
    act = int(dut.out_candidates.value)
    assert popcount(act) <= 3, \
        f"bottom row singleton has at most 3 neighbours, got {popcount(act)}"
    cocotb.log.info("bottom row — no down neighbour ✓")

# @cocotb.test() - decorator that register the function with cocotb as a test to run.  When the simulation starts cocotb finds all functions decorated with @cocotb.test() and runs them in order.
@cocotb.test()
#async keyword makes this a coroutine so it can use await.
#dut is automatically provided by cocotb - its a handle to the hardware module being simulated, giving us access to all its ports.
async def test_all_assigned(dut):
    # the docstring describes what this test is checking.  cocotb prints this in the test output so we can see at a glance what each test does without reading the code.
    """All variables assigned — no unassigned candidates."""
    # Calls our shared check function with unassigned=0 meaning all variables are placed - no bits set means nothing is unassigned.  
    # The await is needed because check is itself an async function that waits for the simulation time to pass.
    # This drives the inputs, waits 1ns, then asserts the output matches what we expected
    await check(dut, 0)
    # An extra explicit assertion on top of what check already verifies.  When all variables are placed there are no unassigned neighbours possible so the output must be exactly zero.  
    # This makes the test intent crystal clear even if you don't read the reference model.
    assert int(dut.out_candidates.value) == 0
    # prints a message to teh simulation log when the test passes.  This is what you see in the test output alongside the PASS/FAIL status - it confirms which specific scenario was verified
    cocotb.log.info("all assigned → no candidates ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(11)
    for _ in range(50):
        unassigned = random.randint(0, ALL_VARS)
        await check(dut, unassigned)
    cocotb.log.info("50 random tests ✓")

# entry point that pytest calls to run the tests.  It does two things, build the simulation and then run it
def test_ChooseNextVariable_ExpandSingletons():
    # Get a cocotb runner configured to use Verilator as the simulator.  Verilator compiles System Verilog into c++ and then compiles that into a fast executable
    runner = get_runner("verilator")
    # compiles the system verilog into a simulation executable
    runner.build(
        # the list of .sv files to compile.  Just one file here since ExpandSingletons has no submodules
        sources=["rtl/ChooseNextVariable_ExpandSingletons.sv"],
        # out of these sources which is the top of the design, ie the one we are testing
        hdl_toplevel="ChooseNextVariable_ExpandSingletons",
        # override the modules parameters.  Here we pass N=4 and V=16 which is defined above
        parameters={"N": N, "V": V},
        # suppress width matching warings that would otherwise cause the build to fail
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    # runs the compiled simulation and executes the cocotb tests
    runner.test(
        # the top module to simulate
        hdl_toplevel="ChooseNextVariable_ExpandSingletons",
        # the python file constaining the @cocotb.test() functions to run which is this file itself
        test_module="test_ChooseNextVariable_ExpandSingletons",
    )
    # When pytest discovers test_ChooseNextVariable_ExpandSingletons it calls this function which builds and runs the simulation and cocotb reports pass or fail for each cocotb.test() inside.