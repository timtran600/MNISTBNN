# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_control {
input_r { 
	dir I
	width 256
	depth 1
	mode ap_none
	offset 16
	offset_end 51
}
weights { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 52
	offset_end 63
}
load_weights { 
	dir I
	width 1
	depth 1
	mode ap_none
	offset 64
	offset_end 71
}
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
interrupt {
}
}
dict set axilite_register_dict control $port_control


