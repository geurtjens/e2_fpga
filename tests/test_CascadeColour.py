import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
CC = 6
V = N * N
PAIRS = (N-1) * (N-1)
CC_MASK = (1 << CC) - 1

def pack_colours(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & CC_MASK) << (i * CC)
    return val

def unpack_colours(val):
    return [(val >> (i * CC)) & CC_MASK for i in range(V)]

def vid(x, y): return y * N + x

def reference(in_top, in_right, in_bottom, in_left):
    out_top    = list(in_top)
    out_right  = list(in_right)
    out_bottom = list(in_bottom)
    out_left   = list(in_left)
    deadend = False
    updated = False

    for py in range(N-1):
        for px in range(N-1):
            id_ = py * N + px
            h = in_right[id_] & in_left[id_+1]
            v = in_bottom[id_] & in_top[id_+N]
            out_right[id_]    = h
            out_left[id_+1]   = h
            out_bottom[id_]   = v
            out_top[id_+N]    = v
            if h == 0 or v == 0:
                deadend = True
            if h != in_right[id_] or h != in_left[id_+1]:
                updated = True
            if v != in_bottom[id_] or v != in_top[id_+N]:
                updated = True

    return out_top, out_right, out_bottom, out_left, deadend, updated

async def apply(dut, in_top, in_right, in_bottom, in_left):
    dut.in_colours_top.value    = pack_colours(in_top)
    dut.in_colours_right.value  = pack_colours(in_right)
    dut.in_colours_bottom.value = pack_colours(in_bottom)
    dut.in_colours_left.value   = pack_colours(in_left)
    await Timer(1, unit="ns")

async def check(dut, in_top, in_right, in_bottom, in_left):
    await apply(dut, in_top, in_right, in_bottom, in_left)
    exp_top, exp_right, exp_bottom, exp_left, exp_de, exp_up = \
        reference(in_top, in_right, in_bottom, in_left)

    act_top    = unpack_colours(dut.out_colours_top.value.to_unsigned())
    act_right  = unpack_colours(dut.out_colours_right.value.to_unsigned())
    act_bottom = unpack_colours(dut.out_colours_bottom.value.to_unsigned())
    act_left   = unpack_colours(dut.out_colours_left.value.to_unsigned())

    for i in range(V):
        assert act_top[i]    == exp_top[i],    f"top[{i}]={act_top[i]:06b} exp={exp_top[i]:06b}"
        assert act_right[i]  == exp_right[i],  f"right[{i}]={act_right[i]:06b} exp={exp_right[i]:06b}"
        assert act_bottom[i] == exp_bottom[i], f"bottom[{i}]={act_bottom[i]:06b} exp={exp_bottom[i]:06b}"
        assert act_left[i]   == exp_left[i],   f"left[{i}]={act_left[i]:06b} exp={exp_left[i]:06b}"

    assert dut.out_deadend.value == int(exp_de), \
        f"deadend={dut.out_deadend.value} exp={int(exp_de)}"
    assert dut.out_updated.value == int(exp_up), \
        f"updated={dut.out_updated.value} exp={int(exp_up)}"

def make_full():
    return [CC_MASK] * V

def make_zero():
    return [0] * V

@cocotb.test()
async def test_all_ones_no_change(dut):
    """All-ones inputs — outputs unchanged, no deadend, no update."""
    c = make_full()
    await check(dut, c, c, c, c)
    assert dut.out_deadend.value == 0
    assert dut.out_updated.value == 0
    cocotb.log.info("all ones ✓")

@cocotb.test()
async def test_horizontal_cascade(dut):
    """Horizontal pair AND propagated to both sides."""
    c = make_full()
    in_right = list(c)
    in_left  = list(c)
    in_right[vid(0,0)] = 0b001111
    in_left[vid(1,0)]  = 0b111100
    await check(dut, c, in_right, c, in_left)
    act_right = unpack_colours(dut.out_colours_right.value.to_unsigned())
    act_left  = unpack_colours(dut.out_colours_left.value.to_unsigned())
    assert act_right[vid(0,0)] == 0b001100
    assert act_left[vid(1,0)]  == 0b001100
    cocotb.log.info("horizontal cascade ✓")

@cocotb.test()
async def test_vertical_cascade(dut):
    """Vertical pair AND propagated to both sides."""
    c = make_full()
    in_bottom = list(c)
    in_top    = list(c)
    in_bottom[vid(0,0)] = 0b001111
    in_top[vid(0,1)]    = 0b111100
    await check(dut, in_top, c, in_bottom, c)
    act_bottom = unpack_colours(dut.out_colours_bottom.value.to_unsigned())
    act_top    = unpack_colours(dut.out_colours_top.value.to_unsigned())
    assert act_bottom[vid(0,0)] == 0b001100
    assert act_top[vid(0,1)]    == 0b001100
    cocotb.log.info("vertical cascade ✓")

@cocotb.test()
async def test_horizontal_deadend(dut):
    """No overlap on horizontal pair — deadend."""
    c = make_full()
    in_right = list(c)
    in_left  = list(c)
    in_right[vid(0,0)] = 0b010101
    in_left[vid(1,0)]  = 0b101010
    await check(dut, c, in_right, c, in_left)
    assert dut.out_deadend.value == 1
    cocotb.log.info("horizontal deadend ✓")

@cocotb.test()
async def test_vertical_deadend(dut):
    """No overlap on vertical pair — deadend."""
    c = make_full()
    in_bottom = list(c)
    in_top    = list(c)
    in_bottom[vid(0,0)] = 0b010101
    in_top[vid(0,1)]    = 0b101010
    await check(dut, in_top, c, in_bottom, c)
    assert dut.out_deadend.value == 1
    cocotb.log.info("vertical deadend ✓")

@cocotb.test()
async def test_last_column_not_cascaded(dut):
    """Last column right edge not cascaded."""
    c = make_full()
    in_right = list(c)
    for y in range(N):
        in_right[vid(N-1, y)] = 0b000001
    await check(dut, c, in_right, c, c)
    assert dut.out_deadend.value == 0
    cocotb.log.info("last column not cascaded ✓")

@cocotb.test()
async def test_last_row_not_cascaded(dut):
    """Last row bottom edge not cascaded."""
    c = make_full()
    in_bottom = list(c)
    for x in range(N):
        in_bottom[vid(x, N-1)] = 0b000001
    await check(dut, c, c, in_bottom, c)
    assert dut.out_deadend.value == 0
    cocotb.log.info("last row not cascaded ✓")

@cocotb.test()
async def test_non_cascaded_passthrough(dut):
    """Non-cascaded positions pass through unchanged."""
    c = make_full()
    in_top = list(c)
    in_top[vid(0,0)] = 0b000011
    await check(dut, in_top, c, c, c)
    act_top = unpack_colours(dut.out_colours_top.value.to_unsigned())
    assert act_top[vid(0,0)] == 0b000011
    cocotb.log.info("non-cascaded passthrough ✓")

@cocotb.test()
async def test_random(dut):
    """100 random inputs verified against reference."""
    random.seed(17)
    for _ in range(100):
        def rc(): return [random.randint(0, CC_MASK) for _ in range(V)]
        await check(dut, rc(), rc(), rc(), rc())
    cocotb.log.info("100 random tests ✓")

def test_CascadeColour():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/CascadeColour_Single.sv",
            "rtl/CascadeColour_Pair.sv",
            "rtl/CascadeColour.sv",
        ],
        hdl_toplevel="CascadeColour",
        parameters={"N": N, "CC": CC},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="CascadeColour",
        test_module="test_CascadeColour",
    )