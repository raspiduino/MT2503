##############################################################
# Define ext bootloader internal configuration
##############################################################
BL_SLIM_SEG                = 16_3_SEG

##############################################################
# Define source file lists to SRC_LIST
##############################################################

SRC_LIST =  \
            hal\system\bootloader\src\bl_BOOTARM.S \
            hal\system\bootloader\src\bl_Cache.c \
            hal\system\bootloader\src\bl_DBGPRINT.C \
            hal\system\bootloader\src\bl_FOTA.c \
            hal\system\bootloader\src\bl_FTL.c \
            hal\system\bootloader\src\bl_GFH_body.c \
            hal\system\bootloader\src\bl_ImageLoader.c \
            hal\system\bootloader\src\bl_ImageLoaderCommon.c \
            hal\system\bootloader\src\bl_ImageLoader_v5.c \
            hal\system\bootloader\src\bl_Init.c \
            hal\system\bootloader\src\bl_Main.c \
            hal\system\bootloader\src\bl_NFI.c \
            hal\system\bootloader\src\bl_NFI_V3.c \
            hal\system\bootloader\src\bl_NFI_V31.c \
            hal\system\bootloader\src\bl_SNAND_V2.c \
            hal\system\bootloader\src\bl_portingfunc.c \
            hal\system\bootloader\src\bl_regioninit.s \
            hal\system\bootloader\src\bl_UART.C \
            hal\system\bootloader\src\bl_pdn.c \
            hal\system\bootloader\src\bl_Update.c \
            hal\system\bootloader\src\bl_FUNET.c \
            hal\system\bootloader\src\bl_Alg.c \
            hal\system\bootloader\src\bl_verno.c \
            hal\system\bootloader\src\drv_comm_bl.c \
            hal\system\bootloader\src\lcd_display.c \
            hal\system\bootloader\src\msdc_adap_bl.c \
            hal\system\bootloader\src\msdc_dma_bl.c \
            hal\system\bootloader\src\pmic_adpt_bl.c \
            hal\system\bootloader\src\usbdl_debug_tool.c \
            hal\system\bootloader\src\usbdl_pmu.c \
            hal\system\bootloader\src\usbdl_upll.c \
            hal\system\bootloader\src\usbdl_usb.c  \
            hal\system\bootloader\src\usbdl_usbacm_adap.c \
            hal\system\bootloader\src\usbdl_usbacm_drv.c \
            hal\system\bootloader\src\usbdl_usb_drv.c \
            hal\system\bootloader\src\usbdl_usb_resource.c \
            hal\system\init\src\arm_unaligned.s \
            hal\system\GFH\public\br_GFH_parser.c \
            hal\system\GFH\public\br_GFH_file_info.c \
            custom\system\$(strip $(BOARD_VER))\custom_blconfig.c \
            custom\common\hal\custom_flash.c \
            custom\common\hal\custom_SNAND.c \
            custom\common\hal\combo_flash_init.c \
            custom\system\$(strip $(BOARD_VER))\custom_img_config.c \
            $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,custom_hw_default.c) \
            $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,gpio_drv.c) \
            $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,keypad_def.c) \
            $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,usb_custom.c) \
            custom\drv\common_drv\nld_central_ctrl.c \
            custom\drv\common_drv\gpio_setting.c \
            hal\peripheral\src\dcl_gpio.c \
            hal\peripheral\src\gpio.c \
            custom\drv\common_drv\pwic_cust.c \
            hal\system\cache\src\cp15.s \
            hal\system\cache\src\cache.c \
            hal\system\pdn\src\pdn.c \
            hal\system\init\src\init_comm.c \
            hal\system\pdn\src\pdnoldarch.c \
            hal\peripheral\src\lpwr.c \
            hal\peripheral\src\pwm.c \
            hal\peripheral\src\dcl_rtc.c \
            hal\peripheral\src\rtc.c \
            hal\peripheral\src\f32k_clk.c \
            hal\peripheral\src\dcl_f32k_clk.c \
            hal\peripheral\src\bmt_bl_chr_setting.c \
            hal\peripheral\src\bmt_hw.c \
            hal\peripheral\src\dcl_pwm.c \
            hal\peripheral\src\pwm.c 
            
            
SRC_LIST += hal\system\CBR\src\CBR.c \
            hal\system\CBR\src\cbr_util.c

# PMU
SRC_LIST +=  hal\peripheral\src\dcl_pmu.c \
           hal\peripheral\src\dcl_pmu_common.c

