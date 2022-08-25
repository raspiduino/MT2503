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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "EmailAppProt.h"

#include "EmailAppLib.h"
#include "EmailAppAccountData.h"

typedef struct
{
    EMAIL_ACCT_ID acc_id;
    U32 num_unread;
    U32 num_inbox;
    EMAIL_FLDR_ID fldid[SRV_EMAIL_FLDR_TYPE_BASICS_CNT];

    U32 progress; // Sending / Receiving / Wait Sending / Wait Receiving / Sending Fail / Receiving Fail / Non

}email_mmi_account_data_item_struct;

typedef struct
{
    U32 count;
    EMAIL_ACCT_ID default_id;
    EMAIL_ACCT_ID push_id;
    email_mmi_account_data_item_struct list[MMI_EMAIL_MAX_ACCTS];
}email_mmi_account_data_context_struct;

static email_mmi_account_data_context_struct g_acct_ctx;

static srv_email_acct_info_cache_struct g_email_acc_srvinfo_temp;
static srv_email_acct_folder_struct g_email_fld_srvinfo_temp;

static EMAIL_ACCT_ID get_id(U32 idx);
static S32 get_index(EMAIL_ACCT_ID id);
static email_mmi_account_data_item_struct* get_item_by_index(U32 idx);
static email_mmi_account_data_item_struct* get_item_by_id(EMAIL_ACCT_ID id);

static void set_account_info(EMAIL_ACCT_ID acc_id, email_mmi_account_data_item_struct *p)
{
    S32 folder_num;
    EMAIL_ACCT_HANDLE acct_handle;
    srv_email_result_enum result;

    // Fill in
    memset(p, 0, sizeof(email_mmi_account_data_item_struct));

    result = srv_email_acct_create(0, &acct_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        WARRING();
        return;
    }

    result = srv_email_acct_open(acct_handle, acc_id);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_acct_destroy(acct_handle);
        WARRING();
        return;
    }

    folder_num = SRV_EMAIL_FLDR_TYPE_BASICS_CNT;
    srv_email_acct_get_fldr_id(
        acct_handle,
        SRV_EMAIL_ACCT_FLDR_TYPE_BASIC,
        0,
        &folder_num,
        p->fldid);

    result = srv_email_acct_get_fldr_info(acct_handle, p->fldid[SRV_EMAIL_FLDR_TYPE_INBOX], &g_email_fld_srvinfo_temp);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_acct_destroy(acct_handle);
        WARRING();
        return;
    }

    p->acc_id = acc_id;
    p->num_unread = g_email_fld_srvinfo_temp.unread_count;
    p->num_inbox = g_email_fld_srvinfo_temp.msg_count;

    srv_email_acct_destroy(acct_handle);
}

void email_mmi_account_data_init(void)
{
    S32 i,temp;
    U32 count;
    EMAIL_ACCT_ID acc_id;

    srv_email_result_enum result;
    email_mmi_account_data_item_struct *p;

    count = email_mmi_account_data_get_count();
    for (i = 0; i < (S32)count/*MMI_EMAIL_MAX_ACCTS*/; i++)
    {
        p = &g_acct_ctx.list[i];
        memset(p, 0, sizeof(email_mmi_account_data_item_struct));
        p->acc_id = EMAIL_ACCT_INVALID_ID;

        temp = 1;
        acc_id = EMAIL_ACCT_INVALID_ID;
        result = srv_email_acct_get_acct_id(i, &temp, &acc_id);
        if (result != SRV_EMAIL_RESULT_SUCC || temp != 1 || acc_id == EMAIL_ACCT_INVALID_ID)
        {
            WARRING();
            continue;
        }

        set_account_info(acc_id, p);
    }

    for (; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        p = &g_acct_ctx.list[i];
        memset(p, 0, sizeof(email_mmi_account_data_item_struct));
        p->acc_id = EMAIL_ACCT_INVALID_ID;
    }

    // Default ACCOUNT ID
    g_acct_ctx.default_id = EMAIL_ACCT_INVALID_ID;
    result = srv_email_acct_get_default(&g_acct_ctx.default_id);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        g_acct_ctx.default_id = EMAIL_ACCT_INVALID_ID;
    }

    // PUSH ACCOUNT ID
#ifdef __MMI_EMAIL_IMAP_PUSH__
    g_acct_ctx.push_id = mmi_email_lib_get_push_account();
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

}

