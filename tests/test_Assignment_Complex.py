import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

N = 4
TC = 6
VARIABLES = N * N
ID_BITS = 4
TC_MASK = (1 << TC) - 1
ALL_DOMAIN = (1 << VARIABLES) - 1

# Colour constants matching Brendan4
X = 0b000001
A = 0b000010
B = 0b000100
C = 0b001000
D = 0b010000
E = 0b100000

# Brendan4 rotation 0 patterns (top, right, bottom, left)
R0 = [
    (A,A,X,X),(A,B,X,X),(B,A,X,X),(B,B,X,X),
    (C,A,X,A),(C,B,X,A),(D,A,X,A),(E,B,X,A),
    (D,A,X,B),(D,B,X,B),(E,A,X,B),(E,B,X,B),
    (C,C,E,E),(C,D,C,E),(C,D,D,D),(C,E,E,D),
]

def rotate_cw(top, right, bottom, left):
    return left, top, right, bottom

def piece_colours(tile_id, rotation):
    t, r, b, l = R0[tile_id]
    for _ in range(rotation):
        t, r, b, l = rotate_cw(t, r, b, l)
    return t, r, b, l

def pack_colour_array(arr):
    val = 0
    for i in range(VARIABLES):
        val |= (arr[i] & TC_MASK) << (i * TC)
    return val

def pack_domain_array(arr):
    val = 0
    for i in range(VARIABLES):
        val |= (arr[i] & ALL_DOMAIN) << (i * VARIABLES)
    return val

def unpack_colour_array(val):
    return [(val >> (i * TC)) & TC_MASK for i in range(VARIABLES)]

def unpack_domain_array(val):
    return [(val >> (i * VARIABLES)) & ALL_DOMAIN for i in range(VARIABLES)]

def make_piece_arrays(patterns):
    """Build four rotation pattern arrays from R0 patterns."""
    tops = [p[0] for p in patterns]
    rights = [p[1] for p in patterns]
    bottoms = [p[2] for p in patterns]
    lefts = [p[3] for p in patterns]
    return tops, rights, bottoms, lefts

def get_rotation_arrays(rot):
    patterns = []
    for tile in range(VARIABLES):
        t, r, b, l = R0[tile]
        for _ in range(rot):
            t, r, b, l = rotate_cw(t, r, b, l)
        patterns.append((t, r, b, l))
    return make_piece_arrays(patterns)

def reference(variable_id, tile_id, rotation,
              in_top, in_right, in_bottom, in_left,
              in_r0, in_r1, in_r2, in_r3):
    x = variable_id % N
    y = variable_id // N

    pt, pr, pb, pl = piece_colours(tile_id, rotation)

    out_top    = list(in_top)
    out_right  = list(in_right)
    out_bottom = list(in_bottom)
    out_left   = list(in_left)
    out_r0 = list(in_r0)
    out_r1 = list(in_r1)
    out_r2 = list(in_r2)
    out_r3 = list(in_r3)

    # Part 1 — lock domain
    tile_mask = 1 << tile_id
    out_r0[variable_id] = tile_mask if rotation == 0 else 0
    out_r1[variable_id] = tile_mask if rotation == 1 else 0
    out_r2[variable_id] = tile_mask if rotation == 2 else 0
    out_r3[variable_id] = tile_mask if rotation == 3 else 0

    # Part 2 — set own colours
    out_top[variable_id]    = pt
    out_right[variable_id]  = pr
    out_bottom[variable_id] = pb
    out_left[variable_id]   = pl

    # Part 3 — update neighbours
    colours_changed = False
    if x < N-1:
        new = in_left[variable_id+1] & pr
        if new != in_left[variable_id+1]:
            colours_changed = True
        out_left[variable_id+1] = new
    if y < N-1:
        new = in_top[variable_id+N] & pb
        if new != in_top[variable_id+N]:
            colours_changed = True
        out_top[variable_id+N] = new
    if x > 0:
        new = in_right[variable_id-1] & pl
        if new != in_right[variable_id-1]:
            colours_changed = True
        out_right[variable_id-1] = new
    if y > 0:
        new = in_bottom[variable_id-N] & pt
        if new != in_bottom[variable_id-N]:
            colours_changed = True
        out_bottom[variable_id-N] = new

    return (out_top, out_right, out_bottom, out_left,
            out_r0, out_r1, out_r2, out_r3, colours_changed)

