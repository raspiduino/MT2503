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
 *  RightsMgrUtil.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Rights Manager
 *
 * Author:
 * -------
 * -------
 * -------
 *============================================================================
 *          HISTORY
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * Include
 */
#include "MMI_include.h"
#ifdef __DRM_SUPPORT__
#include "RightsMgrGprot.h"
#include "RightsMgrProt.h"

#include "drm_gprot.h"
//#include "drm_msg.h"
#include "drm_memory.h"
#include "drm_ui.h"
#include "drm_util.h"
#include "drm_trace.h"

#include "app_mine.h"
#include "app_str.h"
//#include "ProtocolEvents.h"
//#include "FileManagerDef.h"
//#include "FileManagerGprot.h"

//#include "wapadp.h"
//#include "SimDetectionGprot.h"

//#include "CommonScreens.h"
//#include "SettingProfile.h"
//#include "ProfileGprots.h"
//#include "DLAgentResDef.h"
//#include "IdleAppProt.h"
//#include "BrowserGprots.h" /*  mmi_brw_app_deinit */
//#include "ScrLockerGprot.h"

#include "MMIDataType.h"
#include "fs_type.h"
#include "FileMgrGProt.h"
#include "drm_errcode.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "mmi_rp_app_rmgr_def.h"
#include "Unicodexdcl.h"
#include "drm_def.h"
#include "fs_func.h"
#include "kal_trace.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "CommonScreensResDef.h"
#include "fs_errcode.h"
#include "kal_public_api.h"
#include "FileMgrSrvGProt.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "gui_typedef.h"
#include "custom_mmi_default_value.h"
#include "wgui_categories_util.h"
#include "kal_internal_api.h"
#include "string.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "RightsMgrResDef.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "browser_api.h"
#include "mmi_frm_history_gprot.h"
#include "MMI_features.h"
#include "ProfilesSrvGprot.h"
#include "gui_data_types.h"
#include "wgui_categories_text_viewer.h"
#include "mmi_rp_app_downloadagent_def.h"
#include "RightsMgrSrv.h"

#include "NITZ.h"

#define RMGR_UTIL_TRC DRM_UI_DEBUG

/*
 * Structure
 */
typedef struct
{
#if defined(__MMI_RMGR_SEAMLESS_UNLOCK__) && defined(__MMI_BROWSER_2__)
    S32 sd_callback_id;
#endif
    mmi_rmgr_ri_callback result_callback;
    U16 *file_path;
    U16 *url;
    U16 *confirm_string;
    U16 icon;
    FS_HANDLE file_handle;
    MMI_BOOL is_activating;  /* only usable in __MMI_RMGR_SEAMLESS_UNLOCK__ */
    MMI_BOOL more;
    MMI_BOOL show_detail;
    U8 permission;
}rmgr_req_rights_struct;

typedef struct
{
    U16 *content_path;
}rmgr_ro_arrival_struct;

#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */ 

/*
 * Local
 */
/* *FORMATTER-DISABLE* */
static const mmi_fmgr_fs_error_info_struct mmi_rmgr_err_table[] =
{
    {DRM_RESULT_NON_DRM,             STR_GLOBAL_DRM_NON_DRM},
    {DRM_RESULT_FS_ERROR,            STR_GLOBAL_DRM_FS_ERROR},
    {DRM_RESULT_INVALID_FORMAT,      STR_GLOBAL_DRM_INVALID_FORMAT},
    {DRM_RESULT_NO_PERMISSION,       STR_GLOBAL_DRM_PROHIBITED},

#ifndef __MMI_SLIM_FILE_MANAGER__
    {DRM_RESULT_SIZE_TOO_BIG,        FMGR_FS_FILE_TOO_LARGE_TEXT},
    {DRM_RESULT_FILE_EXISTS,         FMGR_FS_FILE_EXISTS_TEXT},
#endif
    {DRM_RESULT_INVALID_PARA,        FMGR_FS_PARAM_ERROR_TEXT},
#ifndef __MMI_SLIM_FILE_MANAGER__   
    {DRM_RESULT_TOO_MANY_FILES,      FMGR_FS_TOO_MANY_FILES_TEXT},
#endif
    {DRM_RESULT_NOT_SUPPORT,         STR_GLOBAL_NOT_SUPPORTED},
    
    {DRM_RESULT_BAD_CONTENT_TYPE,    STR_GLOBAL_INVALID_FORMAT},
    {DRM_RESULT_INVALID_KEY,         STR_ID_DRM_INVALID_KEY},
    {DRM_RESULT_INVALID_RIGHT,       STR_ID_DRM_INVALID_RO},


    {DRM_RESULT_EOF,                 STR_ID_DRM_EOF},
    {DRM_RESULT_TRUNCATED,           STR_ID_DRM_TRUNCATED},
    {DRM_RESULT_BUSY,                STR_GLOBAL_BUSY_TRY_LATER},
    {DRM_RESULT_CANCELED,            FMGR_FS_ABORTED_ERROR_TEXT},

#if __DRM_V02__    
    {DRM_RESULT_KEY_NOT_FOUND,       STR_ID_DRM_KEY_NOT_FOUND},
    {DRM_RESULT_CERT_NOT_FOUND,      STR_ID_DRM_CERT_NOT_FOUND},
    {DRM_RESULT_CERT_ROOT_NOT_FOUND, STR_ID_DRM_CERT_ROOT_NOT_FOUND},
    {DRM_RESULT_CERT_EXPIRED,        STR_ID_DRM_CERT_EXPIRED},
    {DRM_RESULT_INVALID_CERT,        STR_ID_DRM_INVALID_CERT},
    {DRM_RESULT_DOMAIN_EXPIRED,      STR_ID_DRM_DOMAIN_EXPIRED},
    {DRM_RESULT_NEED_DOMAIN_UPGD,    STR_ID_DRM_NEED_DOMAIN_UPGD},
    {DRM_RESULT_INVALID_DRMTIME,     STR_ID_DRM_INVALID_DRMTIME},
    {DRM_RESULT_NETWORK_ERROR,       STR_ID_DRM_NETWORK_ERROR},
    {DRM_RESULT_DATABASE_ERROR,      STR_ID_DRM_DATABASE_ERROR},
    {DRM_RESULT_TIME_UNTRUSTED,      STR_ID_DRM_TIME_UNTRUSTED},
    {DRM_RESULT_DATA_NOT_FOUND,      STR_ID_DRM_NOT_FOUND},
    {DRM_RESULT_NO_MEMORY,           STR_ID_DRM_NO_MEMORY},
    {DRM_RESULT_NOT_ARCHIVE,         STR_ID_DRM_NOT_ARCHIVE},
    {DRM_RESULT_NOT_IN_DOMAIN,       STR_ID_DRM_NOT_IN_DOMAIN},
    {DRM_RESULT_NOT_REGISTERED,      STR_ID_DRM_NOT_REGISTERED},
    {DRM_RESULT_REGISTRATION_FAILED, STR_ID_DRM_REG_FAILED},
    {DRM_RESULT_JOIN_DOMAIN_FAILED,  STR_ID_DRM_DOMAIN_JOIN_FAILED},
    {DRM_RESULT_LEAVE_DOMAIN_FAILED, STR_ID_DRM_DOMAIN_LEAVE_FAILED},
#endif

    {DRM_RESULT_DB_LOCKED,           STR_ID_DRM_DB_LOCKED_BY_APP},
    {DRM_RESULT_NO_RIGHTS_SPACE,     STR_ID_DRM_NO_RIGHT_SPACE},
    {DRM_RESULT_UNKNOWN_ERROR,       STR_ID_DRM_PROCESS_ERROR},
    {0, 0}
};
/* *FORMATTER-ENABLE* */

static rmgr_req_rights_struct rmgr_req_ri_entry;

#ifdef __MTK_INTERNAL__
/* under construction !*/
#endif

static rmgr_ro_arrival_struct g_rmgr_arrival;

U8 rmgr_space_check_user = 1;

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_get_err_string
 * DESCRIPTION
 *  to provide string ID associated to error code
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
MMI_ID_TYPE mmi_rmgr_get_err_string(S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; mmi_rmgr_err_table[i].errorNo != 0; i++)
    {
        if (mmi_rmgr_err_table[i].errorNo == error)
        {
            return mmi_rmgr_err_table[i].stringId;
        }
    }

    return STR_ID_DRM_PROCESS_ERROR;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_ucs2cat_secure
 * DESCRIPTION
 * PARAMETERS
 *  strDestination      [?]         
 *  strSource           [IN]        
 *  destSize            [IN]        
 * RETURNS
 *****************************************************************************/
