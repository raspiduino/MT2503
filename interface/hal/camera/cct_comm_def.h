/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cct_comm_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Definition the feature set for camera calibration tool (CCT)
 *
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CCT_COMM_DEF_H__
#define __CCT_COMM_DEF_H__

#include "cal_comm_def.h"
#include "isp_comm_def.h"
//#include "sensor_comm_def.h"
#include "cal_api.h"

/****************temporary ***************/
//#include "camera_para_v2.h"
/****************temporary ***************/
#define AE_TOTAL_GAMMA_NO 5
#define GAMMA_FAST_LUT_NO 64
#define GAMMA_STEP_NO 20
#define MAX_ISO_LUT_NO 3

typedef enum
{
    CAL_FEATURE_CCT_BEGIN=CAL_CCT_FEATURE_BEGIN
    ,CAL_FEATURE_CCT_OP_CAMERA_PARA_TO_SENSOR   // CAL_FEATURE_TYPE_COMMAND, camera_para_to_sensor in sensor_set_struct
    ,CAL_FEATURE_CCT_OP_SENSOR_TO_CAMERA_PARA   // CAL_FEATURE_TYPE_COMMAND, sensor_to_camera_para in sensor_set_struct
    ,CAL_FEATURE_CCT_OP_REG_READ
    ,CAL_FEATURE_CCT_OP_REG_WRITE
    ,CAL_FEATURE_CCT_OP_PREVIEW_LCD_START
    ,CAL_FEATURE_CCT_OP_PREVIEW_LCD_STOP
    //,CAL_FEATURE_CCT_OP_SINGLE_SHOT_CAPTURE
    //,CAL_FEATURE_CCT_OP_MULTI_SHOT_CAPTURE
    //,CAL_FEATURE_CCT_OP_SINGLE_SHOT_CAPTURE_EX
    ,CAL_FEATURE_CCT_OP_MULTI_SHOT_CAPTURE_EX
    ,CAL_FEATURE_CCT_OP_SET_SCENARIO_PARA
    ,CAL_FEATURE_CCT_OP_QUERY_SENSOR
    ,CAL_FEATURE_CCT_OP_GET_SENSOR_ID_TYPE
    ,CAL_FEATURE_CCT_OP_GET_SENSOR_GROUP_COUNT
    ,CAL_FEATURE_CCT_OP_GET_SENSOR_GROUP_INFO
    ,CAL_FEATURE_CCT_OP_GET_SENSOR_ITEM_INFO
    ,CAL_FEATURE_CCT_OP_SET_SENSOR_ITEM_INFO
    ,CAL_FEATURE_CCT_OP_LOAD_FROM_NVRAM
    ,CAL_FEATURE_CCT_OP_SAVE_TO_NVRAM
    ,CAL_FEATURE_CCT_OP_GET_CAMERA_PARA
    ,CAL_FEATURE_CCT_OP_GET_NVRAM_SIZE
    ,CAL_FEATURE_CCT_OP_GET_CAMERA_3A
    ,CAL_FEATURE_CCT_OP_GET_CAMERA_DEFECT1
    ,CAL_FEATURE_CCT_OP_GET_CAMERA_DEFECT2
    ,CAL_FEATURE_CCT_OP_GET_DEFECT_TBL
    ,CAL_FEATURE_CCT_OP_GET_CAMERA_SHADING1
    ,CAL_FEATURE_CCT_OP_GET_CAMERA_SHADING2
    ,CAL_FEATURE_CCT_OP_GET_CAMERA_PCA
    ,CAL_FEATURE_CCT_OP_GET_CAMERA_PCA2
    ,CAL_FEATURE_CCT_OP_SET_CAMERA_DEFECT

//    ,CAL_FEATURE_CCT_OP_AE_ENABLE     //redaundant
//    ,CAL_FEATURE_CCT_OP_AE_DISABLE    //redaundant
//    ,CAL_FEATURE_CCT_OP_AE_SET_EXPOSE_LEVEL  //
//    ,CAL_FEATURE_CCT_OP_AE_GET_EXPOSE_LEVEL
//    ,CAL_FEATURE_CCT_OP_AE_QUERY_EC_STEP_INFO
//    ,CAL_FEATURE_CCT_OP_AE_SET_INIT_SHUTTER
//    ,CAL_FEATURE_CCT_OP_AE_GET_INIT_SHUTTER
    ,CAL_FEATURE_CCT_OP_WB_ACTIVATE_BY_INDEX
//    ,CAL_FEATURE_CCT_OP_WB_SET_BY_INDEX
//    ,CAL_FEATURE_CCT_OP_WB_QUERY_ALL
    ,CAL_FEATURE_CCT_OP_AE_SET_MANUAL_SHUTTER
    ,CAL_FEATURE_CCT_OP_AE_GET_MANUAL_SHUTTER
    ,CAL_FEATURE_CCT_OP_GET_CAMERA_PARA_BUF
//    ,CAL_FEATURE_CCT_OP_GET_CAPTURE_BUF
//    ,CAL_FEATURE_CCT_OP_RESUME_AE_AWB_PREVIEW_FROM_UNFINISHED_CAPTURE
//    ,CAL_FEATURE_CCT_OP_GET_BANDING_FACTOR
    ,CAL_FEATURE_CCT_OP_GET_SENSOR_PREGAIN
    ,CAL_FEATURE_CCT_OP_SET_SENSOR_PREGAIN
//    ,CAL_FEATURE_CCT_OP_MAIN_LCD_BACKLIGHT_SETTING
//    ,CAL_FEATURE_CCT_OP_GET_GAMMA_TABLE
//    ,CAL_FEATURE_CCT_OP_SET_GAMMA_TABLE
    ,CAL_FEATURE_CCT_OP_QUERY_ISP_ID
//    ,CAL_FEATURE_CCT_OP_GET_CAL_STRUCT_BUF
    ,CAL_FEATURE_CCT_OP_GET_ENG_SENSOR_PARA
    ,CAL_FEATURE_CCT_OP_SET_ENG_SENSOR_PARA
//    ,CAL_FEATURE_CCT_OP_GET_COMPENSATION_MODE
//    ,CAL_FEATURE_CCT_OP_SET_COMPENSATION_MODE
//    ,CAL_FEATURE_CCT_OP_GET_SHADING_PARA
//    ,CAL_FEATURE_CCT_OP_SET_SHADING_PARA
//    ,CAL_FEATURE_CCT_OP_GET_AUTODEFECT_PARA
//    ,CAL_FEATURE_CCT_OP_SET_AUTODEFECT_PARA
//    ,CAL_FEATURE_CCT_OP_GET_LAST_COMPENSATION_MODE
//    ,CAL_FEATURE_CCT_OP_GET_AUTODEFECT_COUNT
//    ,CAL_FEATURE_CCT_OP_SET_CAPTURE_DATA_TUNNEL
//    ,CAL_FEATURE_CCT_OP_USB_TUNNEL_CANCEL
//    ,CAL_FEATURE_CCT_OP_DEFECT_TABLE_VERIFY_BLOCK_FACTOR
//    ,CAL_FEATURE_CCT_OP_DEFECT_TABLE_CAL
//    ,CAL_FEATURE_CCT_OP_GET_DEFECT_TABLE
//    ,CAL_FEATURE_CCT_OP_SET_DEFECT_TABLE
    ,CAL_FEATURE_CCT_OP_DEV_GET_DSC_INFO
//    ,CAL_FEATURE_CCT_OP_DEV_GET_IRIS_INFO
//    ,CAL_FEATURE_CCT_OP_DEV_SET_IRIS_INFO
    ,CAL_FEATURE_CCT_OP_DEV_AE_GET_INFO
    ,CAL_FEATURE_CCT_OP_DEV_AE_SET_TABLE_IDX
    ,CAL_FEATURE_CCT_OP_DEV_AE_SET_VALUE
//    ,CAL_FEATURE_CCT_OP_DEV_AF_GET_TABLE
//    ,CAL_FEATURE_CCT_OP_DEV_AF_CAL
//    ,CAL_FEATURE_CCT_OP_DEV_AF_SET_TABLE_IDX
    ,CAL_FEATURE_CCT_OP_DEV_AF_SET_POS
//    ,CAL_FEATURE_CCT_OP_DEV_STROBE_CAL_ENABLE
//    ,CAL_FEATURE_CCT_OP_DEV_STROBE_CAL_SET_PARA
//    ,CAL_FEATURE_CCT_OP_DEV_STROBE_CAL_DISABLE
//    ,CAL_FEATURE_CCT_OP_ENABLE_USBCOM
    ,CAL_FEATURE_CCT_OP_AF_ON_OFF
//    ,CAL_FEATURE_CCT_OP_DEFECT_TABLE_ON_OFF
//    ,CAL_FEATURE_CCT_OP_AF_LENS_OFFSET_CAL
//    ,CAL_FEATURE_CCT_OP_DEFECT_TABLE_BYPASS_BACKUP_SETTING
//    ,CAL_FEATURE_CCT_OP_DEFECT_TABLE_RESTORE_SETTING
    ,CAL_FEATURE_CCT_OP_AE_GET_PERIOD_PARA
    ,CAL_FEATURE_CCT_OP_AE_SET_PERIOD_PARA
    ,CAL_FEATURE_CCT_OP_DEV_AE_BYPASS_FREERUN
    ,CAL_FEATURE_CCT_OP_DEV_AE_SET_SCENE_MODE
//    ,CAL_FEATURE_CCT_OP_GET_GAMMA_TABLE_ON_OFF_FLAG
//    ,CAL_FEATURE_CCT_OP_SET_GAMMA_TABLE_ON_OFF_FLAG
//    ,CAL_FEATURE_CCT_OP_GET_GAMMA_ON_OFF_FLAG
//    ,CAL_FEATURE_CCT_OP_SET_GAMMA_ON_OFF_FLAG
    ,CAL_FEATURE_CCT_OP_DEV_GET_ISO_GAIN
    ,CAL_FEATURE_CCT_OP_DEV_SET_ISO_GAIN
    ,CAL_FEATURE_CCT_OP_DEV_RECOVER_ISO_CAPTURE
    ,CAL_FEATURE_CCT_OP_DEV_SET_ISO_CAPTURE
    ,CAL_FEATURE_CCT_OP_DEV_GET_ISO_VALUE
    ,CAL_FEATURE_CCT_OP_DEV_SET_ISO_VALUE

    ,CAL_FEATURE_CCT_OP_DEV_FLASHLIGHT_CHARGE
    ,CAL_FEATURE_CCT_OP_DEV_FLASHLIGHT_STROBE
    ,CAL_FEATURE_CCT_OP_DEV_FLASHLIGHT_CONF
    ,CAL_FEATURE_CCT_OP_DEV_FLASHLIGHT_TYPE
    ,CAL_FEATURE_CCT_V2_OP_ISP_FLASHLIGHT_LINEARITY_PRESTROBE
    ,CAL_FEATURE_CCT_V2_OP_ISP_FLASHLIGHT_SET_AE_PARA
    ,CAL_FEATURE_CCT_V2_OP_ISP_FLASHLIGHT_GET_AE_PARA
    ,CAL_FEATURE_CCT_V2_FLASH_DURATION_LUT
    ,CAL_FEATURE_CCT_V2_OP_ISP_FLASHLIGHT_LINEARITY_RESULTS

//    ,CAL_FEATURE_CCT_OP_DEV_MODE_SIZE
//    ,CAL_FEATURE_CCT_OP_DEV_GET_ISO_GAIN_CCT
//    ,CAL_FEATURE_CCT_OP_DEV_SET_ISO_GAIN_CCT
//    ,CAL_FEATURE_CCT_OP_DEV_GET_ISO_VALUE_CCT
//    ,CAL_FEATURE_CCT_OP_DEV_SET_ISO_VALUE_CCT
//    ,CAL_FEATURE_CCT_OP_DEV_IF_SUPPORT_ISO
    ,CAL_FEATURE_CCT_OP_DEV_GET_FLASH_LEVEL
    ,CAL_FEATURE_CCT_OP_DEV_SET_FLASH_LEVEL
    ,CAL_FEATURE_CCT_OP_DEV_SET_FLASH_AE_INDEX
    ,CAL_FEATURE_CCT_OP_DEV_GET_FLASH_AE_INDEX
    ,CAL_FEATURE_CCT_V2_OP_AE_ENABLE
    ,CAL_FEATURE_CCT_V2_OP_AE_DISABLE
    ,CAL_FEATURE_CCT_V2_OP_AE_SET_SCENE_MODE
    ,CAL_FEATURE_CCT_V2_OP_AE_SET_METERING_MODE
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_CURRENT_EXPO_INFO
    ,CAL_FEATURE_CCT_V2_OP_AE_APPLY_EXPO_INFO
    ,CAL_FEATURE_CCT_V2_OP_AE_SELECT_BAND
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_AUTO_EXPO_PARA
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_ISO_VALUE_GAIN
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_GAMMA_PARA
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_GAMMA_TABLE
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_FLARE_PARA
    ,CAL_FEATURE_CCT_V2_OP_AE_UPDATE_AUTO_EXPO_PARA
    ,CAL_FEATURE_CCT_V2_OP_AE_UPDATE_ISO_VALUE_GAIN
    ,CAL_FEATURE_CCT_V2_OP_AE_UPDATE_GAMMA_PARA
    ,CAL_FEATURE_CCT_V2_OP_AE_UPDATE_FLARE_PARA
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_HISTOGRAM
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_METERING_RESULT
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_METERING_MODE_SETTING
    ,CAL_FEATURE_CCT_V2_OP_AE_UPDATE_METERING_MODE_SETTING
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_WINDOW_HISTOGRAM
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_SMOOTH_MODE_SETTING
    ,CAL_FEATURE_CCT_V2_OP_AE_UPDATE_SMOOTH_MODE_SETTING
    ,CAL_FEATURE_CCT_V2_OP_AE_ENABLE_PREVIEW_LOG
    ,CAL_FEATURE_CCT_V2_OP_AE_DISABLE_PREVIEW_LOG
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_PREVIEW_EXPO_INFO
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_SCENE_MODE
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_METERING_MODE
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_BAND
    ,CAL_FEATURE_CCT_V2_OP_AE_SET_GAMMA_BYPASS
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_GAMMA_BYPASS_FLAG

    ,CAL_FEATURE_CCT_V2_OP_AF_GET_PARA
    ,CAL_FEATURE_CCT_V2_OP_AF_SET_PARA

    ,CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_PREF_GAIN
    ,CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_PREF_GAIN
    ,CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_FAST_CONVERGE
    ,CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_FAST_CONVERGE
    ,CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_AUTO_RUN
    ,CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_AUTO_RUN
    ,CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_SMALL_BOX
    ,CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_SMALL_BOX
    ,CAL_FEATURE_CCT_V2_OP_AWB_GET_WINDOW_WHIT_POINT_COUNT_ARRAY
    ,CAL_FEATURE_CCT_V2_OP_AWB_GET_LIGHT_MODE
    ,CAL_FEATURE_CCT_V2_OP_AWB_GET_GAIN
    ,CAL_FEATURE_CCT_V2_OP_AWB_SET_GAIN
    ,CAL_FEATURE_CCT_V2_OP_AWB_SET_PREF_FACTOR
    ,CAL_FEATURE_CCT_V2_OP_AWB_GET_PREF_FACTOR
    ,CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_DYNAMIC_CCM
    ,CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_DYNAMIC_CCM
    ,CAL_FEATURE_CCT_V2_OP_AWB_GET_CURRENT_CCM
    ,CAL_FEATURE_CCT_V2_OP_AWB_ENABLE_FLASH_SYNC
    ,CAL_FEATURE_CCT_V2_OP_AWB_DISABLE_FLASH_SYNC
    ,CAL_FEATURE_CCT_V2_OP_AWB_APPLY_CAMERA_PARA2
    ,CAL_FEATURE_CCT_V2_OP_AWB_UPDATE_CAMERA_PARA2
    ,CAL_FEATURE_CCT_V2_OP_AWB_GET_NVRAM_CCM
    ,CAL_FEATURE_CCT_V2_OP_AWB_SET_NVRAM_CCM
    ,CAL_FEATURE_CCT_V2_OP_AWB_GET_AWB_PARA
    ,CAL_FEATURE_CCT_V2_OP_AWB_GET_CCM_PARA
    ,CAL_FEATURE_CCT_V2_OP_AWB_UPDATE_AWB_PARA
    ,CAL_FEATURE_CCT_V2_OP_AWB_UPDATE_CCM_PARA
    ,CAL_FEATURE_CCT_V2_OP_AWB_GET_AWB_STATUS
    ,CAL_FEATURE_CCT_V2_OP_AWB_GET_CCM_STATUS
    ,CAL_FEATURE_CCT_V2_OP_AWB_UPDATE_AWB_STATUS
    ,CAL_FEATURE_CCT_V2_OP_AWB_UPDATE_CCM_STATUS
    ,CAL_FEATURE_CCT_V2_OP_AWB_SET_CURRENT_CCM


    ,CAL_FEATURE_CCT_V2_OP_ISP_SET_SHADING_PARA
    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_SHADING_PARA
    ,CAL_FEATURE_CCT_V2_OP_ISP_ENABLE_DYNAMIC_BYPASS_MODE
    ,CAL_FEATURE_CCT_V2_OP_ISP_DISABLE_DYNAMIC_BYPASS_MODE
//    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_TUNING_PARA
//    ,CAL_FEATURE_CCT_V2_OP_ISP_SET_TUNING_PARA
//    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_PARTIAL_SHADING_TABLE
//    ,CAL_FEATURE_CCT_V2_OP_ISP_SET_PARTIAL_SHADING_TABLE
    ,CAL_FEATURE_CCT_V2_OP_ISP_SET_SHADING_ON_OFF
    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_SHADING_ON_OFF
    ,CAL_FEATURE_CCT_V2_OP_ISP_SET_TUNING_INDEX
    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_TUNING_INDEX
    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_AE_TOTAL_GAIN
    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_DYNAMIC_BYPASS_MODE_ON_OFF

//    ,CAL_FEATURE_CCT_V2_OP_ISP_FLASHLIGHT_LINEARITY_RESULT
    ,CAL_FEATURE_CCT_V2_OP_ISP_ENABLE_BINNING_MODE
    ,CAL_FEATURE_CCT_V2_OP_ISP_DISABLE_BINNING_MODE
//    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_BINNING_MODE
    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_CAMCORDER_INFO
    ,CAL_FEATURE_CCT_V2_OP_ISP_BYPASS_SHADING_MODE_ENABLE
    ,CAL_FEATURE_CCT_V2_OP_ISP_BYPASS_SHADING_MODE_DISABLE
    ,CAL_FEATURE_CCT_V2_OP_ISP_SET_CAP_RAWBIT
    ,CAL_FEATURE_CCT_V2_OP_ISP_SET_CAP_PREVIEW_SIZE    
    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_RAW_CAPTURE_SIZE    
    ,CAL_FEATURE_CCT_V2_OP_FLASH_CONFIG
    ,CAL_FEATURE_CCT_V2_ISP_DEFECT_TABLE_ON
    ,CAL_FEATURE_CCT_V2_ISP_DEFECT_TABLE_OFF
//    ,CAL_FEATURE_CCT_V2_OP_SET_SHUTTER_MODE
//    ,CAL_FEATURE_CCT_V2_OP_SET_SHUTTER_TARGET_TIME
//    ,CAL_FEATURE_CCT_V2_OP_SET_SHUTTER_DELAY_TIME
//    ,CAL_FEATURE_CCT_V2_OP_GET_SHUTTER_G_CHANNEL_MEAN
//    ,CAL_FEATURE_CCT_V2_OP_GET_SHUTTER_TARGET_TIME
	,CAL_FEATURE_CCT_V2_OP_GET_SHUTTER_DELAY_TIME
	,CAL_FEATURE_CCT_V2_OP_GET_SHUTTER_MODE
//	,CAL_FEATURE_CCT_V2_OP_SET_SHUTTER_CALIBRATION_ENABLE
//	,CAL_FEATURE_CCT_V2_OP_SET_SHUTTER_CALIBRATION_DISABLE
//	,CAL_FEATURE_CCT_V2_OP_GET_PREVIEW_TARGET_LINES
//	,CAL_FEATURE_CCT_V2_OP_ENABLE_IMAGE_TRANSFER
//	,CAL_FEATURE_CCT_V2_OP_DISABLE_IMAGE_TRANSFER
	,CAL_FEATURE_CCT_V2_OP_ISP_ENABLE_AUTO_DEFECT
	,CAL_FEATURE_CCT_V2_OP_ISP_DISABLE_AUTO_DEFECT
//    ,CAL_FEATURE_CCT_V2_ISP_GET_DEFECT_TABLE
//    ,CAL_FEATURE_CCT_V2_ISP_SET_DEFECT_TABLE
    ,CAL_FEATURE_CCT_V2_ISP_GET_SHADING_TABLE
    ,CAL_FEATURE_CCT_V2_ISP_SET_SHADING_TABLE
    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_TUNING_PARAS    
    ,CAL_FEATURE_CCT_V2_OP_ISP_UPDATE_PARA_FROM_REG    
    ,CAL_FEATURE_CCT_V2_OP_ISP_SET_TUNING_PARAS
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_GAMMA_PARAS
    ,CAL_FEATURE_CCT_V2_OP_AE_UPDATE_GAMMA_PARAS
    ,CAL_FEATURE_CCT_V2_OP_AE_GET_WINDOW_HISTOGRAM_DATA
    ,CAL_FEATURE_CCT_V2_OP_AWB_GET_AWB_PARAS
    ,CAL_FEATURE_CCT_V2_OP_AWB_UPDATE_AWB_PARAS
    ,CAL_FEATURE_CCT_V2_OP_AF_GET_PARAS
    ,CAL_FEATURE_CCT_V2_OP_AF_SET_PARAS
    ,CAL_FEATURE_CCT_DUAL_OP_SET_CAMERA_MAIN_OR_SUB_TYPE
    ,CAL_FEATURE_CCT_DUAL_OP_GET_CAMRA_PARA_TABLE
    ,CAL_FEATURE_CCT_DUAL_OP_GET_VALID_CAMERA_TYPE
    ,CAL_FEATURE_CCT_DUAL_OP_GET_SENSOR_PREFIX_NAME
    ,CAL_FEATURE_CCT_DUAL_OP_GET_LENS_PREFIX_NAME
    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_SHADING_TABLE_V3
    ,CAL_FEATURE_CCT_V2_OP_ISP_SET_SHADING_TABLE_V3
    ,CAL_FEATURE_CCT_V2_OP_CHECK_DYNAMIC_LSC_SUPPORT
    ,CAL_FEATURE_CCT_V2_OP_ENABLE_AWB_CT
    ,CAL_FEATURE_CCT_V2_OP_DISABLE_AWB_CT
    ,CAL_FEATURE_CCT_V2_OP_SET_LIGHT_SOURCE
    ,CAL_FEATURE_CCT_V2_OP_ISP_SET_PCA_TABLE
    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_PCA_TABLE
    ,CAL_FEATURE_CCT_V2_OP_ISP_SET_PCA_PARA
    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_PCA_PARA
    ,CAL_FEATURE_CCT_V2_OP_CHECK_PCA_SUPPORT
    ,CAL_FEATURE_CCT_V2_OP_SET_CCM_MODE
    ,CAL_FEATURE_CCT_V2_OP_GET_CCM_MODE
    ,CAL_FEATURE_CCT_V2_OP_CHECK_PCA2_SUPPORT	
    ,CAL_FEATURE_CCT_V2_OP_ISP_SET_PCA_TABLE_IDX
    ,CAL_FEATURE_CCT_V2_OP_ISP_GET_PCA_TABLE_IDX
    

    ,CAL_FEATURE_CCT_END
} CAL_CCT_FEATURE_ENUM;

