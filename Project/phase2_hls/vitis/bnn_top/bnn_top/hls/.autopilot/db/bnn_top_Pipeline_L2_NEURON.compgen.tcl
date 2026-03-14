# This script segment is generated automatically by AutoPilot

# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 6 \
    name l2_output_1 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename l2_output_1 \
    op interface \
    ports { l2_output_1_address0 { O 7 vector } l2_output_1_ce0 { O 1 bit } l2_output_1_we0 { O 1 bit } l2_output_1_d0 { O 10 vector } l2_output_1_address1 { O 7 vector } l2_output_1_ce1 { O 1 bit } l2_output_1_we1 { O 1 bit } l2_output_1_d1 { O 10 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'l2_output_1'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 7 \
    name l2_output \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename l2_output \
    op interface \
    ports { l2_output_address0 { O 7 vector } l2_output_ce0 { O 1 bit } l2_output_we0 { O 1 bit } l2_output_d0 { O 10 vector } l2_output_address1 { O 7 vector } l2_output_ce1 { O 1 bit } l2_output_we1 { O 1 bit } l2_output_d1 { O 10 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'l2_output'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 9 \
    name bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_1 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_1 \
    op interface \
    ports { bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_1_address0 { O 7 vector } bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_1_ce0 { O 1 bit } bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_1_q0 { I 256 vector } bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_1_address1 { O 7 vector } bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_1_ce1 { O 1 bit } bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_1_q1 { I 256 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_1'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 10 \
    name bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights \
    op interface \
    ports { bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_address0 { O 7 vector } bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_ce0 { O 1 bit } bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_q0 { I 256 vector } bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_address1 { O 7 vector } bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_ce1 { O 1 bit } bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_q1 { I 256 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 8 \
    name l2_input \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_l2_input \
    op interface \
    ports { l2_input { I 256 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -2 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


# flow_control definition:
set InstName bnn_top_flow_control_loop_pipe_sequential_init_U
set CompName bnn_top_flow_control_loop_pipe_sequential_init
set name flow_control_loop_pipe_sequential_init
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control] == "::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control"} {
eval "::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control { \
    name ${name} \
    prefix bnn_top_ \
}"
} else {
puts "@W \[IMPL-107\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $CompName BINDTYPE interface TYPE internal_upc_flow_control INSTNAME $InstName
}


