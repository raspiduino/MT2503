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
 * BTMMIAntilostScr.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MMI screen of bluetooth anti-lost eature.
 *
 * Author:
 * -------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Included files
*****************************************************************************/
#include "MMI_features.h"
#include "BTMMIScrGprots.h"
#include "BTMMIScr.h"

#include "ProfilesSrvGprot.h"
#include "Wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "gui_touch_feedback.h"

#include "GlobalResDef.h"
#include "CommonScreens.h"
#include "gpiosrvgprot.h"
#include "mmi_rp_app_profiles_def.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "BTMMIAntilostScr.h"
#include "Bluetooth_gap_struct.h"

#ifdef __MMI_BT_BTBOX_NOLCD__
#include "A2dpSrvGprot.h"
#include "Mmi_frm_input_event.h"
#endif /* __MMI_BT_BTBOX_NOLCD__ */

/***************************************************************************** 
 * External Variable
 *****************************************************************************/
 
/***************************************************************************** 
 * External functions
 *****************************************************************************/
extern void srv_bt_cm_copy_addr(void *dest,void *src);
 
/*****************************************************************
*Internal functions
*****************************************************************/
static void mmi_bt_anti_lost_read_rssi_cnf(void* msg);
static mmi_bt_anti_lost_alert_mode_enum mmi_bt_anti_lost_get_alert_mode(void);
void mmi_bt_cm_anti_lost_hdr(void* msg);
MMI_BOOL mmi_bt_antilost_ind_nmgr_callback(mmi_scenario_id scen_id, void *arg);
void mmi_bt_anti_lost_entry_indication_screen_ext(mmi_scrn_essential_struct* scr_info);
void mmi_bt_anti_lost_ind_lsk_hdlr_ext(void);
void mmi_bt_anti_lost_indication_cancle_hdlr_ext(void);
mmi_ret mmi_bt_anti_lost_ind_proc(mmi_event_struct* evt);
mmi_ret mmi_bt_anti_lost_indication_screen_delete_proc_ext(mmi_event_struct* evt);
U32 mmi_bt_anti_lost_list_get_idx(srv_bt_cm_bt_addr* mmi_bt_anti_lost_addr);
void mmi_bt_anti_lost_ind_lsk_hdlr_time_out(void *arg);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/*static srv_bt_cm_bt_addr* g_mmi_bt_anti_lost_addr;*/
/* items common structure */
typedef struct 
{
    S16 index;
    srv_bt_cm_bt_addr mmi_bt_anti_lost_addr;
}mmi_bt_anti_lost_ind_scr_struct;

mmi_bt_anti_lost_ind_scr_struct g_mmi_bt_anti_lost_ind[BT_DEVICE_LINK_NUM];

static U16 g_mmi_bt_anti_lost_status_str_id[] = 
{
    STR_GLOBAL_OFF,
    STR_GLOBAL_ON,  
};

const static U16 g_mmi_bt_anti_lost_alert_str_id[MMI_BT_ANTI_LOST_ALERT_MODE_TOTAL]=
{
	STR_ID_PROF_VIB_AND_RING,
	STR_ID_PROF_RING_ONLY,
	STR_ID_PROF_VIB_ONLY
};

static cui_inline_item_caption_struct g_mmi_bt_anti_lost_status_caption = {STR_BT_SET_ANTI_LOST_STATUS} ;

static cui_inline_item_select_struct g_mmi_bt_anti_lost_status_select =
{
    2,
    0,
    g_mmi_bt_anti_lost_status_str_id
};

static cui_inline_item_caption_struct g_mmi_bt_anti_lost_mode_caption = {STR_BT_ANTI_LOST_ALERT_TYPE} ;

static const cui_inline_item_select_struct g_mmi_bt_anti_lost_alert_select = 
{
    MMI_BT_ANTI_LOST_ALERT_MODE_TOTAL, 
	0, 
	g_mmi_bt_anti_lost_alert_str_id
};

const static cui_inline_set_item_struct g_mmi_bt_anti_lost_inline_data[] =
{
    {BT_ANTI_LOST_SET_STATUS_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, NULL, &g_mmi_bt_anti_lost_status_caption},
    {BT_ANTI_LOST_SET_STATUS, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_mmi_bt_anti_lost_status_select},
    {BT_ANTI_LOST_SET_ALERT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, NULL, &g_mmi_bt_anti_lost_mode_caption},
	{BT_ANTI_LOST_SET_ALERT_MODE,CUI_INLINE_ITEM_TYPE_SELECT,0, &g_mmi_bt_anti_lost_alert_select}
};

static const cui_inline_struct g_mmi_bt_anti_lost_inline = 
{
    sizeof(g_mmi_bt_anti_lost_inline_data)/sizeof(cui_inline_set_item_struct),
    STR_BT_SET_ANTI_LOST,
    NULL,
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_mmi_bt_anti_lost_inline_data    
};


/* items common structure */
typedef struct 
{
#ifdef __MMI_BT_BTBOX_NOLCD__
    U8 times;
    U8 curr_times;
#endif /* __MMI_BT_BTBOX_NOLCD__ */
    S16 curr_status;
    S16 alert_mode;
    MMI_BOOL need_slow_timer; /* After 1st  reminder, it will user show  timer to show reminder again. */
}mmi_bt_anti_lost_cntx_struct;


static mmi_bt_anti_lost_cntx_struct g_mmi_bt_anti_lost_cntx;


/*****************************************************************************
 * Functions
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_read_rssi_req
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  srv_bt_cm_bt_addr *bt_addr
 * RETURNS
 *  N/A.
 *****************************************************************************/
void mmi_bt_anti_lost_read_rssi_req(srv_bt_cm_bt_addr *bt_addr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	bt_read_rssi_req_struct* msg_p;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	msg_p = (bt_read_rssi_req_struct*)construct_local_para(
											sizeof(bt_read_rssi_req_struct),
											TD_CTRL);
	msg_p->lap = bt_addr->lap;
	msg_p->nap = bt_addr->nap;
	msg_p->uap = bt_addr->uap;
	
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_READ_RSSI_REQ_FUNC, msg_p->lap, msg_p->nap, msg_p->uap);
	srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_READ_RSSI_REQ, (void*)msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_enable_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_bt_cm_bt_addr   *bt_addr
 *  MMI_BOOL                enbale
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_anti_lost_enable_req(srv_bt_cm_bt_addr *bt_addr , MMI_BOOL enbale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_report_low_power_prxm_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_report_low_power_prxm_req_struct*)construct_local_para(
                                                    sizeof(bt_report_low_power_prxm_req_struct),
                                                    TD_CTRL);
    msg_p->enable = enbale;
    msg_p->bd_addr.lap = bt_addr->lap;
    msg_p->bd_addr.nap= bt_addr->nap;
    msg_p->bd_addr.uap= bt_addr->uap;

    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_REPORT_LOW_POWER_PRXM_REQ, (void*)msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_init
 * DESCRIPTION
 *  This function is to init anti-lost global variable
 * PARAMETERS
 *  void         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_anti_lost_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												*/
	/*----------------------------------------------------------------*/
	S16 error;
    
	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/
#ifdef __MMI_BT_BTBOX_NOLCD__
    ReadValue(NVRAM_BT_ANTI_LOST_CONFIG, &(g_mmi_bt_anti_lost_cntx.times), DS_BYTE, &error);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
        MMI_BT_ANTILOST_INIT, 
        g_mmi_bt_anti_lost_cntx.times,
        g_mmi_bt_anti_lost_cntx.curr_times);
    SetProtocolEventHandler(mmi_bt_cm_anti_lost_hdr, MSG_ID_BT_REPORT_LOW_POWER_PRXM_IND);
#else /* __MMI_BT_BTBOX_NOLCD__ */
    ReadValue(NVRAM_BT_ANTI_LOST_STATUS, &(g_mmi_bt_anti_lost_cntx.curr_status), DS_BYTE, &error);
    ReadValue(NVRAM_BT_ANTI_LOST_ALERT_MODE, &(g_mmi_bt_anti_lost_cntx.alert_mode), DS_BYTE, &error);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_INIT_FUNC, g_mmi_bt_anti_lost_cntx.curr_status, g_mmi_bt_anti_lost_cntx.alert_mode);
#if 1	
	if (g_mmi_bt_anti_lost_cntx.curr_status == 1)
    {
        SetProtocolEventHandler(mmi_bt_cm_anti_lost_hdr, MSG_ID_BT_REPORT_LOW_POWER_PRXM_IND);
    }
    if (g_mmi_bt_anti_lost_cntx.curr_status == 0xFF)
    {
        g_mmi_bt_anti_lost_cntx.curr_status = 0;
        WriteValue(NVRAM_BT_ANTI_LOST_STATUS, &(g_mmi_bt_anti_lost_cntx.curr_status), DS_BYTE, &error);
        ClearProtocolEventHandler(MSG_ID_BT_REPORT_LOW_POWER_PRXM_IND);
    }
    if (g_mmi_bt_anti_lost_cntx.alert_mode == 0xFF)
    {
        g_mmi_bt_anti_lost_cntx.alert_mode = 0;
        WriteValue(NVRAM_BT_ANTI_LOST_ALERT_MODE, &(g_mmi_bt_anti_lost_cntx.alert_mode), DS_BYTE, &error);
    }
  #endif
