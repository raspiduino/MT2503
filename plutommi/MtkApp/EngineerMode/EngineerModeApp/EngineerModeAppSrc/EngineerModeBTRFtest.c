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
 *  EngineerModeBTRFtest.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 * 
 *  
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EM_BT_RF_TEST__
#include "EngineerMode.h"
#include "GpioSrvGprot.h"
#include "PhoneSetupGprots.h"
#include "CommonScreens.h"

#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"

#include "EngineerModeUtil.h"
#include "EngineerModeDef.h"
#include "fseditorcuigprot.h"
#include "EngineerModeCommUI.h"

#ifdef __MMI_BT_SUPPORT__       
#include "ProfilesSrvGProt.h"
#include "BTMMIScrGprots.h"
#include "bluetooth_struct.h"
#include "BtcmSrvGprot.h"
#ifdef __BT_HFG_SUPPORT__
#include "BTMMISCOPathGprots.h"
#endif
#endif /* __MMI_BT_SUPPORT__ */

#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
#include "BTMMIAVRCPGProt.h"
#endif
#include "wgui_categories_util.h"
#include "TimerEvents.h"
#include "inlinecuigprot.h"
#include "EngineerModeBT.h"
#include "mmi_rp_app_engineermode1_def.h"

#define MMI_EM_CAPTION_1        CUI_INLINE_ITEM_ID_BASE+0
#define MMI_EM_CAPTION_2     	CUI_INLINE_ITEM_ID_BASE+1
#define MMI_EM_CAPTION_3     	CUI_INLINE_ITEM_ID_BASE+2
#define MMI_EM_CAPTION_4     	CUI_INLINE_ITEM_ID_BASE+3
#define MMI_EM_STR_SELECT_1     CUI_INLINE_ITEM_ID_BASE+4
#define MMI_EM_STR_SELECT_2     CUI_INLINE_ITEM_ID_BASE+5
#define MMI_EM_TEXT_EDIT_1   	CUI_INLINE_ITEM_ID_BASE+6
#define MMI_EM_TEXT_EDIT_2  	CUI_INLINE_ITEM_ID_BASE+7
#define MMI_EM_TEXT_EDIT_3  	CUI_INLINE_ITEM_ID_BASE+8

//add by Shuo Xie
#define MMI_EM_CAPTION_PATTERN_TYPE CUI_INLINE_ITEM_ID_BASE + 9
#define MMI_EM_SELECT_PATTERN_TYPE CUI_INLINE_ITEM_ID_BASE + 10
#define MMI_EM_CAPTION_NON_SIGNALING_RX_BT_ADDR CUI_INLINE_ITEM_ID_BASE + 11
#define MMI_EM_TEXT_EDIT_BT_ADDR CUI_INLINE_ITEM_ID_BASE + 12
extern MMI_BOOL mmi_em_bt_addr_wcs2char(WCHAR* wcs_addr, CHAR* acs);
/*-----------------------------------------------------------------------------*/
/*-------------------------------- BT RF test ---------------------------------*/
/*-----------------------------------------------------------------------------*/
typedef struct {
    U8  test_item;
    U8  currCtrlPwrLevel;
    U16 channel;
    S32 currHoping;
    U32 currPacketType;
    U32 currPatternType;
    U8  last_cmd;
    U16 data_len;
    U16 poll_period;
    U8  BdAddr[26];
	U8  btAddr[6];
	CHAR nsr_ret[200];
} em_bt_rf_test_struct;

em_bt_rf_test_struct g_bt_rf_test_cntx={0};

typedef enum
{
    EM_BT_RF_TEST_TYPE_POWER_ON = 0,
    EM_BT_RF_TEST_TYPE_TX,
    EM_BT_RF_TEST_TYPE_RX,
    EM_BT_RF_TEST_TYPE_NON_SIGNALING_RX,
    EM_BT_RF_TEST_TYPE_BD_ADDR,
    EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE,
    EM_BT_RF_TEST_TYPE_PWR_CTRL_LEVEL,
    EM_BT_RF_TEST_TYPE_MAX
} EM_BT_RF_TEST_TYPE;

typedef enum
{
    EM_BT_RF_TEST_HOPING_OFF = 0,
    EM_BT_RF_TEST_HOPING_ON
} EM_BT_RF_TEST_HOPING_TYPE;

typedef enum
{
    EM_BT_RF_TEST_PACKET_TYPE_DH1 = 0,
    EM_BT_RF_TEST_PACKET_TYPE_DH3,
    EM_BT_RF_TEST_PACKET_TYPE_DH5,
    EM_BT_RF_TEST_PACKET_TYPE_DM1,
    EM_BT_RF_TEST_PACKET_TYPE_DM3,
    EM_BT_RF_TEST_PACKET_TYPE_DM5,
    EM_BT_RF_TEST_PACKET_TYPE_2DH1,
    EM_BT_RF_TEST_PACKET_TYPE_2DH3,
    EM_BT_RF_TEST_PACKET_TYPE_2DH5,
    EM_BT_RF_TEST_PACKET_TYPE_3DH1,
    EM_BT_RF_TEST_PACKET_TYPE_3DH3,
    EM_BT_RF_TEST_PACKET_TYPE_3DH5,
    EM_BT_RF_TEST_PACKET_TYPE_NON_MOD
} EM_BT_RF_TEST_PACKET_TYPE;


static MMI_RET mmi_em_bt_rf_test_confirm_proc(mmi_event_struct *evt);
static void mmi_em_bt_rf_test_menu_list_appear(void);
static mmi_ret mmi_em_bt_rf_test_menu_list_proc(mmi_event_struct *evt);
static void mmi_em_bt_rf_test_format_level_str(WCHAR* info);
static void mmi_em_bt_rf_set_inline_value(U16 data, mmi_id inline_id, U16 item_id);
static void mmi_em_bt_rf_test_tx_rx_send_req(U8 last_cmd);
static void mmi_em_bt_rf_addr_edit_hdlr(
                MMI_BOOL is_accept, U32 output_num, 
                MMI_ID editor_gid, void* user_data);
void mmi_em_bt_non_signaling_rx_hdlr(cui_event_inline_common_struct* evt);
mmi_ret mmi_em_bt_non_signaling_rx_test_proc(mmi_event_struct* evt);
void mmi_em_bt_rf_test_non_signaling_rx_init_cntx(MMI_ID inline_id);
void mmi_em_bt_rf_packet_type_highlight_hdlr(cui_event_inline_notify_struct* notify_evt);
void mmi_em_bt_rf_test_non_signaling_rx_enter_scrn(void);
MMI_BOOL mmi_em_bt_non_signaling_get_value(cui_event_inline_common_struct* evt);
void mmi_em_bt_rf_testing_non_signaling_rx_exit(void);
void mmi_em_bt_rf_testing_non_signaling_result(void* msg);
void mmi_em_bt_non_signaling_rx_popup(WCHAR* message);

void mmi_em_bt_init_item(MMI_ID inline_gid, U16 item_id, U16 set_value)
{
    WCHAR wcs_buf[20];
    mmi_wcs_itow((S32)set_value, wcs_buf, 10);
    cui_inline_set_value(inline_gid, item_id, (void*)wcs_buf);
}

void mmi_em_bt_save_item_result(cui_event_inline_common_struct* inline_evt, U16 item_id, U16 *set_value)
{
    WCHAR buf[20];
    cui_inline_get_value(inline_evt->sender_id, item_id, (void *)buf);
    *set_value = mmi_wcs_wtoi(buf);
}

void mmi_em_bt_rf_test_confirm(void)
{
    g_bt_rf_test_cntx.test_item = EM_BT_RF_TEST_TYPE_POWER_ON;
    g_bt_rf_test_cntx.last_cmd = EM_BT_RF_TEST_TYPE_POWER_ON;

	if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
	{
		mmi_em_popup_by_str(STR_ID_EM_DEV_BT_RF_TEST_TURN_OFF_BT, MMI_EVENT_WARNING);
        return;
	}
   
    mmi_em_display_confirm(
        STR_ID_EM_RF_TEST_GSM_CONFIRM_NOTIFY_TEST,
        mmi_em_get_root_group(),
        MMI_EVENT_INFO, 
        mmi_em_bt_rf_test_confirm_proc
        );
}

static MMI_RET mmi_em_bt_rf_test_confirm_proc(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;
    
    switch (alert->result)
    {
        case MMI_ALERT_CNFM_YES:
            mmi_em_bt_rf_test_disable_sleep_mode();
            break;
    	default:
            break;
    }
    return MMI_RET_OK;
}
/**************************************************************
**    FUNCTION NAME        : mmi_em_bt_rf_test_disable_sleep_mode
**
**  PURPOSE                : BT RF Test Disable Sleep Mode
**
**    INPUT PARAMETERS    : nil
**
**    OUTPUT PARAMETERS    : void
**
**    RETURNS              : void
**
**    REMARKS            : 
**************************************************************/
void mmi_em_bt_rf_test_disable_sleep_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_progress_cntx_struct cntx = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* re-register protocol event handler of MSG_ID_MMI_EQ_SET_SLEEP_MODE_RSP */
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_SET_SLEEP_MODE_RSP, (PsIntFuncPtr)mmi_em_rf_test_sleep_mode_hdlr, MMI_FALSE);
    cntx.message = (U8*)get_string(STR_GLOBAL_PLEASE_WAIT);
    mmi_em_show_progress_scrn(&cntx);
    EngineerModeSetSleepModeReq(MMI_TRUE);     /* 1 means disable */
}


/**************************************************************
**    FUNCTION NAME        : mmi_em_rf_test_sleep_mode_hdlr
**
**  PURPOSE                : BT RF Test Sleep Mode Handler
**
**    INPUT PARAMETERS    : nil
**
**    OUTPUT PARAMETERS    : void
**
**   RETURNS            : void
**
**   EMARKS             : 
**************************************************************/
void mmi_em_rf_test_sleep_mode_hdlr(void* inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_em_get_root_group())
    {
       return;
    }
    
    /* stop MMI sleep mode */
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    mmi_em_close_progress_scrn();         
#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
    /* Enter Flight mode */
    mmi_em_rf_test_enter_flight_mode();
#else
    mmi_em_bt_rf_test_power_on_bt();
#endif /* #ifdef __FLIGHT_MODE_SUPPORT__ */
}


#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
/**************************************************************
**    FUNCTION NAME        : mmi_em_rf_test_enter_flight_mode
**
**  PURPOSE                : BT RF Test menu Enter Flight Mode
**
**    INPUT PARAMETERS    : nil
**
**    OUTPUT PARAMETERS    : void
**
**    RETURNS                : void
**
**    REMARKS            : 
**************************************************************/
void mmi_em_rf_test_enter_flight_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_em_get_root_group())
        return;

    mmi_em_dualmode_enter_flight_mode((FuncPtr)mmi_em_bt_rf_test_power_on_bt);
}
#endif /* __FLIGHT_MODE_SUPPORT__ */


/**************************************************************
**    FUNCTION NAME        : mmi_em_bt_rf_test_power_on_bt
**
**  PURPOSE                : BT RF Test Disable Sleep Mode
**
**    INPUT PARAMETERS    : nil
**
**    OUTPUT PARAMETERS    : void
**
**    RETURNS                : void
**
**    REMARKS            : 
**************************************************************/
void mmi_em_bt_rf_test_power_on_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_progress_cntx_struct cntx = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_em_get_root_group())
        return;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_ENGINEER_MODE_POWERON_CNF, (PsIntFuncPtr)mmi_em_bt_rf_test_power_on_bt_rsp_hdlr, MMI_FALSE );    
    
    cntx.message = (U8*)get_string(STR_GLOBAL_PLEASE_WAIT);
    mmi_em_show_progress_scrn(&cntx);

    EMBtRfTestSendReq();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_bt_rf_test_power_on_bt_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_bt_rf_test_power_on_bt_rsp_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_engineer_mode_poweron_cnf_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_em_get_root_group())
    {
       return;
    }

    if (rsp_p->result)
    {
        mmi_em_bt_rf_test_menu_list_appear();
    }
    else
    {
        mmi_em_fail_popup();
    }
    mmi_em_close_progress_scrn();
}


