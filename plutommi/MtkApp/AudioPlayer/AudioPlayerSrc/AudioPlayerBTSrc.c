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
/*  Include: MMI header file */
#include "MMI_features.h"
#if defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
#ifdef __MMI_AUDIO_PLAYER__
#include "mmi_rp_app_audioplayer_def.h"
#include "AudioPlayerprot.h"
#endif
#include "FileManagerGProt.h"
#include "A2dpSrvGprot.h"
#include "mmi_rp_srv_a2dp_def.h"
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "BTMMIScr.h"
#include "AudioPlayerBTNowPlaying.h"
#include "BTMMIAVRCPGProt.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_popup.h"
#include "Conversions.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "IdleGprot.h"

/***************************************************************************** 
* Public Functions Declaration
*****************************************************************************/
void mmi_bt_music_device_list_entry(void);
void mmi_bt_music_inc_vol(void);
void mmi_bt_music_dec_vol(void);

/***************************************************************************** 
* Global Variable
*****************************************************************************/
MMI_BOOL g_is_enter_local_list = MMI_FALSE;
MMI_BOOL g_is_launch_from_bt = MMI_FALSE;
mmi_audply_dev_list_cntx_struct g_bt_music_dev;

/***************************************************************************** 
* static Variable
*****************************************************************************/
#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
static MMI_BOOL bt_music_connecting = MMI_FALSE;
#endif
static U32 elapsed_ms = -1;
static U32 duration = 0;
static MMI_BOOL is_bt_music_premmpted = MMI_FALSE;
//static MMI_BOOL stream_valid = MMI_FALSE;
static U32 a2dp_conn_num = 0;
/***************************************************************************** 
* function implement
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_check_role_by_addr
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  u8
 *****************************************************************************/
U8 mmi_bt_music_check_role_by_addr(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 role;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    role = srv_a2dp_get_role(dev_addr);
    return role;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_reset_status_icon_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/ 
static void mmi_bt_music_reset_status_icon_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*Update status icon*/
    //wgui_status_icon_bar_reset_icon_display(STATUS_ICON_AUDPLY);
    StartTimer(BT_MUSIC_STATUS_ICON_TIMER, 100, wgui_status_icon_bar_update);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_show_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/ 
static void mmi_bt_music_show_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Update status icon*/
    //ShowStatusIcon(STATUS_ICON_AUDPLY); 
    StartTimer(BT_MUSIC_STATUS_ICON_TIMER,100,UpdateStatusIcons);  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_set_elapsed_ms
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_audply_dev_list_cntx_struct *mmi_bt_music_get_dev_list_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_bt_music_dev;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_get_dev_addr_by_role
 * DESCRIPTION
 *  
 * PARAMETERS
 *  role       [IN]                
 * RETURNS
 *  void
 *****************************************************************************/
srv_bt_cm_bt_addr *mmi_bt_music_get_dev_addr_by_role(U8 r)
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
                MMI_TRC_BT_MUSIC_GET_DEV_ADDR_BY_ROLE,
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
 *  mmi_bt_music_get_second_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  role       [IN]                
 * RETURNS
 *  void
 *****************************************************************************/
srv_bt_cm_bt_addr *mmi_bt_music_get_second_addr(srv_bt_cm_bt_addr *first_addr)
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
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_GET_SECOND_ADDR, first_addr, second_addr); 
            return second_addr;
        }
    }
    
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_get_ct_dev_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  VOID                
 * RETURNS
 *  srv_bt_cm_bt_addr*
 *****************************************************************************/
srv_bt_cm_bt_addr* mmi_bt_music_get_ct_dev_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_bt_music_get_dev_addr_by_role(A2DP_ROLE_SOURCE);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_get_tg_dev_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  VOID               
 * RETURNS
 *  srv_bt_cm_bt_addr*
 *****************************************************************************/