#endif /* __MMI_BT_BTBOX_NOLCD__ */

    memset(g_mmi_bt_anti_lost_ind,0,sizeof(mmi_bt_anti_lost_ind_scr_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_get_status
 * DESCRIPTION
 *  This function is to get anti-lost status on/off
 * PARAMETERS
 *  void         
 * RETURNS
 *  0 OFF, 1 ON
 *****************************************************************************/
mmi_bt_anti_lost_status_enum mmi_bt_anti_lost_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_GET_STATUS, g_mmi_bt_anti_lost_cntx.curr_status);
    
    if (g_mmi_bt_anti_lost_cntx.curr_status == 1)
    {
        return MMI_BT_ANTI_LOST_ON;
    }

    return MMI_BT_ANTI_LOST_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_get_alert_mode
 * DESCRIPTION
 *  This function is to get anti-lost alert type
 * PARAMETERS
 *  void         
 * RETURNS
 *  0 , 1 ,2
 *****************************************************************************/
mmi_bt_anti_lost_alert_mode_enum mmi_bt_anti_lost_get_alert_mode(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_GET_ALERTMODE, g_mmi_bt_anti_lost_cntx.alert_mode);
    
    if (g_mmi_bt_anti_lost_cntx.alert_mode < MMI_BT_ANTI_LOST_ALERT_MODE_TOTAL)
    {
        return (mmi_bt_anti_lost_alert_mode_enum)g_mmi_bt_anti_lost_cntx.alert_mode;
    }
    
    return MMI_BT_ANTI_LOST_VIBRATION_AND_RING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_setting_lsk_hdlr
 * DESCRIPTION
 *  This function is left softkey handler for connectivity->bluetooth->anti lost ->edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_anti_lost_setting_lsk_hdlr(void)
{
#ifndef __MMI_BT_BTBOX_NOLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MMI_ID *inlinecui_gid = mmi_frm_group_get_user_data(GRP_ID_BT_ANTI_LOST_SETTING);
    U8 status;
    U8 alert_mode;
    U32 dev_num = srv_bt_cm_get_linked_dev_list_idx();
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_ENTRY_SETTING_LSK, g_mmi_bt_anti_lost_cntx.curr_status, g_mmi_bt_anti_lost_cntx.alert_mode);
    
    cui_inline_get_value(*inlinecui_gid, BT_ANTI_LOST_SET_STATUS, (void*)&status);
    g_mmi_bt_anti_lost_cntx.curr_status = status;
    WriteValue(NVRAM_BT_ANTI_LOST_STATUS, &(g_mmi_bt_anti_lost_cntx.curr_status), DS_BYTE, &error);
    if (g_mmi_bt_anti_lost_cntx.curr_status == 1)
    {
        SetProtocolEventHandler(mmi_bt_cm_anti_lost_hdr, MSG_ID_BT_REPORT_LOW_POWER_PRXM_IND);
        if(dev_num > 0)
        {
            for(i = 0; i < dev_num; i++)
            {
                srv_bt_cm_dev_struct* dev_p =(srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(i);
                MMI_BOOL enbale = MMI_TRUE;
                mmi_bt_anti_lost_enable_req(&dev_p->bd_addr,enbale);
            }
        }
    }
    else
    {
        ClearProtocolEventHandler(MSG_ID_BT_REPORT_LOW_POWER_PRXM_IND);
        if(dev_num > 0)
        {
            for(i = 0; i < dev_num; i++)
            {
               srv_bt_cm_dev_struct* dev_p =(srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(i);
               MMI_BOOL enbale = MMI_FALSE;
               mmi_bt_anti_lost_enable_req(&dev_p->bd_addr,enbale);
            }
        }
    }

    cui_inline_get_value(*inlinecui_gid, BT_ANTI_LOST_SET_ALERT_MODE, (void*)&alert_mode);
    g_mmi_bt_anti_lost_cntx.alert_mode = alert_mode;
    WriteValue(NVRAM_BT_ANTI_LOST_ALERT_MODE, &(g_mmi_bt_anti_lost_cntx.alert_mode), DS_BYTE, &error);
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);    
    mmi_frm_group_close(GRP_ID_BT_ANTI_LOST_SETTING);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_ENTRY_SETTING_SAVE, status, alert_mode);
#endif /* __MMI_BT_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_setting_proc
 * DESCRIPTION
 *  Proc function for anti lost setting 
 * PARAMETERS
 * 
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_bt_anti_lost_setting_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID *inlinecui_gid =(MMI_ID*)mmi_frm_group_get_user_data(GRP_ID_BT_ANTI_LOST_SETTING);
    U8 highlighted_item;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:        
            mmi_bt_anti_lost_setting_lsk_hdlr();
            break;
        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(*inlinecui_gid);
            break;
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify_event = (cui_event_inline_notify_struct*)param;
        #ifndef __INLINE_CUI_SLIM_SELECT_ITEM_STYLE__
            if (notify_event->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
            {
                cui_inline_set_softkey_text(
                    notify_event->sender_id, 
                    notify_event->item_id,
                    MMI_LEFT_SOFTKEY,
                    STR_GLOBAL_SAVE);
            }
        #endif /* __INLINE_CUI_SLIM_SELECT_ITEM_STYLE__ */
            if (notify_event->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
            {
                switch (notify_event->item_id)
                {
                    case BT_ANTI_LOST_SET_STATUS:
                        cui_inline_get_value(
                            *inlinecui_gid,
                            BT_ANTI_LOST_SET_STATUS,
                            (void*) &highlighted_item);                   
                        break;  
		    case BT_ANTI_LOST_SET_ALERT_MODE:
			cui_inline_get_value(
				*inlinecui_gid,
				BT_ANTI_LOST_SET_ALERT_MODE,
				(void*) &highlighted_item);                   
			break;
		}
            }
            break;
        }   

        case EVT_ID_GROUP_DEINIT:
	    if (param->user_data)
	    {
		OslMfree(param->user_data);
		param->user_data = NULL;
	    }
	    break;

        default:
	    break;
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
 * FUNCTION
 * mmi_bt_entry_anti_lost_setting
 * DESCRIPTION
 * entry function for anti lost setting
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_anti_lost_setting(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables											  */
	/*----------------------------------------------------------------*/
	MMI_ID *inlinecui_gid;
        
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT,MMI_BT_ANTILOST_ENTRY_SETTING);

	if (mmi_frm_group_is_present(GRP_ID_BT_ANTI_LOST_IND))
	 {
         return;
	 }

    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_ANTILOST_SET);
	if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
        MMI_BT_SET_FLAG(MMI_BT_CONFIRM_ANTILOST_SET);
        mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.main_gid);
        return;
    }

	inlinecui_gid = (MMI_ID*)OslMalloc(sizeof(MMI_ID));
	mmi_frm_group_create_ex(
		g_mmi_bt_scr_cntx.main_gid,
		GRP_ID_BT_ANTI_LOST_SETTING,
		mmi_bt_anti_lost_setting_proc,
		(void*)inlinecui_gid,
		MMI_FRM_NODE_SMART_CLOSE_FLAG);

	*inlinecui_gid = cui_inline_create(GRP_ID_BT_ANTI_LOST_SETTING, &g_mmi_bt_anti_lost_inline);
	cui_inline_set_value(*inlinecui_gid, BT_ANTI_LOST_SET_STATUS, (void*)g_mmi_bt_anti_lost_cntx.curr_status);
	cui_inline_set_value(*inlinecui_gid, BT_ANTI_LOST_SET_ALERT_MODE, (void*)g_mmi_bt_anti_lost_cntx.alert_mode);
	cui_inline_run(*inlinecui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_play_ringtone
 * DESCRIPTION
 *  play ringtone when alert
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_anti_lost_play_ringtone(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_prof_play_req_struct play_req;    
	srv_prof_play_req_struct_init(&play_req, SRV_PROF_TONE_REMIND);
	/*----------------------------------------------------------------*/
	/* Code	Body									                  */
	/*----------------------------------------------------------------*/
	play_req.volume = 4;
	play_req.aud_path = MDI_DEVICE_LOUDSPEAKER;
	play_req.play_style = SRV_PROF_RING_TYPE_REPEAT;
	play_req.audio_id = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_RING, 0);
	play_req.callback = NULL;
	play_req.audio_type = SRV_PROF_AUDIO_STRING;
	srv_prof_play_tone_with_full_struct(&play_req);
}

