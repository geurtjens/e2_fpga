// ─────────────────────────────────────────────────────────────
// tb_working_set
//
// Testbench for WorkingSet.
//
// Test plan:
//   1. Fill BRAM at gameId=2 with known patterns
//   2. Load gameId=2 → working registers, verify registers match
//   3. Simulate processing — commit updated values to registers
//   4. Save registers → BRAM at gameId=2, verify BRAM updated
//   5. Verify other gameId slots in BRAM are untouched
// ─────────────────────────────────────────────────────────────
module tb_working_set;

    // ── Parameters ─────────────────────────────────────────────
    localparam int N         = 4;
    localparam int TC        = 6;
    localparam int VARIABLES = N * N;
    localparam int ID_BITS   = $clog2(VARIABLES);
    localparam int DEPTH     = VARIABLES + 1;
    localparam int ADDR_BITS = $clog2(DEPTH * VARIABLES);
    localparam int COL_BITS  = 4 * TC;

    // Colour word slice positions
    localparam int TOP_LO    = 0;       localparam int TOP_HI    = TC-1;
    localparam int RIGHT_LO  = TC;      localparam int RIGHT_HI  = 2*TC-1;
    localparam int BOTTOM_LO = 2*TC;    localparam int BOTTOM_HI = 3*TC-1;
    localparam int LEFT_LO   = 3*TC;    localparam int LEFT_HI   = 4*TC-1;

    // ── Clock ──────────────────────────────────────────────────
    logic clk = 0;
    always #5 clk = ~clk;

    // ── DUT signals ────────────────────────────────────────────
    logic                     rst, load, save, commit, done, busy;
    logic [$clog2(DEPTH)-1:0] gameId;

    // Domain BRAM
    logic [ADDR_BITS-1:0]     dom_rd_addr;
    logic [VARIABLES-1:0]     dom_rd_r0, dom_rd_r1, dom_rd_r2, dom_rd_r3;
    logic                     dom_wr_en;
    logic [ADDR_BITS-1:0]     dom_wr_addr;
    logic [VARIABLES-1:0]     dom_wr_r0, dom_wr_r1, dom_wr_r2, dom_wr_r3;

    // Colour BRAM
    logic [ADDR_BITS-1:0]     col_rd_addr;
    logic [COL_BITS-1:0]      col_rd_data;
    logic                     col_wr_en;
    logic [ADDR_BITS-1:0]     col_wr_addr;
    logic [COL_BITS-1:0]      col_wr_data;

    // Working registers (outputs from DUT)
    logic [VARIABLES-1:0][VARIABLES-1:0] wrk_r0, wrk_r1, wrk_r2, wrk_r3;
    logic [VARIABLES-1:0][TC-1:0]        wrk_top, wrk_right, wrk_bottom, wrk_left;

    // New values (inputs to DUT from processing)
    logic [VARIABLES-1:0][VARIABLES-1:0] new_r0, new_r1, new_r2, new_r3;
    logic [VARIABLES-1:0][TC-1:0]        new_top, new_right, new_bottom, new_left;

    // ── BRAM model ─────────────────────────────────────────────
    logic [VARIABLES-1:0]  mem_r0  [0:DEPTH*VARIABLES-1];
    logic [VARIABLES-1:0]  mem_r1  [0:DEPTH*VARIABLES-1];
    logic [VARIABLES-1:0]  mem_r2  [0:DEPTH*VARIABLES-1];
    logic [VARIABLES-1:0]  mem_r3  [0:DEPTH*VARIABLES-1];
    logic [COL_BITS-1:0]   mem_col [0:DEPTH*VARIABLES-1];

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
    WorkingSet #(.N(N), .TC(TC)) dut (
        .clk         (clk),
        .rst         (rst),
        .load        (load),
        .save        (save),
        .gameId      (gameId),
        .done        (done),
        .busy        (busy),
        .dom_rd_addr (dom_rd_addr),
        .dom_rd_r0   (dom_rd_r0),
        .dom_rd_r1   (dom_rd_r1),
        .dom_rd_r2   (dom_rd_r2),
        .dom_rd_r3   (dom_rd_r3),
        .dom_wr_en   (dom_wr_en),
        .dom_wr_addr (dom_wr_addr),
        .dom_wr_r0   (dom_wr_r0),
        .dom_wr_r1   (dom_wr_r1),
        .dom_wr_r2   (dom_wr_r2),
        .dom_wr_r3   (dom_wr_r3),
        .col_rd_addr (col_rd_addr),
        .col_rd_data (col_rd_data),
        .col_wr_en   (col_wr_en),
        .col_wr_addr (col_wr_addr),
        .col_wr_data (col_wr_data),
        .wrk_r0      (wrk_r0),
        .wrk_r1      (wrk_r1),
        .wrk_r2      (wrk_r2),
        .wrk_r3      (wrk_r3),
        .wrk_top     (wrk_top),
        .wrk_right   (wrk_right),
        .wrk_bottom  (wrk_bottom),
        .wrk_left    (wrk_left),
        .new_r0      (new_r0),
        .new_r1      (new_r1),
        .new_r2      (new_r2),
        .new_r3      (new_r3),
        .new_top     (new_top),
        .new_right   (new_right),
        .new_bottom  (new_bottom),
        .new_left    (new_left),
        .commit      (commit)
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
    localparam int TEST_GAME_ID = 2;   // use gameId=2 to prove addressing works

    initial begin
        pass_count = 0;
        fail_count = 0;

        // Initialise BRAM and inputs
        for (int i = 0; i < DEPTH * VARIABLES; i++) begin
            mem_r0[i] = '0; mem_r1[i] = '0;
            mem_r2[i] = '0; mem_r3[i] = '0;
            mem_col[i] = '0;
        end
        load   = 0; save  = 0; commit = 0;
        gameId = 0;
        new_r0 = '0; new_r1 = '0; new_r2 = '0; new_r3 = '0;
        new_top = '0; new_right = '0; new_bottom = '0; new_left = '0;

        // Reset
        rst = 1;
        @(posedge clk); @(posedge clk);
        rst = 0;
        @(posedge clk);

        // ══════════════════════════════════════════════════════
        // TEST 1 — Load gameId=2 into working registers
        // ══════════════════════════════════════════════════════
        $display("\n=== TEST 1: Load BRAM[gameId=2] → working registers ===");

        // Fill gameId=2 slot with distinct patterns
        for (int v = 0; v < VARIABLES; v++) begin
            automatic int base = v + 1;
            mem_r0 [TEST_GAME_ID * VARIABLES + v] = VARIABLES'(base);
            mem_r1 [TEST_GAME_ID * VARIABLES + v] = VARIABLES'(base + 16);
            mem_r2 [TEST_GAME_ID * VARIABLES + v] = VARIABLES'(base + 32);
            mem_r3 [TEST_GAME_ID * VARIABLES + v] = VARIABLES'(base + 48);
            mem_col[TEST_GAME_ID * VARIABLES + v] = {
                TC'(base + 3),   // left
                TC'(base + 2),   // bottom
                TC'(base + 1),   // right
                TC'(base)        // top
            };
        end

        // Trigger load
        gameId = TEST_GAME_ID;
        @(posedge clk);
        load = 1;
        @(posedge clk);
        load = 0;
        @(posedge done);
        @(posedge clk);

        // Verify working registers
        $display("\n--- Verifying working registers after load ---");
        for (int v = 0; v < VARIABLES; v++) begin
            automatic int base = v + 1;
            $display("  variable %0d:", v);
            check_dom($sformatf("wrk_r0[%0d]",     v), wrk_r0[v],     VARIABLES'(base));
            check_dom($sformatf("wrk_r1[%0d]",     v), wrk_r1[v],     VARIABLES'(base + 16));
            check_dom($sformatf("wrk_r2[%0d]",     v), wrk_r2[v],     VARIABLES'(base + 32));
            check_dom($sformatf("wrk_r3[%0d]",     v), wrk_r3[v],     VARIABLES'(base + 48));
            check_edge($sformatf("wrk_top[%0d]",    v), wrk_top[v],    TC'(base));
            check_edge($sformatf("wrk_right[%0d]",  v), wrk_right[v],  TC'(base + 1));
            check_edge($sformatf("wrk_bottom[%0d]", v), wrk_bottom[v], TC'(base + 2));
            check_edge($sformatf("wrk_left[%0d]",   v), wrk_left[v],   TC'(base + 3));
        end

        // ══════════════════════════════════════════════════════
        // TEST 2 — Commit updated values (simulating processing)
        // ══════════════════════════════════════════════════════
        $display("\n=== TEST 2: Commit updated values from processing ===");

        // Simulate processing result — invert all domain bits
        for (int v = 0; v < VARIABLES; v++) begin
            automatic int base = v + 1;
            new_r0[v]     = ~VARIABLES'(base);
            new_r1[v]     = ~VARIABLES'(base + 16);
            new_r2[v]     = ~VARIABLES'(base + 32);
            new_r3[v]     = ~VARIABLES'(base + 48);
            new_top[v]    = ~TC'(base);
            new_right[v]  = ~TC'(base + 1);
            new_bottom[v] = ~TC'(base + 2);
            new_left[v]   = ~TC'(base + 3);
        end

        @(posedge clk);
        commit = 1;
        @(posedge clk);
        commit = 0;
        @(posedge clk);

        // Verify working registers updated
        $display("\n--- Verifying working registers after commit ---");
        for (int v = 0; v < VARIABLES; v++) begin
            automatic int base = v + 1;
            $display("  variable %0d:", v);
            check_dom($sformatf("wrk_r0[%0d]",     v), wrk_r0[v],     ~VARIABLES'(base));
            check_dom($sformatf("wrk_r1[%0d]",     v), wrk_r1[v],     ~VARIABLES'(base + 16));
            check_dom($sformatf("wrk_r2[%0d]",     v), wrk_r2[v],     ~VARIABLES'(base + 32));
            check_dom($sformatf("wrk_r3[%0d]",     v), wrk_r3[v],     ~VARIABLES'(base + 48));
            check_edge($sformatf("wrk_top[%0d]",    v), wrk_top[v],    ~TC'(base));
            check_edge($sformatf("wrk_right[%0d]",  v), wrk_right[v],  ~TC'(base + 1));
            check_edge($sformatf("wrk_bottom[%0d]", v), wrk_bottom[v], ~TC'(base + 2));
            check_edge($sformatf("wrk_left[%0d]",   v), wrk_left[v],   ~TC'(base + 3));
        end

        // ══════════════════════════════════════════════════════
        // TEST 3 — Save working registers → BRAM[gameId=2]
        // ══════════════════════════════════════════════════════
        $display("\n=== TEST 3: Save working registers → BRAM[gameId=2] ===");

        gameId = TEST_GAME_ID;
        @(posedge clk);
        save = 1;
        @(posedge clk);
        save = 0;
        @(posedge done);
        @(posedge clk);

        // Verify BRAM updated with new values
        $display("\n--- Verifying BRAM after save ---");
        for (int v = 0; v < VARIABLES; v++) begin
            automatic int addr = TEST_GAME_ID * VARIABLES + v;
            automatic int base = v + 1;
            $display("  variable %0d:", v);
            check_dom($sformatf("mem_r0[%0d]",     v), mem_r0[addr],  ~VARIABLES'(base));
            check_dom($sformatf("mem_r1[%0d]",     v), mem_r1[addr],  ~VARIABLES'(base + 16));
            check_dom($sformatf("mem_r2[%0d]",     v), mem_r2[addr],  ~VARIABLES'(base + 32));
            check_dom($sformatf("mem_r3[%0d]",     v), mem_r3[addr],  ~VARIABLES'(base + 48));
            check_edge($sformatf("top[%0d]",    v),
                mem_col[addr][TOP_HI:TOP_LO],    ~TC'(base));
            check_edge($sformatf("right[%0d]",  v),
                mem_col[addr][RIGHT_HI:RIGHT_LO],  ~TC'(base + 1));
            check_edge($sformatf("bottom[%0d]", v),
                mem_col[addr][BOTTOM_HI:BOTTOM_LO], ~TC'(base + 2));
            check_edge($sformatf("left[%0d]",   v),
                mem_col[addr][LEFT_HI:LEFT_LO],   ~TC'(base + 3));
        end

        // ── Verify other gameId slots untouched ────────────────
        $display("\n--- Verifying other gameId slots untouched ---");
        for (int v = 0; v < VARIABLES; v++) begin
            check_dom($sformatf("gameId=0 r0[%0d]", v),
                mem_r0[0 * VARIABLES + v], '0);
            check_dom($sformatf("gameId=1 r0[%0d]", v),
                mem_r0[1 * VARIABLES + v], '0);
            check_dom($sformatf("gameId=3 r0[%0d]", v),
                mem_r0[3 * VARIABLES + v], '0);
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
        #20000;
        $display("TIMEOUT — simulation did not complete");
        $stop;
    end

endmodule
