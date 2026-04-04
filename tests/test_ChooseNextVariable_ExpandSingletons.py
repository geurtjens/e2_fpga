import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
V = N * N
ALL_VARS = (1 << V) - 1

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
    assert dut.out_candidates.value == exp, \
        f"candidates={dut.out_candidates.value:#x} expected={exp:#x}"

@cocotb.test()
async def test_no_singletons(dut):
    """No singletons — no candidates."""
    await check(dut, 0, ALL_VARS)
    assert dut.out_candidates.value == 0
    cocotb.log.info("no singletons → no candidates ✓")

@cocotb.test()
async def test_var0_singleton(dut):
    """Var 0 singleton — neighbours are var 1 and var N."""
    await check(dut, 1, ALL_VARS & ~1)
    nv = int(dut.out_candidates.value)
    assert (nv >> 1) & 1, "var 1 should be candidate"
    assert (nv >> N) & 1, "var N should be candidate"
    cocotb.log.info("var 0 expands correctly ✓")

@cocotb.test()
async def test_no_right_wrap(dut):
    """Right edge singleton does not wrap to next row."""
    singleton = 1 << (N-1)
    await check(dut, singleton, ALL_VARS & ~singleton)
    candidates = int(dut.out_candidates.value)
    assert not (candidates & 1), "var 0 should not be candidate"
    cocotb.log.info("no row wrap ✓")

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