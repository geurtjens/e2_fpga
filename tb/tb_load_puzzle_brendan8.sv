// ─────────────────────────────────────────────────────────────
// Testbench for LoadPuzzle — Puzzle_Brendan8
// 256 checks: 64 pieces x 4 rotations
// Expected values independently computed from puzzle definition
// ─────────────────────────────────────────────────────────────
module tb_load_puzzle;

    parameter int N         = 8;
    parameter int TC        = 12;
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
    localparam logic [TC-1:0] X = 12'b000000000001;
    localparam logic [TC-1:0] A = 12'b000000000010;
    localparam logic [TC-1:0] B = 12'b000000000100;
    localparam logic [TC-1:0] C = 12'b000000001000;
    localparam logic [TC-1:0] D = 12'b000000010000;
    localparam logic [TC-1:0] E = 12'b000000100000;
    localparam logic [TC-1:0] F = 12'b000001000000;
    localparam logic [TC-1:0] G = 12'b000010000000;
    localparam logic [TC-1:0] H = 12'b000100000000;
    localparam logic [TC-1:0] I = 12'b001000000000;
    localparam logic [TC-1:0] J = 12'b010000000000;
    localparam logic [TC-1:0] K = 12'b100000000000;

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
        $display(" LoadPuzzle Testbench — Brendan8");
        $display("-----------------------------------------");

        $display("\n-- Rotation 0 --");
        check_piece( 0, 0, A, B, X, X);
        check_piece( 1, 0, B, A, X, X);
        check_piece( 2, 0, B, B, X, X);
        check_piece( 3, 0, B, C, X, X);
        check_piece( 4, 0, D, A, X, A);
        check_piece( 5, 0, E, C, X, A);
        check_piece( 6, 0, F, C, X, A);
        check_piece( 7, 0, H, A, X, A);
        check_piece( 8, 0, H, C, X, A);
        check_piece( 9, 0, J, A, X, A);
        check_piece(10, 0, J, B, X, A);
        check_piece(11, 0, K, A, X, A);
        check_piece(12, 0, K, B, X, A);
        check_piece(13, 0, D, A, X, B);
        check_piece(14, 0, D, B, X, B);
        check_piece(15, 0, D, C, X, B);
        check_piece(16, 0, I, A, X, B);
        check_piece(17, 0, I, B, X, B);
        check_piece(18, 0, J, C, X, B);
        check_piece(19, 0, D, B, X, C);
        check_piece(20, 0, D, C, X, C);
        check_piece(21, 0, E, A, X, C);
        check_piece(22, 0, E, B, X, C);
        check_piece(23, 0, I, A, X, C);
        check_piece(24, 0, I, C, X, C);
        check_piece(25, 0, J, B, X, C);
        check_piece(26, 0, K, A, X, C);
        check_piece(27, 0, K, C, X, C);
        check_piece(28, 0, D, E, D, G);
        check_piece(29, 0, D, E, J, F);
        check_piece(30, 0, D, F, E, I);
        check_piece(31, 0, D, F, G, E);
        check_piece(32, 0, D, F, J, I);
        check_piece(33, 0, D, G, D, I);
        check_piece(34, 0, D, G, E, F);
        check_piece(35, 0, D, H, G, K);
        check_piece(36, 0, D, H, J, J);
        check_piece(37, 0, D, I, F, E);
        check_piece(38, 0, D, I, F, H);
        check_piece(39, 0, D, J, K, H);
        check_piece(40, 0, D, K, G, J);
        check_piece(41, 0, D, K, H, F);
        check_piece(42, 0, E, E, E, H);
        check_piece(43, 0, E, E, K, J);
        check_piece(44, 0, E, F, J, J);
        check_piece(45, 0, E, G, E, J);
        check_piece(46, 0, E, G, F, I);
        check_piece(47, 0, E, H, F, F);
        check_piece(48, 0, E, I, F, F);
        check_piece(49, 0, E, I, H, K);
        check_piece(50, 0, E, K, H, G);
        check_piece(51, 0, F, F, H, K);
        check_piece(52, 0, F, G, H, G);
        check_piece(53, 0, F, G, K, G);
        check_piece(54, 0, F, H, G, I);
        check_piece(55, 0, F, I, J, G);
        check_piece(56, 0, F, J, G, H);
        check_piece(57, 0, G, H, I, K);
        check_piece(58, 0, G, I, J, K);
        check_piece(59, 0, G, J, J, H);
        check_piece(60, 0, G, J, K, K);
        check_piece(61, 0, G, K, I, H);
        check_piece(62, 0, G, K, I, I);
        check_piece(63, 0, H, H, I, K);

        $display("\n-- Rotation 1 --");
        check_piece( 0, 1, X, A, B, X);
        check_piece( 1, 1, X, B, A, X);
        check_piece( 2, 1, X, B, B, X);
        check_piece( 3, 1, X, B, C, X);
        check_piece( 4, 1, A, D, A, X);
        check_piece( 5, 1, A, E, C, X);
        check_piece( 6, 1, A, F, C, X);
        check_piece( 7, 1, A, H, A, X);
        check_piece( 8, 1, A, H, C, X);
        check_piece( 9, 1, A, J, A, X);
        check_piece(10, 1, A, J, B, X);
        check_piece(11, 1, A, K, A, X);
        check_piece(12, 1, A, K, B, X);
        check_piece(13, 1, B, D, A, X);
        check_piece(14, 1, B, D, B, X);
        check_piece(15, 1, B, D, C, X);
        check_piece(16, 1, B, I, A, X);
        check_piece(17, 1, B, I, B, X);
        check_piece(18, 1, B, J, C, X);
        check_piece(19, 1, C, D, B, X);
        check_piece(20, 1, C, D, C, X);
        check_piece(21, 1, C, E, A, X);
        check_piece(22, 1, C, E, B, X);
        check_piece(23, 1, C, I, A, X);
        check_piece(24, 1, C, I, C, X);
        check_piece(25, 1, C, J, B, X);
        check_piece(26, 1, C, K, A, X);
        check_piece(27, 1, C, K, C, X);
        check_piece(28, 1, G, D, E, D);
        check_piece(29, 1, F, D, E, J);
        check_piece(30, 1, I, D, F, E);
        check_piece(31, 1, E, D, F, G);
        check_piece(32, 1, I, D, F, J);
        check_piece(33, 1, I, D, G, D);
        check_piece(34, 1, F, D, G, E);
        check_piece(35, 1, K, D, H, G);
        check_piece(36, 1, J, D, H, J);
        check_piece(37, 1, E, D, I, F);
        check_piece(38, 1, H, D, I, F);
        check_piece(39, 1, H, D, J, K);
        check_piece(40, 1, J, D, K, G);
        check_piece(41, 1, F, D, K, H);
        check_piece(42, 1, H, E, E, E);
        check_piece(43, 1, J, E, E, K);
        check_piece(44, 1, J, E, F, J);
        check_piece(45, 1, J, E, G, E);
        check_piece(46, 1, I, E, G, F);
        check_piece(47, 1, F, E, H, F);
        check_piece(48, 1, F, E, I, F);
        check_piece(49, 1, K, E, I, H);
        check_piece(50, 1, G, E, K, H);
        check_piece(51, 1, K, F, F, H);
        check_piece(52, 1, G, F, G, H);
        check_piece(53, 1, G, F, G, K);
        check_piece(54, 1, I, F, H, G);
        check_piece(55, 1, G, F, I, J);
        check_piece(56, 1, H, F, J, G);
        check_piece(57, 1, K, G, H, I);
        check_piece(58, 1, K, G, I, J);
        check_piece(59, 1, H, G, J, J);
        check_piece(60, 1, K, G, J, K);
        check_piece(61, 1, H, G, K, I);
        check_piece(62, 1, I, G, K, I);
        check_piece(63, 1, K, H, H, I);

        $display("\n-- Rotation 2 --");
        check_piece( 0, 2, X, X, A, B);
        check_piece( 1, 2, X, X, B, A);
        check_piece( 2, 2, X, X, B, B);
        check_piece( 3, 2, X, X, B, C);
        check_piece( 4, 2, X, A, D, A);
        check_piece( 5, 2, X, A, E, C);
        check_piece( 6, 2, X, A, F, C);
        check_piece( 7, 2, X, A, H, A);
        check_piece( 8, 2, X, A, H, C);
        check_piece( 9, 2, X, A, J, A);
        check_piece(10, 2, X, A, J, B);
        check_piece(11, 2, X, A, K, A);
        check_piece(12, 2, X, A, K, B);
        check_piece(13, 2, X, B, D, A);
        check_piece(14, 2, X, B, D, B);
        check_piece(15, 2, X, B, D, C);
        check_piece(16, 2, X, B, I, A);
        check_piece(17, 2, X, B, I, B);
        check_piece(18, 2, X, B, J, C);
        check_piece(19, 2, X, C, D, B);
        check_piece(20, 2, X, C, D, C);
        check_piece(21, 2, X, C, E, A);
        check_piece(22, 2, X, C, E, B);
        check_piece(23, 2, X, C, I, A);
        check_piece(24, 2, X, C, I, C);
        check_piece(25, 2, X, C, J, B);
        check_piece(26, 2, X, C, K, A);
        check_piece(27, 2, X, C, K, C);
        check_piece(28, 2, D, G, D, E);
        check_piece(29, 2, J, F, D, E);
        check_piece(30, 2, E, I, D, F);
        check_piece(31, 2, G, E, D, F);
        check_piece(32, 2, J, I, D, F);
        check_piece(33, 2, D, I, D, G);
        check_piece(34, 2, E, F, D, G);
        check_piece(35, 2, G, K, D, H);
        check_piece(36, 2, J, J, D, H);
        check_piece(37, 2, F, E, D, I);
        check_piece(38, 2, F, H, D, I);
        check_piece(39, 2, K, H, D, J);
        check_piece(40, 2, G, J, D, K);
        check_piece(41, 2, H, F, D, K);
        check_piece(42, 2, E, H, E, E);
        check_piece(43, 2, K, J, E, E);
        check_piece(44, 2, J, J, E, F);
        check_piece(45, 2, E, J, E, G);
        check_piece(46, 2, F, I, E, G);
        check_piece(47, 2, F, F, E, H);
        check_piece(48, 2, F, F, E, I);
        check_piece(49, 2, H, K, E, I);
        check_piece(50, 2, H, G, E, K);
        check_piece(51, 2, H, K, F, F);
        check_piece(52, 2, H, G, F, G);
        check_piece(53, 2, K, G, F, G);
        check_piece(54, 2, G, I, F, H);
        check_piece(55, 2, J, G, F, I);
        check_piece(56, 2, G, H, F, J);
        check_piece(57, 2, I, K, G, H);
        check_piece(58, 2, J, K, G, I);
        check_piece(59, 2, J, H, G, J);
        check_piece(60, 2, K, K, G, J);
        check_piece(61, 2, I, H, G, K);
        check_piece(62, 2, I, I, G, K);
        check_piece(63, 2, I, K, H, H);

        $display("\n-- Rotation 3 --");
        check_piece( 0, 3, B, X, X, A);
        check_piece( 1, 3, A, X, X, B);
        check_piece( 2, 3, B, X, X, B);
        check_piece( 3, 3, C, X, X, B);
        check_piece( 4, 3, A, X, A, D);
        check_piece( 5, 3, C, X, A, E);
        check_piece( 6, 3, C, X, A, F);
        check_piece( 7, 3, A, X, A, H);
        check_piece( 8, 3, C, X, A, H);
        check_piece( 9, 3, A, X, A, J);
        check_piece(10, 3, B, X, A, J);
        check_piece(11, 3, A, X, A, K);
        check_piece(12, 3, B, X, A, K);
        check_piece(13, 3, A, X, B, D);
        check_piece(14, 3, B, X, B, D);
        check_piece(15, 3, C, X, B, D);
        check_piece(16, 3, A, X, B, I);
        check_piece(17, 3, B, X, B, I);
        check_piece(18, 3, C, X, B, J);
        check_piece(19, 3, B, X, C, D);
        check_piece(20, 3, C, X, C, D);
        check_piece(21, 3, A, X, C, E);
        check_piece(22, 3, B, X, C, E);
        check_piece(23, 3, A, X, C, I);
        check_piece(24, 3, C, X, C, I);
        check_piece(25, 3, B, X, C, J);
        check_piece(26, 3, A, X, C, K);
        check_piece(27, 3, C, X, C, K);
        check_piece(28, 3, E, D, G, D);
        check_piece(29, 3, E, J, F, D);
        check_piece(30, 3, F, E, I, D);
        check_piece(31, 3, F, G, E, D);
        check_piece(32, 3, F, J, I, D);
        check_piece(33, 3, G, D, I, D);
        check_piece(34, 3, G, E, F, D);
        check_piece(35, 3, H, G, K, D);
        check_piece(36, 3, H, J, J, D);
        check_piece(37, 3, I, F, E, D);
        check_piece(38, 3, I, F, H, D);
        check_piece(39, 3, J, K, H, D);
        check_piece(40, 3, K, G, J, D);
        check_piece(41, 3, K, H, F, D);
        check_piece(42, 3, E, E, H, E);
        check_piece(43, 3, E, K, J, E);
        check_piece(44, 3, F, J, J, E);
        check_piece(45, 3, G, E, J, E);
        check_piece(46, 3, G, F, I, E);
        check_piece(47, 3, H, F, F, E);
        check_piece(48, 3, I, F, F, E);
        check_piece(49, 3, I, H, K, E);
        check_piece(50, 3, K, H, G, E);
        check_piece(51, 3, F, H, K, F);
        check_piece(52, 3, G, H, G, F);
        check_piece(53, 3, G, K, G, F);
        check_piece(54, 3, H, G, I, F);
        check_piece(55, 3, I, J, G, F);
        check_piece(56, 3, J, G, H, F);
        check_piece(57, 3, H, I, K, G);
        check_piece(58, 3, I, J, K, G);
        check_piece(59, 3, J, J, H, G);
        check_piece(60, 3, J, K, K, G);
        check_piece(61, 3, K, I, H, G);
        check_piece(62, 3, K, I, I, G);
        check_piece(63, 3, H, I, K, H);

        $display("\n-----------------------------------------");
        $display(" Testbench complete — 256 checks");
        $display("-----------------------------------------");
        $finish;
    end

endmodule