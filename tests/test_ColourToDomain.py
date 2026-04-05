import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N  = 4
CC = 6
V  = N * N
CC_MASK    = (1 << CC) - 1
ALL_DOMAIN = (1 << V) - 1

def pack_domain_array(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL_DOMAIN) << (i * V)
    return val

def unpack_domain_array(val):
    return [(val >> (i * V)) & ALL_DOMAIN for i in range(V)]

def pack_colour_array(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & CC_MASK) << (i * CC)
    return val

def pack_elements(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & CC_MASK) << (i * CC)
    return val

def vid(x, y): return y * N + x

def rotation_for_position(x, y):
    if   y == N-1 and x == 0:    return 0  # bottom-left
    elif y == 0   and x == 0:    return 1  # top-left
    elif y == 0   and x == N-1:  return 2  # top-right
    elif y == N-1 and x == N-1:  return 3  # bottom-right
    elif y == N-1:                return 0  # bottom edge
    elif x == 0:                  return 1  # left edge
    elif y == 0:                  return 2  # top edge
    elif x == N-1:                return 3  # right edge
    else:                         return -1 # inner

def rotate_elements(el_top, el_right, el_bottom, el_left, rotation):
    """Derive a rotated element set from the base orientation.
    Matches the internal rewiring done by ColourToDomain:
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

def reference_rotation(domain, c_top, c_right, c_bottom, c_left,
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

def reference(in_r0, in_r1, in_r2, in_r3,
              c_top, c_right, c_bottom, c_left,
              el_top, el_right, el_bottom, el_left):
    """Reference model — derives rotations from base element set,
    matching the internal rewiring in ColourToDomain."""

    domains_in  = [in_r0, in_r1, in_r2, in_r3]
    out_r0 = list(in_r0)
    out_r1 = list(in_r1)
    out_r2 = list(in_r2)
    out_r3 = list(in_r3)
    out_domains = [out_r0, out_r1, out_r2, out_r3]

    changed = False
    deadend = False

    for gy in range(N):
        for gx in range(N):
            i = vid(gx, gy)
            rot = rotation_for_position(gx, gy)

            if rot >= 0:
                r_top, r_right, r_bottom, r_left = rotate_elements(
                    el_top, el_right, el_bottom, el_left, rot)
                result, ch, de = reference_rotation(
                    domains_in[rot][i],
                    c_top[i], c_right[i], c_bottom[i], c_left[i],
                    r_top, r_right, r_bottom, r_left)
                out_domains[rot][i] = result
                if ch: changed = True
                if de: deadend = True
            else:
                # inner — all four rotations
                for r_idx in range(4):
                    r_top, r_right, r_bottom, r_left = rotate_elements(
                        el_top, el_right, el_bottom, el_left, r_idx)
                    result, ch, de = reference_rotation(
                        domains_in[r_idx][i],
                        c_top[i], c_right[i], c_bottom[i], c_left[i],
                        r_top, r_right, r_bottom, r_left)
                    out_domains[r_idx][i] = result
                    if ch: changed = True
                    if de: deadend = True

    return out_r0, out_r1, out_r2, out_r3, changed, deadend

async def apply(dut,
                in_r0, in_r1, in_r2, in_r3,
                c_top, c_right, c_bottom, c_left,
                el_top, el_right, el_bottom, el_left):
    dut.in_domain_r0.value = pack_domain_array(in_r0)
    dut.in_domain_r1.value = pack_domain_array(in_r1)
    dut.in_domain_r2.value = pack_domain_array(in_r2)
    dut.in_domain_r3.value = pack_domain_array(in_r3)
    dut.in_colours_top.value    = pack_colour_array(c_top)
    dut.in_colours_right.value  = pack_colour_array(c_right)
    dut.in_colours_bottom.value = pack_colour_array(c_bottom)
    dut.in_colours_left.value   = pack_colour_array(c_left)
    dut.in_elements_top.value    = pack_elements(el_top)
    dut.in_elements_right.value  = pack_elements(el_right)
    dut.in_elements_bottom.value = pack_elements(el_bottom)
    dut.in_elements_left.value   = pack_elements(el_left)
    await Timer(1, unit="ns")

async def check(dut,
                in_r0, in_r1, in_r2, in_r3,
                c_top, c_right, c_bottom, c_left,
                el_top, el_right, el_bottom, el_left):
    await apply(dut,
                in_r0, in_r1, in_r2, in_r3,
                c_top, c_right, c_bottom, c_left,
                el_top, el_right, el_bottom, el_left)

    exp_r0, exp_r1, exp_r2, exp_r3, exp_ch, exp_de = reference(
        in_r0, in_r1, in_r2, in_r3,
        c_top, c_right, c_bottom, c_left,
        el_top, el_right, el_bottom, el_left)

    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())

    for i in range(V):
        assert act_r0[i] == exp_r0[i], f"r0[{i}]={act_r0[i]:#x} exp={exp_r0[i]:#x}"
        assert act_r1[i] == exp_r1[i], f"r1[{i}]={act_r1[i]:#x} exp={exp_r1[i]:#x}"
        assert act_r2[i] == exp_r2[i], f"r2[{i}]={act_r2[i]:#x} exp={exp_r2[i]:#x}"
        assert act_r3[i] == exp_r3[i], f"r3[{i}]={act_r3[i]:#x} exp={exp_r3[i]:#x}"

    assert dut.out_changed.value == int(exp_ch), \
        f"changed={dut.out_changed.value} exp={int(exp_ch)}"
    assert dut.out_deadend.value == int(exp_de), \
        f"deadend={dut.out_deadend.value} exp={int(exp_de)}"

def make_full_el():  return [CC_MASK]    * V
def make_zero_el():  return [0]          * V
def make_full_dom(): return [ALL_DOMAIN] * V
def make_zero_dom(): return [0]          * V
def make_full_col(): return [CC_MASK]    * V
def make_zero_col(): return [0]          * V

@cocotb.test()
async def test_empty_domains(dut):
    """All domains empty — no change, no deadend."""
    r  = make_zero_dom()
    c  = make_full_col()
    el = make_full_el()
    await check(dut, r, r, r, r, c, c, c, c, el, el, el, el)
    assert dut.out_changed.value == 0
    assert dut.out_deadend.value == 0
    cocotb.log.info("empty domains ✓")

@cocotb.test()
async def test_all_pass_full_colours(dut):
    """Full domains, all-ones colours and elements — no change."""
    r  = make_full_dom()
    c  = make_full_col()
    el = make_full_el()
    await check(dut, r, r, r, r, c, c, c, c, el, el, el, el)
    assert dut.out_changed.value == 0
    assert dut.out_deadend.value == 0
    cocotb.log.info("all pass full colours ✓")

@cocotb.test()
async def test_bottom_left_uses_rotation0(dut):
    """Bottom-left corner uses rotation 0 only.
    Zero base elements means rotation 0 gets zero top/right/bottom/left
    so all pieces are filtered out — deadend expected."""
    i  = vid(0, N-1)
    r0 = make_zero_dom(); r0[i] = ALL_DOMAIN
    r1 = r2 = r3 = make_zero_dom()
    c  = make_full_col()
    el_zero = make_zero_el()
    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el_zero, el_zero, el_zero, el_zero)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    assert act_r0[i] == 0, "bottom-left should use rotation 0 elements"
    assert dut.out_deadend.value == 1
    cocotb.log.info("bottom-left uses rotation 0 ✓")

@cocotb.test()
async def test_top_left_uses_rotation1(dut):
    """Top-left corner uses rotation 1 (top=left, right=top, bottom=right, left=bottom).
    Setting only el_top to zero means rotation 1 gets zero right — deadend expected."""
    i  = vid(0, 0)
    r1 = make_zero_dom(); r1[i] = ALL_DOMAIN
    r0 = r2 = r3 = make_zero_dom()
    c  = make_full_col()
    el_full = make_full_el()
    el_zero = make_zero_el()
    # rotation 1: right=top, so zeroing el_top kills the right side
    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el_zero, el_full, el_full, el_full)
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    assert act_r1[i] == 0, "top-left should use rotation 1 elements"
    assert dut.out_deadend.value == 1
    cocotb.log.info("top-left uses rotation 1 ✓")

@cocotb.test()
async def test_inner_uses_all_rotations(dut):
    """Inner position processes all four rotations."""
    i  = vid(1, 1)
    r0 = make_zero_dom(); r0[i] = 1 << 0
    r1 = make_zero_dom(); r1[i] = 1 << 1
    r2 = make_zero_dom(); r2[i] = 1 << 2
    r3 = make_zero_dom(); r3[i] = 1 << 3
    c  = make_full_col()
    el = make_full_el()
    await check(dut, r0, r1, r2, r3, c, c, c, c, el, el, el, el)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())
    assert act_r0[i] == (1 << 0)
    assert act_r1[i] == (1 << 1)
    assert act_r2[i] == (1 << 2)
    assert act_r3[i] == (1 << 3)
    cocotb.log.info("inner uses all rotations ✓")

@cocotb.test()
async def test_zero_colour_causes_deadend(dut):
    """Zero colour constraint removes all pieces — deadend."""
    i  = vid(0, N-1)  # bottom-left
    r0 = make_zero_dom(); r0[i] = ALL_DOMAIN
    r1 = r2 = r3 = make_zero_dom()
    c_zero = make_zero_col()
    c_full = make_full_col()
    el = make_full_el()
    await check(dut, r0, r1, r2, r3,
                c_zero, c_full, c_full, c_full,
                el, el, el, el)
    assert dut.out_deadend.value == 1
    cocotb.log.info("zero colour → deadend ✓")

@cocotb.test()
async def test_changed_detected(dut):
    """Domain shrinks — changed flag set.
    Only piece 0 has matching elements in the base orientation,
    so only piece 0 survives at the bottom-left corner (rotation 0)."""
    i  = vid(0, N-1)  # bottom-left uses rotation 0
    r0 = make_zero_dom(); r0[i] = ALL_DOMAIN
    r1 = r2 = r3 = make_zero_dom()
    c  = make_full_col()
    # only piece 0 has matching elements in base orientation
    el_t = make_zero_el(); el_t[0] = CC_MASK
    el_r = make_zero_el(); el_r[0] = CC_MASK
    el_b = make_zero_el(); el_b[0] = CC_MASK
    el_l = make_zero_el(); el_l[0] = CC_MASK
    await check(dut, r0, r1, r2, r3, c, c, c, c, el_t, el_r, el_b, el_l)
    assert dut.out_changed.value == 1
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    assert act_r0[i] == 1, f"only piece 0 should survive, got {act_r0[i]:#x}"
    cocotb.log.info("changed detected ✓")

@cocotb.test()
async def test_unused_rotations_pass_through(dut):
    """Unused rotations for border positions pass through unchanged."""
    i  = vid(0, N-1)  # bottom-left — only r0 used
    r0 = make_zero_dom(); r0[i] = 0b1010
    r1 = make_zero_dom(); r1[i] = 0b0101
    r2 = make_zero_dom(); r2[i] = 0b1100
    r3 = make_zero_dom(); r3[i] = 0b0011
    c  = make_full_col()
    el = make_full_el()
    await check(dut, r0, r1, r2, r3, c, c, c, c, el, el, el, el)
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())
    assert act_r1[i] == 0b0101, "r1 should pass through unchanged"
    assert act_r2[i] == 0b1100, "r2 should pass through unchanged"
    assert act_r3[i] == 0b0011, "r3 should pass through unchanged"
    cocotb.log.info("unused rotations pass through ✓")

@cocotb.test()
async def test_rotation_wiring(dut):
    """Verify the internal rotation rewiring is correct.
    Uses asymmetric elements so each rotation produces a distinct result,
    then checks that each grid position gets the expected rotation."""
    i_bl = vid(0, N-1)  # bottom-left — rotation 0
    i_tl = vid(0, 0)    # top-left    — rotation 1
    i_tr = vid(N-1, 0)  # top-right   — rotation 2
    i_br = vid(N-1, N-1)# bottom-right — rotation 3

    # unique colour per side so rotations are distinguishable
    A, B, C, D = 0b000001, 0b000010, 0b000100, 0b001000

    el_top    = [A] * V
    el_right  = [B] * V
    el_bottom = [C] * V
    el_left   = [D] * V

    # colour constraints that only match one specific side pattern
    # rotation 0: top=A right=B bottom=C left=D
    # rotation 1: top=D right=A bottom=B left=C
    # rotation 2: top=C right=D bottom=A left=B
    # rotation 3: top=B right=C bottom=D left=A

    for corner, rx, c_t, c_r, c_b, c_l in [
        (i_bl, 0, A, B, C, D),  # rotation 0
        (i_tl, 1, D, A, B, C),  # rotation 1
        (i_tr, 2, C, D, A, B),  # rotation 2
        (i_br, 3, B, C, D, A),  # rotation 3
    ]:
        r0 = make_zero_dom()
        r1 = make_zero_dom()
        r2 = make_zero_dom()
        r3 = make_zero_dom()
        [r0, r1, r2, r3][rx][corner] = ALL_DOMAIN

        c_top    = [c_t] * V
        c_right  = [c_r] * V
        c_bottom = [c_b] * V
        c_left   = [c_l] * V

        await check(dut, r0, r1, r2, r3,
                    c_top, c_right, c_bottom, c_left,
                    el_top, el_right, el_bottom, el_left)
        assert dut.out_deadend.value == 0, \
            f"rotation {rx} at corner {corner} should not deadend"
        cocotb.log.info(f"rotation wiring {rx} ✓")

@cocotb.test()
async def test_random(dut):
    """20 random inputs verified against reference."""
    random.seed(51)
    for _ in range(20):
        def rd(): return [random.randint(0, ALL_DOMAIN) for _ in range(V)]
        def rc(): return [random.randint(0, CC_MASK)    for _ in range(V)]
        def re(): return [random.randint(0, CC_MASK)    for _ in range(V)]
        r0, r1, r2, r3 = rd(), rd(), rd(), rd()
        c_t, c_r, c_b, c_l = rc(), rc(), rc(), rc()
        el_t, el_r, el_b, el_l = re(), re(), re(), re()
        await check(dut, r0, r1, r2, r3, c_t, c_r, c_b, c_l,
                    el_t, el_r, el_b, el_l)
    cocotb.log.info("20 random tests ✓")

def test_ColourToDomain():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/ColourToDomain_Rotation.sv",
            "rtl/ColourToDomain.sv",
        ],
        hdl_toplevel="ColourToDomain",
        parameters={"N": N, "CC": CC},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="ColourToDomain",
        test_module="test_ColourToDomain",
    )