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
 *  BootupDiskCheck.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Adaptors for bootup.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "BootupAppProt.h"
#include "ShutdownSrvGprot.h"
#include "AlarmFrameworkProt.h" /* AlmATPowerReset */
#include "MMIDataType.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_bootup_def.h"
#include "wgui_categories_list.h"
#include "wgui_categories_popup.h"
#include "mmi_rp_app_filemanager_def.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "custom_events_notify.h"
#include "BootupScrUtil.h"
#include "mmi_res_range_def.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "fs_type.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/

struct mmi_bootup_disk_check_cntx_struct_s;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    struct mmi_bootup_disk_check_cntx_struct_s *cntx;
} mmi_bootup_disk_check_callback_evt_struct;


typedef struct mmi_bootup_disk_check_cntx_struct_s
{
    mmi_id grp_id;
    mmi_bootup_disk_check_result_callback completed_callback;
    void *user_data;
    S32 error_code;
    int recover_device_type;
    mmi_bootup_disk_check_callback_evt_struct evt;
} mmi_bootup_disk_check_cntx_struct;

static void mmi_bootup_disk_check_display_warning(mmi_bootup_disk_check_cntx_struct *cntx, U16 prompt_str_id);

/****************************************************************************
 * Local functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_callback_client
 * DESCRIPTION
 *  Callback client.
 * PARAMETERS
 *  evt     [IN] mmi_bootup_disk_check_callback_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_bootup_disk_check_callback_client(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_disk_check_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = ((mmi_bootup_disk_check_callback_evt_struct*)evt)->cntx;

    if (cntx->error_code == FS_NO_ERROR)
    {
        FS_SetDiskFlag();
    }

    MMI_ASSERT(cntx->completed_callback != NULL);
    cntx->completed_callback(cntx->user_data, cntx->error_code);
    OslMfree(cntx);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_notify_result
 * DESCRIPTION
 *  Callback client by post event.
 * PARAMETERS
 *  cntx        [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_disk_check_notify_result(
                mmi_bootup_disk_check_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Callback in another cycle */
    MMI_FRM_INIT_EVENT(&(cntx->evt), 0);
    cntx->evt.cntx = cntx;
    MMI_FRM_POST_EVENT(&(cntx->evt), mmi_bootup_disk_check_callback_client, NULL);
}

