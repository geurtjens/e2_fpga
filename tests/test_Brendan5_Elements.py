# test_Brendan5_Elements.py
import cocotb
from cocotb_tools.runner import get_runner
from data_elements_brendan5 import data_elements_brendan5

@cocotb.test()
async def test_elements(dut):
    """FPGA elements match C++ solver snapshot."""
    await data_elements_brendan5.assert_dut(dut)
    cocotb.log.info("Brendan5_Elements matches C++ snapshot ✓")

def test_Brendan5_Elements():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/Brendan5_Elements.sv"],
        hdl_toplevel="Brendan5_Elements",
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Brendan5_Elements",
        test_module="test_Brendan5_Elements",
    )