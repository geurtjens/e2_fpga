import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

from elements_state                 import ElementsState
from grid_state                     import GridState
from data_elements_brendan3         import data_elements_brendan3
from data_initial_grid_brendan3     import data_initial_grid_brendan3
from data_first_assignment_brendan3 import data_first_assignment_brendan3


async def _apply(dut, elements: ElementsState, grid: GridState):
    """Drive all DUT inputs from ElementsState + GridState, then wait 1 ns."""
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
async def test_phase1_assign_process_brendan3(dut):
    """
    Brendan3 scenario: create puzzle → load elements → Phase1_AssignProcess
    for variable 0, tile 0, rotation 1.
    Drives inputs from the initial GridState and ElementsState.
    Compares outputs against the post-assignment GridState.

    Phase1_AssignProcess runs:
      Step 1 — Assignment: lock domain, set colours, propagate to neighbours.
      Steps 2 & 3 — AllDifferentProcess: AllDifferent_Simple then
                    SingletonDetection_WithoutDeadend, repeated DEPTH times.
      Step 4 — DomainToColour: recompute colours from settled domains.

    data_elements_brendan3 and data_initial_grid_brendan3 are the single
    source of truth for inputs. data_first_assignment_brendan3 is the
    expected output after Phase1_AssignProcess completes.
    """
    await _apply(dut, data_elements_brendan3, data_initial_grid_brendan3)

    cocotb.log.info(
        f"Assigning variable={data_initial_grid_brendan3.VARIABLE_TO_ASSIGN} "
        f"tile={data_initial_grid_brendan3.TILE_TO_ASSIGN} "
        f"rotation={data_initial_grid_brendan3.ROTATION_TO_ASSIGN}"
    )

    # ── Dump DUT vs expected domain outputs before checking ───
    gs = data_first_assignment_brendan3
    gs.print_domain_comparison("Domains after Phase1_AssignProcess", dut)
    gs.print_colour_comparison("Colours after Phase1_AssignProcess", dut)

    await data_first_assignment_brendan3.assert_dut(dut)
    cocotb.log.info("phase1 assign process brendan3 ✓")


def test_Phase1_AssignProcess1_Brendan3():
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
            "N":  data_initial_grid_brendan3.N,
            "CC": data_initial_grid_brendan3.CC,
        },
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Phase1_AssignProcess",
        test_module="test_Phase1_AssignProcess1_Brendan3",
    )