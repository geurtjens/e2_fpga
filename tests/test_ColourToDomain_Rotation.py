import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

V  = 16
CC = 6
CC_MASK    = (1 << CC) - 1
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
    return out


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
    exp = reference(domain, c_top, c_right, c_bottom, c_left,
                    el_top, el_right, el_bottom, el_left)
    assert int(dut.out_domain.value) == exp, \
        f"domain={int(dut.out_domain.value):#x} exp={exp:#x}"


def make_full_elements(): return [CC_MASK] * V
def make_zero_elements(): return [0]       * V


@cocotb.test()
async def test_empty_domain(dut):
    """Empty domain — output zero."""
    el = make_full_elements()
    await check(dut, 0, CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el, el, el, el)
    assert int(dut.out_domain.value) == 0
    cocotb.log.info("empty domain ✓")


@cocotb.test()
async def test_full_domain_full_colours_unchanged(dut):
    """Full domain, all-ones colours and elements — domain unchanged."""
    el = make_full_elements()
    await check(dut, ALL_DOMAIN, CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el, el, el, el)
    assert int(dut.out_domain.value) == ALL_DOMAIN
    cocotb.log.info("full domain unchanged ✓")


@cocotb.test()
async def test_zero_colour_eliminates_all(dut):
    """Zero colour on any face eliminates all tiles."""
    el = make_full_elements()
    await check(dut, ALL_DOMAIN, 0, CC_MASK, CC_MASK, CC_MASK,
                el, el, el, el)
    assert int(dut.out_domain.value) == 0
    cocotb.log.info("zero colour eliminates all ✓")


@cocotb.test()
async def test_single_piece_passes_top(dut):
    """Only piece 3 has matching top colour — only bit 3 survives."""
    el_top = make_zero_elements(); el_top[3] = 0b001100
    el_ful = make_full_elements()
    await check(dut, ALL_DOMAIN, 0b001100, CC_MASK, CC_MASK, CC_MASK,
                el_top, el_ful, el_ful, el_ful)
    assert int(dut.out_domain.value) == (1 << 3)
    cocotb.log.info("single piece passes top ✓")


@cocotb.test()
async def test_single_piece_passes_right(dut):
    """Only piece 5 has matching right colour — only bit 5 survives."""
    el_right = make_zero_elements(); el_right[5] = 0b000011
    el_ful   = make_full_elements()
    await check(dut, ALL_DOMAIN, CC_MASK, 0b000011, CC_MASK, CC_MASK,
                el_ful, el_right, el_ful, el_ful)
    assert int(dut.out_domain.value) == (1 << 5)
    cocotb.log.info("single piece passes right ✓")


@cocotb.test()
async def test_single_piece_passes_bottom(dut):
    """Only piece 7 has matching bottom colour — only bit 7 survives."""
    el_bottom = make_zero_elements(); el_bottom[7] = 0b110000
    el_ful    = make_full_elements()
    await check(dut, ALL_DOMAIN, CC_MASK, CC_MASK, 0b110000, CC_MASK,
                el_ful, el_ful, el_bottom, el_ful)
    assert int(dut.out_domain.value) == (1 << 7)
    cocotb.log.info("single piece passes bottom ✓")


@cocotb.test()
async def test_single_piece_passes_left(dut):
    """Only piece 2 has matching left colour — only bit 2 survives."""
    el_left = make_zero_elements(); el_left[2] = 0b001010
    el_ful  = make_full_elements()
    await check(dut, ALL_DOMAIN, CC_MASK, CC_MASK, CC_MASK, 0b001010,
                el_ful, el_ful, el_ful, el_left)
    assert int(dut.out_domain.value) == (1 << 2)
    cocotb.log.info("single piece passes left ✓")


@cocotb.test()
async def test_piece_fails_one_edge(dut):
    """A piece fails if any single edge has no colour overlap."""
    el_top    = make_full_elements()
    el_right  = make_full_elements()
    el_bottom = make_full_elements()
    el_left   = make_zero_elements()  # no left colour for any piece
    await check(dut, ALL_DOMAIN, CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el_top, el_right, el_bottom, el_left)
    assert int(dut.out_domain.value) == 0
    cocotb.log.info("piece fails one edge ✓")


@cocotb.test()
async def test_inactive_piece_ignored(dut):
    """Piece not in domain is ignored even if it would pass."""
    el  = make_full_elements()
    dom = ALL_DOMAIN & ~(1 << 0)  # piece 0 not in domain
    await check(dut, dom, CC_MASK, CC_MASK, CC_MASK, CC_MASK,
                el, el, el, el)
    assert not (int(dut.out_domain.value) & 1), "piece 0 should not appear in output"
    cocotb.log.info("inactive piece ignored ✓")


@cocotb.test()
async def test_partial_colour_overlap_sufficient(dut):
    """Partial overlap is sufficient — piece survives if any bit matches."""
    el_top = make_zero_elements(); el_top[0] = 0b000001
    el_ful = make_full_elements()
    await check(dut, 1, 0b000001, CC_MASK, CC_MASK, CC_MASK,
                el_top, el_ful, el_ful, el_ful)
    assert int(dut.out_domain.value) == 1
    cocotb.log.info("partial overlap sufficient ✓")


@cocotb.test()
async def test_all_four_faces_checked_independently(dut):
    """Each face is checked — a piece fails if any face has no overlap."""
    A, B, C, D = 0b000001, 0b000010, 0b000100, 0b001000
    el_top    = [A] * V; el_top[4]    = 0  # tile 4 fails top
    el_right  = [B] * V; el_right[3]  = 0  # tile 3 fails right
    el_bottom = [C] * V; el_bottom[2] = 0  # tile 2 fails bottom
    el_left   = [D] * V; el_left[1]   = 0  # tile 1 fails left

    await check(dut, ALL_DOMAIN, A, B, C, D,
                el_top, el_right, el_bottom, el_left)

    out = int(dut.out_domain.value)
    assert     (out >> 0) & 1, "tile 0 should survive"
    assert not (out >> 1) & 1, "tile 1 should fail (left=0)"
    assert not (out >> 2) & 1, "tile 2 should fail (bottom=0)"
    assert not (out >> 3) & 1, "tile 3 should fail (right=0)"
    assert not (out >> 4) & 1, "tile 4 should fail (top=0)"
    cocotb.log.info("all four faces checked independently ✓")


@cocotb.test()
async def test_sparse_domain(dut):
    """Sparse domain — only bits present in domain are considered."""
    el_top = make_zero_elements()
    el_top[0] = 0b001100
    el_top[5] = 0b001100
    el_top[9] = 0b110000  # different colour — won't match
    el_ful = make_full_elements()
    domain = (1 << 0) | (1 << 5) | (1 << 9)
    await check(dut, domain, 0b001100, CC_MASK, CC_MASK, CC_MASK,
                el_top, el_ful, el_ful, el_ful)
    out = int(dut.out_domain.value)
    assert     (out >> 0) & 1, "tile 0 should survive"
    assert     (out >> 5) & 1, "tile 5 should survive"
    assert not (out >> 9) & 1, "tile 9 should be eliminated"
    cocotb.log.info("sparse domain ✓")


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