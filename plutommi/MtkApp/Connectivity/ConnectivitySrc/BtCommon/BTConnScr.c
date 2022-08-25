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
 * BTCONNScr.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MMI screen of BT dailer conn application.
 *
 * Author:
 * -------
 * -------

*============================================================================
* 			HISTORY
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
*
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"


#ifdef __MMI_BT_SUPPORT__ 
#ifdef __MMI_BT_DIALER_SUPPORT__

#include "GlobalResDef.h"
#include "CommonScreens.h"
#include "mmi_rp_app_bluetooth_def.h"



#include "wgui_categories_util.h"
#include "wgui_categories.h"
#include "bluetooth_bm_struct.h"

/* for get sound/image id */
#include "Custom_events_notify.h"
#include "nvram_common_defs.h"

/***************************/
/* for MTK bluetooh       */
/***************************/
#ifdef __MMI_BT_AUDIO_SUPPORT__
#include "BTMMIScoPathGprots.h"
#endif/*__MMI_BT_AUDIO_SUPPORT__*/

#include "BTMMIHfpGprots.h"
#include "BthfSrvGprot.h"

#if defined(__MMI_HIDD_SUPPORT__)
#include "BTMMIHiddGprots.h"
#include "BTMMIHidScr.h"
#endif /*defined(__MMI_HIDD_SUPPORT__)*/


#ifdef __MMI_OPP_SUPPORT__
#include "BTMMIOppGprots.h"
#endif/*__MMI_OPP_SUPPORT__*/

#ifdef __MMI_BT_MAP_CLIENT__
#include "MapSrvGprot.h"
#include "mapcsrv.h"
#endif/*__MMI_BT_MAP_CLIENT__*/

#if defined(__MMI_PBAP_SUPPORT__) || defined(__BT_PBAP_CLIENT__)
#include "BTMMIPbapGprots.h"
#endif/*__MMI_PBAP_SUPPORT__*/
#ifdef __MMI_BT_PBAP_CLIENT__
#include "PbapSrvGprot.h"
#include "pbapcsrv.h"
#endif/*__MMI_BT_PBAP_CLIENT__*/
#include "BTDialerSrvGprot.h"
#include "mmi_rp_app_bt_dialer_def.h"

#if defined(__MMI_A2DP_SUPPORT__)
#include "A2dpSrvGprot.h"
#endif/*__MMI_A2DP_SUPPORT__*/
#if defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
#ifdef __MMI_AVRCP_SUPPORT__
#include "AudioPlayerBTNowPlaying.h"
#endif/*__MMI_AVRCP_SUPPORT__*/
#endif

#ifdef __MMI_AVRCP_SUPPORT__
#include "AvrcpSrvGprot.h"
#endif/*__MMI_AVRCP_SUPPORT__*/
/***************************/
/* bluetooh common files   */
/***************************/

#include "BTMMIScrGprots.h"
#include "BTMMIScr.h"
#include "BtcmCuiGprot.h"
#include "BtcmSrvGprot.h"
#ifdef __MMI_BT_BTBOX_NOLCD__
#include "BTMMIAntilostScr.h"
#include "Mmi_rp_app_bt_music_nolcd_def.h"
#include "UcmGProtBT.h"
#endif/*__MMI_BT_BTBOX_NOLCD__*/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__

typedef struct
{
    MMI_BOOL bt_dialer_reconn_flag;
    S32 bt_dialer_reconn_accu_time;
    U32 bt_dialer_reconn_duration;
    U32 bt_dialer_reconn_freq;      /* for confirm exit func or progress rsk func */
    srv_bt_cm_bt_addr bd_addr;
} mmi_bt_reconn_ctx_struct;

#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/

typedef struct
{
    MMI_BT_CONN_VIS g_vis_type;
    mmi_bt_dialer_conn_callback_item callback_item;
    srv_bt_cm_bt_addr bd_addr;
    MMI_BOOL result;
    MMI_BOOL is_connect;
} mmi_bt_conn_set_vis_struct;

/***************************************************************************** 
 * Golobal function
 *****************************************************************************/
extern U16 mmi_btdialer_app_launch_func(void *param, U32 param_size);
extern void mmi_btdialer_cm_app_exit_func(void);
extern void mmi_bt_dialor_disconnect(srv_bt_cm_bt_addr* dev_addr);
static void mmi_bt_close_group(MMI_ID group_id);

/***************************************************************************** 
 * Local functions
 *****************************************************************************/

static void mmi_bt_dialer_disconnect_lsk(void);
static void mmi_bt_dialer_disconn_hdlr(void);
void mmi_bt_connected_by_app(mmi_scrn_essential_struct* param);
static mmi_bt_dialer_conn_callback_item *mmi_bt_dialer_next_callback_item(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL is_connect, MMI_BOOL is_indicate);
static MMI_BOOL mmi_bt_dialer_get_time_out_flag(void);
void mmi_bt_dialer_set_connected_dev_info(srv_bt_cm_dev_struct *dev_info);
void mmi_bt_dialer_clean_connected_dev_info(srv_bt_cm_dev_struct *dev_info);
static void mmi_bt_dialer_quick_list_hilite_handler(S32 idx);
static U32 mmi_bt_dialer_quick_conn_dev_num(void);
static void mmi_bt_dialer_quick_conn_dev_lsk(void);
static void mmi_bt_dialer_set_vis_change_flag(MMI_BOOL is_change);
static MMI_BOOL mmi_bt_dialer_get_vis_change_flag(void);
static mmi_bt_conn_set_vis_struct mmi_bt_dialer_get_conn_vis_enum(void);
static MMI_BOOL  mmi_bt_dialer_set_conn_vis_enum(mmi_bt_conn_set_vis_struct change_vis_sate, MMI_BOOL prevent_conn_flag);
static void mmi_bt_dialor_connect_int(srv_bt_cm_bt_addr* dev_addr, mmi_bt_dialer_conn_callback_item *callback_item);
static void mmi_bt_dialor_callback_int(srv_bt_cm_bt_addr* dev_addr,  MMI_BOOL result,MMI_BOOL is_connect, mmi_bt_dialer_conn_callback_item *callback_item);
static void mmi_bt_dialer_callback_done_int(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL is_connect);
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
static void mmi_bt_dialer_set_autoreconn_dev(mmi_bt_reconn_ctx_struct *dev);
static void mmi_bt_dialer_clean_autoreconn_dev(mmi_bt_reconn_ctx_struct *dev);
static void mmi_bt_dialer_disconn_excpt_hdlr(void *msg_ptr);
static void mmi_bt_dialer_auto_reconn_hdlr(void);
static void mmi_bt_dialer_auto_reconn_start(void);
static void mmi_bt_dialer_auto_reconn_first_start_check(void);
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/

/**************************************************************************** 
 * Globol Variable
 *****************************************************************************/
extern mmi_bt_scr_cntx_struct g_mmi_bt_scr_cntx;
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__

static mmi_bt_reconn_ctx_struct  g_mmi_bt_reconn_ctx[BT_DEVICE_LINK_NUM];
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
mmi_bt_conn_set_vis_struct g_mmi_bt_change_vis_dev;
/**************************************************************************** 
 * Local Variable
 *****************************************************************************/
static MMI_BOOL g_mmi_is_disconn_req=MMI_FALSE;
static MMI_BOOL g_centkey_flag = MMI_FALSE;
static MMI_BOOL time_out_flag = MMI_FALSE;
static MMI_BOOL g_bt_is_all_disconn = MMI_FALSE;
static MMI_BOOL g_mmi_bt_dialer_headset_flag = MMI_FALSE;
static MMI_BOOL g_mmi_is_vis_change_in_busy_state=MMI_FALSE;
static void mmi_bt_dialer_show_conn_status_nmgr_popup(WCHAR* str);

WCHAR name_buf[BT_DEVICE_LINK_NUM][SRV_BT_CM_BD_FNAME_LEN + 20];
static mmi_frm_proc_id_info_struct g_id_info;
static mmi_id g_parent_id = NULL ;
srv_bt_cm_dev_struct g_connected_dev_info[BT_DEVICE_LINK_NUM];
S32 g_quick_conn_idx;


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_time_out_flag
 * DESCRIPTION
 *  This function is for getting time page out flag.
 * PARAMETERS
 *  void 
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_bt_dialer_get_time_out_flag(void)
{
	  /*----------------------------------------------------------------*/
	  /* Local Variables												*/
	  /*----------------------------------------------------------------*/
	
	  /*----------------------------------------------------------------*/
	  /* Code Body														*/
	  /*----------------------------------------------------------------*/
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_TIME_OUT_FLAG, time_out_flag);
	return time_out_flag;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_time_out_flag
 * DESCRIPTION
 *  This function is for setting time page out flag.
 * PARAMETERS
 *  MMI_BOOL 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_set_time_out_flag(MMI_BOOL flag)
{
	  /*----------------------------------------------------------------*/
	  /* Local Variables												*/
	  /*----------------------------------------------------------------*/
	
	  /*----------------------------------------------------------------*/
	  /* Code Body														*/
	  /*----------------------------------------------------------------*/
	
	time_out_flag = flag;
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_TIME_OUT_FLAG, time_out_flag);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_disconn_req
 * DESCRIPTION
 *  This function is for setting disconnecting flag.
 * PARAMETERS
 *  MMI_BOOL req
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_set_disconn_req(MMI_BOOL req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_is_disconn_req = req;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SET_DISCONN_REQ_FLAG, g_mmi_is_disconn_req);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_disconn_req
 * DESCRIPTION
 *  This function is for getting disconnecting flag.
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  MMI_BOOL g_mmi_is_disconn_req
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_get_disconn_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_GET_DISCONN_REQ_FLAG, g_mmi_is_disconn_req);
    return g_mmi_is_disconn_req;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_main_menu_bt_dialer
 * DESCRIPTION
 *  This function is Main menu entry function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_main_menu_bt_dialer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MAIN_MENU);

    g_mmi_bt_scr_cntx.main_gid = mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_BT_CM,
        mmi_bt_main_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

	mmi_bt_pre_entry_mydev_menu	();		
}


static void mmi_bt_conn_pop_show_timer_hdlr(void* usr_data)
{
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_show_dialor_conn_success
 * DESCRIPTION
 *  This function is for showning connected popup function
 * PARAMETERS
 *  srv_bt_cm_dev_struct* dev_p
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_show_dialor_conn_success(srv_bt_cm_dev_struct* dev_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL show_pop = MMI_TRUE;
    S16 error;
    WCHAR string[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};
    WCHAR string1[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};
   
    /*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__) && !defined(__MMI_BT_BTBOX_NOLCD__)
    if (MMI_TRUE == g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag || 0 != g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time)
    {
        show_pop = MMI_FALSE;
    }
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__ && !__MMI_BT_BTBOX_NOLCD__ */
   
    if (dev_p == NULL)
    {
        return;
    }

    mmi_chset_utf8_to_ucs2_string((kal_uint8*)string, (SRV_BT_CM_BD_UCS2_NAME_LEN * 2), (kal_uint8*)dev_p->name);
    mmi_bt_dialer_app_emit_event(EVT_ID_DIALER_CONN_EVENT_ID, dev_p, MMI_FALSE);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_EVENT);
#ifndef __MMI_BT_BTBOX_NOLCD__
    mmi_wcscat((WCHAR*)string, (WCHAR*)GetString(STR_BT_CONN_POP));
    WriteRecord(NVRAM_BYTE_BT_DIALER_CONNSTR,1,&string,NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE,&error);
#endif /* __MMI_BT_BTBOX_NOLCD__ */
    mmi_wcs_to_asc((CHAR *)string1, (WCHAR *)string);
    kal_prompt_trace(MOD_MMI, "[btconn]STRING = %s", string1);
#ifndef __MMI_BT_BTBOX_NOLCD__
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHOW_POP);
    if (show_pop)
    {
        mmi_bt_dialer_show_conn_status_nmgr_popup((WCHAR*)string);
    }
