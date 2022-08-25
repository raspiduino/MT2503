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
 *  mtvsmsviewer.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  mtvsmsviewer.c
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
 /************************************
  * Header Files Include
  **************************************************************/
#include "MMI_include.h"
#ifdef __ATV_SMS_SUPPORT__

#include "mtvsmsiprot.h"
#include "Wgui_ems.h"
/**************************************************************
 * Const define
 **************************************************************/
#define MAX_DIGITS               41     /* Maximum number of digits in phone number */
#ifndef MAX_DIGITS_SMS
#define MAX_DIGITS_SMS           21     /* Maximum number of digits in sms source/destination */
#endif
#define MAX_TIMESTAMP_SIZE    12
#define MMI_MTV_SMS_MAX_VIEWER_HEADER_LEN       120
typedef enum
{
    SMS_ADDR_TYPE_NUMBER,
    SMS_ADDR_TYPE_EMAIL_ADDR,
    SMS_ADDR_TYPE_TOTAL
}mmi_sms_address_type_enum;
typedef MYTIME      UI_time;



static S8 *viewer_number_buff = NULL;
static S8 *viewer_time_buff = NULL;

static U8 mmi_mtv_sms_viewer_scrn_del_callback(void);
static U16 mmi_mtv_sms_get_viewer_caption_id(void);
static void mmi_mtv_sms_get_msg_date_time(U16 msg_id, S8 *date_str, S8 *time_str);
static void mmi_mtv_sms_entry_viewer_list_option(void);

static void mmi_mtv_sms_entry_viewer_enable_csk(void);
static void mmi_mtv_sms_entry_viewer_set_csk(void);
static void mmi_mtv_sms_viewer_opt_check_item(void);

