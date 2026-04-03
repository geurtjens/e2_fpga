import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

N = 3
VARIABLES = N * N
TC = 5

# Piece patterns at rotation 0 (top right bottom left)
# From the header comments
PIECES_R0 = [
    # top        right      bottom     left
    (0b00010, 0b00010, 0b00001, 0b00001),  # 0: aaxx  wait - using RTL as truth
]

# Colour encoding
X = 0b00001  # boundary
A = 0b00010
B = 0b00100
C = 0b01000
D = 0b10000

# Rotation 0 patterns from comments: t r b l
# 0:aaxx, 1:abxx, 2:baxx, 3:bbxx, 4:cbxa, 5:daxa, 6:caxb, 7:dbxb, 8:ccdd
R0 = [
    # top  right  bottom  left
    (A,    A,     X,      X),   # 0
    (A,    B,     X,      X),   # 1
    (B,    A,     X,      X),   # 2
    (B,    B,     X,      X),   # 3
    (C,    B,     X,      A),   # 4
    (D,    A,     X,      A),   # 5
    (C,    A,     X,      B),   # 6
    (D,    B,     X,      B),   # 7
    (C,    C,     D,      D),   # 8
]

def rotate_cw(top, right, bottom, left):
    """One clockwise rotation: left→top, top→right, right→bottom, bottom→left."""
    return left, top, right, bottom

def expected_rotation(r0_patterns, n_rotations):
    """Apply n_rotations clockwise rotations to all pieces."""
    result = list(r0_patterns)
    for _ in range(n_rotations):
        result = [rotate_cw(*p) for p in result]
    return result

def unpack_colour_array(val, n, tc):
    tc_mask = (1 << tc) - 1
    return [(val >> (i * tc)) & tc_mask for i in range(n)]

@cocotb.test()
async def test_rotation0_matches_spec(dut):
    """Rotation 0 patterns match the piece spec from comments."""
    await Timer(1, unit="ns")
    tc_mask = (1 << TC) - 1

    act_top    = unpack_colour_array(dut.p0_top.value.to_unsigned(),    VARIABLES, TC)
    act_right  = unpack_colour_array(dut.p0_right.value.to_unsigned(),  VARIABLES, TC)
    act_bottom = unpack_colour_array(dut.p0_bottom.value.to_unsigned(), VARIABLES, TC)
    act_left   = unpack_colour_array(dut.p0_left.value.to_unsigned(),   VARIABLES, TC)

    for p, (exp_t, exp_r, exp_b, exp_l) in enumerate(R0):
        assert act_top[p]    == exp_t, f"p{p} r0 top={act_top[p]:05b} expected={exp_t:05b}"
        assert act_right[p]  == exp_r, f"p{p} r0 right={act_right[p]:05b} expected={exp_r:05b}"
        assert act_bottom[p] == exp_b, f"p{p} r0 bottom={act_bottom[p]:05b} expected={exp_b:05b}"
        assert act_left[p]   == exp_l, f"p{p} r0 left={act_left[p]:05b} expected={exp_l:05b}"
    cocotb.log.info("rotation 0 matches spec ✓")

@cocotb.test()
async def test_rotation1_consistent(dut):
    """Rotation 1 is rotation 0 rotated clockwise once."""
    await Timer(1, unit="ns")
    exp = expected_rotation(R0, 1)

    act_top    = unpack_colour_array(dut.p1_top.value.to_unsigned(),    VARIABLES, TC)
    act_right  = unpack_colour_array(dut.p1_right.value.to_unsigned(),  VARIABLES, TC)
    act_bottom = unpack_colour_array(dut.p1_bottom.value.to_unsigned(), VARIABLES, TC)
    act_left   = unpack_colour_array(dut.p1_left.value.to_unsigned(),   VARIABLES, TC)

    for p, (exp_t, exp_r, exp_b, exp_l) in enumerate(exp):
        assert act_top[p]    == exp_t, f"p{p} r1 top={act_top[p]:05b} expected={exp_t:05b}"
        assert act_right[p]  == exp_r, f"p{p} r1 right={act_right[p]:05b} expected={exp_r:05b}"
        assert act_bottom[p] == exp_b, f"p{p} r1 bottom={act_bottom[p]:05b} expected={exp_b:05b}"
        assert act_left[p]   == exp_l, f"p{p} r1 left={act_left[p]:05b} expected={exp_l:05b}"
    cocotb.log.info("rotation 1 consistent ✓")

@cocotb.test()
async def test_rotation2_consistent(dut):
    """Rotation 2 is rotation 0 rotated clockwise twice."""
    await Timer(1, unit="ns")
    exp = expected_rotation(R0, 2)

    act_top    = unpack_colour_array(dut.p2_top.value.to_unsigned(),    VARIABLES, TC)
    act_right  = unpack_colour_array(dut.p2_right.value.to_unsigned(),  VARIABLES, TC)
    act_bottom = unpack_colour_array(dut.p2_bottom.value.to_unsigned(), VARIABLES, TC)
    act_left   = unpack_colour_array(dut.p2_left.value.to_unsigned(),   VARIABLES, TC)

    for p, (exp_t, exp_r, exp_b, exp_l) in enumerate(exp):
        assert act_top[p]    == exp_t, f"p{p} r2 top={act_top[p]:05b} expected={exp_t:05b}"
        assert act_right[p]  == exp_r, f"p{p} r2 right"
        assert act_bottom[p] == exp_b, f"p{p} r2 bottom"
        assert act_left[p]   == exp_l, f"p{p} r2 left"
    cocotb.log.info("rotation 2 consistent ✓")

@cocotb.test()
async def test_rotation3_consistent(dut):
    """Rotation 3 is rotation 0 rotated clockwise three times."""
    await Timer(1, unit="ns")
    exp = expected_rotation(R0, 3)

    act_top    = unpack_colour_array(dut.p3_top.value.to_unsigned(),    VARIABLES, TC)
    act_right  = unpack_colour_array(dut.p3_right.value.to_unsigned(),  VARIABLES, TC)
    act_bottom = unpack_colour_array(dut.p3_bottom.value.to_unsigned(), VARIABLES, TC)
    act_left   = unpack_colour_array(dut.p3_left.value.to_unsigned(),   VARIABLES, TC)

    for p, (exp_t, exp_r, exp_b, exp_l) in enumerate(exp):
        assert act_top[p]    == exp_t, f"p{p} r3 top={act_top[p]:05b} expected={exp_t:05b}"
        assert act_right[p]  == exp_r, f"p{p} r3 right"
        assert act_bottom[p] == exp_b, f"p{p} r3 bottom"
        assert act_left[p]   == exp_l, f"p{p} r3 left"
    cocotb.log.info("rotation 3 consistent ✓")

@cocotb.test()
async def test_four_rotations_cycle(dut):
    """Four rotations of any piece returns to rotation 0."""
    await Timer(1, unit="ns")
    exp = expected_rotation(R0, 4)
    # Should equal R0
    for p, (e, r) in enumerate(zip(exp, R0)):
        assert e == r, f"piece {p} 4-rotation cycle failed"
    cocotb.log.info("4-rotation cycle ✓")

def test_Brendan3():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/Brendan3.sv"],
        hdl_toplevel="Brendan3",
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="Brendan3",
        test_module="test_Brendan3",
    )