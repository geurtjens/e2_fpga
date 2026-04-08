import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

from elements_state import ElementsState
from grid_state     import GridState

N         = 4
CC        = 6
V         = N * N
ID_BITS   = 4
CC_MASK   = (1 << CC) - 1
ALL_DOM   = (1 << V) - 1

# ── Colour constants ──────────────────────────────────────────
X = 0b000001
A = 0b000010
B = 0b000100
C = 0b001000
D = 0b010000
E = 0b100000

# ── Brendan4 base tile patterns (top, right, bottom, left) ───
R0 = [
    (A,A,X,X),(A,B,X,X),(B,A,X,X),(B,B,X,X),
    (C,A,X,A),(C,B,X,A),(D,A,X,A),(E,B,X,A),
    (D,A,X,B),(D,B,X,B),(E,A,X,B),(E,B,X,B),
    (C,C,E,E),(C,D,C,E),(C,D,D,D),(C,E,E,D),
]

def rotate_cw(top, right, bottom, left):
    """One 90-degree clockwise rotation — new_top=old_left."""
    return left, top, right, bottom

def piece_colours(tile_id, rotation):
    """Derive tile colours at given rotation from base orientation."""
    t, r, b, l = R0[tile_id]
    for _ in range(rotation):
        t, r, b, l = rotate_cw(t, r, b, l)
    return t, r, b, l

def pack_colour(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & CC_MASK) << (i * CC)
    return val

def pack_domain(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL_DOM) << (i * V)
    return val

def unpack_colour(val):
    return [(val >> (i * CC)) & CC_MASK for i in range(V)]

def unpack_domain(val):
    return [(val >> (i * V)) & ALL_DOM for i in range(V)]

def make_elements():
    """Build element arrays from R0 base patterns."""
    tops    = [R0[t][0] for t in range(V)]
    rights  = [R0[t][1] for t in range(V)]
    bottoms = [R0[t][2] for t in range(V)]
    lefts   = [R0[t][3] for t in range(V)]
    return tops, rights, bottoms, lefts

import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

from elements_state import ElementsState
from grid_state     import GridState

N         = 4
CC        = 6
V         = N * N
ID_BITS   = 4
CC_MASK   = (1 << CC) - 1
ALL_DOM   = (1 << V) - 1

# ── Colour constants ──────────────────────────────────────────
X = 0b000001
A = 0b000010
B = 0b000100
C = 0b001000
D = 0b010000
E = 0b100000

# ── Brendan4 base tile patterns (top, right, bottom, left) ───
R0 = [
    (A,A,X,X),(A,B,X,X),(B,A,X,X),(B,B,X,X),
    (C,A,X,A),(C,B,X,A),(D,A,X,A),(E,B,X,A),
    (D,A,X,B),(D,B,X,B),(E,A,X,B),(E,B,X,B),
    (C,C,E,E),(C,D,C,E),(C,D,D,D),(C,E,E,D),
]

def rotate_cw(top, right, bottom, left):
    """One 90-degree clockwise rotation — new_top=old_left."""
    return left, top, right, bottom

def piece_colours(tile_id, rotation):
    """Derive tile colours at given rotation from base orientation."""
    t, r, b, l = R0[tile_id]
    for _ in range(rotation):
        t, r, b, l = rotate_cw(t, r, b, l)
    return t, r, b, l

def pack_colour(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & CC_MASK) << (i * CC)
    return val

def pack_domain(arr):
    val = 0
    for i in range(V):
        val |= (arr[i] & ALL_DOM) << (i * V)
    return val

def unpack_colour(val):
    return [(val >> (i * CC)) & CC_MASK for i in range(V)]

def unpack_domain(val):
    return [(val >> (i * V)) & ALL_DOM for i in range(V)]

def make_elements():
    """Build element arrays from R0 base patterns."""
    tops    = [R0[t][0] for t in range(V)]
    rights  = [R0[t][1] for t in range(V)]
    bottoms = [R0[t][2] for t in range(V)]
    lefts   = [R0[t][3] for t in range(V)]
    return tops, rights, bottoms, lefts

