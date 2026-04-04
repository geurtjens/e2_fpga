import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

CC = 6
CC_MASK = (1 << CC) - 1

def reference(slot, neighbour):
    combined = slot & neighbour
    deadend  = combined == 0
    updated  = slot != combined or neighbour != combined
    return combined, deadend, updated

async def check(dut, slot, neighbour):
    dut.in_slotColour.value      = slot
    dut.in_neighbourColour.value = neighbour
    await Timer(1, unit="ns")
    exp_combined, exp_deadend, exp_updated = reference(slot, neighbour)
    assert dut.out_combinedColour.value == exp_combined, \
        f"combined={dut.out_combinedColour.value:06b} exp={exp_combined:06b}"
    assert dut.out_deadend.value == int(exp_deadend), \
        f"deadend={dut.out_deadend.value} exp={int(exp_deadend)}"
    assert dut.out_updated.value == int(exp_updated), \
        f"updated={dut.out_updated.value} exp={int(exp_updated)}"

@cocotb.test()
async def test_full_overlap(dut):
    """Both inputs identical all-ones — combined unchanged, no deadend, no update."""
    await check(dut, CC_MASK, CC_MASK)
    assert dut.out_deadend.value == 0
    assert dut.out_updated.value == 0
    cocotb.log.info("full overlap ✓")

@cocotb.test()
async def test_no_overlap_deadend(dut):
    """No overlap — combined is zero, deadend."""
    await check(dut, 0b010101, 0b101010)
    assert dut.out_deadend.value == 1
    cocotb.log.info("no overlap → deadend ✓")

@cocotb.test()
async def test_partial_overlap(dut):
    """Partial overlap — combined has common bits only."""
    await check(dut, 0b001111, 0b111100)
    assert dut.out_combinedColour.value == 0b001100
    assert dut.out_deadend.value == 0
    assert dut.out_updated.value == 1
    cocotb.log.info("partial overlap ✓")

@cocotb.test()
async def test_slot_restricts_neighbour(dut):
    """Slot colour restricts neighbour — updated."""
    await check(dut, 0b000111, CC_MASK)
    assert dut.out_combinedColour.value == 0b000111
    assert dut.out_updated.value == 1
    cocotb.log.info("slot restricts neighbour ✓")

@cocotb.test()
async def test_neighbour_restricts_slot(dut):
    """Neighbour colour restricts slot — updated."""
    await check(dut, CC_MASK, 0b000111)
    assert dut.out_combinedColour.value == 0b000111
    assert dut.out_updated.value == 1
    cocotb.log.info("neighbour restricts slot ✓")

@cocotb.test()
async def test_zero_slot(dut):
    """Zero slot — combined zero, deadend."""
    await check(dut, 0, CC_MASK)
    assert dut.out_deadend.value == 1
    cocotb.log.info("zero slot → deadend ✓")

@cocotb.test()
async def test_zero_neighbour(dut):
    """Zero neighbour — combined zero, deadend."""
    await check(dut, CC_MASK, 0)
    assert dut.out_deadend.value == 1
    cocotb.log.info("zero neighbour → deadend ✓")

@cocotb.test()
async def test_both_zero(dut):
    """Both zero — combined zero, deadend, no update."""
    await check(dut, 0, 0)
    assert dut.out_deadend.value == 1
    assert dut.out_updated.value == 0
    cocotb.log.info("both zero → deadend no update ✓")

@cocotb.test()
async def test_single_bit_match(dut):
    """Single bit in common — combined is one bit, not deadend."""
    await check(dut, 0b000001, CC_MASK)
    assert dut.out_combinedColour.value == 0b000001
    assert dut.out_deadend.value == 0
    cocotb.log.info("single bit match ✓")

@cocotb.test()
async def test_random(dut):
    """100 random inputs verified against reference."""
    random.seed(42)
    for _ in range(100):
        slot      = random.randint(0, CC_MASK)
        neighbour = random.randint(0, CC_MASK)
        await check(dut, slot, neighbour)
    cocotb.log.info("100 random tests ✓")

def test_CascadeColour_Single():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/CascadeColour_Single.sv"],
        hdl_toplevel="CascadeColour_Single",
        parameters={"CC": CC},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="CascadeColour_Single",
        test_module="test_CascadeColour_Single",
    )