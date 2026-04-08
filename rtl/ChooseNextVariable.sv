// ─────────────────────────────────────────────────────────────
// ChooseNextVariable
//
//! Selects the next variable for the solver to branch on
//! using the Minimum Remaining Values (MRV) heuristic.
//!
//! Strategy:
//!   1. Find all singletons (assigned variables — NOT in mask)
//!   2. Expand to unassigned neighbours (up/down/left/right)
//!   3. Among neighbours pick the one with smallest domain
//!   4. If tie, pick the lowest variable ID
//!   5. Return binary encoded variable ID
//!
//! Submodules:
//!   ExpandSingletons    — finds candidate neighbours
//!   ComputeDomainSizes  — counts bits in each domain
//!   FindMinimumDomain   — finds smallest domain size
//!   SelectVariable      — priority encodes the winner
//
// Parameters
//   N — board side length (board is N x N)
//   V — number of variables (derived from N — do not override)
// ─────────────────────────────────────────────────────────────
module ChooseNextVariable #(
    parameter int N = 4,      //! Puzzle size
    parameter int V = N * N   //! Number of variables in game
)(
    input  logic [V-1:0]         in_unassignedVariables, //! bitmask — 1=unassigned, 0=singleton
    input  logic [V-1:0][V-1:0]  in_domain_r0,           //! domain rotation 0
    input  logic [V-1:0][V-1:0]  in_domain_r1,           //! domain rotation 1
    input  logic [V-1:0][V-1:0]  in_domain_r2,           //! domain rotation 2
    input  logic [V-1:0][V-1:0]  in_domain_r3,           //! domain rotation 3
    output logic [$clog2(V)-1:0] out_next_var,           //! chosen variable ID
    output logic                 out_valid               //! 1 if valid candidate found
);

    // ── Internal signals ───────────────────────────────────────
    logic [V-1:0]             candidates;
    logic [V-1:0][$clog2(4*V+1)-1:0] pop_count;
    logic [$clog2(4*V+1)-1:0] min_count;

    //! Step 1 — expand singletons to candidate neighbours.
    ChooseNextVariable_ExpandSingletons #(.N(N), .V(V)) expand_inst (
        .in_unassignedVariables  (in_unassignedVariables),
        .out_candidates     (candidates)
    );

    //! Step 2 — compute domain sizes for all variables. 
    DomainSizes #(.V(V)) domain_sizes_inst (
        .in_domain_r0   (in_domain_r0),
        .in_domain_r1   (in_domain_r1),
        .in_domain_r2   (in_domain_r2),
        .in_domain_r3   (in_domain_r3),
        .out_pop_count  (pop_count)
    );

    //! Step 3 — find minimum domain size among candidates.
    ChooseNextVariable_FindMinimumDomain #(.V(V)) min_domain_inst (
        .in_candidates  (candidates),
        .in_pop_count   (pop_count),
        .out_min_count  (min_count)
    );

    //! Step 4 — select variable with minimum domain size.
    ChooseNextVariable_SelectVariable #(.V(V)) select_inst (
        .in_candidates  (candidates),
        .in_pop_count   (pop_count),
        .in_min_count   (min_count),
        .out_next_var   (out_next_var),
        .out_valid      (out_valid)
    );

endmodule
