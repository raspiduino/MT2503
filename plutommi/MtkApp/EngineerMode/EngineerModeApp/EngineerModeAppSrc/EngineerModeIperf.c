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
 *  EngineerModeIperf.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode soket - IPERF. 
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_EM_IPERF__
#include "mmi_rp_app_engineermode1_def.h"
#include "menucuigprot.h"
#include "InlineCuiGprot.h"
#include "soc_api.h"
#include "iperf_mmi_enums.h"
#include "iperf2mmi_struct.h"
#include "DataAccountGprot.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "DataAccountCUIGprot.h"
#else
#include "vcui_dtcnt_select_gprot.h"
#endif
#include "EngineerModeDef.h"
#include "EngineerModeIperf.h"
#include "GlobalResDef.h"
#include "ImeGprot.h"
#include "MMIDataType.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "cbm_api.h"
#include "MMI_common_app_trc.h"
#include "mmi_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "custom_data_account.h"
#include "gui.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_list.h"
#include "wgui_categories_text_viewer.h"
#include "mmi_frm_history_gprot.h"
#include "DtcntSrvGprot.h"
#include "wgui_inline_edit.h"
#include "stack_msgs.h"
#include "NotificationGprot.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "cbm_consts.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_common.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "mmi_common_app_trc.h"
#include "TetheringSrvGprot.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeUtil.h"
#include "EngineerModeCommUI.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

static unsigned int iperf_cur_job_id;
em_iperf_context_struct iperf_context;
em_iperf_context_struct *iperf_p = &iperf_context;
MMI_ID g_em_iperf_cui_menu_id;

static const MMI_STR_ID clisrv_sel_str[] = {STR_ID_EM_IPERF_CLIENT, STR_ID_EM_IPERF_SERVER};
static const MMI_STR_ID dual_test_sel_str[] = {STR_ID_EM_IPERF_DUAL_TEST_OFF, STR_ID_EM_IPERF_DUAL_TEST_ON};
//static const MMI_STR_ID tos_sel_str[] = {STR_ID_EM_IPERF_BEST_EFFORT, STR_ID_EM_IPERF_BACK_GROUND, STR_ID_EM_IPERF_VIDEO, STR_ID_EM_IPERF_VOICE};
//static const MMI_STR_ID rw_file_sel_str[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
extern void cui_inline_set_all_items_softkey_text(mmi_id gid, WGUI_SOFTKEY_ENUM key, U16 string_id);
//static const    cui_inline_item_caption_struct      inline_data_account_cap = {STR_GLOBAL_DATA_ACCOUNT};
//static const    cui_inline_item_display_only_struct inline_data_account;
//static const cui_inline_item_caption_struct      inline_clisrv_cap = {STR_ID_EM_IPERF_CLIENT_SERVER};
static const cui_inline_item_select_struct       inline_clisrv = {sizeof(clisrv_sel_str)/sizeof(clisrv_sel_str[0]), 0, clisrv_sel_str};
static const cui_inline_item_caption_struct      inline_faddr_cap = {STR_ID_EM_IPERF_FADDR};
static const cui_inline_item_ip4_struct          inline_faddr;
static const cui_inline_item_caption_struct      inline_len_cap = {STR_ID_EM_IPERF_LEN};
static const cui_inline_item_text_edit_struct    inline_len = {0, 0, IPERF_LEN, IMM_INPUT_TYPE_NUMERIC, 0, NULL};
static const cui_inline_item_caption_struct      inline_port_cap = {STR_ID_EM_IPERF_PORT};
static const cui_inline_item_text_edit_struct    inline_port = {0, 0, IPERF_PORT, IMM_INPUT_TYPE_NUMERIC, 0, NULL};
static const cui_inline_item_caption_struct      inline_window_or_buffer_cap;
static const cui_inline_item_text_edit_struct    inline_window_or_buffer = {0, 0, IPERF_WINDOW > IPERF_BUFFER ? IPERF_WINDOW : IPERF_BUFFER, IMM_INPUT_TYPE_NUMERIC, 0, NULL};
static const cui_inline_item_caption_struct      inline_mss_or_bandwidth_cap;
static const cui_inline_item_text_edit_struct    inline_mss_or_bandwidth = {0, 0, IPERF_MSS > IPERF_BANDWIDTH ? IPERF_MSS : IPERF_BANDWIDTH, IMM_INPUT_TYPE_NUMERIC, 0, NULL};
//static const cui_inline_item_caption_struct      inline_dual_test_cap = {STR_ID_EM_IPERF_DUAL};
static const cui_inline_item_caption_struct      inline_num_cap = {STR_ID_EM_IPERF_NUM_BYTES};
static const cui_inline_item_text_edit_struct    inline_num = {0, 0, IPERF_NUM, IMM_INPUT_TYPE_NUMERIC, 0, NULL};
static const cui_inline_item_caption_struct      inline_time_cap = {STR_ID_EM_IPERF_TIME_SECS};
static const cui_inline_item_text_edit_struct    inline_time = {0, 0, IPERF_TIME, IMM_INPUT_TYPE_NUMERIC, 0, NULL};
static const cui_inline_item_select_struct       inline_dual_test = {sizeof(dual_test_sel_str)/sizeof(dual_test_sel_str[0]), 0, dual_test_sel_str};
//static const cui_inline_item_caption_struct      inline_tos_cap = {STR_ID_EM_IPERF_TOS};
//static const cui_inline_item_select_struct       inline_tos = {sizeof(tos_sel_str)/sizeof(tos_sel_str[0]), 0, tos_sel_str};
//static const cui_inline_item_caption_struct      inline_rw_file_cap = {STR_ID_EM_IPERF_RW_FILE};
//static const cui_inline_item_select_struct       inline_rw_file = {sizeof(rw_file_sel_str)/sizeof(rw_file_sel_str[0]), 0, rw_file_sel_str};

