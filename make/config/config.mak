# Define source file lists to SRC_LIST
SRC_LIST = config\src\hal\syscomp_config.c \
           config\src\hal\task_config.c \
           config\src\hal\stack_config.c \
           config\src\hal\ctrl_buff_pool.c

#  Define include path lists to INC_DIR
INC_DIR = interface\hwdrv \
          tst\include \
          tst\local_inc\
          hal\system\DP\inc
          
# Define the specified compile options to COMP_DEFS
COMP_DEFS = 

ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  ifeq ($(strip $(L1_3GSOLUTION)),MTK_UL1_FDD)
    # special for AST projects
    COMP_DEFS += __UL1_ON_MNT__
  endif
endif