static void mmi_em_bt_rf_test_menu_list_appear(void)
{
    mmi_id list_id = 0;
    mmi_id group_id = 0;
    
    
    group_id = mmi_frm_group_create_ex(
					mmi_em_get_root_group(),
					GRP_ID_AUTO_GEN, 
					mmi_em_bt_rf_test_menu_list_proc,
					NULL,
					MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    list_id = cui_menu_create(
                  group_id,
                  CUI_MENU_SRC_TYPE_RESOURCE,
                  CUI_MENU_TYPE_FROM_RESOURCE,
                  MENU_ID_EM_BT_RF_TEST_LIST,
                  MMI_TRUE, NULL);
    cui_menu_set_currlist_flags(list_id, CUI_MENU_LIST_WITH_TEXT_NUMBERED_ITEMS);
    cui_menu_run(list_id);
}


static mmi_ret mmi_em_bt_rf_test_menu_list_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_EM_DEVICE_BT_RF_TEST_TX:
                    mmi_em_bt_rf_test_tx_rx_enter_scrn(EM_BT_RF_TEST_TYPE_TX);
                    break;

                case MENU_ID_EM_DEVICE_BT_RF_TEST_RX:
                    mmi_em_bt_rf_test_tx_rx_enter_scrn(EM_BT_RF_TEST_TYPE_RX);
                    break;
				case MENU_ID_EM_BT_RF_TEST_NON_SIGNALING_RX:
					mmi_em_bt_rf_test_non_signaling_rx_enter_scrn();
					break;
                case MENU_ID_EM_DEVICE_BT_RF_TEST_BD_ADDR:
                    mmi_em_bt_rf_enter_bd_addr_scrn();
                    break;

                case MENU_ID_EM_DEVICE_BT_RF_TEST_MODE:
                    mmi_em_bt_rf_bd_enter_test_mode();
                    break;
                    
                default:
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        case EVT_ID_GROUP_DEINIT:
            mmi_em_shutdown();
            break;
            
        default:
            break;
    }    
    return MMI_RET_OK;
}

static const U16 g_mmi_em_bt_select_hope_str[] = {
	STR_ID_EM_DEV_BT_RF_TEST_NO_HOPING, 
	STR_ID_EM_DEV_BT_RF_TEST_HOPIN
	};

static const cui_inline_item_select_struct g_mmi_em_bt_select_hope = 
{
    sizeof(g_mmi_em_bt_select_hope_str)/sizeof(U16),
    0,
    (U16*)g_mmi_em_bt_select_hope_str,
};

static const cui_inline_item_caption_struct g_mmi_em_bt_channel = 
{
    STR_ID_EM_DEV_BT_RF_TEST_CHANNEL,
};

static const cui_inline_item_text_edit_struct g_mmi_em_bt_channel_tx_edit = 
{
    0,
    0,
    10,
    IMM_INPUT_TYPE_DECIMAL_NUMERIC,
    0,
    NULL
};

static const cui_inline_item_caption_struct g_mmi_em_bt_packet_type = 
{
    STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE,
};

static const U16 g_mmi_em_bt_packet_type_select_str[] = {
					  STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_DM1,
                      STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_DH1,
                      STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_DM3,
                      STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_DH3,
                      STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_DM5,  
                      STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_DH5,                    
                      STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_2DH1,
                      STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_2DH3,
                      STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_2DH5,
                      STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_3DH1,
                      STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_3DH3,
                      STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_3DH5,
                      STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_NON_MOD
                      };

static const cui_inline_item_select_struct g_mmi_em_bt_packet_type_select = 
{
    sizeof(g_mmi_em_bt_packet_type_select_str)/sizeof(U16),
    0,
    (U16*)g_mmi_em_bt_packet_type_select_str,
};

static const cui_inline_item_select_struct g_mmi_em_bt_non_signaling_packet_type_select =
{
	sizeof(g_mmi_em_bt_packet_type_select_str)/sizeof(U16) - 1,
    0,
    (U16*)g_mmi_em_bt_packet_type_select_str,
};

//packet type mapping value
static const U8 g_mmi_bt_rf_test_cur_page_type_map[] = 
{
    0x03, 0x04,
	0x0A, 0x0B,
	0x0E, 0x0F, 	
	0x24, 0x2A, 0x2E, 
	0x28, 0x2B, 0x2F, 
	0xFF
};

static const cui_inline_item_caption_struct g_mmi_em_bt_data_len = 
{
    STR_ID_EM_DEV_BT_RF_TEST_DATA_LEN,
};

static const cui_inline_item_text_edit_struct g_mmi_em_bt_data_len_tx_edit = 
{
    0,
    0,
    10,
    IMM_INPUT_TYPE_DECIMAL_NUMERIC,
    0,
    NULL
};

static const cui_inline_item_caption_struct g_mmi_em_bt_poll_period = 
{
    STR_ID_EM_DEV_BT_RF_TEST_POLL_PERIOD,
};


static const cui_inline_item_text_edit_struct g_mmi_em_bt_poll_period_tx_edit = 
{
    0,
    0,
    10,
    IMM_INPUT_TYPE_DECIMAL_NUMERIC,
    0,
    NULL
};

//data len && period maping value
typedef struct
{
    U16 data_len;
    U16 data_period;
} mmi_em_bt_rf_packet_type_hdlr_data_struct;

static const mmi_em_bt_rf_packet_type_hdlr_data_struct g_em_bt_rf_packet_type_hdlr_data[] =
{
    {17, 0}, {27, 0}, {121, 0},
    {183, 0}, {224, 0}, {339, 0},
    {54, 0}, {367, 0}, {679, 0},
	{83, 0}, {552, 0}, {1021, 0},
    {0, 0}
};

static const cui_inline_item_caption_struct g_mmi_em_bt_pattern_type_caption_cntx =
{
	STR_ID_EM_DEV_BT_RF_TEST_PATTERN_TYPE,
};

static const U16 g_mmi_em_bt_pattern_type_select_str[] = 
{
	STR_ID_EM_DEV_BT_RF_TEST_PATTERN_TYPE_1,
	STR_ID_EM_DEV_BT_RF_TEST_PATTERN_TYPE_2,
	STR_ID_EM_DEV_BT_RF_TEST_PATTERN_TYPE_3,
	STR_ID_EM_DEV_BT_RF_TEST_PATTERN_TYPE_4,
	STR_ID_EM_DEV_BT_RF_TEST_PATTERN_TYPE_5
};

static const cui_inline_item_select_struct g_mmi_em_bt_pattern_type_select_cntx =
{
	sizeof(g_mmi_em_bt_pattern_type_select_str)/sizeof(U16),
	0,
	g_mmi_em_bt_pattern_type_select_str
};

//pattern type maping type
static const U8 g_mmi_em_bt_pattern_type_map_value[] =
{
	0x01, 0x02, 0x03, 0x04, 0x09
};

static const cui_inline_set_item_struct g_mmi_em_bt_rf_tx_inline[] = 
{
    {MMI_EM_STR_SELECT_1, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_bt_select_hope},
    {MMI_EM_CAPTION_1, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_bt_channel},
    {MMI_EM_TEXT_EDIT_1, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_bt_channel_tx_edit},
    {MMI_EM_CAPTION_2, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_bt_packet_type},
    {MMI_EM_STR_SELECT_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_bt_packet_type_select},
    {MMI_EM_CAPTION_3, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_bt_data_len},
    {MMI_EM_TEXT_EDIT_2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_bt_data_len_tx_edit},
    {MMI_EM_CAPTION_4, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_bt_poll_period},
    {MMI_EM_TEXT_EDIT_3, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_bt_poll_period_tx_edit},
	{MMI_EM_CAPTION_PATTERN_TYPE, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_bt_pattern_type_caption_cntx},
    {MMI_EM_SELECT_PATTERN_TYPE, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_bt_pattern_type_select_cntx}
};