static const cui_inline_set_item_struct g_em_iperf_setting_inline_items[] =
{
    //{EF_IPERF_INLINE_ITEM_DATA_ACCOUNT_CAP,     CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L1,  (void*)&inline_data_account_cap},
    //{EF_IPERF_INLINE_ITEM_DATA_ACCOUNT,         CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_DISPLAY_NO_RESPONSE_NUMKEY, 0,  (void*)&inline_data_account},
    //{EF_IPERF_INLINE_ITEM_CLISRV_CAP,           CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L1,  (void*)&inline_clisrv_cap},
    {EF_IPERF_INLINE_ITEM_CLISRV,               CUI_INLINE_ITEM_TYPE_SELECT,                                        0,              (void*)&inline_clisrv},
    {EF_IPERF_INLINE_ITEM_FADDR_CAP,            CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L2,  (void*)&inline_faddr_cap},
    {EF_IPERF_INLINE_ITEM_FADDR,                CUI_INLINE_ITEM_TYPE_IP4,                                           0,              (void*)&inline_faddr},
    {EF_IPERF_INLINE_ITEM_LEN_CAP,              CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L3,  (void*)&inline_len_cap},
    {EF_IPERF_INLINE_ITEM_LEN,                  CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_NO_LEADING_ZERO,   0,              (void*)&inline_len},
    {EF_IPERF_INLINE_ITEM_PORT_CAP,             CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L4,  (void*)&inline_port_cap},
    {EF_IPERF_INLINE_ITEM_PORT,                 CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_NO_LEADING_ZERO,   0,              (void*)&inline_port},
    {EF_IPERF_INLINE_ITEM_WINDOW_OR_BUFFER_CAP, CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L5,  (void*)&inline_window_or_buffer_cap},
    {EF_IPERF_INLINE_ITEM_WINDOW_OR_BUFFER,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_NO_LEADING_ZERO,   0,              (void*)&inline_window_or_buffer},
    {EF_IPERF_INLINE_ITEM_MSS_OR_BANDWIDTH_CAP, CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L6,  (void*)&inline_mss_or_bandwidth_cap},
    {EF_IPERF_INLINE_ITEM_MSS_OR_BANDWIDTH,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_NO_LEADING_ZERO,   0,              (void*)&inline_mss_or_bandwidth},
    //{EF_IPERF_INLINE_ITEM_DUAL_TEST_CAP,        CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L7,  (void*)&inline_dual_test_cap},
    {EF_IPERF_INLINE_ITEM_NUM_CAP,              CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L8,  (void*)&inline_num_cap},
    {EF_IPERF_INLINE_ITEM_NUM,                  CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_NO_LEADING_ZERO,   0,              (void*)&inline_num},
    {EF_IPERF_INLINE_ITEM_TIME_CAP,             CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L9, (void*)&inline_time_cap},
    {EF_IPERF_INLINE_ITEM_TIME,                 CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_NO_LEADING_ZERO,   0,              (void*)&inline_time},
    {EF_IPERF_INLINE_ITEM_DUAL_TEST,            CUI_INLINE_ITEM_TYPE_SELECT,                                        0,              (void*)&inline_dual_test},
    //{EF_IPERF_INLINE_ITEM_TOS_CAP,              CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L10, (void*)&inline_tos_cap},
    //{EF_IPERF_INLINE_ITEM_TOS,                  CUI_INLINE_ITEM_TYPE_SELECT,                                        0,              (void*)&inline_tos},
    //{EF_IPERF_INLINE_ITEM_RW_FILE_CAP,          CUI_INLINE_ITEM_TYPE_CAPTION,                                       IMG_GLOBAL_L11, (void*)&inline_rw_file_cap},
    //{EF_IPERF_INLINE_ITEM_RW_FILE,              CUI_INLINE_ITEM_TYPE_SELECT,                                        0,              (void*)&inline_rw_file}
};

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
MMI_ID g_ef_iperf_setting_inline_id;
MMI_ID g_ef_iperf_grp_id_report;
U8 g_em_iperf_cbm_id;
extern void iperf_stop(int task_id, kal_uint8 job_id);

/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
void mmi_em_iperf_menu_sel_event_hdlr(cui_menu_event_struct *event)
{
    switch (event->highlighted_menu_id)
    {
        case MENU_ID_EM_IPERF:
        {
            PreEntryEmIperf();
            break;
        }

        default:
            break;
    }
}


void mmi_em_iperf_menu_list_exit_event_hdlr(cui_menu_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->parent_menu_id)
    {
        case MENU_ID_EM_IPERF:
        {
            if(iperf_p->iperf_misc != NULL)
            {
                MMI_EM_FREE(iperf_p->iperf_misc);
                iperf_p->iperf_misc = NULL;
            }
            
            if(iperf_p->iperf_edit_tcp != NULL)
            {
                MMI_EM_FREE(iperf_p->iperf_edit_tcp);
                iperf_p->iperf_edit_tcp= NULL;
            }
            
            if(iperf_p->iperf_edit_udp != NULL)
            {
                MMI_EM_FREE(iperf_p->iperf_edit_udp);
                iperf_p->iperf_edit_udp= NULL;
            }
            
            if(iperf_p->iperf_report != NULL)
            {
                MMI_EM_FREE(iperf_p->iperf_report);
                iperf_p->iperf_report = NULL;
            }

            break;
        }

        default:
            break;
    }
}


mmi_ret ef_iperf_setting_scr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    cui_event_inline_abort_struct *inline_abort = (cui_event_inline_abort_struct*)evt;
    cui_dtcnt_select_event_any_sim_selected_struct *dtcnt_select = (cui_dtcnt_select_event_any_sim_selected_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_EM_IPERF_TCP:
                {
                    PreEntryEmIperfTcp();
                    break;
                }

                case MENU_ID_EM_IPERF_UDP:
                {
                    PreEntryEmIperfUdp();
                    break;
                }

                case MENU_ID_EM_IPERF_DTCNT:
                {
                    if (srv_tethering_is_on(SRV_TETHERING_TYPE_WIFI_HS) == MMI_TRUE)
                    {
                        mmi_popup_display_simple(
                            (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
                            MMI_EVENT_FAILURE,
                            GRP_ID_IPERF,
                            NULL);
                    }
                    else
                    {
                        em_iperf_setting_data_acct();
                    }
                    break;
                }

                case MENU_ID_EM_IPERF_OPTIONS_RESET_SETTINGS:
                {
                    em_iperf_load_default();
                    mmi_popup_display_simple(
                        (WCHAR*)GetString(STR_GLOBAL_DONE),
                        MMI_EVENT_SUCCESS,
                        GRP_ID_IPERF,
                        NULL);
                    break;
                }

                default:
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }

        default:
            break;
    }

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            em_iperf_run();
            break;
    
        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(inline_abort->sender_id);
            break;
            
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
        {
            em_iperf_dt_callback(
                (U8)dtcnt_select->selectSim,
                dtcnt_select->accountId);
            break;
        }

        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
        #ifdef __PLUTO_MMI_PACKAGE__
            cui_dtcnt_select_close(dtcnt_select->sender_id);
        #else
            vcui_dtcnt_select_close(dtcnt_select->sender_id);
        #endif
            break;

        case EVT_ID_GROUP_EXIT:
        {
            if(iperf_p->iperf_misc != NULL)
            {
                MMI_EM_FREE(iperf_p->iperf_misc);
                iperf_p->iperf_misc = NULL;
            }
            
            if(iperf_p->iperf_edit_tcp!= NULL)
            {
                MMI_EM_FREE(iperf_p->iperf_edit_tcp);
                iperf_p->iperf_edit_tcp= NULL;
            }
            
            if(iperf_p->iperf_edit_udp!= NULL)
            {
                MMI_EM_FREE(iperf_p->iperf_edit_udp);
                iperf_p->iperf_edit_udp= NULL;
            }
            
            if(iperf_p->iperf_report!= NULL)
            {
                MMI_EM_FREE(iperf_p->iperf_report);
                iperf_p->iperf_report= NULL;
            }
        }

        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*   em_iperf_disp_not_support_simulator_popup
