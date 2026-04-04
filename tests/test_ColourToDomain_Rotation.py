import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

V  = 16
CC = 6
CC_MASK  = (1 << CC) - 1
ALL_DOMAIN = (1 << V) - 1

def pack_elements(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & CC_MASK) << (i * CC)
    return val

def reference(domain, c_top, c_right, c_bottom, c_left,
              el_top, el_right, el_bottom, el_left):
    out = 0
    for p in range(V):
        if (domain >> p) & 1:
            if (c_top    & el_top[p])    != 0 and \
               (c_right  & el_right[p])  != 0 and \
               (c_bottom & el_bottom[p]) != 0 and \
               (c_left   & el_left[p])   != 0:
                out |= 1 << p
    changed = out != domain
    deadend = (domain != 0) and (out == 0)
    return out, changed, deadend

async def apply(dut, domain, c_top, c_right, c_bottom, c_left,
                el_top, el_right, el_bottom, el_left):
    dut.in_domain.value         = domain
    dut.in_colour_top.value     = c_top
    dut.in_colour_right.value   = c_right
    dut.in_colour_bottom.value  = c_bottom
    dut.in_colour_left.value    = c_left
    dut.in_element_top.value    = pack_elements(el_top)
    dut.in_element_right.value  = pack_elements(el_right)
    dut.in_element_bottom.value = pack_elements(el_bottom)
    dut.in_element_left.value   = pack_elements(el_left)
    await Timer(1, unit="ns")

async def check(dut, domain, c_top, c_right, c_bottom, c_left,
                el_top, el_right, el_bottom, el_left):
    await apply(dut, domain, c_top, c_right, c_bottom, c_left,
                el_top, el_right, el_bottom, el_left)
    exp_domain, exp_changed, exp_deadend = \
        reference(domain, c_top, c_right, c_bottom, c_left,
                  el_top, el_right, el_bottom, el_left)
    assert dut.out_domain.value  == exp_domain, \
        f"domain={dut.out_domain.value:#x} exp={exp_domain:#x}"
    assert dut.out_changed.value == int(exp_changed), \
        f"changed={dut.out_changed.value} exp={int(exp_changed)}"
    assert dut.out_deadend.value == int(exp_deadend), \
        f"deadend={dut.out_deadend.value} exp={int(exp_deadend)}"

def make_full_elements():
    return [CC_MASK] * V

def make_zero_elements():
    return [0] * V

@cocotb.test()
async def test_empty_domain(dut):
    """Empty domain — output zero, no change, no deadend."""
    el = make_full_elements()
    await check(dut, 0, CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el, el, el, el)
    assert dut.out_domain.value  == 0
    assert dut.out_changed.value == 0
    assert dut.out_deadend.value == 0
    cocotb.log.info("empty domain ✓")

@cocotb.test()
async def test_all_pass_full_colours(dut):
    """All pieces pass when colours are all-ones — domain unchanged."""
    el = make_full_elements()
    await check(dut, ALL_DOMAIN, CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el, el, el, el)
    assert dut.out_domain.value  == ALL_DOMAIN
    assert dut.out_changed.value == 0
    assert dut.out_deadend.value == 0
    cocotb.log.info("all pass full colours ✓")

@cocotb.test()
async def test_all_fail_zero_colour(dut):
    """Zero colour constraint — all pieces fail, deadend."""
    el = make_full_elements()
    await check(dut, ALL_DOMAIN, 0, CC_MASK, CC_MASK, CC_MASK,
                el, el, el, el)
    assert dut.out_domain.value  == 0
    assert dut.out_deadend.value == 1
    assert dut.out_changed.value == 1
    cocotb.log.info("zero colour → deadend ✓")

@cocotb.test()
async def test_single_piece_passes(dut):
    """Only piece 3 has matching top colour — only bit 3 survives."""
    el_top = make_zero_elements()
    el_top[3] = 0b001100  # piece 3 has top colour matching constraint
    el_full = make_full_elements()
    await check(dut, ALL_DOMAIN, 0b001100, CC_MASK, CC_MASK, CC_MASK,
                el_top, el_full, el_full, el_full)
    assert dut.out_domain.value == (1 << 3)
    assert dut.out_changed.value == 1
    cocotb.log.info("single piece passes ✓")

@cocotb.test()
async def test_piece_fails_one_edge(dut):
    """Piece fails if any single edge has no overlap."""
    el_top    = make_full_elements()
    el_right  = make_full_elements()
    el_bottom = make_full_elements()
    el_left   = make_zero_elements()  # no left colour for any piece
    await check(dut, ALL_DOMAIN, CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el_top, el_right, el_bottom, el_left)
    assert dut.out_domain.value  == 0
    assert dut.out_deadend.value == 1
    cocotb.log.info("fail on one edge ✓")

@cocotb.test()
async def test_inactive_piece_ignored(dut):
    """Piece not in domain is ignored even if it would pass."""
    el = make_full_elements()
    domain = ALL_DOMAIN & ~1  # piece 0 not in domain
    await check(dut, domain, CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el, el, el, el)
    assert not (int(dut.out_domain.value) & 1), "piece 0 should not appear in output"
    cocotb.log.info("inactive piece ignored ✓")

@cocotb.test()
async def test_partial_colour_overlap(dut):
    """Partial overlap is sufficient — piece survives."""
    el_top = make_zero_elements()
    el_top[0] = 0b000001  # only bit 0 set
    el_full = make_full_elements()
    # constraint has bit 0 set — overlap exists
    await check(dut, 1, 0b000001, CC_MASK, CC_MASK, CC_MASK,
                el_top, el_full, el_full, el_full)
    assert dut.out_domain.value == 1
    assert dut.out_deadend.value == 0
    cocotb.log.info("partial overlap sufficient ✓")

@cocotb.test()
async def test_no_change_when_all_pass(dut):
    """No change flag when all pieces in domain still pass."""
    el = make_full_elements()
    domain = 0b1010  # pieces 1 and 3
    await check(dut, domain, CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el, el, el, el)
    assert dut.out_domain.value  == domain
    assert dut.out_changed.value == 0
    cocotb.log.info("no change ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(37)
    for _ in range(50):
        domain  = random.randint(0, ALL_DOMAIN)
        c_top   = random.randint(0, CC_MASK)
        c_right = random.randint(0, CC_MASK)
        c_bot   = random.randint(0, CC_MASK)
        c_left  = random.randint(0, CC_MASK)
        el_t = [random.randint(0, CC_MASK) for _ in range(V)]
        el_r = [random.randint(0, CC_MASK) for _ in range(V)]
        el_b = [random.randint(0, CC_MASK) for _ in range(V)]
        el_l = [random.randint(0, CC_MASK) for _ in range(V)]
        await check(dut, domain, c_top, c_right, c_bot, c_left,
                    el_t, el_r, el_b, el_l)
    cocotb.log.info("50 random tests ✓")

def test_ColourToDomain_Rotation():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/ColourToDomain_Rotation.sv"],
        hdl_toplevel="ColourToDomain_Rotation",
        parameters={"V": V, "CC": CC},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="ColourToDomain_Rotation",
        test_module="test_ColourToDomain_Rotation",
    )