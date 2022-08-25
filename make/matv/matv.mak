# Define source file lists to SRC_LIST

SRC_LIST = matv\src\matvctrl.c \
             matv\src\atv_api.c

ifneq ($(filter __ATV_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += matv\src\matv_task.c \
            matv\src\matv_common.c \
            custom\drv\mATV\$(strip $(ATV_CHIP))\matv_hostdrv.c \
            custom\drv\mATV\$(strip $(ATV_CHIP))\matv_drv.c \
            $(call AUTO_MERGE_FILE_CHECK,custom\drv\mATV,matv_cust.c)
endif
 
#  Define include path lists to INC_DIR
INC_DIR = custom\drv\mATV\$(strip $(ATV_CHIP)) \
          matv\inc \
          hal\system\dcmgr\inc
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK
