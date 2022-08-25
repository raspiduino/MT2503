/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  NtpApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "NtpApp.h"
#include "mmi_rp_app_ntp_def.h"
#include "NtpSrvGprot.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "Inlinecuigprot.h"
#include "MenuCuiGprot.h"
#include "GlobalResDef.h"
#include "DataAccountCuiGprot.h"
#include "DataAccountGProt.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "CommonScreensResDef.h"
#include "SimCtrlSrvGprot.h"

typedef enum
{
    MMI_NTP_TURN_ON_OFF_CAPTION = (CUI_INLINE_ITEM_ID_BASE + 0),
    MMI_NTP_TURN_ON_OFF_CONTENT,

    MMI_NTP_DATA_ACCT_CAPTION,
    MMI_NTP_DATA_ACCT_CONTENT,

    MMI_NTP_INLINE_END,
    MMI_NTP_INLINE_TOTAL = MMI_NTP_INLINE_END - MMI_NTP_TURN_ON_OFF_CAPTION,
}mmi_ntp_inline_item_enum;

static mmi_id inline_id;
static U32 g_dataacct_id[MMI_SIM_TOTAL];

static void mmi_ntp_sel_dtcnt_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_ID dtcnt_id;
    cui_dtcnt_select_run_struct select_run_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_any_sim_is_available())
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            0);
        return;
    }

    memset(&select_run_info, 0x00, sizeof(cui_dtcnt_select_run_struct));

    dtcnt_id = cui_dtcnt_select_create(GRP_ID_NTP_APP);
    for (i = 0; i < MMI_SIM_TOTAL; ++i)
    {
        select_run_info.sim_account_id[i] = g_dataacct_id[i];
    }
    select_run_info.str_id = STR_GLOBAL_DATA_ACCOUNT;
    select_run_info.icon_id = GetRootTitleIcon(MENU_ID_NTP_APP);
    select_run_info.app_id = srv_ntp_data_acct_app_id_get();
    select_run_info.AppMenuID = MENU_ID_NTP_APP;
    select_run_info.bearers = DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI;
    select_run_info.option = CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
    select_run_info.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
    select_run_info.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;
    cui_dtcnt_select_set_param(dtcnt_id, &select_run_info);
    cui_dtcnt_select_run(dtcnt_id);
}

static void mmi_ntp_inline_submit(cui_event_inline_submit_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
    confirm_struct.parent_id = GRP_ID_NTP_APP;
    confirm_struct.user_tag = (void*)MMI_NTP_DATA_ACCT_CONTENT;
    mmi_confirm_display(
        (WCHAR*)GetString(STR_GLOBAL_SAVE_ASK),
        MMI_EVENT_QUERY,
        &confirm_struct);
}

void mmi_ntp_sync_result_proc(S32 result, S64 offset, void*user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_CONN_TRC_G9_NTPD, APP_NTP_SYNC_PROC, result, offset, __LINE__);
    if (result == 0)
    {
        /* for SUCCESS, update phone's time */
        srv_ntp_update_time_to_phone(offset, NULL, NULL);
    }
}

static void mmi_ntp_setting_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ntp_on_off;
    MMI_BOOL orig_availability;
    MMI_BOOL curr_availability;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(inline_id, MMI_NTP_TURN_ON_OFF_CONTENT, &ntp_on_off);
    
    orig_availability = srv_ntp_availability_get();
    curr_availability = ntp_on_off == 1 ? MMI_TRUE : MMI_FALSE;
    srv_ntp_availability_set(curr_availability);
/*
    MMI_TRACE(MMI_CONN_TRC_G9_NTPD,
              APP_NTP_SETTING_SAVE,
              orig_availability,
              curr_availability,
              __LINE__);
*/
    for (i = 0; i < MMI_SIM_TOTAL; ++i)
    {
        srv_ntp_data_acct_set(g_dataacct_id[i], i);
    }

    if (curr_availability && !orig_availability)
    {
        srv_ntp_sync(mmi_ntp_sync_result_proc, NULL);
    }
}

static void mmi_ntp_alert_quit(mmi_alert_result_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 user_tag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_tag = (U32)p_event->user_tag;
    switch (user_tag)
    {
        case MMI_NTP_DATA_ACCT_CONTENT:
        {
            if (MMI_ALERT_CNFM_YES == p_event->result)
            {
                mmi_ntp_setting_save();
            }
            cui_inline_close(inline_id);
        }
        default:
        {
            break;
        }
    }
    return;    
}


static mmi_ret mmi_ntp_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            // cui_event_inline_notify_struct *e = (cui_event_inline_notify_struct*)evt;
            break;
        }

        case EVT_ID_CUI_INLINE_SET_KEY:
        {
            cui_event_inline_set_key_struct *e = (cui_event_inline_set_key_struct*)evt;
            if (e->item_id == MMI_NTP_DATA_ACCT_CONTENT)
            {
                wgui_inline_set_lsk_function(mmi_ntp_sel_dtcnt_lsk);
                SetCenterSoftkeyFunction(mmi_ntp_sel_dtcnt_lsk, KEY_EVENT_UP);
            }
            break;
        }

        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            mmi_ntp_inline_submit((cui_event_inline_submit_struct*)evt);
            break;
        }

        case EVT_ID_ALERT_QUIT:
        {
            mmi_ntp_alert_quit((mmi_alert_result_evt_struct*)evt);
            break;
        }

        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
        {
            cui_dtcnt_select_event_any_sim_selected_struct* e =
                (cui_dtcnt_select_event_any_sim_selected_struct*)evt;
            g_dataacct_id[e->selectSim] = e->accountId;

            // make RSK to "Done"
            cui_inline_set_screen_attributes(
                inline_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
            break;
        }
        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
        {
            cui_dtcnt_select_event_result_struct* e = (cui_dtcnt_select_event_result_struct*)evt;
            cui_dtcnt_select_close(e->sender_id);
            break;
        }

        case EVT_ID_CUI_INLINE_ABORT:
        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        {
            cui_inline_close(((cui_event_inline_common_struct*)evt)->sender_id);
        }

        default:
            break;
      }

      return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_entry_ntp_app
 * DESCRIPTION
 *  This function is entry function of NITZ menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_ntp_app(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 inline_item_index = 0;
    S32 caption_index = 0;
    cui_inline_struct inline_struct;
    cui_inline_set_item_struct *inline_item = NULL;
    cui_inline_item_caption_struct caption_struct[MMI_NTP_INLINE_TOTAL/2];
    cui_inline_item_select_struct select_struct;
    cui_inline_item_display_only_struct display_only_struct;
    const U16 list_of_item_id[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
    const cui_inline_item_softkey_struct softkey_struct = {{
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}}};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(parent_id, 
                         GRP_ID_NTP_APP, 
                         mmi_ntp_group_proc, 
                         NULL);

    mmi_frm_group_enter(GRP_ID_NTP_APP, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_item = OslMalloc(
        sizeof(cui_inline_set_item_struct) * MMI_NTP_INLINE_TOTAL);

    // NTP availability setting
    caption_struct[caption_index].string_id = STR_ID_NTP_APP;
    inline_item[inline_item_index].item_id = MMI_NTP_TURN_ON_OFF_CAPTION;
    inline_item[inline_item_index].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[inline_item_index].image_id = 0;
    inline_item[inline_item_index].item_data = &caption_struct[caption_index];
    ++caption_index;
    ++inline_item_index;

    select_struct.n_items = sizeof(list_of_item_id)/sizeof(list_of_item_id[0]);
    select_struct.highlighted_item = srv_ntp_availability_get();
    select_struct.list_of_item_id = list_of_item_id;
    inline_item[inline_item_index].item_id = MMI_NTP_TURN_ON_OFF_CONTENT;
    inline_item[inline_item_index].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
    inline_item[inline_item_index].image_id = 0;
    inline_item[inline_item_index].item_data = &select_struct;
    ++inline_item_index;

    /* data account part begin */
    caption_struct[caption_index].string_id = STR_GLOBAL_DATA_ACCOUNT;
    inline_item[inline_item_index].item_id = MMI_NTP_DATA_ACCT_CAPTION;
    inline_item[inline_item_index].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[inline_item_index].image_id = 0;
    inline_item[inline_item_index].item_data = &caption_struct[caption_index];
    ++caption_index;
    ++inline_item_index;
    
    display_only_struct.default_text_id = STR_GLOBAL_DATA_CONN_SETTING;
    display_only_struct.string_id = STR_GLOBAL_DATA_CONN_SETTING;
    inline_item[inline_item_index].item_id = MMI_NTP_DATA_ACCT_CONTENT;
    inline_item[inline_item_index].item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY;
    inline_item[inline_item_index].image_id = 0;
    inline_item[inline_item_index].item_data = &display_only_struct;
    ++inline_item_index;
    /* data account part end */

    inline_struct.items_count = (U8)(MMI_NTP_INLINE_TOTAL);
    inline_struct.title = STR_ID_NTP_APP;
    inline_struct.title_icon = 0;//GetRootTitleIcon(MENU_ID_NTP_APP);
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = &softkey_struct;
    inline_struct.items = inline_item;

    inline_id = cui_inline_create(GRP_ID_NTP_APP, &inline_struct);

    cui_inline_set_value(inline_id, MMI_NTP_DATA_ACCT_CONTENT, (WCHAR*)GetString(STR_GLOBAL_DATA_CONN_SETTING));
    cui_inline_set_softkey_text(inline_id, MMI_NTP_DATA_ACCT_CONTENT, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
    cui_inline_set_softkey_icon(inline_id, MMI_NTP_DATA_ACCT_CONTENT, MMI_LEFT_SOFTKEY, 0);
    cui_inline_set_softkey_icon(inline_id, MMI_NTP_DATA_ACCT_CONTENT, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);

    for (i = 0; i < MMI_SIM_TOTAL; ++i)
    {
        g_dataacct_id[i] = srv_ntp_data_acct_get(i);
    }

    /*
    if (!srv_sim_ctrl_any_sim_is_available())
    {
        // disable data account item
        cui_inline_set_item_attributes(
            inline_id, 
            MMI_NTP_DATA_ACCT_CONTENT, 
            CUI_INLINE_SET_ATTRIBUTE, 
            CUI_INLINE_ITEM_DISABLE);
    }
    */

    cui_inline_run(inline_id);

    OslMfree(inline_item);
}


mmi_ret mmi_ntp_phnset_menu_handler(void *menu_evt, mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct *)menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt != NULL && parent_id != GRP_ID_INVALID);
    
    if (evt->highlighted_menu_id == MENU_ID_NTP_APP &&
        (evt->evt_id == EVT_ID_CUI_MENU_ITEM_SELECT ||
         evt->evt_id == EVT_ID_CUI_MENU_ITEM_TAP ||
         evt->evt_id == EVT_ID_CUI_MENU_ITEM_CSK_SELECT))
    {
        mmi_entry_ntp_app(parent_id);
        return MMI_RET_OK;
    }

    return MMI_RET_DONT_CARE;
}