* DESCRIPTION
*   Common function to display "Not Support at PC Simulator" popup
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void em_iperf_disp_not_support_simulator_popup(void)
{
    mmi_popup_display_simple(
        (WCHAR*)GetString(STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR),
        MMI_EVENT_FAILURE,
        GRP_ID_IPERF,
        NULL);
}


#define Iperf_Pre_Entry
/**************************************************************
*   FUNCTION NAME       : PreEntryEmIperf
*
*   PURPOSE             :Pre Entry function for EM Iperf (Iperf->Iperf Setting)
*
*   INPUT PARAMETERS    : nil
*
*   OUTPUT PARAMETERS   : void
*
*   RETURNS             : void
*
*   REMARKS             : 
**************************************************************/
void PreEntryEmIperf(void)
{
    cbm_app_info_struct cbm_app_info;

    MMI_TRACE(MMI_COMMON_TRC_G8_EM, MMI_EM_IPERF_PRE_ENTRY_IPERF);

    /* memory allocation for Iperf*/
    
    if(iperf_p->iperf_misc== NULL)
    {
      iperf_p->iperf_misc = (em_iperf_misc_struct*)MMI_EM_MALLOC(sizeof(em_iperf_misc_struct));
      memset(iperf_p->iperf_misc, 0, sizeof(em_iperf_misc_struct));
    }

    if(iperf_p->iperf_edit_tcp== NULL)
    {
      iperf_p->iperf_edit_tcp = (em_iperf_edit_struct*)MMI_EM_MALLOC(sizeof(em_iperf_edit_struct));
      memset(iperf_p->iperf_edit_tcp, 0, sizeof(em_iperf_edit_struct));
    }

    if(iperf_p->iperf_edit_udp== NULL)
    {
      iperf_p->iperf_edit_udp = (em_iperf_edit_struct*)MMI_EM_MALLOC(sizeof(em_iperf_edit_struct));
      memset(iperf_p->iperf_edit_udp, 0, sizeof(em_iperf_edit_struct));
    }

    if (g_em_iperf_cbm_id == 0)
    {
        cbm_app_info.app_str_id = STR_ID_EM_IPERF;
        cbm_app_info.app_icon_id = GetRootTitleIcon(MENU_ID_EM_IPERF);
        cbm_app_info.app_type = DTCNT_APPTYPE_DEF;
        cbm_register_app_id_with_app_info(&cbm_app_info, &g_em_iperf_cbm_id);
    }

    em_iperf_read_file();

    mmi_frm_group_create_ex(
        mmi_em_get_root_group(),
        GRP_ID_IPERF,
        ef_iperf_setting_scr_group_proc,
        (void*)NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* call iperf entry function */
    EntryEmIperf();
}


/**************************************************************
*   FUNCTION NAME       : PreEntryEmIperfTcp
*
*   PURPOSE             : Pre Entry function for EM IperfTcp (Iperf Setting -> Protocol(TCP) Seting)
*
*   INPUT PARAMETERS    : nil
*
*   OUTPUT PARAMETERS   : void
*
*   RETURNS             : void
*
*   REMARKS             : 
**************************************************************/
void PreEntryEmIperfTcp(void)
{
    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_PRE_ENTRY_IPERF_TCP);

    /* Set Protocol to identify which protocol setting screen*/
    iperf_p->iperf_misc->prot = TCP;    

    EntryEmIperfSetting();
}

/**************************************************************
*   FUNCTION NAME       : EntryEmIperfUdp
*
*   PURPOSE             : Entry function for EM IperfUdp (Iperf Setting -> Protocol(UDP) Seting)
*
*   INPUT PARAMETERS    : nil
*
*   OUTPUT PARAMETERS   : void
*
*   RETURNS             : void
*
*   REMARKS             : 
**************************************************************/
void PreEntryEmIperfUdp(void)
{
    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_PRE_ENTRY_IPERF_UDP);

    /* Set Protocol to identify which protocol setting screen*/
    iperf_p->iperf_misc->prot = UDP;    

    EntryEmIperfSetting();
}

#define Iperf_Entry
/**************************************************************
*   FUNCTION NAME       : EntryEmIperf
*
*   PURPOSE             : Entry function for EM Iperf Setting
*
*   INPUT PARAMETERS    : nil
*
*   OUTPUT PARAMETERS   : void
*
*   RETURNS             : void
*
*   REMARKS             : 
**************************************************************/
void EntryEmIperf(void)
{
    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_ENTRY_IPERF);

    iperf_p->cui_menu_id = cui_menu_create(
                            GRP_ID_IPERF,
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_APPMAIN,
                            MENU_ID_EM_IPERF_APP,
                            MMI_TRUE,
                            NULL);
    cui_menu_run(iperf_p->cui_menu_id);
}


