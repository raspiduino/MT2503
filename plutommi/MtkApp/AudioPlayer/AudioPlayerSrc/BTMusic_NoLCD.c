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
*  BTMusic_NoLCD.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   BTMusic NoLCD
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"
#include "BTMusicNoLCDProt.h"

#ifdef __MMI_BT_MUSIC_NOLCD__
#include "globalresdef.h"
#include "gui_typedef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_softkeys.h"
#include "wgui_draw_manager.h"
#include "gpiosrvgprot.h"
#include "mdi_audio.h"
#include "BootupSrvGprot.h"

#include "mmi_rp_app_bt_music_nolcd_def.h"
#include "wgui_categories_btbox.h"
#include "ProfilesSrvGprot.h"
#include "mmi_frm_input_event.h"
#include "BTMMIAVRCPGProt.h"
#include "BtcmSrvGprot.h"
#include "A2dpSrvGprot.h"
#ifdef __MMI_AVRCP_SUPPORT__
#include "AvrcpSrvGprot.h"
#endif
#ifdef __MMI_BT_CALL_SUPPORT__
#include "UcmGProtBT.h"
#endif /* __MMI_BT_CALL_SUPPORT__ */
#include "bluetooth_a2dp_struct.h"
#ifdef __MMI_BT_BTBOX_NOLCD__
#include "BTMMIScrGprots.h"
#endif

#ifdef __MMI_BT_DIALER_SUPPORT__
#include "mmi_rp_app_ucmbt_def.h"
#endif

static mmi_bt_music_nolcd_context_struct g_btmusic_nolcd_cntx;
kal_bool g_is_wait_for_notify=MMI_TRUE;
kal_bool g_pause_btmusic_for_notify=MMI_FALSE;
#ifdef __KARAOKE_SUPPORT__
#define BT_MUSIC_KARAOKE_SWITCH_DURATION (300)
#endif

MMI_BOOL mmi_bt_music_nolcd_is_active(void);
mmi_ret mmi_bt_music_nolcd_proc(mmi_event_struct *event);
static void mmi_bt_music_nolcd_play_pause(void);
srv_bt_cm_bt_addr *mmi_bt_music_nolcd_get_dev_addr_by_role(U8 r);
srv_bt_cm_bt_addr *mmi_bt_music_nolcd_get_second_addr(srv_bt_cm_bt_addr *first_addr);


