import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
ALL = (1 << N) - 1

def reference(r0, r1, r2, r3, vim):
    tiles_taken = 0
    for i in range(N):
        if not ((vim >> i) & 1):  # inactive = singleton
            tiles_taken |= r0[i] | r1[i] | r2[i] | r3[i]
    return tiles_taken & ALL

def pack(arr):
    val = 0
    for i in range(N):
        val |= (arr[i] & ALL) << (i * N)
    return val

async def apply(dut, r0, r1, r2, r3, vim):
    dut.r0_in.value = pack(r0)
    dut.r1_in.value = pack(r1)
    dut.r2_in.value = pack(r2)
    dut.r3_in.value = pack(r3)
    dut.variablesIncludedMask.value = vim
    await Timer(1, unit="ns")

async def check(dut, r0, r1, r2, r3, vim):
    await apply(dut, r0, r1, r2, r3, vim)
    exp = reference(r0, r1, r2, r3, vim)
    assert dut.tilesTaken.value == exp, \
        f"tilesTaken={dut.tilesTaken.value:04b} expected={exp:04b}"

@cocotb.test()
async def test_all_active_no_singletons(dut):
    """All variables active — no tiles taken."""
    r = [ALL] * N
    await check(dut, r, r, r, r, ALL)
    assert dut.tilesTaken.value == 0
    cocotb.log.info("all active → no tiles taken ✓")

@cocotb.test()
async def test_all_inactive(dut):
    """All variables inactive — all their tiles taken."""
    r = [ALL] * N
    await check(dut, r, r, r, r, 0)
    assert dut.tilesTaken.value == ALL
    cocotb.log.info("all inactive → all tiles taken ✓")

@cocotb.test()
async def test_one_singleton(dut):
    """One inactive variable contributes its tiles."""
    r0 = [0] * N
    r1 = [0] * N
    r2 = [0] * N
    r3 = [0] * N
    r0[0] = 0b0011  # var 0 is singleton with these tiles
    vim = ALL & ~1   # var 0 inactive
    await check(dut, r0, r1, r2, r3, vim)
    assert dut.tilesTaken.value == 0b0011
    cocotb.log.info("one singleton ✓")

@cocotb.test()
async def test_multiple_singletons_or(dut):
    """Multiple singletons — tiles are ORed together."""
    r0 = [0b0001, 0b0010, 0b0100, 0b1000]
    r1 = [0] * N
    r2 = [0] * N
    r3 = [0] * N
    vim = 0  # all inactive
    await check(dut, r0, r1, r2, r3, vim)
    assert dut.tilesTaken.value == ALL
    cocotb.log.info("multiple singletons ORed ✓")

@cocotb.test()
async def test_active_variable_not_counted(dut):
    """Active variable's tiles are NOT included in tilesTaken."""
    r0 = [ALL] * N
    r1 = [ALL] * N
    r2 = [ALL] * N
    r3 = [ALL] * N
    vim = ALL  # all active
    await check(dut, r0, r1, r2, r3, vim)
    assert dut.tilesTaken.value == 0
    cocotb.log.info("active variable not counted ✓")

@cocotb.test()
async def test_all_rotations_ored(dut):
    """All four rotations contribute to tilesTaken for singletons."""
    r0 = [0b0001] * N
    r1 = [0b0010] * N
    r2 = [0b0100] * N
    r3 = [0b1000] * N
    vim = ALL & ~1  # var 0 inactive
    await check(dut, r0, r1, r2, r3, vim)
    assert dut.tilesTaken.value == ALL
    cocotb.log.info("all rotations ORed ✓")

@cocotb.test()
async def test_random(dut):
    """100 random inputs verified against reference."""
    random.seed(77)
    for _ in range(100):
        r0 = [random.randint(0, ALL) for _ in range(N)]
        r1 = [random.randint(0, ALL) for _ in range(N)]
        r2 = [random.randint(0, ALL) for _ in range(N)]
        r3 = [random.randint(0, ALL) for _ in range(N)]
        vim = random.randint(0, ALL)
        await check(dut, r0, r1, r2, r3, vim)
    cocotb.log.info("100 random tests ✓")

def test_AllDifferent_CalculateTilesTaken():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/AllDifferent_CalculateTilesTaken.sv"],
        hdl_toplevel="AllDifferent_CalculateTilesTaken",
        parameters={"N": N},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="AllDifferent_CalculateTilesTaken",
        test_module="test_AllDifferent_CalculateTilesTaken",
    )