# Define source file lists to SRC_LIST
SRC_LIST =  hal\system\cache\src\cp15.s \
            hal\system\cache\src\cache.c \
            hal\system\pdn\src\pdnoldarch.c \
            hal\system\dma\src\dma.c \
            hal\system\pll\src\pll.c \
            hal\system\counter\src\uscounter.c  \
            hal\system\DP\src\fault.c \
            hal\system\pmu\src\arm11_pmu_montr.c \
            hal\system\GFH\public\br_GFH_parser.c \
            hal\system\GFH\public\br_GFH_file_info.c \
            hal\system\CBR\src\cbr.c \
            hal\system\CBR\src\cbr_util.c \
            hal\system\FTL\src\FTL.c \
            hal\system\excep_hdlr\src\excep_hdlr.c \
            hal\system\init\src\armlibc_rt.c \
            hal\system\init\src\nfb_loader.c \
            hal\system\init\src\idle_task.c \
            hal\system\init\src\info.c \
            hal\system\dcm\src\dcm_service.c \
            hal\system\compression\src\code_decompression_hal.c \
            hal\system\csci\src\AP_CSCI_dynamic.c

SRC_LIST +=  hal\system\AP_BtSS\src\AP_BtSS.c
ifeq ($(strip $(TINY_SYS)),TRUE)
  SRC_LIST +=  hal\system\AP_BtSS\src\AP_BtSS_save.s
  SRC_LIST +=  hal\system\csci\src\AP_CSCI_static.c
  SRC_LIST +=  hal\system\csd\src\AP_csd_trace.c
  SRC_LIST +=  hal\system\emi\src\emi_tiny.c
endif

ifneq ($(strip $(FUNET_ENABLE)),NONE)
   SRC_LIST +=  hal\system\funet\src\FUNET.c
endif

ifneq ($(strip $(DCM_MULTITRUNK)),NONE)
  SRC_LIST +=  hal\system\dcmgr\src\dcmgr_pl.c
else
  SRC_LIST +=  hal\system\dcmgr\src\dcmgr.c
endif

ifeq ($(strip $(DCM_DEBUG_SUITE_ENABLE)),TRUE)
  SRC_LIST +=  hal\system\dcmgr\src\dcm_intercept_c.c
  SRC_LIST +=  hal\system\dcmgr\src\dcm_intercept_a.s
endif


