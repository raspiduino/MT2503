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
 * EmailAppUtil.c
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
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EMAIL__
#include "CommonScreens.h"
#include "Menucuigprot.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif 

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Def.h"
#include "HomeScreenOp11V32Gprot.h"
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __MMI_OP12_TOOLBAR__
#include "IdleToolbarGprot.h"
#endif /* __MMI_OP12_TOOLBAR__ */

#include "IdleNotificationManagergprot.h"

#include "EmailSrvGprot.h"
#include "EmailAppGProt.h"
#include "EmailAppProt.h"
#include "EmailAppOperators.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "customer_ps_inc.h"
#include "kal_public_api.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "FileMgrSrvGProt.h"
#include "fs_func.h"
#include "fs_type.h"
#include "DebugInitDef_Int.h"
#include "app_datetime.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_events_gprot.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_email_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "NotificationGprot.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"
#include "NwUsabSrvGprot.h"

#include "EmailAppLib.h"
#include "EmailAppStateMgr.h"

/************************************************************************/
/*                   defines                                            */
/************************************************************************/
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#define EMAIL_HS_SCT_EXT_NAME                           ".sct"
#define EMAIL_HS_SCT_VERSION                            1
#define EMAIL_HS_SCT_ACCT_FILE_NAME                     "hs_sct_acct"

typedef struct
{
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID fldr_id;
    BOOL valid;
    BOOL is_requeired;
    S32 unread_count;
} mmi_email_hs_shortcut_account_info_struct;

typedef struct
{
    U8 curr_select_acct_index;
    mmi_email_hs_shortcut_account_info_struct acct_array[MMI_OP11_HS32_AP_EML_ACCOUNT_MAX];
} mmi_email_hs_shortcut_info_struct;
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

/************************************************************************/
/*                          Variables                                   */
/************************************************************************/

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
// shortcut account info
static mmi_email_hs_shortcut_info_struct email_hs_sct_info;
static BOOL email_hs_is_inbox_select = FALSE;
static BOOL email_hs_is_sidebar_required = FALSE;
static U8 email_hs_selected_index = 0;
static mmi_id email_hs_select_grp_id = 0;
static mmi_id email_hs_set_grp_id = 0;
static mmi_id email_hs_parent_id = 0;
static WCHAR email_hs_acct_name[MMI_EMAIL_MAX_ACCTS][SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];
static EMAIL_ACCT_ID email_hs_acct_id_array[MMI_EMAIL_MAX_ACCTS];
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __OP12__
static BOOL can_show_vf_list = FALSE;
#endif /* __OP12__ */

#ifdef __MMI_OP12_TOOLBAR__
static mmi_tb_result_enum email_tb_status = MMI_TB_RESULT_NOT_READY;
static WCHAR email_tb_string[50];
static mmi_id email_tb_option_grp_id = 0;
#endif /* __MMI_OP12_TOOLBAR__ */


/************************************************************************/
/*                          Prototypes                                  */
/************************************************************************/

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
static void mmi_email_hs_make_path(WCHAR *path_buff);
static void mmi_email_hs_get_shortcut_file_name(WCHAR *path_buff);
static void mmi_email_hs_del_shortcut_file(void);
static BOOL mmi_email_hs_read_shortcut_item(void *data);
static void mmi_email_hs_write_shortcut_item(void *data);
static BOOL mmi_email_hs_get_acct_unread_count(EMAIL_ACCT_ID acct_id, S32 *count, EMAIL_FLDR_ID *fldr_id);
static void mmi_email_hs_update_sidebar_info(void);
static void mmi_email_hs_update_sidebar_info_internal(
                mmi_op11_hs32_data_result_enum flag,
                mmi_op11_hs32_sidebar_notify_eml_enum type);
static void mmi_email_hs_update_email_shct_info(EMAIL_ACCT_ID acct_id, S32 shct_id);
static mmi_ret mmi_email_hs_acct_set_group_proc(mmi_event_struct *evt);
static void mmi_email_hs_entry_acct_set(void);
static void mmi_email_hs_acct_set_lsk(void);
static void mmi_email_hs_save_acct_info(void);
static void mmi_email_hs_entry_select(void);
static mmi_ret mmi_email_hs_acct_sel_group_proc(mmi_event_struct *evt);
static void mmi_email_hs_entry_acct_select_list(void);
static void mmi_email_hs_hilit_acct_handler(S32 index);
static void mmi_email_hs_acct_select_lsk(void);
static void mmi_email_hs_entry_select_single(EMAIL_ACCT_ID acct_id);
static U32 mmi_email_hs_get_shct_acct_count(void);
static U32 mmi_email_hs_set_acct_select(EMAIL_ACCT_ID *acct_array);
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __OP12__
static void mmi_email_nmgr_event_list_entry_inbox(void *user_data);
#endif /* __OP12__ */

#ifdef __MMI_OP12_TOOLBAR__
static void mmi_email_tb_answer_handler(void);
static void mmi_email_tb_key_handler(U16 key_code, U16 key_type, void *user_data);
static void mmi_email_tb_entry_opt(void);
static mmi_ret mmi_email_tb_opt_proc(mmi_event_struct *evt);
static void mmi_email_tb_opt_handler(mmi_menu_id menu_id);
#endif /* __MMI_OP12_TOOLBAR__ */


/************************************************************************/
/*                           Implements                                 */
/************************************************************************/

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)

void mmi_email_close_hs_screen(void)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_CLOSE_HS_SCREEN, __LINE__);

    if (email_hs_select_grp_id != 0)
    {
        mmi_frm_group_close(email_hs_select_grp_id);
    }

    if (email_hs_set_grp_id)
    {
        mmi_frm_group_close(email_hs_set_grp_id);
    }
}


