import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N          = 4
V          = N * N
ITERATIONS = 2
ALL        = (1 << V) - 1

def popcount(x): return bin(x).count('1')

def reference_stage(unassigned_variables, unassigned_tiles, r0, r1, r2, r3):
    """One pass of TileFrequency."""
    out_r0 = list(r0)
    out_r1 = list(r1)
    out_r2 = list(r2)
    out_r3 = list(r3)

    for t in range(V):
        if not (unassigned_tiles >> t) & 1:
            continue
        count    = 0
        forced_v = -1
        for v in range(V):
            if not (unassigned_variables >> v) & 1:
                continue
            combined = r0[v] | r1[v] | r2[v] | r3[v]
            if (combined >> t) & 1:
                count   += 1
                forced_v = v
        if count == 1:
            forced_mask    = 1 << t
            out_r0[forced_v] = r0[forced_v] & forced_mask
            out_r1[forced_v] = r1[forced_v] & forced_mask
            out_r2[forced_v] = r2[forced_v] & forced_mask
            out_r3[forced_v] = r3[forced_v] & forced_mask

    return out_r0, out_r1, out_r2, out_r3

def reference(unassigned_variables, unassigned_tiles, r0, r1, r2, r3,
              iterations=ITERATIONS):
    """Run ITERATIONS passes then check deadend."""
    cr0, cr1, cr2, cr3 = list(r0), list(r1), list(r2), list(r3)
    for _ in range(iterations):
        cr0, cr1, cr2, cr3 = reference_stage(
            unassigned_variables, unassigned_tiles, cr0, cr1, cr2, cr3)

    # deadend: any unassigned tile has no active variable that can hold it
    deadend = False
    for t in range(V):
        if not (unassigned_tiles >> t) & 1:
            continue
        cnt = 0
        for v in range(V):
            if not (unassigned_variables >> v) & 1:
                continue
            combined = cr0[v] | cr1[v] | cr2[v] | cr3[v]
            if (combined >> t) & 1:
                cnt += 1
        if cnt == 0:
            deadend = True

    if popcount(unassigned_tiles) != popcount(unassigned_variables):
        deadend = True

    return cr0, cr1, cr2, cr3, deadend

def pack(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL) << (i * V)
    return val

def unpack(val):
    return [(val >> (i * V)) & ALL for i in range(V)]

async def apply(dut, unassigned_variables, unassigned_tiles, r0, r1, r2, r3):
    dut.in_unassigned_variables.value = unassigned_variables
    dut.in_unassigned_tiles.value     = unassigned_tiles
    dut.in_domain_r0.value            = pack(r0)
    dut.in_domain_r1.value            = pack(r1)
    dut.in_domain_r2.value            = pack(r2)
    dut.in_domain_r3.value            = pack(r3)
    await Timer(1, unit="ns")

async def check(dut, unassigned_variables, unassigned_tiles, r0, r1, r2, r3):
    await apply(dut, unassigned_variables, unassigned_tiles, r0, r1, r2, r3)

    exp_r0, exp_r1, exp_r2, exp_r3, exp_de = reference(
        unassigned_variables, unassigned_tiles, r0, r1, r2, r3)

    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack(dut.out_domain_r3.value.to_unsigned())

    for v in range(V):
        assert act_r0[v] == exp_r0[v], f"r0[{v}]={act_r0[v]:#x} exp={exp_r0[v]:#x}"
        assert act_r1[v] == exp_r1[v], f"r1[{v}]={act_r1[v]:#x} exp={exp_r1[v]:#x}"
        assert act_r2[v] == exp_r2[v], f"r2[{v}]={act_r2[v]:#x} exp={exp_r2[v]:#x}"
        assert act_r3[v] == exp_r3[v], f"r3[{v}]={act_r3[v]:#x} exp={exp_r3[v]:#x}"

    assert dut.out_deadend.value == int(exp_de), \
        f"deadend={dut.out_deadend.value} exp={int(exp_de)}"