typedef enum
{
    CAL_CCT_SCENARIO_ID_NORMAL,
    CAL_CCT_SCENARIO_ID_SHADING_CALIBRATION,
    CAL_CCT_SCENARIO_ID_SHADING_VERIFICATION,
    CAL_CCT_SCENARIO_ID_DEFECT_CALIBRATION,
    CAL_CCT_SCENARIO_ID_DEFECT_VERIFICATION,
    CAL_CCT_SCENARIO_ID_AF_VERIFICATION,
}  CAL_CCT_SCENARIO_ID_ENUM;

typedef enum
{
    CAL_CCT_REG_ISP = 0,
    CAL_CCT_REG_CMOS,
    CAL_CCT_REG_CCD
} CAL_CCT_REG_TYPE_ENUM;


typedef enum
{
    CAL_CCT_SENSOR_MAIN = 0,
    CAL_CCT_SENSOR_SUB
}CAL_CCT_SENSOR_TYPE_ENUM;


typedef enum
{
	CAMERA_TUNING_PREVIEW_SET,
	CAMERA_TUNING_CAPTURE_SET,
	CAMERA_TUNING_BINNING_SET
} CAMERA_TUNING_SET_ENUM, CAL_CCT_TUNING_SET_ENUM;

typedef enum
{
	 OUTPUT_RAW_8BITS = 0
	,OUTPUT_YUV
	,OUTPUT_JPEG
	,OUTPUT_RGB888
	,OUTPUT_RAW_10BITS
	,OUTPUT_EXT_RAW_8BITS
	,OUTPUT_EXT_RAW_10BITS
	,OUTPUT_EXT_YUV
} CAL_CCT_CAP_OUTPUT_FORMAT;

