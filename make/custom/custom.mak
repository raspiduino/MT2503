# Define source file lists to SRC_LIST
# Define source file folder to SRC_LIST

AUTO_MERGE_FOLDER = custom\audio custom\drv\camera custom\drv\misc_drv

ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
   AUDFOLDER         =  hal\audio\src\v2
else
   ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
      AUDFOLDER         =  hal\audio\src\v1\sp
   else
      AUDFOLDER         =  hal\audio\src\v1
   endif
endif
INC_DIR =
COMP_DEFS =
FOLDER_LIST = custom\drv\misc_drv\$(strip $(BOARD_VER)) \
              custom\system\$(strip $(BOARD_VER)) \
              custom\ps\$(strip $(BOARD_VER)) \
              custom\common \
              custom\app\$(strip $(BOARD_VER)) \
              custom\codegen\$(strip $(BOARD_VER)) \
              custom\l1_rf\$(strip $(RF_MODULE)) \
              custom\tst \
              custom\atci\src \
              custom\common\hal \
              custom\common\hal_public \
              custom\common\ps \
              custom\common\hal\nvram \
              custom\drv\measure \
              custom\drv\LCD\$(strip $(LCD_MODULE)) \
              custom\drv\color\$(strip $(LCD_MODULE))

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
  FOLDER_LIST += custom\common\$(strip $(MMI_BASE)) custom\audio\$(strip $(BOARD_VER)) custom\meta\$(strip $(BOARD_VER))
endif

ifdef JOGBALL_SUPPORT
  ifneq ($(filter OFN,$(JOGBALL_SUPPORT)),)
    FOLDER_LIST += custom\drv\misc_drv\$(strip $(BOARD_VER))
    INC_DIR += custom\drv\misc_drv\$(strip $(BOARD_VER))
    SRC_LIST += custom\drv\misc_drv\$(strip $(BOARD_VER))\ofn_main.c
  endif
endif

ifdef TOUCH_PANEL_SUPPORT
  ifneq ($(filter CTP_%,$(TOUCH_PANEL_SUPPORT)),)
    FOLDER_LIST += custom\drv\CTP_module\$(strip $(TOUCH_PANEL_SUPPORT))
    INC_DIR += custom\drv\CTP_module\$(strip $(TOUCH_PANEL_SUPPORT))
    FOLDER_LIST += custom\drv\CTP_module\common
    INC_DIR += custom\drv\CTP_module\common
  endif
endif

SRC_LIST += custom\drv\common_drv\gpio_setting.c \
           custom\drv\common_drv\pwic_cust.c \
           custom\drv\common_drv\nld_central_ctrl.c

INC_DIR += interface\hal\peripheral
INC_DIR += interface\ata
INC_DIR += plutommi\mmi\inc
INC_DIR += hal\system\dcmgr\inc
           

FOLDER_CHECK = $(shell dir custom\drv\fmr\$(strip $(BOARD_VER))\*.c /b 2>nul)
ifneq ($(words $(strip $(FOLDER_CHECK))),0)
  FOLDER_LIST += custom\drv\fmr\$(strip $(BOARD_VER))
  INC_DIR += custom\drv\fmr\$(strip $(BOARD_VER))
else
  FOLDER_CHECK = $(shell dir custom\drv\fmr\default_bb\*.c /b 2>nul)
  ifneq ($(words $(strip $(FOLDER_CHECK))),0)
    FOLDER_LIST += custom\drv\fmr\default_bb
    INC_DIR += custom\drv\fmr\default_bb
  endif
endif

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
  ifneq ($(call Upper,$(strip $(PROJECT))),L1S)

    ifdef PROXIMITY_SENSOR
      ifneq ($(strip $(PROXIMITY_SENSOR)),NONE)
        INC_DIR += custom\drv\Proximity_Sensor\$(PROXIMITY_SENSOR)
        FOLDER_LIST += custom\drv\Proximity_Sensor\$(PROXIMITY_SENSOR) # Tell preprocessor to add files to xxx.lis
        # No need to add custom\drv\misc_drv\$(strip $(BOARD_VER))\pxs_custom.c, because first FOLDER_LIST line has added whole folder
        INC_DIR += custom\drv\misc_drv\$(strip $(BOARD_VER))
      endif
    endif

    ifdef CMOS_SENSOR
      ifneq ($(strip $(CMOS_SENSOR)),NONE)
        FOLDER_LIST += custom\drv\camera\$(strip $(BOARD_VER))
        INC_DIR += custom\drv\camera\$(strip $(BOARD_VER))
        ifeq ($(strip $(ISP_SUPPORT)),TRUE)
          SRC_LIST += custom\drv\Camera_common\camera_sccb.c \
                      custom\drv\Camera_common\image_sensor.c \
                      custom\drv\Camera_common\lens_module.c \
                      custom\drv\Camera_common\sensor_frame_rate_lut.c

          # Use custom\drv\camera\$(strip $(BOARD_VER))\camera_tuning_oper.c not use custom\drv\Camera_common\camera_tuning_oper.c if it existed.
          FILE_CHECK = $(shell dir custom\drv\camera\$(strip $(BOARD_VER))\camera_tuning_oper.c /b 2>nul)
          ifeq ($(words $(strip $(FILE_CHECK))),1)
          else
            SRC_LIST += custom\drv\Camera_common\camera_tuning_oper.c
          endif
          
          FILE_CHECK = $(shell dir custom\drv\camera\$(strip $(BOARD_VER))\camera_tuning_para.c /b 2>nul)
          ifeq ($(words $(strip $(FILE_CHECK))),1)
          else
            SRC_LIST += custom\drv\Camera_common\camera_tuning_para.c
          endif

          INC_DIR += custom\drv\Camera_common
        endif
      endif

      ifeq ($(strip $(SENSOR_TYPE)),RAW)
        SENSOR_MODULE_FOLDER = $(shell dir custom\drv\image_sensor\$(strip $(CMOS_SENSOR)) /b 2>nul)
        ifneq ($(words $(strip $(SENSOR_MODULE_FOLDER))),0)
          FOLDER_LIST += custom\drv\image_sensor\$(strip $(CMOS_SENSOR))
          INC_DIR += custom\drv\image_sensor\$(strip $(CMOS_SENSOR))
        else
          $(error ERROR:The folder( custom\drv\image_sensor\$(strip $(CMOS_SENSOR))) is not existed,please check CMOS_SENSOR setting)
        endif
      endif

      ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
        ifeq ($(strip $(SENSOR_TYPE)),YUV)
          SENSOR_MODULE_FOLDER = $(shell dir custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR)) /b 2>nul)
          ifneq ($(words $(strip $(SENSOR_MODULE_FOLDER))),0)
            FOLDER_LIST += custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR))
            INC_DIR += custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR))
          else
            $(error ERROR:The folder( custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR)) ) is not existed,please check CMOS_SENSOR setting)
          endif
        endif
      endif

      ifeq ($(strip $(SENSOR_TYPE)),JPEG)
        SENSOR_MODULE_FOLDER = $(shell dir custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR)) /b 2>nul)
        ifneq ($(words $(strip $(SENSOR_MODULE_FOLDER))),0)
          FOLDER_LIST += custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR))
          INC_DIR += custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR))
        else
          $(error ERROR:The folder( custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR)) ) is not existed,please check CMOS_SENSOR setting)
        endif
      endif

      ifeq ($(strip $(SENSOR_TYPE)),DIRECT)
        SRC_LIST += custom\drv\direct_sensor\camera_para_noon010pc20.c \
                    custom\drv\direct_sensor\camera_para_noon010pc30.c \
                    custom\drv\direct_sensor\camera_para_OV6680.c \
                    custom\drv\direct_sensor\camera_para_OV6690.c \
                    custom\drv\direct_sensor\camera_para_PAS6167.c \
                    custom\drv\direct_sensor\camera_para_PO4010K.c \
                    custom\drv\direct_sensor\camera_para_SIA100A.c \
                    custom\drv\direct_sensor\camera_para_SIC110A.c \
                    custom\drv\direct_sensor\image_sensor_common.c
        INC_DIR += custom\drv\direct_sensor
      endif
    endif

    ifdef CMOS_SENSOR_SUB
      ifneq ($(strip $(CMOS_SENSOR_SUB)),NONE)
        FOLDER_LIST += custom\drv\camera\$(strip $(BOARD_VER))
        INC_DIR += custom\drv\camera\$(strip $(BOARD_VER))
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          SENSOR_MODULE_FOLDER = $(shell dir custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB)) /b 2>nul)
          ifneq ($(words $(strip $(SENSOR_MODULE_FOLDER))),0)
            FOLDER_LIST += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB))
            INC_DIR += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB))
          else
            $(error ERROR:The folder( custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB)) ) is not existed,please check CMOS_SENSOR setting)
          endif
        endif

        ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
          ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
            SENSOR_MODULE_FOLDER = $(shell dir custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB)) /b 2>nul)
            ifneq ($(words $(strip $(SENSOR_MODULE_FOLDER))),0)
              FOLDER_LIST += custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB))
              INC_DIR += custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB))
            else
              $(error ERROR:The folder( custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB)) ) is not existed,please check CMOS_SENSOR setting)
            endif
          endif
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),JPEG)
          SENSOR_MODULE_FOLDER = $(shell dir custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_SUB)) /b 2>nul)
          ifneq ($(words $(strip $(SENSOR_MODULE_FOLDER))),0)
            FOLDER_LIST += custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_SUB))
            INC_DIR += custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_SUB))
          else
            $(error ERROR:The folder( custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_SUB)) ) is not existed,please check CMOS_SENSOR setting)
          endif
        endif
      endif
    endif

    ifdef CMOS_SENSOR_BAK1
      ifneq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
        FOLDER_LIST += custom\drv\camera\$(strip $(BOARD_VER))
        INC_DIR += custom\drv\camera\$(strip $(BOARD_VER))
        ifeq ($(strip $(SENSOR_TYPE)),RAW)
          SENSOR_MODULE_FOLDER = $(shell dir custom\drv\image_sensor\$(strip $(CMOS_SENSOR_BAK1)) /b 2>nul)
          ifneq ($(words $(strip $(SENSOR_MODULE_FOLDER))),0)
            FOLDER_LIST += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_BAK1))
            INC_DIR += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_BAK1))
          else
            $(error ERROR:The folder( custom\drv\image_sensor\$(strip $(CMOS_SENSOR_BAK1)) ) is not existed,please check CMOS_SENSOR setting)
          endif
        endif

        ifeq ($(strip $(SENSOR_TYPE)),YUV)
          SENSOR_MODULE_FOLDER = $(shell dir custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_BAK1)) /b 2>nul)
          ifneq ($(words $(strip $(SENSOR_MODULE_FOLDER))),0)
            FOLDER_LIST += custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_BAK1))
            INC_DIR += custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_BAK1))
          else
            $(error ERROR:The folder( custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_BAK1)) ) is not existed,please check CMOS_SENSOR setting)
          endif
        endif

        ifeq ($(strip $(SENSOR_TYPE)),JPEG)
          SENSOR_MODULE_FOLDER = $(shell dir custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_BAK1)) /b 2>nul)
          ifneq ($(words $(strip $(SENSOR_MODULE_FOLDER))),0)
            FOLDER_LIST += custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_BAK1))
            INC_DIR += custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_BAK1))
          else
            $(error ERROR:The folder( custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_BAK1)) ) is not existed,please check CMOS_SENSOR setting)
          endif
        endif

      endif
    endif

    ifdef CMOS_SENSOR_SUB_BAK1
      ifneq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
        FOLDER_LIST += custom\drv\camera\$(strip $(BOARD_VER))
        INC_DIR += custom\drv\camera\$(strip $(BOARD_VER))
        ifeq ($(strip $(SENSOR_TYPE)),RAW)
          SENSOR_MODULE_FOLDER = $(shell dir custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1)) /b 2>nul)
          ifneq ($(words $(strip $(SENSOR_MODULE_FOLDER))),0)
            FOLDER_LIST += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
            INC_DIR += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
          else
            $(error ERROR:The folder( custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1)) ) is not existed,please check CMOS_SENSOR setting)
          endif
        endif

        ifeq ($(strip $(SENSOR_TYPE)),YUV)
          SENSOR_MODULE_FOLDER = $(shell dir custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1)) /b 2>nul)
          ifneq ($(words $(strip $(SENSOR_MODULE_FOLDER))),0)
            FOLDER_LIST += custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
            INC_DIR += custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
          else
            $(error ERROR:The folder( custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1)) ) is not existed,please check CMOS_SENSOR setting)
          endif          
        endif

        ifeq ($(strip $(SENSOR_TYPE)),JPEG)
          SENSOR_MODULE_FOLDER = $(shell dir custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1)) /b 2>nul)
          ifneq ($(words $(strip $(SENSOR_MODULE_FOLDER))),0)
            FOLDER_LIST += custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
            INC_DIR += custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
          else
            $(error ERROR:The folder( custom\drv\JPEG_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1)) ) is not existed,please check CMOS_SENSOR setting)
          endif
        endif
                
      endif
    endif

    ifdef LENS_MODULE
      ifneq ($(strip $(LENS_MODULE)),NONE)
        SRC_LIST += custom\drv\lens_module\$(strip $(LENS_MODULE))\lens_module_$(strip $(LENS_MODULE)).c
        INC_DIR += custom\drv\lens_module\$(strip $(LENS_MODULE))
      endif
    endif

    ifdef LENS_MODULE_BAK1
      ifneq ($(strip $(LENS_MODULE_BAK1)),NONE)
        SRC_LIST += custom\drv\lens_module\$(strip $(LENS_MODULE_BAK1))\lens_module_$(strip $(LENS_MODULE_BAK1)).c
        INC_DIR += custom\drv\lens_module\$(strip $(LENS_MODULE_BAK1))
      endif
    endif

    ifdef E_COMPASS_SENSOR_SUPPORT
      ifneq ($(strip $(E_COMPASS_SENSOR_SUPPORT)),NONE)
        SRC_LIST += custom\drv\e_compass_sensor\$(strip $(E_COMPASS_SENSOR_SUPPORT))\e_compass_sensor_custom.c
        INC_DIR += custom\drv\e_compass_sensor\$(strip $(E_COMPASS_SENSOR_SUPPORT))
      endif
    endif

    ifdef MOTION_SENSOR_SUPPORT
      ifneq ($(strip $(MOTION_SENSOR_SUPPORT)),NONE)
        FOLDER_LIST += custom\drv\motion_sensor\$(strip $(MOTION_SENSOR_SUPPORT))
        INC_DIR += custom\drv\motion_sensor\$(strip $(MOTION_SENSOR_SUPPORT))
      endif
    endif

    # WIFI_SUPPORT
    ifdef WIFI_SUPPORT
      ifneq ($(strip $(WIFI_SUPPORT)),NONE)
        SRC_LIST += custom\drv\wifi\$(strip $(BOARD_VER))\wndrv_configure.c

        ifeq ($(strip $(WIFI_SUPPORT)),MT5911)
          INC_DIR += custom\drv\wifi\$(strip $(BOARD_VER)) \
                     wifi\wndrv\include\hal \
                     wifi\wndrv\include\hal\mt5911 \
                     wifi\wndrv\include\mgmt \
                     wifi\wndrv\include\os \
                     wifi\wndrv\include
          COMP_DEFS += MT5911 \
                       DBG=0 \
                       BUILD_AP=0 \
                       BUILD_CCX=0 \
                       BUILD_WMM=0 \
                       BUILD_11A=0 \
                       BUILD_11G=1 \
                       BUILD_11H=0 \
                       BUILD_11D=0 \
                       BUILD_SW_ENCRYPT=0
        endif

        ifeq ($(strip $(WIFI_SUPPORT)),MT5921)
          INC_DIR += custom\drv\wifi\$(strip $(BOARD_VER))
          COMP_DEFS += MT5921 \
                       _HIF_HPI \
                       DBG=0 \
                       BUILD_AP=0 \
                       BUILD_CCX=0 \
                       BUILD_WMM=0 \
                       BUILD_11A=0 \
                       SUPPORT_802_11A=0 \
                       BUILD_11G=1 \
                       SUPPORT_802_11G=1 \
                       BUILD_11H=0 \
                       BUILD_11D=0 \
                       BUILD_SW_ENCRYPT=0 \
                       BUILD_PTA=1 \
                       SUPPORT_WPS=0 \
                       CFG_FAKE_THERMO_VALUE_DBG_EN=0 \
                       MT5911_BB=0 \
                       MT5921_BB=0 \
                       WNDRV_EEPROM_USAGE=0 \
                       SUPPORT_EHPI_8=1 \
                       BUILD_QA_DBG=0 \
                       WCP_MAUI
        endif
        
        ifeq ($(strip $(WIFI_SUPPORT)),MT5931)
          INC_DIR += custom\drv\wifi\$(strip $(BOARD_VER)) \
                     wifi\wndrv\$(strip $(WIFI_SUPPORT))\include \
						wifi\wndrv\$(strip $(WIFI_SUPPORT))\include\mgmt \
						wifi\wndrv\$(strip $(WIFI_SUPPORT))\include\nic \
						wifi\wndrv\$(strip $(WIFI_SUPPORT))\include\os \
						wifi\wndrv\$(strip $(WIFI_SUPPORT))\os \
						wifi\wndrv\$(strip $(WIFI_SUPPORT))\os\include \
						wifi\wndrv\$(strip $(WIFI_SUPPORT))\os\hif\ehpi\include
          COMP_DEFS += MT5931 \
           			   _HIF_HPI \
					   _HIF_EHPI \
					   SUPPORT_EHPI_8=1 \
					   WCN_MAUI
        endif
        
      endif
    endif

	ifdef WIFI_SUPPORT
      ifneq ($(strip $(WIFI_SUPPORT)),NONE)
		SRC_LIST += custom\common\custom_wlan_ui_config.c
      endif
    endif
    
    # BLUETOOTH_SUPPORT
    ifdef BLUETOOTH_SUPPORT
      ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
        FOLDER_LIST += custom\drv\bluetooth\$(strip $(BOARD_VER))
        INC_DIR += custom\drv\bluetooth\$(strip $(BOARD_VER))
      endif
    endif

    # GPS_SUPPORT
    ifdef GPS_SUPPORT
      ifneq ($(strip $(GPS_SUPPORT)),NONE)
        SRC_LIST +=  custom\drv\gps\$(strip $(BOARD_VER))\gpsmtk_config.c
        INC_DIR += custom\drv\gps\$(strip $(BOARD_VER)) \
                   gps\inc
      endif
    endif

    # BT_GPS_SUPPORT
    ifdef BT_GPS_SUPPORT
      ifneq ($(strip $(BT_GPS_SUPPORT)),FALSE)
        SRC_LIST +=  custom\drv\gps\$(strip $(BOARD_VER))\gpsmtk_config.c
      endif
    endif

    # FLASHLIGHT_MODULE
    ifdef FLASHLIGHT_TYPE
      ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT_ANTI_RED_EYE)
        ifdef FLASHLIGHT_TYPE
          ifneq ($(strip $(FLASHLIGHT_TYPE)),NONE)
            SRC_LIST += custom\drv\Flashlight_module\$(strip $(FLASHLIGHT_MODULE))\xenon_flashlight.c
          endif
        endif
      endif
      ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT)
        ifdef FLASHLIGHT_TYPE
          ifneq ($(strip $(FLASHLIGHT_TYPE)),NONE)
            SRC_LIST += custom\drv\Flashlight_module\$(strip $(FLASHLIGHT_MODULE))\xenon_flashlight.c
          endif
        endif
      endif
    endif


    # CMMB_SUPPORT
    ifdef CMMB_SUPPORT
      ifneq ($(strip $(CMMB_SUPPORT)),NONE)
        FOLDER_LIST += custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Adaption\src \
                       custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Demod\src
        INC_DIR += cmmb\hostdrv\inc \
                   drv\src \
                   custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Adaption\inc \
                   custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Demod\inc
      endif
      
      ifneq ($(filter SIANO_%,$(CMMB_SUPPORT)),)
        FOLDER_LIST += custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Adaption\src \
                       custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Demod\src \
                       custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\smshostlib_lite\platforms\Nucleus\ADR \
                       custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\smshostlib_lite\platforms\Nucleus\OSW \
                       custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\smshostlib_lite\platforms\Nucleus\OSW\Src \
                       custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\smshostlib_lite\platforms\Nucleus\SPIDriver\Src \
                       custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\smshostlib_lite\src
      endif
    endif
  endif
endif

ifneq ($(call Upper,$(strip $(PROJECT))),L1S)
  # EXTERNL_CHARGER
  ifdef EXTERNL_CHARGER
    ifneq ($(strip $(EXTERNL_CHARGER)),NONE)
      SRC_LIST +=  custom\drv\Ext_Charger\$(strip $(EXTERNL_CHARGER))
    endif
  endif

  # EXTERNAL_CHARGER_DETECTION
  ifdef EXTERNAL_CHARGER_DETECTION
    ifneq ($(strip $(EXTERNAL_CHARGER_DETECTION)),NONE)
      SRC_LIST +=  custom\drv\Ext_Cable_Detection\$(strip $(EXTERNAL_CHARGER_DETECTION))\ext_cable_det_accessory_if.c \
                   custom\drv\Ext_Cable_Detection\$(strip $(EXTERNAL_CHARGER_DETECTION))\ext_cable_det_charger_if.c \
                   custom\drv\Ext_Cable_Detection\$(strip $(EXTERNAL_CHARGER_DETECTION))\ext_cable_det_fac_if.c \
                   custom\drv\Ext_Cable_Detection\$(strip $(EXTERNAL_CHARGER_DETECTION))\ext_cable_det_$(strip $(EXTERNAL_CHARGER_DETECTION))_drv.c
    endif
  endif

  # EXTERNAL_ACCESSORY_DETECTION
  ifdef EXTERNAL_ACCESSORY_DETECTION
    ifneq ($(strip $(EXTERNAL_ACCESSORY_DETECTION)),NONE)
      SRC_LIST +=  custom\drv\Ext_Cable_Detection\$(strip $(EXTERNAL_ACCESSORY_DETECTION))\ext_cable_det_accessory_if.c \
                   custom\drv\Ext_Cable_Detection\$(strip $(EXTERNAL_ACCESSORY_DETECTION))\ext_cable_det_charger_if.c \
                   custom\drv\Ext_Cable_Detection\$(strip $(EXTERNAL_ACCESSORY_DETECTION))\ext_cable_det_fac_if.c \
                   custom\drv\Ext_Cable_Detection\$(strip $(EXTERNAL_ACCESSORY_DETECTION))\ext_cable_det_$(strip $(EXTERNAL_ACCESSORY_DETECTION))_drv.c
    endif
  endif

  # CUSTOMER_SPECIFIC_FACTORY_DETECTION
  ifdef CUSTOMER_SPECIFIC_FACTORY_DETECTION
    ifneq ($(strip $(CUSTOMER_SPECIFIC_FACTORY_DETECTION)),NONE)
      SRC_LIST +=  custom\drv\CS_Fac_Det\$(strip $(CUSTOMER_SPECIFIC_FACTORY_DETECTION))\cs_fac_det_type_1.c
    endif
  endif
endif


# External device common ASSERT handler
# Always build the specific folder
SRC_LIST += custom\drv\Ext_Drv_Assert_Hdlr\ext_drv_assert_hdlr_if.c
INC_DIR += custom\drv\Ext_Drv_Assert_Hdlr

# AST HIF driver
SRC_LIST += custom\drv\ast\ast_hif_hw.c
INC_DIR += custom\drv\ast
INC_DIR += interface\hal

#EM
INC_DIR += plutommi\MtkApp\EngineerMode\EngineerModeApp\EngineerModeAppInc
INC_DIR += plutommi\MtkApp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc
INC_DIR += BTMT\rf_desense
INC_DIR += interface\hal\bluetooth
INC_DIR += custom\drv\measure\Inc
#SRC_LIST += custom\common\hal\rf_desense_em_test.c

# J2ME

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
  ifneq ($(call Upper,$(strip $(PROJECT))),L1S)

    ifdef J2ME_SUPPORT
      ifneq ($(strip $(J2ME_SUPPORT)),NONE)
        J2ME_BOARDBB = $(strip $(BOARD_VER))
        ifdef FLAVOR
          ifneq ($(strip $(FLAVOR)),NONE)
            #J2ME_BOARDBB_DIR = $(dir custom\j2me\IJET\$(strip $(BOARD_VER))($(strip $(FLAVOR)))\)
            J2ME_BOARDBB = $(strip $(BOARD_VER))($(strip $(FLAVOR)))
          endif
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
          FOLDER_LIST += custom\j2me\JBLENDIA\$(strip $(BOARD_VER)) \
                         custom\j2me\JBLENDIA\_DEFAULT_BB
          INC_DIR += custom\j2me\JBLENDIA\$(strip $(BOARD_VER)) \
                     custom\j2me\JBLENDIA\_DEFAULT_BB
        endif
        ifeq ($(strip $(J2ME_SUPPORT)),JBED)

        endif
        ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMYVM)

        endif
        ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMY_MVM)
          FOLDER_LIST += custom\j2me\DUMMY\$(strip $(BOARD_VER)) \
                         custom\j2me\DUMMY\_DEFAULT_BB
          INC_DIR += custom\j2me\DUMMY\$(strip $(BOARD_VER)) \
                     custom\j2me\DUMMY\_DEFAULT_BB
        endif
        ifeq ($(strip $(J2ME_SUPPORT)),IJET)
          FOLDER_LIST += custom\j2me\IJET\$(strip $(J2ME_BOARDBB)) custom\j2me\IJET\_DEFAULT_BB
          INC_DIR += custom\j2me\IJET\$(strip $(J2ME_BOARDBB)) \
                     custom\j2me\IJET\_DEFAULT_BB \
                     j2me\vm\IJET\adaptation\include \
                     j2me\jal\include
        endif
        ifeq ($(strip $(J2ME_SUPPORT)),NEMO)
          FOLDER_LIST += custom\j2me\NEMO\$(strip $(J2ME_BOARDBB)) custom\j2me\NEMO\_DEFAULT_BB
          INC_DIR += custom\j2me\NEMO\$(strip $(J2ME_BOARDBB)) \
                     custom\j2me\NEMO\_DEFAULT_BB \
                     j2me\vm\NEMO\adaptation\include \
                     j2me\jal\include
        endif
      endif
    endif

  endif
