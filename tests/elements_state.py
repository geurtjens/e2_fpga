# elements_state.py
from dataclasses import dataclass
from typing import List
import cocotb
from cocotb.triggers import Timer

@dataclass
class ElementsState:
    CC:              int
    ELEMENTS_TOP:    List[int]
    ELEMENTS_RIGHT:  List[int]
    ELEMENTS_BOTTOM: List[int]
    ELEMENTS_LEFT:   List[int]

    def pack_colour(self, arr: List[int]) -> int:
        """Pack a list of CC-bit colour values into a single wide integer."""
        val = 0
        for i, v in enumerate(arr):
            val |= (v & ((1 << self.CC) - 1)) << (i * self.CC)
        return val



    def _unpack_colour(self, val: int) -> List[int]:
        mask = (1 << self.CC) - 1
        V = len(self.ELEMENTS_TOP)
        return [(val >> (i * self.CC)) & mask for i in range(V)]

    async def assert_dut(self, dut):
        """Compare all DUT element outputs against this ElementsState snapshot."""
        await Timer(1, unit="ns")
        for name, act_raw, exp in [
            ("top",    dut.out_elements_top.value.to_unsigned(),    self.ELEMENTS_TOP),
            ("right",  dut.out_elements_right.value.to_unsigned(),  self.ELEMENTS_RIGHT),
            ("bottom", dut.out_elements_bottom.value.to_unsigned(), self.ELEMENTS_BOTTOM),
            ("left",   dut.out_elements_left.value.to_unsigned(),   self.ELEMENTS_LEFT),
        ]:
            V = len(exp)
            act = self._unpack_colour(act_raw)
            for v in range(V):
                assert act[v] == exp[v], \
                    f"elements_{name}[{v}]={act[v]:#08b} exp={exp[v]:#08b}"
        cocotb.log.info("all elements match ✓")