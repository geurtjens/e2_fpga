import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

from grid_state                        import GridState
from data_tileFrequencyBefore_brendan6 import data_tileFrequencyBefore_brendan6
from data_tileFrequencyAfter_brendan6  import data_tileFrequencyAfter_brendan6


async def _apply(dut, grid: GridState):
    """Drive all DUT inputs from GridState, then wait 1 ns."""
    dut.in_unassigned_variables.value = grid.UNASSIGNED_VARIABLES
    dut.in_unassigned_tiles.value     = grid.UNASSIGNED_TILES
    dut.in_domain_r0.value            = grid.pack_domain(grid.R0)
    dut.in_domain_r1.value            = grid.pack_domain(grid.R1)
    dut.in_domain_r2.value            = grid.pack_domain(grid.R2)
    dut.in_domain_r3.value            = grid.pack_domain(grid.R3)
    await Timer(1, unit="ns")


@cocotb.test()
async def test_tile_frequency_process_brendan6(dut):
    before = data_tileFrequencyBefore_brendan6
    cocotb.log.info(f"correct UV = {before.UNASSIGNED_VARIABLES & ~(1 << 33):#038b}")
    cocotb.log.info(f"correct UT = {before.UNASSIGNED_TILES & ~(1 << 8):#038b}")
    cocotb.log.info(f"correct R0[33] = {1 << 8:#038b}")

    """
    Brendan6 scenario: drive TileFrequencyProcess with the before snapshot
    and verify outputs match the after snapshot.

    TileFrequency forces tiles that can only go to one variable,
    collapsing their domains. SingletonAssignment then sweeps those
    collapsed domains and updates the availability masks.

    data_tileFrequencyBefore_brendan6 — input state
    data_tileFrequencyAfter_brendan6  — expected output state
    """
    await _apply(dut, data_tileFrequencyBefore_brendan6)

    data_tileFrequencyAfter_brendan6.print_domains_and_masks_comparison(
        "TileFrequencyProcess brendan6", dut)

    await data_tileFrequencyAfter_brendan6.assert_dut_domains_and_masks(dut)
    cocotb.log.info("tile frequency process brendan6 ✓")


def test_TileFrequency_Brendan6():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/TileFrequency.sv",
            "rtl/TileFrequency_Single.sv",
            "rtl/SingletonAssignment.sv",
        ],
        hdl_toplevel="TileFrequency",
        parameters={
            "N": data_tileFrequencyBefore_brendan6.N,
            "V": data_tileFrequencyBefore_brendan6.V,
        },
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNOPTFLAT"],
    )
    runner.test(
        hdl_toplevel="TileFrequency",
        test_module="test_TileFrequency_Brendan6",
    )