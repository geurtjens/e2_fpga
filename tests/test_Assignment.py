import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

from elements_state             import ElementsState
from grid_state                 import GridState
from data_elements_brendan3     import data_elements_brendan3
from data_initial_grid_brendan3 import data_initial_grid_brendan3
from data_first_assignment_brendan3 import data_first_assignment_brendan3

N       = data_initial_grid_brendan3.N
CC      = data_initial_grid_brendan3.CC
V       = data_initial_grid_brendan3.V
CC_MASK = (1 << CC) - 1
ALL_DOM = (1 << V) - 1


def rotate_cw(top, right, bottom, left):
    """One 90-degree clockwise rotation — new_top=old_left."""
    return left, top, right, bottom


def piece_colours(elements: ElementsState, tile_id: int, rotation: int):
    """Derive tile colours at given rotation from base orientation."""
    t = elements.ELEMENTS_TOP[tile_id]
    r = elements.ELEMENTS_RIGHT[tile_id]
    b = elements.ELEMENTS_BOTTOM[tile_id]
    l = elements.ELEMENTS_LEFT[tile_id]
    for _ in range(rotation):
        t, r, b, l = rotate_cw(t, r, b, l)
    return t, r, b, l


def reference(elements: ElementsState,
              variable_id, tile_id, rotation,
              in_uv, in_ut,
              in_top, in_right, in_bottom, in_left,
              in_r0, in_r1, in_r2, in_r3):
    x  = variable_id % N
    y  = variable_id // N
    pt, pr, pb, pl = piece_colours(elements, tile_id, rotation)

    out_top    = list(in_top)
    out_right  = list(in_right)
    out_bottom = list(in_bottom)
    out_left   = list(in_left)
    out_r0     = list(in_r0)
    out_r1     = list(in_r1)
    out_r2     = list(in_r2)
    out_r3     = list(in_r3)

    # Part 1 — lock domain
    tile_mask           = 1 << tile_id
    out_r0[variable_id] = tile_mask if rotation == 0 else 0
    out_r1[variable_id] = tile_mask if rotation == 1 else 0
    out_r2[variable_id] = tile_mask if rotation == 2 else 0
    out_r3[variable_id] = tile_mask if rotation == 3 else 0

    # Part 2 — set own colours
    out_top[variable_id]    = pt
    out_right[variable_id]  = pr
    out_bottom[variable_id] = pb
    out_left[variable_id]   = pl

    # Part 3 — update neighbours
    if x < N-1:
        out_left[variable_id+1]   = in_left[variable_id+1]   & pr
    if y < N-1:
        out_top[variable_id+N]    = in_top[variable_id+N]    & pb
    if x > 0:
        out_right[variable_id-1]  = in_right[variable_id-1]  & pl
    if y > 0:
        out_bottom[variable_id-N] = in_bottom[variable_id-N] & pt

    # Part 4 — update availability masks
    out_uv = in_uv & ~(1 << variable_id)
    out_ut = in_ut & ~(1 << tile_id)
    
    return (out_top, out_right, out_bottom, out_left,
            out_r0, out_r1, out_r2, out_r3,
            out_uv, out_ut)


async def apply(dut, elements: ElementsState, grid: GridState,
                variable_id, tile_id, rotation,
                in_uv, in_ut,
                in_top, in_right, in_bottom, in_left,
                in_r0, in_r1, in_r2, in_r3):
    dut.in_variableId.value           = variable_id
    dut.in_tileId.value               = tile_id
    dut.in_rotation.value             = rotation
    dut.in_unassigned_variables.value = in_uv
    dut.in_unassigned_tiles.value     = in_ut
    dut.in_colours_top.value          = grid.pack_colour(in_top)
    dut.in_colours_right.value        = grid.pack_colour(in_right)
    dut.in_colours_bottom.value       = grid.pack_colour(in_bottom)
    dut.in_colours_left.value         = grid.pack_colour(in_left)
    dut.in_domain_r0.value            = grid.pack_domain(in_r0)
    dut.in_domain_r1.value            = grid.pack_domain(in_r1)
    dut.in_domain_r2.value            = grid.pack_domain(in_r2)
    dut.in_domain_r3.value            = grid.pack_domain(in_r3)
    dut.in_elements_top.value         = elements.pack_colour(elements.ELEMENTS_TOP)
    dut.in_elements_right.value       = elements.pack_colour(elements.ELEMENTS_RIGHT)
    dut.in_elements_bottom.value      = elements.pack_colour(elements.ELEMENTS_BOTTOM)
    dut.in_elements_left.value        = elements.pack_colour(elements.ELEMENTS_LEFT)
    await Timer(1, unit="ns")


