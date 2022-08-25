# Define source file lists to SRC_LIST
SRC_LIST = drm\src\drm_main.c \
           drm\src\drm_util.c \
           drm\src\drm_interface.c \
           drm\src\drm_http.c \
           drm\src\drm_ui.c \
           drm\src\drm_memory.c \
           drm\src\drm_consume.c \
           drm\src\drm_stime.c

#  Define include path lists to INC_DIR
INC_DIR = drm\include \
          drv\include \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          plutommi\MtkApp\RightsMgr\RightsMgrInc \
          plutommi\Framework\GDI\GDIInc \
          plutommi\MMI\MiscFramework\MiscFrameworkInc \
          plutommi\MMI\PROFILES\ProfilesInc \
          applib\misc\include \
          applib\inet\engine\include \
          dp_engine\che\include \
          applib\mem\include    \
          plutommi\mmi\Organizer\OrganizerInc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = __DRM_SEC_MTK__ \
            __DRM_CHE_UT__

