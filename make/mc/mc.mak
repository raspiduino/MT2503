# Define source file\ lists to SRC_LIST
SRC_LIST = hal\storage\mc\src\dcl_memory_card.c \
		   hal\storage\mc\src\msdc_fake_kal.c \
		   hal\storage\mc\src\msdc.c \
		   hal\storage\mc\src\usbms_msdc.c \
		   hal\storage\mc\src\msdc2.c \
		   hal\storage\mc\src\sdio_drv.c
		   
ifneq ($(filter __MAUI_BASIC__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += hal\storage\mc\src\msdc_test.c
endif

#SD/MMC memory card select.
ifneq ($(filter __MSDC_SD_MMC__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\storage\mc\src\sd.c \
                hal\storage\mc\src\sd_drv.c \
                hal\storage\mc\src\sd2.c \
                hal\storage\mc\src\sd_drv2.c \
                hal\storage\mc\src\sd_adap.c 
endif


#  Define include path lists to INC_DIR
INC_DIR = drv\include \
          hal\drv_def \
          hal\storage\mc\inc \
          inc \
          hal\bluetooth\btif\include \
          sst\include \
          hal\system\regbase\inc \
          hal\system\dma\inc \
          hal\system\counter\inc \
          hal\system\DP\inc


# Define the specified compile options to COMP_DEFS
COMP_DEFS =


