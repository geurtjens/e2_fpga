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

def is_corner(x, y):
    return (x == 0 and y == N-1) or (x == 0 and y == 0) or \
           (x == N-1 and y == 0) or (x == N-1 and y == N-1)

def is_edge(x, y):
    return not is_corner(x, y) and \
           (x == 0 or x == N-1 or y == 0 or y == N-1)

def rotation_for_position(x, y):
    """Which rotation is used for corners and edges."""
    if y == N-1 and x == 0:  return 0  # bottom-left corner
    if y == 0   and x == 0:  return 1  # top-left corner
    if y == 0   and x == N-1: return 2  # top-right corner
    if y == N-1 and x == N-1: return 3  # bottom-right corner
    if y == N-1: return 0  # bottom edge
    if x == 0:   return 1  # left edge
    if y == 0:   return 2  # top edge
    if x == N-1: return 3  # right edge
    return -1  # inner

def reference(in_r0, in_r1, in_r2, in_r3,
              in_c_top, in_c_right, in_c_bottom, in_c_left,
              el0_top, el0_right, el0_bottom, el0_left,
              el1_top, el1_right, el1_bottom, el1_left,
              el2_top, el2_right, el2_bottom, el2_left,
              el3_top, el3_right, el3_bottom, el3_left):

    elements = [
        (el0_top, el0_right, el0_bottom, el0_left),
        (el1_top, el1_right, el1_bottom, el1_left),
        (el2_top, el2_right, el2_bottom, el2_left),
        (el3_top, el3_right, el3_bottom, el3_left),
    ]
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
                el_t, el_r, el_b, el_l = elements[rot]
                t = r = b = l = 0
                for p in range(V):
                    if (domain >> p) & 1:
                        t |= el_t[p]
                        r |= el_r[p]
                        b |= el_b[p]
                        l |= el_l[p]
                out_top[i]    = t
                out_right[i]  = r
                out_bottom[i] = b
                out_left[i]   = l
            else:
                # inner — OR all four rotations
                t = r = b = l = 0
                for rot_idx in range(4):
                    domain = domains[rot_idx][i]
                    el_t, el_r, el_b, el_l = elements[rot_idx]
                    for p in range(V):
                        if (domain >> p) & 1:
                            t |= el_t[p]
                            r |= el_r[p]
                            b |= el_b[p]
                            l |= el_l[p]
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

def make_zero_elements():
    return [0] * V

def make_full_elements():
    return [CC_MASK] * V

def make_zero_domains():
    return [0] * V

def make_full_domains():
    return [ALL_DOMAIN] * V

async def apply(dut,
                in_r0, in_r1, in_r2, in_r3,
                in_c_top, in_c_right, in_c_bottom, in_c_left,
                el0_t, el0_r, el0_b, el0_l,
                el1_t, el1_r, el1_b, el1_l,
                el2_t, el2_r, el2_b, el2_l,
                el3_t, el3_r, el3_b, el3_l):
    dut.in_domain_r0.value = pack_domain_array(in_r0)
    dut.in_domain_r1.value = pack_domain_array(in_r1)
    dut.in_domain_r2.value = pack_domain_array(in_r2)
    dut.in_domain_r3.value = pack_domain_array(in_r3)
    dut.in_colours_top.value    = pack_colour_array(in_c_top)
    dut.in_colours_right.value  = pack_colour_array(in_c_right)
    dut.in_colours_bottom.value = pack_colour_array(in_c_bottom)
    dut.in_colours_left.value   = pack_colour_array(in_c_left)
    dut.in_element0_top.value    = pack_colour_array(el0_t)
    dut.in_element0_right.value  = pack_colour_array(el0_r)
    dut.in_element0_bottom.value = pack_colour_array(el0_b)
    dut.in_element0_left.value   = pack_colour_array(el0_l)
    dut.in_element1_top.value    = pack_colour_array(el1_t)
    dut.in_element1_right.value  = pack_colour_array(el1_r)
    dut.in_element1_bottom.value = pack_colour_array(el1_b)
    dut.in_element1_left.value   = pack_colour_array(el1_l)
    dut.in_element2_top.value    = pack_colour_array(el2_t)
    dut.in_element2_right.value  = pack_colour_array(el2_r)
    dut.in_element2_bottom.value = pack_colour_array(el2_b)
    dut.in_element2_left.value   = pack_colour_array(el2_l)
    dut.in_element3_top.value    = pack_colour_array(el3_t)
    dut.in_element3_right.value  = pack_colour_array(el3_r)
    dut.in_element3_bottom.value = pack_colour_array(el3_b)
    dut.in_element3_left.value   = pack_colour_array(el3_l)
    await Timer(1, unit="ns")

async def check(dut,
                in_r0, in_r1, in_r2, in_r3,
                in_c_top, in_c_right, in_c_bottom, in_c_left,
                el0_t, el0_r, el0_b, el0_l,
                el1_t, el1_r, el1_b, el1_l,
                el2_t, el2_r, el2_b, el2_l,
                el3_t, el3_r, el3_b, el3_l):
    await apply(dut,
                in_r0, in_r1, in_r2, in_r3,
                in_c_top, in_c_right, in_c_bottom, in_c_left,
                el0_t, el0_r, el0_b, el0_l,
                el1_t, el1_r, el1_b, el1_l,
                el2_t, el2_r, el2_b, el2_l,
                el3_t, el3_r, el3_b, el3_l)

    exp_top, exp_right, exp_bottom, exp_left, exp_ch, exp_de = reference(
        in_r0, in_r1, in_r2, in_r3,
        in_c_top, in_c_right, in_c_bottom, in_c_left,
        el0_t, el0_r, el0_b, el0_l,
        el1_t, el1_r, el1_b, el1_l,
        el2_t, el2_r, el2_b, el2_l,
        el3_t, el3_r, el3_b, el3_l)

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

def make_simple_inputs():
    """Helper — zero domains, zero colours, full elements."""
    r   = make_zero_domains()
    c   = make_zero_elements()
    el  = make_full_elements()
    return r, c, el

@cocotb.test()
async def test_empty_domains(dut):
    """All domains empty — all output colours zero, no deadend."""
    r  = make_zero_domains()
    c  = make_zero_elements()
    el = make_full_elements()
    await check(dut, r, r, r, r, c, c, c, c,
                el, el, el, el,
                el, el, el, el,
                el, el, el, el,
                el, el, el, el)
    assert dut.out_deadend.value == 0
    assert dut.out_changed.value == 0
    cocotb.log.info("empty domains ✓")

@cocotb.test()
async def test_single_piece_bottom_left_corner(dut):
    """Bottom-left corner uses rotation 0 only."""
    i = vid(0, N-1)  # bottom-left
    r0 = make_zero_domains()
    r0[i] = 1 << 0   # piece 0 in domain
    r1 = make_zero_domains()
    r2 = make_zero_domains()
    r3 = make_zero_domains()
    c  = make_zero_elements()

    el0_t = [0] * V; el0_t[0] = 0b001100
    el0_r = [0] * V; el0_r[0] = 0b110000
    el0_b = [0] * V; el0_b[0] = 0b000011
    el0_l = [0] * V; el0_l[0] = 0b001111
    el_zero = make_zero_elements()

    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el0_t, el0_r, el0_b, el0_l,
                el_zero, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero)

    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b001100
    cocotb.log.info("bottom-left corner rotation 0 ✓")

@cocotb.test()
async def test_single_piece_top_left_corner(dut):
    """Top-left corner uses rotation 1 only."""
    i = vid(0, 0)
    r1 = make_zero_domains()
    r1[i] = 1 << 2
    r0 = r2 = r3 = make_zero_domains()
    c  = make_zero_elements()

    el1_t = [0] * V; el1_t[2] = 0b010101
    el_zero = make_zero_elements()

    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el_zero, el_zero, el_zero, el_zero,
                el1_t, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero)

    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b010101
    cocotb.log.info("top-left corner rotation 1 ✓")

