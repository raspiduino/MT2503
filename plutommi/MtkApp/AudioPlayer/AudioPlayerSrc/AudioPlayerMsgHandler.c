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
*  AudioPlayerMsgHandler.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player message handling
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/




#include "MMI_features.h"

#ifdef __MMI_AUDIO_PLAYER__

//#include "HardwareEvents.h"
#include "IdleAppDef.h"
#include "CommonScreens.h"

/* dependent headers for AudioPlayerXXX.h" */
#include "mdi_datatype.h"
//#include "gpioInc.h"
#include "mdi_audio.h"
#include "AudioPlayerDef.h"
#include "AudioPlayerType.h"
#include "AudioPlayerProt.h"
#include "AudioPlayerMainScreen.h"
#include "AudioPlayerPlayList.h"
#include "Filemgrsrvgprot.h"
#include "AlertScreen.h"
#include "IdleGprot.h"
/*DRM related*/
#include "DRM_gprot.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_timer_gprot.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_audioplayer_def.h"
#include "gui_data_types.h"
#include "wgui_categories_util.h"
#include "gui_typedef.h"
#include "device.h"
#include "AudioPlayerResDef.h"
#include "GlobalResDef.h"
#include "CommonScreensResDef.h"
#include "fs_type.h"
#include "drm_def.h"
#include "fs_errcode.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_scenario_gprot.h"
#include "BTMMIA2DPScr.h"
//#include "GeneralDeviceGprot.h"
#ifdef __MMI_HF_SUPPORT__
#include "BthScoPathSrvGprot.h"
#endif /* __MMI_HF_SUPPORT__ */
#ifdef __MMI_A2DP_SUPPORT__
#include "av_bt.h"
MMI_BOOL wait_open_bt = MMI_FALSE;
#endif

/*
#ifdef __MTK_TARGET__
#ifdef MT6253
#include "custom_emi_release.h"
#endif
#endif
*/

#include "gpiosrvgprot.h"

MMI_BOOL g_audply_A2DP_spectrum_need_blocked = MMI_FALSE;

extern MMI_BOOL g_mmi_audply_play_completed_after_button_down;  /* defined in AudioPlayerSrc.c */
extern MMI_BOOL g_mmi_audply_init_done;                         /* defined in AudioPlayerSrc.c */
/* for memery card plug-in and plug-out */

extern void (*RedrawCategoryFunction) (void);   /* defined in wgui_categories.c */
extern void idle_screen_show_network_details(void);  /* defined in wgui_categories_idlescreen.c */

extern audply_struct g_audply;  /* defined in AudioPlayerSrc.c */

extern MMI_BOOL g_mmi_audply_longpressed; /* defined in AudioPlayerSrc.c */

#ifdef __MTK_TARGET__
extern __align(4) U8 audio_cache[BUILD_CACHE_SIZE]; /* defined in AudioPlayerSrc.c */
#else
extern U8 audio_cache[BUILD_CACHE_SIZE]; /* defined in AudioPlayerSrc.c */
#endif /* __MTK_TARGET__ */

extern MMI_BOOL g_mmi_audply_longpressed ;



extern S16 g_audply_main_selected_button;   /* defined in AudioPlayerMainScreen.c */
extern MMI_BOOL g_audply_main_selected_button_down;     /* defined in AudioPlayerMainScreen.c */

#ifdef __MMI_A2DP_SUPPORT__
static kal_bool to_resume = KAL_FALSE;
#endif


#define MSG_HDLR_VARIABLES
#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
extern MMI_BOOL g_audply_spectrum_blocked;
#endif

#if defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
extern audply_lyric_struct audply_lyric;
extern audply_lyric_printing_struct audply_lyric_print;
extern MMI_BOOL lyric_reEntry;
extern MMI_BOOL lyric_parse_ok;
#ifdef __GDI_MEMORY_PROFILE_2__
extern GDI_HANDLE audply_osd_layer;      /* defined in AudioPlayerMainScren.c */
#endif /*__GDI_MEMORY_PROFILE_2__*/
#endif


#define MSG_HDLR_PROTOTYPES
static MMI_BOOL mmi_audply_is_play_speed_normal(void);
static void mmi_audply_do_play_action(void);
static mmi_ret mmi_audply_do_play_action_pop_cb(mmi_event_struct *evt);
static S32 mmi_audply_do_portion_play_action_without_handle_result(CHAR* error_class);
void mmi_audply_do_stop_action(MMI_BOOL clear_bg_handler);

BOOL mmi_audply_background_callback_hdlr(mdi_result result, void *user_data);
static void mmi_audply_play_callback_hdlr(mdi_result result, void *user_data);
static void mmi_audply_pause_callback_hdlr(mdi_result result, void *user_data);
static void mmi_audply_do_pause_action(MMI_BOOL need_pop_up);
static void mmi_audply_do_resume_action(void);
static void mmi_audply_auto_update_duration_hdlr(U32 duration);

static void mmi_audply_play_completed_callback(void);
static void mmi_audply_play_completed(void);
static void mmi_audply_stopped(MMI_BOOL clear_bg_handler);
static void mmi_audply_played(void);
static void mmi_audply_paused(void);
static void mmi_audply_resumed(void);


#define MSG_HDLR_CODE

#ifdef __MMI_A2DP_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_play_speed_normal
 * DESCRIPTION
 *  return is the current play speed normal
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_is_play_speed_normal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_TIME_STRETCH__
    return g_audply.speed == MDI_AUDIO_SPEED_NORMAL;
#else
    return MMI_TRUE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_wait_open_bt
 * DESCRIPTION
 *  return if it's waiting for opening bt
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_is_wait_open_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wait_open_bt;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bt_open_callback
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_bt_open_callback(srv_bt_cm_bt_addr *address, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL prev_wait_open_bt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BT_CALLBACK,result,g_audply.state,to_resume);

    prev_wait_open_bt = wait_open_bt;

    
    //bql: confused about the follow error handling
    if (g_mmi_audply_longpressed)
    {
        if (result == AV_BT_CALLBACK_EVENT_STREAM_START_IND)
        {
            //mtk54262 mod
            srv_a2dp_pause_stream();
            //av_bt_close(KAL_FALSE);
        }
        return;
    }
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
    switch (result)
    {
    case AV_BT_CALLBACK_EVENT_OPEN_OK:
        if (g_audply.state == STATE_PLAY)
        {
            //srv_a2dp_start_stream(mmi_a2dp_get_bt_headset());

			wait_open_bt = MMI_TRUE;
            srv_a2dp_reconfig_start_streaming(
                        mmi_a2dp_get_bt_headset(), 
                        g_audply.filefullname, 
                        0, 
                        0, 
                        MMI_TRUE);

       
             if (g_audply_A2DP_spectrum_need_blocked)
             {
                 
            #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
                g_audply_spectrum_blocked = MMI_TRUE;
                mmi_audply_turn_off_spectrum();
            #endif
             }
        
        }
        else
        {
			wait_open_bt = MMI_TRUE;
            srv_a2dp_reconfig_start_streaming(
                        mmi_a2dp_get_bt_headset(), 
                        g_audply.filefullname, 
                        0, 
                        0, 
                        MMI_TRUE);
            
        
            if (g_audply_A2DP_spectrum_need_blocked)
            {
            #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
                g_audply_spectrum_blocked = MMI_TRUE;
            #endif
            }
        
            
        }
        break;
    case AV_BT_CALLBACK_EVENT_OPEN_FAILED:
    case AV_BT_CALLBACK_EVENT_OPEN_STOPPED:
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    case AV_BT_CALLBACK_EVENT_OPEN_SCO:
#endif
        if (g_audply.state == STATE_PLAY)
        {
            srv_a2dp_pause_stream();
//            av_bt_close_codec();
        
            if (g_audply_A2DP_spectrum_need_blocked)
            {
                #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
                g_audply_spectrum_blocked = MMI_FALSE;
                mmi_audply_turn_on_spectrum();
                #endif            
            }
        
        }
        else if (to_resume)
        {
            ASSERT(g_audply.state == STATE_PAUSED);
            to_resume = KAL_FALSE;
            /*change state because it is not called by button pressing and 
              it might already be in main screen so there is no chance to update 
              state by calling entry main screen*/
            g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
            g_audply_main_selected_button_down = MMI_FALSE;                            
            mmi_audply_do_resume_action();
        }
        else
        {
            mmi_audply_do_play_action();
        }
        break;
    case AV_BT_CALLBACK_EVENT_OPEN_CANCELED:
        mmi_audply_bt_stop(KAL_TRUE, KAL_FALSE);
        to_resume = KAL_FALSE;
        g_audply.need_replay = prev_wait_open_bt;

        /*when ab bt is canceled by mdi (interrupted callback), we shall update the play button
          since nobody else will release the button in this situation*/        
        g_audply_main_selected_button = AUDPLY_MAIN_PAUSE;
        g_audply_main_selected_button_down = MMI_FALSE;
        if (g_audply.in_main_screen)
        {
            mmi_audply_redraw_main_buttons();
        }        
        break;
    case AV_BT_CALLBACK_EVENT_STREAM_ABORT_IND:
    case AV_BT_CALLBACK_EVENT_STREAM_CLOSE_IND:
    case AV_BT_CALLBACK_EVENT_STREAM_SUSPEND_IND:
    case AV_BT_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
         wait_open_bt = MMI_FALSE;
        if (g_audply.state == STATE_PLAY)
        {
           // srv_a2dp_pause_stream();
        
            if (g_audply_A2DP_spectrum_need_blocked)
            {
                #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
                g_audply_spectrum_blocked = MMI_FALSE;
                mmi_audply_turn_on_spectrum();
                #endif
            }
        
        }
        else if (prev_wait_open_bt == MMI_TRUE)
        {
        /*    if (to_resume && g_audply.state == STATE_PAUSED)
            {
                to_resume = KAL_FALSE;
                g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
                g_audply_main_selected_button_down = MMI_FALSE;                                
                mmi_audply_do_resume_action();
            }
            else
            {
                mmi_audply_do_play_action();
        }    */
        }    
        break;
    case AV_BT_CALLBACK_EVENT_STREAM_START_IND:
        wait_open_bt = MMI_FALSE;
        if (mmi_a2dp_is_output_to_bt())
        {
           if (to_resume && g_audply.state == STATE_PAUSED)
            {
                to_resume = KAL_FALSE;
                /*change state because it is not called by button pressing and 
                  it might already be in main screen so there is no chance to update 
                  state by calling entry main screen*/
                g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
                g_audply_main_selected_button_down = MMI_FALSE;                                
                mmi_audply_do_resume_action();
            }
            else
            {   //bql: what if (g_audply.state == STATE_IDLE) ? Do we also need to do_play_action?
                to_resume = KAL_FALSE;
                mmi_audply_do_play_action();
            }
            if (g_audply.state == STATE_IDLE)
        {
            	kal_prompt_trace(MOD_MMI_MEDIA_APP,"mmi_audply_bt_open_callback pause 1");
                srv_a2dp_pause_stream();
            
                if (g_audply_A2DP_spectrum_need_blocked)
                {
                    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
                    g_audply_spectrum_blocked = MMI_FALSE;
                    #endif
                }
            
            }
        }
        else
        {
            //mtk54262 del
            //av_bt_close(KAL_FALSE);
            
            srv_a2dp_delete_app_callback();
        }
        break;
        
    case AV_BT_CALLBACK_EVENT_INQUIRY_START_IND:
        if (mmi_a2dp_is_output_to_bt() && av_bt_is_streaming() &&
            g_audply.state == STATE_PLAY)
        {
            mmi_audply_do_pause_action(MMI_FALSE);
            if (g_audply.state != STATE_PLAY)
            {
                srv_a2dp_pause_stream();
            
                if (g_audply_A2DP_spectrum_need_blocked)
                {
                  #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
                  g_audply_spectrum_blocked = MMI_FALSE;  
                  #endif                
                }
            
            }
            if (g_audply.state == STATE_PAUSED)
            {
                to_resume = KAL_TRUE;
                av_bt_pause();
            }
        }
        break;
    case AV_BT_CALLBACK_EVENT_INQUIRY_STOP_IND:
        if (to_resume)
        {
            if (g_audply.state == STATE_PAUSED)
            {
                mmi_audply_resume();
            }
            else if (g_audply.state == STATE_IDLE && !wait_open_bt)
            {
                //mtk54262 mod
                //av_bt_close(KAL_FALSE);
                srv_a2dp_delete_app_callback();
            }
        }
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_switch_bt_output
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_switch_bt_output(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_SWITCH_BT_OUTPUT, g_audply.state);

    //mtk54262 add
    srv_a2dp_set_app_callback(mmi_audply_bt_open_callback);
    if (mmi_a2dp_is_output_to_bt())
    {
        /* switch output: OFF -> ON */
        if (g_audply.state == STATE_PLAY)
        {
            wait_open_bt = MMI_TRUE;
            
            //mtk54262 begin
            //srv_a2dp_set_default_callback(mmi_audply_bt_open_callback);
            //srv_a2dp_start_stream(mmi_a2dp_get_bt_headset());
            
            srv_a2dp_reconfig_start_streaming(
                        mmi_a2dp_get_bt_headset(), 
                        g_audply.filefullname, 
                        0, 
                        0, 
                        MMI_TRUE);
//            wait_open_bt = MMI_TRUE;
//            av_bt_open((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(), g_audply.prev_filefullname, 
//                mmi_audply_bt_open_callback, (kal_bool)!mmi_audply_is_play_speed_normal(),
//                KAL_TRUE);
        }
    }
    else
    {
        /* switch output: ON -> OFF */
        if (g_audply.state == STATE_PLAY)
        {
            srv_a2dp_pause_stream();
            if (g_audply_A2DP_spectrum_need_blocked)
            {
            	#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
                g_audply_spectrum_blocked = MMI_FALSE;
                mmi_audply_turn_on_spectrum();
                #endif    
            }
        
        }
        
        //mtk54262 mod
        //av_bt_close(KAL_FALSE);
        srv_a2dp_delete_app_callback();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_turn_off_bt_output
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_turn_off_bt_output(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_SWITCH_BT_OUTPUT, g_audply.state);
    /* switch output: ON -> OFF */
    if (g_audply.state == STATE_PLAY)
    {
        srv_a2dp_pause_stream();
    
        if (g_audply_A2DP_spectrum_need_blocked)
        {
            #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
            g_audply_spectrum_blocked = MMI_FALSE;
            mmi_audply_turn_on_spectrum();
            #endif    
        }
    
    }

    //mtk54262 mod
    //av_bt_close(KAL_TRUE);
    srv_a2dp_delete_app_callback();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sync_bt_output
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_sync_bt_output(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    AV_BT_CALLBACK callback = NULL;
    kal_wchar *filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_SYNC_BT_OUTPUT);

    ASSERT(mmi_a2dp_is_output_to_bt());
    
    filename = g_audply.filefullname;
    to_resume = KAL_FALSE;
    if (g_audply.state == STATE_PLAY)
    {
        mmi_audply_do_stop_action(MMI_FALSE);
//        av_bt_close_codec();
    
            if (g_audply_A2DP_spectrum_need_blocked)
            {
            	#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
                g_audply_spectrum_blocked = MMI_FALSE;
                /*normally not need to turn on spectrum, in case pause not succeed*/
                mmi_audply_turn_on_spectrum();
               #endif        
            }  
        
        callback = mmi_audply_bt_open_callback;
        filename = g_audply.prev_filefullname;
       }
    else if (wait_open_bt)
    {
        callback = mmi_audply_bt_open_callback;
    }

    //mtk54262 add
    srv_a2dp_set_app_callback(mmi_audply_bt_open_callback);
    if (callback && mmi_a2dp_is_output_to_bt())
    {
        //srv_a2dp_start_stream(mmi_a2dp_get_bt_headset());
        
        wait_open_bt = MMI_TRUE;
        srv_a2dp_reconfig_start_streaming(
                    mmi_a2dp_get_bt_headset(), 
                    g_audply.filefullname, 
                    0, 
                    0, 
                    MMI_TRUE);
//        av_bt_open((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(), filename, callback, 
//            (kal_bool)!mmi_audply_is_play_speed_normal(), KAL_TRUE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bt_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stop_codec      [IN]
 *  notify_opener   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_bt_stop(MMI_BOOL stop_codec, MMI_BOOL notify_opener) //bql: dummy para of stop_codec
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* always stop codec*/
    if( mmi_a2dp_is_output_to_bt() )
    {
        srv_a2dp_pause_stream();
        
        if (g_audply_A2DP_spectrum_need_blocked)
        {
             #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
             g_audply_spectrum_blocked = MMI_FALSE;
             mmi_audply_turn_on_spectrum();
            #endif    
        }
        
        //mtk54262 add
        //av_bt_close(notify_opener);
        srv_a2dp_delete_app_callback();
    }
    wait_open_bt = MMI_FALSE;
}
#endif /* __MMI_A2DP_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_delay_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_delay_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bg_suspend = MMI_FALSE;
    S32 order = -1;
    U8 empty = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_DELAY_PLAY,g_audply.state);

    if (g_audply.state == STATE_PLAY)
    {
        mmi_audply_play();
        return;
    }

    bg_suspend = mdi_audio_is_background_play_suspended();
    order = mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY);
    empty = mdi_audio_get_background_callback_register_app_num();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_FOUR_VALS,bg_suspend,order,empty,-1);

    /*check if someone calls suspend background play during wait next time*/
    if (bg_suspend || (order != 0 && empty == 0))
    {
        g_audply.need_replay = MMI_TRUE;
        return;
    }
    else
    {
        mmi_audply_play();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_play(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__  
    mmi_audply_set_LSK_text(STR_GLOBAL_PAUSE);
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_LSK_up();
    }
#endif

    /*since wait next and stop timer is reset in do_play_action, if user press stop while bt 
      it connecting, which will stop bt action and do_play_action will never have chance to
      execute so that wait_next flag will always be on. so reset them when play is execute*/
    StopTimer(AUDPLY_DELAY_PLAY_TIMER);
    g_audply.wait_next = MMI_FALSE;

#ifdef __MMI_A2DP_SUPPORT__
    to_resume = KAL_FALSE;
    //mtk54262 add
    srv_a2dp_set_app_callback(mmi_audply_bt_open_callback);
    if (mmi_a2dp_is_output_to_bt())
    {
        if (g_audply.state == STATE_PLAY)
        {
            mmi_audply_do_stop_action(MMI_TRUE);
            srv_a2dp_pause_stream();
        
            if (g_audply_A2DP_spectrum_need_blocked)
            {
                #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
                g_audply_spectrum_blocked = MMI_FALSE;
                mmi_audply_turn_on_spectrum();
                #endif
            }    
        
        }    
//        wait_open_bt = MMI_TRUE;
    
        /*handle background play*/
        if (g_audply.in_audio_player == MMI_FALSE)
        {
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_AUDPLY, mmi_audply_background_callback_hdlr, NULL);
        }
        
        srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);

