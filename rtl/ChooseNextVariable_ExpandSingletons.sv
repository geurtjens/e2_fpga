// ─────────────────────────────────────────────────────────────
// ExpandSingletons
//
//! Expands singleton variables to their unassigned neighbours.
//! Each singleton contributes its four neighbours (up/down/left/right).
//! NOT_FIRST_COL and NOT_LAST_COL prevent row wrap-around.
// ─────────────────────────────────────────────────────────────
module ChooseNextVariable_ExpandSingletons #(
    parameter int N = 4, //! Puzzle size
    parameter int V = N * N //! Number of variables — derived, do not override
)(
    input  logic [V-1:0] in_singletons,      //! bitmask of assigned variables
    input  logic [V-1:0] in_not_first_col,   //! mask — 1 everywhere except column 0
    input  logic [V-1:0] in_not_last_col,    //! mask — 1 everywhere except column N-1
    input  logic [V-1:0] in_unassignedVariables, //! bitmask — 1=unassigned
    output logic [V-1:0] out_candidates      //! unassigned neighbours of singletons
);
    localparam logic [V-1:0] VALID_MASK = V'((1 << V) - 1);

    logic [V-1:0] expanded;

    //! Expand singletons to their four neighbours then
    //! mask to only unassigned variables within bounds.
    always_comb begin : expand_singletons_to_neighbours
        expanded =
            (in_singletons >> N)                          |  // up
            (in_singletons << N)                          |  // down
            ((in_singletons & in_not_first_col) >> 1)     |  // left
            ((in_singletons & in_not_last_col)  << 1);        // right

        out_candidates = expanded & VALID_MASK & in_unassignedVariables;
    end

endmodule
