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


def pack_colour_array(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & CC_MASK) << (i * CC)
    return val


def unpack_colour_array(val):
    return [(val >> (i * CC)) & CC_MASK for i in range(V)]


def vid(x, y): return y * N + x


def rotation_for_position(x, y):
    if y == N-1 and x == 0:   return 0  # bottom-left corner
    if y == 0   and x == 0:   return 1  # top-left corner
    if y == 0   and x == N-1: return 2  # top-right corner
    if y == N-1 and x == N-1: return 3  # bottom-right corner
    if y == N-1: return 0  # bottom edge
    if x == 0:   return 1  # left edge
    if y == 0:   return 2  # top edge
    if x == N-1: return 3  # right edge
    return -1              # inner


def rotate_elements(el_top, el_right, el_bottom, el_left, rotation):
    if rotation == 0: return el_top,    el_right,  el_bottom, el_left
    if rotation == 1: return el_left,   el_top,    el_right,  el_bottom
    if rotation == 2: return el_bottom, el_left,   el_top,    el_right
    if rotation == 3: return el_right,  el_bottom, el_left,   el_top


def reference(in_r0, in_r1, in_r2, in_r3,
              in_c_top, in_c_right, in_c_bottom, in_c_left,
              el_top, el_right, el_bottom, el_left):
    domains = [in_r0, in_r1, in_r2, in_r3]
    out_top    = [0] * V
    out_right  = [0] * V
    out_bottom = [0] * V
    out_left   = [0] * V

    for gy in range(N):
        for gx in range(N):
            i   = vid(gx, gy)
            rot = rotation_for_position(gx, gy)
            if rot >= 0:
                domain = domains[rot][i]
                r_top, r_right, r_bottom, r_left = rotate_elements(
                    el_top, el_right, el_bottom, el_left, rot)
                t = r = b = l = 0
                for p in range(V):
                    if (domain >> p) & 1:
                        t |= r_top[p];    r |= r_right[p]
                        b |= r_bottom[p]; l |= r_left[p]
                out_top[i]    = t & in_c_top[i]
                out_right[i]  = r & in_c_right[i]
                out_bottom[i] = b & in_c_bottom[i]
                out_left[i]   = l & in_c_left[i]
            else:
                t = r = b = l = 0
                for rot_idx in range(4):
                    domain = domains[rot_idx][i]
                    r_top, r_right, r_bottom, r_left = rotate_elements(
                        el_top, el_right, el_bottom, el_left, rot_idx)
                    for p in range(V):
                        if (domain >> p) & 1:
                            t |= r_top[p];    r |= r_right[p]
                            b |= r_bottom[p]; l |= r_left[p]
                out_top[i]    = t & in_c_top[i]
                out_right[i]  = r & in_c_right[i]
                out_bottom[i] = b & in_c_bottom[i]
                out_left[i]   = l & in_c_left[i]

    return out_top, out_right, out_bottom, out_left


def make_zero_elements(): return [0]          * V
def make_full_elements(): return [CC_MASK]    * V
def make_zero_domains():  return [0]          * V
def make_full_domains():  return [ALL_DOMAIN] * V
def make_full_colours():  return [CC_MASK]    * V
def make_zero_colours():  return [0]          * V


async def apply(dut,
                in_r0, in_r1, in_r2, in_r3,
                in_c_top, in_c_right, in_c_bottom, in_c_left,
                el_top, el_right, el_bottom, el_left):
    dut.in_domain_r0.value       = pack_domain_array(in_r0)
    dut.in_domain_r1.value       = pack_domain_array(in_r1)
    dut.in_domain_r2.value       = pack_domain_array(in_r2)
    dut.in_domain_r3.value       = pack_domain_array(in_r3)
    dut.in_colours_top.value     = pack_colour_array(in_c_top)
    dut.in_colours_right.value   = pack_colour_array(in_c_right)
    dut.in_colours_bottom.value  = pack_colour_array(in_c_bottom)
    dut.in_colours_left.value    = pack_colour_array(in_c_left)
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

    exp_top, exp_right, exp_bottom, exp_left = reference(
        in_r0, in_r1, in_r2, in_r3,
        in_c_top, in_c_right, in_c_bottom, in_c_left,
        el_top, el_right, el_bottom, el_left)

    act_top    = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    act_right  = unpack_colour_array(dut.out_colours_right.value.to_unsigned())
    act_bottom = unpack_colour_array(dut.out_colours_bottom.value.to_unsigned())
    act_left   = unpack_colour_array(dut.out_colours_left.value.to_unsigned())

    for i in range(V):
        assert act_top[i]    == exp_top[i],    \
            f"top[{i}]={act_top[i]:06b} exp={exp_top[i]:06b}"
        assert act_right[i]  == exp_right[i],  \
            f"right[{i}]={act_right[i]:06b} exp={exp_right[i]:06b}"
        assert act_bottom[i] == exp_bottom[i], \
            f"bottom[{i}]={act_bottom[i]:06b} exp={exp_bottom[i]:06b}"
        assert act_left[i]   == exp_left[i],   \
            f"left[{i}]={act_left[i]:06b} exp={exp_left[i]:06b}"