static const cui_inline_struct g_mmi_em_bt_rf_tx_inline_screen = 
{
    sizeof(g_mmi_em_bt_rf_tx_inline)/sizeof(cui_inline_set_item_struct),
    STR_ID_EM_DEVICE_BT_RF_TEST_TX,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)g_mmi_em_bt_rf_tx_inline
};

static void mmi_em_bt_rf_test_tx_rx_init(MMI_ID inline_id)
{
    cui_inline_set_value(inline_id, MMI_EM_STR_SELECT_1, (void*)g_bt_rf_test_cntx.currHoping);
    mmi_em_bt_init_item(inline_id, MMI_EM_TEXT_EDIT_1, g_bt_rf_test_cntx.channel);
    cui_inline_set_value(inline_id, MMI_EM_STR_SELECT_2, (void*)g_bt_rf_test_cntx.currPacketType);
    mmi_em_bt_init_item(inline_id, MMI_EM_TEXT_EDIT_2, g_bt_rf_test_cntx.data_len);
    mmi_em_bt_init_item(inline_id, MMI_EM_TEXT_EDIT_3, g_bt_rf_test_cntx.poll_period);
	cui_inline_set_value(inline_id, MMI_EM_SELECT_PATTERN_TYPE, (void*)g_bt_rf_test_cntx.currPatternType);
}

void mmi_em_bt_rf_test_tx_rx_enter_scrn(U8 test_item)
{
    MMI_ID gid;
    MMI_ID inline_id;


    g_bt_rf_test_cntx.test_item = test_item;
    
    if (g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_POWER_ON &&
     	g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_TX &&
      	g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_RX &&
      	g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_NON_SIGNALING_RX
      	)
    {
        mmi_em_popup_by_str(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_ERROR);
        return;
    }
    
    gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
              GRP_ID_AUTO_GEN, 
              mmi_em_bt_tx_rx_scrn_proc, NULL,
              MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(gid, &g_mmi_em_bt_rf_tx_inline_screen);

    if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_RX)
    {
        cui_inline_set_title(inline_id, STR_ID_EM_DEVICE_BT_RF_TEST_RX, 0);
    }
    mmi_em_bt_rf_test_tx_rx_init(inline_id);    
    cui_inline_run(inline_id);
}


MMI_RET mmi_em_bt_tx_rx_scrn_proc(mmi_event_struct *evt)
{
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;
    cui_event_inline_notify_struct* notify_evt = (cui_event_inline_notify_struct*) evt;

 
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            mmi_em_bt_tx_rx_value_hdlr(inline_evt);
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(inline_evt->sender_id);
            break;

        case EVT_ID_CUI_INLINE_NOTIFY:
            if (CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED == notify_evt->event_type)
                mmi_em_bt_rf_packet_type_highlight_hdlr(notify_evt);
            break;
        default:
           break;
    }
    return MMI_RET_OK;
}


void mmi_em_bt_tx_rx_value_hdlr(cui_event_inline_common_struct* inline_evt)
{
    cui_inline_get_value(inline_evt->sender_id, MMI_EM_STR_SELECT_1, (void *)&g_bt_rf_test_cntx.currHoping);
    mmi_em_bt_save_item_result(inline_evt, MMI_EM_TEXT_EDIT_1, &g_bt_rf_test_cntx.channel);
    cui_inline_get_value(inline_evt->sender_id, MMI_EM_STR_SELECT_2, (void *)&g_bt_rf_test_cntx.currPacketType);
    mmi_em_bt_save_item_result(inline_evt, MMI_EM_TEXT_EDIT_2, &g_bt_rf_test_cntx.data_len);
    mmi_em_bt_save_item_result(inline_evt, MMI_EM_TEXT_EDIT_3, &g_bt_rf_test_cntx.poll_period);
	cui_inline_get_value(inline_evt->sender_id, MMI_EM_SELECT_PATTERN_TYPE, (void*)&g_bt_rf_test_cntx.currPatternType);
	
    EMBtRfTestTXRXSendReq();
}

