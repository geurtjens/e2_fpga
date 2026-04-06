// ─────────────────────────────────────────────────────────────
// CreateInitialGame
//
// Computes the initial top, right, bottom, left colour masks
// and r0,r1,r2,r3 domain bitmasks for every variable in an
// Eternity-2 style puzzle.
//
// Parameters
//   N                   — board side length (board is N x N)
//   BORDER_COLOUR_COUNT — number of border colours
//   INNER_COLOUR_COUNT  — number of inner colours
//
// Derived constants
//   CC        = 1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT
//   V         = N * N
//   NUM_EDGES = 4 * (N - 2)
//   NUM_INNER = (N - 2) * (N - 2)
//
// Colour bitmask layout (CC bits wide)
//   bit 0              — boundary colour  (always 0b1)
//   bits 1..BC         — border colours
//   bits BC+1..BC+IC   — inner colours
//
// Domain bitmask layout (V bits wide)
//   bits 0..3                 — corner pieces  (4 corners)
//   bits 4..4+NUM_EDGES-1     — edge pieces
//   bits 4+NUM_EDGES..end     — inner pieces
//
// All variables start fully unassigned — the first assignment
// is made externally by Assignment_Complex before propagation.
// ─────────────────────────────────────────────────────────────
module CreateInitialGame #(
    parameter int N                   = 4, //! Size of grid
    parameter int V                   = N * N, //! Number of variables in grid
    parameter int BORDER_COLOUR_COUNT = 3, //! Number of border colours in the grid, edge and corner colours
    parameter int INNER_COLOUR_COUNT  = 2, //! Number of inner colours in the grid
    parameter int CC                  = 1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT //! total number of colours including the boundary colours
)(
    output logic [V-1:0][CC-1:0]  out_colours_top,         //! top colour for each variable in the grid.
    output logic [V-1:0][CC-1:0]  out_colours_right,       //! right colour for each variable in the grid.
    output logic [V-1:0][CC-1:0]  out_colours_bottom,      //! bottom colour for each variable in the grid.
    output logic [V-1:0][CC-1:0]  out_colours_left,        //! left colour for each variable in the grid.
    output logic [V-1:0][V-1:0]   out_domain_r0,           //! rotation 0 domain bitmask for all variables. 1=tile available, 0=not available.
    output logic [V-1:0][V-1:0]   out_domain_r1,           //! rotation 1 domain bitmask for all variables. 1=tile available, 0=not available.
    output logic [V-1:0][V-1:0]   out_domain_r2,           //! rotation 2 domain bitmask for all variables. 1=tile available, 0=not available.
    output logic [V-1:0][V-1:0]   out_domain_r3,           //! rotation 3 domain bitmask for all variables. 1=tile available, 0=not available.
    output logic [V-1:0]          out_unassignedVariables, //! 1=variable unassigned, 0=placed. All ones at start — nothing placed yet.
    output logic [V-1:0]          out_unassignedTiles      //! 1=tile available, 0=placed. All ones at start — nothing placed yet.
);

    // ── Derived constants ──────────────────────────────────────
    localparam int NUM_EDGES = 4 * (N - 2);       //! total number of edge variables in the grid.
    localparam int NUM_INNER = (N - 2) * (N - 2); //! total number of inner variables in the grid.

    // ── Colour masks ───────────────────────────────────────────
    localparam logic [CC-1:0] BOUNDARY = CC'(1); //! boundary colour — bit 0 set only.

    //! border colours — BORDER_COLOUR_COUNT bits set starting at bit 1.
    localparam logic [CC-1:0] BORDER = CC'({BORDER_COLOUR_COUNT{1'b1}}) << 1;

    //! inner colours — INNER_COLOUR_COUNT bits set starting at bit BORDER_COLOUR_COUNT+1.
    localparam logic [CC-1:0] INNER_C = CC'({INNER_COLOUR_COUNT{1'b1}})
                                        << (BORDER_COLOUR_COUNT + 1);

    // ── Domain masks ───────────────────────────────────────────
    //! all 4 corner tiles — bits 0..3 set.
    localparam logic [V-1:0] ALL_CORNERS = V'(4'b1111);

    //! all edge tiles — NUM_EDGES bits set starting at bit 4.
    localparam logic [V-1:0] EDGE_D = V'({NUM_EDGES{1'b1}}) << 4;

    //! all inner tiles — NUM_INNER bits set starting at bit 4+NUM_EDGES.
    localparam logic [V-1:0] INNER_D = V'({NUM_INNER{1'b1}}) << (4 + NUM_EDGES);

    // ── Availability masks — all unassigned at start ───────────
    //! Nothing is placed yet — the first assignment is made externally.
    assign out_unassignedVariables = '1;
    assign out_unassignedTiles     = '1;

    //! Assigns all variables with correct colours and domain depending
    //! on grid position — corner, edge or inner. All corner variables
    //! start with all 4 corner tiles available in their valid rotation.
    //! The first assignment (top-left corner) is made externally.
    always_comb begin : set_initial_constraints
        for (int id = 0; id < V; id++) begin

            // defaults
            out_colours_top[id]    = '0;
            out_colours_right[id]  = '0;
            out_colours_bottom[id] = '0;
            out_colours_left[id]   = '0;
            out_domain_r0[id]      = '0;
            out_domain_r1[id]      = '0;
            out_domain_r2[id]      = '0;
            out_domain_r3[id]      = '0;

            // ── Top Left Corner  (x==0, y==0) ─────────────────
            if ((id % N) == 0 && (id / N) == 0) begin
                out_colours_top[id]    = BOUNDARY;
                out_colours_right[id]  = BORDER;
                out_colours_bottom[id] = BORDER;
                out_colours_left[id]   = BOUNDARY;
                out_domain_r1[id]      = ALL_CORNERS; // all 4 corner tiles, rotation 1 only
            end
            // ── Bottom Left Corner  (x==0, y==N-1) ────────────
            else if ((id % N) == 0 && (id / N) == N-1) begin
                out_colours_top[id]    = BORDER;
                out_colours_right[id]  = BORDER;
                out_colours_bottom[id] = BOUNDARY;
                out_colours_left[id]   = BOUNDARY;
                out_domain_r0[id]      = ALL_CORNERS; // all 4 corner tiles, rotation 0 only
            end
            // ── Top Right Corner  (x==N-1, y==0) ──────────────
            else if ((id % N) == N-1 && (id / N) == 0) begin
                out_colours_top[id]    = BOUNDARY;
                out_colours_right[id]  = BOUNDARY;
                out_colours_bottom[id] = BORDER;
                out_colours_left[id]   = BORDER;
                out_domain_r2[id]      = ALL_CORNERS; // all 4 corner tiles, rotation 2 only
            end
            // ── Bottom Right Corner  (x==N-1, y==N-1) ─────────
            else if ((id % N) == N-1 && (id / N) == N-1) begin
                out_colours_top[id]    = BORDER;
                out_colours_right[id]  = BOUNDARY;
                out_colours_bottom[id] = BOUNDARY;
                out_colours_left[id]   = BORDER;
                out_domain_r3[id]      = ALL_CORNERS; // all 4 corner tiles, rotation 3 only
            end
            // ── Bottom Edge  (y==N-1, x>0, x<N-1) ────────────
            else if ((id / N) == N-1) begin
                out_colours_top[id]    = INNER_C;
                out_colours_right[id]  = BORDER;
                out_colours_bottom[id] = BOUNDARY;
                out_colours_left[id]   = BORDER;
                out_domain_r0[id]      = EDGE_D;
            end
            // ── Left Edge  (x==0, y>0, y<N-1) ─────────────────
            else if ((id % N) == 0) begin
                out_colours_top[id]    = BORDER;
                out_colours_right[id]  = INNER_C;
                out_colours_bottom[id] = BORDER;
                out_colours_left[id]   = BOUNDARY;
                out_domain_r1[id]      = EDGE_D;
            end
            // ── Top Edge  (y==0, x>0, x<N-1) ──────────────────
            else if ((id / N) == 0) begin
                out_colours_top[id]    = BOUNDARY;
                out_colours_right[id]  = BORDER;
                out_colours_bottom[id] = INNER_C;
                out_colours_left[id]   = BORDER;
                out_domain_r2[id]      = EDGE_D;
            end
            // ── Right Edge  (x==N-1, y>0, y<N-1) ─────────────
            else if ((id % N) == N-1) begin
                out_colours_top[id]    = BORDER;
                out_colours_right[id]  = BOUNDARY;
                out_colours_bottom[id] = BORDER;
                out_colours_left[id]   = INNER_C;
                out_domain_r3[id]      = EDGE_D;
            end
            // ── Inner variable ─────────────────────────────────
            else begin
                out_colours_top[id]    = INNER_C;
                out_colours_right[id]  = INNER_C;
                out_colours_bottom[id] = INNER_C;
                out_colours_left[id]   = INNER_C;
                out_domain_r0[id]      = INNER_D;
                out_domain_r1[id]      = INNER_D;
                out_domain_r2[id]      = INNER_D;
                out_domain_r3[id]      = INNER_D;
            end

        end
    end

endmodule
