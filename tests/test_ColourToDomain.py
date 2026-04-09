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


def unpack_domain_array(val):
    return [(val >> (i * V)) & ALL_DOMAIN for i in range(V)]


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


def tile_matches(el_top, el_right, el_bottom, el_left,
                 c_top, c_right, c_bottom, c_left, rotation, tile):
    """Check if a tile at a given rotation is compatible with colour constraints."""
    r_top, r_right, r_bottom, r_left = rotate_elements(
        el_top, el_right, el_bottom, el_left, rotation)
    return (
        (r_top[tile]    & c_top)    != 0 and
        (r_right[tile]  & c_right)  != 0 and
        (r_bottom[tile] & c_bottom) != 0 and
        (r_left[tile]   & c_left)   != 0
    )


def reference(in_r0, in_r1, in_r2, in_r3,
              in_c_top, in_c_right, in_c_bottom, in_c_left,
              el_top, el_right, el_bottom, el_left):
    out_r0 = list(in_r0)
    out_r1 = list(in_r1)
    out_r2 = list(in_r2)
    out_r3 = list(in_r3)

    for gy in range(N):
        for gx in range(N):
            i   = vid(gx, gy)
            rot = rotation_for_position(gx, gy)
            c_top    = in_c_top[i]
            c_right  = in_c_right[i]
            c_bottom = in_c_bottom[i]
            c_left   = in_c_left[i]

            if rot >= 0:
                # corner or edge — single rotation
                domains = [in_r0, in_r1, in_r2, in_r3]
                new_domain = 0
                for t in range(V):
                    if (domains[rot][i] >> t) & 1:
                        if tile_matches(el_top, el_right, el_bottom, el_left,
                                        c_top, c_right, c_bottom, c_left, rot, t):
                            new_domain |= (1 << t)
                if rot == 0: out_r0[i] = new_domain
                if rot == 1: out_r1[i] = new_domain
                if rot == 2: out_r2[i] = new_domain
                if rot == 3: out_r3[i] = new_domain
            else:
                # inner — all four rotations filtered independently
                for rot_idx, (in_d, out_d) in enumerate(
                        zip([in_r0, in_r1, in_r2, in_r3],
                            [out_r0, out_r1, out_r2, out_r3])):
                    new_domain = 0
                    for t in range(V):
                        if (in_d[i] >> t) & 1:
                            if tile_matches(el_top, el_right, el_bottom, el_left,
                                            c_top, c_right, c_bottom, c_left, rot_idx, t):
                                new_domain |= (1 << t)
                    if rot_idx == 0: out_r0[i] = new_domain
                    if rot_idx == 1: out_r1[i] = new_domain
                    if rot_idx == 2: out_r2[i] = new_domain
                    if rot_idx == 3: out_r3[i] = new_domain

    return out_r0, out_r1, out_r2, out_r3


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

    exp_r0, exp_r1, exp_r2, exp_r3 = reference(
        in_r0, in_r1, in_r2, in_r3,
        in_c_top, in_c_right, in_c_bottom, in_c_left,
        el_top, el_right, el_bottom, el_left)

    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())

    for i in range(V):
        assert act_r0[i] == exp_r0[i], \
            f"r0[{i}]={act_r0[i]:#018b} exp={exp_r0[i]:#018b}"
        assert act_r1[i] == exp_r1[i], \
            f"r1[{i}]={act_r1[i]:#018b} exp={exp_r1[i]:#018b}"
        assert act_r2[i] == exp_r2[i], \
            f"r2[{i}]={act_r2[i]:#018b} exp={exp_r2[i]:#018b}"
        assert act_r3[i] == exp_r3[i], \
            f"r3[{i}]={act_r3[i]:#018b} exp={exp_r3[i]:#018b}"


@cocotb.test()
async def test_full_domain_full_colours_passes_through(dut):
    """Full domain, full colour masks, all-ones elements — domains unchanged."""
    r   = make_full_domains()
    c   = make_full_colours()
    el  = make_full_elements()
    await check(dut, r, r, r, r, c, c, c, c, el, el, el, el)
    cocotb.log.info("full domain full colours passes through ✓")


@cocotb.test()
async def test_empty_domain_passes_through(dut):
    """Empty domains pass through unchanged regardless of colours."""
    r   = make_zero_domains()
    c   = make_full_colours()
    el  = make_full_elements()
    await check(dut, r, r, r, r, c, c, c, c, el, el, el, el)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    for i in range(V):
        assert act_r0[i] == 0, f"empty domain should remain zero at [{i}]"
    cocotb.log.info("empty domain passes through ✓")


@cocotb.test()
async def test_zero_colour_eliminates_all_tiles(dut):
    """Zero colour mask on one face eliminates all tiles from domain."""
    i   = vid(0, N-1)  # bottom-left corner — rotation 0
    r0  = make_full_domains()
    r1  = r2 = r3 = make_zero_domains()
    c_top = make_full_colours(); c_top[i] = 0  # zero top colour
    c_ful = make_full_colours()
    el    = make_full_elements()
    await check(dut, r0, r1, r2, r3,
                c_top, c_ful, c_ful, c_ful,
                el, el, el, el)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    assert act_r0[i] == 0, f"zero colour should eliminate all tiles, got {act_r0[i]:#018b}"
    cocotb.log.info("zero colour eliminates all tiles ✓")


@cocotb.test()
async def test_bottom_left_corner_rotation_0(dut):
    """Bottom-left corner (gx=0, gy=N-1) uses rotation 0.
    Only tiles whose base top matches the colour constraint survive."""
    i   = vid(0, N-1)
    r0  = make_full_domains()
    r1  = r2 = r3 = make_zero_domains()
    c_ful = make_full_colours()

    # tile 3 has top=0b001100, tile 5 has top=0b110000
    el_top = [0b001100] * V; el_top[5] = 0b110000
    el_oth = make_full_elements()

    # colour constraint only allows 0b001100 on top
    c_top = make_full_colours(); c_top[i] = 0b001100

    await check(dut, r0, r1, r2, r3,
                c_top, c_ful, c_ful, c_ful,
                el_top, el_oth, el_oth, el_oth)

    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    # tile 5 has top=0b110000 which doesn't match 0b001100 — should be eliminated
    assert not (act_r0[i] >> 5) & 1, "tile 5 should be eliminated (top mismatch)"
    cocotb.log.info("bottom-left corner rotation 0 ✓")


@cocotb.test()
async def test_top_left_corner_rotation_1(dut):
    """Top-left corner (gx=0, gy=0) uses rotation 1 — left→top rewiring.
    Colour constraint on top is checked against element left."""
    i   = vid(0, 0)
    r1  = make_full_domains()
    r0  = r2 = r3 = make_zero_domains()
    c_ful = make_full_colours()

    # rotation 1: top=left, so top colour constraint filters against el_left
    el_left = [0b001100] * V; el_left[2] = 0b110000
    el_oth  = make_full_elements()

    # top colour only allows 0b001100 — tile 2 has el_left=0b110000 so fails
    c_top = make_full_colours(); c_top[i] = 0b001100

    await check(dut, r0, r1, r2, r3,
                c_top, c_ful, c_ful, c_ful,
                el_oth, el_oth, el_oth, el_left)

    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    assert not (act_r1[i] >> 2) & 1, "tile 2 should be eliminated (left→top mismatch)"
    cocotb.log.info("top-left corner rotation 1 ✓")


@cocotb.test()
async def test_top_right_corner_rotation_2(dut):
    """Top-right corner (gx=N-1, gy=0) uses rotation 2 — bottom→top rewiring."""
    i   = vid(N-1, 0)
    r2  = make_full_domains()
    r0  = r1 = r3 = make_zero_domains()
    c_ful = make_full_colours()

    # rotation 2: top=bottom, so top colour constraint filters against el_bottom
    el_bottom = [0b001100] * V; el_bottom[4] = 0b110000
    el_oth    = make_full_elements()

    c_top = make_full_colours(); c_top[i] = 0b001100

    await check(dut, r0, r1, r2, r3,
                c_top, c_ful, c_ful, c_ful,
                el_oth, el_oth, el_bottom, el_oth)

    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    assert not (act_r2[i] >> 4) & 1, "tile 4 should be eliminated (bottom→top mismatch)"
    cocotb.log.info("top-right corner rotation 2 ✓")