static void mmi_em_bt_rf_set_inline_value(U16 data, mmi_id inline_id, U16 item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR buffer[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(buffer, "%d", data);
    cui_inline_set_value(inline_id, item_id, (void *) buffer);
}

void mmi_em_bt_rf_packet_type_highlight_hdlr(cui_event_inline_notify_struct* notify_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (notify_evt->item_id == MMI_EM_STR_SELECT_2)
	{    
		cui_inline_get_value(notify_evt->sender_id, notify_evt->item_id, (void*)&g_bt_rf_test_cntx.currPacketType);
		g_bt_rf_test_cntx.data_len = g_em_bt_rf_packet_type_hdlr_data[g_bt_rf_test_cntx.currPacketType].data_len;	    
		g_bt_rf_test_cntx.poll_period = g_em_bt_rf_packet_type_hdlr_data[g_bt_rf_test_cntx.currPacketType].data_period;

		mmi_em_bt_rf_set_inline_value(
			g_bt_rf_test_cntx.data_len, 
			notify_evt->sender_id,
			MMI_EM_TEXT_EDIT_2
		);
		mmi_em_bt_rf_set_inline_value(
			g_bt_rf_test_cntx.poll_period, 
			notify_evt->sender_id,
			MMI_EM_TEXT_EDIT_3
		);
	}
}


////////////////////////Non signaling Rx Test///////////////////////////
static const cui_inline_item_caption_struct g_mmi_em_bt_non_signaling_rx_bt_addr_caption =
{
	STR_ID_EM_DEV_BT_RF_TEST_BT_ADDR
};

static const cui_inline_item_text_edit_struct g_mmi_em_bt_non_signaling_rx_bt_addr_edit = 
{
    0,
    0,
    22,
    IMM_INPUT_TYPE_SENTENCE,
    0,
    NULL
};


static const cui_inline_set_item_struct g_mmi_em_bt_rf_non_signaling_rx[] =
{
    {MMI_EM_CAPTION_1, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_bt_channel},
    {MMI_EM_TEXT_EDIT_1, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_bt_channel_tx_edit},
    {MMI_EM_CAPTION_2, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_bt_packet_type},
    {MMI_EM_STR_SELECT_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_bt_non_signaling_packet_type_select},
	{MMI_EM_CAPTION_PATTERN_TYPE, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_bt_pattern_type_caption_cntx},
    {MMI_EM_SELECT_PATTERN_TYPE, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_bt_pattern_type_select_cntx},
	{MMI_EM_CAPTION_NON_SIGNALING_RX_BT_ADDR, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_bt_non_signaling_rx_bt_addr_caption},
	{MMI_EM_TEXT_EDIT_BT_ADDR, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_bt_non_signaling_rx_bt_addr_edit}
};

static const cui_inline_struct g_mmi_em_bt_rf_non_signaling_rx_inline_cntx = 
{
    sizeof(g_mmi_em_bt_rf_non_signaling_rx)/sizeof(cui_inline_set_item_struct),
    STR_ID_EM_BT_RF_TEST_NON_SIGNALING_RX,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_bt_rf_non_signaling_rx
};


void mmi_em_bt_rf_test_non_signaling_rx_enter_scrn(void)
{    
	MMI_ID grp_id, inline_id;

//	kal_prompt_trace(MOD_MMI, "BTRFTestLog: start %d", g_bt_rf_test_cntx.last_cmd);

    if (g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_POWER_ON &&
     	g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_TX &&
      	g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_RX &&
      	g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_NON_SIGNALING_RX
      	)
    {
        mmi_em_popup_by_str(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_ERROR);
        return;
    }
	
	g_bt_rf_test_cntx.test_item = EM_BT_RF_TEST_TYPE_NON_SIGNALING_RX;
	
	grp_id = mmi_frm_group_create_ex(
				mmi_em_get_root_group(),
              	GRP_ID_AUTO_GEN, 
              	mmi_em_bt_non_signaling_rx_test_proc,
              	NULL,
              	MMI_FRM_NODE_SMART_CLOSE_FLAG
              	);
    inline_id = cui_inline_create(grp_id, &g_mmi_em_bt_rf_non_signaling_rx_inline_cntx);
	mmi_em_bt_rf_test_non_signaling_rx_init_cntx(inline_id);
    cui_inline_run(inline_id);		
}

void mmi_em_bt_rf_test_non_signaling_rx_init_cntx(MMI_ID inline_id)
{
	WCHAR bt_addr[11] = L"0x00A5F0C3";
	g_bt_rf_test_cntx.channel = 0;

	mmi_em_bt_init_item(inline_id, MMI_EM_TEXT_EDIT_1, g_bt_rf_test_cntx.channel);
	cui_inline_set_value(inline_id, MMI_EM_STR_SELECT_2, (void*)g_bt_rf_test_cntx.currPacketType);
	cui_inline_set_value(inline_id, MMI_EM_SELECT_PATTERN_TYPE, (void*)g_bt_rf_test_cntx.currPatternType);
	cui_inline_set_value(inline_id, MMI_EM_TEXT_EDIT_BT_ADDR, bt_addr);	
}

mmi_ret mmi_em_bt_non_signaling_rx_test_proc(mmi_event_struct* evt)
{
	cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            mmi_em_bt_non_signaling_rx_hdlr(inline_evt);
            break;
        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(inline_evt->sender_id);
            break;
        default:
           	break;
    }
    return MMI_RET_OK;
}

void mmi_em_bt_non_signaling_rx_hdlr(cui_event_inline_common_struct* evt)
{
	if (mmi_em_bt_non_signaling_get_value(evt))
		mmi_em_bt_rf_test_tx_rx_send_req(EM_BT_RF_TEST_TYPE_NON_SIGNALING_RX);
	else 
		mmi_em_bt_non_signaling_rx_popup(L"BT addr error!");
}

MMI_BOOL mmi_em_bt_char_is_hexadecimal(U8 num)
{
	if (
		('0' <= num && num <= '9') ||
		('a' <= num && num <= 'f') ||
		('A' <= num && num <= 'F')
		)
		return MMI_TRUE;
	else return MMI_FALSE;
}

void mmi_em_bt_non_signaling_rx_popup(WCHAR* message)
{
	mmi_popup_display_simple(
		message,
		MMI_EVENT_FAILURE,
		mmi_em_get_root_group(),
		NULL
		);
	return;
}

U8 mmi_em_bt_char_to_int(CHAR num)
{
	U8 ret;
	if ('0' <= num && num <= '9')
		ret = num - '0';
	else if ('a' <= num && num <= 'f')
		ret = num - 'a' + 10;
	else if ('A' <= num && num <= 'F')
		ret = num - 'A' + 10;
	else
			ret = 0;
	return ret;	
}

MMI_BOOL mmi_em_bt_non_signaling_get_value(cui_event_inline_common_struct* evt)
{
	WCHAR bt_addr[11];
	U8 i, j;
    mmi_em_bt_save_item_result(evt, MMI_EM_TEXT_EDIT_1, &g_bt_rf_test_cntx.channel);
    cui_inline_get_value(evt->sender_id, MMI_EM_STR_SELECT_2, (void*)&g_bt_rf_test_cntx.currPacketType);
	cui_inline_get_value(evt->sender_id, MMI_EM_SELECT_PATTERN_TYPE, (void*)&g_bt_rf_test_cntx.currPatternType);
	cui_inline_get_value(evt->sender_id, MMI_EM_TEXT_EDIT_BT_ADDR, (void*)bt_addr);

/*
	kal_prompt_trace(
		MOD_MMI, 
		"BTRFTestLog: cui_get_value:%d,%d,%d", 
		g_bt_rf_test_cntx.channel,
		g_bt_rf_test_cntx.currPacketType,
		g_bt_rf_test_cntx.currPatternType
		);
*/

	if (!(bt_addr[0] == '0' && bt_addr[1] == 'x'))
		return MMI_FALSE;
	for (i = 2; i < 10; i++)
		if (!mmi_em_bt_char_is_hexadecimal((U8)bt_addr[i]))
			return MMI_FALSE;
	
	for (i = 9, j = 5; i >= 2; i -= 2, j--)
	{
		U8 first;
		first = mmi_em_bt_char_to_int((CHAR)bt_addr[i - 1]) << 4; 		
		g_bt_rf_test_cntx.btAddr[j] = first + mmi_em_bt_char_to_int((CHAR)bt_addr[i]);		
/*
		kal_prompt_trace(
			MOD_MMI, 
			"BTRFTestLog: cui_get_value bt addr %d", 
			g_bt_rf_test_cntx.btAddr[j]
			);
*/
	}
	return MMI_TRUE;
}

