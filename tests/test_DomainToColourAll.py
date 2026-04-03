import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
TC = 6
VARIABLES = N * N
ALL_DOMAIN = (1 << VARIABLES) - 1
TC_MASK = (1 << TC) - 1

def rotation_for_position(x, y):
    if x == 0 and y == N-1:   return [0]  # bottom-left corner
    if x == 0 and y == 0:     return [1]  # top-left corner
    if x == N-1 and y == 0:   return [2]  # top-right corner
    if x == N-1 and y == N-1: return [3]  # bottom-right corner
    if y == N-1:               return [0]  # bottom edge
    if x == 0:                 return [1]  # left edge
    if y == 0:                 return [2]  # top edge
    if x == N-1:               return [3]  # right edge
    return [0, 1, 2, 3]                    # inner

def reference_rotation(domain, p_top, p_right, p_bottom, p_left):
    top = right = bottom = left = 0
    for p in range(VARIABLES):
        if (domain >> p) & 1:
            top    |= p_top[p]
            right  |= p_right[p]
            bottom |= p_bottom[p]
            left   |= p_left[p]
    return top, right, bottom, left

def reference_all(r0, r1, r2, r3, in_top, in_right, in_bottom, in_left,
                  p0_top, p0_right, p0_bottom, p0_left,
                  p1_top, p1_right, p1_bottom, p1_left,
                  p2_top, p2_right, p2_bottom, p2_left,
                  p3_top, p3_right, p3_bottom, p3_left):
    p = [
        (p0_top, p0_right, p0_bottom, p0_left),
        (p1_top, p1_right, p1_bottom, p1_left),
        (p2_top, p2_right, p2_bottom, p2_left),
        (p3_top, p3_right, p3_bottom, p3_left),
    ]
    domains = [r0, r1, r2, r3]
    out_top    = [0] * VARIABLES
    out_right  = [0] * VARIABLES
    out_bottom = [0] * VARIABLES
    out_left   = [0] * VARIABLES
    changed = False
    deadend = False

    for gy in range(N):
        for gx in range(N):
            vid = gy * N + gx
            rots = rotation_for_position(gx, gy)
            t = r = b = l = 0
            for rot in rots:
                pt, pr, pb, pl = p[rot]
                rt, rr, rb, rl = reference_rotation(domains[rot][vid], pt, pr, pb, pl)
                t |= rt; r |= rr; b |= rb; l |= rl
            out_top[vid]    = t
            out_right[vid]  = r
            out_bottom[vid] = b
            out_left[vid]   = l
            if t != in_top[vid] or r != in_right[vid] or \
               b != in_bottom[vid] or l != in_left[vid]:
                changed = True
            any_domain = domains[0][vid] | domains[1][vid] | \
                         domains[2][vid] | domains[3][vid]
            if any_domain != 0 and (t | r | b | l) == 0:
                deadend = True

    return out_top, out_right, out_bottom, out_left, changed, deadend

def pack_domain_array(arr):
    val = 0
    for i in range(VARIABLES):
        val |= (arr[i] & ALL_DOMAIN) << (i * VARIABLES)
    return val

def pack_colour_array(arr):
    val = 0
    for i in range(VARIABLES):
        val |= (arr[i] & TC_MASK) << (i * TC)
    return val

def unpack_colour_array(val):
    return [(val >> (i * TC)) & TC_MASK for i in range(VARIABLES)]

async def apply(dut, r0, r1, r2, r3,
                in_top, in_right, in_bottom, in_left,
                p0_top, p0_right, p0_bottom, p0_left,
                p1_top, p1_right, p1_bottom, p1_left,
                p2_top, p2_right, p2_bottom, p2_left,
                p3_top, p3_right, p3_bottom, p3_left):
    dut.r0.value = pack_domain_array(r0)
    dut.r1.value = pack_domain_array(r1)
    dut.r2.value = pack_domain_array(r2)
    dut.r3.value = pack_domain_array(r3)
    dut.in_top.value    = pack_colour_array(in_top)
    dut.in_right.value  = pack_colour_array(in_right)
    dut.in_bottom.value = pack_colour_array(in_bottom)
    dut.in_left.value   = pack_colour_array(in_left)
    dut.p0_top.value    = pack_colour_array(p0_top)
    dut.p0_right.value  = pack_colour_array(p0_right)
    dut.p0_bottom.value = pack_colour_array(p0_bottom)
    dut.p0_left.value   = pack_colour_array(p0_left)
    dut.p1_top.value    = pack_colour_array(p1_top)
    dut.p1_right.value  = pack_colour_array(p1_right)
    dut.p1_bottom.value = pack_colour_array(p1_bottom)
    dut.p1_left.value   = pack_colour_array(p1_left)
    dut.p2_top.value    = pack_colour_array(p2_top)
    dut.p2_right.value  = pack_colour_array(p2_right)
    dut.p2_bottom.value = pack_colour_array(p2_bottom)
    dut.p2_left.value   = pack_colour_array(p2_left)
    dut.p3_top.value    = pack_colour_array(p3_top)
    dut.p3_right.value  = pack_colour_array(p3_right)
    dut.p3_bottom.value = pack_colour_array(p3_bottom)
    dut.p3_left.value   = pack_colour_array(p3_left)
    await Timer(1, unit="ns")

