// ─────────────────────────────────────────────────────────────
// SingletonDetectionOne
//
// Detects whether a domain register contains exactly one bit —
// a "singleton" — meaning only one possibility remains.
//
// This is equivalent to one-hot encoding detection: a value is
// one-hot if and only if exactly one bit is set.
//
// Uses the classic bit trick: x & (x-1) clears the lowest set
// bit. If the result is zero and x is non-zero, exactly one bit
// was set.
//
// Parameters
//   VARIABLES — width of the domain register
//
// Inputs
//   domain — current domain bitmask
//
// Outputs
//   is_singleton — 1 if exactly one bit is set (one-hot)
//                  0 if zero bits or more than one bit is set
// ─────────────────────────────────────────────────────────────
module SingletonDetectionOne #(
    parameter int VARIABLES = 16
)(
    input  logic [VARIABLES-1:0] domain,
    output logic                 is_singleton
);
    assign is_singleton = (domain != '0) && ((domain & (domain - 1)) == '0);

endmodule