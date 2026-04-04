import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

V = 16
ALL_VARS = (1 << V) - 1
BITS_PER_COUNT = (4 * V + 1).bit_length()

def pack_domain(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL_VARS) << (i * V)
    return val

def unpack_pop_count(dut):
    val = dut.out_pop_count.value.to_unsigned()
    return [(val >> (i * BITS_PER_COUNT)) & ((1 << BITS_PER_COUNT) - 1)
            for i in range(V)]

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