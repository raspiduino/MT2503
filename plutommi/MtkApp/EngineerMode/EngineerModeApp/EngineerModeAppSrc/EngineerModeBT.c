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
 *  EngineerModeBT.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Engineer mode bluetooth raleted items, includes:
 *      - General Test
 *      - RF Test
 *      - Get Chip Version
 *      - UPF IOT
 *      - Limited discoverable
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"


#include "MMIDataType.h"
#include "gui_data_types.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_list.h"
#include "GlobalMenuItems.h"
#include "CustMenuRes.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "wgui_inline_edit.h"
#include "ImeGprot.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "wgui_categories_popup.h"
#include "kal_public_api.h"
#include "GpioSrvGprot.h"
#include "mmi_res_range_def.h"
#include "stdio.h"
#include "wgui_fixed_menus.h"
#include "mmi_frm_queue_gprot.h"
#include "stdlib.h"
#include "gui_typedef.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "DebugInitDef_Int.h"

#include "PhoneSetupGprots.h"
#include "CommonScreens.h"

#include "ShutdownSrvGprot.h"

#include "EngineerModeUtil.h"
#include "EngineerModeDef.h"
#include "EngineerModeCommUI.h"
#include "ProfilesSrvGProt.h"
#include "BTMMIScrGprots.h"
#include "bluetooth_struct.h"

#ifdef __MMI_EM_BT_GENERAL_TEST__

#ifdef __BT_HFG_SUPPORT__
#include "BthScoPathSrvGProt.h"
#endif

#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
#include "BTMMIAVRCPGProt.h"
#include "AvrcpSrvGprot.h"
#endif

#ifdef __MMI_EM_BT_RF_TEST__
#include "EngineerMode.h"
#endif

#ifdef __MMI_EM_BT_BQB_HID_SUPPORT__
#include "Bt_hidd_struct.h"
#include "BtcmSrvGprot.h"
#include "AlertScreen.h"
#include "bt_dm_struct.h"
#include "CommonScreensResDef.h"
#include "mmi_rp_app_bluetooth_def.h"
#endif

#include "EngineerModeBT.h"

#include "mmi_rp_app_engineermode1_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_EM_CAPTION_1        CUI_INLINE_ITEM_ID_BASE+0
#define MMI_EM_CAPTION_2     	CUI_INLINE_ITEM_ID_BASE+1
#define MMI_EM_CAPTION_3     	CUI_INLINE_ITEM_ID_BASE+2
#define MMI_EM_CAPTION_4     	CUI_INLINE_ITEM_ID_BASE+3
#define MMI_EM_STR_SELECT_1     CUI_INLINE_ITEM_ID_BASE+4
#define MMI_EM_STR_SELECT_2     CUI_INLINE_ITEM_ID_BASE+5
#define MMI_EM_TEXT_EDIT_1   	CUI_INLINE_ITEM_ID_BASE+6
#define MMI_EM_TEXT_EDIT_2  	CUI_INLINE_ITEM_ID_BASE+7
#define MMI_EM_TEXT_EDIT_3  	CUI_INLINE_ITEM_ID_BASE+8

#define BT_ADDRESS_LEN     (12)
#define BT_PASSWORD_LEN    (16)

#ifdef __MMI_EM_BT_GET_CHIP_VERION__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_BT_GET_CHIP_VERION__ */

#ifdef __MMI_EM_BT_BQB_HID_SUPPORT__
#define EM_BT_HID_AUTHORIZE_TIME   (30000)
#define EM_BT_HID_NUM_OF_CTRL_DATA (4)
#define EM_BT_HID_MAX_CTRL_DATA_LENGTH (9)

typedef enum{
    MMI_EM_BT_HID_STATE_IDLE,
    MMI_EM_BT_HID_STATE_ACTIVATING,
    MMI_EM_BT_HID_STATE_ACTIVATED,
    MMI_EM_BT_HID_STATE_AUTHORIZING,
    MMI_EM_BT_HID_STATE_WAITCONNECTING,
    MMI_EM_BT_HID_STATE_CONNECTED,
    MMI_EM_BT_HID_STATE_DISCONNECTING,
    MMI_EM_BT_HID_STATE_DISCONNECTED,
    MMI_EM_BT_HID_STATE_DEACTIVATING,
} mmi_em_bt_hid_state_enum;

typedef enum{
    SRV_EM_BT_HID_ACTIVATED_NOTIFY,
    SRV_EM_BT_HID_CONNECTABLE_NOTIFY,
    SRV_EM_BT_HID_CONNECTED_NOTIFY,
    SRV_EM_BT_HID_WAIT_NOTIFY
} srv_em_bt_hid_notify;

typedef struct{
    MMI_ID hid_group;
    mmi_em_bt_hid_state_enum state;
    srv_bt_cm_bt_addr last_device;
    U16 trans_data_flag;
#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
    U32 handle;
#endif
} mmi_em_bt_hid_cntx;

#endif


/***************************************************************************** 
 * Static Variable
 *****************************************************************************/
#ifdef __MMI_EM_BT_UPF_IOT_TEST__
#define EM_BT_UPF_IOT_BUFFER_SIZE (12)
static const UI_character_type g_em_bt_upf_iot_cha[] = L"a-f0-9";
#endif /* __MMI_EM_BT_UPF_IOT_TEST__ */

#ifdef __MMI_EM_BT_BQB_HID_SUPPORT__
mmi_em_bt_hid_cntx g_mmi_em_bt_hid_cntx;

#define EM_BT_HID_CHANGE_STATE(s) g_mmi_em_bt_hid_cntx.state = s

const U8 hid_control_data_desktop[EM_BT_HID_NUM_OF_CTRL_DATA][EM_BT_HID_MAX_CTRL_DATA_LENGTH] =
{
    {0x02, 0x00, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x02, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x02, 0x00, 0x00, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x02, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00}
};
#endif

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Static Function
 *****************************************************************************/
#ifdef __MMI_EM_BT_GENERAL_TEST__
static void mmi_em_bt_test_mode(void);
static void mmi_em_bt_test_mode_reserved(void);
#endif

#ifdef __MMI_EM_BT_AUDIO_CONN__
static void mmi_em_entry_bt_remove_and_add_aud_conn(MMI_ID cur_item_id);
#endif /* __MMI_EM_BT_AUDIO_CONN__ */

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
#ifdef __MMI_EM_BT_BQB_HID_SUPPORT__
static void mmi_em_bt_hid_screen_init();
static void mmi_em_bt_hid_init();
static void mmi_em_bt_hid_activate_req();
static void mmi_em_bt_hid_deactivate_req();
static void mmi_em_bt_hid_deactivate_cnf_hdler();
static void mmi_em_bt_hid_activate_cnf_hdler(void* arg);
static void mmi_em_bt_hid_authorize_ind_hdlr(void *arg);
static void mmi_em_bt_hid_authorize_rsp(mmi_event_struct* evt);
static void mmi_em_bt_hid_authorize_accept();
static void mmi_em_bt_hid_authorize_reject();
static void mmi_em_bt_hid_authorize_send_msg(bt_hidd_connect_authorization_enum rst);
static void mmi_em_bt_hid_authorize_timeout_rsp(void* arg);
static void mmi_em_bt_hid_connect_ind_hdler(void* arg);
static void mmi_em_bt_hid_trans_data();
static void mmi_em_bt_hid_interrupt_data_req(U8 data_len, U8* data_ptr);
static void mmi_em_bt_hid_disconnect_req();
static void mmi_em_bt_hid_disconncet_ind_hdler();
static void mmi_em_bt_hid_disconnect_cnf_hdler(void* arg);
static void mmi_em_bt_hid_connect_req();
void mmi_em_bt_hid_connectable_highlight();
void mmi_em_bt_hid_connect_highlight();
void mmi_em_bt_hid_trans_data_highlight(U32 hiliteId);
void mmi_em_bt_hid_trans_data_highlight(U32 hiliteId);
static void mmi_em_bt_hid_show_screen(srv_em_bt_hid_notify evt);
static void mmi_em_bt_hid_screen_enter();
static void mmi_em_bt_hid_connectable_screen_enter();
static void mmi_em_bt_hid_connected_screen_enter();
static void mmi_em_bt_hid_wait_screen();
U8 mmi_em_bt_hid_screen_del_cb();
static void mmi_em_bt_hid_send_msg(U32 msg_id, void* p_local_para);
void mmi_em_bt_hid_screen_highlight_hdler(U32 hiliteId);
static void mmi_em_bt_hid_connect_cnf_hdler(void* arg);
static void mmi_em_bt_hid_unplug_ind_hdlr(void* arg);
static void mmi_em_bt_hid_authorize_screen_enter(srv_bt_cm_bt_addr* bt_addr);
#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
void mmi_em_bt_hid_Limited_vis_highlight(void);
static void mmi_em_bt_hid_limit_discover_screen_enter();
#endif

#endif

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

#if defined(__MMI_BT_SUPPORT__) && defined(__MMI_AVRCP_DEBUG__) && defined(__MMI_AVRCP_CT_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  HighlightEmBTAVRCPCmdList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_avrcp_ct_main(void);

static void mmi_em_bt_avrcp_cmd_list_hdlr(void)
{
    mmi_bt_avrcp_ct_main();
}
#endif /* defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_DEBUG__) && defined(__MMI_AVRCP_CT_SUPPORT__) */

#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
/*****************************************************************************
 * FUNCTION
 *  mmi_em_bt_toggle_avrcp_connect_ct_actively
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_bt_toggle_avrcp_connect_ct_actively(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_set_actively_connect_tg_flag((MENU_ID_EM_MISC_ON == menu_id)?MMI_TRUE:MMI_FALSE);
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, mmi_em_get_root_group(), NULL);
}
#endif  /* __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__ */

static void mmi_em_bt_test_mode()
{
#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
	mmi_em_dualmode_enter_flight_mode((FuncPtr)mmi_em_bt_test_mode_reserved);
#else	
	mmi_em_bt_test_mode_reserved();
#endif
}

static void mmi_em_bt_test_mode_reserved(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bt_test_mode_req_struct *param_ptr;

    param_ptr = (bt_test_mode_req_struct *)construct_local_para(
                    (kal_uint16)sizeof(bt_test_mode_req_struct), 
                    TD_CTRL);

    param_ptr->mode = 1;

#if (MMI_MAX_SIM_NUM >= 2)
    param_ptr->dual_sim_uart_setting = PhnsetGetUARTConfig();
#endif

    mmi_frm_send_ilm((oslModuleType) MOD_BT, MSG_ID_BT_TEST_MODE_REQ, 
        (oslParaType*)param_ptr, NULL);

    mmi_em_popup_by_str(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
}

#ifdef __MMI_EM_BT_AUDIO_CONN__
static void mmi_em_entry_bt_remove_and_add_aud_conn(MMI_ID cur_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __BT_HFG_SUPPORT__
    if (cur_item_id == MENU_ID_EM_BT_ADD_AUDIO_CONNECTION)
        srv_btsco_connect_sco_req(NULL);
    else
        srv_btsco_disconnect_sco_req();
#endif
    mmi_em_popup_by_str(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
}
#endif /* __MMI_EM_BT_AUDIO_CONN__ */


static const cui_inline_item_caption_struct g_mmi_em_bt_bd_addr = 
{
    STR_ID_EM_BT_BD_ADDR,
};

static const cui_inline_item_text_edit_struct g_mmi_em_bt_bd_addr_edit =
{
    0,
    0,
    10,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE,
    0,
    NULL    
};

static const cui_inline_item_caption_struct g_mmi_em_bt_bd_pw = 
{
    STR_ID_EM_BT_BD_PASSWORD,
};

static const cui_inline_item_text_edit_struct g_mmi_em_bt_bd_pw_edit =
{
    0,
    0,
    10,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE,
    0,
    NULL    
};

static const cui_inline_set_item_struct g_mmi_em_bt_bd_lookback_inline[] = 
{
    {MMI_EM_CAPTION_1, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_bt_bd_addr},
    {MMI_EM_TEXT_EDIT_1, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_bt_bd_addr_edit},
    {MMI_EM_CAPTION_2, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_bt_bd_pw},
    {MMI_EM_TEXT_EDIT_2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_bt_bd_pw_edit},
};

static const cui_inline_struct g_mmi_em_bt_bd_lookback_inline_screen = 
{
    sizeof(g_mmi_em_bt_bd_lookback_inline)/sizeof(cui_inline_set_item_struct),
    STR_ID_EM_BT_LOOKBACK,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_bt_bd_lookback_inline,
};

void mmi_em_bt_bd_lookback_scrn_hdlr(void)
{
    MMI_ID gid;


    gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
              GRP_ID_AUTO_GEN, 
              mmi_em_bt_bd_lookback_scrn_proc, NULL,
              MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_inline_run(cui_inline_create(gid, &g_mmi_em_bt_bd_lookback_inline_screen));
}

MMI_RET mmi_em_bt_bd_lookback_scrn_proc(mmi_event_struct *evt)
{
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;

 
    switch(evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        mmi_em_bt_loop_back_req_hdlr(inline_evt);
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        cui_inline_close(inline_evt->sender_id);
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}

MMI_BOOL mmi_em_bt_addr_wcs2char(WCHAR* wcs_addr, CHAR* acs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcs_to_asc(acs, wcs_addr);

    /* Re-transfer BT address. And check if the bt address is valid.  */
    for (i = 0; i < 12; i++)
    {
        if (acs[i] >= '0' && acs[i] <= '9')         /* 0 ~ 9 */
        {
            acs[i] = acs[i] - '0';
        }
        else if (acs[i] >= 'A' && acs[i] <= 'F')    /* A ~ F */
        {
            acs[i] = acs[i] - 'A' + 10;
        }
        else if (acs[i] >= 'a' && acs[i] <= 'f')    /* a ~ f */
        {
            acs[i] = acs[i] - 'a' + 10;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}

void mmi_em_bt_loop_back_req_hdlr(cui_event_inline_common_struct *inline_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR addrbuf[BT_ADDRESS_LEN + 1];
    WCHAR pwbuf[BT_PASSWORD_LEN + 1];
    CHAR asc_addrbuf[BT_ADDRESS_LEN + 1];
    CHAR asc_pwbuf[BT_PASSWORD_LEN + 1];
    U32 lap = 0;
    U8 uap = 0;
    U16 nap = 0;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(inline_evt->sender_id, MMI_EM_TEXT_EDIT_1,(void *)addrbuf);
    cui_inline_get_value(inline_evt->sender_id, MMI_EM_TEXT_EDIT_2,(void *)pwbuf);

    if ((!mmi_em_bt_addr_wcs2char(addrbuf, asc_addrbuf)) ||
        (addrbuf[0] == 0 && pwbuf[0] == 0) ||
        (mmi_wcslen(addrbuf) > BT_ADDRESS_LEN || mmi_wcslen(pwbuf) > BT_PASSWORD_LEN))
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, mmi_em_get_root_group(), NULL);
        cui_inline_close(inline_evt->sender_id);
        return;
    }
    
    /* transfer bt address from U8 array to low-layer format */
    /* nap : array[0]~array[3] */
    for (i = 0; i < 4; i++)
    {
        nap |= ((U16) asc_addrbuf[i] << (((3 - i) << 2)));
    }

    /* uap : array[4]~array[5] */
    for (i = 4; i < 6; i++)
    {
        uap |= ((U8) asc_addrbuf[i] << (((5 - i) << 2)));
    }

    /* lap : array[6]~array[11] */
    for (i = 6; i < 12; i++)
    {
        lap |= ((U32) asc_addrbuf[i] << (((11 - i) << 2)));
    }

    mmi_wcs_to_asc(asc_pwbuf, pwbuf);

    /* enter in progress screen */
    mmi_em_bt_in_progress_scrn();

    /* call mmi_bt function to do pcm loopback test */
    mmi_bt_sco_far_end_loopback_test(lap, uap, nap, (U8*)asc_pwbuf, (U8) strlen((const S8*)asc_pwbuf));
}

static void mmi_em_bt_in_progress_scrn(void)
{
    mmi_em_progress_cntx_struct cntx = {0};
    
    cntx.title_id = STR_ID_EM_BT_LOOKBACK;
    cntx.right_softkey = STR_GLOBAL_CANCEL;
    cntx.message = (U8*)get_string(STR_ID_EM_GLOBAL_PROCESSING);
    cntx.message_icon = IMG_GLOBAL_PROGRESS;
    cntx.rsk_func = mm_em_bt_in_progress_abort;
    cntx.esk_func = mm_em_bt_in_progress_abort;
    
    mmi_em_show_progress_scrn(&cntx);
}

/*****************************************************************************
 * FUNCTION
 *  mm_em_bt_in_progress_abort
 * DESCRIPTION
 *  BT progress abort
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mm_em_bt_in_progress_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_sco_far_end_loopback_cancel_test();

    mmi_em_popup_by_str(STR_GLOBAL_CANCEL, MMI_EVENT_FAILURE);
    mmi_frm_scrn_close(mmi_em_get_root_group(), SCR_ID_EM_CMN_SCRN);
}


void mmi_em_bt_exit_test_mode_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_test_mode_req_struct *param_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_ptr = (bt_test_mode_req_struct *)construct_local_para(
                     (kal_uint16)sizeof(bt_test_mode_req_struct), TD_CTRL);    
    param_ptr->mode = 2;
#if (MMI_MAX_SIM_NUM >= 2)
    param_ptr->dual_sim_uart_setting = PhnsetGetUARTConfig();
#endif

    mmi_frm_send_ilm((oslModuleType) MOD_BT, MSG_ID_BT_TEST_MODE_REQ, 
        (oslParaType*)param_ptr, NULL);
    mmi_em_popup_by_str(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
    kal_sleep_task(300); 
    mmi_em_shutdown();
}

/*****************************************************************************
 * FUNCTION
 *  EmBTNotifyLoopbackDoneCnf
 * DESCRIPTION
 *  Loopback test Done.
 *  This function will be called by MMI_BT
 *  after BT PCM loopback test is done.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EmBTNotifyLoopbackDoneCnf(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_display_notify_popup(result);
}

/*-----------------------------------------------------------------------------*/
/*--------------------------- BT get chip version -----------------------------*/
/*-----------------------------------------------------------------------------*/

#ifdef __MMI_EM_BT_GET_CHIP_VERION__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #ifdef __MMI_EM_BT_GET_CHIP_VERION__ */


/*-----------------------------------------------------------------------------*/
/*----------------------------- BT UPF IOT test -------------------------------*/
/*-----------------------------------------------------------------------------*/

#ifdef __MMI_EM_BT_UPF_IOT_TEST__

static const cui_inline_set_item_struct g_mmi_em_bt_upf_test_inline[] = 
{
    {MMI_EM_CAPTION_1, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_bt_bd_addr},
    {MMI_EM_TEXT_EDIT_1, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_bt_bd_addr_edit},
};

static const cui_inline_struct g_mmi_em_bt_upf_test_inline_screen = 
{
    sizeof(g_mmi_em_bt_upf_test_inline)/sizeof(cui_inline_set_item_struct),
    STR_ID_EM_BT_UPF_IOT_TEST,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_bt_upf_test_inline,
};

void mmi_em_bt_entry_upf_test_scrn(void)
{
    MMI_ID gid;
    MMI_ID inline_gid;


    gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
              GRP_ID_AUTO_GEN, 
              mmi_em_bt_entry_upf_test_scrn_proc, NULL,
              MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_gid = cui_inline_create(gid, &g_mmi_em_bt_upf_test_inline_screen);
    cui_inline_run(inline_gid);
}

MMI_RET mmi_em_bt_entry_upf_test_scrn_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
            mmi_em_bt_upf_iot_test_send_ind((cui_event_inline_common_struct*)evt);
            break;

        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*)evt;
            cui_inline_close(inline_evt->sender_id);
            break;
        }

        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct* notify_evt = (cui_event_inline_notify_struct*)evt;
            if (CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM == notify_evt->event_type &&
                MMI_EM_TEXT_EDIT_1 == notify_evt->item_id)
            mmi_imm_set_characters(MMI_TRUE, g_em_bt_upf_iot_cha);
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  em_bt_upf_iot_test_send_ind
 * DESCRIPTION
 *  send the msg to the btstack module of BT task
 *  Note. no needs to get response. success always
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_bt_upf_iot_test_send_ind(cui_event_inline_common_struct* inline_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR data_buf[EM_BT_UPF_IOT_BUFFER_SIZE + 1];
    CHAR upf_iot_buffer[EM_BT_UPF_IOT_BUFFER_SIZE + 1];
    bt_engineer_mode_device_test_req_struct *upf_iot_local_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if bt upf iot input size is equal to 12 */
    cui_inline_get_value(inline_evt->sender_id, MMI_EM_TEXT_EDIT_1, (WCHAR*)data_buf);
    
    if ((data_buf[0] == 0) || 
        (mmi_wcslen(data_buf) != EM_BT_UPF_IOT_BUFFER_SIZE) ||
        !mmi_em_bt_addr_wcs2char(data_buf, upf_iot_buffer))
    {
        mmi_em_popup_by_str(STR_GLOBAL_INVALID, MMI_EVENT_FAILURE);
        return;    
    }

    /* start to send external message to btstack module of BT Task */
    upf_iot_local_para = construct_local_para(sizeof(*upf_iot_local_para), TD_RESET);

    memcpy((void *)upf_iot_local_para->addr, (const void *)upf_iot_buffer, EM_BT_UPF_IOT_BUFFER_SIZE);

    mmi_frm_send_ilm(MOD_BT, MSG_ID_BT_ENGINEER_MODE_DEVICE_TEST_REQ, 
                        (oslParaType*)upf_iot_local_para, NULL);
    
    mmi_em_popup_by_str(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
}
#endif /* __MMI_EM_BT_UPF_IOT_TEST__ */

void mmi_em_bt_menu_entry_event_hdlr(cui_menu_event_struct *event)
{
    if (EVT_ID_CUI_MENU_LIST_ENTRY != event->evt_id)
        return;

    switch(event->parent_menu_id)
    {
    #ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
        case MENU_ID_EM_BT_AVRCP_CONNECT_TG_ACTIVELY:
        {
            mmi_menu_id menu_id = MENU_ID_EM_MISC_ON ;
            
            if (!srv_avrcp_get_actively_connect_tg_flag())
                menu_id = MENU_ID_EM_MISC_OFF;
           
            cui_menu_set_currlist_highlighted_id(event->sender_id, menu_id);
        }
        break;
    #endif /* __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__ */
        default:
            break;
    }
}

void mmi_em_bt_menu_sel_event_hdlr(cui_menu_event_struct *event)
{
    /* For ON/OFF select*/
    if ((event->highlighted_menu_id == MENU_ID_EM_MISC_ON ||
        event->highlighted_menu_id == MENU_ID_EM_MISC_OFF))
    {
        switch(event->parent_menu_id)
        {
        #ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
            case MENU_ID_EM_BT_AVRCP_CONNECT_TG_ACTIVELY:
                mmi_em_bt_toggle_avrcp_connect_ct_actively(event->highlighted_menu_id);
                break;
        #endif
            default:
                break;
        }
    }

    /* For select item handler */
    switch(event->highlighted_menu_id)
    {
    #ifdef __MMI_EM_BT_GET_CHIP_VERION__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    #ifdef __MMI_EM_BT_GENERAL_TEST__
        case MENU_ID_EM_BT_ENTRY_TEST:
            mmi_em_bt_test_mode();
            break;
		case MENU_ID_EM_BT_ENTRY_TEST_RESERVED:
			mmi_em_bt_test_mode_reserved();
    #endif /*__MMI_EM_BT_GENERAL_TEST__*/

    #ifdef __MMI_EM_BT_AUDIO_CONN__
        case MENU_ID_EM_BT_ADD_AUDIO_CONNECTION:
        case MENU_ID_EM_BT_REMOVE_AUDIO_CONNECTION:
            mmi_em_entry_bt_remove_and_add_aud_conn(event->highlighted_menu_id);
            break;
    #endif /* __MMI_EM_BT_AUDIO_CONN__ */    
    
    #ifdef __MMI_EM_BT_GENERAL_TEST__    
        case MENU_ID_EM_BT_ENTRY_LOOKBACK:
            mmi_em_bt_bd_lookback_scrn_hdlr();
            break;
    #endif /*__MMI_EM_BT_GENERAL_TEST__*/

    #ifdef __MMI_EM_BT_GENERAL_TEST__
        case MENU_ID_EM_BT_EXIT_TEST_MODE:
        mmi_em_bt_exit_test_mode_hdlr();
        break;
    #endif /*__MMI_EM_BT_GENERAL_TEST__*/
        
    #if defined(__MMI_BT_SUPPORT__) && defined(__MMI_AVRCP_DEBUG__) && defined(__MMI_AVRCP_CT_SUPPORT__)
        case MENU_ID_EM_BT_AVRCP_CMD_LIST:
            mmi_em_bt_avrcp_cmd_list_hdlr();
            break;
    #endif

    #ifdef __MMI_EM_BT_RF_TEST__
        case MENU_ID_EM_BT_RF_TEST:
            mmi_em_bt_rf_test_confirm();
            break;
    #endif /* __MMI_EM_BT_RF_TEST__ */  

    #ifdef __MMI_EM_BT_UPF_IOT_TEST__
        case MENU_ID_EM_BT_UPF_IOT_TEST:
            mmi_em_bt_entry_upf_test_scrn();
            break;
    #endif /* __MMI_EM_BT_UPF_IOT_TEST__ */ 
    #ifdef __MMI_EM_BT_BQB_HID_SUPPORT__
        case MENU_ID_EM_BT_BQB_TEST_HID:
            mmi_em_bt_hid_screen_init();
            break;
    #endif
        default:
            break;
    }
}


/**************************BT HID BQB TEST STRAT*******************************/
#ifdef __MMI_EM_BT_BQB_HID_SUPPORT__
static void mmi_em_bt_hid_screen_init()
{
    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
    {
        mmi_em_bt_hid_init();
        mmi_em_bt_hid_activate_req();
    }
    else
    {
        mmi_popup_display((WCHAR*)L"Please PowerOn BT", MMI_EVENT_WARNING, NULL);
    }
}


static void mmi_em_bt_hid_init()
{
    memset(&g_mmi_em_bt_hid_cntx, 0x00, sizeof(g_mmi_em_bt_hid_cntx));
    g_mmi_em_bt_hid_cntx.state = MMI_EM_BT_HID_STATE_IDLE;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HIDD_CONNECTION_AUTHORIZE_IND, mmi_em_bt_hid_authorize_ind_hdlr, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HIDD_ACTIVATE_CNF, mmi_em_bt_hid_activate_cnf_hdler, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HIDD_DEACTIVATE_CNF, mmi_em_bt_hid_deactivate_cnf_hdler, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HIDD_CONNECT_IND, mmi_em_bt_hid_connect_ind_hdler, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HIDD_DISCONNECT_CNF, mmi_em_bt_hid_disconnect_cnf_hdler, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HIDD_CONNECT_CNF, mmi_em_bt_hid_connect_cnf_hdler, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HIDD_DISCONNECT_IND, mmi_em_bt_hid_disconncet_ind_hdler, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HIDD_UNPLUG_IND, mmi_em_bt_hid_unplug_ind_hdlr, MMI_FALSE);
}

static void mmi_em_bt_hid_deinit()
{
    mmi_frm_clear_protocol_event_handler(MSG_ID_BT_HIDD_ACTIVATE_CNF, mmi_em_bt_hid_activate_cnf_hdler);
    mmi_frm_clear_protocol_event_handler(MSG_ID_BT_HIDD_CONNECT_IND, mmi_em_bt_hid_connect_ind_hdler);
    mmi_frm_clear_protocol_event_handler(MSG_ID_BT_HIDD_DEACTIVATE_CNF, mmi_em_bt_hid_deactivate_cnf_hdler);
    mmi_frm_clear_protocol_event_handler(MSG_ID_BT_HIDD_DISCONNECT_CNF, mmi_em_bt_hid_disconnect_cnf_hdler);
    mmi_frm_clear_protocol_event_handler(MSG_ID_BT_HIDD_CONNECT_CNF, mmi_em_bt_hid_connect_cnf_hdler);
    mmi_frm_clear_protocol_event_handler(MSG_ID_BT_HIDD_DISCONNECT_IND, mmi_em_bt_hid_disconncet_ind_hdler);
    mmi_frm_clear_protocol_event_handler(MSG_ID_BT_HIDD_CONNECTION_AUTHORIZE_IND, mmi_em_bt_hid_authorize_ind_hdlr);
    mmi_frm_clear_protocol_event_handler(MSG_ID_BT_HIDD_UNPLUG_IND, mmi_em_bt_hid_unplug_ind_hdlr);

    g_mmi_em_bt_hid_cntx.state = MMI_EM_BT_HID_STATE_IDLE;
}

static void mmi_em_bt_hid_activate_req()
{
    switch (g_mmi_em_bt_hid_cntx.state)
    {
        case MMI_EM_BT_HID_STATE_IDLE:
        {
            EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_ACTIVATING);
            mmi_em_bt_hid_send_msg(MSG_ID_BT_HIDD_ACTIVATE_REQ, NULL);
            break;
        }
        default:
            MMI_BT_ASSERT(0);
    }
}

