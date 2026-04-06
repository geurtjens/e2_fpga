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

def reference(candidates, counts):
    # only consider candidates with count > 1
    valid = [counts[i] for i in range(V)
             if (candidates >> i) & 1 and counts[i] > 1]
    if not valid:
        return (1 << BITS_PER_COUNT) - 1  # max value — no valid candidates
    return min(valid)

async def apply(dut, candidates, pop_counts):
    dut.in_candidates.value = candidates
    dut.in_pop_count.value  = pack_pop_count(pop_counts)
    await Timer(1, unit="ns")

async def check(dut, candidates, counts):
    await apply(dut, candidates, counts)
    exp = reference(candidates, counts)
    act = int(dut.out_min_count.value)
    assert act == exp, \
        f"candidates={candidates:#x}\n" \
        f"  got={act} exp={exp}"

@cocotb.test()
async def test_single_candidate(dut):
    """Single candidate — min is its count."""
    counts = [10] * V
    counts[3] = 5
    await check(dut, 1 << 3, counts)
    cocotb.log.info("single candidate ✓")

@cocotb.test()
async def test_single_candidate_var0(dut):
    """Single candidate at var 0."""
    counts = [10] * V
    counts[0] = 3
    await check(dut, 1 << 0, counts)
    cocotb.log.info("single candidate var 0 ✓")

@cocotb.test()
async def test_single_candidate_last_var(dut):
    """Single candidate at last variable."""
    counts = [10] * V
    counts[V-1] = 7
    await check(dut, 1 << (V-1), counts)
    cocotb.log.info("single candidate last var ✓")

@cocotb.test()
async def test_multiple_candidates(dut):
    """Multiple candidates — min is smallest."""
    counts = [0] * V
    counts[0] = 8
    counts[1] = 3
    counts[2] = 6
    await check(dut, 0b111, counts)
    assert int(dut.out_min_count.value) == 3
    cocotb.log.info("minimum found ✓")

@cocotb.test()
async def test_ignores_non_candidates(dut):
    """Non-candidate with small count is ignored."""
    counts = [5] * V
    counts[5] = 0
    candidates = ALL_VARS & ~(1 << 5)
    await check(dut, candidates, counts)
    assert int(dut.out_min_count.value) == 5
    cocotb.log.info("non-candidate ignored ✓")

@cocotb.test()
async def test_all_candidates_equal(dut):
    """All candidates have same count — min equals that count."""
    counts = [7] * V
    await check(dut, ALL_VARS, counts)
    assert int(dut.out_min_count.value) == 7
    cocotb.log.info("all candidates equal ✓")

@cocotb.test()
async def test_min_at_last_candidate(dut):
    """Minimum is at the highest ID candidate — not missed by early exit.
    Count 1 is skipped so out_min_count stays at max."""
    counts = [10] * V
    counts[V-1] = 2  # changed from 1 to 2 — count 1 is now skipped
    await check(dut, ALL_VARS, counts)
    assert int(dut.out_min_count.value) == 2
    cocotb.log.info("min at last candidate ✓")

@cocotb.test()
async def test_count_zero_candidate_skipped(dut):
    """Candidate with count 0 is skipped — deadend variable not considered.
    Var 5 is a candidate with count 0, var 9 is a candidate with count 3.
    Expected: min_count = 3, not 0."""
    counts     = [10] * V   # large default for non-candidates
    counts[5]  = 0           # candidate but count 0 — deadend, must be skipped
    counts[9]  = 3           # candidate with valid count
    candidates = (1 << 5) | (1 << 9)
    await apply(dut, candidates, counts)
    assert int(dut.out_min_count.value) == 3, \
        f"count 0 should be skipped, expected min=3 got {int(dut.out_min_count.value)}"
    cocotb.log.info("count 0 candidate skipped ✓")

@cocotb.test()
async def test_count_one_candidate_skipped(dut):
    """Candidate with count 1 is skipped — singleton handled by SingletonDetection.
    Var 2 is a candidate with count 1, var 7 is a candidate with count 4.
    Expected: min_count = 4, not 1."""
    counts     = [10] * V   # large default for non-candidates
    counts[2]  = 1           # candidate but count 1 — singleton, must be skipped
    counts[7]  = 4           # candidate with valid count
    candidates = (1 << 2) | (1 << 7)
    await apply(dut, candidates, counts)
    assert int(dut.out_min_count.value) == 4, \
        f"count 1 should be skipped, expected min=4 got {int(dut.out_min_count.value)}"
    cocotb.log.info("count 1 candidate skipped ✓")

@cocotb.test()
async def test_all_candidates_count_zero_or_one_skipped(dut):
    """All candidates have count 0 or 1 — all skipped, out_min_count stays at max.
    This represents a state where all neighbours are either deadends or singletons."""
    counts     = [10] * V   # large default for non-candidates
    counts[3]  = 0           # candidate — deadend
    counts[6]  = 1           # candidate — singleton
    counts[11] = 0           # candidate — deadend
    candidates = (1 << 3) | (1 << 6) | (1 << 11)
    await apply(dut, candidates, counts)
    # out_min_count should stay at max value since no valid candidates exist
    max_val = (1 << BITS_PER_COUNT) - 1
    assert int(dut.out_min_count.value) == max_val, \
        f"all skipped, expected max value got {int(dut.out_min_count.value)}"
    cocotb.log.info("all count 0 or 1 candidates skipped — min stays at max ✓")

@cocotb.test()
async def test_mix_of_valid_and_skipped_candidates(dut):
    """Mix of count 0, count 1 and valid candidates — only valid ones contribute.
    Var 1 count=0, var 4 count=1, var 8 count=2, var 12 count=5.
    Expected: min_count = 2 — only vars 8 and 12 are valid candidates."""
    counts      = [10] * V
    counts[1]   = 0          # deadend — skipped
    counts[4]   = 1          # singleton — skipped
    counts[8]   = 2          # valid — smallest valid count
    counts[12]  = 5          # valid
    candidates  = (1 << 1) | (1 << 4) | (1 << 8) | (1 << 12)
    await apply(dut, candidates, counts)
    assert int(dut.out_min_count.value) == 2, \
        f"expected min=2 among valid candidates, got {int(dut.out_min_count.value)}"
    cocotb.log.info("mix of valid and skipped candidates — min=2 ✓")

@cocotb.test()
async def test_two_candidates_min_is_second(dut):
    """Two candidates — min is the second one."""
    counts = [0] * V
    counts[2] = 9
    counts[8] = 4
    await check(dut, (1 << 2) | (1 << 8), counts)
    assert int(dut.out_min_count.value) == 4
    cocotb.log.info("two candidates min is second ✓")

@cocotb.test()
async def test_only_non_candidates_have_small_counts(dut):
    """All candidates have large counts, non-candidates have small — min ignores non-candidates."""
    counts = [1] * V        # small counts everywhere
    for i in range(4, 8):
        counts[i] = 100     # large counts for our candidates
    candidates = 0b11110000  # vars 4-7
    await check(dut, candidates, counts)
    assert int(dut.out_min_count.value) == 100
    cocotb.log.info("only non-candidates have small counts — ignored ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(33)
    for _ in range(50):
        candidates = random.randint(1, ALL_VARS)
        counts     = [random.randint(0, 4*V) for _ in range(V)]
        await check(dut, candidates, counts)
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