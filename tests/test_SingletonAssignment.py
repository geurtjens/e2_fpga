import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N       = 4
V       = N * N
ID_BITS = 4
ALL_DOM = (1 << V) - 1


def pack_domain_array(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL_DOM) << (i * V)
    return val


def unpack_domain_array(val):
    return [(val >> (i * V)) & ALL_DOM for i in range(V)]


def reference(in_uv, in_ut, in_r0, in_r1, in_r2, in_r3):
    out_uv = in_uv
    out_ut = in_ut
    out_r0 = list(in_r0)
    out_r1 = list(in_r1)
    out_r2 = list(in_r2)
    out_r3 = list(in_r3)

    for v in range(V):
        if not (in_uv >> v) & 1:
            continue

        r0_any = in_r0[v] != 0
        r1_any = in_r1[v] != 0
        r2_any = in_r2[v] != 0
        r3_any = in_r3[v] != 0

        def is_onehot(x):
            return x != 0 and (x & (x - 1)) == 0

        r0_onehot = is_onehot(in_r0[v])
        r1_onehot = is_onehot(in_r1[v])
        r2_onehot = is_onehot(in_r2[v])
        r3_onehot = is_onehot(in_r3[v])

        active_count = r0_any + r1_any + r2_any + r3_any

        if active_count == 1 and (r0_onehot or r1_onehot or r2_onehot or r3_onehot):
            combined = in_r0[v] | in_r1[v] | in_r2[v] | in_r3[v]

            # extract tile id — highest set bit
            tile_id = 0
            for p in range(V):
                if (combined >> p) & 1:
                    tile_id = p

            # extract rotation
            if r0_any:   rot = 0
            elif r1_any: rot = 1
            elif r2_any: rot = 2
            else:        rot = 3

            out_r0[v] = combined if rot == 0 else 0
            out_r1[v] = combined if rot == 1 else 0
            out_r2[v] = combined if rot == 2 else 0
            out_r3[v] = combined if rot == 3 else 0

            out_uv = out_uv & ~(1 << v)
            out_ut = out_ut & ~(1 << tile_id)

    return out_uv, out_ut, out_r0, out_r1, out_r2, out_r3


async def apply(dut, in_uv, in_ut, in_r0, in_r1, in_r2, in_r3):
    dut.in_unassignedVariables.value = in_uv
    dut.in_unassignedTiles.value     = in_ut
    dut.in_domain_r0.value           = pack_domain_array(in_r0)
    dut.in_domain_r1.value           = pack_domain_array(in_r1)
    dut.in_domain_r2.value           = pack_domain_array(in_r2)
    dut.in_domain_r3.value           = pack_domain_array(in_r3)
    await Timer(1, unit="ns")


async def check(dut, in_uv, in_ut, in_r0, in_r1, in_r2, in_r3):
    await apply(dut, in_uv, in_ut, in_r0, in_r1, in_r2, in_r3)

    exp_uv, exp_ut, exp_r0, exp_r1, exp_r2, exp_r3 = reference(
        in_uv, in_ut, in_r0, in_r1, in_r2, in_r3)

    act_uv = int(dut.out_unassignedVariables.value)
    act_ut = int(dut.out_unassignedTiles.value)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())

    assert act_uv == exp_uv, \
        f"unassignedVariables={act_uv:#018b} exp={exp_uv:#018b}"
    assert act_ut == exp_ut, \
        f"unassignedTiles={act_ut:#018b} exp={exp_ut:#018b}"

    for v in range(V):
        assert act_r0[v] == exp_r0[v], \
            f"r0[{v}]={act_r0[v]:#018b} exp={exp_r0[v]:#018b}"
        assert act_r1[v] == exp_r1[v], \
            f"r1[{v}]={act_r1[v]:#018b} exp={exp_r1[v]:#018b}"
        assert act_r2[v] == exp_r2[v], \
            f"r2[{v}]={act_r2[v]:#018b} exp={exp_r2[v]:#018b}"
        assert act_r3[v] == exp_r3[v], \
            f"r3[{v}]={act_r3[v]:#018b} exp={exp_r3[v]:#018b}"


