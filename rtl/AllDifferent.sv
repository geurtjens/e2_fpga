// ─────────────────────────────────────────────────────────────
// AllDifferent
//
//! Removes taken tiles from every active variable's domain.
//! Variables NOT in variablesIncludedMask are singletons and
//! are passed through unchanged.
//
// ─────────────────────────────────────────────────────────────
module AllDifferent #(
    parameter int N = 4,     //! size of puzzle
    parameter int V = N * N  //! number of variables N*N
)(
    input  logic [V-1:0][V-1:0] in_domain_r0,           //! original domain rotation 0 (0 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0] in_domain_r1,           //! original domain rotation 1 (90 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0] in_domain_r2,           //! original domain rotation 2 (180 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0] in_domain_r3,           //! original domain rotation 3 (270 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0]        in_unassignedVariables, //! bitmask for available variables with 1=available 0=unavailable
    input  logic [V-1:0]        in_unassignedTiles,     //! bitmask for available tiles with 1=available 0=unavailable
    output logic [V-1:0][V-1:0] out_domain_r0,          //! updated domain rotation 0 (0 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0] out_domain_r1,          //! updated domain rotation 1 (90 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0] out_domain_r2,          //! updated domain rotation 2 (180 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0] out_domain_r3,          //! updated domain rotation 3 (270 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic                out_changed,            //! has a change occurred and output different to input
    output logic                out_deadend             //! have we reached an impossible state
);

    //! we apply the mask for all variables that are unassigned and make sure they only have unassigned tiles in them
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

    //! detect changes between the input and output and also detect a deadend state where we have an empty domain
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
