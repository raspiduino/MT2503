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
 *  mtvsmsphb.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  mtvsms[hb.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "mmi_include.h"
#ifdef __ATV_SMS_SUPPORT__

#include "PhoneBookGprot.h"
#include "PhoneBookProt.h"
#include "PhbSrvGprot.h"
#include "Phonebookresdef.h"
#include "MtvSMSIProt.h"

typedef void (*CallBackFuncPtr)(U16);

typedef struct
{
    U16 contact_count;
    U16 *contact_array;
    S32 hilite_index;
    U32 field_filter;
    CallBackFuncPtr g_matv_sms_phb_callback_ptr;
}mmi_matv_sms_phb_list_struct;


static mmi_matv_sms_phb_list_struct *g_mmi_matv_sms_phb_list_p;


void mmi_matv_sms_register_phb_list_callback(CallBackFuncPtr func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_matv_sms_phb_list_struct *sg_group_cntx = 
        (mmi_matv_sms_phb_list_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_MATV_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(sg_group_cntx != NULL);

    sg_group_cntx->g_matv_sms_phb_callback_ptr = func_ptr;
    return;
}


/* SRV_PHB_ENTRY_FIELD_GSM_NUM for number
 
 */
static U32 mmi_matv_sms_phb_get_filter_type(mmi_mtv_sms_phb_list_req_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MMI_MTV_SMS_PHB_NAME_REQ)
    {
        return SRV_PHB_ENTRY_FIELD_NAME;
    }
    else
    {
        return SRV_PHB_ENTRY_FIELD_NUMBER;
    }
}


static void mmi_matv_sms_exit_phb_list(void)
{
    mmi_mtv_sms_common_screen_exit();
    return;
}


static pBOOL mmi_matv_sms_phb_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_name(g_mmi_matv_sms_phb_list_p->contact_array[item_index], str_buff, MAX_SUBMENU_CHARACTERS);

    if (str_buff[0] == 0)
    {
        mmi_ucs2ncpy((S8*) str_buff, GetString(STR_ID_PHB_UNNAMED), MAX_SUBMENU_CHARACTERS);
    }

    mmi_phb_contact_get_item_image(g_mmi_matv_sms_phb_list_p->contact_array[item_index], img_buff_p, NULL);

    return TRUE;
}


static S32 mmi_matv_sms_phb_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index > g_mmi_matv_sms_phb_list_p->contact_count - 1)
    {
        return 0;
    }
    
    store_index = g_mmi_matv_sms_phb_list_p->contact_array[item_index];
    srv_phb_get_number(store_index, (U16*) hint_array[0], MAX_SUBMENU_CHARACTERS);
    return 1;
}


static void mmi_matv_sms_phb_list_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_matv_sms_phb_list_struct *sg_group_cntx = 
        (mmi_matv_sms_phb_list_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_MATV_GROUP);
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = sg_group_cntx->contact_array[sg_group_cntx->hilite_index];
    sg_group_cntx->g_matv_sms_phb_callback_ptr(store_index);
}


static void mmi_matv_sms_phb_list_hilite_handler(S32 field_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_matv_sms_phb_list_struct *sg_group_cntx = 
        (mmi_matv_sms_phb_list_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_MATV_GROUP);


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sg_group_cntx->hilite_index = field_index;
}


static mmi_ret mmi_matv_sms_entry_phb_list_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        param->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
        wgui_cat_matv_stop_video();
        wgui_cat_matv_reset_video_info();
    }
    return MMI_RET_OK;
}


