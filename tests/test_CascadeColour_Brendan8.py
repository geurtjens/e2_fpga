import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

from grid_state                         import GridState
from data_first_assignment_brendan8     import data_first_assignment_brendan8
from data_first_cascadeColours_brendan8 import data_first_cascadeColours_brendan8


async def _apply(dut, grid: GridState):
    """Drive CascadeColour inputs from GridState — colours only."""
    dut.in_colours_top.value    = grid.pack_colour(grid.TOP)
    dut.in_colours_right.value  = grid.pack_colour(grid.RIGHT)
    dut.in_colours_bottom.value = grid.pack_colour(grid.BOTTOM)
    dut.in_colours_left.value   = grid.pack_colour(grid.LEFT)
    await Timer(1, unit="ns")


@cocotb.test()
async def test_cascade_colours_brendan8(dut):
    """
    Brendan8 scenario: drive CascadeColour with the Phase1 output colours
    and verify the result matches the expected post-cascade state.

    data_first_assignment_brendan8     — input state (Phase1 output)
    data_first_cascadeColours_brendan8 — expected output state
    """
    await _apply(dut, data_first_assignment_brendan8)

    data_first_cascadeColours_brendan8.print_colour_comparison(
        "Colours after CascadeColour brendan8", dut)

    assert int(dut.out_deadend.value) == int(data_first_cascadeColours_brendan8.DEADEND), \
        f"deadend={int(dut.out_deadend.value)} exp={int(data_first_cascadeColours_brendan8.DEADEND)}"
    assert int(dut.out_updated.value) == int(data_first_cascadeColours_brendan8.UPDATED), \
        f"updated={int(dut.out_updated.value)} exp={int(data_first_cascadeColours_brendan8.UPDATED)}"

    act_top    = data_first_cascadeColours_brendan8._unpack_colour(
        dut.out_colours_top.value.to_unsigned())
    act_right  = data_first_cascadeColours_brendan8._unpack_colour(
        dut.out_colours_right.value.to_unsigned())
    act_bottom = data_first_cascadeColours_brendan8._unpack_colour(
        dut.out_colours_bottom.value.to_unsigned())
    act_left   = data_first_cascadeColours_brendan8._unpack_colour(
        dut.out_colours_left.value.to_unsigned())

    exp = data_first_cascadeColours_brendan8
    for v in range(exp.V):
        assert act_top[v]    == exp.TOP[v],    \
            f"top[{v}]    DUT={act_top[v]:#0{exp.CC+2}b} EXP={exp.TOP[v]:#0{exp.CC+2}b}"
        assert act_right[v]  == exp.RIGHT[v],  \
            f"right[{v}]  DUT={act_right[v]:#0{exp.CC+2}b} EXP={exp.RIGHT[v]:#0{exp.CC+2}b}"
        assert act_bottom[v] == exp.BOTTOM[v], \
            f"bottom[{v}] DUT={act_bottom[v]:#0{exp.CC+2}b} EXP={exp.BOTTOM[v]:#0{exp.CC+2}b}"
        assert act_left[v]   == exp.LEFT[v],   \
            f"left[{v}]   DUT={act_left[v]:#0{exp.CC+2}b} EXP={exp.LEFT[v]:#0{exp.CC+2}b}"

    cocotb.log.info("cascade colours brendan8 ✓")


def test_CascadeColour_Brendan8():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/CascadeColour.sv",
            "rtl/CascadeColour_Pair.sv",
            "rtl/CascadeColour_Single.sv",
        ],
        hdl_toplevel="CascadeColour",
        parameters={
            "N": data_first_assignment_brendan8.N,
            "CC": data_first_assignment_brendan8.CC,
        },
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="CascadeColour",
        test_module="test_CascadeColour_Brendan8",
    )