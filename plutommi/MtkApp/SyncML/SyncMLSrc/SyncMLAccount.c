/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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

/* Filename:
 * ---------
 *    SyncMLAccount.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*****************************************************************************
* Include
*****************************************************************************/

#include "MMI_features.h"
#ifdef __SYNCML_SUPPORT__

#include "common_nvram_editor_data_item.h"
#include "MMIDataType.h"
#include "mmi_rp_srv_syncml_def.h"
#include "GlobalResDef.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "custom_mmi_default_value.h"
#include "cbm_api.h"
#include "wgui_categories_util.h"
#include "cbm_consts.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "fs_func.h"
#include "wgui_categories_list.h"
#include "mmi_rp_app_mobile_service_def.h"
#include "app_url.h"
#include "custom_data_account.h"
#include "AlarmFrameWorkProt.h"
#include "SyncMLGProt.h"
#include "SyncMLDef.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"
#include "DataAccountGProt.h"
#include "cbmsrvgprot.h"
#include "dtcntsrvgprot.h"
#include "fseditorcuigprot.h"
#include "menucuigprot.h"
#include "dataaccountcuigprot.h"
#include "inlinecuigprot.h"
#include "SimCtrlSrvGprot.h"
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#endif


/*****************************************************************************
 * Static variable declaration
 *****************************************************************************/
static mmi_syncml_account_edit_struct g_syncml_account_edit;

#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
static U8 g_syncml_account_index = 0xff;
#endif

/*****************************************************************************
 * Global variable declaration
 *****************************************************************************/
mmi_syncml_account_struct g_syncml_account;


/*****************************************************************************
 * Static function declaration
 *****************************************************************************/
/* account list */
static void mmi_syncml_account_list_entry_evt_hdlr(cui_menu_event_struct* evt);
static void mmi_syncml_account_list_hilite_evt_hdlr(cui_menu_event_struct* evt);

/* account option */
static void mmi_syncml_account_option_entry_evt_hdlr(cui_menu_event_struct* evt);
static void mmi_syncml_entry_account_edit(void);
static void mmi_syncml_entry_account_sync(void);
static void mmi_syncml_account_edit_entry_evt_hdlr(cui_menu_event_struct* evt);

/* account name */
static void mmi_syncml_entry_account_name(void);
static void mmi_syncml_edit_account_name_save(cui_fseditor_evt_struct *evt);

/* account trans type */
static void mmi_syncml_entry_account_trans_type(void);
static void mmi_syncml_account_trans_type_entry_evt_hdlr(cui_menu_event_struct* evt);
static void mmi_syncml_account_trans_type_edit_save(cui_menu_event_struct* evt);

/* account app to sync */
static void mmi_syncml_account_app_to_sync_entry_evt_hdlr(cui_menu_event_struct* evt);
static void mmi_syncml_account_app_to_sync_exit_evt_hdlr(cui_menu_event_struct* evt);
static void mmi_syncml_account_app_to_sync_edit_confirm(void);
static void mmi_syncml_account_app_to_sync_edit_save(void);
static void mmi_syncml_account_app_to_sync_edit_cancel(void);

/* account server setting */
static void mmi_syncml_edit_account_server_setting_done(void);
static void mmi_syncml_edit_account_server_setting_save(void);

/* account database setting */
static void mmi_syncml_account_db_settings_entry_evt_hdlr(cui_menu_event_struct* evt);

static void mmi_syncml_edit_account_db_contact_done(void);
static void mmi_syncml_edit_account_db_contact_save(void);

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
static void mmi_syncml_edit_account_db_calendar_done(void);
static void mmi_syncml_edit_account_db_calendar_save(void);
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
static void mmi_syncml_edit_account_db_task_done(void);
static void mmi_syncml_edit_account_db_task_save(void);
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
static void mmi_syncml_edit_account_db_note_done(void);
static void mmi_syncml_edit_account_db_note_save(void);
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

/* account data account setting */
static void mmi_syncml_select_data_account_save(U32 index, cui_dtcnt_sim_enum dtcnt_enum);

/* account regular sync */
static void mmi_syncml_entry_account_regular_sync(void);
static void mmi_syncml_account_regular_sync_entry_evt_hdlr(cui_menu_event_struct* evt);
static void mmi_syncml_account_regular_sync_edit_save(cui_menu_event_struct * evt);
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
static void mmi_syncml_account_regular_sync_edit_confirm(void);
static void mmi_syncml_account_regular_sync_edit_cancel(void);
#endif
static void mmi_syncml_account_regular_sync_edit_save_done(void);

/* account report */
static void mmi_syncml_entry_account_sync_report(void);
static void mmi_syncml_account_report_entry_evt_hdlr(cui_menu_event_struct* evt);
static void mmi_syncml_account_report_edit_save(cui_menu_event_struct* evt);

/* account sas */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

/* account refresh sync */
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
static void mmi_syncml_entry_account_sync_type(cui_menu_event_struct* evt);
static void mmi_syncml_account_sync_type_entry_evt_hdlr(cui_menu_event_struct* evt);
static void mmi_syncml_account_sync_type_edit_save(cui_menu_event_struct* evt);
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */



/*****************************************************************************
 * Static varaible definition
 *****************************************************************************/
/* for inline editor cui */
static const cui_inline_item_caption_struct svr_addr_cap = 
{
    STR_ID_SYNC_SERVER_ADDRESS
};
static const cui_inline_item_caption_struct db_addr_cap = 
{
    STR_ID_SYNC_DATABASE_ADDRESS
};
static const cui_inline_item_caption_struct user_name_cap = 
{
    STR_GLOBAL_USERNAME
};
static const cui_inline_item_caption_struct password_cap = 
{
    STR_GLOBAL_PASSWORD
};

static const cui_inline_item_fullscreen_edit_struct svr_addr = 
{
    0,
    0,
    STR_ID_SYNC_SERVER_ADDRESS,
    IMG_ID_SYNC_MENU,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL | INPUT_TYPE_EXT_ASCII_ENCODING_BASE_LENGTH,
    IMM_INPUT_TYPE_URL,
    MAX_SYNCML_SERVER_ADDR_LEN,
    NULL
};
static const cui_inline_item_fullscreen_edit_struct db_addr = 
{
    0,
    0,
    STR_ID_SYNC_DATABASE_ADDRESS,
    IMG_ID_SYNC_MENU,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ASCII_CHAR,
    MAX_SYNCML_DATABASE_ADDR_LEN,
    NULL
};
static const cui_inline_item_fullscreen_edit_struct user_name = 
{
    0,
    0,
    STR_GLOBAL_USERNAME,
    IMG_ID_SYNC_MENU,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ASCII_CHAR,
    MAX_SYNCML_USERNAME,
    NULL
};
static const cui_inline_item_fullscreen_edit_struct password = 
{
    0,
    0,
    STR_GLOBAL_PASSWORD,
    IMG_ID_SYNC_MENU,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ASCII_PASSWORD,
    MAX_SYNCML_PASSWORD,
    NULL
};

/*
static const U16 user_proxy_select[2] = {STR_GLOBAL_NO, STR_GLOBAL_YES};
static const cui_inline_item_select_struct user_proxy = 
{
    2,
    0,
    (U16*)user_proxy_select
};*/

/* server setting */
const cui_inline_set_item_struct server_setting_inline[6] = 
{
    {MMI_SYNCML_INLINE_SVR_ADDR_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_SERVER, (void*)&svr_addr_cap},
    {MMI_SYNCML_INLINE_SVR_ADDR, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&svr_addr},
    {MMI_SYNCML_INLINE_SVR_UN_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_USERNAME, (void*)&user_name_cap},
    {MMI_SYNCML_INLINE_SVR_UN, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&user_name},
    {MMI_SYNCML_INLINE_SVR_PSW_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_PASSWORD, (void*)&password_cap},
    {MMI_SYNCML_INLINE_SVR_PSW, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&password}
};
const cui_inline_struct server_setting_screen = 
{
    6,
    STR_ID_SYNC_PROFILE_SERVER,
    IMG_ID_SYNC_MENU,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    server_setting_inline
};

/* contact setting */
const cui_inline_set_item_struct con_setting_inline[6] = 
{
    {MMI_SYNCML_INLINE_CON_ADDR_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_CONTACT, (void*)&db_addr_cap},
    {MMI_SYNCML_INLINE_CON_ADDR, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&db_addr},
    {MMI_SYNCML_INLINE_CON_UN_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_USERNAME, (void*)&user_name_cap},
    {MMI_SYNCML_INLINE_CON_UN, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&user_name},
    {MMI_SYNCML_INLINE_CON_PSW_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_PASSWORD, (void*)&password_cap},
    {MMI_SYNCML_INLINE_CON_PSW, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&password}
};
const cui_inline_struct con_setting_screen = 
{
    6,
    STR_ID_SYNC_APP_PHB,
    IMG_ID_SYNC_MENU,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    con_setting_inline
};

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
/* calendar setting */
const cui_inline_set_item_struct cal_setting_inline[6] = 
{
    {MMI_SYNCML_INLINE_CAL_ADDR_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_CALENDAR, (void*)&db_addr_cap},
    {MMI_SYNCML_INLINE_CAL_ADDR, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&db_addr},
    {MMI_SYNCML_INLINE_CAL_UN_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_USERNAME, (void*)&user_name_cap},
    {MMI_SYNCML_INLINE_CAL_UN, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&user_name},
    {MMI_SYNCML_INLINE_CAL_PSW_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_PASSWORD, (void*)&password_cap},
    {MMI_SYNCML_INLINE_CAL_PSW, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&password}
};
const cui_inline_struct cal_setting_screen = 
{
    6,
    STR_ID_SYNC_APP_CAL,
    IMG_ID_SYNC_MENU,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    cal_setting_inline
};
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
/* calendar setting */
const cui_inline_set_item_struct task_setting_inline[6] = 
{
    {MMI_SYNCML_INLINE_TASK_ADDR_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_TASK, (void*)&db_addr_cap},
    {MMI_SYNCML_INLINE_TASK_ADDR, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&db_addr},
    {MMI_SYNCML_INLINE_TASK_UN_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_USERNAME, (void*)&user_name_cap},
    {MMI_SYNCML_INLINE_TASK_UN, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&user_name},
    {MMI_SYNCML_INLINE_TASK_PSW_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_PASSWORD, (void*)&password_cap},
    {MMI_SYNCML_INLINE_TASK_PSW, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&password}
};
const cui_inline_struct task_setting_screen = 
{
    6,
    STR_ID_SYNC_APP_TASK,
    IMG_ID_SYNC_MENU,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    task_setting_inline
};
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
/* note setting */
const cui_inline_set_item_struct note_setting_inline[6] = 
{
    {MMI_SYNCML_INLINE_NOTE_ADDR_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_NOTE, (void*)&db_addr_cap},
    {MMI_SYNCML_INLINE_NOTE_ADDR, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&db_addr},
    {MMI_SYNCML_INLINE_NOTE_UN_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_USERNAME, (void*)&user_name_cap},
    {MMI_SYNCML_INLINE_NOTE_UN, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&user_name},
    {MMI_SYNCML_INLINE_NOTE_PSW_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SYNC_PASSWORD, (void*)&password_cap},
    {MMI_SYNCML_INLINE_NOTE_PSW, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&password}
};
const cui_inline_struct note_setting_screen = 
{
    6,
    STR_ID_SYNC_APP_NOTE,
    IMG_ID_SYNC_MENU,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    note_setting_inline
};
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */


/*****************************************************************************
 * Function definition
 *****************************************************************************/
#define Common_api
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_profile_init
 * DESCRIPTION
 *  Initialize highlight and hint for SyncML profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_app_info_struct info;
    U8 app_id;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info.app_type = DTCNT_APPTYPE_SYNCML;
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
    info.app_icon_id = GetRootTitleIcon(MENU_ID_SYNCML_MAIN);
