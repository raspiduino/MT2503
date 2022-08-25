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
 *  EmailAppNetwork.c
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_EMAIL__

#include "MMIDataType.h"

#include "MMI_trc_Int.h" // MMI_TRACE
#include "mmi_inet_app_trc.h"
#include "emailsrvgprot.h"
#include "emailappcore.h"

#include "GlobalResDef.h"
#include "mmi_rp_app_email_def.h"

#include "FileMgrSrvGProt.h"
#include "FileMgrCuiGProt.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"


#include "emailappprot.h"

#include "EmailAppLib.h"
#include "EmailAppStateMgr.h"
#include "EmailAppSwitchStorage.h"

typedef struct
{
    FuncPtr cb;
    CHAR driver;
    //mmi_bool_funcptr_type cb;

}mmi_email_switch_storage_context_struct;

static mmi_email_switch_storage_context_struct g_cntx;


static void eass_loading(void);
static void eass_switch_done(void);
static void eass_switch_storage(void);
static BOOL check_driver(CHAR driver);

static void eass_switch_done(void)
{
    U16 err_str_id = mmi_email_smgr_get_init_result();
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_EMAIL_LOADING_ID);
    if (err_str_id != 0)
    {
        mmi_email_lib_error_popup(err_str_id);
    }
    else if (g_cntx.cb != NULL)
    {
        g_cntx.cb();
        g_cntx.cb = NULL;
    }
    else
    {
        // Nothing to do here
    }
}


static void eass_switch_storage(void)
{
    if (srv_email_set_drive(g_cntx.driver) != SRV_EMAIL_RESULT_SUCC)
    {
        mmi_email_lib_error_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
        return;
    }

    eass_loading();
    mmi_email_smgr_deinit();
    mmi_email_smgr_init(eass_switch_done);
}


static void eass_loading(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_ROOT,
            SCR_EMAIL_LOADING_ID,
            NULL,
            eass_loading,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    ShowCategory66Screen(
        STR_GLOBAL_EMAIL,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*)GetString(STR_GLOBAL_LOADING),
        mmi_email_lib_get_progress_img_id(),
        NULL);
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
}


static BOOL check_driver(CHAR driver)
{
    int result = 0;
    result = FS_GetDevStatus((U16)driver, FS_MOUNT_STATE_ENUM);

    switch (result)
    {
        case FS_DRIVE_NOT_FOUND:
        case FS_UNSUPPORTED_DEVICE:
        case FS_DRIVE_NOT_READY:
        case FS_DEVICE_BUSY:
        case FS_FLASH_MOUNT_ERROR:
        case FS_MSDC_MOUNT_ERROR:
        case FS_MSDC_READ_SECTOR_ERROR:
        case FS_MSDC_WRITE_SECTOR_ERROR:
        case FS_MSDC_NOT_PRESENT:
            return FALSE;

        default:
            return TRUE;
    }
}


static mmi_ret group_proc(mmi_event_struct* p_event)
{
    S32 new_drive = 0;
    WCHAR drive_wcs_path[10]; /* "D:\\" */
    S32 dev_type = FS_DEVICE_TYPE_CARD;

    if (p_event->evt_id != EVT_ID_CUI_STORAGE_SELECTOR_RESULT)
    {
        return MMI_RET_OK;
    }

    new_drive = ((cui_storage_selector_result_event_struct*)p_event)->result;
    if (new_drive <= 0)
    {
        goto END;
    }

    memset(drive_wcs_path, 0, sizeof(drive_wcs_path));
    drive_wcs_path[0] = new_drive;
    mmi_wcscat(drive_wcs_path, L":\\");
    dev_type = FS_GetDevType((const WCHAR*)drive_wcs_path);

    /* Do not support OTG device*/
    if (FS_DEVICE_TYPE_EXTERNAL == dev_type)
    {
        mmi_email_lib_error_popup(STR_EMAIL_OTG_DEVICE_IS_NOT_SUPPORTED);
        goto END;
    }

    // Not changed
    if ((CHAR)new_drive == srv_email_get_drive())
    {
        goto END;
    }

    /* switch */
    g_cntx.cb = NULL;
    g_cntx.driver = new_drive;
    eass_switch_storage();

END:
    cui_storage_selector_close(((cui_storage_selector_result_event_struct*)p_event)->sender_id);
    return MMI_RET_OK;
}


BOOL mmi_email_switch_storage_check(FuncPtr cb, BOOL show_ui)
{
    if (check_driver(srv_email_get_drive()))
    {
        return TRUE;
    }

    if (cb != NULL)
    {
        /* Ask to switch to PHONE storage */
        g_cntx.cb = cb;
        g_cntx.driver = SRV_FMGR_PHONE_DRV;

        mmi_email_util_display_confirm(
            GRP_ID_ROOT,
            eass_switch_storage,
            mmi_frm_scrn_close_active_id,
            NULL,
            TRUE,
            GetString(STR_GLOBAL_MC_REMOVED_USE_PHONE),
            MMI_EVENT_QUERY);
    }
    else if (show_ui)
    {
        mmi_email_lib_error_popup(STR_GLOBAL_MC_REMOVED);
    }

    return FALSE;
}

void mmi_email_switch_storage(mmi_id parent)
{
    mmi_id grp_id, cui_id;

    grp_id = mmi_frm_group_create_ex(
        parent,
        GRP_ID_AUTO_GEN, 
        group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_id = cui_storage_selector_create(grp_id, (U8)(srv_email_get_drive()), 0);
    cui_storage_selector_run(cui_id);
}


#endif /* __MMI_EMAIL__ */
