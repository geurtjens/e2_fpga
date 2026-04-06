// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_ColourToDomain_Rotation
constexpr IData/*31:0*/ Vtop_ColourToDomain_Rotation::V;
constexpr IData/*31:0*/ Vtop_ColourToDomain_Rotation::CC;


void Vtop_ColourToDomain_Rotation___ctor_var_reset(Vtop_ColourToDomain_Rotation* vlSelf);

Vtop_ColourToDomain_Rotation::Vtop_ColourToDomain_Rotation() = default;
Vtop_ColourToDomain_Rotation::~Vtop_ColourToDomain_Rotation() = default;

void Vtop_ColourToDomain_Rotation::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_ColourToDomain_Rotation___ctor_var_reset(this);
}

void Vtop_ColourToDomain_Rotation::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_ColourToDomain_Rotation::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
