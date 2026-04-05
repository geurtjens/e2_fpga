// ─────────────────────────────────────────────────────────────
// Elements_My3x3_Unsolvable
//
//! Tile element colour masks for the My3x3_Unsolvable puzzle (3x3).
//!
//! Puzzle:  bbxx baxx aaxx /
//!          abxx faxb caxa /
//!          dbxa ebxb ddfc
//! N=3, V=9, CC=7
//! Colours: x=bit0  a=bit1  b=bit2  c=bit3
//!          d=bit4  e=bit5  f=bit6
//!
//! Note: differs from My3x3 only in tile 8: ddfc instead of edfc.
//!
//! Rotation is handled externally by the consumer (e.g. DomainToColour).
//!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
//!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
//!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
//!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top
// ─────────────────────────────────────────────────────────────
module My3x3_Unsolvable_Elements #(
    parameter int CC = 7,
    parameter int V  = 9
)(
    output logic [V-1:0][CC-1:0] out_elements_top,    //! top colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_right,  //! right colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_bottom, //! bottom colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_left    //! left colour for each tile.
);

    // ── Colour bit masks ──────────────────────────────────────
    localparam logic [CC-1:0] X = 7'b0000001; // boundary grey
    localparam logic [CC-1:0] A = 7'b0000010;
    localparam logic [CC-1:0] B = 7'b0000100;
    localparam logic [CC-1:0] C = 7'b0001000;
    localparam logic [CC-1:0] D = 7'b0010000;
    localparam logic [CC-1:0] E = 7'b0100000;
    localparam logic [CC-1:0] F = 7'b1000000;

    // ── Tile definitions ──────────────────────────────────────
    // tile  string  top  right  bottom  left
    //   0   bbxx     b     b      x      x
    //   1   baxx     b     a      x      x
    //   2   aaxx     a     a      x      x
    //   3   abxx     a     b      x      x
    //   4   faxb     f     a      x      b
    //   5   caxa     c     a      x      a
    //   6   dbxa     d     b      x      a
    //   7   ebxb     e     b      x      b
    //   8   ddfc     d     d      f      c   ← differs from My3x3 (was edfc)

    assign out_elements_top[0] = B; // bbxx
    assign out_elements_top[1] = B; // baxx
    assign out_elements_top[2] = A; // aaxx
    assign out_elements_top[3] = A; // abxx
    assign out_elements_top[4] = F; // faxb
    assign out_elements_top[5] = C; // caxa
    assign out_elements_top[6] = D; // dbxa
    assign out_elements_top[7] = E; // ebxb
    assign out_elements_top[8] = D; // ddfc

    assign out_elements_right[0] = B; // bbxx
    assign out_elements_right[1] = A; // baxx
    assign out_elements_right[2] = A; // aaxx
    assign out_elements_right[3] = B; // abxx
    assign out_elements_right[4] = A; // faxb
    assign out_elements_right[5] = A; // caxa
    assign out_elements_right[6] = B; // dbxa
    assign out_elements_right[7] = B; // ebxb
    assign out_elements_right[8] = D; // ddfc

    assign out_elements_bottom[0] = X; // bbxx
    assign out_elements_bottom[1] = X; // baxx
    assign out_elements_bottom[2] = X; // aaxx
    assign out_elements_bottom[3] = X; // abxx
    assign out_elements_bottom[4] = X; // faxb
    assign out_elements_bottom[5] = X; // caxa
    assign out_elements_bottom[6] = X; // dbxa
    assign out_elements_bottom[7] = X; // ebxb
    assign out_elements_bottom[8] = F; // ddfc

    assign out_elements_left[0] = X; // bbxx
    assign out_elements_left[1] = X; // baxx
    assign out_elements_left[2] = X; // aaxx
    assign out_elements_left[3] = X; // abxx
    assign out_elements_left[4] = B; // faxb
    assign out_elements_left[5] = A; // caxa
    assign out_elements_left[6] = A; // dbxa
    assign out_elements_left[7] = B; // ebxb
    assign out_elements_left[8] = C; // ddfc

endmodule