srv_bt_cm_bt_addr* mmi_bt_music_get_tg_dev_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_bt_music_get_dev_addr_by_role(A2DP_ROLE_SINK);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_send_avrcp_command_by_addr
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_send_avrcp_command_by_addr(srv_bt_cm_bt_addr *dev_addr, S32 cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_send_cmd_frame(dev_addr, cmd);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_send_ct_avrcp_command
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_send_ct_avrcp_command(S32 cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_dialer;
    srv_bt_cm_bt_addr *ct_addr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ct_addr = mmi_bt_music_get_ct_dev_addr();
    
    if(!ct_addr)
    {
        return;
    }
    
    is_dialer = srv_bt_cm_is_bt_dialer(ct_addr);
    
    if(is_dialer)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_SEND_CT_AVRCP_CMD, cmd); 
        srv_avrcp_send_cmd_frame(ct_addr, cmd);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_send_tg_avrcp_command
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_send_tg_avrcp_command(S32 cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_dialer;
    srv_bt_cm_bt_addr *tg_addr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_SEND_TG_AVRCP_CMD, cmd); 

    tg_addr = mmi_bt_music_get_tg_dev_addr();
    
    if(!tg_addr)
    {
        return;
    }
    
    srv_avrcp_send_cmd_frame(tg_addr, cmd);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_avrcp_reverse_control_hdlr
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_music_avrcp_reverse_control_hdlr(srv_bt_cm_bt_addr *dev_addr, U8 command_type, srv_avrcp_key_events key_events)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bt_addr *addr_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_AVRCP_REVERSE_CONTROL_HDLR, command_type, key_events); 
    
	if(key_events == SRV_AVRCP_KEY_DOWN)
		return MMI_TRUE;
    //need to transfer avrcp command to another linked device
    addr_p = mmi_bt_music_get_second_addr(dev_addr);
    
    if((key_events == SRV_AVRCP_KEY_UP) && addr_p)
    {
        mmi_bt_music_send_avrcp_command_by_addr(addr_p, command_type);
    }

    switch (command_type)
    {
        case MMI_AVRCP_POP_PLAY:
        {
           mmi_bt_music_set_main_sel_btn(BT_MUSIC_MAIN_PAUSE);
            mmi_bt_music_redraw_main_btns_bt();
            break;
        }
        case MMI_AVRCP_POP_PAUSE:
        {
            mmi_bt_music_set_main_sel_btn(BT_MUSIC_MAIN_PLAY);
            mmi_bt_music_redraw_main_btns_bt();
            break;
        }
        case MMI_AVRCP_POP_STOP:
        {
            break;
        }
        case MMI_AVRCP_POP_FORWARD:
        {
            break;
        }
        case MMI_AVRCP_POP_BACKWARD:
        {
            break;
        }
        case MMI_AVRCP_POP_VOLUME_DOWN:
        {
            mmi_bt_music_dec_vol();
            mmi_bt_music_redraw_volumebar();
            mmi_bt_music_redraw_main_volume_speaker();
            break;
        }
        case MMI_AVRCP_POP_VOLUME_UP:
        {
            mmi_bt_music_inc_vol();
            mmi_bt_music_redraw_volumebar();
            mmi_bt_music_redraw_main_volume_speaker();
            break;
        }
        default:
            break;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_reg_avrcp_reverse_control
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_reg_avrcp_reverse_control(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_register_bt_dialer_tg_cmd_callback(mmi_bt_music_avrcp_reverse_control_hdlr);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_set_elapsed_ms
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_set_elapsed_ms(U32 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    elapsed_ms = val;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_get_elapsed_ms
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_bt_music_get_elapsed_ms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return elapsed_ms;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_set_duration
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_set_duration(U32 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    duration = val;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_get_duration
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_bt_music_get_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return duration;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_read_volume
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_read_volume(U8 *val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BT_MUSIC, val, DS_BYTE, &error);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_write_volume
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_write_volume(U8 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_BT_MUSIC, &val, DS_BYTE, &error);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_set_launch_point
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_set_launch_point(MMI_BOOL lp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_launch_from_bt = lp;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_btspeaker_set_volume_handler
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_btspeaker_set_volume_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gain;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_music_read_volume(&gain);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_SET_VOL, gain);
    mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(gain)));
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_close_cb
 * DESCRIPTION
 *  bt music close callback function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_bt_music_close_cb(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_CLOSE_CALLBACK);
    
    a2dp_conn_num--;
    
    if(a2dp_conn_num == 0)
    {
        mmi_frm_cb_dereg_event(EVT_ID_SRV_A2DP_DISCONNECT, mmi_bt_music_close_cb, NULL);
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO,
            (WCHAR*)GetString(STR_ID_BT_MUSIC_DISCONNECTING));
    }
    return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_disconnect_A2DP_sink_dev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index       [IN]                
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_bt_music_disconnect_A2DP_sink_dev()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *dev_p;
    srv_bt_cm_bt_addr *addr_p;
    MMI_BOOL A2DP_connc;
    U8 role;
    U32 i;
    U32 link_dev_num = srv_bt_cm_get_linked_dev_list_idx();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    a2dp_conn_num = 0;
    
    for(i=0; i<link_dev_num; i++)
    {
        //get device address
        dev_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(i);
        addr_p = &(dev_p->bd_addr);
        
        A2DP_connc = srv_a2dp_is_connected_ex(addr_p);
        role = mmi_bt_music_check_role_by_addr(addr_p);

        if(A2DP_connc && (role == A2DP_ROLE_SINK))
        {
            a2dp_conn_num++;
            srv_a2dp_close_ex(addr_p);
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_disconnect
 * DESCRIPTION
 *  
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
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_DISCONNECT);
    mmi_frm_cb_reg_event(EVT_ID_SRV_A2DP_DISCONNECT, mmi_bt_music_close_cb, NULL);
    mmi_bt_music_disconnect_A2DP_sink_dev();
    //callback(MMI_TRUE);
}
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
    U32 link_dev_num;
    MMI_BOOL res;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    link_dev_num = srv_bt_cm_get_linked_dev_list_idx();
    res = (link_dev_num == 0) ? MMI_FALSE : MMI_TRUE;
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_CHECK_CONNECTION, res);
    
    return res;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_speaker_background_callback_hdlr
 * DESCRIPTION
 *  BT music background callbak func.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/ 
BOOL mmi_bt_speaker_background_callback_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BG_CB, result, is_bt_music_premmpted);
    
    if(result == MDI_AUDIO_RESUME)
    {
        if(is_bt_music_premmpted)
        {
            mmi_btspeaker_set_volume_handler();
            srv_a2dp_sink_avrcp_interface(SRV_A2DP_SINK_RESUME);
            is_bt_music_premmpted = MMI_FALSE;
			mmi_bt_music_set_app_streaming_state(MMI_TRUE); //MAUI_03495390
        } 
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_BT_MUSIC);
    }
    return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sepaker_power_off
 * DESCRIPTION
 *  BT music interrupt callback func, will be registered by MDI when A2DP
 *  codec open.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/ 
void mmi_bt_sepaker_power_off(S32 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL is_streaming = srv_a2dp_is_streaming();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_POWER_OFF, result, is_streaming);

	if(is_streaming != mmi_bt_music_get_app_streaming_state())
	    mmi_bt_music_set_app_streaming_state(is_streaming);
	
    if(result == MDI_AUDIO_TERMINATED)
    {
        if (is_streaming)
        {
            is_bt_music_premmpted = MMI_TRUE;
            srv_a2dp_sink_avrcp_interface(SRV_A2DP_SINK_TERMINATED);
			mmi_bt_music_set_app_streaming_state(MMI_FALSE);
        }	
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_BT_MUSIC, mmi_bt_speaker_background_callback_hdlr,NULL);
        mdi_audio_clear_other_background_handler(MDI_BACKGROUND_APP_BT_MUSIC);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_inc_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_inc_vol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gain;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_music_read_volume(&gain);
    if (gain < MDI_AUD_VOL_EX_NUM-1)
    {  
        gain++;
        mmi_bt_music_write_volume(gain);
        mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(gain)));
        mmi_bt_music_send_avrcp_command_by_addr(g_bt_music_dev.device_address, SRV_AVRCP_POP_VOLUME_UP);  
    }    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_dec_vol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_dec_vol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gain;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_music_read_volume(&gain);
    if (gain)
    {  
        gain--;
        mmi_bt_music_write_volume(gain);
        mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(gain)));
        mmi_bt_music_send_avrcp_command_by_addr(g_bt_music_dev.device_address, SRV_AVRCP_POP_VOLUME_DOWN);  
    }  
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_is_A2DP_sink
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_music_is_A2DP_sink(srv_bt_cm_bt_addr *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 role;
    MMI_BOOL is_headset;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    role = srv_a2dp_get_role(addr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_IS_A2DP_SINK, role, is_headset);
    if(A2DP_ROLE_SINK == role)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_check_profile
 * DESCRIPTION
 *  check music player releated profiles: A2DP and AVRCP_CT
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_music_check_profile(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL AVRCP_connc, A2DP_connc;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    A2DP_connc = srv_a2dp_is_connected_ex(dev_addr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_A2DP_PROFILE, A2DP_connc);
    AVRCP_connc = srv_avrcp_is_avrcp_connected(dev_addr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_AVRCP_PROFILE, AVRCP_connc);
    
    return (AVRCP_connc && A2DP_connc);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_playing = MMI_FALSE;
	MMI_BOOL conn = MMI_FALSE;  
    srv_bt_cm_bt_addr *src_addr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_PRE_ENTRY);
    
    src_addr = mmi_bt_music_get_tg_dev_addr();
    
    if(src_addr)
    {
        is_playing = srv_a2dp_is_streaming_ex(src_addr);
		conn = mmi_bt_music_check_profile(src_addr);
    }
    
    if(is_playing && conn)// src device is playing
    {
        g_bt_music_dev.device_address = src_addr;
        mmi_bt_music_entry_nowplaying_page();
    }
    else
    {
        //entry connecting list
        mmi_bt_music_device_list_entry();
    }
    return;
} 
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_create_main_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_create_main_group(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_LAUNCH, parent_gid);
    mmi_frm_group_create_ex(parent_gid,
                            GRP_ID_BT_MUSIC_APP,
                            NULL,
                            NULL,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    return;
} 
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_launch_dev_list
 * DESCRIPTION
 *  This function is to launch bt music
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_launch_dev_list(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_music_create_main_group(parent_gid);
    mmi_bt_music_device_list_entry();
    return;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_launch_fn
 * DESCRIPTION
 *  This function is to launch bt music
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_launch_fn(MMI_ID parent_gid)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_bt_music_create_main_group(parent_gid);
    mmi_bt_music_pre_entry();
    return;
} 
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_is_playing
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_music_is_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    return srv_a2dp_is_streaming();

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_a2dp_connect_callback_hdlr
 * DESCRIPTION
 *  passive connect a2dp event hdlr
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 ****************************************************************************/
mmi_ret mmi_bt_music_a2dp_connect_callback_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL nowplaying_page_is_present = mmi_frm_scrn_is_present(GRP_ID_BT_MUSIC_APP,SCR_ID_BT_MUSIC_APP, MMI_FRM_NODE_ALL_FLAG);
    MMI_BOOL conn_page_is_present = mmi_frm_scrn_is_present(GRP_ID_BT_MUSIC_APP,SCR_ID_BT_MUSIC_CONN_SCREEN, MMI_FRM_NODE_ALL_FLAG);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_A2DP_CONNECT_CALLBACK_HDLR, nowplaying_page_is_present, conn_page_is_present);
    if(conn_page_is_present && !nowplaying_page_is_present)
    {
        mmi_bt_music_entry_nowplaying_page();
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_a2dp_connect_callback_hdlr
 * DESCRIPTION
 *  passive connect a2dp event hdlr
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 ****************************************************************************/
mmi_ret mmi_bt_music_dialer_disconn_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_dev_struct* dev_p = NULL;	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	dev_p = (srv_bt_cm_dev_struct*)(((srv_bt_dialer_event_struct *)event)->event_info);

	if(mmi_frm_group_is_present(GRP_ID_BT_MUSIC_APP))
	{
	  if(dev_p == NULL) return MMI_RET_OK;
      MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_BT_MUSIC_DISCONN_DEV_ADDRESS,dev_p->bd_addr.lap,dev_p->bd_addr.uap,dev_p->bd_addr.nap);	
	  if(dev_p->bd_addr.lap == g_bt_music_dev.device_address->lap &&
         dev_p->bd_addr.uap == g_bt_music_dev.device_address->uap &&
         dev_p->bd_addr.nap == g_bt_music_dev.device_address->nap)
	  		mmi_frm_group_close(GRP_ID_BT_MUSIC_APP);
	}
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_profile_evt_hdlr
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
mmi_ret mmi_bt_music_profile_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_BOOL)mmi_bt_music_is_playing())
    {
        return (!MMI_RET_OK);
    }
    return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_progressbar_forward
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_progressbar_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(elapsed_ms < duration)
    {
        elapsed_ms = elapsed_ms + 500;
        mmi_bt_music_redraw_progressbar();
        mmi_bt_music_redraw_time();
    }
    StartTimer(BT_MUSIC_SEEKING_TIMER, 500, mmi_bt_music_progressbar_forward);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_sync_current_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_sync_current_pos(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_get_play_status_req(g_bt_music_dev.device_address);
    StartTimer(BT_MUSIC_SYNC_POS_TIMER, 3000, mmi_bt_music_sync_current_pos);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_auto_seeking
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_auto_seeking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BT_MUSIC_SEEKING_TIMER);
    StartTimer(BT_MUSIC_SEEKING_TIMER, 500, mmi_bt_music_progressbar_forward);

    StopTimer(BT_MUSIC_SYNC_POS_TIMER);
    StartTimer(BT_MUSIC_SYNC_POS_TIMER, 3000, mmi_bt_music_sync_current_pos);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_progressbar_forward_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_progressbar_forward_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BT_MUSIC_SEEKING_TIMER);
    StopTimer(BT_MUSIC_SYNC_POS_TIMER);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_entry_local_music
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_entry_local_music()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */

    /*check memory card first (only in audioplayerBT mode)*/
    if (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
        mmi_popup_display_ext(
                STR_GLOBAL_INSERT_MEMORY_CARD, 
                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(FS_MEDIA_CHANGED), 
                NULL);
        return;
    }
    mmi_bt_music_set_launch_point(MMI_TRUE);
    #ifdef __MMI_AUDIO_PLAYER__
    mmi_audply_entry_main();
    #endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_entry_local_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_entry_local_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__USB_IN_NORMAL_MODE__)
	if (srv_usb_is_in_mass_storage_mode())
	{
		mmi_usb_app_unavailable_popup(0);
		return;
	}
