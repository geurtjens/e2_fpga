// ─────────────────────────────────────────────────────────────
// Testbench for DomainToColour
// Uses Puzzle_Brendan4 piece data (N=4, TC=6)
//
// Tests verify that given a specific domain bitmask the correct
// colour masks are derived by OR-ing piece colours together.
//
// Brendan4 colour encoding (TC=6):
//   x = 6'b000001  (bit 0)
//   a = 6'b000010  (bit 1)
//   b = 6'b000100  (bit 2)
//   c = 6'b001000  (bit 3)
//   d = 6'b010000  (bit 4)
//   e = 6'b100000  (bit 5)
//
// Pieces at r0 (top right bottom left):
//   0:aaxx  1:abxx  2:baxx  3:bbxx
//   4:caxa  5:cbxa  6:daxa  7:ebxa
//   8:daxb  9:dbxb 10:eaxb 11:ebxb
//  12:ccee 13:cdce 14:cddd 15:ceed
// ─────────────────────────────────────────────────────────────
module tb_domain_to_colour;

    parameter int N         = 4;
    parameter int TC        = 6;
    parameter int VARIABLES = N * N;

    // ── Domain inputs ──────────────────────────────────────────
    logic [VARIABLES-1:0][VARIABLES-1:0] r0, r1, r2, r3;

    // ── Previous colour inputs ─────────────────────────────────
    logic [VARIABLES-1:0][TC-1:0] in_top, in_right, in_bottom, in_left;

    // ── Pattern inputs from LoadPuzzle ─────────────────────────
    logic [VARIABLES-1:0][TC-1:0] p0_top, p0_right, p0_bottom, p0_left;
    logic [VARIABLES-1:0][TC-1:0] p1_top, p1_right, p1_bottom, p1_left;
    logic [VARIABLES-1:0][TC-1:0] p2_top, p2_right, p2_bottom, p2_left;
    logic [VARIABLES-1:0][TC-1:0] p3_top, p3_right, p3_bottom, p3_left;

    // ── DUT outputs ────────────────────────────────────────────
    logic [VARIABLES-1:0][TC-1:0] out_top, out_right, out_bottom, out_left;
    logic                         updated;

    // ── DUT: DomainToColour ────────────────────────────────────
    DomainToColour #(.N(N), .TC(TC), .VARIABLES(VARIABLES)) dut (
        .r0(r0), .r1(r1), .r2(r2), .r3(r3),
        .in_top(in_top), .in_right(in_right),
        .in_bottom(in_bottom), .in_left(in_left),
        .p0_top(p0_top), .p0_right(p0_right),
        .p0_bottom(p0_bottom), .p0_left(p0_left),
        .p1_top(p1_top), .p1_right(p1_right),
        .p1_bottom(p1_bottom), .p1_left(p1_left),
        .p2_top(p2_top), .p2_right(p2_right),
        .p2_bottom(p2_bottom), .p2_left(p2_left),
        .p3_top(p3_top), .p3_right(p3_right),
        .p3_bottom(p3_bottom), .p3_left(p3_left),
        .out_top(out_top), .out_right(out_right),
        .out_bottom(out_bottom), .out_left(out_left),
        .updated(updated)
    );

    // ── LoadPuzzle ROM ─────────────────────────────────────────
    LoadPuzzle #(.N(N), .TC(TC), .VARIABLES(VARIABLES)) puzzle (
        .p0_top(p0_top), .p0_right(p0_right),
        .p0_bottom(p0_bottom), .p0_left(p0_left),
        .p1_top(p1_top), .p1_right(p1_right),
        .p1_bottom(p1_bottom), .p1_left(p1_left),
        .p2_top(p2_top), .p2_right(p2_right),
        .p2_bottom(p2_bottom), .p2_left(p2_left),
        .p3_top(p3_top), .p3_right(p3_right),
        .p3_bottom(p3_bottom), .p3_left(p3_left)
    );

    // ── Waveform dump ──────────────────────────────────────────
    initial begin
        $dumpfile("tb_domain_to_colour.vcd");
        $dumpvars(0, tb_domain_to_colour);
    end

    // ── Colour constants ───────────────────────────────────────
    localparam logic [TC-1:0] X = 6'b000001;
    localparam logic [TC-1:0] A = 6'b000010;
    localparam logic [TC-1:0] B = 6'b000100;
    localparam logic [TC-1:0] C = 6'b001000;
    localparam logic [TC-1:0] D = 6'b010000;
    localparam logic [TC-1:0] E = 6'b100000;

    // ── Task: check one variable's output colours ──────────────
    task automatic check_var(
        input int           vid,
        input logic [TC-1:0] exp_top, exp_right,
                             exp_bottom, exp_left,
        input string        test_name
    );
        if (out_top[vid]    !== exp_top    ||
            out_right[vid]  !== exp_right  ||
            out_bottom[vid] !== exp_bottom ||
            out_left[vid]   !== exp_left)
            $display("  FAIL %s var[%0d]: top=%b(exp %b) right=%b(exp %b) bottom=%b(exp %b) left=%b(exp %b)",
                     test_name, vid,
                     out_top[vid],    exp_top,
                     out_right[vid],  exp_right,
                     out_bottom[vid], exp_bottom,
                     out_left[vid],   exp_left);
        else
            $display("  PASS %s var[%0d]: top=%b right=%b bottom=%b left=%b",
                     test_name, vid,
                     out_top[vid], out_right[vid],
                     out_bottom[vid], out_left[vid]);
    endtask

    // ── Task: check updated flag ───────────────────────────────
    task automatic check_updated(
        input logic  exp_updated,
        input string test_name
    );
        if (updated !== exp_updated)
            $display("FAIL %s: updated=%b(exp %b)",
                     test_name, updated, exp_updated);
        else
            $display("PASS %s: updated=%b", test_name, updated);
    endtask

    // ── Task: clear all domains ────────────────────────────────
    task automatic clear_domains();
        for (int i = 0; i < VARIABLES; i++) begin
            r0[i] = '0; r1[i] = '0;
            r2[i] = '0; r3[i] = '0;
        end
    endtask

    // ── Task: clear all in colours ─────────────────────────────
    task automatic clear_in_colours();
        for (int i = 0; i < VARIABLES; i++) begin
            in_top[i]    = '0; in_right[i]  = '0;
            in_bottom[i] = '0; in_left[i]   = '0;
        end
    endtask

    // ── Stimulus ───────────────────────────────────────────────
    initial begin
        clear_domains();
        clear_in_colours();
        #10;

        $display("-----------------------------------------");
        $display(" DomainToColour Testbench — Brendan4");
        $display("-----------------------------------------");

        // ══════════════════════════════════════════════════════
        // TEST 1 — Single piece in domain at r0
        // var[0] has only piece 0 (aaxx) in r0
        // Expected: top=a right=a bottom=x left=x
        // updated=1 since out differs from in (which is all zero)
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 1: Single piece in r0 (piece 0 = aaxx) --");
        clear_domains();
        clear_in_colours();
        r0[0] = 16'b0000000000000001; // piece 0 only
        #10;
        check_var(0, A, A, X, X, "Test1");
        check_updated(1'b1, "Test1");

        // ══════════════════════════════════════════════════════
        // TEST 2 — Two pieces in r0 for var[0]
        // piece 0 (aaxx) + piece 1 (abxx)
        // top = a|a = a, right = a|b = a|b, bottom = x, left = x
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 2: Two pieces in r0 (piece 0+1) --");
        clear_domains();
        clear_in_colours();
        r0[0] = 16'b0000000000000011; // pieces 0 and 1
        #10;
        check_var(0, A, A|B, X, X, "Test2");
        check_updated(1'b1, "Test2");

        // ══════════════════════════════════════════════════════
        // TEST 3 — Same piece across all rotations for var[0]
        // piece 4 (caxa) at r0: top=c right=a bottom=x left=a
        // piece 4 at r1: top=a right=c bottom=a left=x
        // piece 4 at r2: top=x right=a bottom=c left=a
        // piece 4 at r3: top=a right=x bottom=a left=c
        // Combined: top=c|a|x|a=c|a|x right=a|c|a|x=a|c|x
        //           bottom=x|a|c|a=x|a|c left=a|x|a|c=a|x|c
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 3: Piece 4 in all rotations for var[0] --");
        clear_domains();
        clear_in_colours();
        r0[0] = 16'b0000000000010000; // piece 4
        r1[0] = 16'b0000000000010000; // piece 4
        r2[0] = 16'b0000000000010000; // piece 4
        r3[0] = 16'b0000000000010000; // piece 4
        #10;
        check_var(0, C|A|X, A|C|X, X|A|C, A|X|C, "Test3");
        check_updated(1'b1, "Test3");

        // ══════════════════════════════════════════════════════
        // TEST 4 — No change: out matches in
        // var[0] has piece 0 (aaxx) in r0, in_colours set to match
        // updated=0 since nothing changed
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 4: No change when out matches in --");
        clear_domains();
        r0[0] = 16'b0000000000000001; // piece 0
        in_top[0]    = A;
        in_right[0]  = A;
        in_bottom[0] = X;
        in_left[0]   = X;
        #10;
        check_var(0, A, A, X, X, "Test4");
        check_updated(1'b0, "Test4");

        // ══════════════════════════════════════════════════════
        // TEST 5 — Empty domain produces all zero colours
        // No pieces in domain — all outputs zero
        // updated=0 since in_colours are also zero
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 5: Empty domain gives zero colours --");
        clear_domains();
        clear_in_colours();
        // all domains already zero from clear
        #10;
        check_var(0, '0, '0, '0, '0, "Test5");
        check_updated(1'b0, "Test5");

        // ══════════════════════════════════════════════════════
        // TEST 6 — Multiple variables independent
        // var[0]: piece 0 (aaxx) in r0 → top=a right=a bot=x left=x
        // var[5]: piece 12 (ccee) in r0 → top=c right=c bot=e left=e
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 6: Multiple variables independent --");
        clear_domains();
        clear_in_colours();
        r0[0]  = 16'b0000000000000001; // piece 0
        r0[5]  = 16'b0001000000000000; // piece 12
        #10;
        check_var(0, A, A, X, X,   "Test6");
        check_var(5, C, C, E, E,   "Test6");
        check_updated(1'b1, "Test6");

        // ══════════════════════════════════════════════════════
        // TEST 7 — Colour reduction detected
        // Start with two pieces, in_colours reflects both.
        // Remove one piece — colours reduce — updated=1
        // var[0]: pieces 0+1 (aaxx, abxx) → top=a right=a|b bot=x left=x
        // Remove piece 1, now only piece 0 → right shrinks from a|b to a
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 7: Colour reduction detected --");
        clear_domains();
        r0[0] = 16'b0000000000000001; // piece 0 only (piece 1 removed)
        // in_colours reflect what was there before (piece 0 + piece 1)
        in_top[0]    = A;
        in_right[0]  = A|B;  // was a|b, now should be just a
        in_bottom[0] = X;
        in_left[0]   = X;
        #10;
        check_var(0, A, A, X, X, "Test7");
        check_updated(1'b1, "Test7");

        $display("\n-----------------------------------------");
        $display(" Testbench complete");
        $display("-----------------------------------------");
        $finish;
    end

endmodule
