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
*  MediaPlayerMsgHandler.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media player message handling
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"

//#include "MMI_include.h"

#ifdef __MMI_MEDIA_PLAYER__

#include "MMI_features_mediaplayer.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_video.h"
//#include "mdi_tv.h"

/*DRM related*/
#include "DRM_gprot.h"
#ifdef __DRM_SUPPORT__
//#include "RightsMgrGProt.h"
#endif

#include "FileMgrResDef.h"
//#include "ProfilesSrvGProt.h"
#include "CommonScreens.h"  /*display pop up*/
//#include "GpioSrvGprot.h" /*backlight control*/

#ifdef __MMI_A2DP_SUPPORT__
#include "av_bt.h"
//#include "BTMMIScrGprots.h" /*check bt power on*/
//#include "SimDetectionGprot.h" /*check flight mode*/
#endif

//#ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__
#include "ImageViewerGprot.h"
//#endif
//#include "GpioSrvGprot.h"
#include "MediaPlayerProt.h"
//#include "MediaPlayerResDef.h"

/*check in call*/
//#include "UcmSrvGprot.h"
#include "FileMgrSrvGProt.h"

#include "MMIDataType.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "MediaPlayerEnumDef.h"
#include "kal_general_types.h"
#include "device.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "kal_public_api.h"
#include "MediaPlayerPlayList.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "MediaAppWidgetDef.h"
#include "fs_type.h"
#include "drm_def.h"
#include "fs_errcode.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_medply_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "SoundEffect.h"
#include "fs_func.h"
#include "MediaPlayerGProt.h"
#include "GpioSrvGprot.h"
#include "string.h"
#include "gdi_include.h"
#include "common_nvram_editor_data_item.h"
#include "stdio.h"
#include "FileMgrType.h"
#include "gui.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "mdi_include.h"

#ifdef __MMI_MEDIA_PLAYER_STREAM__
#include "CbmSrvGprot.h"
#include "DtcntSrvGprot.h"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_set_mute_callback
 * DESCRIPTION
 *  when it is not currently playing, turn on mute flag.
 *  currently used by user profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_set_mute_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_SET_MUTE_CALLBACK, g_medply.state);

    switch(g_medply.state)
    {
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
    #endif

    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
    #endif

    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
    #endif
        {
            mdi_audio_set_mute(VOL_TYPE_MEDIA,MMI_TRUE);
            break;
        }

        default:
        {
            break;
        }
    }

    g_medply.mute = MMI_TRUE;
    WriteValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);
}


