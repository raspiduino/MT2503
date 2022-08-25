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
 * Filename:
 * ---------
 *  mdi_video.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access video related functions.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MDI_VIDEO_H
#define _MDI_VIDEO_H

#ifndef _MDI_DATATYPE_H_
#include "mdi_datatype.h"
#endif 

#ifndef _GDI_INCLUDE_H_
#include "gdi_include.h"
#endif
/* add for event type */
#include "custom_events_notify.h"
#include "cal_comm_def.h"
#include "med_api.h"
#include "mdi_camera.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "mmi_frm_events_gprot.h"
#include "gdi_datatype.h"
#include "MMI_features.h"
#include "app_ltlcom.h"
#include "drv_sw_features_video.h"

#include "val_recorder_if.h"
#include "mpl_recorder.h"
#include "mm_comm_def.h"

#define MDI_VIDEO_SETTING_CAPMODE      CAL_FEATURE_CAMERA_STILL_CAPTURE_MODE
#define MDI_VIDEO_SETTING_CAMSCENE     CAL_FEATURE_CAMERA_SCENE_MODE
#define MDI_VIDEO_SETTING_CAPSIZE      CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE
#define MDI_VIDEO_SETTING_BANDING      CAL_FEATURE_CAMERA_BANDING_FREQ
#define MDI_VIDEO_SETTING_FLASH        CAL_FEATURE_CAMERA_FLASH_MODE
#define MDI_VIDEO_SETTING_AFRANGE      CAL_FEATURE_CAMERA_AF_RANGE_CONTROL
#define MDI_VIDEO_SETTING_ISO          CAL_FEATURE_CAMERA_BINNING_INFO
#define MDI_VIDEO_SETTING_WB           CAL_FEATURE_CAMERA_WB
#define MDI_VIDEO_SETTING_EFFECT       CAL_FEATURE_CAMERA_IMAGE_EFFECT
#define MDI_VIDEO_SETTING_AFMODE       CAL_FEATURE_CAMERA_AF_OPERATION_MODE
#define MDI_VIDEO_SETTING_AEMETER      CAL_FEATURE_CAMERA_AE_METERING_MODE
#define MDI_VIDEO_SETTING_SHARPNESS    CAL_FEATURE_CAMERA_SHARPNESS
#define MDI_VIDEO_SETTING_CONTRAST     CAL_FEATURE_CAMERA_CONTRAST
#define MDI_VIDEO_SETTING_SATURATION   CAL_FEATURE_CAMERA_SATURATION
#define MDI_VIDEO_SETTING_EV           CAL_FEATURE_CAMERA_EV_VALUE
#define MDI_VIDEO_SETTING_ZOOM         CAL_FEATURE_CAMERA_DIGITAL_ZOOM
#define MDI_VIDEO_SETTING_VIDEOSCENE   CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE
#define MDI_VIDEO_SUPPORT_ITEM_MAX_NO  (CAMERA_SUPPORT_ITEM_MAX_NO)

typedef enum
{
    MDI_VIDEO_REC_RESOLUTION_128x96 = 0,             // SQCIF
    MDI_VIDEO_REC_RESOLUTION_160x120,             // QQVGA
    MDI_VIDEO_REC_RESOLUTION_176x144,            // QCIF
    MDI_VIDEO_REC_RESOLUTION_320x240,            // QVGA
    MDI_VIDEO_REC_RESOLUTION_400x240,            // WQVGA
    MDI_VIDEO_REC_RESOLUTION_352x288,            // CIF
    MDI_VIDEO_REC_RESOLUTION_432x240,            // CIF
    MDI_VIDEO_REC_RESOLUTION_480x320,            // HVGA
    MDI_VIDEO_REC_RESOLUTION_640x368,            // VGA
    MDI_VIDEO_REC_RESOLUTION_640x480,            // VGA
    MDI_VIDEO_REC_RESOLUTION_720x480,            // D1
    MDI_VIDEO_REC_RESOLUTION_800x480,            // WVGA
    MDI_VIDEO_REC_RESOLUTION_848x480,            // WVGA
    MDI_VIDEO_REC_RESOLUTION_720x576,            // D1
    MDI_VIDEO_REC_RESOLUTION_800x608,            // SVGA
    MDI_VIDEO_REC_RESOLUTION_1024x768,           // XGA
    MDI_VIDEO_REC_RESOLUTION_1280x720,           // 720P
    MDI_VIDEO_REC_RESOLUTION_1280x960,           // 4VGA
    MDI_VIDEO_REC_RESOLUTION_1280x1024,          // SXGA
    MDI_VIDEO_REC_RESOLUTION_1408x1152,          // 16CIF
    MDI_VIDEO_REC_RESOLUTION_1600x1200,          // 4SVGA
    MDI_VIDEO_REC_RESOLUTION_1920x1088,          // FHD
    MDI_VIDEO_REC_RESOLUTION_704x576,            // 4CIF
    MDI_VIDEO_REC_RESOLUTION_864x480,            // FWVGA      

    MDI_VIDEO_REC_RESOLUTION_96x128,              // SQCIF
    MDI_VIDEO_REC_RESOLUTION_120x160,            // QQVGA
    MDI_VIDEO_REC_RESOLUTION_144x176,            // QCIF
    MDI_VIDEO_REC_RESOLUTION_240x320,            // QVGA
    MDI_VIDEO_REC_RESOLUTION_240x400,            // WQVGA
    MDI_VIDEO_REC_RESOLUTION_288x352,            // CIF
    MDI_VIDEO_REC_RESOLUTION_240x432,            // CIF
    MDI_VIDEO_REC_RESOLUTION_320x480,            // HVGA
    MDI_VIDEO_REC_RESOLUTION_368x640,            // VGA
    MDI_VIDEO_REC_RESOLUTION_480x640,            // VGA
    MDI_VIDEO_REC_RESOLUTION_480x720,            // D1
    MDI_VIDEO_REC_RESOLUTION_480x800,            // WVGA
    MDI_VIDEO_REC_RESOLUTION_480x848,            // WVGA
    MDI_VIDEO_REC_RESOLUTION_576x720,            // D1
    MDI_VIDEO_REC_RESOLUTION_608x800,            // SVGA
    MDI_VIDEO_REC_RESOLUTION_768x1024,           // XGA
    MDI_VIDEO_REC_RESOLUTION_720x1280,           // 720P
    MDI_VIDEO_REC_RESOLUTION_960x1280,           // 4VGA
    MDI_VIDEO_REC_RESOLUTION_1024x1280,          // SXGA
    MDI_VIDEO_REC_RESOLUTION_1152x1408,          // 16CIF
    MDI_VIDEO_REC_RESOLUTION_1200x1600,          // 4SVGA
    MDI_VIDEO_REC_RESOLUTION_1088x1920,          // FHD
    MDI_VIDEO_REC_RESOLUTION_576x704,            // 4CIF
    MDI_VIDEO_REC_RESOLUTION_480x864,            // FWVGA 
    
    MDI_VIDEO_REC_RESOLUTION_176x208,
    
    MDI_VIDEO_REC_RESOLUTION_TOTAL_COUNT    
} mdi_video_rec_resolution_enum;

#define MDI_VIDEO_UI_ROTATE_0      MM_IMAGE_ROTATE_0
#define MDI_VIDEO_UI_ROTATE_90     MM_IMAGE_ROTATE_90         /**< clock-wise  90 degree. */
#define MDI_VIDEO_UI_ROTATE_180    MM_IMAGE_ROTATE_180        /**< clock-wise 180 degree. */
#define MDI_VIDEO_UI_ROTATE_270    MM_IMAGE_ROTATE_270        /**< clock-wise 270 degree. */
/******************************************************************************
* This data structure is used by MMI.
******************************************************************************/
typedef struct
{
    mdi_video_rec_resolution_enum video_size;
    U16 video_format;
    U16 storage;
    U16 quality;
} mdi_video_rec_spec_struct;


/* Main sensor */
#define MDI_VIDEO_MAIN_SENSOR               CAM_MAIN_CAMERA
/* Sub sensor */
#define MDI_VIDEO_SUB_SENSOR                CAM_SUB_CAMERA

/* EV value which is higher than default value by 4 levels */
#define MDI_VIDEO_EV_P4                      CAM_EV_POS_4_3
/* EV value which is higher than default value by 3 levels */
#define MDI_VIDEO_EV_P3                      CAM_EV_POS_3_3
/* EV value which is higher than default value by 2 levels */
#define MDI_VIDEO_EV_P2                      CAM_EV_POS_2_3
/* EV value which is higher than default value by 1 levels */
#define MDI_VIDEO_EV_P1                      CAM_EV_POS_1_3
/* Default EV value */
#define MDI_VIDEO_EV_0                       CAM_EV_ZERO
/* EV value which is lower than default value by 1 levels */
#define MDI_VIDEO_EV_N1                      CAM_EV_NEG_1_3
/* EV value which is lower than default value by 2 levels */
#define MDI_VIDEO_EV_N2                      CAM_EV_NEG_2_3
/* EV value which is lower than default value by 3 levels */
#define MDI_VIDEO_EV_N3                      CAM_EV_NEG_3_3
/* EV value which is lower than default value by 4 levels */
#define MDI_VIDEO_EV_N4                      CAM_EV_NEG_4_3
/* EV value which is specific for night mode */
#define MDI_VIDEO_EV_NIGHT                   CAM_EV_NIGHT_SHOT
/* Total count of EV */
#define MDI_VIDEO_EV_COUNT                   CAM_NO_OF_EV

/* Video effect: Normal */
#define MDI_VIDEO_EFFECT_NOMRAL              CAM_EFFECT_ENC_NORMAL
/* Video effect: Grayscale */
#define MDI_VIDEO_EFFECT_GRAYSCALE           CAM_EFFECT_ENC_GRAYSCALE
/* Video effect: Sepia */
#define MDI_VIDEO_EFFECT_SEPIA               CAM_EFFECT_ENC_SEPIA
/* Video effect: Sepia Green */
#define MDI_VIDEO_EFFECT_SEPIA_GREEN         CAM_EFFECT_ENC_SEPIAGREEN
/* Video effect: Sepia Blue */
#define MDI_VIDEO_EFFECT_SEPIA_BLUE          CAM_EFFECT_ENC_SEPIABLUE
/* Video effect: Color Invert */
#define MDI_VIDEO_EFFECT_COLOR_INVERT        CAM_EFFECT_ENC_COLORINV
/* Video effect: Gray Invert */
#define MDI_VIDEO_EFFECT_GRAY_INVERT         CAM_EFFECT_ENC_GRAYINV
/* Video effect: Blackborad */
#define MDI_VIDEO_EFFECT_BLACKBOARD          CAM_EFFECT_ENC_BLACKBOARD
/* Video effect: Whiteborad */
#define MDI_VIDEO_EFFECT_WHITEBOARD          CAM_EFFECT_ENC_WHITEBOARD
/* Video effect: Copper Carving */
#define MDI_VIDEO_EFFECT_COPPER_CARVING      CAM_EFFECT_ENC_COPPERCARVING
/* Video effect: Blue Carving */
#define MDI_VIDEO_EFFECT_BLUE_CARVING        CAM_EFFECT_ENC_BLUECARVING
/* Video effect: Embossment */
#define MDI_VIDEO_EFFECT_EMBOSSMENT          CAM_EFFECT_ENC_EMBOSSMENT
/* Video effect: Contrast */
#define MDI_VIDEO_EFFECT_CONTRAST            CAM_EFFECT_ENC_CONTRAST
/* Video effect: Jean */
#define MDI_VIDEO_EFFECT_JEAN                CAM_EFFECT_ENC_JEAN
/* Video effect: Sketch */
#define MDI_VIDEO_EFFECT_SKETCH              CAM_EFFECT_ENC_SKETCH
/* Video effect: Oil */
#define MDI_VIDEO_EFFECT_OIL                 CAM_EFFECT_ENC_OIL
/* Total count of video effect */
#define MDI_VIDEO_EFFECT_COUNT               CAM_NO_OF_EFFECT_ENC

/* White balance: Auto */
#define MDI_VIDEO_WB_AUTO                    CAM_WB_AUTO
/* White balance: Daylight */
#define MDI_VIDEO_WB_DAYLIGHT                CAM_WB_DAYLIGHT
/* White balance: Tungsten */
#define MDI_VIDEO_WB_TUNGSTEN                CAM_WB_TUNGSTEN
/* White balance: Fluorescent */
#define MDI_VIDEO_WB_FLUORESCENT             CAM_WB_FLUORESCENT
/* White balance: Cloud */
#define MDI_VIDEO_WB_CLOUD                   CAM_WB_CLOUD
/* White balance: Incandescence */
#define MDI_VIDEO_WB_INCANDESCENCE           CAM_WB_INCANDESCENCE
/* Total count of white balance */
#define MDI_VIDEO_WB_COUNT                   CAM_NO_OF_WB

/* Camera banding 50HZ */
#define MDI_VIDEO_BANDING_50HZ               CAM_BANDING_50HZ
/* Camera banding 60HZ */
#define MDI_VIDEO_BANDING_60HZ               CAM_BANDING_60HZ
/* Total count of camera banding */
#define MDI_VIDEO_BANDING_COUNT              CAM_NO_OF_BANDING

#define MDI_VIDEO_VIDEO_SIZE_SQCIF           MDI_VIDEO_REC_RESOLUTION_128x96
#define MDI_VIDEO_VIDEO_SIZE_QQVGA           MDI_VIDEO_REC_RESOLUTION_160x120
#define MDI_VIDEO_VIDEO_SIZE_QCIF            MDI_VIDEO_REC_RESOLUTION_176x144
#define MDI_VIDEO_VIDEO_SIZE_QVGA            MDI_VIDEO_REC_RESOLUTION_320x240
#define MDI_VIDEO_VIDEO_SIZE_CIF             MDI_VIDEO_REC_RESOLUTION_352x288
#define MDI_VIDEO_VIDEO_SIZE_WQVGA           MDI_VIDEO_REC_RESOLUTION_400x240
#define MDI_VIDEO_VIDEO_SIZE_HVGA            MDI_VIDEO_REC_RESOLUTION_480x320
#define MDI_VIDEO_VIDEO_SIZE_NHD             MDI_VIDEO_REC_RESOLUTION_640x368
#define MDI_VIDEO_VIDEO_SIZE_VGA             MDI_VIDEO_REC_RESOLUTION_640x480
#define MDI_VIDEO_VIDEO_SIZE_WVGA            MDI_VIDEO_REC_RESOLUTION_800x480
#define MDI_VIDEO_VIDEO_SIZE_D1              MDI_VIDEO_REC_RESOLUTION_720x480
#define MDI_VIDEO_VIDEO_SIZE_D1_2            MDI_VIDEO_REC_RESOLUTION_720x576
#define MDI_VIDEO_VIDEO_SIZE_CIF_2           MDI_VIDEO_REC_RESOLUTION_432x240
#define MDI_VIDEO_VIDEO_SIZE_WVGA_2          MDI_VIDEO_REC_RESOLUTION_848x480
#define MDI_VIDEO_VIDEO_SIZE_SVGA            MDI_VIDEO_REC_RESOLUTION_800x608  
#define MDI_VIDEO_VIDEO_SIZE_XGA             MDI_VIDEO_REC_RESOLUTION_1024x768 
#define MDI_VIDEO_VIDEO_SIZE_720P            MDI_VIDEO_REC_RESOLUTION_1280x720 
#define MDI_VIDEO_VIDEO_SIZE_4VGA            MDI_VIDEO_REC_RESOLUTION_1280x960 
#define MDI_VIDEO_VIDEO_SIZE_SXGA            MDI_VIDEO_REC_RESOLUTION_1280x1024
#define MDI_VIDEO_VIDEO_SIZE_16CIF           MDI_VIDEO_REC_RESOLUTION_1408x1152
#define MDI_VIDEO_VIDEO_SIZE_4SVGA           MDI_VIDEO_REC_RESOLUTION_1600x1200
#define MDI_VIDEO_VIDEO_SIZE_FHD             MDI_VIDEO_REC_RESOLUTION_1920x1088
#define MDI_VIDEO_VIDEO_SIZE_4CIF            MDI_VIDEO_REC_RESOLUTION_704x576
#define MDI_VIDEO_VIDEO_SIZE_FWVGA           MDI_VIDEO_REC_RESOLUTION_864x480

#define MDI_VIDEO_VIDEO_SIZE_WP_QCIF         MDI_VIDEO_REC_RESOLUTION_176x208
#define MDI_VIDEO_VIDEO_SIZE_WP_QVGA         MDI_VIDEO_REC_RESOLUTION_240x320
#define MDI_VIDEO_VIDEO_SIZE_WP_WQVGA        MDI_VIDEO_REC_RESOLUTION_240x400
#define MDI_VIDEO_VIDEO_SIZE_WP_HVGA         MDI_VIDEO_REC_RESOLUTION_320x480
#define MDI_VIDEO_VIDEO_SIZE_WP_WVGA         MDI_VIDEO_REC_RESOLUTION_480x800

/* Video size: User Define, which is not defined in our support list */
#define MDI_VIDEO_VIDEO_SIZE_USER_DEFINE     MDI_VIDEO_REC_RESOLUTION_TOTAL_COUNT

/* Video quality: Fine */
#define MDI_VIDEO_REC_QTY_FINE               MPL_RECORDER_QUALITY_FINE
/* Video quality: High */
#define MDI_VIDEO_REC_QTY_HIGH               MPL_RECORDER_QUALITY_HIGH
/* Video quality: Normal */
#define MDI_VIDEO_REC_QTY_NORMAL             MPL_RECORDER_QUALITY_NORMAL
/* Video quality: Low */
#define MDI_VIDEO_REC_QTY_LOW                MPL_RECORDER_QUALITY_LOW
/* Total count of video quality */
#define MDI_VIDEO_REC_QTY_COUNT              MPL_RECORDER_QUALITY_MAX
#define MDI_VIDEO_REC_QTY_ALL                MPL_RECORDER_QUALITY_MAX

/* Video Storage:  */
#define MDI_VIDEO_REC_STORAGE_PHONE             MPL_RECORDER_STORAGE_PHONE
/* Video Storage:  */
#define MDI_VIDEO_REC_STORAGE_SD                MPL_RECORDER_STORAGE_CARD
/* Total count of video storage */
#define MDI_VIDEO_REC_STORAGE_COUNT              MPL_RECORDER_STORAGE_MAX
#define MDI_VIDEO_REC_STORAGE_ALL              MPL_RECORDER_STORAGE_MAX

/* Video telephony encode quality: Fine */
#define MDI_VIDEO_TEL_ENC_QTY_FINE           VCALL_ENC_QTY_FINE
/* Video telephony encode quality: Normal */
#define MDI_VIDEO_TEL_ENC_QTY_NORMAL         VCALL_ENC_QTY_NORMAL
/* Video telephony encode quality: Low */
#define MDI_VIDEO_TEL_ENC_QTY_LOW            VCALL_ENC_QTY_LOW
/* Total count of video telephony encode quality */
#define MDI_VIDEO_TEL_ENC_QTY_COUNT          VCALL_ENC_QTY_TOTAL

/* Video format: 3GP */
#define MDI_VIDEO_VIDEO_FORMAT_3GP           MPL_RECORDER_FORMAT_H263
/* Video format: MP4 */
#define MDI_VIDEO_VIDEO_FORMAT_MP4           MPL_RECORDER_FORMAT_MPEG4
/* Video format: MJPEG */
#define MDI_VIDEO_VIDEO_FORMAT_MJPEG         MPL_RECORDER_FORMAT_MJPEG

#define MDI_VIDEO_VIDEO_FORMAT_H264          MPL_RECORDER_FORMAT_H264

/* Total count of video format */
#define MDI_VIDEO_VIDEO_FORMAT_COUNT         MPL_RECORDER_FORMAT_MAX

/* Preview rotate: 0 degree */
#define MDI_VIDEO_PREVIEW_ROTATE_0           CAM_IMAGE_NORMAL
/* Preview rotate: 90 degree */
#define MDI_VIDEO_PREVIEW_ROTATE_90          CAM_IMAGE_ROTATE_90
/* Preview rotate: 180 degree */
#define MDI_VIDEO_PREVIEW_ROTATE_180         CAM_IMAGE_ROTATE_180
/* Preview rotate: 270 degree */
#define MDI_VIDEO_PREVIEW_ROTATE_270         CAM_IMAGE_ROTATE_270
/* Preview rotate: 0 degree + Mirror*/
#define MDI_VIDEO_PREVIEW_ROTATE_0_MIRROR    CAM_IMAGE_MIRROR
/* Preview rotate: 90 degree + Mirror */
#define MDI_VIDEO_PREVIEW_ROTATE_90_MIRROR   CAM_IMAGE_MIRROR_ROTATE_90
/* Preview rotate: 180 degree + Mirror */
#define MDI_VIDEO_PREVIEW_ROTATE_180_MIRROR  CAM_IMAGE_MIRROR_ROTATE_180
/* Preview rotate: 270 degree + Mirror */
#define MDI_VIDEO_PREVIEW_ROTATE_270_MIRROR  CAM_IMAGE_MIRROR_ROTATE_270

#define MDI_VIDEO_PREVIEW_ROTATE_RESET       (999)

#if defined(ISP_SUPPORT)
/* LCD rotate: 0 degree */
#define MDI_VIDEO_LCD_ROTATE_0            LCD_LAYER_ROTATE_NORMAL
/* LCD rotate: 90 degree */
#define MDI_VIDEO_LCD_ROTATE_90           LCD_LAYER_ROTATE_90
/* LCD rotate: 180 degree */
#define MDI_VIDEO_LCD_ROTATE_180          LCD_LAYER_ROTATE_180
/* LCD rotate: 270 degree */
#define MDI_VIDEO_LCD_ROTATE_270          LCD_LAYER_ROTATE_270
/* LCD rotate: 0 degree + Mirror */
#define MDI_VIDEO_LCD_ROTATE_0_MIRROR     LCD_LAYER_MIRROR
/* LCD rotate: 90 degree + Mirror */
#define MDI_VIDEO_LCD_ROTATE_90_MIRROR    LCD_LAYER_MIRROR_ROTATE_90
/* LCD rotate: 180 degree + Mirror */
#define MDI_VIDEO_LCD_ROTATE_180_MIRROR   LCD_LAYER_MIRROR_ROTATE_180
/* LCD rotate: 270 degree + Mirror */
#define MDI_VIDEO_LCD_ROTATE_270_MIRROR   LCD_LAYER_MIRROR_ROTATE_270
#else /* defined(ISP_SUPPORT) */ 
/* LCD rotate: 0 degree */
#define MDI_VIDEO_LCD_ROTATE_0            0
/* LCD rotate: 90 degree */
#define MDI_VIDEO_LCD_ROTATE_90           1
/* LCD rotate: 180 degree */
#define MDI_VIDEO_LCD_ROTATE_180          2
/* LCD rotate: 270 degree */
#define MDI_VIDEO_LCD_ROTATE_270          3
/* LCD rotate: 0 degree + Mirror */
#define MDI_VIDEO_LCD_ROTATE_0_MIRROR     4
/* LCD rotate: 90 degree + Mirror */
#define MDI_VIDEO_LCD_ROTATE_90_MIRROR    5
/* LCD rotate: 180 degree + Mirror */
#define MDI_VIDEO_LCD_ROTATE_180_MIRROR   6
/* LCD rotate: 270 degree + Mirror */
#define MDI_VIDEO_LCD_ROTATE_270_MIRROR   7
#endif /* defined(ISP_SUPPORT) */ 

/* Brightness value which is darker than default value by 5 levels */
#define MDI_VIDEO_BRIGHTNESS_N5              0
/* Brightness value which is darker than default value by 4 levels */
#define MDI_VIDEO_BRIGHTNESS_N4              1
/* Brightness value which is darker than default value by 3 levels */
#define MDI_VIDEO_BRIGHTNESS_N3              2
/* Brightness value which is darker than default value by 2 levels */
#define MDI_VIDEO_BRIGHTNESS_N2              3
/* Brightness value which is darker than default value by 1 levels */
#define MDI_VIDEO_BRIGHTNESS_N1              4
/* Default brightness value */
#define MDI_VIDEO_BRIGHTNESS_0               5
/* Brightness value which is brighter than default value by 1 level */
#define MDI_VIDEO_BRIGHTNESS_P1              6
/* Brightness value which is brighter than default value by 2 level */
#define MDI_VIDEO_BRIGHTNESS_P2              7
/* Brightness value which is brighter than default value by 3 level */
#define MDI_VIDEO_BRIGHTNESS_P3              8
/* Brightness value which is brighter than default value by 4 level */
#define MDI_VIDEO_BRIGHTNESS_P4              9
/* Brightness value which is brighter than default value by 5 level */
#define MDI_VIDEO_BRIGHTNESS_P5              10

/* Contrast value which is lower than default value by 5 levels */
#define MDI_VIDEO_CONTRAST_N5                0
/* Contrast value which is lower than default value by 4 levels */
#define MDI_VIDEO_CONTRAST_N4                1
/* Contrast value which is lower than default value by 3 levels */
#define MDI_VIDEO_CONTRAST_N3                2
/* Contrast value which is lower than default value by 2 levels */
#define MDI_VIDEO_CONTRAST_N2                3
/* Contrast value which is lower than default value by 1 levels */
#define MDI_VIDEO_CONTRAST_N1                4
/* Default contrast value */
#define MDI_VIDEO_CONTRAST_0                 5
/* Contrast value which is higher than default value by 1 levels */
#define MDI_VIDEO_CONTRAST_P1                6
/* Contrast value which is higher than default value by 2 levels */
#define MDI_VIDEO_CONTRAST_P2                7
/* Contrast value which is higher than default value by 3 levels */
#define MDI_VIDEO_CONTRAST_P3                8
/* Contrast value which is higher than default value by 4 levels */
#define MDI_VIDEO_CONTRAST_P4                9
/* Contrast value which is higher than default value by 5 levels */
#define MDI_VIDEO_CONTRAST_P5                10

/* Frame mode in which video content will stretch to video layer */
#define MDI_VIDEO_FRAME_MODE_STRETCH        MED_VID_FRAME_STRETCH

/* Frame mode in which video content will best fit the video layer from the outside */
#define MDI_VIDEO_FRAME_MODE_FIT_OUTSIDE    MED_VID_FRAME_FIT_OUTSIDE

/* Frame mode in which video content will best fit the video layer from the inside */
#define MDI_VIDEO_FRAME_MODE_FIT_INSIDE    MED_VID_FRAME_FIT_INSIDE

/* Max length of content info */
#define MDI_VIDEO_MAX_CONTENT_INFO_LEN       80

/* Max buffer size of content info */
#define MDI_VIDEO_CONTENT_BUFFER_SIZE        ((MDI_VIDEO_MAX_CONTENT_INFO_LEN + 1) * ENCODING_LENGTH)

/* Character count of the info title */
#define MDI_VIDEO_INFO_TITLE_CHAR_COUNT      32

#define MDI_VIDEO_MAX_TRACK_NUM (VID_MAX_VIDEO_TRACK_NUM)
#define MDI_VIDEO_MAX_SUBTITLE_NUM (VID_MAX_VIDEO_SUBTITLE_NUM)

#ifdef __MMI_OP11_PDL_FROM_SDP__
/* Max length of url buffer inside SDP*/
#define MDI_SDP_MAX_URL_LEN     256
/* Max SDP file size */
#define MDI_SDP_MAX_FILE_SIZE   40960

#define MDI_SDP_ATTRIB_PURGE    "X-purge"
#define MDI_SDP_ATTRIB_FSIZE    "X-filesize"
#define MDI_SDP_ATTRIB_FWALLOW  "X-FORWARD-ALLOWED"
#endif /* __MMI_OP11_PDL_FROM_SDP__ */

#if defined(__MTK_TARGET__)
    /* HW Rotator support */
    #define __MDI_VIDEO_HW_ROTATOR_SUPPORT__
    #define __MDI_VIDEO_HW_ROTATOR_BY_IDP__
#endif

#if defined(VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED)
    #define __MDI_VIDEO_PROCESSING_SUPPORT__
#endif

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
#define MDI_VDOPLY_MAX_SUBTITLE_LAYER_WIDTH (VIDEO_SUBTITLE_RECT_MAX_WIDTH)
#define MDI_VDOPLY_MAX_SUBTITLE_LAYER_HEIGHT (VIDEO_SUBTITLE_RECT_MAX_HEIGHT)
#endif

#if defined(__MTK_TARGET__)
/* Scene mode: Audo */
#define MDI_VIDEO_SCENE_MODE_AUTO                   CAM_VIDEO_AUTO
/* Scene mode: Night */
#define MDI_VIDEO_SCENE_MODE_NIGHT                  CAM_VIDEO_NIGHT
/* AF range mode: Auto */
#define MDI_VIDEO_AF_RANGE_AUTO                     CAM_AF_RANGE_AUTO
/* AF range mode: Landscape */
#define MDI_VIDEO_AF_RANGE_LANDSCAPE                CAM_AF_RANGE_LANDSCAPE
/* AF range mode: Macro */
#define MDI_VIDEO_AF_RANGE_MACRO                    CAM_AF_RANGE_MACRO
/* AF operation mode: Single zone */
#define MDI_VIDEO_AF_OPERATION_MODE_SINGLE_ZONE     CAM_AF_SINGLE_ZONE
/* AF operation mode: Continuous */
#define MDI_VIDEO_AF_OPERATION_MODE_CONTINUOUS      CAM_AF_CONTINUOUS
/* Image enhancement level: Low */
#define MDI_VIDEO_IE_LEVEL_LOW                      CAM_ADJUST_LOW_LEVEL
/* Image enhancement level: Medium */
#define MDI_VIDEO_IE_LEVEL_MEDIUM                   CAM_ADJUST_MED_LEVEL
/* Image enhancement level: High*/
#define MDI_VIDEO_IE_LEVEL_HIGH                     CAM_ADJUST_HIGH_LEVEL
#else
/* Scene mode: Audo */
#define MDI_VIDEO_SCENE_MODE_AUTO                   0
/* Scene mode: Night */
#define MDI_VIDEO_SCENE_MODE_NIGHT                  0
/* AF range mode: Auto */
#define MDI_VIDEO_AF_RANGE_AUTO                     0
/* AF range mode: Landscape */
#define MDI_VIDEO_AF_RANGE_LANDSCAPE                0
/* AF range mode: Macro */
#define MDI_VIDEO_AF_RANGE_MACRO                    0
/* AF operation mode: Single zone */
#define MDI_VIDEO_AF_OPERATION_MODE_SINGLE_ZONE     0
/* AF operation mode: Continuous */
#define MDI_VIDEO_AF_OPERATION_MODE_CONTINUOUS      0
/* Image enhancement level: Low */
#define MDI_VIDEO_IE_LEVEL_LOW                      0
/* Image enhancement level: Medium */
#define MDI_VIDEO_IE_LEVEL_MEDIUM                   0
/* Image enhancement level: High*/
#define MDI_VIDEO_IE_LEVEL_HIGH                     0
#endif

/* Video telephony display type enum */
typedef enum {
    MDI_VIDEO_TEL_DISPLAY_HIDE,     /* Video display type: hide */
    MDI_VIDEO_TEL_DISPLAY_IMAGE,    /* Video display type: image */    
    MDI_VIDEO_TEL_DISPLAY_VIDEO     /* Video display type: video */
} mdi_video_tel_disp_type_enum;

/* Video telephony codec event enum */
typedef enum {
    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_SIZE,     /* Event: change encode size */
    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_QUALITY,  /* Event: change encode quality */    
    MDI_VIDEO_TEL_EVENT_UPDATE_LCD,  /* Event: update lcd */        
    MDI_VIDEO_TEL_EVENT_ENC_PATH_BUILT,  /* Event: notify enc path is built */           
    MDI_VIDEO_TEL_EVENT_DEC_CH_CHANGE  /* Event: notify dec CH is changed (close camera) */               
} mdi_video_tel_codec_event_enum;

/* Stream type enum */
typedef enum
{
    MDI_VIDEO_STREAM_RTSP_URL,  /* Stream type in RSTP URL format */
    MDI_VIDEO_STREAM_SDP_FILE   /* Stream type in SDP File format */
} mdi_video_stream_type_enum;

/* Stream transport type enum */
typedef enum
{
    MDI_VIDEO_STREAM_TRANSPORT_UDP,  /* Stream transport type UDP */
    MDI_VIDEO_STREAM_TRANSPORT_TCP   /* Stream transport type TCP */
} mdi_video_stream_transport_type_enum;

/* Video track type enum */
typedef enum
{
    MDI_VIDEO_TRACK_NONE,   /* Video has no track in it */
    MDI_VIDEO_TRACK_AV,     /* Video has both audio and video tracks */
    MDI_VIDEO_TRACK_A_ONLY, /* Video has audio track only */
    MDI_VIDEO_TRACK_V_ONLY, /* Video has video track only */
    MDI_VIDEO_TRACK_COUNT   /* Count of video track enum */
} mdi_video_track_enum;

/* DRM state enum */
typedef enum
{
    MDI_VIDEO_DRM_EXIT,         /* Drm State: Exit */
    MDI_VIDEO_DRM_PERMITTED,    /* Drm State: Permitted */
    MDI_VIDEO_DRM_CONSUMING,    /* Drm State: Consuming */
    MDI_VIDEO_DRM_PLAY_FINISHED,/* Drm State: Finished */
    MDI_VIDEO_DRM_PAUSED,       /* Drm State: Paused */

    MDI_VIDEO_DRM_END           /* Count of drm state */
} mdi_video_drm_state_enum;


/* Video scenario type */
typedef enum
{
    MDI_VIDEO_SCENARIO_DEFAULT = MPL_DECODER,
    MDI_VIDEO_SCENARIO_QVGA = MPL_UPTO_QVGA,
    MDI_VIDEO_SCENARIO_CIF = MPL_UPTO_CIF,
    MDI_VIDEO_SCENARIO_PREVIEW = MPL_PREVIEW,
    MDI_VIDEO_SCENARIO_INFO = MPL_INFO,
    MDI_VIDEO_SCENARIO_MPEG4 = MPL_MPEG4_DECODER,
    MDI_VIDEO_SCENARIO_DEFAULT_N_SUBTITLE = MPL_DECODER_N_SUBTITLE,
    MDI_VIDEO_SCENARIO_QVGA_MPEG4SP = MPL_QVGA_MPEG4SP
} mdi_video_scenario_type_enum;

/* video 3D mode */
typedef enum
{
    MDI_VIDEO_3D_MODE_NONE = MPL_RENDERER_3D_MODE_OFF,
    MDI_VIDEO_3D_MODE_SIDE_BY_SIDE = MPL_RENDERER_3D_MODE_SIDE_BY_SIDE,
    MDI_VIDEO_3D_MODE_TOP_DOWN = MPL_RENDERER_3D_MODE_TOP_DOWN
} mdi_video_3d_mode_enum;

/* Video key frame direction */
typedef enum
{
    MDI_VIDEO_SEARCH_DIR_BACKWARD,
    MDI_VIDEO_SEARCH_DIR_FORWARD    
} mdi_video_search_dir_enum;

typedef struct
{
    U8 elapse_ticks;
    U8 sleep_ticks;
} mdi_video_sleep_struct;

/* Video information structure */
typedef enum
{
    MDI_VIDEO_TRACK_2D_NORMAL = MPL_VIDEO_2D_NORMAL,
    MDI_VIDEO_TRACK_3D = MPL_VIDEO_3D
} mdi_video_track_type_enum;

typedef struct
{
    U32 track_index;
    mdi_video_track_type_enum track_type;
} mdi_video_track_info;

typedef struct
{
    U32 track_index;
    U32 language;
} mdi_video_subtitle_info;

typedef enum
{
    MDI_VIDEO_THUMB_NONE = MPL_THUMBNAIL_NONE,
    MDI_VIDEO_THUMB_JPG = MPL_THUMBNAIL_JPG,
    MDI_VIDEO_THUMB_PNG = MPL_THUMBNAIL_PNG,
    MDI_VIDEO_THUMB_BMP = MPL_THUMBNAIL_BMP
} mdi_video_thumb_type_enum;

typedef struct
{
    WCHAR *title_desc_ptr;
    U16 title_desc_len;

    WCHAR *artist_desc_ptr;
    U16 artist_desc_len;

    WCHAR *date_desc_ptr;
    U16 date_desc_len;

    WCHAR *annotation_desc_ptr;
    U16 annotation_desc_len;

    WCHAR *type_desc_ptr;
    U16 type_desc_len;

    U8 *thumb_ptr;
    U32 thumb_allocated_len;
    U32 thumb_usaged_len;

    mdi_video_thumb_type_enum thumb_type;
}mdi_video_mot_meta_struct;


typedef struct
{
    U16 width;                      /* Width of the video */
    U16 height;                     /* Height of the video */
    U32 total_frame_count;          /* Total framecount of the video */
    U64 total_time_duration;        /* Total time duration of the video */
    mdi_video_track_enum track;     /* Track information of the video */
    //mdi_handle handle;              /* Handle of the opened video file */
    MMI_BOOL is_seekable;           /* Is this video seekable */
    MMI_BOOL is_stereo;             /* Not used */
    U8 aud_channel_no;              /* Audio channel count information */
    U16 aud_sample_rate;            /* Audio sample rate information */

    MMI_BOOL is_drm_streaming;      /* Is this is a drm streaming file */
    MMI_BOOL is_rec_allowed;        /* Recording is allowed or not */    
#ifdef __MMI_VIDEO_CLIPPER__ 
    MMI_BOOL is_proprietary;        /* Is proprietary */
#endif
    S32 drm_handle;                 /* DRM handle of this video */
    
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
    U32 track_num;
    mdi_video_track_info track_info[MDI_VIDEO_MAX_TRACK_NUM];
#endif /* __MMI_VIDEO_3D_ANAGLYPH__ */ 
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__    
    U32 subtitle_num;
    mdi_video_subtitle_info subtitle_info[MDI_VIDEO_MAX_SUBTITLE_NUM];
#endif  

    CHAR title_desc[MDI_VIDEO_CONTENT_BUFFER_SIZE];       /* Title information */
    CHAR artist_desc[MDI_VIDEO_CONTENT_BUFFER_SIZE];      /* Artist information */
    CHAR album_desc[MDI_VIDEO_CONTENT_BUFFER_SIZE];       /* Album information */
    CHAR author_desc[MDI_VIDEO_CONTENT_BUFFER_SIZE];      /* Author information */
    CHAR copyright_desc[MDI_VIDEO_CONTENT_BUFFER_SIZE];   /* Copyright information */
    CHAR date_desc[MDI_VIDEO_CONTENT_BUFFER_SIZE];        /* Date information */ 
} mdi_video_info_struct;

/* Video setting structure */
typedef struct
{
    U16 wb;                 /* Current white balance value cached in MDI-Video */
    U16 ev;                 /* Current EV value cached in MDI-Video */
    U16 banding;            /* Current camera banding value cached in MDI-Video */
    U16 effect;             /* Current effect value cached in MDI-Video */
    U16 zoom;               /* Current zoom value cached in MDI-Video */
    U16 brightness;         /* Current brightness value cached in MDI-Video */
    U16 contrast;           /* Current contrast value cached in MDI-Video */
    U16 saturation;         /* Current saturation value cached in MDI-Video */
    U16 hue;                /* Current hue value cached in MDI-Video */
    U16 preview_rotate;     /* Current preview rotate value cached in MDI-Video */
    U16 lcm_rotate;         /* Current lcm rotate value cached in MDI-Video */
    U16 night;              /* Current night mode value cached in MDI-Video */
    U16 flash;              /* Current flash light mode cached in MDI-Video */

    U16 dsc_mode;           /* Current scene mode value cached in MDI-Video */
    U16 af_operation_mode;  /* Current af operation mode value cached in MDI-Video */
    U16 af_range;           /* Current af range value cached in MDI-Video */
    U16 sharpness;          /* Current sharpness value cached in MDI-Video */
    U32 max_zoom_factor;    /* Current max zoom factor value cached in MDI-Video */
    U8 total_zoom_step;     /* Current total zoom sted cached in MDI-Video */

    U16 video_size;         /* Current video size cached in MDI-Video */
    U16 video_qty;          /* Current video quality cached in MDI-Video */
    U16 size_limit;         /* Current video limit of size cached in MDI-Video */
    U32 time_limit;         /* Current video time limit of size cached in MDI-Video */
    U16 record_aud;         /* Record audio or not flag cached in MDI-Video */
    U16 video_format;       /* Current video format cached in MDI-Video */
    U16 user_def_width;     /* User defined width cached in MDI-Video */
    U16 user_def_height;    /* User defined height cached in MDI-Video */

    BOOL overlay_frame_mode;            /* Overlay frame mode */
    U8 overlay_frame_depth;             /* Overlay frame depth */
    U8 overlay_frame_source_key;        /* Overlay frame source key */
    U16 overlay_frame_width;            /* Overlay frame width */
    U16 overlay_frame_height;           /* Overlay frame height */
    U32 overlay_frame_buffer_address;   /* Overlay frame buffer address */

    U16 peer_enc_qty;               /* Video Telephony: peer encode quality */
    BOOL notify_peer_on_camera_off; /* Video Telephony: notify peer when local camera is off */
    BOOL display_mirror;            /* Video Telephony: mirror display */
    U16  display_rotate;            /* Video Telephony: rotate display */

    U16 ui_rotate;         /* ui rotate angle */
    U16 storage;
    U32 encode_one_frame_duration; /* the duration for recording one frame [TimeLapse], ms */
} mdi_video_setting_struct;


#ifdef __MMI_OP11_PDL_FROM_SDP__
/* PDL sdp url structure */
typedef struct
{
    kal_char  url[MDI_SDP_MAX_URL_LEN];
    kal_uint32 byte_fsize;
    kal_bool   x_forward_allowed;
    kal_bool   x_purge;
}mdi_sdp_pdl_info;
#endif /* __MMI_OP11_PDL_FROM_SDP__ */


/*****************************************************************************
 * <GROUP CallBackFunctions>
 * FUNCTION
 *  mdi_record_result_callback
 * DESCRIPTION
 *  When recording, if there is any error or indication from media-task, MDI-Video module will invoke this callback function and pass the result to it.
 *  MMI application should handle this kind of error.
 * PARAMETERS
 *  ret: [IN] The result in MDI_RESULT enum type.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mdi_record_result_callback) (MDI_RESULT ret, void* user_data);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 * FUNCTION
 *  mdi_save_result_callback
 * DESCRIPTION
 *  When merging and saving recorded video data, if there is any error or indication from media-task, MDI-Video module will invoke this callback function and pass the result to MMI applications.
 *  MMI application should handle this kind of error.
 * PARAMETERS
 *  ret: [IN] The result in MDI_RESULT enum type.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mdi_save_result_callback) (MDI_RESULT ret, void* user_data);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 * FUNCTION
 *  mdi_open_result_callback
 * DESCRIPTION
 *  When open a file in async mode, if there is any error or indication (open succeefully) from media-task, MDI-Video module will invoke this callback function and pass the result to MMI appliactions.
 *  MMI application should handle this kind of error.
 * PARAMETERS
 *  ret : [IN] The result in MDI_RESULT enum type.
 *  video_info : [OUT] video information of this opened file, it will contain valid data if the open operation is succeeded.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mdi_open_result_callback)(MDI_RESULT ret, mdi_video_info_struct *video_info, void *user_data);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 * FUNCTION
 *  mdi_play_finish_callback
 * DESCRIPTION
 *  When playing a video, if there is any error or indication (finished playing) from media-task, MDI-Video module will invoke this callback function and pass the result to MMI applications.
 *  MMI application should handle this kind of error.
 * PARAMETERS
 *  ret: [IN] The result in MDI_RESULT enum type.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mdi_play_finish_callback) (MDI_RESULT ret, void *user_data);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 * FUNCTION
 *  mdi_seek_result_callback
 * DESCRIPTION
 *  When seeking, if there is any error or indication (finish seeking) from media-task, MDI-Video module will invoke this callback function and pass the result to MMI applications.
 *  MMI application should handle this kind of error.
 * PARAMETERS
 *  ret: [IN] The result in MDI_RESULT enum type.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mdi_seek_result_callback) (MDI_RESULT ret, void *user_data);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 * FUNCTION
 *  mdi_get_thumbnail_result_callback
 * DESCRIPTION
 *  When getting thumbnail, if there is any error or indication (finish seeking) from media-task, MDI-Video module will invoke this callback function and pass the result to MMI applications.
 *  MMI application should handle this kind of error.
 * PARAMETERS
 *  ret: [IN] The result in MDI_RESULT enum type.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mdi_get_thumbnail_result_callback) (MDI_RESULT ret);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 * FUNCTION
 *  mdi_merge_result_callback
 * DESCRIPTION
 *  When merge or encode video editors clips, if there is any error or indication (finish seeking) from media-task, MDI-Video module will invoke this callback function and pass the result to MMI applications.
 *  MMI application should handle this kind of error.
 * PARAMETERS
 *  ret: [IN] The result in MDI_RESULT enum type.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mdi_merge_result_callback) (MDI_RESULT ret);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 * FUNCTION
 *  mdi_progressive_result_callback
 * DESCRIPTION
 *  When open a progressive download file in async mode, if there is any error or indication (open succeefully) from media-task, MDI-Video module will invoke this callback function and pass the result to MMI appliactions.
 *  MMI application should handle this kind of error.
 * PARAMETERS
 *  ret : [IN] The result in MDI_RESULT enum type.
 *  video_info : [OUT] video information of this opened file, it will contain valid data if the open operation is succeeded.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mdi_progressive_result_callback) (MDI_RESULT ret , mdi_video_info_struct* video_info, void *user_data);


/*****************************************************************************
 * <GROUP CallBackFunctions>
 * FUNCTION
 *  mdi_connect_result_callback
 * DESCRIPTION
 *  When open a stream file in async mode, if there is any error or indication (open succeefully) from media-task, MDI-Video module will invoke this callback function and pass the result to MMI appliactions.
 *  MMI application should handle this kind of error.
 * PARAMETERS
 *  ret : [IN] The result in MDI_RESULT enum type.
 *  video_info : [OUT] video information of this opened file, it will contain valid data if the open operation is succeeded.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mdi_connect_result_callback)(MDI_RESULT ret, mdi_video_info_struct* video_info, void *user_data);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 * FUNCTION
 *  mdi_buffering_result_callback
 * DESCRIPTION
 *  When buffering video/audio data in async mode, if there is any error or indication (open succeefully) from media-task, MDI-Video module will invoke this callback function and pass the result to MMI appliactions.
 *  MMI application should handle this kind of error.
 * PARAMETERS
 *  ret : [IN] The result in MDI_RESULT enum type.
 *  video_info : [OUT] video information of this opened file, it will contain valid data if the open operation is succeeded.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mdi_buffering_result_callback)(MDI_RESULT ret, mdi_video_info_struct* video_info, void *user_data);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP CallBackFunctions>
 * FUNCTION
 *  mdi_event_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  codec_event : [IN]
 *  para : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mdi_video_tel_event_callback)(mdi_video_tel_codec_event_enum codec_event, S32 para, void* callback_userdata);
/* DOM-NOT_FOR_SDK-END */

/* Video get frame structure */
typedef struct
{
    gdi_handle player_layer_handle;
    gdi_handle subtitle_layer_handle;
} mdi_video_get_frame_struct;

/* Video seek structure */
typedef struct
{
    U64 time;    
    MMI_BOOL blocking;
    mdi_seek_result_callback seek_result_callback;
    void *user_data;

    /* get frame structure */
    MMI_BOOL get_frame;
    mdi_video_get_frame_struct frame;
} mdi_video_seek_struct;



/* Video play structure */
typedef struct
{
    gdi_handle player_layer_handle;
    gdi_handle subtitle_layer_handle;
    U32 blt_layer_flag;
    U32 play_layer_flag;
    U32 subtitle_layer_flag;
    U16 repeat_count;
    MMI_BOOL is_visual_update;
    MMI_BOOL is_play_audio;
    U8 audio_path;
    U16 rotate;
    S16 play_speed;
    mdi_play_finish_callback play_finish_callback;
    void *user_data;    
} mdi_video_play_struct;

/* Video update layer resume structure */
typedef struct
{
    gdi_handle player_layer_handle;
    gdi_handle subtitle_layer_handle;
    U32 blt_layer_flag;
    U32 play_layer_flag;
    U32 subtitle_layer_flag;
    BOOL is_visual_update;  
    U16 rotate;
} mdi_video_update_layer_resume_struct;


extern MMI_BOOL mdi_video_message_dispatcher(void *ilm_ptr);
extern void mdi_video_enable_mimic_task(module_type module_id);
extern void mdi_video_disable_mimic_task(void);

/**** RECORDER ****/
#if defined (__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_force_set_ui_rotate
 * DESCRIPTION
 *  To force set ui rotate as desired orientation.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_VDOREC_SUCCEED : Succeed to set camera id.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set camera id.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_force_set_ui_rotate(U16 rotate);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_reset_ui_rotate
 * DESCRIPTION
 *  To reset ui rotate as "don't care".
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_VDOREC_SUCCEED : Succeed to set camera id.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set camera id.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_reset_ui_rotate(void);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_frame_rate_table_query_num_of_entry
 * DESCRIPTION
 *  To get error string id and popup type enum by error code.
 * PARAMETERS
 *  void
 * RETURNS
 *  row number of frame rate table in U16.
 *****************************************************************************/
