import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
V = N * N
ALL = (1 << V) - 1

def pack(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL) << (i * V)
    return val

def unpack(val):
    return [(val >> (i * V)) & ALL for i in range(V)]

def reference(in_r0, in_r1, in_r2, in_r3, in_uv, in_ut):
    out_r0 = list(in_r0)
    out_r1 = list(in_r1)
    out_r2 = list(in_r2)
    out_r3 = list(in_r3)
    changed = False
    deadend = False
    for i in range(V):
        if (in_uv >> i) & 1:
            out_r0[i] = in_r0[i] & in_ut
            out_r1[i] = in_r1[i] & in_ut
            out_r2[i] = in_r2[i] & in_ut
            out_r3[i] = in_r3[i] & in_ut
            if (out_r0[i] != in_r0[i] or out_r1[i] != in_r1[i] or
                out_r2[i] != in_r2[i] or out_r3[i] != in_r3[i]):
                changed = True
            if (out_r0[i] | out_r1[i] | out_r2[i] | out_r3[i]) == 0:
                deadend = True
    return out_r0, out_r1, out_r2, out_r3, changed, deadend

async def apply(dut, in_r0, in_r1, in_r2, in_r3, in_uv, in_ut):
    dut.in_domain_r0.value           = pack(in_r0)
    dut.in_domain_r1.value           = pack(in_r1)
    dut.in_domain_r2.value           = pack(in_r2)
    dut.in_domain_r3.value           = pack(in_r3)
    dut.in_unassignedVariables.value = in_uv
    dut.in_unassignedTiles.value     = in_ut
    await Timer(1, unit="ns")

async def check(dut, in_r0, in_r1, in_r2, in_r3, in_uv, in_ut):
    await apply(dut, in_r0, in_r1, in_r2, in_r3, in_uv, in_ut)
    exp_r0, exp_r1, exp_r2, exp_r3, exp_ch, exp_de = \
        reference(in_r0, in_r1, in_r2, in_r3, in_uv, in_ut)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack(dut.out_domain_r3.value.to_unsigned())
    for i in range(V):
        assert act_r0[i] == exp_r0[i], f"r0[{i}]={act_r0[i]:#x} exp={exp_r0[i]:#x}"
        assert act_r1[i] == exp_r1[i], f"r1[{i}]={act_r1[i]:#x} exp={exp_r1[i]:#x}"
        assert act_r2[i] == exp_r2[i], f"r2[{i}]={act_r2[i]:#x} exp={exp_r2[i]:#x}"
        assert act_r3[i] == exp_r3[i], f"r3[{i}]={act_r3[i]:#x} exp={exp_r3[i]:#x}"
    assert dut.out_changed.value == int(exp_ch), \
        f"changed={dut.out_changed.value} exp={int(exp_ch)}"
    assert dut.out_deadend.value == int(exp_de), \
        f"deadend={dut.out_deadend.value} exp={int(exp_de)}"

def make_full():
    return [ALL] * V

@cocotb.test()
async def test_no_tiles_taken(dut):
    """All tiles unassigned — domains unchanged, no change, no deadend."""
    r = make_full()
    await check(dut, r, r, r, r, ALL, ALL)
    assert dut.out_changed.value == 0
    assert dut.out_deadend.value == 0
    cocotb.log.info("no tiles taken ✓")

@cocotb.test()
async def test_tile_removed_from_domain(dut):
    """Tile 0 taken — removed from all active variable domains."""
    r = make_full()
    in_ut = ALL & ~1
    await check(dut, r, r, r, r, ALL, in_ut)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    for i in range(V):
        assert not (act_r0[i] & 1), f"tile 0 should be removed from var {i}"
    assert dut.out_changed.value == 1
    cocotb.log.info("tile removed from domain ✓")

@cocotb.test()
async def test_inactive_variable_unchanged(dut):
    """Inactive variable domain not masked."""
    r = make_full()
    in_ut = ALL & ~1
    in_uv = ALL & ~1
    await check(dut, r, r, r, r, in_uv, in_ut)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    assert act_r0[0] == ALL, "inactive var 0 should be unchanged"
    cocotb.log.info("inactive variable unchanged ✓")

@cocotb.test()
async def test_deadend(dut):
    """All tiles taken for active variable — deadend."""
    r0 = [0] * V
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    r0[0] = 0b0001
    for i in range(1, V):
        r0[i] = ALL
    in_ut = ALL & ~1
    await check(dut, r0, r1, r2, r3, ALL, in_ut)
    assert dut.out_deadend.value == 1
    cocotb.log.info("deadend ✓")

@cocotb.test()
async def test_no_change_when_tiles_not_in_domain(dut):
    """Taken tile not in domain — no change."""
    r0 = [ALL & ~1] * V
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    in_ut = ALL & ~1
    await check(dut, r0, r1, r2, r3, ALL, in_ut)
    assert dut.out_changed.value == 0
    assert dut.out_deadend.value == 0
    cocotb.log.info("no change when tile not in domain ✓")

@cocotb.test()
async def test_all_variables_inactive(dut):
    """No active variables — nothing changes."""
    r = make_full()
    await check(dut, r, r, r, r, 0, ALL & ~1)
    assert dut.out_changed.value == 0
    assert dut.out_deadend.value == 0
    cocotb.log.info("all inactive ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(77)
    for _ in range(50):
        in_uv = random.randint(0, ALL)
        in_ut = random.randint(0, ALL)
        r0 = [random.randint(0, ALL) for _ in range(V)]
        r1 = [random.randint(0, ALL) for _ in range(V)]
        r2 = [random.randint(0, ALL) for _ in range(V)]
        r3 = [random.randint(0, ALL) for _ in range(V)]
        await check(dut, r0, r1, r2, r3, in_uv, in_ut)
    cocotb.log.info("50 random tests ✓")

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