S8 *mmi_rmgr_ucs2cat_secure(S8 *strDestination, const S8 *strSource, S32 destSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n = mmi_ucs2strlen(strDestination);

    destSize = destSize / 2;

    if (destSize - n - 1 <= 0)
    {
        return NULL;
    }

    return mmi_ucs2ncat(strDestination, strSource, destSize - n - 1 );
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_space_check
 * DESCRIPTION
 *  remaining space check function
 * PARAMETERS
 *  void
 * RETURNS
 *  0: do not enter ro list
 *  1: enter ro list
 *****************************************************************************/
U8 mmi_rmgr_space_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_rmgr_db_check_status() && rmgr_space_check_user)
    {
#ifdef __DRM_MTK__
        U32 size;
    #if defined(MAX_DRM_DB_SIZE) && defined(__FS_QM_SUPPORT__) && (MAX_DRM_DB_SIZE != 0)
        if ((size = FS_QmGetFree((BYTE *)DRM_DEFAULT_APP_PATH)) < DRM_MIN_FS_SIZE)
        {
            RMGR_UTIL_TRC(
                "[RMGR] mmi_rmgr_space_check",
                (TRACE_GROUP_UI, RMGR_UTIL_SPACE_CHECK, size, DRM_MIN_FS_SIZE));
            return 1;
        }
        RMGR_UTIL_TRC("[RMGR] mmi_rmgr_space_check", (TRACE_GROUP_UI, RMGR_UTIL_SPACE_CHECK, size, DRM_MIN_FS_SIZE));
    #else /* defined(MAX_DRM_DB_SIZE) && defined(__FS_QM_SUPPORT__) && (MAX_DRM_DB_SIZE != 0) */ 
        if ((size = FS_GetFolderSize(DRM_PATH, FS_COUNT_IN_CLUSTER, NULL, 0)) >= 256)
        {
            RMGR_UTIL_TRC("[RMGR] mmi_rmgr_space_check", (TRACE_GROUP_UI, RMGR_UTIL_SPACE_CHECK, size, 256));
            return 1;
        }
        RMGR_UTIL_TRC("[RMGR] mmi_rmgr_space_check", (TRACE_GROUP_UI, RMGR_UTIL_SPACE_CHECK, size, 256));
    #endif /* defined(MAX_DRM_DB_SIZE) && defined(__FS_QM_SUPPORT__) && (MAX_DRM_DB_SIZE != 0) */ 

    #else /* __DRM_MTK__ */ 
        S32 dbsize, dbmax;
        dbsize = DRM_get_ro_dbsize(&dbmax);

        RMGR_UTIL_TRC("[RMGR] mmi_rmgr_space_check", (TRACE_GROUP_UI, RMGR_UTIL_SPACE_CHECK, dbsize, dbmax));

        if (dbsize > 0 && (dbmax - dbsize < DRM_MIN_FS_SIZE))
        {
            return 1;
        }
    #endif
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_space_check_cancel
 * DESCRIPTION
 *  To cancel space check
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_space_check_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_space_check_cancel", (TRACE_GROUP_UI, RMGR_UTIL_SPACE_CHECK_CANCEL));

    rmgr_space_check_user = 0;

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_entry_db_check
 * DESCRIPTION
 *  confrim to enter ro list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_entry_db_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*mmi_display_popup_confirm_SG*/
     {
		mmi_confirm_property_struct arg;
		mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
		arg.softkey[0].str = (WCHAR *)GetString(STR_GLOBAL_YES);
		arg.softkey[2].str = (WCHAR *)GetString(STR_GLOBAL_NO);
		arg.callback = (mmi_proc_func)mmi_rmgr_db_check_conf_callback;
		mmi_confirm_display((WCHAR *)GetString(STR_ID_RMGR_SPACE_PROMPT), MMI_EVENT_QUERY, &arg);
      }
	/*mmi_display_popup_confirm(
                (UI_string_type)GetString(STR_GLOBAL_YES),
                (PU8)GetImage(IMG_GLOBAL_YES),
                (UI_string_type)GetString(STR_GLOBAL_NO),
                (PU8)GetImage(IMG_GLOBAL_NO),
                (UI_string_type)GetString(STR_ID_RMGR_SPACE_PROMPT),
                MMI_EVENT_QUERY);

        SetRightSoftkeyFunction(mmi_rmgr_space_check_cancel, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_rmgr_list_ro_entry_main, KEY_EVENT_UP);
        SetKeyHandler(mmi_rmgr_space_check_cancel, KEY_END, KEY_EVENT_DOWN);*/
    }

mmi_ret mmi_rmgr_db_check_conf_callback(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alertEvt = (mmi_alert_result_evt_struct *)evt;
	
    if (alertEvt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alertEvt->result)
        {
        case MMI_ALERT_CNFM_YES:
	    rmgr_list_ro_cntx.refresh = MMI_TRUE;
	    mmi_rmgr_p->current_idx = 0;
            mmi_rmgr_list_ro_entry_main();
           rmgr_space_check_user = 0;
	    break;
        case MMI_ALERT_CNFM_CANCEL:
        case MMI_ALERT_CNFM_NO:
            mmi_rmgr_space_check_cancel();
            break;
	  default:
	  	break;
        }
    }
    return MMI_RET_OK;
}


#define __RMGR_UT__
#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */


#define __RMGR_UTIL_DETAIL__

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_populate_drm_constraint
 * DESCRIPTION
 *  populate the constraint detail
 * PARAMETERS
 *  constraint          [?]         
 *  permission          [IN]        
 *  data                [?]         
 *  buf_size            [IN]        
 *  simple_format       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_populate_drm_constraint(
        drm_constraint_struct *constraint,
        U8 permission,
        U8 *data,
        S32 buf_size,
        MMI_BOOL simple_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 tmp[64]; /* For 10^10 <count> constraint */
    applib_time_struct t;
    S32 start = 0, end = 0;
	U8 *buff = data;
	applib_time_struct time_check;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (constraint->status != DRM_STATUS_RIGHTS_PRESENT &&
        constraint->status != DRM_STATUS_UNTRUSTED_TIME &&
        constraint->status != DRM_STATUS_RIGHTS_IN_FUTURE)
    {
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY), buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_GLOBAL_INVALID), buf_size);
        //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        return;
    }

    if (constraint->type & DRM_CONSTRAINT_DATETIME)
    {
        /* two constraint
            |-------------------|
                      |----------------|
            A         B         C      D
            We should show B ~ C  */

        if ((constraint->type & DRM_CONSTRAINT_INTERVAL) && constraint->start_intv != 0)
        {
            if (constraint->start_time <= constraint->start_intv)
            {
                start = constraint->start_intv;
            }
            else
            {
                start = constraint->start_time;
            }

            /* there is a limitation time in end_time, or we just use the end_intv */
            if (constraint->end_time <= constraint->end_intv && constraint->end_time!=0)
            {
                end = constraint->end_time;
            }
            else
            {
                end = constraint->end_intv;
            }
        }
        else
        {
            start = constraint->start_time;
            end = constraint->end_time;
        }
    }
    else if (constraint->type & DRM_CONSTRAINT_INTERVAL)
    {
        if (constraint->interval <= 0)
        {
            start = 0;
            end = 0;
        }
        else
        {
            start = constraint->start_intv;
            end = constraint->end_intv;
        }
    }

#ifdef __MMI_RMGR_SIMPLE_DETAILS__
    if (simple_format)
    {
    	#if __DRM_V02__
        if (constraint->status == DRM_STATUS_UNTRUSTED_TIME)
        {
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8)GetString(STR_ID_DRM_TIME_UNTRUSTED), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        }
        /* unlimited constraint or unlimited time anymore */
        else 
      #endif  
        if (constraint->type == DRM_CONSTRAINT_NONE ||
            (end == 0 && (constraint->type == DRM_CONSTRAINT_DATETIME)))
        {
			mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size); //Akhil
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_LEFT_COUNT), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_LEFT_TIME), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        }
        else
        {
            if (constraint->type & DRM_CONSTRAINT_COUNT)
            {
				mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size); //Akhil
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_LEFT_COUNT), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);

                if (constraint->used_count > 0xFFFFFFFF)
                {
                    kal_wsprintf(
                        (WCHAR*) tmp,
                        "%u%09u\n",
                        (kal_uint32) (constraint->used_count / 1000000000),
                        (kal_uint32) (constraint->used_count % 1000000000));
                }
                else
                {
                     kal_wsprintf((WCHAR*)tmp, "%u\n", (kal_uint32)constraint->used_count);
                }

                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
            }

          if (constraint->type & (DRM_CONSTRAINT_INTERVAL | DRM_CONSTRAINT_ACCUMULATED | DRM_CONSTRAINT_DATETIME))
          {
            S32 left = 0;
			if(DRM_get_secure_time((applib_time_struct *)&t))
			{
            if (end > 0)
            {
                left = end - applib_dt_mytime_2_utc_sec(&t, KAL_FALSE);
            }

            if (constraint->type & DRM_CONSTRAINT_INTERVAL)
            {
                /* not start to use */
                if (constraint->start_intv == 0 && constraint->end_intv == 0)
                {
                    if (left <= 0 || left > constraint->interval)
                    {
                        left = constraint->interval;
                    }
                }
            }

            #ifdef __DRM_V02__
            if (constraint->type & DRM_CONSTRAINT_ACCUMULATED)
            {
                if (left <= 0 || left > constraint->accum_dur)
                {
                    left = constraint->accum_dur;
                }
            }
            #endif

            if (left > 0)
            {
				mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8)GetString(STR_ID_RMGR_DETAIL_LEFT_TIME), buf_size);

                if (left > DT_SEC_PER_DAY)
                {
                    /* >= 24 hours */
                    kal_wsprintf((WCHAR*)tmp, " %d ", left/DT_SEC_PER_DAY);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_LEFT_DAYS), buf_size);
                }
                else if (left > DT_SEC_PER_HOUR)
                {
                    /* < 24 hours, >= 1 hours */
                    kal_wsprintf((WCHAR*)tmp, " %d ", left/DT_SEC_PER_HOUR);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_LEFT_HOURS), buf_size);
                }
                else
                {
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                    /* < 1 hours */
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_LEFT_LAST), buf_size);
                }
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            }
			else
			{
				memset(buff, 0, buf_size);
				mmi_rmgr_ucs2cat_secure((PS8) buff, (PS8) GetString(STR_ID_RMGR_REQ_RITS_EXPIRE_DETAIL), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) buff, (PS8) L"\n", buf_size);
			}
          }
        }
    }
    }
    else
