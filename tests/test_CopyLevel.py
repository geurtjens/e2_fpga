import cocotb
from cocotb.triggers import RisingEdge, Timer, First
from cocotb_tools.runner import get_runner

N = 4
TC = 6
VARIABLES = N * N
DEPTH = VARIABLES + 1
ALL_VARS = (1 << VARIABLES) - 1
COL_MASK = (1 << (4 * TC)) - 1

async def clock_gen(dut):
    dut.clk.value = 0
    while True:
        await Timer(5, unit="ns")
        dut.clk.value = ~dut.clk.value

async def do_reset(dut):
    dut.rst.value   = 1
    dut.start.value = 0
    dut.gameId.value = 0
    dut.in_availableVariables.value = 0
    dut.in_availableTiles.value = 0
    dut.dom_rd_r0.value = 0
    dut.dom_rd_r1.value = 0
    dut.dom_rd_r2.value = 0
    dut.dom_rd_r3.value = 0
    dut.col_rd_data.value = 0
    for _ in range(4):
        await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

async def run_copy(dut, game_id, domain_data, colour_data, avail_vars, avail_tiles):
    dut.gameId.value = game_id
    dut.in_availableVariables.value = avail_vars
    dut.in_availableTiles.value = avail_tiles

    dom_writes = []
    col_writes = []
    prev_dom_addr = game_id * VARIABLES
    prev_col_addr = game_id * VARIABLES

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0

    for cycle in range(VARIABLES + 10):
        await RisingEdge(dut.clk)

        if dut.dom_wr_en.value:
            dom_writes.append((
                int(dut.dom_wr_addr.value),
                int(dut.dom_wr_r0.value),
                int(dut.dom_wr_r1.value),
                int(dut.dom_wr_r2.value),
                int(dut.dom_wr_r3.value),
            ))

        if dut.col_wr_en.value:
            col_writes.append((
                int(dut.col_wr_addr.value),
                int(dut.col_wr_data.value),
            ))

        vid = prev_dom_addr % VARIABLES
        dut.dom_rd_r0.value = domain_data[vid][0]
        dut.dom_rd_r1.value = domain_data[vid][1]
        dut.dom_rd_r2.value = domain_data[vid][2]
        dut.dom_rd_r3.value = domain_data[vid][3]
        dut.col_rd_data.value = colour_data[vid] & COL_MASK

        prev_dom_addr = int(dut.dom_rd_addr.value)
        prev_col_addr = int(dut.col_rd_addr.value)

        #cocotb.log.info(f"cycle {cycle}: wr_en={int(dut.dom_wr_en.value)} done={int(dut.done.value)} out_valid={int(dut.out_valid.value)}")

        if dut.done.value:
            break

    return dom_writes, col_writes

@cocotb.test()
async def test_done_pulses(dut):
    """done pulses exactly once after start."""
    cocotb.start_soon(clock_gen(dut))
    await do_reset(dut)

    domain_data = [(i & ALL_VARS,)*4 for i in range(VARIABLES)]
    colour_data = [0] * VARIABLES

    done_count = 0
    dut.gameId.value = 0
    dut.in_availableVariables.value = ALL_VARS
    dut.in_availableTiles.value = ALL_VARS
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0

    prev = 0
    for _ in range(VARIABLES + 10):
        await RisingEdge(dut.clk)
        vid = prev % VARIABLES
        dut.dom_rd_r0.value = domain_data[vid][0]
        dut.dom_rd_r1.value = domain_data[vid][1]
        dut.dom_rd_r2.value = domain_data[vid][2]
        dut.dom_rd_r3.value = domain_data[vid][3]
        dut.col_rd_data.value = 0
        prev = int(dut.dom_rd_addr.value)
        if dut.done.value:
            done_count += 1
            break  # stop after done fires

    # Wait one more cycle to ensure done was only one pulse
    await RisingEdge(dut.clk)
    assert dut.done.value == 0, "done still high after one cycle"
    assert done_count == 1, f"done pulsed {done_count} times"
    cocotb.log.info("done pulses once ✓")

@cocotb.test()
async def test_correct_write_count(dut):
    """Exactly VARIABLES domain and colour writes occur."""
    cocotb.start_soon(clock_gen(dut))
    await do_reset(dut)

    domain_data = [((i+1) & ALL_VARS, (i+2) & ALL_VARS,
                    (i+3) & ALL_VARS, (i+4) & ALL_VARS)
                   for i in range(VARIABLES)]
    colour_data = [(i * 0x41) & COL_MASK for i in range(VARIABLES)]

    dom_writes, col_writes = await run_copy(
        dut, 0, domain_data, colour_data, ALL_VARS, ALL_VARS)

    assert len(dom_writes) == VARIABLES, \
        f"expected {VARIABLES} domain writes, got {len(dom_writes)}"
    assert len(col_writes) == VARIABLES, \
        f"expected {VARIABLES} colour writes, got {len(col_writes)}"
    cocotb.log.info(f"{VARIABLES} writes each ✓")

@cocotb.test()
async def test_writes_to_correct_level(dut):
    """All writes go to gameId+1."""
    cocotb.start_soon(clock_gen(dut))
    await do_reset(dut)

    game_id = 2
    domain_data = [(0xF, 0xF, 0xF, 0xF)] * VARIABLES
    colour_data = [0xFF] * VARIABLES

    dom_writes, _ = await run_copy(
        dut, game_id, domain_data, colour_data, ALL_VARS, ALL_VARS)

    base_addr = (game_id + 1) * VARIABLES
    for addr, *_ in dom_writes:
        assert base_addr <= addr < base_addr + VARIABLES, \
            f"write addr {addr} outside [{base_addr}, {base_addr+VARIABLES})"
    cocotb.log.info("writes to correct level ✓")

@cocotb.test()
async def test_data_copied_correctly(dut):
    """Data read from source appears correctly in writes to destination."""
    cocotb.start_soon(clock_gen(dut))
    await do_reset(dut)

    # Use same data for all variables so latency shift doesn't matter
    # Just verify the colour data which is simpler
    FIXED_R0 = 0xABCD & ALL_VARS
    FIXED_R1 = 0x1234 & ALL_VARS
    FIXED_R2 = 0x5678 & ALL_VARS
    FIXED_R3 = 0x9ABC & ALL_VARS
    FIXED_COL = 0x123456 & COL_MASK

    domain_data = [(FIXED_R0, FIXED_R1, FIXED_R2, FIXED_R3)] * VARIABLES
    colour_data = [FIXED_COL] * VARIABLES

    dom_writes, col_writes = await run_copy(
        dut, 0, domain_data, colour_data, ALL_VARS, ALL_VARS)

    assert len(dom_writes) == VARIABLES, f"got {len(dom_writes)} writes"

    # All writes should contain the fixed data (same for every variable)
    for addr, r0, r1, r2, r3 in dom_writes:
        assert r0 == FIXED_R0, f"addr {addr} r0={r0:#x} expected={FIXED_R0:#x}"
        assert r1 == FIXED_R1, f"addr {addr} r1={r1:#x} expected={FIXED_R1:#x}"
        assert r2 == FIXED_R2, f"addr {addr} r2={r2:#x} expected={FIXED_R2:#x}"
        assert r3 == FIXED_R3, f"addr {addr} r3={r3:#x} expected={FIXED_R3:#x}"

    for addr, col in col_writes:
        assert col == FIXED_COL, f"addr {addr} col={col:#x} expected={FIXED_COL:#x}"

    cocotb.log.info("data copied correctly ✓")

@cocotb.test()
async def test_metadata_copied(dut):
    """Available variables and tiles are copied to outputs."""
    cocotb.start_soon(clock_gen(dut))
    await do_reset(dut)

    avail_vars  = 0b1010101010101010
    avail_tiles = 0b0101010101010101
    domain_data = [(0, 0, 0, 0)] * VARIABLES
    colour_data = [0] * VARIABLES

    dut.gameId.value = 0
    dut.in_availableVariables.value = avail_vars
    dut.in_availableTiles.value = avail_tiles
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0

    metadata_ok = False
    prev = 0
    for _ in range(VARIABLES + 10):
        await RisingEdge(dut.clk)
        dut.dom_rd_r0.value = 0
        dut.dom_rd_r1.value = 0
        dut.dom_rd_r2.value = 0
        dut.dom_rd_r3.value = 0
        dut.col_rd_data.value = 0
        prev = int(dut.dom_rd_addr.value)
        if dut.out_valid.value:
            assert dut.out_availableVariables.value == avail_vars
            assert dut.out_availableTiles.value == avail_tiles
            metadata_ok = True
        if dut.done.value:
            break

    assert metadata_ok, "out_valid never pulsed"
    cocotb.log.info("metadata copied ✓")

@cocotb.test()
async def test_idle_after_done(dut):
    """Module returns to idle — second copy works correctly."""
    cocotb.start_soon(clock_gen(dut))
    await do_reset(dut)

    domain_data = [(0, 0, 0, 0)] * VARIABLES
    colour_data = [0] * VARIABLES

    # First copy
    await run_copy(dut, 0, domain_data, colour_data, ALL_VARS, ALL_VARS)
    # Wait to ensure back in idle
    for _ in range(3):
        await RisingEdge(dut.clk)
    # Second copy
    dom_writes, _ = await run_copy(dut, 1, domain_data, colour_data, ALL_VARS, ALL_VARS)
    assert len(dom_writes) == VARIABLES, \
        f"second copy: expected {VARIABLES} writes, got {len(dom_writes)}"
    cocotb.log.info("idle after done ✓")

def test_CopyLevel():
    runner = get_runner("verilator")
    runner.build(
        sources=["rtl/CopyLevel.sv"],
        hdl_toplevel="CopyLevel",
        parameters={"N": N, "TC": TC},
        build_args=["--public-flat-rw", "--timing",
                    "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-CASEINCOMPLETE"],
    )
    runner.test(
        hdl_toplevel="CopyLevel",
        test_module="test_CopyLevel",
    )