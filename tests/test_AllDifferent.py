import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
VARIABLES = N
ALL = (1 << N) - 1

def reference(r0_in, r1_in, r2_in, r3_in, vim, tiles_taken):
    mask = (~tiles_taken) & ALL
    r0_out = list(r0_in)
    r1_out = list(r1_in)
    r2_out = list(r2_in)
    r3_out = list(r3_in)
    changed = False
    deadend = False

    for i in range(VARIABLES):
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
    for i in range(VARIABLES):
        val |= (arr[i] & ALL) << (i * N)
    return val

def unpack(val):
    return [(val >> (i * N)) & ALL for i in range(VARIABLES)]

async def apply(dut, r0, r1, r2, r3, vim, tiles_taken):
    dut.r0_in.value = pack(r0)
    dut.r1_in.value = pack(r1)
    dut.r2_in.value = pack(r2)
    dut.r3_in.value = pack(r3)
    dut.variablesIncludedMask.value = vim
    dut.tilesTaken.value = tiles_taken
    await Timer(1, unit="ns")

async def check(dut, r0, r1, r2, r3, vim, tiles_taken):
    await apply(dut, r0, r1, r2, r3, vim, tiles_taken)
    exp_r0, exp_r1, exp_r2, exp_r3, exp_changed, exp_deadend = \
        reference(r0, r1, r2, r3, vim, tiles_taken)

    act_r0 = unpack(dut.r0_out.value.to_unsigned())
    act_r1 = unpack(dut.r1_out.value.to_unsigned())
    act_r2 = unpack(dut.r2_out.value.to_unsigned())
    act_r3 = unpack(dut.r3_out.value.to_unsigned())

    for i in range(VARIABLES):
        assert act_r0[i] == exp_r0[i], f"r0[{i}]={act_r0[i]:04b} exp={exp_r0[i]:04b}"
        assert act_r1[i] == exp_r1[i], f"r1[{i}]={act_r1[i]:04b} exp={exp_r1[i]:04b}"
        assert act_r2[i] == exp_r2[i], f"r2[{i}]={act_r2[i]:04b} exp={exp_r2[i]:04b}"
        assert act_r3[i] == exp_r3[i], f"r3[{i}]={act_r3[i]:04b} exp={exp_r3[i]:04b}"

    assert dut.changed.value == int(exp_changed), \
        f"changed={dut.changed.value} exp={int(exp_changed)}"
    assert dut.deadend.value == int(exp_deadend), \
        f"deadend={dut.deadend.value} exp={int(exp_deadend)}"

@cocotb.test()
async def test_no_tiles_taken(dut):
    """No tiles taken — domains unchanged, no change."""
    r = [ALL] * VARIABLES
    await check(dut, r, r, r, r, ALL, 0)
    assert dut.changed.value == 0
    assert dut.deadend.value == 0
    cocotb.log.info("no tiles taken ✓")

@cocotb.test()
async def test_all_tiles_taken(dut):
    """All tiles taken — all active domains go to zero — deadend."""
    r = [ALL] * VARIABLES
    await check(dut, r, r, r, r, ALL, ALL)
    assert dut.deadend.value == 1
    cocotb.log.info("all tiles taken → deadend ✓")

@cocotb.test()
async def test_inactive_variable_unchanged(dut):
    """Variables not in mask are passed through unchanged."""
    r = [ALL] * VARIABLES
    vim = ALL & ~1  # var 0 inactive
    await check(dut, r, r, r, r, vim, ALL)
    act_r0 = unpack(dut.r0_out.value.to_unsigned())
    assert act_r0[0] == ALL, "inactive var 0 should be unchanged"
    cocotb.log.info("inactive variable unchanged ✓")

@cocotb.test()
async def test_partial_tiles_taken(dut):
    """Some tiles taken — only those bits cleared from active domains."""
    r = [ALL] * VARIABLES
    tiles_taken = 0b0101
    await check(dut, r, r, r, r, ALL, tiles_taken)
    cocotb.log.info("partial tiles taken ✓")

@cocotb.test()
async def test_changed_detected(dut):
    """changed=1 when mask removes bits from active domain."""
    r = [ALL] * VARIABLES
    await check(dut, r, r, r, r, ALL, 0b0001)
    assert dut.changed.value == 1
    cocotb.log.info("changed detected ✓")

@cocotb.test()
async def test_no_change_when_already_clear(dut):
    """changed=0 when taken tiles already absent from domain."""
    r = [0b1010] * VARIABLES  # bits 0,2 already clear
    tiles_taken = 0b0101       # taking bits 0,2 — no effect
    await check(dut, r, r, r, r, ALL, tiles_taken)
    assert dut.changed.value == 0
    cocotb.log.info("no change when already clear ✓")

@cocotb.test()
async def test_random(dut):
    """100 random inputs verified against reference."""
    random.seed(42)
    for _ in range(100):
        r0 = [random.randint(0, ALL) for _ in range(VARIABLES)]
        r1 = [random.randint(0, ALL) for _ in range(VARIABLES)]
        r2 = [random.randint(0, ALL) for _ in range(VARIABLES)]
        r3 = [random.randint(0, ALL) for _ in range(VARIABLES)]
        vim = random.randint(0, ALL)
        tiles_taken = random.randint(0, ALL)
        await check(dut, r0, r1, r2, r3, vim, tiles_taken)
    cocotb.log.info("100 random tests ✓")

def test_AllDifferent():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/AllDifferent.sv"],
        hdl_toplevel="AllDifferent",
        parameters={"N": N},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="AllDifferent",
        test_module="test_AllDifferent",
    )