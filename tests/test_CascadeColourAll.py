import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
TC = 6
VARIABLES = N * N
PAIRS = (N-1) * (N-1)
TC_MASK = (1 << TC) - 1

def pack_vars(arr):
    val = 0
    for i in range(VARIABLES):
        val |= (arr[i] & TC_MASK) << (i * TC)
    return val

def unpack_pairs(val):
    return [(val >> (i * TC)) & TC_MASK for i in range(PAIRS)]

def reference(in_top, in_right, in_bottom, in_left):
    out_h = [0] * PAIRS
    out_v = [0] * PAIRS
    deadend = False
    updated = False

    for y in range(N-1):
        for x in range(N-1):
            vid = y * N + x
            p   = y * (N-1) + x
            h = in_right[vid] & in_left[vid+1]
            v = in_bottom[vid] & in_top[vid+N]
            out_h[p] = h
            out_v[p] = v
            if h == 0 or v == 0:
                deadend = True
            if h != in_right[vid] or h != in_left[vid+1]:
                updated = True
            if v != in_bottom[vid] or v != in_top[vid+N]:
                updated = True

    return out_h, out_v, deadend, updated

async def check(dut, in_top, in_right, in_bottom, in_left):
    dut.in_top.value    = pack_vars(in_top)
    dut.in_right.value  = pack_vars(in_right)
    dut.in_bottom.value = pack_vars(in_bottom)
    dut.in_left.value   = pack_vars(in_left)
    await Timer(1, unit="ns")

    exp_h, exp_v, exp_de, exp_up = reference(in_top, in_right, in_bottom, in_left)

    act_h = unpack_pairs(dut.out_h.value.to_unsigned())
    act_v = unpack_pairs(dut.out_v.value.to_unsigned())

    for p in range(PAIRS):
        assert act_h[p] == exp_h[p], f"out_h[{p}]={act_h[p]:06b} exp={exp_h[p]:06b}"
        assert act_v[p] == exp_v[p], f"out_v[{p}]={act_v[p]:06b} exp={exp_v[p]:06b}"

    assert dut.deadend.value == int(exp_de), \
        f"deadend={dut.deadend.value} exp={int(exp_de)}"
    assert dut.updated.value == int(exp_up), \
        f"updated={dut.updated.value} exp={int(exp_up)}"

@cocotb.test()
async def test_all_ones_no_change(dut):
    """All-ones inputs — no deadend, no update."""
    c = [TC_MASK] * VARIABLES
    await check(dut, c, c, c, c)
    assert dut.deadend.value == 0
    assert dut.updated.value == 0
    cocotb.log.info("all ones ✓")

@cocotb.test()
async def test_horizontal_cascade(dut):
    """Horizontal pair AND propagated correctly."""
    c = [TC_MASK] * VARIABLES
    in_right = list(c)
    in_left  = list(c)
    in_right[0] = 0b001111
    in_left[1]  = 0b111100
    await check(dut, c, in_right, c, in_left)
    act_h = unpack_pairs(dut.out_h.value.to_unsigned())
    assert act_h[0] == 0b001100
    cocotb.log.info("horizontal cascade ✓")

@cocotb.test()
async def test_vertical_cascade(dut):
    """Vertical pair AND propagated correctly."""
    c = [TC_MASK] * VARIABLES
    in_bottom = list(c)
    in_top    = list(c)
    in_bottom[0] = 0b001111
    in_top[N]    = 0b111100
    await check(dut, in_top, c, in_bottom, c)
    act_v = unpack_pairs(dut.out_v.value.to_unsigned())
    assert act_v[0] == 0b001100
    cocotb.log.info("vertical cascade ✓")

@cocotb.test()
async def test_deadend_horizontal(dut):
    """No overlap on horizontal pair — deadend."""
    c = [TC_MASK] * VARIABLES
    in_right = list(c)
    in_left  = list(c)
    in_right[0] = 0b010101
    in_left[1]  = 0b101010
    await check(dut, c, in_right, c, in_left)
    assert dut.deadend.value == 1
    cocotb.log.info("horizontal deadend ✓")

@cocotb.test()
async def test_deadend_vertical(dut):
    """No overlap on vertical pair — deadend."""
    c = [TC_MASK] * VARIABLES
    in_bottom = list(c)
    in_top    = list(c)
    in_bottom[0] = 0b010101
    in_top[N]    = 0b101010
    await check(dut, in_top, c, in_bottom, c)
    assert dut.deadend.value == 1
    cocotb.log.info("vertical deadend ✓")

@cocotb.test()
async def test_pair_count(dut):
    """Correct number of pairs: (N-1)*(N-1)."""
    assert PAIRS == (N-1)*(N-1), f"PAIRS={PAIRS}"
    cocotb.log.info(f"PAIRS={PAIRS} ✓")

@cocotb.test()
async def test_random(dut):
    """100 random inputs verified against reference."""
    random.seed(23)
    for _ in range(100):
        def rc(): return [random.randint(0, TC_MASK) for _ in range(VARIABLES)]
        await check(dut, rc(), rc(), rc(), rc())
    cocotb.log.info("100 random tests ✓")

def test_CascadeColourAll():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/CascadeColourSingle.sv",
            "rtl/CascadeColourPair.sv",
            "rtl/CascadeColourAll.sv",
        ],
        hdl_toplevel="CascadeColourAll",
        parameters={"N": N, "TC": TC},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="CascadeColourAll",
        test_module="test_CascadeColourAll",
    )