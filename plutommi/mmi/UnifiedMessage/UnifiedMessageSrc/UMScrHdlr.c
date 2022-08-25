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
 * UMScrHdlr.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __UM_SUPPORT__
#include "UMGProt.h"
#include "UMDefs.h"
#include "UMProt.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "UmSrvGprot.h"

#include "MessagesMiscell.h"
#include "Mms_api.h"
#include "UcAppGprot.h"
#include "SMSAppGprot.h"

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif /* __MMI_EMAIL__ */

#ifdef __MMI_IMPS__
/* under construction !*/
#endif /* __MMI_IMPS__ */

#ifdef __QQIM_SUPPORT__
#include "TencentQQ_vm.h"
#endif /* __QQIM_SUPPORT__ */

#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__)
#include "ProvBoxAPPGProt.h"
#endif /* defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__) */

#include "UCMGProt.h"

#include "custom_phb_config.h" /* for MMI_PHB_NAME_LENGTH */
#include "PhbSrvGprot.h"

#include "GpioSrvGprot.h" /* for srv_backlight_turn_on */


#include "Menucuigprot.h" /* for menu cui */
#include "PhbCuiGprot.h" /* for phb cui */
#ifdef __DM_MO_SUPPORT__
#include "Dmuigprot.h" /* mmi_dmui_get_status */
#include "mmiapi_dm_struct.h"
#endif /* __DM_MO_SUPPORT__ */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "string.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalConstants.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "CustMenuRes.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "Unicodexdcl.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "UmSrvGprot.h"
#include "stdio.h"
#include "UmSrvDefs.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "gui_typedef.h"
#include "wgui_categories_list.h"
#include "AlertScreen.h"
#include "gui_effect_oem.h"
#include "wgui_fixed_menus.h"
#include "gui_fixed_menus.h"
#include "customer_email_num.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "wgui_categories_email.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "wgui_touch_screen.h"
#include "custom_events_notify.h"
#include "UcSrvGprot.h"
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "Custom_ProvBox.h"
#include "custom_wap_config.h"
#include "mmi_rp_app_uiframework_def.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "mmi_rp_app_sms_def.h"
#include "CommonScreensResDef.h"
#include "gui_inputs.h"
#ifdef __MMI_MMS_IN_UM__
#include "mmi_rp_app_umms_mms_def.h"
#endif
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif /* __USB_IN_NORMAL_MODE__ */
#include "NwUsabSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "umsrvgprot.h"
#ifdef __MMI_BT_MAP_CLIENT__
#include "SmsBtmapcSrvGprot.h"
#include "Mmi_frm_scenario_gprot.h"
#endif

#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __MMI_SMS_SLIM__
#include "MmsSrvGprot.h"
#endif
#endif

#ifdef __MMI_BT_MAP_CLIENT__
#include "SmsUmBtMapGProt.h"
#endif /*__MMI_BT_MAP_CLIENT__*/

typedef void (*mmi_um_ui_sh_entry_func_ext)(void);

static S32 mmi_um_ui_mainmenu_req_msg_num_cb(S32 pid, srv_um_get_msg_num_result *rsp, S32 para);
static MMI_BOOL mmi_um_ui_sh_main_msg_get_num(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx);
#ifndef __MMI_UM_OP_FSM_SUPPORT__
static S32 mmi_um_ui_delete_folder_req_cb(S32 pid, srv_um_delete_folder_result *rsp, S32 para);
#endif

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
static void mmi_um_ui_sh_general_folder_ms_item_select_common_hanlder(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, srv_um_mark_several_op_action_enum ms_action);
#endif
typedef enum
{
    MMI_UM_UI_ENTRY_MAIN_MENU
#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
    ,MMI_UM_UI_ENTRY_DELETE_FOLDER
#endif
} mmi_um_ui_main_menu_delete_folder_enum;

#ifdef  __GENERAL_TTS__
#include "TTSSettingGprot.h"
#endif
#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
static void mmi_um_ui_sh_setting_entry_prefer_sim_setting(void);
static U16 mmi_um_ui_if_entry_setting_prefer_sim(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp);
static MMI_BOOL mmi_um_ui_sh_setting_prefer_sim_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting);
static MMI_BOOL mmi_um_ui_sh_setting_prefer_sim_evt_hdlr(U16 scrn_id, U16 event, void *arg);
static void mmi_um_ui_sh_setting_prefer_sim_entry(mmi_scrn_essential_struct *arg);
static void mmi_um_ui_sh_setting_prefer_sim_hilite_hdlr(S32 index);
static void mmi_um_ui_sh_setting_prefer_sim_lsk_hdlr(void);
#endif
#define MMI_UM_UI_SCRN_INVALID_MSG_NUMBER -1
#define MMI_UM_UI_SCRN_TTS_TIMER_COUNT_DOWN_INTERVAL 500 

#ifdef __MMI_BT_MAP_CLIENT__
extern mmi_sms_bt_cntx_struct *g_sms_bt_ui_p;
#endif /* __MMI_BT_MAP_CLIENT__ */ 


#ifdef  __GENERAL_TTS__
static void mmi_um_ui_tts_stop();
static U16 msg_to_tts = SRV_SMS_INVALID_MSG_ID;
static void mmi_um_ui_sh_tts_time_out_callback(void)
{
    StopTimer(MESSAGES_TTS_COUNT_DOWN_TIMER_ID);
    mmi_sms_tts_play_msg_by_id(msg_to_tts);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_tts_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
static void mmi_um_ui_tts_stop()
{
    mmi_sms_tts_stop_play();
    msg_to_tts = SRV_SMS_INVALID_MSG_ID;
}
#endif

#ifdef __MMI_BT_MAP_CLIENT__
mmi_um_ui_cc_scrn_cntx_struct * g_sh_get_item_scrn_cntx = NULL;
mmi_um_ui_aprc_263_struct g_aprc_int_cntx = {0};
MMI_BOOL g_aprc_enter_tab = MMI_FALSE;
srv_um_box_identity_struct g_um_box_struct = {0};
extern MMI_BOOL g_is_first_enter_tab;
mmi_um_tab_page g_tab_last_enter = 0;
mmi_um_tab_page g_tab_curr_first_enter = 0;
MMI_BOOL g_enter_from_bt;
MMI_BOOL g_exit_folder = MMI_FALSE;
#endif /* __MMI_BT_MAP_CLIENT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_inbox
 * DESCRIPTION
 *  Funtion is called when inbox menu item selected
 * NA
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_main_menu_general_highlight(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(f, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(f, KEY_EVENT_UP);
}


MMI_BOOL mmi_um_ui_sh_tsfr_fsm_event(U16 sh_evt, mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, void *arg)
{
    U16 fsm_event;

    fsm_event = mmi_um_ui_ut_get_fsm_event_by_ui_event(sh_evt);
    return scrn_cntx->fsm.event_hdlr(scrn_cntx->scrn_id, fsm_event, arg);
}

MMI_BOOL mmi_um_ui_sh_setting_template_event_hdlr(U16 scrn_id, U16 event, void *arg, mmi_um_entry_func_ptr entry_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        {
            /* Check if UM is ready */
            if (srv_um_check_ready_type(scrn_cntx->screen_hdlr.folder_type.msg_type))
            {
                /* UM is ready */
                mmi_um_ui_sh_create(entry_func, scrn_cntx);
            }
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}

typedef void (*mmi_um_ui_sh_hilite_hdlr)(S32 index);
typedef void (*mmi_um_ui_sh_key_hdlr)(void);
void mmi_um_ui_sh_set_general_cntx(
        mmi_um_ui_aprc_general_cntx_struct *general_aprc_cntx, 
        U16 group_id, 
        U16 disp_scrn_id, 
        U16 menu_item_id, 
        U16 title_str_id, 
        U16 title_icon_id, 
        U16 lsk_str_id, 
        U16 lsk_icon_id, 
        U16 rsk_str_id, 
        U16 rsk_icon_id, 
        U16 csk_icon_id, 
        mmi_um_ui_sh_hilite_hdlr hilite_hdlr, 
        U16 hilite_idx, 
        U16 num_of_item, 
        mmi_um_entry_func_ptr entry_func, 
        mmi_um_entry_func_ptr exit_func, 
        U8 *gui_buffer, 
        mmi_um_ui_sh_key_hdlr lsk, 
        mmi_um_ui_sh_key_hdlr rsk, 
        mmi_um_ui_sh_key_hdlr csk, 
        mmi_proc_func leave_proc)
{
    /* General context */
    general_aprc_cntx->grp_id = group_id;
    general_aprc_cntx->scrn_id = disp_scrn_id;
    general_aprc_cntx->menu_item_id = menu_item_id;
    general_aprc_cntx->title_str_id = title_str_id;
    general_aprc_cntx->title_icon_id = title_icon_id;
    general_aprc_cntx->lsk_str_id = lsk_str_id;
    general_aprc_cntx->lsk_icon_id = lsk_icon_id;
    general_aprc_cntx->rsk_str_id = rsk_str_id;
    general_aprc_cntx->rsk_icon_id = rsk_icon_id;
    general_aprc_cntx->csk_icon_id = csk_icon_id;
    general_aprc_cntx->hilite_hdlr = hilite_hdlr;
    general_aprc_cntx->hilite_idx = hilite_idx;
    general_aprc_cntx->num_of_item = num_of_item;
    general_aprc_cntx->entry_func = entry_func;
    general_aprc_cntx->exit_func = exit_func;
    general_aprc_cntx->gui_buffer = gui_buffer;
    general_aprc_cntx->key_hdlr.lsk_hdlr = lsk;
    general_aprc_cntx->key_hdlr.rsk_hdlr = rsk;
    general_aprc_cntx->key_hdlr.csk_hdlr = csk;
    general_aprc_cntx->leave_proc = leave_proc;
}


void mmi_um_ui_sh_setting_write_msg_entry(mmi_scrn_essential_struct *arg, U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_list_struct *aprc;
    U16 str_item_list[MAX_SUB_MENUS];
    U16 item_icons[MAX_SUB_MENUS];
    U8 *popup_list[MAX_SUB_MENUS];
    U16 menu_id = MENU_ID_UM_WRITE_MSG; /* default for write message */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.list);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    {
        /* default for write message */
        MMI_ID string_id = STR_UM_WRITE_MSG_ID;
        void (* hilight_handler)(S32) = mmi_um_ui_sh_write_msg_hilite_hdlr;
        void (* entry_func)(mmi_scrn_essential_struct *arg) = mmi_um_ui_sh_write_msg_entry;
        void (*lsk_hdlr)(void) = mmi_um_ui_sh_write_msg_lsk_hdlr;

        /* if it is for setting, change to other parameters */
        if (type == 1)
        {
            menu_id = MENU_ID_UM_SETTING;
            string_id = STR_UM_SETTING_ID;
            hilight_handler = mmi_um_ui_sh_setting_hilite_hdlr;
            entry_func = mmi_um_ui_sh_setting_entry;
            lsk_hdlr = NULL;
            #if (defined(__OP01__) && (MMI_MAX_SIM_NUM >=2))
            {
                S32 usable_sim_amount = 0;
                S32 i = 0;
                for (; i < MMI_SIM_TOTAL; ++i)
                {
                    mmi_sim_enum current_sim = mmi_frm_index_to_sim(i);
                    /* detect how many sim is avaiable */
                    if (srv_nw_usab_is_usable(current_sim))
                    {   
                        ++usable_sim_amount;
                    }
                }
                if(usable_sim_amount <= 1)
                {
                    mmi_frm_hide_menu_item(MENU_ID_UM_SETTING_PREFER_SIM);
                }
                else
                {
                    mmi_frm_unhide_menu_item(MENU_ID_UM_SETTING_PREFER_SIM);
                }
            }
            #endif 
        }

        mmi_um_ui_sh_set_general_cntx(
                &aprc->general_aprc_cntx, 
                scrn_cntx->group_id, 
                scrn_cntx->screen_hdlr.disp_scrn_id, 
                menu_id, 
                string_id, 
                IMG_UM_ENTRY_SCRN_CAPTION, 
                STR_GLOBAL_OK, 
                IMG_GLOBAL_OK, 
                STR_GLOBAL_BACK, 
                IMG_GLOBAL_BACK, 
                IMG_GLOBAL_COMMON_CSK, 
                hilight_handler, 
                0, 
                GetNumOfChild_Ext(menu_id), 
                entry_func, 
                NULL, 
                NULL, 
                lsk_hdlr, 
                mmi_um_ui_sh_rsk_hdlr, 
                lsk_hdlr, 
                mmi_um_ui_sh_leave_proc);
    }

    /* Specified context */
    /* Construct the menu item strings */
    GetSequenceStringIds_Ext(menu_id, str_item_list);
    GetSequenceImageIds_Ext(menu_id, item_icons);
    ConstructHintsList(menu_id, popup_list);

    {
        S32 i;
        /* Copy to global buffer and use the global buffer pointer */
        for (i = 0; i < aprc->general_aprc_cntx.num_of_item; i++)
        {
            mmi_ucs2cpy((CHAR*)subMenuData[i], (CHAR*)get_string((MMI_ID_TYPE)str_item_list[i]));
        }
    }

    aprc->list_of_items = (U16 *)subMenuDataPtrs;
    aprc->list_of_item_hints = (U8 **)popup_list;
    aprc->list_of_item_icons = (U16 *)item_icons;
    scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);
}


void mmi_um_ui_sh_main_msg_delete_folder_entry(mmi_scrn_essential_struct *arg, U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 str_id_item_list[MAX_SUB_MENUS];
    U16 item_icons[MAX_SUB_MENUS];
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_main_menu_struct *aprc;
    mmi_um_entry_main_msg_evt_struct entry_main_msg_evt;
    U16 menu_id;
    mmi_um_entry_func_ptr entry_func = mmi_um_ui_sh_main_msg_entry; 
    mmi_um_entry_func_ptr exit_func = mmi_um_ui_sh_main_msg_exit; 
    
    mmi_um_ui_sh_hilite_hdlr hilite_hdlr =  mmi_um_ui_sh_main_msg_hilite_hdlr;
    
    mmi_um_ui_sh_key_hdlr lsk = NULL; 
    mmi_um_ui_sh_key_hdlr csk = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.main_menu);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
    if (type == MMI_UM_UI_ENTRY_MAIN_MENU)
#endif /* __MMI_UM_DELETE_FOLDER_SUPPORT__ */
    {
        /* Arrange the menu items */
        mmi_um_ui_sh_main_msg_arrange_menu_item(scrn_cntx);
        menu_id = MAIN_MENU_MESSAGES_MENUID;
    }
#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
    else
    {
        menu_id = MENU_ID_UM_DELETE_FOLDER;
        entry_func = mmi_um_ui_sh_delete_folder_entry;
        exit_func = NULL;
        hilite_hdlr = mmi_um_ui_sh_delete_folder_hilite_hdlr;
        lsk = csk = mmi_um_ui_sh_delete_folder_lsk_hdlr;
    }
#endif /* __MMI_UM_DELETE_FOLDER_SUPPORT__ */
    mmi_um_ui_sh_set_general_cntx(
            &aprc->general_aprc_cntx, 
            scrn_cntx->group_id, 
            scrn_cntx->screen_hdlr.disp_scrn_id, 
            menu_id, 
            MAIN_MENU_MESSAGES_TEXT, 
            IMG_UM_ENTRY_SCRN_CAPTION, 
            STR_GLOBAL_OK, 
            IMG_GLOBAL_OK, 
            STR_GLOBAL_BACK, 
            IMG_GLOBAL_BACK, 
            IMG_GLOBAL_COMMON_CSK, 
            hilite_hdlr, 
            0, 
            GetNumOfChild_Ext(menu_id), 
            entry_func, 
            exit_func, 
            NULL, 
            lsk, 
            mmi_um_ui_sh_general_folder_rsk_hdlr, 
            csk, 
            mmi_um_ui_sh_general_folder_leave_proc);

    /* Specified context */
    /* Construct the menu item strings */
    GetSequenceStringIds_Ext(menu_id, str_id_item_list);
    MMI_ASSERT(MAX_SUB_MENUS >= aprc->general_aprc_cntx.num_of_item);

    /* Copy to global buffer and use the global buffer pointer */
    for (i = 0; i < aprc->general_aprc_cntx.num_of_item; i++)
    {
        mmi_ucs2cpy((CHAR*)subMenuData[i], (CHAR*)get_string((MMI_ID_TYPE)str_id_item_list[i]));
    }
    aprc->list_of_items = (U8 **)subMenuDataPtrs;
    GetSequenceImageIds_Ext(menu_id, item_icons);
    ConstructHintsList(menu_id, hintDataPtrs);
    /* Clear the folder hint string */
    if (type == MMI_UM_UI_ENTRY_MAIN_MENU)
    {
        mmi_um_ui_sh_main_msg_clear_folder_hint(hintDataPtrs, MAX_SUB_MENU_HINT_SIZE);
        aprc->list_of_item_hints = (U8 **)hintDataPtrs;
    }
    else
    {
        aprc->list_of_item_hints = NULL;
    }
    aprc->list_of_item_icons = (U16 *)item_icons;
    scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);

    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
    {
        return;
    }

#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
    if (type == MMI_UM_UI_ENTRY_DELETE_FOLDER)
    {
        if (!srv_um_check_ready_type(scrn_cntx->screen_hdlr.folder_type.msg_type))
        {
            //scrn_cntx->child_scrn_id = mmi_um_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
            scrn_cntx->child_scrn_id = mmi_um_ui_if_entry_general(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE, MMI_UM_ENTRY_SCREEN_DELETE_FOLDER, NULL);
            mmi_um_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
        }
    }
#endif /* __MMI_UM_DELETE_FOLDER_SUPPORT__ */
    /* inform FSM to check the current data */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);

#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
    if (type == MMI_UM_UI_ENTRY_MAIN_MENU)
#endif /* __MMI_UM_DELETE_FOLDER_SUPPORT__ */
    {
        /* Send the event out */
        MMI_FRM_INIT_EVENT(&entry_main_msg_evt, EVT_ID_MMI_UM_ENTRY_MAIN_MSG);
        entry_main_msg_evt.is_entry = MMI_TRUE;
        entry_main_msg_evt.um_user_data = (void *)scrn_cntx;
        MMI_FRM_CB_EMIT_POST_EVENT(&entry_main_msg_evt);
    }
}


MMI_BOOL mmi_um_ui_sh_non_fsm_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    
    /* FSM initialize */
    
    /* Appearance initialize */
    mmi_um_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_um_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;
    scrn_cntx->screen_hdlr.scrn_data = setting->scrn_data;

    return result;
}


MMI_BOOL mmi_um_ui_sh_mainmenu_fsm_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting, 
                    U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    /* FSM initialize */
    {
        mmi_um_ui_fsm_node_struct *fsm_cntx = &(scrn_cntx->fsm);
        mmi_um_ui_fsm_entry_list_struct *fsm;
        fsm = &(fsm_cntx->cntx.fsm_entry_list);
        memset(fsm, 0, sizeof(mmi_um_ui_fsm_entry_list_struct));
        
        /* External setting */
        fsm->scrn_id = scrn_cntx->scrn_id;
        fsm->req_folder_type= setting->folder;
        fsm->get_msg_num = mmi_um_ui_fsm_el_get_msg_num;
        /* Internal setting */
        fsm->pid = 0;
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_NONE;
        memset(&(fsm->req_msg_num_result), 0, sizeof(srv_um_get_msg_num_result));
    }
    /* Appearance initialize */
    mmi_um_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_um_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;
    scrn_cntx->screen_hdlr.scrn_data = setting->scrn_data;

    return result;
}

#ifdef __MMI_UM_EL_FSM_SUPPORT__
MMI_BOOL mmi_um_ui_sh_el_fsm_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting, 
                    U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_fsm_el_setting_struct fsm_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    
    /* FSM initialize */
    memset(&(fsm_setting), 0, sizeof(mmi_um_ui_fsm_el_setting_struct));
    fsm_setting.req_data = MMI_TRUE;
    fsm_setting.req_data_type = MMI_UM_UI_FSM_EL_REQ_MSG_NUM;
    if (type == 0)
    {
        //fsm_setting.scrn_callback_hdlr = mmi_um_ui_sh_delete_folder_fsm_cb;
    }
    else
    {
        fsm_setting.scrn_callback_hdlr = mmi_um_ui_sh_main_msg_fsm_cb;
    }
    fsm_setting.req_folder_type = setting->folder;
    fsm_setting.scrn_id = scrn_cntx->scrn_id;
    mmi_um_ui_fsm_el_init(&(scrn_cntx->fsm), fsm_setting);
    
    /* Appearance initialize */
    mmi_um_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_um_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;
    scrn_cntx->screen_hdlr.scrn_data = setting->scrn_data;

    return result;
}
#endif /* __MMI_UM_EL_FSM_SUPPORT__ */

void mmi_um_ui_sh_main_msg_delete_folder_update(void *arg, U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_of_item;
    U16 str_id_item_list[MAX_SUB_MENUS];
    U16 item_icons[MAX_SUB_MENUS];
    srv_um_get_msg_num_result *msg_num_info;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_main_menu_struct *aprc;
    U16 menu_id = MAIN_MENU_MESSAGES_MENUID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.main_menu);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
#ifdef __MMI_UM_EL_FSM_SUPPORT__
    scrn_cntx->fsm.cntx.fsm_entry_list.get_msg_num(scrn_cntx->scrn_id, &msg_num_info);
#else
    mmi_um_ui_fsm_el_get_msg_num(scrn_cntx->scrn_id, &msg_num_info);
#endif
    /* Update the stirng of folder menu item */
    if (mmi_frm_scrn_get_active_id() != scrn_cntx->screen_hdlr.disp_scrn_id)
    {
        return;
    }
#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
    if (type == 0)
#endif
    {
        menu_id = MAIN_MENU_MESSAGES_MENUID;
    }
#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
    else
    {
        menu_id = MENU_ID_UM_DELETE_FOLDER;
    }
#endif /* __MMI_UM_DELETE_FOLDER_SUPPORT__ */
    i = 0;
    num_of_item = 0;
    memset(str_id_item_list, 0, sizeof(str_id_item_list));
    num_of_item = GetSequenceStringIds_Ext(menu_id, str_id_item_list);
    MMI_ASSERT(MAX_SUB_MENUS >= num_of_item);

    if (type == 0)
    {
        ConstructHintsList(MAIN_MENU_MESSAGES_MENUID, hintDataPtrs);
    }
    
#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
    else
    {
        ConstructHintsList(MENU_ID_UM_DELETE_FOLDER, hintDataPtrs);
    }
#endif /*  __MMI_UM_DELETE_FOLDER_SUPPORT__ */
    /* Construct the menu item strings */
    aprc->general_aprc_cntx.num_of_item = num_of_item;
#ifdef __MMI_MESSAGE_MAIN_MENU_HINT_INLINE__
    if (type == MMI_UM_UI_ENTRY_MAIN_MENU)
    {
        mmi_um_ui_sh_main_msg_update_item(subMenuDataPtrs, msg_num_info);
    }
#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
    else
    {
        mmi_um_ui_sh_delete_folder_update_item(subMenuDataPtrs, msg_num_info);
    }
#endif /* __MMI_UM_DELETE_FOLDER_SUPPORT__ */
    aprc->list_of_items = subMenuDataPtrs;
    aprc->list_of_item_hints = NULL;
#else /* __MMI_MESSAGE_MAIN_MENU_HINT_INLINE__ */
    for (i = 0; i < num_of_item; i++)
    {
        mmi_ucs2cpy((CHAR*)subMenuData[i], (CHAR*)get_string((MMI_ID_TYPE)str_id_item_list[i]));
        memset(hintData[i], 0, MAX_SUB_MENU_HINT_SIZE);
        hintDataPtrs[i] = hintData[i];
    }
    if (type == MMI_UM_UI_ENTRY_MAIN_MENU)
    {
#ifndef __MMI_BT_MAP_CLIENT__
        mmi_um_ui_sh_main_msg_update_item_hint(hintDataPtrs, msg_num_info);
#endif
    }
#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
    else
    {
        mmi_um_ui_sh_delete_folder_update_item_hint(hintDataPtrs, msg_num_info);
    }
#endif /* __MMI_UM_DELETE_FOLDER_SUPPORT__ */
    aprc->list_of_items = subMenuDataPtrs;
    aprc->list_of_item_hints = hintDataPtrs;
#endif /* __MMI_MESSAGE_MAIN_MENU_HINT_INLINE__ */
    GetSequenceImageIds_Ext(MAIN_MENU_MESSAGES_MENUID, item_icons);
    aprc->list_of_item_icons = item_icons;
    
    scrn_cntx->aprc.redraw_func(&aprc_union, scrn_cntx->aprc.st_type, MMI_UM_UI_APRC_REDRAW_BODY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_init
 * DESCRIPTION
 *  Initialize the main message screen varialbe. It shall trigger the 
 *  fsm initial function to initialize the fsm context.
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  setting                 [IN]: Setting
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_main_msg_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
    
#ifdef __MMI_UM_EL_FSM_SUPPORT__
    return mmi_um_ui_sh_el_fsm_init(scrn_cntx, setting, 1);
#else
    return mmi_um_ui_sh_mainmenu_fsm_init(scrn_cntx, setting, 1);
#endif
}

MMI_BOOL mmi_um_ui_sh_main_msg_proc_interanl(U16 scrn_id, U16 event, mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
            MMI_ASSERT(scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE);
            scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
            mmi_um_ui_sh_create(mmi_um_ui_sh_main_msg_entry, scrn_cntx);
            break;
            
        case MMI_UM_UI_EVENT_CHECK:
        case MMI_UM_UI_EVENT_READY:
        case MMI_UM_UI_EVENT_REFRESH:
            mmi_um_ui_sh_main_msg_get_num(scrn_cntx);
           /* no break here, so it will reset message number using code below. */
        case MMI_UM_UI_EVENT_UNREADY:
            mmi_um_ui_sh_main_msg_reset(scrn_cntx);
    }
    return MMI_TRUE;
}

static MMI_BOOL mmi_um_ui_sh_main_msg_get_num(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    MMI_BOOL is_processing = MMI_FALSE;
    mmi_um_ui_fsm_node_struct *fsm_cntx = &(scrn_cntx->fsm);
    mmi_um_ui_fsm_entry_list_struct *fsm;
    fsm = &(fsm_cntx->cntx.fsm_entry_list);

    if (mmi_um_ui_int_is_available())
    {
        if (fsm->pid == 0)
        {
            fsm->req_srv_status = MMI_UM_UI_REQ_SRV_PROGRESS;
            #ifdef __MMI_TELEPHONY_SUPPORT__
            fsm->pid = srv_um_get_msg_num(
                            fsm->req_folder_type.msg_type, 
                            fsm->req_folder_type.sim_id, 
                            mmi_um_ui_mainmenu_req_msg_num_cb, 
                            fsm->scrn_id);
            #endif
            if (MMI_UM_UI_REQ_SRV_NONE == fsm->req_srv_status) /* sync callback, reset pid here */
            {
                fsm->pid = 0;
            }
            is_processing = MMI_TRUE;
        }
    }
    return is_processing;
}

static S32 mmi_um_ui_mainmenu_req_msg_num_cb(S32 pid, srv_um_get_msg_num_result *rsp, S32 para)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_list_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx((U16)para);
    
    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_list);

    if((pid != 0) && (pid == fsm->pid))
    {
        memcpy(&(fsm->req_msg_num_result), rsp, sizeof(srv_um_get_msg_num_result));
        mmi_um_ui_sh_main_msg_update(scrn_cntx);
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_NONE;
        fsm->pid = 0;
    }
    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_event_hdlr
 * DESCRIPTION
 *  Main message screen event handler. Receive the event from the Central 
 *  controller and it needs to handle the event by itself or pass to finite 
 *  state machine.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_main_msg_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        case MMI_UM_UI_EVENT_ABORT:
        case MMI_UM_UI_EVENT_CHECK:
        case MMI_UM_UI_EVENT_READY:
        case MMI_UM_UI_EVENT_UNREADY:
        case MMI_UM_UI_EVENT_REFRESH:
        {
        #ifndef __MMI_UM_EL_FSM_SUPPORT__
            result = mmi_um_ui_sh_main_msg_proc_interanl(scrn_id,event,scrn_cntx);
        #else
            result = mmi_um_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
        #endif
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            #ifdef __MMI_BT_MAP_CLIENT__
            if (scrn_cntx->aprc.st_type == MMI_UM_UI_SCRN_TYPE_MAIN_MENU)
            {
                g_sms_um_ui_main_menu_scrn_id = 0;
            }
            #endif
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        case MMI_UM_UI_EVENT_DELETED:
        {
            /* Set child screen as 0 */
            scrn_cntx->child_scrn_id = 0;
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}

#ifdef __MMI_UM_EL_FSM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_fsm_cb
 * DESCRIPTION
 *  The registered callback function for finite state machine. Finite state
 *  machine will notify screen handler and it should has the relative
 *  reaction.
 *
 * PARAMETERS
 *  scrn_id             [IN]: Current screen id
 *  state               [IN]: State of finite state machine
 *  status              [IN]: In that state, the current status
 *  
 * RETURNS
 *  MMI_TRUE: handle this callback successfully
 *  MMI_FALSE: fail to handle this callback
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_main_msg_fsm_cb(U16 scrn_id, U16 state, U16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    switch (state)
    {
        case MMI_UM_UI_FSM_EL_INSIDE:
        {
            if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_TRUE)
            {
                if (MMI_SCENARIO_STATE_ACTIVE == 
                    mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
                {
                    mmi_um_ui_sh_main_msg_update(scrn_cntx);
                }
            }
            else
            {
                scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
                mmi_um_ui_sh_create(mmi_um_ui_sh_main_msg_entry, scrn_cntx);
            }
            break;
        }
        case MMI_UM_UI_FSM_EL_UPDATE:
        {
            /* First entry main message menu */
            if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_TRUE)
            {
                /* receive unready indication, clean the number and refresh the screen */
                if (status == MMI_UM_UI_REQ_SRV_WAIT_READY)
                {
                    mmi_um_ui_sh_main_msg_reset(scrn_cntx);
                }
            }
            else
            {
                scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
                mmi_um_ui_sh_create(mmi_um_ui_sh_main_msg_entry, scrn_cntx);
            }
        }
        default:
        {
            break;
        }
    }

    return result;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry
 * DESCRIPTION
 *  Entry the main message screen.
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry(mmi_scrn_essential_struct *arg)
{
    mmi_um_ui_sh_main_msg_delete_folder_entry(arg, MMI_UM_UI_ENTRY_MAIN_MENU);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_exit
 * DESCRIPTION
 *  Exit main message screen.
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_exit(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_entry_main_msg_evt_struct entry_main_msg_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Send the event out */
    MMI_FRM_INIT_EVENT(&entry_main_msg_evt, EVT_ID_MMI_UM_ENTRY_MAIN_MSG);
    entry_main_msg_evt.is_entry = MMI_FALSE;
    entry_main_msg_evt.um_user_data = (void *)arg->user_data;
    MMI_FRM_CB_EMIT_POST_EVENT(&entry_main_msg_evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_hilite_hdlr
 * DESCRIPTION
 *  Highlight handler for main message menu.
 *
 * PARAMETERS
 *  index:          [IN]    highlight index
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = GetSeqItemId_Ext(MAIN_MENU_MESSAGES_MENUID, (U16)index);
    switch (menu_id)
    {
        case MENU_ID_UM_WRITE_MSG:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_write_msg);
            break;
        }
        case MENU_ID_UM_INBOX:
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__ 
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_inbox);
        #elif defined(__MMI_BT_MAP_CLIENT__)
            mmi_um_main_menu_general_highlight(mmi_sms_um_bt_ui_sh_main_msg_entry_inbox);
        #endif
            break;
        }
        case MENU_ID_UM_DRAFT:
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__ 
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_draft);
        #elif defined(__MMI_BT_MAP_CLIENT__)
            mmi_um_main_menu_general_highlight(mmi_sms_um_bt_ui_sh_main_msg_entry_draft);
        #endif
            break;
        }
        case MENU_ID_UM_UNSENT:
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__ 
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_outbox);
        #elif defined(__MMI_BT_MAP_CLIENT__)
            mmi_um_main_menu_general_highlight(mmi_sms_um_bt_ui_sh_main_msg_entry_outbox);
        #endif
            break;
        }
        case MENU_ID_UM_SENT:
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__ 
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_sent);
        #elif defined(__MMI_BT_MAP_CLIENT__)
            mmi_um_main_menu_general_highlight(mmi_sms_um_bt_ui_sh_main_msg_entry_sent);
        #endif
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MENU_ID_UM_ARCHIVE:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_archive);
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MENU_ID_UM_SIM:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_simbox);
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    #ifdef __MMI_UM_REPORT_BOX__
        case MENU_ID_UM_REPORT:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_report);
            break;
        }
    #endif /* __MMI_UM_REPORT_BOX__ */
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MENU_ID_UM_CS_BOX:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_cs_box);
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */

    #if defined(MMS_SUPPORT) && !defined(__UM_FOLDER__)
        case MENU_ID_UM_MMS_V01_MAIN:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_mms_v01);
            break;
        }
    #endif /* MMS_SUPPORT & !__UM_FOLDER__ */
	#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__) && !defined(__MMI_APP_MANAGER_SUPPORT__)        
		case MENU_ID_UM_PBOX_MAIN:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_pbox);
            break;
        }
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ & !__MMI_PROV_IN_UM__ */
    #ifdef __MMI_EMAIL__
        case MENU_ID_UM_EMAIL_MAIN:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_email);
            break;
        }
    #endif /* __MMI_EMAIL__ */
    #ifdef __MMI_IMPS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_IMPS__ */
    #ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
        case MENU_ID_UM_DELETE_FOLDER:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_del_folder);
            break;
        }
    #endif /* __MMI_UM_DELETE_FOLDER_SUPPORT__ */
	#ifdef __MMI_SMS_SLIM__
        case MENU_ID_UM_DELETE_MSG_FOLDER:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_del_msg_folder);
            break;
        }
    #endif /* __MMI_SMS_SLIM__ */
        case MENU_ID_UM_CB_MAIN:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_cb);
            break;
        }
    #if !defined(__MMI_PUSH_IN_UM__) && defined(BROWSER_SUPPORT) && defined(__WAP_PUSH_SUPPORT__) && !defined(__WAP_PUSH_SERVICE_ONLY_SUPPORT__)
        case MENU_ID_UM_WAP_PUSH_MSG_MAIN:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_wap_push_msg);
            break;
        }
    #endif /* !__MMI_PUSH_IN_UM__ && BROWSER_SUPPORT */
    #ifdef __MMI_UM_TEMPLATE_SUPPORT__
        case MENU_ID_UM_TEMPLATE:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_template);
            break;
        }
    #endif /* __MMI_UM_TEMPLATE_SUPPORT__ */
        case MENU_ID_UM_SETTING:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_setting);
            break;
        }
    #ifndef __UM_FOLDER__
    #ifdef __MMI_MESSAGES_TEMPLATE__
        case MENU_ID_UM_TEMPLATE_SMS_ONLY:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_template_sms_only);
            break;
        }
    #endif /* __MMI_MESSAGES_TEMPLATE__ */  
    #if (((defined(__MMI_BT_MAP_CLIENT__) && defined(__MMI_TELEPHONY_SUPPORT__)) || (!defined(__MMI_BT_MAP_CLIENT__))) && defined(__MMI_TELEPHONY_SUPPORT__))
        case MENU_ID_UM_SETTING_SMS_ONLY:
        {
            mmi_um_main_menu_general_highlight(mmi_um_ui_sh_main_msg_entry_setting_sms_only);
            break;
        }
    #endif
    #endif /* __UM_FOLDER__ */
        default:
        {
            ExecuteCurrHiliteHandler(index);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_update
 * DESCRIPTION
 *  Update the main message screen.
 *  Before:
 *      Inbox
 *      Draft
 *      Outbox
 *      ...
 *  After:
 *      Inbox (0/10)
 *      Draft (21)
 *      Outbox (2)
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_update(void *arg)
{
    mmi_um_ui_sh_main_msg_delete_folder_update(arg, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_update_item
 * DESCRIPTION
 *  Update the main message screen.
 *      Inbox (0/10)
 *      Draft (21)
 *      Outbox (1)
 *
 * PARAMETERS
 *  item_string             [OUT]: Buffer for items string
 *  msg_num_info            [IN]: Message number information
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_update_item(U8 **item_string, srv_um_get_msg_num_result *msg_num_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_of_item;
    U16 menu_id_idx;
    U16 item_str_id[MAX_SUB_MENUS];
    U8 hint_asc[MAX_SUB_MENU_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_num_info != NULL);
    
    num_of_item = GetSequenceStringIds_Ext(MAIN_MENU_MESSAGES_MENUID, item_str_id);
    MMI_ASSERT(MAX_SUB_MENUS >= num_of_item);

    for (i = 0; i < num_of_item; i++)
    {
        /* Only copy UM menu item */
        menu_id_idx = GetSeqItemId_Ext(MAIN_MENU_MESSAGES_MENUID, i);
        if (MENU_ID_UM_INBOX    == menu_id_idx ||
            MENU_ID_UM_DRAFT    == menu_id_idx ||
            MENU_ID_UM_UNSENT   == menu_id_idx ||
            MENU_ID_UM_SENT     == menu_id_idx ||
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            MENU_ID_UM_ARCHIVE  == menu_id_idx ||
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            MENU_ID_UM_SIM      == menu_id_idx ||
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        #ifdef __MMI_UM_REPORT_BOX__
            MENU_ID_UM_REPORT   == menu_id_idx ||
        #endif /* __MMI_UM_REPORT_BOX__ */
            MMI_TRUE)
        {
            mmi_ucs2cpy((CHAR*)item_string[i], (CHAR*)get_string((MMI_ID_TYPE)item_str_id[i]));
        }
        else
        {
            /* Do not need to redraw */
            item_string[i] = NULL;
        }
    }

    /* Inbox */
    if (!mmi_frm_test_menu_item_hide(MENU_ID_UM_INBOX))
    {
        i = GetIndexOfStringId_Ext(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_INBOX);
        sprintf((CHAR *)hint_asc, " (%d/%d)", msg_num_info->inbox_unread_msg_number, msg_num_info->inbox_msg_number);
        mmi_um_ui_ut_concate_str_with_num((CHAR *)hint_asc, (CHAR *)item_string[i]);
    }

    /* Draft, outbox, sent */
    mmi_um_ui_ut_update_item_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_DRAFT, item_string, msg_num_info->draft_msg_number);
    mmi_um_ui_ut_update_item_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_UNSENT, item_string, msg_num_info->unsent_msg_number);
    mmi_um_ui_ut_update_item_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_SENT, item_string, msg_num_info->sent_msg_number);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    mmi_um_ui_ut_update_item_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_ARCHIVE, item_string, msg_num_info->archive_msg_number);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    mmi_um_ui_ut_update_item_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_SIM, item_string, msg_num_info->sim_msg_number);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
    mmi_um_ui_ut_update_item_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_REPORT, item_string, msg_num_info->report_msg_number);
#endif /* __MMI_UM_REPORT_BOX__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_update_item_hint
 * DESCRIPTION
 *  Update the delete folder screen.
 *      Inbox
 *          10 messages
 *      Draft
 *          21 messages
 *      Outbox
 *          1 message
 *
 * PARAMETERS
 *  item_hint               [OUT]: Buffer for items hint string
 *  msg_num_info            [IN]: Message number information
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_update_item_hint(U8 **item_hint, srv_um_get_msg_num_result *msg_num_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_num_info != NULL);

    /* Write message */
    if (!mmi_frm_test_menu_item_hide(MENU_ID_UM_WRITE_MSG))
    {
        i = GetIndexOfStringId_Ext(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_WRITE_MSG);
        item_hint[i] = NULL;
    }

    mmi_um_ui_ut_update_item_hint_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_INBOX, item_hint, msg_num_info->inbox_msg_number);
    mmi_um_ui_ut_update_item_hint_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_DRAFT, item_hint, msg_num_info->draft_msg_number);
    mmi_um_ui_ut_update_item_hint_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_UNSENT, item_hint, msg_num_info->unsent_msg_number);
    mmi_um_ui_ut_update_item_hint_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_SENT, item_hint, msg_num_info->sent_msg_number);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    mmi_um_ui_ut_update_item_hint_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_ARCHIVE, item_hint, msg_num_info->archive_msg_number);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    mmi_um_ui_ut_update_item_hint_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_SIM, item_hint, msg_num_info->sim_msg_number);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
    mmi_um_ui_ut_update_item_hint_by_menu_id(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_REPORT, item_hint, msg_num_info->report_msg_number);
#endif /* __MMI_UM_REPORT_BOX__ */


#ifdef __MMI_UM_CONVERSATION_BOX__
    if (!mmi_frm_test_menu_item_hide(MENU_ID_UM_CS_BOX))
    {
        i = GetIndexOfStringId_Ext(MAIN_MENU_MESSAGES_MENUID, MENU_ID_UM_CS_BOX);
        item_hint[i] = NULL;
    }
#endif /* __MMI_UM_CONVERSATION_BOX__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_reset
 * DESCRIPTION
 *  Reset the main message screen.
 *  Set as follows
 *      Inbox
 *      Draft
 *      Outbox
 *      ...
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_reset(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_of_item;
    U16 str_id_item_list[MAX_SUB_MENUS];
    U16 item_icons[MAX_SUB_MENUS];
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_main_menu_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.main_menu);
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_struct_union));
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Update the stirng of folder menu item */
    if (MMI_SCENARIO_STATE_ACTIVE != 
        mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
    {
        return;
    }

    i = 0;
    num_of_item = 0;
    memset(str_id_item_list, 0, sizeof(str_id_item_list));
    num_of_item = GetSequenceStringIds_Ext(MAIN_MENU_MESSAGES_MENUID, str_id_item_list);
    MMI_ASSERT(MAX_SUB_MENUS >= num_of_item);

    /* Construct the menu item strings */
    aprc->general_aprc_cntx.num_of_item = num_of_item;
    for (i = 0; i < num_of_item; i++)
    {
        mmi_ucs2cpy((CHAR*)subMenuData[i], (CHAR*)get_string((MMI_ID_TYPE)str_id_item_list[i]));
    }
    ConstructHintsList(MAIN_MENU_MESSAGES_MENUID, hintDataPtrs);
    /* Clear the folder hint string */
    mmi_um_ui_sh_main_msg_clear_folder_hint(hintDataPtrs, MAX_SUB_MENU_HINT_SIZE);

    aprc->list_of_items = subMenuDataPtrs;
    aprc->list_of_item_hints = hintDataPtrs;
    GetSequenceImageIds_Ext(MAIN_MENU_MESSAGES_MENUID, item_icons);
    aprc->list_of_item_icons = item_icons;
    
    scrn_cntx->aprc.redraw_func(&aprc_union, scrn_cntx->aprc.st_type, MMI_UM_UI_APRC_REDRAW_BODY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_folder
 * DESCRIPTION
 *  Entry folder from main message menu.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_folder(srv_um_msg_box_enum msg_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UM_EL_FSM_SUPPORT__
    U16 fsm_state;
#else
    MMI_BOOL is_nubmer_got = MMI_FALSE;
#endif
    U16 number;
    srv_um_box_identity_struct folder;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_get_msg_num_result *msg_num_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_MAP_CLIENT__

    scrn_cntx = mmi_um_ui_sh_get_active_user_data(); 
    if (scrn_cntx == NULL)
    {
        scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(mmi_frm_scrn_get_active_id()); 
        if (scrn_cntx == NULL)
            scrn_cntx = g_sh_get_item_scrn_cntx;
    }
#else
    scrn_cntx = mmi_um_ui_sh_get_active_user_data(); 
#endif /* __MMI_BT_MAP_CLIENT__ */

    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
#ifdef __MMI_BT_MAP_CLIENT__
    if (scrn_cntx->fsm.cntx.fsm_entry_list.get_msg_num != NULL)
        scrn_cntx->fsm.cntx.fsm_entry_list.get_msg_num(scrn_cntx->scrn_id, &msg_num_info);
    else
        mmi_um_ui_fsm_el_get_msg_num(scrn_cntx->scrn_id, &msg_num_info);
#else
    scrn_cntx->fsm.cntx.fsm_entry_list.get_msg_num(scrn_cntx->scrn_id, &msg_num_info);
#endif /* __MMI_BT_MAP_CLIENT__ */
    folder.msg_box_type = msg_box;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_cntx->child_scrn_id = mmi_um_ui_if_entry_general(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE, MMI_UM_ENTRY_SCREEN_GENERAL_FOLDER, &folder);
    number = mmi_um_ui_ut_get_msg_num_by_msg_box(msg_box, msg_num_info);
#ifdef __MMI_UM_EL_FSM_SUPPORT__
    fsm_state = mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm));
    if (0 == number && MMI_UM_UI_FSM_EL_INSIDE == fsm_state)
#else /* __MMI_UM_EL_FSM_SUPPORT__ */
    {
        mmi_um_ui_fsm_entry_list_struct * fsm_node = &scrn_cntx->fsm.cntx.fsm_entry_list;
        is_nubmer_got = (MMI_BOOL)(fsm_node->pid == 0);
    }
    if (0 == number && is_nubmer_got)
#endif /* __MMI_UM_EL_FSM_SUPPORT__ */
    {
        number = 0xffff;
    #if !defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
        mmi_um_ui_cc_send_event(scrn_cntx->child_scrn_id, MMI_UM_UI_EVENT_SET_NUM_MSG_INSIDE, &number);
    #endif
    }
    mmi_um_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_write_msg
 * DESCRIPTION
 *  Entry write message screen. it could be UC or UM selection screen.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__UM_FOLDER__) && !defined(__MMI_UNIFIED_COMPOSER__)
    U16 scrn_id;
#endif /* __UM_FOLDER__ && !__MMI_UNIFIED_COMPOSER__ */
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

#ifdef __UM_FOLDER__
    #ifdef __MMI_UNIFIED_COMPOSER__
        mmi_um_ui_adp_cui_launch_by_menu_id(mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id), MENU_ID_UM_WRITE_MSG);
    #else /* __MMI_UNIFIED_COMPOSER__ */
        scrn_id = mmi_um_ui_if_entry_write_msg(0, scrn_cntx->group_id, MMI_FALSE);
        mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_INIT, NULL);
    #endif /* __MMI_UNIFIED_COMPOSER__ */
#else /* !__UM_FOLDER__ */
    mmi_um_ui_adp_cui_launch_by_menu_id(mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id), MENU_ID_UM_WRITE_MSG_SMS);
#endif /* __UM_FOLDER__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_inbox
 * DESCRIPTION
 *  Entry inbox from main message menu.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BOX_INBOX);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_draft
 * DESCRIPTION
 *  Entry draft from main message menu.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BOX_DRAFT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_outbox
 * DESCRIPTION
 *  Entry outbox from main message menu.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BOX_UNSENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_sent
 * DESCRIPTION
 *  Entry sent from main message menu.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BOX_SENT);
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_archive
 * DESCRIPTION
 *  Entry archive from main message menu.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_archive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BOX_ARCHIVE);
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_simbox
 * DESCRIPTION
 *  Entry simbox from main message menu.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BOX_SIM);
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


#ifdef __MMI_UM_REPORT_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_report
 * DESCRIPTION
 *  Entry report box from main message menu.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_main_msg_entry_folder(SRV_UM_MSG_BOX_REPORT);
}
#endif /* __MMI_UM_REPORT_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_del_folder
 * DESCRIPTION
 *  Entry delete messages screens
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_del_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    scrn_id = mmi_um_ui_if_entry_general(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE, MMI_UM_ENTRY_SCREEN_DELETE_FOLDER, NULL);
    mmi_um_ui_ut_send_init_event(scrn_id);
}
#ifdef __MMI_SMS_SLIM__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_del_msg_folder
 * DESCRIPTION
 *  Entry delete messages screens
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_del_msg_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

	mmi_um_ui_adp_cui_msg_delete_launch(scrn_cntx->group_id,MENU_ID_UM_DELETE_MSG_FOLDER);
}
#endif


#if defined(MMS_SUPPORT) && !defined(__UM_FOLDER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_mms_v01
 * DESCRIPTION
 *  Entry MMS V01 main screen
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_mms_v01(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_MMS_V01_MAIN);
}
#endif /* MMS_SUPPORT & !__UM_FOLDER__ */


#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__)
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_pbox
 * DESCRIPTION
 *  Entry Provisioing message main screen
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_pbox(void)
{
#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__) && !defined(__MMI_APP_MANAGER_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_PBOX_MAIN);
#endif
}
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ & !__MMI_PROV_IN_UM__ */


#ifdef __MMI_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_email
 * DESCRIPTION
 *  Entry Email main screen
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_EMAIL_MAIN);
}
#endif /* __MMI_EMAIL__ */


#ifdef __MMI_IMPS__
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
#endif /* __MMI_IMPS__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_cb
 * DESCRIPTION
 *  Entry cell broadcast main screen
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_CB_MAIN);
}


#if !defined(__MMI_PUSH_IN_UM__) && defined(BROWSER_SUPPORT) && defined(__WAP_PUSH_SUPPORT__) && !defined(__WAP_PUSH_SERVICE_ONLY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_wap_push_msg
 * DESCRIPTION
 *  Entry wap push service message main screen
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_wap_push_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_WAP_PUSH_MSG_MAIN);
}
#endif /* !__MMI_PUSH_IN_UM__ && BROWSER_SUPPORT */


#ifdef __MMI_UM_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_template
 * DESCRIPTION
 *  Entry template selection screen
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

   
    scrn_id = mmi_um_ui_if_entry_general(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE, MMI_UM_ENTRY_SCREEN_TEMPLATE, NULL);
    mmi_um_ui_ut_send_init_event(scrn_id);
}
#endif /* __MMI_UM_TEMPLATE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_setting
 * DESCRIPTION
 *  Entry setting selection screen
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    scrn_id = mmi_um_ui_if_entry_general(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE, MMI_UM_ENTRY_SCREEN_SETTING, NULL);
    mmi_um_ui_ut_send_init_event(scrn_id);
}


#ifndef __UM_FOLDER__
#ifdef __MMI_MESSAGES_TEMPLATE__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_template_sms_only
 * DESCRIPTION
 *  Entry sms only template
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_template_sms_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_TEMPLATE_SMS_ONLY);
}
#endif /* __MMI_MESSAGES_TEMPLATE__ */


#if ((defined(__MMI_BT_MAP_CLIENT__) && defined(__MMI_TELEPHONY_SUPPORT__)) || (!defined(__MMI_BT_MAP_CLIENT__)) || (!defined(__MMI_TELEPHONY_SUPPORT__)))

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_setting_sms_only
 * DESCRIPTION
 *  Entry sms only setting
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_setting_sms_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
#ifdef __MMI_TELEPHONY_SUPPORT__
    mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_SETTING_SMS_ONLY);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
}
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#endif /* __UM_FOLDER__ */


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_cs_box
 * DESCRIPTION
 *  Entry conversation box from main message menu.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_cs_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    scrn_cntx->child_scrn_id = mmi_um_ui_if_entry_conversation_box(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
    mmi_um_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_arrange_menu_item
 * DESCRIPTION
 *  Arrange the menu item and index.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: Screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_arrange_menu_item(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UM_CONVERSATION_BOX__
    U8 select;
    S16 error;
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    mmi_um_ui_sh_main_msg_adjust_menu_item((MMI_BOOL)mmi_email_is_email_can_forward(), 
                                           MENU_ID_UM_EMAIL_MAIN, 
                                           MAIN_MENU_MESSAGES_MENUID, 
                                           scrn_cntx);
#endif /* __MMI_EMAIL__ */

#ifdef __MMI_IMPS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_IMPS__ */

#ifdef __QQIM_SUPPORT__
    mmi_um_ui_sh_main_msg_adjust_menu_item(mmi_qqim_is_qqim_can_forward(),
                                           MESSAGES_MENU_QQIM_MENUID,
                                           MAIN_MENU_MESSAGES_MENUID,
                                           scrn_cntx);
#endif /* __QQIM_SUPPORT__ */

#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__) && !defined(__MMI_APP_MANAGER_SUPPORT__)    
	mmi_um_ui_sh_main_msg_adjust_menu_item(mmi_provbox_app_is_ready(), 
                                           MENU_ID_UM_PBOX_MAIN, 
                                           MAIN_MENU_MESSAGES_MENUID, 
                                           scrn_cntx);
#endif /* defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__) */

#if (defined(MMS_SUPPORT) && defined(OBIGO_Q03C_MMS_V01))
    mmi_um_ui_sh_main_msg_adjust_menu_item(mmi_mms_is_mms_can_enter(), 
                                           MENU_ID_UM_MMS_V01_MAIN, 
                                           MAIN_MENU_MESSAGES_MENUID, 
                                           scrn_cntx);
#endif /* MMS_SUPPORT && OBIGO_Q03C_MMS_V01 */

#ifdef __MMI_TELEPHONY_SUPPORT__
    mmi_um_ui_sh_main_msg_adjust_menu_item(mmi_msg_is_display_cphs_menu_items(),
                                           MENU_ID_UM_CB_MAIN, 
                                           MAIN_MENU_MESSAGES_MENUID, 
                                           scrn_cntx);
#else
    mmi_um_ui_sh_main_msg_adjust_menu_item(MMI_FALSE,
                                           MENU_ID_UM_CB_MAIN, 
                                           MAIN_MENU_MESSAGES_MENUID, 
                                           scrn_cntx);
    mmi_um_ui_sh_main_msg_adjust_menu_item(MMI_FALSE,
                                           MENU_ID_UM_SETTING_SMS_ONLY, 
                                           MAIN_MENU_MESSAGES_MENUID, 
                                           scrn_cntx);
#ifdef __MMI_SMS_SLIM__
    mmi_um_ui_sh_main_msg_adjust_menu_item(MMI_FALSE,
                                           MENU_ID_UM_DELETE_MSG_FOLDER, 
                                           MAIN_MENU_MESSAGES_MENUID, 
                                           scrn_cntx);
#endif /* __MMI_SMS_SLIM__ */
#endif
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    mmi_um_ui_sh_main_msg_adjust_menu_item((MMI_BOOL)(0 != srv_sim_ctrl_get_one_available_sim()),
                                       MENU_ID_UM_SIM, 
                                       MAIN_MENU_MESSAGES_MENUID, 
                                       scrn_cntx);
#endif

#if defined(__MMI_BT_BOX__) || defined(__MMI_WEARABLE_DEVICE__)
 mmi_um_ui_sh_main_msg_adjust_menu_item(MMI_FALSE,
                                        MENU_ID_UM_WRITE_MSG, 
                                        MAIN_MENU_MESSAGES_MENUID, 
                                        scrn_cntx);
 mmi_um_ui_sh_main_msg_adjust_menu_item(MMI_FALSE,
                                        MENU_ID_UM_DRAFT, 
                                        MAIN_MENU_MESSAGES_MENUID, 
                                        scrn_cntx);
 mmi_um_ui_sh_main_msg_adjust_menu_item(MMI_FALSE,
					MENU_ID_UM_SENT, 
					MAIN_MENU_MESSAGES_MENUID, 
					scrn_cntx);
#endif

#ifdef __MMI_UM_CONVERSATION_BOX__
	/* if (MMI_TRUE == mmi_um_ui_int_is_available()) */
	{
		ReadValue(NVRAM_UM_CONVERSATION_BOX_SETTING, &select, DS_BYTE, &error);
		if (select != 0 && select != 1)
		{
			/* Value is wrong, reset as default value */
        #ifdef __OP01__
            select = 0;
        #else
            select = 1;
        #endif
			WriteValue(NVRAM_UM_CONVERSATION_BOX_SETTING, &select, DS_BYTE, &error);
		}
		mmi_um_ui_sh_main_msg_adjust_menu_item((MMI_BOOL)select, 
											   MENU_ID_UM_CS_BOX, 
											   MAIN_MENU_MESSAGES_MENUID, 
											   scrn_cntx);
		mmi_um_ui_sh_main_msg_adjust_menu_item((MMI_BOOL)!select, 
											   MENU_ID_UM_INBOX, 
											   MAIN_MENU_MESSAGES_MENUID, 
											   scrn_cntx);
		mmi_um_ui_sh_main_msg_adjust_menu_item((MMI_BOOL)!select, 
											   MENU_ID_UM_SENT, 
											   MAIN_MENU_MESSAGES_MENUID, 
											   scrn_cntx);
		#ifdef __MMI_UM_CONVERSATION_BOX_WITH_OUTBOX__
			mmi_um_ui_sh_main_msg_adjust_menu_item((MMI_BOOL)!select, 
												   MENU_ID_UM_UNSENT, 
												   MAIN_MENU_MESSAGES_MENUID, 
												   scrn_cntx);
		#endif /* __MMI_UM_CONVERSATION_BOX_WITH_OUTBOX__ */
	}
#endif /* __MMI_UM_CONVERSATION_BOX__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_adjust_menu_item
 * DESCRIPTION
 *  Adjust one menu item status. hide/unhide and index arrangement.
 *
 * PARAMETERS
 *  is_shown                [IN]: hide or unhide menu item
 *  child_item_id           [IN]: the child menu item
 *  parent_item_id          [IN]: the parent menu item
 *  scrn_cntx               [IN]: the current screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_adjust_menu_item(MMI_BOOL is_shown, U16 child_item_id, U16 parent_item_id, mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 highlight_item_id = 0;
    S16 gui_hiliteitem = 0;
    S16 new_highlight_index;
    U8 *gui_buffer;
    list_menu_category_history *h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_buffer = mmi_frm_scrn_get_gui_buf(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id);
    h = (list_menu_category_history*)gui_buffer;

    /* First entry main message menu */
    if (MMI_SCENARIO_STATE_FIRST_ENTRY ==
        mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
    {
        if (is_shown == MMI_TRUE)
        {
            mmi_frm_unhide_menu_item(child_item_id);
        }
        else
        {
            mmi_frm_hide_menu_item(child_item_id);
        }
        return;
    }

    /* Goback history to adjust the highlight and menu item */
    /* get the current highlight menu item id */
    if (gui_buffer != NULL)
    {
        gui_hiliteitem = h->highlighted_item;
        highlight_item_id = GetSeqItemId_Ext(parent_item_id, gui_hiliteitem);
    }

    /* hide/unhide the menu item */
    if (is_shown == MMI_TRUE)
    {
        mmi_frm_unhide_menu_item(child_item_id);
    }
    else
    {
        mmi_frm_hide_menu_item(child_item_id);
    }

    /* reset the highlight index by current highlight menu item */
    if (gui_buffer != NULL)
    {
        new_highlight_index = GetIndexOfStringId_Ext(parent_item_id, highlight_item_id);

        if (new_highlight_index != gui_hiliteitem)
        {
            h->highlighted_item = new_highlight_index;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_clear_folder_hint
 * DESCRIPTION
 *  Clear folder hint string
 *      <Inbox, draft, outbox, sent, archive, sim message>
 *
 *
 * PARAMETERS
 *  popup_list              [IN]: the hint string
 *  length                  [IN]: the length of string
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_clear_folder_hint(U8 **popup_list, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_main_msg_clear_folder_hint_by_menu_id(MENU_ID_UM_INBOX, popup_list, length);
    mmi_um_ui_sh_main_msg_clear_folder_hint_by_menu_id(MENU_ID_UM_DRAFT, popup_list, length);
    mmi_um_ui_sh_main_msg_clear_folder_hint_by_menu_id(MENU_ID_UM_UNSENT, popup_list, length);
    mmi_um_ui_sh_main_msg_clear_folder_hint_by_menu_id(MENU_ID_UM_SENT, popup_list, length);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    mmi_um_ui_sh_main_msg_clear_folder_hint_by_menu_id(MENU_ID_UM_ARCHIVE, popup_list, length);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    mmi_um_ui_sh_main_msg_clear_folder_hint_by_menu_id(MENU_ID_UM_SIM, popup_list, length);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __MMI_UM_CONVERSATION_BOX__
    mmi_um_ui_sh_main_msg_clear_folder_hint_by_menu_id(MENU_ID_UM_CS_BOX, popup_list, length);
#endif /* __MMI_UM_CONVERSATION_BOX__ */
#ifdef __MMI_UM_REPORT_BOX__
    mmi_um_ui_sh_main_msg_clear_folder_hint_by_menu_id(MENU_ID_UM_REPORT, popup_list, length);
#endif /* __MMI_UM_REPORT_BOX__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_clear_folder_hint_by_menu_id
 * DESCRIPTION
 *  Clear folder hint string by single menu id
 *      <Inbox, draft, outbox, sent, archive, sim message>
 *
 *
 * PARAMETERS
 *  menu_id                 [IN]: single menu id
 *  hint_ptr                [IN]: the hint string
 *  length                  [IN]: the length of string
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_clear_folder_hint_by_menu_id(U16 menu_id, U8 **hint_ptr, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_test_menu_item_hide(menu_id))
    {
        index = GetIndexOfStringId_Ext(MAIN_MENU_MESSAGES_MENUID, menu_id);
        if (NULL == hint_ptr[index])
        {
            /* set as global */
            hint_ptr[index] = hintData[index];
        }
        memset(hint_ptr[index], 0, sizeof(length));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_message_update_by_app
 * DESCRIPTION
 *  It used to update the main menu screen by menu item id and the updated 
 *  string. Only use for other message application used.
 *
 * PARAMETERS
 *  menu_item_id:       [IN]    Menu item id
 *  update_string:      [IN]    Updated string
 *  user_data:          [IN]    Screen user data
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_message_update_by_app(U16 menu_item_id, U8 *update_string, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Should not update UM related menu id */
    if (MENU_ID_UM_WRITE_MSG == menu_item_id || 
        MENU_ID_UM_INBOX == menu_item_id || 
        MENU_ID_UM_DRAFT == menu_item_id || 
        MENU_ID_UM_UNSENT == menu_item_id || 
        MENU_ID_UM_SENT == menu_item_id || 
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        MENU_ID_UM_ARCHIVE == menu_item_id || 
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        MENU_ID_UM_SIM == menu_item_id || 
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    #ifdef __MMI_UM_REPORT_BOX__
        MENU_ID_UM_REPORT == menu_item_id ||
    #endif /* __MMI_UM_REPORT_BOX__ */

    #ifdef __MMI_UM_TEMPLATE_SUPPORT__
        MENU_ID_UM_TEMPLATE == menu_item_id || 
    #endif /* __MMI_UM_TEMPLATE_SUPPORT__ */
        MENU_ID_UM_SETTING == menu_item_id)
    {
        MMI_ASSERT(0);
    }
    MMI_ASSERT(update_string != NULL);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Update the stirng of folder menu item */
    if (MMI_SCENARIO_STATE_ACTIVE != 
        mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
    {
        return;
    }

    /* Check if the update menu id is hided */
    if (!mmi_frm_test_menu_item_hide(menu_item_id))
    {
        i = GetIndexOfStringId_Ext(MAIN_MENU_MESSAGES_MENUID, menu_item_id);

        mmi_ucs2cpy((CHAR*)subMenuData[i], (CHAR*)update_string);
        Category53ChangeItemText((S32)i, (U8*)subMenuData[i]);

        RedrawCategoryFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_init
 * DESCRIPTION
 *  Initialize the general folder variable. It shall trigger the fsm initial
 *  function to initialize the fsm context.
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  setting                 [IN]: Setting
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_general_folder_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_fsm_ef_setting_struct fsm_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    
    /* FSM initialize */
    memset(&fsm_setting, 0, sizeof(mmi_um_ui_fsm_ef_setting_struct));
    fsm_setting.folder_mode = MMI_UM_FOLDER_MODE_DEFAULT;
    fsm_setting.folder_type = setting->folder;
    fsm_setting.scrn_callback_hdlr = mmi_um_ui_sh_general_folder_fsm_cb;
    fsm_setting.scrn_id = scrn_cntx->scrn_id;
    mmi_um_ui_fsm_ef_init(&(scrn_cntx->fsm), fsm_setting);

    /* Appearance initialize */
    mmi_um_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_um_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;
    scrn_cntx->screen_hdlr.scrn_data = setting->scrn_data;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_event_hdlr
 * DESCRIPTION
 *  Folder event handler. Receive the event from the Central controller and 
 *  it needs to handle the event by itself or pass to finite state machine.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_general_folder_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        case MMI_UM_UI_EVENT_ABORT:
        case MMI_UM_UI_EVENT_CHECK:
        case MMI_UM_UI_EVENT_UNREADY:
        case MMI_UM_UI_EVENT_REL_DATA_LIST:
        {
            #if 0
/* under construction !*/
/* under construction !*/
            #endif
            result = mmi_um_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            break;
        }
        case MMI_UM_UI_EVENT_READY:
        {
            if (mmi_um_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
            {
                /* If current state is not check ready, return */
                if (mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)) != MMI_UM_UI_FSM_EF_CHECK_READY)
                {
                    break;
                }

                /* Invoke FSM mechanism */
                #if 0
/* under construction !*/
/* under construction !*/
                #endif
                result = mmi_um_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            }
            break;
        }
        case MMI_UM_UI_EVENT_REFRESH:
        {
            srv_um_msg_box_enum *msg_box;

            msg_box = (srv_um_msg_box_enum *)arg;
            /* Check current box folder */
            if ((scrn_cntx->screen_hdlr.folder_type.msg_box_type & *msg_box) == 0)
            {
                break;
            }

            /***********************************************************************************
             * Empty screen => other screen => new message => it should set a fake number of 
             * message
             * Because we use the trick solution to set the data list as NULL to avoid the 
             * un-necessary loading screen.
             **********************************************************************************/
            if (0 == scrn_cntx->screen_hdlr.num_of_item)
            {
                scrn_cntx->screen_hdlr.num_of_item = 1;
            }
            /* No any action */
            if (mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)) == MMI_UM_UI_FSM_EF_CHECK_DATA &&
                MMI_SCENARIO_STATE_ACTIVE != mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
            {
                /* Turn on the update flag */
                result = scrn_cntx->fsm.event_hdlr(scrn_id, MMI_UM_UI_FSM_EVENT_UPDATE_DATA_LIST, NULL);

                /* Check child group id, child must be option menu */
                /* Dial confirm => refresh indication, Option => delete confirm (conversations), any confirm popup */
                if ((0 != scrn_cntx->child_group_id && mmi_frm_group_get_active_id() == scrn_cntx->child_group_id) ||
                    (GRP_ID_INVALID != scrn_cntx->screen_hdlr.cf_grp_id))
                {
                    /* Display a hint to end user */
                    mmi_popup_display_simple(
                            (WCHAR *)get_string(STR_GLOBAL_UPDATE), 
                            MMI_EVENT_INFO, 
                            scrn_cntx->group_id, 
                            NULL);
                }
            }
            else
            {
                /* Invoke refresh mechanism */
                #if 0
/* under construction !*/
/* under construction !*/
                #endif
                result = mmi_um_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            }
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        case MMI_UM_UI_EVENT_DELETED:
        {
            /* Set child screen as 0 */
            scrn_cntx->child_scrn_id = 0;
            /* During update data, it could not call "GobackHistory" in loading screen */
            if (mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)) == MMI_UM_UI_FSM_EF_UPDATE_DATA && 
                MMI_SCENARIO_STATE_ACTIVE != mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
            {
                //MMI_ASSERT(0);
            }
            /* 
             * During updating data, screen is not in history. It should delete the screen context.
             * The scenario should be messaging => inbox => get_list => display loading => press end key
             */
            if ((MMI_UM_UI_FSM_EF_UPDATE_DATA == mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)) ||
                 MMI_UM_UI_FSM_EF_CHECK_READY == mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm))) && 
                MMI_FALSE == mmi_frm_scrn_is_present(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, MMI_FRM_NODE_ALL_FLAG))
            {
                mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
            }
            break;
        }
        case MMI_UM_UI_EVENT_HIGHLIGHT_CHANGE:
        {
            mmi_um_ui_sh_hilite_folder_info_struct *hilite_folder;
            /* Set the new highlight */
            hilite_folder = (mmi_um_ui_sh_hilite_folder_info_struct *)arg;

            if (scrn_cntx->screen_hdlr.folder_type.msg_box_type == hilite_folder->folder_info.msg_box_type)
            {
                scrn_cntx->screen_hdlr.hilite_info.msg_id = hilite_folder->hilite_info.msg_id;
                scrn_cntx->screen_hdlr.hilite_info.msg_type = hilite_folder->hilite_info.msg_type;
            #ifdef __MMI_UM_CONVERSATION_BOX__
                scrn_cntx->screen_hdlr.hilite_info.thrd_id.type = hilite_folder->hilite_info.thrd_id.type;
                scrn_cntx->screen_hdlr.hilite_info.thrd_id.value = hilite_folder->hilite_info.thrd_id.value;
            #endif /* __MMI_UM_CONVERSATION_BOX__ */
            }
            break;
        }
        case MMI_UM_UI_EVENT_HIGHLIGHT_IDX_CHANGE:
        {
            mmi_um_ui_sh_hilite_folder_info_struct *hilite_folder;
            /* Set the new highlight */
            hilite_folder = (mmi_um_ui_sh_hilite_folder_info_struct *)arg;

            if (scrn_cntx->screen_hdlr.folder_type.msg_box_type == hilite_folder->folder_info.msg_box_type)
            {
                scrn_cntx->screen_hdlr.hilite_info.index = hilite_folder->hilite_info.index;
            }
            break;
        }
        case MMI_UM_UI_EVENT_SET_NUM_MSG_INSIDE:
        {
            U16 *num;

            num = (U16 *)arg;
            if (0xffff == *num)
            {
                /* Set event to FSM */
                result = scrn_cntx->fsm.event_hdlr(scrn_id, MMI_UM_UI_FSM_EVENT_KEEP_DATA_LIST, NULL);
            }
            break;
        }
        case MMI_UM_UI_EVENT_SET_FILTER_TYPE:
        {
            srv_um_list_filter_struct *filter;

            filter = (srv_um_list_filter_struct *)arg;
            /* Set the sorting type */
            mmi_um_ui_fsm_ef_set_list_filter_type(&(scrn_cntx->fsm), *filter);
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_UI_EVENT_SET_FOLDER_MODE:
        {
            mmi_um_ui_folder_mode_enum *mode;

            mode = (mmi_um_ui_folder_mode_enum *)arg;
            /* Set the folder mode */
            mmi_um_ui_fsm_ef_set_folder_mode(&(scrn_cntx->fsm), *mode);
            break;
        }
    #endif /* __MMI_UM_CONVERSATIO_BOX__ */
    #ifdef __MMI_UM_ITERATOR_VIEWER__
        case MMI_UM_UI_EVENT_QUERY_INDEXING:
        {
            if (NULL != scrn_cntx->ext_app_user_data)
            {
                OslMfree(scrn_cntx->ext_app_user_data);
                scrn_cntx->ext_app_user_data = NULL;
            }
            scrn_cntx->ext_app_user_data = OslMalloc(sizeof(mmi_um_iter_viewer_info_struct));
            memcpy(scrn_cntx->ext_app_user_data, arg, sizeof(mmi_um_iter_viewer_info_struct));
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
            break;
        }
    #endif /* __MMI_UM_ITERATOR_VIEWER__ */
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_fsm_cb
 * DESCRIPTION
 *  A general folder callback is regitered to finite state machine. 
 *  It is used to know the state and status from the finite state machine. 
 *  Screen handler needs to display some screens if it is necessary.
 *  Currently, it uses the Entry folder finite state machine and it needs to 
 *  handle 5 states situation.
 *
 * PARAMETERS
 *  scrn_id             [IN]: Current screen id
 *  state               [IN]: State of finite state machine
 *  status              [IN]: In that state, the current status
 *  
 * RETURNS
 *  MMI_TRUE: handle the callback successfully
 *  MMI_FALSE: fail to handle this callback
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_general_folder_fsm_cb(U16 scrn_id, U16 state, U16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_item;
    MMI_BOOL result;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_folder_mode_enum folder_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Based on the Mode, get the entry function pointer */
    folder_mode = mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm));

    switch (state)
    {
        case MMI_UM_UI_FSM_EF_CHECK_READY:
        {
            MMI_ID child_group_id;

            /* call UI interface to entry a process screen with RSK */
            /* Check child group id, option menu */
            if (0 != scrn_cntx->child_group_id)
            {
                if (mmi_frm_group_get_active_id() == scrn_cntx->child_group_id)
                {
                    /* Display a hint to end user */
                    mmi_popup_display_simple(
                            (WCHAR *)get_string(STR_GLOBAL_UPDATE), 
                            MMI_EVENT_INFO, 
                            scrn_cntx->group_id, 
                            NULL);
                }
                else
                {
                    child_group_id = scrn_cntx->child_group_id;
                    scrn_cntx->child_group_id = 0;
                    /* Reset the data list */
                    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);
                    
                    /* Reset cache in the Service level */
                    srv_um_clear_msg_info_cache();
                    cui_menu_close(child_group_id);
                }
            }
            else
            {
            }
            break;
        }
        case MMI_UM_UI_FSM_EF_CHECK_DATA:
        {
        #ifdef __MMI_UM_CONVERSATION_BOX__
            U16 tmp_child_scrn_id;
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
        #ifdef __MMI_UM_ITERATOR_VIEWER__
            mmi_um_iter_viewer_info_struct *viewer_info;
        #endif /* __MMI_UM_ITERATOR_VIEWER__ */

            /* It is ready to display screen */
            num_item = mmi_um_ui_sh_general_folder_get_msg_num(scrn_cntx);

        #ifdef __MMI_UM_CONVERSATION_BOX__
            tmp_child_scrn_id = scrn_cntx->child_scrn_id;
            /* In thread message mode, the empty list should delete thread list, too */
            if (0 == num_item &&
                MMI_UM_FOLDER_MODE_THREAD_MSG == folder_mode)
            {
                /* delete current screen */
                result = mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
                /* delete child screen */
                mmi_um_ui_ut_del_relative_scrn(&tmp_child_scrn_id);
                return result;
            }
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
			if (0 == num_item )
			{
			    memset(&scrn_cntx->screen_hdlr.hilite_info, 0, sizeof(scrn_cntx->screen_hdlr.hilite_info));
			}
            /* Check if it has the child screen */
            if (mmi_um_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
            {
                #if 1
                /* folder screen is not in the history/active */
                if (!mmi_frm_scrn_is_present(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_um_ui_sh_create(mmi_um_ui_sh_general_folder_get_entry_func(folder_mode), scrn_cntx);
                    /* After entry, the child processing screen will be deleted */
                }
                else
                #endif
                {
                    /* The child should be removed */
                    mmi_um_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
                }
            }
            else
            {
                if (MMI_SCENARIO_STATE_ACTIVE == mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
                {
            #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
                    /* Not during SSP status, update it */
                    if (!gui_screen_smooth_scrolling_moved_by_pen())
                    {
                #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
                        if (MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_um_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm))
                        {
                            mmi_cat_conversation_refresh(
                                    MMI_fixed_list_menu.n_items,
                                    MMI_fixed_list_menu.highlighted_item,
                                    mmi_um_ui_sh_thread_enhance_get_async_item);
                        }
                        else
                #endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
                        {
                            mmi_cat_refresh_asyncdynamic_list(
                                    MMI_fixed_list_menu.n_items, 
                                    MMI_fixed_list_menu.highlighted_item, 
                                    mmi_um_ui_sh_get_async_item,
                                    NULL);
                        }
                    }
            #endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
                }
                else if (!mmi_frm_scrn_is_present(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, MMI_FRM_NODE_ALL_FLAG))
                {
                    /* this screen is not created yet */
                    mmi_um_ui_sh_create(mmi_um_ui_sh_general_folder_get_entry_func(folder_mode), scrn_cntx);
                }
                /***********************************************************
                 * Other cases:
                 *  (a) SSP => during collect msg info => other screen over
                 **********************************************************/
            }
        #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
            /* try to prevent double loading, or black background */
            if ((MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_um_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm)) &&
                (!mmi_um_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id) && 
                (MMI_UM_UI_FSM_EF_UPDATE_DATA == scrn_cntx->fsm.cntx.fsm_entry_folder.state)))
            {
                scrn_cntx->child_scrn_id = mmi_um_ui_if_entry_processing(scrn_id, scrn_cntx->group_id, MMI_FALSE);
                mmi_um_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
            }
        #endif

        #ifdef __MMI_UM_ITERATOR_VIEWER__
            if (NULL != scrn_cntx->ext_app_user_data)
            {
                viewer_info = (mmi_um_iter_viewer_info_struct *)scrn_cntx->ext_app_user_data;
                /* notify app to get the data */
                viewer_info->func_cb(viewer_info->user_data);
                OslMfree(scrn_cntx->ext_app_user_data);
                scrn_cntx->ext_app_user_data = NULL;
            }
        #endif /* __MMI_UM_ITERATOR_VIEWER__ */
            break;
        }
        case MMI_UM_UI_FSM_EF_UPDATE_DATA:
        {
            /* call UI interface to entry a process screen without RSK */
            if (mmi_um_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
            {
            }
            else
            {
                /* Entry processing screen */
            #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
                if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE ||
                #ifdef __MMI_UM_CONVERSATION_BOX__
                    (mmi_um_ui_fsm_ef_get_action(&(scrn_cntx->fsm)) != MMI_UM_UI_ACTION_GET_THRD_INFO &&
                #endif /* __MMI_UM_CONVERSATION_BOX__ */
                    mmi_um_ui_fsm_ef_get_action(&(scrn_cntx->fsm)) != MMI_UM_UI_ACTION_GET_MSG_INFO
                #ifdef __MMI_UM_CONVERSATION_BOX__
                     )
                #endif /* __MMI_UM_CONVERSATION_BOX__ */
                    )
            #endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
                {
                #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
                    if (((MMI_UM_FOLDER_MODE_THREAD_MSG == folder_mode) && 
                    (mmi_um_ui_fsm_ef_get_action(&(scrn_cntx->fsm)) == MMI_UM_UI_ACTION_GET_MSG_CONTENT)))
                    {
                        break;
                    }
                #endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
                    scrn_cntx->child_scrn_id = mmi_um_ui_if_entry_processing(scrn_id, scrn_cntx->group_id, MMI_FALSE);
                    mmi_um_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
                }
            }
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}

#ifdef __MMI_BT_MAP_CLIENT__

void mmi_um_ui_sh_general_folder_tab_entry(mmi_scrn_essential_struct* scr_ess)
{
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx = scr_ess->user_data;
#ifdef __MMI_TELEPHONY_SUPPORT__
    mmi_frm_tab_struct tab_pages_info_array[2] = {0};
#endif
    U16 i;
    U16 num_item;
    srv_um_list_cntx_struct *data_list;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_263_struct *aprc;
    
    MMI_ID lsk_str_id = 0;
    MMI_ID lsk_icon_id = 0;
    MMI_ID csk_icon_id = 0;
    void (*lsk_hdlr)(void) = NULL;     /* Left soft key handler */
    void (*csk_hdlr)(void) = NULL;     /* Center soft key handler */
    
#ifdef __MMI_UM_CONVERSATION_BOX__
    MMI_BOOL result;
    U16 title_len = 0;
    U8 *hint_asc;
    srv_um_msg_info_struct **msg_detail_info;
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    mmi_um_entry_folder_evt_struct entry_folder_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = (mmi_um_ui_aprc_263_struct *)&(aprc_union.folder);
    if (g_aprc_enter_tab)
    {
        g_sh_get_item_scrn_cntx = scrn_cntx;
        g_aprc_enter_tab = MMI_FALSE;
    }
    else
    {
        scrn_cntx = g_sh_get_item_scrn_cntx;
    }

    /* set the number of items */
    num_item = mmi_um_ui_sh_general_folder_get_msg_num(scrn_cntx);
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    /* if data list is NULL, it means FSM does not have the correct message number info. */
    if (NULL != data_list)
    {
        scrn_cntx->screen_hdlr.num_of_item = num_item;
        /* search the specified highlight index based on the highlight msg id and msg type*/
        if (NULL != data_list)
        {
            for (i = 0; i < num_item; i++)
            {
                if (((srv_um_msg_node_struct*)data_list->list)[i].msg_id == scrn_cntx->screen_hdlr.hilite_info.msg_id &&
                    ((srv_um_msg_node_struct*)data_list->list)[i].msg_type == scrn_cntx->screen_hdlr.hilite_info.msg_type)
                {
                    scrn_cntx->screen_hdlr.hilite_info.index = i;
                    break;
                }
            }
        }
        
        /* error handling for highlight */
        if (scrn_cntx->screen_hdlr.hilite_info.index >= num_item &&
            num_item != 0)
        {
            /* highlight to last one */
            scrn_cntx->screen_hdlr.hilite_info.index = num_item - 1;
        }
    }

    /* If there is no message, the lsk string should not display */
    if (0 != scrn_cntx->screen_hdlr.num_of_item)
    {
        lsk_str_id = STR_GLOBAL_VIEW;
        lsk_icon_id = IMG_GLOBAL_OPTIONS;
        csk_icon_id = IMG_GLOBAL_COMMON_CSK;
        lsk_hdlr = mmi_um_ui_sh_general_folder_lsk_hdlr;
        csk_hdlr = mmi_um_ui_sh_general_folder_csk_hdlr;
    }
#if defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
    else if((scrn_cntx->fsm.cntx.fsm_entry_folder.folder_mode == MMI_UM_FOLDER_MODE_DEFAULT) &&
                ((scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type !=  SRV_UM_MSG_BOX_DRAFT) &&
                (scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type !=  SRV_UM_MSG_BOX_ARCHIVE)))
                
    {
        lsk_str_id = STR_UM_FILTER_BY;
        lsk_icon_id = IMG_GLOBAL_OPTIONS;
        csk_icon_id = IMG_GLOBAL_OPTION_CSK;
        lsk_hdlr = mmi_um_ui_sh_general_folder_lsk_hdlr;
        csk_hdlr = mmi_um_ui_sh_general_folder_csk_hdlr;
    }
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */
    g_um_box_struct = scrn_cntx->screen_hdlr.folder_type;
    mmi_um_ui_sh_set_general_cntx(
            &aprc->general_aprc_cntx, 
            scrn_cntx->group_id, 
            scrn_cntx->screen_hdlr.disp_scrn_id, 
            0, 
            mmi_um_ui_ut_get_str_id_by_folder(scrn_cntx->screen_hdlr.folder_type), 
            IMG_UM_ENTRY_SCRN_CAPTION, 
            lsk_str_id, 
            lsk_icon_id, 
            STR_GLOBAL_BACK, 
            IMG_GLOBAL_BACK, 
            csk_icon_id, 
            mmi_um_ui_sh_general_folder_hilite_hdlr, 
            scrn_cntx->screen_hdlr.hilite_info.index, 
            scrn_cntx->screen_hdlr.num_of_item, 
            mmi_um_ui_sh_general_folder_entry, 
            mmi_um_ui_sh_general_folder_exit, 
            NULL, 
            lsk_hdlr, 
            mmi_um_ui_sh_general_folder_rsk_hdlr, 
            csk_hdlr, 
            mmi_um_ui_sh_general_folder_leave_proc);

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_sh_general_folder_set_toolbar_info(
                &(aprc->general_aprc_cntx.tb_hdlr), 
                scrn_cntx->screen_hdlr.folder_type.msg_box_type, 
                mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm)));
    aprc->general_aprc_cntx.intuitive_cmd_cb_func = mmi_um_ui_sh_general_folder_intuitive_cmd_cb;
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    /* Specified context */
#ifdef __MMI_UM_CONVERSATION_BOX__
    /* Check title */
    if (MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm)) && NULL != data_list)
    {
        /* Get the address/phb name */
        result = mmi_um_ui_fsm_ef_get_thrd_info(scrn_cntx->scrn_id, &msg_detail_info, NULL);

        /* This memory should be relase in the exit handler */
        title_len = (MMI_PHB_NAME_LENGTH > SRV_UM_MAX_ADDR_LEN) ? MMI_PHB_NAME_LENGTH : SRV_UM_MAX_ADDR_LEN;
        title_len += MMI_UM_UI_MAX_GET_STRING_LEN;
        aprc->special_title = OslMalloc(title_len * ENCODING_LENGTH);
        memset(aprc->special_title, 0, title_len * ENCODING_LENGTH);
        if(MMI_FALSE != result)
        {
            srv_phb_get_name_by_number((U16 *)msg_detail_info[0]->address, (U16 *)aprc->special_title, MMI_PHB_NAME_LENGTH);
            /* could not find */
            if (0 == mmi_ucs2strlen((CHAR*)aprc->special_title))
            {
                /* copy address */
                memcpy(aprc->special_title, msg_detail_info[0]->address, sizeof(kal_wchar)*msg_detail_info[0]->address_length);
            }
            
            /* no number */
            if (0 == mmi_ucs2strlen((S8*)aprc->special_title))
            {
                /* copy no nubmer indication */
                mmi_ucs2cat((CHAR*)aprc->special_title, (CHAR*)GetString(STR_GLOBAL_NO_NUMBER));
            }
        }
        /* Add the total number of message inside */
        hint_asc = OslMalloc(MMI_UM_UI_MAX_GET_STRING_LEN * ENCODING_LENGTH);
        memset(hint_asc, 0, MMI_UM_UI_MAX_GET_STRING_LEN * ENCODING_LENGTH);
        if (NULL == data_list)
        {
            sprintf((CHAR *)hint_asc, " (%d)", 0);
        }
        else
        {
            sprintf((CHAR *)hint_asc, " (%d)", data_list->msg_number);
        }
        mmi_um_ui_ut_concate_str_with_num((CHAR *)hint_asc, (CHAR *)aprc->special_title);
        OslMfree(hint_asc);
        /* Recorde the memory in the screen user data in order to free in the exit handler */
        scrn_cntx->aprc.user_data = aprc->special_title;

        /* Set folder style */
        aprc->folder_style = MMI_CAT263_DISPLAY_SUBJECT_TIME;
    }
#endif /* __MMI_UM_CONVERSATION_BOX__ */
#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
    if (MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_um_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm))
    {
        aprc->get_item_cb = NULL;
        /* use special one in draw_func */
    }
    else
#endif /* */
    {
        aprc->get_item_cb = mmi_um_ui_sh_get_async_item;
    }
    aprc->get_item_hint_cb = NULL;
    aprc->hilite_notify_cb = mmi_um_ui_sh_general_folder_notify_highlight;

    memcpy(&g_aprc_int_cntx, aprc, sizeof(mmi_um_ui_aprc_263_struct));

#ifdef __MMI_TELEPHONY_SUPPORT__    
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    tab_pages_info_array[0].screen_id = aprc->general_aprc_cntx.scrn_id;
#else
    tab_pages_info_array[0].screen_id = aprc->general_aprc_cntx.scrn_id + 1;
#endif
    tab_pages_info_array[0].tab_entry_func = (FuncPtr)mmi_um_ui_aprc_263_tab_local;
#ifdef __MMI_MAINLCD_240X320__
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(IMG_UM_LOCAL);
    tab_pages_info_array[0].tab_string = 0;
#else
    tab_pages_info_array[0].tab_icon = 0;
    tab_pages_info_array[0].tab_string = (U8*)GetString(STR_UM_LOCAL);
#endif
    tab_pages_info_array[0].user_data = NULL;

    tab_pages_info_array[1].screen_id = aprc->general_aprc_cntx.scrn_id + 2;
    tab_pages_info_array[1].tab_entry_func = mmi_um_ui_aprc_263_tab_BT;
#ifdef __MMI_MAINLCD_240X320__
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(IMG_UM_BT);
    tab_pages_info_array[1].tab_string = 0;
#else
    tab_pages_info_array[1].tab_icon = 0;
    tab_pages_info_array[1].tab_string = (U8*)GetString(STR_UM_BT);
#endif
    tab_pages_info_array[1].user_data = NULL;

   if (g_tab_last_enter == MMI_UM_TAB_PAGE_BT && !g_enter_from_bt &&
       srv_bt_mapc_adp_is_connected(g_sms_active_dev_index))
   {
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_create(
        aprc->general_aprc_cntx.grp_id, 
        aprc->general_aprc_cntx.scrn_id,
        tab_pages_info_array,
        2,
        1,
        scrn_cntx);   
    scrn_cntx->screen_hdlr.disp_scrn_id = aprc->general_aprc_cntx.scrn_id + 2;
    g_um_general_folder_scrn_id = aprc->general_aprc_cntx.scrn_id + 2;
#else
    mmi_frm_scrn_tab_enter(
        aprc->general_aprc_cntx.grp_id, 
        aprc->general_aprc_cntx.scrn_id,
        mmi_um_ui_sh_general_folder_exit, 
        (FuncPtr)mmi_um_ui_sh_general_folder_tab_entry, 
        tab_pages_info_array, 
        2, 
        1);
#endif/*__MMI_TAB_BAR_SUPPORT_TAB_PAGE__*/
    g_tab_curr_first_enter = MMI_UM_TAB_PAGE_BT;
   }
   else
   {

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_create(
        aprc->general_aprc_cntx.grp_id, 
        aprc->general_aprc_cntx.scrn_id,
        tab_pages_info_array,
        2,
        0,
        scrn_cntx); 
    scrn_cntx->screen_hdlr.disp_scrn_id = aprc->general_aprc_cntx.scrn_id;
    g_um_general_folder_scrn_id = aprc->general_aprc_cntx.scrn_id;
#else
    mmi_frm_scrn_tab_enter(
        aprc->general_aprc_cntx.grp_id, 
        aprc->general_aprc_cntx.scrn_id,
        mmi_um_ui_sh_general_folder_exit, 
        (FuncPtr)mmi_um_ui_sh_general_folder_tab_entry, 
        tab_pages_info_array, 
        2, 
        0);
#endif/*__MMI_TAB_BAR_SUPPORT_TAB_PAGE__*/
    g_tab_curr_first_enter = MMI_UM_TAB_PAGE_LOCAL;
   } 
#else
    if (g_enter_from_bt)
    {
        g_enter_from_bt = MMI_FALSE;
        return;
    }
    g_enter_from_bt = MMI_TRUE;
    mmi_um_ui_aprc_263_tab_BT(NULL);
    mmi_frm_scrn_set_leave_proc(
           aprc->general_aprc_cntx.grp_id, 
           aprc->general_aprc_cntx.scrn_id,
           mmi_um_ui_sh_general_folder_leave_proc);
#endif
    
    scrn_cntx->screen_hdlr.is_scrn_displayed = g_category_error_flag;

    /*mmi_frm_scrn_set_user_data(
       aprc->general_aprc_cntx.grp_id, 
       aprc->general_aprc_cntx.scrn_id,
       scrn_cntx);*/

    /*mmi_frm_scrn_set_leave_proc(aprc->general_aprc_cntx.grp_id,       
       aprc->general_aprc_cntx.scrn_id,
       mmi_um_ui_sh_general_folder_leave_proc);*/


    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
    {
        return;
    }
    
    /* After drawing, the child should be removed */
    mmi_um_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
    
    /* Due to the category usage, it should check the screen is displayed or not */
    if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE)
    {
#if (defined(__MMI_BT_MAP_CLIENT__) && defined(__MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__))
        MMI_fixed_list_menu.n_items = num_item;
        MMI_fixed_list_menu.highlighted_item = scrn_cntx->screen_hdlr.hilite_info.index;
#endif
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
    #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
        if (MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_um_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm))
        {
            scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
    }
    
    /* global setting reset */
    if (MMI_TRUE == scrn_cntx->screen_hdlr.is_scrn_displayed)
    {
        /* Send the event out */
        MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_UM_ENTRY_FOLDER);
        entry_folder_evt.is_entry = MMI_TRUE;
        entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
        entry_folder_evt.um_user_data = (void *)scrn_cntx;
        MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
    }   
}

#endif /* __MMI_BT_MAP_CLIENT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_entry
 * DESCRIPTION
 *  Entry folder to display the current screen.
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_item;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_folder_struct *aprc;
    
    MMI_ID lsk_str_id = 0;
    MMI_ID lsk_icon_id = 0;
    MMI_ID csk_icon_id = 0;
    void (*lsk_hdlr)(void) = NULL;     /* Left soft key handler */
    void (*csk_hdlr)(void) = NULL;     /* Center soft key handler */
    
#ifdef __MMI_UM_CONVERSATION_BOX__
    MMI_BOOL result;
    U16 title_len = 0;
    U8 *hint_asc;
    srv_um_msg_info_struct **msg_detail_info;
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    mmi_um_entry_folder_evt_struct entry_folder_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.folder);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* set the number of items */
    num_item = mmi_um_ui_sh_general_folder_get_msg_num(scrn_cntx);
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    /* if data list is NULL, it means FSM does not have the correct message number info. */
    if (NULL != data_list)
    {
        scrn_cntx->screen_hdlr.num_of_item = num_item;
        /* search the specified highlight index based on the highlight msg id and msg type*/
        if (NULL != data_list)
        {
            for (i = 0; i < num_item; i++)
            {
                if (((srv_um_msg_node_struct*)data_list->list)[i].msg_id == scrn_cntx->screen_hdlr.hilite_info.msg_id &&
                    ((srv_um_msg_node_struct*)data_list->list)[i].msg_type == scrn_cntx->screen_hdlr.hilite_info.msg_type)
                {
                    scrn_cntx->screen_hdlr.hilite_info.index = i;
                    break;
                }
            }
        }
        
        /* error handling for highlight */
        if (scrn_cntx->screen_hdlr.hilite_info.index >= num_item &&
            num_item != 0)
        {
            /* highlight to last one */
            scrn_cntx->screen_hdlr.hilite_info.index = num_item - 1;
        }
    }

    /* If there is no message, the lsk string should not display */
    if (0 != scrn_cntx->screen_hdlr.num_of_item)
    {
#ifndef __MMI_SMS_SLIM__
        lsk_str_id = STR_GLOBAL_OPTIONS;
#else
		lsk_str_id = STR_GLOBAL_VIEW;
#endif
        lsk_icon_id = IMG_GLOBAL_OPTIONS;
        csk_icon_id = IMG_GLOBAL_COMMON_CSK;
#ifndef __MMI_SMS_SLIM__
        lsk_hdlr = mmi_um_ui_sh_general_folder_lsk_hdlr;
#else
		lsk_hdlr = mmi_um_ui_sh_general_folder_csk_hdlr;
#endif
        csk_hdlr = mmi_um_ui_sh_general_folder_csk_hdlr;
    }
#if defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
    else if((scrn_cntx->fsm.cntx.fsm_entry_folder.folder_mode == MMI_UM_FOLDER_MODE_DEFAULT) &&
                ((scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type !=  SRV_UM_MSG_BOX_DRAFT) &&
                (scrn_cntx->fsm.cntx.fsm_entry_folder.folder_type.msg_box_type !=  SRV_UM_MSG_BOX_ARCHIVE)))
                
    {
        lsk_str_id = STR_UM_FILTER_BY;
        lsk_icon_id = IMG_GLOBAL_OPTIONS;
        csk_icon_id = IMG_GLOBAL_OPTION_CSK;
        lsk_hdlr = mmi_um_ui_sh_general_folder_lsk_hdlr;
        csk_hdlr = mmi_um_ui_sh_general_folder_csk_hdlr;
    }
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */

#ifdef __MMI_BT_MAP_CLIENT__
    g_um_box_struct = scrn_cntx->screen_hdlr.folder_type;
#endif /* __MMI_BT_MAP_CLIENT__ */

    mmi_um_ui_sh_set_general_cntx(
            &aprc->general_aprc_cntx, 
            scrn_cntx->group_id, 
            scrn_cntx->screen_hdlr.disp_scrn_id, 
            0, 
            mmi_um_ui_ut_get_str_id_by_folder(scrn_cntx->screen_hdlr.folder_type), 
            IMG_UM_ENTRY_SCRN_CAPTION, 
            lsk_str_id, 
            lsk_icon_id, 
            STR_GLOBAL_BACK, 
            IMG_GLOBAL_BACK, 
            csk_icon_id, 
            mmi_um_ui_sh_general_folder_hilite_hdlr, 
            scrn_cntx->screen_hdlr.hilite_info.index, 
            scrn_cntx->screen_hdlr.num_of_item, 
            mmi_um_ui_sh_general_folder_entry, 
            mmi_um_ui_sh_general_folder_exit, 
            NULL, 
            lsk_hdlr, 
            mmi_um_ui_sh_general_folder_rsk_hdlr, 
            csk_hdlr, 
            mmi_um_ui_sh_general_folder_leave_proc);

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_sh_general_folder_set_toolbar_info(
                &(aprc->general_aprc_cntx.tb_hdlr), 
                scrn_cntx->screen_hdlr.folder_type.msg_box_type, 
                mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm)));
    aprc->general_aprc_cntx.intuitive_cmd_cb_func = mmi_um_ui_sh_general_folder_intuitive_cmd_cb;
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    /* Specified context */
#ifdef __MMI_UM_CONVERSATION_BOX__
    /* Check title */
    if (MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm)) && NULL != data_list)
    {
        /* Get the address/phb name */
        result = mmi_um_ui_fsm_ef_get_thrd_info(scrn_cntx->scrn_id, &msg_detail_info, NULL);

        /* This memory should be relase in the exit handler */
        title_len = (MMI_PHB_NAME_LENGTH > SRV_UM_MAX_ADDR_LEN) ? MMI_PHB_NAME_LENGTH : SRV_UM_MAX_ADDR_LEN;
        title_len += MMI_UM_UI_MAX_GET_STRING_LEN;
        aprc->special_title = OslMalloc(title_len * ENCODING_LENGTH);
        memset(aprc->special_title, 0, title_len * ENCODING_LENGTH);
        if(MMI_FALSE != result)
        {
            srv_phb_get_name_by_number((U16 *)msg_detail_info[0]->address, (U16 *)aprc->special_title, MMI_PHB_NAME_LENGTH);
            /* could not find */
            if (0 == mmi_ucs2strlen((CHAR*)aprc->special_title))
            {
                /* copy address */
                memcpy(aprc->special_title, msg_detail_info[0]->address, sizeof(kal_wchar)*msg_detail_info[0]->address_length);
            }
            
            /* no number */
            if (0 == mmi_ucs2strlen((S8*)aprc->special_title))
            {
                /* copy no nubmer indication */
                mmi_ucs2cat((CHAR*)aprc->special_title, (CHAR*)GetString(STR_GLOBAL_NO_NUMBER));
            }
        }
        /* Add the total number of message inside */
        hint_asc = OslMalloc(MMI_UM_UI_MAX_GET_STRING_LEN * ENCODING_LENGTH);
        memset(hint_asc, 0, MMI_UM_UI_MAX_GET_STRING_LEN * ENCODING_LENGTH);
        if (NULL == data_list)
        {
            sprintf((CHAR *)hint_asc, " (%d)", 0);
        }
        else
        {
            sprintf((CHAR *)hint_asc, " (%d)", data_list->msg_number);
        }
        mmi_um_ui_ut_concate_str_with_num((CHAR *)hint_asc, (CHAR *)aprc->special_title);
        OslMfree(hint_asc);
        /* Recorde the memory in the screen user data in order to free in the exit handler */
        scrn_cntx->aprc.user_data = aprc->special_title;

        /* Set folder style */
        aprc->folder_style = MMI_CAT263_DISPLAY_SUBJECT_TIME;
    }
#endif /* __MMI_UM_CONVERSATION_BOX__ */
#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
    if (MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_um_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm))
    {
        aprc->get_item_cb = NULL;
        /* use special one in draw_func */
    }
    else
#endif /* */
    {
        aprc->get_item_cb = mmi_um_ui_sh_get_async_item;
    }
    aprc->get_item_hint_cb = NULL;
    aprc->hilite_notify_cb = mmi_um_ui_sh_general_folder_notify_highlight;
    scrn_cntx->screen_hdlr.is_scrn_displayed = scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);

    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
    {
        return;
    }
    
    /* After drawing, the child should be removed */
    mmi_um_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
    
    /* Due to the category usage, it should check the screen is displayed or not */
    if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE)
    {
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
    #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
        if (MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_um_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm))
        {
            scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
        }
     #endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
    }
    
    /* global setting reset */
    if (MMI_TRUE == scrn_cntx->screen_hdlr.is_scrn_displayed)
    {
        /* Send the event out */
        MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_UM_ENTRY_FOLDER);
        entry_folder_evt.is_entry = MMI_TRUE;
        entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
        entry_folder_evt.um_user_data = (void *)scrn_cntx;
        MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_exit
 * DESCRIPTION
 *  Exit folder screen.
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_exit(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_entry_folder_evt_struct entry_folder_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

#ifdef __MMI_UM_CONVERSATION_BOX__
    if (NULL != scrn_cntx->aprc.user_data)
    {
        OslMfree(scrn_cntx->aprc.user_data);
        scrn_cntx->aprc.user_data = NULL;
    }
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;

    /* Send the event out */
    MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_UM_ENTRY_FOLDER);
    entry_folder_evt.is_entry = MMI_FALSE;
    entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
    entry_folder_evt.um_user_data = (void *)scrn_cntx;
    MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_destroy
 * DESCRIPTION
 *  Destory folder screen. In this function, it should clean the screen
 *  context from central controller.
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  ?
 *****************************************************************************/
U8 mmi_um_ui_sh_general_folder_destroy(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clean the cache memory */
    srv_um_clear_msg_info_cache();
    result = mmi_um_ui_sh_destroy(arg);

    return result;
}

#ifdef __MMI_BT_MAP_CLIENT__
extern srv_sms_btmapc_bt_enum g_sms_active_dev_index;	   /* Bt index ID */
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_leave_proc
 * DESCRIPTION
 *  Screen proc handler. In this function, it should handle the deinit event.
 *
 * PARAMETERS
 *  evt             [IN]: Screen event from FW
 *  
 * RETURNS
 *  handler result
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_general_folder_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_RET_OK;

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
        #ifdef __GENERAL_TTS__
            mmi_um_ui_tts_stop();
        #endif
            mmi_um_ui_sh_general_folder_destroy(evt->user_data);
#ifdef __MMI_BT_MAP_CLIENT__
        g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered = SRV_SMS_BTMAPC_BOX_NONE;
#endif
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_lsk_hdlr
 * DESCRIPTION
 *  General left soft key handler for general folder.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_lsk_hdlr(void)
{
#ifdef __MMI_BT_MAP_CLIENT__
    MMI_ID opt_grp_id;
    MMI_ID opt_menu_id;
    MMI_MENU_ID msg_menu_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;
    mmi_um_opt_para_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    memset(&para, 0, sizeof(mmi_sms_um_opt_para_struct));
    para.msg_id = scrn_cntx->screen_hdlr.hilite_info.msg_id;
    para.parent_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    para.display_flag = MMI_TRUE;
    para.user_data = (void *)scrn_cntx;  
  #ifdef __MMI_TELEPHONY_SUPPORT__
    mmi_sms_um_set_sms_context(scrn_cntx->screen_hdlr.hilite_info.msg_id);
    mmi_sms_group_entry(para.parent_grp_id);
    mmi_sms_box_list_opt_pre_view();
  #endif /* __MMI_TELEPHONY_SUPPORT__ */
#else
#ifndef __MMI_SMS_SLIM__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID opt_grp_id;
    MMI_ID opt_menu_id;
    MMI_MENU_ID msg_menu_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);

    /* If during updating data, lsk should not activate any action */
    if (MMI_UM_UI_FSM_EF_UPDATE_DATA == mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)))
    {
        return;
    }

    /* create group */
    opt_grp_id = mmi_frm_group_create(
                            scrn_cntx->group_id, 
                            GRP_ID_AUTO_GEN, 
                            mmi_um_ui_sh_general_folder_opt_proc, 
                            (void*) scrn_cntx);
    mmi_frm_group_enter(opt_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

#if defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
    if (0 == scrn_cntx->screen_hdlr.num_of_item)
    {
        msg_menu_id = MENU_ID_UM_FILTER_BY_OPT;
    }
    else
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */
    {
        /* create menu cui */
        msg_menu_id = mmi_um_ui_adp_get_opt_menu_id(((srv_um_msg_node_struct*)data_list->list)[scrn_cntx->screen_hdlr.hilite_info.index].msg_type, 
                                                ((srv_um_msg_node_struct*)data_list->list)[scrn_cntx->screen_hdlr.hilite_info.index].msg_id);
        MMI_ASSERT(msg_menu_id != 0);
    }
    opt_menu_id = cui_menu_create(
                            opt_grp_id, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_OPTION, 
                            msg_menu_id, 
                            MMI_TRUE, 
                            NULL);
    /* Set default string/icon */
    cui_menu_set_default_title(
            opt_menu_id, 
            (WCHAR*)GetString(STR_GLOBAL_OPTIONS), 
            (UI_image_type)GetImage(IMG_UM_ENTRY_SCRN_CAPTION));
    cui_menu_run(opt_menu_id);
    /* set child group id */
    scrn_cntx->child_group_id = opt_menu_id;
    if (0 != scrn_cntx->screen_hdlr.num_of_item)
    {
        /* Reset the data list */
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);
    }
    /* Reset cache in the Service level */
    srv_um_clear_msg_info_cache();
#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_rsk_hdlr
 * DESCRIPTION
 *  General right soft key handler for general folder.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_rsk_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_csk_hdlr
 * DESCRIPTION
 *  General center soft key handler for general folder.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;
    U16 highlight_idx;
    srv_um_msg_box_enum hilite_msg_box_type;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;
    mmi_um_entry_msg_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    if (NULL == data_list)
    {
        mmi_um_current_not_avaiable_popup();
        return;
    }

    /* If during updating data, csk should not activate any action */
    if (MMI_UM_UI_FSM_EF_UPDATE_DATA == mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)))
    {
        return;
    }

#if defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
    if((scrn_cntx->fsm.cntx.fsm_entry_folder.folder_mode == MMI_UM_FOLDER_MODE_DEFAULT) &&
        (0 == scrn_cntx->screen_hdlr.num_of_item))
    {
        mmi_um_ui_sh_general_folder_lsk_hdlr();
        return;
    }
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */
    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;

    memset(&para, 0, sizeof(mmi_um_entry_msg_struct));
    para.key_code = MMI_UM_UI_ENTRY_KEY_CSK;
    para.parent_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    para.msg_id = ((srv_um_msg_node_struct *)data_list->list)[highlight_idx].msg_id;
    para.user_data = (void *)scrn_cntx;
#ifndef __MMI_SMS_SLIM__
    hilite_msg_box_type = mmi_um_ui_adp_get_msg_box(((srv_um_msg_node_struct *)data_list->list)[highlight_idx].msg_type, 
                                                    ((srv_um_msg_node_struct *)data_list->list)[highlight_idx].msg_id);
    if ((SRV_UM_MSG_BOX_UNSENT == hilite_msg_box_type)
    #ifdef __MMI_MMS_IN_UM__
        ||( MENU_ID_UMMS_INBOX_OPTIONS_NOTIFICATION == mmi_um_ui_adp_get_opt_menu_id(((srv_um_msg_node_struct *)data_list->list)[highlight_idx].msg_type, 
                                                    ((srv_um_msg_node_struct *)data_list->list)[highlight_idx].msg_id))
    #endif    
    #ifdef __MMI_UM_REPORT_BOX__
        || (SRV_UM_MSG_BOX_REPORT == hilite_msg_box_type)
    #endif /* __MMI_UM_REPORT_BOX__ */
    #ifdef __MMI_TELEPHONY_SUPPORT__
        || (SRV_SMS_STATUS_UNSUPPORTED == srv_sms_get_msg_status(((srv_um_msg_node_struct *)data_list->list)[highlight_idx].msg_id))
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
    )
    {
        /* outbox message should map to lsk handler */
        mmi_um_ui_sh_general_folder_lsk_hdlr();
    }
    else
    {
#endif
        grp_id = mmi_um_ui_adp_entry_msg(
                        ((srv_um_msg_node_struct *)data_list->list)[highlight_idx].msg_type,
                        &para);

        if (GRP_ID_INVALID != grp_id)
        {
            /* Reset the data list */
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);

            /* Reset cache in the Service level */
            srv_um_clear_msg_info_cache();
        }
#ifndef __MMI_SMS_SLIM__
    }
#endif
}


#ifdef __MMI_UM_DIAL_FROM_FOLDER__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_send_key_pre_confirm
 * DESCRIPTION
 *  Pre-confirm for dialing sender from inbox by using send key(s)
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_send_key_pre_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 highlight_idx;
    U8 popup_str[(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH];
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    srv_um_msg_info_struct **msg_detail_info;
    srv_um_list_cntx_struct *data_list;
    U16 phb_name[MMI_PHB_NAME_LENGTH * ENCODING_LENGTH];
    mmi_confirm_property_struct confirm_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* If during updating data, send key should not activate any action */
    if (MMI_UM_UI_FSM_EF_UPDATE_DATA == mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)))
    {
        return;
    }

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    result = fsm->get_msg_info(scrn_cntx->scrn_id, highlight_idx, 1, &msg_detail_info, NULL);
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));

    /* it should get the detail information */
    MMI_ASSERT(result != MMI_FALSE);
    MMI_ASSERT(data_list != NULL);

    /* check if SMS or MMS */
    if (SRV_UM_MSG_SMS == ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type ||
        SRV_UM_MSG_MMS == ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type ||
        SRV_UM_MSG_UT == ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type)
    {
        /* check if phone number & there is a phone number */
        if (SRV_UM_ADDR_PHONE_NUMBER == msg_detail_info[0]->address_type &&
            msg_detail_info[0]->address_length > 0)
        {
            /* concate the popup string */
            mmi_ucs2cpy((CHAR *)popup_str, (CHAR *)get_string(STR_GLOBAL_DIAL));
            mmi_ucs2cat((CHAR *)popup_str, (CHAR *)GUI_NEWLINE_STRING);

            /* concate the number / contact name */
            memset(phb_name, 0, sizeof(phb_name));
            /* Get the name by phb API. If not found or cause error, PHB will help to copy the number to the buffer */
            srv_phb_get_name_by_number((U16 *)msg_detail_info[0]->address, phb_name, MMI_PHB_NAME_LENGTH);

            /* Could not find */
            if (0 == mmi_ucs2strlen((CHAR*)phb_name))
            {
                /* use the longest name, the address length may be larger than the phb name length */
                mmi_ucs2ncat((CHAR *)popup_str, (CHAR *)msg_detail_info[0]->address, msg_detail_info[0]->address_length);
            }
            else
            {
                mmi_ucs2ncat((CHAR *)popup_str, (CHAR *)phb_name, mmi_ucs2strlen((CHAR *)phb_name));
            }
            /* concate the question mark "?" */
            mmi_ucs2cat((CHAR *)popup_str, (CHAR *)get_string(STR_UM_QUESTION_MARK));
            /* end of string */
            /* Display confirm */
            memset(&confirm_param, 0, sizeof(mmi_confirm_property_struct));
            mmi_confirm_property_init(&confirm_param, CNFM_TYPE_YESNO);
            mmi_um_ui_sh_set_confirm_param(&confirm_param, scrn_cntx, MMI_UM_UI_SH_CF_FOLDER_SEND_KEY);
            scrn_cntx->screen_hdlr.cf_grp_id = mmi_confirm_display(
                                                        (WCHAR *) popup_str, 
                                                        MMI_EVENT_QUERY, 
                                                        &confirm_param);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_send_key_confirm_yes_hdlr
 * DESCRIPTION
 *  General center send key make a call handler for general folder.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_general_folder_send_key_confirm_yes_hdlr(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 highlight_idx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    srv_um_msg_info_struct **msg_detail_info;
    srv_um_list_cntx_struct *data_list;
    mmi_ucm_make_call_para_struct *make_call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    result = fsm->get_msg_info(scrn_cntx->scrn_id, highlight_idx, 1, &msg_detail_info, NULL);
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));

    /* it should get the detail information */
    MMI_ASSERT(result != MMI_FALSE);
    MMI_ASSERT(data_list != NULL);

    /* Make a call */
    make_call_para = OslMalloc(sizeof(mmi_ucm_make_call_para_struct));

    mmi_ucm_init_call_para_for_sendkey(make_call_para);
    make_call_para->ucs2_num_uri = (U16 *) msg_detail_info[0]->address;
    mmi_ucm_call_launch(0, make_call_para);

    OslMfree(make_call_para);
    make_call_para = NULL;

    return MMI_RET_OK;
}
#endif /* __MMI_UM_DIAL_FROM_FOLDER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_get_msg_num
 * DESCRIPTION
 *  Get the number of data function. It should call finite state machine 
 *  api to get the information.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 *  
 * RETURNS
 *  The number of items
 *****************************************************************************/
U16 mmi_um_ui_sh_general_folder_get_msg_num(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_of_item;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_item = 0;

    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    num_of_item = fsm->get_msg_num(scrn_cntx->scrn_id);

    return num_of_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_hilite_hdlr
 * DESCRIPTION
 *  The general highlight folder function.
 *
 * PARAMETERS
 *  index               [IN]: the highlight index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined( __MMI_UM_REPORT_BOX__ ) || defined (__GENERAL_TTS__)
    srv_um_msg_box_enum hilite_msg_box_type;
#endif /* defined( __MMI_UM_REPORT_BOX__ ) || defined (__GENERAL_TTS__) */
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    MMI_BOOL result;
    srv_um_msg_info_struct **msg_detail_info;
    srv_um_list_cntx_struct *data_list;
#ifdef __MMI_FTE_SUPPORT__
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_folder_struct *aprc;
    mmi_um_ui_folder_mode_enum folder_mode;
#endif /* __MMI_FTE_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    result = fsm->get_msg_info(scrn_cntx->scrn_id, (U16) index, 1, &msg_detail_info, NULL);
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));

    /* Tricky for category bugs */
    if (result == MMI_FALSE)
    {
        return;
    }
    /* Tricky for category bugs */
    MMI_ASSERT(result != MMI_FALSE);
    MMI_ASSERT(data_list != NULL);

    /* Set highlight message id & type */
    scrn_cntx->screen_hdlr.hilite_info.index = index;
    scrn_cntx->screen_hdlr.hilite_info.msg_id = ((srv_um_msg_node_struct*)data_list->list)[index].msg_id;
    scrn_cntx->screen_hdlr.hilite_info.msg_type = ((srv_um_msg_node_struct*)data_list->list)[index].msg_type;
#if defined( __MMI_UM_REPORT_BOX__ ) || defined (__GENERAL_TTS__)
    /* change CSK icon */
    hilite_msg_box_type = mmi_um_ui_adp_get_msg_box(((srv_um_msg_node_struct *)data_list->list)[index].msg_type, 
                                               ((srv_um_msg_node_struct *)data_list->list)[index].msg_id);
#endif   

#ifdef __MMI_UM_REPORT_BOX__
    if (SRV_UM_MSG_BOX_REPORT == hilite_msg_box_type)
    {
        /* outbox message should map to option csk icon */
        ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
    }
    else
#endif /* __MMI_UM_REPORT_BOX__ */
    {
        ChangeCenterSoftkey(0, msg_detail_info[0]->csk_icon_id);
#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __MMI_SMS_SLIM__
		mmi_sms_set_hilite_msg_addr((CHAR*)(*(*msg_detail_info)).address);
#endif
#endif
    }

#ifdef __MMI_MMS_2__ 
#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __MMI_SMS_SLIM__
	if(scrn_cntx->screen_hdlr.hilite_info.msg_type == SRV_UM_MSG_MMS &&
		srv_mms_is_mms_notification(scrn_cntx->screen_hdlr.hilite_info.msg_id))
	{
		ChangeLeftSoftkeyExt(STR_GLOBAL_DOWNLOAD);
	}
	else
	{
		ChangeLeftSoftkeyExt(STR_GLOBAL_VIEW);
	}
#endif
#endif
#endif

#ifdef __MMI_ICON_BAR_SUPPORT__
    /* Check each toolbar icon status */
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.folder);
    folder_mode = mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm));
    /* set status */
    mmi_um_ui_sh_general_folder_set_toolbar_status(
                        &(aprc->general_aprc_cntx.tb_hdlr), 
                        scrn_cntx->screen_hdlr.hilite_info.msg_type, 
                        scrn_cntx->screen_hdlr.hilite_info.msg_id, 
                        scrn_cntx->screen_hdlr.folder_type.msg_box_type, 
                        folder_mode);
    scrn_cntx->aprc.redraw_func(&aprc_union, scrn_cntx->aprc.st_type, MMI_UM_UI_APRC_REDRAW_TB_STATUS);
#endif /* __MMI_ICON_BAR_SUPPORT__ */

#ifdef  __GENERAL_TTS__
    if ( (hilite_msg_box_type == SRV_UM_MSG_BOX_INBOX) && 
         (scrn_cntx->screen_hdlr.hilite_info.msg_type == SRV_UM_MSG_SMS) &&
         mmi_tts_setting_is_sms_tts_enabled() )
    {
        /* when SMS is hilited in Inbox*/
        if (msg_to_tts != scrn_cntx->screen_hdlr.hilite_info.msg_id)
        /* only for the first time when then message is highlighted,
           if reentry, will not play tts again*/
        {
            mmi_um_ui_tts_stop();
            msg_to_tts = scrn_cntx->screen_hdlr.hilite_info.msg_id;
            StartTimer(MESSAGES_TTS_COUNT_DOWN_TIMER_ID, MMI_UM_UI_SCRN_TTS_TIMER_COUNT_DOWN_INTERVAL, mmi_um_ui_sh_tts_time_out_callback);
        }
    }
    else if((scrn_cntx->screen_hdlr.hilite_info.msg_type != SRV_UM_MSG_SMS))
    /* if highlighed message is not SMS */
    {
        mmi_um_ui_tts_stop();
    }
#endif /* __GENERAL_TTS__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_notify_highlight
 * DESCRIPTION
 *  The general notify highlight index function.
 *
 * PARAMETERS
 *  index               [IN]: the highlight index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_notify_highlight(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    
    if (data_list != NULL)
    {
        /* Set highlight message id & type */
        scrn_cntx->screen_hdlr.hilite_info.index = index;
        scrn_cntx->screen_hdlr.hilite_info.msg_id = ((srv_um_msg_node_struct*)data_list->list)[index].msg_id;
        scrn_cntx->screen_hdlr.hilite_info.msg_type = ((srv_um_msg_node_struct*)data_list->list)[index].msg_type;
    }
}

#ifndef __MMI_SMS_SLIM__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_opt_proc
 * DESCRIPTION
 *  The proc function of option menu for general folder
 *
 * PARAMETERS
 *  evt                     [IN]: event
 *  
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_general_folder_opt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    cui_menu_event_struct *menu_evt;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
#ifdef __GENERAL_TTS__
    static MMI_BOOL is_rsk_close = MMI_TRUE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    ret = MMI_RET_OK;
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            ret = mmi_um_ui_sh_general_folder_opt_list_entry_hdlr(evt);
        #ifdef __GENERAL_TTS__
            is_rsk_close = MMI_TRUE;
        #endif
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
        #ifdef __GENERAL_TTS__
            is_rsk_close = MMI_FALSE;
        #endif /* __GENERAL_TTS__ */
            ret = mmi_um_ui_sh_general_folder_opt_item_select_hdlr(evt);
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            if ( SRV_UM_MSG_NONE != scrn_cntx->screen_hdlr.hilite_info.msg_type)
            {
                mmi_um_opt_para_struct para;

                memset(&para, 0, sizeof(mmi_um_opt_para_struct));
                para.msg_id = scrn_cntx->screen_hdlr.hilite_info.msg_id;
                para.parent_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
                para.display_flag = MMI_TRUE;
                para.user_data = (void *)scrn_cntx;
                ret = mmi_um_ui_adp_opt_cb(evt, 
                                           scrn_cntx->screen_hdlr.hilite_info.msg_type, 
                                           &para);
                }
            scrn_cntx->child_group_id = 0;
        #ifdef __GENERAL_TTS__
            if (!is_rsk_close)
            {
                StopTimer(MESSAGES_TTS_COUNT_DOWN_TIMER_ID);
                mmi_sms_tts_stop_play();
            }
        #endif
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}
#else
mmi_ret mmi_um_ui_sh_general_folder_opt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    cui_menu_event_struct *menu_evt;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
#ifdef __GENERAL_TTS__
    static MMI_BOOL is_rsk_close = MMI_TRUE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    ret = MMI_RET_OK;
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
        #ifdef __GENERAL_TTS__
            is_rsk_close = MMI_FALSE;
        #endif /* __GENERAL_TTS__ */
            ret = mmi_um_ui_sh_general_folder_opt_item_select_hdlr(evt);
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            if ( SRV_UM_MSG_NONE != scrn_cntx->screen_hdlr.hilite_info.msg_type)
            {
                mmi_um_opt_para_struct para;

                memset(&para, 0, sizeof(mmi_um_opt_para_struct));
                para.msg_id = scrn_cntx->screen_hdlr.hilite_info.msg_id;
                para.parent_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
                para.display_flag = MMI_TRUE;
                para.user_data = (void *)scrn_cntx;
              }
            scrn_cntx->child_group_id = 0;
        #ifdef __GENERAL_TTS__
            if (!is_rsk_close)
            {
                StopTimer(MESSAGES_TTS_COUNT_DOWN_TIMER_ID);
                mmi_sms_tts_stop_play();
            }
        #endif
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
        {
            break;
        }
    }
    return ret;
}
#endif
#ifndef __MMI_SMS_SLIM__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_opt_list_entry_hdlr
 * DESCRIPTION
 *  Handling the list entry event sent from menu cui.
 *
 * PARAMETERS
 *  evt                     [IN]: event
 *  
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_general_folder_opt_list_entry_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    ret = MMI_RET_OK;
    switch (menu_evt->parent_menu_id)
    {
    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        case MENU_ID_UM_SORT_BY_OPT:
        {
            MMI_MENU_ID disable_menu_id;
        #ifdef __MMI_UM_CONVERSATION_BOX__
            mmi_um_ui_folder_mode_enum folder_mode;
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
            srv_um_list_filter_struct *filter;
            MMI_ID_TYPE address_str;

            /* set item string */
            if ((scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_UNSENT) == SRV_UM_MSG_BOX_UNSENT ||
                (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_SENT)   == SRV_UM_MSG_BOX_SENT ||
                (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_DRAFT)  == SRV_UM_MSG_BOX_DRAFT)
            {
                address_str = STR_UM_SORT_BY_RECIPIENT_NAME;
            }
            else if ((scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_ARCHIVE) == SRV_UM_MSG_BOX_ARCHIVE ||
                     (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_SIM)     == SRV_UM_MSG_BOX_SIM)
            {
                address_str = STR_UM_SORT_BY_SENDER_RECIPIENT_NAME;
            }
            else
            {
                address_str = STR_UM_SORT_BY_SENDER_NAME;
            }
            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_UM_SORT_BY_RECIPIENT, (WCHAR *)get_string(address_str));

            /* Set title */
            cui_menu_set_currlist_title(
                    menu_evt->sender_id, 
                    (WCHAR *)get_string(STR_GLOBAL_SORT_BY), 
                    (UI_image_type)get_image(GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID)));
            /* Set all unhidden */
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_SORT_BY_TIME, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_SORT_BY_RECIPIENT, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_SORT_BY_SUBJECT, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_SORT_BY_READ_STATUS, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_SORT_BY_SIZE, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_SORT_BY_TYPE, MMI_FALSE);

            filter = mmi_um_ui_fsm_ef_get_list_filter_type(&(scrn_cntx->fsm));
            disable_menu_id = (MMI_MENU_ID)mmi_um_ui_ut_get_menu_id_by_filter_type(filter->idx_type);

            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

            /* disable the current filter type */
            cui_menu_set_currlist_highlighted_id(
                            menu_evt->sender_id, 
                            disable_menu_id);

            disable_menu_id = (MMI_MENU_ID)mmi_um_ui_ut_get_menu_id_by_filter_type(SRV_UM_LIST_IDX_READ_STATUS);
            if ((scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_UNSENT) == SRV_UM_MSG_BOX_UNSENT ||
                (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_SENT) == SRV_UM_MSG_BOX_SENT ||
                (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_DRAFT) == SRV_UM_MSG_BOX_DRAFT ||
            #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_ARCHIVE) == SRV_UM_MSG_BOX_ARCHIVE ||
            #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
                MMI_FALSE)
            {
                /* disable the read status type */
                cui_menu_set_item_hidden(
                                menu_evt->sender_id, 
                                disable_menu_id, 
                                MMI_TRUE);
            }
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            disable_menu_id = (MMI_MENU_ID)mmi_um_ui_ut_get_menu_id_by_filter_type(SRV_UM_LIST_IDX_MSG_TYPE);
            if ((scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_UNSENT) == SRV_UM_MSG_BOX_SIM)
            {
                /* disable the message type */
                cui_menu_set_item_hidden(
                                menu_evt->sender_id, 
                                disable_menu_id, 
                                MMI_TRUE);
            }
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        #ifndef __UM_FOLDER__ /* UM standalone : sms only */
            disable_menu_id = (MMI_MENU_ID)mmi_um_ui_ut_get_menu_id_by_filter_type(SRV_UM_LIST_IDX_MSG_TYPE);
            /* disable the message type */
            cui_menu_set_item_hidden(
                            menu_evt->sender_id, 
                            disable_menu_id, 
                            MMI_TRUE);
        #endif /* __UM_FOLDER__ */
        #ifdef __MMI_UM_CONVERSATION_BOX__
            /* In thread message, diable the address sorting type */
            folder_mode = mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm));
            if (MMI_UM_FOLDER_MODE_THREAD_MSG == folder_mode)
            {
                disable_menu_id = (MMI_MENU_ID)mmi_um_ui_ut_get_menu_id_by_filter_type(SRV_UM_LIST_IDX_ADDRESS);
                /* disable the address type */
                cui_menu_set_item_hidden(
                                menu_evt->sender_id, 
                                disable_menu_id, 
                                MMI_TRUE);
            }
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
    
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MENU_ID_UM_MS_OPT:
        {
            
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            /* Archive */
            /* if current folder is Outbox/Archive/SIM message, "move to archive" should be hided */
            if ((scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_UNSENT) == SRV_UM_MSG_BOX_UNSENT
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                || (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_ARCHIVE) == SRV_UM_MSG_BOX_ARCHIVE
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                || (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_SIM) == SRV_UM_MSG_BOX_SIM
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    #ifdef __MMI_UM_REPORT_BOX__
                || (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_REPORT) == SRV_UM_MSG_BOX_REPORT
    #endif /* __MMI_UM_REPORT_BOX__ */
                )
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_MOVE_TO_ARCHIVE_PRE, 
                                         MMI_TRUE);
            }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

                /* Move/Copy to SIM/Phone */
#ifndef __UM_FOLDER__
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                /* SIMBox open, the menu item should be hided */
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_MOVE_TO_SIM_PRE, 
                                         MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_COPY_TO_SIM_PRE, 
                                         MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE_PRE, 
                                         MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_COPY_TO_PHONE_PRE, 
                                         MMI_TRUE);
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                if (SRV_UM_MSG_BOX_ARCHIVE == (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_ARCHIVE))
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, 
                                             MENU_ID_UM_MULTI_OP_MOVE_TO_SIM_PRE, 
                                             MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, 
                                             MENU_ID_UM_MULTI_OP_COPY_TO_SIM_PRE, 
                                             MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, 
                                             MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE_PRE, 
                                             MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, 
                                             MENU_ID_UM_MULTI_OP_COPY_TO_PHONE_PRE, 
                                             MMI_TRUE);
                }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#endif /* __UM_FOLDER__ */
            }
        break;
#endif
        default:
        {
            mmi_um_opt_para_struct para;

            
            if (SRV_UM_MSG_NONE != scrn_cntx->screen_hdlr.hilite_info.msg_type)
            {
                memset(&para, 0, sizeof(mmi_um_opt_para_struct));
                para.msg_id = scrn_cntx->screen_hdlr.hilite_info.msg_id;
                para.parent_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
                para.display_flag = MMI_TRUE;
                para.user_data = (void *)scrn_cntx;
                ret = mmi_um_ui_adp_opt_cb(evt, 
                                           scrn_cntx->screen_hdlr.hilite_info.msg_type, 
                                           &para);
            }

	#if defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
            if ((SRV_UM_MSG_BOX_ARCHIVE == scrn_cntx->screen_hdlr.folder_type.msg_box_type) ||  
				(SRV_UM_MSG_BOX_DRAFT== scrn_cntx->screen_hdlr.folder_type.msg_box_type))
        	{
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                         MENU_ID_UM_FILTER_BY_OPT, 
                         MMI_TRUE);
        	}

            if (MENU_ID_UM_FILTER_BY_OPT == menu_evt->parent_menu_id)
            {
                
                S32 i = 0;
                MMI_ID menu_id[]= {  MENU_ID_UM_FILTER_BY_OPT_SIM1,
                                    MENU_ID_UM_FILTER_BY_OPT_SIM2,
                    #if (MMI_MAX_SIM_NUM >= 3)
                                    MENU_ID_UM_FILTER_BY_OPT_SIM3,
                    #endif
                    #if (MMI_MAX_SIM_NUM >= 4)
                                    MENU_ID_UM_FILTER_BY_OPT_SIM4,
                    #endif
                                    MENU_ID_UM_FILTER_BY_OPT_ALL,
                                    };
                cui_menu_set_currlist_title(
                        menu_evt->sender_id, 
                        (WCHAR *)get_string(STR_UM_FILTER_BY), 
                        (UI_image_type)get_image(GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID)));
                for(; i <= MMI_MAX_SIM_NUM; i++)
                {
                    if (mmi_um_ui_ut_get_sim_id_by_menu_id(menu_id[i]) == (scrn_cntx->screen_hdlr.folder_type.sim_id))
                    {
                        break;
                    }
                }
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                
                /* disable the current filter type */
                cui_menu_set_currlist_highlighted_id(
                                menu_evt->sender_id, 
                                menu_id[i]);
            }
        #endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */

            #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            {
                MMI_BOOL is_need_single_delete = MMI_FALSE;
				MMI_BOOL is_need_single_delete_temp =MMI_FALSE;
                {
                    if (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_UNSENT ||
                        scrn_cntx->screen_hdlr.folder_type.msg_box_type &  SRV_UM_MSG_BOX_DRAFT ||
                        scrn_cntx->screen_hdlr.folder_type.msg_box_type &  SRV_UM_MSG_BOX_ARCHIVE ||
                        scrn_cntx->screen_hdlr.folder_type.msg_box_type &  SRV_UM_MSG_BOX_SIM)
                    {
                        is_need_single_delete = MMI_TRUE;
                    }
                #ifndef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                    is_need_single_delete = MMI_TRUE;
                #endif
                }
                    cui_menu_set_item_hidden(menu_evt->sender_id, 
                                             MENU_ID_UM_MS_OPT, 
                                             is_need_single_delete);
					if(is_need_single_delete)
						is_need_single_delete_temp=MMI_FALSE;
					else
						is_need_single_delete_temp=MMI_TRUE;
                    cui_menu_set_item_hidden(menu_evt->sender_id, 
                                             (MMI_MENU_ID)MENU_ID_UM_MS_DELETE_OPT, 
                                             is_need_single_delete_temp);
            }
            #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */

            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_opt_item_select_hdlr
 * DESCRIPTION
 *  Handling the item select event sent from menu cui.
 *
 * PARAMETERS
 *  evt                     [IN]: event
 *  
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_general_folder_opt_item_select_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    cui_menu_event_struct *menu_evt;
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    ret = MMI_RET_OK;
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_UM_DEL_ALL_OPT:
#ifdef __MMI_SMS_SLIM__
		case MENU_ID_UM_DELETE_MSG_FOLDER_INBOX:
		case MENU_ID_UM_DELETE_MSG_FOLDER_DRAFT:
		case MENU_ID_UM_DELETE_MSG_FOLDER_UNSENT:
		case MENU_ID_UM_DELETE_MSG_FOLDER_SENT:
#endif
        {
            U16 confirm_msg_str_id;
        #ifdef __MMI_UM_CONVERSATION_BOX__
            mmi_um_ui_folder_mode_enum folder_mode;
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
            mmi_confirm_property_struct confirm_param;

        /*----------------------------------------------------------------*/
        /* Add code here to detect USB mode when try to delete            */
        /* archive box messages. So the behavior between UM and message   */
        /* App will be uinified and MAUI_02452811 will be solved.        */
        /*----------------------------------------------------------------*/
        #if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
            if ((SRV_UM_MSG_BOX_ARCHIVE == (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_ARCHIVE)) &&
                 srv_usb_is_in_mass_storage_mode())
            {
                mmi_usb_app_unavailable_popup(0);
                break;
            }
        #endif
            /* Confirm first */
        #ifdef __MMI_UM_CONVERSATION_BOX__
            folder_mode = mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm));
            if (MMI_UM_FOLDER_MODE_THREAD_MSG == folder_mode)
            {
                confirm_msg_str_id = STR_UM_DELETE_ALL_MSG_IN_CONTACT;
            }
            else
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
            {
                confirm_msg_str_id = STR_GLOBAL_DELETE_ALL_ASK;
            }
#ifdef __MMI_SMS_SLIM__
			/***** As there is no FSM is enabled need to set message 
			box type explicitly at scrn cntx variable as launch from external cui  ******/
			scrn_cntx->screen_hdlr.folder_type.msg_box_type = 1 << (menu_evt->highlighted_menu_id - MENU_ID_UM_DELETE_MSG_FOLDER_INBOX);
#endif
            memset(&confirm_param, 0, sizeof(mmi_confirm_property_struct));
            mmi_confirm_property_init(&confirm_param, CNFM_TYPE_YESNO);
            mmi_um_ui_sh_set_confirm_param(&confirm_param, scrn_cntx, MMI_UM_UI_SH_CF_FOLDER_OPT_DEL_ALL);
            scrn_cntx->screen_hdlr.cf_grp_id = mmi_confirm_display(
                                                        (WCHAR *)get_string((MMI_ID_TYPE)confirm_msg_str_id), 
                                                        MMI_EVENT_QUERY, 
                                                        &confirm_param);
            break;
        }
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MENU_ID_UM_MS_OPT:
        {
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MENU_ID_UM_MULTI_OP_MOVE_TO_ARCHIVE_PRE:
        {
        #ifdef __USB_IN_NORMAL_MODE__
            if (srv_usb_is_in_mass_storage_mode())
            {
                mmi_usb_app_unavailable_popup(0);
            }
            else
        #endif /* __USB_IN_NORMAL_MODE__ */
            {
                mmi_um_ui_sh_general_folder_ms_item_select_common_hanlder(scrn_cntx, SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE);
            }
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        /*----------------------------------------------------------------*/
        /* Add code here to detect USB mode when try to delete            */
        /* archive box messages. So the behavior between UM and message   */
        /* App will be uinified and MAUI_02452811 will be solved.        */
        /*----------------------------------------------------------------*/
        case MENU_ID_UM_MULTI_OP_DELETE_PRE:
        case MENU_ID_UM_MS_DELETE_OPT:
        {
        #if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
            if ((SRV_UM_MSG_BOX_ARCHIVE == (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_ARCHIVE)) &&
                 srv_usb_is_in_mass_storage_mode())
            {
                mmi_usb_app_unavailable_popup(0);
            }
            else
        #endif
          	{ 
                mmi_um_ui_sh_general_folder_ms_item_select_common_hanlder(scrn_cntx, SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE);
          	}
            break; 
        }
        #ifndef __UM_FOLDER__
        case MENU_ID_UM_MULTI_OP_COPY_TO_PHONE_PRE:
        {
            mmi_um_ui_sh_general_folder_ms_item_select_common_hanlder(scrn_cntx, SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_PHONE);
            break;
        }
        case MENU_ID_UM_MULTI_OP_COPY_TO_SIM_PRE:
        {
            mmi_um_ui_sh_general_folder_ms_item_select_common_hanlder(scrn_cntx, SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM);
            break;
        }
        case MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE_PRE:
        {
            mmi_um_ui_sh_general_folder_ms_item_select_common_hanlder(scrn_cntx, SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_PHONE);
            break;
        }
        
        case MENU_ID_UM_MULTI_OP_MOVE_TO_SIM_PRE:
        {
            mmi_um_ui_sh_general_folder_ms_item_select_common_hanlder(scrn_cntx, SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_SIM);
            break;
        }
        #endif /* __UM_FOLDER__ */
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        case MENU_ID_UM_SORT_BY_OPT:
        {
            /* Select on sort by root option, do nothing */
            break;
        }
        case MENU_ID_UM_SORT_BY_TIME:
        case MENU_ID_UM_SORT_BY_RECIPIENT:
        case MENU_ID_UM_SORT_BY_SUBJECT:
        case MENU_ID_UM_SORT_BY_READ_STATUS:
        case MENU_ID_UM_SORT_BY_SIZE:
        case MENU_ID_UM_SORT_BY_TYPE:
        {
            srv_um_list_filter_struct *filter;

            filter = mmi_um_ui_fsm_ef_get_list_filter_type(&(scrn_cntx->fsm));
            /* Get the select menu id */
            filter->idx_type = mmi_um_ui_ut_get_filter_type_by_menu_id(menu_evt->highlighted_menu_id);
            mmi_um_ui_fsm_ef_set_list_filter_type(&(scrn_cntx->fsm), *filter);

            scrn_cntx->child_group_id = 0;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
    #if (defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__))
        case MENU_ID_UM_FILTER_BY_OPT:
        {
            /* Select on filter by root option, do nothing */
            break;
        }
        case MENU_ID_UM_FILTER_BY_OPT_SIM1:
        case MENU_ID_UM_FILTER_BY_OPT_SIM2:
        #if (MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_UM_FILTER_BY_OPT_SIM3:
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
        case MENU_ID_UM_FILTER_BY_OPT_SIM4:
        #endif
        case MENU_ID_UM_FILTER_BY_OPT_ALL:
        {
            srv_um_sim_enum sim_id;

            /* Get the select menu id */
            sim_id = mmi_um_ui_ut_get_sim_id_by_menu_id(menu_evt->highlighted_menu_id);
            mmi_um_ui_fsm_ef_set_sim_type(&(scrn_cntx->fsm), sim_id);
            scrn_cntx->screen_hdlr.folder_type.sim_id = sim_id;

            scrn_cntx->child_group_id = 0;
            cui_menu_close(menu_evt->sender_id);
            /* force update */
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);

            break;
        }
    #endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */
        default:
        {
            mmi_um_opt_para_struct para;

            memset(&para, 0, sizeof(mmi_um_opt_para_struct));
            para.msg_id = scrn_cntx->screen_hdlr.hilite_info.msg_id;
            para.parent_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
            para.display_flag = MMI_TRUE;
            para.user_data = (void *)scrn_cntx;
            ret = mmi_um_ui_adp_opt_cb(evt, 
                                       scrn_cntx->screen_hdlr.hilite_info.msg_type, 
                                       &para);

            /* Close menu cui if not any new screen display */
            if (MMI_FALSE == para.display_flag)
            {
                scrn_cntx->child_group_id = 0;
                cui_menu_close(menu_evt->sender_id);
            }
            break;
        }
    }

    return ret;
}
#else
mmi_ret mmi_um_ui_sh_general_folder_opt_item_select_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    cui_menu_event_struct *menu_evt;
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    ret = MMI_RET_OK;
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_UM_DEL_ALL_OPT:
#ifdef __MMI_SMS_SLIM__
		case MENU_ID_UM_DELETE_MSG_FOLDER_INBOX:
		case MENU_ID_UM_DELETE_MSG_FOLDER_DRAFT:
		case MENU_ID_UM_DELETE_MSG_FOLDER_UNSENT:
		case MENU_ID_UM_DELETE_MSG_FOLDER_SENT:
#endif
        {
            U16 confirm_msg_str_id;
        #ifdef __MMI_UM_CONVERSATION_BOX__
            mmi_um_ui_folder_mode_enum folder_mode;
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
            mmi_confirm_property_struct confirm_param;

        /*----------------------------------------------------------------*/
        /* Add code here to detect USB mode when try to delete            */
        /* archive box messages. So the behavior between UM and message   */
        /* App will be uinified and MAUI_02452811 will be solved.        */
        /*----------------------------------------------------------------*/
        #if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
            if ((SRV_UM_MSG_BOX_ARCHIVE == (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_ARCHIVE)) &&
                 srv_usb_is_in_mass_storage_mode())
            {
                mmi_usb_app_unavailable_popup(0);
                break;
            }
        #endif
            /* Confirm first */
        #ifdef __MMI_UM_CONVERSATION_BOX__
            folder_mode = mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm));
            if (MMI_UM_FOLDER_MODE_THREAD_MSG == folder_mode)
            {
                confirm_msg_str_id = STR_UM_DELETE_ALL_MSG_IN_CONTACT;
            }
            else
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
            {
                confirm_msg_str_id = STR_GLOBAL_DELETE_ALL_ASK;
            }
#ifdef __MMI_SMS_SLIM__
			/***** As there is no FSM is enabled need to set message 
			box type explicitly at scrn cntx variable as launch from external cui  ******/
			scrn_cntx->screen_hdlr.folder_type.msg_box_type = 1 << (menu_evt->highlighted_menu_id - MENU_ID_UM_DELETE_MSG_FOLDER_INBOX);
#endif
            memset(&confirm_param, 0, sizeof(mmi_confirm_property_struct));
            mmi_confirm_property_init(&confirm_param, CNFM_TYPE_YESNO);
            mmi_um_ui_sh_set_confirm_param(&confirm_param, scrn_cntx, MMI_UM_UI_SH_CF_FOLDER_OPT_DEL_ALL);
            scrn_cntx->screen_hdlr.cf_grp_id = mmi_confirm_display(
                                                        (WCHAR *)get_string((MMI_ID_TYPE)confirm_msg_str_id), 
                                                        MMI_EVENT_QUERY, 
                                                        &confirm_param);
            break;
        }
    }
    return ret;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_opt_del_all_cf_yes
 * DESCRIPTION
 *  While pressing "Yes" on confirm screen, it should trigger the deleta all
 *  process
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_general_folder_opt_del_all_cf_yes(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 process_scrn_id;
    srv_um_box_identity_struct folder_setting;
#ifdef __MMI_UM_CONVERSATION_BOX__
    srv_um_thread_id_struct thread_id;
    mmi_um_ui_folder_mode_enum folder_mode;
    srv_um_list_filter_struct *filter;
#endif /* __MMI_UM_CONVERSATION_BOX__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

#ifdef __MMI_UM_CONVERSATION_BOX__
    folder_mode = mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm));
    filter = mmi_um_ui_fsm_ef_get_list_filter_type(&(scrn_cntx->fsm));
    if (MMI_UM_FOLDER_MODE_THREAD_MSG == folder_mode)
    {
        /* Delete a thread */
        process_scrn_id = mmi_um_ui_if_entry_delete_thrd_msg(0, scrn_cntx->group_id, MMI_FALSE);
        thread_id.type = filter->thread_id.type;
        thread_id.value = filter->thread_id.value;
        /* Set the thread id */
        mmi_um_ui_cc_send_event(process_scrn_id, MMI_UM_UI_EVENT_SET_THREAD_ID, &thread_id);
        mmi_um_ui_ut_send_init_event(process_scrn_id);
    }
    else
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    {
        /* Setting of delete all indication */
        folder_setting.msg_box_type = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
        folder_setting.msg_type = scrn_cntx->screen_hdlr.folder_type.msg_type;
        folder_setting.sim_id = scrn_cntx->screen_hdlr.folder_type.sim_id;
        /* Process to delete folder */
        process_scrn_id = mmi_um_ui_if_entry_process_delete_folder(0, &folder_setting, scrn_cntx->group_id, MMI_FALSE);
        mmi_um_ui_ut_send_init_event(process_scrn_id);
    }
    /* release the original list */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);

    return MMI_RET_OK;
}


#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_set_toolbar_info
 * DESCRIPTION
 *  The general function to set each different box toolbar information.
 *
 * PARAMETERS
 *  tb_info             [OUT]: Toolbar information
 *  box_type            [IN]:  Box type
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_set_toolbar_info(
                        mmi_um_ui_tb_handler_struct *tb_info, 
                        srv_um_msg_box_enum box_type, 
                        mmi_um_ui_folder_mode_enum folder_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_um_ui_tb_action_folder_enum folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != tb_info);

    folder = mmi_um_ui_ut_get_tb_folder_by_msg_box_type(box_type, folder_mode);
    MMI_ASSERT(MMI_UM_UI_TB_FOLDER_TOTAL > folder);

    memset(tb_info, 0, sizeof(mmi_um_ui_tb_handler_struct));
    for (i = 0 ; i < MMI_UM_UI_MAX_TB_ICON ; i++)
    {
        if (NULL == g_um_ui_sh_tb_action_table[folder][i])
        {
            break;
        }
        /* Update the number of toolbar */
        tb_info->num_of_toolbar++;
        /* Set icon */
        tb_info->body[i] = get_image(g_um_ui_sh_tb_icon_table[folder][i]);
        tb_info->body_disable[i] = get_image(g_um_ui_sh_tb_disable_icon_table[folder][i]);
        /* Set string */
        tb_info->hint[i] = (PU8)get_string(g_um_ui_sh_tb_str_table[folder][i]);
    }
    /* Set cb function */
    tb_info->callback = mmi_um_ui_sh_general_folder_tb_cb;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_set_toolbar_status
 * DESCRIPTION
 *  The general function to set each different box toolbar status.
 *  (enable/disable)
 *
 * PARAMETERS
 *  tb_info             [OUT]: Toolbar information
 *  msg_type            [IN]:  message type
 *  msg_id              [IN]:  message id
 *  box_type            [IN]:  Box type
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_set_toolbar_status(
                        mmi_um_ui_tb_handler_struct *tb_info, 
                        srv_um_msg_enum msg_type, 
                        U32 msg_id, 
                        srv_um_msg_box_enum box_type, 
                        mmi_um_ui_folder_mode_enum folder_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_um_ui_tb_action_folder_enum folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != tb_info);

    folder = mmi_um_ui_ut_get_tb_folder_by_msg_box_type(box_type, folder_mode);
    MMI_ASSERT(MMI_UM_UI_TB_FOLDER_TOTAL > folder);

    memset(tb_info, 0, sizeof(mmi_um_ui_tb_handler_struct));
    for (i = 0 ; i < MMI_UM_UI_MAX_TB_ICON ; i++)
    {
        /* Check the status by the global toolbar checking table */
        if (NULL == g_um_ui_sh_tb_check_action_table[folder][i])
        {
            break;
        }
        /* Update the number of toolbar */
        tb_info->num_of_toolbar++;
        /* Set the status */
        tb_info->status[i] = (*g_um_ui_sh_tb_check_action_table[folder][i])(msg_type, msg_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_tb_action
 * DESCRIPTION
 *  In toolbar, "action" the specified message by calling adaptor function
 *      Action could be "reply", "forward", "send", "resend", "edit", 
 *      "delete", "copy", "move".
 *
 * PARAMETERS
 *  action              [IN]:   selected action
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_tb_action(mmi_um_ui_tb_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 highlight_idx;
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;
#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
    srv_um_msg_enum msg_type=SRV_UM_MSG_NONE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);

    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    switch (action)
    {
        case MMI_UM_UI_TB_ACTION_REPLY:
        {
            mmi_um_ui_adp_reply_msg(
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type, 
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_id, 
                    root_grp_id);
            break;
        }
        case MMI_UM_UI_TB_ACTION_FORWARD:
        {
            mmi_um_ui_adp_forward_msg(
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type, 
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_id, 
                    root_grp_id);
            break;
        }
        case MMI_UM_UI_TB_ACTION_SEND:
        {
            mmi_um_ui_adp_send_msg(
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type, 
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_id, 
                    root_grp_id);
            break;
        }
        case MMI_UM_UI_TB_ACTION_RESEND:
        {
            mmi_um_ui_adp_resend_msg(
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type, 
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_id, 
                    root_grp_id);
            break;
        }
        case MMI_UM_UI_TB_ACTION_EDIT:
        {
            mmi_um_ui_adp_edit_msg(
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type, 
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_id, 
                    root_grp_id);
            break;
        }
        case MMI_UM_UI_TB_ACTION_DELETE:
        {
            mmi_um_ui_adp_delete_msg(
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type, 
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_id, 
                    root_grp_id);
            break;
        }
        case MMI_UM_UI_TB_ACTION_COPY:
        {
            mmi_um_ui_adp_copy_msg(
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type, 
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_id, 
                    root_grp_id);
            break;
        }
        case MMI_UM_UI_TB_ACTION_MOVE:
        {
            mmi_um_ui_adp_move_msg(
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type, 
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_id, 
                    root_grp_id);
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
    if((SRV_UM_MSG_SMS ==((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type) && (action==MMI_UM_UI_TB_ACTION_DELETE))
    {
        msg_type=((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type;
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);
        srv_um_clear_msg_info_cache();
    }
    if((SRV_UM_MSG_SMS ==msg_type) && (action!=MMI_UM_UI_TB_ACTION_DELETE))
    {
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
    }
    if((SRV_UM_MSG_SMS !=msg_type))
    {
        /* Reset the data list */
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);

        /* Reset cache in the Service level */
        srv_um_clear_msg_info_cache();

        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
    }

#else
    if((SRV_UM_MSG_SMS !=((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type))
    /* operation on SMS will always send refresh indication, no need to do force refresh by UM */
    {
        /* Reset the data list */
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);

        /* Reset cache in the Service level */
        srv_um_clear_msg_info_cache();
    
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL); 
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_tb_reply
 * DESCRIPTION
 *  In toolbar, reply the specified message by calling adaptor function
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_tb_cb(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_tb_action_folder_enum tb_box;
    mmi_um_ui_folder_mode_enum folder_mode;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    folder_mode = mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm));
    tb_box = mmi_um_ui_ut_get_tb_folder_by_msg_box_type(
                    scrn_cntx->screen_hdlr.folder_type.msg_box_type, 
                    folder_mode);
    g_um_ui_sh_tb_action_table[tb_box][index]();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_tb_reply
 * DESCRIPTION
 *  In toolbar, reply the specified message by calling adaptor function
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_tb_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_general_folder_tb_action(MMI_UM_UI_TB_ACTION_REPLY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_tb_forward
 * DESCRIPTION
 *  In toolbar, forward the specified message by calling adaptor function
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_tb_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_general_folder_tb_action(MMI_UM_UI_TB_ACTION_FORWARD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_tb_send
 * DESCRIPTION
 *  In toolbar, send the specified message by calling adaptor function
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_tb_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_general_folder_tb_action(MMI_UM_UI_TB_ACTION_SEND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_tb_resend
 * DESCRIPTION
 *  In toolbar, resend the specified message by calling adaptor function
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_tb_resend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_general_folder_tb_action(MMI_UM_UI_TB_ACTION_RESEND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_tb_edit
 * DESCRIPTION
 *  In toolbar, edit the specified message by calling adaptor function
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_tb_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_general_folder_tb_action(MMI_UM_UI_TB_ACTION_EDIT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_tb_delete
 * DESCRIPTION
 *  In toolbar, delete the specified message by calling adaptor function
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_tb_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_general_folder_tb_action(MMI_UM_UI_TB_ACTION_DELETE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_tb_copy
 * DESCRIPTION
 *  In toolbar, copy the specified message by calling adaptor function
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_tb_copy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_general_folder_tb_action(MMI_UM_UI_TB_ACTION_COPY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_tb_move
 * DESCRIPTION
 *  In toolbar, move the specified message by calling adaptor function
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_tb_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_general_folder_tb_action(MMI_UM_UI_TB_ACTION_MOVE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_intuitive_cmd_cb
 * DESCRIPTION
 *  In FTE, it should support intuitive command. (tap to selecte)
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_general_folder_intuitive_cmd_cb(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;
    U16 highlight_idx;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;
    mmi_um_entry_msg_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ENUM_TAP_ON_NONHIGHLIGHTED_ITEM == tap_type)
    {
        /* only change highlight, do nothing */
        return;
    }
    
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);

    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;

    memset(&para, 0, sizeof(mmi_um_entry_msg_struct));
    para.key_code = MMI_UM_UI_ENTRY_INTUITIVE_CMD;
    para.parent_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    para.msg_id = ((srv_um_msg_node_struct *)data_list->list)[highlight_idx].msg_id;
    para.user_data = (void *)scrn_cntx;

    grp_id = mmi_um_ui_adp_entry_msg(
                    ((srv_um_msg_node_struct*)data_list->list)[highlight_idx].msg_type, 
                    &para);

    if (GRP_ID_INVALID != grp_id)
    {
        /* Reset the data list */
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);

        /* Reset cache in the Service level */
        srv_um_clear_msg_info_cache();
    }
}
#endif /* __MMI_ICON_BAR_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_general_folder_get_entry_func
 * DESCRIPTION
 *  Get the entry function pointer by different folder mode
 *
 * PARAMETERS
 *  mode                    [IN]: the folder mode
 *  
 * RETURNS
 *  Entry function pointer
 *****************************************************************************/
mmi_um_entry_func_ptr mmi_um_ui_sh_general_folder_get_entry_func(mmi_um_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_entry_func_ptr func_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    func_ptr = NULL;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
        {
            func_ptr = mmi_um_ui_sh_general_folder_entry;
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_CONVERSATION_BOX:
        {
            func_ptr = mmi_um_ui_sh_cs_entry;
            break;
        }
        case MMI_UM_FOLDER_MODE_THREAD_MSG:
        {
            func_ptr = mmi_um_ui_sh_general_folder_entry;
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return func_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_write_msg_init
 * DESCRIPTION
 *  Initialize the write message screen varialbe. It shall trigger the 
 *  fsm initial function to initialize the fsm context.
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  setting                 [IN]: Setting
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_write_msg_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
    return mmi_um_ui_sh_non_fsm_init(scrn_cntx, setting);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_write_msg_event_hdlr
 * DESCRIPTION
 *  The write message selection menu. If UC does not open, it should have 
 *  SMS editor / MMS editor could be selected.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_write_msg_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        {
            mmi_um_ui_sh_create(mmi_um_ui_sh_write_msg_entry, scrn_cntx);
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_write_msg_entry
 * DESCRIPTION
 *  Entry the write message screen.
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_write_msg_entry(mmi_scrn_essential_struct *arg)
{
    mmi_um_ui_sh_setting_write_msg_entry(arg, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_write_hilite_hdlr
 * DESCRIPTION
 *  Write message hilite handler
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_write_msg_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    scrn_cntx->screen_hdlr.hilite_info.index = (U16)index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_write_msg_lsk_hdlr
 * DESCRIPTION
 *  Left soft key handler for write message screen.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_write_msg_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hilite_menu_id;
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    hilite_menu_id = GetSeqItemId_Ext((U16)MENU_ID_UM_WRITE_MSG, scrn_cntx->screen_hdlr.hilite_info.index);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    switch (hilite_menu_id)
    {
        case MENU_ID_UM_WRITE_MSG_SMS:
        {
            mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_WRITE_MSG_SMS);
#ifndef __MMI_UM_ULTRA_SLIM__
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
#endif
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case MENU_ID_UM_WRITE_MSG_MMS:
        {
            mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_WRITE_MSG_MMS);
#ifndef __MMI_UM_ULTRA_SLIM__
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
#endif
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
        default:
        {
            break;
        }
    }
}

#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_main_msg_entry_del_folder
 * DESCRIPTION
 *  Entry delete messages screens
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_main_msg_entry_del_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    scrn_id = mmi_um_ui_if_entry_general(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE, MMI_UM_ENTRY_SCREEN_DELETE_FOLDER, NULL);
    mmi_um_ui_ut_send_init_event(scrn_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_delete_folder_init
 * DESCRIPTION
 *  Initialize the delete folder screen varialbe. It shall trigger the 
 *  fsm initial function to initialize the fsm context.
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  setting                 [IN]: Setting
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_delete_folder_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
    return mmi_um_ui_sh_el_fsm_init(scrn_cntx, setting, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_delete_folder_event_hdlr
 * DESCRIPTION
 *  Delete folder screen event handler. Receive the event from the Central 
 *  controller and it needs to handle the event by itself or pass to finite 
 *  state machine.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_delete_folder_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        case MMI_UM_UI_EVENT_ABORT:
        case MMI_UM_UI_EVENT_CHECK:
        case MMI_UM_UI_EVENT_READY:
        case MMI_UM_UI_EVENT_UNREADY:
        {
            #if 0
/* under construction !*/
/* under construction !*/
            #endif
            result = mmi_um_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            break;
        }
        case MMI_UM_UI_EVENT_REFRESH:
        {
            if (GRP_ID_INVALID != scrn_cntx->screen_hdlr.cf_grp_id)
            {
                /* display a update popup */
                mmi_popup_display_simple(
                        (WCHAR *)get_string(STR_GLOBAL_UPDATE), 
                        MMI_EVENT_INFO, 
                        scrn_cntx->group_id, 
                        NULL);
            }
            else
            {
                #if 0
/* under construction !*/
/* under construction !*/
                #endif
                result = mmi_um_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            }
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        case MMI_UM_UI_EVENT_DELETED:
        {
            /* Set child screen as 0 */
            scrn_cntx->child_scrn_id = 0;
            if (!mmi_frm_scrn_is_present(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, MMI_FRM_NODE_ALL_FLAG))
            {
                /**************************************************** 
                 * Screen is not in history and the child is deleted.
                 * This scenario happens in UM is not ready.
                 * (1) Entry delete messages
                 * (2) Display processing with RSK (unready)
                 * (3) Press end key in processing screen
                 * (4) child is deleted and notify parent
                 ***************************************************/
                mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
            }
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_delete_folder_fsm_cb
 * DESCRIPTION
 *  The registered callback function for finite state machine. Finite state
 *  machine will notify screen handler and it should has the relative
 *  reaction.
 *
 * PARAMETERS
 *  scrn_id             [IN]: Current screen id
 *  state               [IN]: State of finite state machine
 *  status              [IN]: In that state, the current status
 *  
 * RETURNS
 *  MMI_TRUE: handle this callback successfully
 *  MMI_FALSE: fail to handle this callback
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_delete_folder_fsm_cb(U16 scrn_id, U16 state, U16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    switch (state)
    {
        case MMI_UM_UI_FSM_EL_INSIDE:
        {
            if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_TRUE)
            {
                mmi_um_ui_sh_delete_folder_update(scrn_cntx);
            }
            else
            {
                scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
                mmi_um_ui_sh_create(mmi_um_ui_sh_delete_folder_entry, scrn_cntx);
            }

            /* After collecting data, it should enable LSK function */
            if (MMI_SCENARIO_STATE_ACTIVE == 
                mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
            {
                EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            }
            break;
        }
        case MMI_UM_UI_FSM_EL_UPDATE:
        {
            if (MMI_UM_UI_REQ_SRV_WAIT_READY == status)
            {
                /* UM is not ready yet */
                if (!mmi_um_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
                {
                    scrn_cntx->child_scrn_id = mmi_um_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
                    mmi_um_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
                }
            }
            else
            {
                /* child screen is alive */
                if (MMI_FALSE == scrn_cntx->screen_hdlr.is_scrn_displayed)
                {
                    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
                    mmi_um_ui_sh_create(mmi_um_ui_sh_delete_folder_entry, scrn_cntx);
                }
                mmi_um_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));

                /* During collecting data, it should disable LSK function */
                if (MMI_SCENARIO_STATE_ACTIVE == 
                    mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
                {
                    DisableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
                }
            }
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_delete_folder_entry
 * DESCRIPTION
 *  Entry the delete folder screen.
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_delete_folder_entry(mmi_scrn_essential_struct *arg)
{
    mmi_um_ui_sh_main_msg_delete_folder_entry(arg, MMI_UM_UI_ENTRY_DELETE_FOLDER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_delete_folder_lsk_hdlr
 * DESCRIPTION
 *  Left soft key handler for delete folder.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_delete_folder_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_of_item;
    U16 confirm_msg_str_id;
    srv_um_get_msg_num_result *msg_num_info;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_confirm_property_struct confirm_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    scrn_cntx->fsm.cntx.fsm_entry_list.get_msg_num(scrn_cntx->scrn_id, &msg_num_info);

    num_of_item = mmi_um_ui_ut_get_msg_num_by_msg_box(scrn_cntx->screen_hdlr.folder_type.msg_box_type, msg_num_info);
    confirm_msg_str_id = mmi_um_ui_ut_get_delete_folder_str_id_by_msg_box(scrn_cntx->screen_hdlr.folder_type.msg_box_type);

    if (num_of_item == 0)
    {
        mmi_popup_display_simple(
                (WCHAR *)get_string(STR_GLOBAL_EMPTY), 
                MMI_EVENT_FAILURE, 
                scrn_cntx->group_id, 
                NULL);
    }
    else
    {
        memset(&confirm_param, 0, sizeof(mmi_confirm_property_struct));
        mmi_confirm_property_init(&confirm_param, CNFM_TYPE_YESNO);
        mmi_um_ui_sh_set_confirm_param(&confirm_param, scrn_cntx, MMI_UM_UI_SH_CF_DELETE_FOLDER);
        scrn_cntx->screen_hdlr.cf_grp_id = mmi_confirm_display(
                                                    (WCHAR *)get_string((MMI_ID_TYPE)confirm_msg_str_id), 
                                                    MMI_EVENT_QUERY, 
                                                    &confirm_param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_delete_folder_hilite_hdlr
 * DESCRIPTION
 *  Delete folder of Highlight handler.
 *
 * PARAMETERS
 *  index:          [IN] highlighted index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_delete_folder_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hilite_menu_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    hilite_menu_id = GetSeqItemId_Ext((U16)MENU_ID_UM_DELETE_FOLDER, (U16)index);

    scrn_cntx->screen_hdlr.hilite_info.index = (U16)index;
    scrn_cntx->screen_hdlr.folder_type.msg_box_type = mmi_um_ui_ut_get_box_type_by_delete_menu_id(hilite_menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_delete_folder_update
 * DESCRIPTION
 *  Update the delete folder screen.
 *  Inline feature is open:
 *      Inbox (0/10)
 *      Draft (21)
 *      Outbox (1)
 *  Inline feature is close:
 *      Inbox
 *          10 messages
 *      Draft
 *          21 messages
 *      Outbox
 *          1 message
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_delete_folder_update(void *arg)
{
    mmi_um_ui_sh_main_msg_delete_folder_update(arg, 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_delete_folder_update_item
 * DESCRIPTION
 *  Update the delete folder screen.
 *      Inbox (0/10)
 *      Draft (21)
 *      Outbox (1)
 *
 * PARAMETERS
 *  item_string             [OUT]: Buffer for items string
 *  msg_num_info            [IN]: Message number information
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_delete_folder_update_item(U8 **item_string, srv_um_get_msg_num_result *msg_num_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_of_item;
    U16 item_str_id[MAX_SUB_MENUS];
    U8 hint_asc[MAX_SUB_MENU_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_num_info != NULL);
    
    num_of_item = GetSequenceStringIds_Ext(MENU_ID_UM_DELETE_FOLDER, item_str_id);
    MMI_ASSERT(MAX_SUB_MENUS >= num_of_item);

    for (i = 0; i < num_of_item; i++)
    {
        mmi_ucs2cpy((CHAR*)item_string[i], (CHAR*)get_string((MMI_ID_TYPE)item_str_id[i]));
    }

    /* Inbox */
    i = GetIndexOfStringId_Ext(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_INBOX);
    sprintf((CHAR *)hint_asc, " (%d/%d)", msg_num_info->inbox_unread_msg_number, msg_num_info->inbox_msg_number);
    mmi_um_ui_ut_concate_str_with_num((CHAR *)hint_asc, (CHAR *)item_string[i]);

    /* Draft, Outbox, Sent */
    mmi_um_ui_ut_update_item_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_DRAFT, item_string, msg_num_info->draft_msg_number);
    mmi_um_ui_ut_update_item_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_UNSENT, item_string, msg_num_info->unsent_msg_number);
    mmi_um_ui_ut_update_item_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_SENT, item_string, msg_num_info->sent_msg_number);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    mmi_um_ui_ut_update_item_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_ARCHIVE, item_string, msg_num_info->archive_msg_number);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    mmi_um_ui_ut_update_item_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_SIM, item_string, msg_num_info->sim_msg_number);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
    mmi_um_ui_ut_update_item_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_REPORT, item_string, msg_num_info->report_msg_number);
#endif /* __MMI_UM_REPORT_BOX__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_delete_folder_update_item_hint
 * DESCRIPTION
 *  Update the delete folder screen.
 *      Inbox
 *          10 messages
 *      Draft
 *          21 messages
 *      Outbox
 *          1 message
 *
 * PARAMETERS
 *  item_hint               [OUT]: Buffer for items hint string
 *  msg_num_info            [IN]: Message number information
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_delete_folder_update_item_hint(U8 **item_hint, srv_um_get_msg_num_result *msg_num_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_num_info != NULL);

    mmi_um_ui_ut_update_item_hint_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_INBOX, item_hint, msg_num_info->inbox_msg_number);
    mmi_um_ui_ut_update_item_hint_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_DRAFT, item_hint, msg_num_info->draft_msg_number);
    mmi_um_ui_ut_update_item_hint_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_UNSENT, item_hint, msg_num_info->unsent_msg_number);
    mmi_um_ui_ut_update_item_hint_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_SENT, item_hint, msg_num_info->sent_msg_number);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    mmi_um_ui_ut_update_item_hint_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_ARCHIVE, item_hint, msg_num_info->archive_msg_number);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    mmi_um_ui_ut_update_item_hint_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_SIM, item_hint, msg_num_info->sim_msg_number);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
    mmi_um_ui_ut_update_item_hint_by_menu_id(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_REPORT, item_hint, msg_num_info->report_msg_number);
#endif /* __MMI_UM_REPORT_BOX__ */

    /* All messages */
    i = GetIndexOfStringId_Ext(MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_DELETE_FOLDER_ALL);
    item_hint[i] = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_delete_folder_process
 * DESCRIPTION
 *  Delete the folder process. It will invoke the other screen to process.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_delete_folder_process(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    srv_um_box_identity_struct folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    folder.msg_box_type = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
    folder.msg_type = g_um_ui_p->setting.support_msg_type;
    folder.sim_id = SRV_UM_SIM_ALL;
    scrn_id = mmi_um_ui_if_entry_process_delete_folder(0, &folder, scrn_cntx->group_id, MMI_FALSE);

    /* Start to process by INIT */
    mmi_um_ui_ut_send_init_event(scrn_id);

    return MMI_RET_OK;
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
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/* under construction !*/
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/* under construction !*/
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
/* under construction !*/
#endif /* __MMI_UM_REPORT_BOX__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __MMI_UM_DELETE_FOLDER_SUPPORT__ */
#endif/*__MMI_TELEPHONY_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_process_del_folder_init
 * DESCRIPTION
 *  Initialize the process delete folder screen varialbe. It shall trigger the 
 *  fsm initial function to initialize the fsm context.
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  setting                 [IN]: Setting
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_process_del_folder_init(
                        mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                        mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UM_OP_FSM_SUPPORT__ 
    {
        /* FSM initialize */
        /* Local variable in code block */
        mmi_um_ui_fsm_op_setting_struct fsm_setting;
        
        memset(&(fsm_setting), 0, sizeof(mmi_um_ui_fsm_op_setting_struct));
        fsm_setting.action_type = MMI_UM_UI_ACTION_DELETE_FOLDER;
        fsm_setting.folder_type = setting->folder;
        fsm_setting.scrn_callback_hdlr = mmi_um_ui_sh_process_del_folder_fsm_cb;
        fsm_setting.scrn_id = scrn_cntx->scrn_id;
        mmi_um_ui_fsm_op_init(&(scrn_cntx->fsm), fsm_setting);
    }
#else /* __MMI_UM_OP_FSM_SUPPORT__ */
    {
        /* Local variable in code block */
        mmi_um_ui_fsm_node_struct *fsm_cntx = &(scrn_cntx->fsm);
        mmi_um_ui_fsm_operation_struct *fsm;
        fsm_cntx->type = MMI_UM_UI_FSM_OPERATION;

        fsm = &(fsm_cntx->cntx.fsm_operation);
        memset(fsm, 0, sizeof(mmi_um_ui_fsm_operation_struct));
        fsm->folder_type = setting->folder;
        fsm->req_srv_status = MMI_UM_UI_REQ_SRV_NONE;
        fsm->scrn_id = scrn_cntx->scrn_id;
    }
#endif  /* __MMI_UM_OP_FSM_SUPPORT__ */
    /* Appearance initialize */
    mmi_um_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_um_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;
    scrn_cntx->screen_hdlr.scrn_data = setting->scrn_data;

    return MMI_TRUE;
}

#ifndef __MMI_UM_OP_FSM_SUPPORT__ 
MMI_BOOL mmi_um_ui_sh_process_del_folder_event_hdlr_without_op(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct * fsm_cntx;
    MMI_BOOL result;
    mmi_um_ui_fsm_operation_struct *fsm;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    fsm_cntx = &scrn_cntx->fsm;
    fsm = &(fsm_cntx->cntx.fsm_operation);
    result = MMI_TRUE;
    
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        {
            mmi_um_ui_sh_create(mmi_um_ui_sh_process_del_folder_entry, scrn_cntx);
            {
                
                fsm->pid = srv_um_delete_folder(
                                    fsm->folder_type, 
                                    mmi_um_ui_delete_folder_req_cb, 
                                    (S32) fsm->scrn_id);
                
                fsm->req_srv_status = MMI_UM_UI_REQ_SRV_PROGRESS;
            }
            break;
        }
        case MMI_UM_UI_EVENT_ABORT:
        {
            srv_um_cancel_request(fsm->pid);
            fsm->req_srv_status = MMI_UM_UI_REQ_SRV_CANCELLING;
            mmi_um_ui_sh_process_del_folder_update((void *)scrn_cntx, 
                                                   STR_GLOBAL_CANCELLING, 
                                                   mmi_get_event_based_image(MMI_EVENT_PROGRESS));
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_fsm_op_req_delete_folder_cb
 * DESCRIPTION
 *  The callback function for delete folder from service.
 *
 * PARAMETERS
 *  pid                 [IN]: Request id
 *  rsp                 [IN]: Response from service
 *  para                [IN]: Optional paramenter, it is used for screen id
 *
 * RETURNS
 *  Process result. Regards to srv_um_result_enum.
 *****************************************************************************/
S32 mmi_um_ui_delete_folder_req_cb(S32 pid, srv_um_delete_folder_result *rsp, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_operation_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check pid if invalid */
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx((U16)para);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_operation);

    if((0 != pid ) && (pid == fsm->pid))
    {
        if ((rsp->error != SRV_UM_RESULT_OK) && (rsp->error != SRV_UM_RESULT_CANCELLLED))
        {
            /* Display a fail popup */
            mmi_popup_display_simple(
                    (WCHAR *)get_string(STR_GLOBAL_UNFINISHED), 
                    MMI_EVENT_FAILURE, 
                    scrn_cntx->group_id, 
                    NULL);
        }
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
    }
    return SRV_UM_RESULT_OK;
}
#endif

#ifdef __MMI_UM_OP_FSM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_process_del_folder_event_hdlr
 * DESCRIPTION
 *  Process delete folder screen event handler. Receive the event from the 
 *  Central controller and it needs to handle the event by itself or pass to 
 *  finite state machine.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_process_del_folder_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        case MMI_UM_UI_EVENT_ABORT:
        case MMI_UM_UI_EVENT_READY:
        case MMI_UM_UI_EVENT_UNREADY:
        {
            #if 0
/* under construction !*/
/* under construction !*/
            #endif
            result = mmi_um_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_process_del_folder_fsm_cb
 * DESCRIPTION
 *  The registered callback function for finite state machine. Finite state
 *  machine will notify screen handler and it should has the relative
 *  reaction.
 *
 * PARAMETERS
 *  scrn_id             [IN]: Current screen id
 *  state               [IN]: State of finite state machine
 *  status              [IN]: In that state, the current status
 *  
 * RETURNS
 *  MMI_TRUE: handle this callback successfully
 *  MMI_FALSE: fail to handle this callback
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_process_del_folder_fsm_cb(U16 scrn_id, U16 state, U16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    switch (state)
    {
        case MMI_UM_UI_FSM_OP_OPERATION:
        {
            if (status == MMI_UM_UI_REQ_SRV_PROGRESS)
            {
                mmi_um_ui_sh_create(mmi_um_ui_sh_process_del_folder_entry, scrn_cntx);
            }
            else if (status == MMI_UM_UI_REQ_SRV_FINISH)
            {
                /* Display a finish popup */
                mmi_popup_display_simple(
                        (WCHAR *)get_string(STR_GLOBAL_DELETED), 
                        MMI_EVENT_EXPLICITLY_DELETED, 
                        scrn_cntx->group_id, 
                        NULL);
                mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
            }
            else if (status == MMI_UM_UI_REQ_SRV_FAIL)
            {
                /* Display a fail popup */
                mmi_popup_display_simple(
                        (WCHAR *)get_string(STR_GLOBAL_UNFINISHED), 
                        MMI_EVENT_FAILURE, 
                        scrn_cntx->group_id, 
                        NULL);
                mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
            }
            else if (status == MMI_UM_UI_REQ_SRV_CANCELLING)
            {
                mmi_um_ui_sh_process_del_folder_update((void *)scrn_cntx, 
                                                       STR_GLOBAL_CANCELLING, 
                                                       mmi_get_event_based_image(MMI_EVENT_PROGRESS));
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}
#endif /* __MMI_UM_OP_FSM_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_process_del_folder_entry
 * DESCRIPTION
 *  Entry the process delete folder screen.
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_process_del_folder_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_loading_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.loading);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* General context */
    aprc->general_aprc_cntx.grp_id = scrn_cntx->group_id;
    aprc->general_aprc_cntx.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
    aprc->general_aprc_cntx.entry_func = mmi_um_ui_sh_process_del_folder_entry;
    aprc->general_aprc_cntx.key_hdlr.clear_end_key = MMI_TRUE;
    aprc->general_aprc_cntx.leave_proc = mmi_um_ui_sh_process_del_folder_leave_proc;

    if (MMI_UM_UI_REQ_SRV_CANCELLING == mmi_um_ui_fsm_get_fsm_req_srv_status(&(scrn_cntx->fsm)))
    {
        /* Cancelling */
        aprc->msg_str_id = STR_GLOBAL_CANCELLING;
        aprc->msg_icon_id = 0;
    }
    else
    {
        /* General context */
        aprc->general_aprc_cntx.rsk_str_id = STR_GLOBAL_CANCEL;
        aprc->general_aprc_cntx.rsk_icon_id = IMG_GLOBAL_BACK;                
        aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = mmi_um_ui_sh_process_del_folder_rsk_hdlr;

        /* Deleting */
        aprc->msg_str_id = STR_GLOBAL_DELETING;               
    }
    /* Specified context */
    aprc->msg_icon_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
    
    scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_process_del_folder_leave_proc
 * DESCRIPTION
 *  Screen proc handler. In this function, it should handle the delete and 
 *  deinit event.
 *
 * PARAMETERS
 *  evt             [IN]: Screen event from FW
 *  
 * RETURNS
 *  Handler result
 *  MMI_TRUE, it could not be deleted.
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_process_del_folder_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_RET_OK;

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        {
        #ifdef __DM_MO_SUPPORT__
            if (MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING == mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK))
            {
                result = MMI_RET_OK;
            }
        #endif /* __DM_MO_SUPPORT__ */
            break;
        }
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            /*************************************************
            * Current delete callback does not support       *
            * argment mechanism, workaround solution.        *
            * The best solution is use screen context and    *
            * check if the screen id exists in history or    *
            * not. If exist, it should not be deleted. Else  *
            * It could be deleted.                           *
            *************************************************/
        #ifdef __DM_MO_SUPPORT__
            if (MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING == mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK))
            {
                result = MMI_RET_OK;
            }
            else
        #endif /* __DM_MO_SUPPORT__ */
            {
                result = MMI_RET_ERR;
            }
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_um_ui_sh_destroy(evt->user_data);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_process_del_folder_update
 * DESCRIPTION
 *  Update the process screen due to end user press RSK(Cancel). It should 
 *  change the text as "Cancelling".
 *
 * PARAMETERS
 *  arg:                [IN]    the screen context
 *  center_update_str   [IN]    updated string id
 *  center_update_icon  [IN]    updated icon id
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_process_del_folder_update(void *arg, U16 center_update_str, U16 center_update_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_loading_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.loading);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Specified context */
    aprc->msg_icon_id = center_update_icon;
    /* Cancelling */
    aprc->msg_str_id = center_update_str;
    aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = NULL;
    
    scrn_cntx->aprc.redraw_func(&aprc_union, 
                                scrn_cntx->aprc.st_type, 
                                (mmi_um_ui_aprc_redraw_type_enum)(MMI_UM_UI_APRC_REDRAW_KEY | MMI_UM_UI_APRC_REDRAW_BODY));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_process_del_folder_rsk_hdlr
 * DESCRIPTION
 *  Right soft key handler for deleting process screen.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_process_del_folder_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_ABORT, NULL);
}

#ifdef __MMI_UM_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_template_init
 * DESCRIPTION
 *  Initialize the template screen varialbe. It shall trigger the fsm initial
 *  function to initialize the fsm context.
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  setting                 [IN]: Setting
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_template_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
    return mmi_um_ui_sh_non_fsm_init(scrn_cntx, setting);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_template_event_hdlr
 * DESCRIPTION
 *  The template selection menu.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_template_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
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
    #endif
    return mmi_um_ui_sh_setting_template_event_hdlr(scrn_id, event, arg, mmi_um_ui_sh_template_entry);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_template_entry
 * DESCRIPTION
 *  Entry the template screen.
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_template_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_list_struct *aprc;
    U16 str_item_list[MAX_SUB_MENUS];
    U16 item_icons[MAX_SUB_MENUS];
    U8 *popup_list[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.list);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* General context */
    aprc->general_aprc_cntx.grp_id = scrn_cntx->group_id;
    aprc->general_aprc_cntx.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
    aprc->general_aprc_cntx.menu_item_id = MENU_ID_UM_TEMPLATE;
    aprc->general_aprc_cntx.title_str_id = STR_UM_TEMPLATE_ID;
    aprc->general_aprc_cntx.title_icon_id = IMG_UM_ENTRY_SCRN_CAPTION;
    aprc->general_aprc_cntx.lsk_str_id = STR_GLOBAL_OK;
    aprc->general_aprc_cntx.lsk_icon_id = IMG_GLOBAL_OK;
    aprc->general_aprc_cntx.rsk_str_id = STR_GLOBAL_BACK;
    aprc->general_aprc_cntx.rsk_icon_id = IMG_GLOBAL_BACK;
    aprc->general_aprc_cntx.csk_icon_id = IMG_GLOBAL_COMMON_CSK;
    aprc->general_aprc_cntx.hilite_hdlr = mmi_um_ui_sh_template_hilite_hdlr;
    aprc->general_aprc_cntx.hilite_idx = 0;
    aprc->general_aprc_cntx.num_of_item = GetNumOfChild_Ext(MENU_ID_UM_TEMPLATE);
    aprc->general_aprc_cntx.entry_func = mmi_um_ui_sh_template_entry;
    aprc->general_aprc_cntx.exit_func = NULL;
    aprc->general_aprc_cntx.gui_buffer = NULL;
    aprc->general_aprc_cntx.key_hdlr.lsk_hdlr = NULL;
    aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = mmi_um_ui_sh_rsk_hdlr;
    aprc->general_aprc_cntx.key_hdlr.csk_hdlr = NULL;
    aprc->general_aprc_cntx.leave_proc = mmi_um_ui_sh_leave_proc;

    /* Specified context */
    /* Construct the menu item strings */
    GetSequenceStringIds_Ext(MENU_ID_UM_TEMPLATE, str_item_list);
    GetSequenceImageIds_Ext(MENU_ID_UM_TEMPLATE, item_icons);
    ConstructHintsList(MENU_ID_UM_TEMPLATE, popup_list);

    {
        S32 i;
        /* Copy to global buffer and use the global buffer pointer */
        for (i = 0; i < aprc->general_aprc_cntx.num_of_item; i++)
        {
            mmi_ucs2cpy((CHAR*)subMenuData[i], (CHAR*)get_string((MMI_ID_TYPE)str_item_list[i]));
        }
    }

    
    aprc->list_of_items = (U16 *)subMenuDataPtrs;
    aprc->list_of_item_hints = (U8 **)popup_list;
    aprc->list_of_item_icons = (U16 *)item_icons;
    scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);

    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
    {
        return;
    }

    if (!srv_um_check_ready_type(scrn_cntx->screen_hdlr.folder_type.msg_type))
    {
        scrn_cntx->child_scrn_id = mmi_um_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
        mmi_um_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_template_hilite_hdlr
 * DESCRIPTION
 *  The highlight handler of tempalte screen
 *
 * PARAMETERS
 *  index               [IN]: the highlight index of template screen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_template_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = GetSeqItemId_Ext(MENU_ID_UM_TEMPLATE, (U16)index);
    
    switch (menu_id)
    {
    #ifdef __MMI_MESSAGES_TEMPLATE__
        case MENU_ID_UM_TEMPLATE_SMS:
        {
            /* SMS */
            SetLeftSoftkeyFunction(mmi_um_ui_sh_template_entry_sms_template, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_um_ui_sh_template_entry_sms_template, KEY_EVENT_UP);
            break;
        }
    #endif /* __MMI_MESSAGES_TEMPLATE__ */
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        case MENU_ID_UM_TEMPLATE_MMS:
        {
            /* MMS */
        #ifdef __MMI_MMS_IN_UM__
            SetLeftSoftkeyFunction(mmi_um_ui_sh_template_entry_mms_template, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_um_ui_sh_template_entry_mms_template, KEY_EVENT_UP);
        #endif
            break;
        }
    #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}


#ifdef __MMI_MESSAGES_TEMPLATE__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_template_entry_sms_template
 * DESCRIPTION
 *  Entry the sms template screen
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_template_entry_sms_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the current setting screen context */
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_TEMPLATE_SMS);
}
#endif /* __MMI_MESSAGES_TEMPLATE__ */


#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_template_entry_mms_template
 * DESCRIPTION
 *  Entry the mms template screen
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_template_entry_mms_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the current setting screen context */
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_TEMPLATE_MMS);
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */
#endif /* __MMI_UM_TEMPLATE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_init
 * DESCRIPTION
 *  Initialize the setting screen varialbe. It shall trigger the fsm initial
 *  function to initialize the fsm context.
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  setting                 [IN]: Setting
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_setting_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
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
    return mmi_um_ui_sh_non_fsm_init(scrn_cntx, setting);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_event_hdlr
 * DESCRIPTION
 *  The setting selection menu.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_setting_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    return mmi_um_ui_sh_setting_template_event_hdlr(scrn_id, event, arg, mmi_um_ui_sh_setting_entry);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_entry
 * DESCRIPTION
 *  Entry the setting screen.
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_entry(mmi_scrn_essential_struct *arg)
{
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    mmi_um_ui_sh_setting_write_msg_entry(arg, 1);

    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
    {
        return;
    }

    if (!srv_um_check_ready_type(scrn_cntx->screen_hdlr.folder_type.msg_type))
    {
        scrn_cntx->child_scrn_id = mmi_um_ui_if_entry_processing(scrn_cntx->scrn_id, scrn_cntx->group_id, MMI_FALSE);
        mmi_um_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_hilite_hdlr
 * DESCRIPTION
 *  The highlight handler of setting screen
 *
 * PARAMETERS
 *  index               [IN]: the highlight index of setting screen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = GetSeqItemId_Ext(MENU_ID_UM_SETTING, (U16)index);
    
    switch (menu_id)
    {
        case MENU_ID_UM_SETTING_SMS:
        {
            /* SMS */
            SetLeftSoftkeyFunction(mmi_um_ui_sh_setting_entry_sms_setting, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_um_ui_sh_setting_entry_sms_setting, KEY_EVENT_UP);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case MENU_ID_UM_SETTING_MMS:
        {
            /* MMS */
            SetLeftSoftkeyFunction(mmi_um_ui_sh_setting_entry_mms_setting, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_um_ui_sh_setting_entry_mms_setting, KEY_EVENT_UP);
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case MENU_ID_UM_SETTING_PUSH:
        {
            SetLeftSoftkeyFunction(mmi_um_ui_sh_setting_entry_push_setting, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_um_ui_sh_setting_entry_push_setting, KEY_EVENT_UP);
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MENU_ID_UM_SETTING_CS:
        {
            SetLeftSoftkeyFunction(mmi_um_ui_sh_setting_entry_cs_setting, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_um_ui_sh_setting_entry_cs_setting, KEY_EVENT_UP);
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
    
#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
        case MENU_ID_UM_SETTING_PREFER_SIM:
        {
            SetLeftSoftkeyFunction(mmi_um_ui_sh_setting_entry_prefer_sim_setting, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_um_ui_sh_setting_entry_prefer_sim_setting, KEY_EVENT_UP);
            break;
        }
#endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            ExecuteCurrHiliteHandler(index);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_entry_sms_setting
 * DESCRIPTION
 *  Entry the SMS setting menu
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_entry_sms_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the current setting screen context */
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_SETTING_SMS);
}


#ifdef __MMI_MMS_IN_UM__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_entry_mms_setting
 * DESCRIPTION
 *  Entry the MMS setting menu
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_entry_mms_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the current setting screen context */
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_SETTING_MMS);
}
#endif /* __MMI_MMS_IN_UM__ */


#ifdef __MMI_PUSH_IN_UM__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_entry_push_setting
 * DESCRIPTION
 *  Entry the Push setting menu
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_entry_push_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the current setting screen context */
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
    mmi_um_ui_adp_cui_launch_by_menu_id(root_grp_id, MENU_ID_UM_SETTING_PUSH);
}
#endif /* __MMI_PUSH_IN_UM__ */


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_entry_cs_setting
 * DESCRIPTION
 *  Entry the conversation box setting menu
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_entry_cs_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the current setting screen context */
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    scrn_id = mmi_um_ui_if_entry_setting_cs(0, scrn_cntx->group_id, MMI_FALSE);
    mmi_um_ui_ut_send_init_event(scrn_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_cs_init
 * DESCRIPTION
 *  Initialize the conversation box setting screen variable. It shall 
 *  trigger the fsm initial function to initialize the fsm context.
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  setting                 [IN]: Setting
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_setting_cs_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    
    /* FSM initialize */
    
    /* Appearance initialize */
    mmi_um_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_um_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;
    scrn_cntx->screen_hdlr.scrn_data = setting->scrn_data;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_cs_evt_hdlr
 * DESCRIPTION
 *  The conversation box setting selection menu.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_setting_cs_evt_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        {
            mmi_um_ui_sh_create(mmi_um_ui_sh_setting_cs_entry, scrn_cntx);
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_cs_entry
 * DESCRIPTION
 *  Entry the conversation box setting screen.
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_cs_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 select;
    S16 error;
    U16 i;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_cs_setting_struct *aprc;
    U16 str_item_list[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.cs_setting);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* General context */
    aprc->general_aprc_cntx.grp_id = scrn_cntx->group_id;
    aprc->general_aprc_cntx.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
    aprc->general_aprc_cntx.menu_item_id = MENU_ID_UM_SETTING_CS;
    aprc->general_aprc_cntx.title_str_id = STR_UM_CONVERSATION_BOX;
    aprc->general_aprc_cntx.title_icon_id = IMG_UM_ENTRY_SCRN_CAPTION;
    aprc->general_aprc_cntx.lsk_str_id = STR_GLOBAL_OK;
    aprc->general_aprc_cntx.lsk_icon_id = IMG_GLOBAL_OK;
    aprc->general_aprc_cntx.rsk_str_id = STR_GLOBAL_BACK;
    aprc->general_aprc_cntx.rsk_icon_id = IMG_GLOBAL_BACK;
    aprc->general_aprc_cntx.csk_icon_id = IMG_GLOBAL_COMMON_CSK;
    aprc->general_aprc_cntx.hilite_hdlr = mmi_um_ui_sh_setting_cs_hilite_hdlr;
    aprc->general_aprc_cntx.num_of_item = GetNumOfChild_Ext(MENU_ID_UM_SETTING_CS);
    aprc->general_aprc_cntx.entry_func = mmi_um_ui_sh_setting_cs_entry;
    aprc->general_aprc_cntx.exit_func = NULL;
    aprc->general_aprc_cntx.gui_buffer = NULL;
    aprc->general_aprc_cntx.key_hdlr.lsk_hdlr = mmi_um_ui_sh_setting_cs_lsk_hdlr;
    aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = mmi_um_ui_sh_rsk_hdlr;
    aprc->general_aprc_cntx.key_hdlr.csk_hdlr = mmi_um_ui_sh_setting_cs_lsk_hdlr;
    aprc->general_aprc_cntx.leave_proc = mmi_um_ui_sh_leave_proc;
    /* Set the highlight */
    ReadValue(NVRAM_UM_CONVERSATION_BOX_SETTING, &select, DS_BYTE, &error);
    if (0 != select && 1 != select)
    {
        /* Value is wrong, reset as default value */
    #ifdef __OP01__
        select = 0;
    #else
        select = 1;
    #endif
        WriteValue(NVRAM_UM_CONVERSATION_BOX_SETTING, &select, DS_BYTE, &error);
    }
    if (1 == select)
    {
        aprc->general_aprc_cntx.hilite_idx = GetIndexOfStringId_Ext(MENU_ID_UM_SETTING_CS, MENU_ID_UM_SETTING_CS_ON);
    }
    else if (0 == select)
    {
        aprc->general_aprc_cntx.hilite_idx = GetIndexOfStringId_Ext(MENU_ID_UM_SETTING_CS, MENU_ID_UM_SETTING_CS_OFF);
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* Specified context */
    /* Construct the menu item strings */
    GetSequenceStringIds_Ext(MENU_ID_UM_SETTING_CS, str_item_list);
    for (i = 0 ; i < aprc->general_aprc_cntx.num_of_item ; i++)
    {
        mmi_ucs2cpy((CHAR*)subMenuData[i], (CHAR*)get_string((MMI_ID_TYPE)str_item_list[i]));
    }
    aprc->list_of_items = subMenuDataPtrs;
    scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_cs_hilite_hdlr
 * DESCRIPTION
 *  Highlight handler for conversation box setting screen
 *
 * PARAMETERS
 *  index           [IN]: Highlighed index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_cs_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    scrn_cntx->screen_hdlr.hilite_info.index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_cs_lsk_hdlr
 * DESCRIPTION
 *  Left soft key handler for conversation box setting screen.
 *  Use Menu cui to display the option menu
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_cs_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 select = 0;
    S16 error;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    if (MENU_ID_UM_SETTING_CS_ON == GetSeqItemId_Ext(MENU_ID_UM_SETTING_CS, scrn_cntx->screen_hdlr.hilite_info.index))
    {
        select = 1;
    }
    else if (MENU_ID_UM_SETTING_CS_OFF == GetSeqItemId_Ext(MENU_ID_UM_SETTING_CS, scrn_cntx->screen_hdlr.hilite_info.index))
    {
        select = 0;
    }
    else
    {
        MMI_ASSERT(0);
    }
    /* write to the NVRAM */
    WriteValue(NVRAM_UM_CONVERSATION_BOX_SETTING, &select, DS_BYTE, &error);

    /* Display a saved popup */
    mmi_popup_display_simple(
                        (WCHAR *)get_string(STR_GLOBAL_SAVED), 
                        MMI_EVENT_SUCCESS, 
                        scrn_cntx->group_id, 
                        NULL);
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */


#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_entry_prefer_sim_setting
 * DESCRIPTION
 *  Entry the prefer_sim setting menu
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_entry_prefer_sim_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the current setting screen context */
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    scrn_id = mmi_um_ui_if_entry_setting_prefer_sim(0, scrn_cntx->group_id, MMI_FALSE);
    mmi_um_ui_ut_send_init_event(scrn_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_if_entry_setting_prefer_sim
 * DESCRIPTION
 *  A entry function for prefer setting
 *  If parent screen id = 0, it means there is no any parent.
 *
 * PARAMETERS
 *  parent_scrn_id          [IN]: Parent screen id
 *  parent_grp_id           [IN]: Parent group id
 *  new_grp                 [IN]: Create new group flag. (MMI_TRUE: create new)
 *  
 * RETURNS
 *  The created screen id
 *****************************************************************************/
U16 mmi_um_ui_if_entry_setting_prefer_sim(U16 parent_scrn_id, MMI_ID parent_grp_id, MMI_BOOL new_grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_setting_struct setting;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&setting, 0, sizeof(mmi_um_ui_cc_scrn_cntx_setting_struct));

    setting.scrn_id = mmi_um_ui_ut_create_scrn_id();
    setting.parent_scrn_id = parent_scrn_id;
    setting.disp_scrn_id = SCR_ID_UM_PREFER_SIM_SETTING;
    
    /* Set appearance */
    setting.aprc_type = MMI_UM_UI_SCRN_TYPE_PREFER_SIM_SETTING;
    
    /* Set screen handler */
    setting.event_hdlr = mmi_um_ui_sh_setting_prefer_sim_evt_hdlr;
    setting.folder.msg_box_type = SRV_UM_MSG_BOX_NONE;
    setting.folder.msg_type = g_um_ui_p->setting.support_msg_type;
    setting.folder.sim_id = SRV_UM_SIM_ALL;

    /* Set screen group */
    setting.new_grp = new_grp;
    setting.parent_group_id = parent_grp_id;

    result = mmi_um_ui_cc_create_scrn_cntx(&setting, mmi_um_ui_sh_setting_prefer_sim_init);

    MMI_ASSERT(result == MMI_TRUE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_IF_ENTRY_SETTING_CS, setting.scrn_id);

    return setting.scrn_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_prefer_sim_init
 * DESCRIPTION
 *  Initialize the conversation box setting screen variable. It shall 
 *  trigger the fsm initial function to initialize the fsm context.
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  setting                 [IN]: Setting
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_setting_prefer_sim_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    
    /* FSM initialize */
    
    /* Appearance initialize */
    mmi_um_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_um_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;
    scrn_cntx->screen_hdlr.scrn_data = setting->scrn_data;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_cs_evt_hdlr
 * DESCRIPTION
 *  The conversation box setting selection menu.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_setting_prefer_sim_evt_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        {
            mmi_um_ui_sh_create(mmi_um_ui_sh_setting_prefer_sim_entry, scrn_cntx);
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_cs_entry
 * DESCRIPTION
 *  Entry the conversation box setting screen.
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_prefer_sim_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_sim_enum prefer_sim;
    U16 i;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_cs_setting_struct *aprc;
    U16 str_item_list[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.cs_setting);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* General context */
    aprc->general_aprc_cntx.grp_id = scrn_cntx->group_id;
    aprc->general_aprc_cntx.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
    aprc->general_aprc_cntx.menu_item_id = MENU_ID_UM_SETTING_PREFER_SIM;
    aprc->general_aprc_cntx.title_str_id = STR_UM_PREFER_SIM;
    aprc->general_aprc_cntx.title_icon_id = IMG_UM_ENTRY_SCRN_CAPTION;
    aprc->general_aprc_cntx.lsk_str_id = STR_GLOBAL_OK;
    aprc->general_aprc_cntx.lsk_icon_id = IMG_GLOBAL_OK;
    aprc->general_aprc_cntx.rsk_str_id = STR_GLOBAL_BACK;
    aprc->general_aprc_cntx.rsk_icon_id = IMG_GLOBAL_BACK;
    aprc->general_aprc_cntx.csk_icon_id = IMG_GLOBAL_COMMON_CSK;
    aprc->general_aprc_cntx.hilite_hdlr = mmi_um_ui_sh_setting_prefer_sim_hilite_hdlr;
    aprc->general_aprc_cntx.num_of_item = GetNumOfChild_Ext(MENU_ID_UM_SETTING_PREFER_SIM);
    aprc->general_aprc_cntx.entry_func = mmi_um_ui_sh_setting_prefer_sim_entry;
    aprc->general_aprc_cntx.exit_func = NULL;
    aprc->general_aprc_cntx.gui_buffer = NULL;
    aprc->general_aprc_cntx.key_hdlr.lsk_hdlr = mmi_um_ui_sh_setting_prefer_sim_lsk_hdlr;
    aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = mmi_um_ui_sh_rsk_hdlr;
    aprc->general_aprc_cntx.key_hdlr.csk_hdlr = mmi_um_ui_sh_setting_prefer_sim_lsk_hdlr;
    aprc->general_aprc_cntx.leave_proc = mmi_um_ui_sh_leave_proc;
    /* Set the highlight */
    prefer_sim = srv_um_get_prefer_sim();
    switch (prefer_sim)
    {
        case SRV_UM_SIM_UNCLASSIFIED :
        {
            aprc->general_aprc_cntx.hilite_idx = 0;
            break;
        }
        case SRV_UM_SIM_GSM_SIM1:
        {
            aprc->general_aprc_cntx.hilite_idx = 1;
            break;
        }
        
        case SRV_UM_SIM_GSM_SIM2:
        {
            aprc->general_aprc_cntx.hilite_idx = 2;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
        }
    }

    /* Specified context */
    /* Construct the menu item strings */
    GetSequenceStringIds_Ext(MENU_ID_UM_SETTING_PREFER_SIM, str_item_list);
    for (i = 0 ; i < aprc->general_aprc_cntx.num_of_item ; i++)
    {
        mmi_ucs2cpy((S8*)subMenuData[i], (S8*)get_string((MMI_ID_TYPE)str_item_list[i]));
    }
    aprc->list_of_items = subMenuDataPtrs;
    scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_cs_hilite_hdlr
 * DESCRIPTION
 *  Highlight handler for conversation box setting screen
 *
 * PARAMETERS
 *  index           [IN]: Highlighed index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_prefer_sim_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    scrn_cntx->screen_hdlr.hilite_info.index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_setting_cs_lsk_hdlr
 * DESCRIPTION
 *  Left soft key handler for conversation box setting screen.
 *  Use Menu cui to display the option menu
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_setting_prefer_sim_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_sim_enum prefer_sim = SRV_UM_SIM_UNCLASSIFIED;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    switch (scrn_cntx->screen_hdlr.hilite_info.index)
    {
        case  0:
        {
            prefer_sim = SRV_UM_SIM_UNCLASSIFIED;
            break;
        }
        case 1:
        {
            prefer_sim = SRV_UM_SIM_GSM_SIM1;
            break;
        }
        
        case 2:
        {
            prefer_sim = SRV_UM_SIM_GSM_SIM2;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
        }
    }
    srv_um_set_prefer_sim(prefer_sim);
    
    /* Display a saved popup */
    mmi_popup_display_simple(
                        (WCHAR *)get_string(STR_GLOBAL_SAVED), 
                        MMI_EVENT_SUCCESS, 
                        scrn_cntx->group_id, 
                        NULL);
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
}
#endif /* (defined(__OP01__) &&  (MMI_MAX_SIM_NUM >= 2))) */

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_process_init
 * DESCRIPTION
 *  Initialize the process screen varialbe. It shall trigger the fsm initial
 *  function to initialize the fsm context.
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  setting                 [IN]: Setting
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_process_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
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
    return mmi_um_ui_sh_non_fsm_init(scrn_cntx, setting);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_process_event_hdlr
 * DESCRIPTION
 *  The processing screen.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_process_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        {
            mmi_um_ui_sh_create(mmi_um_ui_sh_process_entry, scrn_cntx);
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
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
        #endif
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_process_entry
 * DESCRIPTION
 *  Entry the process screen.
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_process_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_enum parent_support_type;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_loading_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.loading);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* For popup, it should turn on backlight first */
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    /* General context */
    aprc->general_aprc_cntx.grp_id = scrn_cntx->group_id;
    aprc->general_aprc_cntx.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
    
    /* Check if ready of service */
    parent_support_type = mmi_um_ui_cc_get_support_msg_type_by_scrn_id(scrn_cntx->parent_scrn_id);
    if (srv_um_check_ready_type(parent_support_type))
    {
        /* ready */
        aprc->scrn_effect = MMI_UM_UI_BLOCK_SLIDE_SHOW;
    }
    else
    {
        /* not_ready */
        aprc->general_aprc_cntx.rsk_str_id = STR_GLOBAL_CANCEL;
        aprc->general_aprc_cntx.rsk_icon_id = IMG_GLOBAL_BACK;
        aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = mmi_um_ui_sh_process_rsk_hdlr;
    }
    aprc->general_aprc_cntx.entry_func = mmi_um_ui_sh_process_entry;
    aprc->general_aprc_cntx.leave_proc = mmi_um_ui_sh_leave_proc;

    /* Specified context */
    aprc->msg_icon_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
    /* Deleting or Moving */
    aprc->msg_str_id = STR_GLOBAL_LOADING;
    
    scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_process_rsk_hdlr
 * DESCRIPTION
 *  RSK handler for processing screen
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_process_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Delete parent screen */
    mmi_um_ui_ut_del_relative_scrn(&(scrn_cntx->parent_scrn_id));

    /* Delete itself */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_process_clean_rsk_hdlr
 * DESCRIPTION
 *  Clean RSK handler for processing screen
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_process_clean_rsk_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* General context */
    scrn_cntx->aprc.redraw_func(&aprc_union, scrn_cntx->aprc.st_type, MMI_UM_UI_APRC_REDRAW_KEY);
}


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_entry
 * DESCRIPTION
 *  Entry conversation box to display the current screen.
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_item;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_cs_folder_struct *aprc;
    mmi_um_entry_folder_evt_struct entry_folder_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.cs_folder);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* set the number of items */
    num_item = mmi_um_ui_sh_general_folder_get_msg_num(scrn_cntx);
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    /* if data list is NULL, it means FSM does not have the correct message number info. */
    if (NULL != data_list)
    {
        scrn_cntx->screen_hdlr.num_of_item = num_item;
        /* search the specified highlight index based on the highlight thread id */
        if (NULL != data_list)
        {
            for (i = 0; i < num_item; i++)
            {
                if (((srv_um_thread_id_struct *)data_list->list)[i].type == scrn_cntx->screen_hdlr.hilite_info.thrd_id.type &&
                    ((srv_um_thread_id_struct *)data_list->list)[i].value == scrn_cntx->screen_hdlr.hilite_info.thrd_id.value)
                {
                    scrn_cntx->screen_hdlr.hilite_info.index = i;
                    break;
                }
            }
        }
        
        /* error handling for highlight */
        if (scrn_cntx->screen_hdlr.hilite_info.index >= num_item &&
            num_item != 0)
        {
            /* highlight to last one */
            scrn_cntx->screen_hdlr.hilite_info.index = num_item - 1;
        }
    }

    /* set general context */
    aprc->general_aprc_cntx.grp_id = scrn_cntx->group_id;
    aprc->general_aprc_cntx.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
    aprc->general_aprc_cntx.title_str_id = STR_UM_CONVERSATION_BOX;
    aprc->general_aprc_cntx.title_icon_id = IMG_UM_ENTRY_SCRN_CAPTION;
    /* If there is no message, the lsk string should not display */
    if (0 != scrn_cntx->screen_hdlr.num_of_item)
    {
        aprc->general_aprc_cntx.lsk_str_id = STR_GLOBAL_OPTIONS;
        aprc->general_aprc_cntx.lsk_icon_id = IMG_GLOBAL_OPTIONS;
        aprc->general_aprc_cntx.csk_icon_id = IMG_GLOBAL_COMMON_CSK;
    #ifdef __MMI_UM_DIAL_FROM_FOLDER__
        aprc->general_aprc_cntx.key_hdlr.special_key_code = KEY_SEND;
        aprc->general_aprc_cntx.key_hdlr.key_hdlr = mmi_um_ui_sh_cs_send_key_pre_confirm;
    #endif /* __MMI_UM_DIAL_FROM_FOLDER__ */
    }
    aprc->general_aprc_cntx.rsk_str_id = STR_GLOBAL_BACK;
    aprc->general_aprc_cntx.rsk_icon_id = IMG_GLOBAL_BACK;
    aprc->general_aprc_cntx.hilite_hdlr = mmi_um_ui_sh_cs_hilite_hdlr;
    aprc->general_aprc_cntx.hilite_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    aprc->general_aprc_cntx.num_of_item = scrn_cntx->screen_hdlr.num_of_item;
    aprc->general_aprc_cntx.entry_func = mmi_um_ui_sh_cs_entry;
    aprc->general_aprc_cntx.exit_func = mmi_um_ui_sh_cs_exit;
    /* If entry empty screen, the lsk and csk should be disabled */
    if (0 != scrn_cntx->screen_hdlr.num_of_item)
    {
        aprc->general_aprc_cntx.key_hdlr.lsk_hdlr = mmi_um_ui_sh_cs_lsk_hdlr;
        aprc->general_aprc_cntx.key_hdlr.csk_hdlr = mmi_um_ui_sh_cs_csk_hdlr;
    #ifdef __MMI_UM_DIAL_FROM_FOLDER__
        aprc->general_aprc_cntx.key_hdlr.special_key_code = KEY_SEND;
        aprc->general_aprc_cntx.key_hdlr.key_hdlr = mmi_um_ui_sh_cs_send_key_pre_confirm;
    #endif /* __MMI_UM_DIAL_FROM_FOLDER__ */
    }
    aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = mmi_um_ui_sh_cs_rsk_hdlr;
    aprc->general_aprc_cntx.leave_proc = mmi_um_ui_sh_general_folder_leave_proc;

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_um_ui_sh_cs_set_toolbar_info(&(aprc->general_aprc_cntx.tb_hdlr));
#endif /* __MMI_ICON_BAR_SUPPORT__ */
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    aprc->general_aprc_cntx.intuitive_cmd_cb_func = mmi_um_ui_sh_cs_intuitive_cmd_cb;
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    /* Specified context */
    aprc->folder_style = CAT263_DISPLAY_ALL;
    aprc->get_item_cb = mmi_um_ui_sh_get_async_item;
    aprc->get_item_hint_cb = NULL;
    aprc->hilite_notify_cb = mmi_um_ui_sh_cs_notify_highlight;
    scrn_cntx->screen_hdlr.is_scrn_displayed = scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);

    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
    {
        return;
    }

    
    /* After drawing, the child should be removed */
    mmi_um_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
    
    /* Due to the category usage, it should check the screen is displayed or not */
    if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE)
    {
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
    }

    /* global setting reset */
    if (MMI_TRUE == scrn_cntx->screen_hdlr.is_scrn_displayed)
    {
        /* Send the event out */
        MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_UM_ENTRY_FOLDER);
        entry_folder_evt.is_entry = MMI_TRUE;
        entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
        entry_folder_evt.um_user_data = (void *)scrn_cntx;
        MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_exit
 * DESCRIPTION
 *  Exit conversation box handler
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_exit(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_entry_folder_evt_struct entry_folder_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;

    /* Send the event out */
    MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_UM_ENTRY_FOLDER);
    entry_folder_evt.is_entry = MMI_FALSE;
    entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
    entry_folder_evt.um_user_data = (void *)scrn_cntx;
    MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_hilite_hdlr
 * DESCRIPTION
 *  Highlight handler for conversation box
 *
 * PARAMETERS
 *  index           [IN]: Highlighed index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;
#ifdef __MMI_FTE_SUPPORT__
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_cs_folder_struct *aprc;
#endif /* __MMI_FTE_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);

    /* Tricky for category bugs */
    if (index >= data_list->msg_number)
    {
        return;
    }
    /* Tricky for category bugs */

    /* Set highlight message id & type */
    scrn_cntx->screen_hdlr.hilite_info.index = index;
    scrn_cntx->screen_hdlr.hilite_info.thrd_id.type = ((srv_um_thread_id_struct *)data_list->list)[index].type;
    scrn_cntx->screen_hdlr.hilite_info.thrd_id.value = ((srv_um_thread_id_struct *)data_list->list)[index].value;

#ifdef __MMI_ICON_BAR_SUPPORT__
    /* Check each toolbar icon status */
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.cs_folder);
    /* set status */
    mmi_um_ui_sh_cs_set_toolbar_status(&(aprc->general_aprc_cntx.tb_hdlr));
    scrn_cntx->aprc.redraw_func(&aprc_union, scrn_cntx->aprc.st_type, MMI_UM_UI_APRC_REDRAW_TB_STATUS);
#endif /* __MMI_ICON_BAR_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_lsk_hdlr
 * DESCRIPTION
 *  Left soft key handler for conversation box.
 *  Use Menu cui to display the option menu
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID opt_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);

    /* If during updating data, lsk should not activate any action */
    if (MMI_UM_UI_FSM_EF_UPDATE_DATA == mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)))
    {
        return;
    }

    /* create group */
    opt_grp_id = mmi_frm_group_create(
                            scrn_cntx->group_id, 
                            GRP_ID_AUTO_GEN, 
                            mmi_um_ui_sh_cs_opt_proc, 
                            (void*) scrn_cntx);
    mmi_frm_group_enter(opt_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    opt_grp_id = cui_menu_create(
                            opt_grp_id, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_OPTION, 
                            MENU_ID_UM_CS_BOX_OPT, 
                            MMI_FALSE, 
                            NULL);
    /* Set default string/icon */
    cui_menu_set_default_title(
            opt_grp_id, 
            (WCHAR*)GetString(STR_GLOBAL_OPTIONS), 
            (UI_image_type)GetImage(IMG_UM_ENTRY_SCRN_CAPTION));
    cui_menu_run(opt_grp_id);
    scrn_cntx->child_group_id = opt_grp_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_rsk_hdlr
 * DESCRIPTION
 *  Right soft key handler for conversation box.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_rsk_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_csk_hdlr
 * DESCRIPTION
 *  Center soft key handler for conversation box.
 *  Entry the highlighed thread message screen
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;
    U16 highlight_idx;
    srv_um_list_filter_struct list_filter;
    srv_um_list_cntx_struct *data_list;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Set the list filter by thread id */
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);

    /* If during updating data, lsk should not activate any action */
    if (MMI_UM_UI_FSM_EF_UPDATE_DATA == mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)))
    {
        return;
    }

    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    memset(&list_filter, 0, sizeof(srv_um_list_filter_struct));
    list_filter.thread_id.type = ((srv_um_thread_id_struct *)data_list->list)[highlight_idx].type;
    list_filter.thread_id.value = ((srv_um_thread_id_struct *)data_list->list)[highlight_idx].value;

    /* Launch the thread screen */
    scrn_id = mmi_um_ui_if_entry_thread_msg(0, &list_filter, scrn_cntx->group_id, MMI_FALSE);
    mmi_um_ui_ut_send_init_event(scrn_id);

    /* Reset the data list, it will cause the option list getting the list fail */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);
}


#ifdef __MMI_UM_DIAL_FROM_FOLDER__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_send_key_pre_confirm
 * DESCRIPTION
 *  The pre-confirm for conversation box send key handler
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_send_key_pre_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 highlight_idx;
    U8 *popup_str;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    srv_um_msg_info_struct **msg_detail_info;
    srv_um_list_cntx_struct *data_list;
    U16 *phb_name;
    mmi_confirm_property_struct confirm_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* If during updating data, send key should not activate any action */
    if (MMI_UM_UI_FSM_EF_UPDATE_DATA == mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)))
    {
        return;
    }

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    result = fsm->get_msg_info(scrn_cntx->scrn_id, highlight_idx, 1, &msg_detail_info, NULL);
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));

    /* it should get the detail information */
    MMI_ASSERT(result != MMI_FALSE);
    MMI_ASSERT(data_list != NULL);

    /* check if phone number & there is a phone number */
    if (SRV_UM_ADDR_PHONE_NUMBER == msg_detail_info[0]->address_type &&
        msg_detail_info[0]->address_length > 0)
    {
        popup_str = OslMalloc(sizeof(U8)*((MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH));
        phb_name = OslMalloc(sizeof(U16)*((MMI_PHB_NAME_LENGTH + 1) * ENCODING_LENGTH));

        memset(popup_str, 0, sizeof(popup_str));
        /* concate the popup string */
        mmi_ucs2cpy((CHAR *)popup_str, (CHAR *)get_string(STR_GLOBAL_DIAL));
        mmi_ucs2cat((CHAR *)popup_str, (CHAR *)GUI_NEWLINE_STRING);

        /* concate the number / contact name */
        memset(phb_name, 0, sizeof(phb_name));
        /* Get the name by phb API. If not found or cause error, PHB will help to copy the number to the buffer */
        srv_phb_get_name_by_number((U16 *)msg_detail_info[0]->address, phb_name, MMI_PHB_NAME_LENGTH);

        /* Could not find */
        if (0 == mmi_ucs2strlen((CHAR*)phb_name))
        {
            /* use the longest name, the address length may be larger than the phb name length */
            mmi_ucs2ncat((CHAR *)popup_str, (CHAR *)msg_detail_info[0]->address, msg_detail_info[0]->address_length);
        }
        else
        {
            mmi_ucs2ncat((CHAR *)popup_str, (CHAR *)phb_name, mmi_ucs2strlen((CHAR *)phb_name));
        }
        /* concate the question mark "?" */
        mmi_ucs2cat((CHAR *)popup_str, (CHAR *)get_string(STR_UM_QUESTION_MARK));
        /* end of string */
        memset(&confirm_param, 0, sizeof(mmi_confirm_property_struct));
        mmi_confirm_property_init(&confirm_param, CNFM_TYPE_YESNO);
        mmi_um_ui_sh_set_confirm_param(&confirm_param, scrn_cntx, MMI_UM_UI_SH_CF_CS_SEND_KEY);
        /* Display confirm, lack csk handler */
        scrn_cntx->screen_hdlr.cf_grp_id = mmi_confirm_display(
                                                    (WCHAR *)popup_str, 
                                                    MMI_EVENT_QUERY, 
                                                    &confirm_param);
        OslMfree(popup_str);
        OslMfree(phb_name);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_send_key_confirm_yes_hdlr
 * DESCRIPTION
 *  General center send key make a call handler for conversation box.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_cs_send_key_confirm_yes_hdlr(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 highlight_idx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    srv_um_msg_info_struct **msg_detail_info;
    srv_um_list_cntx_struct *data_list;
    mmi_ucm_make_call_para_struct *make_call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    result = fsm->get_msg_info(scrn_cntx->scrn_id, highlight_idx, 1, &msg_detail_info, NULL);
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));

    /* it should get the detail information */
    MMI_ASSERT(result != MMI_FALSE);
    MMI_ASSERT(data_list != NULL);

    /* Make a call */
    make_call_para = OslMalloc(sizeof(mmi_ucm_make_call_para_struct));

    mmi_ucm_init_call_para_for_sendkey(make_call_para);
    make_call_para->ucs2_num_uri = (U16 *) msg_detail_info[0]->address;
    mmi_ucm_call_launch(0, make_call_para);

    OslMfree(make_call_para);
    make_call_para = NULL;

    return MMI_RET_OK;
}
#endif /* __MMI_UM_DIAL_FROM_FOLDER__ */


#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_set_toolbar_info
 * DESCRIPTION
 *  The conversation box set toolbar information.
 *      String, icon, callback
 *
 * PARAMETERS
 *  tb_info             [OUT]: Toolbar information
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_set_toolbar_info(mmi_um_ui_tb_handler_struct *tb_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != tb_info);

    memset(tb_info, 0, sizeof(mmi_um_ui_tb_handler_struct));
    for (i = 0 ; i < MMI_UM_UI_MAX_TB_ICON ; i++)
    {
        if (NULL == g_um_ui_sh_tb_action_table[MMI_UM_UI_TB_FOLDER_CONVERSATION][i])
        {
            break;
        }
        /* Update the number of toolbar */
        tb_info->num_of_toolbar++;
        /* Set icon */
        tb_info->body[i] = get_image(g_um_ui_sh_tb_icon_table[MMI_UM_UI_TB_FOLDER_CONVERSATION][i]);
        tb_info->body_disable[i] = get_image(g_um_ui_sh_tb_disable_icon_table[MMI_UM_UI_TB_FOLDER_CONVERSATION][i]);
        /* Set string */
        tb_info->hint[i] = (PU8)get_string(g_um_ui_sh_tb_str_table[MMI_UM_UI_TB_FOLDER_CONVERSATION][i]);
    }
    /* Set cb function */
    tb_info->callback = mmi_um_ui_sh_cs_tb_cb;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_set_toolbar_status
 * DESCRIPTION
 *  The conversation box to set each toolbar status.
 *  (enable/disable)
 *
 * PARAMETERS
 *  tb_info             [OUT]: Toolbar information
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_set_toolbar_status(mmi_um_ui_tb_handler_struct *tb_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != tb_info);

    memset(tb_info, 0, sizeof(mmi_um_ui_tb_handler_struct));
    for (i = 0 ; i < MMI_UM_UI_MAX_TB_ICON ; i++)
    {
        /* Check the status by the global toolbar checking table */
        if (NULL == g_um_ui_sh_tb_check_action_table[MMI_UM_UI_TB_FOLDER_CONVERSATION][i])
        {
            break;
        }
        /* Update the number of toolbar */
        tb_info->num_of_toolbar++;
        /* Set the status */
        tb_info->status[i] = (*g_um_ui_sh_tb_check_action_table[MMI_UM_UI_TB_FOLDER_CONVERSATION][i])(SRV_UM_MSG_NONE, 0);
    }
}




/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_tb_cb
 * DESCRIPTION
 *  In toolbar, the toolbar callback registered in FW
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_tb_cb(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_ui_sh_tb_action_table[MMI_UM_UI_TB_FOLDER_CONVERSATION][index]();
}
#endif /* __MMI_ICON_BAR_SUPPORT__ */


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_intuitive_cmd_cb
 * DESCRIPTION
 *  In FTE, it should support intuitive command. (tap to selecte)
 *
 * PARAMETERS
 *  tap_type            [IN]: the tap type from FW
 *  index               [IN]: The tap item of index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_intuitive_cmd_cb(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 highlight_idx;
    U16 scrn_id;
    srv_um_list_filter_struct list_filter;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ENUM_TAP_ON_NONHIGHLIGHTED_ITEM == tap_type)
    {
        /* only change highlight, do nothing */
        return;
    }

    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);

    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;

    /* entry thread message, it should pass the thread id to child */
    /* Set the list filter by thread id */
    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    memset(&list_filter, 0, sizeof(srv_um_list_filter_struct));
    list_filter.thread_id.type = ((srv_um_thread_id_struct *)data_list->list)[highlight_idx].type;
    list_filter.thread_id.value = ((srv_um_thread_id_struct *)data_list->list)[highlight_idx].value;

    /* Launch the thread screen */
    scrn_id = mmi_um_ui_if_entry_thread_msg(0, &list_filter, scrn_cntx->group_id, MMI_FALSE);
    mmi_um_ui_ut_send_init_event(scrn_id);

    /* Reset the data list */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);

    /* Reset cache in the Service level */
    srv_um_clear_msg_info_cache();
}
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_notify_highlight
 * DESCRIPTION
 *  The notify highlight index function.
 *
 * PARAMETERS
 *  index               [IN]: the highlight index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_notify_highlight(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    
    if (data_list != NULL)
    {
        /* Set highlight message id & type */
        scrn_cntx->screen_hdlr.hilite_info.index = index;
        scrn_cntx->screen_hdlr.hilite_info.thrd_id.type = ((srv_um_thread_id_struct *)data_list->list)[index].type;
        scrn_cntx->screen_hdlr.hilite_info.thrd_id.value = ((srv_um_thread_id_struct *)data_list->list)[index].value;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_opt_proc
 * DESCRIPTION
 *  Option proc of menu cui.
 *  It needs to handle the menu cui event like entry, select and exit.
 *
 * PARAMETERS
 *  evt                 [IN]: event structure pointer
 *  
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_cs_opt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    cui_menu_event_struct *menu_evt;
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    ret = MMI_RET_OK;
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            ret = mmi_um_ui_sh_cs_opt_list_entry_hdlr(evt);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            ret = mmi_um_ui_sh_cs_opt_item_select_hdlr(evt);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            scrn_cntx->child_group_id = 0;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_opt_list_entry_hdlr
 * DESCRIPTION
 *  List entry proc of menu cui.
 *  Seperate each event to let function more modulaized.
 *  The sub-function of mmi_um_ui_sh_cs_opt_proc.
 *
 * PARAMETERS
 *  evt                 [IN]: event structure pointer
 *  
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_cs_opt_list_entry_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    cui_menu_event_struct *menu_evt;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);

    ret = MMI_RET_OK;
    switch (menu_evt->parent_menu_id)
    {
        case MENU_ID_UM_CS_BOX_OPT:
        {
            U16 highlight_idx;
            srv_um_msg_info_struct **msg_detail_info;
            mmi_um_ui_fsm_entry_folder_struct *fsm;
            U16 phb_name[MMI_PHB_NAME_LENGTH * ENCODING_LENGTH];

            fsm = &(scrn_cntx->fsm.cntx.fsm_entry_folder);
            highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
            fsm->get_msg_info(scrn_cntx->scrn_id, highlight_idx, 1, &msg_detail_info, NULL);
            /* check the number to see if the call menu item status */
            if (0 == msg_detail_info[0]->address_length ||
                SRV_UM_ADDR_PHONE_NUMBER != msg_detail_info[0]->address_type)
            {
                /* no number or other type address, hide the call menu item */
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_CS_BOX_OPT_CALL, MMI_TRUE);
            }
            /* check the number to see if the reply menu item status */

			/* reply by MMS */
            if (0 == msg_detail_info[0]->address_length ||
                (SRV_UM_ADDR_PHONE_NUMBER != msg_detail_info[0]->address_type 
                 && SRV_UM_ADDR_EMAIL_ADDRESS != msg_detail_info[0]->address_type))
            {
                /* no number or non-phone/non-email address, hide the reply menu item */
			#if (defined (__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__))
				cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_CS_BOX_OPT_REPLY_BY_MMS, MMI_TRUE);
			#else
				cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_CS_BOX_OPT_REPLY, MMI_TRUE);
			#endif
            }
			/* reply by SMS */
		#if ( !defined(__MMI_UNIFIED_COMPOSER__))
			if (0 == msg_detail_info[0]->address_length ||
				((SRV_UM_ADDR_PHONE_NUMBER != msg_detail_info[0]->address_type)
			#if ( defined (__MMI_MESSAGES_SMS_EMAIL__))
					 && SRV_UM_ADDR_EMAIL_ADDRESS != msg_detail_info[0]->address_type
			#endif
				))
			{
			/* with email in SMS, can reply by SMS */
			#if (defined (__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__))
				cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_CS_BOX_OPT_REPLY_BY_SMS, MMI_TRUE);
			#else
				cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_CS_BOX_OPT_REPLY, MMI_TRUE);
			#endif
			}
		#endif
            /* check the number to see if the phb menu item status */
            if (0 == msg_detail_info[0]->address_length)
            {
                /* no number, hide the add to phb menu item */
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_CS_BOX_OPT_ADD_TO_PHB, MMI_TRUE);
            }
            else
            {
                if (SRV_UM_ADDR_PHONE_NUMBER == msg_detail_info[0]->address_type)
                {
                    /* Get the name by phb API. If not found or cause error, PHB will help to copy the number to the buffer */
                    srv_phb_get_name_by_number((U16 *)msg_detail_info[0]->address, phb_name, MMI_PHB_NAME_LENGTH);
                    /* find */
                    if (0 != mmi_ucs2strlen((CHAR*)phb_name))
                    {
                       cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_CS_BOX_OPT_ADD_TO_PHB, MMI_TRUE);
                    }
                }
                else if (SRV_UM_ADDR_EMAIL_ADDRESS == msg_detail_info[0]->address_type)
                {
                    /* Do nothing */
                }
                else
                {
                    /* no number, hide the add to phb menu item */
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_CS_BOX_OPT_ADD_TO_PHB, MMI_TRUE);
                }
            }
            #ifndef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            cui_menu_set_item_hidden(menu_evt->sender_id, 
                                     MENU_ID_UM_CS_BOX_OPT_MS, 
                                     MMI_TRUE);
            #else
            cui_menu_set_item_hidden(menu_evt->sender_id, 
                                     MENU_ID_UM_MS_DELETE_OPT, 
                                     MMI_TRUE);
            #endif

            break;
        }
    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        case MENU_ID_UM_CS_BOX_OPT_SORT_BY:
        {
            srv_um_list_filter_struct *list_filter;

            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_UM_SORT_BY_RECIPIENT, (WCHAR *)get_string(STR_UM_SORT_BY_SENDER_RECIPIENT_NAME));

            cui_menu_set_currlist_title(
                    menu_evt->sender_id, 
                    (WCHAR *)get_string(STR_GLOBAL_SORT_BY), 
                    (UI_image_type)get_image(GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID)));

            /* check the current sorting type to see if the sort type disable status */
            list_filter = mmi_um_ui_fsm_ef_get_list_filter_type(&(scrn_cntx->fsm));
            if (SRV_UM_LIST_IDX_TIMESTAMP == list_filter->idx_type)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_SORT_BY_TIME, MMI_TRUE);
            }
            else if (SRV_UM_LIST_IDX_ADDRESS == list_filter->idx_type)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UM_SORT_BY_RECIPIENT, MMI_TRUE);
            }
            else
            {
                /* should not entry here */
                MMI_ASSERT(0);
            }
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        /* case MENU_ID_UM_CS_BOX_OPT: */
        {
        }
    #endif
        default:
        {
            /* others, ignore */
            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_opt_item_select_hdlr
 * DESCRIPTION
 *  Item select proc of menu cui.
 *  Seperate each event to let function more modulaized.
 *  The sub-function of mmi_um_ui_sh_cs_opt_proc.
 *
 * PARAMETERS
 *  evt                 [IN]: event structure pointer
 *  
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_cs_opt_item_select_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 highlight_idx;
    mmi_ret ret;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    cui_menu_event_struct *menu_evt;
    srv_um_list_cntx_struct *data_list;
    srv_um_msg_info_struct **msg_detail_info;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    srv_um_mark_several_op_action_enum ms_action = SRV_UM_MARK_SEVERAL_OP_ACTION_NONE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);

    fsm = &(scrn_cntx->fsm.cntx.fsm_entry_folder);
    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    result = fsm->get_msg_info(scrn_cntx->scrn_id, highlight_idx, 1, &msg_detail_info, NULL);
    MMI_ASSERT(MMI_TRUE == result);

    ret = MMI_RET_OK;
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_UM_CS_BOX_OPT_VIEW:
        {
            U16 scrn_id;
            U16 highlight_idx;
            srv_um_list_filter_struct list_filter;

            /* entry thread message, it should pass the thread id to child */
            /* Set the list filter by thread id */
            highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
            memset(&list_filter, 0, sizeof(srv_um_list_filter_struct));
            list_filter.thread_id.type = ((srv_um_thread_id_struct *)data_list->list)[highlight_idx].type;
            list_filter.thread_id.value = ((srv_um_thread_id_struct *)data_list->list)[highlight_idx].value;

            /* Launch the thread screen */
            scrn_id = mmi_um_ui_if_entry_thread_msg(0, &list_filter, scrn_cntx->group_id, MMI_FALSE);
            mmi_um_ui_ut_send_init_event(scrn_id);

            /* Reset the data list, it will cause the option list getting the list fail */
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);
            break;
        }

#if (defined (__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__))
        case MENU_ID_UM_CS_BOX_OPT_REPLY_BY_SMS:
        {
            CHAR ascii_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
            mmi_sms_write_msg_para_struct sendData;
            memset(ascii_number, 0, sizeof(ascii_number));
            memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));
            mmi_ucs2_n_to_asc(ascii_number, (CHAR*)msg_detail_info[0]->address, MMI_PHB_NUMBER_LENGTH + 1);
            sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;
            sendData.ascii_addr = (U8*) ascii_number;
            mmi_sms_write_msg_lanch(0, &sendData);
            break;
        }
		case MENU_ID_UM_CS_BOX_OPT_REPLY_BY_MMS:
        {
            mms_address_insert_hdlr((CHAR*)msg_detail_info[0]->address);
            break;
        }
#else /* (defined (__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__)) */
        case MENU_ID_UM_CS_BOX_OPT_REPLY:
        {
        #ifdef __MMI_UNIFIED_COMPOSER__
            mmi_uc_entry_write_struct *data;
            mmi_uc_addr_struct *uc_addr;

            /* entry editor */
            data = OslMalloc(sizeof(mmi_uc_entry_write_struct));
            uc_addr = OslMalloc(sizeof(mmi_uc_addr_struct));
            memset(data, 0, sizeof(mmi_uc_entry_write_struct));
            memset(uc_addr, 0, sizeof(mmi_uc_addr_struct));
            uc_addr->previous = uc_addr->next = NULL;
            uc_addr->addr = (kal_uint8 *)msg_detail_info[0]->address;
            if (SRV_UM_ADDR_PHONE_NUMBER == msg_detail_info[0]->address_type)
            {
                uc_addr->type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
            }
            else if (SRV_UM_ADDR_EMAIL_ADDRESS == msg_detail_info[0]->address_type)
            {
                uc_addr->type = SRV_UC_ADDRESS_TYPE_EMAIL;
            }
            else
            {
                MMI_ASSERT(0);
            }
            uc_addr->group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
            data->addr = uc_addr;
            data->addr_num = 1;
            data->msg_type = SRV_UC_MSG_TYPE_SMS_PREFER;
            mmi_uc_entry_write_msg_with_content(SRV_UC_STATE_WRITE_NEW_MSG, data);

            OslMfree(data);
            OslMfree(uc_addr);
        #else /* __MMI_UNIFIED_COMPOSER__ */
        #ifndef __MMI_MMS_IN_UM__
            CHAR ascii_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
            mmi_sms_write_msg_para_struct sendData;
            memset(ascii_number, 0, sizeof(ascii_number));
            memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));
            mmi_ucs2_n_to_asc(ascii_number, (CHAR *)msg_detail_info[0]->address, MMI_PHB_NUMBER_LENGTH + 1);
            sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;
            sendData.ascii_addr = (U8*) ascii_number;
            mmi_sms_write_msg_lanch(0, &sendData);
        #endif
        #endif /* __MMI_UNIFIED_COMPOSER__ */
            break;
        }
        
#endif /* (defined (__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__)) */
        case MENU_ID_UM_CS_BOX_OPT_CALL:
        {
            mmi_ucm_make_call_para_struct *make_call_para;

            /* Make a call */
            make_call_para = OslMalloc(sizeof(mmi_ucm_make_call_para_struct));

            mmi_ucm_init_call_para(make_call_para);
            make_call_para->ucs2_num_uri = (U16 *) msg_detail_info[0]->address;
            mmi_ucm_call_launch(0, make_call_para);
            OslMfree(make_call_para);
            break;
        }
        case MENU_ID_UM_CS_BOX_OPT_DELETE:
        {
            U8 *temp_str;
            mmi_confirm_property_struct confirm_param;

            temp_str = OslMalloc(sizeof(U8)*(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH);
            memset(temp_str, 0, sizeof(U8)*(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH);
            mmi_ucs2cpy((CHAR *)temp_str, (CHAR *)get_string(STR_GLOBAL_DELETE));
            mmi_ucs2cat((CHAR *)temp_str, (CHAR *)get_string(STR_UM_QUESTION_MARK));

            memset(&confirm_param, 0, sizeof(mmi_confirm_property_struct));
            mmi_confirm_property_init(&confirm_param, CNFM_TYPE_YESNO);
            mmi_um_ui_sh_set_confirm_param(&confirm_param, scrn_cntx, MMI_UM_UI_SH_CF_CS_OPT_DELETE);
            scrn_cntx->screen_hdlr.cf_grp_id = mmi_confirm_display(
                                                        (WCHAR *)temp_str, 
                                                        MMI_EVENT_QUERY, 
                                                        &confirm_param);
            OslMfree(temp_str);
            break;
        }
        case MENU_ID_UM_CS_BOX_OPT_DELETE_ALL:
        {
            U8 *temp_str;
            mmi_confirm_property_struct confirm_param;

            temp_str = OslMalloc(sizeof(U8)*(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH);
            memset(temp_str, 0, sizeof(U8)*(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH);
            mmi_ucs2cpy((CHAR *)temp_str, (CHAR *)get_string(STR_GLOBAL_DELETE_ALL));
            mmi_ucs2cat((CHAR *)temp_str, (CHAR *)get_string(STR_UM_QUESTION_MARK));

            mmi_confirm_property_init(&confirm_param, CNFM_TYPE_YESNO);
            mmi_um_ui_sh_set_confirm_param(&confirm_param, scrn_cntx, MMI_UM_UI_SH_CF_CS_OPT_DEL_ALL);
            scrn_cntx->screen_hdlr.cf_grp_id = mmi_confirm_display(
                                                        (WCHAR *)temp_str, 
                                                        MMI_EVENT_QUERY, 
                                                        &confirm_param);
            OslMfree(temp_str);
            break;
        }
        case MENU_ID_UM_CS_BOX_OPT_ADD_TO_PHB:
        {
            MMI_ID phb_grp_id;
            MMI_ID cui_parent_id;
            MMI_ID root_grp_id;

            /* Use PHB common ui */
            /* If there is no any address, this menu ite should be hided */
            if (0 == msg_detail_info[0]->address_length)
            {
                MMI_ASSERT(0);
            }
            /* create group */
            root_grp_id = mmi_um_ui_cc_get_root_grp_id(scrn_cntx->group_id);
            cui_parent_id = mmi_frm_group_create(
                                    root_grp_id, 
                                    GRP_ID_AUTO_GEN, 
                                    mmi_um_ui_sh_cs_phb_proc, 
                                    (void*) scrn_cntx);
            mmi_frm_group_enter(cui_parent_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
            phb_grp_id = cui_phb_save_contact_create(cui_parent_id);
            if (SRV_UM_ADDR_PHONE_NUMBER == msg_detail_info[0]->address_type)
            {
                cui_phb_save_contact_set_number(phb_grp_id, msg_detail_info[0]->address);
            }
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            else if (SRV_UM_ADDR_EMAIL_ADDRESS == msg_detail_info[0]->address_type)
            {
                cui_phb_save_contact_set_email(phb_grp_id, msg_detail_info[0]->address);
            }
        #endif /* __MMI_PHB_OPTIONAL_FIELD__ */
            else
            {
                MMI_ASSERT(0);
            }
            cui_phb_save_contact_run(phb_grp_id);
            break;
        }
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MENU_ID_UM_MS_DELETE_OPT:
        case MENU_ID_UM_MS_CS_BOX_OPT_DELETE_PRE:
        {
            ms_action = SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MENU_ID_UM_MS_CS_BOX_OPT_MOVE_TO_ARCH_PRE:
        if (ms_action == SRV_UM_MARK_SEVERAL_OP_ACTION_NONE)
        {
            ms_action = SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE;
        }
    #endif
        {
            U16 scrn_id;
            mmi_um_ui_sh_hilite_folder_info_struct hilite;
        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            srv_um_list_filter_struct *filter;
        #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */

            /* Reset the data list, it will cause the option list getting the list fail */
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);

            /* entry mark several */
            scrn_id = mmi_um_ui_if_entry_ms_conversation_box(0, scrn_cntx->group_id, MMI_FALSE);
            /* Set highlight */
            memset(&hilite, 0, sizeof(mmi_um_ui_sh_hilite_folder_info_struct));
            memcpy(&(hilite.hilite_info), &(scrn_cntx->screen_hdlr.hilite_info), sizeof(mmi_um_ui_sh_hilite_info_struct));
            memcpy(&(hilite.folder_info), &(scrn_cntx->screen_hdlr.folder_type), sizeof(srv_um_box_identity_struct));
            mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_HIGHLIGHT_CHANGE, &hilite);
            /* Set filter type */
        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            filter = mmi_um_ui_fsm_ef_get_list_filter_type(&(scrn_cntx->fsm));
            /* Set the sorting type */
            mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_SET_FILTER_TYPE, (void *)filter);
        #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
            mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_SET_MS_OP_TYPE, (void *)&ms_action);
        #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
            mmi_um_ui_ut_send_init_event(scrn_id);

            /* Reset the current folder highlight */
            memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_um_ui_sh_hilite_info_struct));
            break;
        }
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MENU_ID_UM_CS_BOX_OPT_MOVE_TO_ARCH:
        {
            U8 *temp_str;
            mmi_confirm_property_struct confirm_param;

            temp_str = OslMalloc(sizeof(U8)*(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH);
            memset(temp_str, 0, sizeof(U8)*(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH);
            mmi_ucs2cpy((CHAR *)temp_str, (CHAR *)get_string(STR_UM_MOVE_TO_ARCHIVE));
            mmi_ucs2cat((CHAR *)temp_str, (CHAR *)get_string(STR_UM_QUESTION_MARK));

            mmi_confirm_property_init(&confirm_param, CNFM_TYPE_YESNO);
            mmi_um_ui_sh_set_confirm_param(&confirm_param, scrn_cntx, MMI_UM_UI_SH_CF_CS_OPT_MOV2ARC);
            scrn_cntx->screen_hdlr.cf_grp_id = mmi_confirm_display(
                                                        (WCHAR *)temp_str, 
                                                        MMI_EVENT_QUERY, 
                                                        &confirm_param);
            OslMfree(temp_str);
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        case MENU_ID_UM_SORT_BY_TIME:
        {
            srv_um_list_filter_struct filter;
            srv_um_list_filter_struct *fsm_filter;

            /* Set as sorting by time */
            fsm_filter = mmi_um_ui_fsm_ef_get_list_filter_type(&(scrn_cntx->fsm));
            memcpy(&filter, fsm_filter, sizeof(srv_um_list_filter_struct));
            filter.idx_type = SRV_UM_LIST_IDX_TIMESTAMP;
            mmi_um_ui_fsm_ef_set_list_filter_type(&(scrn_cntx->fsm), filter);

            /* Special solution for reset highlight */
            scrn_cntx->screen_hdlr.hilite_info.index = 0;
            scrn_cntx->screen_hdlr.hilite_info.msg_id = 0;
            scrn_cntx->screen_hdlr.hilite_info.msg_type = SRV_UM_MSG_NONE;

            /* release the data list to update the list */
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);

            /* close menu cui */
            scrn_cntx->child_group_id = 0;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case MENU_ID_UM_SORT_BY_RECIPIENT:
        {
            srv_um_list_filter_struct filter;
            srv_um_list_filter_struct *fsm_filter;

            /* Set as sorting by recipient */
            fsm_filter = mmi_um_ui_fsm_ef_get_list_filter_type(&(scrn_cntx->fsm));
            memcpy(&filter, fsm_filter, sizeof(srv_um_list_filter_struct));
            filter.idx_type = SRV_UM_LIST_IDX_ADDRESS;
            mmi_um_ui_fsm_ef_set_list_filter_type(&(scrn_cntx->fsm), filter);

            /* Special solution for reset highlight */
            scrn_cntx->screen_hdlr.hilite_info.index = 0;
            scrn_cntx->screen_hdlr.hilite_info.msg_id = 0;
            scrn_cntx->screen_hdlr.hilite_info.msg_type = SRV_UM_MSG_NONE;

            /* release the data list to update the list */
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);

            /* close menu cui */
            scrn_cntx->child_group_id = 0;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
        default:
        {
            /* Others, ignore */
            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_opt_del_item_hdlr
 * DESCRIPTION
 *  "Delete" item handler. Because it needs to display a confirm to let end 
 *  user, it needs use a void func(void) to handle the delete operattion after
 *  pressing Yes on the confirm screen.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_cs_opt_del_item_hdlr(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U16 scrn_id;
    srv_um_thread_id_struct thread_id;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    /* Delete a thread */
    scrn_id = mmi_um_ui_if_entry_delete_thrd_msg(0, scrn_cntx->group_id, MMI_FALSE);
    thread_id.type = ((srv_um_thread_id_struct *)data_list->list)[scrn_cntx->screen_hdlr.hilite_info.index].type;
    thread_id.value = ((srv_um_thread_id_struct *)data_list->list)[scrn_cntx->screen_hdlr.hilite_info.index].value;
    /* Set the thread id */
    mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_SET_THREAD_ID, &thread_id);
    mmi_um_ui_ut_send_init_event(scrn_id);

    /* Reset the data list, it will cause the option list getting the list fail */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_opt_del_all_item_hdlr
 * DESCRIPTION
 *  "Delete all" item handler. Because it needs to display a confirm to let end 
 *  user, it needs use a void func(void) to handle the delete operattion after
 *  pressing Yes on the confirm screen.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_cs_opt_del_all_item_hdlr(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U16 scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Delete all thread */
    scrn_id = mmi_um_ui_if_entry_process_delete_conversation_box(0, scrn_cntx->group_id, MMI_FALSE);
    mmi_um_ui_ut_send_init_event(scrn_id);

    /* Reset the data list, it will cause the option list getting the list fail */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);

    return MMI_RET_OK;
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_opt_mov2arc_item_hdlr
 * DESCRIPTION
 *  "Move to archive" item handler. Because it needs to display a confirm to 
 *  let end user, it needs use a void func(void) to handle the delete 
 *  operattion after pressing Yes on the confirm screen.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_cs_opt_mov2arc_item_hdlr(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U16 scrn_id;
    srv_um_thread_id_struct thread_id;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);

    /* Move a thread into archive */
    scrn_id = mmi_um_ui_if_entry_mov2arc_thrd_msg(0, scrn_cntx->group_id, MMI_FALSE);
    thread_id.type = ((srv_um_thread_id_struct *)data_list->list)[scrn_cntx->screen_hdlr.hilite_info.index].type;
    thread_id.value = ((srv_um_thread_id_struct *)data_list->list)[scrn_cntx->screen_hdlr.hilite_info.index].value;
    /* Set the thread id */
    mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_SET_THREAD_ID, &thread_id);
    mmi_um_ui_ut_send_init_event(scrn_id);

    /* Reset the data list, it will cause the option list getting the list fail */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_DATA_LIST, NULL);

    return MMI_RET_OK;
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_phb_proc
 * DESCRIPTION
 *  Phonebook cui proc handler.
 *  Becase conversation use the phb cui to "add to contact", it also needs
 *  to handle the phb event.
 *  EVT_ID_PHB_SAVE_CONTACT & EVT_ID_PHB_SAVE_CONTACT_CANCEL
 *
 * PARAMETERS
 *  evt                 [IN]: event structure pointer
 *  
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_cs_phb_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    cui_phb_save_contact_result_struct* phb_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_PHB_SAVE_CONTACT:
        {
            /* save finish/fail */
            phb_event = (cui_phb_save_contact_result_struct *)evt;
            cui_phb_save_contact_close(phb_event->sender_id);
            break;
        }
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
        {
            /* Cancel */
            phb_event = (cui_phb_save_contact_result_struct *)evt;
            cui_phb_save_contact_close(phb_event->sender_id);
            break;
        }
        default:
        {
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_op_thrd_msg_init
 * DESCRIPTION
 *  Initialize the operation of thread message variable. It shall trigger 
 *  the fsm initial function to initialize the fsm context.
 *
 *  Some operations for thread messages.
 *  Delete & Move to archive.
 *  
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: Screen context
 *  setting                 [IN]: Setting context
 *  
 * RETURNS
 *  MMI_TRUE: Init successfully
 *  MMI_FALSE: init fail
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_cs_op_thrd_msg_init(
                        mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                        mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_fsm_op_setting_struct fsm_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    
    /* FSM initialize */
    memset(&(fsm_setting), 0, sizeof(mmi_um_ui_fsm_op_setting_struct));
    /* Action type should set by event */
    fsm_setting.action_type = MMI_UM_UI_ACTION_NONE;
    fsm_setting.folder_type = setting->folder;
    fsm_setting.scrn_callback_hdlr = mmi_um_ui_sh_cs_op_thrd_msg_fsm_cb;
    fsm_setting.scrn_id = scrn_cntx->scrn_id;
    mmi_um_ui_fsm_op_init(&(scrn_cntx->fsm), fsm_setting);
    
    /* Appearance initialize */
    mmi_um_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_um_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_op_thrd_msg_evt_hdlr
 * DESCRIPTION
 *  Operation of thread message event handler. Receive the event from the 
 *  Central controller and it needs to handle the event by itself or pass to 
 *  finite state machine.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_cs_op_thrd_msg_evt_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        case MMI_UM_UI_EVENT_ABORT:
        case MMI_UM_UI_EVENT_READY:
        case MMI_UM_UI_EVENT_UNREADY:
        {
            #if 0
/* under construction !*/
/* under construction !*/
            #endif
            result = mmi_um_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        case MMI_UM_UI_EVENT_SET_THREAD_ID:
        {
            srv_um_thread_id_struct *thread_id;

            thread_id = (srv_um_thread_id_struct *)arg;
            mmi_um_ui_fsm_op_set_thrd_id(&(scrn_cntx->fsm), thread_id);
            break;
        }
        case MMI_UM_UI_EVENT_SET_OP_TYPE:
        {
            mmi_um_ui_req_srv_action_enum *action;

            action = (mmi_um_ui_req_srv_action_enum *)arg;
            mmi_um_ui_fsm_op_set_op_type(&(scrn_cntx->fsm), *action);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_op_thrd_msg_fsm_cb
 * DESCRIPTION
 *  A general folder callback is regitered to finite state machine. 
 *  It is used to know the state and status from the finite state machine. 
 *  Screen handler needs to display some screens if it is necessary.
 *  Currently, it uses the Entry folder finite state machine and it needs to 
 *  handle 3 states situation.
 *
 * PARAMETERS
 *  scrn_id             [IN]: Current screen id
 *  state               [IN]: State of finite state machine
 *  status              [IN]: In that state, the current status
 *  
 * RETURNS
 *  MMI_TRUE: handle the callback successfully
 *  MMI_FALSE: fail to handle this callback
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_cs_op_thrd_msg_fsm_cb(U16 scrn_id, U16 state, U16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    switch (state)
    {
        case MMI_UM_UI_FSM_OP_OPERATION:
        {
            if (status == MMI_UM_UI_REQ_SRV_PROGRESS)
            {
                mmi_um_ui_sh_create(mmi_um_ui_sh_cs_op_thrd_msg_entry, scrn_cntx);
            }
            else if (status == MMI_UM_UI_REQ_SRV_FINISH)
            {
                mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
            }
            else if (status == MMI_UM_UI_REQ_SRV_FAIL)
            {
                /* Display a fail popup */
                mmi_popup_display_simple(
                        (WCHAR *)get_string(STR_GLOBAL_UNFINISHED), 
                        MMI_EVENT_FAILURE, 
                        scrn_cntx->group_id, 
                        NULL);
                mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
            }
            else if (status == MMI_UM_UI_REQ_SRV_CANCELLING)
            {
                /* Update as cancelling */
                mmi_um_ui_sh_cs_op_thrd_msg_update((void *)scrn_cntx);
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_op_thrd_msg_entry
 * DESCRIPTION
 *  Entry the operation of thread message screen
 *
 * PARAMETERS
 *  arg             [IN]: Argument of this screen
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_op_thrd_msg_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 action_type;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_loading_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.loading);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* General context */
    aprc->general_aprc_cntx.grp_id = scrn_cntx->group_id;
    aprc->general_aprc_cntx.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;

    aprc->general_aprc_cntx.entry_func = mmi_um_ui_sh_cs_op_thrd_msg_entry;
    aprc->general_aprc_cntx.rsk_str_id = STR_GLOBAL_CANCEL;
    aprc->general_aprc_cntx.rsk_icon_id = IMG_GLOBAL_BACK;
    aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = mmi_um_ui_sh_cs_op_thrd_msg_rsk_hdlr;
    aprc->general_aprc_cntx.leave_proc = mmi_um_ui_sh_leave_proc;

    /* Specified context */
    /* Deleting or Moving */
    action_type = mmi_um_ui_fsm_op_get_action(&(scrn_cntx->fsm));
    aprc->msg_str_id = mmi_um_ui_ut_get_activate_str_id_by_op((mmi_um_ui_req_srv_action_enum)action_type);
    aprc->msg_icon_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);

    scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_op_thrd_msg_rsk_hdlr
 * DESCRIPTION
 *  Right soft key handler for screen handler module
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_op_thrd_msg_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Send the abort event to screen */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_ABORT, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_op_thrd_msg_update
 * DESCRIPTION
 *  Update the screen via cancelling operation
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_op_thrd_msg_update(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_loading_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.loading);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Specified context */
    aprc->msg_icon_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
    /* Deleting or Moving */
    aprc->msg_str_id = mmi_um_ui_ut_get_cancel_str_id_by_op(
                                (mmi_um_ui_req_srv_action_enum)mmi_um_ui_fsm_op_get_action(&(scrn_cntx->fsm)));

    scrn_cntx->aprc.redraw_func(&aprc_union, 
                                scrn_cntx->aprc.st_type, 
                                (mmi_um_ui_aprc_redraw_type_enum)(MMI_UM_UI_APRC_REDRAW_KEY | MMI_UM_UI_APRC_REDRAW_BODY));
}


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_cs_entry
 * DESCRIPTION
 *  Entry conversation box of Mark several to display the current screen.
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_cs_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_item;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_ms_cs_folder_struct *aprc;
    mmi_um_entry_folder_evt_struct entry_folder_evt;
    mmi_um_ui_ms_cntx_struct *ms_table;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.ms_cs_folder);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    ms_table = (mmi_um_ui_ms_cntx_struct *)scrn_cntx->screen_hdlr.scrn_data;

    /* set the number of items */
    num_item = mmi_um_ui_sh_ms_general_get_msg_num(scrn_cntx);
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    if (num_item != 0)
    {
        scrn_cntx->screen_hdlr.num_of_item = num_item;
        /* search the specified highlight index based on the highlight msg id and msg type*/
        if (data_list != NULL)
        {
            for (i = 0; i < num_item; i++)
            {
                if (((srv_um_thread_id_struct *)data_list->list)[i].type == scrn_cntx->screen_hdlr.hilite_info.thrd_id.type &&
                    ((srv_um_thread_id_struct *)data_list->list)[i].value == scrn_cntx->screen_hdlr.hilite_info.thrd_id.value)
                {
                    scrn_cntx->screen_hdlr.hilite_info.index = i;
                    break;
                }
            }
        }
        
        /* error handling for highlight */
        if (scrn_cntx->screen_hdlr.hilite_info.index >= num_item)
        {
            /* highlight to last one */
            scrn_cntx->screen_hdlr.hilite_info.index = num_item - 1;
        }
    }

    /* set the marked messages */
    if (data_list != NULL
        && mmi_is_redrawing_bk_screens() == MMI_FALSE
       )
    {
        mmi_um_ui_sh_ms_general_copy_mark_msg(
                            data_list, 
                            (mmi_um_ui_ms_cntx_struct *)scrn_cntx->screen_hdlr.scrn_data, 
                            mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm)));
    }

    /* General context */
    aprc->general_aprc_cntx.grp_id = scrn_cntx->group_id;
    aprc->general_aprc_cntx.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
    aprc->general_aprc_cntx.menu_item_id = 0;
    aprc->general_aprc_cntx.title_str_id = mmi_um_ui_ut_get_str_id_by_option(scrn_cntx->screen_hdlr.ms_op);
    aprc->general_aprc_cntx.title_icon_id = IMG_UM_ENTRY_SCRN_CAPTION;
    if (ms_table->num_of_mark != 0)
    {
        aprc->general_aprc_cntx.lsk_str_id = STR_GLOBAL_OPTIONS;
    }
    else
    {
        aprc->general_aprc_cntx.lsk_str_id = STR_GLOBAL_MARK_ALL;
    }
    aprc->general_aprc_cntx.lsk_icon_id = IMG_GLOBAL_OPTIONS;
    aprc->general_aprc_cntx.rsk_str_id = STR_GLOBAL_BACK;
    aprc->general_aprc_cntx.rsk_icon_id = IMG_GLOBAL_BACK;
    aprc->general_aprc_cntx.csk_icon_id = IMG_GLOBAL_MARK_CSK;
    aprc->general_aprc_cntx.hilite_hdlr = mmi_um_ui_sh_ms_cs_hilite_hdlr;
    aprc->general_aprc_cntx.hilite_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    aprc->general_aprc_cntx.num_of_item = scrn_cntx->screen_hdlr.num_of_item;
    aprc->general_aprc_cntx.entry_func = mmi_um_ui_sh_ms_cs_entry;
    aprc->general_aprc_cntx.exit_func = mmi_um_ui_sh_ms_cs_exit;
    aprc->general_aprc_cntx.gui_buffer = NULL;
    aprc->general_aprc_cntx.key_hdlr.lsk_hdlr = mmi_um_ui_sh_ms_cs_lsk_hdlr;
    aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = mmi_um_ui_sh_ms_cs_rsk_hdlr;
    aprc->general_aprc_cntx.key_hdlr.csk_hdlr = mmi_um_ui_sh_ms_general_csk_hdlr;
    aprc->general_aprc_cntx.leave_proc = mmi_um_ui_sh_ms_general_leave_proc;

    /* Specified context */
    aprc->folder_style = CAT263_DISPLAY_ALL;
    aprc->get_item_cb = mmi_um_ui_sh_get_async_item;
    aprc->get_item_hint_cb = NULL;
    aprc->set_mark_cb = mmi_um_ui_sh_ms_general_set_mark_cb;
    aprc->get_mark_cb = mmi_um_ui_sh_ms_general_get_mark_cb;
    aprc->hilite_notify_cb = mmi_um_ui_sh_ms_cs_notify_highlight;
    scrn_cntx->screen_hdlr.is_scrn_displayed = scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);

    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
    {
        return;
    }

    /* After drawing, the child should be removed */
    mmi_um_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
    
    /* Due to the category usage, it should check the screen is displayed or not */
    if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE)
    {
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
    }

    /* global setting reset */
    if (MMI_TRUE == scrn_cntx->screen_hdlr.is_scrn_displayed)
    {
        /* Send the event out */
        MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_UM_ENTRY_FOLDER);
        entry_folder_evt.is_entry = MMI_TRUE;
        entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
        entry_folder_evt.um_user_data = (void *)scrn_cntx;
        MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_cs_exit
 * DESCRIPTION
 *  Exit conversation box of mark several folder.
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_cs_exit(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_entry_folder_evt_struct entry_folder_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    /* Send the event out */
    MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_UM_ENTRY_FOLDER);
    entry_folder_evt.is_entry = MMI_FALSE;
    entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
    entry_folder_evt.um_user_data = (void *)scrn_cntx;
    MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_hilite_hdlr
 * DESCRIPTION
 *  The mark several general highlight function.
 *
 * PARAMETERS
 *  index               [IN]: the highlight index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_cs_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    MMI_BOOL result;
    srv_um_msg_info_struct **msg_detail_info;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    result = fsm->get_msg_info(scrn_cntx->scrn_id, (U16) index, 1, &msg_detail_info, NULL);
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));

    /* Tricky for category bugs */
    if (result == MMI_FALSE)
    {
        return;
    }
    /* Tricky for category bugs */
    MMI_ASSERT(result != MMI_FALSE);
    MMI_ASSERT(data_list != NULL);

    /* Set highlight message id & type */
    scrn_cntx->screen_hdlr.hilite_info.index = index;
    scrn_cntx->screen_hdlr.hilite_info.thrd_id.type = ((srv_um_thread_id_struct *)data_list->list)[index].type;
    scrn_cntx->screen_hdlr.hilite_info.thrd_id.value = ((srv_um_thread_id_struct *)data_list->list)[index].value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_cs_lsk_hdlr
 * DESCRIPTION
 *  Left soft key handler for conversation box of mark several.
 *  Use Menu cui to display the option menu
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_cs_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID opt_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;
    mmi_um_ui_ms_cntx_struct *ms_table;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    ms_table = (mmi_um_ui_ms_cntx_struct *)scrn_cntx->screen_hdlr.scrn_data;
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);
    /* If during updating data, lsk should not activate any action */
    if (MMI_UM_UI_FSM_EF_UPDATE_DATA == mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)))
    {
        return;
    }

    if (ms_table->num_of_mark != 0)
    {
            /* create group */
            opt_grp_id = mmi_frm_group_create(
                                    scrn_cntx->group_id, 
                                    GRP_ID_AUTO_GEN, 
                                    mmi_um_ui_sh_ms_cs_opt_proc, 
                                    (void*) scrn_cntx);
            mmi_frm_group_enter(opt_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

            opt_grp_id = cui_menu_create(
                                    opt_grp_id, 
                                    CUI_MENU_SRC_TYPE_RESOURCE, 
                                    CUI_MENU_TYPE_OPTION, 
                                    MENU_ID_UM_MS_CS_BOX_OPT, 
                                    MMI_FALSE, 
                                    NULL);
            /* Set default string/icon */
            cui_menu_set_default_title(
                    opt_grp_id, 
                    (WCHAR*)GetString(STR_GLOBAL_OPTIONS), 
                    (UI_image_type)GetImage(IMG_UM_ENTRY_SCRN_CAPTION));
            cui_menu_run(opt_grp_id);
            scrn_cntx->child_group_id = opt_grp_id;
        }
    else
    {
        /* Set the mark status as 0xff */
        memset(ms_table->mark_status, 0xff, sizeof(U32)*MMI_UM_UI_MAX_BIT_MARK_STATUS_NUM);
        ms_table->num_of_mark = ms_table->num_of_item;
        mmi_frm_display_dummy_screen();
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_cs_rsk_hdlr
 * DESCRIPTION
 *  General right soft key handler for conversation box of mark several.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_cs_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_sh_hilite_folder_info_struct hilite;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    memset(&hilite, 0, sizeof(mmi_um_ui_sh_hilite_folder_info_struct));
    memcpy(&(hilite.hilite_info), &(scrn_cntx->screen_hdlr.hilite_info), sizeof(mmi_um_ui_sh_hilite_info_struct));
    memcpy(&(hilite.folder_info), &(scrn_cntx->screen_hdlr.folder_type), sizeof(srv_um_box_identity_struct));
    /* send to all related screens */
    mmi_um_ui_cc_send_event(0, MMI_UM_UI_EVENT_HIGHLIGHT_CHANGE, &hilite);    

    mmi_um_ui_sh_rsk_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_cs_notify_highlight
 * DESCRIPTION
 *  The notify highlight index function.
 *
 * PARAMETERS
 *  index               [IN]: the highlight index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_cs_notify_highlight(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    
    if (data_list != NULL)
    {
        /* Set highlight message id & type */
        scrn_cntx->screen_hdlr.hilite_info.index = index;
        scrn_cntx->screen_hdlr.hilite_info.thrd_id.type = ((srv_um_thread_id_struct *)data_list->list)[index].type;
        scrn_cntx->screen_hdlr.hilite_info.thrd_id.value = ((srv_um_thread_id_struct *)data_list->list)[index].value;
    }
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
void mmi_um_ui_sh_ms_cs_intuitive_cmd_cb(mmi_tap_type_enum tap_type, S32 index)
{
}
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_cs_opt_proc
 * DESCRIPTION
 *  Option proc of menu cui.
 *  It needs to handle the menu cui event like entry, select and exit.
 *
 * PARAMETERS
 *  evt                 [IN]: event structure pointer
 *  
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_cs_opt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    cui_menu_event_struct *menu_evt;
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    ret = MMI_RET_OK;
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            ret = mmi_um_ui_sh_ms_cs_opt_list_entry_hdlr(evt);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            ret = mmi_um_ui_sh_ms_cs_opt_item_select_hdlr(evt);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            scrn_cntx->child_group_id = 0;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_cs_opt_list_entry_hdlr
 * DESCRIPTION
 *  List entry proc of menu cui.
 *  Seperate each event to let function more modulaized.
 *  The sub-function of mmi_um_ui_sh_ms_cs_opt_proc.
 *
 * PARAMETERS
 *  evt                 [IN]: event structure pointer
 *  
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_cs_opt_list_entry_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_ms_cntx_struct *ms_cntx;
    cui_menu_event_struct *menu_evt; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    ms_cntx = scrn_cntx->screen_hdlr.scrn_data;
    MMI_ASSERT(NULL != ms_cntx);

    ret = MMI_RET_OK;
    if (MENU_ID_UM_MS_CS_BOX_OPT == menu_evt->parent_menu_id)
    {
        /* Entry option, set hide/unhide */
    
        cui_menu_set_item_hidden(
                menu_evt->sender_id, 
                MENU_ID_UM_MS_CS_BOX_OPT_DELETE, 
                MMI_TRUE);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        cui_menu_set_item_hidden(
                menu_evt->sender_id, 
                MENU_ID_UM_MS_CS_BOX_OPT_MOVE_TO_ARCH, 
                MMI_TRUE);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        /* Check delete, move to archive, unmark all */
        if (0 == ms_cntx->num_of_mark)
        {
            cui_menu_set_item_hidden(
                    menu_evt->sender_id, 
                    MENU_ID_UM_MS_CS_BOX_OPT_UNMARK_ALL, 
                    MMI_TRUE);
        }
        else if (0 != ms_cntx->num_of_item)
        {
            if (scrn_cntx->screen_hdlr.ms_op ==  SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE)
            {
                cui_menu_set_item_hidden(
                        menu_evt->sender_id, 
                        MENU_ID_UM_MS_CS_BOX_OPT_DELETE, 
                        MMI_FALSE);
            }
            
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            if (scrn_cntx->screen_hdlr.ms_op ==  SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE)
            {
                
                cui_menu_set_item_hidden(
                        menu_evt->sender_id, 
                        MENU_ID_UM_MS_CS_BOX_OPT_MOVE_TO_ARCH, 
                        MMI_FALSE);
            }
#endif
        }
        if (ms_cntx->num_of_item == ms_cntx->num_of_mark)
        {
            cui_menu_set_item_hidden(
                menu_evt->sender_id, 
                MENU_ID_UM_MS_CS_BOX_OPT_MARK_ALL, 
                MMI_TRUE);
        }

    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_cs_opt_item_select_hdlr
 * DESCRIPTION
 *  Item select proc of menu cui.
 *  Seperate each event to let function more modulaized.
 *  The sub-function of mmi_um_ui_sh_ms_cs_opt_proc.
 *
 * PARAMETERS
 *  evt                 [IN]: event structure pointer
 *  
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_cs_opt_item_select_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_ms_cntx_struct *ms_cntx;
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    ms_cntx = scrn_cntx->screen_hdlr.scrn_data;
    MMI_ASSERT(NULL != ms_cntx);

    ret = MMI_RET_OK;
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_UM_MS_CS_BOX_OPT_DELETE:
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MENU_ID_UM_MS_CS_BOX_OPT_MOVE_TO_ARCH:
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        {
            U16 str_id;
            U8 temp_str[(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH];
            U8 str_msg_num[MMI_UM_UI_MAX_MSG_NUM_DIGIT + 1];
            U8 str_msg_num_ucs2[(MMI_UM_UI_MAX_MSG_NUM_DIGIT + 1) * ENCODING_LENGTH];
            mmi_confirm_property_struct confirm_param;
            mmi_um_ui_sh_confirm_action_enum action;

            /* Display a confirm to ask delete/move */
            /* construct the confirm string */
            memset(temp_str, 0, sizeof(temp_str));
            memset(str_msg_num, 0, sizeof(str_msg_num));
            memset(str_msg_num_ucs2, 0, sizeof(str_msg_num_ucs2));
            
            /* Get the string of each operation */
            str_id = mmi_um_ui_sh_ms_query_string_action(menu_evt->highlighted_menu_id);

            /* String => Delete N message or messages ? */
            mmi_ucs2cpy((CHAR *)temp_str, (CHAR *) GetString(str_id));
            mmi_ucs2cat((CHAR *)temp_str, (CHAR *)L" ");

            /* transfer the number into ucs2 */
            sprintf((CHAR*) str_msg_num, "%d ", ms_cntx->num_of_mark);
            mmi_asc_to_ucs2((CHAR*) str_msg_num_ucs2, (CHAR*) str_msg_num);
            mmi_ucs2cat((CHAR *)temp_str, (CHAR *)str_msg_num_ucs2);

            if (ms_cntx->num_of_mark > 1)
            {
                mmi_ucs2cat((CHAR *)temp_str, (CHAR *)GetString(STR_UM_CONVERSATION_BOXES_ASK));
            }
            else
            {
                mmi_ucs2cat((CHAR *)temp_str, (CHAR *)GetString(STR_UM_CONVERSATION_BOX_ASK));
            }

            mmi_confirm_property_init(&confirm_param, CNFM_TYPE_YESNO);
            action = mmi_um_ui_sh_ms_query_action(menu_evt->highlighted_menu_id);
            mmi_um_ui_sh_set_confirm_param(&confirm_param, scrn_cntx, action);
            scrn_cntx->screen_hdlr.cf_grp_id = mmi_confirm_display(
                                                        (WCHAR *)temp_str, 
                                                        MMI_EVENT_QUERY, 
                                                        &confirm_param);
            break;
        }
        case MENU_ID_UM_MS_CS_BOX_OPT_MARK_ALL:
        {
            /* Set the mark status as 0xff */
            memset(ms_cntx->mark_status, 0xff, sizeof(U32)*MMI_UM_UI_MAX_BIT_MARK_STATUS_NUM);
            ms_cntx->num_of_mark = ms_cntx->num_of_item;
            scrn_cntx->child_group_id = 0;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case MENU_ID_UM_MS_CS_BOX_OPT_UNMARK_ALL:
        {
            /* Set the mark status as 0 */
            memset(ms_cntx->mark_status, 0, sizeof(U32)*MMI_UM_UI_MAX_BIT_MARK_STATUS_NUM);
            ms_cntx->num_of_mark = 0;
            scrn_cntx->child_group_id = 0;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_cs_opt_delete
 * DESCRIPTION
 *  Process the conversation mark several operations. (Delete)
 *  Invoke the mark several operation delete screen.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_cs_opt_delete(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* invoke the delete screen */
    scrn_id = mmi_um_ui_if_entry_ms_cs_op_delete(0, scrn_cntx->group_id, MMI_FALSE);

    /* transfer the mark several status list to child screen */
    mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_SET_MS_LIST, scrn_cntx->screen_hdlr.scrn_data);

    /* Remove the mark several status list from parent screen */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_MS_LIST, NULL);
    
    /* start to run mark several operation */
    mmi_um_ui_ut_send_init_event(scrn_id);

    /* Kill myself */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);

    return MMI_RET_OK;
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_cs_opt_mov2arc
 * DESCRIPTION
 *  Process the conversation mark several operations. (Move to archive)
 *  Invoke the mark several operation delete screen.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_cs_opt_mov2arc(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* invoke the delete screen */
    scrn_id = mmi_um_ui_if_entry_ms_cs_op_mov2arc(0, scrn_cntx->group_id, MMI_FALSE);

    /* transfer the mark several status list to child screen */
    mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_SET_MS_LIST, scrn_cntx->screen_hdlr.scrn_data);

    /* Remove the mark several status list from parent screen */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_MS_LIST, NULL);
    
    /* start to run mark several operation */
    mmi_um_ui_ut_send_init_event(scrn_id);

    /* Kill myself */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);

    return MMI_RET_OK;
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* __MMI_UM_CONVERSATION_BOX__ */


#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_tb_reply
 * DESCRIPTION
 *  In toolbar, reply the selected contact
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_tb_reply(void)
{
#ifdef __MMI_UM_CONVERSATION_BOX__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 highlight_idx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    srv_um_msg_info_struct **msg_detail_info;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_uc_entry_write_struct *data;
    mmi_uc_addr_struct *uc_addr;
#else
    CHAR ascii_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    mmi_sms_write_msg_para_struct sendData;
#endif /* __MMI_UNIFIED_COMPOSER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm = &(scrn_cntx->fsm.cntx.fsm_entry_folder);
    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    result = fsm->get_msg_info(scrn_cntx->scrn_id, highlight_idx, 1, &msg_detail_info, NULL);
    MMI_ASSERT(MMI_TRUE == result);

    #ifdef __MMI_UNIFIED_COMPOSER__
    /* entry editor */
    data = OslMalloc(sizeof(mmi_uc_entry_write_struct));
    uc_addr = OslMalloc(sizeof(mmi_uc_addr_struct));
    memset(data, 0, sizeof(mmi_uc_entry_write_struct));
    memset(uc_addr, 0, sizeof(mmi_uc_addr_struct));
    uc_addr->previous = uc_addr->next = NULL;
    uc_addr->addr = (kal_uint8 *)msg_detail_info[0]->address;
    if (SRV_UM_ADDR_PHONE_NUMBER == msg_detail_info[0]->address_type)
    {
        uc_addr->type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
    }
    else if (SRV_UM_ADDR_EMAIL_ADDRESS == msg_detail_info[0]->address_type)
    {
        uc_addr->type = SRV_UC_ADDRESS_TYPE_EMAIL;
    }
    else
    {
        MMI_ASSERT(0);
    }
    uc_addr->group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
    data->addr = uc_addr;
    data->addr_num = 1;
    data->msg_type = SRV_UC_MSG_TYPE_SMS_PREFER;
    mmi_uc_entry_write_msg_with_content(SRV_UC_STATE_WRITE_NEW_MSG, data);

    OslMfree(data);
    OslMfree(uc_addr);
    #else /* __MMI_UNIFIED_COMPOSER__ */
    if (SRV_UM_ADDR_PHONE_NUMBER == msg_detail_info[0]->address_type)
	{
	    memset(ascii_number, 0, sizeof(ascii_number));
	    memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));
	    mmi_ucs2_n_to_asc(ascii_number, (CHAR *)msg_detail_info[0]->address, MMI_PHB_NUMBER_LENGTH + 1);
	    sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;
	    sendData.ascii_addr = (U8*) ascii_number;
	    mmi_sms_write_msg_lanch(0, &sendData);
	}
	
#if (defined(__MMI_MMS_IN_UM__))
	if (SRV_UM_ADDR_EMAIL_ADDRESS== msg_detail_info[0]->address_type)
	{
		mms_address_insert_hdlr((CHAR*)msg_detail_info[0]->address);
	}

#endif
    #endif /* __MMI_UNIFIED_COMPOSER__ */
#endif /* __MMI_UM_CONVERSATION_BOX__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_tb_call
 * DESCRIPTION
 *  In toolbar, make a call on the selected contact
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_tb_call(void)
{
#ifdef __MMI_UM_CONVERSATION_BOX__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 highlight_idx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    srv_um_msg_info_struct **msg_detail_info;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_ucm_make_call_para_struct *make_call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm = &(scrn_cntx->fsm.cntx.fsm_entry_folder);
    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    result = fsm->get_msg_info(scrn_cntx->scrn_id, highlight_idx, 1, &msg_detail_info, NULL);
    MMI_ASSERT(MMI_TRUE == result);

    /* Make a call */
    make_call_para = OslMalloc(sizeof(mmi_ucm_make_call_para_struct));

    mmi_ucm_init_call_para(make_call_para);
    make_call_para->ucs2_num_uri = (U16 *) msg_detail_info[0]->address;
    mmi_ucm_call_launch(0, make_call_para);
    OslMfree(make_call_para);
#endif /* __MMI_UM_CONVERSATION_BOX__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_tb_delete
 * DESCRIPTION
 *  In toolbar, delete the selected contact
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_cs_tb_delete(void)
{
#ifdef __MMI_UM_CONVERSATION_BOX__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    U8 *temp_str;
    mmi_confirm_property_struct confirm_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    temp_str = OslMalloc(sizeof(U8)*(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH);
    memset(temp_str, 0, sizeof(U8)*(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((CHAR *)temp_str, (CHAR *)get_string(STR_GLOBAL_DELETE));
    mmi_ucs2cat((CHAR *)temp_str, (CHAR *)get_string(STR_UM_QUESTION_MARK));

    memset(&confirm_param, 0, sizeof(mmi_confirm_property_struct));
    mmi_confirm_property_init(&confirm_param, CNFM_TYPE_YESNO);
    mmi_um_ui_sh_set_confirm_param(&confirm_param, scrn_cntx, MMI_UM_UI_SH_CF_CS_TB_DELETE);
    scrn_cntx->screen_hdlr.cf_grp_id = mmi_confirm_display(
                                                (WCHAR *)temp_str, 
                                                MMI_EVENT_QUERY, 
                                                &confirm_param);
    OslMfree(temp_str);
#endif /* __MMI_UM_CONVERSATION_BOX__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_check_reply
 * DESCRIPTION
 *  Check if this contact could be replied.
 *
 * PARAMETERS
 *  msg_type                [IN]: useless
 *  msg_id                  [IN]: useless
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_cs_check_reply(srv_um_msg_enum msg_type, U32 msg_id)
{
#ifdef __MMI_UM_CONVERSATION_BOX__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 highlight_idx;
    srv_um_msg_info_struct **msg_detail_info;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm = &(scrn_cntx->fsm.cntx.fsm_entry_folder);
    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    result = fsm->get_msg_info(scrn_cntx->scrn_id, highlight_idx, 1, &msg_detail_info, NULL);
    MMI_ASSERT(result == MMI_TRUE);

    /* check the number to see if the reply menu item status */
    result = MMI_TRUE;
    if (0 == msg_detail_info[0]->address_length ||
        (SRV_UM_ADDR_PHONE_NUMBER != msg_detail_info[0]->address_type 
    #if (defined (__UNIFIED_COMPOSER_SUPPORT__) || defined (__MMI_MESSAGES_SMS_EMAIL__) || defined(__MMI_MMS_IN_UM__))
         && SRV_UM_ADDR_EMAIL_ADDRESS != msg_detail_info[0]->address_type
    #endif
         ))
    {
	    /* Without UC, tap toolbar will reply by SMS directly*/
        /* no number or other type address, disable toolbar */
        result = MMI_FALSE;
    }

    return result;
#else
    return MMI_TRUE;
#endif /* __MMI_UM_CONVERSATION_BOX__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_check_call
 * DESCRIPTION
 *  Check if this contact could be called.
 *
 * PARAMETERS
 *  msg_type                [IN]: useless
 *  msg_id                  [IN]: useless
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_cs_check_call(srv_um_msg_enum msg_type, U32 msg_id)
{
#ifdef __MMI_UM_CONVERSATION_BOX__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 highlight_idx;
    srv_um_msg_info_struct **msg_detail_info;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm = &(scrn_cntx->fsm.cntx.fsm_entry_folder);
    highlight_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    result = fsm->get_msg_info(scrn_cntx->scrn_id, highlight_idx, 1, &msg_detail_info, NULL);
    MMI_ASSERT(result == MMI_TRUE);

    /* check the number to see if the call menu item status */
    result = MMI_TRUE;
    if (0 == msg_detail_info[0]->address_length ||
        SRV_UM_ADDR_PHONE_NUMBER != msg_detail_info[0]->address_type)
    {
        /* no number or other type address, disable toolbar */
        result = MMI_FALSE;
    }

    return result;
#else
    return MMI_TRUE;
#endif /* __MMI_UM_CONVERSATION_BOX__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_cs_check_delete
 * DESCRIPTION
 *  Check if this contact could be deleted.
 *
 * PARAMETERS
 *  msg_type                [IN]: useless
 *  msg_id                  [IN]: useless
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_cs_check_delete(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}
#endif /* __MMI_ICON_BAR_SUPPORT__ */


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_init
 * DESCRIPTION
 *  Initialize the mark sevearl general folder variable. It shall trigger 
 *  the fsm initial function to initialize the fsm context.
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  setting                 [IN]: Setting
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_ms_general_init(
                    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                    mmi_um_ui_cc_scrn_cntx_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_fsm_ef_setting_struct fsm_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    
    /* FSM initialize */
    memset(&fsm_setting, 0, sizeof(mmi_um_ui_fsm_ef_setting_struct));
    fsm_setting.folder_type = setting->folder;
    fsm_setting.scrn_callback_hdlr = mmi_um_ui_sh_ms_general_fsm_cb;
    fsm_setting.scrn_id = scrn_cntx->scrn_id;
    mmi_um_ui_fsm_ef_init(&(scrn_cntx->fsm), fsm_setting);

    /* Appearance initialize */
    mmi_um_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_um_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;
    scrn_cntx->screen_hdlr.scrn_data = setting->scrn_data;

    return result;
}


static void mmi_um_ui_sh_general_folder_ms_item_select_common_hanlder(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, srv_um_mark_several_op_action_enum ms_action)
{
        U16 scrn_id;
        srv_um_list_filter_struct *filter;
    #ifdef __MMI_UM_CONVERSATION_BOX__
        mmi_um_ui_folder_mode_enum folder_mode;
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        mmi_um_ui_sh_hilite_folder_info_struct hilite_folder_info;

        /* create screen context */
        filter = mmi_um_ui_fsm_ef_get_list_filter_type(&(scrn_cntx->fsm));
    #ifdef __MMI_UM_CONVERSATION_BOX__
        folder_mode = mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm));
        if (MMI_UM_FOLDER_MODE_THREAD_MSG == folder_mode)
        {
            scrn_id = mmi_um_ui_if_entry_ms_thrd_msg(
                                0, 
                                filter, 
                                scrn_cntx->group_id, 
                                MMI_FALSE);
        }
        else
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            scrn_id = mmi_um_ui_if_entry_ms_folder(
                                    scrn_cntx->screen_hdlr.folder_type, 
                                    0, 
                                    scrn_cntx->group_id, 
                                    MMI_FALSE);
        }

        /* Set highlight to mark several screen*/
        memcpy(&(hilite_folder_info.hilite_info), &(scrn_cntx->screen_hdlr.hilite_info), sizeof(mmi_um_ui_sh_hilite_info_struct));
        memcpy(&(hilite_folder_info.folder_info), &(scrn_cntx->screen_hdlr.folder_type), sizeof(srv_um_box_identity_struct));
        mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_HIGHLIGHT_CHANGE, (void *)&hilite_folder_info);
        /* Set the supporting message type, it may only support SMS-only */
        mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_SET_SPT_MSG_TYPE, (void *)&(scrn_cntx->screen_hdlr.folder_type));

    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        /* Set the sorting type */
        mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_SET_FILTER_TYPE, (void *)filter);
    #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
    
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_SET_MS_OP_TYPE, (void *)&ms_action);
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
        /* start to display mark several screen */
        mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_INIT, NULL);

        /* Reset the current folder highlight */
        memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_um_ui_sh_hilite_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_event_hdlr
 * DESCRIPTION
 *  Mark sevearl general event handler. Receive the event from the Central 
 *  controller and it needs to handle the event by itself or pass to finite 
 *  state machine.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_ms_general_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        case MMI_UM_UI_EVENT_ABORT:
        case MMI_UM_UI_EVENT_CHECK:
        case MMI_UM_UI_EVENT_UNREADY:
        case MMI_UM_UI_EVENT_REL_DATA_LIST:
        {
            #if 0
/* under construction !*/
/* under construction !*/
            #endif
            result = mmi_um_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            break;
        }
        case MMI_UM_UI_EVENT_READY:
        {
            if (mmi_um_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
            {
                /* If current state is not check ready, return */
                if (mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)) != MMI_UM_UI_FSM_EF_CHECK_READY)
                {
                    break;
                }

                /* Invoke FSM mechanism */
                #if 0
/* under construction !*/
/* under construction !*/
                #endif
                result = mmi_um_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            }
            break;
        }
        case MMI_UM_UI_EVENT_REFRESH:
        {
            srv_um_msg_box_enum *msg_box;

            msg_box = (srv_um_msg_box_enum *)arg;
            /* Check current box folder */
            if ((scrn_cntx->screen_hdlr.folder_type.msg_box_type & *msg_box) == 0)
            {
                break;
            }

            /* No any action */
            if (mmi_um_ui_fsm_get_fsm_state(&(scrn_cntx->fsm)) == MMI_UM_UI_FSM_EF_CHECK_DATA && 
                MMI_SCENARIO_STATE_ACTIVE != mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
            {
                /* Turn on the update flag */
                result = scrn_cntx->fsm.event_hdlr(scrn_id, MMI_UM_UI_FSM_EVENT_UPDATE_DATA_LIST, NULL);

                /* Check child group id, child must be option menu */
                /* Check the confirm popup */
                if ((0 != scrn_cntx->child_group_id && mmi_frm_group_get_active_id() == scrn_cntx->child_group_id) ||
                    (GRP_ID_INVALID != scrn_cntx->screen_hdlr.cf_grp_id))
                {
                    /* Display a hint to end user */
                    mmi_popup_display_simple(
                            (WCHAR *)get_string(STR_GLOBAL_UPDATE), 
                            MMI_EVENT_INFO, 
                            scrn_cntx->group_id, 
                            NULL);
                }
            }
            else
            {
                /* Invoke refresh mechanism */
                #if 0
/* under construction !*/
/* under construction !*/
                #endif
                result = mmi_um_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            }
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        case MMI_UM_UI_EVENT_DELETED:
        {
            /* Set child screen as 0 */
            scrn_cntx->child_scrn_id = 0;
            if (!mmi_frm_scrn_is_present(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, MMI_FRM_NODE_ALL_FLAG))
            {
                /**************************************************** 
                 * Screen is not in history and the child is deleted.
                 * (1) Entry ms messages
                 * (2) Display processing with RSK (unready)
                 * (3) Press end key in processing screen
                 * (4) child is deleted and notify parent
                 ***************************************************/
                mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
            }
            break;
        }
        case MMI_UM_UI_EVENT_HIGHLIGHT_CHANGE:
        {
            mmi_um_ui_sh_hilite_folder_info_struct *hilite_folder;
            /* Set the new highlight */
            hilite_folder = (mmi_um_ui_sh_hilite_folder_info_struct *)arg;

            if (scrn_cntx->screen_hdlr.folder_type.msg_box_type == hilite_folder->folder_info.msg_box_type)
            {
                scrn_cntx->screen_hdlr.hilite_info.msg_id = hilite_folder->hilite_info.msg_id;
                scrn_cntx->screen_hdlr.hilite_info.msg_type = hilite_folder->hilite_info.msg_type;
            #ifdef __MMI_UM_CONVERSATION_BOX__
                scrn_cntx->screen_hdlr.hilite_info.thrd_id.type = hilite_folder->hilite_info.thrd_id.type;
                scrn_cntx->screen_hdlr.hilite_info.thrd_id.value = hilite_folder->hilite_info.thrd_id.value;
            #endif /* __MMI_UM_CONVERSATION_BOX__ */
            }
            break;
        }
        case MMI_UM_UI_EVENT_REL_MS_LIST:
        {
            scrn_cntx->screen_hdlr.scrn_data = NULL;
            break;
        }
        case MMI_UM_UI_EVENT_SET_SPT_MSG_TYPE:
        {
            srv_um_box_identity_struct *box;

            box = (srv_um_box_identity_struct *)arg;
            
            scrn_cntx->screen_hdlr.folder_type.msg_type = box->msg_type;
            /* Set FSM folder type */
            mmi_um_ui_fsm_ef_set_box_identity(&(scrn_cntx->fsm), box);
            break;
        }
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MMI_UM_UI_EVENT_SET_MS_OP_TYPE:
        {
            scrn_cntx->screen_hdlr.ms_op = *((srv_um_mark_several_op_action_enum*)arg);
            break;
        }
    #endif
        case MMI_UM_UI_EVENT_SET_FILTER_TYPE:
        {
            srv_um_list_filter_struct *filter;

            filter = (srv_um_list_filter_struct *)arg;
            /* Set the sorting type */
            mmi_um_ui_fsm_ef_set_list_filter_type(&(scrn_cntx->fsm), *filter);
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_UI_EVENT_SET_FOLDER_MODE:
        {
            mmi_um_ui_folder_mode_enum *mode;

            mode = (mmi_um_ui_folder_mode_enum *)arg;
            /* Set the folder mode */
            mmi_um_ui_fsm_ef_set_folder_mode(&(scrn_cntx->fsm), *mode);
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_fsm_cb
 * DESCRIPTION
 *  A mark sevearl general callback is regitered to finite state machine. 
 *  It is used to know the state and status from the finite state machine. 
 *  Screen handler needs to display some screens if it is necessary.
 *  Currently, it uses the Entry folder finite state machine and it needs to 
 *  handle 5 states situation.
 *
 * PARAMETERS
 *  scrn_id             [IN]: Current screen id
 *  state               [IN]: State of finite state machine
 *  status              [IN]: In that state, the current status
 *  
 * RETURNS
 *  MMI_TRUE: handle the callback successfully
 *  MMI_FALSE: fail to handle this callback
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_ms_general_fsm_cb(U16 scrn_id, U16 state, U16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_item;
    MMI_BOOL result;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_entry_func_ptr entry_func;
    mmi_um_ui_folder_mode_enum folder_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Based on the Mode, get the entry function pointer */
    folder_mode = mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm));
    entry_func = mmi_um_ui_sh_ms_general_get_entry_func(folder_mode);

    switch (state)
    {
        case MMI_UM_UI_FSM_EF_CHECK_READY:
        {
            MMI_ID child_group_id;

            /* Check child group id, option menu */
            if (0 != scrn_cntx->child_group_id)
            {
                if (mmi_frm_group_get_active_id() == scrn_cntx->child_group_id)
                {
                    /* Display a hint to end user */
                    mmi_popup_display_simple(
                            (WCHAR *)get_string(STR_GLOBAL_UPDATE), 
                            MMI_EVENT_INFO, 
                            scrn_cntx->group_id, 
                            NULL);
                }
                else
                {
                    child_group_id = scrn_cntx->child_group_id;
                    scrn_cntx->child_group_id = 0;
                    cui_menu_close(child_group_id);
                }
            }
            else
            {
                /* Not exist in scenario tree or exist+active */
                if (mmi_um_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id) == MMI_FALSE &&
                    MMI_FALSE == mmi_frm_scrn_is_present(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                {
                    scrn_cntx->child_scrn_id = mmi_um_ui_if_entry_processing(scrn_id, scrn_cntx->group_id, MMI_FALSE);
                    mmi_um_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
                }
            }
            break;
        }
        case MMI_UM_UI_FSM_EF_CHECK_DATA:
        {
            U16 tmp_child_scrn_id;

            /* It is ready to display screen */
            num_item = mmi_um_ui_sh_ms_general_get_msg_num(scrn_cntx);

            /* Do not display a "empty popup screen". Go back to previous screen directly */
            if (num_item == 0)
            {
                /* delete current screen */
                tmp_child_scrn_id = scrn_cntx->child_scrn_id;
                result = mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
                /* delete child screen */
                mmi_um_ui_ut_del_relative_scrn(&tmp_child_scrn_id);
                return result;
            }
            
            /* Check if it has the child screen */
            if (mmi_um_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
            {
                /* folder screen is not in the history/active */
                if (!mmi_frm_scrn_is_present(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_um_ui_sh_create(entry_func, scrn_cntx);
                    /* After entry, the child processing screen will be deleted */
                }
                else
                {
                    /* The child should be removed */
                    mmi_um_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
                }
            }
            else
            {
            #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
                if (MMI_SCENARIO_STATE_ACTIVE == 
                    mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
                {
                    /* Not during SSP status, update it */
                    if (!gui_screen_smooth_scrolling_moved_by_pen())
                    {
                    #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
                        if (MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_um_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm))
                        {
                            mmi_cat_conversation_refresh(
                                    MMI_fixed_list_menu.n_items,
                                    MMI_fixed_list_menu.highlighted_item,
                                    mmi_um_ui_sh_thread_enhance_get_async_item);
                        }
                        else
                    #endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
                        {
                            mmi_cat_refresh_asyncdynamic_list(
                                    MMI_fixed_list_menu.n_items, 
                                    MMI_fixed_list_menu.highlighted_item, 
                                    mmi_um_ui_sh_get_async_item,
                                    NULL);
                        }
                    }
                }
            #endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
                /***********************************************************
                 * Other cases:
                 *  (a) SSP => during collect msg info => other screen over
                 **********************************************************/
            }
        #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
            /* try to prevent double loading, or black background */
            if ((MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_um_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm)) &&
                (!mmi_um_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id) && 
                (MMI_UM_UI_FSM_EF_UPDATE_DATA == scrn_cntx->fsm.cntx.fsm_entry_folder.state)))
            {
                scrn_cntx->child_scrn_id = mmi_um_ui_if_entry_processing(scrn_id, scrn_cntx->group_id, MMI_FALSE);
                mmi_um_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
            }
        #endif
            break;
        }
        case MMI_UM_UI_FSM_EF_UPDATE_DATA:
        {
            /* call UI interface to entry a process screen without RSK */
            if (mmi_um_ui_cc_check_scrn_alive(scrn_cntx->child_scrn_id))
            {
                /* Clean the rsk icon/string of child screen */
                if (MMI_SCENARIO_STATE_ACTIVE == 
                    mmi_frm_scrn_get_state(scrn_cntx->group_id, mmi_um_ui_ut_get_disp_scrn_id_by_scrn_id(scrn_cntx->child_scrn_id)))
                {
                    mmi_um_ui_cc_send_event(scrn_cntx->child_scrn_id, MMI_UM_UI_EVENT_CLEAN_RSK_HDLR, NULL);
                }
            }
            else
            {
                /* Entry processing screen */
            #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
                if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE ||
            #ifdef __MMI_UM_CONVERSATION_BOX__
                    (mmi_um_ui_fsm_ef_get_action(&(scrn_cntx->fsm)) != MMI_UM_UI_ACTION_GET_THRD_INFO &&
            #endif /* __MMI_UM_CONVERSATION_BOX__ */
                    mmi_um_ui_fsm_ef_get_action(&(scrn_cntx->fsm)) != MMI_UM_UI_ACTION_GET_MSG_INFO
            #ifdef __MMI_UM_CONVERSATION_BOX__
                     )
            #endif /* __MMI_UM_CONVERSATION_BOX__ */
                    )
            #endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
                {
                #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
                    if (((MMI_UM_FOLDER_MODE_THREAD_MSG == folder_mode) && 
                    (mmi_um_ui_fsm_ef_get_action(&(scrn_cntx->fsm)) == MMI_UM_UI_ACTION_GET_MSG_CONTENT)))
                    {
                        break;
                    }
                #endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
                    scrn_cntx->child_scrn_id = mmi_um_ui_if_entry_processing(scrn_id, scrn_cntx->group_id, MMI_FALSE);
                    mmi_um_ui_ut_send_init_event(scrn_cntx->child_scrn_id);
                }
            }
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_entry
 * DESCRIPTION
 *  Entry mark several folder to display the current screen.
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_general_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 num_item;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_ms_struct *aprc;
#if 0
#ifdef __MMI_UM_CONVERSATION_BOX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UM_CONVERSATION_BOX__ */
#endif /*Build Warning Fix *****/
    mmi_um_entry_folder_evt_struct entry_folder_evt;
    mmi_um_ui_ms_cntx_struct *ms_table;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.ms_folder);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    ms_table = (mmi_um_ui_ms_cntx_struct *)scrn_cntx->screen_hdlr.scrn_data;
    /* set the number of items */
    num_item = mmi_um_ui_sh_ms_general_get_msg_num(scrn_cntx);
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    if (num_item != 0)
    {
        scrn_cntx->screen_hdlr.num_of_item = num_item;
        /* search the specified highlight index based on the highlight msg id and msg type*/
        if (data_list != NULL)
        {
            for (i = 0; i < num_item; i++)
            {
                if (((srv_um_msg_node_struct*)data_list->list)[i].msg_id == scrn_cntx->screen_hdlr.hilite_info.msg_id &&
                    ((srv_um_msg_node_struct*)data_list->list)[i].msg_type == scrn_cntx->screen_hdlr.hilite_info.msg_type)
                {
                    scrn_cntx->screen_hdlr.hilite_info.index = i;
                    break;
                }
            }
        }
        
        /* error handling for highlight */
        if (scrn_cntx->screen_hdlr.hilite_info.index >= num_item)
        {
            /* highlight to last one */
            scrn_cntx->screen_hdlr.hilite_info.index = num_item - 1;
        }
    }

    /* set the marked messages */
    if (data_list != NULL
        && mmi_is_redrawing_bk_screens() == MMI_FALSE
       )
    {
        mmi_um_ui_sh_ms_general_copy_mark_msg(
                            data_list, 
                            (mmi_um_ui_ms_cntx_struct *)scrn_cntx->screen_hdlr.scrn_data, 
                            mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm)));
    }

    /* General context */
    aprc->general_aprc_cntx.grp_id = scrn_cntx->group_id;
    aprc->general_aprc_cntx.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
    aprc->general_aprc_cntx.menu_item_id = 0;
    aprc->general_aprc_cntx.title_str_id = mmi_um_ui_ut_get_str_id_by_option(scrn_cntx->screen_hdlr.ms_op);
    aprc->general_aprc_cntx.title_icon_id = IMG_UM_ENTRY_SCRN_CAPTION;
    
    if (ms_table->num_of_mark != 0)
    {
        aprc->general_aprc_cntx.lsk_str_id = STR_GLOBAL_OPTIONS;
    }
    else
    {
        aprc->general_aprc_cntx.lsk_str_id = STR_GLOBAL_MARK_ALL;
    }
    aprc->general_aprc_cntx.lsk_icon_id = IMG_GLOBAL_OPTIONS;
    aprc->general_aprc_cntx.rsk_str_id = STR_GLOBAL_BACK;
    aprc->general_aprc_cntx.rsk_icon_id = IMG_GLOBAL_BACK;
    aprc->general_aprc_cntx.csk_icon_id = IMG_GLOBAL_MARK_CSK;
    aprc->general_aprc_cntx.hilite_hdlr = mmi_um_ui_sh_ms_general_hilite_hdlr;
    aprc->general_aprc_cntx.hilite_idx = scrn_cntx->screen_hdlr.hilite_info.index;
    aprc->general_aprc_cntx.num_of_item = scrn_cntx->screen_hdlr.num_of_item;
    aprc->general_aprc_cntx.entry_func = mmi_um_ui_sh_ms_general_entry;
    aprc->general_aprc_cntx.exit_func = mmi_um_ui_sh_ms_general_exit;
    aprc->general_aprc_cntx.gui_buffer = NULL;
    aprc->general_aprc_cntx.key_hdlr.lsk_hdlr = mmi_um_ui_sh_ms_general_lsk_hdlr;
    aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = mmi_um_ui_sh_ms_general_rsk_hdlr;
    aprc->general_aprc_cntx.key_hdlr.csk_hdlr = mmi_um_ui_sh_ms_general_csk_hdlr;
    aprc->general_aprc_cntx.leave_proc = mmi_um_ui_sh_ms_general_leave_proc;

    /* Specified context */
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
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    aprc->get_item_cb = mmi_um_ui_sh_get_async_item;
    aprc->get_item_hint_cb = NULL;
    aprc->set_mark_cb = mmi_um_ui_sh_ms_general_set_mark_cb;
    aprc->get_mark_cb = mmi_um_ui_sh_ms_general_get_mark_cb;
    aprc->hilite_notify_cb = mmi_um_ui_sh_ms_general_notify_highlight;
    scrn_cntx->screen_hdlr.is_scrn_displayed = scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);

    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
    {
        return;
    }

    /* After drawing, the child should be removed */
    mmi_um_ui_ut_del_relative_scrn(&(scrn_cntx->child_scrn_id));
    
    /* Due to the category usage, it should check the screen is displayed or not */
    if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_FALSE)
    {
        mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
        if (MMI_UM_FOLDER_MODE_THREAD_MSG == mmi_um_ui_fsm_ef_get_folder_mode(&scrn_cntx->fsm))
        {
            scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
        }
 #endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */
    }

    /* global setting reset */
    if (MMI_TRUE == scrn_cntx->screen_hdlr.is_scrn_displayed)
    {
        /* Send the event out */
        MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_UM_ENTRY_FOLDER);
        entry_folder_evt.is_entry = MMI_TRUE;
        entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
        entry_folder_evt.um_user_data = (void *)scrn_cntx;
        MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_exit
 * DESCRIPTION
 *  Exit mark several folder. It needs to record the marked message
 *  information.
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_general_exit(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_entry_folder_evt_struct entry_folder_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

#ifdef __MMI_UM_CONVERSATION_BOX__
    if (NULL != scrn_cntx->aprc.user_data)
    {
        OslMfree(scrn_cntx->aprc.user_data);
        scrn_cntx->aprc.user_data = NULL;
    }
#endif /* __MMI_UM_CONVERSATION_BOX__ */    
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;

    /* Send the event out */
    MMI_FRM_INIT_EVENT(&entry_folder_evt, EVT_ID_MMI_UM_ENTRY_FOLDER);
    entry_folder_evt.is_entry = MMI_FALSE;
    entry_folder_evt.msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
    entry_folder_evt.um_user_data = (void *)scrn_cntx;
    MMI_FRM_CB_EMIT_POST_EVENT(&entry_folder_evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_destroy
 * DESCRIPTION
 *  Destory mark several screen. In this function, it should clean the screen
 *  context from central controller.
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  ?
 *****************************************************************************/
U8 mmi_um_ui_sh_ms_general_destroy(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset the mark table */
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg;
    if (scrn_cntx->screen_hdlr.scrn_data != NULL)
    {
        memset(scrn_cntx->screen_hdlr.scrn_data, 0, sizeof(mmi_um_ui_ms_cntx_struct));
        scrn_cntx->screen_hdlr.scrn_data = NULL;
    }
    
    result = mmi_um_ui_sh_destroy(arg);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_leave_proc
 * DESCRIPTION
 *  Screen leave proc. In this function, it should handle the deinit event.
 *
 * PARAMETERS
 *  evt             [IN]: Screen event from FW
 *  
 * RETURNS
 *  ?
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_general_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_RET_OK;

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_um_ui_sh_ms_general_destroy(evt->user_data);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_lsk_hdlr
 * DESCRIPTION
 *  General left soft key handler for mark several.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_general_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID opt_grp_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_ms_cntx_struct *ms_table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    ms_table = (mmi_um_ui_ms_cntx_struct *)scrn_cntx->screen_hdlr.scrn_data;

    if (ms_table->num_of_mark != 0)
    {
        /* create group */
        opt_grp_id = mmi_frm_group_create(
                                scrn_cntx->group_id, 
                                GRP_ID_AUTO_GEN, 
                                mmi_um_ui_sh_ms_general_opt_proc, 
                                (void*) scrn_cntx);
        mmi_frm_group_enter(opt_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        /* create menu cui */
        opt_grp_id = cui_menu_create(
                                opt_grp_id, 
                                CUI_MENU_SRC_TYPE_RESOURCE, 
                                CUI_MENU_TYPE_OPTION, 
                                MENU_ID_UM_MULTI_OP_OPTION, 
                                MMI_FALSE, 
                                NULL);
        /* Set default string/icon */
        cui_menu_set_default_title(
                opt_grp_id, 
                (WCHAR*)GetString(STR_GLOBAL_OPTIONS), 
                (UI_image_type)GetImage(IMG_UM_ENTRY_SCRN_CAPTION));
        scrn_cntx->child_group_id = opt_grp_id;
        cui_menu_run(opt_grp_id);
    }
    else
    {
        mmi_um_ui_sh_ms_option_mark_all(scrn_cntx);
        mmi_frm_display_dummy_screen();
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_rsk_hdlr
 * DESCRIPTION
 *  General right soft key handler for mark several.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_general_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_box_enum msg_box;
    srv_um_msg_enum msg_type;
    U32 msg_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    msg_box = scrn_cntx->screen_hdlr.folder_type.msg_box_type;
    msg_type = scrn_cntx->screen_hdlr.hilite_info.msg_type;
    msg_id = scrn_cntx->screen_hdlr.hilite_info.msg_id;

    /* Set highlight to the previous folder */
    mmi_um_highlight_msg_ind(msg_type, msg_box, (kal_uint32)msg_id);

    mmi_um_ui_sh_rsk_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_csk_hdlr
 * DESCRIPTION
 *  General right soft key handler for mark several. Use to mark/unmark
 *  selected message
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_general_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Mark/Unmark messages */
    if (mmi_um_ui_sh_ms_general_set_mark_cb(scrn_cntx->screen_hdlr.hilite_info.index))
    {
        /* redraw the check box */
        RedrawCategoryFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_hilite_hdlr
 * DESCRIPTION
 *  The mark several general highlight function.
 *
 * PARAMETERS
 *  index               [IN]: the highlight index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_general_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    MMI_BOOL result;
    srv_um_msg_info_struct **msg_detail_info;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    result = fsm->get_msg_info(scrn_cntx->scrn_id, (U16) index, 1, &msg_detail_info, NULL);
    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));

    /* Tricky for category bugs */
    if (result == MMI_FALSE)
    {
        return;
    }
    /* Tricky for category bugs */
    MMI_ASSERT(result != MMI_FALSE);
    MMI_ASSERT(data_list != NULL);

    /* Set highlight message id & type */
    scrn_cntx->screen_hdlr.hilite_info.index = index;
    scrn_cntx->screen_hdlr.hilite_info.msg_id = ((srv_um_msg_node_struct*)data_list->list)[index].msg_id;
    scrn_cntx->screen_hdlr.hilite_info.msg_type = ((srv_um_msg_node_struct*)data_list->list)[index].msg_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_notify_highlight
 * DESCRIPTION
 *  The mark several general notify highlight index function.
 *
 * PARAMETERS
 *  index               [IN]: the highlight index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_general_notify_highlight(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    srv_um_list_cntx_struct *data_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    
    if (data_list != NULL)
    {
        /* Set highlight message id & type */
        scrn_cntx->screen_hdlr.hilite_info.index = index;
        scrn_cntx->screen_hdlr.hilite_info.msg_id = ((srv_um_msg_node_struct*)data_list->list)[index].msg_id;
        scrn_cntx->screen_hdlr.hilite_info.msg_type = ((srv_um_msg_node_struct*)data_list->list)[index].msg_type;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_set_mark_cb
 * DESCRIPTION
 *  Mark sevearl general set the mark state of current message
 *      Mark => Unmark
 *      Unmark => Mark
 *
 * PARAMETERS
 *  index               [IN]: the message index
 *
 * RETURNS
 *  return MMI_TRUE
 *****************************************************************************/
S32 mmi_um_ui_sh_ms_general_set_mark_cb(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx;
    U16 reminding;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_ms_cntx_struct *mark_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* Set the mark status */
    mark_cntx = (mmi_um_ui_ms_cntx_struct *)scrn_cntx->screen_hdlr.scrn_data;

    MMI_ASSERT(mark_cntx != NULL);
    MMI_ASSERT(index < scrn_cntx->screen_hdlr.num_of_item);

    idx = index / MMI_UM_UI_BIT_MARK_STATUS_SIZE;
    reminding = index - (idx * MMI_UM_UI_BIT_MARK_STATUS_SIZE);

    /* It has been marked */
    if ((mark_cntx->mark_status[idx] >> (MMI_UM_UI_BIT_MARK_STATUS_SIZE - 1 - reminding)) & 1)
    {
        /* reest as unmarked */
        mark_cntx->mark_status[idx] &= ~(1 << (MMI_UM_UI_BIT_MARK_STATUS_SIZE - 1 - reminding));
        mark_cntx->num_of_mark--;
    }
    else
    {
        /* set as marked */
        mark_cntx->mark_status[idx] |= (1 << (MMI_UM_UI_BIT_MARK_STATUS_SIZE - 1 - reminding));
        mark_cntx->num_of_mark++;
    }
    
    if (mark_cntx->num_of_mark != 0)
    {
        ChangeLeftSoftkeyExt(STR_GLOBAL_OPTIONS);
    }
    else
    {
        ChangeLeftSoftkeyExt(STR_GLOBAL_MARK_ALL);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_get_mark_cb
 * DESCRIPTION
 *  Mark sevearl general get the mark state of current message
 *
 * PARAMETERS
 *  item_index          [IN]: the message index
 *  checkbox_image      [OUT]: the check box image(mark or unmark)
 *
 * RETURNS
 *  return MMI_TRUE
 *****************************************************************************/
S32 mmi_um_ui_sh_ms_general_get_mark_cb(S32 index, PU8 *checkbox_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx;
    U16 reminding;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_ms_cntx_struct *mark_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* get the marked/unmarked image */
    mark_cntx = (mmi_um_ui_ms_cntx_struct *)scrn_cntx->screen_hdlr.scrn_data;

    MMI_ASSERT(mark_cntx != NULL);

    idx = index / MMI_UM_UI_BIT_MARK_STATUS_SIZE;
    reminding = index - (idx * MMI_UM_UI_BIT_MARK_STATUS_SIZE);

    /* It has been marked */
    if ((mark_cntx->mark_status[idx] >> (MMI_UM_UI_BIT_MARK_STATUS_SIZE - 1 - reminding)) & 1)
    {
        *checkbox_image = (PU8)GetImage(CHECKBOX_ON_IMAGE_ID);
    }
    else
    {
        *checkbox_image = (PU8)GetImage(CHECKBOX_OFF_IMAGE_ID);
    }
/*
    if (mark_cntx->num_of_mark != 0)
    {
        set_softkey_label(GetString(STR_GLOBAL_OPTIONS), MMI_LEFT_SOFTKEY);
    }
    else
    {
        set_softkey_label(GetString(STR_GLOBAL_MARK_ALL), MMI_LEFT_SOFTKEY);
    }
    */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_copy_mark_msg
 * DESCRIPTION
 *  Update the marked context based on the new data list.
 *
 * PARAMETERS
 *  data_list           [IN]: New data list
 *  mark_cntx           [OUT]: Old mark_cntx(need to update)
 *  folder_mode         [IN]: The folder mode of this screen
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_general_copy_mark_msg(
                    srv_um_list_cntx_struct *data_list, 
                    mmi_um_ui_ms_cntx_struct *mark_cntx, 
                    mmi_um_ui_folder_mode_enum folder_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U16 idx, reminding;
    U32 tmp_mark_status[MMI_UM_UI_MAX_BIT_MARK_STATUS_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/;

    /* Copy data list to the screen context */    
    if (mark_cntx->num_of_mark == 0)
    {
        /* First entry */
        memset(mark_cntx, 0, sizeof(mmi_um_ui_ms_cntx_struct));
    #ifdef __MMI_UM_CONVERSATION_BOX__
        if (MMI_UM_FOLDER_MODE_CONVERSATION_BOX == folder_mode)
        {
            memcpy(mark_cntx->thrd_id_table, 
                   data_list->list,
                   sizeof(srv_um_thread_id_struct)*data_list->msg_number);
        }
        else
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            memcpy(mark_cntx->msg_table, 
                   data_list->list,
                   sizeof(srv_um_msg_node_struct)*data_list->msg_number);
        }
        mark_cntx->num_of_item = data_list->msg_number;
    }
    else
    {
        /* Go back history */
        memset(tmp_mark_status, 0, sizeof(tmp_mark_status));
        /* Mark status to temp buffer based on new data list */
        for (i = 0; i < SRV_UM_MAX_MSG_NUM; i++)
        {
            /* transfer to bit index */
            idx = i / MMI_UM_UI_BIT_MARK_STATUS_SIZE;
            reminding = i - (idx * MMI_UM_UI_BIT_MARK_STATUS_SIZE);

            /* Marked */
            if ((mark_cntx->mark_status[idx] >> (MMI_UM_UI_BIT_MARK_STATUS_SIZE - 1 - reminding)) & 1)
            {
                for (j = 0; j < SRV_UM_MAX_MSG_NUM; j++)
                {
                #ifdef __MMI_UM_CONVERSATION_BOX__
                    if (MMI_UM_FOLDER_MODE_CONVERSATION_BOX == folder_mode)
                    {
                        if (mark_cntx->thrd_id_table[i].type == ((srv_um_thread_id_struct *)data_list->list)[j].type &&
                            mark_cntx->thrd_id_table[i].value == ((srv_um_thread_id_struct *)data_list->list)[j].value)
                        {
                            /* transfer to bit index */
                            idx = j / MMI_UM_UI_BIT_MARK_STATUS_SIZE;
                            reminding = j - (idx * MMI_UM_UI_BIT_MARK_STATUS_SIZE);
                            tmp_mark_status[idx] |= (1 << (MMI_UM_UI_BIT_MARK_STATUS_SIZE - 1 - reminding));
                            break;
                        }
                    }
                    else
                #endif /* __MMI_UM_CONVERSATION_BOX__ */
                    {
                        if (mark_cntx->msg_table[i].msg_id == ((srv_um_msg_node_struct *)data_list->list)[j].msg_id &&
                            mark_cntx->msg_table[i].msg_type == ((srv_um_msg_node_struct *)data_list->list)[j].msg_type)
                        {
                            /* transfer to bit index */
                            idx = j / MMI_UM_UI_BIT_MARK_STATUS_SIZE;
                            reminding = j - (idx * MMI_UM_UI_BIT_MARK_STATUS_SIZE);
                            tmp_mark_status[idx] |= (1 << (MMI_UM_UI_BIT_MARK_STATUS_SIZE - 1 - reminding));
                            break;
                        }
                    }
                }
                /* Not find */
                if (j == SRV_UM_MAX_MSG_NUM)
                {
                    mark_cntx->num_of_mark--;
                }
            }
        }
        
        memset(mark_cntx->msg_table, 0, sizeof(mark_cntx->msg_table));
        memset(mark_cntx->mark_status, 0, sizeof(mark_cntx->mark_status));
        /* Copy data list info */
    #ifdef __MMI_UM_CONVERSATION_BOX__
        if (MMI_UM_FOLDER_MODE_CONVERSATION_BOX == folder_mode)
        {
            memcpy(mark_cntx->thrd_id_table, 
                   data_list->list,
                   sizeof(srv_um_thread_id_struct)*data_list->msg_number);
            mark_cntx->num_of_item = data_list->msg_number;
        }
        else
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            memcpy(mark_cntx->msg_table, 
                   data_list->list,
                   sizeof(srv_um_msg_node_struct)*data_list->msg_number);
            mark_cntx->num_of_item = data_list->msg_number;
        }
        /* Copy mark status */
        memcpy(mark_cntx->mark_status, 
               tmp_mark_status, 
               sizeof(tmp_mark_status));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_get_msg_num
 * DESCRIPTION
 *  Get the number of data function. It should call finite state machine 
 *  api to get the information.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 *  
 * RETURNS
 *  The number of items
 *****************************************************************************/
U16 mmi_um_ui_sh_ms_general_get_msg_num(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_of_item;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_item = 0;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);

    num_of_item = fsm->get_msg_num(scrn_cntx->scrn_id);

    return num_of_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_opt_proc
 * DESCRIPTION
 *  The proc function of option menu for mark several screen
 *
 * PARAMETERS
 *  evt                 [IN]: event
 *  
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_general_opt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    cui_menu_event_struct *menu_evt;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    ret = MMI_RET_OK;
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            ret = mmi_um_ui_sh_ms_general_opt_list_entry_hdlr(evt);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            ret = mmi_um_ui_sh_ms_general_opt_item_select_hdlr(evt);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            scrn_cntx->child_group_id = 0;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_opt_list_entry_hdlr
 * DESCRIPTION
 *  List entry proc of menu cui.
 *  Seperate each event to let function more modulaized.
 *  The sub-function of mmi_um_ui_sh_ms_general_opt_proc.
 *
 * PARAMETERS
 *  evt                 [IN]: event structure pointer
 *  
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_general_opt_list_entry_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    cui_menu_event_struct *menu_evt;
    mmi_um_ui_ms_cntx_struct *ms_table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    ret = MMI_RET_OK;
    /* In list entry event, it should consider the parent mentu id */
    switch (menu_evt->parent_menu_id)
    {
        case MENU_ID_UM_MULTI_OP_OPTION:
        {
            ms_table = (mmi_um_ui_ms_cntx_struct *)scrn_cntx->screen_hdlr.scrn_data;
            MMI_ASSERT(NULL != ms_table);
                /* end user does not select any message, hide action menu item */
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_DELETE, 
                                         MMI_TRUE);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_MOVE_TO_ARCHIVE, 
                                         MMI_TRUE);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifndef __UM_FOLDER__
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_MOVE_TO_SIM, 
                                         MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_COPY_TO_SIM, 
                                         MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE, 
                                         MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_COPY_TO_PHONE, 
                                         MMI_TRUE);
#endif /* __UM_FOLDER__ */
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_UNMARK_ALL, 
                                         MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_MARK_ALL, 
                                         MMI_TRUE);

            if (ms_table->num_of_mark != 0)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_UNMARK_ALL, 
                                         MMI_FALSE);
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         mmi_um_ui_ut_get_menu_id_by_option(scrn_cntx->screen_hdlr.ms_op), 
                                         MMI_FALSE);
                
            }
            if (ms_table->num_of_mark != ms_table->num_of_item)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, 
                                         MENU_ID_UM_MULTI_OP_MARK_ALL, 
                                         MMI_FALSE);
            }
            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_opt_item_select_hdlr
 * DESCRIPTION
 *  Item select proc of menu cui.
 *  Seperate each event to let function more modulaized.
 *  The sub-function of mmi_um_ui_sh_ms_general_opt_proc.
 *
 * PARAMETERS
 *  evt                 [IN]: event structure pointer
 *  
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_general_opt_item_select_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)menu_evt->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    ret = MMI_RET_OK;
    switch (menu_evt->highlighted_menu_id)
    {
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MENU_ID_UM_MULTI_OP_MOVE_TO_ARCHIVE:
        {
        #ifdef __USB_IN_NORMAL_MODE__
            if (srv_usb_is_in_mass_storage_mode())
            {
                mmi_usb_app_unavailable_popup(0);
            }
            else
        #endif /* __USB_IN_NORMAL_MODE__ */
            {
                mmi_um_ui_sh_ms_general_opt_op_confirm(menu_evt->highlighted_menu_id, 
                                                       menu_evt->user_data);
            }
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        /*----------------------------------------------------------------*/
        /* Add code here to detect USB mode when try to delete            */
        /* archive box messages. So the behavior between UM and message   */
        /* App will be uinified and MAUI_02452811 will be solved.        */
        /*----------------------------------------------------------------*/
        case MENU_ID_UM_MULTI_OP_DELETE:
        {
        #if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__))
            if ((SRV_UM_MSG_BOX_ARCHIVE == (scrn_cntx->screen_hdlr.folder_type.msg_box_type & SRV_UM_MSG_BOX_ARCHIVE)) &&
                 srv_usb_is_in_mass_storage_mode())
            {
                mmi_usb_app_unavailable_popup(0);
            }
            else
        #endif
          	{ 
		        mmi_um_ui_sh_ms_general_opt_op_confirm(menu_evt->highlighted_menu_id, 
                                       menu_evt->user_data);
          	}
            break; 
        }
    #ifndef __UM_FOLDER__
        case MENU_ID_UM_MULTI_OP_COPY_TO_PHONE:
        case MENU_ID_UM_MULTI_OP_COPY_TO_SIM:
        case MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE:
        case MENU_ID_UM_MULTI_OP_MOVE_TO_SIM:
        {
            mmi_um_ui_sh_ms_general_opt_op_confirm(menu_evt->highlighted_menu_id, 
                                                   menu_evt->user_data);
            break;
        }
#endif /* __UM_FOLDER__ */
        case MENU_ID_UM_MULTI_OP_MARK_ALL:
        case MENU_ID_UM_MULTI_OP_UNMARK_ALL:
        {
            mmi_um_ui_sh_ms_general_opt_mark_unmark_proc(menu_evt->highlighted_menu_id, 
                                                         menu_evt->user_data);
            scrn_cntx->child_group_id = 0;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_opt_op_confirm
 * DESCRIPTION
 *  Display a confirm for ms operations.
 *
 * PARAMETERS
 *  menu_id                 [IN]: selected menu id
 *  user_data               [IN]: screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_general_opt_op_confirm(U16 menu_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    mmi_um_ui_ms_cntx_struct *ms_table;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    U8 temp_str[(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH];
    U8 str_msg_num[MMI_UM_UI_MAX_MSG_NUM_DIGIT + 1];
    U8 str_msg_num_ucs2[(MMI_UM_UI_MAX_MSG_NUM_DIGIT + 1) * ENCODING_LENGTH];
    mmi_confirm_property_struct confirm_param;
    mmi_um_ui_sh_confirm_action_enum action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Launch the process */
    /* set screen context before confirm popup, framework limitation */
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)user_data;
    MMI_ASSERT(NULL != scrn_cntx);

    ms_table = (mmi_um_ui_ms_cntx_struct *)scrn_cntx->screen_hdlr.scrn_data;
    MMI_ASSERT(NULL != ms_table);

    /* construct the confirm string */
    memset(temp_str, 0, sizeof(temp_str));
    memset(str_msg_num, 0, sizeof(str_msg_num));
    memset(str_msg_num_ucs2, 0, sizeof(str_msg_num_ucs2));

    /* Get the string of each operation */
    str_id = mmi_um_ui_sh_ms_query_string_action(menu_id);
    /* Get the lsk function pointer */
    action = mmi_um_ui_sh_ms_query_action(menu_id);

    /* Concate the string */
    /* String => Delete N message or messages ? */
    mmi_ucs2cat((S8 *)temp_str, (S8 *) GetString(str_id));
    mmi_ucs2cat((S8 *)temp_str, (S8 *)L" ");
    
    sprintf((S8*) str_msg_num, "%d ", ms_table->num_of_mark);
    mmi_asc_to_ucs2((S8*) str_msg_num_ucs2, (S8*) str_msg_num);
    mmi_ucs2cat((S8 *)temp_str, (S8 *)str_msg_num_ucs2);

    if (ms_table->num_of_mark > 1)
    {
        mmi_ucs2cat((S8 *)temp_str, (S8 *)GetString(STR_UM_MSGS_WITH_QUESTION_MARK_ID));
    }
    else
    {
        mmi_ucs2cat((S8 *)temp_str, (S8 *)GetString(STR_UM_MSG_WITH_QUESTION_MARK_ID));
    }

    mmi_confirm_property_init(&confirm_param, CNFM_TYPE_YESNO);
    mmi_um_ui_sh_set_confirm_param(&confirm_param, scrn_cntx, action);
    scrn_cntx->screen_hdlr.cf_grp_id = mmi_confirm_display(
                                                (WCHAR *)temp_str, 
                                                MMI_EVENT_QUERY, 
                                                &confirm_param);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_opt_mark_unmark_proc
 * DESCRIPTION
 *  Mark/Unmark handler for option menu, it is used to hide/unhide mark all
 *  and unmark all
 *
 * PARAMETERS
 *  menu_id                 [IN]: selected menu id
 *  user_data               [IN]: screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_general_opt_mark_unmark_proc(U16 menu_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    switch (menu_id)
    {
        case MENU_ID_UM_MULTI_OP_MARK_ALL:
        {
            mmi_um_ui_sh_ms_option_mark_all(scrn_cntx);
            break;
        }
        case MENU_ID_UM_MULTI_OP_UNMARK_ALL:
        {
            mmi_um_ui_sh_ms_option_unmark_all(scrn_cntx);
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_intuitive_cmd_cb
 * DESCRIPTION
 *  In FTE, the intuitive command should not work.
 *
 * PARAMETERS
 *  tap_type        [IN]: the tap type
 *  index           [IN]: highlight index
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_general_intuitive_cmd_cb(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* All do nothing */
    return;
}
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_general_get_entry_func
 * DESCRIPTION
 *  Get the entry function pointer by different folder mode
 *
 * PARAMETERS
 *  mode                    [IN]: the folder mode
 *  
 * RETURNS
 *  Entry function pointer
 *****************************************************************************/
mmi_um_entry_func_ptr mmi_um_ui_sh_ms_general_get_entry_func(mmi_um_ui_folder_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_entry_func_ptr func_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    func_ptr = NULL;

    switch (mode)
    {
        case MMI_UM_FOLDER_MODE_DEFAULT:
        {
            func_ptr = mmi_um_ui_sh_ms_general_entry;
            break;
        }
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_FOLDER_MODE_CONVERSATION_BOX:
        {
            func_ptr = mmi_um_ui_sh_ms_cs_entry;
            break;
        }
        case MMI_UM_FOLDER_MODE_THREAD_MSG:
        {
            func_ptr = mmi_um_ui_sh_ms_general_entry;
            break;
        }
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return func_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_option_process_delete
 * DESCRIPTION
 *  Process the mark several operations. (Delete)
 *  Invoke the mark several operation delete screen.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_option_process_delete(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_um_ui_sh_ms_option_process_action(MMI_UM_UI_ACTION_MARK_SEVERAL_OP_DELETE, scrn_cntx);
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_option_process_mov2arc
 * DESCRIPTION
 *  Process the mark several operations. (Move to archive)
 *  Invoke the mark several operation move to archive screen.
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_option_process_mov2arc(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_um_ui_sh_ms_option_process_action(MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_ARCHIVE, scrn_cntx);
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_option_process_move2sim
 * DESCRIPTION
 *  Process the mark several operations. (Move to SIM)
 *  Invoke the mark several operation delete screen.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_option_process_mov2sim(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_um_ui_sh_ms_option_process_action(MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_SIM, scrn_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_option_process_move2phone
 * DESCRIPTION
 *  Process the mark several operations. (Move to Phone)
 *  Invoke the mark several operation delete screen.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_option_process_mov2phone(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_um_ui_sh_ms_option_process_action(MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_PHONE, scrn_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_option_process_cpy2sim
 * DESCRIPTION
 *  Process the mark several operations. (Copy to SIM)
 *  Invoke the mark several operation delete screen.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_option_process_cpy2sim(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_um_ui_sh_ms_option_process_action(MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_SIM, scrn_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_option_process_cpy2phone
 * DESCRIPTION
 *  Process the mark several operations. (Copy to Phone)
 *  Invoke the mark several operation delete screen.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  
 * RETURNS
 *  Handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_option_process_cpy2phone(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_um_ui_sh_ms_option_process_action(MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_PHONE, scrn_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_option_process_action
 * DESCRIPTION
 *  General function for processing the mark several operation.
 *
 * PARAMETERS
 *  action_type         [IN]: the action type
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_option_process_action(mmi_um_ui_req_srv_action_enum action_type, 
                                              mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* invoke the action screen */
    switch (action_type)
    {
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_DELETE:
        {
            scrn_id = mmi_um_ui_if_entry_ms_op_delete_folder(
                                0, 
                                scrn_cntx->screen_hdlr.folder_type.msg_box_type, 
                                scrn_cntx->group_id, 
                                MMI_FALSE);
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_ARCHIVE:
        {
            scrn_id = mmi_um_ui_if_entry_ms_op_mov2arc_folder(
                                0, 
                                scrn_cntx->screen_hdlr.folder_type.msg_box_type, 
                                scrn_cntx->group_id, 
                                MMI_FALSE);
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifndef __UM_FOLDER__
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_SIM:
        {
            scrn_id = mmi_um_ui_if_entry_ms_op_mov2sim(
                                0, 
                                scrn_cntx->screen_hdlr.folder_type.msg_box_type, 
                                scrn_cntx->group_id, 
                                MMI_FALSE);
            break;
        }
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_PHONE:
        {
            scrn_id = mmi_um_ui_if_entry_ms_op_mov2phone(
                                0, 
                                scrn_cntx->screen_hdlr.folder_type.msg_box_type, 
                                scrn_cntx->group_id, 
                                MMI_FALSE);
            break;
        }
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_SIM:
        {
            scrn_id = mmi_um_ui_if_entry_ms_op_cpy2sim(
                                0, 
                                scrn_cntx->screen_hdlr.folder_type.msg_box_type, 
                                scrn_cntx->group_id, 
                                MMI_FALSE);
            break;
        }
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_PHONE:
        {
            scrn_id = mmi_um_ui_if_entry_ms_op_cpy2phone(
                                0, 
                                scrn_cntx->screen_hdlr.folder_type.msg_box_type, 
                                scrn_cntx->group_id, 
                                MMI_FALSE);
            break;
        }
    #endif /* __UM_FOLDER__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    /* transfer the mark several status list to child screen */
    mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_SET_MS_LIST, scrn_cntx->screen_hdlr.scrn_data);

    /* Remove the mark several status list from parent screen */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_REL_MS_LIST, NULL);

    /* start to run mark several operation */
    mmi_um_ui_ut_send_init_event(scrn_id);

    /* Kill myself */
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_option_mark_all
 * DESCRIPTION
 *  Mark all items and go back to previous screen
 *
 * PARAMETERS
 *  scrn_cntx:          [IN]    screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_option_mark_all(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 idx, reminding;
    mmi_um_ui_ms_cntx_struct *ms_table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ms_table = (mmi_um_ui_ms_cntx_struct *)scrn_cntx->screen_hdlr.scrn_data;

    for (i = 0 ; i < ms_table->num_of_item ; i++)
    {
        /* transfer to bit index */
        idx = i / MMI_UM_UI_BIT_MARK_STATUS_SIZE;
        reminding = i - (idx * MMI_UM_UI_BIT_MARK_STATUS_SIZE);

        /* Unmarked */
        if (!((ms_table->mark_status[idx] >> (MMI_UM_UI_BIT_MARK_STATUS_SIZE - 1 - reminding)) & 1))
        {
            /* set as marked */
            ms_table->mark_status[idx] |= (1 << (MMI_UM_UI_BIT_MARK_STATUS_SIZE - 1 - reminding));
        }
    }

    ms_table->num_of_mark = ms_table->num_of_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_option_unmark_all
 * DESCRIPTION
 *  Unmark all items and go back to previous screen
 *
 * PARAMETERS
 *  scrn_cntx:          [IN]    screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_option_unmark_all(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_ms_cntx_struct *ms_table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ms_table = (mmi_um_ui_ms_cntx_struct *)scrn_cntx->screen_hdlr.scrn_data;

    memset(ms_table->mark_status, 0, sizeof(ms_table->mark_status));

    ms_table->num_of_mark = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_action_init
 * DESCRIPTION
 *  Initialize the mark sevearl operation screen variable. It shall trigger 
 *  the fsm initial function to initialize the fsm context.
 *  It is the general initialize function.
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  setting                 [IN]: Setting
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_ms_action_init(mmi_um_ui_cc_scrn_cntx_struct * scrn_cntx, 
                                     mmi_um_ui_cc_scrn_cntx_setting_struct * setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    mmi_um_ui_fsm_op_setting_struct fsm_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    
    /* FSM initialize */
    memset(&(fsm_setting), 0, sizeof(mmi_um_ui_fsm_op_setting_struct));
    fsm_setting.action_type = MMI_UM_UI_ACTION_NONE;
    fsm_setting.folder_type = setting->folder;
    fsm_setting.scrn_callback_hdlr = mmi_um_ui_sh_ms_action_fsm_cb;
    fsm_setting.scrn_id = scrn_cntx->scrn_id;
    fsm_setting.data = scrn_cntx->screen_hdlr.scrn_data;
    mmi_um_ui_fsm_op_init(&(scrn_cntx->fsm), fsm_setting);
    
    /* Appearance initialize */
    mmi_um_ui_aprc_set_cntx(&(scrn_cntx->aprc), setting->aprc_type);

    /* Screen handler initialize */
    scrn_cntx->screen_hdlr.disp_scrn_id = setting->disp_scrn_id;
    scrn_cntx->screen_hdlr.folder_type = setting->folder;
    memset(&(scrn_cntx->screen_hdlr.hilite_info), 0, sizeof(mmi_um_ui_sh_hilite_info_struct));
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_FALSE;
    scrn_cntx->screen_hdlr.num_of_item = 0;
    scrn_cntx->screen_hdlr.scrn_data = setting->scrn_data;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_action_event_hdlr
 * DESCRIPTION
 *  Mark sevearl action general event handler. Receive the event from the 
 *  Central controller and it needs to handle the event by itself or pass to 
 *  finite state machine.
 *
 * PARAMETERS
 *  scrn_id             [IN]: the screen id
 *  event               [IN]: the event id
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_ms_action_event_hdlr(U16 scrn_id, U16 event, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    result = MMI_TRUE;
    switch (event)
    {
        case MMI_UM_UI_EVENT_INIT:
        case MMI_UM_UI_EVENT_ABORT:
        {
            result = mmi_um_ui_sh_tsfr_fsm_event(event,scrn_cntx,arg);
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            mmi_um_ui_sh_evt_hdlr_delete(scrn_cntx, arg);
            break;
        }
        case MMI_UM_UI_EVENT_SET_MS_LIST:
        {
            scrn_cntx->screen_hdlr.scrn_data = arg;
            scrn_cntx->fsm.event_hdlr(scrn_id, MMI_UM_UI_FSM_EVENT_SET_FSM_DATA, arg);
            break;
        }
        case MMI_UM_UI_EVENT_SET_OP_TYPE:
        {
            mmi_um_ui_req_srv_action_enum *action;

            action = (mmi_um_ui_req_srv_action_enum *)arg;
            mmi_um_ui_fsm_op_set_op_type(&(scrn_cntx->fsm), *action);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_action_fsm_cb
 * DESCRIPTION
 *  A mark sevearl action general callback is regitered to finite state 
 *  machine. 
 *  It is used to know the state and status from the finite state machine. 
 *  Screen handler needs to display some screens if it is necessary.
 *  Currently, it uses the Entry folder finite state machine and it needs to 
 *  handle 5 states situation.
 *
 * PARAMETERS
 *  scrn_id             [IN]: Current screen id
 *  state               [IN]: State of finite state machine
 *  status              [IN]: In that state, the current status
 *  
 * RETURNS
 *  MMI_TRUE: handle the callback successfully
 *  MMI_FALSE: fail to handle this callback
 *****************************************************************************/
MMI_BOOL mmi_um_ui_sh_ms_action_fsm_cb(U16 scrn_id, U16 state, U16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_str_id;
    MMI_BOOL result;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    switch (state)
    {
        case MMI_UM_UI_FSM_OP_OPERATION:
        {
            if (status == MMI_UM_UI_REQ_SRV_PROGRESS)
            {
                /* Entry action screen */
                mmi_um_ui_sh_create(mmi_um_ui_sh_ms_action_entry, scrn_cntx);
                StartTimerEx(UM_INPROGRESS_TIMER_ID, MMI_UM_UI_PROGRESS_INTERVAL, mmi_um_ui_sh_ms_action_timeout_hdlr, scrn_cntx);
            }
            else if (status == MMI_UM_UI_REQ_SRV_CANCELLING)
            {
                mmi_um_ui_sh_ms_action_update((void *)scrn_cntx, 
                                              STR_GLOBAL_CANCELLING, 
                                              0, 
                                              NULL, 
                                              0);
                StopTimer(UM_INPROGRESS_TIMER_ID);
            }
            else if (status == MMI_UM_UI_REQ_SRV_CANCEL_FAIL)
            {
                /* it should be impossible */
                mmi_popup_display_simple(
                        (WCHAR *)get_string(STR_GLOBAL_BUSY_TRY_LATER), 
                        MMI_EVENT_FAILURE, 
                        scrn_cntx->group_id, 
                        NULL);
                StopTimer(UM_INPROGRESS_TIMER_ID);
            }
            else if (status == MMI_UM_UI_REQ_SRV_FINISH)
            {
                /* update the screen */
                msg_str_id = mmi_um_ui_ut_get_activate_str_id_by_op(
                                (mmi_um_ui_req_srv_action_enum)mmi_um_ui_fsm_op_get_action(&(scrn_cntx->fsm)));
                mmi_um_ui_sh_ms_action_update((void *)scrn_cntx, 
                                              msg_str_id, 
                                              0, 
                                              NULL, 
                                              100);

                mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
                StopTimer(UM_INPROGRESS_TIMER_ID);
            }
            else if (status == MMI_UM_UI_REQ_SRV_FAIL)
            {
                /* update the screen */
                msg_str_id = mmi_um_ui_ut_get_activate_str_id_by_op(
                                (mmi_um_ui_req_srv_action_enum)mmi_um_ui_fsm_op_get_action(&(scrn_cntx->fsm)));
                mmi_um_ui_sh_ms_action_update((void *)scrn_cntx, 
                                              msg_str_id, 
                                              0, 
                                              NULL, 
                                              100);
                /* display number of message could not proceed */
                mmi_um_ui_sh_ms_action_unfinished_notify(scrn_cntx);
                mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
                StopTimer(UM_INPROGRESS_TIMER_ID);
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_action_entry
 * DESCRIPTION
 *  Entry mark several action process screen.
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_action_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_str_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_loading_pgrs_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.loading_pgrs);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg->user_data;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* General context */
    aprc->general_aprc_cntx.grp_id = scrn_cntx->group_id;
    aprc->general_aprc_cntx.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
    aprc->general_aprc_cntx.rsk_str_id = STR_GLOBAL_CANCEL;
    aprc->general_aprc_cntx.rsk_icon_id = IMG_GLOBAL_BACK;
    aprc->general_aprc_cntx.entry_func = mmi_um_ui_sh_ms_action_entry;
    aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = mmi_um_ui_sh_ms_action_rsk_hdlr;
    aprc->general_aprc_cntx.leave_proc = mmi_um_ui_sh_ms_action_leave_proc;

    /* Specified context */
    /* Deleting or Moving */
    msg_str_id = mmi_um_ui_ut_get_activate_str_id_by_op(
                                (mmi_um_ui_req_srv_action_enum)mmi_um_ui_fsm_op_get_action(&(scrn_cntx->fsm)));  
    aprc->message = get_string(msg_str_id);
    scrn_cntx->aprc.draw_func(&aprc_union, scrn_cntx->aprc.st_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_action_update
 * DESCRIPTION
 *  Update mark several action screen. In this function, it should change the
 *  words in the screen and disable RSK handler because end user press
 *  "CANCEL" button
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  body_str_id     [IN]: The updated string id
 *  rsk_id          [IN]: The RSK string id
 *  rsk_hdlr        [IN]: The right soft key handler
 *  forced_value_p  [IN]: Force to set the percentage value
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_action_update(void *arg, U16 body_str_id, U16 rsk_str_id, void (*rsk_hdlr)(void), U8 forced_value_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_loading_pgrs_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.loading_pgrs);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    if (MMI_SCENARIO_STATE_ACTIVE !=
        mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
    {
        /* Not active screen, it should not update */
        return;
    }

    if (0 == forced_value_p)
    {
        percentage = mmi_um_ui_fsm_query_status(&(scrn_cntx->fsm));
    }
    else
    {
        percentage = forced_value_p;
    }

    /* General context */
    aprc->general_aprc_cntx.rsk_str_id = rsk_str_id;
    aprc->general_aprc_cntx.key_hdlr.rsk_hdlr = rsk_hdlr;

    /* Specified context */
    /* Cancelling */
    aprc->message = get_string(body_str_id);
    aprc->percentage = percentage;
    scrn_cntx->aprc.redraw_func(&aprc_union, 
                                scrn_cntx->aprc.st_type, 
                                (mmi_um_ui_aprc_redraw_type_enum)(MMI_UM_UI_APRC_REDRAW_KEY | MMI_UM_UI_APRC_REDRAW_BODY));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_action_rsk_hdlr
 * DESCRIPTION
 *  General right soft key handler for mark several action screen.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_action_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_ABORT, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_action_unfinished_notify
 * DESCRIPTION
 *  Display a popup notification to end user while operation is fail
 *
 * PARAMETERS
 *  scrn_cntx               [IN]: the screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_ms_action_unfinished_notify(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_string = 0;
    U16 num_of_fail;
    U8 *temp_str = NULL;
    U8 *str_msg_num = NULL;
    U8 *str_msg_num_ucs2 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Display number of fail messages */
    /* string of fail : N Message(s) Unfinished */
    temp_str = OslMalloc(sizeof(U8)*(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH);
    str_msg_num = OslMalloc(sizeof(U8)*(MMI_UM_UI_MAX_MSG_NUM_DIGIT + 1));
    str_msg_num_ucs2 = OslMalloc(sizeof(U8)*(MMI_UM_UI_MAX_MSG_NUM_DIGIT + 1) * ENCODING_LENGTH);

    memset(temp_str, 0, sizeof(sizeof(U8)*(MMI_UM_UI_MAX_CONFIRM_STR_LEN + 1) * ENCODING_LENGTH));
    memset(str_msg_num, 0, sizeof(sizeof(U8)*(MMI_UM_UI_MAX_MSG_NUM_DIGIT + 1)));
    memset(str_msg_num_ucs2, 0, sizeof(sizeof(U8)*(MMI_UM_UI_MAX_MSG_NUM_DIGIT + 1) * ENCODING_LENGTH));

    num_of_fail = mmi_um_ui_fsm_op_get_num_of_fail(&(scrn_cntx->fsm));
    sprintf((S8*) str_msg_num, "%d ", num_of_fail);
    mmi_asc_to_ucs2((S8*) str_msg_num_ucs2, (S8*) str_msg_num);
    mmi_ucs2cat((S8 *)temp_str, (S8 *)str_msg_num_ucs2);

    switch (scrn_cntx->fsm.cntx.fsm_operation.action_type)
    {
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_DELETE:
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_UI_ACTION_MS_DELETE_THRD_MSG:
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            if (num_of_fail > 1)
            {
                error_string = STR_UM_MULTI_OP_UNDELETED_WITH_MSGS_ID;
            }
            else
            {
                error_string = STR_UM_MULTI_OP_UNDELETED_WITH_MSG_ID;
            }
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_ARCHIVE:
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_SIM:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_PHONE:
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MMI_UM_UI_ACTION_MS_MOV2ARC_THRD_MSG:
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            if (num_of_fail > 1)
            {
                error_string = STR_UM_MULTI_OP_UNMOVED_WITH_MSGS_ID;
            }
            else
            {
                error_string = STR_UM_MULTI_OP_UNMOVED_WITH_MSG_ID;
            }
            break;
        }
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_SIM:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_PHONE:
        {
            if (num_of_fail > 1)
            {
                error_string = STR_UM_MULTI_OP_UNCOPIED_WITH_MSGS_ID;
            }
            else
            {
                error_string = STR_UM_MULTI_OP_UNCOPIED_WITH_MSG_ID;
            }
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    mmi_ucs2cat((S8 *)temp_str, 
                (S8 *)GetString(error_string));
    /* popup rule */
    mmi_popup_display_simple(
            (WCHAR *)temp_str, 
            MMI_EVENT_FAILURE, 
            scrn_cntx->group_id, 
            NULL);

    OslMfree(temp_str);
    OslMfree(str_msg_num);
    OslMfree(str_msg_num_ucs2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_action_timeout_hdlr
 * DESCRIPTION
 *  It is used to update the current screen for mark several operation.
 *
 * PARAMETERS
 *  arg                     [IN]: the screen context
 *  
 * RETURNS
 *  MMI_TRUE: handle this event successfully
 *  MMI_FALSE: fail to handle this event
 *****************************************************************************/
void mmi_um_ui_sh_ms_action_timeout_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage;
    U16 action_str_id;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_aprc_st_union aprc_union;
    mmi_um_ui_aprc_st_loading_pgrs_struct *aprc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&aprc_union, 0, sizeof(mmi_um_ui_aprc_st_union));
    aprc = &(aprc_union.loading_pgrs);
    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg;
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    /* query current status */
    percentage = mmi_um_ui_fsm_query_status(&(scrn_cntx->fsm));

    /* Update the screen if necessary */
    if (MMI_SCENARIO_STATE_ACTIVE ==
        mmi_frm_scrn_get_state(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id))
    {
        /* General context */
        /* Done need to set because of no modification */

        /* Specified context */
        action_str_id = mmi_um_ui_ut_get_activate_str_id_by_op(
                                (mmi_um_ui_req_srv_action_enum)mmi_um_ui_fsm_op_get_action(&(scrn_cntx->fsm)));
        aprc->message = get_string(action_str_id);
        aprc->percentage = percentage;
        scrn_cntx->aprc.redraw_func(&aprc_union, 
                                    scrn_cntx->aprc.st_type, 
                                    MMI_UM_UI_APRC_REDRAW_BODY);
    }

    StartTimerEx(UM_INPROGRESS_TIMER_ID, MMI_UM_UI_PROGRESS_INTERVAL, mmi_um_ui_sh_ms_action_timeout_hdlr, scrn_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_action_leave_proc
 * DESCRIPTION
 *  Screen leave proc. In this function, it should handle the deinit event.
 *
 * PARAMETERS
 *  evt             [IN]: Screen event from FW
 *  
 * RETURNS
 *  ?
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_ms_action_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_RET_OK;

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_um_ui_sh_ms_general_destroy(evt->user_data);
            StopTimer(UM_INPROGRESS_TIMER_ID);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_query_string_action
 * DESCRIPTION
 *  Query the string of each menu item.
 *
 * PARAMETERS
 *  menu_id             [IN]: Current menu id
 *  
 * RETURNS
 *  String id
 *****************************************************************************/
U16 mmi_um_ui_sh_ms_query_string_action(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = 0;
    switch (menu_id)
    {
        case MENU_ID_UM_MULTI_OP_DELETE:
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MENU_ID_UM_MS_CS_BOX_OPT_DELETE:
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            str_id = STR_GLOBAL_DELETE;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MENU_ID_UM_MULTI_OP_MOVE_TO_ARCHIVE:
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MENU_ID_UM_MS_CS_BOX_OPT_MOVE_TO_ARCH:
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        {
            str_id = STR_UM_MOVE_ID;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifndef __UM_FOLDER__
        case MENU_ID_UM_MULTI_OP_MOVE_TO_SIM:
        case MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE:
        {
            str_id = STR_UM_MOVE_ID;
            break;
        }
        case MENU_ID_UM_MULTI_OP_COPY_TO_SIM:
        case MENU_ID_UM_MULTI_OP_COPY_TO_PHONE:
        {
            str_id = STR_UM_COPY_ID;
            break;
        }
    #endif /* __UM_FOLDER__ */
        case MENU_ID_UM_MULTI_OP_MARK_ALL:
        case MENU_ID_UM_MULTI_OP_UNMARK_ALL:
        {
            /* No string */
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_ms_query_string_action
 * DESCRIPTION
 *  Query the string of each menu item.
 *
 * PARAMETERS
 *  menu_id             [IN]: Current menu id
 *  
 * RETURNS
 *  action enum
 *****************************************************************************/
mmi_um_ui_sh_confirm_action_enum mmi_um_ui_sh_ms_query_action(MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_sh_confirm_action_enum cf_action = MMI_UM_UI_SH_CF_NONE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
        case MENU_ID_UM_MULTI_OP_DELETE:
        {
            cf_action = MMI_UM_UI_SH_CF_MS_DELETE;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MENU_ID_UM_MULTI_OP_MOVE_TO_ARCHIVE:
        {
            cf_action = MMI_UM_UI_SH_CF_MS_MOV2ARC;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifndef __UM_FOLDER__
        case MENU_ID_UM_MULTI_OP_MOVE_TO_SIM:
        {
            cf_action = MMI_UM_UI_SH_CF_MS_MOV2SIM;
            break;
        }
        case MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE:
        {
            cf_action = MMI_UM_UI_SH_CF_MS_MOV2PHONE;
            break;
        }
        case MENU_ID_UM_MULTI_OP_COPY_TO_SIM:
        {
            cf_action = MMI_UM_UI_SH_CF_MS_CPY2SIM;
            break;
        }
        case MENU_ID_UM_MULTI_OP_COPY_TO_PHONE:
        {
            cf_action = MMI_UM_UI_SH_CF_MS_CPY2PHONE;
            break;
        }
    #endif /* __UM_FOLDER__ */
    #ifdef __MMI_UM_CONVERSATION_BOX__
        case MENU_ID_UM_MS_CS_BOX_OPT_DELETE:
        {
            cf_action = MMI_UM_UI_SH_CF_MS_CS_OPT_DELETE;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MENU_ID_UM_MS_CS_BOX_OPT_MOVE_TO_ARCH:
        {
            cf_action = MMI_UM_UI_SH_CF_MS_CS_OPT_MOV2ARC;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return cf_action;
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_create
 * DESCRIPTION
 *  General Create function for screen handler module
 *
 * PARAMETERS
 *  entry_func_ptr          [IN]: the entry funciton pointer
 *  scrn_cntx               [IN]: the screen context
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_create(mmi_um_entry_func_ptr entry_func_ptr, mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);  
#ifdef __MMI_BT_MAP_CLIENT__
    if (SCR_ID_UM_FOLDER == scrn_cntx->screen_hdlr.disp_scrn_id)
    {  
        mmi_scrn_essential_struct scrn_arg;
        
        g_aprc_enter_tab = MMI_TRUE;
        g_enter_from_bt = MMI_FALSE;
        scrn_arg.group_id = scrn_cntx->group_id;
        scrn_arg.scrn_id = scrn_cntx->screen_hdlr.disp_scrn_id;
        scrn_arg.user_data = scrn_cntx;
        mmi_frm_scrn_set_user_data(scrn_arg.group_id, 
                             scrn_arg.scrn_id,
                             (void *)scrn_cntx);
        mmi_um_ui_sh_general_folder_tab_entry(&scrn_arg);
        /*mmi_frm_scrn_first_enter(scrn_cntx->group_id, 
                             scrn_cntx->screen_hdlr.disp_scrn_id,
                             mmi_um_ui_sh_general_folder_tab_entry,
                             (void*)scrn_cntx);*/
        //mmi_um_ui_sh_general_folder_tab_entry(&scrn_arg);
    }
    else
        mmi_frm_scrn_first_enter(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, (FuncPtr)entry_func_ptr, (void *)scrn_cntx);
#else
    mmi_frm_scrn_first_enter(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, (FuncPtr)entry_func_ptr, (void *)scrn_cntx);
#endif /* __MMI_BT_MAP_CLIENT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_rsk_hdlr
 * DESCRIPTION
 *  General Right soft key handler for screen handler module
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    
    mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_destroy
 * DESCRIPTION
 *  Destory screen. In this function, it should clean the screen context 
 *  from central controller.
 *
 * PARAMETERS
 *  arg             [IN]: Screen context
 *  
 * RETURNS
 *  ?
 *****************************************************************************/
U8 mmi_um_ui_sh_destroy(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 fsm_event;
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_TRUE;

    scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)arg;

    /* Notify parent screen deleted */
    mmi_um_ui_ut_notify_scrn_deleted(scrn_cntx->parent_scrn_id);

    /* Send Delete event to finite state machine if necessary */
    fsm_event = mmi_um_ui_ut_get_fsm_event_by_ui_event(MMI_UM_UI_EVENT_DELETE);
    if (scrn_cntx->fsm.type != MMI_UM_UI_FSM_NONE)
    {
        if (NULL != scrn_cntx->fsm.event_hdlr)
        {
            result = scrn_cntx->fsm.event_hdlr(scrn_cntx->scrn_id, fsm_event, NULL);
        }
    }
    
    /* Delete the screen context */
    if (result == MMI_TRUE)
    {
        mmi_um_ui_cc_delete_scrn_cntx(scrn_cntx->scrn_id);
    }
    else
    {
        MMI_ASSERT(0);
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_leave_proc
 * DESCRIPTION
 *  Screen leave proc handler. In this function, it should handle the deinit
 *  event to release the screen context
 *
 * PARAMETERS
 *  evt             [IN]: Event from FW
 *  
 * RETURNS
 *  Result of handler
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_RET_OK;

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_um_ui_sh_destroy(evt->user_data);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_get_async_item
 * DESCRIPTION
 *  A general functio to get the async item data function. It is used by
 *  normal folder screen or mark several screen
 *
 * PARAMETERS
 *  start_index         [IN]: Start index
 *  menu_data           [IN]: Menu item data
 *  num_of_item         [IN]: Number of items
 *  
 * RETURNS
 *  The number of items
 *****************************************************************************/
S32 mmi_um_ui_sh_get_async_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_of_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 i;
    U16 copy_len;
    MYTIME time;
#ifdef __MMI_UM_CONVERSATION_BOX__
    applib_time_struct curr_time;
    U8 str_year[MMI_UM_UI_MAX_MSG_NUM_DIGIT + 1];
    srv_um_thread_info_struct **thread_detail_info;
    mmi_um_ui_folder_mode_enum folder_mode;
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    UI_character_type str[MMI_UM_UI_MAX_LEN_TIME_STR];
    UI_character_type msg_time[MMI_UM_UI_MAX_LEN_TIME_STR];
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    srv_um_msg_info_struct **msg_detail_info;
    srv_um_list_cntx_struct *data_list;
#ifdef __MMI_UM_REPORT_BOX__
    S8 *time_tmp_string = NULL;
#endif /* __MMI_UM_REPORT_BOX__ */
#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__2
    CHAR *message_contents[MMI_UM_CONTENT_CACHE_UNIT_AMOUNT];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#ifdef __MMI_BT_MAP_CLIENT__
    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(mmi_frm_scrn_get_active_id()); 
    if (scrn_cntx == NULL)
        scrn_cntx = g_sh_get_item_scrn_cntx;
#else
    scrn_cntx = mmi_um_ui_sh_get_active_user_data(); 
#endif /* __MMI_BT_MAP_CLIENT__ */

    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);


    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
#ifdef __MMI_BT_MAP_CLIENT__
    scrn_cntx->screen_hdlr.is_scrn_displayed = MMI_TRUE;
#endif

    /* No data in the finite state machine */
#ifdef __MMI_UM_CONVERSATION_BOX__
    result = fsm->get_msg_info(scrn_cntx->scrn_id, 
                               (U16) start_index, 
                               (U16) num_of_item, 
                               &msg_detail_info, 
                               &thread_detail_info);
#else
    result = fsm->get_msg_info(scrn_cntx->scrn_id, 
                               (U16) start_index, 
                               (U16) num_of_item, 
                               &msg_detail_info, 
                               NULL);
#endif /* __MMI_UM_CONVERSATION_BOX__ */

#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__2
    /* try to get message content if in thread */
    if (MMI_UM_FOLDER_MODE_THREAD_MSG == fsm->folder_mode)
    {
        /* message info got, try to get message content */
        if (result == MMI_TRUE)
        {
            result = fsm->get_msg_content(scrn_cntx->scrn_id, 
                                           (U16) start_index, 
                                           (U16) num_of_item, 
                                           message_contents);
        } 
    }
#endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */

    if (result == MMI_FALSE)
    {
        if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_TRUE)
        {
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
        #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
            return WGUI_GET_DATA_LOADING;
        #else /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
            return WGUI_GET_DATA_NONE;
        #endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
        }
        else
        {
            return WGUI_GET_DATA_NONE;
        }
    }
    //g_is_first_enter_tab = MMI_FALSE;

    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
    MMI_ASSERT(data_list != NULL);

    /* Has data, copy to the framework */
    for (i = 0; i < num_of_item; i++)
    {
#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__2
        srv_um_msg_node_struct *current_node = (srv_um_msg_node_struct *)(fsm->folder_info.data_list->list) + start_index + i;
        if ((MMI_UM_FOLDER_MODE_THREAD_MSG == fsm->folder_mode) &&
            (current_node->msg_type == SRV_UM_MSG_SMS))
        {
            mmi_ucs2ncpy(
                (S8*) menu_data[i].item_list[0],
                (S8*) message_contents[i],
                MAX_SUBMENU_CHARACTERS);
        }

        else
#endif
        do{
            /* MAX_SUBMENU_CHARACTERS is the max limitation of list buffer in category */

            /* subject */
        #ifndef __MMI_BT_MAP_CLIENT__
            copy_len = MAX_SUBMENU_CHARACTERS;
            
            if (msg_detail_info[i]->subject_length < MAX_SUBMENU_CHARACTERS)
            {
                copy_len = msg_detail_info[i]->subject_length;
            }

            if (copy_len == 0)
            {
                mmi_ucs2ncpy(
                    (CHAR*) menu_data[i].item_list[0],
                    (CHAR*) GetString(STR_UM_EMPTY_SUBJECT_ID),
                    SRV_UM_MAX_SUBJECT_LEN);
            }
            else
            {
                mmi_ucs2ncpy(
                    (CHAR*) menu_data[i].item_list[0],
                    (CHAR*) msg_detail_info[i]->subject,
                    copy_len);
            }
        #else
            if (msg_detail_info[i]->address_length == 0)
            {
                mmi_ucs2ncpy(
                    (S8*) menu_data[i].item_list[0],
                    (S8*) GetString(STR_GLOBAL_NO_NUMBER),
                    SRV_UM_MAX_SUBJECT_LEN);
            }
            else
            {
                copy_len = MAX_SUBMENU_CHARACTERS - 1;
                if (msg_detail_info[i]->address_length < MAX_SUBMENU_CHARACTERS)
                {
                    copy_len = msg_detail_info[i]->address_length;
                }

                /* Lookup name first if it is phone number */
                if (SRV_UM_ADDR_PHONE_NUMBER == msg_detail_info[i]->address_type)
                {
                    srv_phb_get_name_by_number((U16 *)msg_detail_info[i]->address, 
                                               (U16 *)menu_data[i].item_list[0], 
                                               MAX_SUBMENU_CHARACTERS - 1);
                    if (0 == mmi_ucs2strlen((S8*)menu_data[i].item_list[0]))
                    {
                        mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], 
                                 (S8*) msg_detail_info[i]->address, 
                                 copy_len);
                    }
                }
                else
                {
                    mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], 
                                 (S8*) msg_detail_info[i]->address, 
                                 copy_len);
                }
            }
        #endif /* __MMI_BT_MAP_CLIENT__ */
        }while (0);
    
        /*Timestamp*/
        memset((CHAR*)str, 0, sizeof(str));
        memset((CHAR*)msg_time, 0, sizeof(msg_time));

        copy_len = MAX_SUBMENU_CHARACTERS;
        if (MMI_UM_UI_MAX_LEN_TIME_STR < MAX_SUBMENU_CHARACTERS)
        {
            copy_len = MMI_UM_UI_MAX_LEN_TIME_STR;
        }


        if (msg_detail_info[i]->timestamp != 0)
        {
            U32 local_sec = 0;

            memset(&time, 0, sizeof(MYTIME));
            local_sec = applib_dt_sec_utc_to_local(msg_detail_info[i]->timestamp);
            mmi_dt_utc_sec_2_mytime(local_sec, &time, MMI_FALSE);
        #ifdef __MMI_UM_CONVERSATION_BOX__
            /* Check the time different with current target setting */
            memset(&curr_time, 0, sizeof(applib_time_struct));
            applib_dt_get_date_time(&curr_time);
            /* Check Year */
            if (curr_time.nYear != time.nYear)
            {
                /* Display year */
                memset(str_year, 0, sizeof(U8)*(MMI_UM_UI_MAX_MSG_NUM_DIGIT+1));
                sprintf((S8*)str_year, "%d", time.nYear);
                mmi_asc_n_to_ucs2((S8*) str, (S8*) str_year, MMI_UM_UI_MAX_MSG_NUM_DIGIT);
            }
            else if ((curr_time.nDay != time.nDay) ||
                     (curr_time.nMonth != time.nMonth))
            {
                /* Display Month/Day */
                date_string(&time, str, DT_IDLE_SCREEN_2);
            }
            else
            {
                /* Display Time */
                time_string(&time, str, DT_IDLE_SCREEN);
            }
            /* Copy the string */
            mmi_ucs2ncpy((S8*) msg_time, (S8*) str, (MMI_UM_UI_MAX_LEN_TIME_STR -1));
        #else
            /* Normal time display as IDLE */
            date_string(&time, str, DT_IDLE_SCREEN);
            mmi_ucs2ncpy((S8*) msg_time, (S8*) str, (MMI_UM_UI_MAX_LEN_TIME_STR - 1));
            mmi_ucs2ncat((S8*) msg_time, (S8*) " ", 1);

            time_string(&time, str, DT_IDLE_SCREEN);
            mmi_ucs2ncat((S8*) msg_time, (S8*) str, (MMI_UM_UI_MAX_LEN_TIME_STR - 1));
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
        }

        mmi_ucs2ncpy(
            (S8*) menu_data[i].item_list[1],
            (S8*) msg_time,
            copy_len);

    #ifdef __MMI_UM_REPORT_BOX__
        /* Concate the time / subject into 1 string in subject/time field in report box */
        if (SRV_UM_MSG_BOX_REPORT == scrn_cntx->screen_hdlr.folder_type.msg_box_type)
        {
            time_tmp_string = OslMalloc(MAX_SUB_MENU_SIZE);
            mmi_ucs2cpy(time_tmp_string, (S8 *)menu_data[i].item_list[1]);
            /* concate into time field */
            mmi_ucs2cat((S8 *) menu_data[i].item_list[1], (S8 *)L" ");
            copy_len = (MAX_SUBMENU_CHARACTERS - 1) - mmi_ucs2strlen((S8 *)menu_data[i].item_list[1]);
            mmi_ucs2ncat((S8 *) menu_data[i].item_list[1], (S8 *) menu_data[i].item_list[0], copy_len);
            /* copy back to subject field */
            copy_len = mmi_ucs2strlen((S8 *) menu_data[i].item_list[1]);
            mmi_ucs2ncpy((S8 *) menu_data[i].item_list[0], (S8 *) menu_data[i].item_list[1], copy_len);
            /* copy the original time string */
            mmi_ucs2cpy((S8 *)menu_data[i].item_list[1], time_tmp_string);
            /* Free the temp data */
            OslMfree(time_tmp_string);
            time_tmp_string = NULL;
        }
    #endif /* __MMI_UM_REPORT_BOX__ */

        /*address*/
        if (msg_detail_info[i]->address_length == 0)
        {
            mmi_ucs2ncpy(
                (S8*) menu_data[i].item_list[2],
                (S8*) GetString(STR_GLOBAL_NO_NUMBER),
                SRV_UM_MAX_SUBJECT_LEN);
        }
        else
        {
            copy_len = MAX_SUBMENU_CHARACTERS - 1;
            if (msg_detail_info[i]->address_length < MAX_SUBMENU_CHARACTERS)
            {
                copy_len = msg_detail_info[i]->address_length;
            }

            /* Lookup name first if it is phone number */
            if (SRV_UM_ADDR_PHONE_NUMBER == msg_detail_info[i]->address_type)
            {
                srv_phb_get_name_by_number((U16 *)msg_detail_info[i]->address, 
                                           (U16 *)menu_data[i].item_list[2], 
                                           MAX_SUBMENU_CHARACTERS - 1);
                if (0 == mmi_ucs2strlen((S8*)menu_data[i].item_list[2]))
                {
                    mmi_ucs2ncpy((S8*) menu_data[i].item_list[2], 
                             (S8*) msg_detail_info[i]->address, 
                             copy_len);
                }
            }
            else
            {
                mmi_ucs2ncpy((S8*) menu_data[i].item_list[2], 
                             (S8*) msg_detail_info[i]->address, 
                             copy_len);
            }
        }

        /* status icon */
    #ifdef __MMI_UM_CONVERSATION_BOX__
        folder_mode = mmi_um_ui_fsm_ef_get_folder_mode(&(scrn_cntx->fsm));
        if (MMI_UM_FOLDER_MODE_CONVERSATION_BOX == folder_mode)
        {
            if (thread_detail_info[i]->unread_msg_number > 0)
            {
                /* has unread */
                menu_data[i].image_list[0] = (PU8) GetImage(IMG_UM_UNREAD_THREAD_MSG);
            }
            else
            {
                /* all read */
                menu_data[i].image_list[0] = (PU8) GetImage(IMG_UM_READ_THREAD_MSG);
            }
        }
        else
    #endif
        {
            menu_data[i].image_list[0] = (PU8) GetImage(msg_detail_info[i]->icon_id);
        }

    #if (MMI_MAX_SIM_NUM >= 2)
        if (msg_detail_info[i]->sim_id == SRV_UM_SIM_GSM_SIM1)
        {
            menu_data[i].image_list[1] = (PU8) GetImage(IMG_GLOBAL_SIM1);  
        }
        else if (msg_detail_info[i]->sim_id == SRV_UM_SIM_GSM_SIM2)
        {
            menu_data[i].image_list[1] = (PU8) GetImage(IMG_GLOBAL_SIM2);  
        }
    #if (MMI_MAX_SIM_NUM >= 3) 
        else if (msg_detail_info[i]->sim_id == SRV_UM_SIM_GSM_SIM3)
        {
            menu_data[i].image_list[1] = (PU8) GetImage(IMG_GLOBAL_SIM3);  
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)    
        else if (msg_detail_info[i]->sim_id == SRV_UM_SIM_GSM_SIM4)
        {
            menu_data[i].image_list[1] = (PU8) GetImage(IMG_GLOBAL_SIM4);  
        }
    #endif
        else
        {
            menu_data[i].image_list[1] = NULL;
        }
    #endif        /*   (MMI_MAX_SIM_NUM >= 2)  */ 
    }
    
    return num_of_item;
}


#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_thread_enhance_get_async_item
 * DESCRIPTION
 *  A general functio to get the async item data function. It is used by
 *  normal folder screen or mark several screen
 *
 * PARAMETERS
 *  start_index         [IN]: Start index
 *  menu_data           [IN]: Menu item data
 *  num_of_item         [IN]: Number of items
 *  
 * RETURNS
 *  The number of items
 *****************************************************************************/
S32 mmi_um_ui_sh_thread_enhance_get_async_item(S32 start_index, cat_iconlist_menu_item *menu_data, S32 num_of_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    U16 i;
    U16 copy_len;
    MYTIME time;
    applib_time_struct curr_time;
    U8 str_year[MMI_UM_UI_MAX_MSG_NUM_DIGIT + 1];
    srv_um_thread_info_struct **thread_detail_info;
    UI_character_type str[MMI_UM_UI_MAX_LEN_TIME_STR];
    UI_character_type msg_time[MMI_UM_UI_MAX_LEN_TIME_STR];
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;
    mmi_um_ui_fsm_node_struct *fsm_cntx;
    mmi_um_ui_fsm_entry_folder_struct *fsm;
    srv_um_msg_info_struct **msg_detail_info;
    srv_um_list_cntx_struct *data_list;
    CHAR *message_contents[MMI_UM_CONTENT_CACHE_UNIT_AMOUNT];
	S32 item_number_with_data = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_GET_ITEM, start_index, num_of_item);
    fsm_cntx = &(scrn_cntx->fsm);
    fsm = &(fsm_cntx->cntx.fsm_entry_folder);
    if (fsm->folder_info.data_list == NULL ||
        (fsm->state == MMI_UM_UI_FSM_EF_UPDATE_DATA && fsm->action == MMI_UM_UI_ACTION_GET_MSG_LIST))
    {
        result =  MMI_FALSE;
    }

    if (result == MMI_TRUE)
	{
		/* list gotten, fill direction */
	    for (i = 0; i < num_of_item; i++)
	    {
	        srv_um_msg_node_struct *current_node = (srv_um_msg_node_struct *)(fsm->folder_info.data_list->list) + start_index + i;
			if (mmi_um_ui_adp_get_msg_box(current_node->msg_type, current_node->msg_id) == SRV_UM_MSG_BOX_INBOX)
			{
				menu_data[i].lr_flag = 0;
			}
			else
			{
				menu_data[i].lr_flag = 1;
			}
		}
    }
	
    if (result == MMI_FALSE)
    {
        if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_TRUE)
        {
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
	#ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
            return WGUI_GET_DATA_LOADING;
	#else /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
            return WGUI_GET_DATA_NONE;
	#endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
        }
        else
        {
            return WGUI_GET_DATA_NONE;
        }
    }
    if (result == MMI_TRUE)
	{
		/* list gotten, tre messsage info */
	    result = fsm->get_msg_info(scrn_cntx->scrn_id, 
	                               (U16) start_index, 
	                               (U16) num_of_item, 
	                               &msg_detail_info, 
	                               &thread_detail_info);
	}

    if (result == MMI_FALSE)
    {
        if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_TRUE)
        {
            mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
        #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
            return WGUI_GET_DATA_LOADING;
        #else /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
            return WGUI_GET_DATA_NONE;
        #endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
        }
        else
        {
            return WGUI_GET_DATA_NONE;
        }
    }
	
    if (result == MMI_TRUE)
    {
		/* message info got, try to get message content */
		memset((CHAR*)message_contents, 0, (sizeof(CHAR*) * MMI_UM_CONTENT_CACHE_UNIT_AMOUNT));
        result = fsm->get_msg_content(scrn_cntx->scrn_id, 
                                       (U16) start_index, 
                                       (U16) num_of_item, 
                                       message_contents);
	    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_GET_ITEM_RESULT, 1, result);

	    data_list = mmi_um_ui_fsm_get_data_list_ptr(&(scrn_cntx->fsm));
	    MMI_ASSERT(data_list != NULL);

	    /* Has data, copy to the framework */
	    for (i = 0; i < num_of_item; i++)
	    {
	        srv_um_msg_node_struct *current_node = (srv_um_msg_node_struct *)(fsm->folder_info.data_list->list) + start_index + i;
	        if (current_node->msg_type == SRV_UM_MSG_SMS)
	        {
	                menu_data[i].string_ptr = (CHAR*) message_contents[i];
	        }
	        else
	        {
	            /* MAX_SUBMENU_CHARACTERS is the max limitation of list buffer in category */
	            /* subject */
	            copy_len = MAX_SUBMENU_CHARACTERS;
	            
	            if (msg_detail_info[i]->subject_length < MAX_SUBMENU_CHARACTERS)
	            {
	                copy_len = msg_detail_info[i]->subject_length;
	            }

	            if (copy_len == 0)
	            {
	                 menu_data[i].string_ptr = (CHAR*)GetString(STR_UM_EMPTY_SUBJECT_ID);
	            }
	            else
	            {
	                 menu_data[i].string_ptr = (CHAR*)msg_detail_info[i]->subject;
	            }
	        }
			
	        if(NULL != menu_data[i].string_ptr)
	     	{
		     	item_number_with_data++;
	     	}
	        /*Timestamp*/
	        memset((CHAR *)str, 0, sizeof(str));
	        memset((CHAR *)msg_time, 0, sizeof(msg_time));

	        copy_len = MAX_SUBMENU_CHARACTERS;
	        if (MMI_UM_UI_MAX_LEN_TIME_STR < MAX_SUBMENU_CHARACTERS)
	        {
	            copy_len = MMI_UM_UI_MAX_LEN_TIME_STR;
	        }


	        if (msg_detail_info[i]->timestamp != 0)
	        {
	            U32 local_sec = 0;

	            memset(&time, 0, sizeof(MYTIME));
	            local_sec = applib_dt_sec_utc_to_local(msg_detail_info[i]->timestamp);
	            mmi_dt_utc_sec_2_mytime(local_sec, &time, MMI_FALSE);
	            /* Check the time different with current target setting */
	            memset(&curr_time, 0, sizeof(applib_time_struct));
	            applib_dt_get_date_time(&curr_time);
	            /* Check Year */
	            if (curr_time.nYear != time.nYear)
	            {
	                /* Display year */
	                memset(str_year, 0, sizeof(U8)*(MMI_UM_UI_MAX_MSG_NUM_DIGIT+1));
	                sprintf((S8*)str_year, "%d", time.nYear);
	                mmi_asc_n_to_ucs2((S8*) str, (S8*) str_year, MMI_UM_UI_MAX_MSG_NUM_DIGIT);
	            }
	            else if ((curr_time.nDay != time.nDay) ||
	                     (curr_time.nMonth != time.nMonth))
	            {
	                /* Display Month/Day */
	                date_string(&time, str, DT_IDLE_SCREEN_2);
	            }
	            else
	            {
	                /* Display Time */
	                time_string(&time, str, DT_IDLE_SCREEN);
	            }
	            /* Copy the string */
	            mmi_ucs2ncpy((S8*) msg_time, (S8*) str, (MMI_UM_UI_MAX_LEN_TIME_STR -1));
	        }

	        mmi_ucs2ncpy(
	            (S8*) menu_data[i].item_list[0],
	            (S8*) msg_time,
	            copy_len);
	        mmi_wcscpy((WCHAR*)menu_data[i].item_list[1], L"");

	        /* status icon */
	        menu_data[i].image_list[0] = (PU8) GetImage(msg_detail_info[i]->icon_id);
	    }
    } 
	if (result == MMI_FALSE)
	{
		if (scrn_cntx->screen_hdlr.is_scrn_displayed == MMI_TRUE)
		{
			mmi_um_ui_cc_send_event(scrn_cntx->scrn_id, MMI_UM_UI_EVENT_CHECK, NULL);
			if (item_number_with_data == 0)
			{
            #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
                return WGUI_GET_DATA_LOADING;
            #else /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
                return WGUI_GET_DATA_NONE;
			#endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
			}
		}
		else
		{
		    return WGUI_GET_DATA_NONE;
		}
	}
    return item_number_with_data;
}
#endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__2 */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_evt_hdlr_delete
 * DESCRIPTION
 *  "Delete" event handler. General delete event handler for each screen. It 
 *  is used to reduce the rom/ram size in the target.
 *
 * PARAMETERS
 *  scrn_cntx           [IN]: screen context
 *  arg                 [IN]: the event argument
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_evt_hdlr_delete(mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(scrn_cntx->group_id, scrn_cntx->screen_hdlr.disp_scrn_id);
    }
    else
    {
        mmi_um_ui_sh_destroy(scrn_cntx);
    }
    /* Destroy function will delete the finite state machine and screen context */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_get_active_user_data
 * DESCRIPTION
 *  Get the active user data from several FW apis.
 *
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  Active screen user data
 *****************************************************************************/
mmi_um_ui_cc_scrn_cntx_struct *mmi_um_ui_sh_get_active_user_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;
    MMI_ID scrn_id;
    mmi_um_ui_cc_scrn_cntx_struct *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = mmi_frm_group_get_active_id();
    scrn_id = mmi_frm_scrn_get_active_id();

    user_data = (mmi_um_ui_cc_scrn_cntx_struct *)mmi_frm_scrn_get_user_data(grp_id, scrn_id);

    return user_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_confirm_cb
 * DESCRIPTION
 *  General confirm proc callback handler.
 *
 * PARAMETERS
 *  evt             [IN]: event sent from confirm
 *  
 * RETURNS
 *  handling result : MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_um_ui_sh_confirm_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    mmi_um_confirm_hdlr_ptr cf_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = MMI_RET_OK;
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert_evt = (mmi_alert_result_evt_struct *)evt;
            mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

            scrn_cntx = (mmi_um_ui_cc_scrn_cntx_struct *)alert_evt->user_tag;
            switch (alert_evt->result)
            {
                case MMI_ALERT_CNFM_YES:
                case MMI_ALERT_CNFM_OK:
                {
                    cf_ptr = mmi_um_ui_sh_get_confirm_hdlr(scrn_cntx->screen_hdlr.cf_action);
                    ret = cf_ptr(scrn_cntx);
                    break;
                }
                case MMI_ALERT_NORMAL_EXIT:
                case MMI_ALERT_INTERRUPT_EXIT:
                {
                    scrn_cntx->screen_hdlr.cf_action = MMI_UM_UI_SH_CF_NONE;
                    scrn_cntx->screen_hdlr.cf_grp_id = GRP_ID_INVALID;
                    break;
                }
            }
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_get_confirm_hdlr
 * DESCRIPTION
 *  Get the confirm function handler by action.
 *
 * PARAMETERS
 *  cf_action           [IN]: confirm action
 *  
 * RETURNS
 *  handler function pointer
 *****************************************************************************/
mmi_um_confirm_hdlr_ptr mmi_um_ui_sh_get_confirm_hdlr(mmi_um_ui_sh_confirm_action_enum cf_action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_confirm_hdlr_ptr cf_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cf_action)
    {
    #ifdef __MMI_UM_DIAL_FROM_FOLDER__
        case MMI_UM_UI_SH_CF_FOLDER_SEND_KEY:
        {
            cf_ptr = mmi_um_ui_sh_general_folder_send_key_confirm_yes_hdlr;
            break;
        }
    #endif /* __MMI_UM_DIAL_FROM_FOLDER__  */
        case MMI_UM_UI_SH_CF_FOLDER_OPT_DEL_ALL:
        {
            cf_ptr = mmi_um_ui_sh_general_folder_opt_del_all_cf_yes;
            break;
        }
    #ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
        case MMI_UM_UI_SH_CF_DELETE_FOLDER:
        {
            cf_ptr = mmi_um_ui_sh_delete_folder_process;
            break;
        }
    #endif
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MMI_UM_UI_SH_CF_MS_DELETE:
        {
            cf_ptr = mmi_um_ui_sh_ms_option_process_delete;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMI_UM_UI_SH_CF_MS_MOV2ARC:
        {
            cf_ptr = mmi_um_ui_sh_ms_option_process_mov2arc;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifndef __UM_FOLDER__
        case MMI_UM_UI_SH_CF_MS_MOV2SIM:
        {
            cf_ptr = mmi_um_ui_sh_ms_option_process_mov2sim;
            break;
        }
        case MMI_UM_UI_SH_CF_MS_MOV2PHONE:
        {
            cf_ptr = mmi_um_ui_sh_ms_option_process_mov2phone;
            break;
        }
        case MMI_UM_UI_SH_CF_MS_CPY2SIM:
        {
            cf_ptr = mmi_um_ui_sh_ms_option_process_cpy2sim;
            break;
        }
        case MMI_UM_UI_SH_CF_MS_CPY2PHONE:
        {
            cf_ptr = mmi_um_ui_sh_ms_option_process_cpy2phone;
            break;
        }
    #endif /* __UM_FOLDER__ */
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
    #ifdef __MMI_UM_CONVERSATION_BOX__
    #ifdef __MMI_UM_DIAL_FROM_FOLDER__
        case MMI_UM_UI_SH_CF_CS_SEND_KEY:
        {
            cf_ptr = mmi_um_ui_sh_cs_send_key_confirm_yes_hdlr;
            break;
        }
    #endif /* __MMI_UM_DIAL_FROM_FOLDER__ */
    #ifdef __MMI_ICON_BAR_SUPPORT__
        case MMI_UM_UI_SH_CF_CS_TB_DELETE:
    #endif /* __MMI_ICON_BAR_SUPPORT__ */
        case MMI_UM_UI_SH_CF_CS_OPT_DELETE:
        {
            cf_ptr = mmi_um_ui_sh_cs_opt_del_item_hdlr;
            break;
        }
        case MMI_UM_UI_SH_CF_CS_OPT_DEL_ALL:
        {
            cf_ptr = mmi_um_ui_sh_cs_opt_del_all_item_hdlr;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMI_UM_UI_SH_CF_CS_OPT_MOV2ARC:
        {
            cf_ptr = mmi_um_ui_sh_cs_opt_mov2arc_item_hdlr;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MMI_UM_UI_SH_CF_MS_CS_OPT_DELETE:
        {
            cf_ptr = mmi_um_ui_sh_ms_cs_opt_delete;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMI_UM_UI_SH_CF_MS_CS_OPT_MOV2ARC:
        {
            cf_ptr = mmi_um_ui_sh_ms_cs_opt_mov2arc;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return cf_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_set_confirm_param
 * DESCRIPTION
 *  Set the confirm structure parameter with screen context.
 *
 * PARAMETERS
 *  cf_param            [IN]: confirm parameter
 *  scrn_cntx           [IN]: Screen context
 *  type                [IN]: confirm action type
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sh_set_confirm_param(
                mmi_confirm_property_struct *cf_param, 
                mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx, 
                mmi_um_ui_sh_confirm_action_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cf_param->parent_id = scrn_cntx->group_id;
    cf_param->user_tag = (void *)scrn_cntx;
    cf_param->callback = mmi_um_ui_sh_confirm_cb;
    /* for delete op, auto_map shoudl disable */
    cf_param->f_auto_map_empty_softkey = 1;
    scrn_cntx->screen_hdlr.cf_action = type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sh_auto_map_csk
 * DESCRIPTION
 *  Check if the auto map csk could work or not.
 *
 * PARAMETERS
 *  cf_action           [IN]: confirm action type
 *  
 * RETURNS
 *  Return the auto map csk value.
 *  1 : Could map
 *  0 : Could not map. (Like delete)
 *****************************************************************************/
U32 mmi_um_ui_sh_auto_map_csk(mmi_um_ui_sh_confirm_action_enum cf_action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 auto_map = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
/* under construction !*/
#endif
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/* under construction !*/
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
    #ifdef __MMI_UM_CONVERSATION_BOX__
    #ifdef __MMI_ICON_BAR_SUPPORT__
/* under construction !*/
    #endif /* __MMI_ICON_BAR_SUPPORT__ */
/* under construction !*/
/* under construction !*/
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/* under construction !*/
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
    #endif /* __MMI_UM_CONVERSATION_BOX__ */
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
    return auto_map;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_write_msg
 * DESCRIPTION
 *  Funtion is called when write message menu item selected
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UM_FOLDER__
    #ifdef __MMI_UNIFIED_COMPOSER__
        #ifdef __MMI_MMS_POSTCARD__
        mmi_um_main_menu_general_highlight(mmi_uc_entry_write_msg_selection);
        #else
        mmi_um_main_menu_general_highlight(mmi_uc_pre_entry_write_msg);
        #endif/*__MMI_MMS_POSTCARD__*/
    #else /* __MMI_UNIFIED_COMPOSER__ */
        mmi_um_main_menu_general_highlight(mmi_um_entry_write_msg);
    #endif /* __MMI_UNIFIED_COMPOSER__ */
#else /* !__UM_FOLDER__ */
    mmi_um_main_menu_general_highlight(mmi_msg_pre_entry_write_new_msg);
#endif /* __UM_FOLDER__ */
}


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_conversation
 * DESCRIPTION
 *  Funtion is called when conversation box menu item selected
 * NA
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_conversation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_main_menu_general_highlight(mmi_um_entry_conversation);
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_inbox
 * DESCRIPTION
 *  Funtion is called when inbox menu item selected
 * NA
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_main_menu_general_highlight(mmi_um_entry_inbox);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_draft
 * DESCRIPTION
 *  Funtion is called when draft menu item selected
 * NA
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_main_menu_general_highlight(mmi_um_entry_draft);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_unsent
 * DESCRIPTION
 *  Funtion is called when unsent menu item selected
 * NA
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_unsent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_main_menu_general_highlight(mmi_um_entry_outbox);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_sent
 * DESCRIPTION
 *  Funtion is called when sent menu item selected
 * NA
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_main_menu_general_highlight(mmi_um_entry_sent);
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_archive
 * DESCRIPTION
 *  Funtion is called when archive menu item selected
 * NA
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_archive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_main_menu_general_highlight(mmi_um_entry_archive);
    return;
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_simbox
 * DESCRIPTION
 *  Funtion is called when SIM Message menu item selected
 * NA
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_main_menu_general_highlight(mmi_um_entry_simbox);
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_delete_folder
 * DESCRIPTION
 *  Funtion is called when delete folder menu item selected
 * NA
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_delete_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_main_menu_general_highlight(mmi_um_entry_delete_folder);
}
#endif

#ifdef __MMI_UM_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_template
 * DESCRIPTION
 *  Funtion is called when template menu item selected
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_main_menu_general_highlight(mmi_um_entry_template);
}


#ifdef __MMI_MESSAGES_TEMPLATE__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_template_sms
 * DESCRIPTION
 *  Funtion is called when highlight SMS template menu item selected
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_template_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_main_menu_general_highlight(mmi_sms_um_entry_template);
}
#endif /* __MMI_MESSAGES_TEMPLATE__ */


#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_template_mms
 * DESCRIPTION
 *  Funtion is called when highlight MMS template menu item selected
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_template_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_IN_UM__
    mmi_um_main_menu_general_highlight(mms_um_entry_template);
#endif /* __MMI_MMS_IN_UM__ */
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */
#endif /* __MMI_UM_TEMPLATE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_setting
 * DESCRIPTION
 *  Funtion is called when setting menu item selected
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_main_menu_general_highlight(mmi_um_entry_setting);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_hide_main_message_all_folder_menu_id
 * DESCRIPTION
 *      hide all folder menu id.
 *      MENU_ID_UM_WRITE_MSG, MENU_ID_UM_INBOX, MENU_ID_UM_UNSENT,
 *      MENU_ID_UM_SENT, MENU_ID_UM_DRAFT, MENU_ID_UM_ARCHIVE,
 *      MENU_ID_UM_SIM, MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_TEMPLATE,
 *      MENU_ID_UM_SETTING
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_hide_main_message_all_folder_menu_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_hide_menu_item(MENU_ID_UM_WRITE_MSG);
    mmi_frm_hide_menu_item(MENU_ID_UM_INBOX);
    mmi_frm_hide_menu_item(MENU_ID_UM_DRAFT);
    mmi_frm_hide_menu_item(MENU_ID_UM_UNSENT);
    mmi_frm_hide_menu_item(MENU_ID_UM_SENT);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UM_ARCHIVE);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UM_SIM);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __MMI_UM_TEMPLATE_SUPPORT__
    mmi_frm_hide_menu_item(MENU_ID_UM_TEMPLATE);
#endif /* __MMI_UM_TEMPLATE_SUPPORT__ */
    mmi_frm_hide_menu_item(MENU_ID_UM_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_unhide_main_message_all_folder_menu_id
 * DESCRIPTION
 *      unhide all folder menu id.
 *      MENU_ID_UM_WRITE_MSG, MENU_ID_UM_INBOX, MENU_ID_UM_UNSENT,
 *      MENU_ID_UM_SENT, MENU_ID_UM_DRAFT, MENU_ID_UM_ARCHIVE,
 *      MENU_ID_UM_SIM, MENU_ID_UM_DELETE_FOLDER, MENU_ID_UM_TEMPLATE,
 *      MENU_ID_UM_SETTING
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_unhide_main_message_all_folder_menu_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MENU_ID_UM_WRITE_MSG);
    mmi_frm_unhide_menu_item(MENU_ID_UM_INBOX);
    mmi_frm_unhide_menu_item(MENU_ID_UM_DRAFT);
    mmi_frm_unhide_menu_item(MENU_ID_UM_UNSENT);
    mmi_frm_unhide_menu_item(MENU_ID_UM_SENT);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UM_ARCHIVE);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UM_SIM);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __MMI_UM_TEMPLATE_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_UM_TEMPLATE);
#endif /* __MMI_UM_TEMPLATE_SUPPORT__ */
    mmi_frm_unhide_menu_item(MENU_ID_UM_SETTING);
}


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_mark_several_option
 * DESCRIPTION
 *  When highlight to the mark several option menu,
 *  change the LSK, RSK function
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_mark_several_option(void)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_mark_several_op_delete
 * DESCRIPTION
 *  When highlight to delete action,
 *  change the LSK, RSK function
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_mark_several_op_delete(void)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_mark_several_op_move_to_archive
 * DESCRIPTION
 *  When highlight to move to archive action,
 *  change the LSK, RSK function
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_mark_several_op_move_to_archive(void)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_mark_several_op_mark_all
 * DESCRIPTION
 *  When highlight to move to mark all action,
 *  change the LSK, RSK function
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_mark_several_op_mark_all(void)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_mark_several_op_unmark_all
 * DESCRIPTION
 *  When highlight to move to unmark all action,
 *  change the LSK, RSK function
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_mark_several_op_unmark_all(void)
{
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* __UM_SUPPORT__ */
