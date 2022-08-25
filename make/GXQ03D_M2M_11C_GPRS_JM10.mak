#
#  Copyright Statement:
#  ---------------------------
#  This software/firmware and related documentation ("MediaTek Software") are
#  protected under relevant copyright laws. The information contained herein
#  is confidential and proprietary to MediaTek Inc. and/or its licensors.
#  Without the prior written permission of MediaTek inc. and/or its licensors,
#  any reproduction,modification, use or disclosure of MediaTek Software, and
#  information contained herein, in whole or in part, shall be strictly prohibited.
#
#  MediaTek Inc.(C)2011.All rights reserved.
#
#  BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND
#  AGREES THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK
#  SOFTWARE") RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED
#  TO RECEIVER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
#  WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
#  WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
#  NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER
#  WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
#  INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER
#  AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING
#  THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE
#  RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
#  CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR
#  ANY MEDIATEK SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO
#  CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND
#  EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT
#  TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,AT MEDIATEK'S OPTION,
#  TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,OR REFUND ANY SOFTWARE
#  LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK
#  SOFTWARE AT ISSUE.
#
# *************************************************************************


#-------------Function config------------------

PROJECT_SUPPORT_TRACK=JM10

#Search "project_null" and add a project name


SWITCHABLE_FEATURE = GEMINI

MD_FEATURE = GEMINI_SUPPORT


BT_MAX_LE_LINK_NUM = 1    #

ECALL_SUPPORT = FALSE     #


TRACK_CUST_GPS_SUPPORT = NONE 
  #   M10382: GPS SIRF4
  #   UBX-G7020
  
GPS_SUPPORT =MT3333
  # Description:
  #   Mapping with GPS CHIP, Such as MT3336       # NONE, MT3336, MT3332
  #   MT3326  phase out after 11BW1144MP
  # Option Values:
  #   NONE: NO GPS CHIP Bind with Baseband
  #   MT3336: GPS CHIP MT3336
  #   MT3332: Support GPS CHIP MT3332
  # Switch-ability:
  #   Non-switchable

TRACK_GPS_TYPE = GPS_BEIDOU
  # Description:
  #   mt3333 type
  # Option Values:
  #   GPS_BEIDOU: GPS and BEIDOU
  #   GPS_GLONASS: GPS and GLONASS
  # Switch-ability:
  #   any
  
TRACK_SENSOR_SUPPORT =TRUE
  # Description:
  #   sensor type 
  # Option Values:
  #   TRUE :Enable this feature (BMA250/BMA250E/MC3410/AFA750/MMA8452Q)
  #   FALSE : no sensor
  
WATDOG =PULSE
  # Description:
  #   watch dog signal type to EM78P152
  # Option Values:
  #   NONE: no 152
  #   PULSE: pulse
  #   IIC: IIC communication


RF_MODULE_CUSTOM = RF_6625E
  # Description:
  #   describe the RF module used in this project
  # Option Values:
  #   NA: the RF module used in this project
  # Switch-ability:
  #   Non-switchable
RVCT_VERSION = V31
  # Description:
  #   ARM RVCT Version
  # Option Values:
  #   V31: ARM RVCT Version 3.1
  #   V22: ARM RVCT Version 2.2
  # Switch-ability:
  #   [Any] -> [Any]

RVCT_PARTIAL_LINK = TRUE
  # Description:
  #   True:turn on partial link; False:turn off partial link
  # Option Values:
  #   TRUE: In linking process, try normal link firstly, if OOM, try partiallink next
  #   FALSE: In linking process, normal link only
  # Switch-ability:
  #   [Any] -> [Any]

FEATURE_OVERLOAD = FALSE
  # Description:
  #   Enabling this option will allow a project configured with more features than its physical constraints. This option just bypass some building error checkings and generate the .bin. However, the .bin is still can NOT work in target if the physical constrain
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

# ------------------------------ HW and Project
BOARD_VER = GXQ03D_M2M_11C_BB
  # Description:
  #   Name of the PCB or EVB.
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

SUB_BOARD_VER = PCB01
  # Description:
  #   Sub-name of the PCB or EVB.
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

DCM_COMPRESSION_SUPPORT = FALSE
  # Description:
  #   Dynamic code management with compression support.
  #   Certain codes would be put on flash in compressed form and decompressed into RAM to execute.
  # Option Values:
  #   TRUE: Enable DCM with compression support
  #   FALSE: Disable DCM with compression support
  # Switch-ability:
  #   [Any] -> [Any]

DCM_COMPRESSION_AUDIO_BT = FALSE
  # Description:
  #   To enable DCM with compression mechanism for BT application.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

DCM_COMPRESSION_AUDIO_CODEC = FALSE
  # Description:
  #   To enable DCM with compression mechanism for audio codec.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

DCM_COMPRESSION_AUDIO_EFFECT = FALSE
  # Description:
  #   To enable DCM with compression mechanism for audio post-processing.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

CHIP_VERSION_CHECK = TRUE
  # Description:
  #   Enable/Disable HW ID check and supported in all projects with all current online project
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

PHONE_TYPE = BAR
  # Description:
  #   Phone type is clamshell, bar or slide type.
  # Option Values:
  #   CLAMSHELL: Clamshell phone
  #   BAR: BAR type phone
  #   SLIDE: Slide type phone
  # Switch-ability:
  #   [Any] -> [Any]

FM_RADIO_I2S_PATH = FALSE
  # Description:
  #   Used to determine the audio path of FM radio
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

FM_RADIO_RDS_SUPPORT = FALSE
  # Description:
  #   To enable or disable FM RDS function.It has no impact on the chips which don't support RDS and some other scenarios this feature is useless(Like FTE MMI).
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature(default value)
  # Switch-ability:
  #   TRUE -> FALSE

DCM_COMPRESSION_MAUI_INIT = FALSE
  # Description:
  #   To enable DCM with compression mechanism for MAUI INIT code.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

MULTI_LEVEL_BACKLIGHT_SUPPORT = FALSE
  # Description:
  #   To specify do we support multi-level backlight support (Multi-level means more than 5 levels can be adjusted by users)
  # Option Values:
  #   TRUE: Turn on multi-level backlight adjustment (more than 5 levels)
  #   FALSE: Turn off multi-level backlight adjustment
  # Switch-ability:
  #   FALSE -> TRUE

DRV_BATTERY_EXIST_DETECTION = FALSE
  # Description:
  #   To check battery exist is needed to check or not
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   [Any] -> [Any]

PROXIMITY_SENSOR = NONE
  # Description:
  #   The feature is to specify proximity sensor support
  #   If proximity sensor is supported, then the sensor type is specified
  #   The proximity sensor is an external device
  # Option Values:
  #   CM3623:
  #   NONE:
  # Switch-ability:
  #   NONE -> CM3623

MOTION_SENSOR_SUPPORT = NONE
  # Description:
  #   To enable motion sensor support.
  #   And Describe which sensor chip in use.
  # Option Values:
  #   KXP74_SPI: moiton sensor is KXP74 and using SPI interface.
  #   KXP84_I2C: motion sensor is KXP84 and using I2C interface.
  #   KXP84_SPI: motion sensor is KXP84 and using SPI interface.
  #   KXTF9_I2C: motion sensor is KXTF9 and using I2C interface.
  #   BMA220_I2C: motion sensor is BMA220 and using I2C interface.
  #   MMA7455_I2C: motion sensor is MMA7455 and using I2C interface.
  #   MMA7660_I2C: motion sensor is MMA7660 and using I2C interface.
  #   MXC6202_I2C: motion sensor is MXC6202 and using I2C interface.
  #   MC3230_I2C: motion sensor is mc3230 and using i2c interface.
  #   NONE: Disable this feature
  # Switch-ability:
  #   N/A

JOGBALL_SUPPORT = NONE
  # Description:
  #   Support Jogball or OFN (Optical Finger Navigation) to replace navigation keys
  # Option Values:
  #   JOGBALL: HW support for Jogball
  #   OFN: HW support for OFN
  #   NONE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

SLT_ENHANCE = NONE
  # Description:
  #   feature option for SLT2.0
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

INTERNAL_ANTENNAL_SUPPORT = FALSE
  # Description:
  #   if FM HW support S.Ant, this option can be set to true or false, or it should be set to false
  # Option Values:
  #   FALSE: only support long antenna
  #   TRUE: support both long and short antenna
  # Switch-ability:
  #   TRUE -> FALSE

HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT = FALSE
  # Description:
  #   To support High voltage charger with adaptive charge current
  # Option Values:
  #   TRUE: Turn On
  #   FALSE: Turn off
  # Switch-ability:
  #   TRUE -> FALSE

NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION = FALSE
  # Description:
  #   FALSE: UE benefits from battery consumption optimisation mechanism from network, e.g. mobile phone   # TRUE: UE doesn't benefit from battery consumption optimisation mechanism from network, e.g. data card
  # Option Values:
  #   TRUE: UE doesn't benefit from battery consumption optimisation mechanism from network, e.g. data card
  #   FALSE: UE benefits from battery consumption optimisation mechanism from network, e.g. mobile phone
  # Switch-ability:
  #   N/A

SIM_SWTICH_CONTROLLER_MT6306 = FALSE
  # Description:
  #   enable MT6306 4SIM feature
  # Option Values:
  #   TRUE: enable 4SIM controller for MT6306
  #   FALSE: disable 4SIM controller for MT6306
  # Switch-ability:
  #   N/A

SIM_SWTICH_CONTROLLER_MT6302 = FALSE
  # Description:
  #   enable MT6302 4SIM feature
  # Option Values:
  #   TRUE: enable 4SIM controller for MT6302
  #   FALSE: disable 4SIM controller for MT6302
  # Switch-ability:
  #   N/A

# ------------------------------ LCD
LCD_MODULE = GXQ03D_M2M_11C_LCM
  # Description:
  #   In order to select the folders of LCD module of specified project, please set the option as the folder name in custom folder.
  # Option Values:
  #   NA:
  # Switch-ability:
  #   Non-switchable

DISPLAY_TYPE = COLOR
  # Description:
  #   Support lcmmi to select BW/COLOR image
  # Option Values:
  #   COLOR: .
  #   BW: .
  # Switch-ability:
  #   Non-switchable

MAIN_LCD_SIZE = 176X220
  # Description:
  #   Add a MAIN_LCD_SIZE compile option in make file
  # Option Values:
  #   320X240: The main lcd size is 320X240
  #   240X320: The main lcd size is 240X320
  #   128X128: The main lcd size is 128X128
  #   96X64: The main lcd size is 96X64
  #   360X640: The main lcd size is 360X640
  #   128X160: The main lcd size is 128X160
  #   176X220: The main lcd size is 176X220
  #   240X400: The main lcd size is 240X400
  #   320X480: The main lcd size is 320X480
  # Switch-ability:
  #   128X128 -> 128X160

MAIN_LCM_PHYSICAL_SIZE = BY_LCD_SIZE_SETTING
  # Description:
  #   This is the physical size of attached main LCM, MAIN_LCD_SIZE is MMI size actually
  # Option Values:
  #   320x240:
  #   240x320:
  #   128X128:
  #   96X64:
  #   360X640:
  #   128X160:
  #   176X220:
  #   240x400:
  #   320x480:
  #   BY_LCD_SIZE_SETTING:
  # Switch-ability:
  #   [Any] -> [Any]

MAIN_MEDIA_LAYER_BITS_PER_PIXEL = DEFAULT
  # Description:
  #   If set this option to 24, Image Viewer, Slide Show, Photo Editor, Image Tile, Wallpaper would use 24-bit color format layer to show image. The image quality would be better.
  # Option Values:
  #   24: multimedia app support 24 bits LCD display
  #   DEFAULT:
  # Switch-ability:
  #   [Any] -> [Any]

SYNC_LCM_METHOD = BY_CHIP
  # Description:
  #   Specifies either HW or SW sync LCM method. Will pick either __SYNC_LCM_HW_SUPPORT__ or __SYNC_LCM_SW_SUPPORT__ option. If user is not knowledgeable with the chip capability, just set it as SYNC_LCM_METHOD = BY_CHIP.
  # Option Values:
  #   N/A
  # Switch-ability:
  #   [Any] -> [Any]

SUB_LCD_SIZE = NONE
  # Description:
  #   To support enable SubLCD, customer can set size to NONE and 128X128.
  # Option Values:
  #   NONE: Disable this feature
  #   128X128: temporary value
  # Switch-ability:
  #   Non-switchable

SUB_LCM_PHYSICAL_SIZE = BY_LCD_SIZE_SETTING
  # Description:
  #   This is the physical size of attached sub LCM if any, SUB_LCD_SIZE is MMI size actually
  # Option Values:
  #   320x240:
  #   240x320:
  #   128X128:
  #   96X64:
  #   360X640:
  #   128X160:
  #   176X220:
  #   240x400:
  #   320x480:
  #   BY_LCD_SIZE_SETTING:
  # Switch-ability:
  #   [Any] -> [Any]

LCM_ROTATE_SUPPORT = FALSE
  # Description:
  #   enable/disable use LCM HW's rotation,
  #   Turn on it when MT6228/29 platform and use TV-out
  # Option Values:
  #   TRUE: LCM support rotate
  #   FALSE: LCM does not support rotate
  # Switch-ability:
  #   [Any] -> [Any]

SYNC_LCM_SUPPORT = TRUE
  # Description:
  #   COMPILER OPTION FOR SUPPORTING SYNC MODE LCM
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   FALSE -> TRUE
  #   TRUE -> FALSE

TOUCH_PANEL_SUPPORT = NONE
  # Description:
  #   Touch panel integration
  # Option Values:
  #   CTP_SITRONIX_ST1232_FAKE_MULTIPLE: support Sitroniz ST1232 capacitence touch panel controller -- fake multiple touch
  #   NONE: Not support touch panel
  #   CTP_CYPRESS_TMA340_TRUE_MULTIPLE: support cypress TMA340 capacitence touch panel controller -- true multiple touch
  #   CTP_NOVATEK_NT11001_FAKE_MULTIPLE: support Novatek NT11001 capacitence touch panel controller -- fake multiple touch
  #   CTP_ITE_7250AFN_FAKE_MULTIPLE: support ITE 7250AFN capacitence touch panel controller -- fake multiple touch
  #   TP_INTERNAL: use Internal AUXADC to implement touch panel
  #   CTP_FOCALTEK_FT5206_TRUE_MULTIPLE: support FocalTech FT5206 capacitence touch panel controller -- true multiple touch
  #   CTP_GOODIX_GT818_TRUE_MULTIPLE: Support Goodix GT818 capacitence touch panel controller
  #   CTP_GOODIX_GT868_TRUE_MULTIPLE: Support Goodix GT868 capacitence touch panel controller
  # Switch-ability:
  #   TP_INTERNAL -> NONE
  #   CTP_GOODIX_GT818_TRUE_MULTIPLE -> TP_INTERNAL
  #   CTP_GOODIX_GT818_TRUE_MULTIPLE -> NONE
  #   TP_INTERNAL -> CTP_GOODIX_GT868_TRUE_MULTIPLE
  #   CTP_GOODIX_GT868_TRUE_MULTIPLE -> CTP_GOODIX_GT818_TRUE_MULTIPLE
  #   NONE -> CTP_GOODIX_GT818_TRUE_MULTIPLE
  #   NONE -> CTP_GOODIX_GT868_TRUE_MULTIPLE
  #   CTP_GOODIX_GT868_TRUE_MULTIPLE -> TP_INTERNAL
  #   TP_INTERNAL -> CTP_GOODIX_GT818_TRUE_MULTIPLE
  #   CTP_GOODIX_GT818_TRUE_MULTIPLE -> CTP_GOODIX_GT868_TRUE_MULTIPLE
  #   NONE -> TP_INTERNAL
  #   CTP_GOODIX_GT868_TRUE_MULTIPLE -> NONE

TOUCH_PANEL_SHORTCUT_SUPPORT = FALSE
  # Description:
  #   Support touch panel shortcut functionality
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

# ------------------------------ MMI
MMI_VERSION = EMPTY_MMI
  # Description:
  #   It's MMI version type control
  #   For example:
  #   MMI_VERSION=PLUTO_MMI (It's an internal or MP at customer side project)
  #   MMI_VERSION=XXX_MMI (It's a MP at MTK side project)
  # Option Values:
  #   NEPTUNE_MMI:
  #   COSMOS_MMI:
  #   PLUTO_MMI:
  #   EMPTY_MMI:
  # Switch-ability:
  #   [Any] -> [Any]

VENUS_MMI = NONE
  # Description:
  #   Enable Venus UI Engine and related Fancy Apps
  # Option Values:
  #   NONE: Disable venus ui engine
  #   VENUS_LEVEL1: Enable venus ui engine
  # Switch-ability:
  #   [Any] -> [Any]

FINGER_TOUCH_SUPPORT = NONE
  # Description:
  #   it needs to covert to this macro
  #   __MMI_FTE_SUPPORT__
  #   for using in C program
  # Option Values:
  #   NONE: Not support finger touch
  #   FTE: Enable finger touch
  # Switch-ability:
  #   FTE -> NONE

VM_CONCURRENCE = EXCLUSIVE
  # Description:
  #   To set the concurrence setting(CONCURRENT/EXCLUSIVE) for VMs(Java/MRE)
  # Option Values:
  #   CONCURRENT: JAVA can be concurrent with MRE
  #   EXCLUSIVE: JAVA can NOT be concurrent with MRE
  # Switch-ability:
  #   N/A

# ------------------------------ Input and Language
HAND_WRITING = NONE
  # Description:
  #   Enable Which Third Party Handwriting Engine
  # Option Values:
  #   MMI_HANWANG_DEMO:
  #   MMI_DECUMA_DEMO:
  #   NONE: No hand writing support
  #   MMI_DECUMA:
  #   MMI_PENPOWER_DEMO:
  #   MMI_HANWANG:
  #   MMI_PENPOWER:
  #   MMI_GUOBI_HW_STANDARD: Guobi Handwriting standard lib support
  #   MMI_GUOBI_HW_SC_SLIM: Guobi Handwriting Slim lib support.
  # Switch-ability:
  #   [Any] -> [Any]

INPUT_METHOD = NONE
  # Description:
  #   Add a INPUT_METHOD compile option in make file
  # Option Values:
  #   MMI_T9: T9 IME support
  #   NONE: No input method support
  #   MMI_ZI_V7: ZI V7 IME support
  #   MMI_KOMOXO:
  #   MMI_T9_V7_4:
  #   MMI_CSTAR_V2: CSTAR IME support
  #   MMI_CSTAR_V2_DEMO:
  #   MMI_KOMOXO_DEMO:
  #   MMI_ZI: ZI IME supoort
  #   MMI_ZI_V6: ZI V6 IME support
  # Switch-ability:
  #   [Any] -> [Any]

MMI_IME_V3_SUPPORT = FALSE
  # Description:
  #   this is for input method version
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

KEYPAD_TYPE = NORMAL_KEYPAD
  # Description:
  #   To set keypad type
  # Option Values:
  #   REDUCED_KEYPAD:
  #   EXTEND_QWERTY_KEYPAD:
  #   NORMAL_KEYPAD:
  #   QWERTY_KEYPAD:
  # Switch-ability:
  #   Non-switchable

# ------------------------------ Application
ALIPAY_SUPPORT = FALSE
  # Description:
  #   -
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

BACKGROUND_CALL_SUPPORT = FALSE
  # Description:
  #   Background call feature allows end users to launch MMI applications during in-call. End users can enter MMI main menu from in-call option menu. Background call feature also allows end user to continue the MMI application launched before incoming call. Aft
  # Option Values:
  #   TRUE: Enable background call feature
  #   FALSE: Disable background call feature
  # Switch-ability:
  #   [Any] -> [Any]

OBIGO_FEATURE = NONE
  # Description:
  #   It defines the capability of Obigo Q03C/Q05A WAP and Opera Mobile Browser solution. If feature option OBIGO_FEATURE is NONE, it means no WAP solution is enabled.
  # Option Values:
  #   NONE:
  #   WAP2_SEC_MMS:
  #   WAP_SEC:
  #   WAP_MMS:
  #   WAP2:
  #   WAP:
  #   WAP_SEC_MMS:
  #   WAP2_MMS:
  #   WAP2_SEC:
  #   WAP2_SEC_HTTP_ONLY:  It means (HTTP protocol + Security ). No WAP1.2.1 protocol
  #   WAP2_HTTP_ONLY:  It means (HTTP protocolonly ). No WAP1.2.1 protocol
  # Switch-ability:
  #   WAP2_SEC_HTTP_ONLY -> NONE
  #   WAP_SEC -> NONE
  #   WAP2 -> NONE
  #   WAP2_SEC -> NONE

HTTPSRV_SUPPORT = FALSE
  # Description:
  #   Enable/Disable HTTP Server
  # Option Values:
  #   TRUE: Turn on HTTP Server
  #   FALSE: Turn off HTTP Server
  # Switch-ability:
  #   [Any] -> [Any]

KARAOKE_SUPPORT = FALSE
  # Description:
  #   Enable Karaoke function.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

WAP_MMS_FEATURES = NONE
  # Description:
  #   Please see attached PPT.
  # Option Values:
  #   NONE: Set value to NONE to modify settings of WAP and MMS individually, with more flexibility.
  #         If this is NOT NONE, then following configuration macros will NOT impact project configuration.
  #         1. OBIGO_FEATURE
  #         2. XYSSL
  #         3. UNIFIED_PUSH_FEATURES
  #         4. MMS_FEATURES
  #   FULL: Enable full-version of WAP and MMS, including obigo security.
  #   UTRA_SLIM: Browser feature will be same as OBIGO_Q03C_SLIM.
  #              MMS feature will be same as LOW_TIER_SLIM
  #              Obigo security will be OFF.
  #   UTRA_SLIM_SECURITY: ULTRA_SLIM feature set with HTTPS support using XYSSL.
  # Switch-ability:
  #   N/A

MMS_FEATURES = NONE
  # Description:
  #   Define features set of MMS solution
  # Option Values:
  #   SLIM: SLIM Feature set of MMS-V02
  #   NONE: In case MMS_SUPPORT is NONE
  #   FULL: FULL Feature set of MMS-V02
  # Switch-ability:
  #   SLIM -> FULL
  #   FULL -> SLIM

MMS_SUPPORT = NONE
  # Description:
  #   Determine MMS solution
  # Option Values:
  #   OBIGO_Q03C_MMS_V02: MMS-V02 is supported
  #   NONE: MMS Feature is not supported
  # Switch-ability:
  #   N/A

CLOG_SIM_SYNC_SUPPORT = FALSE
  # Description:
  #   Turn on/Off CallLog SIM Sync feature, when turn on it, Calllog will read the call log data  in SIM card when power on if find the SIM card is changed or when being notified that SIM card is refreshed by SAT, and also wiill write the latest call log in phone storage to the SIM card when each normal power off such as longpress END key
  # Option Values:
  #   TRUE: Turn on it
  #   FALSE: Turn off it
  # Switch-ability:
  #   N/A

CBM_CONNECTION_MANAGER_SUPPORT = FALSE
  # Description:
  #   This feature option is used to turn on/off Connection Manager (CNMGR).
  #
  #   CNMGR counts the sent/received data size of dial-up and local bearers. It also counts the connection time of current activated bearer. The information provided by CNMGR is listed below.
  #   - The sent/received data size of last connection
  #   - The connection time of last connection
  #   - The sent/received data size of all connections
  #   - The connection time of all connections
  #   - The sent/received data size of current activated connection
  #   - The connection time of current activated connection
  #
  #   The second functionality of CNMGR is user can disconnect connection from CNMGR Application UI.
  #
  #   The third functionality of CNMGR is supporting 3G Fast Dormancy (FD) feature. CNMGR monitors connection status and send FD request if no data transmission continues for a while.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   TRUE -> FALSE
  #   FALSE -> TRUE

CLOUD_SUPPORT = NONE
  # Description:
  #   cloud related features
  # Option Values:
  #   NONE: Disable this feature
  #   LIB: library release of sso.mak
  #   SOURCE: source release for internal projects
  # Switch-ability:
  #   N/A

CARDAV_SUPPORT = FALSE
  # Description:
  #   This will enable carddav protocol
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   TRUE -> FALSE
  #   FALSE -> TRUE

VCARD_CLOUD_SUPPORT = FALSE
  # Description:
  #   VCARD_CLOUD_SUPPORT = TRUE
  #   Description:
  #   To enable Contact backup restore.
  #   Option Values:
  #   TRUE: Support Contact backup restore.
  #   FALSE: Disable Contact backup restore.
  #   Switch-ability:
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   FALSE -> TRUE
  #   TRUE -> FALSE

KEY_TONE_DETECTION = FALSE
  # Description:
  #   while in call, with this feature, we could analyze the intput number (0~9 , * ,#) by the tone passed in by the other side.
  #   Currently mmi application "Auto Answer Machine" depends on this option.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   [Any] -> [Any]

DA_MEMORY_CUT_SUPPORT = FALSE
  # Description:
  #   Reduce the data account memory.
  # Option Values:
  #   TRUE: Enable memory cut.
  #   FALSE: Disable memory cut.
  # Switch-ability:
  #   [Any] -> [Any]

DA_SMART_SELECTION_SUPPORT = FALSE
  # Description:
  #   Give a chance to close smart selection feature to slim project
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   TRUE -> FALSE

DCM_COMPRESSION_MMI_SUPPORT = NONE
  # Description:
  #   To enable DCM with compression mechanism for mmi ap.
  # Option Values:
  #   DCM_AP_ONLY: Enable mmi ap to use DCM£¬should Only set in 32+32/16+32 segment
  #   NONE: Disable this feature£¬in other segment above 32+32 should set NONE
  # Switch-ability:
  #   N/A

DCM_COMPRESSION_MMI_POOL_A = FALSE
  # Description:
  #   To enable DCM with compression mechanism for Cosmos app: 'BROWSER', 'CALC', 'CALLSET', 'CAMCO', 'CLNDR', 'CLOCK', 'FMRADIO', 'SOUNDSET', 'COSMOS_EM', 'COSMOS_FM'.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

DCM_COMPRESSION_MMI_POOL_B = FALSE
  # Description:
  #   To enable DCM with compression mechanism for Cosmos app: 'COSMOS_DTCNT', 'MOT', 'SECSET'.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

DCM_COMPRESSION_MMI_POOL_C = FALSE
  # Description:
  #   To enable DCM with compression mechanism for Cosmos app: 'BAIDUSEARCH', 'BOOTUP', 'SETTING', 'SOUNDREC'.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

DOWNLOADABLE_THEME = FALSE
  # Description:
  #   Theme is to change MMI look and feel easily;
  #   Capable of changing look and feel of the phone by downloaded theme file. Can: Change Color/Change Image/Change Tone;
  #   Dynamically downloaded on phone
  # Option Values:
  #   TRUE: Enable downloadable theme feature
  #   FALSE: Disable downloadable theme feature
  # Switch-ability:
  #   [Any] -> [Any]

DLT_ALWAYS_LOAD_BUFFER_SIZE = 0
  # Description:
  #   The basic idea is to load images into a global buffer so as to reduce file system access; the loading maybe of three types:
  #   one is "LOAD_ALWAYS images that are always loaded. Ex: Images that are part of the base control set are frequently accessed and can
  # Option Values:
  #   NA: For downloadable theme feature, define memory buffer (in KByte) for theme attributes. It is for performance acceleration. Some theme attributes will always be loaded to this buffer.
  # Switch-ability:
  #   [Any] -> [Any]

DLT_LOAD_ON_DEMAND_BUFFER_SIZE = 0
  # Description:
  #   The basic idea is to load images into a global buffer so as to reduce file system access; the loading maybe of three types:
  #   one is "LOAD_ONDEMAND images that are loaded as need arises. Images that may be frequently accessed from a screen like matrix menu
  # Option Values:
  #   NA: For downloadable theme feature, define memory buffer (in KByte) for theme attributes. It is for performance acceleration. Theme attributes will be loaded on demand to this buffer.
  # Switch-ability:
  #   [Any] -> [Any]

DRM_VERSION = NONE
  # Description:
  #   Provides information about DRM version supported
  # Option Values:
  #   NONE: Value will be NONE if DRM is not supported.
  #   V01: If DRM 1.0 is supported, version will be V01
  # Switch-ability:
  #   NONE -> V01

DRM_SUPPORT_DB_SIZE = NONE
  # Description:
  #   Provides information about number of licenses which can be supported in license database.
  # Option Values:
  #   256: Can support upto 256 licenses
  #   512: Can support upto 512 licenses
  #   1024: Can support upto 1024 licenses
  #   64: Can support upto 64 licenses
  #   NONE: Should be NONE if DRM SUPPORT is not present.
  # Switch-ability:
  #   Non-switchable

DRM_SUPPORT_SCAN_DISK = FALSE
  # Description:
  #   DRM supports scan disk or not
  # Option Values:
  #   FALSE: Scan disk is not supported.
  #   TRUE: Scan disk is supported
  # Switch-ability:
  #   FALSE -> TRUE

GEMINI = FALSE
  # Description:
  #   To identify if this project uses a "Single chip-dual SIM" solution.
  # Option Values:
  #   FALSE: Disable this feature
  #   2: Enable 2 SIMs, single talk.
  #   3: Enable 3 SIMs, single talk.
  #   4: Enable 4 SIMs, single talk.
  # Switch-ability:
  #   Non-switchable

SENDKEY_MODE = SINGLE_KEY_SELECT_MENU
  # Description:
  #   Send key mode.
  #   SINGLE_KEY_SELECT_MENU : only one sendkey will popup a menu to select dail card1 or card2
  #   SENDKEY2_SUPPORT :  two sendkeys the one is for card1 and the other is for card2
  #   LSK_KEYSEND2_IN_ONE: only one sendkey and is for card1 dial ,card2 an
  # Option Values:
  #   SENDKEY2_SUPPORT: Two sendkeys , the one is for card1 and the other is for card2
  #   SINGLE_KEY_SELECT_MENU: Only one sendkey, will popup a menu to select dial card1 or card2
  # Switch-ability:
  #   SENDKEY2_SUPPORT -> SINGLE_KEY_SELECT_MENU

IMPS_SUPPORT = FALSE
  # Description:
  #   Enable OMA Instant Messaging and Presence Services(IMPS) feature
  # Option Values:
  #   TRUE: Enable IMPS feature
  #   FALSE: Disable IMPS feature
  # Switch-ability:
  #   N/A

MRE_PACKAGE = SLIM
  # Description:
  #   if this feature set TRUE, then the package will support dynamic load app
  # Option Values:
  #   SLIM: set MRE package as slim package
  #   NORMAL: set MRE package as normal package
  #   FULL: set MRE package as full package
  # Switch-ability:
  #   SLIM -> NORMAL
  #   FULL -> SLIM
  #   FULL -> NORMAL
  #   NORMAL -> SLIM

MRE_CONTENT_NUMBER = 20
  # Description:
  #   It's a number define how much MRE Content can be installed on the Project.
  #   Include all mre content (app,widget......)
  # Option Values:
  #   20: 20 app supported to install.
  #   40: 20 app supported to install.
  #   60: 20 app supported to install.
  # Switch-ability:
  #   [Any] -> [Any]

MCARE_SUPPORT = FALSE
  # Description:
  #   mCare platform
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

PHB_FDN_ENTRY = 32
  # Description:
  #   Maximum fixed dial number in SIM card, its value must <=32
  # Option Values:
  #   NA: The value can be 1 to 32, must <=32
  # Switch-ability:
  #   N/A

PHB_LN_ENTRY = 10
  # Description:
  #   Number of the call log with single log type from single SIM card, it 's a range better no more than 100, suggestion to be 10, 20, 30, 40, 50, 60, 80, 100 and so on. Totol log num = PHB_LN_ENTRY * log type num * sim card num.
  # Option Values:
  #   50: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 50, total log num = 50 * log type num * sim card num.
  #   40: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 40, total log num = 40 * log type num * sim card num.
  #   80: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 80, total log num = 80 * log type num * sim card num.
  #   20: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 20, total log num = 20 * log type num * sim card num.
  #   60: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 60, total log num = 60 * log type num * sim card num.
  #   30: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 30, total log num = 30 * log type num * sim card num.
  #   10: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 10, total log num = 10 * log type num * sim card num.
  #   100: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 100, total log num = 100 * log type num * sim card num.
  # Switch-ability:
  #   [Any] -> [Any]

PHB_PHONE_ENTRY = 5
  # Description:
  #   Maximum Phonebook entry in Phone,  #Switch-ability: [Any] -> [Any]
  # Option Values:
  #   NA: .
  # Switch-ability:
  #   N/A

PHB_SIM_ENTRY = 5
  # Description:
  #   Maximum Phonebook entry in SIM card.
  # Option Values:
  #   NA: .
  # Switch-ability:
  #   N/A

PHB_TCARD_ENTRY = 0
  # Description:
  #   Maximum Phonebook entry in memory card,  #Switch-ability: [Any] -> [Any]
  # Option Values:
  #   NA: Any number value, but it will impact RAM and ROM size.
  # Switch-ability:
  #   [Any] -> [Any]

PHB_SYNC = OFF
  # Description:
  #   To enable/disable phonebook sync feature.
  # Option Values:
  #   ON: Support Sync from Phonebook
  #   OFF: Not support Sync from Phonebook
  # Switch-ability:
  #   [Any] -> [Any]

PHB_ADDITIONAL_SUPPORT = FALSE
  # Description:
  #   USIM Phonebook Support
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   N/A

SIM_PROVISIONING = NONE
  # Description:
  #   Enable provisioning of Internet profile settings from SIM card
  # Option Values:
  #   NONE: Disable SIM Provisioning feature
  #   MMSICP: Enable SIM provsioning feature and support 3GPP Efmmsicp file in SIM card
  # Switch-ability:
  #   MMSICP -> NONE

SMS_CLOUD_SUPPORT = FALSE
  # Description:
  #   SMS_CLOUD_SUPPORT = TRUE
  #   Description:
  #   To enable SMS backup restore.
  #   Option Values:
  #   TRUE: Support SMS backup restore.
  #   FALSE: Disable SMS backup restore.
  #   Switch-ability:
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE
  #   FALSE -> TRUE

SMS_PHONE_ENTRY = 10
  # Description:
  #   SMS Entry Number in NVRAM
  # Option Values:
  #   NA: SMS entities on NVRAM
  # Switch-ability:
  #   [Any] -> [Any]

SMS_R8_TABLE_MECHANISM = SMS_R8_DEFAULT
  # Description:
  #   Customize the GSM R8 table mechanism
  # Option Values:
  #   SMS_R8_BOTH: Support National Locking table + National extension table mode
  #   SMS_R8_SINGLE: Support English Locking table + National extension table mode
  #   SMS_R8_LOCKING: Support National Locking table + English extension table mode
  #   SMS_R8_DEFAULT: Only support English Gsm7bit conversion table
  #   SMS_R8_AUTO: Support switch table mode automaticlly by the minimized text size
  # Switch-ability:
  #   [Any] -> [Any]

SMS_SIM_ENTRY = 10
  # Description:
  #   This option should be added below the feature SMS_PHONE_ENTRY.
  # Option Values:
  #   50: MAX number of SIM to save SMS, customer to set reasonable value accoring to SIM, if too bigger, waster memory, if too smaller, do not display all SMS
  #   100: MAX number of SIM to save SMS, customer to set reasonable value accoring to SIM, if too bigger, waster memory, if too smaller, do not display all SMS
  # Switch-ability:
  #   [Any] -> [Any]

SMS_TOTAL_ENTRY = 20
  # Description:
  #   total number of SMS stored in SIM and NVRAM can be read
  # Option Values:
  #   NA: SMS entities on NVRAM+SIM
  # Switch-ability:
  #   [Any] -> [Any]

SMS_TCARD_ENTRY = 0
  # Description:
  #   Maximum SMS entry in memory card,  #Switch-ability: [Any] -> [Any]
  # Option Values:
  #   NA: Any number value, but it will impact RAM and ROM size.
  # Switch-ability:
  #   [Any] -> [Any]

BACKGROUND_SMS_SUPPORT = FALSE
  # Description:
  #   to enable unified message background sending feature
  # Option Values:
  #   TRUE: support background send: when send SMS, SMS will be saved to Outbox, outbox background send SMS one by one
  #   FALSE: DO not support background send, if user send one SMS, willl display sending screen and send this SMS directly
  # Switch-ability:
  #   N/A

MSG_SMS_EMAIL_SUPPORT = FALSE
  # Description:
  #   To enable SMS Email interworking support from orange project
  # Option Values:
  #   TRUE: support SMS email interworking feature, user can send Email by SMS
  #   FALSE: only support normal SMS send
  # Switch-ability:
  #   FALSE -> TRUE

SOCIAL_NETWORK_SUPPORT = NONE
  # Description:
  #   SNS deep integration configuration
  # Option Values:
  #   NONE: Disable this feature
  #   LIB: Release sns module in binary format.
  # Switch-ability:
  #   LIB -> NONE

TCPIP_RAW_SOCKET_SUPPORT = TRUE
  # Description:
  #   this feature used to turn off raw socket for slim version to reduce code size
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   N/A

QOS_PROFILE_SUPPORT = ALL
  # Description:
  #   If QOS_PROFILE_SUPPORT is NONE, this means the QoS feature is disable.
  #   If QOS_PROFILE_SUPPORT is STATIC, this means the static QoS feature is supported.
  #   If QOS_PROFILE_SUPPORT is DYNAMIC, this means the dynamic QoS feature is supported.
  #   If QOS_PROFILE_SUPPORT is ALL, this means both static and dynamic qos feature is supported.
  #   The static QoS feature is that there is a default GPRS qos default value in customer folder and customer can change default GPRS qos values. The default value will be passed to operator network to tell operator that it uses this default qos setting. If customer doesn't enable static qos feature, there may be some IOT problem. If dynamic QoS feature is another way to change default qos values passed to operator network, there is a API called cbm_set_qos_profile. customer can call this API to set default qos values. The API usage is defined in CBM SAP
  # Option Values:
  #   ALL: .
  #   NONE: .
  #   STATIC: .
  #   DYNAMIC: .
  # Switch-ability:
  #   Non-switchable

UNIFIED_MESSAGE_ADVANCE_FEATURE = NONE
  # Description:
  #   to enable unified message advance feature
  # Option Values:
  #   COMPOSER_LISTOPTION_ARCHIVE: This value already phase out
  #   NONE: Disable all message advance feature
  #   LISTOPTION: This value already phase out
  #   ARCHIVE: enable  message archive feature
  #   LISTOPTION_ARCHIVE: This value already phase out
  #   COMPOSER_LISTOPTION: This value already phase out
  #   COMPOSER: enable unified message composer feature
  #   COMPOSER_ARCHIVE: enable unified message composer and archive feature
  # Switch-ability:
  #   [Any] -> [Any]

UNIFIED_MESSAGE_FOLDER = FALSE
  # Description:
  #   to enable unified message feature
  # Option Values:
  #   TRUE: Enable unified message folder feature
  #   FALSE: Disable unified message folder feature
  # Switch-ability:
  #   N/A

UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE = FALSE
  # Description:
  #   "Mark several" feature is multiple operation of messages.
  #   End users can mark several messages and do the operation on them together.
  # Option Values:
  #   TRUE: Enable message mark several feature
  #   FALSE: Disable message mark several feature
  # Switch-ability:
  #   [Any] -> [Any]

UNIFIED_MESSAGE_SIMBOX_SUPPORT = FALSE
  # Description:
  #   MT SMS stored in phone only. SIM message box would be displayed to show SMS stored in SIM.
  # Option Values:
  #   TRUE: Enable message SIM box feature
  #   FALSE: Disable message SIM box feature
  # Switch-ability:
  #   [Any] -> [Any]

UNIFIED_MESSAGE_SORT_MESSAGE_LIST = FALSE
  # Description:
  #   Enable the unified message sort feature
  # Option Values:
  #   TRUE: Enable message sort feature
  #   FALSE: Disable message sort feature
  # Switch-ability:
  #   [Any] -> [Any]

WBXML_SUPPORT = FALSE
  # Description:
  #   to enable wbxml parser function
  # Option Values:
  #   TRUE: Enable WBXML.
  #   FALSE: Disable WBXML.
  # Switch-ability:
  #   TRUE -> FALSE

XML_SUPPORT = TRUE
  # Description:
  #   to enable xml parser function
  # Option Values:
  #   TRUE: Enable XML.
  #   FALSE: Disable XML.
  # Switch-ability:
  #   TRUE -> FALSE

UDX_SUPPORT = FALSE
  # Description:
  #   Enable the feature of UDX support.
  # Option Values:
  #   TRUE: Enable UDX support
  #   FALSE: Disable UDX Support
  # Switch-ability:
  #   N/A

PNS_SUPPORT = FALSE
  # Description:
  #   Support PUSH notification servcie
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

GOOGLE_SEARCH_SUPPORT = FALSE
  # Description:
  #   Idle and browser support google search. Customer must sign google search distribution agreement then can get this feature in the SW package
  # Option Values:
  #   TRUE: Enable this feature when customer has signed the google search distribution agreement
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

FACEBOOK_CONTENT_SUPPORT = FALSE
  # Description:
  #   To control the release of facebook related contents (including MRE and Widget clients)
  # Option Values:
  #   TRUE: To preload all licensed facebook applications.
  #   FALSE: Not to preload all licensed facebook applications.
  # Switch-ability:
  #   TRUE -> FALSE

FACEBOOK_SNS_SUPPORT = FALSE
  # Description:
  #   To enable facebook support in SNS deep integration. Customer has to have the license to enable this option.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   TRUE -> FALSE

TWITTER_CONTENT_SUPPORT = FALSE
  # Description:
  #   For releasing twitter related feature files
  # Option Values:
  #   TRUE: Release relevant content files
  #   FALSE: Do not release relevant content files
  # Switch-ability:
  #   TRUE -> FALSE

TWITTER_SNS_SUPPORT = FALSE
  # Description:
  #   To enable twitter support in SNS deep integration. Customer has to have the license to enable this option.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   TRUE -> FALSE

BT_SPEAKER_SUPPORT = FALSE
  # Description:
  #   To support A2DP and AVRCP sink on MAUI architecture. This feature option will make handset acts as A2DP SINK. It means user can transfer high quality music onto Feature phone when it is connected with Smartphone via Bluetooth Link.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   TRUE -> FALSE

FTPSRV_SUPPORT = FALSE
  # Description:
  #   Enable/disable FTP server
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

# ------------------------------ Connectivity
BLUETOOTH_SUPPORT = BTMTK_MT6261
  # Description:
  #   The supported Bluetooth chip
  # Option Values:
  #   BTMTK_MT6626: The MAUI load supports MT6626
  #   BTMTK_MT6611: The MAUI load supports MT6611 (phased-out in 11A)
  #   NONE: The MAUI load did not support Bluetooth
  #   BTMTK_MT6616: The MAUI load supports MT6616
  #   BTMTK_MT6612: The MAUI load supports MT6612
  #   BTMTK_MT6612_22_26: The MAUI load supports MT6622, MT6626, MT6612
  #   BTMTK_MT6276: The MAUI load supports MT6276
  #   BTMTK_MT6601: The MAUI load supports MT6601 (phased-out in 11A)
  #   BTMTK_MT6236: The MAUI load supports MT6236
  #   BTMTK_MT6255: The MAUI load supports MT6255
  #   BTMTK_MT6622: The MAUI load supports MT6622
  #   BTMTK_MT6256: The MAUI load supports MT6256
  #   BTMTK_MT6250: The MAUI load supports MT6250
  # Switch-ability:
  #   BTMTK_MT6622 -> BTMTK_MT6612
  #   BTMTK_MT6612_22_26 -> BTMTK_MT6626
  #   BTMTK_MT6612 -> BTMTK_MT6626
  #   BTMTK_MT6626 -> BTMTK_MT6612_22_26
  #   BTMTK_MT6612_22_26 -> BTMTK_MT6622
  #   BTMTK_MT6626 -> BTMTK_MT6622
  #   BTMTK_MT6622 -> BTMTK_MT6612_22_26
  #   BTMTK_MT6612 -> BTMTK_MT6622
  #   BTMTK_MT6626 -> BTMTK_MT6612
  #   BTMTK_MT6612_22_26 -> BTMTK_MT6612
  #   BTMTK_MT6622 -> BTMTK_MT6626
  #   BTMTK_MT6612 -> BTMTK_MT6612_22_26

BT_CONNECT_TO_UART2 = FALSE
  # Description:
  #   For non BT built-in project, BT chip can be connected to BB via UART2 or UART3.
  #   UART & BT drivers may need to know the information and change configurations.
  # Option Values:
  #   TRUE: BT is connected to UART2
  #   FALSE: BT is connected to UART3
  # Switch-ability:
  #   Non-switchable

BT_DIALER_SUPPORT = FALSE
  # Description:
  #   To make MTK feature phone act as BT Handsfree Unit. In this mode, user can hear audio from remote device (connected via Bluetooth) while GSM modem is being used at the the remote side for incoming and outgoing call
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   TRUE -> FALSE

BT_DUN_PROFILE = FALSE
  # Description:
  #   To turn on/off Dial-Up Networking profile
  # Option Values:
  #   TRUE: Turn on DUN support
  #   FALSE: Turn off DUN support
  # Switch-ability:
  #   TRUE -> FALSE

BT_FAX_PROFILE = FALSE
  # Description:
  #   Turn on/off Bluetooth FAX profile feature.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   Non-switchable

BT_FTC_PROFILE = FALSE
  # Description:
  #   To turn on/off FTP Client profile
  # Option Values:
  #   TRUE: Turn on FTP client role support
  #   FALSE: Turn off FTP client role support
  # Switch-ability:
  #   TRUE -> FALSE

BT_FTS_PROFILE = FALSE
  # Description:
  #   To turn on/off  FTP Server profile
  # Option Values:
  #   TRUE: Turn on FTP server role support
  #   FALSE: Turn off FTP server role support
  # Switch-ability:
  #   TRUE -> FALSE

BT_HFG_PROFILE = FALSE
  # Description:
  #   To turn on/off  Hands-Free Gateway profile
  # Option Values:
  #   TRUE: Turn on HFP/HSP gateway role support
  #   FALSE: Turn off HFP/HSP gateway role support
  # Switch-ability:
  #   TRUE -> FALSE

BT_HIDD_PROFILE = FALSE
  # Description:
  #   To turn on/off bluetooth HID profile
  # Option Values:
  #   TRUE: Turn on HID Device role support
  #   FALSE: Turn off HID Device role support
  # Switch-ability:
  #   TRUE -> FALSE

BT_MAPC_PROFILE = FALSE
  # Description:
  #   To enable Bluetooth Message Access Profile client. This feature is a part of BT dialer support feature. It helps user to view/send sms of remote device
  # Option Values:
  #   FALSE: Disable this feature: By setting it to False, it ll disable thsi feature
  #   TRUE: Enable this feature: By setting it to TRUE, it ll enable this feature
  # Switch-ability:
  #   TRUE -> FALSE

BT_OPP_PROFILE = FALSE
  # Description:
  #   To turn on/off Object Push profile
  # Option Values:
  #   TRUE: Turn on OPP support
  #   FALSE: Turn off OPP support
  # Switch-ability:
  #   TRUE -> FALSE

BT_PBAP_PROFILE = FALSE
  # Description:
  #   bluetooth phonebook access profile support
  # Option Values:
  #   TRUE: enable this feature
  #   FALSE: disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

BT_PBAPC_PROFILE = FALSE
  # Description:
  #   To Support Phonebook access profile client. It ll help user to view phonebook of remote device connected via Bluetooth.
  #   User ll be able to edit the phonebook entires of the remote device and it can also make a call using the remote device entry.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   TRUE -> FALSE

BT_SIM_PROFILE = FALSE
  # Description:
  #   Turn on/off Bluetooth SIMAP profile feature.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   TRUE -> FALSE

BT_SPP_CLIENT = BT_SPP_CLI_NO_SCO
  # Description:
  #   Turn on/off Bluetooth SPP CLient feature
  # Option Values:
  #   NONE: Disable this feature
  #   BT_SPP_CLI_NO_SCO: If set this, it means open normal SPP Client feature and could connect remote SPP Server.
  #   BT_SPP_CLI_WITH_SCO: If set this, it means open normal SPP Client feature with extra feature to create SCO link with remote.
  # Switch-ability:
  #   BT_SPP_CLI_NO_SCO -> NONE

BT_SPP_PROFILE = TRUE
  # Description:
  #   To turn on/off Serial Port profile
  # Option Values:
  #   TRUE: Turn on SPP support
  #   FALSE: Turn off SPP support
  # Switch-ability:
  #   TRUE -> FALSE

BT_SPP_SERVER = BT_SPP_SRV_NO_SCO
  # Description:
  #   Bluetooth SPP proilfe Server role
  # Option Values:
  #   NONE: If set this, it means SPP Server is not support.
  #   BT_SPP_SRV_NO_SCO: If set this, it means open normal SPP server feature and could accept remote SPP connection request.
  #   BT_SPP_SRV_WITH_SCO: If set this, it means open noemal SPP feature with extra feature to create SCO link with remote device.
  # Switch-ability:
  #   BT_SPP_SRV_NO_SCO -> NONE



GPS_UART_PORT = NONE
  # Description:
  #   Set GPS UART HW usage port
  # Option Values:
  #   UART2: If this value is set, it means GPS UART port use UART2
  #   NONE: If GPS is not supported(the GPS_SUPPORT set to NONE). This option set to NONE also.
  #   UART3: If this value is set, it means GPS UART port use UART3
  # Switch-ability:
  #   [Any] -> [Any]

USB_HS_SUPPORT = FALSE
  # Description:
  #   Customer can use this compileoption to decide USB2.0 or USB1.1. TRUE:: work in USB2.0
  # Option Values:
  #   TRUE: Enable USB High-Speed
  #   FALSE: Disable USB High-Soeed mode (Run in Full Speed)
  # Switch-ability:
  #   TRUE -> FALSE

USB_BOOTUP_TRACE = FALSE
  # Description:
  #   Enable bootup trace via USB
  #   Should enable KEYPAD_DEBUG_TRACE or KAL_RECORD_BOOTUP_LOG as well
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

USB_DATA_CONNECTION_SUPPORT = FALSE
  # Description:
  #   To enable data connection feature.
  #   If value is TRUE, define this as global compile option.
  # Option Values:
  #   TRUE: Enable
  #   FALSE: Disable
  # Switch-ability:
  #   TRUE -> FALSE

USB_MULTIPLE_COMPORT_ENABLE = TRUE
  # Description:
  #   To enable USB multiple com port feature
  # Option Values:
  #   TRUE: Enable multiple usb comport
  #   FALSE: disable multiple usb comport
  # Switch-ability:
  #   [Any] -> [Any]

USB_HIGH_SPEED_COM_PORT_SUPPORT = FALSE
  # Description:
  #   USB High Speed Interface API usage.
  # Option Values:
  #   TRUE: Enable USB high-speed comport interface API
  #   FALSE: Disable USB high-speed comport interface API
  # Switch-ability:
  #   [Any] -> [Any]

USB_IN_NORMAL_MODE_SUPPORT = TRUE
  # Description:
  #   When this option is enable, the USB Mass Storage function could be used in normal mode. That is, the targe doesn't need to reboot when the user select "Mass Storage" in the USB query menu.
  # Option Values:
  #   TRUE: Support USB mass storage in USB normal boot mode
  #   FALSE: Mass Storage only work on charging boot mode
  # Switch-ability:
  #   [Any] -> [Any]

USB_MASS_STORAGE_SUPPORT = TRUE
  # Description:
  #   enable USB mass storage feature
  # Option Values:
  #   TRUE: Support USB mass storage function
  #   FALSE: doesn't  support Mass Storage  function
  # Switch-ability:
  #   N/A

USB_MASS_STORAGE_CDROM_SUPPORT = FALSE
  # Description:
  #   enable USB mass storage feature
  # Option Values:
  #   N/A
  # Switch-ability:
  #   [Any] -> [Any]

USB_DOWNLOAD_IN_BL = NONE
  # Description:
  #   enable factory download / connection via USB cable via Bootloader
  # Option Values:
  #   NONE: USBDL in Bootloader is disabled
  #   NORMAL: USBDL in Bootloader is enabled for non-secure platform
  #   SECURE: USBDL in Bootloader is enabled for secure platform
  # Switch-ability:
  #   NORMAL -> NONE

USB_MULTI_CHARGE_CURRENT_SUPPORT = FALSE
  # Description:
  #   To make USB device mode support multiple configurations, i.e., it supports multiple charging currents defined in USB_CHARGE_CURRENT[] table.
  #   Note that it only effects when we set enable_usb_charge as false
  # Option Values:
  #   TRUE: Support multiple charging current in USB
  #   FALSE: Disable multiple charging current in USB (Only 0ma and 500ma)
  # Switch-ability:
  #   [Any] -> [Any]

GENERAL_EXTERNAL_CHARGER = NONE
  # Description:
  #   The feature is to indicate whether we use external charger or NOT
  # Option Values:
  #   NONE: no external charger
  #   ISL9221: external charger type is ISL9221
  #   BQ25040: external charger type is BQ25040
  #   RT9505_BQ24020: external charger type is RT9505_BQ24020
  #   STT818B: external charger type is STT818B
  # Switch-ability:
  #   [Any] -> [Any]

DMA_UART_VFIFO_TUNNEL_SUPPORT = FALSE
  # Description:
  #   enable the VFIFO support UART for separate tx or rx
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

DMA_UART_VIRTUAL_FIFO = TRUE
  # Description:
  #   Support UART Virtual FIFO
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

# ------------------------------ Multimedia
3D_IMAGE_SUPPORT = FALSE
  # Description:
  #   To enable the feature of 3D image capture, which can be seen through red-blue glasses
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

AUDIO_CLIPPER_SUPPORT = FALSE
  # Description:
  #   The audio clipper function is to clip audio segment from an audio file. The audio clip could be used as ringtone.
  # Option Values:
  #   TRUE: Enable audio clipper
  #   FALSE: Disable audio clipper
  # Switch-ability:
  #   FALSE -> TRUE
  #   TRUE -> FALSE

IMAGE_VIEWER_VER = NONE
  # Description:
  #   Version of ImageViewer APP.
  # Option Values:
  #   SLIM: Simple version. Not support zoom and tool panel.
  #   STANDARD: Standard version. Support zoom and tool panel.
  #   EX: Ex version. Support zoom, tool panel with fancy effect. Use default cache memory allocation machenism.
  #   EX_DB: Ex with DB cache and cache memory use default allocation machenism.
  #   EX_SHARE_MEDMEM: Ex with cache memory allocated from MED pool.
  #   EX_DB_SHARE_MEDMEM: EX_DB with cache memory allocated from MED pool.
  #   NONE: With no imageviewer. The value cannot be set currently.
  # Switch-ability:
  #   Non-switchable

INTERGRAFX_SUPPORT = NONE
  # Description:
  #   Co-work with vendor InterGrafx to support those features in QVGA/WQVGA/HVGA/WVGA LCD resolution:
  #   a) Pre-integrated InterGrafx engine
  #   b) 10 live wallpapers for MT6236/MT6276 for Venus home screen.
  #   c) Customize tools for live wallpapers
  #
  #   ( 4 3D games for MT6236/MT6276 tracked by FMS00065384)
  # Option Values:
  #   NONE: Disable intergrafx live wallpaper & game
  #   INTERGRAFX_ENGINE_EN_BASIC: Enable  4 Intergrafx wallpaper and 1 game (English version)
  #   INTERGRAFX_ENGINE_CH_BASIC: Enable  4 Intergrafx wallpaper and 1 game (Chinese version)
  #   INTERGRAFX_ENGINE_EN_VALUED: Enable  9 Intergrafx wallpaper and 2 games (English version)
  #   INTERGRAFX_ENGINE_CH_VALUED: Enable  9 Intergrafx wallpaper and 2 games (Chinese version)
  #   INTERGRAFX_ENGINE_EN_FULL: Enable 10 Intergrafx wallpaper and 2 games (English version)
  #   INTERGRAFX_ENGINE_CH_FULL: Enable 10 Intergrafx wallpaper and 2 games (Chinese version)
  # Switch-ability:
  #   [Any] -> [Any]

MELODY_BUFFER_LEN = 512
  # Description:
  #   Defining buffer midi/imelody files to provide different number of notes supported
  # Option Values:
  #   512: Support up to 512 bytes MIDI file
  #   307200: Support up to 307200 bytes MIDI file
  #   1024: Support up to 1024 bytes MIDI file
  #   102400: Support up to 102400 bytes MIDI file
  #   20480: Support up to 20480 bytes MIDI file
  #   1300: Support up to 1300 bytes MIDI file
  #   81920: Support up to 81920 bytes MIDI file
  # Switch-ability:
  #   81920 -> 20480

# ------------------------------ Audio
TWOMICNR_SUPPORT = NONE
  # Description:
  #   External two MIC support ( ForteMedia)
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   N/A

EXT_DAC_SUPPORT = FALSE
  # Description:
  #   To enable the interface between AFE control and EXT_DAC control.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   [Any] -> [Any]

EXTERNAL_AMPLIFIER_ROUTE_CONFIGURATION = FALSE
  # Description:
  #   configure external amplifier router
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   N/A

GAIN_TABLE_SUPPORT = FALSE
  # Description:
  #   If GAIN_TABLE_SUPPORT is set to TRUE, the project is allowed to customize gain table in custom folder.
  #   If GAIN_TABLE_SUPPORT is set to FALSE, MED will be responsible for updating gain (current MAUI design).
  # Option Values:
  #   TRUE: Enable gain table
  #   FALSE: Disable gain table
  # Switch-ability:
  #   FALSE -> TRUE
  #   TRUE -> FALSE

MMA_MAX_NUM = 2
  # Description:
  #   Specify the maximum number of  MMA players. The default setting is 12, which means we could play up to 12 MMA players concurrently. For slim project, we could reduce the maximum number (e.g. 6) to save memory.
  # Option Values:
  #   6:
  #   11:
  #   3:
  #   7:
  #   9:
  #   12:
  #   2:
  #   8:
  #   4:
  #   10:
  #   5:
  # Switch-ability:
  #   N/A

VM_CODEC = FALSE
  # Description:
  #   For speech debug
  # Option Values:
  #   TRUE: Support VM playback and recording
  #   FALSE: Not support VM
  # Switch-ability:
  #   TRUE -> FALSE

SPECTRUM_DISPLAY = FALSE
  # Description:
  #   VM (voice memo) playback and recording for speech debug.
  # Option Values:
  #   TRUE: Support spectrum display
  #   FALSE: Not support spectrum display
  # Switch-ability:
  #   TRUE -> FALSE

# ------------------------------ Speech
NVRAM_AFE_DIGITAL_GAIN_SUPPORT = FALSE
  # Description:
  #   NVRAM afe digital gain control
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   N/A

# ------------------------------ Video
3D_ANAGLYPH = FALSE
  # Description:
  #   3d anaglyph support, it can decode a 3D video from MOT tool
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

HD_RECORD_SUPPORT = FALSE
  # Description:
  #   Enable/Disable high definition recording. Only MT6255/6256/6276 and later chip support it
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   N/A

CMMB_CAS_2GPP_VER = NONE
  # Description:
  #   Support 2G CMMB Post paid in two or more segament,
  #   Currently only support version 1 (No cost for user, only support Account/Authorize)
  # Option Values:
  #   NONE: Disable this feature
  #   V10: Support 2G CMMB Post paid version 1.0 (Support ¿ª»§/ÊÚÈ¨,need 2G CMMB Chip Support,Such as IF206)
  # Switch-ability:
  #   Non-switchable

H264_DECODE_PROFILE = BASELINE
  # Description:
  #   This feature option identifies supporting profile  when H264DEC opens.
  # Option Values:
  #   BASELINE: Only support baseline profile
  #   MAINHIGH: Support high profile
  # Switch-ability:
  #   MAINHIGH -> BASELINE
  #   BASELINE -> MAINHIGH

H264_ENCODE = FALSE
  # Description:
  #   Turn on/off H264 SW encoder support
  # Option Values:
  #   TRUE: support SW h264 encode
  #   FALSE: does not support SW h264 encode
  # Switch-ability:
  #   TRUE -> FALSE

FLV_FILE_FORMAT_SUPPORT = FALSE
  # Description:
  #   Turn on/off FLV file format support
  # Option Values:
  #   TRUE: Flash video file format is supported
  #   FALSE: Flash video file format is NOT supported
  # Switch-ability:
  #   TRUE -> FALSE

MP4_DECODE_PROFILE = NONE
  # Description:
  #   This feature option identifies supporting profile  when MP4DEC opens.
  # Option Values:
  #   SP: Onlu support simple profile
  #   ASP: Support both simple profile and advanced simple profile
  #   NONE: Describe MP4 decoder disable
  # Switch-ability:
  #   ASP -> SP
  #   [Any] -> [Any]
  #   SP -> ASP

PGDL_SUPPORT = FALSE
  # Description:
  #   to enable streaming function
  # Option Values:
  #   TRUE: Progressive download is supported
  #   FALSE: Progressive download is not supported
  # Switch-ability:
  #   Non-switchable

MOT_SUPPORT = FALSE
  # Description:
  #   to enable Movie Theater feature.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   FALSE -> TRUE
  #   TRUE -> FALSE

MJPG_DECODE = FALSE
  # Description:
  #   To enable Mjpeg decoder.
  # Option Values:
  #   TRUE: support motion jpeg decode
  #   FALSE: does not support motion jpeg decode
  # Switch-ability:
  #   TRUE -> FALSE

MJPG_ENCODE = FALSE
  # Description:
  #   To enable Mjpeg encoder
  # Option Values:
  #   TRUE: support motion jpeg encode
  #   FALSE: support motion jpeg encode
  # Switch-ability:
  #   TRUE -> FALSE

MULTIPLE_ANGLE_VIEW_SUPPORT = FALSE
  # Description:
  #   To support a fancy camera application which could take 3D-like pictures
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   FALSE -> TRUE
  #   TRUE -> FALSE

TIME_LAPSE_VIDEO_RECORDER = DISABLE
  # Description:
  #   Turn on and off TIME_LAPSE_VIDEO_RECORDER by setting its value to ENABLE and DISABLE respectively.
  # Option Values:
  #   DISABLE: Disable this feature
  #   ENABLE: Enable this feature
  # Switch-ability:
  #   N/A

RM_DECODE = FALSE
  # Description:
  #   When RM_DECODE = TRUE/FALSE, turn on/off Real Media video decode support
  # Option Values:
  #   TRUE: enable this feature
  #   FALSE: disable this feature
  # Switch-ability:
  #   N/A

SIDE_BY_SIDE_3D_VIDEO = DISABLE
  # Description:
  #   This feature option is to turn ON/OFF the run-time rendering of side-by-side 3D videos. When this feature is on, player shows an red-cyan glasses icon on screen. When users press the icon, target render side-by-side 3D video to red-cyan anaglyph video. Then users can see stereo video by wearing red-cyan 3D glasses.
  # Option Values:
  #   ENABLE: Enable this feature
  #   DISABLE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

STREAM_SUPPORT = FALSE
  # Description:
  #   to enable streaming function
  # Option Values:
  #   TRUE: to enable video streaming
  #   FALSE: to disable video streaming
  # Switch-ability:
  #   [Any] -> [Any]

VIDEO_PLAYER_RECORDER_W_DCM = DISABLE
  # Description:
  #   To enable video player/recorder middleware DCM with compression mechanism.
  # Option Values:
  #   ENABLE: Enable this feature
  #   DISABLE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

VP8_DECODE = FALSE
  # Description:
  #   VP8_DECODE is used to enable or disable to support VP8 SW DEcoder
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

# ------------------------------ Camera
AF_AUXI_LED_SUPPORT = FALSE
  # Description:
  #   AF auxiliary LED feature enable/disable, under low light environment, auxiliary LED will emit to let AF function better quality & performance
  #   If switch from FALSE to TRUE, FlashlightPowerOn() function must implemented in custom\drv\camera\[proj]\camera_hw.c
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   [Any] -> [Any]

AF_SUPPORT = FALSE
  # Description:
  #   to enable Auto Focus function
  #   If switch from FALSE to TRUE, LENS_MODULE must not be NONE, except YUV sensor project.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   [Any] -> [Any]

BACKUP_SENSOR_SUPPORT = FALSE
  # Description:
  #   support multiple sensors with a single firmware bin file. It doesn't need to change firmware when change sensor module on production line.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   [Any] -> [Any]

CAMCORDER_SUPPORT = NONE
  # Description:
  #   Check if camcorder support. If yes, camera and video recorder will be turned off.
  # Option Values:
  #   SLIM:
  #   TRUE:
  #   NONE:
  #   CUSTOM:
  #   FULL:
  #   FALSE:
  #   STANDARD:
  # Switch-ability:
  #   STANDARD -> FULL
  #   FULL -> SLIM
  #   STANDARD -> SLIM
  #   SLIM -> STANDARD
  #   FULL -> STANDARD
  #   SLIM -> FULL

CAMCORDER_AUTO_SCENE_DETECT_SUPPORT = FALSE
  # Description:
  #   Support auto scene detection capture mode for camcoder
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

CAMCORDER_FACE_DETECTION_MODE_SUPPORT = FALSE
  # Description:
  #   To enable camcorder face detection mode
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   TRUE -> FALSE

CAMCORDER_MULTIPLE_DISPLAY_BUFFER_SUPPORT = DISABLE
  # Description:
  #   Camcorder support multiple display buffer for MDP.
  # Option Values:
  #   ENABLE: Enable this feature
  #   DISABLE: Disable this feature
  # Switch-ability:
  #   DISABLE -> ENABLE
  #   ENABLE -> DISABLE

CAMCORDER_SMILE_SHUTTER_MODE_SUPPORT = FALSE
  # Description:
  #   if this feature is enabled, it will enable the function to automatically capture while the smile in a face is detected
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   [Any] -> [Any]

CAMCORDER_ZERO_SHUTTER_DELAY_SUPPORT = FALSE
  # Description:
  #   Support Zero Shutter Delay capture mode for camcoder
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   FALSE -> TRUE
  #   TRUE -> FALSE

DUAL_CAMERA_SUPPORT = FALSE
  # Description:
  #   Enable the feature of dual camera support for end user
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   TRUE -> FALSE

CMOS_SENSOR_BAK1 = NONE
  # Description:
  #   Set sensor module of main backup camera
  # Option Values:
  #   NA:
  #   NONE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

SENSOR_ROTATE = SENSOR_ROTATE_90
  # Description:
  #   For different camera hw module mount direction.
  # Option Values:
  #   SENSOR_ROTATE_90:
  #   SENSOR_ROTATE_180:
  #   SENSOR_ROTATE_0:
  #   SENSOR_ROTATE_270:
  # Switch-ability:
  #   N/A

SENSOR_TYPE = NONE
  # Description:
  #   indicate the sensor type
  # Option Values:
  #   YUV:
  #   NONE:
  #   RAW:
  # Switch-ability:
  #   Non-switchable

CMOS_SENSOR_SUB = NONE
  # Description:
  #   Set sensor module of sub camera
  # Option Values:
  #   NONE:
  #   NA:
  # Switch-ability:
  #   [Any] -> NA

CMOS_SENSOR_SUB_BAK1 = NONE
  # Description:
  #   Set sensor module of sub backup camera
  # Option Values:
  #   NA:
  #   NONE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

SENSOR_SUB_ROTATE = SENSOR_ROTATE_0
  # Description:
  #   Set the angle between sensor scan direction and handset.
  # Option Values:
  #   SENSOR_ROTATE_90:
  #   SENSOR_ROTATE_180:
  #   SENSOR_ROTATE_0:
  #   SENSOR_ROTATE_270:
  # Switch-ability:
  #   [Any] -> [Any]

SENSOR_TYPE_SUB = NONE
  # Description:
  #   indicate the sub sensor type
  # Option Values:
  #   YUV:
  #   NONE:
  #   RAW:
  # Switch-ability:
  #   Non-switchable

CAPTURE_SCENARIO = NONE
  # Description:
  #   Indicate on the fly or off line capture
  # Option Values:
  #   OFFLINE:
  #   STANDARD:
  #   ON_THE_FLY:
  # Switch-ability:
  #   Non-switchable

FLASHLIGHT_TYPE = NONE
  # Description:
  #   Set flashlight type
  # Option Values:
  #   NONE:
  #   LED_FLASHLIGHT_SUPPORT:
  # Switch-ability:
  #   N/A

HIGH_DYNAMIC_RANGE_SUPPORT = FALSE
  # Description:
  #   Support High Dynamic Range capture mode for camcoder
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   TRUE -> FALSE

HORIZONTAL_CAMERA = TRUE
  # Description:
  #   To enable horizontal camera feature.
  #   Add HORIZONTAL_CAMERA to global compile option when the value is TRUE.
  # Option Values:
  #   TRUE: Camera or Camcorder with Horizontal  UI
  #   FALSE: Camera or Camcorder with Vertical UI
  # Switch-ability:
  #   [Any] -> [Any]

LENS_MODULE = NONE
  # Description:
  #   Set the lens module of main camera
  #   If switch from Any to NONE, AF_SUPPORT must set to FALSE, except YUV sensor project.
  #   If switch from NONE to Any, AF_SUPPORT must set to TRUE.
  # Option Values:
  #   NA:
  #   NONE: Disable this feature
  # Switch-ability:
  #   [Any] -> NONE
  #   NONE -> [Any]

LENS_MODULE_BAK1 = NONE
  # Description:
  #   Set the lens module of main backup camera
  # Option Values:
  #   NA:
  #   NONE: Disable this feature
  # Switch-ability:
  #   [Any] -> NONE

AUTOCAP_PANORAMA_MODE = 3
  # Description:
  #   Each mode represents different spec and memory usage.
  #   The value ranges from 3 to 8.
  # Option Values:
  #   3: Maximum capture image number is 3
  #   4: Maximum capture image number is 4
  #   5: Maximum capture image number is 5
  #   6: Maximum capture image number is 6
  #   7: Maximum capture image number is 7
  #   8: Maximum capture image number is 8
  # Switch-ability:
  #   [Any] -> [Any]

SENSOR_LOCATION = SENSOR_ON_BODY
  # Description:
  #   For different camera hw module mount location.
  # Option Values:
  #   SENSOR_ON_BODY:
  #   SENSOR_ON_COVER:
  # Switch-ability:
  #   N/A

WEBCAM_SUPPORT = FALSE
  # Description:
  #   To enable webcam feature.
  #   If value is TRUE, define this as global compile option.
  # Option Values:
  #   TRUE: Enable Webcam
  #   FALSE: Disable Webcam
  # Switch-ability:
  #   [Any] -> [Any]

COMPOSITE_WEBCAM_SUPPORT = FALSE
  # Description:
  #   Customer can use this compileoption to decide Webcam Composite Device: Webcam+CDC ACM or pure Webcam Device
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

YUVCAM_INTERPOLATION = NONE
  # Description:
  #   YUVCAM_INTERPOLATION = HW  means to use HW Resizer to do this interpolation.YUVCAM_INTERPOLATION = SW means touse SW JPEG Encoder to do this interpolation.
  # Option Values:
  #   SW:
  #   NONE:
  #   HW:
  # Switch-ability:
  #   [Any] -> [Any]

# ------------------------------ Graphic
GDI_SCREEN_SHOT_BUFFER = OFF
  # Description:
  #   If ON, preserve a global memory buffer for some debug tool to get the screen shot, the memory size is LCD_WIDTH*LCD_HEIGHT*2. If OFF, there is not such memory, then the screen shot function of those debug tools would not be able to use.
  # Option Values:
  #   ON: Support tool snapshop feature
  #   OFF: Disable tool snapshop feature
  # Switch-ability:
  #   [Any] -> [Any]

GIF_DECODE = FALSE
  # Description:
  #   Support for 11A/11B branch.
  #   This option define if SW/HW GIF decoder support or not.
  # Option Values:
  #   TRUE:
  #   NONE:
  #   FALSE:
  #   GIF_HW:
  #   GIF_SW:
  # Switch-ability:
  #   [Any] -> [Any]

JPG_DECODE_PROGRESSIVE_CAPABILITY = BASELINE
  # Description:
  #   To select jpeg decode support capability
  # Option Values:
  #   BASELINE: support decode baseline jpeg images only. (no progressive image)
  #   PROGRESSIVE_03M: support decode progressive jpeg images of 0.3 mega pixels. (640x480)
  #   PROGRESSIVE_1M: support decode progressive jpeg images of 1 mega pixels. (1280x960)
  #   PROGRESSIVE_2M: support decode progressive jpeg images of 2 mega pixels. (1600x1200)
  #   PROGRESSIVE_3M: support decode progressive jpeg images of 3 mega pixels. (2048x1536)
  # Switch-ability:
  #   [Any] -> [Any]

SCALADO_SUPPORT = FALSE
  # Description:
  #   using SCALADO Caps engine to enhance applications: Image Viewer and Photo Editor
  # Option Values:
  #   TRUE: Turn on SCALADO Caps engine with image viewer and photo editor
  #   FALSE: not use SCALADO caps engine.
  # Switch-ability:
  #   Non-switchable

# ------------------------------ Security
DISABLE_A5_2 = TRUE
  # Description:
  #   Disable A5/2 cipering algo
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

OCSP_SUPPORT = FALSE
  # Description:
  #   To support OCSP (Online Certificate Status Protocol) for socket SSL handshakes.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   N/A

SECURE_VERSION = 1
  # Description:
  #   Support security system
  # Option Values:
  #   1: Secure version 1
  #   0: Secure version 0
  # Switch-ability:
  #   [Any] -> [Any]

SECURE_CUSTOM_NAME = MTK
  # Description:
  #   Support security system
  # Option Values:
  #   JRD: .
  #   NONE: No customer name specified, non secure load only
  #   MTK: Customer name for MTK
  # Switch-ability:
  #   [Any] -> [Any]

SECURE_JTAG_ENABLE = FALSE
  # Description:
  #   Support security system
  # Option Values:
  #   TRUE: The JTAG on the phone will b on
  #   FALSE: The JTAG on the phone will b off
  # Switch-ability:
  #   FALSE -> TRUE
  #   TRUE -> FALSE

SOCKET_SSL_SUPPORT = TRUE
  # Description:
  #   To provide SSL APIs in socket API style.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   N/A

SSL_SUPPORT = OPENSSL_MTK
  # Description:
  #   SSL library for secure connections with SSL/TLS.
  # Option Values:
  #   NONE: Disable this feature
  #   OPENSSL: Use OpenSSL library to support SSL protocol.
  #   OPENSSL_MTK: Use OpenSSL library to support SSL protocol, but replace the cipher engine with Mediatek home made ones.
  # Switch-ability:
  #   OPENSSL_MTK -> NONE
  #   OPENSSL -> NONE

# ------------------------------ Modem
BAND_SUPPORT = QUAD
  # Description:
  #   Described the support band of RF
  # Option Values:
  #   DUAL900: Support 900/1800
  #   EGSM900: Support 900
  #   RGSM900: Support 900
  #   DCS1800: Support 1800
  #   PGSM900: Support 900
  #   QUAD: Support 850/900/1800/1900
  #   DUAL850: Support 850/1900
  #   PCS1900: Support 1900
  #   GSM480: Support 480
  #   GSM850: Support 850
  #   TRIPLE: Support 900/1800/1900
  #   GSM450: Support 450
  # Switch-ability:
  #   QUAD -> [Any]
  #   DUAL900 -> DCS1800
  #   TRIPLE -> DUAL900
  #   DUAL850 -> GSM850
  #   TRIPLE -> DCS1800
  #   DUAL900 -> EGSM900
  #   TRIPLE -> EGSM900
  #   TRIPLE -> PCS1900
  #   DUAL850 -> PCS1900

GPRS_CLASS_10 = FALSE
  # Description:
  #   This is for AT&T requirement that Handset can only have multislot class 10. However our default setting is multielost class 12. So we need this feature option to let customer open this feature if they want to pass AT&T cases
  # Option Values:
  #   TRUE: EDGE Multislot Class 10
  #   FALSE: GPRS Multislot Class 12
  # Switch-ability:
  #   N/A

EDGE_CLASS_10 = FALSE
  # Description:
  #   This is for AT&T requirement that Handset can only have multislot class 10. However our default setting is multielost class 12. So we need this feature option to let customer open this feature if they want to pass AT&T cases
  # Option Values:
  #   TRUE: GPRS Multislot Class 10
  #   FALSE: GPRS Multislot Class 12
  # Switch-ability:
  #   N/A

BIP_SCWS_SUPPORT = FALSE
  # Description:
  #   BIP SCWS feature:
  #   Server mode: To establish channel between Browser and UICC
  #   Client mode: To establish channel between UICC and network
  # Option Values:
  #   TRUE: Enable BIP support
  #   FALSE: Disable BIP support(default)
  # Switch-ability:
  #   Non-switchable

CMUX_SUPPORT = FALSE
  # Description:
  #   Support 07.10 multiplexer feature: TRUE or FALSE
  # Option Values:
  #   TRUE: Enable 27.010 multiplexer
  #   FALSE: Disable 27.010 multiplexer
  # Switch-ability:
  #   Non-switchable

ECC_RETRY_ENHANCEMENT = FALSE
  # Description:
  #   If this feature option is turned on, L4C would retry ECC in other RAT when the first ECC attemp is fail.
  # Option Values:
  #   TRUE: Modem will retry fail ECC on the other RAT
  #   FALSE: Modem will not retry fail ECC on the other RAT
  # Switch-ability:
  #   Non-switchable

WCDMA_PREFERRED = FALSE
  # Description:
  #   enable/disable WCDMA Preferred feature
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   N/A

RSAT_SUPPORT = MODEM_WITH_RSAT
  # Description:
  #   To enable RSAT(STK AT command) feature
  # Option Values:
  #   NONE: Disable RSAT support(default)
  #   MMI_WITH_RSAT: Enable RSAT support in MMI project
  #   MODEM_WITH_RSAT: Enable RSAT support in modem project
  # Switch-ability:
  #   N/A

SIM_RECOVERY_ENHANCEMENT = FALSE
  # Description:
  #   Enable continuous SIM card recovery procedure
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

UMTS_BAND_I = FALSE
  # Description:
  #   Indicates whether UE support UMTS FDD band I
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

UMTS_BAND_II = FALSE
  # Description:
  #   Indicates whether UE support UMTS FDD band II
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   N/A

UMTS_BAND_III = FALSE
  # Description:
  #   Indicates whether UE support UMTS FDD band III
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

UMTS_BAND_IV = FALSE
  # Description:
  #   Indicates whether UE support UMTS FDD band IV
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

UMTS_BAND_V = FALSE
  # Description:
  #   Indicates whether UE support UMTS FDD band V
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

UMTS_BAND_VI = FALSE
  # Description:
  #   Indicates whether UE support UMTS FDD band VI
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

UMTS_BAND_VII = FALSE
  # Description:
  #   Indicates whether UE support UMTS FDD band VII
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

UMTS_BAND_VIII = FALSE
  # Description:
  #   Indicates whether UE support UMTS FDD band VIII
  # Option Values:
  #   TRUE: UE supports UMTS FDD band VIII
  #   FALSE: UE not supports UMTS FDD band VIII
  # Switch-ability:
  #   [Any] -> [Any]

UMTS_BAND_IX = FALSE
  # Description:
  #   Indicates whether UE support UMTS FDD band IX
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

UMTS_BAND_X = FALSE
  # Description:
  #   Indicates whether UE support UMTS FDD band X
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

# ------------------------------ TD-SCDMA
# ------------------------------ File system and System service
DEMAND_PAGING_VERSION = DPV2
  # Description:
  #   Set up which objects will be put to demand paging (DP) area.
  #   Note that the default value will be set to DPv2 by default after W11.37
  # Option Values:
  #   DPV1: Put MMI objects to DP area
  #   DPV2: Put all possible objects to DP area.
  # Switch-ability:
  #   DPV2 -> DPV1

DEMAND_PAGING_AUTO_CONFIG = FALSE
  # Description:
  #   To define if we need to adjust demand page rom size(MAX_DEMAND_PAGING_ROM0_SIZE) in custom_FeatureConfig.h automatically for scatGen
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

EMMC_BOOTING = NONE
  # Description:
  #   eMMC booting (similar to NAND_FLASH_BOOTING)
  # Option Values:
  #   NONE: Disable this feature
  #   BASIC: Only Primary MAUI and Secondary MAUI exist
  #   ONDEMAND: Use demand paging mechanism
  # Switch-ability:
  #   N/A

EXT_BL_UPDATE_SUPPORT = FALSE
  # Description:
  #   This option is to control if we can use USBDL in Bootloader to update ExtBootloader.
  #   If this option is TRUE, bootloader will take more space as backup to make sure all download process will be done in a safe way
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE
  #   FALSE -> TRUE

BLRESERVEDSIZE_AUTOCONFIG = TRUE
  # Description:
  #   To define if we need to adjust bootloader size(MAX_BL_SIZE, MAX_EXT_BL_SIZE) in custom_FeatureConfig.h automatically for scatGen
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

FUNET_ENABLE = NONE
  # Description:
  #   Enable firmware update from the internet (IOT FOTA)
  # Option Values:
  #   FULL_IMAGE_UPDATE: Enable this feature and use full image update
  #   NONE: Disable this feature
  # Switch-ability:
  #   FULL_IMAGE_UPDATE -> NONE
  #   NONE -> FULL_IMAGE_UPDATE

FAST_LOGO_SUPPORT = FALSE
  # Description:
  #   The feature makes the boot-up logo can be shown in BL. End user can have better user experience
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

FS_CACHE_SUPPORT = FALSE
  # Description:
  #   If this feature is enabled, FS will pre-fetching FAT table and directory entries to accelerate file searching and file seeking.
  #   FS dedicate buffer is merged into FS cache, and dynamically allocated from FS cache at runtime.
  # Option Values:
  #   TRUE: Enable FS Cache, FS_DEDICATED_BUFFER must also be enabled.
  #   FALSE: Disable FS Cache
  # Switch-ability:
  #   [Any] -> [Any]

FS_SORT_MAX_ENTRY = 64
  # Description:
  #   FS supports up to sort up to 20000 files.
  # Option Values:
  #   NA: To specify number of sorting entry
  # Switch-ability:
  #   Non-switchable

NVRAM_BACKUP_PARTITION_ON_NOR = ENABLE		#GPS_TRACK
  # Description:
  #   NOR Backup Partition provides a data partition as backup of NVRAM most critical data, i.e. IMEI, SIM-ME-lock, calibration.
  # Option Values:
  #   ENABLE: Enable this feature
  #   DISABLE: Disable this feature
  # Switch-ability:
  #   DISABLE -> ENABLE
  #   ENABLE -> DISABLE

NVRAM_BIND_TO_CHIP_CIPHER = DISABLE
  # Description:
  #   This option enables NVRAM to use HW encryption/decryption on LIDs with attributes NVRAM_ATTR_MSP, i.e. SIM-ME-Lock.
  # Option Values:
  #   ENABLE: Enable this feature
  #   DISABLE: Disable this feature
  # Switch-ability:
  #   ENABLE -> DISABLE

KAL_STACK_LAYOUT = SHARING
  # Description:
  #   Define the TASK stack layout
  # Option Values:
  #   SIMPLE: stack is resident in linear system memory, default
  #   EXTENSIBLE: stack is isolated and dynamic extensible, only support on ARM9/ARM11 platform
  #   ISOLATE: stack is isolated in virtual memory to detect stack overflow, only support on ARM9/ARM11platform
  #   SHARING: All task stack sharing a common pool, and task stack will be allocated/freed dynamically.
  # Switch-ability:
  #   N/A

KAL_TRACE_OUTPUT = FULL
  # Description:
  #   This option is used to enable or disable the trace output for the concern of saving ROM size
  # Option Values:
  #   CUST_PARTIAL: Enable partial traces
  #   NONE: Disable all trace
  #   FULL: Enable all trace
  # Switch-ability:
  #   NONE -> FULL
  #   NONE -> CUST_PARTIAL

PARTIAL_TRACE_LIB = NONE
  # Description:
  #   When module was defined in PARTIAL_TRACE_LIB, the compile option, TRACE_MODULE_OFF, will be un-defined, and it will be buit with TRACE information.
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

CUSTOM_DEBUG_MODULES = NVRAM SYSTEM
  # Description:
  #   CUSTOM_DEBUG_MODULES means these modules will be built with debug information.
  # Option Values:
  #   ALL: all
  #   NONE: Disable this feature
  #   module_names: The modules' name that you want to turn on debug information, seperated by space
  # Switch-ability:
  #   [Any] -> [Any]

CUSTOM_NON_DEBUG_MODULES = NONE
  # Description:
  #   CUSTOM_NON_DEBUG_MODULES means it will be built without debug information after custom release
  # Option Values:
  #   ALL: .
  #   NONE: .
  #   module_names: Module name list using space seperated
  # Switch-ability:
  #   [Any] -> [Any]

KAL_RECORD_BOOTUP_LOG = FALSE
  # Description:
  #   The goal is to print out log via Catcher at the initialization stage. We supply the API for customers and print out each initialization milistone by default. With this facility, customers who do not have Trace32 can easily locat where the problem is via UART at MAUI initialization stage.
  # Option Values:
  #   TRUE: enable boot up trace
  #   FALSE: disable boot up trace
  # Switch-ability:
  #   [Any] -> [Any]

DRV_DEBUG_MEMORY_TRACE_SUPPORT = FALSE
  # Description:
  #   Driver do not want to depend on MMI_FEATURES_SWITCH because sometimes we do need to use memory trace debug on memory monitored project.
  # Option Values:
  #   TRUE: driver will log the trace in memory
  #   FALSE: driver won't log the trace in memory
  # Switch-ability:
  #   TRUE -> FALSE

MULTIPLE_BINARY_FILES = FALSE
  # Description:
  #   This feature option indicate resource binary could be replaced / changed after first time download.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   [Any] -> [Any]

MBA_DEFAULT_BINARY = CUST_AND_LANG
  # Description:
  #   This feature option indicate MBA binary number and type.
  #   There are three type
  #   CUST_ONLY
  #   LANG_ONLY
  #   CUST_AND_LANG
  # Option Values:
  #   LANG_ONLY: Multiple BIN layout contain only langpack BIN and main BIN
  #   CUST_ONLY: Multiple BIN layout contain only custpack BIN and main BIN
  #   CUST_AND_LANG: Multiple BIN layout contain custpack BIN , langpack BIN and main BIN
  # Switch-ability:
  #   [Any] -> [Any]

REDUCE_HEADER_DEPTH = FALSE
  # Description:
  #   To collect used header files to one folder to reduce compiler's searching time.
  # Option Values:
  #   N/A
  # Switch-ability:
  #   [Any] -> [Any]

ZIMAGE_SUPPORT = FALSE
  # Description:
  #   Please refer to CR MAUI_02832638 which was applied to 10AW1041OFD_53EL_SLIM
  # Option Values:
  #   TRUE: Enable code compression to utilize the free RAM space and save ROM space
  #   FALSE: Disable code compression mechanism
  # Switch-ability:
  #   Non-switchable

BOOT_ZIMAGE_SUPPORT = FALSE
  # Description:
  #   BOOT_ZIMAGE is enabled or not. BOOT_ZIMAGE is an extension of ZIMAGE to compress the original un-compressible region.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

ZIMAGE_CONTENT_POLICY = FIT_ROM #MagicNing BEST_PERF
  # Description:
  #   It's an accessory feature option of ZIMAGE_SUPPORT, and is used in zImage auto configuration mechanism to decide the policy of ZIMAGE.
  # Option Values:
  #   BEST_PERF: Utilize all unused free RAM to achieve better footprint and runtime performance.
  #   FIT_ROM: Tyr to reserve maximum free RAM while keepting the load can be build pass.
  #   MUST_ONLY: Only compress the pre-defined objects which must be in ZIMAGE region.
  # Switch-ability:
  #   [Any] -> [Any]

TINY_SYS = FALSE
  # Description:
  #   enable or disable tiny system feature
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   Non-switchable

# ------------------------------ Flash
DUAL_SERIAL_FLASH_SUPPORT = FALSE
  # Description:
  #   Enable 2 serial flash support.
  # Option Values:
  #   TRUE: Enable dual flash support
  #   FALSE: Disable dual serial flash support
  # Switch-ability:
  #   [Any] -> [Any]

NAND_FLASH_BOOTING = NONE
  # Description:
  #   Specify if system has to boot from nand-flash.
  #   If yes, bootloader will be built and MAUI will be splitted into
  #   primary and secondary MAUI.
  # Option Values:
  #   NONE: Disable this feature
  #   BASIC: Only Primary MAUI and Secondary MAUI exist
  #   ONDEMAND: Use demand paging mechanism
  #   ENFB: Enable third ROM
  # Switch-ability:
  #   Non-switchable

NOR_SUPPORT_RAW_DISK = TRUE  #GPS_TRACK
  # Description:
  #   Purpose
  #   (1) Support direct access API for NOR flash.
  #   (2) Support at most 2 additional raw disk regions on NOR flash.
  #   (3) Support flexible settings of disk base address and length. Only need to have disk range aligned with block size.
  #   Usage
  #   (1) Set to TRUE.
  #   (2) Should modify custom_memorydevice.h NOR_BOOTING_NOR_DISK_NUM & NOR_BOOTING_NOR_DISKX_BASE_ADDRESS & NOR_BOOTING_NOR_DISKX_SIZE  to assign disk region.
  #   Limitation
  #   (1) In V32/V33 project, NOR_BOOTING_NOR_DISK_NUM should be 2 and the second disk is treated as Security Partition.
  # Option Values:
  #   TRUE: Enable NOR RAW disk support
  #   FALSE: Disable NOR RAW disk support
  # Switch-ability:
  #   [Any] -> [Any]

OTP_SUPPORT = FALSE
  # Description:
  #   Support One-Time-Programming area for the flash device
  # Option Values:
  #   TRUE: Enable One-Time Program Support
  #   FALSE: Disable One-Time Program Support
  # Switch-ability:
  #   TRUE -> FALSE

COMBO_MEMORY_SUPPORT = TRUE
  # Description:
  #   To support different memory part in the same load.
  # Option Values:
  #   TRUE: Enable combo memory support
  #   FALSE: Disable combo memory support.
  #          Default setting is FALSE.
  # Switch-ability:
  #   [Any] -> [Any]

SIP_RAM_SIZE = 32M_BITS
  # Description:
  #   Set SiP RAM size according to BB chip
  # Option Values:
  #   32M_BITS: SiP 32M bits RAM
  #   64M_BITS: SiP 64M bits RAM
  #   128M_BITS: SiP 128M bits RAM
  #   256M_BITS: SiP 256M bits RAM
  #   NONE: For Non-SiP RAM
  # Switch-ability:
  #   Non-switchable

# ------------------------------ Memory card
DUAL_MEMORY_CARD_SUPPORT = NONE
  # Description:
  #   N/A
  # Option Values:
  #   N/A
  # Switch-ability:
  #   [Any] -> [Any]

# ------------------------------ Tools
ATA_SUPPORT = FALSE
  # Description:
  #   This option is for PCB test in production line.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   TRUE -> FALSE

CAT_IN_ZIMAGE = FALSE
  # Description:
  #   Put CAT section in ZIMAGE region when ZIMAGE_SUPPORT is enabled
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

TST_WRITE_TO_FILE = FALSE
  # Description:
  #   enable tst outputting traces to files
  # Option Values:
  #   TRUE: Enable
  #   FALSE: Disable
  # Switch-ability:
  #   TRUE -> FALSE
  #   FALSE -> TRUE

DRV_CUSTOM_TOOL_SUPPORT = TRUE
  # Description:
  #   To enable using driver customization tool for GPIO/EINT/ADC/UEM/Keypad/PMU setting.
  # Option Values:
  #   TRUE: Enable
  #   FALSE: Disable
  # Switch-ability:
  #   [Any] -> [Any]

# ------------------------------ Java
J2ME_SHARE_MED_EXT_MEM = FALSE
  # Description:
  #   (1) When J2ME_SHARE_MED_EXT_MEM = TRUE, Java will share Media Memory,
  #   and therefore it will decrease the required RAM size. In experiment,
  #   the RAM size decreases about 300k~400k bytes in MT6219, MT6225.
  #   (2) When J2ME_SHARE_MED_EXT_MEM = TRUE, Java can not support video/camera/recording for MMAPI. Background running will also be disabled. If we enable both J2ME_SHARE_MED_EXT_MEM and J2ME_SLIM_MEMORY_SUPPORT, Java background running will support with some limitation. Please check J2ME_SLIM_MEMORY_SUPPORT for more information.
  # Option Values:
  #   TRUE: Java will use MED memory to save overall memory. Java can not support Video in this case
  #   FALSE: Java will use ASM to allocate memory.
  # Switch-ability:
  #   Non-switchable

SUPPORT_BACKGROUND_JAVA = FALSE
  # Description:
  #   FALSE: disable background running JAVA only applied on Jblendia
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   [Any] -> [Any]

SUPPORT_JSR_75_PIM = FALSE
  # Description:
  #   J2ME FEATURE SETTINGS
  #   MUST TURN ON JTWI FEATURESET or NO USE
  #   SUPPORT_JSR_75_PIM/SUPPORT_JSR_205/SUPPORT_INFUSIO is TRUE
  #   SUPPORT_JSR_184/SUPPORT_SURFKITCHEN is FALSE
  # Option Values:
  #   TRUE: Support JSR-75 PIM
  #   FALSE: Turn off JSR-75 PIM
  # Switch-ability:
  #   Non-switchable

SUPPORT_JSR_75_PIM_MSA = FALSE
  # Description:
  #   This feature option is used to support MSA 1.0 clarifications for JSR-75 PIM. Enabling this compile option will enable TITLE, URL, ADDR, NOTE, and 2nd EMAIL of Contact. Please note that to enable the compile option may enlarge the memory usage.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

SUPPORT_JSR_179 = FALSE
  # Description:
  #   Enable Java JSR179 location API
  #   Please add this compile option under SUPPORT_JSR_82 in project.mak
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

SUPPORT_JSR_205 = FALSE
  # Description:
  #   J2ME FEATURE SETTINGS
  #   MUST TURN ON JTWI FEATURESET or NO USE
  #   SUPPORT_JSR_75_PIM/SUPPORT_JSR_205/SUPPORT_INFUSIO is TRUE
  #   SUPPORT_JSR_184/SUPPORT_SURFKITCHEN is FALSE
  # Option Values:
  #   TRUE: Support JSR-205
  #   FALSE: Turn off JSR-205
  # Switch-ability:
  #   Non-switchable

# ------------------------------ VoIP
# ------------------------------ Wifi
CUSTOM_WIFI_FEATURES_SWITCH = FALSE      #no wifi VMC 
  # Description:
  #   support WLAN feature on/off when WIFI_SUPPORT != NONE
  #   if WIFI_SUPPORT = NONE,  CUSTOM_WIFI_FEATURES_SWITCH only can be set FALSE
  #   Notice: WIFI_SUPPORT is not customer switchable option.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

WIFI_INTERFACE_TYPE = HIF_SDIO
  # Description:
  #   the HW interface selection for WIFI CHIP
  #   the configuration is HW dependency. please confirm the HW first before your configuration
  # Option Values:
  #   EHPI_8BIT: EHPI BUS 8BIT Mode
  #   EHPI_16BIT: EHPI BUS 16BIT Mode
  #   NONE: Disable this feature
  #   HIF_SDIO: Set this value when WIFI use SDIO as interface.
  # Switch-ability:
  #   [Any] -> [Any]

WIFI_PREFER_SUPPORT = FALSE
  # Description:
  #   To enable select WiFi first if WiFi is available.
  # Option Values:
  #   TRUE: Select WiFi first if WiFi is available
  #   FALSE: close WiFi prefer
  # Switch-ability:
  #   [Any] -> [Any]

MMI_HIDE_WAPI = FALSE
  # Description:
  #   Turn off MMI WAPI support
  # Option Values:
  #   TRUE: Turn off MMI WAPI support
  #   FALSE: Turn on MMI WAPI support
  # Switch-ability:
  #   [Any] -> [Any]

# ------------------------------ Tiny system
# ------------------------------ Operator
# ------------------------------ TC01
# ------------------------------ Others
# =========================================================================
# Feature Options which customer can NOT modify
# =========================================================================
#[Non-modifiable]# ------------------------------ ARM
COMPILER = RVCT
  # Description:
  #   RVCT or ADS
  # Option Values:
  #   ADS: Use ARM ADS tool chain.
  #   RVCT: Use ARM RVCT tool chain
  #   GCC: Use GNU GCC tool chain (Mentor Sourcery 2010.09 , 4.5.1)
  # Switch-ability:
  #   Non-switchable

RVCT_MULTI_FILE = NONE
  # Description:
  #   Set RVCT feature MULTI_FILE. RVCT is a compiler
  # Option Values:
  #   NONE: Disable --multifile compiler argument .
  #   MULTI: Enable --multifile compiler argument to compile specified source files into one object file.
  # Switch-ability:
  #   Non-switchable

CUSTOM_CFLAGS = #--debug --no_debug_macros
  # Description:
  #   Add custom cflag
  # Option Values:
  #   --debug --no_debug_macros: .
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ HW and Project
ACCDET_SUPPORT = EINT_ACCDET
  # Description:
  #   This compile option is defined to indicate that out new chip support Accessory Detection module.
  # Option Values:
  #   HYBRID: accdet+eint SW Solution to detection
  #   TRUE: Support ACCDET HW Detection Solution;And on MT6276 and MT6251, it indicates the Accdet+Earbias Solution
  #   FALSE: Indicate the Old AuxADC detection solution
  #   DISABLE_AUX_ACCDET: no earphone detection on the project
  #   EINT_ACCDET: accdet+eint hw solution
  #   DISABLE_EARPHONE: no earphone detection on the project But have AUX task
  # Switch-ability:
  #   Non-switchable

CLASSK_CHARGEPUMP_SUPPORT = FALSE
  # Description:
  #   For MT6260, support Class-K (chargepump)
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

MCU_CLOCK = MCU_260M
  # Description:
  #   Specify MCU clock rate,
  #   MT6205B = 26MHz (MCU_26M)
  #   MT6218B/19, MT6226/7, MT6223 = 52MHz (MCU_52M)
  #   MT6228, MT6229, MT6230, MT6225 = 104MHz (MCU_104M)
  #   MT6235, MT6238, MT6239 = 208MHz (MCU_208M)
  # Option Values:
  #   MCU_39M: CPU normal operation frequency:39MHz
  #   MCU_245_76M: CPU normal operation frequency:245.76MHz
  #   MCU_208M: CPU normal operation frequency: 208MHz
  #   MCU_312M: CPU normal operation frequency: 312MHz
  #   MCU_52M: CPU normal operation frequency:52MHz
  #   MCU_104M: CPU normal operation frequency: 104MHz
  #   MCU_520M: CPU normal operation frequency: 520MHz
  #   MCU_122_88M: CPU normal operation frequency: 122.88MHz
  #   MCU_13M: CPU normal operation frequency:13MHz
  #   MCU_650M: CPU normal operation frequency: 650MHz
  #   MCU_26M: CPU normal operation frequency:26MHz
  #   MCU_416M: CPU normal operation frequency: 416Mhz
  # Switch-ability:
  #   Non-switchable

MCU_DCM = DCM_ENABLE
  # Description:
  #   to enable Dynamic Clock Switching (MCU_DCM) function for saving the current consumption. Please set DCM_ENABLE to turn on this feature. (DCM_ENABLE <-> DCM_DISABLE) DCM_ENABLE: Need correct EMI configurations.
  # Option Values:
  #   DCM_ENABLE: Enable DCM support
  #   DCM_DISABLE: Disable DCM support
  # Switch-ability:
  #   Non-switchable

CHIP_VER = S00
  # Description:
  #   Chip version, changed according to ECO.
  # Option Values:
  #   S01: .
  #   S00: .
  #   S02: .
  # Switch-ability:
  #   Non-switchable

RF_MODULE = MT2503RF_CUSTOM
  # Description:
  #   describe the RF module used in this project
  # Option Values:
  #   NA: the RF module used in this project
  # Switch-ability:
  #   Non-switchable

PLATFORM = MT6261
  # Description:
  #   Name of BB-chip.
  # Option Values:
  #   NA:
  # Switch-ability:
  #   Non-switchable

PLATFORM_FOR_CHECK = NONE
  # Description:
  #   Name of BB-chip for tool check.
  # Option Values:
  #   NONE: Disable this feature.
  #   NA: MediaTek setup this name for tool check.
  # Switch-ability:
  #   Non-switchable

DEMO_PROJECT = FALSE
  # Description:
  #   To define projects that are experimental or for demo purposes only. It should NEVER be enabled on MP projects, and it is used by MTK internally. Customer does not need to change it
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

FLAVOR = NONE
  # Description:
  #   To describe what flavor setting was used in internal project.
  # Option Values:
  #   NA: .
  # Switch-ability:
  #   Non-switchable

FM_RADIO_CHIP = NONE
  # Description:
  #   To determine which FM chip will be used.
  # Option Values:
  #   MT6189A1:
  #   MT6188A1:
  #   MT6276FM:
  #   AR1000:
  #   MT6626:
  #   MT6256FM:
  #   MT6616:
  #   MT6251FM:
  #   NONE: This project doesn't support FM radio
  # Switch-ability:
  #   Non-switchable

FM_INTERFACE_TYPE = NONE
  # Description:
  #   Before, FM Chip use I2C or SPI, but new MT6616 FM Chip support HCI Interface, we need add compile option to dedicate HCI to MT6616.
  # Option Values:
  #   HCI:
  #   I2C:
  #   NONE: other control interface: FSPI
  # Switch-ability:
  #   Non-switchable

FM_RADIO_RECORD = FALSE
  # Description:
  #   Turn on FM radio record feature
  # Option Values:
  #   TRUE: Turn on FM Radio record function
  #   FALSE: Turn off FM radio record function
  # Switch-ability:
  #   TRUE -> FALSE

AFC_VCXO_TYPE = VCXO
  # Description:
  #   the oscillator type used in this project
  # Option Values:
  #   VCTCXO: VCTCXO clk
  #   VCXO: VCXO clk
  # Switch-ability:
  #   Non-switchable

EXT_CLOCK = EXT_26M
  # Description:
  #   Specify external clock rate.
  # Option Values:
  #   EXT_26M: .
  #   EXT_13M: .
  # Switch-ability:
  #   Non-switchable

PRODUCTION_RELEASE = TRUE
  # Description:
  #   Specify if production released is turned on.
  #   If it is enabled, some system code will be effected, like
  #   1. Watchdog enabled, and must be restared each time context switch;
  #   2. Handset silent reboot if system comes across with exception;
  # Option Values:
  #   TRUE: Disable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

CHARGING_ALGORITHM = LINEAR_LI_CHARGING
  # Description:
  #   To specify which charging algorithm is used, or no charging.
  # Option Values:
  #   LINEAR_LI_CHARGING: Linear charging with Li battery type
  #   PULSE_LI_CHARGING: Pulse charging with Li battery type
  #   LINEAR_NIMH_CHARGING: Linear charging with NiMH battery type
  #   PULSE_NIMH_CHARGING: Pulse charging with NiMH battery type
  # Switch-ability:
  #   Non-switchable

LOW_COST_SUPPORT = COMMON
  # Description:
  #   General compile option for Low Cost features. Please not that a module can define its own low-cost levels, or it can just adopt
  # Option Values:
  #   TRUE: .
  #   NONE: .
  #   FALSE: .
  #   ULC: .
  #   COMMON: .
  # Switch-ability:
  #   Non-switchable

PMIC = MT6261PMU
  # Description:
  #   To specify which Power Management IC(PMIC) is used, or no PMIC.
  # Option Values:
  #   MT6235PMU: .
  #   MT6318: .
  #   MT6238PMU: .
  #   MT6305: .
  #   NONE: No PMU/PMIC on PCB
  #   MT6326_CCCI: .
  #   MT6253PMU: .
  #   MT6326: .
  #   MT6258PMU: .
  #   MT6253ELPMU: .
  #   MT6223PMU: .
  #   MT6276PMU: .
  #   MT6236PMU: .
  #   MT6573PMU: .
  #   MT6255PMU: For MT6255 Usage
  # Switch-ability:
  #   Non-switchable

VIBRATION_SPEAKER_SUPPORT = FALSE
  # Description:
  #   Support Vibration Speaker (3-in-1 speaker)
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ LCD
MAIN_LCM_SCANLINE_ROTATION = FALSE
  # Description:
  #   This refers to the scanline rotation supportness for Main LCM
  # Option Values:
  #   FALSE: Disable this feature
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   [Any] -> [Any]

SUB_LCM_SCANLINE_ROTATION = FALSE
  # Description:
  #   This refers to the scanline rotation supportness for Sub LCM
  # Option Values:
  #   FALSE: Disable this feature
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   [Any] -> [Any]

SUBLCD_SYNC_LCM_METHOD = NONE
  # Description:
  #   Set this feature SUBLCD_SYNC_LCM_METHOD to SW or HW according to real HW layout connection
  # Option Values:
  #   SW:
  #   NONE:
  #   HW:
  # Switch-ability:
  #   [Any] -> [Any]

SPATIAL_DITHERING = FALSE
  # Description:
  #   Dithering is an intentionally applied form of noise, used to randomize quantization error.
  #   Dithering is routinely used in processing of both digital audio and video data.
  #   In our case, the spatial dithering technique is applied on image decoding.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ MMI
MMI_BASE = PLUTO_MMI
  # Description:
  #   Set MMI_BASE as PLUTO_MMI or NEPTUNE_MMI
  # Option Values:
  #   NEPTUNE_MMI:
  #   PLUTO_MMI:
  # Switch-ability:
  #   Non-switchable

MMI_FEATURES_SWITCH = FALSE
  # Description:
  #   MMI_FEATURES_SWITCH = TRUE means it's a memory reduction project, and the specified MMI_features_switch.h will be used, but USE_COMMON_MMI_FEATURES_SWITCH won't be defined.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Input and Language
FONT_ENGINE = NONE
  # Description:
  #   Set font engine type
  # Option Values:
  #   FONT_ENGINE_WTLE: Monotype WTLE Font
  #   FONT_ENGINE_WTLE: Monotype WTLE Font
  #   FONT_ENGINE_FREETYPE_DEMO: Demo Freetype Font
  #   FONT_ENGINE_FREETYPE_DEMO: Demo Freetype Font
  #   FONT_ENGINE_FREETYPE: Freetype Font
  #   FONT_ENGINE_FREETYPE: Freetype Font
  #   FONT_ENGINE_MONOTYPE_DEMO: Demo Monotype Font
  #   FONT_ENGINE_MONOTYPE_DEMO: Demo Monotype Font
  #   NONE: Bitmap Font
  #   NONE: Bitmap Font
  #   FONT_ENGINE_MONOTYPE: Monotype Font
  #   FONT_ENGINE_MONOTYPE: Monotype Font
  #   FONT_ENGINE_ETRUMP: Etrump Vector Font
  #   FONT_ENGINE_ETRUMP: Etrump Vector Font
  # Switch-ability:
  #   Non-switchable

FONT_RESOURCE = OFFICIAL
  # Description:
  #   To add compile option for demo font resource
  # Option Values:
  #   DEMO: Demo Bitmap Font Data
  #   OFFICIAL: Official Bitmap Font Data
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Application
BROWSER_SUPPORT = NONE
  # Description:
  #   This feature option is used to set browser solution of one project.
  # Option Values:
  #   OPERA_TURBO: Set Browser solution as Opera Turbo
  #   OPERA_V10: Set browser solution as Opera Mobile V10
  #   OBIGO_Q03C: Set browser solution as Obigo Q03C Browser
  #   OBIGO_Q05A: Set browser solution as Obigo Q05A Browser
  #   NONE: Disable this feature
  # Switch-ability:
  #   Non-switchable

BT_PRODUCT_LINE = NONE
  # Description:
  #   It define the BT procduct, which can be BT dailer or BT BOX.
  #   User can use BT dialer to connect to smart phone by blue tooth, and make bt call, view contacts and message of smart phone from BT dialer device.
  # Option Values:
  #   BT_DIALER: It means the project will be a BT dialer project with SIM, user can choice to use local SIM or use BT to make call, send sms.
  #              BT dialer device can connect to smart phone by BT, using BT dialer, user can make BT call, read phb & message of smart phone and listen the music or receive notification from smart phone.
  #   BT_DIALER_BTONLY: Its a BT dialer project without SIM.
  #   BT_BOX: BT BOX is a project for bt speaker. smart phone can connect to bt box by BT, then user can listen the music or answer the call of smart phone from bt box.
  #   NONE: Disable this feature
  #   BT_DIALER_BTONLY_W_PS: BT only project will have ps, but there is no telephony related app.
  # Switch-ability:
  #   Non-switchable

WAP_MEM_DEBUG = FALSE
  # Description:
  #   WAP_MEM_DEBUG = TRUE # TRUE, FALSE. Works only for WAP_SUPPORT = OBIGO_Q03C
  #   When WAP_SUPPORT=OBIGO_Q05A, WAP_MEM_DEBUG = TRUE or FALSE will not have any effect.
  #   And when WAP_SUPPORT=OBIGO_Q03C, WAP_MEM_DEBUG = TRUE or FALSE will work.
  # Option Values:
  #   TRUE: It will enable debug memory pool, so the memory requirement of Q03C browser will get increase.
  #   FALSE: It will disable debug memory pool, so the memory requirement of Q03C browser will get decrease.
  # Switch-ability:
  #   Non-switchable

TRANSCODING_PROXY_SUPPORT = NONE
  # Description:
  #   To support transocding proxy when the browser request for any URL. The URL will be first transferred to transocding Proxy. This proxy will interact with origin web server to fetch the data. For end user, the complete process is non-transparent. This feature is requested by Baidu so that all the MTK request URL should go via Baidu proxy server.
  # Option Values:
  #   BAIDU: Use Baidu Transcoding proxy while sending browser URL request
  #   NONE: Disable this feature
  # Switch-ability:
  #   Non-switchable

UNIFIED_PUSH_FEATURES = NONE
  # Description:
  #   This feature option is used to enable or disable the push feature.
  # Option Values:
  #   SLIM: It will disable white list and black list (trust list) management
  #   NONE: WAP Push disable
  #   STANDARD: It will enable  only white list and not black list (trust list) management
  #   FULL: It will enable white list and black list (trust list) management
  #   SERVICE_ONLY: It will enable the service only for receiving the push - like MMS push
  # Switch-ability:
  #   Non-switchable

CBM_BEARER_SWITCH_SUPPORT = FALSE
  # Description:
  #   support bearer switch in CBM
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

CUST_KEYPAD_TONE_SUPPORT = FALSE
  # Description:
  #   enable/disable cust keypad tone
  # Option Values:
  #   TRUE: Turn on customized keypad tone
  #   FALSE: Turn off customized keypad tone
  # Switch-ability:
  #   [Any] -> [Any]

DRM_SUPPORT = NONE
  # Description:
  #   Provides feature of DRM.
  # Option Values:
  #   NONE: If DRM not support, value will be NONE
  #   MTK: If DRM 1.0 is supported, value will be MTK
  # Switch-ability:
  #   Non-switchable

FOTA_ENABLE = NONE
  # Description:
  #   Turn on FOTA (firmware update over the air) feature, support full image firmware update now
  # Option Values:
  #   NONE: FOTA is disable
  #   FOTA_DM: Support FOTA
  # Switch-ability:
  #   Non-switchable

FOTA_UPDATE_PACKAGE_ON_NAND = FALSE
  # Description:
  #   Use NAND to place update package for NOR project
  # Option Values:
  #   TRUE: Enable FOTA update package in NAND for NOR project
  #   FALSE: Place diff package on NOR
  # Switch-ability:
  #   Non-switchable

NTPD_SUPPORT = TRUE
  # Description:
  #   Support network time protocol.
  # Option Values:
  #   FALSE: Turn off network time protocol.
  #   TRUE: Turn on network time protocol.
  # Switch-ability:
  #   Non-switchable

SMS_R8_NATION_LANGUAGE = FALSE
  # Description:
  #   The feature option is to support Turkish special character encoding method which is defined in 3GPP 23.038 Release8.
  #   New SMS UDH IEI is introduced to indicate the encoding/decoding alphabet of special Turikish character.
  #   Using the new method, SMS can avoid to use UCS2 coding scheme when the special Turkish character is present in the message.
  # Option Values:
  #   TRUE: Enable SMS R8 Nation Language (ex: Turkey)
  #   FALSE: Disable SMS R8 Nation Language (ex: Turkey)
  # Switch-ability:
  #   Non-switchable

EMS_SUPPORT = EMS_NONE
  # Description:
  #   There are four level for EMS functionality, EMS 5.0, EMS 4.0, slim EMS (pure text only), and ultra low cost slim EMS (currently only can be used in PLUTO MMI). This feature option is to set what level of the EMS functionality. It will impact three library mmi (plutommi or lcmmi), ems, and custom.
  # Option Values:
  #   EMS_50: support EMS 5.0
  #   EMS_SLIM: support only pure text content.
  #   EMS_40: support EMS 4.0
  #   EMS_ULC_SLIM: remove PLUTO MMI non used part, only remain support concatenate, port, R8 language handling
  #                 (Currently only support Plutommi, other MMI version can't use!)
  # Switch-ability:
  #   Non-switchable

TCPIP_LOOP_SUPPORT = TRUE
  # Description:
  #   When TCPIP_LOOP_SUPPORT is TRUE, __TCPIP_LOOP_BACK__ will be defined. WAP routes all the requests for "localhost" to 127.0.0.1.
  # Option Values:
  #   TRUE: Enable LOOPBACK.
  #   FALSE: Disable LOOPBACK.
  # Switch-ability:
  #   Non-switchable

TCPIP_SUPPORT = UDP_TCP
  # Description:
  #   To enable TCP/UDP/IP.
  # Option Values:
  #   NONE: Disable TCPIP
  #   TCP: Support TCP only.
  #   UDP_TCP: Support TCP and UDP.
  #   UDP: Use UDP.
  # Switch-ability:
  #   Non-switchable

DHCPD_SUPPORT = FALSE
  # Description:
  #   To enable dhcp server.
  # Option Values:
  #   TRUE: Support DHCP server.
  #   FALSE: Disable dhcp server.
  # Switch-ability:
  #   Non-switchable

TCPIP_AT_SUPPORT = PS
  # Description:
  #   There are three values could be set.
  #   1. PS, TCPIP AT USE PS.
  #   2. WIFI, TCPIP AT USE WIFI.
  #   3. NONE, Not support.
  # Option Values:
  #   NONE: NOT SUPPORT.
  #   PS: TCPIP AT USE protocol stack.
  #   WIFI: TCPIP AT use WIFI.
  # Switch-ability:
  #   Non-switchable

YAHOO_CONTENT_SUPPORT = FALSE
  # Description:
  #   TRUE: To preload all licensed Yahoo applications.
  #   FALSE: Not to preload all licensed Yahoo applications.
  # Option Values:
  #   TRUE: To preload all licensed Yahoo applications.
  #   FALSE: Not to preload all licensed Yahoo applications.
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Connectivity
BT_AUTO_DETECT_SUPPORT = FALSE
  # Description:
  #   To detect the existence of BT chip and show/hide BT MMI.
  #   Support BT chip: MT6612, MT6616, MT6622, MT6626
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

BT_AVRCP_PROFILE = FALSE
  # Description:
  #   To turn on/off AVRCP profile
  # Option Values:
  #   TRUE: Turn on AVRCP Profile
  #   FALSE: Turn off AVRCP Profile
  # Switch-ability:
  #   TRUE -> FALSE

BT_AUDIO_VIA_SCO = FALSE
  # Description:
  #   To turn on/off Audio via Bluetooth SCO link feature
  # Option Values:
  #   TRUE: Turn on audio via SCO function
  #   FALSE: Turn off audio via SCO function
  # Switch-ability:
  #   TRUE -> FALSE

BT_FM_RADIO_VIA_SCO = FALSE
  # Description:
  #   To turn on/off FM Radio via Bluetooth SCO link feature
  # Option Values:
  #   TRUE: Turn on FM via SCO function
  #   FALSE: Turn off FM via SCO function
  # Switch-ability:
  #   TRUE -> FALSE

AGPS_SUPPORT = NONE
  # Description:
  #   It decides user plane or control plane is used.
  # Option Values:
  #   BOTH: Enable both user-plane and control-plane.
  #   NONE: Disable AGPS feature.
  #   CONTROL_PLANE: Enable AGPS control-plane. (only used for the modem load on smart phone project)
  #   USER_PLANE: Enable AGPS user-plane. (SUPL) Use IP network to get assistance data.
  # Switch-ability:
  #   Non-switchable

OMA_ULP_SUPPORT = NONE
  # Description:
  #   It decides which OMA ULP version is used.
  #   AGPS will acceralte GPS TTFF, and also provide LBS service framework.
  # Option Values:
  #   NONE: Disable SUPL feature. Only can be this value when AGPS_SUPPORT is NONE or CONTROL_PLANE.
  #   V1: Enable SUPL v1.0.
  # Switch-ability:
  #   Non-switchable

RRLP_VER_SUPPORT = NONE
  # Description:
  #   To change RRLP protocol version for both AGPS user plane and/or control plane.
  # Option Values:
  #   NONE: Doesn't support RRLP (it also means both AGPS user plane and control plane are not supported)
  #   R5: Support RRLP for 3GPP R5
  # Switch-ability:
  #   Non-switchable

USB_SUPPORT = TRUE
  # Description:
  #   to enable USB function
  # Option Values:
  #   TRUE: Enable USB
  #   FALSE: Disable USB
  # Switch-ability:
  #   [Any] -> [Any]

USB_COM_PORT_SUPPORT = TRUE
  # Description:
  #   Open Com Port function
  # Option Values:
  #   TRUE: Enable USB comport
  #   FALSE: Disbale USB comport
  # Switch-ability:
  #   N/A

USB_COMPORT_PC_DRIVER_SUPPORT = MS
  # Description:
  #   Only if __TC01__  is defined
  #   then
  #   USB_COMPORT_PC_DRIVER_SUPPORT = TC01
  # Option Values:
  #   TC01: TC01 comport driver
  #   MS: Microsoft comport driver
  # Switch-ability:
  #   Non-switchable

BATTERY_CHARGING_SUPPORT = FALSE
  # Description:
  #   enable battery charging .
  # Option Values:
  #   TRUE: support BC1.1 spec
  #   FALSE: use MTK detection flow
  # Switch-ability:
  #   Non-switchable

OTG_SUPPORT = FALSE
  # Description:
  #   To enable OTG suuport  feature
  # Option Values:
  #   TRUE: Enable OTG
  #   FALSE: Disable OTG
  # Switch-ability:
  #   Non-switchable

SYNCML_SUPPORT = FALSE
  # Description:
  #   define __SYNCML_SUPPORT__ to specify if syncml is enabled.
  #   if yes, MMI and SYNCML tasks will refer to this compile option.
  # Option Values:
  #   TRUE: Turn on SyncML support
  #   FALSE: Turn off SyncML support
  # Switch-ability:
  #   Non-switchable

SYNCML_DEVICE_SYNC_SUPPORT = FALSE
  # Description:
  #   To enable phone to phone sync
  # Option Values:
  #   TRUE: Turn on device sync support
  #   FALSE: Turn off device sync support
  # Switch-ability:
  #   Non-switchable

SYNCML_PC_SYNC_SUPPORT = FALSE
  # Description:
  #   to enable SyncML with PC tool
  # Option Values:
  #   TRUE: Turn on PC sync support
  #   FALSE: Turn off PC sync support
  # Switch-ability:
  #   Non-switchable

SYNCML_DM_SUPPORT = FALSE
  # Description:
  #   define SYNCML_DM_SUPPORT to specify if dm is enabled.
  #   if yes, MMI and DM tasks will refer to this compile option.
  # Option Values:
  #   TRUE: enabile DM
  #   INSIGNIA_DM: enabile insignial DM
  #   FALSE: disable DM
  # Switch-ability:
  #   Non-switchable

SYNCML_DM_VERSION = NONE
  # Description:
  #   The version that project can support for DM.
  # Option Values:
  #   DM11: DM 1.1
  #   NONE: DM 1.1
  #   DM12: DM1.2
  #   DM12_SCTS: SCTS tool test
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Multimedia
ATV_SUPPORT = FALSE
  # Description:
  #   enable mobile atv feature support
  # Option Values:
  #   SLIM:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   TRUE -> FALSE
  #   SLIM -> FALSE

ATV_CHIP = VER01
  # Description:
  #   This option is to indentify driver version.
  # Option Values:
  #   VER00: atv chip version 5192
  #   VER01: atv chip version 5193
  # Switch-ability:
  #   Non-switchable

ATV_I2S_PATH = FALSE
  # Description:
  #   turn on I2S audio path for mATV feature
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   TRUE -> FALSE

ATV_RECORD_SUPPORT = FALSE
  # Description:
  #   enable mobile atv record feature
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   TRUE -> FALSE

BACKGROUND_SOUND = TRUE
  # Description:
  #   To enable the calling background sound feature.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   [Any] -> [Any]

JTONE_SUPPORT = FALSE
  # Description:
  #   JTONE support is the tone interface in JAVA game or JAVA application,
  #   It should be open if J2ME_SUPPORT not equal to NONE.
  # Option Values:
  #   TRUE: JAVA Tone Sequence Support
  #   FALSE: Not support JAVA Tone Sequence
  # Switch-ability:
  #   Non-switchable

MEDIA_PLAYER_VER = NONE
  # Description:
  #   This feature option is to decide if MMI use two seperate player to play video and audio files
  #   or use an integrated media player to play these files.
  #   Also, the media player can use file system or SQLite as its play list by changing this option.
  # Option Values:
  #   INTEGRATED_DB: Integrated audio and video player with auto category function by using database
  #   COSMOS_MUSIC_PLY: Cosmos MMI music player with auto category function
  #   SEPARATED: Seperated audio player and video player applications
  #   INTEGRATED: Integrate audio and video playback into a player
  # Switch-ability:
  #   [Any] -> [Any]

M3GPMP4_FILE_FORMAT_SUPPORT = FALSE
  # Description:
  #   3GPMP4_FILE_FORMAT_SUPPORT is used to enable or disable to support mp4/3gp iso media file format
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

PURE_AUDIO_SUPPORT = FALSE
  # Description:
  #   To support pure audio 3GP/MP4 files in audio player
  # Option Values:
  #   TRUE: Turn on pure audio support
  #   FALSE: Turn off pure audio support
  # Switch-ability:
  #   [Any] -> [Any]

#[Non-modifiable]# ------------------------------ Audio
AAC_DECODE = FALSE
  # Description:
  #   To enable AAC decoder.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

AAC_PLUS_DECODE = FALSE
  # Description:
  #   To enable AAC PLUS decoder.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

AAC_PLUS_PS_DECODE = FALSE
  # Description:
  #   to enable aacPlus v2
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

AIFF_DECODE = FALSE
  # Description:
  #   AIFF decoder support
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

AMR_CODEC = FALSE
  # Description:
  #   AMR codec is a basic audio capability in general platforms. It supports file/stream AMR playback/record so it should be turned on in most cases. Only turn off it in ultra-low-cost platform to reduce memory usage . Consider carefully before turning off it.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

AMRWB_DECODE = FALSE
  # Description:
  #   Because MT6219 DSP can't support AMRWB_ENCODE when GPRS connection. We have to split decode and encode. MT6219 only support decode.
  # Option Values:
  #   TRUE: Turn on AWB decoder
  #   FALSE: Turn off AWB decoder
  # Switch-ability:
  #   Non-switchable

AMRWB_ENCODE = FALSE
  # Description:
  #   Because MT6219 DSP can't support AMRWB_ENCODE when GPRS connection. We have to split decode and encode. MT6219 only support decode.
  # Option Values:
  #   TRUE: Turn on AWB encoder
  #   FALSE: Turn off AWB encoder
  # Switch-ability:
  #   Non-switchable

DEDI_AMR_REC = FALSE
  # Description:
  #   To enable the AMR encoder for conversation recording.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

APE_DECODE = FALSE
  # Description:
  #   APE audio file deocde
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

AU_DECODE = FALSE
  # Description:
  #   AU decoder support
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

COOK_DECODE = FALSE
  # Description:
  #   for real media cook audio decoder support
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

DAF_DECODE = FALSE
  # Description:
  #   To enable DAF decoder.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

DAF_ENCODE = FALSE
  # Description:
  #   mp3 encoder for fm recording
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

DRA_DECODE = FALSE
  # Description:
  #   DRA is a kind of audio codec for CMMB. This option is to enable or disable DRA decoder.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

M4A_DECODE = FALSE
  # Description:
  #   To support .m4a file whose content is AAC.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

MUSICAM_DECODE = FALSE
  # Description:
  #   add mp2 decoder
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

WAV_CODEC = TRUE
  # Description:
  #   wav codec is a basic audio capability in general platforms. It supports linear PCM , u-law, a-law, ADPCM wav playabck/record so it should be turned on in most cases. Only turn off it in ultra-low-cost platform to reduce memory usage and it cause not only
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

WAVETABLE_VER = WT20K
  # Description:
  #   Use the compiletion to choose a suitable wavetable for the system. The bigger the wavetable is, the higher quality it can provide.
  # Option Values:
  #   WT_ROM_V2: only 6251 (one to one and onto)
  #              Wavetable Size
  #   WT100K: Wavetable Size
  #   WT600K: Wavetable Size
  #   WT150K: Wavetable Size
  #   WT70K: Wavetable Size
  #   WT20K: Wavetable Size
  #   WT_ROM_V1: only 6253
  #              Wavetable Size
  #   WT300K: Wavetable Size
  # Switch-ability:
  #   N/A

WMA_DECODE = FALSE
  # Description:
  #   WMA (Window Media Audio) decoder.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

AUDIO_COMPENSATION_DSP_IIR_SUPPORT = FALSE
  # Description:
  #   For audio IIR filter tuning. Only valid on MT6251. Otherchip could use BES_LOUDNESS_SUPPORT instead
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

AUDIO_COMPENSATION_ENABLE = FALSE
  # Description:
  #   to enable Audio_EQ and Audio_Compensation_filter
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   N/A

AUD_RECORD = FALSE
  # Description:
  #   Check if the platform support audio record.
  #   (1) Sound Recorder
  #   (2) FM Radio Recorder
  #   (3) Schedule FM Radio Record
  #   (4) Media Task record APIs
  # Option Values:
  #   TRUE: Turn on audio record function
  #   FALSE: Turn off audio record function
  # Switch-ability:
  #   TRUE -> FALSE

BITSTREAM_SUPPORT = FALSE
  # Description:
  #   (1) support bitstream audio playback interface
  #   (2) support bitstream audio record interface
  # Option Values:
  #   TRUE: Turn on bitstream interface
  #   FALSE: Turn off bitstream interface
  # Switch-ability:
  #   [Any] -> [Any]

BES_BASS_SUPPORT = FALSE
  # Description:
  #   add bass enhancement audio feature
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

BES_EQ_SUPPORT = FALSE
  # Description:
  #   to enable Audio_EQ and Audio_Compensation_filter
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

BES_LIVE_SUPPORT = FALSE
  # Description:
  #   To turn on audio post process (3D effect, time stretch) feature
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

BES_SURROUND_SUPPORT = NONE
  # Description:
  #   to enable 3D surround,
  # Option Values:
  #   MODE_EARP:
  #   MODE_BOTH:
  #   NONE:
  #   MODE_LSPK:
  # Switch-ability:
  #   Non-switchable

BES_TS_SUPPORT = FALSE
  # Description:
  #   To turn on audio post process time stretch feature
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

CTM_SUPPORT = FALSE
  # Description:
  #   To turn on/off CTM, TTY  feature
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

DSP_COMPRESS = 7Z
  # Description:
  #   Compress DSP ROM code. Decompress into RAM at power on.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

DUAL_MIC_SUPPORT = FALSE
  # Description:
  #   Enable/Disable the baseband dual microphone support capability. Only MT6256/6276 and later chip support it
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   TRUE -> FALSE

I2S_INPUT_MODE_SUPPORT = FALSE
  # Description:
  #   This feature option enables the I2S input mode
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

IP_COMMON_SUPPORT = FALSE
  # Description:
  #   To use common SWIP.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

LARGE_MIDI_FILE_SUPPORT = FALSE
  # Description:
  #   Support large size midi playback
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   TRUE -> FALSE

MED_PROFILE = MED_BASIC
  # Description:
  #   To set the MED profile, MED_LOW means not support play audio from file.
  # Option Values:
  #   MED_HIGH: Config MED task for plutommi/cosmos project
  #   MED_MODEM: Config MED task for Modem project
  #   MED_LOW: Config MED task for Neptune or low cost project
  #   MED_BASIC: Config MED task for Modem project contain basic audio
  # Switch-ability:
  #   Non-switchable

MELODY_VER = NONE
  # Description:
  #   Choose the built-in melody synthesizer.
  # Option Values:
  #   SW_SYN_16K:
  #   NONE:
  #   EXT_AUDIO_CHIP:
  #   SW_SYN_8K:
  #   DSP_WT_SYN: Midi synthesizer
  # Switch-ability:
  #   Non-switchable

OGG_VORBIS_DECODE = FALSE
  # Description:
  #   Support audio format .ogg playback
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

OGG_VORBIS_ENCODE = FALSE
  # Description:
  #   Support .ogg format audio recording
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Speech
AEC_ENABLE = TRUE
  # Description:
  #   For Acoustic Echo Cancellation (AEC)
  # Option Values:
  #   TRUE: Support AEC in handset mode
  #   FALSE: Not Support AEC in handset mode
  # Switch-ability:
  #   Non-switchable

AMRWB_LINK_SUPPORT = FALSE
  # Description:
  #   If the compile option is true, our BB chip will support AMRWB voice call. If false, we won't support this function.
  # Option Values:
  #   TRUE: Support WB-AMR link
  #   FALSE: Not Support WB-AMR link
  # Switch-ability:
  #   Non-switchable

DATA_CARD_SPEECH = FALSE
  # Description:
  #   Enable speech capablility via data card tool  through PC speaker and microphone
  # Option Values:
  #   TRUE: Enable data card speech
  #   FALSE: Disable Datacrad speech
  # Switch-ability:
  #   Non-switchable

EES_ENABLE = TRUE
  # Description:
  #   For Enhanced Echo Suppression (EES)
  # Option Values:
  #   TRUE: Support AEC in speaker mode
  #   FALSE: Not Support AEC in speaker mode
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Video
CMMB_SUPPORT = NONE
  # Description:
  #   To enable CMMB support
  # Option Values:
  #   NONE: CMMB Is not supported
  #   NONE: CMMB Is not supported
  #   SIANO_SMS2186: CMMB is supported and vendor chip is SMS2186
  #   SIANO_SMS2186: CMMB is supported and vendor chip is SMS2186
  #   INNOFIDEI_IF228: CMMB is supported and vendor chip is IF228
  #   INNOFIDEI_IF228: CMMB is supported and vendor chip is IF228
  #   INNOFIDEI_IF106: CMMB is supported and vendor chip is IF206
  #   INNOFIDEI_IF106: CMMB is supported and vendor chip is IF206
  # Switch-ability:
  #   [Any] -> [Any]

CMMB_CAS_MBBMS_SUPPORT = FALSE
  # Description:
  #   N/A
  # Option Values:
  #   TRUE: MBBMS is supported
  #   FALSE: MBBMS is not supported
  # Switch-ability:
  #   [Any] -> [Any]

FLAC_DECODE = FALSE
  # Description:
  #   FLAC (Free Lossless Audio Codec) decoder
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

H264_DECODE = FALSE
  # Description:
  #   This option is used to turn on H264  decoder.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   TRUE -> FALSE

H264_DECODE_MODE = NONE
  # Description:
  #   When this option is set as SLIM. The support resolution may be decreased in order to reduce memory.
  # Option Values:
  #   SLIM: Enable slim-version of this feature
  #   NORMAL: Enable normal-version of this feature
  # Switch-ability:
  #   SLIM -> NORMAL
  #   NORMAL -> SLIM

MP4_DECODE = FALSE
  # Description:
  #   Turn on/off and set MP4/H264 decode/encode to SW/HW solution
  # Option Values:
  #   TRUE:
  #   MP4_SW:
  #   NONE:
  #   FALSE:
  #   MP4_HW:
  # Switch-ability:
  #   TRUE -> FALSE

MP4_DECODE_MODE = NONE
  # Description:
  #   When this option is set as SLIM. The support resolution will be decreased in order to reduce memory.
  # Option Values:
  #   SLIM:
  #   NONE:
  #   NORMAL:
  # Switch-ability:
  #   NORMAL -> SLIM
  #   SLIM -> NORMAL

PGDL_SUPPORT_YOUTUBE = FALSE
  # Description:
  #   To support PGDL on Youtube website
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

KINGMOVIE_FILE_FORMAT_SUPPORT = FALSE
  # Description:
  #   KINGMOVIE_FILE_FORMAT_SUPPORT is used to enable or disable to support kmv media file format
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

MP4_ENCODE = FALSE
  # Description:
  #   Turn on/off and set MP4/H264 decode/encode to SW/HW solution
  # Option Values:
  #   TRUE: TRUE to enable MPEG-4 encoder
  #   MP4_SW: Not supported anymore
  #   NONE: Not supported anymore
  #   FALSE: FALSE to disable MPEG-4 encoder
  #   MP4_HW: Not supported anymore
  # Switch-ability:
  #   TRUE -> FALSE

MP4_ENCODE_MODE = SLIM
  # Description:
  #   When this option is set as SLIM. The support resolution may be decreased in order to reduce memory.
  # Option Values:
  #   SLIM: Reduce MP4 encode resolution and memory usage
  #   NORMAL: No reduction of maximum resolution for MP4 encode and thus no memory reduction
  # Switch-ability:
  #   [Any] -> [Any]

MJPG_DECODE_MODE = SLIM
  # Description:
  #   When this option is set as SLIM. The support resolution may be decreased in order to reduce memory.
  # Option Values:
  #   SLIM:
  #   NORMAL:
  # Switch-ability:
  #   [Any] -> [Any]

MKV_FILE_FORMAT_SUPPORT = FALSE
  # Description:
  #   MKV_FILE_FORMAT_SUPPORT is used to enable or disable to support mkv media file format
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

RTSP_SUPPORT = FALSE
  # Description:
  #   to enable streaming function
  # Option Values:
  #   TRUE: open this feature
  #   FALSE: not open this feature
  # Switch-ability:
  #   Non-switchable

VIDEO_SUBTITLE_SUPPORT = FALSE
  # Description:
  #   VIDEO_SUBTITLE_SUPPORT is used to enable or disable to support video subtitle
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Camera
CAMCORDER_MOTION_SENSOR_SUPPORT = NONE
  # Description:
  #   Camcorder support motion sensor direction to capture or record. It makes users could user any direction to capture or record and the content will be upright
  # Option Values:
  #   NONE: Disable this feature
  #   BOTH_BY_TAG: Camera and recorder both use the way of adding tag information to header
  #   BOTH_BY_ENCODE: Camera and recorder both use the way of encoding rotation.
  #   CAM_BY_ENCODE_REC_BY_TAG: Camera uses the encoding rotation. Recorder uses adding tag information.
  #   CAM_BY_TAG_REC_BY_ENCODE: Camera uses adding tag information. Recorder uses encoding rotation.
  # Switch-ability:
  #   Non-switchable

ISP_SUPPORT = FALSE
  # Description:
  #   To enable BB embeded image signal processor for camera applications.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Graphic
JPG_DECODE = FALSE
  # Description:
  #   To enable jpeg decoder.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

JPG_ENCODE = FALSE
  # Description:
  #   To enable jpeg encoder.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

EXIF_SUPPORT = FALSE
  # Description:
  #   Turn On/Off Exif feature. EXIF is abbreviation of Exchangeable Image File Format.
  #   It's a specification for the image file format sued by digital cameras.
  #   I can embedded some information into image files, such as shutter speed, explosure time, etc.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

PNG_DECODE = FALSE
  # Description:
  #   To enable png decoder.
  # Option Values:
  #   TRUE:
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Security
BOOT_CERT_SUPPORT = NONE
  # Description:
  #   Make hacker can not abuse download the binary and boot-up successfully
  # Option Values:
  #   NONE: Disable this feature
  #   BOOT_CERT_V1: BOOT_CERT_V1 make the built binary must combine with a BOOT_CERT file. Hacker can not download stolen binary into a empty phone and boot-up successfully.
  #   BOOT_CERT_V2: BOOT_CERT_V2 will cover BOOT_ECRT_V1 scope plus read back attack
  # Switch-ability:
  #   Non-switchable

IPSEC_SUPPORT = FALSE
  # Description:
  #   IPSEC support (using IKEv1)
  # Option Values:
  #   IPSEC_IKEv1: Support IKEv1.
  #   FALSE: Disable IPSEC.
  # Switch-ability:
  #   Non-switchable

RC5_SUPPORT = FALSE
  # Description:
  #   to enable RC5 crypto support in security library
  #   This is to turn off RC5 cipher algorithm used in Obigo WAP solution.
  #   Customer will need to turn off this cipher if the handset is shipped to US by US law.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

SECURE_SUPPORT = FALSE
  # Description:
  #   Support security system
  # Option Values:
  #   TRUE: Secure load
  #   FALSE: Non-secure load
  # Switch-ability:
  #   Non-switchable

SECURE_RO_ENABLE = FALSE
  # Description:
  #   Putting default values of SIM-ME-Lock and any other senitive data in put a encrypted RO.
  # Option Values:
  #   TRUE: To enable Secure RO
  #   FALSE: To disable Secure RO
  # Switch-ability:
  #   Non-switchable

RES_PROT = FALSE
  # Description:
  #   RES_PROT is the enhanced anticlone mechenism which not only protect the code, also the data
  #   It's for customer who have concern about the own picture and ringtons that may be stolen by read-out image
  # Option Values:
  #   TRUE: Enable encryption on some important resource data
  #   FALSE: Resource protection is disabled
  # Switch-ability:
  #   Non-switchable

SW_BINDING_SUPPORT = NONE
  # Description:
  #   These 2 options are used to replace original UID_SUPPORT.
  #   SW_BINDING_SUPPORT specifies what kind of anticlone feature for the main code is enabled.
  #   BIND_TO_CHIP_BASIC is the same type as original UID_SUPPORT
  #   BIND_TO_CHIP is the new type which can support FOTA
  #   BIND_TO_KEY is the new type which can bind software to a customer defined key in the chip (SV5 only)
  #   BIND_TO_CHIP_AND_KEY is the combination of BIND_TO_CHIP and BIND_TO_KEY
  # Option Values:
  #   BIND_TO_CHIP_AND_KEY: BIND_TO_CHIP plus BIND_TO_KEY
  #   BIND_TO_CHIP_BASIC: Enable software binding. is the same type as original UID_SUPPORT
  #   NONE: Software bindnig is off
  #   BIND_TO_CHIP: Enable software binding which can support FOTA
  #   BIND_TO_KEY: Enable software binding which can support ROM writer
  # Switch-ability:
  #   Non-switchable

VERIFY_ALL_IMAGES = FALSE
  # Description:
  #   While this FO is set to TRUE, all images will be verified
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Modem
EDGE_SUPPORT = FALSE
  # Description:
  #   Enable EDGE support Only applicable to 6229 latter version
  # Option Values:
  #   TRUE: EGPRS enable
  #   FALSE: EGPRS enable
  # Switch-ability:
  #   Non-switchable

USIM_SUPPORT = TRUE
  # Description:
  #   Support USIM card commands or not(TRUE: support; FALSE: not support)
  # Option Values:
  #   TRUE: Enable the capability to operate USIM as USIM card, instead of SIM card.
  #   FALSE: Operate USIM as SIM
  # Switch-ability:
  #   Non-switchable

UMTS_MODE_SUPPORT = NONE
  # Description:
  #   The option is to switch the FDD or TDD mode for 3G modem
  # Option Values:
  #   UMTS_TDD128_MODE_SUPPORT: 3G modem in TDD mode
  #   UMTS_FDD_MODE_SUPPORT: 3G modem in FDD mode
  #   NONE: None of 3G modem mode is supported.
  # Switch-ability:
  #   Non-switchable

HSUPA_SUPPORT = FALSE
  # Description:
  #   Define if UE supports HSUPA feature. (TRUE/FALSE)
  # Option Values:
  #   TRUE: HSUPA is support
  #   FALSE: HSUPA is not support
  # Switch-ability:
  #   Non-switchable

AMR_LINK_SUPPORT = TRUE
  # Description:
  #   Support AMR link, channel codec and RATSCCH procedure, with base station.
  # Option Values:
  #   TRUE: AMR enable
  #   FALSE: AMR disable
  # Switch-ability:
  #   Non-switchable

AT_COMMAND_SET = FULL
  # Description:
  #   set AT_COMMAND_SET = FULL for all projects
  #   FULL means the same setting in current existed project.s
  #   So it will not impact any existed project.
  # Option Values:
  #   SLIM: support BT HF/DUN commands, phonesuite commands, dial up programs, and EM AT commands
  #   ULC: support BT HF commands and EM AT commands
  #   FULL: all AT commands are supported
  # Switch-ability:
  #   Non-switchable

CB_SUPPORT = TRUE
  # Description:
  #   Wrap the functionality - "CB" - for switchable
  # Option Values:
  #   FALSE: Disable CBS function
  #   TRUE: Enable CBS function
  # Switch-ability:
  #   Non-switchable

CSD_SUPPORT = NONE
  # Description:
  #   for CSD support
  # Option Values:
  #   T_NT: .
  #   TRUE: CSD enable
  #   NT_ONLY: .
  #   NONE: .
  #   FALSE: CSD disable
  # Switch-ability:
  #   Non-switchable

GPRS_MAX_PDP_SUPPORT = 4
  # Description:
  #   Maximum simultaneous PDP contexts (2~7)
  # Option Values:
  #   6: Maximum simultaneous PDP contexts is six
  #   4: Maximum simultaneous PDP contexts is four
  #   1: Maximum simultaneous PDP contexts is one
  #   3: Maximum simultaneous PDP contexts is three
  #   7: Maximum simultaneous PDP contexts is seven
  #   2: Maximum simultaneous PDP contexts is two
  #   5: Maximum simultaneous PDP contexts is five
  # Switch-ability:
  #   Non-switchable

L1_EGPRS = FALSE
  # Description:
  #   this compile option is only used for L1 Stand alone to turn on/off EDGE function
  # Option Values:
  #   TRUE: EGPRS enable
  #   FALSE: EGPRS disable
  # Switch-ability:
  #   Non-switchable

L1_EPSK_TX = FALSE
  # Description:
  #   Turn on/off this compile option may switch the function of EPSK modulation transmitter
  # Option Values:
  #   TRUE: EPSK TX enable
  #   FALSE: EPSK TX disable
  # Switch-ability:
  #   Non-switchable

L1_GPRS = TRUE
  # Description:
  #   Turn on the GPRS support of Layer 1
  #   This is used for internal test
  # Option Values:
  #   TRUE: GPRS enable
  #   FALSE: GPRS disable
  # Switch-ability:
  #   Non-switchable

MCD_SUPPORT = TRUE
  # Description:
  #   to enable MediaTek Message Coder Decoder feature for GSM/GPRS/EDGE project
  # Option Values:
  #   TRUE: Enable MCD (default)
  #   FALSE: Disable MCD
  # Switch-ability:
  #   Non-switchable

PPP_SUPPORT = GPRS_PPP_SUPPORT
  # Description:
  #   The option is used to define ppp module's function. We can turn off ppp, or set PPP module's function as csd ppp support or gprs ppp support used FP as modem for dialup
  # Option Values:
  #   FULL_SUPPORT: PPP used for supporting these two functions
  #   GPRS_PPP_SUPPORT: PPP used for supporting dialup as a modem for PC
  #   NONE: Turn off PPP
  #   CSD_PPP_SUPPORT: PPP used for supporting tcpip over csd option
  # Switch-ability:
  #   Non-switchable

SMART_PHONE_CORE = NONE
  # Description:
  #   To distinguish if it is a smart phone MODEM makefile or a smart phone APP makefile. NONE means it is not a smart-phone make file
  # Option Values:
  #   AP: in-house testing load running on application processor
  #   NONE: .
  #   WM_MODEM: modem processor software load for Windows Mobile smart phone
  #   MD: in-house testing load running on modem processor
  #   ANDROID_MODEM: modem processor software load for Android smart phone
  # Switch-ability:
  #   Non-switchable

SP_VIDEO_CALL_SUPPORT = FALSE
  # Description:
  #   Enable Video Call Modem Capability for Smartphone project
  # Option Values:
  #   TRUE: Turn on Video Call Support for Smartphone
  #         (conflict w/ 3G_VIDEO_CALL)
  #   FALSE: Turn off Video Call Support for Smartphone
  # Switch-ability:
  #   Non-switchable

SMS_OVER_PS_SUPPORT = FALSE
  # Description:
  #   Wrap the functionality - "SMS over PS" - for switchable
  # Option Values:
  #   TRUE: Enable SMS send over PS
  #   FALSE: Disable SMS send over PS
  # Switch-ability:
  #   Non-switchable

UMTS_RELEASE_SUPPORT = NONE
  # Description:
  #   The option is to switch different version of release for 3G modem
  # Option Values:
  #   UMTS_R6_SUPPORT: 3G modem supports Rel6
  #   UMTS_R4_SUPPORT: 3G modem supports Rel4
  #   UMTS_R5_SUPPORT: 3G modem supports Rel5
  # Switch-ability:
  #   Non-switchable

IOT_NO_CELLULAR = FALSE
  # Description:
  #   decide if remove cellular part in IOT project or not.
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

MODEM_CARD = NONE
  # Description:
  #   Target is data card module.
  # Option Values:
  #   CS_CALL_DISABLE: Data card project, has ability to disable CS call
  #   FULL: Data card project
  #   NONE: Disable this feature
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ TD-SCDMA
#[Non-modifiable]# ------------------------------ File system and System service
FACTORY_BOOT_BY_KEY = FALSE
  # Description:
  #   This feature option is used for future enhancement, currently it will impact nothing.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

FS_CHECKDRIVE_SUPPORT = FALSE
  # Description:
  #   Both File System and File Manager support Scan Disk function. System will ask user to do check disk at boot time if the phone was abnormal shutdown last time. Also, user can do that by selecting it from disk menu anytime.
  # Option Values:
  #   TRUE: To enable FS Check Drive
  #   FALSE: To disable FS Check Drive
  # Switch-ability:
  #   [Any] -> [Any]

FS_QM_SUPPORT = TRUE
  # Description:
  #   File System will support quota management mechanism on system drive. The mechanism prevents exhausted system drive from single application.
  # Option Values:
  #   TRUE: To enable FS Quota Management
  #   FALSE: To disable FS Quota Management
  # Switch-ability:
  #   [Any] -> [Any]

FS_SORT_SUPPORT = FALSE
  # Description:
  #   Both File System and File Manager support Sort function. User can browse folders/files with sorted order.
  # Option Values:
  #   TRUE: To enable FS Sorting
  #   FALSE: To disable FS Sorting
  # Switch-ability:
  #   [Any] -> [Any]

FS_TRACE_SUPPORT = FALSE
  # Description:
  #   File System will provide run-time trace information with proper configure. The trace information is very helpful to identify problem source.
  # Option Values:
  #   TRUE: To enable FS debug messange
  #   FALSE: To disable FS debug messange
  # Switch-ability:
  #   [Any] -> [Any]

FS_ASYNC_SUPPORT = FALSE
  # Description:
  #   File system supports handling requests asynchronously, i.e. in FS task.
  # Option Values:
  #   ON: To enable FS Async Interface.
  #   OFF: To disable FS Async Interface.
  # Switch-ability:
  #   [Any] -> [Any]

NVRAM_PSEUDO_MERGE = ON
  # Description:
  #   NVRAM will combine small files and this will transparent to applications.
  # Option Values:
  #   ON: To enable NVRAM pseudo merge
  #   OFF: To disable NVRAM pseudo merge
  # Switch-ability:
  #   [Any] -> [Any]

KAL_DEBUG_LEVEL = SLIM_DEBUG_KAL
  # Description:
  #   Control the major KAL debugging facility availability and behavior. More debugging facility consume more extra RAM footprint.
  #   Less debugging facility may suffer extra effort to locate root cause of issue.
  #   RICH_DEBUG_KAL > NORMAL_DEBUG_KAL > SLIM_DEBUG_KAL > RELEASE_KAL.
  #   Default Setting : MT6251, MT6252, MT6253 => SLIM_DEBUG_KAL
  #   Other Platform Project => NORMAL_DEBUG_KAL
  # Option Values:
  #   RELEASE_KAL: .
  #   SLIM_DEBUG_KAL: .
  #   RICH_DEBUG_KAL: .
  #   NORMAL_DEBUG_KAL: .
  # Switch-ability:
  #   N/A

KAL_ASSERT_LEVEL = KAL_ASSERT_LEVEL0
  # Description:
  #   Setup KAL assert level
  #   3: for full debugging facility support
  #   0: for minimal debugging facility support
  # Option Values:
  #   KAL_ASSERT_LEVEL3: .
  #   KAL_ASSERT_LEVEL2: .
  #   KAL_ASSERT_LEVEL0: .
  #   KAL_ASSERT_LEVEL1: .
  #   KAL_ASSERT_LEVEL4: save entire CPU registers
  # Switch-ability:
  #   Non-switchable

KEYPAD_DEBUG_TRACE = TRUE
  # Description:
  #   Enable bootup trace with keypad
  # Option Values:
  #   TRUE: Enable
  #   FALSE: Disable
  # Switch-ability:
  #   Non-switchable

SPLIT_BINARY_SUPPORT = NONE
  # Description:
  #   This is used to split normal binary & factory binary
  # Option Values:
  #   FACTORY_ONLY: This is used to create factory only project
  #   MAUI_ONLY: The will create MAUI only binary which does not have factory functionality
  #   NONE: Disable this feature
  #   FACTORY_COMBINE: MAUI/FACTORY binaries can be download in the same downloading process
  # Switch-ability:
  #   Non-switchable

SDS_SUPPORT = FALSE
  # Description:
  #   create a dsecure data storage to make customer can store data without erased by file system format
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Flash
NAND_SUPPORT = FALSE
  # Description:
  #   To enable NAND flash support, please set NAND_SUPPORT as TRUE.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

SPI_NAND_SUPPORT = FALSE
  # Description:
  #   Description:
  #   To enable SPI-NAND flash support, please set SPI_NAND_SUPPORT as TRUE.
  #   Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  #   Switch-ability:
  #   Non-switchable
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

SYSTEM_DRIVE_ON_NAND = FALSE
  # Description:
  #   To use NAND flash as system drive,
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   [Any] -> [Any]

NAND_SUPPORT_RAW_DISK = FALSE
  # Description:
  #   NAND Disk can be access without file system format
  # Option Values:
  #   TRUE: Enable NAND RAW disk support
  #   FALSE: Disable NAND RAW disk support. Normal project should be FALSE.
  # Switch-ability:
  #   Non-switchable

ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT = TRUE
  # Description:
  #   to enable enhanced single bank NOR flash support.
  # Option Values:
  #   TRUE: Enable Single Bank support
  #   FALSE: Disable Single Bank support
  # Switch-ability:
  #   Non-switchable

SYSDRV_BACKUP_DISK_SUPPORT = NONE
  # Description:
  #   System drive support backup disk option.
  #   Option - RAW, FAT or NONE (MAUI)
  #   Option - TRUE or FALSE (Lipton project)
  #   RAW  : Enable Backup Partition with Raw Disk Format Feature.
  #   FAT/TRUE  : Enable Backup Partition with FAT Format Feature.
  #   NONE/FALSE : Disable Backup Partition for NOR and NAND.
  #   Purpose
  #   (1) Support NVRAM Data Backup Feature.
  #   Usage
  #   (1) Set to RAW/FAT.
  #   Limitation
  #   (1) Currently NOR flash does not support FAT format backup disk.
  #   (2) Currently NAND flash does not support Raw format backup disk.
  #   (3) Must set NOR_SUPPORT_RAW_DISK=TRUE if backup paritition is raw disk format.
  # Option Values:
  #   NONE: System Drive backup to disk is not supported
  #   FAT: System Drive backup to disk is supported, the disk is FAT Format
  #   RAW: System Drive backup to disk is supported, the disk is RAW Format
  # Switch-ability:
  #   Non-switchable

NORFLASH_NON_XIP_SUPPORT = FALSE
  # Description:
  #   This feature can be enabled on NOR flash booting project, the ROM region will shadow to RAM, and all codes will run on RAM after enter MAUI.
  #   this feature can be used to support the cheap serial flash, which doesn't support suspend and  resume functionality, but the previous conditions
  #   is the RAM size is enough for all codes and RW/ZI data
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

SERIAL_FLASH_SUPPORT = TRUE
  # Description:
  #   Description:
  #   To enable serial flash support, please set SERIAL_FLASH_SUPPORT as TRUE.
  #   Option Values:
  #   TRUE:
  #   FALSE:
  #   Switch-ability:
  #   Non-switchable
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

SIP_SERIAL_FLASH_SIZE = 32M_BITS
  # Description:
  #   MT6252D SIP 16Mb serial flash and MT6250D SIP 32Mb serial flash. This feature option notifies EMI gen to generate SIP serial flash setting.After set this value other than NONE, need to set COMBO_MEMORY_SUPPORT to TRUE also.
  # Option Values:
  #   NONE: No serial flash SIP inside.
  #   16M_BITS: SIP 16Mb serial flash
  #   32M_BITS: SIP 32Mb serial flash
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Memory card
MSDC_CARD_SUPPORT_TYPE = MSDC_SD_SDIO
  # Description:
  #   to support various memory card type
  # Option Values:
  #   MSDC_SD_MMC: Enable SD/MMC card support
  #   NONE: Disable memory card support
  # Switch-ability:
  #   MSDC_SD_MMC -> NONE

CARD_DOWNLOAD = NONE
  # Description:
  #   When this option is not NONE, Card Download will be enabled. It will turn on Bootloader and add some LCD and T-Flash dirver in it.
  # Option Values:
  #   NONE: Disable Card Download
  #   FILESYSTEM_ON_CARD: Enable Card DL. The memory card needs to be formated as FAT/FAT32. In other words, the download package can be directly copied into T-flash by Windows. It is the recommanded option for enabling Card DL.
  #   RAW_FORMAT_CARD: Enable Card DL. The image is copied into card via an extra card writer with RAW format. The original content in the card will lost after using the card writer.
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Tools
GAS_SUPPORT = TRUE
  # Description:
  #   This feature is for ATA Tool test on BT & WIFI.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

L1_CATCHER = TRUE
  # Description:
  #   to enable L1 logging.
  # Option Values:
  #   TRUE: Enable
  #   FALSE: Disable
  # Switch-ability:
  #   Non-switchable

LQT_SUPPORT = TRUE
  # Description:
  #   Support LCM Qualification auto-measurement
  # Option Values:
  #   TRUE: Default:
  #         can use LCM Qualification tool
  #   FALSE: Can't use LCM Qualification tool
  # Switch-ability:
  #   Non-switchable

TST_LOGACC_SUPPORT = FALSE
  # Description:
  #   to enable the LogAcc HW Support for TST.
  # Option Values:
  #   TRUE: Enable
  #   TRUE: Enable
  #   FALSE: Disable
  #   FALSE: Disable
  # Switch-ability:
  #   Non-switchable

TST_SET_LOG_BUF_SIZ = NONE
  # Description:
  #   This option allow users to set the desired logging buffer size.
  #   With this option, user could have a large logging buffer and reduce the probability of log drop.
  #   It's useful for a feaure testing under QC.
  # Option Values:
  #   NONE: Invalidate this setting
  #   13-23: Set the logging buffer as (2^n) bytes
  # Switch-ability:
  #   Non-switchable

2G_RF_CUSTOM_TOOL_SUPPORT = FALSE
  # Description:
  #   2G_RF_CUSTOM_TOOL_SUPPORT set to TRUE is to enable the feature of 2G RF custom setting modified by modem bin update tool and can modify the value by NVRAM editor
  #   For UMTS FDD dual mode projects, if user want to enable this feature,  2G_RF_CUSTOM_TOOL_SUPPORT need to set to TRUE. And customer can not modify it by himself, needs to ask for flavor build (lock build)
  #
  #   2G_RF_CUSTOM_TOOL_SUPPORT feature options are default disabled on 11AW1112MP and 11AW1112_MOTO_ODM_SP (due to it is a patch back feature), but is default enabled on 11AMDW1119SP and 11A (thus default enabled on 11B)
  # Option Values:
  #   TRUE: Enable the feature of 2G/3G RF custom setting and band support setting modified by modem bin update tool and can modify the value by NVRAM editor
  #   FALSE: Disable the feature of 2G/3G RF custom setting and band support setting modified by modem bin update tool and also can not modify the value by NVRAM editor
  # Switch-ability:
  #   Non-switchable

FDD_RF_CUSTOM_TOOL_SUPPORT = FALSE
  # Description:
  #   FDD_RF_CUSTOM_TOOL_SUPPORT set to TRUE is to enable the feature of 3G RF custom setting and band support setting modified by modem bin update tool and can modify the value by NVRAM editor
  #
  #
  #
  #   For UMTS FDD dual mode projects, if user want to enable this feature, both FDD_RF_CUSTOM_TOOL_SUPPORT  need to set to TRUE. And customer can not modify it by himself, needs to ask for flavor build (lock build)
  #
  #   FDD_RF_CUSTOM_TOOL_SUPPORT  feature options are default disabled on 11AW1112MP and 11AW1112_MOTO_ODM_SP (due to it is a patch back feature), but is default enabled on 11AMDW1119SP and 11A (thus default enabled on 11B)
  # Option Values:
  #   TRUE: Enable the feature of 2G/3G RF custom setting and band support setting modified by modem bin update tool and can modify the value by NVRAM editor
  #   FALSE: Disable the feature of 2G/3G RF custom setting and band support setting modified by modem bin update tool and also can not modify the value by NVRAM editor
  # Switch-ability:
  #   Non-switchable

DT_SUPPORT = FALSE
  # Description:
  #   This option is used to Turn on/off PC tool Phonesuite File manager related functions. If set FALSE, Phonesuite File manager will not available.
  # Option Values:
  #   FLASE: Turn off DT_SUPPORT, In this case PC tool "phonesuite" can use only limited functions(function like file manager is disabled)
  #   TRUE: Turn on DT_SUPPORT, So MediaTek PC tool "Phonesutie" file manager related functions can be used
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Java
J2ME_SUPPORT = NONE
  # Description:
  #   Modify J2ME_SUPPORT options to meet future 3rd party VM solution
  # Option Values:
  #   J2ME_LIB: Not supported now
  #   NONE: Not support Java
  #   IJET: RollTech Java solution
  #   JBLENDIA: Aplix Java solution
  #   JBED: Not supported now
  #   MTK_DUMMY_MVM: J2ME_VM can be NONE. Not supported now.
  # Switch-ability:
  #   Non-switchable

J2ME_VM = NONE
  # Description:
  #   J2ME_VM     = HI_VM  # J2ME VM:  NONE, KVM, KVM_SOURCE, HI_VM, HI_VM_SOURCE, JAZELLE
  # Option Values:
  #   JAZELLE: Phase out
  #   HI_VM_SOURCE: VM sources (Used by VM vendor)
  #   NONE: Java is disable
  #   HI_VM: Hot spot VM
  #   KVM_SOURCE: VM sources (Used by VM vendor)
  #   KVM: Kilo bytes VM
  # Switch-ability:
  #   Non-switchable

