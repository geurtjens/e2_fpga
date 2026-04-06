// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_COLOURTODOMAINROTATION_H_
#define VERILATED_VTOP_COLOURTODOMAINROTATION_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ColourToDomainRotation final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*5:0*/ top;
    CData/*5:0*/ right;
    CData/*5:0*/ bottom;
    CData/*5:0*/ left;
    VlWide<3>/*95:0*/ p_top;
    VlWide<3>/*95:0*/ p_right;
    VlWide<3>/*95:0*/ p_bottom;
    VlWide<3>/*95:0*/ p_left;
    CData/*0:0*/ changed;
    CData/*0:0*/ deadend;
    SData/*15:0*/ domain;
    SData/*15:0*/ domain_out;
    IData/*31:0*/ unnamedblk1__DOT__p;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ VARIABLES = 0x00000010U;
    static constexpr IData/*31:0*/ TC = 6U;

    // CONSTRUCTORS
    Vtop_ColourToDomainRotation();
    ~Vtop_ColourToDomainRotation();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_ColourToDomainRotation);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
