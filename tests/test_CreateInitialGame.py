import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

N = 4
BORDER_COLOUR_COUNT = 3
INNER_COLOUR_COUNT  = 2
TC        = 1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT  # 6
VARIABLES = N * N
NUM_EDGES = 4 * (N - 2)
NUM_INNER = (N - 2) * (N - 2)

# Colour masks
BOUNDARY = 1
BORDER   = ((1 << BORDER_COLOUR_COUNT) - 1) << 1
INNER_C  = ((1 << INNER_COLOUR_COUNT)  - 1) << (BORDER_COLOUR_COUNT + 1)
TC_MASK  = (1 << TC) - 1

# Domain masks
FIXED_CORNER = 1
FREE_CORNER  = 0b1110
EDGE_D       = ((1 << NUM_EDGES) - 1) << 4
INNER_D      = ((1 << NUM_INNER) - 1) << (4 + NUM_EDGES)

def vid(x, y): return y * N + x

def unpack_colour(val):
    return [(val >> (i * TC)) & TC_MASK for i in range(VARIABLES)]

def unpack_domain(val):
    return [(val >> (i * VARIABLES)) & ((1 << VARIABLES) - 1) for i in range(VARIABLES)]

@cocotb.test()
async def test_top_left_corner(dut):
    """Variable 0 (top-left) is fixed — boundary top/left, border right/bottom, r1 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.top.value.to_unsigned())
    right  = unpack_colour(dut.right.value.to_unsigned())
    bottom = unpack_colour(dut.bottom.value.to_unsigned())
    left   = unpack_colour(dut.left.value.to_unsigned())
    r0     = unpack_domain(dut.r0.value.to_unsigned())
    r1     = unpack_domain(dut.r1.value.to_unsigned())
    r2     = unpack_domain(dut.r2.value.to_unsigned())
    r3     = unpack_domain(dut.r3.value.to_unsigned())

    v = vid(0, 0)
    assert top[v]    == BOUNDARY, f"top-left top={top[v]:#x}"
    assert left[v]   == BOUNDARY, f"top-left left={left[v]:#x}"
    assert right[v]  == BORDER,   f"top-left right={right[v]:#x}"
    assert bottom[v] == BORDER,   f"top-left bottom={bottom[v]:#x}"
    assert r0[v] == 0,            "top-left r0 should be 0"
    assert r1[v] == FIXED_CORNER, f"top-left r1={r1[v]:#x}"
    assert r2[v] == 0,            "top-left r2 should be 0"
    assert r3[v] == 0,            "top-left r3 should be 0"
    cocotb.log.info("top-left corner ✓")

@cocotb.test()
async def test_top_right_corner(dut):
    """Top-right corner — boundary top/right, border left/bottom, all rotations free."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.top.value.to_unsigned())
    right  = unpack_colour(dut.right.value.to_unsigned())
    bottom = unpack_colour(dut.bottom.value.to_unsigned())
    left   = unpack_colour(dut.left.value.to_unsigned())
    r0     = unpack_domain(dut.r0.value.to_unsigned())
    r1     = unpack_domain(dut.r1.value.to_unsigned())
    r2     = unpack_domain(dut.r2.value.to_unsigned())
    r3     = unpack_domain(dut.r3.value.to_unsigned())

    v = vid(N-1, 0)
    assert top[v]    == BOUNDARY,    f"top-right top"
    assert right[v]  == BOUNDARY,    f"top-right right"
    assert left[v]   == BORDER,      f"top-right left"
    assert bottom[v] == BORDER,      f"top-right bottom"
    assert r0[v] == FREE_CORNER
    assert r1[v] == FREE_CORNER
    assert r2[v] == FREE_CORNER
    assert r3[v] == FREE_CORNER
    cocotb.log.info("top-right corner ✓")

@cocotb.test()
async def test_bottom_left_corner(dut):
    """Bottom-left corner — boundary left/bottom, border right/top."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.top.value.to_unsigned())
    right  = unpack_colour(dut.right.value.to_unsigned())
    bottom = unpack_colour(dut.bottom.value.to_unsigned())
    left   = unpack_colour(dut.left.value.to_unsigned())
    r0     = unpack_domain(dut.r0.value.to_unsigned())

    v = vid(0, N-1)
    assert left[v]   == BOUNDARY
    assert bottom[v] == BOUNDARY
    assert right[v]  == BORDER
    assert top[v]    == BORDER
    assert r0[v] == FREE_CORNER
    cocotb.log.info("bottom-left corner ✓")

@cocotb.test()
async def test_bottom_right_corner(dut):
    """Bottom-right corner — boundary right/bottom, border left/top."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.top.value.to_unsigned())
    right  = unpack_colour(dut.right.value.to_unsigned())
    bottom = unpack_colour(dut.bottom.value.to_unsigned())
    left   = unpack_colour(dut.left.value.to_unsigned())

    v = vid(N-1, N-1)
    assert right[v]  == BOUNDARY
    assert bottom[v] == BOUNDARY
    assert left[v]   == BORDER
    assert top[v]    == BORDER
    cocotb.log.info("bottom-right corner ✓")