static void mmi_em_bt_hid_deactivate_req()
{
    switch (g_mmi_em_bt_hid_cntx.state)
    {
        case MMI_EM_BT_HID_STATE_ACTIVATED:
            mmi_em_bt_hid_send_msg(MSG_ID_BT_HIDD_DEACTIVATE_REQ, NULL);
            EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_DEACTIVATING);
            mmi_frm_scrn_close(g_mmi_em_bt_hid_cntx.hid_group, SCR_ID_EM_BT_HID_TEST);
            break;
        case MMI_EM_BT_HID_STATE_ACTIVATING:
            mmi_em_bt_hid_send_msg(MSG_ID_BT_HIDD_DEACTIVATE_REQ, NULL);
            EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_DEACTIVATING);
            break;
        case MMI_EM_BT_HID_STATE_IDLE:
            break;
    }
}

static void mmi_em_bt_hid_deactivate_cnf_hdler()
{
    switch (g_mmi_em_bt_hid_cntx.state)
    {
        case MMI_EM_BT_HID_STATE_DEACTIVATING:
            EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_IDLE);
            mmi_em_bt_hid_deinit();
            break;
    }
}

static void mmi_em_bt_hid_activate_cnf_hdler(void* arg)
{
    switch (g_mmi_em_bt_hid_cntx.state)
    {
        case MMI_EM_BT_HID_STATE_ACTIVATING:
        {
            bt_hidd_activate_cnf_struct* activate_cnf = (bt_hidd_activate_cnf_struct*)arg;
            if (activate_cnf->result == hidd_result_ok)
            {
                EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_ACTIVATED);
                mmi_em_bt_hid_show_screen(SRV_EM_BT_HID_ACTIVATED_NOTIFY);
            }
            else
            {
                MMI_BT_ASSERT(0);
            }
            break;
        }
        default:
            MMI_BT_ASSERT(0);
    }
}


