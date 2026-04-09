import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

V  = 16
CC = 6
CC_MASK = (1 << CC) - 1

def pack_domain(domain):
    return domain

def pack_elements(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & CC_MASK) << (i * CC)
    return val

def reference(domain, in_c_top, in_c_right, in_c_bottom, in_c_left,
              el_top, el_right, el_bottom, el_left):
    top = right = bottom = left = 0
    for p in range(V):
        if (domain >> p) & 1:
            top    |= el_top[p]
            right  |= el_right[p]
            bottom |= el_bottom[p]
            left   |= el_left[p]
    # AND with existing colours — can only narrow
    top    &= in_c_top
    right  &= in_c_right
    bottom &= in_c_bottom
    left   &= in_c_left
    return top, right, bottom, left

async def apply(dut, domain,
                in_c_top, in_c_right, in_c_bottom, in_c_left,
                el_top, el_right, el_bottom, el_left):
    dut.in_domain.value          = domain
    dut.in_colour_top.value      = in_c_top
    dut.in_colour_right.value    = in_c_right
    dut.in_colour_bottom.value   = in_c_bottom
    dut.in_colour_left.value     = in_c_left
    dut.in_element_top.value     = pack_elements(el_top)
    dut.in_element_right.value   = pack_elements(el_right)
    dut.in_element_bottom.value  = pack_elements(el_bottom)
    dut.in_element_left.value    = pack_elements(el_left)
    await Timer(1, unit="ns")

async def check(dut, domain,
                in_c_top, in_c_right, in_c_bottom, in_c_left,
                el_top, el_right, el_bottom, el_left):
    await apply(dut, domain,
                in_c_top, in_c_right, in_c_bottom, in_c_left,
                el_top, el_right, el_bottom, el_left)
    exp_top, exp_right, exp_bottom, exp_left = reference(
        domain, in_c_top, in_c_right, in_c_bottom, in_c_left,
        el_top, el_right, el_bottom, el_left)
    assert int(dut.out_colour_top.value)    == exp_top,    \
        f"top={int(dut.out_colour_top.value):06b} exp={exp_top:06b}"
    assert int(dut.out_colour_right.value)  == exp_right,  \
        f"right={int(dut.out_colour_right.value):06b} exp={exp_right:06b}"
    assert int(dut.out_colour_bottom.value) == exp_bottom, \
        f"bottom={int(dut.out_colour_bottom.value):06b} exp={exp_bottom:06b}"
    assert int(dut.out_colour_left.value)   == exp_left,   \
        f"left={int(dut.out_colour_left.value):06b} exp={exp_left:06b}"

def make_elements(val): return [val] * V
def full_colours():     return CC_MASK  # single colour value for rotation test


@cocotb.test()
async def test_empty_domain(dut):
    """Empty domain — all outputs zero regardless of incoming colours."""
    el = make_elements(CC_MASK)
    await check(dut, 0, CC_MASK, CC_MASK, CC_MASK, CC_MASK, el, el, el, el)
    assert int(dut.out_colour_top.value)    == 0
    assert int(dut.out_colour_right.value)  == 0
    assert int(dut.out_colour_bottom.value) == 0
    assert int(dut.out_colour_left.value)   == 0
    cocotb.log.info("empty domain → all zero ✓")


@cocotb.test()
async def test_full_domain_all_ones(dut):
    """Full domain all-ones elements, full incoming colours — all outputs all-ones."""
    el = make_elements(CC_MASK)
    await check(dut, (1 << V) - 1,
                CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el, el, el, el)
    assert int(dut.out_colour_top.value)    == CC_MASK
    assert int(dut.out_colour_right.value)  == CC_MASK
    assert int(dut.out_colour_bottom.value) == CC_MASK
    assert int(dut.out_colour_left.value)   == CC_MASK
    cocotb.log.info("full domain all ones ✓")


