/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  mdi_camera.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Camera interfce header file
 *
 * Author:
 * -------
 * -------
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by P4 VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 02 18 2013 tokiya.chang
 * removed!
 * .
 *
 * 12 20 2012 tokiya.chang
 * removed!
 * .
 * 
 * 08 08 2012 cathytr.huang
 * removed!
 * .
 *
 * 06 21 2012 cathytr.huang
 * removed!
 * .
 *
 * 06 21 2012 cathytr.huang
 * removed!
 * .
 *
 * 06 12 2012 cathytr.huang
 * removed!
 * .
 *
 * 06 08 2012 cathytr.huang
 * removed!
 * .
 *
 * 05 31 2012 cathytr.huang
 * removed!
 * .
 *
 * 05 17 2012 cathytr.huang
 * removed!
 * .
 *
 * 03 23 2012 cathytr.huang
 * removed!
 * .
 *
 * 03 15 2012 cathytr.huang
 * removed!
 * .
 *
 * 03 06 2012 cathytr.huang
 * removed!
 * .
 *
 * 03 01 2012 cathytr.huang
 * removed!
 * .
 *
 * 02 24 2012 cathytr.huang
 * removed!
 * .
 *
 * 02 23 2012 cathytr.huang
 * removed!
 * .
 *
 * 02 08 2012 cathytr.huang
 * removed!
 * .
 *
 * 12 28 2011 cathytr.huang
 * removed!
 * .
 *
 * 12 20 2011 cathytr.huang
 * removed!
 * .
 *
 * 11 28 2011 cathytr.huang
 * removed!
 * .
 *
 * 11 01 2011 cathytr.huang
 * removed!
 * .
 *
 * 10 09 2011 tokiya.chang
 * removed!
 * .
 *
 * 09 29 2011 cathytr.huang
 * removed!
 * .
 *
 * 09 05 2011 cathytr.huang
 * removed!
 * .
 *
 * 08 24 2011 cathytr.huang
 * removed!
 * .
 *
 * 05 31 2011 tokiya.chang
 * removed!
 * .
 *
 * 05 18 2011 cathytr.huang
 * removed!
 * .
 *
 * 05 17 2011 cathytr.huang
 * removed!
 * .
 *
 * 05 17 2011 cathytr.huang
 * removed!
 * .
 *
 * 05 13 2011 cathytr.huang
 * removed!
 * .
 *
 * 05 10 2011 cathytr.huang
 * removed!
 * .
 *
 * 04 29 2011 cathytr.huang
 * removed!
 * .
 *
 * 04 28 2011 cathytr.huang
 * removed!
 * .
 *
 * 04 28 2011 cathytr.huang
 * removed!
 * .
 *
 * 04 19 2011 cathytr.huang
 * removed!
 * .
 *
 * 04 12 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 25 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 09 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 07 2011 cathytr.huang
 * removed!
 * .
 *
 * 03 04 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 23 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 22 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 16 2011 cathytr.huang
 * removed!
 * .
 *
 * 02 08 2011 cathytr.huang
 * removed!
 * Add cam get buffer content operation.
 *
 * 01 14 2011 cathytr.huang
 * removed!
 * .
 *
 * 01 05 2011 cathytr.huang
 * removed!
 * .
 *
 * 01 04 2011 cathytr.huang
 * removed!
 * .
 *
 * 12 30 2010 cathytr.huang
 * removed!
 * .
 *
 * 12 26 2010 cathytr.huang
 * removed!
 * .
 *
 * 12 16 2010 cathytr.huang
 * removed!
 * .
 *
 * 12 14 2010 cathytr.huang
 * removed!
 * Add panorama new API and revise profiling.
 *
 * 12 07 2010 cathytr.huang
 * removed!
 * .
 *
 * 12 07 2010 bin.han
 * removed!
 * .Rename camera capture profiling enum
 *
 * 11 23 2010 cathytr.huang
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by P4 VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MDI_CAMERA_H_
#define _MDI_CAMERA_H_

#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

#include "mdi_datatype.h"
#include "med_api.h"
#include "cal_comm_def.h"
#include "fd_comm_def.h"
#include "med_struct.h"
#include "jpeg_enum.h"
#include "img_common_enum.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gdi_include.h"
#include "mmi_frm_events_gprot.h"
#include "cal_feature_option.h"
#include "gdi_features.h"
#include "drv_sw_features_mdp.h"
#include "mm_comm_def.h"

#if defined(XENON_FLASHLIGHT_ANTI_RED_EYE) || defined(XENON_FLASHLIGHT)
#define __MDI_CAMERA_XENON_FLASH_SUPPORT__
#endif

#if defined(__FACE_DETECTION_SUPPORT__)
#define __MDI_CAMERA_FD_SUPPORT__
#endif

#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
#define __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__
#endif

#if defined(__MDI_CAMERA_FD_SUPPORT__)
#define MDI_CAMERA_FD_MAX_NO CAMERA_FD_MAX_NO       /* The number of face that face detection supports */
#else
#define MDI_CAMERA_FD_MAX_NO 1
#endif

#if defined(GDI_LCD_PALETTE_SUPPORT_RGB_888) && defined(MDP_SUPPORT_HW_OVERLAP)
#define __MDI_CAMERA_ADDFRAME_SUPPORT__
#endif

#ifdef __CAL_CAPTURE_MODE_BSS_SUPPORT__
#define __MDI_CAMERA_BESTSHOT_SUPPORT__
#endif

#ifdef __CAL_CAPTURE_MODE_EV_BRACKET_SUPPORT__
#define __MDI_CAMERA_EV_BRACKETING_SUPPORT__
#endif

#ifdef __HIGH_DYNAMIC_RANGE_SUPPORT__
#define __MDI_CAMERA_HDR_SUPPORT__
#endif

#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__) || defined(__3D_IMAGE_SUPPORT__)
#define __MDI_CAMERA_MAV_SUPPORT__
#endif

#ifndef __LOW_COST_SUPPORT_COMMON__
#define __MDI_CAMERA_BURSTSHOT_SUPPORT__
#define __MDI_CAMERA_PROFILING_SUPPORT__
#define __MDI_CAMERA_GET_PREDICT_IMGSIZE_SUPPORT__
#endif

#ifndef __LOW_COST_SUPPORT_ULC__
#define __MDI_CAMERA_GET_BUFFER_CONTENT_SUPPORT__
#endif

/***************************************************************************** 
* Define
*****************************************************************************/
#define MDI_CAMERA_SETTING_CAPMODE      CAL_FEATURE_CAMERA_STILL_CAPTURE_MODE
#define MDI_CAMERA_SETTING_CAMSCENE     CAL_FEATURE_CAMERA_SCENE_MODE
#define MDI_CAMERA_SETTING_CAPSIZE      CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE
#define MDI_CAMERA_SETTING_BANDING      CAL_FEATURE_CAMERA_BANDING_FREQ
#define MDI_CAMERA_SETTING_FLASH        CAL_FEATURE_CAMERA_FLASH_MODE
#define MDI_CAMERA_SETTING_AFRANGE      CAL_FEATURE_CAMERA_AF_RANGE_CONTROL
#define MDI_CAMERA_SETTING_ISO          CAL_FEATURE_CAMERA_BINNING_INFO
#define MDI_CAMERA_SETTING_WB           CAL_FEATURE_CAMERA_WB
#define MDI_CAMERA_SETTING_EFFECT       CAL_FEATURE_CAMERA_IMAGE_EFFECT
#define MDI_CAMERA_SETTING_AFMODE       CAL_FEATURE_CAMERA_AF_OPERATION_MODE
#define MDI_CAMERA_SETTING_AEMETER      CAL_FEATURE_CAMERA_AE_METERING_MODE
#define MDI_CAMERA_SETTING_SHARPNESS    CAL_FEATURE_CAMERA_SHARPNESS
#define MDI_CAMERA_SETTING_CONTRAST     CAL_FEATURE_CAMERA_CONTRAST
#define MDI_CAMERA_SETTING_SATURATION   CAL_FEATURE_CAMERA_SATURATION
#define MDI_CAMERA_SETTING_EV           CAL_FEATURE_CAMERA_EV_VALUE
#define MDI_CAMERA_SETTING_ZOOM         CAL_FEATURE_CAMERA_DIGITAL_ZOOM
#define MDI_CAMERA_SETTING_VIDEOSCENE   CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE
#define MDI_CAMERA_SETTING_CAP_OVERLAY  CAL_FEATUER_CAMERA_CAPTURE_OVERLAY_CAPABILITY
#define MDI_CAMERA_SETTING_ZSD_CAPSIZE  CAL_FEATURE_CAMERA_ZSD_CAPTURE_SIZE
#define MDI_CAMERA_SETTING_CAPSIZE_WITH_DIMENSION      CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE_WITH_DIMENSION

#define MDI_CAMERA_UI_ROTATE_0      MM_IMAGE_ROTATE_0
#define MDI_CAMERA_UI_ROTATE_90     MM_IMAGE_ROTATE_90         /**< clock-wise  90 degree. */
#define MDI_CAMERA_UI_ROTATE_180    MM_IMAGE_ROTATE_180        /**< clock-wise 180 degree. */
#define MDI_CAMERA_UI_ROTATE_270    MM_IMAGE_ROTATE_270        /**< clock-wise 270 degree. */
#define MDI_CAMERA_UI_ROTATE_0_WITH_LCD_CONFIG  MM_IMAGE_ROTATE_0_WITH_LCD_CONFIG

#define MDI_CAMERA_SUPPORT_ITEM_MAX_NO  (CAMERA_SUPPORT_ITEM_MAX_NO)
typedef struct
{
    kal_bool is_support;                                    /* Is this camera function supportable ? */
    kal_uint32 item_count;                                  /* The number of the workable item */
    kal_uint32 support_item[CAMERA_SUPPORT_ITEM_MAX_NO];    /* The enum of workable item */
}mdi_camera_sensor_general_info;                            /* for mdi_camera_query_support_info */

typedef struct
{
    kal_uint16 image_width;
    kal_uint16 image_height;
    
}mdi_camera_capture_image_size_info;

typedef struct
{
    kal_bool is_support;                                    /* Is this camera function supportable ? */
    kal_uint32 item_count;                                  /* The number of the workable item */
    kal_uint32 support_item[CAMERA_SUPPORT_ITEM_MAX_NO];    /* The enum of workable item */
    mdi_camera_capture_image_size_info image_size[CAMERA_SUPPORT_ITEM_MAX_NO];      /* extra information */
}mdi_camera_sensor_capture_resolution_info; 


typedef struct
{
    BINNING_INFO_STRUCT IsoBinningInfo[CAM_NO_OF_ISO];    
}mdi_camera_sensor_iso_binning_info;                        /* for mdi_camera_query_support_info */

typedef mdi_camera_sensor_general_info mdi_camera_fun_info;