void mmi_em_bt_rf_testing_non_signaling_rx_enter(void* msg)
{
	bt_engineer_mode_txrx_test_cnf_struct* test_cnf = (bt_engineer_mode_txrx_test_cnf_struct*)msg;
	if (test_cnf->result)
	{
		mmi_em_progress_cntx_struct cntx = {0};
	    cntx.title_id = STR_ID_EM_BT_RF_TEST_NON_SIGNALING_RX;
	    cntx.right_softkey = STR_GLOBAL_EXIT;
	    cntx.message = (U8*)get_string(STR_ID_EM_GLOBAL_PROCESSING);
	    cntx.message_icon = IMG_GLOBAL_PROGRESS;
	    cntx.rsk_func = mmi_em_bt_rf_testing_non_signaling_rx_exit;
		mmi_em_show_progress_scrn(&cntx);
	}
	else
	{
		mmi_em_fail_popup();
	}
}

void mmi_em_bt_rf_testing_non_signaling_rx_exit(void)
{
	mmi_frm_set_protocol_event_handler(
		MSG_ID_BT_ENGINEER_MODE_NSR_TEST_EXIT_CNF,
		(PsIntFuncPtr)mmi_em_bt_rf_testing_non_signaling_result, 
		MMI_FALSE
		);	
	mmi_frm_send_ilm(MOD_BT, MSG_ID_BT_ENGINEER_MODE_NSR_TEST_EXIT_REQ, NULL, NULL);
	return;
}


void mmi_em_bt_rf_testing_non_signaling_result(void* msg)
{
	bt_engineer_mode_nsr_result_cnf_struct* result = (bt_engineer_mode_nsr_result_cnf_struct*)msg;
	MMI_ID grp_id;

/*
	kal_prompt_trace(MOD_MMI, "BTRFTestLog: non_signaling_result: %d, %d,%d,%d",
		result->nsr_packet_count, result->nsr_per, result->nsr_byte_count, result->nsr_ber);
*/
	mmi_em_close_progress_scrn();
	if (!result->result)
	{
		mmi_em_fail_popup();
        return;
	}
	
	grp_id = mmi_frm_group_create_ex(
			mmi_em_get_root_group(),
          	GRP_ID_AUTO_GEN, 
          	NULL,
          	NULL,
          	MMI_FRM_NODE_SMART_CLOSE_FLAG
          	);
	if (mmi_frm_scrn_enter(
		grp_id,
		SCR_ID_EM_BT_NON_SIGNALING_RX_RET_SCRN,
		NULL,
		NULL,
		MMI_FRM_UNKNOW_SCRN)
		)
	{
		kal_wsprintf(
			(WCHAR*)g_bt_rf_test_cntx.nsr_ret, 
			"%w%d \n%w%d%w%d%w \n%w%d \n%w%d%w%d%w",
			L"Package Count:",
			result->nsr_packet_count,
			L"Error rate:",
			result->nsr_per/1000,
			L".",
			result->nsr_per%1000,
			L"%",
			L"Byte Count:",
			result->nsr_byte_count,
			L"Error rate:",
			result->nsr_ber/1000,
			L".",
			result->nsr_ber%1000,
			L"%"
			);
		ShowCategory7Screen(
            STR_ID_EM_BT_RF_TEST_NON_SIGNALING_RX,
            NULL,
            0,  /* STR_GLOBAL_OPTIONS */
            0,  /* IMG_GLOBAL_OPTIONS */
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8*)g_bt_rf_test_cntx.nsr_ret,
            NULL
            );
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}		
}

/**************************************************************

    FUNCTION NAME        : EMBtRfTestTXRXSendReq

      PURPOSE                : Send BT RF Test req

    INPUT PARAMETERS    : nil

    OUTPUT PARAMETERS    : nil

    RETURNS                : void

    REMARKS                : nil

**************************************************************/
void EMBtRfTestTXRXSendReq(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Send request to RF,  now req_type = RF_TEST_GSM_RX_TEST */
    g_bt_rf_test_cntx.currCtrlPwrLevel = 7;
    EMBtRfTestSendReq();
}

static void mmi_em_bt_rf_test_tx_rx_send_req(U8 last_cmd)
{
    bt_engineer_mode_txrx_test_req_struct *msg_p;
	U16 msg_id;
	
    if (g_bt_rf_test_cntx.channel > 78)
    {
        mmi_em_fail_popup();
        return;
    }

//	kal_prompt_trace(MOD_MMI, "mmi_em_bt_rf_test_tx_rx_send_req: %d", last_cmd);

    g_bt_rf_test_cntx.last_cmd = last_cmd;

    ClearInputEventHandler(MMI_DEVICE_ALL);

    msg_p = OslConstructDataPtr(sizeof(bt_engineer_mode_txrx_test_req_struct));

	if (g_bt_rf_test_cntx.last_cmd == EM_BT_RF_TEST_TYPE_RX)	
		msg_p->pattern = 0x07;
	else
		msg_p->pattern = g_mmi_em_bt_pattern_type_map_value[g_bt_rf_test_cntx.currPatternType]; 
    msg_p->channel_hopping = 1;
    msg_p->tx_freq= 0; 
    msg_p->rx_freq= 0;
    
    if (g_bt_rf_test_cntx.currHoping != EM_BT_RF_TEST_HOPING_ON)
    {
        msg_p->channel_hopping = 0;        
        if (last_cmd == EM_BT_RF_TEST_TYPE_RX || last_cmd == EM_BT_RF_TEST_TYPE_NON_SIGNALING_RX)
        {
           msg_p->rx_freq = msg_p->tx_freq = g_bt_rf_test_cntx.channel;
        } 
        else if (last_cmd == EM_BT_RF_TEST_TYPE_TX)
        {
           msg_p->tx_freq= g_bt_rf_test_cntx.channel; 
        }
    }

    msg_p->packet_type   = g_mmi_bt_rf_test_cur_page_type_map[g_bt_rf_test_cntx.currPacketType];
    msg_p->packet_length = g_bt_rf_test_cntx.data_len;
    msg_p->poll_period   = g_bt_rf_test_cntx.poll_period; 

	if (last_cmd == EM_BT_RF_TEST_TYPE_NON_SIGNALING_RX)
	{
		msg_id = MSG_ID_BT_ENGINEER_MODE_NSR_TEST_ENTER_REQ;
		memcpy(msg_p->bt_addr, g_bt_rf_test_cntx.btAddr, 6);
		mmi_frm_set_protocol_event_handler(
			MSG_ID_BT_ENGINEER_MODE_NSR_TEST_ENTER_CNF, 
			(PsIntFuncPtr)mmi_em_bt_rf_testing_non_signaling_rx_enter, 
			MMI_FALSE
			);
	}
	else
	{
		msg_id = MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_REQ;
		mmi_frm_set_protocol_event_handler(
			MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_CNF, 
			(PsIntFuncPtr)EmBtRfTestTXRXRspHdlr, 
			MMI_FALSE
			);	
	}
    EngineerModeSendMsg_Ext(msg_id, MOD_BT, (void*)msg_p, NULL);
}

