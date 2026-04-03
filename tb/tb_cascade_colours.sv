// ─────────────────────────────────────────────────────────────
// Testbench for CascadeColours
// N=4, TC=6 — clean SystemVerilog for Questa and Verilator
//
// Board layout:
//  0  1  2  3    y=0
//  4  5  6  7    y=1
//  8  9 10 11    y=2
// 12 13 14 15    y=3
//
// Colour masks (TC=6 bits):
//   BOUNDARY = 6'b000001
//   BORDER   = 6'b001110
//   INNER_C  = 6'b110000
//   ALL_C    = 6'b111111  (all bits set)
//   ZERO_C   = 6'b000000
// ─────────────────────────────────────────────────────────────
module tb_cascade_colours;

    parameter int N  = 4;
    parameter int TC = 6;
    parameter int VARIABLES = N * N;

    // ── DUT inputs ─────────────────────────────────────────────
    logic [VARIABLES-1:0][TC-1:0] in_top;
    logic [VARIABLES-1:0][TC-1:0] in_right;
    logic [VARIABLES-1:0][TC-1:0] in_bottom;
    logic [VARIABLES-1:0][TC-1:0] in_left;

    // ── DUT outputs ────────────────────────────────────────────
    logic [VARIABLES-1:0][TC-1:0] out_top;
    logic [VARIABLES-1:0][TC-1:0] out_right;
    logic [VARIABLES-1:0][TC-1:0] out_bottom;
    logic [VARIABLES-1:0][TC-1:0] out_left;
    logic                         deadend;
    logic                         updated;

    // ── DUT ────────────────────────────────────────────────────
    CascadeColours #(.N(N), .TC(TC)) dut (
        .in_top    (in_top),
        .in_right  (in_right),
        .in_bottom (in_bottom),
        .in_left   (in_left),
        .out_top   (out_top),
        .out_right (out_right),
        .out_bottom(out_bottom),
        .out_left  (out_left),
        .deadend   (deadend),
        .updated   (updated)
    );

    // ── Waveform dump ──────────────────────────────────────────
    initial begin
        $dumpfile("tb_cascade_colours.vcd");
        $dumpvars(0, tb_cascade_colours);
    end

    // ── Colour constants ───────────────────────────────────────
    localparam logic [TC-1:0] BOUNDARY = 6'b000001;
    localparam logic [TC-1:0] BORDER   = 6'b001110;
    localparam logic [TC-1:0] INNER_C  = 6'b110000;
    localparam logic [TC-1:0] ALL_C    = 6'b111111;
    localparam logic [TC-1:0] ZERO_C   = 6'b000000;

    // ── Task: initialise all edges to a given value ────────────
    task automatic init_all(input logic [TC-1:0] val);
        for (int i = 0; i < VARIABLES; i++) begin
            in_top[i]    = val;
            in_right[i]  = val;
            in_bottom[i] = val;
            in_left[i]   = val;
        end
    endtask

    // ── Task: check a single variable's output colours ─────────
    task automatic check_var(
        input int           id,
        input logic [TC-1:0] exp_top, exp_right,
                             exp_bottom, exp_left,
        input string        test_name
    );
        if (out_top[id]    !== exp_top    ||
            out_right[id]  !== exp_right  ||
            out_bottom[id] !== exp_bottom ||
            out_left[id]   !== exp_left)
            $display("  FAIL %s var[%0d]: top=%b(exp %b) right=%b(exp %b) bottom=%b(exp %b) left=%b(exp %b)",
                     test_name, id,
                     out_top[id],    exp_top,
                     out_right[id],  exp_right,
                     out_bottom[id], exp_bottom,
                     out_left[id],   exp_left);
        else
            $display("  PASS %s var[%0d]: top=%b right=%b bottom=%b left=%b",
                     test_name, id,
                     out_top[id], out_right[id],
                     out_bottom[id], out_left[id]);
    endtask

    // ── Task: check flags ──────────────────────────────────────
    task automatic check_flags(
        input logic exp_deadend,
        input logic exp_updated,
        input string test_name
    );
        if (deadend !== exp_deadend || updated !== exp_updated)
            $display("FAIL %s: deadend=%b(exp %b) updated=%b(exp %b)",
                     test_name, deadend, exp_deadend,
                     updated, exp_updated);
        else
            $display("PASS %s: deadend=%b updated=%b",
                     test_name, deadend, updated);
    endtask

    // ── Stimulus ───────────────────────────────────────────────
    initial begin
        $display("-----------------------------------------");
        $display(" CascadeColours Testbench N=%0d TC=%0d", N, TC);
        $display("-----------------------------------------");

        // ══════════════════════════════════════════════════════
        // TEST 1 — All edges identical (ALL_C)
        // AND of matching values = same value, no change
        // deadend=0, updated=0
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 1: All edges ALL_C, no change expected --");
        init_all(ALL_C);
        #10;
        check_flags(1'b0, 1'b0, "Test1");
        // spot check a few internal variables
        check_var(5,  ALL_C, ALL_C, ALL_C, ALL_C, "Test1");
        check_var(6,  ALL_C, ALL_C, ALL_C, ALL_C, "Test1");
        check_var(9,  ALL_C, ALL_C, ALL_C, ALL_C, "Test1");
        check_var(10, ALL_C, ALL_C, ALL_C, ALL_C, "Test1");

        // ══════════════════════════════════════════════════════
        // TEST 2 — Horizontal cascade only
        // var 5 right = BORDER, var 6 left = INNER_C
        // AND = ZERO_C — deadend on that edge
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 2: Horizontal mismatch causes deadend --");
        init_all(ALL_C);
        in_right[5] = BORDER;
        in_left[6]  = INNER_C;
        #10;
        check_flags(1'b1, 1'b1, "Test2");
        // the shared edge between var5 and var6 should be zero
        check_var(5, ALL_C, ZERO_C, ALL_C, ALL_C, "Test2");
        check_var(6, ALL_C, ALL_C,  ALL_C, ZERO_C, "Test2");

        // ══════════════════════════════════════════════════════
        // TEST 3 — Horizontal cascade, partial overlap
        // var 1 right = BORDER|BOUNDARY = 6'b001111
        // var 2 left  = BORDER          = 6'b001110
        // AND = 6'b001110 — non zero, updated but no deadend
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 3: Horizontal partial overlap, updated no deadend --");
        init_all(ALL_C);
        in_right[1] = 6'b001111;
        in_left[2]  = 6'b001110;
        #10;
        check_flags(1'b0, 1'b1, "Test3");
        check_var(1, ALL_C, 6'b001110, ALL_C, ALL_C, "Test3");
        check_var(2, ALL_C, ALL_C,     ALL_C, 6'b001110, "Test3");

        // ══════════════════════════════════════════════════════
        // TEST 4 — Vertical cascade only
        // var 1 bottom = BORDER, var 5 top = INNER_C
        // AND = ZERO_C — deadend on that edge
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 4: Vertical mismatch causes deadend --");
        init_all(ALL_C);
        in_bottom[1] = BORDER;
        in_top[5]    = INNER_C;
        #10;
        check_flags(1'b1, 1'b1, "Test4");
        check_var(1, ALL_C, ALL_C, ZERO_C, ALL_C, "Test4");
        check_var(5, ZERO_C, ALL_C, ALL_C, ALL_C, "Test4");

        // ══════════════════════════════════════════════════════
        // TEST 5 — Vertical cascade, partial overlap
        // var 2 bottom = INNER_C|BOUNDARY = 6'b110001
        // var 6 top    = INNER_C          = 6'b110000
        // AND = 6'b110000 — non zero, updated no deadend
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 5: Vertical partial overlap, updated no deadend --");
        init_all(ALL_C);
        in_bottom[2] = 6'b110001;
        in_top[6]    = 6'b110000;
        #10;
        check_flags(1'b0, 1'b1, "Test5");
        check_var(2, ALL_C, ALL_C, 6'b110000, ALL_C, "Test5");
        check_var(6, 6'b110000, ALL_C, ALL_C, ALL_C, "Test5");

        // ══════════════════════════════════════════════════════
        // TEST 6 — Boundary edges are static and never modified
        // Cascade should not touch the outer boundary edges.
        // We set up a realistic board state where boundary edges
        // hold BOUNDARY and internal edges hold ALL_C, then
        // confirm the cascade leaves the boundary edges alone.
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 6: Boundary edges untouched by cascade --");
        init_all(ALL_C);
        // outer boundary edges — these must never be changed
        in_top[0]=BOUNDARY;  in_top[1]=BOUNDARY;
        in_top[2]=BOUNDARY;  in_top[3]=BOUNDARY;      // y=0 top
        in_left[0]=BOUNDARY; in_left[4]=BOUNDARY;
        in_left[8]=BOUNDARY; in_left[12]=BOUNDARY;    // x=0 left
        in_right[3]=BOUNDARY; in_right[7]=BOUNDARY;
        in_right[11]=BOUNDARY; in_right[15]=BOUNDARY; // x=3 right
        in_bottom[12]=BOUNDARY; in_bottom[13]=BOUNDARY;
        in_bottom[14]=BOUNDARY; in_bottom[15]=BOUNDARY; // y=3 bottom
        #10;
        check_flags(1'b0, 1'b0, "Test6");
        // confirm boundary edges are unchanged on output
        check_var(0,  BOUNDARY, ALL_C, ALL_C,    BOUNDARY, "Test6");
        check_var(3,  BOUNDARY, BOUNDARY, ALL_C, ALL_C,    "Test6");
        check_var(12, ALL_C,    ALL_C, BOUNDARY, BOUNDARY, "Test6");
        check_var(15, ALL_C,    BOUNDARY, BOUNDARY, ALL_C, "Test6");

        // ══════════════════════════════════════════════════════
        // TEST 7 — No cascade when inputs already match
        // All internal shared edges identical — no change
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 7: All internal edges match, no change --");
        init_all(INNER_C);
        #10;
        check_flags(1'b0, 1'b0, "Test7");

        $display("\n-----------------------------------------");
        $display(" Testbench complete");
        $display("-----------------------------------------");
        $finish;
    end

endmodule