@cocotb.test()
async def test_empty_domains(dut):
    """All domains empty — all output colours zero."""
    r   = make_zero_domains()
    c   = make_full_colours()
    el  = make_full_elements()
    await check(dut, r, r, r, r, c, c, c, c, el, el, el, el)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    for i in range(V):
        assert act_top[i] == 0, f"empty domain should give zero colour at [{i}]"
    cocotb.log.info("empty domains ✓")


@cocotb.test()
async def test_incoming_colours_narrow_output(dut):
    """Incoming colours AND with derived colours — output is narrowed."""
    i   = vid(0, N-1)  # bottom-left corner — rotation 0
    r0  = make_zero_domains(); r0[i] = ALL_DOMAIN
    r1  = r2 = r3 = make_zero_domains()
    el_top = make_full_elements()
    el_zer = make_zero_elements()
    c_top  = make_full_colours(); c_top[i] = 0b001100
    c_ful  = make_full_colours()
    await check(dut, r0, r1, r2, r3,
                c_top, c_ful, c_ful, c_ful,
                el_top, el_zer, el_zer, el_zer)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b001100, \
        f"expected narrowing to 0b001100, got {act_top[i]:06b}"
    cocotb.log.info("incoming colours narrow output ✓")


@cocotb.test()
async def test_bottom_left_corner_rotation_0(dut):
    """Bottom-left corner (gx=0, gy=N-1) uses rotation 0 — base orientation."""
    i   = vid(0, N-1)
    r0  = make_zero_domains(); r0[i] = 1 << 0
    r1  = r2 = r3 = make_zero_domains()
    el_top = [0]*V; el_top[0] = 0b001100
    el_zer = make_zero_elements()
    c_ful  = make_full_colours()
    await check(dut, r0, r1, r2, r3,
                c_ful, c_ful, c_ful, c_ful,
                el_top, el_zer, el_zer, el_zer)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b001100, f"bottom-left top={act_top[i]:06b}"
    cocotb.log.info("bottom-left corner rotation 0 ✓")


@cocotb.test()
async def test_top_left_corner_rotation_1(dut):
    """Top-left corner (gx=0, gy=0) uses rotation 1 — left→top rewiring."""
    i   = vid(0, 0)
    r1  = make_zero_domains(); r1[i] = 1 << 2
    r0  = r2 = r3 = make_zero_domains()
    el_left = [0]*V; el_left[2] = 0b010101
    el_zer  = make_zero_elements()
    c_ful   = make_full_colours()
    await check(dut, r0, r1, r2, r3,
                c_ful, c_ful, c_ful, c_ful,
                el_zer, el_zer, el_zer, el_left)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b010101, \
        f"rotation 1 maps left→top, got {act_top[i]:06b}"
    cocotb.log.info("top-left corner rotation 1 ✓")


@cocotb.test()
async def test_top_right_corner_rotation_2(dut):
    """Top-right corner (gx=N-1, gy=0) uses rotation 2 — bottom→top rewiring."""
    i   = vid(N-1, 0)
    r2  = make_zero_domains(); r2[i] = 1 << 4
    r0  = r1 = r3 = make_zero_domains()
    el_bottom = [0]*V; el_bottom[4] = 0b110000
    el_zer    = make_zero_elements()
    c_ful     = make_full_colours()
    await check(dut, r0, r1, r2, r3,
                c_ful, c_ful, c_ful, c_ful,
                el_zer, el_zer, el_bottom, el_zer)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b110000, \
        f"rotation 2 maps bottom→top, got {act_top[i]:06b}"
    cocotb.log.info("top-right corner rotation 2 ✓")