/**************************************************************
**    FUNCTION NAME        : EMBtRfTestSendReq
**
**     PURPOSE                : BT RF Test send request function. 
**
**    INPUT PARAMETERS    : nil
**
**    OUTPUT PARAMETERS    : void
**
**    RETURNS                : void
**
**    REMARKS            : 
**************************************************************/
void EMBtRfTestSendReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_bt_rf_test_cntx.test_item)
    {
        case EM_BT_RF_TEST_TYPE_POWER_ON:
        {
        #if (MMI_MAX_SIM_NUM >= 2)
            bt_engineer_mode_poweron_req_struct* msg_p;
            msg_p = OslConstructDataPtr(sizeof(bt_engineer_mode_poweron_req_struct));
            msg_p->dual_sim_uart_setting = PhnsetGetUARTConfig();
            EngineerModeSendMsg_Ext(MSG_ID_BT_ENGINEER_MODE_POWERON_REQ, MOD_BT, (local_para_struct*)msg_p, NULL);
        #else            
            EngineerModeSendMsg_Ext(MSG_ID_BT_ENGINEER_MODE_POWERON_REQ, MOD_BT, NULL, NULL);
        #endif
            break;
        }
        case EM_BT_RF_TEST_TYPE_TX:
        {
            mmi_em_bt_rf_test_tx_rx_send_req(EM_BT_RF_TEST_TYPE_TX);
            break;
        }
        case EM_BT_RF_TEST_TYPE_RX:
        {
            mmi_em_bt_rf_test_tx_rx_send_req(EM_BT_RF_TEST_TYPE_RX);
            break;
        }
        case EM_BT_RF_TEST_TYPE_BD_ADDR:
        {
            U32 i = 0;
            U8 addrbuf[13];
            bt_set_bd_param_req_struct *msg_p;

            g_bt_rf_test_cntx.last_cmd = EM_BT_RF_TEST_TYPE_BD_ADDR;
            
            msg_p = OslConstructDataPtr(sizeof(bt_set_bd_param_req_struct));
            
            if (!mmi_em_bt_addr_wcs2char((WCHAR*)g_bt_rf_test_cntx.BdAddr, (CHAR*)addrbuf))
            {
                 mmi_em_fail_popup();
                 return;
            }

            for (i= 0;i < 12;i += 2)
            {
                msg_p->bd_addr[i/2] = addrbuf[i]+addrbuf[i+1]*16;
            }

            EngineerModeSendMsg_Ext(MSG_ID_BT_SET_BD_ADDR_REQ, MOD_BT, msg_p, NULL);
            break;
        }
        case EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE:
        {
            bt_test_mode_req_struct *msg_p;

            if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE)
            {
                if ((g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_POWER_ON) &&
                    (g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE))
                {
                    mmi_em_popup_by_str(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
                    return;
                }
            }

            g_bt_rf_test_cntx.last_cmd = EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE;
            
            msg_p = OslConstructDataPtr(sizeof(bt_test_mode_req_struct));
            msg_p->mode = MMI_TRUE;
       #if (MMI_MAX_SIM_NUM >= 2)
            msg_p->dual_sim_uart_setting = PhnsetGetUARTConfig();
       #endif
            EngineerModeSendMsg_Ext(MSG_ID_BT_TEST_MODE_REQ, MOD_BT, msg_p, NULL);

            /* no response, display sucess directly */
            mmi_em_bt_rf_testing_enter_text_show_scrn();
            break;
        }
        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  EmBtRfTestTXRXRspHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmBtRfTestTXRXRspHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_engineer_mode_txrx_test_cnf_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_em_get_root_group())
        return;

    if (rsp_p->result)
    {
        mmi_em_bt_rf_testing_enter_text_show_scrn();
    }
    else
    {
        mmi_em_fail_popup();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EmBtRfTestPwrCtrlLevelRspHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmBtRfTestPwrCtrlLevelRspHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_engineer_mode_txrx_power_cnf_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_display_notify_popup(rsp_p->result);
}

static mmi_ret mmi_em_bt_rf_testing_text_scrn_key_hdlr(U8 key_orig, U8 up_key, U8 down_key)
{
    if (key_orig == up_key)
    {
        EmBtRfTestPwrLevelUp();
        return MMI_RET_KEY_HANDLED;
    }
    if (key_orig == down_key)
    {
        EmBtRfTestPwrLevelDown();
        return MMI_RET_KEY_HANDLED;
    }
    return 0;
}

void mmi_em_bt_rf_test_tx_rx_exit_hdler()
{
	mmi_em_close_progress_scrn();
}