ifeq ($(strip $(PMIC)),MT6235PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6235.c
endif
ifneq ($(filter MT6236PMU MT6921PMU, $(strip $(PMIC))),)
   SRC_LIST += hal\peripheral\src\dcl_pmu6236.c
endif
ifeq ($(strip $(PMIC)),MT6253PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6253.c
endif
ifeq ($(strip $(PMIC)),MT6326_CCCI)
   SRC_LIST += hal\peripheral\src\dcl_pmic6326_ccci.c
endif
#ifeq ($(strip $(PMIC)),MT6326)
#   SRC_LIST += hal\system\bootloader\src\usbdl_pmic6326.c
#endif

ifeq ($(strip $(PMIC)),MT6326)
   SRC_LIST += 	hal\peripheral\src\dcl_pmic6326.c \
                hal\peripheral\src\i2c_dual.c
   SRC_LIST +=  $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,pmic_custom.c)
endif
ifeq ($(strip $(PMIC)),MT6250PMU)
	SRC_LIST += hal\peripheral\src\dcl_pmu6250.c \
				hal\peripheral\src\dcl_pmu6250_init.c
endif
ifeq ($(strip $(PMIC)),MT6251PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6251.c
endif
ifeq ($(strip $(PMIC)),MT6252PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6252.c
endif
ifeq ($(strip $(PMIC)),MT6255PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6255.c \
               hal\peripheral\src\dcl_pmu6255_init.c
endif
ifeq ($(strip $(PMIC)),MT6256PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6256.c \
               hal\peripheral\src\dcl_pmu6256_init.c
endif
ifeq ($(strip $(PMIC)),MT6260PMU)
	SRC_LIST += hal\peripheral\src\dcl_pmu6260.c \
				hal\peripheral\src\dcl_pmu6260_init.c
endif
ifeq ($(strip $(PMIC)),MT6261PMU)
	SRC_LIST += hal\peripheral\src\dcl_pmu6261.c \
				hal\peripheral\src\dcl_pmu6261_init.c
endif
ifeq ($(strip $(PMIC)),MT6276PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6276.c
endif
ifeq ($(strip $(PMIC)),MT6573PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6573.c
endif

SRC_LIST +=  $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,pmu_custom.c)

FILE_EXIST = $(shell dir custom\codegen\$(strip $(BOARD_VER))\gpio_var.c /b 2>nul)
ifneq ($(words $(strip $(FILE_EXIST))),0)
  SRC_LIST += custom\codegen\$(strip $(BOARD_VER))\gpio_var.c
endif
     
SRC_LIST += hal\peripheral\src\keypad_bl.c
SRC_LIST += hal\peripheral\src\sw_keypad.c

SRC_LIST += custom\common\hal\custom_sfi.c

# eMMC driver
ifneq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,msdc_custom.c) \
              hal\storage\mc\src\msdc.c \
              hal\storage\mc\src\sd.c \
              hal\storage\mc\src\msdc_fake_kal.c \
              hal\storage\mc\src\dcl_memory_card.c \
              hal\storage\mc\src\sd_drv.c \
              hal\storage\mc\src\sd_adap.c
endif


# Add by Kuohong
# NAND driver build condition
# #if ( defined(__NAND_FDM_50__) && (defined(__NFI_VERSION2__)||defined(__NFI_VERSION3_1__)) )
ifneq ($(filter __NAND_FDM_50__, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __NFI_VERSION2__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\storage\flash\mtd\src\NAND_DAL.c
    SRC_LIST += hal\storage\flash\mtd\src\NAND_MTD_FDM50.c
    SRC_LIST += hal\storage\flash\mtd\src\NAND_DevConfig.c
  else 
     ifneq ($(filter __NFI_VERSION3_1__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += hal\storage\flash\mtd\src\NAND_DAL.c
       SRC_LIST += hal\storage\flash\mtd\src\NAND_MTD_FDM50.c
       SRC_LIST += hal\storage\flash\mtd\src\NAND_DevConfig.c
     endif
  endif
endif
ifneq ($(filter _NAND_FLASH_BOOTING_, $(strip $(MODULE_DEFS))),)
  ifeq ($(filter __NFI_VERSION3__, $(strip $(MODULE_DEFS))),)
    ifeq ($(filter __NFI_VERSION2__, $(strip $(MODULE_DEFS))),)    
    endif
  endif
else
 ifneq ($(filter __NOR_FLASH_BOOTING__, $(strip $(MODULE_DEFS))),)
  ifeq ($(filter __NFI_VERSION3__, $(strip $(MODULE_DEFS))),)
    ifeq ($(filter __NFI_VERSION2__, $(strip $(MODULE_DEFS))),)    
    endif
  endif 
 endif
endif
# Add by Kuohong


# For SPI-NAND (begin)
ifneq ($(filter __NAND_FDM_50__, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __SNAND_VERSION2__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\storage\flash\mtd\src\SPI_NAND_DAL.c
    SRC_LIST += hal\storage\flash\mtd\src\SPI_NAND_MTD_FDM50.c
    SRC_LIST += hal\storage\flash\mtd\src\SPI_NAND_DevConfig.c
    ifneq ($(filter __SNAND_STT_EN__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\storage\flash\mtd\src\bl_STT_SNAND.c
    endif
  endif
endif
# For SPI-NAND (end)

# NOR/SF driver
ifeq ($(filter _NAND_FLASH_BOOTING_, $(strip $(MODULE_DEFS))),)
ifeq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += custom\common\hal\combo_flash_init.c \
              custom\common\hal\combo_flash_nor.c \
              hal\storage\flash\mtd\src\flash_mtd_sf_common.c \
              hal\storage\flash\mtd\src\flash_cfi.c \
              hal\storage\flash\mtd\src\flash_disk.c \
              hal\storage\flash\mtd\src\flash_mtd.c \
              hal\storage\flash\mtd\src\flash_mtd_sf_dal.c \
              hal\storage\flash\mtd\src\flash_mtd_pf_dal.c \
              hal\storage\flash\mtd\src\flash_mtd.amd.c \
              hal\storage\flash\mtd\src\flash_mtd.intel.c \
              hal\storage\flash\mtd\src\bl_STT_SF.c \
              hal\system\emi\src\emi.c
endif
endif


ifdef FUNET_ENABLE
ifneq ($(strip $(FUNET_ENABLE)),NONE)
  
  # For LCD
  SRC_LIST += hal\display\fota\src\lcd_fota.c \
              hal\display\lcd_if_manager\src\lcd_if_manager.c \
              hal\display\common\src\lcm_proxy.c \
              hal\lqt\src\lcd_lqt.c \
              hal\system\compression\src\code_decompression_fota.c \
              hal\graphics\misc\src\simple_memory_manager.c

	FOLDER_LIST = custom\drv\LCD\$(strip $(LCD_MODULE))
	SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  	$(foreach FILE,$(shell if exist $(DIR)\*.c dir $(DIR)\*.c /b),$(DIR)\$(FILE)) \
	)
  
  # For Backlight
  SRC_LIST += $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,pwmdrv.c) \
              hal\peripheral\src\rtc.c \
              hal\peripheral\src\rwg.c \
              hal\peripheral\src\pwm.c \
              custom\common\ps\custom_uem.c \
              $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,custom_equipment.c) \
              $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,uem_gpio.c) \
              $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,custom_hw_default.c) \
              custom\codegen\$(strip $(BOARD_VER))\uem_drv.c

  #LCD only display picture in COSMOS/PLUTO project
  ifdef MMI_VERSION
    ifneq ($(filter COSMOS_MMI PLUTO_MMI,$(MMI_VERSION)),)
      SRC_LIST += hal\system\bootloader\src\gdi_image_alpha_bmp_v2_internal.c \
                  hal\system\bootloader\src\gdi_image_alpha_bmp_v2_core.c
    endif
  endif
  
  SRC_LIST += hal\peripheral\src\dcl_rtc.c \
              hal\peripheral\src\dcl_pwm.c \
              hal\peripheral\src\dcl_pw.c


  # IOT FOTA FS
  SRC_LIST += custom\system\$(strip $(BOARD_VER))\fs_config.c \
              fs\fat\src\Format.c \
              fs\efs\src\fs_bl_func.c \
              fs\efs\src\fs_utility.c \
              fs\fat\src\fs_bl_main.c \
              fs\fat\src\fs_kal.c \
              fs\fat\src\rtfcore.c \
              fs\fat\src\rtfbuf.c \
              fs\fat\src\rtfex.c \
              fs\efs\src\fs_internal.c\
              fs\common\src\fs_internal_api.c\
              fs\fat\src\rtfiles.c\
              fs\fat\src\rtfbs.c
#GPS fota
SRC_LIST += \
            hal\system\bootloader\src\gps_fota\brom_base.c \
            hal\system\bootloader\src\gps_fota\brom_mt3301.c \
            hal\system\bootloader\src\gps_fota\da_cmd.c \
            hal\system\bootloader\src\gps_fota\flashtool.c \
            hal\system\bootloader\src\gps_fota\gps_uart.C 

endif
endif

ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
  # For card
  SRC_LIST += $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,msdc_custom.c) \
              hal\storage\mc\src\msdc.c \
              hal\storage\mc\src\sd.c \
              hal\storage\mc\src\dcl_memory_card.c \
              hal\storage\mc\src\sd_drv.c \
              hal\storage\mc\src\msdc_fake_kal.c
              
  # For LCD
  SRC_LIST += hal\display\fota\src\lcd_fota.c \
              hal\display\lcd_if_manager\src\lcd_if_manager.c \
              hal\display\common\src\lcm_proxy.c \
              hal\lqt\src\lcd_lqt.c

	FOLDER_LIST = custom\drv\LCD\$(strip $(LCD_MODULE))
	SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  	$(foreach FILE,$(shell if exist $(DIR)\*.c dir $(DIR)\*.c /b),$(DIR)\$(FILE)) \
	)

  
  # For Backlight
  SRC_LIST += $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,pwmdrv.c) \
              hal\peripheral\src\rtc.c \
              hal\peripheral\src\rwg.c \
              hal\peripheral\src\pwm.c \
              custom\common\ps\custom_uem.c \
              $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,custom_equipment.c) \
              $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,uem_gpio.c) \
              $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,custom_hw_default.c) \
              custom\codegen\$(strip $(BOARD_VER))\uem_drv.c

  #LCD only display picture in COSMOS/PLUTO project
  ifdef MMI_VERSION
    ifneq ($(filter COSMOS_MMI PLUTO_MMI,$(MMI_VERSION)),)
      SRC_LIST += hal\system\bootloader\src\gdi_image_alpha_bmp_v2_internal.c \
                  hal\system\bootloader\src\gdi_image_alpha_bmp_v2_core.c
    endif
  endif
  
  SRC_LIST += hal\peripheral\src\dcl_rtc.c \
              hal\peripheral\src\dcl_pwm.c \
              hal\peripheral\src\dcl_pw.c

  ifeq ($(strip $(CARD_DOWNLOAD)),FILESYSTEM_ON_CARD)
    SRC_LIST += custom\system\$(strip $(BOARD_VER))\fs_config.c \
                fs\fat\src\Format.c \
                fs\efs\src\fs_bl_func.c \
                fs\efs\src\fs_utility.c \
                fs\fat\src\fs_bl_main.c \
                fs\fat\src\fs_kal.c \
                fs\fat\src\rtfcore.c \
                fs\fat\src\rtfbuf.c \
                fs\fat\src\rtfex.c
  endif

endif

ifneq ($(filter __FOTA_DM__,$(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\bootloader\src\bl_fota.c \
              custom\system\$(strip $(BOARD_VER))\custom_fota.c
endif
ifneq ($(filter __SV5_ENABLED__,$(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\bootloader\src\bl_gfh_body.c \
              hal\system\bootloader\src\bl_imageloader_v5.c
endif


ifneq ($(filter __DSP_FCORE4__,$(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\system\init\src\dmdsp_init.c
endif

ifdef FAST_LOGO_SUPPORT
  ifneq ($(strip $(FAST_LOGO_SUPPORT)),FALSE)

  # For LCD
  SRC_LIST += hal\display\fota\src\lcd_fota.c \
              hal\display\lcd_if_manager\src\lcd_if_manager.c \
              hal\display\common\src\lcm_proxy.c \
              hal\lqt\src\lcd_lqt.c

ifneq ($(filter MT6260, $(strip $(MODULE_DEFS))),)
  SRC_LIST += custom\drv\LCD\$(strip $(LCD_MODULE))\combo_lcm.c \
              custom\drv\LCD\$(strip $(LCD_MODULE))\combo_lcm_ILI9486.c \
              custom\drv\LCD\$(strip $(LCD_MODULE))\combo_lcm_R61529.c
else

  SRC_LIST += custom\drv\LCD\$(strip $(LCD_MODULE))\lcd.c

endif
  
  # For Backlight
  SRC_LIST += $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,pwmdrv.c) \
              hal\peripheral\src\rtc.c \
              hal\peripheral\src\rwg.c \
              hal\peripheral\src\pwm.c \
              custom\common\ps\custom_uem.c \
              $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,custom_equipment.c) \
              $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,uem_gpio.c) \
              $(call AUTO_MERGE_FILE_CHECK,custom\drv\misc_drv,custom_hw_default.c) \
              custom\codegen\$(strip $(BOARD_VER))\uem_drv.c

  # For ABM V2 decoder
  SRC_LIST += hal\system\bootloader\src\gdi_image_alpha_bmp_v2_internal.c \
              hal\system\bootloader\src\gdi_image_alpha_bmp_v2_core.c

  # For latching power in Bootloader
  SRC_LIST += hal\peripheral\src\dcl_rtc.c \
              hal\peripheral\src\dcl_pwm.c \
              hal\peripheral\src\dcl_pw.c \
              hal\peripheral\src\rtc.c \
              hal\peripheral\src\pw_bl.c
  endif
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
          custom\drv\misc_drv\$(strip $(BOARD_VER)) \
          hal\system\fota\inc \
          sss\interface\inc \
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
          plutommi\MMI\Inc \
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
          interface\hal\system \
          usb\include \
          interface\hal\peripheral \
          hal\system\DP\inc \
          custom\common\hal_public \
          hal\drv_def \
          interface\hal\storage \
          interface\fs \
          hal\system\funet\inc \
          hal\system\bootloader\inc\gps_fota


##############################################################
# Define the specified compile options to COMP_DEFS
##############################################################
COMP_DEFS = BL_ECC_ENABLE \
            __UBL__ \
            __EXT_BOOTLOADER__ \
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

ifdef FAST_LOGO_SUPPORT
  ifneq ($(strip $(FAST_LOGO_SUPPORT)),FALSE)
    COMP_DEFS += __FAST_LOGO__
    COMP_DEFS += __LCD_DRIVER_IN_BL__
    COMP_DEFS += __BG_IMAGE__
  endif
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

ifdef SERIAL_FLASH_STT_SUPPORT
  ifeq ($(strip $(SERIAL_FLASH_STT_SUPPORT)),TRUE)
    COMP_DEFS += __ADV_DBG_PRINT__
  endif
endif

ifdef SERIAL_FLASH_SUPPORT
  ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
    COMP_DEFS += __NOR_FULL_DRIVER__
  endif
endif

ifneq ($(filter __FS_IN_BL__, $(strip $(MODULE_DEFS))),)

  	SRC_LIST += custom\system\$(strip $(BOARD_VER))\fs_config.c \
            fs\fat\src\Format.c \
            fs\efs\src\fs_bl_func.c \
            fs\efs\src\fs_utility.c \
            fs\fat\src\fs_bl_main.c \
            fs\fat\src\fs_kal.c \
            fs\fat\src\rtfcore.c \
            fs\fat\src\rtfbuf.c \
            fs\fat\src\rtfex.c \
            fs\efs\src\fs_internal.c\
            fs\common\src\fs_internal_api.c\
            fs\fat\src\rtfiles.c\
            fs\fat\src\rtfbs.c
  
    COMP_DEFS += BL_DEBUG\
         __UBL_NOR_FULL_DRIVER__ \
         __NOR_FULL_DRIVER__ \
         __FS_FUNET_ENABLE__

endif

# TS_PROFILING := TRUE
ifeq ($(TS_PROFILING),TRUE)

COMP_DEFS += \
             __TIME_STAMP__ \
             __TIME_STAMP_UTIL__ \
             __TIME_STAMP_TDMA_TIMER__ \
             __TIME_STAMP_FORCE_ENABLE__

COMP_DEFS += BL_DEBUG

SRC_LIST += hal\system\bootloader\src\bl_time_stamp_util.c \
            hal\system\profile\src\br_time_stamp.c \
            hal\system\profile\src\time_stamp_timer.c

endif



ifdef FUNET_ENABLE
  ifneq ($(strip $(FUNET_ENABLE)),NONE)
    COMP_DEFS += BL_DEBUG
    COMP_DEFS += \
             __UBL_NOR_FULL_DRIVER__ \
             __NOR_FULL_DRIVER__ \
             __FS_FUNET_ENABLE__ \
             __GPS_FW_UPDATE_SUPPORT__

  endif
endif
