import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

from elements_state             import ElementsState
from grid_state                 import GridState
from data_brendan3_elements     import data_brendan3_elements
from data_brendan3_initial_grid import data_brendan3_initial_grid


def rotate_cw(top, right, bottom, left):
    """One 90-degree clockwise rotation — new_top=old_left."""
    return left, top, right, bottom

def expected_colours(elements: ElementsState, tile_id: int, rotation: int):
    """Derive expected colours for a tile at a given rotation."""
    t = elements.ELEMENTS_TOP[tile_id]
    r = elements.ELEMENTS_RIGHT[tile_id]
    b = elements.ELEMENTS_BOTTOM[tile_id]
    l = elements.ELEMENTS_LEFT[tile_id]
    for _ in range(rotation):
        t, r, b, l = rotate_cw(t, r, b, l)
    return t, r, b, l


async def apply(dut, grid: GridState,
                variable_id: int, piece_top: int, piece_right: int,
                piece_bottom: int, piece_left: int):
    """Drive all DUT inputs and wait 1 ns."""
    dut.in_variableId.value     = variable_id
    dut.in_piece_top.value      = piece_top
    dut.in_piece_right.value    = piece_right
    dut.in_piece_bottom.value   = piece_bottom
    dut.in_piece_left.value     = piece_left
    dut.in_colours_top.value    = grid.pack_colour(grid.TOP)
    dut.in_colours_right.value  = grid.pack_colour(grid.RIGHT)
    dut.in_colours_bottom.value = grid.pack_colour(grid.BOTTOM)
    dut.in_colours_left.value   = grid.pack_colour(grid.LEFT)
    await Timer(1, unit="ns")


@cocotb.test()
async def test_colour_assignment_brendan3(dut):
    """
    Tests ColourAssignment using data_brendan3_initial_grid and
    data_brendan3_elements as the single source of truth.

    Expected piece colours for tile 0 at rotation 1 are derived
    from data_brendan3_elements in Python and driven directly into
    the DUT as in_piece_top/right/bottom/left — ColourAssignment
    only writes colours into the array, it does not do lookup.

    Verifies that:
    - Variable 0's colours match the expected piece colours.
    - All other variables are unchanged from the initial grid.
    """
    variable_id = 0
    tile_id     = 0
    rotation    = 1

    exp_t, exp_r, exp_b, exp_l = expected_colours(
        data_brendan3_elements, tile_id, rotation)

    cocotb.log.info(
        f"Assigning variable={variable_id} tile={tile_id} rotation={rotation}"
    )
    cocotb.log.info(
        f"Piece colours: top={exp_t:0{data_brendan3_elements.CC}b} "
        f"right={exp_r:0{data_brendan3_elements.CC}b} "
        f"bottom={exp_b:0{data_brendan3_elements.CC}b} "
        f"left={exp_l:0{data_brendan3_elements.CC}b}"
    )

    await apply(dut, data_brendan3_initial_grid,
                variable_id, exp_t, exp_r, exp_b, exp_l)

    # ── Unpack DUT output colour arrays ───────────────────────
    cc = data_brendan3_initial_grid.CC
    V  = data_brendan3_initial_grid.V

    act_top    = data_brendan3_initial_grid._unpack_colour(
        dut.out_colours_top.value.to_unsigned())
    act_right  = data_brendan3_initial_grid._unpack_colour(
        dut.out_colours_right.value.to_unsigned())
    act_bottom = data_brendan3_initial_grid._unpack_colour(
        dut.out_colours_bottom.value.to_unsigned())
    act_left   = data_brendan3_initial_grid._unpack_colour(
        dut.out_colours_left.value.to_unsigned())

    # ── Print all variable colours after assignment ────────────
    cocotb.log.info("── Colour arrays after assignment ──────────────────")
    for v in range(V):
        marker = " ◄ assigned" if v == variable_id else ""
        cocotb.log.info(
            f"  var={v}  "
            f"top={act_top[v]:0{cc}b}  "
            f"right={act_right[v]:0{cc}b}  "
            f"bottom={act_bottom[v]:0{cc}b}  "
            f"left={act_left[v]:0{cc}b}"
            f"{marker}"
        )

    # ── Assert assigned variable colours are correct ──────────
    assert act_top[variable_id]    == exp_t, \
        f"top={act_top[variable_id]:0{cc}b} exp={exp_t:0{cc}b}"
    assert act_right[variable_id]  == exp_r, \
        f"right={act_right[variable_id]:0{cc}b} exp={exp_r:0{cc}b}"
    assert act_bottom[variable_id] == exp_b, \
        f"bottom={act_bottom[variable_id]:0{cc}b} exp={exp_b:0{cc}b}"
    assert act_left[variable_id]   == exp_l, \
        f"left={act_left[variable_id]:0{cc}b} exp={exp_l:0{cc}b}"

    # ── Assert all other variables are unchanged ───────────────
    for v in range(V):
        if v != variable_id:
            assert act_top[v]    == data_brendan3_initial_grid.TOP[v], \
                f"var={v} top changed unexpectedly"
            assert act_right[v]  == data_brendan3_initial_grid.RIGHT[v], \
                f"var={v} right changed unexpectedly"
            assert act_bottom[v] == data_brendan3_initial_grid.BOTTOM[v], \
                f"var={v} bottom changed unexpectedly"
            assert act_left[v]   == data_brendan3_initial_grid.LEFT[v], \
                f"var={v} left changed unexpectedly"

    cocotb.log.info("colour assignment brendan3 ✓")


def test_ColourAssignment_Brendan3():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/ColourAssignment.sv"],
        hdl_toplevel="ColourAssignment",
        parameters={
            "N":  data_brendan3_initial_grid.N,
            "CC": data_brendan3_initial_grid.CC,
        },
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="ColourAssignment",
        test_module="test_ColourAssignment_Brendan3",
    )