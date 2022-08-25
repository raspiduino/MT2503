/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_fnc_cct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Camera calibtration related fuctions
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _FT_FNC_CCT_H_
#define _FT_FNC_CCT_H_

//#include "ft_msg.h"
#include "ft_msg_common.h"


//#include "aaa_awb_v2.h"
#if (!defined(__MODEM_COMPONENT__)&&!defined(__MODEM_PRODUCT__))
#include "cct_comm_def.h"
#endif
//#include "ft_private.h"

/*******************************************************************************
*
*  Message structures defined for CCT Interface
*
*******************************************************************************/

#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))//aviod smart phone moden build error
//#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))
//#include "isp_if.h"
//#include "camera_para.h"// <-- you must include this before isp_cct_if.h
#include "isp_cct_if.h"
//#include "isp_device_if.h"
//#include "ae_awb.h"

//HAL macro
 #define aeFlareSettingStruct AE_FLARE_SETTING_STRUCT
 #define aeGammaTableStruct AE_GAMMA_TABLE_STRUCT
 #define aeCctCurrentMeteringResultStruct AE_CCT_CURRENT_METERING_RESULT_STRUCT
 #define aeCctMeteringSettingStruct AE_CCT_METERING_SETTING_STRUCT
 #define T_CCMMode CCM_MODE_ENUM
 #define cct_awb_status_struct CAL_CCT_AWB_STATUS_STRUCT
 #define aeOutputCurrentAeInfo AE_OUTPUT_CURRENT_AE_INFO_STRUCT
 #define aeGammaSettingStruct AE_GAMMA_SETTING_STRUCT
 #define aeCctApplyExpoInfoStruct AE_CCT_APPLY_EXPO_INFO_STRUCT
 #define aeCctExpoSettingStruct AE_CCT_EXPO_SETTING_STRUCT
 #define aeCctCurrentExpoInfoStruct AE_CCT_CURRENT_EXPO_INFO_STRUCT
 //#define ccm_para_struct CCM_PARA_STRUCT
 #define cct_ccm_status_struct CAL_CCT_CCM_STATUS_STRUCT
 //#define awb_v2_para_struct AWB_PARA_STRUCT //HAL
 //#define nvram_af_para_struct AF_NVRAM_PARA_STRUCT// HAL
 //#define camera_ae_period_para_struct CAL_CCT_AE_PERIOD_PARA_STRUCT // danbo add
 #define flashlight_cdt_ae_para_struct FLASH_AE_CDT_PARA_STRUCT
 //#define aeSmoothModeStruct AE_CCT_SMOOTH_SETTING_STRUCT
 #define aeFlareHistogram CAL_CCT_AE_FLARE_HISTOGRAM_STRUCT
 #define aeWindowHistogram CAL_CCT_AE_WINDOW_HISTOGRAM_STRUCT

#define FT_CCT_ERR_TGT_NO_MEM_FOR_SINGLE_SHOT			0xFF
#define FT_CCT_ERR_TGT_NO_MEM_FOR_MULTI_SHOT			0xFE
#define FT_CCT_ERR_INVALID_SENSOR_ID					0xFD
#define FT_CCT_ERR_NOT_IMPLEMENT_YET					0xFC
#define FT_CCT_ERR_PREVIEW_ALREADY_STARTED				0xFB
#define FT_CCT_ERR_PREVIEW_ALREADY_STOPPED				0xFA
#define FT_CCT_ERR_CANCEL_IMAGE_SENDING					0xF9
#define FT_CCT_ERR_TST_QUEUE_FULL						0xF8
#define FT_CCT_ERR_READ_NVRAM_FAIL						0xF7
#define FT_CCT_ERR_WRITE_NVRAM_FAIL						0xF6
#define FT_CCT_ERR_AE_INVALID_EC_LEVEL					0xF5
#define FT_CCT_ERR_AE_INVALID_EC_STEP					0xF4
#define FT_CCT_ERR_AE_ALREADY_ENABLED					0xF3
#define FT_CCT_ERR_AE_ALREADY_DISABLED					0xF2
#define FT_CCT_ERR_WB_INVALID_INDEX						0xF1
#define FT_CCT_ERR_AE_IS_NOT_DISABLED					0xF0
#define FT_CCT_ERR_AFRESH_CAPTURE_FIRST					0xEF
#define FT_CCT_ERR_CAPTURE_WIDTH_HEIGHT_TOO_SMALL		0xEE
#define FT_CCT_ERR_SENSOR_ENG_SET_INVALID_VALUE			0xED
#define FT_CCT_ERR_SENSOR_ENG_GROUP_NOT_EXIST			0xEC
#define FT_CCT_ERR_SENSOR_ENG_ITEM_NOT_EXIST			0xEB
#define FT_CCT_ERR_INVALID_COMPENSATION_MODE			0xEA
#define FT_CCT_ERR_USB_COM_NOT_READY					0xE9
#define FT_CCT_DEFECTPIXEL_CAL_UNDER_PROCESSING			0xE8
#define FT_CCT_ERR_DEFECTPIXEL_CAL_NO_MEM				0xE7
#define	FT_CCT_ERR_TOO_MANY_DEFECT_PIXEL				0xE6
#define FT_CCT_ERR_CAPTURE_JPEG_FAIL					0xE5
#define FT_CCT_ERR_CAPTURE_JPEG_TIMEOUT					0xE4
#define FT_CCT_ERR_AF_FAIL								0xE3
#define FT_CCT_ERR_AF_TIMEOUT							0xE2
#define FT_CCT_ERR_AF_LENS_OFFSET_CAL_FAIL				0xE1
#define FT_CCT_ERR_PREVIEW_MUST_ENABLE					0xE0
#define FT_CCT_ERR_UNSUPPORT_CAPTURE_FORMAT				0xDF
#define FT_CCT_ERR_EXCEED_MAX_DEFECT_PIXEL				0xDE
#define FT_CCT_ERR_INVALID_WIDTH_FACTOR					0xDD
#define FT_CCT_ERR_PREVIEW_MUST_DISABLE					0xDC
#define FT_CCT_6238_ERR_AE_ALREADY_ENABLED					0xDB
#define FT_CCT_6238_ERR_AE_ALREADY_DISABLED					0xDA
#define FT_CCT_6238_ERR_AE_IS_NOT_DISABLED					0xD9
#define FT_CCT_ERR_SHADING_TABLE_SIZE					0xD8
#define FT_CCT_DUAL_ERR_DETECT_SENSOR_ID_FAIL			0xD7
#define FT_CCT_ERR_DETECT_SENSOR_ID_FAIL					0xD6
#define FT_CCT_ERR_YUV_SENSOR_NOT_SUPPORT				0xD5
#define FT_CCT_DUAL_GET_LENS_PREFIX_NAME_TAIL			0xD4
#if defined(DRV_ISP_PCA_SUPPORT)
#define FT_CCT_6238_CAMERA_LID_NUM 7;
#else
#define FT_CCT_6238_CAMERA_LID_NUM 6;
#endif
#define FT_CCT_CAMERA_LID_NUM		   2;

#define FT_CCT_INTERNAL_BUF_SIZE		(0x2100)	// 2112 DWORDs 



