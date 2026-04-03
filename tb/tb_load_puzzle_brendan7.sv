// ─────────────────────────────────────────────────────────────
// Testbench for LoadPuzzle — Puzzle_Brendan7
// 196 checks: 49 pieces x 4 rotations
// Expected values independently computed from puzzle definition
// ─────────────────────────────────────────────────────────────
module tb_load_puzzle;

    parameter int N         = 7;
    parameter int TC        = 10;
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
    localparam logic [TC-1:0] X = 10'b0000000001;
    localparam logic [TC-1:0] A = 10'b0000000010;
    localparam logic [TC-1:0] B = 10'b0000000100;
    localparam logic [TC-1:0] C = 10'b0000001000;
    localparam logic [TC-1:0] D = 10'b0000010000;
    localparam logic [TC-1:0] E = 10'b0000100000;
    localparam logic [TC-1:0] F = 10'b0001000000;
    localparam logic [TC-1:0] G = 10'b0010000000;
    localparam logic [TC-1:0] H = 10'b0100000000;
    localparam logic [TC-1:0] I = 10'b1000000000;

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
        $display(" LoadPuzzle Testbench — Brendan7");
        $display("-----------------------------------------");

        $display("\n-- Rotation 0 --");
        check_piece( 0, 0, A, B, X, X);
        check_piece( 1, 0, A, C, X, X);
        check_piece( 2, 0, B, A, X, X);
        check_piece( 3, 0, C, B, X, X);
        check_piece( 4, 0, E, A, X, A);
        check_piece( 5, 0, F, A, X, A);
        check_piece( 6, 0, F, C, X, A);
        check_piece( 7, 0, G, B, X, A);
        check_piece( 8, 0, H, B, X, A);
        check_piece( 9, 0, H, C, X, A);
        check_piece(10, 0, D, B, X, B);
        check_piece(11, 0, E, C, X, B);
        check_piece(12, 0, G, B, X, B);
        check_piece(13, 0, H, B, X, B);
        check_piece(14, 0, H, C, X, B);
        check_piece(15, 0, I, A, X, B);
        check_piece(16, 0, I, C, X, B);
        check_piece(17, 0, D, A, X, C);
        check_piece(18, 0, D, B, X, C);
        check_piece(19, 0, E, A, X, C);
        check_piece(20, 0, F, A, X, C);
        check_piece(21, 0, F, C, X, C);
        check_piece(22, 0, H, C, X, C);
        check_piece(23, 0, I, A, X, C);
        check_piece(24, 0, D, D, E, H);
        check_piece(25, 0, D, D, G, E);
        check_piece(26, 0, D, D, G, G);
        check_piece(27, 0, D, E, E, G);
        check_piece(28, 0, D, E, H, E);
        check_piece(29, 0, D, F, E, G);
        check_piece(30, 0, D, F, G, F);
        check_piece(31, 0, D, H, F, I);
        check_piece(32, 0, D, H, G, G);
        check_piece(33, 0, D, H, I, E);
        check_piece(34, 0, D, H, I, F);
        check_piece(35, 0, D, I, F, H);
        check_piece(36, 0, D, I, H, E);
        check_piece(37, 0, D, I, I, F);
        check_piece(38, 0, E, E, H, G);
        check_piece(39, 0, E, E, I, G);
        check_piece(40, 0, E, F, G, G);
        check_piece(41, 0, E, F, H, F);
        check_piece(42, 0, E, F, I, I);
        check_piece(43, 0, E, I, G, I);
        check_piece(44, 0, F, G, I, H);
        check_piece(45, 0, F, H, G, G);
        check_piece(46, 0, F, H, H, G);
        check_piece(47, 0, F, I, H, I);
        check_piece(48, 0, F, I, I, G);

        $display("\n-- Rotation 1 --");
        check_piece( 0, 1, X, A, B, X);
        check_piece( 1, 1, X, A, C, X);
        check_piece( 2, 1, X, B, A, X);
        check_piece( 3, 1, X, C, B, X);
        check_piece( 4, 1, A, E, A, X);
        check_piece( 5, 1, A, F, A, X);
        check_piece( 6, 1, A, F, C, X);
        check_piece( 7, 1, A, G, B, X);
        check_piece( 8, 1, A, H, B, X);
        check_piece( 9, 1, A, H, C, X);
        check_piece(10, 1, B, D, B, X);
        check_piece(11, 1, B, E, C, X);
        check_piece(12, 1, B, G, B, X);
        check_piece(13, 1, B, H, B, X);
        check_piece(14, 1, B, H, C, X);
        check_piece(15, 1, B, I, A, X);
        check_piece(16, 1, B, I, C, X);
        check_piece(17, 1, C, D, A, X);
        check_piece(18, 1, C, D, B, X);
        check_piece(19, 1, C, E, A, X);
        check_piece(20, 1, C, F, A, X);
        check_piece(21, 1, C, F, C, X);
        check_piece(22, 1, C, H, C, X);
        check_piece(23, 1, C, I, A, X);
        check_piece(24, 1, H, D, D, E);
        check_piece(25, 1, E, D, D, G);
        check_piece(26, 1, G, D, D, G);
        check_piece(27, 1, G, D, E, E);
        check_piece(28, 1, E, D, E, H);
        check_piece(29, 1, G, D, F, E);
        check_piece(30, 1, F, D, F, G);
        check_piece(31, 1, I, D, H, F);
        check_piece(32, 1, G, D, H, G);
        check_piece(33, 1, E, D, H, I);
        check_piece(34, 1, F, D, H, I);
        check_piece(35, 1, H, D, I, F);
        check_piece(36, 1, E, D, I, H);
        check_piece(37, 1, F, D, I, I);
        check_piece(38, 1, G, E, E, H);
        check_piece(39, 1, G, E, E, I);
        check_piece(40, 1, G, E, F, G);
        check_piece(41, 1, F, E, F, H);
        check_piece(42, 1, I, E, F, I);
        check_piece(43, 1, I, E, I, G);
        check_piece(44, 1, H, F, G, I);
        check_piece(45, 1, G, F, H, G);
        check_piece(46, 1, G, F, H, H);
        check_piece(47, 1, I, F, I, H);
        check_piece(48, 1, G, F, I, I);

        $display("\n-- Rotation 2 --");
        check_piece( 0, 2, X, X, A, B);
        check_piece( 1, 2, X, X, A, C);
        check_piece( 2, 2, X, X, B, A);
        check_piece( 3, 2, X, X, C, B);
        check_piece( 4, 2, X, A, E, A);
        check_piece( 5, 2, X, A, F, A);
        check_piece( 6, 2, X, A, F, C);
        check_piece( 7, 2, X, A, G, B);
        check_piece( 8, 2, X, A, H, B);
        check_piece( 9, 2, X, A, H, C);
        check_piece(10, 2, X, B, D, B);
        check_piece(11, 2, X, B, E, C);
        check_piece(12, 2, X, B, G, B);
        check_piece(13, 2, X, B, H, B);
        check_piece(14, 2, X, B, H, C);
        check_piece(15, 2, X, B, I, A);
        check_piece(16, 2, X, B, I, C);
        check_piece(17, 2, X, C, D, A);
        check_piece(18, 2, X, C, D, B);
        check_piece(19, 2, X, C, E, A);
        check_piece(20, 2, X, C, F, A);
        check_piece(21, 2, X, C, F, C);
        check_piece(22, 2, X, C, H, C);
        check_piece(23, 2, X, C, I, A);
        check_piece(24, 2, E, H, D, D);
        check_piece(25, 2, G, E, D, D);
        check_piece(26, 2, G, G, D, D);
        check_piece(27, 2, E, G, D, E);
        check_piece(28, 2, H, E, D, E);
        check_piece(29, 2, E, G, D, F);
        check_piece(30, 2, G, F, D, F);
        check_piece(31, 2, F, I, D, H);
        check_piece(32, 2, G, G, D, H);
        check_piece(33, 2, I, E, D, H);
        check_piece(34, 2, I, F, D, H);
        check_piece(35, 2, F, H, D, I);
        check_piece(36, 2, H, E, D, I);
        check_piece(37, 2, I, F, D, I);
        check_piece(38, 2, H, G, E, E);
        check_piece(39, 2, I, G, E, E);
        check_piece(40, 2, G, G, E, F);
        check_piece(41, 2, H, F, E, F);
        check_piece(42, 2, I, I, E, F);
        check_piece(43, 2, G, I, E, I);
        check_piece(44, 2, I, H, F, G);
        check_piece(45, 2, G, G, F, H);
        check_piece(46, 2, H, G, F, H);
        check_piece(47, 2, H, I, F, I);
        check_piece(48, 2, I, G, F, I);

        $display("\n-- Rotation 3 --");
        check_piece( 0, 3, B, X, X, A);
        check_piece( 1, 3, C, X, X, A);
        check_piece( 2, 3, A, X, X, B);
        check_piece( 3, 3, B, X, X, C);
        check_piece( 4, 3, A, X, A, E);
        check_piece( 5, 3, A, X, A, F);
        check_piece( 6, 3, C, X, A, F);
        check_piece( 7, 3, B, X, A, G);
        check_piece( 8, 3, B, X, A, H);
        check_piece( 9, 3, C, X, A, H);
        check_piece(10, 3, B, X, B, D);
        check_piece(11, 3, C, X, B, E);
        check_piece(12, 3, B, X, B, G);
        check_piece(13, 3, B, X, B, H);
        check_piece(14, 3, C, X, B, H);
        check_piece(15, 3, A, X, B, I);
        check_piece(16, 3, C, X, B, I);
        check_piece(17, 3, A, X, C, D);
        check_piece(18, 3, B, X, C, D);
        check_piece(19, 3, A, X, C, E);
        check_piece(20, 3, A, X, C, F);
        check_piece(21, 3, C, X, C, F);
        check_piece(22, 3, C, X, C, H);
        check_piece(23, 3, A, X, C, I);
        check_piece(24, 3, D, E, H, D);
        check_piece(25, 3, D, G, E, D);
        check_piece(26, 3, D, G, G, D);
        check_piece(27, 3, E, E, G, D);
        check_piece(28, 3, E, H, E, D);
        check_piece(29, 3, F, E, G, D);
        check_piece(30, 3, F, G, F, D);
        check_piece(31, 3, H, F, I, D);
        check_piece(32, 3, H, G, G, D);
        check_piece(33, 3, H, I, E, D);
        check_piece(34, 3, H, I, F, D);
        check_piece(35, 3, I, F, H, D);
        check_piece(36, 3, I, H, E, D);
        check_piece(37, 3, I, I, F, D);
        check_piece(38, 3, E, H, G, E);
        check_piece(39, 3, E, I, G, E);
        check_piece(40, 3, F, G, G, E);
        check_piece(41, 3, F, H, F, E);
        check_piece(42, 3, F, I, I, E);
        check_piece(43, 3, I, G, I, E);
        check_piece(44, 3, G, I, H, F);
        check_piece(45, 3, H, G, G, F);
        check_piece(46, 3, H, H, G, F);
        check_piece(47, 3, I, H, I, F);
        check_piece(48, 3, I, I, G, F);

        $display("\n-----------------------------------------");
        $display(" Testbench complete — 196 checks");
        $display("-----------------------------------------");
        $finish;
    end

endmodule