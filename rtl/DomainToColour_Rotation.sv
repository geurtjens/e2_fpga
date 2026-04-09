// ─────────────────────────────────────────────────────────────
// DomainToColour_Rotation
//
//! Derives colour masks for a single variable at a single rotation.
//!
//! For each edge (top, right, bottom, left), ORs together the
//! colours of all tiles still present in the domain bitmask.
//! This gives the set of colours still possible on each edge
//! given the current domain.
//!
//! The result is then ANDed with the incoming colour mask so
//! that colours removed by a previous constraint pass cannot
//! be reinstated. Colours can only narrow, never broaden.
//!
//! Example: if the domain contains tiles 2 and 5, and tile 2
//! has top colour A and tile 5 has top colour B, then
//! out_colour_top = A | B, ANDed with in_colour_top.
//!
//! Parameters
//!   V  — number of variables (and tiles) in the puzzle
//!   CC — colour bits per edge
// ─────────────────────────────────────────────────────────────
module DomainToColour_Rotation #(
    parameter int V  = 4*4, //! number of variables/tiles in the puzzle.
    parameter int CC = 6    //! colour bits per edge.
)(
    input  logic [V-1:0]         in_domain,        //! domain bitmask — 1=tile still possible, 0=eliminated.

    input  logic [CC-1:0]        in_colour_top,    //! current top colour mask — result is ANDed with this.
    input  logic [CC-1:0]        in_colour_right,  //! current right colour mask — result is ANDed with this.
    input  logic [CC-1:0]        in_colour_bottom, //! current bottom colour mask — result is ANDed with this.
    input  logic [CC-1:0]        in_colour_left,   //! current left colour mask — result is ANDed with this.

    input  logic [V-1:0][CC-1:0] in_element_top,    //! top colour for each tile at this rotation.
    input  logic [V-1:0][CC-1:0] in_element_right,  //! right colour for each tile at this rotation.
    input  logic [V-1:0][CC-1:0] in_element_bottom, //! bottom colour for each tile at this rotation.
    input  logic [V-1:0][CC-1:0] in_element_left,   //! left colour for each tile at this rotation.

    output logic [CC-1:0]        out_colour_top,    //! derived top colour mask, narrowed by in_colour_top.
    output logic [CC-1:0]        out_colour_right,  //! derived right colour mask, narrowed by in_colour_right.
    output logic [CC-1:0]        out_colour_bottom, //! derived bottom colour mask, narrowed by in_colour_bottom.
    output logic [CC-1:0]        out_colour_left    //! derived left colour mask, narrowed by in_colour_left.
);

    always_comb begin

        // ── Start with no colours ─────────────────────────────
        //! Begin with all edges at zero — colours are built up
        //! by ORing in each surviving tile's contribution.
        out_colour_top    = '0;
        out_colour_right  = '0;
        out_colour_bottom = '0;
        out_colour_left   = '0;

        // ── OR in each surviving tile's colours ───────────────
        //! For every tile still present in the domain, its colour
        //! on each edge is still a possibility for this variable.
        //! ORing accumulates all remaining colour possibilities.
        for (int p = 0; p < V; p++) begin
            if (in_domain[p]) begin
                out_colour_top    |= in_element_top[p];
                out_colour_right  |= in_element_right[p];
                out_colour_bottom |= in_element_bottom[p];
                out_colour_left   |= in_element_left[p];
            end
        end

        // ── AND with existing colours — can only narrow ───────
        //! Colours removed by a previous constraint pass (e.g.
        //! ColourAssignmentNeighbours or ColourToDomain) cannot
        //! be reinstated by domain-to-colour derivation.
        //! The AND ensures this module is monotonically narrowing.
        out_colour_top    &= in_colour_top;
        out_colour_right  &= in_colour_right;
        out_colour_bottom &= in_colour_bottom;
        out_colour_left   &= in_colour_left;

    end

endmodule
