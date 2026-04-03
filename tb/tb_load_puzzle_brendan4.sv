// ─────────────────────────────────────────────────────────────
// Testbench for LoadPuzzle (Puzzle_Brendan4)
// Checks every piece at every rotation against known values
// ─────────────────────────────────────────────────────────────
module tb_load_puzzle;

    parameter int N         = 4;
    parameter int TC        = 6;
    parameter int VARIABLES = N * N;

    // ── DUT outputs ────────────────────────────────────────────
    logic [VARIABLES-1:0][TC-1:0] p0_top, p0_right, p0_bottom, p0_left;
    logic [VARIABLES-1:0][TC-1:0] p1_top, p1_right, p1_bottom, p1_left;
    logic [VARIABLES-1:0][TC-1:0] p2_top, p2_right, p2_bottom, p2_left;
    logic [VARIABLES-1:0][TC-1:0] p3_top, p3_right, p3_bottom, p3_left;

    // ── DUT ────────────────────────────────────────────────────
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

    // ── Waveform dump ──────────────────────────────────────────
    initial begin
        $dumpfile("tb_load_puzzle.vcd");
        $dumpvars(0, tb_load_puzzle);
    end

    // ── Colour constants ───────────────────────────────────────
    localparam logic [TC-1:0] X = 6'b000001;
    localparam logic [TC-1:0] A = 6'b000010;
    localparam logic [TC-1:0] B = 6'b000100;
    localparam logic [TC-1:0] C = 6'b001000;
    localparam logic [TC-1:0] D = 6'b010000;
    localparam logic [TC-1:0] E = 6'b100000;

    // ── Task: check one piece at one rotation ──────────────────
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

    // ── Stimulus ───────────────────────────────────────────────
    initial begin
        #10;
        $display("-----------------------------------------");
        $display(" LoadPuzzle Testbench — Brendan4");
        $display("-----------------------------------------");

        $display("\n-- Rotation 0 --");
        check_piece( 0, 0, A, A, X, X);
        check_piece( 1, 0, A, B, X, X);
        check_piece( 2, 0, B, A, X, X);
        check_piece( 3, 0, B, B, X, X);
        check_piece( 4, 0, C, A, X, A);
        check_piece( 5, 0, C, B, X, A);
        check_piece( 6, 0, D, A, X, A);
        check_piece( 7, 0, E, B, X, A);
        check_piece( 8, 0, D, A, X, B);
        check_piece( 9, 0, D, B, X, B);
        check_piece(10, 0, E, A, X, B);
        check_piece(11, 0, E, B, X, B);
        check_piece(12, 0, C, C, E, E);
        check_piece(13, 0, C, D, C, E);
        check_piece(14, 0, C, D, D, D);
        check_piece(15, 0, C, E, E, D);

        $display("\n-- Rotation 1 --");
        check_piece( 0, 1, X, A, A, X);
        check_piece( 1, 1, X, A, B, X);
        check_piece( 2, 1, X, B, A, X);
        check_piece( 3, 1, X, B, B, X);
        check_piece( 4, 1, A, C, A, X);
        check_piece( 5, 1, A, C, B, X);
        check_piece( 6, 1, A, D, A, X);
        check_piece( 7, 1, A, E, B, X);
        check_piece( 8, 1, B, D, A, X);
        check_piece( 9, 1, B, D, B, X);
        check_piece(10, 1, B, E, A, X);
        check_piece(11, 1, B, E, B, X);
        check_piece(12, 1, E, C, C, E);
        check_piece(13, 1, E, C, D, C);
        check_piece(14, 1, D, C, D, D);
        check_piece(15, 1, D, C, E, E);

        $display("\n-- Rotation 2 --");
        check_piece( 0, 2, X, X, A, A);
        check_piece( 1, 2, X, X, A, B);
        check_piece( 2, 2, X, X, B, A);
        check_piece( 3, 2, X, X, B, B);
        check_piece( 4, 2, X, A, C, A);
        check_piece( 5, 2, X, A, C, B);
        check_piece( 6, 2, X, A, D, A);
        check_piece( 7, 2, X, A, E, B);
        check_piece( 8, 2, X, B, D, A);
        check_piece( 9, 2, X, B, D, B);
        check_piece(10, 2, X, B, E, A);
        check_piece(11, 2, X, B, E, B);
        check_piece(12, 2, E, E, C, C);
        check_piece(13, 2, C, E, C, D);
        check_piece(14, 2, D, D, C, D);
        check_piece(15, 2, E, D, C, E);

        $display("\n-- Rotation 3 --");
        check_piece( 0, 3, A, X, X, A);
        check_piece( 1, 3, B, X, X, A);
        check_piece( 2, 3, A, X, X, B);
        check_piece( 3, 3, B, X, X, B);
        check_piece( 4, 3, A, X, A, C);
        check_piece( 5, 3, B, X, A, C);
        check_piece( 6, 3, A, X, A, D);
        check_piece( 7, 3, B, X, A, E);
        check_piece( 8, 3, A, X, B, D);
        check_piece( 9, 3, B, X, B, D);
        check_piece(10, 3, A, X, B, E);
        check_piece(11, 3, B, X, B, E);
        check_piece(12, 3, C, E, E, C);
        check_piece(13, 3, D, C, E, C);
        check_piece(14, 3, D, D, D, C);
        check_piece(15, 3, E, E, D, C);

        $display("\n-----------------------------------------");
        $display(" Testbench complete");
        $display("-----------------------------------------");
        $finish;
    end

endmodule