//        av_bt_open(
//            (srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(), 
//            g_audply.filefullname, 
//            mmi_audply_bt_open_callback, 
//            (kal_bool)!mmi_audply_is_play_speed_normal(), //bql: the meaning of this para (sbc_only)?
//            KAL_TRUE);
    }
    else
#endif /* __MMI_A2DP_SUPPORT__ */
    {
        /*handle background play*/
        if (g_audply.in_audio_player == MMI_FALSE)
        {
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_AUDPLY, mmi_audply_background_callback_hdlr, NULL);
        }
        mmi_audply_do_play_action();    /* do play action */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* do pause action */
	if(g_audply.is_support_pause)
	{  
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__  
        mmi_audply_set_LSK_text(STR_GLOBAL_PLAY);
        if (g_audply.in_main_screen)
        {
            mmi_audply_redraw_LSK_up();
        }
        #endif   
    	mmi_audply_do_pause_action(MMI_TRUE); 
	}
	else
	{
		mmi_audply_stop_playing();
		mmi_popup_display_ext(
                    STR_ID_AUDPLY_CANNOT_PAUSE, 
                    MMI_EVENT_FAILURE,
                    NULL);
	}
#ifdef __MMI_A2DP_SUPPORT__
    if( mmi_a2dp_is_output_to_bt() )
    {
        if( g_audply.state != STATE_PLAY )
        {
            srv_a2dp_delete_app_callback();
            srv_a2dp_pause_stream();
        
            if (g_audply_A2DP_spectrum_need_blocked)
            {
                #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
                g_audply_spectrum_blocked = MMI_FALSE;
                #endif            
            } 
            //mtk54262 mod
            //av_bt_close(KAL_FALSE);
            srv_a2dp_delete_app_callback();
        }
    }
#endif /* __MMI_A2DP_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_pause_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_do_pause_action(MMI_BOOL need_pop_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.need_replay = MMI_FALSE;
    result = mdi_audio_pause(mmi_audply_pause_callback_hdlr, NULL);

    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_audply_paused();
    }
    else if (result == MDI_AUDIO_UNSUPPORTED_OPERATION)
    {
        /* Pause action for AAC / ADIF format not supported */
        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
        if (need_pop_up)
        {
                mmi_popup_display_ext(
                    STR_ID_AUDPLY_CANNOT_PAUSE, 
                    MMI_EVENT_FAILURE,
                    NULL);
        }
    }
    else
    {
        mmi_audply_play_completed();
    }

    /* If not continue playing, restore speed */
#if defined(__MMI_AUDIO_TIME_STRETCH__)
    if (result != MDI_AUDIO_UNSUPPORTED_OPERATION)
    {
        mmi_audply_speed_close();
    }
#endif	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pause_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_pause_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.state != STATE_PAUSED)
    {
        return;
    }

    /* Handle the result */
    g_audply.need_replay = MMI_FALSE;

    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
            mmi_audply_play_completed();
            break;
        case MDI_AUDIO_TERMINATED:
            /* Stop file but let progress bar stop where it is */
            mmi_audply_seek_stop_playing();
            break;
        default:
            mmi_audply_clear_play_seconds();
            mmi_audply_stopped(MMI_FALSE);   
            {
                mmi_audply_display_popup(result, NULL, NULL);
            }
            break;
    } /* end switch */
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_paused
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_paused(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Update the state */
    g_audply.state = STATE_PAUSED;

    mmi_audply_update_play_seconds();
    StopTimer(AUDPLY_COUNT_PLAY_TIMER);


      {
    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
        mmi_audply_calc_spectrum(MMI_FALSE);
    #endif 

    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        mmi_audply_lyric_check_backlight(MMI_FALSE);
    #endif 
      }   
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
        mmi_audply_spectrum_display_stop();
    #endif 
    }

    mmi_idle_update_service_area();

    /* Update the status icon */
    HideStatusIcon(STATUS_ICON_AUDPLY);//xudong: please refer [MAUI_01897542] Revise Status icon bar
    StartTimer(AUDPLY_STATUS_ICON_TIMER, 100, UpdateStatusIcons);
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_resume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__  
    mmi_audply_set_LSK_text(STR_GLOBAL_PAUSE);
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_LSK_up();
    }
#endif
#ifdef __MMI_A2DP_SUPPORT__
    //mtk54262 add
    srv_a2dp_set_app_callback(mmi_audply_bt_open_callback);
    if (mmi_a2dp_is_output_to_bt())
    {
        to_resume = KAL_TRUE;
        //wait_open_bt = MMI_TRUE;

        //mtk54262 begin
        //srv_a2dp_set_default_callback(mmi_audply_bt_open_callback);
        srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    }
    else
