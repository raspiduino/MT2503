# Define source file lists to SRC_LIST
SRC_LIST_MP4ENC =

SRC_LIST =  hal\video_codec\interface\src\H264SwDecCustomize.c \
            hal\video_codec\interface\src\MP4SwDecCustomize.c \
            hal\video_codec\interface\src\RVSwDecCustomize.c \
            hal\video_codec\interface\src\VP8SwDecCustomize.c \
            hal\video_codec\interface\src\hal_custom_video_codec_internal.c \
            hal\video_codec\interface\src\vcodec_customization.c \
            hal\video_codec\interface\src\vcodec_demand_page.c \
            hal\video_codec\interface\src\vcodec_dcm.c
           
# Define include path lists to INC_DIR
INC_DIR =  hal\video_codec\video_codec_sec\sw_mp4_dec\include \
           hal\video_codec\video_codec_sec\sw_mp4_dec\src \
           hal\video_codec\video_codec_sec\sw_h264_dec\src \
           hal\video_codec\video_codec_sec\sw_h264_dec\include \
           hal\video_codec\video_codec_sec\mp4enc\include \
           hal\video_codec\video_codec_sec\mp4enc\src \
           hal\video_codec\video_codec_sec\video_msg \
           drv\include \
           media\common\include \
           media\audio\include \
           media\video\include \
           media\common\include \
           drm\include \
           media\video\include \
           hal\video\common\include \
           custom\common \
           hal\drv_def	\
           hal\video_codec\video_codec_sec\adaptor\inc \
           hal\video\video_sec\decoder\include \
           hal\video\decoder\include \
           hal\video\video_sec\encoder\include  \
           hal\video_codec\video_codec_sec\sw_rv9_dec\RV9_src_comm\include \
           hal\video_codec\video_codec_sec\sw_rv9_dec\RV9_src_LC\include \
           hal\video_codec\video_codec_sec\sw_rv9_dec\RV9_src_ST\include \
           hal\video_codec\interface\inc \
           hal\video_codec\video_codec_sec\sw_uvt_enc\include \
           hal\video_codec\video_codec_sec\sw_uvt_enc\src \
           custom\video \
           hal\video\custom \
           interface\hal\system \
           hal\system\dcmgr\inc \
           interface\hal\video_codec


# Define the specified compile options to COMP_DEFS
COMP_DEFS =



