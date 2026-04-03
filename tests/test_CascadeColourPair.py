import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

async def apply(dut, right, left, down, up):
    dut.right.value = right
    dut.left.value  = left
    dut.down.value  = down
    dut.up.value    = up
    await Timer(1, unit="ns")

@cocotb.test()
async def test_basic_and(dut):
    await apply(dut, 0b111000, 0b101010, 0b111111, 0b000111)
    assert dut.out_h.value == 0b101000
    assert dut.out_v.value == 0b000111

@cocotb.test()
async def test_deadend_h(dut):
    await apply(dut, 0b101010, 0b010101, 0b111111, 0b111111)
    assert dut.deadend.value == 1

@cocotb.test()
async def test_deadend_v(dut):
    await apply(dut, 0b111111, 0b111111, 0b101010, 0b010101)
    assert dut.deadend.value == 1

@cocotb.test()
async def test_deadend_both(dut):
    await apply(dut, 0b101010, 0b010101, 0b101010, 0b010101)
    assert dut.deadend.value == 1

@cocotb.test()
async def test_no_deadend(dut):
    await apply(dut, 0b111111, 0b111111, 0b111111, 0b111111)
    assert dut.deadend.value == 0

@cocotb.test()
async def test_updated_h(dut):
    await apply(dut, 0b111111, 0b000111, 0b111111, 0b111111)
    assert dut.updated.value == 1

@cocotb.test()
async def test_updated_v(dut):
    await apply(dut, 0b111111, 0b111111, 0b111111, 0b000111)
    assert dut.updated.value == 1

@cocotb.test()
async def test_not_updated(dut):
    await apply(dut, 0b000111, 0b111111, 0b000111, 0b111111)
    assert dut.updated.value == 0

def test_CascadeColourPair():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/CascadeColourSingle.sv", "rtl/CascadeColourPair.sv"],
        hdl_toplevel="CascadeColourPair",
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="CascadeColourPair",
        test_module="test_CascadeColourPair",
    )