#endif /* __MMI_A2DP_SUPPORT__ */
    {
        /* do resume action */
        mmi_audply_do_resume_action();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_resume_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_do_resume_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.need_replay = MMI_FALSE;

    /* Set play speed before resume, no need to check the support */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_audply_speed_set_speed();
#endif 
    
    /* In case it is muted by profile switching */
#if 1
    mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)MDI_AUD_VOL_EX_MUTE(g_audply.volume));
#else
/* under construction !*/
#endif /*__MMI_FTE_SUPPORT__*/
       
    result = mdi_audio_resume(mmi_audply_play_callback_hdlr, NULL);    

    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_audply_resumed();
    }
    else if (result == MDI_AUDIO_END_OF_FILE)
    {
        /* Play paused when file finished */
        mmi_audply_play_completed();
    }
    else
    {
        g_audply.state = STATE_IDLE;
    
    #ifdef __MMI_AUDIO_TIME_STRETCH__
        /* Reset speed if not play successfully */
        mmi_audply_speed_close();
    #endif /* __MMI_AUDIO_TIME_STRETCH__ */ 
    
        {
            mmi_audply_display_popup(result, NULL, NULL);
        }
    }
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_resumed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_resumed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Update the state */
    g_audply.state = STATE_PLAY;
    StartTimer(AUDPLY_COUNT_PLAY_TIMER, 500, mmi_audply_timer);
    {
    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_SUBLCD__)
        if (g_audply.spectrum_style != 0 && mmi_audply_is_spectrum_valid() && !g_audply_spectrum_blocked)
        {
            mmi_audply_calc_spectrum(MMI_TRUE);
        }
    #endif /* defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_SUBLCD__) */ 

    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        mmi_audply_lyric_check_backlight(MMI_TRUE);
    #endif 
    } 
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        if (g_audply.spectrum_style != 0 && mmi_audply_is_spectrum_valid() &&
			!g_audply_spectrum_blocked)
        {
            mmi_audply_spectrum_display_start();
        }
    #endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
    }

    mmi_idle_update_service_area();    

    /*Update status icon*/
    ShowStatusIcon(STATUS_ICON_AUDPLY); //xudong: please refer [MAUI_01897542] Revise Status icon bar
    StartTimer(AUDPLY_STATUS_ICON_TIMER,100,UpdateStatusIcons);  
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(APP_AUDIOPLAYER,MDI_AUD_VOL_LEVEL_EXTEND_MUTE,mmi_audply_handfree_volume_sync_callback);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_play_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_do_play_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    CHAR  error_class = 0;
    S32 total = mmi_audply_playlist_get_total();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HF_SUPPORT__
#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
    srv_btsco_dialer_stop_single_sco();
#endif
#endif /* __MMI_HF_SUPPORT__ */
#ifdef __BT_SPEAKER_SUPPORT__
    if (srv_a2dp_sink_is_streaming())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PLAY,-2,-1);
        mdi_audio_stop_all();
        //mdi_audio_set_background_handler(MDI_BACKGROUND_APP_AUDPLY, mmi_audply_background_callback_hdlr, NULL);
    }
#endif 
    result =  mmi_audply_do_portion_play_action_without_handle_result((CHAR*)&error_class);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PLAY,result,error_class);

    if (error_class == 1)
    {
        /*not filemgr issue*/
        if (result == MDI_AUDIO_SUCCESS)
        {
            g_audply.successive_fail_num = 0;
        #ifdef __DRM_SUPPORT__            
            g_audply.DRM_consumed = MMI_TRUE;
        #endif
            mmi_audply_played();
        }
        else if (result == MDI_AUDIO_END_OF_FILE)
        {
            mmi_audply_play_completed();    /* in the case that we stopped a file when it's play finished */
        }
        else
        {
            if (result == MMI_AUDPLY_NOT_ALLOW_PLAY)
            {
                mmi_audply_stopped(MMI_FALSE);
            }
            else
            {
                mmi_audply_stopped(MMI_TRUE);
            }
            
            if (result <= MDI_AUDIO_FAIL && result != MDI_AUDIO_BLOCKED)
            {
                g_audply.successive_fail_num ++;

                mmi_audply_clear_play_seconds();

                {
                    g_audply.seekable = MMI_FALSE;
                #ifdef __MMI_BTD_BOX_UI_STYLE__
                    if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
                #else
                    if (g_audply.repeat_mode != REPEAT_ONE &&
                        total > 1 &&
                        g_audply.successive_fail_num < total)
                #endif
                    {
                        if (g_audply.in_audio_player == MMI_FALSE)
                        {
                            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_AUDPLY, mmi_audply_background_callback_hdlr, NULL);
                        }
                        //apply and pick next file in play_completed
                        mmi_audply_display_popup(result, mmi_audply_play_completed_callback, mmi_audply_play_completed);
                        g_audply.wait_next_with_pop_up = MMI_TRUE;
                    }
                    else
                    {
                        g_audply.old_play_time = 0 ;
                        /*handle background play*/
                        if(mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY)>=0 && 
                            g_audply.in_audio_player == MMI_FALSE)
                        {
                            mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_AUDPLY);
                        } 
                        mmi_audply_display_popup(result, NULL, NULL);
                    }
                }
            }
            if (g_audply.successive_fail_num == total)
            {
               g_audply.successive_fail_num = 0 ; 
            }
        }
    }
    else if (error_class == 0)
    {
        /*filemgr issue*/
        mmi_audply_stopped(MMI_TRUE);//bql: clear audio player background handler, but why or why not?
        
        g_audply.successive_fail_num++;
       
        {
            g_audply.seekable = MMI_FALSE;
            if (g_audply.repeat_mode != REPEAT_ONE &&
                total > 1 &&
                g_audply.successive_fail_num < total)
            {
                if (g_audply.in_audio_player == MMI_FALSE)
                {
                    mdi_audio_set_background_handler(MDI_BACKGROUND_APP_AUDPLY, mmi_audply_background_callback_hdlr, NULL);
                }
                do
                {
                    //bql: should we use the newly wrapper of mmi_audply_display_popup with callback?
                    //mmi_audply_display_popup() and we also need update mmi_audply_err_str() to support fs error or string id
                    mmi_popup_property_struct arg;
                    mmi_popup_property_init(&arg);
                    if (!g_audply.background_play)
                    {
                        arg.parent_id = GRP_ID_AUDPLY_MAIN;
                    }
                    else
                    {
                        arg.parent_id = GRP_ID_ROOT; 
                    }

                    arg.callback = (mmi_proc_func)mmi_audply_do_play_action_pop_cb;
                    mmi_popup_display_ext(
                        srv_fmgr_fs_error_get_string_and_popup_type(result, 0), 
                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result), 
                        &arg);
                }
                while(0);

                g_audply.wait_next_with_pop_up = MMI_TRUE;
            }
            else
            {
                g_audply.old_play_time = 0 ;
                /*handle background play*/
                if(mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY)>=0 && 
                   g_audply.in_audio_player == MMI_FALSE)
                {
                    mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_AUDPLY);
                } 
                mmi_popup_display_ext(
                    (srv_fmgr_fs_error_get_string_and_popup_type(result, 0)), 
                    (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result), 
                    NULL);  
            }

        }
        if(g_audply.successive_fail_num == total)
        {
           g_audply.successive_fail_num = 0 ; 
        }        
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_play_action_pop_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_audply_do_play_action_pop_cb(mmi_event_struct *evt)
{
	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (EVT_ID_ALERT_QUIT == evt->evt_id)
    {
        mmi_alert_result_evt_struct *param = (mmi_alert_result_evt_struct *)evt;
        switch (param->result)
        {

        case MMI_ALERT_NORMAL_EXIT:
            mmi_audply_play_completed_callback(); //<execute popup callback here>
            break;
        case MMI_ALERT_INTERRUPT_EXIT:
            mmi_audply_play_completed(); //<execute exit callback here>
            break;
        }
    }
    return MMI_RET_OK;
}     



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_portion_play_action_without_handle_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_class     [OUT] 
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_audply_do_portion_play_action_without_handle_result(CHAR* error_class)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    U8* cache_ptr = NULL;
    FS_HANDLE handle;