static void mmi_email_hs_make_path(WCHAR *path_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR drive = srv_email_get_drive(); // No needed!

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_MAKE_PATH, __LINE__);
    kal_wsprintf(path_buff, "%s", srv_email_get_root_path());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hs_get_shortcut_file_name
 * DESCRIPTION
 *  Get the file name
 * PARAMETERS
 *  path_buff      [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_hs_get_shortcut_file_name(WCHAR *path_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR temp_name[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_GET_SHORTCUT_FILE_NAME, __LINE__);

    memset(path_buff, 0, sizeof(path_buff));
    mmi_email_hs_make_path(path_buff);
    kal_wsprintf(temp_name, "%s%s", EMAIL_HS_SCT_ACCT_FILE_NAME, EMAIL_HS_SCT_EXT_NAME);
    mmi_wcscat(path_buff, temp_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hs_del_shortcut_file
 * DESCRIPTION
 *  Get the file name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_hs_del_shortcut_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *file_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_DEL_SHORTCUT_FILE, __LINE__);

    file_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    mmi_email_hs_get_shortcut_file_name(file_path);
    FS_Delete(file_path);
    OslMfree(file_path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hs_read_shortcut_item
 * DESCRIPTION
 *  Read the items from file    // read the account id(s)
 * PARAMETERS
 *  data      [OUT]
 * RETURNS
 *  whether the file is corrupted
 *****************************************************************************/
static BOOL mmi_email_hs_read_shortcut_item(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_h;
    U32 error_code = 0;
    WCHAR *file_path;
    U8 value = 0;
    U32 file_size;
    S32 data_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_READ_SHORTCUT_ITEM, __LINE__);
    /*
     * version value header
     * account ID
     * version value tail
     */
    data_size = MMI_OP11_HS32_AP_EML_ACCOUNT_MAX * sizeof(EMAIL_ACCT_ID);
    file_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    mmi_email_hs_get_shortcut_file_name(file_path);
    file_h = FS_Open((U16*)file_path, FS_READ_ONLY);
    if (file_h > 0)
    {
        FS_GetFileSize(file_h, &file_size);
        if (file_size != data_size + 2)
        {
            goto HS_SCT_ERROR1;
        }
        /* check the version */
        FS_Read(file_h, &value, 1, &error_code);    // the return value of {FS_Read} should be cared, and the 4th arg is NOT error code, it's read/writtern
        if ((error_code == 0) || (value != EMAIL_HS_SCT_VERSION))
        {
            goto HS_SCT_ERROR1;
        }
        FS_Read(file_h, data, data_size, &error_code);
        if ((error_code == 0) || (error_code != (U32)data_size))    // should be {error_code < data_size}
        {
            goto HS_SCT_ERROR1;
        }
        /* check file whether integrated */
        FS_Read(file_h, &value, 1, &error_code);
        if ((error_code == 0) || (value != EMAIL_HS_SCT_VERSION))
        {
            goto HS_SCT_ERROR1;
        }
        OslMfree(file_path);
        FS_Close(file_h);
        return TRUE;
    }
    else
    {
        goto HS_SCT_ERROR2;
    }
HS_SCT_ERROR1:
    FS_Close(file_h);
HS_SCT_ERROR2:
    FS_Delete((U16*)file_path);
    OslMfree(file_path);
    memset(data, 0, data_size);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hs_write_shortcut_item
 * DESCRIPTION
 *  Write the items to file
 * PARAMETERS
 *  data      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_hs_write_shortcut_item(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_h;
    U32 file_len = 0;
    WCHAR *file_path;
    U8 value = 0;
    S32 data_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_WRITE_SHORTCUT_ITEM, __LINE__);

    data_size = MMI_OP11_HS32_AP_EML_ACCOUNT_MAX * sizeof(EMAIL_ACCT_ID);
    file_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    mmi_email_hs_get_shortcut_file_name(file_path);
    file_h = FS_Open((U16*)file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    OslMfree(file_path);
    if (file_h > 0)
    {
        value = (U8)EMAIL_HS_SCT_VERSION;
        /* write version */
        FS_Write(file_h, &value, 1, &file_len);
        /* write items */
        FS_Write(file_h, data, data_size, &file_len);
        /* write file tail */
        FS_Write(file_h, &value, 1, &file_len);
        FS_Close(file_h);
    }
    // may be should be {else} here, and return the FS {result}
}


// in this function, APP read unread num from Storage's File,
// but account's unread num is stored in memory
// it's better for APP to read from memory
static BOOL mmi_email_hs_get_acct_unread_count(EMAIL_ACCT_ID acct_id, S32 *count, EMAIL_FLDR_ID *fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 folder_num = 4;
    EMAIL_FLDR_ID fldr_id_array[4];
    EMAIL_ACCT_HANDLE acct_handle = 0;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    srv_email_acct_folder_struct *folder_info_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_GET_ACCT_UNREAD_COUNT, __LINE__);

    folder_info_ptr = OslMalloc(sizeof(srv_email_acct_folder_struct));
    memset(folder_info_ptr, 0, sizeof(srv_email_acct_folder_struct));
    *count = -1;
    *fldr_id = 0;
    result = srv_email_acct_create(0, &acct_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        goto HS_GET_UNREAD_ERR2;
    }
    result = srv_email_acct_open(acct_handle, acct_id);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        goto HS_GET_UNREAD_ERR1;
    }
    result = srv_email_acct_get_fldr_id(
                acct_handle,
                SRV_EMAIL_ACCT_FLDR_TYPE_BASIC,
                0,
                &folder_num,
                fldr_id_array);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        goto HS_GET_UNREAD_ERR1;
    }
    result = srv_email_acct_get_fldr_info(
                acct_handle,
                fldr_id_array[SRV_EMAIL_FLDR_TYPE_INBOX],
                folder_info_ptr);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        goto HS_GET_UNREAD_ERR1;
    }
    *fldr_id = fldr_id_array[SRV_EMAIL_FLDR_TYPE_INBOX];
    *count = folder_info_ptr->unread_count;
HS_GET_UNREAD_ERR1:
    srv_email_acct_destroy(acct_handle);
HS_GET_UNREAD_ERR2:
    OslMfree(folder_info_ptr);
    return ((*count == -1) ? FALSE : TRUE);
}


void mmi_email_hs_init_acct_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = 0;
    S32 count = 0;
    MMI_BOOL is_valid = FALSE;
    EMAIL_FLDR_ID fldr_id = 0;
    EMAIL_ACCT_ID hs_sct_acct[MMI_OP11_HS32_AP_EML_ACCOUNT_MAX];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_INIT_ACCT_INFO, __LINE__);

    memset(&email_hs_sct_info, 0, sizeof(mmi_email_hs_shortcut_info_struct));
    if (mmi_email_hs_read_shortcut_item(hs_sct_acct))
    {
        for (; index < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; index++)
        {
            srv_email_acct_check_valid(hs_sct_acct[index], &is_valid);
            if (!is_valid)
            {
                continue;
            }
            if (!mmi_email_hs_get_acct_unread_count(hs_sct_acct[index], &count, &fldr_id))
            {
                continue;
            }
            email_hs_sct_info.acct_array[index].acct_id = hs_sct_acct[index];
            email_hs_sct_info.acct_array[index].fldr_id = fldr_id;
            email_hs_sct_info.acct_array[index].unread_count = count;
            email_hs_sct_info.acct_array[index].valid = TRUE;
        }
        if (email_hs_is_sidebar_required)
        {   // bootup, show idle, but email srv not ready
            mmi_email_hs_update_sidebar_info();
            email_hs_is_sidebar_required = FALSE;
        }
    }
    else
    {
        for (index = 0; index < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; index++)
        {
            email_hs_sct_info.acct_array[index].acct_id = 0;
            email_hs_sct_info.acct_array[index].fldr_id = 0;
            email_hs_sct_info.acct_array[index].unread_count = 0;
            email_hs_sct_info.acct_array[index].valid = TRUE;
        }
        if (email_hs_is_sidebar_required)
        {
            mmi_email_hs_update_sidebar_info();
            email_hs_is_sidebar_required = FALSE;
        }
	}
}


void mmi_email_hs_query_sidebar_info(S32 sidebar_id, S32 indctr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_sidebar_query_info_struct *data =
        OslMalloc(sizeof(mmi_op11_hs32_sidebar_query_info_struct));
    EMAIL_ACCT_ID account_array[MMI_OP11_HS32_AP_EML_ACCOUNT_MAX];
    S32 i = 0;
    EMAIL_FLDR_ID fldr_id = 0;
    S32 count = 0;
    MMI_BOOL is_valid = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_QUERY_SIDEBAR_INFO, __LINE__);

    memset(data, 0, sizeof(mmi_op11_hs32_sidebar_query_info_struct));
    if (mmi_email_smgr_could_show_icon())
    {
        data->result_flag = MMI_OP11_HS32_RESULT_OK;
        data->indicator_value = 0;

        for (; i < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; i++)
        {
            if (email_hs_sct_info.acct_array[i].valid)
            {
                srv_email_acct_check_valid(email_hs_sct_info.acct_array[i].acct_id, &is_valid);
                if (!is_valid)
                {
                    mmi_email_acct_del_notify(email_hs_sct_info.acct_array[i].acct_id);
                    account_array[i] = 0;
                    data->indicator_value += 0;
                    continue;
                }
                account_array[i] = email_hs_sct_info.acct_array[i].acct_id;
                mmi_email_hs_get_acct_unread_count(email_hs_sct_info.acct_array[i].acct_id, &count, &fldr_id);
                email_hs_sct_info.acct_array[i].unread_count = count;
                data->indicator_value += email_hs_sct_info.acct_array[i].unread_count;
                count = 0;
            }
            else
            {
                account_array[i] = 0;
                data->indicator_value += 0; // should be removed..
            }
        }
        data->sync_data= account_array;

        mmi_op11_hs32_answer_sidebar(sidebar_id, indctr_id, data);
    }
    else
    {
        data->result_flag = MMI_OP11_HS32_RESULT_NOT_READY;
        data->indicator_value = 0;
        mmi_op11_hs32_answer_sidebar(sidebar_id, indctr_id, data);
        email_hs_is_sidebar_required = TRUE;
    }
    OslMfree(data);
}

void mmi_email_hs_update_sidebar_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_data_result_enum flag = MMI_OP11_HS32_RESULT_UPDATE;
    mmi_op11_hs32_sidebar_notify_eml_enum type = MMI_OP11_HS32_EML_NOTIFY_ALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_UPDATE_SIDEBAR_INFO, __LINE__);
    mmi_email_hs_update_sidebar_info_internal(flag, type);
}


void mmi_email_hs_update_sidebar_indicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_data_result_enum flag = MMI_OP11_HS32_RESULT_UPDATE;
    mmi_op11_hs32_sidebar_notify_eml_enum type = MMI_OP11_HS32_EML_NOTIFY_INDICATOR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_UPDATE_SIDEBAR_INDICATOR, __LINE__);
    mmi_email_hs_update_sidebar_info_internal(flag, type);
}


void mmi_email_hs_update_sidebar_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_data_result_enum flag = MMI_OP11_HS32_RESULT_UPDATE;
    mmi_op11_hs32_sidebar_notify_eml_enum type = MMI_OP11_HS32_EML_NOTIFY_SYNC_ACCOUNT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_UPDATE_SIDEBAR_ACCOUNT, __LINE__);
    mmi_email_hs_update_sidebar_info_internal(flag, type);
}

// update HS data
void mmi_email_hs_update_sidebar_info_internal(
            mmi_op11_hs32_data_result_enum flag,
            mmi_op11_hs32_sidebar_notify_eml_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_op11_hs32_sidebar_query_info_struct *data =
        OslMalloc(sizeof(mmi_op11_hs32_sidebar_query_info_struct));
    EMAIL_ACCT_ID account_array[MMI_OP11_HS32_AP_EML_ACCOUNT_MAX];
    S32 i = 0;
    EMAIL_FLDR_ID fldr_id = 0;
    S32 count = 0;
    MMI_BOOL is_valid = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_UPDATE_SIDEBAR_INFO_INTERNAL, __LINE__);

    memset(data, 0, sizeof(mmi_op11_hs32_sidebar_query_info_struct));
    data->result_flag = flag;
    data->indicator_value = 0;

    for (; i < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; i++)
    {
        if (email_hs_sct_info.acct_array[i].valid)
        {
            srv_email_acct_check_valid(email_hs_sct_info.acct_array[i].acct_id, &is_valid);
            if (!is_valid)
            {
                // if not valid, delete it from hsc.acct file
                mmi_email_acct_del_notify(email_hs_sct_info.acct_array[i].acct_id);
                account_array[i] = 0;
                data->indicator_value += 0;
                continue;
            }
            account_array[i] = email_hs_sct_info.acct_array[i].acct_id;
            mmi_email_hs_get_acct_unread_count(email_hs_sct_info.acct_array[i].acct_id, &count, &fldr_id);
            email_hs_sct_info.acct_array[i].unread_count = count;
            // it's the num shown in HS
            data->indicator_value += email_hs_sct_info.acct_array[i].unread_count;
            count = 0;
        }
        else
        {
            account_array[i] = 0;
            data->indicator_value += 0;
        }
    }
    data->sync_data = account_array;

    // notify sidebar to update data
    mmi_op11_hs32_answer_sidebar(
        MMI_OP11_HS32_AP_EML,
        type,
        data);
    OslMfree(data);
}


void mmi_email_hs_reset_sidebar_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_RESET_SIDEBAR_ICON, __LINE__);

    for (; index < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; index++)
    {
        if (email_hs_sct_info.acct_array[index].acct_id != 0)
        {
            email_hs_sct_info.acct_array[index].unread_count = 0;
        }
    }
}


void mmi_email_hs_query_email_shct_info(S32 sidebar_id, S32 shct_id, void *shct_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    WCHAR account_name[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];
    U32 acct_name_length =
            ((SRV_EMAIL_MAX_ACCT_NAME_LEN > MMI_OP11_HS32_SHCT_LABEL_STRLEN_MAX) ?
             MMI_OP11_HS32_SHCT_LABEL_STRLEN_MAX : SRV_EMAIL_MAX_ACCT_NAME_LEN);
    mmi_op11_hs32_shct_data_struct *shct_data_p = (mmi_op11_hs32_shct_data_struct *)shct_data;
    srv_email_acct_info_cache_struct *cache_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_QUERY_EMAIL_SHCT_INFO, __LINE__);

    /* fill the default data */
    shct_data_p->item_count = 0;
    cache_info = OslMalloc(sizeof(srv_email_acct_info_cache_struct));
    srv_email_acct_cache_get((EMAIL_ACCT_ID)shct_data_p->query_index, cache_info);
    mmi_wcscpy(account_name, cache_info->acct_name);
    OslMfree(cache_info);
    mmi_wcsncpy(shct_data_p->shct_label, account_name, acct_name_length);
    shct_data_p->shct_label[acct_name_length] = L'\0';
    for (; index < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; index++)
    {
        if (email_hs_sct_info.acct_array[index].acct_id == (EMAIL_ACCT_ID)shct_data_p->query_index)
        {
            break;
        }
    }
    MMI_EXT_ASSERT((index < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX), 0, 0, 0);
    email_hs_sct_info.acct_array[index].is_requeired = TRUE;
    shct_data_p->result_flag = MMI_OP11_HS32_RESULT_NOT_READY;    
    
    if (srv_email_get_srv_init_state() != SRV_EMAIL_INIT_STATE_READY ||
        !mmi_email_is_drive_valid(srv_email_get_drive()))
    {
        mmi_op11_hs32_answer_shct_data(sidebar_id, shct_id, shct_data_p);
    }
    else
    {
        mmi_email_hs_update_email_shct_info((EMAIL_ACCT_ID)shct_data_p->query_index, shct_id);
    }
}


