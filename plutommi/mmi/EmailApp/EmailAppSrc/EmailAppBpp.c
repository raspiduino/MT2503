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
 *  EmailAppBPP.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email bpp function.
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EMAIL__
#ifdef __MMI_BPP20_SUPPORT__
#include "Conversions.h"
#include "mmi_rp_app_email_def.h"
#include "EmailAppProt.h"
#include "EmailSrvgprot.h"
#include "EmailAppBpp.h"
#include "BppCuiGprot.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "BppXhtmlGprot.h"
#include "kal_general_types.h"
#include "string.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "app_datetime.h"
#include "gui_typedef.h"
#include "gui_data_types.h"
#include "wgui.h"
#include "wgui_categories_util.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "FileMgrSrvGProt.h"
#include "fs_func.h"
#include "stdio.h"

//#define __MMI_EMAIL_BPP_DEBUG__
static const U16 mmi_email_bpp_field[MMI_EMAIL_BPP_FIELD_TOTAL] =
{
    STR_EMAIL_FROM_ID,
    STR_GLOBAL_TIME,
    STR_GLOBAL_PRIORITY,
    STR_EMAIL_TO_ID,
    STR_EMAIL_CC_ID,
    STR_EMAIL_BCC_ID,
    STR_GLOBAL_SUBJECT,
};

static xhtml_prop_struct email_title_props[] = {
        {XHTML_PROP_VERTICAL_ALIGN,   "top"},
        {XHTML_PROP_FONT_WEIGHT,      "bold"}
    };
static xhtml_rule_struct email_title_rule = {
        "title",
        NULL,
        STYLE_RULE_CLASS,
        email_title_props, 
        2
    };

static xhtml_prop_struct email_value_props[] = {
        {XHTML_PROP_PADDING_LEFT,   "20mm"}
    };

static xhtml_rule_struct email_value_rule = {
        "value",
        NULL,
        STYLE_RULE_CLASS,
        email_value_props, 
        1
    };
static mmi_ret mmi_email_bpp_print_proc(mmi_event_struct *p_event);
static S32 mmi_email_compose_xhtml_file(U32 bpp_inst, WCHAR *file, mmi_email_bpp_cntx_struct *p_bpp_cntx_struct);
static S32 mmi_email_bpp_compose_header(void *xhtml, mmi_email_bpp_cntx_struct *p_bpp_cntx_struct, CHAR * buff, U32 buf_size);
static S32 mmi_email_bpp_compose_content(void *xhtml, mmi_email_bpp_cntx_struct *p_bpp_cntx_struct, CHAR * buff, U32 buf_size);
static S32 mmi_email_bpp_compose_attachment(void *xhtml, mmi_email_bpp_cntx_struct *p_bpp_cntx_struct, CHAR * buff, U32 buf_size);

static mmi_email_bpp_cntx_struct g_mmi_email_bpp_cntx;
static mmi_email_bpp_cntx_struct *mmi_email_bpp_cntx_p = &g_mmi_email_bpp_cntx;