typedef struct
{
    kal_bool is_support;
}mdi_camera_capture_overlay_info;

typedef struct
{
    U8  zoom_support_type;  
    U16 zoom_steps;         /* The number of the total zoom steps */
    U16 max_zoom_factor;    /* The maximum zoom factor */
}mdi_camera_zoom_info;

typedef enum
{
    MDI_CAMERA_SD_ON_READY_TO_CAPTURE,
    MDI_CAMERA_SD_ON_FAILED,
    MDI_CAMERA_SD_ON_CANCEL
}mdi_camera_sd_event_enum;


typedef struct mdi_camera_sd_event_struct mdi_camera_sd_event_struct;

/* The structure of face detection zone description */
typedef struct mdi_camera_fd_zone_struct
{
//    U32 fd_id;          /* The ID for detected face */
//    U8  fd_priority;    /* The priority for detected face */
    U32 fd_zone_x;      /* The offset x of the dected face in preview window coordinate */
    U32 fd_zone_y;      /* The offset y of the dected face in preview window coordinate */
    U32 fd_zone_w;      /* The width of the dected face in preview window coordinate */
    U32 fd_zone_h;      /* The height of the dected face in preview window coordinate */

#if defined(__SMILE_SHUTTER_SUPPORT__)
//    MMI_BOOL sd_detected_flag;
    U32 sd_zone_x;      /* The offset x of the dected face in preview window coordinate */
    U32 sd_zone_y;      /* The offset y of the dected face in preview window coordinate */
    U32 sd_zone_w;      /* The width of the dected face in preview window coordinate */
    U32 sd_zone_h;      /* The height of the dected face in preview window coordinate */
#endif
}mdi_camera_fd_zone_struct;


struct mdi_camera_sd_event_struct{

    mdi_camera_sd_event_enum event;   
    mdi_camera_fd_zone_struct fd_zone[MDI_CAMERA_FD_MAX_NO];
    U8 fd_searched_num;        /* The number of found face */ 
    U8 smile_detected_num;
};

/*****************************************************************************
 * <GROUP  CallBackFunctions>       
 *
 * FUNCTION
 *  mdi_camera_on_sd_event_cb
 * DESCRIPTION
 *  Smile Detection decode callback
 * PARAMETERS
 *  sd_event_p      : [IN]     event structure of smile shot process.
 *  user_data       : [IN]     user data
 * RETURN VALUE
 *  void
 *****************************************************************************/
 typedef void (*mdi_camera_on_sd_event_cb) (mdi_camera_sd_event_struct* sd_event_p, void* user_data);



/* The structure of face detection result */
typedef struct
{
    MDI_RESULT fd_result;       /* Face detection result */               
    U32 fd_searched_num;        /* The number of found face */ 

#if defined(__SMILE_SHUTTER_SUPPORT__)
    MMI_BOOL sd_end_flag;
    U8 sd_searched_num;
#endif    

    mdi_camera_fd_zone_struct fd_zone[MDI_CAMERA_FD_MAX_NO];    /* The array of face detection zone */ 
}mdi_camera_fd_result_ind_struct, mdi_camera_fd_result_struct ;


typedef enum
{
    MDI_CAMERA_RAWDATA_RGB565 = 0,
    MDI_CAMERA_RAWDATA_YUV420
}mdi_camera_raw_data_format_enum;



/*****************************************************************************
 * <GROUP  CallBackFunctions>       
 *
 * FUNCTION
 *  mdi_camera_fd_callback
 * DESCRIPTION
 *  Face detection callback
 * PARAMETERS
 *  result_ind      : [IN]     Face detection result structure
 *  user_data       : [IN]     user data
 * RETURN VALUE
 *  void
 *****************************************************************************/
typedef void (*mdi_camera_fd_callback)(mdi_camera_fd_result_ind_struct* result_ind, void* user_data);


/* Parameters settings - mapping to media(driver's setting) */
#define MDI_CAMERA_MAIN     CAL_CAMERA_SOURCE_MAIN     /* Main camera sensor */
#define MDI_CAMERA_SUB      CAL_CAMERA_SOURCE_SUB      /* Sub camera sensor */

/* EV +4 */
#define MDI_CAMERA_EV_P4                        CAM_EV_POS_4_3
/* EV +3 */
#define MDI_CAMERA_EV_P3                        CAM_EV_POS_3_3
/* EV +2 */
#define MDI_CAMERA_EV_P2                        CAM_EV_POS_2_3
/* EV +1 */
#define MDI_CAMERA_EV_P1                        CAM_EV_POS_1_3
/* EV 0 */
#define MDI_CAMERA_EV_0                         CAM_EV_ZERO
/* EV -1 */
#define MDI_CAMERA_EV_N1                        CAM_EV_NEG_1_3
/* EV -2 */
#define MDI_CAMERA_EV_N2                        CAM_EV_NEG_2_3
/* EV -3 */
#define MDI_CAMERA_EV_N3                        CAM_EV_NEG_3_3
/* EV -4 */
#define MDI_CAMERA_EV_N4                        CAM_EV_NEG_4_3
/* EV total number */
#define MDI_CAMERA_EV_COUNT                     CAM_NO_OF_EV

/* Effect - normal */
#define MDI_CAMERA_EFFECT_NOMRAL                CAM_EFFECT_ENC_NORMAL
/* Effect - grayscale */
#define MDI_CAMERA_EFFECT_GRAYSCALE             CAM_EFFECT_ENC_GRAYSCALE
/* Effect - sepia */
#define MDI_CAMERA_EFFECT_SEPIA                 CAM_EFFECT_ENC_SEPIA
/* Effect - sepiagreen */
#define MDI_CAMERA_EFFECT_SEPIA_GREEN           CAM_EFFECT_ENC_SEPIAGREEN
/* Effect - sepiablue */
#define MDI_CAMERA_EFFECT_SEPIA_BLUE            CAM_EFFECT_ENC_SEPIABLUE
/* Effect - color invert */
#define MDI_CAMERA_EFFECT_COLOR_INVERT          CAM_EFFECT_ENC_COLORINV
/* Effect - gray invert */
#define MDI_CAMERA_EFFECT_GRAY_INVERT           CAM_EFFECT_ENC_GRAYINV
/* Effect - black board */
#define MDI_CAMERA_EFFECT_BLACKBOARD            CAM_EFFECT_ENC_BLACKBOARD
/* Effect - white board */
#define MDI_CAMERA_EFFECT_WHITEBOARD            CAM_EFFECT_ENC_WHITEBOARD
/* Effect - copper carving */
#define MDI_CAMERA_EFFECT_COPPER_CARVING        CAM_EFFECT_ENC_COPPERCARVING
/* Effect - blue arving */
#define MDI_CAMERA_EFFECT_BLUE_CARVING          CAM_EFFECT_ENC_BLUECARVING
/* Effect - embossment */
#define MDI_CAMERA_EFFECT_EMBOSSMENT            CAM_EFFECT_ENC_EMBOSSMENT
/* Effect - contrast */
#define MDI_CAMERA_EFFECT_CONTRAST              CAM_EFFECT_ENC_CONTRAST
/* Effect - jean */
#define MDI_CAMERA_EFFECT_JEAN                  CAM_EFFECT_ENC_JEAN
/* Effect - sketch */
#define MDI_CAMERA_EFFECT_SKETCH                CAM_EFFECT_ENC_SKETCH
/* Effect - oil */
#define MDI_CAMERA_EFFECT_OIL                   CAM_EFFECT_ENC_OIL
/* Effect - lomo effect */
#define MDI_CAMERA_EFFECT_LOMO                  CAM_EFFECT_ENC_LOMO
/* Effect - color accent red */
#define MDI_CAMERA_EFFECT_COLOR_RED             CAM_EFFECT_ENC_COLOR_RED
/* Effect - color accent yellow */
#define MDI_CAMERA_EFFECT_COLOR_YELLOW          CAM_EFFECT_ENC_COLOR_YELLOW
/* Effect - color accent green */
#define MDI_CAMERA_EFFECT_COLOR_GREEN           CAM_EFFECT_ENC_COLOR_GREEN
/* Effect - color accent blue */
#define MDI_CAMERA_EFFECT_COLOR_BLUE            CAM_EFFECT_ENC_COLOR_BLUE
/* Effect total number */
#define MDI_CAMERA_EFFECT_COUNT                 CAM_NO_OF_EFFECT_ENC

/* WB - auto */
#define MDI_CAMERA_WB_AUTO                      CAM_WB_AUTO
/* WB - daylight */
#define MDI_CAMERA_WB_DAYLIGHT                  CAM_WB_DAYLIGHT
/* WB - tungsten */
#define MDI_CAMERA_WB_TUNGSTEN                  CAM_WB_TUNGSTEN
/* WB - fluorescent */
#define MDI_CAMERA_WB_FLUORESCENT               CAM_WB_FLUORESCENT
/* WB - cloud */
#define MDI_CAMERA_WB_CLOUD                     CAM_WB_CLOUD
/* WB - incandescence */
#define MDI_CAMERA_WB_INCANDESCENCE             CAM_WB_INCANDESCENCE
/* WB - manual */
#define MDI_CAMERA_WB_MANUAL                    CAM_WB_MANUAL
/* WB - total number */
#define MDI_CAMERA_WB_COUNT                     CAM_NO_OF_WB

/* Banding 50HZ */
#define MDI_CAMERA_BANDING_50HZ                 CAM_BANDING_50HZ
/* Banding 60HZ */
#define MDI_CAMERA_BANDING_60HZ                 CAM_BANDING_60HZ
/* Banding total number */
#define MDI_CAMERA_BANDING_COUNT                CAM_NO_OF_BANDING

/* Image quality fine */
#define MDI_CAMERA_JPG_QTY_FINE                 JPEG_ENCODE_QUALITY_EXCELLENT
/* Image quality high */
#define MDI_CAMERA_JPG_QTY_HIGH                 JPEG_ENCODE_QUALITY_GOOD
/* Image quality normal */
#define MDI_CAMERA_JPG_QTY_NORMAL               JPEG_ENCODE_QUALITY_FAIR
/* Image quality low */
#define MDI_CAMERA_JPG_QTY_LOW                  JPEG_ENCODE_QUALITY_LOW
/* Image quality poor */
#define MDI_CAMERA_JPG_QTY_POOR                 JPEG_ENCODE_QUALITY_POOR
/* Image quality total number */
#define MDI_CAMERA_JPG_QTY_COUNT                (5)    

/* Flash off */
#define MDI_CAMERA_FLASH_OFF                    CAM_FLASH_OFF
/* Flash on */
#define MDI_CAMERA_FLASH_ON                     CAM_FLASH_ON
/* Flash auto */
#define MDI_CAMERA_FLASH_AUTO                   CAM_FLASH_AUTO
/* Flash redeye */
#define MDI_CAMERA_FLASH_REDEYE                 CAM_FLASH_REDEYE
/* Flash total number */
#define MDI_CAMERA_FLASH_COUNT                  CAM_NO_OF_FLASH

