import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

N                   = 4
BORDER_COLOUR_COUNT = 3
INNER_COLOUR_COUNT  = 2
CC        = 1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT  # 6
V         = N * N
NUM_EDGES = 4 * (N - 2)
NUM_INNER = (N - 2) * (N - 2)

# ── Colour masks ──────────────────────────────────────────────
BOUNDARY = 1
BORDER   = ((1 << BORDER_COLOUR_COUNT) - 1) << 1
INNER_C  = ((1 << INNER_COLOUR_COUNT)  - 1) << (BORDER_COLOUR_COUNT + 1)
CC_MASK  = (1 << CC) - 1

# ── Domain masks ──────────────────────────────────────────────
FIXED_CORNER = 1
FREE_CORNER  = 0b1110
EDGE_D       = ((1 << NUM_EDGES) - 1) << 4
INNER_D      = ((1 << NUM_INNER) - 1) << (4 + NUM_EDGES)

def vid(x, y): return y * N + x

def unpack_colour(val):
    return [(val >> (i * CC)) & CC_MASK for i in range(V)]

def unpack_domain(val):
    return [(val >> (i * V)) & ((1 << V) - 1) for i in range(V)]

@cocotb.test()
async def test_top_left_corner(dut):
    """Variable 0 (top-left) is fixed — boundary top/left, border right/bottom, r1 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    r0     = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    r1     = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    r2     = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    r3     = unpack_domain(dut.out_domain_r3.value.to_unsigned())

    v = vid(0, 0)
    assert top[v]    == BOUNDARY,     f"top-left top={top[v]:#x}"
    assert left[v]   == BOUNDARY,     f"top-left left={left[v]:#x}"
    assert right[v]  == BORDER,       f"top-left right={right[v]:#x}"
    assert bottom[v] == BORDER,       f"top-left bottom={bottom[v]:#x}"
    assert r0[v]     == 0,            "top-left r0 should be 0"
    assert r1[v]     == FIXED_CORNER, f"top-left r1={r1[v]:#x}"
    assert r2[v]     == 0,            "top-left r2 should be 0"
    assert r3[v]     == 0,            "top-left r3 should be 0"
    cocotb.log.info("top-left corner ✓")

@cocotb.test()
async def test_top_right_corner(dut):
    """Top-right corner — boundary top/right, border left/bottom, r2 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    r0     = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    r1     = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    r2     = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    r3     = unpack_domain(dut.out_domain_r3.value.to_unsigned())

    v = vid(N-1, 0)
    assert top[v]    == BOUNDARY,    f"top-right top={top[v]:#x}"
    assert right[v]  == BOUNDARY,    f"top-right right={right[v]:#x}"
    assert left[v]   == BORDER,      f"top-right left={left[v]:#x}"
    assert bottom[v] == BORDER,      f"top-right bottom={bottom[v]:#x}"
    assert r0[v]     == 0,           "top-right r0 should be 0"
    assert r1[v]     == 0,           "top-right r1 should be 0"
    assert r2[v]     == FREE_CORNER, f"top-right r2={r2[v]:#x}"
    assert r3[v]     == 0,           "top-right r3 should be 0"
    cocotb.log.info("top-right corner ✓")