/*****************************************************************************
 * FUNCTION
 *  mmi_email_bpp_print
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_bpp_print(mmi_id parent_id, mmi_email_bpp_mail_struct *p_mail_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&(mmi_email_bpp_cntx_p->mail), p_mail_struct, sizeof(*p_mail_struct));
    mmi_email_bpp_cntx_p->bpp_group_id = mmi_frm_group_create(
                                            parent_id, 
                                            GRP_ID_AUTO_GEN, 
                                            mmi_email_bpp_print_proc, 
                                            mmi_email_bpp_cntx_p);
    mmi_frm_group_enter(mmi_email_bpp_cntx_p->bpp_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
#ifndef __MMI_EMAIL_BPP_DEBUG__
    cui_bt_printing_launch(
        mmi_email_bpp_cntx_p->bpp_group_id, 
        BT_PRINT_EMAIL, 
        NULL,
        0);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_PRINT_LOG1, parent_id, mmi_email_bpp_cntx_p->bpp_group_id, p_mail_struct);
#else
    {
            EMAIL_MSG_HANDLE msg_handle = EMAIL_MSG_INVALID_HANDLE;
            srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
            S32 file_size = 0;

            srv_op_result = srv_email_msg_create(mmi_email_bpp_cntx_p->srv_handle, &msg_handle);
            if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
            {
                goto MMI_EMAIL_BPP_PRINT_PROC_DATA_REQ_END;
            }
            
            srv_op_result = srv_email_msg_open(
                                msg_handle, 
                                mmi_email_bpp_cntx_p->mail.account_id, 
                                mmi_email_bpp_cntx_p->mail.folder_id, 
                                mmi_email_bpp_cntx_p->mail.msg_id);
            if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
            {
                goto MMI_EMAIL_BPP_PRINT_PROC_DATA_REQ_END;
            }
            else
            {
                mmi_email_bpp_cntx_p->msg_handle = msg_handle;
            }
            srv_op_result = srv_email_msg_get_basic_info(
                                msg_handle, 
                                &(mmi_email_bpp_cntx_p->msg_basic_info));
            if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
            {
                goto MMI_EMAIL_BPP_PRINT_PROC_DATA_REQ_END;
            }
            
            file_size = mmi_email_compose_xhtml_file(
                            0, 
                            L"D:\\test_bpp.txt",
                            mmi_email_bpp_cntx_p);
            if (file_size >= 0)
            {
                mmi_email_lib_succ_popup(STR_GLOBAL_OK);
            }
            else
            {
            }

            
        MMI_EMAIL_BPP_PRINT_PROC_DATA_REQ_END:
            if (EMAIL_MSG_INVALID_HANDLE != msg_handle)
            {
                srv_email_msg_destroy(msg_handle);
            }
        }
#endif
    return;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_bpp_print_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_email_bpp_print_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_bpp_cntx_struct *p_bpp_cntx_struct = NULL;
    EMAIL_MSG_HANDLE msg_handle = EMAIL_MSG_INVALID_HANDLE;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    evt_bt_print_data_req_struct *p_bt_data_req_event = NULL;
    S32 file_size = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_bpp_cntx_struct = (mmi_email_bpp_cntx_struct*)(p_event->user_data);
    p_bt_data_req_event = (evt_bt_print_data_req_struct*)p_event;
    
    switch (p_event->evt_id)
    {
        case EVT_BT_PRINT_START:
        {
            break;
        }
        case EVT_BT_PRINT_DATA_REQ:
        {
            srv_op_result = srv_email_msg_create(p_bpp_cntx_struct->srv_handle, &msg_handle);
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL, 
                MMI_EMAIL_BPP_PRINT_PROC_LOG1, 
                p_bpp_cntx_struct->srv_handle,
                msg_handle,
                srv_op_result);
            if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
            {
                goto MMI_EMAIL_BPP_PRINT_PROC_DATA_REQ_END;
            }
            else
            {
                p_bpp_cntx_struct->msg_handle = msg_handle;
            }

            srv_op_result = srv_email_msg_open(
                                msg_handle, 
                                p_bpp_cntx_struct->mail.account_id, 
                                p_bpp_cntx_struct->mail.folder_id, 
                                p_bpp_cntx_struct->mail.msg_id);
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL, 
                MMI_EMAIL_BPP_PRINT_PROC_LOG2, 
                p_bpp_cntx_struct->mail.account_id,
                p_bpp_cntx_struct->mail.folder_id,
                p_bpp_cntx_struct->mail.msg_id,
                srv_op_result);
            if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
            {
                goto MMI_EMAIL_BPP_PRINT_PROC_DATA_REQ_END;
            }
            
            srv_op_result = srv_email_msg_get_basic_info(
                                msg_handle, 
                                &(p_bpp_cntx_struct->msg_basic_info));
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_PRINT_PROC_LOG3, srv_op_result);
            if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
            {
                goto MMI_EMAIL_BPP_PRINT_PROC_DATA_REQ_END;
            }
            
            file_size = mmi_email_compose_xhtml_file(
                            p_bt_data_req_event->inst, 
                            p_bt_data_req_event->storage.u.file,
                            p_bpp_cntx_struct);
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_PRINT_PROC_LOG4, p_bt_data_req_event->inst, file_size);
            if (file_size >= 0)
            {
                p_bt_data_req_event->storage.size = (U32)file_size;
                cui_bt_printing_set_data(p_bt_data_req_event->inst, &(p_bt_data_req_event->storage));
            }
            else
            {
                goto MMI_EMAIL_BPP_PRINT_PROC_DATA_REQ_END;
            }

            
        MMI_EMAIL_BPP_PRINT_PROC_DATA_REQ_END:
            if (EMAIL_MSG_INVALID_HANDLE != msg_handle)
            {
                srv_email_msg_destroy(msg_handle);
            }
            break;
        }
        case EVT_BT_PRINT_COMPLETE:
        {
            break;

        }
        default:
        {
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_bpp_compose_addr
 * DESCRIPTION
 *  The function composes the mail's address.
 * PARAMETERS
 *  pbuf            [OUT]       Used to store the email address
 *  buf_size        [IN]        The buffer's size
 *  disp_name       [IN]        The display name
 *  email_addr      [IN]        The email address
 * RETURNS
 *  The compose size
 *****************************************************************************/
