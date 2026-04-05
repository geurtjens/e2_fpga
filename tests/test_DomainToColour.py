import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N  = 4
CC = 6
V  = N * N
CC_MASK = (1 << CC) - 1
ALL_DOMAIN = (1 << V) - 1

def pack_domain_array(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL_DOMAIN) << (i * V)
    return val

def pack_colour_array(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & CC_MASK) << (i * CC)
    return val

def unpack_colour_array(val):
    return [(val >> (i * CC)) & CC_MASK for i in range(V)]

def vid(x, y): return y * N + x

def rotation_for_position(x, y):
    """Which rotation is used for corners and edges."""
    if y == N-1 and x == 0:   return 0  # bottom-left corner
    if y == 0   and x == 0:   return 1  # top-left corner
    if y == 0   and x == N-1: return 2  # top-right corner
    if y == N-1 and x == N-1: return 3  # bottom-right corner
    if y == N-1: return 0  # bottom edge
    if x == 0:   return 1  # left edge
    if y == 0:   return 2  # top edge
    if x == N-1: return 3  # right edge
    return -1  # inner

def rotate_elements(el_top, el_right, el_bottom, el_left, rotation):
    """Derive a rotated element set from the base orientation.
    Matches the internal rewiring done by DomainToColour:
      rotation 0:  top=top,    right=right,  bottom=bottom, left=left
      rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
      rotation 2:  top=bottom, right=left,   bottom=top,    left=right
      rotation 3:  top=right,  right=bottom, bottom=left,   left=top
    """
    if rotation == 0:
        return el_top, el_right, el_bottom, el_left
    elif rotation == 1:
        return el_left, el_top, el_right, el_bottom
    elif rotation == 2:
        return el_bottom, el_left, el_top, el_right
    elif rotation == 3:
        return el_right, el_bottom, el_left, el_top

def reference(in_r0, in_r1, in_r2, in_r3,
              in_c_top, in_c_right, in_c_bottom, in_c_left,
              el_top, el_right, el_bottom, el_left):
    """Reference model — derives all four rotations from the base
    element set by rewiring sides, matching DomainToColour internally."""

    domains = [in_r0, in_r1, in_r2, in_r3]

    out_top    = [0] * V
    out_right  = [0] * V
    out_bottom = [0] * V
    out_left   = [0] * V

    for gy in range(N):
        for gx in range(N):
            i = vid(gx, gy)
            rot = rotation_for_position(gx, gy)

            if rot >= 0:
                # corner or edge — single rotation
                domain = domains[rot][i]
                r_top, r_right, r_bottom, r_left = rotate_elements(
                    el_top, el_right, el_bottom, el_left, rot)
                t = r = b = l = 0
                for p in range(V):
                    if (domain >> p) & 1:
                        t |= r_top[p]
                        r |= r_right[p]
                        b |= r_bottom[p]
                        l |= r_left[p]
                out_top[i]    = t
                out_right[i]  = r
                out_bottom[i] = b
                out_left[i]   = l
            else:
                # inner — OR all four rotations
                t = r = b = l = 0
                for rot_idx in range(4):
                    domain = domains[rot_idx][i]
                    r_top, r_right, r_bottom, r_left = rotate_elements(
                        el_top, el_right, el_bottom, el_left, rot_idx)
                    for p in range(V):
                        if (domain >> p) & 1:
                            t |= r_top[p]
                            r |= r_right[p]
                            b |= r_bottom[p]
                            l |= r_left[p]
                out_top[i]    = t
                out_right[i]  = r
                out_bottom[i] = b
                out_left[i]   = l

    changed = any(
        out_top[i] != in_c_top[i] or out_right[i] != in_c_right[i] or
        out_bottom[i] != in_c_bottom[i] or out_left[i] != in_c_left[i]
        for i in range(V)
    )

    deadend = any(
        (in_r0[i] | in_r1[i] | in_r2[i] | in_r3[i]) != 0 and
        (out_top[i] | out_right[i] | out_bottom[i] | out_left[i]) == 0
        for i in range(V)
    )

    return out_top, out_right, out_bottom, out_left, changed, deadend

def make_zero_elements(): return [0]        * V
def make_full_elements(): return [CC_MASK]  * V
def make_zero_domains():  return [0]        * V
def make_full_domains():  return [ALL_DOMAIN] * V

async def apply(dut,
                in_r0, in_r1, in_r2, in_r3,
                in_c_top, in_c_right, in_c_bottom, in_c_left,
                el_top, el_right, el_bottom, el_left):
    dut.in_domain_r0.value      = pack_domain_array(in_r0)
    dut.in_domain_r1.value      = pack_domain_array(in_r1)
    dut.in_domain_r2.value      = pack_domain_array(in_r2)
    dut.in_domain_r3.value      = pack_domain_array(in_r3)
    dut.in_colours_top.value    = pack_colour_array(in_c_top)
    dut.in_colours_right.value  = pack_colour_array(in_c_right)
    dut.in_colours_bottom.value = pack_colour_array(in_c_bottom)
    dut.in_colours_left.value   = pack_colour_array(in_c_left)
    dut.in_elements_top.value    = pack_colour_array(el_top)
    dut.in_elements_right.value  = pack_colour_array(el_right)
    dut.in_elements_bottom.value = pack_colour_array(el_bottom)
    dut.in_elements_left.value   = pack_colour_array(el_left)
    await Timer(1, unit="ns")