typedef enum {
	 FT_CCT_OP_REG_READ = 0
	,FT_CCT_OP_REG_WRITE
	,FT_CCT_OP_PREVIEW_LCD_START
	,FT_CCT_OP_PREVIEW_LCD_STOP
	,FT_CCT_OP_SINGLE_SHOT_CAPTURE
	,FT_CCT_OP_MULTI_SHOT_CAPTURE   //5
	,FT_CCT_OP_QUERY_SENSOR
	,FT_CCT_OP_LOAD_FROM_NVRAM
	,FT_CCT_OP_SAVE_TO_NVRAM
	,FT_CCT_OP_AE_ENABLE
	,FT_CCT_OP_AE_DISABLE   //10
	,FT_CCT_OP_AE_SET_EXPOSE_LEVEL
	,FT_CCT_OP_AE_GET_EXPOSE_LEVEL
	,FT_CCT_OP_AE_QUERY_EC_STEP_INFO
	,FT_CCT_OP_AE_SET_INIT_SHUTTER
	,FT_CCT_OP_AE_GET_INIT_SHUTTER  //15
	,FT_CCT_OP_WB_ACTIVATE_BY_INDEX
	,FT_CCT_OP_WB_SET_BY_INDEX
	,FT_CCT_OP_WB_QUERY_ALL
	,FT_CCT_OP_AE_SET_MANUAL_SHUTTER
	,FT_CCT_OP_AE_GET_MANUAL_SHUTTER  //20
	,FT_CCT_OP_GET_CAMERA_PARA_BUF
	,FT_CCT_OP_SINGLE_SHOT_CAPTURE_EX
	,FT_CCT_OP_MULTI_SHOT_CAPTURE_EX
	,FT_CCT_OP_GET_CAPTURE_BUF
	,FT_CCT_OP_RESUME_AE_AWB_PREVIEW_FROM_UNFINISHED_CAPTURE  //25
	,FT_CCT_OP_GET_BANDING_FACTOR
	,FT_CCT_OP_GET_SENSOR_PREGAIN
	,FT_CCT_OP_SET_SENSOR_PREGAIN
	,FT_CCT_OP_MAIN_LCD_BACKLIGHT_SETTING
	,FT_CCT_OP_GET_GAMMA_TABLE   //30
	,FT_CCT_OP_SET_GAMMA_TABLE
	,FT_CCT_OP_QUERY_ISP_ID
	,FT_CCT_OP_GET_CAL_STRUCT_BUF
	,FT_CCT_OP_GET_ENG_SENSOR_PARA
	,FT_CCT_OP_SET_ENG_SENSOR_PARA  //35
	,FT_CCT_OP_GET_COMPENSATION_MODE
	,FT_CCT_OP_SET_COMPENSATION_MODE
	,FT_CCT_OP_GET_SHADING_PARA
	,FT_CCT_OP_SET_SHADING_PARA
	,FT_CCT_OP_GET_AUTODEFECT_PARA   //40
	,FT_CCT_OP_SET_AUTODEFECT_PARA
	,FT_CCT_OP_GET_LAST_COMPENSATION_MODE
	,FT_CCT_OP_GET_AUTODEFECT_COUNT
	,FT_CCT_OP_SET_CAPTURE_DATA_TUNNEL
	,FT_CCT_OP_USB_TUNNEL_CANCEL    //45
	,FT_CCT_OP_DEFECT_TABLE_VERIFY_BLOCK_FACTOR
	,FT_CCT_OP_DEFECT_TABLE_CAL
	,FT_CCT_OP_GET_DEFECT_TABLE
	,FT_CCT_OP_SET_DEFECT_TABLE
	,FT_CCT_OP_DEV_GET_DSC_INFO   //50
	,FT_CCT_OP_DEV_GET_IRIS_INFO
	,FT_CCT_OP_DEV_SET_IRIS_INFO
	,FT_CCT_OP_DEV_AE_GET_INFO
	,FT_CCT_OP_DEV_AE_SET_TABLE_IDX
	,FT_CCT_OP_DEV_AE_SET_VALUE  //55
	,FT_CCT_OP_DEV_AF_GET_TABLE
	,FT_CCT_OP_DEV_AF_CAL
	,FT_CCT_OP_DEV_AF_SET_TABLE_IDX
	,FT_CCT_OP_DEV_AF_SET_POS
	,FT_CCT_OP_DEV_STROBE_CAL_ENABLE  //60
	,FT_CCT_OP_DEV_STROBE_CAL_SET_PARA
	,FT_CCT_OP_DEV_STROBE_CAL_DISABLE
	,FT_CCT_OP_ENABLE_USBCOM
	,FT_CCT_OP_AF_ON_OFF
	,FT_CCT_OP_DEFECT_TABLE_ON_OFF  //65
	,FT_CCT_OP_AF_LENS_OFFSET_CAL
	,FT_CCT_OP_DEFECT_TABLE_BYPASS_BACKUP_SETTING
	,FT_CCT_OP_DEFECT_TABLE_RESTORE_SETTING
	,FT_CCT_OP_AE_GET_PERIOD_PARA
	,FT_CCT_OP_AE_SET_PERIOD_PARA   //70
	,FT_CCT_OP_DEV_AE_BYPASS_FREERUN
	,FT_CCT_OP_DEV_AE_SET_SCENE_MODE
	,FT_CCT_OP_GET_GAMMA_TABLE_ON_OFF_FLAG
	,FT_CCT_OP_SET_GAMMA_TABLE_ON_OFF_FLAG
	,FT_CCT_OP_GET_GAMMA_ON_OFF_FLAG  //75
	,FT_CCT_OP_SET_GAMMA_ON_OFF_FLAG
	,FT_CCT_OP_DEV_GET_ISO_GAIN
	,FT_CCT_OP_DEV_SET_ISO_GAIN
	,FT_CCT_OP_DEV_RECOVER_ISO_CAPTURE
	,FT_CCT_OP_DEV_SET_ISO_CAPTURE  //80
	,FT_CCT_OP_DEV_GET_ISO_VALUE
	,FT_CCT_OP_DEV_SET_ISO_VALUE
	,FT_CCT_OP_DEV_FLASHLIGHT_CHARGE
	,FT_CCT_OP_DEV_FLASHLIGHT_STROBE
	,FT_CCT_OP_DEV_FLASHLIGHT_CONF  //85
	,FT_CCT_OP_DEV_MODE_SIZE
	,FT_CCT_OP_DEV_FLASHLIGHT_TYPE
	,FT_CCT_OP_DEV_GET_ISO_GAIN_CCT
	,FT_CCT_OP_DEV_SET_ISO_GAIN_CCT
	,FT_CCT_OP_DEV_GET_ISO_VALUE_CCT  //90
	,FT_CCT_OP_DEV_SET_ISO_VALUE_CCT
	,FT_CCT_OP_DEV_IF_SUPPORT_ISO
	,FT_CCT_OP_DEV_GET_FLASH_LEVEL
	,FT_CCT_OP_DEV_SET_FLASH_LEVEL
	,FT_CCT_OP_DEV_SET_FLASH_AE_INDEX  //95
	,FT_CCT_OP_DEV_GET_FLASH_AE_INDEX
	,FT_CCT_6238_OP_AE_ENABLE
	,FT_CCT_6238_OP_AE_DISABLE
	,FT_CCT_6238_OP_AE_SET_SCENE_MODE
	,FT_CCT_6238_OP_AE_SET_METERING_MODE  //100
	,FT_CCT_6238_OP_AE_GET_CURRENT_EXPO_INFO
	,FT_CCT_6238_OP_AE_APPLY_EXPO_INFO
	,FT_CCT_6238_OP_AE_SELECT_BAND
	,FT_CCT_6238_OP_AE_GET_AUTO_EXPO_PARA
	,FT_CCT_6238_OP_AE_GET_ISO_VALUE_GAIN   //105
	,FT_CCT_6238_OP_AE_GET_GAMMA_PARA
	,FT_CCT_6238_OP_AE_GET_GAMMA_TABLE
	,FT_CCT_6238_OP_AE_GET_FLARE_PARA
	,FT_CCT_6238_OP_AE_UPDATE_AUTO_EXPO_PARA
	,FT_CCT_6238_OP_AE_UPDATE_ISO_VALUE_GAIN  //110
	,FT_CCT_6238_OP_AE_UPDATE_GAMMA_PARA
	,FT_CCT_6238_OP_AE_UPDATE_FLARE_PARA
	,FT_CCT_6238_OP_AE_GET_HISTOGRAM
	,FT_CCT_6238_OP_AE_GET_METERING_RESULT
	,FT_CCT_6238_OP_AE_GET_METERING_MODE_SETTING  //115
	,FT_CCT_6238_OP_AE_UPDATE_METERING_MODE_SETTING
	,FT_CCT_6238_OP_AE_GET_WINDOW_HISTOGRAM
	,FT_CCT_6238_OP_AE_GET_SMOOTH_MODE_SETTING
	,FT_CCT_6238_OP_AE_UPDATE_SMOOTH_MODE_SETTING
	,FT_CCT_6238_OP_AE_ENABLE_PREVIEW_LOG  //120
	,FT_CCT_6238_OP_AE_DISABLE_PREVIEW_LOG	
	,FT_CCT_6238_OP_AE_GET_PREVIEW_EXPO_INFO
	,FT_CCT_6238_OP_AWB_ENABLE_PREF_GAIN
	,FT_CCT_6238_OP_AWB_DISABLE_PREF_GAIN
	,FT_CCT_6238_OP_AWB_ENABLE_FAST_CONVERGE  //125
	,FT_CCT_6238_OP_AWB_DISABLE_FAST_CONVERGE
	,FT_CCT_6238_OP_AWB_ENABLE_AUTO_RUN
	,FT_CCT_6238_OP_AWB_DISABLE_AUTO_RUN	
	,FT_CCT_6238_OP_AWB_ENABLE_SMALL_BOX
	,FT_CCT_6238_OP_AWB_DISABLE_SMALL_BOX  //130
	,FT_CCT_6238_OP_AWB_GET_WINDOW_WHIT_POINT_COUNT_ARRAY
	,FT_CCT_6238_OP_AWB_GET_LIGHT_MODE
	,FT_CCT_6238_OP_AWB_GET_GAIN
	,FT_CCT_6238_OP_AWB_SET_GAIN
	,FT_CCT_6238_OP_AWB_SET_PREF_FACTOR  //135
	,FT_CCT_6238_OP_AWB_GET_PREF_FACTOR
	,FT_CCT_6238_OP_AWB_ENABLE_DYNAMIC_CCM
	,FT_CCT_6238_OP_AWB_DISABLE_DYNAMIC_CCM
	,FT_CCT_6238_OP_AWB_GET_CURRENT_CCM
	,FT_CCT_6238_OP_AWB_ENABLE_FLASH_SYNC  //140
	,FT_CCT_6238_OP_AWB_DISABLE_FLASH_SYNC
	,FT_CCT_6238_OP_AWB_APPLY_CAMERA_PARA2
	,FT_CCT_6238_OP_AWB_UPDATE_CAMERA_PARA2
	,FT_CCT_6238_OP_AWB_GET_NVRAM_CCM
	,FT_CCT_6238_OP_AWB_SET_NVRAM_CCM   //145
	,FT_CCT_6238_OP_AWB_GET_AWB_PARA
	,FT_CCT_6238_OP_AWB_GET_CCM_PARA
	,FT_CCT_6238_OP_AWB_UPDATE_AWB_PARA
	,FT_CCT_6238_OP_AWB_UPDATE_CCM_PARA
	,FT_CCT_6238_OP_AWB_GET_AWB_STATUS  //150
	,FT_CCT_6238_OP_AWB_GET_CCM_STATUS
	,FT_CCT_6238_OP_AWB_UPDATE_AWB_STATUS
	,FT_CCT_6238_OP_AWB_UPDATE_CCM_STATUS
	,FT_CCT_6238_OP_AWB_SET_CURRENT_CCM
	,FT_CCT_6238_OP_ISP_SET_SHADING_PARA  //155
	,FT_CCT_6238_OP_ISP_GET_SHADING_PARA
	,FT_CCT_6238_OP_ISP_ENABLE_DYNAMIC_BYPASS_MODE
	,FT_CCT_6238_OP_ISP_DISABLE_DYNAMIC_BYPASS_MODE
	,FT_CCT_6238_OP_ISP_GET_TUNING_PARA
	,FT_CCT_6238_OP_ISP_SET_TUNING_PARA  //160
	,FT_CCT_6238_OP_ISP_GET_PARTIAL_SHADING_TABLE
	,FT_CCT_6238_OP_ISP_SET_PARTIAL_SHADING_TABLE
	,FT_CCT_6238_OP_ISP_SET_SHADING_ON_OFF
	,FT_CCT_6238_OP_ISP_GET_SHADING_ON_OFF	
    ,FT_CCT_6238_OP_AE_GET_SCENE_MODE    //165
    ,FT_CCT_6238_OP_AE_GET_METERING_MODE
    ,FT_CCT_6238_OP_AE_GET_BAND
    ,FT_CCT_6238_OP_AE_SET_GAMMA_BYPASS
    ,FT_CCT_6238_OP_AE_GET_GAMMA_BYPASS_FLAG		
	,FT_CCT_6238_OP_ISP_SET_TUNING_INDEX  //170
	,FT_CCT_6238_OP_ISP_GET_TUNING_INDEX
	,FT_CCT_6238_OP_ISP_GET_AE_TOTAL_GAIN
	,FT_CCT_6238_OP_ISP_GET_DYNAMIC_BYPASS_MODE_ON_OFF
     ,FT_CCT_6238_OP_ISP_FLASHLIGHT_LINEARITY_PRESTROBE
     ,FT_CCT_6238_OP_ISP_FLASHLIGHT_LINEARITY_RESULT  //175
     ,FT_CCT_6238_OP_ISP_ENABLE_BINNING_MODE
     ,FT_CCT_6238_OP_ISP_DISABLE_BINNING_MODE     
     ,FT_CCT_6238_OP_ISP_GET_BINNING_MODE
     ,FT_CCT_6238_OP_ISP_FLASHLIGHT_SET_AE_PARA_2
	,FT_CCT_6238_OP_AF_GET_PARA                   //180
	,FT_CCT_6238_OP_AF_SET_PARA
	,FT_CCT_6238_OP_ISP_FLASHLIGHT_GET_AE_PARA_2
      ,FT_CCT_6238_OP_ISP_GET_CAMCORDER_INFO
      ,FT_CCT_6238_OP_ISP_BYPASS_SHADING_MODE_ENABLE
    ,FT_CCT_6238_OP_ISP_BYPASS_SHADING_MODE_DISABLE  //185
    ,FT_CCT_6238_OP_FLASH_CONFIG
    ,FT_CCT_6238_FLASH_DURATION_LUT
    ,FT_CCT_6238_ISP_DEFECT_TABLE_ON
	,FT_CCT_6238_ISP_DEFECT_TABLE_OFF
    //----------[TH]M-shutter---------------------------------------------
	,FT_CCT_6238_OP_SET_SHUTTER_MODE    //190
	,FT_CCT_6238_OP_SET_SHUTTER_TARGET_TIME
	,FT_CCT_6238_OP_SET_SHUTTER_DELAY_TIME
	,FT_CCT_6238_OP_GET_SHUTTER_G_CHANNEL_MEAN
	,FT_CCT_6238_OP_GET_SHUTTER_TARGET_TIME
	,FT_CCT_6238_OP_GET_SHUTTER_DELAY_TIME  //195
	,FT_CCT_6238_OP_GET_SHUTTER_MODE
	,FT_CCT_6238_OP_SET_SHUTTER_CALIBRATION_ENABLE
	,FT_CCT_6238_OP_SET_SHUTTER_CALIBRATION_DISABLE
	,FT_CCT_6238_OP_GET_PREVIEW_TARGET_LINES
	,FT_CCT_6238_OP_ENABLE_IMAGE_TRANSFER   //200
	,FT_CCT_6238_OP_DISABLE_IMAGE_TRANSFER
	,FT_CCT_6238_OP_ISP_ENABLE_AUTO_DEFECT
	,FT_CCT_6238_OP_ISP_DISABLE_AUTO_DEFECT
	//--------------Please add op code above this line for tool version compatibility--------------------
	,FT_CCT_6238_ISP_GET_DEFECT_TABLE
	,FT_CCT_6238_ISP_SET_DEFECT_TABLE   //205
	,FT_CCT_6238_ISP_GET_SHADING_TABLE
	,FT_CCT_6238_ISP_SET_SHADING_TABLE	
	,FT_CCT_6238_OP_ISP_GET_TUNING_PARAS
	,FT_CCT_6238_OP_ISP_SET_TUNING_PARAS
	,FT_CCT_6238_OP_AE_GET_GAMMA_PARAS  //210
	,FT_CCT_6238_OP_AE_UPDATE_GAMMA_PARAS
	,FT_CCT_6238_OP_AE_GET_WINDOW_HISTOGRAM_DATA
	,FT_CCT_6238_OP_AWB_GET_AWB_PARAS
	,FT_CCT_6238_OP_AWB_UPDATE_AWB_PARAS
	,FT_CCT_6238_OP_AF_GET_PARAS    //215
	,FT_CCT_6238_OP_AF_SET_PARAS
	,FT_CCT_6238_OP_ISP_FLASHLIGHT_LINEARITY_RESULTS
       ,FT_CCT_DUAL_OP_SET_CAMERA_MAIN_OR_SUB_TYPE		
       ,FT_CCT_DUAL_OP_GET_CAMRA_PARA_TABLE				
       ,FT_CCT_DUAL_OP_GET_VALID_CAMERA_TYPE //220				
       ,FT_CCT_DUAL_OP_GET_SENSOR_PREFIX_NAME
       ,FT_CCT_DUAL_OP_GET_LENS_PREFIX_NAME
       ,FT_CCT_6238_OP_ISP_GET_SHADING_TABLE_V3
       ,FT_CCT_6238_OP_ISP_SET_SHADING_TABLE_V3
       ,FT_CCT_6238_OP_CHECK_DYNAMIC_LSC_SUPPORT  //225
       ,FT_CCT_6238_OP_ENABLE_AWB_CT
       ,FT_CCT_6238_OP_DISABLE_AWB_CT
       ,FT_CCT_6238_OP_SET_LIGHT_SOURCE
       ,FT_CCT_6238_OP_ISP_SET_PCA_TABLE
       ,FT_CCT_6238_OP_ISP_GET_PCA_TABLE  //230
       ,FT_CCT_6238_OP_ISP_SET_PCA_PARA
       ,FT_CCT_6238_OP_ISP_GET_PCA_PARA
       ,FT_CCT_6238_OP_CHECK_PCA_SUPPORT
       ,FT_CCT_6238_OP_SET_CCM_MODE
	,FT_CCT_6238_OP_GET_CCM_MODE   //235
	,FT_CCT_OP_CHECK_ASD_PCA_SUPPORT
	,FT_CCT_OP_ISP_SET_PCA_TABLE_IDX
	,FT_CCT_OP_ISP_GET_PCA_TABLE_IDX
	,FT_CCT_OP_END
} FT_CCT_OP;

