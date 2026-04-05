// ─────────────────────────────────────────────────────────────
// Elements_My5x5
//
//! Tile element colour masks for the My5x5 puzzle (5x5).
//!
//! Puzzle:  adxx ecxx abxx eexx kdxa /
//!          uexb pcxb vaxe faxd rcxe /
//!          gbxd naxb uexd rdxc sbxc /
//!          hexc irps ptol qnvj hlts /
//!          smvo fitg uqpr qmqk utvj
//! N=5, V=25, CC=23
//! Colours: x=bit0   a=bit1   b=bit2   c=bit3   d=bit4
//!          e=bit5   f=bit6   g=bit7   h=bit8   i=bit9
//!          j=bit10  k=bit11  l=bit12  m=bit13  n=bit14
//!          o=bit15  p=bit16  q=bit17  r=bit18  s=bit19
//!          t=bit20  u=bit21  v=bit22
//!
//! Rotation is handled externally by the consumer (e.g. DomainToColour).
//!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
//!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
//!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
//!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top
// ─────────────────────────────────────────────────────────────
module My5x5_Elements #(
    parameter int CC = 23,
    parameter int V  = 25
)(
    output logic [V-1:0][CC-1:0] out_elements_top,    //! top colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_right,  //! right colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_bottom, //! bottom colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_left    //! left colour for each tile.
);

    // ── Colour bit masks ──────────────────────────────────────
    localparam logic [CC-1:0] X = 23'b00000000000000000000001; // boundary grey
    localparam logic [CC-1:0] A = 23'b00000000000000000000010;
    localparam logic [CC-1:0] B = 23'b00000000000000000000100;
    localparam logic [CC-1:0] C = 23'b00000000000000000001000;
    localparam logic [CC-1:0] D = 23'b00000000000000000010000;
    localparam logic [CC-1:0] E = 23'b00000000000000000100000;
    localparam logic [CC-1:0] F = 23'b00000000000000001000000;
    localparam logic [CC-1:0] G = 23'b00000000000000010000000;
    localparam logic [CC-1:0] H = 23'b00000000000000100000000;
    localparam logic [CC-1:0] I = 23'b00000000000001000000000;
    localparam logic [CC-1:0] J = 23'b00000000000010000000000;
    localparam logic [CC-1:0] K = 23'b00000000000100000000000;
    localparam logic [CC-1:0] L = 23'b00000000001000000000000;
    localparam logic [CC-1:0] M = 23'b00000000010000000000000;
    localparam logic [CC-1:0] N = 23'b00000000100000000000000;
    localparam logic [CC-1:0] O = 23'b00000001000000000000000;
    localparam logic [CC-1:0] P = 23'b00000010000000000000000;
    localparam logic [CC-1:0] Q = 23'b00000100000000000000000;
    localparam logic [CC-1:0] R = 23'b00001000000000000000000;
    localparam logic [CC-1:0] S = 23'b00010000000000000000000;
    localparam logic [CC-1:0] T = 23'b00100000000000000000000;
    localparam logic [CC-1:0] U = 23'b01000000000000000000000;
    localparam logic [CC-1:0] V = 23'b10000000000000000000000;

    // ── Tile definitions ──────────────────────────────────────
    // tile  string  top  right  bottom  left
    //   0   adxx     a     d      x      x
    //   1   ecxx     e     c      x      x
    //   2   abxx     a     b      x      x
    //   3   eexx     e     e      x      x
    //   4   kdxa     k     d      x      a
    //   5   uexb     u     e      x      b
    //   6   pcxb     p     c      x      b
    //   7   vaxe     v     a      x      e
    //   8   faxd     f     a      x      d
    //   9   rcxe     r     c      x      e
    //  10   gbxd     g     b      x      d
    //  11   naxb     n     a      x      b
    //  12   uexd     u     e      x      d
    //  13   rdxc     r     d      x      c
    //  14   sbxc     s     b      x      c
    //  15   hexc     h     e      x      c
    //  16   irps     i     r      p      s
    //  17   ptol     p     t      o      l
    //  18   qnvj     q     n      v      j
    //  19   hlts     h     l      t      s
    //  20   smvo     s     m      v      o
    //  21   fitg     f     i      t      g
    //  22   uqpr     u     q      p      r
    //  23   qmqk     q     m      q      k
    //  24   utvj     u     t      v      j

    assign out_elements_top[ 0] = A; // adxx
    assign out_elements_top[ 1] = E; // ecxx
    assign out_elements_top[ 2] = A; // abxx
    assign out_elements_top[ 3] = E; // eexx
    assign out_elements_top[ 4] = K; // kdxa
    assign out_elements_top[ 5] = U; // uexb
    assign out_elements_top[ 6] = P; // pcxb
    assign out_elements_top[ 7] = V; // vaxe
    assign out_elements_top[ 8] = F; // faxd
    assign out_elements_top[ 9] = R; // rcxe
    assign out_elements_top[10] = G; // gbxd
    assign out_elements_top[11] = N; // naxb
    assign out_elements_top[12] = U; // uexd
    assign out_elements_top[13] = R; // rdxc
    assign out_elements_top[14] = S; // sbxc
    assign out_elements_top[15] = H; // hexc
    assign out_elements_top[16] = I; // irps
    assign out_elements_top[17] = P; // ptol
    assign out_elements_top[18] = Q; // qnvj
    assign out_elements_top[19] = H; // hlts
    assign out_elements_top[20] = S; // smvo
    assign out_elements_top[21] = F; // fitg
    assign out_elements_top[22] = U; // uqpr
    assign out_elements_top[23] = Q; // qmqk
    assign out_elements_top[24] = U; // utvj

    assign out_elements_right[ 0] = D; // adxx
    assign out_elements_right[ 1] = C; // ecxx
    assign out_elements_right[ 2] = B; // abxx
    assign out_elements_right[ 3] = E; // eexx
    assign out_elements_right[ 4] = D; // kdxa
    assign out_elements_right[ 5] = E; // uexb
    assign out_elements_right[ 6] = C; // pcxb
    assign out_elements_right[ 7] = A; // vaxe
    assign out_elements_right[ 8] = A; // faxd
    assign out_elements_right[ 9] = C; // rcxe
    assign out_elements_right[10] = B; // gbxd
    assign out_elements_right[11] = A; // naxb
    assign out_elements_right[12] = E; // uexd
    assign out_elements_right[13] = D; // rdxc
    assign out_elements_right[14] = B; // sbxc
    assign out_elements_right[15] = E; // hexc
    assign out_elements_right[16] = R; // irps
    assign out_elements_right[17] = T; // ptol
    assign out_elements_right[18] = N; // qnvj
    assign out_elements_right[19] = L; // hlts
    assign out_elements_right[20] = M; // smvo
    assign out_elements_right[21] = I; // fitg
    assign out_elements_right[22] = Q; // uqpr
    assign out_elements_right[23] = M; // qmqk
    assign out_elements_right[24] = T; // utvj

    assign out_elements_bottom[ 0] = X; // adxx
    assign out_elements_bottom[ 1] = X; // ecxx
    assign out_elements_bottom[ 2] = X; // abxx
    assign out_elements_bottom[ 3] = X; // eexx
    assign out_elements_bottom[ 4] = X; // kdxa
    assign out_elements_bottom[ 5] = X; // uexb
    assign out_elements_bottom[ 6] = X; // pcxb
    assign out_elements_bottom[ 7] = X; // vaxe
    assign out_elements_bottom[ 8] = X; // faxd
    assign out_elements_bottom[ 9] = X; // rcxe
    assign out_elements_bottom[10] = X; // gbxd
    assign out_elements_bottom[11] = X; // naxb
    assign out_elements_bottom[12] = X; // uexd
    assign out_elements_bottom[13] = X; // rdxc
    assign out_elements_bottom[14] = X; // sbxc
    assign out_elements_bottom[15] = X; // hexc
    assign out_elements_bottom[16] = P; // irps
    assign out_elements_bottom[17] = O; // ptol
    assign out_elements_bottom[18] = V; // qnvj
    assign out_elements_bottom[19] = T; // hlts
    assign out_elements_bottom[20] = V; // smvo
    assign out_elements_bottom[21] = T; // fitg
    assign out_elements_bottom[22] = P; // uqpr
    assign out_elements_bottom[23] = Q; // qmqk
    assign out_elements_bottom[24] = V; // utvj

    assign out_elements_left[ 0] = X; // adxx
    assign out_elements_left[ 1] = X; // ecxx
    assign out_elements_left[ 2] = X; // abxx
    assign out_elements_left[ 3] = X; // eexx
    assign out_elements_left[ 4] = A; // kdxa
    assign out_elements_left[ 5] = B; // uexb
    assign out_elements_left[ 6] = B; // pcxb
    assign out_elements_left[ 7] = E; // vaxe
    assign out_elements_left[ 8] = D; // faxd
    assign out_elements_left[ 9] = E; // rcxe
    assign out_elements_left[10] = D; // gbxd
    assign out_elements_left[11] = B; // naxb
    assign out_elements_left[12] = D; // uexd
    assign out_elements_left[13] = C; // rdxc
    assign out_elements_left[14] = C; // sbxc
    assign out_elements_left[15] = C; // hexc
    assign out_elements_left[16] = S; // irps
    assign out_elements_left[17] = L; // ptol
    assign out_elements_left[18] = J; // qnvj
    assign out_elements_left[19] = S; // hlts
    assign out_elements_left[20] = O; // smvo
    assign out_elements_left[21] = G; // fitg
    assign out_elements_left[22] = R; // uqpr
    assign out_elements_left[23] = K; // qmqk
    assign out_elements_left[24] = J; // utvj

endmodule
