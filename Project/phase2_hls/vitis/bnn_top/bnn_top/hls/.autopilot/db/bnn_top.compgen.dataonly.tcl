# This script segment is generated automatically by AutoPilot

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
l1_weights { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 120
	offset_end 131
}
l2_weights { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 132
	offset_end 143
}
l3_weights { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 144
	offset_end 155
}
load_weights { 
	dir I
	width 1
	depth 1
	mode ap_none
	offset 156
	offset_end 163
}
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
interrupt {
}
}
dict set axilite_register_dict control $port_control