#endif
    
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {
        info.app_str_id = STR_ID_SYNC_APP_ID1 + i;

        /* register app_id for each sync account */
        if (CBM_OK == cbm_register_app_id_with_app_info(&info, &app_id))
        {
            g_mmi_syncml_cntx.app_id[i] = app_id;
        }
		
        /* register diconnection function for syncml app */
        srv_cbm_register_bearer_info(
            app_id, 
            SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED, 
            SRV_CBM_BEARER_PS | SRV_CBM_BEARER_GPRS | SRV_CBM_BEARER_WIFI, 
            (mmi_proc_func)mmi_syncml_cbm_brearer_disconn_callback, 
            NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_read_account_from_nvram
 * DESCRIPTION
 *  Read account from NVRAM, when entry edit from idle screen(regular sync notification)
 * PARAMETERS
 *  record_id       [IN]            record index
 *  temp_buff       [IN]            buffer to read
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_pre_read_account(U8 account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_SYNCML_ACCOUNT_LID, account_id , (void*)&g_syncml_account, NVRAM_EF_SYNCML_ACCOUNT_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_read_account_from_nvram
 * DESCRIPTION
 *  Read account from NVRAM
 * PARAMETERS
 *  record_id       [IN]            record index
 *  temp_buff       [IN]            buffer to read
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_read_account_from_nvram(U8 record_id, void *temp_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *temp_account = (mmi_syncml_account_struct *) temp_buff;
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record_id == 0)
    {
        return;
    }
    
    ReadRecord(NVRAM_EF_SYNCML_ACCOUNT_LID, record_id, (void*)temp_account, NVRAM_EF_SYNCML_ACCOUNT_SIZE, &error); 
    
    if (mmi_ucs2strlen((CHAR*)temp_account->account_name) == 0)
    {
        mmi_ucs2cpy((CHAR*)temp_account->account_name, GetString((U16)(STR_ID_SYNC_PROFILE_ID1 + record_id - 1)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_write_account_to_nvram
 * DESCRIPTION
 *  Write account to NVRAM
 * PARAMETERS
 *  record_id       [IN]            record index
 *  temp_buff       [IN]            buffer to read
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_write_account_to_nvram(U8 record_id, void *temp_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *temp_account = (mmi_syncml_account_struct *) temp_buff;
    U8 temp_name_modified = 0;
    S16 error;    
	U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If current language is changed, the GetString value will be changed, so save the null name */
    if (mmi_ucs2cmp((CHAR*) temp_account->account_name, GetString((U16)(STR_ID_SYNC_PROFILE_ID1 + record_id - 1))) == 0)
    {
        memset(temp_account->account_name, 0, MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH);
        temp_name_modified = 1;   
    }
    
    WriteRecord(NVRAM_EF_SYNCML_ACCOUNT_LID, record_id, (void*)temp_account, NVRAM_EF_SYNCML_ACCOUNT_SIZE, &error);

    if (temp_name_modified)
    {   
        /* use the new value under current language */
        mmi_ucs2cpy((CHAR*) temp_account->account_name, GetString((U16) (STR_ID_SYNC_PROFILE_ID1 + record_id - 1)));
    }
    
    for(i = 0; i < MMI_MAX_SIM_NUM; i++ )
    {
		g_mmi_syncml_cntx.net_id[record_id - 1][i] = temp_account->net_id[i];
    }
}


#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_active_account_bearer
 * DESCRIPTION
 *  Bearer check for preferred mode
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U32 mmi_syncml_get_active_account_bearer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *temp_account = NULL;
	srv_dtcnt_sim_type_enum sim_id;
    U32 net_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_account = (mmi_syncml_account_struct*) OslMalloc(sizeof(mmi_syncml_account_struct));
    
    mmi_syncml_read_account_from_nvram(g_mmi_syncml_cntx.active_account, (void*)temp_account);

	srv_dtcnt_get_sim_preference(&sim_id);
	
	if(SRV_DTCNT_SIM_TYPE_NONE == sim_id)
	{
		sim_id = SRV_DTCNT_SIM_TYPE_1;
	}
	
	net_id = temp_account->net_id[sim_id -1];
    
    if (temp_account != NULL)
    {
        OslMfree(temp_account);
    }
    
    return (U32)cbm_get_original_account(net_id);
}
#endif /* __MMI_WLAN_FEATURES__ */


#define hint_function
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_name_set_hint
 * DESCRIPTION
 *  "account name" menu hint handler
 * PARAMETERS
 *  index       [IN]        hint index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_name_set_hint(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    /* name hint */
    cui_menu_set_item_hint(
        evt->sender_id, 
        MENU_ID_SYNCML_ACCOUNT_EDIT_NAME, 
        (UI_string_type)g_syncml_account.account_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_transport_type_set_hint
 * DESCRIPTION
 *  "transport type" menu hint handler
 * PARAMETERS
 *  index       [IN]        hint index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_transport_type_set_hint(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
	if (g_syncml_account.transport_type == MMI_SYNCML_TRANS_TYPE_INTERNET)
	{   
        cui_menu_set_item_hint(
            evt->sender_id, 
            MENU_ID_SYNCML_ACCOUNT_EDIT_TRANSPORT_TYPE, 
            (UI_string_type)get_string(STR_ID_SYNC_CONN_INTERNET));             
	}
	else
	{
        cui_menu_set_item_hint(
            evt->sender_id, 
            MENU_ID_SYNCML_ACCOUNT_EDIT_TRANSPORT_TYPE, 
            (UI_string_type)get_string(STR_ID_SYNC_CONN_BT)); 
	}    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_server_settings_set_hint
 * DESCRIPTION
 *  "server setting" menu hint handler
 * PARAMETERS
 *  index       [IN]        hint index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_server_settings_set_hint(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CHAR hintstring[MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    mmi_asc_to_ucs2(hintstring, (CHAR*)g_syncml_account.server_address);
    
    cui_menu_set_item_hint(
        evt->sender_id, 
        MENU_ID_SYNCML_ACCOUNT_EDIT_SERVER_SETTINGS, 
        (UI_string_type)hintstring);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_each_db_set_hint
 * DESCRIPTION
 *  hint function for each database in account
 * PARAMETERS
 *  hint_count       [IN]      The hint count
 *  hint_array       [OUT]     The hint pointer array to the strings
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_each_db_set_hint(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR hintstring[MAX_SYNCML_DATABASE_ADDR_LEN * ENCODING_LENGTH];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2(hintstring,(CHAR*) g_syncml_account.contact_address);
    cui_menu_set_item_hint(
        evt->sender_id, 
        MENU_ID_SYNCML_ACCOUNT_EDIT_DB_CONTACT, 
        (UI_string_type)hintstring);
    
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__       
    mmi_asc_to_ucs2(hintstring,(CHAR*) g_syncml_account.calendar_address);
    cui_menu_set_item_hint(
        evt->sender_id, 
        MENU_ID_SYNCML_ACCOUNT_EDIT_DB_CALENDAR, 
        (UI_string_type)hintstring);
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */   

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__       
    mmi_asc_to_ucs2(hintstring,(CHAR*) g_syncml_account.task_address);
    cui_menu_set_item_hint(
        evt->sender_id, 
        MENU_ID_SYNCML_ACCOUNT_EDIT_DB_TASK, 
        (UI_string_type)hintstring);
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */   

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__       
    mmi_asc_to_ucs2(hintstring,(CHAR*) g_syncml_account.note_address);
    cui_menu_set_item_hint(
        evt->sender_id, 
        MENU_ID_SYNCML_ACCOUNT_EDIT_DB_NOTE, 
        (UI_string_type)hintstring);
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */  

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__          
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */   

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__                
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */    
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

#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_sync_type_set_hint
 * DESCRIPTION
 *  "connection type" menu hint handler
 * PARAMETERS
 *  index       [IN]        hint index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_sync_type_set_hint(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CHAR* hintsting[MAX_SUB_MENU_HINT_SIZE];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    switch (g_syncml_account.sync_type)
    {
        case MMI_SYNCML_TYPE_BACKUP:
            mmi_ucs2cpy(hintsting, (CHAR*) GetString(STR_ID_SYNC_BACKUP));
            break;

        case MMI_SYNCML_TYPE_RESTORE:
            mmi_ucs2cpy(hintsting, (CHAR*) GetString(STR_ID_SYNC_RESTORE));
            break;

        case MMI_SYNCML_TYPE_EXPORT:
            mmi_ucs2cpy(hintsting, (CHAR*) GetString(STR_ID_SYNC_EXPORT));
            break;

        case MMI_SYNCML_TYPE_IMPORT:
            mmi_ucs2cpy(hintsting, (CHAR*) GetString(STR_ID_SYNC_IMPORT));
            break;

        case MMI_SYNCML_TYPE_DEFAULT:
        default:
            mmi_ucs2cpy(hintsting, (CHAR*) GetString(STR_ID_SYNC_TWOWAY));
            break;
    } 

    cui_menu_set_item_hint(
        evt->sender_id, 
        MENU_ID_SYNCML_ACCOUNT_EDIT_SYNC_TYPE, 
        (UI_string_type)hintsting);
}
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_regular_sync_set_hint
 * DESCRIPTION
 *  "connection type" menu hint handler
 * PARAMETERS
 *  index       [IN]        hint index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_regular_sync_set_hint(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CHAR hintstring[MAX_SUB_MENU_HINT_SIZE];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    switch (g_syncml_account.regular_sync)
	{
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
    	case MMI_SYNCML_REGULAR_SYNC_DATA_CHANGED:
    		mmi_ucs2cpy(hintstring, (CHAR*) GetString(STR_ID_SYNC_REGULARITY_DATA));
    		break;
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */  		
    	case MMI_SYNCML_REGULAR_SYNC_POWER_ON:
    		mmi_ucs2cpy(hintstring, (CHAR*) GetString(STR_ID_SYNC_REGULARITY_POWERON));
    		break;
    		
    	case MMI_SYNCML_REGULAR_SYNC_EVERY_DAY:
    		mmi_ucs2cpy(hintstring, (CHAR*) GetString(STR_ID_SYNC_REGULARITY_DAY));
    		break;
    		
    	case MMI_SYNCML_REGULAR_SYNC_EVERY_WEEK:
    		mmi_ucs2cpy(hintstring, (CHAR*) GetString(STR_ID_SYNC_REGULARITY_WEEK));
    		break;
    		
    	case MMI_SYNCML_REGULAR_SYNC_EVERY_MONTH:
    		mmi_ucs2cpy(hintstring, (CHAR*) GetString(STR_ID_SYNC_REGULARITY_MONTH));
    		break;
    		
    	case MMI_SYNCML_REGULAR_SYNC_NONE:
            
    	default:
    		mmi_ucs2cpy(hintstring, (CHAR*) GetString(STR_ID_SYNC_REGULARITY_NONE));
    		break;
	}
                
    cui_menu_set_item_hint(
        evt->sender_id, 
        MENU_ID_SYNCML_ACCOUNT_EDIT_REGULAR_SYNC, 
        (UI_string_type)hintstring);
}


#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
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
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_sync_report_set_hint
 * DESCRIPTION
 *  "sas" menu hint handler
 * PARAMETERS
 *  index       [IN]        hint index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_sync_report_set_hint(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CHAR hintstring[MAX_SUB_MENU_HINT_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (g_syncml_account.sync_report_status)
    { 
        mmi_ucs2cpy(hintstring, (CHAR*) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy(hintstring, (CHAR*) GetString(STR_GLOBAL_OFF));
    }
    
    cui_menu_set_item_hint(
        evt->sender_id, 
        MENU_ID_SYNCML_ACCOUNT_EDIT_REPORT, 
        (UI_string_type)hintstring);
}


#define account_list
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_list_entry_evt_hdlr
 * DESCRIPTION
 *  entry event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_list_entry_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id list_of_ids[MMI_MAX_SYNCML_ACCOUNTS];
    mmi_menu_id i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(STR_ID_SYNC_PROFILE),
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_MAIN))
#endif
        );
    
    cui_menu_set_currlist_left_softkey(
        evt->sender_id, 
        (WCHAR*)get_string(STR_GLOBAL_OPTIONS));
    
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {
        list_of_ids[i] = i;
    }

    cui_menu_set_currlist(evt->sender_id, MMI_MAX_SYNCML_ACCOUNTS, list_of_ids);
 
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            list_of_ids[i], 
            (WCHAR*)g_mmi_syncml_cntx.account_name_display[i]);   
    }

#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
#endif    

	cui_menu_enable_center_softkey(evt->sender_id, 0, IMG_GLOBAL_OPTION_CSK);

    /* always highlight the first account when first enter account list screen */
    cui_menu_set_currlist_highlighted_id(evt->sender_id, list_of_ids[0]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_list_hilite_evt_hdlr
 * DESCRIPTION
 *  highlight event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_list_hilite_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    g_mmi_syncml_cntx.selected_account = (U8)(evt->highlighted_menu_id);
}


#define account_option
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_option
 * DESCRIPTION
 *  entry event handler, it also is used for CMCC
 * PARAMETERS
 *  menu_id 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_account_option(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        parent_id,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_FROM_RESOURCE,
                        MENU_ID_SYNCML_ACCOUNT_OPTION,
                        MMI_FALSE,
                        NULL);
    
    cui_menu_set_default_title(
        menu_cui_gid, 
        (WCHAR*)get_string(STR_GLOBAL_OPTIONS), 
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_MAIN))
#endif
        );
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_SYNCML_SETTING__ */  
 
    cui_menu_run(menu_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_option_entry_evt_hdlr
 * DESCRIPTION
 *  Specified account entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_option_entry_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* tell menu cui, EDIT menu is leaf in this option menu cui */
    cui_menu_set_non_leaf_item(evt->sender_id, MENU_ID_SYNCML_ACCOUNT_EDIT, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_sync
 * DESCRIPTION
 *  Specified account entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_account_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_group_entry_sync_pre_check(GRP_ID_SYNC_MAIN, MMI_TRUE); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_group_account_edit_proc
 * DESCRIPTION
 *  launch the account editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_syncml_group_account_edit_proc(mmi_event_struct *param)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        /* full editor cui event hdlr */
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            cui_fseditor_evt_struct *evt = (cui_fseditor_evt_struct*) param;
            mmi_syncml_edit_account_name_save(evt);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            cui_fseditor_evt_struct *evt = (cui_fseditor_evt_struct*) param;
            cui_fseditor_close(evt->sender_id);
            break;
        }

        /* menu cui event hdlr */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_syncml_menu_cui_entry_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
        {           
            mmi_syncml_menu_cui_exit_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct *evt = (cui_menu_event_struct*)param;
            if (MENU_ID_SYNCML_ACCOUNT_EDIT_TRANSPORT_TYPE == evt->parent_menu_id)
            {
                mmi_syncml_account_trans_type_edit_save(evt);
            }
            else if (MENU_ID_SYNCML_ACCOUNT_EDIT_APP_TO_SYNC == evt->parent_menu_id)
            {
                mmi_syncml_account_app_to_sync_edit_confirm();
            }
            else if (MENU_ID_SYNCML_ACCOUNT_EDIT_REGULAR_SYNC == evt->parent_menu_id)
            {
                mmi_syncml_account_regular_sync_edit_save(evt);
            }
            else if (MENU_ID_SYNCML_ACCOUNT_EDIT_REPORT == evt->parent_menu_id)
            {
                mmi_syncml_account_report_edit_save(evt);
            }
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
            else if (MENU_ID_SYNCML_ACCOUNT_EDIT_SYNT_TYPE == evt->parent_menu_id)
            {
                mmi_syncml_account_sync_type_edit_save(evt);
            }
#endif	
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            else
            {
            }
			break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            mmi_syncml_menu_cui_close_notify_evt_hdlr(param);
            break;
        }

        /* inline cui event hdlr */
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_submit_struct *evt = (cui_event_inline_submit_struct*)param;
            if (evt->item_id >= MMI_SYNCML_INLINE_SVR_ADDR_CAP && evt->item_id < MMI_SYNCML_INLINE_SVR_ITEM_TOTAL)
            {
                mmi_syncml_edit_account_server_setting_done();
            }
            else if (evt->item_id >= MMI_SYNCML_INLINE_CON_ADDR_CAP && evt->item_id <= MMI_SYNCML_INLINE_CON_PSW)
            {
                mmi_syncml_edit_account_db_contact_done();
            }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
            else if (evt->item_id >= MMI_SYNCML_INLINE_CAL_ADDR_CAP && evt->item_id <= MMI_SYNCML_INLINE_CAL_PSW)
            {
                mmi_syncml_edit_account_db_calendar_done();
            }
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
            else if (evt->item_id >= MMI_SYNCML_INLINE_TASK_ADDR_CAP && evt->item_id <= MMI_SYNCML_INLINE_TASK_PSW)
            {
                mmi_syncml_edit_account_db_task_done();
            }
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
            else if (evt->item_id >= MMI_SYNCML_INLINE_NOTE_ADDR_CAP && evt->item_id <= MMI_SYNCML_INLINE_NOTE_PSW)
            {
                mmi_syncml_edit_account_db_note_done();
            }
#endif
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            else
            {
            }
            
            break;
        }
        case EVT_ID_CUI_INLINE_ABORT:
        {
			cui_event_inline_abort_struct *evt = (cui_event_inline_abort_struct*)param;
            cui_inline_close(evt->sender_id);
            break;
        }

        /* data account select account CUI */
		case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
		{
			cui_dtcnt_select_event_any_sim_selected_struct *dsSelectResult =
				(cui_dtcnt_select_event_any_sim_selected_struct*)param;

			switch(dsSelectResult->selectSim)
        {
			
				case CUI_DTCNT_SIM1:

					mmi_syncml_select_data_account_save(dsSelectResult->accountId,CUI_DTCNT_SIM1);
					break;
				case CUI_DTCNT_SIM2:

					mmi_syncml_select_data_account_save(dsSelectResult->accountId,CUI_DTCNT_SIM2);
					break;
				case CUI_DTCNT_SIM3:

					mmi_syncml_select_data_account_save(dsSelectResult->accountId,CUI_DTCNT_SIM3);
					break;
				case CUI_DTCNT_SIM4:

					mmi_syncml_select_data_account_save(dsSelectResult->accountId,CUI_DTCNT_SIM4);
					break;
				default:
            break;
        }
			
		}
		
        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
        {
            cui_dtcnt_select_event_struct *evt = (cui_dtcnt_select_event_struct*)param;
            cui_dtcnt_select_close(evt->sender_id);
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_edit
 * DESCRIPTION
 *  the account editor group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_account_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
    #ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
    #else
                        GRP_ID_SYNC_MAIN,
    #endif                    
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_FROM_RESOURCE,
                        MENU_ID_SYNCML_ACCOUNT_EDIT,
                        MMI_FALSE,
                        NULL);
        
    cui_menu_run(menu_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_edit_entry_evt_hdlr
 * DESCRIPTION
 *  entry event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_edit_entry_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    /* clear all data for every time edition */  
    memset(&g_syncml_account, 0, sizeof(mmi_syncml_account_struct));
    memset(&g_syncml_account_edit, 0, sizeof(mmi_syncml_account_edit_struct));
    
    mmi_syncml_read_account_from_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void*)&g_syncml_account);

    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(STR_ID_SYNC_ACCOUNT_EDIT), 
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_MAIN))
#endif
        );


#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if (g_syncml_account.transport_type == MMI_SYNCML_TRANS_TYPE_BT)
    {
        cui_menu_set_item_hidden(
            evt->sender_id, 
            MENU_ID_SYNCML_ACCOUNT_EDIT_CONN_SETTINGS, 
            MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(
            evt->sender_id, 
            MENU_ID_SYNCML_ACCOUNT_EDIT_CONN_SETTINGS, 
            MMI_FALSE);
    }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */  

#ifdef __MMI_OP01_SYNCML_SETTING__
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
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __MMI_OP01_SYNCML_SETTING__ */  

	if(!srv_sim_ctrl_any_sim_is_available())
	{
		cui_menu_set_item_hidden(
			evt->sender_id, 
			MENU_ID_SYNCML_ACCOUNT_EDIT_CONN_SETTINGS, 
			MMI_TRUE);

	}

    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    mmi_syncml_account_name_set_hint(evt);
    mmi_syncml_account_transport_type_set_hint(evt);
    mmi_syncml_account_server_settings_set_hint(evt);
    //mmi_syncml_account_dtcnt_set_hint(evt);
    mmi_syncml_account_regular_sync_set_hint(evt);
    mmi_syncml_account_sync_report_set_hint(evt);
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    mmi_syncml_account_sync_type_set_hint(evt);
#endif
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#endif
}

#define Edit_account_name
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_name
 * DESCRIPTION
 *  "Account Name" menu select event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_account_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 fseditor_gid;
    U16 title_icon;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    /* read-only account'name is uneditable */
    if (g_syncml_account.read_only == 1)
    {   
        return;
    }
    else
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    {
        fseditor_gid = cui_fseditor_create(GRP_ID_SYNC_EDIT);
    
        if (fseditor_gid != GRP_ID_INVALID)
        {
    
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
            title_icon = GetRootTitleIcon(MENU_ID_SYNCML_MAIN);
#endif 
            cui_fseditor_set_title(fseditor_gid, STR_ID_SYNC_PROFILE_NAME, title_icon);
            
            mmi_ucs2ncpy(
                (CHAR*) g_syncml_account_edit.temp_addr_buffer,
                (CHAR*) g_syncml_account.account_name,
                MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH);
            
            cui_fseditor_set_buffer(
                fseditor_gid, 
                g_syncml_account_edit.temp_addr_buffer, 
                MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH,
                MAX_SYNCML_PROFILE_NAME - 1);
            
            cui_fseditor_set_input_method(
                fseditor_gid, 
                IMM_INPUT_TYPE_SENTENCE, 
                NULL,
                0);       
            
            cui_fseditor_run(fseditor_gid);
        }
    }
}
   

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_edit_name_save
 * DESCRIPTION
 *  "Profile Name" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_edit_account_name_save(cui_fseditor_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U8 account_index = g_mmi_syncml_cntx.selected_account;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/               
	cui_fseditor_get_text(
        evt->sender_id, 
        (WCHAR *)g_syncml_account_edit.temp_addr_buffer, 
        MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH);

	if (mmi_ucs2strlen((CHAR*)g_syncml_account_edit.temp_addr_buffer) == 0)
	{
		mmi_popup_display_simple(
			(WCHAR*)get_string(STR_GLOBAL_EMPTY),
			MMI_EVENT_FAILURE,
			GRP_ID_ROOT,
			NULL);
		return;
	}
	
    mmi_popup_display_simple(
	    (WCHAR*)get_string(STR_GLOBAL_SAVED), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_ROOT, 
		NULL); 

    mmi_ucs2cpy((CHAR*) g_syncml_account.account_name, (CHAR*) g_syncml_account_edit.temp_addr_buffer);
    
    g_syncml_account.account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_NAME;
    g_mmi_syncml_cntx.account_validation[account_index] = g_syncml_account.account_validation;
    
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__    
    /* If the name was changed, the hash buffer must be cleared. */  
    if (mmi_ucs2cmp((CHAR*)g_syncml_account.account_name, (CHAR*)g_mmi_syncml_cntx.account_name_display[account_index]) != 0)
    {
        memset(g_syncml_account.prov_url_hash, 0, MAX_SYNCML_HASH_BUF_LEN * sizeof(U8)); 
        memset(g_syncml_account.proxy_id_hash, 0, MAX_SYNCML_HASH_BUF_LEN * sizeof(U8)); 
    }
    g_syncml_account.type = MMI_SYNCML_ACCOUNT_TYPE_USR_DEFINED;
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    mmi_syncml_write_account_to_nvram((U8)(account_index + 1), (void*)&g_syncml_account);

    /* update account name to default name*/
    if (mmi_ucs2strlen((CHAR*)g_syncml_account.account_name) == 0)
    {
        /* update display name */
        mmi_ucs2cpy((CHAR*)g_mmi_syncml_cntx.account_name_display[account_index], 
            GetString((U16) (STR_ID_SYNC_PROFILE_ID1 + account_index)));
        /* update hint */
        mmi_ucs2cpy((CHAR*)g_syncml_account.account_name, 
            GetString((U16) (STR_ID_SYNC_PROFILE_ID1 + account_index)));
    }
    else
    {
        mmi_ucs2cpy((CHAR*)g_mmi_syncml_cntx.account_name_display[account_index], 
            (CHAR*)g_syncml_account.account_name);
    }
#if defined(__MMI_NCENTER_SUPPORT__)	
	mmi_syncml_ncenter_sync_unfinish_update(g_mmi_syncml_cntx.selected_account + 1);
#endif
	cui_fseditor_close(evt->sender_id);
}


#define Edit_account_transport_type
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_trans_type
 * DESCRIPTION
 *  transport type menu select event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_account_trans_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    /* read-only account'conn_type is uneditable */
    if (g_syncml_account.read_only == 1)
    {
        return;
    }
    else
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    {        
        menu_cui_gid = cui_menu_create(
                            GRP_ID_SYNC_EDIT,
                            CUI_MENU_SRC_TYPE_APPCREATE,
                            CUI_MENU_TYPE_APPSUB,
                            MENU_ID_SYNCML_ACCOUNT_EDIT_TRANSPORT_TYPE,
                            MMI_FALSE,
                            NULL);
        
        cui_menu_run(menu_cui_gid);  
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_trans_type_entry_evt_hdlr
 * DESCRIPTION
 *  entry event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_trans_type_entry_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id list_of_ids[MMI_SYNCML_TRANS_TYPE_TOTAL];
    mmi_menu_id i;
    const U16 list_of_str[2]
         = {STR_ID_SYNC_CONN_INTERNET, STR_ID_SYNC_CONN_BT};
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < MMI_SYNCML_TRANS_TYPE_TOTAL; i++)
    {
        list_of_ids[i] = MMI_SYNCML_TRANS_TYPE_INTERNET + i;
    }

    cui_menu_set_currlist(
        evt->sender_id,
        MMI_SYNCML_TRANS_TYPE_TOTAL,
        list_of_ids);
    
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(STR_ID_SYNC_PROFILE_CONNECTION_TYPE), 
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_MAIN))
#endif
        );
    
    for(i = 0; i < MMI_SYNCML_TRANS_TYPE_TOTAL; i++)
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            (mmi_menu_id)(MMI_SYNCML_TRANS_TYPE_INTERNET + i), 
            (WCHAR*)get_string(list_of_str[i]));
    }

    cui_menu_set_currlist_left_softkey(
        evt->sender_id, 
        (WCHAR*)get_string(STR_GLOBAL_OK));

    cui_menu_set_currlist_highlighted_id(
        evt->sender_id, 
        (mmi_menu_id)(g_syncml_account.transport_type + MMI_SYNCML_TRANS_TYPE_INTERNET));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_account_transport_type_save
 * DESCRIPTION
 *  Save the transport type to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_trans_type_edit_save(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_popup_display_simple(
		(WCHAR*)get_string(STR_GLOBAL_SAVED), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_ROOT, 
		NULL); 
   
    g_syncml_account.transport_type = (U8)(evt->highlighted_menu_id - MMI_SYNCML_TRANS_TYPE_INTERNET);

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__

    g_mmi_syncml_cntx.transport_type[g_mmi_syncml_cntx.selected_account] = g_syncml_account.transport_type;

    if (g_syncml_account.transport_type == MMI_SYNCML_TRANS_TYPE_INTERNET)
    {
       if (applib_url_is_valid((const char *) &g_syncml_account.server_address) != 0)
       {
           g_syncml_account.account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_SVR;
           g_mmi_syncml_cntx.account_validation[g_mmi_syncml_cntx.selected_account] = g_syncml_account.account_validation;
       }   
    }
    else
    {
       if (g_syncml_account.server_address != 0)
       {
           g_syncml_account.account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_SVR;
           g_mmi_syncml_cntx.account_validation[g_mmi_syncml_cntx.selected_account] = g_syncml_account.account_validation;
       }
       
    }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

    mmi_syncml_write_account_to_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void*)&g_syncml_account);

    cui_menu_close(evt->sender_id);
}


