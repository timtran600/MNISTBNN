# This script segment is generated automatically by AutoPilot

if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler bnn_layer1_xnor_local_weights_RAM_2P_BRAM_1R1W BINDTYPE {storage} TYPE {ram_2p} IMPL {bram} LATENCY 2 ALLOW_PRAGMA 1
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler bnn_layer1_xnor_gmem0_m_axi BINDTYPE {interface} TYPE {adapter} IMPL {m_axi}
}


# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

set axilite_register_dict [dict create]
set port_control {
input_r { 
	dir I
	width 784
	depth 1
	mode ap_none
	offset 16
	offset_end 119
}
weights { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 120
	offset_end 131
}
load_weights { 
	dir I
	width 1
	depth 1
	mode ap_none
	offset 132
	offset_end 139
}
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
interrupt {
}
}
dict set axilite_register_dict control $port_control


# Native S_AXILite:
if {${::AESL::PGuard_simmodel_gen}} {
	if {[info proc ::AESL_LIB_XILADAPTER::s_axilite_gen] == "::AESL_LIB_XILADAPTER::s_axilite_gen"} {
		eval "::AESL_LIB_XILADAPTER::s_axilite_gen { \
			id 11 \
			corename bnn_layer1_xnor_control_axilite \
			name bnn_layer1_xnor_control_s_axi \
			ports {$port_control} \
			op interface \
			interrupt_clear_mode TOW \
			interrupt_trigger_type default \
			is_flushable 0 \
			is_datawidth64 0 \
			is_addrwidth64 1 \
		} "
	} else {
		puts "@W \[IMPL-110\] Cannot find AXI Lite interface model in the library. Ignored generation of AXI Lite  interface for 'control'"
	}
}

if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler bnn_layer1_xnor_control_s_axi BINDTYPE interface TYPE interface_s_axilite
}

# Native AXIS:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::native_axis_add] == "::AESL_LIB_XILADAPTER::native_axis_add"} {
eval "::AESL_LIB_XILADAPTER::native_axis_add { \
    id 12 \
    name output_stream_V_data_V \
    reset_level 0 \
    sync_rst true \
    corename {output_stream} \
    metadata {  } \
    op interface \
    ports { output_stream_TDATA { O 16 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'output_stream_V_data_V'"
}
}


# Native AXIS:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::native_axis_add] == "::AESL_LIB_XILADAPTER::native_axis_add"} {
eval "::AESL_LIB_XILADAPTER::native_axis_add { \
    id 13 \
    name output_stream_V_keep_V \
    reset_level 0 \
    sync_rst true \
    corename {output_stream} \
    metadata {  } \
    op interface \
    ports { output_stream_TKEEP { O 2 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'output_stream_V_keep_V'"
}
}


# Native AXIS:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::native_axis_add] == "::AESL_LIB_XILADAPTER::native_axis_add"} {
eval "::AESL_LIB_XILADAPTER::native_axis_add { \
    id 14 \
    name output_stream_V_strb_V \
    reset_level 0 \
    sync_rst true \
    corename {output_stream} \
    metadata {  } \
    op interface \
    ports { output_stream_TSTRB { O 2 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'output_stream_V_strb_V'"
}
}


# Native AXIS:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::native_axis_add] == "::AESL_LIB_XILADAPTER::native_axis_add"} {
eval "::AESL_LIB_XILADAPTER::native_axis_add { \
    id 15 \
    name output_stream_V_last_V \
    reset_level 0 \
    sync_rst true \
    corename {output_stream} \
    metadata {  } \
    op interface \
    ports { output_stream_TVALID { O 1 bit } output_stream_TREADY { I 1 bit } output_stream_TLAST { O 1 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'output_stream_V_last_V'"
}
}



# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -1 \
    name ${PortName} \
    reset_level 0 \
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
set PortName ap_rst_n
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -2 \
    name ${PortName} \
    reset_level 0 \
    sync_rst true \
    corename apif_ap_rst_n \
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


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler bnn_layer1_xnor_regslice_both BINDTYPE {interface} TYPE {adapter} IMPL {reg_slice}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler bnn_layer1_xnor_regslice_both BINDTYPE {interface} TYPE {adapter} IMPL {reg_slice}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler bnn_layer1_xnor_regslice_both BINDTYPE {interface} TYPE {adapter} IMPL {reg_slice}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler bnn_layer1_xnor_regslice_both BINDTYPE {interface} TYPE {adapter} IMPL {reg_slice}
}


