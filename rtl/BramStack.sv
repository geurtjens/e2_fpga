// ─────────────────────────────────────────────────────────────
// BramStack
//
//! Backtrack stack for the Eternity 2 FPGA solver.
//!
//! Push protocol:
//!   Assert push=1 with din valid for one cycle.
//!   Data is written to stack_ram[depth] on the rising edge.
//!   depth increments on the following cycle.
//!   Do not assert push when full=1.
//!
//! Pop protocol:
//!   Assert pop=1 for one cycle.
//!   dout is valid TWO cycles after pop is asserted:
//!     cycle 0 — pop asserted; read address captured = depth-1;
//!               depth decrements on rising edge
//!     cycle 1 — RAM read issued to captured address; pop_d1 high
//!     cycle 2 — dout valid; valid pulses high; dout held stable
//!   Do not assert pop when empty=1.
//!
//! Read design:
//!   The top-of-stack address (depth-1) is captured combinatorially
//!   at pop time — before the depth counter decrements. This address
//!   is registered into read_addr_r on the pop edge and used to
//!   issue the RAM read on the following cycle (pop_d1). dout is
//!   only updated on pop_d1 cycles, so it stays stable until the
//!   next pop.
//!
//! Frame layout:
//!   [FRAME_BITS-1 : VAR_BITS]   board constraint state
//!   [VAR_BITS-1   : 0]          chosen_var for this depth level
//!
//! CC is puzzle-size dependent — pass the correct value per build:
//!   N=3 → CC=5,  N=4 → CC=6,  N=5 → CC=8
//!   N=6 → CC=9,  N=7 → CC=10, N=8 → CC=12
//!
//! Geometry (N=8, CC=12, STACK_DEPTH=40):
//!   FRAME_BITS = 11008 + 3072 + 128 + 6 = 14214
//!   Total BRAM = 14214 * 40 = 568,560 bits (~56 M10Ks)
//!
//! Geometry (N=4, CC=6, STACK_DEPTH=40):
//!   FRAME_BITS = 448 + 384 + 32 + 4 = 868
//!   Total BRAM = 868 * 40 = 34,720 bits (~4 M10Ks)
// ─────────────────────────────────────────────────────────────
module BramStack #(
    parameter int N           = 8,
    parameter int CC          = 12,
    parameter int STACK_DEPTH = 40
)(
    input  logic                    clk,
    input  logic                    rst,

    input  logic                    push,
    input  logic                    pop,

    input  logic [FRAME_BITS-1:0]   din,
    output logic [FRAME_BITS-1:0]   dout,   //! Valid when valid=1, held stable until next pop

    output logic                    valid,
    output logic                    empty,
    output logic                    full
);

    // ── Geometry ──────────────────────────────────────────────
    localparam int V            = N * N;
    localparam int V_INTERIOR   = (N-2) * (N-2);
    localparam int V_BORDER     = 4 * N - 4;
    localparam int DOMAIN_BITS  = V_INTERIOR * 4 * V
                                + V_BORDER   * 1 * V;
    localparam int COLOUR_BITS  = 4 * V * CC;
    localparam int MASK_BITS    = 2 * V;
    localparam int VAR_BITS     = $clog2(V);
    localparam int FRAME_BITS   = DOMAIN_BITS + COLOUR_BITS + MASK_BITS + VAR_BITS;
    localparam int DEPTH_BITS   = $clog2(STACK_DEPTH + 1);

    // ── Stack RAM ─────────────────────────────────────────────
    logic [FRAME_BITS-1:0] stack_ram [0:STACK_DEPTH-1];

    // ── Depth counter ─────────────────────────────────────────
    logic [DEPTH_BITS-1:0] depth;

    assign empty = (depth == '0);
    assign full  = (depth == DEPTH_BITS'(STACK_DEPTH));

    always_ff @(posedge clk) begin
        if (rst)
            depth <= '0;
        else if (push && !full)
            depth <= depth + 1'b1;
        else if (pop && !empty)
            depth <= depth - 1'b1;
    end

    // ── Write ─────────────────────────────────────────────────
    always_ff @(posedge clk) begin
        if (push && !full)
            stack_ram[depth] <= din;
    end

    // ── Read address capture ───────────────────────────────────
    //! Capture the top-of-stack address (depth-1) combinatorially
    //! at pop time, before depth decrements on the clock edge.
    //! This registered address is used to issue the RAM read
    //! on the following cycle (pop_d1).
    logic [DEPTH_BITS-1:0] read_addr_r;

    always_ff @(posedge clk) begin
        if (pop && !empty)
            read_addr_r <= depth - 1'b1;
    end

    // ── Valid pipeline — two cycle pop latency ─────────────────
    logic pop_d1;

    always_ff @(posedge clk) begin
        if (rst) begin
            pop_d1 <= 1'b0;
            valid  <= 1'b0;
        end else begin
            pop_d1 <= pop && !empty;
            valid  <= pop_d1;
        end
    end

    // ── RAM read — issued on pop_d1 using captured address ────
    //! pop_d1 is high exactly one cycle after pop.
    //! read_addr_r holds the correct top-of-stack address
    //! captured before the depth decrement.
    //! dout is held stable after valid until the next pop.
    always_ff @(posedge clk) begin
        if (pop_d1)
            dout <= stack_ram[read_addr_r];
    end

endmodule
