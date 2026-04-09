import cocotb
from cocotb_tools.runner import get_runner
from data_initial_grid_brendan4 import data_initial_grid_brendan4

@cocotb.test()
async def test_initial_state(dut):
    """FPGA output matches C++ solver snapshot: InitialGridCreated."""
    await data_initial_grid_brendan4.assert_dut(dut)
    cocotb.log.info("Brendan4_Load initial state matches C++ snapshot ✓")

def test_Brendan4_Load():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/CreateInitialGame.sv",
            "rtl/Brendan4_Load.sv",
        ],
        hdl_toplevel="Brendan4_Load",
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Brendan4_Load",
        test_module="test_Brendan4_Load",
    )