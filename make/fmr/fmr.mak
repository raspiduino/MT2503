# Define source file lists to SRC_LIST
SRC_LIST = fmr\src\fmr_main.c \
           fmr\src\mpll_freq_hopping_FM.c

ifneq ($(filter __FM_RADIO_RDS_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += fmr\src\fm_rds.c
endif

ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += fmr\src\fm_radio.c
endif
ifneq ($(filter __FM_AT_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += fmr\src\FMATCommand.c
endif
#  Define include path lists to INC_DIR
INC_DIR = fmr\inc \
          media\common\include \
          interface\hal\audio \
          interface\hal\fmr

# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK


