; ModuleID = 'C:/GitRepos/EECE4632/Project/phase2_hls/vitis/bnn_layer2_Stream_BRAM/bnn_layer2_Stream_BRAM/hls/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>" = type { %"struct.hls::axis<ap_uint<16>, 0, 0, 0, '8', false>" }
%"struct.hls::axis<ap_uint<16>, 0, 0, 0, '8', false>" = type { %"struct.ap_uint<16>", %"struct.ap_uint<2>", %"struct.ap_uint<2>", %"struct.hls::axis_disabled_signal", %"struct.ap_uint<1>", %"struct.hls::axis_disabled_signal", %"struct.hls::axis_disabled_signal" }
%"struct.ap_uint<16>" = type { %"struct.ap_int_base<16, false>" }
%"struct.ap_int_base<16, false>" = type { %"struct.ssdm_int<16, false>" }
%"struct.ssdm_int<16, false>" = type { i16 }
%"struct.ap_uint<2>" = type { %"struct.ap_int_base<2, false>" }
%"struct.ap_int_base<2, false>" = type { %"struct.ssdm_int<2, false>" }
%"struct.ssdm_int<2, false>" = type { i2 }
%"struct.ap_uint<1>" = type { %"struct.ap_int_base<1, false>" }
%"struct.ap_int_base<1, false>" = type { %"struct.ssdm_int<1, false>" }
%"struct.ssdm_int<1, false>" = type { i1 }
%"struct.hls::axis_disabled_signal" = type { i8 }
%"struct.ap_uint<256>" = type { %"struct.ap_int_base<256, false>" }
%"struct.ap_int_base<256, false>" = type { %"struct.ssdm_int<256, false>" }
%"struct.ssdm_int<256, false>" = type { i256 }

; Function Attrs: noinline
define void @apatb_bnn_layer2_xnor_ir(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* noalias nonnull dereferenceable(8) %output_stream, %"struct.ap_uint<256>"* nocapture readonly %input, %"struct.ap_uint<256>"* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="256" "maxi" %weights, %"struct.ap_uint<1>"* nocapture readonly %load_weights) local_unnamed_addr #0 {
entry:
  %output_stream_copy.data = alloca i16, align 512
  %output_stream_copy.keep = alloca i2, align 512
  %output_stream_copy.strb = alloca i2, align 512
  %output_stream_copy.last = alloca i1, align 512
  %malloccall = call i8* @malloc(i64 8192)
  %weights_copy = bitcast i8* %malloccall to [256 x i256]*
  %0 = bitcast %"struct.ap_uint<256>"* %weights to [256 x %"struct.ap_uint<256>"]*
  call fastcc void @copy_in(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* nonnull %output_stream, i16* nonnull align 512 %output_stream_copy.data, i2* nonnull align 512 %output_stream_copy.keep, i2* nonnull align 512 %output_stream_copy.strb, i1* nonnull align 512 %output_stream_copy.last, [256 x %"struct.ap_uint<256>"]* nonnull %0, [256 x i256]* %weights_copy)
  call void @apatb_bnn_layer2_xnor_hw(i16* %output_stream_copy.data, i2* %output_stream_copy.keep, i2* %output_stream_copy.strb, i1* %output_stream_copy.last, %"struct.ap_uint<256>"* %input, [256 x i256]* %weights_copy, %"struct.ap_uint<1>"* %load_weights)
  call void @copy_back(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %output_stream, i16* %output_stream_copy.data, i2* %output_stream_copy.keep, i2* %output_stream_copy.strb, i1* %output_stream_copy.last, [256 x %"struct.ap_uint<256>"]* %0, [256 x i256]* %weights_copy)
  call void @free(i8* %malloccall)
  ret void
}

declare noalias i8* @malloc(i64) local_unnamed_addr

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @copy_in(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* noalias "unpacked"="0", i16* noalias align 512 "unpacked"="1.0" %_V_data_V, i2* noalias align 512 "unpacked"="1.1" %_V_keep_V, i2* noalias align 512 "unpacked"="1.2" %_V_strb_V, i1* noalias align 512 "unpacked"="1.3" %_V_last_V, [256 x %"struct.ap_uint<256>"]* noalias readonly "unpacked"="2", [256 x i256]* noalias nocapture "unpacked"="3.0") unnamed_addr #1 {
entry:
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>.18"(i16* align 512 %_V_data_V, i2* align 512 %_V_keep_V, i2* align 512 %_V_strb_V, i1* align 512 %_V_last_V, %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %0)
  call fastcc void @"onebyonecpy_hls.p0a256struct.ap_uint<256>"([256 x i256]* %2, [256 x %"struct.ap_uint<256>"]* %1)
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* noalias %dst, i16* noalias align 512 "unpacked"="1.0" %src_V_data_V, i2* noalias align 512 "unpacked"="1.1" %src_V_keep_V, i2* noalias align 512 "unpacked"="1.2" %src_V_strb_V, i1* noalias align 512 "unpacked"="1.3" %src_V_last_V) unnamed_addr #2 {
entry:
  %0 = icmp eq %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* nonnull %dst, i16* align 512 %src_V_data_V, i2* align 512 %src_V_keep_V, i2* align 512 %src_V_strb_V, i1* align 512 %src_V_last_V)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* noalias nocapture, i16* noalias nocapture align 512 "unpacked"="1.0" %_V_data_V, i2* noalias nocapture align 512 "unpacked"="1.1" %_V_keep_V, i2* noalias nocapture align 512 "unpacked"="1.2" %_V_strb_V, i1* noalias nocapture align 512 "unpacked"="1.3" %_V_last_V) unnamed_addr #3 {