#ifdef __MMI_AUDIO_TIME_STRETCH__
    S32 check_result;
#endif 

    MMI_BOOL bg_suspend = MMI_FALSE;
    S32 order = -1;
    U8 empty = 0;
    U8 volume = g_audply.volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //bql: hardcode... error_class [0: file issue / 1: not file issue]
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_PLAY_ACTION);

    StopTimer(AUDPLY_DELAY_PLAY_TIMER);
    
    g_audply.wait_next = MMI_FALSE;

    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_time();  /* update time: show MM:SS */
    }
    if (g_audply.duration == 0 || g_audply.seekable == MMI_FALSE)
    {
        if (mdi_audio_get_duration(g_audply.filefullname, &(g_audply.duration)) != MDI_AUDIO_SUCCESS)
        {
            g_audply.duration = 0 ;
        }
        g_audply.seekable = MMI_TRUE;
        mmi_audply_determine_progress_speed();
        if (g_audply.duration != 0)
        {
            /* in case there is no right */
        #ifdef __DRM_SUPPORT__
            result = mmi_audply_drm_valide_right((PU16)g_audply.filefullname);
            if(result == 2)
            {
                g_audply.seekable = MMI_FALSE;
            }
            g_audply.DRM_consumed = MMI_FALSE;
        #endif

            if(g_audply.is_support_pause == MMI_FALSE)
            {
                g_audply.seekable = MMI_FALSE;
            }
            
            
        }
    }
    /*check and refresh cache*/
    mmi_audply_refresh_cache(MMI_TRUE);

    /* Check if file exists or not */
    handle = DRM_open_file((PU16)g_audply.filefullname, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    if (handle >= FS_NO_ERROR)
    {
        *error_class = 1;
        DRM_close_file(handle);
    }
    else
    {
        *error_class = 0;
        mmi_audply_stop_playing();
        if (handle == FS_MEDIA_CHANGED)
        {
            handle = FS_FILE_NOT_FOUND;
        }
        return (S32)handle;
    }

    bg_suspend = mdi_audio_is_background_play_suspended();
    order = mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY);
    empty = mdi_audio_get_background_callback_register_app_num();

    /* This could happen when timer experied after suspend background play or another play or record req by others */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_FOUR_VALS,bg_suspend,empty,order,-1);

    if (bg_suspend || empty==0 || order!=0 || !mdi_audio_is_idle())
    {
        g_audply.need_replay = MMI_TRUE;
        g_audply.state = STATE_IDLE;
        result = MMI_AUDPLY_NOT_ALLOW_PLAY; //bql: audio player internal error result (-1)
    }
    else
    {
        g_audply.state = STATE_IDLE;    /* for preventing from terminated callback; */
        g_audply.need_replay = MMI_FALSE;
 
    #ifdef __MMI_AUDIO_TIME_STRETCH__
        /* Check if audio time stretch support for the file */
        if ((check_result = mmi_audply_speed_check_before_play(g_audply.speed)) != MDI_AUDIO_SUCCESS)
        {
            mdi_audio_stop_all();
            return check_result;
        }

        /* Set audio time stretch speed before play request */
        mmi_audply_speed_set_speed();
    #endif /* __MMI_AUDIO_TIME_STRETCH__ */ 
    
        cache_ptr = mmi_audply_determine_cache_ptr();

        /*regisiter auto update time callback*/
        mdi_audio_regisiter_auto_update_duration_handler(mmi_audply_auto_update_duration_hdlr);

    #ifdef __DRM_SUPPORT__
        if(g_audply.DRM_consumed)
        {
            mdi_audio_drm_disable_consume_count();
        }
    #endif /* __DRM_SUPPORT__ */

        /* Portion play request */
        result = mdi_audio_play_file_portion_with_vol_path(
                   g_audply.filefullname,
                   g_audply.new_play_time,
                   0,
                   DEVICE_AUDIO_PLAY_ONCE,
                   cache_ptr,
                   mmi_audply_play_callback_hdlr,
                   NULL,
		   #if 1// && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
                   (U8)MDI_AUD_VOL_EX_MUTE(volume),
                   #else
/* under construction !*/
                    #endif
                   MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    #ifdef __MMI_AUDIO_TIME_STRETCH__
        /* Reset speed if not play successfully */
        if (result != MDI_AUDIO_SUCCESS)
        {
            mmi_audply_speed_close();
        }
    #endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

        if (result == MDI_AUDIO_SUCCESS)
        {
            g_audply.state = STATE_PLAY;
        }
        else if (result == MDI_AUDIO_BLOCKED)
        {
            g_audply.need_replay = MMI_TRUE;
        }
    }

    return (S32)result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_do_stop_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMI_BOOL clear_bg_handler
 *  MMI_TRUE : will clear background handler if not in audio player
 *  MMI_FALSE: will not clear background handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_do_stop_action(MMI_BOOL clear_bg_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_STOP_ACTION);
    
    g_audply.need_replay = MMI_FALSE;

    g_audply.state = STATE_IDLE;    /* for preventing from set g_audply.need_replay = TRUE; */
    mdi_audio_stop_file();
    mmi_audply_stopped(clear_bg_handler);

    if (
    #ifdef __MMI_AUDPLY_WALK_PLAY__
        g_audply.play_style == AUDPLY_PLAY_STYLE_BY_PLAYLIST &&
    #endif  //__MMI_AUDPLY_WALK_PLAY__
        mmi_audply_playlist_is_empty())
    {
        /*
        mmi_audply_clear_play_seconds();
        g_audply.seekable = MMI_FALSE;
        g_audply.need_to_build_cache = MMI_FALSE;
        g_audply.title[0] = 0;
        g_audply.filefullname[0] = 0;
        */
        mmi_audply_reset_context();
        g_audply.successive_fail_num = 0;

        if (g_audply.in_main_screen)
        {
            mmi_audply_redraw_main_screen();
        }
    }
    /* restore to normal speed when stop play */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_audply_speed_close();
#endif 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_stop_playing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_stop_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_STOP_PLAYING,g_audply.state);
    
    if (!g_mmi_audply_init_done)
    {
        return;
    }
    StopTimer(AUDPLY_DELAY_PLAY_TIMER);

    g_audply.wait_next = MMI_FALSE;

    g_audply.need_replay = MMI_FALSE;

    if (g_audply.state != STATE_IDLE)
    {
        mmi_audply_do_stop_action(MMI_TRUE);    /* stop song */
    }
    else
    {
        /*handle background play*/
        if (mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY)>=0 &&
            g_audply.in_audio_player == MMI_FALSE)
        {
            mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_AUDPLY);
        }
    }

#ifdef __BT_SPK_VOL_CONTROL__
    if(!g_audply.in_main_screen)
    {
        mdi_audio_bt_clear_volume_sync_callback(APP_AUDIOPLAYER);
    }
#endif

    mmi_audply_clear_play_seconds();
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_time();
        mmi_audply_redraw_main_progressbar();
    }

#ifdef __MMI_A2DP_SUPPORT__
    mmi_audply_bt_stop(KAL_FALSE, KAL_FALSE);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_seek_stop_playing
 * DESCRIPTION
 *  do the stop playing actions except redraw mainscreen ones
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_seek_stop_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_SEEK_STOP_PLAYING);

    StopTimer(AUDPLY_DELAY_PLAY_TIMER);

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__     
    mmi_audply_stop_lyric();
#elif defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)     
    mmi_audply_stop_update_lyric();
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    /*this shall be done before state to IDLE, or it will not work*/
    mmi_audply_turn_off_spectrum();
#endif
    /*set before mdi_audio_stop_file to prevent from calling play_callback_hdlr*/
    g_audply.state = STATE_IDLE; 
    