static S32 mmi_email_bpp_compose_addr(CHAR *buff, U32 buf_size, CHAR *disp_name, CHAR *email_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 offset = 0, len, end_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(disp_name))
    {
        /* Write the left quota */
        buff[offset++] = '"';

        /* Write the display name */
        len = mmi_chset_convert_ex(CHSET_UCS2, CHSET_UTF8, disp_name, &buff[offset], buf_size-offset, &end_pos);
        if (*((WCHAR *)end_pos) != L'\0')
            return EMAIL_BPP_ERROR;
        offset += (len - 1);

        /* Write the right quota */
        buff[offset++] = '\"';

        /* Write the space between the display name and the email address */
        buff[offset++] = ' ';
    }

    if (mmi_ucs2strlen(email_addr))
    {
        /* Write the left character (<) of the email address */
        buff[offset++] = '<';

        /* Write the email address */
        len = mmi_chset_convert_ex(CHSET_UCS2, CHSET_UTF8, email_addr, &buff[offset], buf_size-offset, &end_pos);
        if (*((WCHAR *)end_pos) != L'\0')
            return EMAIL_BPP_ERROR;
        offset += (len - 1);

        /* Write the right character (>) of the email address */
        buff[offset++] = '>';
    }
    buff[offset] = '\0';

    return offset;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_bpp_compose_header
 * DESCRIPTION
 *  The function composes the mail's header.
 * PARAMETERS
 *  fh              [IN]        The file handle
 *  pbuf            [OUT]       Used to store the header information
 *  buf_remain      [IN]        The remained buffer size
 * RETURNS
 *  Success: >= 0
 *  Failure: < 0
 *****************************************************************************/