/**************************************************************
*   FUNCTION NAME       : EntryEmIperfSetting
*
*   PURPOSE             : Entry function for EM Iperf Protocol Setting
*
*   INPUT PARAMETERS    : nil
*
*   OUTPUT PARAMETERS   : void
*
*   RETURNS             : void
*
*   REMARKS             : 
**************************************************************/
void EntryEmIperfSetting(void)
{
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct setting_inline;
    em_iperf_edit_struct *activate;

    WCHAR tempbuf[32];
    cui_inline_item_ip4_struct faddr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_ENTRY_IPERF_SETTING);

    if(iperf_p->iperf_misc->prot == UDP)
    {
        activate = iperf_p->iperf_edit_udp;
        setting_inline.title = STR_ID_EM_IPERF_UDP_SETTING;
    }
    else
    {
        activate = iperf_p->iperf_edit_tcp;
        setting_inline.title = STR_ID_EM_IPERF_TCP_SETTING;
    }

    setting_inline.items_count =
        sizeof(g_em_iperf_setting_inline_items) / sizeof(g_em_iperf_setting_inline_items[0]);

    //setting_inline.title_icon = IMG_ID_EM_MAIN_ICON;
    setting_inline.screen_flag = CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE;
    setting_inline.softkey = NULL;
    setting_inline.items = g_em_iperf_setting_inline_items;
    setting_inline.title_icon = IMG_NONE;
    g_ef_iperf_setting_inline_id = cui_inline_create(GRP_ID_IPERF, &setting_inline);

    cui_inline_set_value(
        g_ef_iperf_setting_inline_id,
        EF_IPERF_INLINE_ITEM_CLISRV,
        (void*)activate->client_server);

    faddr.b1 = activate->faddr_ip[0];
    faddr.b2 = activate->faddr_ip[1];
    faddr.b3 = activate->faddr_ip[2];
    faddr.b4 = activate->faddr_ip[3];
    cui_inline_set_value(
        g_ef_iperf_setting_inline_id,
        EF_IPERF_INLINE_ITEM_FADDR,
        (void*)&faddr);

    gui_itoa((U32)activate->len, tempbuf, 10);
    cui_inline_set_value(
        g_ef_iperf_setting_inline_id,
        EF_IPERF_INLINE_ITEM_LEN,
        tempbuf);

    gui_itoa((U32)activate->port, tempbuf, 10);
    cui_inline_set_value(
        g_ef_iperf_setting_inline_id,
        EF_IPERF_INLINE_ITEM_PORT,
        tempbuf);

    if (iperf_p->iperf_misc->prot == TCP)
    {
        cui_inline_set_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_WINDOW_OR_BUFFER_CAP,
            (void*)GetString(STR_ID_EM_IPERF_WINDOW));

        gui_itoa((U32)activate->window, tempbuf, 10);
        cui_inline_set_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_WINDOW_OR_BUFFER,
            tempbuf);

        cui_inline_set_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_MSS_OR_BANDWIDTH_CAP,
            (void*)GetString(STR_ID_EM_IPERF_MSS));

        gui_itoa((U32)activate->mss, tempbuf, 10);
        cui_inline_set_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_MSS_OR_BANDWIDTH,
            tempbuf);
    }
    else if (iperf_p->iperf_misc->prot == UDP)
    {
        cui_inline_set_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_WINDOW_OR_BUFFER_CAP,
            (void*)GetString(STR_ID_EM_IPERF_BUFFER));

        gui_itoa((U32)activate->buffer, tempbuf, 10);
        cui_inline_set_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_WINDOW_OR_BUFFER,
            tempbuf);

        cui_inline_set_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_MSS_OR_BANDWIDTH_CAP,
            (void*)GetString(STR_ID_EM_IPERF_BANDWIDTH));

        gui_itoa((U32)activate->bandwidth, tempbuf, 10);
        cui_inline_set_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_MSS_OR_BANDWIDTH,
            tempbuf);
    }

    cui_inline_set_value(
        g_ef_iperf_setting_inline_id,
        EF_IPERF_INLINE_ITEM_DUAL_TEST,
        (void*)activate->dualtest);

    //cui_inline_set_value(
        //g_ef_iperf_setting_inline_id,
        //EF_IPERF_INLINE_ITEM_TOS,
        //(void*)activate->tos);

    gui_itoa((U32)activate->num, tempbuf, 10);
    cui_inline_set_value(
        g_ef_iperf_setting_inline_id,
        EF_IPERF_INLINE_ITEM_NUM,
        tempbuf);

    gui_itoa((U32)activate->time, tempbuf, 10);
    cui_inline_set_value(
        g_ef_iperf_setting_inline_id,
        EF_IPERF_INLINE_ITEM_TIME,
        tempbuf);

    //cui_inline_set_value(
        //g_ef_iperf_setting_inline_id,
        //EF_IPERF_INLINE_ITEM_RW_FILE,
        //(void*)activate->rw_file);

    cui_inline_set_all_items_softkey_text(
        g_ef_iperf_setting_inline_id,
        MMI_LEFT_SOFTKEY,
        STR_ID_EM_IPERF_RUN);

    cui_inline_run(g_ef_iperf_setting_inline_id);
}


/*****************************************************************************
* FUNCTION
*  em_iperf_show_progressing_screen
* DESCRIPTION
*  This function is to display progressing screen.
*
* PARAMETERS
*  None.
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*  None.
*****************************************************************************/
void em_iperf_show_progressing_screen(void)
{
    mmi_confirm_property_struct arg;

    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_ENTRY_PROGRESSING_SCREEN);

    mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
    arg.parent_id = GRP_ID_IPERF;
    arg.callback = em_iperf_progress_confirm_cb;
    arg.f_auto_dismiss = MMI_FALSE;
    arg.softkey[2].str = (WCHAR*)GetString(STR_GLOBAL_ABORT);
    arg.softkey[2].img = GetImage(IMG_GLOBAL_NO);
    mmi_confirm_display(
        (WCHAR*)GetString(STR_ID_EM_IPERF_PROGRESSING),
        MMI_EVENT_PROGRESS,
        &arg);
}

mmi_ret em_iperf_progress_confirm_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
        case MMI_ALERT_CNFM_3:
            em_iperf_progress_abort();
            mmi_alert_dismiss(alert_result_evt->alert_id);
            ClearProtocolEventHandler(MSG_ID_MMI_IPERF_REPORT_IND);
            iperf_p->is_running = MMI_FALSE;
            break;

        default:
            break;
        }
    }
    return MMI_RET_OK;
}

/**************************************************************
*   FUNCTION NAME       : EntryEmIperfReport
*
*   PURPOSE             : Entry function for EM Iperf Report
*
*   INPUT PARAMETERS    : nil
*
*   OUTPUT PARAMETERS   : void
*
*   RETURNS             : void
*
*   REMARKS             : 
**************************************************************/
void EntryEmIperfReport(void)
{
    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_ENTRY_IPERF_REPORT);
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        g_ef_iperf_grp_id_report, 
                        SCR_ID_EM_IPERF_REPORT,
                        NULL,
                        (FuncPtr)EntryEmIperfReport, 
                        MMI_FRM_FULL_SCRN))
    {
        ShowCategory74Screen(STR_ID_EM_IPERF_REPORT,
                             0,
                             0,
                             IMG_GLOBAL_OK,
                             STR_GLOBAL_BACK,
                             IMG_GLOBAL_BACK,
                             (U8*)iperf_p->iperf_report->report_UI_buffer,
                             sizeof(iperf_p->iperf_report->report_UI_buffer),
                             mmi_frm_scrn_get_active_gui_buf());

        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetRightSoftkeyFunction(em_iperf_report_back, KEY_EVENT_UP);
    }
}


void em_iperf_setting_data_acct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID dtcnt_id;
    cui_dtcnt_select_run_struct select_run_info;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PLUTO_MMI_PACKAGE__
    dtcnt_id = cui_dtcnt_select_create(GRP_ID_IPERF);
#else
    dtcnt_id = vcui_dtcnt_select_create(GRP_ID_IPERF);