async def check(dut, elements: ElementsState, grid: GridState,
                variable_id, tile_id, rotation,
                in_uv, in_ut,
                in_top, in_right, in_bottom, in_left,
                in_r0, in_r1, in_r2, in_r3):
    await apply(dut, elements, grid,
                variable_id, tile_id, rotation,
                in_uv, in_ut,
                in_top, in_right, in_bottom, in_left,
                in_r0, in_r1, in_r2, in_r3)

    (exp_top, exp_right, exp_bottom, exp_left,
     exp_r0, exp_r1, exp_r2, exp_r3,
     exp_uv, exp_ut) = reference(
        elements, variable_id, tile_id, rotation,
        in_uv, in_ut,
        in_top, in_right, in_bottom, in_left,
        in_r0, in_r1, in_r2, in_r3)

    act_top    = grid._unpack_colour(dut.out_colours_top.value.to_unsigned())
    act_right  = grid._unpack_colour(dut.out_colours_right.value.to_unsigned())
    act_bottom = grid._unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    act_left   = grid._unpack_colour(dut.out_colours_left.value.to_unsigned())
    act_r0     = grid._unpack_domain(dut.out_domain_r0.value.to_unsigned())
    act_r1     = grid._unpack_domain(dut.out_domain_r1.value.to_unsigned())
    act_r2     = grid._unpack_domain(dut.out_domain_r2.value.to_unsigned())
    act_r3     = grid._unpack_domain(dut.out_domain_r3.value.to_unsigned())
    act_uv     = int(dut.out_unassigned_variables.value)
    act_ut     = int(dut.out_unassigned_tiles.value)

    for v in range(V):
        assert act_top[v]    == exp_top[v],    \
            f"top[{v}]={act_top[v]:0{CC}b} exp={exp_top[v]:0{CC}b}"
        assert act_right[v]  == exp_right[v],  \
            f"right[{v}]={act_right[v]:0{CC}b} exp={exp_right[v]:0{CC}b}"
        assert act_bottom[v] == exp_bottom[v], \
            f"bottom[{v}]={act_bottom[v]:0{CC}b} exp={exp_bottom[v]:0{CC}b}"
        assert act_left[v]   == exp_left[v],   \
            f"left[{v}]={act_left[v]:0{CC}b} exp={exp_left[v]:0{CC}b}"
        assert act_r0[v] == exp_r0[v], \
            f"r0[{v}]={act_r0[v]:0{V}b} exp={exp_r0[v]:0{V}b}"
        assert act_r1[v] == exp_r1[v], \
            f"r1[{v}]={act_r1[v]:0{V}b} exp={exp_r1[v]:0{V}b}"
        assert act_r2[v] == exp_r2[v], \
            f"r2[{v}]={act_r2[v]:0{V}b} exp={exp_r2[v]:0{V}b}"
        assert act_r3[v] == exp_r3[v], \
            f"r3[{v}]={act_r3[v]:0{V}b} exp={exp_r3[v]:0{V}b}"

    assert act_uv == exp_uv, \
        f"unassigned_variables={act_uv:#x} exp={exp_uv:#x}"
    assert act_ut == exp_ut, \
        f"unassigned_tiles={act_ut:#x} exp={exp_ut:#x}"


def full_colours(): return [CC_MASK] * V
def full_domains(): return [ALL_DOM] * V
def full_mask():    return ALL_DOM