def reference(variable_id, tile_id, rotation,
              in_uv, in_ut,
              in_top, in_right, in_bottom, in_left,
              in_r0, in_r1, in_r2, in_r3):
    x  = variable_id % N
    y  = variable_id // N
    pt, pr, pb, pl = piece_colours(tile_id, rotation)

    out_top    = list(in_top)
    out_right  = list(in_right)
    out_bottom = list(in_bottom)
    out_left   = list(in_left)
    out_r0     = list(in_r0)
    out_r1     = list(in_r1)
    out_r2     = list(in_r2)
    out_r3     = list(in_r3)

    # Part 1 — lock domain
    tile_mask           = 1 << tile_id
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
    if x < N-1:
        out_left[variable_id+1]  = in_left[variable_id+1]  & pr
    if y < N-1:
        out_top[variable_id+N]   = in_top[variable_id+N]   & pb
    if x > 0:
        out_right[variable_id-1] = in_right[variable_id-1] & pl
    if y > 0:
        out_bottom[variable_id-N] = in_bottom[variable_id-N] & pt

    # Part 4 — update availability masks
    out_uv = in_uv & ~(1 << variable_id)
    out_ut = in_ut & ~(1 << tile_id)

    # Part 5 — AllDifferent_Simple
    # Every still-unassigned variable loses the placed tile from its domain
    for v in range(V):
        if (out_uv >> v) & 1:
            out_r0[v] = out_r0[v] & out_ut
            out_r1[v] = out_r1[v] & out_ut
            out_r2[v] = out_r2[v] & out_ut
            out_r3[v] = out_r3[v] & out_ut

    return (out_top, out_right, out_bottom, out_left,
            out_r0, out_r1, out_r2, out_r3,
            out_uv, out_ut)

async def apply(dut, variable_id, tile_id, rotation,
                in_uv, in_ut,
                in_top, in_right, in_bottom, in_left,
                in_r0, in_r1, in_r2, in_r3):
    el_top, el_right, el_bottom, el_left = make_elements()
    dut.in_variableId.value           = variable_id
    dut.in_tileId.value               = tile_id
    dut.in_rotation.value             = rotation
    dut.in_unassigned_variables.value = in_uv
    dut.in_unassigned_tiles.value     = in_ut
    dut.in_colours_top.value          = pack_colour(in_top)
    dut.in_colours_right.value        = pack_colour(in_right)
    dut.in_colours_bottom.value       = pack_colour(in_bottom)
    dut.in_colours_left.value         = pack_colour(in_left)
    dut.in_domain_r0.value            = pack_domain(in_r0)
    dut.in_domain_r1.value            = pack_domain(in_r1)
    dut.in_domain_r2.value            = pack_domain(in_r2)
    dut.in_domain_r3.value            = pack_domain(in_r3)
    dut.in_elements_top.value         = pack_colour(el_top)
    dut.in_elements_right.value       = pack_colour(el_right)
    dut.in_elements_bottom.value      = pack_colour(el_bottom)
    dut.in_elements_left.value        = pack_colour(el_left)
    await Timer(1, unit="ns")

async def check(dut, variable_id, tile_id, rotation,
                in_uv, in_ut,
                in_top, in_right, in_bottom, in_left,
                in_r0, in_r1, in_r2, in_r3):
    await apply(dut, variable_id, tile_id, rotation,
                in_uv, in_ut,
                in_top, in_right, in_bottom, in_left,
                in_r0, in_r1, in_r2, in_r3)

    (exp_top, exp_right, exp_bottom, exp_left,
     exp_r0, exp_r1, exp_r2, exp_r3,
     exp_uv, exp_ut) = reference(
        variable_id, tile_id, rotation,
        in_uv, in_ut,
        in_top, in_right, in_bottom, in_left,
        in_r0, in_r1, in_r2, in_r3)

    act_top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    act_right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    act_bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    act_left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    act_r0     = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    act_r1     = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    act_r2     = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    act_r3     = unpack_domain(dut.out_domain_r3.value.to_unsigned())
    act_uv     = int(dut.out_unassigned_variables.value)
    act_ut     = int(dut.out_unassigned_tiles.value)

    for v in range(V):
        assert act_top[v]    == exp_top[v],    \
            f"top[{v}]={act_top[v]:06b} exp={exp_top[v]:06b}"
        assert act_right[v]  == exp_right[v],  \
            f"right[{v}]={act_right[v]:06b} exp={exp_right[v]:06b}"
        assert act_bottom[v] == exp_bottom[v], \
            f"bottom[{v}]={act_bottom[v]:06b} exp={exp_bottom[v]:06b}"
        assert act_left[v]   == exp_left[v],   \
            f"left[{v}]={act_left[v]:06b} exp={exp_left[v]:06b}"
        assert act_r0[v] == exp_r0[v], \
            f"r0[{v}]={act_r0[v]:016b} exp={exp_r0[v]:016b}"
        assert act_r1[v] == exp_r1[v], \
            f"r1[{v}]={act_r1[v]:016b} exp={exp_r1[v]:016b}"
        assert act_r2[v] == exp_r2[v], \
            f"r2[{v}]={act_r2[v]:016b} exp={exp_r2[v]:016b}"
        assert act_r3[v] == exp_r3[v], \
            f"r3[{v}]={act_r3[v]:016b} exp={exp_r3[v]:016b}"

    assert act_uv == exp_uv, \
        f"unassigned_variables={act_uv:#x} exp={exp_uv:#x}"
    assert act_ut == exp_ut, \
        f"unassigned_tiles={act_ut:#x} exp={exp_ut:#x}"