entry:
  %1 = alloca i16
  %2 = alloca i2
  %3 = alloca i2
  %4 = alloca i1
  %5 = alloca %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"
  br label %empty

empty:                                            ; preds = %push, %entry
  %6 = bitcast i16* %_V_data_V to i8*
  %7 = call i1 @fpga_fifo_not_empty_2(i8* %6)
  br i1 %7, label %push, label %ret

push:                                             ; preds = %empty
  %8 = bitcast i16* %1 to i8*
  %9 = bitcast i16* %_V_data_V to i8*
  call void @fpga_fifo_pop_2(i8* %8, i8* %9)
  %10 = load volatile i16, i16* %1
  %11 = bitcast i2* %3 to i8*
  %12 = bitcast i2* %_V_keep_V to i8*
  call void @fpga_fifo_pop_1(i8* %11, i8* %12)
  %13 = bitcast i2* %3 to i8*
  %14 = load i8, i8* %13
  %15 = trunc i8 %14 to i2
  %16 = bitcast i2* %2 to i8*
  %17 = bitcast i2* %_V_strb_V to i8*
  call void @fpga_fifo_pop_1(i8* %16, i8* %17)
  %18 = bitcast i2* %2 to i8*
  %19 = load i8, i8* %18
  %20 = trunc i8 %19 to i2
  %21 = bitcast i1* %4 to i8*
  %22 = bitcast i1* %_V_last_V to i8*
  call void @fpga_fifo_pop_1(i8* %21, i8* %22)
  %23 = bitcast i1* %4 to i8*
  %24 = load i8, i8* %23
  %25 = trunc i8 %24 to i1
  %.fca.0.0.0.0.0.insert = insertvalue %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>" undef, i16 %10, 0, 0, 0, 0, 0
  %.fca.0.1.0.0.0.insert = insertvalue %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>" %.fca.0.0.0.0.0.insert, i2 %15, 0, 1, 0, 0, 0
  %.fca.0.2.0.0.0.insert = insertvalue %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>" %.fca.0.1.0.0.0.insert, i2 %20, 0, 2, 0, 0, 0
  %.fca.0.4.0.0.0.insert = insertvalue %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>" %.fca.0.2.0.0.0.insert, i1 %25, 0, 4, 0, 0, 0
  store %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>" %.fca.0.4.0.0.0.insert, %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %5
  %26 = bitcast %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %5 to i8*
  %27 = bitcast %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %0 to i8*
  call void @fpga_fifo_push_8(i8* %26, i8* %27)
  br label %empty, !llvm.loop !5

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @"onebyonecpy_hls.p0a256struct.ap_uint<256>"([256 x i256]* noalias nocapture "unpacked"="0.0" %dst, [256 x %"struct.ap_uint<256>"]* noalias readonly "unpacked"="1" %src) unnamed_addr #4 {
entry:
  %0 = icmp eq [256 x %"struct.ap_uint<256>"]* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @"arraycpy_hls.p0a256struct.ap_uint<256>"([256 x i256]* %dst, [256 x %"struct.ap_uint<256>"]* nonnull %src, i64 256)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @"arraycpy_hls.p0a256struct.ap_uint<256>"([256 x i256]* nocapture "unpacked"="0.0" %dst, [256 x %"struct.ap_uint<256>"]* readonly "unpacked"="1" %src, i64 "unpacked"="2" %num) local_unnamed_addr #5 {