static mmi_ret mmi_em_bt_rf_testing_text_scrn_proc(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            U8 *info;
            U16 title=0, image=0;
            



            info = (PU8) subMenuData;

            if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_TX)
            {
                title = STR_ID_EM_DEVICE_BT_RF_TEST_TX;
            }
            else if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_RX)
            {
                title = STR_ID_EM_DEVICE_BT_RF_TEST_RX;
            }
			else if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_NON_SIGNALING_RX)
			{
				title = STR_ID_EM_BT_RF_TEST_NON_SIGNALING_RX;
			}

            if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_TX ||
                g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_RX)
            {
                mmi_em_bt_rf_test_format_level_str((WCHAR*)info);
            }

            if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_BD_ADDR)
            {
                mmi_ucs2cpy((PS8) info, (PS8) get_string(STR_ID_EM_GLOBAL_PROCESSING));
                title = STR_ID_EM_BT_BD_ADDR;
                image = IMG_GLOBAL_PROGRESS;
            }
            else if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE)
            {
                mmi_ucs2cpy((PS8) info, (PS8) get_string(STR_GLOBAL_ACTIVATED));
                title = STR_ID_EM_DEVICE_BT_RF_TEST_MODE;
                image = IMG_GLOBAL_PROGRESS;
            }

            /* Show progress screen */
            ShowCategory66Screen(
                title, 0,
                0, 0,
                STR_GLOBAL_CANCEL, 0,
                (PU8) subMenuData, image,
                NULL);
           break;
        }
        
        case EVT_ID_WGUI_RSK_CLICK:
        {
            if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE)
            {
                mmi_em_shutdown();
                return MMI_RET_KEY_HANDLED;
            }
			else if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_TX ||
				g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_RX)
			{
				mmi_em_progress_cntx_struct cntx = {0};
				mmi_frm_send_ilm(MOD_BT, MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_EXIT_REQ, NULL, NULL);			
    			mmi_frm_set_protocol_event_handler(MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_EXIT_CNF, (PsIntFuncPtr)mmi_em_bt_rf_test_tx_rx_exit_hdler, MMI_FALSE); 
				mmi_frm_scrn_close_active_id();
    
    			cntx.message = (U8*)get_string(STR_GLOBAL_PLEASE_WAIT);
    			mmi_em_show_progress_scrn(&cntx);
				return MMI_RET_KEY_HANDLED;
			}
            break;
        }
        
        case EVT_ID_ON_KEY:
        {
            mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
            
            if (key_evt->key_type == KEY_EVENT_UP)
            {
            #ifdef __COSMOS_MMI__
                 if (MMI_RET_KEY_HANDLED == mmi_em_bt_rf_testing_text_scrn_key_hdlr(key_evt->key_code, KEY_SEND, KEY_BACK)
                     || MMI_RET_KEY_HANDLED == mmi_em_bt_rf_testing_text_scrn_key_hdlr(key_evt->key_code, KEY_UP_ARROW, KEY_DOWN_ARROW))
            #else
                 if (MMI_RET_KEY_HANDLED == mmi_em_bt_rf_testing_text_scrn_key_hdlr(key_evt->key_code, KEY_UP_ARROW, KEY_DOWN_ARROW)
                     || MMI_RET_KEY_HANDLED == mmi_em_bt_rf_testing_text_scrn_key_hdlr(key_evt->key_code, KEY_UP_ARROW, KEY_DOWN_ARROW))
            #endif
                 { 
                     return MMI_RET_KEY_HANDLED;
                 }
                 
                 if (key_evt->key_code == KEY_END)
                 {
                     if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE)
                     {
                         mmi_em_shutdown();
                         return MMI_RET_KEY_HANDLED;
                     }
                 }
            }
            break;
        }
        
        
        default:
            break;
    }
    
    return MMI_RET_OK;

}

void mmi_em_bt_rf_testing_enter_text_show_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     mmi_frm_scrn_create(mmi_em_get_root_group(),
         SCR_ID_EM_BT_RF_TEST_RESLUT_SCRN,
         mmi_em_bt_rf_testing_text_scrn_proc,
         NULL);
}

static void mmi_em_bt_rf_test_format_level_str(WCHAR* info)
{
    kal_wsprintf((WCHAR*)info, 
        "%w:\n\n\n%d\n", 
        get_string(STR_ID_EM_DEV_BT_RF_TEST_CTRL_PWR_LEVEL),
        g_bt_rf_test_cntx.currCtrlPwrLevel);
}

static void mmi_em_bt_rf_test_show_level_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_engineer_mode_power_test_req_struct *msg_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_ENGINEER_MODE_POWER_TEST_CNF, (PsIntFuncPtr)EmBtRfTestPwrCtrlLevelRspHdlr, MMI_FALSE );    
    msg_p = OslConstructDataPtr(sizeof(bt_engineer_mode_power_test_req_struct));
    msg_p->level = g_bt_rf_test_cntx.currCtrlPwrLevel;
    EngineerModeSendMsg_Ext(MSG_ID_BT_ENGINEER_MODE_POWER_TEST_REQ, MOD_BT, msg_p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  EmBtRfTestPwrLevelUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmBtRfTestPwrLevelUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_rf_test_cntx.currCtrlPwrLevel < 7)
    {
        g_bt_rf_test_cntx.currCtrlPwrLevel++;
		mmi_em_bt_rf_test_show_level_scrn();
    }
}



/*****************************************************************************
 * FUNCTION
 *  EmBtRfTestPwrLevelDown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmBtRfTestPwrLevelDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_rf_test_cntx.currCtrlPwrLevel > 0)
    {
        g_bt_rf_test_cntx.currCtrlPwrLevel--;
		mmi_em_bt_rf_test_show_level_scrn();
    }    
}

void mmi_em_bt_rf_enter_bd_addr_scrn(void)
{
    mmi_em_num_editor_struct data = {0};
   
    
    g_bt_rf_test_cntx.test_item = EM_BT_RF_TEST_TYPE_BD_ADDR;
    
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_ENGINEER_MODE_CNF, (PsIntFuncPtr)EmBtRfTestSetBdAddrRspHdlr, MMI_FALSE);     

    if ((g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_POWER_ON) &&
        (g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_BD_ADDR))
    {
        mmi_em_popup_by_str(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        return;
    }
    
    data.title_id = STR_ID_EM_BT_BD_ADDR;
    data.notify = mmi_em_bt_rf_addr_edit_hdlr;
    data.input_type = IMM_INPUT_TYPE_ENGLISH_SENTENCE;
    mmi_em_show_num_editor(&data);
}

static void mmi_em_bt_rf_addr_edit_hdlr(MMI_BOOL is_accept, U32 output_num, MMI_ID editor_gid, void* user_data)
{
     memcpy((void *)g_bt_rf_test_cntx.BdAddr, (const void *)user_data, sizeof(g_bt_rf_test_cntx.BdAddr));
     EMBtRfTestSendReq();
}

static void mmi_em_bt_rf_test_set_bd_addr_rsp_hdlr(void)
{
    StartTimer(EM_NOTIFYDURATION_TIMER, 3000, mmi_em_shutdown);
}

/*****************************************************************************
 * FUNCTION
 *  EmBtRfTestSetBdAddrRspHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmBtRfTestSetBdAddrRspHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_engineer_mode_cnf_struct *rsp_p = (bt_engineer_mode_cnf_struct *)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (rsp_p->result)
    {
        mmi_em_progress_cntx_struct cntx = {0};
		
        cntx.esk_func = mmi_em_progress_sftkey_null_hdlr;
        cntx.rsk_func = mmi_em_progress_sftkey_null_hdlr;
        cntx.enter_func = mmi_em_bt_rf_test_set_bd_addr_rsp_hdlr;
        cntx.message = (U8*)get_string(STR_ID_EM_GLOBAL_PROCESSING);
        
        mmi_em_show_progress_scrn(&cntx);
    }
    else
    {
        mmi_em_fail_popup();
    }
}

void mmi_em_bt_rf_bd_enter_test_mode(void)
{
    g_bt_rf_test_cntx.test_item = EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE;
    EMBtRfTestSendReq();
}
#endif /* __MMI_EM_BT_RF_TEST__*/