async def check(dut,
                in_r0, in_r1, in_r2, in_r3,
                in_c_top, in_c_right, in_c_bottom, in_c_left,
                el_top, el_right, el_bottom, el_left):
    await apply(dut,
                in_r0, in_r1, in_r2, in_r3,
                in_c_top, in_c_right, in_c_bottom, in_c_left,
                el_top, el_right, el_bottom, el_left)

    exp_top, exp_right, exp_bottom, exp_left, exp_ch, exp_de = reference(
        in_r0, in_r1, in_r2, in_r3,
        in_c_top, in_c_right, in_c_bottom, in_c_left,
        el_top, el_right, el_bottom, el_left)

    act_top    = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    act_right  = unpack_colour_array(dut.out_colours_right.value.to_unsigned())
    act_bottom = unpack_colour_array(dut.out_colours_bottom.value.to_unsigned())
    act_left   = unpack_colour_array(dut.out_colours_left.value.to_unsigned())

    for i in range(V):
        assert act_top[i]    == exp_top[i],    f"top[{i}]={act_top[i]:06b} exp={exp_top[i]:06b}"
        assert act_right[i]  == exp_right[i],  f"right[{i}]={act_right[i]:06b} exp={exp_right[i]:06b}"
        assert act_bottom[i] == exp_bottom[i], f"bottom[{i}]={act_bottom[i]:06b} exp={exp_bottom[i]:06b}"
        assert act_left[i]   == exp_left[i],   f"left[{i}]={act_left[i]:06b} exp={exp_left[i]:06b}"

    assert dut.out_changed.value == int(exp_ch), \
        f"changed={dut.out_changed.value} exp={int(exp_ch)}"
    assert dut.out_deadend.value == int(exp_de), \
        f"deadend={dut.out_deadend.value} exp={int(exp_de)}"

@cocotb.test()
async def test_empty_domains(dut):
    """All domains empty — all output colours zero, no deadend."""
    r  = make_zero_domains()
    c  = make_zero_elements()
    el = make_full_elements()
    await check(dut, r, r, r, r, c, c, c, c, el, el, el, el)
    assert dut.out_deadend.value == 0
    assert dut.out_changed.value == 0
    cocotb.log.info("empty domains ✓")

@cocotb.test()
async def test_single_piece_bottom_left_corner(dut):
    """Bottom-left corner uses rotation 0 (base orientation).
    Piece 0 contributes its base top colour directly."""
    i = vid(0, N-1)
    r0 = make_zero_domains(); r0[i] = 1 << 0
    r1 = r2 = r3 = make_zero_domains()
    c  = make_zero_elements()

    el_top = [0] * V; el_top[0] = 0b001100
    el_zer = make_zero_elements()

    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el_top, el_zer, el_zer, el_zer)

    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b001100
    cocotb.log.info("bottom-left corner rotation 0 ✓")

@cocotb.test()
async def test_single_piece_top_left_corner(dut):
    """Top-left corner uses rotation 1 (top=left, right=top, bottom=right, left=bottom).
    Piece 2 with el_left=0b010101 — rotation 1 maps left→top so top should be 0b010101."""
    i = vid(0, 0)
    r1 = make_zero_domains(); r1[i] = 1 << 2
    r0 = r2 = r3 = make_zero_domains()
    c  = make_zero_elements()

    el_left = [0] * V; el_left[2] = 0b010101
    el_zer  = make_zero_elements()

    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el_zer, el_zer, el_zer, el_left)

    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b010101, \
        f"rotation 1 maps left→top, got {act_top[i]:06b}"
    cocotb.log.info("top-left corner rotation 1 ✓")

@cocotb.test()
async def test_inner_ors_all_rotations(dut):
    """Inner variable ORs colours from all four rotations.
    Each rotation contributes a distinct colour bit via the rewired sides."""
    i = vid(1, 1)
    r0 = make_zero_domains(); r0[i] = 1 << 0
    r1 = make_zero_domains(); r1[i] = 1 << 1
    r2 = make_zero_domains(); r2[i] = 1 << 2
    r3 = make_zero_domains(); r3[i] = 1 << 3
    c  = make_zero_elements()

    # rotation 0: top=top     → piece 0 contributes 0b000001 to top
    # rotation 1: top=left    → piece 1 contributes el_left[1]=0b000010 to top
    # rotation 2: top=bottom  → piece 2 contributes el_bottom[2]=0b000100 to top
    # rotation 3: top=right   → piece 3 contributes el_right[3]=0b001000 to top
    el_top    = [0]*V; el_top[0]    = 0b000001
    el_right  = [0]*V; el_right[3]  = 0b001000
    el_bottom = [0]*V; el_bottom[2] = 0b000100
    el_left   = [0]*V; el_left[1]   = 0b000010

    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el_top, el_right, el_bottom, el_left)

    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b001111, \
        f"expected all four rotation bits OR'd, got {act_top[i]:06b}"
    cocotb.log.info("inner OR all rotations ✓")