typedef enum
{
     CAL_CCT_RESULT_FAIL = 0
    ,CAL_CCT_RESULT_PASS
} CAL_CCT_RESULT_ENUM;

typedef enum
{
    CAL_CCT_IS_SHADING_SUPPORTED = 0,
    CAL_CCT_IS_AUTODEFECT_SUPPORTED,
    CAL_CCT_IS_AUTODEFECT_COUNT_SUPPORTED,
    CAL_CCT_IS_GAMMA_TABLE_SUPPORTED,
    CAL_CCT_IS_CAPMODE_SUPPORTED,
    CAL_CCT_IS_ISO_SUPPORTED,
    CAL_CCT_IS_ISO_PRIORITY_SUPPORTED,
    CAL_CCT_IS_AF_SUPPORTED,
} CAL_CCT_IS_SUPPORTED_ENUM;

typedef enum
{
    CAL_DEFECT_MODE_NONE = 0,
    CAL_DEFECT_MODE_CAPTURE,
    CAL_DEFECT_MODE_PREVIEW,
    CAL_DEFECT_MODE_BOTH
}CAL_DEFECT_MODE_ENUM;

/* Memory Structure */
typedef struct
{
    kal_uint32  BuffAddr;
    kal_uint32     BuffSize;
    kal_uint16    Width;
    kal_uint16    Height;
    MM_IMAGE_FORMAT_ENUM OutputFormat;
} CAL_CCT_BUFFER_STRUCT, *P_CAL_CCT_BUFFER_STRUCT;

