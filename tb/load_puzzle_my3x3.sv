// ─────────────────────────────────────────────────────────────
// LoadPuzzle — Puzzle_My3x3
//
// ROM module — all values are constants baked in at elaboration.
// No inputs. Outputs the four rotation patterns for every piece.
//
// Puzzle parameters:
//   Name          : My3x3
//   N             : 3  (3x3 board, 9 pieces)
//   borderColours : 2
//   innerColours  : 4
//   TC            : 1 + 2 + 4 = 7 bits per colour edge
//   VARIABLES     : 9
//
// Colour encoding (7 bits):
//   x = boundary = 7'b0000001  (bit 0)
//   a            = 7'b0000010  (bit 1)
//   b            = 7'b0000100  (bit 2)
//   c            = 7'b0001000  (bit 3)
//   d            = 7'b0010000  (bit 4)
//   e            = 7'b0100000  (bit 5)
//   f            = 7'b1000000  (bit 6)
//
// Rotation rule (clockwise):
//   r0: t  r  b  l
//   r1: l  t  r  b   (left  becomes top)
//   r2: b  l  t  r   (bottom becomes top)
//   r3: r  b  l  t   (right  becomes top)
//
// Piece patterns at rotation 0 (top right bottom left):
//    0:bbxx
//    1:baxx
//    2:aaxx
//    3:abxx
//    4:faxb
//    5:caxa
//    6:dbxa
//    7:ebxb
//    8:edfc
// ─────────────────────────────────────────────────────────────
module LoadPuzzle #(
    parameter int N                   = 3,
    parameter int BORDER_COLOUR_COUNT = 2,
    parameter int INNER_COLOUR_COUNT  = 4,
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
    assign p0_top    = '{ 7'b0100000, 7'b0100000, 7'b0010000, 7'b0001000, 7'b1000000, 7'b0000010, 7'b0000010, 7'b0000100, 7'b0000100 };
    assign p0_right  = '{ 7'b0010000, 7'b0000100, 7'b0000100, 7'b0000010, 7'b0000010, 7'b0000100, 7'b0000010, 7'b0000010, 7'b0000100 };
    assign p0_bottom = '{ 7'b1000000, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001 };
    assign p0_left   = '{ 7'b0001000, 7'b0000100, 7'b0000010, 7'b0000010, 7'b0000100, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001 };

    // ── Rotation 1 ────────────────────────────────────────────────────
    assign p1_top    = '{ 7'b0001000, 7'b0000100, 7'b0000010, 7'b0000010, 7'b0000100, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001 };
    assign p1_right  = '{ 7'b0100000, 7'b0100000, 7'b0010000, 7'b0001000, 7'b1000000, 7'b0000010, 7'b0000010, 7'b0000100, 7'b0000100 };
    assign p1_bottom = '{ 7'b0010000, 7'b0000100, 7'b0000100, 7'b0000010, 7'b0000010, 7'b0000100, 7'b0000010, 7'b0000010, 7'b0000100 };
    assign p1_left   = '{ 7'b1000000, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001 };

    // ── Rotation 2 ────────────────────────────────────────────────────
    assign p2_top    = '{ 7'b1000000, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001 };
    assign p2_right  = '{ 7'b0001000, 7'b0000100, 7'b0000010, 7'b0000010, 7'b0000100, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001 };
    assign p2_bottom = '{ 7'b0100000, 7'b0100000, 7'b0010000, 7'b0001000, 7'b1000000, 7'b0000010, 7'b0000010, 7'b0000100, 7'b0000100 };
    assign p2_left   = '{ 7'b0010000, 7'b0000100, 7'b0000100, 7'b0000010, 7'b0000010, 7'b0000100, 7'b0000010, 7'b0000010, 7'b0000100 };

    // ── Rotation 3 ────────────────────────────────────────────────────
    assign p3_top    = '{ 7'b0010000, 7'b0000100, 7'b0000100, 7'b0000010, 7'b0000010, 7'b0000100, 7'b0000010, 7'b0000010, 7'b0000100 };
    assign p3_right  = '{ 7'b1000000, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001 };
    assign p3_bottom = '{ 7'b0001000, 7'b0000100, 7'b0000010, 7'b0000010, 7'b0000100, 7'b0000001, 7'b0000001, 7'b0000001, 7'b0000001 };
    assign p3_left   = '{ 7'b0100000, 7'b0100000, 7'b0010000, 7'b0001000, 7'b1000000, 7'b0000010, 7'b0000010, 7'b0000100, 7'b0000100 };

endmodule