void email_mmi_account_data_add(EMAIL_ACCT_ID acct_id)
{
    U32 i;
    email_mmi_account_data_item_struct *p;

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        p = &g_acct_ctx.list[i];
        if (p->acc_id == EMAIL_ACCT_INVALID_ID)
        {
            set_account_info(acct_id, p);
            return;
        }
    }

    ASSERT(0);
}

void email_mmi_account_data_del(EMAIL_ACCT_ID acct_id)
{
    U32 i;
    email_mmi_account_data_item_struct *p1, *p2;

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        p1 = &g_acct_ctx.list[i];
        if (p1->acc_id == acct_id)
        {
            break;
        }
    }

    if (i == MMI_EMAIL_MAX_ACCTS)
    {
        return;
    }

    p2 = NULL;
    for (; i < MMI_EMAIL_MAX_ACCTS - 1; i++)
    {
        // Copy next to this
        p1 = &g_acct_ctx.list[i];
        p2 = &g_acct_ctx.list[i+1];
        memcpy(p1, p2, sizeof(email_mmi_account_data_item_struct));
    }

    if (p2 == NULL)
    {
        p2 = p1;
    }

    memset(p2, 0, sizeof(email_mmi_account_data_item_struct));
    p2->acc_id = EMAIL_ACCT_INVALID_ID;

    if (g_acct_ctx.default_id == acct_id)
    {
        email_mmi_account_data_set_default(EMAIL_ACCT_INVALID_ID);
    }

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (g_acct_ctx.push_id == acct_id)
    {
        email_mmi_account_data_set_push(EMAIL_ACCT_INVALID_ID);
    }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
}


U32 email_mmi_account_data_get_count(void)
{
    U32 count = 0;
    srv_email_result_enum result;

    result = srv_email_acct_get_num(&count);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        WARRING();
        return 0;
    }

    return count;
}

static EMAIL_ACCT_ID get_id(U32 idx)
{
    ASSERT((U32)idx < email_mmi_account_data_get_count());
    ASSERT(email_mmi_account_data_get_count() <= MMI_EMAIL_MAX_ACCTS);

    return g_acct_ctx.list[idx].acc_id;
}

static S32 get_index(EMAIL_ACCT_ID id)
{
    S32 i;
    email_mmi_account_data_item_struct *p;

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        p = &g_acct_ctx.list[i];
        if (p->acc_id == id)
        {
            return i;
        }
    }

    ASSERT(0);
    return -1;
}

static email_mmi_account_data_item_struct* get_item_by_index(U32 idx)
{
    ASSERT((U32)idx < email_mmi_account_data_get_count());
    ASSERT(email_mmi_account_data_get_count() <= MMI_EMAIL_MAX_ACCTS);

    return &g_acct_ctx.list[idx];
}

static email_mmi_account_data_item_struct* get_item_by_id(EMAIL_ACCT_ID id)
{
    return get_item_by_index(get_index(id));
}

EMAIL_ACCT_ID email_mmi_account_data_get_id(U32 idx)
{
    return get_id(idx);
}


extern EMAIL_FLDR_ID email_mmi_account_data_get_fldid(EMAIL_ACCT_ID acct_id, U32 fld_idx)
{
    email_mmi_account_data_item_struct *p;

    p = get_item_by_id(acct_id);
    if (p == NULL)
    {
        return EMAIL_FLDR_INVALID_ID;
    }

    ASSERT(fld_idx < SRV_EMAIL_FLDR_TYPE_BASICS_CNT);
    return p->fldid[fld_idx];
}


BOOL email_mmi_account_data_is_imap(U32 idx)
{
    g_email_acc_srvinfo_temp.protocol = SRV_EMAIL_PROT_POP3;
    srv_email_acct_cache_get(get_id(idx), &g_email_acc_srvinfo_temp);

    return (g_email_acc_srvinfo_temp.protocol == SRV_EMAIL_PROT_IMAP4);
}

BOOL email_mmi_account_data_is_imap_accid(EMAIL_ACCT_ID acct_id)
{
    g_email_acc_srvinfo_temp.protocol = SRV_EMAIL_PROT_POP3;
    srv_email_acct_cache_get(acct_id, &g_email_acc_srvinfo_temp);

    return (g_email_acc_srvinfo_temp.protocol == SRV_EMAIL_PROT_IMAP4);
}

const WCHAR* email_mmi_account_data_get_name(U32 idx)
{
    g_email_acc_srvinfo_temp.acct_name[0] = 0;
    srv_email_acct_cache_get(get_id(idx), &g_email_acc_srvinfo_temp);

    return g_email_acc_srvinfo_temp.acct_name;
}