#define Edit_account_app_to_sync
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_app_to_sync
 * DESCRIPTION
 *  "app to sync" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_account_app_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        GRP_ID_SYNC_EDIT,
                        CUI_MENU_SRC_TYPE_APPCREATE,
                        CUI_MENU_TYPE_APPSUB,
                        MENU_ID_SYNCML_ACCOUNT_EDIT_APP_TO_SYNC,
                        MMI_FALSE,
                        NULL);
    
    cui_menu_run(menu_cui_gid);

    g_mmi_syncml_cntx.temp_gid = menu_cui_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_app_to_sync_entry_evt_hdlr
 * DESCRIPTION
 *  entry event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_app_to_sync_entry_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id list_of_ids[MMI_SYNCML_SYNC_APP_TOTAL];
    mmi_menu_id i;
    U8 list_of_state[MMI_SYNCML_SYNC_APP_TOTAL];
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < MMI_SYNCML_SYNC_APP_TOTAL; i++) 
    {
        list_of_ids[i] = MMI_SYNCML_SYNC_APP_PHB + i ;
    }
    
    cui_menu_set_currlist(
        evt->sender_id, 
        MMI_SYNCML_SYNC_APP_TOTAL, 
        list_of_ids);
    
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_CHECK_BOX_LIST);

    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(STR_ID_SYNC_APPLICATIONS), 
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_MAIN))
#endif
        );

    for(i = 0; i < MMI_SYNCML_SYNC_APP_TOTAL; i++)
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            (mmi_menu_id)(MMI_SYNCML_SYNC_APP_PHB + i), 
            (WCHAR*)get_string((U16)(STR_ID_SYNC_APP_PHB + i)));
    }

    if (g_syncml_account.app_to_sync & SYNCML_DB_PHONEBOOK)
    {
        list_of_state[MMI_SYNCML_SYNC_APP_PHB] = 1;
    }
    else
    {
        list_of_state[MMI_SYNCML_SYNC_APP_PHB] = 0;
    }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    if (g_syncml_account.app_to_sync & SYNCML_DB_CALENDAR)
    {
        list_of_state[MMI_SYNCML_SYNC_APP_CAL] = 1;
    }
    else
    {
        list_of_state[MMI_SYNCML_SYNC_APP_CAL] = 0;
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    if (g_syncml_account.app_to_sync & SYNCML_DB_TASK)
    {
        list_of_state[MMI_SYNCML_SYNC_APP_TASK] = 1;
    }
    else
    {
        list_of_state[MMI_SYNCML_SYNC_APP_TASK] = 0;
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (g_syncml_account.app_to_sync & SYNCML_DB_NOTE)
    {
        list_of_state[MMI_SYNCML_SYNC_APP_NOTE] = 1;
    }
    else
    {
        list_of_state[MMI_SYNCML_SYNC_APP_NOTE] = 0;
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    cui_menu_set_checkbox_state(evt->sender_id, list_of_state);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_app_to_sync_exit_evt_hdlr
 * DESCRIPTION
 *  exit event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_app_to_sync_exit_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    cui_menu_get_checkbox_state(evt->sender_id, g_syncml_account_edit.selected_applications);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_app_to_sync_edit_confirm
 * DESCRIPTION
 *  Confirmation of the application to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_app_to_sync_edit_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
	/*----------------------------------------------------------------*/
    mmi_syncml_confirm_display_with_proc(
        GRP_ID_ROOT, 
        (WCHAR*)get_string(STR_GLOBAL_SAVE_ASK), 
        CNFM_TYPE_YESNO, 
        mmi_syncml_account_app_to_sync_edit_save, 
        mmi_syncml_account_app_to_sync_edit_cancel, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_app_to_sync_edit_save
 * DESCRIPTION
 *  save operation of the application to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_app_to_sync_edit_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_popup_display_simple(
	    (WCHAR*)get_string(STR_GLOBAL_SAVED), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_ROOT, 
		NULL); 
    
    g_syncml_account.app_to_sync = 0;

    if (g_syncml_account_edit.selected_applications[MMI_SYNCML_SYNC_APP_PHB])
    {
        g_syncml_account.app_to_sync |= SYNCML_DB_PHONEBOOK;
    }

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    if (g_syncml_account_edit.selected_applications[MMI_SYNCML_SYNC_APP_CAL])
    {
        g_syncml_account.app_to_sync |= SYNCML_DB_CALENDAR;
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    if (g_syncml_account_edit.selected_applications[MMI_SYNCML_SYNC_APP_TASK])
    {
        g_syncml_account.app_to_sync |= SYNCML_DB_TASK;
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (g_syncml_account_edit.selected_applications[MMI_SYNCML_SYNC_APP_NOTE])
    {
        g_syncml_account.app_to_sync |= SYNCML_DB_NOTE;
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.selected_account] = g_syncml_account.app_to_sync;

    mmi_syncml_write_account_to_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void*)&g_syncml_account);

    cui_menu_close(g_mmi_syncml_cntx.temp_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_app_to_sync_edit_cancel
 * DESCRIPTION
 *  save operation of the application to sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_app_to_sync_edit_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_close(g_mmi_syncml_cntx.temp_gid);
    mmi_frm_scrn_close_active_id();
}


#define Edit_account_server_seting
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_inline_screen_edit_save_abort
 * DESCRIPTION
 *  Generic abortion of profile settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_inline_screen_edit_save_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(g_mmi_syncml_cntx.temp_gid);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_server
 * DESCRIPTION
 *  "Server Settings" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_account_server_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    U16 icon_id;
    U16 i = 0;
    
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
    icon_id = GetRootTitleIcon(MENU_ID_SYNCML_MAIN);
#endif
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_addr_buffer,
        (CHAR*) g_syncml_account.server_address,
        MAX_SYNCML_SERVER_ADDR_LEN);
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_name_buffer,
        (CHAR*) g_syncml_account.server_username,
        MAX_SYNCML_USERNAME);
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_pswd_buffer,
        (CHAR*) g_syncml_account.server_password,
        MAX_SYNCML_PASSWORD);
        
    inline_id = cui_inline_create(GRP_ID_SYNC_EDIT, &server_setting_screen); 

    /* set inline editor title icon */
    cui_inline_set_title_icon(inline_id, icon_id);

    /* set fseditor in inline editor title icon */
    for (i = MMI_SYNCML_INLINE_SVR_ADDR; i < MMI_SYNCML_INLINE_SVR_ITEM_TOTAL; i = i + 2)
    {
        cui_inline_set_fullscreen_edit_title_icon(inline_id, i, icon_id);
    }

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (g_syncml_account.read_only == 1)
    {
        cui_inline_set_item_struct new_item;
        new_item.item_id = MMI_SYNCML_INLINE_SVR_ADDR;
        new_item.item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY;
        new_item.image_id = 0;
        new_item.item_data = NULL;
        
        cui_inline_delete_item(inline_id, MMI_SYNCML_INLINE_SVR_ADDR);
        cui_inline_insert_item(inline_id, MMI_SYNCML_INLINE_SVR_UN_CAP, &new_item);
    }
#endif

    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_SVR_ADDR, (void*)g_syncml_account_edit.temp_addr_buffer);
    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_SVR_UN, (void*)g_syncml_account_edit.temp_name_buffer);
    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_SVR_PSW, (void*)g_syncml_account_edit.temp_pswd_buffer);

    cui_inline_run(inline_id);

    g_mmi_syncml_cntx.temp_gid = inline_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_profile_server_done
 * DESCRIPTION
 *  "Server Settings" menu finish function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_edit_account_server_setting_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_syncml_confirm_display_with_proc(
        GRP_ID_ROOT, 
        (WCHAR*)get_string(STR_GLOBAL_SAVE_ASK), 
        CNFM_TYPE_YESNO, 
        mmi_syncml_edit_account_server_setting_save, 
        mmi_syncml_inline_screen_edit_save_abort, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_account_server_save
 * DESCRIPTION
 *  "Server Settings" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_edit_account_server_setting_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_server[MAX_SYNCML_SERVER_ADDR_LEN];
    U8 *fs_path;
    U8 account_index = g_mmi_syncml_cntx.selected_account;
    mmi_id inline_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    inline_id = g_mmi_syncml_cntx.temp_gid;
    
    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_SVR_ADDR, (void *)g_syncml_account_edit.temp_addr_buffer);
    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_SVR_UN, (void *)g_syncml_account_edit.temp_name_buffer);
    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_SVR_PSW, (void *)g_syncml_account_edit.temp_pswd_buffer);

    mmi_ucs2_to_asc((CHAR*) temp_server, (CHAR*) g_syncml_account_edit.temp_addr_buffer);
    
    if (g_syncml_account.transport_type == MMI_SYNCML_TRANS_TYPE_INTERNET)
    {  
        if (applib_url_is_valid((const char *) temp_server) != 0)
        {
			mmi_popup_display_simple(
				(WCHAR*)get_string(STR_ID_SYNC_INVALID_SERVER_INPUT), 
				MMI_EVENT_FAILURE, 
				GRP_ID_ROOT, 
				NULL); 
            return;
        }
    }   
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    else
    {
        if (temp_server[0] == 0 || temp_server[0] == ' ')
        {
			mmi_popup_display_simple(
				(WCHAR*)get_string(STR_ID_SYNC_INVALID_SERVER_INPUT), 
				MMI_EVENT_FAILURE, 
				GRP_ID_ROOT, 
				NULL); 
            return; 
        }
    }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

	mmi_popup_display_simple(
		(WCHAR*)get_string(STR_GLOBAL_SAVED), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_ROOT, 
		NULL); 

    /* last anchor and change log should be reset if the server is changed */
    if (strcmp((CHAR*) g_syncml_account.server_address, (CHAR*) temp_server) != 0)
    {    
        g_mmi_syncml_cntx.last_phb_anchor[account_index] = g_syncml_account.last_phb_anchor = 0;
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        g_mmi_syncml_cntx.last_cal_anchor[account_index] = g_syncml_account.last_cal_anchor = 0;
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        g_mmi_syncml_cntx.last_task_anchor[account_index] = g_syncml_account.last_task_anchor = 0;
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        g_mmi_syncml_cntx.last_note_anchor[account_index] = g_syncml_account.last_note_anchor = 0;
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif 
        /* phb path + 1 is the longest */
        fs_path = OslMalloc(sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PATH)); 
        
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_PHB_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + account_index + 1;
        FS_Delete((U16*) fs_path);
             
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_CAL_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_CAL_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + account_index + 1;
        FS_Delete((U16*) fs_path);       
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
        
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__       
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_TASK_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_TASK_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + account_index + 1;
        FS_Delete((U16*) fs_path);       
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__       
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_NOTE_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_NOTE_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + account_index + 1;
        FS_Delete((U16*) fs_path);       
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */   

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

        OslMfree(fs_path);
    }
    
    memset(g_syncml_account.server_address, 0, MAX_SYNCML_SERVER_ADDR_LEN);
    memset(g_syncml_account.server_username, 0, MAX_SYNCML_USERNAME);
    memset(g_syncml_account.server_password, 0, MAX_SYNCML_PASSWORD);
    
    /* save to nvram */
    if (g_syncml_account.transport_type == MMI_SYNCML_TRANS_TYPE_INTERNET)
    {
        if (mmi_ucs2strlen((CHAR*) g_syncml_account_edit.temp_addr_buffer) == 0
            ||  mmi_ucs2cmp((CHAR*) g_syncml_account_edit.temp_addr_buffer, (CHAR*) L"http://") == 0)
        {
            strcpy((CHAR*) g_syncml_account.server_address, "http://");
            g_syncml_account.account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_SVR;        
        }
        else
        {            
            mmi_ucs2_to_asc((CHAR*) g_syncml_account.server_address, (CHAR*) g_syncml_account_edit.temp_addr_buffer);
            g_syncml_account.account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_SVR;
        }      
    }
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    else 
    {      
        /* only invalid server addr, can entry here */
        g_syncml_account.account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_SVR;
        mmi_ucs2_to_asc((CHAR*) g_syncml_account.server_address, (CHAR*) g_syncml_account_edit.temp_addr_buffer);
    }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
        
    mmi_ucs2_to_asc((CHAR*) g_syncml_account.server_username, (CHAR*) g_syncml_account_edit.temp_name_buffer);
    mmi_ucs2_to_asc((CHAR*) g_syncml_account.server_password, (CHAR*) g_syncml_account_edit.temp_pswd_buffer);

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    g_syncml_account.type = MMI_SYNCML_ACCOUNT_TYPE_USR_DEFINED;
#endif
    
    g_mmi_syncml_cntx.account_validation[g_mmi_syncml_cntx.selected_account] = g_syncml_account.account_validation;

    mmi_syncml_write_account_to_nvram((U8)(account_index + 1), (void*)&g_syncml_account);

