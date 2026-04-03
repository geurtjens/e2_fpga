// ─────────────────────────────────────────────────────────────
// Testbench for SingletonDetection
// N=4, VARIABLES=16
//
// Tests cover:
//   - No singletons present
//   - One singleton detected and locked
//   - Multiple singletons detected simultaneously
//   - Deadend from duplicate tile assignment
//   - Already assigned variables are skipped
// ─────────────────────────────────────────────────────────────
module tb_singleton_detection;

    parameter int N         = 4;
    parameter int VARIABLES = N * N;
    parameter int ID_BITS   = $clog2(VARIABLES);

    // ── Inputs ─────────────────────────────────────────────────
    logic [VARIABLES-1:0]                in_variablesIncludedMask;
    logic [VARIABLES-1:0]                in_unassignedTiles;
    logic [VARIABLES-1:0][VARIABLES-1:0] in_r0, in_r1, in_r2, in_r3;

    // ── Outputs ────────────────────────────────────────────────
    logic [VARIABLES-1:0]                out_variablesIncludedMask;
    logic [VARIABLES-1:0]                out_unassignedTiles;
    logic [VARIABLES-1:0][VARIABLES-1:0] out_r0, out_r1, out_r2, out_r3;
    logic                                singleton_found, deadend;

    // ── DUT ────────────────────────────────────────────────────
    SingletonDetection #(.N(N), .VARIABLES(VARIABLES)) dut (
        .in_variablesIncludedMask  (in_variablesIncludedMask),
        .in_unassignedTiles        (in_unassignedTiles),
        .in_r0(in_r0), .in_r1(in_r1), .in_r2(in_r2), .in_r3(in_r3),
        .out_variablesIncludedMask (out_variablesIncludedMask),
        .out_unassignedTiles       (out_unassignedTiles),
        .out_r0(out_r0), .out_r1(out_r1),
        .out_r2(out_r2), .out_r3(out_r3),
        .singleton_found(singleton_found),
        .deadend(deadend)
    );

    // ── Waveform dump ──────────────────────────────────────────
    initial begin
        $dumpfile("tb_singleton_detection.vcd");
        $dumpvars(0, tb_singleton_detection);
    end

    localparam logic [VARIABLES-1:0] FULL = 16'hFFFF;
    localparam logic [VARIABLES-1:0] NONE = 16'h0000;

    // ── Task: initialise all domains to FULL ───────────────────
    task automatic init_all();
        in_variablesIncludedMask = FULL;
        in_unassignedTiles       = FULL;
        for (int i = 0; i < VARIABLES; i++) begin
            in_r0[i] = FULL; in_r1[i] = FULL;
            in_r2[i] = FULL; in_r3[i] = FULL;
        end
    endtask

    // ── Task: check flags ──────────────────────────────────────
    task automatic check_flags(
        input logic  exp_found,
        input logic  exp_deadend,
        input string test_name
    );
        if (singleton_found !== exp_found || deadend !== exp_deadend)
            $display("FAIL %s: singleton_found=%b(exp %b) deadend=%b(exp %b)",
                     test_name, singleton_found, exp_found,
                     deadend, exp_deadend);
        else
            $display("PASS %s: singleton_found=%b deadend=%b",
                     test_name, singleton_found, deadend);
    endtask

    // ── Task: check variable was removed from mask ─────────────
    task automatic check_var_removed(
        input int    vid,
        input string test_name
    );
        if (out_variablesIncludedMask[vid] !== 1'b0)
            $display("  FAIL %s: var[%0d] still in mask (exp removed)",
                     test_name, vid);
        else
            $display("  PASS %s: var[%0d] correctly removed from mask",
                     test_name, vid);
    endtask

    // ── Task: check tile was removed from available ────────────
    task automatic check_tile_removed(
        input int    tid,
        input string test_name
    );
        if (out_unassignedTiles[tid] !== 1'b0)
            $display("  FAIL %s: tile[%0d] still available (exp removed)",
                     test_name, tid);
        else
            $display("  PASS %s: tile[%0d] correctly removed from tiles",
                     test_name, tid);
    endtask

    // ── Task: check domain locked correctly ───────────────────
    task automatic check_domain_locked(
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

    // ── Stimulus ───────────────────────────────────────────────
    initial begin
        init_all();
        #10;

        $display("-----------------------------------------");
        $display(" SingletonDetection Testbench  N=%0d", N);
        $display("-----------------------------------------");

        // ══════════════════════════════════════════════════════
        // TEST 1 — No singletons
        // All variables have full domains — nothing to detect
        // singleton_found=0, deadend=0
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 1: No singletons --");
        init_all();
        #10;
        check_flags(1'b0, 1'b0, "Test1");

        // ══════════════════════════════════════════════════════
        // TEST 2 — One singleton at var[3]
        // var[3] has only piece 5 in r0 (bit 5 set)
        // All other variables have full domains
        // Expected:
        //   singleton_found=1
        //   var[3] removed from variablesIncludedMask
        //   tile 5 removed from unassignedTiles
        //   r0[3] = bit5, r1/r2/r3[3] = 0
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 2: One singleton at var[3], piece 5 in r0 --");
        init_all();
        in_r0[3] = 16'b0000000000100000; // piece 5 only
        in_r1[3] = NONE;
        in_r2[3] = NONE;
        in_r3[3] = NONE;
        #10;
        check_flags(1'b1, 1'b0, "Test2");
        check_var_removed(3, "Test2");
        check_tile_removed(5, "Test2");
        check_domain_locked(3,
            16'b0000000000100000, NONE, NONE, NONE, "Test2");

        // ══════════════════════════════════════════════════════
        // TEST 3 — Singleton in r2 (rotation 2)
        // var[7] has only piece 9 in r2
        // Expected: r2[7] = bit9, r0/r1/r3[7] = 0
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 3: Singleton in r2 for var[7] --");
        init_all();
        in_r0[7] = NONE;
        in_r1[7] = NONE;
        in_r2[7] = 16'b0000001000000000; // piece 9 only
        in_r3[7] = NONE;
        #10;
        check_flags(1'b1, 1'b0, "Test3");
        check_var_removed(7, "Test3");
        check_tile_removed(9, "Test3");
        check_domain_locked(7,
            NONE, NONE, 16'b0000001000000000, NONE, "Test3");

        // ══════════════════════════════════════════════════════
        // TEST 4 — Two singletons simultaneously
        // var[2] has piece 3 in r1, var[10] has piece 7 in r3
        // Both detected in one pass
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 4: Two singletons simultaneously --");
        init_all();
        in_r0[2] = NONE;
        in_r1[2] = 16'b0000000000001000; // piece 3
        in_r2[2] = NONE;
        in_r3[2] = NONE;
        in_r0[10] = NONE;
        in_r1[10] = NONE;
        in_r2[10] = NONE;
        in_r3[10] = 16'b0000000010000000; // piece 7
        #10;
        check_flags(1'b1, 1'b0, "Test4");
        check_var_removed(2,  "Test4");
        check_var_removed(10, "Test4");
        check_tile_removed(3, "Test4");
        check_tile_removed(7, "Test4");
        check_domain_locked(2,
            NONE, 16'b0000000000001000, NONE, NONE, "Test4");
        check_domain_locked(10,
            NONE, NONE, NONE, 16'b0000000010000000, "Test4");

        // ══════════════════════════════════════════════════════
        // TEST 5 — Deadend: two variables forced to same tile
        // var[1] and var[5] both have only piece 4 remaining
        // After processing: variablesIncludedMask loses 2 bits
        // but unassignedTiles loses only 1 bit (tile 4)
        // counts diverge — deadend=1
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 5: Two variables forced to same tile — deadend --");
        init_all();
        in_r0[1] = 16'b0000000000010000; // piece 4 only
        in_r1[1] = NONE;
        in_r2[1] = NONE;
        in_r3[1] = NONE;
        in_r0[5] = 16'b0000000000010000; // piece 4 only (same tile!)
        in_r1[5] = NONE;
        in_r2[5] = NONE;
        in_r3[5] = NONE;
        #10;
        check_flags(1'b1, 1'b1, "Test5");

        // ══════════════════════════════════════════════════════
        // TEST 6 — Already assigned variable is skipped
        // var[3] is NOT in variablesIncludedMask (already singleton)
        // Even though it has one piece in domain — should be ignored
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 6: Already assigned variable skipped --");
        init_all();
        in_variablesIncludedMask[3] = 1'b0; // var 3 already assigned
        in_unassignedTiles[5]       = 1'b0; // tile 5 already placed with var 3
        in_r0[3] = 16'b0000000000100000;    // piece 5 — but should be ignored
        in_r1[3] = NONE;
        in_r2[3] = NONE;
        in_r3[3] = NONE;
        #10;
        check_flags(1'b0, 1'b0, "Test6");
        // var 3 mask bit should remain 0 (already was 0)
        if (out_variablesIncludedMask[3] !== 1'b0)
            $display("  FAIL Test6: var[3] mask changed unexpectedly");
        else
            $display("  PASS Test6: var[3] correctly ignored");
        // tile 5 was pre-removed and should remain removed
        if (out_unassignedTiles[5] !== 1'b0)
            $display("  FAIL Test6: tile[5] state changed unexpectedly");
        else
            $display("  PASS Test6: tile[5] correctly unchanged");

        $display("\n-----------------------------------------");
        $display(" Testbench complete");
        $display("-----------------------------------------");
        $finish;
    end

endmodule
