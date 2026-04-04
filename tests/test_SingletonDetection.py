import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
VARIABLES = N * N
ALL_VARS = (1 << VARIABLES) - 1
ALL_TILES = (1 << VARIABLES) - 1

def popcount(x):
    return bin(x).count('1')

def reference(in_uv, in_ut, in_r0, in_r1, in_r2, in_r3):
    out_uv = in_uv
    out_ut = in_ut
    out_r0 = list(in_r0)
    out_r1 = list(in_r1)
    out_r2 = list(in_r2)
    out_r3 = list(in_r3)
    singleton_found = False

    for v in range(VARIABLES):
        if (in_uv >> v) & 1:
            combined = in_r0[v] | in_r1[v] | in_r2[v] | in_r3[v]
            if combined != 0 and (combined & (combined - 1)) == 0:
                singleton_found = True
                tile_id = combined.bit_length() - 1
                if in_r0[v] != 0:   rot = 0
                elif in_r1[v] != 0: rot = 1
                elif in_r2[v] != 0: rot = 2
                else:                rot = 3
                out_r0[v] = combined if rot == 0 else 0
                out_r1[v] = combined if rot == 1 else 0
                out_r2[v] = combined if rot == 2 else 0
                out_r3[v] = combined if rot == 3 else 0
                out_uv &= ~(1 << v)
                out_ut &= ~(1 << tile_id)

    deadend = popcount(out_uv) != popcount(out_ut)
    return out_uv, out_ut, out_r0, out_r1, out_r2, out_r3, singleton_found, deadend

def pack_domain_array(arr):
    val = 0
    for i in range(VARIABLES):
        val |= (arr[i] & ALL_VARS) << (i * VARIABLES)
    return val

def unpack_domain_array(val):
    return [(val >> (i * VARIABLES)) & ALL_VARS for i in range(VARIABLES)]

async def apply(dut, in_uv, in_ut, in_r0, in_r1, in_r2, in_r3):
    dut.in_unassignedVariables.value = in_uv
    dut.in_unassignedTiles.value     = in_ut
    dut.in_r0.value = pack_domain_array(in_r0)
    dut.in_r1.value = pack_domain_array(in_r1)
    dut.in_r2.value = pack_domain_array(in_r2)
    dut.in_r3.value = pack_domain_array(in_r3)
    await Timer(1, unit="ns")

async def check(dut, in_uv, in_ut, in_r0, in_r1, in_r2, in_r3):
    await apply(dut, in_uv, in_ut, in_r0, in_r1, in_r2, in_r3)
    exp_uv, exp_ut, exp_r0, exp_r1, exp_r2, exp_r3, exp_sf, exp_de = \
        reference(in_uv, in_ut, in_r0, in_r1, in_r2, in_r3)

    act_r0 = unpack_domain_array(dut.out_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_r3.value.to_unsigned())

    assert dut.out_unassignedVariables.value == exp_uv, \
        f"unassignedVariables={dut.out_unassignedVariables.value:016b} expected={exp_uv:016b}"
    assert dut.out_unassignedTiles.value == exp_ut, \
        f"unassignedTiles={dut.out_unassignedTiles.value:016b} expected={exp_ut:016b}"
    assert dut.out_singleton.value == int(exp_sf), \
        f"out_singleton={dut.out_singleton.value} expected={int(exp_sf)}"
    assert dut.out_deadend.value == int(exp_de), \
        f"out_deadend={dut.out_deadend.value} expected={int(exp_de)}"

    for v in range(VARIABLES):
        assert act_r0[v] == exp_r0[v], f"r0[{v}]={act_r0[v]:016b} expected={exp_r0[v]:016b}"
        assert act_r1[v] == exp_r1[v], f"r1[{v}]={act_r1[v]:016b} expected={exp_r1[v]:016b}"
        assert act_r2[v] == exp_r2[v], f"r2[{v}]={act_r2[v]:016b} expected={exp_r2[v]:016b}"
        assert act_r3[v] == exp_r3[v], f"r3[{v}]={act_r3[v]:016b} expected={exp_r3[v]:016b}"

