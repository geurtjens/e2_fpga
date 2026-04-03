// ─────────────────────────────────────────────────────────────
// Brendan3
//
// ROM module — all values are constants baked in at elaboration.
// No inputs. Outputs the four rotation patterns for every piece.
//
// Puzzle parameters:
//   Name          : Brendan3
//   N             : 3  (3x3 board, 9 pieces)
//   borderColours : 2
//   innerColours  : 2
//   TC            : 1 + 2 + 2 = 5 bits per colour edge
//   VARIABLES     : 9
//
// Colour encoding (5 bits):
//   x = boundary = 5'b00001  (bit 0)
//   a            = 5'b00010  (bit 1)
//   b            = 5'b00100  (bit 2)
//   c            = 5'b01000  (bit 3)
//   d            = 5'b10000  (bit 4)
//
// Rotation rule (clockwise):
//   r0: t  r  b  l
//   r1: l  t  r  b   (left  becomes top)
//   r2: b  l  t  r   (bottom becomes top)
//   r3: r  b  l  t   (right  becomes top)
//
// Piece patterns at rotation 0 (top right bottom left):
//    0:aaxx
//    1:abxx
//    2:baxx
//    3:bbxx
//    4:cbxa
//    5:daxa
//    6:caxb
//    7:dbxb
//    8:ccdd
// ─────────────────────────────────────────────────────────────
module Brendan3 #(
    parameter int N                   = 3,
    parameter int BORDER_COLOUR_COUNT = 2,
    parameter int INNER_COLOUR_COUNT  = 2,
    parameter int TC                  = 1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT,
    parameter int VARIABLES           = N * N
)(
    output logic [VARIABLES-1:0][TC-1:0] p0_top,
    output logic [VARIABLES-1:0][TC-1:0] p0_right,
    output logic [VARIABLES-1:0][TC-1:0] p0_bottom,
    output logic [VARIABLES-1:0][TC-1:0] p0_left,
    output logic [VARIABLES-1:0][TC-1:0] p1_top,
    output logic [VARIABLES-1:0][TC-1:0] p1_right,
    output logic [VARIABLES-1:0][TC-1:0] p1_bottom,
    output logic [VARIABLES-1:0][TC-1:0] p1_left,
    output logic [VARIABLES-1:0][TC-1:0] p2_top,
    output logic [VARIABLES-1:0][TC-1:0] p2_right,
    output logic [VARIABLES-1:0][TC-1:0] p2_bottom,
    output logic [VARIABLES-1:0][TC-1:0] p2_left,
    output logic [VARIABLES-1:0][TC-1:0] p3_top,
    output logic [VARIABLES-1:0][TC-1:0] p3_right,
    output logic [VARIABLES-1:0][TC-1:0] p3_bottom,
    output logic [VARIABLES-1:0][TC-1:0] p3_left
);
    // ── Rotation 0 ────────────────────────────────────────────────────
    assign p0_top    = '{ 5'b01000, 5'b10000, 5'b01000, 5'b10000, 5'b01000, 5'b00100, 5'b00100, 5'b00010, 5'b00010 };
    assign p0_right  = '{ 5'b01000, 5'b00100, 5'b00010, 5'b00010, 5'b00100, 5'b00100, 5'b00010, 5'b00100, 5'b00010 };
    assign p0_bottom = '{ 5'b10000, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001 };
    assign p0_left   = '{ 5'b10000, 5'b00100, 5'b00100, 5'b00010, 5'b00010, 5'b00001, 5'b00001, 5'b00001, 5'b00001 };

    // ── Rotation 1 ────────────────────────────────────────────────────
    assign p1_top    = '{ 5'b10000, 5'b00100, 5'b00100, 5'b00010, 5'b00010, 5'b00001, 5'b00001, 5'b00001, 5'b00001 };
    assign p1_right  = '{ 5'b01000, 5'b10000, 5'b01000, 5'b10000, 5'b01000, 5'b00100, 5'b00100, 5'b00010, 5'b00010 };
    assign p1_bottom = '{ 5'b01000, 5'b00100, 5'b00010, 5'b00010, 5'b00100, 5'b00100, 5'b00010, 5'b00100, 5'b00010 };
    assign p1_left   = '{ 5'b10000, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001 };

    // ── Rotation 2 ────────────────────────────────────────────────────
    assign p2_top    = '{ 5'b10000, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001 };
    assign p2_right  = '{ 5'b10000, 5'b00100, 5'b00100, 5'b00010, 5'b00010, 5'b00001, 5'b00001, 5'b00001, 5'b00001 };
    assign p2_bottom = '{ 5'b01000, 5'b10000, 5'b01000, 5'b10000, 5'b01000, 5'b00100, 5'b00100, 5'b00010, 5'b00010 };
    assign p2_left   = '{ 5'b01000, 5'b00100, 5'b00010, 5'b00010, 5'b00100, 5'b00100, 5'b00010, 5'b00100, 5'b00010 };

    // ── Rotation 3 ────────────────────────────────────────────────────
    assign p3_top    = '{ 5'b01000, 5'b00100, 5'b00010, 5'b00010, 5'b00100, 5'b00100, 5'b00010, 5'b00100, 5'b00010 };
    assign p3_right  = '{ 5'b10000, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001, 5'b00001 };
    assign p3_bottom = '{ 5'b10000, 5'b00100, 5'b00100, 5'b00010, 5'b00010, 5'b00001, 5'b00001, 5'b00001, 5'b00001 };
    assign p3_left   = '{ 5'b01000, 5'b10000, 5'b01000, 5'b10000, 5'b01000, 5'b00100, 5'b00100, 5'b00010, 5'b00010 };

endmodule
