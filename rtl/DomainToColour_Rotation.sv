// ─────────────────────────────────────────────────────────────
// DomainToColourRotation
//
// Derives the colour mask for a single variable and single
// rotation by ORing the edge colours of every piece still
// present in the domain.
//
// A colour bit is set in the output if at least one piece
// remaining in the domain has that colour on that edge.
//
// Fully combinational — all pieces checked simultaneously.
//
// Parameters
//   VARIABLES — total number of pieces (and domain width)
//   TC        — total colour bits per edge
//
// Inputs
//   domain      — current domain bitmask for this variable
//                 and rotation, one bit per piece
//   p_top..left — piece colour patterns for this rotation,
//                 indexed by piece
//
// Outputs
//   top..left   — derived colour masks for this variable
// ─────────────────────────────────────────────────────────────
module DomainToColour_Rotation #(
    parameter int V = 4*4,
    parameter int CC = 6 //! colour count - number of bits in each colour
)(
    input  logic [V-1:0] in_domain,

    input  logic [V-1:0][CC-1:0] in_element_top,
    input  logic [V-1:0][CC-1:0] in_element_right,
    input  logic [V-1:0][CC-1:0] in_element_bottom,
    input  logic [V-1:0][CC-1:0] in_element_left,

    output logic [CC-1:0] out_colour_top,
    output logic [CC-1:0] out_colour_right,
    output logic [CC-1:0] out_colour_bottom,
    output logic [CC-1:0] out_colour_left
);
    always_comb begin
        // ── Start with no colours ──────────────────────────────
        out_colour_top    = '0;
        out_colour_right  = '0;
        out_colour_bottom = '0;
        out_colour_left   = '0;

        // ── OR in each surviving piece's colours ───────────────
        // If piece p is still in the domain, its colour on each
        // edge is still a possibility for this variable
        for (int p = 0; p < V; p++) begin
            if (in_domain[p]) begin
                out_colour_top    |= in_element_top[p];
                out_colour_right  |= in_element_right[p];
                out_colour_bottom |= in_element_bottom[p];
                out_colour_left   |= in_element_left[p];
            end
        end
    end

endmodule
