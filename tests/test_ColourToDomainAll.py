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
    """Return which rotation(s) apply for grid position (x,y). 0,0 = top-left."""
    if x == 0 and y == N-1:      return [0]  # bottom-left corner
    if x == 0 and y == 0:        return [1]  # top-left corner
    if x == N-1 and y == 0:      return [2]  # top-right corner
    if x == N-1 and y == N-1:    return [3]  # bottom-right corner
    if y == N-1:                  return [0]  # bottom edge
    if x == 0:                    return [1]  # left edge
    if y == 0:                    return [2]  # top edge
    if x == N-1:                  return [3]  # right edge
    return [0, 1, 2, 3]                       # inner

def reference_rotation(domain, top, right, bottom, left, p_top, p_right, p_bottom, p_left):
    """Filter domain for one rotation using Python reference."""
    out = 0
    for p in range(VARIABLES):
        if (domain >> p) & 1:
            if (top    & p_top[p])    and \
               (right  & p_right[p])  and \
               (bottom & p_bottom[p]) and \
               (left   & p_left[p]):
                out |= (1 << p)
    return out

def reference_all(r0, r1, r2, r3, in_top, in_right, in_bottom, in_left,
                  p0_top, p0_right, p0_bottom, p0_left,
                  p1_top, p1_right, p1_bottom, p1_left,
                  p2_top, p2_right, p2_bottom, p2_left,
                  p3_top, p3_right, p3_bottom, p3_left):
    """Full reference model for ColoursToDomainAllRotations."""
    p = [
        (p0_top, p0_right, p0_bottom, p0_left),
        (p1_top, p1_right, p1_bottom, p1_left),
        (p2_top, p2_right, p2_bottom, p2_left),
        (p3_top, p3_right, p3_bottom, p3_left),
    ]
    domains = [r0, r1, r2, r3]
    r0_out = list(r0)
    r1_out = list(r1)
    r2_out = list(r2)
    r3_out = list(r3)
    out = [r0_out, r1_out, r2_out, r3_out]

    changed = False
    deadend = False

    for gy in range(N):
        for gx in range(N):
            vid = gy * N + gx
            rots = rotation_for_position(gx, gy)
            top    = in_top[vid]
            right  = in_right[vid]
            bottom = in_bottom[vid]
            left   = in_left[vid]

            for rot in rots:
                pt, pr, pb, pl = p[rot]
                d = domains[rot][vid]
                result = reference_rotation(d, top, right, bottom, left, pt, pr, pb, pl)
                out[rot][vid] = result
                if result != d:
                    changed = True
                if d != 0 and result == 0:
                    deadend = True

    return r0_out, r1_out, r2_out, r3_out, changed, deadend

def pack_domain_array(arr):
    """Pack list of VARIABLES domain bitmasks into one big integer."""
    val = 0
    for i in range(VARIABLES):
        val |= (arr[i] & ALL_DOMAIN) << (i * VARIABLES)
    return val

def pack_colour_array(arr):
    """Pack list of VARIABLES colour masks into one big integer."""
    val = 0
    for i in range(VARIABLES):
        val |= (arr[i] & TC_MASK) << (i * TC)
    return val