@cocotb.test()
async def test_left_edge(dut):
    """Left edge variables — boundary left, inner right, border top/bottom, r1 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.top.value.to_unsigned())
    right  = unpack_colour(dut.right.value.to_unsigned())
    bottom = unpack_colour(dut.bottom.value.to_unsigned())
    left   = unpack_colour(dut.left.value.to_unsigned())
    r1     = unpack_domain(dut.r1.value.to_unsigned())
    r0     = unpack_domain(dut.r0.value.to_unsigned())

    for y in range(1, N-1):
        v = vid(0, y)
        assert left[v]   == BOUNDARY, f"left edge y={y} left"
        assert right[v]  == INNER_C,  f"left edge y={y} right"
        assert top[v]    == BORDER,   f"left edge y={y} top"
        assert bottom[v] == BORDER,   f"left edge y={y} bottom"
        assert r1[v] == EDGE_D,       f"left edge y={y} r1"
        assert r0[v] == 0,            f"left edge y={y} r0 should be 0"
    cocotb.log.info("left edge ✓")

@cocotb.test()
async def test_top_edge(dut):
    """Top edge variables — boundary top, inner bottom, border left/right, r1 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.top.value.to_unsigned())
    right  = unpack_colour(dut.right.value.to_unsigned())
    bottom = unpack_colour(dut.bottom.value.to_unsigned())
    left   = unpack_colour(dut.left.value.to_unsigned())
    r1     = unpack_domain(dut.r1.value.to_unsigned())

    for x in range(1, N-1):
        v = vid(x, 0)
        assert top[v]    == BOUNDARY, f"top edge x={x} top"
        assert bottom[v] == INNER_C,  f"top edge x={x} bottom"
        assert left[v]   == BORDER,   f"top edge x={x} left"
        assert right[v]  == BORDER,   f"top edge x={x} right"
        assert r1[v] == EDGE_D,       f"top edge x={x} r1"
    cocotb.log.info("top edge ✓")

@cocotb.test()
async def test_bottom_edge(dut):
    """Bottom edge variables — boundary bottom, inner top, border left/right, r0 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.top.value.to_unsigned())
    bottom = unpack_colour(dut.bottom.value.to_unsigned())
    left   = unpack_colour(dut.left.value.to_unsigned())
    right  = unpack_colour(dut.right.value.to_unsigned())
    r0     = unpack_domain(dut.r0.value.to_unsigned())
    r1     = unpack_domain(dut.r1.value.to_unsigned())

    for x in range(1, N-1):
        v = vid(x, N-1)
        assert bottom[v] == BOUNDARY, f"bottom edge x={x} bottom"
        assert top[v]    == INNER_C,  f"bottom edge x={x} top"
        assert left[v]   == BORDER,   f"bottom edge x={x} left"
        assert right[v]  == BORDER,   f"bottom edge x={x} right"
        assert r0[v] == EDGE_D,       f"bottom edge x={x} r0"
        assert r1[v] == 0,            f"bottom edge x={x} r1 should be 0"
    cocotb.log.info("bottom edge ✓")

@cocotb.test()
async def test_right_edge(dut):
    """Right edge variables — boundary right, inner left, border top/bottom, r3 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.top.value.to_unsigned())
    right  = unpack_colour(dut.right.value.to_unsigned())
    bottom = unpack_colour(dut.bottom.value.to_unsigned())
    left   = unpack_colour(dut.left.value.to_unsigned())
    r3     = unpack_domain(dut.r3.value.to_unsigned())
    r0     = unpack_domain(dut.r0.value.to_unsigned())

    for y in range(1, N-1):
        v = vid(N-1, y)
        assert right[v]  == BOUNDARY, f"right edge y={y} right"
        assert left[v]   == INNER_C,  f"right edge y={y} left"
        assert top[v]    == BORDER,   f"right edge y={y} top"
        assert bottom[v] == BORDER,   f"right edge y={y} bottom"
        assert r3[v] == EDGE_D,       f"right edge y={y} r3"
        assert r0[v] == 0,            f"right edge y={y} r0 should be 0"
    cocotb.log.info("right edge ✓")

@cocotb.test()
async def test_inner_variables(dut):
    """Inner variables — all inner colours, all rotations with inner domain."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.top.value.to_unsigned())
    right  = unpack_colour(dut.right.value.to_unsigned())
    bottom = unpack_colour(dut.bottom.value.to_unsigned())
    left   = unpack_colour(dut.left.value.to_unsigned())
    r0     = unpack_domain(dut.r0.value.to_unsigned())
    r1     = unpack_domain(dut.r1.value.to_unsigned())
    r2     = unpack_domain(dut.r2.value.to_unsigned())
    r3     = unpack_domain(dut.r3.value.to_unsigned())

    for y in range(1, N-1):
        for x in range(1, N-1):
            v = vid(x, y)
            assert top[v]    == INNER_C, f"inner x={x},y={y} top"
            assert right[v]  == INNER_C, f"inner x={x},y={y} right"
            assert bottom[v] == INNER_C, f"inner x={x},y={y} bottom"
            assert left[v]   == INNER_C, f"inner x={x},y={y} left"
            assert r0[v] == INNER_D,     f"inner x={x},y={y} r0"
            assert r1[v] == INNER_D,     f"inner x={x},y={y} r1"
            assert r2[v] == INNER_D,     f"inner x={x},y={y} r2"
            assert r3[v] == INNER_D,     f"inner x={x},y={y} r3"
    cocotb.log.info("inner variables ✓")

@cocotb.test()
async def test_variables_included_mask(dut):
    """Only variable 0 is placed — variablesIncludedMask has only bit 0 set."""
    await Timer(1, unit="ns")
    vim = int(dut.variablesIncludedMask.value)
    assert vim == 1, f"variablesIncludedMask={vim:#x} expected=0x1"
    cocotb.log.info("variablesIncludedMask ✓")

def test_CreateInitialGame():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/CreateInitialGame.sv"],
        hdl_toplevel="CreateInitialGame",
        parameters={"N": N,
                    "BORDER_COLOUR_COUNT": BORDER_COLOUR_COUNT,
                    "INNER_COLOUR_COUNT":  INNER_COLOUR_COUNT},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="CreateInitialGame",
        test_module="test_CreateInitialGame",
    )