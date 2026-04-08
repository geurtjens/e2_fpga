# grid_state.py
# Dataclass representing a complete solver state snapshot.
# Used to compare FPGA outputs against C++ reference data.

from dataclasses import dataclass
from typing import List
import cocotb
from cocotb.triggers import Timer

@dataclass
class GridState:
    N:                    int
    V:                    int
    CC:                   int
    UNASSIGNED_VARIABLES: int
    UNASSIGNED_TILES:     int
    R0:                   List[int]
    R1:                   List[int]
    R2:                   List[int]
    R3:                   List[int]
    TOP:                  List[int]
    RIGHT:                List[int]
    BOTTOM:               List[int]
    LEFT:                 List[int]
    VARIABLE_TO_ASSIGN:   int  = 0
    TILE_TO_ASSIGN:       int  = 0
    ROTATION_TO_ASSIGN:   int  = 0
    DEADEND:              bool = False
    UPDATED:              bool = False

    def pack_colour(self, arr: List[int]) -> int:
        """Pack a list of CC-bit colour values into a single wide integer."""
        val = 0
        for i, v in enumerate(arr):
            val |= (v & ((1 << self.CC) - 1)) << (i * self.CC)
        return val

    def pack_domain(self, arr: List[int]) -> int:
        """Pack a list of V-bit domain values into a single wide integer."""
        val = 0
        for i, d in enumerate(arr):
            val |= (d & ((1 << self.V) - 1)) << (i * self.V)
        return val

    def _unpack_domain(self, val: int) -> List[int]:
        """Unpack a packed [V-1:0][V-1:0] domain array into a list of V ints."""
        mask = (1 << self.V) - 1
        return [(val >> (i * self.V)) & mask for i in range(self.V)]

    def _unpack_colour(self, val: int) -> List[int]:
        """Unpack a packed [V-1:0][CC-1:0] colour array into a list of V ints."""
        mask = (1 << self.CC) - 1
        return [(val >> (i * self.CC)) & mask for i in range(self.V)]

    # ── Print helpers ─────────────────────────────────────────

    def print_colours(self, label: str, top: list, right: list,
                      bottom: list, left: list, highlight: int = -1):
        """Print a colour array snapshot with a label and optional highlighted variable."""
        cocotb.log.info(f"── {label} ───────────────────────────────────────")
        for v in range(self.V):
            marker = " ◄" if v == highlight else ""
            cocotb.log.info(
                f"  var={v}  "
                f"top={top[v]:0{self.CC}b}  "
                f"right={right[v]:0{self.CC}b}  "
                f"bottom={bottom[v]:0{self.CC}b}  "
                f"left={left[v]:0{self.CC}b}"
                f"{marker}"
            )

    def print_dut_colours(self, label: str, dut, highlight: int = -1):
        """Unpack and print the DUT's current colour outputs."""
        top    = self._unpack_colour(dut.out_colours_top.value.to_unsigned())
        right  = self._unpack_colour(dut.out_colours_right.value.to_unsigned())
        bottom = self._unpack_colour(dut.out_colours_bottom.value.to_unsigned())
        left   = self._unpack_colour(dut.out_colours_left.value.to_unsigned())
        self.print_colours(label, top, right, bottom, left, highlight)

    def print_expected_colours(self, label: str, highlight: int = -1):
        """Print this GridState's own colour arrays as expected values."""
        self.print_colours(label, self.TOP, self.RIGHT,
                           self.BOTTOM, self.LEFT, highlight)

    def print_colour_comparison(self, label: str, dut, highlight: int = -1):
        """Print DUT vs expected colours side by side with a match indicator."""
        cocotb.log.info(f"── {label} ───────────────────────────────────────")
        top    = self._unpack_colour(dut.out_colours_top.value.to_unsigned())
        right  = self._unpack_colour(dut.out_colours_right.value.to_unsigned())
        bottom = self._unpack_colour(dut.out_colours_bottom.value.to_unsigned())
        left   = self._unpack_colour(dut.out_colours_left.value.to_unsigned())
        for v in range(self.V):
            marker = " ◄" if v == highlight else ""
            for name, act, exp in [
                ("top",    top[v],    self.TOP[v]),
                ("right",  right[v],  self.RIGHT[v]),
                ("bottom", bottom[v], self.BOTTOM[v]),
                ("left",   left[v],   self.LEFT[v]),
            ]:
                match = "✓" if act == exp else "✗"
                cocotb.log.info(
                    f"  {match} var={v} {name:6} "
                    f"DUT={act:0{self.CC}b}  "
                    f"EXP={exp:0{self.CC}b}"
                    f"{marker}"
                )

    def print_domains(self, label: str, r0: list, r1: list,
                      r2: list, r3: list, highlight: int = -1):
        """Print a domain array snapshot with a label and optional highlighted variable."""
        cocotb.log.info(f"── {label} ───────────────────────────────────────")
        for v in range(self.V):
            marker = " ◄" if v == highlight else ""
            cocotb.log.info(
                f"  var={v}  "
                f"r0={r0[v]:0{self.V}b}  "
                f"r1={r1[v]:0{self.V}b}  "
                f"r2={r2[v]:0{self.V}b}  "
                f"r3={r3[v]:0{self.V}b}"
                f"{marker}"
            )

    def print_dut_domains(self, label: str, dut, highlight: int = -1):
        """Unpack and print the DUT's current domain outputs."""
        r0 = self._unpack_domain(dut.out_domain_r0.value.to_unsigned())
        r1 = self._unpack_domain(dut.out_domain_r1.value.to_unsigned())
        r2 = self._unpack_domain(dut.out_domain_r2.value.to_unsigned())
        r3 = self._unpack_domain(dut.out_domain_r3.value.to_unsigned())
        self.print_domains(label, r0, r1, r2, r3, highlight)

    def print_expected_domains(self, label: str, highlight: int = -1):
        """Print this GridState's own domain arrays as expected values."""
        self.print_domains(label, self.R0, self.R1,
                           self.R2, self.R3, highlight)

    def print_domain_comparison(self, label: str, dut, highlight: int = -1):
        """Print DUT vs expected domains side by side with a match indicator."""
        cocotb.log.info(f"── {label} ───────────────────────────────────────")
        r0 = self._unpack_domain(dut.out_domain_r0.value.to_unsigned())
        r1 = self._unpack_domain(dut.out_domain_r1.value.to_unsigned())
        r2 = self._unpack_domain(dut.out_domain_r2.value.to_unsigned())
        r3 = self._unpack_domain(dut.out_domain_r3.value.to_unsigned())
        for v in range(self.V):
            marker = " ◄" if v == highlight else ""
            for rname, act, exp in [
                ("r0", r0[v], self.R0[v]),
                ("r1", r1[v], self.R1[v]),
                ("r2", r2[v], self.R2[v]),
                ("r3", r3[v], self.R3[v]),
            ]:
                match = "✓" if act == exp else "✗"
                cocotb.log.info(
                    f"  {match} var={v} {rname} "
                    f"DUT={act:0{self.V}b}  "
                    f"EXP={exp:0{self.V}b}"
                    f"{marker}"
                )

    # ── Assertion ─────────────────────────────────────────────

    async def assert_dut(self, dut):
        """Compare all DUT outputs against this GridState snapshot."""
        await Timer(1, unit="ns")

        # ── Availability masks ─────────────────────────────
        act_uv = int(dut.out_unassigned_variables.value)
        act_ut = int(dut.out_unassigned_tiles.value)
        assert act_uv == self.UNASSIGNED_VARIABLES, \
            f"unassigned_variables={act_uv:#018b} exp={self.UNASSIGNED_VARIABLES:#018b}"
        assert act_ut == self.UNASSIGNED_TILES, \
            f"unassigned_tiles={act_ut:#018b} exp={self.UNASSIGNED_TILES:#018b}"
        cocotb.log.info("unassigned masks match ✓")

        # ── Domains ───────────────────────────────────────
        for name, act_raw, exp in [
            ("r0", dut.out_domain_r0.value.to_unsigned(), self.R0),
            ("r1", dut.out_domain_r1.value.to_unsigned(), self.R1),
            ("r2", dut.out_domain_r2.value.to_unsigned(), self.R2),
            ("r3", dut.out_domain_r3.value.to_unsigned(), self.R3),
        ]:
            act = self._unpack_domain(act_raw)
            for v in range(self.V):
                assert act[v] == exp[v], \
                    f"domain_{name}[{v}]={act[v]:#018b} exp={exp[v]:#018b}"
        cocotb.log.info("all domains match ✓")

        # ── Colours ───────────────────────────────────────
        for name, act_raw, exp in [
            ("top",    dut.out_colours_top.value.to_unsigned(),    self.TOP),
            ("right",  dut.out_colours_right.value.to_unsigned(),  self.RIGHT),
            ("bottom", dut.out_colours_bottom.value.to_unsigned(), self.BOTTOM),
            ("left",   dut.out_colours_left.value.to_unsigned(),   self.LEFT),
        ]:
            act = self._unpack_colour(act_raw)
            for v in range(self.V):
                assert act[v] == exp[v], \
                    f"colours_{name}[{v}]={act[v]:#08b} exp={exp[v]:#08b}"
        cocotb.log.info("all colours match ✓")