#endif /* __MMI_BT_BTBOX_NOLCD__ */
	
	srv_bt_cm_set_dev_link_state(&dev_p->bd_addr,MMI_TRUE);
	mmi_bt_dialer_set_connected_dev_info(dev_p);

#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
  #ifndef __MMI_BT_BTBOX_NOLCD__
    if(mmi_bt_anti_lost_get_status())
  #endif /* __MMI_BT_BTBOX_NOLCD__ */
    {
    #ifndef __MMI_BT_BTBOX_NOLCD__
        if(!mmi_bt_anti_lost_is_in_list(&dev_p->bd_addr))//if have not eisted in anti-lost list,so do it.
    #endif /* __MMI_BT_BTBOX_NOLCD__ */
        {
            mmi_bt_anti_lost_enable_req(&dev_p->bd_addr, MMI_TRUE);
        }
    }
    // add this device to anti-lost list.
    mmi_bt_anti_lost_add_addr(&dev_p->bd_addr);
#endif/*__MMI_BT_ANTI_LOST_BY_RSSI__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_show_dialor_help
 * DESCRIPTION
 *  This function is for showning help function
 * PARAMETERS
 *  srv_bt_cm_dev_struct *dev_p
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_show_dialor_help(srv_bt_cm_dev_struct *dev_p)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ui_buffer_size;
    U8 *guiBuffer;                      /* Buffer holding history data */
	U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_ABOUT);

    if (mmi_frm_scrn_enter(
            g_mmi_bt_scr_cntx.main_gid,
            SCR_BT_ABOUT,
            (FuncPtr) NULL,
            (FuncPtr) mmi_bt_show_dialor_help,
            MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

#ifdef __MMI_BTD_BOX_UI_STYLE__
    mmi_wcscpy(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *) GetString(STR_BT_MYDEV_HELP_CONTENT_BT_BOX));
#else /*__MMI_BTD_BOX_UI_STYLE__*/
    mmi_wcscpy(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *) GetString(STR_BT_DIALER_HELP_CONTENT));
    #ifdef __MMI_BT_REMOTE_CAPTURE__
        mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *) GetString(STR_BT_REMOTE_CAPTURE_INFO));
    #endif/*__MMI_BT_REMOTE_CAPTURE__*/
    #ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
        mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *) GetString(STR_BT_ANTI_LOST_INFO));
    #endif/*__MMI_BT_ANTI_LOST_BY_RSSI__*/
    mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *) GetString(STR_BT_DIALER_ETC));