#endif /* defined(__USB_IN_NORMAL_MODE__) */
	
    /*check memory card first (only in audioplayerBT mode)*/
    if (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
        mmi_popup_display_ext(
                STR_GLOBAL_INSERT_MEMORY_CARD, 
                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(FS_MEDIA_CHANGED), 
                NULL);
        return;
    }
	
 #ifdef __MMI_AUDIO_PLAYER__
	if(mmi_frm_group_is_present(GRP_ID_BT_MUSIC_APP))
	    mmi_frm_group_close(GRP_ID_BT_MUSIC_APP);

	if(!mmi_frm_group_is_present(GRP_ID_AUDPLY_MAIN))
    {
	  mmi_frm_group_create_ex(
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        GRP_ID_AUDPLY_MAIN_PRE_LIST,
    #else
        GRP_ID_ROOT, 
    #endif
        GRP_ID_AUDPLY_MAIN, 
        NULL, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

	mmi_audply_playlist_entry_playlist(); 
	//g_is_enter_local_list = MMI_FALSE;
#endif /*__MMI_AUDIO_PLAYER__*/
}	
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_A2DP_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_A2DP_cb(srv_bt_cm_bt_addr *address, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_a2dp_callback_event_enum event = (srv_a2dp_callback_event_enum)result;
    MMI_ID scrn_id = mmi_frm_scrn_get_active_id(); 
	MMI_ID group_id = mmi_frm_group_get_active_id();
    MMI_BOOL is_streaming = mmi_bt_music_get_app_streaming_state();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_A2DP_CB, event);
    switch(event)
    {
        case SRV_A2DP_CALLBACK_EVENT_OPEN_OK:
        {    
            #if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
            bt_music_connecting = MMI_FALSE;
            #endif
            mmi_bt_music_entry_nowplaying_page();
            break;
        }
        case SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED:
        {
			if(GRP_ID_BT_MUSIC_APP == group_id)	
           		mmi_frm_nmgr_popup(
               		MMI_SCENARIO_ID_DEFAULT,
                	MMI_EVENT_FAILURE,
                	(WCHAR*)GetString(STR_ID_BT_MUSIC_CONN_FAILED));
            break;
        }
        case SRV_A2DP_CALLBACK_EVENT_STREAM_PAUSE_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_A2DP_CB_SUSPEND_IND, is_streaming);
            //if(is_streaming) MAUI_03495390
            {
                mmi_bt_music_set_app_streaming_state(MMI_FALSE);
                if(scrn_id == SCR_ID_BT_MUSIC_APP)
                {
                    #if defined(__MMI_BTMUSIC_BTBOX_KEYBOARD_STYLE__)
                    mmi_bt_music_set_main_LSK_text((UI_string_type) GetString(STR_GLOBAL_PLAY));
                    mmi_bt_music_redraw_LSK_up();
                    #else
                    mmi_bt_music_set_main_sel_btn(BT_MUSIC_MAIN_PLAY);
                    mmi_bt_music_redraw_main_btns_bt();
                    #endif
                }
                mmi_bt_music_reset_status_icon_bar();
            }
            /*BT music will not resumed if paused*/
            break;
        }
        case SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND:
        case SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_A2DP_CB_DISCONNECT_IND);
            if(mmi_frm_scrn_is_present(GRP_ID_BT_MUSIC_APP,SCR_ID_BT_MUSIC_APP, MMI_FRM_NODE_ALL_FLAG))
            {
                mmi_bt_music_entry_bt_connect_page();
                mmi_frm_scrn_close(GRP_ID_BT_MUSIC_APP, SCR_ID_BT_MUSIC_APP);
            }
            break;
        }
        case SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_A2DP_CB_START_IND,is_streaming);
            mmi_btspeaker_set_volume_handler();
           // if(!is_streaming)MAUI_03495390
            {
                mmi_bt_music_set_app_streaming_state(MMI_TRUE);
                if(scrn_id == SCR_ID_BT_MUSIC_APP)
                {
                    #if defined(__MMI_BTMUSIC_BTBOX_KEYBOARD_STYLE__)
                    mmi_bt_music_set_main_LSK_text((UI_string_type) GetString(STR_GLOBAL_PAUSE));
                    mmi_bt_music_redraw_LSK_up();
                    #else
                    mmi_bt_music_set_main_sel_btn(BT_MUSIC_MAIN_PAUSE);
                    mmi_bt_music_redraw_main_btns_bt();
                    #endif
                }
                mmi_bt_music_show_status_icon();
            }
            break;
        }
        default:
            break;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_bt_link_lsk_hdlr
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_music_bt_link_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	a2dp_role_enum role = A2DP_ROLE_NONE;
	U32 link_dev_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_LSK_CONN);
	/*get device num  */
    link_dev_num = srv_bt_cm_get_linked_dev_list_idx();
	if(0 == link_dev_num)
	  {
		mmi_frm_nmgr_popup(
			MMI_SCENARIO_ID_DEFAULT,
			MMI_EVENT_FAILURE,
			(WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE));

		if(mmi_frm_scrn_is_present(GRP_ID_BT_MUSIC_APP,SCR_ID_BT_MUSIC_CONN_SCREEN, MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_scrn_close(GRP_ID_BT_MUSIC_APP, SCR_ID_BT_MUSIC_CONN_SCREEN);
        }
		return;
	  }
	role = srv_a2dp_get_role(g_bt_music_dev.device_address);
	if (BT_A2DP_SOURCE == role)
	  {
		mmi_frm_nmgr_popup(
			MMI_SCENARIO_ID_DEFAULT,
			MMI_EVENT_FAILURE,
			(WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE));
		return;
	  }

    srv_a2dp_open_sink(g_bt_music_dev.device_address, mmi_bt_music_A2DP_cb, MMI_TRUE);

    #if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
    bt_music_connecting = MMI_TRUE;
    #endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_auto_connect
 * DESCRIPTION
 *  This function is to auto connect A2DP profile
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_auto_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_AUTO_CONN);
    mmi_bt_music_bt_link_lsk_hdlr();
}

