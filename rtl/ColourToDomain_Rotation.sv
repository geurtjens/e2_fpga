// ─────────────────────────────────────────────────────────────
// ColourToDomainRotation
//
//! Filters the domain of a single variable for a single rotation
//! by checking every piece against the variable's colour
//! constraints on all four edges.
//
//! A tile is kept only if its colour on every edge has at least
//! one bit in common with the variable's constraint mask for that
//! edge (AND is non-zero on all four sides).
//
//! Fully combinational — all pieces checked simultaneously.
//
// Parameters
//   V — total number of pieces (and domain width)
//   CC        — total colour bits per edge
//
// Inputs
//   domain      — current domain bitmask for this variable and
//                 rotation, one bit per piece
//   top..left   — colour constraint masks for this variable
//   p_top..left — piece colour patterns for this rotation,
//                 indexed by piece
//
// Outputs
//   domain_out  — filtered domain bitmask
//   changed     — 1 if any bit was cleared
//   deadend     — 1 if domain was non-empty but is now empty
// ─────────────────────────────────────────────────────────────
module ColourToDomain_Rotation #(
    parameter int V = 16,                           //! n*n number of variables in game
    parameter int CC = 6                            //! colour count - number of bits in each colour
)(
    input  logic [V-1:0] in_domain,                 //! domain of a passed in rotation

    input  logic [CC-1:0] in_colour_top,            //! top colour bitmask for variable
    input  logic [CC-1:0] in_colour_right,          //! right colour bitmask for variable
    input  logic [CC-1:0] in_colour_bottom,         //! bottom colour bitmask for variable
    input  logic [CC-1:0] in_colour_left,           //! left colour bitmask for variable

    input  logic [V-1:0][CC-1:0] in_element_top,    //! top pattern for this rotation and position
    input  logic [V-1:0][CC-1:0] in_element_right,  //! right pattern for this rotation and position
    input  logic [V-1:0][CC-1:0] in_element_bottom, //! bottom pattern for this rotation and position
    input  logic [V-1:0][CC-1:0] in_element_left,   //! left pattern for this rotation and position

    output logic [V-1:0] out_domain,                //! domain that was updated due to colour to domain operation
    output logic         out_changed,               //! have any changes occurred
    output logic         out_deadend                //! did this operation result in an empty domain
);

    //! Discover what bits are set in domain and add that to the colours for this given rotation
    always_comb begin : apply_colour_to_domain_and_detect_change_deadend
        
        // Step 1 - Each bit set selectively below if piece passes check
        out_domain = '0;

        // Step 2 — test each piece against constraints 
        // Piece p survives if it was in the domain AND its colour
        // on every edge overlaps with the constraint mask
        for (int p = 0; p < V; p++) begin
            if (in_domain[p] &&
                (in_colour_top    & in_element_top[p])    != '0 &&
                (in_colour_right  & in_element_right[p])  != '0 &&
                (in_colour_bottom & in_element_bottom[p]) != '0 &&
                (in_colour_left   & in_element_left[p])   != '0)
                out_domain[p] = 1'b1;
        end

        // ── Step 3 — changed detection ─────────────────────────
        // True if any bit was cleared — domain only ever shrinks
        out_changed = (out_domain != in_domain);

        // ── Step 4 — deadend detection ─────────────────────────
        // True if domain was non-empty but is now completely empty
        out_deadend = (in_domain != '0) && (out_domain == '0);
    end

endmodule