/*****************************************************************************
 * FUNCTION
 * mmi_bt_antilost_clear_alertmode
 * DESCRIPTION
 *  clear alert
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_antilost_clear_alertmode(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												*/
	/*----------------------------------------------------------------*/
    mmi_bt_anti_lost_alert_mode_enum mode = mmi_bt_anti_lost_get_alert_mode();
    
	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_CLEAR_ALM_FUNC, mode);
            		
    if (mode == MMI_BT_ANTI_LOST_VIBRATION_AND_RING || mode == MMI_BT_ANTI_LOST_VIBRATION);
    {
        srv_vibrator_off();
    }
    
    if (mode == MMI_BT_ANTI_LOST_VIBRATION_AND_RING || mode == MMI_BT_ANTI_LOST_RING);
    {
        srv_prof_stop_tone(SRV_PROF_TONE_REMIND);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_antilost_alert
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  N/A.
 * RETURNS
 *  N/A.
 *****************************************************************************/

static void mmi_bt_antilost_alert(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_bt_anti_lost_alert_mode_enum alert_mode;
	MMI_BOOL is_play_tone = MMI_FALSE;
	MMI_BOOL is_play_vib  = MMI_FALSE;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_ALERT_FUNC);

    if (!mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
    {
		alert_mode = mmi_bt_anti_lost_get_alert_mode();
		switch(alert_mode)
		{
			case MMI_BT_ANTI_LOST_VIBRATION_AND_RING:
				is_play_tone = MMI_TRUE;
				is_play_vib = MMI_TRUE;
				break;
				
			case MMI_BT_ANTI_LOST_RING:
				is_play_tone = MMI_TRUE;
				break;

			case MMI_BT_ANTI_LOST_VIBRATION:
				is_play_vib = MMI_TRUE;
				break;	
			
			default:
				break;
	    }
        
	    if (is_play_tone)
	    {
		    mmi_bt_anti_lost_play_ringtone();
	    }
    
	    if (is_play_vib)
	    {
		    srv_vibrator_on();
		    gui_touch_feedback_disable_vibrate();
        }
    }
    else
    {
        srv_prof_play_tone(SRV_PROF_TONE_SMS_INCALL, NULL);
    }
       
}


/*****************************************************************************
 * FUNCTION
 * mmi_bt_anti_lost_exit_ind_scr
 * DESCRIPTION
 * entry function for  anti lost alert indication screen
 * PARAMETERS
 * void
 * RETURNS
 * void
 *****************************************************************************/
void mmi_bt_anti_lost_exit_ind_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_backlight_turn_off();
	mmi_bt_antilost_clear_alertmode();	
	mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_read_rssi_cnf
 * DESCRIPTION
 * hdlr for event  .
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_bt_anti_lost_read_rssi_cnf(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bt_addr *dev_addr;
    U32 anti_lost_idx;
    bt_read_rssi_cnf_struct* read_rssi_ind = (bt_read_rssi_cnf_struct*)msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_RSSI_CNF_FUNC, 
    read_rssi_ind->rssi_value, 
    read_rssi_ind->result,
    read_rssi_ind->lap,
    read_rssi_ind->uap,
    read_rssi_ind->nap);

    if (read_rssi_ind->result == 0)	
    {   
        if (read_rssi_ind->rssi_value < BT_ANTI_LOST_CFG_RSSI_ALERT_THRESHOLD)
        {
            dev_addr->lap = read_rssi_ind->lap;		
            dev_addr->uap= read_rssi_ind->uap;
            dev_addr->nap = read_rssi_ind->nap;
            anti_lost_idx = mmi_bt_anti_lost_list_get_idx(dev_addr);
            if (anti_lost_idx != -1) 
            {
                if (!mmi_frm_scrn_is_present(GRP_ID_BT_ANTI_LOST_IND, 
											SCR_ID_BT_ANTI_LOST_IND + anti_lost_idx, 
											MMI_FRM_NODE_ALL_FLAG))
                {
                    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_RSSI_CNF_SCR_PRESENT, SCR_ID_BT_ANTI_LOST_IND, anti_lost_idx);
                    mmi_frm_nmgr_notify_by_app(
		                MMI_SCENARIO_ID_HIGH_SCRN,
		                 MMI_EVENT_WARNING,
		                 mmi_bt_antilost_ind_nmgr_callback,
		                 &g_mmi_bt_anti_lost_ind[anti_lost_idx]);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_cm_anti_lost_hdr
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  N/A.
 * RETURNS
 *  N/A.
 *****************************************************************************/
void mmi_bt_cm_anti_lost_hdr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bt_addr dev_addr;
    static U32 anti_lost_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bt_report_low_power_prxm_ind_struct* anti_lost_data = (bt_report_low_power_prxm_ind_struct*) msg;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_HDR_FUNC,
		anti_lost_data->rssi_value, 
		anti_lost_data->lap,
		anti_lost_data->uap, 
		anti_lost_data->nap, 
		anti_lost_data->threshold);

    /*dev_addr = (srv_bt_cm_bt_addr*)OslMalloc(sizeof(srv_bt_cm_bt_addr));*/
    dev_addr.lap = anti_lost_data->lap;
    dev_addr.uap = anti_lost_data->uap;
    dev_addr.nap = anti_lost_data->nap;

    if(anti_lost_data->rssi_value <= anti_lost_data->threshold)// for test remove.
    {
        anti_lost_idx = mmi_bt_anti_lost_list_get_idx(&dev_addr);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_HDR_CONTINUE, anti_lost_idx);
        if (anti_lost_idx != -1)
        {
        #ifndef __MMI_BT_BTBOX_NOLCD__
            if (!mmi_frm_scrn_is_present(GRP_ID_BT_ANTI_LOST_IND, SCR_ID_BT_ANTI_LOST_IND + anti_lost_idx, MMI_FRM_NODE_ALL_FLAG))
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_HDR_SCR_PRESENT, SCR_ID_BT_ANTI_LOST_IND, anti_lost_idx);
                mmi_frm_nmgr_notify_by_app(
                    MMI_SCENARIO_ID_HIGH_SCRN,
                    MMI_EVENT_WARNING,
                    mmi_bt_antilost_ind_nmgr_callback,
                    &g_mmi_bt_anti_lost_ind[anti_lost_idx]);
            }
        #else /* __MMI_BT_BTBOX_NOLCD__ */
            mmi_bt_anti_lost_notify_hdlr(&anti_lost_idx);
        #endif /* __MMI_BT_BTBOX_NOLCD__ */
        }
    }