entry:
  %0 = icmp eq [256 x %"struct.ap_uint<256>"]* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %src.addr.0.0.05 = getelementptr [256 x %"struct.ap_uint<256>"], [256 x %"struct.ap_uint<256>"]* %src, i64 0, i64 %for.loop.idx2, i32 0, i32 0, i32 0
  %dst.addr.0.0.06 = getelementptr [256 x i256], [256 x i256]* %dst, i64 0, i64 %for.loop.idx2
  %1 = load i256, i256* %src.addr.0.0.05, align 32
  store i256 %1, i256* %dst.addr.0.0.06, align 32
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @copy_out(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* noalias "unpacked"="0", i16* noalias align 512 "unpacked"="1.0" %_V_data_V, i2* noalias align 512 "unpacked"="1.1" %_V_keep_V, i2* noalias align 512 "unpacked"="1.2" %_V_strb_V, i1* noalias align 512 "unpacked"="1.3" %_V_last_V, [256 x %"struct.ap_uint<256>"]* noalias "unpacked"="2", [256 x i256]* noalias nocapture readonly "unpacked"="3.0") unnamed_addr #6 {
entry:
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %0, i16* align 512 %_V_data_V, i2* align 512 %_V_keep_V, i2* align 512 %_V_strb_V, i1* align 512 %_V_last_V)
  call fastcc void @"onebyonecpy_hls.p0a256struct.ap_uint<256>.6"([256 x %"struct.ap_uint<256>"]* %1, [256 x i256]* %2)
  ret void
}

declare void @free(i8*) local_unnamed_addr

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @"onebyonecpy_hls.p0a256struct.ap_uint<256>.6"([256 x %"struct.ap_uint<256>"]* noalias "unpacked"="0" %dst, [256 x i256]* noalias nocapture readonly "unpacked"="1.0" %src) unnamed_addr #4 {
entry:
  %0 = icmp eq [256 x %"struct.ap_uint<256>"]* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @"arraycpy_hls.p0a256struct.ap_uint<256>.9"([256 x %"struct.ap_uint<256>"]* nonnull %dst, [256 x i256]* %src, i64 256)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @"arraycpy_hls.p0a256struct.ap_uint<256>.9"([256 x %"struct.ap_uint<256>"]* "unpacked"="0" %dst, [256 x i256]* nocapture readonly "unpacked"="1.0" %src, i64 "unpacked"="2" %num) local_unnamed_addr #5 {
entry:
  %0 = icmp eq [256 x %"struct.ap_uint<256>"]* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %src.addr.0.0.05 = getelementptr [256 x i256], [256 x i256]* %src, i64 0, i64 %for.loop.idx2
  %dst.addr.0.0.06 = getelementptr [256 x %"struct.ap_uint<256>"], [256 x %"struct.ap_uint<256>"]* %dst, i64 0, i64 %for.loop.idx2, i32 0, i32 0, i32 0
  %1 = load i256, i256* %src.addr.0.0.05, align 32
  store i256 %1, i256* %dst.addr.0.0.06, align 32
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>.18"(i16* noalias align 512 "unpacked"="0.0" %dst_V_data_V, i2* noalias align 512 "unpacked"="0.1" %dst_V_keep_V, i2* noalias align 512 "unpacked"="0.2" %dst_V_strb_V, i1* noalias align 512 "unpacked"="0.3" %dst_V_last_V, %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* noalias %src) unnamed_addr #2 {
entry:
  %0 = icmp eq %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>.21"(i16* align 512 %dst_V_data_V, i2* align 512 %dst_V_keep_V, i2* align 512 %dst_V_strb_V, i1* align 512 %dst_V_last_V, %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* nonnull %src)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @"streamcpy_hls.p0class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>.21"(i16* noalias nocapture align 512 "unpacked"="0.0" %_V_data_V, i2* noalias nocapture align 512 "unpacked"="0.1" %_V_keep_V, i2* noalias nocapture align 512 "unpacked"="0.2" %_V_strb_V, i1* noalias nocapture align 512 "unpacked"="0.3" %_V_last_V, %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* noalias nocapture) unnamed_addr #3 {
entry:
  %1 = alloca %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"
  %2 = alloca i16
  %3 = alloca i2
  %4 = alloca i2
  %5 = alloca i1
  br label %empty

empty:                                            ; preds = %push, %entry
  %6 = bitcast %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %0 to i8*
  %7 = call i1 @fpga_fifo_not_empty_8(i8* %6)
  br i1 %7, label %push, label %ret

