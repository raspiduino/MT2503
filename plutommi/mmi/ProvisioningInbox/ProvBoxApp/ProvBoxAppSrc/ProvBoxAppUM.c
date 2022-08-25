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
 * ProvBoxAppUM.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Provisioning Inbox UI main procedure.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && defined(__MMI_PROV_IN_UM__) 
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "mmi_inet_app_trc.h"
#include "mmi_frm_events_gprot.h"

#if defined(__MMI_UM_ITERATOR_VIEWER__) && defined(__MMI_PROV_IN_UM__)
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
#include "mmi_frm_gestures_gprot.h"
#endif
#endif

#include "UMGprot.h"
#include "UMDefs.h"

#ifdef __MMI_UM_ITERATOR_VIEWER__
#include "TimerEvents.h"
#endif

#include "wgui_categories_util.h"

#include "mmi_rp_app_cca_def.h"
#include "mmi_rp_app_provbox_def.h"

#include "ProvBoxSrvGProt.h"
#include "ProvBoxSrvIProt.h"
#include "ProvBoxAppGProt.h"
#include "ProvBoxAppProt.h"


/*****************************************************************************
 * Static Declaration
 *****************************************************************************/
#ifdef __MMI_UM_ITERATOR_VIEWER__
static void mmi_provbox_um_iter_view_cb(void *user_data);

static void mmi_provbox_um_iter_viewer_time_hdlr(void);
#endif

/*****************************************************************************
 * Local function
 *****************************************************************************/
#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
void mmi_provbox_um_set_sort_info(
         srv_um_list_idx_data_union *list_data, 
         const srv_provbox_msg_cmn_info_struct* msg_info,
         const S16 msg_size,
         U8 list_idx_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_list_idx_enum list_sort_type = (srv_um_list_idx_enum)list_idx_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UM_SET_SORT_INFO, list_sort_type);

    switch (list_sort_type)
    {
        case SRV_UM_LIST_IDX_MSG_SIZE:
            list_data->msg_size = msg_size;
            break;
            
        case SRV_UM_LIST_IDX_ADDRESS:
            mmi_ucs2ncpy(
                (CHAR*)list_data->address, 
                (CHAR*)msg_info->sender_addr.addr, 
                SRV_UM_MAX_LIST_INDEX_LEN);
            break;
            
        case SRV_UM_LIST_IDX_READ_STATUS:
            list_data->read_status = (msg_info->read_status == MMI_PROVBOX_MSG_READ_STATUS_READ);
            break;
            
        case SRV_UM_LIST_IDX_MSG_TYPE:
            list_data->msg_type = SRV_UM_MSG_PROV;
            break;
            
        case SRV_UM_LIST_IDX_SUBJECT:
            mmi_ucs2ncpy(
                 (CHAR *)list_data->subject, 
                 (CHAR *)get_string(mmi_provbox_get_sim_msg_title(mmi_frm_sim_to_index(msg_info->sim_id))), 
                 SRV_UM_MAX_LIST_INDEX_LEN);
            break;
        
        default:
            memset((void *)list_data, 0, sizeof(srv_um_list_idx_data_union));
            break;
    }
}
#endif /* __UNIFIED_MESSAGE_LIST_INDEX_DATA__ */


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  srv_provbox_um_traverse_process_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_provbox_um_traverse_process_msg_detail(
        srv_provbox_msg_cmn_info_struct *info, 
        S16 msg_size,
        U32 um_user_data,
        srv_um_detail_field_enum um_detail_field,
        srv_um_traverse_func um_traverse_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 traverse_reulst;
    srv_um_msg_detail_struct detail = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UM_TRAVERSE_PROCESS_MSG_DETAIL, info->msg_id, um_detail_field);

    detail.msg_id   = info->msg_id;
    detail.msg_type = SRV_UM_MSG_PROV;
    
    //is_all_field = um_detail_field == SRV_UM_DETAIL_ALL;
    
    if (um_detail_field & SRV_UM_DETAIL_TIMESTAMP)
    {
        detail.timestamp= info->timestamp;
    }
    if (um_detail_field & SRV_UM_DETAIL_MSG_BOX)
    {
        detail.msg_box_type = mmi_provbox_box_type_pbox2um(info->box_type);
    }
    if (um_detail_field & SRV_UM_DETAIL_READ_STATUS)
    {
        detail.read_status = srv_provbox_read_status_pbox2um(info->read_status);
    }
    if (um_detail_field & SRV_UM_DETAIL_MSG_SIZE)
    {
        detail.msg_size = msg_size;
    }
    if (um_detail_field & SRV_UM_DETAIL_ADDRESS || um_detail_field & SRV_UM_DETAIL_MULTI_ADDRESS)
    {
        mmi_provbox_add_address(
            &detail, (WCHAR *)info->sender_addr.addr, 
            srv_provbox_addr_type_pbox2um(info->sender_addr.addr_type),
            SRV_UM_ADDR_GROUP_FROM);
    }
    if (um_detail_field & SRV_UM_DETAIL_SUBJECT)
    {
        detail.subject = (WCHAR*)get_string(STR_ID_PROVBOX_PROV_ITEM_NAME);
    }