@cocotb.test()
async def test_bottom_right_corner_rotation_3(dut):
    """Bottom-right corner (gx=N-1, gy=N-1) uses rotation 3 — right→top rewiring."""
    i   = vid(N-1, N-1)
    r3  = make_full_domains()
    r0  = r1 = r2 = make_zero_domains()
    c_ful = make_full_colours()

    # rotation 3: top=right, so top colour constraint filters against el_right
    el_right = [0b001100] * V; el_right[7] = 0b110000
    el_oth   = make_full_elements()

    c_top = make_full_colours(); c_top[i] = 0b001100

    await check(dut, r0, r1, r2, r3,
                c_top, c_ful, c_ful, c_ful,
                el_oth, el_right, el_oth, el_oth)

    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())
    assert not (act_r3[i] >> 7) & 1, "tile 7 should be eliminated (right→top mismatch)"
    cocotb.log.info("bottom-right corner rotation 3 ✓")


@cocotb.test()
async def test_inner_filters_all_four_rotations(dut):
    """Inner variable filters all four rotations independently."""
    i   = vid(1, 1)
    c_ful = make_full_colours()

    # put tile 0 in all four rotations for the inner variable
    r0 = make_zero_domains(); r0[i] = 1 << 0
    r1 = make_zero_domains(); r1[i] = 1 << 0
    r2 = make_zero_domains(); r2[i] = 1 << 0
    r3 = make_zero_domains(); r3[i] = 1 << 0

    # tile 0 top=0b001100, all others 0b000000
    el_top = [0b000000] * V; el_top[0] = 0b001100
    el_oth = make_full_elements()

    # top colour allows 0b001100 — tile 0 should survive in rotation 0 (top=top)
    # but fail in rotation 1 (top=left), 2 (top=bottom), 3 (top=right)
    # since el_left[0], el_bottom[0], el_right[0] are all full (0b111111)
    # and top constraint is 0b001100 — they match so all survive
    # Let's instead restrict to make rotation 1 fail:
    # rotation 1: top=left, so check el_left[0]
    el_left = [0b000000] * V; el_left[0] = 0b110000  # doesn't match c_top=0b001100

    c_top = make_full_colours(); c_top[i] = 0b001100

    await check(dut, r0, r1, r2, r3,
                c_top, c_ful, c_ful, c_ful,
                el_top, el_oth, el_oth, el_left)

    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    assert (act_r0[i] >> 0) & 1, "tile 0 r0 should survive (top matches)"
    assert not (act_r1[i] >> 0) & 1, "tile 0 r1 should be eliminated (left→top mismatch)"
    cocotb.log.info("inner filters all four rotations ✓")


@cocotb.test()
async def test_corner_non_active_rotations_pass_through(dut):
    """For a corner variable, the non-active rotation domains pass through unchanged."""
    i   = vid(0, N-1)  # bottom-left corner — only r0 is active
    r0  = make_full_domains()
    r1  = make_full_domains()  # should pass through unchanged
    r2  = make_full_domains()  # should pass through unchanged
    r3  = make_full_domains()  # should pass through unchanged
    c_ful = make_full_colours()
    el    = make_full_elements()
    await check(dut, r0, r1, r2, r3,
                c_ful, c_ful, c_ful, c_ful,
                el, el, el, el)
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())
    assert act_r1[i] == ALL_DOMAIN, "r1 should pass through unchanged"
    assert act_r2[i] == ALL_DOMAIN, "r2 should pass through unchanged"
    assert act_r3[i] == ALL_DOMAIN, "r3 should pass through unchanged"
    cocotb.log.info("corner non-active rotations pass through ✓")


@cocotb.test()
async def test_top_edge_rotation_2(dut):
    """Top edge (gy=0, not corner) uses rotation 2 — bottom→top."""
    i   = vid(1, 0)
    r2  = make_full_domains()
    r0  = r1 = r3 = make_zero_domains()
    c_ful = make_full_colours()

    el_bottom = [0b001100] * V; el_bottom[3] = 0b110000
    el_oth    = make_full_elements()
    c_top = make_full_colours(); c_top[i] = 0b001100

    await check(dut, r0, r1, r2, r3,
                c_top, c_ful, c_ful, c_ful,
                el_oth, el_oth, el_bottom, el_oth)

    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    assert not (act_r2[i] >> 3) & 1, "tile 3 should be eliminated"
    cocotb.log.info("top edge rotation 2 ✓")