enum
{
	CCT_BAYER_B=0,
	CCT_BAYER_Gb,
	CCT_BAYER_Gr,
	CCT_BAYER_R
};
//remove by HAL, but CCT still need it to maintain its structure
typedef enum //AV_NO
{
	AV020=0,AV028, AV035, AV040, AV045, AV050, AV056, AV063, AV071, AV080, 
	AV090, 	AV100, AV110, AV130, AV140, AV160, AV180, AV200, AV220, AV_NO
}APERTURE_VALUE_INDEX;

enum
{
	CAPTRUE_MODE_RAW_8BIT = 0,		// RAW, 8Bit, capture to internal ram
	CAPTRUE_MODE_YUV,				// YUV, capture to internal ram
	CAPTRUE_MODE_RAW_10BIT,			// RAW, 10Bit, capture to internal ram
	CAPTRUE_MODE_RGB888,			// RGB888, capture to internal ram
	CAPTRUE_MODE_RGB565,			// RGB565, capture to internal ram
	CAPTRUE_MODE_EXT_RAW_8BIT,      // RAW, 8Bit, capture to external ram
	CAPTRUE_MODE_EXT_RAW_10BIT,		// RAW, 10Bit, capture to external ram	
	CAPTRUE_MODE_EXT_YUV,			// YUV, capture to external ram
	CAPTRUE_MODE_EXT_RGB888,		// RGB888, capture to external ram
	CAPTRUE_MODE_EXT_RGB565,		// RGB565, capture to external ram
	CAPTRUE_MODE_JPEG		    	// JPEG capture
};
typedef enum {
	 DATA_TUNNEL_RS232 = 0
	,DATA_TUNNEL_USB_COM
} FT_CCT_DATA_TUNNEL_E;

typedef enum {
	 USB_TUNNEL_IDLE = 0
	,USB_TUNNEL_SENDING
	,USB_TUNNEL_CANCEL
	,USB_TUNNEL_FINISH
} FT_CCT_USB_TUNNEL_STATE_E;

// capture jpeg 
typedef enum {
	 CAPTURE_JPEG_IDLE = 0
	,CAPTURE_JPEG_PROCESS
	,CAPTURE_JPEG_DONE
	,CAPTURE_JPEG_FAIL
} FT_CCT_CAPTURE_JPEG_STATE_E;



typedef enum {
	FT_CCT_REG_ISP = 0,
	FT_CCT_REG_CMOS,
	FT_CCT_REG_CCD
} FT_CCT_REG_TYPE;

typedef enum {
	FT_CCT_CAP_TO_INT_SRAM = 0,
	FT_CCT_CAP_TO_EXT_SRAM
} FT_CCT_CAP_BUF_TYPE;
/* HAL cct_comm_def.h
typedef enum {
	 OUTPUT_RAW_8BITS = 0
	,OUTPUT_YUV
	,OUTPUT_JPEG
	,OUTPUT_RGB888
	,OUTPUT_RAW_10BITS
	,OUTPUT_EXT_RAW_8BITS
	,OUTPUT_EXT_RAW_10BITS
	,OUTPUT_EXT_YUV
} FT_CCT_CAP_OUTPUT_FORMAT;
*/
typedef enum {
	FT_CCT_BAYER_PTN_GR = 0,
	FT_CCT_BAYER_PTN_R,
	FT_CCT_BAYER_PTN_B,
	FT_CCT_BAYER_PTN_GB
} FT_CCT_BAYER_PATTERN;

typedef enum {
	FT_CCT_WB_MANUAL_1 = 0,
	FT_CCT_WB_MANUAL_2,
	FT_CCT_WB_MANUAL_3,
	FT_CCT_WB_MANUAL_4,
	FT_CCT_WB_MANUAL_5,
	FT_CCT_WB_AUTO = 0xAA,
	FT_CCT_WB_RESET = 0xBB,
	FT_CCT_WB_OFF = 0xFF
} FT_CCT_WB_SETTING;

typedef struct {
	FT_CCT_REG_TYPE			type;
	kal_uint32				device_id;
	kal_uint16				width;
	kal_uint16				height;
	FT_CCT_BAYER_PATTERN	start_pixel_bayer_ptn;
	kal_uint16				grab_x_offset;
	kal_uint16				grab_y_offset;
} FT_CCT_SENSOR;

typedef struct {
	FT_CCT_SENSOR			sensor[4];
	kal_uint8				sensor_count;
} FT_CCT_ON_BOARD_SENSOR;