#endif /* __MMI_RMGR_SIMPLE_DETAILS__ */
    {
		 mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        switch(permission)
        {
            case DRM_PERMISSION_PLAY:
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_DRM_PLAY), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                break;
            case DRM_PERMISSION_DISPLAY:
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_DRM_DISPLAY), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                break;
            case DRM_PERMISSION_EXECUTE:
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_DRM_EXECUTE), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                break;
            case DRM_PERMISSION_PRINT:
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_DRM_PRINT), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                break;
#if __DRM_V02__
            case DRM_PERMISSION_EXPORT:
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_DRM_EXPORT), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                break;
#endif
            default:
                break;
        }

#if __DRM_V02__
        if (constraint->status == DRM_STATUS_UNTRUSTED_TIME)
        {
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8)GetString(STR_ID_DRM_TIME_UNTRUSTED), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        }
        else
#endif
        {

			
            if (constraint->type != DRM_CONSTRAINT_NONE)
            {
                if (constraint->type & DRM_CONSTRAINT_COUNT)
                {
		    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_COUNT), buf_size);
                    if (constraint->total_count > 0xFFFFFFFF)
                    {
                        if (constraint->used_count > 0xFFFFFFFF)
                        {
                            kal_wsprintf(
                                (WCHAR*) tmp,
                                "\n%u%09u/%u%09u",
                                (kal_uint32) (constraint->used_count / 1000000000),
                                (kal_uint32) (constraint->used_count % 1000000000),
                                (kal_uint32) (constraint->total_count / 1000000000),
                                (kal_uint32) (constraint->total_count % 1000000000));
                        }
                        else
                        {
                            kal_wsprintf(
                                (WCHAR*) tmp,
                                "\n%u/%u%09u",
                                (kal_uint32)constraint->used_count,
                                (kal_uint32) (constraint->total_count / 1000000000),
                                (kal_uint32) (constraint->total_count % 1000000000));
                        }

                    }
                    else
                    {
                        kal_wsprintf(
                            (WCHAR*) tmp,
                            "\n%u/%u",
                            (kal_uint32) constraint->used_count,
                            (kal_uint32) constraint->total_count);
                    }

                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
                }

            #ifdef __DRM_V02__
                if (constraint->type & DRM_CONSTRAINT_ACCUMULATED)
                {
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_ACCUMULATED), buf_size);
                    kal_wsprintf((WCHAR*)tmp, "\n%d\n", constraint->accum_dur);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
                }

                if (constraint->type & DRM_CONSTRAINT_TIMEDCOUNT)
                {
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_TIMEDCOUNT), buf_size);
                    kal_wsprintf((WCHAR*)tmp, "\n %d ", constraint->timed_count);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_TIMEDCOUNT_TIME), buf_size);
                    kal_wsprintf((WCHAR*)tmp, " %d ", constraint->period);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_SEC), buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                }
            #endif /* __DRM_V02__ */

if(DRM_get_secure_time((applib_time_struct *)&time_check))
{
                if (start > 0)
                {
		    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_START), buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                    mmi_dt_utc_sec_2_mytime(start, &t, MMI_FALSE);
                    date_string((MYTIME *)&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                    time_string((MYTIME *)&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                   // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                }

                if (end > 0)
                {
		    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_END), buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                    mmi_dt_utc_sec_2_mytime(end, &t, MMI_FALSE);
                    date_string((MYTIME *)&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                    time_string((MYTIME *)&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                  //  mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                }
}

            }
            else
            {
				mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_populate_drm_info_aux
 * DESCRIPTION
 *
 * PARAMETERS
 *  path                [?]         
 *  app_perm            [IN]        
 *  data                [?]         [?]
 *  buf_size            [IN]        
 *  ref                 [IN]        
 *  permission(?)       [IN]        
 *  rights          [?](?)
 * RETURNS
 *
 *****************************************************************************/
MMI_BOOL mmi_rmgr_populate_drm_info_aux(U16 *path, U8 app_perm, U8 *data, S32 buf_size, S32 ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE input = FS_ERROR_RESERVED;
    S32 cons_ret = DRM_RESULT_NON_DRM;
    MMI_BOOL result = MMI_FALSE, flag = MMI_TRUE;
    U8 permission;
    drm_method_enum method;
    MMI_BOOL is_installable;
    MMI_BOOL is_printable;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DRM_MEM_START_EVAL

    if (ref < 0)
    {
        /* we use DRM_PERMISSION_PLAY first */
        input = DRM_open_file((kal_wchar*)path, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_PLAY);

        if (input < DRM_RESULT_OK)
        {
            result = MMI_FALSE;
            goto final;
        }

        method = DRM_get_object_method(input, NULL);
    }
    else
    {
        method = DRM_get_object_method_by_ref(ref, DRM_DB_GET_VALID);
    }

    if (method != DRM_METHOD_NONE)  /* 1. DRM file */
    {
        if (ref < 0)
        {
    #ifdef __DRM_V02__
            U16 *sepa = kal_wstrrchr(path, (kal_int32) '\\');
    #endif
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_RIGHT), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_PROTECTED), buf_size);

    #ifdef __DRM_V02__
            if (DRM_is_archive(input, NULL) && sepa &&
                app_ucs2_strnicmp((kal_int8*) (sepa - 4), (kal_int8*) L".odf\\", 5) != 0)
            {
                /* 1.1 Multi Part ODF */
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_MULTI_PART), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);

                result = MMI_FALSE;
                goto final;
            }
        #endif /* __DRM_V02__ */ 
            //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        }
    }
    else    /* 2. Not DRM file */
    {
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_RIGHT), buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNPROTECTED), buf_size);
       // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);

        result = MMI_FALSE;
        goto final;
    }

    if (method == DRM_METHOD_FORWARD_LOCK)
    {
        drm_constraint_struct cons;

        if (ref < 0)
        {
            DRM_get_constraint(input, NULL, DRM_PERMISSION_PLAY, &cons);
        }
        else
        {
            DRM_get_constraint_by_ref(ref, DRM_PERMISSION_PLAY, &cons);
        }

        if (cons.status == DRM_STATUS_RIGHTS_PRESENT)
        {
            /* 1.2 forward lock with right */
#ifdef __MMI_RMGR_SIMPLE_DETAILS__
            if (ref < 0)
            {
		mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8)GetString(STR_ID_RMGR_DETAIL_LEFT_COUNT), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8)GetString(STR_ID_RMGR_DETAIL_LEFT_TIME), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                if (app_perm == DRM_PERMISSION_EXECUTE)
                {
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_INSTALLABLE), buf_size);
                }
                else
                {
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNINSTALLABLE), buf_size);
                }
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);

                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNFORWARDABLE), buf_size);

               // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);

            }
            else
#endif /* __MMI_RMGR_SIMPLE_DETAILS__ */
            {
		mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED), buf_size);
               // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            }
        }
        else
        {
            /* 1.3 forward lock without right */
	    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_GLOBAL_INVALID), buf_size);
            //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        }

        result = MMI_FALSE;
        goto final;
    }


    permission = DRM_PERMISSION_PLAY;
    is_installable = is_printable = MMI_FALSE;

    do
    {
        if (app_perm != DRM_PERMISSION_ALL)
        {
            /* not in app_perm, we do not check this permission */
            if (app_perm & permission)
            {
                /* not first time in this loop, need to reopen file */
                if (ref < 0 && permission != DRM_PERMISSION_PLAY)
                {
                    DRM_close_file(input);
                    if (DRM_RESULT_OK > DRM_open_file(path, FS_READ_ONLY | FS_OPEN_SHARED, permission))
                    {
                        result = MMI_FALSE;
                        break;
                    }
                }
            }
            else
            {
                permission  = permission << 1;
                continue;
            }
        }

        if (permission &
            (DRM_PERMISSION_PLAY | DRM_PERMISSION_DISPLAY | DRM_PERMISSION_EXECUTE | DRM_PERMISSION_PRINT |
             DRM_PERMISSION_EXPORT))
        {
            drm_constraint_struct cons;
            memset(&cons, 0, sizeof(drm_constraint_struct));

            if (ref < 0)
            {
                cons_ret = DRM_get_constraint(input, NULL, permission, &cons);
            }
            else
            {
                cons_ret = DRM_get_constraint_by_ref(ref, permission, &cons);
            }

            if (cons_ret >= DRM_RESULT_OK &&
                (cons.status == DRM_STATUS_RIGHTS_PRESENT ||
                 cons.status == DRM_STATUS_UNTRUSTED_TIME || cons.status == DRM_STATUS_RIGHTS_IN_FUTURE))
            {
                /* 1.4 SD/CD/V2/PDCF with right */
                if (flag)
                {
#ifdef __MMI_RMGR_SIMPLE_DETAILS__
                    if (ref >=0)
#endif
                    {
	          	//ref value >=0 signifies that call is from licence list options.
			if(ref<0)
			{
			mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
			}
                        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY), buf_size);
                        //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                    }
                }

                if (ref < 0)    /* list in file manager or AP*/
                {
                #ifndef __MMI_RMGR_SIMPLE_DETAILS__
                    mmi_rmgr_populate_drm_constraint(&cons, (U8)permission, (U8*)data, buf_size, MMI_TRUE);
                #else /* __MMI_RMGR_SIMPLE_DETAILS__ */ 
                    if (permission == DRM_PERMISSION_PLAY || permission == DRM_PERMISSION_DISPLAY ||
                        permission == DRM_PERMISSION_EXECUTE)
                    {
                        mmi_rmgr_populate_drm_constraint(&cons, (U8)permission, (U8*)data, buf_size, MMI_TRUE);

                        /* This is the first permission for the content
                           If one content has the play or display permission, we will skip execute permission */
                        if (permission == DRM_PERMISSION_EXECUTE && flag == MMI_TRUE)
                        {
                            is_installable = MMI_TRUE;
                        }
                    }
                    else if (permission == DRM_PERMISSION_PRINT)
                    {
                        is_printable = MMI_TRUE;
                    }
                    else
                    {
                        break;
                    }
                #endif /* __MMI_RMGR_SIMPLE_DETAILS__ */ 
                }
                else /* list in right manager */
                {
                    mmi_rmgr_populate_drm_constraint(&cons, (U8)permission, (U8*)data, buf_size, MMI_FALSE);
                }

                flag = KAL_FALSE;
            }
        }
        permission = permission << 1;
    }
    while(permission < DRM_PERMISSION_EXPORT && permission <= app_perm);


    if (flag)
    {
        /* 1.5 SD/CD/V2/PDCF without right */
	mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY), buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_GLOBAL_INVALID), buf_size);
      // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
    }
#ifdef __MMI_RMGR_SIMPLE_DETAILS__
    else
    {
        if (ref < 0) /* list in file manager or AP*/
        {
            if (is_printable)
            {
				mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_PRINTABLE), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            }

            if (is_installable)
            {
				mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_INSTALLABLE), buf_size);
            }
            else
            {
				mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNINSTALLABLE), buf_size);
            }

            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);

            if (DRM_interdev_movable(0, path))
            {
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_FORWARDABLE), buf_size);
            }
            else
            {
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNFORWARDABLE), buf_size);
            }
          //  mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        }
    }
#endif /* __MMI_RMGR_SIMPLE_DETAILS__ */ 

final:
    if (ref < 0)
    {
        if (input >= 0)
        {
            DRM_close_file(input);
        }
    }
    else
    {
        DRM_free_ro_detail();
    }
    DRM_MEM_END_EVAL
    return result;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_populate_drm_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  path                [?]         
 *  app_perm            [IN]        
 *  data                [?]         [?]
 *  buf_size            [IN]        
 *  permission(?)       [IN]        
 *  rights          [?](?)
 * RETURNS
 *
 *****************************************************************************/

MMI_BOOL mmi_rmgr_populate_drm_info(U16 *path, U8 app_perm, U8 *data, S32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */   
   return mmi_rmgr_populate_drm_info_aux(path, app_perm, data, buf_size, -1);
}

#define __RMGR_ACTIVATE_FILE__

#ifdef __DRM_V02__

/*****************************************************************************
* FUNCTION
*   mmi_rmgr_activate_callback
* DESCRIPTION
*
* PARAMETERS
 *  serial      [IN]        
 *  result      [IN]        
* RETURNS
*   Void
*****************************************************************************/
void mmi_rmgr_activate_callback(U8 serial, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_activate_callback result = %d",
            (TRACE_GROUP_2, RMGR_UTIL_ACTIVATE_CALLBACK, result));

    if (result == DRM_RESULT_OK)
    {
        /* it should be an embedded RO */
        mmi_popup_display((WCHAR*) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
    }
    else if (result != DRM_RESULT_IN_PROGRESS)
    {
        if (result == DRM_RESULT_CANCELED)
        {
            mmi_popup_display((WCHAR*)GetString(FMGR_FS_ABORTED_ERROR_TEXT), MMI_EVENT_SUCCESS, NULL);
        }
        else
        {
            mmi_popup_display((WCHAR*)GetString(srv_fmgr_fs_error_get_string(result)), MMI_EVENT_FAILURE, NULL);
        }
    }

    if (rmgr_req_ri_entry.result_callback)
    {
        rmgr_req_ri_entry.result_callback(MMI_TRUE);
    }

    /* if we turn on seamless unlock, we need not delete processing screen
       when the browser is launched. We would delete processing screen
       in mmi_rmgr_unlock_session_callback or after we receive right */

#if defined(__MMI_RMGR_SEAMLESS_UNLOCK__) && defined(__MMI_BROWSER_2__)
    if (result != DRM_RESULT_IN_PROGRESS)
#endif
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_RMGR_ACTIVATE_PROCESS)
        {
            mmi_frm_scrn_close_active_id();
        }
        else
        {
            mmi_frm_scrn_close(GRP_ID_RMGR_MAIN, SCR_ID_RMGR_ACTIVATE_PROCESS);
        }
        mmi_rmgr_wipe_unlock_session();
    }
}


#endif


/*****************************************************************************
* FUNCTION
 *  mmi_rmgr_get_ro_bound_path
* DESCRIPTION
 *  To get content path
* PARAMETERS
*   void
* RETURNS
*   the content path
*****************************************************************************/
U16 *mmi_rmgr_get_ro_bound_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_rmgr_arrival.content_path;
}


/*****************************************************************************
* FUNCTION
*   mmi_rmgr_set_ro_bound_path
* DESCRIPTION
 *  To set content path
* PARAMETERS
*   path        [IN]    the content path
* RETURNS
*   Void
*****************************************************************************/
void mmi_rmgr_set_ro_bound_path(U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rmgr_arrival.content_path)
        drmt_mem_free(g_rmgr_arrival.content_path);

    g_rmgr_arrival.content_path = (U16*)drmt_mem_alloc((kal_wstrlen((kal_wchar*)path) + 1) * ENCODING_LENGTH);

    kal_wstrcpy((kal_wchar*)g_rmgr_arrival.content_path, (kal_wchar*)path);

}


/*****************************************************************************
* FUNCTION
*   mmi_rmgr_reset_ro_bound_path
* DESCRIPTION
 *  To reset content path
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
U8 mmi_rmgr_reset_ro_bound_path(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rmgr_arrival.content_path)
        drmt_mem_free(g_rmgr_arrival.content_path);

    g_rmgr_arrival.content_path = NULL;
    return 0;

}


#if defined(__MMI_RMGR_SEAMLESS_UNLOCK__) && defined(__MMI_BROWSER_2__)


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_sd_callback_usenow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_sd_callback_usenow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_receive_da_file(0, 0, 0, 0, g_rmgr_arrival.content_path, NULL, NULL);

    mmi_rmgr_reset_ro_bound_path(NULL);
}


/*****************************************************************************
* FUNCTION
*   mmi_rmgr_unlock_session_callback
* DESCRIPTION
 *  To delete progress screen when the browser need to show a page
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
void mmi_rmgr_unlock_session_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_unlock_session_callback", (TRACE_GROUP_UI, RMGR_UTIL_UNLOCK_SESSION_CALLBACK));

    /* browser link to web page , we need to clean processing screen
       and the unlock session */
     if (mmi_frm_scrn_get_active_id() == SCR_ID_RMGR_ACTIVATE_PROCESS)
        {
            mmi_frm_scrn_close_active_id();
        }
        else
        {
            mmi_frm_scrn_close(GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_PROCESS);
        }

    if (mmi_rmgr_unlock_session_on())
    {
        //ClearDelScrnIDCallbackHandler(SCR_ID_RMGR_ACTIVATE_PROCESS, NULL);

        DRM_cancel_sd_callback((kal_uint8)rmgr_req_ri_entry.sd_callback_id);
        mmi_rmgr_wipe_unlock_session();
    }
}

void mmi_rmgr_entry_use_confirm()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_enter(GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_USE_NOW_CONFIRM, NULL, mmi_rmgr_entry_use_confirm, MMI_FRM_FG_ONLY_SCRN))
   {
   
    guiBuffer = mmi_frm_scrn_get_gui_buf (GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_USE_NOW_CONFIRM);

    /* EntryNewScreen(SCR_ID_RMGR_USE_NOW_CONFIRM, NULL, NULL, NULL); */
    ShowCategory74Screen(
         STR_ID_DA_JOB_USE,
          rmgr_req_ri_entry.icon,
          STR_GLOBAL_YES,
          IMG_GLOBAL_YES,
          STR_GLOBAL_NO,
          IMG_GLOBAL_NO,
          (U8 *)rmgr_req_ri_entry.confirm_string,
          mmi_ucs2strlen((S8 *)rmgr_req_ri_entry.confirm_string),
          guiBuffer);

           SetLeftSoftkeyFunction(mmi_rmgr_sd_callback_usenow, KEY_EVENT_UP);
           SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_unlock_session_sd_cb
 * DESCRIPTION
 *  the callback function when the right incoming or timeout
 * PARAMETERS
 *  para    [IN]    parameter
 *  type    [IN]    result
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_rmgr_unlock_session_sd_cb(void *para, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_unlock_session_right_delivery_cb, %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_UNLOCK_SESSION_RIGHT_DELIVERY_CB, para, type));

    /* rights incoming or timeout, we need to clean browser and processing screen
       After all, we clean the unlock session data. */
    if (mmi_rmgr_unlock_session_on())
    {

        if (type != DRM_SD_EXPIRY_RIGHTS_ARRIVE)
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_RMGR_ACTIVATE_PROCESS)
            {
                mmi_popup_display((WCHAR*) GetString(FMGR_FS_TIMEOUT_TEXT), MMI_EVENT_FAILURE, NULL);
            }
        }
        else if (!rmgr_req_ri_entry.more)
        {
            if (FS_GetAttributes((WCHAR*)rmgr_req_ri_entry.file_path) >= FS_NO_ERROR)
            {
                U8 *guiBuffer;
                UI_string_type dest;
                UI_string_type src = (UI_string_type)app_ucs2_strrchr((kal_int8 *)rmgr_req_ri_entry.file_path, L'\\');
                UI_string_type offset =
                    (UI_string_type) app_ucs2_strrchr((kal_int8*) rmgr_req_ri_entry.file_path, L'.');

                if (src == NULL)
                {
                    src = rmgr_req_ri_entry.file_path;
                }

                if (offset)
                {
                    if (offset > src && ( app_ucs2_stricmp((kal_int8 *)offset, (kal_int8 *)L".mp3") == 0 ||
                                          app_ucs2_stricmp((kal_int8 *)offset, (kal_int8 *)L".mp2") == 0))
                    {
                        *offset = 0;
                    }
                    else
                    {
                        offset = NULL;
                    }
                }

                rmgr_req_ri_entry.confirm_string = (U16*) subMenuData;

                app_ucs2_strcpy((kal_int8 *)rmgr_req_ri_entry.confirm_string, (kal_int8 *)(src + 1));
                app_ucs2_strcat((kal_int8 *)rmgr_req_ri_entry.confirm_string, (kal_int8 *)GetString(STR_ID_RMGR_USE_NOW));
                mmi_rmgr_entry_use_confirm();
                mmi_rmgr_set_ro_bound_path(para);

                if (offset)
                {
                    *offset = L'.';
                }
            }
        }
        else
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_RMGR_ACTIVATE_PROCESS)
            {
                mmi_popup_display((WCHAR*) GetString(STR_ID_RMGR_ACTIVATE_COMPLETED), MMI_EVENT_SUCCESS, NULL);
            }
        }

        mmi_brw_app_deinit();

        mmi_rmgr_wipe_unlock_session();

        //ClearDelScrnIDCallbackHandler(SCR_ID_RMGR_ACTIVATE_PROCESS, NULL);
        mmi_frm_scrn_close(GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_PROCESS);
    }
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*   mmi_rmgr_resume_unlocking
* DESCRIPTION
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
void mmi_rmgr_resume_unlocking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_resume_unlocking",
            (TRACE_GROUP_UI, RMGR_UTIL_RESUME_UNLOCKING, mmi_rmgr_unlock_session_on()));

    if (mmi_rmgr_unlock_session_on())
    {
        //ClearDelScrnIDCallbackHandler(SCR_ID_RMGR_ACTIVATE_PROCESS, NULL);

        mmi_frm_scrn_close(GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_PROCESS);

        mmi_rmgr_entry_activate();
    }
}

/*****************************************************************************
* FUNCTION
*   mmi_rmgr_unlock_session_on
* DESCRIPTION
*  To tell unlock session is on or off
* PARAMETERS
*   Void
* RETURNS
*   TRUE of FALSE
*****************************************************************************/
MMI_BOOL mmi_rmgr_unlock_session_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return rmgr_req_ri_entry.is_activating;
}
#endif /* __MMI_RMGR_SEAMLESS_UNLOCK__ */

/*****************************************************************************
* FUNCTION
*   mmi_rmgr_clear_unlock_screen
* DESCRIPTION
 *  To clear all related screen, avoid reentry
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
void mmi_rmgr_clear_unlock_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Avoid reentry problem */
    mmi_frm_scrn_close(GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_CONFIRM);
    mmi_frm_scrn_close(GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_PROCESS);
    //DeleteScreenIfPresent(SCR_ID_RMGR_ACTIVATE_CONFIRM);
    //DeleteScreenIfPresent(SCR_ID_RMGR_ACTIVATE_PROCESS);
}

/*****************************************************************************
* FUNCTION
*   mmi_rmgr_unlock_session_del_cb
* DESCRIPTION
 *  To delete progress screen
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
void mmi_rmgr_activate_del_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_unlock_session_del_cb",
            (TRACE_GROUP_UI, RMGR_UTIL_UNLOCK_SESSUION_DEL_CB));

/* We cannot cancel the request right procedure in normal scenario
   But under semaless unlock, we hide the browser at background,
   we can deinit it and cancel the request right procedure */

#if defined(__MMI_RMGR_SEAMLESS_UNLOCK__) && defined(__MMI_BROWSER_2__)
    if (mmi_rmgr_unlock_session_on())
    {
        /* the processing screen is deleted , we need to clean browser and
           the unlock session */
        mmi_brw_app_deinit();
        DRM_cancel_sd_callback((kal_uint8)rmgr_req_ri_entry.sd_callback_id);
        mmi_rmgr_wipe_unlock_session();
    }
#endif

    //return MMI_HIST_ALLOW_DELETING;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_activate_abort_hdlr
 * DESCRIPTION
 *  try abort processing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_activate_abort_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_popup_display((WCHAR*) GetString(FMGR_FS_ABORTED_ERROR_TEXT), MMI_EVENT_SUCCESS, NULL);

    /* delete activating screen then invoke mmi_rmgr_activate_del_cb to clean the session*/
    mmi_frm_scrn_close(GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_PROCESS);
}

/*****************************************************************************
* FUNCTION
*   mmi_rmgr_entry_activate
* DESCRIPTION
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
void mmi_rmgr_entry_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(
                          GRP_ID_RMGR_ACTIVATE, 
       			  SCR_ID_RMGR_ACTIVATE_PROCESS, 
       			  NULL, 
       			  mmi_rmgr_entry_activate, 
       			  MMI_FRM_FULL_SCRN))
   {
#if defined(__MMI_RMGR_SEAMLESS_UNLOCK__) && defined(__MMI_BROWSER_2__)
//    EntryNewScreen(SCR_ID_RMGR_ACTIVATE_PROCESS, NULL, mmi_rmgr_entry_activate, NULL);
    ShowCategory66Screen(
        STR_GLOBAL_ACTIVATE,
        mmi_rmgr_get_root_icon(),
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        (U8 *) GetString(STR_ID_RMGR_PROCESSING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    SetRightSoftkeyFunction(mmi_rmgr_activate_abort_hdlr, KEY_EVENT_UP);
    //SetDelScrnIDCallbackHandler(SCR_ID_RMGR_ACTIVATE_PROCESS, mmi_rmgr_activate_del_cb);
    mmi_frm_scrn_set_leave_proc (GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_PROCESS, mmi_rmgr_activate_leave_proc);
#else
    //EntryNewScreen(SCR_ID_RMGR_ACTIVATE_PROCESS, NULL, mmi_rmgr_entry_activate, NULL);
    ShowCategory66Screen(
        STR_GLOBAL_ACTIVATE,
        mmi_rmgr_get_root_icon(),
        0,
        0,
        0,
        0,
        (U8 *) GetString(STR_ID_RMGR_PROCESSING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    //SetDelScrnIDCallbackHandler(SCR_ID_RMGR_ACTIVATE_PROCESS, mmi_rmgr_activate_del_cb);
    mmi_frm_scrn_set_leave_proc (GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_PROCESS, mmi_rmgr_activate_leave_proc);
#endif
}
}

mmi_ret mmi_rmgr_activate_leave_proc(mmi_event_struct *evt)
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
            mmi_rmgr_activate_del_cb();
            break;

		//case EVT_ID_SCRN_DELETE_REQ:
			//mmi_ecompass_deinitialize();
       
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_register_unlock_session
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_register_unlock_session(FS_HANDLE handle,  U16 *path,
                                      U8 permission, MMI_BOOL more,
                                      U8 *url, U32 url_size,
                                      U16 icon,
                                      mmi_rmgr_ri_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_register_unlock_session %d %d %d %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_REGISTER_UNLOCK_SESSION, permission, more, url_size, icon, callback));


    if (handle > FS_NO_ERROR)
    {
        rmgr_req_ri_entry.file_handle = handle;
    }

    if (path)
    {
        ASSERT(rmgr_req_ri_entry.file_path == NULL);

        rmgr_req_ri_entry.file_path = (U16 *)drmt_mem_alloc((kal_wstrlen((kal_wchar*)path) + 1) * ENCODING_LENGTH);
        app_ucs2_strcpy((kal_int8 *)rmgr_req_ri_entry.file_path, (kal_int8 *)path);
    }

    rmgr_req_ri_entry.more = more;

    if (url)
    {
        ASSERT(rmgr_req_ri_entry.url == NULL);
        rmgr_req_ri_entry.url = (U16 *)drmt_mem_alloc(url_size * ENCODING_LENGTH);
        kal_wsprintf((kal_wchar*)rmgr_req_ri_entry.url, "%s", url);
    }

    if (icon)
    {
        rmgr_req_ri_entry.icon = icon;
    }
    else
    {
        rmgr_req_ri_entry.icon = mmi_rmgr_get_root_icon();
    }

    if (callback)
    {
        rmgr_req_ri_entry.result_callback = callback;
    }

    if (permission)
    {
        rmgr_req_ri_entry.permission = permission;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_wipe_unlock_session
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_wipe_unlock_session(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_wipe_unlock_session",
            (TRACE_GROUP_UI, RMGR_UTIL_WIPE_UNLOCK_SESSION));

    if (rmgr_req_ri_entry.file_path)
    {
        drmt_mem_free(rmgr_req_ri_entry.file_path);
    }

    if (rmgr_req_ri_entry.url)
    {
        drmt_mem_free(rmgr_req_ri_entry.url);
    }

    /* also set is_set to KAL_FALSE */
    memset(&rmgr_req_ri_entry, 0, sizeof(rmgr_req_ri_entry));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_send_rights_request
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_send_rights_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_send_rights_request",
            (TRACE_GROUP_UI, RMGR_UTIL_SEND_RIGHTS_REQUEST));