async def apply(dut, variable_id, tile_id, rotation,
                in_top, in_right, in_bottom, in_left,
                in_r0, in_r1, in_r2, in_r3):
    dut.variableId.value = variable_id
    dut.tileId.value     = tile_id
    dut.rotation.value   = rotation
    dut.in_top.value    = pack_colour_array(in_top)
    dut.in_right.value  = pack_colour_array(in_right)
    dut.in_bottom.value = pack_colour_array(in_bottom)
    dut.in_left.value   = pack_colour_array(in_left)
    dut.in_r0.value = pack_domain_array(in_r0)
    dut.in_r1.value = pack_domain_array(in_r1)
    dut.in_r2.value = pack_domain_array(in_r2)
    dut.in_r3.value = pack_domain_array(in_r3)

    # Set piece pattern arrays for all 4 rotations
    for rot, prefix in enumerate(['p0', 'p1', 'p2', 'p3']):
        tops, rights, bottoms, lefts = get_rotation_arrays(rot)
        getattr(dut, f'{prefix}_top').value    = pack_colour_array(tops)
        getattr(dut, f'{prefix}_right').value  = pack_colour_array(rights)
        getattr(dut, f'{prefix}_bottom').value = pack_colour_array(bottoms)
        getattr(dut, f'{prefix}_left').value   = pack_colour_array(lefts)

    await Timer(1, unit="ns")

async def check(dut, variable_id, tile_id, rotation,
                in_top, in_right, in_bottom, in_left,
                in_r0, in_r1, in_r2, in_r3):
    await apply(dut, variable_id, tile_id, rotation,
                in_top, in_right, in_bottom, in_left,
                in_r0, in_r1, in_r2, in_r3)

    exp = reference(variable_id, tile_id, rotation,
                    in_top, in_right, in_bottom, in_left,
                    in_r0, in_r1, in_r2, in_r3)
    exp_top, exp_right, exp_bottom, exp_left, \
    exp_r0, exp_r1, exp_r2, exp_r3, exp_cc = exp

    act_top    = unpack_colour_array(dut.out_top.value.to_unsigned())
    act_right  = unpack_colour_array(dut.out_right.value.to_unsigned())
    act_bottom = unpack_colour_array(dut.out_bottom.value.to_unsigned())
    act_left   = unpack_colour_array(dut.out_left.value.to_unsigned())
    act_r0 = unpack_domain_array(dut.out_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_r3.value.to_unsigned())

    for v in range(VARIABLES):
        assert act_top[v]    == exp_top[v],    f"top[{v}]={act_top[v]:06b} exp={exp_top[v]:06b}"
        assert act_right[v]  == exp_right[v],  f"right[{v}]={act_right[v]:06b} exp={exp_right[v]:06b}"
        assert act_bottom[v] == exp_bottom[v], f"bottom[{v}]={act_bottom[v]:06b} exp={exp_bottom[v]:06b}"
        assert act_left[v]   == exp_left[v],   f"left[{v}]={act_left[v]:06b} exp={exp_left[v]:06b}"
        assert act_r0[v] == exp_r0[v], f"r0[{v}]={act_r0[v]:016b} exp={exp_r0[v]:016b}"
        assert act_r1[v] == exp_r1[v], f"r1[{v}]={act_r1[v]:016b} exp={exp_r1[v]:016b}"
        assert act_r2[v] == exp_r2[v], f"r2[{v}]={act_r2[v]:016b} exp={exp_r2[v]:016b}"
        assert act_r3[v] == exp_r3[v], f"r3[{v}]={act_r3[v]:016b} exp={exp_r3[v]:016b}"

    assert dut.colours_changed.value == int(exp_cc), \
        f"colours_changed={dut.colours_changed.value} exp={int(exp_cc)}"

def make_all_ones():
    return [TC_MASK] * VARIABLES