#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_handfree_volume_sync_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_medply_handfree_volume_sync_callback(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MMI_BOOL apply_vol = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_HFP_VOL_CALLBACK, g_medply.state, g_medply.in_main_screen, g_medply.volume, volume, g_medply.mute, MMI_FALSE);

    ASSERT(volume <= MDI_AUD_VOL_EX_MUTE_MAX);

    switch(g_medply.state)
    {
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
    #endif

    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
    #endif

    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
    #endif
        {
            apply_vol = MMI_TRUE;
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
    /*this is for case that video state exit main screen and expect to keep playing,it will 
      start to gui timer to go on playing, if handfree vol sync comes before timer times out,
      we shall still consider it is playing state. ex: hfp connected pop up make video go to
      background*/
        case MEDPLY_STATE_PURE_AUDIO_READY:
        {
            if(g_medply.continue_to_play)
            {
                apply_vol = MMI_TRUE;
            }
            break;
        }    
    #endif

        default:
        {
            if(g_medply.in_main_screen)
            {
                apply_vol = MMI_TRUE;
            }
            break;
        }
    }

    if(apply_vol)
    {        
        g_medply.volume = volume;

        if (g_medply.state != MEDPLY_STATE_IDLE)
        {
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(g_medply.volume)));
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        if(!g_medply.mute &&  (MDI_AUD_VOL_EX_MUTE_MIN == g_medply.volume))
        {
            g_medply.mute = MMI_TRUE;
            WriteValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);
        }
        else if(g_medply.mute && (MDI_AUD_VOL_EX_MUTE_MIN != g_medply.volume))
        {
            g_medply.mute = MMI_FALSE;
            WriteValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);            
        }

        if(mmi_medply_main_screen_show_volme_tuning())
        {
            mmi_medply_clear_key_down();
        #ifdef __MMI_TOUCH_SCREEN__
            mmi_medply_clear_pen_down();
        #endif

            mmi_medply_register_key_hdlrs(MMI_MEDPLY_SCREEN_VOLUME);        
            mmi_medply_main_screen_update_mute();    
            mmi_medply_main_screen_update_vol();
        }
        else if(g_medply.widget_callback != NULL)
        {
            g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDTET_PLAYER_VOL_CHANGE_CALLBACK,NULL);
        }

    #else
        if(g_medply.mute)
        {
            g_medply.mute = MMI_FALSE;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,MMI_MEDPLY_RGN_STATUS_UP);
            WriteValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);
        }

        if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_VOL_DEC))
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_DEC,
                MMI_MEDPLY_RGN_STATUS_DISABLE);
        }
        else
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_DEC,
                MMI_MEDPLY_RGN_STATUS_UP);
        }

        if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_VOL_INC))
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_INC,
                MMI_MEDPLY_RGN_STATUS_DISABLE);
        }
        else
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_INC,
                MMI_MEDPLY_RGN_STATUS_UP);
        }

        mmi_medply_main_screen_draw_volume(g_medply.volume);
    #endif /*__MMI_MEDIA_PLAYER_FTE__*/

        if(!g_medply.fullscreen)
        {
            mmi_medply_main_screen_blt();
        }
        WriteValue(NVRAM_MEDIA_PLAYER_VOLUME, &g_medply.volume, DS_BYTE, &error);

        return MMI_TRUE;

    }

    return MMI_FALSE;

}
#endif/*__BT_SPK_VOL_CONTROL__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_background_prepare
 * DESCRIPTION
 *  do the prepare action for background actively play request ex: widget,avrcp
 *  current case:
 *  when streaming is background inited, we shall stop other audil file
 *  since streaming will not stop audio actively like audio/pure audio.
 *  hence other background task might not know it has been interrupted and stopped.
 *  ex: java
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_background_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_BG_PREPARE,g_medply.state,g_medply.media_type, g_medply.in_main_screen);

    if(g_medply.in_main_screen)
    {
        return;
    }

    switch(g_medply.state)
    {
        case MEDPLY_STATE_IDLE:
        {
            switch(g_medply.media_type)
            {
                case MEDPLY_TYPE_AUDIO:
                case MEDPLY_TYPE_VIDEO:
                case MEDPLY_TYPE_STREAM:
                {
                   mdi_audio_stop_all();
                   break;
                }
                default:
                {
                    break;
                }
            }
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_READY:
        case MEDPLY_STATE_AUDIO_INTERRUPTED:
    #endif
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_PURE_AUDIO_READY:
        case MEDPLY_STATE_VIDEO_INTERRUPTED:
    #endif
    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_INTERRUPTED:
        case MEDPLY_STATE_STREAM_IDLE:
    #endif
        {
            mdi_audio_stop_all();
            break;
        }

        default:
        {
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_background_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_background_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_BACKGROUND_CALLBACK, g_medply.state, result);

    /*when media player background hdlr is cleared by other module*/
    if (result == MDI_AUDIO_TERMINATED)
    {
        mmi_medply_set_continue_flag(MMI_FALSE);

        mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);

        return MMI_TRUE;
    }

    switch(g_medply.state)
    {
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_INTERRUPTED:
        {
            /*let continue flag decide whether play or not*/
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
            break;
        }

        case MEDPLY_STATE_AUDIO_INTERRUPTED_WAIT_ACTIVATE:
        {
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_WAIT_ACTIVATE);
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_INTERRUPTED:
        {
            if(!g_medply.in_main_screen)
            {
                mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);
            }
            else
            {
                mmi_medply_video_open();
            }
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_INTERRUPTED:
        {
            MMI_BOOL result;

            result = mmi_medply_stream_init();
            if(result && g_medply.continue_to_play)
            {
                mmi_medply_set_continue_flag(MMI_FALSE);
                mmi_medply_stream_connect();
            }
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

        case MEDPLY_STATE_WAIT_NEXT_SUSPNEDED:
        {
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_kuro_delay_complete
 * DESCRIPTION
 *  delay complete popup since compelte
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_completed_delay_list_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_medply_plst_display_popup(g_medply.apply_result,NULL);

    g_medply.apply_result = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_play_completed
 * DESCRIPTION
 *  in charge of pick up next song and play it if play list return a song to play
 *
 * PARAMETERS
 *  with_pop_up [IN]    indicate whether there is pop up for play complete or not
 *  continue_play [IN]  indicate if shall set continue play on when pick success
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_play_completed(MMI_BOOL with_pop_up, MMI_BOOL continue_play)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  repeat_mode = MMI_MEDPLY_REPEAT_OFF;
    S32 apply_result = 0 ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_PLAY_COMPLETED, with_pop_up, continue_play, MMI_FALSE);

#ifdef __MMI_A2DP_SUPPORT__
    mmi_medply_bt_stop(MMI_FALSE);
#endif

    if(mmi_medply_plst_do_pick() >=0 )
    {
        apply_result = mmi_medply_plst_apply_picked_file();

        if(apply_result<0)
        {
            mmi_medply_stop_playing();
            g_medply.apply_result = apply_result;
            if(!with_pop_up)
            {
                StartTimer(MEDPLY_DELAY_PLST_POPUP_TIMER, 50, mmi_medply_completed_delay_list_popup);
            }
            return;
        }

        if(with_pop_up)
        {
            g_medply.wait_next_with_pop_up = MMI_TRUE;
        }
        mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_REPEAT,&repeat_mode);

        if(repeat_mode == MMI_MEDPLY_REPEAT_ONE && with_pop_up == MMI_TRUE)
        {
            continue_play = MMI_FALSE;
        }
            
        if(!continue_play && g_medply.fullscreen)
        {
            mmi_medply_clear_play_seconds();
            mmi_medply_main_screen_set_full_screen(MMI_FALSE);
            if(g_medply.media_type != MEDPLY_TYPE_AUDIO)
            {
                mmi_medply_main_screen_clear_video_layer();
            }

            g_medply.fullscreen = MMI_FALSE;

            /*register key hdlr*/
            mmi_medply_register_key_hdlrs(MMI_MEDPLY_SCREEN_NORMAL);
        }

        mmi_medply_set_continue_flag(continue_play);
        mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);

    }
    else
    {
        if(g_medply.widget_callback != NULL)
        {
            g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDGET_PLAYER_LIST_END_CALLBACK,NULL);
        }
        apply_result = mmi_medply_plst_apply_picked_file();
        if(apply_result<0)
        {
            mmi_medply_stop_playing();
            g_medply.apply_result = apply_result;
            if(!with_pop_up)
            {
                StartTimer(MEDPLY_DELAY_PLST_POPUP_TIMER, 50, mmi_medply_completed_delay_list_popup);
            }
            return;
        }

        if(!g_medply.in_media_player)
        {
            /*since not going to play next song, clear backgrond hdlr here*/
            mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
        }
        
        if(g_medply.fullscreen)
        {
            mmi_medply_clear_play_seconds();
            mmi_medply_main_screen_set_full_screen(MMI_FALSE);
            if(g_medply.media_type != MEDPLY_TYPE_AUDIO)
            {
                mmi_medply_main_screen_clear_video_layer();
            }

            g_medply.fullscreen = MMI_FALSE;

            /*register key hdlr*/
            mmi_medply_register_key_hdlrs(MMI_MEDPLY_SCREEN_NORMAL);
        }

        mmi_medply_set_continue_flag(MMI_FALSE);
        mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);

    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_play_from_play_list
 * DESCRIPTION
 *  for play list interruptedly play file
 *
 *  1. stop current playing if necessary.
 *  2. set to idle state and continue flag set to on
 *  3. GoBackToHistory to main screen
 *  4. entry screen with state idle and continue flag on will
 *     automatically play the picked some
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_play_from_play_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 apply_result = 0 ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_PLAY_FROM_PLAY_LIST, g_medply.state);

    switch(g_medply.state)
    {
        case MEDPLY_STATE_WAIT_NEXT:
        {
            mmi_medply_stop_wait_next_timer();
            break;
        }
    
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_AUDIO_PLAY:
        {
            mmi_medply_audio_stop();
            break;
        }

        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__            
            mmi_medply_bt_stop(MMI_FALSE);
        #endif 
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:            
        {
            mmi_medply_set_self_stop_flag(MMI_TRUE);
            
            /*stop file*/
            mdi_audio_stop_file();
        
            mmi_medply_set_self_stop_flag(MMI_FALSE);
        
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            /* restore to normal speed when stop play */
        #ifdef __MMI_AUDIO_TIME_STRETCH__
                mmi_medply_settings_close_speed();
        #endif 
            break;
        }

        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__            
            mmi_medply_bt_stop(MMI_FALSE);
        #endif       
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_INITED:
        {
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

            break;
        }

        case MEDPLY_STATE_STREAM_CONNECTING:
        case MEDPLY_STATE_STREAM_CONNECTED:            
        {
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

            break;
        }

        case MEDPLY_STATE_STREAM_BUFFERING:
        {
            StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
            mdi_video_stream_stop_buffering();
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            break;
        }

        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:            
        {
            mdi_video_stream_stop();
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            break;
        }

        case MEDPLY_STATE_STREAM_BT_CONNECTING:
        {
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

        default:
        {
            break;
        }
    }

    apply_result = mmi_medply_plst_apply_picked_file();

    mmi_medply_util_fill_idle_display_str();

#if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
    g_medply.DRM_consumed = MMI_FALSE;
#endif

#ifdef __MMI_A2DP_SUPPORT__
#ifdef __MMI_MEDIA_PLAYER_VIDEO__
    g_medply.bt_connect_fail = MMI_FALSE;
#endif /*__MMI_MEDIA_PLAYER_VIDEO__*/
    g_medply.inquiry_paused = MMI_FALSE;
#endif /*__MMI_A2DP_SUPPORT__*/

    mmi_medply_clear_play_seconds();

    /*set to idle state*/
    g_medply.state = MEDPLY_STATE_IDLE;

    if(apply_result<0)
    { 
        mmi_medply_set_continue_flag(MMI_FALSE);
        mmi_medply_entry_main();
        mmi_medply_plst_display_popup(apply_result,NULL);
        return;
    }

    /*continue flag set to on*/
    mmi_medply_set_continue_flag(MMI_TRUE);

    switch(g_medply.media_type)
    {
        case MEDPLY_TYPE_AUDIO:
        {
            g_medply.state = MEDPLY_STATE_AUDIO_READY;
            break;
        }

        case MEDPLY_TYPE_VIDEO:
        {
            g_medply.state = MEDPLY_STATE_PURE_AUDIO_READY;
            break;
        }

        case MEDPLY_TYPE_STREAM:
        {
            g_medply.state = MEDPLY_STATE_STREAM_IDLE;
            break;
        }

        default:
        {
            break;
        }
    }

    /*go back to main screen*/
    mmi_medply_entry_main();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stop_playing
 * DESCRIPTION
 *  to stop playing and go back to idle state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_stop_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STOP_PLAYING, g_medply.state);

    switch(g_medply.state)
    {
        case MEDPLY_STATE_IDLE:
        {
            return;
        }

        case MEDPLY_STATE_WAIT_NEXT_SUSPNEDED:
        case MEDPLY_STATE_WAIT_NEXT:
        {
            mmi_medply_stop_wait_next_timer();
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);            
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_READY:
        {
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
        case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
        {
            if(g_medply.need_to_build_cache)
            {
                mdi_audio_stop_build_cache();
            }

        #ifdef __MMI_TOUCH_SCREEN__            
            if(g_medply.pen_on_object != MMI_MEDPLY_RGN_ID_NULL)
            {
                /*since we are not able to know pos.x, we use key function 
                  instead but this is not a proper usage though*/
                mmi_medply_main_screen_duration_seek_done();
            }
            else
        #endif
                mmi_medply_main_screen_duration_seek_done();

            mmi_medply_set_continue_flag(MMI_FALSE);       
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:            
        {
            mmi_medply_audio_stop();
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_AUDIO_WAIT_ACTIVATE:
        {
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY_WAIT_ACTIVATE:
        {
            mmi_medply_audio_stop();
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_AUDIO_BT_CONNECTING_WAIT_ACTIVATE:
        {
        #ifdef __MMI_A2DP_SUPPORT__            
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING_WAIT_ACTIVATE:
        {
        #ifdef __MMI_A2DP_SUPPORT__            
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mmi_medply_audio_stop();
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__            
            mmi_medply_bt_stop(MMI_FALSE);
        #endif        
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }
        
        case MEDPLY_STATE_AUDIO_INTERRUPTED:
        case MEDPLY_STATE_AUDIO_INTERRUPTED_WAIT_ACTIVATE:
        {
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_OPENING:
        {
            /*close video*/
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }
        case MEDPLY_STATE_VIDEO_READY:            
        {
            /*close video*/
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
        {
        #ifdef __MMI_TOUCH_SCREEN__            
            if(g_medply.pen_on_object != MMI_MEDPLY_RGN_ID_NULL)
            {
                mmi_medply_main_screen_duration_seek_done();
            }
            else
        #endif
                mmi_medply_main_screen_duration_seek_done();

            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;            
        }

        case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
        case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:            
        {
        #ifdef __MMI_TOUCH_SCREEN__            
            if(g_medply.pen_on_object != MMI_MEDPLY_RGN_ID_NULL)
            {
                mmi_medply_main_screen_duration_seek_done();
            }
            else
        #endif
                mmi_medply_main_screen_duration_seek_done();

            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
        case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY:
        {
            mdi_video_ply_stop();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
        
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_VIDEO_IDLE:
        case MEDPLY_STATE_PURE_AUDIO_READY:
        {
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }
            
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
        {
            mmi_medply_set_self_stop_flag(MMI_TRUE);
            
            /*stop file*/
            mdi_audio_stop_file();
        
            mmi_medply_set_self_stop_flag(MMI_FALSE);
        
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            /* audio is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }

            /* restore to normal speed when stop play */
            #ifdef __MMI_AUDIO_TIME_STRETCH__
                mmi_medply_settings_close_speed();
            #endif 

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_VIDEO_BT_CONNECTING:
        {
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
        #ifdef __MMI_A2DP_SUPPORT__            
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__            
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__            
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_VIDEO_INTERRUPTED:
        {
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_INITED:
        {
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_STREAM_CONNECTING:
        case MEDPLY_STATE_STREAM_CONNECTED:            
        {
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_STREAM_BUFFERING:
        {
            StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
            mdi_video_stream_stop_buffering();
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_STREAM_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:            
        {
            mdi_video_stream_stop();
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback(); 

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
        {
        #ifdef __MMI_TOUCH_SCREEN__            
            if(g_medply.pen_on_object != MMI_MEDPLY_RGN_ID_NULL)
            {
                mmi_medply_main_screen_duration_seek_done();
            }
            else
        #endif
                mmi_medply_main_screen_duration_seek_done();

            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_STREAM_BT_CONNECTING:
        {
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);            
            break;
        }

        case MEDPLY_STATE_STREAM_IDLE:
        case MEDPLY_STATE_STREAM_INTERRUPTED:
        {
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);            
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

        default:
        {
            break;
        }

    }

    if(!g_medply.in_media_player)
    {
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
    }

}


#ifdef __MMI_MEDIA_PLAYER_AUDIO__


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_determine_cache_ptr
 * DESCRIPTION
 *  return cache pointer for L1 build cache to use
 * PARAMETERS
 *  void
 * RETURNS
 *  cache_ptr
 *****************************************************************************/
static U8* mmi_medply_determine_cache_ptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_medply.need_to_build_cache)
    {
        return g_medply_audio_cache;
    }
    else
    {
        return NULL;
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_audio_interrupted
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_audio_interrupted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_AUD_INTERRUPTED, g_medply.state);

    switch(g_medply.state)
    {
        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        {
            mmi_medply_set_continue_flag(MMI_TRUE);
            if(!g_medply.is_audio_seekable)
            {
                mmi_medply_clear_play_seconds();
            }
            break;
        }

        default:
        {
            break;
        }
    }

#ifdef __MMI_A2DP_SUPPORT__
    mmi_medply_bt_stop(MMI_FALSE);
#endif

    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_INTERRUPTED);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_audio_auto_update_duration_hdlr
 * DESCRIPTION
 *  handle auto update duration
 * PARAMETERS
 *  duration    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_audio_auto_update_duration_hdlr(U32 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_AUTO_UPDATE_DUR, duration, g_medply.state, MMI_FALSE);

    if(duration == 0 || g_medply.current_time > duration)
    {
        return;
    }

    if(g_medply.state == MEDPLY_STATE_AUDIO_PLAY || g_medply.state == MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING)
    {
        g_medply.duration = duration;

        mmi_medply_main_screen_draw_duration();
        mmi_medply_main_screen_blt();        
        g_medply.progress_speed = mmi_medply_determine_progress_speed(duration);
        if(g_medply.duration == 0)
        {
            g_medply.seekable = MMI_FALSE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_play_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_audio_play_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_PLAY_CALLBACK, g_medply.state, result, MMI_FALSE);
    
    /* restore to normal speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_medply_settings_close_speed();
#endif 

#if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
    mmi_settings_apply_track_effect(MMI_SETTINGS_TRACK_EFFECTS_NONE,0);
#endif

    switch(g_medply.state)
    {
        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_AUDIO_PLAY_WAIT_ACTIVATE:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING_WAIT_ACTIVATE:
        {
            break;
        }
        default:
        {
            return;
        }
    }

    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
        {
            g_medply.current_time= g_medply.duration;

            if(!g_medply.fullscreen)
            {
                mmi_medply_main_screen_draw_duration();
                mmi_medply_main_screen_blt();
            }

            if(g_medply.widget_callback != NULL)
            {
                g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDGET_PLAYER_PLAY_END_CALLBACK,NULL);
            }

            mmi_medply_play_completed(MMI_FALSE,MMI_TRUE);   
            break;
        }

        case MDI_AUDIO_TERMINATED:
        {
            if(g_medply.self_stop)
            {
                return;
            }
            mdi_audio_stop_file();
            mmi_medply_audio_interrupted();
            break;
        }

    #ifdef __DRM_SUPPORT__
        case MDI_AUDIO_DRM_TIMEOUT:
        {
            mmi_medply_set_self_stop_flag(MMI_TRUE);

            mdi_audio_stop_file();

            mmi_medply_set_self_stop_flag(MMI_FALSE);

            mmi_medply_display_popup(result,MMI_TRUE);
            mmi_medply_play_completed(MMI_TRUE,MMI_TRUE); 
            break;
        }
    #endif /* __DRM_SUPPORT__ */

        default:
        {
            mmi_medply_display_popup(result,MMI_TRUE);
            mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_build_cache_fail_callback_hdlr
 * DESCRIPTION
 *  when build cache fail, set to non seekable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_build_cache_fail_callback_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_BUILD_CACHE_FAIL, g_medply.state, MMI_FALSE);


    g_medply.seekable = MMI_FALSE ;
    g_medply.build_cache_failed = MMI_TRUE;

    /*there is a case that pen up or key up is faster than build cache fail ind, so state might not always be one of these two states*/
    if(g_medply.state == MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING || g_medply.state == MEDPLY_STATE_AUDIO_PLAY_PROGRESSING )
    {
        mdi_audio_stop_build_cache();

        mmi_medply_main_screen_duration_seek_done();
        mmi_medply_set_continue_flag(MMI_FALSE);
        mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
    }
    
    mmi_medply_set_pop_up_flag();

    mmi_popup_display_simple((WCHAR*)GetString(STR_ID_MEDPLY_ERR_BUILD_CACHE_FAIL), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    mmi_frm_ui_force_update_now();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_build_cache_update_dur_hdlr
 * DESCRIPTION
 *  when build cache fail, set to non seekable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_build_cache_update_dur_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 duration;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_medply.state != MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING && g_medply.state != MEDPLY_STATE_AUDIO_PLAY_PROGRESSING)
    {
        return;
    }

    if (g_medply.need_to_build_cache)
    {
        if(mdi_audio_build_cache_get_total_duration(&duration))
        {
            if(g_medply.duration != duration)
            {
                g_medply.duration = (U64)duration;
                g_medply.progress_speed = mmi_medply_determine_progress_speed(g_medply.duration);
                if(g_medply.duration == 0)
                {
                    g_medply.seekable = MMI_FALSE;
                }
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_TRC_MEDPLY_CTL_UPDATE_DUR_BY_CACHE,duration,MMI_FALSE);
            }
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_audio_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_audio_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_AUD_PAUSE);

    if(!g_medply.is_audio_seekable)
    {
        mmi_popup_display_simple((WCHAR*)GetString(STR_ID_MEDPLY_ERR_ADIF_NOT_SUPPORT_PAUSE), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        mmi_frm_ui_force_update_now();
        return;
    }

    /*set to latest time*/
    mdi_audio_get_progress_time(&current_time);

    if(current_time > g_medply.duration)
    {
        g_medply.duration = current_time;
    }

    /*this means alrady played to the end, so do not reset time back to 0*/
    if( current_time == 0 && g_medply.current_time != 0) 
    {
        g_medply.current_time = g_medply.duration;
    }
    else
    {
        g_medply.current_time = (U64)current_time ;
    }

    mmi_medply_set_self_stop_flag(MMI_TRUE);

    /*stop file*/
    mdi_audio_stop_file();

    mmi_medply_set_self_stop_flag(MMI_FALSE);
#ifdef __MMI_A2DP_SUPPORT__
    mmi_medply_bt_stop(MMI_FALSE);
#endif

    if(!g_medply.in_media_player)
    {
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
    }

    mmi_medply_set_continue_flag(MMI_FALSE);

    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);


#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_medply_settings_close_speed();
#endif

#if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
    mmi_settings_apply_track_effect(MMI_SETTINGS_TRACK_EFFECTS_NONE,0);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_audio_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_audio_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_AUD_STOP,1);

    mmi_medply_set_self_stop_flag(MMI_TRUE);

    /*stop file*/
    mdi_audio_stop_file();

    mmi_medply_set_self_stop_flag(MMI_FALSE);

#ifdef __MMI_A2DP_SUPPORT__
    mmi_medply_bt_stop(MMI_FALSE);
#endif

#if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
    g_medply.DRM_consumed = MMI_FALSE;
#endif

    /* audio is stopped, clear background hdlr here*/
    if(!g_medply.in_media_player)
    {
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
    }

    mmi_medply_set_continue_flag(MMI_FALSE);
    mmi_medply_clear_play_seconds();
    
    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
 
    /* restore to normal speed when stop play */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_medply_settings_close_speed();
#endif 

#if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
    mmi_settings_apply_track_effect(MMI_SETTINGS_TRACK_EFFECTS_NONE,0);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_audio_stop_for_not_seekable_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_audio_stop_for_not_seekable_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_AUD_STOP,2);

    mmi_medply_set_self_stop_flag(MMI_TRUE);

    /*stop file*/
    mdi_audio_stop_file();

    mmi_medply_set_self_stop_flag(MMI_FALSE);

#ifdef __MMI_A2DP_SUPPORT__
    mmi_medply_bt_stop(MMI_FALSE);
#endif

    /* audio is stopped, clear background hdlr here*/
    if(!g_medply.in_media_player)
    {
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
    }

    mmi_medply_set_continue_flag(MMI_FALSE);
    mmi_medply_clear_play_seconds();
    
    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
 
    /* restore to normal speed when stop play */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_medply_settings_close_speed();
#endif 

#if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
    mmi_settings_apply_track_effect(MMI_SETTINGS_TRACK_EFFECTS_NONE,0);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_audio_seek_stop
 * DESCRIPTION
 *  stop action for seeking, so do not call stopped or entered ready state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_audio_seek_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_AUD_SEEK_STOP);

    mmi_medply_set_self_stop_flag(MMI_TRUE);

    mdi_audio_stop_file();

    mmi_medply_set_self_stop_flag(MMI_FALSE);


#ifdef __MMI_A2DP_SUPPORT__
    mmi_medply_bt_stop(MMI_FALSE);
#endif

    mmi_medply_set_continue_flag(MMI_FALSE);

    /* restore to normal speed when stop play */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_medply_settings_close_speed();
#endif

#if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
    mmi_settings_apply_track_effect(MMI_SETTINGS_TRACK_EFFECTS_NONE,0);
#endif

    /*in case in rewind mode that old_play_time > current_time*/
    g_medply.old_play_time = 0 ;


}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_audio_do_play_action_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMI_BOOL    [OUT]    returning if error belongs to file system issue
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_audio_do_play_action_ext(MMI_BOOL *file_issue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    U8* cache_ptr = NULL ;
    FS_HANDLE handle;
    U8 volume = g_medply.volume;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_medply.duration == 0)
    {
        if (mdi_audio_get_duration(g_medply.filefullpath, (U32*)&(g_medply.duration)) != MDI_AUDIO_SUCCESS)
        {
            g_medply.duration = 0 ;
        }

        g_medply.progress_speed = mmi_medply_determine_progress_speed(g_medply.duration);
        g_medply.seekable = MMI_TRUE;

        if(g_medply.duration == 0)
        {
            g_medply.seekable = MMI_FALSE;
        }
        else
        {
        #ifdef __DRM_SUPPORT__
            U8 ret ;
            ret = mmi_medply_drm_valide_right((PU16)g_medply.filefullpath);
            if(ret ==2)
            {
                g_medply.seekable = MMI_FALSE;
            }
            else
       #endif
            {
                if(g_medply.is_audio_seekable == MMI_FALSE)
                {
                    g_medply.seekable = MMI_FALSE;
                }
            }
        }
    }

    /* Check if file condition */
    handle = FS_GetAttributes((PU16)g_medply.filefullpath);

    if (handle >= FS_NO_ERROR)
    {
        *file_issue = MMI_FALSE;
    }
    else
    {
        *file_issue = MMI_TRUE;
        return (S32)handle;
    }

    if (mdi_audio_is_background_play_suspended())
    {
        result = MDI_AUDIO_TERMINATED;
    }
    else
    {
        #ifdef __MMI_AUDIO_TIME_STRETCH__
        if( mmi_medply_settings_check_and_set_audio_speed() != MDI_AUDIO_SUCCESS)
        {
            return MDI_AUDIO_UNSUPPORTED_SPEED;
        }
        #endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

        #ifdef __MMI_AUDIO_VOCAL_REMOVAL__
        if(mmi_medply_is_kuro_file()&& g_medply.vocal_removal == MMI_SETTINGS_VOCAL_REMOVAL_ON && g_medply.vocal_removal_enabled)
        {    
            mmi_settings_apply_track_effect(MMI_SETTINGS_TRACK_EFFECTS_VOCAL_REMOVAL,g_medply.vocal_removal);
        }
        #endif

        #ifdef __MMI_AUDIO_PITCH_SHIFTING__
        if(mmi_medply_is_kuro_file()&& g_medply.pitch != MMI_SETTINGS_PITCH_SHIFTING_0)
        {
            mmi_settings_apply_track_effect(MMI_SETTINGS_TRACK_EFFECTS_PITCH_SHIFTING,g_medply.pitch);
        }
        #endif

        cache_ptr = mmi_medply_determine_cache_ptr();

        /*regisiter auto update time callback*/
        mdi_audio_regisiter_auto_update_duration_handler(mmi_medply_audio_auto_update_duration_hdlr);

        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_AUD_PLAY_ACT_EXT, g_medply.seekable, g_medply.duration, g_medply.mute, g_medply.current_time);

    #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_DRM_CONSUMED, g_medply.DRM_consumed);
        if (g_medply.DRM_consumed)
        {
        #if defined (__DRM_SUPPORT__)
            mdi_audio_drm_disable_consume_count();
        #endif /* __DRM_SUPPORT__ */
        }
        else
        {
            g_medply.DRM_consumed = MMI_TRUE;
        }
    #endif /*defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)*/

        if(g_medply.mute)
        {
            volume = 0 ;
        }

        /* Portion play request */
        result = mdi_audio_play_file_portion_with_vol_path(
                   g_medply.filefullpath,
                   g_medply.current_time,
                   0,
                   DEVICE_AUDIO_PLAY_ONCE,
                   cache_ptr,
                   mmi_medply_audio_play_callback_hdlr,
                   NULL,
                   MDI_AUD_VOL_EX_MUTE(volume),
                   MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));


        /* Reset speed if not play successfully */
        if (result != MDI_AUDIO_SUCCESS)
        {
        #ifdef __MMI_AUDIO_TIME_STRETCH__
            mmi_medply_settings_close_speed();
        #endif /* __MMI_AUDIO_TIME_STRETCH__ */ 
        #if defined(__MMI_AUDIO_VOCAL_REMOVAL__) || defined(__MMI_AUDIO_PITCH_SHIFTING__)
            mmi_settings_apply_track_effect(MMI_SETTINGS_TRACK_EFFECTS_NONE,0);
        #endif
        }

    }

    return (S32) result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_audio_do_play_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_audio_do_play_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = MDI_AUDIO_SUCCESS;
    MMI_BOOL file_issue = MMI_FALSE;
//enhance
#if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__) || defined(__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__)
    MMI_BOOL already_added_to_recent_play = g_medply.DRM_consumed ;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result =  mmi_medply_audio_do_play_action_ext(&file_issue);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_AUD_PLAY_ACT, result,file_issue);

    if (!file_issue)
    {
        /* When no file issue happens - resent fs error popup */
        g_medply.fs_error_pop_up = MMI_TRUE;

        /*not filemgr issue*/
        if (result == MDI_AUDIO_SUCCESS)
        {
//enhance
        #if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__) || defined(__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__)
            if(!already_added_to_recent_play)
            {
                mmi_medply_plst_add_to_recent_played();
            }
        #endif
            if(g_medply.state == MEDPLY_STATE_AUDIO_WAIT_ACTIVATE || g_medply.state == MEDPLY_STATE_AUDIO_BT_CONNECTING_WAIT_ACTIVATE)
            {
                mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PLAY_WAIT_ACTIVATE);
            }
            else
            {
                mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PLAY);
            }
        }
        else if (result == MDI_AUDIO_END_OF_FILE)
        {
//enhance
        #if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__) || defined(__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__)
            if(!already_added_to_recent_play)
            {
                mmi_medply_plst_add_to_recent_played();
            }
        #endif

            if(g_medply.widget_callback != NULL)
            {
                g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDGET_PLAYER_PLAY_END_CALLBACK,NULL);
            }

            g_medply.current_time= g_medply.duration;
            mmi_medply_main_screen_draw_duration();
            mmi_medply_main_screen_blt();

            mmi_medply_play_completed(MMI_FALSE,MMI_TRUE);
        }
        else if(result == MDI_AUDIO_TERMINATED)
        {
            /*stop bt since we might connect bt and try to play but terminated*/
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            /*when mdi is suspended or other bg app is using*/
            mmi_medply_set_continue_flag(MMI_TRUE);

            if(g_medply.state == MEDPLY_STATE_AUDIO_WAIT_ACTIVATE || g_medply.state == MEDPLY_STATE_AUDIO_BT_CONNECTING_WAIT_ACTIVATE)
            {
                mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_INTERRUPTED_WAIT_ACTIVATE);
            }
            else
            {
                mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_INTERRUPTED);
            }
        }    
        else
        {
            mmi_medply_plst_notify_file_not_available(MEDPLY_FAIL_PLAY_TYPE_MED_ISSUE);        
            mmi_medply_display_popup(result,MMI_TRUE);
            mmi_medply_play_completed(MMI_TRUE,MMI_TRUE); 
        }
    }
    else
    {
        /*file issue*/
        MMI_ID_TYPE string_id;
        mmi_event_notify_enum popup_type;

        mmi_medply_plst_notify_file_not_available(MEDPLY_FAIL_PLAY_TYPE_FILE_ISSUE);
        /* MAUI_03248329 - display popup for file is not present MAUI_03333013 - only show one popup */
        if (g_medply.fs_error_pop_up == MMI_TRUE)
        {
            g_medply.fs_error_pop_up = MMI_FALSE;
            string_id = srv_fmgr_fs_error_get_string_and_popup_type(result, (S32*)&popup_type);
            mmi_medply_display_popup_with_sg(string_id, popup_type);
        }
        mmi_medply_play_completed(MMI_FALSE,MMI_TRUE);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_audio_play
 * DESCRIPTION
 *  paly audio main function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_audio_play(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_AUD_PLAY);

#ifdef __MMI_A2DP_SUPPORT__
    if( mmi_medply_settings_is_output_to_bt() )
    {
        /*handle background play*/
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);

        /*enter audio_bt_connecting state before av_bt_open in case open returns fail directly
          and callback will handle as audio_ready state*/
        if(g_medply.state == MEDPLY_STATE_AUDIO_WAIT_ACTIVATE)
        {
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_BT_CONNECTING_WAIT_ACTIVATE);
        }
        else
        {
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_BT_CONNECTING);
        }

        av_bt_open(mmi_medply_settings_get_bt_headset(), g_medply.filefullpath,
            mmi_medply_bt_open_callback, (kal_bool)(!mmi_medply_settings_is_audio_speed_normal()),
            KAL_TRUE);
        return;
    }
    else
#endif /* __MMI_A2DP_SUPPORT__ */
    {
        /*handle background play*/
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);
        mmi_medply_audio_do_play_action();
    }
}

#endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

#ifdef __MMI_MEDIA_PLAYER_VIDEO__

#ifdef __MMI_VIDEO_3D_ANAGLYPH__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_get_video_speed_factor
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  S16
 *****************************************************************************/
static void mmi_medply_check_and_set_play_mode(mdi_video_info_struct *vdo_clip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 play_mode = 0;
	U32 i;
    U32 index_2d = 0, index_3d = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_CHECK_AND_SET_TRACK,g_medply.has_2d_mode, g_medply.has_3d_mode);
    for( i = 0; i < vdo_clip->track_num; i++)
    {
        if(g_medply.has_3d_mode == MMI_FALSE && MDI_VIDEO_TRACK_3D == vdo_clip->track_info[i].track_type)
        {
            g_medply.has_3d_mode = MMI_TRUE;
            index_3d = vdo_clip->track_info[i].track_index;
        }
        else if( g_medply.has_2d_mode == MMI_FALSE && MDI_VIDEO_TRACK_2D_NORMAL == vdo_clip->track_info[i].track_type)
        {
            g_medply.has_2d_mode = MMI_TRUE;
            index_2d = vdo_clip->track_info[i].track_index;
        }     
    }  

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_CHECK_AND_SET_TRACK,g_medply.has_2d_mode, g_medply.has_3d_mode);

    if(g_medply.has_3d_mode && g_medply.has_2d_mode)
    {
        mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_PLAY_MODE,(void*)&play_mode);
        if(play_mode == MDI_VIDEO_TRACK_3D)
        {
            mdi_video_ply_set_track_index(index_3d);
        }
        else if(play_mode == MDI_VIDEO_TRACK_2D_NORMAL)
        {
           mdi_video_ply_set_track_index(index_2d);
        }
    }
    else if(g_medply.has_3d_mode)
    {
        mdi_video_ply_set_track_index(index_3d);
    }
    else if(g_medply.has_2d_mode)
    {
        mdi_video_ply_set_track_index(index_2d);
    }
    
    
}
#endif

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_check_and_set_subtitle
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  S16
 *****************************************************************************/
static void mmi_medply_check_and_set_subtitle(mdi_video_info_struct *vdo_clip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U32 i;
    U32 i; //Eason
    U8* phone_lcc;
    U8* subtitle_lcc;
    U32 settings_iso;
    U32 match_iso_track_index = 0;
    U32 settings_track_index = 0;
    MMI_BOOL track_index_result;
    MMI_BOOL iso_result;
    MMI_BOOL has_match_index = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_CHECK_AND_SET_SUBTITLE_TRACK,vdo_clip->subtitle_num);
    if(g_medply.track == MDI_VIDEO_TRACK_A_ONLY || vdo_clip->subtitle_num<=0)
    {
         g_medply.has_subtitle = MMI_FALSE;
         return;
    }

    g_medply.has_subtitle = MMI_TRUE;

    track_index_result = mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_SUBTITLE_TRACK_INDEX, &settings_track_index);
    if(track_index_result == MMI_TRUE)
    {
        mdi_video_ply_set_subtitle_track_index(settings_track_index);
    }
    else
    {
        iso_result = mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_SUBTITLE_LCC, &settings_iso);

        mmi_medply_settings_subtitle_iso_startup();

        for(i = 0; i< vdo_clip->subtitle_num; i++)
        {
            mmi_medply_settings_subtitle_iso_add_iso_element(vdo_clip->subtitle_info[i].track_index, vdo_clip->subtitle_info[i].language);
        }
        
        mmi_li_Get_Current_LCC(&phone_lcc);
        
        i = vdo_clip->subtitle_num;
        do
        {
            i--;
            if(iso_result == MMI_TRUE)
            {
                if(vdo_clip->subtitle_info[i].language == settings_iso)
                {
                    match_iso_track_index = vdo_clip->subtitle_info[i].track_index;
                    mmi_medply_settings_subtitle_iso_set_active_iso(
                                vdo_clip->subtitle_info[i].track_index, 
                                vdo_clip->subtitle_info[i].language);
                    has_match_index = MMI_TRUE;
                }
            }
            else
            {
                mmi_li_get_lcc(vdo_clip->subtitle_info[i].language, &subtitle_lcc);
                if(phone_lcc == subtitle_lcc)
                {
                    match_iso_track_index = vdo_clip->subtitle_info[i].track_index;
                    mmi_medply_settings_subtitle_iso_set_active_iso(
                                vdo_clip->subtitle_info[i].track_index, 
                                vdo_clip->subtitle_info[i].language);
                    has_match_index = MMI_TRUE;
                }
            }
        }
        while(i != 0);

       if (has_match_index == MMI_TRUE)
       {
           mdi_video_ply_set_subtitle_track_index(match_iso_track_index);
       }
       else
       {
           mmi_medply_settings_subtitle_iso_set_active_iso(
                                vdo_clip->subtitle_info[0].track_index, 
                                vdo_clip->subtitle_info[0].language);
           mdi_video_ply_set_subtitle_track_index(vdo_clip->subtitle_info[0].track_index);
       }
    }

    mdi_video_ply_set_subtitle_font_size(g_medply.subtitle_font_size);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_get_video_speed_factor
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  S16
 *****************************************************************************/
static S16 mmi_medply_get_video_speed_factor()
{
#ifdef __MMI_MEDIA_PLAYER_VIDEO_SPEED__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 speed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_VIDEO_SPEED,(void*)&speed);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_VDO_SPEED,speed);
    return speed;
#else /* __MMI_MEDIA_PLAYER_VIDEO_SPEED__ */ 
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_VDO_SPEED,100);
    return 100; /* 1x play speed */
#endif /* __MMI_MEDIA_PLAYER_VIDEO_SPEED__ */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_interrupted
 * DESCRIPTION
 *  handle video/pure audio interrupted by other audio
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_video_interrupted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_INTERRUPTED, g_medply.state);

    switch(g_medply.state)
    {
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
        {
            mmi_medply_set_continue_flag(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_VIDEO_IDLE:
        case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
        case MEDPLY_STATE_PURE_AUDIO_READY:
        {
            mmi_medply_set_continue_flag(MMI_FALSE);
            break;
        }

        case MEDPLY_STATE_VIDEO_OPENING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_main_screen_video_updated();
            break;
        }

        case MEDPLY_STATE_VIDEO_READY:
        case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
        {
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_FALSE);
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
        case MEDPLY_STATE_VIDEO_BT_CONNECTING:
        {
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY:
        {
            mdi_video_ply_stop();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_TRUE);
            break;            
        }

        case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_main_screen_video_updated();
            break;            
        }

        case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_main_screen_video_updated();
            break;            
        }

        default:
        {
            break;
        }
    }

#ifdef __MMI_A2DP_SUPPORT__
    mmi_medply_bt_stop(MMI_FALSE);
#endif

    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_INTERRUPTED);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_open_callback_hdlr
 * DESCRIPTION
 *  to handle open callback, continue to do seek action if open success
 * PARAMETERS
 *  result          [IN]        >=0, means successfully opened, if result < 0 measn some error happened)
 *  vdo_clip        [IN]        Video info
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_video_open_callback_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_OPEN_CALLBACK_1,result, MMI_FALSE);
    
    if (result >= 0)
    {
        /* open sucess */
        U16 brightness, contrast;
        mmi_medply_video_play_para_struct video_layer_info;

        mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_BRIGHTNESS,(void*)&brightness);
        mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_CONTRAST,(void*)&contrast);

        /* set brightness/contrast */
        mdi_video_ply_set_brightness(brightness);
        mdi_video_ply_set_contrast(contrast);

        /* fit it into player window */
        g_medply.width = vdo_clip->width;
        g_medply.height = vdo_clip->height;
        g_medply.duration = vdo_clip->total_time_duration;
        g_medply.progress_speed = mmi_medply_determine_progress_speed(g_medply.duration);
        g_medply.seekable = vdo_clip->is_seekable;
        g_medply.track = vdo_clip->track;
        g_medply.aud_channel_no = vdo_clip->aud_channel_no;        
        g_medply.aud_sample_rate= vdo_clip->aud_sample_rate;

       #ifdef __MMI_VIDEO_3D_ANAGLYPH__
        mmi_medply_check_and_set_play_mode(vdo_clip);
        #endif
        
        #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        mmi_medply_check_and_set_subtitle(vdo_clip);
        #endif

        /* this avoid driver return total time druation == 0, which will cause divid by zero */
        if (g_medply.duration == 0)
        {
            g_medply.seekable = MMI_FALSE;
            g_medply.current_time= 0;
        }

        /* in case enter from pure audio and current time is larger then duration*/
        if (g_medply.current_time > g_medply.duration)
        {
            g_medply.current_time = g_medply.duration;
        }

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_OPEN_CALLBACK_2, (U32)g_medply.duration, g_medply.seekable,g_medply.track, MMI_FALSE);

        if(g_medply.track == MDI_VIDEO_TRACK_A_ONLY)
        {
            g_medply.height = 0;
            g_medply.width = 0;
        }

        video_layer_info.video_height = g_medply.height;
        video_layer_info.video_width = g_medply.width;
        mmi_medply_main_screen_get_video_parameter(&video_layer_info);

        /* since we might have to seek to far away from begining, so we use non_block seek*/
        result = mmi_medply_adption_video_non_block_seek_and_get_frame(
                g_medply.current_time,
                video_layer_info.layer_hdl,
                #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                video_layer_info.layer_subtitle_hdl,
                #endif
                mmi_medply_video_seek_callback_hdlr,
                0);

        if(result >= 0)
        {
            return;
        }

    }

    /*since open success but seek fail, need to close*/
    mmi_medply_video_close();
    mdi_audio_clear_interrupt_callback();

    mmi_medply_set_pop_up_flag();
    mmi_medply_display_popup(result,MMI_TRUE);
    mmi_medply_play_completed(MMI_TRUE,g_medply.continue_to_play);
    return;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_seek_callback_hdlr
 * DESCRIPTION
 *  seek result
 * PARAMETERS
 *  result      [IN]        Seek result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_video_seek_callback_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_SEEK_CALLBACK, result, g_medply.state, MMI_FALSE);

    /* error happened */
    if (result < 0 && result != MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED)
    {
        mmi_medply_video_close();
        mdi_audio_clear_interrupt_callback();

        mmi_medply_set_pop_up_flag();
        mmi_medply_display_popup(result,MMI_TRUE);
        switch(g_medply.state)
        {
            case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
            {
                mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
                break;
            }
            case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
            {
                mmi_medply_play_completed(MMI_TRUE,MMI_FALSE);
                break;
            }
            case MEDPLY_STATE_VIDEO_OPENING:
            {
                mmi_medply_play_completed(MMI_TRUE,g_medply.continue_to_play);
                break;
            }
        }

        return;
    }

    /* seek partial done, so need to reassign current time to seek time */
    if (result == MDI_RES_VDOPLY_SEEK_PARTIAL_DONE)
    {
        /* get current play time */
        mdi_video_ply_get_cur_play_time(&g_medply.current_time);
    }

    mmi_medply_main_screen_video_updated();
    mmi_medply_main_screen_blt();

    mmi_medply_main_screen_stop_animation(MMI_MEDPLY_ANI_VIDEO_OPENING);

    /* enter next state */
    switch (g_medply.state)
    {
        case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
        {
            mmi_medply_video_play();
            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
        {
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
            break;
        }

        case MEDPLY_STATE_VIDEO_OPENING:
        {
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
            break;
        }

    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_play_callback_hdlr
 * DESCRIPTION
 *  video play callback handler
 * PARAMETERS
 *  result      [IN]        >=0, means successfully finished, 
 *                          if result < 0 measn some error happened
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_video_play_callback_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if not in player screen */
    /* 
     * this may happend when video has error and driver send out this message, 
     * but before MMI receive this message, MMI stop and play the video again, 
     * that will cause driver to send another play finish message. When MMI 
     * receive first message, it will exit and display popup, when the second 
     * message comes, MMI already exit video play app. so we shall igore this 
     * message.
     */

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_PLAY_CALLBACK, result, g_medply.in_main_screen, MMI_FALSE);

    if(!g_medply.in_main_screen)
    {
        return;
    }
    /* new mdi error code , following error code should be ignore */
    if(result == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR || result == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
    {
        return;
    }

    /* error happened */
    if (result < 0 )
    {
        mmi_medply_video_close();
        mdi_audio_clear_interrupt_callback();

        mmi_medply_set_pop_up_flag();
        mmi_medply_display_popup(result,MMI_TRUE);
        mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
        return;
    }

    if(!g_medply.fullscreen)
    {
        /* draw timer bar to end */
        g_medply.current_time = g_medply.duration;

        mmi_medply_main_screen_draw_duration();
        mmi_medply_main_screen_blt();

        if(g_medply.widget_callback != NULL)
        {
            g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDGET_PLAYER_PLAY_END_CALLBACK,NULL);
        }

    }


    mmi_medply_video_close();
    mdi_audio_clear_interrupt_callback();
    mmi_medply_play_completed(MMI_FALSE,MMI_TRUE);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_play_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_pure_audio_play_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_PURE_AUD_PLAY_CALLBACK, result, g_medply.state, g_medply.self_stop);

    /* restore to normal speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    mmi_medply_settings_close_speed();
#endif 

    if(g_medply.state != MEDPLY_STATE_PURE_AUDIO_PLAY && g_medply.state != MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING)
    {
        return;
    }

    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
        {

            if(g_medply.widget_callback != NULL)
            {
                g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDGET_PLAYER_PLAY_END_CALLBACK,NULL);
            }

            mmi_medply_play_completed(MMI_FALSE,MMI_TRUE);
            break;
        }

        case MDI_AUDIO_TERMINATED:
        {
            if(g_medply.self_stop)
            {
                return;
            }
            mdi_audio_stop_file();
            mmi_medply_video_interrupted();
            break;
        }

    #ifdef __DRM_SUPPORT__
        case MDI_AUDIO_DRM_TIMEOUT:
        {
            mmi_medply_set_self_stop_flag(MMI_TRUE);

            mdi_audio_stop_file();

            mmi_medply_set_self_stop_flag(MMI_FALSE);

            mmi_medply_display_popup(result,MMI_TRUE);
            mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
            break;
        }
    #endif /* __DRM_SUPPORT__ */

        default:
        {
            mmi_medply_display_popup(result,MMI_TRUE);
            mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_audio_interrupt_callback_hdlr
 * DESCRIPTION
 *  audio interrupt callback for video playing
 *  since we will not suspend bg play in media player, there shall be a way for
 *  mdi audio to inform media player about audio interrupt
 * PARAMETERS
 *  result      [IN]        only accept MDI_AUDIO_TERMINATED
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_video_audio_interrupt_callback_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_AUD_INTERRUPT_CALLBACK, result, g_medply.state);

    if(result == MDI_AUDIO_TERMINATED)
    {

        switch(g_medply.state)
        {
            case MEDPLY_STATE_VIDEO_OPENING:
            case MEDPLY_STATE_VIDEO_IDLE:
            case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
            case MEDPLY_STATE_VIDEO_READY:
            case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
            case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
            case MEDPLY_STATE_VIDEO_PLAY:
            case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
            case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
            case MEDPLY_STATE_VIDEO_BT_CONNECTING:
            {
                mmi_medply_video_interrupted();
                break;
            }

            default:
            {
                break;
            }
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_open
 * DESCRIPTION
 *  open video file
 *  in media player design, open action has to take care of non-block seeking to
 *  the spot
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_video_open(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result = -1 ;
    FS_HANDLE handle;
    MMI_BOOL file_issue = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if file condition */
    handle = FS_GetAttributes((PU16)g_medply.filefullpath);

    mdi_audio_register_interrupt_callback(mmi_medply_video_audio_interrupt_callback_hdlr, NULL);

    if (handle >= FS_NO_ERROR)
    {

    #ifdef __DRM_SUPPORT__
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_DRM_CONSUMED, g_medply.DRM_consumed);
        if (g_medply.DRM_consumed)
        {
            mdi_video_ply_drm_disable_consume_count();            
        }
    #endif /* __DRM_SUPPORT__ */

        #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_DEFAULT_N_SUBTITLE);
        #endif

        result = mdi_video_ply_open_file(APP_MEDPLY, (CHAR*)g_medply.filefullpath, mmi_medply_video_open_callback_hdlr, 0);
    }
    else
    {
        file_issue = MMI_TRUE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_OPEN, result, g_medply.continue_to_play, MMI_FALSE);

    if(result<0)
    {
        /*error happened*/
        MMI_BOOL popup = MMI_TRUE;
        if(file_issue)
        {
            mmi_medply_plst_notify_file_not_available(MEDPLY_FAIL_PLAY_TYPE_FILE_ISSUE);
            popup = MMI_FALSE;
        }
        else
        {
            mmi_medply_plst_notify_file_not_available(MEDPLY_FAIL_PLAY_TYPE_MED_ISSUE);
            mmi_medply_set_pop_up_flag();
            mmi_medply_display_popup(result,MMI_TRUE);
        }
        mdi_audio_clear_interrupt_callback();
        mmi_medply_play_completed(popup,MMI_TRUE);

        return MMI_FALSE;

    }
    else
    {
        mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_OPENING);
        return MMI_TRUE;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_do_play_action_ext
 * DESCRIPTION
 *  start play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MDI_RESULT mmi_medply_video_do_play_action_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    U8 volume = g_medply.volume;
    mmi_medply_video_play_para_struct video_layer_info;
    S16 video_speed = 100;
    BOOL is_play_audio = TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_PLAY_ACT_EXT, g_medply.mute);

#if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_DRM_CONSUMED, g_medply.DRM_consumed);
    if (g_medply.DRM_consumed)
    {
    #ifdef __DRM_SUPPORT__
        mdi_video_ply_drm_disable_consume_count();
    #endif /* __DRM_SUPPORT__ */
    }
    else
    {
        g_medply.DRM_consumed = MMI_TRUE;
    }
#endif /*defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)*/

    if(g_medply.mute)
    {
        volume = 0 ;
    }


    mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(volume));

    video_layer_info.video_height = g_medply.height;
    video_layer_info.video_width = g_medply.width;
    mmi_medply_main_screen_get_video_parameter(&video_layer_info);

    if(g_medply.track != MDI_VIDEO_TRACK_A_ONLY)
    {
        video_speed = mmi_medply_get_video_speed_factor();
    }

