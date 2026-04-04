// ─────────────────────────────────────────────────────────────
// ComputeDomainSizes
//
//! Computes the total domain size for each variable by counting
//! set bits across all four rotation arrays combined.
//! Smaller count = fewer options = higher MRV priority.
// ─────────────────────────────────────────────────────────────
module ChooseNextVariable_ComputeDomainSizes #(
    parameter int V = 16 //! Number of variables
)(
    input  logic [V-1:0][V-1:0] in_domain_r0, //! domain rotation 0
    input  logic [V-1:0][V-1:0] in_domain_r1, //! domain rotation 1
    input  logic [V-1:0][V-1:0] in_domain_r2, //! domain rotation 2
    input  logic [V-1:0][V-1:0] in_domain_r3, //! domain rotation 3
    output logic [V-1:0][$clog2(4*V+1)-1:0] out_pop_count //! domain size per variable
);
    //! Count set bits across all four rotations for each variable.
    always_comb begin : compute_domain_sizes
        for (int i = 0; i < V; i++) begin
            out_pop_count[i] = $countones(in_domain_r0[i]) +
                               $countones(in_domain_r1[i]) +
                               $countones(in_domain_r2[i]) +
                               $countones(in_domain_r3[i]);
        end
    end

endmodule
