import cocotb
from cocotb_tools.runner import get_runner
from data_initial_grid_brendan5 import data_initial_grid_brendan5

@cocotb.test()
async def test_initial_state(dut):
    """FPGA output matches C++ solver snapshot: InitialGridCreated."""
    await data_initial_grid_brendan5.assert_dut(dut)
    cocotb.log.info("Brendan5_Load initial state matches C++ snapshot ✓")

def test_Brendan5_Load():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/CreateInitialGame.sv",
            "rtl/Brendan5_Load.sv",
        ],
        hdl_toplevel="Brendan5_Load",
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Brendan5_Load",
        test_module="test_Brendan5_Load",
    )