static S32 mmi_email_bpp_compose_header(void *xhtml, mmi_email_bpp_cntx_struct *p_bpp_cntx_struct, CHAR *buff, U32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *field_str = NULL;
    U32 len = 0;
    U32 offset = 0;
    email_bpp_ret_code_enum ret = EMAIL_BPP_SUCCESS;
    U8 i = 0;
    U8 index = 0;
    xhtml_attr_struct attr;
    srv_email_msg_get_recipient_struct *p_recipient = NULL;
    WCHAR *p_subject = NULL;
    U32 subject_len = 0;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_COMPOSE_HEADER_LOG1, xhtml, p_bpp_cntx_struct, buff, buf_size);
    bpp_xhtml_element_begin(xhtml, XHTML_ELE_DIV, NULL, 0);
    bpp_xhtml_element_begin(xhtml, XHTML_ELE_TABLE, NULL, 0);

    for (i = MMI_EMAIL_BPP_FROM; i < MMI_EMAIL_BPP_FIELD_TOTAL; i++)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_COMPOSE_HEADER_LOG2, i);
    #ifndef __MMI_EMAIL_BCC__
        if (i == MMI_EMAIL_BPP_BCC)
        {
            continue;
        }
    #endif /* __MMI_EMAIL_BCC__ */

        /* Compose the field name */
        bpp_xhtml_element_begin(xhtml, XHTML_ELE_TABLE_ROW, NULL, 0);
        
        attr.name = XHTML_ATTR_CLASS;
        attr.value = "title";
        bpp_xhtml_element_begin(xhtml, XHTML_ELE_TABLE_CELL, &attr, 1);

        field_str = GetString(mmi_email_bpp_field[i]);
        len = mmi_chset_convert(CHSET_UCS2, CHSET_UTF8, field_str, buff, buf_size);
        buf_size -= (len - 1);
        
        /* Write the colon */
        field_str = GetString(STR_EMAIL_COLON_ID);
        len = mmi_chset_convert(CHSET_UCS2, CHSET_UTF8, field_str, &buff[len - 1], buf_size);
        buf_size -= (len - 1);

        bpp_xhtml_element_data(xhtml, buff);

        bpp_xhtml_element_end(xhtml, XHTML_ELE_TABLE_CELL);

        attr.name = XHTML_ATTR_CLASS;
        attr.value = "value";
        bpp_xhtml_element_begin(xhtml, XHTML_ELE_TABLE_CELL, &attr, 1);

        switch (i)
        {
            buf_size = MMI_EMAIL_BPP_COMPOSE_BUF_SIZE;
            case MMI_EMAIL_BPP_FROM:
            {
                srv_email_addr_struct *p_addr_info = NULL;

                p_addr_info = OslMalloc(sizeof(srv_email_addr_struct));
                srv_op_result = srv_email_msg_get_sender(p_bpp_cntx_struct->msg_handle, p_addr_info);
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_COMPOSE_HEADER_LOG3, srv_op_result);

                if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
                {
                    ret = mmi_email_bpp_compose_addr(
                            buff, 
                            buf_size,
                            p_addr_info->disp_name,
                            p_addr_info->email_addr);

                    bpp_xhtml_element_data(xhtml, buff);
                }

                if (NULL != p_addr_info)
                {
                    OslMfree(p_addr_info);
                    p_addr_info = NULL;
                }
        	    break;
            }
            case MMI_EMAIL_BPP_TIME:
            {
                applib_time_struct time_info;
                WCHAR str_buff[30] = {0};

                len = 0;
                applib_dt_utc_sec_2_mytime(
                    p_bpp_cntx_struct->msg_basic_info.mail_date, 
                    &time_info,
                    KAL_FALSE);

                /* date zone */
                date_string((UI_time*)&time_info, (UI_string_type)str_buff, DT_IDLE_SCREEN);
                if (0 != str_buff[0])
                {
                    len = mmi_chset_convert(
                            CHSET_UCS2, 
                            CHSET_UTF8, 
                            (char*)str_buff, 
                            buff, 
                            buf_size);
                    //bpp_xhtml_element_data(xhtml, buff);
                    buff[len - 1] = ' ';
                    buf_size -= (len);
                }

                /* time zone */
                time_string((UI_time*)&time_info, (UI_string_type)str_buff, DT_IDLE_SCREEN);
                if (0 != str_buff[0])
                {
                    len = mmi_chset_convert(
                            CHSET_UCS2, 
                            CHSET_UTF8, 
                            (char*)str_buff, 
                            &buff[len], 
                            buf_size);
                }
                bpp_xhtml_element_data(xhtml, buff);
        	    break;

            }

            case MMI_EMAIL_BPP_PRIORITY:
            {
                U16 pri_str_id = 0;
                CHAR *pri_str = NULL;

                if (p_bpp_cntx_struct->msg_basic_info.priority == 0)
                {
                    pri_str_id = STR_GLOBAL_MEDIUM;
                }
                else if (p_bpp_cntx_struct->msg_basic_info.priority == 2)
                {
                    pri_str_id = STR_GLOBAL_HIGH;
                }
                else
                {
                    pri_str_id = STR_GLOBAL_LOW;
                }

                pri_str = GetString(pri_str_id);

                mmi_chset_convert(CHSET_UCS2, CHSET_UTF8, pri_str, buff, buf_size);
                bpp_xhtml_element_data(xhtml, buff);
                break;
            }

            case MMI_EMAIL_BPP_TO:
            {
                p_recipient = OslMalloc(sizeof(srv_email_msg_get_recipient_struct));
                p_recipient->addr_list = OslMalloc(sizeof(srv_email_addr_struct));
                p_recipient->type = SRV_EMAIL_ADDR_TYPE_TO;
                p_recipient->number = 1;
                
                for (index = 0; index < p_bpp_cntx_struct->msg_basic_info.to_addr_num; index++)
                {
                    p_recipient->start_index = index;
                    srv_op_result = srv_email_msg_get_recipient(p_bpp_cntx_struct->msg_handle, p_recipient);
                    MMI_TRACE(
                        MMI_INET_TRC_G9_EMAIL, 
                        MMI_EMAIL_BPP_COMPOSE_HEADER_LOG4, 
                        index, 
                        p_bpp_cntx_struct->msg_basic_info.to_addr_num, 
                        srv_op_result);
                    
                    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
                    {
                        OslMfree(p_recipient->addr_list);
                        p_recipient->addr_list = NULL;
                        OslMfree(p_recipient);
                        p_recipient = NULL;
                        ret = EMAIL_BPP_ERROR;
                        goto BPP_ERROR_CLEAN;
                    }
                    ret = mmi_email_bpp_compose_addr(
                            buff,
                            buf_size,
                            p_recipient->addr_list->disp_name,
                            p_recipient->addr_list->email_addr);


                    if ((p_bpp_cntx_struct->msg_basic_info.to_addr_num > 1) && 
                        (index < p_bpp_cntx_struct->msg_basic_info.to_addr_num - 1))
                    {
                        strcat(buff, "; ");
                    }
                    bpp_xhtml_element_data(xhtml, buff);
                }
                OslMfree(p_recipient->addr_list);
                p_recipient->addr_list = NULL;
                OslMfree(p_recipient);
                p_recipient = NULL;
                break;
            }

            case MMI_EMAIL_BPP_CC:
            {
                p_recipient = OslMalloc(sizeof(srv_email_msg_get_recipient_struct));
                p_recipient->addr_list = OslMalloc(sizeof(srv_email_addr_struct));
                p_recipient->type = SRV_EMAIL_ADDR_TYPE_CC;
                p_recipient->number = 1;
                
                for (index = 0; index < p_bpp_cntx_struct->msg_basic_info.cc_addr_num; index++)
                {
                    p_recipient->start_index = index;
                    srv_op_result = srv_email_msg_get_recipient(p_bpp_cntx_struct->msg_handle, p_recipient);
                    MMI_TRACE(
                        MMI_INET_TRC_G9_EMAIL, 
                        MMI_EMAIL_BPP_COMPOSE_HEADER_LOG5, 
                        index, 
                        p_bpp_cntx_struct->msg_basic_info.cc_addr_num, 
                        srv_op_result);
                    
                    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
                    {
                        OslMfree(p_recipient->addr_list);
                        p_recipient->addr_list = NULL;
                        OslMfree(p_recipient);
                        p_recipient = NULL;
                        ret = EMAIL_BPP_ERROR;
                        goto BPP_ERROR_CLEAN;
                    }
                    ret = mmi_email_bpp_compose_addr(
                            buff,
                            buf_size,
                            p_recipient->addr_list->disp_name,
                            p_recipient->addr_list->email_addr);


                    if ((p_bpp_cntx_struct->msg_basic_info.cc_addr_num > 1) && 
                        (index < p_bpp_cntx_struct->msg_basic_info.cc_addr_num - 1))
                    {
                        strcat(buff, "; ");
                    }
                    bpp_xhtml_element_data(xhtml, buff);
                }
                OslMfree(p_recipient->addr_list);
                p_recipient->addr_list = NULL;
                OslMfree(p_recipient);
                p_recipient = NULL;
                break;
            }
        #ifdef __MMI_EMAIL_BCC__
            case MMI_EMAIL_BPP_BCC:
            {
                p_recipient = OslMalloc(sizeof(srv_email_msg_get_recipient_struct));
                p_recipient->addr_list = OslMalloc(sizeof(srv_email_addr_struct));
                p_recipient->type = SRV_EMAIL_ADDR_TYPE_BCC;
                p_recipient->number = 1;
                
                for (index = 0; index < p_bpp_cntx_struct->msg_basic_info.bcc_addr_num; index++)
                {
                    p_recipient->start_index = index;
                    srv_op_result = srv_email_msg_get_recipient(p_bpp_cntx_struct->msg_handle, p_recipient);

                    MMI_TRACE(
                        MMI_INET_TRC_G9_EMAIL, 
                        MMI_EMAIL_BPP_COMPOSE_HEADER_LOG6, 
                        index, 
                        p_bpp_cntx_struct->msg_basic_info.bcc_addr_num, 
                        srv_op_result);
                    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
                    {
                        OslMfree(p_recipient->addr_list);
                        p_recipient->addr_list = NULL;
                        OslMfree(p_recipient);
                        p_recipient = NULL;
                        ret = EMAIL_BPP_ERROR;
                        goto BPP_ERROR_CLEAN;
                    }
                    ret = mmi_email_bpp_compose_addr(
                            buff,
                            buf_size,
                            p_recipient->addr_list->disp_name,
                            p_recipient->addr_list->email_addr);


                    if ((p_bpp_cntx_struct->msg_basic_info.bcc_addr_num > 1) && 
                        (index < p_bpp_cntx_struct->msg_basic_info.bcc_addr_num - 1))
                    {
                        strcat(buff, "; ");
                    }
                    bpp_xhtml_element_data(xhtml, buff);
                }
                OslMfree(p_recipient->addr_list);
                p_recipient->addr_list = NULL;
                OslMfree(p_recipient);
                p_recipient = NULL;
                break;
            }
        #endif /* __MMI_EMAIL_BCC__ */

            case MMI_EMAIL_BPP_SUBJECT:
            {
                p_subject = OslMalloc(MMI_EMAIL_BPP_COMPOSE_BUF_SIZE);
                subject_len = MMI_EMAIL_BPP_COMPOSE_BUF_SIZE / sizeof(WCHAR);
                srv_op_result = srv_email_msg_get_subject(
                                    p_bpp_cntx_struct->msg_handle, 
                                    p_subject, 
                                    &subject_len);
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_COMPOSE_HEADER_LOG7, subject_len, srv_op_result);
                if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
                {
                    if (subject_len > (MMI_EMAIL_BPP_COMPOSE_BUF_SIZE / sizeof(WCHAR) - 1))
                    {
                        subject_len = (MMI_EMAIL_BPP_COMPOSE_BUF_SIZE / sizeof(WCHAR) - 1);
                    }
                    p_subject[subject_len] = 0;
                    if (0 != p_subject[0])
                    {
                        mmi_chset_convert(
                            CHSET_UCS2, 
                            CHSET_UTF8, 
                            (char*)p_subject,
                            buff,
                            buf_size);
                        bpp_xhtml_element_data(xhtml, buff);
                    }
                    OslMfree(p_subject);
                    p_subject = NULL;
                }
                else
                {
                    OslMfree(p_subject);
                    p_subject = NULL;
                    ret = EMAIL_BPP_ERROR;
                    goto BPP_ERROR_CLEAN;
                }
                break;
            }

            default:
                goto BPP_ERROR_CLEAN;
                break;
        }

        bpp_xhtml_element_end(xhtml, XHTML_ELE_TABLE_CELL);
        bpp_xhtml_element_end(xhtml, XHTML_ELE_TABLE_ROW);
    }

    bpp_xhtml_element_end(xhtml, XHTML_ELE_TABLE);
    bpp_xhtml_element_end(xhtml, XHTML_ELE_DIV);

