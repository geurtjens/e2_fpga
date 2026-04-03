// ─────────────────────────────────────────────────────────────
// Testbench for Assignment
// Uses Puzzle_Brendan4 piece data (N=4, TC=6)
//
// Board layout:
//  0  1  2  3   y=0
//  4  5  6  7   y=1
//  8  9 10 11   y=2
// 12 13 14 15   y=3
//
// Brendan4 colour encoding (TC=6):
//   x = 6'b000001  boundary
//   a = 6'b000010
//   b = 6'b000100
//   c = 6'b001000
//   d = 6'b010000
//   e = 6'b100000
//
// Pieces at r0 (top right bottom left):
//   0:aaxx  1:abxx  2:baxx  3:bbxx
//   4:caxa  5:cbxa  6:daxa  7:ebxa
//   8:daxb  9:dbxb 10:eaxb 11:ebxb
//  12:ccee 13:cdce 14:cddd 15:ceed
// ─────────────────────────────────────────────────────────────
module tb_assignment;

    parameter int N         = 4;
    parameter int TC        = 6;
    parameter int VARIABLES = N * N;
    parameter int ID_BITS   = $clog2(VARIABLES);

    // ── Assignment inputs ──────────────────────────────────────
    logic [ID_BITS-1:0] variableId;
    logic [ID_BITS-1:0] tileId;
    logic [1:0]         rotation;

    // ── Colour arrays ──────────────────────────────────────────
    logic [VARIABLES-1:0][TC-1:0] in_top, in_right, in_bottom, in_left;

    // ── Domain arrays ──────────────────────────────────────────
    logic [VARIABLES-1:0][VARIABLES-1:0] in_r0, in_r1, in_r2, in_r3;

    // ── Pattern inputs ─────────────────────────────────────────
    logic [VARIABLES-1:0][TC-1:0] p0_top, p0_right, p0_bottom, p0_left;
    logic [VARIABLES-1:0][TC-1:0] p1_top, p1_right, p1_bottom, p1_left;
    logic [VARIABLES-1:0][TC-1:0] p2_top, p2_right, p2_bottom, p2_left;
    logic [VARIABLES-1:0][TC-1:0] p3_top, p3_right, p3_bottom, p3_left;

    // ── DUT outputs ────────────────────────────────────────────
    logic [VARIABLES-1:0][TC-1:0]        out_top, out_right;
    logic [VARIABLES-1:0][TC-1:0]        out_bottom, out_left;
    logic [VARIABLES-1:0][VARIABLES-1:0] out_r0, out_r1, out_r2, out_r3;
    logic                                colours_changed;

    // ── DUT ────────────────────────────────────────────────────
    Assignment #(.N(N), .TC(TC), .VARIABLES(VARIABLES)) dut (
        .variableId(variableId), .tileId(tileId), .rotation(rotation),
        .in_top(in_top), .in_right(in_right),
        .in_bottom(in_bottom), .in_left(in_left),
        .in_r0(in_r0), .in_r1(in_r1), .in_r2(in_r2), .in_r3(in_r3),
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
        .out_r0(out_r0), .out_r1(out_r1),
        .out_r2(out_r2), .out_r3(out_r3),
        .colours_changed(colours_changed)
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
        $dumpfile("tb_assignment.vcd");
        $dumpvars(0, tb_assignment);
    end

    // ── Colour constants ───────────────────────────────────────
    localparam logic [TC-1:0] X   = 6'b000001;
    localparam logic [TC-1:0] A   = 6'b000010;
    localparam logic [TC-1:0] B   = 6'b000100;
    localparam logic [TC-1:0] C   = 6'b001000;
    localparam logic [TC-1:0] D   = 6'b010000;
    localparam logic [TC-1:0] E   = 6'b100000;
    localparam logic [TC-1:0] ALL = 6'b111111;

    localparam logic [VARIABLES-1:0] FULL = 16'hFFFF;
    localparam logic [VARIABLES-1:0] NONE = 16'h0000;

    // ── Task: initialise all colours to ALL, domains to FULL ──
    task automatic init_all();
        for (int i = 0; i < VARIABLES; i++) begin
            in_top[i]    = ALL; in_right[i]  = ALL;
            in_bottom[i] = ALL; in_left[i]   = ALL;
            in_r0[i] = FULL; in_r1[i] = FULL;
            in_r2[i] = FULL; in_r3[i] = FULL;
        end
    endtask

    // ── Task: check assigned variable's domain ─────────────────
    task automatic check_domain(
        input int                   vid,
        input logic [VARIABLES-1:0] exp_r0, exp_r1,
                                    exp_r2, exp_r3,
        input string                test_name
    );
        if (out_r0[vid] !== exp_r0 || out_r1[vid] !== exp_r1 ||
            out_r2[vid] !== exp_r2 || out_r3[vid] !== exp_r3)
            $display("  FAIL %s domain var[%0d]: r0=%b(exp %b) r1=%b(exp %b) r2=%b(exp %b) r3=%b(exp %b)",
                     test_name, vid,
                     out_r0[vid], exp_r0, out_r1[vid], exp_r1,
                     out_r2[vid], exp_r2, out_r3[vid], exp_r3);
        else
            $display("  PASS %s domain var[%0d]: r0=%b r1=%b r2=%b r3=%b",
                     test_name, vid,
                     out_r0[vid], out_r1[vid],
                     out_r2[vid], out_r3[vid]);
    endtask

    // ── Task: check one variable's colours ────────────────────
    task automatic check_colours(
        input int           vid,
        input logic [TC-1:0] exp_top, exp_right,
                             exp_bottom, exp_left,
        input string        test_name
    );
        if (out_top[vid]    !== exp_top    ||
            out_right[vid]  !== exp_right  ||
            out_bottom[vid] !== exp_bottom ||
            out_left[vid]   !== exp_left)
            $display("  FAIL %s colours var[%0d]: top=%b(exp %b) right=%b(exp %b) bottom=%b(exp %b) left=%b(exp %b)",
                     test_name, vid,
                     out_top[vid],    exp_top,
                     out_right[vid],  exp_right,
                     out_bottom[vid], exp_bottom,
                     out_left[vid],   exp_left);
        else
            $display("  PASS %s colours var[%0d]: top=%b right=%b bottom=%b left=%b",
                     test_name, vid,
                     out_top[vid], out_right[vid],
                     out_bottom[vid], out_left[vid]);
    endtask

    // ── Task: check flags ──────────────────────────────────────
    task automatic check_flags(
        input logic  exp_changed,
        input string test_name
    );
        if (colours_changed !== exp_changed)
            $display("FAIL %s: colours_changed=%b(exp %b)",
                     test_name, colours_changed, exp_changed);
        else
            $display("PASS %s: colours_changed=%b",
                     test_name, colours_changed);
    endtask

    // ── Stimulus ───────────────────────────────────────────────
    initial begin
        init_all();
        variableId = 0; tileId = 0; rotation = 0;
        #10;

        $display("-----------------------------------------");
        $display(" Assignment Testbench — Brendan4");
        $display("-----------------------------------------");

        // ══════════════════════════════════════════════════════
        // TEST 1 — Assign piece 0 (aaxx) at rotation 0 to var 5
        // var 5 is at x=1, y=1 — has all 4 neighbours
        // piece 0 r0: top=a right=a bottom=x left=x
        //
        // Expected domain: r0[5]=bit0, r1[5]=0, r2[5]=0, r3[5]=0
        // Expected colours var[5]: top=a right=a bottom=x left=x
        //
        // Neighbour updates:
        //   right  = var 6: in_left[6]  & piece_right(a) = ALL & a = a
        //   below  = var 9: in_top[9]   & piece_bottom(x) = ALL & x = x
        //   left   = var 4: in_right[4] & piece_left(x)  = ALL & x = x
        //   above  = var 1: in_bottom[1] & piece_top(a)  = ALL & a = a
        // colours_changed=1 since neighbours narrowed from ALL
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 1: Assign piece 0 (aaxx) r0 to var[5] --");
        init_all();
        variableId = 4'd5;
        tileId     = 4'd0;
        rotation   = 2'd0;
        #10;
        // domain locked
        check_domain(5,
            16'b0000000000000001, NONE, NONE, NONE, "Test1");
        // own colours
        check_colours(5, A, A, X, X, "Test1");
        // neighbour colours updated
        check_colours(6, ALL, ALL, ALL, A,   "Test1"); // left of var6 = a
        check_colours(9, X,   ALL, ALL, ALL, "Test1"); // top  of var9 = x
        check_colours(4, ALL, X,   ALL, ALL, "Test1"); // right of var4 = x
        check_colours(1, ALL, ALL, A,   ALL, "Test1"); // bottom of var1 = a
        check_flags(1'b1, "Test1");

        // ══════════════════════════════════════════════════════
        // TEST 2 — Assign piece 4 (caxa) at rotation 1 to var 5
        // piece 4 r1: top=a right=c bottom=a left=x
        //
        // Expected domain: r0[5]=0, r1[5]=bit4, r2[5]=0, r3[5]=0
        // Expected colours var[5]: top=a right=c bottom=a left=x
        //
        // Neighbour updates:
        //   right  = var 6: in_left[6]  & piece_right(c) = ALL & c = c
        //   below  = var 9: in_top[9]   & piece_bottom(a) = ALL & a = a
        //   left   = var 4: in_right[4] & piece_left(x)  = ALL & x = x
        //   above  = var 1: in_bottom[1] & piece_top(a)  = ALL & a = a
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 2: Assign piece 4 (caxa) r1 to var[5] --");
        init_all();
        variableId = 4'd5;
        tileId     = 4'd4;
        rotation   = 2'd1;
        #10;
        check_domain(5, NONE, 16'b0000000000010000, NONE, NONE, "Test2");
        check_colours(5, A, C, A, X, "Test2");
        check_colours(6, ALL, ALL, ALL, C,   "Test2"); // left = c
        check_colours(9, A,   ALL, ALL, ALL, "Test2"); // top  = a
        check_colours(4, ALL, X,   ALL, ALL, "Test2"); // right = x
        check_colours(1, ALL, ALL, A,   ALL, "Test2"); // bottom = a
        check_flags(1'b1, "Test2");

        // ══════════════════════════════════════════════════════
        // TEST 3 — Assign to corner var 0 (x=0, y=0)
        // var 0 has only right and below neighbours
        // piece 0 r0: top=a right=a bottom=x left=x
        //
        // Only 2 neighbour updates:
        //   right = var 1: in_left[1]  & a = ALL & a = a
        //   below = var 4: in_top[4]   & x = ALL & x = x
        // No left or above neighbours
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 3: Assign piece 0 r0 to corner var[0] --");
        init_all();
        variableId = 4'd0;
        tileId     = 4'd0;
        rotation   = 2'd0;
        #10;
        check_domain(0, 16'b0000000000000001, NONE, NONE, NONE, "Test3");
        check_colours(0, A, A, X, X,   "Test3");
        check_colours(1, ALL, ALL, ALL, A, "Test3"); // left of var1 = a
        check_colours(4, X,   ALL, ALL, ALL, "Test3"); // top of var4 = x
        check_flags(1'b1, "Test3");

        // ══════════════════════════════════════════════════════
        // TEST 4 — No colour change when neighbours already match
        // Assign piece 0 (aaxx) r0 to var 5
        // Pre-set neighbours to already have the exact colours
        // the piece provides — colours_changed=0
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 4: No change when neighbours already match --");
        init_all();
        in_left[6]   = A;  // already matches piece right
        in_top[9]    = X;  // already matches piece bottom
        in_right[4]  = X;  // already matches piece left
        in_bottom[1] = A;  // already matches piece top
        variableId = 4'd5;
        tileId     = 4'd0;
        rotation   = 2'd0;
        #10;
        check_flags(1'b0, "Test4");

        // ══════════════════════════════════════════════════════
        // TEST 5 — Assign to right edge var 7 (x=3, y=1)
        // var 7 has no right neighbour (rightmost column)
        // Only updates: above=var3, below=var11, left=var6
        // piece 3 r0: top=b right=b bottom=x left=x
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 5: Assign to right edge var[7], no right neighbour --");
        init_all();
        variableId = 4'd7;
        tileId     = 4'd3;  // piece 3 (bbxx) r0: top=b right=b bottom=x left=x
        rotation   = 2'd0;
        #10;
        check_domain(7, 16'b0000000000001000, NONE, NONE, NONE, "Test5");
        check_colours(7, B, B, X, X, "Test5");
        // left neighbour var6: right & piece_left(x) = ALL & x = x
        check_colours(6,  ALL, X, ALL, ALL, "Test5");
        // above neighbour var3: bottom & piece_top(b) = ALL & b = b
        check_colours(3,  ALL, ALL, B,   ALL, "Test5");
        // below neighbour var11: top & piece_bottom(x) = ALL & x = x
        check_colours(11, X,   ALL, ALL, ALL, "Test5");
        // right neighbour var8 should be unchanged (no right neighbour from var7)
        check_colours(8, ALL, ALL, ALL, ALL, "Test5");
        check_flags(1'b1, "Test5");

        $display("\n-----------------------------------------");
        $display(" Testbench complete");
        $display("-----------------------------------------");
        $finish;
    end

endmodule