#endif /*__MMI_BTD_BOX_UI_STYLE__*/
    mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *) L"\n");

    ui_buffer_size = mmi_wcslen(g_mmi_bt_scr_cntx.ui_buf);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    SetParentHandler(MENU_CONN_BT_MAIN);
	if ( srv_bt_cm_get_btdialor_app_mode() == MMI_TRUE)
	{
		str_id = STR_GLOBAL_HELP; 
	}
	else
	{
		str_id = STR_BT_ABOUT; 
	}
    ShowCategory74Screen(
       str_id,
       GetRootTitleIcon(MENU_CONN_BT_MAIN),
       0,
       0,
       STR_GLOBAL_BACK,
       IMG_GLOBAL_BACK,
       (PU8) g_mmi_bt_scr_cntx.ui_buf,
       ui_buffer_size,
       guiBuffer);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_next_callback_item
 * DESCRIPTION
 *  This function is for call callback function.
 * PARAMETERS
 *  srv_bt_cm_connection_type conn_type
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_bt_dialer_conn_callback_item *mmi_bt_dialer_next_callback_item(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL is_connect, MMI_BOOL is_indicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                						*/
    /*----------------------------------------------------------------*/
    U32 i;
    static MMI_BOOL has_first_item_conn = MMI_FALSE;
    U32 total = mmi_bt_dialer_tbl_count();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                     						 */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_NEXE_CB_FUNC, conn_type,is_connect,is_indicate);

    if(is_indicate)
    {
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
        if (is_connect && conn_type == SRV_BT_CM_HF_CONNECTION)
        {
            mmi_bt_dialer_auto_reconn_reset();
        }
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
        if(!is_connect && !mmi_bt_dialer_app_is_connected_ex(dev_addr))
        {
            return NULL;
        }
        if (!is_connect && 
            conn_type == SRV_BT_CM_HF_CONNECTION && 
            (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr)&&
            srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr)))
        {
            return NULL;
        }
        if (!is_connect && 
            conn_type != SRV_BT_CM_AVRCP_CT_CONNECTION && 
            conn_type != SRV_BT_CM_A2DP_CONNECTION && 
            conn_type != SRV_BT_CM_HF_CONNECTION && 
            (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, dev_addr) ||
            (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr)||
            srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr))))
        {
            return NULL;
        }
        if (!is_connect && (conn_type == SRV_BT_CM_AVRCP_CT_CONNECTION || conn_type == SRV_BT_CM_A2DP_CONNECTION))
	       {
            if(srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, dev_addr))
            {
                return NULL;
            }
            else
            {
                return &g_mmi_btdialer_callback_tbl[0];
            }
        }
        if (!is_connect && conn_type == SRV_BT_CM_HF_CONNECTION && srv_bt_cm_is_dev_busy(dev_addr))
        {
            mmi_bt_dialer_set_time_out_flag(MMI_TRUE);
        }
    }
    if (conn_type == SRV_BT_CM_NO_CONNECTION)
    {
        return &g_mmi_btdialer_callback_tbl[0];
    }
    if (conn_type == g_mmi_btdialer_callback_tbl[0].type)
    {
        has_first_item_conn = is_connect;
    }
    for (i = 0; i < total; i++)
    {
        if (g_mmi_btdialer_callback_tbl[i].type == conn_type)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_NEXE_CB_RESET_BUSY_STATE, conn_type, dev_addr->lap,dev_addr->nap,dev_addr->uap);
            srv_bt_cm_set_dev_busy_state(dev_addr, conn_type, MMI_FALSE);
            break;
        }
    }
    if ((i + 1) < total)
    {
        return &g_mmi_btdialer_callback_tbl[i + 1];
    }
    if (conn_type == SRV_BT_CM_A2DP_CONNECTION  && !has_first_item_conn)
    {
        return &g_mmi_btdialer_callback_tbl[0];
    }
	
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CB_NEXTITEM, i, total);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_show_conn_status_nmgr_popup
 * DESCRIPTION
 *  This function is show conn status nmgr popup
 * PARAMETERS
 *  WCHAR*
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_show_conn_status_nmgr_popup(WCHAR* str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL timer_exist = IsMyTimerExist(BT_DIALER_CONN_NMGR_POP_TIMER);	
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHOW_CONN_STATUS_NMGR,(U32)timer_exist);
    if(!timer_exist)
    {
        StartTimer(BT_DIALER_CONN_NMGR_POP_TIMER,2000,mmi_bt_conn_pop_show_timer_hdlr);
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, str);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_callback_done
 * DESCRIPTION
 *  This function is bt dialer callback done
 * PARAMETERS
 *  srv_bt_cm_bt_addr*
 *  MMI_BOOL
 *  MMI_BOOL
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_callback_done(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL result,MMI_BOOL is_connect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                						*/
    /*----------------------------------------------------------------*/
    //MMI_BOOL show_pop = MMI_TRUE;
    mmi_bt_conn_set_vis_struct change_vis_dev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* when reconnection started, then should not show popup*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CB_DONE, result,is_connect,dev_addr->lap, dev_addr->nap, dev_addr->uap);

    mmi_bt_update_status_icon();
    if(!srv_bt_cm_is_dev_busy(dev_addr))
    {
        if (mmi_bt_dialer_get_vis_change_flag())
        {
            if(is_connect && !srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr))
            {
                memcpy(&change_vis_dev.bd_addr,dev_addr, sizeof(srv_bt_cm_bt_addr));
                change_vis_dev.g_vis_type = MMI_BT_CONN_DONE;
                change_vis_dev.result = result;
                change_vis_dev.is_connect = is_connect;
                if(mmi_bt_dialer_set_conn_vis_enum(change_vis_dev, MMI_FALSE))
                {
                    return;
                }
            }

            if(!is_connect && !srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr))
            {
                memcpy(&change_vis_dev.bd_addr,dev_addr, sizeof(srv_bt_cm_bt_addr));
                change_vis_dev.g_vis_type = MMI_BT_CONN_DONE;
                change_vis_dev.result = result;
                change_vis_dev.is_connect = is_connect;
                if(mmi_bt_dialer_set_conn_vis_enum(change_vis_dev, MMI_FALSE))
                {
                    return;
                }
            }
        }
        mmi_bt_dialer_callback_done_int(dev_addr, is_connect);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_callback_done_int
 * DESCRIPTION
 *  This function is a internal bt dialer callback done
 * PARAMETERS
 *  srv_bt_cm_bt_addr*
 *  MMI_BOOL
 *  MMI_BOOL
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialer_callback_done_int(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL is_connect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL show_pop = MMI_TRUE;
    srv_bt_cm_dev_struct* dev_p ;
    WCHAR string1[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};
    WCHAR string[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_p = (srv_bt_cm_dev_struct*)srv_bt_cm_get_dev_info(dev_addr);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CB_DONE_INT, is_connect,dev_addr->lap, dev_addr->nap, dev_addr->uap);
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    if (MMI_TRUE == g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag && 0 != g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time)
    {
        show_pop = MMI_FALSE;	
    }
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
	
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHOW_POP);
    if (is_connect)
    {
    #ifndef __MMI_BT_BTBOX_NOLCD__
        mmi_frm_scrn_close(g_parent_id, SCR_BT_INQUIRED_POWER_ON); 
    #endif /* __MMI_BT_BTBOX_NOLCD__ */
        if (mmi_bt_dialer_app_is_connected_ex(&dev_p->bd_addr))
        {
            mmi_bt_show_dialor_conn_success(dev_p);
        #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIALER_AUTO_RECONN_STATUS, is_connect, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time/1000);
            if (MMI_TRUE == g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag)
            {
                g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag = MMI_FALSE;
                mmi_bt_dialer_clean_autoreconn_dev(&g_mmi_bt_reconn_ctx[0]);
                if (!mmi_bt_dialer_is_addr_equal_0(&g_mmi_bt_reconn_ctx[0].bd_addr))
                {
                    mmi_bt_dialer_auto_reconn_first_start_check();//  for the 2nd device do the auto conenct
                }
            }
        #endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
        #ifndef __MMI_BT_BTBOX_NOLCD__
            mmi_frm_scrn_close(g_mmi_bt_scr_cntx.main_gid, SCR_BT_CONNECTING);
        #endif /* __MMI_BT_BTBOX_NOLCD__ */
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_FAIL_POPUP);
        #ifndef __MMI_BT_BTBOX_NOLCD__
            if (show_pop)
            {
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*)string,
                    (SRV_BT_CM_BD_UCS2_NAME_LEN * 2),
                    (kal_uint8*)dev_p->name);
                mmi_wcscat((WCHAR*)string, (WCHAR*)GetString(STR_BT_CONN_FAILED));
                mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)string);
            }
        #endif /* __MMI_BT_BTBOX_NOLCD__ */
            srv_bt_cm_set_dev_link_state(&dev_p->bd_addr,MMI_FALSE);
        #ifndef __MMI_BT_BTBOX_NOLCD__
            mmi_frm_scrn_close(g_mmi_bt_scr_cntx.main_gid, SCR_BT_CONNECTING);
        #endif /* __MMI_BT_BTBOX_NOLCD__ */
        }
    }
    else
    {
    #ifndef __MMI_BT_BTBOX_NOLCD__
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), SCR_BT_DIALER_DISCONNECT_ASK); 
    #endif /* __MMI_BT_BTBOX_NOLCD__ */
        if (!mmi_bt_dialer_app_is_connected_ex(&dev_p->bd_addr))
        {
        #ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
          #ifndef __MMI_BT_BTBOX_NOLCD__
            mmi_bt_anti_lost_close_scr(&dev_p->bd_addr);
          #else 
                mmi_bt_anti_lost_stop(&dev_p->bd_addr);
          #endif /* __MMI_BT_BTBOX_NOLCD__ */
            mmi_bt_anti_lost_clean_addr(&dev_p->bd_addr);//clean the device in anti-lost list.
        #endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ */
            srv_bt_cm_set_dev_link_state(&dev_p->bd_addr,MMI_FALSE);
            if (!srv_shutdown_is_running())
            {
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*)string,
                    (SRV_BT_CM_BD_UCS2_NAME_LEN * 2),
                    (kal_uint8*)dev_p->name);
            #ifndef __MMI_BT_BTBOX_NOLCD__
                mmi_wcscat((WCHAR*)string, (WCHAR*)GetString(STR_BT_DISCONN_POP));
                mmi_frm_nmgr_popup(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_FAILURE,
                    (WCHAR*)string);
            #endif /* __MMI_BT_BTBOX_NOLCD__ */
                mmi_wcs_to_asc((CHAR *)string1, (WCHAR *)string);
                kal_prompt_trace(MOD_MMI_CONN_APP, "[btconn]STRING = %s", string1);
            #ifndef __MMI_BT_BTBOX_NOLCD__
                mmi_wcs_to_asc((CHAR *)string1, (WCHAR *)dev_p->name);
                kal_prompt_trace(MOD_MMI_CONN_APP, "[btconn]STRING = %s", string1);
            #endif /* __MMI_BT_BTBOX_NOLCD__ */
                mmi_bt_dialer_app_emit_event(EVT_ID_DIALER_DISCONN_EVENT_ID, dev_p, MMI_FALSE);
                MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIS_EVENT);
            #ifndef __MMI_BT_BTBOX_NOLCD__
                mmi_frm_scrn_close(g_mmi_bt_scr_cntx.main_gid, SCR_BT_CONNECTING);
                /* restart connnection when the disconnection pop comes firstly*/
              #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
                mmi_bt_dialer_auto_reconn_first_start_check();
              #endif /* __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__ */
            #endif /* __MMI_BT_BTBOX_NOLCD__ */
            }
        mmi_bt_dialer_set_disconn_req(MMI_FALSE);
        }
    }
    if (mmi_bt_dialer_get_time_out_flag())
    {
        mmi_bt_dialer_set_time_out_flag(MMI_FALSE); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialor_callback
 * DESCRIPTION
 *  This function is bt dialer callback function
 * PARAMETERS
 *  srv_bt_cm_connection_type conn_type
 * MMI_BOOL result
 * MMI_BOOL is_connect
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialor_callback(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res = MMI_FALSE;
    srv_bt_cm_dev_struct* dev_p;
    mmi_bt_dialer_conn_callback_item *callback_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CALLBACK, result, is_connect, conn_type, is_indicate);
    srv_bt_cm_copy_addr(&g_mmi_bt_scr_cntx.conn_dev_add,dev_addr);

    dev_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_dev_info(&g_mmi_bt_scr_cntx.conn_dev_add);
    callback_item = mmi_bt_dialer_next_callback_item(&dev_p->bd_addr, conn_type, is_connect, is_indicate);
    if(is_connect)
    {
        if (mmi_bt_dialer_get_time_out_flag())
        {
            callback_item = NULL;
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CB_NULL);
        }
    }
    if(is_connect && !mmi_bt_dialer_get_vis_change_flag() && callback_item != NULL)
    {
        mmi_bt_conn_set_vis_struct change_vis_dev;
        memcpy(&change_vis_dev.bd_addr,&dev_p->bd_addr, sizeof(srv_bt_cm_bt_addr));
        //change_vis_dev.callback_itm = callback_item;
        memcpy(&change_vis_dev.callback_item,callback_item, sizeof(mmi_bt_dialer_conn_callback_item));

        change_vis_dev.g_vis_type = MMI_BT_CONN_PASSIVE;
        change_vis_dev.result = result;
        change_vis_dev.is_connect = is_connect;
        MMI_TRACE(MMI_CONN_TRC_G7_BT,MMI_BT_CONN_CBITEM_NULL);
        if(mmi_bt_dialer_set_conn_vis_enum(change_vis_dev, MMI_TRUE))
        {
            mmi_bt_dialer_set_vis_change_flag(MMI_TRUE);
            return;
        }
    }
    mmi_bt_dialor_callback_int(&dev_p->bd_addr, result,is_connect, callback_item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialor_callback_int
 * DESCRIPTION
 *  This function is a internal bt dialer callback function
 * PARAMETERS
 *  srv_bt_cm_bt_addr*
 * MMI_BOOL result
 * MMI_BOOL is_connect
 * mmi_bt_dialer_conn_callback_item *
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_bt_dialor_callback_int(srv_bt_cm_bt_addr* dev_addr,  MMI_BOOL result,MMI_BOOL is_connect, mmi_bt_dialer_conn_callback_item *callback_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CALLBACK_INT, result, is_connect, dev_addr->lap, dev_addr->nap, dev_addr->uap);

	if(callback_item != NULL)
	{
		if (is_connect)
		{
			if (result)
			{
				srv_bt_cm_set_dev_link_state(dev_addr,MMI_TRUE);
			}
			if (callback_item->conn != NULL)
			{
				MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CBITEM_CONN_NULL);
				MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_NEXE_CB_SET_BUSY_STATE, callback_item->type, dev_addr->lap, dev_addr->nap, dev_addr->uap);
				srv_bt_cm_set_dev_busy_state(dev_addr, callback_item->type, MMI_TRUE);
				callback_item->conn(&g_mmi_bt_scr_cntx.conn_dev_add, mmi_bt_dialor_callback);
			}
			else
			{
				mmi_bt_dialer_callback_done(&g_mmi_bt_scr_cntx.conn_dev_add, result, is_connect);
			}
		}
		else
		{
			if(callback_item->disconn != NULL)
			{
			  
				MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CBITEM_CONN_NULL);
				callback_item->disconn(&g_mmi_bt_scr_cntx.conn_dev_add, mmi_bt_dialor_callback);
			}
			else
			{
				mmi_bt_dialer_callback_done(&g_mmi_bt_scr_cntx.conn_dev_add, result, is_connect);
			}
		}
	}
	else
	{
		mmi_bt_dialer_callback_done(&g_mmi_bt_scr_cntx.conn_dev_add, result, is_connect);
	}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialor_disconnect
 * DESCRIPTION
 *  This function is bt dialer disconnect function
 * PARAMETERS
 *  srv_bt_cm_bt_addr* dev_addr
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialor_disconnect(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_bt_dialer_conn_callback_item *callback_item;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT,MMI_BT_CONN_DIS_FROM_DAILER, dev_addr->lap, dev_addr->nap, dev_addr->uap);
    callback_item = mmi_bt_dialer_next_callback_item(dev_addr, SRV_BT_CM_NO_CONNECTION, MMI_FALSE, MMI_FALSE);

    if (srv_bt_cm_get_busy_dev() == NULL &&
        (callback_item != NULL) && 
        (callback_item->indx != 0xFF))
    {
        mmi_bt_dialer_set_disconn_req(MMI_TRUE);
        if (!srv_shutdown_is_running())
        {
            mmi_bt_show_progress_scr(
                g_mmi_bt_scr_cntx.main_gid,
                SCR_BT_CONNECTING,
                STR_GLOBAL_DISCONNECTING,
                STR_GLOBAL_DISCONNECTING,
                NULL);
        }
        callback_item->disconn(dev_addr, mmi_bt_dialor_callback);
    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_BT_SERVICE_UNAVAILABLE));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialor_connect
 * DESCRIPTION
 *  This function is bt dialer connect function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialor_connect(srv_bt_cm_bt_addr* dev_addr)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL show_pop_up = MMI_TRUE;
    mmi_bt_dialer_conn_callback_item *callback_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callback_item = mmi_bt_dialer_next_callback_item(dev_addr, SRV_BT_CM_NO_CONNECTION, MMI_TRUE, MMI_FALSE);
    MMI_TRACE(MMI_CONN_TRC_G7_BT,MMI_BT_CONN_CONNECT_FROM_DIALER);
  
    if (srv_bt_cm_get_busy_dev() == NULL &&
        (callback_item) != NULL && 
        (callback_item->indx) != 0xFF)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_NEXE_CB_SET_BUSY_STATE, callback_item->type, dev_addr->lap,dev_addr->nap,dev_addr->uap);
        srv_bt_cm_set_dev_busy_state(dev_addr, callback_item->type, MMI_TRUE);
    #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
        if (g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag == MMI_TRUE)
            show_pop_up = MMI_FALSE;
    #endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
        if (show_pop_up)
        {
            mmi_bt_show_progress_scr(g_mmi_bt_scr_cntx.main_gid, SCR_BT_CONNECTING, STR_GLOBAL_CONNECTING, STR_GLOBAL_CONNECTING, NULL);
        }
        if (callback_item != NULL)
        {
            mmi_bt_conn_set_vis_struct change_vis_dev; 
            memcpy(&change_vis_dev.bd_addr,dev_addr, sizeof(srv_bt_cm_bt_addr));
            memcpy(&change_vis_dev.callback_item,callback_item, sizeof(mmi_bt_dialer_conn_callback_item));
            change_vis_dev.g_vis_type = MMI_BT_CONN_ACTIVE;
            MMI_TRACE(MMI_CONN_TRC_G7_BT,MMI_BT_CONN_CBITEM_NULL);
            if(mmi_bt_dialer_set_conn_vis_enum(change_vis_dev, MMI_TRUE))
            {
                mmi_bt_dialer_set_vis_change_flag(MMI_TRUE);
                return;
            }
            callback_item->conn(dev_addr, mmi_bt_dialor_callback);
        } 
    }
    else
    {
        U16 pop_str_id = STR_BT_SERVICE_UNAVAILABLE;
    #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
        if(MMI_TRUE == srv_bt_cm_get_auto_reconn_flag(dev_addr))
        {
            StartTimer(BT_DIALER_AUTO_RECONN_TIMER,g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_freq, mmi_bt_dialer_auto_reconn_hdlr);
            return;
        }
    #endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
        mmi_frm_nmgr_popup(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_FAILURE,
                       (WCHAR*)GetString(pop_str_id));
     }
}  


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialor_connect_int
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  srv_bt_cm_bt_addr* 
 *  mmi_bt_dialer_conn_callback_item *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialor_connect_int(srv_bt_cm_bt_addr* dev_addr, mmi_bt_dialer_conn_callback_item *callback_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT,MMI_BT_CONN_CONNECT_FROM_DIALER_INT,dev_addr->lap,dev_addr->nap,dev_addr->uap);
    callback_item->conn(dev_addr, mmi_bt_dialor_callback);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_dialor_mydev_opt_group_proc
 * DESCRIPTION
 *  This function is the screen group proc function of my device option menu
 *  It is responsible for handling the event of screen group.
 * PARAMETERS
 *  evt         [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_entry_dialor_mydev_opt_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    srv_bt_cm_dev_struct* dev_p =(srv_bt_cm_dev_struct *)srv_bt_cm_get_dev_info(&g_mmi_bt_scr_cntx.conn_dev_add);
    U16 nItems = 0;
    srv_bt_cm_bt_addr dev_addr = dev_p->bd_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        /* CUI Menu show event sent to APP before entering list menu screen */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == SCR_BT_MYDEV_OPT)
            {
                mmi_menu_id root_ids[MMI_BT_MYDEV_OPT_LAST];
				if ( srv_bt_cm_is_dev_conn_active((srv_bt_cm_bt_addr*)&dev_addr)&&
					mmi_bt_dialer_app_is_connected_ex(&dev_addr))
				{	 
				    root_ids[nItems++]=MMI_BT_MYDEV_DISCONNECT;	
				}
				else	
				{
					root_ids[nItems++]=MMI_BT_MYDEV_CONNECT;
				}
				
                root_ids[nItems++] = MMI_BT_MYDEV_OPT_DEL;
				root_ids[nItems++]=MMI_BT_MYDEV_HELP;
#if defined(__MMI_HIDD_SUPPORT__)
				if (srv_bt_cm_dev_is_support_hid(dev_p))
				{
					root_ids[nItems++] = MMI_BT_MYDEV_OPT_REMOTE_CTRL;
				}
#endif /*defined(__MMI_HIDD_SUPPORT__) */

	            cui_menu_set_currlist(	menu_evt->sender_id,
									nItems,
									root_ids);

       		    cui_menu_set_item_string(
								   menu_evt->sender_id,
								   MMI_BT_MYDEV_CONNECT,
                    (WCHAR*)GetString(STR_GLOBAL_CONNECT));
				cui_menu_set_item_string(
								   menu_evt->sender_id,
								   MMI_BT_MYDEV_DISCONNECT,
                    (WCHAR*)GetString(STR_GLOBAL_DISCONNECT));
				
				cui_menu_set_item_string(
								   menu_evt->sender_id,
								   MMI_BT_MYDEV_HELP,
								   (WCHAR*)GetString(STR_GLOBAL_HELP));			
			    cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_MYDEV_OPT_DEL,
                    (WCHAR*)GetString(STR_GLOBAL_DELETE));
#if defined(__MMI_HIDD_SUPPORT__)				
				cui_menu_set_item_string(
								   menu_evt->sender_id,
								   MMI_BT_MYDEV_OPT_REMOTE_CTRL,
								   (WCHAR*)GetString(STR_BT_REMOTE_CONTROL));
#endif /*defined(__MMI_HIDD_SUPPORT__)*/
                cui_menu_set_default_title_string(
                    menu_evt->sender_id,
                    (WCHAR*)GetString(STR_GLOBAL_OPTIONS));
			}
		}
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {

                case MMI_BT_MYDEV_OPT_DEL:
				{
					mmi_bt_entry_mydev_delete_confirm(MMI_BT_DELETE_DEV_CONFIRM);
					break;
        		}
        
				case MMI_BT_MYDEV_CONNECT:
				{
					#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
					mmi_bt_dialer_auto_reconn_reset();
                    #endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
					
					if (srv_bt_cm_get_busy_dev() != NULL)
					{
						mmi_frm_nmgr_popup(
									   MMI_SCENARIO_ID_DEFAULT,
									   MMI_EVENT_FAILURE,
									  (WCHAR*)GetString(STR_BT_SERVICE_UNAVAILABLE));

					}
					else if (mmi_bt_dialer_app_is_connected_ex(&dev_addr) || (srv_bt_cm_get_linked_dev_list_idx() == BT_DEVICE_LINK_NUM))
					{
						mmi_bt_popup_display(
							STR_BT_RELEASE_CONN_PROMPT,
							MMI_EVENT_FAILURE,
							NULL);
					}				
  			        else
					{
						if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) )
						{
						    if(srv_bt_cm_is_headset_connected_ex())//headset is connected, 
						    {
							    mmi_frm_nmgr_popup(
								MMI_SCENARIO_ID_DEFAULT,
								MMI_EVENT_FAILURE,
								(WCHAR*)GetString(STR_BT_HEADSET_CONN_PROMPT));
					    	}
							else
							{
								mmi_bt_entry_connecting(g_mmi_bt_scr_cntx.mydev_gid);
							}
						}
						else
						{
							mmi_bt_dialor_connect(&(dev_p->bd_addr)); 							
						}						
					}
                    break;
                }
				case MMI_BT_MYDEV_DISCONNECT:
				{
					if (srv_bt_cm_get_busy_dev()== NULL)
				    {    
		     			if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) )
						{
						mmi_bt_entry_release_device_connections(g_mmi_bt_scr_cntx.mydev_gid);

					    }
						else
						{

					        mmi_bt_dialor_disconnect(&(dev_p->bd_addr));
						}
				   	}
					else
					{
						mmi_frm_nmgr_popup(
						    MMI_SCENARIO_ID_DEFAULT,
						    MMI_EVENT_FAILURE,
						   (WCHAR*)GetString(STR_BT_SERVICE_UNAVAILABLE));
					}
                    break;
                }
        
				case MMI_BT_MYDEV_HELP:
				{
					mmi_bt_show_dialor_help(dev_p);
                    break;
                }
#if defined(__MMI_HIDD_SUPPORT__)											
				case MMI_BT_MYDEV_OPT_REMOTE_CTRL:
                {
					mmi_bt_entry_remote_control_ext(&(dev_p->bd_addr));
					break;
                }
				
#endif /*defined(__MMI_HIDD_SUPPORT__)*/
                default:
                    break;
            }

         default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_main_group_proc
 * DESCRIPTION
 *  This function is bt dialer main proc function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/