/*******************************************************/
/************** Sensor Info CCT exposed struct **************/
/*******************************************************/
/* for CAL_CCT_V2_OP_GET_SENSOR_RESOLUTION */
typedef struct
{
    kal_uint16 SensorPreviewWidth;
    kal_uint16 SensorPreviewHeight;
    kal_uint16 SensorFullWidht;
    kal_uint16 SensorFullHeight;
} CAL_CCT_SENSOR_RESOLUTION_STRUCT, *P_CAL_CCT_SENSOR_RESOLUTION_STRUCT;

/*******************************************************/
/************** TUNING CCT exposed struct **************/
/*******************************************************/
typedef enum
{
    CAL_CCT_COMP_PREVIEW_NORMAL_SET = 0
    ,CAL_CCT_COMP_PREVIEW_LOWLIGHT_SET
    ,CAL_CCT_COMP_CAPTURE_NORMAL_SET
    ,CAL_CCT_COMP_CAPTURE_LOWLIGHT_SET
} CAL_CCT_COMP_SET_ENUM;

typedef struct
{
    kal_uint32 SDBLK_TRIG;
    kal_uint32 SHADING_EN;
    kal_uint32 SHADINGBLK_XOFFSET;
    kal_uint32 SHADINGBLK_YOFFSET;
    kal_uint32 SHADINGBLK_XNUM;
    kal_uint32 SHADINGBLK_YNUM;
    kal_uint32 SHADINGBLK_WIDTH;
    kal_uint32 SHADINGBLK_HEIGHT;
    kal_uint32 SHADING_RADDR;
    kal_uint32 SD_LWIDTH;
    kal_uint32 SD_LHEIGHT;
    kal_uint32 SDBLK_RATIO00;
    kal_uint32 SDBLK_RATIO01;
    kal_uint32 SDBLK_RATIO10;
    kal_uint32 SDBLK_RATIO11;
    kal_uint16 SD_TABLE_SIZE;
    //kal_uint32 SD_TABLE[MAX_SHADING_TABLE_SIZE];
}cct_shading_comp_struct;
typedef struct
{
    kal_uint8 SHADING_MODE;
    cct_shading_comp_struct *pShadingComp;
}CAL_CCT_SHADING_COMP_STRUCT, *P_CAL_CCT_SHADING_COMP_STRUCT;

typedef struct // 0x840B0550 / 0x840B0568 ~ 0x840B058C
{
    kal_uint8 ENNR;
    kal_uint8 GNF;
    kal_uint8 S1;
    kal_uint8 S2;
    kal_uint16 MBND;
    kal_uint8 GN1;
    kal_uint8    GN2;
    kal_uint8    GN3;
    kal_uint8    VLR1;
    kal_uint8 VLR2;
    kal_uint8 VLR3;
    kal_uint8 VLR4;
    kal_uint8    VLR5;
    kal_uint8 VLR6;
    kal_uint8 VLR7;
    kal_uint8 VLR8;
    kal_uint8    VLGR1;
    kal_uint8 VLGR2;
    kal_uint8 VLGR3;
    kal_uint8 VLGR4;
    kal_uint8    VLGR5;
    kal_uint8 VLGR6;
    kal_uint8 VLGR7;
    kal_uint8 VLGR8;
    kal_uint8    VLGB1;
    kal_uint8 VLGB2;
    kal_uint8 VLGB3;
    kal_uint8 VLGB4;
    kal_uint8    VLGB5;
    kal_uint8 VLGB6;
    kal_uint8 VLGB7;
    kal_uint8 VLGB8;
    kal_uint8    VLB1;
    kal_uint8 VLB2;
    kal_uint8 VLB3;
    kal_uint8 VLB4;
    kal_uint8    VLB5;
    kal_uint8 VLB6;
    kal_uint8 VLB7;
    kal_uint8 VLB8;
}cct_NR1_comp_struct, CAL_CCT_NR1_COMP_STRUCT, *P_CAL_CCT_NR1_COMP_STRUCT;

typedef struct
{
    kal_uint8 ENC;
    kal_uint8 ENY;
    kal_uint8 UV_SMPL;
    kal_uint8 S2;
    kal_uint8 S3;
    kal_uint8    SY1;
    kal_uint8    SC1;
    kal_uint8    GNY;
    kal_uint8 GNC;
    kal_uint8 PTY1;
    kal_uint8 PTY2;
    kal_uint8 PTY3;
    kal_uint8 PTY4;
    kal_uint8 PTC1;
    kal_uint8 PTC2;
    kal_uint8 PTC3;
    kal_uint8 PTC4;
}cct_NR2_comp_struct, CAL_CCT_NR2_COMP_STRUCT, *P_CAL_CCT_NR2_COMP_STRUCT;

typedef struct
{
    kal_uint8 ED_GAIN_TH;
    kal_uint8 CLIP_UNDER_TH;
    kal_uint8 CLIP_OVER_TH;
    kal_uint8 ED_BOUND_EN;
    kal_uint8 FILTER_SEL;
    kal_uint8    CLIP_UNDER_EN;
    kal_uint8    CLIP_OVER_EN;
    kal_uint8    YEDGE_EN;
    kal_uint8 RGBEDGE_EN;
    kal_uint8 ED_LUT_X1;
    kal_uint8 ED_LUT_X2;
    kal_uint8 ED_LUT_X3;
    kal_uint8 ED_LUT_Y1;
    kal_uint8 ED_LUT_Y2;
    kal_uint8 ED_LUT_Y3;
    kal_uint8 ED_LUT_Y4;
}cct_Edge_comp_struct, CAL_CCT_EDGE_COMP_STRUCT, *P_CAL_CCT_EDGE_COMP_STRUCT;

typedef struct
{
    kal_uint8 ENC3;
    kal_uint8 Y1;
    kal_uint8 Y2;
    kal_uint8 Y3;
    kal_uint8 Y4;
    kal_uint8    G1;
    kal_uint8    G2;
    kal_uint8    G3;
    kal_uint8 G4;
    kal_uint8 G5;
}cct_Saturation_comp_struct, CAL_CCT_SATURATION_COMP_STRUCT, *P_CAL_CCT_SATURATION_COMP_STRUCT;


typedef struct
{
    kal_uint8 ENY3;
    kal_uint8 OFSTY;
    kal_uint8 GAINY;
}cct_Contrast_comp_struct, CAL_CCT_CONTRAST_COMP_STRUCT, *P_CAL_CCT_CONTRAST_COMP_STRUCT;

typedef struct
{
    kal_uint8  ENDP;
    kal_uint16 DP_THRD0;
    kal_uint16 DP_THRD1;
    kal_uint16 DP_THRD2;
    kal_uint16 DP_THRD3;
    kal_uint16 DP_THRD4;
    kal_uint16 DP_THRD5;
    kal_uint16 DP_THRD6;
    kal_uint16 DP_THRD7;
    kal_uint8 DP_CD1;
    kal_uint8 DP_CD2;
    kal_uint8 DP_CD3;
    kal_uint8 DP_CD4;
    kal_uint8 DP_CD5;
    kal_uint8 DP_CD6;
    kal_uint8 DP_CD7;
    kal_uint8 DP_SEL;
    kal_uint8 DP_NUM;
}cct_autodefect_comp_struct, CAL_CCT_AUTODEFECT_COMP_STRUCT, *P_CAL_CCT_AUTODEFECT_COMP_STRUCT;

//already defined in isp_cct_if_v2.h
/*typedef struct
{

    cct_NR1_comp_struct  isp_nr1_set[7];
       cct_NR2_comp_struct  isp_nr2_set[7];
       cct_Edge_comp_struct  isp_edge_set[7];
       cct_Saturation_comp_struct isp_sat_set[7];
       cct_Contrast_comp_struct isp_contrast_set[3];
    cct_autodefect_comp_struct isp_auto_defect_set[3];
    kal_uint8  current_index;
    kal_uint8  current_category;
} CCT_ISP_TUNING_CMD;

typedef struct
{
    CAL_CCT_COMP_SET_ENUM  comp_set;
    CCT_ISP_TUNING_CMD      *tuning_cmd;
} CAL_CCT_ISP_TUNING_CMD, CAL_CCT_ISP_TUNING_CMD, *P_CAL_CCT_ISP_TUNING_CMD;
*/

typedef enum
{
    ISP_CATEGORY_NR1 = 0,
    ISP_CATEGORY_NR2,
    ISP_CATEGORY_EDGE,
    ISP_CATEGORY_SAT,
    ISP_CATEGORY_CONTRAST,
    ISP_CATEGORY_AUTO_DEFECT,
    ISP_CATEGORY_AUTO_SHADING
}CAL_ISP_CATEGORY_ENUM;


typedef struct
{
    CAL_ISP_CATEGORY_ENUM    index;
    kal_uint8                value;
}CAL_ISP_TUNING_SET;


typedef struct
{
    kal_uint32 CameraParaSize;
    kal_uint32 AeIsoParaSize;
    kal_uint32 AeMeteringCommSize;
    kal_uint32 AeSmoothModeStructSize;
    kal_uint32 AeNvramSize;
    kal_uint32 AwbNvramSize;
    kal_uint32 CcmParaSize;
    kal_uint32 AfNvramSize;   
}CAL_CCT_GET_SIZE_STRUCT, *P_CAL_CCT_GET_SIZE_STRUCT;
/*******************************************************/
/***************** AE CCT exposed struct ***************/
/*******************************************************/

typedef struct
{
	kal_uint8		AeTableIdx;
	kal_uint16	AeShutterLine;
	kal_uint16	AeSensorGain;
	kal_uint8		AeIspGain;
	kal_uint8		AeGammaNo;
	kal_uint8		AeFlareOffset;
	kal_uint8		AePreviewGammaNo;
	kal_uint8		AePreviewFlareOffset;
}AE_CCT_CURRENT_EXPO_INFO_STRUCT, CAL_CCT_AE_CURRENT_EXPO_INFO_STRUCT, *P_CAL_CCT_AE_CURRENT_EXPO_INFO_STRUCT;

/* CAL_CCT_OP_DEV_AE_SET_VALUE */
typedef struct
{
	kal_uint8		AeLutEnable;
	kal_uint8		AeTableIdx;
	kal_uint16	AeShutterLine;
	kal_uint16	AeSensorGain;
	kal_uint8		AeIspGain;
	kal_uint8		AeGammaNo;
	kal_uint8		AeFlareOffset;
}AE_CCT_APPLY_EXPO_INFO_STRUCT, CAL_CCT_AE_APPLY_EXPO_INFO_STRUCT, *P_CAL_CCT_AE_APPLY_EXPO_INFO_STRUCT;

typedef struct
{
	kal_uint8 TargetMean;
	kal_uint8 InitExpoIdx;
}AE_CCT_EXPO_SETTING_STRUCT, CAL_CCT_AE_EXPO_SETTING_STRUCT, *P_CAL_CCT_AE_EXPO_SETTING_STRUCT;

typedef struct
{
	kal_uint8 PreviewGammaNo;
    /* gamma lut for table apply & gamma mean */
	kal_uint8 GammaLut[AE_TOTAL_GAMMA_NO][GAMMA_FAST_LUT_NO];
}AE_GAMMA_SETTING_STRUCT, CAL_CCT_AE_GAMMA_SETTING_STRUCT ,*P_CAL_CCT_AE_GAMMA_SETTING_STRUCT;

typedef struct
{
	kal_uint8 Gamma[AE_TOTAL_GAMMA_NO][GAMMA_STEP_NO];
} AE_GAMMA_TABLE_STRUCT, CAL_CCT_AE_GAMMA_TABLE_STRUCT ,*P_CAL_CCT_AE_GAMMA_TABLE_STRUCT;

typedef struct
{
    /* capture flare offset cal */
	kal_uint8 FlareFixFlag;
	kal_uint8	FlareFixOffset;
	kal_uint8	FlareSearchDnRatio;
	kal_uint8 PreviewFlareOffset;
}AE_FLARE_SETTING_STRUCT, CAL_CCT_AE_FLARE_SETTING_STRUCT, *P_CAL_CCT_AE_FLARE_SETTING_STRUCT;


typedef struct
{
	kal_uint8 	AeLinearMean;
	kal_uint8 	AeGammaMean;
	kal_uint8 	AeMeteringRule;
}AE_CCT_CURRENT_METERING_RESULT_STRUCT, CAL_CCT_AE_CURRENT_METERING_RESULT_STRUCT, *P_CAL_CCT_AE_CURRENT_METERING_RESULT_STRUCT;


typedef struct
{
	kal_uint16	IsoGain[MAX_ISO_LUT_NO];
	kal_uint16	IsoValue[MAX_ISO_LUT_NO];
}/*aeIsoLutStruct,*/ CAL_CCT_AE_ISO_LUT_STRUCT, *P_CAL_CCT_AE_ISO_LUT_STRUCT;
// SC NV