#ifdef __MMI_BT_AVRCP_V13__
/*****************************************************************************
 * FUNCTION
 *  bt_music_avrcp_notify_handler
 * DESCRIPTION
 *  srv_avrcp_metadata_trasnfer_events
 *  Whenever AVRCP(Bt music) is connected to SP, it will internally register 
 *  following notifications:
 *  SRV_AVRCP_EVENT_PLAYBACK_STATUS_CHANGED
 *  SRV_AVRCP_EVENT_TRACK_CHANGED
 *  SRV_AVRCP_EVENT_TRACK_REACHED_END
 *  SRV_AVRCP_EVENT_TRACK_REACHED_START
 *  SRV_AVRCP_EVENT_BATT_STATUS_CHANGED
 *  SRV_AVRCP_EVENT_SYSTEM_STATUS_CHANGED
 * PARAMETERS
 *  notification_evt:  [IN]   notify event
 * RETURNS
 *  void
 *****************************************************************************/ 
void mmi_bt_music_avrcp_notify_handler(srv_avrcp_register_notification_result notification_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scrn_id = mmi_frm_scrn_get_active_id(); 
    MMI_BOOL is_streaming = mmi_bt_music_get_app_streaming_state();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_AUDPLY_BT_EVT_ID, notification_evt.event_id);
    switch (notification_evt.event_id)
    {        
        case SRV_AVRCP_EVENT_PLAYBACK_STATUS_CHANGED:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
                      MMI_TRC_AUDPLY_BT_STATUS_CHANGE, 
                      notification_evt.playback_status,
                      is_streaming);
            
            if (SRV_AVRCP_PLAY_STATUS_PLAYING == notification_evt.playback_status)
            {
                if(scrn_id == SCR_ID_BT_MUSIC_APP)
                {
                    mmi_bt_music_auto_seeking();
                }
                if (!is_streaming)
                {
                    mmi_bt_music_set_app_streaming_state(MMI_TRUE);
                    if (scrn_id == SCR_ID_BT_MUSIC_APP)
                    {
                        #if defined(__MMI_BTMUSIC_BTBOX_KEYBOARD_STYLE__)
                        mmi_bt_music_set_main_LSK_text((UI_string_type) GetString(STR_GLOBAL_PAUSE));
                        mmi_bt_music_redraw_LSK_up();
                        #else
                        mmi_bt_music_set_main_sel_btn(BT_MUSIC_MAIN_PAUSE);
                        mmi_bt_music_redraw_main_btns_bt();
                        #endif
                    }
                }
            }
            else
            {
                if(scrn_id == SCR_ID_BT_MUSIC_APP)
                {
                    mmi_bt_music_progressbar_forward_stop();
                }
                if (is_streaming)
                {
                    mmi_bt_music_set_app_streaming_state(MMI_FALSE);
                    if(scrn_id == SCR_ID_BT_MUSIC_APP)
                    {
                        #if defined(__MMI_BTMUSIC_BTBOX_KEYBOARD_STYLE__)
                        mmi_bt_music_set_main_LSK_text((UI_string_type) GetString(STR_GLOBAL_PLAY));
                        mmi_bt_music_redraw_LSK_up();
                        #else
                        mmi_bt_music_set_main_sel_btn(BT_MUSIC_MAIN_PLAY);
                        mmi_bt_music_redraw_main_btns_bt();
                        #endif
                    }
                }
            }
            break;
        }
        
        case SRV_AVRCP_EVENT_TRACK_CHANGED:
        {
            if(scrn_id == SCR_ID_BT_MUSIC_APP)
            {
                srv_avrcp_get_elements_attr_request(g_bt_music_dev.device_address);
                srv_avrcp_get_play_status_req(g_bt_music_dev.device_address);
            }
            break;
        }
        
        case SRV_AVRCP_EVENT_TRACK_REACHED_END:
        {
            break;
        }
        
        case SRV_AVRCP_EVENT_TRACK_REACHED_START:
        {
            break;
        }
        
        case SRV_AVRCP_EVENT_PLAYBACK_POS_CHNAGED:
        {
            break;
        }
        
        case SRV_AVRCP_EVENT_BATT_STATUS_CHANGED:
        {
            break;
        }
        
        case SRV_AVRCP_EVENT_SYSTEM_STATUS_CHANGED:
        {
            break;
        }
        
        case SRV_AVRCP_EVENT_PLAYER_APP_SETTING_CHNAGED:
        {
            break;
        }
        
        default:
            break;
    }
}
/*****************************************************************************
 * FUNCTION
 *  bt_music_avrcp_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/ 
void mmi_bt_music_avrcp_cb(srv_bt_cm_bt_addr *dev_addr, srv_avrcp_event_enum event_id, srv_avrcp_result_union result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scrn_id = mmi_frm_scrn_get_active_id(); 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event_id)
    {
        case SRV_AVRCP_EVT_ID_SUPPORTED_ATTR_EVENT:
        {
            break;
        }
        
        case SRV_AVRCP_EVT_ID_SUPPORTED_ATTR_VALUE_EVENT:
        {
            break;
        }
        
        case SRV_AVRCP_EVT_ID_CURR_ATTR_VAL_EVENT:
        {
            break;
        }

        case SRV_AVRCP_EVT_ID_SET_PLAYERAPP_VAL_EVENT:
        {
            break;
        }

        case SRV_AVRCP_EVT_ID_ATTR_TXT_EVENT:
        {
            break;
        }
        
        case SRV_AVRCP_EVT_ID_ATTR_TXT_VAL_EVENT:
        {
            break;
        }
        
        case SRV_AVRCP_EVT_ID_INFORM_DISPLAYABLE_CHARSET_EVENT:
        {
            break;
        }
        
        case SRV_AVRCP_EVT_ID_INFORM_BATT_STATUS_CT_EVENT:
        {
            break;
        }
        
        case SRV_AVRCP_EVT_ID_PLAY_STATUS_EVENT:
        {
            if (scrn_id != SCR_ID_BT_MUSIC_APP)
            {
                break;
            }
            if (SRV_AVRCP_RESULT_SUCCESS != result.play_status.result)
            {
                break;
            }

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
                      MMI_TRC_AUDPLY_BT_EVT_STATUS, 
                      result.play_status.song_len,
                      result.play_status.song_pos,
                      result.play_status.play_status);

            duration = result.play_status.song_len;
            elapsed_ms = result.play_status.song_pos;
            mmi_bt_music_redraw_time();
            mmi_bt_music_redraw_progressbar();
            if (SRV_AVRCP_PLAY_STATUS_PLAYING == result.play_status.play_status)
            {
                mmi_bt_music_auto_seeking();
            }
            break;
        }
        case SRV_AVRCP_EVT_ID_ELEM_ATTR_EVENT:
        {
            if (scrn_id != SCR_ID_BT_MUSIC_APP)
            {
                break;
            }
            if (SRV_AVRCP_RESULT_SUCCESS != result.elem_attr.result)
            {
                break;
            }
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_AUDPLY_BT_EVT_UPDATE_TITLE);
            mmi_bt_music_update_songinfo(result.elem_attr);
            mmi_bt_music_redraw_main_BT_title();
            break;
        }
        
        case SRV_AVRCP_EVT_ID_REG_NOTIFICATION_EVENT:
        {
            if (SRV_AVRCP_RESULT_SUCCESS != result.reg_notification_event.result)
            {
                break;
            }

            mmi_bt_music_avrcp_notify_handler(result.reg_notification_event);
            break;
        }

        case SRV_AVRCP_EVT_ID_ABORT_REQ_EVENT:
        {
            break;
        }
    
        default:
            break;
    }
}
#endif

#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_scrlocker_event_notify_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_music_scrlocker_event_notify_handler(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    if (event->evt_id == EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING)
    {
        if (bt_music_connecting)
        {
            return MMI_RET_ERR;
        }
    }
    */
    return MMI_RET_OK;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_terminate_other_src_dev_stream_by_addr
 * DESCRIPTION
 *  termiante src device stream before enter nowplaying page
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/ 
void mmi_bt_music_terminate_other_src_dev_stream_by_addr(srv_bt_cm_bt_addr *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bt_addr *sec;
    MMI_BOOL is_role_sink, is_streaming;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sec = mmi_bt_music_get_second_addr(addr);
    is_role_sink = mmi_bt_music_is_A2DP_sink(sec);
    is_streaming = srv_a2dp_is_streaming_ex(sec);
    
    if(is_role_sink && is_streaming)
    {
        //srv_a2dp_pause_stream();
        srv_avrcp_send_cmd_frame(sec, SRV_AVRCP_POP_PAUSE);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_enter_select_device_scrn
 * DESCRIPTION
 *  enter selected device screen
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/ 
void mmi_bt_music_enter_select_device_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL conn, role_sink;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_ENTER_SELECT_DEV_SCRN);
    
    conn = mmi_bt_music_check_profile(g_bt_music_dev.device_address);
    role_sink = mmi_bt_music_is_A2DP_sink(g_bt_music_dev.device_address);
	g_is_enter_local_list = MMI_FALSE; //MAUI_03495266

    if(mmi_frm_scrn_is_present(GRP_ID_BT_MUSIC_APP,SCR_ID_BT_MUSIC_APP, MMI_FRM_NODE_ALL_FLAG))
    {
	  mmi_frm_scrn_close(GRP_ID_BT_MUSIC_APP, SCR_ID_BT_MUSIC_APP);
    }	
	
    if(role_sink && conn)
    {
        MMI_TRACE(
                MMI_MEDIA_TRC_G2_APP,
                MMI_BT_MUSIC_ENTER_SELECT_DEV_SCRN_ADDRESS,
                g_bt_music_dev.device_address->lap,
                g_bt_music_dev.device_address->nap,
                g_bt_music_dev.device_address->uap); 
        
        //registe a2dp callback
        srv_a2dp_open_sink(g_bt_music_dev.device_address, mmi_bt_music_A2DP_cb, MMI_TRUE);
        mmi_bt_music_terminate_other_src_dev_stream_by_addr(g_bt_music_dev.device_address);
        mmi_bt_music_entry_nowplaying_page();
    }
    else
    {
        mmi_bt_music_entry_bt_connect_page();
        mmi_bt_music_auto_connect();
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_enter_select_device_scrn
 * DESCRIPTION
 *  enter selected device screen
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/ 
void mmi_bt_music_registe_connected_dev_AVRCP_callback(srv_bt_cm_bt_addr *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BT_MUSIC_TRC_DEV_AVRCP_CB);
    if(mmi_bt_music_check_profile(addr))
    {
        #ifdef __MMI_BT_AVRCP_V13__
        srv_avrcp_register_notification_hdlr(addr, (srv_avrcp_notification_hdlr)mmi_bt_music_avrcp_cb);
        #endif
    }
}
#ifdef __MMI_AVRCP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_avrcp_cmd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  command         [IN]        
 *  key_press       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_bt_music_avrcp_cmd_hdlr(srv_bt_cm_bt_addr *addr, U8 command, mmi_avrcp_key_events key_events) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_AVRCP_CR_ACCEPT;
    srv_bt_cm_bt_addr *addr_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_BT_MUSIC_TRC_AVRCP_HDLR, addr, command, key_events);

    //need to transfer avrcp command to another linked device
    addr_p = mmi_bt_music_get_second_addr(addr);
    if(addr_p)
    {
        mmi_bt_music_send_avrcp_command_by_addr(addr, command);
    }
    
    switch (command)
    {
        case MMI_AVRCP_POP_PLAY:
        {
            mmi_bt_music_set_main_sel_btn(BT_MUSIC_MAIN_PLAY);
            mmi_bt_music_redraw_main_btns_bt();
            break;
        }
        case MMI_AVRCP_POP_PAUSE:
        {
            mmi_bt_music_set_main_sel_btn(BT_MUSIC_MAIN_PAUSE);
            mmi_bt_music_redraw_main_btns_bt();
            break;
        }
        case MMI_AVRCP_POP_STOP:
        {
            break;
        }
        case MMI_AVRCP_POP_FORWARD:
        {
            break;
        }
        case MMI_AVRCP_POP_BACKWARD:
        {
            break;
        }
        case MMI_AVRCP_POP_VOLUME_DOWN:
        {
            mmi_bt_music_dec_vol();
            mmi_bt_music_redraw_volumebar();
            mmi_bt_music_redraw_main_volume_speaker();
            break;
        }
        case MMI_AVRCP_POP_VOLUME_UP:
        {
            mmi_bt_music_inc_vol();
            mmi_bt_music_redraw_volumebar();
            mmi_bt_music_redraw_main_volume_speaker();
            break;
        }
        default:
        {
            result = MMI_AVRCP_CR_NOT_IMPLEMENT;
            break;
        }
    }
    return result;
}
#endif /* __MMI_AVRCP_SUPPORT__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_get_list_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        item index
 *  str_buff        [OUT]       string buffer for item string
 *  img_buff_p      [OUT]       image buffer for item icon
 * RETURNS
 *  pBOOL            TRUE : return the item successfully
 *                  FALSE : didn't find the item
 *****************************************************************************/