BPP_ERROR_CLEAN:
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_bpp_compose_content
 * DESCRIPTION
 *  The function composes the mail's header.
 * PARAMETERS
 *  fh              [IN]        The file handle
 *  pbuf            [OUT]       Used to store the content information
 *  buf_remain      [IN]        The remained buffer size
 * RETURNS
 *  Success: >= 0
 *  Failure: < 0
 *****************************************************************************/
static S32 mmi_email_bpp_compose_content(void *xhtml, mmi_email_bpp_cntx_struct *p_bpp_cntx_struct, CHAR *buff, U32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cont_len = 0;
    U32 curr_len = 0;
    WCHAR *start_ptr = NULL;
    U32 ucs2_buf_len = 0;
    email_bpp_ret_code_enum ret = EMAIL_BPP_SUCCESS;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    S32 charset = CHSET_BASE;
    WCHAR *bpp_file_path = NULL;
    FS_HANDLE file_handle = -1;
    S32 fs_error = FS_NO_ERROR;
    U32 read_size = 0;
    S8 text_status = 0;
    S8 html_status = 0;
    WCHAR *p_html_data = NULL;
    S32 html_cont_len = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_op_result = srv_email_msg_cont_status(p_bpp_cntx_struct->msg_handle, &text_status, &html_status);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        ret = EMAIL_BPP_ERROR;
        goto MMI_EMAIL_APP_COMPOSE_CONTENT_END;
    }
    if (text_status & SRV_EMAIL_MSG_CONT_PART_EXIST)
    {
        srv_op_result = srv_email_msg_get_content_len(
                            p_bpp_cntx_struct->msg_handle, 
                            &cont_len, 
                            &charset);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_COMPOSE_CONTENT_LOG1, cont_len, charset, srv_op_result);
        if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
        {
            ret = EMAIL_BPP_ERROR;
            goto MMI_EMAIL_APP_COMPOSE_CONTENT_END;
        }

        start_ptr = OslMalloc(MMI_EMAIL_BPP_COMPOSE_BUF_SIZE / sizeof(WCHAR));
        
        bpp_xhtml_element_begin(xhtml, XHTML_ELE_DIV, NULL, 0);
        bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, NULL, 0);

        if (cont_len > MMI_EMAIL_BPP_ENCODE_CONT_LEN)
        {
            bpp_file_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
            kal_wsprintf(bpp_file_path, "%s%s", srv_email_get_root_path(), "bpp_file.txt");
            cont_len += 2; 
            srv_op_result = srv_email_msg_get_content(
                                p_bpp_cntx_struct->msg_handle, 
                                MMI_FALSE, 
                                bpp_file_path, 
                                &cont_len);
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_COMPOSE_CONTENT_LOG2, srv_op_result);
            
            if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
            {
                ret = EMAIL_BPP_ERROR;
                goto MMI_EMAIL_APP_COMPOSE_CONTENT_END;
            }
    		file_handle = FS_Open(bpp_file_path, FS_READ_WRITE);
            if (file_handle < 0)
            {
                ret = EMAIL_BPP_ERROR;
                goto MMI_EMAIL_APP_COMPOSE_CONTENT_END;
            }
            while ((FS_NO_ERROR == (fs_error = FS_Read(file_handle, start_ptr, MMI_EMAIL_BPP_ENCODE_CONT_LEN * sizeof(WCHAR), &read_size))) &&
                   (read_size > 0))
            {
                start_ptr[(read_size >> 1)] = 0;
                mmi_chset_convert(CHSET_UCS2, CHSET_UTF8, (char*)start_ptr, buff, buf_size);
                bpp_xhtml_element_data(xhtml, buff);
            }
            if (FS_NO_ERROR != fs_error)
            {
                ret = EMAIL_BPP_ERROR;
                goto MMI_EMAIL_APP_COMPOSE_CONTENT_END;
            }
        }
        else
        {
            cont_len += 2;
            srv_op_result = srv_email_msg_get_content(
                                p_bpp_cntx_struct->msg_handle, 
                                MMI_TRUE, 
                                start_ptr, 
                                &cont_len);
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_COMPOSE_CONTENT_LOG3, srv_op_result);

            if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
            {
                ret = EMAIL_BPP_ERROR;
                goto MMI_EMAIL_APP_COMPOSE_CONTENT_END;
            }
            start_ptr[cont_len] = 0;
            mmi_chset_convert(CHSET_UCS2, CHSET_UTF8, (char*)start_ptr, buff, buf_size);
            bpp_xhtml_element_data(xhtml, buff);
        }

        bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);
        bpp_xhtml_element_end(xhtml, XHTML_ELE_DIV);
    }
