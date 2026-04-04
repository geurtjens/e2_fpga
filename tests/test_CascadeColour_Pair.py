import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

CC = 6
CC_MASK = (1 << CC) - 1

def reference(slot_right, neighbour_left, slot_down, neighbour_up):
    h = slot_right & neighbour_left
    v = slot_down  & neighbour_up
    h_deadend = h == 0
    v_deadend = v == 0
    h_updated = slot_right != h or neighbour_left != h
    v_updated = slot_down  != v or neighbour_up   != v
    deadend = h_deadend or v_deadend
    updated = h_updated or v_updated
    return h, v, deadend, updated

async def check(dut, slot_right, neighbour_left, slot_down, neighbour_up):
    dut.in_slotRightColour.value    = slot_right
    dut.in_neighbourLeftColour.value = neighbour_left
    dut.in_slotDownColour.value     = slot_down
    dut.in_neighbourUpColour.value  = neighbour_up
    await Timer(1, unit="ns")

    exp_h, exp_v, exp_de, exp_up = \
        reference(slot_right, neighbour_left, slot_down, neighbour_up)

    assert dut.out_horizontalColour.value == exp_h, \
        f"h={dut.out_horizontalColour.value:06b} exp={exp_h:06b}"
    assert dut.out_verticalColour.value == exp_v, \
        f"v={dut.out_verticalColour.value:06b} exp={exp_v:06b}"
    assert dut.out_deadend.value == int(exp_de), \
        f"deadend={dut.out_deadend.value} exp={int(exp_de)}"
    assert dut.out_updated.value == int(exp_up), \
        f"updated={dut.out_updated.value} exp={int(exp_up)}"

@cocotb.test()
async def test_all_ones_no_change(dut):
    """All-ones inputs — both outputs unchanged, no deadend, no update."""
    await check(dut, CC_MASK, CC_MASK, CC_MASK, CC_MASK)
    assert dut.out_deadend.value == 0
    assert dut.out_updated.value == 0
    cocotb.log.info("all ones ✓")

@cocotb.test()
async def test_horizontal_cascade(dut):
    """Horizontal AND propagated correctly."""
    await check(dut, 0b001111, 0b111100, CC_MASK, CC_MASK)
    assert dut.out_horizontalColour.value == 0b001100
    assert dut.out_updated.value == 1
    cocotb.log.info("horizontal cascade ✓")

@cocotb.test()
async def test_vertical_cascade(dut):
    """Vertical AND propagated correctly."""
    await check(dut, CC_MASK, CC_MASK, 0b001111, 0b111100)
    assert dut.out_verticalColour.value == 0b001100
    assert dut.out_updated.value == 1
    cocotb.log.info("vertical cascade ✓")

@cocotb.test()
async def test_horizontal_deadend(dut):
    """No overlap on horizontal — deadend."""
    await check(dut, 0b010101, 0b101010, CC_MASK, CC_MASK)
    assert dut.out_deadend.value == 1
    cocotb.log.info("horizontal deadend ✓")

@cocotb.test()
async def test_vertical_deadend(dut):
    """No overlap on vertical — deadend."""
    await check(dut, CC_MASK, CC_MASK, 0b010101, 0b101010)
    assert dut.out_deadend.value == 1
    cocotb.log.info("vertical deadend ✓")

@cocotb.test()
async def test_both_deadend(dut):
    """No overlap on both — deadend."""
    await check(dut, 0b010101, 0b101010, 0b010101, 0b101010)
    assert dut.out_deadend.value == 1
    cocotb.log.info("both deadend ✓")

@cocotb.test()
async def test_zero_inputs(dut):
    """Zero inputs — deadend on both."""
    await check(dut, 0, 0, 0, 0)
    assert dut.out_deadend.value == 1
    assert dut.out_updated.value == 0
    cocotb.log.info("zero inputs ✓")

@cocotb.test()
async def test_random(dut):
    """100 random inputs verified against reference."""
    random.seed(31)
    for _ in range(100):
        sr = random.randint(0, CC_MASK)
        nl = random.randint(0, CC_MASK)
        sd = random.randint(0, CC_MASK)
        nu = random.randint(0, CC_MASK)
        await check(dut, sr, nl, sd, nu)
    cocotb.log.info("100 random tests ✓")

def test_CascadeColour_Pair():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/CascadeColour_Single.sv",
            "rtl/CascadeColour_Pair.sv",
        ],
        hdl_toplevel="CascadeColour_Pair",
        parameters={"CC": CC},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="CascadeColour_Pair",
        test_module="test_CascadeColour_Pair",
    )