#if defined(__RF_DESENSE_TEST__) && defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        is_play_audio = FALSE;
    }
#endif /* defined(__RF_DESENSE_TEST__) && defined(__MMI_BACKGROUND_CALL__) */


    result = mmi_medply_adption_video_play(
            video_layer_info.layer_hdl,          /* play layer handle */
            video_layer_info.layer_blt_flag,     /* blt layer */
            video_layer_info.layer_play_flag,    /* play_layer_flag */
            #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            video_layer_info.layer_subtitle_hdl,
            video_layer_info.layer_subtitle_flag,
            #endif
            1,                                      /* repeat */
            TRUE,                                   /* visual update */
            is_play_audio,                          /* play aud */
            MDI_DEVICE_SPEAKER2,                    /* audio path */
            video_layer_info.layer_lcd_rotate,   /* rotate */
            video_speed,                         /* speed factor */
            mmi_medply_video_play_callback_hdlr,
            0);   /* play layer */


    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_do_play_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_video_do_play_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MDI_RESULT result;
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
    MMI_BOOL already_added_to_recent_play = g_medply.DRM_consumed ;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*turn on backlight to make sure video will not play in LCD turn off situation*/
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    /* start play video */
    result = mmi_medply_video_do_play_action_ext();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_PLAY_ACT, result);

    if(result >= 0)
    {
    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
        if(!already_added_to_recent_play)
        {
            mmi_medply_plst_add_to_recent_played();
        }
    #endif
        mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PLAY);
        return;
    }
    else
    {
        mmi_medply_video_close();
        mdi_audio_clear_interrupt_callback();

        mmi_medply_set_pop_up_flag();
        mmi_medply_display_popup(result,MMI_TRUE);
        mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
    }

    return;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_pure_audio_do_play_action_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMI_BOOL    [OUT]    returning if error belongs to file system issue
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_pure_audio_do_play_action_ext(MMI_BOOL *file_issue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    FS_HANDLE handle;

    U8  volume = g_medply.volume;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_PURE_AUD_PLAY_ACT_EXT, g_medply.mute);

    /* Check if file condition */
    handle = FS_GetAttributes((PU16)g_medply.filefullpath);
    
    if (handle >= FS_NO_ERROR)
    {
        *file_issue = MMI_FALSE;
    }
    else
    {
        *file_issue = MMI_TRUE;
        return (S32)handle;
    }

    /* This could happen when timer experied after suspend background play or another play or record req by others */
    if (mdi_audio_is_background_play_suspended())
    {
        result = MDI_AUDIO_TERMINATED;
    }
    else
    {
    #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_DRM_CONSUMED, g_medply.DRM_consumed);
        if (g_medply.DRM_consumed)
        {
        #if defined (__DRM_SUPPORT__)
            mdi_audio_drm_disable_consume_count();
        #endif /* __DRM_SUPPORT__ */
        }
        else
        {
            g_medply.DRM_consumed = MMI_TRUE;
        }
    #endif /*defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)*/

        if(g_medply.mute)
        {
            volume = 0 ;
        }

        /* Portion play request */
        result = mdi_audio_play_file_portion_with_vol_path(
                   g_medply.filefullpath,
                   g_medply.current_time,
                   0,
                   DEVICE_AUDIO_PLAY_ONCE,
                   NULL,
                   mmi_medply_pure_audio_play_callback_hdlr,
                   NULL,
                   MDI_AUD_VOL_EX_MUTE(volume),
                   MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2));

    }

    return (S32) result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_pure_audio_do_play_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_pure_audio_do_play_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    MMI_BOOL file_issue = MMI_FALSE;
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
    MMI_BOOL already_added_to_recent_play = g_medply.DRM_consumed ;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result =  mmi_medply_pure_audio_do_play_action_ext(&file_issue);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_PURE_AUD_PLAY_ACT, result);

    if (!file_issue)
    {
        /*not filemgr issue*/
        if (result == MDI_AUDIO_SUCCESS)
        {
        #ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
            if(!already_added_to_recent_play)
            {
                mmi_medply_plst_add_to_recent_played();
            }
        #endif
            mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_PLAY);
        }
        else if (result == MDI_AUDIO_END_OF_FILE)
        {
        #ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
            if(!already_added_to_recent_play)
            {
                mmi_medply_plst_add_to_recent_played();
            }
        #endif

            if(g_medply.widget_callback != NULL)
            {
                g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDGET_PLAYER_PLAY_END_CALLBACK,NULL);
            }

            /* in the case that we stopped a file when it's play finished */
            mmi_medply_play_completed(MMI_FALSE,MMI_TRUE);
        }
        else if(result == MDI_AUDIO_TERMINATED)
        {
            /*stop bt since we might connect bt and try to play but terminated*/
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            /*when mdi is suspended or other bg app is using*/
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_INTERRUPTED);
        }    
        else
        {
            mmi_medply_plst_notify_file_not_available(MEDPLY_FAIL_PLAY_TYPE_MED_ISSUE);

        #if defined(MJPG_DECODE) || defined(__MKV_FILE_FORMAT_SUPPORT__)
            if(g_medply.media_format == MEDPLY_FORMAT_AVI || g_medply.media_format == MEDPLY_FORMAT_MKV || g_medply.media_format == MEDPLY_FORMAT_WEBM)
            {
                mmi_medply_display_popup_with_sg(STR_ID_MEDPLY_ERR_NOT_SUPPORT_PURE_AUDIO, MMI_EVENT_FAILURE);

            }
            else
        #endif
                mmi_medply_display_popup(result,MMI_TRUE);

            mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
        }
    }
    else
    {
        /*file issue*/
        mmi_medply_plst_notify_file_not_available(MEDPLY_FAIL_PLAY_TYPE_FILE_ISSUE);
        mmi_medply_play_completed(MMI_FALSE,MMI_TRUE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_play
 * DESCRIPTION
 *  paly video main function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_video_play(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_A2DP_SUPPORT__
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_PLAY_1,g_medply.state, g_medply.bt_connect_fail, g_medply.track);

    if( mmi_medply_settings_is_output_to_bt() && !g_medply.bt_connect_fail)
    {

        MMI_BOOL is_stereo;
        
        /*handle background play*/
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);
        
        if (g_medply.aud_channel_no == 2)
        {
            is_stereo = MMI_TRUE;
        }
        else
        {
            is_stereo = MMI_FALSE;
        }
        
        switch(g_medply.state)
        {
            case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
            case MEDPLY_STATE_VIDEO_READY:
            case MEDPLY_STATE_VIDEO_PAUSE_SEEKING: /*for full screen case*/
            {
                if(g_medply.track != MDI_VIDEO_TRACK_V_ONLY)
                {
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_BT_CONNECTING);

                    /*put this behind enter states because some times it will callback directly with in 
                    this function, in that case, entering bt connecting state would be too late*/        
                    av_bt_open_ex(
                          mmi_medply_settings_get_bt_headset(),
                          g_medply.aud_sample_rate,
                         (kal_bool)is_stereo,
                         mmi_medply_bt_open_callback,
                         KAL_TRUE);
                }
                else
                {
                    mmi_medply_video_do_play_action();
                    return;
                }
                break;
            }

            case MEDPLY_STATE_PURE_AUDIO_READY:
            {
                if(g_medply.track != MDI_VIDEO_TRACK_V_ONLY)
                {
                    mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING);
                    av_bt_open(
                          mmi_medply_settings_get_bt_headset(), g_medply.filefullpath,
                          mmi_medply_bt_open_callback, KAL_TRUE,KAL_TRUE);
                }
                else
                {
                    /*if video track only, then do not try to play and leave state in MEDPLY_STATE_PURE_AUDIO_READY*/
                    mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                    return;
                }
                break;
            }
        }

    }
    else
#endif /* __MMI_A2DP_SUPPORT__ */
    {    
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_PLAY_2,g_medply.state, g_medply.track);

        /*handle background play*/
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);
        switch(g_medply.state)
        {
            case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
            case MEDPLY_STATE_VIDEO_READY:
            case MEDPLY_STATE_VIDEO_PAUSE_SEEKING: /*for full screen case*/
            {        
                mmi_medply_video_do_play_action();
                break;
            }

            case MEDPLY_STATE_PURE_AUDIO_READY:
            {
                /*if video track only, then do not try to play and leave state in MEDPLY_STATE_PURE_AUDIO_READY*/
                if(g_medply.track != MDI_VIDEO_TRACK_V_ONLY)
                {
                    /* MAUI_03333109 -Since pure audio playback is not supported now keep media player in pure audio ready state */
                    //mmi_medply_pure_audio_do_play_action();
                    mmi_medply_set_continue_flag(MMI_TRUE);
                }

                break;
            }
            
        }
    }
    return;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_pause
 * DESCRIPTION
 *  pause video fucntion, actually it stops video file but not reset time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_video_pause(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_PAUSE,g_medply.state, MMI_FALSE);

    switch(g_medply.state)
    {
        case MEDPLY_STATE_VIDEO_PLAY:
        {
            MDI_RESULT result;

            /*stop video*/
            result = mdi_video_ply_stop();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif


            if(result == MDI_RES_VDOPLY_ALREADY_FINISHED)
            {
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();

                mmi_medply_main_screen_clear_video_layer();

                /* draw timer bar to end */
                g_medply.current_time = g_medply.duration;
                mmi_medply_main_screen_draw_duration();

                mmi_medply_main_screen_blt();

                if(g_medply.widget_callback != NULL)
                {
                    g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDGET_PLAYER_PLAY_END_CALLBACK,NULL);
                }

                mmi_medply_set_pop_up_flag();

                mmi_medply_display_popup_with_sg(STR_ID_MEDPLY_ERR_VIDEO_ALREADY_FINISHED, MMI_EVENT_FAILURE);

                mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
                break;                
            }
            
            /* set current time to lastest */
            mdi_video_ply_get_cur_play_time(&g_medply.current_time);

            if(g_medply.current_time > g_medply.duration)
            {
                g_medply.duration = g_medply.current_time;
            }

            mmi_medply_set_continue_flag(MMI_FALSE);

            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
            
            break;
        }

        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        {

            /*update to latest time*/
            mdi_audio_get_progress_time((U32*)(&g_medply.current_time));

            mmi_medply_set_self_stop_flag(MMI_TRUE);
        
            /*stop file*/
            mdi_audio_stop_file();
        
            mmi_medply_set_self_stop_flag(MMI_FALSE);
        
            
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            /*not in main screen, so clear background*/
            mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
        
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);

        #ifdef __MMI_AUDIO_TIME_STRETCH__
            mmi_medply_settings_close_speed();
        #endif

            break;
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_close
 * DESCRIPTION
 *  close video file fucntion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_video_close(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_ply_close_file();
    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
    g_medply.has_2d_mode = MMI_FALSE;
    g_medply.has_3d_mode = MMI_FALSE;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_stop
 * DESCRIPTION
 *  stop video fucntion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_video_stop(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    mmi_medply_video_play_para_struct video_layer_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_STOP,g_medply.state);

    /*stop video*/
    mdi_video_ply_stop();

    mmi_medply_clear_play_seconds();

#if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
    g_medply.DRM_consumed = MMI_FALSE;
#endif    

#ifdef __MMI_A2DP_SUPPORT__
    g_medply.bt_connect_fail = MMI_FALSE;
    mmi_medply_bt_stop(MMI_FALSE);
#endif


    video_layer_info.video_height = g_medply.height;
    video_layer_info.video_width = g_medply.width;
    mmi_medply_main_screen_get_video_parameter(&video_layer_info);

    result = mmi_medply_adption_video_seek_and_get_frame(
                g_medply.current_time, 
                video_layer_info.layer_hdl
                #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                ,video_layer_info.layer_subtitle_hdl
                #endif
                );

    if(result < 0)
    {
        mmi_medply_set_pop_up_flag();
        mmi_medply_display_popup(result,MMI_TRUE);
        mmi_medply_play_completed(MMI_TRUE,MMI_FALSE);

        return;
    }
    else
    {        
        mmi_medply_set_continue_flag(MMI_FALSE);
        
        mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
    }


}

#endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