typedef struct
{
    /* gamma mean */
	kal_uint8 IndoorOutdoorEv;
	kal_uint8 IndoorMinGammaMean;
	kal_uint8 OutdoorMaxGammaMean;
    /* sky detection */
	kal_uint8 SkyEv;
	kal_uint8 SkyMean;
	kal_uint8 SkyMaxWindowMean;
    /* max under expo bin */
	kal_uint8 MinUnderExpoBin;
    /* lowlight gamma limit */
	kal_uint8 LowlightEv;
	kal_uint8 LowlightMinTargetMean;
    /* enable flag */
	kal_uint8 NonOverExposureStretchEnabled;
	kal_uint8 FullDarkBackgroundCheckEnabled;
	kal_uint8 BacklightStretchEnabled;
	kal_uint8 GrassDetectEnable;/* padding for even size */
	kal_uint8 Reserve2;/* padding for even size */
} AE_CCT_METERING_SETTING_STRUCT, CAL_CCT_AE_METERING_SETTING_STRUCT, *P_CAL_CCT_AE_METERING_SETTING_STRUCT;

/* for CCT read out current AE exposure */
typedef struct
{
	kal_uint8		AeCount;
	kal_uint8		AeMean;
	kal_uint8		AeGammaMean;
	kal_uint8		AeMeteringEv;
	kal_uint8		AeApplyEv;
	kal_uint8		AeDisplayEv;
}AE_OUTPUT_CURRENT_AE_INFO_STRUCT, CAL_CCT_AE_OUTPUT_CURRENT_AE_INFO_STRUCT, *P_CAL_CCT_AE_OUTPUT_CURRENT_INFO_STRUCT;

typedef struct
{
    AE_EXPOSURE_LUT_STRUCT *lut;
    kal_uint8   *iris_lut;
    kal_uint16  start_idx;
    kal_uint16  end_idx;
    kal_uint32  timer_ms;
}AE_CCT_BYPASS_FREERUN_STRUCT, *P_AE_CCT_BYPASS_FREERUN_STRUCT, CAL_AE_BYPASS_FREERUN_STRUCT;


typedef struct
{
	kal_uint16  pregain_max;
	kal_uint16	pregain_min;
} CAL_CCT_SENSOR_PREGRAIN_INFO_STRUCT;

typedef struct {
	AE_LUT_INFO_STRUCT			ae_lut_info;	/* defined in MSDK_ISP_exp.h */
	kal_uint8						ae_index;
} CAL_CCT_DEV_AE_TABLE_IDX_INFO;

typedef struct
{
    kal_uint32 *resultLum;
}AE_CCT_BYPASS_FREERUN_RESULT_STRUCT, *P_AE_CCT_BYPASS_FREERUN_RESULT_STRUCT, CAL_AE_BYPASS_FREERUN_RESULT_STRUCT, *P_CAL_AE_BYPASS_FREERUN_RESULT_STRUCT;

/*******************************************************/
/**************** AWB CCT exposed struct ***************/
/*******************************************************/

typedef enum {
	CAL_CCT_WB_MANUAL_1 = 0,
	CAL_CCT_WB_MANUAL_2,
	CAL_CCT_WB_MANUAL_3,
	CAL_CCT_WB_MANUAL_4,
	CAL_CCT_WB_MANUAL_5,
	CAL_CCT_WB_AUTO = 0xAA,
	CAL_CCT_WB_RESET = 0xBB,
	CAL_CCT_WB_OFF = 0xFF
} CAL_CCT_WB_SETTING;

typedef struct
{
    kal_bool awbEn;
    kal_bool fastConvergeEn;
    kal_bool smallAWinEn;
    kal_bool smallTL84WinEn;
    kal_bool smallCWFWinEn;
    kal_bool smallDWinEn;
    kal_bool preferenceEn;
    kal_bool flashEn;
} CAL_CCT_AWB_STATUS_STRUCT, *P_CAL_CCT_AWB_STATUS_STRUCT;


typedef enum {
    CCM_MODE_A, //A & TL84
    CCM_MODE_C,
    CCM_MODE_D,
    CCM_MODE_SIZE
}CCM_MODE_ENUM;

//T_CCMMode;

typedef struct
{
    kal_bool DynamicCcmEn;
} CAL_CCT_CCM_STATUS_STRUCT, *P_CAL_CCT_CCM_STATUS_STRUCT;

/* CAL_CCT_V2_OP_AWB_GET_GAIN; CAL_CCT_V2_OP_AWB_SET_GAIN */
typedef struct
{
    kal_uint16 awbRgain;
    kal_uint16 awbGgain;
    kal_uint16 awbBgain;
}cct_awb_gain_struct, CAL_CCT_AWB_GAIN_STRUCT, *P_CAL_CCT_AWB_GAIN_STRUCT;

/* CAL_CCT_V2_OP_AWB_SET_PREF_FACTOR; CAL_CCT_V2_OP_AWB_GET_PREF_FACTOR */
typedef struct
{
    kal_uint8 PreferenceFactor[3][3];
}cct_awb_preference_struct, CAL_CCT_AWB_PREF_FACTOR_STRUCT, *P_CAL_CCT_AWB_PREF_FACTOR_STRUCT;

/* CAL_CCT_V2_OP_AWB_GET_CURRENT_CCM; CAL_CCT_V2_OP_AWB_SET_CURRENT_CCM */
typedef struct
{
    kal_uint8 M11;
    kal_uint8 M12;
    kal_uint8 M13;
    kal_uint8 M21;
    kal_uint8 M22;
    kal_uint8 M23;
    kal_uint8 M31;
    kal_uint8 M32;
    kal_uint8 M33;
}cct_ccm_matrix_struct, CAL_CCT_CCM_STRUCT, *P_CAL_CCT_CCM_STRUCT;


// interface for dynamic lsc table
/*typedef enum
{
	CAMERA_COLOR_TEMP_LO,
	CAMERA_COLOR_TEMP_MD,
	CAMERA_COLOR_TEMP_HI
}CAMERA_COLOR_TEMP_INFO_ENUM;
*/

/* R/W ISP/Sensor Register */
typedef struct
{
    CAL_CCT_REG_TYPE_ENUM Type;
    kal_uint32 RegAddr;
    kal_uint32 RegData;
}    CAL_CCT_REG_RW_STRUCT, *P_CAL_CCT_REG_RW_STRUCT;

/* Preview Process */
typedef struct
{
    CAL_CCT_SCENARIO_ID_ENUM    ScenarioId;
} CAL_CCT_PREVIEW_EX_STRUCT, *P_CAL_CCT_PREVIEW_EX_STRUCT;

typedef struct
{
    P_CAL_CAMERA_PREVIEW_STRUCT    pPreviewConfig;
    P_CAL_CCT_PREVIEW_EX_STRUCT    pCCTPreviewConfig;
} CAL_CCT_PREVIEW_REQ_STRUCT, *P_CAL_CCT_PREVIEW_REQ_STRUCT;


/* Capture Process */
typedef struct
{
    CAL_CCT_SCENARIO_ID_ENUM    ScenarioId;
    kal_uint16                        LeftPos;
    kal_uint16                        TopPos;
    kal_uint16                        Width;
    kal_uint16                        Height;
    kal_uint8                        SubSample;
    CAL_CCT_CAP_OUTPUT_FORMAT    OutputFormat;
} CAL_CCT_CAPTURE_EX_STRUCT, *P_CAL_CCT_CAPTURE_EX_STRUCT;

/* CCT scenario para setting */
/* CAL_FEATURE_CCT_OP_SET_SCENARIO_PARA */
typedef struct
{
    kal_bool CctMetaMode;
    kal_bool CctPreviewModeCapture;                                 /* capture at sensor preview mode or not (capture mode) */
    kal_bool CctRawDataCapture;                                         /* capture raw data to ext memory */
} CAL_CCT_SCENARIO_PARA_STRUCT, *P_CAL_CCT_SCENARIO_PARA_STRUCT;