@cocotb.test()
async def test_bottom_left_corner(dut):
    """Bottom-left corner — boundary left/bottom, border right/top, r0 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    r0     = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    r1     = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    r2     = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    r3     = unpack_domain(dut.out_domain_r3.value.to_unsigned())

    v = vid(0, N-1)
    assert left[v]   == BOUNDARY,    f"bottom-left left={left[v]:#x}"
    assert bottom[v] == BOUNDARY,    f"bottom-left bottom={bottom[v]:#x}"
    assert right[v]  == BORDER,      f"bottom-left right={right[v]:#x}"
    assert top[v]    == BORDER,      f"bottom-left top={top[v]:#x}"
    assert r0[v]     == FREE_CORNER, f"bottom-left r0={r0[v]:#x}"
    assert r1[v]     == 0,           "bottom-left r1 should be 0"
    assert r2[v]     == 0,           "bottom-left r2 should be 0"
    assert r3[v]     == 0,           "bottom-left r3 should be 0"
    cocotb.log.info("bottom-left corner ✓")

@cocotb.test()
async def test_bottom_right_corner(dut):
    """Bottom-right corner — boundary right/bottom, border left/top, r3 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    r0     = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    r1     = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    r2     = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    r3     = unpack_domain(dut.out_domain_r3.value.to_unsigned())

    v = vid(N-1, N-1)
    assert right[v]  == BOUNDARY,    f"bottom-right right={right[v]:#x}"
    assert bottom[v] == BOUNDARY,    f"bottom-right bottom={bottom[v]:#x}"
    assert left[v]   == BORDER,      f"bottom-right left={left[v]:#x}"
    assert top[v]    == BORDER,      f"bottom-right top={top[v]:#x}"
    assert r0[v]     == 0,           "bottom-right r0 should be 0"
    assert r1[v]     == 0,           "bottom-right r1 should be 0"
    assert r2[v]     == 0,           "bottom-right r2 should be 0"
    assert r3[v]     == FREE_CORNER, f"bottom-right r3={r3[v]:#x}"
    cocotb.log.info("bottom-right corner ✓")

@cocotb.test()
async def test_left_edge(dut):
    """Left edge variables — boundary left, inner right, border top/bottom, r1 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    r0     = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    r1     = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    r2     = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    r3     = unpack_domain(dut.out_domain_r3.value.to_unsigned())

    for y in range(1, N-1):
        v = vid(0, y)
        assert left[v]   == BOUNDARY, f"left edge y={y} left={left[v]:#x}"
        assert right[v]  == INNER_C,  f"left edge y={y} right={right[v]:#x}"
        assert top[v]    == BORDER,   f"left edge y={y} top={top[v]:#x}"
        assert bottom[v] == BORDER,   f"left edge y={y} bottom={bottom[v]:#x}"
        assert r1[v]     == EDGE_D,   f"left edge y={y} r1={r1[v]:#x}"
        assert r0[v]     == 0,        f"left edge y={y} r0 should be 0"
        assert r2[v]     == 0,        f"left edge y={y} r2 should be 0"
        assert r3[v]     == 0,        f"left edge y={y} r3 should be 0"
    cocotb.log.info("left edge ✓")

@cocotb.test()
async def test_top_edge(dut):
    """Top edge variables — boundary top, inner bottom, border left/right, r2 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    r0     = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    r1     = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    r2     = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    r3     = unpack_domain(dut.out_domain_r3.value.to_unsigned())

    for x in range(1, N-1):
        v = vid(x, 0)
        assert top[v]    == BOUNDARY, f"top edge x={x} top={top[v]:#x}"
        assert bottom[v] == INNER_C,  f"top edge x={x} bottom={bottom[v]:#x}"
        assert left[v]   == BORDER,   f"top edge x={x} left={left[v]:#x}"
        assert right[v]  == BORDER,   f"top edge x={x} right={right[v]:#x}"
        assert r2[v]     == EDGE_D,   f"top edge x={x} r2={r2[v]:#x}"
        assert r0[v]     == 0,        f"top edge x={x} r0 should be 0"
        assert r1[v]     == 0,        f"top edge x={x} r1 should be 0"
        assert r3[v]     == 0,        f"top edge x={x} r3 should be 0"
    cocotb.log.info("top edge ✓")