#if  defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) ||defined(__MMI_VUI_LAUNCHER_KEY__)
    if(g_audply.widget_callback != NULL)
    {
        g_audply.widget_callback(g_audply.widget_callback_userdata, MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK, NULL);
    }
#endif
    
    mdi_audio_stop_file();

    /*the setting of flags shall be done after stop file since the callback funcions will set 
      the flag too*/
    g_audply.wait_next = MMI_FALSE;
    g_audply.need_replay = MMI_FALSE;

#ifdef __MMI_A2DP_SUPPORT__
    mmi_audply_bt_stop(KAL_TRUE, KAL_FALSE);
#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_audply_speed_close();
#endif
    /*in case in rewind mode that old_play_time > new_play_time*/
    g_audply.old_play_time = 0;

    /*Update status icon*/
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_AUDPLY);
    StartTimer(AUDPLY_STATUS_ICON_TIMER,100,wgui_status_icon_bar_update);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_encoding_type_change_callback
 * DESCRIPTION
 *  when default encoding type is changed, audio player can update file name
 * PARAMETERS
 *      
 * RETURNS
 *
 *****************************************************************************/
void mmi_audply_encoding_type_change_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;
    UI_character_type filefullname[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type wchar_filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN  + 1];
    UI_character_type filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN  + 1];
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*set to zero so that it will use the new encoding type to update buffer*/
    mmi_audply_playlist_reset_ui_cntx();

    /*try to update current song title*/
    if ((result = mmi_audply_playlist_get_path_for_player(filefullname, mmi_audply_playlist_get_current_index())) != 0)
    {
        if (result == 2)    /* if it is a short filename */
        {
            mmi_audply_extract_filename(wchar_filename, filefullname);
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) filename,
                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN  + 1) * ENCODING_LENGTH,
                (U8*) wchar_filename,
                g_chset_text_encoding);
        }
        else
        {
            mmi_audply_extract_filename(filename, filefullname);
        }
        mmi_audply_split_filename_ext(filename, g_audply.title, ext);
    #if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) ||defined(__MMI_VUI_LAUNCHER_KEY__)
        if(g_audply.widget_callback != NULL)
        {
            g_audply.widget_callback(g_audply.widget_callback_userdata, MMI_WIDGET_PLAYER_MEDIA_CHANGE_CALLBACK, NULL);
        }
    #endif
	#ifdef __MMI_NCENTER_SUPPORT__
       mmi_audply_ncenter_update();
	#endif
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_background_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_background_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BACKGOURND_CALLBACK,g_audply.need_replay,g_mmi_audply_longpressed,g_audply.wait_next,result);

    /*when audio player background hdlr is cleared by other module*/
    if (result == MDI_AUDIO_TERMINATED)
    {
        g_audply.wait_next = MMI_FALSE;
        g_audply.need_replay = MMI_FALSE;
        //bql: consider not to clear play second if bg cb terminated
        //mmi_audply_clear_play_seconds();
    #if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
        if(g_audply.widget_callback != NULL)
        {
            g_audply.widget_callback(g_audply.widget_callback_userdata, MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK, NULL);
        }
    #endif
        return MMI_TRUE;
    }

    if (mdi_audio_is_background_play_suspended())
    {
        return MMI_TRUE;
    }

    /*when under longpressed, shall skip background callback*/
    if (g_audply.need_replay && !g_mmi_audply_longpressed)
    {
        StopTimer(AUDPLY_DELAY_PLAY_TIMER); /* stop previous play request */
        if(g_audply.wait_next)
        {
            mmi_audply_clear_play_seconds();            
        }
        mmi_audply_play();
    }
    else if(g_audply.wait_next)
    {
        mmi_audply_play(); /*it will begin to play when press next key continuous,so deleted this*/
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_play_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_play_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PLAY_CALLBACK,g_audply.state,result);
    
    /* restore to normal speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_audply_speed_close();
#endif 
    if(g_audply.volume_nvram != g_audply.volume)
    {
        WriteValueSlim(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE);
        g_audply.volume_nvram = g_audply.volume;
    }
    /* ignore it */
    if (g_audply.state != STATE_PLAY)
    {
        return;
    }

    /* handle result */

    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
            g_audply.need_replay = MMI_FALSE;
            if (g_audply.in_main_screen == MMI_TRUE)
            {
                g_audply.new_play_time = g_audply.duration;
                mmi_audply_redraw_main_progressbar();
                //single
                if (!mmi_audply_playlist_is_valid()
                    #ifdef __MMI_AUDPLY_WALK_PLAY__
                    && g_audply.play_style == AUDPLY_PLAY_STYLE_BY_PLAYLIST
                    #endif  //__MMI_AUDPLY_WALK_PLAY__
                    )
                {
                    mmi_audply_playlist_init();    
                }
            }
            mmi_audply_play_completed();
            break;
        case MDI_AUDIO_TERMINATED:
            g_audply.need_replay = MMI_TRUE;
            if (g_audply.is_support_pause == MMI_FALSE)
            {
                mmi_audply_clear_play_seconds();
            }
            mdi_audio_stop_file();
            mmi_audply_stopped(MMI_FALSE);
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__            
            if (g_audply.in_main_screen)
            {
                mmi_audply_set_LSK_text(STR_GLOBAL_PLAY);
                mmi_audply_redraw_LSK_up();
            }
        #endif 
            break;
    #ifdef __DRM_SUPPORT__
        case MDI_AUDIO_DRM_TIMEOUT:
            mmi_audply_display_popup(result, NULL, NULL);
            mmi_audply_do_stop_action(MMI_TRUE);
        #if defined(__MMI_A2DP_SUPPORT__)
            //bql: DUMMY CODE?
            //mmi_audply_bt_stop has been performed in mmi_audply_stopped
            mmi_audply_bt_stop(KAL_FALSE, KAL_FALSE); 
        #endif
            break;
    #endif /* __DRM_SUPPORT__ */
        default:
            {
                g_audply.need_replay = MMI_FALSE;
                mmi_audply_stopped(MMI_TRUE);
                mmi_audply_clear_play_seconds();   
                {
                    if ((g_audply.repeat_mode != REPEAT_ONE && mmi_audply_playlist_get_total() > 1)
                        #ifdef __MMI_AUDPLY_WALK_PLAY__
                        || g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER
                        #endif  //__MMI_AUDPLY_WALK_PLAY__
                        )
                    {
                        if (g_audply.in_audio_player == MMI_FALSE)
                        {
                            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_AUDPLY, mmi_audply_background_callback_hdlr, NULL);
                        }
                        mmi_audply_display_popup(result, mmi_audply_play_completed_callback, mmi_audply_play_completed);
                        g_audply.wait_next_with_pop_up = MMI_TRUE;
                    }
                    else
                    {
                        g_audply.old_play_time = 0 ;
                        mmi_audply_display_popup(result, NULL, NULL);
                    }                        
                }
            }
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_build_cache_fail_callback_hdlr
 * DESCRIPTION
 *  when build cache fail, set to non-seekable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_build_cache_fail_callback_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_BUILD_CACHE_FAIL_CALLBACK,g_audply.state);

    g_audply.seekable = MMI_FALSE;
    mmi_audply_redraw_main_progressbar();
    if (g_audply.state == STATE_PLAY)
    {
        mmi_audply_stop_playing();
    }
}

mmi_ret mmi_audply_lcd_sleep_in_handler(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_LCD_SLEEP_IN_HANDLER, event->evt_id, g_audply.in_audio_player, __LINE__);
    if (g_audply.in_audio_player != MMI_TRUE)
    {
        return MMI_RET_OK;
    }

    switch(event->evt_id)
    {
        case EVT_ID_GPIO_LCD_SLEEP_IN:
        {
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
            /*this shall be done before state to IDLE, or it will not work*/
            mmi_audply_turn_off_spectrum();
    #endif
            break;
        }
        case EVT_ID_GPIO_LCD_SLEEP_OUT:
        {
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
            mmi_audply_turn_on_spectrum();
    #endif
            break;
        }
        default:
        break;
    }
    return MMI_RET_OK;
}

