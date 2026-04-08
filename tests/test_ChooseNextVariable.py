import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
V = N * N
ALL_VARS = (1 << V) - 1

def pack(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL_VARS) << (i * V)
    return val

async def apply(dut, unassigned, r0, r1, r2, r3):
    dut.in_unassignedVariables.value = unassigned
    dut.in_domain_r0.value = pack(r0)
    dut.in_domain_r1.value = pack(r1)
    dut.in_domain_r2.value = pack(r2)
    dut.in_domain_r3.value = pack(r3)
    await Timer(1, unit="ns")

@cocotb.test()
async def test_no_singletons(dut):
    """All unassigned — no singletons, no candidates."""
    r = [ALL_VARS] * V
    await apply(dut, ALL_VARS, r, r, r, r)
    assert dut.out_valid.value == 0
    cocotb.log.info("no singletons → valid=0 ✓")

@cocotb.test()
async def test_mrv_picks_smallest(dut):
    """MRV picks neighbour with smallest domain."""
    r0 = [ALL_VARS] * V
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    r0[1] = 0b0011
    r0[4] = 0b1111
    unassigned = ALL_VARS & ~1
    await apply(dut, unassigned, r0, r1, r2, r3)
    assert dut.out_valid.value == 1
    assert int(dut.out_next_var.value) == 1
    cocotb.log.info("MRV picks smallest domain ✓")

@cocotb.test()
async def test_random(dut):
    """30 random inputs — check valid is consistent."""
    random.seed(55)
    r = [ALL_VARS] * V
    for _ in range(30):
        unassigned = random.randint(0, ALL_VARS)
        await apply(dut, unassigned, r, r, r, r)
    cocotb.log.info("30 random tests ✓")

def test_ChooseNextVariable():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/ChooseNextVariable_ExpandSingletons.sv",
            "rtl/DomainSizes.sv",
            "rtl/ChooseNextVariable_FindMinimumDomain.sv",
            "rtl/ChooseNextVariable_SelectVariable.sv",
            "rtl/ChooseNextVariable.sv",
        ],
        hdl_toplevel="ChooseNextVariable",
        parameters={"N": N, "V": V},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="ChooseNextVariable",
        test_module="test_ChooseNextVariable",
    )