pBOOL mmi_bt_music_get_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *list_item_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_item_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(item_index);
    if (list_item_p)
    {
        kal_prompt_trace(
                    MOD_MMI_MEDIA_APP,
                    "mmi_bt_music_get_list_item: %d:%d:%d",
                    list_item_p->bd_addr.lap,
                    list_item_p->bd_addr.nap,
                    list_item_p->bd_addr.uap);
        
        mmi_bt_music_registe_connected_dev_AVRCP_callback(&list_item_p->bd_addr);
        /*
        #ifdef __MMI_AVRCP_SUPPORT__
        mmi_bt_avrcp_set_cmd_hdlr(mmi_bt_music_avrcp_cmd_hdlr);
        #endif 
        */
        //mmi_bt_music_reg_avrcp_reverse_control();
        
        srv_bt_cm_get_dev_ucs2_name(
                        &list_item_p->bd_addr,
                        SRV_BT_CM_BD_UCS2_NAME_LEN,
                        (WCHAR*)str_buff);
    
        //*img_buff_p = (PU8)mmi_bt_get_device_image(list_item_p->cod);
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_get_device_name_async
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  s32
 *****************************************************************************/ 
static S32 mmi_bt_music_get_device_name_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i= 0; i < data_size; i++)
    {
        idx = start_index + i;

        #ifdef __MMI_AUDIO_PLAYER__
        if(idx == 0)
        {
          if(!g_is_enter_local_list)
            kal_wsprintf(
                    menu_data[i].item_list[0],
                    "%w",
                    (U16*)GetString(STR_ID_OPTION_LOCAL_MUSIC));
          else
            kal_wsprintf(
                    menu_data[i].item_list[0],
                    "%w",
                    (U16*)GetString(STR_ID_OPTION_LOCAL_LIST));			
        }
        else
        #endif
        {
        #ifdef __MMI_AUDIO_PLAYER__
            --idx;
		#endif
            mmi_bt_music_get_list_item(idx, menu_data[i].item_list[0], &menu_data[i].image_list[0]);
        }
    }
    return data_size;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_dev_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index       [IN]                
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_bt_music_dev_list_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *list_item_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_HIGHLIGHT_DEV_ADDR, item_index);

