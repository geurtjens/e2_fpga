// ─────────────────────────────────────────────────────────────
// Testbench for ColoursToDomain
// Uses Puzzle_Brendan4 piece data (N=4, TC=6)
//
// All variables have explicit domain values in every test.
// Expected values independently computed from puzzle definition.
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
module tb_colours_to_domain;

    parameter int N         = 4;
    parameter int TC        = 6;
    parameter int VARIABLES = N * N;

    // ── Domain inputs ──────────────────────────────────────────
    logic [VARIABLES-1:0][VARIABLES-1:0] r0, r1, r2, r3;

    // ── Colour constraint inputs ───────────────────────────────
    logic [VARIABLES-1:0][TC-1:0] in_top, in_right, in_bottom, in_left;

    // ── Pattern inputs ─────────────────────────────────────────
    logic [VARIABLES-1:0][TC-1:0] p0_top, p0_right, p0_bottom, p0_left;
    logic [VARIABLES-1:0][TC-1:0] p1_top, p1_right, p1_bottom, p1_left;
    logic [VARIABLES-1:0][TC-1:0] p2_top, p2_right, p2_bottom, p2_left;
    logic [VARIABLES-1:0][TC-1:0] p3_top, p3_right, p3_bottom, p3_left;

    // ── DUT outputs ────────────────────────────────────────────
    logic [VARIABLES-1:0][VARIABLES-1:0] r0_out, r1_out, r2_out, r3_out;
    logic                                changed, deadend;

    // ── DUT: ColoursToDomain ───────────────────────────────────
    ColoursToDomain #(.N(N), .TC(TC), .VARIABLES(VARIABLES)) dut (
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
        .r0_out(r0_out), .r1_out(r1_out),
        .r2_out(r2_out), .r3_out(r3_out),
        .changed(changed), .deadend(deadend)
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
        $dumpfile("tb_colours_to_domain.vcd");
        $dumpvars(0, tb_colours_to_domain);
    end

    // ── Colour constants ───────────────────────────────────────
    localparam logic [TC-1:0] X   = 6'b000001;
    localparam logic [TC-1:0] A   = 6'b000010;
    localparam logic [TC-1:0] B   = 6'b000100;
    localparam logic [TC-1:0] C   = 6'b001000;
    localparam logic [TC-1:0] D   = 6'b010000;
    localparam logic [TC-1:0] E   = 6'b100000;
    localparam logic [TC-1:0] ALL = 6'b111111; // all colours open

    // ── Domain constants ───────────────────────────────────────
    localparam logic [VARIABLES-1:0] FULL = 16'hFFFF; // all pieces
    localparam logic [VARIABLES-1:0] NONE = 16'h0000; // no pieces

    // ── Task: set all variables to full domain, all colours ────
    task automatic init_all_full();
        for (int i = 0; i < VARIABLES; i++) begin
            r0[i] = FULL; r1[i] = FULL;
            r2[i] = FULL; r3[i] = FULL;
            in_top[i]    = ALL; in_right[i]  = ALL;
            in_bottom[i] = ALL; in_left[i]   = ALL;
        end
    endtask

    // ── Task: check domain output for one variable ─────────────
    task automatic check_domain(
        input int                   vid,
        input logic [VARIABLES-1:0] exp_r0, exp_r1,
                                    exp_r2, exp_r3,
        input string                test_name
    );
        if (r0_out[vid] !== exp_r0 || r1_out[vid] !== exp_r1 ||
            r2_out[vid] !== exp_r2 || r3_out[vid] !== exp_r3)
            $display("  FAIL %s var[%0d]: r0=%b(exp %b) r1=%b(exp %b) r2=%b(exp %b) r3=%b(exp %b)",
                     test_name, vid,
                     r0_out[vid], exp_r0,
                     r1_out[vid], exp_r1,
                     r2_out[vid], exp_r2,
                     r3_out[vid], exp_r3);
        else
            $display("  PASS %s var[%0d]: r0=%b r1=%b r2=%b r3=%b",
                     test_name, vid,
                     r0_out[vid], r1_out[vid],
                     r2_out[vid], r3_out[vid]);
    endtask

    // ── Task: check flags ──────────────────────────────────────
    task automatic check_flags(
        input logic  exp_changed,
        input logic  exp_deadend,
        input string test_name
    );
        if (changed !== exp_changed || deadend !== exp_deadend)
            $display("FAIL %s: changed=%b(exp %b) deadend=%b(exp %b)",
                     test_name,
                     changed, exp_changed,
                     deadend, exp_deadend);
        else
            $display("PASS %s: changed=%b deadend=%b",
                     test_name, changed, deadend);
    endtask

    // ── Stimulus ───────────────────────────────────────────────
    initial begin
        init_all_full();
        #10;

        $display("-----------------------------------------");
        $display(" ColoursToDomain Testbench — Brendan4");
        $display("-----------------------------------------");

        // ══════════════════════════════════════════════════════
        // TEST 1 — All colours open, all pieces in all rotations
        // Every piece is compatible — domain passes through
        // unchanged. changed=0, deadend=0
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 1: All colours open, full domain passes through --");
        init_all_full();
        #10;
        // all variables should pass through unchanged
        check_domain(0,  FULL, FULL, FULL, FULL, "Test1");
        check_domain(5,  FULL, FULL, FULL, FULL, "Test1");
        check_domain(15, FULL, FULL, FULL, FULL, "Test1");
        check_flags(1'b0, 1'b0, "Test1");

        // ══════════════════════════════════════════════════════
        // TEST 2 — Top=A constraint on var[0] only
        // All other variables still open (full domain)
        // var[0] filtered:
        //   r0 pieces with top=a: 0(aaxx) 1(abxx)             → 0000000000000011
        //   r1 pieces with top=a: 4(caxa) 5(cbxa) 6(daxa) 7(ebxa) → 0000000011110000
        //   r2 pieces with top=a: none (r2 top is bottom colour, all x or c/d/e)
        //   r3 pieces with top=a: 0,2,4,6,8,10                → 0000010101010101
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 2: Top=A on var[0], others unchanged --");
        init_all_full();
        in_top[0] = A;
        #10;
        check_domain(0,
            16'b0000000000000011,  // r0: pieces 0,1
            16'b0000000011110000,  // r1: pieces 4,5,6,7
            16'b0000000000000000,  // r2: none
            16'b0000010101010101,  // r3: pieces 0,2,4,6,8,10
            "Test2");
        check_domain(5,  FULL, FULL, FULL, FULL, "Test2"); // unchanged
        check_flags(1'b1, 1'b0, "Test2");

        // ══════════════════════════════════════════════════════
        // TEST 3 — Deadend: piece in domain cannot match constraint
        // var[0] has only piece 0 (aaxx) in r0, top constraint=C
        // piece 0 top=A — fails C constraint — all domains empty
        // All other variables remain full
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 3: Constraint mismatch causes deadend on var[0] --");
        init_all_full();
        for (int i = 0; i < VARIABLES; i++) begin
            r0[i] = NONE; r1[i] = NONE;
            r2[i] = NONE; r3[i] = NONE;
        end
        r0[0]     = 16'b0000000000000001; // piece 0 only
        in_top[0] = C;  // top must be C, piece 0 top=A — no match
        #10;
        check_domain(0, NONE, NONE, NONE, NONE, "Test3");
        check_flags(1'b1, 1'b1, "Test3");

        // ══════════════════════════════════════════════════════
        // TEST 4 — Rotation eliminated by colour constraint
        // var[0] has piece 4 (caxa) in r0 and r1 only
        // r0: top=c right=a bottom=x left=a — constraint top=A fails C
        // r1: top=a right=c bottom=a left=x — constraint top=A passes
        // r0 eliminated, r1 survives
        // All other variables remain full
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 4: top=A eliminates r0, keeps r1 for piece 4 --");
        init_all_full();
        for (int i = 0; i < VARIABLES; i++) begin
            r0[i] = NONE; r1[i] = NONE;
            r2[i] = NONE; r3[i] = NONE;
        end
        r0[0]     = 16'b0000000000010000; // piece 4
        r1[0]     = 16'b0000000000010000; // piece 4
        in_top[0] = A;
        #10;
        check_domain(0,
            NONE,
            16'b0000000000010000,  // r1: piece 4 survives
            NONE,
            NONE, "Test4");
        check_flags(1'b1, 1'b0, "Test4");

        // ══════════════════════════════════════════════════════
        // TEST 5 — No change: constraints match existing domain
        // var[0] has piece 0 (aaxx) in r0 only
        // Constraints set to exactly what piece 0 provides
        // Nothing eliminated — changed=0
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 5: No change when constraints match domain --");
        init_all_full();
        for (int i = 0; i < VARIABLES; i++) begin
            r0[i] = NONE; r1[i] = NONE;
            r2[i] = NONE; r3[i] = NONE;
        end
        r0[0]         = 16'b0000000000000001; // piece 0 (aaxx)
        in_top[0]     = A;
        in_right[0]   = A;
        in_bottom[0]  = X;
        in_left[0]    = X;
        #10;
        check_domain(0, 16'b0000000000000001, NONE, NONE, NONE, "Test5");
        check_flags(1'b0, 1'b0, "Test5");

        // ══════════════════════════════════════════════════════
        // TEST 6 — Multiple variables filtered independently
        // var[0]: piece 0+1 in r0, top=A → pieces 0,1 survive (top=a)
        // var[5]: piece 12 (ccee) in r0, top=C → piece 12 survives
        // var[10]: piece 4 in r1, all colours open → survives
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 6: Multiple variables filtered independently --");
        init_all_full();
        for (int i = 0; i < VARIABLES; i++) begin
            r0[i] = NONE; r1[i] = NONE;
            r2[i] = NONE; r3[i] = NONE;
        end
        r0[0]     = 16'b0000000000000011;  // pieces 0,1
        in_top[0] = A;
        r0[5]     = 16'b0001000000000000;  // piece 12 (ccee)
        in_top[5] = C;
        r1[10]    = 16'b0000000000010000;  // piece 4 in r1
        #10;
        check_domain(0,
            16'b0000000000000011, NONE, NONE, NONE, "Test6"); // both survive top=a
        check_domain(5,
            16'b0001000000000000, NONE, NONE, NONE, "Test6"); // piece 12 top=c matches
        check_domain(10,
            NONE, 16'b0000000000010000, NONE, NONE, "Test6"); // piece 4 r1 survives
        check_flags(1'b0, 1'b0, "Test6");

        $display("\n-----------------------------------------");
        $display(" Testbench complete");
        $display("-----------------------------------------");
        $finish;
    end

endmodule
