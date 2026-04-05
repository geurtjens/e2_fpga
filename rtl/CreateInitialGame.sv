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
//   VARIABLES = N * N
//   NUM_EDGES = 4 * (N - 2)
//   NUM_INNER = (N - 2) * (N - 2)
//
// Colour bitmask layout (CC bits wide)
//   bit 0              — boundary colour  (always 0b1)
//   bits 1..BC         — border colours
//   bits BC+1..BC+IC   — inner colours
//
// Domain bitmask layout (VARIABLES bits wide)
//   bits 0..3                 — corner pieces  (4 corners)
//   bits 4..4+NUM_EDGES-1     — edge pieces
//   bits 4+NUM_EDGES..end     — inner pieces
//
// Variable 0 (top-left corner) is the fixed starting placement.
// Its domain is locked to r1=0b0001 only.
// All other corners have domain 0b1110 across all rotations
// meaning any of the 3 remaining corner pieces can be placed
// in any rotation.
// ─────────────────────────────────────────────────────────────
module CreateInitialGame #(
    parameter int N                   = 4, //! Size of grid
    parameter int V                   = N * N, //! Number of variables in grid
    parameter int BORDER_COLOUR_COUNT = 3, //! Number of border colours in the grid, edge and corner colours
    parameter int INNER_COLOUR_COUNT  = 2, //! Number of inner colours in the grid
    parameter int CC                  = 1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT //! total number of colours including the boundary colours
)(
    output logic [V-1:0][CC-1:0]        out_colours_top,         //! top colour for each variable in the grid.
    output logic [V-1:0][CC-1:0]        out_colours_right,       //! right colour for each variable in the grid.
    output logic [V-1:0][CC-1:0]        out_colours_bottom,      //! bottom colour for each variable in the grid.
    output logic [V-1:0][CC-1:0]        out_colours_left,        //! left colour for each variable in the grid.
    output logic [V-1:0][N*N-1:0]       out_domain_r0,           //! rotation 0 bitmask of allowable tiles, for all variables in the grid. 1=tile is available, 0=tile is not available.
    output logic [V-1:0][N*N-1:0]       out_domain_r1,           //! rotation 1 bitmask of allowable tiles, for all variables in the grid. 1=tile is available, 0=tile is not available.
    output logic [V-1:0][N*N-1:0]       out_domain_r2,           //! rotation 2 bitmask of allowable tiles, for all variables in the grid. 1=tile is available, 0=tile is not available.
    output logic [V-1:0][N*N-1:0]       out_domain_r3,           //! rotation 3 bitmask of allowable tiles, for all variables in the grid. 1=tile is available, 0=tile is not available.
    output logic [V-1:0]                out_unassignedVariables, //! available variables, when bit=1 variable position can be used and if bit=0 it cannot.
    output logic [V-1:0]                out_unassignedTiles      //! available tiles, when bit=1 tile can be used and if bit=0 it cannot.
);
    // ── Derived constants ──────────────────────────────────────
    
    localparam int NUM_EDGES = 4 * (N - 2); //! total number of edge variables in the grid
    localparam int NUM_INNER = (N - 2) * (N - 2); //! total number of inner variables in the grid

    // ── Colour masks ───────────────────────────────────────────
    localparam logic [CC-1:0] BOUNDARY = CC'(1); //! grey area, boundary bits where bit 1 is set
    
    //! Set BORDER_COLOUR_COUNT bits to 1, starting at bit position 1" — where bit 0 is the boundary colour (colour 0, the grey edge colour), and border colours start immediately after.
    localparam logic [CC-1:0] BORDER   = CC'({BORDER_COLOUR_COUNT{1'b1}}) << 1;
    
    //! Set INNER_COLOUR_COUNT bits to 1, starting at bit position BORDER_COLOUR_COUNT + 1" — where bit 0 is boundary, bits 1 through BORDER_COLOUR_COUNT are border colours, and inner colours start immediately after.
    localparam logic [CC-1:0] INNER_C  = CC'({INNER_COLOUR_COUNT{1'b1}})
                                         << (BORDER_COLOUR_COUNT + 1);

    // ── Domain masks ───────────────────────────────────────────
    // var 0 is fixed — only corner piece 0, rotation 1
    localparam logic [V-1:0] FIXED_CORNER = V'(1); //! variable 0 is fixed to be tile 0 at rotation 1

    // all other corners — any of the 3 remaining corner pieces,
    // any rotation
    localparam logic [V-1:0] FREE_CORNER  = V'(4'b1110); //! all corner tiles excluding tile 0 which will always be at top left corner

    //! Set NUM_EDGES bits to 1, starting at bit position 4
    localparam logic [V-1:0] EDGE_D = V'({NUM_EDGES{1'b1}}) << 4;

    //! inner pieces occupy bits above the edge domain. Set NUM_INNER bits to 1, starting at bit position 4 + NUM_EDGES" — where bits 0–3 are corners, bits 4 through 4 + NUM_EDGES - 1 are edges, and the inner tile orientations start immediately after.
    localparam logic [V-1:0] INNER_D = V'({NUM_INNER{1'b1}}) << (4 + NUM_EDGES);

    // ── unassigned variables — only variable 0 placed with tile 0 ────────
    assign out_unassignedVariables = ~V'(1);  //! all variables unassigned except var 0 which is fixed.
    assign out_unassignedTiles     = ~V'(1);  //! all tiles unassigned except tile 0 which is placed.
    //! assigns all variables in grid with correct colours and domain depending on where it appears in the grid, that is what type of tile can fit there.
    always_comb begin : set_initial_constraints
        for (int id = 0; id < V; id++) begin

            // defaults
            out_colours_top[id]    = '0;
            out_colours_right[id]  = '0;
            out_colours_bottom[id] = '0;
            out_colours_left[id]   = '0;
            out_domain_r0[id]     = '0;
            out_domain_r1[id]     = '0;
            out_domain_r2[id]     = '0;
            out_domain_r3[id]     = '0;

            // ── Top Left Corner  (x==0, y==0) ─────────────────
            if ((id % N) == 0 && (id / N) == 0) begin
                out_colours_top[id]    = BOUNDARY;
                out_colours_right[id]  = BORDER;
                out_colours_bottom[id] = BORDER;
                out_colours_left[id]   = BOUNDARY;
                out_domain_r1[id]      = FIXED_CORNER;
            end
            // ── Bottom Left Corner  (x==0, y==N-1) ────────────
            else if ((id % N) == 0 && (id / N) == N-1) begin
                out_colours_top[id]    = BORDER;
                out_colours_right[id]  = BORDER;
                out_colours_bottom[id] = BOUNDARY;
                out_colours_left[id]   = BOUNDARY;
                out_domain_r0[id]      = FREE_CORNER;
            end
            // ── Top Right Corner  (x==N-1, y==0) ──────────────
            else if ((id % N) == N-1 && (id / N) == 0) begin
                out_colours_top[id]    = BOUNDARY;
                out_colours_right[id]  = BOUNDARY;
                out_colours_bottom[id] = BORDER;
                out_colours_left[id]   = BORDER;
                out_domain_r2[id]      = FREE_CORNER;
            end
            // ── Bottom Right Corner  (x==N-1, y==N-1) ─────────
            else if ((id % N) == N-1 && (id / N) == N-1) begin
                out_colours_top[id]    = BORDER;
                out_colours_right[id]  = BOUNDARY;
                out_colours_bottom[id] = BOUNDARY;
                out_colours_left[id]   = BORDER;
                out_domain_r3[id]      = FREE_CORNER;
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