#endif

#ifdef __PLUTO_MMI_PACKAGE__
    select_run_info.AppMenuID = MENU_ID_EM_IPERF;
#endif
    select_run_info.app_id = g_em_iperf_cbm_id;
    select_run_info.bearers = DATA_ACCOUNT_BEARER_ALL;
    select_run_info.option = CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
    select_run_info.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
    select_run_info.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;
    select_run_info.icon_id = IMG_NONE;
    select_run_info.str_id = STR_GLOBAL_DATA_ACCOUNT;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        select_run_info.sim_account_id[i] = iperf_p->account_id[i];
    }
#ifdef __PLUTO_MMI_PACKAGE__
    cui_dtcnt_select_set_param(dtcnt_id, &select_run_info);
    cui_dtcnt_select_run(dtcnt_id);
#else
    vcui_dtcnt_select_set_param(dtcnt_id, &select_run_info);
    vcui_dtcnt_select_run(dtcnt_id);
#endif
}


void em_iperf_dt_callback(U8 sim_index, U32 account_id)
{
    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_DT_CB);    

    iperf_p->account_id[sim_index] = account_id;
    em_iperf_save();
    IPERF_DBG(kal_print("Account ID : %u",account_id););

    /* set inline menu changed */
    SetInlineListMenuChanged();
}


#define Iperf_Utility
void em_iperf_run(void)
{
    if (iperf_p->is_running == MMI_FALSE)
    {
        em_iperf_check();
    }
    else
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_BUSY_TRY_LATER),
            MMI_EVENT_FAILURE,
            GRP_ID_IPERF,
            NULL);
    }
}


/*****************************************************************************
* FUNCTION
*   em_iperf_check
* DESCRIPTION
*   check iperf setting to run and save to file
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void em_iperf_check(void)
{
    em_iperf_edit_struct iperf_edit;
    WCHAR len[IPERF_LEN];
    WCHAR port[IPERF_PORT];
    WCHAR window[IPERF_WINDOW];
    WCHAR mss[IPERF_MSS];
    WCHAR buffer[IPERF_BUFFER];
    WCHAR bandwidth[IPERF_BANDWIDTH];
    U8 clisrv_sel = 0;
    U8 dual_test_sel = 0;
    cui_inline_item_ip4_struct faddr;

    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_CHECK_SETTINGS);     

    if(iperf_p->iperf_misc->prot == TCP)
    {
        memcpy(&iperf_edit, iperf_p->iperf_edit_tcp, sizeof(em_iperf_edit_struct));
    }
    else
    {
        memcpy(&iperf_edit, iperf_p->iperf_edit_udp, sizeof(em_iperf_edit_struct));
    }

    /* check iperf settings */
    /* check len */
    cui_inline_get_value(
        g_ef_iperf_setting_inline_id,
        EF_IPERF_INLINE_ITEM_LEN,
        len);
    iperf_edit.len = (S32)gui_atoi(len);
    if(iperf_edit.len > 2880)
    {
         em_iperf_disp_err_popup(STR_ID_EM_IPERF_LEN_ERR);
         return;
    }

    /* check port*/
    cui_inline_get_value(
        g_ef_iperf_setting_inline_id,
        EF_IPERF_INLINE_ITEM_PORT,
        port);
    iperf_edit.port = (U32)gui_atoi(port);
    if(iperf_edit.port > 65535)
    {
         em_iperf_disp_err_popup(STR_ID_EM_IPERF_PORT_ERR);
         return;    
    }

    /* check mss and window */
    if(iperf_p->iperf_misc->prot == TCP) 
    {
        cui_inline_get_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_WINDOW_OR_BUFFER,
            window);
        iperf_edit.window = (S32)gui_atoi(window);
        if(iperf_edit.window > 36000) //36*1000
        {
            em_iperf_disp_err_popup(STR_ID_EM_IPERF_WINDOW_ERR);
            return;
        }
        
        cui_inline_get_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_MSS_OR_BANDWIDTH,
            mss);
        iperf_edit.mss = (S32)gui_atoi(mss);
        if(iperf_edit.mss > 1500)
        {
             em_iperf_disp_err_popup(STR_ID_EM_IPERF_MSS_ERR);
             return;    
        }
    }

     /* check bandwidth and window */        
    if(iperf_p->iperf_misc->prot == UDP) 
    {        
        cui_inline_get_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_WINDOW_OR_BUFFER,
            buffer);
        iperf_edit.buffer = (S32)gui_atoi(window);
        if(iperf_edit.window > 36000) //36*1000
        {
            em_iperf_disp_err_popup(STR_ID_EM_IPERF_BUFFER_ERR);
            return;    
        }

        cui_inline_get_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_MSS_OR_BANDWIDTH,
            bandwidth);
        iperf_edit.bandwidth = (U32)gui_atoi(bandwidth);
        if(iperf_edit.bandwidth > 54000)
        {
            em_iperf_disp_err_popup(STR_ID_EM_IPERF_BANDWIDTH_ERR);
            return;    
        }
    }

    /* check faddr for client mode */
    cui_inline_get_value(
        g_ef_iperf_setting_inline_id,
        EF_IPERF_INLINE_ITEM_CLISRV,
        &clisrv_sel);
    iperf_edit.client_server = clisrv_sel;
    cui_inline_get_value(
        g_ef_iperf_setting_inline_id,
        EF_IPERF_INLINE_ITEM_FADDR,
        &faddr);
    iperf_edit.faddr_ip[0] = faddr.b1;
    iperf_edit.faddr_ip[1] = faddr.b2;
    iperf_edit.faddr_ip[2] = faddr.b3;
    iperf_edit.faddr_ip[3] = faddr.b4;
    if (clisrv_sel == 0) // Client must have an address
    {
        if(faddr.b1 == 0 &&
           faddr.b2 == 0 &&
           faddr.b3 == 0 &&
           faddr.b4 == 0)
        {
            em_iperf_disp_err_popup(STR_ID_EM_IPERF_FADDR_ERR);
            return;
        }
    }

    /* check server - dual testing mode */
    cui_inline_get_value(
        g_ef_iperf_setting_inline_id,
        EF_IPERF_INLINE_ITEM_DUAL_TEST,
        &dual_test_sel);
    iperf_edit.dualtest = dual_test_sel;
    if(dual_test_sel == 1 && clisrv_sel == 1)
    {
        em_iperf_disp_err_popup(STR_ID_EM_IPERF_SERVER_DUAL_ERR);
        return;
    }

    /* get other values */
    {
        WCHAR temp_buf[10];
        //U8 temp_sel;
        cui_inline_get_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_NUM,
            temp_buf);
        iperf_edit.num = (U32)gui_atoi(temp_buf);

        cui_inline_get_value(
            g_ef_iperf_setting_inline_id,
            EF_IPERF_INLINE_ITEM_TIME,
            temp_buf);
        iperf_edit.time = (U32)gui_atoi(temp_buf);

        //cui_inline_get_value(
            //g_ef_iperf_setting_inline_id,
            //EF_IPERF_INLINE_ITEM_TOS,
            //&temp_sel);
        //iperf_edit.tos = temp_sel;

        //cui_inline_get_value(
            //g_ef_iperf_setting_inline_id,
            //EF_IPERF_INLINE_ITEM_RW_FILE,
            //&temp_sel);
        //iperf_edit.rw_file = temp_sel;
    }

    IPERF_DBG(kal_print("Valid Iperf Settings !! \n"););

    /* show progressing screen and set protocol event handler */
    em_iperf_show_progressing_screen();

    /* save the temp info */
    if(iperf_p->iperf_misc->prot == TCP)
    {
        memcpy(iperf_p->iperf_edit_tcp, &iperf_edit, sizeof(em_iperf_edit_struct));
    }
    else
    {
        memcpy(iperf_p->iperf_edit_udp, &iperf_edit, sizeof(em_iperf_edit_struct));
    }

    /* save settings to file */
    em_iperf_save();

    /* fill the req struct and send req to iperf task */
    em_iperf_send_req();
}