#if defined(__MMI_NCENTER_SUPPORT__)	
	if(mmi_syncml_necnter_is_unfinish_account(g_mmi_syncml_cntx.selected_account + 1))
	{
		mmi_syncml_ncenter_sync_unfinish_destroy(MMI_SYNCML_NOTIFICATION_SYNC_REMOTE);
	}
#endif

    cui_inline_close(inline_id);
}


#define Edit_app_setting
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_db_settings_entry_evt_hdlr
 * DESCRIPTION
 *  entry event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_db_settings_entry_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(STR_ID_SYNC_DATABASE_SETTING), 
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_MAIN))
#endif
        );

    mmi_syncml_account_each_db_set_hint(evt);
}


#define Edit_app_setting_contact
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_db_contact
 * DESCRIPTION
 *  "Contact Settings" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_account_db_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    U16 i = 0;
    U16 icon_id;
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
    icon_id = GetRootTitleIcon(MENU_ID_SYNCML_MAIN);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_addr_buffer,
        (CHAR*) g_syncml_account.contact_address,
        MAX_SYNCML_DATABASE_ADDR_LEN);
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_name_buffer,
        (CHAR*) g_syncml_account.contact_username,
        MAX_SYNCML_USERNAME);
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_pswd_buffer,
        (CHAR*) g_syncml_account.contact_password,
        MAX_SYNCML_PASSWORD);
        
    inline_id = cui_inline_create(GRP_ID_SYNC_EDIT, &con_setting_screen); 
        
    /* set inline editor title icon */
    cui_inline_set_title_icon(inline_id, icon_id);
    
    /* set fseditor in inline editor title icon */
    for (i = MMI_SYNCML_INLINE_CON_ADDR; i <= MMI_SYNCML_INLINE_CON_PSW; i = i + 2)
    {
        cui_inline_set_fullscreen_edit_title_icon(inline_id, i, icon_id);
    }

    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_CON_ADDR, (void*)g_syncml_account_edit.temp_addr_buffer);
    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_CON_UN, (void*)g_syncml_account_edit.temp_name_buffer);
    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_CON_PSW, (void*)g_syncml_account_edit.temp_pswd_buffer);

    cui_inline_run(inline_id);
    
    g_mmi_syncml_cntx.temp_gid = inline_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_profile_calendar_done
 * DESCRIPTION
 *  "Calendar Settings" menu finish function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_edit_account_db_contact_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_confirm_display_with_proc(
        GRP_ID_ROOT, 
        (WCHAR*)get_string(STR_GLOBAL_SAVE_ASK), 
        CNFM_TYPE_YESNO, 
        mmi_syncml_edit_account_db_contact_save, 
        mmi_syncml_inline_screen_edit_save_abort, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_account_db_contact_save
 * DESCRIPTION
 *  "Contact Settings" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_edit_account_db_contact_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_id = g_mmi_syncml_cntx.temp_gid;
    
 	mmi_popup_display_simple(
		(WCHAR*)get_string(STR_GLOBAL_SAVED), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_ROOT, 
		NULL);   

    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_CON_ADDR, (void *)g_syncml_account_edit.temp_addr_buffer);
    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_CON_UN, (void *)g_syncml_account_edit.temp_name_buffer);
    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_CON_PSW, (void *)g_syncml_account_edit.temp_pswd_buffer);

    memset(g_syncml_account.contact_address, 0, MAX_SYNCML_DATABASE_ADDR_LEN);
    memset(g_syncml_account.contact_username, 0, MAX_SYNCML_USERNAME);
    memset(g_syncml_account.contact_password, 0, MAX_SYNCML_PASSWORD);
    
    /* save to nvram */
    if (mmi_ucs2strlen((CHAR*) g_syncml_account_edit.temp_addr_buffer) == 0
        || mmi_ucs2cmp((CHAR*) g_syncml_account_edit.temp_addr_buffer, (CHAR*) L"./") == 0)
    {
        strcpy((CHAR*) g_syncml_account.contact_address, "./");
            
        g_syncml_account.account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_CON;           
    }
    else
    {
        mmi_ucs2_to_asc((CHAR*) g_syncml_account.contact_address, (CHAR*) g_syncml_account_edit.temp_addr_buffer);

        g_syncml_account.account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_CON;
    }
    mmi_ucs2_to_asc((CHAR*) g_syncml_account.contact_username, (CHAR*) g_syncml_account_edit.temp_name_buffer);
    mmi_ucs2_to_asc((CHAR*) g_syncml_account.contact_password, (CHAR*) g_syncml_account_edit.temp_pswd_buffer);

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    g_syncml_account.type = MMI_SYNCML_ACCOUNT_TYPE_USR_DEFINED;
#endif
    g_mmi_syncml_cntx.account_validation[g_mmi_syncml_cntx.selected_account] = g_syncml_account.account_validation;

    mmi_syncml_write_account_to_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void*)&g_syncml_account);

    cui_inline_close(inline_id);
}


