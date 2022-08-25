#######################################################################################
# Define source file lists to SRC_LIST                                                #
#######################################################################################


################################ Start of G2D SRC_LIST ################################
SRC_LIST = hal\graphics\g2d\common\src\g2d_bitblt_api.c                               \
           hal\graphics\g2d\common\src\g2d_common_api.c                               \
           hal\graphics\g2d\common\src\g2d_font_api.c                                 \
           hal\graphics\g2d\common\src\g2d_mutex.c                                    \
           hal\graphics\g2d\common\src\g2d_overlay_api.c                              \
           hal\graphics\g2d\common\src\g2d_rectfill_api.c

####### The following 4 files are moved to gfx_core16.lib for security concern. #######
#           hal\graphics\g2d\common\src\g2d_lt_api.c                                   \
#           hal\graphics\g2d\common\src\g2d_lt_int.c                                   \
#           hal\graphics\g2d\common\src\g2d_lt_csc_switch.c                            \
#           hal\graphics\g2d\hw\src\g2d_lt_int_hw.c

ifneq ($(filter MT6235, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6235_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_common_6235_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_font_6235_series.c                      \
              hal\graphics\g2d\hw\src\g2d_drv_rectfill_6235_series.c
else
   ifneq ($(filter MT6235B, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6235_series.c                \
                  hal\graphics\g2d\hw\src\g2d_drv_common_6235_series.c                \
                  hal\graphics\g2d\hw\src\g2d_drv_font_6235_series.c                  \
                  hal\graphics\g2d\hw\src\g2d_drv_rectfill_6235_series.c
   endif
endif

ifneq ($(filter MT6268, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6268_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_common_6268_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_font_6268_series.c                      \
              hal\graphics\g2d\hw\src\g2d_drv_rectfill_6268_series.c
else
   ifneq ($(filter MT6268A, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6268_series.c                \
                  hal\graphics\g2d\hw\src\g2d_drv_common_6268_series.c                \
                  hal\graphics\g2d\hw\src\g2d_drv_font_6268_series.c                  \
                  hal\graphics\g2d\hw\src\g2d_drv_rectfill_6268_series.c
   endif
endif

ifneq ($(filter MT6236, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6236_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_common_6236_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_font_6236_series.c                      \
              hal\graphics\g2d\hw\src\g2d_drv_lt_6236_series.c                        \
              hal\graphics\g2d\hw\src\g2d_drv_rectfill_6236_series.c
else
   ifneq ($(filter MT6236B, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6236_series.c                \
                  hal\graphics\g2d\hw\src\g2d_drv_common_6236_series.c                \
                  hal\graphics\g2d\hw\src\g2d_drv_font_6236_series.c                  \
                  hal\graphics\g2d\hw\src\g2d_drv_lt_6236_series.c                    \
                  hal\graphics\g2d\hw\src\g2d_drv_rectfill_6236_series.c
   endif
endif

ifneq ($(filter MT6276, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6276_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_common_6276_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_font_6276_series.c                      \
              hal\graphics\g2d\hw\src\g2d_drv_lt_6276_series.c                        \
              hal\graphics\g2d\hw\src\g2d_drv_overlay_6276_series.c                   \
              hal\graphics\g2d\hw\src\g2d_drv_rectfill_6276_series.c
endif

ifneq ($(filter MT6255, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6255_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_common_6255_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_font_6255_series.c                      \
              hal\graphics\g2d\hw\src\g2d_drv_lt_6255_series.c                        \
              hal\graphics\g2d\hw\src\g2d_drv_overlay_6255_series.c                   \
              hal\graphics\g2d\hw\src\g2d_drv_rectfill_6255_series.c
endif

ifneq ($(filter MT6250, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6250_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_common_6250_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_font_6250_series.c                      \
              hal\graphics\g2d\hw\src\g2d_drv_lt_6250_series.c                        \
              hal\graphics\g2d\hw\src\g2d_drv_overlay_6250_series.c                   \
              hal\graphics\g2d\hw\src\g2d_drv_rectfill_6250_series.c
endif

ifneq ($(filter MT6260, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6260_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_common_6260_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_font_6260_series.c                      \
              hal\graphics\g2d\hw\src\g2d_drv_lt_6260_series.c                        \
              hal\graphics\g2d\hw\src\g2d_drv_overlay_6260_series.c                   \
              hal\graphics\g2d\hw\src\g2d_drv_rectfill_6260_series.c
endif

ifneq ($(filter MT6261, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6260_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_common_6260_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_font_6260_series.c                      \
              hal\graphics\g2d\hw\src\g2d_drv_lt_6260_series.c                        \
              hal\graphics\g2d\hw\src\g2d_drv_overlay_6260_series.c                   \
              hal\graphics\g2d\hw\src\g2d_drv_rectfill_6260_series.c
endif

ifneq ($(filter MT2501, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6260_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_common_6260_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_font_6260_series.c                      \
              hal\graphics\g2d\hw\src\g2d_drv_lt_6260_series.c                        \
              hal\graphics\g2d\hw\src\g2d_drv_overlay_6260_series.c                   \
              hal\graphics\g2d\hw\src\g2d_drv_rectfill_6260_series.c
endif

ifneq ($(filter MT2502, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\graphics\g2d\hw\src\g2d_drv_bitblt_6260_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_common_6260_series.c                    \
              hal\graphics\g2d\hw\src\g2d_drv_font_6260_series.c                      \
              hal\graphics\g2d\hw\src\g2d_drv_lt_6260_series.c                        \
              hal\graphics\g2d\hw\src\g2d_drv_overlay_6260_series.c                   \
              hal\graphics\g2d\hw\src\g2d_drv_rectfill_6260_series.c
endif


################################# End of G2D SRC_LIST #################################



################################ Start of JPEG SRC_LIST ###############################
SRC_LIST += hal\graphics\jpeg\encode\common\src\jpeg_encode_api.c                     \
            hal\graphics\jpeg\common\src\jpeg_mem_check.c                             \
            hal\graphics\jpeg\common\src\jpeg_misc_api.c                              \
            hal\graphics\jpeg\common\src\jpeg_drv_null_driver.c

ifneq ($(filter MT6236, $(strip $(MODULE_DEFS))),)
   SRC_LIST += hal\graphics\jpeg\common\src\jpeg_drv_init_6236_series.c
else
   ifneq ($(filter MT6236B, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\graphics\jpeg\common\src\jpeg_drv_init_6236_series.c
   endif
endif

ifneq ($(filter MT6276, $(strip $(MODULE_DEFS))),)
   SRC_LIST += hal\graphics\jpeg\common\src\jpeg_drv_init_6276_series.c
endif

ifneq ($(filter MT6256, $(strip $(MODULE_DEFS))),)
   SRC_LIST += hal\graphics\jpeg\common\src\jpeg_drv_init_6256_series.c
endif

ifneq ($(filter MT6255, $(strip $(MODULE_DEFS))),)
   SRC_LIST += hal\graphics\jpeg\common\src\jpeg_drv_init_6255_series.c
endif

ifneq ($(filter MT6268, $(strip $(MODULE_DEFS))),)
   SRC_LIST += hal\graphics\jpeg\common\src\jpeg_drv_init_6268_series.c
else
   ifneq ($(filter MT6268A, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\graphics\jpeg\common\src\jpeg_drv_init_6268_series.c
   else
      ifneq ($(filter MT6270A, $(strip $(MODULE_DEFS))),)
         SRC_LIST += hal\graphics\jpeg\common\src\jpeg_drv_init_6268_series.c
      endif
   endif
endif

ifneq ($(filter MT6250, $(strip $(MODULE_DEFS))),)
   SRC_LIST += hal\graphics\jpeg\common\src\jpeg_drv_init_6250_series.c
endif


ifneq ($(filter JPG_ENCODE, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\graphics\jpeg\encode\common\src\jpeg_encode_feature_switch.c        \
              hal\graphics\jpeg\encode\common\src\jpeg_encode_int.c                   \
              hal\graphics\jpeg\encode\common\src\jpeg_encode_wrapper.c               \
              hal\graphics\jpeg\encode\hw\src\jpeg_encode_int_hw.c                    \
              hal\graphics\jpeg\encode\sw\src\jpeg_encode_int_sw.c

  ifneq ($(filter MT6236, $(strip $(MODULE_DEFS))),)
     SRC_LIST += hal\graphics\jpeg\encode\hw\src\jpeg_drv_enc_6236_series.c
  else
     ifneq ($(filter MT6236B, $(strip $(MODULE_DEFS))),)
        SRC_LIST += hal\graphics\jpeg\encode\hw\src\jpeg_drv_enc_6236_series.c
     endif
  endif

  ifneq ($(filter MT6276, $(strip $(MODULE_DEFS))),)
     SRC_LIST += hal\graphics\jpeg\encode\hw\src\jpeg_drv_enc_6276_series.c
  endif

  ifneq ($(filter MT6256, $(strip $(MODULE_DEFS))),)
     SRC_LIST += hal\graphics\jpeg\encode\hw\src\jpeg_drv_enc_6256_series.c
  endif

  ifneq ($(filter MT6255, $(strip $(MODULE_DEFS))),)
     SRC_LIST += hal\graphics\jpeg\encode\hw\src\jpeg_drv_enc_6255_series.c
  endif

  ifneq ($(filter MT6268, $(strip $(MODULE_DEFS))),)
     SRC_LIST += hal\graphics\jpeg\encode\hw\src\jpeg_drv_enc_6268_series.c
  else
     ifneq ($(filter MT6268A, $(strip $(MODULE_DEFS))),)
        SRC_LIST += hal\graphics\jpeg\encode\hw\src\jpeg_drv_enc_6268_series.c
     else
        ifneq ($(filter MT6270A, $(strip $(MODULE_DEFS))),)
           SRC_LIST += hal\graphics\jpeg\encode\hw\src\jpeg_drv_enc_6268_series.c
        endif
     endif
  endif

  ifneq ($(filter MT6250, $(strip $(MODULE_DEFS))),)
     SRC_LIST += hal\graphics\jpeg\encode\hw\src\jpeg_drv_enc_6250_series.c     
  endif
endif


ifneq ($(filter JPG_DECODE, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\graphics\jpeg\decode\common\src\jpeg_decode_api.c                   \
              hal\graphics\jpeg\decode\common\src\jpeg_decode_feature_switch.c        \
              hal\graphics\jpeg\decode\common\src\jpeg_decode_int.c                   \
              hal\graphics\jpeg\decode\common\src\jpeg_parse_api.c                    \
              hal\graphics\jpeg\decode\common\src\jpeg_parse_int.c                    \
              hal\graphics\jpeg\decode\hw\src\jpeg_decode_int_hw.c                    \
              hal\graphics\jpeg\decode\sw\src\jpeg_decode_int_sw.c                    \
              hal\graphics\jpeg\decode\sw\src\jpeg_decode_int_sw_post_parsing.c

  ifneq ($(filter MT6276, $(strip $(MODULE_DEFS))),)
     SRC_LIST += hal\graphics\jpeg\decode\hw\src\jpeg_drv_dec_6276_series.c
  endif

  ifneq ($(filter MT6256, $(strip $(MODULE_DEFS))),)
     SRC_LIST += hal\graphics\jpeg\decode\hw\src\jpeg_drv_dec_6256_series.c
  endif

  ifneq ($(filter MT6255, $(strip $(MODULE_DEFS))),)
     SRC_LIST += hal\graphics\jpeg\decode\hw\src\jpeg_drv_dec_6255_series.c
  endif

  ifneq ($(filter MT6268, $(strip $(MODULE_DEFS))),)
     SRC_LIST += hal\graphics\jpeg\decode\hw\src\jpeg_drv_dec_6268_series.c
  else
     ifneq ($(filter MT6268A, $(strip $(MODULE_DEFS))),)
        SRC_LIST += hal\graphics\jpeg\decode\hw\src\jpeg_drv_dec_6268_series.c
     else
        ifneq ($(filter MT6270A, $(strip $(MODULE_DEFS))),)
           SRC_LIST += hal\graphics\jpeg\decode\hw\src\jpeg_drv_dec_6268_series.c
        endif
     endif
  endif
  
  ifneq ($(filter MT6250, $(strip $(MODULE_DEFS))),)     
     SRC_LIST += hal\graphics\jpeg\decode\hw\src\Jpeg_drv_dec_6250_series.c
  endif  
endif
################################# End of JPEG SRC_LIST ################################



################################ Start of EXIF SRC_LIST ###############################
SRC_LIST += hal\graphics\jpeg\exif\src\exif_enc_api.c                                 \
            hal\graphics\jpeg\exif\src\exif_enc_wrapper.c                             \
            hal\graphics\jpeg\exif\src\exif_legacy.c
################################# End of EXIF SRC_LIST ################################



################################ Start of JAIA SRC_LIST ###############################
SRC_LIST += hal\graphics\jpeg\jaia\src\jaia_api.c                                     \
            hal\graphics\jpeg\jaia\src\jaia_utility.c
################################# End of JAIA SRC_LIST ################################



############################## Start of Rotator SRC_LIST ##############################
SRC_LIST += hal\graphics\rotator\rgb_rotator\common\src\rgb_rotator_api.c             \
            hal\graphics\rotator\rgb_rotator\hw\src\rgb_rotator_int_hw.c              \
            hal\graphics\rotator\rgb_rotator\sw\src\rgb_rotator_int_sw.c              \
            hal\graphics\rotator\yuv_rotator\common\src\yuv_rotator_api.c             \
            hal\graphics\rotator\yuv_rotator\hw\src\yuv_rotator_int_hw.c              \
            hal\graphics\rotator\yuv_rotator\sw\src\yuv_rotator_int_sw.c
################################ End of Rotator SRC_LIST ##############################



############################## Start of Resizer SRC_LIST ##############################
SRC_LIST += hal\graphics\resizer\rgb_resizer\common\src\rgb_resizer_api.c             \
            hal\graphics\resizer\rgb_resizer\hw\src\rgb_resizer_int_hw.c              \
            hal\graphics\resizer\rgb_resizer\sw\src\rgb_resizer_int_sw.c
################################ End of Resizer SRC_LIST ##############################



################################ Start of PNG SRC_LIST ################################
SRC_LIST += hal\graphics\png\common\src\png_decode_api.c                              \
            hal\graphics\png\common\src\png_decode_int.c                              \
            hal\graphics\png\hw\src\png_decoder_int_hw.c                              \
            hal\graphics\png\sw\src\png_decoder_int_sw.c                              \
            hal\graphics\png\hw\src\png_drv_6268_series.c                             \
            hal\graphics\png\hw\src\png_drv_6276_series.c

#ifneq ($(filter __DRV_GRAPHICS_PNG_6268_SERIES__, $(strip $(MODULE_DEFS))),)
#  SRC_LIST += hal\graphics\png\hw\src\png_drv_6268_series.c
#endif
#
#ifneq ($(filter __DRV_GRAPHICS_PNG_6276_SERIES__, $(strip $(MODULE_DEFS))),)
#  SRC_LIST += hal\graphics\png\hw\src\png_drv_6276_series.c
#endif
################################# End of PNG SRC_LIST #################################



################################ Start of GIF SRC_LIST ################################
ifneq ($(filter USE_SW_GIF_DECODER, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\graphics\gif\common\src\gif_decode_api.c                              \
            hal\graphics\gif\sw\src\gif_parse.c                                       \
            hal\graphics\gif\sw\src\gif_decode_int_sw.c                               \
            hal\graphics\gif\sw\src\gif_decode_int_sw_codec.c                         \
            hal\graphics\gif\sw\src\gif_decode_int_sw_util.c

   ifneq ($(filter USE_HW_GIF_DECODER_V3, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\graphics\gif\hw\src\gif_drv_dec_6268_series.c
   endif

   ifneq ($(filter USE_HW_GIF_DECODER_V4, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\graphics\gif\hw\src\gif_drv_dec_6276_series.c
   endif
endif

#ifneq ($(filter __DRV_GRAPHICS_GIF_DEC_6268_SERIES__, $(strip $(MODULE_DEFS))),)
#  SRC_LIST += hal\graphics\gif\hw\src\gif_drv_dec_6268_series.c
#endif
################################# End of GIF SRC_LIST #################################



################################ Start of BFC SRC_LIST ################################
SRC_LIST += hal\graphics\bfc\src\bfc_decode_api.c                                     \
            hal\graphics\bfc\src\bfc_decode_feature_switch.c
################################# End of BFC SRC_LIST #################################



################################ Start of MISC SRC_LIST ###############################
SRC_LIST += hal\graphics\misc\src\drv_gfx_dct_control.c                               \
            hal\graphics\misc\src\drv_gfx_dynamic_switch.c                            \
            hal\graphics\misc\src\drv_gfx_stack_switch_manager.c                      \
            hal\graphics\misc\src\simple_memory_manager.c                             \
            hal\graphics\misc\src\rs_buffer.c                                         \
            hal\graphics\misc\src\drv_gfx_l1sm_ctrl.c                                 \
            hal\graphics\misc\src\drv_gfx_hisr_ctrl.c                                 \
            hal\graphics\misc\src\drv_gfx_codec_limitation.c
################################# End of MISC SRC_LIST ################################



################################ Start of IPP SRC_LIST ################################
SRC_LIST += hal\graphics\ipp\src\ipp_interface.c
################################# End of IPP SRC_LIST #################################



################################ Start of CONTAINER SRC_LIST ################################
SRC_LIST += hal\graphics\container\ivlw_decoder.c                               \
            hal\graphics\container\ivlw_encoder.c                               \
            hal\graphics\container\lwp_decoder.c                                \
            hal\graphics\container\mav_decoder.c                                \
            hal\graphics\container\mav_encoder.c
################################## End of IPP SRC_LIST #################################



################################ Start of COLOR SRC_LIST ###############################
SRC_LIST += hal\graphics\color\common\src\color_api.c                    \
            hal\graphics\color\common\src\color_drv_null_driver.c        \
            hal\graphics\color\hw\src\color_drv_6260_series.c
################################# End of JPEG SRC_LIST ################################



#######################################################################################
#  Define include path lists to INC_DIR                                               #
#######################################################################################

INC_DIR = interface\hal\graphics                            \
          interface\hal\mm_comm                             \
          interface\hal\mdp                                 \
          hal\graphics\g2d\common\inc                       \
          hal\graphics\g2d\hw\inc                           \
          hal\graphics\jpeg\common\inc                      \
          hal\graphics\jpeg\decode\common\inc               \
          hal\graphics\jpeg\encode\common\inc               \
          hal\graphics\jpeg\exif\inc                        \
          hal\graphics\jpeg\jaia\inc                        \
          hal\graphics\rotator\rgb_rotator\common\inc       \
          hal\graphics\rotator\yuv_rotator\common\inc       \
          hal\graphics\resizer\rgb_resizer\common\inc       \
          hal\graphics\png\common\inc                       \
          hal\graphics\png\hw\inc                           \
          hal\graphics\png\sw\inc                           \
          hal\graphics\gfx_core\png\inc                     \
          hal\graphics\gif\hw\inc                           \
          hal\graphics\gif\sw\inc                           \
          hal\graphics\misc\inc                             \
          hal\mm_comm\inc                                   \
          hal\mdp\include                                   \
          hal\graphics\gfx_core\g2d\inc                     \
          hal\graphics\gfx_core\resizer\rgb_resizer\inc     \
          hal\graphics\gfx_core\rotator\yuv_rotator\inc     \
          hal\graphics\gfx_core\rotator\rgb_rotator\inc     \
          hal\graphics\gfx_core\ipp\inc                     \
          hal\graphics\gfx_core\jpeg\encode\inc             \
          hal\graphics\gfx_core\jpeg\decode\inc             \
          hal\graphics\gfx_core\jpeg\exif\inc               \
          hal\graphics\gfx_core\jpeg\jaia\inc               \
          hal\graphics\bfc\inc                              \
          hal\graphics\gfx_core\bfc\inc                     \
          hal\graphics\ipp\inc                              \
          hal\graphics\color\hw\inc                         \
          hal\display\common\include                        \
          plutommi\Framework\GDI\GDIInc                     \
          plutommi\MMI\Resource\Inc




#######################################################################################
# Define the specified compile options to COMP_DEFS                                   #
#######################################################################################

COMP_DEFS = MMI_ON_HARDWARE_P





