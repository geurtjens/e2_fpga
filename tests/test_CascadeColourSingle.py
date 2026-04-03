import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

async def apply(dut, colour, neighbour):
    dut.colour.value = colour
    dut.neighbourColour.value = neighbour
    await Timer(1, unit="ns")

@cocotb.test()
async def test_and_output(dut):
    await apply(dut, 0b101010, 0b111000)
    assert dut.out.value == 0b101000

@cocotb.test()
async def test_deadend_when_no_overlap(dut):
    await apply(dut, 0b101010, 0b010101)
    assert dut.deadend.value == 1
    assert dut.out.value == 0

@cocotb.test()
async def test_no_deadend_when_overlap(dut):
    await apply(dut, 0b111000, 0b111000)
    assert dut.deadend.value == 0

@cocotb.test()
async def test_updated_when_neighbour_restricts(dut):
    await apply(dut, 0b111111, 0b000111)
    assert dut.updated.value == 1

@cocotb.test()
async def test_not_updated_when_no_change(dut):
    await apply(dut, 0b000111, 0b111111)
    assert dut.updated.value == 0

@cocotb.test()
async def test_all_zeros_input(dut):
    await apply(dut, 0, 0)
    assert dut.out.value == 0
    assert dut.deadend.value == 1
    assert dut.updated.value == 0

@cocotb.test()
async def test_all_ones_input(dut):
    await apply(dut, 0b111111, 0b111111)
    assert dut.out.value == 0b111111
    assert dut.deadend.value == 0
    assert dut.updated.value == 0

def test_CascadeColourSingle():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/CascadeColourSingle.sv"],
        hdl_toplevel="CascadeColourSingle",
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="CascadeColourSingle",
        test_module="test_CascadeColourSingle",
    )