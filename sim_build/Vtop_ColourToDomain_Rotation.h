// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_COLOURTODOMAIN_ROTATION_H_
#define VERILATED_VTOP_COLOURTODOMAIN_ROTATION_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ColourToDomain_Rotation final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*5:0*/ in_colour_top;
    CData/*5:0*/ in_colour_right;
    CData/*5:0*/ in_colour_bottom;
    CData/*5:0*/ in_colour_left;
    VlWide<3>/*95:0*/ in_element_top;
    VlWide<3>/*95:0*/ in_element_right;
    VlWide<3>/*95:0*/ in_element_bottom;
    VlWide<3>/*95:0*/ in_element_left;
    CData/*0:0*/ out_changed;
    CData/*0:0*/ out_deadend;
    SData/*15:0*/ in_domain;
    SData/*15:0*/ out_domain;
    IData/*31:0*/ apply_colour_to_domain_and_detect_change_deadend__DOT__unnamedblk1__DOT__p;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ V = 0x00000010U;
    static constexpr IData/*31:0*/ CC = 6U;

    // CONSTRUCTORS
    Vtop_ColourToDomain_Rotation();
    ~Vtop_ColourToDomain_Rotation();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_ColourToDomain_Rotation);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