#ifdef __MMI_AVRCP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_send_ct_avrcp_cmd
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_nolcd_send_ct_avrcp_cmd(S32 cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_dialer;
    srv_bt_cm_bt_addr *ct_addr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ct_addr = mmi_bt_music_nolcd_get_dev_addr_by_role(A2DP_ROLE_SOURCE);
    
    if(!ct_addr)
    {
        return;
    }
    
    is_dialer = srv_bt_cm_is_bt_dialer(ct_addr);
    
    if(is_dialer)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_SEND_CT_AVRCP_CMD, cmd); 
        srv_avrcp_send_cmd_frame(ct_addr, cmd);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_send_avrcp_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_nolcd_send_avrcp_cmd(S32 cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_SEND_AVRCP_CMD, cmd);
    srv_avrcp_send_cmd_frame(g_btmusic_nolcd_cntx.bt_address, cmd);
    mmi_bt_music_nolcd_send_ct_avrcp_cmd(cmd);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_check_profile
 * DESCRIPTION
 *  check music player releated profiles: A2DP and AVRCP_CT
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_music_nolcd_check_profile(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL /*AVRCP_connc, */ A2DP_connc;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_bt_cm_addr_is_nul(dev_addr))
		return MMI_FALSE;
    A2DP_connc = srv_a2dp_is_connected_ex(dev_addr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_CHECK_A2DP_CONN, A2DP_connc);
    //AVRCP_connc = srv_avrcp_is_avrcp_connected(dev_addr);
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_AVRCP_PROFILE, AVRCP_connc);
    
    //return (AVRCP_connc && A2DP_connc);
    return (A2DP_connc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_get_dev_addr_by_role
 * DESCRIPTION
 *  
 * PARAMETERS
 *  role       [IN]                
 * RETURNS
 *  void
 *****************************************************************************/
srv_bt_cm_bt_addr *mmi_bt_music_nolcd_get_dev_addr_by_role(U8 r)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *list_item_p;
    U32 i, link_dev_num;
    U8 role;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    link_dev_num = srv_bt_cm_get_linked_dev_list_idx();

    for(i = 0; i<link_dev_num; i++)
    {
        list_item_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(i);
        role = srv_a2dp_get_role(&(list_item_p->bd_addr));
        
        if(role == r)
        {
        
            MMI_TRACE(
                MMI_MEDIA_TRC_G2_APP,
                MMI_BT_MUSIC_NOLCD_GET_ADDR_BY_ROLE,
                r,
                list_item_p->bd_addr.lap,
                list_item_p->bd_addr.nap,
                list_item_p->bd_addr.uap); 
            
            return &(list_item_p->bd_addr);
        }
    }
    
    return NULL;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_get_second_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  role       [IN]                
 * RETURNS
 *  void
 *****************************************************************************/
srv_bt_cm_bt_addr *mmi_bt_music_nolcd_get_second_addr(srv_bt_cm_bt_addr *first_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *p;
    U32 i, link_dev_num;
    srv_bt_cm_bt_addr *second_addr;
    MMI_BOOL is_equal;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    link_dev_num = srv_bt_cm_get_linked_dev_list_idx();

    for(i = 0; i<link_dev_num; i++)
    {
        p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(i);
        second_addr = &(p->bd_addr);

        is_equal = srv_bt_cm_is_dev_addr_equal((const srv_bt_cm_bt_addr*)second_addr, (const srv_bt_cm_bt_addr*)first_addr);
        
        if(second_addr && !is_equal)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_GET_SECOND_ADDR); 
            return second_addr;
        }
    }
    
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_is_sink_streaming
 * DESCRIPTION
 *  check device streaming state, the device role is "SRC"
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
MMI_BOOL mmi_bt_music_nolcd_is_sink_streaming(void)
{
    MMI_BOOL is_streaming = MMI_FALSE;
	srv_bt_cm_bt_addr *temp_bt_addr;

    is_streaming = srv_a2dp_is_streaming_ex(g_btmusic_nolcd_cntx.bt_address);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_IS_STREAMING, is_streaming);
	if(is_streaming)
		return MMI_TRUE;

	temp_bt_addr = mmi_bt_music_nolcd_get_second_addr(g_btmusic_nolcd_cntx.bt_address);
	if(A2DP_ROLE_SINK != srv_a2dp_get_role(temp_bt_addr)) //if 2th device is not Source, we should not be in sink streaming
		return MMI_FALSE;

	is_streaming = srv_a2dp_is_streaming_ex(temp_bt_addr);
	if(is_streaming)
	{
	    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_IS_STREAMING, MMI_TRUE);
	    g_btmusic_nolcd_cntx.bt_address = temp_bt_addr;
		return MMI_TRUE;
	}

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_IS_STREAMING, MMI_FALSE);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_is_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_music_nolcd_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_IS_ACTIVE, (MMI_BOOL)(mmi_frm_group_get_active_id() == GRP_ID_BT_MUSIC_NOLCD));
    if (mmi_frm_group_get_active_id() == GRP_ID_BT_MUSIC_NOLCD)
        return MMI_TRUE;

    return MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_is_playing_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_music_nolcd_is_playing_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_IS_ACTIVE, (MMI_BOOL)(mmi_frm_group_get_active_id() == GRP_ID_BT_MUSIC_NOLCD));
    if (mmi_frm_group_get_active_id() == GRP_ID_BT_MUSIC_NOLCD)
        return g_is_wait_for_notify;

    return MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_is_wait_for_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: Wait for notify
 *  MMI_FALSE: No need Wait for notify
 *****************************************************************************/
MMI_BOOL mmi_bt_music_nolcd_is_wait_for_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_IS_WAIT_NOTIFY,g_is_wait_for_notify);
    return g_is_wait_for_notify;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_init_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_music_nolcd_init_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_INIT_VOL);
	if(g_is_wait_for_notify)
		return;
	
	ReadValueSlim(NVRAM_BT_MUSIC_NOLCD_VOL, &g_btmusic_nolcd_cntx.volume, DS_BYTE);
    if (g_btmusic_nolcd_cntx.volume < MDI_BT_MUSIC_NOLCD_VOL_MUTE_MIN || g_btmusic_nolcd_cntx.volume > MDI_BT_MUSIC_NOLCD_VOL_MUTE_MAX)
    {
        g_btmusic_nolcd_cntx.volume = MDI_BT_MUSIC_NOLCD_DEFAULT_VOL;
        WriteValueSlim(NVRAM_BT_MUSIC_NOLCD_VOL, &g_btmusic_nolcd_cntx.volume, DS_BYTE);
    }
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(g_btmusic_nolcd_cntx.volume)));  
	if(g_btmusic_nolcd_cntx.volume == MDI_BT_MUSIC_NOLCD_VOL_MUTE_MIN)
        mmi_frm_input_event_notify(INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_MUTE, NULL);
}