@cocotb.test()
async def test_bottom_edge(dut):
    """Bottom edge variables — boundary bottom, inner top, border left/right, r0 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    r0     = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    r1     = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    r2     = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    r3     = unpack_domain(dut.out_domain_r3.value.to_unsigned())

    for x in range(1, N-1):
        v = vid(x, N-1)
        assert bottom[v] == BOUNDARY, f"bottom edge x={x} bottom={bottom[v]:#x}"
        assert top[v]    == INNER_C,  f"bottom edge x={x} top={top[v]:#x}"
        assert left[v]   == BORDER,   f"bottom edge x={x} left={left[v]:#x}"
        assert right[v]  == BORDER,   f"bottom edge x={x} right={right[v]:#x}"
        assert r0[v]     == EDGE_D,   f"bottom edge x={x} r0={r0[v]:#x}"
        assert r1[v]     == 0,        f"bottom edge x={x} r1 should be 0"
        assert r2[v]     == 0,        f"bottom edge x={x} r2 should be 0"
        assert r3[v]     == 0,        f"bottom edge x={x} r3 should be 0"
    cocotb.log.info("bottom edge ✓")

@cocotb.test()
async def test_right_edge(dut):
    """Right edge variables — boundary right, inner left, border top/bottom, r3 only."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    r0     = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    r1     = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    r2     = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    r3     = unpack_domain(dut.out_domain_r3.value.to_unsigned())

    for y in range(1, N-1):
        v = vid(N-1, y)
        assert right[v]  == BOUNDARY, f"right edge y={y} right={right[v]:#x}"
        assert left[v]   == INNER_C,  f"right edge y={y} left={left[v]:#x}"
        assert top[v]    == BORDER,   f"right edge y={y} top={top[v]:#x}"
        assert bottom[v] == BORDER,   f"right edge y={y} bottom={bottom[v]:#x}"
        assert r3[v]     == EDGE_D,   f"right edge y={y} r3={r3[v]:#x}"
        assert r0[v]     == 0,        f"right edge y={y} r0 should be 0"
        assert r1[v]     == 0,        f"right edge y={y} r1 should be 0"
        assert r2[v]     == 0,        f"right edge y={y} r2 should be 0"
    cocotb.log.info("right edge ✓")

@cocotb.test()
async def test_inner_variables(dut):
    """Inner variables — all inner colours, all rotations with inner domain."""
    await Timer(1, unit="ns")
    top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    r0     = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    r1     = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    r2     = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    r3     = unpack_domain(dut.out_domain_r3.value.to_unsigned())

    for y in range(1, N-1):
        for x in range(1, N-1):
            v = vid(x, y)
            assert top[v]    == INNER_C, f"inner x={x},y={y} top={top[v]:#x}"
            assert right[v]  == INNER_C, f"inner x={x},y={y} right={right[v]:#x}"
            assert bottom[v] == INNER_C, f"inner x={x},y={y} bottom={bottom[v]:#x}"
            assert left[v]   == INNER_C, f"inner x={x},y={y} left={left[v]:#x}"
            assert r0[v]     == INNER_D, f"inner x={x},y={y} r0={r0[v]:#x}"
            assert r1[v]     == INNER_D, f"inner x={x},y={y} r1={r1[v]:#x}"
            assert r2[v]     == INNER_D, f"inner x={x},y={y} r2={r2[v]:#x}"
            assert r3[v]     == INNER_D, f"inner x={x},y={y} r3={r3[v]:#x}"
    cocotb.log.info("inner variables ✓")

@cocotb.test()
async def test_unassigned_masks(dut):
    """Variable 0 is placed — all others unassigned.
    unassignedVariables and unassignedTiles have all bits set except bit 0."""
    await Timer(1, unit="ns")
    uv       = int(dut.out_unassignedVariables.value)
    ut       = int(dut.out_unassignedTiles.value)
    expected = ((1 << V) - 1) & ~1  # 0xfffe for V=16
    assert uv == expected, f"out_unassignedVariables={uv:#x} expected={expected:#x}"
    assert ut == expected, f"out_unassignedTiles={ut:#x} expected={expected:#x}"
    cocotb.log.info("unassigned masks ✓")

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