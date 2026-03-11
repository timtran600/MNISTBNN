set SynModuleInfo {
  {SRCNAME bnn_layer1_xnor_Pipeline_NEURON_LOOP MODELNAME bnn_layer1_xnor_Pipeline_NEURON_LOOP RTLNAME bnn_layer1_xnor_bnn_layer1_xnor_Pipeline_NEURON_LOOP
    SUBMODULES {
      {MODELNAME bnn_layer1_xnor_flow_control_loop_pipe_sequential_init RTLNAME bnn_layer1_xnor_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME bnn_layer1_xnor_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME bnn_layer1_xnor_Pipeline_LOAD_LOOP MODELNAME bnn_layer1_xnor_Pipeline_LOAD_LOOP RTLNAME bnn_layer1_xnor_bnn_layer1_xnor_Pipeline_LOAD_LOOP}
  {SRCNAME bnn_layer1_xnor MODELNAME bnn_layer1_xnor RTLNAME bnn_layer1_xnor IS_TOP 1
    SUBMODULES {
      {MODELNAME bnn_layer1_xnor_local_weights_RAM_2P_BRAM_1R1W RTLNAME bnn_layer1_xnor_local_weights_RAM_2P_BRAM_1R1W BINDTYPE storage TYPE ram_2p IMPL bram LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME bnn_layer1_xnor_gmem0_m_axi RTLNAME bnn_layer1_xnor_gmem0_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME bnn_layer1_xnor_gmem1_m_axi RTLNAME bnn_layer1_xnor_gmem1_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME bnn_layer1_xnor_control_s_axi RTLNAME bnn_layer1_xnor_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
