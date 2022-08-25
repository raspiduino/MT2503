# Define source file lists to SRC_LIST
# SRC_LIST =

# ifneq ($(filter __VIDEO_ARCHI_V2__, $(strip $(MODULE_DEFS))),)
SRC_LIST = hal\video\video_sec\common\src\video_OAL_v2.c \
           hal\video\video_sec\common\src\video_decoder_common_adapter_v2.c \
           hal\video\video_sec\common\src\video_encoder_common_adapter_v2.c \
           hal\video\video_sec\common\src\h264_hw_decoder_component_v2.c \
           hal\video\video_sec\common\src\mp4_decore_v2.c \
           hal\video\video_sec\common\src\mp4_rc_v2.c \
           hal\video\video_sec\common\src\mpeg4_hw_decoder_component_v2.c \
           hal\video\video_sec\common\src\mjpeg_decoder_component_v2.c \
           hal\video\video_sec\common\src\mjpeg_encoder_component_v2.c \
           hal\video\video_sec\common\src\video_codec_schedule_control.c \
           hal\video\video_sec\common\src\video_decscheduler_component_v2.c \
           hal\video\video_sec\decoder\src\video_decoder_isolation_v2.c \
           hal\video\video_sec\decoder\src\video_codec_buffer_mgr_v2.c \
           hal\video\video_sec\decoder\src\video_decoder_component_v2.c \
           hal\video\video_sec\common\src\video_codec_log.c

    # Video recoder
    # ifneq ($(filter __MPEG4_ENC_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\video\video_sec\common\src\mpeg4_hw_encoder_component_v2.c \
                hal\video\video_sec\common\src\mpeg4_hw_encore_v2.c \
                hal\video\video_sec\common\src\video_recorder_source_component_v2.c \
                hal\video\video_sec\common\src\yuv_encoder_component_v2.c \
                hal\video\video_sec\encoder\src\video_encoder_component_v2.c \
                hal\video\video_sec\encoder\src\video_encoder_auxiliary_v2.c
    # endif

    # H264 OPEN API
    ifneq ($(filter __H264_DEC_HW_SUPPORT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\video\video_sec\h264_open_api\src\open_api_h264_decode.c \
                hal\video\video_sec\h264_open_api\src\open_api_h264_driver.c \
                hal\video\video_sec\h264_open_api\src\open_api_h264_mem_if.c \
                hal\video\video_sec\h264_open_api\src\open_api_h264_memory_management.c \
                hal\video\video_sec\h264_open_api\src\open_api_h264_sw_driver.c \
                hal\video\video_sec\h264_open_api\src\open_api_h264_yuv_management.c
    endif
# endif

ifneq ($(filter MT6235, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\video\video_sec\common\src\sw_video_resizer.c
else
    ifneq ($(filter MT6235B, $(strip $(MODULE_DEFS))),)
        SRC_LIST += hal\video\video_sec\common\src\sw_video_resizer.c
    endif
endif

# Define include path lists to INC_DIR
INC_DIR = hal\video\decoder\include \
          hal\video\common\include \
          hal\video\video_sec \
          hal\video\video_sec\common\include \
          hal\video\video_sec\decoder\include \
          hal\video\video_sec\encoder\include \
          hal\video\video_sec\h264_open_api\include \
          media\common\include \
          drm\include \
          interface\media \
          interface\hwdrv \
          interface\hal\video \
          matv\inc \
          custom\common custom\common\hal custom\common\ps \
          hal\mm_comm\inc \
          hal\mdp\include \
          hal\mdp\include\mt6253 \
          hal\mdp\include\mt6252 \
          hal\graphics\misc\inc \
          hal\video_codec\interface\inc \
          hal\video_codec\video_codec_sec\common\inc\
          interface\hal\display \
          interface\hal\display\ddv1 \
          interface\hal\system \
          interface\hal\graphics \
          custom\video \
          hal\video\custom \
          hal\video\mpl\inc \
          hal\video\demuxer\provider\inc \
          hal\video\demuxer\mp4_parser\inc \
          hal\system\dcmgr\inc \
          hal\video\fluency\include

# Define the specified compile options to COMP_DEFS
COMP_DEFS =


