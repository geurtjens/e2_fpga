import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

VARIABLES = 16
TC = 6
ALL_DOMAIN = (1 << VARIABLES) - 1
TC_MASK = (1 << TC) - 1

def reference(domain, p_top, p_right, p_bottom, p_left):
    top = right = bottom = left = 0
    for p in range(VARIABLES):
        if (domain >> p) & 1:
            top    |= p_top[p]
            right  |= p_right[p]
            bottom |= p_bottom[p]
            left   |= p_left[p]
    return top, right, bottom, left

def pack(arr):
    val = 0
    for p in range(VARIABLES):
        val |= (arr[p] & TC_MASK) << (p * TC)
    return val

async def apply(dut, domain, p_top, p_right, p_bottom, p_left):
    dut.domain.value  = domain
    dut.p_top.value   = pack(p_top)
    dut.p_right.value = pack(p_right)
    dut.p_bottom.value = pack(p_bottom)
    dut.p_left.value  = pack(p_left)
    await Timer(1, unit="ns")

async def check(dut, domain, p_top, p_right, p_bottom, p_left):
    await apply(dut, domain, p_top, p_right, p_bottom, p_left)
    exp_top, exp_right, exp_bottom, exp_left = reference(domain, p_top, p_right, p_bottom, p_left)
    assert dut.top.value    == exp_top,    f"top={dut.top.value} expected={exp_top}"
    assert dut.right.value  == exp_right,  f"right={dut.right.value} expected={exp_right}"
    assert dut.bottom.value == exp_bottom, f"bottom={dut.bottom.value} expected={exp_bottom}"
    assert dut.left.value   == exp_left,   f"left={dut.left.value} expected={exp_left}"

@cocotb.test()
async def test_empty_domain(dut):
    """Empty domain gives all-zero colours."""
    p = [TC_MASK] * VARIABLES
    await check(dut, 0, p, p, p, p)
    assert dut.top.value == 0
    cocotb.log.info("empty domain ✓")

@cocotb.test()
async def test_single_piece(dut):
    """Single piece in domain — its colours appear exactly."""
    p_top    = [0b000001 if p == 3 else 0 for p in range(VARIABLES)]
    p_right  = [0b000010 if p == 3 else 0 for p in range(VARIABLES)]
    p_bottom = [0b000100 if p == 3 else 0 for p in range(VARIABLES)]
    p_left   = [0b001000 if p == 3 else 0 for p in range(VARIABLES)]
    await check(dut, 1 << 3, p_top, p_right, p_bottom, p_left)
    assert dut.top.value    == 0b000001
    assert dut.right.value  == 0b000010
    assert dut.bottom.value == 0b000100
    assert dut.left.value   == 0b001000
    cocotb.log.info("single piece ✓")

@cocotb.test()
async def test_all_pieces_same_colour(dut):
    """All pieces same colour — output equals that colour."""
    p = [0b101010] * VARIABLES
    await check(dut, ALL_DOMAIN, p, p, p, p)
    assert dut.top.value == 0b101010
    cocotb.log.info("all same colour ✓")

@cocotb.test()
async def test_or_accumulation(dut):
    """Different pieces contribute different bits — all ORed together."""
    p_top = [1 << (p % TC) for p in range(VARIABLES)]
    p_right = p_top
    p_bottom = p_top
    p_left = p_top
    await check(dut, ALL_DOMAIN, p_top, p_right, p_bottom, p_left)
    cocotb.log.info("OR accumulation ✓")

@cocotb.test()
async def test_piece_not_in_domain_ignored(dut):
    """Piece not in domain doesn't contribute its colour."""
    p_top    = [TC_MASK if p == 0 else 0 for p in range(VARIABLES)]
    p_right  = [TC_MASK if p == 0 else 0 for p in range(VARIABLES)]
    p_bottom = [TC_MASK if p == 0 else 0 for p in range(VARIABLES)]
    p_left   = [TC_MASK if p == 0 else 0 for p in range(VARIABLES)]
    # exclude piece 0 from domain
    await check(dut, ALL_DOMAIN & ~1, p_top, p_right, p_bottom, p_left)
    assert dut.top.value == 0
    cocotb.log.info("excluded piece ignored ✓")

@cocotb.test()
async def test_random(dut):
    """100 random inputs verified against Python reference."""
    random.seed(77)
    for _ in range(100):
        domain = random.randint(0, ALL_DOMAIN)
        p_top    = [random.randint(0, TC_MASK) for _ in range(VARIABLES)]
        p_right  = [random.randint(0, TC_MASK) for _ in range(VARIABLES)]
        p_bottom = [random.randint(0, TC_MASK) for _ in range(VARIABLES)]
        p_left   = [random.randint(0, TC_MASK) for _ in range(VARIABLES)]
        await check(dut, domain, p_top, p_right, p_bottom, p_left)
    cocotb.log.info("100 random tests passed ✓")

def test_DomainToColourRotation():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/DomainToColourRotation.sv"],
        hdl_toplevel="DomainToColourRotation",
        parameters={"VARIABLES": VARIABLES, "TC": TC},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="DomainToColourRotation",
        test_module="test_DomainToColourRotation",
    )