@cocotb.test()
async def test_inner_ors_all_rotations(dut):
    """Inner variable ORs all four rotations."""
    i = vid(1, 1)  # inner position
    r0 = make_zero_domains(); r0[i] = 1 << 0
    r1 = make_zero_domains(); r1[i] = 1 << 1
    r2 = make_zero_domains(); r2[i] = 1 << 2
    r3 = make_zero_domains(); r3[i] = 1 << 3
    c  = make_zero_elements()

    el0_t = [0]*V; el0_t[0] = 0b000001
    el1_t = [0]*V; el1_t[1] = 0b000010
    el2_t = [0]*V; el2_t[2] = 0b000100
    el3_t = [0]*V; el3_t[3] = 0b001000
    el_zero = make_zero_elements()

    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el0_t, el_zero, el_zero, el_zero,
                el1_t, el_zero, el_zero, el_zero,
                el2_t, el_zero, el_zero, el_zero,
                el3_t, el_zero, el_zero, el_zero)

    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b001111
    cocotb.log.info("inner OR all rotations ✓")

@cocotb.test()
async def test_changed_detected(dut):
    """Changed flag set when output differs from input colours."""
    i  = vid(0, N-1)
    r0 = make_zero_domains(); r0[i] = 1 << 0
    r1 = r2 = r3 = make_zero_domains()
    c  = make_zero_elements()

    el0_t = [0]*V; el0_t[0] = 0b001100
    el_zero = make_zero_elements()

    # input colours are zero so output will differ
    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el0_t, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero)
    assert dut.out_changed.value == 1
    cocotb.log.info("changed detected ✓")

@cocotb.test()
async def test_no_change_when_colours_match(dut):
    """No change when output equals input colours."""
    i  = vid(0, N-1)
    r0 = make_zero_domains(); r0[i] = 1 << 0
    r1 = r2 = r3 = make_zero_domains()

    el0_t = [0]*V; el0_t[0] = 0b001100
    el_zero = make_zero_elements()

    # set input colours to match expected output
    c_top = make_zero_elements(); c_top[i] = 0b001100

    await check(dut, r0, r1, r2, r3,
                c_top, make_zero_elements(),
                make_zero_elements(), make_zero_elements(),
                el0_t, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero)
    assert dut.out_changed.value == 0
    cocotb.log.info("no change when colours match ✓")

@cocotb.test()
async def test_deadend_active_variable_zero_colours(dut):
    """Deadend when active variable produces all-zero colours."""
    i  = vid(0, N-1)
    r0 = make_zero_domains(); r0[i] = 1 << 0  # active domain
    r1 = r2 = r3 = make_zero_domains()
    c  = make_zero_elements()
    el_zero = make_zero_elements()  # all elements zero → output zero

    await check(dut, r0, r1, r2, r3, c, c, c, c,
                el_zero, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero,
                el_zero, el_zero, el_zero, el_zero)
    assert dut.out_deadend.value == 1
    cocotb.log.info("deadend ✓")

@cocotb.test()
async def test_random(dut):
    """30 random inputs verified against reference."""
    random.seed(66)
    for _ in range(30):
        def rd(): return [random.randint(0, ALL_DOMAIN) for _ in range(V)]
        def rc(): return [random.randint(0, CC_MASK) for _ in range(V)]
        r0, r1, r2, r3 = rd(), rd(), rd(), rd()
        c_t, c_r, c_b, c_l = rc(), rc(), rc(), rc()
        el0_t, el0_r, el0_b, el0_l = rc(), rc(), rc(), rc()
        el1_t, el1_r, el1_b, el1_l = rc(), rc(), rc(), rc()
        el2_t, el2_r, el2_b, el2_l = rc(), rc(), rc(), rc()
        el3_t, el3_r, el3_b, el3_l = rc(), rc(), rc(), rc()
        await check(dut, r0, r1, r2, r3, c_t, c_r, c_b, c_l,
                    el0_t, el0_r, el0_b, el0_l,
                    el1_t, el1_r, el1_b, el1_l,
                    el2_t, el2_r, el2_b, el2_l,
                    el3_t, el3_r, el3_b, el3_l)
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