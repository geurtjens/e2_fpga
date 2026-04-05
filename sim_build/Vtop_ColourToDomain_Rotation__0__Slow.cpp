// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop_ColourToDomain_Rotation___ctor_var_reset(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->in_domain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10371183289324151927ull);
    vlSelf->in_colour_top = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 10040419684351975175ull);
    vlSelf->in_colour_right = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 1476303710547307584ull);
    vlSelf->in_colour_bottom = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 3103913820044973116ull);
    vlSelf->in_colour_left = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 12209637401904934015ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->in_element_top, __VscopeHash, 8982849305944971701ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->in_element_right, __VscopeHash, 16439574472073960431ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->in_element_bottom, __VscopeHash, 6363838393743466529ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->in_element_left, __VscopeHash, 2977949892661074883ull);
    vlSelf->out_domain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5197531358171655438ull);
    vlSelf->out_changed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8844864791567013543ull);
    vlSelf->out_deadend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7493292469854410692ull);
    vlSelf->apply_colour_to_domain_and_detect_change_deadend__DOT__unnamedblk1__DOT__p = 0;
}