const WCHAR* email_mmi_account_data_get_hint(U32 idx)
{
    static WCHAR hint[32];
    email_mmi_account_data_item_struct *p;

    p = get_item_by_index(idx);
    kal_wsprintf(
        hint,
        "(%d / %d)",
        p->num_unread,
        p->num_inbox);

    return hint;
}


// default / push / both / non
U16 email_mmi_account_data_get_icon1(U32 idx)
{
    email_mmi_account_data_item_struct *p;

    p = get_item_by_index(idx);
    if ((p->acc_id == g_acct_ctx.default_id) && (p->acc_id == g_acct_ctx.push_id))
    {
        return IMG_EMAIL_ACCTYPE_BOTH;
    }
    else if (p->acc_id == g_acct_ctx.default_id)
    {
        return IMG_EMAIL_ACCTYPE_DEFAULT;
    }
    else if (p->acc_id == g_acct_ctx.push_id)
    {
        return IMG_EMAIL_ACCTYPE_PUSH;
    }
    else
    {
        return IMG_EMAIL_ACCTYPE_NORMAL;
    }
}


// progress
U16 email_mmi_account_data_get_icon2(U32 idx)
{
    // TODO...
    email_mmi_account_data_item_struct* p;
    U32 s;

    p = get_item_by_index(idx);
    if (p == NULL)
    {
        return 0;
    }

    s = p->progress;
    if (s & EMACC_S_RECEIVING)
    {
        return IMG_EMAIL_ACC_STATUS_RECEIVING;
    }

    if (s & EMACC_S_SENDING)
    {
        return IMG_EMAIL_ACC_STATUS_SENDING;
    }

    if (s & EMACC_S_RECEIVEFAIL)
    {
        return IMG_EMAIL_ACC_STATUS_RECEIVEFAIL;
    }

    if (s & EMACC_S_SENDFAIL)
    {
        return IMG_EMAIL_ACC_STATUS_SENDFAIL;
    }

    return 0;
}


void email_mmi_account_data_reset_status(void)
{
    S32 i;
    email_mmi_account_data_item_struct *p;

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        p = &g_acct_ctx.list[i];
        p->progress = 0;
    }
}


void email_mmi_account_data_set_refresh_status(EMAIL_ACCT_ID acct_id, email_mmi_account_state_enum s)
{
    email_mmi_account_data_item_struct* p;

    p = get_item_by_id(acct_id);

    p->progress &= ~(EMACC_S_TORECEIVE | EMACC_S_RECEIVING | EMACC_S_RECEIVEFAIL);
    p->progress |= s;

    mmi_email_ui_refresh_mainmenu();
}

void email_mmi_account_data_set_send_status(EMAIL_ACCT_ID acct_id, email_mmi_account_state_enum s)
{
    email_mmi_account_data_item_struct* p;

    p = get_item_by_id(acct_id);

    p->progress &= ~(EMACC_S_TOSEND | EMACC_S_SENDING | EMACC_S_SENDFAIL);
    p->progress |= s;

    mmi_email_ui_refresh_mainmenu();
}


EMAIL_ACCT_ID email_mmi_account_data_get_default(void)
{
    return g_acct_ctx.default_id;
}


void email_mmi_account_data_set_default(EMAIL_ACCT_ID id)
{
    g_acct_ctx.default_id = id;
    if (id == EMAIL_ACCT_INVALID_ID)
    {
        srv_email_acct_del_default();
    }
    else
    {
        srv_email_acct_set_default(id);
    }
}


#ifdef __MMI_EMAIL_IMAP_PUSH__
EMAIL_ACCT_ID email_mmi_account_data_get_push(void)
{
    return g_acct_ctx.push_id;
}

void email_mmi_account_data_set_push(EMAIL_ACCT_ID id)
{
    g_acct_ctx.push_id = id;
    mmi_email_lib_set_push_account(id);
}
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

void email_mmi_account_data_update_inbox_number(EMAIL_ACCT_ID acct_id, U32 num_unread, U32 num_inbox)
{
    email_mmi_account_data_item_struct* p;

    p = get_item_by_index(get_index(acct_id));

    if (num_inbox == 0xFFFFFFFF)
    {
        set_account_info(acct_id, p);
    }
    else
    {
        p->num_unread = num_unread;
        p->num_inbox = num_inbox;
    }
}


#endif /* __MMI_EMAIL__ */

