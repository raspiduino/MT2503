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
 *  EmailAppLib.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email memory management functions.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"

#ifdef __MMI_EMAIL__
#include "MMIDataType.h"

#include "emailsrvgprot.h"
#include "emailappcore.h"
#include "EmailAppLib.h"

#include "fs_type.h"
#include "fs_errcode.h"
#include "FileMgrSrvGProt.h"

#include "mmi_frm_mem_gprot.h"

#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#endif

#include "UcmSrvGprot.h"

#include "GlobalResDef.h"
#include "AlertScreen.h"

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_email_def.h"

#include "custom_events_notify.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "Wgui_categories_popup.h"

typedef struct
{
    mmi_id parent_id, grp_id;
    WCHAR* string;
    FuncPtr abort_func;
}mmi_email_loading_ui_context_struct;

static mmi_email_loading_ui_context_struct g_loading_ui_ctx;

static void loading_rsk(void);
static void show(void);
static MMI_RET proc(mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_get_total_unread_number
 * DESCRIPTION 
 *  mmi email lib get total unread number
 * PARAMETERS 
 *  void
 * RETURNS 
 *  U32 
*****************************************************************************/
U32 mmi_email_lib_get_total_unread_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 email_unread_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_acct_total_unread_num_get(&email_unread_count);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_GET_TOTAL_UNREAD_NUMBER, email_unread_count);
    return email_unread_count;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_dir_exist
 * DESCRIPTION 
 *  mmi email lib dir exist
 * PARAMETERS 
 *  const WCHAR *path
 * RETURNS 
 *  MMI_BOOL 
*****************************************************************************/
MMI_BOOL mmi_email_lib_dir_exist(const WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (handle >= FS_NO_ERROR)
    {
        FS_Close(handle);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_DIR_EXIST, 0);
        return MMI_TRUE;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_DIR_EXIST, 1);
    return MMI_FALSE;
}


MMI_BOOL mmi_email_lib_is_copy_file_dir(WCHAR *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR drive = srv_email_get_drive();
    WCHAR *dir_path;
    MMI_BOOL ret = MMI_FALSE;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_CREATE_COPY_FILE_DIR, __LINE__);

    dir_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    kal_wsprintf(dir_path, "%scopy_file\\", srv_email_get_root_path());

    if (file_path != NULL)
    {
        for (i = 0; dir_path[i] != 0 ; i++)
        {
            if (file_path[i] != dir_path[i])
            {
                break;
            }
        }

        if (dir_path[i] == 0)
        {
            ret = MMI_TRUE;
        }
    }

    OslMfree(dir_path);

    return ret;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_create_copy_file_dir
 * DESCRIPTION 
 *  mmi email lib create copy file dir
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_lib_create_copy_file_dir(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR drive = srv_email_get_drive();
    WCHAR *dir_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_CREATE_COPY_FILE_DIR, __LINE__);

    dir_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    kal_wsprintf(dir_path, "%scopy_file\\", srv_email_get_root_path());
    FS_XDelete(dir_path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_CreateDir(dir_path);
    OslMfree(dir_path);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_empty_copy_file_dir
 * DESCRIPTION 
 *  mmi_email_lib_empty_copy_file_dir
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_lib_empty_copy_file_dir(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_lib_create_copy_file_dir();
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_is_phone_locked
 * DESCRIPTION 
 *  mmi email lib is phone locked
 * PARAMETERS 
 *  void
 * RETURNS 
 *  MMI_BOOL 
*****************************************************************************/
MMI_BOOL mmi_email_lib_is_phone_locked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_is_phone_lock())
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_IS_PHONE_LOCKED, 1);
        return MMI_TRUE;
    }
#endif /* __DM_LAWMO_SUPPORT__ */
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_IS_PHONE_LOCKED, 0);
    return MMI_FALSE;
}



MMI_BOOL mmi_email_lib_is_call_interrupt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_IS_CALL_INTERRUPT, 0);

#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) ||
            srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_IS_CALL_INTERRUPT, 1);
            return MMI_TRUE;
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_IS_CALL_INTERRUPT, -2);
            return MMI_FALSE;
        }
    }
    else