typedef struct {
	FT_CCT_REG_TYPE			type;
	kal_uint32				device_id;
	kal_uint16				width;
	kal_uint16				height;
	kal_uint16				preview_width;
	kal_uint16				preview_height;
	FT_CCT_BAYER_PATTERN	start_pixel_bayer_ptn;
	kal_uint16				grab_x_offset;
	kal_uint16				grab_y_offset;
} FT_CCT_SENSOR_EX;

typedef struct {
	kal_uint32				sensor_count;
	FT_CCT_SENSOR_EX		sensor[4];
} FT_CCT_ON_BOARD_SENSOR_EX;

typedef struct {
	kal_uint16				color_temperature;
	kal_uint16				r_gain;
	kal_uint16				g_gain;
	kal_uint16				b_gain;
} FT_CCT_WHITE_BALANCE;

typedef struct {
	FT_CCT_WHITE_BALANCE	wb[5];
} FT_CCT_WHITE_BALANCE_ALL;

typedef struct {
	kal_uint32				reg_addr;
	kal_uint8				reg_len;
	kal_uint8				value_len;
} FT_CCT_REG_READ_REQ;

typedef struct {
	kal_uint32				value;
	kal_uint8				value_len;
} FT_CCT_REG_READ_CNF;

typedef struct {
	kal_uint32				reg_addr;
	kal_uint32				value;
	kal_uint8				reg_len;
	kal_uint8				value_len;
} FT_CCT_REG_WRITE_REQ;

typedef struct {
	kal_uint16				left_pos;
	kal_uint16				top_pos;
	kal_uint16				width;
	kal_uint16				height;
	kal_uint8				sub_sample;
	kal_uint8				output_format;
	FT_CCT_CAP_BUF_TYPE		buf_type;
} FT_CCT_CAPTURE_REQ;

typedef struct {
	kal_uint16				left_pos;
	kal_uint16				top_pos;
	kal_uint16				width;
	kal_uint16				height;
	kal_uint8				sub_sample;
	kal_uint8				output_format;
	FT_CCT_BAYER_PATTERN	bayer_ptn;
	kal_uint16				output_width;
	kal_uint16				output_height;
	kal_uint16				frame_num;
	kal_bool				last_frame;
} FT_CCT_CAPTURE_CNF;

typedef struct {
	kal_uint16				left_pos;
	kal_uint16				top_pos;
	kal_uint16				width;
	kal_uint16				height;
	kal_uint8				sub_sample;
	kal_uint8				output_format;
	FT_CCT_CAP_BUF_TYPE		buf_type;
	kal_bool				continue_shot;
} FT_CCT_CAPTURE_EX_REQ;

typedef struct {
	kal_uint16				left_pos;
	kal_uint16				top_pos;
	kal_uint16				width;
	kal_uint16				height;
	kal_uint8				sub_sample;
	kal_uint8				output_format;
	FT_CCT_BAYER_PATTERN	bayer_ptn;
	kal_uint16				output_width;
	kal_uint16				output_height;
	kal_uint32				capture_size;
	kal_bool				continue_shot;
} FT_CCT_CAPTURE_EX_CNF;

typedef struct {
	kal_uint32				offset;
	kal_uint32				length;
} FT_CCT_GET_CAPTURE_BUF_REQ;

typedef struct {
	kal_uint8				value;
	kal_uint8				ec_step;
	kal_int8				ec_level;
} FT_CCT_AE_SET_EXPOSE_LEVEL_REQ;

typedef struct {
	kal_uint8				value;
	kal_uint8				ec_step;
	kal_int8				ec_level;
} FT_CCT_AE_GET_EXPOSE_LEVEL_CNF;

typedef struct {
	kal_uint8				step;
} FT_CCT_AE_QUERY_EC_STEP_INFO_REQ;

typedef struct {
	kal_uint8				step;
	kal_uint8				total_level;
} FT_CCT_AE_QUERY_EC_STEP_INFO_CNF;

typedef struct {
	kal_uint8				status;
} FT_CCT_NVRAM_CNF;

typedef struct {
	FT_CCT_WB_SETTING		index;
} FT_CCT_WB_ACTIVATE_BY_INDEX_REQ;

typedef struct {
	FT_CCT_WB_SETTING		index;
	FT_CCT_WHITE_BALANCE	wb;
} FT_CCT_WB_SET_BY_INDEX_REQ;

typedef struct {
	FT_CCT_WB_SETTING		activated_index;
} FT_CCT_WB_QUERY_ALL_CNF;

typedef struct {
	kal_bool				no_confirm;
} FT_CCT_RESUME_PREVIEW_REQ;

typedef struct {
	kal_uint32				baseshutter_60hz;
	kal_uint32				baseshutter_50hz;
} FT_CCT_BANDING_FACTOR;

typedef struct {
	kal_int32				value;
	kal_int32				min;
	kal_int32				max;
	kal_bool				exist;
} FT_CCT_SensorEngModeItem;

typedef struct {
	FT_CCT_SensorEngModeItem	pregain_r;
	FT_CCT_SensorEngModeItem	pregain_gr;
	FT_CCT_SensorEngModeItem	pregain_gb;
	FT_CCT_SensorEngModeItem	pregain_b;
} FT_CCT_SENSOR_PREGAIN;

typedef struct {
	kal_bool					pregain_r_result;
	kal_bool					pregain_gr_result;
	kal_bool					pregain_gb_result;
	kal_bool					pregain_b_result;
} FT_CCT_SET_SENSOR_PREGAIN_CNF;

typedef struct {
	kal_bool					turn_on;
} FT_CCT_MAIN_LCD_BACKLIGHT_REQ;

typedef struct {
	kal_uint8					gamma[1024];
} FT_CCT_GAMMA_TABLE;

typedef struct {
	kal_char					group_name[64];
	kal_char					item_name[64];
} FT_CCT_SENSOR_ENG_KEY;

typedef enum {
	 FT_CCT_COMP_PREVIEW_NORMAL_SET = 0
	,FT_CCT_COMP_PREVIEW_LOWLIGHT_SET
	,FT_CCT_COMP_CAPTURE_NORMAL_SET
	,FT_CCT_COMP_CAPTURE_LOWLIGHT_SET
	,FT_CCT_COMP_CAPTURE_HALF_SET
} FT_CCT_COMP_SET_ENUM;

typedef struct {
	kal_bool						is_cal_result;
	defectpixel_result_struct		defectpixel;
} FT_CCT_DEFECT_TABLE;

typedef struct {
	kal_uint16						pregain_max;
	kal_uint16						pregain_min;
} sensor_info_struct;

/*
typedef struct {
	dsc_info_struct					dsc_info;
	sensor_info_struct				sensor_info;
} FT_CCT_DEV_DSC_INFO;
*/

typedef struct {
	kal_uint16						gain[3];
} FT_CCT_DEV_ISO_GAIN;
typedef struct {
	kal_uint16						value[3];
} FT_CCT_DEV_ISO_VALUE;
typedef struct {
	kal_uint8						select;
} FT_CCT_DEV_ISO_CAPTURE;
typedef struct {
	kal_bool						iris[AV_NO];//HAL
} FT_CCT_DEV_IRIS_INFO;

typedef struct {
	kal_uint32						shutter;
	kal_uint32						sensorgain;
	kal_uint32						ispgain;
} FT_CCT_DEV_AE_SET_VALUE_PARA;

typedef struct {
	kal_uint8						table_size;
	exposure_lut_struct				ae_table[256];
	kal_uint8						iris_table[256];
} FT_CCT_DEV_AE_TABLE;

typedef struct {
	device_info_struct				device_info;
	FT_CCT_DEV_AE_TABLE				ae_table;
} FT_CCT_DEV_AE_INFO;

typedef struct {
	kal_uint32		pos;
	kal_uint32		atf_value;
} FT_CCT_DEV_AF_CAL_RESULT;

typedef struct {
	kal_uint8		activate_af_table_index;
	kal_uint32		set_pos;
} FT_CCT_DEV_AF_PARA;

typedef struct {
	kal_uint32		curr_lum;
	kal_uint32		target_lum;
} FT_CCT_DEV_STROBE_CAL_PARA;

typedef struct {
    kal_uint16				start_idx;
    kal_uint16				end_idx;
    kal_uint32				timer_ms;
    FT_CCT_DEV_AE_TABLE		freerun_table;
} FT_CCT_DEV_AE_BYPASS_FREERUN_PARA;

typedef struct {
	kal_uint32				lum_info_size;
	kal_uint32				lum_info[256];
} FT_CCT_DEV_AE_BYPASS_FREERUN_RESULT;

typedef struct {
	kal_uint16				width;
	kal_uint16				height;
	kal_uint16				preview_width;
	kal_uint16				preview_height;
} FT_CCT_DEV_MODE_SIZE;
//#if (defined(DRV_ISP_6238_SERIES)) //HAL remove
#if 0 //HAL
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct{
	kal_uint32 windowWhitPoint[12];
}awbWindowWhitPointArray;

typedef struct{
	kal_uint8 lightSourceMode;
	cct_ccm_matrix_struct nvram_ccm;
}awbNvramCCMReq;

typedef struct{
	kal_uint8		mode;
	kal_uint32	offset;
	kal_uint32	length;
	kal_uint32	buffer[100];
}ispPartialShadingTable;

typedef struct{
	kal_uint8		mode;
	kal_uint8		m_switch;
}ispShadingStatusMsg;
typedef struct{
	kal_uint8	value[7];   // NR1, NR2, EDGE, SATURATION, CONTRAST, AUTODEFECT, AUTOSHADING
}ispTuningSettingIndexValue;
typedef struct{
	kal_uint8 enableFlag;
	flashlight_cdt_ae_para_struct aePara; // danbo opened for ft_cct_6238_isp_flashlight_set_ae_para_2
}ispFlashAePara;
typedef struct {
	kal_uint16 lut_trigger_time[20];
	kal_uint16 lut_result_time[20];
}xenon_duration_lut_struct;
//#endif
//---------TEST-----------------
typedef struct{
	kal_uint8  mode;
	kal_uint32 offset;
	kal_uint32 length;
}ispDefectPara;

typedef struct{
	kal_uint8  mode;
	kal_uint32 offset;
	kal_uint32 length;
}ispShadingPara;