void mmi_email_hs_update_email_shct_info(EMAIL_ACCT_ID acct_id, S32 shct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0, i = 0, chset = 0;
    BOOL is_update = FALSE;
    mmi_op11_hs32_shct_data_struct *shct_data_p = NULL;
    WCHAR account_name[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];
    U32 acct_name_length =
            ((SRV_EMAIL_MAX_ACCT_NAME_LEN > MMI_OP11_HS32_SHCT_LABEL_STRLEN_MAX) ?
             MMI_OP11_HS32_SHCT_LABEL_STRLEN_MAX : SRV_EMAIL_MAX_ACCT_NAME_LEN);
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    EMAIL_MSG_HANDLE msg_handle = 0;
    srv_email_inbox_index_msg_struct msg_info_array[MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX];
    U32 count = MMI_OP11_HS32_SHCT_ITEM_COUNT_MAX, sub_len = 0;
    srv_email_msg_get_basic_info_struct *basic_info = NULL;
    srv_email_addr_struct *addr = NULL;
    applib_time_struct time_info = {0};
    WCHAR *sub = NULL;
    srv_email_acct_info_cache_struct *cache_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_UPDATE_EMAIL_SHCT_INFO, __LINE__);

    if (shct_id == -1)
    {
        shct_id = mmi_op11_hs32_email_get_shct_id_by_account((S32)acct_id);
        is_update = TRUE;
    }
    if (shct_id != -1)
    {
        shct_data_p = mmi_op11_hs32_get_shct_data_pointer(MMI_OP11_HS32_AP_EML, shct_id);
    }
    if (shct_data_p == NULL)    // revised {if}, return here
    {
        return;
    }

        /* fill the default data */
        shct_data_p->item_count = 0;
        cache_info = OslMalloc(sizeof(srv_email_acct_info_cache_struct));
        srv_email_acct_cache_get((EMAIL_ACCT_ID)shct_data_p->query_index, cache_info);
        mmi_wcscpy(account_name, cache_info->acct_name);
        OslMfree(cache_info);
        mmi_wcsncpy(shct_data_p->shct_label, account_name, acct_name_length);
        shct_data_p->shct_label[acct_name_length] = L'\0';
        shct_data_p->result_flag = MMI_OP11_HS32_RESULT_UPDATE;
        for (; index < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; index++)
        {
            if (email_hs_sct_info.acct_array[index].acct_id == (EMAIL_ACCT_ID)shct_data_p->query_index)
            {
                break;
            }
        }
        MMI_EXT_ASSERT((index < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX), 0, 0, 0);
    
        /* find account info */
        if (email_hs_sct_info.acct_array[index].valid)
        {
            if (email_hs_sct_info.acct_array[index].unread_count)
            {
                /* get data */
                result = srv_email_fldr_inbox_get_recent_list(
                            (EMAIL_ACCT_ID)shct_data_p->query_index,
                            0,
                            &count,
                            1,
                            0,
                            msg_info_array);
                if (result != SRV_EMAIL_RESULT_SUCC)
                {
                    /* get info fail */
                    email_hs_sct_info.acct_array[index].valid = TRUE;
                    email_hs_sct_info.acct_array[index].unread_count = 0;
                    if (!is_update)
                    {
                        shct_data_p->result_flag = MMI_OP11_HS32_RESULT_NOT_READY;
                        email_hs_sct_info.acct_array[index].is_requeired = TRUE;
                    }
                }
                else
                {
                    shct_data_p->item_count = email_hs_sct_info.acct_array[index].unread_count;
                    email_hs_sct_info.acct_array[index].is_requeired = FALSE;
                    basic_info = OslMalloc(sizeof(srv_email_msg_get_basic_info_struct));
                    addr = OslMalloc(sizeof(srv_email_addr_struct));
                    sub = OslMalloc(sizeof(WCHAR) * (MMI_EMAIL_MAX_SUBJ_LEN + 1));
                    /* fill data */
                // fill the unread msg data
                    for (; i < count; i++)
                    {
                        memset(basic_info, 0, sizeof(srv_email_msg_get_basic_info_struct));
                        memset(addr, 0, sizeof(srv_email_addr_struct));
                        memset(&time_info, 0, sizeof(time_info));
                        memset(sub, 0, sizeof(WCHAR) * (MMI_EMAIL_MAX_SUBJ_LEN + 1));
                        sub_len = 0;
                        chset = 0;
                        result = srv_email_msg_create(0, &msg_handle);
                        if (result != SRV_EMAIL_RESULT_SUCC)
                        {
                            shct_data_p->item_count = i;
                            break;
                        }
                        result = srv_email_msg_open(
                                    msg_handle,
                                    (EMAIL_ACCT_ID)shct_data_p->query_index,
                                    email_hs_sct_info.acct_array[index].fldr_id,
                                    msg_info_array[i].msg_id);
                        if (result != SRV_EMAIL_RESULT_SUCC)
                        {
                            srv_email_msg_destroy(msg_handle);
                            shct_data_p->item_count = i;
                            break;
                        }
                        result = srv_email_msg_get_basic_info(
                                    msg_handle,
                                    basic_info);
                        if (result != SRV_EMAIL_RESULT_SUCC)
                        {
                            srv_email_msg_destroy(msg_handle);
                            shct_data_p->item_count = i;
                            break;
                        }
                        result = srv_email_msg_get_sender(
                                    msg_handle,
                                    addr);
                        if (result != SRV_EMAIL_RESULT_SUCC)
                        {
                            srv_email_msg_destroy(msg_handle);
                            shct_data_p->item_count = i;
                            break;
                        }
                        if (MMI_EMAIL_MAX_SUBJ_LEN > MMI_OP11_HS32_SHCT_CONTENT_STRLEN_MAX)
                        {
                            sub_len = MMI_OP11_HS32_SHCT_CONTENT_STRLEN_MAX;
                        }
                        else
                        {
                            sub_len = MMI_EMAIL_MAX_SUBJ_LEN;
                        }
                        sub_len += 1;
                        result = srv_email_msg_get_subject(
                                    msg_handle,
                                    sub,
                                    &sub_len);
                        if (result != SRV_EMAIL_RESULT_SUCC)
                        {
                            srv_email_msg_destroy(msg_handle);
                            shct_data_p->item_count = i;
                            break;
                        }
                        srv_email_msg_destroy(msg_handle);
                        msg_handle = 0;
                        /* UID */
                        shct_data_p->item_uid[i] = msg_info_array[i].msg_id;
                        /* time */
                        applib_dt_utc_sec_2_mytime(msg_info_array[i].date, &time_info, MMI_FALSE);
                        shct_data_p->item_time[i].DayIndex = time_info.DayIndex;
                        shct_data_p->item_time[i].nDay = time_info.nDay;
                        shct_data_p->item_time[i].nHour = time_info.nHour;
                        shct_data_p->item_time[i].nMin = time_info.nMin;
                        shct_data_p->item_time[i].nMonth = time_info.nMonth;
                        shct_data_p->item_time[i].nSec = time_info.nSec;
                        shct_data_p->item_time[i].nYear = time_info.nYear;
                        /* name */
                        if (mmi_wcslen(addr->email_addr))
                        {
                        mmi_wcsncpy(shct_data_p->item_name[i], addr->email_addr, MMI_OP11_HS32_SHCT_NAME_STRLEN_MAX);
                        }
                        else
                    {   /* empty data to let IDLE display text */
                            shct_data_p->item_name[i][0] = L'\0';
                        }
                        /* content */
                        if (sub_len)
                        {
                            mmi_wcscpy(shct_data_p->item_content[i], sub);
                        }
                        else
                    {   /* empty data to let IDLE display text */
                            shct_data_p->item_content[i][0] = L'\0';
                        }
                    }
                    OslMfree(basic_info);
                    OslMfree(addr);
                    OslMfree(sub);
                }
            }
        }
        else
        {
            if (!is_update)
            {
                /* get info fail */
                email_hs_sct_info.acct_array[index].valid = TRUE;
                email_hs_sct_info.acct_array[index].unread_count = 0;
                shct_data_p->result_flag = MMI_OP11_HS32_RESULT_NOT_READY;
                email_hs_sct_info.acct_array[index].is_requeired = TRUE;
            }
        }
    mmi_op11_hs32_answer_shct_data(MMI_OP11_HS32_AP_EML, shct_id, shct_data_p);
}

// this function called when user choose {set} in HS.account.list
void mmi_email_hs_pre_set_shct_acct(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_PRE_SET_SHCT_ACCT, __LINE__);

    if (!mmi_email_smgr_show_ui_check(NULL))
    {
        return;
    }

    email_hs_parent_id = GRP_ID_ROOT;
    email_hs_sct_info.curr_select_acct_index = index;
    result = srv_email_acct_get_num(&count);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        mmi_email_util_display_error_popup(0, result);
        return;
    }
    if (count == 0)
    {
        mmi_email_lib_error_popup(STR_EMAIL_ERROR_CODE_ACCT_NOT_CONFIG_ID);
        return;
    }
    email_hs_set_grp_id = mmi_frm_group_create(
        email_hs_parent_id,
        GRP_ID_AUTO_GEN, 
        mmi_email_hs_acct_set_group_proc,
        NULL);
    mmi_frm_group_enter(email_hs_set_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_email_hs_entry_acct_set();
}


static mmi_ret mmi_email_hs_acct_set_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_ACCT_SET_GROUP_PROC, evt->evt_id);
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            email_hs_set_grp_id = 0;
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


static void mmi_email_hs_entry_acct_set(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 *nStrItemList[MMI_EMAIL_MAX_ACCTS];
    U32 count = 0;
    U8 *gui_buffer;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    srv_email_acct_info_cache_struct *cache_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_ENTRY_ACCT_SET, __LINE__);

    if (!mmi_frm_scrn_enter(
            email_hs_set_grp_id,
            SCR_ID_EMAIL_HS_SCT_ACCT,
            NULL,
            mmi_email_hs_entry_acct_set,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    email_hs_selected_index = 0;
    srv_email_acct_get_num(&count);
    if (count == 0) // check SRV account again
    {
        mmi_email_lib_error_popup(STR_EMAIL_ERROR_CODE_ACCT_NOT_CONFIG_ID);
        mmi_frm_group_close(email_hs_set_grp_id);
        return;
    }
    result = srv_email_acct_get_acct_id(0, (S32*)(&count), email_hs_acct_id_array);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        mmi_email_util_display_error_popup(0, result);
        mmi_frm_group_close(email_hs_set_grp_id);
        return;
    }
    memset(email_hs_acct_name, 0, sizeof(email_hs_acct_name));
    cache_info = OslMalloc(sizeof(srv_email_acct_info_cache_struct));
    for (; i < count; i++)
    {   // fill account list data
        srv_email_acct_cache_get(email_hs_acct_id_array[i], cache_info);
        mmi_wcscpy(email_hs_acct_name[i], cache_info->acct_name);
        nStrItemList[i] = (U8*)email_hs_acct_name[i];
    }
    OslMfree(cache_info);
    RegisterHighlightHandler(mmi_email_hs_hilit_acct_handler);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory53Screen(
        STR_EMAIL_EMAIL_ACCTS_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        count,
        nStrItemList,
        (U16*)gIndexIconsImageList,
        NULL,
        0,
        (S32)email_hs_selected_index,
        gui_buffer);
    SetLeftSoftkeyFunction(mmi_email_hs_acct_set_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_email_hs_acct_set_lsk, KEY_EVENT_UP);
}