@cocotb.test()
async def test_bottom_right_corner_rotation_3(dut):
    """Bottom-right corner (gx=N-1, gy=N-1) uses rotation 3 — right→top rewiring."""
    i   = vid(N-1, N-1)
    r3  = make_zero_domains(); r3[i] = 1 << 6
    r0  = r1 = r2 = make_zero_domains()
    el_right = [0]*V; el_right[6] = 0b000111
    el_zer   = make_zero_elements()
    c_ful    = make_full_colours()
    await check(dut, r0, r1, r2, r3,
                c_ful, c_ful, c_ful, c_ful,
                el_zer, el_right, el_zer, el_zer)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b000111, \
        f"rotation 3 maps right→top, got {act_top[i]:06b}"
    cocotb.log.info("bottom-right corner rotation 3 ✓")


@cocotb.test()
async def test_inner_ors_all_rotations(dut):
    """Inner variable ORs colours from all four rotations."""
    i   = vid(1, 1)
    r0  = make_zero_domains(); r0[i] = 1 << 0
    r1  = make_zero_domains(); r1[i] = 1 << 1
    r2  = make_zero_domains(); r2[i] = 1 << 2
    r3  = make_zero_domains(); r3[i] = 1 << 3
    # rotation 0: top=top     → piece 0 el_top[0]=0b000001
    # rotation 1: top=left    → piece 1 el_left[1]=0b000010
    # rotation 2: top=bottom  → piece 2 el_bottom[2]=0b000100
    # rotation 3: top=right   → piece 3 el_right[3]=0b001000
    el_top    = [0]*V; el_top[0]    = 0b000001
    el_right  = [0]*V; el_right[3]  = 0b001000
    el_bottom = [0]*V; el_bottom[2] = 0b000100
    el_left   = [0]*V; el_left[1]   = 0b000010
    c_ful = make_full_colours()
    await check(dut, r0, r1, r2, r3,
                c_ful, c_ful, c_ful, c_ful,
                el_top, el_right, el_bottom, el_left)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b001111, \
        f"expected all four bits OR'd, got {act_top[i]:06b}"
    cocotb.log.info("inner OR all rotations ✓")


@cocotb.test()
async def test_inner_narrowed_by_incoming(dut):
    """Inner variable: derived colour is narrowed by incoming colour mask."""
    i   = vid(1, 1)
    r0  = make_zero_domains(); r0[i] = ALL_DOMAIN
    r1  = r2 = r3 = make_zero_domains()
    el_top = make_full_elements()
    el_zer = make_zero_elements()
    c_top  = make_full_colours(); c_top[i] = 0b000011
    c_ful  = make_full_colours()
    await check(dut, r0, r1, r2, r3,
                c_top, c_ful, c_ful, c_ful,
                el_top, el_zer, el_zer, el_zer)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b000011, \
        f"inner should be narrowed to 0b000011, got {act_top[i]:06b}"
    cocotb.log.info("inner narrowed by incoming ✓")


@cocotb.test()
async def test_rotation_wiring_all_corners(dut):
    """Verify rotation rewiring for all four corners using asymmetric elements."""
    A, B, C, D = 0b000001, 0b000010, 0b000100, 0b001000
    el_top    = [A] * V
    el_right  = [B] * V
    el_bottom = [C] * V
    el_left   = [D] * V
    c_ful = make_full_colours()
    # rotation 0: top=top    → A
    # rotation 1: top=left   → D
    # rotation 2: top=bottom → C
    # rotation 3: top=right  → B
    corners = [
        (vid(0,   N-1), 0, A),
        (vid(0,   0),   1, D),
        (vid(N-1, 0),   2, C),
        (vid(N-1, N-1), 3, B),
    ]
    for corner_id, rot, expected_top in corners:
        r0 = make_zero_domains()
        r1 = make_zero_domains()
        r2 = make_zero_domains()
        r3 = make_zero_domains()
        [r0, r1, r2, r3][rot][corner_id] = ALL_DOMAIN
        await check(dut, r0, r1, r2, r3,
                    c_ful, c_ful, c_ful, c_ful,
                    el_top, el_right, el_bottom, el_left)
        act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
        assert act_top[corner_id] == expected_top, \
            f"corner {corner_id} rot {rot}: top={act_top[corner_id]:06b} exp={expected_top:06b}"
        cocotb.log.info(f"rotation wiring corner {corner_id} rotation {rot} ✓")


