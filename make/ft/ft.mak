# Define source file lists to SRC_LIST
# in this case there should be only ft_main.c is compiled
# keep ft_create for kal config
# if !defined(__FACTORY_BIN__) && defined(__SPLIT_BINARY__)
FACTORY_BIN_COMBINATION = __SPLIT_BINARY__ __FACTORY_BIN__
ifeq ($(filter $(FACTORY_BIN_COMBINATION), $(strip $(MODULE_DEFS))), __SPLIT_BINARY__)
SRC_LIST = meta\ft\src\ft_dummy.c
else
SRC_LIST = meta\ft\src\ft_main.c \
           meta\ft\src\ft_mem.c \
           meta\ft\src\ft_report.c \
           meta\ft\src\ft_fnc.c \
           meta\ft\src\ft_fnc_l1rf.c \
           meta\ft\src\ft_fnc_audio.c \
           meta\ft\src\ft_fnc_misc.c \
           meta\ft\src\ft_fnc_nvram.c \
           meta\ft\src\ft_fnc_nfc.c \
           meta\ft\src\ft_fnc_fat.c \
           meta\ft\src\ft_fnc_fm.c \
           meta\ft\src\ft_fnc_custom.c \
           meta\ft\src\ft_fnc_misc_ex.c \
           meta\ft\src\ft_fnc_util.c
# Define optional source file
ifneq ($(filter __ATV_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += meta\ft\src\ft_fnc_matv.c
endif
ifneq ($(filter __BT_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += meta\ft\src\ft_fnc_bt.c
endif
ifneq ($(filter __WIFI_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += meta\ft\src\ft_fnc_wifi.c
endif
ifneq ($(filter __CMMB_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += meta\ft\src\ft_fnc_cmmb.c
endif
ifneq ($(filter __TDMB_SUPPORT__, $(strip $(MODULE_DEFS))),)
SRC_LIST += meta\ft\src\ft_fnc_tdmb.c
endif
ifneq ($(filter __UMTS_RAT__, $(strip $(MODULE_DEFS))),)
ifneq ($(filter __MTK_UL1_FDD__, $(strip $(MODULE_DEFS))),)
SRC_LIST += meta\ft\src\ft_fnc_wcdma.c
endif
endif

ifneq ($(filter __UMTS_TDD128_MODE__, $(strip $(MODULE_DEFS))),)
ifneq ($(filter __AST_TL1_TDD__, $(strip $(MODULE_DEFS))),)
SRC_LIST += meta\ft\src\ft_fnc_aux.c
endif
endif

SRC_LIST += meta\ft\src\ft_fnc_gps.c
endif
#  Define include path lists to INC_DIR
INC_DIR = meta\cct \
          interface\meta \
          interface\hal\audio \
          applib\misc\include \
          dp_engine\che\include \
          cmmb\hostdrv\inc \
          matv\inc \
          $(strip $(PS_FOLDER))\l4\include \
          hal\system\init\inc \
          meta\ft\inc \
          interface\nfc
INC_DIR += tst\local_inc
INC_DIR += interface\media\hal
INC_DIR += nvram\include
INC_DIR += interface\gps
INC_DIR += interface\hal\bluetooth

# Define the specified compile options to COMP_DEFS
COMP_DEFS =

# Define the source file search paths to SRC_PATH
SRC_PATH = meta\ft\src