ifneq ($(filter __FOTA_DM__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\init\src\fota_nfb_loader.c 
endif

ifneq ($(filter __ARM_FPUV2__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\vfp\src\vfp.s
endif

ifneq ($(filter __VI_ENABLED__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\compression\src\viva.c
endif

ifneq ($(filter __EVENT_BASED_TIMER__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\timer\src\event_timer.c
endif

ifneq ($(filter __DSP_FCORE4__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\init\src\Dmdsp_init.c
endif

ifneq ($(filter __SMART_PHONE_MODEM__ , $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\system\ipc\src\fs_ccci.c \
                hal\system\ipc\src\ccci.c \
                hal\system\ipc\src\ccci_uart_drv.c \
                hal\system\ipc\src\ipc_msgsvc.c \
                drv\src\ipc_rpc.c \
                drv\src\ipc_rpc_cpsvc.c
  endif
  SRC_LIST += hal\system\emi\src\emimpu.c
endif

ifeq ($(filter __SMART_PHONE_MODEM__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\emi\src\emi.c
else
  SRC_LIST += hal\system\emi\src\emi.c
endif

ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
ifneq ($(filter __DSP_FCORE4__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\ipc\src\mdci.c
endif
endif

ifneq ($(filter DCM_ENABLE, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\system\dcm\src\dcm.c  hal\system\dcm\src\sleep.c
else
  ifneq ($(filter __MEUT__ __KTEST__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\system\dcm\src\dcm.c hal\system\dcm\src\sleep.c
  else
    ifeq ($(filter L1_NOT_PRESENT, $(strip $(MODULE_DEFS))),)
        SRC_LIST += hal\system\dcm\src\dcm.c hal\system\dcm\src\sleep.c
    endif
  endif
endif

ifneq ($(filter __MCU_DORMANT_MODE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\system\dcm\src\arm1176-dormantMode.s 
endif

ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\init\src\init.c \
              hal\system\init\src\init_comm.c \
              hal\system\init\src\init_trc.c \
              hal\system\init\src\boot_cert_pattern.c \
              hal\system\region\src\regioninit_ads.s \
              hal\system\region\src\stack.s \
              hal\system\cirq\src\Eint.c \
              hal\system\cirq\src\intrCtrl.c \
              hal\system\cirq\src\isrentry.c \
              hal\system\cirq\src\ADIE_Eint.c \
              hal\system\cirq\src\ADIE_intrCtrl.c \
              hal\system\cirq\src\irq.s \
              hal\system\region\src\init_memory_stack.c \
              hal\system\pdn\src\pdn.c \
              hal\system\init\src\bootarm.s \
              hal\system\init\src\misc.s \
              hal\system\init\src\armlibc_rt_heap.c \
              hal\system\init\src\armlibc_rt_io.c \
              hal\system\init\src\arm_unaligned.s \
              hal\system\init\src\third_rom_res.c
endif

ifneq ($(filter __SV5_ENABLED__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\GFH\public\maui_GFH_body.c 
endif

ifneq ($(filter __MT6255_CONCURRENCY_TEST__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\pmu\src\arm9_pmu_montr.c
endif

# Define include path lists to INC_DIR
INC_DIR = hal\system\cache\inc \
          hal\system\region\inc \
          interface\hal\system \
          hal\system\bootloader\inc \
          hal\system\cirq\inc \
          hal\system\counter\inc \
          hal\system\compression\inc \
          hal\system\dcm\inc \
          hal\system\AP_BtSS\inc \
          hal\system\dma\inc \
          hal\system\DP\inc \
          hal\system\emi\inc \
          hal\system\fota\inc \
          hal\system\init\inc \
          hal\system\ipc\inc \
          hal\system\pdn\inc \
          hal\system\pll\inc \
          hal\system\dcmgr\inc \
          hal\system\regbase\inc \
          hal\system\pmu\inc \
          hal\system\excep_hdlr\inc \
          hal\storage\flash\fdm\inc \
          hal\storage\mc\inc \
          inc \
          interface\l1interface \
          drv\include \
          hal\bluetooth\btif\include \
          MCT\Source\MainLib\Include \
          sst\include \
          verno \
          ssf\inc \
          sss\interface\inc \
          security\sds \
          hal\system\CBR\inc \
          hal\system\GFH\public \
          hal\dsp_ram \
          interface\hal\system \
          hal\peripheral\inc \
          interface\l1interface\internal \
          init\include \
          tst\local_inc \
          hal\system\funet\inc \
          interface\hal\system \
          hal\system\csci\inc
          
ifeq ($(strip $(TINY_SYS)),TRUE)
  INC_DIR += tiny_system\csd\logging\inc \
  	     kal\common\include
endif
 
ifneq ($(filter __ARM9_MMU__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\cache\src\mmu.c
endif

ifneq ($(filter __ARM11_MMU__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\cache\src\mmu.c
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK

COMP_DEFS += $(strip $(PLATFORM))


FORCE_NO_REMAPPING_PLATFORM = MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502

ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
      COMP_DEFS += __BL_ENABLE__
endif

ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
  ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    ifdef EMMC_BOOTING
    ifeq ($(strip $(EMMC_BOOTING)),NONE)  
      COMP_DEFS += __BL_ENABLE__
      ifeq ($(filter $(strip $(PLATFORM)),$(FORCE_NO_REMAPPING_PLATFORM)),)
        COMP_DEFS += REMAPPING
      endif
    endif
    else
      COMP_DEFS += __BL_ENABLE__
      ifeq ($(filter $(strip $(PLATFORM)),$(FORCE_NO_REMAPPING_PLATFORM)),)
        COMP_DEFS += REMAPPING
      endif
    endif
  endif
endif

ifneq ($(strip $(FOTA_ENABLE)),NONE)
  ifneq ($(strip $(FOTA_ENABLE)),)
    COMP_DEFS += __FOTA_ENABLE__
    ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      ifdef EMMC_BOOTING
      ifeq ($(strip $(EMMC_BOOTING)),NONE)
        ifeq ($(filter $(strip $(PLATFORM)),$(FORCE_NO_REMAPPING_PLATFORM)),)
        COMP_DEFS += REMAPPING
        endif
      endif
      else
        ifeq ($(filter $(strip $(PLATFORM)),$(FORCE_NO_REMAPPING_PLATFORM)),)
        COMP_DEFS += REMAPPING
        endif
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

ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
  COMP_DEFS += DCM_ENABLE
endif

ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
  COMP_DEFS += SINGLE_BANK_SUPPORT
      ifeq ($(filter $(strip $(PLATFORM)),$(FORCE_NO_REMAPPING_PLATFORM)),)
        COMP_DEFS += REMAPPING
      endif
endif

ifeq ($(strip $(DCM_COMPRESSION_MAUI_INIT)),TRUE)
	COMP_DEFS += __DCM_WITH_COMPRESSION_MAUI_INIT__
endif
###################################################################
# TimeStamp Profiling
###################################################################

# include path 
INC_DIR     +=  hal\system\profile\inc

# TS_PROFILING := TRUE
ifeq ($(TS_PROFILING),TRUE)

    # compile option
    COMP_DEFS   +=  __TIME_STAMP__\
                    __TIME_STAMP_UTIL__\
                    __TIME_STAMP_TDMA_TIMER__\
                    __TIME_STAMP_FORCE_ENABLE__

    # source flle list 
    SRC_LIST    +=  hal\system\profile\src\br_time_stamp.c\
                    hal\system\profile\src\maui_time_stamp_util.c\
                    hal\system\profile\src\time_stamp_timer.c

endif

# SRC_RULE_PREPROCESS means the asm file needs to be preprocessed by armcc -E and then armasm
SRC_RULE_PREPROCESS = bootarm.s

