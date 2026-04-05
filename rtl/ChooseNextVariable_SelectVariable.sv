// ─────────────────────────────────────────────────────────────
// SelectVariable
//
//! Selects the candidate variable with the minimum domain size.
//! Ties are broken by lowest variable ID (priority encoder).
//! Iterates high to low so the lowest ID wins (last write wins).
// ─────────────────────────────────────────────────────────────
module ChooseNextVariable_SelectVariable #(
    parameter int V = 16 //! Number of variables
)(
    input  logic [V-1:0]             in_candidates,       //! bitmask of candidate variables, unassigned neighbours of singletons
    input  logic [V-1:0][$clog2(4*V+1)-1:0] in_pop_count, //! domain size per variable
    input  logic [$clog2(4*V+1)-1:0] in_min_count,        //! minimum domain size
    output logic [$clog2(V)-1:0]     out_next_var,        //! chosen variable ID
    output logic                     out_valid            //! 1 if valid candidate found
);
    localparam int ID_BITS = $clog2(V);

    //! Iterate high to low — last write wins = lowest ID selected.
    always_comb begin : select_next_variable
        out_next_var = '0; // default — overwritten if valid candidate found
        out_valid    = 1'b0;
        for (int i = V-1; i >= 0; i--) begin
            if (in_candidates[i] && in_pop_count[i] == in_min_count) begin
                out_next_var = ID_BITS'(i);
                out_valid    = 1'b1;
            end
        end
    end

endmodule
