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

async def apply(dut, in_top, in_right, in_bottom, in_left,
                out_top, out_right, out_bottom, out_left):
    dut.in_top.value    = pack(in_top)
    dut.in_right.value  = pack(in_right)
    dut.in_bottom.value = pack(in_bottom)
    dut.in_left.value   = pack(in_left)
    dut.out_top.value    = pack(out_top)
    dut.out_right.value  = pack(out_right)
    dut.out_bottom.value = pack(out_bottom)
    dut.out_left.value   = pack(out_left)
    await Timer(1, unit="ns")

def reference(in_top, in_right, in_bottom, in_left,
              out_top, out_right, out_bottom, out_left):
    for i in range(VARIABLES):
        if (out_top[i] != in_top[i] or out_right[i] != in_right[i] or
                out_bottom[i] != in_bottom[i] or out_left[i] != in_left[i]):
            return True
    return False

async def check(dut, in_top, in_right, in_bottom, in_left,
                out_top, out_right, out_bottom, out_left):
    await apply(dut, in_top, in_right, in_bottom, in_left,
                out_top, out_right, out_bottom, out_left)
    exp = reference(in_top, in_right, in_bottom, in_left,
                    out_top, out_right, out_bottom, out_left)
    assert dut.changed.value == int(exp), \
        f"changed={dut.changed.value} expected={int(exp)}"

@cocotb.test()
async def test_no_change(dut):
    """Identical inputs and outputs — changed=0."""
    c = [TC_MASK] * VARIABLES
    await check(dut, c, c, c, c, c, c, c, c)
    assert dut.changed.value == 0
    cocotb.log.info("no change ✓")

@cocotb.test()
async def test_top_changed(dut):
    """One variable's top edge differs — changed=1."""
    c = [TC_MASK] * VARIABLES
    out_top = list(c)
    out_top[5] = TC_MASK ^ 0b000001  # flip one bit
    await check(dut, c, c, c, c, out_top, c, c, c)
    assert dut.changed.value == 1
    cocotb.log.info("top changed ✓")

@cocotb.test()
async def test_right_changed(dut):
    """One variable's right edge differs — changed=1."""
    c = [TC_MASK] * VARIABLES
    out_right = list(c)
    out_right[3] = 0b000001
    await check(dut, c, c, c, c, c, out_right, c, c)
    assert dut.changed.value == 1
    cocotb.log.info("right changed ✓")

@cocotb.test()
async def test_bottom_changed(dut):
    """One variable's bottom edge differs — changed=1."""
    c = [TC_MASK] * VARIABLES
    out_bottom = list(c)
    out_bottom[0] = 0b000001
    await check(dut, c, c, c, c, c, c, out_bottom, c)
    assert dut.changed.value == 1
    cocotb.log.info("bottom changed ✓")

@cocotb.test()
async def test_left_changed(dut):
    """One variable's left edge differs — changed=1."""
    c = [TC_MASK] * VARIABLES
    out_left = list(c)
    out_left[15] = 0b000001
    await check(dut, c, c, c, c, c, c, c, out_left)
    assert dut.changed.value == 1
    cocotb.log.info("left changed ✓")

@cocotb.test()
async def test_all_zeros_unchanged(dut):
    """All zeros in and out — no change."""
    z = [0] * VARIABLES
    await check(dut, z, z, z, z, z, z, z, z)
    assert dut.changed.value == 0
    cocotb.log.info("all zeros unchanged ✓")

@cocotb.test()
async def test_random(dut):
    """100 random inputs verified against reference."""
    random.seed(13)
    for _ in range(100):
        def rc(): return [random.randint(0, TC_MASK) for _ in range(VARIABLES)]
        in_t, in_r, in_b, in_l = rc(), rc(), rc(), rc()
        out_t, out_r, out_b, out_l = rc(), rc(), rc(), rc()
        await check(dut, in_t, in_r, in_b, in_l,
                    out_t, out_r, out_b, out_l)
    cocotb.log.info("100 random tests ✓")

def test_CascadeColourChanges():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/CascadeColourChanges.sv"],
        hdl_toplevel="CascadeColourChanges",
        parameters={"N": N, "TC": TC},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="CascadeColourChanges",
        test_module="test_CascadeColourChanges",
    )