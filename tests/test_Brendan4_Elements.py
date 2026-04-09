# test_Brendan4_Elements.py
import cocotb
from cocotb_tools.runner import get_runner
from data_elements_brendan4 import data_elements_brendan4

@cocotb.test()
async def test_elements(dut):
    """FPGA elements match C++ solver snapshot."""
    await data_elements_brendan4.assert_dut(dut)
    cocotb.log.info("Brendan4_Elements matches C++ snapshot ✓")

def test_Brendan4_Elements():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/Brendan4_Elements.sv"],
        hdl_toplevel="Brendan4_Elements",
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Brendan4_Elements",
        test_module="test_Brendan4_Elements",
    )