@cocotb.test()
async def test_no_singletons(dut):
    """No variables with single piece — nothing changes."""
    r = [0b11 for _ in range(VARIABLES)]
    await check(dut, ALL_VARS, ALL_TILES, r, r, r, r)
    assert dut.out_singleton.value == 0
    assert dut.out_deadend.value == 0
    cocotb.log.info("no singletons ✓")

@cocotb.test()
async def test_single_singleton_r0(dut):
    """Variable 0 has exactly one piece in r0 — gets locked."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    r0[0] = 1 << 5
    for v in range(1, VARIABLES):
        r0[v] = 0b11
    await check(dut, ALL_VARS, ALL_TILES, r0, r1, r2, r3)
    assert dut.out_singleton.value == 1
    assert dut.out_deadend.value == 0
    cocotb.log.info("singleton in r0 ✓")

@cocotb.test()
async def test_singleton_r2(dut):
    """Variable 3 has exactly one piece in r2 — gets locked."""
    r0 = [0b11] * VARIABLES
    r1 = [0b11] * VARIABLES
    r2 = [0b11] * VARIABLES
    r3 = [0b11] * VARIABLES
    r0[3] = 0
    r1[3] = 0
    r2[3] = 1 << 7
    r3[3] = 0
    await check(dut, ALL_VARS, ALL_TILES, r0, r1, r2, r3)
    assert dut.out_singleton.value == 1
    cocotb.log.info("singleton in r2 ✓")

@cocotb.test()
async def test_multiple_singletons(dut):
    """Multiple variables each have one piece — all locked."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    r0[0] = 1 << 0
    r1[1] = 1 << 1
    for v in range(2, VARIABLES):
        r0[v] = 0b11
    await check(dut, ALL_VARS, ALL_TILES, r0, r1, r2, r3)
    assert dut.out_singleton.value == 1
    cocotb.log.info("multiple singletons ✓")

@cocotb.test()
async def test_deadend_same_tile(dut):
    """Two variables forced to same tile — deadend."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    r0[0] = 1 << 5
    r0[1] = 1 << 5
    for v in range(2, VARIABLES):
        r0[v] = 0b11
    await check(dut, ALL_VARS, ALL_TILES, r0, r1, r2, r3)
    assert dut.out_deadend.value == 1
    cocotb.log.info("deadend — same tile ✓")

@cocotb.test()
async def test_inactive_variable_ignored(dut):
    """Variable not in mask is ignored even if singleton."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    r0[0] = 1 << 3
    for v in range(1, VARIABLES):
        r0[v] = 0b11
    uv = ALL_VARS & ~1
    await check(dut, uv, ALL_TILES, r0, r1, r2, r3)
    assert dut.out_singleton.value == 0
    cocotb.log.info("inactive variable ignored ✓")

@cocotb.test()
async def test_all_singletons_unique(dut):
    """Every variable has a unique singleton — all locked, no deadend."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    for v in range(VARIABLES):
        r0[v] = 1 << v
    await check(dut, ALL_VARS, ALL_TILES, r0, r1, r2, r3)
    assert dut.out_singleton.value == 1
    assert dut.out_deadend.value == 0
    cocotb.log.info("all unique singletons ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(99)
    for _ in range(50):
        uv = random.randint(0, ALL_VARS)
        ut = random.randint(0, ALL_TILES)
        r0 = [random.randint(0, ALL_VARS) for _ in range(VARIABLES)]
        r1 = [random.randint(0, ALL_VARS) for _ in range(VARIABLES)]
        r2 = [random.randint(0, ALL_VARS) for _ in range(VARIABLES)]
        r3 = [random.randint(0, ALL_VARS) for _ in range(VARIABLES)]
        await check(dut, uv, ut, r0, r1, r2, r3)
    cocotb.log.info("50 random tests ✓")

def test_SingletonDetection():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/SingletonDetection.sv"],
        hdl_toplevel="SingletonDetection",
        parameters={"N": N},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="SingletonDetection",
        test_module="test_SingletonDetection",
    )