/* AE meter auto */
#define MDI_CAMERA_AE_METER_AUTO                CAM_AE_METER_AUTO
/* AE meter spot */
#define MDI_CAMERA_AE_METER_SPOT                CAM_AE_METER_SPOT
/* AE meter central */
#define MDI_CAMERA_AE_METER_CENTER              CAM_AE_METER_CENTRAL
/* AE meter average */
#define MDI_CAMERA_AE_METER_AVERAGE             CAM_AE_METER_AVERAGE
/* AE meter total number */
#define MDI_CAMERA_AE_METER_COUNT               CAM_NO_OF_AE_METERING


/* Scene mode - auto */
#define MDI_CAMERA_SCENE_MODE_AUTO                  CAM_AUTO_DSC
/* Scene mode - portrait */
#define MDI_CAMERA_SCENE_MODE_PORTRAIT              CAM_PORTRAIT
/* Scene mode - landscape */
#define MDI_CAMERA_SCENE_MODE_LANDSCAPE             CAM_LANDSCAPE
/* Scene mode - sport */
#define MDI_CAMERA_SCENE_MODE_SPORT                 CAM_SPORT
/* Scene mode - flower */
#define MDI_CAMERA_SCENE_MODE_FLOWER                CAM_FLOWER
/* Scene mode - night */
#define MDI_CAMERA_SCENE_MODE_NIGHT                 CAM_NIGHTSCENE
/* Scene mode - backlight */
#define MDI_CAMERA_SCENE_MODE_BACKLIGHT             CAM_BACKLIGHT
/* Scene mode - backlight portriat*/
#define MDI_CAMERA_SCENE_MODE_BACKLIGHT_PORTRAIT    CAM_BACKLIGHT_PORTRAIT
/* Scene mode - night portriat*/
#define MDI_CAMERA_SCENE_MODE_NIGHT_PORTRAIT        CAM_NIGHT_PORTRAIT
/* Scene mode - document */
#define MDI_CAMERA_SCENE_MODE_DOCUMENT              CAM_DOCUMENT
/* Scene mode - ISO anti-handshake */
#define MDI_CAMERA_SCENE_MODE_ISO_ANTI_HAND_SHAKE   CAM_ISO_ANTI_HAND_SHAKE
/* Scene mode - video auto */
#define MDI_CAMERA_SCENE_MODE_VIDEO_AUTO            CAM_VIDEO_AUTO
/* Scene mode - video night */
#define MDI_CAMERA_SCENE_MODE_VIDEO_NIGHT           CAM_VIDEO_NIGHT
/* Scene mode - total number */
#define MDI_CAMERA_SCENE_MODE_COUNT                 CAM_NO_OF_SCENE_MODE

/* ISO auto */
#define MDI_CAMERA_ISO_AUTO                     CAM_ISO_AUTO
/* ISO 100 */
#define MDI_CAMERA_ISO_100                      CAM_ISO_100
/* ISO 200 */
#define MDI_CAMERA_ISO_200                      CAM_ISO_200
/* ISO 400 */
#define MDI_CAMERA_ISO_400                      CAM_ISO_400
/* ISO 800 */
#define MDI_CAMERA_ISO_800                      CAM_ISO_800
/* ISO 1600 */
#define MDI_CAMERA_ISO_1600                     CAM_ISO_1600

#define MDI_CAMERA_ISO_COUNT                    CAM_NO_OF_ISO

/* AF off */
#define MDI_CAMERA_AF_OPERATION_MODE_OFF                  CAM_AF_OFF
/* AF single zone */
#define MDI_CAMERA_AF_OPERATION_MODE_SINGLE_ZONE          CAM_AF_SINGLE_ZONE
/* AF multi zone */
#define MDI_CAMERA_AF_OPERATION_MODE_MULTI_ZONE           CAM_AF_MULTI5_ZONE
/* AF continuous */
#define MDI_CAMERA_AF_OPERATION_MODE_CONTINUOUS           CAM_AF_CONTINUOUS
/* AF total number */
#define MDI_CAMERA_AF_OPERATION_MODE_COUNT                CAM_NO_OF_AF_MODE

/* The maximum number of af zone */
#define MDI_CAMERA_AF_ZONE_MAX_NO 5         

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

/* AF range auto */
#define MDI_CAMERA_AF_RANGE_AUTO                CAM_AF_RANGE_AUTO
/* AF range marco */
#define MDI_CAMERA_AF_RANGE_MACRO               CAM_AF_RANGE_MACRO
/* AF range landscape */
#define MDI_CAMERA_AF_RANGE_LANDSCAPE           CAM_AF_RANGE_LANDSCAPE
/* AF range total number */
#define MDI_CAMERA_AF_RANGE_COUNT               CAM_NO_OF_AF_RANGE

/* Overlay 1-byte depth */ 
#define MDI_CAMERA_OVERLAY_1BPP                 IMG_PALETTE_MODE_1BPP
/* Overlay 2-bytes depth */
#define MDI_CAMERA_OVERLAY_2BPP                 IMG_PALETTE_MODE_2BPP
/* Overlay 4-bytes depth */
#define MDI_CAMERA_OVERLAY_4BPP                 IMG_PALETTE_MODE_4BPP
/* Overlay 8-bytes depth */
#define MDI_CAMERA_OVERLAY_8BPP                 IMG_PALETTE_MODE_8BPP


/* Capture mode - normal */
#define MDI_CAMERA_CAP_MODE_NORMAL              CAM_STILL_CAPTURE_NORMAL
/* Capture mode - bestshot */
#define MDI_CAMERA_CAP_MODE_BEST_SHOT           CAM_STILL_CAPTURE_BEST_SHOT
/* Capture mode - continuous shot */
#define MDI_CAMERA_CAP_MODE_CONT_SHOT           CAM_STILL_CAPTURE_CONT_SHOT
/* Capture mode - burstshot */
#define MDI_CAMERA_CAP_MODE_BURST_SHOT          CAM_STILL_CAPTURE_BURST_SHOT
/* Capture mode - EV bracketing shot */
#define MDI_CAMERA_CAP_MODE_EV_BRACKETING       CAM_STILL_CAPTURE_EV_BRACKETING
/* Capture mode - add frame */
#define MDI_CAMERA_CAP_MODE_ADD_FRAME           CAM_STILL_CAPTURE_ADD_FRAME
/* Capture mode - panorama */
#define MDI_CAMERA_CAP_MODE_PANORAMA            CAM_STILL_CAPTURE_PANO_VIEW
/* Capture mode - panorama */
#define MDI_CAMERA_CAP_MODE_AUTORAMA            CAM_STILL_CAPTURE_AUTO_RAMA
/* Capture mode - smile shot */
#define MDI_CAMERA_CAP_MODE_SMILE_SHOT          CAM_STILL_CAPTURE_SMILE_SHOT
/* Capture mode - high dynamic range */
#define MDI_CAMERA_CAP_MODE_HDR                 CAM_STILL_CAPTURE_HDR
/* Capture mode - auto scene detect */
#define MDI_CAMERA_CAP_MODE_ASD                 CAM_STILL_CAPTURE_ASD
/* Capture mode - zero shutter delay */
#define MDI_CAMERA_CAP_MODE_ZSD                 CAM_STILL_CAPTURE_ZSD
/* Capture mode - multiple angle view */
#define MDI_CAMERA_CAP_MODE_MAV                 CAM_STILL_CAPTURE_MAV
/* Capture mode - 3D image */
#define MDI_CAMERA_CAP_MODE_3D_IMAGE            CAM_STILL_CAPTURE_3D_IMAGE

/* Capture size - wallpaper */
#define MDI_CAMERA_CAP_SIZE_WALLPAPER           CAM_IMAGE_SIZE_WALLPAPER
/* Capture size - QVGA */
#define MDI_CAMERA_CAP_SIZE_QVGA                CAM_IMAGE_SIZE_QVGA
/* Capture size - VGA */
#define MDI_CAMERA_CAP_SIZE_VGA                 CAM_IMAGE_SIZE_VGA
/* Capture size - 1M */
#define MDI_CAMERA_CAP_SIZE_1M                  CAM_IMAGE_SIZE_1M
/* Capture size - 2M */
#define MDI_CAMERA_CAP_SIZE_2M                  CAM_IMAGE_SIZE_2M
/* Capture size - 3M */
#define MDI_CAMERA_CAP_SIZE_3M                  CAM_IMAGE_SIZE_3M
/* Capture size - 4M */
#define MDI_CAMERA_CAP_SIZE_4M                  CAM_IMAGE_SIZE_4M
/* Capture size - 5M */
#define MDI_CAMERA_CAP_SIZE_5M                  CAM_IMAGE_SIZE_5M
/* Capture size - 8M */
#define MDI_CAMERA_CAP_SIZE_8M                  CAM_IMAGE_SIZE_8M
/* Capture size - Others */
#define MDI_CAMERA_CAP_SIZE_OTHER               CAM_IMAGE_SIZE_OTHER


/* Image enhacement level - low */
#define MDI_CAMERA_IE_LEVEL_LOW                 CAM_SHARPNESS_LOW
/* Image enhacement level - medium */
#define MDI_CAMERA_IE_LEVEL_MEDIUM              CAM_SHARPNESS_MEDIUM
/* Image enhacement level - high */
#define MDI_CAMERA_IE_LEVEL_HIGH                CAM_SHARPNESS_HIGH
/* Image enhacement level - total number */
#define MDI_CAMERA_IE_LEVEL_COUNT               CAM_SHARPNESS_MAX


/* Sharpness level - low */
#define MDI_CAMERA_SHARPNESS_LOW                 CAM_SHARPNESS_LOW
/* Sharpness level - medium */
#define MDI_CAMERA_SHARPNESS_MEDIUM              CAM_SHARPNESS_MEDIUM
/* Sharpness level - high */
#define MDI_CAMERA_SHARPNESS_HIGH                CAM_SHARPNESS_HIGH
/* Sharpness level - total number */
#define MDI_CAMERA_SHARPNESS_COUNT               CAM_SHARPNESS_MAX


/* Contrast level - low */
#define MDI_CAMERA_CONTRAST_LOW                 CAM_CONTRAST_LOW
/* Contrast level - medium */
#define MDI_CAMERA_CONTRAST_MEDIUM              CAM_CONTRAST_MEDIUM
/* Contrast level - high */
#define MDI_CAMERA_CONTRAST_HIGH                CAM_CONTRAST_HIGH
/* Contrast level - total number */
#define MDI_CAMERA_CONTRAST_COUNT               CAM_CONTRAST_MAX


/* Saturation level - low */
#define MDI_CAMERA_SATURATION_LOW                 CAM_SATURATION_LOW
/* Saturation level - medium */
#define MDI_CAMERA_SATURATION_MEDIUM              CAM_SATURATION_MEDIUM
/* Saturation level - high */
#define MDI_CAMERA_SATURATION_HIGH                CAM_SATURATION_HIGH
/* Saturation level - total number */
#define MDI_CAMERA_SATURATION_COUNT               CAM_SATURATION_MAX


/* Preview rotate - 0 */
#define MDI_CAMERA_PREVIEW_ROTATE_0             CAM_IMAGE_NORMAL
/* Preview rotate - 90 */
#define MDI_CAMERA_PREVIEW_ROTATE_90            CAM_IMAGE_ROTATE_90
/* Preview rotate - 180 */
#define MDI_CAMERA_PREVIEW_ROTATE_180           CAM_IMAGE_ROTATE_180
/* Preview rotate - 270 */
#define MDI_CAMERA_PREVIEW_ROTATE_270           CAM_IMAGE_ROTATE_270
/* Preview rotate - 0 mirror */
#define MDI_CAMERA_PREVIEW_ROTATE_0_MIRROR      CAM_IMAGE_MIRROR
/* Preview rotate - 90 mirror */
#define MDI_CAMERA_PREVIEW_ROTATE_90_MIRROR     CAM_IMAGE_MIRROR_ROTATE_90
/* Preview rotate - 180 mirror */
#define MDI_CAMERA_PREVIEW_ROTATE_180_MIRROR    CAM_IMAGE_MIRROR_ROTATE_180
/* Preview rotate - 270 mirror */
#define MDI_CAMERA_PREVIEW_ROTATE_270_MIRROR    CAM_IMAGE_MIRROR_ROTATE_270


/* LCM rotate - 0 */
#define MDI_CAMERA_LCM_ROTATE_0              LCD_LAYER_ROTATE_NORMAL
/* LCM rotate - 90 */
#define MDI_CAMERA_LCM_ROTATE_90             LCD_LAYER_ROTATE_90
/* LCM rotate - 180 */
#define MDI_CAMERA_LCM_ROTATE_180            LCD_LAYER_ROTATE_180
/* LCM rotate - 270 */
#define MDI_CAMERA_LCM_ROTATE_270            LCD_LAYER_ROTATE_270
/* LCM rotate - 0 mirror */
#define MDI_CAMERA_LCM_ROTATE_0_MIRROR       LCD_LAYER_MIRROR
/* LCM rotate - 90 mirror */
#define MDI_CAMERA_LCM_ROTATE_90_MIRROR      LCD_LAYER_MIRROR_ROTATE_90
/* LCM rotate - 180 mirror */
#define MDI_CAMERA_LCM_ROTATE_180_MIRROR     LCD_LAYER_MIRROR_ROTATE_180
/* LCM rotate - 270 mirror */
#define MDI_CAMERA_LCM_ROTATE_270_MIRROR     LCD_LAYER_MIRROR_ROTATE_270


/* Post effect - normal */
#define MDI_CAMERA_POST_EFFECT_NORMAL        CAM_EFFECT_DEC_NORMAL
/* Post effect - grayscale */
#define MDI_CAMERA_POST_EFFECT_GRAYSCALE     CAM_EFFECT_DEC_GRAYSCALE
/* Post effect - sepia */
#define MDI_CAMERA_POST_EFFECT_SEPIA         CAM_EFFECT_DEC_SEPIA
/* Post effect - sepiagreen */
#define MDI_CAMERA_POST_EFFECT_SEPIAGREEN    CAM_EFFECT_DEC_SEPIAGREEN
/* Post effect - sepiablue */
#define MDI_CAMERA_POST_EFFECT_SEPIABLUE     CAM_EFFECT_DEC_SEPIABLUE
/* Post effect - color invert */
#define MDI_CAMERA_POST_EFFECT_COLORINV      CAM_EFFECT_DEC_COLORINV
/* Post effect - gray invert */
#define MDI_CAMERA_POST_EFFECT_GRAYINV       CAM_EFFECT_DEC_GRAYINV
/* Post effect - water color */
#define MDI_CAMERA_POST_EFFECT_WATERCOLOR    CAM_EFFECT_DEC_WATERCOLOR
/* Post effect - light blur */
#define MDI_CAMERA_POST_EFFECT_LIGHTBLUR     CAM_EFFECT_DEC_LIGHTBLUR
/* Post effect - blur */
#define MDI_CAMERA_POST_EFFECT_BLUR          CAM_EFFECT_DEC_BLUR
/* Post effect - strong blur */
#define MDI_CAMERA_POST_EFFECT_STRONGBLUR    CAM_EFFECT_DEC_STRONGBLUR
/* Post effect - unsharp */
#define MDI_CAMERA_POST_EFFECT_UNSHARP       CAM_EFFECT_DEC_UNSHARP
/* Post effect - sharpen */
#define MDI_CAMERA_POST_EFFECT_SHARPEN       CAM_EFFECT_DEC_SHARPEN
/* Post effect - more sharpen */
#define MDI_CAMERA_POST_EFFECT_MORESHARPEN   CAM_EFFECT_DEC_MORESHARPEN
/* Post effect - median */
#define MDI_CAMERA_POST_EFFECT_MEDIAN        CAM_EFFECT_DEC_MEDIAN
/* Post effect - dilation */
#define MDI_CAMERA_POST_EFFECT_DILATION      CAM_EFFECT_DEC_DILATION
/* Post effect - erosion */
#define MDI_CAMERA_POST_EFFECT_EROSION       CAM_EFFECT_DEC_EROSION


/* Adjustment - brightness */
#define MDI_CAMERA_ADJUSMENT_BRIGHTNESS      CAM_ADJ_DEC_BRIGHTNESS
/* Adjustment - contrast */
#define MDI_CAMERA_ADJUSMENT_CONTRAST        CAM_ADJ_DEC_CONTRAST
/* Adjustment - saturation */
#define MDI_CAMERA_ADJUSMENT_SATURATION      CAM_ADJ_DEC_SATURATION
/* Adjustment - hue */
#define MDI_CAMERA_ADJUSMENT_HUE             CAM_ADJ_DEC_HUE
/* Adjustment - red */
#define MDI_CAMERA_ADJUSMENT_COLOR_R         CAM_ADJ_DEC_ADJR
/* Adjustment - green */
#define MDI_CAMERA_ADJUSMENT_COLOR_G         CAM_ADJ_DEC_ADJG
/* Adjustment - blue */
#define MDI_CAMERA_ADJUSMENT_COLOR_B         CAM_ADJ_DEC_ADJB


#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
#endif

#define MDI_CAMERA_JPEG_RESIZER_UPPER_BOUND  (640*480*GDI_MAINLCD_BIT_PER_PIXEL)>>3

/***************************************************************************** 
* Typedef
*****************************************************************************/
/* Preview on which LCM */
typedef enum
{
    MDI_CAMERA_PREVIEW_LCM_MAINLCD = 0,     /* Main LCM */
    MDI_CAMERA_PREVIEW_LCM_SUBLCD,          /* Sub LCM */
    MDI_CAMERA_PREVIEW_LCM_COUNT            /* LCM total number */
} mdi_camera_preview_lcm_enum;

/* Flash, led highlight */
typedef struct
{
    U8 r;   /* Red */
    U8 g;   /* Green */
    U8 b;   /* Blue */
} mdi_camera_flash_struct;


/* Camera setting structure */
typedef struct
{
    U16 wb;                             /* Whilte balance */
    U16 ev;                             /* EV */
    U16 zoom;                           /* Zoom step */
    U16 effect;                         /* Effect */
    U16 image_qty;                      /* Image quality */
    U16 image_resolution;               /* Capture image resolution */
    U16 image_width;                    /* Capture image width */
    U16 image_height;                   /* Capture image height */
    U16 preview_width;                  /* Preview image width */
    U16 preview_height;                 /* Preview image height */
    U16 banding;                        /* Banding */
    U16 lcm;                            /* LCM */
    U16 sharpness;                      /* Sharpness value */
    U16 saturation;                     /* Saturation value */
    U16 contrast;                       /* Contrast value */
    U16 hue;                            /* Hue value */
    U16 flash;                          /* Flash */
    U16 ae_meter;                       /* Aemeter value */
    U16 iso;                            /* ISO value */
    U16 scene_mode;                     /* Scene mode */
    U16 af_operation_mode;              /* AF operation mode */
    U16 af_range;                       /* AF range */
    U8  preview_format;                 /* preview layer format */

   /* Color Index Overlay    */
    BOOL overlay_frame_mode;            /* Overlay flag */
    U8   overlay_frame_depth;            /* Overlay color depth */
    U8   overlay_frame_source_key;       /* Overlay source key color */
    U16  overlay_frame_width;            /* Overlay frame width */
    U16  overlay_frame_height;           /* Overlay frame height */
    U32  overlay_frame_buffer_address;   /* Overlay frame buffer address */
    U32* overlay_palette_addr;           /* Overlay palette address */
    U8   overlay_palette_size;           /* Overlay palette size */

    void (*xenon_flash_status_callback) (mdi_result, void*);   /* xenon flash status callback function pointer */

#if defined(__MDI_CAMERA_FD_SUPPORT__)
    mdi_camera_fd_callback fd_callback; /* Face detection result callback pointer */
    BOOL fd_enable;                     /* Face detection enable flag */
    #if defined(__SMILE_SHUTTER_SUPPORT__)
    U8 smile_request_no;
    #endif

#endif /* __MDI_CAMERA_FD_SUPPORT__ */
} mdi_camera_setting_struct;

/* Preview window data */
typedef struct
{
    gdi_handle preview_layer_handle;    /* Preview layer handle */
    U32  blt_layer_flag;                /* Layer flags of needing to blt when camera previewing */
    U32  preview_layer_flag;            /* Previwe layer flag */
    BOOL is_lcd_update;                 /* LCD update the preview layer flag */
    BOOL is_tvout;                      /* Update to TV flag, Reserved */
    U16  src_key_color;                 /* Source key color */
} mdi_camera_preview_struct;

typedef struct
{
    U8  resolution;
    U16  width;
    U16  height;
}mdi_camera_image_info;

typedef struct
{
    U32 y_buffer_address;
    U32 y_buffer_size;
    U32 u_buffer_address;
    U32 u_buffer_size;
    U32 v_buffer_address;
    U32 v_buffer_size;    
    
}mdi_camera_capture_yuv_buffer_struct;