static void mmi_matv_sms_entry_phb_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    srv_phb_filter_struct *filter;
    U16 contact_count;
    mmi_matv_sms_phb_list_struct *sg_group_cntx = 
        (mmi_matv_sms_phb_list_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_MATV_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(sg_group_cntx != NULL);

    if (!mmi_phb_check_ready(MMI_FALSE))
    {
        mmi_mtv_sms_display_popup(STR_PROCESSING_PHONEBOOK, MMI_MTV_SMS_NOTIFY_FAILURE);
        return;
    }
    kal_prompt_trace(MOD_MMI, "before entry phb screen scrn_id");
    mmi_frm_scrn_enter(GRP_ID_PHB_MATV_GROUP, SCR_ID_MATV_SMS_PHB_LIST, mmi_matv_sms_exit_phb_list, mmi_matv_sms_entry_phb_list, MMI_FRM_UNKNOW_SCRN);
    kal_prompt_trace(MOD_MMI, "entry phb screen scrn_id = %d", SCR_ID_MATV_SMS_PHB_LIST);
    wgui_cat_matv_init_video_info(
                    (U8 *)video_layer_buffer_ptr, 
                    MATV_VIDEO_LAYER_BUF_SIZE, 
                    (U8 *)util_layer_buffer_ptr, 
                    MATV_UTIL_LAYER_BUF_SIZE, 
                    mmi_mtv_sms_video_player_callback, 
                    mmi_mtv_sms_video_player_stop_callback);

    gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_PHB_MATV_GROUP, SCR_ID_MATV_SMS_PHB_LIST);
    RegisterHighlightHandler(mmi_matv_sms_phb_list_hilite_handler);

    filter = mmi_phb_list_build_filter(
                 (U8)mmi_phb_get_preferred_storage(),
                 sg_group_cntx->field_filter,
                 NULL,
                 NULL,
                 0);

    sg_group_cntx->contact_count = (U16) srv_phb_oplib_build_contact_list(filter, sg_group_cntx->contact_array, MMI_PHB_ENTRIES);

    mmi_phb_list_free_filter(filter);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    wgui_cat1011_show(
        get_string(STR_SCR_PBOOK_VIEW_CAPTION),
        NULL,
        get_string(STR_GLOBAL_OK),
        get_image(IMG_GLOBAL_OK),
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        sg_group_cntx->contact_count,
        mmi_matv_sms_phb_list_get_item,
        mmi_matv_sms_phb_list_get_hint,
        0,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_matv_sms_phb_list_lsk_handler, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_matv_sms_phb_list_lsk_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);    

    mmi_frm_scrn_set_leave_proc(GRP_ID_PHB_MATV_GROUP, SCR_ID_MATV_SMS_PHB_LIST, mmi_matv_sms_entry_phb_list_proc);
    
    if (mmi_is_redrawing_bk_screens())
    {
        wgui_cat_matv_stop_video();
        wgui_cat_matv_reset_video_info();
    }
}


static mmi_ret mmi_matv_sms_phb_list_group_proc_func(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_matv_sms_phb_list_struct * sg_group_cntx = 
        (mmi_matv_sms_phb_list_struct *)mmi_frm_group_get_user_data(GRP_ID_PHB_MATV_GROUP);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(param->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            if (sg_group_cntx->contact_array)
            {
                srv_phb_mem_free(sg_group_cntx->contact_array);
                sg_group_cntx->contact_array = NULL;
            }
            srv_phb_mem_free(sg_group_cntx);
            g_mmi_matv_sms_phb_list_p = NULL;
            break;

        case EVT_ID_GROUP_INACTIVE:
            mmi_mtv_sms_common_screen_exit();
            if (!mmi_frm_scrn_get_count(GRP_ID_PHB_MATV_GROUP))
            {
                mmi_frm_group_close(GRP_ID_PHB_MATV_GROUP);
            }
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


MMI_BOOL mmi_matv_sms_entry_phb_list_group(mmi_mtv_sms_phb_list_req_enum type)
{
    mmi_matv_sms_phb_list_struct * buf = 
            (mmi_matv_sms_phb_list_struct *)srv_phb_mem_malloc(sizeof(mmi_matv_sms_phb_list_struct), SRV_PHB_MEMORY_TYPE_ADM);
    srv_phb_filter_struct *filter;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_FALSE))
    {
        
        mmi_mtv_sms_display_popup(STR_PROCESSING_PHONEBOOK, MMI_MTV_SMS_NOTIFY_FAILURE);
        return MMI_FALSE;
    }

    memset(buf, 0x00, sizeof(mmi_matv_sms_phb_list_struct));

    buf->contact_array = srv_phb_mem_malloc(MMI_PHB_ENTRIES * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);

    buf->field_filter = mmi_matv_sms_phb_get_filter_type(type);

    filter = mmi_phb_list_build_filter(
         (U8)mmi_phb_get_preferred_storage(),
         buf->field_filter,
         NULL,
         NULL,
         0);
    buf->contact_count = (U16) srv_phb_oplib_build_contact_list(filter, buf->contact_array, MMI_PHB_ENTRIES);
    mmi_phb_list_free_filter(filter);

    if ( buf->contact_count <= 0)
    {
        mmi_mtv_sms_display_popup(STR_ID_PHB_NO_ENTRY_TO_SELECT, MMI_MTV_SMS_NOTIFY_FAILURE);
        srv_phb_mem_free(buf->contact_array);
        srv_phb_mem_free(buf);
        return MMI_FALSE;
    }
    
    g_mmi_matv_sms_phb_list_p = buf;

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_PHB_MATV_GROUP, mmi_matv_sms_phb_list_group_proc_func, buf);
    mmi_frm_group_enter(GRP_ID_PHB_MATV_GROUP, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_matv_sms_entry_phb_list();
    return MMI_TRUE;
}

void mmi_matv_sms_phb_list_close(void)
{
    mmi_frm_group_close(GRP_ID_PHB_MATV_GROUP);
}

#endif /*  __MMI_ATV_SMS_SUPPORT__ */

