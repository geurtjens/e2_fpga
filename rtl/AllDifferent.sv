// ─────────────────────────────────────────────────────────────
// AllDifferent
//
// Removes taken tiles from every active variable's domain.
// Variables NOT in variablesIncludedMask are singletons and
// are passed through unchanged.
//
// tilesTaken is pre-computed by Driver and passed in so it
// does not need to be recalculated here.
// ─────────────────────────────────────────────────────────────
module AllDifferent #(
    parameter int N = 4,
    parameter int V = N * N  //! number of variables — derived, do not override
)(
    input  logic [V-1:0][V-1:0] in_domain_r0,
    input  logic [V-1:0][V-1:0] in_domain_r1,
    input  logic [V-1:0][V-1:0] in_domain_r2,
    input  logic [V-1:0][V-1:0] in_domain_r3,
    input  logic [V-1:0]        in_unassignedVariables,
    input  logic [V-1:0]        in_unassignedTiles,
    output logic [V-1:0][V-1:0] out_domain_r0,
    output logic [V-1:0][V-1:0] out_domain_r1,
    output logic [V-1:0][V-1:0] out_domain_r2,
    output logic [V-1:0][V-1:0] out_domain_r3,
    output logic                out_changed,
    output logic                out_deadend
);
    always_comb begin : apply_mask_to_active_variables
        for (int i = 0; i < V; i++) begin
            if (in_unassignedVariables[i]) begin
                out_domain_r0[i] = in_domain_r0[i] & in_unassignedTiles;
                out_domain_r1[i] = in_domain_r1[i] & in_unassignedTiles;
                out_domain_r2[i] = in_domain_r2[i] & in_unassignedTiles;
                out_domain_r3[i] = in_domain_r3[i] & in_unassignedTiles;
            end else begin
                out_domain_r0[i] = in_domain_r0[i];
                out_domain_r1[i] = in_domain_r1[i];
                out_domain_r2[i] = in_domain_r2[i];
                out_domain_r3[i] = in_domain_r3[i];
            end
        end
    end

    always_comb begin : detect_changed_and_deadend
        out_changed = 1'b0;
        out_deadend = 1'b0;
        for (int i = 0; i < V; i++) begin
            if (in_unassignedVariables[i]) begin
                if (out_domain_r0[i] != in_domain_r0[i] ||
                    out_domain_r1[i] != in_domain_r1[i] ||
                    out_domain_r2[i] != in_domain_r2[i] ||
                    out_domain_r3[i] != in_domain_r3[i])
                    out_changed = 1'b1;
                if ((out_domain_r0[i] | out_domain_r1[i] |
                     out_domain_r2[i] | out_domain_r3[i]) == '0)
                    out_deadend = 1'b1;
            end
        end
    end

endmodule
