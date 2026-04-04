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

def reference(domain, el_top, el_right, el_bottom, el_left):
    top = right = bottom = left = 0
    for p in range(V):
        if (domain >> p) & 1:
            top    |= el_top[p]
            right  |= el_right[p]
            bottom |= el_bottom[p]
            left   |= el_left[p]
    return top, right, bottom, left

async def apply(dut, domain, el_top, el_right, el_bottom, el_left):
    dut.in_domain.value        = domain
    dut.in_element_top.value   = pack_elements(el_top)
    dut.in_element_right.value = pack_elements(el_right)
    dut.in_element_bottom.value = pack_elements(el_bottom)
    dut.in_element_left.value  = pack_elements(el_left)
    await Timer(1, unit="ns")

async def check(dut, domain, el_top, el_right, el_bottom, el_left):
    await apply(dut, domain, el_top, el_right, el_bottom, el_left)
    exp_top, exp_right, exp_bottom, exp_left = \
        reference(domain, el_top, el_right, el_bottom, el_left)
    assert dut.out_colour_top.value    == exp_top,    \
        f"top={dut.out_colour_top.value:06b} exp={exp_top:06b}"
    assert dut.out_colour_right.value  == exp_right,  \
        f"right={dut.out_colour_right.value:06b} exp={exp_right:06b}"
    assert dut.out_colour_bottom.value == exp_bottom, \
        f"bottom={dut.out_colour_bottom.value:06b} exp={exp_bottom:06b}"
    assert dut.out_colour_left.value   == exp_left,   \
        f"left={dut.out_colour_left.value:06b} exp={exp_left:06b}"

def make_elements(val):
    return [val] * V

@cocotb.test()
async def test_empty_domain(dut):
    """Empty domain — all outputs zero."""
    el = make_elements(CC_MASK)
    await check(dut, 0, el, el, el, el)
    assert dut.out_colour_top.value    == 0
    assert dut.out_colour_right.value  == 0
    assert dut.out_colour_bottom.value == 0
    assert dut.out_colour_left.value   == 0
    cocotb.log.info("empty domain → all zero ✓")

@cocotb.test()
async def test_full_domain_all_ones(dut):
    """Full domain all-ones elements — all outputs all-ones."""
    el = make_elements(CC_MASK)
    await check(dut, (1 << V) - 1, el, el, el, el)
    assert dut.out_colour_top.value    == CC_MASK
    assert dut.out_colour_right.value  == CC_MASK
    assert dut.out_colour_bottom.value == CC_MASK
    assert dut.out_colour_left.value   == CC_MASK
    cocotb.log.info("full domain all ones ✓")

@cocotb.test()
async def test_single_piece_in_domain(dut):
    """Single piece in domain — output equals that piece's colours."""
    el_top    = [0] * V
    el_right  = [0] * V
    el_bottom = [0] * V
    el_left   = [0] * V
    el_top[3]    = 0b001100
    el_right[3]  = 0b110000
    el_bottom[3] = 0b000011
    el_left[3]   = 0b001111
    domain = 1 << 3
    await check(dut, domain, el_top, el_right, el_bottom, el_left)
    assert dut.out_colour_top.value    == 0b001100
    assert dut.out_colour_right.value  == 0b110000
    assert dut.out_colour_bottom.value == 0b000011
    assert dut.out_colour_left.value   == 0b001111
    cocotb.log.info("single piece ✓")

@cocotb.test()
async def test_two_pieces_or(dut):
    """Two pieces in domain — output is OR of their colours."""
    el_top = [0] * V
    el_top[0] = 0b001100
    el_top[1] = 0b000011
    el_zero = [0] * V
    domain = 0b11
    await check(dut, domain, el_top, el_zero, el_zero, el_zero)
    assert dut.out_colour_top.value == 0b001111
    cocotb.log.info("two pieces OR ✓")

@cocotb.test()
async def test_inactive_piece_ignored(dut):
    """Piece not in domain is ignored."""
    el_top = [0] * V
    el_top[0] = 0b001100  # piece 0 in domain
    el_top[1] = 0b110011  # piece 1 NOT in domain
    el_zero = [0] * V
    domain = 0b01  # only piece 0
    await check(dut, domain, el_top, el_zero, el_zero, el_zero)
    assert dut.out_colour_top.value == 0b001100
    cocotb.log.info("inactive piece ignored ✓")

@cocotb.test()
async def test_all_directions_independent(dut):
    """Each direction is OR'd independently."""
    el_top    = [0b000001] * V
    el_right  = [0b000010] * V
    el_bottom = [0b000100] * V
    el_left   = [0b001000] * V
    domain = (1 << V) - 1
    await check(dut, domain, el_top, el_right, el_bottom, el_left)
    assert dut.out_colour_top.value    == 0b000001
    assert dut.out_colour_right.value  == 0b000010
    assert dut.out_colour_bottom.value == 0b000100
    assert dut.out_colour_left.value   == 0b001000
    cocotb.log.info("all directions independent ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(13)
    for _ in range(50):
        domain    = random.randint(0, (1 << V) - 1)
        el_top    = [random.randint(0, CC_MASK) for _ in range(V)]
        el_right  = [random.randint(0, CC_MASK) for _ in range(V)]
        el_bottom = [random.randint(0, CC_MASK) for _ in range(V)]
        el_left   = [random.randint(0, CC_MASK) for _ in range(V)]
        await check(dut, domain, el_top, el_right, el_bottom, el_left)
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