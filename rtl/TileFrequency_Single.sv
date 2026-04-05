module TileFrequency_Single #(
    parameter int N = 4, //! Size of puzzle grid.
    parameter int V = N * N //! Number of variables in grid (N*N).
)(
    input  logic [V-1:0][V-1:0] in_domain_r0,            //! rotation 0 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1,            //! rotation 1 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2,            //! rotation 2 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3,            //! rotation 3 domain bitmask for each variable.
    input  logic [V-1:0]        in_unassigned_variables, //! bitmask of unassigned variables — 1=unassigned, 0=placed.
    input  logic [V-1:0]        in_unassigned_tiles,     //! bitmask of unassigned tiles — 1=available, 0=already placed.

    output logic [V-1:0][V-1:0] out_domain_r0,           //! updated rotation 0 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r1,           //! updated rotation 1 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r2,           //! updated rotation 2 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r3            //! updated rotation 3 domain bitmask for each variable.
);

    // ── Per-tile forced signals ────────────────────────────────
    logic [V-1:0]        tile_forced; //! 1=tile t is forced to exactly one variable.
    logic [V-1:0][V-1:0] forced_mask; //! for each tile t, a one-hot bitmask of the variable it is forced to.

    // ── Per-variable mask ──────────────────────────────────────
    logic [V-1:0][V-1:0] var_mask; //! for each variable, the AND of all forced tile masks that apply to it.

    // ── find_forced_tiles ─────────────────────────────────────
    //! Scans every unassigned tile and counts how many unassigned
    //! variables still have it in their combined domain.
    //! If exactly one variable can hold a tile, that tile is forced
    //! and forced_mask records which variable it must go to.
    always_comb begin : find_forced_tiles
        for (int t = 0; t < V; t++) begin
            tile_forced[t] = 1'b0;
            forced_mask[t] = '0;
            if (in_unassigned_tiles[t]) begin
                automatic int cnt;
                automatic int fv;
                cnt = 0;
                fv  = 0;
                for (int i = 0; i < V; i++) begin
                    if (in_unassigned_variables[i]) begin
                        automatic logic [V-1:0] combined;
                        combined = in_domain_r0[i] | in_domain_r1[i] |
                                   in_domain_r2[i] | in_domain_r3[i];
                        if (combined[t]) begin
                            cnt = cnt + 1;
                            fv  = i;
                        end
                    end
                end
                if (cnt == 1) begin
                    tile_forced[t] = 1'b1;
                    forced_mask[t] = V'(1) << fv;
                end
            end
        end
    end

    // ── build_variable_masks ──────────────────────────────────
    //! For each variable, collects all tiles that are forced to it
    //! and builds a mask containing only those tile bits.
    //! If no tiles are forced to a variable the mask stays all-ones
    //! so the domain is unchanged. If one or more tiles are forced
    //! to a variable the mask collapses to that single tile bit,
    //! eliminating all other tiles from the domain.
    always_comb begin : build_variable_masks
        for (int i = 0; i < V; i++) begin
            var_mask[i] = '1;  // default — no constraint, pass domain through unchanged
            for (int t = 0; t < V; t++) begin
                if (tile_forced[t] && forced_mask[t][i]) begin
                    var_mask[i] = V'(1) << t;
                end
            end
        end
    end

    // ── apply_masks ───────────────────────────────────────────
    //! ANDs each variable's domain with its var_mask across all
    //! four rotations, removing any tiles that are inconsistent
    //! with the forcing constraints found above.
    always_comb begin : apply_masks
        for (int i = 0; i < V; i++) begin
            out_domain_r0[i] = in_domain_r0[i] & var_mask[i];
            out_domain_r1[i] = in_domain_r1[i] & var_mask[i];
            out_domain_r2[i] = in_domain_r2[i] & var_mask[i];
            out_domain_r3[i] = in_domain_r3[i] & var_mask[i];
        end
    end

endmodule
