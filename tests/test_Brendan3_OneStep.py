import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner

# ── Puzzle constants ──────────────────────────────────────────
N   = 3
V   = N * N   # 9
CC  = 5       # x=bit0 a=bit1 b=bit2 c=bit3 d=bit4
ALL = (1 << V) - 1

# ── Colour masks (matching CreateInitialGame) ─────────────────
BOUNDARY = 0b00001  # x
BORDER   = 0b00110  # a | b  (borderColours=2, bits 1..2)
INNER_C  = 0b11000  # c | d  (innerColours=2,  bits 3..4)

def unpack_domain(val):
    """Unpack a packed [V-1:0][V-1:0] domain array into a list of V ints."""
    return [(val >> (i * V)) & ALL for i in range(V)]

def unpack_colour(val):
    """Unpack a packed [V-1:0][CC-1:0] colour array into a list of V ints."""
    CC_MASK = (1 << CC) - 1
    return [(val >> (i * CC)) & CC_MASK for i in range(V)]

def popcount(x):
    return bin(x).count('1')

def vid(x, y):
    return y * N + x

@cocotb.test()
async def test_no_deadend(dut):
    """Brendan3 is solvable — full one-step pipeline should not deadend."""
    await Timer(100, unit="ns")
    assert dut.out_deadend.value == 0, \
        f"Brendan3 should not deadend after one step, got deadend=1"
    cocotb.log.info("no deadend ✓")

@cocotb.test()
async def test_valid_variable_chosen(dut):
    """ChooseNextVariable should find a valid candidate."""
    await Timer(100, unit="ns")
    assert dut.out_valid.value == 1, \
        f"ChooseNextVariable should find a valid variable, got valid=0"
    next_var = int(dut.out_next_var.value)
    assert 0 <= next_var < V, \
        f"next_var={next_var} out of range [0,{V})"
    cocotb.log.info(f"valid variable chosen: var {next_var} ✓")

@cocotb.test()
async def test_domains_shrank(dut):
    """After one step domains should be smaller than full."""
    await Timer(100, unit="ns")
    r0 = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    r1 = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    r2 = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    r3 = unpack_domain(dut.out_domain_r3.value.to_unsigned())
    any_shrank = False
    for v in range(V):
        combined = r0[v] | r1[v] | r2[v] | r3[v]
        if popcount(combined) < V:
            any_shrank = True
    assert any_shrank, "At least some domains should have shrunk after propagation"
    cocotb.log.info("domains shrank ✓")

@cocotb.test()
async def test_colours_set(dut):
    """After propagation all active variables should have non-zero colours."""
    await Timer(100, unit="ns")
    top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    left   = unpack_colour(dut.out_colours_left.value.to_unsigned())
    uv     = int(dut.out_unassigned_variables.value)
    for v in range(V):
        if (uv >> v) & 1:
            assert (top[v] | right[v] | bottom[v] | left[v]) != 0, \
                f"active variable {v} has all-zero colours — deadend"
    cocotb.log.info("all active variables have non-zero colours ✓")

@cocotb.test()
async def test_assigned_variable_locked(dut):
    """The chosen variable should have a singleton domain after assignment
    and second propagation."""
    await Timer(100, unit="ns")
    next_var = int(dut.out_next_var.value)
    r0 = unpack_domain(dut.out_domain_r0.value.to_unsigned())
    r1 = unpack_domain(dut.out_domain_r1.value.to_unsigned())
    r2 = unpack_domain(dut.out_domain_r2.value.to_unsigned())
    r3 = unpack_domain(dut.out_domain_r3.value.to_unsigned())
    combined = r0[next_var] | r1[next_var] | r2[next_var] | r3[next_var]
    assert popcount(combined) <= 1, \
        f"assigned variable {next_var} should be singleton, combined={combined:#011b}"
    cocotb.log.info(f"assigned variable {next_var} is locked ✓")

@cocotb.test()
async def test_unassigned_counts_decreased(dut):
    """After assignment and propagation fewer variables and tiles should be unassigned."""
    await Timer(100, unit="ns")
    uv = int(dut.out_unassigned_variables.value)
    ut = int(dut.out_unassigned_tiles.value)
    # started with 1 variable placed (top-left fixed), after one step at least 2
    assert popcount(uv) < V - 1, \
        f"expected fewer than {V-1} unassigned variables, got {popcount(uv)}"
    assert popcount(uv) == popcount(ut), \
        f"unassigned variables {popcount(uv)} != unassigned tiles {popcount(ut)}"
    cocotb.log.info(f"unassigned counts decreased: {popcount(uv)} variables remaining ✓")

@cocotb.test()
async def test_corner_constraints_respected(dut):
    """Corner variables should still have boundary colours on their outer edges."""
    await Timer(100, unit="ns")
    top    = unpack_colour(dut.out_colours_top.value.to_unsigned())
    right  = unpack_colour(dut.out_colours_right.value.to_unsigned())
    bottom = unpack_colour(dut.out_colours_bottom.value.to_unsigned())
    left   = unpack_colour(dut.out_colours_left.value.to_unsigned())

    # top-left corner (0,0) — top and left should be boundary
    tl = vid(0, 0)
    assert (top[tl]  & BOUNDARY) != 0, f"top-left top should include boundary"
    assert (left[tl] & BOUNDARY) != 0, f"top-left left should include boundary"

    # bottom-left corner (0,N-1) — bottom and left should be boundary
    bl = vid(0, N-1)
    assert (bottom[bl] & BOUNDARY) != 0, f"bottom-left bottom should include boundary"
    assert (left[bl]   & BOUNDARY) != 0, f"bottom-left left should include boundary"

    # top-right corner (N-1,0) — top and right should be boundary
    tr = vid(N-1, 0)
    assert (top[tr]   & BOUNDARY) != 0, f"top-right top should include boundary"
    assert (right[tr] & BOUNDARY) != 0, f"top-right right should include boundary"

    # bottom-right corner (N-1,N-1) — bottom and right should be boundary
    br = vid(N-1, N-1)
    assert (bottom[br] & BOUNDARY) != 0, f"bottom-right bottom should include boundary"
    assert (right[br]  & BOUNDARY) != 0, f"bottom-right right should include boundary"

    cocotb.log.info("corner constraints respected ✓")

def test_Brendan3_OneStep():
    runner = get_runner("verilator")
    runner.build(
        sources=[
            "rtl/Brendan3_Elements.sv",
            "rtl/CreateInitialGame.sv",
            "rtl/Brendan3_Load.sv",
            "rtl/DomainToColour_Rotation.sv",
            "rtl/DomainToColour.sv",
            "rtl/CascadeColour_Single.sv",
            "rtl/CascadeColour_Pair.sv",
            "rtl/CascadeColour.sv",
            "rtl/ColourToDomain_Rotation.sv",
            "rtl/ColourToDomain.sv",
            "rtl/AllDifferent.sv",
            "rtl/TileFrequency_Single.sv",
            "rtl/TileFrequency.sv",
            "rtl/SingletonDetection.sv",
            "rtl/PropagateOnce.sv",
            "rtl/ChooseNextVariable_ExpandSingletons.sv",
            "rtl/ChooseNextVariable_ComputeDomainSizes.sv",
            "rtl/ChooseNextVariable_FindMinimumDomain.sv",
            "rtl/ChooseNextVariable_SelectVariable.sv",
            "rtl/ChooseNextVariable.sv",
            "rtl/Assignment.sv",
            "rtl/Brendan3_OneStep.sv",
        ],
        hdl_toplevel="Brendan3_OneStep",
        build_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNOPTFLAT"],
    )
    runner.test(
        hdl_toplevel="Brendan3_OneStep",
        test_module="test_Brendan3_OneStep",
    )