#endif /* __MMI_BACKGROUND_CALL__ */
    {
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_IS_CALL_INTERRUPT, 3);
            return MMI_TRUE;
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_IS_CALL_INTERRUPT, -4);
            return MMI_FALSE;
        }
    }
}









/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_error_popup
 * DESCRIPTION 
 *  mmi email lib error popup
 * PARAMETERS 
 *  U16 str_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_lib_error_popup(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_ERROR_POPUP, str_id);
    mmi_popup_display_simple(
        (WCHAR*)GetString(str_id), 
        MMI_EVENT_FAILURE, 
        GRP_ID_ROOT, 
        0);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_succ_popup
 * DESCRIPTION 
 *  mmi email lib succ popup
 * PARAMETERS 
 *  U16 str_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_lib_succ_popup(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_SUCC_POPUP, str_id);
    mmi_popup_display_simple(
        (WCHAR*)GetString(str_id),
        MMI_EVENT_SUCCESS, 
        GRP_ID_ROOT, 
        0);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_infor_popup
 * DESCRIPTION 
 *  mmi email lib infor popup
 * PARAMETERS 
 *  U16 str_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_lib_infor_popup(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_INFOR_POPUP, str_id);
    mmi_popup_display_simple(
        (WCHAR*)GetString(str_id),
        MMI_EVENT_INFO, 
        GRP_ID_ROOT, 
        0);
}







S32 mmi_email_lib_get_outbox_number(EMAIL_ACCT_HANDLE acct_handle, EMAIL_FLDR_ID *outbox_id)
{
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    S32 fld_cnt = 4;
    EMAIL_FLDR_ID fld_id[4];
    srv_email_acct_folder_struct *fld_info;
    S32 num = 0;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_GET_OUTBOX_NUMBER, 0);

    if (outbox_id)
    {
        *outbox_id = 0;
    }

    result = srv_email_acct_get_fldr_id(acct_handle, SRV_EMAIL_ACCT_FLDR_TYPE_BASIC, 0, &fld_cnt, fld_id);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_GET_OUTBOX_NUMBER, -1);
        return 0;
    }


    num = 0;
    fld_info = (srv_email_acct_folder_struct*)OslMalloc(sizeof(srv_email_acct_folder_struct));
    result = srv_email_acct_get_fldr_info(acct_handle, fld_id[1], fld_info);
    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        num = fld_info->msg_count;
    }
    OslMfree(fld_info);

    if (outbox_id)
    {
        *outbox_id = fld_id[1];
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_GET_OUTBOX_NUMBER, num);
    return num;
}








static void show(void)
{
    MMI_BOOL ret;

    g_loading_ui_ctx.grp_id = GRP_ID_ROOT;
    ret = mmi_frm_scrn_enter(
            g_loading_ui_ctx.grp_id,
            SCR_EMAIL_NWK_SCREEN_ID,
            NULL,
            show,
            MMI_FRM_FULL_SCRN);

    if (ret == MMI_FALSE)
    {
        return;
    }

    ShowCategory66Screen(
        STR_GLOBAL_EMAIL,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        g_loading_ui_ctx.abort_func == NULL ? 0 : STR_GLOBAL_CANCEL,
        g_loading_ui_ctx.abort_func == NULL ? 0 : IMG_GLOBAL_BACK,
        (U8*)g_loading_ui_ctx.string,
        mmi_email_lib_get_progress_img_id(),
        NULL);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(loading_rsk, KEY_EVENT_UP);
}

static void loading_rsk(void)
{
    if (g_loading_ui_ctx.abort_func != NULL)
    {
        g_loading_ui_ctx.abort_func();
        g_loading_ui_ctx.abort_func = NULL;
    }

    mmi_email_lib_loading_ui_close();
}

static MMI_RET proc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_GROUP_DEINIT 
        && g_loading_ui_ctx.abort_func != NULL)
    {
        g_loading_ui_ctx.abort_func();
        g_loading_ui_ctx.abort_func = NULL;
    }

    return MMI_RET_OK;
}




