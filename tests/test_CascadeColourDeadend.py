import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
TC = 6
VARIABLES = N * N
TC_MASK = (1 << TC) - 1

def pack(arr):
    val = 0
    for i in range(VARIABLES):
        val |= (arr[i] & TC_MASK) << (i * TC)
    return val

def reference(out_right, out_bottom):
    for vid in range(VARIABLES):
        x = vid % N
        y = vid // N
        if x < N-1 and out_right[vid] == 0:
            return True
        if y < N-1 and out_bottom[vid] == 0:
            return True
    return False

async def check(dut, out_right, out_bottom):
    dut.out_right.value  = pack(out_right)
    dut.out_bottom.value = pack(out_bottom)
    await Timer(1, unit="ns")
    exp = reference(out_right, out_bottom)
    assert dut.deadend.value == int(exp), \
        f"deadend={dut.deadend.value} expected={int(exp)}"

@cocotb.test()
async def test_no_deadend(dut):
    """All edges non-zero — no deadend."""
    c = [TC_MASK] * VARIABLES
    await check(dut, c, c)
    assert dut.deadend.value == 0
    cocotb.log.info("no deadend ✓")

@cocotb.test()
async def test_right_zero_interior(dut):
    """Interior right edge zero — deadend."""
    c = [TC_MASK] * VARIABLES
    out_right = list(c)
    out_right[5] = 0  # x=1,y=1 — interior, x < N-1
    await check(dut, out_right, c)
    assert dut.deadend.value == 1
    cocotb.log.info("interior right zero → deadend ✓")

@cocotb.test()
async def test_right_zero_last_column(dut):
    """Right edge zero on last column (x=N-1) — NOT a deadend."""
    c = [TC_MASK] * VARIABLES
    out_right = list(c)
    # Last column: ids 3,7,11,15 (x=N-1)
    out_right[3] = 0
    out_right[7] = 0
    out_right[11] = 0
    out_right[15] = 0
    await check(dut, out_right, c)
    assert dut.deadend.value == 0
    cocotb.log.info("last column right zero — not deadend ✓")

@cocotb.test()
async def test_bottom_zero_interior(dut):
    """Interior bottom edge zero — deadend."""
    c = [TC_MASK] * VARIABLES
    out_bottom = list(c)
    out_bottom[6] = 0  # x=2,y=1 — interior, y < N-1
    await check(dut, c, out_bottom)
    assert dut.deadend.value == 1
    cocotb.log.info("interior bottom zero → deadend ✓")

@cocotb.test()
async def test_bottom_zero_last_row(dut):
    """Bottom edge zero on last row (y=N-1) — NOT a deadend."""
    c = [TC_MASK] * VARIABLES
    out_bottom = list(c)
    # Last row: ids 12,13,14,15 (y=N-1)
    out_bottom[12] = 0
    out_bottom[13] = 0
    out_bottom[14] = 0
    out_bottom[15] = 0
    await check(dut, c, out_bottom)
    assert dut.deadend.value == 0
    cocotb.log.info("last row bottom zero — not deadend ✓")

@cocotb.test()
async def test_all_zeros(dut):
    """All edges zero — deadend from interior positions."""
    z = [0] * VARIABLES
    await check(dut, z, z)
    assert dut.deadend.value == 1
    cocotb.log.info("all zeros → deadend ✓")

@cocotb.test()
async def test_random(dut):
    """100 random inputs verified against reference."""
    random.seed(31)
    for _ in range(100):
        out_right  = [random.randint(0, TC_MASK) for _ in range(VARIABLES)]
        out_bottom = [random.randint(0, TC_MASK) for _ in range(VARIABLES)]
        await check(dut, out_right, out_bottom)
    cocotb.log.info("100 random tests ✓")

def test_CascadeColourDeadend():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/CascadeColourDeadend.sv"],
        hdl_toplevel="CascadeColourDeadend",
        parameters={"N": N, "TC": TC},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="CascadeColourDeadend",
        test_module="test_CascadeColourDeadend",
    )