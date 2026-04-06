import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

V = 16
ALL_VARS = (1 << V) - 1
BITS_PER_COUNT = (4 * V + 1).bit_length()

# Packs a list of V domain bitmasks into a single wide integer for the DUT input.
# The hardware port in_domain_r0 is declared as [V-1:0][V-1:0] — a packed array
# where variable i occupies bits (i*V + V-1) down to (i*V).
# This function replicates that layout in Python so cocotb can drive the port correctly.
def pack_domain(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL_VARS) << (i * V)
    return val


# Unpacks the DUT's out_pop_count output into a list of V integers.
# The hardware port out_pop_count is declared as [V-1:0][BITS_PER_COUNT-1:0] —
# a packed array where variable i's count occupies bits
# (i*BITS_PER_COUNT + BITS_PER_COUNT-1) down to (i*BITS_PER_COUNT).
# BITS_PER_COUNT is the number of bits needed to hold the maximum possible
# count of 4*V (one bit per tile across four rotations).
# Reads the full packed output as an unsigned integer then for each variable i
# shifts right by i*BITS_PER_COUNT and masks to BITS_PER_COUNT bits to extract that variable's count.
def unpack_pop_count(dut):
    val = dut.out_pop_count.value.to_unsigned()
    return [(val >> (i * BITS_PER_COUNT)) & ((1 << BITS_PER_COUNT) - 1)
            for i in range(V)]

# Reference model — counts the total number of set bits across all four rotational domains for each variable.
# This is the combined domain size used by FindMinimumDomain and SelectVariable to apply the MRV heuristic.
def reference(r0, r1, r2, r3):
    return [bin(r0[i]).count('1') + bin(r1[i]).count('1') +
            bin(r2[i]).count('1') + bin(r3[i]).count('1')
            for i in range(V)]

async def apply(dut, r0, r1, r2, r3):
    dut.in_domain_r0.value = pack_domain(r0)
    dut.in_domain_r1.value = pack_domain(r1)
    dut.in_domain_r2.value = pack_domain(r2)
    dut.in_domain_r3.value = pack_domain(r3)
    await Timer(1, unit="ns")

@cocotb.test()
async def test_all_zeros(dut):
    """Empty domains — all counts zero."""
    r = [0] * V
    await apply(dut, r, r, r, r)
    counts = unpack_pop_count(dut)
    assert all(c == 0 for c in counts)
    cocotb.log.info("all zeros ✓")

@cocotb.test()
async def test_all_ones(dut):
    """Full domains — all counts = 4*V."""
    r = [ALL_VARS] * V
    await apply(dut, r, r, r, r)
    counts = unpack_pop_count(dut)
    assert all(c == 4 * V for c in counts)
    cocotb.log.info("all ones ✓")

@cocotb.test()
async def test_single_bit(dut):
    """Single bit in r0 only — count = 1."""
    r0 = [1] * V
    r  = [0] * V
    await apply(dut, r0, r, r, r)
    counts = unpack_pop_count(dut)
    assert all(c == 1 for c in counts)
    cocotb.log.info("single bit → count 1 ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(22)
    for _ in range(50):
        r0 = [random.randint(0, ALL_VARS) for _ in range(V)]
        r1 = [random.randint(0, ALL_VARS) for _ in range(V)]
        r2 = [random.randint(0, ALL_VARS) for _ in range(V)]
        r3 = [random.randint(0, ALL_VARS) for _ in range(V)]
        await apply(dut, r0, r1, r2, r3)
        exp = reference(r0, r1, r2, r3)
        counts = unpack_pop_count(dut)
        for i in range(V):
            assert counts[i] == exp[i], \
                f"var {i} count={counts[i]} expected={exp[i]}"
    cocotb.log.info("50 random tests ✓")

@cocotb.test()
async def test_incremental_domain_counts(dut):
    """Set each variable's domain to have an increasing number of bits — var 0 has
    1 bit, var 1 has 2 bits, var 2 has 3 bits and so on up to var V-1 has V bits.
    All bits are in r0 only, r1/r2/r3 are zero. Verifies each variable's count
    is computed independently and correctly."""
    r0 = [0] * V
    r  = [0] * V

    # set var i to have exactly i+1 bits set — (1 << (i+1)) - 1 gives i+1 ones
    for i in range(V):
        r0[i] = (1 << (i + 1)) - 1

    await apply(dut, r0, r, r, r)
    counts = unpack_pop_count(dut)

    for i in range(V):
        expected = i + 1
        assert counts[i] == expected, \
            f"var {i} count={counts[i]} expected={expected}"
        cocotb.log.info(f"var {i} domain={r0[i]:016b} count={counts[i]} ✓")

    cocotb.log.info("incremental domain counts ✓")

@cocotb.test()
async def test_incremental_domain_counts_all_rotations(dut):
    """Set each variable's domain to have an increasing number of bits across
    all four rotations. Var i gets i+1 bits in each of r0, r1, r2 and r3 so
    the total count for var i should be 4*(i+1).
    Verifies that counts are correctly summed across all four rotations."""
    r0 = [0] * V
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V

    # set var i to have exactly i+1 bits set in every rotation
    # (1 << (i+1)) - 1 gives a bitmask with i+1 ones in the lowest bits
    for i in range(V):
        r0[i] = (1 << (i + 1)) - 1
        r1[i] = (1 << (i + 1)) - 1
        r2[i] = (1 << (i + 1)) - 1
        r3[i] = (1 << (i + 1)) - 1

    await apply(dut, r0, r1, r2, r3)
    counts = unpack_pop_count(dut)

    for i in range(V):
        expected = 4 * (i + 1)  # i+1 bits in each of 4 rotations
        assert counts[i] == expected, \
            f"var {i} count={counts[i]} expected={expected}"
        cocotb.log.info(f"var {i} domain={r0[i]:016b} count={counts[i]} ✓")

    cocotb.log.info("incremental domain counts across all rotations ✓")






# Entry point called by pytest. Builds the Verilator simulation then runs
# all @cocotb.test() functions defined above.
def test_ChooseNextVariable_ComputeDomainSizes():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/ChooseNextVariable_ComputeDomainSizes.sv"],
        hdl_toplevel="ChooseNextVariable_ComputeDomainSizes",
        parameters={"V": V},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="ChooseNextVariable_ComputeDomainSizes",
        test_module="test_ChooseNextVariable_ComputeDomainSizes",
    )