#ifdef __MMI_MEDIA_PLAYER_STREAM__

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_interrupted
 * DESCRIPTION
 *  handle streaming audio interrupted by other audio
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_stream_interrupted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_INTERRUPTED,g_medply.state);

    switch(g_medply.state)
    {
        case MEDPLY_STATE_STREAM_INITED:
        {
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_FALSE);
            break;
        }

        case MEDPLY_STATE_STREAM_CONNECTING:
        case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:            
        case MEDPLY_STATE_STREAM_BT_CONNECTING:            
        {
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_TRUE);
            break;
        }
        
        case MEDPLY_STATE_STREAM_CONNECTED:
        {
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_FALSE);
            break;
        }

        case MEDPLY_STATE_STREAM_BUFFERING:
        {
            StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
            mdi_video_stream_stop_buffering();
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_STREAM_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:            
        {
            mdi_video_stream_stop();
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_TRUE);
            break;
        }

        default:
        {
            break;
        }
    }

#ifdef __MMI_A2DP_SUPPORT__
    mmi_medply_bt_stop(MMI_FALSE);
#endif

    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INTERRUPTED);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bear_event_disconnect
 * DESCRIPTION
 *  check if mediaplayer is currently playing or prepare to play
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static void mmi_medply_bear_event_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_medply.bearer_pause == MMI_TRUE)
    {
        return;
    }
    
    mmi_medply_set_continue_flag(MMI_FALSE);
    
    switch(g_medply.state)
    {
        case MEDPLY_STATE_STREAM_CONNECTING:
        {
            mdi_video_stream_disconnect();
            g_medply.bearer_pause = MMI_TRUE;
            if(!g_medply.in_media_player)
            {
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            else
            {
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
            }
            break;
        }

        case MEDPLY_STATE_STREAM_INTERRUPTED:
        {
        	  g_medply.bearer_pause = MMI_TRUE;
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif
            mmi_medply_main_screen_reset();
            mmi_medply_main_screen_blt();
            break;
        }

        case MEDPLY_STATE_STREAM_CONNECTED:
        {
            mdi_video_stream_disconnect();
            g_medply.bearer_pause = MMI_TRUE;
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);

        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif
            mmi_medply_main_screen_reset();
            mmi_medply_main_screen_blt();

            if(g_medply.widget_callback != NULL)
            {
                g_medply.widget_callback(g_medply.widget_callback_userdata,MMI_WIDTET_PLAYER_RESET_TIME_CALLBACK,NULL);
            }
            break;
        }

        case MEDPLY_STATE_STREAM_BUFFERING:         
        {
            StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
            mdi_video_stream_stop_buffering();
        #ifdef __MMI_A2DP_SUPPORT__            
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            /*while not in main screen, disconnect*/
            mdi_video_stream_disconnect();
            g_medply.bearer_pause = MMI_TRUE;

            if(!g_medply.in_media_player)
            {
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            else
            {
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
            }
    }

    break;


    case MEDPLY_STATE_STREAM_PLAY:
    case MEDPLY_STATE_STREAM_AUDIO_PLAY:
    case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
    {
        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
        g_medply.DRM_consumed = MMI_FALSE;
        #endif

        mdi_video_stream_stop();

        #ifdef __MMI_A2DP_SUPPORT__
        mmi_medply_bt_stop(MMI_FALSE);
        #endif
        
        mdi_video_stream_disconnect();
        g_medply.bearer_pause = MMI_TRUE;
            
        if(!g_medply.in_media_player)
        {
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
            mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
        }
        else
        {
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
        }
        break;
    }

    case MEDPLY_STATE_STREAM_BT_CONNECTING:
    {
    #ifdef __MMI_A2DP_SUPPORT__
        mmi_medply_bt_stop(MMI_FALSE);
    #endif
        mdi_video_stream_disconnect();
        g_medply.bearer_pause = MMI_TRUE;
        

        /* audio is stopped, clear background hdlr here*/
        if(!g_medply.in_media_player)
        {
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
            mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
        }
        else
        {
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
        }
        break;
    }
    default:
        break;
    } 
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bear_event_reconnect
 * DESCRIPTION
 *  check if mediaplayer is currently playing or prepare to play
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static void mmi_medply_bear_event_reconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_medply.bearer_pause == MMI_TRUE)
    {
        g_medply.bearer_pause = MMI_FALSE;
        if(g_medply.state == MEDPLY_STATE_STREAM_INITED)
        {
            mmi_medply_stream_connect();
        }
        else if(g_medply.state == MEDPLY_STATE_STREAM_IDLE)
        {
            result = mmi_medply_stream_init();
            if(result)
            {
                mmi_medply_stream_connect();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bear_event_callback_hdlr
 * DESCRIPTION
 *  check if mediaplayer is currently playing or prepare to play
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static mmi_ret mmi_medply_bear_event_callback_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_bearer_event_struct *cbm_event = (srv_cbm_bearer_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_BEAR_EVENT_CALLBACK, cbm_event->type, g_medply.state, g_medply.bearer_pause);
    if(g_medply.media_type != MEDPLY_TYPE_STREAM)
    {
        return MMI_RET_OK;
    }
    
    switch(cbm_event->type)
    {
        case SRV_CBM_BEARER_EVENT_DISCONNECT:
            mmi_medply_bear_event_disconnect();
            break;

        case SRV_CBM_BEARER_EVENT_SWITCH:
            mmi_medply_bear_event_disconnect();
            mmi_medply_bear_event_reconnect();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
      
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_buffering_callback_hdlr
 * DESCRIPTION
 *  callback handler of stream buffering
 * PARAMETERS
 *  result          [IN]        >=0, means successfully opened, if result < 0 measn some error happened)
 *  stream_info     [IN]        stream info
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_medply_stream_buffering_callback_hdlr(MDI_RESULT result, mdi_video_info_struct *stream_info, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_BUF_CALLBACK,result,MMI_FALSE);

    StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
    
    /*open sucessfully */
    if (result >= 0)
    {
        U16 brightness, contrast;

        /* draw progress bar to 100%*/
        mmi_medply_main_screen_show_loading(100);

        mmi_medply_main_screen_stop_animation(MMI_MEDPLY_ANI_LOADING);

        mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_BRIGHTNESS,(void*)&brightness);
        mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_CONTRAST,(void*)&contrast);    
    
        mdi_video_stream_set_brightness(brightness);
        mdi_video_stream_set_contrast(contrast);

        g_medply.width = stream_info->width;
        g_medply.height = stream_info->height;

        if(g_medply.track == MDI_VIDEO_TRACK_A_ONLY)
        {
            g_medply.height = 0;
            g_medply.width = 0;
        }

        /*turn on backlight to make sure video will not play in LCD turn off situation*/
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        mmi_medply_stream_play();

    }
    else
    {
        mmi_medply_set_pop_up_flag();
        mmi_medply_display_popup(result,MMI_TRUE);

        mdi_video_stream_disconnect();
        mmi_medply_stream_deinit();

        g_medply.state = MEDPLY_STATE_STREAM_IDLE;

        mdi_audio_clear_interrupt_callback();
        mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_play_callback_hdlr
 * DESCRIPTION
 *  callback handler of stream play
 * PARAMETERS
 *  result          [IN]        >=0, means successfully opened, if result < 0 measn some error happened
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_stream_play_callback_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_PLAY_CALLBACK, result, g_medply.seekable, MMI_FALSE);

    if(result<0)
    {
        mmi_medply_set_pop_up_flag();
        mmi_medply_display_popup(result,MMI_TRUE);

        mdi_video_stream_disconnect();
        mmi_medply_stream_deinit();

        g_medply.state = MEDPLY_STATE_STREAM_IDLE;

        mdi_audio_clear_interrupt_callback();
        
        mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
        return;
    }

    /* new mdi error code , following error code should be ignore */
    if(result == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR || result == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR)
    {
        return;
    }

    if(result== MDI_RES_VDOPLY_STREAM_BUFFER_OVERFLOW || result== MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW)
    {
        /*need update video content */
        mmi_medply_main_screen_video_updated();
        mmi_medply_main_screen_blt();


        if(g_medply.seekable)
        {
            mdi_video_stream_get_cur_play_time(&g_medply.current_time);
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mmi_medply_stream_buffer();
        }
        else
        {
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mdi_video_stream_disconnect();
            mmi_medply_stream_connect();
        }
        return;
    }

    if(g_medply.seekable && !g_medply.fullscreen)
    {
        g_medply.current_time = g_medply.duration;

        mmi_medply_main_screen_draw_duration();
        mmi_medply_main_screen_blt();

        if(g_medply.widget_callback != NULL)
        {
            g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDGET_PLAYER_PLAY_END_CALLBACK,NULL);
        }

    }


    mdi_video_stream_disconnect();
    mmi_medply_stream_deinit();

    g_medply.state = MEDPLY_STATE_STREAM_IDLE;

    mdi_audio_clear_interrupt_callback();
    mmi_medply_play_completed(MMI_FALSE,MMI_TRUE);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_audio_interrupt_callback_hdlr
 * DESCRIPTION
 *  audio interrupt callback for stream playing
 *  since we will not suspend bg play in media player, there shall be a way for
 *  mdi audio to inform media player about audio interrupt
 * PARAMETERS
 *  result      [IN]        only accept MDI_AUDIO_TERMINATED
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_stream_audio_interrupt_callback_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_AUD_INTERRUPT_CALLBACK,result, g_medply.state);

    if(result == MDI_AUDIO_TERMINATED)
    {

        switch(g_medply.state)
        {
            case MEDPLY_STATE_STREAM_INITED:
            case MEDPLY_STATE_STREAM_CONNECTING:
            case MEDPLY_STATE_STREAM_CONNECTED:
            case MEDPLY_STATE_STREAM_BUFFERING:
            case MEDPLY_STATE_STREAM_PLAY:
            case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
            case MEDPLY_STATE_STREAM_AUDIO_PLAY:
            case MEDPLY_STATE_STREAM_BT_CONNECTING:
            case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
            {
                mmi_medply_stream_interrupted();
            }

            default:
            {
                break;
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_connect_callback_hdlr
 * DESCRIPTION
 *  callback handler of stream connecting
 * PARAMETERS
 *  result          [IN]        >=0, means successfully opened, if result < 0 measn some error happened)
 *  stream_info     [IN]        stream info
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_medply_stream_connect_callback_hdlr(MDI_RESULT result, mdi_video_info_struct *stream_info, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    S32 i;
    MMI_BOOL is_valid;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_CONNECT_CALLBACK_1,result, g_medply.state, MMI_FALSE);

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
        #ifdef __MMI_A2DP_SUPPORT__
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
#endif
    if (result == MDI_RES_VDOPLY_STREAM_DRM_NEED_RIGHT)
    {
        /* no permission - shall disconnect and show popup */
        mdi_video_stream_disconnect();
        mmi_medply_stream_deinit();

        g_medply.state = MEDPLY_STATE_STREAM_IDLE;

        mmi_medply_set_pop_up_flag();
        mmi_medply_display_popup(result,MMI_TRUE);
        
        mdi_audio_clear_interrupt_callback();        

        mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);

        return;
    }

    if (result >= 0)
    {
        mmi_medply_main_screen_stop_animation(MMI_MEDPLY_ANI_RTP_CONNECTING);

        g_medply.duration = stream_info->total_time_duration;
        g_medply.progress_speed = mmi_medply_determine_progress_speed(g_medply.duration);        
        g_medply.seekable = stream_info->is_seekable;

        if (g_medply.duration == 0)
        {
            g_medply.seekable = MMI_FALSE;
        }

        if(g_medply.current_time > g_medply.duration)
        {
            g_medply.current_time = g_medply.duration ;
        }

        g_medply.track = stream_info->track;
        g_medply.aud_channel_no = stream_info->aud_channel_no;
        g_medply.aud_sample_rate = stream_info->aud_sample_rate;

        str_len = strlen((CHAR*)stream_info->title_desc);

        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_STREAM_CONNECT_CALLBACK_2,g_medply.duration, g_medply.seekable, g_medply.track, str_len, MMI_FALSE);

        /* stream has title, change title name to this 
           when steram title is null, use file_title*/

        memset(g_medply.stream_title, 0, sizeof(g_medply.stream_title)); 

        if (str_len != 0)
        {
            /* check if title is all space */
            is_valid = MMI_FALSE;
            for (i = 0; i < str_len; i++)
            {
                if (stream_info->title_desc[i] != ' ')
                {
                    is_valid = MMI_TRUE;
                    break;                    
                }
            }

            if (is_valid)
            {              
                mmi_asc_n_to_ucs2(
                    (CHAR*)g_medply.stream_title,
                    (CHAR*)&stream_info->title_desc, 
                    MDI_VIDEO_INFO_TITLE_CHAR_COUNT - 1);
            }
        }
        
#ifdef __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__
        if (g_medply.media_format!= MEDPLY_FORMAT_RAM)
        {
            mmi_medply_history_insert_url((CHAR*)g_medply.filefullpath, (CHAR*)g_medply.stream_title, MMI_FALSE);
        }
        else
        {
            mmi_medply_history_insert_url((CHAR*)g_medply.url_path , (CHAR*)g_medply.stream_title, MMI_FALSE);
        }
#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__ */

        if(g_medply.track == MDI_VIDEO_TRACK_V_ONLY && !g_medply.in_main_screen)
        {
            /*can not play audio only, so stay in connected state or disconnect for live streaming*/
            /*live*/
            mmi_medply_set_continue_flag(MMI_FALSE);
            mdi_video_stream_disconnect();
            if(!g_medply.in_media_player)
            {
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);                    
            }
            else
            {
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
            }
            return;
        }

        mmi_medply_set_continue_flag(MMI_TRUE);
        mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_CONNECTED);
    
    }
    else
    {
        mmi_medply_set_pop_up_flag();
        mmi_medply_display_popup(result,MMI_TRUE);

        if(result == MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT)
        {
            mmi_medply_stream_deinit();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mdi_audio_clear_interrupt_callback();
            mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
        }
        else
        {
            mmi_medply_set_continue_flag(MMI_FALSE);

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            if (g_medply.in_media_player)
            {
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
            }
            else
            {            
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_update_buffer_percent
 * DESCRIPTION
 *  start a timer to update buffer percentage
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_medply_stream_update_buffer_percent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_medply.state != MEDPLY_STATE_STREAM_BUFFERING)
    {
        return;  
    }

    mdi_video_stream_get_buf_percentage(&percentage);

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_STREAM_UPDATE_BUF_PERCENT, percentage, MMI_FALSE);

    /* draw progress bar*/
    mmi_medply_main_screen_show_loading(percentage);

    if(percentage <100)
    {
        StartTimer(MEDPLY_STREAM_BUFFER_TIMER, 300, mmi_medply_stream_update_buffer_percent);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_do_buffer_action
 * DESCRIPTION
 *  start buffering action
 * PARAMETERS
 *  void
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_medply_stream_do_buffer_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_BUF_ACT, g_medply.in_main_screen, g_medply.seekable);

    if (mdi_audio_is_background_play_suspended() && !g_medply.in_main_screen)
    {

        mdi_video_stream_disconnect();        
    #ifdef __MMI_A2DP_SUPPORT__
        mmi_medply_bt_stop(MMI_FALSE);    
    #endif
        mmi_medply_set_continue_flag(MMI_TRUE);
        mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INTERRUPTED);
        return;
    }

    if(g_medply.in_main_screen)
    {
    #if defined(__CS_STREAMING_CONCURRENT_SUPPORT__) && defined(__MMI_BACKGROUND_CALL__)
        if (srv_ucm_is_background_call())
        {
            mdi_video_stream_set_track(MDI_VIDEO_TRACK_V_ONLY);
        }
        else
    #endif /* defined(__RF_DESENSE_TEST__) && defined(__MMI_BACKGROUND_CALL__) */
    
        mdi_video_stream_set_track(MDI_VIDEO_TRACK_AV);
    }
    else
    {
        mdi_video_stream_set_track(MDI_VIDEO_TRACK_A_ONLY);
    }

    if (g_medply.seekable)
    {
        result = mdi_video_stream_start_buffering(
                 g_medply.current_time,            
                 mmi_medply_stream_buffering_callback_hdlr,
                 NULL);
    }
    else
    {
        result = mdi_video_stream_start_buffering(
                 0,            
                 mmi_medply_stream_buffering_callback_hdlr,
                 NULL);
    }

    if (result == MDI_RES_VDOPLY_STREAM_DRM_NEED_RIGHT)
    {
        /* no permission - shall disconnect and show popup */
        mdi_video_stream_disconnect();
        mmi_medply_stream_deinit();

        g_medply.state = MEDPLY_STATE_STREAM_IDLE;

        mmi_medply_set_pop_up_flag();
        mmi_medply_display_popup(result,MMI_TRUE);
        
        mdi_audio_clear_interrupt_callback();
        mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
        return;
    }
   
    if(result<0)
    {
        mmi_medply_set_pop_up_flag();
        mmi_medply_display_popup(result,MMI_TRUE);
        mdi_video_stream_disconnect();
        mmi_medply_stream_deinit();

        g_medply.state = MEDPLY_STATE_STREAM_IDLE;

        mdi_audio_clear_interrupt_callback();
        mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
    }
    else
    {
        StartTimer(MEDPLY_STREAM_BUFFER_TIMER, 100, mmi_medply_stream_update_buffer_percent);
        /*if currently is stream buffering, it is foregornd background switching*/
        if(g_medply.state != MEDPLY_STATE_STREAM_BUFFERING)
        {
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_BUFFERING);
        }
    }
    
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_stop
 * DESCRIPTION
 *  stream stop main funcion, it shall stop stream and reset time
 * PARAMETERS
 *  void
 * RETURNS
 * 
 *****************************************************************************/