#ifndef __MMI_BOOTUP_DISK_CHECK_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_entry_formatting
 * DESCRIPTION
 *  Entry function of formatting screen.
 * PARAMETERS
 *  es_data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_disk_check_entry_formatting(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_disk_check_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(es_data != NULL && es_data->user_data != NULL);
    cntx = (mmi_bootup_disk_check_cntx_struct*)es_data->user_data;
    
    if (!mmi_frm_scrn_enter(
        cntx->grp_id,
        SCR_ID_BOOTUP_DISK_CHECK_FORMATTING,
        NULL,
        (FuncPtr)mmi_bootup_disk_check_entry_formatting,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    ShowCategory66Screen(
        STR_FMGR_TITLE,
        GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID),
        0,
        0,
        0,
        0,
        (U8*)get_string(STR_ID_BOOTUP_FORMATING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        mmi_frm_scrn_get_active_gui_buf());
    
    mmi_frm_scrn_set_key_proc(
        cntx->grp_id,
        SCR_ID_BOOTUP_DISK_CHECK_FORMATTING,
        mmi_bootup_block_all_keys);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_start_format
 * DESCRIPTION
 *  Enter formatting screen and start formatting. After formatted, it will
 *  reboot automatically.
 * PARAMETERS
 *  evt     [IN] mmi_bootup_count_down_selected_evt_struct*
 * RETURNS
 *  MMI_BOOTUP_SCR_ALLOW_TO_CLOSE
 *****************************************************************************/
static mmi_ret mmi_bootup_disk_check_start_format(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_disk_check_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_MMI_BOOTUP_SCR_SELECTED_POSITIVE && evt->user_data != NULL);
    
    cntx = (mmi_bootup_disk_check_cntx_struct*)evt->user_data;
    
    mmi_frm_scrn_first_enter(
        cntx->grp_id,
        SCR_ID_BOOTUP_DISK_CHECK_FORMATTING,
        (FuncPtr)mmi_bootup_disk_check_entry_formatting,
        cntx);

    /* Format */
    FS_RecoverDevice(cntx->recover_device_type);

    OslMfree(cntx);

    /* Reset phone */
    AlmATPowerReset(0, 0);

    return MMI_BOOTUP_SCR_ALLOW_TO_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_shutdown
 * DESCRIPTION
 *  Shutdown.
 * PARAMETERS
 *  cntx        [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_disk_check_shutdown(mmi_bootup_disk_check_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bootup_put_dummy_screen(cntx->grp_id);

    OslMfree(cntx);

    srv_shutdown_exit_system(APP_BOOTUP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_shutdown_on_neg_event
 * DESCRIPTION
 *  User reject the formatting or timeout on fatal error.
 *  Shutdown right away.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bootup_disk_check_shutdown_on_neg_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_disk_check_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_MMI_BOOTUP_SCR_SELECTED_NEGATIVE:
        case EVT_ID_MMI_BOOTUP_SCR_TIMEOUT:
            cntx = (mmi_bootup_disk_check_cntx_struct*)evt->user_data;
            mmi_bootup_disk_check_shutdown(cntx);
            return MMI_BOOTUP_SCR_ALLOW_TO_CLOSE;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_skip
 * DESCRIPTION
 *  Skip formatting and callback client.
 * PARAMETERS
 *  cntx        [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_disk_check_skip(mmi_bootup_disk_check_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bootup_disk_check_notify_result(cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_skip_on_neg_event
 * DESCRIPTION
 *  User reject the formatting or timeout on fatal error.
 *  Skip formatting and callback client.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bootup_disk_check_skip_on_neg_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_disk_check_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_MMI_BOOTUP_SCR_SELECTED_NEGATIVE:
        case EVT_ID_MMI_BOOTUP_SCR_TIMEOUT:
            cntx = (mmi_bootup_disk_check_cntx_struct*)evt->user_data;
            mmi_bootup_disk_check_skip(cntx);
            return MMI_BOOTUP_SCR_ALLOW_TO_CLOSE;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_display_format_confirm
 * DESCRIPTION
 *  Display formatting query.
 * PARAMETERS
 *  cntx            [IN] Context
 *  prompt_str_id   [IN] The ID of the string to prompt user
 *  fatal_error     [IN] If MMI_TRUE, the error is non-ignorable. If user
 *                       rejects the formatting system has to shutdown immediately.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_disk_check_display_format_confirm(
                mmi_bootup_disk_check_cntx_struct *cntx,
                U16 prompt_str_id,
                MMI_BOOL fatal_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_proc_func neg_proc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* To avoid compile warning */
    neg_proc = NULL;

    if (fatal_error)
    {
        neg_proc = mmi_bootup_disk_check_shutdown_on_neg_event;
    }
    else
    {
        neg_proc = mmi_bootup_disk_check_skip_on_neg_event;
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
	#endif
}
#endif /* __MMI_BOOTUP_DISK_CHECK_SLIM__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_for_sanity_passed
 * DESCRIPTION
 *  Continue advanced disk check for sanity pass
 * PARAMETERS
 *  cntx            [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_disk_check_for_sanity_passed(
                mmi_bootup_disk_check_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR drive_path[5] = L"X:\\";
    FS_HANDLE fs_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drive_path[0] = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_ONLY_ALT_SERIAL);
    fs_hdlr = FS_Open(drive_path, FS_READ_ONLY | FS_OPEN_DIR);

    cntx->error_code = fs_hdlr;

    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_DISK_CHECK_FOR_SANITY, drive_path[0], cntx->error_code);

    if (fs_hdlr >= 0)
    {
        FS_Close(fs_hdlr);
        cntx->error_code = FS_NO_ERROR;
        mmi_bootup_disk_check_notify_result(cntx);
    }
	
#ifndef __MMI_BOOTUP_DISK_CHECK_SLIM__
    else if (fs_hdlr == FS_FDM_USER_DRIVE_BROKEN)
    {
        cntx->recover_device_type = FS_GetDevType(drive_path);
        mmi_bootup_disk_check_display_format_confirm(cntx, STR_ID_BOOTUP_USER_DRIVE_CORRUPTED, MMI_TRUE);
    }
    else if (fs_hdlr == FS_NAND_DEVICE_NOT_SUPPORTED)
    {
        mmi_bootup_disk_check_display_warning(cntx, STR_ID_BOOTUP_NAND_NOT_SUPPORTED);
    }
#endif /* #ifndef __MMI_BOOTUP_DISK_CHECK_SLIM__ */
    else
    {
        mmi_bootup_disk_check_notify_result(cntx);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_warning_callback
 * DESCRIPTION
 *  The event handler of the warning screen.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_bootup_disk_check_warning_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *popup_evt;
    mmi_bootup_disk_check_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_POPUP_QUIT)
    {
        popup_evt = (mmi_alert_result_evt_struct*)evt;
        cntx = (mmi_bootup_disk_check_cntx_struct*)popup_evt->user_tag;
        mmi_bootup_disk_check_notify_result(cntx);
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_display_warning
 * DESCRIPTION
 *  Display warning screen
 * PARAMETERS
 *  cntx            [IN] Context
 *  prompt_str_id   [IN] The ID of the string to prompt user
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_disk_check_display_warning(
                mmi_bootup_disk_check_cntx_struct *cntx,
                U16 prompt_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&property);

    property.callback = mmi_bootup_disk_check_warning_callback;
    property.parent_id = cntx->grp_id;
    property.user_tag = cntx;
    
    if (mmi_popup_display(
            get_string(prompt_str_id),
            MMI_EVENT_INFO,
            &property) != GRP_ID_INVALID)
    {
        /* Do nothing, wait for callback */
    }
    else
    {
        mmi_bootup_disk_check_notify_result(cntx);
    }
}

/****************************************************************************
 * Global functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_check_disk
 * DESCRIPTION
 *  Disk check. This may show formatting screen or warning screen to user
 *  if there is something wrong on storage.
 * PARAMETERS
 *  pargent_grp_id      [IN] Screen group ID
 *  completed_callback  [IN] Callback function for completed
 *  user_data           [IN] To be passed into completed_callback
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_check_disk(
        mmi_id parent_grp_id,
        mmi_bootup_disk_check_result_callback completed_callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_disk_check_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(completed_callback != NULL);
    
    cntx = (mmi_bootup_disk_check_cntx_struct*)
        OslMalloc(sizeof(mmi_bootup_disk_check_cntx_struct));

    /* Initialize context */
    cntx->grp_id = parent_grp_id;
    cntx->completed_callback = completed_callback;
    cntx->user_data = user_data;
    cntx->error_code = FS_NO_ERROR;
    cntx->recover_device_type = -1;    

    /* Sanity check*/
    cntx->error_code = FS_SanityCheck();

    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_CHECK_DISK, cntx->error_code);

    switch (cntx->error_code)
    {
        case FS_NO_ERROR:
            mmi_bootup_disk_check_for_sanity_passed(cntx);
            break;

	#ifndef __MMI_BOOTUP_DISK_CHECK_SLIM__
	
        case FS_FDM_SYS_DRIVE_BROKEN:
        case FS_FDM_MULTIPLE_BROKEN:
        case FS_FDM_USER_DRIVE_BROKEN:
            cntx->recover_device_type = FS_GetDevType(L"Z:\\");
            mmi_bootup_disk_check_display_format_confirm(cntx, STR_ID_BOOTUP_SYSTEM_DRIVE_CORRUPTED, MMI_TRUE);
            break;

        case FS_FDM_VERSION_MISMATCH:
#if defined (_NAND_FLASH_BOOTING_) || defined(__FS_SYSDRV_ON_NAND__)
            mmi_bootup_disk_check_display_format_confirm(cntx, STR_ID_BOOTUP_NAND_VERSION_MISMATCH, MMI_TRUE);
#else
            mmi_bootup_disk_check_display_format_confirm(cntx, STR_ID_BOOTUP_NAND_VERSION_MISMATCH, MMI_FALSE);
#endif
            break;

	#endif /* __MMI_BOOTUP_DISK_CHECK_SLIM__ */
	
        case FS_QUOTA_OVER_DISK_SPACE:
            mmi_bootup_disk_check_display_warning(cntx, STR_ID_BOOTUP_NAND_QUOTA_OVER_DISK);
            break;

        case FS_QUOTA_USAGE_WARNING:
            mmi_bootup_disk_check_display_warning(cntx, STR_ID_BOOTUP_NAND_QUOTA_USAGE_WARNING);
            break;

        default:
            mmi_bootup_disk_check_notify_result(cntx);
            break;
    }
}


