import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import pytest

@cocotb.test()
async def test_nand_all_inputs(dut):
    for a in range(2):
        for b in range(2):
            dut.a.value = a
            dut.b.value = b
            await Timer(1, unit="ns")
            expected = int(not (a and b))
            assert dut.out.value == expected

def test_nand_gate():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/nand_gate.sv"],
        hdl_toplevel="nand_gate",
    )
    runner.test(
        hdl_toplevel="nand_gate",
        test_module="test_nand_gate",
    )