@cocotb.test()
async def test_single_piece_in_domain(dut):
    """Single piece in domain — output equals that piece's colours ANDed with incoming."""
    el_top    = [0] * V; el_top[3]    = 0b001100
    el_right  = [0] * V; el_right[3]  = 0b110000
    el_bottom = [0] * V; el_bottom[3] = 0b000011
    el_left   = [0] * V; el_left[3]   = 0b001111
    domain = 1 << 3
    await check(dut, domain,
                CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el_top, el_right, el_bottom, el_left)
    assert int(dut.out_colour_top.value)    == 0b001100
    assert int(dut.out_colour_right.value)  == 0b110000
    assert int(dut.out_colour_bottom.value) == 0b000011
    assert int(dut.out_colour_left.value)   == 0b001111
    cocotb.log.info("single piece ✓")


@cocotb.test()
async def test_incoming_colours_narrow_output(dut):
    """Incoming colours AND with derived colours — output is narrowed."""
    el_top = [0] * V; el_top[0] = 0b001111
    el_zer = [0] * V
    domain = 1 << 0
    # incoming colour only allows bits 0b001100 — should mask out 0b000011
    await check(dut, domain,
                0b001100, CC_MASK, CC_MASK, CC_MASK,
                el_top, el_zer, el_zer, el_zer)
    assert int(dut.out_colour_top.value) == 0b001100, \
        f"expected 0b001100 after AND, got {int(dut.out_colour_top.value):06b}"
    cocotb.log.info("incoming colours narrow output ✓")


@cocotb.test()
async def test_two_pieces_or(dut):
    """Two pieces in domain — output is OR of their colours ANDed with incoming."""
    el_top = [0] * V
    el_top[0] = 0b001100
    el_top[1] = 0b000011
    el_zero = [0] * V
    domain = 0b11
    await check(dut, domain,
                CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el_top, el_zero, el_zero, el_zero)
    assert int(dut.out_colour_top.value) == 0b001111
    cocotb.log.info("two pieces OR ✓")


@cocotb.test()
async def test_inactive_piece_ignored(dut):
    """Piece not in domain is ignored."""
    el_top = [0] * V
    el_top[0] = 0b001100
    el_top[1] = 0b110011
    el_zero = [0] * V
    domain = 0b01
    await check(dut, domain,
                CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el_top, el_zero, el_zero, el_zero)
    assert int(dut.out_colour_top.value) == 0b001100
    cocotb.log.info("inactive piece ignored ✓")


@cocotb.test()
async def test_all_directions_independent(dut):
    """Each direction is OR'd independently."""
    el_top    = [0b000001] * V
    el_right  = [0b000010] * V
    el_bottom = [0b000100] * V
    el_left   = [0b001000] * V
    domain = (1 << V) - 1
    await check(dut, domain,
                CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el_top, el_right, el_bottom, el_left)
    assert int(dut.out_colour_top.value)    == 0b000001
    assert int(dut.out_colour_right.value)  == 0b000010
    assert int(dut.out_colour_bottom.value) == 0b000100
    assert int(dut.out_colour_left.value)   == 0b001000
    cocotb.log.info("all directions independent ✓")


@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(13)
    for _ in range(50):
        domain    = random.randint(0, (1 << V) - 1)
        in_c_top    = random.randint(0, CC_MASK)
        in_c_right  = random.randint(0, CC_MASK)
        in_c_bottom = random.randint(0, CC_MASK)
        in_c_left   = random.randint(0, CC_MASK)
        el_top    = [random.randint(0, CC_MASK) for _ in range(V)]
        el_right  = [random.randint(0, CC_MASK) for _ in range(V)]
        el_bottom = [random.randint(0, CC_MASK) for _ in range(V)]
        el_left   = [random.randint(0, CC_MASK) for _ in range(V)]
        await check(dut, domain,
                    in_c_top, in_c_right, in_c_bottom, in_c_left,
                    el_top, el_right, el_bottom, el_left)
    cocotb.log.info("50 random tests ✓")


def test_DomainToColour_Rotation():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/DomainToColour_Rotation.sv"],
        hdl_toplevel="DomainToColour_Rotation",
        parameters={"V": V, "CC": CC},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="DomainToColour_Rotation",
        test_module="test_DomainToColour_Rotation",
    )