@cocotb.test()
async def test_changed_detected(dut):
    """Changed flag set when output differs from input colours."""
    i  = vid(0, N-1)
    r0 = make_zero_domains(); r0[i] = 1 << 0
    r1 = r2 = r3 = make_zero_domains()
    c  = make_zero_elements()

    el_top = [0]*V; el_top[0] = 0b001100
    el_zer = make_zero_elements()

    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el_top, el_zer, el_zer, el_zer)
    assert dut.out_changed.value == 1
    cocotb.log.info("changed detected ✓")

@cocotb.test()
async def test_no_change_when_colours_match(dut):
    """No change when output equals input colours."""
    i  = vid(0, N-1)
    r0 = make_zero_domains(); r0[i] = 1 << 0
    r1 = r2 = r3 = make_zero_domains()

    el_top = [0]*V; el_top[0] = 0b001100
    el_zer = make_zero_elements()

    c_top = make_zero_elements(); c_top[i] = 0b001100

    await check(dut, r0, r1, r2, r3,
                c_top, make_zero_elements(),
                make_zero_elements(), make_zero_elements(),
                el_top, el_zer, el_zer, el_zer)
    assert dut.out_changed.value == 0
    cocotb.log.info("no change when colours match ✓")

@cocotb.test()
async def test_deadend_active_variable_zero_colours(dut):
    """Deadend when active variable produces all-zero colours."""
    i  = vid(0, N-1)
    r0 = make_zero_domains(); r0[i] = 1 << 0
    r1 = r2 = r3 = make_zero_domains()
    c  = make_zero_elements()
    el_zer = make_zero_elements()

    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el_zer, el_zer, el_zer, el_zer)
    assert dut.out_deadend.value == 1
    cocotb.log.info("deadend ✓")

@cocotb.test()
async def test_rotation_wiring(dut):
    """Verify the internal rotation rewiring is correct for all corners.
    Uses asymmetric elements so each rotation produces a distinct top colour,
    then checks each corner gets the expected value."""

    # unique colour per base side
    A, B, C, D = 0b000001, 0b000010, 0b000100, 0b001000
    el_top    = [A] * V
    el_right  = [B] * V
    el_bottom = [C] * V
    el_left   = [D] * V

    # for each corner, which rotation it uses and what top colour to expect:
    # rotation 0: top=top    → A
    # rotation 1: top=left   → D
    # rotation 2: top=bottom → C
    # rotation 3: top=right  → B
    corners = [
        (vid(0,   N-1), 0, A),  # bottom-left  — rotation 0
        (vid(0,   0),   1, D),  # top-left     — rotation 1
        (vid(N-1, 0),   2, C),  # top-right    — rotation 2
        (vid(N-1, N-1), 3, B),  # bottom-right — rotation 3
    ]

    for corner_id, rot, expected_top in corners:
        r0 = make_zero_domains()
        r1 = make_zero_domains()
        r2 = make_zero_domains()
        r3 = make_zero_domains()
        [r0, r1, r2, r3][rot][corner_id] = ALL_DOMAIN
        c = make_zero_elements()

        await check(dut, r0, r1, r2, r3, c, c, c, c,
                    el_top, el_right, el_bottom, el_left)

        act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
        assert act_top[corner_id] == expected_top, \
            f"corner {corner_id} rotation {rot}: top={act_top[corner_id]:06b} exp={expected_top:06b}"
        cocotb.log.info(f"rotation wiring corner {corner_id} rotation {rot} ✓")

@cocotb.test()
async def test_random(dut):
    """30 random inputs verified against reference."""
    random.seed(66)
    for _ in range(30):
        def rd(): return [random.randint(0, ALL_DOMAIN) for _ in range(V)]
        def rc(): return [random.randint(0, CC_MASK)    for _ in range(V)]
        r0, r1, r2, r3 = rd(), rd(), rd(), rd()
        c_t, c_r, c_b, c_l = rc(), rc(), rc(), rc()
        el_t, el_r, el_b, el_l = rc(), rc(), rc(), rc()
        await check(dut, r0, r1, r2, r3, c_t, c_r, c_b, c_l,
                    el_t, el_r, el_b, el_l)
    cocotb.log.info("30 random tests ✓")

def test_DomainToColour():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/DomainToColour_Rotation.sv",
            "rtl/DomainToColour.sv",
        ],
        hdl_toplevel="DomainToColour",
        parameters={"N": N, "CC": CC},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="DomainToColour",
        test_module="test_DomainToColour",
    )