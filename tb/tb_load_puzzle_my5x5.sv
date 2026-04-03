// ─────────────────────────────────────────────────────────────
// Testbench for LoadPuzzle — Puzzle_My5x5
// 100 checks: 25 pieces x 4 rotations
// Expected values independently computed from puzzle definition
// ─────────────────────────────────────────────────────────────
module tb_load_puzzle;

    parameter int N         = 5;
    parameter int TC        = 23;
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
    localparam logic [TC-1:0] X = 23'b00000000000000000000001;
    localparam logic [TC-1:0] A = 23'b00000000000000000000010;
    localparam logic [TC-1:0] B = 23'b00000000000000000000100;
    localparam logic [TC-1:0] C = 23'b00000000000000000001000;
    localparam logic [TC-1:0] D = 23'b00000000000000000010000;
    localparam logic [TC-1:0] E = 23'b00000000000000000100000;
    localparam logic [TC-1:0] F = 23'b00000000000000001000000;
    localparam logic [TC-1:0] G = 23'b00000000000000010000000;
    localparam logic [TC-1:0] H = 23'b00000000000000100000000;
    localparam logic [TC-1:0] I = 23'b00000000000001000000000;
    localparam logic [TC-1:0] J = 23'b00000000000010000000000;
    localparam logic [TC-1:0] K = 23'b00000000000100000000000;
    localparam logic [TC-1:0] L = 23'b00000000001000000000000;
    localparam logic [TC-1:0] M = 23'b00000000010000000000000;
    localparam logic [TC-1:0] N = 23'b00000000100000000000000;
    localparam logic [TC-1:0] O = 23'b00000001000000000000000;
    localparam logic [TC-1:0] P = 23'b00000010000000000000000;
    localparam logic [TC-1:0] Q = 23'b00000100000000000000000;
    localparam logic [TC-1:0] R = 23'b00001000000000000000000;
    localparam logic [TC-1:0] S = 23'b00010000000000000000000;
    localparam logic [TC-1:0] T = 23'b00100000000000000000000;
    localparam logic [TC-1:0] U = 23'b01000000000000000000000;
    localparam logic [TC-1:0] V = 23'b10000000000000000000000;

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
        $display(" LoadPuzzle Testbench — My5x5");
        $display("-----------------------------------------");

        $display("\n-- Rotation 0 --");
        check_piece( 0, 0, A, D, X, X);
        check_piece( 1, 0, E, C, X, X);
        check_piece( 2, 0, A, B, X, X);
        check_piece( 3, 0, E, E, X, X);
        check_piece( 4, 0, K, D, X, A);
        check_piece( 5, 0, U, E, X, B);
        check_piece( 6, 0, P, C, X, B);
        check_piece( 7, 0, V, A, X, E);
        check_piece( 8, 0, F, A, X, D);
        check_piece( 9, 0, R, C, X, E);
        check_piece(10, 0, G, B, X, D);
        check_piece(11, 0, N, A, X, B);
        check_piece(12, 0, U, E, X, D);
        check_piece(13, 0, R, D, X, C);
        check_piece(14, 0, S, B, X, C);
        check_piece(15, 0, H, E, X, C);
        check_piece(16, 0, I, R, P, S);
        check_piece(17, 0, P, T, O, L);
        check_piece(18, 0, Q, N, V, J);
        check_piece(19, 0, H, L, T, S);
        check_piece(20, 0, S, M, V, O);
        check_piece(21, 0, F, I, T, G);
        check_piece(22, 0, U, Q, P, R);
        check_piece(23, 0, Q, M, Q, K);
        check_piece(24, 0, U, T, V, J);

        $display("\n-- Rotation 1 --");
        check_piece( 0, 1, X, A, D, X);
        check_piece( 1, 1, X, E, C, X);
        check_piece( 2, 1, X, A, B, X);
        check_piece( 3, 1, X, E, E, X);
        check_piece( 4, 1, A, K, D, X);
        check_piece( 5, 1, B, U, E, X);
        check_piece( 6, 1, B, P, C, X);
        check_piece( 7, 1, E, V, A, X);
        check_piece( 8, 1, D, F, A, X);
        check_piece( 9, 1, E, R, C, X);
        check_piece(10, 1, D, G, B, X);
        check_piece(11, 1, B, N, A, X);
        check_piece(12, 1, D, U, E, X);
        check_piece(13, 1, C, R, D, X);
        check_piece(14, 1, C, S, B, X);
        check_piece(15, 1, C, H, E, X);
        check_piece(16, 1, S, I, R, P);
        check_piece(17, 1, L, P, T, O);
        check_piece(18, 1, J, Q, N, V);
        check_piece(19, 1, S, H, L, T);
        check_piece(20, 1, O, S, M, V);
        check_piece(21, 1, G, F, I, T);
        check_piece(22, 1, R, U, Q, P);
        check_piece(23, 1, K, Q, M, Q);
        check_piece(24, 1, J, U, T, V);

        $display("\n-- Rotation 2 --");
        check_piece( 0, 2, X, X, A, D);
        check_piece( 1, 2, X, X, E, C);
        check_piece( 2, 2, X, X, A, B);
        check_piece( 3, 2, X, X, E, E);
        check_piece( 4, 2, X, A, K, D);
        check_piece( 5, 2, X, B, U, E);
        check_piece( 6, 2, X, B, P, C);
        check_piece( 7, 2, X, E, V, A);
        check_piece( 8, 2, X, D, F, A);
        check_piece( 9, 2, X, E, R, C);
        check_piece(10, 2, X, D, G, B);
        check_piece(11, 2, X, B, N, A);
        check_piece(12, 2, X, D, U, E);
        check_piece(13, 2, X, C, R, D);
        check_piece(14, 2, X, C, S, B);
        check_piece(15, 2, X, C, H, E);
        check_piece(16, 2, P, S, I, R);
        check_piece(17, 2, O, L, P, T);
        check_piece(18, 2, V, J, Q, N);
        check_piece(19, 2, T, S, H, L);
        check_piece(20, 2, V, O, S, M);
        check_piece(21, 2, T, G, F, I);
        check_piece(22, 2, P, R, U, Q);
        check_piece(23, 2, Q, K, Q, M);
        check_piece(24, 2, V, J, U, T);

        $display("\n-- Rotation 3 --");
        check_piece( 0, 3, D, X, X, A);
        check_piece( 1, 3, C, X, X, E);
        check_piece( 2, 3, B, X, X, A);
        check_piece( 3, 3, E, X, X, E);
        check_piece( 4, 3, D, X, A, K);
        check_piece( 5, 3, E, X, B, U);
        check_piece( 6, 3, C, X, B, P);
        check_piece( 7, 3, A, X, E, V);
        check_piece( 8, 3, A, X, D, F);
        check_piece( 9, 3, C, X, E, R);
        check_piece(10, 3, B, X, D, G);
        check_piece(11, 3, A, X, B, N);
        check_piece(12, 3, E, X, D, U);
        check_piece(13, 3, D, X, C, R);
        check_piece(14, 3, B, X, C, S);
        check_piece(15, 3, E, X, C, H);
        check_piece(16, 3, R, P, S, I);
        check_piece(17, 3, T, O, L, P);
        check_piece(18, 3, N, V, J, Q);
        check_piece(19, 3, L, T, S, H);
        check_piece(20, 3, M, V, O, S);
        check_piece(21, 3, I, T, G, F);
        check_piece(22, 3, Q, P, R, U);
        check_piece(23, 3, M, Q, K, Q);
        check_piece(24, 3, T, V, J, U);

        $display("\n-----------------------------------------");
        $display(" Testbench complete — 100 checks");
        $display("-----------------------------------------");
        $finish;
    end

endmodule