J2ME_MAX_LAUNCH_NUM = 0
  # Description:
  #   Define the Maximum number of VM that can be executed concurrently
  # Option Values:
  #   4: Java concurrent VM count is 4
  #   1: Java concurrent VM count is 1
  #   3: Java concurrent VM count is 3
  #   2: Java concurrent VM count is 2
  #   5: Java concurrent VM count is 5
  # Switch-ability:
  #   Non-switchable

J2ME_SLIM_MEMORY_SUPPORT = FALSE
  # Description:
  #   To enable J2ME_SLIM_MEMORY_SUPPORT, J2ME_SHARE_MED_EXT_MEM must also be enabled. Once enable J2ME_SLIM_MEMORY_SUPPORT, the global memory used by Java will be shrunk for 210K on QVGA, 6252 and the background running will be supported. Since Java will use MED memory in background running with this compile option, all applications using MED memory can not be concurrent. If we want to integrate any third party application using MED memory, we should
  #   1. test if MED has enough memory, if not, please pop up an error dialog and prevent the user entering Java, or,
  #   2. Allocate the full ASM memory when entering the application. Since Java will also allocate some ASM memory, once the application allocates the whole memory, an out-of-memory dialog will be shown and the user can use it to terminate Java.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  #   NO_JSR135_VIDEO: If use the compile option, we'll disable Java video playback, recording, and camera capture.
  # Switch-ability:
  #   Non-switchable

SUPPORT_JAVA_NOKIA_UI = FALSE
  # Description:
  #   On Aplix solution (J2ME_SUPPORT = JBLENDIA), Once SUPPORT_JAVA_NOKIA_UI is TRUE, SUPPORT_JSR_75_PIM, SUPPORT_JSR_205 must be true and J2ME_FEATURE_SET must be JTWI. Aplix kernal libraries will be the files under \mcu\j2me\vm\Jblendia\lib\CLDCHI_JTWI10_FC_
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

SUPPORT_JSR_177 = FALSE
  # Description:
  #   Support Java security API. When SUPPORT_JSR_177 is TRUE inproject make file, SUPPORT_JSR_177 must be defined in projgram.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   Non-switchable

SUPPORT_JSR_257 = FALSE
  # Description:
  #   Support Java JSR-257 for NFC control. Please add a dependency in JAVA_DEF.mak that UPPORT_JSR_177 and NFC_SUPPORT must be both TRUE. When SUPPORT_JSR_257 feature option is TRUE in project make file, SUPPORT_JSR_257 compiile option must also be true.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ VoIP
SDP_SUPPORT = FALSE
  # Description:
  #   to enable SDP function which will be used by PoC, VoIP, Video Streaming, etc
  # Option Values:
  #   TRUE: Enable SDP(Session Description Protocol). It is used in streaming features.
  #   FALSE: Disable SDP.
  # Switch-ability:
  #   N/A

#[Non-modifiable]# ------------------------------ Wifi
WIFI_AUTHENTICATION_LEVEL = WIFI_AUTHENTICATION_PSK_ONLY
  # Description:
  #   Compile option for WIFI security method
  # Option Values:
  #   WIFI_AUTHENTICATION_FULL_EAP: WIFI WPA/WPA2 Enterpise
  #   WIFI_AUTHENTICATION_PSK_ONLY: WIFI WPA/WPA2 PSK
  # Switch-ability:
  #   Non-switchable

WIFI_BT_SINGLE_ANTENNA_SUPPORT = TRUE
  # Description:
  #   for SW control the new HW broad design of WIFI/BT single antenna
  # Option Values:
  #   TRUE: Enable BT WIFI single antenna feature
  #   FALSE: Disable BT WIFI single antenna feature
  # Switch-ability:
  #   Non-switchable

WIFI_BT_SINGLE_ANTENNA_DESIGN = TDD
  # Description:
  #   1. Bluetoot/WLAN Single antenna add a new hardware design. Therefore, WIFI_BT_SINGLE_ANTENNA_SUPPORT is not enought to switch.
  # Option Values:
  #   FDD: single antenna with coupler
  #   TDD: single antenna without coupler
  #   NONE: Disable this feature
  # Switch-ability:
  #   Non-switchable

WAPI_SUPPORT = FALSE
  # Description:
  #   for WAPI feature suuport
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

WNDRV_SUPPORT = LIB
  # Description:
  #   When BM builds the code,  the value should be set to SOURCE.
  #   The compiled library should be put in "\mcu\custom\drv\wifi\Project_Name\lib\".
  #   When BM releases the code, the value should be set to LIB. And the
  #   wndrv should be always linked as a library.
  # Option Values:
  #   LIB:
  #   SOURCE:
  # Switch-ability:
  #   Non-switchable

WPS_SUPPORT = FALSE
  # Description:
  #   To support WiFi Protect Setup
  # Option Values:
  #   TRUE: enable WPS
  #   FALSE: disable WPS
  # Switch-ability:
  #   Non-switchable

HOTSPOT_SUPPORT = FALSE
  # Description:
  #   Enable or disable hotspot feature.
  # Option Values:
  #   TRUE: Enable the hotspot feature.
  #   FALSE: disable the hotspot feature.
  # Switch-ability:
  #   Non-switchable

IPERF_SUPPORT = NONE
  # Description:
  #   Detect compile option conflict for IPERF_SUPPORT.
  #   Iperf (http://dast.nlanr.net/Projects/Iperf/) is an open source software for throughput measurement, especially for Wi-Fi.
  #   Wi-Fi alliance uses it as the benchmark tool for certification program.
  #   To passed
  # Option Values:
  #   QUAD: create 4 iperf tasks.
  #   DUAL: create 2 iperf tasks.
  #   NONE: not open this feature
  #   TRIPLE: create 3 iperf tasks.
  #   SINGLE: create 1 iperf tasks.
  # Switch-ability:
  #   Non-switchable

WIFI_SUPPORT_SNIFFER_MODE = FALSE
  # Description:
  #   wifi feature for supporting wifi sniffer mode(include smartconnection)
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

IPERF_WMM_PS_TEST_SUPPORT = FALSE
  # Description:
  #   Wrap some license request code. When customer need this part and the customer have the authority, this feature could be turn on.
  # Option Values:
  #   TRUE: open this feature
  #   FALSE: not open this feature
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Tiny system
#[Non-modifiable]# ------------------------------ Operator
OPTR_SPEC = NONE
  # Description:
  #   Operator spec name, version and segment
  # Option Values:
  #   CMCC_TDULC_GENERAL: CMCC TD2.0 Ultra Low Cost project, e.g. TD 128+64 project.
  #   VODAFONE_R15_ENTRY3G: Vodafone R15 Entry3G version
  #   ORANGE_0905_COMMASS: Orange 9.0 COMMASS version
  #   NONE: General version (none operator)
  #   VODAFONE_R12_LIVE: Vodafone R12 Live version
  #   CMCC_TD0200_GENERAL: CMCC TD2.0 General project
  #   UNICOM_0200_GENERAL: China Unicom 2.0 version
  #   ORANGE_0800_MEDIAENTRY: Orange 8.0 MEDIAENTRY version
  #   ORANGE_0605_CAM240: Orange 6.5 CAM240 version
  #   CMCC_0204_SEGC: CMCC 2G spec v2.4 Segment C project
  #   CMCC_FWPBW_GENERAL: CMCC 3G TD Fix Wireless Phone Black&White General project
  #   CMCC_FWPCOLOR_GENERAL: CMCC 3G TD Fix Wireless Phone Color General project
  #   ATT_0402_ADAPT: AT&T 4.2 Adapt Project (Only Modem customized)
  # Switch-ability:
  #   Non-switchable

DM_MO_SUPPORT = NONE
  # Description:
  #   To support DM Management Object
  # Option Values:
  #   NONE: not support lawmo and scomo
  #   SCO: scomo
  #   LAW: lawmo
  #   LAW_SCO: lawmo and scomo
  # Switch-ability:
  #   Non-switchable

MOBILE_VIDEO_SUPPORT = NONE
  # Description:
  #   CMCCTD Key feature, which let user play video by network
  # Option Values:
  #   NONE: Not Define this feature
  #   WONDER: Define this feature
  # Switch-ability:
  #   WONDER -> NONE

#[Non-modifiable]# ------------------------------ TC01
TC01_OAEP_SUPPORT = FALSE
  # Description:
  #   LGE audio effect package for opera.
  #   Currently, it only contains EQ and loudness.
  #   LGE will replace the library with Dolby by themselve.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

TC01_BT_SYSTEM_SUPPORT = FALSE
  # Description:
  #   LGE uses its own A2DP library without release any header file or library.
  #   We provide the sample code for LGE integration.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   TRUE -> FALSE

TC01_VOICE_ENGINE = FALSE
  # Description:
  #   LGE has Voice Clarity and Voice Stabilizer engine to provide DRC and DL NR function, this feature option is wrapping their engine into our driver. Since this their engine, only LGE project can open this option.
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   Non-switchable

#[Non-modifiable]# ------------------------------ Others
CUSTOMER_SPECIFIC_FACTORY_DETECTION = NONE
  # Description:
  #   Customer specific factory mode detection mechanism
  #   Some customers may have their own factory mode definition, the mechanism can help to mapping customer specific factory mode to system mode
  # Option Values:
  #   NONE: .
  #   CS_FAC_DET_TYPE_1: Use this type of factoty detection algorithm
  # Switch-ability:
  #   Non-switchable

CLASSAB_LOW_VOLTAGE_VOLUME_PROTECTION = FALSE
  # Description:
  #   For MT6253, If the battary is low, reduce class AB volume to prevent power down
  # Option Values:
  #   TRUE:
  #   FALSE:
  # Switch-ability:
  #   FALSE -> TRUE

PACKAGE_SEG = 32_32_SEG
  # Description:
  #   To identify the package by MCP combination that MTK prepared for difference chipsets. If XX_YY_SEG be configured, then __XX_YY_SEG__ compile option defined for module owners to wrap the code for specific configuration or design for this package.
  # Option Values:
  #   2G_1G_SEG: for 2G+1G segment
  #   1G_512_SEG: for 1G+512 segment
  #   512_256_SEG: for 512+256 segment
  #   128_32_SEG: for 128+32 segment
  #   64_32_SEG: for 64+32 segment
  #   32_32_SEG: for 32+32 segment
  #   16_32_SEG: for 16+32 segment
  #   32_3_SEG: for 32+3 segment
  #   16_3_SEG: for 16+3 segment
  # Switch-ability:
  #   Non-switchable

KEEP_LCD_ENGINE_ON = FALSE
  # Description:
  #   Keep LCD engine on but backlight is off
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   N/A

INIT_LCM_IN_BOOTLOADER = FALSE
  # Description:
  #   In order to speed up boot time, we have to init LCM in bootloader, but in I2C/SPI interface LCMs, they don't need this, so add a FO to seperate.
  # Option Values:
  #   TRUE: Enable this feature, speed up the bootup time.
  #   FALSE: Disable this feature, because these LCMs don't need to hide the delay time.
  # Switch-ability:
  #   N/A

NORMAL_MODE_CAPID_CAL_SUPPORT = FALSE
  # Description:
  #   This option is used for turing on normal mode capid calibration
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

RX_G2_HIGH_GAIN_MODE_DE_FEATURE_SAWLESS = FALSE
  # Description:
  #   Depend on this option to distinguish whether RX_G2_HIGH_GAIN_MODE_DE_FEATURE_SAWLESS is turn on or off.
  # Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

BT_DISABLE_SSP_SUPPORT = FALSE
  # Description:
  #   To disable Bluetooth secure simple pairing on SLIM/low memory projects
  # Option Values:
  #   FALSE: Disable this feature. By default this feature option should be set to FALSE.
  #
  #          Should be enabled only on SLIM project or low memory projects
  #   TRUE: Enable this feature.
  #         Please make sure the project to be considered falls in the catergory of SLIM or low cost model.
  #         Only low memory project should enable this feature
  # Switch-ability:
  #   Non-switchable

BT_MAX_LINK_NUM = 1
  # Description:
  #   BTD v3.0 will suport BT multilink, one BTD can connect to two BTD or smart phone
  #   this option will decribe the maximum linked device
  # Option Values:
  #   1: One link
  #   2: BTD support 2 links
  # Switch-ability:
  #   Non-switchable

#[Phase-out and MTK internal used]# ------------------------------
TST_DNT_LOGGING = FALSE

IC_TEST_TYPE = NONE

NDIS_SUPPORT = NONE

EXTERNAL_ACCESSORY_DETECTION = NONE

RTOS = NUCLEUS

OPENGLES_SUPPORT = FALSE

IRDA_SUPPORT = FALSE

SIM_HOT_SWAP = NONE

MODIS_PLUGIN = ENABLE

RRC_PAYLOAD_FOR_3G_UP_SUPPORT = FALSE

G2D_SUPPORT = FALSE

APP_STORAGE_IN_SYS_DRV = FALSE

VIDEO_CLIPPER_SUPPORT = FALSE

CAMCORDER_VRT_MEM_CAPTURE = FALSE

HTTP_INTERFACE_SUPPORT = FALSE

PLMN_LIST_PREF_SUPPORT = OFF

SQLITE3_SUPPORT = FALSE

GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND = FALSE

PPP_TYPE_PDP_DIALUP_SUPPORT = FALSE

DSP_SOLUTION = NONE

DSPIRDBG = FALSE

GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO = FALSE

MULTIPLE_PPP_DIALUP_SUPPORT = FALSE

MAX_NUM_OF_NDIS_SUPPORT = 3

RM_DECODE_MODE = NORMAL

TST_SUPPORT = TRUE

NVRAM_SUPPORT = TRUE

CENTRALIZED_SLEEP_MANAGER = TRUE

FAX_SUPPORT = FALSE

EMPTY_RESOURCE = TRUE

UART3_SUPPORT = TRUE

MODEM_3G_LOGGING = FALSE

SWLA_RESERVE_SPACE = NONE

FORCE_MEMORY_DUMP = FASLE

MAUI_SDK_TEST = FALSE

E_COMPASS_SENSOR_SUPPORT = NONE

DUMMY_SCATTER_ENABLE = FALSE

TTL_SUPPORT = LIB

L1_GPS_REF_TIME_SUPPORT = FALSE

VCARD_SUPPORT = NONE  #MagicNing SINGLE

ULCS_ASN_SUPPORT_VERSION = ULCS_ASN_SUPPORT_R99

AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT = FALSE

DRM_SECURE_CLOCK = FALSE

DCM_MULTITRUNK = TRUNK_128K

MCD_CODESET_SHIFT_SUPPORT = NONE

STREAM_REC_SUPPORT = FALSE

PPPV6_SUPPORT = FALSE

FORCE_WATCHDOG_MUTE = FALSE

HSUPA_CAPABILITY_NOT_SUPPORT = FALSE

HOTSPOT_SUPPORT_PERFORMANCE_BENCHMARK = FALSE

USB_TETHERING = FALSE

EXT_MODEM_SUPPORT = FALSE

PBCCH_SUPPORT = FALSE

MODIS_FDM = OFF

ALICE_SUPPORT = TRUE

FS_DEDICATED_BUFFER = TRUE

BT_SEQ_SUPPORT = FALSE

BLUETOOTH_VERSION = BT_VER_40

FS_MAX_DISK_SIZE = 0

CNAP_SUPPORT = FALSE

MTK_SLEEP_ENABLE = TRUE

3SET_F8F9_ENABLE = FALSE

AGPS_CP_SIB15_SUPPORT = FALSE

FACTORY_BOOT_MODE_SUPPORT = TRUE

RTOS_DEBUG = TRUE

SSS_SUPPORT = SSS_LIB

FS_OPEN_HINT_SUPPORT = TRUE

FM_RADIO_HW_SEARCH = FALSE

DCM_MM_IMEHW_SUPPORT = FALSE

VENDOR = NONE

MRE_BG_CONC_LAUNCHER = TRUE

BT_A2DP_PROFILE = FALSE

SML_SUPPORT = TRUE

NFC_SUPPORT = NONE

UCM_SUPPORT = TRUE

VAMOS_SUPPORT = FALSE

AOC_SUPPORT = FALSE

MULTIPLE_NDIS_SUPPORT = FALSE

DSSS_SUPPORT = FALSE

GPS_ADAPTOR_SUPPORT = FALSE

BT_GATTS_PROFILE = TRUE

BT_GOEP_PROFILE = FALSE

BT_HF_PROFILE = FALSE

BT_GATTC_PROFILE = TRUE

BCM_AT_SUPPORT = TRUE

IOT_NO_MULTIMEDIA = FALSE

DNSSRV_SUPPORT = FALSE

LOW_LEVEL_BRIDGE_SUPPORT = FALSE

STREAM_SERVER_SUPPORT = FALSE

VAD_SUPPORT = FALSE

WIFI_SUPPORT_APSTA_CONCURRENCY = FALSE

VOICE_CHANGER_SUPPORT = FALSE

XYSSL_SUPPORT = FALSE

EMAIL_SUPPORT = NONE

GPS_HS_SUPPORT = FALSE

MJPG_ENCODE_MODE = SLIM

CMOS_SENSOR = NONE

BES_LOUDNESS_SUPPORT = FALSE

WIFI_SUPPORT = MT5931

GUOBI_WINGUO_SUPPORT = WINGUO_NONE

GAMELOFT_CONTENT_SUPPORT = FALSE

UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT = FALSE

H264_OPEN_API = FALSE

FLASHLIGHT_MODULE = NONE

ISO_PRIORITY_MODE_SUPPORT = FALSE

MSHUTTER_SUPPORT = FALSE

MTK_DSP_DEBUG = FALSE

PMU_WITH_EXTERNL_CHARGER = FALSE

MDP_LCD_FW_UPDATE = FALSE

ATV_SMS_SUPPORT = FALSE

SW_FLASH = NONE

CHE_SUPPORT = FALSE

R99_SUPPORT = TRUE

R4_SUPPORT = FALSE

R5_SUPPORT = FALSE

UART_CHARGER_THE_SAME_INTERFACE = NONE

MODIS_ON_VC9 = TRUE

BSAC_DECODE = FALSE

EMLPP_SUPPORT = FALSE

GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP = TRUE

SUPPORT_VIDEO_RECORD_ROTATE = FALSE

SUBLCD_DEDICATED_KEYS_SUPPORT = FALSE

TV_OUT_SUPPORT = FALSE

CCBS_SUPPORT = FALSE

GAME_ENGINE = NONE

UUS_SUPPORT = FALSE

CMMB_CAS_FULL_CARD_SUPPORT = FALSE

QQMOVIE_SUPPORT = FALSE

SPLIT_SYSTEM = FALSE

VDOEDT_SUPPORT = FALSE

FS_MOVE_SUPPORT = TRUE

CMMB_CAS_SMD_SUPPORT = FALSE

AUTOCAP_PANORAMA_SUPPORT = FALSE

GEMINI_VERSION = V1

LCM_SCANLINE_ROTATION_SUPPORT = FALSE

MAIN_LCM_SCANLINE_ROTATION_CCW_ANGLE = 90

SUB_LCM_SCANLINE_ROTATION_CCW_ANGLE = 90

# *************************************************************************
# Release Setting Section
# *************************************************************************
RELEASE_PACKAGE		= REL_CR_MMI_$(strip $(PROJECT))	# REL_CR_MMI_GPRS, REL_CR_MMI_GSM, REL_CR_L4_GPRS, REL_CR_L4_GSM
RELEASE_WAE		= SRC		# MTK/SRC, only works when TELECA_FEATURES works
RELEASE_WAP		= MTK		# MTK/SRC, only works when TELECA_FEATURES works

RELEASE_$(strip $(INPUT_METHOD)) = SRC	# MTK/SRC, only works when INPUT_METHOD is turning on
RELEASE_INPUT_METHODS_SRC =		# MMI_ZI, MMI_T9, MMI_ITAP,

# *************************************************************************
# Consistent Feature Options
# *************************************************************************
COM_DEFS_FOR_MT2503RF_CUSTOM = MT6261RF_RF MT2503RF_RF MT2503RF_CUSTOM
COM_DEFS_FOR_GXQ03D_M2M_11C_LCM = COLOR_LCD GXQ03D_M2M_11C_LCM TFT_MAINLCD
# *************************************************************************
# Include MODEM.mak
# *************************************************************************
include make\MODEM.mak

# *************************************************************************
# Project specified preprocessor definitions
# *************************************************************************
CUSTOM_OPTION += __GAS_DISABLE_POWER_ON_STORED_SEARCH__
CUSTOM_OPTION += __MM_FAST_RETRY_ON_LOWER_LAYER_RELEASE__
CUSTOM_OPTION     +=  __MSDC_NO_WRITE_PROTECT__
CUSTOM_OPTION     +=  __MMS_MEMORY_CARD_STORAGE_SUPPORT__
CUSTOM_OPTION     +=  __TST_USE_MINI_LOG_BUF__
CUSTOM_OPTION     +=  __MRE_CUST_MEM_SIZE__=800
CUSTOM_OPTION     +=  __IMAGE_SENSOR_PRETEND_VGA__
CUSTOM_OPTION     +=  __AUDIO_ULTRA_SLIM__
CUSTOM_OPTION     +=  __CUSTOM_MRE_MAX_SIZE__=0
CUSTOM_OPTION     +=  __GFX_SLIM_COLOR_FORMAT__ __GFX_SLIM_THUMB_SWITCH__
CUSTOM_OPTION     +=  __AUTO_TCL__
CUSTOM_OPTION     +=  __MRE_BGMEM_SIZE__=200
CUSTOM_OPTION     +=  __MSDC_4BIT_BUSWIDTH__ __NBR_CELL_INFO__
#CUSTOM_OPTION     +=  DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON
CUSTOM_OPTION += __FAKE_CELL_FEATURE__
REMOVE_CUSTOM_OPTION += __IP_NUMBER__
# *************************************************************************
# Custom Release Component Configuration
# *************************************************************************
include make\$(strip $(RELEASE_PACKAGE)).mak


# ************************************************************************* 
# Component trace definition header files for custom release only 
# ************************************************************************* 
# Following trace headers are already existed in custom release 
# You can add new traces with kal_trace() in the following trace headers 
EXISTED_CUS_REL_TRACE_DEFS = 
EXISTED_CUS_REL_TRACE_DEFS += nvram\include\nvram_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\phb\include\phb_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\uem\include\uem_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += fs\common\include\fs_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += hal\system\init\inc\system_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\include\l4_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\csm\csm_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += hal\peripheral\inc\bmt_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += hal\audio\src\v1\inc\l1sp_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += hal\audio\src\v1\inc\l1audio_sph_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += inet_ps\abm\include\abm_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += usb\include\usb_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += drv\include\drv_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\sim2\include\sim_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += gps\inc\gps_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += media\common\include\med_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += hal\video\common\include\vcodec_v2_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += inet_ps\ntpd\include\ntpd_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += bcm\bcm_trc.h 
 
# Customer can add new trace headers here for new modules 
NEW_CUS_REL_TRACE_DEFS = 
