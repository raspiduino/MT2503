##############################################################
# Define mini bootloader internal configuration
##############################################################
CRYPTO_SHARED_DRV_PLATFORM = MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
NFI_SHARED_DRV_PLATFORM    = MT6255 MT6922 MT6260 MT6261 MT2501 MT2502
DIV_SLIM_PLATFORM          = MT6255 MT6922 MT6250 MT6260 MT6261 MT2501 MT2502
BL_SLIM_SEG                = 16_3_SEG 


ifneq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
CRYPTO_SHARED_DRV_PLATFORM += MT6276
endif

##############################################################
# Define source file lists to SRC_LIST
##############################################################

SRC_LIST =  \
            hal\system\bootloader\src\bl_BOOTARM.S \
            hal\system\bootloader\src\bl_Cache.c \
            hal\system\bootloader\src\bl_DBGPRINT.C \
            hal\system\bootloader\src\bl_FTL.c \
            hal\system\bootloader\src\bl_GFH_body.c \
            hal\system\bootloader\src\bl_ImageLoader.c \
            hal\system\bootloader\src\bl_ImageLoaderCommon.c \
            hal\system\bootloader\src\bl_ImageLoader_v5.c \
            hal\system\bootloader\src\bl_Init.c \
            hal\system\bootloader\src\bl_Main.c \
            hal\system\bootloader\src\bl_portingfunc.c \
            hal\system\bootloader\src\bl_regioninit.s \
            hal\system\bootloader\src\bl_UART.C \
            hal\system\bootloader\src\bl_verno.c \
            hal\system\bootloader\src\drv_comm_bl.c \
            hal\system\bootloader\src\bl_SNAND_V2.c \
            hal\system\bootloader\src\bl_NFI_V31.c \
            hal\system\bootloader\src\pmic_adpt_bl.c

ifeq ($(filter $(strip $(PLATFORM)), $(strip $(NFI_SHARED_DRV_PLATFORM))),)
SRC_LIST += \
            hal\system\bootloader\src\bl_NFI.c \
            hal\system\bootloader\src\bl_NFI_V3.c 
endif

SRC_LIST += interface\l1interface\l1_interface.c \
            custom\system\$(strip $(BOARD_VER))\custom_blconfig.c \
            custom\common\hal\custom_flash.c \
            $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,custom_hw_default.c) \
            custom\drv\common_drv\pwic_cust.c \
            custom\common\hal\combo_flash_init.c \
            hal\system\init\src\init_comm.c \
            hal\system\pll\src\pll.c \
            hal\system\cache\src\cp15.s \
            hal\system\cache\src\cache.c \
            hal\system\init\src\arm_unaligned.s \
            hal\system\GFH\public\br_GFH_parser.c \
            hal\system\GFH\public\br_GFH_file_info.c

SRC_LIST += hal\system\pdn\src\pdn.c \
            hal\system\pdn\src\pdnoldarch.c \
            hal\peripheral\src\lpwr.c \
            hal\peripheral\src\f32k_clk.c \
            hal\peripheral\src\dcl_f32k_clk.c\
            hal\peripheral\src\dcl_pwm.c\
            hal\peripheral\src\pwm.c
ifneq ($(filter MT6256, $(strip $(MODULE_DEFS))),)
    SRC_LIST += custom\common\hal\custom_emi_MT6256.c
else
    ifneq ($(filter MT6255, $(strip $(MODULE_DEFS))),)
        SRC_LIST += custom\common\hal\custom_emi_MT6255.c
    else
        ifneq ($(filter MT6250, $(strip $(MODULE_DEFS))),)
            SRC_LIST += custom\common\hal\custom_emi_MT6250.c
        else
            ifneq ($(filter MT6260, $(strip $(MODULE_DEFS))),)
                SRC_LIST += custom\common\hal\custom_emi_MT6260.c
            else
				        ifneq ($(filter MT6261, $(strip $(MODULE_DEFS))),)
					         SRC_LIST += custom\common\hal\custom_emi_MT6261.c
                else
                   ifneq ($(filter MT2501, $(strip $(MODULE_DEFS))),)
					            SRC_LIST += custom\common\hal\custom_emi_MT6261.c
                   else
                      ifneq ($(filter MT2502, $(strip $(MODULE_DEFS))),)
					               SRC_LIST += custom\common\hal\custom_emi_MT6261.c
                      else
					               SRC_LIST += custom\system\$(strip $(BOARD_VER))\custom_emi.c
					            endif
					         endif   
				        endif
            endif
        endif
    endif