void mmi_bt_music_nolcd_A2DP_cb(srv_bt_cm_bt_addr *address, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_a2dp_callback_event_enum event = (srv_a2dp_callback_event_enum)result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_A2DP_CB, event);
	
    switch(event)
    {
        case SRV_A2DP_CALLBACK_EVENT_STREAM_SUSPEND_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND:
		case SRV_A2DP_CALLBACK_EVENT_STREAM_PAUSE_IND:
        {
			if(srv_bt_cm_is_dev_addr_equal((const srv_bt_cm_bt_addr*)address, (const srv_bt_cm_bt_addr*)g_btmusic_nolcd_cntx.bt_address))
			    g_btmusic_nolcd_cntx.is_playing = MMI_FALSE;
            break;
        }
        case SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
        {
            break;
        }
        case SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND:
        {
            if(mmi_bt_music_nolcd_is_active() && (A2DP_ROLE_SINK == srv_a2dp_get_role(address)))
            {
				g_btmusic_nolcd_cntx.bt_address = address;
				srv_a2dp_sink_set_callback_notifier(g_btmusic_nolcd_cntx.bt_address,(A2DP_SRV_CALLBACK)mmi_bt_music_nolcd_A2DP_cb);
				
				mmi_bt_music_nolcd_init_volume();
				g_btmusic_nolcd_cntx.is_playing = MMI_TRUE;
            }
            break;
        }
        default:
            break;
    }
}

#ifdef __KARAOKE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_is_karaoke_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_music_nolcd_is_karaoke_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_IS_KARAOKE_ENABLE, g_btmusic_nolcd_cntx.is_karaoke_enable);
    return g_btmusic_nolcd_cntx.is_karaoke_enable;    
}
#endif /*#ifdef __KARAOKE_SUPPORT__*/



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_notify_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static srv_prof_ret mmi_bt_music_nolcd_notify_callback_hdlr(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_TRC_NOTIFY_CALLBACK, result,g_pause_btmusic_for_notify);

	if(!mmi_bt_music_nolcd_is_active())
	{
	    if(!mmi_frm_group_is_present(GRP_ID_BT_MUSIC_NOLCD))
	    {
			g_pause_btmusic_for_notify = MMI_FALSE;
			#ifdef __KARAOKE_SUPPORT__
			g_btmusic_nolcd_cntx.is_karaoke_enable = MMI_FALSE;
			g_btmusic_nolcd_cntx.is_original_enable = MMI_FALSE;
			#endif
	    }
		return 0;
	}
	g_is_wait_for_notify = MMI_FALSE;
	#ifdef __KARAOKE_SUPPORT__
	if(g_btmusic_nolcd_cntx.is_karaoke_enable)
	{
	   mmi_input_event_notify_param param = {0};
       mmi_frm_input_event_notify(BTBOX_BT_MUSIC_NOLCD_KARAOKE_NO_AUD,&param);
       mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_PLAY_MIX_ONLY,NULL);
	   if(g_btmusic_nolcd_cntx.is_original_enable)
	   	   mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_RIGHT);
	   else
           mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_LEFT);
	}
	#endif /*#ifdef __KARAOKE_SUPPORT__*/
	
    if (g_pause_btmusic_for_notify)
    {
        g_btmusic_nolcd_cntx.is_playing = MMI_FALSE;
        mmi_bt_music_nolcd_play_pause();
        if(mmi_bt_music_nolcd_is_sink_streaming())
        {
            kal_uint8 stream_handle=0;
            if(!srv_a2dp_sink_is_codec_open())
				srv_a2dp_open_codec(MMI_TRUE);

			stream_handle = srv_a2dp_get_stream_handle(g_btmusic_nolcd_cntx.bt_address);
			mmi_a2dp_stream_start_codec_req(stream_handle);
		}
		g_pause_btmusic_for_notify = MMI_FALSE;
    }
    else
    {
        mdi_audio_resume_background_play();
    }
	
    mmi_bt_music_nolcd_init_volume();
    return 0;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_resume_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
