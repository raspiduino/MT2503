# Define source file lists to SRC_LIST
SRC_LIST = hal\mdp\src\idp_bus_monitor.c \
           hal\mdp\src\idp_cal.c \
           hal\mdp\src\idp_core.c \
           hal\mdp\src\idp_core_internal.c \
           hal\mdp\src\idp_mem.c \
           hal\mdp\src\image_effect_post.c \
           hal\mdp\src\idp_sw_yuv_2_rgb_dithering.c \
           hal\mdp\src\idp_sw_yuv420_2_uyvy422_resizer.c \
           hal\mdp\src\idp_img_rot_flip.c \
           hal\mdp\src\unit_test_rgb565_120x90.c \
           hal\mdp\src\unit_test_rgb888_80x80.c \
           hal\mdp\src\unit_test_yuv420_80x96_h264.c

ifneq ($(filter MT6250, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_rotdma0_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_crz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_engines_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hisr_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_common_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_cp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_ic_jpeg_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vr_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_ir_mt6250.c
  SRC_LIST += hal\mdp\src\idp_val.c
endif

ifneq ($(filter MT6260, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_rotdma0_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_crz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_engines_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hisr_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_common_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_cp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_ic_jpeg_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vr_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_ir_mt6250.c
  SRC_LIST += hal\mdp\src\idp_val.c
endif

ifneq ($(filter MT6261, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_rotdma0_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_crz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_engines_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hisr_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_common_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_cp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_ic_jpeg_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vr_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_ir_mt6250.c
  SRC_LIST += hal\mdp\src\idp_val.c
endif

ifneq ($(filter MT2501, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_rotdma0_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_crz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_engines_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hisr_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_common_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_cp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_ic_jpeg_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vr_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_ir_mt6250.c
  SRC_LIST += hal\mdp\src\idp_val.c
endif

ifneq ($(filter MT2502, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_rotdma0_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_crz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_engines_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hisr_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_common_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_cp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_ic_jpeg_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vr_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_ir_mt6250.c
  SRC_LIST += hal\mdp\src\idp_val.c
endif

ifneq ($(filter MT6253, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6253\idp_hw\idp_resz_crz_mt6253.c
  SRC_LIST += hal\mdp\src\mt6253\idp_hw\idp_resz_mt6253.c
  SRC_LIST += hal\mdp\src\mt6253\idp_engines_mt6253.c
  SRC_LIST += hal\mdp\src\mt6253\idp_hisr_mt6253.c
  SRC_LIST += hal\mdp\src\mt6253\idp_scen_common_mt6253.c
  SRC_LIST += hal\mdp\src\mt6253\idp_scen_cp_mt6253.c
  SRC_LIST += hal\mdp\src\mt6253\idp_scen_ic_jpeg_mt6253.c
  SRC_LIST += hal\mdp\src\mt6253\idp_scen_vp_mt6253.c
  SRC_LIST += hal\mdp\src\mt6253\idp_scen_vr_mt6253.c
  SRC_LIST += hal\mdp\src\idp_val.c
endif

ifneq ($(filter MT6252, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_rotdma0_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_crz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_engines_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hisr_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_common_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_cp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_ic_jpeg_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vr_mt6252.c
  SRC_LIST += hal\mdp\src\idp_val.c
else
  ifneq ($(filter MT6252H, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_rotdma0_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_crz_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_engines_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_hisr_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_scen_common_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_scen_cp_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_scen_ic_jpeg_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_scen_vp_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_scen_vr_mt6252.c
    SRC_LIST += hal\mdp\src\idp_val.c
  endif
endif

ifneq ($(filter MT6253E, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_rotdma0_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_crz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_engines_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_hisr_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_common_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_cp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_ic_jpeg_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vp_mt6252.c
  SRC_LIST += hal\mdp\src\mt6252\idp_scen_vr_mt6252.c
  SRC_LIST += hal\mdp\src\idp_val.c
else
  ifneq ($(filter MT6253L, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_imgdma_rotdma0_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_crz_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_hw\idp_resz_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_engines_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_hisr_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_scen_common_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_scen_cp_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_scen_ic_jpeg_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_scen_vp_mt6252.c
    SRC_LIST += hal\mdp\src\mt6252\idp_scen_vr_mt6252.c
    SRC_LIST += hal\mdp\src\idp_val.c
  endif
endif


ifneq ($(filter MT6235, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6235\idp_hw\idp_resz_crz_mt6235.c
  SRC_LIST += hal\mdp\src\mt6235\idp_hw\idp_resz_mt6235.c
  SRC_LIST += hal\mdp\src\mt6235\idp_engines_mt6235.c
  SRC_LIST += hal\mdp\src\mt6235\idp_hisr_mt6235.c
  SRC_LIST += hal\mdp\src\mt6235\idp_scen_cp_mt6235.c
  SRC_LIST += hal\mdp\src\mt6235\idp_scen_ic_jpeg_mt6235.c
  SRC_LIST += hal\mdp\src\mt6235\idp_scen_vp_mt6235.c
  SRC_LIST += hal\mdp\src\mt6235\idp_scen_vr_mt6235.c
  SRC_LIST += hal\mdp\src\idp_val_mt6235.c
else
  ifneq ($(filter MT6235B, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\mdp\src\mt6235\idp_hw\idp_resz_crz_mt6235.c
    SRC_LIST += hal\mdp\src\mt6235\idp_hw\idp_resz_mt6235.c
    SRC_LIST += hal\mdp\src\mt6235\idp_engines_mt6235.c
    SRC_LIST += hal\mdp\src\mt6235\idp_hisr_mt6235.c
    SRC_LIST += hal\mdp\src\mt6235\idp_scen_cp_mt6235.c
    SRC_LIST += hal\mdp\src\mt6235\idp_scen_ic_jpeg_mt6235.c
    SRC_LIST += hal\mdp\src\mt6235\idp_scen_vp_mt6235.c
    SRC_LIST += hal\mdp\src\mt6235\idp_scen_vr_mt6235.c
    SRC_LIST += hal\mdp\src\idp_val_mt6235.c
  endif
endif

ifneq ($(filter MT6268, $(strip $(MODULE_DEFS))),)
 SRC_LIST += hal\mdp\src\mt6238\idp_hw\idp_imgdma.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgdma_ibr1.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgdma_ibr2.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgdma_ibw1.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgdma_ibw2.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgdma_irt0.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgdma_irt1.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgdma_irt2.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgdma_irt3.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgdma_ovl.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgdma_jpeg.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgdma_video_decode.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgdma_video_encode.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgproc.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgproc_ipp.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgproc_r2y0.c \
           hal\mdp\src\mt6238\idp_hw\idp_imgproc_y2r1.c \
           hal\mdp\src\mt6238\idp_hw\idp_mp4deblk.c \
           hal\mdp\src\mt6238\idp_hw\idp_resz.c \
           hal\mdp\src\mt6238\idp_hw\idp_resz_drz.c \
           hal\mdp\src\mt6238\idp_hw\idp_resz_crz.c \
           hal\mdp\src\mt6238\idp_hw\idp_resz_prz.c \
           hal\mdp\src\mt6238\idp_core_mt6238.c \
           hal\mdp\src\mt6238\idp_jpeg_decode.c \
           hal\mdp\src\mt6238\idp_jpeg_encode.c \
           hal\mdp\src\mt6238\idp_video_decode.c \
           hal\mdp\src\mt6238\idp_video_encode.c \
           hal\mdp\src\mt6238\idp_video_call_decode.c \
           hal\mdp\src\mt6238\idp_video_call_encode.c \
           hal\mdp\src\mt6238\idp_camera_preview.c \
           hal\mdp\src\mt6238\idp_camera_capture_to_mem.c \
           hal\mdp\src\mt6238\idp_camera_capture_to_jpeg.c \
           hal\mdp\src\mt6238\idp_image_effect_pixel.c \
           hal\mdp\src\mt6238\idp_image_resize.c \
           hal\mdp\src\mt6238\idp_rgb2yuv.c \
           hal\mdp\src\mt6238\idp_hisr.c \
           hal\mdp\src\mt6238\unit_test_mt6238.c \
           hal\mdp\src\mt6238\unit_test_basic_reg_rw_mt6238.c \
           hal\mdp\src\mt6238\unit_test_camera_preview_mt6238.c \
           hal\mdp\src\idp_val.c
else
  ifneq ($(filter MT6268H, $(strip $(MODULE_DEFS))),)
	 SRC_LIST += hal\mdp\src\mt6238\idp_hw\idp_imgdma.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgdma_ibr1.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgdma_ibr2.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgdma_ibw1.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgdma_ibw2.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgdma_irt0.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgdma_irt1.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgdma_irt2.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgdma_irt3.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgdma_ovl.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgdma_jpeg.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgdma_video_decode.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgdma_video_encode.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgproc.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgproc_ipp.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgproc_r2y0.c \
	           hal\mdp\src\mt6238\idp_hw\idp_imgproc_y2r1.c \
	           hal\mdp\src\mt6238\idp_hw\idp_mp4deblk.c \
	           hal\mdp\src\mt6238\idp_hw\idp_resz.c \
	           hal\mdp\src\mt6238\idp_hw\idp_resz_drz.c \
	           hal\mdp\src\mt6238\idp_hw\idp_resz_crz.c \
	           hal\mdp\src\mt6238\idp_hw\idp_resz_prz.c \
	           hal\mdp\src\mt6238\idp_core_mt6238.c \
	           hal\mdp\src\mt6238\idp_jpeg_decode.c \
	           hal\mdp\src\mt6238\idp_jpeg_encode.c \
	           hal\mdp\src\mt6238\idp_video_decode.c \
	           hal\mdp\src\mt6238\idp_video_encode.c \
	           hal\mdp\src\mt6238\idp_video_call_decode.c \
	           hal\mdp\src\mt6238\idp_video_call_encode.c \
	           hal\mdp\src\mt6238\idp_camera_preview.c \
	           hal\mdp\src\mt6238\idp_camera_capture_to_mem.c \
	           hal\mdp\src\mt6238\idp_camera_capture_to_jpeg.c \
	           hal\mdp\src\mt6238\idp_image_effect_pixel.c \
	           hal\mdp\src\mt6238\idp_image_resize.c \
	           hal\mdp\src\mt6238\idp_rgb2yuv.c \
	           hal\mdp\src\mt6238\idp_hisr.c \
	           hal\mdp\src\mt6238\unit_test_mt6238.c \
	           hal\mdp\src\mt6238\unit_test_basic_reg_rw_mt6238.c \
	           hal\mdp\src\mt6238\unit_test_camera_preview_mt6238.c \
	           hal\mdp\src\idp_val.c
  endif
endif

ifneq ($(filter MT6236, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_jpgdma_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_mout_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_ovl_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_rdma0_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_rdma1_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_rotdma0_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_rotdma1_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_wdma0_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_wdma1_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_wdma2_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgproc_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgproc_ipp_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_resz_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_resz_crz_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_resz_drz_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_resz_prz_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_cp_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_ic_jpeg_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_ic_mem_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_vp_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_vr_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_image_resize_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_image_effect_pixel_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_jpeg_encode_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_vt_playback_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_vt_record_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_engines_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hisr_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\unit_test_basic_reg_rw_mt6236.c
  SRC_LIST += hal\mdp\src\idp_val.c
else
 ifneq ($(filter MT6236B, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_jpgdma_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_mout_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_ovl_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_rdma0_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_rdma1_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_rotdma0_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_rotdma1_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_wdma0_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_wdma1_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgdma_wdma2_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgproc_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_imgproc_ipp_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_resz_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_resz_crz_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_resz_drz_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hw\idp_resz_prz_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_cp_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_ic_jpeg_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_ic_mem_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_vp_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_vr_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_image_resize_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_image_effect_pixel_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_jpeg_encode_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_vt_playback_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_scen_vt_record_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_engines_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\idp_hisr_mt6236.c
  SRC_LIST += hal\mdp\src\mt6236\unit_test_basic_reg_rw_mt6236.c
  SRC_LIST += hal\mdp\src\idp_val.c
  endif
endif

ifneq ($(filter MT6276, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6276\idp_hw\idp_imgdma_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_jpgdma_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_mout0_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_mout1_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_mout2_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_mout3_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_ovl_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_rdma0_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_rotdma0_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_rotdma1_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_rotdma2_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_vdorot_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_rgbrot0_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_rgbrot1_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgproc_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgproc_ipp_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_resz_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_resz_crz_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_resz_vrz_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_resz_brz_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_resz_prz_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_engines_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_camera_preview_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_camera_capture_to_jpeg_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_camera_capture_to_mem_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_image_effect_pixel_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_image_resize_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_jpeg_decode_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_jpeg_encode_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_video_decode_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_video_encode_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_video_call_decode_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_video_call_encode_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hisr_mt6276.c
  SRC_LIST +=   hal\mdp\src\idp_val.c
endif

ifneq ($(filter MT6256_S00, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6276\idp_hw\idp_imgdma_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_jpgdma_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_mout0_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_mout1_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_mout2_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_mout3_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_ovl_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_rdma0_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_rotdma0_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_rotdma1_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgdma_rotdma2_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgproc_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_imgproc_ipp_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_resz_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_resz_crz_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_resz_vrz_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_resz_brz_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hw\idp_resz_prz_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_engines_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_camera_preview_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_camera_preview_with_face_detection_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_camera_capture_to_jpeg_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_camera_capture_to_mem_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_image_effect_pixel_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_image_resize_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_jpeg_decode_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_jpeg_encode_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_jpeg_resize_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_video_decode_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_video_encode_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_video_call_decode_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_video_call_encode_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_scen_webcam_mt6276.c
  SRC_LIST +=	hal\mdp\src\mt6276\idp_hisr_mt6276.c
  SRC_LIST +=   hal\mdp\src\idp_val.c
endif

ifneq ($(filter MT6256_S01, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6256_e2\idp_hw\idp_imgdma_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_imgdma_jpgdma_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_imgdma_mout_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_imgdma_mimo_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_imgdma_mux_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_imgdma_ovl_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_imgdma_rdma_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_imgdma_vdorot_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_imgdma_rgbrot0_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_imgproc_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_imgproc_ipp_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_resz_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_resz_crz_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_resz_brz_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hw\idp_resz_prz_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_engines_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_scen_camera_preview_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_scen_camera_capture_to_jpeg_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_scen_camera_capture_to_mem_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_scen_image_effect_pixel_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_scen_image_resize_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_scen_jpeg_decode_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_scen_jpeg_encode_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_scen_video_decode_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_scen_video_encode_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_scen_mjpeg_encode_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_scen_video_call_decode_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_scen_video_call_encode_mt6256_e2.c
  SRC_LIST +=	hal\mdp\src\mt6256_e2\idp_hisr_mt6256_e2.c
  SRC_LIST +=   hal\mdp\src\idp_val.c
endif

ifneq ($(filter MT6255, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mdp\src\mt6255\idp_hw\idp_imgdma_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_hw\idp_imgdma_mout_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_hw\idp_imgdma_rdma_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_hw\idp_imgdma_vdorot_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_hw\idp_imgdma_rgbrot0_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_hw\idp_imgproc_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_hw\idp_imgproc_ipp_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_hw\idp_resz_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_hw\idp_resz_crz_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_hw\idp_resz_vrz_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_engines_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_scen_camera_preview_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_scen_camera_capture_to_jpeg_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_scen_camera_capture_to_mem_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_scen_image_effect_pixel_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_scen_image_resize_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_scen_video_decode_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_scen_video_encode_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_scen_video_call_decode_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_scen_video_call_encode_mt6255.c
  SRC_LIST +=	hal\mdp\src\mt6255\idp_hisr_mt6255.c
  SRC_LIST +=   hal\mdp\src\idp_val.c
endif


#  Define include path lists to INC_DIR
INC_DIR = hal\mdp\include \
          hal\mm_comm\inc \
          hal\video\custom \
          hal\display \
          hal\system\cache\inc \
          hal\graphics\jpeg\encode\common\inc \
          hal\graphics\g2d\common\inc \
          interface\hal\mm_comm \
          drv\include \
          media\common\include \
          media\audio\include \
          media\video\include \
          media\camera\include \
          media\image\include \
          media\webcam\include \
          media\tvout\include \
          media\mtv\include \
          drm\include \
          plutommi\mtkapp\mtkappinc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          media\rtp\inc \
          media\stream\include \
          applib\inet\engine\include \
          sst\include \
          applib\misc\include \
          $(strip $(PS_FOLDER))\l4\uem\include \
          media\vcall\include \
          init\include \
          media\common\include \
          hal\video\renderer\include \
          hal\video\common\include \
          interface\hal\display\ddv1 \
          hal\display\common\include

# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P