static void mmi_em_bt_hid_authorize_ind_hdlr(void *arg)
{
    bt_hidd_connection_authorize_ind_struct* msg_p = (bt_hidd_connection_authorize_ind_struct*)arg;
    mmi_em_bt_hid_authorize_screen_enter((srv_bt_cm_bt_addr*)&(msg_p->bt_addr));
    EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_AUTHORIZING);
}

static void mmi_em_bt_hid_authorize_screen_enter(srv_bt_cm_bt_addr* bt_addr)
{
    U8 dev_name[SRV_BT_CM_BD_NAME_UCS2_LEN] = {0};
    mmi_confirm_property_struct cnfm_arg;
    MMI_ID popup_cnfm_id = 0;
    U16 authorize_display[50];
    const srv_bt_cm_dev_struct *remote_dev = srv_bt_cm_get_dev_info(bt_addr);

    if (mmi_frm_scrn_get_active_id() != SCR_ID_EM_BT_HID_CONNECTABLE)
    {
        mmi_em_bt_hid_authorize_reject();
        return;
    }

    if (remote_dev == NULL)
    {
        memset(dev_name, 0x00, sizeof(dev_name));
    }
    else
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*)dev_name,
            sizeof(dev_name),
            (kal_uint8*)remote_dev->name);
    }

    kal_wsprintf(authorize_display, "%s HID %s %s%s",
        get_string(STR_GLOBAL_ACCEPT),
        "from",
        dev_name,
        "?");

    mmi_confirm_property_init(&cnfm_arg, CNFM_TYPE_YESNO);
    cnfm_arg.callback = mmi_em_bt_hid_authorize_rsp;
    cnfm_arg.parent_id = g_mmi_em_bt_hid_cntx.hid_group;

    popup_cnfm_id = mmi_confirm_display(
        (UI_string_type)authorize_display,
        MMI_EVENT_QUERY,
        &cnfm_arg
        );
    //StartTimerEx(BT_AUTHORIZE_SCREEN_HID_TIMER, EM_BT_HID_AUTHORIZE_TIME, mmi_em_bt_hid_authorize_timeout_rsp, (void*)popup_cnfm_id);
}