BOOL mmi_bt_music_nolcd_resume_callback(S32 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_RESUME, result,g_btmusic_nolcd_cntx.is_interrupted);
	if((result == MDI_AUDIO_RESUME) && (mmi_bt_music_nolcd_is_active()))
    {
        if(g_btmusic_nolcd_cntx.is_interrupted)
        {
            #ifdef __MMI_AVRCP_SUPPORT__
			mmi_bt_music_nolcd_send_avrcp_cmd(SRV_AVRCP_POP_PLAY);
            #endif
            g_btmusic_nolcd_cntx.is_interrupted = MMI_FALSE;
        }
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_BT_MUSIC);
		mmi_bt_music_nolcd_init_volume();
    }
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_interrupt_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_bt_music_nolcd_interrupt_callback(S32 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_INTERRUPT, result,mmi_bt_music_nolcd_is_sink_streaming());
	mdi_audio_clear_interrupt_callback();
	if((result == MDI_AUDIO_TERMINATED) && (mmi_bt_music_nolcd_is_sink_streaming() == MMI_TRUE))
    {
	    srv_a2dp_sink_avrcp_interface(SRV_A2DP_SINK_TERMINATED);
	    mdi_audio_set_background_handler(MDI_BACKGROUND_APP_BT_MUSIC, mmi_bt_music_nolcd_resume_callback,NULL);
	    mdi_audio_clear_other_background_handler(MDI_BACKGROUND_APP_BT_MUSIC);
		g_btmusic_nolcd_cntx.is_interrupted = MMI_TRUE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_switch_src
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_switch_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_bt_addr *temp_bt_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_SWITCH_SRC);
    if (mmi_bt_music_nolcd_is_active())
    {
		temp_bt_addr = mmi_bt_music_nolcd_get_second_addr(g_btmusic_nolcd_cntx.bt_address);
		srv_a2dp_sink_set_callback_notifier(g_btmusic_nolcd_cntx.bt_address,(A2DP_SRV_CALLBACK)mmi_bt_music_nolcd_A2DP_cb);
		if(mmi_bt_music_nolcd_check_profile(temp_bt_addr) &&
			(A2DP_ROLE_SINK == srv_a2dp_get_role(temp_bt_addr)))
		{
		    /* If Current SP is playing, pause it first, then update BT addr */
		    if(srv_a2dp_is_streaming_ex(g_btmusic_nolcd_cntx.bt_address)) 
		    {
		        #ifdef __MMI_AVRCP_SUPPORT__
				mmi_bt_music_nolcd_send_avrcp_cmd(SRV_AVRCP_POP_PAUSE);
		        #endif        
				g_btmusic_nolcd_cntx.is_playing = MMI_FALSE;
			}
			g_btmusic_nolcd_cntx.bt_address = temp_bt_addr;
			srv_a2dp_sink_set_callback_notifier(g_btmusic_nolcd_cntx.bt_address,(A2DP_SRV_CALLBACK)mmi_bt_music_nolcd_A2DP_cb);
		}
		else
		{
		    /* If another BT device has not connect A2DP or to another BT device's role is not SINK, do nothing*/
		}
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_bt_music_nolcd_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_bt_addr *temp_bt_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_LAUNCH, mmi_bt_music_nolcd_is_active(),srv_a2dp_is_connected(),1);
	if(!srv_a2dp_is_connected())
	{
		//return; //if A2DP not connected, do not launch BT Music
	}
	
    if (!mmi_frm_group_is_present(GRP_ID_BT_MUSIC_NOLCD))
    {
        temp_bt_addr = mmi_bt_music_nolcd_get_dev_addr_by_role(A2DP_ROLE_SINK);
		if(!temp_bt_addr)
			return MMI_RET_OK;
		else
		{
            g_btmusic_nolcd_cntx.bt_address = temp_bt_addr;
		}
#ifdef __MMI_BT_DIALER_SUPPORT__
		if(mmi_frm_group_is_present(GRP_ID_UCM_BT_MO) ||
			mmi_frm_group_is_present(GRP_ID_UCM_BT_MT) ||
			mmi_frm_group_is_present(GRP_ID_UCM_BT_INCALL) ||
			mmi_frm_group_is_present(GRP_ID_UCM_BT_CALL_END)
			)
		{
		    MMI_ID curr_call_sg_id = mmi_frm_group_get_active_id();

            mmi_frm_node_struct * new_node_info = NULL;
			g_btmusic_nolcd_cntx.group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BT_MUSIC_NOLCD, mmi_bt_music_nolcd_proc, NULL);
            new_node_info = OslMalloc(sizeof(mmi_frm_node_struct));
            new_node_info->id = GRP_ID_BT_MUSIC_NOLCD;
            new_node_info->entry_proc = mmi_bt_music_nolcd_proc;
            new_node_info->user_data = NULL;
            mmi_frm_group_insert(GRP_ID_ROOT, curr_call_sg_id, new_node_info, MMI_FRM_NODE_NONE_FLAG);
			OslMfree(new_node_info);
		}
		else