/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_loading_ui_show
 * DESCRIPTION 
 *  mmi email lib loading ui show
 * PARAMETERS 
 *  mmi_id grp_id
 *  WCHAR* string
 *  FuncPtr abort_func
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_lib_loading_ui_show(mmi_id grp_id, WCHAR* string, FuncPtr abort_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_LOADING_UI_SHOW, __LINE__);

    g_loading_ui_ctx.string = string;
    g_loading_ui_ctx.parent_id = grp_id;
    g_loading_ui_ctx.abort_func = abort_func;
    g_loading_ui_ctx.grp_id = mmi_frm_group_create_ex(
        grp_id, GRP_ID_AUTO_GEN, proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    show();
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_loading_ui_update
 * DESCRIPTION 
 *  mmi email lib loading ui update
 * PARAMETERS 
 *  WCHAR* string
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_lib_loading_ui_update(WCHAR* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_LOADING_UI_UPDATE, __LINE__);
    wgui_cat_popup_update_string((UI_string_type)string);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_loading_ui_close
 * DESCRIPTION 
 *  mmi email lib loading ui close
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_lib_loading_ui_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_LOADING_UI_CLOSE, __LINE__);
    g_loading_ui_ctx.abort_func = NULL;
    if (g_loading_ui_ctx.grp_id != 0)
    {
        //mmi_frm_group_close(g_loading_ui_ctx.grp_id);
        mmi_frm_scrn_close(g_loading_ui_ctx.grp_id, SCR_EMAIL_NWK_SCREEN_ID);
        g_loading_ui_ctx.grp_id = 0;
    }
}



U16 mmi_email_lib_get_progress_img_id(void)
{
#if defined __MMI_MAINLCD_128X128__
    return 0;
#elif defined __MMI_MAINLCD_128X160__
    return 0;
#elif defined __MMI_MAINLCD_172X220__
    return 0;
#elif defined __MMI_MAINLCD_240X320__
    return mmi_get_event_based_image(MMI_EVENT_PROGRESS);
#elif defined __MMI_MAINLCD_320X240__
    return 0;
#else
    return mmi_get_event_based_image(MMI_EVENT_PROGRESS);
#endif
}



void mmi_email_lib_warning(char *filename, int line)
{

}

void mmi_email_lib_assert(char *filename, int line)
{
}


MMI_BOOL email_mmi_lib_is_valid_account(EMAIL_ACCT_ID acct_id)
{
    srv_email_result_enum ret;
    MMI_BOOL is_valid = MMI_FALSE;

    ret = srv_email_acct_check_valid(acct_id, &is_valid);
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        is_valid = MMI_FALSE;
    }

    return is_valid;
}


