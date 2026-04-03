import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

VARIABLES = 16
ALL = (1 << VARIABLES) - 1

def reference(domain):
    return domain != 0 and (domain & (domain - 1)) == 0

async def check(dut, domain):
    dut.domain.value = domain
    await Timer(1, unit="ns")
    exp = reference(domain)
    assert dut.is_singleton.value == int(exp), \
        f"domain={domain:#018b} is_singleton={dut.is_singleton.value} expected={int(exp)}"

@cocotb.test()
async def test_zero_not_singleton(dut):
    """Zero bits set — not a singleton."""
    await check(dut, 0)
    assert dut.is_singleton.value == 0
    cocotb.log.info("zero not singleton ✓")

@cocotb.test()
async def test_single_bit_is_singleton(dut):
    """Each individual bit set alone is a singleton."""
    for i in range(VARIABLES):
        await check(dut, 1 << i)
        assert dut.is_singleton.value == 1, f"bit {i} should be singleton"
    cocotb.log.info("all single bits are singletons ✓")

@cocotb.test()
async def test_two_bits_not_singleton(dut):
    """Two bits set — not a singleton."""
    for i in range(VARIABLES - 1):
        await check(dut, (1 << i) | (1 << (i + 1)))
        assert dut.is_singleton.value == 0, f"bits {i},{i+1} should not be singleton"
    cocotb.log.info("two bits not singleton ✓")

@cocotb.test()
async def test_all_bits_not_singleton(dut):
    """All bits set — not a singleton."""
    await check(dut, ALL)
    assert dut.is_singleton.value == 0
    cocotb.log.info("all bits not singleton ✓")

@cocotb.test()
async def test_all_powers_of_two(dut):
    """All powers of two up to VARIABLES bits are singletons."""
    for i in range(VARIABLES):
        await check(dut, 1 << i)
    cocotb.log.info("all powers of two ✓")

@cocotb.test()
async def test_random(dut):
    """100 random inputs verified against reference."""
    random.seed(42)
    for _ in range(100):
        domain = random.randint(0, ALL)
        await check(dut, domain)
    cocotb.log.info("100 random tests ✓")

def test_SingletonDetectionOne():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/SingletonDetectionOne.sv"],
        hdl_toplevel="SingletonDetectionOne",
        parameters={"VARIABLES": VARIABLES},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="SingletonDetectionOne",
        test_module="test_SingletonDetectionOne",
    )