# Define source file lists to SRC_LIST
SRC_LIST = init\src\l6478e.s \
           init\src\code_decompression.c 
           
ifneq ($(filter __ZIMAGE_SUPPORT__, $(strip $(MODULE_DEFS))),)
ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  SRC_LIST += plutommi\Framework\GUI\gui_src\bootup_logo.c
endif
endif
endif

ifneq ($(filter __MEUT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += init\src\meut_init.c
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
ifneq ($(filter $(COMPONENT),$(CUS_REL_PAR_SRC_COMP)),)

SRC_LIST := $(filter $(call Lower,$(SRC_LIST)),$(call Lower,$(CUS_REL_$(strip $(call Upper,$(COMPONENT)))_PAR_SRC_LIST)))
endif #CUS_REL_PAR_SRC_COMP
endif #CUSTOM_RELEASE

#  Define include path lists to INC_DIR
INC_DIR = inc \
          interface\l1interface \
          drv\include \
          interface\hal\system \
          hal\storage\flash\mtd\inc \
          hal\storage\flash\fdm\inc \
          hal\storage\mc\inc \
          hal\system\bootloader\inc \
          MCT\Source\MainLib\Include \
          sst\include \
          hal\dsp_ram \
          verno \
          hal\system\fota\inc \
          hal\system\cache\inc \
          ssf\inc \
          hal\system\CBR\inc \
          hal\system\GFH\public \
          sss\interface\inc \
          security\sds \
          interface\hal\graphics \
          interface\ps\include \
          plutommi\mmi\inc \
          plutommi\customer\custresource \
          hal\system\DP\inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK

COMP_DEFS += $(strip $(PLATFORM))

ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
  ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    ifdef EMMC_BOOTING
    ifeq ($(strip $(EMMC_BOOTING)),NONE)  
      COMP_DEFS += __BL_ENABLE__ \
                   REMAPPING
    endif
    else
      COMP_DEFS += __BL_ENABLE__ \
                   REMAPPING    
    endif
  endif
endif

ifneq ($(strip $(FOTA_ENABLE)),NONE)
  ifneq ($(strip $(FOTA_ENABLE)),)
    COMP_DEFS += __FOTA_ENABLE__
    ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      ifdef EMMC_BOOTING
      ifeq ($(strip $(EMMC_BOOTING)),NONE)
        COMP_DEFS += REMAPPING
      endif
      else
        COMP_DEFS += REMAPPING
      endif
    endif
  endif
endif

ifdef NAND_FLASH_BOOTING
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    COMP_DEFS  += _NAND_FLASH_BOOTING_
  endif
endif

ifdef EMMC_BOOTING
  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    COMP_DEFS  += __EMMC_BOOTING__
  endif
endif

ifeq ($(SWDBG_SUPPORT),TRUE)
  COMP_DEFS += __SWDBG_SUPPORT__
endif

ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
  COMP_DEFS += SINGLE_BANK_SUPPORT
  COMP_DEFS += REMAPPING
endif