mmi_ret mmi_bt_dialer_main_group_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	switch (param->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            g_mmi_bt_scr_cntx.main_gid = GRP_ID_BT_CM;
            break;

        default:
            break;
    }
     return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_power_on
 * DESCRIPTION
 *  This function is bt dialer power on function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_power_on(void)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	mmi_id group_id;
    mmi_id parent_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_POWER_ON);

    parent_id = mmi_frm_group_get_active_id();
    group_id = mmi_frm_group_create_ex(
             parent_id,
             GRP_ID_BT_CM_POWER_ON_CNF,
             mmi_bt_dialer_main_group_proc,
             NULL,
             MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_bt_display_power_on_confirm(group_id);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_close_group
 * DESCRIPTION
 *  This function is bt dialer close group function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_close_group(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (MMI_TRUE == mmi_frm_group_is_present(group_id))
    {
        mmi_frm_group_close(group_id);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_cb
 * DESCRIPTION
 *  This function is bt dialer power on cb function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_bt_dialer_cb(MMI_BOOL is_open)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	WCHAR *item_list[BT_DEVICE_LINK_NUM];
	U32 i;
	void *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	U32 dev_num = mmi_bt_dialer_quick_conn_dev_num();
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_BT_DIALER_CB);
    if (!is_open)
    {
        return;
    }
	
    if (mmi_frm_group_is_present(GRP_ID_BT_CM_POWER_ON_CNF) == MMI_TRUE)
    {
        mmi_frm_group_close(GRP_ID_BT_CM_POWER_ON_CNF);
    }
	if ((dev_num == 1) && (srv_bt_cm_get_paired_dev_num()> 0))
	{
	// only one device pre connected, so quick connect it.
    // auto connecting
        g_mmi_bt_scr_cntx.main_gid = mmi_frm_group_get_active_id();
        mmi_bt_dialer_conn_dev_by_addr(g_connected_dev_info[0]);
	}
	else if (dev_num > 1)
	{
		if (mmi_frm_scrn_enter(
		            g_parent_id,
		            SCR_BT_INQUIRED_POWER_ON,
		            (FuncPtr) NULL,
		            (FuncPtr) mmi_bt_connected_by_app,
		            MMI_FRM_FULL_SCRN) == MMI_FALSE)
		{
		    return;
		}
		for (i = 0; i < dev_num; i++)
		{
			 	 mmi_chset_utf8_to_ucs2_string(
				 (kal_uint8*)name_buf[i],
				 SRV_BT_CM_BD_FNAME_LEN,
				 (U8*)(g_connected_dev_info[i].name));
			item_list[i] = (WCHAR*)name_buf[i];
		}
		 
		gui_buffer = mmi_frm_scrn_get_active_gui_buf();		/* get current guibuffer */
		RegisterHighlightHandler(mmi_bt_dialer_quick_list_hilite_handler);

		ShowCategory6Screen_ext(
			GetString(STR_BT_QUICK_CONN_PROMPT),
			NULL,
			(U8*)get_string(STR_GLOBAL_OK),
			get_image(IMG_GLOBAL_OK),
			(U8*)get_string(STR_GLOBAL_BACK),
			get_image(IMG_GLOBAL_BACK),
			dev_num,
			(U8**)item_list,
			0,
			0,
			gui_buffer);

		SetLeftSoftkeyFunction(mmi_bt_dialer_quick_conn_dev_lsk, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_bt_dialer_quick_conn_dev_lsk, KEY_EVENT_UP);
		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	}	    
    else
    {
    //launch app
        mmi_bt_close_group(GRP_ID_BT_CM);
        mmi_btdialer_app_launch_func(NULL,0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connected_by_app
 * DESCRIPTION
 *  This function is bt dialer connect  function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connected_by_app(mmi_scrn_essential_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	WCHAR *item_list[BT_DEVICE_LINK_NUM];
	U32 i;
	void *gui_buffer;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	U32 dev_num = mmi_bt_dialer_quick_conn_dev_num();
	if (mmi_frm_scrn_enter(
                param->group_id,
                param->scrn_id,
                (FuncPtr) NULL,
                (FuncPtr) mmi_bt_connected_by_app,
                MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
	if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
        mmi_bt_close_group(GRP_ID_BT_CM);
        mmi_bt_close_group(GRP_ID_BT_CM_POWER_ON_CNF);
    //ask power on
     	mmi_bt_register_power_on_callback_with_result(mmi_bt_dialer_cb);
        mmi_bt_dialer_power_on();
		mmi_frm_scrn_close(g_parent_id, SCR_BT_INQUIRED_POWER_ON);
    } 
	else if ((dev_num == 1) && (srv_bt_cm_get_paired_dev_num()> 0) && !srv_bt_cm_is_dev_conn_active(&g_connected_dev_info[0].bd_addr))
	{
	// only one device pre connected, so quick connect it.
    // auto connecting
        g_mmi_bt_scr_cntx.main_gid = mmi_frm_group_get_active_id();
        mmi_bt_dialer_conn_dev_by_addr(g_connected_dev_info[0]);
		mmi_frm_scrn_close(g_parent_id, SCR_BT_INQUIRED_POWER_ON);
	}
	else if ((dev_num == 1) && (srv_bt_cm_get_paired_dev_num()> 0) && srv_bt_cm_is_dev_conn_active(&g_connected_dev_info[0].bd_addr))
	{
		//launch app
	    mmi_bt_close_group(GRP_ID_BT_CM);
		mmi_btdialer_app_launch_func(NULL,0);
		mmi_frm_scrn_close(g_parent_id, SCR_BT_INQUIRED_POWER_ON);
	}
	else if (dev_num > 1)
	{
		for (i = 0; i < dev_num; i++)
		{
			 mmi_chset_utf8_to_ucs2_string(
				 (kal_uint8*)name_buf[i],
				 SRV_BT_CM_BD_FNAME_LEN,
				 (U8*)(g_connected_dev_info[i].name));
			item_list[i] = (WCHAR*)name_buf[i];
		}
		 
		gui_buffer = mmi_frm_scrn_get_active_gui_buf();		/* get current guibuffer */
		RegisterHighlightHandler(mmi_bt_dialer_quick_list_hilite_handler);

		ShowCategory6Screen_ext(
			GetString(STR_BT_QUICK_CONN_PROMPT),
			NULL,
			(U8*)get_string(STR_GLOBAL_OK),
			get_image(IMG_GLOBAL_OK),
			(U8*)get_string(STR_GLOBAL_BACK),
			get_image(IMG_GLOBAL_BACK),
			dev_num,
			(U8**)item_list,
			0,
			0,
			gui_buffer);

		SetLeftSoftkeyFunction(mmi_bt_dialer_quick_conn_dev_lsk, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_bt_dialer_quick_conn_dev_lsk, KEY_EVENT_UP);
		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);	
	}	    
    else
    {
    //launch app
        mmi_bt_close_group(GRP_ID_BT_CM);
        mmi_btdialer_app_launch_func(NULL,0);
		
		mmi_frm_scrn_close(g_parent_id, SCR_BT_INQUIRED_POWER_ON);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_show_popup
 * DESCRIPTION
 *  This function is bt dialer for app function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_bt_dialer_show_popup(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;   
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WCHAR string[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    mmi_bt_dialer_auto_reconn_reset();
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
    g_parent_id = group_id;
    if ((srv_bt_cm_get_busy_dev() == NULL) && (srv_bt_cm_get_linked_dev_list_idx() < BT_DEVICE_LINK_NUM))
    {    
        mmi_frm_scrn_first_enter(group_id,SCR_BT_INQUIRED_POWER_ON,mmi_bt_connected_by_app,NULL);
    }
    else
    {
        mmi_frm_nmgr_popup(
                     MMI_SCENARIO_ID_DEFAULT,
                     MMI_EVENT_FAILURE,
                    (WCHAR*)GetString(STR_BT_SERVICE_UNAVAILABLE));
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_app_emit_event
 * DESCRIPTION
 *  This function is bt dialer emit evnet function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_app_emit_event(U32 event_id, void* event_info, MMI_BOOL is_all_dis)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_event_struct event_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_FRM_INIT_EVENT(&event_data, event_id);
    event_data.event_info = event_info;
	event_data.is_dis_all = is_all_dis;

    MMI_FRM_CB_EMIT_EVENT(&event_data);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_connect
 * DESCRIPTION
 *  This function is bt dialer auto connect function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_auto_connect(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    srv_bt_cm_bt_addr addr;
    srv_bt_cm_dev_struct dev_info[BT_DEVICE_LINK_NUM];
    U32 dev_num;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO); 
#ifndef __MMI_BT_BTBOX_NOLCD__
    ReadRecord(NVRAM_BYTE_BT_DIALER_AUTO_CONN,1,g_connected_dev_info,sizeof(srv_bt_cm_dev_struct) *BT_DEVICE_LINK_NUM,&error);
    for(i = 0; i< BT_DEVICE_LINK_NUM; i++)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DEV_INFOR, i, g_connected_dev_info[i].bd_addr.lap,g_connected_dev_info[i].bd_addr.nap,g_connected_dev_info[i].bd_addr.uap);
    }
    dev_num = mmi_bt_dialer_quick_conn_dev_num();
    if (dev_num == 0)
    {
        return;
    }
    if ((srv_bt_cm_get_busy_dev() == NULL) && !srv_bt_cm_get_btdialor_app_mode() &&(srv_bt_cm_get_linked_dev_list_idx() <= BT_DEVICE_LINK_NUM))
    {
        if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_BT_NOT_OPEN); 
         //bt is not open
            return;
        }
        else if (srv_bt_cm_get_paired_dev_num()<= 0)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_BT_NOT_PAIRED); 
         //have not paired device
            return;
        }
        else
        {
           g_mmi_bt_scr_cntx.main_gid = mmi_frm_group_get_active_id();
			mmi_bt_dialer_conn_dev_by_addr(g_connected_dev_info[0]);
         //connect device.
        }
    }
#endif /* __MMI_BT_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_app_is_connected
 * DESCRIPTION
 *  This function is judged bt dialer is connected function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_app_is_connected()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION) ||
       srv_bt_cm_is_profile_connected(SRV_BT_CM_MAPC_CONNECTION) ||
       srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION) ||
       srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION) ||
       srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) ||
       srv_bt_cm_is_profile_connected(SRV_BT_CM_AVRCP_CT_CONNECTION) ||
       srv_bt_cm_is_profile_connected(SRV_BT_CM_SPP_CONNECTION))
    {
    	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_IS_CONNECTED); 
        return MMI_TRUE;
        
    }
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_IS_NOT_CONNECTED); 
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_app_is_connected
 * DESCRIPTION
 *  This function is judged bt dialer is connected function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_app_is_connected_ex(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_MAPC_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HFP_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_SPP_CONNECTION, dev_addr))
    {
    	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_IS_CONNECTED); 
        return MMI_TRUE;
    }
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_IS_NOT_CONNECTED); 
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_cent
 * DESCRIPTION
 *  This function is center key function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_cent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct* dev_p = srv_bt_cm_get_paired_dev_info(g_mmi_bt_scr_cntx.hilight_item);
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_OPT);
    memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &(dev_p->bd_addr), sizeof(srv_bt_cm_bt_addr));
    if (srv_bt_cm_get_btdialor_app_mode() == MMI_TRUE)
    {
        if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
        {
			mmi_bt_dialer_set_cent_flag(MMI_TRUE);
			MMI_BT_SET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_OPT);
			mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.mydev_gid);
			return;
            
        }
	    if (srv_bt_cm_get_busy_dev() == NULL)
	    {    
            if ((srv_bt_cm_is_dev_conn_active(&g_mmi_bt_scr_cntx.conn_dev_add)) && (mmi_bt_dialer_app_is_connected_ex(&g_mmi_bt_scr_cntx.conn_dev_add)))
            {
                if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION))
				{
					mmi_bt_entry_release_device_connections(g_mmi_bt_scr_cntx.mydev_gid);

				}
				else
				{

			        mmi_bt_dialor_disconnect(&g_mmi_bt_scr_cntx.conn_dev_add);
				}
            //disconnect
	        }
	        else
	        {
				#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
				mmi_bt_dialer_auto_reconn_reset();
                #endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
				if (mmi_bt_dialer_app_is_connected_ex(&g_mmi_bt_scr_cntx.conn_dev_add) || (srv_bt_cm_get_linked_dev_list_idx() == BT_DEVICE_LINK_NUM))
				{
					mmi_bt_popup_display(
								STR_BT_RELEASE_CONN_PROMPT,
								MMI_EVENT_FAILURE,
								NULL);
								return;
	    		}
	            //connect
				if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) )
				{
					if (srv_bt_cm_is_headset_connected_ex())//headset is connected,
					{
						mmi_frm_nmgr_popup(
						MMI_SCENARIO_ID_DEFAULT,
						MMI_EVENT_FAILURE,
						(WCHAR*)GetString(STR_BT_HEADSET_CONN_PROMPT));
					}
					else
					{
						mmi_bt_entry_connecting(g_mmi_bt_scr_cntx.mydev_gid);
					}
				}
				else
				{
		            mmi_bt_dialor_connect(&g_mmi_bt_scr_cntx.conn_dev_add); 
				}	
	        }
	   	}
		else
		{
			mmi_frm_nmgr_popup(
			    MMI_SCENARIO_ID_DEFAULT,
			    MMI_EVENT_FAILURE,
			   (WCHAR*)GetString(STR_BT_SERVICE_UNAVAILABLE));
		}
    }
    else
    {
        if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
        {
    
            mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.mydev_gid);
            return;
        }
    
        if (srv_bt_cm_is_dev_conn_active(&g_mmi_bt_scr_cntx.conn_dev_add))
        {
        #ifdef __MMI_BT_DIALER_SUPPORT__
            mmi_bt_dialer_set_disconn_req(MMI_TRUE);
        #endif
            mmi_bt_entry_release_device_connections(g_mmi_bt_scr_cntx.mydev_gid);
            //disconnect
        }
        else
        {
            mmi_bt_entry_mydev_ren();
            //rename
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_cent_flag
 * DESCRIPTION
 *  This function is whether is center key function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_get_cent_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_centkey_flag)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_cent_flag
 * DESCRIPTION
 *  This function is set center key flag function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_set_cent_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_centkey_flag = flag;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_shutdown
 * DESCRIPTION
 *  This function is bt dialer shutdown function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_bt_dialer_shutdown(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_bt_cm_dev_struct* dev_p =(srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(0);//  wait for Yiquan's interface
    g_id_info = id_info;
	memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &(dev_p->bd_addr), sizeof(srv_bt_cm_bt_addr));
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHUTDOWN, dev_p->bd_addr.lap, dev_p->bd_addr.uap, dev_p->bd_addr.nap); 
	
	#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
	 StopTimer(BT_DIALER_AUTO_RECONN_TIMER);
	
	mmi_bt_dialer_auto_reconn_reset();
	/*if (g_bt_dialer_reconn_flag == MMI_TRUE)
	{
		g_bt_dialer_reconn_flag = MMI_FALSE;
	}*/
	#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/  
	
	if (mmi_bt_dialer_app_is_connected_ex(&g_mmi_bt_scr_cntx.conn_dev_add))
	{
		if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION))
		{
			mmi_bt_entry_release_device_connections(g_mmi_bt_scr_cntx.mydev_gid);

		}
		else
		{

			mmi_bt_dialor_disconnect(&(dev_p->bd_addr));
		}
	    if(mmi_bt_dialer_get_disconn_req())
	    {
	        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHUTDOWN_TIMER);
	        StartTimer(BT_DIALER_DISCONN_TIMER,50,mmi_bt_dialer_disconn_hdlr);
		    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
		}
    }
    return MMI_FRM_PROC_RESULT_COMPLETED;   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_disconn_hdlr
 * DESCRIPTION
 *  This function is bt dialer disconnect hdlr in shutdown function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialer_disconn_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHUTDOWN_HDLR);

    if (!mmi_bt_dialer_get_disconn_req())
    {        
        if (mmi_bt_dialer_app_is_connected())
        {
       	    srv_bt_cm_dev_struct* dev_p =(srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(0);//  wait for Yiquan's interface
	    memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &(dev_p->bd_addr), sizeof(srv_bt_cm_bt_addr));
            if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) )
            {
                mmi_bt_entry_release_device_connections(g_mmi_bt_scr_cntx.mydev_gid);
            }
            else
            {
                mmi_bt_dialor_disconnect(&(dev_p->bd_addr));
            }
            if (mmi_bt_dialer_get_disconn_req())
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHUTDOWN_TIMER);
                StartTimer(BT_DIALER_DISCONN_TIMER,50,mmi_bt_dialer_disconn_hdlr);
            }
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SHUTDOWN_STOP_TIMER);
	    StopTimer(BT_DIALER_DISCONN_TIMER);
	    mmi_frm_proc_notify_completed(g_id_info);
	}
    }
    else
    {
        StartTimer(BT_DIALER_DISCONN_TIMER,50,mmi_bt_dialer_disconn_hdlr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_connect_time_out_hdlr
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  N/A
 *
 *
 * RETURNS
 *  N/A
 *****************************************************************************/
void mmi_bt_dialer_connect_time_out_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_TIMER_OUT_HDLR);

    if (srv_bt_cm_get_busy_dev() != NULL)
    {
// don't do connect the next profile.
        mmi_bt_dialer_set_time_out_flag(MMI_TRUE);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_TIMER_OUT_HDLR_SET_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_connecting_time_out_hdlr
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  N/A
 *
 *
 * RETURNS
 *  N/A
 *****************************************************************************/
void mmi_bt_entry_connecting_time_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_entry_connecting( mmi_frm_group_get_active_id());
}


#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_reconn_and_to_ind
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * void* para
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_auto_reconn_and_to_ind(void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_fail_conn_to_struct* event = (srv_bt_cm_fail_conn_to_struct*)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(event->reason)
    {
        case BTBM_ADP_FAIL_LINK_PAGE_TIMEOUT:
        {
            mmi_bt_dialer_connect_time_out_hdlr(NULL);
            break;
        }
        case BTBM_ADP_FAIL_LINK_CONNECTION_TIMEOUT:
        {
            mmi_bt_dialer_disconn_excpt_hdlr(&event->dev_addr);
            break;
        }
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_reconn_reset
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_auto_reconn_reset(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	StopTimer(BT_DIALER_AUTO_RECONN_TIMER);
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        srv_bt_cm_bt_addr* curr = &g_mmi_bt_reconn_ctx[i].bd_addr;
    	if (mmi_bt_dialer_is_addr_equal_0(curr))
		{
			continue;
		}
		
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO_RECONN_RESET, curr->lap, curr->uap, curr->nap);
        if (g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_flag == MMI_TRUE)
        {
            srv_bt_cm_set_auto_reconn_flag(&g_mmi_bt_reconn_ctx[i].bd_addr, MMI_FALSE);
            memset(&g_mmi_bt_reconn_ctx[i],0,sizeof(mmi_bt_reconn_ctx_struct));
        }
    }
}
	
	
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_disconn_excpt_hdlr
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  N/A
 *
 * RETURNS
 *  NMMI_BOOLA
 *****************************************************************************/
static void mmi_bt_dialer_disconn_excpt_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_reconn_ctx_struct temp_dev;
    srv_bt_cm_bt_addr* dev_addr =(srv_bt_cm_bt_addr*)msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIALER_CONNECT_LOST,
		((dev_addr->nap & 0xff00) >> 8), (dev_addr->nap & 0x00ff), (dev_addr->uap));

    memcpy(&temp_dev.bd_addr, dev_addr, sizeof(srv_bt_cm_bt_addr));
    temp_dev.bt_dialer_reconn_flag = MMI_TRUE;
    temp_dev.bt_dialer_reconn_accu_time = 0;
    temp_dev.bt_dialer_reconn_duration = MMI_BT_DIALER_AUTO_RECONN_DURATION;
    temp_dev.bt_dialer_reconn_freq = MMI_BT_DIALER_AUTO_RECONN_FREQ;
    mmi_bt_dialer_set_autoreconn_dev(&temp_dev);
    if (!mmi_bt_dialer_is_addr_equal_0(&temp_dev.bd_addr))
    {
    #ifndef __MMI_BT_BTBOX_NOLCD__
        if(!mmi_bt_dialer_app_is_connected_ex(&temp_dev.bd_addr) && !srv_bt_cm_is_dev_busy(&temp_dev.bd_addr) )
    #else /* __MMI_BT_BTBOX_NOLCD__ */
        if(!srv_bt_cm_is_dev_busy(&temp_dev.bd_addr) )
    #endif /* __MMI_BT_BTBOX_NOLCD__ */
        {
            mmi_bt_dialer_auto_reconn_first_start_check();//  for disconenction done. do the auto conenct
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_autoreconn_dev
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * mmi_bt_reconn_ctx_struct *
 *
 * RETURNS
 *  N/A
 *****************************************************************************/
static void mmi_bt_dialer_set_autoreconn_dev(mmi_bt_reconn_ctx_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 j = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SET_CONNECTED_DEV_FUNC,dev->bd_addr.lap,dev->bd_addr.nap,dev->bd_addr.uap);

    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (mmi_bt_dialer_is_addr_equal_0(&g_mmi_bt_reconn_ctx[i].bd_addr))
        {
            memcpy(&g_mmi_bt_reconn_ctx[i],dev, sizeof(mmi_bt_reconn_ctx_struct));
            srv_bt_cm_set_auto_reconn_flag(&g_mmi_bt_reconn_ctx[i].bd_addr, MMI_TRUE);
            break;
        }
    }
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO_RECONN_SET_DEV,i,g_mmi_bt_reconn_ctx[i].bd_addr.lap,g_mmi_bt_reconn_ctx[i].bd_addr.nap,g_mmi_bt_reconn_ctx[i].bd_addr.uap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_clean_autoreconn_dev
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  mmi_bt_reconn_ctx_struct *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialer_clean_autoreconn_dev(mmi_bt_reconn_ctx_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(&dev->bd_addr, &g_mmi_bt_reconn_ctx[i].bd_addr))
        {
            srv_bt_cm_set_auto_reconn_flag(&dev->bd_addr, MMI_FALSE);
            for (j = i; j < BT_DEVICE_LINK_NUM - 1; j++)
            {
                //shift array
                memcpy(&g_mmi_bt_reconn_ctx[j],&g_mmi_bt_reconn_ctx[j + 1], sizeof(mmi_bt_reconn_ctx_struct));
            }
            memset(&g_mmi_bt_reconn_ctx[BT_DEVICE_LINK_NUM - 1],0,sizeof(mmi_bt_reconn_ctx_struct));
        }
    }
    for(i = 0; i< BT_DEVICE_LINK_NUM; i++)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO_RECONN_CLEAN_DEV,i,g_mmi_bt_reconn_ctx[i].bd_addr.lap,g_mmi_bt_reconn_ctx[i].bd_addr.nap,g_mmi_bt_reconn_ctx[i].bd_addr.uap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_autoreconn_inx_array
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * srv_bt_cm_bt_addr* 
 *
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_bt_dialer_get_autoreconn_inx_array(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(&g_mmi_bt_reconn_ctx[i].bd_addr, dev_addr))
        {
            return i;
        }
    }
    
    return -1;    
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_reconn_first_start_check
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_auto_reconn_first_start_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIALER_AUTO_RECONN_STATUS, 0, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time/1000);

    if (MMI_TRUE == g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag && 0 == g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time)
    {
        if (IsMyTimerExist(BT_DIALER_AUTO_RECONN_TIMER))
        {
            StopTimer(BT_DIALER_AUTO_RECONN_TIMER);
            mmi_bt_dialer_auto_reconn_hdlr();
        }
        else
        {
        #if defined(__MMI_BT_BTBOX_NOLCD__) && defined(__MMI_BT_ANTI_LOST_BY_RSSI__)
            mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BT_ANTI_LOST_IND, mmi_bt_anti_lost_ind_proc, NULL); 
            mmi_frm_group_enter(GRP_ID_BT_ANTI_LOST_IND, MMI_FRM_NODE_NONE_FLAG);
            mmi_bt_anti_lost_send_notify(mmi_bt_anti_lost_get_notify(MMI_BT_ANTI_LOST_BTB_NOTIFY_ABDISC,0));
            kal_prompt_trace(MOD_MMI, "[BTCONN] reconnection start @ mmi_bt_dialer_auto_reconn_first_start_check");
            StartTimer(BT_DIALER_AUTO_RECONN_TIMER, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_freq, mmi_bt_dialer_auto_reconn_hdlr);
        #else /* __MMI_BT_BTBOX_NOLCD__ */
            StartTimer(BT_DIALER_AUTO_RECONN_TIMER, 500, mmi_bt_dialer_auto_reconn_hdlr);
        #endif /* __MMI_BT_BTBOX_NOLCD__ */
        }
    }
