set SynModuleInfo {
  {SRCNAME bnn_top_Pipeline_L1_NEURON MODELNAME bnn_top_Pipeline_L1_NEURON RTLNAME bnn_top_bnn_top_Pipeline_L1_NEURON
    SUBMODULES {
      {MODELNAME bnn_top_flow_control_loop_pipe_sequential_init RTLNAME bnn_top_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME bnn_top_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME bnn_top_Pipeline_L2_NEURON MODELNAME bnn_top_Pipeline_L2_NEURON RTLNAME bnn_top_bnn_top_Pipeline_L2_NEURON}
  {SRCNAME bnn_top_Pipeline_L3_NEURON MODELNAME bnn_top_Pipeline_L3_NEURON RTLNAME bnn_top_bnn_top_Pipeline_L3_NEURON}
  {SRCNAME bnn_top_Pipeline_L1_LOAD MODELNAME bnn_top_Pipeline_L1_LOAD RTLNAME bnn_top_bnn_top_Pipeline_L1_LOAD}
  {SRCNAME bnn_top_Pipeline_L2_LOAD MODELNAME bnn_top_Pipeline_L2_LOAD RTLNAME bnn_top_bnn_top_Pipeline_L2_LOAD}
  {SRCNAME bnn_top_Pipeline_L3_LOAD MODELNAME bnn_top_Pipeline_L3_LOAD RTLNAME bnn_top_bnn_top_Pipeline_L3_LOAD}
  {SRCNAME bnn_top MODELNAME bnn_top RTLNAME bnn_top IS_TOP 1
    SUBMODULES {
      {MODELNAME bnn_top_bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l1_weights_1_RAMbkb RTLNAME bnn_top_bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l1_weights_1_RAMbkb BINDTYPE storage TYPE ram_2p IMPL bram LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME bnn_top_bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_1_RAMdEe RTLNAME bnn_top_bnn_top_stream_ap_uint_ap_uint_ap_uint_ap_uint_ap_uint_local_l2_weights_1_RAMdEe BINDTYPE storage TYPE ram_2p IMPL bram LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME bnn_top_local_l3_weights_RAM_2P_BRAM_1R1W RTLNAME bnn_top_local_l3_weights_RAM_2P_BRAM_1R1W BINDTYPE storage TYPE ram_2p IMPL bram LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME bnn_top_l1_output_RAM_AUTO_1R1W RTLNAME bnn_top_l1_output_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME bnn_top_l2_output_RAM_AUTO_1R1W RTLNAME bnn_top_l2_output_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME bnn_top_gmem0_m_axi RTLNAME bnn_top_gmem0_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME bnn_top_gmem1_m_axi RTLNAME bnn_top_gmem1_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME bnn_top_gmem2_m_axi RTLNAME bnn_top_gmem2_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME bnn_top_control_s_axi RTLNAME bnn_top_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
      {MODELNAME bnn_top_regslice_both RTLNAME bnn_top_regslice_both BINDTYPE interface TYPE adapter IMPL reg_slice}
    }
  }
}
