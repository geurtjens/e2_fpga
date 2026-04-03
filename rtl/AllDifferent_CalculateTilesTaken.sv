// ─────────────────────────────────────────────────────────────
// CalculateTilesTaken
//
// Computes the union of all values claimed by singleton
// variables (those NOT in variablesIncludedMask).
//
// A singleton is a variable that has already been placed —
// its values are taken and must not appear in any active
// variable's domain.
// ─────────────────────────────────────────────────────────────
module AllDifferent_CalculateTilesTaken #(
    parameter int N = 8
)(
    input  logic [N-1:0][N-1:0] r0_in,
    input  logic [N-1:0][N-1:0] r1_in,
    input  logic [N-1:0][N-1:0] r2_in,
    input  logic [N-1:0][N-1:0] r3_in,
    input  logic [N-1:0]        variablesIncludedMask,
    output logic [N-1:0]        tilesTaken
);
    always_comb begin
        tilesTaken = '0;
        for (int i = 0; i < N; i++) begin
            if (!variablesIncludedMask[i])
                tilesTaken = tilesTaken
                           | r0_in[i] | r1_in[i]
                           | r2_in[i] | r3_in[i];
        end
    end
    
endmodule