typedef struct{
	kal_uint32 data[400];
}ispTable;
typedef struct{
	kal_uint8 data[400];
}ispPCATable;
//------------------------------
typedef enum
{
	CCT_MAIN_SENSOR,
	CCT_SUB_SENSOR
}FT_CCT_SENSOR_TYPE__ENUM;


typedef struct {
	kal_char	lid_name[64];
	kal_char	struct_name[64];
	kal_char	var_name[64];
}camera_para_struct;

#if defined(DRV_ISP_PCA_SUPPORT)
typedef struct{
	camera_para_struct table[7];	// threre are 7 camera LID( +PCA)
}camera_para_table_struct;
#else
typedef struct{
	camera_para_struct table[6];	// threre are six camera LID
}camera_para_table_struct;
#endif

typedef struct{
	kal_char sensor_prefix_name[64];
}camera_sensor_prefix_name_struct;

typedef struct{
	kal_char lens_prefix_name[64];
}camera_lens_prefix_name_struct;
typedef struct{
	kal_uint8  mode;
	kal_uint8  color_temperature;
	kal_uint32 offset;
	kal_uint32 length;	
}ispShadingParaV3;
typedef struct {
	kal_uint8  color_temperature;
	kal_uint8  channel;
	kal_uint32 offset;
	kal_uint32 length;	
}ispPCATblPara;

typedef struct{
	kal_uint8 pca_en;
	kal_uint8 chroma_lo;
	kal_uint8 chroma_md;
	kal_uint8 chroma_hi;
}ispPCApara;

typedef enum {
    PCA_TABLE_1 = 1, 
	ASD_PCA_TABLE_2, 
}PCA_TABLE_ENUM;


// danbo add for FT_CCT_OP_GET_ENG_SENSOR_PARA
typedef struct
{
   kal_uint8   item_name_ptr[50];		  // item name
   kal_int32	item_value; 			   // item value
   kal_bool    is_true_false;			  // is this item for enable/disable functions
   kal_bool    is_read_only;			  // is this item read only
   kal_bool    is_need_restart; 		  // after set this item need restart
   kal_int32	min;					   // min value of item value	
   kal_int32	max;					   // max value of item value	
} ENG_sensor_info;

//danbo add for CCT Tools
// ISP Change ShadingPara Struct Item use Uint32,but CCT use this Struct
typedef struct
{
    kal_uint8 SDBLK_TRIG;
    kal_uint8 SHADING_EN;
    kal_uint8 SHADINGBLK_XOFFSET;
    kal_uint8 SHADINGBLK_YOFFSET;
    kal_uint8 SHADINGBLK_XNUM;
    kal_uint8 SHADINGBLK_YNUM;
    kal_uint16 SHADINGBLK_WIDTH;
    kal_uint16 SHADINGBLK_HEIGHT;
    kal_uint32 SHADING_RADDR;
    kal_uint16 SD_LWIDTH;
    kal_uint16 SD_LHEIGHT;
    kal_uint8 SDBLK_RATIO00;
    kal_uint8 SDBLK_RATIO01;
    kal_uint8 SDBLK_RATIO10;
    kal_uint8 SDBLK_RATIO11;
    kal_uint16 SD_TABLE_SIZE;
    //kal_uint32 SD_TABLE[MAX_SHADING_TABLE_SIZE];
}cct_shading_comp_tool_struct;

// danbo add for cdt tools 110412
typedef struct {
	camcorder_info_struct					dsc_info;
	sensor_info_struct				sensor_info;
} FT_CCT_DEV_DSC_INFO;


typedef union {
	FT_CCT_REG_READ_REQ					reg_read;
	FT_CCT_REG_WRITE_REQ				reg_write;
	FT_CCT_CAPTURE_REQ					capture;
	FT_CCT_AE_SET_EXPOSE_LEVEL_REQ		ae_expose;
	FT_CCT_AE_QUERY_EC_STEP_INFO_REQ	ae_ec_step;
	FT_CCT_WB_ACTIVATE_BY_INDEX_REQ		wb_activate;
	FT_CCT_WB_SET_BY_INDEX_REQ			wb_set;
	kal_uint16							ae_init_shutter;
	kal_uint16							ae_manual_shutter;
	FT_CCT_CAPTURE_EX_REQ				capture_ex;
	FT_CCT_GET_CAPTURE_BUF_REQ			get_capture_buf;
	FT_CCT_RESUME_PREVIEW_REQ			resume_preview;
	FT_CCT_SENSOR_PREGAIN				set_sensor_pregain;
	FT_CCT_MAIN_LCD_BACKLIGHT_REQ		main_lcd_backlight;
	kal_uint16							cal_nvram_lid;
	kal_int32							set_eng_sensor_para;
	FT_CCT_COMP_SET_ENUM				set_compensation_mode;
	
	//cct_shading_comp_struct				set_shading_para;//danbo change for cct_shading_comp_tool_struct
	                                                   //because ISP use Uint32  but tools use Unit8,Unit16 and Unit32.
	cct_shading_comp_tool_struct		set_shading_para;
	
	cct_autodefect_comp_struct			set_autodefect_para;
	kal_uint16							set_capture_data_tunnel;
	defectpixel_para_struct				defect_table_cal_para;
	FT_CCT_DEV_IRIS_INFO				dev_set_iris_info;
	FT_CCT_DEV_AF_PARA					dev_af_para;
	FT_CCT_DEV_STROBE_CAL_PARA			dev_strobe_cal_para;
	kal_bool							on_off;
	AF_OQC_cal_struct					lens_offset_cal_para;
	camera_ae_period_para_struct		set_ae_period_para;
	FT_CCT_DEV_AE_SET_VALUE_PARA		dev_ae_set_value_para;
	kal_uint8							dev_ae_set_table_index;
	ae_lut_info_struct					dev_ae_set_scene_mode;
	FT_CCT_DEV_ISO_GAIN					dev_set_iso_gain;
	FT_CCT_DEV_ISO_CAPTURE				dev_set_iso_capture;
	FT_CCT_DEV_ISO_VALUE				dev_set_iso_value;
	flashlight_cdt_charge_struct		dev_flashlight_charge;
	flashlight_cdt_strobe_struct		dev_flashlight_strobe;
	flashlight_cdt_capture_struct       dev_flashlight_capture;
	kal_uint32							flash_charge_level;
//#if (defined(DRV_ISP_6238_SERIES))
	kal_uint8						dev_6238_ae_scene_mode;
	kal_uint8						dev_6238_ae_metering_mode;
	aeCctApplyExpoInfoStruct		dev_6238_ae_expo_info_eq;
	aeCctExpoSettingStruct			dev_6238_ae_auto_expo_para;
	aeIsoLutStruct					dev_6238_ae_iso_value_gain;
	aeFlareSettingStruct			dev_6238_ae_flare_para;
	aeCctMeteringSettingStruct		dev_6238_ae_metering_mode_setting;
	/*aeUpdateSmoothModeStruct*/void*		dev_6238_ae_smooth_mode_setting;
	kal_uint8						dev_6238_ae_select_band;
	cct_awb_gain_struct			dev_6238_awb_set_gain;
	cct_awb_preference_struct 		dev_6238_awb_set_pref_factor;
	kal_uint8						dev_6238_awb_light_source_mode;
	awbNvramCCMReq				dev_6238_awb_nvram_ccm;
	/*ccm_para_struct*/void* 				dev_6238_awb_cmm_para;
	cct_awb_status_struct 		dev_6238_awb_awb_status;
	cct_ccm_status_struct 		dev_6238_awb_ccm_status;	
	kal_uint32					dev_6238_awb_small_box_light_source;
	cct_ccm_matrix_struct			dev_6238_awb_current_ccm;
	CCT_LIGHT_SOURCE_ENUM		dev_6238_awb_cct_light_source;
	cct_shading_comp_struct		dev_6238_isp_set_shading_para;	
	ispShadingStatusMsg			dev_6238_isp_shading_status;
	kal_uint8									dev_6238_ae_gamma_bypass;
	ispTuningSettingIndexValue		dev_6238_isp_tuning_setting_index_value;
 	flashlight_cdt_capture_struct		dev_6238_isp_flashlight_cdt_capture;
	ispFlashAePara				dev_6238_isp_flashlight_set_ae_para;
	xenon_duration_lut_struct		dev_6238_flash_duration_lut;
	kal_uint32						dev_6238_shutter_mode;
	kal_uint32					dev_6238_shutter_target_time;
	kal_uint32					dev_6238_shutter_delay_time;
	kal_uint32					dev_6238_shutter_target_time_for_preview_target_lines;
	ispDefectPara					dev_6238_isp_defect_para;
	ispShadingPara				dev_6238_isp_shading_para;
	ispShadingParaV3				dev_6238_isp_shading_para_v3;
	ispPCATblPara					dev_6238_isp_PCA_tbl_para;
	ispPCApara					dev_6238_isp_PCA_para;
	T_CCMMode					dev_6238_ccm_mode;
//#endif
	kal_uint8						dev_dual_isp_set_camera_type;	// [delete]
	PCA_TABLE_ENUM              dev_isp_PCA_Index;
	kal_uint32	dummy;
} FT_CCT_CMD;

