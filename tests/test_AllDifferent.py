import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N       = 4
V       = N * N
ALL_DOM = (1 << V) - 1


def pack_domain_array(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL_DOM) << (i * V)
    return val


def unpack_domain_array(val):
    return [(val >> (i * V)) & ALL_DOM for i in range(V)]


def reference(in_uv, in_ut, in_r0, in_r1, in_r2, in_r3):
    out_r0 = list(in_r0)
    out_r1 = list(in_r1)
    out_r2 = list(in_r2)
    out_r3 = list(in_r3)
    for i in range(V):
        if (in_uv >> i) & 1:
            out_r0[i] = in_r0[i] & in_ut
            out_r1[i] = in_r1[i] & in_ut
            out_r2[i] = in_r2[i] & in_ut
            out_r3[i] = in_r3[i] & in_ut
    return out_r0, out_r1, out_r2, out_r3


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

    exp_r0, exp_r1, exp_r2, exp_r3 = reference(in_uv, in_ut, in_r0, in_r1, in_r2, in_r3)

    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())

    for i in range(V):
        assert act_r0[i] == exp_r0[i], \
            f"r0[{i}]={act_r0[i]:#018b} exp={exp_r0[i]:#018b}"
        assert act_r1[i] == exp_r1[i], \
            f"r1[{i}]={act_r1[i]:#018b} exp={exp_r1[i]:#018b}"
        assert act_r2[i] == exp_r2[i], \
            f"r2[{i}]={act_r2[i]:#018b} exp={exp_r2[i]:#018b}"
        assert act_r3[i] == exp_r3[i], \
            f"r3[{i}]={act_r3[i]:#018b} exp={exp_r3[i]:#018b}"


def full_mask():    return ALL_DOM
def zero_mask():    return 0
def full_domains(): return [ALL_DOM] * V
def zero_domains(): return [0] * V


@cocotb.test()
async def test_all_unassigned_full_tiles(dut):
    """All variables unassigned, all tiles available — domains unchanged."""
    r = full_domains()
    await check(dut, full_mask(), full_mask(), r, r, r, r)
    cocotb.log.info("all unassigned full tiles ✓")


@cocotb.test()
async def test_all_unassigned_one_tile_removed(dut):
    """All variables unassigned, tile 3 removed — all domains lose bit 3."""
    r   = full_domains()
    ut  = full_mask() & ~(1 << 3)
    await check(dut, full_mask(), ut, r, r, r, r)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    for i in range(V):
        assert not (act_r0[i] >> 3) & 1, \
            f"var {i} r0 should have tile 3 cleared"
    cocotb.log.info("tile 3 removed from all domains ✓")


@cocotb.test()
async def test_assigned_variable_passes_through(dut):
    """Assigned variable (bit clear in uv) passes through unchanged
    even when unassigned tiles mask would clear bits."""
    r0 = full_domains()
    r1 = full_domains()
    r2 = full_domains()
    r3 = full_domains()
    uv = full_mask() & ~(1 << 5)  # var 5 already assigned
    ut = full_mask() & ~(1 << 3)  # tile 3 placed
    await check(dut, uv, ut, r0, r1, r2, r3)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    # var 5 is assigned — its domain should pass through unchanged (ALL_DOM)
    assert act_r0[5] == ALL_DOM, \
        f"assigned var 5 should pass through, got {act_r0[5]:#018b}"
    # var 4 is unassigned — tile 3 should be cleared
    assert not (act_r0[4] >> 3) & 1, \
        "unassigned var 4 should have tile 3 cleared"
    cocotb.log.info("assigned variable passes through ✓")


@cocotb.test()
async def test_no_unassigned_variables(dut):
    """All variables assigned — all domains pass through unchanged."""
    r = full_domains()
    ut = full_mask() & ~(1 << 0)  # tile 0 placed — but should have no effect
    await check(dut, zero_mask(), ut, r, r, r, r)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    for i in range(V):
        assert act_r0[i] == ALL_DOM, \
            f"var {i} should pass through unchanged, got {act_r0[i]:#018b}"
    cocotb.log.info("no unassigned variables — all pass through ✓")