void mmi_medply_stream_stop()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_medply_video_play_para_struct video_layer_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_STOP, g_medply.in_main_screen, g_medply.in_media_player, g_medply.seekable);

#if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
    g_medply.DRM_consumed = MMI_FALSE;
#endif

    mdi_video_stream_stop();

#ifdef __MMI_A2DP_SUPPORT__
    mmi_medply_bt_stop(MMI_FALSE);
#endif

    mmi_medply_clear_play_seconds();

    /*only draw black in main screen since it might be AVRCP command*/
    if(g_medply.in_main_screen)
    {
        video_layer_info.video_height = g_medply.height;
        video_layer_info.video_width = g_medply.width;
        mmi_medply_main_screen_get_video_parameter(&video_layer_info);

        gdi_layer_push_and_set_active(video_layer_info.layer_hdl);
        gdi_layer_clear(GDI_COLOR_BLACK);    
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();

        mmi_medply_main_screen_blt();
    }

    if(g_medply.seekable)
    {
        /*while not in main screen, disconnect*/
        mdi_video_stream_disconnect();
        mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
    }
    else
    {
        /*live, shall disconnect while pause*/
        mdi_video_stream_disconnect();
        mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
    }

    /* stream is stopped, clear background hdlr here*/
    if(!g_medply.in_media_player)
    {
        mmi_medply_stream_deinit();
        mdi_audio_clear_interrupt_callback();
        mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
    }


}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_pause
 * DESCRIPTION
 *  stream pause main funcion, it shall not reset time
 * PARAMETERS
 *  void
 * RETURNS
 * 
 *****************************************************************************/
void mmi_medply_stream_pause()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_PAUSE, g_medply.in_main_screen, g_medply.in_media_player, g_medply.seekable);

    mdi_video_stream_stop();
    
#ifdef __MMI_A2DP_SUPPORT__    
    mmi_medply_bt_stop(MMI_FALSE);
#endif


    if(g_medply.seekable)
    {
        /* get latest time */    
        mdi_video_stream_get_cur_play_time(&g_medply.current_time);

        if(g_medply.current_time > g_medply.duration)
        {
            g_medply.duration = g_medply.current_time;
        }

        if(g_medply.in_main_screen)
        {
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_CONNECTED);
        }
        else
        {
            /*while not in main screen, disconnect*/
            mdi_video_stream_disconnect();
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);            
        }
    }
    else
    {
        /*live, shall disconnect while pause*/
        mdi_video_stream_disconnect();
        g_medply.duration = 0;
        g_medply.current_time = 0;

        mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
    }

    /* audio is stopped, clear background hdlr here*/
    if(!g_medply.in_media_player)
    {
        mmi_medply_stream_deinit();
        mdi_audio_clear_interrupt_callback();
        mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
    }    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_play
 * DESCRIPTION
 *  stream play main funcion
 * PARAMETERS
 *  void
 * RETURNS
 * 
 *****************************************************************************/
void mmi_medply_stream_play()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT  result;
    MMI_BOOL visual_update = MMI_TRUE;
    U8  volume = g_medply.volume ;
    mmi_medply_video_play_para_struct video_layer_info;
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
    MMI_BOOL already_added_to_recent_play = g_medply.DRM_consumed ;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_PLAY, g_medply.in_main_screen, g_medply.mute, MMI_FALSE);

#if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_DRM_CONSUMED, g_medply.DRM_consumed);
    if (g_medply.DRM_consumed)
    {
    #ifdef __DRM_SUPPORT__
        mdi_video_stream_drm_disable_consume_count();
    #endif /* __DRM_SUPPORT__ */
    }
    else
    {
        g_medply.DRM_consumed = MMI_TRUE;    
    }
#endif /*defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)*/

    if(!g_medply.in_main_screen)
    {
        if(g_medply.track == MDI_VIDEO_TRACK_V_ONLY)
        {
            mdi_video_stream_stop_buffering();
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mdi_audio_clear_interrupt_callback();
            mmi_medply_play_completed(MMI_FALSE,MMI_TRUE);
            return;
        }
            
        mdi_video_stream_set_track(MDI_VIDEO_TRACK_A_ONLY);
        visual_update = MMI_FALSE;
    }
    else
    {
    #if defined(__CS_STREAMING_CONCURRENT_SUPPORT__) && defined(__MMI_BACKGROUND_CALL__)
        if (srv_ucm_is_background_call())
        {
            mdi_video_stream_set_track(MDI_VIDEO_TRACK_V_ONLY);
        }
        else
    #endif /* defined(__RF_DESENSE_TEST__) && defined(__MMI_BACKGROUND_CALL__) */

        mdi_video_stream_set_track(MDI_VIDEO_TRACK_AV);
    }

    if(g_medply.mute)
    {
        volume = 0;
    }
 
 
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(volume));

    video_layer_info.video_height = g_medply.height;
    video_layer_info.video_width = g_medply.width;
    mmi_medply_main_screen_get_video_parameter(&video_layer_info);

    result = mdi_video_stream_play(
                video_layer_info.layer_hdl,          /* play_layer_handle */
                video_layer_info.layer_blt_flag,     /* blt_layer */ 
                video_layer_info.layer_play_flag,    /* play_layer */
                visual_update,
                MDI_DEVICE_SPEAKER2, 
                video_layer_info.layer_lcd_rotate,   /* rotate */
                mmi_medply_stream_play_callback_hdlr,
                NULL
                );

    if (result == MDI_RES_VDOPLY_SUCCEED)
    {
    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
        if(!already_added_to_recent_play)
        {
            mmi_medply_plst_add_to_recent_played();
        }
    #endif

        if(!g_medply.in_main_screen)
        {
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_AUDIO_PLAY);             
        }
        else
        {
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_PLAY);
        }
    }    
    else
    {
        mmi_medply_set_pop_up_flag();
        mmi_medply_display_popup(result,MMI_TRUE);

        mdi_video_stream_disconnect();
        mmi_medply_stream_deinit();

        g_medply.state = MEDPLY_STATE_STREAM_IDLE;

        mdi_audio_clear_interrupt_callback();
        mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
    }
    

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_buffer
 * DESCRIPTION
 *  stream buffer main function, when bt output is on, connect bt first
 * PARAMETERS
 *  void
 * RETURNS
 * 
 *****************************************************************************/
void mmi_medply_stream_buffer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_BUF);

#ifdef __MMI_A2DP_SUPPORT__
    if(mmi_medply_settings_is_output_to_bt())
    {
        MMI_BOOL is_stereo;
        
        /*handle background play*/
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);

        if(g_medply.track != MDI_VIDEO_TRACK_V_ONLY)
        {
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_BT_CONNECTING);
        }
        else
        {
            mmi_medply_stream_do_buffer_action();
            return;
        }

        if(g_medply.aud_channel_no == 0 || g_medply.aud_sample_rate == 0)
        {
            mdi_video_stream_get_audio_info(&(g_medply.aud_channel_no),&(g_medply.aud_sample_rate));
        }

        if (g_medply.aud_channel_no == 2)
        {
            is_stereo = MMI_TRUE;
        }
        else
        {
            is_stereo = MMI_FALSE;
        }

       /*put this behind enter states because some times it will callback directly with in 
         this function, in that case, entering bt connecting state would be too late*/
        av_bt_open_ex(
            mmi_medply_settings_get_bt_headset(),
            g_medply.aud_sample_rate,
            (kal_bool)is_stereo,
            mmi_medply_bt_open_callback,
            KAL_TRUE
            );

    }
    else
#endif /*__MMI_A2DP_SUPPORT__*/
    {
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);    
        mmi_medply_stream_do_buffer_action();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_connect
 * DESCRIPTION
 *  connect for streamming main function
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_stream_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result = -1 ;
    nvram_ef_medply_settings_profile_struct* profile_p;
    mdi_video_stream_type_enum stream_type;
    MMI_BOOL file_issue = MMI_FALSE;
    FS_HANDLE handle = NULL ;
    U32 data_account_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_CONNECT, g_medply.media_format, MMI_FALSE);

    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_PROFILE,(void*)&profile_p);
    mmi_medply_settings_get_data_account_id(&data_account_id);
#ifdef __DRM_SUPPORT__
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_DRM_CONSUMED, g_medply.DRM_consumed);
    if (g_medply.DRM_consumed)
    {
        /*skip DRM right checking*/
        mdi_video_stream_drm_disable_consume_count();            
    }
#endif /* __DRM_SUPPORT__ */

    switch(g_medply.media_format)
    {
        case MEDPLY_FORMAT_RTSP:
        {
            stream_type = MDI_VIDEO_STREAM_RTSP_URL;
            break;
        }

        case MEDPLY_FORMAT_RAM:
        {
            CHAR url_buf[SRV_FMGR_PATH_MAX_LEN+1];
            U32 readed;

            stream_type = MDI_VIDEO_STREAM_RTSP_URL;

            handle = DRM_open_file((U16*)g_medply.filefullpath, FS_READ_ONLY, DRM_PERMISSION_NONE);

            memset(url_buf, 0, SRV_FMGR_PATH_MAX_LEN+1);
            
            if (handle < FS_NO_ERROR)
            {
                file_issue = MMI_TRUE;
                break;
            }
            else
            {
                DRM_read_file(handle, (void*)url_buf, SRV_FMGR_PATH_MAX_LEN, &readed);
                DRM_close_file(handle);
            }

            memset(g_medply.url_path, 0 , sizeof(g_medply.url_path));
            mmi_asc_to_ucs2((CHAR*)g_medply.url_path, (CHAR*)url_buf);

            break;            
        }

        case MEDPLY_FORMAT_SDP:
        {
            stream_type = MDI_VIDEO_STREAM_SDP_FILE;
            
            /* Check if file condition */
            handle = FS_GetAttributes((PU16)g_medply.filefullpath);
            
            if (handle < FS_NO_ERROR)
            {
                file_issue = MMI_TRUE;
            }

            break;
        }

        default:
        {
            stream_type = MDI_VIDEO_STREAM_SDP_FILE;
            MMI_ASSERT(0);
            break;
        }
    }

    if(!file_issue)
    {
        if(g_medply.media_format!= MEDPLY_FORMAT_RAM)
        {
            result = mdi_video_stream_connect(
                        data_account_id,
                        stream_type,
                        (CHAR*)g_medply.filefullpath, 
                        (MMI_BOOL)profile_p->proxy_on_off, 
                        profile_p->proxy_addr, 
                        profile_p->proxy_port,
                        MMI_TRUE,
                        profile_p->highest_udp_port,
                        profile_p->lowest_udp_port,
                        mmi_medply_stream_connect_callback_hdlr,
                        NULL);
        }
        else
        {
            result = mdi_video_stream_connect(
                        data_account_id,
                        stream_type,
                        (CHAR*)g_medply.url_path, 
                        (MMI_BOOL)profile_p->proxy_on_off, 
                        profile_p->proxy_addr, 
                        profile_p->proxy_port,
                        MMI_TRUE,
                        profile_p->highest_udp_port,
                        profile_p->lowest_udp_port,
                        mmi_medply_stream_connect_callback_hdlr,
                        NULL);
        }
    }

    if(result != MDI_RES_VDOPLY_SUCCEED)
    {
        /*error happened*/
        MMI_BOOL popup = MMI_TRUE;
              
        if(file_issue)
        {
            mmi_medply_plst_notify_file_not_available(MEDPLY_FAIL_PLAY_TYPE_FILE_ISSUE);
            popup = MMI_FALSE;
        }
        else
        {
            mmi_medply_plst_notify_file_not_available(MEDPLY_FAIL_PLAY_TYPE_MED_ISSUE);
            mmi_medply_set_pop_up_flag();
            mmi_medply_display_popup(result,MMI_TRUE);
        }
        mmi_medply_stream_deinit();

        g_medply.state = MEDPLY_STATE_STREAM_IDLE;

        mdi_audio_clear_interrupt_callback();
        mmi_medply_play_completed(popup,MMI_TRUE);

        return MMI_FALSE;
    }

    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_CONNECTING);

    return MMI_TRUE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_init
 * DESCRIPTION
 *  init stream
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL     to see if init success or not
 *****************************************************************************/
MMI_BOOL mmi_medply_stream_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mdi_audio_register_interrupt_callback(mmi_medply_stream_audio_interrupt_callback_hdlr, NULL);    

    mmi_medply_register_bear_event(mmi_medply_bear_event_callback_hdlr);
    result = mdi_video_stream_init(APP_MEDPLY);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_INIT, result, MMI_FALSE);

    if(result != MDI_RES_VDOPLY_SUCCEED)
    {
        /*error happened*/
        mdi_audio_clear_interrupt_callback();

        mmi_medply_set_pop_up_flag();
        mmi_medply_display_popup(result,MMI_TRUE);
        mmi_medply_play_completed(MMI_TRUE,g_medply.continue_to_play);
        return MMI_FALSE;
    }

    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stream_deinit
 * DESCRIPTION
 *  init stream
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL     to see if init success or not
 *****************************************************************************/
void mmi_medply_stream_deinit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_stream_deinit();
    mmi_medply_deregister_bear_event();
}

#endif /*__MMI_MEDIA_PLAYER_STREAM__*/

#ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_enable_snapshot_button
 * DESCRIPTION
 *  snap shot will be disabled for shor time after taking one snap shot to avoids
 *  burestly taking and make MMI too busy, this api is to enable snap again.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_enable_snapshot_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_medply.enable_snapshot = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_get_next_snapshot_filename
 * DESCRIPTION
 *  get next file name for snapshot
 * PARAMETERS
 *  file_buf        [OUT]       Filename buffer ptr
 *  file_path       [IN]        Filepath
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_get_next_snapshot_filename(CHAR* file_buf, CHAR* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR buffer[25];
    CHAR UCS2_buffer[50];
    CHAR UCS2_testname[50];
    CHAR UCS2_alpha[10];
    U16 alpha_count;
    U16 alpha_index;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_medply.filename_seq_no == 0xffff)
    {
        g_medply.filename_seq_no = 1;    /* init value */
    }
    else
    {
        g_medply.filename_seq_no++;
        if (g_medply.filename_seq_no > 9999) /* more than 4 digits */
        {
            g_medply.filename_seq_no = 1;
        }
    }

    alpha_count = 'Z' - 'A' + 1;
    alpha_index = 0;

    sprintf((CHAR*) buffer, "SNP%04d", g_medply.filename_seq_no);
    mmi_asc_to_ucs2((CHAR*) UCS2_buffer, (CHAR*) buffer);

    while (1)
    {
        sprintf((CHAR*) buffer, "%c", 'A' + alpha_index);
        mmi_asc_to_ucs2((CHAR*) UCS2_alpha, (CHAR*) buffer);

        mmi_ucs2cpy(UCS2_testname, UCS2_buffer);
        mmi_ucs2cat(UCS2_testname, UCS2_alpha);
        mmi_ucs2cat(UCS2_testname, (CHAR*) L".jpg");

        mmi_ucs2ncpy((CHAR*) file_buf, (CHAR*) file_path, SRV_FMGR_PATH_MAX_LEN+1);
        mmi_ucs2cat((CHAR*) file_buf, (CHAR*) UCS2_testname);

        file_handle = DRM_open_file((U16*) file_buf, FS_READ_ONLY, DRM_PERMISSION_NONE);


        if (file_handle >= 0)
        {
            /* file exist */
            DRM_close_file(file_handle);
            alpha_index++;
        }
        else
        {
            /* file not exit. return */
            return;
        }

        /* exit condition - will get a IMGXXXXZ.jpg as file name */
        if (alpha_index >= alpha_count - 1)
        {
            return;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_snapshot_pause
 * DESCRIPTION
 *  pause video/stream file temporarily for snapshot taking
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_snapshot_pause(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_SNAPSHOT_PAUSE, g_medply.state);

    switch(g_medply.state)
    {
#ifdef __MMI_MEDIA_PLAYER_VIDEO__    
        case MEDPLY_STATE_VIDEO_PLAY:
        {
            /*stop video*/
            result = mdi_video_ply_stop();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif


            if(result == MDI_RES_VDOPLY_ALREADY_FINISHED)
            {
                mmi_medply_video_close();

                /* draw timer bar to end */
                g_medply.current_time = g_medply.duration;

                mmi_medply_main_screen_draw_duration();
                mmi_medply_main_screen_blt();

                mdi_audio_clear_interrupt_callback();

                if(g_medply.widget_callback != NULL)
                {
                    g_medply.widget_callback(g_medply.widget_callback_userdata, MMI_WIDGET_PLAYER_PLAY_END_CALLBACK,NULL);
                }

                mmi_medply_set_pop_up_flag();

                mmi_medply_display_popup_with_sg(STR_ID_MEDPLY_ERR_VIDEO_ALREADY_FINISHED, MMI_EVENT_FAILURE);

                mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
                return MMI_FALSE;                
            }
            break;
        }

        case MEDPLY_STATE_VIDEO_READY:
        {
            break;
        }

#endif /* __MMI_MEDIA_PLAYER_VIDEO__*/

#ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_PLAY:
        {
            result = mdi_video_stream_stop();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

        /* live stream shall reset the duration and current time */
        if(!g_medply.seekable)
        {
            g_medply.duration = 0;
            g_medply.current_time = 0;
        }


            if(result != MDI_RES_VDOPLY_SUCCEED)
            {
                mdi_video_stream_disconnect();
                mmi_medply_stream_deinit();

                g_medply.state = MEDPLY_STATE_STREAM_IDLE;

                mdi_audio_clear_interrupt_callback();
                mmi_medply_set_pop_up_flag();
                mmi_medply_display_popup(MDI_RES_VDOPLY_ERR_SNAPSHOT_FAILED,MMI_TRUE);
                mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);
                return MMI_FALSE;
            }
            break;
        }
#endif /* __MMI_MEDIA_PLAYER_VIDEO__*/

        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return MMI_TRUE;    

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_snapshot_resume
 * DESCRIPTION
 *  resume video/stream file from snapshot taking
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_snapshot_resume(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_SNAPSHOT_RESUME, g_medply.prev_state);
    
    switch(g_medply.prev_state)
    {
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_PLAY:
        {
            g_medply.state = MEDPLY_STATE_VIDEO_READY;
            mmi_medply_video_play();
            break;
        }

        case MEDPLY_STATE_VIDEO_READY:
        {
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
            break;
        }
    #endif /* __MMI_MEDIA_PLAYER_VIDEO__*/

    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_PLAY:
        {
            mmi_medply_stream_buffer();
            break;
        }
    #endif /* __MMI_MEDIA_PLAYER_STREAM__*/

        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_take_snapshot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_take_snapshot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR buf_pathname[SRV_FMGR_PATH_BUFFER_SIZE];
    CHAR buf_filename[SRV_FMGR_PATH_BUFFER_SIZE];
    MDI_RESULT result;
    MDI_RESULT snap_result;
    S32 create_result;
    MMI_BOOL take_result;
    mmi_medply_video_play_para_struct video_layer_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_TAKE_SNAPSHOT);

    /* init value */
    result = MDI_RES_VDOPLY_SUCCEED;
    /*
    {
        CHAR drv_buf[8];
        U16 drv = mmi_imgview_get_storage();
        sprintf(drv_buf, "%c:\\", (U8)drv);
        mmi_asc_to_ucs2(buf_pathname, drv_buf);
        mmi_ucs2cat((CHAR*) buf_pathname, (CHAR*) FMGR_DEFAULT_FOLDER_PHOTOS);
    }
    */

    create_result = mmi_imgview_get_storage_file_path((WCHAR*)buf_pathname);
    /* check if imgview storage path is valid or not */
    if (FS_NO_ERROR == FS_GetDevStatus((U16)buf_pathname[0] ,FS_MOUNT_STATE_ENUM))
    {
        /* if drv is valid, check if the folder is crated or not */
        /*create_result = mmi_imgview_create_file_dir(buf_pathname);*/

        /* create directory failed */
        if (create_result == FS_WRITE_PROTECTION)
        {
            result = MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION;
        }
        else if (create_result == FS_DISK_FULL)
        {
            result = MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL;
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            result = MDI_RES_VDOPLY_ERR_SNAPSHOT_ROOT_DIR_FULL;
        }

        if(result != MDI_RES_VDOPLY_SUCCEED)
        {
            mmi_medply_display_popup(result,MMI_TRUE);
            return;
        }
    }

    /* start snapshot */
    mmi_medply_get_next_snapshot_filename(buf_filename, buf_pathname);

    take_result = mmi_medply_snapshot_pause();

    if(!take_result)
    {
        return;
    }

    video_layer_info.video_height = g_medply.height;
    video_layer_info.video_width = g_medply.width;
    mmi_medply_main_screen_get_video_parameter(&video_layer_info);

    snap_result = mdi_video_ply_snapshot(video_layer_info.layer_hdl, buf_filename);

    /* error check */
    if(snap_result != MDI_RES_VDOPLY_SUCCEED)
    {
        switch(g_medply.state)
        {
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__    
            case MEDPLY_STATE_VIDEO_PLAY:
            {
                mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
                break;
            }
    #endif
    #ifdef __MMI_MEDIA_PLAYER_STREAM__
            case MEDPLY_STATE_STREAM_PLAY:
            {
                if(g_medply.seekable)
                {
                    mmi_medply_enter_video_states(MEDPLY_STATE_STREAM_CONNECTED);
                }
                else
                {
                    /*live, shall disconnect while pause*/
                    mdi_video_stream_disconnect();
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
                }
                break;
            }
    #endif
            default:
            {
                break;
            }
        }
        mmi_medply_display_popup(snap_result,MMI_TRUE);
        return;
    }

    mmi_medply_enter_core_states(MEDPLY_STATE_SNAPSHOT);
    /* show 200 ms */
    kal_sleep_task(50);

    mmi_medply_main_screen_stop_animation(MMI_MEDPLY_ANI_SNAP_SHOT);
    mmi_medply_snapshot_resume();

    g_medply.enable_snapshot = MMI_FALSE;
    gui_start_timer(500, mmi_medply_enable_snapshot_button);

    return;

}

#endif /*__MMI_MEDIA_PLAYER_SNAPSHOT__*/

#ifdef __MMI_A2DP_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bt_open_callback
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_bt_open_callback(S32 result)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_BT_OPEN_CALLBACK_IN, result, g_medply.state, g_medply.inquiry_paused, g_medply.bt_success_during_inquiry);

    mmi_medply_main_screen_stop_animation(MMI_MEDPLY_ANI_BT_CONNECTING);

    switch( result )
    {
        case AV_BT_CALLBACK_EVENT_OPEN_OK:
        {
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
                {
                    /*while inquirying, postpone until inquiry action is over */
                    if(!av_bt_is_inquiry())
                    {
                        av_bt_open_codec(KAL_TRUE);
                        #if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) 
                        {
                            g_medply.A2DP_blocked = MMI_TRUE;
                            mmi_medply_main_screen_stop_spectrum();
                        }
                        #endif
                        mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PLAY);
                    }
                    else
                    {
                        g_medply.bt_success_during_inquiry = MMI_TRUE;
                    }
                    break;
                }

                case MEDPLY_STATE_AUDIO_BT_CONNECTING:
                {
                    if(!av_bt_is_inquiry())
                    {
                        av_bt_open_codec(KAL_FALSE);
                    #if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) 
                        g_medply.A2DP_blocked = MMI_TRUE;
                    #endif    
                        mmi_medply_audio_do_play_action();
                    }
                    else
                    {
                        g_medply.bt_success_during_inquiry = MMI_TRUE;
                    }
                    break;
                }


            #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/
            
            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_VIDEO_BT_CONNECTING:
                {
                    if(!av_bt_is_inquiry())
                    {
                        av_bt_open_codec(KAL_FALSE);
                        mmi_medply_video_do_play_action();
                    }
                    else
                    {
                        g_medply.bt_success_during_inquiry = MMI_TRUE;
                    }                    
                    break;
                }

                case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
                {
                    mmi_medply_set_continue_flag(MMI_TRUE);
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
                    mmi_medply_video_open();

                    break;
                }

                case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
                {
                    if(!av_bt_is_inquiry())
                    {
                        av_bt_open_codec(KAL_FALSE);
                        mmi_medply_pure_audio_do_play_action();
                    }
                    else
                    {
                        g_medply.bt_success_during_inquiry = MMI_TRUE;
                    }                    
                    break;
                }

                case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
                {
                    if(!av_bt_is_inquiry())
                    {
                        av_bt_open_codec(KAL_TRUE);
                        mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_PLAY);
                    }
                    else
                    {
                        g_medply.bt_success_during_inquiry = MMI_TRUE;
                    }                    
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_BT_CONNECTING:
                {
                    if(!av_bt_is_inquiry())
                    {
                        av_bt_open_codec(KAL_FALSE);
                        mmi_medply_stream_do_buffer_action();
                    }
                    else
                    {
                        g_medply.bt_success_during_inquiry = MMI_TRUE;
                    }
                    break;
                }

                case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
                {
                    if(!av_bt_is_inquiry())
                    {
                        av_bt_open_codec(KAL_TRUE);
                        mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_AUDIO_PLAY);
                    }
                    else
                    {
                        g_medply.bt_success_during_inquiry = MMI_TRUE;
                    }
                    break;
                }

            #endif /*__MMI_MEDIA_PLAYER_STREAM__*/
            }
            break;
        }
                
        case AV_BT_CALLBACK_EVENT_OPEN_FAILED:
        case AV_BT_CALLBACK_EVENT_OPEN_STOPPED:
#ifdef __MMI_BT_AUDIO_VIA_SCO__
        case AV_BT_CALLBACK_EVENT_OPEN_SCO:
#endif
        {
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
                {
                    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PLAY);
                    break;
                }

                case MEDPLY_STATE_AUDIO_BT_CONNECTING:
                {
                    mmi_medply_audio_do_play_action();
                    break;
                }

                case MEDPLY_STATE_AUDIO_PLAY:
                {
                    av_bt_close_codec();
                #if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) 
                    g_medply.A2DP_blocked = MMI_FALSE;
                    #ifdef __MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__
                    mmi_medply_main_screen_play_spectrum();
                    #endif
                #endif                        
                    break;
                }


            #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_VIDEO_BT_CONNECTING:
                {
                    if(result == AV_BT_CALLBACK_EVENT_OPEN_FAILED)
                    {
                        g_medply.bt_connect_fail = MMI_TRUE;
                    }
                    mmi_medply_video_do_play_action();
                    break;
                }

                case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
                {
                    if(result == AV_BT_CALLBACK_EVENT_OPEN_FAILED)
                    {
                        g_medply.bt_connect_fail = MMI_TRUE;
                    }

                    mmi_medply_set_continue_flag(MMI_TRUE);
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
                    mmi_medply_video_open();
                    
                    break;
                }

                case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
                {
                    if(result == AV_BT_CALLBACK_EVENT_OPEN_FAILED)
                    {
                        g_medply.bt_connect_fail = MMI_TRUE;
                    }                    
                    mmi_medply_pure_audio_do_play_action();
                    break;
                }

                case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
                {
                    if(result == AV_BT_CALLBACK_EVENT_OPEN_FAILED)
                    {
                        g_medply.bt_connect_fail = MMI_TRUE;
                    }                    
                    mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_PLAY);
                    break;
                }

                case MEDPLY_STATE_PURE_AUDIO_PLAY:
                case MEDPLY_STATE_VIDEO_PLAY:
                {
                    if(result == AV_BT_CALLBACK_EVENT_OPEN_FAILED)
                    {
                        g_medply.bt_connect_fail = MMI_TRUE;
                    }                    
                    av_bt_close_codec();
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_BT_CONNECTING:
                {
                    mmi_medply_stream_do_buffer_action();
                    break;
                }

                case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
                {
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_AUDIO_PLAY);
                    break;
                }

                case MEDPLY_STATE_STREAM_PLAY:
                case MEDPLY_STATE_STREAM_AUDIO_PLAY:
                {
                    av_bt_close_codec();
                    break;
                }

            #endif /*__MMI_MEDIA_PLAYER_STREAM__*/
            }
            break;
        }

        /*this result means someone else is using mdi audio thus current playing is canceled*/
        case AV_BT_CALLBACK_EVENT_OPEN_CANCELED:
        {
            /*play state with bt connecting shall let mdi interrupt callback to handle
              and goes to interrupted state*/
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_BT_CONNECTING:
                case MEDPLY_STATE_AUDIO_BT_CONNECTING_WAIT_ACTIVATE:
                {
                    mmi_medply_audio_interrupted();
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/
            
            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_VIDEO_BT_CONNECTING:
                case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
                case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
                {
                    mmi_medply_video_interrupted();
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_BT_CONNECTING:
                {
                    mmi_medply_stream_interrupted();
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

            }
            break;
        }

        case AV_BT_CALLBACK_EVENT_STREAM_ABORT_IND:
        case AV_BT_CALLBACK_EVENT_STREAM_CLOSE_IND:
        case AV_BT_CALLBACK_EVENT_STREAM_SUSPEND_IND:
        case AV_BT_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
        {
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_BT_CONNECTING:
                {
                    mmi_medply_audio_do_play_action();
                    break;
                }

                case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
                {
                    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PLAY);
                    break;
                }

                case MEDPLY_STATE_AUDIO_PLAY:
                {
                    av_bt_close_codec();
                #if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) 
                    g_medply.A2DP_blocked = MMI_FALSE;
                    mmi_medply_main_screen_play_spectrum();
                    #endif
                    break;
                }

            #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_VIDEO_BT_CONNECTING:
                {
                    mmi_medply_video_do_play_action();
                    break;
                }

                case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
                {
                    mmi_medply_set_continue_flag(MMI_TRUE);
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
                    mmi_medply_video_open();
                    break;
                }

                case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
                {
                    mmi_medply_pure_audio_do_play_action();
                    break;
                }
                
                case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
                {
                    mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_PLAY);
                    break;
                }

                case MEDPLY_STATE_PURE_AUDIO_PLAY:
                case MEDPLY_STATE_VIDEO_PLAY:
                {
                    av_bt_close_codec();
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_BT_CONNECTING:
                {
                    mmi_medply_stream_do_buffer_action();
                    break;
                }

                case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
                {
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_AUDIO_PLAY);
                    break;
                }

                case MEDPLY_STATE_STREAM_BUFFERING:
                case MEDPLY_STATE_STREAM_PLAY:
                case MEDPLY_STATE_STREAM_AUDIO_PLAY:
                {
                    av_bt_close_codec();
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

            }
            break;
        }

        case AV_BT_CALLBACK_EVENT_STREAM_START_IND:
        {
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY:
                {
                    /*change state first since av_bt might callback success immediately*/
                    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING);

                    av_bt_open(mmi_medply_settings_get_bt_headset(), g_medply.filefullpath, 
                            mmi_medply_bt_open_callback, (kal_bool)(!mmi_medply_settings_is_audio_speed_normal()),
                            KAL_TRUE);

                    break;  
                }


                /* some earphone will send start ind right after avrcp play command, if we av_bt_close the start id
                   the bt_connecting will never have chance to go to next state for no bt callback*/
                case MEDPLY_STATE_AUDIO_BT_CONNECTING:
                case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
                {
                    break;
                }
            
            #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_PURE_AUDIO_PLAY:
                {
                    mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING);

                    av_bt_open(
                        mmi_medply_settings_get_bt_headset(), g_medply.filefullpath,
                        mmi_medply_bt_open_callback, KAL_TRUE,KAL_TRUE);
                    break;
                }

                case MEDPLY_STATE_VIDEO_PLAY:
                {
                    /*do not accept start stream currently, need to add state to handle this*/
                    av_bt_close(KAL_FALSE);
                    break;
                }

                case MEDPLY_STATE_VIDEO_BT_CONNECTING:
                case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
                case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
                case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
                {
                    break;
                }

            #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_PLAY:
                {
                    /*do not accept start stream currently*/
                    av_bt_close(KAL_FALSE);                    
                    break;
                }

                case MEDPLY_STATE_STREAM_AUDIO_PLAY:
                {
                    MMI_BOOL is_stereo;
                    
                    if (g_medply.aud_channel_no == 2)
                    {
                        is_stereo = MMI_TRUE;
                    }
                    else
                    {
                        is_stereo = MMI_FALSE;
                    }

                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING);

                    av_bt_open_ex(
                        mmi_medply_settings_get_bt_headset(),
                        g_medply.aud_sample_rate,
                        (kal_bool)is_stereo,
                        mmi_medply_bt_open_callback,
                        KAL_TRUE);                    
                    break;
                }

                case MEDPLY_STATE_STREAM_BT_CONNECTING:
                case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
                {
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

                default:
                {
                    av_bt_close(KAL_FALSE);
                    break;
                }
            }
            
            break;
        }

        case AV_BT_CALLBACK_EVENT_INQUIRY_START_IND:
        {
            /*since this flag only works for inquiry period, reset it while receive inquiry ind*/
            g_medply.bt_success_during_inquiry = MMI_FALSE;

            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY:
                {
                    if(mmi_medply_settings_is_output_to_bt() && av_bt_is_streaming())
                    {
                        mmi_medply_audio_seek_stop();
                        mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
                        g_medply.inquiry_paused = MMI_TRUE;
                    }
                    break;
                }

            #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_PURE_AUDIO_PLAY:
                {
                    if(mmi_medply_settings_is_output_to_bt() && av_bt_is_streaming())
                    {
                        mmi_medply_set_self_stop_flag(MMI_TRUE);
                        
                        mdi_audio_stop_file();
                        
                        mmi_medply_set_self_stop_flag(MMI_FALSE);
        
                    #ifdef __MMI_A2DP_SUPPORT__
                        mmi_medply_bt_stop(MMI_FALSE);
                    #endif
                        mmi_medply_set_continue_flag(MMI_FALSE);
                        mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);

                        g_medply.inquiry_paused = MMI_TRUE;
                    }
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_AUDIO_PLAY:
                {
                    if(mmi_medply_settings_is_output_to_bt() && av_bt_is_streaming())
                    {   
                        mdi_video_stream_stop();
        
                    #ifdef __MMI_A2DP_SUPPORT__
                        mmi_medply_bt_stop(MMI_FALSE);
                    #endif

                        if(g_medply.seekable)
                        {
                            mmi_medply_set_continue_flag(MMI_FALSE);
                            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_CONNECTED);
                        }
                        else
                        {
                            mdi_video_stream_disconnect();
                            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
                        }

                        g_medply.inquiry_paused = MMI_TRUE;
                    }                            
                    break;
                }
                
            #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

            }
            break;
        }

        case AV_BT_CALLBACK_EVENT_INQUIRY_STOP_IND:
        {
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
                case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING_WAIT_ACTIVATE:
                {
                    if(g_medply.bt_success_during_inquiry)
                    {
                        g_medply.bt_success_during_inquiry = MMI_FALSE;
                        av_bt_open_codec(KAL_TRUE);

                    #if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) 
                    {
                        g_medply.A2DP_blocked = MMI_TRUE;
                        mmi_medply_main_screen_stop_spectrum();
                    }
                    #endif

                    }
                    break;
                }

                case MEDPLY_STATE_AUDIO_BT_CONNECTING:
                case MEDPLY_STATE_AUDIO_BT_CONNECTING_WAIT_ACTIVATE:
                {
                    if(g_medply.bt_success_during_inquiry)
                    {
                        g_medply.bt_success_during_inquiry = MMI_FALSE;
                        av_bt_open_codec(KAL_FALSE);
                    #if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) 
                        g_medply.A2DP_blocked = MMI_TRUE;
                    #endif
                        mmi_medply_audio_do_play_action();
                    }
                    break;
                }

                case MEDPLY_STATE_AUDIO_READY:
                case MEDPLY_STATE_AUDIO_WAIT_ACTIVATE:
                {
                    if(g_medply.inquiry_paused)
                    {
                        g_medply.inquiry_paused = MMI_FALSE;
                        mmi_medply_audio_play();
                    }
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
                {
                    if(g_medply.bt_success_during_inquiry)
                    {
                        g_medply.bt_success_during_inquiry = MMI_FALSE;
                        av_bt_open_codec(KAL_TRUE);
                    }
                    break;
                }
                
                case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
                {
                    if(g_medply.bt_success_during_inquiry)
                    {
                        g_medply.bt_success_during_inquiry = MMI_FALSE;
                        av_bt_open_codec(KAL_FALSE);
                        mmi_medply_pure_audio_do_play_action();
                    }
                    break;
                }
                
                case MEDPLY_STATE_VIDEO_BT_CONNECTING:
                {
                    if(g_medply.bt_success_during_inquiry)
                    {
                        g_medply.bt_success_during_inquiry = MMI_FALSE;
                        av_bt_open_codec(KAL_FALSE);
                        mmi_medply_video_do_play_action();
                    }
                    break;
                }
                    
                case MEDPLY_STATE_PURE_AUDIO_READY:
                {
                    if(g_medply.inquiry_paused)
                    {
                        g_medply.inquiry_paused = MMI_FALSE;
                        mmi_medply_video_play();
                    }
                    break;
                }

            #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/
            
            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_BT_CONNECTING:
                {
                    if(g_medply.bt_success_during_inquiry)
                    {
                        g_medply.bt_success_during_inquiry = MMI_FALSE;                    
                        av_bt_open_codec(KAL_FALSE);
                        mmi_medply_stream_do_buffer_action();
                    }
                    break;
                }

                case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
                {
                    if(g_medply.bt_success_during_inquiry)
                    {
                        g_medply.bt_success_during_inquiry = MMI_FALSE;                
                        av_bt_open_codec(KAL_TRUE);
                    }
                    break;                    
                }

                case MEDPLY_STATE_STREAM_CONNECTED:
                {
                    if(g_medply.inquiry_paused)
                    {
                       g_medply.inquiry_paused = MMI_FALSE;
                       mmi_medply_stream_buffer();

                    }
                    break;
                }

                case MEDPLY_STATE_STREAM_INITED:
                {
                    if(g_medply.inquiry_paused)
                    {
                        g_medply.inquiry_paused = MMI_FALSE;
                        mmi_medply_stream_connect();
                    }
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

            }
            break;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_BT_OPEN_CALLBACK_OUT,g_medply.inquiry_paused, g_medply.bt_success_during_inquiry);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bt_stop
 * DESCRIPTION
 *  close codec and suspend a2dp steraming
 * PARAMETERS
 *  notify_opener   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_bt_stop(MMI_BOOL notify_opener)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_BT_STOP, notify_opener);

    if( mmi_medply_settings_is_output_to_bt() )
    {
        av_bt_close_codec();
    #if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) 
        g_medply.A2DP_blocked = MMI_FALSE;
        #ifdef __MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__
        mmi_medply_main_screen_play_spectrum();
        #endif
    #endif
        av_bt_close(notify_opener);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_turn_off_bt_output
 * DESCRIPTION
 *  handle bt output turn off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_turn_off_bt_output(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_TURN_OFF_BT_OUTPUT, g_medply.state);

    switch(g_medply.state)
    {
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__        
        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        {
            av_bt_close(KAL_TRUE);
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_AUDIO_PLAY:
        {
            av_bt_close_codec();
        #if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__)
            g_medply.A2DP_blocked = MMI_FALSE;
            #ifdef __MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__
            mmi_medply_main_screen_play_spectrum();
            #endif
        #endif

            av_bt_close(KAL_TRUE);
            break;
        }
    #endif
    
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        {
            av_bt_close(KAL_TRUE);
            break;
        }

        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
        {
            av_bt_close_codec();
            av_bt_close(KAL_TRUE);
            break;
        }
    #endif

    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_BT_CONNECTING:
        {
            av_bt_close(KAL_TRUE);
            break;
        }
        case MEDPLY_STATE_STREAM_BUFFERING:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
        {
            av_bt_close_codec();                
            av_bt_close(KAL_TRUE);
            break;
        }
    #endif

    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_switch_bt_output
 * DESCRIPTION
 *  handle bt output swith on/off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_switch_bt_output(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_SWITCH_BT_OUTPUT, g_medply.state);

    if (mmi_medply_settings_is_output_to_bt())
    {
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        g_medply.bt_connect_fail = MMI_FALSE;
    #endif

        /* switch output: OFF -> ON */
        switch(g_medply.state)
        {
        #ifdef __MMI_MEDIA_PLAYER_AUDIO__
            case MEDPLY_STATE_AUDIO_PLAY:
            {
                mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING);

                av_bt_open(mmi_medply_settings_get_bt_headset(), g_medply.filefullpath,
                    mmi_medply_bt_open_callback, (kal_bool)(!mmi_medply_settings_is_audio_speed_normal()),
                    KAL_TRUE
                    );
                break;
            }
        #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

        #ifdef __MMI_MEDIA_PLAYER_VIDEO__
            case MEDPLY_STATE_PURE_AUDIO_PLAY:
            {
                mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING);

                av_bt_open(
                     mmi_medply_settings_get_bt_headset(), g_medply.filefullpath,
                     mmi_medply_bt_open_callback, KAL_TRUE,KAL_TRUE);

                break;
            }
        #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

        #ifdef __MMI_MEDIA_PLAYER_STREAM__
            case MEDPLY_STATE_STREAM_BUFFERING:
            {
                MMI_BOOL is_stereo;

                StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
                mdi_video_stream_stop_buffering();

                if (g_medply.aud_channel_no == 2)
                {
                    is_stereo = MMI_TRUE;
                }
                else
                {
                    is_stereo = MMI_FALSE;
                }

                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_BT_CONNECTING);

                av_bt_open_ex(mmi_medply_settings_get_bt_headset(),g_medply.aud_sample_rate,
                    (kal_bool)is_stereo,mmi_medply_bt_open_callback,
                    KAL_TRUE);

                break;
            }
            case MEDPLY_STATE_STREAM_AUDIO_PLAY:
            {
                MMI_BOOL is_stereo;

                if (g_medply.aud_channel_no == 2)
                {
                    is_stereo = MMI_TRUE;
                }
                else
                {
                    is_stereo = MMI_FALSE;
                }
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING);

                av_bt_open_ex(mmi_medply_settings_get_bt_headset(),g_medply.aud_sample_rate,
                    (kal_bool)is_stereo,mmi_medply_bt_open_callback,
                    KAL_TRUE);
                break;
            }
        #endif

        }

    }
    else
    {
        /* switch output: ON -> OFF */
        switch(g_medply.state)
        {
        #ifdef __MMI_MEDIA_PLAYER_AUDIO__        
            case MEDPLY_STATE_AUDIO_BT_CONNECTING:
            {
                av_bt_close(KAL_TRUE);
                break;
            }

            case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
            case MEDPLY_STATE_AUDIO_PLAY:
            {
                av_bt_close_codec();
            #if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) 
                g_medply.A2DP_blocked = MMI_FALSE;
                #ifdef __MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__
                mmi_medply_main_screen_play_spectrum();
                #endif
            #endif

                av_bt_close(KAL_TRUE);
                break;
            }
        #endif
        
        #ifdef __MMI_MEDIA_PLAYER_VIDEO__
            case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
            {
                av_bt_close(KAL_TRUE);
                break;
            }

            case MEDPLY_STATE_PURE_AUDIO_PLAY:
            case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
            {
                av_bt_close_codec();
                av_bt_close(KAL_TRUE);
                break;
            }
        #endif

        #ifdef __MMI_MEDIA_PLAYER_STREAM__
            case MEDPLY_STATE_STREAM_BT_CONNECTING:
            {
                av_bt_close(KAL_TRUE);
                break;
            }
            case MEDPLY_STATE_STREAM_BUFFERING:
            case MEDPLY_STATE_STREAM_AUDIO_PLAY:
            case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
            {
                av_bt_close_codec();                
                av_bt_close(KAL_TRUE);
                break;
            }
        #endif

        }

    }



}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_sync_bt_output
 * DESCRIPTION
 *  handle bt earphone change or speed change
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_sync_bt_output(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_SYNC_BT_OUTPUT, g_medply.state);
    
    MMI_ASSERT( mmi_medply_settings_is_output_to_bt() );

    switch(g_medply.state)
    {
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_PLAY:
        {
            if(g_medply.is_audio_seekable)
            {
                mmi_medply_audio_pause();
            }
            else
            {
                mmi_medply_audio_stop_for_not_seekable_file();
            }

            mmi_medply_audio_play();
            break;
        }

        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:            
        {
            mmi_medply_bt_stop(MMI_FALSE);
            av_bt_open(mmi_medply_settings_get_bt_headset(), g_medply.filefullpath,
                mmi_medply_bt_open_callback, (kal_bool)(!mmi_medply_settings_is_audio_speed_normal()),
                KAL_TRUE);
            break;
        }
    #endif

    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        {
            mmi_medply_video_pause();
            mmi_medply_video_play();
            break;
        }

        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:            
        {
            mmi_medply_bt_stop(MMI_FALSE);

            av_bt_open(
                 mmi_medply_settings_get_bt_headset(), g_medply.filefullpath,
                 mmi_medply_bt_open_callback, KAL_TRUE,KAL_TRUE);
            break;
        }
    #endif
    
    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        {
            mmi_medply_stream_pause();
            mmi_medply_stream_connect();
            break;
        }

        case MEDPLY_STATE_STREAM_BT_CONNECTING:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:            
        {
            MMI_BOOL is_stereo;

            mmi_medply_bt_stop(MMI_FALSE);  

            if (g_medply.aud_channel_no == 2)
            {
                is_stereo = MMI_TRUE;
            }
            else
            {
                is_stereo = MMI_FALSE;
            }
            
            av_bt_open_ex(mmi_medply_settings_get_bt_headset(),g_medply.aud_sample_rate,
                (kal_bool)is_stereo,mmi_medply_bt_open_callback,
                KAL_TRUE);
            break;            
        }
    #endif
    
        default:
            break;
    }


}

#ifdef __MMI_AUDIO_TIME_STRETCH__

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bt_sync_speed
 * DESCRIPTION
 *  handle bt sync issue when user change audio speed in settings
 *  sync bt again if it is currently mp3 streaming
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_bt_sync_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_BT_SYNC_SPEED);

    if (g_medply.state != MEDPLY_STATE_AUDIO_PLAY  && g_medply.state != MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING)
    {
        return;
    }

    /* check if need to reopen av bt */
    if (mmi_medply_settings_is_output_to_bt() && av_bt_is_mp3_cfg())
    {
        mmi_medply_sync_bt_output();
    }
}

#endif /*__MMI_AUDIO_TIME_STRETCH__*/

#endif /* __MMI_A2DP_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_pop_up_proc
 * DESCRIPTION
 *  pop up proc
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_medply_pop_up_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *popup_info = ((mmi_event_popoupcallback_result_struct*)param)->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(param->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {
            mmi_frm_group_close(GRP_ID_MEDPLY_POPUP);

            if (MMI_POPUP_NORMAL_EXIT ==((mmi_event_popoupcallback_result_struct*)param)->result)
            {
                mmi_medply_pop_up_wait_next_callback();

                if(g_medply.apply_result < 0)
                {
                    StartTimer(MEDPLY_DELAY_PLST_POPUP_TIMER, 50, mmi_medply_completed_delay_list_popup);
                }
            }
            else if(MMI_POPUP_INTERRUPT_EXIT == ((mmi_event_popoupcallback_result_struct*)param)->result)
            {
                mmi_medply_pop_up_start_wait_next_timer();

                if(g_medply.apply_result < 0)
                {
                   g_medply.apply_result = 0; 
                }

            }
            else if(MMI_ALERT_NO_SHOW == ((mmi_event_popoupcallback_result_struct*)param)->result)
            {
                if (NULL != popup_info)
                {
                    mmi_medply_display_popup_with_sg(
                                ((mmi_medply_popup_info_struct*)popup_info)->str_id,
                                (mmi_event_notify_enum)((mmi_medply_popup_info_struct*)popup_info)->event_id);

                }
            }
            else
            {
                /*should not happen*/
            }

            if (NULL != popup_info)
            {
                free_ctrl_buffer(popup_info);
            }
            break;
        }
        default:
            break;
    }    
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_display_popup_with_sg
 * DESCRIPTION
 *  media player might pop up in background, create group and display popup.
 * PARAMETERS
 *  string_id       [IN]
 *  event_id        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_display_popup_with_sg(U16 string_id, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MEDPLY_POPUP, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_MEDPLY_POPUP,MMI_FRM_NODE_NONE_FLAG);

    mmi_popup_property_init(&arg);
    arg.callback = mmi_medply_pop_up_proc;
    arg.parent_id = GRP_ID_MEDPLY_POPUP;
    /* MAUI_02222230 */
    arg.user_tag = (void*)get_ctrl_buffer(sizeof(mmi_medply_popup_info_struct));
    ((mmi_medply_popup_info_struct*)arg.user_tag)->str_id = string_id;
    ((mmi_medply_popup_info_struct*)arg.user_tag)->event_id = (U32)event_id;

    mmi_popup_display((WCHAR*)GetString(string_id), event_id, &arg);
    mmi_frm_ui_force_update_now();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_display_popup_for_all_file_fail
 * DESCRIPTION
 *  call display pop up for play list all file fail case
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_display_popup_for_all_file_fail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple((WCHAR*)GetString(STR_ID_MEDPLY_PLAY_ALL_FAIL), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    mmi_frm_ui_force_update_now();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_display_popup
 * DESCRIPTION
 *  call display pop up with corresponding parameter for the result
 * PARAMETERS
 *  result  [IN]
 *  wait_next_callback  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_display_popup(MDI_RESULT result, MMI_BOOL wait_next_callback)//, mmi_medply_err_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum result_type;
    MMI_ID_TYPE mdi_string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_POP_UP, wait_next_callback, result);

    mdi_string = mdi_util_get_mdi_error_info(result,&result_type);

#ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
    if(g_single.intro_play)
    {
        mmi_popup_property_struct popup_args;
    
        mmi_popup_property_init(&popup_args);
        popup_args.parent_id = GRP_ID_MEDPLY_SINGLE;
        popup_args.callback = mmi_medply_single_audio_play_popup_callback;

        mmi_popup_display((WCHAR*)GetString(mdi_string), result_type, &popup_args);
        mmi_frm_ui_force_update_now();
        return;
    }
#endif /*__MMI_MEDIA_PLAYER_INTRO_PLAY__*/


    if(wait_next_callback)
    {
        mmi_medply_display_popup_with_sg(mdi_string, result_type);
    }
    else
    {
        mmi_popup_display_simple((WCHAR*)GetString(mdi_string), result_type, GRP_ID_ROOT, NULL);
    }
    mmi_frm_ui_force_update_now();
}

#endif /* __MMI_MEDIA_PLAYER__ */ 
