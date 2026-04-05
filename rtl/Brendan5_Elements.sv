// ─────────────────────────────────────────────────────────────
// Elements_Brendan5
//
//! Tile element colour masks for the Brendan5 puzzle (5x5).
//!
//! Puzzle:  aaxx baxx bcxx caxx daxa /
//!          dcxa ebxa ecxa fbxa ebxb /
//!          fcxb gcxb daxc faxc fbxc /
//!          gbxc ddef dedf deef degg /
//!          dfef dfgg dgee efgg fggg
//! N=5, V=25, CC=8
//! Colours: x=bit0  a=bit1  b=bit2  c=bit3
//!          d=bit4  e=bit5  f=bit6  g=bit7
//!
//! Rotation is handled externally by the consumer (e.g. DomainToColour).
//!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
//!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
//!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
//!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top
// ─────────────────────────────────────────────────────────────
module Brendan5_Elements #(
    parameter int CC = 8,
    parameter int V  = 25
)(
    output logic [V-1:0][CC-1:0] out_elements_top,    //! top colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_right,  //! right colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_bottom, //! bottom colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_left    //! left colour for each tile.
);

    // ── Colour bit masks ──────────────────────────────────────
    localparam logic [CC-1:0] X = 8'b00000001; // boundary grey
    localparam logic [CC-1:0] A = 8'b00000010;
    localparam logic [CC-1:0] B = 8'b00000100;
    localparam logic [CC-1:0] C = 8'b00001000;
    localparam logic [CC-1:0] D = 8'b00010000;
    localparam logic [CC-1:0] E = 8'b00100000;
    localparam logic [CC-1:0] F = 8'b01000000;
    localparam logic [CC-1:0] G = 8'b10000000;

    // ── Tile definitions ──────────────────────────────────────
    // tile  string  top  right  bottom  left
    //   0   aaxx     a     a      x      x
    //   1   baxx     b     a      x      x
    //   2   bcxx     b     c      x      x
    //   3   caxx     c     a      x      x
    //   4   daxa     d     a      x      a
    //   5   dcxa     d     c      x      a
    //   6   ebxa     e     b      x      a
    //   7   ecxa     e     c      x      a
    //   8   fbxa     f     b      x      a
    //   9   ebxb     e     b      x      b
    //  10   fcxb     f     c      x      b
    //  11   gcxb     g     c      x      b
    //  12   daxc     d     a      x      c
    //  13   faxc     f     a      x      c
    //  14   fbxc     f     b      x      c
    //  15   gbxc     g     b      x      c
    //  16   ddef     d     d      e      f
    //  17   dedf     d     e      d      f
    //  18   deef     d     e      e      f
    //  19   degg     d     e      g      g
    //  20   dfef     d     f      e      f
    //  21   dfgg     d     f      g      g
    //  22   dgee     d     g      e      e
    //  23   efgg     e     f      g      g
    //  24   fggg     f     g      g      g

    assign out_elements_top[ 0] = A; // aaxx
    assign out_elements_top[ 1] = B; // baxx
    assign out_elements_top[ 2] = B; // bcxx
    assign out_elements_top[ 3] = C; // caxx
    assign out_elements_top[ 4] = D; // daxa
    assign out_elements_top[ 5] = D; // dcxa
    assign out_elements_top[ 6] = E; // ebxa
    assign out_elements_top[ 7] = E; // ecxa
    assign out_elements_top[ 8] = F; // fbxa
    assign out_elements_top[ 9] = E; // ebxb
    assign out_elements_top[10] = F; // fcxb
    assign out_elements_top[11] = G; // gcxb
    assign out_elements_top[12] = D; // daxc
    assign out_elements_top[13] = F; // faxc
    assign out_elements_top[14] = F; // fbxc
    assign out_elements_top[15] = G; // gbxc
    assign out_elements_top[16] = D; // ddef
    assign out_elements_top[17] = D; // dedf
    assign out_elements_top[18] = D; // deef
    assign out_elements_top[19] = D; // degg
    assign out_elements_top[20] = D; // dfef
    assign out_elements_top[21] = D; // dfgg
    assign out_elements_top[22] = D; // dgee
    assign out_elements_top[23] = E; // efgg
    assign out_elements_top[24] = F; // fggg

    assign out_elements_right[ 0] = A; // aaxx
    assign out_elements_right[ 1] = A; // baxx
    assign out_elements_right[ 2] = C; // bcxx
    assign out_elements_right[ 3] = A; // caxx
    assign out_elements_right[ 4] = A; // daxa
    assign out_elements_right[ 5] = C; // dcxa
    assign out_elements_right[ 6] = B; // ebxa
    assign out_elements_right[ 7] = C; // ecxa
    assign out_elements_right[ 8] = B; // fbxa
    assign out_elements_right[ 9] = B; // ebxb
    assign out_elements_right[10] = C; // fcxb
    assign out_elements_right[11] = C; // gcxb
    assign out_elements_right[12] = A; // daxc
    assign out_elements_right[13] = A; // faxc
    assign out_elements_right[14] = B; // fbxc
    assign out_elements_right[15] = B; // gbxc
    assign out_elements_right[16] = D; // ddef
    assign out_elements_right[17] = E; // dedf
    assign out_elements_right[18] = E; // deef
    assign out_elements_right[19] = E; // degg
    assign out_elements_right[20] = F; // dfef
    assign out_elements_right[21] = F; // dfgg
    assign out_elements_right[22] = G; // dgee
    assign out_elements_right[23] = F; // efgg
    assign out_elements_right[24] = G; // fggg

    assign out_elements_bottom[ 0] = X; // aaxx
    assign out_elements_bottom[ 1] = X; // baxx
    assign out_elements_bottom[ 2] = X; // bcxx
    assign out_elements_bottom[ 3] = X; // caxx
    assign out_elements_bottom[ 4] = X; // daxa
    assign out_elements_bottom[ 5] = X; // dcxa
    assign out_elements_bottom[ 6] = X; // ebxa
    assign out_elements_bottom[ 7] = X; // ecxa
    assign out_elements_bottom[ 8] = X; // fbxa
    assign out_elements_bottom[ 9] = X; // ebxb
    assign out_elements_bottom[10] = X; // fcxb
    assign out_elements_bottom[11] = X; // gcxb
    assign out_elements_bottom[12] = X; // daxc
    assign out_elements_bottom[13] = X; // faxc
    assign out_elements_bottom[14] = X; // fbxc
    assign out_elements_bottom[15] = X; // gbxc
    assign out_elements_bottom[16] = E; // ddef
    assign out_elements_bottom[17] = D; // dedf
    assign out_elements_bottom[18] = E; // deef
    assign out_elements_bottom[19] = G; // degg
    assign out_elements_bottom[20] = E; // dfef
    assign out_elements_bottom[21] = G; // dfgg
    assign out_elements_bottom[22] = E; // dgee
    assign out_elements_bottom[23] = G; // efgg
    assign out_elements_bottom[24] = G; // fggg

    assign out_elements_left[ 0] = X; // aaxx
    assign out_elements_left[ 1] = X; // baxx
    assign out_elements_left[ 2] = X; // bcxx
    assign out_elements_left[ 3] = X; // caxx
    assign out_elements_left[ 4] = A; // daxa
    assign out_elements_left[ 5] = A; // dcxa
    assign out_elements_left[ 6] = A; // ebxa
    assign out_elements_left[ 7] = A; // ecxa
    assign out_elements_left[ 8] = A; // fbxa
    assign out_elements_left[ 9] = B; // ebxb
    assign out_elements_left[10] = B; // fcxb
    assign out_elements_left[11] = B; // gcxb
    assign out_elements_left[12] = C; // daxc
    assign out_elements_left[13] = C; // faxc
    assign out_elements_left[14] = C; // fbxc
    assign out_elements_left[15] = C; // gbxc
    assign out_elements_left[16] = F; // ddef
    assign out_elements_left[17] = F; // dedf
    assign out_elements_left[18] = F; // deef
    assign out_elements_left[19] = G; // degg
    assign out_elements_left[20] = F; // dfef
    assign out_elements_left[21] = G; // dfgg
    assign out_elements_left[22] = E; // dgee
    assign out_elements_left[23] = G; // efgg
    assign out_elements_left[24] = G; // fggg

endmodule