/*
typedef struct
{
    P_CAL_CAMERA_CAPTURE_STRUCT    pCaptureConfig;
    P_CAL_CCT_CAPTURE_EX_STRUCT    pCCTCaptureConfig;
} CAL_CCT_CAPTURE_REQ_STRUCT, *P_CAL_CCT_CAPTURE_REQ_STRUCT;
*/
/* AWB white point count */
/* CAL_CCT_V2_OP_AWB_GET_WINDOW_WHIT_POINT_COUNT_ARRAY */
typedef struct
{
    kal_uint32                        Win0Count;
    kal_uint32                        Win1Count;
    kal_uint32                        Win2Count;
    kal_uint32                        Win3Count;
    kal_uint32                        Win4Count;
    kal_uint32                        Win5Count;
    kal_uint32                        Win6Count;
    kal_uint32                        Win7Count;
    kal_uint32                        Win8Count;
    kal_uint32                        Win9Count;
    kal_uint32                        WinACount;
    kal_uint32                        WinBCount;
}CAL_CCT_AWB_WHITE_COUNT_STRUCT, *P_CAL_CCT_AWB_WHITE_COUNT_STRUCT;


/* CCM light mode */
/* CAL_CCT_V2_OP_AWB_GET_NVRAM_CCM; CAL_CCT_V2_OP_AWB_SET_NVRAM_CCM */
typedef struct
{
    CAL_CCT_CCM_STRUCT            CCM;
    CCM_MODE_ENUM                        CCMLightMode;
}CAL_CCT_CCM_LIGHTMODE_STRUCT, *P_CAL_CCT_CCM_LIGHTMODE_STRUCT;

/* ISP or 3A function enable */
/* CAL_CCT_V2_OP_ISP_GET_DYNAMIC_BYPASS_MODE_ON_OFF */
/* CAL_CCT_V2_OP_AE_SET_GAMMA_BYPASS; CAL_CCT_V2_OP_AE_GET_GAMMA_BYPASS_FLAG */
typedef struct
{
    kal_bool                        Enable;
}CAL_CCT_FUNCTION_ENABLE_STRUCT, *P_CAL_CCT_FUNCTION_ENABLE_STRUCT;


/* AE Flare Histogram */
typedef struct
{
    kal_uint32                        Histogram[10];
    kal_uint32                        Count;
}CAL_CCT_AE_FLARE_HISTOGRAM_STRUCT, *P_CAL_CCT_AE_FLARE_HISTOGRAM_STRUCT;

/* AE Window Histogram */
typedef struct
{
    kal_uint32                        Pixel;
    kal_uint32                        Window[25];
    kal_uint32                        Histogram[64];
}CAL_CCT_AE_WINDOW_HISTOGRAM_STRUCT, *P_CAL_CCT_AE_WINDOW_HISTROGRAM_STRUCT;


/* CAL_CCT_V2_OP_AE_SET_SCENE_MODE */
/* Parameter: [In] AE_LUT_INFO_STRUCT */

/* Enable/Disable Shading/Defect.. */
/* CAL_CCT_V2_OP_ISP_GET_SHADING_ON_OFF */
typedef struct
{
    CAMERA_TUNING_SET_ENUM        Mode;
    kal_uint8                        Enable;
}CAL_CCT_MODULE_CTRL_STRUCT, *P_CAL_CCT_MODULE_CTRL_STRUCT;

/* CAL_CCT_V2_ISP_SET_SHADING_TABLE */
typedef struct
{
    CAMERA_TUNING_SET_ENUM        Mode;
    kal_uint32     Length;
    kal_uint32     Offset;
    kal_uint8    ColorTemp;
    kal_uint32    *pBuffer;
}CAL_CCT_TABLE_SET_STRUCT, *P_CAL_CCT_TABLE_SET_STRUCT;

/* Calibration/Verification Info */
/* CAL_CCT_V2_OP_SHADING_CAL ; CAL_CCT_OP_DEFECT_TABLE_CAL */
/* CAL_CCT_V2_OP_SHADING_VERIFY ; CAL_CCT_V2_OP_DEFECT_VERIFY */
/* CAL_CCT_V2_OP_GET_LOG_BUF */
typedef struct
{
    CAL_CCT_SCENARIO_ID_ENUM    ScenarioId;
    P_CAL_CCT_BUFFER_STRUCT     pFrameBuffer;
} CAL_CCT_CAL_STRUCT, *P_CAL_CCT_CAL_STRUCT;

/* Result Query */
/* CAL_CCT_V2_OP_AF_SET_TEST_MODE output */
typedef struct
{
    CAL_CCT_RESULT_ENUM        Result;
    kal_uint32                        Para;
}CAL_CCT_RESULT_STRUCT, *P_CAL_CCT_RESULT_STRUCT;

/* AF Engineer Mode ENUM */
typedef enum {
    CAL_EM_AF_FULL_SCAN_FORW1=0,    // 0
    CAL_EM_AF_FULL_SCAN_FORW4,    // 1
    CAL_EM_AF_FULL_SCAN_BACK1,    // 2
    CAL_EM_AF_FULL_SCAN_BACK4,    // 3
    CAL_EM_AF_CONT_FOCUS_SHOT,    // 4
    CAL_EM_AF_BEST_BRACKET_SHOT,    // 5
    CAL_EM_AF_CONT_FORWARD_LOG,    // 6
    CAL_EM_AF_CONT_BACKWARD_LOG,    // 7
    CAL_EM_AF_SINGLE_FORWARD_LOG,    // 8
    CAL_EM_AF_OFF,        // 9
    CAL_EM_AF_NO
}CAL_EM_AF_ENUM;

/* For setting engineer AF mode */
/* CAL_CCT_V2_OP_AF_SET_TEST_MODE : CAL_EM_AF_ENUM */
/* CAL_CCT_V2_OP_AF_KEY : CMA_AF_KEY_ENUM */
/* CAL_CCT_V2_OP_AF_OPERATION : CAM_AF_OPERATION_MODE_ENUM */
/* CAL_CCT_V2_OP_AF_RANGE : CAM_AF_RANGE_ENUM */
typedef struct
{
    CAL_CCT_SCENARIO_ID_ENUM    ScenarioId;
    /* Mode :     CAL_EM_AF_ENUM/
                CAM_AF_KEY_ENUM/
                CAM_AF_OPERATION_MODE_ENUM/
                CAM_AF_RANGE_ENUM*/
    kal_uint32    Mode;
} CAL_CCT_EM_AF_TEST_STRUCT, *P_CAL_CCT_EM_AF_TEST_STRUCT;

/* CAL_CCT_V2_OP_IS_SUPPORTED */
typedef struct
{
    CAL_CCT_IS_SUPPORTED_ENUM    Mode;
    kal_uint32    Para;
} CAL_CCT_IS_SUPPORT_STRUCT, *P_CAL_CCT_IS_SUPPORT_STRUCT;

/* For setting/getting Sensor engineer mode */
/* CAL_CCT_OP_GET_ENG_SENSOR_GROUP_COUNT */
/* Parameter : get kal_uint32 group count */

/* CAL_CCT_OP_GET_ENG_SENSOR_GROUP_PARA */
/* Parameter : CAL_SENSOR_GROUP_INFO_STRUCT in CAL_Sensor_exp.h */
/* CAL_CCT_OP_GET_ENG_SENSOR_PARA, CAL_CCT_OP_SET_ENG_SENSOR_PARA */
/* Parameter : CAL_SENSOR_ITEM_INFO_STRUCT in CAL_Sensor_exp.h */

/* Dummy Structures for CCT Tool*/

// danbo move from "isp_qc_if.h"
#define	ERR_OVER_MAX_SEARCH_NUM			(-1)
#define	ERR_OVER_MAX_DEFECT_NUM			(-2)

#define	ERR_STATE_INIT_PROCESS			(-3)
#define	ERR_STATE_UNDER_PROCESSING		(-4)
#define	ERR_STATE_UNKNOWN_MODE			(-5)

#define	ERR_PARA_SIZE_NOT_ALIGN			(-10)
#define	ERR_PARA_SIZE_OVER_MEM			(-11)
#define	ERR_PARA_SIZE_OVER_BLOCK		(-12)


typedef struct
{
    kal_uint8    search_mode_select;    /* Area1 or Avg. priority*/
    kal_uint8    defect_type;            /* Black or white */
    kal_uint8    defect_type_select;    /* Black only or white only or B&W or W&B */
    kal_uint8    threshold_area1;        /* threshold condition for area 1*/
    kal_uint8    threshold_area2;        /* threshold condition for area 2*/
    kal_uint16    image_width;            /* image width */
    kal_uint16    image_height;            /* image height */
    kal_uint16    block_width_factor;    /* block width factor */
    kal_uint16    block_height_factor;    /* block height factor */
    kal_uint16    boarder_len;            /* boarder length */
    kal_uint16    max_defect_num;        /* max defect pixel limit */
    kal_uint16    max_search_num;        /* max search pixel limit */
} defectpixel_para_struct, CAL_CCT_DEFECTPIXEL_PARA_STRUCT, *P_CAL_CCT_DEFECTPIXEL_PARA_STRUCT;