#endif
            g_btmusic_nolcd_cntx.group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_BT_MUSIC_NOLCD, mmi_bt_music_nolcd_proc, NULL, NULL);
        MMI_ASSERT(g_btmusic_nolcd_cntx.group_id != GRP_ID_INVALID);
    }    
	srv_a2dp_sink_set_callback_notifier(g_btmusic_nolcd_cntx.bt_address,(A2DP_SRV_CALLBACK)mmi_bt_music_nolcd_A2DP_cb);
	temp_bt_addr = mmi_bt_music_nolcd_get_second_addr(g_btmusic_nolcd_cntx.bt_address);
	if(temp_bt_addr && (A2DP_ROLE_SINK == srv_a2dp_get_role(temp_bt_addr)))
        srv_a2dp_sink_set_callback_notifier(temp_bt_addr,(A2DP_SRV_CALLBACK)mmi_bt_music_nolcd_A2DP_cb);
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_delaunch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_bt_music_nolcd_delaunch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_DELAUNCH, mmi_bt_music_nolcd_is_active(),srv_a2dp_is_connected());
	if(srv_a2dp_is_connected())
	{
	    if(mmi_bt_music_nolcd_check_profile(g_btmusic_nolcd_cntx.bt_address))
		    return MMI_RET_OK; //if Active device A2DP connected, keep in BT Music and do nothing
		else
		{  
		    srv_bt_cm_bt_addr *temp_bt_addr;
			
		    temp_bt_addr = mmi_bt_music_nolcd_get_second_addr(g_btmusic_nolcd_cntx.bt_address);
			if((A2DP_ROLE_SINK == srv_a2dp_get_role(temp_bt_addr)))
			{
			    /* Active device's A2DP not exsit && another SRC A2DP exit, update g_btmusic_nolcd_cntx.bt_address*/
			    g_btmusic_nolcd_cntx.bt_address = temp_bt_addr;
				srv_a2dp_sink_set_callback_notifier(g_btmusic_nolcd_cntx.bt_address,(A2DP_SRV_CALLBACK)mmi_bt_music_nolcd_A2DP_cb);
				return MMI_RET_OK;
			}
		}
	}
	
    if (NULL != g_btmusic_nolcd_cntx.group_id)
    {
        mmi_frm_group_close(GRP_ID_BT_MUSIC_NOLCD);
    }    
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_play_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_nolcd_play_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_PLAY_PAUSE, g_btmusic_nolcd_cntx.is_playing);
	#ifdef __KARAOKE_SUPPORT__
	g_btmusic_nolcd_cntx.karaoke_timer_enable = MMI_FALSE;
	#endif
	
    if(g_btmusic_nolcd_cntx.is_playing)
    { 
        #ifdef __MMI_AVRCP_SUPPORT__
		mmi_bt_music_nolcd_send_avrcp_cmd(SRV_AVRCP_POP_PAUSE);
        #endif        
		g_btmusic_nolcd_cntx.is_playing = MMI_FALSE;
    }
    else
    {    
        #ifdef __MMI_AVRCP_SUPPORT__
		mmi_bt_music_nolcd_send_avrcp_cmd(SRV_AVRCP_POP_PLAY);
        #endif        
		g_btmusic_nolcd_cntx.is_playing = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_inc_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_nolcd_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_INC_VOL, g_btmusic_nolcd_cntx.volume);
    if (g_btmusic_nolcd_cntx.volume < MDI_BT_MUSIC_NOLCD_VOL_MUTE_MAX)
    {
        g_btmusic_nolcd_cntx.volume++;
        WriteValueSlim(NVRAM_BT_MUSIC_NOLCD_VOL, &g_btmusic_nolcd_cntx.volume, DS_BYTE);
        mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(g_btmusic_nolcd_cntx.volume)));
        mmi_frm_input_event_notify(INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_UP, NULL);
    }
	mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_MUTE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_dec_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_nolcd_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_DEC_VOL, g_btmusic_nolcd_cntx.volume);
    if (g_btmusic_nolcd_cntx.volume > MDI_BT_MUSIC_NOLCD_VOL_MUTE_MIN)
    {
        g_btmusic_nolcd_cntx.volume--;
        WriteValueSlim(NVRAM_BT_MUSIC_NOLCD_VOL, &g_btmusic_nolcd_cntx.volume, DS_BYTE);
        mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(g_btmusic_nolcd_cntx.volume)));
        mmi_frm_input_event_notify(INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_DOWN, NULL);
		if(g_btmusic_nolcd_cntx.volume == MDI_BT_MUSIC_NOLCD_VOL_MUTE_MIN)
	        mmi_frm_input_event_notify(INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_MUTE, NULL);
		else
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_MUTE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_nolcd_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_PREV);
	
    #ifdef __MMI_AVRCP_SUPPORT__
	mmi_bt_music_nolcd_send_avrcp_cmd(MMI_AVRCP_POP_BACKWARD);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_nolcd_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_NEXT);
	#ifdef __MMI_AVRCP_SUPPORT__
	mmi_bt_music_nolcd_send_avrcp_cmd(MMI_AVRCP_POP_FORWARD);
    #endif
}

