import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

from elements_state         import ElementsState
from data_brendan3_elements import data_brendan3_elements


# ── Rotation helpers ──────────────────────────────────────────

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


async def apply(dut, elements: ElementsState, tile_id: int, rotation: int):
    """Drive DUT inputs and wait 1 ns."""
    dut.in_tileId.value          = tile_id
    dut.in_rotation.value        = rotation
    dut.in_elements_top.value    = elements.pack_colour(elements.ELEMENTS_TOP)
    dut.in_elements_right.value  = elements.pack_colour(elements.ELEMENTS_RIGHT)
    dut.in_elements_bottom.value = elements.pack_colour(elements.ELEMENTS_BOTTOM)
    dut.in_elements_left.value   = elements.pack_colour(elements.ELEMENTS_LEFT)
    await Timer(1, unit="ns")


async def check(dut, elements: ElementsState, tile_id: int, rotation: int):
    """Apply inputs and compare DUT outputs against expected colours."""
    await apply(dut, elements, tile_id, rotation)

    exp_t, exp_r, exp_b, exp_l = expected_colours(elements, tile_id, rotation)

    act_t = int(dut.out_top.value)
    act_r = int(dut.out_right.value)
    act_b = int(dut.out_bottom.value)
    act_l = int(dut.out_left.value)

    cc = elements.CC
    assert act_t == exp_t, \
        f"tile={tile_id} rot={rotation} top={act_t:0{cc}b} exp={exp_t:0{cc}b}"
    assert act_r == exp_r, \
        f"tile={tile_id} rot={rotation} right={act_r:0{cc}b} exp={exp_r:0{cc}b}"
    assert act_b == exp_b, \
        f"tile={tile_id} rot={rotation} bottom={act_b:0{cc}b} exp={exp_b:0{cc}b}"
    assert act_l == exp_l, \
        f"tile={tile_id} rot={rotation} left={act_l:0{cc}b} exp={exp_l:0{cc}b}"


@cocotb.test()
async def test_all_tiles_all_rotations(dut):
    """
    Exhaustively verifies ColourLookup against data_brendan3_elements.

    data_brendan3_elements is the single source of truth for this test:
    - The element arrays (ELEMENTS_TOP, ELEMENTS_RIGHT, ELEMENTS_BOTTOM,
      ELEMENTS_LEFT) are packed and driven into the DUT inputs via pack_colour.
    - The expected colours are also derived from the same data via
      expected_colours() which applies the rotation logic in Python.

    So if data_brendan3_elements is correct and ColourLookup.sv is correct
    they will agree. If either is wrong the test will catch it.

    The test asks: does the hardware rotation logic match the Python rotation
    logic for every tile and rotation in this dataset?

    Checks all 9 tiles x 4 rotations = 36 combinations.
    """
    elements = data_brendan3_elements
    V = len(elements.ELEMENTS_TOP)
    for tile_id in range(V):
        for rotation in range(4):
            await check(dut, elements, tile_id, rotation)
            cocotb.log.info(f"tile={tile_id} rot={rotation} ✓")
    cocotb.log.info(f"all {V * 4} lookups passed ✓")


def test_ColourLookup_Brendan3():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/ColourLookup.sv"],
        hdl_toplevel="ColourLookup",
        parameters={
            "V":  len(data_brendan3_elements.ELEMENTS_TOP),
            "CC": data_brendan3_elements.CC,
        },
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="ColourLookup",
        test_module="test_ColourLookup_Brendan3",
    )