#ifdef __MMI_EMAIL_HTML__
    else
    {
        bpp_xhtml_element_begin(xhtml, XHTML_ELE_DIV, NULL, 0);
        bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, NULL, 0);

        p_html_data = mmi_email_get_read_cont_buff_ptr((S32*)&html_cont_len);
        html_cont_len++;

        if (html_cont_len > MMI_EMAIL_BPP_ENCODE_CONT_LEN)
        {
            start_ptr = OslMalloc(MMI_EMAIL_BPP_COMPOSE_BUF_SIZE / sizeof(WCHAR));
            while (html_cont_len > 0)
            {
                memcpy(start_ptr, p_html_data + read_size, MMI_EMAIL_BPP_ENCODE_CONT_LEN * sizeof(WCHAR));
                html_cont_len -= MMI_EMAIL_BPP_ENCODE_CONT_LEN;
                read_size += MMI_EMAIL_BPP_ENCODE_CONT_LEN;
                start_ptr[MMI_EMAIL_BPP_ENCODE_CONT_LEN] = 0;
                mmi_chset_convert(CHSET_UCS2, CHSET_UTF8, (char*)start_ptr, buff, buf_size);
                bpp_xhtml_element_data(xhtml, buff);
            }
        }
        else
        {
            mmi_chset_convert(CHSET_UCS2, CHSET_UTF8, (char*)p_html_data, buff, buf_size);
            bpp_xhtml_element_data(xhtml, buff);
        }
        bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);
        bpp_xhtml_element_end(xhtml, XHTML_ELE_DIV);
    }