@cocotb.test()
async def test_no_unassigned_tiles(dut):
    """All tiles placed — all active variable domains go to zero."""
    r = full_domains()
    await check(dut, full_mask(), zero_mask(), r, r, r, r)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())
    for i in range(V):
        assert act_r0[i] == 0, f"r0[{i}] should be zero"
        assert act_r1[i] == 0, f"r1[{i}] should be zero"
        assert act_r2[i] == 0, f"r2[{i}] should be zero"
        assert act_r3[i] == 0, f"r3[{i}] should be zero"
    cocotb.log.info("no unassigned tiles — all domains zero ✓")


@cocotb.test()
async def test_all_rotations_masked(dut):
    """Mask is applied to all four rotations independently."""
    r0 = [1 << 0] * V
    r1 = [1 << 1] * V
    r2 = [1 << 2] * V
    r3 = [1 << 3] * V
    # keep only tiles 1 and 2
    ut = (1 << 1) | (1 << 2)
    await check(dut, full_mask(), ut, r0, r1, r2, r3)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_domain_r3.value.to_unsigned())
    for i in range(V):
        assert act_r0[i] == 0,       f"r0[{i}] tile 0 not in mask, should be 0"
        assert act_r1[i] == 1 << 1,  f"r1[{i}] tile 1 in mask, should survive"
        assert act_r2[i] == 1 << 2,  f"r2[{i}] tile 2 in mask, should survive"
        assert act_r3[i] == 0,       f"r3[{i}] tile 3 not in mask, should be 0"
    cocotb.log.info("all rotations masked ✓")


@cocotb.test()
async def test_mixed_assigned_unassigned(dut):
    """Mix of assigned and unassigned variables — only unassigned are masked."""
    r0 = full_domains()
    r1 = full_domains()
    r2 = full_domains()
    r3 = full_domains()
    # vars 0, 2, 4 assigned — vars 1, 3, 5+ unassigned
    uv = 0
    for i in range(V):
        if i % 2 == 1:
            uv |= 1 << i
    ut = full_mask() & ~((1 << 0) | (1 << 2) | (1 << 4))
    await check(dut, uv, ut, r0, r1, r2, r3)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    for i in range(V):
        if i % 2 == 0:
            assert act_r0[i] == ALL_DOM, \
                f"assigned var {i} should pass through unchanged"
        else:
            assert act_r0[i] == ut, \
                f"unassigned var {i} should be masked to ut"
    cocotb.log.info("mixed assigned/unassigned ✓")


@cocotb.test()
async def test_sparse_domain(dut):
    """Variables with sparse domains — only surviving tile bits remain."""
    r0 = zero_domains()
    r1 = zero_domains()
    r2 = zero_domains()
    r3 = zero_domains()
    # var 6: tiles 2, 5, 9 in r0
    r0[6] = (1 << 2) | (1 << 5) | (1 << 9)
    # remove tile 5 from unassigned tiles
    ut = full_mask() & ~(1 << 5)
    await check(dut, full_mask(), ut, r0, r1, r2, r3)
    act_r0 = unpack_domain_array(dut.out_domain_r0.value.to_unsigned())
    expected = (1 << 2) | (1 << 9)  # tile 5 removed
    assert act_r0[6] == expected, \
        f"r0[6]={act_r0[6]:#018b} exp={expected:#018b}"
    cocotb.log.info("sparse domain ✓")


@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(77)
    for _ in range(50):
        uv = random.randint(0, ALL_DOM)
        ut = random.randint(0, ALL_DOM)
        r0 = [random.randint(0, ALL_DOM) for _ in range(V)]
        r1 = [random.randint(0, ALL_DOM) for _ in range(V)]
        r2 = [random.randint(0, ALL_DOM) for _ in range(V)]
        r3 = [random.randint(0, ALL_DOM) for _ in range(V)]
        await check(dut, uv, ut, r0, r1, r2, r3)
    cocotb.log.info("50 random tests ✓")


def test_AllDifferent():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/AllDifferent.sv"],
        hdl_toplevel="AllDifferent",
        parameters={"N": N},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="AllDifferent",
        test_module="test_AllDifferent",
    )