/*****************************************************************************
* FUNCTION
*   em_iperf_progress_abort
* DESCRIPTION
*   abort iperf
* PARAMETERS
*   str_id  IN    id of string to be displayed
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void em_iperf_progress_abort(void)
{
    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_PROGRESS_ABORT);
    
    /* clear protocol event handler */
    ClearProtocolEventHandler(MSG_ID_MMI_IPERF_RUN_CNF);
   
    /* call abort function */
#ifdef __MTK_TARGET__
    IPERF_DBG(kal_print("call iperf_stop function!!\n"););
    iperf_stop(0, iperf_cur_job_id % 2);
#endif
    /* show fail popup to notify user */
    em_iperf_disp_fail_popup(STR_GLOBAL_ABORTING);
}

/*****************************************************************************
* FUNCTION
*   em_iperf_report_back
* DESCRIPTION
*   report screen back to prot setting screen 
* PARAMETERS
*   str_id  IN    id of string to be displayed
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void em_iperf_report_back(void)
{
    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_REPORT_BACK);

    /* release allocated report memory */
    if(iperf_p->iperf_report!= NULL)
    {
        MMI_EM_FREE(iperf_p->iperf_report);
        iperf_p->iperf_report= NULL;
    }

    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
* FUNCTION
*   em_iperf_disp_fail_popup
* DESCRIPTION
*   Common function to display fail popup (abort, cnf_fail, report_fail)
* PARAMETERS
*   str_id  IN    id of string to be displayed
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void em_iperf_disp_fail_popup(MMI_STR_ID str_id)
{
    mmi_frm_nmgr_popup(
        MMI_SCENARIO_ID_GENERAL,
        MMI_EVENT_FAILURE,
        (WCHAR*)GetString(str_id));
}

/*****************************************************************************
* FUNCTION
*   em_iperf_disp_err_popup
* DESCRIPTION
*   Common function to display error popup (setting error)
* PARAMETERS
*   str_id  IN    id of string to be displayed
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void em_iperf_disp_err_popup(MMI_STR_ID str_id)
{
    mmi_frm_nmgr_popup(
        MMI_SCENARIO_ID_GENERAL,
        MMI_EVENT_FAILURE,
        (WCHAR*)GetString(str_id));
}


#define Iperf_FS
/*****************************************************************************
* FUNCTION
*   em_iperf_save
* DESCRIPTION
*   Save the settings to file
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void em_iperf_save(void)
{
    FS_HANDLE   fd;
    U32 writtenbytes;
    S32 ret;
    em_iperf_restore_struct restore_data;
    S32 i;

    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_SAVE);

    fd = FS_Open((WCHAR*)IPERF_SETTING_FILE, FS_READ_WRITE | FS_CREATE);
    if(fd < 0)
    {
        IPERF_DBG(kal_print("s%\n",(MMI_STR_ID)srv_fmgr_fs_error_get_string(fd)););
        MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_SAVE_OPEN_FAILED);
        return;
    }

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        restore_data.account_id[i] = iperf_p->account_id[i];
    }
    memcpy(&restore_data.iperf_edit_tcp, iperf_p->iperf_edit_tcp, sizeof(em_iperf_edit_struct));
    memcpy(&restore_data.iperf_edit_udp, iperf_p->iperf_edit_udp, sizeof(em_iperf_edit_struct));
    
    ret= FS_Write(fd, &restore_data, sizeof(em_iperf_restore_struct), &writtenbytes);      
    FS_Close(fd);
    if (ret != FS_NO_ERROR || writtenbytes != sizeof(em_iperf_restore_struct))
    {
        IPERF_DBG(kal_print("s%\n",(MMI_STR_ID)srv_fmgr_fs_error_get_string(ret)););
        return;
    }
}


/*****************************************************************************
* FUNCTION
*   em_iperf_read_file
* DESCRIPTION
*   read both TCP and UDP settings from file
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void em_iperf_read_file(void)
{
    
    FS_HANDLE   fd;
    U32 readbytes;
    S32 ret;
    em_iperf_restore_struct restore_data;
    S32 i;
    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_READ); 

    /*if occurs any file error, try to reload the default settings for both prots */
    
    fd = FS_Open((WCHAR*)IPERF_SETTING_FILE, FS_READ_ONLY);
    if(fd < 0)
    {
        IPERF_DBG(kal_print("s%\n",(MMI_STR_ID)srv_fmgr_fs_error_get_string(fd)););
        MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_READ_OPEN_FAILED);
        /* load default settings */
        em_iperf_load_default();
        return;
    }

    ret= FS_Read(fd, &restore_data, sizeof(em_iperf_restore_struct), &readbytes);    
    if (ret != FS_NO_ERROR || readbytes != sizeof(em_iperf_restore_struct))
    {
        IPERF_DBG(kal_print("s%\n",(MMI_STR_ID)srv_fmgr_fs_error_get_string(ret)););
        MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_READ_TCP_FAILED);            
        /* load default settings */
        FS_Close(fd);
        em_iperf_load_default();
        return;
    }

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        iperf_p->account_id[i] = restore_data.account_id[i];
    }
    memcpy(iperf_p->iperf_edit_tcp, &restore_data.iperf_edit_tcp, sizeof(em_iperf_edit_struct));
    memcpy(iperf_p->iperf_edit_udp, &restore_data.iperf_edit_udp, sizeof(em_iperf_edit_struct));
    FS_Close(fd);
}