static void mmi_em_bt_hid_authorize_rsp(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*)evt;
            switch (alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    mmi_em_bt_hid_authorize_accept();
                    break;
                case MMI_ALERT_CNFM_NO:
                    mmi_em_bt_hid_authorize_reject();
                    break;
            }
            break;
        }
    }
}

static void mmi_em_bt_hid_authorize_accept()
{
    mmi_em_bt_hid_show_screen(SRV_EM_BT_HID_WAIT_NOTIFY);
    mmi_em_bt_hid_authorize_send_msg(hidd_connect_authorization_result_accepted);
    EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_WAITCONNECTING);
}

static void mmi_em_bt_hid_authorize_reject()
{
    mmi_em_bt_hid_authorize_send_msg(hidd_connect_authorization_result_rejected);
    EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_ACTIVATED);
}

static void mmi_em_bt_hid_authorize_send_msg(bt_hidd_connect_authorization_enum rst)
{
    bt_hidd_connection_authorize_rsp_struct* authorize_result =
        (bt_hidd_connection_authorize_rsp_struct*)construct_local_para(
            sizeof(bt_hidd_connection_authorize_rsp_struct), TD_UL);
    authorize_result->result = rst;

    switch (g_mmi_em_bt_hid_cntx.state)
    {
        case MMI_EM_BT_HID_STATE_AUTHORIZING:
            //StopTimer(BT_AUTHORIZE_SCREEN_HID_TIMER);
            break;
    }
    mmi_em_bt_hid_send_msg(MSG_ID_BT_HIDD_CONNECTION_AUTHORIZE_RSP, authorize_result);
}

static void mmi_em_bt_hid_authorize_timeout_rsp(void* arg)
{
    mmi_alert_dismiss((MMI_ID)arg);
    mmi_em_bt_hid_authorize_reject();
}

static void mmi_em_bt_hid_connect_ind_hdler(void* arg)
{
    switch (g_mmi_em_bt_hid_cntx.state)
    {
        case MMI_EM_BT_HID_STATE_WAITCONNECTING:
        {
            bt_hidd_connect_ind_struct* msg_p = (bt_hidd_connect_ind_struct*)arg;
            memcpy(&g_mmi_em_bt_hid_cntx.last_device, &msg_p->bt_addr, sizeof(g_mmi_em_bt_hid_cntx.last_device));
            EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_CONNECTED);
            mmi_em_bt_hid_show_screen(SRV_EM_BT_HID_CONNECTED_NOTIFY);
        }
    }
}

static void mmi_em_bt_hid_connect_cnf_hdler(void* arg)
{
    switch (g_mmi_em_bt_hid_cntx.state)
    {
        case MMI_EM_BT_HID_STATE_WAITCONNECTING:
        {
            bt_hidd_connect_cnf_struct *msg_p = (bt_hidd_connect_cnf_struct*)arg;
            if (msg_p->result == hidd_result_ok)
            {
                EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_CONNECTED);
                mmi_em_bt_hid_connected_screen_enter();
            }
            else
            {
                EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_ACTIVATED);
                mmi_frm_scrn_close_active_id();
                mmi_popup_display((WCHAR*)L"Connect Fail", MMI_EVENT_SUCCESS, NULL);
            }
            break;
        }
        default:
            MMI_ASSERT(0);
    }
}


static void mmi_em_bt_hid_trans_data()
{
    mmi_em_bt_hid_interrupt_data_req(
        EM_BT_HID_MAX_CTRL_DATA_LENGTH,
        (U8*)hid_control_data_desktop[g_mmi_em_bt_hid_cntx.trans_data_flag]);
}

static void mmi_em_bt_hid_interrupt_data_req(U8 data_len, U8* data_ptr)
{
    bt_hidd_interrupt_data_req_struct *msg_p;

    msg_p = (bt_hidd_interrupt_data_req_struct*)construct_local_para(sizeof(*msg_p), TD_CTRL);

    msg_p->bt_addr = *(bt_dm_addr_struct*)&g_mmi_em_bt_hid_cntx.last_device;
    msg_p->report_type = hidd_report_input;
    msg_p->data_len = data_len;
    msg_p->data_ptr = data_ptr;
    mmi_em_bt_hid_send_msg(MSG_ID_BT_HIDD_INTERRUPT_DATA_REQ, (void*)msg_p);
}


static void mmi_em_bt_hid_disconnect_req()
{
    mmi_frm_scrn_close(g_mmi_em_bt_hid_cntx.hid_group, SCR_ID_EM_BT_HID_CONNECTED);
    switch (g_mmi_em_bt_hid_cntx.state)
    {
        case MMI_EM_BT_HID_STATE_CONNECTED:
        {
            mmi_em_bt_hid_send_msg(MSG_ID_BT_HIDD_DISCONNECT_REQ, NULL);
            mmi_em_bt_hid_wait_screen();
            EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_DISCONNECTING);
            break;
        }
    }
}

static void mmi_em_bt_hid_disconncet_ind_hdler()
{
    switch (g_mmi_em_bt_hid_cntx.state)
    {
        case MMI_EM_BT_HID_STATE_CONNECTED:
        {
            mmi_frm_scrn_close(g_mmi_em_bt_hid_cntx.hid_group, SCR_ID_EM_BT_HID_WAIT);
            mmi_popup_display_ext(STR_GLOBAL_OK, MMI_EVENT_SUCCESS, NULL);
            EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_ACTIVATED);
            break;
        }
        case MMI_EM_BT_HID_STATE_WAITCONNECTING:
        {
            mmi_frm_scrn_close(g_mmi_em_bt_hid_cntx.hid_group, SCR_ID_EM_BT_HID_WAIT);
            mmi_popup_display_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, NULL);
            break;
        }
    }
    return;
}