#if (MMI_MAX_SIM_NUM >= 2)
    if (um_detail_field & SRV_UM_DETAIL_SIM_ID)
    {
        detail.sim_id = srv_provbox_sim_pbox2um(info->sim_id);
    }
#endif

    traverse_reulst =  um_traverse_callback(um_user_data, (srv_um_msg_detail_struct*)&detail);
    
    //mmi_provbox_remove_address(&detail);

    return traverse_reulst;
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_set_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_um_set_msg_info(srv_um_msg_info_struct *um_msg_info, srv_provbox_msg_cmn_info_struct *cmn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *name = NULL;
    S32 name_len;
    WCHAR msg_addr[MMI_PROVBOX_ADDR_MAX_LEN] = {0};
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UM_SET_MSG_INFO, cmn_info->msg_id, cmn_info->box_type, cmn_info->timestamp, cmn_info->sender_addr.addr_type);

    if (NULL == um_msg_info || NULL == cmn_info)
    {
        return;
    }

    cntx->cur_box_type  =  cmn_info->box_type;    
    um_msg_info->msg_id = cmn_info->msg_id;
    um_msg_info->timestamp = cmn_info->timestamp;

    um_msg_info->address_type = srv_provbox_addr_type_pbox2um(cmn_info->sender_addr.addr_type);
    
    mmi_provbox_get_msg_address(
        msg_addr, (mmi_sim_enum)cmn_info->sim_id ,
        cmn_info->msg_type, &cmn_info->sender_addr);
 
    name_len = mmi_wcslen((const WCHAR*)msg_addr);

    if (um_msg_info->address_type == SRV_UM_ADDR_IP_ADDRESS && !mmi_provbox_ip_addr_is_validate((U16*)name, name_len))
    {
        um_msg_info->address_type = SRV_UM_ADDR_PLAIN_TEXT;
    }
    
    if (name_len <= SRV_UM_MAX_ADDR_LEN)
    {
        mmi_wcscpy((WCHAR*)um_msg_info->address, msg_addr);
        um_msg_info->address_length = name_len;
    }
    else
    {
        mmi_wcsncpy((WCHAR*) um_msg_info->address, (const WCHAR*)msg_addr, SRV_UM_MAX_ADDR_LEN);
        um_msg_info->address_length = SRV_UM_MAX_ADDR_LEN;
    }

    if (cmn_info->read_status == MMI_PROVBOX_MSG_READ_STATUS_UNREAD)
    {
        um_msg_info->icon_id = IMG_ID_PROVBOX_UNREAD;
    }
    else
    {
        um_msg_info->icon_id = IMG_ID_PROVBOX_READ;
    }

#if (MMI_MAX_SIM_NUM >= 2)
    um_msg_info->sim_id = srv_provbox_sim_pbox2um(cmn_info->sim_id);
#endif
    um_msg_info->csk_icon_id = IMG_GLOBAL_COMMON_CSK;

    /* Subject*/
    name = (WCHAR *)get_string(STR_ID_PROVBOX_PROV_ITEM_NAME);
    mmi_wcscpy((WCHAR*) um_msg_info->subject, (const WCHAR *)name);
    um_msg_info->subject_length = mmi_wcslen((const WCHAR *)name);
}


MMI_ID mmi_provbox_um_enter_msg(mmi_um_entry_msg_struct* um_entry_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID prov_gid;
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, 
        MMI_PROVBOXAPP_TRC_UM_ENTER_MSG, 
        um_entry_info->parent_grp_id, 
        um_entry_info->msg_id, 
        um_entry_info->key_code);

#ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_is_phone_lock())
    {
        return GRP_ID_INVALID;
    }
#endif

    prov_gid = mmi_provbox_scrn_group_create(um_entry_info->parent_grp_id);
 
    cntx->um_grp_id  = um_entry_info->parent_grp_id;
    cntx->cur_msg_id = um_entry_info->msg_id;
    cntx->user_data  = um_entry_info->user_data;

    if (MMI_UM_UI_ENTRY_KEY_CSK == um_entry_info->key_code ||
        MMI_UM_UI_ENTRY_INTUITIVE_CMD == um_entry_info->key_code)
    {
    /* Press CSK in UM box, install directly*/
    #ifdef __MMI_UM_ITERATOR_VIEWER__
        mmi_provbox_um_iter_viewer();
    #else
        mmi_provbox_msg_install(cntx->cur_msg_id);
    #endif
        return prov_gid;
    }

    return GRP_ID_INVALID;
}