#ifdef __MMI_AUDIO_PLAYER__
    if (item_index == 0)
    {
	    if(!g_is_enter_local_list)
    	{
        SetLeftSoftkeyFunction(mmi_bt_music_entry_local_music, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_bt_music_entry_local_music, KEY_EVENT_UP);
    	}
	    else
		{
          SetLeftSoftkeyFunction(mmi_bt_music_entry_local_list, KEY_EVENT_UP);
          SetCenterSoftkeyFunction(mmi_bt_music_entry_local_list, KEY_EVENT_UP);
	    }
    }
    else
#endif /*__MMI_AUDIO_PLAYER__*/
    {
    #ifdef __MMI_AUDIO_PLAYER__
        --item_index;
    #endif
        list_item_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info((U32) item_index);
        if(list_item_p)
        {
            g_bt_music_dev.highlight_id = (U8)item_index;
            g_bt_music_dev.device_address = &list_item_p->bd_addr;
            SetCenterSoftkeyFunction(mmi_bt_music_enter_select_device_scrn, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(mmi_bt_music_enter_select_device_scrn, KEY_EVENT_UP);
			MMI_TRACE(
                MMI_MEDIA_TRC_G2_APP,
                MMI_TRC_BT_MUSIC_HIGHLIGHT_DEV_ADDR_INFO,
                g_bt_music_dev.device_address->lap,
                g_bt_music_dev.device_address->nap,
                g_bt_music_dev.device_address->uap); 
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_HIGHLIGHT_DEV_ADDR_NULL);
        }
    }
}
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_dev_list_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_music_dev_list_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
    #ifdef __MMI_AUDIO_PLAYER__
        if (index == 0)
        {
            mmi_bt_music_entry_local_music();
        }
        else
	#endif /*__MMI_AUDIO_PLAYER__*/
        {
            if (g_bt_music_dev.device_address)
            {
                mmi_bt_music_enter_select_device_scrn();
            }
        }
    }
    return;
}
#endif //(__MMI_FTE_SUPPORT__) && (__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_device_list_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/ 
void mmi_bt_music_device_list_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 link_dev_num;
	U8 num_of_items = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
                    GRP_ID_BT_MUSIC_APP,
                    SCR_ID_BT_MUSIC_DEVICE_LIST,
                    NULL,
                    mmi_bt_music_device_list_entry,
                    MMI_FRM_FULL_SCRN))
    {
        /*get device num  */
        link_dev_num = srv_bt_cm_get_linked_dev_list_idx();
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_DEVICE_LIST_ENTRY, link_dev_num);
        
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        RegisterHighlightHandler(mmi_bt_music_dev_list_highlight_hdlr);

		#ifdef __MMI_AUDIO_PLAYER__
		num_of_items = link_dev_num + 1;
		#else
		num_of_items = link_dev_num;
		#endif

		wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NO_ICON);
        wgui_cat1032_show(
		#ifdef __MMI_AUDIO_PLAYER_BT__
		    (WCHAR*)GetString(STR_ID_AUDPLY_TITLE),
		#else /*__MMI_AUDIO_PLAYER_BT__*/
                    (WCHAR*)GetString(STR_ID_BT_MUSIC_TITLE),
                #endif /*__MMI_AUDIO_PLAYER_BT__*/
                    //get_image(GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID)),
                    NULL,
                    (WCHAR*)GetString(STR_GLOBAL_OK),
                    (PU8)GetImage(IMG_GLOBAL_OK),
                    get_string(STR_GLOBAL_BACK),
                    get_image(IMG_GLOBAL_BACK),
                    num_of_items,
                    mmi_bt_music_get_device_name_async,
                    0,
                    0,
                    0,    
                    0,
                    0,
                    guiBuffer,
                    NULL);
		wgui_restore_list_menu_slim_style();
		//g_is_enter_local_list = MMI_FALSE;
        #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_bt_music_dev_list_tap_callback);
        #endif
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
} 

#endif //__MMI_BT_MUSIC__||__MMI_AUDIO_PLAYER_BT__
