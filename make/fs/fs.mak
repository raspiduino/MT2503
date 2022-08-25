TARGET_SRC_LIST = fs\fat\src\fs_kal.c \
                  fs\fat\src\rtfbs.c \
                  fs\fat\src\rtfex.c \
                  fs\fat\src\format.c \
                  fs\fat\src\rtfiles.c \
                  fs\fat\src\rtfcore.c \
                  fs\fat\src\rtfbuf.c \
                  fs\common\src\fs_internal_api.c \
                  fs\common\src\fs_sst.c \
                  fs\Efs\src\fs_internal.c \
                  fs\Efs\src\fs_func.c \
                  fs\Efs\src\fs_func_adv.c \
                  fs\Efs\src\fs_func_async.c \
                  fs\Efs\src\fs_utility.c \
                  fs\Efs\src\fs_task.c \
                  fs\Efs\src\fs_usbms.c

MODIS_SRC_LIST = MoDIS_VC9\FileSystem\FileSystemSrc\FSSim_core.c \
                 MoDIS_VC9\FileSystem\FileSystemSrc\FSSim_data.c \
                 MoDIS_VC9\FileSystem\FileSystemSrc\FSSim_supplemental.c


# if defined(__FS_BENCHMARK__)
ifneq ($(filter __FS_BENCHMARK__, $(strip $(MODULE_DEFS))),)
  TARGET_SRC_LIST += fs\Efs\src\fs_task.c
endif

# if !defined(__SMART_PHONE_MODEM__) || !defined(__MTK_TARGET__)
ifeq ($(filter __SMART_PHONE_MODEM__, $(strip $(MODULE_DEFS))),)
	 TARGET_SRC_LIST += fs\Efs\src\fs_internal.c \
	                    fs\Efs\src\fs_func.c \
	                    fs\Efs\src\fs_func_adv.c
else
  ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
	 TARGET_SRC_LIST += fs\Efs\src\fs_internal.c \
	                    fs\Efs\src\fs_func.c \
	                    fs\Efs\src\fs_func_adv.c
  endif
endif

# if defined(__FS_TRACE_SUPPORT__)
ifneq ($(filter __FS_TRACE_SUPPORT__, $(strip $(MODULE_DEFS))),)
	TARGET_SRC_LIST += fs\Efs\src\fs_utility.c   
endif


# Define source file lists to SRC_LIST
ifneq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
 SRC_LIST = $(TARGET_SRC_LIST)
else
 ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
  SRC_LIST = $(TARGET_SRC_LIST)
 else
  SRC_LIST = $(MODIS_SRC_LIST)
 endif
endif
SRC_LIST += fs\fsal\src\fsal.c \
			fs\fsal\src\fsal_buffer.c \
			fs\fsal\src\fsal_read.c \
			fs\fsal\src\fsal_write.c
			
#  Define include path lists to INC_DIR
ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
 INC_DIR = fs\fat\include \
           fs\Efs\include \
           drv\include \
           fs\common\include
else
 ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
  INC_DIR = fs\fat\include \
            fs\Efs\include \
            drv\include \
            fs\common\include
 else
  INC_DIR = MoDIS_VC9\FileSystem\FileSystemInc
 endif
endif

ifneq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
else
 ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
 else
 endif
endif


# Define the specified compile options to COMP_DEFS
COMP_DEFS = NODEBUG
ifneq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
 COMP_DEFS = NODEBUG
else
 ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
  COMP_DEFS = NODEBUG
 else
  COMP_DEFS = 
 endif
endif

COMP_DEFS += CURR_MODULE=MOD_$(strip $(call Upper,$(COMPONENT))) 
