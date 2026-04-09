# BramStack Debugging — Session Notes

## Overview

We built and debugged a synchronous BRAM-backed push/pop stack module (`BramStack.sv`) for the Eternity 2 FPGA solver. The module stores backtrack frames on Cyclone V M10K blocks. Getting the read timing right took several iterations and a cycle-by-cycle debug trace to fully resolve.

---

## The Module's Job

`BramStack` is the backtrack stack for the solver FSM. Each stack frame contains:

- Full board constraint state (domains, colours, masks)
- The chosen variable ID for that depth level (`chosen_var`)

**Push** — write current state to `stack_ram[depth]`, increment depth.  
**Pop** — decrement depth, read back the frame at the new top, signal `valid` when `dout` is ready.

The key hardware constraint: **M10K BRAM has one cycle of registered read latency** — a read address presented on cycle N produces data on cycle N+1.

---

## What We Were Trying to Achieve

A clean two-cycle pop protocol:

```
cycle 0 — pop asserted
cycle 1 — depth decremented, read address presented to RAM
cycle 2 — dout valid, valid pulses high
```

---

## Iteration 1 — Continuous Read Address

### Design

```systemverilog
logic [DEPTH_BITS-1:0] read_addr;
assign read_addr = depth - 1'b1;  // combinatorial, always live

always_ff @(posedge clk) begin
    dout <= stack_ram[read_addr];
end
```

`dout` was updated every cycle from `read_addr`.

### What Happened

Tests returned `dout = 0x0` on pop. The debug trace revealed:

```
cycle 1 after pop: depth=1, read_addr=0 — dout=0xb008... ✓ (correct!)
cycle 2 after pop: depth=0, read_addr=63 — dout=0xb008... ✓ (still correct)
cycle 3 after pop: depth=0, read_addr=63 — valid=1, dout=0x0 ✗ (wrong!)
```

### Root Cause

`valid` pulsed on cycle 3, but by then `depth` had decremented to 0, making `read_addr = depth - 1 = 63`. The RAM re-read that uninitialised slot on cycle 3 and overwrote `dout` with zero — exactly as `valid` went high. The correct data was present on cycle 2 but we sampled one cycle too late.

---

## Iteration 2 — Gated Read on pop_d1

### Design

Gate the RAM read on `pop_d1` (one cycle after pop) to prevent `dout` being overwritten:

```systemverilog
always_ff @(posedge clk) begin
    if (pop_d1)
        dout <= stack_ram[depth - 1'b1];
end
```

### What Happened

`dout` was still 0x0. The debug trace showed `dout` never updated at all — even `0xdeadbeef` didn't appear after a push and pop.

### Root Cause

When `pop_d1` fires (one cycle after pop), `depth` has **already decremented**. So `depth - 1` on that cycle evaluates to the **new** `depth - 1`, which is one level below the frame we want — effectively `depth_original - 2`, or worse, wrapping to 63 when depth is 0.

The fundamental problem: we need the address that was valid **before** the decrement, but we're computing it **after**.

---

## Iteration 3 — Capture Address at Pop Time

### Design

Capture `depth - 1` combinatorially at the moment `pop` is asserted — before the depth counter decrements — and register it for use on the next cycle:

```systemverilog
// Capture top-of-stack address before depth decrements
logic [DEPTH_BITS-1:0] read_addr_r;

always_ff @(posedge clk) begin
    if (pop && !empty)
        read_addr_r <= depth - 1'b1;  // captured on same edge as decrement
end

// Issue RAM read on pop_d1 using the captured address
always_ff @(posedge clk) begin
    if (pop_d1)
        dout <= stack_ram[read_addr_r];
end
```

### Why This Works

On the clock edge when `pop` is asserted:
- `depth - 1` is evaluated **combinatorially** from the current (pre-decrement) depth
- That value is registered into `read_addr_r`
- `depth` also decrements on this same edge

So `read_addr_r` captures the correct top-of-stack address, and `depth` decrements — both happen simultaneously on the same edge. On the next cycle, `pop_d1` fires and the RAM read uses `read_addr_r` which correctly points to the frame we want.

### Confirmed Timing

```
cycle 0 — pop asserted; read_addr_r <= depth-1 (correct addr captured);
           depth decrements on this edge
cycle 1 — pop_d1 high; RAM read issued to read_addr_r
cycle 2 — valid=1; dout stable with correct data; held until next pop
```

### Debug Trace (confirmed correct)

```
[post-push cycle 1] depth=1  valid=0  dout=0x0
[post-push cycle 2] depth=1  valid=0  dout=0x0
--- POP ---
[post-pop cycle 1]  depth=0  valid=0  dout=<previous>
[post-pop cycle 2]  depth=0  valid=1  dout=0xdeadbeef  ← correct
[post-pop cycle 3]  depth=0  valid=0  dout=0xdeadbeef  ← held stable
```

---

## Testbench Timing Lessons

### The do_push Extra Cycle

`do_push` waits one `RisingEdge` after deasserting push for the depth counter output to settle:

```python
async def do_push(dut, frame):
    dut.push.value = 1
    await RisingEdge(dut.clk)   # frame written, depth increments
    dut.push.value = 0
    await RisingEdge(dut.clk)   # depth output stable  ← extra cycle
```

This extra cycle shifts the timing of any pop that immediately follows `do_push`. Tests that manually count cycles after `do_push` must account for this — `valid` appears one cycle later than it would after a raw push.

### The do_pop Timing

```python
async def do_pop(dut):
    dut.pop.value = 1
    await RisingEdge(dut.clk)   # cycle 0: depth decrements, addr captured
    dut.pop.value = 0
    await RisingEdge(dut.clk)   # cycle 1: RAM read issued; assert valid==0
    await RisingEdge(dut.clk)   # cycle 2: dout stable; assert valid==1
    return int(dut.dout.value)
```

### The Stale Cache Problem

Verilator caches compiled binaries in `sim_build/`. If the RTL changes but the testbench runner skips the build step ("Nothing to be done for 'default'"), the old binary runs silently. Always use a clean build when debugging RTL changes:

```bash
rm -rf sim_build && pytest tests/test_BramStack.py -s -v
```

Or use the VS Code "Run single test (clean build)" task.

---

## Final Design — BramStack.sv

```systemverilog
// Depth counter
always_ff @(posedge clk) begin
    if (rst)             depth <= '0;
    else if (push&&!full) depth <= depth + 1'b1;
    else if (pop&&!empty) depth <= depth - 1'b1;
end

// Write
always_ff @(posedge clk) begin
    if (push && !full)
        stack_ram[depth] <= din;
end

// Capture read address at pop time (before depth decrements)
always_ff @(posedge clk) begin
    if (pop && !empty)
        read_addr_r <= depth - 1'b1;
end

// Valid pipeline
always_ff @(posedge clk) begin
    if (rst) begin
        pop_d1 <= 1'b0;
        valid  <= 1'b0;
    end else begin
        pop_d1 <= pop && !empty;
        valid  <= pop_d1;
    end
end

// RAM read — issued on pop_d1 with captured address
always_ff @(posedge clk) begin
    if (pop_d1)
        dout <= stack_ram[read_addr_r];
end
```

---

## Test Results

| Test | Status |
|---|---|
| test_reset | ✓ PASS |
| test_push_pop_single | ✓ PASS |
| test_lifo_ordering | ✓ PASS |
| test_full_flag | ✓ PASS |
| test_empty_flag | ✓ PASS |
| test_pop_latency | ✓ PASS |
| test_chosen_var_field | ✓ PASS |
| test_interleaved_push_pop | ✓ PASS |

**8/8 passing.**

---

## Key Takeaway

The core insight for synchronous BRAM design: **you cannot use a signal on the same cycle it changes**. When `pop` fires, `depth` decrements and the correct read address must be captured simultaneously — not derived from the new (already decremented) `depth` on the following cycle. The solution is to treat the address capture as a separate registered pipeline stage that runs in parallel with the depth decrement, not after it.