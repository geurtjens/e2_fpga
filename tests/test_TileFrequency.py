import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
VARIABLES = N * N
ITERATIONS = 2
ALL = (1 << VARIABLES) - 1

def popcount(x): return bin(x).count('1')

def reference_stage(vim, unassigned_tiles, r0, r1, r2, r3):
    """One pass of TileFrequency."""
    out_r0 = list(r0)
    out_r1 = list(r1)
    out_r2 = list(r2)
    out_r3 = list(r3)

    for t in range(VARIABLES):
        if not (unassigned_tiles >> t) & 1:
            continue
        count = 0
        forced_v = -1
        for v in range(VARIABLES):
            if not (vim >> v) & 1:
                continue
            combined = r0[v] | r1[v] | r2[v] | r3[v]
            if (combined >> t) & 1:
                count += 1
                forced_v = v
        if count == 1:
            forced_mask = 1 << t
            out_r0[forced_v] = r0[forced_v] & forced_mask
            out_r1[forced_v] = r1[forced_v] & forced_mask
            out_r2[forced_v] = r2[forced_v] & forced_mask
            out_r3[forced_v] = r3[forced_v] & forced_mask

    return out_r0, out_r1, out_r2, out_r3

def reference(vim, unassigned_tiles, r0, r1, r2, r3, iterations=ITERATIONS):
    """Run ITERATIONS passes then check deadend."""
    cr0, cr1, cr2, cr3 = list(r0), list(r1), list(r2), list(r3)
    for _ in range(iterations):
        cr0, cr1, cr2, cr3 = reference_stage(vim, unassigned_tiles, cr0, cr1, cr2, cr3)

    # deadend check on final output
    deadend = False
    for t in range(VARIABLES):
        if not (unassigned_tiles >> t) & 1:
            continue
        cnt = 0
        for v in range(VARIABLES):
            if not (vim >> v) & 1:
                continue
            combined = cr0[v] | cr1[v] | cr2[v] | cr3[v]
            if (combined >> t) & 1:
                cnt += 1
        if cnt == 0:
            deadend = True

    if popcount(unassigned_tiles) != popcount(vim):
        deadend = True

    return cr0, cr1, cr2, cr3, deadend

def pack(arr):
    val = 0
    for i in range(VARIABLES):
        val |= (arr[i] & ALL) << (i * VARIABLES)
    return val

def unpack(val):
    return [(val >> (i * VARIABLES)) & ALL for i in range(VARIABLES)]

async def apply(dut, vim, unassigned_tiles, r0, r1, r2, r3):
    dut.in_variablesIncludedMask.value = vim
    dut.in_unassignedTiles.value       = unassigned_tiles
    dut.in_r0.value = pack(r0)
    dut.in_r1.value = pack(r1)
    dut.in_r2.value = pack(r2)
    dut.in_r3.value = pack(r3)
    await Timer(1, unit="ns")

async def check(dut, vim, unassigned_tiles, r0, r1, r2, r3):
    await apply(dut, vim, unassigned_tiles, r0, r1, r2, r3)
    exp_r0, exp_r1, exp_r2, exp_r3, exp_de = \
        reference(vim, unassigned_tiles, r0, r1, r2, r3)

    act_r0 = unpack(dut.out_r0.value.to_unsigned())
    act_r1 = unpack(dut.out_r1.value.to_unsigned())
    act_r2 = unpack(dut.out_r2.value.to_unsigned())
    act_r3 = unpack(dut.out_r3.value.to_unsigned())

    for v in range(VARIABLES):
        assert act_r0[v] == exp_r0[v], f"r0[{v}]={act_r0[v]:#x} exp={exp_r0[v]:#x}"
        assert act_r1[v] == exp_r1[v], f"r1[{v}]={act_r1[v]:#x} exp={exp_r1[v]:#x}"
        assert act_r2[v] == exp_r2[v], f"r2[{v}]={act_r2[v]:#x} exp={exp_r2[v]:#x}"
        assert act_r3[v] == exp_r3[v], f"r3[{v}]={act_r3[v]:#x} exp={exp_r3[v]:#x}"

    assert dut.deadend.value == int(exp_de), \
        f"deadend={dut.deadend.value} exp={int(exp_de)}"

@cocotb.test()
async def test_no_forced_tiles(dut):
    """All tiles available in all variables — no forcing."""
    r = [ALL] * VARIABLES
    await check(dut, ALL, ALL, r, r, r, r)
    assert dut.deadend.value == 0
    cocotb.log.info("no forced tiles ✓")