#if defined(__MMI_BT_BTBOX_NOLCD__) && defined(__MMI_BT_ANTI_LOST_BY_RSSI__)
    else if (MMI_FALSE == g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag)
    {
        kal_prompt_trace(MOD_MMI, "[BTCONN] reconnection finish");
        if (srv_btsco_is_sco_open() && srv_bt_dialer_is_any_call() 
            && !mmi_ucm_is_ucm_sg_bt(mmi_frm_group_get_active_id()))
        {
            // need create bt call group and close anti lost group by bt call
            return;
        }
        if(srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION)
            && !mmi_frm_group_is_present(GRP_ID_BT_MUSIC_NOLCD))
        {
            // need create bt music group and close anti lost group by bt music
            return;
        }
        if(mmi_frm_group_is_present(GRP_ID_BT_ANTI_LOST_IND))
        {
            kal_prompt_trace(MOD_MMI, "[BTCONN] reconnection end @ mmi_bt_dialer_auto_reconn_first_start_check");
            mmi_frm_group_close(GRP_ID_BT_ANTI_LOST_IND);
}
    }
#endif /* __MMI_BT_BTBOX_NOLCD__ && __MMI_BT_ANTI_LOST_BY_RSSI__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_reconn_hdlr
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * void
 *
 * RETURNS
 * void
 *****************************************************************************/
