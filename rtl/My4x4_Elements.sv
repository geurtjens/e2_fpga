// ─────────────────────────────────────────────────────────────
// Elements_My4x4
//
//! Tile element colour masks for the My4x4 puzzle (4x4).
//!
//! Puzzle:  abxx aaxx baxx bbxx /
//!          iaxa jbxa faxb hbxa /
//!          ibxb ebxa gaxb haxb /
//!          cdie hhdj fjgg jgci
//! N=4, V=16, CC=11
//! Colours: x=bit0  a=bit1  b=bit2  c=bit3  d=bit4  e=bit5
//!          f=bit6  g=bit7  h=bit8  i=bit9  j=bit10
//!
//! Rotation is handled externally by the consumer (e.g. DomainToColour).
//!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
//!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
//!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
//!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top
// ─────────────────────────────────────────────────────────────
module My4x4_Elements #(
    parameter int CC = 11,
    parameter int V  = 16
)(
    output logic [V-1:0][CC-1:0] out_elements_top,    //! top colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_right,  //! right colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_bottom, //! bottom colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_left    //! left colour for each tile.
);

    // ── Colour bit masks ──────────────────────────────────────
    localparam logic [CC-1:0] X = 11'b00000000001; // boundary grey
    localparam logic [CC-1:0] A = 11'b00000000010;
    localparam logic [CC-1:0] B = 11'b00000000100;
    localparam logic [CC-1:0] C = 11'b00000001000;
    localparam logic [CC-1:0] D = 11'b00000010000;
    localparam logic [CC-1:0] E = 11'b00000100000;
    localparam logic [CC-1:0] F = 11'b00001000000;
    localparam logic [CC-1:0] G = 11'b00010000000;
    localparam logic [CC-1:0] H = 11'b00100000000;
    localparam logic [CC-1:0] I = 11'b01000000000;
    localparam logic [CC-1:0] J = 11'b10000000000;

    // ── Tile definitions ──────────────────────────────────────
    // tile  string  top  right  bottom  left
    //   0   abxx     a     b      x      x
    //   1   aaxx     a     a      x      x
    //   2   baxx     b     a      x      x
    //   3   bbxx     b     b      x      x
    //   4   iaxa     i     a      x      a
    //   5   jbxa     j     b      x      a
    //   6   faxb     f     a      x      b
    //   7   hbxa     h     b      x      a
    //   8   ibxb     i     b      x      b
    //   9   ebxa     e     b      x      a
    //  10   gaxb     g     a      x      b
    //  11   haxb     h     a      x      b
    //  12   cdie     c     d      i      e
    //  13   hhdj     h     h      d      j
    //  14   fjgg     f     j      g      g
    //  15   jgci     j     g      c      i

    assign out_elements_top[ 0] = A; // abxx
    assign out_elements_top[ 1] = A; // aaxx
    assign out_elements_top[ 2] = B; // baxx
    assign out_elements_top[ 3] = B; // bbxx
    assign out_elements_top[ 4] = I; // iaxa
    assign out_elements_top[ 5] = J; // jbxa
    assign out_elements_top[ 6] = F; // faxb
    assign out_elements_top[ 7] = H; // hbxa
    assign out_elements_top[ 8] = I; // ibxb
    assign out_elements_top[ 9] = E; // ebxa
    assign out_elements_top[10] = G; // gaxb
    assign out_elements_top[11] = H; // haxb
    assign out_elements_top[12] = C; // cdie
    assign out_elements_top[13] = H; // hhdj
    assign out_elements_top[14] = F; // fjgg
    assign out_elements_top[15] = J; // jgci

    assign out_elements_right[ 0] = B; // abxx
    assign out_elements_right[ 1] = A; // aaxx
    assign out_elements_right[ 2] = A; // baxx
    assign out_elements_right[ 3] = B; // bbxx
    assign out_elements_right[ 4] = A; // iaxa
    assign out_elements_right[ 5] = B; // jbxa
    assign out_elements_right[ 6] = A; // faxb
    assign out_elements_right[ 7] = B; // hbxa
    assign out_elements_right[ 8] = B; // ibxb
    assign out_elements_right[ 9] = B; // ebxa
    assign out_elements_right[10] = A; // gaxb
    assign out_elements_right[11] = A; // haxb
    assign out_elements_right[12] = D; // cdie
    assign out_elements_right[13] = H; // hhdj
    assign out_elements_right[14] = J; // fjgg
    assign out_elements_right[15] = G; // jgci

    assign out_elements_bottom[ 0] = X; // abxx
    assign out_elements_bottom[ 1] = X; // aaxx
    assign out_elements_bottom[ 2] = X; // baxx
    assign out_elements_bottom[ 3] = X; // bbxx
    assign out_elements_bottom[ 4] = X; // iaxa
    assign out_elements_bottom[ 5] = X; // jbxa
    assign out_elements_bottom[ 6] = X; // faxb
    assign out_elements_bottom[ 7] = X; // hbxa
    assign out_elements_bottom[ 8] = X; // ibxb
    assign out_elements_bottom[ 9] = X; // ebxa
    assign out_elements_bottom[10] = X; // gaxb
    assign out_elements_bottom[11] = X; // haxb
    assign out_elements_bottom[12] = I; // cdie
    assign out_elements_bottom[13] = D; // hhdj
    assign out_elements_bottom[14] = G; // fjgg
    assign out_elements_bottom[15] = C; // jgci

    assign out_elements_left[ 0] = X; // abxx
    assign out_elements_left[ 1] = X; // aaxx
    assign out_elements_left[ 2] = X; // baxx
    assign out_elements_left[ 3] = X; // bbxx
    assign out_elements_left[ 4] = A; // iaxa
    assign out_elements_left[ 5] = A; // jbxa
    assign out_elements_left[ 6] = B; // faxb
    assign out_elements_left[ 7] = A; // hbxa
    assign out_elements_left[ 8] = B; // ibxb
    assign out_elements_left[ 9] = A; // ebxa
    assign out_elements_left[10] = B; // gaxb
    assign out_elements_left[11] = B; // haxb
    assign out_elements_left[12] = E; // cdie
    assign out_elements_left[13] = J; // hhdj
    assign out_elements_left[14] = G; // fjgg
    assign out_elements_left[15] = I; // jgci

endmodule