static void mmi_mtv_sms_viewer_select_reply(void);
static void mmi_mtv_sms_viewer_select_resend(void);
static void mmi_mtv_sms_viewer_select_send(void);
static void mmi_mtv_sms_viewer_select_forward(void);
static void mmi_mtv_sms_viewer_select_edit(void);
static void mmi_mtv_sms_entry_view_msg_ems_cut_confirm(void);
static void mmi_mtv_sms_entry_viewer(void);
static void mmi_mtv_sms_viewer_send_call_back(mtv_sms_result_enum result);
static void mmi_mtv_sms_viewer_select_delete(void);
static  void mmi_mtv_sms_viewer_pre_delete(void);
static void mmi_mtv_sms_viewer_delete_handle(srv_sms_callback_struct *callback_data);
static void mmi_mtv_sms_viewer_delete(void);
static U8 * mmi_mtv_sms_get_viewer_header_number(void);
static U8 * mmi_mtv_sms_get_viewer_header_time(void);
static void mmi_mtv_sms_view_read_msg_callback(mmi_mtv_sms_result_enum result, void *data);
static void mmi_mtv_sms_entry_view_msg_ems_cut_confirm_lsk_func(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_opt_pre_view
 * DESCRIPTION
 *  Pre entry list option view msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_list_opt_pre_view(void)
{
    if (srv_sms_get_msg_status(g_mtv_sms_cntx.curr_msg_id) & SRV_SMS_STATUS_UNREAD)
    {
        mmi_mtv_sms_read_msg(
             g_mtv_sms_cntx.curr_msg_id,
             MMI_TRUE,
             mmi_mtv_sms_view_read_msg_callback);

    }
    else
    {
        mmi_mtv_sms_read_msg(
             g_mtv_sms_cntx.curr_msg_id,
             MMI_FALSE,
             mmi_mtv_sms_view_read_msg_callback);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_view_read_msg_callback
 * DESCRIPTION
 *  Read current highlight msg callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_view_read_msg_callback(mmi_mtv_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MTV_SMS_RESULT_OK)
    {
        mmi_mtv_sms_msg_status_enum msg_status = *(mmi_mtv_sms_msg_status_enum*)data;

        g_mtv_sms_cntx.curr_msg_status = msg_status;

        if (SCR_ID_MTV_SMS_POPUP_READING == GetActiveScreenId())
        {
            mmi_mtv_sms_entry_view_msg_ems_cut_confirm();
            mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_POPUP_READING);
        }
        else if (IsScreenPresent(SCR_ID_MTV_SMS_POPUP_READING))
        {
            
            EMSData *pEMS = MtvGetEMSDataForView(NULL, 0);
            MMI_ASSERT(pEMS != NULL);
            if (pEMS->listHead != NULL) 
            {
                mmi_mtv_sms_set_confirm_generic( 
                    SCR_ID_MTV_SMS_CONFIRM_DELETE,
                    STR_ID_MTV_SMS_REMOVE_OBJECT_CONFIRM,
                    mmi_mtv_sms_entry_viewer,
                    mmi_mtv_sms_scrn_back);
                HistoryReplace(SCR_ID_MTV_SMS_POPUP_READING, SCR_ID_MTV_SMS_CONFIRM_DELETE, mmi_mtv_sms_entry_confirm);
            }
            else
            {
                HistoryReplace(SCR_ID_MTV_SMS_POPUP_READING, SCR_ID_MTV_SMS_VIEWER, mmi_mtv_sms_entry_viewer);
            }
        }
    }
    else
    {
        mmi_mtv_sms_display_popup((STR_ID_MTV_SMS_READ_FAILED), MMI_MTV_SMS_NOTIFY_FAILURE);
        mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_POPUP_READING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_write_msg_ems_cut_confirm
 * DESCRIPTION
 *  confirm to cut viewer object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_view_msg_ems_cut_confirm(void)
{
    mmi_mtv_sms_send_case_enum send_case = mmi_mtv_sms_get_send_msg_case();
    EMSData *pEMS = MtvGetEMSDataForView(NULL, 0);
    MMI_ASSERT(pEMS != NULL);
    if (pEMS->listHead != NULL) 
    {
        mmi_mtv_sms_entry_confirm_generic(
            SCR_ID_MTV_SMS_CONFIRM_DELETE,
            STR_ID_MTV_SMS_REMOVE_OBJECT_CONFIRM,
            mmi_mtv_sms_entry_view_msg_ems_cut_confirm_lsk_func,
            mmi_mtv_sms_scrn_back);
    }
    else
    {
        mmi_mtv_sms_entry_viewer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_view_msg_ems_cut_confirm_lsk_func
 * DESCRIPTION
 *  pre-entry write new sms 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_view_msg_ems_cut_confirm_lsk_func(void)
{
    mmi_mtv_sms_entry_viewer();
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_CONFIRM_DELETE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_remove_edit_all_ems_objects
 * DESCRIPTION
 *  Pre entry list option view msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_remove_view_all_ems_objects(EMSData** ppEMS)
{
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
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
 *  mmi_mtv_sms_entry_viewer
 * DESCRIPTION
 *  Entry the SMS Viewer Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U8 *header_buff_number;
    U8 *header_buff_time;
    U16 title_str_id;
    EMSData *ems_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTV_SMS_VIEWER, mmi_mtv_sms_common_screen_exit, mmi_mtv_sms_entry_viewer, NULL);

    wgui_cat_matv_init_video_info(
                    (U8 *)video_layer_buffer_ptr, 
                    MATV_VIDEO_LAYER_BUF_SIZE, 
                    (U8 *)util_layer_buffer_ptr, 
                    MATV_UTIL_LAYER_BUF_SIZE, 
                    mmi_mtv_sms_video_player_callback, 
                    mmi_mtv_sms_video_player_stop_callback);
    
    g_mtv_sms_scrn_cntx.current_scrn = SCR_ID_MTV_SMS_VIEWER;
    mmi_mtv_sms_remove_view_all_ems_objects(&g_mtv_sms_cntx.view_ems_data);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_MTV_SMS_VIEWER);

    title_str_id = mmi_mtv_sms_get_viewer_caption_id();

    //Make sure this screen can't be re-entry
    header_buff_number = mmi_mtv_sms_get_viewer_header_number();
    header_buff_time = mmi_mtv_sms_get_viewer_header_time();

    SetDelScrnIDCallbackHandler(
        SCR_ID_MTV_SMS_VIEWER,
        (HistoryDelCBPtr)mmi_mtv_sms_viewer_scrn_del_callback);

    mmi_mtv_sms_entry_viewer_enable_csk();
    if (g_mtv_sms_cntx.curr_msg_status != MMI_MTV_SMS_STATUS_UNSUPPORT)
    {
        MtvGetEMSDataForView(&ems_data, 0);
    }
    else
    {
        MtvGetEMSDataForView(&ems_data, 1);
        AddString(ems_data, 
            (U8*)get_string(STR_GLOBAL_NOT_SUPPORTED),
            mmi_ucs2strlen((const CHAR*)get_string(STR_GLOBAL_NOT_SUPPORTED)),
            NULL);
    }
    MMI_ASSERT(ems_data);
    wgui_cat9008_show(
        get_string(title_str_id),
        get_image(0),
        get_string(STR_GLOBAL_OPTIONS),
        get_image(0),
        get_string(STR_GLOBAL_BACK),
        get_image(0),
        ems_data,
        (UI_string_type)header_buff_number,
        (UI_string_type)header_buff_time,
        gui_buffer);
    SetLeftSoftkeyFunction(mmi_mtv_sms_entry_viewer_list_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_mtv_sms_scrn_back, KEY_EVENT_UP);
    mmi_mtv_sms_scrn_close(STR_ID_MTV_SMS_REMOVE_OBJECT_CONFIRM);
    mmi_mtv_sms_entry_viewer_set_csk();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_scrn_del_callback
 * DESCRIPTION
 *  release viewer reource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_mtv_sms_viewer_scrn_del_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (viewer_number_buff != NULL)
    {
        OslMfree(viewer_number_buff);
        viewer_number_buff = NULL;
    }

    if (viewer_time_buff != NULL)
    {
        OslMfree(viewer_time_buff);
        viewer_time_buff = NULL;
    }
    MTVReleaseEMSViewBuffer();
    ClearDelScrnIDCallbackHandler(SCR_ID_MTV_SMS_VIEWER, NULL);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_viewer_enable_csk
 * DESCRIPTION
 *  Enable the SMS Viewer Screen CSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_entry_viewer_enable_csk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_mtv_sms_cntx.curr_msg_status)
    {
        case MMI_MTV_SMS_STATUS_UNREAD:
        case MMI_MTV_SMS_STATUS_INBOX:
            if (mmi_mtv_sms_check_is_valid_oa_addr(g_mtv_sms_cntx.curr_msg_id) == MMI_TRUE)
            {
                EnableCenterSoftkey(0, IMG_GLOBAL_REPLY_MSG_CSK);
            }
            else
            {
                EnableCenterSoftkey(0, IMG_GLOBAL_FORWARD_MSG_CSK);
            }
            break;

        case MMI_MTV_SMS_STATUS_SENT:
            EnableCenterSoftkey(0, IMG_GLOBAL_FORWARD_MSG_CSK);
            break;

        case MMI_MTV_SMS_STATUS_UNSENT:
        case MMI_MTV_SMS_STATUS_DRAFTS:
        {
            if (mmi_mtv_sms_is_send_enable() == MMI_TRUE)
            {
                EnableCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);
            }
            else
            {
                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            }
            break;
        }

        case MMI_MTV_SMS_STATUS_UNSUPPORT:
            if (g_mtv_sms_cntx.curr_box_type == SRV_SMS_BOX_INBOX)
            {
                if (mmi_mtv_sms_check_is_valid_oa_addr(g_mtv_sms_cntx.curr_msg_id) == MMI_TRUE)
                {
                    EnableCenterSoftkey(0, IMG_GLOBAL_REPLY_MSG_CSK);
                    break;
                }
            }
        case MMI_MTV_SMS_STATUS_DELIVERY_REPORT:
        case MMI_MTV_SMS_STATUS_PENDING_REPORT:
        default:
            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_viewer_set_csk
 * DESCRIPTION
 *  Set the SMS Viewer Screen CSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_entry_viewer_set_csk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        switch(g_mtv_sms_cntx.curr_msg_status)
        {
            case MMI_MTV_SMS_STATUS_UNREAD:
            case MMI_MTV_SMS_STATUS_INBOX:
                if (mmi_mtv_sms_check_is_valid_oa_addr(g_mtv_sms_cntx.curr_msg_id) == MMI_TRUE)
                {
                    SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_reply, KEY_EVENT_UP);
                }
                else
                {
                    SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_forward, KEY_EVENT_UP);
                }
                break;

            case MMI_MTV_SMS_STATUS_SENT:
                SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_forward, KEY_EVENT_UP);
                break;

    #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
            case MMI_MTV_SMS_STATUS_UNSENT:
                if (mmi_mtv_sms_is_send_enable() == MMI_TRUE)
                {
                    SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_resend, KEY_EVENT_UP);
                }
                else
                {
                    SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_edit, KEY_EVENT_UP);
                }
                break;

    #else /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */
            case MMI_MTV_SMS_STATUS_UNSENT:
    #endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */
            case MMI_MTV_SMS_STATUS_DRAFTS:
            {
                if (mmi_mtv_sms_is_send_enable() == MMI_TRUE)
                {
                    SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_send, KEY_EVENT_UP);
                }
                else
                {
                    SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_edit, KEY_EVENT_UP);
                }
                break;
            }

            case MMI_MTV_SMS_STATUS_UNSUPPORT:
            {
                if (g_mtv_sms_cntx.curr_box_type == SRV_SMS_BOX_INBOX)
                {
                    if (mmi_mtv_sms_check_is_valid_oa_addr(g_mtv_sms_cntx.curr_msg_id) == MMI_TRUE)
                    {
                        SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_reply, KEY_EVENT_UP);
                    }
                    else
                    {
                        SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_delete, KEY_EVENT_UP);
                    }
                }
                else
                {
                    SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_delete, KEY_EVENT_UP);
                }
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_check_is_valid_or_addr
 * DESCRIPTION
 *  Check if inbox OA address valid
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_mtv_sms_check_is_valid_oa_addr(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ucs2_addr;
    S8 ucs2_num[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    srv_sms_get_msg_address(msg_id, ucs2_num);

    ucs2_addr = ucs2_num;

    if (((ucs2_addr[0] == '\0') && (ucs2_addr[1] == '\0')) ||
        (srv_sms_check_ucs2_number(ucs2_addr) == MMI_FALSE))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_get_viewer_caption_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_mtv_sms_get_viewer_caption_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 capiton_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    capiton_str_id = STR_ID_MTV_SMS_VIEW_TITLE;

    return capiton_str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_get_viewer_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*    header buffer
 *****************************************************************************/
static U8* mmi_mtv_sms_get_viewer_header_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 name[(MMI_PHB_NAME_LENGTH + 1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (viewer_number_buff != NULL)
    {
        OslMfree(viewer_number_buff);
        viewer_number_buff = NULL;
    }
    viewer_number_buff = OslMalloc((MMI_MTV_SMS_MAX_VIEWER_HEADER_LEN + 1) * ENCODING_LENGTH);
    /*if (g_mtv_sms_cntx.curr_msg_status == MMI_MTV_SMS_STATUS_UNSUPPORT)
    {
        mmi_ucs2cpy(viewer_number_buff, GetString(STR_GLOBAL_NOT_SUPPORTED));
    }
    else*/
    {
        U16 header_str_id = 0;

        switch (g_mtv_sms_cntx.curr_msg_status)
        {
            case MMI_MTV_SMS_STATUS_SENT:
            case MMI_MTV_SMS_STATUS_UNSENT:
            case MMI_MTV_SMS_STATUS_DRAFTS:
                header_str_id = STR_ID_MTV_SMS_VIEW_TO;
                break;

            case MMI_MTV_SMS_STATUS_UNREAD:
            case MMI_MTV_SMS_STATUS_INBOX:
            case MMI_MTV_SMS_STATUS_DELIVERY_REPORT:
            case MMI_MTV_SMS_STATUS_PENDING_REPORT:
            case MMI_MTV_SMS_STATUS_UNSUPPORT:
                header_str_id = STR_ID_MTV_SMS_VIEW_FROM;
                break;
        }

        if (header_str_id != 0)
        {
            mmi_ucs2cpy(viewer_number_buff, GetString(header_str_id));
        }
        else
        {
            viewer_number_buff[0] = '\0';
            viewer_number_buff[1] = '\0';
        }
        if (mmi_mtv_sms_get_address(g_mtv_sms_cntx.curr_msg_id, name, MMI_PHB_NAME_LENGTH))
        {
            mmi_ucs2cat(viewer_number_buff, name);
        }
    }
    return (U8*)viewer_number_buff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_date_time
 * DESCRIPTION
 *  Get message date time
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 * mmi_mtv_sms_get_viewer_header_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ts_date[(MAX_TIMESTAMP_SIZE + 1) * ENCODING_LENGTH];
    S8 ts_time[(MAX_TIMESTAMP_SIZE + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (viewer_time_buff != NULL)
    {
        OslMfree(viewer_time_buff);
        viewer_time_buff = NULL;
    }
    viewer_time_buff = OslMalloc((MMI_MTV_SMS_MAX_VIEWER_HEADER_LEN + 1) * ENCODING_LENGTH);
    memset(viewer_time_buff, 0x00, ((MMI_MTV_SMS_MAX_VIEWER_HEADER_LEN + 1) * ENCODING_LENGTH));
//Only the inbox msg need to show the Data and Time
    if ((g_mtv_sms_cntx.curr_msg_status == MMI_MTV_SMS_STATUS_UNREAD) ||
        (g_mtv_sms_cntx.curr_msg_status == MMI_MTV_SMS_STATUS_INBOX) ||
        (g_mtv_sms_cntx.curr_msg_status == MMI_MTV_SMS_STATUS_DELIVERY_REPORT) ||
        (g_mtv_sms_cntx.curr_msg_status == MMI_MTV_SMS_STATUS_PENDING_REPORT))
    {
        mmi_mtv_sms_get_msg_date_time(
            g_mtv_sms_cntx.curr_msg_id,
            ts_date,
            ts_time);
        mmi_ucs2cat(viewer_time_buff, ts_date);
        mmi_ucs2cat(viewer_time_buff, (S8*)L" ");
        mmi_ucs2cat(viewer_time_buff, ts_time);
        mmi_ucs2cat(viewer_time_buff, (S8*)L" ");
     }
    return (U8 *)viewer_time_buff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_date_time
 * DESCRIPTION
 *  Get message date time
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_get_msg_date_time(U16 msg_id, S8 *date_str, S8 *time_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_time datetime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_get_msg_timestamp(msg_id, (MYTIME*)&datetime);

    if (date_str != NULL)
    {
        date_string(&datetime, (UI_string_type)date_str, DT_IDLE_SCREEN);
    }

    if (time_str != NULL)
    {
        time_string(&datetime, (UI_string_type)time_str, DT_IDLE_SCREEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_msgbox_list_option
 * DESCRIPTION
 *  Entry inbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_entry_viewer_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mtv_sms_viewer_opt_check_item(); 
    mmi_mtv_sms_entry_common_options(SCR_ID_MTV_SMS_VIEWER_OPTIONS, MENU_ID_MTV_SMS_VIEW_ROOT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_opt_check_item
 * DESCRIPTION
 *  check items of viewer option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_viewer_opt_check_item(void)
{
    switch (g_mtv_sms_cntx.curr_msg_status)
    {
        case MMI_MTV_SMS_STATUS_SENT:
            mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_VIEW_FORWARD);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_REPLY);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_RESEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_SEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_EDIT);
            break;
            
        case MMI_MTV_SMS_STATUS_UNSENT:
            mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_VIEW_RESEND);
            mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_VIEW_EDIT);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_REPLY);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_FORWARD);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_SEND);
            if (!srv_sms_is_sms_valid())
            {
                mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_RESEND);
            }
            
            break;
            
        case MMI_MTV_SMS_STATUS_DRAFTS:
            mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_VIEW_EDIT);
            mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_VIEW_SEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_REPLY);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_RESEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_FORWARD);
            
            if (!srv_sms_is_sms_valid())
            {
                mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_SEND);
            }
            break;

        case MMI_MTV_SMS_STATUS_UNREAD:
        case MMI_MTV_SMS_STATUS_INBOX:
            if (mmi_mtv_sms_check_is_valid_oa_addr(g_mtv_sms_cntx.curr_msg_id) == MMI_TRUE)
            {
                mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_VIEW_REPLY);
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_REPLY);
            }
            mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_VIEW_FORWARD);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_RESEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_SEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_EDIT);
            break;
            
        case MMI_MTV_SMS_STATUS_UNSUPPORT:
            if (g_mtv_sms_cntx.curr_box_type == SRV_SMS_BOX_INBOX)
            {
                if (mmi_mtv_sms_check_is_valid_oa_addr(g_mtv_sms_cntx.curr_msg_id))
                {
                    mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_VIEW_REPLY);
                }
                else
                {
                    mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_REPLY);
                }
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_REPLY);
            }
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_FORWARD);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_RESEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_SEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_VIEW_EDIT);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_edit_hilite
 * DESCRIPTION
 *  hilite edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_viewer_edit_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_viewer_select_edit, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_edit, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_select_edit
 * DESCRIPTION
 *  Pre entry list option item: edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_viewer_select_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    if (g_mtv_sms_cntx.curr_msg_status == MMI_MTV_SMS_STATUS_DRAFTS)
    {
        mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_EDIT_DRAFT);
        mmi_mtv_sms_entry_write_msg_ems_cut_confirm();
    }
    else
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */
    {
       mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_EDIT_UNSENT);
       mmi_mtv_sms_entry_write_msg_ems_cut_confirm();
    }
    mmi_mtv_sms_send_register_call_back(mmi_mtv_sms_viewer_send_call_back);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_reply_hilite
 * DESCRIPTION
 *  hilite reply
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_viewer_reply_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_viewer_select_reply, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_reply, KEY_EVENT_UP);
}

