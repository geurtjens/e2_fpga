import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

N = 4
TC = 6
VARIABLES = N * N

# Colour encoding
X = 0b000001
A = 0b000010
B = 0b000100
C = 0b001000
D = 0b010000
E = 0b100000

# Piece patterns at rotation 0 (top, right, bottom, left)
# From comments: 0:aaxx 1:abxx 2:baxx 3:bbxx
#                4:caxa 5:cbxa 6:daxa 7:ebxa
#                8:daxb 9:dbxb 10:eaxb 11:ebxb
#               12:ccee 13:cdce 14:cddd 15:ceed
R0 = [
    (A, A, X, X),   # 0
    (A, B, X, X),   # 1
    (B, A, X, X),   # 2
    (B, B, X, X),   # 3
    (C, A, X, A),   # 4
    (C, B, X, A),   # 5
    (D, A, X, A),   # 6
    (E, B, X, A),   # 7
    (D, A, X, B),   # 8
    (D, B, X, B),   # 9
    (E, A, X, B),   # 10
    (E, B, X, B),   # 11
    (C, C, E, E),   # 12
    (C, D, C, E),   # 13
    (C, D, D, D),   # 14
    (C, E, E, D),   # 15
]

def rotate_cw(top, right, bottom, left):
    """One clockwise rotation: left→top, top→right, right→bottom, bottom→left."""
    return left, top, right, bottom

def expected_rotation(r0_patterns, n_rotations):
    result = list(r0_patterns)
    for _ in range(n_rotations):
        result = [rotate_cw(*p) for p in result]
    return result

def unpack_colour_array(val):
    tc_mask = (1 << TC) - 1
    return [(val >> (i * TC)) & tc_mask for i in range(VARIABLES)]

def check_rotation(act_top, act_right, act_bottom, act_left, exp, rot_name):
    for p, (exp_t, exp_r, exp_b, exp_l) in enumerate(exp):
        assert act_top[p]    == exp_t, f"p{p} {rot_name} top={act_top[p]:06b} expected={exp_t:06b}"
        assert act_right[p]  == exp_r, f"p{p} {rot_name} right={act_right[p]:06b} expected={exp_r:06b}"
        assert act_bottom[p] == exp_b, f"p{p} {rot_name} bottom={act_bottom[p]:06b} expected={exp_b:06b}"
        assert act_left[p]   == exp_l, f"p{p} {rot_name} left={act_left[p]:06b} expected={exp_l:06b}"

@cocotb.test()
async def test_rotation0(dut):
    """Rotation 0 matches piece spec."""
    await Timer(1, unit="ns")
    check_rotation(
        unpack_colour_array(dut.p0_top.value.to_unsigned()),
        unpack_colour_array(dut.p0_right.value.to_unsigned()),
        unpack_colour_array(dut.p0_bottom.value.to_unsigned()),
        unpack_colour_array(dut.p0_left.value.to_unsigned()),
        R0, "r0")
    cocotb.log.info("rotation 0 ✓")

@cocotb.test()
async def test_rotation1(dut):
    """Rotation 1 is rotation 0 rotated clockwise once."""
    await Timer(1, unit="ns")
    check_rotation(
        unpack_colour_array(dut.p1_top.value.to_unsigned()),
        unpack_colour_array(dut.p1_right.value.to_unsigned()),
        unpack_colour_array(dut.p1_bottom.value.to_unsigned()),
        unpack_colour_array(dut.p1_left.value.to_unsigned()),
        expected_rotation(R0, 1), "r1")
    cocotb.log.info("rotation 1 ✓")

@cocotb.test()
async def test_rotation2(dut):
    """Rotation 2 is rotation 0 rotated clockwise twice."""
    await Timer(1, unit="ns")
    check_rotation(
        unpack_colour_array(dut.p2_top.value.to_unsigned()),
        unpack_colour_array(dut.p2_right.value.to_unsigned()),
        unpack_colour_array(dut.p2_bottom.value.to_unsigned()),
        unpack_colour_array(dut.p2_left.value.to_unsigned()),
        expected_rotation(R0, 2), "r2")
    cocotb.log.info("rotation 2 ✓")

@cocotb.test()
async def test_rotation3(dut):
    """Rotation 3 is rotation 0 rotated clockwise three times."""
    await Timer(1, unit="ns")
    check_rotation(
        unpack_colour_array(dut.p3_top.value.to_unsigned()),
        unpack_colour_array(dut.p3_right.value.to_unsigned()),
        unpack_colour_array(dut.p3_bottom.value.to_unsigned()),
        unpack_colour_array(dut.p3_left.value.to_unsigned()),
        expected_rotation(R0, 3), "r3")
    cocotb.log.info("rotation 3 ✓")

@cocotb.test()
async def test_four_rotation_cycle(dut):
    """Four clockwise rotations returns to rotation 0."""
    await Timer(1, unit="ns")
    exp = expected_rotation(R0, 4)
    for p, (e, r) in enumerate(zip(exp, R0)):
        assert e == r, f"piece {p} 4-rotation cycle failed"
    cocotb.log.info("4-rotation cycle ✓")

@cocotb.test()
async def test_border_pieces_have_boundary_colour(dut):
    """Pieces 0-11 (non-inner) have boundary colour X on two edges."""
    await Timer(1, unit="ns")
    top    = unpack_colour_array(dut.p0_top.value.to_unsigned())
    right  = unpack_colour_array(dut.p0_right.value.to_unsigned())
    bottom = unpack_colour_array(dut.p0_bottom.value.to_unsigned())
    left   = unpack_colour_array(dut.p0_left.value.to_unsigned())
    for p in range(12):
        edges = [top[p], right[p], bottom[p], left[p]]
        x_count = sum(1 for e in edges if e == X)
        assert x_count >= 1, f"piece {p} has no boundary colour"
    cocotb.log.info("border pieces have boundary colour ✓")

@cocotb.test()
async def test_inner_pieces_no_boundary_colour(dut):
    """Pieces 12-15 (inner) have no boundary colour X."""
    await Timer(1, unit="ns")
    top    = unpack_colour_array(dut.p0_top.value.to_unsigned())
    right  = unpack_colour_array(dut.p0_right.value.to_unsigned())
    bottom = unpack_colour_array(dut.p0_bottom.value.to_unsigned())
    left   = unpack_colour_array(dut.p0_left.value.to_unsigned())
    for p in range(12, 16):
        edges = [top[p], right[p], bottom[p], left[p]]
        assert X not in edges, f"piece {p} has boundary colour but should be inner"
    cocotb.log.info("inner pieces have no boundary colour ✓")

def test_Brendan4():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/Brendan4.sv"],
        hdl_toplevel="Brendan4",
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="Brendan4",
        test_module="test_Brendan4",
    )