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
 *  mtvsmslist.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  mtvsmslist.c
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
#include "mmi_rp_app_sms_def.h"
#include "mmi_rp_app_mtv_sms_def.h"

/**************************************************************
 * Const define
 **************************************************************/



typedef enum
{
    SMS_STORAGE_ME = 0,
    SMS_STORAGE_SIM,
    SMS_STORAGE_TOTAL
}mmi_mtv_sms_storage_type_enum;


typedef enum
{
    SMS_BOX_TYPE_NOBOX,
    SMS_BOX_TYPE_INBOX,
    SMS_BOX_TYPE_OUTBOX,
    SMS_BOX_TYPE_DRAFTS,
    SMS_BOX_TYPE_UNSENT,
    SMS_BOX_TYPE_ARCHIVE,    
    SMS_BOX_TYPE_TOTAL
}mmi_mtv_sms_box_type_enum;



typedef enum
{
    STATUS_ICON_READ = 0,
    STATUS_ICON_UNREAD,
    STATUS_ICON_SENT,
    STATUS_ICON_UNSENT,
    STATUS_ICON_SS_NCOMP,
    STATUS_ICON_TOTAL
}mmi_mtv_sms_status_icon_enum;



typedef enum
{
    /* SIM Card 1 */
    SMS_SIM_1 = 0,
    /* SIM Card 2 */
    SMS_SIM_2,
    /* Total SIM Card Number */
    SMS_SIM_TOTAL,
    /* Unspecific SIM Card */
    SMS_SIM_UNSPECIFIC
}mmi_mtv_sms_icon_sim_enum;



/**************************************************************
 * struct define
 **************************************************************/


/**************************************************************
 * Global Variables Declaration
 **************************************************************/


/**************************************************************
 * Global Function Declaration
 **************************************************************/

/**************************************************************
 * Static Variables Defination
 **************************************************************/


/**************************************************************
 * Static Function Declaration
 **************************************************************/

static void mmi_mtv_sms_msgbox_list_highlight_hdlr(S32 nIndex);
static S32 mmi_mtv_sms_get_curr_msgbox_highlihgt_index(U16 total_num);
static void mmi_mtv_sms_entry_msgbox_list(void);
static pBOOL mmi_mtv_sms_msgbox_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static  U16 mmi_mtv_sms_get_msgbox_string(srv_sms_box_enum msg_box_type);
static  U16 mmi_mtv_sms_get_icon(U16 msg_id);
static  void mmi_mtv_sms_msgbox_list_option_enable_csk(void);
static void mmi_mtv_sms_list_option_read_msg_callback(mmi_mtv_sms_result_enum result, void *data);
static void mmi_mtv_sms_entry_msgbox_list_option(void);

