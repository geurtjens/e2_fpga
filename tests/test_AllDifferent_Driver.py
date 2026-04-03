import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
ALL = (1 << N) - 1

def reference(r0_in, r1_in, r2_in, r3_in, vim):
    # Calculate tiles taken from inactive variables
    tiles_taken = 0
    for i in range(N):
        if not ((vim >> i) & 1):
            tiles_taken |= r0_in[i] | r1_in[i] | r2_in[i] | r3_in[i]
    tiles_taken &= ALL
    mask = (~tiles_taken) & ALL

    r0_out = list(r0_in)
    r1_out = list(r1_in)
    r2_out = list(r2_in)
    r3_out = list(r3_in)
    changed = False
    deadend = False

    for i in range(N):
        if (vim >> i) & 1:
            r0_out[i] = r0_in[i] & mask
            r1_out[i] = r1_in[i] & mask
            r2_out[i] = r2_in[i] & mask
            r3_out[i] = r3_in[i] & mask
            if (r0_out[i] != r0_in[i] or r1_out[i] != r1_in[i] or
                    r2_out[i] != r2_in[i] or r3_out[i] != r3_in[i]):
                changed = True
            if (r0_out[i] | r1_out[i] | r2_out[i] | r3_out[i]) == 0:
                deadend = True

    return r0_out, r1_out, r2_out, r3_out, changed, deadend

def pack(arr):
    val = 0
    for i in range(N):
        val |= (arr[i] & ALL) << (i * N)
    return val

def unpack(val):
    return [(val >> (i * N)) & ALL for i in range(N)]

async def apply(dut, r0, r1, r2, r3, vim):
    dut.r0_in.value = pack(r0)
    dut.r1_in.value = pack(r1)
    dut.r2_in.value = pack(r2)
    dut.r3_in.value = pack(r3)
    dut.variablesIncludedMask.value = vim
    await Timer(1, unit="ns")

async def check(dut, r0, r1, r2, r3, vim):
    await apply(dut, r0, r1, r2, r3, vim)
    exp_r0, exp_r1, exp_r2, exp_r3, exp_changed, exp_deadend = \
        reference(r0, r1, r2, r3, vim)

    act_r0 = unpack(dut.r0_out.value.to_unsigned())
    act_r1 = unpack(dut.r1_out.value.to_unsigned())
    act_r2 = unpack(dut.r2_out.value.to_unsigned())
    act_r3 = unpack(dut.r3_out.value.to_unsigned())

    for i in range(N):
        assert act_r0[i] == exp_r0[i], f"r0[{i}]={act_r0[i]:04b} exp={exp_r0[i]:04b}"
        assert act_r1[i] == exp_r1[i], f"r1[{i}]={act_r1[i]:04b} exp={exp_r1[i]:04b}"
        assert act_r2[i] == exp_r2[i], f"r2[{i}]={act_r2[i]:04b} exp={exp_r2[i]:04b}"
        assert act_r3[i] == exp_r3[i], f"r3[{i}]={act_r3[i]:04b} exp={exp_r3[i]:04b}"

    assert dut.changed.value == int(exp_changed), \
        f"changed={dut.changed.value} exp={int(exp_changed)}"
    assert dut.deadend.value == int(exp_deadend), \
        f"deadend={dut.deadend.value} exp={int(exp_deadend)}"

@cocotb.test()
async def test_no_singletons(dut):
    """All active — no tiles taken, domains unchanged."""
    r = [ALL] * N
    await check(dut, r, r, r, r, ALL)
    assert dut.changed.value == 0
    assert dut.deadend.value == 0
    cocotb.log.info("no singletons ✓")

@cocotb.test()
async def test_singleton_removes_tile(dut):
    """Singleton var removes its tile from active domains."""
    r0 = [0b0001] * N  # var 0 singleton has tile 0
    r1 = [0] * N
    r2 = [0] * N
    r3 = [0] * N
    # active vars have tile 0 in domain
    for i in range(1, N):
        r0[i] = ALL
    vim = ALL & ~1  # var 0 is singleton
    await check(dut, r0, r1, r2, r3, vim)
    act_r0 = unpack(dut.r0_out.value.to_unsigned())
    for i in range(1, N):
        assert (act_r0[i] & 1) == 0, f"tile 0 should be cleared from var {i}"
    cocotb.log.info("singleton removes tile ✓")

@cocotb.test()
async def test_deadend_when_all_tiles_taken(dut):
    """All tiles taken by singletons — active vars deadend."""
    r0 = [ALL] * N
    r1 = [0] * N
    r2 = [0] * N
    r3 = [0] * N
    # var 0 inactive with all tiles
    vim = ALL & ~1
    await check(dut, r0, r1, r2, r3, vim)
    assert dut.deadend.value == 1
    cocotb.log.info("deadend when all tiles taken ✓")

@cocotb.test()
async def test_consistent_with_components(dut):
    """Driver output matches combined CalculateTilesTaken + AllDifferent."""
    r0 = [0b1010, 0b0101, 0b1100, 0b0011]
    r1 = [0b0001, 0b0010, 0b0100, 0b1000]
    r2 = [0] * N
    r3 = [0] * N
    vim = 0b1100  # vars 0,1 are singletons
    await check(dut, r0, r1, r2, r3, vim)
    cocotb.log.info("consistent with components ✓")

@cocotb.test()
async def test_random(dut):
    """100 random inputs verified against reference."""
    random.seed(42)
    for _ in range(100):
        r0 = [random.randint(0, ALL) for _ in range(N)]
        r1 = [random.randint(0, ALL) for _ in range(N)]
        r2 = [random.randint(0, ALL) for _ in range(N)]
        r3 = [random.randint(0, ALL) for _ in range(N)]
        vim = random.randint(0, ALL)
        await check(dut, r0, r1, r2, r3, vim)
    cocotb.log.info("100 random tests ✓")

def test_AllDifferent_Driver():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/AllDifferent_CalculateTilesTaken.sv",
            "rtl/AllDifferent.sv",
            "rtl/AllDifferent_Driver.sv",
        ],
        hdl_toplevel="AllDifferent_Driver",
        parameters={"N": N},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="AllDifferent_Driver",
        test_module="test_AllDifferent_Driver",
    )