#ifdef __KARAOKE_SUPPORT__
static void mmi_bt_music_nolcd_karaoke()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_BT_MUSIC_NOLCD_KARAOKE,
              g_btmusic_nolcd_cntx.karaoke_timer_enable,
              g_btmusic_nolcd_cntx.is_original_enable,
              g_btmusic_nolcd_cntx.is_karaoke_enable);
    if(g_btmusic_nolcd_cntx.is_karaoke_enable == MMI_FALSE)
    {
        mmi_input_event_notify_param param = {0};
		if(mmi_bt_music_nolcd_is_sink_streaming() && srv_a2dp_sink_is_codec_open())
        {
            srv_a2dp_close_codec(); //close sink Codec for nofity
            mmi_bt_music_nolcd_play_pause();
			g_pause_btmusic_for_notify=MMI_TRUE;
        }
		else
		    mdi_audio_suspend_background_play();
		g_is_wait_for_notify = MMI_TRUE;
		g_btmusic_nolcd_cntx.is_karaoke_enable = MMI_TRUE;
		param.aud_cb = mmi_bt_music_nolcd_notify_callback_hdlr;
	    mmi_frm_input_event_notify(BTBOX_BT_MUSIC_NOLCD_KARAOKE, &param);
    }
    else
    {
        if(g_btmusic_nolcd_cntx.is_original_enable == MMI_TRUE)
        {
            kal_bool close_codec; //close codec for switch karaoke mode
            if(mmi_bt_music_nolcd_is_sink_streaming() && srv_a2dp_sink_is_codec_open())
	        {
	            srv_a2dp_close_codec(); //close sink Codec for karaoke change mode
	            close_codec=MMI_TRUE;
	        }
			else
		        mdi_audio_suspend_background_play();

            mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
            //mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_LEFT);
            g_btmusic_nolcd_cntx.is_karaoke_enable = MMI_FALSE;
            g_btmusic_nolcd_cntx.is_original_enable = MMI_FALSE;
            mmi_frm_input_event_notify_remove(BTBOX_BT_MUSIC_NOLCD_KARAOKE);
			if(close_codec)
	        {
	            srv_a2dp_open_codec(MMI_TRUE); //close sink Codec for karaoke change mode

				if(mmi_bt_music_nolcd_is_sink_streaming())
				{
				    kal_uint8 stream_handle=0;
				    stream_handle = srv_a2dp_get_stream_handle(g_btmusic_nolcd_cntx.bt_address);
			        mmi_a2dp_stream_start_codec_req(stream_handle);
				}
				close_codec = MMI_FALSE;
	        }
			else
		        mdi_audio_resume_background_play();
        }
        else
        {
            g_btmusic_nolcd_cntx.is_original_enable = MMI_TRUE;
            mdi_audio_set_karaoke_channel(MEDIA_KARAREC_MIX_RIGHT);
        }
    }
}