#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_handfree_volume_sync_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_audply_handfree_volume_sync_callback(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_HFP_VOL_SYNC,volume,is_mute,g_audply.state,g_audply.in_main_screen);

    ASSERT(volume <= MDI_AUD_VOL_EX_NUM);
    
    if(g_audply.state == STATE_PLAY || g_audply.in_main_screen)
    {        
        g_audply.volume = volume;

        if (g_audply.state != STATE_IDLE)
        {
            #if 1// && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
            mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(g_audply.volume)));
            #else
/* under construction !*/
            #endif   
        }

        if (g_audply.in_main_screen)
        {
#if defined(__MMI_AUDIO_PLAYER_SKIN_SHOW_VOL_CTL__)        
            if (g_audply.volume == MDI_AUD_VOL_EX_NUM - 1)
            {
                mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_TRUE);
            }
            else
            {
                mmi_audply_redraw_main_volumectrl(1, MMI_FALSE, MMI_FALSE);
            }
            
            if (g_audply.volume == 0)
            {
                mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_TRUE);
                #if defined(__MMI_FTE_SUPPORT__)// && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
                mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
                #endif /*#ifdef __MMI_FTE_SUPPORT__ */	
            }
            else
            {
                mmi_audply_redraw_main_volumectrl(0, MMI_FALSE, MMI_FALSE);
                #if defined(__MMI_FTE_SUPPORT__)// && !defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__)
                mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
                #endif /*#ifdef __MMI_FTE_SUPPORT__ */	
            }     

#else
        if (g_audply.volume == 0)
        {
            #if defined(__MMI_FTE_SUPPORT__)
            mmi_audply_redraw_main_volume_speaker(MMI_TRUE);
            #endif /*#ifdef __MMI_FTE_SUPPORT__ */	
        }
        else
        {
            #if defined(__MMI_FTE_SUPPORT__)
            mmi_audply_redraw_main_volume_speaker(MMI_FALSE);
            #endif /*#ifdef __MMI_FTE_SUPPORT__ */	
        }    
#endif
            mmi_audply_redraw_main_volumebar();
        }
        else if (g_audply.state != STATE_PLAY)
        {
            WriteValueSlim(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE);
            g_audply.volume_nvram = g_audply.volume;
        }

        return MMI_TRUE;

    }

    return MMI_FALSE;

}
#endif/*__BT_SPK_VOL_CONTROL__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_auto_update_duration_hdlr
 * DESCRIPTION
 *  handle auto update duration
 * PARAMETERS
 *  duration    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_auto_update_duration_hdlr(U32 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* when MMI changes to next/previous song but haven't played yet(press next/prev key)
      ,update dur ind might update the wrong song */
    if (!g_audply.file_name_identical)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_AUTO_UPDATE_DUR_FAIL);
        return;
    }

    if (g_audply.state != STATE_IDLE && duration != 0)
    {
        g_audply.duration = duration;
        mmi_audply_determine_progress_speed();
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_AUTO_UPDATE_DUR,g_audply.duration);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_play_completed_callback
 * DESCRIPTION
 *  popup callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_play_completed_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
    mmi_audply_play_completed();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_play_completed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_play_completed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_COMPLETED);
    
#ifdef __MMI_A2DP_SUPPORT__
    mmi_audply_bt_stop(KAL_TRUE, KAL_FALSE);
#endif
#if defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
		mmi_audply_unprepare_lyrics();
#endif
    g_audply.wait_next_with_pop_up = MMI_FALSE;
    /* update state */
    g_audply.state = STATE_IDLE;
#if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
    if(g_audply.widget_callback != NULL)
    {
        g_audply.widget_callback(g_audply.widget_callback_userdata, MMI_WIDGET_PLAYER_PLAY_END_CALLBACK, NULL);
        g_audply.widget_callback(g_audply.widget_callback_userdata, MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK, NULL);
    }
#endif
    StopTimer(AUDPLY_COUNT_PLAY_TIMER);

    {
    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_SUBLCD__)
        mmi_audply_calc_spectrum(MMI_FALSE);
    #endif 
    }

    if (
        #ifdef __MMI_AUDPLY_WALK_PLAY__
        g_audply.play_style == AUDPLY_PLAY_STYLE_BY_PLAYLIST &&
        #endif  //__MMI_AUDPLY_WALK_PLAY__
        mmi_audply_playlist_is_empty())
    {
        /*
        mmi_audply_clear_play_seconds();
        g_audply.seekable = MMI_FALSE;
        g_audply.need_to_build_cache = MMI_FALSE;
        g_audply.title[0] = 0;
        g_audply.filefullname[0] = 0;
        */
        mmi_audply_reset_context();
        g_audply.successive_fail_num = 0;;

        if (g_audply.in_main_screen)
        {
            mmi_audply_redraw_main_screen();
        }
    }
    /* check if buttin is pressed down is to avoid repeating on a short file too quick and cause a result to block other commands */
    if (g_audply_main_selected_button_down &&
        (g_audply_main_selected_button == AUDPLY_MAIN_STOP ||
         g_audply_main_selected_button == AUDPLY_MAIN_PREV ||
         g_audply_main_selected_button == AUDPLY_MAIN_NEXT))
    {
        g_mmi_audply_play_completed_after_button_down = MMI_TRUE;
        /*in case in rewind mode that old_play_time > new_play_time*/
        g_audply.old_play_time = 0;
    }
    else
    {

        mmi_audply_clear_play_seconds();
        if (
            #ifdef __MMI_AUDPLY_WALK_PLAY__
            g_audply.play_style == AUDPLY_PLAY_STYLE_BY_PLAYLIST &&
            #endif  //__MMI_AUDPLY_WALK_PLAY__
            mmi_audply_playlist_do_pick() < 0)
        {
            mmi_audply_playlist_do_pick(); /* pick after play list  reset */
            if (mmi_audply_playlist_apply_picked_file())
            {
                g_audply_main_selected_button = AUDPLY_MAIN_STOP;
                g_audply_main_selected_button_down = MMI_FALSE;

            }
				#ifdef __MMI_NCENTER_SUPPORT__
				mmi_audply_ncenter_close();
				#endif
            /*handle background play*/
            if(mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY)>=0 && 
               g_audply.in_audio_player == MMI_FALSE)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_AUDPLY);
            }
        #ifdef __BT_SPK_VOL_CONTROL__
            if(!g_audply.in_main_screen)
            {
                mdi_audio_bt_clear_volume_sync_callback(APP_AUDIOPLAYER);
            }
        #endif            
        }
        else
        {
            #ifdef __MMI_AUDPLY_WALK_PLAY__
            if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER &&
				g_audply.filefullname[0] != 0)
            {
                g_audply.walk.state = AUDPLY_WALK_STATE_NEXT;
            }
            #endif  //__MMI_AUDPLY_WALK_PLAY__
            if (mmi_audply_playlist_apply_picked_file())
            {
                StopTimer(AUDPLY_DELAY_PLAY_TIMER); /* stop previous play request */
                StartTimer(AUDPLY_DELAY_PLAY_TIMER, 700, mmi_audply_delay_play);    /* wait for 0.7 second to request play */
                g_audply.wait_next = MMI_TRUE;
                /*it is not necessary to set need_store to false here, but to make it identical, make every need_restore
                  to false after wait_next is true*/
                g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
            }
            else
            {
                /*handle background play*/
                if(mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY)>=0 &&
                   g_audply.in_audio_player == MMI_FALSE)
                {
                   mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_AUDPLY);
                }

            #ifdef __BT_SPK_VOL_CONTROL__
                if(!g_audply.in_main_screen)
                {
                    mdi_audio_bt_clear_volume_sync_callback(APP_AUDIOPLAYER);
                }
            #endif

            }
        } 
        if (g_audply.in_main_screen)
        {
            mmi_audply_update_main_button_flag();
            mmi_audply_redraw_main_screen();
        }
		/*
		else if (g_audply.in_list_screen)
		{
			asyncdynamic_list_goto_item(mmi_audply_playlist_get_current_index());
		}*/

        mmi_idle_update_service_area();    
    }

    /*Update status icon*/
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_AUDPLY);
    StartTimer(AUDPLY_STATUS_ICON_TIMER, 100, wgui_status_icon_bar_update);

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if (g_audply.in_main_screen)
    {
        mmi_audply_spectrum_display_stop();
    }
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

    /*disable lyric display*/
    {
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        mmi_audply_stop_scroll_lyric_and_clean_screen();
        audply_lyric.is_ready = MMI_FALSE;
        lyric_parse_ok = MMI_FALSE;
        mmi_audply_lyric_check_backlight(MMI_FALSE);
    #endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
     }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_stopped
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMI_BOOL clear_bg_handler
 *  MMI_TRUE : will clear background handler if not in audio player
 *  MMI_FALSE: will not clear background handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_stopped(MMI_BOOL clear_bg_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_STOPPED,clear_bg_handler);
    