#ifdef __DRM_V02__
    if (rmgr_req_ri_entry.file_path)
    {
        mmi_rmgr_entry_activate();
        DRM_activate_file((kal_wchar*)rmgr_req_ri_entry.file_path, rmgr_req_ri_entry.permission, NULL, mmi_rmgr_activate_callback);
    }
    else if (rmgr_req_ri_entry.file_handle)
    {
        mmi_rmgr_entry_activate();
        DRM_activate_file_by_handle(rmgr_req_ri_entry.file_handle, NULL, mmi_rmgr_activate_callback);
    }
    else
#endif /* __DRM_V02__ */
    if (rmgr_req_ri_entry.url)
    {
#ifdef BROWSER_SUPPORT
#if defined(__MMI_RMGR_SEAMLESS_UNLOCK__) && defined(__MMI_BROWSER_2__)
        rmgr_req_ri_entry.is_activating = MMI_TRUE;
        mmi_rmgr_entry_activate();

        if (rmgr_req_ri_entry.file_path)
        {
            /* In some slow network, we cannot get the file immediately, therefore,
               we set the timeout time longer */
            rmgr_req_ri_entry.sd_callback_id = DRM_register_sd_callback(rmgr_req_ri_entry.file_path, DRM_DEFAULT_WAIT * 2, rmgr_req_ri_entry.file_path, mmi_rmgr_unlock_session_sd_cb);
        }
        else if(rmgr_req_ri_entry.file_handle)
        {
            rmgr_req_ri_entry.sd_callback_id = DRM_register_sd_callback_by_handle(rmgr_req_ri_entry.file_handle, DRM_DEFAULT_WAIT * 2, NULL, mmi_rmgr_unlock_session_sd_cb);
        }
        else
        {
            ASSERT(0);
        }

        wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)rmgr_req_ri_entry.url);

        if (rmgr_req_ri_entry.result_callback)
        {
            rmgr_req_ri_entry.result_callback(MMI_TRUE);
        }
        /* we do not clean the unlock session if support seamless unlock  */
#else

        wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)rmgr_req_ri_entry.url);

        if (rmgr_req_ri_entry.result_callback)
        {
            rmgr_req_ri_entry.result_callback(MMI_TRUE);
        }
        mmi_rmgr_wipe_unlock_session();

#endif
#endif
    }
    else
    {
        ASSERT(0);
    }

    mmi_frm_scrn_close(GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_CONFIRM);
     //ClearDelScrnIDCallbackHandler(SCR_ID_RMGR_ACTIVATE_CONFIRM, NULL);
    //DeleteScreenIfPresent(SCR_ID_RMGR_ACTIVATE_CONFIRM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_request_rights_confirm_del_cb
 * DESCRIPTION
 *  The skip option of confirm to request rights
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_rmgr_request_rights_confirm_del_cb(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_request_rights_confirm_del_cb",
            (TRACE_GROUP_UI, RMGR_UTIL_REQUEST_RIGHTS_CONFIRM_DEL_CB));

    if (rmgr_req_ri_entry.result_callback)
    {
        rmgr_req_ri_entry.result_callback(MMI_FALSE);
    }
    mmi_rmgr_wipe_unlock_session();

    return MMI_HIST_ALLOW_DELETING;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_request_rights_back
 * DESCRIPTION
 *  The skip option of confirm to request rights
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_request_rights_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_request_rights_back",
            (TRACE_GROUP_UI, RMGR_UTIL_REQUEST_RIGHTS_BACK));

    mmi_rmgr_request_rights_confirm_del_cb(NULL);
    //ClearDelScrnIDCallbackHandler(SCR_ID_RMGR_ACTIVATE_CONFIRM, NULL);
    mmi_frm_scrn_close_active_id();
}



/*****************************************************************************
 * FUNCTION
 *   mmi_rmgr_exit_request_rights_confirm
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_exit_request_rights_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_exit_request_rights_confirm",
            (TRACE_GROUP_UI, RMGR_UTIL_EXIT_REQUEST_RUGHTS_CONFIRM));

#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        leave_full_screen();
#endif

        ResetCenterSoftkey();

    srv_prof_stop_tone(SRV_PROF_TONE_WARNING);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_request_rights_format_msg
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_request_rights_format_msg(U16 *buff, S32 buf_size, S32 format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(buff, 0, buf_size);

    if (format == 1)
    {
        FS_HANDLE handle;
        drm_constraint_struct cons;

        if (rmgr_req_ri_entry.file_path)
        {
            handle = DRM_open_file((kal_wchar*)rmgr_req_ri_entry.file_path, FS_READ_ONLY, rmgr_req_ri_entry.permission);
        }
        else
        {
            handle = rmgr_req_ri_entry.file_handle;
        }

        if (handle >= DRM_RESULT_OK)
        {
            DRM_get_constraint(handle, NULL, rmgr_req_ri_entry.permission, &cons);

            if (cons.status != DRM_STATUS_RIGHTS_PRESENT)
            {
                mmi_rmgr_ucs2cat_secure((PS8) buff, (PS8) GetString(STR_ID_RMGR_REQ_RITS_EXPIRE_DETAIL), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) buff, (PS8) L"\n", buf_size);
            }
            else
            {
                mmi_rmgr_ucs2cat_secure((PS8) buff, (PS8) GetString(STR_ID_RMGR_REQ_RITS_EXTEND_DETAIL), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) buff, (PS8) L"\n", buf_size);
                mmi_rmgr_populate_drm_constraint(&cons, (U8)rmgr_req_ri_entry.permission, (U8*)buff, buf_size, MMI_TRUE);
            }
        }
        else
        {
            ASSERT(0);
        }

        if (rmgr_req_ri_entry.file_path)
        {
            DRM_close_file(handle);
        }
    }
    else if (format == 2)
    {

        app_ucs2_strcat((kal_int8 *)buff, (kal_int8 *)GetString(STR_ID_RMGR_REQ_RIGHTS));

    }
}

mmi_ret mmi_rmgr_activate_conf_leave_proc(mmi_event_struct *evt)
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
            mmi_rmgr_request_rights_confirm_del_cb(NULL);
            break;

	case EVT_ID_SCRN_DELETE_REQ:
            mmi_rmgr_request_rights_confirm_del_cb(NULL);
            break;
       
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_request_rights_confirm
 * DESCRIPTION
 *  The confirm to request rights
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_entry_request_rights_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_id g_id;
    UI_string_type str = NULL;

     g_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_RMGR_ACTIVATE, mmi_rmgr_main_evt_hdlr, NULL);
     mmi_frm_group_enter(g_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
if(mmi_frm_scrn_enter(
       				GRP_ID_RMGR_ACTIVATE, 
       				SCR_ID_RMGR_ACTIVATE_CONFIRM, 
       				mmi_rmgr_exit_request_rights_confirm, 
       				mmi_rmgr_entry_request_rights_confirm, 
       				MMI_FRM_SCRN_GROUP))
   {
    guiBuffer = mmi_frm_scrn_get_gui_buf (GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_CONFIRM);
    //EntryNewScreen(SCR_ID_RMGR_ACTIVATE_CONFIRM, mmi_rmgr_exit_request_rights_confirm, mmi_rmgr_entry_request_rights_confirm, NULL);

    if (rmgr_req_ri_entry.confirm_string)
    {
        str = rmgr_req_ri_entry.confirm_string;
    }
    else if(rmgr_req_ri_entry.show_detail)
    {
        str = (UI_string_type)subMenuData;
        mmi_rmgr_request_rights_format_msg((U16*)subMenuData, sizeof(subMenuData), 1);
    }
    else if(rmgr_req_ri_entry.more)
    {
        str = (UI_string_type)GetString(STR_ID_RMGR_MORE_RITS_QUERY);
    }
    else
    {
        str = (UI_string_type)subMenuData;
        mmi_rmgr_request_rights_format_msg((U16*)subMenuData, sizeof(subMenuData), 2);
    }
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    if (rmgr_req_ri_entry.show_detail)
    {
        /* 8. Display Category74 Screen */
        ShowCategory74Screen(
            STR_GLOBAL_ACTIVATE,
            rmgr_req_ri_entry.icon,
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (PU8) str,
            mmi_ucs2strlen((PS8) str),
            guiBuffer);
    }
    else if (rmgr_req_ri_entry.more)
    {
        ShowCategory165Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            str,
            mmi_get_event_based_image(MMI_EVENT_QUERY),
            guiBuffer);

        if (!guiBuffer)
            srv_prof_play_tone((srv_prof_tone_enum) mmi_get_event_based_sound(MMI_EVENT_QUERY), NULL);
    }
    else
    {

        ShowCategory7Screen(
            STR_ID_RMGR,
            mmi_rmgr_get_root_icon(),
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (U8 *)str,
            guiBuffer);

        if (!guiBuffer)
            srv_prof_play_tone((srv_prof_tone_enum) mmi_get_event_based_sound(MMI_EVENT_QUERY), NULL);
    }
    SetCenterSoftkeyFunction(mmi_rmgr_send_rights_request, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_rmgr_send_rights_request, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_rmgr_request_rights_back, KEY_EVENT_UP);
    mmi_frm_scrn_set_leave_proc(GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_CONFIRM, mmi_rmgr_activate_conf_leave_proc);
    //SetDelScrnIDCallbackHandler(SCR_ID_RMGR_ACTIVATE_CONFIRM, mmi_rmgr_request_rights_confirm_del_cb);
}
else
{
    mmi_frm_scrn_set_leave_proc(GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_CONFIRM, mmi_rmgr_activate_conf_leave_proc);
   return;// mmi_rmgr_wipe_unlock_session();
}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_request_rights_confirm
 * DESCRIPTION
 *  The confirm to request rights
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_request_rights_confirm_ext(U16 *confirm_string, MMI_BOOL show_immediately)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_request_rights_confirm",
            (TRACE_GROUP_UI, RMGR_UTIL_REQUEST_RIGHTS_CONFIRM));

    if (rmgr_req_ri_entry.file_path == NULL && rmgr_req_ri_entry.file_handle == 0)
    {
        ASSERT(0);
    }

    rmgr_req_ri_entry.confirm_string = confirm_string;