static void mmi_bt_music_nolcd_karaoke_switch()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_BT_MUSIC_NOLCD_KARAOKE_SWITCH,
              g_btmusic_nolcd_cntx.karaoke_timer_enable,
              g_btmusic_nolcd_cntx.is_original_enable,
              g_btmusic_nolcd_cntx.is_karaoke_enable);
    
    if(g_btmusic_nolcd_cntx.karaoke_timer_enable == MMI_TRUE)
    {
        StopTimer(BT_MUSIC_NOLCD_KARAOKE_SWITCH_TIMER);
        mmi_bt_music_nolcd_karaoke();
        g_btmusic_nolcd_cntx.karaoke_timer_enable = MMI_FALSE;
    }
    else
    {
        StartTimer(BT_MUSIC_NOLCD_KARAOKE_SWITCH_TIMER,BT_MUSIC_KARAOKE_SWITCH_DURATION,mmi_bt_music_nolcd_play_pause);
        g_btmusic_nolcd_cntx.karaoke_timer_enable = MMI_TRUE;
    }
}
#endif /*#ifdef __KARAOKE_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_nolcd_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_music_nolcd_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_NOLCD_PROC, event->evt_id);
    switch (event->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
			mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_BT_MUSIC);
			g_btmusic_nolcd_cntx.group_id = GRP_ID_INVALID;
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_UP);
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_DOWN);
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_MUTE);
			#ifdef __KARAOKE_SUPPORT__
			mmi_frm_input_event_notify_remove(BTBOX_BT_MUSIC_NOLCD_KARAOKE);
			mmi_frm_input_event_notify_remove(BTBOX_BT_MUSIC_NOLCD_KARAOKE_NO_AUD);
			#endif
			mmi_frm_input_event_notify_remove(BTBOX_BT_MUSIC_NOLCD_ENTER);
			mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
			g_pause_btmusic_for_notify = MMI_FALSE;
			g_is_wait_for_notify = MMI_TRUE;
            #ifdef __KARAOKE_SUPPORT__
			g_btmusic_nolcd_cntx.is_karaoke_enable = MMI_FALSE;
			g_btmusic_nolcd_cntx.is_original_enable = MMI_FALSE;
            #endif
            break;

		case EVT_ID_GROUP_ACTIVE:
            #ifdef __MMI_BTB_APPLICATION_BQB__
            g_is_wait_for_notify = 0;
            #endif  //__MMI_BTB_APPLICATION_BQB__
			if(g_is_wait_for_notify)
			{
				mmi_input_event_notify_param param = {0};
	            //Add Notify Here
	            if(mmi_bt_music_nolcd_is_sink_streaming() && srv_a2dp_sink_is_codec_open())
		        {
		            srv_a2dp_close_codec(); //close sink Codec for nofity
		            mmi_bt_music_nolcd_play_pause();
					g_pause_btmusic_for_notify=MMI_TRUE;
		        }
				else
			        mdi_audio_suspend_background_play();
				g_is_wait_for_notify = MMI_TRUE;
				param.aud_cb = mmi_bt_music_nolcd_notify_callback_hdlr;
			    mmi_frm_input_event_notify(BTBOX_BT_MUSIC_NOLCD_ENTER, &param);
				mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
				srv_a2dp_sink_set_callback_notifier(g_btmusic_nolcd_cntx.bt_address,(A2DP_SRV_CALLBACK)mmi_bt_music_nolcd_A2DP_cb);
				//srv_avrcp_register_bt_dialer_tg_cmd_callback(mmi_bt_music_nolcd_avrcp_reverse_control_hdlr);
				g_btmusic_nolcd_cntx.is_playing = mmi_bt_music_nolcd_is_sink_streaming();
				#ifdef __MMI_BT_BTBOX_NOLCD__
				//mmi_bt_anti_lost_screen_close();
				#endif
			}
			else
			{
			    #ifdef __KARAOKE_SUPPORT__
			    if(g_btmusic_nolcd_cntx.is_karaoke_enable)
			    {
			        mmi_input_event_notify_param param = {0};
                    mmi_frm_input_event_notify(BTBOX_BT_MUSIC_NOLCD_KARAOKE_NO_AUD,&param);
			    }
				#endif
				mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
				srv_a2dp_sink_set_callback_notifier(g_btmusic_nolcd_cntx.bt_address,(A2DP_SRV_CALLBACK)mmi_bt_music_nolcd_A2DP_cb);
				//srv_avrcp_register_bt_dialer_tg_cmd_callback(mmi_bt_music_nolcd_avrcp_reverse_control_hdlr);
				g_btmusic_nolcd_cntx.is_playing = mmi_bt_music_nolcd_is_sink_streaming();
				mmi_bt_music_nolcd_init_volume();
			}
			
            break;
		case EVT_ID_GROUP_INACTIVE:
			//mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_BT_MUSIC);
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_UP);
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_DOWN);
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_MUTE);
			#ifdef __KARAOKE_SUPPORT__
			mmi_frm_input_event_notify_remove(BTBOX_BT_MUSIC_NOLCD_KARAOKE);
			mmi_frm_input_event_notify_remove(BTBOX_BT_MUSIC_NOLCD_KARAOKE_NO_AUD);
			#endif
			mmi_frm_input_event_notify_remove(BTBOX_BT_MUSIC_NOLCD_ENTER);
			srv_avrcp_register_bt_dialer_tg_cmd_callback(NULL);
			mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
            break;
			/*
        case EVT_ID_DIALER_CONN_EVENT_ID:
            mmi_bt_music_nolcd_launch();
            break;
		case EVT_ID_DIALER_DISCONN_EVENT_ID:
            mmi_bt_music_nolcd_delaunch();
            break;
            */
        case BTBOX_BT_MUSIC_NOLCD_PLAY_PAUSE:
			//#ifdef __KARAOKE_SUPPORT__
			#if 0