@cocotb.test()
async def test_left_edge_rotation_1(dut):
    """Left edge (gx=0, not corner) uses rotation 1 — left→top."""
    i   = vid(0, 1)
    r1  = make_full_domains()
    r0  = r2 = r3 = make_zero_domains()
    c_ful = make_full_colours()

    el_left = [0b001100] * V; el_left[5] = 0b110000
    el_oth  = make_full_elements()
    c_top = make_full_colours(); c_top[i] = 0b001100

    await check(dut, r0, r1, r2, r3,
                c_top, c_ful, c_ful, c_ful,
                el_oth, el_oth, el_oth, el_left)

    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    assert not (act_r1[i] >> 5) & 1, "tile 5 should be eliminated"
    cocotb.log.info("left edge rotation 1 ✓")


@cocotb.test()
async def test_right_edge_rotation_3(dut):
    """Right edge (gx=N-1, not corner) uses rotation 3 — right→top."""
    i   = vid(N-1, 1)
    r3  = make_full_domains()
    r0  = r1 = r2 = make_zero_domains()
    c_ful = make_full_colours()

    el_right = [0b001100] * V; el_right[6] = 0b110000
    el_oth   = make_full_elements()
    c_top = make_full_colours(); c_top[i] = 0b001100

    await check(dut, r0, r1, r2, r3,
                c_top, c_ful, c_ful, c_ful,
                el_oth, el_right, el_oth, el_oth)

    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())
    assert not (act_r3[i] >> 6) & 1, "tile 6 should be eliminated"
    cocotb.log.info("right edge rotation 3 ✓")


@cocotb.test()
async def test_bottom_edge_rotation_0(dut):
    """Bottom edge (gy=N-1, not corner) uses rotation 0 — base orientation."""
    i   = vid(1, N-1)
    r0  = make_full_domains()
    r1  = r2 = r3 = make_zero_domains()
    c_ful = make_full_colours()

    el_top = [0b001100] * V; el_top[2] = 0b110000
    el_oth = make_full_elements()
    c_top = make_full_colours(); c_top[i] = 0b001100

    await check(dut, r0, r1, r2, r3,
                c_top, c_ful, c_ful, c_ful,
                el_top, el_oth, el_oth, el_oth)

    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    assert not (act_r0[i] >> 2) & 1, "tile 2 should be eliminated"
    cocotb.log.info("bottom edge rotation 0 ✓")


@cocotb.test()
async def test_all_four_colour_faces_checked(dut):
    """All four colour faces (top, right, bottom, left) are checked independently."""
    i   = vid(1, 1)  # inner variable
    r0  = make_zero_domains(); r0[i] = ALL_DOMAIN
    r1  = r2 = r3 = make_zero_domains()
    c_ful = make_full_colours()

    # tile 0: top=A, right=B, bottom=C, left=D — all pass
    # tile 1: top=A, right=B, bottom=C, left=0 — fails left
    # tile 2: top=A, right=B, bottom=0, left=D — fails bottom
    # tile 3: top=A, right=0, bottom=C, left=D — fails right
    # tile 4: top=0, right=B, bottom=C, left=D — fails top
    A, B, C, D = 0b000001, 0b000010, 0b000100, 0b001000
    el_top    = [A] * V; el_top[4]    = 0
    el_right  = [B] * V; el_right[3]  = 0
    el_bottom = [C] * V; el_bottom[2] = 0
    el_left   = [D] * V; el_left[1]   = 0

    c_top    = make_full_colours(); c_top[i]    = A
    c_right  = make_full_colours(); c_right[i]  = B
    c_bottom = make_full_colours(); c_bottom[i] = C
    c_left   = make_full_colours(); c_left[i]   = D

    await check(dut, r0, r1, r2, r3,
                c_top, c_right, c_bottom, c_left,
                el_top, el_right, el_bottom, el_left)

    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    assert     (act_r0[i] >> 0) & 1, "tile 0 should survive (all faces match)"
    assert not (act_r0[i] >> 1) & 1, "tile 1 should be eliminated (left=0)"
    assert not (act_r0[i] >> 2) & 1, "tile 2 should be eliminated (bottom=0)"
    assert not (act_r0[i] >> 3) & 1, "tile 3 should be eliminated (right=0)"
    assert not (act_r0[i] >> 4) & 1, "tile 4 should be eliminated (top=0)"
    cocotb.log.info("all four colour faces checked ✓")


@cocotb.test()
async def test_random(dut):
    """30 random inputs verified against reference."""
    random.seed(88)
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