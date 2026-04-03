// ─────────────────────────────────────────────────────────────
// LoadPuzzle — Puzzle_Brendan4
//
// ROM module — all values are constants baked in at elaboration.
// No inputs. Outputs the four rotation patterns for every piece.
//
// Puzzle parameters:
//   Name          : Brendan4
//   N             : 4  (4x4 board, 16 pieces)
//   borderColours : 2
//   innerColours  : 3
//   TC            : 1 + 2 + 3 = 6 bits per colour edge
//   VARIABLES     : 16
//
// Colour encoding (6 bits):
//   x = boundary = 6'b000001  (bit 0)
//   a            = 6'b000010  (bit 1)
//   b            = 6'b000100  (bit 2)
//   c            = 6'b001000  (bit 3)
//   d            = 6'b010000  (bit 4)
//   e            = 6'b100000  (bit 5)
//
// Rotation rule (clockwise) — given r0 = (top right bottom left):
//   r0: t  r  b  l
//   r1: l  t  r  b   (left  becomes top)
//   r2: b  l  t  r   (bottom becomes top)
//   r3: r  b  l  t   (right  becomes top)
//
// Piece patterns at rotation 0 (top right bottom left):
//   0:aaxx  1:abxx  2:baxx  3:bbxx
//   4:caxa  5:cbxa  6:daxa  7:ebxa
//   8:daxb  9:dbxb 10:eaxb 11:ebxb
//  12:ccee 13:cdce 14:cddd 15:ceed
//
// Array index ordering: index 15 is MSB, index 0 is LSB
// i.e. assign p0_top = '{piece15, piece14, ... piece1, piece0}
// ─────────────────────────────────────────────────────────────
module Brendan4 #(
    parameter int N         = 4,
    parameter int TC        = 6,
    parameter int VARIABLES = N * N
)(
    // rotation 0
    output logic [VARIABLES-1:0][TC-1:0] p0_top,
    output logic [VARIABLES-1:0][TC-1:0] p0_right,
    output logic [VARIABLES-1:0][TC-1:0] p0_bottom,
    output logic [VARIABLES-1:0][TC-1:0] p0_left,

    // rotation 1
    output logic [VARIABLES-1:0][TC-1:0] p1_top,
    output logic [VARIABLES-1:0][TC-1:0] p1_right,
    output logic [VARIABLES-1:0][TC-1:0] p1_bottom,
    output logic [VARIABLES-1:0][TC-1:0] p1_left,

    // rotation 2
    output logic [VARIABLES-1:0][TC-1:0] p2_top,
    output logic [VARIABLES-1:0][TC-1:0] p2_right,
    output logic [VARIABLES-1:0][TC-1:0] p2_bottom,
    output logic [VARIABLES-1:0][TC-1:0] p2_left,

    // rotation 3
    output logic [VARIABLES-1:0][TC-1:0] p3_top,
    output logic [VARIABLES-1:0][TC-1:0] p3_right,
    output logic [VARIABLES-1:0][TC-1:0] p3_bottom,
    output logic [VARIABLES-1:0][TC-1:0] p3_left
);
    // ── Colour constants ───────────────────────────────────────
    localparam logic [TC-1:0] X = 6'b000001; // boundary
    localparam logic [TC-1:0] A = 6'b000010;
    localparam logic [TC-1:0] B = 6'b000100;
    localparam logic [TC-1:0] C = 6'b001000;
    localparam logic [TC-1:0] D = 6'b010000;
    localparam logic [TC-1:0] E = 6'b100000;

    // ── Rotation 0 (top right bottom left as defined) ─────────
    // piece: 15    14    13    12    11    10     9     8
    //         7     6     5     4     3     2     1     0
    assign p0_top    = '{ C,    C,    C,    C,    E,    E,    D,    D,
                          E,    D,    C,    C,    B,    B,    A,    A };
    assign p0_right  = '{ E,    D,    D,    C,    B,    A,    B,    A,
                          B,    A,    B,    A,    B,    A,    B,    A };
    assign p0_bottom = '{ E,    D,    C,    E,    X,    X,    X,    X,
                          X,    X,    X,    X,    X,    X,    X,    X };
    assign p0_left   = '{ D,    D,    E,    E,    B,    B,    B,    B,
                          A,    A,    A,    A,    X,    X,    X,    X };

    // ── Rotation 1 (left becomes top) ─────────────────────────
    assign p1_top    = '{ D,    D,    E,    E,    B,    B,    B,    B,
                          A,    A,    A,    A,    X,    X,    X,    X };
    assign p1_right  = '{ C,    C,    C,    C,    E,    E,    D,    D,
                          E,    D,    C,    C,    B,    B,    A,    A };
    assign p1_bottom = '{ E,    D,    D,    C,    B,    A,    B,    A,
                          B,    A,    B,    A,    B,    A,    B,    A };
    assign p1_left   = '{ E,    D,    C,    E,    X,    X,    X,    X,
                          X,    X,    X,    X,    X,    X,    X,    X };

    // ── Rotation 2 (bottom becomes top) ───────────────────────
    assign p2_top    = '{ E,    D,    C,    E,    X,    X,    X,    X,
                          X,    X,    X,    X,    X,    X,    X,    X };
    assign p2_right  = '{ D,    D,    E,    E,    B,    B,    B,    B,
                          A,    A,    A,    A,    X,    X,    X,    X };
    assign p2_bottom = '{ C,    C,    C,    C,    E,    E,    D,    D,
                          E,    D,    C,    C,    B,    B,    A,    A };
    assign p2_left   = '{ E,    D,    D,    C,    B,    A,    B,    A,
                          B,    A,    B,    A,    B,    A,    B,    A };

    // ── Rotation 3 (right becomes top) ────────────────────────
    assign p3_top    = '{ E,    D,    D,    C,    B,    A,    B,    A,
                          B,    A,    B,    A,    B,    A,    B,    A };
    assign p3_right  = '{ E,    D,    C,    E,    X,    X,    X,    X,
                          X,    X,    X,    X,    X,    X,    X,    X };
    assign p3_bottom = '{ D,    D,    E,    E,    B,    B,    B,    B,
                          A,    A,    A,    A,    X,    X,    X,    X };
    assign p3_left   = '{ C,    C,    C,    C,    E,    E,    D,    D,
                          E,    D,    C,    C,    B,    B,    A,    A };

endmodule
