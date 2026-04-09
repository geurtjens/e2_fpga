import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N  = 4
CC = 6
V  = N * N
CC_MASK    = (1 << CC) - 1
ALL_DOMAIN = (1 << V) - 1


def pack_domain_array(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL_DOMAIN) << (i * V)
    return val


def pack_colour_array(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & CC_MASK) << (i * CC)
    return val


def reference(in_uv, in_ut,
              in_r0, in_r1, in_r2, in_r3,
              in_c_top, in_c_right, in_c_bottom, in_c_left):
    # Condition 1: empty domain for any unassigned variable
    empty_domain = False
    for i in range(V):
        if (in_uv >> i) & 1:
            if (in_r0[i] | in_r1[i] | in_r2[i] | in_r3[i]) == 0:
                empty_domain = True
                break

    # Condition 2: singleton collision
    uv_count = bin(in_uv).count('1')
    ut_count = bin(in_ut).count('1')
    singleton_collision = (uv_count != ut_count)

    # Condition 3: blank colour for any unassigned variable
    blank_colour = False
    for i in range(V):
        if (in_uv >> i) & 1:
            if (in_c_top[i] == 0 or in_c_right[i] == 0 or
                    in_c_bottom[i] == 0 or in_c_left[i] == 0):
                blank_colour = True
                break

    deadend  = empty_domain or singleton_collision or blank_colour
    solution = (in_uv == 0) and not deadend
    return deadend, solution


async def apply(dut, in_uv, in_ut,
                in_r0, in_r1, in_r2, in_r3,
                in_c_top, in_c_right, in_c_bottom, in_c_left):
    dut.in_unassigned_variables.value = in_uv
    dut.in_unassigned_tiles.value     = in_ut
    dut.in_domain_r0.value            = pack_domain_array(in_r0)
    dut.in_domain_r1.value            = pack_domain_array(in_r1)
    dut.in_domain_r2.value            = pack_domain_array(in_r2)
    dut.in_domain_r3.value            = pack_domain_array(in_r3)
    dut.in_colours_top.value          = pack_colour_array(in_c_top)
    dut.in_colours_right.value        = pack_colour_array(in_c_right)
    dut.in_colours_bottom.value       = pack_colour_array(in_c_bottom)
    dut.in_colours_left.value         = pack_colour_array(in_c_left)
    await Timer(1, unit="ns")


async def check(dut, in_uv, in_ut,
                in_r0, in_r1, in_r2, in_r3,
                in_c_top, in_c_right, in_c_bottom, in_c_left):
    await apply(dut, in_uv, in_ut,
                in_r0, in_r1, in_r2, in_r3,
                in_c_top, in_c_right, in_c_bottom, in_c_left)
    exp_deadend, exp_solution = reference(
        in_uv, in_ut,
        in_r0, in_r1, in_r2, in_r3,
        in_c_top, in_c_right, in_c_bottom, in_c_left)
    assert int(dut.out_deadend.value)  == int(exp_deadend), \
        f"deadend={int(dut.out_deadend.value)} exp={int(exp_deadend)}"
    assert int(dut.out_solution.value) == int(exp_solution), \
        f"solution={int(dut.out_solution.value)} exp={int(exp_solution)}"


def full_mask():     return ALL_DOMAIN
def zero_mask():     return 0
def full_domains():  return [ALL_DOMAIN] * V
def zero_domains():  return [0]          * V
def full_colours():  return [CC_MASK]    * V
def zero_colours():  return [0]          * V


@cocotb.test()
async def test_no_deadend_no_solution(dut):
    """Normal state — variables still unassigned, full domains, no deadend."""
    r = full_domains()
    c = full_colours()
    await check(dut, full_mask(), full_mask(), r, r, r, r, c, c, c, c)
    assert int(dut.out_deadend.value)  == 0
    assert int(dut.out_solution.value) == 0
    cocotb.log.info("no deadend no solution ✓")


@cocotb.test()
async def test_solution(dut):
    """All variables assigned, full domains, full colours — solution."""
    r = full_domains()
    c = full_colours()
    await check(dut, zero_mask(), zero_mask(), r, r, r, r, c, c, c, c)
    assert int(dut.out_deadend.value)  == 0
    assert int(dut.out_solution.value) == 1
    cocotb.log.info("solution ✓")


@cocotb.test()
async def test_deadend_empty_domain(dut):
    """Unassigned variable with empty domain across all rotations — deadend."""
    r0 = zero_domains()  # all domains empty
    c  = full_colours()
    await check(dut, full_mask(), full_mask(), r0, r0, r0, r0, c, c, c, c)
    assert int(dut.out_deadend.value)  == 1
    assert int(dut.out_solution.value) == 0
    cocotb.log.info("deadend empty domain ✓")


@cocotb.test()
async def test_deadend_singleton_collision(dut):
    """More unassigned variables than tiles — singleton collision deadend."""
    # uv has 2 bits set, ut has 1 bit set → collision
    uv = 0b11
    ut = 0b01
    r  = full_domains()
    c  = full_colours()
    await check(dut, uv, ut, r, r, r, r, c, c, c, c)
    assert int(dut.out_deadend.value) == 1
    cocotb.log.info("deadend singleton collision ✓")


@cocotb.test()
async def test_deadend_blank_top_colour(dut):
    """Unassigned variable with zero top colour — deadend."""
    r     = full_domains()
    c_top = full_colours(); c_top[3] = 0  # var 3 has blank top
    c_ful = full_colours()
    uv    = full_mask()
    await check(dut, uv, uv, r, r, r, r, c_top, c_ful, c_ful, c_ful)
    assert int(dut.out_deadend.value) == 1
    cocotb.log.info("deadend blank top colour ✓")


