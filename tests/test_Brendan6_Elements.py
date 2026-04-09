# test_Brendan6_Elements.py
import cocotb
from cocotb_tools.runner import get_runner
from data_elements_brendan6 import data_elements_brendan6

@cocotb.test()
async def test_elements(dut):
    """FPGA elements match C++ solver snapshot."""
    await data_elements_brendan6.assert_dut(dut)
    cocotb.log.info("Brendan6_Elements matches C++ snapshot ✓")

def test_Brendan6_Elements():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/Brendan6_Elements.sv"],
        hdl_toplevel="Brendan6_Elements",
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Brendan6_Elements",
        test_module="test_Brendan6_Elements",
    )