#endif /* __MMI_EMAIL_HTML__ */

MMI_EMAIL_APP_COMPOSE_CONTENT_END:
    if (NULL != start_ptr)
    {
        OslMfree(start_ptr);
        start_ptr = NULL;
    }
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
    }
    if (NULL != bpp_file_path)
    {
        FS_Delete(bpp_file_path);
        OslMfree(bpp_file_path);
        bpp_file_path = NULL;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_COMPOSE_CONTENT_LOG4, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_bpp_compose_attachment
 * DESCRIPTION
 *  The function composes the mail's header.
 * PARAMETERS
 *  fh              [IN]        The file handle
 *  pbuf            [OUT]       Used to store the attachment information
 *  buf_remain      [IN]        The remained buffer size
 * RETURNS
 *  Success: >= 0
 *  Failure: < 0
 *****************************************************************************/
static S32 mmi_email_bpp_compose_attachment(void *xhtml, mmi_email_bpp_cntx_struct *p_bpp_cntx_struct, CHAR *buff, U32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_attach = p_bpp_cntx_struct->msg_basic_info.attach_num;
    U8 i = 0;
    S32 offset = 0;
    CHAR *buf_ptr = NULL;
    U32 len = 0;
    U32 end_pos = 0;
    srv_email_attach_struct *p_attach_info = NULL;
    S32 number = 1;
    email_bpp_ret_code_enum return_value = EMAIL_BPP_SUCCESS;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_COMPOSE_ATTACHMENT_LOG1, total_attach);
    if (total_attach == 0)
    {
        goto MMI_EMAIl_BPP_COMPOSE_ATTACHMENT_END;
    }
    
    p_attach_info = OslMalloc(sizeof(srv_email_attach_struct));
    
    bpp_xhtml_element_begin(xhtml, XHTML_ELE_DIV, NULL, 0);
    bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, NULL, 0);

    for (i = 0; i < total_attach; i++)
    {
        /* Write the attachment field */
        buf_ptr = GetString(STR_EMAIL_SERIAL_ATTACHMENT_ID);

        len = mmi_chset_convert_ex(CHSET_UCS2, CHSET_UTF8, buf_ptr, buff, buf_size, &end_pos);
        if (*((WCHAR*)end_pos) != L'\0')
        {
            return_value = EMAIL_BPP_ERROR;
            goto MMI_EMAIl_BPP_COMPOSE_ATTACHMENT_END;
        }
        offset += (len - 1);

        /* Write the left parenthesis */
        buf_ptr = GetString(STR_EMAIL_LEFT_PARENTHESIS_ID);
        len = mmi_chset_convert_ex(CHSET_UCS2, CHSET_UTF8, buf_ptr, &buff[offset], (buf_size - offset), &end_pos);
        if (*((WCHAR*)end_pos) != L'\0')
        {
            return_value = EMAIL_BPP_ERROR;
            goto MMI_EMAIl_BPP_COMPOSE_ATTACHMENT_END;
        }        
        offset += (len - 1);

        /* Write the attachment number */
        offset += sprintf(&buff[offset], "%d", i + 1);

        /* Write the right parenthesis */
        buf_ptr = GetString(STR_EMAIL_RIGHT_PARENTHESIS_ID);
        len = mmi_chset_convert_ex(CHSET_UCS2, CHSET_UTF8, buf_ptr, &buff[offset], (buf_size - offset), &end_pos);
        if (*((WCHAR*)end_pos) != L'\0')
        {
            return_value = EMAIL_BPP_ERROR;
            goto MMI_EMAIl_BPP_COMPOSE_ATTACHMENT_END;
        }        
        offset += (len - 1);

        /* Write the colon */
        buf_ptr = GetString(STR_EMAIL_COLON_ID);
        len = mmi_chset_convert_ex(CHSET_UCS2, CHSET_UTF8, buf_ptr, &buff[offset], (buf_size - offset), &end_pos);
        if (*((WCHAR *)end_pos) != L'\0')
        {
            return_value = EMAIL_BPP_ERROR;
            goto MMI_EMAIl_BPP_COMPOSE_ATTACHMENT_END;
        }        
        offset += (len - 1);

        buff[offset++] = ' ';
        buff[offset] = '\0';

        /* Write the attachment's filename */
        srv_op_result = srv_email_msg_get_attachment_info(
                            p_bpp_cntx_struct->msg_handle, 
                            i, 
                            &number, 
                            p_attach_info);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_BPP_COMPOSE_ATTACHMENT_LOG2, i, number, srv_op_result);
        if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
        {
            return_value = EMAIL_BPP_ERROR;
            goto MMI_EMAIl_BPP_COMPOSE_ATTACHMENT_END;
        }
        len = mmi_chset_convert_ex(
                CHSET_UCS2, 
                CHSET_UTF8, 
                (char*)p_attach_info->name, 
                &buff[offset], 
                buf_size,
                &end_pos);
        if (*((WCHAR *)end_pos) != L'\0')
        {
            return_value = EMAIL_BPP_ERROR;
            goto MMI_EMAIl_BPP_COMPOSE_ATTACHMENT_END;
        }        
        offset += (len - 1);

        /* Write the new line */
        buff[offset++] = '\n';
        buff[offset] = '\0';

        if (total_attach > 1 && i < total_attach - 1)
        {
            /* Write the new line */
            buff[offset++] = '\n';
            buff[offset] = '\0';
        }
        bpp_xhtml_element_data(xhtml, buff);

        buf_size = MMI_EMAIL_BPP_COMPOSE_BUF_SIZE;
        offset = 0;
    }

    bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);
    bpp_xhtml_element_end(xhtml, XHTML_ELE_DIV);

