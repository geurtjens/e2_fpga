// ─────────────────────────────────────────────────────────────
// Testbench for LoadPuzzle — Puzzle_Brendan5
// 100 checks: 25 pieces x 4 rotations
// Expected values independently computed from puzzle definition
// ─────────────────────────────────────────────────────────────
module tb_load_puzzle;

    parameter int N         = 5;
    parameter int TC        = 8;
    parameter int VARIABLES = N * N;

    // ── DUT outputs ──────────────────────────────────────────
    logic [VARIABLES-1:0][TC-1:0] p0_top, p0_right, p0_bottom, p0_left;
    logic [VARIABLES-1:0][TC-1:0] p1_top, p1_right, p1_bottom, p1_left;
    logic [VARIABLES-1:0][TC-1:0] p2_top, p2_right, p2_bottom, p2_left;
    logic [VARIABLES-1:0][TC-1:0] p3_top, p3_right, p3_bottom, p3_left;

    // ── DUT ──────────────────────────────────────────────────
    LoadPuzzle #(.N(N), .TC(TC), .VARIABLES(VARIABLES)) dut (
        .p0_top(p0_top), .p0_right(p0_right),
        .p0_bottom(p0_bottom), .p0_left(p0_left),
        .p1_top(p1_top), .p1_right(p1_right),
        .p1_bottom(p1_bottom), .p1_left(p1_left),
        .p2_top(p2_top), .p2_right(p2_right),
        .p2_bottom(p2_bottom), .p2_left(p2_left),
        .p3_top(p3_top), .p3_right(p3_right),
        .p3_bottom(p3_bottom), .p3_left(p3_left)
    );

    // ── Waveform dump ────────────────────────────────────────
    initial begin
        $dumpfile("tb_load_puzzle.vcd");
        $dumpvars(0, tb_load_puzzle);
    end

    // ── Colour constants ─────────────────────────────────────
    localparam logic [TC-1:0] X = 8'b00000001;
    localparam logic [TC-1:0] A = 8'b00000010;
    localparam logic [TC-1:0] B = 8'b00000100;
    localparam logic [TC-1:0] C = 8'b00001000;
    localparam logic [TC-1:0] D = 8'b00010000;
    localparam logic [TC-1:0] E = 8'b00100000;
    localparam logic [TC-1:0] F = 8'b01000000;
    localparam logic [TC-1:0] G = 8'b10000000;

    // ── Task: check one piece at one rotation ────────────────
    task automatic check_piece(
        input int           pid,
        input int           rot,
        input logic [TC-1:0] exp_t, exp_r, exp_b, exp_l
    );
        logic [TC-1:0] got_t, got_r, got_b, got_l;
        case (rot)
            0: begin got_t=p0_top[pid]; got_r=p0_right[pid];
                     got_b=p0_bottom[pid]; got_l=p0_left[pid]; end
            1: begin got_t=p1_top[pid]; got_r=p1_right[pid];
                     got_b=p1_bottom[pid]; got_l=p1_left[pid]; end
            2: begin got_t=p2_top[pid]; got_r=p2_right[pid];
                     got_b=p2_bottom[pid]; got_l=p2_left[pid]; end
            3: begin got_t=p3_top[pid]; got_r=p3_right[pid];
                     got_b=p3_bottom[pid]; got_l=p3_left[pid]; end
            default: begin got_t='x; got_r='x; got_b='x; got_l='x; end
        endcase
        if (got_t !== exp_t || got_r !== exp_r ||
            got_b !== exp_b || got_l !== exp_l)
            $display("FAIL piece[%0d] r%0d: top=%b(exp %b) right=%b(exp %b) bottom=%b(exp %b) left=%b(exp %b)",
                     pid, rot,
                     got_t, exp_t, got_r, exp_r,
                     got_b, exp_b, got_l, exp_l);
        else
            $display("PASS piece[%0d] r%0d: top=%b right=%b bottom=%b left=%b",
                     pid, rot, got_t, got_r, got_b, got_l);
    endtask

    // ── Stimulus ─────────────────────────────────────────────
    initial begin
        #10;
        $display("-----------------------------------------");
        $display(" LoadPuzzle Testbench — Brendan5");
        $display("-----------------------------------------");

        $display("\n-- Rotation 0 --");
        check_piece( 0, 0, A, A, X, X);
        check_piece( 1, 0, B, A, X, X);
        check_piece( 2, 0, B, C, X, X);
        check_piece( 3, 0, C, A, X, X);
        check_piece( 4, 0, D, A, X, A);
        check_piece( 5, 0, D, C, X, A);
        check_piece( 6, 0, E, B, X, A);
        check_piece( 7, 0, E, C, X, A);
        check_piece( 8, 0, F, B, X, A);
        check_piece( 9, 0, E, B, X, B);
        check_piece(10, 0, F, C, X, B);
        check_piece(11, 0, G, C, X, B);
        check_piece(12, 0, D, A, X, C);
        check_piece(13, 0, F, A, X, C);
        check_piece(14, 0, F, B, X, C);
        check_piece(15, 0, G, B, X, C);
        check_piece(16, 0, D, D, E, F);
        check_piece(17, 0, D, E, D, F);
        check_piece(18, 0, D, E, E, F);
        check_piece(19, 0, D, E, G, G);
        check_piece(20, 0, D, F, E, F);
        check_piece(21, 0, D, F, G, G);
        check_piece(22, 0, D, G, E, E);
        check_piece(23, 0, E, F, G, G);
        check_piece(24, 0, F, G, G, G);

        $display("\n-- Rotation 1 --");
        check_piece( 0, 1, X, A, A, X);
        check_piece( 1, 1, X, B, A, X);
        check_piece( 2, 1, X, B, C, X);
        check_piece( 3, 1, X, C, A, X);
        check_piece( 4, 1, A, D, A, X);
        check_piece( 5, 1, A, D, C, X);
        check_piece( 6, 1, A, E, B, X);
        check_piece( 7, 1, A, E, C, X);
        check_piece( 8, 1, A, F, B, X);
        check_piece( 9, 1, B, E, B, X);
        check_piece(10, 1, B, F, C, X);
        check_piece(11, 1, B, G, C, X);
        check_piece(12, 1, C, D, A, X);
        check_piece(13, 1, C, F, A, X);
        check_piece(14, 1, C, F, B, X);
        check_piece(15, 1, C, G, B, X);
        check_piece(16, 1, F, D, D, E);
        check_piece(17, 1, F, D, E, D);
        check_piece(18, 1, F, D, E, E);
        check_piece(19, 1, G, D, E, G);
        check_piece(20, 1, F, D, F, E);
        check_piece(21, 1, G, D, F, G);
        check_piece(22, 1, E, D, G, E);
        check_piece(23, 1, G, E, F, G);
        check_piece(24, 1, G, F, G, G);

        $display("\n-- Rotation 2 --");
        check_piece( 0, 2, X, X, A, A);
        check_piece( 1, 2, X, X, B, A);
        check_piece( 2, 2, X, X, B, C);
        check_piece( 3, 2, X, X, C, A);
        check_piece( 4, 2, X, A, D, A);
        check_piece( 5, 2, X, A, D, C);
        check_piece( 6, 2, X, A, E, B);
        check_piece( 7, 2, X, A, E, C);
        check_piece( 8, 2, X, A, F, B);
        check_piece( 9, 2, X, B, E, B);
        check_piece(10, 2, X, B, F, C);
        check_piece(11, 2, X, B, G, C);
        check_piece(12, 2, X, C, D, A);
        check_piece(13, 2, X, C, F, A);
        check_piece(14, 2, X, C, F, B);
        check_piece(15, 2, X, C, G, B);
        check_piece(16, 2, E, F, D, D);
        check_piece(17, 2, D, F, D, E);
        check_piece(18, 2, E, F, D, E);
        check_piece(19, 2, G, G, D, E);
        check_piece(20, 2, E, F, D, F);
        check_piece(21, 2, G, G, D, F);
        check_piece(22, 2, E, E, D, G);
        check_piece(23, 2, G, G, E, F);
        check_piece(24, 2, G, G, F, G);

        $display("\n-- Rotation 3 --");
        check_piece( 0, 3, A, X, X, A);
        check_piece( 1, 3, A, X, X, B);
        check_piece( 2, 3, C, X, X, B);
        check_piece( 3, 3, A, X, X, C);
        check_piece( 4, 3, A, X, A, D);
        check_piece( 5, 3, C, X, A, D);
        check_piece( 6, 3, B, X, A, E);
        check_piece( 7, 3, C, X, A, E);
        check_piece( 8, 3, B, X, A, F);
        check_piece( 9, 3, B, X, B, E);
        check_piece(10, 3, C, X, B, F);
        check_piece(11, 3, C, X, B, G);
        check_piece(12, 3, A, X, C, D);
        check_piece(13, 3, A, X, C, F);
        check_piece(14, 3, B, X, C, F);
        check_piece(15, 3, B, X, C, G);
        check_piece(16, 3, D, E, F, D);
        check_piece(17, 3, E, D, F, D);
        check_piece(18, 3, E, E, F, D);
        check_piece(19, 3, E, G, G, D);
        check_piece(20, 3, F, E, F, D);
        check_piece(21, 3, F, G, G, D);
        check_piece(22, 3, G, E, E, D);
        check_piece(23, 3, F, G, G, E);
        check_piece(24, 3, G, G, G, F);

        $display("\n-----------------------------------------");
        $display(" Testbench complete — 100 checks");
        $display("-----------------------------------------");
        $finish;
    end

endmodule