static void mmi_email_hs_acct_set_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_ACCT_SET_LSK, __LINE__);

    for (; index < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; index++)
    {
        if (email_hs_sct_info.acct_array[index].acct_id ==
            email_hs_acct_id_array[email_hs_selected_index])
        {   // this account already exists
            mmi_email_lib_error_popup(STR_EMAIL_ACCT_SELECTED_ID);
            return;
        }
    }
    // fill account info
    if (mmi_email_hs_get_acct_unread_count(
            email_hs_acct_id_array[email_hs_selected_index],
            &email_hs_sct_info.acct_array[email_hs_sct_info.curr_select_acct_index].unread_count,
            &email_hs_sct_info.acct_array[email_hs_sct_info.curr_select_acct_index].fldr_id))
    {
        mmi_op11_hs32_get_eml_account_after_select(email_hs_acct_id_array[email_hs_selected_index]);
        email_hs_sct_info.acct_array[email_hs_sct_info.curr_select_acct_index].valid = TRUE;
        email_hs_sct_info.acct_array[email_hs_sct_info.curr_select_acct_index].acct_id =
            email_hs_acct_id_array[email_hs_selected_index];
        email_hs_sct_info.acct_array[email_hs_sct_info.curr_select_acct_index].is_requeired = FALSE;
        mmi_email_hs_save_acct_info();  // flush to file
        mmi_frm_group_close(email_hs_set_grp_id);
    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }
}

// called by HS, to remove the selected account
void mmi_email_hs_remove_shct_acct(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_REMOVE_SHCT_ACCT, __LINE__);

    if (!mmi_email_smgr_show_ui_check(NULL))
    {
        return;
    }

    // make selected account invalid
    email_hs_sct_info.acct_array[index].acct_id = 0;
    email_hs_sct_info.acct_array[index].fldr_id = 0;
    email_hs_sct_info.acct_array[index].unread_count = 0;
    email_hs_sct_info.acct_array[index].valid = FALSE;
    mmi_email_hs_save_acct_info();
}

// called internal (eg. the shortcut account not valid)
void mmi_email_hs_remove_shct_acct_by_id(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_REMOVE_SHCT_ACCT_BY_ID, __LINE__);

    for (; index < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; index++)
    {
        if (email_hs_sct_info.acct_array[index].acct_id == acct_id)
        {
            email_hs_sct_info.acct_array[index].acct_id = 0;
            email_hs_sct_info.acct_array[index].fldr_id = 0;
            email_hs_sct_info.acct_array[index].unread_count = 0;
            email_hs_sct_info.acct_array[index].valid = FALSE;
            mmi_email_hs_save_acct_info();
        }
    }
}


static void mmi_email_hs_save_acct_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID acct_id_array[MMI_OP11_HS32_AP_EML_ACCOUNT_MAX];
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_SAVE_ACCT_INFO, __LINE__);

    for (; index < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; index++)
    {
        acct_id_array[index] = email_hs_sct_info.acct_array[index].acct_id;
    }
    // update the selected account to file
    mmi_email_hs_write_shortcut_item(acct_id_array);
}

// called by HS, for {write Email}
void mmi_email_hs_entry_comp_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_ENTRY_COMP_SELECT, __LINE__);

    if (!mmi_email_smgr_show_ui_check(NULL))
    {
        return;
    }

    email_hs_is_inbox_select = FALSE;
    email_hs_parent_id = GRP_ID_ROOT;
    mmi_email_hs_entry_select();
}

// indicator click callback function
void mmi_email_hs_entry_inbox_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_ENTRY_INBOX_SELECT, __LINE__);

    if (!mmi_email_smgr_show_ui_check(NULL))
    {
        return;
    }

    email_hs_is_inbox_select = TRUE;
    email_hs_parent_id = GRP_ID_ROOT;
    mmi_email_hs_entry_select();

}

// determined show shortcut account list or choose the single account
static void mmi_email_hs_entry_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    EMAIL_ACCT_ID acct_id = 0;
    U32 count = 0;
    EMAIL_ACCT_ID acct_array[MMI_OP11_HS32_AP_EML_ACCOUNT_MAX];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_ENTRY_SELECT, __LINE__);

    if (mmi_email_hs_get_shct_acct_count() != 1)
    {
        count = mmi_email_hs_set_acct_select(acct_array);
        if (count == 0)
        {
            mmi_email_lib_error_popup(STR_EMAIL_ERROR_CODE_ACCT_NOT_CONFIG_ID);
            return;
        }
        email_hs_select_grp_id = mmi_frm_group_create(
            email_hs_parent_id,
            GRP_ID_AUTO_GEN, 
            mmi_email_hs_acct_sel_group_proc,
            NULL);
        mmi_frm_group_enter(email_hs_select_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_email_hs_entry_acct_select_list();  // list
    }
    else
    {
        for (; i < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; i++)
        {
            if (email_hs_sct_info.acct_array[i].acct_id != 0)
            {
                acct_id = email_hs_sct_info.acct_array[i].acct_id;
                break;
            }
        }
        email_hs_parent_id = GRP_ID_ROOT;
        mmi_email_hs_entry_select_single(acct_id);  // single
    }
}


static mmi_ret mmi_email_hs_acct_sel_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_ACCT_SEL_GROUP_PROC, evt->evt_id);

    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            email_hs_select_grp_id = 0;
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}

