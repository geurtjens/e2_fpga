// ─────────────────────────────────────────────────────────────
// Testbench for CreateInitialGame
// N=4, BORDER_COLOUR_COUNT=3, INNER_COLOUR_COUNT=2
// Clean SystemVerilog for Quartus/ModelSim and Verilator
//
// Board layout (variableId = y*N + x):
//  0  1  2  3    y=0  top row
//  4  5  6  7    y=1
//  8  9 10 11    y=2
// 12 13 14 15    y=3  bottom row
//
// Colour masks (TC=6 bits):
//   BOUNDARY = 6'b000001
//   BORDER   = 6'b001110
//   INNER_C  = 6'b110000
//
// Domain masks (VARIABLES=16 bits):
//   FIXED_CORNER = 16'b0000000000000001  (var 0 only)
//   FREE_CORNER  = 16'b0000000000001110  (any of 3 free corners)
//   EDGE_D       = 16'b0000111111110000  (8 edge pieces)
//   INNER_D      = 16'b1111000000000000  (4 inner pieces)
// ─────────────────────────────────────────────────────────────
module tb_create_initial_game;

    parameter int N                   = 4;
    parameter int BORDER_COLOUR_COUNT = 3;
    parameter int INNER_COLOUR_COUNT  = 2;
    parameter int TC                  = 1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT;
    parameter int VARIABLES           = N * N;

    // ── DUT outputs ────────────────────────────────────────────
    logic [VARIABLES-1:0][TC-1:0]        top, right, bottom, left;
    logic [VARIABLES-1:0][VARIABLES-1:0] r0, r1, r2, r3;
    logic [VARIABLES-1:0]                variablesIncludedMask;

    // ── DUT ────────────────────────────────────────────────────
    CreateInitialGame #(
        .N                   (N),
        .BORDER_COLOUR_COUNT (BORDER_COLOUR_COUNT),
        .INNER_COLOUR_COUNT  (INNER_COLOUR_COUNT),
        .TC                  (TC)
    ) dut (
        .top                  (top),
        .right                (right),
        .bottom               (bottom),
        .left                 (left),
        .r0                   (r0),
        .r1                   (r1),
        .r2                   (r2),
        .r3                   (r3),
        .variablesIncludedMask (variablesIncludedMask)
    );

    // ── Waveform dump ──────────────────────────────────────────
    initial begin
        $dumpfile("tb_create_initial_game.vcd");
        $dumpvars(0, tb_create_initial_game);
    end

    // ── Known colour masks ─────────────────────────────────────
    localparam logic [TC-1:0]        BOUNDARY    = 6'b000001;
    localparam logic [TC-1:0]        BORDER      = 6'b001110;
    localparam logic [TC-1:0]        INNER_C     = 6'b110000;

    // ── Known domain masks ─────────────────────────────────────
    localparam logic [VARIABLES-1:0] FIXED_CORNER = 16'b0000000000000001;
    localparam logic [VARIABLES-1:0] FREE_CORNER  = 16'b0000000000001110;
    localparam logic [VARIABLES-1:0] EDGE_D       = 16'b0000111111110000;
    localparam logic [VARIABLES-1:0] INNER_D      = 16'b1111000000000000;
    localparam logic [VARIABLES-1:0] ZERO_D       = '0;
    localparam logic [TC-1:0]        ZERO_C       = '0;

    // ── Task: check one variable's colours ────────────────────
    task automatic check_colours(
        input int           id,
        input logic [TC-1:0] exp_top, exp_right, exp_bottom, exp_left
    );
        if (top[id]    !== exp_top    || right[id]  !== exp_right ||
            bottom[id] !== exp_bottom || left[id]   !== exp_left)
            $display("FAIL colours var[%0d]: top=%b(exp %b) right=%b(exp %b) bottom=%b(exp %b) left=%b(exp %b)",
                     id,
                     top[id],    exp_top,
                     right[id],  exp_right,
                     bottom[id], exp_bottom,
                     left[id],   exp_left);
        else
            $display("PASS colours var[%0d]: top=%b right=%b bottom=%b left=%b",
                     id, top[id], right[id], bottom[id], left[id]);
    endtask

    // ── Task: check one variable's domain ─────────────────────
    task automatic check_domain(
        input int                id,
        input logic [VARIABLES-1:0] exp_r0, exp_r1, exp_r2, exp_r3
    );
        if (r0[id] !== exp_r0 || r1[id] !== exp_r1 ||
            r2[id] !== exp_r2 || r3[id] !== exp_r3)
            $display("FAIL domain  var[%0d]: r0=%b(exp %b) r1=%b(exp %b) r2=%b(exp %b) r3=%b(exp %b)",
                     id,
                     r0[id], exp_r0,
                     r1[id], exp_r1,
                     r2[id], exp_r2,
                     r3[id], exp_r3);
        else
            $display("PASS domain  var[%0d]: r0=%b r1=%b r2=%b r3=%b",
                     id, r0[id], r1[id], r2[id], r3[id]);
    endtask

    // ── Stimulus ───────────────────────────────────────────────
    initial begin
        #10;
        $display("-----------------------------------------");
        $display(" CreateInitialGame Testbench N=%0d BC=%0d IC=%0d",
                 N, BORDER_COLOUR_COUNT, INNER_COLOUR_COUNT);
        $display("-----------------------------------------");

        // variablesIncludedMask
        if (variablesIncludedMask !== 16'b0000000000000001)
            $display("FAIL variablesIncludedMask=%b expected 0000000000000001",
                     variablesIncludedMask);
        else
            $display("PASS variablesIncludedMask=%b", variablesIncludedMask);

        $display("\n-- Corners --");

        // var 0 — top-left (x=0,y=0) — fixed starting piece
        $display("-- var[0] top-left corner");
        check_colours(0, BOUNDARY, BORDER,   BORDER,   BOUNDARY);
        check_domain (0, ZERO_D,   FIXED_CORNER, ZERO_D, ZERO_D);

        // var 3 — top-right (x=3,y=0)
        $display("-- var[3] top-right corner");
        check_colours(3, BOUNDARY, BOUNDARY, BORDER,   BORDER);
        check_domain (3, FREE_CORNER, FREE_CORNER, FREE_CORNER, FREE_CORNER);

        // var 12 — bottom-left (x=0,y=3)
        $display("-- var[12] bottom-left corner");
        check_colours(12, BORDER,   BORDER,   BOUNDARY, BOUNDARY);
        check_domain (12, FREE_CORNER, FREE_CORNER, FREE_CORNER, FREE_CORNER);

        // var 15 — bottom-right (x=3,y=3)
        $display("-- var[15] bottom-right corner");
        check_colours(15, BORDER,   BOUNDARY, BOUNDARY, BORDER);
        check_domain (15, FREE_CORNER, FREE_CORNER, FREE_CORNER, FREE_CORNER);

        $display("\n-- Left Edge --");

        $display("-- var[4] left edge (x=0,y=1)");
        check_colours(4, BORDER,   INNER_C,  BORDER,   BOUNDARY);
        check_domain (4, ZERO_D, EDGE_D, ZERO_D, ZERO_D);

        $display("-- var[8] left edge (x=0,y=2)");
        check_colours(8, BORDER,   INNER_C,  BORDER,   BOUNDARY);
        check_domain (8, ZERO_D, EDGE_D, ZERO_D, ZERO_D);

        $display("\n-- Right Edge --");

        $display("-- var[7] right edge (x=3,y=1)");
        check_colours(7, BORDER,   BOUNDARY, BORDER,   INNER_C);
        check_domain (7, ZERO_D, ZERO_D, ZERO_D, EDGE_D);

        $display("-- var[11] right edge (x=3,y=2)");
        check_colours(11, BORDER,   BOUNDARY, BORDER,   INNER_C);
        check_domain (11, ZERO_D, ZERO_D, ZERO_D, EDGE_D);

        $display("\n-- Top Edge --");

        $display("-- var[1] top edge (x=1,y=0)");
        check_colours(1, BOUNDARY, BORDER,   INNER_C,  BORDER);
        check_domain (1, ZERO_D, EDGE_D, ZERO_D, ZERO_D);

        $display("-- var[2] top edge (x=2,y=0)");
        check_colours(2, BOUNDARY, BORDER,   INNER_C,  BORDER);
        check_domain (2, ZERO_D, EDGE_D, ZERO_D, ZERO_D);

        $display("\n-- Bottom Edge --");

        $display("-- var[13] bottom edge (x=1,y=3)");
        check_colours(13, INNER_C,  BORDER,   BOUNDARY, BORDER);
        check_domain (13, EDGE_D, ZERO_D, ZERO_D, ZERO_D);

        $display("-- var[14] bottom edge (x=2,y=3)");
        check_colours(14, INNER_C,  BORDER,   BOUNDARY, BORDER);
        check_domain (14, EDGE_D, ZERO_D, ZERO_D, ZERO_D);

        $display("\n-- Inner Variables --");

        $display("-- var[5] inner (x=1,y=1)");
        check_colours(5, INNER_C, INNER_C, INNER_C, INNER_C);
        check_domain (5, INNER_D, INNER_D, INNER_D, INNER_D);

        $display("-- var[6] inner (x=2,y=1)");
        check_colours(6, INNER_C, INNER_C, INNER_C, INNER_C);
        check_domain (6, INNER_D, INNER_D, INNER_D, INNER_D);

        $display("-- var[9] inner (x=1,y=2)");
        check_colours(9, INNER_C, INNER_C, INNER_C, INNER_C);
        check_domain (9, INNER_D, INNER_D, INNER_D, INNER_D);

        $display("-- var[10] inner (x=2,y=2)");
        check_colours(10, INNER_C, INNER_C, INNER_C, INNER_C);
        check_domain (10, INNER_D, INNER_D, INNER_D, INNER_D);

        $display("\n-----------------------------------------");
        $display(" Testbench complete");
        $display("-----------------------------------------");
        $finish;
    end

endmodule
