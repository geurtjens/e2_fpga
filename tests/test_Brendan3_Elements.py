# test_Brendan3_Elements.py
import cocotb
from cocotb_tools.runner import get_runner
from data_brendan3_elements import data_brendan3_elements

@cocotb.test()
async def test_elements(dut):
    """FPGA elements match C++ solver snapshot."""
    await data_brendan3_elements.assert_dut(dut)
    cocotb.log.info("Brendan3_Elements matches C++ snapshot ✓")

def test_Brendan3_Elements():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/Brendan3_Elements.sv"],
        hdl_toplevel="Brendan3_Elements",
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Brendan3_Elements",
        test_module="test_Brendan3_Elements",
    )