#ifdef __MMI_UM_ITERATOR_VIEWER__
/*===========================================================================
 * Iterator viewer Handle
 *==========================================================================*/
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_iter_query_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_iter_query_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL query_result;
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();
    mmi_um_iter_viewer_info_struct um_iter_info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    um_iter_info.msg_id = cntx->cur_msg_id;
    um_iter_info.msg_type = SRV_UM_MSG_PROV;
    um_iter_info.user_data = cntx->user_data;
    um_iter_info.func_cb = mmi_provbox_um_iter_view_cb;

    if (NULL == cntx->um_iter_node)
    {
        cntx->um_iter_node = mmi_provbox_malloc(sizeof(mmi_um_iter_viewer_result_struct));
    }
    
    query_result = mmi_um_query_indexing(&um_iter_info, cntx->um_iter_node, cntx->user_data);

    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, 
        MMI_PROVBOXAPP_TRC_UM_ITER_QUERY_NODE, 
        cntx->cur_msg_id, 
        query_result);

    return query_result;
}


static void mmi_provbox_um_iter_view_cb(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_provbox_um_iter_query_node() != MMI_TRUE)
    {
        MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UM_ITER_VIEW_QUARY_NODE_FAIL);
        return;
    }

    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UM_ITER_VIEW_ENTER_PROPERTIES_SCRN);
    mmi_provbox_properties_scrn_show();
    mmi_provbox_progress_scrn_close();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_launch_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_um_iter_launch_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_iter_viewer_result_struct* iter_node;
    mmi_provbox_context_struct* cntx = mmi_provbox_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UM_ITER_LAUNCH_PREV);

    iter_node = cntx->um_iter_node;

    if (iter_node == NULL || iter_node->prev_launch_func_ptr == NULL)
        return;

    iter_node->prev_launch_func_ptr(cntx->um_grp_id, 
                   iter_node->prev_msg_id, 
                   cntx->user_data,
                   CUI_MSG_VIEWER_TYPE_ITERATOR);

    if (mmi_frm_scrn_get_active_id() == SCR_ID_PROVBOX_PROPERTIES)
    {
        return;
    }

    mmi_frm_scrn_close(mmi_provbox_scrn_group_get_id(), SCR_ID_PROVBOX_PROPERTIES);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_launch_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_um_iter_launch_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_iter_viewer_result_struct* iter_node;
    mmi_provbox_context_struct* cntx = mmi_provbox_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UM_ITER_LAUNCH_NEXT);

    iter_node = cntx->um_iter_node;

    if (iter_node == NULL || iter_node->next_launch_func_ptr == NULL)
        return;

    iter_node->next_launch_func_ptr(cntx->um_grp_id,
                   iter_node->next_msg_id, 
                   cntx->user_data,
                   CUI_MSG_VIEWER_TYPE_ITERATOR);

    if (mmi_frm_scrn_get_active_id() == SCR_ID_PROVBOX_PROPERTIES)
    {
        return;
    }
    
    mmi_frm_scrn_close(mmi_provbox_scrn_group_get_id(), SCR_ID_PROVBOX_PROPERTIES);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_iterator_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_provbox_um_iter_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_provbox_progress_scrn_show(MMI_PROVBOX_OP_READING_PROPERTIES);
    
    if (mmi_provbox_um_iter_query_node() != MMI_TRUE)
    {
        return;
    }

    mmi_provbox_um_iter_viewer_time_hdlr();
}


static void mmi_provbox_um_iter_viewer_time_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UM_ITER_VIEWER_TIME_HDLR);

    mmi_provbox_properties_scrn_show();
    
    mmi_provbox_progress_scrn_close();
}


#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_left_gesture_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_frm_gesture_event_enum  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_um_left_gesture_hdlr(mmi_frm_gesture_event_enum gesture_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FRM_GESTURE_RIGHT != gesture_event)
        return;

    mmi_provbox_um_iter_launch_prev();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_right_gesture_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_frm_gesture_event_enum  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_um_right_gesture_hdlr(mmi_frm_gesture_event_enum gesture_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FRM_GESTURE_LEFT != gesture_event)
        return;

    mmi_provbox_um_iter_launch_next();
}
#endif /* __MMI_TOUCH_SCREEN & __MMI_GESTURES_FRAMEWORK__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_iter_viewer_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_um_refresh_evt_struct* 
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
extern MMI_RET mmi_provbox_um_iter_viewer_refresh(mmi_um_refresh_evt_struct* refresh_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UM_ITER_VIEWER_REFRESH);