#ifdef __MMI_BT_BTBOX_NOLCD__
    else 
    {
        anti_lost_idx = mmi_bt_anti_lost_list_get_idx(&dev_addr);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_HDR_TIMEOUT, anti_lost_idx);
        if (anti_lost_idx != -1)
        {
            StopTimer(BT_ANTI_LOST_ALARM_DURATION_TIMER);
            g_mmi_bt_anti_lost_cntx.curr_times = 0;
        }
    }
#endif /* __MMI_BT_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_antilost_ind_nmgr_callback
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  N/A.
 * RETURNS
 *  N/A.
 *****************************************************************************/
MMI_BOOL mmi_bt_antilost_ind_nmgr_callback(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_anti_lost_ind_scr_struct *ind;
    ind = (mmi_bt_anti_lost_ind_scr_struct*)arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_IND_NMGR_CALLBACK, 
		ind->index, 
		ind->mmi_bt_anti_lost_addr.lap, 
		ind->mmi_bt_anti_lost_addr.uap, 
		ind->mmi_bt_anti_lost_addr.nap);

    if (!mmi_frm_group_is_present(GRP_ID_BT_ANTI_LOST_IND))
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_IND_GROUP_IS_PRESENT);
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BT_ANTI_LOST_IND, mmi_bt_anti_lost_ind_proc, NULL);
        mmi_frm_group_enter(GRP_ID_BT_ANTI_LOST_IND, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    mmi_frm_scrn_first_enter(
        GRP_ID_BT_ANTI_LOST_IND, 
        SCR_ID_BT_ANTI_LOST_IND+ (ind->index), 
        (FuncPtr)mmi_bt_anti_lost_entry_indication_screen_ext, 
        ind);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_entry_indication_screen_ext
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  N/A.
 * RETURNS
 *  N/A.
 *****************************************************************************/
void mmi_bt_anti_lost_entry_indication_screen_ext(mmi_scrn_essential_struct* scr_info)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 *guiBuffer;
	static mmi_bt_anti_lost_ind_scr_struct *ind;
	srv_bt_cm_dev_struct* dev_p ;
	static WCHAR string[100] = {0};
	ind = (mmi_bt_anti_lost_ind_scr_struct*)scr_info->user_data;
	dev_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_dev_info(&ind->mmi_bt_anti_lost_addr);

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_IND_EXT_FUNC,	
        ind->index, 
		ind->mmi_bt_anti_lost_addr.lap, 
		ind->mmi_bt_anti_lost_addr.uap, 
		ind->mmi_bt_anti_lost_addr.nap);
    
	if (!mmi_frm_scrn_enter(
			GRP_ID_BT_ANTI_LOST_IND, 
			SCR_ID_BT_ANTI_LOST_IND+(ind->index), 
			mmi_bt_anti_lost_exit_ind_scr, 
			(FuncPtr)mmi_bt_anti_lost_entry_indication_screen_ext, 
			MMI_FRM_FULL_SCRN))
	{
		mmi_frm_scrn_set_leave_proc(GRP_ID_BT_ANTI_LOST_IND, 
									SCR_ID_BT_ANTI_LOST_IND+(ind->index), 
									mmi_bt_anti_lost_indication_screen_delete_proc_ext);
		return;
	}
    
	mmi_frm_scrn_set_leave_proc(GRP_ID_BT_ANTI_LOST_IND, 
								SCR_ID_BT_ANTI_LOST_IND+(ind->index), 
								mmi_bt_anti_lost_indication_screen_delete_proc_ext);

    mmi_bt_antilost_alert();
    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

	//ClearKeyEvents();
	ClearAllKeyHandler();
	guiBuffer = mmi_frm_scrn_get_active_gui_buf();
	 
	srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

	mmi_chset_utf8_to_ucs2_string((kal_uint8*)string, (SRV_BT_CM_BD_UCS2_NAME_LEN * 2), (kal_uint8*)dev_p->name);
	//mmi_wcscat((WCHAR*)string, (WCHAR*)GetString(STR_BT_ANTI_LOST_NOTIFY));
	 kal_prompt_trace(MOD_MMI, "[btconn]anti lost STRING = %s", string);
	 mmi_ucs2cat((CHAR*) string, (CHAR*) GetString(STR_BT_ANTI_LOST_NOTIFY));
	ShowCategory121Screen(
		STR_GLOBAL_OK,
		0,
		0,
		0,
		(U8*)string,
		NULL,
		guiBuffer,
		1);
	g_mmi_bt_anti_lost_ind[ind->index].index = ind->index;
	StartTimerEx(BT_ANTI_LOST_ALARM_DURATION_TIMER+(ind->index), 
	        MMI_BT_ANTI_LOST_ALARM_DURATION, 
	        mmi_bt_anti_lost_ind_lsk_hdlr_time_out,
	        &g_mmi_bt_anti_lost_ind[ind->index]);
	SetLeftSoftkeyFunction(mmi_bt_anti_lost_ind_lsk_hdlr_ext, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_bt_anti_lost_ind_lsk_hdlr_ext, KEY_EVENT_UP);
	//SetRightSoftkeyFunction(mmi_bt_anti_lost_indication_cancle_hdlr_ext, KEY_EVENT_UP); //4/2
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_ind_lsk_hdlr_time_out
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  N/A.
 * RETURNS
 *  N/A.
 *****************************************************************************/