def make_all_ones_domains():
    return [ALL_DOMAIN] * VARIABLES

@cocotb.test()
async def test_domain_locked(dut):
    """Assigned variable's domain is locked to one tile in one rotation."""
    r = make_all_ones_domains()
    c = make_all_ones()
    await apply(dut, 5, 3, 1, c, c, c, c, r, r, r, r)
    act_r0 = unpack_domain_array(dut.out_r0.value.to_unsigned())
    act_r1 = unpack_domain_array(dut.out_r1.value.to_unsigned())
    act_r2 = unpack_domain_array(dut.out_r2.value.to_unsigned())
    act_r3 = unpack_domain_array(dut.out_r3.value.to_unsigned())
    assert act_r0[5] == 0,         "r0 should be zero for assigned var"
    assert act_r1[5] == (1 << 3),  "r1 should have only tile 3"
    assert act_r2[5] == 0,         "r2 should be zero for assigned var"
    assert act_r3[5] == 0,         "r3 should be zero for assigned var"
    cocotb.log.info("domain locked ✓")

@cocotb.test()
async def test_own_colours_set(dut):
    """Assigned variable's colours match piece pattern."""
    r = make_all_ones_domains()
    c = make_all_ones()
    tile_id = 5
    rotation = 2
    await apply(dut, 6, tile_id, rotation, c, c, c, c, r, r, r, r)
    exp_t, exp_r, exp_b, exp_l = piece_colours(tile_id, rotation)
    act_top  = unpack_colour_array(dut.out_top.value.to_unsigned())
    act_right = unpack_colour_array(dut.out_right.value.to_unsigned())
    act_bottom = unpack_colour_array(dut.out_bottom.value.to_unsigned())
    act_left = unpack_colour_array(dut.out_left.value.to_unsigned())
    assert act_top[6]    == exp_t, f"top mismatch"
    assert act_right[6]  == exp_r, f"right mismatch"
    assert act_bottom[6] == exp_b, f"bottom mismatch"
    assert act_left[6]   == exp_l, f"left mismatch"
    cocotb.log.info("own colours set ✓")

@cocotb.test()
async def test_neighbour_colours_updated(dut):
    """Neighbour colours are ANDed with piece edge colours."""
    r = make_all_ones_domains()
    c = make_all_ones()
    # assign var 5 (x=1, y=1) — inner, has all 4 neighbours
    await check(dut, 5, 0, 0, c, c, c, c, r, r, r, r)
    cocotb.log.info("neighbour colours updated ✓")

@cocotb.test()
async def test_corner_no_missing_neighbours(dut):
    """Corner assignment (var 0) doesn't access out-of-bounds neighbours."""
    r = make_all_ones_domains()
    c = make_all_ones()
    await check(dut, 0, 0, 1, c, c, c, c, r, r, r, r)
    cocotb.log.info("corner assignment safe ✓")

@cocotb.test()
async def test_colours_changed_when_restricted(dut):
    """colours_changed=1 when neighbour colour is restricted."""
    r = make_all_ones_domains()
    # set neighbour colour to all-ones so AND will change it
    c = make_all_ones()
    # assign inner variable — neighbour restriction likely
    await check(dut, 5, 7, 0, c, c, c, c, r, r, r, r)
    cocotb.log.info("colours_changed ✓")

@cocotb.test()
async def test_random(dut):
    """30 random assignments verified against reference."""
    random.seed(55)
    r = make_all_ones_domains()
    for _ in range(30):
        vid  = random.randint(0, VARIABLES-1)
        tid  = random.randint(0, VARIABLES-1)
        rot  = random.randint(0, 3)
        c    = [random.randint(1, TC_MASK) for _ in range(VARIABLES)]
        await check(dut, vid, tid, rot, c, c, c, c, r, r, r, r)
    cocotb.log.info("30 random tests passed ✓")

def test_Assignment_Complex():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/Assignment_Complex.sv"],
        hdl_toplevel="Assignment_Complex",
        parameters={"N": N, "TC": TC},
        build_args=["--public-flat-rw","-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Assignment_Complex",
        test_module="test_Assignment_Complex",
    )