// show the shortcut account list
static void mmi_email_hs_entry_acct_select_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    EMAIL_ACCT_ID acct_array[MMI_OP11_HS32_AP_EML_ACCOUNT_MAX];
    U8 *nStrItemList[MMI_OP11_HS32_AP_EML_ACCOUNT_MAX];
    U32 count = 0;
    U8 *gui_buffer;
    srv_email_acct_info_cache_struct *cache_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_ENTRY_ACCT_SELECT_LIST, __LINE__);

    if (!mmi_frm_scrn_enter(
            email_hs_select_grp_id,
            SCR_ID_EMAIL_HS_ACCT_SEL,
            NULL,
            mmi_email_hs_entry_acct_select_list,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    email_hs_selected_index = 0;
    count = mmi_email_hs_set_acct_select(acct_array);
    memset(email_hs_acct_name, 0, sizeof(email_hs_acct_name));
    cache_info = OslMalloc(sizeof(srv_email_acct_info_cache_struct));
    for (; i < count; i++)
    {
        srv_email_acct_cache_get(acct_array[i], cache_info);
        mmi_wcscpy(email_hs_acct_name[i], cache_info->acct_name);
        nStrItemList[i] = (U8*)email_hs_acct_name[i];
    }
    OslMfree(cache_info);
    RegisterHighlightHandler(mmi_email_hs_hilit_acct_handler);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory53Screen(
        STR_EMAIL_EMAIL_ACCTS_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        count,
        nStrItemList,
        (U16*)gIndexIconsImageList,
        NULL,
        0,
        (S32)email_hs_selected_index,
        gui_buffer);
    SetLeftSoftkeyFunction(mmi_email_hs_acct_select_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_email_hs_acct_select_lsk, KEY_EVENT_UP);
}


static void mmi_email_hs_hilit_acct_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_HILIT_ACCT_HANDLER, __LINE__);

    email_hs_selected_index = (U8)index;
}


static void mmi_email_hs_acct_select_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, index = 0;
    EMAIL_ACCT_ID acct_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_ACCT_SELECT_LSK, __LINE__);

    for (; i < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; i++)
    {
        if (email_hs_sct_info.acct_array[i].acct_id != 0)
        {
            if (index == email_hs_selected_index)
            {   // get the hilighted account id
                acct_id = email_hs_sct_info.acct_array[i].acct_id;
                break;
            }
            else
            {
                index++;
            }
        }
    }
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */
    email_hs_parent_id = GRP_ID_ROOT;
    mmi_email_hs_entry_select_single(acct_id);
    mmi_frm_group_close(email_hs_select_grp_id);
}


static void mmi_email_hs_entry_select_single(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_ENTRY_SELECT_SINGLE, __LINE__);

    if (email_hs_is_inbox_select)
    {
        mmi_email_app_entry_inbox_by_acct(acct_id);
    }
    else
    {   // shortcut account list selected
        mmi_email_app_entry_comp(acct_id, GRP_ID_ROOT);
    }
}


void mmi_email_get_account_name_by_id(EMAIL_ACCT_ID acct_id, WCHAR *name, U16 buff_len_in_ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 length = 0;
    srv_email_acct_info_cache_struct *cache_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_GET_ACCOUNT_NAME_BY_ID, __LINE__);

    if (name && buff_len_in_ucs2)
    {
        cache_info = OslMalloc(sizeof(srv_email_acct_info_cache_struct));
        length = (buff_len_in_ucs2 < SRV_EMAIL_MAX_ACCT_NAME_LEN) ? buff_len_in_ucs2 : SRV_EMAIL_MAX_ACCT_NAME_LEN;
        memset(name, 0, sizeof(name));
        srv_email_acct_cache_get(acct_id, cache_info);
        mmi_wcsncpy(name, cache_info->acct_name, (S32)length);
        OslMfree(cache_info);
    }
}

// compute the num of shortcut account 
static U32 mmi_email_hs_get_shct_acct_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0, index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_GET_SHCT_ACCT_COUNT, __LINE__);

    for (; index < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; index++)
    {
        if (email_hs_sct_info.acct_array[index].acct_id != 0)
        {
            count++;
        }
    }
    return count;
}

// get shortcut account id(s)
static U32 mmi_email_hs_set_acct_select(EMAIL_ACCT_ID *acct_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0, index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_HS_SET_ACCT_SELECT, __LINE__);

    memset(acct_array, 0, MMI_OP11_HS32_AP_EML_ACCOUNT_MAX * sizeof(EMAIL_ACCT_ID));
    for (; index < MMI_OP11_HS32_AP_EML_ACCOUNT_MAX; index++)
    {
        if (email_hs_sct_info.acct_array[index].acct_id != 0)
        {
            acct_array[count++] = email_hs_sct_info.acct_array[index].acct_id;
        }
    }
    return count;
}
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */


#ifdef __OP12__
/*****************************************************************************
 * FUNCTION 
 *  mmi_email_vf_set_flag
 * DESCRIPTION 
 *  mmi email vf set flag
 * PARAMETERS 
 *  BOOL is_show
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_vf_set_flag(BOOL is_show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_VF_SET_FLAG, is_show);
    can_show_vf_list = is_show; // whether softnote needed
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_vf_get_flag
 * DESCRIPTION 
 *  mmi email vf get flag
 * PARAMETERS 
 *  void
 * RETURNS 
 *  BOOL 
*****************************************************************************/
BOOL mmi_email_vf_get_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_VF_GET_FLAG, can_show_vf_list);
    return can_show_vf_list;    // for nmgr
}

// for nmgr to query softnote data

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_vf_nmgr_query
 * DESCRIPTION 
 *  mmi email vf nmgr query
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_vf_nmgr_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_info_struct info;
    WCHAR str_buff[20];
    U32 unread_num = mmi_email_get_unread_count();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_VF_NMGR_QUERY, __LINE__);

    if (unread_num)
    {
        memset(str_buff, 0, sizeof(str_buff));
        if (unread_num == 1)
        {
            kal_wsprintf(str_buff, "%u %w", unread_num, (WCHAR*)GetString(STR_EMAIL_NEW_EMAIL_ID));
        }
        else
        {
            kal_wsprintf(str_buff, "%u %w", unread_num, (WCHAR*)GetString(STR_EMAIL_NEW_EMAILS_ID));
        }
        info.total_num = unread_num;
        info.idle_text1 = (CHAR*)str_buff;
    }
    else
    {
        info.total_num = 0;
        info.idle_text1 = NULL;
    }
    info.idle_text2 = NULL;
    info.image = 0;
    info.left_softkey = 0;
    info.user_data = NULL;
    info.icon = IMG_EMAIL_SINGLE_LIST_UNREAD_ID;

    mmi_nmgr_answer(
        MMI_NMGR_APP_EMAIL,
        MMI_NMGR_RESULT_OK,
        &info,
        mmi_email_nmgr_event_list_entry_inbox); // set proc function
}