@cocotb.test()
async def test_tile_forced_to_one_variable(dut):
    """Tile 0 only available in variable 0 — var 0 forced to tile 0."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    # only var 0 has tile 0
    r0[0] = 1 << 0
    # all other vars have tiles 1..15 but not tile 0
    for v in range(1, VARIABLES):
        r0[v] = ALL & ~1
    await check(dut, ALL, ALL, r0, r1, r2, r3)
    act_r0 = unpack(dut.out_r0.value.to_unsigned())
    assert act_r0[0] == (1 << 0), f"var 0 should be forced to tile 0"
    assert dut.deadend.value == 0
    cocotb.log.info("tile forced to one variable ✓")

@cocotb.test()
async def test_tile_has_no_variable_deadend(dut):
    """Tile 0 available nowhere — deadend."""
    r0 = [ALL & ~1] * VARIABLES  # all vars missing tile 0
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    await check(dut, ALL, ALL, r0, r1, r2, r3)
    assert dut.deadend.value == 1
    cocotb.log.info("tile with no variable → deadend ✓")

@cocotb.test()
async def test_inactive_tile_ignored(dut):
    """Tile not in unassignedTiles is ignored even if count=0."""
    r0 = [ALL & ~1] * VARIABLES  # tile 0 missing from all domains
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    # tile 0 not unassigned AND var 0 not active — popcounts match
    unassigned_tiles = ALL & ~1  # 15 tiles
    vim = ALL & ~1               # 15 active variables
    await check(dut, vim, unassigned_tiles, r0, r1, r2, r3)
    assert dut.deadend.value == 0
    cocotb.log.info("inactive tile ignored ✓")

@cocotb.test()
async def test_inactive_variable_ignored(dut):
    """Variable not in mask not counted for tile frequency."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    # only var 0 has tile 0, but var 0 is inactive
    r0[0] = 1 << 0
    vim = ALL & ~1  # var 0 inactive
    await check(dut, vim, ALL, r0, r1, r2, r3)
    # tile 0 has count=0 among active vars — deadend
    assert dut.deadend.value == 1
    cocotb.log.info("inactive variable ignored ✓")

@cocotb.test()
async def test_two_stage_propagation(dut):
    """Forcing in stage 1 enables forcing in stage 2."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES

    # tile 0 only in var 0 — stage 1 forces var 0 to tile 0
    # tile 1 only in var 1 and var 0 — after stage 1 var 0 loses tile 1
    # so stage 2 forces var 1 to tile 1
    r0[0] = (1 << 0) | (1 << 1)  # var 0 has tiles 0 and 1
    r0[1] = (1 << 1) | (1 << 2)  # var 1 has tiles 1 and 2
    for v in range(2, VARIABLES):
        r0[v] = ALL & ~1 & ~2    # others have tiles 2..15

    await check(dut, ALL, ALL, r0, r1, r2, r3)
    cocotb.log.info("two stage propagation ✓")

@cocotb.test()
async def test_popcount_deadend(dut):
    """popcount(unassignedTiles) != popcount(vim) → deadend."""
    r = [ALL] * VARIABLES
    vim = ALL & ~1  # 15 active variables
    unassigned_tiles = ALL  # 16 unassigned tiles
    # mismatch → deadend
    await check(dut, vim, unassigned_tiles, r, r, r, r)
    assert dut.deadend.value == 1
    cocotb.log.info("popcount mismatch → deadend ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(88)
    for _ in range(50):
        vim   = random.randint(0, ALL)
        tiles = random.randint(0, ALL)
        r0 = [random.randint(0, ALL) for _ in range(VARIABLES)]
        r1 = [random.randint(0, ALL) for _ in range(VARIABLES)]
        r2 = [random.randint(0, ALL) for _ in range(VARIABLES)]
        r3 = [random.randint(0, ALL) for _ in range(VARIABLES)]
        await check(dut, vim, tiles, r0, r1, r2, r3)
    cocotb.log.info("50 random tests ✓")

def test_TileFrequency():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/TileFrequencySingle.sv","rtl/TileFrequency.sv"],
        hdl_toplevel="TileFrequency",
        parameters={"N": N, "ITERATIONS": ITERATIONS},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNOPTFLAT"],
    )
    runner.test(
        hdl_toplevel="TileFrequency",
        test_module="test_TileFrequency",
    )