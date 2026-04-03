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
    parameter int N = 8
)(
    input  logic [N-1:0][N-1:0] r0_in,
    input  logic [N-1:0][N-1:0] r1_in,
    input  logic [N-1:0][N-1:0] r2_in,
    input  logic [N-1:0][N-1:0] r3_in,
    input  logic [N-1:0]        variablesIncludedMask,
    input  logic [N-1:0]        tilesTaken,
    output logic [N-1:0][N-1:0] r0_out,
    output logic [N-1:0][N-1:0] r1_out,
    output logic [N-1:0][N-1:0] r2_out,
    output logic [N-1:0][N-1:0] r3_out,
    output logic                changed,
    output logic                deadend
);
    logic [N-1:0] mask;
    assign mask = ~tilesTaken;

    // ── Apply mask to active variables ─────────────────────────
    always_comb begin
        for (int i = 0; i < N; i++) begin
            if (variablesIncludedMask[i]) begin
                r0_out[i] = r0_in[i] & mask;
                r1_out[i] = r1_in[i] & mask;
                r2_out[i] = r2_in[i] & mask;
                r3_out[i] = r3_in[i] & mask;
            end else begin
                r0_out[i] = r0_in[i];
                r1_out[i] = r1_in[i];
                r2_out[i] = r2_in[i];
                r3_out[i] = r3_in[i];
            end
        end
    end

    // ── Detect changed and deadend ─────────────────────────────
    always_comb begin
        changed = 1'b0;
        deadend = 1'b0;
        for (int i = 0; i < N; i++) begin
            if (variablesIncludedMask[i]) begin
                if (r0_out[i] != r0_in[i] || r1_out[i] != r1_in[i] ||
                    r2_out[i] != r2_in[i] || r3_out[i] != r3_in[i])
                    changed = 1'b1;
                if ((r0_out[i] | r1_out[i] | r2_out[i] | r3_out[i]) == '0)
                    deadend = 1'b1;
            end
        end
    end
endmodule