static void mmi_mtv_sms_list_opt_check_item(void);
static void mmi_mtv_sms_select_view(void);
static void mmi_mtv_sms_select_reply(void);
static void mmi_mtv_sms_select_resend(void);
static void mmi_mtv_sms_select_send(void);
static void mmi_mtv_sms_select_forward(void);
static void mmi_mtv_sms_select_delete(void);
static void mmi_mtv_sms_select_delete_all(void);
static void mmi_mtv_sms_list_delete_handle(srv_sms_callback_struct *callback_data);
static void mmi_mtv_sms_list_pre_delete(void);
static void mmi_mtv_sms_list_delete(void);
static void mmi_mtv_sms_list_delete_all(void);
static void mmi_mtv_sms_list_send_call_back(mtv_sms_result_enum result);
static void mmi_mtv_sms_pre_entry_msgbox_list_option(void);
static S32 mmi_mtv_sms_msgbox_list_get_hint(S32 item_index, UI_string_type *hint_array);
static U16 mtv_mmi_sms_get_msgbox_delete_all_string(srv_sms_box_enum msg_box_type);
static void mmi_mtv_sms_select_edit(void);
static U8 mmi_mtv_sms_list_scrn_del_callback(void* dummy);


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_pre_entry_msgbox_list
 * DESCRIPTION
 *  Before entry msgbox list, check whether can enter the msgbox list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_pre_entry_msgbox_list(srv_sms_box_enum list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mtv_sms_cntx.curr_box_type = list_type;
    mmi_mtv_sms_entry_msgbox_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_msgbox_list_highlight_hdlr
 * DESCRIPTION
 *  Get current highlight message box index
 * PARAMETERS
 *  nIndex      [IN]        Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_msgbox_list_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_send_status_enum send_status = SRV_SMS_SEND_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mtv_sms_cntx.curr_list_index = nIndex;
    g_mtv_sms_cntx.curr_msg_id = srv_sms_get_msg_id(g_mtv_sms_cntx.curr_box_type, (U16)nIndex);
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    send_status = srv_sms_get_unsent_msg_status(g_mtv_sms_cntx.curr_msg_id);
    if ((g_mtv_sms_cntx.curr_box_type==SRV_SMS_BOX_UNSENT) && 
        (send_status == SRV_SMS_SEND_WAITING) || (send_status == SRV_SMS_SEND_SENDING))
    {
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);
        kal_prompt_trace(MOD_MMI, "List hilight msg_id = %d, send status = %d, box = %d, LSK = %d, csk = %d",
                            g_mtv_sms_cntx.curr_msg_id,  
                            g_mtv_sms_cntx.curr_box_type,
                            send_status,
                            0,
                            0);
        
    }
    else 
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    if (g_mtv_sms_cntx.curr_box_type==SRV_SMS_BOX_UNSENT)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        SetCenterSoftkeyFunction(mmi_mtv_sms_pre_entry_msgbox_list_option, KEY_EVENT_UP);
        kal_prompt_trace(MOD_MMI, "List hilight msg_id = %d, send status = %d, box = %d, LSK = %d, csk = %d",
                            g_mtv_sms_cntx.curr_msg_id,  
                            g_mtv_sms_cntx.curr_box_type,
                            send_status,
                            1,
                            1);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_mtv_sms_select_view, KEY_EVENT_UP);
        kal_prompt_trace(MOD_MMI, "List hilight msg_id = %d, send status = %d, box = %d, LSK = %d, csk = %d",
                            g_mtv_sms_cntx.curr_msg_id,  
                            g_mtv_sms_cntx.curr_box_type,
                            send_status,
                            1,
                            1);
    }
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_msgbox_list
 * DESCRIPTION
 *  Entry msgbox list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_msgbox_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;
    S32 numitem = 0;
    srv_sms_box_enum msg_box_type = g_mtv_sms_cntx.curr_box_type;
    U16 title_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numitem = srv_sms_get_list_size(msg_box_type);
    kal_prompt_trace(MOD_MMI, "current number = %d", numitem);

    if (srv_sms_is_sms_ready()== MMI_FALSE)
    {
        mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_LIST);
        mmi_mtv_sms_scrn_back();
        return;
    }
    g_mtv_sms_scrn_cntx.current_scrn = SCR_ID_MTV_SMS_LIST;
    
    EntryNewScreen(SCR_ID_MTV_SMS_LIST, mmi_mtv_sms_common_screen_exit, mmi_mtv_sms_entry_msgbox_list, NULL);

    wgui_cat_matv_init_video_info(
                    (U8 *)video_layer_buffer_ptr, 
                    MATV_VIDEO_LAYER_BUF_SIZE, 
                    (U8 *)util_layer_buffer_ptr, 
                    MATV_UTIL_LAYER_BUF_SIZE, 
                    mmi_mtv_sms_video_player_callback, 
                    mmi_mtv_sms_video_player_stop_callback);

    SetDelScrnIDCallbackHandler(
        SCR_ID_MTV_SMS_LIST,
        (HistoryDelCBPtr)mmi_mtv_sms_list_scrn_del_callback);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MTV_SMS_LIST);

    RegisterHighlightHandler(mmi_mtv_sms_msgbox_list_highlight_hdlr);

    if (guiBuffer != NULL)
    {
        list_menu_category_history *h = (list_menu_category_history*)guiBuffer;

        hiliteitem = mmi_mtv_sms_get_curr_msgbox_highlihgt_index((U16)numitem);

        /* change gui buffer content */
        h->highlighted_item = hiliteitem;
    }

    title_str_id = mmi_mtv_sms_get_msgbox_string(msg_box_type);
    if (numitem != 0)
    {
        mmi_mtv_sms_msgbox_list_option_enable_csk();
    }
    wgui_cat_set_list_menu_empty_lable(get_string(STR_ID_MTV_SMS_EMPTY_LIST));

    wgui_cat1011_show(
        get_string(title_str_id),
        get_image(0),
        get_string((numitem)?STR_GLOBAL_OPTIONS:0),
        get_image(IMG_GLOBAL_OPTIONS),
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        numitem,
        mmi_mtv_sms_msgbox_list_get_item,
        NULL,
        hiliteitem,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_mtv_sms_pre_entry_msgbox_list_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_LIST_ENTRY, msg_box_type, numitem);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_scrn_del_callback
 * DESCRIPTION
 *  release ems buffer for list send processing half
 * PARAMETERS
 * void 
 * RETURNS
 * pBOOL
 *****************************************************************************/
