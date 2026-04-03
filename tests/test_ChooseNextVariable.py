import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
VARIABLES = N * N
ID_BITS = 4
ALL_VARS = (1 << VARIABLES) - 1

def vid(x, y): return y * N + x

def not_first_col():
    mask = 0
    for r in range(N):
        for c in range(1, N):
            mask |= 1 << (r * N + c)
    return mask

def not_last_col():
    mask = 0
    for r in range(N):
        for c in range(0, N-1):
            mask |= 1 << (r * N + c)
    return mask

NOT_FIRST_COL = not_first_col()
NOT_LAST_COL  = not_last_col()

def reference(vim, r0, r1, r2, r3):
    singletons = ALL_VARS & ~vim & ALL_VARS

    expanded = (
        ((singletons >> N) & ALL_VARS) |
        ((singletons << N) & ALL_VARS) |
        (((singletons & NOT_FIRST_COL) >> 1) & ALL_VARS) |
        (((singletons & NOT_LAST_COL)  << 1) & ALL_VARS)
    )
    candidates = expanded & ALL_VARS & vim

    if candidates == 0:
        return 0, False

    def popcount(x): return bin(x).count('1')

    pop = [popcount(r0[v]) + popcount(r1[v]) + popcount(r2[v]) + popcount(r3[v])
           for v in range(VARIABLES)]

    min_count = min(pop[v] for v in range(VARIABLES) if (candidates >> v) & 1)

    # iterate high to low — last write wins = lowest ID wins
    next_var = None
    for v in range(VARIABLES - 1, -1, -1):
        if (candidates >> v) & 1 and pop[v] == min_count:
            next_var = v

    return next_var, True

def pack_domain(arr):
    val = 0
    for i in range(VARIABLES):
        val |= (arr[i] & ALL_VARS) << (i * VARIABLES)
    return val

async def apply(dut, vim, r0, r1, r2, r3):
    dut.variablesIncludedMask.value = vim
    dut.r0.value = pack_domain(r0)
    dut.r1.value = pack_domain(r1)
    dut.r2.value = pack_domain(r2)
    dut.r3.value = pack_domain(r3)
    await Timer(1, unit="ns")

async def check(dut, vim, r0, r1, r2, r3):
    await apply(dut, vim, r0, r1, r2, r3)
    exp_var, exp_valid = reference(vim, r0, r1, r2, r3)
    assert dut.valid.value == int(exp_valid), \
        f"valid={dut.valid.value} expected={int(exp_valid)}"
    if exp_valid:
        assert int(dut.next_var.value) == exp_var, \
            f"next_var={int(dut.next_var.value)} expected={exp_var}"

def make_domain(n_bits):
    """Domain with n_bits set bits."""
    return (1 << n_bits) - 1

@cocotb.test()
async def test_no_singletons(dut):
    """All variables unassigned — no singletons, no candidates, valid=0."""
    r = [ALL_VARS] * VARIABLES
    await apply(dut, ALL_VARS, r, r, r, r)
    assert dut.valid.value == 0
    cocotb.log.info("no singletons → valid=0 ✓")

@cocotb.test()
async def test_all_assigned(dut):
    """All singletons, none unassigned — valid=0."""
    r = [1] * VARIABLES
    await apply(dut, 0, r, r, r, r)
    assert dut.valid.value == 0
    cocotb.log.info("all assigned → valid=0 ✓")

@cocotb.test()
async def test_single_singleton_picks_neighbour(dut):
    """Var 0 assigned — neighbours are var 1 (right) and var 4 (below), lowest ID wins."""
    r = [ALL_VARS] * VARIABLES
    vim = ALL_VARS & ~1
    await check(dut, vim, r, r, r, r)
    assert dut.valid.value == 1
    nv = int(dut.next_var.value)
    assert nv in [1, 4], f"expected neighbour of var 0, got {nv}"
    cocotb.log.info(f"singleton var 0 → neighbour var {nv} ✓")


@cocotb.test()
async def test_mrv_picks_smallest_domain(dut):
    """Among candidates, pick the one with smallest domain."""
    r0 = [ALL_VARS] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    # var 0 is singleton, neighbours are var 1 and var 4
    # give var 1 a smaller domain than var 4
    r0[1] = 0b0001   # 1 bit
    r0[4] = 0b1111   # 4 bits
    vim = ALL_VARS & ~1
    await check(dut, vim, r0, r1, r2, r3)
    assert dut.valid.value == 1
    assert int(dut.next_var.value) == 1, \
        f"expected var 1 (smaller domain), got {int(dut.next_var.value)}"
    cocotb.log.info("MRV picks smallest domain ✓")

@cocotb.test()
async def test_tie_picks_lowest_id(dut):
    """Tie in domain size — lowest variable ID wins."""
    r0 = [0] * VARIABLES
    r1 = [0] * VARIABLES
    r2 = [0] * VARIABLES
    r3 = [0] * VARIABLES
    r0[1] = 0b0011  # 2 bits
    r0[4] = 0b0011  # 2 bits
    vim = ALL_VARS & ~1
    await check(dut, vim, r0, r1, r2, r3)
    assert dut.valid.value == 1
    assert int(dut.next_var.value) == 1, \
        f"expected var 1 (lower ID), got {int(dut.next_var.value)}"
    cocotb.log.info("tie → lowest ID ✓")

@cocotb.test()
async def test_no_wrap_left_right(dut):
    """Right edge singleton doesn't expand left into next row."""
    r = [ALL_VARS] * VARIABLES
    # var 3 (x=3,y=0) is singleton — right edge
    # should NOT expand to var 4 (x=0,y=1) via wrap
    vim = ALL_VARS & ~(1 << 3)
    await apply(dut, vim, r, r, r, r)
    if dut.valid.value:
        nv = int(dut.next_var.value)
        assert nv != 4, f"wrap-around: var 4 should not be neighbour of var 3"
    cocotb.log.info("no left/right wrap ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against reference."""
    random.seed(42)
    for _ in range(50):
        vim = random.randint(0, ALL_VARS)
        r0 = [random.randint(0, ALL_VARS) for _ in range(VARIABLES)]
        r1 = [random.randint(0, ALL_VARS) for _ in range(VARIABLES)]
        r2 = [random.randint(0, ALL_VARS) for _ in range(VARIABLES)]
        r3 = [random.randint(0, ALL_VARS) for _ in range(VARIABLES)]
        await check(dut, vim, r0, r1, r2, r3)
    cocotb.log.info("50 random tests ✓")

def test_ChooseNextVariable():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/ChooseNextVariable.sv"],
        hdl_toplevel="ChooseNextVariable",
        parameters={"N": N},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="ChooseNextVariable",
        test_module="test_ChooseNextVariable",
    )