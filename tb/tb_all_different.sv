// ─────────────────────────────────────────────────────────────
// Testbench for CalculateTilesTaken, AllDifferent and Driver
// N=4 — clean SystemVerilog for Quartus/ModelSim and Verilator
// ─────────────────────────────────────────────────────────────
module tb_all_different;

    parameter int N = 4;

    // ── Shared inputs ──────────────────────────────────────────
    logic [N-1:0][N-1:0] r0_in;
    logic [N-1:0][N-1:0] r1_in;
    logic [N-1:0][N-1:0] r2_in;
    logic [N-1:0][N-1:0] r3_in;
    logic [N-1:0]        variablesIncludedMask;

    // ── CalculateTilesTaken outputs ────────────────────────────
    logic [N-1:0] tilesTaken;

    // ── AllDifferent outputs ───────────────────────────────────
    logic [N-1:0][N-1:0] ad_r0_out;
    logic [N-1:0][N-1:0] ad_r1_out;
    logic [N-1:0][N-1:0] ad_r2_out;
    logic [N-1:0][N-1:0] ad_r3_out;
    logic                changed_ad;
    logic                deadend_ad;

    // ── Driver outputs ─────────────────────────────────────────
    logic [N-1:0][N-1:0] drv_r0_out;
    logic [N-1:0][N-1:0] drv_r1_out;
    logic [N-1:0][N-1:0] drv_r2_out;
    logic [N-1:0][N-1:0] drv_r3_out;
    logic                changed_drv;
    logic                deadend_drv;

    // ── Test number for waveform annotation ────────────────────
    int test_num;

    // ── DUT: CalculateTilesTaken ───────────────────────────────
    CalculateTilesTaken #(.N(N)) dut_ctt (
        .r0_in                 (r0_in),
        .r1_in                 (r1_in),
        .r2_in                 (r2_in),
        .r3_in                 (r3_in),
        .variablesIncludedMask (variablesIncludedMask),
        .tilesTaken            (tilesTaken)
    );

    // ── DUT: AllDifferent ──────────────────────────────────────
    AllDifferent #(.N(N)) dut_ad (
        .r0_in                 (r0_in),
        .r1_in                 (r1_in),
        .r2_in                 (r2_in),
        .r3_in                 (r3_in),
        .variablesIncludedMask (variablesIncludedMask),
        .tilesTaken            (tilesTaken),
        .r0_out                (ad_r0_out),
        .r1_out                (ad_r1_out),
        .r2_out                (ad_r2_out),
        .r3_out                (ad_r3_out),
        .changed               (changed_ad),
        .deadend               (deadend_ad)
    );

    // ── DUT: Driver ────────────────────────────────────────────
    Driver #(.N(N)) dut_drv (
        .r0_in                 (r0_in),
        .r1_in                 (r1_in),
        .r2_in                 (r2_in),
        .r3_in                 (r3_in),
        .variablesIncludedMask (variablesIncludedMask),
        .r0_out                (drv_r0_out),
        .r1_out                (drv_r1_out),
        .r2_out                (drv_r2_out),
        .r3_out                (drv_r3_out),
        .changed               (changed_drv),
        .deadend               (deadend_drv)
    );

    // ── Waveform dump ──────────────────────────────────────────
    initial begin
        $dumpfile("tb_all_different.vcd");
        $dumpvars(0, tb_all_different);
    end

    // ── Task: check CalculateTilesTaken ───────────────────────
    task automatic check_ctt(
        input logic [N-1:0] expected,
        input int           tnum
    );
        if (tilesTaken !== expected)
            $display("FAIL [CTT] Test%0d: tilesTaken=%b expected=%b",
                     tnum, tilesTaken, expected);
        else
            $display("PASS [CTT] Test%0d: tilesTaken=%b", tnum, tilesTaken);
    endtask

    // ── Task: check AllDifferent flags ─────────────────────────
    task automatic check_ad_flags(
        input logic exp_changed,
        input logic exp_deadend,
        input int   tnum
    );
        if (changed_ad !== exp_changed || deadend_ad !== exp_deadend)
            $display("FAIL [AD]  Test%0d: changed=%b(exp %b) deadend=%b(exp %b)",
                     tnum, changed_ad, exp_changed, deadend_ad, exp_deadend);
        else
            $display("PASS [AD]  Test%0d: changed=%b deadend=%b",
                     tnum, changed_ad, deadend_ad);
    endtask

    // ── Task: check AllDifferent per-variable outputs ──────────
    task automatic check_ad_vars(
        input logic [N-1:0][N-1:0] exp_r0,
        input logic [N-1:0][N-1:0] exp_r1,
        input logic [N-1:0][N-1:0] exp_r2,
        input logic [N-1:0][N-1:0] exp_r3,
        input int tnum
    );
        for (int i = 0; i < N; i++) begin
            if (ad_r0_out[i] !== exp_r0[i] || ad_r1_out[i] !== exp_r1[i] ||
                ad_r2_out[i] !== exp_r2[i] || ad_r3_out[i] !== exp_r3[i])
                $display("  FAIL [AD] Test%0d var[%0d]: r0=%b(exp %b) r1=%b(exp %b) r2=%b(exp %b) r3=%b(exp %b)",
                         tnum, i,
                         ad_r0_out[i], exp_r0[i],
                         ad_r1_out[i], exp_r1[i],
                         ad_r2_out[i], exp_r2[i],
                         ad_r3_out[i], exp_r3[i]);
        end
    endtask

    // ── Task: check Driver matches AllDifferent ────────────────
    task automatic check_driver_matches(input int tnum);
        if (changed_drv !== changed_ad || deadend_drv !== deadend_ad)
            $display("FAIL [DRV] Test%0d: changed=%b(AD %b) deadend=%b(AD %b)",
                     tnum, changed_drv, changed_ad, deadend_drv, deadend_ad);
        else
            $display("PASS [DRV] Test%0d: Driver outputs match AllDifferent", tnum);
        for (int i = 0; i < N; i++) begin
            if (drv_r0_out[i] !== ad_r0_out[i] || drv_r1_out[i] !== ad_r1_out[i] ||
                drv_r2_out[i] !== ad_r2_out[i] || drv_r3_out[i] !== ad_r3_out[i])
                $display("  FAIL [DRV] Test%0d var[%0d] mismatch vs AllDifferent",
                         tnum, i);
        end
    endtask

    // ── Test stimulus ──────────────────────────────────────────
    initial begin
        $display("-----------------------------------------");
        $display(" Starting Testbench  N=%0d", N);
        $display("-----------------------------------------");

        test_num = 0;
        variablesIncludedMask = '0;
        r0_in = '0; r1_in = '0; r2_in = '0; r3_in = '0;
        #10;

        // ══════════════════════════════════════════════════════
        // TEST 1 — No singletons, all variables active
        // tilesTaken=0 so outputs equal inputs, no change
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 1: No singletons, all active ----");
        test_num = 1;
        variablesIncludedMask = 4'b1111;
        r0_in[0]=4'b0001; r1_in[0]=4'b0010; r2_in[0]=4'b0100; r3_in[0]=4'b1000;
        r0_in[1]=4'b0011; r1_in[1]=4'b0011; r2_in[1]=4'b0011; r3_in[1]=4'b0011;
        r0_in[2]=4'b1111; r1_in[2]=4'b1111; r2_in[2]=4'b1111; r3_in[2]=4'b1111;
        r0_in[3]=4'b0101; r1_in[3]=4'b0101; r2_in[3]=4'b0101; r3_in[3]=4'b0101;
        #10;
        check_ctt(4'b0000, test_num);
        check_ad_flags(1'b0, 1'b0, test_num);
        check_ad_vars(
            16'b0101_1111_0011_0001,
            16'b0101_1111_0011_0010,
            16'b0101_1111_0011_0100,
            16'b0101_1111_0011_1000,
            test_num);
        check_driver_matches(test_num);

        // ══════════════════════════════════════════════════════
        // TEST 2 — One singleton (var0) holding bit 0
        // Active vars (1,2,3) lose bit 0
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 2: Singleton var[0]=bit0, active vars lose bit0 --");
        test_num = 2;
        variablesIncludedMask = 4'b1110;
        r0_in[0]=4'b0001; r1_in[0]=4'b0000; r2_in[0]=4'b0000; r3_in[0]=4'b0000;
        r0_in[1]=4'b0011; r1_in[1]=4'b0011; r2_in[1]=4'b0011; r3_in[1]=4'b0011;
        r0_in[2]=4'b1111; r1_in[2]=4'b1111; r2_in[2]=4'b1111; r3_in[2]=4'b1111;
        r0_in[3]=4'b0101; r1_in[3]=4'b0101; r2_in[3]=4'b0101; r3_in[3]=4'b0101;
        #10;
        check_ctt(4'b0001, test_num);
        check_ad_flags(1'b1, 1'b0, test_num);
        check_ad_vars(
            16'b0100_1110_0010_0001,
            16'b0100_1110_0010_0000,
            16'b0100_1110_0010_0000,
            16'b0100_1110_0010_0000,
            test_num);
        check_driver_matches(test_num);

        // ══════════════════════════════════════════════════════
        // TEST 3 — Deadend: singleton takes all bits of var1
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 3: Deadend -- active var[1] wiped out ----");
        test_num = 3;
        variablesIncludedMask = 4'b1110;
        r0_in[0]=4'b0011; r1_in[0]=4'b0011; r2_in[0]=4'b0011; r3_in[0]=4'b0011;
        r0_in[1]=4'b0001; r1_in[1]=4'b0001; r2_in[1]=4'b0001; r3_in[1]=4'b0001;
        r0_in[2]=4'b1100; r1_in[2]=4'b1100; r2_in[2]=4'b1100; r3_in[2]=4'b1100;
        r0_in[3]=4'b1100; r1_in[3]=4'b1100; r2_in[3]=4'b1100; r3_in[3]=4'b1100;
        #10;
        check_ctt(4'b0011, test_num);
        check_ad_flags(1'b1, 1'b1, test_num);
        check_ad_vars(
            16'b1100_1100_0000_0011,
            16'b1100_1100_0000_0011,
            16'b1100_1100_0000_0011,
            16'b1100_1100_0000_0011,
            test_num);
        check_driver_matches(test_num);

        // ══════════════════════════════════════════════════════
        // TEST 4 — All singletons, no active variables
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 4: All singletons, nothing active ----");
        test_num = 4;
        variablesIncludedMask = 4'b0000;
        r0_in[0]=4'b0001; r1_in[0]=4'b0000; r2_in[0]=4'b0000; r3_in[0]=4'b0000;
        r0_in[1]=4'b0010; r1_in[1]=4'b0000; r2_in[1]=4'b0000; r3_in[1]=4'b0000;
        r0_in[2]=4'b0100; r1_in[2]=4'b0000; r2_in[2]=4'b0000; r3_in[2]=4'b0000;
        r0_in[3]=4'b1000; r1_in[3]=4'b0000; r2_in[3]=4'b0000; r3_in[3]=4'b0000;
        #10;
        check_ctt(4'b1111, test_num);
        check_ad_flags(1'b0, 1'b0, test_num);
        check_ad_vars(
            16'b1000_0100_0010_0001,
            16'b0000_0000_0000_0000,
            16'b0000_0000_0000_0000,
            16'b0000_0000_0000_0000,
            test_num);
        check_driver_matches(test_num);

        // ══════════════════════════════════════════════════════
        // TEST 5 — Two singletons (var0,var1), two active (var2,var3)
        // ══════════════════════════════════════════════════════
        $display("\n-- Test 5: Two singletons, two active ----");
        test_num = 5;
        variablesIncludedMask = 4'b1100;
        r0_in[0]=4'b0001; r1_in[0]=4'b0000; r2_in[0]=4'b0000; r3_in[0]=4'b0000;
        r0_in[1]=4'b0000; r1_in[1]=4'b0010; r2_in[1]=4'b0000; r3_in[1]=4'b0000;
        r0_in[2]=4'b1111; r1_in[2]=4'b1111; r2_in[2]=4'b1111; r3_in[2]=4'b1111;
        r0_in[3]=4'b1111; r1_in[3]=4'b1111; r2_in[3]=4'b1111; r3_in[3]=4'b1111;
        #10;
        check_ctt(4'b0011, test_num);
        check_ad_flags(1'b1, 1'b0, test_num);
        check_ad_vars(
            16'b1100_1100_0000_0001,
            16'b1100_1100_0010_0000,
            16'b1100_1100_0000_0000,
            16'b1100_1100_0000_0000,
            test_num);
        check_driver_matches(test_num);

        #10;
        $display("\n-----------------------------------------");
        $display(" Testbench complete");
        $display("-----------------------------------------");
        $finish;
    end

endmodule