push:                                             ; preds = %empty
  %8 = bitcast %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %1 to i8*
  %9 = bitcast %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %0 to i8*
  call void @fpga_fifo_pop_8(i8* %8, i8* %9)
  %10 = load volatile %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>", %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %1
  %.fca.0.0.0.0.0.extract = extractvalue %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>" %10, 0, 0, 0, 0, 0
  %.fca.0.1.0.0.0.extract = extractvalue %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>" %10, 0, 1, 0, 0, 0
  %.fca.0.2.0.0.0.extract = extractvalue %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>" %10, 0, 2, 0, 0, 0
  %.fca.0.4.0.0.0.extract = extractvalue %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>" %10, 0, 4, 0, 0, 0
  store i16 %.fca.0.0.0.0.0.extract, i16* %2
  %11 = bitcast i16* %2 to i8*
  %12 = bitcast i16* %_V_data_V to i8*
  call void @fpga_fifo_push_2(i8* %11, i8* %12)
  store i2 %.fca.0.1.0.0.0.extract, i2* %4
  %13 = bitcast i2* %4 to i8*
  %14 = bitcast i2* %_V_keep_V to i8*
  call void @fpga_fifo_push_1(i8* %13, i8* %14)
  store i2 %.fca.0.2.0.0.0.extract, i2* %3
  %15 = bitcast i2* %3 to i8*
  %16 = bitcast i2* %_V_strb_V to i8*
  call void @fpga_fifo_push_1(i8* %15, i8* %16)
  store i1 %.fca.0.4.0.0.0.extract, i1* %5
  %17 = bitcast i1* %5 to i8*
  %18 = bitcast i1* %_V_last_V to i8*
  call void @fpga_fifo_push_1(i8* %17, i8* %18)
  br label %empty, !llvm.loop !5

ret:                                              ; preds = %empty
  ret void
}

declare void @apatb_bnn_layer2_xnor_hw(i16*, i2*, i2*, i1*, %"struct.ap_uint<256>"*, [256 x i256]*, %"struct.ap_uint<1>"*)

; Function Attrs: argmemonly noinline willreturn
define internal fastcc void @copy_back(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* noalias "unpacked"="0", i16* noalias align 512 "unpacked"="1.0" %_V_data_V, i2* noalias align 512 "unpacked"="1.1" %_V_keep_V, i2* noalias align 512 "unpacked"="1.2" %_V_strb_V, i1* noalias align 512 "unpacked"="1.3" %_V_last_V, [256 x %"struct.ap_uint<256>"]* noalias "unpacked"="2", [256 x i256]* noalias nocapture readonly "unpacked"="3.0") unnamed_addr #6 {
entry:
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %0, i16* align 512 %_V_data_V, i2* align 512 %_V_keep_V, i2* align 512 %_V_strb_V, i1* align 512 %_V_last_V)
  ret void
}

define void @bnn_layer2_xnor_hw_stub_wrapper(i16*, i2*, i2*, i1*, %"struct.ap_uint<256>"*, [256 x i256]*, %"struct.ap_uint<1>"*) #7 {
entry:
  %7 = alloca %"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"
  %malloccall = tail call i8* @malloc(i64 8192)
  %8 = bitcast i8* %malloccall to [256 x %"struct.ap_uint<256>"]*
  call void @copy_out(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %7, i16* %0, i2* %1, i2* %2, i1* %3, [256 x %"struct.ap_uint<256>"]* %8, [256 x i256]* %5)
  %9 = bitcast [256 x %"struct.ap_uint<256>"]* %8 to %"struct.ap_uint<256>"*
  call void @bnn_layer2_xnor_hw_stub(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %7, %"struct.ap_uint<256>"* %4, %"struct.ap_uint<256>"* %9, %"struct.ap_uint<1>"* %6)
  call void @copy_in(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* %7, i16* %0, i2* %1, i2* %2, i1* %3, [256 x %"struct.ap_uint<256>"]* %8, [256 x i256]* %5)
  ret void
}

declare void @bnn_layer2_xnor_hw_stub(%"class.hls::stream<hls::axis<ap_uint<16>, 0, 0, 0, '8', false>, 0>"* noalias nonnull, %"struct.ap_uint<256>"* nocapture readonly, %"struct.ap_uint<256>"* noalias nocapture nonnull readonly, %"struct.ap_uint<1>"* nocapture readonly)

declare i1 @fpga_fifo_not_empty_8(i8*)

declare i1 @fpga_fifo_not_empty_2(i8*)

declare void @fpga_fifo_pop_8(i8*, i8*)

declare void @fpga_fifo_pop_2(i8*, i8*)

declare void @fpga_fifo_pop_1(i8*, i8*)

declare void @fpga_fifo_push_8(i8*, i8*)

declare void @fpga_fifo_push_2(i8*, i8*)

declare void @fpga_fifo_push_1(i8*, i8*)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline willreturn "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline willreturn "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline willreturn "fpga.wrapper.func"="streamcpy_hls" }
attributes #4 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #5 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="arraycpy_hls" }
attributes #6 = { argmemonly noinline willreturn "fpga.wrapper.func"="copyout" }
attributes #7 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.rotate.disable"}