/* MDI camera context */
typedef struct
{
    mdi_camera_setting_struct setting;  /* Setting parameter */
    mdi_camera_preview_struct preview;  /* Preview parameter */
    
    U16 state;                          /* Current state */
    U16 seq_num;                        /* Sequence number */
    U16 stitch_seq_num;                 /* Panorama stitch sequence number */
    BOOL is_preview_stopped;            /* Preview stop flag */
    BOOL is_tvout;                      /* TV-out flag */
    U16 burst_cap_count;                /* Burstshot capture counter */
    U16 tvout_prev_owner;               /* The previous tvout owner. Reserved */
    U16 cam_id;                         /* Camera sensor id */
    U8  capture_mode;

    /* Info for burst capture for MT6228 and after */
    U8 lcd_id;                          /* LCD id */
    S32 tv_output_offset_x;             /* TV-out offset x. Reserved */
    S32 tv_output_offset_y;             /* TV-out offset y. Reserved */
    kal_uint8* frame_buf1_ptr;          /* Preview buffer1 address */
    kal_uint8* frame_buf2_ptr;          /* Preview buffer2 address */
    U32 frame_buf_size;                 /* Preview layer buffer length */

#if defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__)
    U16 hw_rotate;                      /* HW rotate value */
#endif

#if defined(__MDI_CAMERA_FD_SUPPORT__)
    BOOL is_fd_enabled;                 /* Face detection enble flag */
#endif
    U8  cbm_app_id;
    U8  capture_rotate;
    U8  quickview_rotate;
    U16 app_id;
    void* user_data;
    MMI_BOOL is_profiling_on;
#ifdef __CAMERA_CAPTURE_USING_APP_MEMORY__    
    mdi_camera_capture_yuv_buffer_struct capture_yuv_buffer;
#endif
    
} mdi_camera_context_struct;

/* Define as media JPEG structure */
#define mdi_camera_jpegs_struct jpegs_struct 


/*****************************************************************************
 * <GROUP  CallBackFunctions>       
 *
 * FUNCTION
 *  capture_result_callback
 * DESCRIPTION
 *  Capture result callback
 * PARAMETERS
 *  result          : [IN]     Capture result
 *  capture_count   : [IN]     Capture image count
 *  user_data       : [IN]     user data
 * RETURN VALUES
 *  void
*****************************************************************************/
typedef void (*capture_result_callback) (mdi_result result, U16 capture_count, void* user_data);


#if 1
    /* AF result */
    typedef struct
    {
        mdi_af_result_enum af_result;   /* AF result */
        U32 af_success_zone;            /* AF success zone */
    }mdi_camera_af_result_struct;

    /* AF zone structure */
    typedef struct
    {
        U32 af_zone_w;      /* Width */
        U32 af_zone_h;      /* Height */
        U32 af_zone_x;      /* Offset x */
        U32 af_zone_y;      /* Offset y */
    }mdi_camera_af_zone_struct;

    /* AF window structure */
    typedef struct
    {
        U32 af_active_zone;     /* Active zone */
        mdi_camera_af_zone_struct af_zone[MDI_CAMERA_AF_ZONE_MAX_NO];   /* AF zone array */
    }mdi_camera_af_window_struct;

    /*****************************************************************************
     * <GROUP  CallBackFunctions>       
     *
     * FUNCTION
     *  mdi_camera_af_ind_callback
     * DESCRIPTION
     *  AF result callback
     * PARAMETERS
     *  result_ind      : [IN]     AF result structure
     *  user_data       : [IN]     user data
     * RETURN VALUES
     *  void
     *****************************************************************************/
    typedef void (*mdi_camera_af_ind_callback) (mdi_camera_af_result_struct result_ind, void* user_data);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* Overlay frame setting */
typedef struct
{
    BOOL overlay_frame_mode;            /* Overlay flag */
    U8   overlay_frame_depth;             /* Overlay color depth */
    U8   overlay_frame_source_key;        /* Overlay source key color */
    U16  overlay_frame_width;            /* Overlay frame width */
    U16  overlay_frame_height;           /* Overlay frame height */
    U32  overlay_frame_buffer_address;   /* Overlay frame buffer address */
    U32  *overlay_palette_addr;          /* Overlay palette address */
    U8   overlay_palette_size;            /* Overlay palette size */
}mdi_camera_overlay_struct;

    
/* Direction of panorama stitch */
typedef enum
{
    MDI_CAMERA_PANO_RIGHT_DIR = CAM_PANO_RIGHT_DIR,     /* Right */
    MDI_CAMERA_PANO_LEFT_DIR = CAM_PANO_LEFT_DIR,       /* Left */
    MDI_CAMERA_PANO_UP_DIR = CAM_PANO_UP_DIR,           /* Up */
    MDI_CAMERA_PANO_DOWN_DIR = CAM_PANO_DOWN_DIR        /* Down */
} mdi_camera_panorama_direciton_enum;


/* HDR buffer type */
typedef enum
{
    MDI_CAMERA_HDR_CAPTURE_QUICKVIEW = CAM_HDR_CAPTURE_QUICKVIEW_RAWDATA,               /* The quick view of capture image */
    MDI_CAMERA_HDR_CAPTURE_MAINIMAGE = CAM_HDR_CAPTURE_MAINIMAGE_JPEG,                  /* The main image of capture image */
    MDI_CAMERA_HDR_PROCESSED_QUICKVIEW = CAM_HDR_PROCESSED_QUICKVIEW_RAWDATA,           /* The quick view of HDR image */
    MDI_CAMERA_HDR_PROCESSED_MAINIMAGE = CAM_HDR_PROCESSED_MAINIMAGE_JPEG               /* The main image of HDR image */
} mdi_camera_hdr_buffer_type_enum;

/* The maximum capture number of panorama */
#define MDI_CAMERA_PANORAMA_MAX_NO (CAM_PANO_MAX_SHOT_NUM)

/* The panorama stitch request structure */
typedef struct _mdi_camera_panorama_struct
{
    U8 image_num;                                               /* The number of stitch image */
    mdi_camera_panorama_direciton_enum direction;               /* The direction of stitch image */
    U32 src_jpeg_buffer_address[MDI_CAMERA_PANORAMA_MAX_NO];    /* The address of capture image */
    U32 src_jpeg_buffer_size[MDI_CAMERA_PANORAMA_MAX_NO];       /* The size of capture image */
    U32 dest_jpeg_buffer_address;                               /* The buffer address of storing stitched image */
    U32 dest_jpeg_buffer_size;                                  /* The buffer size of storing stitched image */
}mdi_camera_panorama_struct;

/* The panorama stitch result structure */
typedef struct
{
    MDI_RESULT result;                      /* Stitch result */

    U32 jpeg_buffer_address;                /* The buffer address of stitched image */
    U32 jpeg_buffer_size;                   /* The length of stitched image */
    U32 jpeg_image_width;                   /* The width of stitched image */
    U32 jpeg_image_height;                  /* The height of stitched image */
}mdi_camera_panorama_stitch_result_struct;

typedef struct
{
    U16 result;
    U16 quickview_start_x;
    U16 quickview_start_y;
    U16 quickview_width;
    U16 quickview_height;
}mdi_camera_panorama_stitch_quickview_struct;


typedef struct
{
    U16 quickview_roi_x;
    U16 quickview_roi_y;
    U16 quickview_roi_width;
    U16 quickview_roi_height;
    BOOL is_quickview_centred;
}mdi_camera_panorama_stitch_encode_struct;

/* The structure of autocap result */
typedef media_cam_autocap_result_struct mdi_camera_panorama_cap_info_struct;


/* The hdr result structure */
typedef struct
{
    MDI_RESULT result;                                      /* result */
    mdi_camera_hdr_buffer_type_enum  buffer_type;     /* buffer content type */
    U32 buffer_address;                                     /* The buffer address of return image */
    U32 buffer_size;                                        /* The length of return image */
}mdi_camera_hdr_result_struct;


/* The mav result structure */
typedef struct
{
    U32 capture_count;                                     /* The buffer address of return image */
    U32 total_count;                                        /* The length of return image */
}mdi_camera_mav_capture_struct;

/* The mav result structure */
typedef struct
{
    MDI_RESULT result;                                      /* result */
    U32 buffer_address;                                     /* The buffer address of return image */
    U32 buffer_size;                                        /* The length of return image */
}mdi_camera_mav_result_struct;


/*****************************************************************************
 * <GROUP  CallBackFunctions>       
 *
 * FUNCTION
 *  mdi_camera_panorama_callback
 * DESCRIPTION
 *  Panorama stitch finish callback
 * PARAMETERS
 *  result_ind      : [IN]     The panorama stitch result structure
 *  user_data       : [IN]     user data
 * RETURN VALUE
 *  void
 *****************************************************************************/
