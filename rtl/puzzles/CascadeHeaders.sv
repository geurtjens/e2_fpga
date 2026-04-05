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

module Assignment #(
    parameter int N = 4,     //! puzzle size
    parameter int V = N * N  //! number of variables in the puzzle
)(
    input  logic [$clog2(V)-1:0]  in_variableId, //! variable to be assigned a value
    input  logic [$clog2(V)-1:0]  in_tileId,     //! value being assigned to variable
    input  logic [1:0]            in_rotation,   //! rotation of the tile assigned to variable

    input  logic [V-1:0][V-1:0]   in_domain_r0,  //! original domain rotation 0 (0 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0]   in_domain_r1,  //! original domain rotation 1 (90 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0]   in_domain_r2,  //! original domain rotation 2 (180 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0]   in_domain_r3,  //! original domain rotation 3 (270 degrees), one bit per tile, 1=available, 0=unavailable.

    output logic [V-1:0][V-1:0]   out_domain_r0, //! updated domain rotation 0 (0 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0]   out_domain_r1, //! updated domain rotation 1 (90 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0]   out_domain_r2, //! updated domain rotation 2 (190 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0]   out_domain_r3  //! updated domain rotation 3 (270 degrees), one bit per tile, 1=available, 0=unavailable.
);

module CascadeColour #(
    parameter int N  = 4,     //! Puzzle size
    parameter int CC = 6,     //! Colour count per edge
    parameter int V  = N * N  //! Number of variables — derived from N, do not override
)(
    input  logic [V-1:0][CC-1:0] in_colours_top,    //! top colours for each grid position
    input  logic [V-1:0][CC-1:0] in_colours_right,  //! right colours for each grid position
    input  logic [V-1:0][CC-1:0] in_colours_bottom, //! bottom colours for each grid position
    input  logic [V-1:0][CC-1:0] in_colours_left,   //! left colours for each grid position

    output logic [V-1:0][CC-1:0] out_colours_top,    //! updated top colour for each grid position
    output logic [V-1:0][CC-1:0] out_colours_right,  //! updated right colour for each grid position
    output logic [V-1:0][CC-1:0] out_colours_bottom, //! updated bottom colour for each grid position
    output logic [V-1:0][CC-1:0] out_colours_left,   //! updated left colour for each grid position

    output logic out_deadend, //! HIGH if any cascaded edge becomes empty — no valid colour remains
    output logic out_updated  //! HIGH if any colour changed during cascade
);

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

module DomainToColour #(
    parameter int N  = 4,
    parameter int CC = 6,
    parameter int V  = N * N
)(
    // ── Domain bitmasks ───────────────────────────────────────
    input  logic [V-1:0][V-1:0] in_domain_r0, //! domain bitmask for rotation 0 for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1, //! domain bitmask for rotation 1 for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2, //! domain bitmask for rotation 2 for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3, //! domain bitmask for rotation 3 for each variable.

    // ── Current colour masks ──────────────────────────────────
    input  logic [V-1:0][CC-1:0] in_colours_top,    //! current top colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_right,  //! current right colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_bottom, //! current bottom colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_left,   //! current left colour mask for each variable.

    // ── Tile elements (base orientation, rotation handled internally) ──
    input  logic [V-1:0][CC-1:0] in_elements_top,    //! top colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_right,  //! right colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_bottom, //! bottom colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_left,   //! left colour for each tile in base orientation.

    // ── Derived colour masks ──────────────────────────────────
    output logic [V-1:0][CC-1:0] out_colours_top,    //! derived top colour mask for each variable.
    output logic [V-1:0][CC-1:0] out_colours_right,  //! derived right colour mask for each variable.
    output logic [V-1:0][CC-1:0] out_colours_bottom, //! derived bottom colour mask for each variable.
    output logic [V-1:0][CC-1:0] out_colours_left,   //! derived left colour mask for each variable.

    output logic                 out_changed, //! 1 if any colour changed from input.
    output logic                 out_deadend  //! 1 if any active variable has all-zero colours.
);

module ColourToDomain #(
    parameter int N  = 4,    //! Size of grid.
    parameter int CC = 6,    //! Colour count — number of bits to represent colours.
    parameter int V  = N * N //! Variables in grid — N * N.
)(
    // ── Domain inputs ─────────────────────────────────────────
    input  logic [V-1:0][V-1:0] in_domain_r0,        //! rotation 0 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1,        //! rotation 1 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2,        //! rotation 2 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3,        //! rotation 3 domain bitmask for each variable.

    // ── Colour constraint inputs ───────────────────────────────
    input  logic [V-1:0][CC-1:0] in_colours_top,     //! top colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_right,   //! right colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_bottom,  //! bottom colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_left,    //! left colour mask for each variable.

    // ── Tile elements (base orientation, rotation handled internally) ──
    input  logic [V-1:0][CC-1:0] in_elements_top,    //! top colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_right,  //! right colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_bottom, //! bottom colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_left,   //! left colour for each tile in base orientation.

    // ── Domain outputs ────────────────────────────────────────
    output logic [V-1:0][V-1:0] out_domain_r0,       //! updated rotation 0 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r1,       //! updated rotation 1 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r2,       //! updated rotation 2 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r3,       //! updated rotation 3 domain bitmask for each variable.

    output logic                out_changed,          //! 1 if any domain changed.
    output logic                out_deadend           //! 1 if any variable has an empty domain.
);

module SingletonDetection #(
    parameter int N       = 4,                           //! size of puzzle 3,4,5,6,7,8
    parameter int V       = N * N,                       //! number of positions in the grid.
    parameter int ID_BITS = $clog2(V)                    //! number of bits needed to represent a variable ID e.g. 4 for 16 V
)(
    input  logic [V-1:0]        in_unassignedVariables,  //! original bitmask — one bit per variable, 1=unassigned, 0=already placed (singleton)
    input  logic [V-1:0]        in_unassignedTiles,      //! original V-wide bitmask — one bit per tile, 1=tile not yet placed, 0=tile already use

    input  logic [V-1:0][V-1:0] in_domain_r0,            //! original domain rotation 0 (0 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0] in_domain_r1,            //! original domain rotation 1 (90 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0] in_domain_r2,            //! original domain rotation 2 (180 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0] in_domain_r3,            //! original domain rotation 2 (180 degrees), one bit per tile, 1=available, 0=unavailable.

    output logic [V-1:0]        out_unassignedVariables, //! updated bitmask — one bit per variable, 1=unassigned, 0=already placed (singleton)
    output logic [V-1:0]        out_unassignedTiles,     //! updated V-wide bitmask — one bit per tile, 1=tile not yet placed, 0=tile already use

    output logic [V-1:0][V-1:0] out_domain_r0,           //! updated domain rotation 0 (0 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0] out_domain_r1,           //! updated domain rotation 1 (90 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0] out_domain_r2,           //! updated domain rotation 2 (180 degrees), one bit per tile, 1=available, 0=unavailable. 
    output logic [V-1:0][V-1:0] out_domain_r3,           //! updated domain rotation 2 (180 degrees), one bit per tile, 1=available, 0=unavailable.

    output logic                out_singleton,           //! whether or not a singleton was detected, 1 = singleton was detected
    output logic                out_deadend              //! whether or not a deadend was detected, 1 = deadend was detected
);

module TileFrequency #(
    parameter int N          = 4,          //! int. size of puzzle grid.
    parameter int V          = N * N,      //! int. number of variables in grid (N*N).
    parameter int ITERATIONS = 2           //! int. number of TileFrequencySingle passes to run in series.
)(
    input  logic [V-1:0][V-1:0] in_domain_r0,           //! rotation 0 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1,           //! rotation 1 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2,           //! rotation 2 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3,           //! rotation 3 domain bitmask for each variable.
    input  logic [V-1:0]        in_unassigned_variables, //! bitmask of unassigned variables — 1=unassigned, 0=placed.
    input  logic [V-1:0]        in_unassigned_tiles,     //! bitmask of unassigned tiles — 1=available, 0=already placed.

    output logic [V-1:0][V-1:0] out_domain_r0,          //! updated rotation 0 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r1,          //! updated rotation 1 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r2,          //! updated rotation 2 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r3,          //! updated rotation 3 domain bitmask for each variable.
    output logic                out_deadend              //! 1 if any unassigned tile has no valid variable or popcount mismatch.
);