#define Edit_app_setting_calendar
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_db_calendar
 * DESCRIPTION
 *  "Calendar Settings" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_account_db_calendar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    U16 i = 0;
    U16 icon_id;
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
    icon_id = GetRootTitleIcon(MENU_ID_SYNCML_MAIN);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_addr_buffer,
        (CHAR*) g_syncml_account.calendar_address,
        MAX_SYNCML_DATABASE_ADDR_LEN);
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_name_buffer,
        (CHAR*) g_syncml_account.calendar_username,
        MAX_SYNCML_USERNAME);
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_pswd_buffer,
        (CHAR*) g_syncml_account.calendar_password,
        MAX_SYNCML_PASSWORD);
        
    inline_id = cui_inline_create(GRP_ID_SYNC_EDIT, &cal_setting_screen); 
    
    /* set inline editor title icon */
    cui_inline_set_title_icon(inline_id, icon_id);
    
    /* set fseditor in inline editor title icon */
    for (i = MMI_SYNCML_INLINE_CAL_ADDR; i <= MMI_SYNCML_INLINE_CAL_PSW; i = i + 2)
    {
        cui_inline_set_fullscreen_edit_title_icon(inline_id, i, icon_id);
    }

    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_CAL_ADDR, (void*)g_syncml_account_edit.temp_addr_buffer);
    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_CAL_UN, (void*)g_syncml_account_edit.temp_name_buffer);
    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_CAL_PSW, (void*)g_syncml_account_edit.temp_pswd_buffer);

    cui_inline_run(inline_id);

    g_mmi_syncml_cntx.temp_gid = inline_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_account_db_calendar_done
 * DESCRIPTION
 *  "Calendar Settings" menu finish function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_edit_account_db_calendar_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_confirm_display_with_proc(
        GRP_ID_ROOT, 
        (WCHAR*)get_string(STR_GLOBAL_SAVE_ASK), 
        CNFM_TYPE_YESNO, 
        mmi_syncml_edit_account_db_calendar_save, 
        mmi_syncml_inline_screen_edit_save_abort, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_account_db_calendar_save
 * DESCRIPTION
 *  "Calendar Settings" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_edit_account_db_calendar_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_id = g_mmi_syncml_cntx.temp_gid;
    
	mmi_popup_display_simple(
		(WCHAR*)get_string(STR_GLOBAL_SAVED), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_ROOT, 
		NULL); 
    
    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_CAL_ADDR, (void *)g_syncml_account_edit.temp_addr_buffer);
    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_CAL_UN, (void *)g_syncml_account_edit.temp_name_buffer);
    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_CAL_PSW, (void *)g_syncml_account_edit.temp_pswd_buffer);

    memset(g_syncml_account.calendar_address, 0, MAX_SYNCML_DATABASE_ADDR_LEN);
	memset(g_syncml_account.calendar_username, 0, MAX_SYNCML_USERNAME);
	memset(g_syncml_account.calendar_password, 0, MAX_SYNCML_PASSWORD);
	
	/* save to nvram */
	if (mmi_ucs2strlen((CHAR*) g_syncml_account_edit.temp_addr_buffer) == 0
		||  mmi_ucs2cmp((CHAR*) g_syncml_account_edit.temp_addr_buffer, (CHAR*) L"./") == 0)
	{
		strcpy((CHAR*) g_syncml_account.calendar_address, "./");
		
		g_syncml_account.account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_CAL;           
	}
	else
	{
		mmi_ucs2_to_asc((CHAR*) g_syncml_account.calendar_address, (CHAR*) g_syncml_account_edit.temp_addr_buffer);
		
		g_syncml_account.account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_CAL;
	}
	mmi_ucs2_to_asc((CHAR*) g_syncml_account.calendar_username, (CHAR*) g_syncml_account_edit.temp_name_buffer);
	mmi_ucs2_to_asc((CHAR*) g_syncml_account.calendar_password, (CHAR*) g_syncml_account_edit.temp_pswd_buffer);
    
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	g_syncml_account.type = MMI_SYNCML_ACCOUNT_TYPE_USR_DEFINED;
#endif
	
    g_mmi_syncml_cntx.account_validation[g_mmi_syncml_cntx.selected_account] = g_syncml_account.account_validation;
    mmi_syncml_write_account_to_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void*)&g_syncml_account);

    cui_inline_close(inline_id);
}
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */


#define Edit_app_setting_task
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_db_task
 * DESCRIPTION
 *  "Task Settings" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_account_db_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    U16 i = 0;
    U16 icon_id;
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
    icon_id = GetRootTitleIcon(MENU_ID_SYNCML_MAIN);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_addr_buffer,
        (CHAR*) g_syncml_account.task_address,
        MAX_SYNCML_DATABASE_ADDR_LEN);
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_name_buffer,
        (CHAR*) g_syncml_account.task_username,
        MAX_SYNCML_USERNAME);
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_pswd_buffer,
        (CHAR*) g_syncml_account.task_password,
        MAX_SYNCML_PASSWORD);
        
    inline_id = cui_inline_create(GRP_ID_SYNC_EDIT, &task_setting_screen); 
        
    /* set inline editor title icon */
    cui_inline_set_title_icon(inline_id, icon_id);
    
    /* set fseditor in inline editor title icon */
    for (i = MMI_SYNCML_INLINE_TASK_ADDR; i <= MMI_SYNCML_INLINE_TASK_PSW; i = i + 2)
    {
        cui_inline_set_fullscreen_edit_title_icon(inline_id, i, icon_id);
    }

    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_TASK_ADDR, (void*)g_syncml_account_edit.temp_addr_buffer);
    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_TASK_UN, (void*)g_syncml_account_edit.temp_name_buffer);
    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_TASK_PSW, (void*)g_syncml_account_edit.temp_pswd_buffer);

    cui_inline_run(inline_id);
    
    g_mmi_syncml_cntx.temp_gid = inline_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_account_app_task_done
 * DESCRIPTION
 *  "Task Settings" menu finish function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_edit_account_db_task_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_confirm_display_with_proc(
        GRP_ID_ROOT, 
        (WCHAR*)get_string(STR_GLOBAL_SAVE_ASK), 
        CNFM_TYPE_YESNO, 
        mmi_syncml_edit_account_db_task_save, 
        mmi_syncml_inline_screen_edit_save_abort, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_account_app_calendar_save
 * DESCRIPTION
 *  "Calendar Settings" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_edit_account_db_task_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_id = g_mmi_syncml_cntx.temp_gid;
   
	mmi_popup_display_simple(
		(WCHAR*)get_string(STR_GLOBAL_SAVED), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_ROOT, 
		NULL);    

    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_TASK_ADDR, (void *)g_syncml_account_edit.temp_addr_buffer);
    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_TASK_UN, (void *)g_syncml_account_edit.temp_name_buffer);
    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_TASK_PSW, (void *)g_syncml_account_edit.temp_pswd_buffer);
	
	memset(g_syncml_account.task_address, 0, MAX_SYNCML_DATABASE_ADDR_LEN);
	memset(g_syncml_account.task_username, 0, MAX_SYNCML_USERNAME);
	memset(g_syncml_account.task_password, 0, MAX_SYNCML_PASSWORD);
	
	/* save to nvram */
	if (mmi_ucs2strlen((CHAR*) g_syncml_account_edit.temp_addr_buffer) == 0
		||  mmi_ucs2cmp((CHAR*) g_syncml_account_edit.temp_addr_buffer, (CHAR*) L"./") == 0)
	{
		strcpy((CHAR*) g_syncml_account.task_address, "./");
		
		g_syncml_account.account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_TASK;           
	}
	else
	{
		mmi_ucs2_to_asc((CHAR*) g_syncml_account.task_address, (CHAR*) g_syncml_account_edit.temp_addr_buffer);
		
		g_syncml_account.account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_TASK;
	}
	mmi_ucs2_to_asc((CHAR*) g_syncml_account.task_username, (CHAR*) g_syncml_account_edit.temp_name_buffer);
	mmi_ucs2_to_asc((CHAR*) g_syncml_account.task_password, (CHAR*) g_syncml_account_edit.temp_pswd_buffer);
    
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	g_syncml_account.type = MMI_SYNCML_ACCOUNT_TYPE_USR_DEFINED;
#endif
    g_mmi_syncml_cntx.account_validation[g_mmi_syncml_cntx.selected_account] = g_syncml_account.account_validation;
	mmi_syncml_write_account_to_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void*)&g_syncml_account);

    cui_inline_close(inline_id);
}
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */


#define Edit_app_setting_note
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_db_note
 * DESCRIPTION
 *  "Note Settings" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_account_db_note(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    U16 i = 0;
    U16 icon_id;
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
    icon_id = GetRootTitleIcon(MENU_ID_SYNCML_MAIN);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prepare default strings to display if this screen is first entered */
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_addr_buffer,
        (CHAR*) g_syncml_account.note_address,
        MAX_SYNCML_DATABASE_ADDR_LEN);
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_name_buffer,
        (CHAR*) g_syncml_account.note_username,
        MAX_SYNCML_USERNAME);
    mmi_asc_n_to_ucs2(
        (CHAR*) g_syncml_account_edit.temp_pswd_buffer,
        (CHAR*) g_syncml_account.note_password,
        MAX_SYNCML_PASSWORD);
        
    inline_id = cui_inline_create(GRP_ID_SYNC_EDIT, &note_setting_screen); 
    
    /* set inline editor title icon */
    cui_inline_set_title_icon(inline_id, icon_id);
    
    /* set fseditor in inline editor title icon */
    for (i = MMI_SYNCML_INLINE_NOTE_ADDR; i <= MMI_SYNCML_INLINE_NOTE_PSW; i = i + 2)
    {
        cui_inline_set_fullscreen_edit_title_icon(inline_id, i, icon_id);
    }

    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_NOTE_ADDR, (void*)g_syncml_account_edit.temp_addr_buffer);
    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_NOTE_UN, (void*)g_syncml_account_edit.temp_name_buffer);
    cui_inline_set_value(inline_id, MMI_SYNCML_INLINE_NOTE_PSW, (void*)g_syncml_account_edit.temp_pswd_buffer);

    cui_inline_run(inline_id);
    
    g_mmi_syncml_cntx.temp_gid = inline_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_account_app_note_done
 * DESCRIPTION
 *  "Note Settings" menu finish function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_edit_account_db_note_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_confirm_display_with_proc(
        GRP_ID_ROOT, 
        (WCHAR*)get_string(STR_GLOBAL_SAVE_ASK), 
        CNFM_TYPE_YESNO, 
        mmi_syncml_edit_account_db_note_save, 
        mmi_syncml_inline_screen_edit_save_abort, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_account_app_note_save
 * DESCRIPTION
 *  "Note Settings" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_edit_account_db_note_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_id = g_mmi_syncml_cntx.temp_gid;
       
	mmi_popup_display_simple(
		(WCHAR*)get_string(STR_GLOBAL_SAVED), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_ROOT, 
		NULL); 

    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_NOTE_ADDR, (void *)g_syncml_account_edit.temp_addr_buffer);
    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_NOTE_UN, (void *)g_syncml_account_edit.temp_name_buffer);
    cui_inline_get_value(inline_id, MMI_SYNCML_INLINE_NOTE_PSW, (void *)g_syncml_account_edit.temp_pswd_buffer);
	
	memset(g_syncml_account.note_address, 0, MAX_SYNCML_DATABASE_ADDR_LEN);
	memset(g_syncml_account.note_username, 0, MAX_SYNCML_USERNAME);
	memset(g_syncml_account.note_password, 0, MAX_SYNCML_PASSWORD);
	
	/* save to nvram */
	if ((g_syncml_account_edit.temp_addr_buffer[0] == 0 && g_syncml_account_edit.temp_addr_buffer[1] == 0)
		||  mmi_ucs2cmp((CHAR*) g_syncml_account_edit.temp_addr_buffer, (CHAR*) L"./") == 0)
	{
		strcpy((CHAR*) g_syncml_account.note_address, "./");
		
		g_syncml_account.account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_NOTE;           
	}
	else
	{
		mmi_ucs2_to_asc((CHAR*) g_syncml_account.note_address, (CHAR*) g_syncml_account_edit.temp_addr_buffer);
		
		g_syncml_account.account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_NOTE;
	}
	mmi_ucs2_to_asc((CHAR*) g_syncml_account.note_username, (CHAR*) g_syncml_account_edit.temp_name_buffer);
	mmi_ucs2_to_asc((CHAR*) g_syncml_account.note_password, (CHAR*) g_syncml_account_edit.temp_pswd_buffer);
    
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	g_syncml_account.type = MMI_SYNCML_ACCOUNT_TYPE_USR_DEFINED;
#endif
    g_mmi_syncml_cntx.account_validation[g_mmi_syncml_cntx.selected_account] = g_syncml_account.account_validation;
	mmi_syncml_write_account_to_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void*)&g_syncml_account);
	
    cui_inline_close(inline_id);
}
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */


#define Edit_app_setting_email
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
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
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */


#define Edit_app_setting_bookmark
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */


#define Edit_dataaccount
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_data_account
 * DESCRIPTION
 *  Retrieve the data accounts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_check_data_account_ready(FuncPtr fp, MMI_BOOL with_scr_lock)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* check data account ready */
    if (mmi_dtcnt_ready_check(fp, with_scr_lock))
    {
        fp();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_dtcnt_list
 * DESCRIPTION
 *  List function of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_account_dtcnt_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_run_struct para;
    mmi_id dtcn_sel_cui;
    U8 acct_index = g_mmi_syncml_cntx.selected_account;
	U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&para, 0, sizeof(cui_dtcnt_select_run_struct));
    
    para.str_id = STR_ID_SYNC_APP_ID1 + acct_index;
    
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
/* under construction !*/
#else
    para.AppMenuID = MENU_ID_SYNCML_MAIN;
    para.icon_id = GetRootTitleIcon(MENU_ID_SYNCML_MAIN);
#endif

	for(i = 0; i<MMI_SIM_TOTAL; i++)
	{
	    if (mmi_syncml_data_account_is_valid(i, NULL))
        {
        	para.sim_account_id[i] = cbm_get_original_account(g_syncml_account.net_id[i]);
        }
        else
        {
        	para.sim_account_id[i] = CBM_DEFAULT_ACCT_ID;
    	}
    }
    
    para.app_id = g_mmi_syncml_cntx.app_id[acct_index];
    para.bearers = DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI;
	para.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;
    para.option = CUI_DTCNT_SELECT_SIM;
    para.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
    
    dtcn_sel_cui = cui_dtcnt_select_create(GRP_ID_SYNC_EDIT);
    cui_dtcnt_select_set_param(dtcn_sel_cui, &para);
    cui_dtcnt_select_run(dtcn_sel_cui);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_select_data_account_save
 * DESCRIPTION
 *  Callback of data account selection to get the corresponding string
 * PARAMETERS
 *  U32 index   [IN]    new encoded acct id that user select
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_select_data_account_save(U32 index, cui_dtcnt_sim_enum dtcnt_enum)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32  sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    MMI_SYNCML_TRACE0(MMI_SYNCML_SAVE_DTCNT);
    
	mmi_popup_display_simple(
		(WCHAR*)get_string(STR_GLOBAL_SAVED), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_ROOT, 
		NULL);

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	g_syncml_account.type = MMI_SYNCML_ACCOUNT_TYPE_USR_DEFINED;
#endif

    if(mmi_dtcnt_acct_is_valid(index) == MMI_DTCNT_ACCT_VALID_NONE)
    {
        g_syncml_account.account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_CONN;
    }
    else
    {
        g_syncml_account.account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_CONN; 
    }
    
    /* clear app id in net id */
	sim_index = dtcnt_enum - CUI_DTCNT_SIM1;
    g_syncml_account.net_id[sim_index] = cbm_encode_data_account_id(
                                    cbm_get_original_account(index), 
                                    (cbm_sim_id_enum)(sim_index), 
                                    0, 
                                    MMI_FALSE);      

    g_mmi_syncml_cntx.account_validation[g_mmi_syncml_cntx.selected_account] = g_syncml_account.account_validation;
	mmi_syncml_write_account_to_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void*)&g_syncml_account);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_is_valid
 * DESCRIPTION
 *  Pre-check function before start sync
 * PARAMETERS
 *  U32     acct_id     [IN]    the acct id should be original number
 *  U32*    acct_id_out [Out]   new acct id that is encoded;
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_syncml_data_account_is_valid(U32 index, U32* acct_id_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 encoded_acct_id;
    U8 acct_index = g_mmi_syncml_cntx.selected_account;
	U32 acct_id = g_syncml_account.net_id[index];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	
    encoded_acct_id = cbm_encode_data_account_id(
                        acct_id,                                                /* orginal data account id */
                        (cbm_sim_id_enum)(index),                               /* SIM info */ /*cbm_get_sim_id(g_syncml_account.net_id[sim_id - 1])*/
                        g_mmi_syncml_cntx.app_id[acct_index],                   /* app id   */
                        KAL_FALSE);                                             /* always ask feature */ 

    if (acct_id_out)
    {
        *acct_id_out = encoded_acct_id;
    }
    
    if(mmi_dtcnt_acct_is_valid(encoded_acct_id) == MMI_DTCNT_ACCT_VALID_NONE)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


#define Edit_sync_type
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_sync_type
 * DESCRIPTION
 *  entry event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_account_sync_type(cui_menu_event_struct* evt)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        GRP_ID_SYNC_EDIT,
                        CUI_MENU_SRC_TYPE_APPCREATE,
                        CUI_MENU_TYPE_APPSUB,
                        MENU_ID_SYNCML_ACCOUNT_EDIT_SYNC_TYPE,
                        MMI_FALSE,
                        NULL);
    
    cui_menu_run(menu_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_sync_type_entry_evt_hdlr
 * DESCRIPTION
 *  entry event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_sync_type_entry_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id list_of_ids[MMI_SYNCML_TYPE_END];
	mmi_menu_id i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < MMI_SYNCML_TYPE_END; i++) 
    {
        list_of_ids[i] = MMI_SYNCML_TYPE_DEFAULT + i ;
    }
    
    cui_menu_set_currlist(
        evt->sender_id, 
        MMI_SYNCML_TYPE_END, 
        list_of_ids);
    
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(MMI_SYNCML_TYPE_DEFAULT), 
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_MAIN))
#endif
        );

    for(i = 0; i < MMI_SYNCML_TYPE_END; i++)
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            MMI_SYNCML_TYPE_DEFAULT + i,
            (WCHAR*)get_string((U16)(STR_ID_SYNC_TWOWAY + i)));
    }
    
    cui_menu_set_currlist_left_softkey(
        evt->sender_id, 
        (WCHAR*)get_string(STR_GLOBAL_OK));

    cui_menu_set_currlist_highlighted_id(evt->sender_id, (mmi_menu_id)(g_syncml_account.sync_type + MMI_SYNCML_TYPE_DEFAULT));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_sync_type_edit_save
 * DESCRIPTION
 *  Save the transport type to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_sync_type_edit_save(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmi_popup_display_simple(
		(WCHAR*)get_string(STR_GLOBAL_SAVED), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_ROOT, 
		NULL); 

	g_syncml_account.sync_type = (U8)(evt->highlighted_menu_id - MENU_ID_SYNC_TYPE_DEFAULT);

	g_mmi_syncml_cntx.sync_type[g_mmi_syncml_cntx.selected_account] = g_syncml_account.sync_type;

	mmi_syncml_write_account_to_nvram((g_mmi_syncml_cntx.selected_account + 1), (void*)&g_syncml_account);

	cui_menu_close(evt->sender_id);
}
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */


#define Edit_regular_sync
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_regular_sync
 * DESCRIPTION
 *  "Regular Sync" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_account_regular_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        GRP_ID_SYNC_EDIT,
                        CUI_MENU_SRC_TYPE_APPCREATE,
                        CUI_MENU_TYPE_APPSUB,
                        MENU_ID_SYNCML_ACCOUNT_EDIT_REGULAR_SYNC,
                        MMI_FALSE,
                        NULL);
    
    cui_menu_run(menu_cui_gid);
    
    g_mmi_syncml_cntx.temp_gid = menu_cui_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_regular_sync_entry_evt_hdlr
 * DESCRIPTION
 *  entry event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_regular_sync_entry_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id list_of_ids[MMI_SYNCML_REGULAR_SYNC_END];
	mmi_menu_id i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < MMI_SYNCML_REGULAR_SYNC_END; i++) 
    {
        list_of_ids[i] = MMI_SYNCML_REGULAR_SYNC_NONE + i ;
    }
    
    cui_menu_set_currlist(
        evt->sender_id, 
        MMI_SYNCML_REGULAR_SYNC_END, 
        list_of_ids);
    
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(STR_ID_SYNC_REGULARITY), 
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_MAIN))
#endif
        );

    for(i = 0; i < MMI_SYNCML_REGULAR_SYNC_END; i++)
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            (mmi_menu_id)(MMI_SYNCML_REGULAR_SYNC_NONE + i),
            (WCHAR*)get_string((U16)(STR_ID_SYNC_REGULARITY_NONE + i)));
    }
    
    cui_menu_set_currlist_left_softkey(
        evt->sender_id, 
        (WCHAR*)get_string(STR_GLOBAL_OK));
    
    cui_menu_set_currlist_highlighted_id(evt->sender_id, (mmi_menu_id)(g_syncml_account.regular_sync + MMI_SYNCML_REGULAR_SYNC_NONE));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_regular_sync_edit_save
 * DESCRIPTION
 *  entry event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_regular_sync_edit_save(cui_menu_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_mmi_syncml_cntx.highlighted_id = (U8)(evt->highlighted_menu_id - MMI_SYNCML_REGULAR_SYNC_NONE);

#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
    if (evt->highlighted_menu_id == MMI_SYNCML_REGULAR_SYNC_DATA_CHANGED)
    {
        mmi_syncml_account_regular_sync_edit_confirm();
    }
    else
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
    {
        mmi_syncml_account_regular_sync_edit_save_done();
    }
}


#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_regular_sync_edit_confirm
 * DESCRIPTION
 *  Save the transport type to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_regular_sync_edit_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {
        if (i == g_mmi_syncml_cntx.selected_account)
		{
			continue;
		}
		/* If the setting is present on another account, notify */
		if (g_mmi_syncml_cntx.highlighted_id == MMI_SYNCML_REGULAR_SYNC_DATA_CHANGED
			&& g_mmi_syncml_cntx.regular_sync[i]== MMI_SYNCML_REGULAR_SYNC_DATA_CHANGED)
		{  
            mmi_syncml_confirm_display_with_proc(
                GRP_ID_ROOT, 
                (WCHAR*)get_string(STR_ID_SYNC_SETTING_CONFLICT), 
                CNFM_TYPE_YESNO, 
                mmi_syncml_account_regular_sync_edit_save_done, 
                mmi_syncml_account_regular_sync_edit_cancel, 
                NULL);
			g_syncml_account_index = i;            
            return;    
        }
    }
    mmi_syncml_account_regular_sync_edit_save_done();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_regular_sync_edit_cancel
 * DESCRIPTION
 *  Save the transport type to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_regular_sync_edit_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_syncml_account_index = 0xff;
    cui_menu_close(g_mmi_syncml_cntx.temp_gid);
    mmi_frm_scrn_close_active_id();
}
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_regular_sync_edit_save_done
 * DESCRIPTION
 *  Save the transport type to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_regular_sync_edit_save_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
    mmi_syncml_account_struct *temp_account = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
	mmi_popup_display_simple(
		(WCHAR*)get_string(STR_GLOBAL_SAVED), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_ROOT, 
		NULL); 
    
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
    /* reset original account regular_sync type to NONE*/
    if (g_syncml_account_index != 0xff)
    {      
        temp_account = (mmi_syncml_account_struct*) OslMalloc(sizeof(mmi_syncml_account_struct));

        g_mmi_syncml_cntx.regular_sync[g_syncml_account_index] = MMI_SYNCML_REGULAR_SYNC_NONE;       
        mmi_syncml_read_account_from_nvram((U8)(g_syncml_account_index + 1), (void*)temp_account);
        temp_account->regular_sync = MMI_SYNCML_REGULAR_SYNC_NONE;
        mmi_syncml_write_account_to_nvram((U8)(g_syncml_account_index + 1), (void*)temp_account);  
        g_syncml_account_index = 0xff;
        
        if (temp_account != NULL)
        {
            OslMfree(temp_account);
        }
    }
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
    
    g_syncml_account.regular_sync = g_mmi_syncml_cntx.highlighted_id;
    
    g_mmi_syncml_cntx.regular_sync[g_mmi_syncml_cntx.selected_account] = g_syncml_account.regular_sync;
 
    mmi_syncml_write_account_to_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void*)&g_syncml_account);

    if (g_syncml_account.regular_sync > MMI_SYNCML_REGULAR_SYNC_POWER_ON)
    {            
	mmi_syncml_set_reminder(g_mmi_syncml_cntx.selected_account);
    }
    else
    {
        srv_reminder_cancel(SRV_REMINDER_TYPE_SYNCML, g_mmi_syncml_cntx.selected_account);
    }

    cui_menu_close(g_mmi_syncml_cntx.temp_gid);
}


