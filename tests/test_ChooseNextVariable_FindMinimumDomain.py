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

async def apply(dut, candidates, pop_counts):
    dut.in_candidates.value  = candidates
    dut.in_pop_count.value   = pack_pop_count(pop_counts)
    await Timer(1, unit="ns")

@cocotb.test()
async def test_single_candidate(dut):
    """Single candidate — min is its count."""
    counts = [10] * V
    counts[3] = 5
    await apply(dut, 1 << 3, counts)
    assert dut.out_min_count.value == 5
    cocotb.log.info("single candidate ✓")

@cocotb.test()
async def test_multiple_candidates(dut):
    """Multiple candidates — min is smallest."""
    counts = [0] * V
    counts[0] = 8
    counts[1] = 3
    counts[2] = 6
    await apply(dut, 0b111, counts)
    assert dut.out_min_count.value == 3
    cocotb.log.info("minimum found ✓")

@cocotb.test()
async def test_ignores_non_candidates(dut):
    """Non-candidate with small count is ignored."""
    counts = [5] * V
    counts[5] = 0
    candidates = ALL_VARS & ~(1 << 5)
    await apply(dut, candidates, counts)
    assert dut.out_min_count.value == 5
    cocotb.log.info("non-candidate ignored ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(33)
    for _ in range(50):
        candidates = random.randint(1, ALL_VARS)
        counts = [random.randint(0, 4*V) for _ in range(V)]
        await apply(dut, candidates, counts)
        exp = min(counts[i] for i in range(V) if (candidates >> i) & 1)
        assert dut.out_min_count.value == exp
    cocotb.log.info("50 random tests ✓")

def test_ChooseNextVariable_FindMinimumDomain():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/ChooseNextVariable_FindMinimumDomain.sv"],
        hdl_toplevel="ChooseNextVariable_FindMinimumDomain",
        parameters={"V": V},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="ChooseNextVariable_FindMinimumDomain",
        test_module="test_ChooseNextVariable_FindMinimumDomain",
    )