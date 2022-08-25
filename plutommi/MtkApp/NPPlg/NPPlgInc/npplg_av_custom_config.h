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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   npplg_av_custom_config.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   This file provides the configurations of A/V Plug-in.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NPPLG_AV_CUSTOM_CONFIG_H
#define NPPLG_AV_CUSTOM_CONFIG_H

#include "npplg_av_main.h"
#include "PixcomFontEngine.h"
#include "kal_general_types.h"


/************************************************************
 * Common Configuration
 ************************************************************/

/* This configuration is the maximum number of objects that plug-in supports for one application at runtime. */
#define NPPLG_AV_CFG_MAX_OBJECT_NUM 10


/* 
 * If this compile option is defined, A/V Plug-in will seek the audio/video by ratio NPPLG_AV_CFG_SEEK_RATIO.
 * If this compile option is not defined, A/V Plug-in will seek the audio/video by a fixed time interval.
 */
#define NPPLG_AV_CFG_SEEK_BY_RATIO

#ifdef NPPLG_AV_CFG_SEEK_BY_RATIO
/* 
 * This configuration indicates how much ratio A/V Plug-in will seek at one time.
 * If the audio is 1000 seconds and the configuration is 0.01, the time A/V Plug-in will seek at one time is 10 seconds.
 */
#define NPPLG_AV_CFG_SEEK_RATIO 0.05
#else /* NPPLG_AV_CFG_SEEK_BY_RATIO */
/* 
 * This configuration indicates how much time A/V Plug-in will seek at one time.
 * The unit is ms.
 */
#define NPPLG_AV_CFG_SEEK_TIME 5000
#endif /* NPPLG_AV_CFG_SEEK_BY_RATIO */

/*
 * This configuration is used to tell plug-in that plug-in should draw one line between each playback control.
 * Not define this configuration if no need to draw line to separate playback controls
 */
#define NPPLG_AV_CFG_DRAW_SEPARATE_LINE


/************************************************************
 * Audio Configuration
 ************************************************************/

/* How many play panel style */
#ifdef __COSMOS_MMI_PACKAGE__
#define NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM 4
#else
#define NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM 5
#endif

/*
 * If NPPLG_AV_CFG_SET_DEFAULT_AUD_OBJ_SIZE is defined, application will use the 
 * following configuration (NPPLG_AV_CFG_DEFAULT_AUD_WIDTH and 
 * NPPLG_AV_CFG_DEFAULT_AUD_HEIGHT) as the default size when author does not assign 
 * object width or object height.
 *
 * If NPPLG_AV_CFG_SET_DEFAULT_AUD_OBJ_SIZE is not defined, application will use
 * ((NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM - 1) * icon_width) and (icon_height + 
 * progress_bar_height) as the default size when author does not assign object width 
 * or object height.
 */
#undef NPPLG_AV_CFG_SET_DEFAULT_AUD_OBJ_SIZE
#define NPPLG_AV_CFG_DEFAULT_AUD_WIDTH 100
#define NPPLG_AV_CFG_DEFAULT_AUD_HEIGHT 30


/************************************************************
 * Video Configuration
 ************************************************************/

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

/* How many play panel style */
#ifdef __COSMOS_MMI_PACKAGE__
#define NPPLG_AV_CFG_DIFF_VDO_PLAY_PANEL_NUM 5
#else
#define NPPLG_AV_CFG_DIFF_VDO_PLAY_PANEL_NUM 6
#endif

/* Minimum drawing width of the embedded video object */
#define NPPLG_AV_CFG_MIN_VDO_WIDTH 80

/* Minimum drawing height of the embedded video object */
#define NPPLG_AV_CFG_MIN_VDO_HEIGHT 45

/*
 * Following values are used for the video image and the video string which are 
 * shown in the blank area when video state is IDLE state.
 *
 * NPPLG_AV_CFG_VDO_BLANK_PIXEL is defined for following usage:
 * (1) the distance between video string and video image
 * (2) the distance between video string and the object border
 * (3) the distance between video image and the play panel
 *
 * NPPLG_AV_CFG_VDO_STR_COLOR_A, NPPLG_AV_CFG_VDO_STR_COLOR_R, NPPLG_AV_CFG_VDO_STR_COLOR_G
 * and NPPLG_AV_CFG_VDO_STR_COLOR_B compose the color of the video string.
 */
#define NPPLG_AV_CFG_VDO_BLANK_PIXEL 5
#define NPPLG_AV_CFG_VDO_STR_COLOR_A 200
#define NPPLG_AV_CFG_VDO_STR_COLOR_R 160
#define NPPLG_AV_CFG_VDO_STR_COLOR_G 160
#define NPPLG_AV_CFG_VDO_STR_COLOR_B 175

/*
 * If A/V Plug-in starts to play the video, it will hide the playback/volume control 
 * after a short period.
 *
 * If user presses key to let virtual cursor click the object or touches the object 
 * when browser is playing video, browser will show playback/volume control again 
 * and hide the control after a short period.
 *
 * This configuration is the value of the short period. The unit is millisecond.
 */
#define NPPLG_AV_CFG_VDO_HIDE_PLAY_PANEL_AFTER_PLAY_TIME 5000

#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */


/************************************************************
 * Extern
 ************************************************************/
extern const kal_uint8 g_npplg_av_cfg_audio_play_panel[NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM][NPPLG_AV_AUD_PANEL_MAX_SUPPORT_CTRL_NUM];

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
extern const kal_uint8 g_npplg_av_cfg_video_play_panel[NPPLG_AV_CFG_DIFF_VDO_PLAY_PANEL_NUM][NPPLG_AV_VDO_PANEL_MAX_SUPPORT_CTRL_NUM];
#endif

extern const mmi_fe_color g_npplg_av_cfg_play_time_str_color;

#endif /* NPPLG_AV_CUSTOM_CONFIG_H */
