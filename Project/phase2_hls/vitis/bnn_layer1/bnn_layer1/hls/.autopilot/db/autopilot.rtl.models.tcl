set SynModuleInfo {
  {SRCNAME bnn_layer1_xnor MODELNAME bnn_layer1_xnor RTLNAME bnn_layer1_xnor IS_TOP 1
    SUBMODULES {
      {MODELNAME bnn_layer1_xnor_gmem0_m_axi RTLNAME bnn_layer1_xnor_gmem0_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME bnn_layer1_xnor_gmem1_m_axi RTLNAME bnn_layer1_xnor_gmem1_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME bnn_layer1_xnor_control_s_axi RTLNAME bnn_layer1_xnor_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
      {MODELNAME bnn_layer1_xnor_flow_control_loop_pipe RTLNAME bnn_layer1_xnor_flow_control_loop_pipe BINDTYPE interface TYPE internal_upc_flow_control INSTNAME bnn_layer1_xnor_flow_control_loop_pipe_U}
    }
  }
}