typedef struct
{
	kal_uint8	area_id;
	kal_uint8	pixel_diff;
	kal_uint16	pos_x;
	kal_uint16	pos_y;
} defectpixel_pixel_struct;

typedef struct
{
	kal_uint16	defect_num;				/* defect pixel found */
	kal_uint16	search_num;				/* searched pixel */
	defectpixel_pixel_struct	pixel_list[256];
} defectpixel_result_struct, CAL_COQC_DEFECTPIXEL_RESULT_STRUCT,*P_CAL_COQC_DEFECTPIXEL_RESULT_STRUCT;


typedef struct
{
	kal_uint8  Mode;
	kal_uint32 Offset;
	kal_uint32 Length;
	kal_uint32 Data[400];
}CAL_CCT_DEFECT_PARA, *P_CAL_CCT_DEFECT_PARA;

typedef struct
{
    kal_uint32 *pPreviewTbl;
    kal_uint32 *pCaptureTbl1;
    kal_uint32 *pCaptureTbl2;
}CAL_CCT_DEFECT_TBL, *P_CAL_CCT_DEFECT_TBL;

typedef struct
{
    kal_uint32 AF_cal_distance;    //calibration chart distance, 2.5M=250
    kal_uint32 AF_table_step;        //if table with same distance, fill in table step
    kal_uint16 AF_cal_step;            //if AF OK, calibrated step will fill in
    kal_uint32 AF_max_tol;            //if cal_step>AF_table_step+AF_max_tol, report over max tol
    kal_uint32 AF_min_tol;            //if cal_step<AF_table_step-AF_min_tol, report under min tol
    kal_uint8 AF_min_step_tol;        //precision of minimum step
}AF_OQC_cal_struct, CAL_CCT_AF_OQC_CAL_STRUCT, *P_CAL_CCT_AF_OQC_CAL_STRUCT;

typedef struct
{
    kal_uint8    AeAwbCalPeriod;                    /* AE AWB calculation period */
    kal_uint8    AeSettingGainDelayFrame;        /* The frame of setting gain */
    kal_uint8    AeSettingShutDelayFrame;        /* The frame of setting shutter */
    kal_uint8    AeSettingCalDelayFrame;            /* The frame of calculation */
    kal_uint8    AeSettingSensorGainDelayFrame;    /* The frame of setting sensor gain */
}camera_ae_period_para_struct, CAL_CCT_AE_PERIOD_PARA_STRUCT, *P_CAL_CCT_AE_PERIOD_PARA_STRUCT;

typedef struct
{
    kal_bool    charge_on;              /* charge status after charge ready */
    kal_uint32  timeout_ms;             /* Charge timout limit*/
} flashlight_cdt_charge_struct, CAL_CDT_FLASHLIGHT_CHARGE_STRUCT, *P_CAL_CDT_FLASHLIGHT_CHARGE_STRUCT;

typedef struct
{
    kal_uint16  strobe_width;           /* the image width */
    kal_uint16  strobe_height;          /* the image height */
    kal_uint32  strobe_offset;          /* strobe offset */
    kal_uint32  strobe_duty;            /* strobe duty */
} flashlight_cdt_strobe_struct, CAL_CDT_FLASHLIGHT_STROBE_STRUCT, *P_CAL_CDT_FLASHLIGHT_STROBE_STRUCT;

typedef struct
{
    kal_bool    prestrobe_en;           /* enable pre-strobe */
    kal_uint16  prestrobe_duty;            /* pre-strobe duty(us) */
    kal_uint16  prestrobe_times;        /* pre-strobe times */
    kal_bool    redeye_en;              /* enable red eye */
    kal_uint16  redeye_duty;            /* red eye duty(us) */
    kal_uint16  redeye_offset;           /* red-eye-strobe offset(line) */
    kal_uint8    redeye_wait_frame;   /*red-eye wait frame btw main flash*/
    kal_uint16  strobe_width;           /* the image width */
    kal_uint16  strobe_height;          /* the image height */
    kal_uint16  max_strobe_duty;        /* main-strobe duty(us) */
    kal_uint16  ae_index;               /* ae index when capture */
    kal_bool    is_awb_apply;           /* apply r/g/b gain or not */
    kal_uint16  rgain;                    /* rgain when capture */
    kal_uint16  ggain;                    /* ggain when capture */
    kal_uint16  bgain;                    /* bgain when capture */
    kal_uint16  linearity_duty;     /*linearity measurement duty(us)*/
    kal_uint8   linearity_count;     /*linearity measurement count num */
} flashlight_cdt_capture_struct, CAL_CDT_FLASHLIGHT_CAPTURE_STRUCT, *P_CAL_CDT_FLASHLIGHT_CAPTURE_STRUCT;


typedef struct
{
    kal_uint16 *pLutTriggerTime;
    kal_uint16 *pLutResultTime;
}CAL_CDT_XENON_DURATION, *P_CAL_CDT_XENON_DURATION;

typedef struct
{
    kal_uint32 flash_linearity_ae_value[50];
}flashlight_linearity_ae_result_struct;


typedef struct
{
    kal_uint16 max_sensor_gain;
    kal_uint16 max_isp_gain;
    kal_uint16 flash_gamma_no;
    kal_uint16 flash_flare_offset;
    kal_uint16 flash_target_mean;
    kal_uint16 flash_min_mean;
} FLASH_AE_CDT_PARA_STRUCT, *P_FLASH_AE_CDT_PARA_STRUCT;

typedef struct
{
    kal_bool EnableFlag;
    FLASH_AE_CDT_PARA_STRUCT *FlashAeCdtPara;
}CAL_CDT_FLASH_AE_PARA_STRUCT, *P_CAL_CDT_FLASH_AE_PARA_STRUCT;


/*CAL_CCT_V2_OP_SET_LIGHT_SOURCE*/
typedef enum{
    CCT_LIGHT_SRC_A,
    CCT_LIGHT_SRC_T,
    CCT_LIGHT_SRC_C,
    CCT_LIGHT_SRC_D,
    CCT_LIGHT_SRC_NUM
}CCT_LIGHT_SOURCE_ENUM;

typedef struct
{
    CCT_LIGHT_SOURCE_ENUM LightSource;
}CAL_CCT_LIGHT_SOURCE_SET_STRUCT, *P_CAL_CCT_LIGHT_SOURCE_SET_STRUCT;


// for CAL_CCT_OP_GET_ENG_SENSOR_GROUP_PARA ==> IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_INFO
typedef struct
{
	kal_uint16 GroupIdx;
	kal_uint32 ItemCount;
	kal_uint8 *GroupNamePtr;
} CAL_CCT_SENSOR_GROUP_INFO_STRUCT, *P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT;


// for CAL_CCT_OP_GET_ENG_SENSOR_PARA ==> IMAGE_SENSOR_FEATURE_GET_CCT_ITEM_INFO
// CAL_CCT_OP_SET_ENG_SENSOR_PARA ==> IMAGE_SENSOR_FEATURE_SET_CCT_ITEM_INFO
//
//

typedef struct
{
	kal_uint8  ColorTemperature;
	kal_uint8  Channel;
	kal_uint32 Offset;
	kal_uint32 Length;
	kal_uint8 *pBuffer;
}CAL_CCT_PCA_TBL_PARA_STRUCT, *P_CAL_CCT_PCA_TBL_PARA_STRUCT;

typedef struct
{
	kal_uint8 pca_en;
	kal_uint8 chroma_lo;
	kal_uint8 chroma_md;
	kal_uint8 chroma_hi;
}CAL_CCT_PCA_PARA_STRUCT, *P_CAL_CCT_PCA_PARA_STRUCT;



#endif /* __CCT_COMM_DEF_H__ */