def full_colours(): return [CC_MASK] * V
def full_domains(): return [ALL_DOM] * V
def full_mask():    return ALL_DOM

@cocotb.test()
async def test_domain_locked_r0(dut):
    """Assigned variable's domain is locked to one tile in rotation 0."""
    await check(dut, 5, 3, 0, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    act_r0 = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain(dut.out_domain_r3.value.to_unsigned())
    assert act_r0[5] == (1 << 3), "r0 should have only tile 3"
    assert act_r1[5] == 0,        "r1 should be zero"
    assert act_r2[5] == 0,        "r2 should be zero"
    assert act_r3[5] == 0,        "r3 should be zero"
    cocotb.log.info("domain locked rotation 0 ✓")

@cocotb.test()
async def test_domain_locked_r1(dut):
    """Assigned variable's domain is locked to one tile in rotation 1."""
    await check(dut, 5, 3, 1, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    act_r0 = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    assert act_r0[5] == 0,        "r0 should be zero"
    assert act_r1[5] == (1 << 3), "r1 should have only tile 3"
    cocotb.log.info("domain locked rotation 1 ✓")

@cocotb.test()
async def test_own_colours_set(dut):
    """Assigned variable's colours match piece pattern at chosen rotation."""
    tile_id  = 5
    rotation = 2
    await check(dut, 6, tile_id, rotation, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    exp_t, exp_r, exp_b, exp_l = piece_colours(tile_id, rotation)
    act_top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    act_right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    act_bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    act_left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    assert act_top[6]    == exp_t, f"top mismatch got={act_top[6]:06b} exp={exp_t:06b}"
    assert act_right[6]  == exp_r, f"right mismatch"
    assert act_bottom[6] == exp_b, f"bottom mismatch"
    assert act_left[6]   == exp_l, f"left mismatch"
    cocotb.log.info("own colours set ✓")

@cocotb.test()
async def test_neighbour_colours_updated(dut):
    """Inner variable — all four neighbours get colour constraints applied."""
    await check(dut, 5, 0, 0, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("neighbour colours updated ✓")

@cocotb.test()
async def test_top_left_corner_safe(dut):
    """Top-left corner (var 0) — no up or left neighbours, no out-of-bounds access."""
    await check(dut, 0, 0, 1, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("top-left corner safe ✓")

@cocotb.test()
async def test_bottom_right_corner_safe(dut):
    """Bottom-right corner (var V-1) — no right or down neighbours."""
    await check(dut, V-1, 1, 3, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("bottom-right corner safe ✓")

@cocotb.test()
async def test_top_right_corner_safe(dut):
    """Top-right corner (var N-1) — no up or right neighbours."""
    await check(dut, N-1, 2, 2, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("top-right corner safe ✓")

@cocotb.test()
async def test_bottom_left_corner_safe(dut):
    """Bottom-left corner (var N*(N-1)) — no left or down neighbours."""
    await check(dut, N*(N-1), 3, 0, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("bottom-left corner safe ✓")

@cocotb.test()
async def test_unassigned_variable_bit_cleared(dut):
    """Assigned variable's bit is cleared in out_unassigned_variables."""
    in_uv = full_mask()
    await check(dut, 5, 3, 0, in_uv, full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    act_uv = int(dut.out_unassigned_variables.value)
    assert not (act_uv >> 5) & 1, "var 5 bit should be cleared"
    assert (act_uv >> 4) & 1,     "var 4 bit should still be set"
    cocotb.log.info("unassigned variable bit cleared ✓")

@cocotb.test()
async def test_unassigned_tile_bit_cleared(dut):
    """Assigned tile's bit is cleared in out_unassigned_tiles."""
    in_ut = full_mask()
    await check(dut, 5, 7, 0, full_mask(), in_ut,
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    act_ut = int(dut.out_unassigned_tiles.value)
    assert not (act_ut >> 7) & 1, "tile 7 bit should be cleared"
    assert (act_ut >> 6) & 1,     "tile 6 bit should still be set"
    cocotb.log.info("unassigned tile bit cleared ✓")

@cocotb.test()
async def test_other_variables_unchanged(dut):
    """Variables other than the assigned one and its neighbours are unchanged.
    After AllDifferent_Simple the placed tile (tile 1) is removed from all
    remaining unassigned variables' domains so we expect ALL_DOM minus tile 1.
    """
    c  = full_colours()
    r  = full_domains()
    uv = full_mask()
    ut = full_mask()
    await check(dut, 0, 1, 1, uv, ut, c, c, c, c, r, r, r, r)
    act_r0  = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    exp_dom = ALL_DOM & ~(1 << 1)  # tile 1 cleared by AllDifferent_Simple
    for v in range(2, V):
        if v != N:  # var N is below var 0 — skip
            assert act_r0[v] == exp_dom, \
                f"var {v} domain should be ALL_DOM minus tile 1, got {act_r0[v]:#x}"
    cocotb.log.info("other variables unchanged ✓")

@cocotb.test()
async def test_random(dut):
    """30 random assignments verified against reference."""
    random.seed(55)
    r  = full_domains()
    uv = full_mask()
    ut = full_mask()
    for _ in range(30):
        vid = random.randint(0, V-1)
        tid = random.randint(0, V-1)
        rot = random.randint(0, 3)
        c   = [random.randint(1, CC_MASK) for _ in range(V)]
        await check(dut, vid, tid, rot, uv, ut, c, c, c, c, r, r, r, r)
    cocotb.log.info("30 random tests ✓")





def test_Assignment():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/Assignment.sv", 
                 "rtl/ColourLookup.sv",
                 "rtl/ColourAssignment.sv",
                 "rtl/ColourAssignmentNeighbours.sv",
                 "rtl/AllDifferent_Simple.sv"],
        hdl_toplevel="Assignment",
        parameters={"N": N, "CC": CC},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Assignment",
        test_module="test_Assignment",
    )

async def apply(dut, variable_id, tile_id, rotation,
                in_uv, in_ut,
                in_top, in_right, in_bottom, in_left,
                in_r0, in_r1, in_r2, in_r3):
    el_top, el_right, el_bottom, el_left = make_elements()
    dut.in_variableId.value           = variable_id
    dut.in_tileId.value               = tile_id
    dut.in_rotation.value             = rotation
    dut.in_unassigned_variables.value = in_uv
    dut.in_unassigned_tiles.value     = in_ut
    dut.in_colours_top.value          = pack_colour(in_top)
    dut.in_colours_right.value        = pack_colour(in_right)
    dut.in_colours_bottom.value       = pack_colour(in_bottom)
    dut.in_colours_left.value         = pack_colour(in_left)
    dut.in_domain_r0.value            = pack_domain(in_r0)
    dut.in_domain_r1.value            = pack_domain(in_r1)
    dut.in_domain_r2.value            = pack_domain(in_r2)
    dut.in_domain_r3.value            = pack_domain(in_r3)
    dut.in_elements_top.value         = pack_colour(el_top)
    dut.in_elements_right.value       = pack_colour(el_right)
    dut.in_elements_bottom.value      = pack_colour(el_bottom)
    dut.in_elements_left.value        = pack_colour(el_left)
    await Timer(1, unit="ns")

async def check(dut, variable_id, tile_id, rotation,
                in_uv, in_ut,
                in_top, in_right, in_bottom, in_left,
                in_r0, in_r1, in_r2, in_r3):
    await apply(dut, variable_id, tile_id, rotation,
                in_uv, in_ut,
                in_top, in_right, in_bottom, in_left,
                in_r0, in_r1, in_r2, in_r3)

    (exp_top, exp_right, exp_bottom, exp_left,
     exp_r0, exp_r1, exp_r2, exp_r3,
     exp_uv, exp_ut) = reference(
        variable_id, tile_id, rotation,
        in_uv, in_ut,
        in_top, in_right, in_bottom, in_left,
        in_r0, in_r1, in_r2, in_r3)

    act_top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    act_right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    act_bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    act_left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    act_r0     = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    act_r1     = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    act_r2     = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    act_r3     = unpack_domain(dut.out_domain_r3.value.to_unsigned())
    act_uv     = int(dut.out_unassigned_variables.value)
    act_ut     = int(dut.out_unassigned_tiles.value)

    for v in range(V):
        assert act_top[v]    == exp_top[v],    \
            f"top[{v}]={act_top[v]:06b} exp={exp_top[v]:06b}"
        assert act_right[v]  == exp_right[v],  \
            f"right[{v}]={act_right[v]:06b} exp={exp_right[v]:06b}"
        assert act_bottom[v] == exp_bottom[v], \
            f"bottom[{v}]={act_bottom[v]:06b} exp={exp_bottom[v]:06b}"
        assert act_left[v]   == exp_left[v],   \
            f"left[{v}]={act_left[v]:06b} exp={exp_left[v]:06b}"
        assert act_r0[v] == exp_r0[v], \
            f"r0[{v}]={act_r0[v]:016b} exp={exp_r0[v]:016b}"
        assert act_r1[v] == exp_r1[v], \
            f"r1[{v}]={act_r1[v]:016b} exp={exp_r1[v]:016b}"
        assert act_r2[v] == exp_r2[v], \
            f"r2[{v}]={act_r2[v]:016b} exp={exp_r2[v]:016b}"
        assert act_r3[v] == exp_r3[v], \
            f"r3[{v}]={act_r3[v]:016b} exp={exp_r3[v]:016b}"

    assert act_uv == exp_uv, \
        f"unassigned_variables={act_uv:#x} exp={exp_uv:#x}"
    assert act_ut == exp_ut, \
        f"unassigned_tiles={act_ut:#x} exp={exp_ut:#x}"

def full_colours(): return [CC_MASK] * V
def full_domains(): return [ALL_DOM] * V
def full_mask():    return ALL_DOM

@cocotb.test()
async def test_domain_locked_r0(dut):
    """Assigned variable's domain is locked to one tile in rotation 0."""
    await check(dut, 5, 3, 0, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    act_r0 = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    act_r2 = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    act_r3 = unpack_domain(dut.out_domain_r3.value.to_unsigned())
    assert act_r0[5] == (1 << 3), "r0 should have only tile 3"
    assert act_r1[5] == 0,        "r1 should be zero"
    assert act_r2[5] == 0,        "r2 should be zero"
    assert act_r3[5] == 0,        "r3 should be zero"
    cocotb.log.info("domain locked rotation 0 ✓")

@cocotb.test()
async def test_domain_locked_r1(dut):
    """Assigned variable's domain is locked to one tile in rotation 1."""
    await check(dut, 5, 3, 1, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    act_r0 = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    act_r1 = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    assert act_r0[5] == 0,        "r0 should be zero"
    assert act_r1[5] == (1 << 3), "r1 should have only tile 3"
    cocotb.log.info("domain locked rotation 1 ✓")

@cocotb.test()
async def test_own_colours_set(dut):
    """Assigned variable's colours match piece pattern at chosen rotation."""
    tile_id  = 5
    rotation = 2
    await check(dut, 6, tile_id, rotation, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    exp_t, exp_r, exp_b, exp_l = piece_colours(tile_id, rotation)
    act_top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    act_right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    act_bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    act_left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    assert act_top[6]    == exp_t, f"top mismatch got={act_top[6]:06b} exp={exp_t:06b}"
    assert act_right[6]  == exp_r, f"right mismatch"
    assert act_bottom[6] == exp_b, f"bottom mismatch"
    assert act_left[6]   == exp_l, f"left mismatch"
    cocotb.log.info("own colours set ✓")

@cocotb.test()
async def test_neighbour_colours_updated(dut):
    """Inner variable — all four neighbours get colour constraints applied."""
    await check(dut, 5, 0, 0, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("neighbour colours updated ✓")

@cocotb.test()
async def test_top_left_corner_safe(dut):
    """Top-left corner (var 0) — no up or left neighbours, no out-of-bounds access."""
    await check(dut, 0, 0, 1, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("top-left corner safe ✓")

@cocotb.test()
async def test_bottom_right_corner_safe(dut):
    """Bottom-right corner (var V-1) — no right or down neighbours."""
    await check(dut, V-1, 1, 3, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("bottom-right corner safe ✓")

@cocotb.test()
async def test_top_right_corner_safe(dut):
    """Top-right corner (var N-1) — no up or right neighbours."""
    await check(dut, N-1, 2, 2, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("top-right corner safe ✓")

@cocotb.test()
async def test_bottom_left_corner_safe(dut):
    """Bottom-left corner (var N*(N-1)) — no left or down neighbours."""
    await check(dut, N*(N-1), 3, 0, full_mask(), full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    cocotb.log.info("bottom-left corner safe ✓")

@cocotb.test()
async def test_unassigned_variable_bit_cleared(dut):
    """Assigned variable's bit is cleared in out_unassigned_variables."""
    in_uv = full_mask()
    await check(dut, 5, 3, 0, in_uv, full_mask(),
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    act_uv = int(dut.out_unassigned_variables.value)
    assert not (act_uv >> 5) & 1, "var 5 bit should be cleared"
    assert (act_uv >> 4) & 1,     "var 4 bit should still be set"
    cocotb.log.info("unassigned variable bit cleared ✓")

@cocotb.test()
async def test_unassigned_tile_bit_cleared(dut):
    """Assigned tile's bit is cleared in out_unassigned_tiles."""
    in_ut = full_mask()
    await check(dut, 5, 7, 0, full_mask(), in_ut,
                full_colours(), full_colours(),
                full_colours(), full_colours(),
                full_domains(), full_domains(),
                full_domains(), full_domains())
    act_ut = int(dut.out_unassigned_tiles.value)
    assert not (act_ut >> 7) & 1, "tile 7 bit should be cleared"
    assert (act_ut >> 6) & 1,     "tile 6 bit should still be set"
    cocotb.log.info("unassigned tile bit cleared ✓")

@cocotb.test()
async def test_other_variables_unchanged(dut):
    """Variables other than the assigned one and its neighbours are unchanged.
    After AllDifferent_Simple the placed tile (tile 1) is removed from all
    remaining unassigned variables' domains so we expect ALL_DOM minus tile 1.
    """
    c   = full_colours()
    r   = full_domains()
    uv  = full_mask()
    ut  = full_mask()
    await check(dut, 0, 1, 1, uv, ut, c, c, c, c, r, r, r, r)
    act_r0  = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    exp_dom = ALL_DOM & ~(1 << 1)  # tile 1 cleared by AllDifferent_Simple
    for v in range(2, V):
        if v != N:  # var N is below var 0 — skip
            assert act_r0[v] == exp_dom, \
                f"var {v} domain should be ALL_DOM minus tile 1, got {act_r0[v]:#x}"
    cocotb.log.info("other variables unchanged ✓")

@cocotb.test()
async def test_random(dut):
    """30 random assignments verified against reference."""
    random.seed(55)
    r  = full_domains()
    uv = full_mask()
    ut = full_mask()
    for _ in range(30):
        vid = random.randint(0, V-1)
        tid = random.randint(0, V-1)
        rot = random.randint(0, 3)
        c   = [random.randint(1, CC_MASK) for _ in range(V)]
        await check(dut, vid, tid, rot, uv, ut, c, c, c, c, r, r, r, r)
    cocotb.log.info("30 random tests ✓")





def test_Assignment():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/Assignment.sv",
                "rtl/AllDifferent_Simple.sv",
                "rtl/DomainToColour.sv",
                "rtl/DomainToColour_Rotation.sv",],
        hdl_toplevel="Assignment",
        parameters={"N": N, "CC": CC},
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"],
    )
    runner.test(
        hdl_toplevel="Assignment",
        test_module="test_Assignment",
    )