typedef union {
	FT_CCT_REG_READ_CNF					reg_read;
	FT_CCT_CAPTURE_CNF					capture;
	FT_CCT_NVRAM_CNF					nvram;
	FT_CCT_AE_GET_EXPOSE_LEVEL_CNF		ae_expose;
	FT_CCT_AE_QUERY_EC_STEP_INFO_CNF	ae_ec_step;
	FT_CCT_WB_QUERY_ALL_CNF				wb_query_all;
	kal_uint16							ae_init_shutter;
	kal_uint16							ae_manual_shutter;
	FT_CCT_CAPTURE_EX_CNF				capture_ex;
	FT_CCT_BANDING_FACTOR				get_banding_factor;
	FT_CCT_SENSOR_PREGAIN				get_sensor_pregain;
	FT_CCT_SET_SENSOR_PREGAIN_CNF		set_sensor_pregain;
	kal_uint32							isp_id;
	FT_CCT_SensorEngModeItem			get_eng_sensor_para;
	FT_CCT_COMP_SET_ENUM				get_compensation_mode;
	
	//cct_shading_comp_struct				get_shading_para; //danbo change for  cct_shading_comp_tool_struct
	                                                   //because ISP use Uint32  but tools use Unit8,Unit16 and Unit32.
	cct_shading_comp_tool_struct				get_shading_para;
	
	cct_autodefect_comp_struct			get_autodefect_para;
	kal_uint16							get_last_compensation_mode;
	kal_uint16							get_autodefect_count;
	defectpixel_para_struct				defect_table_cal_para;
	FT_CCT_DEV_IRIS_INFO				dev_get_iris_info;
	FT_CCT_DEV_AF_CAL_RESULT			dev_af_cal_result;
	kal_uint8							lens_offset_cal_return_code;
	camera_ae_period_para_struct		get_ae_period_para;
	kal_bool							on_off;
	FT_CCT_DEV_ISO_GAIN					dev_get_iso_gain;
	FT_CCT_DEV_ISO_VALUE				dev_get_iso_value;
	FT_CCT_DEV_MODE_SIZE				mode_size;
	kal_uint8							flash_type;
	exposure_lut_struct					flash_lut;
	kal_uint32							flash_charge_level;
	kal_uint32							flash_charge_timeout;
	kal_uint8							ae_index;
//#if (defined(DRV_ISP_6238_SERIES))
	aeCctCurrentExpoInfoStruct			get_6238_ae_current_expo_info_cnf;
	aeCctExpoSettingStruct				get_6238_ae_auto_expo_para;
	aeIsoLutStruct						get_6238_ae_iso_value_gain;
	aeFlareSettingStruct				get_6238_ae_flare_para;
	aeFlareHistogram					get_6238_ae_flare_histogram;
	aeCctCurrentMeteringResultStruct 	get_6238_ae_metering_result;
	aeCctMeteringSettingStruct			get_6238_ae_metering_mode_setting;
	/*aeSmoothModeStruct*/void*				get_6238_ae_smooth_mode_setting;
	aeOutputCurrentAeInfo				get_6238_ae_preview_expo_info;
	aeGammaTableStruct				get_6238_ae_gamma_table;
	awbWindowWhitPointArray			get_6238_awb_window_whit_point;
	kal_uint32						get_6238_awb_light_mode;
	cct_awb_gain_struct 				get_6238_awb_gain;
	cct_awb_preference_struct			get_6238_awb_pref_factor;
	cct_ccm_matrix_struct				get_6238_awb_current_ccm;
	cct_ccm_matrix_struct				get_6238_awb_nvram_ccm;
	/*ccm_para_struct*/void* 					get_6238_awb_cmm_para;
	cct_awb_status_struct 			get_6238_awb_awb_status;
	cct_ccm_status_struct 			get_6238_awb_cmm_status;
	cct_shading_comp_struct			get_6238_isp_shading_para;
	ispShadingStatusMsg				get_6238_isp_shading_status;
	kal_uint8								get_6238_ae_scene_mode;
	kal_uint8								get_6238_ae_metering_mode;
	kal_uint8								get_6238_ae_band;
	kal_uint8								get_6283_ae_gamma_bypass_flag;
	ispTuningSettingIndexValue			get_6238_isp_tuning_setting_index_value;
	kal_uint32							get_6238_isp_ae_total_gain;
	kal_uint8							get_6238_isp_dynamic_bypass_mode_on_off;
	kal_uint8							get_6238_isp_binning_mode;
	flashlight_cdt_ae_para_struct	get_6238_isp_flashlight_cdt_capture;//HAL 
	camcorder_info_struct			get_6238_isp_dev_camcorder_info;
	kal_uint32					get_6238_shutter_g_channel_mean;
	kal_uint32					get_6238_shutter_delay_time;
	kal_uint32					get_6238_shutter_target_time;
	//CAMERA_CAPTURE_EXP_ENUM	get_6238_shutter_mode; //HAL
	kal_uint32					get_6238_shutter_target_lines;
	ispDefectPara					get_6238_isp_defect_table_para;
	ispShadingPara				get_6238_isp_shading_table_para;
	ispShadingParaV3				get_6238_isp_shading_table_para_v3;	
	ispPCATblPara					get_6238_isp_PCA_tbl_para;
	ispPCApara					get_6238_isp_PCA_para;
	kal_bool						get_6238_PCA_is_supported;
	T_CCMMode						get_6238_ccm_mode;
//#endif
	kal_uint32						get_dual_valid_camera_type;	
	camera_sensor_prefix_name_struct	get_dual_sensor_prefix_name;
	camera_lens_prefix_name_struct		get_dual_lens_prefix_name;
	kal_bool						get_6238_is_supported;
	PCA_TABLE_ENUM                dev_isp_PCA_Index;
	kal_uint32	dummy;
} FT_CCT_RESULT;

typedef struct {
	FT_H				header;
	FT_CCT_OP			op;
	FT_CCT_REG_TYPE		type;
	kal_uint32			device_id;
	FT_CCT_CMD			cmd;
} FT_CCT_REQ;

typedef struct {
	FT_H				header;
	FT_CCT_OP			op;
	kal_uint8			status;
	FT_CCT_RESULT		result;
} FT_CCT_CNF;

//------------------------------------------------------------------------------
// CCT state machine global variable                                            
//------------------------------------------------------------------------------

typedef struct {

	kal_bool	is_init;
	kal_uint8	cnf_return_code;

	// memory management 
	kal_uint32	mem_lcd_layer0_buf_addr;
	kal_uint32	mem_lcd_layer0_buf_size;
	kal_uint32	mem_isp_int_buf_addr;
	kal_uint32	mem_isp_int_buf_size;
	kal_uint32	mem_isp_ext_buf_addr;
	kal_uint32	mem_isp_ext_buf_size;
	kal_uint32	mem_capture_ext_buf_addr;
	kal_uint32	mem_capture_ext_buf_size;
	kal_uint32	mem_capture_int_buf_addr;
	kal_uint32	mem_capture_int_buf_size;
	kal_uint32	mem_capture_cur_buf_addr;
	kal_uint32	mem_capture_cur_buf_size;
	kal_uint32	mem_capture_ext_exif_addr;
	kal_uint32	mem_capture_ext_exif_size;

	// sensor info 
	FT_CCT_ON_BOARD_SENSOR_EX	sensor_onboard_sensors;
	// sensor engineer mode state 
	kal_int16					sensor_eng_group_idx;
	kal_int16					sensor_eng_item_idx_pregain_R;
	kal_int16					sensor_eng_item_idx_pregain_Gr;
	kal_int16					sensor_eng_item_idx_pregain_Gb;
	kal_int16					sensor_eng_item_idx_pregain_B;

	// preview state 
	const FT_CCT_SENSOR_EX	*	p_preview_sensor;

	// AE state 
	kal_bool					ae_enable;

	// WB state 
	FT_CCT_WB_SETTING			wb_activated_idx;

	// AF state 
	kal_bool					af_on_off;
	kal_bool					af_done;
	kal_bool					af_lens_offset_cal;

	// compensation mode state 
	FT_CCT_COMP_SET_ENUM		comp_mode;

	// defect table calibration state 
	kal_bool					defect_table_on_off;
	kal_bool					defect_table_cal_in_progress;

	// strobe calibration state 
	kal_bool					strobe_cal_enable;
	FT_CCT_DEV_STROBE_CAL_PARA	strobe_cal_para;

	// capture jpeg state 
	FT_CCT_CAPTURE_JPEG_STATE_E	capture_jpeg_state;

	// USB data tunnel state 
	kal_bool					usb_ready;
	FT_CCT_DATA_TUNNEL_E		usb_capture_data_tunnel;
	FT_CCT_USB_TUNNEL_STATE_E	usb_tunnel_state;
	kal_uint32					usb_ready_to_write_cnt;

	// dev tool scene mode 
	ae_lut_info_struct			dev_ae_scene_mode;	

	kal_bool					gamma_bypass; //danbo add

	// debug 
	FT_CCT_REQ		debug_last_req;
	FT_CCT_CNF		debug_last_cnf;

} FT_CCT_STATE_MACHINE;

#else//YUV support [Dana]
typedef struct {
	kal_uint32	dummy;
} FT_CCT_REQ;
#endif

//#if 0
//extern FT_CCT_STATE_MACHINE g_FT_CCT_StateMachine;
//-----------------------------------------------------------------------------
//
// CCT functionality
//
//-----------------------------------------------------------------------------