typedef void (*mdi_camera_panorama_stitch_result_callback) (mdi_camera_panorama_stitch_result_struct* result_ind, void* user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>       
 *
 * FUNCTION
 *  mdi_camera_panorama_quickview_result_callback
 * DESCRIPTION
 *  Panorama stitch finish callback
 * PARAMETERS
 *  result_ind      : [IN]     The panorama stitch result structure
 *  user_data       : [IN]     user data
 * RETURN VALUE
 *  void
 *****************************************************************************/
typedef void (*mdi_camera_panorama_stitch_quickview_callback) (mdi_camera_panorama_stitch_quickview_struct* result_ind, void* user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>       
 *
 * FUNCTION
 *  mdi_camera_hdr_callback
 * DESCRIPTION
 *  HDR finish callback
 * PARAMETERS
 *  result_ind      : [IN]     The HDR result structure
 * RETURN VALUE
 *  void
 *****************************************************************************/
typedef void (*mdi_camera_hdr_callback) (mdi_camera_hdr_result_struct* result_ind, void* user_data);



/*****************************************************************************
 * <GROUP  CallBackFunctions>       
 *
 * FUNCTION
 *  mdi_camera_mav_capture_callback
 * DESCRIPTION
 *  MAV finish callback
 * PARAMETERS
 *  result_ind      : [IN]     The MAV result structure
 * RETURN VALUE
 *  void
 *****************************************************************************/
typedef void (*mdi_camera_mav_capture_callback) (mdi_camera_mav_capture_struct* result_ind, void* user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>       
 *
 * FUNCTION
 *  mdi_camera_mav_result_callback
 * DESCRIPTION
 *  MAV finish callback
 * PARAMETERS
 *  result_ind      : [IN]     The MAV result structure
 * RETURN VALUE
 *  void
 *****************************************************************************/
typedef void (*mdi_camera_mav_result_callback) (mdi_camera_mav_result_struct* result_ind, void* user_data);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_error_info
 * DESCRIPTION
 *  Get the error string and error type
 * PARAMETERS
 *  error_code   : [IN]     Error code got from MDI APIs
 *  popup_type   : [OUT]    Popup_type of this error_code 
 * RETURNS
 *  string_id
 *****************************************************************************/
extern MMI_ID_TYPE mdi_camera_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_init
 * DESCRIPTION
 *  Init MDI camera
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED  : Success
 *****************************************************************************/
extern MDI_RESULT mdi_camera_init(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_camera_id
 * DESCRIPTION
 *  Choose the camera sensor
 * PARAMETERS
 *  camera_id       : [IN]    Camera sensor id [main or sub]
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *  MDI_RES_WEBCAM_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_camera_set_camera_id(U16 camera_id);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_capture_rotation
 * DESCRIPTION
 *  Set UI rotation value
 * PARAMETERS
 *  value           : [IN]    rotation value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_set_capture_rotation(U8 value);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_quickview_rotation
 * DESCRIPTION
 *  Set UI rotation value
 * PARAMETERS
 *  value           : [IN]    rotation value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_set_quickview_rotation(U8 value);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_power_on
 * DESCRIPTION
 *  Power on the camera module
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *  MDI_RES_WEBCAM_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_camera_power_on(U16 app_id);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_power_off
 * DESCRIPTION
 *  Power off the camera module
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *****************************************************************************/
extern MDI_RESULT mdi_camera_power_off(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_preview_start_with_capmode
 * DESCRIPTION
 *  Start camera preview with capture mode.
 *  Zero shutter delay or auto scene detection capture mode needs to be known 
 *  when previewing.
 * PARAMETERS
 *  preview_p                   : [IN]        Preview data
 *  setting_p                   : [IN]        Setting data
 *  capture_mode                : [IN]        Capture mode
 *  user_data                   : [IN]        User data
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
extern MDI_RESULT mdi_camera_preview_start_with_capmode(
            mdi_camera_preview_struct *preview_p,
            mdi_camera_setting_struct *setting_p,
            U8 capture_mode,
            void* user_data);
/* DOM-NOT_FOR_SDK-END */            

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_preview_start
 * DESCRIPTION
 *  Start camera preview
 * PARAMETERS
 *  preview_p                   : [IN]        Preview data
 *  setting_p                   : [IN]        Setting data
 *  user_data                   : [IN]        User data
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *  MDI_RES_WEBCAM_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_camera_preview_start(
                    mdi_camera_preview_struct *preview_p,
                    mdi_camera_setting_struct *setting_p,
                    void* user_data);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_preview_stop
 * DESCRIPTION
 *  Stop camera preview
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *****************************************************************************/
extern MDI_RESULT mdi_camera_preview_stop(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_quickview_extra_buffer
 * DESCRIPTION
 *  Set quickview extra for saving MED quickview buffer memory
 * PARAMETERS
 *  buf_addr          : [IN]          MED quick view image buffer address
 *  buf_size          : [IN]          MED quick view image buffer address size
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_set_quickview_extra_buffer(U32 buf_addr, U32 buf_size);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_capture_yuv_buffer
 * DESCRIPTION
 *  Set quickview extra for saving MED quickview buffer memory
 * PARAMETERS
 *  capture_yuv_buffer          : [IN]          MED capture yuv buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_set_capture_yuv_buffer(mdi_camera_capture_yuv_buffer_struct* capture_yuv_buffer);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture
 * DESCRIPTION
 *  Capture a jpeg image
 * PARAMETERS
 *  filename            : [IN]        Filename buffer pointer
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            : Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     : Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              : No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       : Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture(S8 *filename);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_with_quickview
 * DESCRIPTION
 *  Capture jpeg to a memory
 * PARAMETERS
 *  quickview_buf_addr          : [IN]          Quick view image buffer address
 *  quickview_buf_size          : [IN]          Quick view image buffer address size
 *  quickview_width             : [IN]          Width of quick view image buffer
 *  quickview_height            : [IN]          Height of quick view image buffer
 *  filename                    : [IN]          File name
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            : Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     : disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              : No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       : Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_with_quickview(
        U32 quickview_buf_addr, 
        U32 quickview_buf_size, 
        U16 quickview_width, 
        U16 quickview_height,
        S8* filename);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_continuous_shot
 * DESCRIPTION
 *  Continue capture
 * PARAMETERS
 *  file_name       : [IN]    The pointer of filename buffer array
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            : Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     : Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              : No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       : Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_continuous_shot(S8* filename);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_continuous_shot_with_quickview
 * DESCRIPTION
 *  Capture jpeg to a memory
 * PARAMETERS
 *  buf_pp              : [OUT]       Pointer to a buffer pointer for jpeg file
 *  captured_size       : [OUT]       Captured size
 *  dc_buf_addr         : [IN]        Captured image layer address
 *  buf_size            : [IN]        Captured image layer buffer length
 *  width               : [IN]        Width of captured image image
 *  height              : [OUT]       Height of captured image image
 *  filename            : [IN]        File name
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_continuous_shot_with_quickview(
        U32 quickview_buf_addr, 
        U32 quickview_buf_size, 
        U16 quickview_width, 
        U16 quickview_height,
        S8* filename);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_burst_shot
 * DESCRIPTION
 *  Non-blocking burstshot capture
 * PARAMETERS
 *  capture_count       : [IN]        Capture number
 *  jpgs_ptr            : [OUT]       Captured jpeg info        
 *  callback            : [IN]        Capture result callback
 *  buffer              : [IN]        Burstshot buffer address
 *  buffer_size         : [IN]        Burstshot buffer length
 *  user_data           : [IN]        User data
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            : Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     : Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              : No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       : Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_to_memory_burst_shot(
                                                U32 capture_count, 
                                                mdi_camera_jpegs_struct *jpgs_ptr, 
                                                capture_result_callback callback, 
                                                U8* buffer, 
                                                S32 buffer_size,
                                                void* user_data);



/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_burst_shot_with_quickview
 * DESCRIPTION
 *  Non-blocking burstshot capture
 * PARAMETERS
 *  capture_count       : [IN]        Capture number
 *  jpgs_ptr            : [OUT]       Captured jpeg info        
 *  callback            : [IN]        Capture result callback
 *  buffer              : [IN]        Burstshot buffer address
 *  buffer_size         : [IN]        Burstshot buffer length
 *  quickview_buf_addr  : [IN]        Quick view image buffer address
 *  quickview_buf_size  : [IN]        Quick view image buffer address size
 *  quickview_width     : [IN]        Width of quick view image buffer
 *  quickview_height    : [IN]        Height of quick view image buffer
 *  user_data           : [IN]        User data
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_to_memory_burst_shot_with_quickview(
                                                    U32 capture_count, 
                                                    mdi_camera_jpegs_struct *jpgs_ptr, 
                                                    capture_result_callback callback, 
                                                    U8* buffer, 
                                                    S32 buffer_size,
                                                    U32 quickview_buf_addr, 
                                                    U32 quickview_buf_size, 
                                                    U16 quickview_width, 
                                                    U16 quickview_height,
                                                    void* user_data);
                                                    
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_non_block_burst_capture
 * DESCRIPTION
 *  Stop non blocking burst capture
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED  : Success
 *****************************************************************************/
extern MDI_RESULT mdi_camera_stop_non_block_burst_capture(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_bracketing
 * DESCRIPTION
 *  EV bracketing capture and this is a blocking function
 * PARAMETERS
 *  jpgs_ptr    : [IN]    The pointer for storing captured jpeg info structure 
 *  buffer      : [IN]    The buffer address
 *  buffer_size : [IN]    The buffer size
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            : Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     : Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              : No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       : Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_to_memory_bracketing(mdi_camera_jpegs_struct *jpgs_ptr,U8* buffer, S32 buffer_size);



/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_best_shot
 * DESCRIPTION
 *  EV bracketing capture and this is a blocking function
 * PARAMETERS
 *  buf_pp          : [OUT]       The pointer to pointer for get capture buffer address
 *  captured_size   : [OUT]       The pointer of capture size
 *  buffer          : [IN]        The buffer address
 *  buffer_size     : [IN]        The buffer size
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            : Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     : Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              : No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       : Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_to_memory_best_shot(U8** buf_pp, U32 *captured_size, U8* buffer, S32 buffer_size);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_panorama_with_quickview
 * DESCRIPTION
 *  Capture one of panorama images and direct couple the captured raw image append to captured data. 
 * PARAMETERS
 *  buffer                      [IN]        Capture buffer address (MT6235: in yuv420 planar format)(MT6238 series: in jpeg format)
 *  buffer_size                 [IN]        Capture buffer size
 *  captured_buffer_pp          [OUT]       Captured image buffer address
 *  captured_buffer_size_p      [OUT]       Captured image size 
 *  shot_num                    [IN]        The capture image index
 *  direction                   [IN]        Panorama stitch direction
 *  quickview_buf_addr          [IN]        Quick view image buffer address_p (if NULL, we will not do this)
 *  quickview_buf_size          [IN]        Quick view image buffer address size
 *  quickview_width             [IN]        Width of quick view image buffer
 *  quickview_height            [IN]        Height of quick view image buffer
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_to_memory_panorama_with_quickview(
                                                 U8  *buffer, 
                                                 U32 buffer_size,
                                                 U8  **captured_buffer_pp,
                                                 U32 *captured_buffer_size_p,
                                                 U8  shot_num,
                                                 U8  direction,
                                                 U32 quickview_buf_addr, 
                                                 U32 quickview_buf_size, 
                                                 U16 quickview_width, 
                                                 U16 quickview_height);  

                                                 
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_panorama
 * DESCRIPTION
 *  Capture one of panorama images
 * PARAMETERS
 *  buffer                      : [IN]        Capture buffer address       
 *  buffer_size                 : [OUT]       Capture buffer size
 *  captured_buffer_size_p      : [IN]        Capture image size 
 *  shot_num                    : [IN]        The capture image index
 *  direction                   : [IN]        Panorama stitch direction
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            : Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     : Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              : No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       : Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_to_memory_panorama(U8* buffer, 
                                                 U32 buffer_size,
                                                 U8 **captured_buffer_pp,                                                 
                                                 U32* captured_buffer_size_p,
                                                 U8 shot_num,
                                                 U8 direciton);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_stitching_panorama_with_quickview
 * DESCRIPTION
 *  Start stitching panorama process
 * PARAMETERS
 *  data                        : [IN]        Panorama capture image information
 *  quickview_callback          : [IN]        Stitch quickview callback
 *  stitch_callback             : [IN]        Stitch result callbcak
 *  quickview_buf_addr          : [IN]        Quick view image buffer address_p (if NULL, we will not do this)
 *  quickview_buf_size          : [IN]        Quick view image buffer address size
 *  quickview_width             : [IN]        Width of quick view image buffer
 *  quickview_height            : [IN]        Height of quick view image buffer
 *  is_quickview_resized_by_buf : [IN]        Decide the quickview resized by buffer size or dimension
 *  user_data                   : [IN]        user data
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_start_stitching_panorama_with_quickview(
                                                mdi_camera_panorama_struct* data, 
                                                mdi_camera_panorama_stitch_quickview_callback quickview_callback,
                                                mdi_camera_panorama_stitch_result_callback stitch_callback, 
                                                U32 quickview_buf_addr, 
                                                U32 quickview_buf_size, 
                                                U16 quickview_width, 
                                                U16 quickview_height,
                                                MMI_BOOL is_quickview_resized_by_buf,                                                
                                                void* user_data);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_stitching_panorama
 * DESCRIPTION
 *  Start stitching panorama process
 * PARAMETERS
 *  data            : [IN]        Panorama capture image information
 *  callback        : [IN]        Stitch result callbcak
 *  user_data       : [IN]        user data 
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_start_stitching_panorama(mdi_camera_panorama_struct* data, mdi_camera_panorama_stitch_result_callback callback, void* user_data);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_stitching_panorama
 * DESCRIPTION
 *  Stop stitching panorama process
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_stop_stitching_panorama(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_pause_stitching_panorama
 * DESCRIPTION
 *  Pause stitching panorama process
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_pause_stitching_panorama(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_resume_stitching_panorama
 * DESCRIPTION
 *  Resume stitching panorama process
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_resume_stitching_panorama(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_reset_panorama_3a
 * DESCRIPTION
 *  Resets 3A when terminating panorama process.
 * PARAMETERS
 *  void     
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_reset_panorama_3a(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_stitch_memory
 * DESCRIPTION
 *  Set stitch memory before panorama capture
 * PARAMETERS
 *  void     
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_set_panorama_stitch_memory(U8* buffer, U32 buffer_size);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_panorama_cap_info
 * DESCRIPTION
 *  Get auto capture tracking infomation
 * PARAMETERS
 *  cap_result_p        : [OUT]       Panorama cap tracking info
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_get_panorama_cap_info(mdi_camera_panorama_cap_info_struct *cap_info_p);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_encode_panorama_stitch_image
 * DESCRIPTION
 *  Encode stitch image with the clip information
 * PARAMETERS
 *  encode_info_p        : [IN]       Panorama encode info
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_encode_panorama_stitch_image(mdi_camera_panorama_stitch_encode_struct *encode_info_p);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_hdr_shot_with_quickview
 * DESCRIPTION
 *  HDR capture and this is a non-blocking function
 * PARAMETERS
 *  quickview_buf_addr          : [IN]        Quick view image buffer address_p (if NULL, we will not do this)
 *  quickview_buf_size          : [IN]        Quick view image buffer address size
 *  quickview_width             : [IN]        Width of quick view image buffer
 *  quickview_height            : [IN]        Height of quick view image buffer
 *  callback                    : [IN]        capture result callbcak
 *  user_data                   : [IN]        user data 
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_hdr_shot_with_quickview(
                                                U32 quickview_buf_addr, 
                                                U32 quickview_buf_size, 
                                                U16 quickview_width,
                                                U16 quickview_height,
                                                mdi_camera_hdr_callback callback, 
                                                void* user_data);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_non_blocking_hdr_shot
 * DESCRIPTION
 *  Stop HDR process
 * PARAMETERS
 *  captured_filename             : [IN]        filepath for saving the captured image (no HDR enhanced file)
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_stop_non_blocking_hdr_shot(S8* captured_filename);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_save_captured_hdr_image
 * DESCRIPTION
 *  According to the passed file name, MED saves the capture result to the file
 * PARAMETERS
 *  captured_filename       : [IN]    capture image file name
 *  hdr_filename            : [IN]    hdr file name 
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Failed
 *****************************************************************************/
extern S32 mdi_camera_save_hdr_images(S8* captured_filename, S8* hdr_filename);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_mav
 * DESCRIPTION
 *  Non-blocking burstshot capture
 * PARAMETERS      
 *  filename            : [IN]        file name
 *  capture_callback    : [IN]        Capture result callback
 *  result_callback     : [IN]        Finish result callback
 *  user_data           : [IN]        User data
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_mav_shot(
                                    CHAR* filename,
                                    mdi_camera_mav_capture_callback capture_callback,
                                    mdi_camera_mav_result_callback result_callback,
                                    void* user_data);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_non_blocking_mav_shot
 * DESCRIPTION
 *  Stop HDR process
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_stop_non_blocking_mav_shot(void);                                
/* DOM-NOT_FOR_SDK-END*/


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_encode_captured_image
 * DESCRIPTION
 *  According to the passed file name, MED saves the capture result to the file
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            : Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     : Write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              : No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       : Failed
 *****************************************************************************/
extern S32 mdi_camera_encode_capture_image(U8 **buf_pp, U32 *buf_size_p);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_save_captured_image
 * DESCRIPTION
 *  According to the passed file name, MED saves the capture result to the file
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            : Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     : Write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              : No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       : Failed
 *****************************************************************************/
extern S32 mdi_camera_save_captured_image(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_banding
 * DESCRIPTION
 *  Update banding value
 * PARAMETERS
 *  cam_para        : [IN]        Banding value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_banding(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_ev
 * DESCRIPTION
 *  Update ev setting value
 * PARAMETERS
 *  cam_para        : [IN]        EV setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_ev(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_zoom
 * DESCRIPTION
 *  Update zoom step value
 * PARAMETERS
 *  cam_para        : [IN]        Zoom step value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_zoom(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_effect
 * DESCRIPTION
 *  Update effect setting value
 * PARAMETERS
 *  cam_para        : [IN]        Effect setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_effect(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_wb
 * DESCRIPTION
 *  Update wb setting value
 * PARAMETERS
 *  cam_para        : [IN]        WB setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_wb(U16 cam_para);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_saturation
 * DESCRIPTION
 *  Update saturation setting value
 * PARAMETERS
 *  cam_para        : [IN]        Saturation setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_saturation(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_contrast
 * DESCRIPTION
 *  Update contrast setting value
 * PARAMETERS
 *  cam_para        : [IN]        Contrast setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_contrast(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_sharpness
 * DESCRIPTION
 *  Update sharpness setting value
 * PARAMETERS
 *  cam_para        : [IN]        Sharpness setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_sharpness(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_hue
 * DESCRIPTION
 *  Update hue setting value
 * PARAMETERS
 *  cam_para        : [IN]        Hue setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_hue(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_night
 * DESCRIPTION
 *  Update night mode setting value
 * PARAMETERS
 *  cam_para        : [IN]        Night mode setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_night(U16 cam_pra);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_image_qty
 * DESCRIPTION
 *  Update image quality setting value
 * PARAMETERS
 *  cam_para        : [IN]        Image qty setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_image_qty(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_image_size
 * DESCRIPTION
 *  Update image size setting value
 * PARAMETERS
 *  image_width         : [IN]        Captured image width
 *  image_height        : [IN]        Captured image height
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_image_size(U16 image_width, U16 image_height);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_flash
 * DESCRIPTION
 *  Update flash setting value
 * PARAMETERS
 *  cam_para        : [IN]        Flash setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_flash(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_iso
 * DESCRIPTION
 *  Update iso setting value
 * PARAMETERS
 *  cam_para        : [IN]        ISO setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_iso(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_ae_meter
 * DESCRIPTION
 *  Update ae meter setting value
 * PARAMETERS
 *  cam_para        : [IN]        AE meter setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_ae_meter(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_scene_mode
 * DESCRIPTION
 *  Update scene mode value
 * PARAMETERS
 *  cam_para        : [IN]        Scene mode setting value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_scene_mode(U16 cam_para);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_key
 * DESCRIPTION
 *  Update af key value
 * PARAMETERS
 *  cam_para        : [IN]        AF key
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_af_key(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_mode
 * DESCRIPTION
 *  Update af mode value
 * PARAMETERS
 *  cam_para        : [IN]        AF mode
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_af_mode(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_metering
 * DESCRIPTION
 *  Update af metering value
 * PARAMETERS
 *  cam_para        : [IN]        AF metering
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_af_metering(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_range
 * DESCRIPTION
 *  Update af range value
 * PARAMETERS
 *  cam_para        : [IN]        AF range value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_af_range(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_operation_mode
 * DESCRIPTION
 *  Update af operation mode value
 * PARAMETERS
 *  cam_para        : [IN]        AF range value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_para_af_operation_mode(U16 cam_para);


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_update_overlay_data
 * DESCRIPTION
 *  Update overlay struct
 * PARAMETERS
 *  overlay        : [IN]        Overlay structure pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_update_overlay_data(mdi_camera_overlay_struct* overlay);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_ev
 * DESCRIPTION
 *  Return the current ev value
 * PARAMETERS
 *  void
 * RETURNS
 *  Camera EV value
 *****************************************************************************/
extern U16 mdi_camera_get_para_ev(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_zoom
 * DESCRIPTION
 *  Return the current zoom step value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam zoom value 
 *****************************************************************************/
extern U16 mdi_camera_get_para_zoom(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_zoom_factor
 * DESCRIPTION
 *  Return the current zoom factor value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam zoom value 
 *****************************************************************************/
extern U32 mdi_camera_get_para_zoom_factor(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_banding
 * DESCRIPTION
 *  Return the current banding value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam banding value
 *****************************************************************************/
extern U16 mdi_camera_get_para_banding(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_effect
 * DESCRIPTION
 *  Return the current effect value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam effect value
 *****************************************************************************/
extern U16 mdi_camera_get_para_effect(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_wb
 * DESCRIPTION
 *  Return the current wb value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam WB value
 *****************************************************************************/
extern U16 mdi_camera_get_para_wb(void);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_sharpness
 * DESCRIPTION
 *  Return the current sharpness value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam brightness value
 *****************************************************************************/
extern U16 mdi_camera_get_para_sharpness(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_saturation
 * DESCRIPTION
 *  Return the current saturation value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam saturation value
 *****************************************************************************/
extern U16 mdi_camera_get_para_saturation(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_contrast
 * DESCRIPTION
 *  Return the current contrast value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam contrast value
 *****************************************************************************/
extern U16 mdi_camera_get_para_contrast(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_hue
 * DESCRIPTION
 *  Return the current hue value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam hue value
 *****************************************************************************/
extern U16 mdi_camera_get_para_hue(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_night
 * DESCRIPTION
 *  Return the current night mode value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam night mode value
 *****************************************************************************/
extern U16 mdi_camera_get_para_night(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_image_qty
 * DESCRIPTION
 *  Return the current image quality value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam image quality value
 *****************************************************************************/
extern U16 mdi_camera_get_para_image_qty(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_image_size
 * DESCRIPTION
 *  Return current image size value
 * PARAMETERS
 *  image width         : [OUT]       Current image width
 *  image height        : [OUT]       Current image height
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_get_para_image_size(U16* image_width_ptr, U16* image_height_ptr);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_flash
 * DESCRIPTION
 *  Return the current flash value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam flash value
 *****************************************************************************/
extern U16 mdi_camera_get_para_flash(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_iso
 * DESCRIPTION
 *  Return the current iso value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam ISO value
 *****************************************************************************/
extern U16 mdi_camera_get_para_iso(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_ae_meter
 * DESCRIPTION
 *  Return the current ae meter value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam AE meter value
 *****************************************************************************/
extern U16 mdi_camera_get_para_ae_meter(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_dsc_mode
 * DESCRIPTION
 *  Return the current dsc mode value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam dsc mode value
 *****************************************************************************/
extern U16 mdi_camera_get_para_dsc_mode(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_af_mode
 * DESCRIPTION
 *  Return the current af mode value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam AF mode value
 *****************************************************************************/
extern U16 mdi_camera_get_para_af_mode(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_detected_scene_mode
 * DESCRIPTION
 *  Get scene detect result
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam detected scene mode
 *****************************************************************************/
extern U16 mdi_camera_get_detected_scene_mode(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_is_camera_avaliable
 * DESCRIPTION
 *  Check if camera is avaliable
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  TRUE        : Avaliable
 *  FALSE       : Not avaliable
 *****************************************************************************/
extern BOOL mdi_camera_is_camera_avaliable(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_is_ready_to_capture
 * DESCRIPTION
 *  Check hw module is ready to capture 
 *  (some module requires some time to power on and init)
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  TRUE        : Ready
 *  FALSE       : Not ready
 *****************************************************************************/
extern BOOL mdi_camera_is_ready_to_capture(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_add_post_effect
 * DESCRIPTION
 *  Add effect to one of layers
 * PARAMETERS
 *  app id              : [IN]        id  
 *  layer_handle        : [IN]        Layer handle 
 *  effect_id           : [IN]        Effect index
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_add_post_effect(U16 app_id, gdi_handle layer_handle, U16 effect_id);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_add_post_adjustment
 * DESCRIPTION
 *  Image adjustment
 * PARAMETERS
 *  app id              : [IN]        id   
 *  layer_handle        : [IN]        Layer handle
 *  adjustment_id       : [IN]        Adjustment index
 *  value               : [IN]        Value
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_add_post_adjustment(U16 app_id, gdi_handle layer_handle, U16 adjustment_id, S32 value);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_fast_zoom
 * DESCRIPTION
 *  Start fast zoom [smooth zoom]
 * PARAMETERS
 *  zoom_in         : [IN]        Zoom in/out
 *  zoom_limit      : [IN]        Max zoom step.
 *  zoom_step       : [IN]        How many zoom step to be operated per zoomin/zoomout operation.
 *  zoom_speed      : [IN]        How many frame to be inserted in each zoomin/zoomout zoom step.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_start_fast_zoom(BOOL zoom_in, U8 zoom_limit, U8 zoom_step, U8 zoom_speed);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_fast_zoom
 * DESCRIPTION
 *  Stop fast zoom
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_stop_fast_zoom(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_fast_zoom_factor
 * DESCRIPTION
 *  Get current zoom factor
 * PARAMETERS
 *  factor      : [OUT]   Zoom factor     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_get_fast_zoom_factor(U32 *factor);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_fast_zoom_step
 * DESCRIPTION
 *  Get current zoom step
 * PARAMETERS
 *  step        : [OUT]   Zoom step    
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_get_fast_zoom_step(U32 *step);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_max_zoom_factor
 * DESCRIPTION
 *  Get max zoom factor
 * PARAMETERS
 *  image_width         : [IN]        Image width      
 *  image_height        : [IN]        Image height
 * RETURNS
 *  Zoom factor value
 *****************************************************************************/
extern U16 mdi_camera_get_max_zoom_factor(S32 image_width, S32 image_height);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_encode_layer_to_jpeg
 * DESCRIPTION
 *  Encode a layer and save the encode result as a file
 * PARAMETERS
 *  layer_handle        : [IN]        Layer handle
 *  file_name           : [IN]        Filename for the jpeg file
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            : Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     : Write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              : No disk
 *  MDI_RES_CAMERA_ERR_ROOT_DIR_FULL        : Root directory full
 *  MDI_RES_CAMERA_ERR_FAILED               : Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_encode_layer_to_jpeg(gdi_handle layer_handle, PS8 file_name);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_load_default_setting
 * DESCRIPTION
 *  Get camera default setting
 * PARAMETERS        
 *  camera_setting_data     : [OUT]       Camera setting structure
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_load_default_setting(mdi_camera_setting_struct *camera_setting_data);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_flash_setting
 * DESCRIPTION
 *  Turn on/off LED flash light
 * PARAMETERS
 *  is_on       : [IN]    On/off 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_flash_setting(BOOL is_on);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_focus_zone
 * DESCRIPTION
 *  Get camera driver AF zone location and 
 *  the location coordinate is the preview layer not LCD 
 * PARAMETERS
 *  zone            : [OUT]       AF zone structure        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_get_focus_zone(mdi_camera_af_window_struct *zone);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_autofocus_process
 * DESCRIPTION
 *  Start to do auto focus process
 * PARAMETERS
 *  handler        : [IN]        Auto focus finish callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_start_autofocus_process(mdi_camera_af_ind_callback handler, void* user_data);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_autofocus_process
 * DESCRIPTION
 *  Stop auto focus process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_stop_autofocus_process(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_query_support_info
 * DESCRIPTION
 *  Query camera sensor function capability
 * PARAMETERS
 *  mdi_setting_type        : [IN]        Function type
 *  p_info                  : [OUT]       Function support information structure 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_query_support_info(U32 mdi_setting_type, void *p_info);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_query_zoom_info
 * DESCRIPTION
 *  Query the zoom information
 * PARAMETERS
 *  p_info          : [OUT]        The current zoom capability
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_query_zoom_info(mdi_camera_zoom_info *p_info);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_query_panorama_zoom_info
 * DESCRIPTION
 *  Query the panorama zoom information
 * PARAMETERS
 *  p_info          : [OUT]        The current zoom capability
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_query_panorama_zoom_info(mdi_camera_zoom_info *p_info);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_fd_process
 * DESCRIPTION
 *  Start face detection process
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_start_fd_process(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_fd_process
 * DESCRIPTION
 *  Stop face detection process
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_stop_fd_process(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_fd_result
 * DESCRIPTION
 *  Get face detection result
 * PARAMETERS
 *  fd_result_p     [OUT]       Face detection result
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_get_fd_result(mdi_camera_fd_result_struct *fd_result_p);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_sd
 * DESCRIPTION
 *  Start smile detection.
 * PARAMETERS
 *  on_sd_event_cb          : [IN]        Smile Detect event callback function ptr.
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_camera_start_sd(mdi_camera_on_sd_event_cb on_sd_event_cb, void* user_data);

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_sd
 * DESCRIPTION
 *  Stop smile detection.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_camera_stop_sd(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_pause_preview_post_process
 * DESCRIPTION
 *  Pause post process
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_pause_preview_post_process(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_resume_preview_post_process
 * DESCRIPTION
 *  Resume preview post process
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_resume_preview_post_process(void);
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_hw_layer_get_content
 * DESCRIPTION
 *  Get preview buffer content.
 * PARAMETERS
 *  layer_handle          : [IN]        layer handle
 *  dst_buff_p            : [IN]        buffer address
 *  dst_buff_size         : [IN]        buffer size 
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_camera_get_hw_layer_buffer_content(gdi_handle layer_handle, U8 *dst_buff_p, U32 dst_buff_size);

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_predicted_image_size
 * DESCRIPTION
 *  Get predicted capture size.
 * PARAMETERS
 *  image_qty       : [IN]        image quality
 *  image_width     : [IN]        image width
 *  image_height    : [IN]        image height
 *  image_size_p    : [OUT]       image size
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_camera_get_predicted_image_size(U16 image_qty, U32 image_width, U32 image_height, U32* image_size_p);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_quickview_color_format
 * DESCRIPTION
 *  Get predicted capture size.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  color format
 *****************************************************************************/
extern U32 mdi_camera_get_quickview_color_format(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_with_raw_data
 * DESCRIPTION
 *  Capture an image with raw data.
 * PARAMETERS
 *  color_format        : [IN]    The color format of raw data 
 *  buffer              : [IN]    The buffer address
 *  buffer_size         : [IN]    The buffer size
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_to_memory_with_raw_data(mdi_camera_raw_data_format_enum color_format, U8* buffer, S32 buffer_size);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_capture_disable_jaia
 * DESCRIPTION
 *  Enable/disable capture with JAIA 
 * PARAMETERS
 *  is_disable          : [IN]        enable[FALSE]/disable[TRUE]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_camera_set_capture_disable_jaia(MMI_BOOL is_disable);

#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory
 * DESCRIPTION
 *  Capture a jpeg image and store the image in memory [old interface, not recommendable]
 * PARAMETERS
 *  buf_pp              : [OUT]       Pointer to a buffer pointer for jpeg file
 *  captured_size       : [OUT]       Captured size
 *  file_name           : [IN]        Filename buffer pointer
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_to_memory(U8 **buf_pp, U32 *captured_size,S8 *file_name);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_file
 * DESCRIPTION
 *  Capture one jpeg image
 * PARAMETERS
 *  file_name               : [IN]        Filename buffer pointer         
 *  continue_capture        : [IN]        Continue capture flag
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            : Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     : Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              : No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       : Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_to_file(S8 *file_name, U8 continue_capture);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_layer_to_file
 * DESCRIPTION
 *  Capture from one of layers to a jpeg file [old interface, not recommendable]
 * PARAMETERS
 *  capture_layer_flag      : [IN]        Layer configuration
 *  file_name               : [IN]        File_name buffer pointer
 *  offset_x                : [IN]        Capture region's offset x
 *  offset_y                : [IN]        Capture region's offset y
 *  width                   : [IN]        Capture region's width
 *  height                  : [IN]        Capture region's height
 *  continue_capture        : [IN]        Continue capture flag
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            : Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     : Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              : No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       : Capture failed
 *****************************************************************************/
extern MDI_RESULT mdi_camera_capture_layer_to_file(
                    U32 capture_layer_flag,
                    S8 *filename,
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height,
                    U8 continue_capture);


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_color_engine_open
 * DESCRIPTION
 *  Open MM color Engine
 * PARAMETERS   
 * RETURNS
 *  void
 *****************************************************************************/
extern MDI_RESULT mdi_camera_color_engine_open();

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_color_engine_enable
 * DESCRIPTION
 *  Enable MM color Engine
 * PARAMETERS   
 * RETURNS
 *  void
 *****************************************************************************/
extern MDI_RESULT mdi_camera_color_engine_enable();

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_color_engine_disable
 * DESCRIPTION
 *  Disable MM color Engine
 * PARAMETERS   
 * RETURNS
 *  void
 *****************************************************************************/
extern MDI_RESULT mdi_camera_color_engine_disable();

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_color_engine_close
 * DESCRIPTION
 *  Close MM color Engine
 * PARAMETERS   
 * RETURNS
 *  void
 *****************************************************************************/
extern MDI_RESULT mdi_camera_color_engine_close();

#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
#endif /* _MDI_CAMERA_H_ */ /* _CAMERA_API_H_ */