/*****************************************************************************
* FUNCTION
*  mmi_mtv_sms_viewer_select_reply
* DESCRIPTION
*  Entry reply
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_mtv_sms_viewer_select_reply(void)
{
    mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_REPLY);
    mmi_mtv_sms_start_send_msg_get_sendcase();
    mmi_mtv_sms_send_register_call_back(mmi_mtv_sms_viewer_send_call_back);
}

 /*****************************************************************************
  * FUNCTION
  * mmi_mtv_sms_editor_send_call_back(); 
  * DESCRIPTION
  *  pre-entry write new sms 
  * PARAMETERS
  *  result     [IN]:   send result
  * RETURNS
  *  void
  *****************************************************************************/
 static void mmi_mtv_sms_viewer_send_call_back(mtv_sms_result_enum result)
 {
     mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_EDITOR);
     if (GetActiveScreenId() == SCR_ID_MTV_SMS_VIEWER)
     {
        mmi_mtv_sms_scrn_back();
     }
     else
     {
        mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_VIEWER);
     }
     MTVReleaseEMSEditBuffer();
 }


 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_sms_viewer_resend_hilite
  * DESCRIPTION
  *  hilite resend
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
void mmi_mtv_sms_viewer_resend_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_viewer_select_resend, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_resend, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_select_resend
 * DESCRIPTION
 *  resend from viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_viewer_select_resend(void)
{
    mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_RESEND);
    mmi_mtv_sms_start_send_msg_get_sendcase();
    mmi_mtv_sms_send_register_call_back(mmi_mtv_sms_viewer_send_call_back);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_forward_hilite
 * DESCRIPTION
 *  hilite forward
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_viewer_forward_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_viewer_select_forward, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_forward, KEY_EVENT_UP);
}
  
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_select_forward
 * DESCRIPTION
 *  forward from viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_viewer_select_forward(void)
{
    mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_FORWARD);
    mmi_mtv_sms_entry_write_msg_ems_cut_confirm();
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_VIEWER);
    mmi_mtv_sms_send_register_call_back(mmi_mtv_sms_viewer_send_call_back);
}

   
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_send_hilite
 * DESCRIPTION
 *  hilite send from viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_viewer_send_hilite(void)
{
 SetLeftSoftkeyFunction(mmi_mtv_sms_viewer_select_send, KEY_EVENT_UP);
 SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_send, KEY_EVENT_UP);
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_select_send
 * DESCRIPTION
 *  send from viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_viewer_select_send(void)
{
    mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_SEND_DRAFT);
    mmi_mtv_sms_start_send_msg_get_sendcase();
    mmi_mtv_sms_send_register_call_back(mmi_mtv_sms_viewer_send_call_back);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_delete_hilite
 * DESCRIPTION
 *  hilte delete in viewer option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_viewer_delete_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_viewer_select_delete, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_viewer_select_delete, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_select_delete
 * DESCRIPTION
 *  Entry select to delete confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_sms_viewer_select_delete(void)
 {
     mmi_mtv_sms_viewer_pre_delete();
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_pre_delete
 * DESCRIPTION
 *  Entry select to delete confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_sms_viewer_pre_delete(void)
 {
    mmi_mtv_sms_set_confirm_generic(SCR_ID_MTV_SMS_CONFIRM_DELETE_VIEWER, STR_ID_MTV_SMS_IS_DELETE, mmi_mtv_sms_viewer_delete, mmi_mtv_sms_scrn_back);
    mmi_mtv_sms_entry_confirm_no_csk();
 }

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_viewer_delete
 * DESCRIPTION
 *  Entry select to delete screen and delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_viewer_delete(void)
{
   mmi_mtv_sms_pre_entry_processing_screen(
       SCR_ID_MTV_SMS_POPUP_DELETE_PROCESSING, 
       0, 
       0, 
       NULL, 
       0, 
       NULL, 
       STR_GLOBAL_DELETING);
   srv_sms_delete_msg(g_mtv_sms_cntx.curr_msg_id, mmi_mtv_sms_viewer_delete_handle, NULL);
   mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_CONFIRM_DELETE);
}

 
 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_sms_viewer_delete_handle
  * DESCRIPTION
  *  handle delete processing delete result
  * PARAMETERS
  *  callback_data        [IN]    result Data
  * RETURNS
  *  void
  *****************************************************************************/
static void mmi_mtv_sms_viewer_delete_handle(srv_sms_callback_struct *callback_data)
{
    MMI_BOOL result = callback_data->result;
    if (GetActiveScreenId() == SCR_ID_MTV_SMS_POPUP_DELETE_PROCESSING)
    {
        if (result)
        {
           mmi_mtv_sms_display_popup((STR_GLOBAL_DELETED), MMI_MTV_SMS_NOTIFY_OK);
           g_mtv_sms_cntx.curr_msg_id = SRV_SMS_INVALID_MSG_ID;
        }
        else
        {
           mmi_mtv_sms_display_popup((STR_ID_MTV_SMS_DELETE_FAILED), MMI_MTV_SMS_NOTIFY_FAILURE);
        }
    }
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_POPUP_DELETE_PROCESSING);
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_VIEWER);
}
 
     
#endif /*__MMI_ATV_SMS_SUPPORT__*/