/*****************************************************************************
* FUNCTION
*   em_iperf_load_default
* DESCRIPTION
*   load default setting to iperf_p and write default file
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void em_iperf_load_default(void)
{
    S32 i;

    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_LOAD_DEFAULT);

    /* Data account id */
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        iperf_p->account_id[i] = CBM_DEFAULT_ACCT_ID;
    }

    iperf_p->iperf_edit_tcp->client_server = 0;
    iperf_p->iperf_edit_udp->client_server = 0;

    /* Faddr {000.000.000.000} */
    iperf_p->iperf_edit_tcp->faddr_ip[0] = 0;
    iperf_p->iperf_edit_tcp->faddr_ip[1] = 0;
    iperf_p->iperf_edit_tcp->faddr_ip[2] = 0;
    iperf_p->iperf_edit_tcp->faddr_ip[3] = 0;
    
    iperf_p->iperf_edit_udp->faddr_ip[0] = 0;
    iperf_p->iperf_edit_udp->faddr_ip[1] = 0;
    iperf_p->iperf_edit_udp->faddr_ip[2] = 0;
    iperf_p->iperf_edit_udp->faddr_ip[3] = 0;

    /* Len, Window/Buffer */
    iperf_p->iperf_edit_tcp->len = 0;
    iperf_p->iperf_edit_udp->len = 0;
    iperf_p->iperf_edit_tcp->window = 0;
    iperf_p->iperf_edit_udp->window = 0;

    /* Port */
    iperf_p->iperf_edit_tcp->port = 5001;
    iperf_p->iperf_edit_udp->port = 5001;

    /* Num, Time */
    iperf_p->iperf_edit_tcp->num = 1000;
    iperf_p->iperf_edit_udp->num = 1000;
    iperf_p->iperf_edit_tcp->time = 10;
    iperf_p->iperf_edit_udp->time = 10;

    /* TCP MSS, UDP Bandwidth */
    iperf_p->iperf_edit_tcp->mss = 0;
    iperf_p->iperf_edit_udp->bandwidth = 1000;

    iperf_p->iperf_edit_tcp->tos = 0;
    iperf_p->iperf_edit_udp->tos = 0;

    iperf_p->iperf_edit_tcp->rw_file = 0;
    iperf_p->iperf_edit_udp->rw_file = 0;
    IPERF_DBG(kal_print("em_iperf_load_default_complete!!! \n"););

    em_iperf_save();
}


#define Iperf_PS

/*****************************************************************************
* FUNCTION
*   em_iperf_send_req
* DESCRIPTION
*   send req to iperf task 
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void em_iperf_send_req(void)
{
    mmi_iperf_run_req_struct* req;
    em_iperf_edit_struct* act;
    
    srv_dtcnt_sim_type_enum sim_type;
    srv_dtcnt_get_sim_preference(&sim_type);
    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_SEND_REQ);         

    req = OslAllocDataPtr(mmi_iperf_run_req_struct);

    /* outstanding cur_job_id switches between 0 and 1 */
    req->job_id = (++iperf_cur_job_id) % 2;
    
    /* set prots related data */
    
    /* default TCP Testing*/
    act = iperf_p->iperf_edit_tcp;
    
    /* TCP Testing */
    if(iperf_p->iperf_misc->prot == TCP)
    {
        req->udp = KAL_FALSE;   
        req->mss = act->mss;
        IPERF_DBG(kal_print("TCP MSS: %u\n",req->mss););
    }
    
    /* change pointer for UDP Testing */
    if(iperf_p->iperf_misc->prot == UDP)
    {
        act = iperf_p->iperf_edit_udp;
        req->udp = KAL_TRUE;   //udp
        req->bandwidth  = act->bandwidth;
        req->bandwidth  *= 1000;    //kbps -> bps
        IPERF_DBG(kal_print("UDP Bandwidth: %u\n",req->bandwidth););
    }
    
    /* account id */    
    if (srv_tethering_is_on(SRV_TETHERING_TYPE_WIFI_HS) == MMI_TRUE)
    {
        req->account_id = cbm_encode_data_account_id(
                            CBM_WIFI_HS_ACCT_ID,
                            CBM_SIM_ID_SIM1,
                            g_em_iperf_cbm_id,
                            KAL_FALSE);
    }
    else if (sim_type == SRV_DTCNT_SIM_TYPE_NONE)
    {
        req->account_id = cbm_encode_data_account_id(
                            CBM_DEFAULT_ACCT_ID,
                            CBM_SIM_ID_SIM1,
                            g_em_iperf_cbm_id,
                            KAL_FALSE);
    }
    else
    {
        req->account_id = cbm_encode_data_account_id(
                            iperf_p->account_id[sim_type - 1],
                            (cbm_sim_id_enum)(sim_type - 1),
                            g_em_iperf_cbm_id,
                            KAL_FALSE);
    }

    /* client/server */
    if(act->client_server == 0)
    {
        req->client = KAL_TRUE;
        req->server = KAL_FALSE;
    }
    if(act->client_server == 1)
    {
        req->client = KAL_FALSE;
        req->server = KAL_TRUE;
    }

    /* fadder */
    // reassemble faddr
    req->faddr = (act->faddr_ip[0]) << 24 |
                 (act->faddr_ip[1]) << 16 |
                 (act->faddr_ip[2]) <<  8 |
                 (act->faddr_ip[3]);
    IPERF_DBG(kal_print("faddr(host): %u\n",req->faddr););
    // host to network layer address transfer
    req->faddr = soc_htonl(req->faddr);
    IPERF_DBG(kal_print("faddr(nl): %u\n",req->faddr););


    /*len, port, window, num, time*/    
    req->len    = act->len;
    req->port   = act->port;
    req->window = act->window;
    req->num    = act->num;
    req->time   = act->time;
    IPERF_DBG(kal_print("num: %u\n",req->num););
    IPERF_DBG(kal_print("time: %u\n",req->time););

    /* dualtest */
    if(act->dualtest == 0)
        req->dual = KAL_FALSE;
    if(act->dualtest == 1)
        req->dual = KAL_TRUE;
   
    /* tos */
    switch(act->tos)
    {
        case 0:
            req->tos = BEST_EFFORT;
            IPERF_DBG(kal_print("ToS_BE: %u\n",act->tos););
            break;
        case 1:
            req->tos = BACK_GROUND;
            IPERF_DBG(kal_print("ToS_BG: %u\n",act->tos););
            break;
        case 2:
            req->tos = VIDEO;
            IPERF_DBG(kal_print("ToS_VI: %u\n",act->tos););
            break;
        case 3:
            req->tos = VOICE;
            IPERF_DBG(kal_print("ToS_VO: %u\n",act->tos););
            break;
        default:
            //mine assert (should never happens)
            MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_SEND_REQ_TOS);                     
            IPERF_DBG(kal_print("ToS_DE: %u\n",act->tos););
    }
    
    /* RW File */
    if (act->rw_file == 0)
        req->rw_file = MMI_FALSE;
    else if (act->rw_file == 1)
        req->rw_file = MMI_TRUE;
    
    IPERF_DBG(kal_print("em_iperf_fill_req_complete!!! \n"););

    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_SEND_REQ_ILM);                     
    iperf_p->is_running = MMI_TRUE;
    /* set protocol event handler to handle run_cnf msg and report_ind msg */
    SetProtocolEventHandler(em_iperf_run_cnf_hf, MSG_ID_MMI_IPERF_RUN_CNF);
    SetProtocolEventHandler(em_iperf_report_ind_hf, MSG_ID_MMI_IPERF_REPORT_IND);

    /* Send Message to iperf task */ 
    IPERF_DBG(kal_print("em_iperf_send_req!!! \n"););
    mmi_frm_send_ilm(
        MOD_IPERF,
        MSG_ID_MMI_IPERF_RUN_REQ,
        (oslParaType*)req,
        NULL);
    IPERF_DBG(kal_print("em_iperf_send_req_complete!!! \n"););
}


