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
 *   VdoRecResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video Recorder Resource Define
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef VDO_REC_RES_DEF_H
#define VDO_REC_RES_DEF_H

#include "MMI_features.h"

#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)

#include "MMI_features_video.h"

#include "mmi_rp_app_vdorec_def.h"
#define STR_ID_VDOREC_VIDEO_QTY2    (STR_ID_VDOREC_VIDEO_QTY)

#ifdef __VDOREC_FEATURE_EFFECT__
#define STR_ID_VDOREC_EFFECT_START          STR_ID_VDOREC_EFFECT_SETTING
#endif

#ifdef __VDOREC_FEATURE_WB__
#define STR_ID_VDOREC_WB_START              STR_ID_VDOREC_WB
#endif

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
#define STR_ID_VDOREC_LED_HIGHLIGHT_START   STR_ID_VDOREC_LED_HIGHLIGHT
#endif

#ifdef __VDOREC_FEATURE_EV__
#define STR_ID_VDOREC_EV_START              STR_ID_VDOREC_EV
#endif

#ifdef __VDOREC_FEATURE_NIGHT__
#define STR_ID_VDOREC_NIGHT_START           STR_ID_VDOREC_NIGHT
#endif

#ifdef __VDOREC_FEATURE_BANDING__
#define STR_ID_VDOREC_BANDING_START         STR_ID_VDOREC_BANDING
#endif

#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
#define STR_ID_VDOREC_VIDEO_SIZE_START      STR_ID_VDOREC_VIDEO_SIZE
#endif

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
#define STR_ID_VDOREC_VIDEO_QTY_START      STR_ID_VDOREC_VIDEO_QTY /*????????*/
#endif

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
#define STR_ID_VDOREC_SIZE_LIMIT_START      STR_ID_VDOREC_SIZE_LIMIT
#endif

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
#define STR_ID_VDOREC_TIME_LIMIT_START      STR_ID_VDOREC_TIME_LIMIT
#endif

#ifdef __VDOREC_FEATURE_RECORD_AUD__
#define STR_ID_VDOREC_RECORD_AUD_START      STR_ID_VDOREC_RECORD_AUD
#endif

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
#define STR_ID_VDOREC_VIDEO_FORMAT_START      STR_ID_VDOREC_VIDEO_FORMAT
#endif

#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
#define STR_ID_VDOREC_ACCEPT_CALL_START      STR_ID_VDOREC_ACCEPT_CALL
#endif

#if 0
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


/******* [Option Menu] ********/
typedef enum
{

#ifdef __VDOREC_FEATURE_MERGE_MENU__
    VDOREC_OPTION_CAMCODER_SETTING,
#else /* __VDOREC_FEATURE_MERGE_MENU__ */ 
    VDOREC_OPTION_CAMCODER_SETTING,
    VDOREC_OPTION_VIDEO_SETTING,
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 

#ifdef __VDOREC_FEATURE_EFFECT__
    VDOREC_OPTION_EFFECT_SETTING,
#endif 

#ifdef __VDOREC_FEATURE_SELF_RECORD__
    VDOREC_OPTION_SELF_RECORD,
#endif 

#ifdef __VDOREC_FEATURE_STORAGE__
    VDOREC_OPTION_STORAGE,
#endif 

    VDOREC_OPTION_RESTORE_DEFAULT,
#ifdef __VDOREC_FEATURE_SWITCH_TO_CAMERA__
    VDOREC_OPTION_TO_CAMERA,
#endif /* __VDOREC_FEATURE_SWITCH_TO_CAMERA__ */
    VDOREC_OPTION_ITEM_COUNT
} vdorec_option_count_enum;

/******* [CamCoder Setting] ********/
typedef enum
{
#if 0
#ifdef __VDOREC_FEATURE_WB__
/* under construction !*/
#endif 
#endif
#if defined(__VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__) || defined(__VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__)
    VDOREC_CAMCODER_SETTING_LED_HIGHLIGHT,
#endif 

#ifdef __VDOREC_FEATURE_EV__
    VDOREC_CAMCODER_SETTING_EV,
#endif 

#ifdef __VDOREC_FEATURE_NIGHT__
    VDOREC_CAMCODER_SETTING_NIGHT,
#endif 

#ifdef __VDOREC_FEATURE_BANDING__
    VDOREC_CAMCODER_SETTING_BANDING,
#endif 

#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    VDOREC_VIDEO_SETTING_ACCEPT_CALL,    
#endif

#ifdef __VDOREC_FEATURE_MERGE_MENU__
    /* merge "Video Setting" items into "CamCoder Setting" */
#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    VDOREC_VIDEO_SETTING_VIDEO_QTY,
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    VDOREC_VIDEO_SETTING_SIZE_LIMIT,
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    VDOREC_VIDEO_SETTING_TIMER_LIMIT,
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    VDOREC_VIDEO_SETTING_RECORD_AUD,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    VDOREC_VIDEO_SETTING_VIDEO_FORMAT,
#endif 
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 

    VDOREC_CAMCODER_SETTING_ITEM_COUNT
} vdorec_camcoder_setting_count_enum;

/******* [Video Setting] ********/
#ifndef __VDOREC_FEATURE_MERGE_MENU__

typedef enum
{

#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    VDOREC_VIDEO_SETTING_VIDEO_SIZE,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    VDOREC_VIDEO_SETTING_VIDEO_QTY,
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    VDOREC_VIDEO_SETTING_SIZE_LIMIT,
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    VDOREC_VIDEO_SETTING_TIMER_LIMIT,
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    VDOREC_VIDEO_SETTING_RECORD_AUD,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    VDOREC_VIDEO_SETTING_VIDEO_FORMAT,
#endif 

    VDOREC_VIDEO_SETTING_ITEM_COUNT
} vdorec_video_setting_count_enum;

#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 


/***************************************************************************** 
 * Image
 *****************************************************************************/

#if 0
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
#ifdef __VDOREC_FEATURE_EV_4__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EV_3__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EV_2__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VDOREC_FEATURE_EV_2__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EV_3__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EV_4__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_1__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_2__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_3__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_4__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_5__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_6__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_7__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_8__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_9__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_10__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_1__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_2__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_3__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_4__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_5__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_6__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_7__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_8__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_9__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_10__
/* under construction !*/
#endif 
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
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
/* under construction !*/
#endif 
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
#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_AUTO__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_DAYLIGHT__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_TUNGSTEN__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_FLUORESCENT__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_CLOUD__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_INCANDESCENCE__
/* under construction !*/
#endif 
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__VDOREC_FEATURE_RSK_DELETE__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__VDOREC_FEATURE_MERGE_SEND_OPTION__)
/* under construction !*/
#else  /* __VDOREC_FEATURE_MERGE_SEND_OPTION__ */
    #ifdef __MMI_VDOREC_MMS_SUPPORT__   
/* under construction !*/
    #endif     
    #ifdef __MMI_VDOREC_EMAIL_SUPPORT__
/* under construction !*/
    #endif 
    #ifdef __MMI_OPP_SUPPORT__
/* under construction !*/
    #endif
#endif /* __VDOREC_FEATURE_MERGE_SEND_OPTION__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_VDOREC_MMS_SUPPORT__   
/* under construction !*/
#endif     
#ifdef __MMI_VDOREC_EMAIL_SUPPORT__
/* under construction !*/
#endif 
#if defined(__MMI_OPP_SUPPORT__)
/* under construction !*/
#endif
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
#ifdef __VDOREC_COLOR_IDX_FRAME_1__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_2__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_3__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_4__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_5__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_6__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_7__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_8__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_9__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_COLOR_IDX_FRAME_10__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_AUTO__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_DAYLIGHT__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_TUNGSTEN__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_FLUORESCENT__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_CLOUD__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_INCANDESCENCE__
/* under construction !*/
#endif 
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
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 
/* under construction !*/
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VDOREC_FEATURE_EV_4__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EV_3__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EV_2__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VDOREC_FEATURE_EV_2__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EV_3__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EV_4__
/* under construction !*/
#endif 
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
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
/* under construction !*/
#endif 
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
#ifdef __VDOREC_FEATURE_EFFECT_NORMAL__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_GRAYSCALE__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_SEPIA__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_GRAY_INVERT__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_BLACKBOARD__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_WHITEBOARD__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_BLUE_CARVING__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_EMBOSSMENT__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_CONTRAST__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_JEAN__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_SKETCH__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_EFFECT_OIL__
/* under construction !*/
#endif 
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __MMI_VIDEO_RECORDER__ && !__MMI_CAMCORDER__ */
#endif /* VDO_REC_RES_DEF_H */ 