static void mmi_em_bt_hid_disconnect_cnf_hdler(void* arg)
{
    bt_hidd_disconnect_cnf_struct *msg_p = (bt_hidd_disconnect_cnf_struct*)arg;
    switch (g_mmi_em_bt_hid_cntx.state)
    {
        case MMI_EM_BT_HID_STATE_DISCONNECTING:
        {
            MMI_STR_ID title_id = 0;
            if (msg_p->result == hidd_result_ok)
            {
                title_id = STR_GLOBAL_DONE;
            }
            else
            {
                title_id = STR_GLOBAL_FAILED;
            }
            mmi_popup_display_ext(title_id, MMI_EVENT_SUCCESS, NULL);
            EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_ACTIVATED);
        }
            break;

        case MMI_EM_BT_HID_STATE_DISCONNECTED:
            mmi_em_bt_hid_send_msg(MSG_ID_BT_HIDD_DEACTIVATE_REQ, NULL);
            EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_DEACTIVATING);
            break;
    }
}

static void mmi_em_bt_hid_connect_req()
{
    if (g_mmi_em_bt_hid_cntx.last_device.lap == 0 && g_mmi_em_bt_hid_cntx.last_device.nap == 0
        && g_mmi_em_bt_hid_cntx.last_device.uap == 0)
    {
        mmi_popup_display((WCHAR*)L"Host connect Device first", MMI_EVENT_WARNING, NULL);
    }
    else
    {
        switch (g_mmi_em_bt_hid_cntx.state)
        {
            case MMI_EM_BT_HID_STATE_ACTIVATED:
            {
                bt_hidd_connect_req_struct* connect_req;
                connect_req = (bt_hidd_connect_req_struct*)construct_local_para(sizeof(bt_hidd_connect_req_struct), TD_CTRL);
                connect_req->bt_addr = *(bt_dm_addr_struct*)&g_mmi_em_bt_hid_cntx.last_device;
                mmi_em_bt_hid_send_msg(MSG_ID_BT_HIDD_CONNECT_REQ, connect_req);
                mmi_em_bt_hid_wait_screen();
                EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_WAITCONNECTING);
                break;
            }
        }
    }
}

static void mmi_em_bt_hid_unplug_ind_hdlr(void* arg)
{
    bt_hidd_unplug_ind_struct *msg_p = (bt_hidd_unplug_ind_struct*)arg;

    switch (g_mmi_em_bt_hid_cntx.state)
    {
        case MMI_EM_BT_HID_STATE_CONNECTED:
            mmi_em_bt_hid_disconnect_req();
            memset(&g_mmi_em_bt_hid_cntx.last_device, 0x00, sizeof(g_mmi_em_bt_hid_cntx.last_device));
            break;
    }
}

void mmi_em_bt_hid_connectable_highlight()
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_em_bt_hid_connectable_screen_enter, KEY_EVENT_UP);
}

void mmi_em_bt_hid_connect_highlight()
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_em_bt_hid_connect_req, KEY_EVENT_UP);
}


void mmi_em_bt_hid_trans_data_highlight(U32 hiliteId)
{
    g_mmi_em_bt_hid_cntx.trans_data_flag = hiliteId;
}

void mmi_em_bt_hid_screen_highlight_hdler(U32 hiliteId)
{
    switch (hiliteId)
    {
        case 0:
        {
            mmi_em_bt_hid_connectable_highlight();
            break;
        }
        case 1:
        {
            mmi_em_bt_hid_connect_highlight();
            break;
        }
        case 2:
        {
        #ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
            mmi_em_bt_hid_Limited_vis_highlight();
        #endif
        }
    }
}

static void mmi_em_bt_hid_show_screen(srv_em_bt_hid_notify evt)
{
    switch (evt)
    {
        case SRV_EM_BT_HID_ACTIVATED_NOTIFY:
        {
            g_mmi_em_bt_hid_cntx.hid_group  = mmi_frm_group_create(mmi_em_get_root_group(), GRP_ID_AUTO_GEN, NULL, NULL);
            mmi_frm_group_enter(g_mmi_em_bt_hid_cntx.hid_group, MMI_FRM_NODE_SMART_CLOSE_FLAG);
            mmi_em_bt_hid_screen_enter();
            break;
        }
        case SRV_EM_BT_HID_CONNECTABLE_NOTIFY:
        {
            mmi_em_bt_hid_connectable_screen_enter();
            break;
        }
        case SRV_EM_BT_HID_CONNECTED_NOTIFY:
        {
            mmi_em_bt_hid_connected_screen_enter();
            break;
        }
        case SRV_EM_BT_HID_WAIT_NOTIFY:
        {
            mmi_em_bt_hid_wait_screen();
            break;
        }
        default:
            MMI_ASSERT(0);
    }
}

static void mmi_em_bt_hid_screen_enter()
{
    if (mmi_frm_scrn_enter(g_mmi_em_bt_hid_cntx.hid_group,
                            SCR_ID_EM_BT_HID_TEST,
                            NULL,
                            mmi_em_bt_hid_screen_enter,
                            MMI_FRM_FULL_SCRN))
    {
        U16 itemList[3];
        U16 nItems;
        U8* guiBuffer;

        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        nItems = GetNumOfChild(MENU_ID_EM_BT_BQB_TEST_HID_SCREEN);
        GetSequenceStringIds(MENU_ID_EM_BT_BQB_TEST_HID_SCREEN, itemList);
        SetParentHandler(MENU_ID_EM_BT_BQB_TEST_HID_SCREEN);
        RegisterHighlightHandler(mmi_em_bt_hid_screen_highlight_hdler);

        ShowCategory52Screen(
            STR_ID_EM_BT_HID_TEST_SCREEN_TITLE,
            NULL,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            itemList,
            (U16*)gIndexIconsImageList,
            NULL,
            NULL,
            NULL,
            guiBuffer
            );
        mmi_frm_scrn_set_leave_proc(g_mmi_em_bt_hid_cntx.hid_group, SCR_ID_EM_BT_HID_TEST, mmi_em_bt_hid_screen_del_cb);
        SetRightSoftkeyFunction(mmi_em_bt_hid_deactivate_req, KEY_EVENT_UP);
    }

}


static void mmi_em_bt_hid_connectable_screen_enter()
{
    if (mmi_frm_scrn_enter(g_mmi_em_bt_hid_cntx.hid_group,
                           SCR_ID_EM_BT_HID_CONNECTABLE,
                           NULL,
                           mmi_em_bt_hid_connectable_screen_enter,
                           MMI_FRM_FULL_SCRN))
    {
        ShowCategory7Screen(
            STR_ID_EM_BT_HID_CONNECTABLE_SCREEN_TITLE,
            (U16)NULL,
            (U16)NULL,
            (U16)NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8*)NULL,
            (U8*)NULL);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}