async def check(dut, r0, r1, r2, r3,
                in_top, in_right, in_bottom, in_left,
                p0_top, p0_right, p0_bottom, p0_left,
                p1_top, p1_right, p1_bottom, p1_left,
                p2_top, p2_right, p2_bottom, p2_left,
                p3_top, p3_right, p3_bottom, p3_left):
    await apply(dut, r0, r1, r2, r3,
                in_top, in_right, in_bottom, in_left,
                p0_top, p0_right, p0_bottom, p0_left,
                p1_top, p1_right, p1_bottom, p1_left,
                p2_top, p2_right, p2_bottom, p2_left,
                p3_top, p3_right, p3_bottom, p3_left)

    exp_top, exp_right, exp_bottom, exp_left, exp_changed, exp_deadend = \
        reference_all(r0, r1, r2, r3,
                      in_top, in_right, in_bottom, in_left,
                      p0_top, p0_right, p0_bottom, p0_left,
                      p1_top, p1_right, p1_bottom, p1_left,
                      p2_top, p2_right, p2_bottom, p2_left,
                      p3_top, p3_right, p3_bottom, p3_left)

    act_top    = unpack_colour_array(dut.out_top.value.to_unsigned())
    act_right  = unpack_colour_array(dut.out_right.value.to_unsigned())
    act_bottom = unpack_colour_array(dut.out_bottom.value.to_unsigned())
    act_left   = unpack_colour_array(dut.out_left.value.to_unsigned())

    for vid in range(VARIABLES):
        assert act_top[vid]    == exp_top[vid],    f"out_top[{vid}]={act_top[vid]:06b} expected={exp_top[vid]:06b}"
        assert act_right[vid]  == exp_right[vid],  f"out_right[{vid}]={act_right[vid]:06b} expected={exp_right[vid]:06b}"
        assert act_bottom[vid] == exp_bottom[vid], f"out_bottom[{vid}]={act_bottom[vid]:06b} expected={exp_bottom[vid]:06b}"
        assert act_left[vid]   == exp_left[vid],   f"out_left[{vid}]={act_left[vid]:06b} expected={exp_left[vid]:06b}"

    assert dut.changed.value == int(exp_changed), \
        f"changed={dut.changed.value} expected={int(exp_changed)}"
    assert dut.deadend.value == int(exp_deadend), \
        f"deadend={dut.deadend.value} expected={int(exp_deadend)}"

def make_ones_colours(): return [TC_MASK] * VARIABLES
def make_ones_domains(): return [ALL_DOMAIN] * VARIABLES
def make_zero_domains(): return [0] * VARIABLES

@cocotb.test()
async def test_all_pass(dut):
    """Full domains all-ones pieces — colours are all-ones."""
    r = make_ones_domains()
    c = make_ones_colours()
    p = make_ones_colours()
    await check(dut, r, r, r, r, c, c, c, c,
                p, p, p, p, p, p, p, p,
                p, p, p, p, p, p, p, p)
    assert dut.changed.value == 0
    assert dut.deadend.value == 0
    cocotb.log.info("all ones ✓")

@cocotb.test()
async def test_empty_domains(dut):
    """Empty domains give zero colours — no deadend."""
    r = make_zero_domains()
    c = [0] * VARIABLES
    p = make_ones_colours()
    await check(dut, r, r, r, r, c, c, c, c,
                p, p, p, p, p, p, p, p,
                p, p, p, p, p, p, p, p)
    assert dut.changed.value == 0
    assert dut.deadend.value == 0
    cocotb.log.info("empty domains ✓")

@cocotb.test()
async def test_deadend(dut):
    """Non-empty domain with zero-colour pieces causes deadend."""
    r = make_ones_domains()
    c = [0] * VARIABLES
    p = [0] * VARIABLES  # pieces have no colour
    await check(dut, r, r, r, r, c, c, c, c,
                p, p, p, p, p, p, p, p,
                p, p, p, p, p, p, p, p)
    assert dut.deadend.value == 1
    cocotb.log.info("deadend ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against Python reference."""
    random.seed(42)
    for _ in range(50):
        def rd(): return [random.randint(0, ALL_DOMAIN) for _ in range(VARIABLES)]
        def rc(): return [random.randint(0, TC_MASK) for _ in range(VARIABLES)]
        await check(dut, rd(), rd(), rd(), rd(),
                    rc(), rc(), rc(), rc(),
                    rc(), rc(), rc(), rc(),
                    rc(), rc(), rc(), rc(),
                    rc(), rc(), rc(), rc(),
                    rc(), rc(), rc(), rc())
    cocotb.log.info("50 random tests passed ✓")

def test_DomainToColourAll():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/DomainToColourRotation.sv",
            "rtl/DomainToColourAll.sv",
        ],
        hdl_toplevel="DomainToColourAll",
        parameters={"N": N, "TC": TC},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="DomainToColourAll",
        test_module="test_DomainToColourAll",
    )