@cocotb.test()
async def test_top_edge_rotation_2(dut):
    """Top edge (gy=0, not corner) uses rotation 2 — bottom→top."""
    i   = vid(1, 0)  # top edge, not a corner
    r2  = make_zero_domains(); r2[i] = 1 << 3
    r0  = r1 = r3 = make_zero_domains()
    el_bottom = [0]*V; el_bottom[3] = 0b101010
    el_zer    = make_zero_elements()
    c_ful     = make_full_colours()
    await check(dut, r0, r1, r2, r3,
                c_ful, c_ful, c_ful, c_ful,
                el_zer, el_zer, el_bottom, el_zer)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b101010, \
        f"top edge rotation 2 bottom→top, got {act_top[i]:06b}"
    cocotb.log.info("top edge rotation 2 ✓")


@cocotb.test()
async def test_left_edge_rotation_1(dut):
    """Left edge (gx=0, not corner) uses rotation 1 — left→top."""
    i   = vid(0, 1)  # left edge, not a corner
    r1  = make_zero_domains(); r1[i] = 1 << 5
    r0  = r2 = r3 = make_zero_domains()
    el_left = [0]*V; el_left[5] = 0b011011
    el_zer  = make_zero_elements()
    c_ful   = make_full_colours()
    await check(dut, r0, r1, r2, r3,
                c_ful, c_ful, c_ful, c_ful,
                el_zer, el_zer, el_zer, el_left)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b011011, \
        f"left edge rotation 1 left→top, got {act_top[i]:06b}"
    cocotb.log.info("left edge rotation 1 ✓")


@cocotb.test()
async def test_right_edge_rotation_3(dut):
    """Right edge (gx=N-1, not corner) uses rotation 3 — right→top."""
    i   = vid(N-1, 1)  # right edge, not a corner
    r3  = make_zero_domains(); r3[i] = 1 << 7
    r0  = r1 = r2 = make_zero_domains()
    el_right = [0]*V; el_right[7] = 0b100100
    el_zer   = make_zero_elements()
    c_ful    = make_full_colours()
    await check(dut, r0, r1, r2, r3,
                c_ful, c_ful, c_ful, c_ful,
                el_zer, el_right, el_zer, el_zer)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b100100, \
        f"right edge rotation 3 right→top, got {act_top[i]:06b}"
    cocotb.log.info("right edge rotation 3 ✓")


@cocotb.test()
async def test_bottom_edge_rotation_0(dut):
    """Bottom edge (gy=N-1, not corner) uses rotation 0 — base orientation."""
    i   = vid(1, N-1)  # bottom edge, not a corner
    r0  = make_zero_domains(); r0[i] = 1 << 2
    r1  = r2 = r3 = make_zero_domains()
    el_top = [0]*V; el_top[2] = 0b010010
    el_zer = make_zero_elements()
    c_ful  = make_full_colours()
    await check(dut, r0, r1, r2, r3,
                c_ful, c_ful, c_ful, c_ful,
                el_top, el_zer, el_zer, el_zer)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b010010, \
        f"bottom edge rotation 0 top→top, got {act_top[i]:06b}"
    cocotb.log.info("bottom edge rotation 0 ✓")


@cocotb.test()
async def test_multiple_pieces_in_domain(dut):
    """Multiple pieces in domain — colours are OR'd together."""
    i   = vid(0, N-1)  # bottom-left corner — rotation 0
    r0  = make_zero_domains(); r0[i] = (1 << 0) | (1 << 1)
    r1  = r2 = r3 = make_zero_domains()
    el_top = [0]*V
    el_top[0] = 0b000011
    el_top[1] = 0b001100
    el_zer = make_zero_elements()
    c_ful  = make_full_colours()
    await check(dut, r0, r1, r2, r3,
                c_ful, c_ful, c_ful, c_ful,
                el_top, el_zer, el_zer, el_zer)
    act_top = unpack_colour_array(dut.out_colours_top.value.to_unsigned())
    assert act_top[i] == 0b001111, \
        f"expected OR of two pieces, got {act_top[i]:06b}"
    cocotb.log.info("multiple pieces OR'd ✓")


@cocotb.test()
async def test_random(dut):
    """30 random inputs verified against reference."""
    random.seed(99)
    for _ in range(30):
        def rd(): return [random.randint(0, ALL_DOMAIN) for _ in range(V)]
        def rc(): return [random.randint(0, CC_MASK)    for _ in range(V)]
        r0, r1, r2, r3         = rd(), rd(), rd(), rd()
        c_t, c_r, c_b, c_l    = rc(), rc(), rc(), rc()
        el_t, el_r, el_b, el_l = rc(), rc(), rc(), rc()
        await check(dut, r0, r1, r2, r3,
                    c_t, c_r, c_b, c_l,
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