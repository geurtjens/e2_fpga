// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr CData/*4:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__elements__DOT__X;
constexpr CData/*4:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__elements__DOT__A;
constexpr CData/*4:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__elements__DOT__B;
constexpr CData/*4:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__elements__DOT__C;
constexpr CData/*4:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__elements__DOT__D;
constexpr CData/*4:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__BOUNDARY;
constexpr CData/*4:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__BORDER;
constexpr CData/*4:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__INNER_C;
constexpr SData/*8:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__FIXED_CORNER;
constexpr SData/*8:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__FREE_CORNER;
constexpr SData/*8:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__EDGE_D;
constexpr SData/*8:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__INNER_D;
constexpr SData/*8:0*/ Vtop___024root::Brendan3_OneStep__DOT__choose__DOT__NOT_FIRST_COL;
constexpr SData/*8:0*/ Vtop___024root::Brendan3_OneStep__DOT__choose__DOT__NOT_LAST_COL;
constexpr SData/*8:0*/ Vtop___024root::Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__VALID_MASK;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__N;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__V;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__CC;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__N;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__V;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__BORDER_COLOUR_COUNT;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__INNER_COLOUR_COUNT;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__CC;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__elements__DOT__CC;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__elements__DOT__V;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__N;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__V;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__BORDER_COLOUR_COUNT;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__INNER_COLOUR_COUNT;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__CC;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__NUM_EDGES;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__NUM_INNER;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__choose__DOT__N;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__choose__DOT__V;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__N;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__V;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__V;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__V;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__V;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__ID_BITS;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__assign_inst__DOT__N;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__assign_inst__DOT__CC;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__assign_inst__DOT__V;
constexpr IData/*31:0*/ Vtop___024root::Brendan3_OneStep__DOT__assign_inst__DOT__ID_BITS;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
