# Define source file lists to SRC_LIST
SRC_LIST = hal\video\mpl\src\mpl_utility.c \
           hal\video\mpl\src\mpl_session.c \
           hal\video\mpl\src\mpl_parser.c \
           hal\video\mpl\src\mpl_vt.c

SRC_LIST += hal\video\mpl\src\mpl_video_recorder.c
SRC_LIST += hal\video\mpl\src\mpl_video_clipper.c

#
# MJPEG Encode
#
#ifneq ($(filter MJPG_ENCODE, $(strip $(MODULE_DEFS))),)
#  SRC_LIST += hal\video\mpl\src\avi_recorder.c
#endif
#
#ifneq ($(filter MP4_ENCODE, $(strip $(MODULE_DEFS))),)
#  SRC_LIST += hal\video\mpl\src\mp4_recorder.c
#endif

# Define include path lists to INC_DIR
INC_DIR = hal\video\common\include \
          hal\video\decoder\include \
          hal\video\vt_parser\include \
          hal\video\mpl\inc \
          hal\video\custom \
          hal\video\demuxer\provider\inc \
          hal\video\demuxer\mp4_parser\inc \
          hal\video\demuxer\avi_parser\inc \
          interface\hal\video \
          media\stream\include \
          sst\include \
          media\common\include \
          custom\video \
          hal\video\fluency\include \
          hal\system\dcmgr\inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS =


