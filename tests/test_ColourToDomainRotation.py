import cocotb
from cocotb.triggers import Timer
from cocotb_tools.runner import get_runner
import random

VARIABLES = 16
TC = 6
ALL_PIECES = (1 << VARIABLES) - 1  # 0xFFFF

def reference(domain, top, right, bottom, left, p_top, p_right, p_bottom, p_left):
    """Python reference model — must match RTL exactly."""
    out = 0
    for p in range(VARIABLES):
        if (domain >> p) & 1:
            if (top    & p_top[p])    and \
               (right  & p_right[p])  and \
               (bottom & p_bottom[p]) and \
               (left   & p_left[p]):
                out |= (1 << p)
    return out

async def apply(dut, domain, top, right, bottom, left, p_top, p_right, p_bottom, p_left):
    dut.domain.value  = domain
    dut.top.value     = top
    dut.right.value   = right
    dut.bottom.value  = bottom
    dut.left.value    = left
    # Pack piece arrays into single integers — LSB = piece 0
    def pack(arr):
        val = 0
        for p in range(VARIABLES):
            val |= (arr[p] & ((1 << TC) - 1)) << (p * TC)
        return val
    dut.p_top.value    = pack(p_top)
    dut.p_right.value  = pack(p_right)
    dut.p_bottom.value = pack(p_bottom)
    dut.p_left.value   = pack(p_left)
    await Timer(1, unit="ns")

async def check(dut, domain, top, right, bottom, left, p_top, p_right, p_bottom, p_left):
    await apply(dut, domain, top, right, bottom, left, p_top, p_right, p_bottom, p_left)
    expected = reference(domain, top, right, bottom, left, p_top, p_right, p_bottom, p_left)
    assert dut.domain_out.value == expected, \
        f"domain_out={dut.domain_out.value:016b} expected={expected:016b}"
    expected_changed = int(expected != domain)
    expected_deadend = int(domain != 0 and expected == 0)
    assert dut.changed.value == expected_changed, \
        f"changed={dut.changed.value} expected={expected_changed}"
    assert dut.deadend.value == expected_deadend, \
        f"deadend={dut.deadend.value} expected={expected_deadend}"

@cocotb.test()
async def test_all_pieces_pass(dut):
    """All pieces pass when constraints are all-ones."""
    p_top    = [0b111111] * VARIABLES
    p_right  = [0b111111] * VARIABLES
    p_bottom = [0b111111] * VARIABLES
    p_left   = [0b111111] * VARIABLES
    await check(dut, ALL_PIECES, 0b111111, 0b111111, 0b111111, 0b111111,
                p_top, p_right, p_bottom, p_left)
    assert dut.changed.value == 0
    assert dut.deadend.value == 0
    cocotb.log.info("all pass ✓")

@cocotb.test()
async def test_no_pieces_pass(dut):
    """No pieces pass when constraints have no overlap with any piece."""
    p_top    = [0b000001] * VARIABLES  # piece has only bit 0
    p_right  = [0b000001] * VARIABLES
    p_bottom = [0b000001] * VARIABLES
    p_left   = [0b000001] * VARIABLES
    # constraint has no bit 0 — no overlap
    await check(dut, ALL_PIECES, 0b111110, 0b111110, 0b111110, 0b111110,
                p_top, p_right, p_bottom, p_left)
    assert dut.deadend.value == 1
    cocotb.log.info("all blocked → deadend ✓")

@cocotb.test()
async def test_empty_domain(dut):
    """Empty domain stays empty — no deadend."""
    p_top    = [0b111111] * VARIABLES
    p_right  = [0b111111] * VARIABLES
    p_bottom = [0b111111] * VARIABLES
    p_left   = [0b111111] * VARIABLES
    await check(dut, 0, 0b111111, 0b111111, 0b111111, 0b111111,
                p_top, p_right, p_bottom, p_left)
    assert dut.deadend.value == 0
    assert dut.changed.value == 0
    cocotb.log.info("empty domain ✓")

@cocotb.test()
async def test_single_piece_passes(dut):
    """Only piece 0 passes — it's the only one with matching colours."""
    p_top    = [0b000001 if p == 0 else 0b111110 for p in range(VARIABLES)]
    p_right  = [0b000001 if p == 0 else 0b111110 for p in range(VARIABLES)]
    p_bottom = [0b000001 if p == 0 else 0b111110 for p in range(VARIABLES)]
    p_left   = [0b000001 if p == 0 else 0b111110 for p in range(VARIABLES)]
    await check(dut, ALL_PIECES, 0b000001, 0b000001, 0b000001, 0b000001,
                p_top, p_right, p_bottom, p_left)
    assert dut.domain_out.value == 1  # only bit 0
    assert dut.changed.value == 1
    assert dut.deadend.value == 0
    cocotb.log.info("single piece passes ✓")

@cocotb.test()
async def test_one_edge_blocks(dut):
    """Piece fails if any single edge has no overlap."""
    p_top    = [0b111111] * VARIABLES
    p_right  = [0b111111] * VARIABLES
    p_bottom = [0b111111] * VARIABLES
    p_left   = [0b000001] * VARIABLES  # only bit 0
    # left constraint has no bit 0 — all pieces blocked on left edge
    await check(dut, ALL_PIECES, 0b111111, 0b111111, 0b111111, 0b111110,
                p_top, p_right, p_bottom, p_left)
    assert dut.deadend.value == 1
    cocotb.log.info("one edge blocks all ✓")

@cocotb.test()
async def test_piece_not_in_domain(dut):
    """Piece not in domain is not in output even if it would pass."""
    p_top    = [0b111111] * VARIABLES
    p_right  = [0b111111] * VARIABLES
    p_bottom = [0b111111] * VARIABLES
    p_left   = [0b111111] * VARIABLES
    domain   = ALL_PIECES & ~1  # exclude piece 0
    await check(dut, domain, 0b111111, 0b111111, 0b111111, 0b111111,
                p_top, p_right, p_bottom, p_left)
    assert (dut.domain_out.value.to_unsigned() & 1) == 0  # piece 0 absent
    cocotb.log.info("excluded piece stays out ✓")

@cocotb.test()
async def test_random(dut):
    """100 random inputs verified against Python reference."""
    random.seed(42)
    for i in range(100):
        domain  = random.randint(0, ALL_PIECES)
        top     = random.randint(1, (1 << TC) - 1)
        right   = random.randint(1, (1 << TC) - 1)
        bottom  = random.randint(1, (1 << TC) - 1)
        left    = random.randint(1, (1 << TC) - 1)
        p_top    = [random.randint(1, (1 << TC) - 1) for _ in range(VARIABLES)]
        p_right  = [random.randint(1, (1 << TC) - 1) for _ in range(VARIABLES)]
        p_bottom = [random.randint(1, (1 << TC) - 1) for _ in range(VARIABLES)]
        p_left   = [random.randint(1, (1 << TC) - 1) for _ in range(VARIABLES)]
        await check(dut, domain, top, right, bottom, left,
                    p_top, p_right, p_bottom, p_left)
    cocotb.log.info("100 random tests passed ✓")

def test_ColourToDomainRotation():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/ColourToDomainRotation.sv"],
        hdl_toplevel="ColourToDomainRotation",
        parameters={"VARIABLES": VARIABLES, "TC": TC},
        build_args=["--public-flat-rw"],
    )
    runner.test(
        hdl_toplevel="ColourToDomainRotation",
        test_module="test_ColourToDomainRotation",
    )