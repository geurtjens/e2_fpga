// ─────────────────────────────────────────────────────────────
// Elements_My4x4_TwoSolutions
//
//! Tile element colour masks for the My4x4_TwoSolutions puzzle (4x4).
//!
//! Puzzle:  aaxx baxx abxx bbxx /
//!          jbxb cbxb daxb ibxa /
//!          jaxb gbxa haxa gaxa /
//!          fhhi iecj gghi djef
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
module My4x4_TwoSolutions_Elements #(
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
    //   0   aaxx     a     a      x      x
    //   1   baxx     b     a      x      x
    //   2   abxx     a     b      x      x
    //   3   bbxx     b     b      x      x
    //   4   jbxb     j     b      x      b
    //   5   cbxb     c     b      x      b
    //   6   daxb     d     a      x      b
    //   7   ibxa     i     b      x      a
    //   8   jaxb     j     a      x      b
    //   9   gbxa     g     b      x      a
    //  10   haxa     h     a      x      a
    //  11   gaxa     g     a      x      a
    //  12   fhhi     f     h      h      i
    //  13   iecj     i     e      c      j
    //  14   gghi     g     g      h      i
    //  15   djef     d     j      e      f

    assign out_elements_top[ 0] = A; // aaxx
    assign out_elements_top[ 1] = B; // baxx
    assign out_elements_top[ 2] = A; // abxx
    assign out_elements_top[ 3] = B; // bbxx
    assign out_elements_top[ 4] = J; // jbxb
    assign out_elements_top[ 5] = C; // cbxb
    assign out_elements_top[ 6] = D; // daxb
    assign out_elements_top[ 7] = I; // ibxa
    assign out_elements_top[ 8] = J; // jaxb
    assign out_elements_top[ 9] = G; // gbxa
    assign out_elements_top[10] = H; // haxa
    assign out_elements_top[11] = G; // gaxa
    assign out_elements_top[12] = F; // fhhi
    assign out_elements_top[13] = I; // iecj
    assign out_elements_top[14] = G; // gghi
    assign out_elements_top[15] = D; // djef

    assign out_elements_right[ 0] = A; // aaxx
    assign out_elements_right[ 1] = A; // baxx
    assign out_elements_right[ 2] = B; // abxx
    assign out_elements_right[ 3] = B; // bbxx
    assign out_elements_right[ 4] = B; // jbxb
    assign out_elements_right[ 5] = B; // cbxb
    assign out_elements_right[ 6] = A; // daxb
    assign out_elements_right[ 7] = B; // ibxa
    assign out_elements_right[ 8] = A; // jaxb
    assign out_elements_right[ 9] = B; // gbxa
    assign out_elements_right[10] = A; // haxa
    assign out_elements_right[11] = A; // gaxa
    assign out_elements_right[12] = H; // fhhi
    assign out_elements_right[13] = E; // iecj
    assign out_elements_right[14] = G; // gghi
    assign out_elements_right[15] = J; // djef

    assign out_elements_bottom[ 0] = X; // aaxx
    assign out_elements_bottom[ 1] = X; // baxx
    assign out_elements_bottom[ 2] = X; // abxx
    assign out_elements_bottom[ 3] = X; // bbxx
    assign out_elements_bottom[ 4] = X; // jbxb
    assign out_elements_bottom[ 5] = X; // cbxb
    assign out_elements_bottom[ 6] = X; // daxb
    assign out_elements_bottom[ 7] = X; // ibxa
    assign out_elements_bottom[ 8] = X; // jaxb
    assign out_elements_bottom[ 9] = X; // gbxa
    assign out_elements_bottom[10] = X; // haxa
    assign out_elements_bottom[11] = X; // gaxa
    assign out_elements_bottom[12] = H; // fhhi
    assign out_elements_bottom[13] = C; // iecj
    assign out_elements_bottom[14] = H; // gghi
    assign out_elements_bottom[15] = E; // djef

    assign out_elements_left[ 0] = X; // aaxx
    assign out_elements_left[ 1] = X; // baxx
    assign out_elements_left[ 2] = X; // abxx
    assign out_elements_left[ 3] = X; // bbxx
    assign out_elements_left[ 4] = B; // jbxb
    assign out_elements_left[ 5] = B; // cbxb
    assign out_elements_left[ 6] = B; // daxb
    assign out_elements_left[ 7] = A; // ibxa
    assign out_elements_left[ 8] = B; // jaxb
    assign out_elements_left[ 9] = A; // gbxa
    assign out_elements_left[10] = A; // haxa
    assign out_elements_left[11] = A; // gaxa
    assign out_elements_left[12] = I; // fhhi
    assign out_elements_left[13] = J; // iecj
    assign out_elements_left[14] = I; // gghi
    assign out_elements_left[15] = F; // djef

endmodule
