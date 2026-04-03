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

def reference(in_vim, in_ut, in_r0, in_r1, in_r2, in_r3):
    out_vim = in_vim
    out_ut  = in_ut
    out_r0  = list(in_r0)
    out_r1  = list(in_r1)
    out_r2  = list(in_r2)
    out_r3  = list(in_r3)
    singleton_found = False

    for v in range(VARIABLES):
        if (in_vim >> v) & 1:
            combined = in_r0[v] | in_r1[v] | in_r2[v] | in_r3[v]
            if popcount(combined) == 1:
                singleton_found = True
                # find tile id
                tile_id = combined.bit_length() - 1
                # find rotation
                if in_r0[v] != 0:   rot = 0
                elif in_r1[v] != 0: rot = 1
                elif in_r2[v] != 0: rot = 2
                else:                rot = 3
                # lock domain
                out_r0[v] = combined if rot == 0 else 0
                out_r1[v] = combined if rot == 1 else 0
                out_r2[v] = combined if rot == 2 else 0
                out_r3[v] = combined if rot == 3 else 0
                # remove variable and tile
                out_vim &= ~(1 << v)
                out_ut  &= ~(1 << tile_id)

    deadend = popcount(out_vim) != popcount(out_ut)
    return out_vim, out_ut, out_r0, out_r1, out_r2, out_r3, singleton_found, deadend

def pack_domain_array(arr):
    val = 0
    for i in range(VARIABLES):
        val |= (arr[i] & ALL_VARS) << (i * VARIABLES)
    return val

def unpack_domain_array(val):
    return [(val >> (i * VARIABLES)) & ALL_VARS for i in range(VARIABLES)]

async def apply(dut, in_vim, in_ut, in_r0, in_r1, in_r2, in_r3):
    dut.in_variablesIncludedMask.value = in_vim
    dut.in_unassignedTiles.value       = in_ut
    dut.in_r0.value = pack_domain_array(in_r0)
    dut.in_r1.value = pack_domain_array(in_r1)
    dut.in_r2.value = pack_domain_array(in_r2)
    dut.in_r3.value = pack_domain_array(in_r3)
    await Timer(1, unit="ns")

async def check(dut, in_vim, in_ut, in_r0, in_r1, in_r2, in_r3):
    await apply(dut, in_vim, in_ut, in_r0, in_r1, in_r2, in_r3)
    exp_vim, exp_ut, exp_r0, exp_r1, exp_r2, exp_r3, exp_sf, exp_de = \
        reference(in_vim, in_ut, in_r0, in_r1, in_r2, in_r3)

    act_r0 = unpack_domain_array(dut.out_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_r3.value.to_unsigned())

    assert dut.out_variablesIncludedMask.value == exp_vim, \
        f"vim={dut.out_variablesIncludedMask.value:016b} expected={exp_vim:016b}"
    assert dut.out_unassignedTiles.value == exp_ut, \
        f"ut={dut.out_unassignedTiles.value:016b} expected={exp_ut:016b}"
    assert dut.singleton_found.value == int(exp_sf), \
        f"singleton_found={dut.singleton_found.value} expected={int(exp_sf)}"
    assert dut.deadend.value == int(exp_de), \
        f"deadend={dut.deadend.value} expected={int(exp_de)}"

    for v in range(VARIABLES):
        assert act_r0[v] == exp_r0[v], f"r0[{v}]={act_r0[v]:016b} expected={exp_r0[v]:016b}"
        assert act_r1[v] == exp_r1[v], f"r1[{v}]={act_r1[v]:016b} expected={exp_r1[v]:016b}"
        assert act_r2[v] == exp_r2[v], f"r2[{v}]={act_r2[v]:016b} expected={exp_r2[v]:016b}"
        assert act_r3[v] == exp_r3[v], f"r3[{v}]={act_r3[v]:016b} expected={exp_r3[v]:016b}"

@cocotb.test()
async def test_no_singletons(dut):
    """No variables with single piece — nothing changes."""
    r = [0b11 for _ in range(VARIABLES)]  # all have 2 pieces
    await check(dut, ALL_VARS, ALL_TILES, r, r, r, r)
    assert dut.singleton_found.value == 0
    assert dut.deadend.value == 0
    cocotb.log.info("no singletons ✓")

@cocotb.test()
async def test_single_singleton_r0(dut):
    """Variable 0 has exactly one piece in r0 — gets locked."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    r0[0] = 1 << 5   # piece 5 in rotation 0
    # all others have 2 pieces
    for v in range(1, VARIABLES):
        r0[v] = 0b11
    await check(dut, ALL_VARS, ALL_TILES, r0, r1, r2, r3)
    assert dut.singleton_found.value == 1
    assert dut.deadend.value == 0
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
    r2[3] = 1 << 7  # piece 7 in rotation 2
    r3[3] = 0
    await check(dut, ALL_VARS, ALL_TILES, r0, r1, r2, r3)
    assert dut.singleton_found.value == 1
    cocotb.log.info("singleton in r2 ✓")

@cocotb.test()
async def test_multiple_singletons(dut):
    """Multiple variables each have one piece — all locked."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    # var 0 → piece 0 in r0, var 1 → piece 1 in r1
    r0[0] = 1 << 0
    r1[1] = 1 << 1
    # rest have 2 pieces
    for v in range(2, VARIABLES):
        r0[v] = 0b11
    await check(dut, ALL_VARS, ALL_TILES, r0, r1, r2, r3)
    assert dut.singleton_found.value == 1
    cocotb.log.info("multiple singletons ✓")

@cocotb.test()
async def test_deadend_same_tile(dut):
    """Two variables forced to same tile — deadend."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    # both var 0 and var 1 have only piece 5
    r0[0] = 1 << 5
    r0[1] = 1 << 5
    for v in range(2, VARIABLES):
        r0[v] = 0b11
    await check(dut, ALL_VARS, ALL_TILES, r0, r1, r2, r3)
    assert dut.deadend.value == 1
    cocotb.log.info("deadend — same tile ✓")

@cocotb.test()
async def test_inactive_variable_ignored(dut):
    """Variable not in mask is ignored even if singleton."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    r0[0] = 1 << 3  # singleton but var 0 not in mask
    for v in range(1, VARIABLES):
        r0[v] = 0b11
    vim = ALL_VARS & ~1  # exclude var 0
    await check(dut, vim, ALL_TILES, r0, r1, r2, r3)
    assert dut.singleton_found.value == 0
    cocotb.log.info("inactive variable ignored ✓")

@cocotb.test()
async def test_all_singletons_unique(dut):
    """Every variable has a unique singleton — all locked, no deadend."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    for v in range(VARIABLES):
        r0[v] = 1 << v  # each variable has unique piece
    await check(dut, ALL_VARS, ALL_TILES, r0, r1, r2, r3)
    assert dut.singleton_found.value == 1
    assert dut.deadend.value == 0
    cocotb.log.info("all unique singletons ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against Python reference."""
    random.seed(99)
    for _ in range(50):
        vim = random.randint(0, ALL_VARS)
        ut  = random.randint(0, ALL_TILES)
        r0  = [random.randint(0, ALL_VARS) for _ in range(VARIABLES)]
        r1  = [random.randint(0, ALL_VARS) for _ in range(VARIABLES)]
        r2  = [random.randint(0, ALL_VARS) for _ in range(VARIABLES)]
        r3  = [random.randint(0, ALL_VARS) for _ in range(VARIABLES)]
        await check(dut, vim, ut, r0, r1, r2, r3)
    cocotb.log.info("50 random tests passed ✓")

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