#ifdef BROWSER_SUPPORT
    if (show_immediately)
    {
        mmi_rmgr_entry_request_rights_confirm();
    }
    else
    {
        mmi_rmgr_entry_request_rights_confirm();
        //EntryNewScreen(SCR_ID_RMGR_ACTIVATE_CONFIRM, NULL, mmi_rmgr_entry_request_rights_confirm, NULL);
        //SetDelScrnIDCallbackHandler(SCR_ID_RMGR_ACTIVATE_CONFIRM, mmi_rmgr_request_rights_confirm_del_cb);
    }
#else
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
    mmi_rmgr_wipe_unlock_session();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_request_rights_confirm
 * DESCRIPTION
 *  The confirm to request rights
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_request_rights_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_rmgr_request_rights_confirm_ext(NULL, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_rights_internal
 * DESCRIPTION
 *  To validate rights with given path and permission
 * PARAMETERS
 *  file_path       [IN]       file path
 *  permission      [IN]       application specific permission
 *  callback        [IN]       callback of app to tell proceed or not
 * RETURNS
 *  MMI_RMGR_STATUS_OK:  not DRM file
 *  MMI_RMGR_STATUS_WITH_RIGHTS: DRM file with valid rights
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: SD/V2 w/o valid rights (also have right issuer and can get right now)
 *  MMI_RMGR_STATUS_NO_PERMISSION: FL/CD w/o valid rights or cannot get right now
 *  negative value: Otherwise, error code
 *****************************************************************************/
S32 mmi_rmgr_check_rights_internal(FS_HANDLE handle, U8 permission, U16 icon, mmi_rmgr_ri_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = MMI_RMGR_STATUS_OK;
    U8 method;
    MMI_BOOL is_permitted;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_check_rights_internal %d %d %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_CHECK_RIGHTS_INTERNAL, handle, permission, icon, callback));

    ASSERT(handle>=DRM_RESULT_OK);

    method = DRM_get_object_method(handle, NULL);

    if (method == DRM_METHOD_NONE)
    {
        result = MMI_RMGR_STATUS_OK;
        goto final;
    }

    is_permitted = DRM_validate_permission(handle, NULL, permission);

    if (is_permitted)
    {
        result = MMI_RMGR_STATUS_OK;
        goto final;
    }

    /* No permission area */
    if (!srv_nw_usab_is_any_network_available())
    {
        result = MMI_RMGR_STATUS_NO_PERMISSION;
        goto final;
    }

    if (method & DRM_METHOD_SEPARATE_DELIVERY ||
        method & DRM_METHOD_V2 ||
        method & DRM_METHOD_PDCF)
    {
        U32 size = DRM_MAX_LINE_LENGTH;
        U8 *url = (U8 *)drmt_mem_alloc(size);

        memset(url, 0, size);
        if(DRM_RESULT_OK > DRM_get_rights_issuer(handle, (kal_char*)url, &size))
        {
            result = MMI_RMGR_STATUS_NO_PERMISSION;
        }
        else
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            /* register url, size, icon and callback */
            mmi_rmgr_register_unlock_session(0, NULL, permission, MMI_FALSE, url, size, icon, callback);
        }
        drmt_mem_free(url);
    }
    else
    {
        result = MMI_RMGR_STATUS_NO_PERMISSION;
    }

final:
    if (result != MMI_RMGR_STATUS_REQUEST_RIGHTS)
    {
        mmi_rmgr_wipe_unlock_session();
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_rights
 * DESCRIPTION
 *  To validate rights with given path and permission
 * PARAMETERS
 *  file_path       [IN]       file path
 *  permission      [IN]       application specific permission
 *  callback        [IN]       callback of app to tell proceed or not
 * RETURNS
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: SD/V2 w/o valid rights
 *  MMI_RMGR_STATUS_NO_PERMISSION: FL/CD w/o valid rights or SD/V2 w/o RI URL
 *  negative value: Otherwise, error code
 *****************************************************************************/
S32 mmi_rmgr_check_rights_by_handle(FS_HANDLE handle, U8 permission, U16 icon, mmi_rmgr_ri_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_check_rights_by_handle %d %d %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_CHECK_RIGHTS_BY_HANDLE, handle, permission, icon, callback));

#ifdef __DRM_PDCF__
    if (handle < DRM_RESULT_OK)
    {
        return handle;
    }

    if (DRM_get_object_method(handle, NULL)!= DRM_METHOD_PDCF)
    {
        ASSERT(0);
        return MMI_RMGR_STATUS_NO_PERMISSION;
    }

    mmi_rmgr_clear_unlock_screen();

    /* register file handle only */
    mmi_rmgr_register_unlock_session(handle, NULL, 0, MMI_FALSE, NULL, 0, 0, NULL);

    return mmi_rmgr_check_rights_internal(handle, permission, icon, callback);
#else
    ASSERT(0);
    return MMI_RMGR_STATUS_NO_PERMISSION;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_rights
 * DESCRIPTION
 *  To validate rights with given path and permission
 * PARAMETERS
 *  file_path       [IN]       file path
 *  permission      [IN]       application specific permission
 *  callback        [IN]       callback of app to tell proceed or not
 * RETURNS
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: SD/V2 w/o valid rights
 *  MMI_RMGR_STATUS_NO_PERMISSION: FL/CD w/o valid rights or SD/V2 w/o RI URL
 *  negative value: Otherwise, error code
 *****************************************************************************/
S32 mmi_rmgr_check_rights_by_path(U16* file_path, U8 permission, U16 icon, mmi_rmgr_ri_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    S32 result = MMI_RMGR_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_check_rights_by_path %d %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_CHECK_RIGHTS_BY_PATH, permission, icon, callback));

    handle = DRM_open_file(file_path, FS_READ_ONLY, permission);
    if (handle >= DRM_RESULT_OK)
    {
        mmi_rmgr_clear_unlock_screen();

        /* register file_path only */
        mmi_rmgr_register_unlock_session(0, (U16*)file_path, 0, MMI_FALSE, NULL, 0, 0, NULL);

        result = mmi_rmgr_check_rights_internal(handle, permission, icon, callback);

        DRM_close_file(handle);
    }
    else
    {
        result = handle;
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_rights_full_procedure
 * DESCRIPTION
 * PARAMETERS
 *  file_path       [IN]     file path
 *  FS_HANDLE       [IN]     file handle, can be null when file_path is null
 *  callback        [IN]       callback of app to tell proceed or not
 * RETURNS
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: SD/V2 w/o valid rights
 *  MMI_RMGR_STATUS_NO_PERMISSION: FL/CD w/o valid rights or SD/V2 w/o RI URL
 *  negative value: Otherwise, error code
 *****************************************************************************/

MMI_BOOL mmi_rmgr_check_rights_full_procedure(U16* filepath, FS_HANDLE handle, U8 permission, U16 icon, mmi_rmgr_ri_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_check_rights_full_procedure %d %d %d %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_CHECK_RIGHTS_FULL_PROCEDURE, handle, permission, icon, callback));

    if (filepath)
    {
        result = mmi_rmgr_check_rights_by_path(filepath, permission, icon, callback);
    }
    else
    {
        result = mmi_rmgr_check_rights_by_handle(handle, permission, icon, callback);
    }

    switch(result)
    {
        case MMI_RMGR_STATUS_OK:
        case MMI_RMGR_STATUS_WITH_RIGHTS:
            return MMI_TRUE;
        case MMI_RMGR_STATUS_NO_PERMISSION:
        {
            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DRM_PROHIBITED), MMI_EVENT_FAILURE, NULL);
            break;
        }
        case MMI_RMGR_STATUS_REQUEST_RIGHTS:
        {
            mmi_rmgr_request_rights_confirm();
            break;
        }
        default:
        {
            mmi_popup_display((WCHAR*)GetString(srv_fmgr_fs_error_get_string(result)), MMI_EVENT_FAILURE, NULL);
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_forward
 * DESCRIPTION
 *  To get forward rule of input file path
 * PARAMETERS
 *  file_path       [IN]     file path
 * RETURNS
 *  combination of result (bit mask)
 *  MMI_RMGR_USAGE_DRM: this is a DRM content
 *  MMI_RMGR_USAGE_SEND: this content can be sent via network applications
 *  MMI_RMGR_USAGE_SET: this content can be set as automated usage
 *  negative value: Otherwise, error code
 *****************************************************************************/
S32 mmi_rmgr_check_forward(U16 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    U8 permission = DRM_PERMISSION_NONE;
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_check_forward",
            (TRACE_GROUP_UI, RMGR_UTIL_CHECK_FORWARD));

    handle = DRM_open_file(file_path, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);

    if (handle < DRM_RESULT_OK)
    {
        return handle;
    }

    if (!DRM_is_drm_file(handle, NULL))
    {
        result |= MMI_RMGR_USAGE_SEND;
        result |= MMI_RMGR_USAGE_SET;

        DRM_close_file(handle);
    }
    else
    {
        permission = drm_get_permission_ext(DRM_get_content_type_entry(handle));

        DRM_close_file(handle);

        handle = DRM_open_file(file_path, FS_READ_ONLY | FS_OPEN_SHARED, permission);

        if (handle > FS_NO_ERROR)
        {
            if (DRM_interdev_movable(handle, NULL))
            {
                result |= MMI_RMGR_USAGE_SEND;
            }

            if (DRM_validate_forward_rule(handle, permission))
            {
                result |= MMI_RMGR_USAGE_SET;
            }

            DRM_close_file(handle);
        }
        else
        {
            /* open file fail */
            result = handle;
        }
    }


    return result;
}