def full_mask():    return ALL_DOM
def zero_domains(): return [0] * V
def full_domains(): return [ALL_DOM] * V


@cocotb.test()
async def test_no_singletons(dut):
    """Full domains — no singletons detected, everything passes through."""
    r = full_domains()
    await check(dut, full_mask(), full_mask(), r, r, r, r)
    cocotb.log.info("no singletons ✓")


@cocotb.test()
async def test_singleton_rotation_0(dut):
    """Variable with one tile in r0 only — singleton detected at rotation 0."""
    r0 = zero_domains(); r0[3] = 1 << 5
    r1 = zero_domains()
    r2 = zero_domains()
    r3 = zero_domains()
    uv = full_mask()
    ut = full_mask()
    await check(dut, uv, ut, r0, r1, r2, r3)
    act_uv = int(dut.out_unassignedVariables.value)
    act_ut = int(dut.out_unassignedTiles.value)
    assert not (act_uv >> 3) & 1, "var 3 should be removed from unassigned"
    assert not (act_ut >> 5) & 1, "tile 5 should be removed from unassigned"
    cocotb.log.info("singleton rotation 0 ✓")


@cocotb.test()
async def test_singleton_rotation_1(dut):
    """Variable with one tile in r1 only — singleton detected at rotation 1."""
    r0 = zero_domains()
    r1 = zero_domains(); r1[2] = 1 << 7
    r2 = zero_domains()
    r3 = zero_domains()
    uv = full_mask()
    ut = full_mask()
    await check(dut, uv, ut, r0, r1, r2, r3)
    act_uv = int(dut.out_unassignedVariables.value)
    act_ut = int(dut.out_unassignedTiles.value)
    assert not (act_uv >> 2) & 1, "var 2 should be removed from unassigned"
    assert not (act_ut >> 7) & 1, "tile 7 should be removed from unassigned"
    cocotb.log.info("singleton rotation 1 ✓")


@cocotb.test()
async def test_singleton_rotation_2(dut):
    """Variable with one tile in r2 only — singleton detected at rotation 2."""
    r0 = zero_domains()
    r1 = zero_domains()
    r2 = zero_domains(); r2[5] = 1 << 3
    r3 = zero_domains()
    uv = full_mask()
    ut = full_mask()
    await check(dut, uv, ut, r0, r1, r2, r3)
    act_uv = int(dut.out_unassignedVariables.value)
    act_ut = int(dut.out_unassignedTiles.value)
    assert not (act_uv >> 5) & 1, "var 5 should be removed from unassigned"
    assert not (act_ut >> 3) & 1, "tile 3 should be removed from unassigned"
    cocotb.log.info("singleton rotation 2 ✓")


@cocotb.test()
async def test_singleton_rotation_3(dut):
    """Variable with one tile in r3 only — singleton detected at rotation 3."""
    r0 = zero_domains()
    r1 = zero_domains()
    r2 = zero_domains()
    r3 = zero_domains(); r3[7] = 1 << 1
    uv = full_mask()
    ut = full_mask()
    await check(dut, uv, ut, r0, r1, r2, r3)
    act_uv = int(dut.out_unassignedVariables.value)
    act_ut = int(dut.out_unassignedTiles.value)
    assert not (act_uv >> 7) & 1, "var 7 should be removed from unassigned"
    assert not (act_ut >> 1) & 1, "tile 1 should be removed from unassigned"
    cocotb.log.info("singleton rotation 3 ✓")


@cocotb.test()
async def test_not_singleton_multiple_rotations(dut):
    """Same tile in two rotations — not a singleton, domain passes through."""
    r0 = zero_domains(); r0[4] = 1 << 2
    r1 = zero_domains(); r1[4] = 1 << 2
    r2 = zero_domains()
    r3 = zero_domains()
    uv = full_mask()
    ut = full_mask()
    await check(dut, uv, ut, r0, r1, r2, r3)
    act_uv = int(dut.out_unassignedVariables.value)
    assert (act_uv >> 4) & 1, "var 4 should still be unassigned"
    cocotb.log.info("not singleton — multiple rotations ✓")


