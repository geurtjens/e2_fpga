module TileFrequencySingle #(
    parameter int N         = 4,
    parameter int VARIABLES = N * N
)(
    input  logic [VARIABLES-1:0]                in_variablesIncludedMask,
    input  logic [VARIABLES-1:0]                in_unassignedTiles,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r0,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r1,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r2,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r3,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r0,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r1,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r2,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r3
);
    // ── Per-tile: is this tile forced to exactly one variable? ─
    logic [VARIABLES-1:0]                           tile_forced;
    logic [VARIABLES-1:0][VARIABLES-1:0]            forced_mask;

    always_comb begin
        for (int t = 0; t < VARIABLES; t++) begin
            tile_forced[t]  = 1'b0;
            forced_mask[t]  = '0;

            if (in_unassignedTiles[t]) begin
                automatic int cnt;
                automatic int fv;
                cnt = 0;
                fv  = 0;
                for (int v = 0; v < VARIABLES; v++) begin
                    if (in_variablesIncludedMask[v]) begin
                        automatic logic [VARIABLES-1:0] combined;
                        combined = in_r0[v] | in_r1[v] |
                                   in_r2[v] | in_r3[v];
                        if (combined[t]) begin
                            cnt = cnt + 1;
                            fv  = v;
                        end
                    end
                end
                if (cnt == 1) begin
                    tile_forced[t] = 1'b1;
                    forced_mask[t] = VARIABLES'(1) << fv;
                end
            end
        end
    end

    // ── Per-variable: compute the AND of all forced masks ──────
    // For each variable v, collect all tiles that force it
    // then AND those masks into its domain
    logic [VARIABLES-1:0][VARIABLES-1:0] var_mask;

    always_comb begin
        for (int v = 0; v < VARIABLES; v++) begin
            var_mask[v] = '1;  // start with all bits set
            for (int t = 0; t < VARIABLES; t++) begin
                // if tile t is forced and its forced variable is v
                // then apply tile mask to var v
                if (tile_forced[t] && forced_mask[t][v]) begin
                    var_mask[v] = VARIABLES'(1) << t;
                end
            end
        end
    end

    // ── Apply masks to outputs ─────────────────────────────────
    always_comb begin
        for (int v = 0; v < VARIABLES; v++) begin
            out_r0[v] = in_r0[v] & var_mask[v];
            out_r1[v] = in_r1[v] & var_mask[v];
            out_r2[v] = in_r2[v] & var_mask[v];
            out_r3[v] = in_r3[v] & var_mask[v];
        end
    end

endmodule