// ─────────────────────────────────────────────────────────────
// tb_copy_level
//
// Testbench for CopyLevel.
//
// Colour BRAM word packing (matches CopyLevel):
//   col = { left[TC-1:0], bottom[TC-1:0], right[TC-1:0], top[TC-1:0] }
//
// Test plan:
//   1. Fill gameId=0 with distinct patterns per rotation and edge
//   2. Pulse start with gameId=0
//   3. Wait for done
//   4. Unpack and verify gameId=1 for each of:
//        r0, r1, r2, r3, top, right, bottom, left
//   5. Verify availableVariables and availableTiles
//   6. Verify gameId=0 source is unchanged
// ─────────────────────────────────────────────────────────────
module tb_copy_level;

    // ── Parameters ─────────────────────────────────────────────
    localparam int N         = 4;
    localparam int TC        = 6;
    localparam int VARIABLES = N * N;          // 16
    localparam int ID_BITS   = $clog2(VARIABLES);
    localparam int DEPTH     = VARIABLES + 1;  // 17
    localparam int ADDR_BITS = $clog2(DEPTH * VARIABLES);
    localparam int COL_BITS  = 4 * TC;        // 24

    // Colour word slice positions — must match CopyLevel packing
    localparam int TOP_LO    = 0;
    localparam int TOP_HI    = TC - 1;
    localparam int RIGHT_LO  = TC;
    localparam int RIGHT_HI  = 2*TC - 1;
    localparam int BOTTOM_LO = 2*TC;
    localparam int BOTTOM_HI = 3*TC - 1;
    localparam int LEFT_LO   = 3*TC;
    localparam int LEFT_HI   = 4*TC - 1;

    // ── Clock ──────────────────────────────────────────────────
    logic clk = 0;
    always #5 clk = ~clk;   // 100 MHz

    // ── DUT signals ────────────────────────────────────────────
    logic                     rst;
    logic                     start;
    logic [$clog2(DEPTH)-1:0] gameId;

    logic [ADDR_BITS-1:0]     dom_rd_addr;
    logic [VARIABLES-1:0]     dom_rd_r0, dom_rd_r1, dom_rd_r2, dom_rd_r3;

    logic                     dom_wr_en;
    logic [ADDR_BITS-1:0]     dom_wr_addr;
    logic [VARIABLES-1:0]     dom_wr_r0, dom_wr_r1, dom_wr_r2, dom_wr_r3;

    logic [ADDR_BITS-1:0]     col_rd_addr;
    logic [COL_BITS-1:0]      col_rd_data;

    logic                     col_wr_en;
    logic [ADDR_BITS-1:0]     col_wr_addr;
    logic [COL_BITS-1:0]      col_wr_data;

    logic [VARIABLES-1:0]     in_availableVariables;
    logic [VARIABLES-1:0]     in_availableTiles;
    logic [VARIABLES-1:0]     out_availableVariables;
    logic [VARIABLES-1:0]     out_availableTiles;
    logic                     out_valid;
    logic                     done;

    // ── BRAM model ─────────────────────────────────────────────
    logic [VARIABLES-1:0]  mem_r0  [0:DEPTH*VARIABLES-1];
    logic [VARIABLES-1:0]  mem_r1  [0:DEPTH*VARIABLES-1];
    logic [VARIABLES-1:0]  mem_r2  [0:DEPTH*VARIABLES-1];
    logic [VARIABLES-1:0]  mem_r3  [0:DEPTH*VARIABLES-1];
    logic [COL_BITS-1:0]   mem_col [0:DEPTH*VARIABLES-1];

    // Synchronous read — one cycle latency matching Cyclone V M10K
    always_ff @(posedge clk) begin
        dom_rd_r0   <= mem_r0 [dom_rd_addr];
        dom_rd_r1   <= mem_r1 [dom_rd_addr];
        dom_rd_r2   <= mem_r2 [dom_rd_addr];
        dom_rd_r3   <= mem_r3 [dom_rd_addr];
        col_rd_data <= mem_col[col_rd_addr];
    end

    always_ff @(posedge clk) begin
        if (dom_wr_en) begin
            mem_r0[dom_wr_addr] <= dom_wr_r0;
            mem_r1[dom_wr_addr] <= dom_wr_r1;
            mem_r2[dom_wr_addr] <= dom_wr_r2;
            mem_r3[dom_wr_addr] <= dom_wr_r3;
        end
        if (col_wr_en)
            mem_col[col_wr_addr] <= col_wr_data;
    end

    // ── DUT instantiation ──────────────────────────────────────
    CopyLevel #(.N(N), .TC(TC)) dut (
        .clk                    (clk),
        .rst                    (rst),
        .start                  (start),
        .gameId                 (gameId),
        .dom_rd_addr            (dom_rd_addr),
        .dom_rd_r0              (dom_rd_r0),
        .dom_rd_r1              (dom_rd_r1),
        .dom_rd_r2              (dom_rd_r2),
        .dom_rd_r3              (dom_rd_r3),
        .dom_wr_en              (dom_wr_en),
        .dom_wr_addr            (dom_wr_addr),
        .dom_wr_r0              (dom_wr_r0),
        .dom_wr_r1              (dom_wr_r1),
        .dom_wr_r2              (dom_wr_r2),
        .dom_wr_r3              (dom_wr_r3),
        .col_rd_addr            (col_rd_addr),
        .col_rd_data            (col_rd_data),
        .col_wr_en              (col_wr_en),
        .col_wr_addr            (col_wr_addr),
        .col_wr_data            (col_wr_data),
        .in_availableVariables  (in_availableVariables),
        .in_availableTiles      (in_availableTiles),
        .out_availableVariables (out_availableVariables),
        .out_availableTiles     (out_availableTiles),
        .out_valid              (out_valid),
        .done                   (done)
    );

    // ── Check tasks ────────────────────────────────────────────
    int pass_count;
    int fail_count;

    task automatic check_dom;
        input string               label;
        input logic [VARIABLES-1:0] got;
        input logic [VARIABLES-1:0] expected;
        if (got === expected) begin
            $display("  PASS  %s = %0h", label, got);
            pass_count++;
        end else begin
            $display("  FAIL  %s — got %0h, expected %0h",
                     label, got, expected);
            fail_count++;
        end
    endtask

    task automatic check_edge;
        input string         label;
        input logic [TC-1:0] got;
        input logic [TC-1:0] expected;
        if (got === expected) begin
            $display("  PASS  %s = %0h", label, got);
            pass_count++;
        end else begin
            $display("  FAIL  %s — got %0h, expected %0h",
                     label, got, expected);
            fail_count++;
        end
    endtask

    // ── Test stimulus ──────────────────────────────────────────
    initial begin
        pass_count = 0;
        fail_count = 0;

        for (int i = 0; i < DEPTH * VARIABLES; i++) begin
            mem_r0[i]  = '0;
            mem_r1[i]  = '0;
            mem_r2[i]  = '0;
            mem_r3[i]  = '0;
            mem_col[i] = '0;
        end

        rst    = 1;
        start  = 0;
        gameId = 0;
        in_availableVariables = '0;
        in_availableTiles     = '0;
        @(posedge clk);
        @(posedge clk);
        rst = 0;
        @(posedge clk);

        // ── Fill gameId=0 with distinct patterns ───────────────
        // Each rotation and each edge gets a clearly different
        // value so a swap between any two would be caught
        $display("\n--- Filling gameId=0 with test patterns ---");
        for (int v = 0; v < VARIABLES; v++) begin
            automatic int        base = v + 1;
            automatic logic [TC-1:0] t, r, b, l;

            // Domains — each rotation offset by 16 from the last
            mem_r0[0 * VARIABLES + v] = VARIABLES'(base);
            mem_r1[0 * VARIABLES + v] = VARIABLES'(base + 16);
            mem_r2[0 * VARIABLES + v] = VARIABLES'(base + 32);
            mem_r3[0 * VARIABLES + v] = VARIABLES'(base + 48);

            // Colour edges — each edge offset by 1 from the last
            // packed as { left, bottom, right, top }
            t = TC'(base);
            r = TC'(base + 1);
            b = TC'(base + 2);
            l = TC'(base + 3);
            mem_col[0 * VARIABLES + v] = { l, b, r, t };
        end

        in_availableVariables = 16'hABCD;
        in_availableTiles     = 16'h1234;

        // ── Trigger copy gameId=0 → gameId=1 ──────────────────
        $display("\n--- Starting copy: gameId=0 → gameId=1 ---");
        gameId = 0;
        @(posedge clk);
        start = 1;
        @(posedge clk);
        start = 0;

        @(posedge done);
        @(posedge clk);

        // ── Verify domains ─────────────────────────────────────
        $display("\n--- Verifying domains (r0, r1, r2, r3) ---");
        for (int v = 0; v < VARIABLES; v++) begin
            automatic int dst  = 1 * VARIABLES + v;
            automatic int base = v + 1;
            $display("  variable %0d:", v);
            check_dom($sformatf("r0[%0d]", v),
                mem_r0[dst], VARIABLES'(base));
            check_dom($sformatf("r1[%0d]", v),
                mem_r1[dst], VARIABLES'(base + 16));
            check_dom($sformatf("r2[%0d]", v),
                mem_r2[dst], VARIABLES'(base + 32));
            check_dom($sformatf("r3[%0d]", v),
                mem_r3[dst], VARIABLES'(base + 48));
        end

        // ── Verify colour edges ────────────────────────────────
        $display("\n--- Verifying colour edges (top, right, bottom, left) ---");
        for (int v = 0; v < VARIABLES; v++) begin
            automatic int dst  = 1 * VARIABLES + v;
            automatic int base = v + 1;
            $display("  variable %0d:", v);
            check_edge($sformatf("top[%0d]",    v),
                mem_col[dst][TOP_HI:TOP_LO],       TC'(base));
            check_edge($sformatf("right[%0d]",  v),
                mem_col[dst][RIGHT_HI:RIGHT_LO],   TC'(base + 1));
            check_edge($sformatf("bottom[%0d]", v),
                mem_col[dst][BOTTOM_HI:BOTTOM_LO], TC'(base + 2));
            check_edge($sformatf("left[%0d]",   v),
                mem_col[dst][LEFT_HI:LEFT_LO],     TC'(base + 3));
        end

        // ── Verify metadata ────────────────────────────────────
        $display("\n--- Verifying metadata ---");
        check_dom("availableVariables", out_availableVariables, 16'hABCD);
        check_dom("availableTiles",     out_availableTiles,     16'h1234);

        // ── Verify gameId=0 source unchanged ──────────────────
        $display("\n--- Verifying gameId=0 source is unchanged ---");
        for (int v = 0; v < VARIABLES; v++) begin
            automatic int src  = 0 * VARIABLES + v;
            automatic int base = v + 1;
            $display("  variable %0d:", v);
            check_dom($sformatf("r0[%0d]", v),
                mem_r0[src], VARIABLES'(base));
            check_dom($sformatf("r1[%0d]", v),
                mem_r1[src], VARIABLES'(base + 16));
            check_dom($sformatf("r2[%0d]", v),
                mem_r2[src], VARIABLES'(base + 32));
            check_dom($sformatf("r3[%0d]", v),
                mem_r3[src], VARIABLES'(base + 48));
            check_edge($sformatf("top[%0d]",    v),
                mem_col[src][TOP_HI:TOP_LO],       TC'(base));
            check_edge($sformatf("right[%0d]",  v),
                mem_col[src][RIGHT_HI:RIGHT_LO],   TC'(base + 1));
            check_edge($sformatf("bottom[%0d]", v),
                mem_col[src][BOTTOM_HI:BOTTOM_LO], TC'(base + 2));
            check_edge($sformatf("left[%0d]",   v),
                mem_col[src][LEFT_HI:LEFT_LO],     TC'(base + 3));
        end

        // ── Summary ────────────────────────────────────────────
        $display("\n===========================================");
        $display("  Results: %0d passed, %0d failed",
                 pass_count, fail_count);
        if (fail_count == 0)
            $display("  ALL TESTS PASSED");
        else
            $display("  FAILURES DETECTED");
        $display("===========================================\n");

        $stop;
    end

    // ── Timeout watchdog ───────────────────────────────────────
    initial begin
        #10000;
        $display("TIMEOUT — simulation did not complete");
        $stop;
    end

endmodule