def unpack_domain_array(val):
    """Unpack big integer into list of VARIABLES domain bitmasks."""
    return [(val >> (i * VARIABLES)) & ALL_DOMAIN for i in range(VARIABLES)]

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

    exp_r0, exp_r1, exp_r2, exp_r3, exp_changed, exp_deadend = reference_all(
        r0, r1, r2, r3,
        in_top, in_right, in_bottom, in_left,
        p0_top, p0_right, p0_bottom, p0_left,
        p1_top, p1_right, p1_bottom, p1_left,
        p2_top, p2_right, p2_bottom, p2_left,
        p3_top, p3_right, p3_bottom, p3_left)

    act_r0 = unpack_domain_array(dut.r0_out.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.r1_out.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.r2_out.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.r3_out.value.to_unsigned())

    for vid in range(VARIABLES):
        assert act_r0[vid] == exp_r0[vid], \
            f"r0_out[{vid}]={act_r0[vid]:016b} expected={exp_r0[vid]:016b}"
        assert act_r1[vid] == exp_r1[vid], \
            f"r1_out[{vid}]={act_r1[vid]:016b} expected={exp_r1[vid]:016b}"
        assert act_r2[vid] == exp_r2[vid], \
            f"r2_out[{vid}]={act_r2[vid]:016b} expected={exp_r2[vid]:016b}"
        assert act_r3[vid] == exp_r3[vid], \
            f"r3_out[{vid}]={act_r3[vid]:016b} expected={exp_r3[vid]:016b}"

    assert dut.changed.value == int(exp_changed), \
        f"changed={dut.changed.value} expected={int(exp_changed)}"
    assert dut.deadend.value == int(exp_deadend), \
        f"deadend={dut.deadend.value} expected={int(exp_deadend)}"

def make_all_ones_colours():
    return [TC_MASK] * VARIABLES

def make_all_ones_domains():
    return [ALL_DOMAIN] * VARIABLES

@cocotb.test()
async def test_all_pass(dut):
    """All pieces pass all positions when constraints are all-ones."""
    r = make_all_ones_domains()
    c = make_all_ones_colours()
    p = make_all_ones_colours()
    await check(dut, r, r, r, r, c, c, c, c,
                p, p, p, p, p, p, p, p,
                p, p, p, p, p, p, p, p)
    assert dut.changed.value == 0
    assert dut.deadend.value == 0
    cocotb.log.info("all pass ✓")

@cocotb.test()
async def test_no_pieces_pass(dut):
    """All domains go to zero — deadend."""
    r = make_all_ones_domains()
    c = [0b111110] * VARIABLES   # constraint has no bit 0
    p = [0b000001] * VARIABLES   # pieces only have bit 0
    await check(dut, r, r, r, r, c, c, c, c,
                p, p, p, p, p, p, p, p,
                p, p, p, p, p, p, p, p)
    assert dut.deadend.value == 1
    cocotb.log.info("all deadend ✓")

@cocotb.test()
async def test_empty_domains(dut):
    """Empty domains stay empty — no deadend."""
    r = [0] * VARIABLES
    c = make_all_ones_colours()
    p = make_all_ones_colours()
    await check(dut, r, r, r, r, c, c, c, c,
                p, p, p, p, p, p, p, p,
                p, p, p, p, p, p, p, p)
    assert dut.changed.value == 0
    assert dut.deadend.value == 0
    cocotb.log.info("empty domains ✓")

@cocotb.test()
async def test_random(dut):
    """50 random inputs verified against Python reference."""
    random.seed(123)
    for i in range(50):
        def rand_domains(): return [random.randint(0, ALL_DOMAIN) for _ in range(VARIABLES)]
        def rand_colours(): return [random.randint(1, TC_MASK) for _ in range(VARIABLES)]
        await check(dut,
                    rand_domains(), rand_domains(), rand_domains(), rand_domains(),
                    rand_colours(), rand_colours(), rand_colours(), rand_colours(),
                    rand_colours(), rand_colours(), rand_colours(), rand_colours(),
                    rand_colours(), rand_colours(), rand_colours(), rand_colours(),
                    rand_colours(), rand_colours(), rand_colours(), rand_colours(),
                    rand_colours(), rand_colours(), rand_colours(), rand_colours())
    cocotb.log.info("50 random tests passed ✓")

def test_ColourToDomainAll():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/ColourToDomainRotation.sv",
            "rtl/ColourToDomainAll.sv",
        ],
        hdl_toplevel="ColourToDomainAll",
        parameters={"N": N, "TC": TC},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="ColourToDomainAll",
        test_module="test_ColourToDomainAll",
    )