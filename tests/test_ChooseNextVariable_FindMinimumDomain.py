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
    return min(counts[i] for i in range(V) if (candidates >> i) & 1)

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
    """Minimum is at the highest ID candidate — not missed by early exit."""
    counts = [10] * V
    counts[V-1] = 1
    await check(dut, ALL_VARS, counts)
    assert int(dut.out_min_count.value) == 1
    cocotb.log.info("min at last candidate ✓")

@cocotb.test()
async def test_min_count_zero(dut):
    """Candidate with count zero — min is zero."""
    counts = [5] * V
    counts[4] = 0
    await check(dut, ALL_VARS, counts)
    assert int(dut.out_min_count.value) == 0
    cocotb.log.info("min count zero ✓")

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