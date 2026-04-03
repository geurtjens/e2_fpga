// ─────────────────────────────────────────────────────────────
// Testbench for ChooseNextVariable
// N=4, VARIABLES=16, ID_BITS=4
//
// Board layout:
//  0  1  2  3   y=0
//  4  5  6  7   y=1
//  8  9 10 11   y=2
// 12 13 14 15   y=3
//
// variablesIncludedMask: 1=unassigned, 0=singleton(assigned)
// ─────────────────────────────────────────────────────────────
module tb_choose_next_variable;

    parameter int N         = 4;
    parameter int VARIABLES = N * N;
    parameter int ID_BITS   = $clog2(VARIABLES);

    // ── DUT inputs ─────────────────────────────────────────────
    logic [VARIABLES-1:0]                variablesIncludedMask;
    logic [VARIABLES-1:0][VARIABLES-1:0] r0, r1, r2, r3;

    // ── DUT outputs ────────────────────────────────────────────
    logic [ID_BITS-1:0] next_var;
    logic               valid;

    // ── DUT ────────────────────────────────────────────────────
    ChooseNextVariable #(.N(N), .VARIABLES(VARIABLES)) dut (
        .variablesIncludedMask (variablesIncludedMask),
        .r0(r0), .r1(r1), .r2(r2), .r3(r3),
        .next_var(next_var),
        .valid(valid)
    );

    // ── Waveform dump ──────────────────────────────────────────
    initial begin
        $dumpfile("tb_choose_next_variable.vcd");
        $dumpvars(0, tb_choose_next_variable);
    end

    // ── Task: set all domains to a given popcount value ────────
    // Sets r0 for each variable to have 'count' bits set
    // r1/r2/r3 left zero so popcount = count exactly
    task automatic set_domain_count(input int vid, input int count);
        r0[vid] = (1 << count) - 1; // count LSBs set
        r1[vid] = '0;
        r2[vid] = '0;
        r3[vid] = '0;
    endtask

    // ── Task: check output ─────────────────────────────────────
    task automatic check_result(
        input logic [ID_BITS-1:0] exp_var,
        input logic               exp_valid,
        input string              test_name
    );
        if (next_var !== exp_var || valid !== exp_valid)
            $display("FAIL %s: next_var=%0d(exp %0d) valid=%b(exp %b)",
                     test_name, next_var, exp_var, valid, exp_valid);
        else
            $display("PASS %s: next_var=%0d valid=%b",
                     test_name, next_var, valid);
    endtask

    // ── Task: init all domains to same popcount ────────────────
    task automatic init_domains(input int count);
        for (int i = 0; i < VARIABLES; i++)
            set_domain_count(i, count);
    endtask

    initial begin
        // default — all unassigned, equal domains
        variablesIncludedMask = '1;
        init_domains(4);
        #10;

        $display("-----------------------------------------");
        $display(" ChooseNextVariable Testbench  N=%0d", N);
        $display("-----------------------------------------");

        // ══════════════════════════════════════════════════════
        // TEST 1 — No singletons yet
        // variablesIncludedMask = all 1s — no singletons
        // No neighbours to expand to — valid=0
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 1: No singletons, valid=0 --");
        variablesIncludedMask = 16'hFFFF; // all unassigned
        init_domains(4);
        #10;
        check_result(0, 1'b0, "Test1");

        // ══════════════════════════════════════════════════════
        // TEST 2 — One singleton at var 0 (top-left corner)
        // Neighbours of var 0: right=var1, below=var4
        // All domains equal (4 bits) — lowest ID wins → var 1
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 2: Singleton at var[0], pick lowest neighbour --");
        variablesIncludedMask = 16'hFFFE; // var 0 is singleton
        init_domains(4);
        #10;
        check_result(1, 1'b1, "Test2");

        // ══════════════════════════════════════════════════════
        // TEST 3 — Singleton at var 0, var 4 has smaller domain
        // Neighbours: var1 (count=4), var4 (count=2)
        // var 4 has smaller domain — pick var 4
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 3: Singleton at var[0], var[4] smaller domain --");
        variablesIncludedMask = 16'hFFFE; // var 0 is singleton
        init_domains(4);
        set_domain_count(4, 2); // var 4 has only 2 pieces
        #10;
        check_result(4, 1'b1, "Test3");

        // ══════════════════════════════════════════════════════
        // TEST 4 — Singleton at var 5 (inner variable)
        // Neighbours of var 5 (x=1,y=1): up=1, down=9, left=4, right=6
        // All equal domain (4) — lowest ID wins → var 1
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 4: Singleton at var[5], pick lowest of 4 neighbours --");
        variablesIncludedMask = 16'hFFFF & ~16'b0000000000100000; // var 5 singleton
        init_domains(4);
        #10;
        check_result(1, 1'b1, "Test4");

        // ══════════════════════════════════════════════════════
        // TEST 5 — Singleton at var 5, var 9 has smallest domain
        // Neighbours: 1(4), 4(4), 6(4), 9(1)
        // var 9 has count=1 — pick var 9
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 5: Singleton at var[5], var[9] smallest domain --");
        variablesIncludedMask = 16'hFFFF & ~16'b0000000000100000; // var 5 singleton
        init_domains(4);
        set_domain_count(9, 1);
        #10;
        check_result(9, 1'b1, "Test5");

        // ══════════════════════════════════════════════════════
        // TEST 6 — Multiple singletons expand neighbourhood
        // Singletons: var 0 and var 5
        // Combined neighbours of 0: 1,4
        // Combined neighbours of 5: 1,4,6,9
        // All equal domain — lowest ID wins → var 1
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 6: Two singletons, combined neighbours --");
        variablesIncludedMask = 16'hFFFF
                                & ~16'b0000000000000001  // var 0
                                & ~16'b0000000000100000; // var 5
        init_domains(4);
        #10;
        check_result(1, 1'b1, "Test6");

        // ══════════════════════════════════════════════════════
        // TEST 7 — Boundary wrap prevention
        // Singleton at var 3 (x=3, rightmost column)
        // Right neighbour would be var 4 — must NOT wrap
        // Valid neighbours: left=var2, below=var7 only
        // Equal domains — lowest wins → var 2
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 7: No wrap at right boundary, var[3] singleton --");
        variablesIncludedMask = 16'hFFFF & ~16'b0000000000001000; // var 3 singleton
        init_domains(4);
        #10;
        check_result(2, 1'b1, "Test7");

        // ══════════════════════════════════════════════════════
        // TEST 8 — Boundary wrap prevention left side
        // Singleton at var 4 (x=0, leftmost column)
        // Left neighbour would be var 3 — must NOT wrap
        // Valid neighbours: above=var0, right=var5, below=var8
        // Equal domains — lowest wins → var 0
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 8: No wrap at left boundary, var[4] singleton --");
        variablesIncludedMask = 16'hFFFF & ~16'b0000000000010000; // var 4 singleton
        init_domains(4);
        #10;
        check_result(0, 1'b1, "Test8");

        $display("\n-----------------------------------------");
        $display(" Testbench complete");
        $display("-----------------------------------------");
        $finish;
    end

endmodule