endif

ifdef UMTS_RF_MODULE
  ifneq ($(strip $(UMTS_RF_MODULE)),)
    FOLDER_LIST += custom\ul1_rf\$(strip $(UMTS_RF_MODULE))
    INC_DIR += custom\ul1_rf\$(strip $(UMTS_RF_MODULE))
  endif
endif

ifdef UMTS_TDD128_RF_MODULE
  ifneq ($(strip $(UMTS_TDD128_RF_MODULE)),)
    FOLDER_LIST += custom\tl1_rf\$(strip $(UMTS_TDD128_RF_MODULE))
    INC_DIR += custom\tl1_rf\$(strip $(UMTS_TDD128_RF_MODULE))
  endif
endif

# For JAVA
JAVA_FOLDER = custom\j2me\$(strip $(J2ME_SUPPORT)) custom\j2me\DUMMY
JAVA_FOLDER_TMP := $(foreach DIR,$(JAVA_FOLDER),$(if $(filter $(DIR)\_DEFAULT_BB $(DIR)\$(strip $(J2ME_BOARDBB)),$(FOLDER_LIST)),$(DIR)))

SRC_LIST += $(foreach DIR,$(JAVA_FOLDER_TMP), \
  $(subst /,\,$(foreach file,$(wildcard $(DIR)/_DEFAULT_BB/*.c) $(wildcard $(DIR)/_DEFAULT_BB/*.cpp),$(if $(wildcard $(DIR)/$(strip $(J2ME_BOARDBB))/$(notdir $(file))),,$(file))) $(wildcard $(DIR)/$(strip $(J2ME_BOARDBB))/*.c) $(wildcard $(DIR)/$(strip $(J2ME_BOARDBB))/*.cpp)) \
)
FOLDER_LIST := $(filter-out $(foreach DIR,$(JAVA_FOLDER_TMP),$(DIR)\_DEFAULT_BB $(DIR)\$(strip $(J2ME_BOARDBB))),$(FOLDER_LIST))

# For AUTO_MERGE_FOLDER
AUTO_MERGE_TMP := $(foreach DIR,$(AUTO_MERGE_FOLDER),$(if $(filter $(DIR)\_DEFAULT_BB\$(strip $(PLATFORM)) $(DIR)\$(strip $(BOARD_VER)),$(FOLDER_LIST)),$(DIR)))

SRC_LIST += $(foreach DIR,$(AUTO_MERGE_TMP), \
  $(subst /,\,$(foreach file,$(wildcard $(DIR)/_DEFAULT_BB/$(strip $(PLATFORM))/*.c) $(wildcard $(DIR)/_DEFAULT_BB/$(strip $(PLATFORM))/*.cpp),$(if $(wildcard $(DIR)/$(strip $(BOARD_VER))/$(notdir $(file))),,$(file))) $(wildcard $(DIR)/$(strip $(BOARD_VER))/*.c) $(wildcard $(DIR)/$(strip $(BOARD_VER))/*.cpp)) \
)
FOLDER_LIST := $(filter-out $(foreach DIR,$(AUTO_MERGE_TMP),$(DIR)\_DEFAULT_BB\$(strip $(PLATFORM)) $(DIR)\$(strip $(BOARD_VER))),$(FOLDER_LIST))

#for Video
VIDEO_FOLDER = custom\video

SRC_LIST += $(foreach DIR,$(VIDEO_FOLDER), \
  $(subst /,\,$(foreach file,$(wildcard $(DIR)/default/*.c) $(wildcard $(DIR)/default/*.cpp),$(if $(wildcard $(DIR)/$(strip $(BOARD_VER))/$(notdir $(file))),,$(file))) $(wildcard $(DIR)/$(strip $(BOARD_VER))/*.c) $(wildcard $(DIR)/$(strip $(BOARD_VER))/*.cpp)) \
)

SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(shell if exist $(DIR)\*.c dir $(DIR)\*.c /b),$(DIR)\$(FILE)) \
)
SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(shell if exist $(DIR)\*.cpp dir $(DIR)\*.cpp /b),$(DIR)\$(FILE)) \
)
SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(shell if exist $(DIR)\*.s dir $(DIR)\*.s /b),$(DIR)\$(FILE)) \
)
SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(shell if exist $(DIR)\*.dws dir $(DIR)\*.dws /b),$(DIR)\$(FILE)) \
)
SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(shell if exist $(DIR)\*.rec dir $(DIR)\*.rec /b),$(DIR)\$(FILE)) \
)


SRC_LIST += custom\common\hal_public\custom_rec_config.c \
            custom\common\bt_cust.c

#only in MoDIS
ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  MODIS_DIS_FILE := custom_emi.c custom_flash.c usb_custom.c wndrv_configure.c wndrv_rf_ah.c wndrv_rf_maxim.c
  MODIS_DIS_FILE += custom_flash_norfdm5.c afe.c mal1_create.c kbdmain_joystick.c ERS_api.c ERS_sys.s custom_sfi.c
  MODIS_DIS_FILE += combo_flash_init.c combo_flash_nor.c
  SRC_LIST += custom\tst\tst_file_default_Catcher_filter.c
  MODIS_DIS_FILE += camera_hw.c camera_sccb.c image_sensor.c lens_module.c sensor_frame_rate_lut.c
  SRC_LIST := $(foreach file,$(call Lower,$(SRC_LIST)),$(if $(filter $(notdir $(file)),$(call Lower,$(MODIS_DIS_FILE))),,$(file)))
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
ifneq ($(filter $(COMPONENT),$(CUS_REL_PAR_SRC_COMP)),)
SRC_LIST := $(filter $(call Lower,$(SRC_LIST)),$(call Lower,$(CUS_REL_$(strip $(call Upper,$(COMPONENT)))_PAR_SRC_LIST)))
endif #CUS_REL_PAR_SRC_COMP
endif #CUSTOM_RELEASE

SRC_LIST :=  $(call uniq,$(SRC_LIST))

#  Define include path lists to INC_DIR
INC_DIR += custom\system\$(strip $(BOARD_VER)) \
          custom\system\$(strip $(BOARD_VER))\ERS \
          custom\common \
          custom\common\hal \
          custom\common\hal_public \
          custom\common\ps \
          custom\l1_rf\$(strip $(RF_MODULE)) \
          custom\drv\LCD\$(strip $(LCD_MODULE)) \
          custom\drv\color\$(strip $(LCD_MODULE)) \
          custom\drv\misc_drv\$(strip $(BOARD_VER)) \
          custom\app\$(strip $(BOARD_VER)) \
          custom\ps\$(strip $(BOARD_VER)) \
          custom\codegen\$(strip $(BOARD_VER)) \
          custom\drv\common_drv \
          custom\common\$(strip $(MMI_BASE)) \
          custom\audio\$(strip $(BOARD_VER)) \
          custom\meta\$(strip $(BOARD_VER)) \
          hal\display\common\include \
          $(strip $(AUDFOLDER))\inc \
          $(strip $(AUDFOLDER))

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
  INC_DIR += hal\audio\lib\MTKINC \
             $(strip $(MMIDIR))\MMI\Audio\AudioInc
endif

INC_DIR += verno \
           drv\include \
           hal\peripheral\inc \
           hal\storage\flash\mtd\inc \
           hal\storage\flash\fdm\inc \
           usb\include \
           ssf\inc \
           applib\misc\include

ifeq ($(strip $(MMIDIR)),lcmmi)
  INC_DIR += lcmmi\MMI\PROFILES\ProfilesInc \
             lcmmi\MMI\Inc \
             lcmmi\MMI\GUI\GUI_INC \
             lcmmi\MMI\IdleScreen\IdleScreenInc \
             lcmmi\MMI\Framework\History\HistoryInc \
             lcmmi\MMI\Framework\EventHandling\EventsInc \
             lcmmi\MMI\Framework\OSL\OSLInc \
             lcmmi\MMI\Framework\Tasks\TasksInc \
             lcmmi\MMI\DateTime\DateTimeInc \
             lcmmi\MMI\MiscFramework\MiscFrameworkInc \
             lcmmi\MTKApp\MTKAppInc \
             lcmmi\MTKApp\GDI\GDIInc
else
  INC_DIR += plutommi\MMI\PROFILES\ProfilesInc \
             plutommi\MMI\Inc \
             plutommi\Framework\Interface \
             plutommi\Framework\GUI\GUI_INC \
             plutommi\cui\inc \
             plutommi\MMI\IdleScreen\IdleScreenInc \
             plutommi\Framework\History\HistoryInc \
             plutommi\Framework\MemManager\MemManagerInc \
             plutommi\Framework\EventHandling\EventsInc \
             plutommi\Framework\Tasks\TasksInc \
             plutommi\MMI\DateTime\DateTimeInc \
             plutommi\MMI\MiscFramework\MiscFrameworkInc \
             plutommi\MTKApp\MTKAppInc \
             plutommi\service\mdi\mdiinc \
             plutommi\Framework\GDI\GDIInc
endif

ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  INC_DIR += $(strip $(MMIDIR))\MtkApp\EngineerMode\EngineerModeInc
else
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
    INC_DIR += $(strip $(MMIDIR))\MtkApp\EngineerMode\EngineerModeInc
  else
    INC_DIR += $(strip $(MMIDIR))\MtkApp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
               $(strip $(MMIDIR))\MtkApp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
               $(strip $(MMIDIR))\MtkApp\FactoryMode\FactoryModeInc
  endif
endif

INC_DIR += $(strip $(MMIDIR))\MMI\Setting\SettingInc \
           $(strip $(MMIDIR))\MMI\Organizer\OrganizerInc \
           $(strip $(MMIDIR))\MMI\Inc\MenuID \
           ssf\inc \
           plutommi\MtkApp\FileMgr\FileMgrInc \
           plutommi\Framework\DebugLevels\DebugLevelInc \
           $(strip $(PS_FOLDER))\l4\include \
           inet_ps\tcpip\include \
           inet_ps\tcpip\ipsec\include \
           inet_ps\tcpip\netkey\include \
           nvram\include \
           plutommi\Customer\CustomerInc \
           hal\video_codec\interface\inc \
           matv\inc \
           hal\system\DP\inc

# SV5
INC_DIR += hal\system\GFH\public \
           sss\interface\inc \
           SST\include

INC_DIR += hal\system\cache\inc

# File System custom file (temporary solution)
INC_DIR += hal\storage\mc\inc

# FOTA_ENABLE
ifdef FOTA_ENABLE
  ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
    INC_DIR += dp_engine\che\include
  endif
endif

# GADGET_SUPPORT
ifdef GADGET_SUPPORT
  ifneq ($(strip $(GADGET_SUPPORT)),NONE)
    INC_DIR += vendor\widget\google\gadgets\yahoo\romized \
               vendor\widget\google\gadgets\facebook\romized
  endif
endif

# ATCI is always needed.
INC_DIR += custom\atci\include

ifeq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
  INC_DIR += MoDIS_VC9\drv_sim\include
endif

ifneq ($(filter __MMI_BROWSER_2__, $(strip $(MODULE_DEFS))),)
INC_DIR += plutommi\service\browsersrv
endif

INC_DIR += tst\local_inc

INC_DIR :=  $(call uniq,$(INC_DIR))

# Define the specified compile options to COMP_DEFS
COMP_DEFS += __UCS2_ENCODING \
            MMI_ON_HARDWARE_P \
            APCS_INTWORK \
            USE_JAM=0 \
            COMPILER_SUPPORTS_LONG=1

ifdef FOTA_ENABLE
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    ifneq ($(strip $(FOTA_ENABLE)),)
      ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        COMP_DEFS += REMAPPING
      endif
    endif
  endif
endif

ifeq ($(filter __NOR_FLASH_BOOTING__,$(strip $(DEFINES))),)
  ifdef NEED_BUILD_BOOTLOADER
    ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
      ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        COMP_DEFS += __BL_ENABLE__
        COMP_DEFS += REMAPPING
      endif
    endif
  endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6218B)
  COMP_DEFS += REMAPPING
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6217)
  COMP_DEFS += REMAPPING
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6219)
  COMP_DEFS += REMAPPING
endif

ifdef USB_DOWNLOAD_IN_BL
  ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
    COMP_DEFS += REMAPPING
  endif
endif

ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
  COMP_DEFS += REMAPPING
endif

ifeq ($(shell dir custom\ps\$(strip $(BOARD_VER))\custom_port_setting.c /b 2>nul), custom_port_setting.c)
    COMP_DEFS += __CUSTOMIZED_PORT_SETTING__
endif


# gps track -start
# TRACK_SENSOR_SUPPORT
ifdef TRACK_SENSOR_SUPPORT
  ifeq ($(strip $(TRACK_SENSOR_SUPPORT)),TRUE)
  	COM_DEFS   += __TRACK_SENSOR__
  	
        #BMA250
	COM_DEFS   += __BOSCH_SENSOR__
	COM_DEFS   += __BOSCH_BMA250__
	COMMINCDIRS += custom\drv\track_sensor\BMA250 
	INC_DIR += custom\drv\track_sensor\BMA250
	FOLDER_LIST += custom\drv\track_sensor\BMA250
	SRC_PATH += custom\drv\track_sensor\BMA250	
	SRC_LIST += custom\drv\track_sensor\BMA250\track_sensor_bma250.c\
		custom\drv\track_sensor\BMA250\bma250.c
   
        #BMA250E
        #BMA250E is same to BMA250 without sensitivity
       COM_DEFS   += __BOSCH_BMA250E__


        #sensor IIC 通信驱动
        #理论上未来增加其它Sensor 可以摆脱无厂家代码的限制
        #完全自定义实现功能
        COMMINCDIRS += custom\drv\track_sensor\track_sensor_iic
	INC_DIR += custom\drv\track_sensor\track_sensor_iic
	FOLDER_LIST += custom\drv\track_sensor\track_sensor_iic
	SRC_PATH += custom\drv\track_sensor\track_sensor_iic	
	SRC_LIST += custom\drv\track_sensor\track_sensor_iic\track_sensor_iic.c


        #KXTJ3-1057
	COM_DEFS   += __KIONIX_KXTJ31057__
	COMMINCDIRS += custom\drv\track_sensor\KXTJ31057
	INC_DIR += custom\drv\track_sensor\KXTJ31057
	FOLDER_LIST += custom\drv\track_sensor\KXTJ31057
	SRC_PATH += custom\drv\track_sensor\KXTJ31057	
	SRC_LIST += custom\drv\track_sensor\KXTJ31057\track_sensor_kxtj31057.c

	#SC7A20
	COM_DEFS   += __SILAN_SC7A20__
	COMMINCDIRS += custom\drv\track_sensor\SC7A20
	INC_DIR += custom\drv\track_sensor\SC7A20
	FOLDER_LIST += custom\drv\track_sensor\SC7A20
	SRC_PATH += custom\drv\track_sensor\SC7A20
	SRC_LIST += custom\drv\track_sensor\SC7A20\track_sensor_sc7a20.c

	#DA213
	COM_DEFS   += __MIRA_DA213__
	COMMINCDIRS += custom\drv\track_sensor\DA213
	INC_DIR += custom\drv\track_sensor\DA213
	FOLDER_LIST += custom\drv\track_sensor\DA213
	SRC_PATH += custom\drv\track_sensor\DA213
	SRC_LIST += custom\drv\track_sensor\DA213\track_sensor_da213.c
    
  endif
endif


   
COMP_DEFS += __NVRAM_SPLIT__
INC_DIR += track\drv\drv_inc\
             track\fun\fun_inc  \
             track\at\at_inc \
             track\nvram\nvram_inc \
             track\os\os_inc \
             gps\mnl\include \
	     ELL\ell-common