endif

FILE_EXIST = $(shell dir custom\common\hal\custom_sfi.c /b 2>nul)
ifneq ($(words $(strip $(FILE_EXIST))),0)
  SRC_LIST += custom\common\hal\custom_sfi.c
endif

ifneq ($(filter __SV5_ENABLED__,$(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\bootloader\src\bl_gfh_body.c \
              hal\system\bootloader\src\bl_imageloader_v5.c
endif

# NOR/SF driver
ifeq ($(filter _NAND_FLASH_BOOTING_, $(strip $(MODULE_DEFS))),)
ifeq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += \
              hal\storage\flash\mtd\src\flash_mtd_sf_common.c \
              hal\storage\flash\mtd\src\flash_cfi.c \
              custom\common\hal\combo_flash_nor.c \
              hal\storage\flash\mtd\src\flash_disk.c \
              hal\storage\flash\mtd\src\flash_mtd.c \
              hal\storage\flash\mtd\src\flash_mtd_sf_dal.c \
              hal\storage\flash\mtd\src\flash_mtd_pf_dal.c \
              hal\storage\flash\mtd\src\flash_mtd.amd.c \
              hal\storage\flash\mtd\src\flash_mtd.intel.c \
              hal\system\emi\src\emi.c
endif
endif

# eMMC driver
ifneq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,msdc_custom.c) \
              hal\storage\mc\src\msdc.c \
              hal\storage\mc\src\sd.c \
              hal\storage\mc\src\msdc_fake_kal.c \
              hal\storage\mc\src\dcl_memory_card.c \
              hal\storage\mc\src\sd_drv.c \
              hal\storage\mc\src\sd_adap.c \
              hal\system\bootloader\src\msdc_dma_bl.c \
              hal\system\bootloader\src\usbdl_upll.c
endif

##############################################################
#  Define include path lists to INC_DIR
##############################################################
INC_DIR = hal\system\bootloader\inc \
          interface\hal\system \
          inc \
          hal\system\pll\inc \
          hal\system\cache\inc \
          drv\include \
          hal\storage\flash\mtd\inc \
          hal\storage\flash\fdm\inc \
          hal\storage\mc\inc \
          dp_engine\che\include \
          applib\misc\include \
          custom\codegen\$(strip $(BOARD_VER)) \
          custom\system\$(strip $(BOARD_VER)) \
          hal\system\fota\inc \
          ssf\inc \
          sst\include \
          fs\Efs\include \
          fs\fat\include \
          custom\common \
          custom\common\hal \
          custom\common\ps \
          interface\fs \
          interface\l1interface \
          interface\hwdrv \
          plutommi\Framework\GDI\GDIInc \
          plutommi\Customer\CustResource \
          sss\interface\inc \
          hal\system\CBR\inc \
          hal\system\GFH\public \
          hal\system\profile\inc \
          hal\peripheral\inc \
          hal\storage\mc\inc \
          hal\dsp_ram \
          security\sds \
          hal\display\ddv1\include \
          hal\display\ddv1\include\mt6236govl \
          hal\display\ddv1\include\mt6236lcd \
          hal\display\ddv1\include\mt6253lcd \
          hal\display\ddv1\include\mt6252lcd \
          hal\display\ddv1\include\mt6268lcd \
          hal\display\ddv1\include\mt6276lcd \
          hal\lqt\include \
          hal\display\common\include \
          interface\hal\display \
          interface\hal\display\ddv1 \
          interface\hal\peripheral\
          usb\include \
          hal\system\DP\inc

##############################################################
# Define the specified compile options to COMP_DEFS
##############################################################
COMP_DEFS = BL_ECC_ENABLE \
            __UBL__ \
            __MINI_BOOTLOADER__ \
            USBACM_TX_WITHOUT_DMA \
            BL_ENABLE \
            __CP_DEFINED_ALL_CONTEXT__ \
            __CP_DEFINED_WORKING_BUF__ \
            __CRYPTO_LIB__ \
            __CRYPTO_SCHEME__

ifneq ($(strip $(PLATFORM)),MT6251)
ifneq ($(strip $(PACKAGE_SEG)),32_32_SEG)
  COMP_DEFS += BL_DEBUG
endif
endif

ifneq ($(filter $(BL_SLIM_SEG), $(strip $(PACKAGE_SEG))),)
  COMP_DEFS    +=  __BL_SLIM_SEG__
endif

ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
  COMP_DEFS += BL_DEBUG
endif

ifdef CARD_DOWNLOAD
  ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
    COMP_DEFS += __CARD_DOWNLOAD__ 
    COMP_DEFS += __LCD_DRIVER_IN_BL__
    COMP_DEFS += __MSDC_NOT_SUPPORT_HOT_PLUG__
    #LCD only display picture in COSMOS/PLUTO project
    ifdef MMI_VERSION
      ifneq ($(filter COSMOS_MMI PLUTO_MMI,$(MMI_VERSION)),)
        COMP_DEFS += __BG_IMAGE__
      endif
    endif
  endif
endif

COMP_DEFS += $(strip $(PLATFORM))

ifneq ($(filter $(strip $(PLATFORM)),$(ARM9_PLATFORM)),)
  COMP_DEFS += ARM9_MMU
endif

ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
  COMP_DEFS  += _NAND_FLASH_BOOTING_
endif
    
ifdef EMMC_BOOTING
  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    COMP_DEFS  += __EMMC_BOOTING__
  endif
endif
    
ifneq ($(strip $(FOTA_ENABLE)),NONE)
  ifneq ($(strip $(FOTA_ENABLE)),)
    COMP_DEFS  += __FOTA_ENABLE__
  endif
endif

ifdef USB_DOWNLOAD_IN_BL
  ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
    COMP_DEFS += __USB_DOWNLOAD__
    ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
      COMP_DEFS += __SECURE_USB_DOWNLOAD__
    endif
  endif
endif

ifdef IC_TEST_TYPE
  ifneq ($(strip $(IC_TEST_TYPE)),NONE)
    COMP_DEFS += __SKIP_VERSION_CHECK_FOR_BTMT__
  endif
endif

ifdef CRYPTO_SHARED_DRV_PLATFORM
  ifneq ($(filter $(strip $(PLATFORM)), $(strip $(CRYPTO_SHARED_DRV_PLATFORM))),)
    COMP_DEFS += __CRYPTO_SHARED_DRV__
  endif
endif

ifdef NFI_SHARED_DRV_PLATFORM
  ifneq ($(filter $(strip $(PLATFORM)), $(strip $(NFI_SHARED_DRV_PLATFORM))),)
    COMP_DEFS += __NFI_SHARED_DRV__
  endif
endif

ifdef DIV_SLIM_PLATFORM
  ifneq ($(filter $(strip $(PLATFORM)), $(strip $(DIV_SLIM_PLATFORM))),)
    COMP_DEFS += __BL_SLIM_DIV__
  endif
endif

# TS_PROFILING := TRUE
ifeq ($(TS_PROFILING),TRUE)
  COMP_DEFS += __TIME_STAMP__ \
               __TIME_STAMP_UTIL__ \
               __TIME_STAMP_TDMA_TIMER__ \
               __TIME_STAMP_FORCE_ENABLE__
  COMP_DEFS += BL_DEBUG

  SRC_LIST += hal\system\bootloader\src\bl_time_stamp_util.c \
              hal\system\profile\src\br_time_stamp.c \
              hal\system\profile\src\time_stamp_timer.c
endif