void mmi_bt_anti_lost_ind_lsk_hdlr_time_out(void* arg)
{
    /*----------------------------------------------------------------*/
	/* Local Variables												*/
	/*----------------------------------------------------------------*/
	
    mmi_bt_anti_lost_ind_scr_struct* anti_devp = (mmi_bt_anti_lost_ind_scr_struct*)arg;
	
	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_IND_LSK_TIME_OUT_FUNC, anti_devp->index);

	if(!mmi_bt_dialer_app_is_connected_ex(&anti_devp->mmi_bt_anti_lost_addr))
	{
		memset(&g_mmi_bt_anti_lost_ind[anti_devp->index],0,sizeof(mmi_bt_anti_lost_ind_scr_struct));

	}
	
	mmi_bt_anti_lost_close_scr(&anti_devp->mmi_bt_anti_lost_addr);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_ind_lsk_hdlr_ext
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  N/A.
 * RETURNS
 *  N/A.
 *****************************************************************************/
void mmi_bt_anti_lost_ind_lsk_hdlr_ext(void)
{
    /*----------------------------------------------------------------*/
	/* Local Variables												*/
	/*----------------------------------------------------------------*/
	
    MMI_ID scrn_id;
	
	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/
	scrn_id = mmi_frm_scrn_get_active_id();
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_IND_LSK_EXT_FUNC, scrn_id);
	if(!mmi_bt_dialer_app_is_connected_ex(&g_mmi_bt_anti_lost_ind[scrn_id-SCR_ID_BT_ANTI_LOST_IND].mmi_bt_anti_lost_addr))
	{
		memset(&g_mmi_bt_anti_lost_ind[scrn_id-SCR_ID_BT_ANTI_LOST_IND],0,sizeof(mmi_bt_anti_lost_ind_scr_struct));

	}
    mmi_bt_antilost_clear_alertmode();	
	mmi_frm_scrn_close_active_id();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_indication_cancle_hdlr_ext
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  N/A.
 * RETURNS
 *  N/A.
 *****************************************************************************/
void mmi_bt_anti_lost_indication_cancle_hdlr_ext(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												*/
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_IND_CANCEL_EXT_FUNC);
    
    mmi_bt_antilost_clear_alertmode();
	mmi_frm_scrn_close_active_id();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_clean_addr
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  N/A.
 * RETURNS
 *  N/A.
 *****************************************************************************/
void mmi_bt_anti_lost_clean_addr(srv_bt_cm_bt_addr* dev_addr1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_CLEAN_ADDR_FUNC,dev_addr1->lap, dev_addr1->uap, dev_addr1->nap);

    for (i=0; i<BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(dev_addr1, &g_mmi_bt_anti_lost_ind[i].mmi_bt_anti_lost_addr))
        {
            memset(&g_mmi_bt_anti_lost_ind[i],0,sizeof(mmi_bt_anti_lost_ind_scr_struct));
        #ifdef __MMI_BT_BTBOX_NOLCD__
            g_mmi_bt_anti_lost_cntx.curr_times = 0;
        #endif /* __MMI_BT_BTBOX_NOLCD__ */
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_ADDR_EQUAL, i);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_add_addr
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  srv_bt_cm_bt_addr* mmi_bt_anti_lost_addr
 * RETURNS
 *  N/A.
 *****************************************************************************/
