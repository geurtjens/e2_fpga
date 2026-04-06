import cocotb
from cocotb_tools.runner import get_runner
from data_brendan8_initial_grid import data_brendan8_initial_grid

@cocotb.test()
async def test_initial_state(dut):
    """FPGA output matches C++ solver snapshot: InitialGridCreated."""
    await data_brendan8_initial_grid.assert_dut(dut)
    cocotb.log.info("Brendan8_Load initial state matches C++ snapshot ✓")

def test_Brendan8_Load():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/CreateInitialGame.sv",
            "rtl/Brendan8_Load.sv",
        ],
        hdl_toplevel="Brendan8_Load",
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Brendan8_Load",
        test_module="test_Brendan8_Load",
    )