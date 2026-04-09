import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

from elements_state                 import ElementsState
from grid_state                     import GridState
from data_elements_brendan7         import data_elements_brendan7
from data_initial_grid_brendan7     import data_initial_grid_brendan7
from data_first_assignment_brendan7 import data_first_assignment_brendan7


async def _apply(dut, elements: ElementsState, grid: GridState):
    dut.in_variableId.value           = grid.VARIABLE_TO_ASSIGN
    dut.in_tileId.value               = grid.TILE_TO_ASSIGN
    dut.in_rotation.value             = grid.ROTATION_TO_ASSIGN
    dut.in_unassigned_variables.value = grid.UNASSIGNED_VARIABLES
    dut.in_unassigned_tiles.value     = grid.UNASSIGNED_TILES
    dut.in_colours_top.value          = grid.pack_colour(grid.TOP)
    dut.in_colours_right.value        = grid.pack_colour(grid.RIGHT)
    dut.in_colours_bottom.value       = grid.pack_colour(grid.BOTTOM)
    dut.in_colours_left.value         = grid.pack_colour(grid.LEFT)
    dut.in_domain_r0.value            = grid.pack_domain(grid.R0)
    dut.in_domain_r1.value            = grid.pack_domain(grid.R1)
    dut.in_domain_r2.value            = grid.pack_domain(grid.R2)
    dut.in_domain_r3.value            = grid.pack_domain(grid.R3)
    dut.in_elements_top.value         = elements.pack_colour(elements.ELEMENTS_TOP)
    dut.in_elements_right.value       = elements.pack_colour(elements.ELEMENTS_RIGHT)
    dut.in_elements_bottom.value      = elements.pack_colour(elements.ELEMENTS_BOTTOM)
    dut.in_elements_left.value        = elements.pack_colour(elements.ELEMENTS_LEFT)
    await Timer(1, unit="ns")


@cocotb.test()
async def test_phase1_assign_process_brendan7(dut):
    await _apply(dut, data_elements_brendan7, data_initial_grid_brendan7)
    cocotb.log.info(
        f"Assigning variable={data_initial_grid_brendan7.VARIABLE_TO_ASSIGN} "
        f"tile={data_initial_grid_brendan7.TILE_TO_ASSIGN} "
        f"rotation={data_initial_grid_brendan7.ROTATION_TO_ASSIGN}"
    )
    gs = data_first_assignment_brendan7
    gs.print_domain_comparison("Domains after Phase1_AssignProcess", dut)
    gs.print_colour_comparison("Colours after Phase1_AssignProcess", dut)
    await data_first_assignment_brendan7.assert_dut(dut)
    cocotb.log.info("phase1 assign process brendan7 ✓")


def test_Phase1_AssignProcess1_Brendan7():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/Phase1_AssignProcess.sv",
            "rtl/Assignment.sv",
            "rtl/ColourLookup.sv",
            "rtl/ColourAssignment.sv",
            "rtl/ColourAssignmentNeighbours.sv",
            "rtl/AllDifferentProcess.sv",
            "rtl/AllDifferent.sv",
            "rtl/SingletonAssignment.sv",
            "rtl/DomainToColour.sv",
            "rtl/DomainToColour_Rotation.sv",
        ],
        hdl_toplevel="Phase1_AssignProcess",
        parameters={
            "N":  data_initial_grid_brendan7.N,
            "CC": data_initial_grid_brendan7.CC,
        },
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Phase1_AssignProcess",
        test_module="test_Phase1_AssignProcess1_Brendan7",
    )