@cocotb.test()
async def test_no_forced_tiles(dut):
    """All tiles available in all variables — no forcing."""
    r = [ALL] * V
    await check(dut, ALL, ALL, r, r, r, r)
    assert dut.out_deadend.value == 0
    cocotb.log.info("no forced tiles ✓")

@cocotb.test()
async def test_tile_forced_to_one_variable(dut):
    """Tile 0 only available in variable 0 — var 0 forced to tile 0."""
    r0 = [0] * V
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    r0[0] = 1 << 0           # only var 0 has tile 0
    for v in range(1, V):
        r0[v] = ALL & ~1      # all other vars have tiles 1..V-1 but not tile 0
    await check(dut, ALL, ALL, r0, r1, r2, r3)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    assert act_r0[0] == (1 << 0), f"var 0 should be forced to tile 0, got {act_r0[0]:#x}"
    assert dut.out_deadend.value == 0
    cocotb.log.info("tile forced to one variable ✓")

@cocotb.test()
async def test_tile_has_no_variable_deadend(dut):
    """Tile 0 available nowhere among active variables — deadend."""
    r0 = [ALL & ~1] * V  # all vars missing tile 0
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    await check(dut, ALL, ALL, r0, r1, r2, r3)
    assert dut.out_deadend.value == 1
    cocotb.log.info("tile with no variable → deadend ✓")

@cocotb.test()
async def test_inactive_tile_ignored(dut):
    """Tile not in unassigned_tiles is ignored even if count=0."""
    r0 = [ALL & ~1] * V  # tile 0 missing from all domains
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    # tile 0 not unassigned and var 0 not active — popcounts match
    unassigned_tiles      = ALL & ~1  # 15 tiles
    unassigned_variables  = ALL & ~1  # 15 active variables
    await check(dut, unassigned_variables, unassigned_tiles, r0, r1, r2, r3)
    assert dut.out_deadend.value == 0
    cocotb.log.info("inactive tile ignored ✓")

@cocotb.test()
async def test_inactive_variable_ignored(dut):
    """Variable not in unassigned_variables not counted for tile frequency."""
    r0 = [0] * V
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    r0[0] = 1 << 0          # only var 0 has tile 0, but var 0 is inactive
    unassigned_variables = ALL & ~1  # var 0 inactive
    await check(dut, unassigned_variables, ALL, r0, r1, r2, r3)
    # tile 0 has count=0 among active vars — deadend
    assert dut.out_deadend.value == 1
    cocotb.log.info("inactive variable ignored ✓")

@cocotb.test()
async def test_popcount_deadend(dut):
    """popcount(unassigned_tiles) != popcount(unassigned_variables) → deadend."""
    r = [ALL] * V
    unassigned_variables = ALL & ~1  # 15 active variables
    unassigned_tiles     = ALL       # 16 unassigned tiles — mismatch
    await check(dut, unassigned_variables, unassigned_tiles, r, r, r, r)
    assert dut.out_deadend.value == 1
    cocotb.log.info("popcount mismatch → deadend ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(88)
    for _ in range(50):
        unassigned_variables = random.randint(0, ALL)
        unassigned_tiles     = random.randint(0, ALL)
        r0 = [random.randint(0, ALL) for _ in range(V)]
        r1 = [random.randint(0, ALL) for _ in range(V)]
        r2 = [random.randint(0, ALL) for _ in range(V)]
        r3 = [random.randint(0, ALL) for _ in range(V)]
        await check(dut, unassigned_variables, unassigned_tiles, r0, r1, r2, r3)
    cocotb.log.info("50 random tests ✓")

def test_TileFrequency():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/TileFrequency_Single.sv",
            "rtl/TileFrequency.sv",
            "rtl/SingletonAssignment.sv",
        ],
        hdl_toplevel="TileFrequency",
        parameters={"N": N},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNOPTFLAT"],
    )
    runner.test(
        hdl_toplevel="TileFrequency",
        test_module="test_TileFrequency",
    )