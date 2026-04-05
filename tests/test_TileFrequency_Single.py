import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N   = 4
V   = N * N
ALL = (1 << V) - 1

def reference(unassigned_variables, unassigned_tiles, r0, r1, r2, r3):
    """Reference model for TileFrequencySingle.
    For each unassigned tile, count how many unassigned variables
    have it in their combined domain. If exactly one variable can
    hold the tile, force that variable to that tile only."""
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
            forced_mask      = 1 << t
            out_r0[forced_v] = r0[forced_v] & forced_mask
            out_r1[forced_v] = r1[forced_v] & forced_mask
            out_r2[forced_v] = r2[forced_v] & forced_mask
            out_r3[forced_v] = r3[forced_v] & forced_mask

    return out_r0, out_r1, out_r2, out_r3

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

    exp_r0, exp_r1, exp_r2, exp_r3 = reference(
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

@cocotb.test()
async def test_no_forcing(dut):
    """All tiles available in all variables — no forcing, domains unchanged."""
    r = [ALL] * V
    await check(dut, ALL, ALL, r, r, r, r)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    for v in range(V):
        assert act_r0[v] == ALL, f"r0[{v}] should be unchanged"
    cocotb.log.info("no forcing ✓")

@cocotb.test()
async def test_tile_forced_to_one_variable(dut):
    """Tile 0 only available in variable 0 — var 0 forced to tile 0 only."""
    r0 = [ALL & ~1] * V  # all vars have tiles 1..V-1
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    r0[0] = ALL          # var 0 has all tiles including tile 0
    await check(dut, ALL, ALL, r0, r1, r2, r3)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    assert act_r0[0] == 1, f"var 0 should be forced to tile 0 only, got {act_r0[0]:#x}"
    cocotb.log.info("tile forced to one variable ✓")

@cocotb.test()
async def test_tile_in_multiple_variables_not_forced(dut):
    """Tile 0 available in two variables — not forced, domains unchanged."""
    r0 = [ALL & ~1] * V  # all vars have tiles 1..V-1
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    r0[0] = ALL          # var 0 has tile 0
    r0[1] = ALL          # var 1 also has tile 0 — not forced
    await check(dut, ALL, ALL, r0, r1, r2, r3)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    assert act_r0[0] == ALL, f"var 0 should be unchanged, got {act_r0[0]:#x}"
    assert act_r0[1] == ALL, f"var 1 should be unchanged, got {act_r0[1]:#x}"
    cocotb.log.info("tile in multiple variables not forced ✓")

@cocotb.test()
async def test_inactive_tile_ignored(dut):
    """Tile not in unassigned_tiles is ignored even if only one variable has it."""
    r0 = [ALL & ~1] * V  # all vars have tiles 1..V-1
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    r0[0] = ALL          # var 0 has tile 0 but tile 0 is not unassigned
    unassigned_tiles = ALL & ~1  # tile 0 already placed
    await check(dut, ALL, unassigned_tiles, r0, r1, r2, r3)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    assert act_r0[0] == ALL, f"var 0 should be unchanged since tile 0 inactive"
    cocotb.log.info("inactive tile ignored ✓")

@cocotb.test()
async def test_inactive_variable_not_counted(dut):
    """Inactive variable not counted — tile forced to remaining active variable."""
    r0 = [0] * V
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    r0[0] = 1 << 0      # var 0 has tile 0 but var 0 is inactive
    r0[1] = ALL         # var 1 has all tiles
    unassigned_variables = ALL & ~1  # var 0 inactive
    # tile 0 now only in one active variable (var 1) — forced
    await check(dut, unassigned_variables, ALL, r0, r1, r2, r3)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    assert act_r0[1] == 1, f"var 1 should be forced to tile 0, got {act_r0[1]:#x}"
    cocotb.log.info("inactive variable not counted ✓")

@cocotb.test()
async def test_inactive_variable_not_counted(dut):
    """Inactive variable not counted — tile forced to remaining active variable."""
    r0 = [0] * V
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    r0[0] = 1 << 0      # var 0 has tile 0 but var 0 is inactive
    r0[1] = 1 << 0      # var 1 has only tile 0 — so tile 0 forced to var 1
    unassigned_variables = ALL & ~1  # var 0 inactive
    unassigned_tiles     = 1        # only tile 0 is unassigned
    await check(dut, unassigned_variables, unassigned_tiles, r0, r1, r2, r3)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    assert act_r0[1] == 1, f"var 1 should be forced to tile 0, got {act_r0[1]:#x}"
    cocotb.log.info("inactive variable not counted ✓")
    
@cocotb.test()
async def test_multiple_tiles_forced_to_same_variable(dut):
    """Two tiles both forced to same variable — last one wins in var_mask."""
    r0 = [ALL & ~0b11] * V  # no var has tiles 0 or 1
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    r0[0] = ALL              # var 0 has both tile 0 and tile 1
    # tile 0 and tile 1 are both forced to var 0
    await check(dut, ALL, ALL, r0, r1, r2, r3)
    cocotb.log.info("multiple tiles forced to same variable ✓")

@cocotb.test()
async def test_all_domains_zero(dut):
    """All domains zero — nothing to force, outputs all zero."""
    r = [0] * V
    await check(dut, ALL, ALL, r, r, r, r)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    for v in range(V):
        assert act_r0[v] == 0, f"r0[{v}] should be 0"
    cocotb.log.info("all domains zero ✓")

@cocotb.test()
async def test_single_variable_active(dut):
    """Only one variable active — all unassigned tiles forced to it."""
    r0 = [0] * V
    r1 = [0] * V
    r2 = [0] * V
    r3 = [0] * V
    r0[0] = ALL              # var 0 has all tiles
    unassigned_variables = 1 # only var 0 active
    await check(dut, unassigned_variables, ALL, r0, r1, r2, r3)
    cocotb.log.info("single variable active ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(77)
    for _ in range(50):
        uv = random.randint(0, ALL)
        ut = random.randint(0, ALL)
        r0 = [random.randint(0, ALL) for _ in range(V)]
        r1 = [random.randint(0, ALL) for _ in range(V)]
        r2 = [random.randint(0, ALL) for _ in range(V)]
        r3 = [random.randint(0, ALL) for _ in range(V)]
        await check(dut, uv, ut, r0, r1, r2, r3)
    cocotb.log.info("50 random tests ✓")

def test_TileFrequency_Single():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/TileFrequency_Single.sv"],
        hdl_toplevel="TileFrequency_Single",
        parameters={"N": N},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNOPTFLAT"],
    )
    runner.test(
        hdl_toplevel="TileFrequency_Single",
        test_module="test_TileFrequency_Single",
    )