static U8 mmi_mtv_sms_list_scrn_del_callback(void* dummy)
{
    if ((GetActiveScreenId() != SCR_ID_MTV_SMS_EDITOR) && (!IsScreenPresent(SCR_ID_MTV_SMS_EDITOR)))
    {
        MTVReleaseEMSEditBuffer();
    }
    MTVReleaseEMSViewBuffer();
    return MMI_RET_OK; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_msgbox_list_get_hint
 * DESCRIPTION
 *  Get inbox list hint
 * PARAMETERS
 *  item_index          [IN]            Item index
 *  hint_array            [IN]            String buffer
 * RETURNS
 *  S32
 *****************************************************************************/
 S32 mmi_mtv_sms_msgbox_list_get_hint(S32 item_index, UI_string_type *hint_array)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id;
    CHAR* content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_id = srv_sms_get_msg_id(g_mtv_sms_cntx.curr_box_type, (U16)item_index);
    content = (CHAR *)srv_sms_get_msg_content(msg_id);
    mmi_ucs2ncpy((S8*)hint_array[0], (S8*)content, MAX_SUB_MENU_HINT_SIZE);
    return MMI_TRUE;
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_msgbox_list_get_item
 * DESCRIPTION
 *  Get inbox list item
 * PARAMETERS
 *  item_index          [IN]            Item index
 *  str_buff            [IN]            String buffer
 *  img_buff_p          [?]             Image buffer
 *  str_img_mask        [IN]            String image mask    
 * RETURNS
 * pBOOL
 *****************************************************************************/
static pBOOL mmi_mtv_sms_msgbox_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_id = srv_sms_get_msg_id(g_mtv_sms_cntx.curr_box_type, (U16)item_index);

    if (!mmi_mtv_sms_get_address(msg_id, (S8*)str_buff, MAX_SUBMENU_CHARACTERS))
    {
        mmi_ucs2cpy((S8*)str_buff, (S8*)GetString(STR_GLOBAL_NO_NUMBER));
    }
    *img_buff_p = get_image(mmi_mtv_sms_get_icon(msg_id));

    return MMI_TRUE;
}

   
    
   

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_get_icon
 * DESCRIPTION
 *  get sms icon id
 * PARAMETERS
 *  msg_type        [IN]        
 *  msg_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_mtv_sms_get_icon(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon_id = 0;
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_box_enum msg_box_tpye;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        srv_sms_storage_enum storage_type;
        mmi_mtv_sms_storage_type_enum storage_id = SMS_STORAGE_ME;
        mmi_mtv_sms_status_icon_enum status_index;
   #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #else /* __MMI_DUAL_SIM_MASTER__ */
        U16 status_icon[SMS_STORAGE_TOTAL][STATUS_ICON_TOTAL] = 
                {
                    {
                        IMG_MESSAGE_READ,
                        IMG_MESSAGE_UNREAD,
                        IMG_MESSAGE_SENT,
                        IMG_MESSAGE_UNSENT,
                        IMG_MESSAGE_SS_NCOMP

                    },
                    {
                        IMG_MESSAGE_SIM_READ,
                        IMG_MESSAGE_SIM_UNREAD,
                        IMG_MESSAGE_SIM_SENT,
                        IMG_MESSAGE_SIM_UNSENT,
                        IMG_MESSAGE_SIM_SS_NCOMP
                    }
                };
   #endif /* __MMI_DUAL_SIM_MASTER__ */

        storage_type = srv_sms_get_msg_storage_type(msg_id);

        if (storage_type == SRV_SMS_STORAGE_SIM)
        {
            storage_id = SMS_STORAGE_SIM;
        }

   #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif /* __MMI_DUAL_SIM_MASTER__ */

        if (srv_sms_is_msg_complete(msg_id) == MMI_FALSE)
        {
            status_index = STATUS_ICON_SS_NCOMP;
        }
        else
        {
            srv_sms_status_enum msg_status;

            msg_status = srv_sms_get_msg_status(msg_id);

            msg_status &= (~SRV_SMS_STATUS_UNSUPPORTED);

            switch (msg_status)
            {
                case SRV_SMS_STATUS_UNREAD:
                    status_index = STATUS_ICON_UNREAD;
                    break;

                case SRV_SMS_STATUS_READ:
                    status_index = STATUS_ICON_READ;
                    break;

                case SRV_SMS_STATUS_SENT:
                    status_index = STATUS_ICON_SENT;
                    break;

                case SRV_SMS_STATUS_UNSENT:
                case SRV_SMS_STATUS_DRAFT:
                default:
                    status_index = STATUS_ICON_UNSENT;
                    break;
            }
        }

   #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
   #else /* __MMI_DUAL_SIM_MASTER__ */
        icon_id = status_icon[storage_id][status_index];
   #endif /* __MMI_DUAL_SIM_MASTER__ */
    }

    return icon_id;
}
    
    
    
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_get_msgbox_string
 * DESCRIPTION
 *  Get inbox message header
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_mtv_sms_get_msgbox_string(srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            string_id = STR_ID_MTV_SMS_MAIN_INBOX;
            break;

        case SRV_SMS_BOX_OUTBOX:
            string_id = STR_ID_MTV_SMS_MAIN_SENTBOX;
            break;

   #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case SRV_SMS_BOX_DRAFTS:
            string_id = STR_ID_MTV_SMS_MAIN_DRAFTBOX;
            break;
   #endif /* __MMI_MESSAGES_DRAFT_BOX__ */

        case SRV_SMS_BOX_UNSENT:
            string_id = STR_ID_MTV_SMS_MAIN_OUTBOX;
            break;

        default:
            string_id = 0;
            break;
    }

    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_get_msgbox_delete_all_string
 * DESCRIPTION
 *  Get msg box delete all string id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mtv_mmi_sms_get_msgbox_delete_all_string(srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            string_id = STR_ID_MTV_SMS_DELETE_ALL_INOBX;
            break;

        case SRV_SMS_BOX_OUTBOX:
            string_id = STR_ID_MTV_SMS_DELETE_ALL_SENTBOX;
            break;

        case SRV_SMS_BOX_DRAFTS:
            string_id = STR_ID_MTV_SMS_DELETE_ALL_DRAFTS;
            break;


        case SRV_SMS_BOX_UNSENT:
            string_id = STR_ID_MTV_SMS_DELETE_ALL_OUTBOX;
            break;

        default:
            string_id = 0;
            break;
    }
 
    return string_id;
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_msgbox_list_option_enable_csk
 * DESCRIPTION
 *  Enable msgbox list csk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_msgbox_list_option_enable_csk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 csk_id = IMG_GLOBAL_COMMON_CSK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_send_status_enum send_status= srv_sms_get_unsent_msg_status(g_mtv_sms_cntx.curr_msg_id);
    switch (send_status)
    {
        case SRV_SMS_SEND_WAITING:
        case SRV_SMS_SEND_SENDING:
            return;
            break;
    }
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 

    if (g_mtv_sms_cntx.curr_box_type == SRV_SMS_BOX_UNSENT)
    {
        csk_id = IMG_GLOBAL_OPTION_CSK;
    }
    EnableCenterSoftkey(0, csk_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_get_curr_msgbox_highlihgt_index
 * DESCRIPTION
 *  get curr box hilite index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_mtv_sms_get_curr_msgbox_highlihgt_index(U16 total_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_index;
    srv_sms_box_enum msg_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_index = srv_sms_get_msg_list_index(&msg_box_type, g_mtv_sms_cntx.curr_msg_id);

    /* If the current msg is not existed */
    if ((g_mtv_sms_cntx.curr_msg_id == SRV_SMS_INVALID_MSG_ID) ||
        (list_index == SRV_SMS_INVALID_LIST_INDEX))
    {
        if (g_mtv_sms_cntx.curr_list_index == total_num)
        {
            list_index = g_mtv_sms_cntx.curr_list_index - 1;
        }
        else
        {
            list_index = g_mtv_sms_cntx.curr_list_index;
        }
    }

    return (S32)list_index;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_pre_entry_msgbox_list_option
 * DESCRIPTION
 *  Read current highlihgt msg before entry msgbox list options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_pre_entry_msgbox_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   mmi_mtv_sms_read_msg(
        g_mtv_sms_cntx.curr_msg_id,
        MMI_FALSE,
        mmi_mtv_sms_list_option_read_msg_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_option_read_msg_callback
 * DESCRIPTION
 *  Read current highlight msg callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_list_option_read_msg_callback(mmi_mtv_sms_result_enum result, void *data)
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
            mmi_mtv_sms_entry_msgbox_list_option();
            mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_POPUP_READING);
        }
        else if (IsScreenPresent(SCR_ID_MTV_SMS_POPUP_READING))
        {
            HistoryReplace(SCR_ID_MTV_SMS_POPUP_READING, SCR_ID_MTV_SMS_LIST_OPTIONS, mmi_mtv_sms_entry_msgbox_list_option);
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
 *  mmi_mtv_sms_entry_msgbox_list_option
 * DESCRIPTION
 *  Entry inbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_entry_msgbox_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mtv_sms_list_opt_check_item();
    mmi_mtv_sms_entry_common_options(SCR_ID_MTV_SMS_LIST_OPTIONS, MENU_ID_MTV_SMS_LIST_ROOT);
}



void mmi_mtv_sms_list_opt_check_item(void)
{
    switch (g_mtv_sms_cntx.curr_msg_status)
    {
        case MMI_MTV_SMS_STATUS_SENT:
            mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_LIST_FORWARD);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_EDIT);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_REPLY);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_RESEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_SEND);
            break;
            
        case MMI_MTV_SMS_STATUS_UNSENT:
            mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_LIST_RESEND);
            mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_LIST_EDIT);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_REPLY);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_FORWARD);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_SEND);
            if (!srv_sms_is_sms_valid())
            {
                mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_RESEND);
            }
            break;
            
        case MMI_MTV_SMS_STATUS_DRAFTS:
            mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_LIST_SEND);
            mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_LIST_EDIT);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_RESEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_REPLY);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_FORWARD);
            if (!srv_sms_is_sms_valid())
            {
                mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_SEND);
            }
            break;

        case MMI_MTV_SMS_STATUS_UNREAD:
        case MMI_MTV_SMS_STATUS_INBOX:
        {
            U16 temp[(SRV_SMS_MAX_ADDR_LEN + 1)] = {0};
            srv_sms_get_msg_address(g_mtv_sms_cntx.curr_msg_id, (S8*)temp);
            if (srv_sms_check_ucs2_number((S8 *)temp))
            {
                mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_LIST_REPLY);
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_REPLY);
            }
        }
            
            mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_LIST_FORWARD);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_EDIT);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_RESEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_SEND);
            break;
            
        case MMI_MTV_SMS_STATUS_UNSUPPORT:
            if (g_mtv_sms_cntx.curr_box_type == SRV_SMS_BOX_INBOX)
            {
                if (mmi_mtv_sms_check_is_valid_oa_addr(g_mtv_sms_cntx.curr_msg_id))
                {
                    mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_LIST_REPLY);
                }
                else
                {
                    mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_REPLY);
                }
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_REPLY);
            }
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_FORWARD);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_RESEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_SEND);
            mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_LIST_EDIT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_view_hilite
 * DESCRIPTION
 *  Entry inbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_list_view_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_select_view, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_select_view, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_select_view
 * DESCRIPTION
 *  Entry viewer from list option 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_select_view(void)
{
    mmi_mtv_sms_list_opt_pre_view();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_reply_hilite
 * DESCRIPTION
 *  hilite reply from list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_list_reply_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_select_reply, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_select_reply, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_select_reply
 * DESCRIPTION
 *  Entry reply from list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void mmi_mtv_sms_select_reply(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_LIST_SELECT, MENU_ID_MTV_SMS_LIST_REPLY, g_mtv_sms_cntx.curr_box_type, g_mtv_sms_cntx.curr_msg_id, g_mtv_sms_cntx.curr_list_index);

    mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_REPLY);
    mmi_mtv_sms_start_send_msg_get_sendcase();
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_LIST_OPTIONS);
    mmi_mtv_sms_send_register_call_back(mmi_mtv_sms_list_send_call_back);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_edit_hilite
 * DESCRIPTION
 *  hilite edit from list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void mmi_mtv_sms_list_edit_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_select_edit, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_select_edit, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_select_edit
 * DESCRIPTION
 *  Entry edit from list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void mmi_mtv_sms_select_edit(void)
{
    if (g_mtv_sms_cntx.curr_box_type == SRV_SMS_BOX_DRAFTS)
    {
        mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_EDIT_DRAFT);
    }
    else if (g_mtv_sms_cntx.curr_box_type == SRV_SMS_BOX_UNSENT)
    {
        mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_EDIT_UNSENT);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_LIST_SELECT, MENU_ID_MTV_SMS_LIST_EDIT, g_mtv_sms_cntx.curr_box_type, g_mtv_sms_cntx.curr_msg_id, g_mtv_sms_cntx.curr_list_index);
    mmi_mtv_sms_entry_write_msg_ems_cut_confirm();
    mmi_mtv_sms_send_register_call_back(mmi_mtv_sms_list_send_call_back);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_resend_hilite
 * DESCRIPTION
 *  hilte resend from inbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_list_resend_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_select_resend, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_select_resend, KEY_EVENT_UP);
}
 
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_select_resend
 * DESCRIPTION
 *  entry resend from list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void mmi_mtv_sms_select_resend(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_LIST_SELECT, MENU_ID_MTV_SMS_LIST_RESEND, g_mtv_sms_cntx.curr_box_type, g_mtv_sms_cntx.curr_msg_id, g_mtv_sms_cntx.curr_list_index);
    mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_RESEND);
    mmi_mtv_sms_start_send_msg_get_sendcase();
    mmi_mtv_sms_send_register_call_back(mmi_mtv_sms_list_send_call_back);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_forward_hilite
 * DESCRIPTION
 *  hilite forward from inbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void mmi_mtv_sms_list_forward_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_select_forward, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_select_forward, KEY_EVENT_UP);
}
  
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_select_forward
 * DESCRIPTION
 *  Entry forward list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void mmi_mtv_sms_select_forward(void)
{
    mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_FORWARD);
    mmi_mtv_sms_entry_write_msg_ems_cut_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_send_hilite
 * DESCRIPTION
 *  hikite send inbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_list_send_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_select_send, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_select_send, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_select_send
 * DESCRIPTION
 *  Entry send from inbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_select_send(void)
{
    mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_SEND_DRAFT);
    mmi_mtv_sms_start_send_msg_get_sendcase();
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_LIST_OPTIONS);
    mmi_mtv_sms_send_register_call_back(mmi_mtv_sms_list_send_call_back);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_delete_hilite
 * DESCRIPTION
 *  hilite delete from inbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_list_delete_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_select_delete, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_select_delete, KEY_EVENT_UP);
}
 
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_select_delete
 * DESCRIPTION
 *  Entry delete from inbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_select_delete(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_LIST_SELECT, MENU_ID_MTV_SMS_LIST_DELETE, g_mtv_sms_cntx.curr_box_type, g_mtv_sms_cntx.curr_msg_id, g_mtv_sms_cntx.curr_list_index);
    mmi_mtv_sms_list_pre_delete();
}
  
