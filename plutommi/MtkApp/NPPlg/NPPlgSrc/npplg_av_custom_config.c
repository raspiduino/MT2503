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
 *   npplg_av_custom_config.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Let customer configure the play panel
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
#if defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__)

/************************************************************
 * Include
 ************************************************************/

/* MMI header file */
#include "MMI_features.h"

/* A/V Plug-in header file */
#include "npplg_av_main.h"
#include "npplg_av_custom_config.h"

#include "PixcomFontEngine.h"
#include "kal_general_types.h"


/************************************************************
 * Global Variable
 ************************************************************/

/* 
 * Customer can fill following array to configure the audio play panel layout.
 * A/V Plug-in support six playback controls, progress bar and playing time for audio object.
 * 1. NPPLG_AV_CTRL_TYPE_PLAY
 * 2. NPPLG_AV_CTRL_TYPE_PAUSE
 * 3. NPPLG_AV_CTRL_TYPE_STOP
 * 4. NPPLG_AV_CTRL_TYPE_FAST_FORWARD
 * 5. NPPLG_AV_CTRL_TYPE_REWIND
 * 6. NPPLG_AV_CTRL_TYPE_MUTE
 * 7. NPPLG_AV_CTRL_TYPE_PROGRESS_BAR
 * 8. NPPLG_AV_CTRL_TYPE_TIME
 *
 * A/V Plug-in will bind the "Pause" control with the "Play" control.
 * Therefore, customer does not need to fill NPPLG_AV_CTRL_TYPE_PAUSE.
 * Also, customer does not need to fill NPPLG_AV_CTRL_TYPE_PROGRESS_BAR and NPPLG_AV_CTRL_TYPE_TIME.
 *
 * Default setting description:
 * The first item is used when 0 <= object_width < (2 * icon_width)
 * The second item is used when (2 * icon_width) <= object_width < (3 * icon_width)
 * The third item is used when (3 * icon_width) <= object_width < (4 * icon_width)
 * The fourth item is used when (4 * icon_width) <= object_width < (5 * icon_width)
 * The fifth item is used when (5 * icon_width) <= object_width < (6 * icon_width)
 *
 * Another example (NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM is 3): 
 * const kal_uint8 g_npplg_av_cfg_audio_play_panel[NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM][NPPLG_AV_AUD_PANEL_MAX_SUPPORT_CTRL_NUM] =
 * {{NPPLG_AV_CTRL_TYPE_PLAY, 0, 0, 0, 0},
 *  {NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_STOP, 0, 0, 0},
 *  {NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_STOP, NPPLG_AV_CTRL_TYPE_MUTE, 0, 0},
 * };
 * The first item is used when 0 <= object_width < (2 * icon_width)
 * The second item is used when (2 * icon_width) <= object_width < (3 * icon_width)
 * The third item is used when (3 * icon_width) <= object_width < (4 * icon_width)
 *
 * Note:
 * 1. The first item should have the "Play" control. Otherwise, user can not play 
 *    the audio by himself/herself.
 * 2. If the object height is tall enough to put the progress bar and playing time,
 *    A/V Plug-in will put the progress bar and playing time above the playback controls.
 * 3. 0: NPPLG_AV_CTRL_TYPE_NOT_SUPPORT
 * 4. The width of each control icon (play, pause, stop, fast forward, rewind, mute) 
 *    should be equal.
 */
#ifdef __COSMOS_MMI_PACKAGE__
const kal_uint8 g_npplg_av_cfg_audio_play_panel[NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM][NPPLG_AV_AUD_PANEL_MAX_SUPPORT_CTRL_NUM] =
{{NPPLG_AV_CTRL_TYPE_PLAY, 0, 0, 0},
 {NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_STOP, 0, 0},
 {NPPLG_AV_CTRL_TYPE_REWIND, NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_FAST_FORWARD, 0},
 {NPPLG_AV_CTRL_TYPE_REWIND, NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_FAST_FORWARD, NPPLG_AV_CTRL_TYPE_STOP}
};
#else
const kal_uint8 g_npplg_av_cfg_audio_play_panel[NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM][NPPLG_AV_AUD_PANEL_MAX_SUPPORT_CTRL_NUM] =
{{NPPLG_AV_CTRL_TYPE_PLAY, 0, 0, 0, 0},
 {NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_MUTE, 0, 0, 0},
 {NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_STOP, NPPLG_AV_CTRL_TYPE_MUTE, 0, 0},
 {NPPLG_AV_CTRL_TYPE_REWIND, NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_FAST_FORWARD, NPPLG_AV_CTRL_TYPE_MUTE, 0},
 {NPPLG_AV_CTRL_TYPE_REWIND, NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_FAST_FORWARD, NPPLG_AV_CTRL_TYPE_STOP, NPPLG_AV_CTRL_TYPE_MUTE}
};
#endif /* __COSMOS_MMI_PACKAGE__ */


