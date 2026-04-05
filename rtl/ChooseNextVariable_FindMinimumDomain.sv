// ─────────────────────────────────────────────────────────────
// FindMinimumDomain
//
//! Finds the minimum domain size among candidate variables.
//! Used by MRV heuristic to pick the most constrained variable.
// ─────────────────────────────────────────────────────────────
module ChooseNextVariable_FindMinimumDomain #(
    parameter int V = 16 //! Number of variables
)(
    input  logic [V-1:0]                    in_candidates,  //! bitmask of candidate variables, unassigned neighbours of singletons
    input  logic [V-1:0][$clog2(4*V+1)-1:0] in_pop_count,   //! domain size per variable
    output logic [$clog2(4*V+1)-1:0]        out_min_count   //! minimum domain size among candidates
);
    //! Scan all candidates and find the smallest domain size.
    always_comb begin : find_minimum_domain_size
        out_min_count = '1; // start at max value
        for (int i = 0; i < V; i++) begin
            if (in_candidates[i] && in_pop_count[i] < out_min_count)
                out_min_count = in_pop_count[i];
        end
    end

endmodule
