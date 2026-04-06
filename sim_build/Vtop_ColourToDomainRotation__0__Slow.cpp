// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop_ColourToDomainRotation___ctor_var_reset(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->domain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12198183962952742746ull);
    vlSelf->top = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 1104232379953873212ull);
    vlSelf->right = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 14334850655217974033ull);
    vlSelf->bottom = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 13542906285060670858ull);
    vlSelf->left = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 1043389666081855083ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->p_top, __VscopeHash, 14821883457501014298ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->p_right, __VscopeHash, 10138361286897358334ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->p_bottom, __VscopeHash, 16206788058858768251ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->p_left, __VscopeHash, 9882105370183088609ull);
    vlSelf->domain_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13840680035159873280ull);
    vlSelf->changed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11541211202546759773ull);
    vlSelf->deadend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2568607204292324806ull);
    vlSelf->unnamedblk1__DOT__p = 0;
}
