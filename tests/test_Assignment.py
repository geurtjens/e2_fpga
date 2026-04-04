import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
V = N * N
ID_BITS = V.bit_length()
ALL_DOMAIN = (1 << V) - 1

def pack(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL_DOMAIN) << (i * V)
    return val

def unpack(val):
    return [(val >> (i * V)) & ALL_DOMAIN for i in range(V)]

def reference(variable_id, tile_id, rotation, in_r0, in_r1, in_r2, in_r3):
    out_r0 = list(in_r0)
    out_r1 = list(in_r1)
    out_r2 = list(in_r2)
    out_r3 = list(in_r3)
    tile_mask = 1 << tile_id
    out_r0[variable_id] = tile_mask if rotation == 0 else 0
    out_r1[variable_id] = tile_mask if rotation == 1 else 0
    out_r2[variable_id] = tile_mask if rotation == 2 else 0
    out_r3[variable_id] = tile_mask if rotation == 3 else 0
    return out_r0, out_r1, out_r2, out_r3

async def apply(dut, variable_id, tile_id, rotation, in_r0, in_r1, in_r2, in_r3):
    dut.in_variableId.value = variable_id
    dut.in_tileId.value     = tile_id
    dut.in_rotation.value   = rotation
    dut.in_domain_r0.value  = pack(in_r0)
    dut.in_domain_r1.value  = pack(in_r1)
    dut.in_domain_r2.value  = pack(in_r2)
    dut.in_domain_r3.value  = pack(in_r3)
    await Timer(1, unit="ns")

async def check(dut, variable_id, tile_id, rotation, in_r0, in_r1, in_r2, in_r3):
    await apply(dut, variable_id, tile_id, rotation, in_r0, in_r1, in_r2, in_r3)
    exp_r0, exp_r1, exp_r2, exp_r3 = \
        reference(variable_id, tile_id, rotation, in_r0, in_r1, in_r2, in_r3)

    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack(dut.out_domain_r3.value.to_unsigned())

    for v in range(V):
        assert act_r0[v] == exp_r0[v], f"r0[{v}]={act_r0[v]:#x} exp={exp_r0[v]:#x}"
        assert act_r1[v] == exp_r1[v], f"r1[{v}]={act_r1[v]:#x} exp={exp_r1[v]:#x}"
        assert act_r2[v] == exp_r2[v], f"r2[{v}]={act_r2[v]:#x} exp={exp_r2[v]:#x}"
        assert act_r3[v] == exp_r3[v], f"r3[{v}]={act_r3[v]:#x} exp={exp_r3[v]:#x}"

def make_full():
    return [ALL_DOMAIN] * V

@cocotb.test()
async def test_lock_rotation0(dut):
    """Assignment in rotation 0 — only r0 has tile bit set."""
    r = make_full()
    await check(dut, 5, 3, 0, r, r, r, r)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack(dut.out_domain_r3.value.to_unsigned())
    assert act_r0[5] == (1 << 3)
    assert act_r1[5] == 0
    assert act_r2[5] == 0
    assert act_r3[5] == 0
    cocotb.log.info("rotation 0 lock ✓")

@cocotb.test()
async def test_lock_rotation1(dut):
    """Assignment in rotation 1 — only r1 has tile bit set."""
    r = make_full()
    await check(dut, 2, 7, 1, r, r, r, r)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack(dut.out_domain_r1.value.to_unsigned())
    assert act_r0[2] == 0
    assert act_r1[2] == (1 << 7)
    cocotb.log.info("rotation 1 lock ✓")

@cocotb.test()
async def test_lock_rotation2(dut):
    """Assignment in rotation 2 — only r2 has tile bit set."""
    r = make_full()
    await check(dut, 9, 12, 2, r, r, r, r)
    act_r2 = unpack(dut.out_domain_r2.value.to_unsigned())
    assert act_r2[9] == (1 << 12)
    cocotb.log.info("rotation 2 lock ✓")

@cocotb.test()
async def test_lock_rotation3(dut):
    """Assignment in rotation 3 — only r3 has tile bit set."""
    r = make_full()
    await check(dut, 15, 0, 3, r, r, r, r)
    act_r3 = unpack(dut.out_domain_r3.value.to_unsigned())
    assert act_r3[15] == (1 << 0)
    cocotb.log.info("rotation 3 lock ✓")

@cocotb.test()
async def test_other_variables_unchanged(dut):
    """Only assigned variable changes — all others pass through."""
    r = make_full()
    vid = 6
    await check(dut, vid, 4, 0, r, r, r, r)
    act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack(dut.out_domain_r1.value.to_unsigned())
    for v in range(V):
        if v != vid:
            assert act_r0[v] == ALL_DOMAIN, f"r0[{v}] should be unchanged"
            assert act_r1[v] == ALL_DOMAIN, f"r1[{v}] should be unchanged"
    cocotb.log.info("other variables unchanged ✓")

@cocotb.test()
async def test_tile_mask_one_hot(dut):
    """Output domain for assigned variable is one-hot."""
    r = make_full()
    for tile in range(V):
        await apply(dut, 0, tile, 0, r, r, r, r)
        act_r0 = unpack(dut.out_domain_r0.value.to_unsigned())
        assert act_r0[0] == (1 << tile), f"tile {tile} not one-hot"
    cocotb.log.info("tile mask one-hot ✓")

@cocotb.test()
async def test_random(dut):
    """50 random assignments verified against reference."""
    random.seed(55)
    r = make_full()
    for _ in range(50):
        vid  = random.randint(0, V-1)
        tid  = random.randint(0, V-1)
        rot  = random.randint(0, 3)
        await check(dut, vid, tid, rot, r, r, r, r)
    cocotb.log.info("50 random tests ✓")

def test_Assignment():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/Assignment.sv"],
        hdl_toplevel="Assignment",
        parameters={"N": N},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Assignment",
        test_module="test_Assignment",
    )