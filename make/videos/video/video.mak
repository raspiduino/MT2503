# Define source file lists to SRC_LIST
SRC_LIST =

SRC_LIST += hal\video\common\src\vcodec_v2_main.c
SRC_LIST += hal\video\common\src\vcodec_main.c

SRC_LIST += hal\video\common\src\video_codec_utility_v2.c
SRC_LIST += hal\video\renderer\src\video_renderer_task_thread_pool.c

ifneq ($(filter MULTI_MEDIA_EXIST, $(strip $(MODULE_DEFS))),)
SRC_LIST += hal\video\common\src\vfile_main.c \
            hal\video\common\src\vsrc_main.c
endif

ifneq ($(filter __VIDEO_ARCHI_V2__, $(strip $(MODULE_DEFS))),)
SRC_LIST +=hal\video\common\src\video_buffer_management_v2.c \
           hal\video\common\src\video_codec_custom_setting_v2.c \
           hal\video\common\src\video_codec_custom_adapter_v2.c \
           hal\video\common\src\video_comm_component_v2.c \
           hal\video\common\src\video_comm_v2.c \
           hal\video\common\src\video_dbg_v2.c \
           hal\video\common\src\VideoCall_IL_Client.c \
           hal\video\common\src\video_muxer_component_v2.c \
           hal\video\common\src\avi_muxer_v2.c \
           hal\video\vt_parser\src\video_vt_api_v2.c \
           hal\video\custom\hal_custom_video.c \
           hal\video\renderer\src\va2_comp_video_renderer.c \
           hal\video\renderer\src\va2_util_buffer_header_queue.c \
           hal\video\renderer\src\va2_util_misc.c \
           hal\video\renderer\src\va2_video_renderer_vp.c \
           hal\video\renderer\src\va2_video_renderer_vt.c \
           hal\video\renderer\src\va2_display_api_adapter.c \
           hal\video\renderer\src\stereo_video_color_transformation.c \
           hal\video\common\src\video_codec_parser_utility_v2.c	\
           hal\video\common\src\mp4_muxer_adapter_buffer_management_v2.c \
           hal\video\common\src\mp4_muxer_adapter_meta_creation_v2.c \
           hal\video\common\src\mp4_muxer_adapter_v2.c \
           hal\video\common\src\rtp_muxer_adapter_v2.c \
           hal\video\common\src\video_subtitle_decoder.c \
           hal\video\common\src\video_subtitle_codec_if.c \
           hal\video\common\src\video_subtitle_codec_ssa.c

    # MT6236 VP
    ifneq ($(filter MT6236, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6236.c
    else
      ifneq ($(filter MT6236B, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6236.c
      endif
    endif

    # MT6250 VP
    ifneq ($(filter MT6250, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6252.c
    endif

    # MT6260 VP
    ifneq ($(filter MT6260, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6252.c
    endif

    # MT6261 VP
    ifneq ($(filter MT6261, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6252.c
    else
      ifneq ($(filter MT2501, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6252.c
      else
        ifneq ($(filter MT2502, $(strip $(MODULE_DEFS))),)
        SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6252.c
        endif
      endif
    endif

    # MT6252/MT6253 VP
    ifneq ($(filter MT6253, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6253.c
    else
      ifneq ($(filter MT6253E, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6252.c
      else
        ifneq ($(filter MT6253L, $(strip $(MODULE_DEFS))),)
        SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6252.c
        else
          ifneq ($(filter MT6252, $(strip $(MODULE_DEFS))),)
          SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6252.c
          else
            ifneq ($(filter MT6252H, $(strip $(MODULE_DEFS))),)
            SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6252.c
            endif
          endif
        endif
      endif
    endif

    # MT6268 VP
    ifneq ($(filter MT6268, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6268.c
    else
      ifneq ($(filter MT6268H, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6268.c
      endif
    endif

    # MT6276/MT6256/MT6255 VP
    ifneq ($(filter MT6276, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6276.c
    else
      ifneq ($(filter MT6256_S00, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6276.c
      else
        ifneq ($(filter MT6256_S01, $(strip $(MODULE_DEFS))),)
        SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6276.c
        else
          ifneq ($(filter MT6255, $(strip $(MODULE_DEFS))),)
          SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6276.c
          endif
        endif
      endif
    endif

    # MT6235 VP
    ifneq ($(filter MT6235, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6235.c
    else
      ifneq ($(filter MT6235B, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vp_mt6235.c
      endif
    endif

    # MT6236 VT
    ifneq ($(filter MT6236, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vt_mt6236.c
    else
      ifneq ($(filter MT6236B, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vt_mt6236.c
      endif
    endif

    # MT6268/MT6255 VT
    ifneq ($(filter MT6268, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vt_mt6268.c
    else
      ifneq ($(filter MT6268H, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vt_mt6268.c
      else
        ifneq ($(filter MT6255, $(strip $(MODULE_DEFS))),)
        SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vt_mt6268.c
        endif
      endif
    endif

    # MT6256 VT
    ifneq ($(filter MT6256_S00, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vt_mt6268.c
    else
      ifneq ($(filter MT6256_S01, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vt_mt6268.c
      endif
    endif

    # MT6276 VT
    ifneq ($(filter MT6276, $(strip $(MODULE_DEFS))),)
    SRC_LIST +=hal\video\renderer\src\va2_video_renderer_vt_mt6276.c
    endif

    # Video recoder - MPEG-4
    ifneq ($(filter __MPEG4_ENC_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\video\common\src\video_recorder_clock_utility_v2.c \
                hal\video\common\src\video_recorder_if_v2.c
    endif

    # Video recoder - MJPEG
    ifneq ($(filter __AVI_ENC_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\video\common\src\video_recorder_clock_utility_v2.c \
                hal\video\common\src\video_recorder_if_v2.c
    endif
endif

SRC_LIST += \
           hal\video\custom\custom_video_enc.c \
           hal\video\custom\custom_video_enc_matv_mjpeg.c \
           hal\video\custom\custom_video_enc_matv.c \
           hal\video\custom\custom_video_enc_mjpeg.c \
           hal\video\custom\custom_video_enc_mpeg4.c \
           hal\video\custom\custom_video_enc_h264.c \
           hal\video\custom\custom_video_enc_utility.c \
           hal\video\custom\custom_video_enc_vt.c

# Define include path lists to INC_DIR
INC_DIR = hal\video\common\include \
          hal\video\decoder\include \
          hal\video\vt_parser\include \
          hal\video_codec\interface\inc \
          hal\video\mpl\inc \
          hal\video\demuxer\provider\inc \
          hal\video\demuxer\mp4_parser\inc \
          hal\video\demuxer\avi_parser\inc \
          interface\hal\video \
          media\common\include \
          drm\include \
          plutommi\mtkapp\mtkappinc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          applib\inet\engine\include \
          sst\include \
          applib\misc\include \
          $(strip $(PS_FOLDER))\l4\uem\include \
          interface\hwdrv \
          vendor\player\ipeer\inc \
          blueangel\btcore\btstack\inc \
          blueangel\btcore\btadp\inc \
          matv\inc \
          custom\video \
          hal\video\custom \
          hal\mm_comm\inc \
          hal\mdp\include \
          hal\mdp\include\mt6253 \
          hal\mdp\include\mt6252 \
          hal\graphics\misc\inc \
          hal\display \
          interface\hal\display \
          interface\hal\display\ddv1 \
          interface\hal\system \
          interface\hal\graphics \
          hal\display\common\include \
          hal\system\dcmgr\inc	\
          media\rtp\inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS =


