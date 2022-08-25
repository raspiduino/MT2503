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
 *  EmailAppEMN.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email notification function.
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EMAIL__


#if (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__))
#ifndef __MMI_EMAIL_EMN__
#define __MMI_EMAIL_EMN__
#endif /* __MMI_EMAIL_EMN__ */
#endif /* (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__)) */

#ifdef __MMI_EMAIL_EMN__

#include "IdleNotificationManagergprot.h"
#include "mmi_rp_app_email_def.h"
#include "EmailAppGprot.h"
#include "EmailAppProt.h"
#include "emailsrvgprot.h"
#include "EmailAppEMN.h"
#include "app_crc.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "mmi_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "customer_ps_inc.h"
#include "string.h"
#include "NotificationGprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "ProfilesSrvGprot.h"
#include "wgui_categories_list.h"
#include "app_mem.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "mmi_frm_mem_gprot.h"
#include "fs_func.h"
#include "wgui_categories_text_viewer.h"
#include "EmailAppNetwork.h"

/* function declartion */
static void mmi_email_emn_main_process(EMAIL_ACCT_ID acct_id);
static MMI_BOOL mmi_email_emn_add_request_in_queue(EMAIL_ACCT_ID acct_id);

static MMI_BOOL mmi_email_emn_update_account_status(
                    mmi_email_emn_account_status_struct *p_account_status,
                    S32 *p_fs_error);
static MMI_BOOL mmi_email_emn_read_account_status_file(
                    mmi_email_emn_account_status_file_struct *p_emn_file,
                    S32 *p_fs_error);
static void mmi_email_emn_check_active_account_in_boot_up(void);
static MMI_BOOL mmi_email_emn_check_validity_of_status_file(mmi_email_emn_account_status_file_struct *p_emn_file);

static mmi_email_app_emn_struct g_mmi_email_app_emn_cntx;
mmi_email_app_emn_struct *mmi_email_app_emn_p = &g_mmi_email_app_emn_cntx;

/*****************************************************************************
 * FUNCTION
 *  mmi_email_emn_init
 * DESCRIPTION
 *  Init email emn application 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_emn_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_op_result = srv_email_register_emn_notify(
                        0, 
                        mmi_email_emn_main_process, 
                        NULL);

    mmi_email_app_emn_p->emn_request_queue.valid_account_count = 0;
    kal_wsprintf(mmi_email_app_emn_p->emn_file_path, "%s%s", srv_email_get_root_path(), "emn_file.txt");
    mmi_email_emn_check_active_account_in_boot_up();
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EMN_INIT_LOG1, srv_op_result);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_emn_main_process
 * DESCRIPTION
 *  The email emn application main process
 * PARAMETERS
 *  acct_id  [IN] The account's id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_emn_main_process(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EMN_MAIN_PROCESS_LOG1, acct_id);
    if (MMI_TRUE == mmi_email_emn_add_request_in_queue(acct_id))
    {
        mmi_email_app_nwk_emn_do(acct_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_emn_add_request_in_queue
 * DESCRIPTION
 *  Add the request in queue
 * PARAMETERS
 *  acct_id  [IN] The account's id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_email_emn_add_request_in_queue(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    mmi_email_emn_account_status_struct account_status;
    MMI_BOOL return_value = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EMN_ADD_REQUEST_IN_QUEUE_LOG1, mmi_email_app_emn_p->emn_request_queue.valid_account_count, acct_id);
    if (mmi_email_app_emn_p->emn_request_queue.valid_account_count <= MMI_EMAIL_MAX_ACCTS)
    {
        for (i = 0; i < mmi_email_app_emn_p->emn_request_queue.valid_account_count; i++)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EMN_ADD_REQUEST_IN_QUEUE_LOG2, i, mmi_email_app_emn_p->emn_request_queue.account_id[i]);
            if (mmi_email_app_emn_p->emn_request_queue.account_id[i] == acct_id)
            {
                break;
            }
        }
        
        if (i == mmi_email_app_emn_p->emn_request_queue.valid_account_count)
        {
            mmi_email_app_emn_p->emn_request_queue.account_id[i] = acct_id;
            mmi_email_app_emn_p->emn_request_queue.valid_account_count++;
            account_status.account_id = acct_id;
            account_status.status = EMAIL_EMN_Q_AV;
            if (MMI_TRUE == mmi_email_emn_update_account_status(&account_status, NULL))
            {    
                return_value = MMI_TRUE;
            }
        }
    }

    return return_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_receive_emn_result_handler
 * DESCRIPTION
 *  The emn receive finish callback
 * PARAMETERS
 *  acct_id  [IN] The account's id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_receive_emn_result_handler(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    mmi_email_emn_account_status_struct account_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_RECEIVE_EMN_RESULT_HANDLER_LOG1, mmi_email_app_emn_p->emn_request_queue.valid_account_count);

    for (i = 0; i < mmi_email_app_emn_p->emn_request_queue.valid_account_count; i++)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_RECEIVE_EMN_RESULT_HANDLER_LOG2, i, mmi_email_app_emn_p->emn_request_queue.account_id[i], acc_id);
        if (mmi_email_app_emn_p->emn_request_queue.account_id[i] == acc_id)
        {
            for (j = i; j < (mmi_email_app_emn_p->emn_request_queue.valid_account_count - 1); j++)
            {
                mmi_email_app_emn_p->emn_request_queue.account_id[j] = mmi_email_app_emn_p->emn_request_queue.account_id[j + 1];
            }
            mmi_email_app_emn_p->emn_request_queue.valid_account_count--;
            account_status.account_id = acc_id;
            account_status.status = EMAIL_EMN_Q_NA;
            mmi_email_emn_update_account_status(&account_status, NULL);
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_emn_update_account_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_email_emn_update_account_status(
                    mmi_email_emn_account_status_struct *p_account_status,
                    S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL return_value = MMI_TRUE;
    FS_HANDLE file_handle = -1;
    S32 fs_error = FS_NO_ERROR;
    mmi_email_emn_account_status_file_struct *p_emn_file = NULL;
    U32 fs_op_length = 0;
    U32 check_sum = 0;
    S32 i = 0;
    S32 j = 0;
    U8 *p_crc_data_begin = NULL;
    U16 crc_data_length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_LOG1, p_account_status->account_id, p_account_status->status);
    
    p_emn_file = OslMalloc(sizeof(*p_emn_file));
 
	p_crc_data_begin = (U8*)&(p_emn_file->valid_count);
    crc_data_length = (U16)(sizeof(*p_emn_file) - ((U8*)&(p_emn_file->valid_count) - (U8*)(p_emn_file)));

    file_handle = FS_Open(mmi_email_app_emn_p->emn_file_path, FS_READ_WRITE);
    if (file_handle < 0)
    {
        if (FS_FILE_NOT_FOUND == file_handle)
        {
            file_handle = FS_Open(mmi_email_app_emn_p->emn_file_path, FS_READ_WRITE | FS_CREATE);
            if (file_handle < 0)
            {
                fs_error = file_handle;
                return_value = MMI_FALSE;
                goto MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_END;
            }
            memset(p_emn_file, 0, sizeof(*p_emn_file));
        }
        else if (FS_READ_ONLY_ERROR == file_handle)
        {
            fs_error = FS_GetAttributes(mmi_email_app_emn_p->emn_file_path);
            if (fs_error < 0)
            {
                return_value = MMI_FALSE;
                goto MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_END;
            }
            fs_error = FS_SetAttributes(mmi_email_app_emn_p->emn_file_path, (U8)(fs_error & ~(FS_ATTR_READ_ONLY)));
            if (FS_NO_ERROR != fs_error)
            {
                return_value = MMI_FALSE;
                goto MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_END;
            }
            file_handle = FS_Open(mmi_email_app_emn_p->emn_file_path, FS_READ_WRITE);
            if (file_handle < 0)
            {
                fs_error = file_handle;
                return_value = MMI_FALSE;
                goto MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_END;    
            }
            fs_error = FS_Read(file_handle, p_emn_file, sizeof(*p_emn_file), &fs_op_length);
            if (FS_NO_ERROR != fs_error)
            {
                return_value = MMI_FALSE;
                goto MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_END;
            }

            check_sum = applib_crc_update(MMI_EMAIL_EMN_CHECK_SUM, p_crc_data_begin, crc_data_length);
        }
        else
        {
            fs_error = file_handle;
            return_value = MMI_FALSE;
            goto MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_END;
        }
    }
    else
    {
        fs_error = FS_Read(file_handle, p_emn_file, sizeof(*p_emn_file), &fs_op_length);
        if (FS_NO_ERROR != fs_error)
        {
            return_value = MMI_FALSE;
            goto MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_END;
        }

        check_sum = applib_crc_update(MMI_EMAIL_EMN_CHECK_SUM, p_crc_data_begin, crc_data_length);
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_LOG2, check_sum, p_emn_file->check_sum, p_emn_file->valid_count);
    if (check_sum != p_emn_file->check_sum)
    {
        memset(p_emn_file, 0, sizeof(*p_emn_file));
        if (EMAIL_EMN_Q_AV == p_account_status->status)
        {
            p_emn_file->valid_count = 1;
            memcpy(&(p_emn_file->account_status_struct[0]), p_account_status, sizeof(mmi_email_emn_account_status_struct));
        }
    }
    else
    {
        if (EMAIL_EMN_Q_AV == p_account_status->status)
        {
            for (i = 0; i < p_emn_file->valid_count; i++)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_LOG3, i, p_emn_file->account_status_struct[i].account_id);
                if (p_emn_file->account_status_struct[i].account_id == p_account_status->account_id)
                {
                    break;
                }
                else
                {
                }
            }
            if (MMI_EMAIL_MAX_ACCTS == p_emn_file->valid_count)
            {
                return_value = MMI_FALSE;
                goto MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_END;
            }
            else
            {
                if (i == p_emn_file->valid_count)
                {
                    memcpy(&(p_emn_file->account_status_struct[i]), p_account_status, sizeof(mmi_email_emn_account_status_struct));
                    p_emn_file->valid_count++;
                }
                else
                {
                }
            }
        }
        else
        {
            for (i = 0; i < p_emn_file->valid_count; i++)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_LOG4, i, p_emn_file->account_status_struct[i].account_id);
                if (p_emn_file->account_status_struct[i].account_id == p_account_status->account_id)
                {
                    for (j = i; j < (p_emn_file->valid_count - 1); j++)
                    {
                        p_emn_file->account_status_struct[j] = p_emn_file->account_status_struct[j + 1];
                    }
                    p_emn_file->valid_count--;
                    break;
                }
                else
                {
                }
            }
        }
    }

    p_emn_file->check_sum = applib_crc_update(MMI_EMAIL_EMN_CHECK_SUM, p_crc_data_begin, crc_data_length);

    fs_error = FS_Seek(file_handle, 0, FS_FILE_BEGIN);
    if (fs_error < 0)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_END;
    }

    fs_error = FS_Write(file_handle, p_emn_file, sizeof(*p_emn_file), &fs_op_length);
    if (FS_NO_ERROR != fs_error)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_END;
    }

MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_END:
    if (NULL != p_emn_file)
    {
        OslMfree(p_emn_file);
        p_emn_file = NULL;
    }
    
    if (MMI_TRUE == return_value)
    {
        fs_error = FS_Close(file_handle);
        if (FS_NO_ERROR != fs_error)
        {
            return_value = MMI_FALSE;
            if (NULL != p_fs_error)
            {
                *p_fs_error = fs_error;
            }
        }
    }
    else
    {
        if (NULL != p_fs_error)
        {
            *p_fs_error = fs_error;
        }
        if (file_handle >= 0)
        {
            FS_Close(file_handle);
        }
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EMN_UPDATE_ACCOUNT_STATUS_LOG5, return_value, fs_error);
    return return_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_emn_read_account_status_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_email_emn_read_account_status_file(
                    mmi_email_emn_account_status_file_struct *p_emn_file,
                    S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL return_value = MMI_TRUE;
    FS_HANDLE file_handle = -1;
    S32 fs_error = FS_NO_ERROR;
    U32 fs_op_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = FS_Open(mmi_email_app_emn_p->emn_file_path, FS_READ_ONLY);
    if (file_handle < 0)
    {
        fs_error = file_handle;
        return_value = MMI_FALSE;
        goto MMI_EMAIL_EMN_READ_ACCOUNT_STATUS_FILE_END;
    }

    fs_error = FS_Read(file_handle, p_emn_file, sizeof(*p_emn_file), &fs_op_length);
    if (FS_NO_ERROR != fs_error)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_EMN_READ_ACCOUNT_STATUS_FILE_END;
    }

    /* check sum is error, return MMI_FALSE */
    if (MMI_FALSE == mmi_email_emn_check_validity_of_status_file(p_emn_file))
    {
        fs_error = FS_ERROR_RESERVED;
        return_value = MMI_FALSE;
        goto MMI_EMAIL_EMN_READ_ACCOUNT_STATUS_FILE_END;
    }
    
