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
              el0_t, el0_r, el0_b, el0_l,
              el1_t, el1_r, el1_b, el1_l,
              el2_t, el2_r, el2_b, el2_l,
              el3_t, el3_r, el3_b, el3_l):

    elements = [
        (el0_t, el0_r, el0_b, el0_l),
        (el1_t, el1_r, el1_b, el1_l),
        (el2_t, el2_r, el2_b, el2_l),
        (el3_t, el3_r, el3_b, el3_l),
    ]
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
                el_t, el_r, el_b, el_l = elements[rot]
                result, ch, de = reference_rotation(
                    domains_in[rot][i],
                    c_top[i], c_right[i], c_bottom[i], c_left[i],
                    el_t, el_r, el_b, el_l)
                out_domains[rot][i] = result
                if ch: changed = True
                if de: deadend = True
            else:
                # inner — all four rotations
                for r_idx in range(4):
                    el_t, el_r, el_b, el_l = elements[r_idx]
                    result, ch, de = reference_rotation(
                        domains_in[r_idx][i],
                        c_top[i], c_right[i], c_bottom[i], c_left[i],
                        el_t, el_r, el_b, el_l)
                    out_domains[r_idx][i] = result
                    if ch: changed = True
                    if de: deadend = True

    return out_r0, out_r1, out_r2, out_r3, changed, deadend

async def apply(dut,
                in_r0, in_r1, in_r2, in_r3,
                c_top, c_right, c_bottom, c_left,
                el0_t, el0_r, el0_b, el0_l,
                el1_t, el1_r, el1_b, el1_l,
                el2_t, el2_r, el2_b, el2_l,
                el3_t, el3_r, el3_b, el3_l):
    dut.in_domain_r0.value = pack_domain_array(in_r0)
    dut.in_domain_r1.value = pack_domain_array(in_r1)
    dut.in_domain_r2.value = pack_domain_array(in_r2)
    dut.in_domain_r3.value = pack_domain_array(in_r3)
    dut.in_colours_top.value    = pack_colour_array(c_top)
    dut.in_colours_right.value  = pack_colour_array(c_right)
    dut.in_colours_bottom.value = pack_colour_array(c_bottom)
    dut.in_colours_left.value   = pack_colour_array(c_left)
    dut.in_element0_top.value    = pack_elements(el0_t)
    dut.in_element0_right.value  = pack_elements(el0_r)
    dut.in_element0_bottom.value = pack_elements(el0_b)
    dut.in_element0_left.value   = pack_elements(el0_l)
    dut.in_element1_top.value    = pack_elements(el1_t)
    dut.in_element1_right.value  = pack_elements(el1_r)
    dut.in_element1_bottom.value = pack_elements(el1_b)
    dut.in_element1_left.value   = pack_elements(el1_l)
    dut.in_element2_top.value    = pack_elements(el2_t)
    dut.in_element2_right.value  = pack_elements(el2_r)
    dut.in_element2_bottom.value = pack_elements(el2_b)
    dut.in_element2_left.value   = pack_elements(el2_l)
    dut.in_element3_top.value    = pack_elements(el3_t)
    dut.in_element3_right.value  = pack_elements(el3_r)
    dut.in_element3_bottom.value = pack_elements(el3_b)
    dut.in_element3_left.value   = pack_elements(el3_l)
    await Timer(1, unit="ns")

async def check(dut,
                in_r0, in_r1, in_r2, in_r3,
                c_top, c_right, c_bottom, c_left,
                el0_t, el0_r, el0_b, el0_l,
                el1_t, el1_r, el1_b, el1_l,
                el2_t, el2_r, el2_b, el2_l,
                el3_t, el3_r, el3_b, el3_l):
    await apply(dut,
                in_r0, in_r1, in_r2, in_r3,
                c_top, c_right, c_bottom, c_left,
                el0_t, el0_r, el0_b, el0_l,
                el1_t, el1_r, el1_b, el1_l,
                el2_t, el2_r, el2_b, el2_l,
                el3_t, el3_r, el3_b, el3_l)

    exp_r0, exp_r1, exp_r2, exp_r3, exp_ch, exp_de = reference(
        in_r0, in_r1, in_r2, in_r3,
        c_top, c_right, c_bottom, c_left,
        el0_t, el0_r, el0_b, el0_l,
        el1_t, el1_r, el1_b, el1_l,
        el2_t, el2_r, el2_b, el2_l,
        el3_t, el3_r, el3_b, el3_l)

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
    await check(dut, r, r, r, r, c, c, c, c,
                el, el, el, el, el, el, el, el,
                el, el, el, el, el, el, el, el)
    assert dut.out_changed.value == 0
    assert dut.out_deadend.value == 0
    cocotb.log.info("empty domains ✓")

