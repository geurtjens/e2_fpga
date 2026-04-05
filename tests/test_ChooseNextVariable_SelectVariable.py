import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

V              = 16
ALL_VARS       = (1 << V) - 1
BITS_PER_COUNT = (4 * V + 1).bit_length()
COUNT_MASK     = (1 << BITS_PER_COUNT) - 1

def pack_pop_count(values):
    val = 0
    for i in range(V):
        val |= (values[i] & COUNT_MASK) << (i * BITS_PER_COUNT)
    return val

def reference(candidates, counts, min_count):
    """Reference model — lowest ID candidate with min_count."""
    if candidates == 0:
        return None, False
    winners = [i for i in range(V)
               if (candidates >> i) & 1 and counts[i] == min_count]
    if not winners:
        return None, False
    return min(winners), True

async def apply(dut, candidates, pop_counts, min_count):
    dut.in_candidates.value = candidates
    dut.in_pop_count.value  = pack_pop_count(pop_counts)
    dut.in_min_count.value  = min_count
    await Timer(1, unit="ns")

async def check(dut, candidates, counts, min_count):
    await apply(dut, candidates, counts, min_count)
    exp_var, exp_valid = reference(candidates, counts, min_count)
    assert dut.out_valid.value == int(exp_valid), \
        f"candidates={candidates:#x} min_count={min_count}\n" \
        f"  valid got={dut.out_valid.value} exp={int(exp_valid)}"
    if exp_valid:
        assert int(dut.out_next_var.value) == exp_var, \
            f"candidates={candidates:#x} min_count={min_count}\n" \
            f"  next_var got={int(dut.out_next_var.value)} exp={exp_var}"

@cocotb.test()
async def test_no_candidates(dut):
    """No candidates — valid=0."""
    await apply(dut, 0, [1]*V, 1)
    assert dut.out_valid.value == 0
    cocotb.log.info("no candidates → valid=0 ✓")

@cocotb.test()
async def test_single_candidate(dut):
    """Single candidate — selected regardless of position."""
    counts = [0] * V
    counts[7] = 3
    await check(dut, 1 << 7, counts, 3)
    assert int(dut.out_next_var.value) == 7
    cocotb.log.info("single candidate ✓")

@cocotb.test()
async def test_single_candidate_var0(dut):
    """Single candidate at var 0 — selected."""
    counts = [0] * V
    counts[0] = 5
    await check(dut, 1 << 0, counts, 5)
    assert int(dut.out_next_var.value) == 0
    cocotb.log.info("single candidate var 0 ✓")

@cocotb.test()
async def test_single_candidate_last_var(dut):
    """Single candidate at last variable — selected."""
    counts = [0] * V
    counts[V-1] = 2
    await check(dut, 1 << (V-1), counts, 2)
    assert int(dut.out_next_var.value) == V - 1
    cocotb.log.info("single candidate last var ✓")

@cocotb.test()
async def test_tie_lowest_id(dut):
    """Tie — lowest ID wins."""
    counts = [5] * V
    candidates = (1 << 3) | (1 << 7) | (1 << 12)
    await check(dut, candidates, counts, 5)
    assert int(dut.out_next_var.value) == 3
    cocotb.log.info("tie → lowest ID wins ✓")

@cocotb.test()
async def test_tie_two_vars(dut):
    """Tie between two adjacent vars — lower ID wins."""
    counts = [0] * V
    counts[4] = 7
    counts[5] = 7
    candidates = (1 << 4) | (1 << 5)
    await check(dut, candidates, counts, 7)
    assert int(dut.out_next_var.value) == 4
    cocotb.log.info("tie two vars → lower ID wins ✓")

@cocotb.test()
async def test_mrv(dut):
    """Picks candidate with minimum count."""
    counts = [0] * V
    counts[2] = 8
    counts[5] = 3
    counts[9] = 6
    candidates = (1 << 2) | (1 << 5) | (1 << 9)
    await check(dut, candidates, counts, 3)
    assert int(dut.out_next_var.value) == 5
    cocotb.log.info("MRV selects var 5 ✓")

@cocotb.test()
async def test_mrv_first_var_not_minimum(dut):
    """Lowest ID candidate does not have minimum count — higher ID wins."""
    counts = [0] * V
    counts[0] = 10
    counts[3] = 2
    counts[8] = 6
    candidates = (1 << 0) | (1 << 3) | (1 << 8)
    await check(dut, candidates, counts, 2)
    assert int(dut.out_next_var.value) == 3
    cocotb.log.info("MRV — lowest ID not minimum ✓")

@cocotb.test()
async def test_non_candidate_ignored(dut):
    """Non-candidate variable with lower count is ignored."""
    counts = [0] * V
    counts[0] = 1   # lowest count but NOT a candidate
    counts[5] = 4   # candidate
    counts[9] = 4   # candidate
    candidates = (1 << 5) | (1 << 9)
    await check(dut, candidates, counts, 4)
    assert int(dut.out_next_var.value) == 5
    cocotb.log.info("non-candidate with lower count ignored ✓")

@cocotb.test()
async def test_all_candidates_same_count(dut):
    """All variables are candidates with same count — var 0 wins."""
    counts = [3] * V
    await check(dut, ALL_VARS, counts, 3)
    assert int(dut.out_next_var.value) == 0
    cocotb.log.info("all candidates same count → var 0 wins ✓")

@cocotb.test()
async def test_count_zero(dut):
    """Candidate with count zero — still selectable."""
    counts = [0] * V
    counts[6] = 0
    candidates = 1 << 6
    await check(dut, candidates, counts, 0)
    assert int(dut.out_next_var.value) == 6
    cocotb.log.info("count zero candidate selected ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(44)
    for _ in range(50):
        candidates = random.randint(1, ALL_VARS)
        counts     = [random.randint(0, 4*V) for _ in range(V)]
        min_count  = min(counts[i] for i in range(V) if (candidates >> i) & 1)
        await check(dut, candidates, counts, min_count)
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