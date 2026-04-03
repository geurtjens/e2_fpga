// ─────────────────────────────────────────────────────────────
// Testbench for LoadPuzzle — Puzzle_Brendan6
// 144 checks: 36 pieces x 4 rotations
// Expected values independently computed from puzzle definition
// ─────────────────────────────────────────────────────────────
module tb_load_puzzle;

    parameter int N         = 6;
    parameter int TC        = 9;
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
    localparam logic [TC-1:0] X = 9'b000000001;
    localparam logic [TC-1:0] A = 9'b000000010;
    localparam logic [TC-1:0] B = 9'b000000100;
    localparam logic [TC-1:0] C = 9'b000001000;
    localparam logic [TC-1:0] D = 9'b000010000;
    localparam logic [TC-1:0] E = 9'b000100000;
    localparam logic [TC-1:0] F = 9'b001000000;
    localparam logic [TC-1:0] G = 9'b010000000;
    localparam logic [TC-1:0] H = 9'b100000000;

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
        $display(" LoadPuzzle Testbench — Brendan6");
        $display("-----------------------------------------");

        $display("\n-- Rotation 0 --");
        check_piece( 0, 0, A, A, X, X);
        check_piece( 1, 0, A, C, X, X);
        check_piece( 2, 0, B, B, X, X);
        check_piece( 3, 0, B, C, X, X);
        check_piece( 4, 0, F, A, X, A);
        check_piece( 5, 0, F, B, X, A);
        check_piece( 6, 0, H, A, X, A);
        check_piece( 7, 0, H, B, X, A);
        check_piece( 8, 0, H, C, X, A);
        check_piece( 9, 0, D, A, X, B);
        check_piece(10, 0, E, A, X, B);
        check_piece(11, 0, F, B, X, B);
        check_piece(12, 0, F, C, X, B);
        check_piece(13, 0, G, C, X, B);
        check_piece(14, 0, D, B, X, C);
        check_piece(15, 0, D, C, X, C);
        check_piece(16, 0, E, A, X, C);
        check_piece(17, 0, F, B, X, C);
        check_piece(18, 0, G, A, X, C);
        check_piece(19, 0, H, B, X, C);
        check_piece(20, 0, D, D, G, E);
        check_piece(21, 0, D, E, E, E);
        check_piece(22, 0, D, E, H, H);
        check_piece(23, 0, D, F, F, G);
        check_piece(24, 0, D, F, G, H);
        check_piece(25, 0, D, G, F, E);
        check_piece(26, 0, D, G, G, E);
        check_piece(27, 0, D, G, G, G);
        check_piece(28, 0, D, H, E, F);
        check_piece(29, 0, D, H, E, G);
        check_piece(30, 0, D, H, G, F);
        check_piece(31, 0, D, H, G, H);
        check_piece(32, 0, E, F, E, G);
        check_piece(33, 0, E, F, F, H);
        check_piece(34, 0, E, F, G, H);
        check_piece(35, 0, E, H, F, H);

        $display("\n-- Rotation 1 --");
        check_piece( 0, 1, X, A, A, X);
        check_piece( 1, 1, X, A, C, X);
        check_piece( 2, 1, X, B, B, X);
        check_piece( 3, 1, X, B, C, X);
        check_piece( 4, 1, A, F, A, X);
        check_piece( 5, 1, A, F, B, X);
        check_piece( 6, 1, A, H, A, X);
        check_piece( 7, 1, A, H, B, X);
        check_piece( 8, 1, A, H, C, X);
        check_piece( 9, 1, B, D, A, X);
        check_piece(10, 1, B, E, A, X);
        check_piece(11, 1, B, F, B, X);
        check_piece(12, 1, B, F, C, X);
        check_piece(13, 1, B, G, C, X);
        check_piece(14, 1, C, D, B, X);
        check_piece(15, 1, C, D, C, X);
        check_piece(16, 1, C, E, A, X);
        check_piece(17, 1, C, F, B, X);
        check_piece(18, 1, C, G, A, X);
        check_piece(19, 1, C, H, B, X);
        check_piece(20, 1, E, D, D, G);
        check_piece(21, 1, E, D, E, E);
        check_piece(22, 1, H, D, E, H);
        check_piece(23, 1, G, D, F, F);
        check_piece(24, 1, H, D, F, G);
        check_piece(25, 1, E, D, G, F);
        check_piece(26, 1, E, D, G, G);
        check_piece(27, 1, G, D, G, G);
        check_piece(28, 1, F, D, H, E);
        check_piece(29, 1, G, D, H, E);
        check_piece(30, 1, F, D, H, G);
        check_piece(31, 1, H, D, H, G);
        check_piece(32, 1, G, E, F, E);
        check_piece(33, 1, H, E, F, F);
        check_piece(34, 1, H, E, F, G);
        check_piece(35, 1, H, E, H, F);

        $display("\n-- Rotation 2 --");
        check_piece( 0, 2, X, X, A, A);
        check_piece( 1, 2, X, X, A, C);
        check_piece( 2, 2, X, X, B, B);
        check_piece( 3, 2, X, X, B, C);
        check_piece( 4, 2, X, A, F, A);
        check_piece( 5, 2, X, A, F, B);
        check_piece( 6, 2, X, A, H, A);
        check_piece( 7, 2, X, A, H, B);
        check_piece( 8, 2, X, A, H, C);
        check_piece( 9, 2, X, B, D, A);
        check_piece(10, 2, X, B, E, A);
        check_piece(11, 2, X, B, F, B);
        check_piece(12, 2, X, B, F, C);
        check_piece(13, 2, X, B, G, C);
        check_piece(14, 2, X, C, D, B);
        check_piece(15, 2, X, C, D, C);
        check_piece(16, 2, X, C, E, A);
        check_piece(17, 2, X, C, F, B);
        check_piece(18, 2, X, C, G, A);
        check_piece(19, 2, X, C, H, B);
        check_piece(20, 2, G, E, D, D);
        check_piece(21, 2, E, E, D, E);
        check_piece(22, 2, H, H, D, E);
        check_piece(23, 2, F, G, D, F);
        check_piece(24, 2, G, H, D, F);
        check_piece(25, 2, F, E, D, G);
        check_piece(26, 2, G, E, D, G);
        check_piece(27, 2, G, G, D, G);
        check_piece(28, 2, E, F, D, H);
        check_piece(29, 2, E, G, D, H);
        check_piece(30, 2, G, F, D, H);
        check_piece(31, 2, G, H, D, H);
        check_piece(32, 2, E, G, E, F);
        check_piece(33, 2, F, H, E, F);
        check_piece(34, 2, G, H, E, F);
        check_piece(35, 2, F, H, E, H);

        $display("\n-- Rotation 3 --");
        check_piece( 0, 3, A, X, X, A);
        check_piece( 1, 3, C, X, X, A);
        check_piece( 2, 3, B, X, X, B);
        check_piece( 3, 3, C, X, X, B);
        check_piece( 4, 3, A, X, A, F);
        check_piece( 5, 3, B, X, A, F);
        check_piece( 6, 3, A, X, A, H);
        check_piece( 7, 3, B, X, A, H);
        check_piece( 8, 3, C, X, A, H);
        check_piece( 9, 3, A, X, B, D);
        check_piece(10, 3, A, X, B, E);
        check_piece(11, 3, B, X, B, F);
        check_piece(12, 3, C, X, B, F);
        check_piece(13, 3, C, X, B, G);
        check_piece(14, 3, B, X, C, D);
        check_piece(15, 3, C, X, C, D);
        check_piece(16, 3, A, X, C, E);
        check_piece(17, 3, B, X, C, F);
        check_piece(18, 3, A, X, C, G);
        check_piece(19, 3, B, X, C, H);
        check_piece(20, 3, D, G, E, D);
        check_piece(21, 3, E, E, E, D);
        check_piece(22, 3, E, H, H, D);
        check_piece(23, 3, F, F, G, D);
        check_piece(24, 3, F, G, H, D);
        check_piece(25, 3, G, F, E, D);
        check_piece(26, 3, G, G, E, D);
        check_piece(27, 3, G, G, G, D);
        check_piece(28, 3, H, E, F, D);
        check_piece(29, 3, H, E, G, D);
        check_piece(30, 3, H, G, F, D);
        check_piece(31, 3, H, G, H, D);
        check_piece(32, 3, F, E, G, E);
        check_piece(33, 3, F, F, H, E);
        check_piece(34, 3, F, G, H, E);
        check_piece(35, 3, H, F, H, E);

        $display("\n-----------------------------------------");
        $display(" Testbench complete — 144 checks");
        $display("-----------------------------------------");
        $finish;
    end

endmodule