void mmi_mtv_sms_list_pre_delete(void)
{
    mmi_mtv_sms_set_confirm_generic(SCR_ID_MTV_SMS_CONFIRM_DELETE, STR_ID_MTV_SMS_IS_DELETE, mmi_mtv_sms_list_delete, mmi_mtv_sms_scrn_back);
    mmi_mtv_sms_entry_confirm_no_csk();

}
void mmi_mtv_sms_list_delete(void)
{
    mmi_mtv_sms_pre_entry_processing_screen(
        SCR_ID_MTV_SMS_POPUP_DELETE_PROCESSING, 
        0, 
        0, 
        NULL, 
        0, 
        NULL, 
        STR_GLOBAL_DELETING);
   srv_sms_delete_msg(g_mtv_sms_cntx.curr_msg_id, mmi_mtv_sms_list_delete_handle, NULL);
   mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_CONFIRM_DELETE);
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_delete_handle
 * DESCRIPTION
 *  handle send processing delete result
 * PARAMETERS
 *  req_data        [IN]    Send Request Data
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_list_delete_handle(srv_sms_callback_struct *callback_data)
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
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_deleteall_hilite
 * DESCRIPTION
 *  Hilite delete all from inbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_list_deleteall_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_select_delete_all, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_select_delete_all, KEY_EVENT_UP);
}
 
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_select_delete_all
 * DESCRIPTION
 *  Entry delete all inbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_select_delete_all(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_LIST_SELECT, MENU_ID_MTV_SMS_LIST_DELETE_ALL, g_mtv_sms_cntx.curr_box_type, g_mtv_sms_cntx.curr_msg_id, g_mtv_sms_cntx.curr_list_index);

    mmi_mtv_sms_set_confirm_generic(
        SCR_ID_MTV_SMS_CONFIRM_DELETE_ALL, 
        STR_ID_MTV_SMS_IS_DELETE_ALL, 
        mmi_mtv_sms_list_delete_all, 
        mmi_mtv_sms_scrn_back);
    mmi_mtv_sms_entry_confirm_no_csk();
} 

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_list_delete_all
 * DESCRIPTION
 *  Delete all
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_list_delete_all(void)
{
    srv_sms_sim_enum sim_id = SRV_SMS_SIM_1 | SRV_SMS_SIM_2;
    mmi_mtv_sms_pre_entry_processing_screen(
        SCR_ID_MTV_SMS_POPUP_DELETE_PROCESSING, 
        0, 
        0, 
        NULL, 
        0, 
        NULL, 
        STR_GLOBAL_DELETING);
    srv_sms_delete_msg_list(g_mtv_sms_cntx.curr_box_type, sim_id, mmi_mtv_sms_list_delete_handle, NULL);
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_CONFIRM_DELETE_ALL);

}

/*****************************************************************************
 * FUNCTION
 * mmi_mtv_sms_editor_send_call_back(mtv_sms_result_enum result); 
 * DESCRIPTION
 *  pre-entry write new sms 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_list_send_call_back(mtv_sms_result_enum result)
{
     mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_EDITOR);
     MTVReleaseEMSEditBuffer();
}

 
#endif  /* __MMI_ATV_SMS_SUPPORT__ */