static void mmi_em_bt_hid_connected_screen_enter()
{
    if (mmi_frm_scrn_enter(g_mmi_em_bt_hid_cntx.hid_group,
                           SCR_ID_EM_BT_HID_CONNECTED,
                           NULL,
                           mmi_em_bt_hid_connected_screen_enter,
                           MMI_FRM_FULL_SCRN
                            ))
    {
        U16 itemList[4];
        U16 nItems;
        U8* guiBuffer;
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        nItems = GetNumOfChild(MENU_ID_EM_BT_HID_TRANS_DATA_SCREEN);
        GetSequenceStringIds(MENU_ID_EM_BT_HID_TRANS_DATA_SCREEN, itemList);
        SetParentHandler(MENU_ID_EM_BT_HID_TRANS_DATA_SCREEN);
        RegisterHighlightHandler(mmi_em_bt_hid_trans_data_highlight);

        ShowCategory52Screen(
            STR_ID_EM_BT_HID_CONNECT_SCREEN_TITLE,
            NULL,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            itemList,
            (U16*)gIndexIconsImageList,
            NULL,
            NULL,
            NULL,
            guiBuffer
            );
        SetLeftSoftkeyFunction(mmi_em_bt_hid_trans_data, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_em_bt_hid_disconnect_req, KEY_EVENT_UP);
    }
}


static void mmi_em_bt_hid_wait_screen()
{
    mmi_em_progress_cntx_struct cntx = {0};
    
    cntx.title_id = STR_ID_EM_BT_BQB_TEST_HID;
    cntx.message = (U8*)get_string(STR_ID_EM_GLOBAL_PROCESSING);
    cntx.group_id = g_mmi_em_bt_hid_cntx.hid_group;
    cntx.scrn_id = SCR_ID_EM_BT_HID_WAIT;
    
    mmi_em_show_progress_scrn(&cntx);
}

U8 mmi_em_bt_hid_screen_del_cb()
{
    switch (g_mmi_em_bt_hid_cntx.state)
    {
        case MMI_EM_BT_HID_STATE_ACTIVATED:
        {
            mmi_em_bt_hid_send_msg(MSG_ID_BT_HIDD_DEACTIVATE_REQ, NULL);
            EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_DEACTIVATING);
            break;
        }
        case MMI_EM_BT_HID_STATE_ACTIVATING:
        {
            EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_IDLE);
            mmi_em_bt_hid_deactivate_req();
            break;
        }
        case MMI_EM_BT_HID_STATE_WAITCONNECTING:
            break;
        case MMI_EM_BT_HID_STATE_CONNECTED:
        {
            mmi_em_bt_hid_send_msg(MSG_ID_BT_HIDD_DISCONNECT_REQ, NULL);
            EM_BT_HID_CHANGE_STATE(MMI_EM_BT_HID_STATE_CONNECTED);
            break;
        }
    }
    return MMI_RET_OK;
}

static void mmi_em_bt_hid_send_msg(U32 msg_id, void* p_local_para)
{
	srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, (msg_type)msg_id,(void*)p_local_para, NULL);
}

#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
static void mmi_em_bt_hid_entry_limit_vis(void);
static void mmi_em_bt_set_limit_vis_complete(void *para);
static void mmi_em_bt_limit_vis_event_notify_handle(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE:
            mmi_em_bt_set_limit_vis_complete(para);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_bt_hid_Limited_vis_highlight
 * DESCRIPTION
 *  This function is highlight function of BT limited discoverable mode in engineer mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_bt_hid_Limited_vis_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_limit_vis () == MMI_TRUE )
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_BACK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }

    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_em_bt_hid_entry_limit_vis, KEY_EVENT_UP);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_limit_vis
 * DESCRIPTION
 *  This function is entry function of set limited discoverable mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_bt_hid_entry_limit_vis(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL visibility;
    U32 event_mask;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_SET_LIMIT_VIS);

    event_mask = SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE;
    g_mmi_em_bt_hid_cntx.handle = srv_bt_cm_set_notify((srv_bt_cm_notifier)mmi_em_bt_limit_vis_event_notify_handle, event_mask, NULL);

    if (srv_bt_cm_is_limit_vis () == MMI_TRUE)
    {
        visibility = MMI_FALSE;
    }
    else
    {
        visibility = MMI_TRUE;
    }

    if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_set_limit_vis (visibility))
    {
        mmi_em_bt_hid_wait_screen();
    }
    else
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_temp_vis_complete
 * DESCRIPTION
 *  This function is to handle the screen when set limit visibility complete
 * PARAMETERS
 *  result    [IN]    the result of set limit discovery mode
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_bt_set_limit_vis_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_limit_discoverable_mode_struct *event = (srv_bt_cm_set_limit_discoverable_mode_struct *)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_reset_notify(g_mmi_em_bt_hid_cntx.handle);
    g_mmi_em_bt_hid_cntx.handle = 0;
    switch (event->result)
    {
        case BTBM_ADP_SUCCESS:
			mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR *)GetString(STR_GLOBAL_DONE));
			mmi_em_close_progress_scrn();
            if (srv_bt_cm_is_limit_vis () == MMI_TRUE)
            {
                mmi_em_bt_hid_limit_discover_screen_enter();
                return;
            }
            break;
        default:
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR *)L"Service is unavailable");
            break;
    }
}

static void mmi_em_bt_hid_limit_discover_screen_enter()
{
    mmi_em_progress_cntx_struct cntx = {0};
    
    cntx.title_id = STR_ID_EM_BT_BQB_TEST_HID;
    cntx.message = (U8*)L"Limit discover mode...";
    cntx.group_id = g_mmi_em_bt_hid_cntx.hid_group;
    cntx.scrn_id = SCR_ID_EM_BT_HID_WAIT;
    cntx.right_softkey = STR_GLOBAL_CANCEL;
    cntx.right_softkey_icon = IMG_GLOBAL_BACK;
    cntx.rsk_func = mmi_em_bt_hid_entry_limit_vis;
    
    mmi_em_show_progress_scrn(&cntx);
}
#endif /*__MMI_BT_LIMITED_DISCOVERY_SUPPORT__*/

#endif
#else /* __MMI_EM_BT_GENERAL_TEST__ */ // for build error.

/*****************************************************************************
 * FUNCTION
 *  EmBTNotifyLoopbackDoneCnf
 * DESCRIPTION
 *  Loopback test Done.
 *  This function will be called by MMI_BT
 *  after BT PCM loopback test is done.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EmBTNotifyLoopbackDoneCnf(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // mmi_em_display_notify_popup(result);
}

/******************************BT HID BQB Test END***************************/
#endif /* __MMI_EM_BT_GENERAL_TEST__ */