void mmi_bt_dialer_auto_reconn_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIALER_AUTO_RECONN,g_mmi_bt_reconn_ctx[0].bd_addr.lap,g_mmi_bt_reconn_ctx[0].bd_addr.nap,g_mmi_bt_reconn_ctx[0].bd_addr.uap, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time/1000);
    g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time += g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_freq;
    if (g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time > g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_duration)
    {
        g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag = MMI_FALSE;
    }
    if (g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag == MMI_FALSE)
    {
        g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time = 0;
        StopTimer(BT_DIALER_AUTO_RECONN_TIMER);
        mmi_bt_dialer_clean_autoreconn_dev(&g_mmi_bt_reconn_ctx[0]);
        mmi_bt_dialer_auto_reconn_first_start_check();
        return;
    }
    mmi_bt_dialer_auto_reconn_start();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_reconn_start
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_auto_reconn_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BT_BTBOX_NOLCD__
    const srv_bt_cm_dev_struct* dev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_p = srv_bt_cm_get_dev_info_by_addr(&g_mmi_bt_reconn_ctx[0].bd_addr,SRV_BT_CM_ALL_DEV);
    g_mmi_bt_scr_cntx.main_gid = mmi_frm_group_get_active_id();

    memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &g_mmi_bt_reconn_ctx[0].bd_addr, sizeof(srv_bt_cm_bt_addr));
#endif /* __MMI_BT_BTBOX_NOLCD__ */

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIALER_AUTO_RECONN,g_mmi_bt_reconn_ctx[0].bd_addr.lap,g_mmi_bt_reconn_ctx[0].bd_addr.nap,g_mmi_bt_reconn_ctx[0].bd_addr.uap, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_flag, g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_accu_time/1000);

    StartTimer(BT_DIALER_AUTO_RECONN_TIMER,g_mmi_bt_reconn_ctx[0].bt_dialer_reconn_freq, mmi_bt_dialer_auto_reconn_hdlr);

#ifndef __MMI_BT_BTBOX_NOLCD__
    if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) )
    {
        kal_prompt_trace(MOD_MMI_CONN_APP, "[btconn]WWWW");
        if(!srv_bt_cm_is_headset_connected_ex())//headset is connected, 
        {
            kal_prompt_trace(MOD_MMI_CONN_APP, "[btconn]SDGFSGDFDF");
            mmi_bt_entry_connecting(g_mmi_bt_scr_cntx.mydev_gid);
        }
    }
    else
#endif /* __MMI_BT_BTBOX_NOLCD__ */
    {
        mmi_bt_dialor_connect(&g_mmi_bt_reconn_ctx[0].bd_addr);
    }

#if defined(__MMI_BT_BTBOX_NOLCD__) && defined(__MMI_BT_ANTI_LOST_BY_RSSI__)
    mmi_bt_anti_lost_send_notify(mmi_bt_anti_lost_get_notify(MMI_BT_ANTI_LOST_BTB_NOTIFY_RECONNECT, 0));
#endif /* __MMI_BT_BTBOX_NOLCD__ && __MMI_BT_ANTI_LOST_BY_RSSI__ */
}


#ifdef __MMI_BT_BTBOX_NOLCD__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_auto_reconn_restart
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_auto_reconn_restart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_RECONN_RESTART);

    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        srv_bt_cm_bt_addr* curr = &g_mmi_bt_reconn_ctx[i].bd_addr;

        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO_RECONN_RESET, curr->lap, curr->uap, curr->nap);

        if (g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_flag == MMI_TRUE)
        {
            g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_accu_time = 0;
            g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_duration = MMI_BT_DIALER_AUTO_RECONN_DURATION;
            g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_freq = MMI_BT_DIALER_AUTO_RECONN_FREQ;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_reconn_item
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_bt_dialer_get_reconn_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_flag)
            break;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ANTILOST_RECONN_GET_ITEM, i);

    return i;
}

#endif /* __MMI_BT_BTBOX_NOLCD__ */
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/


#ifdef __MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_acl_timeout_discon_hdlr
 * DESCRIPTION
 *  bt acl disconncet timeout event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_dialer_acl_timeout_discon_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID parent_id = mmi_frm_group_get_active_id();
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the SCR_BT_CONNECTING screen is exist or not */
    if (mmi_frm_scrn_is_present(parent_id, SCR_BT_CONNECTING, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(parent_id, SCR_BT_CONNECTING);
    }
    if (mmi_bt_dialer_app_is_connected())
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_HIGHEST_SCRN,
            MMI_EVENT_WARNING,
            (WCHAR*)GetString(STR_BT_TIMEOUT_DISCON_ED));
    }
    return MMI_RET_OK;
}
#endif /*__MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_enhanced_init
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_enhanced_init(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_flag = MMI_FALSE;
        g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_accu_time = 0;
        g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_duration = MMI_BT_DIALER_AUTO_RECONN_DURATION;
        g_mmi_bt_reconn_ctx[i].bt_dialer_reconn_freq = MMI_BT_DIALER_AUTO_RECONN_FREQ;
    }
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_headset_flag
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_get_headset_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_GET_HS_FLAG, g_mmi_bt_dialer_headset_flag);
    return g_mmi_bt_dialer_headset_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_headset_flag
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  MMI_BOOL
 *
 * RETURNS
 * void
 *****************************************************************************/
void mmi_bt_dialer_set_headset_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_dialer_headset_flag = flag;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SET_HS_FLAG, g_mmi_bt_dialer_headset_flag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_diconn_dev_func
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  srv_bt_cm_bt_addr* 
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_diconn_dev_func(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	const srv_bt_cm_dev_struct* dev_p;
    g_mmi_bt_scr_cntx.main_gid = mmi_frm_group_get_active_id();
	dev_p = srv_bt_cm_get_dev_info_by_addr(dev_addr,SRV_BT_CM_ALL_DEV);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DISCONN_DEV_FUNC, dev_addr->uap, dev_addr->nap, dev_addr->lap);

    memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), dev_addr, sizeof(srv_bt_cm_bt_addr));
    if (srv_bt_cm_get_busy_dev() == NULL)
    {    
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SRV_NO_BUSY);

        if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) )
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_BT_HEADSET);
            mmi_bt_dialer_set_disconn_req(MMI_TRUE);
            mmi_bt_entry_release_device_connections( g_mmi_bt_scr_cntx.main_gid);
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_BT_PHONE);
            mmi_bt_dialor_disconnect(&(g_mmi_bt_scr_cntx.conn_dev_add));
        }
    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_BT_SERVICE_UNAVAILABLE));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_all_disconn_flag
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  MMI_BOOL
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_set_all_disconn_flag(MMI_BOOL is_all_disconn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	g_bt_is_all_disconn = is_all_disconn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_ALL_DISCONN_FLAG, g_bt_is_all_disconn);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_all_disconn_flag
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_get_all_disconn_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	return g_bt_is_all_disconn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_ALL_DISCONN_FLAG, g_bt_is_all_disconn);
}
	

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_connected_dev_info
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  srv_bt_cm_dev_struct *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_set_connected_dev_info(srv_bt_cm_dev_struct *dev_info)
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
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SET_CONNECTED_DEV_FUNC,dev_info->bd_addr.lap,dev_info->bd_addr.nap,dev_info->bd_addr.uap);

    if(!srv_bt_cm_is_dev_addr_equal(&g_connected_dev_info[0].bd_addr, &dev_info->bd_addr))
    {
        for(p = BT_DEVICE_LINK_NUM-1; p > 0; p--)
        {
            memcpy(&g_connected_dev_info[p],&g_connected_dev_info[p-1], sizeof(srv_bt_cm_dev_struct));
        }
        memcpy(&g_connected_dev_info[0],dev_info, sizeof(srv_bt_cm_dev_struct));
    }

#ifndef __MMI_BT_BTBOX_NOLCD__
    WriteRecord(NVRAM_BYTE_BT_DIALER_AUTO_CONN,1,(void*)g_connected_dev_info, sizeof(srv_bt_cm_dev_struct) *BT_DEVICE_LINK_NUM ,&error); 
#endif /* __MMI_BT_BTBOX_NOLCD__ */

    for(i = 0; i< BT_DEVICE_LINK_NUM; i++)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DEV_INFOR, i, g_connected_dev_info[i].bd_addr.lap,g_connected_dev_info[i].bd_addr.nap,g_connected_dev_info[i].bd_addr.uap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_clean_connected_dev_info
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  srv_bt_cm_dev_struct *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_clean_connected_dev_info(srv_bt_cm_dev_struct *dev_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_CLN_DEV_INFO_FUN);

    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(&g_connected_dev_info[i].bd_addr, &dev_info->bd_addr))
        {
        #ifndef __MMI_BT_BTBOX_NOLCD__
            for (j = i; j < BT_DEVICE_LINK_NUM - 1; j++)
            {
                //shift array
                memcpy(&g_connected_dev_info[j], &g_connected_dev_info[j + 1], sizeof(srv_bt_cm_dev_struct));
            }
            memset(&g_connected_dev_info[BT_DEVICE_LINK_NUM - 1], 0, sizeof(srv_bt_cm_dev_struct));
        #else /* __MMI_BT_BTBOX_NOLCD__ */
            memset(&g_connected_dev_info[i], 0, sizeof(srv_bt_cm_dev_struct));
        #endif /* __MMI_BT_BTBOX_NOLCD__ */
        }
    }
#ifndef __MMI_BT_BTBOX_NOLCD__
    WriteRecord(NVRAM_BYTE_BT_DIALER_AUTO_CONN, 1, g_connected_dev_info, sizeof(srv_bt_cm_dev_struct) *BT_DEVICE_LINK_NUM ,&error); 
#endif /* __MMI_BT_BTBOX_NOLCD__ */
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DEV_INFOR, i, g_connected_dev_info[i].bd_addr.lap,g_connected_dev_info[i].bd_addr.nap,g_connected_dev_info[i].bd_addr.uap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_quick_list_hilite_handler
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  S32
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialer_quick_list_hilite_handler(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    g_quick_conn_idx = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_QUICK_LIST_HILITE_HANDLE_FUN,g_quick_conn_idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_quick_conn_dev_num
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 mmi_bt_dialer_quick_conn_dev_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 count = 0;
	U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < BT_DEVICE_LINK_NUM; i++)
    {
        if (!mmi_bt_dialer_is_addr_equal_0(&g_connected_dev_info[i].bd_addr))
        {
            count++;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_QUICK_CONN_DEV_NUM_FUN,count);
    MMI_ASSERT(count <= BT_DEVICE_LINK_NUM);

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_quick_conn_dev_lsk
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * void
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialer_quick_conn_dev_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_bt_dialer_app_is_connected_ex(&g_connected_dev_info[g_quick_conn_idx].bd_addr))
    {
        g_mmi_bt_scr_cntx.main_gid = mmi_frm_group_get_active_id();
        mmi_bt_dialer_conn_dev_by_addr(g_connected_dev_info[g_quick_conn_idx]);
    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_BT_DEVICE_BEING_CONNECTED));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_conn_dev_by_addr
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  srv_bt_cm_dev_struct
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_conn_dev_by_addr(srv_bt_cm_dev_struct dev_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_is_dev_cod_match(dev_info.cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) )
    {
        // this place is no need to add jude ttwo headset case, because it will not use under have connected device.
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_QUICK_CONNECTHS);
        memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &dev_info.bd_addr, sizeof(srv_bt_cm_bt_addr));
        mmi_bt_entry_connecting(g_mmi_bt_scr_cntx.main_gid);
    }
    else
    {
        //g_mmi_bt_scr_cntx.main_gid = mmi_frm_group_get_active_id();
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_AUTO_CASE); 
        memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &dev_info.bd_addr, sizeof(srv_bt_cm_bt_addr));
        mmi_bt_dialor_connect(&dev_info.bd_addr);
    }
}