/*****************************************************************************
* FUNCTION
*  mmi_email_nmgr_event_list_entry_inbox
* DESCRIPTION
*  Handler of VF event list to entry Email Inbox
* PARAMETERS
*  user_data       [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_nmgr_event_list_entry_inbox(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_NMGR_EVENT_LIST_ENTRY_INBOX, __LINE__);
    mmi_email_app_entry_inbox();
}

#endif /* __OP12__ */


#ifdef __MMI_OP12_TOOLBAR__


/*****************************************************************************
 * FUNCTION
 *  mmi_tb_evnt_query_email
 * DESCRIPTION
 *  Toolbar registered callback
 * PARAMETERS
 *  num         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tb_evnt_query_email(S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_TB_EVNT_QUERY_EMAIL, __LINE__);
    MMI_EXT_ASSERT((num <= MMI_TB_MAX_NEW_MESSAGE_NUM), 0, 0, 0);
    if (srv_email_get_srv_init_state() != SRV_EMAIL_INIT_STATE_READY ||
        !mmi_email_is_drive_valid(srv_email_get_drive()))
    {
        email_tb_status = MMI_TB_RESULT_NOT_READY;
    }
    else
    {
        email_tb_status = MMI_TB_RESULT_UPDATE;
    }
    mmi_email_tb_answer_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_tb_answer_handler
 * DESCRIPTION
 *  Email toolbar handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_tb_answer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_TB_ANSWER_HANDLER, __LINE__);
    if ((email_tb_status == MMI_TB_RESULT_NOT_READY) ||
        (mmi_email_get_unread_count() == 0))
    {
        /*
         * IDLE will store the last state to display the items,
         * so the status of Email can not be NOT_READY    
         */
        mmi_tb_evnt_answer(
            MMI_TB_EVNT_NEW_EMAIL,
            MMI_TB_RESULT_OK,
            0,
            0,
            NULL,
            NULL,
            NULL);
    }
    else
    {
        mmi_tb_evnt_struct *toolbar_data = NULL;
        U32 total_num = mmi_email_get_unread_count();
        toolbar_data = OslMalloc(sizeof(mmi_tb_evnt_struct));
        memset(toolbar_data, 0, (sizeof(mmi_tb_evnt_struct)));
        toolbar_data->is_time_present = FALSE;
        toolbar_data->icon = IMG_EMAIL_SINGLE_LIST_UNREAD_ID;
        if (total_num == 1)
        {
            kal_wsprintf(email_tb_string, "%u %w", total_num, GetString(STR_EMAIL_NEW_EMAIL_ID));
        }
        else
        {
            kal_wsprintf(email_tb_string, "%u %w", total_num, GetString(STR_EMAIL_NEW_EMAILS_ID));
        }
        toolbar_data->subject = (CHAR*)email_tb_string;
        mmi_tb_evnt_answer(
            MMI_TB_EVNT_NEW_EMAIL,
            MMI_TB_RESULT_OK,
            (S32)total_num,
            1,
            toolbar_data,
            mmi_email_tb_key_handler,
            NULL);
        OslMfree(toolbar_data);
    }
    email_tb_status = MMI_TB_RESULT_NOT_READY;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_tb_key_handler
 * DESCRIPTION
 *  Toolbar screen key handler
 * PARAMETERS
 *  key_code     [IN]    Key code
 *  key_type     [IN]    Key type
 *  user_data    [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_tb_key_handler(U16 key_code, U16 key_type, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_TB_KEY_HANDLER, key_code);
    switch (key_code)
    {
        case KEY_CSK:
            {
                mmi_email_app_entry_inbox();
            }
            break;
        case KEY_LSK:
            {
                mmi_email_tb_entry_opt();
            }
            break;
        case KEY_SEND:
            {
            }
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_tb_entry_opt
 * DESCRIPTION
 *  This function shows the option menu of the toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_tb_entry_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_TB_ENTRY_OPT, __LINE__);

    email_tb_option_grp_id =
        mmi_frm_group_create(
            GRP_ID_ROOT,
            GRP_ID_AUTO_GEN,
            mmi_email_tb_opt_proc,
            NULL);
    mmi_frm_group_enter(email_tb_option_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    email_tb_option_grp_id =
        cui_menu_create(
            email_tb_option_grp_id,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_OPTION,
            MENU_ID_EMAIL_VF_TB_OPT,
            MMI_FALSE,
            NULL);
    cui_menu_set_default_title(email_tb_option_grp_id, (WCHAR*)GetString(STR_GLOBAL_OPTIONS), get_image(GetRootTitleIcon(MENU_ID_EMAIL_MAIN)));
    cui_menu_run(email_tb_option_grp_id);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_tb_opt_proc
 * DESCRIPTION 
 *  mmi email tb opt proc
 * PARAMETERS 
 *  mmi_event_struct *evt
 * RETURNS 
 *  static mmi_ret 
*****************************************************************************/
static mmi_ret mmi_email_tb_opt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_TB_OPT_PROC, __LINE__);

    switch (menu_evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            email_tb_option_grp_id = 0;
            break;
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            break;
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_email_tb_opt_handler(menu_evt->highlighted_menu_id);
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_tb_opt_handler
 * DESCRIPTION
 *  This function is the menu item handler for the cascading menu of toolbar
 * PARAMETERS
 *  menu_id         [IN]        Menu ID
 * RETURNS
 *  TRUE if the command is handled; otherwise, FALSE to follow the 
 *  cascading menu rule.
 *****************************************************************************/
static void mmi_email_tb_opt_handler(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_TB_OPT_HANDLER, __LINE__);

    switch (menu_id)
    {
        case MENU_ID_EMAIL_VF_TB_VIEW:
            mmi_email_app_entry_inbox();
            break;
        case MENU_ID_EMAIL_VF_TB_TOOLBAR_SETTING:
            mmi_tb_entry_toolbar_setting();
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_tb_update_info
 * DESCRIPTION 
 *  mmi email tb update info
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_tb_update_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_TB_UPDATE_INFO, __LINE__);
    if (mmi_tb_is_enable())
    {
        email_tb_status = MMI_TB_RESULT_UPDATE;
        mmi_email_tb_answer_handler();
    }
}
#endif /* __MMI_OP12_TOOLBAR__ */


#endif /* __MMI_EMAIL__ */

