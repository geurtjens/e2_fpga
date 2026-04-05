// ─────────────────────────────────────────────────────────────
// PropagateOnce
//
//! Runs one full pass of constraint propagation in series:
//!
//!   1. DomainToColour     — derive colour masks from domains
//!   2. CascadeColour      — propagate colours across neighbours
//!   3. ColourToDomain     — filter domains using colour masks
//!   4. AllDifferent       — remove tiles violating all-different
//!   5. TileFrequency      — force tiles with only one valid variable
//!   6. SingletonDetection — lock variables with only one tile left
//!
//! Pure combinational — no clock required.
//! The clocked state machine above decides whether to loop again
//! based on out_changed, or stop on out_deadend.
//!
//! out_changed — 1 if any stage changed any domain or colour
//! out_deadend — 1 if any stage detected an impossible state
// ─────────────────────────────────────────────────────────────
module PropagateOnce #(
    parameter int N  = 4,     //! int. size of puzzle grid.
    parameter int V  = N * N, //! int. number of variables in grid (N*N).
    parameter int CC = 6      //! int. total colour count.
)(
    // ── Tile elements ─────────────────────────────────────────
    input  logic [V-1:0][CC-1:0] in_elements_top,    //! top colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_right,  //! right colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_bottom, //! bottom colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_left,   //! left colour for each tile in base orientation.

    // ── Domain inputs ─────────────────────────────────────────
    input  logic [V-1:0][V-1:0] in_domain_r0,        //! rotation 0 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1,        //! rotation 1 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2,        //! rotation 2 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3,        //! rotation 3 domain bitmask for each variable.

    // ── Colour inputs ─────────────────────────────────────────
    input  logic [V-1:0][CC-1:0] in_colours_top,     //! current top colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_right,   //! current right colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_bottom,  //! current bottom colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_left,    //! current left colour mask for each variable.

    // ── Availability masks ────────────────────────────────────
    input  logic [V-1:0]         in_unassigned_variables, //! bitmask of unassigned variables — 1=unassigned, 0=placed.
    input  logic [V-1:0]         in_unassigned_tiles,     //! bitmask of unassigned tiles — 1=available, 0=placed.

    // ── Domain outputs ────────────────────────────────────────
    output logic [V-1:0][V-1:0] out_domain_r0,       //! updated rotation 0 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r1,       //! updated rotation 1 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r2,       //! updated rotation 2 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r3,       //! updated rotation 3 domain bitmask for each variable.

    // ── Colour outputs ────────────────────────────────────────
    output logic [V-1:0][CC-1:0] out_colours_top,    //! updated top colour mask for each variable.
    output logic [V-1:0][CC-1:0] out_colours_right,  //! updated right colour mask for each variable.
    output logic [V-1:0][CC-1:0] out_colours_bottom, //! updated bottom colour mask for each variable.
    output logic [V-1:0][CC-1:0] out_colours_left,   //! updated left colour mask for each variable.

    // ── Availability mask outputs ─────────────────────────────
    output logic [V-1:0]         out_unassigned_variables, //! updated unassigned variables bitmask.
    output logic [V-1:0]         out_unassigned_tiles,     //! updated unassigned tiles bitmask.

    // ── Status ────────────────────────────────────────────────
    output logic                 out_changed, //! 1 if any stage changed any domain or colour.
    output logic                 out_deadend  //! 1 if any stage detected an impossible state.
);

    // ── Stage 1 → 2 wires ─────────────────────────────────────
    logic [V-1:0][CC-1:0] w1_colours_top;    //! colours after DomainToColour.
    logic [V-1:0][CC-1:0] w1_colours_right;
    logic [V-1:0][CC-1:0] w1_colours_bottom;
    logic [V-1:0][CC-1:0] w1_colours_left;
    logic                 w1_changed;        //! DomainToColour changed flag.
    logic                 w1_deadend;        //! DomainToColour deadend flag.

    // ── Stage 2 → 3 wires ─────────────────────────────────────
    logic [V-1:0][CC-1:0] w2_colours_top;    //! colours after CascadeColour.
    logic [V-1:0][CC-1:0] w2_colours_right;
    logic [V-1:0][CC-1:0] w2_colours_bottom;
    logic [V-1:0][CC-1:0] w2_colours_left;
    logic                 w2_updated;        //! CascadeColour updated flag.
    logic                 w2_deadend;        //! CascadeColour deadend flag.

    // ── Stage 3 → 4 wires ─────────────────────────────────────
    logic [V-1:0][V-1:0] w3_domain_r0;      //! domains after ColourToDomain.
    logic [V-1:0][V-1:0] w3_domain_r1;
    logic [V-1:0][V-1:0] w3_domain_r2;
    logic [V-1:0][V-1:0] w3_domain_r3;
    logic                w3_changed;         //! ColourToDomain changed flag.
    logic                w3_deadend;         //! ColourToDomain deadend flag.

    // ── Stage 4 → 5 wires ─────────────────────────────────────
    logic [V-1:0][V-1:0] w4_domain_r0;      //! domains after AllDifferent.
    logic [V-1:0][V-1:0] w4_domain_r1;
    logic [V-1:0][V-1:0] w4_domain_r2;
    logic [V-1:0][V-1:0] w4_domain_r3;
    logic                w4_changed;         //! AllDifferent changed flag.
    logic                w4_deadend;         //! AllDifferent deadend flag.

    // ── Stage 5 → 6 wires ─────────────────────────────────────
    logic [V-1:0][V-1:0] w5_domain_r0;      //! domains after TileFrequency.
    logic [V-1:0][V-1:0] w5_domain_r1;
    logic [V-1:0][V-1:0] w5_domain_r2;
    logic [V-1:0][V-1:0] w5_domain_r3;
    logic                w5_deadend;         //! TileFrequency deadend flag.

    // ── Stage 1: DomainToColour ───────────────────────────────
    //! Derives colour masks from the current domain bitmasks.
    //! For each variable, ORs the colours of all tiles still in
    //! its domain across all valid rotations.
    DomainToColour #(.N(N), .CC(CC)) stage1_domain_to_colour (
        .in_domain_r0      (in_domain_r0),
        .in_domain_r1      (in_domain_r1),
        .in_domain_r2      (in_domain_r2),
        .in_domain_r3      (in_domain_r3),
        .in_colours_top    (in_colours_top),
        .in_colours_right  (in_colours_right),
        .in_colours_bottom (in_colours_bottom),
        .in_colours_left   (in_colours_left),
        .in_elements_top   (in_elements_top),
        .in_elements_right (in_elements_right),
        .in_elements_bottom(in_elements_bottom),
        .in_elements_left  (in_elements_left),
        .out_colours_top   (w1_colours_top),
        .out_colours_right (w1_colours_right),
        .out_colours_bottom(w1_colours_bottom),
        .out_colours_left  (w1_colours_left),
        .out_changed       (w1_changed),
        .out_deadend       (w1_deadend)
    );

    // ── Stage 2: CascadeColour ────────────────────────────────
    //! Propagates colour constraints across neighbouring variables.
    //! ANDs shared edges so adjacent variables agree on what
    //! colours are possible between them.
    CascadeColour #(.N(N), .CC(CC)) stage2_cascade_colour (
        .in_colours_top    (w1_colours_top),
        .in_colours_right  (w1_colours_right),
        .in_colours_bottom (w1_colours_bottom),
        .in_colours_left   (w1_colours_left),
        .out_colours_top   (w2_colours_top),
        .out_colours_right (w2_colours_right),
        .out_colours_bottom(w2_colours_bottom),
        .out_colours_left  (w2_colours_left),
        .out_deadend       (w2_deadend),
        .out_updated       (w2_updated)
    );

    // ── Stage 3: ColourToDomain ───────────────────────────────
    //! Filters each variable's domain by checking each tile's
    //! colours against the cascaded colour constraints.
    //! Tiles whose colours don't match the constraints are removed.
    ColourToDomain #(.N(N), .CC(CC)) stage3_colour_to_domain (
        .in_domain_r0      (in_domain_r0),
        .in_domain_r1      (in_domain_r1),
        .in_domain_r2      (in_domain_r2),
        .in_domain_r3      (in_domain_r3),
        .in_colours_top    (w2_colours_top),
        .in_colours_right  (w2_colours_right),
        .in_colours_bottom (w2_colours_bottom),
        .in_colours_left   (w2_colours_left),
        .in_elements_top   (in_elements_top),
        .in_elements_right (in_elements_right),
        .in_elements_bottom(in_elements_bottom),
        .in_elements_left  (in_elements_left),
        .out_domain_r0     (w3_domain_r0),
        .out_domain_r1     (w3_domain_r1),
        .out_domain_r2     (w3_domain_r2),
        .out_domain_r3     (w3_domain_r3),
        .out_changed       (w3_changed),
        .out_deadend       (w3_deadend)
    );

    // ── Stage 4: AllDifferent ─────────────────────────────────
    //! Enforces the all-different constraint — no two variables
    //! can be assigned the same tile. Removes tiles from domains
    //! that would violate this constraint using Hall set detection.
    AllDifferent #(.N(N)) stage4_all_different (
        .in_domain_r0          (w3_domain_r0),
        .in_domain_r1          (w3_domain_r1),
        .in_domain_r2          (w3_domain_r2),
        .in_domain_r3          (w3_domain_r3),
        .in_unassignedVariables(in_unassigned_variables),
        .in_unassignedTiles    (in_unassigned_tiles),
        .out_domain_r0         (w4_domain_r0),
        .out_domain_r1         (w4_domain_r1),
        .out_domain_r2         (w4_domain_r2),
        .out_domain_r3         (w4_domain_r3),
        .out_changed           (w4_changed),
        .out_deadend           (w4_deadend)
    );

    // ── Stage 5: TileFrequency ────────────────────────────────
    //! Forces any tile that can only fit in one remaining variable
    //! into that variable's domain, eliminating all other tiles
    //! from that variable. Runs multiple passes internally.
    TileFrequency #(.N(N)) stage5_tile_frequency (
        .in_domain_r0           (w4_domain_r0),
        .in_domain_r1           (w4_domain_r1),
        .in_domain_r2           (w4_domain_r2),
        .in_domain_r3           (w4_domain_r3),
        .in_unassigned_variables(in_unassigned_variables),
        .in_unassigned_tiles    (in_unassigned_tiles),
        .out_domain_r0          (w5_domain_r0),
        .out_domain_r1          (w5_domain_r1),
        .out_domain_r2          (w5_domain_r2),
        .out_domain_r3          (w5_domain_r3),
        .out_deadend            (w5_deadend)
    );

    // ── Stage 6: SingletonDetection ──────────────────────────
    //! Detects variables whose domain has collapsed to a single
    //! tile in a single rotation, locks them as placed, and
    //! removes the tile from all other variables' domains.
    SingletonDetection #(.N(N)) stage6_singleton_detection (
        .in_unassignedVariables (in_unassigned_variables),
        .in_unassignedTiles     (in_unassigned_tiles),
        .in_domain_r0           (w5_domain_r0),
        .in_domain_r1           (w5_domain_r1),
        .in_domain_r2           (w5_domain_r2),
        .in_domain_r3           (w5_domain_r3),
        .out_unassignedVariables(out_unassigned_variables),
        .out_unassignedTiles    (out_unassigned_tiles),
        .out_domain_r0          (out_domain_r0),
        .out_domain_r1          (out_domain_r1),
        .out_domain_r2          (out_domain_r2),
        .out_domain_r3          (out_domain_r3),
        .out_singleton          (),  // absorbed into out_changed below
        .out_deadend            (w6_deadend)
    );

    // ── Colour outputs come from stage 2 ─────────────────────
    //! Colours are finalised after CascadeColour and do not
    //! change in subsequent stages.
    assign out_colours_top    = w2_colours_top;
    assign out_colours_right  = w2_colours_right;
    assign out_colours_bottom = w2_colours_bottom;
    assign out_colours_left   = w2_colours_left;

    // ── Status outputs ────────────────────────────────────────
    //! out_changed is the OR of all stage changed/updated flags
    //! plus singleton detection (a singleton is always a change).
    logic w6_deadend;     //! SingletonDetection deadend flag.
    logic w6_singleton;   //! SingletonDetection singleton flag.

    assign out_changed = w1_changed  |
                         w2_updated  |
                         w3_changed  |
                         w4_changed  |
                         w6_singleton;

    assign out_deadend = w1_deadend  |
                         w2_deadend  |
                         w3_deadend  |
                         w4_deadend  |
                         w5_deadend  |
                         w6_deadend;

endmodule
