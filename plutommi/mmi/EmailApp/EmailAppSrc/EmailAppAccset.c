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
 *  EmailAppAccset.c
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_EMAIL__

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_email_def.h"

#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "Wgui_categories_list.h"

#include "emailsrvgprot.h"
#include "emailappcore.h"

#include "EmailAppLib.h"
#include "EmailAppAccountData.h"
#include "EmailAppAccset.h"
#include "EmailAppNetwork.h"
#include "EmailAppDtcnt.h"
#include "EmailAppSso.h"

typedef struct
{
    U32 number;
    WCHAR name[MMI_EMAIL_MAX_ACCTS + 1][SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];
    EMAIL_ACCT_ID id[MMI_EMAIL_MAX_ACCTS + 1];

    U16 title;
    mmi_id grp_id;
    U32 idx;

    BOOL set_push;

}email_mmi_accset_item_struct;

static email_mmi_accset_item_struct g_ctx;


/*****************************************************************************
 * FUNCTION 
 *  highlight_handler
 * DESCRIPTION 
 *  highlight handler
 * PARAMETERS 
 *  S32 idx
 * RETURNS 
 *  static void 
*****************************************************************************/
static void highlight_handler(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ctx.idx = idx;
}


/*****************************************************************************
 * FUNCTION 
 *  select_done
 * DESCRIPTION 
 *  select done
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void select_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID acc_id;

#ifdef __MMI_EMAIL_IMAP_PUSH__
    BOOL push_dtcnt_conflict = FALSE;
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCSET_SELECT_DONE, __LINE__);
    acc_id = g_ctx.id[g_ctx.idx];

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (g_ctx.set_push)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCSET_SELECT_DONE, __LINE__);
        if (email_mmi_account_data_get_push() != acc_id)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCSET_SELECT_DONE, __LINE__);
            mmi_email_app_network_push_stop(acc_id != EMAIL_ACCT_INVALID_ID);

            email_mmi_account_data_set_push(acc_id);

            if (acc_id != EMAIL_ACCT_INVALID_ID)
            {
                // Check and adjust if conflict
                push_dtcnt_conflict = mmi_email_dtcnt_is_conflict_ext(acc_id);
                mmi_email_app_network_push_start(acc_id, FALSE);
            }
        }
    }
    else
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCSET_SELECT_DONE, __LINE__);
        email_mmi_account_data_set_default(acc_id);
    }

    mmi_frm_scrn_close_active_id();

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (push_dtcnt_conflict)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCSET_SELECT_DONE, __LINE__);
        // POPUP Data account ID has been changed as AUTOMATICAL
        mmi_email_lib_infor_popup(STR_EMAIL_PUSH_DTCNT_RESET_ID);
    }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCSET_SELECT_DONE, __LINE__);
}


/*****************************************************************************
 * FUNCTION 
 *  show_ui
 * DESCRIPTION 
 *  show ui
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void show_ui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 *guiBuffer = NULL;
    U8 *pp[MMI_EMAIL_MAX_ACCTS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ctx.number; i++)
    {
        pp[i] = (U8*)(g_ctx.name[i]);
    }

    if (!mmi_frm_scrn_enter(
            g_ctx.grp_id,
            SCR_EMAIL_ACCT_SET_ID,
            NULL,
            show_ui,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    RegisterHighlightHandler(highlight_handler);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory109Screen(
        g_ctx.title,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_ctx.number,
        pp,
        NULL,
        g_ctx.idx,
        guiBuffer);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(select_done, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(select_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION 
 *  email_mmi_account_set_default
 * DESCRIPTION 
 *  email mmi account set default
 * PARAMETERS 
 *  mmi_id parent
 * RETURNS 
 *  void 
*****************************************************************************/
void email_mmi_account_set_default(mmi_id parent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, total;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_EMAIL_MMI_ACCOUNT_SET_DEFAULT, __LINE__);

    // prepare all account name
    memset(&g_ctx, 0, sizeof(email_mmi_accset_item_struct));
    g_ctx.set_push = FALSE;

    g_ctx.id[0] = EMAIL_ACCT_INVALID_ID;
    mmi_wcsncpy(g_ctx.name[0], (WCHAR*)GetString(STR_GLOBAL_NONE), SRV_EMAIL_MAX_ACCT_NAME_LEN);

    g_ctx.number = 1;
    total = email_mmi_account_data_get_count();
    for (i = 0; i < total; i++)
    {
        g_ctx.id[g_ctx.number] = email_mmi_account_data_get_id(i);
        mmi_wcsncpy(g_ctx.name[g_ctx.number], 
            email_mmi_account_data_get_name(i), 
            SRV_EMAIL_MAX_ACCT_NAME_LEN);

        if (g_ctx.id[g_ctx.number] == email_mmi_account_data_get_default())
        {
            g_ctx.idx = g_ctx.number;
        }

        g_ctx.number++;
    }

    g_ctx.grp_id = parent;
    g_ctx.title = STR_EMAIL_SET_DEFAULT_ACCOUNT_ID;
    show_ui();
}


#ifdef __MMI_EMAIL_IMAP_PUSH__

/*****************************************************************************
 * FUNCTION 
 *  email_mmi_account_set_push
 * DESCRIPTION 
 *  email mmi account set push
 * PARAMETERS 
 *  mmi_id parent
 * RETURNS 
 *  void 
*****************************************************************************/
void email_mmi_account_set_push(mmi_id parent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, total;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_EMAIL_MMI_ACCOUNT_SET_PUSH, __LINE__);

    // prepare all account name
    memset(&g_ctx, 0, sizeof(email_mmi_accset_item_struct));
    g_ctx.set_push = TRUE;

    g_ctx.id[0] = EMAIL_ACCT_INVALID_ID;
    mmi_wcsncpy(g_ctx.name[0], (WCHAR*)GetString(STR_GLOBAL_NONE), SRV_EMAIL_MAX_ACCT_NAME_LEN);

    g_ctx.number = 1;
    total = email_mmi_account_data_get_count();
    for (i = 0; i < total; i++)
    {
        if (!email_mmi_account_data_is_imap(i))
        {
            continue;
        }

#ifdef __MMI_SSO__
        if (mmi_email_sso_is_cloud_account())
        {
            continue;
        }
#endif /* __MMI_SSO__ */

        g_ctx.id[g_ctx.number] = email_mmi_account_data_get_id(i);
        mmi_wcsncpy(g_ctx.name[g_ctx.number], 
            email_mmi_account_data_get_name(i), 
            SRV_EMAIL_MAX_ACCT_NAME_LEN);

        if (g_ctx.id[g_ctx.number] == email_mmi_account_data_get_push())
        {
            g_ctx.idx = g_ctx.number;
        }

        g_ctx.number++;
    }

    if (g_ctx.number == 1)
    {
        // Popup No IMAP account
        mmi_email_lib_error_popup(STR_EMAIL_NO_IMAP_ACCOUNT);
        return;
    }

    g_ctx.grp_id = parent;//mmi_frm_group_create_ex(parent, GRP_ID_AUTO_GEN, group_proc, NULL, 0);
    g_ctx.title = STR_EMAIL_SET_IMAPPUSH_ACCOUNT_ID;
    show_ui();
}
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

#endif /* __MMI_EMAIL__ */