/* connecting screen common UI */
/*****************************************************************************
 * FUNCTION
 *  cui_bt_dialer_connecting_create
 * DESCRIPTION
 *  This function is to create connecting screen common UI
 *  if the common UI is unable to entry, it will return GRP_ID_INVALID
 *  caller need to check the returned group id to see if the common UI can be entry
 * PARAMETERS
 *  parent_gid : parent or caller id
 * RETURNS
 *  mmi_id        return GRP_ID_BT_CM_CONNECTING_SCR, which is power on confirm group id
 *                or return GRP_ID_INVALID if common UI can not be entry
 *****************************************************************************/
mmi_id cui_bt_dialer_connecting_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_get_busy_dev()!=NULL)
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_SRV_NO_BUSY); 
        g_id = mmi_frm_group_create(parent_gid, GRP_ID_BT_CM_CONNECTING_SCR, cui_bt_dialer_connecting_proc, &g_mmi_bt_scr_cntx);
        g_mmi_bt_scr_cntx.main_gid = GRP_ID_BT_CM_CONNECTING_SCR;
		g_mmi_bt_scr_cntx.dialer_cnting_cui_state = MMI_TRUE;
		g_mmi_bt_scr_cntx.dialer_cnting_cui_notify_flag = MMI_FALSE;
    }

    return g_id;
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_power_on_run
 * DESCRIPTION
 *  This function is to run power on confirm screen common UI
 *  It will entry a screen group and entry power on confirm screen
 * PARAMETERS
 *  cui_id : common UI ID
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret cui_bt_dialer_connecting_run(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(g_mmi_bt_scr_cntx.dialer_cnting_cui_state);

    mmi_frm_group_enter(GRP_ID_BT_CM_CONNECTING_SCR, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_bt_show_progress_scr(
                   cui_id,
                   SCR_BT_CONNECTING,
                   STR_GLOBAL_CONNECTING,
                   STR_GLOBAL_CONNECTING,
                   NULL);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_dialer_connecting_proc
 * DESCRIPTION
 *  This function is to handle event from framework on connecting common UI
 * PARAMETERS
 *  evt : mmi event
 * RETURNS
 *  mmi_ret     return MMI_RET_OK
 *****************************************************************************/
mmi_ret cui_bt_dialer_connecting_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            
            g_mmi_bt_scr_cntx.main_gid = 0;
            g_mmi_bt_scr_cntx.dialer_cnting_cui_state = MMI_FALSE;
            g_mmi_bt_scr_cntx.dialer_cnting_cui_notify_flag = MMI_FALSE;   
        }
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_power_on_close
 * DESCRIPTION
 *  This function is to close power on confirm common UI
 * PARAMETERS
 *  cui_gid : common UI group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_dialer_connecting_close(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_scr_cntx.pwr_cnf_cui_state = MMI_FALSE;
    mmi_frm_group_close(cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_vis_change_flag
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * MMI_BOOL
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_dialer_set_vis_change_flag(MMI_BOOL is_change)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_is_vis_change_in_busy_state = is_change;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_VIS_CHANGE_FLAG, g_mmi_is_vis_change_in_busy_state);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_vis_change_flag
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_bt_dialer_get_vis_change_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_VIS_CHANGE_FLAG, g_mmi_is_vis_change_in_busy_state);
    return g_mmi_is_vis_change_in_busy_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_is_addr_equal_0
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * const srv_bt_cm_bt_addr*
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_is_addr_equal_0(const srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dev_addr)
    {
        if ((dev_addr->lap == 0) &&
            (dev_addr->uap == 0) &&
            (dev_addr->nap == 0))
        {
        	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_ADDR_EQUAL_ZERO,dev_addr->lap,dev_addr->uap,dev_addr->nap);
            return MMI_TRUE;
        }
    }
    
    return MMI_FALSE;
}

#ifdef __MMI_A2DP_SUPPORT__
#ifdef __MMI_BT_SPEAKER_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialor_connect_a2dp_src_cb
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * srv_bt_cm_bt_addr*
 * srv_bt_cm_connection_type
 * MMI_BOOL
 * MMI_BOOL
 * MMI_BOOL
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialor_connect_a2dp_src_cb(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_dev_struct* dev_p ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WCHAR string[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};
    dev_p = (srv_bt_cm_dev_struct*)srv_bt_cm_get_dev_info(dev_addr);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_A2DP_SRC_CB,is_connect, result, dev_addr->lap,dev_addr->uap,dev_addr->nap);

    if(is_connect)
    {
        if(result)
        {
            mmi_bt_show_dialor_conn_success(dev_p);
            mmi_bt_dialer_set_headset_flag(MMI_TRUE);
        }
        else
        {
        #ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
            srv_bt_cm_set_dev_busy_state(dev_addr, SRV_BT_CM_A2DP_CONNECTION, MMI_FALSE);
            srv_bt_cm_set_dev_link_state(&dev_p->bd_addr,MMI_FALSE);
            if(MMI_TRUE == srv_bt_cm_get_auto_reconn_flag(dev_addr))
            {
                return;
            }
            else
            {
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*)string,
                    (SRV_BT_CM_BD_UCS2_NAME_LEN * 2),
                    (kal_uint8*)dev_p->name);
                mmi_wcscat((WCHAR*)string, (WCHAR*)GetString(STR_BT_CONN_FAILED));
                mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_BT_CONN_FAILED));
            }
        #else
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*)string,
                (SRV_BT_CM_BD_UCS2_NAME_LEN * 2),
                (kal_uint8*)dev_p->name);
            mmi_wcscat((WCHAR*)string, (WCHAR*)GetString(STR_BT_CONN_FAILED));
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_BT_CONN_FAILED));
        #endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
            srv_bt_cm_set_dev_link_state(&dev_p->bd_addr,MMI_FALSE);
        }
    }
#ifdef __MMI_BTBOX_NOLCD__
    btb_connect_a2dp_src_cb(dev_addr, conn_type, result, is_connect, is_indicate);
#endif  //__MMI_BTBOX_NOLCD__
    srv_bt_cm_set_dev_busy_state(dev_addr, SRV_BT_CM_A2DP_CONNECTION, MMI_FALSE);
    cui_bt_dialer_connecting_close(g_mmi_bt_scr_cntx.cnting_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_connect_a2dp_src
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * srv_bt_cm_bt_addr* 
 * mmi_id group_id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dialer_connect_a2dp_src(srv_bt_cm_bt_addr *dev_addr, mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__		
	if(MMI_TRUE != srv_bt_cm_get_auto_reconn_flag(dev_addr))
	{
    #if !defined(__MMI_BTBOX_NOLCD__)

		g_mmi_bt_scr_cntx.cnting_cui_gid = cui_bt_dialer_connecting_create(group_id);
		cui_bt_dialer_connecting_run(g_mmi_bt_scr_cntx.cnting_cui_gid);

    #endif  //!defined(__MMI_BTBOX_NOLCD__)
	}
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
	
    srv_bt_cm_set_dev_busy_state(dev_addr, SRV_BT_CM_A2DP_CONNECTION, MMI_TRUE);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_A2DP_SRC,dev_addr->lap,dev_addr->uap,dev_addr->nap);
    srv_bt_a2dp_src_cm_connect_req(dev_addr, mmi_bt_dialor_connect_a2dp_src_cb);
}


#endif/*__MMI_BT_SPEAKER_SUPPORT__*/
#endif/*__MMI_A2DP_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_disconnect_by_dev_info
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * srv_bt_cm_dev_struct*
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_dialer_disconnect_by_dev_info(srv_bt_cm_dev_struct* dev_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIS_BY_DEV_INFO_FUNC,dev_p->bd_addr.lap, dev_p->bd_addr.uap, dev_p->bd_addr.nap);

    if (srv_bt_cm_get_busy_dev()== NULL)
    {    
        if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) )
        {
            mmi_bt_entry_release_device_connections(g_mmi_bt_scr_cntx.mydev_gid);
        }
        else
        {
            mmi_bt_dialor_disconnect(&(dev_p->bd_addr));
        }
    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_BT_SERVICE_UNAVAILABLE));

        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_conn_set_vis_state
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * void
 *
 * RETURNS
 * void
 *****************************************************************************/
void mmi_bt_dialer_conn_set_vis_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_bt_conn_set_vis_struct vis_dev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIS_SET_VIS_STATE_FUNC, vis_dev.g_vis_type);

    vis_dev = mmi_bt_dialer_get_conn_vis_enum();
    if(mmi_bt_dialer_get_vis_change_flag())
    {
        switch(vis_dev.g_vis_type)
        {
            case MMI_BT_CONN_NONE:
            {
                break;
            }
            case MMI_BT_CONN_ACTIVE:
            {
                mmi_bt_dialor_connect_int(&vis_dev.bd_addr, &vis_dev.callback_item);
                // call function
                break;
            }
            case MMI_BT_CONN_PASSIVE:
            {
                // call function
                mmi_bt_dialor_callback_int(&vis_dev.bd_addr,vis_dev.result,vis_dev.is_connect, &vis_dev.callback_item);
                break;
            }
            case MMI_BT_CONN_DONE:
            {
                // call function
                mmi_bt_dialer_set_vis_change_flag(MMI_FALSE);
                mmi_bt_dialer_callback_done_int(&vis_dev.bd_addr, vis_dev.is_connect);
                break;
            }
            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_get_conn_vis_enum
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * void
 *
 * RETURNS
 *  mmi_bt_conn_set_vis_struct
 *****************************************************************************/
static mmi_bt_conn_set_vis_struct mmi_bt_dialer_get_conn_vis_enum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIS_GET_VIS_STATE_FUNC, g_mmi_bt_change_vis_dev.g_vis_type);
    return g_mmi_bt_change_vis_dev;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_set_conn_vis_enum
 * DESCRIPTION
 *  N/A
 * PARAMETERS
 * mmi_bt_conn_set_vis_struct
 * MMI_BOOL
 *
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_bt_dialer_set_conn_vis_enum(mmi_bt_conn_set_vis_struct change_vis_dev, MMI_BOOL prevent_conn_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_DIS_SET_VIS_ENUM_FUNC, g_mmi_bt_change_vis_dev.g_vis_type, prevent_conn_flag);

#ifndef __MMI_BTBOX_NOLCD__
        if(SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_set_prevent_connect_flag(prevent_conn_flag))
        {
            g_mmi_bt_change_vis_dev.g_vis_type = change_vis_dev.g_vis_type;
            g_mmi_bt_change_vis_dev.is_connect = change_vis_dev.is_connect;
            memcpy(&g_mmi_bt_change_vis_dev.bd_addr,&change_vis_dev.bd_addr, sizeof(srv_bt_cm_bt_addr));
            memcpy(&g_mmi_bt_change_vis_dev.callback_item,&change_vis_dev.callback_item, sizeof(mmi_bt_dialer_conn_callback_item));
            g_mmi_bt_change_vis_dev.result = change_vis_dev.result;
            return MMI_TRUE;
        }
#endif /* __MMI_BTBOX_NOLCD__ */

    return MMI_FALSE;
}
#endif/*__MMI_BT_DIALER_SUPPORT__*/
#endif/*__MMI_BT_SUPPORT__ */