#ifdef __MMI_UM_ITERATOR_VIEWER__
    if (mmi_frm_scrn_is_present(mmi_provbox_scrn_group_get_id(), 
          SCR_ID_PROVBOX_PROPERTIES, MMI_FRM_NODE_ALL_FLAG) &&
        cntx->um_iter_node)
    {
        mmi_provbox_progress_scrn_show(MMI_PROVBOX_OP_READING_PROPERTIES);
           
        if (mmi_provbox_um_iter_query_node() != MMI_TRUE)
        {
            return MMI_RET_OK;
        }
        
        mmi_provbox_progress_scrn_close();
        return MMI_RET_OK;
    }
#endif
    return MMI_RET_OK;
}

#endif /* __MMI_UM_ITERATOR_VIEWER__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_iter_launch_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMI_ID parent_gid [IN]
 *  U32    msg_id     [IN]
 *  void*  user_data  [IN]
 *  cui_msg_viewer_type_enum [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_um_iter_launch_viewer(MMI_ID parent_gid, U32 msg_id, void *user_data, cui_msg_viewer_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct* cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UM_ITER_VIEWER, parent_gid, msg_id, type);

    cntx->um_grp_id  = parent_gid;
    cntx->cur_msg_id = msg_id;
    cntx->user_data  = user_data;


    if(GRP_ID_INVALID == parent_gid || MMI_PROVBOX_INVALID_MSG_ID == msg_id)
        return;
    
#ifdef __MMI_UM_ITERATOR_VIEWER__
    switch (type)
    {
        case CUI_MSG_VIEWER_TYPE_NORMAL:
            mmi_provbox_msg_install(cntx->cur_msg_id);
            break;

        case CUI_MSG_VIEWER_TYPE_ITERATOR:
	    if (GRP_ID_INVALID == mmi_provbox_scrn_group_get_id())
	    {
	        mmi_provbox_scrn_group_create(parent_gid);
	    }
            mmi_provbox_um_iter_viewer();
            break;

        default:
            MMI_ASSERT(0);
    }
#else
    #ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
        cntx->view_from_widget = MMI_TRUE;
    #endif
    MMI_ASSERT(CUI_MSG_VIEWER_TYPE_NORMAL == type);
    mmi_provbox_msg_install(cntx->cur_msg_id);
#endif /* __MMI_UM_ITERATOR_VIEWER__ */    
}


/*===========================================================================
 * FTE Handle
 *==========================================================================*/
#define MMI_PROVBOX_UM_FTT

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_reply_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_reply_check(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_forward_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_forward_check(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_send_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_send_check(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_edit_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_edit_check(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_resend_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_resend_check(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_delete_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_delete_check(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_activate_reply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_activate_reply(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_activate_forward
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_activate_forward(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_activate_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_activate_send(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_activate_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_activate_edit(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_activate_resend
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_activate_resend(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_um_activate_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_provbox_um_activate_delete(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct* cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_UM_MSG_PROV != msg_type)
    {
        return MMI_FALSE;
    }

    mmi_provbox_scrn_group_create(grp_id);
    
    cntx->cur_msg_id = msg_id;

    mmi_provbox_confirm_display(
         STR_ID_PROVBOX_DELETE_CONFIRM, 
         MMI_EVENT_QUERY, 
         mmi_provbox_msg_delete_confirm,
        (void*)MMI_PROVBOX_OP_DELECTING);
    
    return MMI_TRUE;
}
#endif /* __MMI_FTE_SUPPORT__ && __MMI_TOUCH_SCREEN__ */


/*===========================================================================
 * UM menu cui Handle
 *==========================================================================*/
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_get_option_menu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_MENU_ID
 *****************************************************************************/
MMI_MENU_ID mmi_provbox_um_get_option_menu_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MENU_ID_PROVBOX_OPTION_MENU;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_provboxui_menu_cui_cb_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 * mmi_event_struct*      [IN]
 * mmi_um_opt_para_struct*[OUT]
 * RETURNS
 * MMI_RET
 *****************************************************************************/
MMI_RET mmi_provbox_um_menu_cui_proc(mmi_event_struct *evt, mmi_um_opt_para_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct* cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_UM_MENU_CUI_PROC, para->parent_grp_id, para->msg_id);

    cntx->um_grp_id  = para->parent_grp_id;
    cntx->cur_msg_id = para->msg_id;
    cntx->user_data  = evt->user_data;
    
    if (evt == NULL || para == NULL)
    {
        return MMI_RET_OK;
    }

    mmi_provbox_scrn_group_evt_hdlr(evt, para);

    return MMI_RET_OK;
}

void mmi_provbox_um_scrn_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_context_struct* cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    cntx->um_grp_id    = GRP_ID_INVALID;
    cntx->group_id     = GRP_ID_INVALID;
    cntx->user_data    = NULL;
    cntx->cur_msg_id   = 0;
    cntx->cur_box_type = 0;
}

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ && __MMI_PROV_IN_UM__ */