MMI_EMAIl_BPP_COMPOSE_ATTACHMENT_END:
    if (NULL != p_attach_info)
    {
        OslMfree(p_attach_info);
        p_attach_info = NULL;
    }
    return return_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_compose_xhtml_file
 * DESCRIPTION
 *  The callback function for Email BPP.
 * PARAMETERS
 *
 * RETURNS
 *  The file size of error code
 *****************************************************************************/
static S32 mmi_email_compose_xhtml_file(U32 bpp_inst, WCHAR *file, mmi_email_bpp_cntx_struct *p_bpp_cntx_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *xhtml;
    CHAR *version = NULL, *buff = NULL;
    U32 buf_size;
	CHAR *temp_ptr = "head";
    S32 ret = EMAIL_BPP_SUCCESS;
    xhtml_output_struct x_out;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    version = cui_bt_printing_xhtml_version(bpp_inst);
    if (!version)
        return EMAIL_BPP_ERROR;

    x_out.type = XHTML_OUT_FILE;
    x_out.u.file = file;
    
    xhtml = bpp_xhtml_open(version, &x_out);
    if (!xhtml)
        return EMAIL_BPP_ERROR;

    bpp_xhtml_element_begin(xhtml, temp_ptr, NULL, 0);
    bpp_xhtml_empty_element(xhtml, XHTML_ELE_TITLE, NULL, 0);

    bpp_xhtml_style_begin(xhtml, NULL);

    cui_bt_printing_style_rules(bpp_inst, xhtml);

    bpp_xhtml_style_rule(xhtml, &email_title_rule, 1);
    bpp_xhtml_style_rule(xhtml, &email_value_rule, 1);
    
    bpp_xhtml_style_end(xhtml);

    bpp_xhtml_element_end(xhtml, XHTML_ELE_HEAD);

    /* Start to write the body here */
    bpp_xhtml_element_begin(xhtml, XHTML_ELE_BODY, NULL, 0);

    buff = OslMalloc(MMI_EMAIL_BPP_COMPOSE_BUF_SIZE);
    buf_size = MMI_EMAIL_BPP_COMPOSE_BUF_SIZE;

    /* Write the mail's header here */
    if ((ret = mmi_email_bpp_compose_header(xhtml, p_bpp_cntx_struct, buff, buf_size)) < 0)
    {
        goto BPP_ERROR_CLEAN;
    }

    /* Write the mail's content here */
    if ((ret = mmi_email_bpp_compose_content(xhtml, p_bpp_cntx_struct, buff, buf_size)) < 0)
    {
        goto BPP_ERROR_CLEAN;
    }

    /* Write the mail's attachments here */
    if ((ret = mmi_email_bpp_compose_attachment(xhtml, p_bpp_cntx_struct, buff, buf_size)) < 0)
    {
        goto BPP_ERROR_CLEAN;
    }

    bpp_xhtml_element_end(xhtml, XHTML_ELE_BODY);

BPP_ERROR_CLEAN:
    {
        U32 size;
        
        if (buff)
            OslMfree(buff);

        size = bpp_xhtml_close(xhtml);
        if (ret >= 0)
            ret = (S32)size;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMPOSE_XHTML_FILE_LOG1, ret);
    return ret;
}

#endif /* __MMI_BPP20_SUPPORT__ */
#endif /* __MMI_EMAIL__ */
