// ─────────────────────────────────────────────────────────────
// ChooseNextVariable_ExpandSingletons
//
//! Expands singleton variables to their unassigned neighbours.
//! Each singleton contributes its four neighbours (up/down/left/right).
//! NOT_FIRST_COL and NOT_LAST_COL are computed internally to
//! prevent row wrap-around on left and right edges.
// ─────────────────────────────────────────────────────────────
module ChooseNextVariable_ExpandSingletons #(
    parameter int N = 4,      //! Puzzle size
    parameter int V = N * N   //! Number of variables — derived, do not override
)(
    input  logic [V-1:0] in_unassignedVariables, //! bitmask — 1=unassigned, 0=placed (singleton)
    output logic [V-1:0] out_candidates          //! unassigned neighbours of singletons
);

    // ── Column boundary masks — computed at elaboration time ──
    function automatic logic [V-1:0] calc_not_first_col();
        logic [V-1:0] mask;
        mask = '0;
        for (int r = 0; r < N; r++)
            for (int c = 1; c < N; c++)
                mask[r * N + c] = 1'b1;
        return mask;
    endfunction

    function automatic logic [V-1:0] calc_not_last_col();
        logic [V-1:0] mask;
        mask = '0;
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N-1; c++)
                mask[r * N + c] = 1'b1;
        return mask;
    endfunction

    localparam logic [V-1:0] NOT_FIRST_COL = calc_not_first_col(); //! 1 everywhere except column 0 — prevents left wrap.
    localparam logic [V-1:0] NOT_LAST_COL  = calc_not_last_col();  //! 1 everywhere except column N-1 — prevents right wrap.
    localparam logic [V-1:0] VALID_MASK    = V'((1 << V) - 1);     //! masks expansion to valid variable range.

    // ── Singletons are placed variables — complement of unassigned ──
    logic [V-1:0] singletons;  //! bitmask of placed variables — 1=placed, 0=unassigned.
    assign singletons = VALID_MASK & ~in_unassignedVariables;

    // ── Expand singletons to neighbours ───────────────────────
    logic [V-1:0] expanded; //! raw neighbour expansion before masking.

    //! Expands every placed variable to its four grid neighbours then
    //! filters to only unassigned variables within grid bounds.
    //!
    //! The grid is laid out row by row in the bitmask:
    //! <pre>
    //!  0  1  2  3
    //!
    //!  4  5  6  7
    //!
    //!  8  9 10 11
    //!
    //! 12 13 14 15
    //! </pre>
    //!
    //! Shifting by N moves up or down one row:
    //! <pre>
    //!   >> N  — up   (bit 5 → bit 1)
    //!
    //!   << N  — down (bit 5 → bit 9)
    //! </pre>
    //!
    //! Shifting by 1 moves left or right one column:
    //! <pre>
    //!   >> 1  — left  (bit 5 → bit 4)
    //!
    //!   << 1  — right (bit 5 → bit 6)
    //! </pre>
    //!
    //! NOT_FIRST_COL prevents left wrap — zeroes column 0 before >> 1
    //!   so bit 4 cannot shift to bit 3 (wrong row).
    //! NOT_LAST_COL prevents right wrap — zeroes column N-1 before << 1
    //!   so bit 7 cannot shift to bit 8 (wrong row).
    //!
    //! Final AND with VALID_MASK clips any bits shifted beyond the grid.
    //! Final AND with in_unassignedVariables keeps only unassigned neighbours.
    //! 
    //! This is a purely geometric test.  It means it will return neighbours that have domain count of 1 or 0.
   always_comb begin : expand_singletons_to_neighbours
        expanded =
            (singletons >> N)                           |  // up
            (singletons << N)                           |  // down
            ((singletons & NOT_FIRST_COL) >> 1)         |  // left
            ((singletons & NOT_LAST_COL)  << 1);           // right
        out_candidates = expanded & VALID_MASK & in_unassignedVariables;
    end

endmodule