MMI_EMAIL_EMN_READ_ACCOUNT_STATUS_FILE_END:
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
    }
    if ((FS_NO_ERROR != fs_error) && (NULL != p_fs_error))
    {
        *p_fs_error = fs_error;
    }
    return return_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_emn_check_active_account_in_boot_up
 * DESCRIPTION
 *  Check whether is account which does not receive email in last shutdown
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_emn_check_active_account_in_boot_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_emn_account_status_file_struct *p_emn_file = NULL;
    MMI_BOOL read_status = MMI_FALSE;
    S32 fs_error = 0;
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_emn_file = OslMalloc(sizeof(mmi_email_emn_account_status_file_struct));

    read_status = mmi_email_emn_read_account_status_file(p_emn_file, &fs_error);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EMN_CHECK_ACTIVE_ACCOUNT_IN_BOOT_UP_LOG1, read_status, p_emn_file->valid_count, fs_error);
    
    if (read_status && p_emn_file->valid_count > 0)
    {
        mmi_email_app_emn_p->emn_request_queue.valid_account_count = p_emn_file->valid_count;
        for (i = 0; i < p_emn_file->valid_count; i++)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EMN_CHECK_ACTIVE_ACCOUNT_IN_BOOT_UP_LOG2, p_emn_file->account_status_struct[i].account_id);
            mmi_email_app_emn_p->emn_request_queue.account_id[i] = p_emn_file->account_status_struct[i].account_id;

            mmi_email_app_nwk_emn_do(p_emn_file->account_status_struct[i].account_id);
        }
    }
    else
    {
        mmi_email_app_emn_p->emn_request_queue.valid_account_count = 0;
    }
    
    if (NULL != p_emn_file)
    {
        OslMfree(p_emn_file);
        p_emn_file = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_emn_check_validity_of_status_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_email_emn_check_validity_of_status_file(mmi_email_emn_account_status_file_struct *p_emn_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL return_value = MMI_FALSE;
    U32 check_sum = 0;
    U8 *p_crc_data_begin = NULL;
    U16 crc_data_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_crc_data_begin = (U8*)&(p_emn_file->valid_count);
    crc_data_length = (U16)(sizeof(*p_emn_file) - ((U8*)&(p_emn_file->valid_count) - (U8*)(p_emn_file)));

    check_sum = applib_crc_update(MMI_EMAIL_EMN_CHECK_SUM, p_crc_data_begin, crc_data_length);
    if (check_sum == p_emn_file->check_sum)
    {
        return_value = MMI_TRUE;
    }
    else
    {
        return_value = MMI_FALSE;
    }
    
    return return_value;
}

#endif /* __MMI_EMAIL_EMN__ */
#endif /* __MMI_EMAIL__ */