#define Edit_sas
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
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
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
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
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */


#define Edit_sync_report
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_account_sync_report
 * DESCRIPTION
 *  Switch sync report status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_account_sync_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        GRP_ID_SYNC_EDIT,
                        CUI_MENU_SRC_TYPE_APPCREATE,
                        CUI_MENU_TYPE_APPSUB,
                        MENU_ID_SYNCML_ACCOUNT_EDIT_REPORT,
                        MMI_FALSE,
                        NULL);
    
    cui_menu_run(menu_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_report_entry_evt_hdlr
 * DESCRIPTION
 *  entry event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_report_entry_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U16 list_of_str[2] = {STR_GLOBAL_ON, STR_GLOBAL_OFF};
    mmi_menu_id list_of_ids[2] = {0, 1};
	U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    cui_menu_set_currlist(
        evt->sender_id, 
        2, 
        list_of_ids);
    
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(STR_ID_SYNC_REPORT), 
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SYNCML_MAIN))
#endif
        );
    
    for(i = 0; i < 2; i++)
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            i, 
            (WCHAR*)get_string(list_of_str[i]));
    }

    cui_menu_set_currlist_left_softkey(
        evt->sender_id, 
        (WCHAR*)get_string(STR_GLOBAL_OK));

    cui_menu_set_currlist_highlighted_id(evt->sender_id, (mmi_menu_id)(g_syncml_account.sync_report_status ? 0 : 1));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_report_edit_save
 * DESCRIPTION
 *  Save the report type to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_report_edit_save(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_popup_display_simple(
		(WCHAR*)get_string(STR_GLOBAL_SAVED), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_ROOT, 
		NULL);     

	g_syncml_account.sync_report_status = (U8)(evt->highlighted_menu_id ? 0 : 1);

    g_mmi_syncml_cntx.sync_report_status[g_mmi_syncml_cntx.selected_account] = g_syncml_account.sync_report_status;

    mmi_syncml_write_account_to_nvram((U8)(g_mmi_syncml_cntx.selected_account + 1), (void*)&g_syncml_account);

    cui_menu_close(evt->sender_id);
}


#define menu_cui_event_hdlr
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_account_edit_menu_sel_hdlr
 * DESCRIPTION
 *  menu cui entry handler
 * PARAMETERS
 *  evt       [IN]            highlight_index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_account_edit_menu_sel_hdlr(U16 highlight_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_SYNC_EDIT))
    {
#ifdef __MMI_OP01_SYNCML_SETTING__     
/* under construction !*/
#else
    	mmi_frm_group_create(GRP_ID_SYNC_MAIN, GRP_ID_SYNC_EDIT, mmi_syncml_group_account_edit_proc, NULL);
#endif
        mmi_frm_group_enter(GRP_ID_SYNC_EDIT, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    
    switch(highlight_index)
    {
        case MENU_ID_SYNCML_ACCOUNT_EDIT_NAME:
            mmi_syncml_entry_account_name();
            break;
            
        case MENU_ID_SYNCML_ACCOUNT_EDIT_TRANSPORT_TYPE:
            mmi_syncml_entry_account_trans_type();
            break;
        
        case MENU_ID_SYNCML_ACCOUNT_EDIT_SERVER_SETTINGS:
            mmi_syncml_entry_account_server_setting();
            break;
            
        case MENU_ID_SYNCML_ACCOUNT_EDIT_APP_TO_SYNC:
            mmi_syncml_entry_account_app_to_sync();
            break;
        case MENU_ID_SYNCML_ACCOUNT_EDIT_DB_CONTACT:
            mmi_syncml_entry_account_db_contact();
            break;
            
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        case MENU_ID_SYNCML_ACCOUNT_EDIT_DB_CALENDAR:
            mmi_syncml_entry_account_db_calendar();
            break;
#endif

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        case MENU_ID_SYNCML_ACCOUNT_EDIT_DB_TASK:
            mmi_syncml_entry_account_db_task();
            break;
#endif

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        case MENU_ID_SYNCML_ACCOUNT_EDIT_DB_NOTE:
            mmi_syncml_entry_account_db_note();
            break;
#endif

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        case MENU_ID_SYNCML_ACCOUNT_EDIT_CONN_SETTINGS:
            mmi_syncml_entry_account_dtcnt_list();
            break;

        case MENU_ID_SYNCML_ACCOUNT_EDIT_REGULAR_SYNC:
            
            mmi_syncml_entry_account_regular_sync();
            break;

        case MENU_ID_SYNCML_ACCOUNT_EDIT_REPORT:
            mmi_syncml_entry_account_sync_report();
            break;
            
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
        case MENU_ID_SYNCML_ACCOUNT_EDIT_SYNC_TYPE:
            mmi_syncml_entry_account_trans_type();
            break;
#endif 

#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_menu_cui_entry_evt_hdlr
 * DESCRIPTION
 *  menu cui entry handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_menu_cui_entry_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct*)event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->parent_menu_id)
    {
#ifndef __MMI_OP01_SYNCML_SETTING__
        case  MENU_ID_SYNCML_MAIN:
#else
/* under construction !*/
#endif
        {
            mmi_syncml_account_list_entry_evt_hdlr(evt);
            break;
        }
        case MENU_ID_SYNCML_ACCOUNT_OPTION:
        {
            mmi_syncml_account_option_entry_evt_hdlr(evt);
            break;
        }
        case MENU_ID_SYNCML_ACCOUNT_EDIT:
        {
            mmi_syncml_account_edit_entry_evt_hdlr(evt);
            break;
        }
        case MENU_ID_SYNCML_ACCOUNT_EDIT_TRANSPORT_TYPE:
        {
            mmi_syncml_account_trans_type_entry_evt_hdlr(evt);
            break;
        }
        case MENU_ID_SYNCML_ACCOUNT_EDIT_APP_TO_SYNC:
        {
            mmi_syncml_account_app_to_sync_entry_evt_hdlr(evt);    
            break;
        }
        case MENU_ID_SYNCML_ACCOUNT_EDIT_DB_SETTINGS:
        {
            mmi_syncml_account_db_settings_entry_evt_hdlr(evt);
            break;
        }
        case MENU_ID_SYNCML_ACCOUNT_EDIT_REGULAR_SYNC:
        {
            mmi_syncml_account_regular_sync_entry_evt_hdlr(evt);
            break;
        }
        case MENU_ID_SYNCML_ACCOUNT_EDIT_REPORT:
        {
            mmi_syncml_account_report_entry_evt_hdlr(evt);
            break;
        }
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
        case MENU_ID_SYNCML_ACCOUNT_EDIT_SYNC_TYPE:
        {
            mmi_syncml_account_sync_type_entry_evt_hdlr(evt);
            break;
        }
#endif  
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_menu_cui_exit_evt_hdlr
 * DESCRIPTION
 *  menu cui exit event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_menu_cui_exit_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct*)event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->parent_menu_id)
    {
        case MENU_ID_SYNCML_ACCOUNT_EDIT_APP_TO_SYNC:
            mmi_syncml_account_app_to_sync_exit_evt_hdlr(evt);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_menu_cui_hilite_evt_hdlr
 * DESCRIPTION
 *  menu cui hilite event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_menu_cui_hilite_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct*)event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->parent_menu_id)
    {
#ifndef __MMI_OP01_SYNCML_SETTING__
        case  MENU_ID_SYNCML_MAIN:
#else
/* under construction !*/
#endif
        {
            mmi_syncml_account_list_hilite_evt_hdlr(evt);
            break;
        }
        default:
            break;
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_menu_cui_select_evt_hdlr
 * DESCRIPTION
 *  menu cui select event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_menu_cui_select_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct*)event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
    if (evt->parent_menu_id == MENU_ID_SYNCML_MAIN)
#endif
    {
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else    
        mmi_syncml_entry_account_option(GRP_ID_SYNC_MAIN);    
#endif
        return;
    }
  
    switch(evt->highlighted_menu_id)
    {

#ifdef __MMI_OP01_SYNCML_SETTING__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_SYNCML_SETTING__ */

        case MENU_ID_SYNCML_ACCOUNT_SYNC:
            mmi_syncml_entry_account_sync();
            break;
            
        case MENU_ID_SYNCML_ACCOUNT_EDIT:
            /* check data account is async operation, should pause menu cui firstly */
            cui_menu_pause(evt->sender_id);
            mmi_syncml_check_data_account_ready(mmi_syncml_entry_account_edit, MMI_TRUE);
            break;

        case MENU_ID_SYNCML_ACCOUNT_VIEW_LOG:
            mmi_syncml_entry_sync_log();
            break;
   
        case MENU_ID_SYNCML_ACCOUNT_EDIT_NAME:
        case MENU_ID_SYNCML_ACCOUNT_EDIT_TRANSPORT_TYPE:
        case MENU_ID_SYNCML_ACCOUNT_EDIT_SERVER_SETTINGS:
        case MENU_ID_SYNCML_ACCOUNT_EDIT_APP_TO_SYNC:
        case MENU_ID_SYNCML_ACCOUNT_EDIT_DB_CONTACT:
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        case MENU_ID_SYNCML_ACCOUNT_EDIT_DB_CALENDAR:
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        case MENU_ID_SYNCML_ACCOUNT_EDIT_DB_TASK:
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        case MENU_ID_SYNCML_ACCOUNT_EDIT_DB_NOTE:
#endif
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif
        case MENU_ID_SYNCML_ACCOUNT_EDIT_CONN_SETTINGS:
        case MENU_ID_SYNCML_ACCOUNT_EDIT_REGULAR_SYNC:
        case MENU_ID_SYNCML_ACCOUNT_EDIT_REPORT:
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
        case MENU_ID_SYNCML_ACCOUNT_EDIT_SYNC_TYPE:
#endif 
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#endif 
        {   
            mmi_syncml_account_edit_menu_sel_hdlr(evt->highlighted_menu_id);
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_menu_cui_close_notify_evt_hdlr
 * DESCRIPTION
 *  menu cui csk event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_menu_cui_csk_select_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct*)event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->parent_menu_id)
    {
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
/* under construction !*/
#else
        case MENU_ID_SYNCML_MAIN:
            mmi_syncml_entry_account_option(GRP_ID_SYNC_MAIN);  
#endif
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_menu_cui_close_evt_hdlr
 * DESCRIPTION
 *  menu cui close event handler
 * PARAMETERS
 *  evt       [IN]            menu cui event handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_menu_cui_close_notify_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct*)event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return current menu cui, close menu cui */
    cui_menu_close(evt->sender_id);
}


#endif /* __SYNCML_SUPPORT__ */