@cocotb.test()
async def test_all_pass_full_colours(dut):
    """Full domains, all-ones colours and elements — no change."""
    r  = make_full_dom()
    c  = make_full_col()
    el = make_full_el()
    await check(dut, r, r, r, r, c, c, c, c,
                el, el, el, el, el, el, el, el,
                el, el, el, el, el, el, el, el)
    assert dut.out_changed.value == 0
    assert dut.out_deadend.value == 0
    cocotb.log.info("all pass full colours ✓")

@cocotb.test()
async def test_bottom_left_uses_rotation0(dut):
    """Bottom-left corner uses rotation 0 only."""
    i  = vid(0, N-1)
    r0 = make_zero_dom(); r0[i] = ALL_DOMAIN
    r1 = r2 = r3 = make_zero_dom()
    c  = make_full_col()
    el = make_full_el()
    el0 = make_full_el()
    el_zero = make_zero_el()
    # zero elements for rotation 0 — should cause deadend at bottom-left
    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el_zero, el_zero, el_zero, el_zero,
                el, el, el, el,
                el, el, el, el,
                el, el, el, el)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    assert act_r0[i] == 0, "bottom-left should use rotation 0 elements"
    assert dut.out_deadend.value == 1
    cocotb.log.info("bottom-left uses rotation 0 ✓")

@cocotb.test()
async def test_top_left_uses_rotation1(dut):
    """Top-left corner uses rotation 1 only."""
    i  = vid(0, 0)
    r1 = make_zero_dom(); r1[i] = ALL_DOMAIN
    r0 = r2 = r3 = make_zero_dom()
    c  = make_full_col()
    el = make_full_el()
    el_zero = make_zero_el()
    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el, el, el, el,
                el_zero, el_zero, el_zero, el_zero,
                el, el, el, el,
                el, el, el, el)
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
    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el, el, el, el, el, el, el, el,
                el, el, el, el, el, el, el, el)
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
                el, el, el, el, el, el, el, el,
                el, el, el, el, el, el, el, el)
    assert dut.out_deadend.value == 1
    cocotb.log.info("zero colour → deadend ✓")

@cocotb.test()
async def test_changed_detected(dut):
    """Domain shrinks — changed flag set."""
    i  = vid(0, N-1)  # bottom-left uses rotation 0
    r0 = make_zero_dom(); r0[i] = ALL_DOMAIN
    r1 = r2 = r3 = make_zero_dom()
    c  = make_full_col()
    # only piece 0 has matching elements
    el0_t = make_zero_el(); el0_t[0] = CC_MASK
    el0_r = make_zero_el(); el0_r[0] = CC_MASK
    el0_b = make_zero_el(); el0_b[0] = CC_MASK
    el0_l = make_zero_el(); el0_l[0] = CC_MASK
    el = make_full_el()
    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el0_t, el0_r, el0_b, el0_l,
                el, el, el, el,
                el, el, el, el,
                el, el, el, el)
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
    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el, el, el, el, el, el, el, el,
                el, el, el, el, el, el, el, el)
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())
    assert act_r1[i] == 0b0101, "r1 should pass through unchanged"
    assert act_r2[i] == 0b1100, "r2 should pass through unchanged"
    assert act_r3[i] == 0b0011, "r3 should pass through unchanged"
    cocotb.log.info("unused rotations pass through ✓")

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
        el0_t, el0_r, el0_b, el0_l = re(), re(), re(), re()
        el1_t, el1_r, el1_b, el1_l = re(), re(), re(), re()
        el2_t, el2_r, el2_b, el2_l = re(), re(), re(), re()
        el3_t, el3_r, el3_b, el3_l = re(), re(), re(), re()
        await check(dut, r0, r1, r2, r3, c_t, c_r, c_b, c_l,
                    el0_t, el0_r, el0_b, el0_l,
                    el1_t, el1_r, el1_b, el1_l,
                    el2_t, el2_r, el2_b, el2_l,
                    el3_t, el3_r, el3_b, el3_l)
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