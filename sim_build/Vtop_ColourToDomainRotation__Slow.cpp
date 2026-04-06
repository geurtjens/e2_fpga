// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_ColourToDomainRotation
constexpr IData/*31:0*/ Vtop_ColourToDomainRotation::VARIABLES;
constexpr IData/*31:0*/ Vtop_ColourToDomainRotation::TC;


void Vtop_ColourToDomainRotation___ctor_var_reset(Vtop_ColourToDomainRotation* vlSelf);

Vtop_ColourToDomainRotation::Vtop_ColourToDomainRotation() = default;
Vtop_ColourToDomainRotation::~Vtop_ColourToDomainRotation() = default;

void Vtop_ColourToDomainRotation::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_ColourToDomainRotation___ctor_var_reset(this);
}

void Vtop_ColourToDomainRotation::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_ColourToDomainRotation::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