void mmi_bt_anti_lost_add_addr(srv_bt_cm_bt_addr* mmi_bt_anti_lost_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
	S16 error;
	U32 p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_ADD_ADDR_FUNC,mmi_bt_anti_lost_addr->lap,mmi_bt_anti_lost_addr->uap,mmi_bt_anti_lost_addr->nap);

    if(mmi_bt_anti_lost_is_in_list(mmi_bt_anti_lost_addr))
    {
        return;
    }
    for (p = 0; p < BT_DEVICE_LINK_NUM; p++)
    {
        if (mmi_bt_dialer_is_addr_equal_0(&g_mmi_bt_anti_lost_ind[p].mmi_bt_anti_lost_addr))
        {
            g_mmi_bt_anti_lost_ind[p].index = p;
            memcpy(&g_mmi_bt_anti_lost_ind[p].mmi_bt_anti_lost_addr, mmi_bt_anti_lost_addr, sizeof(mmi_bt_anti_lost_ind_scr_struct));
            break;
        }
    }
    if (p == BT_DEVICE_LINK_NUM)
    {
        MMI_ASSERT(0);
    }
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
    #ifdef __MMI_BT_BTBOX_NOLCD__
        g_mmi_bt_anti_lost_cntx.curr_times = 0;
    #endif /* __MMI_BT_BTBOX_NOLCD__ */
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_ANTI_LOST_ADD_DEV_INFOR, 
            i, 
            g_mmi_bt_anti_lost_ind[i].mmi_bt_anti_lost_addr.lap,
            g_mmi_bt_anti_lost_ind[i].mmi_bt_anti_lost_addr.nap,
            g_mmi_bt_anti_lost_ind[i].mmi_bt_anti_lost_addr.uap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_is_in_list
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  srv_bt_cm_bt_addr* mmi_bt_anti_lost_addr
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_anti_lost_is_in_list(srv_bt_cm_bt_addr* mmi_bt_anti_lost_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_IS_IN_LIST_FUNC);

    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(mmi_bt_anti_lost_addr, &g_mmi_bt_anti_lost_ind[i].mmi_bt_anti_lost_addr))
        {
            return MMI_TRUE;	
        }
    }
    
    return MMI_FALSE; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_list_get_idx
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  srv_bt_cm_bt_addr* mmi_bt_anti_lost_addr
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_bt_anti_lost_list_get_idx(srv_bt_cm_bt_addr* mmi_bt_anti_lost_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_GET_IDX_FUNC);
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(mmi_bt_anti_lost_addr, &g_mmi_bt_anti_lost_ind[i].mmi_bt_anti_lost_addr))
        {
            return i;	
        }
    }

    return -1; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_close_scr
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  srv_bt_cm_bt_addr* mmi_bt_anti_lost_addr
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_anti_lost_close_scr(srv_bt_cm_bt_addr* mmi_bt_anti_lost_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U32 scr_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    scr_idx = mmi_bt_anti_lost_list_get_idx(mmi_bt_anti_lost_addr);
	
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_CLOSE_SCR_FUNC, 
		scr_idx,
		mmi_bt_anti_lost_addr->lap,
		mmi_bt_anti_lost_addr->nap,
		mmi_bt_anti_lost_addr->uap);

    if(scr_idx != -1)
    {
        if (mmi_frm_scrn_is_present(GRP_ID_BT_ANTI_LOST_IND, SCR_ID_BT_ANTI_LOST_IND + scr_idx, MMI_FRM_NODE_ALL_FLAG))
       	{
            mmi_frm_scrn_close(GRP_ID_BT_ANTI_LOST_IND, SCR_ID_BT_ANTI_LOST_IND + scr_idx);
        }

        if(!mmi_frm_group_is_present(GRP_ID_BT_ANTI_LOST_IND))
        {
            mmi_bt_antilost_clear_alertmode();	
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_ind_proc
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  mmi_event_struct* evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_anti_lost_ind_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            break;
        case EVT_ID_GROUP_INACTIVE:
            break;
        default:
    #ifdef __MMI_BT_BTBOX_NOLCD__
            mmi_bt_anti_lost_input_event_proc(evt);
    #endif /* __MMI_BT_BTBOX_NOLCD__ */
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_indication_screen_delete_proc_ext
 * DESCRIPTION
 * N/A.
 * PARAMETERS
 *  mmi_event_struct* evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_anti_lost_indication_screen_delete_proc_ext(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
		case EVT_ID_SCRN_GOBACK_IN_END_KEY:
		case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:  
		case EVT_ID_SCRN_DELETE_REQ:
			break;
		default:
			break;
	}
	return MMI_RET_OK;
	
}


#ifdef __MMI_BT_BTBOX_NOLCD__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_prof_ret result    [IN]
 * RETURNS
 *  srv_prof_ret  [OUT]
 *****************************************************************************/
static srv_prof_ret mmi_bt_anti_lost_notify_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_NOTIFY_CB, result);

    mmi_frm_input_event_enable_notify();

    if (result != MDI_AUDIO_TERMINATED)
        mdi_audio_resume_background_play();    
    
    return 0;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_notify
 * DESCRIPTION
 *  N/A.
 * PARAMETERS
 *  notify_id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U16 mmi_bt_anti_lost_get_notify(mmi_bt_anti_lost_notify_enum type, U8 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 notify_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((idx>=0) && idx<BT_DEVICE_LINK_NUM);
    
    switch(type)
    {
        case MMI_BT_ANTI_LOST_BTB_NOTIFY_LOST:
            notify_id = NOTIFY_BTB_SRC1_LOST;
            break;
        case MMI_BT_ANTI_LOST_BTB_NOTIFY_ABDISC:
            notify_id = NOTIFY_BTB_SRC1_ABDISCONNECT;
            break;
        case MMI_BT_ANTI_LOST_BTB_NOTIFY_RECONNECT:
            notify_id = NOTIFY_BTB_SRC1_RECONNECT;
            break;
        case MMI_BT_ANTI_LOST_BTB_NOTIFY_RECONNECT_FINISH:
            notify_id = NOTIFY_BTB_SRC1_RECONN_FINISH;
            break;
        default:
            ASSERT(0);
            break;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_GET_NOTIFY, type, idx, notify_id);

    return notify_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_notify
 * DESCRIPTION
 *  N/A.
 * PARAMETERS
 *  notify_id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_bt_anti_lost_send_notify(U16 notify_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_input_event_notify_param param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_SEND_NOTIFY, notify_id);

    param.aud_cb = mmi_bt_anti_lost_notify_callback;
    mdi_audio_suspend_background_play();
    mmi_frm_input_event_notify_remove(notify_id);
    mmi_frm_input_event_notify(notify_id, &param);

    if(notify_id==NOTIFY_BTB_SRC1_ABDISCONNECT)
        mmi_frm_input_event_disable_notify();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_screen_close
 * DESCRIPTION
 *  N/A.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_anti_lost_screen_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_anti_lost_notify_enum type;
    U8 notify_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_CLOSE);

    for (type=MMI_BT_ANTI_LOST_BTB_NOTIFY_LOST; type<MMI_BT_ANTI_LOST_BTB_END; type++)
    {
        notify_id = mmi_bt_anti_lost_get_notify(type, 0);
        mmi_frm_input_event_notify_remove(notify_id);
    }

    if(mmi_frm_group_is_present(GRP_ID_BT_ANTI_LOST_IND))
        mmi_frm_group_close(GRP_ID_BT_ANTI_LOST_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_input_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_anti_lost_input_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_INPUT_EVENT_PROC, evt->evt_id);
    
    if (!mmi_frm_group_is_present(GRP_ID_BT_ANTI_LOST_IND))
        return MMI_RET_OK;

    switch(evt->evt_id)
    {
    #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
        case EVT_BTB_RECONN_CANCEL:
            mmi_bt_dialer_auto_reconn_reset();
            mmi_bt_anti_lost_screen_close();
            break;
      #ifdef __MMI_BTB_AT_KEY_SUPPORT__
        case EVT_BTB_RECONN_RESTART:
            mmi_bt_dialer_auto_reconn_restart();
            break;
      #endif /* __MMI_BTB_AT_KEY_SUPPORT__ */
    #endif /* __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__ */
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_prof_ret result    [IN]
 * RETURNS
 *  srv_prof_ret  [OUT]
 *****************************************************************************/
static void mmi_bt_anti_lost_reconnect_finish(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 notify_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    notify_id = mmi_bt_anti_lost_get_notify(MMI_BT_ANTI_LOST_BTB_NOTIFY_RECONNECT_FINISH, 0);
    mmi_bt_anti_lost_send_notify(notify_id);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_RECONN_FINISH, 0, notify_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_prof_ret result    [IN]
 * RETURNS
 *  srv_prof_ret  [OUT]
 *****************************************************************************/
void mmi_bt_anti_lost_notify_hdlr(void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                              */
    /*----------------------------------------------------------------*/
    U16 notify_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_anti_lost_cntx.curr_times++;
    notify_id = mmi_bt_anti_lost_get_notify(MMI_BT_ANTI_LOST_BTB_NOTIFY_LOST, 0/*g_mmi_bt_anti_lost_ind[idx].index*/);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_NOTIFY_HDLR, 0, notify_id);
    kal_prompt_trace(MOD_MMI,"mmi_bt_anti_lost_notify_hdlr curr_times:%d, times:%d",
        g_mmi_bt_anti_lost_cntx.curr_times,
        g_mmi_bt_anti_lost_cntx.times);

    if(g_mmi_bt_anti_lost_cntx.curr_times > g_mmi_bt_anti_lost_cntx.times)
    {
        mmi_frm_input_event_notify_remove(notify_id);
        StopTimer(BT_ANTI_LOST_ALARM_DURATION_TIMER);
    }
    else
    {
        mmi_bt_anti_lost_send_notify(notify_id);
        StartTimerEx(BT_ANTI_LOST_ALARM_DURATION_TIMER, 
                MMI_BT_ANTI_LOST_NOTIFY_INTERVAL, 
                mmi_bt_anti_lost_notify_hdlr,
                NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_anti_lost_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_bt_cm_bt_addr* bd_addr    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_anti_lost_stop(srv_bt_cm_bt_addr* bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = mmi_bt_anti_lost_list_get_idx(bd_addr);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_STOP, idx);

    if (idx != -1)
        StopTimer(BT_ANTI_LOST_ALARM_DURATION_TIMER+idx);
}

#endif /* __MMI_BT_BTBOX_NOLCD__ */


