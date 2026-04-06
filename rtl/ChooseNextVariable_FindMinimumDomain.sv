/// ─────────────────────────────────────────────────────────────
// ChooseNextVariable_FindMinimumDomain
//
//! Scans all candidate variables and finds the smallest domain
//! size among them.
//!
//! Only candidates with domain count > 1 are considered:
//!   count = 0 — deadend, no tiles available, caught upstream
//!   count = 1 — singleton, already handled by SingletonDetection
//!   count > 1 — valid candidate for branching
//!
//! If no valid candidates exist out_min_count stays at max value.
// ─────────────────────────────────────────────────────────────
module ChooseNextVariable_FindMinimumDomain #(
    parameter int V = 16 //! Number of variables
)(
    input  logic [V-1:0]                     in_candidates, //! bitmask of candidate variables — unassigned neighbours of singletons.
    input  logic [V-1:0][$clog2(4*V+1)-1:0] in_pop_count,  //! combined domain size per variable across all four rotations.
    output logic [$clog2(4*V+1)-1:0]        out_min_count  //! minimum domain size among valid candidates (count > 1).
);

    //! Scan all candidates and find the smallest domain size
    //! greater than 1. Variables with count 0 (deadend) or
    //! count 1 (singleton) are excluded from consideration —
    //! they are handled by upstream deadend detection and
    //! SingletonDetection respectively.
    always_comb begin : find_minimum_domain_size
        out_min_count = '1;  // start at max — any valid count will be smaller
        for (int i = 0; i < V; i++) begin
            if (in_candidates[i] && in_pop_count[i] > 1 &&
                in_pop_count[i] < out_min_count)
                out_min_count = in_pop_count[i];
        end
    end

endmodule