#ifdef __MMI_EMAIL_IMAP_PUSH__

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_set_push_account
 * DESCRIPTION 
 *  mmi email lib set push account
 * PARAMETERS 
 *  EMAIL_ACCT_ID acct_id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_lib_set_push_account(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // Remove OLD and Add new
    mmi_email_app_core_result_enum ret;
    U32 i, temp = MMI_EMAIL_MAX_ACCTS;
    EMAIL_ACCT_ID old_id_arr[MMI_EMAIL_MAX_ACCTS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_SET_PUSH_ACCOUNT, acct_id);
    ret = mmi_email_imap_push_acct_get(old_id_arr, &temp);
    if (ret != MMI_EMAIL_SUCCESS || temp != 1)
    {
        temp = 0;
    }
    for (i = 0; i < temp; i++)
    {
        mmi_email_imap_push_acct_remove(old_id_arr[i]);
    }

    if (acct_id != EMAIL_ACCT_INVALID_ID)
    {
        mmi_email_imap_push_acct_add(acct_id);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_lib_get_push_account
 * DESCRIPTION 
 *  mmi email lib get push account
 * PARAMETERS 
 *  void
 * RETURNS 
 *  EMAIL_ACCT_ID 
*****************************************************************************/
EMAIL_ACCT_ID mmi_email_lib_get_push_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, temp = MMI_EMAIL_MAX_ACCTS;
    EMAIL_ACCT_ID push_acct_id = EMAIL_ACCT_INVALID_ID;
    mmi_email_app_core_result_enum ret;

    EMAIL_ACCT_ID old_id_arr[MMI_EMAIL_MAX_ACCTS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_email_imap_push_acct_get(old_id_arr, &temp);
    if (ret != MMI_EMAIL_SUCCESS || temp < 1)
    {
        return EMAIL_ACCT_INVALID_ID;
    }

    // Remove invalid firtly
    for (i = 0; i < temp; i++)
    {
        if (!email_mmi_lib_is_valid_account(old_id_arr[i]))
        {
            mmi_email_imap_push_acct_remove(old_id_arr[i]);
            old_id_arr[i] = EMAIL_ACCT_INVALID_ID;
        }
    }

    for (i = 0; i < temp; i++)
    {
        if (old_id_arr[i] != EMAIL_ACCT_INVALID_ID)
        {
            push_acct_id = old_id_arr[i++];
            break;
        }
    }

    for (; i < temp; i++)
    {
        // Remove all other, only keep one
        if (old_id_arr[i] != EMAIL_ACCT_INVALID_ID)
        {
            WARRING();
            mmi_email_imap_push_acct_remove(old_id_arr[i]);
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_LIB_GET_PUSH_ACCOUNT, push_acct_id);
    return push_acct_id;
}

#endif /* __MMI_EMAIL_IMAP_PUSH__ */








static BOOL g_dummy_disabled = FALSE;
static BOOL g_dummy_pending = FALSE;
static FuncPtr g_dummy_func = NULL;
static mmi_ret mmi_email_dummy_refresh_internal(mmi_event_struct *param);
static void dummy_proc(void);

/*****************************************************************************
 * FUNCTION 
 *  dummy_proc
 * DESCRIPTION 
 *  dummy proc
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void dummy_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}



/*****************************************************************************
 * FUNCTION 
 *  mmi_email_dummy_refresh_enable
 * DESCRIPTION 
 *  mmi email dummy refresh enable
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_dummy_refresh_enable(BOOL to_enable)
{
    g_dummy_disabled = !to_enable;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_dummy_refresh
 * DESCRIPTION 
 *  mmi email dummy refresh
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_dummy_refresh(FuncPtr pfn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DUMMY_REFRESH, 1);

    if (g_dummy_disabled)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DUMMY_REFRESH, -1);
        return;
    }

    if (g_dummy_pending)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DUMMY_REFRESH, -2);
        return;
    }

    g_dummy_pending = TRUE;
    g_dummy_func = pfn;

    evt.evt_id = 0;
    evt.size = sizeof(mmi_event_struct);
    evt.user_data = NULL;

    mmi_frm_post_event(&evt, mmi_email_dummy_refresh_internal, NULL);
}


static mmi_ret mmi_email_dummy_refresh_internal(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DUMMY_REFRESH, 2);

    if (g_dummy_disabled)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DUMMY_REFRESH, -3);
        g_dummy_func = NULL;
        return MMI_TRUE;
    }

    if (g_dummy_func)
    {
        g_dummy_func();
    }
    else
    {
        if(mmi_frm_scrn_enter(
            GRP_ID_ROOT, 
            SCR_EMAIL_DUMMY_SCREEN_ID, 
            NULL, 
            dummy_proc,
            MMI_FRM_UNKNOW_SCRN))
        {
            mmi_frm_scrn_close_active_id();
        }
    }

    g_dummy_pending = FALSE;
    g_dummy_func = NULL;
    return MMI_TRUE;
}




#include "EmailAppAccountData.h"

#define SEL_ACCT_SCREEN_MEM_SIZE (MMI_EMAIL_MAX_ACCTS * (SRV_EMAIL_MAX_ACCT_NAME_LEN + 1) * 2)

static mmi_id sel_acct_grp_id;
static EMAIL_ACCT_ID *sel_acct_acc_id = NULL;
static FuncPtr sel_acct_callback = NULL;
static S32 sel_acct_highlight_idx;
static WCHAR *sel_acct_scrmem_ptr = NULL;


static mmi_ret sel_acct_group_proc(mmi_event_struct *p_event);
static void sel_acct_list(void);
static mmi_ret sel_acct_list_entry(mmi_scrn_essential_struct *p_screen_data);
static void sel_acct_list_highlight(S32 idx);
static mmi_ret sel_acct_list_exit(mmi_scrn_essential_struct *p_screen_data);

static void sel_acct_list_lsk(void);

void mmi_email_lib_select_account(FuncPtr lsk_func, EMAIL_ACCT_ID *acc_id)
{
    mmi_frm_group_close(sel_acct_grp_id);

    sel_acct_callback = lsk_func;
    sel_acct_acc_id = acc_id;

    sel_acct_list();
}




static mmi_ret sel_acct_group_proc(mmi_event_struct *p_event)
{
    switch (p_event->evt_id)
    {
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_emn_entry_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void sel_acct_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sel_acct_grp_id = mmi_frm_group_create(
        GRP_ID_ROOT, 
        GRP_ID_AUTO_GEN, 
        sel_acct_group_proc, 
        NULL);
    mmi_frm_group_enter(sel_acct_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(
        sel_acct_grp_id, 
        SCR_ID_EMAIL_EMN_LIST, // Steal the EMN screen ID
        (FuncPtr)sel_acct_list_entry, 
        NULL);
}


static void sel_acct_list_highlight(S32 idx)
{
    sel_acct_highlight_idx = idx;
}



static mmi_ret sel_acct_list_entry(mmi_scrn_essential_struct *p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *acct_string[MMI_EMAIL_MAX_ACCTS];
    U8 *hint_string[MMI_EMAIL_MAX_ACCTS];
    S32 string_len = 0;
    U8 *string_ptr = subMenuData[0];
    U16 icon[MMI_EMAIL_MAX_ACCTS];
    U32 i, account_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE != mmi_frm_scrn_enter(
                        p_screen_data->group_id,
                        p_screen_data->scrn_id,
                        (FuncPtr)sel_acct_list_exit,
                        (FuncPtr)sel_acct_list_entry,
                        MMI_FRM_FULL_SCRN))
    {
        return MMI_RET_OK;
    }

    account_number = email_mmi_account_data_get_count();
    if (account_number == 0)
    {
        mmi_frm_scrn_close(sel_acct_grp_id, SCR_ID_EMAIL_EMN_LIST);
        return MMI_RET_OK;
    }


    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    memset(subMenuData, 0, sizeof(subMenuData));
    sel_acct_scrmem_ptr = applib_mem_screen_alloc(SEL_ACCT_SCREEN_MEM_SIZE);
    MMI_ASSERT(NULL != sel_acct_scrmem_ptr);


    for (i = 0; i < account_number; i++)
    {
        acct_string[i] = (U8*)(sel_acct_scrmem_ptr + i * (SRV_EMAIL_MAX_ACCT_NAME_LEN + 1));
        kal_wstrcpy((WCHAR*)acct_string[i], email_mmi_account_data_get_name(i));

        kal_wstrcpy((WCHAR*)string_ptr, email_mmi_account_data_get_hint(i));

        string_len = mmi_wcslen((WCHAR*)string_ptr);
        hint_string[i] = string_ptr;
        string_ptr += (string_len + 1) * ENCODING_LENGTH;
        icon[i] = IMG_EMAIL_EMN_LIST_ID;
    }

    RegisterHighlightHandler(sel_acct_list_highlight);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory354Screen(
        (U8*)GetString(STR_GLOBAL_EMAIL),
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_REPLACE,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        account_number,
        acct_string,
        hint_string,
        icon,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(sel_acct_list_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(sel_acct_list_lsk, KEY_EVENT_UP);


    return MMI_RET_OK;
} 


static mmi_ret sel_acct_list_exit(mmi_scrn_essential_struct *p_screen_data)
{
    if (NULL != sel_acct_scrmem_ptr)
    {
        applib_mem_screen_free(sel_acct_scrmem_ptr);
        sel_acct_scrmem_ptr = NULL;
    }
    return MMI_RET_OK;
}


static void sel_acct_list_lsk(void)
{
    if (sel_acct_acc_id != NULL)
    {
        *sel_acct_acc_id = email_mmi_account_data_get_id(sel_acct_highlight_idx);
    }

    if (sel_acct_callback != NULL)
    {
        sel_acct_callback();
    }

    mmi_frm_group_close(sel_acct_grp_id);
}









#endif /* __MMI_EMAIL__ */