/* 
 * Customer can fill following array to configure the video play panel layout.
 * A/V Plug-in support seven playback controls, progress bar and playing time for video object.
 * 1. NPPLG_AV_CTRL_TYPE_PLAY
 * 2. NPPLG_AV_CTRL_TYPE_PAUSE
 * 3. NPPLG_AV_CTRL_TYPE_STOP
 * 4. NPPLG_AV_CTRL_TYPE_FAST_FORWARD
 * 5. NPPLG_AV_CTRL_TYPE_REWIND
 * 6. NPPLG_AV_CTRL_TYPE_MUTE
 * 7. NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER
 * 8. NPPLG_AV_CTRL_TYPE_PROGRESS_BAR
 * 9. NPPLG_AV_CTRL_TYPE_TIME
 *
 * A/V Plug-in will bind the "Pause" control with the "Play" control.
 * Therefore, customer does not need to fill NPPLG_AV_CTRL_TYPE_PAUSE.
 * Also, customer does not need to fill NPPLG_AV_CTRL_TYPE_PROGRESS_BAR and NPPLG_AV_CTRL_TYPE_TIME.
 *
 * Considering user experience, inline audio/video plug-in will handle the embedded 
 * video object and draw playback control according to the object size.
 * 1. If the displaying area of the video object is too small, user can not see 
 *    the video clearly. Inline audio/video plug-in will launch media player to 
 *    play the video.
 * 2. If the displaying area of the video object is too large, user can not see 
 *    the whole video in the page rendering area. It is not convenient if user has 
 *    to scroll the page again and again to see the video or press the playback/
 *    volume control. Inline audio/video plug-in will launch media player to play the video.
 * 3. If video size is not too small and user can see the whole video in the page 
 *    rendering area. User can play the video inside the browser or launch media 
 *    player to play the video.
 *
 * Inline audio/video plug-in has two limitations for the embedded video object.
 * 1. NPPLG_AV_MAX_VDO_WIDTH: maximum drawing width of the embedded video object
 * 2. NPPLG_AV_MAX_VDO_HEIGHT: maximum drawing height of the embedded video object
 * If the width or height of the embedded video object is larger than the limitation, 
 * plug-in will let user launch the media player to play the video. Plug-in has 
 * this limitation because it is not convenient if user has to scroll the page again 
 * and again to see the video or press the playback/volume control. The value of 
 * the limitation will be changed at runtime if screen rotate.
 *
 * Inline audio/video plug-in haS two configurations for the embedded video object.
 * 1. NPPLG_AV_CFG_MIN_VDO_WIDTH: minimum drawing width of the embedded video object
 * 2. NPPLG_AV_CFG_MIN_VDO_HEIGHT: minimum drawing height of the embedded video object
 * If the width or height of the embedded video object is less than the configuration, 
 * plug-in will let user launch the media player to play the video. Plug-in has 
 * this limitation because user can not see the video clearly when the drawing size 
 * is too small.
 *
 *
 * If displaying area is less than ((2 x icon_width) x ( 2 x icon_height)), plug-in also 
 * launches media player to play the video because plug-in must place a "Media player" 
 * icon to let user launch media player to play the video and must place a "Play" 
 * icon to let user play video inside the browser.
 *
 *
 * Default setting description:
 * The first item is used when the video size is too small or too large.
 * (1) too small:
 *     Width:
 *     a. The width of the object is less than the configuration NPPLG_AV_CFG_MIN_VDO_WIDTH.
 *     b. The width of the object is less than (2 x icon_width).
 *     Height:
 *     a. The height of the object is less than the configuration NPPLG_AV_CFG_MIN_VDO_HEIGHT.
 *     b. The height of the object is less than (2 x icon_height).
 * (2) too large:
 *     Width: The width of the object is larger than the limitation NPPLG_AV_MAX_VDO_WIDTH.
 *     Height: The height of the object is larger than the limitation NPPLG_AV_MAX_VDO_HEIGHT.
 *
 * If the video size is not too small and is not too large, we will apply the following rules.
 * The second item is used when object_width < (3 * icon_width)
 * The third item is used when (3 * icon_width) <= object_width < (4 * icon_width)
 * The fourth item is used when (4 * icon_width) <= object_width < (5 * icon_width)
 * The fifth item is used when (5 * icon_width) <= object_width < (6 * icon_width)
 * The sixth item is used when (6 * icon_width) <= object_width < (7 * icon_width)
 *
 * Another example (NPPLG_AV_CFG_DIFF_VDO_PLAY_PANEL_NUM is 3): 
 * const kal_uint8 g_npplg_av_cfg_video_play_panel[NPPLG_AV_CFG_DIFF_VDO_PLAY_PANEL_NUM][NPPLG_AV_VDO_PANEL_MAX_SUPPORT_CTRL_NUM] =
 * {{NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER, 0, 0, 0, 0, 0},
 *  {NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER, NPPLG_AV_CTRL_TYPE_PLAY, 0, 0, 0, 0},
 *  {NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER, NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_STOP, 0, 0, 0},
 * };
 * The first item is used when video size is too small or video size is too large
 * The second item is used when object_width < (3 * icon_width)
 * The third item is used when (3 * icon_width) <= object_width < (4 * icon_width)
 *
 * Note:
 * 1. The first item should have the "Play" control. Otherwise, user can not play 
 *    the video by himself/herself.
 * 2. If the object height is tall enough to put the progress bar and playing time,
 *    A/V Plug-in will put the progress bar and playing time above the playback controls.
 * 3. 0: NPPLG_AV_CTRL_TYPE_NOT_SUPPORT
 * 4. The width of each control icon (play, pause, stop, fast forward, rewind, mute, 
 *    media player) should be equal.
 */
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
#ifdef __COSMOS_MMI_PACKAGE__
const kal_uint8 g_npplg_av_cfg_video_play_panel[NPPLG_AV_CFG_DIFF_VDO_PLAY_PANEL_NUM][NPPLG_AV_VDO_PANEL_MAX_SUPPORT_CTRL_NUM] =
{{NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER, 0, 0, 0, 0},
 {NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER, 0, 0, 0},
 {NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_STOP, NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER, 0, 0},
 {NPPLG_AV_CTRL_TYPE_REWIND, NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_FAST_FORWARD, NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER, 0},
 {NPPLG_AV_CTRL_TYPE_REWIND, NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_FAST_FORWARD, NPPLG_AV_CTRL_TYPE_STOP, NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER}
};
#else /* __COSMOS_MMI_PACKAGE__ */
const kal_uint8 g_npplg_av_cfg_video_play_panel[NPPLG_AV_CFG_DIFF_VDO_PLAY_PANEL_NUM][NPPLG_AV_VDO_PANEL_MAX_SUPPORT_CTRL_NUM] =
{{NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER, 0, 0, 0, 0, 0},
 {NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER, 0, 0, 0, 0},
 {NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_MUTE, NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER, 0, 0, 0},
 {NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_STOP, NPPLG_AV_CTRL_TYPE_MUTE, NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER, 0, 0},
 {NPPLG_AV_CTRL_TYPE_REWIND, NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_FAST_FORWARD, NPPLG_AV_CTRL_TYPE_MUTE, NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER, 0},
 {NPPLG_AV_CTRL_TYPE_REWIND, NPPLG_AV_CTRL_TYPE_PLAY, NPPLG_AV_CTRL_TYPE_FAST_FORWARD, NPPLG_AV_CTRL_TYPE_STOP, NPPLG_AV_CTRL_TYPE_MUTE, NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER}
};
#endif /* __COSMOS_MMI_PACKAGE__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

const mmi_fe_color g_npplg_av_cfg_play_time_str_color = {255, 51, 51, 51};


#endif /* defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__) */
