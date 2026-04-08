import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

from elements_state                 import ElementsState
from grid_state                     import GridState
from data_brendan3_elements         import data_brendan3_elements
from data_brendan3_initial_grid     import data_brendan3_initial_grid
from data_brendan3_first_assignment import data_brendan3_first_assignment


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
async def test_first_assignment_brendan3(dut):
    """
    Brendan3 scenario: create puzzle → load elements → assign variable 0,
    tile 0, rotation 1.  Drive inputs from the initial GridState and
    ElementsState; compare outputs against the post-assignment GridState.
    """
    await _apply(dut, data_brendan3_elements, data_brendan3_initial_grid)

    cocotb.log.info(
        f"Assigning variable={data_brendan3_initial_grid.VARIABLE_TO_ASSIGN} "
        f"tile={data_brendan3_initial_grid.TILE_TO_ASSIGN} "
        f"rotation={data_brendan3_initial_grid.ROTATION_TO_ASSIGN}"
    )

    # ── Dump DUT vs expected domain outputs before checking ───
    gs = data_brendan3_first_assignment
    for rname, act_raw, exp in [
        ("r0", dut.out_domain_r0.value.to_unsigned(), gs.R0),
        ("r1", dut.out_domain_r1.value.to_unsigned(), gs.R1),
        ("r2", dut.out_domain_r2.value.to_unsigned(), gs.R2),
        ("r3", dut.out_domain_r3.value.to_unsigned(), gs.R3),
    ]:
        act = gs._unpack_domain(act_raw)
        for v in range(gs.V):
            match = "✓" if act[v] == exp[v] else "✗"
            cocotb.log.info(
                f"{match} domain_{rname}[{v}] "
                f"DUT={act[v]:#018b} "
                f"EXP={exp[v]:#018b}"
            )
    # Dump out values end


    await data_brendan3_first_assignment.assert_dut(dut)
    cocotb.log.info("first assignment brendan3 ✓")
    

def test_Assignment_Brendan3_First():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/Assignment.sv",
                "rtl/AllDifferent_Simple.sv",
                "rtl/DomainToColour.sv",
                "rtl/DomainToColour_Rotation.sv"],
        hdl_toplevel="Assignment",
        parameters={
            "N":  data_brendan3_initial_grid.N,
            "CC": data_brendan3_initial_grid.CC,
        },
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Assignment",
        test_module="test_Assignment_Brendan3_First",
    )