@cocotb.test()
async def test_not_singleton_multiple_tiles_one_rotation(dut):
    """Two tiles in one rotation — not one-hot, not a singleton."""
    r0 = zero_domains(); r0[4] = (1 << 2) | (1 << 5)
    r1 = zero_domains()
    r2 = zero_domains()
    r3 = zero_domains()
    uv = full_mask()
    ut = full_mask()
    await check(dut, uv, ut, r0, r1, r2, r3)
    act_uv = int(dut.out_unassignedVariables.value)
    assert (act_uv >> 4) & 1, "var 4 should still be unassigned"
    cocotb.log.info("not singleton — multiple tiles ✓")


@cocotb.test()
async def test_already_assigned_variable_skipped(dut):
    """Variable not in unassigned mask is skipped even if domain is singleton."""
    r0 = zero_domains(); r0[3] = 1 << 5
    r1 = zero_domains()
    r2 = zero_domains()
    r3 = zero_domains()
    uv = full_mask() & ~(1 << 3)  # var 3 already assigned
    ut = full_mask()
    await check(dut, uv, ut, r0, r1, r2, r3)
    act_ut = int(dut.out_unassignedTiles.value)
    assert (act_ut >> 5) & 1, "tile 5 should NOT be removed — var 3 was already assigned"
    cocotb.log.info("already assigned variable skipped ✓")


@cocotb.test()
async def test_multiple_singletons(dut):
    """Multiple variables each with one tile in one rotation — all detected."""
    r0 = zero_domains(); r0[0] = 1 << 0
    r1 = zero_domains(); r1[1] = 1 << 1
    r2 = zero_domains(); r2[2] = 1 << 2
    r3 = zero_domains(); r3[3] = 1 << 3
    uv = full_mask()
    ut = full_mask()
    await check(dut, uv, ut, r0, r1, r2, r3)
    act_uv = int(dut.out_unassignedVariables.value)
    act_ut = int(dut.out_unassignedTiles.value)
    for v in range(4):
        assert not (act_uv >> v) & 1, f"var {v} should be removed"
    for t in range(4):
        assert not (act_ut >> t) & 1, f"tile {t} should be removed"
    cocotb.log.info("multiple singletons ✓")


@cocotb.test()
async def test_domain_locked_correctly(dut):
    """Singleton domain is locked — other rotations zeroed out."""
    r0 = zero_domains()
    r1 = zero_domains(); r1[6] = 1 << 9
    r2 = zero_domains()
    r3 = zero_domains()
    uv = full_mask()
    ut = full_mask()
    await check(dut, uv, ut, r0, r1, r2, r3)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())
    assert act_r0[6] == 0,      "r0[6] should be zero"
    assert act_r1[6] == 1 << 9, "r1[6] should be locked to tile 9"
    assert act_r2[6] == 0,      "r2[6] should be zero"
    assert act_r3[6] == 0,      "r3[6] should be zero"
    cocotb.log.info("domain locked correctly ✓")


@cocotb.test()
async def test_empty_domain_not_singleton(dut):
    """Variable with completely empty domain — not a singleton, passes through."""
    r0 = zero_domains()
    r1 = zero_domains()
    r2 = zero_domains()
    r3 = zero_domains()
    uv = full_mask()
    ut = full_mask()
    await check(dut, uv, ut, r0, r1, r2, r3)
    act_uv = int(dut.out_unassignedVariables.value)
    assert act_uv == full_mask(), "no variables should be removed"
    cocotb.log.info("empty domain not singleton ✓")


@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(42)
    for _ in range(50):
        uv = random.randint(0, ALL_DOM)
        ut = random.randint(0, ALL_DOM)
        r0 = [random.randint(0, ALL_DOM) for _ in range(V)]
        r1 = [random.randint(0, ALL_DOM) for _ in range(V)]
        r2 = [random.randint(0, ALL_DOM) for _ in range(V)]
        r3 = [random.randint(0, ALL_DOM) for _ in range(V)]
        await check(dut, uv, ut, r0, r1, r2, r3)
    cocotb.log.info("50 random tests ✓")


def test_SingletonAssignment():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/SingletonAssignment.sv"],
        hdl_toplevel="SingletonAssignment",
        parameters={"N": N},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="SingletonAssignment",
        test_module="test_SingletonAssignment",
    )