extern U32 mdi_video_rec_query_entry_num_of_video_spec_table(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_frame_rate_table_query_num_of_entry
 * DESCRIPTION
 *  To get error string id and popup type enum by error code.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_VDOREC_SUCCEED : Succeed to set camera id.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set camera id.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_get_video_spec_by_index(U32 idx, mdi_video_rec_spec_struct * p_spec_entry_struct, U32 frt_entry_struct_size);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_error_info
 * DESCRIPTION
 *  To get error string id and popup type enum by error code.
 * PARAMETERS
 *  error_code : [IN] error code got from MDI APIs
 *  popup_type : [OUT] popup_type of this error_code 
 * RETURNS
 *  string_id in MMI_ID_TYPE correspounding error enum.
 *****************************************************************************/
extern MMI_ID_TYPE mdi_video_rec_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_init
 * DESCRIPTION
 *  Initialize mdi video recorder.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to initialize video recorder.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to initialize video recorder.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_init(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_video_set_camera_id
 * DESCRIPTION
 *  Choose the camera sensor.
 * PARAMETERS
 *  camera_id : [IN] Camera sensor id [main or sub]
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to set camera id.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set camera id.
 *****************************************************************************/
extern MDI_RESULT mdi_video_set_camera_id(U16 camera_id);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_set_record_rotation
 * DESCRIPTION
 *  Set UI rotation value
 * PARAMETERS
 *  value           : [IN]    rotation value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_set_record_rotation(U8 value);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_detect_sensor_id
 * DESCRIPTION
 *  To detect camera sensor module id.
 * PARAMETERS
 *  cam_id : [IN] Main/Sub camera sensor id.
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to detect camera sensor module id.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to detect camera sensor module id.
 *****************************************************************************/
extern MDI_RESULT mdi_video_detect_sensor_id(U8 cam_id);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_start_fast_zoom
 * DESCRIPTION
 *  Start fast zoom [smooth zoom]
 * PARAMETERS
 *  zoom_in         : [IN]        Zoom in/out
 *  zoom_limit      : [IN]        MAX ZOOM FACTOR ==> 8x zoom should fill in 80.
 *  zoom_step       : [IN]        How many zoom step to be operated per zoomin/zoomout operation.
 *  zoom_speed      : [IN]        How many frame to be inserted in each zoomin/zoomout zoom step.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_start_fast_zoom(BOOL zoom_in, U8 zoom_limit, U8 zoom_step, U8 zoom_speed);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_stop_fast_zoom
 * DESCRIPTION
 *  Stop fast zoom
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_stop_fast_zoom(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_fast_zoom_factor
 * DESCRIPTION
 *  Get current zoom factor
 * PARAMETERS
 *  factor      : [OUT]   Zoom factor     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_get_fast_zoom_factor(U32 *factor);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_fast_zoom_step
 * DESCRIPTION
 *  Get current zoom factor
 * PARAMETERS
 *  step        : [OUT]   Zoom step    
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_get_fast_zoom_step(U32 *step);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_power_on
 * DESCRIPTION
 *  To power on recorder hw.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to power on camera module.
 *  MDI_RES_VDOREC_ERR_POWER_ON_FAILED : Fail to power on camera module.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_power_on(const U16 app_id);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_power_off
 * DESCRIPTION
 *  To power off recorder hw.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to power off camera module.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to power off camera module.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_power_off(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_start
 * DESCRIPTION
 *  To start recording.
 * PARAMETERS
 *  filename : [IN] Video clip's filename.
 *  record_result_callback : [IN] Record result callback function ptr.
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to start recording.
 *  MDI_RES_VDOREC_ERR_DISK_FULL : Fail to start recording due to disk is full.
 *  MDI_RES_VDOREC_ERR_WRITE_PROTECTION : Fail to start recording due to disk is in write protection mode.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to start recording due to open file fail.
 *  MDI_RES_VDOREC_ERR_RECORD_FAILED : Fail to start recording.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_record_start(S8 *filename, mdi_record_result_callback record_result_callback,void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_stop
 * DESCRIPTION
 *  To stop recording.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to stop recording.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to stop recording.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_record_stop(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_pause
 * DESCRIPTION
 *  To pause recording.
 * PARAMETERS
 *  stop_preview : [IN] To stop preview or not.
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to pause recording.
 *  MDI_RES_VDOREC_RECORD_ALREADY_STOP : Fail to pause recording due to it is already stopped.
 *  MDI_RES_VDOREC_REACH_SIZE_LIMIT : Fail to pause recording due to due to it is reached record size limitation (already stopped).
 *  MDI_RES_VDOREC_ERR_DISK_FULL : Fail to pause recording due to disk is full (already stopped).
 *  MDI_RES_VDOREC_ERR_PAUSE_FAILED : Fail to pause recording.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_record_pause(MMI_BOOL stop_preview);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_resume
 * DESCRIPTION
 *  To resume recording.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to resume recording.
 *  MDI_RES_VDOREC_RECORD_ALREADY_STOP : Fail to resume recording due to it is already stopped.
 *  MDI_RES_VDOREC_ERR_RESUME_FAILED : Fail to resume recording.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_record_resume(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_preview_start
 * DESCRIPTION
 *  To start preview for video recorder.
 * PARAMETERS
 *  preview_layer_handle : [IN] Layer handle of preview layer.
 *  blt_layer_flag : [IN] Blt out layer flag.
 *  preview_layer_flag : [IN] Preview layer flag.
 *  is_lcd_update : [IN] Update lcd or not.
 *  setting_p : [IN] Setting data.
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to start preview.
 *  MDI_RES_VDOREC_ERR_HW_NOT_READY : Fail to start preview.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_preview_start(
                    gdi_handle preview_layer_handle,
                    U32 blt_layer_flag,
                    U32 preview_layer_flag,
                    MMI_BOOL is_lcd_update,
                    mdi_video_setting_struct *setting_p);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_preview_stop
 * DESCRIPTION
 *  To stop preview or recorder.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to stop preview.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to stop preview.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_preview_stop(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_save_file
 * DESCRIPTION
 *  To merge and save file in non-blocking mode.
 * PARAMETERS
 *  filepath : [IN] Path to merge file.
 *  save_result_callback : [IN] Callback function for this operation.
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to send save request to media task.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to send save request to media task.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_save_file(S8 *filepath, mdi_save_result_callback save_result_callback, void* user_data);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_stop_save
 * DESCRIPTION
 *  To stop record saving.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to stop save operation.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to stop save operation.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_stop_save(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_has_unsaved_file
 * DESCRIPTION
 *  To check if there is an unsaved video clip.
 * PARAMETERS
 *  filepath : [IN] Path to check.
 * RETURN VALUES
 *  MMI_TRUE : There is unsaved video clip.
 *  MMI_FALSE : There is no unsaved video clip.
 *****************************************************************************/
extern BOOL       mdi_video_rec_has_unsaved_file(S8 *filepath);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_delete_unsaved_file
 * DESCRIPTION
 *  To delete unsaved video file.
 * PARAMETERS
 *  filepath : [IN] Path of unsaved video temp file to be deleted.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_delete_unsaved_file(S8 *filepath);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_cur_record_time
 * DESCRIPTION
 *  To get current recorded time.
 * PARAMETERS
 *  cur_record_time : [OUT] Current recorded time.
 * RETURNS
 *  void
 ****************************************************************************/
extern void mdi_video_rec_get_cur_record_time(U64 *cur_record_time);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_record_frame_num
 * DESCRIPTION
 *  To get current recorded frame num.
 * PARAMETERS
 *  cur_record_num : [OUT] Current recorded frame num.
 * RETURNS
 *  void
 ****************************************************************************/
void mdi_video_rec_get_record_frame_num(U64 *cur_record_num);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_flash_setting
 * DESCRIPTION
 *  Turn on/off LED flash light
 * PARAMETERS
 *  is_on       : [IN]    On/off 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_flash_setting(BOOL is_on);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_ev
 * DESCRIPTION
 *  To update ev setting value.
 * PARAMETERS
 *  para : [IN] Ev setting parameter.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_ev(U16 para);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_zoom
 * DESCRIPTION
 *  To update zoom setting value
 * PARAMETERS
 *  para : [IN] Zoom setting parameter.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_zoom(U16 para);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_effect
 * DESCRIPTION
 *  To update effect setting value.
 * PARAMETERS
 *  para : [IN] Effect setting parameter.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_effect(U16 para);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_wb
 * DESCRIPTION
 *  To update wb setting value.
 * PARAMETERS
 *  para : [IN] White balance setting parameter.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_wb(U16 para);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_night
 * DESCRIPTION
 *  To update night mode setting value
 * PARAMETERS
 *  para : [IN] Night mode setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_night(U16 para);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_rec_size
 * DESCRIPTION
 *  To update rec width & height
 * PARAMETERS
 *  image_width     : [IN]        record image width
 *  image_height    : [IN]        record image height
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_rec_size(U16 image_width, U16 image_height);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_saturation
 * DESCRIPTION
 *  Update saturation setting value
 * PARAMETERS
 *  cam_para        [IN]        Saturation setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_saturation(U16 para);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_contrast
 * DESCRIPTION
 *  Update contrast setting value
 * PARAMETERS
 *  cam_para        [IN]        Contrast setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_contrast(U16 para);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_sharpness
 * DESCRIPTION
 *  Update sharpness setting value
 * PARAMETERS
 *  cam_para        [IN]        Sharpness setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_sharpness(U16 para);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_hue
 * DESCRIPTION
 *  Update hue setting value
 * PARAMETERS
 *  cam_para        [IN]        Hue setting value
 * RETURNS
 *  void
 *****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
extern void mdi_video_rec_update_para_hue(U16 para);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_max_zoom_factor
 * DESCRIPTION
 *  To get max zoom factor based on resoultion
 * PARAMETERS
 *  record_width : [IN] Record size width
 *  record_height : [IN] Record size height
 * RETURNS
 *  Current zoom factor.
 *****************************************************************************/
extern U16 mdi_video_rec_get_max_zoom_factor(S32 record_width, S32 record_height);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_record_file_size
 * DESCRIPTION
 *  To get current record file size
 * PARAMETERS
*   void
 * RETURNS
 *  Current file size of the recording.
 *****************************************************************************/
extern U64 mdi_video_rec_get_record_file_size(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_load_default_setting
 * DESCRIPTION
 *  Initialize default setting value for video preview/record structure.
 * PARAMETERS
 *  setting_p : [OUT] Setting data (All member data in its default values).
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_load_default_setting(mdi_video_setting_struct *setting_p);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_enable_partial_display
 * DESCRIPTION
 *  To enable video to preview outside lcd region
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : To enable partially display record preview data.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to enable partially display record preview data.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_enable_partial_display(void);

#include "mdi_camera.h"

#define MDI_VIDEO_REC_AF_ZONE_MAX_NO 5      

#if (!defined(__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__))
/* The result of af */
typedef enum 
{
    MDI_AF_SEARCH_STATUS_IDLE=0,                /* Idle */
    MDI_AF_SEARCH_STATUS_BUSY,                  /* Busy */
    MDI_AF_SEARCH_STATUS_FOUND_FAIL,            /* Failed */
    MDI_AF_SEARCH_STATUS_FOUND_SUCCESS,         /* Success */
    MDI_AF_SEARCH_STATUS_FOUND_NOFOCUS,         /* No focus */
    MDI_AF_SEARCH_STATUS_SWITCH_MACRO           /* Switch to marco */   
}mdi_af_result_enum;
#endif

typedef struct
{
    mdi_af_result_enum af_result;   /* AF result */
    U32 af_success_zone;            /* AF success zone */
}mdi_video_rec_af_result_struct;

typedef struct
{
    U32 af_zone_w;      /* Width */
    U32 af_zone_h;      /* Height */
    U32 af_zone_x;      /* Offset x */
    U32 af_zone_y;      /* Offset y */
}mdi_video_rec_af_zone_struct;

typedef struct
{
    U32 af_active_zone;     /* Active zone */
    mdi_video_rec_af_zone_struct af_zone[MDI_VIDEO_REC_AF_ZONE_MAX_NO];   /* AF zone array */
}mdi_video_rec_af_window_struct;

/*****************************************************************************
 * <GROUP  CallBackFunctions>       
 *
 * FUNCTION
 *  mdi_video_rec_af_ind_callback
 * DESCRIPTION
 *  AF result callback
 * PARAMETERS
 *  result_ind      : [IN]     AF result structure
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void (*mdi_video_rec_af_ind_callback) (mdi_video_rec_af_result_struct result_ind, void* user_data);



/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_focus_zone
 * DESCRIPTION
 *  Get camera driver AF zone location for 6238 series and 
 *  the location coordinate is the preview layer not LCD 
 * PARAMETERS
 *  zone            : [OUT]       AF zone structure        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_get_focus_zone(mdi_video_rec_af_window_struct *zone);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_start_autofocus_process
 * DESCRIPTION
 *  Start to do auto focus process
 * PARAMETERS
 *  handler        : [IN]        Auto focus finish callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_start_autofocus_process(mdi_video_rec_af_ind_callback handler, void* user_data);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_stop_autofocus_process
 * DESCRIPTION
 *  Stop auto focus process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_stop_autofocus_process(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_af_key
 * DESCRIPTION
 *  Update af key value
 * PARAMETERS
 *  cam_para        : [IN]        AF key
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_af_key(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_af_mode
 * DESCRIPTION
 *  Update af mode value
 * PARAMETERS
 *  cam_para        : [IN]        AF mode
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_af_mode(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_af_metering
 * DESCRIPTION
 *  Update af metering value
 * PARAMETERS
 *  cam_para        : [IN]        AF metering
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_af_metering(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_af_range
 * DESCRIPTION
 *  Update af range value for 6238 series video_rec
 * PARAMETERS
 *  cam_para        : [IN]        AF range value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_af_range(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_af_operation_mode
 * DESCRIPTION
 *  Update af operation mode value for 6238 series video_rec
 * PARAMETERS
 *  cam_para        : [IN]        AF range value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_update_para_af_operation_mode(U16 cam_para);


void mdi_video_rec_af_finish_ind(void *inMsg);



#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
extern void mdi_video_rec_query_support_info(U32 mdi_setting_type, void *p_info);
extern void mdi_video_rec_query_zoom_info(mdi_camera_zoom_info *p_info);
#endif

#endif /* __MMI_VIDEO_RECORDER__ */

typedef struct
{
    U16 video_size;
    U16 quality;
    U16 storage;
    U16 video_format;
}mdi_video_rec_query_bitrate_struct;


extern MDI_RESULT mdi_video_rec_query_bitrate(mdi_video_rec_query_bitrate_struct* spec, U32* bitrate);

extern void mdi_video_rec_get_reserved_disc_size(U32 *size);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_blt_pause
 * DESCRIPTION
 *  Pause for update blt parameters, special function for Java use only; This function should be pariled with mdi_video_rec_resume_for_update_blt_para().
 * EXAMPLE
 *  mdi_video_rec_update_blt_pause();
 *  ....
 *  update related GDI layer configuration
 *  ....
 *  mdi_video_rec_update_blt_resume(); 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to pause to update blt layers.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to pause.
 *****************************************************************************/
extern MDI_RESULT mdi_video_rec_update_blt_pause(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_blt_resume
 * DESCRIPTION
 *  Resume for update blt parameters, special function for Java use only; This function should be pariled with mdi_video_rec_resume_for_update_blt_para().
 * EXAMPLE
 *  mdi_video_rec_update_blt_pause();
 *  ....
 *  update related GDI layer configuration
 *  ....
 *  mdi_video_rec_update_blt_resume();
 * PARAMETERS
 *  preview_layer_handle : [IN] Layer for preview.
 *  blt_layer_flag : [IN] Blt out layer flag.
 *  preview_layer_flag : [IN] Preview layer flag.
 *  is_lcd_update : [IN] Update lcd or not.
 * RETURNS
 *  MDI_RES_VDOREC_SUCCEED : Succeed to resume after updating blt layers.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to resume.
 *****************************************************************************/
 extern MDI_RESULT mdi_video_rec_update_blt_resume(
                    gdi_handle preview_layer_handle,
                    U32 blt_layer_flag,     
                    U32 preview_layer_flag, 
                    MMI_BOOL is_lcd_update);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_set_record_yuv
 * DESCRIPTION
 *  set to record YUV data
 * PARAMETERS
 *  is_yuv        : [IN]        TRUE or FALSE
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_rec_set_record_yuv(MMI_BOOL is_yuv);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_error_info
 * DESCRIPTION
 *  To get error string id and popup type enum by error code.
 * PARAMETERS
 *  error_code : [IN] Error code got from MDI APIs
 *  popup_type : [OUT] Popup_type of this error_code 
 * RETURNS
 *  string_id in MMI_ID_TYPE correspounding error enum.
 *****************************************************************************/
extern MMI_ID_TYPE mdi_video_ply_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_init
 * DESCRIPTION
 *  To initialize mdi video player.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to initialze video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to initialze video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_init(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_file
 * DESCRIPTION
 *  To open video file (non-blocking open).
 * PARAMETERS
 *  filename : [IN] Videe clip's full file name
 *  open_result_callback : [IN] Open file result callback function
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to open video file, need to wait callback function when open operation is finished.
 *  MDI_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to open video file due to drm is prohibited.
 *  MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : Fail to open video file due to memory is insufficient.
 *  MDI_RES_VDOPLY_ERR_FILE_TOO_LARGE : Fail to open video file due to file is too large.
 *  MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH : Fail to open video file due to framerate is too high.
 *  MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to open video file.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_open_file(
                    const U16 app_id,
                    const CHAR *filename,            
                    mdi_open_result_callback open_result_callback,
                    void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_close_file
 * DESCRIPTION
 *  To close video file.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to close video file.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to close video file.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_close_file(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_play
 * DESCRIPTION
 *  To start play opened video.
 * PARAMETERS
 *  player_layer_handle : [IN] Layer handle of playback layer.
 *  blt_layer_flag : [IN] Layers to blt to LCM
 *  play_layer_flag : [IN] Layer for HW to draw
 *  repeat_count : [IN] Repeat how many times.
 *  is_visual_update : [IN] To update to LCM or not.
 *  is_play_audio : [IN] To play audio or not.
 *  audio_path : [IN] Audio output path.
 *  rotate : [IN] Rotate.
 *  play_speed : [IN] Play speed.
 *  play_finish_callback : [IN] Callback function.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to start play.
 *  MDI_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to start play due to drm check is prohibited.
 *  MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH : Fail to start play due to the download data is not enough for progressive playback.
 *  MDI_RES_VDOPLY_REACH_STOP_TIME : Fail to start play due to it is stopped due to stop time is reached.
 *  MDI_RES_VDOPLY_ERR_PLAY_FAILED : Fail to start play.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_play(
                    gdi_handle player_layer_handle, 
                    U32 blt_layer_flag,
                    U32 play_layer_flag, 
                    U16 repeat_count, 
                    BOOL is_visual_update, 
                    BOOL is_play_audio,
                    U8 audio_path, 
                    U16 rotate, 
                    S16 play_speed, 
                    mdi_play_finish_callback play_finish_callback,
                    void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_stop
 * DESCRIPTION
 *  To stop video playing.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to stop player.
 *  MDI_RES_VDOPLY_ALREADY_FINISHED : Fail to stop player due to it is already stopped.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_stop(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_seek
 * DESCRIPTION
 *  To seek video.
 * PARAMETERS
 *  time : [IN] Seek time stamp.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to seek.
 *  MDI_RES_VDOPLY_SEEK_PARTIAL_DONE : Succeed to do partial seek.
 *  MDI_RES_VDOPLY_ERR_SEEK_FAILED : Fail to seek.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_seek(U64 time);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_seek_and_get_frame
 * DESCRIPTION
 *  To seek video and get seek frame.
 * PARAMETERS
 *  time : [IN] Seek time stamp.
 *  player_layer_handle : [IN] Get frame on this layer.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to seek.
 *  MDI_RES_VDOPLY_SEEK_PARTIAL_DONE : Succeed to do partial seek.
 *  MDI_RES_VDOPLY_ERR_SEEK_FAILED : Fail to seek.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_seek_and_get_frame(U64 time, gdi_handle player_layer_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_snapshot
 * DESCRIPTION
 *  To snapshot video and save as jpeg file.
 * PARAMETERS
 *  layer_handle : [IN] Video play layer.
 *  file_name : [IN] Filename for jpeg.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to snapshot.
 *  MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL : Fail to snapshot due to disk is full.
 *  MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION : Fail to snapshot due to the disk is in write protection mode.
 *  MDI_RES_VDOPLY_ERR_SNAPSHOT_FAILED : Fail to snapshot.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_snapshot(gdi_handle layer_handle, CHAR * file_name);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_cur_play_time
 * DESCRIPTION
 *  To get current play time.
 * PARAMETERS
 *  cur_play_time : [OUT] Current play time.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_ply_get_cur_play_time(U64 *cur_play_time);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_non_block_seek
 * DESCRIPTION
 *  To seek video.
 * PARAMETERS
 *  time : [IN] Seek time stamp
 *  seek_result_callback : [IN] Seek result callback function
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to seek.
 *  MDI_RES_VDOPLY_SEEK_PARTIAL_DONE : Succeed to do partial seek.
 *  MDI_RES_VDOPLY_ERR_SEEK_FAILED : Fail to seek.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_non_block_seek(U64 time, mdi_seek_result_callback seek_result_callback, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_non_block_seek_and_get_frame
 * DESCRIPTION
 *  To seek video and get seek frame by non-blocking mode.
 * PARAMETERS
 *  time : [IN] Seek time stamp
 *  player_layer_handle : [IN] Get frame on this layer.
 *  seek_result_callback : [IN] Seek result callback function.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to seek.
 *  MDI_RES_VDOPLY_SEEK_PARTIAL_DONE : Succeed to do partial seek.
 *  MDI_RES_VDOPLY_ERR_SEEK_FAILED : Fail to seek.
 *****************************************************************************/
 extern MDI_RESULT mdi_video_ply_non_block_seek_and_get_frame(
                    U64 time,
                    gdi_handle player_layer_handle,
                    mdi_seek_result_callback seek_result_callback,
                    void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_stop_non_block_seek
 * DESCRIPTION
 *  To stop non block seeking.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to stop non-blocking seek.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to stop non-blocking seek.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_stop_non_block_seek(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_frame
 * DESCRIPTION
 *  get seek frame.
 * PARAMETERS
 *  player_layer_handle : [IN]Get frame on this layer.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get frame.
 *  MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED : Fail to get frame
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_get_frame(gdi_handle player_layer_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_brightness
 * DESCRIPTION
 *  To set brightness parameter for video player.
 * PARAMETERS
 *  brightness : [IN] Brightness value
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set brightness parameter to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set brightness parameter to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_set_brightness(U16 brightness);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_contrast
 * DESCRIPTION
 *  To set contrast parameter to video player.
 * PARAMETERS
 *  contrast : [IN] Contrast value
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set EV parameter to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set EV parameter to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_set_contrast(U16 contrast);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_default_frame_color_format
 * DESCRIPTION
 *  get default frame color format
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GDI_COLOR_FORMAT_16 : RGB565
 *  GDI_COLOR_FORMAT_UYVY422 : UYVY422
 *****************************************************************************/
extern U32 mdi_video_ply_get_default_frame_color_format(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_track_index
 * DESCRIPTION
 *  Set track index
 * PARAMETERS
 *  index : [IN] track index
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set track index
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_set_track_index(U32 index);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_subtitle_track_index
 * DESCRIPTION
 *  Set subtitle track index
 * PARAMETERS
 *  index : [IN] subtitle track index
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set subtitle track index
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_set_subtitle_track_index(U32 index);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_subtitle_font_size
 * DESCRIPTION
 *  Set subtitle font size
 * PARAMETERS
 *  size : [IN] subtitle font size
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set subtitle font size
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_set_subtitle_font_size(U8 size);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_key_frame_time
 * DESCRIPTION
 *  Get key frame time
 * PARAMETERS
 *  time : [IN] input time
 *  dir : [IN] search direction
 *  key_frame_time: [OUT] the largest key frame time less than input time if dir is MDI_VIDEO_SEARCH_DIR_BACKWARD 
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get key frame time
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to get key frame time
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_get_key_frame_time(U64 time, mdi_video_search_dir_enum dir, U64 *key_frame_time);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_mot_meta
 * DESCRIPTION
 *  To get MOT meta
 * PARAMETERS
 *  meta : [IN] MOT meta.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get mot meta
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to get mot meta
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_get_mot_meta(mdi_video_mot_meta_struct *info);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_enable_partial_display
 * DESCRIPTION
 *  To enable video to play outside lcd region.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to enable partial display (outside lcd region) to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to enable partial display (outside lcd region) to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_enable_partial_display(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_stop_time
 * DESCRIPTION
 *  Set stop time, currently for Java use only.
 * PARAMETERS
 *  stop_time : [IN] Stop time
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set stop time to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set stop time to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_set_stop_time(U64 stop_time);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_frame_mode
 * DESCRIPTION
 *  Set frame mode
 * PARAMETERS
 *  mode : [IN] frame mode
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set stop time to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set stop time to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_set_frame_mode(U8 mode);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_sleep_time
 * DESCRIPTION
 *  Set sleep time, currently for Java use only.
 * PARAMETERS
 *  elapse_ticks : [IN] elapse ticks
 *  sleep_ticks  : [IN] sleep ticks
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set stop time to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set stop time to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_set_sleep_time(U8 elapse_ticks, U8 sleep_ticks);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_time_to_frame
 * DESCRIPTION
 *  This function is to map given time to the frame number.
 * PARAMETERS
 *  time : [IN] given timestamp 
 *  frame : [OUT] the frame index  
 * RETURNS
 *  MDI_RES_VDOPLY_SUCCEED : Succeed 
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_get_time_to_frame(U64 time, U32 *frame);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_frame_to_time
 * DESCRIPTION
 *  This function is to map given frame to the frame timestamp.
 * PARAMETERS
 *  frame : [IN] given frame index
 *  time  : [OUT] the timestamp of the given frame index        
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_get_frame_to_time(U32 frame, U64 *time);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_audio_level
 * DESCRIPTION
 *  To set audio level, used by Java only
 * PARAMETERS
 *  aud_level : [IN] Audio level. 
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set audio level to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set audio level to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_set_audio_level(U16 aud_level);

#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_drm_check_permission
 * DESCRIPTION
 *  To check if a video file has DRM permission
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Has permission
 *  MDI_RES_VDOPLY_ERR_DRM_PROHIBITED: No Permission
 *  MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to open file.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_drm_check_permission(const CHAR *filename);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_drm_disable_consume_count
 * DESCRIPTION
 *  Do not consume drm count when next time play.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to disable drm consume count function.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to disable drm consume count function.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_drm_disable_consume_count(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_drm_disable_consume_time
 * DESCRIPTION
 *  Do not consume drm time when play
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to disable drm consume time function.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to disable drm consume time function.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_drm_disable_consume_time(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_drm_disable_time_limit_stop
 * DESCRIPTION
 *  Do not consume drm time limit for next time play.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to disable time limit stop check.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to disable time limit stop check.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_drm_disable_time_limit_stop(void);
#endif /*  __DRM_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_is_drm_file
 * DESCRIPTION
 *  Check if it is drm file or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : It is a drm file.
 *  MMI_FALSE : It is not a drm file.
 *****************************************************************************/
extern MMI_BOOL mdi_video_ply_is_drm_file(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_check_is_able_to_play
 * DESCRIPTION
 *  Check is able to play or not .
 * PARAMETERS
 *  file_name : [IN] Filename of the specific video file to be checked.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : This file is able to play.
 *  MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : This file is not able to play due to memory is not enough.
 *  MDI_RES_VDOPLY_ERR_FAILED : This file is not able to play.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_check_is_able_to_play(CHAR *file_name);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_clip_file
 * DESCRIPTION
 *  To open video clip, this is a blocking function, will return untill file is opened.
 * PARAMETERS
 *  filename : [IN] Video clip's full file name
 *  info : [OUT] Video clip's info
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to open video file, need to wait callback function when open operation is finished.
 *  MDI_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to open video file due to drm is prohibited.
 *  MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : Fail to open video file due to memory is insufficient.
 *  MDI_RES_VDOPLY_ERR_FILE_TOO_LARGE : Fail to open video file due to file is too large.
 *  MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH : Fail to open video file due to framerate is too high.
 *  MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to open video file.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_open_clip_file(
                    const U16 app_id,
                    const CHAR *filename, 
                    mdi_video_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_close_clip_file
 * DESCRIPTION
 *  To close video clip.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to close video clip file.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to close video clip file.
 *****************************************************************************/
#define mdi_video_ply_close_clip_file mdi_video_ply_close_file

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_clip_id
 * DESCRIPTION
 *  To open video clip.
 * PARAMETERS
 *  video_id : [IN] Video clip resource id
 *  info : [OUT] Video clip's info
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to start play.
 *  MDI_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to start play due to drm check is prohibited.
 *  MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH : Fail to start play due to the download data is not enough for progressive playback.
 *  MDI_RES_VDOPLY_REACH_STOP_TIME : Fail to start play due to it is stopped due to stop time is reached.
 *  MDI_RES_VDOPLY_ERR_PLAY_FAILED : Fail to start play.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_open_clip_id(
                    const U16 app_id,
                    U16 video_id, 
                    mdi_video_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_close
 * DESCRIPTION
 *  To close video
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to close video file.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to close video file.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_close(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_close_clip_id
 * DESCRIPTION
 *  To close video clip from id.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to close video clip id.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to close video clip id.
 *****************************************************************************/
#define mdi_video_ply_close_clip_id mdi_video_ply_close


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_clip_buffer
 * DESCRIPTION
 *  To open video clip from buffer.
 * PARAMETERS
 *  file_buffer : [IN] Video clip file buffer
 *  buffer_len : [IN] Video clip's buffer size
 *  info : [OUT] Video clip's info
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to open video buffer, need to wait callback function when open operation is finished.
 *  MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : Fail to open video buffer due to memory is insufficient.
 *  MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH : Fail to open video buffer due to framerate is too high.
 *  MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to open video file.
 *****************************************************************************/
 extern MDI_RESULT mdi_video_ply_open_clip_buffer(
                    const U16 app_id,
                    const U8 *file_buffer,
                    const U32 buffer_len,
                    mdi_video_info_struct *info);
                    
/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_close_clip_buffer
 * DESCRIPTION
 *  To close video clip from buffer
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to close video clip buffer.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to close video clip buffer.
 *****************************************************************************/
#define mdi_video_ply_close_clip_buffer mdi_video_ply_close

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_enable_aud_only_video_clip
 * DESCRIPTION
 *  To enable playing aud only video file 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to enable playing audio only video clip
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to enable playing audio only video clip
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_enable_aud_only_video_clip(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_scenario_type
 * DESCRIPTION
 *  To set scenario type
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to enable playing audio only video clip
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to enable playing audio only video clip
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_set_scenario_type(mdi_video_scenario_type_enum scenario);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_update_layer_pause
 * DESCRIPTION
 *  To pause for update layer parameters. It's a pecial function for Java & WAP use only; 
 *  This function should be pariled with mdi_video_ply_update_layer_resume().
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to pause to update blt layers.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to pause.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_update_layer_pause(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_update_layer_resume
 * DESCRIPTION
 *  Resume for update blt parameters. It's a special function for Java & WAP use only;
 *  This function should be pariled with mdi_video_ply_update_layer_pause().
 * PARAMETERS
 *  player_layer_handle : [IN] Layer handle of playback layer.
 *  blt_layer_flag : [IN] Layers to blt to LCM
 *  play_layer_flag : [IN] Layer for HW to draw
 *  is_visual_update : [IN] To update to LCM or not.
 *  rotate : [IN] Rotate.
 * RETURNS
 *  MDI_RES_VDOREC_SUCCEED : Succeed to resume after updating blt layers.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to resume.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_update_layer_resume(
            gdi_handle player_layer_handle,
            U32 blt_layer_flag, 
            U32 play_layer_flag,
            BOOL is_visual_update,
            U16 rotate);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_default_seek_setting
 * DESCRIPTION
 *  The function is to get the default value for the seek structure
 * PARAMETERS
 *  seek : [OUT] The seek structure for mdi_video_ply_seek_ex()
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_ply_get_default_seek_setting(mdi_video_seek_struct *seek);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_seek_ex
 * DESCRIPTION
 *  The function is a combo function to seek
 * PARAMETERS
 *  seek : [IN] seek parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_seek_ex(mdi_video_seek_struct *seek);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_default_get_frame_setting
 * DESCRIPTION
 *  The function is to get the default value for the get frame structure
 * PARAMETERS
 *  frame : [OUT] The get frame structure for mdi_video_ply_get_frame_ex()
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_ply_get_default_get_frame_setting(mdi_video_get_frame_struct *frame);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_frame_ex
 * DESCRIPTION
 *  The function is a combo function to get frame
 * PARAMETERS
 *  frame : [IN] get frame parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_get_frame_ex(mdi_video_get_frame_struct *frame);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_default_play_setting
 * DESCRIPTION
 *  The function is to get the default value for the play structure
 * PARAMETERS
 *  play : [OUT] The play structure for mdi_video_ply_play_ex()
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_ply_get_default_play_setting(mdi_video_play_struct *play);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_play_ex
 * DESCRIPTION
 *  The function is a combo function to play
 * PARAMETERS
 *  play : [IN] play parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_play_ex(mdi_video_play_struct *play);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_default_resume_setting
 * DESCRIPTION
 *  The function is to get the default value for the resume structure
 * PARAMETERS
 *  resume : [OUT] The resume structure for mdi_video_ply_update_layer_resume_ex()
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_ply_get_default_resume_setting(mdi_video_update_layer_resume_struct *resume);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_update_layer_resume_ex
 * DESCRIPTION
 *  The function is a combo function to update layer resume
 * PARAMETERS
 *  resume : [IN] resume parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_update_layer_resume_ex(mdi_video_update_layer_resume_struct *resume);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_is_playing
 * DESCRIPTION
 *  To check video player is currently playing or not
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : Video is playing now.
 *  MMI_FALSE : Video is not playing now.
 *****************************************************************************/
extern BOOL mdi_video_is_playing(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_check_proc_func
 * DESCRIPTION
 *  To check video player is currently playing or not
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_RET_OK : Video is not playing now.
 *  MMI_RET_ERR : Video is playing now.
 *****************************************************************************/
extern mmi_ret mdi_video_check_proc_func(mmi_event_struct *event);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_is_recording
 * DESCRIPTION
 *  Toc check video recorder is currently recording or not
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : Video is recording now.
 *  MMI_FALSE : Video is not recording now.
 *****************************************************************************/
extern BOOL mdi_video_is_recording(void);



/**** Streaming ****/
#ifdef __MMI_VIDEO_STREAM__
/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_init
 * DESCRIPTION
 *  To initialize video streaming module.
 * PARAMETERS
 *  app_id
 * RETURNS
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to initialize video streaming module.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to initialize video streaming module.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_init(const U16 app_id);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_deinit
 * DESCRIPTION
 *  To de-initialze video streaming module.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to de-initialize video streaming module.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to de-initialize video streaming module.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_deinit(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_scenario
 * DESCRIPTION
 *  To set scenario type
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set scenario type
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set scenario type
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_scenario(mdi_video_scenario_type_enum scenario);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_prefer_transport
 * DESCRIPTION
 *  To get prefer RTP transport
 * PARAMETERS
 *  mdi_video_stream_transport_type_enum *type
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get prefer RTP transport
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to get prefer RTP transport
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_get_prefer_transport(mdi_video_stream_transport_type_enum *type);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_prefer_transport
 * DESCRIPTION
 *  To set prefer RTP transport
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set prefer RTP transport
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set prefer RTP transport
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_prefer_transport(mdi_video_stream_transport_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_connect
 * DESCRIPTION
 *  blah
 * PARAMETERS
 *  data_account : [IN] 
 *  stream_type : [IN] 
 *  data_path : [IN] 
 *  use_proxy : [IN] 
 *  proxy : [IN] a string of proxy address
 *  port : [IN] 
 *  use_udp_port : [IN] 
 *  highest_udp_port : [IN]  
 *  lowest_udp_port : [IN] 
 *  connect_result_callback : [IN] 
 *  user_data : [IN] user_data for Callback function.
 * RETURNS
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to connect to server.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to connect to server.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_connect(
                    U32 data_account, 
                    mdi_video_stream_type_enum stream_type, 
                    CHAR *data_path,
                    MMI_BOOL use_proxy,
                    CHAR *proxy,
                    U16 port,
                    MMI_BOOL use_udp_port,
                    U16 highest_udp_port,
                    U16 lowest_udp_port,
                    mdi_connect_result_callback connect_result_callback,
                    void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_disconnect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to disconnect to server.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to disconnect to server.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_disconnect(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_is_connected
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : It is connected with stream server.
 *  MMI_FALSE : It is not connected with stream server.
 *****************************************************************************/
extern MMI_BOOL   mdi_video_stream_is_connected(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_start_buffering
 * DESCRIPTION
 *  Start buffering.
 * PARAMETERS
 *  time : [IN] 
 *  buffering_result_callback : [IN] 
 *  user_data : [IN] user_data for Callback function.
 * RETURNS
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to start buffering.
 *  MDI_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to start buffering due to drm check is prohibited.
 *  MDI_RES_VDOPLY_REACH_STOP_TIME : Fail to start buffering due to it is stopped due to stop time is reached.
 *  MDI_RES_VDOPLY_ERR_PLAY_FAILED : Fail to start buffering.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_start_buffering(
                    U64 time, 
                    mdi_buffering_result_callback buffering_result_callback,
                    void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_stop_buffering
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to stop buffering.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to stop buffering.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_stop_buffering(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_play
 * DESCRIPTION
 *  To start play streaming video.
 * PARAMETERS
 *  player_layer_handle : [IN]Layer handle of playback layer.
 *  blt_layer_flag : [IN]Layers to blt to LCM
 *  play_layer_flag : [IN]Layer for HW to draw
 *  is_visual_update : [IN]To update to LCM or not.
 *  audio_path : [IN]Audio output path.
 *  rotate : [IN]Rotate.
 *  play_finish_callback : [IN]Callback function.
 *  user_data : [IN] user_data for Callback function.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to start play.
 *  MDI_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to start play due to drm check is prohibited.
 *  MDI_RES_VDOPLY_REACH_STOP_TIME : Fail to start play due to it is stopped due to stop time is reached.
 *  MDI_RES_VDOPLY_ERR_PLAY_FAILED : Fail to start play.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_play(
                    gdi_handle player_layer_handle, 
                    U32 blt_layer_flag,
                    U32 play_layer_flag, 
                    MMI_BOOL is_visual_update, 
                    U8 audio_path, 
                    U16 rotate, 
                    mdi_play_finish_callback play_finish_callback,
                    void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to stop play.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to stop play.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_stop(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_pause
 * DESCRIPTION
 *  To pause play stream video.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to pause stream play.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to pause stream play.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_pause(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_resume
 * DESCRIPTION
 *  To resume playing streaming video
 * PARAMETERS
 *  player_layer_handle : [IN]Layer handle of playback layer.
 *  blt_layer_flag : [IN]Layers to blt to LCM
 *  play_layer_flag : [IN]Layer for HW to draw
 *  is_visual_update : [IN]To update to LCM or not.
 *  audio_path : [IN]Audio output path.
 *  rotate : [IN]Rotate.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to resume stream play.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to resume stream play.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_resume(
                    gdi_handle player_layer_handle, 
                    U32 blt_layer_flag,
                    U32 play_layer_flag, 
                    MMI_BOOL is_visual_update, 
                    U8 audio_path, 
                    U16 rotate);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_drm_disable_consume_count
 * DESCRIPTION
 *  Do not consume drm count when play.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to disable consume drm count for next playing.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to disable consume drm count for next playing.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_drm_disable_consume_count(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_drm_disable_consume_time
 * DESCRIPTION
 *  Do not consume drm count when play
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to disable consume drm time limitation for next playing.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to disable consume drm time limitation for next playing.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_drm_disable_consume_time(void);      

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_buf_percentage
 * DESCRIPTION
 *  ooxx
 * PARAMETERS
 *  percentage : [OUT] stream buffer percentage.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get buffer percentage of the stream downloaded data.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to get buffer percentage of the stream downloaded data.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_get_buf_percentage(S32 *percentage);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_buf_status
 * DESCRIPTION
 *  ooxx
 * PARAMETERS
 *  buffered_time : [OUT] stream buffered absolute time.
 *  buffer_percentage : [OUT] fullness percentage of stream buffer pool.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get buffer status of the stream downloaded data.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to get buffer status of the stream downloaded data.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_get_buf_status(U64 *buffered_time, U32 *buffer_percentage);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_cur_play_time
 * DESCRIPTION
 * 
 * PARAMETERS
 *  cur_play_time : [OUT] Current play time.
 * RETURNS
 *  void
 *****************************************************************************/
extern void       mdi_video_stream_get_cur_play_time(U64 *cur_play_time);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_brightness
 * DESCRIPTION
 *  To set brightness parameter for video player.
 * PARAMETERS
 *  brightness : [IN] Brightness value
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set brightness parameter to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set brightness parameter to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_brightness(U16 brightness);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_contrast
 * DESCRIPTION
 *  To set contrast parameter to video player.
 * PARAMETERS
 *  contrast : [IN] Contrast value
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set EV parameter to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set EV parameter to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_contrast(U16 contrast);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_dimension
 * DESCRIPTION
 *  Get stream source dimension, this function may only be called after 
 *  calling mdi_video_stream_start_buffering, and buf percentage > 0
 * PARAMETERS
 *  video_width : [OUT] video width ptr
 *  video_height : [OUT] video height ptr 
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get dimension.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to get dimension.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_get_dimension(S32 *video_width, S32 *video_height);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_enable_partial_display
 * DESCRIPTION
 *  To enable video to play outside lcd region.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to enable partial display (outside lcd region) to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to enable partial display (outside lcd region) to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_enable_partial_display(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_frame_mode
 * DESCRIPTION
 *  To set stretch mode of video player before playback.
 * PARAMETERS
 *  mode : [IN] frame mode
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set stretch mode of video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set stretch mode of video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_frame_mode(U8 mode);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_3d_mode
 * DESCRIPTION
 *  Set 3D mode
 * PARAMETERS
 *  mode : [IN] 3D mode
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set 3D mode to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set 3D mode to video player.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_3d_mode(mdi_video_3d_mode_enum mode);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_prebuffer_time
 * DESCRIPTION
 *  To set the pre-buffer time that application want.
 * PARAMETERS
 *  U32 time: [IN] the pre-buffer time in millisecond. (min. 3000 ms)
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set pre-buffer time of video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set pre-buffer time of video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_prebuffer_time(U32 time);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_stop_time
 * DESCRIPTION
 *  Set stop time for stream playback, currently for Java use only.
 * PARAMETERS
 *  stop_time : [IN] Stop time
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set stop time to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set stop time to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_stop_time(U64 stop_time);
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_sleep_time
 * DESCRIPTION
 *  Set sleep time, currently for Java use only.
 * PARAMETERS
 *  elapse_ticks : [IN] elapse time to make one sleep operation.
 *  sleep_ticks  : [IN] time duration per sleep.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set sleep time to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set sleep time to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_sleep_time(U8 elapse_ticks, U8 sleep_ticks);
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_audio_level
 * DESCRIPTION
 *  To set audio level, used by Java only
 * PARAMETERS
 *  aud_level : [IN] Audio level. 
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set audio level to video player.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to set audio level to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_audio_level(U16 aud_level);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_is_drm_streaming
 * DESCRIPTION
 *  Check if it is drm stream or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : It is a drm file.
 *  MMI_FALSE : It is not a drm file.
 *****************************************************************************/
extern MMI_BOOL   mdi_video_stream_is_drm_streaming(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_info
 * DESCRIPTION
 *  To get stream audio info.
 * PARAMETERS
 *  aud_channel_no : [IN] Audio channel number.
 *  aud_sample_rate : [IN] Audio sample rate.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get audio info.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to get audio info.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_get_audio_info(PU8 aud_channel_no, PU16 aud_sample_rate);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_stop_visual_update()
 * DESCRIPTION
 * Stop video update while not stopping the streaming playback. (audio will keep playing)
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to stop visual update.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to stop visual update.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_stop_visual_update(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_track
 * DESCRIPTION
 *  Enable user to config which track shall the streaming engine play. The possible values are
 *  MEDIA_STREAM_PLAY_TYPE_BOTH (both track)
 *  MEDIA_STREAM_PLAY_TYPE_AUDIO_ONLY (audio track)
 *  MEDIA_STREAM_PLAY_TYPE_VIDEO_ONLY (video track)
 * PARAMETERS
 *  type : [IN] 
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set track.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to set track.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_track(kal_uint8 type);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *    mdi_video_stream_set_uaprof_diff
 * DESCRIPTION
 *    set the x-wap-profile-diff url string
 * PARAMETERS
 *    diff_p : [IN] pointer to the profile diff url string (char)
 * RETURNS
 *    MEI_RES_VDOPLY_SUCEED : if success, otherwise MDI_RES_VDOPLY_ERR_FAILED
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_uaprof_diff(CHAR* diff_p);
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_STREAM_REC__
/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_rec_open
 * DESCRIPTION
 *  Open the record engine and assigned the target filepath
 * PARAMETERS
 *  p_file_path : [IN] the filepath of saving the recorded file
 * RETURN VALUES
 *  MDI_RES_STREAM_REC_ERR_DISK_FULL : The assigned disk is fulled.
 *  MDI_RES_STREAM_REC_SUCCEED : Open succeed.
 *  MED_RES_STREAM_INVALID_SDP : The SDP is an invalid one.
 *  MED_RES_STREAM_UNSUPPORTED_CODEC : We don't support recording of this codec.
 *  MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT : This video is not supported.
 *  MDI_RES_STREAM_REC_ERR_FAILED : Other undefined errors.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_rec_open(CHAR* p_file_path);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_rec_close
 * DESCRIPTION
 *  Close the record engine and clean up
 * PARAMETERS
 *  none
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed.
 *  MDI_RES_VDORLY_ERR_FAILED : Failed.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_rec_close(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_rec_save
 * DESCRIPTION
 *  Save the record video in the assigned path.
 * PARAMETERS
 *  p_file_path : [IN] The filepath of saved files.
 *  save_result_callback : [IN] The callback function, which will return the result of saving
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set track.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to set track.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_rec_save(CHAR* p_file_path, void(* save_result_callback)(MDI_RESULT));


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_rec_save_abort
 * DESCRIPTION
 *  Abort the current saving process.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Abort succesfully
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_rec_save_abort(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_rec_delete_unsaved_file
 * DESCRIPTION
 *  Remove the unsaved temp files in the assigned path
 * PARAMETERS
 *  dir : [IN] The filepath to be cleaned.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Deleted successfully.
 *****************************************************************************/
extern void mdi_video_stream_rec_delete_unsaved_file(CHAR* dir);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_rec_have_unsaved_file
 * DESCRIPTION
 *  Check if the assigned path have unsaved recording file or not
 * PARAMETERS
 *  dir : [IN] The path to check
 * RETURN VALUES
 *  KAL_TRUE : There is unsaved file.
 *  KAL_FALSE : There's no unsaved file.
 *****************************************************************************/
extern BOOL mdi_video_stream_rec_have_unsaved_file(CHAR* dir);
#endif /* __MMI_STREAM_REC__ */
/* DOM-NOT_FOR_SDK-END */
#endif /* __MMI_VIDEO_STREAM__ */


/**** Progressive ****/
#ifdef __MMI_VIDEO_PDL__
 /*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_open_file
 * DESCRIPTION
 *  To open progressive vidoe file.
 * PARAMETERS
 *  filename : [IN] Filename of the video.
 *  progressive_result_callback : [IN] Callback function of this open operation.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to open video file, need to wait callback function when open operation is finished.
 *  MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : Fail to open video file due to memory is insufficient.
 *  MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to open video file.
 *****************************************************************************/
extern MDI_RESULT mdi_video_progressive_open_file(
                    const U16 app_id,
                    const CHAR *filename,
                    mdi_progressive_result_callback progressive_result_callback,
                    void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_close_file
 * DESCRIPTION
 *  To close the progressive video file.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to close progressive download file.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to close progressive download file.
 *****************************************************************************/
extern MDI_RESULT mdi_video_progressive_close_file(void);                    

/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_get_max_play_time
 * DESCRIPTION
 *  To get the max play time of this progressive downloading file.
 * PARAMETERS
 *  max_play_time : [OUT] Max play time of this progressive downloading file.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get max play time.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to get max play time.
 *****************************************************************************/
extern MDI_RESULT mdi_video_progressive_get_max_play_time(U64 *max_play_time);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_get_buf_percentage
 * DESCRIPTION
 *  To get current downloaded buffer percentage.
 * PARAMETERS
 *  buf_percentage : [OUT] Current buffer percentage.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get buffer percentage.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to get buffer percentage.
 *****************************************************************************/
extern MDI_RESULT mdi_video_progressive_get_buf_percentage(S32 *buf_percentage);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_is_pdl_format
 * DESCRIPTION
 *  To check if this video file is in progresssive download support format.
 * PARAMETERS
 *  file_buf : [IN] Filepath of the specific video file.
 *  buf_size : [IN] Buffer size of the file buffer.
 *  is_pdl : [OUT] Is this file is progressive download format.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to check this file.
 *  MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to check this file due to fail to open it.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to check this file.
 *****************************************************************************/
extern MDI_RESULT mdi_video_progressive_is_pdl_format(U8 *file_buf, S32 buf_size, MMI_BOOL *is_pdl);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_scramble_buffer
 * DESCRIPTION
 *  To scramble buffer
 * PARAMETERS
 *  file_buffer : [IN]Filepath of the specific video file.
 *  buf_size : [IN]Buffer size of the file buffer.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to check this file.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to check this file.
 *****************************************************************************/
extern MDI_RESULT mdi_video_progressive_scramble_buffer(U8 *file_buffer, S32 buf_size);

/* DOM-NOT_FOR_SDK-END */

#endif /* __MMI_VIDEO_PDL__ */


/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_VIDEO_TELEPHONY__

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_load_default_setting
 * DESCRIPTION
 *  Initialize default setting value for video preview/record structure.
 * PARAMETERS
 *  setting_p : [OUT]Setting data (All member data in its default values).
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_tel_load_default_setting(mdi_video_setting_struct *setting_p);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_start
 * DESCRIPTION
 *  To start video telephony preview / decode
 * PARAMETERS
 *  peer_layer_handle : [IN] peer display layer handle
 *  local_layer_handle : [IN] local display layer handle 
 *  peer_disp_type : [IN] peer display type
 *  local_disp_type : [IN] local display type
 *  blt_layer_flag : [IN] which layers will be blt to lcd by driver
 *  peer_layer_flag : [IN] which layer is for peer display
 *  local_layer_flag : [IN] which layer is for local display 
 *  local_preview_setting_p : [IN] local preview video settings
 *  event_callback : [IN] call back function
 * RETURN VALUES
 *  MDI_RES_VDOTEL_SUCCEED : Succeed to start video telephony service.
 *  MDI_RES_VDOTEL_ERR_FAILED : Fail to start video telephony service.
 *****************************************************************************/
extern MDI_RESULT mdi_video_tel_start(
                    gdi_handle peer_layer_handle,
                    gdi_handle local_layer_handle,    
                    mdi_video_tel_disp_type_enum peer_disp_type,
                    mdi_video_tel_disp_type_enum local_disp_type,          
                    U32 blt_layer_flag,                                 
                    U32 peer_layer_flag,                                
                    U32 local_layer_flag,                                             
                    mdi_video_setting_struct *local_preview_setting_p,  
                    const U16 app_id,                       
                    mdi_video_tel_event_callback event_callback,
                    void* callback_userdata); 

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_resume
 * DESCRIPTION
 *  To resume video telephony preview / decode
 * PARAMETERS
 *  peer_layer_handle : [IN] peer display layer handle
 *  local_layer_handle : [IN] local display layer handle 
 *  peer_disp_type : [IN] peer display type
 *  local_disp_type : [IN] local display type
 *  blt_layer_flag : [IN] which layers will be blt to lcd by driver
 *  peer_layer_flag : [IN] which layer is for peer display
 *  local_layer_flag : [IN] which layer is for local display 
 *  local_preview_setting_p : [IN] local preview video settings
 *  event_callback : [IN] call back function
 * RETURN VALUES
 *  MDI_RES_VDOTEL_SUCCEED : Succeed to start video telephony service.
 *  MDI_RES_VDOTEL_ERR_FAILED : Fail to start video telephony service.
 *****************************************************************************/
extern MDI_RESULT mdi_video_tel_resume(
                    gdi_handle peer_layer_handle,
                    gdi_handle local_layer_handle,    
                    mdi_video_tel_disp_type_enum peer_disp_type,
                    mdi_video_tel_disp_type_enum local_disp_type,          
                    U32 blt_layer_flag,                                 
                    U32 peer_layer_flag,                                
                    U32 local_layer_flag,                                                  
                    mdi_video_setting_struct *local_preview_setting_p,  
                    mdi_video_tel_event_callback event_callback,
                    void* callback_userdata); 

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_pause
 * DESCRIPTION
 *  To pause video telephony preview / decode
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOTEL_SUCCEED : Succeed to stop video telephony service.
 *  MDI_RES_VDOTEL_ERR_FAILED : Fail to stop video telephony service.
 *****************************************************************************/
extern MDI_RESULT mdi_video_tel_pause(void); 

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_stop
 * DESCRIPTION
 *  To stop video telephony preview / decode
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOTEL_SUCCEED : Succeed to stop video telephony service.
 *  MDI_RES_VDOTEL_ERR_FAILED : Fail to stop video telephony service.
 *****************************************************************************/
extern MDI_RESULT mdi_video_tel_stop(void); 

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_set_memory_param
 * DESCRIPTION
 *  To set memory config before start (memory usage is related to window size now)
 * PARAMETERS
 *  U32 main wnd width
 *  U32 main wnd height
 *  U32 sub wnd width
 *  U32 sub wnd height
 * RETURN VALUES
 *  MDI_RES_VDOTEL_SUCCEED : Succeed to set id.
 *  MDI_RES_VDOTEL_ERR_FAILED : Fail to set id.
 *****************************************************************************/
extern MDI_RESULT mdi_video_tel_set_memory_param(
    kal_bool is_set, 
    kal_uint32 main_wnd_width, 
    kal_uint32 main_wnd_height, 
    kal_uint32 sub_wnd_width, 
    kal_uint32 sub_wnd_height);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_set_camera_id
 * DESCRIPTION
 *  To set sensor id for preview
 * PARAMETERS
 *  U16 sensor id
 * RETURN VALUES
 *  MDI_RES_VDOTEL_SUCCEED : Succeed to set id.
 *  MDI_RES_VDOTEL_ERR_FAILED : Fail to set id.
 *****************************************************************************/
extern MDI_RESULT mdi_video_tel_set_camera_id(U16 camera_id);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_query_support_info
 * DESCRIPTION
 *  To query sensor info
 * PARAMETERS
 *  U32     info type
 *  void*   return info
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mdi_video_tel_query_support_info(U32 mdi_setting_type, void *p_info);    

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_query_zoom_info
 * DESCRIPTION
 *  To query zoom info
 * PARAMETERS
 *  mdi_camera_zoom_info*  return zoom info
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mdi_video_tel_query_zoom_info(mdi_camera_zoom_info *p_info);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_bypass_3a_stable
 * DESCRIPTION
 *  Bypass 3a stable when start preview
 * PARAMETERS
 *  none
 * RETURNS
 *  void
 *****************************************************************************/
extern void       mdi_video_tel_bypass_3a_stable(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_hw_layer_get_content
 * DESCRIPTION
 *  Get preview buffer content.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_video_tel_get_hw_layer_buffer_content(gdi_handle layer_handle, U8 *dst_buff_p, U32 dst_buff_size);

extern MDI_RESULT mdi_video_tel_get_peer_content(U8 *dst_buff_p, U32 dst_buff_size);

extern MDI_RESULT mdi_video_tel_get_local_content(U8 *dst_buff_p, U32 dst_buff_size);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_update_para_ev
 * DESCRIPTION
 *  To update ev setting value.
 * PARAMETERS
 *  para : [IN] Ev setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern void       mdi_video_tel_update_para_ev(U16 para);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_update_para_contrast
 * DESCRIPTION
 *  To update contrast setting value.
 * PARAMETERS
 *  para : [IN] contrast setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_video_tel_update_para_contrast(U16 para);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_update_para_zoom
 * DESCRIPTION
 *  To update zoom setting value.
 * PARAMETERS
 *  para : [IN] zoom setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern void       mdi_video_tel_update_para_zoom(U16 para);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_enable_vt_loopback
 * DESCRIPTION
 *  Enable VT task start loopback, this function is for UT use only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void       mdi_video_tel_enable_vt_loopback(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_disable_vt_loopback
 * DESCRIPTION
 *  Disable VT task start loopback, this function is for UT use only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void       mdi_video_tel_disable_vt_loopback(void);

typedef struct
{
    LOCAL_PARA_HDR 
} mdi_vt_loopback_active_req_struct;


typedef struct
{
    LOCAL_PARA_HDR 
} mdi_vt_loopback_deactive_req_struct;

#endif /* __MMI_VIDEO_TELEPHONY__ */
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_OP11_PDL_FROM_SDP__
/*****************************************************************************
 * FUNCTION
 *  mdi_sdp_open_pdl_sdp_file
 * DESCRIPTION
 *  Open and check a sdp file to check if it is a progressive download SDP file
 * PARAMETERS
 *  fp_p : [IN] File path
 *  pdl_info : [OUT] Related info of this SDP file.
 * RETURNS
 *  MDI_RES_SDP_ERR_OPEN_FILE_FAILED : Cannot open the file.
 *  MDI_RES_SDP_SUCCEED : The SDP file is a progressive download SDP file, parsed successfully.
 *  MDI_RES_SDP_ERR_FILE_TOO_LARGE : This SDP file is too large to be valid.
 *  MDI_RES_SDP_MEMORY_NOT_ENOUGH : The memory is not enough to parse it.
 *  MDI_RES_SDP_INVALID_FORMAT : This is not a valid SDP.
 *  MDI_RES_SDP_NON_PDL_FORMAT : This is a valid SDP, however, it is not for progressive download.
 *****************************************************************************/
extern mdi_result mdi_sdp_open_pdl_sdp_file(kal_wchar *fp_p, mdi_sdp_pdl_info *pdl_info);
#endif /* __MMI_OP11_PDL_FROM_SDP__ */
/* DOM-NOT_FOR_SDK-END */

#endif /* _MDI_VIDEO_H */ 