#ifdef __MMI_A2DP_SUPPORT__
    mmi_audply_bt_stop(KAL_TRUE, KAL_FALSE);
#endif

    /* update state */
    g_audply.state = STATE_IDLE;
#if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
    if(g_audply.widget_callback != NULL)
    {
        g_audply.widget_callback(g_audply.widget_callback_userdata, MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK, NULL);
    }
#endif
    /*handle background play*/
    if(clear_bg_handler && 
       mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY) >= 0 && 
       g_audply.in_audio_player == MMI_FALSE)
    {
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_AUDPLY);
    }

#ifdef __BT_SPK_VOL_CONTROL__
    if(!g_audply.in_main_screen)
    {
        mdi_audio_bt_clear_volume_sync_callback(APP_AUDIOPLAYER);
    }
#endif

    if (!mmi_audply_playlist_is_empty())
    {
        //bql: why update selected button as play while audply_stop?
        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
    }
    else
    {
        g_audply_main_selected_button = AUDPLY_MAIN_DISABLED;
    }
    #ifdef __MMI_AUDPLY_WALK_PLAY__
    if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
    {
        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
    }
    #endif  //__MMI_AUDPLY_WALK_PLAY__
    g_audply_main_selected_button_down = MMI_FALSE;

    StopTimer(AUDPLY_COUNT_PLAY_TIMER);   
    {
    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) /*&& defined(__MMI_SUBLCD__)*/
        mmi_audply_calc_spectrum(MMI_FALSE);
    #endif 

    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        mmi_audply_stop_lyric();
    #elif defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)     
        mmi_audply_stop_update_lyric();
    #endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
    }
  

    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        mmi_audply_spectrum_display_stop();
    #endif 
    }

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__  
    mmi_audply_set_LSK_text(STR_GLOBAL_PLAY);
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_LSK_up();
    }
#endif

    mmi_idle_update_service_area();   
	#ifdef __MMI_NCENTER_SUPPORT__
	mmi_audply_ncenter_close();
	#endif

    /*Update status icon*/
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_AUDPLY);
    StartTimer(AUDPLY_STATUS_ICON_TIMER,100,wgui_status_icon_bar_update);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_played
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_played(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PLAYED);
   
    {
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        /* re-inialize the lyric. */
        lyric_parse_ok = mmi_audply_init_lyric();

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PARSE_LYRICS,lyric_parse_ok);

        /* re-direct the target_layer, cause init_lyric will clean it to 0 ; */
    #ifdef __GDI_MEMORY_PROFILE_2__
        audply_lyric_print.target_layer = audply_osd_layer;
    #endif /*__GDI_MEMORY_PROFILE_2__*/
        lyric_reEntry = MMI_TRUE;
	#elif defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
	if (g_audply.lyrics_display &&
	        g_audply.state != STATE_IDLE &&
	        mmi_audply_is_lyrics_valid() && g_audply.in_main_screen)
	    {
			StartTimer(AUDPLY_DISPLAY_LYRICS_TIMER,MMI_AUDPLY_UI_UPDATE_PLAY_TIME,mmi_audply_update_lyrics_on_time);
	    }
    #endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
     }

    /* update state */
    g_audply.state = STATE_PLAY;
#if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
    if(g_audply.widget_callback != NULL)
    {
        g_audply.widget_callback(g_audply.widget_callback_userdata, MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK, NULL);
    }
    if(g_audply.in_audio_player == MMI_FALSE)
    {
        mdi_audio_clear_other_background_handler(MDI_BACKGROUND_APP_AUDPLY);
    }
#endif

    { 
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__    
        if (g_audply.lyrics_display &&
            g_audply.in_main_screen &&
            mmi_audply_is_lyrics_valid())
        {
              mmi_audply_lyric_on_time();
        }
    #elif defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
        if (g_audply.lyrics_display &&
            g_audply.in_main_screen &&
            mmi_audply_is_lyrics_valid())
        {
             mmi_audply_update_lyrics_on_time();
        }
    #endif /*__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__*/
    }
    StartTimer(AUDPLY_COUNT_PLAY_TIMER, 500, mmi_audply_timer);
  
    {
    #if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_SUBLCD__)
        /* this turn on spetrcm action is especially for subLCD, in case it is not in main screen so did not turn on for sub*/
        if (!srv_backlight_is_lcd_sleep())
        {
            if (g_audply.spectrum_style != 0 && mmi_audply_is_spectrum_valid() && !g_audply_spectrum_blocked)
            {
                mmi_audply_calc_spectrum(MMI_TRUE);
            }
        }
    #endif /* defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_SUBLCD__) */ 

    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
       mmi_audply_lyric_check_backlight(MMI_TRUE);
    #endif 
   }
 
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        if (!srv_backlight_is_lcd_sleep())
        {
            if (g_audply.spectrum_style != 0 &&
                mmi_audply_is_spectrum_valid() &&
                !g_audply_spectrum_blocked)
            {
                mmi_audply_spectrum_display_start();
            }
        }
    #endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
    }
#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
		mmi_audply_ncenter_open(); 
#endif

    mmi_idle_update_service_area();    

    /*Update status icon*/
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_AUDPLY);
    StartTimer(AUDPLY_STATUS_ICON_TIMER,100,wgui_status_icon_bar_update);

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(APP_AUDIOPLAYER,MDI_AUD_VOL_LEVEL_EXTEND_MUTE,mmi_audply_handfree_volume_sync_callback);
#endif

    g_audply.old_play_time = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_play_activated
 * DESCRIPTION
 *  indicate whether will audio player (or single song) play or attempt to play song soon
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_is_play_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(mmi_audply_is_single_play_activated() || g_audply.state == STATE_PLAY || g_audply.wait_next);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_playing
 * DESCRIPTION
 *  indicate whether will audio player is playing a song
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_is_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 order = 0 ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    order = mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_AUDPLY) ;
    /*order equals 0 means currently audio player is really wait next and playnig
      because other backbround application might take over background play while
      audio player is wait next*/
    return (MMI_BOOL)(g_mmi_audply_init_done && (g_audply.state == STATE_PLAY || (g_audply.wait_next && order == 0)));
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_A2DP_spectrum_need_block
 * DESCRIPTION
 *  indicate whether A2DP+spectrum is required to be blocked or not
 * PARAMETERS
 *  void
 * RETURNS
 * void
 *****************************************************************************/


void mmi_audply_A2DP_spectrum_need_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__

#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__)
#ifdef __A2DP_BLOCK_SPECTRUM__
        g_audply_A2DP_spectrum_need_blocked = MMI_TRUE;
#else
          g_audply_A2DP_spectrum_need_blocked = MMI_FALSE;
#endif
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/

#endif/*__MTK_TARGET__*/
   
}


#endif /* __MMI_AUDIO_PLAYER__ */ 

