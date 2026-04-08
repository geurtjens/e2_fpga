// ─────────────────────────────────────────────────────────────
// DeadendOrSolutionCheck
//
//! Single combinational check for deadend and solution conditions
//! after all constraint propagation has settled.
//!
//! out_deadend — 1 if any of the following are true:
//!   1. Any unassigned variable has an empty domain across all
//!      four rotations.
//!   2. Two singletons were forced to the same tile — detected
//!      by unassigned variable count != unassigned tile count.
//!   3. Any variable has a blank (all-zero) colour on any edge.
//!
//! out_solution — 1 if all variables are assigned, no deadend,
//!                and no blank colours anywhere.
//!
//! Parameters
//!   N  — board side length (board is N x N)
//!   V  — N * N
//!   CC — colour bits per edge
// ─────────────────────────────────────────────────────────────
module DeadendOrSolutionCheck #(
    parameter int N  = 4,
    parameter int V  = N * N,
    parameter int CC = 6
)(
    // ── Availability masks ────────────────────────────────────
    input  logic [V-1:0] in_unassigned_variables, //! 1=unassigned, 0=placed.
    input  logic [V-1:0] in_unassigned_tiles,     //! 1=available, 0=placed.

    // ── Domain inputs ─────────────────────────────────────────
    input  logic [V-1:0][V-1:0] in_domain_r0, //! rotation 0 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1, //! rotation 1 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2, //! rotation 2 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3, //! rotation 3 domain bitmask for each variable.

    // ── Colour inputs ─────────────────────────────────────────
    input  logic [V-1:0][CC-1:0] in_colours_top,    //! top colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_right,  //! right colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_bottom, //! bottom colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_left,   //! left colour mask for each variable.

    // ── Status outputs ────────────────────────────────────────
    output logic out_deadend,  //! 1 if constraint propagation reached an impossible state.
    output logic out_solution  //! 1 if all variables assigned, no deadend, no blank colours.
);

    // ── Condition 1: empty domain ─────────────────────────────
    //! An unassigned variable with no tiles left in any rotation
    //! is an impossible state.
    logic [V-1:0] v_empty_domain;
    genvar di;
    generate
        for (di = 0; di < V; di++) begin : gen_empty_domain
            assign v_empty_domain[di] =
                in_unassigned_variables[di] &&
                (in_domain_r0[di] | in_domain_r1[di] |
                 in_domain_r2[di] | in_domain_r3[di]) == '0;
        end
    endgenerate

    // ── Condition 2: singleton collision ──────────────────────
    //! If two singletons were forced to the same tile the
    //! unassigned variable count and tile count diverge.
    logic [$clog2(V+1)-1:0] uv_count;
    logic [$clog2(V+1)-1:0] ut_count;
    assign uv_count = $countones(in_unassigned_variables);
    assign ut_count = $countones(in_unassigned_tiles);

    // ── Condition 3: blank colours ────────────────────────────
    //! Any variable with an all-zero colour on any edge is a
    //! deadend — no tile can satisfy that constraint.
    //! Only checked for unassigned variables since assigned
    //! variables have their colours locked to a single tile.
    logic [V-1:0] v_blank_colour;
    genvar bi;
    generate
        for (bi = 0; bi < V; bi++) begin : gen_blank_colour
            assign v_blank_colour[bi] =
                in_unassigned_variables[bi] && (
                    in_colours_top[bi]    == '0 ||
                    in_colours_right[bi]  == '0 ||
                    in_colours_bottom[bi] == '0 ||
                    in_colours_left[bi]   == '0
                );
        end
    endgenerate

    // ── Deadend and solution ──────────────────────────────────
    assign out_deadend  = |v_empty_domain ||
                          (uv_count != ut_count) ||
                          |v_blank_colour;

    assign out_solution = (in_unassigned_variables == '0) && !out_deadend;

endmodule