#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))//aviod smart phone moden build error
//#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))
//#if (!defined(MT6219))
kal_uint8 convert_defect_table_err_code(kal_int32 err_code) ;
kal_uint8  ft_cct_defect_table_verify_block_factor(const FT_CCT_REQ *req, FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_defect_table_calibration(const FT_CCT_REQ *req) ;
kal_uint8  ft_cct_get_defect_table(FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret);
kal_uint8  ft_cct_set_defect_table(FT_CCT_CNF *cnf, const defectpixel_result_struct  *p_defect_pixel_list);
kal_uint8  ft_cct_dev_get_dsc_info(peer_buff_struct **pp_peer_buff_ret);
kal_uint8  ft_cct_dev_get_iris_info(FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_dev_set_iris_info(const FT_CCT_REQ *req);
kal_uint8  ft_cct_dev_get_iso_gain(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_dev_set_iso_gain(const FT_CCT_REQ *req);
kal_uint8  ft_cct_dev_get_iso_value(FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_dev_set_iso_value(const FT_CCT_REQ *req);
kal_uint8  ft_cct_dev_get_iso_gain_cct(FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_dev_set_iso_gain_cct(const FT_CCT_REQ *req);
kal_uint8  ft_cct_dev_get_iso_value_cct(FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_dev_set_iso_value_cct(const FT_CCT_REQ *req);
kal_uint8  ft_cct_dev_is_support_iso(void) ;
kal_uint8  ft_cct_dev_recover_iso_capture(void);
kal_uint8  ft_cct_dev_set_iso_capture(const FT_CCT_REQ *req) ;
kal_uint8  ft_cct_dev_ae_get_info(peer_buff_struct **pp_peer_buff_ret);
kal_uint8  ft_cct_dev_ae_set_table_index(const FT_CCT_REQ *req);
kal_uint8  ft_cct_dev_ae_set_value(const FT_CCT_REQ *req) ;
kal_uint8  ft_cct_dev_af_get_table(peer_buff_struct **pp_peer_buff_ret);
kal_uint8  ft_cct_dev_af_calibration(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_dev_af_set_table_index(const FT_CCT_REQ *req);
kal_uint8  ft_cct_dev_af_set_pos(const FT_CCT_REQ *req) ;
kal_uint8  ft_cct_dev_strobe_calibration_enable(void);
kal_uint8  ft_cct_dev_strobe_calibration_set_para(const FT_CCT_REQ *req);
kal_uint8  ft_cct_dev_strobe_calibration_disable(void);
kal_uint8  ft_cct_defect_table_on_off(kal_bool  bOn);
kal_uint8  ft_cct_defect_table_bypass_and_backup_setting(void);
kal_uint8  ft_cct_defect_table_restore_setting(void);
kal_uint8  ft_cct_ae_get_period_para(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_get_flash_level(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_set_flash_level(const FT_CCT_REQ *req);
kal_uint8  ft_cct_dev_flashlight_type(FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_get_flash_ae_index(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_ae_set_period_para(const FT_CCT_REQ *req);
kal_uint8  ft_cct_dev_ae_bypass_freerun(const FT_CCT_DEV_AE_BYPASS_FREERUN_PARA  *req, peer_buff_struct **pp_peer_buff_ret);
kal_uint8  ft_cct_dev_ae_set_scene_mode(const FT_CCT_REQ *req);

kal_uint8  ft_cct_flashlight_charge(const FT_CCT_REQ *req,FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_flashlight_strobe(const FT_CCT_REQ *req) ;
kal_uint8  ft_cct_flashlight_capture(const FT_CCT_REQ *req, FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_set_flash_ae_index(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8  ft_cct_dev_mode_size(FT_CCT_CNF *cnf);
//#endif  // #if (!defined(MT6219))

kal_uint8 ft_cct_check_op_is_support(kal_uint32 query_op_code); 
void ft_cct_usb_communication(ilm_struct* ptrMsg);
kal_uint8  FT_CCT_SendCnf(const FT_CCT_CNF  *cnf, peer_buff_struct *peer_buff) ;
void ft_cct_adjust_capture_buf(kal_uint32  *pBufAddr, kal_uint32  *pBufSize) ;
//void ft_cct_init(void);
kal_uint8 ft_cct_init(void);
const FT_CCT_SENSOR_EX * get_sensor_by_id(const FT_CCT_REG_TYPE  type, const kal_uint32  device_id);
kal_uint8  ft_cct_reg_read(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8  ft_cct_reg_write(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8  ft_cct_preview_on_lcd_enable(const FT_CCT_SENSOR_EX  *sensor, kal_bool enable_flag);
void ft_cct_set_final_grab_xy_width_height(kal_int16  *p_grab_left_pos, kal_int16  *p_grab_top_pos, kal_int16  *p_grab_width, kal_int16  *p_grab_height, kal_uint8	output_format);
kal_uint8  ft_cct_query_sensor(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret) ;
kal_uint8  ft_cct_load_from_nvram(kal_uint8  *p_nvram_cnf_status, kal_bool  apply_to_reg);
kal_uint8  ft_cct_save_to_nvram(kal_uint8  *p_nvram_cnf_status) ;
kal_uint8  ft_cct_ae_enable(kal_bool	enable);
kal_uint8  ft_cct_ae_set_expose_level(const FT_CCT_REQ *req) ;
kal_uint8  ft_cct_ae_get_expose_level(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8  ft_cct_ae_query_ec_step_info(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8  ft_cct_ae_set_init_shutter(kal_uint16  init_shutter);
kal_uint8  ft_cct_ae_get_init_shutter(kal_uint16  *p_init_shutter);
kal_uint8  ft_cct_wb_activate_by_index(const FT_CCT_WB_SETTING  activate_index);
kal_uint8  ft_cct_wb_set_by_index(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8  ft_cct_wb_query_all(FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret);
kal_uint8  ft_cct_ae_set_manual_shutter(const FT_CCT_REQ *req);
kal_uint8  ft_cct_ae_get_manual_shutter(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_get_camera_para_buf(peer_buff_struct **pp_peer_buff_ret);
kal_uint8  ft_cct_suspend_ae_awb_preview_during_capture(kal_bool  bSuspend);
static kal_uint8 ft_cct_convert_capture_format_enum(kal_uint8  format);
//kal_uint8  ft_cct_capture_ex(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, kal_bool  bMultiShot);
kal_uint8  ft_cct_capture_ex(const FT_CCT_REQ *req, FT_CCT_CNF *cnf); //danbo Change  for fix  Warning 110401
kal_uint8  ft_cct_get_capture_buf(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret);
kal_uint8  ft_cct_get_banding_factor(FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_get_sensor_pregain(FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_set_sensor_pregain(const FT_CCT_REQ *req, FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_main_lcd_backlight_setting(const FT_CCT_REQ *req);
kal_uint8  ft_cct_get_gamma_table(FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret) ;
kal_uint8  ft_cct_set_gamma_table(FT_CCT_GAMMA_TABLE  *gamma_tbl);
kal_uint8  ft_cct_query_isp_id(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_get_calibration_struct_buf(kal_uint32	nvram_lid, peer_buff_struct **pp_peer_buff_ret);
kal_uint8  ft_cct_get_eng_sensor_para(const kal_char *group_id, const kal_char *item_id, FT_CCT_CNF *cnf);
kal_uint8  ft_cct_set_eng_sensor_para(const kal_char *group_id, const kal_char *item_id, const FT_CCT_REQ *req);
kal_uint8  ft_cct_get_compensation_mode(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_set_compensation_mode(const FT_CCT_REQ *req);
kal_uint8  ft_cct_get_shading_para(FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_set_shading_para(const FT_CCT_REQ *req) ;
kal_uint8  ft_cct_get_autodefect_para(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_set_autodefect_para(const FT_CCT_REQ *req);
kal_uint8  ft_cct_get_last_compensation_mode(FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_get_autodefect_count(FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_usb_tunnel_cancel(void) ;
void  ft_cct_usb_tunnel_send(kal_bool bReset) ;
kal_uint8  ft_cct_set_capture_data_tunnel(const FT_CCT_REQ *req) ;
kal_uint8  ft_cct_enable_usbcom(void);
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT))) // danbo add for build warning
kal_uint8  ft_cct_af_trigger(void);
#endif
kal_uint8  ft_cct_af_release(void);
kal_uint8  ft_cct_af_on_off(kal_bool  bOn);
kal_uint8  ft_cct_af_lens_offset_cal(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8  ft_cct_get_gamma_table_on_off_flag(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_set_gamma_table_on_off_flag(const kal_bool bOnOff);
kal_uint8  ft_cct_get_gamma_on_off_flag(FT_CCT_CNF *cnf) ;
kal_uint8  ft_cct_set_gamma_on_off_flag(const kal_bool bOnOff);
//------------------------------------------------------------------------------
// kghost: test     calculate array function
//------------------------------------------------------------------------------
kal_uint8  ft_cct_calculate_array(const FT_CCT_REQ *req, FT_CCT_CNF *cnf) ;
//------------------------------------------------------------------------------
// dan: test  	dan command related function
//------------------------------------------------------------------------------
kal_uint8 ft_cct_dan_cmd_1(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8 ft_cct_dan_cmd_2(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8 ft_cct_dan_cmd_3(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8 dan_echo_on(kal_bool flag);
kal_uint8 dan_variation_on(kal_bool flag);
kal_uint8 ft_cct_dan_cmd_4(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8 ft_cct_dan_cmd_5(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
//--------------------------------------------------------------------
//
//    CCT Operation
//
//--------------------------------------------------------------------
void FT_CCT_Operation(const FT_CCT_REQ *req, peer_buff_struct *peer_buff_in);
//------------------------------------------------------------------------------
// ISP HISR callback                                                            
//------------------------------------------------------------------------------
void ft_cct_isp_hisr_preview_ae_awb_callback(kal_uint8 cause);
void ft_cct_isp_hisr_preview_autofocus_callback(kal_uint8 cause);
void ft_cct_isp_hisr_capture_jpeg_result(kal_uint8  return_code) ;
//------------------------------------------------------------------------------
// process function by ISP HISR's indication                                    
//------------------------------------------------------------------------------
void ft_cct_proc_ae_awb(void) ;

kal_uint32 ft_cct_read_sensor_id_from_nvram_tag(FT_CCT_SENSOR_TYPE__ENUM sensor_type);
kal_uint8 ft_cct_detect_sensor_id(void);
kal_bool ft_cct_get_camera_YUV_support(void);
//-----------------------------------------------------------------------------
//	[TH]   CCT 6238 AE API
//-----------------------------------------------------------------------------
kal_uint8 ft_cct_preview_start(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, const FT_CCT_SENSOR_EX **sensor);
kal_uint8 ft_cct_preview_stop(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, const FT_CCT_SENSOR_EX **sensor);
/*
#if (!defined(DRV_ISP_6238_SERIES))
kal_uint8 ft_cct_init_environment(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct *peer_buff_in, peer_buff_struct **peer_buff_ret,  kal_char **pdu_ptr, kal_uint16 *pdu_length  );
kal_uint8 ft_cct_send_back_confirm_message(const FT_CCT_REQ *req,FT_CCT_CNF *cnf, peer_buff_struct* peer_buff_ret);
kal_uint8 ft_cct_send_captured_data_by_usb(const FT_CCT_REQ *req,FT_CCT_CNF *cnf);
#else
*/
kal_uint8 ft_cct_6238_init_environment(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct *peer_buff_in, peer_buff_struct **peer_buff_ret,  kal_char **pdu_ptr, kal_uint16 *pdu_length);
kal_uint8 ft_cct_6238_send_back_confirm_message(const FT_CCT_REQ *req,FT_CCT_CNF *cnf, peer_buff_struct* peer_buff_ret);
kal_uint8 ft_cct_6238_send_captured_data_by_usb(const FT_CCT_REQ *req,FT_CCT_CNF *cnf);
kal_uint8  ft_cct_6238_ae_enable(kal_bool enable);
kal_uint8 ft_cct_6238_ae_set_scene_mode(kal_uint8 scene_mode);
kal_uint8 ft_cct_6238_ae_set_metering_mode(kal_uint8 mode);
kal_uint8 ft_cct_6238_ae_get_current_expo_info(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_ae_apply_expo_info(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_ae_select_band(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_ae_get_auto_expo_para(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_ae_get_iso_value_gain(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_ae_get_gamma_para(FT_CCT_CNF* cnf);
kal_uint8 ft_cct_6238_ae_get_flare_para(FT_CCT_CNF* cnf);
kal_uint8 ft_cct_6238_ae_update_auto_expo_para(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_ae_update_iso_value_gain(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_ae_update_gamma_para(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_ae_update_flare_para(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_ae_get_flare_histogram( FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_ae_get_metering_result( FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_ae_get_metering_mode_setting( FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_ae_update_metering_mode_setting( const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_ae_get_window_histogram( FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_ae_get_smooth_mode_setting( const FT_CCT_REQ *req,  FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_ae_update_smooth_mode_setting(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_ae_enable_preview_log(kal_bool enable);
kal_uint8 ft_cct_6238_ae_get_preview_expo_info(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_ae_get_gamma_table(FT_CCT_CNF *cnf);

//-----------------------------------------------------------------------------
//	[TH]   CCT 6238 AWB API
//-----------------------------------------------------------------------------
kal_uint8 ft_cct_6238_awb_enable_pref_gain(kal_bool enable);
kal_uint8 ft_cct_6238_awb_enable_fast_converge(kal_bool enable);
kal_uint8 ft_cct_6238_awb_enable_auto_run(kal_bool enable);
kal_uint8 ft_cct_6238_awb_enable(kal_bool enable);
kal_uint8 ft_cct_6238_awb_enable_small_box(const FT_CCT_REQ *req, kal_bool enable);
kal_uint8 ft_cct_6238_awb_get_window_whit_point_count_array( FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_awb_get_light_mode(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_awb_get_gain(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_awb_set_gain(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_awb_set_pref_factor(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_awb_get_pref_factor(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_awb_enable_dynamic_ccm(kal_bool enable);
kal_uint8 ft_cct_6238_awb_get_current_ccm(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_awb_set_current_ccm(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_awb_enable_flash_sync(kal_bool enable);
kal_uint8 ft_cct_6238_awb_apply_camera_para2_to_reg(void);
kal_uint8 ft_cct_6238_awb_update_camera_para2_from_req(void);
kal_uint8 ft_cct_6238_awb_get_nvram_ccm(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_awb_set_nvram_ccm(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_awb_get_awb_para(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_awb_get_ccm_para(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_awb_update_awb_para(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_awb_update_ccm_para(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_awb_get_awb_status(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_awb_get_ccm_status(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_awb_update_awb_status(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_awb_update_ccm_status(const FT_CCT_REQ *req);	
kal_uint8  ft_cct_6238_isp_get_shading_para(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_6238_isp_set_shading_para(const FT_CCT_REQ *req);
//----------------------ISP-------------------------------------------------
kal_uint8 ft_cct_6238_isp_enable_dynamic_bypass_mode(kal_bool enable);
kal_uint8  ft_cct_6238_isp_get_tuning_para(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_isp_set_tuning_para(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_isp_get_partial_shading_table(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_isp_set_partial_shading_table(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_isp_set_shading_on_off(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_isp_get_shading_on_off(const FT_CCT_REQ *req, FT_CCT_CNF *cnf);
//----------------------------------------------
kal_uint8 ft_cct_6238_ae_get_scene_mode(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_ae_get_metering_mode(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_ae_get_band(FT_CCT_CNF *cnf);	
kal_uint8 ft_cct_6238_ae_set_gamma_bypass(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_ae_get_gamma_bypass_flag(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_isp_set_tuning_index(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_isp_get_tuning_index(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_isp_get_ae_total_gain(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_isp_get_dynamic_bypass_mode_on_off(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_isp_set_shading_table_V3(const FT_CCT_REQ *req, ispTable *p_shading_table);
kal_uint8 ft_cct_6238_isp_get_shading_table_V3(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret);
//---------------------------PCA----------------------------------------
kal_uint8 ft_cct_6238_isp_set_pca_table(const FT_CCT_REQ *req, ispPCATable *p_shading_table);
kal_uint8 ft_cct_6238_isp_get_pca_table(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret);
kal_uint8  ft_cct_get_pca_para(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_set_pca_para(const FT_CCT_REQ *req) ;

kal_uint8 ft_cct_6238_isp_flash_linearity_prestrobe(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_isp_flash_linearity_result(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_isp_set_binning_mode(kal_bool en);
kal_uint8 ft_cct_6238_isp_get_binning_mode(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_isp_flashlight_set_ae_para_2(const FT_CCT_REQ *req);
kal_uint8  ft_cct_6238_af_get_para(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_6238_af_set_para(const FT_CCT_REQ *req);
kal_uint8  ft_cct_6238_isp_flashlight_get_ae_para_2(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_6238_isp_get_camcorder_info(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_isp_bypass_shading_mode(kal_bool en);
kal_uint8  ft_cct_6238_flash_duration_lut(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_isp_flash_linearity_results(peer_buff_struct **pp_peer_buff_ret);
kal_uint8 ft_cct_6238_isp_defect_table_enable(kal_bool en);
kal_uint8 ft_cct_6238_isp_set_defect_table(const FT_CCT_REQ *req,  ispTable *p_defect_table);
kal_uint8 ft_cct_6238_isp_get_defect_table(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_re);
kal_uint8 ft_cct_6238_isp_get_shading_table(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret);
kal_uint8 ft_cct_6238_isp_set_shading_table(const FT_CCT_REQ *req, ispTable *p_shading_table);
kal_uint8 ft_cct_6238_isp_get_shading_table_V3(const FT_CCT_REQ *req, FT_CCT_CNF *cnf, peer_buff_struct **pp_peer_buff_ret);
kal_uint8 ft_cct_6238_isp_set_shading_table_V3(const FT_CCT_REQ *req, ispTable *p_shading_table);
kal_uint8  ft_cct_6238_get_isp_tuning_para(/*FT_CCT_CNF *cnf,*/ peer_buff_struct **pp_peer_buff_ret);
kal_uint8 ft_cct_6238_set_isp_tuning_para(CCT_ISP_TUNING_CMD *tuning_cmd);
kal_uint8 ft_cct_6238_ae_get_gamma_paras(peer_buff_struct **pp_peer_buff_ret);
kal_uint8 ft_cct_6238_ae_update_gamma_paras(aeGammaSettingStruct* p_gamma_setting);
kal_uint8 ft_cct_6238_ae_get_window_histogram_data(peer_buff_struct **p_peer_buf_ret);
kal_uint8 ft_cct_6238_awb_get_awb_paras(peer_buff_struct **pp_peer_buf_ret);
kal_uint8 ft_cct_6238_awb_update_awb_paras(/*awb_v2_para_struct*/void* p_awb_para);
kal_uint8  ft_cct_6238_af_get_paras(peer_buff_struct **pp_peer_buff_ret);
kal_uint8  ft_cct_6238_af_set_paras( /*nvram_af_para_struct*/ void *p_nvram_af_para); //HAL


kal_uint8  ft_cct_6238_set_shutter_mode(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_set_shutter_target_time(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_set_shutter_delay_time(const FT_CCT_REQ *req);
kal_uint32 ft_cct_6238_cal_g_channel_mean_from_addr(kal_uint32 addr, kal_uint32 size, FT_CCT_BAYER_PATTERN first_pixel_bayer, kal_uint32 width, kal_uint32 height);
kal_uint8 ft_cct_6238_get_capture_center_g_channel_mean(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_get_shutter_target_time( FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_get_shutter_delay_time( FT_CCT_CNF *cnf);
kal_uint8  ft_cct_6238_get_shutter_mode(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_COQC_shutter_calibration_enable(kal_bool enable);
kal_uint8 ft_cct_6238_ge_shuttert_preview_target_lines(const FT_CCT_REQ *req,FT_CCT_CNF *cnf);

kal_uint8 ft_cct_6238_enable_transfer_image(kal_bool enable);
kal_uint8 ft_cct_6238_enable_auto_defect(kal_bool enable);
kal_uint8 ft_cct_dual_set_camera_main_or_sub_type(const FT_CCT_REQ *req);
kal_uint8 ft_cct_dual_get_camera_para_table(peer_buff_struct **pp_peer_buff_ret);
kal_uint8 ft_cct_dual_get_valid_camera_type(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_dual_set_camera_main_or_sub_type(const FT_CCT_REQ *req);
kal_uint32 ft_cct_read_sensor_id_from_nvram_tag(FT_CCT_SENSOR_TYPE__ENUM sensor_type);
kal_uint8 ft_cct_detect_sensor_id(void);
kal_uint32 ft_cct_dual_get_sensor_prefix_name(FT_CCT_CNF *cnf);
//CAMERA_INTERFACE_ENUM ft_cct_get_camera_interface_support(void); //HAL
kal_uint32 ft_cct_dual_get_lens_prefix_name(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_check_if_dynamic_LSC_support(FT_CCT_CNF *cnf);
kal_uint8 ft_cct_6238_enable_awb_cct_ct(kal_bool enable);
kal_uint8 ft_cct_6238_set_awb_cct_light_source(const FT_CCT_REQ *req);
kal_uint8 ft_cct_6238_check_if_PCA_support(FT_CCT_CNF *cnf);
kal_uint8  ft_cct_6238_set_ccm_mode(const FT_CCT_REQ *req);
kal_uint8  ft_cct_6238_get_ccm_mode(FT_CCT_CNF *cnf) ;
//#endif // end for 6238

#else // YUV support [Dana]
void FT_CCT_Operation(const FT_CCT_REQ *req, peer_buff_struct *peer_buff_in) ;
kal_uint8 ft_cct_check_op_is_support(kal_uint32 query_op_code);
void ft_cct_proc_ae_awb(void) ;
void ft_cct_usb_communication(ilm_struct* ptrMsg);

#endif
//#endif /*0*/
//YUV
/*
typedef struct {
	kal_uint8 dumy;
} FT_CCT_REQ;
void FT_CCT_Operation(const FT_CCT_REQ *req, peer_buff_struct *peer_buff_in);
 void ft_cct_proc_ae_awb(void);
 void ft_cct_usb_communication(ilm_struct* ptrMsg);
  kal_uint8 ft_cct_check_op_is_support(kal_uint32 query_op_code,FT_UTILITY_COMMAND_CNF  *cnf);
  */
  
void CalInit(void);
#endif