/*****************************************************************************
* FUNCTION
*   em_iperf_run_cnf_hf
* DESCRIPTION
*   Handler for MSG_ID_MMI_IPERF_RUN_CNF.
* PARAMETERS
*   msg IN  result of confirm
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void em_iperf_run_cnf_hf(void* msg)
{
    mmi_iperf_run_cnf_struct* cnf = (mmi_iperf_run_cnf_struct*)msg;

    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_RUN_CNF_HF);         

    /* clear protocol event handler */
    ClearProtocolEventHandler(MSG_ID_MMI_IPERF_RUN_CNF);

    /* confirm fail*/
    if(cnf->result == MMI_FALSE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_RUN_CNF_HF_FALSE);         
        iperf_p->is_running = MMI_FALSE;
        /* clear protocol event handler */
        ClearProtocolEventHandler(MSG_ID_MMI_IPERF_REPORT_IND);
        mmi_alert_dismiss(iperf_p->progressing_alert_id);

        /* show fail popup */
        em_iperf_disp_fail_popup(STR_ID_EM_IPERF_CNF_FAILED_ERR);
    }
}


/*****************************************************************************
* FUNCTION
*   em_iperf_report_ind_hf
* DESCRIPTION
*   Handler for MSG_ID_MMI_IPERF_REPORT_IND.
* PARAMETERS
*   msg IN  result of indication
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void em_iperf_report_ind_hf(void* msg)
{
    mmi_iperf_report_ind_struct* ind = (mmi_iperf_report_ind_struct*)msg;

    MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_REPORT_IND_HF);       
     
    /* clear protocol event handler */
    ClearProtocolEventHandler(MSG_ID_MMI_IPERF_REPORT_IND);
    iperf_p->is_running = MMI_FALSE;
    
    if (mmi_frm_group_is_present(GRP_ID_IPERF) == MMI_FALSE)
    {
        return;
    }
    
    /* report fail */
    if(ind->result == 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_REPORT_IND_HF_FALSE);
        mmi_alert_dismiss(iperf_p->progressing_alert_id);
        em_iperf_disp_fail_popup(STR_GLOBAL_FAILED);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G8_EM,MMI_EM_IPERF_ENTRY_REPORT_SCREEN);       

        /* show report screen and delete progressing screen */
        /* allocated memory for showing report */
        if(iperf_p->iperf_report== NULL)
        {
          iperf_p->iperf_report = (em_iperf_report_struct*)MMI_EM_MALLOC(sizeof(em_iperf_report_struct));
          memset(iperf_p->iperf_report, 0, sizeof(em_iperf_report_struct));
        }
        /* prepare report buffer */
        if(ind->prot == TCP)
        {
            #define _p1 "Prot : TCP\n"
            #define _i "Interval(secs) : %.1f\n"
            #define _tx "Transfer: %4.1f %s\n"
            #define _th "Thrpt : %6.3f %s\n"
            #define _s "Size : %u\n"
            sprintf((S8*)iperf_p->iperf_report->report_buff, _p1 _i _tx _th _s, 
                ind->interval,
                ind->transfer > 1000000 ? ind->transfer/1000000.0 :
                ind->transfer > 1000 ? ind->transfer/1000.0 : ind->transfer,
                ind->transfer > 1000000 ? "MBytes" : ind->transfer > 1000 ? "KBytes" : "Bytes",            
                ind->thruput > 1000000 ? ind->thruput/1000000 :
                ind->thruput > 1000 ? ind->thruput/1000 : ind->thruput,
                ind->thruput > 1000000 ? "Mbps" : ind->thruput > 1000 ? "Kbps" : "bps",
                ind->size);

        }
        else /* UDP */
        {
            #define _p2 "Prot : UDP\n"
            #define _d "Datagram Size : %u\n"
            #define _j "Jitter : %5.3f ms\n"           
            #define _l "Lost pkt : %4d\n"
            #define _t "Total pkt : %5d\n"
            #define _r "Loss Rate : %.2f%%"

            sprintf((S8*)iperf_p->iperf_report->report_buff, _p2 _i _tx _th _s _d _j _l _t _r,
                ind->interval,
                ind->transfer > 1000000 ? ind->transfer/1000000.0 :
                ind->transfer > 1000 ? ind->transfer/1000.0 : ind->transfer,
                ind->transfer > 1000000 ? "MBytes" : ind->transfer > 1000 ? "KBytes" : "Bytes",            
                ind->thruput > 1000000 ? ind->thruput/1000000 :
                ind->thruput > 1000 ? ind->thruput/1000 : ind->thruput,
                ind->thruput > 1000000 ? "Mbps" : ind->thruput > 1000 ? "Kbps" : "bps",
                ind->size,
                ind->datagram_size,
                ind->jitter,
                ind->lost_pkt,
                ind->total_pkt,
                ind->loss_rate);
        }

        /* prepare UI buffer */
        mmi_asc_to_ucs2((S8*)iperf_p->iperf_report->report_UI_buffer, (S8*)iperf_p->iperf_report->report_buff);

        /* call report screen entry function */
        g_ef_iperf_grp_id_report = mmi_frm_group_create(
                            mmi_em_get_root_group(),
                            GRP_ID_IPERF,
                            NULL,
                            NULL);
        mmi_frm_group_enter(g_ef_iperf_grp_id_report, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        EntryEmIperfReport();
    }
}

#endif /* __MMI_EM_IPERF__ */