#ifdef __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__

#define MMI_RMGR_EXTEND_WARNING_MAX_COUNT 2
#define MMI_RMGR_EXTEND_WARNING_MAX_DATETIME (DT_SEC_PER_DAY) /* 1 day */
#define MMI_RMGR_EXTEND_WARNING_MAX_ACCUM (DT_SEC_PER_HOUR)
#define MMI_RMGR_EXTEND_WARNING_MAX_TIMECOUNT 2

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_rights_internal
 * DESCRIPTION
 *  To validate rights with given path and permission
 * PARAMETERS
 *  file_path       [IN]       file path
 *  permission      [IN]       application specific permission
 *  callback        [IN]       callback of app to tell proceed or not
 * RETURNS
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: the rights is expired or expired soon.
 *  MMI_RMGR_STATUS_WITH_RIGHTS: this content with solid rights
 *  MMI_RMGR_STATUS_OK: this content is not a DRM file
 *  negative value: Otherwise, error code
 *****************************************************************************/
S32 mmi_rmgr_extend_rights_internal(FS_HANDLE handle, U8 permission, U16 icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = MMI_RMGR_STATUS_OK;
    U8 method;
    U32 size = DRM_MAX_LINE_LENGTH;
    U8 *url = NULL;
    drm_constraint_struct cons;
    applib_time_struct curr_time;
    S32 curr_in_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_extend_rights_internal %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_EXTREND_RIGHTS_INTERNAL, permission, icon));

    /* No permission area */
    if (!srv_nw_usab_is_any_network_available() ||
		srv_mode_switch_is_network_service_available())
    {
        result = MMI_RMGR_STATUS_OK;
        goto final;
    }

    ASSERT(handle>=DRM_RESULT_OK);

    method = DRM_get_object_method(handle, NULL);

    /* not DRM file, need not to extend right */
    if (method == DRM_METHOD_NONE)
    {
        result = MMI_RMGR_STATUS_OK;
        goto final;
    }

    /* FL and CD cannot etend rights */
    if (method == DRM_METHOD_FORWARD_LOCK || method == DRM_METHOD_COMBINED_DELIVERY)
    {
        result = MMI_RMGR_STATUS_WITH_RIGHTS;
        goto final;
    }

    /* no right issuer , cannot get more rights */
    size = DRM_MAX_LINE_LENGTH;
    url = (U8 *)drmt_mem_alloc(DRM_MAX_LINE_LENGTH);
    if(DRM_RESULT_OK > DRM_get_rights_issuer(handle, (kal_char*)url, &size) || size == 0)
    {
        result = MMI_RMGR_STATUS_WITH_RIGHTS;
        goto final;
    }

    DRM_get_constraint(handle, NULL, permission, &cons);

    /* no permission, need to extend right */
    if (cons.status != DRM_STATUS_RIGHTS_PRESENT)
    {
        result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
        goto final;
    }

    applib_dt_get_rtc_time(&curr_time);
    curr_in_sec = applib_dt_mytime_2_utc_sec(&curr_time, KAL_FALSE);

    /* too less count */
    if (cons.type & DRM_CONSTRAINT_COUNT)
    {
        if (cons.used_count <= MMI_RMGR_EXTEND_WARNING_MAX_COUNT)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }


    /* too less time */
    if (cons.type & DRM_CONSTRAINT_DATETIME && cons.end_time > 0)
    {
        if (cons.end_time - curr_in_sec <= MMI_RMGR_EXTEND_WARNING_MAX_DATETIME)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }

    /* too less time */
    if (cons.type & DRM_CONSTRAINT_INTERVAL && cons.end_intv > 0)
    {
        if (cons.end_intv - curr_in_sec <= MMI_RMGR_EXTEND_WARNING_MAX_DATETIME)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }

#ifdef __DRM_V02__
    /* too less accumulate time */
    if (cons.type & DRM_CONSTRAINT_ACCUMULATED)
    {
        if (cons.accum_dur <= MMI_RMGR_EXTEND_WARNING_MAX_ACCUM)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }

    /* too less timecount */
    if (cons.type & DRM_CONSTRAINT_TIMEDCOUNT)
    {
        if (cons.timed_count <= MMI_RMGR_EXTEND_WARNING_MAX_TIMECOUNT)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }
#endif

final:

    if (result != MMI_RMGR_STATUS_REQUEST_RIGHTS)
    {
        mmi_rmgr_wipe_unlock_session();
    }
    else
    {
        mmi_rmgr_register_unlock_session(0, NULL, permission, MMI_FALSE, url, size, icon, NULL);
    }

    if (url)
    {
        drmt_mem_free(url);
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_extend_rights_by_path
 * DESCRIPTION
 *  To check if it is necessary to extend right.
 * PARAMETERS
 *  file_path       [IN]    file path
 *  permission      [IN]    content permission
 *  icon            [IN]    icon
 * RETURNS
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: the rights is expired or expired soon.
 *  MMI_RMGR_STATUS_WITH_RIGHTS: this content with solid rights
 *  MMI_RMGR_STATUS_OK: this content is not a DRM file
 *  negative value: Otherwise, error code
 *****************************************************************************/
S32 mmi_rmgr_extend_rights_by_path(U16 *filepath, U8 permission, U16 icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    S32 result = MMI_RMGR_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_extend_rights_by_path %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_EXTREND_RIGHTS_BY_PATH, permission, icon));

    handle = DRM_open_file((kal_wchar*)filepath, FS_READ_ONLY, permission);
    if (handle >= DRM_RESULT_OK)
    {
        mmi_rmgr_clear_unlock_screen();

        /* register file_path only */
        mmi_rmgr_register_unlock_session(0, (U16*)filepath, 0, MMI_FALSE, NULL, 0, 0, NULL);
        rmgr_req_ri_entry.show_detail = MMI_TRUE;

        result = mmi_rmgr_extend_rights_internal(handle, permission, icon);

        DRM_close_file(handle);
    }
    else
    {
        result = handle;
    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_extend_rights_full_procedure
 * DESCRIPTION
 *  To check if it is necessary to extend right. We will handle all the following
 *  sceen in this function
 * PARAMETERS
 *  file_path       [IN]    file path
 *  permission      [IN]    content permission
 *  icon            [IN]    icon
 * RETURNS
 *  MMI_TRUE: need to extend rights
 *  MMI_FALSE: no need
 *****************************************************************************/
MMI_BOOL mmi_rmgr_extend_rights_full_procedure(U16 *filepath, U8 permission, U16 icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_extend_rights_full_procedure %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_EXTREND_RIGHTS_FULL_PROCEDURE, permission, icon));

    result = mmi_rmgr_extend_rights_by_path(filepath, permission, icon);

    if (result == MMI_RMGR_STATUS_REQUEST_RIGHTS)
    {
        mmi_rmgr_request_rights_confirm();
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif /* __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__ */



/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
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
#ifdef __DRM_V02__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif
/*****************************************************************************
 * FUNCTION
 * mmi_rmgr_nitz_update_cb
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_rmgr_nitz_update_cb(void *event)
{
#ifdef __DRM_SEC_CLK_NITZ__
    srv_nitz_update_event_struct *event_data = (srv_nitz_update_event_struct*) event;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     //if(drm_stime_nitz_update_cb(&event_data->time, event_data->sim_id))
     //kal_prompt_trace(MOD_MMI, "[Test] Inside update stime rmgr time_zone=%d, %d",event_data->time_zone, event_data->time_zone_p);
     if(drm_stime_nitz_update_cb(&event_data->time, event_data->sim_id, event_data->time_zone_p, &event_data->time_zone, event_data->dst_p))
	 {
		mmi_popup_display((WCHAR*)GetString(STR_ID_SECURE_TIME_UPDATED), MMI_EVENT_INFO, NULL);
	 }
#endif /*__DRM_SEC_CLK_NITZ__*/
}

#ifdef __DRM_SEC_CLK_NITZ__
/*****************************************************************************
 * FUNCTION
 * mmi_rmgr_stime_expiry_hdlr
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_rmgr_stime_expiry_hdlr(void *MsgStruct, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     mmi_popup_display((WCHAR*)GetString(STR_ID_SECURE_TIME_EXPIRED), MMI_EVENT_INFO, NULL);
}
#endif /*__DRM_SEC_CLK_NITZ__*/



/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/

mmi_ret mmi_rmgr_dlagent_notify_handler(mmi_event_struct *evt)
{
	mmi_rmgr_dlagent_evt_struct *evnt_struct;

	evnt_struct = (mmi_rmgr_dlagent_evt_struct *)evt;
	mmi_popup_display((WCHAR*) GetString(evnt_struct->str_id), evnt_struct->evt_type, NULL);
	return MMI_RET_OK;
	
}




#endif