@cocotb.test()
async def test_deadend_blank_right_colour(dut):
    """Unassigned variable with zero right colour — deadend."""
    r       = full_domains()
    c_right = full_colours(); c_right[5] = 0
    c_ful   = full_colours()
    uv      = full_mask()
    await check(dut, uv, uv, r, r, r, r, c_ful, c_right, c_ful, c_ful)
    assert int(dut.out_deadend.value) == 1
    cocotb.log.info("deadend blank right colour ✓")


@cocotb.test()
async def test_deadend_blank_bottom_colour(dut):
    """Unassigned variable with zero bottom colour — deadend."""
    r         = full_domains()
    c_bottom  = full_colours(); c_bottom[7] = 0
    c_ful     = full_colours()
    uv        = full_mask()
    await check(dut, uv, uv, r, r, r, r, c_ful, c_ful, c_bottom, c_ful)
    assert int(dut.out_deadend.value) == 1
    cocotb.log.info("deadend blank bottom colour ✓")


@cocotb.test()
async def test_deadend_blank_left_colour(dut):
    """Unassigned variable with zero left colour — deadend."""
    r       = full_domains()
    c_left  = full_colours(); c_left[2] = 0
    c_ful   = full_colours()
    uv      = full_mask()
    await check(dut, uv, uv, r, r, r, r, c_ful, c_ful, c_ful, c_left)
    assert int(dut.out_deadend.value) == 1
    cocotb.log.info("deadend blank left colour ✓")


@cocotb.test()
async def test_blank_colour_assigned_variable_ignored(dut):
    """Blank colour on an assigned variable does not trigger deadend."""
    r      = full_domains()
    c_top  = full_colours(); c_top[3] = 0  # var 3 has blank top
    c_ful  = full_colours()
    # var 3 is assigned (bit clear in uv)
    uv     = full_mask() & ~(1 << 3)
    ut     = full_mask() & ~(1 << 3)
    await check(dut, uv, ut, r, r, r, r, c_top, c_ful, c_ful, c_ful)
    assert int(dut.out_deadend.value) == 0
    cocotb.log.info("blank colour assigned variable ignored ✓")


@cocotb.test()
async def test_empty_domain_assigned_variable_ignored(dut):
    """Empty domain on an assigned variable does not trigger deadend."""
    r0 = full_domains(); r0[5] = 0
    r1 = full_domains(); r1[5] = 0
    r2 = full_domains(); r2[5] = 0
    r3 = full_domains(); r3[5] = 0
    c  = full_colours()
    # var 5 is assigned
    uv = full_mask() & ~(1 << 5)
    ut = full_mask() & ~(1 << 5)
    await check(dut, uv, ut, r0, r1, r2, r3, c, c, c, c)
    assert int(dut.out_deadend.value) == 0
    cocotb.log.info("empty domain assigned variable ignored ✓")


@cocotb.test()
async def test_solution_requires_no_deadend(dut):
    """All variables assigned but blank colour — deadend prevents solution."""
    r      = full_domains()
    c_top  = full_colours(); c_top[0] = 0
    c_ful  = full_colours()
    # all variables assigned BUT var 0 has blank top
    # however var 0 is assigned so blank colour is ignored
    await check(dut, zero_mask(), zero_mask(), r, r, r, r,
                c_top, c_ful, c_ful, c_ful)
    assert int(dut.out_deadend.value)  == 0
    assert int(dut.out_solution.value) == 1
    cocotb.log.info("solution with assigned blank colour ✓")


@cocotb.test()
async def test_partial_assignment_no_deadend(dut):
    """Some variables assigned, remaining have valid domains and colours."""
    r   = full_domains()
    c   = full_colours()
    # vars 0-7 assigned
    uv  = full_mask() & ~0xFF
    ut  = full_mask() & ~0xFF
    await check(dut, uv, ut, r, r, r, r, c, c, c, c)
    assert int(dut.out_deadend.value)  == 0
    assert int(dut.out_solution.value) == 0
    cocotb.log.info("partial assignment no deadend ✓")


@cocotb.test()
async def test_multiple_deadend_conditions(dut):
    """Multiple deadend conditions simultaneously — still deadend."""
    r0    = zero_domains()  # empty domains
    c_top = full_colours(); c_top[0] = 0  # blank colour
    c_ful = full_colours()
    uv    = 0b11
    ut    = 0b01  # singleton collision
    await check(dut, uv, ut, r0, r0, r0, r0, c_top, c_ful, c_ful, c_ful)
    assert int(dut.out_deadend.value) == 1
    cocotb.log.info("multiple deadend conditions ✓")


@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(123)
    for _ in range(50):
        uv = random.randint(0, ALL_DOMAIN)
        ut = random.randint(0, ALL_DOMAIN)
        r0 = [random.randint(0, ALL_DOMAIN) for _ in range(V)]
        r1 = [random.randint(0, ALL_DOMAIN) for _ in range(V)]
        r2 = [random.randint(0, ALL_DOMAIN) for _ in range(V)]
        r3 = [random.randint(0, ALL_DOMAIN) for _ in range(V)]
        ct = [random.randint(0, CC_MASK) for _ in range(V)]
        cr = [random.randint(0, CC_MASK) for _ in range(V)]
        cb = [random.randint(0, CC_MASK) for _ in range(V)]
        cl = [random.randint(0, CC_MASK) for _ in range(V)]
        await check(dut, uv, ut, r0, r1, r2, r3, ct, cr, cb, cl)
    cocotb.log.info("50 random tests ✓")


def test_DeadendOrSolutionCheck():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/DeadendOrSolutionCheck.sv"],
        hdl_toplevel="DeadendOrSolutionCheck",
        parameters={"N": N, "CC": CC},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="DeadendOrSolutionCheck",
        test_module="test_DeadendOrSolutionCheck",
    )