/* under construction !*/
/* under construction !*/
			#else
			if(mmi_bt_music_nolcd_is_active())
			    mmi_bt_music_nolcd_play_pause();
			#endif
                
            break;
        case BTBOX_BT_MUSIC_NOLCD_VOL_UP:
			if(mmi_bt_music_nolcd_is_active())
                mmi_bt_music_nolcd_inc_volume();
            break;
        case BTBOX_BT_MUSIC_NOLCD_VOL_DOWN:
			if(mmi_bt_music_nolcd_is_active())
                mmi_bt_music_nolcd_dec_volume();
			break;
		case BTBOX_BT_MUSIC_NOLCD_PREV:
			if(mmi_bt_music_nolcd_is_active())
                mmi_bt_music_nolcd_prev();
            break;
        case BTBOX_BT_MUSIC_NOLCD_NEXT:
            if(mmi_bt_music_nolcd_is_active())
                mmi_bt_music_nolcd_next();
            break;
        case EVT_ID_INPUT_EVENT_BT_MUSIC_DIAL_LAST_CALL:
    #if defined(__MMI_BT_CALL_SUPPORT__) && defined(__MMI_UCM_BT_BTBOX_NOLCD__)
            if(mmi_bt_music_nolcd_is_active())
                mmi_ucm_redial_action_bt();
    #endif
            break;
	#ifdef __KARAOKE_SUPPORT__
		case EVT_ID_INPUT_EVENT_BT_MUSIC_KARAOKE:
			if(mmi_bt_music_nolcd_is_active())
                mmi_bt_music_nolcd_karaoke();
			break;
    #endif /*#ifdef __KARAOKE_SUPPORT__*/
		case EVT_ID_INPUT_EVENT_BT_MUSIC_SWITCH_SRC:
			if(mmi_bt_music_nolcd_is_active())
                mmi_bt_music_switch_src();
			break;
    }
    return MMI_RET_OK;
}

//bellow functions is to avoid link erros
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_check_connection
 * DESCRIPTION
 *  Check bt music need to disconnect
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_music_check_connection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 role;
    MMI_BOOL A2DP_connc = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    A2DP_connc = srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION);
    role = srv_a2dp_get_role((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset());
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_CHECK_CONNECTION, A2DP_connc, role);
    if(BT_A2DP_SINK == role && A2DP_connc)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

typedef  void (*BT_MUSIC_CALLBACK)(MMI_BOOL result);
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_disconnect
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/ 
void mmi_bt_music_disconnect(BT_MUSIC_CALLBACK callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


#endif  //__MMI_BT_MUSIC_NOLCD__