@cocotb.test()
async def test_domain_locked_r0(dut):
    """Assigned variable's domain is locked to one tile in rotation 0."""
    await check(dut, data_elements_brendan3, data_initial_grid_brendan3,
                5, 3, 0, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    act_r0 = data_initial_grid_brendan3._unpack_domain(dut.out_domain_r0.value.to_unsigned())
    act_r1 = data_initial_grid_brendan3._unpack_domain(dut.out_domain_r1.value.to_unsigned())
    act_r2 = data_initial_grid_brendan3._unpack_domain(dut.out_domain_r2.value.to_unsigned())
    act_r3 = data_initial_grid_brendan3._unpack_domain(dut.out_domain_r3.value.to_unsigned())
    assert act_r0[5] == (1 << 3), "r0 should have only tile 3"
    assert act_r1[5] == 0,        "r1 should be zero"
    assert act_r2[5] == 0,        "r2 should be zero"
    assert act_r3[5] == 0,        "r3 should be zero"
    cocotb.log.info("domain locked rotation 0 ✓")


@cocotb.test()
async def test_domain_locked_r1(dut):
    """Assigned variable's domain is locked to one tile in rotation 1."""
    await check(dut, data_elements_brendan3, data_initial_grid_brendan3,
                5, 3, 1, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    act_r0 = data_initial_grid_brendan3._unpack_domain(dut.out_domain_r0.value.to_unsigned())
    act_r1 = data_initial_grid_brendan3._unpack_domain(dut.out_domain_r1.value.to_unsigned())
    assert act_r0[5] == 0,        "r0 should be zero"
    assert act_r1[5] == (1 << 3), "r1 should have only tile 3"
    cocotb.log.info("domain locked rotation 1 ✓")


@cocotb.test()
async def test_own_colours_set(dut):
    """Assigned variable's colours match piece pattern at chosen rotation."""
    tile_id  = 5
    rotation = 2
    await check(dut, data_elements_brendan3, data_initial_grid_brendan3,
                6, tile_id, rotation, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    exp_t, exp_r, exp_b, exp_l = piece_colours(data_elements_brendan3, tile_id, rotation)
    act_top    = data_initial_grid_brendan3._unpack_colour(dut.out_colours_top.value.to_unsigned())
    act_right  = data_initial_grid_brendan3._unpack_colour(dut.out_colours_right.value.to_unsigned())
    act_bottom = data_initial_grid_brendan3._unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    act_left   = data_initial_grid_brendan3._unpack_colour(dut.out_colours_left.value.to_unsigned())
    assert act_top[6]    == exp_t, f"top mismatch got={act_top[6]:0{CC}b} exp={exp_t:0{CC}b}"
    assert act_right[6]  == exp_r, f"right mismatch"
    assert act_bottom[6] == exp_b, f"bottom mismatch"
    assert act_left[6]   == exp_l, f"left mismatch"
    cocotb.log.info("own colours set ✓")


@cocotb.test()
async def test_neighbour_colours_updated(dut):
    """Inner variable — all four neighbours get colour constraints applied."""
    await check(dut, data_elements_brendan3, data_initial_grid_brendan3,
                4, 0, 0, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("neighbour colours updated ✓")


@cocotb.test()
async def test_top_left_corner_safe(dut):
    """Top-left corner (var 0) — no up or left neighbours, no out-of-bounds access."""
    await check(dut, data_elements_brendan3, data_initial_grid_brendan3,
                0, 0, 1, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("top-left corner safe ✓")


@cocotb.test()
async def test_bottom_right_corner_safe(dut):
    """Bottom-right corner (var V-1) — no right or down neighbours."""
    await check(dut, data_elements_brendan3, data_initial_grid_brendan3,
                V-1, 1, 3, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("bottom-right corner safe ✓")


@cocotb.test()
async def test_top_right_corner_safe(dut):
    """Top-right corner (var N-1) — no up or right neighbours."""
    await check(dut, data_elements_brendan3, data_initial_grid_brendan3,
                N-1, 2, 2, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("top-right corner safe ✓")


@cocotb.test()
async def test_bottom_left_corner_safe(dut):
    """Bottom-left corner (var N*(N-1)) — no left or down neighbours."""
    await check(dut, data_elements_brendan3, data_initial_grid_brendan3,
                N*(N-1), 3, 0, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("bottom-left corner safe ✓")


@cocotb.test()
async def test_unassigned_variable_bit_cleared(dut):
    """Assigned variable's bit is cleared in out_unassigned_variables."""
    await check(dut, data_elements_brendan3, data_initial_grid_brendan3,
                5, 3, 0, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    act_uv = int(dut.out_unassigned_variables.value)
    assert not (act_uv >> 5) & 1, "var 5 bit should be cleared"
    assert (act_uv >> 4) & 1,     "var 4 bit should still be set"
    cocotb.log.info("unassigned variable bit cleared ✓")





@cocotb.test()
async def test_random(dut):
    """30 random assignments verified against reference."""
    random.seed(55)
    r  = full_domains()
    uv = full_mask()
    ut = full_mask()
    for _ in range(30):
        vid = random.randint(0, V-1)
        tid = random.randint(0, V-1)
        rot = random.randint(0, 3)
        c   = [random.randint(1, CC_MASK) for _ in range(V)]
        await check(dut, data_elements_brendan3, data_initial_grid_brendan3,
                    vid, tid, rot, uv, ut, c, c, c, c, r, r, r, r)
    cocotb.log.info("30 random tests ✓")




def test_Assignment():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/Assignment.sv",
            "rtl/ColourLookup.sv",
            "rtl/ColourAssignment.sv",
            "rtl/ColourAssignmentNeighbours.sv",
        ],
        hdl_toplevel="Assignment",
        parameters={
            "N":  N,
            "CC": CC,
        },
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Assignment",
        test_module="test_Assignment",
    )