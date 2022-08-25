# Define source file lists to SRC_LIST
SRC_LIST = hal\mm_comm\src\mmsys_pwrmgr.c \
           hal\mm_comm\src\mm_power_ctrl.c \
           hal\mm_comm\src\mm_power_ctrl_mt6253.c \
           hal\mm_comm\src\mm_intmem_mt6253.c

ifneq ($(filter MULTI_MEDIA_EXIST, $(strip $(MODULE_DEFS))),)           
  SRC_LIST += hal\mm_comm\src\visual_comm.c \
           hal\mm_comm\src\visualhisr.c
endif
           
ifneq ($(filter MT6235, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6235.c
  SRC_LIST += hal\mm_comm\src\mm_intmem_mt6235.c
 else
  ifneq ($(filter MT6235B, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6235.c
    SRC_LIST += hal\mm_comm\src\mm_intmem_mt6235.c
  endif
endif

ifneq ($(filter MT6268, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6268.c
  SRC_LIST += hal\mm_comm\src\mm_intmem_mt6268.c
else
  ifneq ($(filter MT6268H, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6268.c
    SRC_LIST += hal\mm_comm\src\mm_intmem_mt6268.c
  endif
endif

ifneq ($(filter MT6236, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6236.c
  SRC_LIST += hal\mm_comm\src\mm_intmem_mt6236.c
else
  ifneq ($(filter MT6236B, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6236.c
    SRC_LIST += hal\mm_comm\src\mm_intmem_mt6236.c
  endif
endif

ifneq ($(filter MT6276, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6276.c
  SRC_LIST += hal\mm_comm\src\mm_intmem_mt6276.c
endif

ifneq ($(filter MT6255, $(strip $(MODULE_DEFS))),)
	SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6255.c
	SRC_LIST += hal\mm_comm\src\mm_intmem_mt6255.c
endif

ifneq ($(filter MT6250, $(strip $(MODULE_DEFS))),)
	SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6250.c
endif

ifneq ($(filter MT6260, $(strip $(MODULE_DEFS))),)
	SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6250.c
	SRC_LIST += hal\mm_comm\src\mm_pq_path_mt6260.c
endif

ifneq ($(filter MT6261, $(strip $(MODULE_DEFS))),)
	SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6250.c
	SRC_LIST += hal\mm_comm\src\mm_pq_path_mt6260.c
endif

ifneq ($(filter MT2501, $(strip $(MODULE_DEFS))),)
	SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6250.c
	SRC_LIST += hal\mm_comm\src\mm_pq_path_mt6260.c
endif

ifneq ($(filter MT2502, $(strip $(MODULE_DEFS))),)
	SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6250.c
	SRC_LIST += hal\mm_comm\src\mm_pq_path_mt6260.c
endif

ifneq ($(filter MT6256_S00, $(strip $(MODULE_DEFS))),)
	SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6256_e1.c
	SRC_LIST += hal\mm_comm\src\mm_intmem_mt6256_e1.c
endif

ifneq ($(filter MT6256_S01, $(strip $(MODULE_DEFS))),)
	SRC_LIST += hal\mm_comm\src\mm_power_ctrl_mt6256_e2.c
	SRC_LIST += hal\mm_comm\src\mm_intmem_mt6256_e2.c
endif

#  Define include path lists to INC_DIR
INC_DIR = drv\include \
          hal\storage\flash\mtd\inc \
          hal\storage\flash\fdm\inc \
          usb\include \
          inc \
          sst\include \
          media\image\include \
          dp_engine\che \
          applib\misc\include \
          ssf\inc \
          vendor\hp_fota\UA \
          irda\inc \
          hal\mm_comm\inc \
          hal\mdp\include \
          hal\drv_def \
          interface\hal \
          interface\hal\mm_comm \
          interface\hal\video \
          interface\hal\system \
          hal\system\regbase\inc \
          hal\system\dma\inc \
          hal\system\counter\inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = 

