import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

V = 16
ALL_VARS = (1 << V) - 1
BITS_PER_COUNT = (4 * V + 1).bit_length()
COUNT_MASK = (1 << BITS_PER_COUNT) - 1

def pack_pop_count(values):
    val = 0
    for i in range(V):
        val |= (values[i] & COUNT_MASK) << (i * BITS_PER_COUNT)
    return val

async def apply(dut, candidates, pop_counts, min_count):
    dut.in_candidates.value = candidates
    dut.in_pop_count.value  = pack_pop_count(pop_counts)
    dut.in_min_count.value  = min_count
    await Timer(1, unit="ns")

@cocotb.test()
async def test_no_candidates(dut):
    """No candidates — valid=0."""
    await apply(dut, 0, [1]*V, 1)
    assert dut.out_valid.value == 0
    cocotb.log.info("no candidates → valid=0 ✓")

@cocotb.test()
async def test_single_candidate(dut):
    """Single candidate — selected."""
    counts = [0] * V
    counts[7] = 3
    await apply(dut, 1 << 7, counts, 3)
    assert dut.out_valid.value == 1
    assert int(dut.out_next_var.value) == 7
    cocotb.log.info("single candidate ✓")

@cocotb.test()
async def test_tie_lowest_id(dut):
    """Tie — lowest ID wins."""
    counts = [5] * V
    candidates = (1 << 3) | (1 << 7) | (1 << 12)
    await apply(dut, candidates, counts, 5)
    assert dut.out_valid.value == 1
    assert int(dut.out_next_var.value) == 3
    cocotb.log.info("tie → lowest ID wins ✓")

@cocotb.test()
async def test_mrv(dut):
    """Picks candidate with minimum count."""
    counts = [0] * V
    counts[2] = 8
    counts[5] = 3
    counts[9] = 6
    candidates = (1 << 2) | (1 << 5) | (1 << 9)
    await apply(dut, candidates, counts, 3)
    assert dut.out_valid.value == 1
    assert int(dut.out_next_var.value) == 5
    cocotb.log.info("MRV selects var 5 ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(44)
    for _ in range(50):
        candidates = random.randint(1, ALL_VARS)
        counts = [random.randint(0, 4*V) for _ in range(V)]
        min_count = min(counts[i] for i in range(V) if (candidates >> i) & 1)
        await apply(dut, candidates, counts, min_count)
        assert dut.out_valid.value == 1
        exp = min(i for i in range(V)
                  if (candidates >> i) & 1 and counts[i] == min_count)
        assert int(dut.out_next_var.value) == exp
    cocotb.log.info("50 random tests ✓")

def test_ChooseNextVariable_SelectVariable():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/ChooseNextVariable_SelectVariable.sv"],
        hdl_toplevel="ChooseNextVariable_SelectVariable",
        parameters={"V": V},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="ChooseNextVariable_SelectVariable",
        test_module="test_ChooseNextVariable_SelectVariable",
    )