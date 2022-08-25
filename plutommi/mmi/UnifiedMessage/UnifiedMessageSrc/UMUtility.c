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

/*******************************************************************************
 * Filename:
 * ---------
 * UMUtility.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __UM_SUPPORT__
#include "UMDefs.h"
#include "UMProt.h"
#include "mmi_rp_app_unifiedmessage_def.h"

#ifdef __MMI_BROWSER_2__
#include "BrowserGprots.h"
#endif /* __MMI_BROWSER_2__ */
#include "IdleNotificationManagerGprot.h"
#include "MMIDataType.h"
#include "UmSrvGprot.h"
#include "UmSrvDefs.h"
#include "GlobalResDef.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "string.h"
#include "GlobalConstants.h"
#include "Unicodexdcl.h"
#include "CustMenuRes.h"
#include "stdio.h"
#include "smsappgprot.h"

#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
static mmi_um_ui_sms_content_mananger_struct g_mmi_um_ui_sms_content_manager_queue;
static mmi_um_ui_sms_content_buffer_pool_struct g_mmi_um_ui_sms_content_buffer_pool;

static mmi_um_ui_sms_content_manager_unit_struct *mmi_um_ui_sms_use_a_content_manager(U16 index);
static mmi_um_ui_sms_content_manager_unit_struct *mmi_um_ui_sms_get_first_free_content_manager(void);
static mmi_um_ui_sms_content_manager_unit_struct* mmi_um_ui_sms_get_first_finished_content_manager(void);
static mmi_um_ui_sms_content_manager_unit_struct* mmi_um_ui_sms_get_first_finished_but_failed_content_manager(void);
static mmi_um_ui_sms_content_manager_unit_struct* mmi_um_ui_sms_get_first_certain_content_manager(mmi_um_ui_sms_content_manager_unit_status query_staus);
static void mmi_um_ui_sms_recycle_a_single_manager(mmi_um_ui_sms_content_manager_unit_struct* manager_to_remove);
static void mmi_um_ui_sms_content_manager_reset_a_unit(mmi_um_ui_sms_content_manager_unit_struct *manager_to_reset);
static mmi_um_ui_sms_content_manager_unit_struct* mmi_um_ui_sms_get_manager_by_id(um_sms_id message_id);
static void mmi_um_ui_sms_content_manager_read_content_callback(srv_sms_callback_struct* callback_data);
static void mmi_um_ui_sms_content_manager_occupy_a_content_buffer(mmi_um_ui_sms_content_manager_unit_struct* occupier);
static void mmi_um_ui_sms_content_manager_release_a_content_buffer(CHAR *content_buffer, mmi_um_ui_sms_content_manager_unit_struct *occupier);
static mmi_um_ui_sms_content_manager_unit_status mmi_um_ui_sms_get_manager_status(mmi_um_ui_sms_content_manager_unit_struct* unit);
static mmi_um_ui_sms_content_manager_unit_struct* mmi_um_ui_sms_get_farest_finished_content_manager(U16 index);

#endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */

#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
/* extern APIs */
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sms_check_sms_content
 * DESCRIPTION
 *  Fill SMS content for SMSes passed in
 *
 * PARAMETERS
 *  messages [IN]: messages need content
 *  content_buffers[OUT]: An array to store message content buffers support check only by pass NULL in
 *  message_nubmer [IN] : Numbers of messages need content
 * RETURNS
 *  SRV_UM_RESULT_DATA_NOT_FOUND if not all contens are cached
 *  SRV_UM_RESULT_OK if all contens are cached
 *****************************************************************************/
S32 mmi_um_ui_sms_check_sms_content(um_sms_id messages[], U16 *indexes, S32 message_number,  CHAR **content_buffers)
{
    S32 check_result = SRV_UM_RESULT_OK;
    S32 iter = 0;
    for (;iter < message_number; iter++)
    {
        mmi_um_ui_sms_content_manager_unit_struct *unit = mmi_um_ui_sms_get_manager_by_id(messages[iter]);
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_CHECK_EACH, messages[iter]);
        if (NULL != unit)
        {
            mmi_um_ui_sms_content_manager_unit_status unit_status = mmi_um_ui_sms_get_manager_status(unit);
            if (MMI_UM_UI_CONTENT_MANAGER_DONE == unit_status || 
                MMI_UM_UI_CONTENT_MANAGER_DONE_WITH_ERROR == unit_status)
            {
                if (content_buffers != NULL)
                /* support check only */
                {
                    content_buffers[iter] = unit->content_buffer;
                }
                unit->reference_index = indexes[iter];
                continue;
            }
        }
        else
        {
            if (content_buffers != NULL)
            /* support check only */
            {
                content_buffers[iter] = NULL;
            }
        }
        check_result = SRV_UM_RESULT_DATA_NOT_FOUND;
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_CHECK_RESULT, check_result);
    return check_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sms_get_sms_content_request
 * DESCRIPTION
 *  Get SMS contents, and will ignore the ones that are cached or in process,
 *  will be stopped if no usable cache unit is got
 *
 * PARAMETERS
 *  messages [IN]: messages need content
 *  message_number [IN] : Numbers of messages need content
 *  request requester_scrn [IN]: Used to identify screen. When callback returns, check screen status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sms_get_sms_content_request(um_sms_id messages[], U16 *indexes, S32 message_number, U16 requester_scrn)
{
    S32 iter = 0;
    if (g_mmi_um_ui_sms_content_manager_queue.requester_scrn_id != requester_scrn)
    {
        /* force farther index for new screen */
        S32 i = 0;
        for (; i < MMI_UM_CONTENT_CACHE_UNIT_AMOUNT; i++)
        {
            g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[i]->reference_index += SRV_SMS_INVALID_LIST_INDEX * 2;
        }
    }
    g_mmi_um_ui_sms_content_manager_queue.requester_scrn_id = requester_scrn;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_REQUEST_SCREEN, g_mmi_um_ui_sms_content_manager_queue.requester_scrn_id);
    for (;iter < message_number; iter++)
    {
        mmi_um_ui_sms_content_manager_unit_struct *cached_unit;
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_USAGE_AMOUNT, g_mmi_um_ui_sms_content_manager_queue.total_units_running);
        if (MMI_UM_CONTENT_RUNNING_PORCESS_AMOUNT == g_mmi_um_ui_sms_content_manager_queue.total_units_running)
        {
            return;
        }
        MMI_ASSERT(g_mmi_um_ui_sms_content_manager_queue.total_units_running <= MMI_UM_CONTENT_RUNNING_PORCESS_AMOUNT);
        cached_unit = mmi_um_ui_sms_get_manager_by_id(messages[iter]);
        /* got one */
        if (cached_unit)
        {
            mmi_um_ui_sms_content_manager_unit_status content_status = mmi_um_ui_sms_get_manager_status(cached_unit);
            cached_unit->reference_index = (indexes[iter]);
            /* this one is in error status, remove and get it again */
            if (MMI_UM_UI_CONTENT_MANAGER_DONE_WITH_ERROR == content_status)
            {
                mmi_um_ui_sms_recycle_a_single_manager(cached_unit);
                /* update cached one */
                cached_unit = mmi_um_ui_sms_get_manager_by_id(messages[iter]);
                MMI_ASSERT(cached_unit == NULL);
            }
            /* this one is in processing, ignore it and wait for callback */
            else if ((MMI_UM_UI_CONTENT_MANAGER_PROCESSING == content_status) ||
                     (MMI_UM_UI_CONTENT_MANAGER_CANCELLNG== content_status))
            {
                continue;
            }
        }
        /* not got or error one is removed, otherwise thie content is cached without error */
        if (NULL == cached_unit)
        {
            /* try to get a usable unit again, it maybe released from an error one */
            mmi_um_ui_sms_content_manager_unit_struct *unit = mmi_um_ui_sms_use_a_content_manager(indexes[iter]);
            if (NULL != unit)
            {
                srv_sms_msg_data_struct *msg_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));
                unit->sms_handler = msg_data;
                unit->msg_id = messages[iter];
                msg_data->para_flag = SRV_SMS_PARA_CONTENT_BUFF;
                msg_data->content_buff = unit->content_buffer;
                msg_data->content_buff_size = MMI_UM_CONTENT_CACHE_CHARACTOR_NUMBER * ENCODING_LENGTH;
                unit->content_status = MMI_UM_UI_CONTENT_MANAGER_PROCESSING;
                unit->reference_index = (indexes[iter]);
                g_mmi_um_ui_sms_content_manager_queue.total_units_running++;
                srv_sms_read_msg(
                    unit->msg_id,
                    MMI_TRUE,
                    msg_data,
                    mmi_um_ui_sms_content_manager_read_content_callback,
                    unit);
            }
            else
            {
                /* All SMS srv are in processiong, just wait for callback, 
                which will invoke get item again */
                return;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sms_content_manager_init
 * DESCRIPTION
 *  init content manager, set content buffer and never release the buffer
 * PARAMETERS
 *  messages [IN]: messages need content
 *  message_number [IN] : Numbers of messages need content
 *  request requester_scrn [IN]: Used to identify screen. When callback returns, check screen status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sms_content_manager_init(void)
{
    S32 iter = 0;
    for (;iter < MMI_UM_CONTENT_CACHE_UNIT_AMOUNT; iter++)
    {
        mmi_um_ui_sms_content_manager_unit_struct *unit = &g_mmi_um_ui_sms_content_manager_queue.content_manager_pool[iter];
        g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[iter] = unit;
        mmi_um_ui_sms_content_manager_reset_a_unit(unit);
        mmi_um_ui_sms_content_manager_occupy_a_content_buffer(unit);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sms_content_manager_refresh_handler
 * DESCRIPTION
 *  remove or cancel msg is refreshed. 
 *  UI update will be applied by screen, no need to notify
 * PARAMETERS
 *  refresh_srv_ev [IN]: event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_sms_content_manager_refresh_handler(srv_um_notify_refresh_evt_struct *refresh_srv_ev)
{
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_REFERSH, refresh_srv_ev->msg_type);
    if ((SRV_UM_MSG_SMS == refresh_srv_ev->msg_type) &&
        (refresh_srv_ev->msg_box_type & SRV_UM_MSG_BOX_CONVERSATION) &&
        (refresh_srv_ev->refresh_type != SRV_UM_REFRESH_MSG_STATUS_CHANGED))
    {
        S32 i = 0;
        for(; i < MMI_UM_CONTENT_CACHE_UNIT_AMOUNT; i++)
        {
            mmi_um_ui_sms_content_manager_unit_struct *manager = &g_mmi_um_ui_sms_content_manager_queue.content_manager_pool[i];
            MMI_ASSERT(manager != NULL);
            {
                mmi_um_ui_sms_content_manager_unit_status unit_status = mmi_um_ui_sms_get_manager_status(manager);
                if (MMI_UM_UI_CONTENT_MANAGER_DONE == unit_status ||
                        MMI_UM_UI_CONTENT_MANAGER_DONE_WITH_ERROR == unit_status)
                {
                    mmi_um_ui_sms_recycle_a_single_manager(manager);
                }
                else
                {
                    if (MMI_UM_UI_CONTENT_MANAGER_PROCESSING == manager->content_status)
                    {
                        manager->content_status = MMI_UM_UI_CONTENT_MANAGER_CANCELLNG;
                    }
                }
            }
        }
    }
}


/* internal APIs */
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_sms_use_a_content_manager
 * DESCRIPTION
 *  Get a SMS content manger with certain order.
 *
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_um_ui_sms_content_manager_unit_struct pointer, return NULL if nothing can get
 *****************************************************************************/
mmi_um_ui_sms_content_manager_unit_struct *mmi_um_ui_sms_use_a_content_manager(U16 index)
{
    mmi_um_ui_sms_content_manager_unit_struct *unit;
    do{
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_USAGE_AMOUNT, g_mmi_um_ui_sms_content_manager_queue.total_units_running);
        unit = mmi_um_ui_sms_get_first_free_content_manager();
        if (NULL == unit)
        {
            mmi_um_ui_sms_content_manager_unit_struct *finished_unit = mmi_um_ui_sms_get_first_finished_but_failed_content_manager();
            if (NULL == finished_unit)
            {
                 /*finished_unit = mmi_um_ui_sms_get_first_finished_content_manager(); */
                finished_unit = mmi_um_ui_sms_get_farest_finished_content_manager(index);
            }
            if (NULL != finished_unit)
            {
                mmi_um_ui_sms_recycle_a_single_manager(finished_unit);
                finished_unit = NULL;
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            return unit;
        }
    }while(NULL == unit);
    return NULL;
}


mmi_um_ui_sms_content_manager_unit_struct *mmi_um_ui_sms_get_first_free_content_manager(void)
{
    return mmi_um_ui_sms_get_first_certain_content_manager(MMI_UM_UI_CONTENT_MANAGER_UNUSED);
}

mmi_um_ui_sms_content_manager_unit_struct* mmi_um_ui_sms_get_first_finished_content_manager(void)
{
    /* only used if no free unit is got */
    return mmi_um_ui_sms_get_first_certain_content_manager(MMI_UM_UI_CONTENT_MANAGER_DONE);
}


mmi_um_ui_sms_content_manager_unit_struct* mmi_um_ui_sms_get_farest_finished_content_manager(U16 index)
{
    S32 i = 0;
    S32 farest = 0;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_QUERY_MANAGER, 0xff);
    for (; i < MMI_UM_CONTENT_CACHE_UNIT_AMOUNT; i++)
    {
        mmi_um_ui_sms_content_manager_unit_status status = mmi_um_ui_sms_get_manager_status(g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[i]);
        if ((status == MMI_UM_UI_CONTENT_MANAGER_DONE) || (status == MMI_UM_UI_CONTENT_MANAGER_DONE_WITH_ERROR))
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_QUERY_MANAGER_INDEX, 100 + i);
            {
                /* compare which is farer */
                if (abs(g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[farest]->reference_index - index) <= 
                    abs(g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[i]->reference_index - index))
                {
                    farest = i;
                }
            }
        }
    }
    return g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[farest];
}


mmi_um_ui_sms_content_manager_unit_struct* mmi_um_ui_sms_get_first_finished_but_failed_content_manager(void)
{
    /* only used if no free unit is got */
    return mmi_um_ui_sms_get_first_certain_content_manager(MMI_UM_UI_CONTENT_MANAGER_DONE_WITH_ERROR);
}


mmi_um_ui_sms_content_manager_unit_struct* mmi_um_ui_sms_get_first_certain_content_manager(mmi_um_ui_sms_content_manager_unit_status query_staus)
{
    S32 i = 0;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_QUERY_MANAGER, query_staus);
    for (; i < MMI_UM_CONTENT_CACHE_UNIT_AMOUNT; i++)
    {
        if (mmi_um_ui_sms_get_manager_status(g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[i])== query_staus)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_QUERY_MANAGER_INDEX, i);
            return g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[i];
        }
    }
    /* not got, return NULL */
    return NULL;
}


mmi_um_ui_sms_content_manager_unit_status mmi_um_ui_sms_get_manager_status(mmi_um_ui_sms_content_manager_unit_struct* unit)
{
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_UNIT_STATUS, unit->content_status);
    return unit->content_status;
}


void mmi_um_ui_sms_recycle_a_single_manager(mmi_um_ui_sms_content_manager_unit_struct* manager_to_reuse)
{
    S32 i = 0;
    MMI_ASSERT(NULL != manager_to_reuse);
    MMI_ASSERT(manager_to_reuse->content_status != MMI_UM_UI_CONTENT_MANAGER_PROCESSING);
    MMI_ASSERT(manager_to_reuse->content_status != MMI_UM_UI_CONTENT_MANAGER_CANCELLNG);
    MMI_ASSERT(NULL == manager_to_reuse->sms_handler);
    for (; i < MMI_UM_CONTENT_CACHE_UNIT_AMOUNT; i++)
    {
        if (g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[i] == manager_to_reuse)
        {
            break;
        }
    }
    MMI_ASSERT(i < MMI_UM_CONTENT_CACHE_UNIT_AMOUNT);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_RECYCLE, manager_to_reuse, i);
    for (; i < MMI_UM_CONTENT_CACHE_UNIT_AMOUNT - 1; i++)
    {
        g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[i] = g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[i + 1];
    }
    g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[i] = manager_to_reuse;
    mmi_um_ui_sms_content_manager_reset_a_unit(manager_to_reuse);
}


void mmi_um_ui_sms_content_manager_reset_a_unit(mmi_um_ui_sms_content_manager_unit_struct *manager_to_reset)
{
    MMI_ASSERT(NULL != manager_to_reset);
    MMI_ASSERT(manager_to_reset->content_status != MMI_UM_UI_CONTENT_MANAGER_PROCESSING);
    MMI_ASSERT(manager_to_reset->content_status != MMI_UM_UI_CONTENT_MANAGER_CANCELLNG);
    MMI_ASSERT(NULL == manager_to_reset->sms_handler);
    manager_to_reset->content_status = MMI_UM_UI_CONTENT_MANAGER_UNUSED;
    manager_to_reset->sms_handler = NULL;
    manager_to_reset->msg_id = SRV_SMS_INVALID_MSG_ID;
    manager_to_reset->reference_index = SRV_SMS_INVALID_LIST_INDEX * 3;
}


mmi_um_ui_sms_content_manager_unit_struct* mmi_um_ui_sms_get_manager_by_id(um_sms_id message_id)
{
    S32 i = 0;
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_GET_BY_ID, message_id);
    for (; i < MMI_UM_CONTENT_CACHE_UNIT_AMOUNT; i++)
    {
        if (g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[i]->msg_id == message_id)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_GET_BY_ID_INDEX_GOT, i);
            return g_mmi_um_ui_sms_content_manager_queue.content_manager_queue[i];
        }
    }
    return NULL;
}


static void mmi_um_ui_sms_content_manager_read_content_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_msg_cb_struct *read_msg_cb_data;
    srv_sms_msg_data_struct *msg_data;
    mmi_um_ui_sms_content_manager_unit_struct *manager;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_msg_cb_data = (srv_sms_read_msg_cb_struct*)callback_data->action_data;
    manager = (mmi_um_ui_sms_content_manager_unit_struct *)callback_data->user_data;
    msg_data = read_msg_cb_data->msg_data;
    MMI_ASSERT(manager->sms_handler == msg_data);
    manager->sms_handler = NULL;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_READ_CALLBACK, manager, msg_data, manager->content_status, callback_data->result);
    if (manager->content_status == MMI_UM_UI_CONTENT_MANAGER_CANCELLNG)
    {
        manager->content_status = MMI_UM_UI_CONTENT_MANAGER_DONE_WITH_ERROR;
        mmi_um_ui_sms_recycle_a_single_manager(manager);
    }
	else
	{
		if (callback_data->result == MMI_FALSE)
	    {
	        manager->content_status = MMI_UM_UI_CONTENT_MANAGER_DONE_WITH_ERROR;
	        mmi_ucs2cpy((CHAR*)manager->content_buffer, (CHAR*)get_string(STR_GLOBAL_UNFINISHED));
	    }
	    else
	    {
	        manager->content_status = MMI_UM_UI_CONTENT_MANAGER_DONE;
	        mmi_sms_update_content_according_to_message_id(manager->msg_id, ((CHAR*)manager->content_buffer));
	    }
	}
    g_mmi_um_ui_sms_content_manager_queue.total_units_running--;
    OslMfree(msg_data);
    if (g_mmi_um_ui_sms_content_manager_queue.total_units_running == 0)
    {
        mmi_um_ui_fsm_ef_get_msg_content_callback(g_mmi_um_ui_sms_content_manager_queue.requester_scrn_id);
    }
}


void mmi_um_ui_sms_content_manager_occupy_a_content_buffer(mmi_um_ui_sms_content_manager_unit_struct *occupier)
{
    S32 i = 0;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_OCCUPY_CONTENT_BUFFER, occupier, occupier->content_buffer);
    for (; i < MMI_UM_CONTENT_CACHE_UNIT_AMOUNT; i++)
    {
        if (g_mmi_um_ui_sms_content_buffer_pool.accupier[i] == NULL)
        {
            MMI_ASSERT(mmi_ucs2strlen((const CHAR *)g_mmi_um_ui_sms_content_buffer_pool.buffer_pool[i].content) == 0);
            g_mmi_um_ui_sms_content_buffer_pool.accupier[i] = occupier;
            occupier->content_buffer = (CHAR *)g_mmi_um_ui_sms_content_buffer_pool.buffer_pool[i].content;
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_CONTENT_CACHE_OCCUPY_CONTENT_BUFFER, occupier, occupier->content_buffer);
            return;
        }
    }
    MMI_ASSERT(NULL == "content buffer full!");
}


void mmi_um_ui_sms_content_manager_release_a_content_buffer(CHAR *content_buffer, mmi_um_ui_sms_content_manager_unit_struct *occupier)
{
    S32 i = 0;
    for (; i < MMI_UM_CONTENT_CACHE_UNIT_AMOUNT; i++)
    {
        if (g_mmi_um_ui_sms_content_buffer_pool.accupier[i] == occupier)
        {
            MMI_ASSERT(content_buffer == (CHAR *)g_mmi_um_ui_sms_content_buffer_pool.buffer_pool[i].content);
            g_mmi_um_ui_sms_content_buffer_pool.accupier[i] = NULL;
            g_mmi_um_ui_sms_content_buffer_pool.buffer_pool[i].content[0] = 0;
        }
    }
}

#endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_str_id_by_folder
 * DESCRIPTION
 *  Get the string id by folder type.
 *
 * PARAMETERS
 *  folder_type         [IN]: Folder type
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_um_ui_ut_get_str_id_by_folder(srv_um_box_identity_struct folder_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = 0;
    
    switch (folder_type.msg_box_type)
    {
        case SRV_UM_MSG_BOX_INBOX:
        {
            str_id = STR_GLOBAL_INBOX;
            break;
        }
        case SRV_UM_MSG_BOX_UNSENT:
        {
            str_id = STR_GLOBAL_OUTBOX;
            break;
        }
        case SRV_UM_MSG_BOX_SENT:
        {
            str_id = STR_UM_SENT_ID;
            break;
        }
        case SRV_UM_MSG_BOX_DRAFT:
        {
            str_id = STR_GLOBAL_DRAFTS;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_UM_MSG_BOX_ARCHIVE:
        {
            str_id = STR_UM_ARCHIVE_ID;
            break;
        }
    #endif
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case SRV_UM_MSG_BOX_SIM:
        {
            str_id = STR_UM_SIM_ID;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    #ifdef __MMI_UM_REPORT_BOX__
        case SRV_UM_MSG_BOX_REPORT:
        {
            str_id = STR_UM_REPORT_ID;
            break;
        }
    #endif /* __MMI_UM_REPORT_BOX__ */
        default:
        {
            break;
        }
    }

    return str_id;
}


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_str_id_by_option
 * DESCRIPTION
 *  Get the string id by folder type.
 *
 * PARAMETERS
 *  folder_type         [IN]: Folder type
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_um_ui_ut_get_str_id_by_option(srv_um_mark_several_op_action_enum option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = 0;
    
    switch (option)
    {
        case SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE:
            str_id = STR_UM_DELETE_MARKED_ID_PRE;
            break;
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE: 
           str_id = STR_UM_MOVE_MARKED_TO_ARCHIVE_ID_PRE;
           break;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifndef __UM_FOLDER__
        case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_SIM:  
            str_id = STR_UM_MOVE_TO_SIM_PRE;
            break;
        case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_PHONE:
            str_id = STR_UM_MOVE_TO_PHONE_PRE;
            break;
        case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM:     
            str_id = STR_UM_COPY_TO_SIM_PRE;
            break;
        case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_PHONE:
            str_id = STR_UM_COPY_TO_PHONE_PRE;
            break;
    #endif /* __UM_FOLDER__ */
    }

    return str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_menu_id_by_option
 * DESCRIPTION
 *  Get the string id by folder type.
 *
 * PARAMETERS
 *  folder_type         [IN]: Folder type
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_um_ui_ut_get_menu_id_by_option(srv_um_mark_several_op_action_enum option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 menu_id;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = 0;
    
    switch (option)
    {
        case SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE:
            menu_id = MENU_ID_UM_MULTI_OP_DELETE;
            break;
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE: 
            menu_id = MENU_ID_UM_MULTI_OP_MOVE_TO_ARCHIVE;
            break;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifndef __UM_FOLDER__
        case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_SIM:  
            menu_id = MENU_ID_UM_MULTI_OP_MOVE_TO_SIM;
            break;
        case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_PHONE:
            menu_id = MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE;
            break;
        case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM:     
            menu_id = MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE;
            break;
        case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_PHONE:
            menu_id = MENU_ID_UM_MULTI_OP_COPY_TO_PHONE;
            break;
    #endif /* __UM_FOLDER__ */
    }

    return menu_id;
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_fsm_event_by_ui_event
 * DESCRIPTION
 *  Get the FSM event enum value by UI event enum value
 *
 * PARAMETERS
 *  ui_event            [IN]: UI event value
 *  
 * RETURNS
 *  fsm_event value
 *****************************************************************************/
U16 mmi_um_ui_ut_get_fsm_event_by_ui_event(U16 ui_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 fsm_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fsm_event = MMI_UM_UI_FSM_EVENT_TOTAL;
    
    switch (ui_event)
    {
        case MMI_UM_UI_EVENT_INIT:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_INIT;
            break;
        }
        case MMI_UM_UI_EVENT_REFRESH:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_REFRESH;
            break;
        }
        case MMI_UM_UI_EVENT_ABORT:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_ABORT;
            break;
        }
        case MMI_UM_UI_EVENT_DELETE:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_DELETE;
            break;
        }
        case MMI_UM_UI_EVENT_CHECK:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_CHECK;
            break;
        }
        case MMI_UM_UI_EVENT_READY:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_READY;
            break;
        }
        case MMI_UM_UI_EVENT_UNREADY:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_UNREADY;
            break;
        }
        case MMI_UM_UI_EVENT_REL_DATA_LIST:
        {
            fsm_event = MMI_UM_UI_FSM_EVENT_REL_DATA_LIST;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return fsm_event;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_not_available_string_id
 * DESCRIPTION
 *  Get string ID for not available case
 * PARAMETERS
 *  void
 * RETURNS
 *  UM not available string ID
 *****************************************************************************/
U16 mmi_um_get_not_available_string_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return STR_GLOBAL_NOT_AVAILABLE;
}


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_ms_action_by_fsm_type
 * DESCRIPTION
 *  Transfer the type from FSM to service.
 *
 * PARAMETERS
 *  action:         [IN]    Action type
 *
 * RETURNS
 *  The service level action type
 *****************************************************************************/
srv_um_mark_several_op_action_enum mmi_um_ui_ut_get_ms_action_by_fsm_type(mmi_um_ui_req_srv_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_mark_several_op_action_enum srv_action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_action = SRV_UM_MARK_SEVERAL_OP_ACTION_NONE;

    switch (action)
    {
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_DELETE:
        case MMI_UM_UI_ACTION_DELETE_THRD_MSG:
        case MMI_UM_UI_ACTION_MS_DELETE_THRD_MSG:
        {
            srv_action = SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE;
            break;
        }
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_ARCHIVE:
        case MMI_UM_UI_ACTION_MOV2ARC_THRD_MSG:
        case MMI_UM_UI_ACTION_MS_MOV2ARC_THRD_MSG:
        {
            srv_action = SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE;
            break;
        }
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_SIM:
        {
            srv_action = SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_SIM;
            break;
        }
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_PHONE:
        {
            srv_action = SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_PHONE;
            break;
        }
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_SIM:
        {
            srv_action = SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM;
            break;
        }
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_PHONE:
        {
            srv_action = SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_PHONE;
            break;
        }
        default:
        {
            break;
        }
    }

    return srv_action;
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_activate_str_id_by_op
 * DESCRIPTION
 *  Get the activating string id by operation
 *
 * PARAMETERS
 *  action:         [IN]    Operation
 *
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_um_ui_ut_get_activate_str_id_by_op(mmi_um_ui_req_srv_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = 0;
    
    switch (action)
    {
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_DELETE:
        case MMI_UM_UI_ACTION_DELETE_THRD_MSG:
        case MMI_UM_UI_ACTION_DELETE_FOLDER:
        case MMI_UM_UI_ACTION_MS_DELETE_THRD_MSG:
        {
            str_id = STR_GLOBAL_DELETING;
            break;
        }
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_ARCHIVE:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_SIM:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_PHONE:
        case MMI_UM_UI_ACTION_MOV2ARC_THRD_MSG:
        case MMI_UM_UI_ACTION_MS_MOV2ARC_THRD_MSG:
        {
            str_id = STR_GLOBAL_MOVING;
            break;
        }
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_SIM:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_PHONE:
        {
            str_id = STR_GLOBAL_COPYING;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return str_id;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_cancel_str_id_by_op
 * DESCRIPTION
 *  Get the cancel string id by operation
 *
 * PARAMETERS
 *  action:         [IN]    Operation
 *
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_um_ui_ut_get_cancel_str_id_by_op(mmi_um_ui_req_srv_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = 0;
    
    switch (action)
    {
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_DELETE:
        case MMI_UM_UI_ACTION_DELETE_THRD_MSG:
        case MMI_UM_UI_ACTION_DELETE_FOLDER:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_ARCHIVE:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_SIM:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_PHONE:
        case MMI_UM_UI_ACTION_MOV2ARC_THRD_MSG:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_SIM:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_PHONE:
        case MMI_UM_UI_ACTION_MS_DELETE_THRD_MSG:
        case MMI_UM_UI_ACTION_MS_MOV2ARC_THRD_MSG:
        {
            str_id = STR_GLOBAL_CANCELLING;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_success_evt_by_op
 * DESCRIPTION
 *  Get the success string id by operation
 *
 * PARAMETERS
 *  action:         [IN]    Operation
 *
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_um_ui_ut_get_success_evt_by_op(mmi_um_ui_req_srv_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = 0;
    
    switch (action)
    {
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_DELETE:
        case MMI_UM_UI_ACTION_DELETE_FOLDER:
        case MMI_UM_UI_ACTION_DELETE_THRD_MSG:
        case MMI_UM_UI_ACTION_MS_DELETE_THRD_MSG:
        {
            evt = MMI_EVENT_EXPLICITLY_DELETED;
            break;
        }
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_ARCHIVE:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_SIM:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_MOVE_TO_PHONE:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_SIM:
        case MMI_UM_UI_ACTION_MARK_SEVERAL_OP_COPY_TO_PHONE:
        case MMI_UM_UI_ACTION_MOV2ARC_THRD_MSG:
        case MMI_UM_UI_ACTION_MS_MOV2ARC_THRD_MSG:
        {
            evt = MMI_EVENT_SUCCESS;
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return evt;
}


#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_nmgr_type_by_msg_type
 * DESCRIPTION
 *  Get the nmgr type by message type
 * PARAMETERS
 *  msg_type            [IN]: message type
 *
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_um_ui_ut_get_nmgr_type_by_msg_type(srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nmgr_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nmgr_type = 0;
    
    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            nmgr_type = MMI_NMGR_APP_SMS;
            break;
        }
        case SRV_UM_MSG_MMS:
        {
            nmgr_type = MMI_NMGR_APP_MMS;
            break;
        }
        case SRV_UM_MSG_WAP_PUSH:
        {
            nmgr_type = MMI_NMGR_APP_WAP_PUSH;
            break;
        }
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            nmgr_type = MMI_NMGR_APP_PROVISIOING;
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
    #ifdef __SRV_UM_UT__
        case SRV_UM_MSG_UT:
        {
            nmgr_type = MMI_NMGR_APP_NULL;
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return nmgr_type;
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_msg_num_by_msg_box
 * DESCRIPTION
 *  Get the number of message based on the message box type
 *
 * PARAMETERS
 *  msg_box             [IN]: message box type
 *  msg_num_info        [IN]: the message number information
 *
 * RETURNS
 *  Number of messages
 *****************************************************************************/
U16 mmi_um_ui_ut_get_msg_num_by_msg_box(srv_um_msg_box_enum msg_box, srv_um_get_msg_num_result *msg_num_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_num = 0;
    
    switch (msg_box)
    {
        case SRV_UM_MSG_BOX_INBOX:
        {
            msg_num = msg_num_info->inbox_msg_number;
            break;
        }
        case SRV_UM_MSG_BOX_DRAFT:
        {
            msg_num = msg_num_info->draft_msg_number;
            break;
        }
        case SRV_UM_MSG_BOX_UNSENT:
        {
            msg_num = msg_num_info->unsent_msg_number;
            break;
        }
        case SRV_UM_MSG_BOX_SENT:
        {
            msg_num = msg_num_info->sent_msg_number;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_UM_MSG_BOX_ARCHIVE:
        {
            msg_num = msg_num_info->archive_msg_number;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case SRV_UM_MSG_BOX_SIM:
        {
            msg_num = msg_num_info->sim_msg_number;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    #ifdef __MMI_UM_REPORT_BOX__
        case SRV_UM_MSG_BOX_REPORT:
        {
            msg_num = msg_num_info->report_msg_number;
            break;
        }
    #endif /* __MMI_UM_REPORT_BOX__ */
        case SRV_UM_MSG_BOX_ALL:
        {
            msg_num = msg_num_info->inbox_msg_number
                      + msg_num_info->draft_msg_number
                      + msg_num_info->unsent_msg_number
                      + msg_num_info->sent_msg_number
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                      + msg_num_info->archive_msg_number
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                      + msg_num_info->sim_msg_number
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        #ifdef __MMI_UM_REPORT_BOX__
                      + msg_num_info->report_msg_number
        #endif /* __MMI_UM_REPORT_BOX__ */
                      ;
            break;
        }
        default:
        {
            msg_num = 0;
            break;
        }        
    }

    return msg_num;
}


#ifdef __MMI_UM_DELETE_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_delete_folder_str_id_by_msg_box
 * DESCRIPTION
 *  Get the number of message based on message box type
 *
 * PARAMETERS
 *  msg_box             [IN]: message box type
 *
 * RETURNS
 *  String id of menu id
 *****************************************************************************/
U16 mmi_um_ui_ut_get_delete_folder_str_id_by_msg_box(srv_um_msg_box_enum msg_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string_id = 0;
#if 1
    switch (msg_box)
    {
        case SRV_UM_MSG_BOX_INBOX:
        {
            string_id = STR_UM_DELETE_FOLDER_INBOX_ID;
            break;
        }
        case SRV_UM_MSG_BOX_DRAFT:
        {
            string_id = STR_UM_DELETE_FOLDER_DRAFT_ID;
            break;
        }
        case SRV_UM_MSG_BOX_UNSENT:
        {
            string_id = STR_UM_DELETE_FOLDER_UNSENT_ID;
            break;
        }
        case SRV_UM_MSG_BOX_SENT:
        {
            string_id = STR_UM_DELETE_FOLDER_SENT_ID;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_UM_MSG_BOX_ARCHIVE:
        {
            string_id = STR_UM_DELETE_FOLDER_ARCHIVE_ID;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case SRV_UM_MSG_BOX_SIM:
        {
            string_id = STR_UM_DELETE_FOLDER_SIM_ID;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    #ifdef __MMI_UM_REPORT_BOX__
        case SRV_UM_MSG_BOX_REPORT:
        {
            string_id = STR_UM_DELETE_FOLDER_REPORT_ID;
            break;
        }
    #endif /* __MMI_UM_REPORT_BOX__ */
        case SRV_UM_MSG_BOX_ALL:
        {
            string_id = STR_UM_DELETE_FOLDER_ALL_ID;
            break;
        }
        default:
        {
            break;
        }        
    }
#endif
    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_box_type_by_delete_menu_id
 * DESCRIPTION
 *  Get the box type based on the delete menu id.
 *
 * PARAMETERS
 *  menu_id             [IN]: delete folder menu id
 *
 * RETURNS
 *  String id of menu id
 *****************************************************************************/
srv_um_msg_box_enum mmi_um_ui_ut_get_box_type_by_delete_menu_id(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_box_enum msg_box;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_box = SRV_UM_MSG_BOX_NONE;
    switch (menu_id)
    {
        case MENU_ID_UM_DELETE_FOLDER_INBOX:
        {
            msg_box = SRV_UM_MSG_BOX_INBOX;
            break;
        }
        case MENU_ID_UM_DELETE_FOLDER_DRAFT:
        {
            msg_box = SRV_UM_MSG_BOX_DRAFT;
            break;
        }
        case MENU_ID_UM_DELETE_FOLDER_UNSENT:
        {
            msg_box = SRV_UM_MSG_BOX_UNSENT;
            break;
        }
        case MENU_ID_UM_DELETE_FOLDER_SENT:
        {
            msg_box = SRV_UM_MSG_BOX_SENT;
            break;
        }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MENU_ID_UM_DELETE_FOLDER_ARCHIVE:
        {
            msg_box = SRV_UM_MSG_BOX_ARCHIVE;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MENU_ID_UM_DELETE_FOLDER_SIM:
        {
            msg_box = SRV_UM_MSG_BOX_SIM;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    #ifdef __MMI_UM_REPORT_BOX__
        case MENU_ID_UM_DELETE_FOLDER_REPORT:
        {
            msg_box = SRV_UM_MSG_BOX_REPORT;
            break;
        }
    #endif /* __MMI_UM_REPORT_BOX__ */
        case MENU_ID_UM_DELETE_FOLDER_ALL:
        {
            msg_box = SRV_UM_MSG_BOX_ALL;
            break;
        }
        default:
        {
            break;
        }        
    }

    return msg_box;
}
#endif /* __MMI_UM_DELETE_FOLDER_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_check_all_msg_pending_action
 * DESCRIPTION
 *  Check all support message pending aciton. If there is pending action, it
 *  will popup a notification to end user.
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_TRUE:   Have pending action
 *  MMI_FALSE:  No pending action
 *****************************************************************************/
MMI_BOOL mmi_um_ui_ut_check_all_msg_pending_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    srv_um_msg_enum msg_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_type = SRV_UM_MSG_SMS;
    for (i = 0; i < SRV_UM_MAX_SUPPORT_MSG_TYPE ; i++, msg_type <<= 1)
    {
        if ((msg_type & g_um_ui_p->setting.support_msg_type) == msg_type)
        {
            if (mmi_um_ui_adp_check_pending_action(msg_type))
            {
                mmi_popup_display_simple(
                        (WCHAR *)get_string(mmi_um_ui_ut_get_pending_action_error_str_id(msg_type)), 
                        MMI_EVENT_FAILURE, 
                        GRP_ID_ROOT, 
                        NULL);
                return MMI_TRUE;
            }
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_pending_action_error_str_id
 * DESCRIPTION
 *  Get the error string of pending action by message type
 *
 * PARAMETERS
 *  msg_type:       [IN]    Message type
 *
 * RETURNS
 *  Error string id
 *****************************************************************************/
U16 mmi_um_ui_ut_get_pending_action_error_str_id(srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = 0;
    
    switch (msg_type)
    {
        case SRV_UM_MSG_WAP_PUSH:
        {
        #ifdef __MMI_BROWSER_2__
            str_id = mmi_brw_get_error_string_id();
        #else
            str_id = STR_GLOBAL_NOT_AVAILABLE;
        #endif /* __MMI_BROWSER_2__ */
            break;
        }
        default:
        {
            str_id = STR_GLOBAL_NOT_AVAILABLE;
            break;
        }
    }

    return str_id;
}


#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_str_id_by_list_idx_type
 * DESCRIPTION
 *  Get the string id by list index type and box type
 *
 * PARAMETERS
 *  idx_type:       [IN]    Message type
 *  box:            [IN]    Box type
 *
 * RETURNS
 *  String id
 *****************************************************************************/
U16 mmi_um_ui_ut_get_str_id_by_list_idx_type(srv_um_list_idx_enum idx_type, srv_um_msg_box_enum box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string_id = 0;
    switch (idx_type)
    {
        case SRV_UM_LIST_IDX_TIMESTAMP:
        {
            string_id = STR_GLOBAL_DATE;
            break;
        }
        case SRV_UM_LIST_IDX_ADDRESS:
        {
            if (box == SRV_UM_MSG_BOX_DRAFT ||
                box == SRV_UM_MSG_BOX_SENT ||
                box == SRV_UM_MSG_BOX_UNSENT)
            {
                string_id = STR_UM_SORT_BY_RECIPIENT_NAME;
            }
            else if (box == SRV_UM_MSG_BOX_INBOX)
            {
                string_id = STR_UM_SORT_BY_SENDER_NAME;
            }
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            else if (box == SRV_UM_MSG_BOX_SIM)
            {
                string_id = STR_UM_SORT_BY_SENDER_RECIPIENT_NAME;
            }
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            else if (box == SRV_UM_MSG_BOX_ARCHIVE)
            {
                string_id = STR_UM_SORT_BY_SENDER_RECIPIENT_NAME;
            }
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        #ifdef __MMI_UM_CONVERSATION_BOX__
            else if (box == SRV_UM_MSG_BOX_CONVERSATION)
            {
                string_id = STR_UM_SORT_BY_SENDER_RECIPIENT_NAME;
            }
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
            break;
        }
        case SRV_UM_LIST_IDX_SUBJECT:
        {
            string_id = STR_GLOBAL_SUBJECT;
            break;
        }
        case SRV_UM_LIST_IDX_READ_STATUS:
        {
            string_id = STR_UM_SORT_BY_READ_STATUS;
            break;
        }
        case SRV_UM_LIST_IDX_MSG_TYPE:
        {
            string_id = STR_UM_SORT_BY_MSG_TYPE;
            break;
        }
        case SRV_UM_LIST_IDX_MSG_SIZE:
        {
            string_id = STR_UM_SORT_BY_MSG_SIZE;
            break;
        }
        default:
        {
            break;
        }

    }

    return string_id;
}
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_create_scrn_id
 * DESCRIPTION
 *  Create a specified screen identity to recgonize the different of screen
 *  screen context
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  Unique screen id
 *****************************************************************************/
U16 mmi_um_ui_ut_create_scrn_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_ui_p->setting.scrn_id_counter++;

    if (0 == g_um_ui_p->setting.scrn_id_counter)
    {
        g_um_ui_p->setting.scrn_id_counter = 1;
    }
    return g_um_ui_p->setting.scrn_id_counter;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_msg_info_buf
 * DESCRIPTION
 *  Get the message detail information buffer
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  The buffer of message detail information
 *****************************************************************************/
srv_um_msg_info_struct **mmi_um_ui_ut_get_msg_info_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_um_ui_msg_info_buf_p, 0, sizeof(g_um_ui_msg_info_buf_p));

    return g_um_ui_msg_info_buf_p;
}


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_msg_info_buf
 * DESCRIPTION
 *  Get the message detail information buffer
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  The buffer of message detail information
 *****************************************************************************/
srv_um_thread_info_struct **mmi_um_ui_ut_get_thread_info_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_um_ui_thread_info_buf_p, 0, sizeof(g_um_ui_thread_info_buf_p));

    return g_um_ui_thread_info_buf_p;
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_concate_str_with_msg
 * DESCRIPTION
 *  Concate the string with input string and STR_UM_MSG_ID. Store in the 
 *  output string
 *
 * PARAMETERS
 *  input_str_asc:          [IN]    The input ascii string
 *  output_str_ucs2:        [OUT]   The output ucs2 string
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_ut_concate_str_with_msg(S8 *input_str_asc, S8 *output_str_ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 input_str_ucs2[MAX_SUB_MENU_HINT_SIZE * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8 *)input_str_ucs2, (S8 *)input_str_asc);
    mmi_ucs2ncpy((S8 *)output_str_ucs2, (S8 *)input_str_ucs2, MMI_UM_UI_MAX_GET_STRING_LEN);
    mmi_ucs2cat((S8 *)output_str_ucs2, (S8 *)get_string((MMI_ID_TYPE)STR_UM_MSG_ID));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_concate_str_with_msgs
 * DESCRIPTION
 *  Concate the string with input string and STR_UM_MSGS_ID. Store in the 
 *  output string
 *
 * PARAMETERS
 *  input_str_asc:          [IN]    The input ascii string
 *  output_str_ucs2:        [OUT]   The output ucs2 string
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_ut_concate_str_with_msgs(S8 *input_str_asc, S8 *output_str_ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 input_str_ucs2[MAX_SUB_MENU_HINT_SIZE * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8 *)input_str_ucs2, (S8 *)input_str_asc);
    mmi_ucs2ncpy((S8 *)output_str_ucs2, (S8 *)input_str_ucs2, MMI_UM_UI_MAX_GET_STRING_LEN);
    mmi_ucs2cat((S8 *)output_str_ucs2, (S8 *)get_string((MMI_ID_TYPE)STR_UM_MSGS_ID));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_concate_str_with_num
 * DESCRIPTION
 *  Concate the string with input string and output string.
 *
 * PARAMETERS
 *  input_str_asc:          [IN]    The input ascii string
 *  output_str_ucs2:        [OUT]   The output ucs2 string
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_ut_concate_str_with_num(S8 *input_str_asc, S8 *output_str_ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 input_str_ucs2[MAX_SUB_MENU_HINT_SIZE * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8 *)input_str_ucs2, (S8 *)input_str_asc);
    mmi_ucs2ncat((S8 *)output_str_ucs2, (S8 *)input_str_ucs2, MMI_UM_UI_MAX_GET_STRING_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_del_relative_scrn
 * DESCRIPTION
 *  Delete the relative screen. It needs to check the screen id if larger than
 *  0 and set the scrn_id = 0;
 *
 * PARAMETERS
 *  scrn_id:            [OUT]   input/output screen id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_ut_del_relative_scrn(U16 *scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tmp_scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp_scrn_id = *scrn_id;
    *scrn_id = 0;
    if (tmp_scrn_id > 0)
    {
        mmi_um_ui_cc_send_event(tmp_scrn_id, MMI_UM_UI_EVENT_DELETE, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_notify_scrn_deleted
 * DESCRIPTION
 *  Notify the screen id that its child has been deleted.
 *
 * PARAMETERS
 *  scrn_id:            [IN]    Notified screen id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_ut_notify_scrn_deleted(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrn_id > 0)
    {
        mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_DELETED, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_send_init_event
 * DESCRIPTION
 *  Send a init event to the screen id. It needs to check the screen id if 
 *  larger than 0.
 *
 * PARAMETERS
 *  scrn_id:            [IN]    Sent screen id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_ut_send_init_event(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrn_id > 0)
    {
        mmi_um_ui_cc_send_event(scrn_id, MMI_UM_UI_EVENT_INIT, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_disp_scrn_id_by_scrn_id
 * DESCRIPTION
 *  Get the displayed screen id(framework-based).
 * PARAMETERS
 *  scrn_id:            [IN]    Screen id
 *
 * RETURNS
 *  Displayed screen id
 *****************************************************************************/
U16 mmi_um_ui_ut_get_disp_scrn_id_by_scrn_id(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrn_id == 0)
    {
        MMI_ASSERT(0);
    }

    scrn_cntx = mmi_um_ui_cc_get_scrn_cntx(scrn_id);
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

    return scrn_cntx->screen_hdlr.disp_scrn_id;
}


#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_tb_folder_by_msg_box_type
 * DESCRIPTION
 *  Get the toolbar folder enum value by message box enum value
 * PARAMETERS
 *  box_type            [IN]: Message box type
 *
 * RETURNS
 *  Toolbar folder enum value
 *****************************************************************************/
mmi_um_ui_tb_action_folder_enum mmi_um_ui_ut_get_tb_folder_by_msg_box_type(srv_um_msg_box_enum box_type, mmi_um_ui_folder_mode_enum folder_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_ui_tb_action_folder_enum tb_folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb_folder = MMI_UM_UI_TB_FOLDER_TOTAL;

    if (MMI_UM_FOLDER_MODE_DEFAULT == folder_mode)
    {
        switch (box_type)
        {
            case SRV_UM_MSG_BOX_INBOX:
            {
                tb_folder = MMI_UM_UI_TB_FOLDER_INBOX;
                break;
            }
            case SRV_UM_MSG_BOX_DRAFT:
            {
                tb_folder = MMI_UM_UI_TB_FOLDER_DRAFT;
                break;
            }
            case SRV_UM_MSG_BOX_UNSENT:
            {
                tb_folder = MMI_UM_UI_TB_FOLDER_UNSENT;
                break;
            }
            case SRV_UM_MSG_BOX_SENT:
            {
                tb_folder = MMI_UM_UI_TB_FOLDER_SENT;
                break;
            }
            case SRV_UM_MSG_BOX_ARCHIVE:
            {
                tb_folder = MMI_UM_UI_TB_FOLDER_ARCHIVE;
                break;
            }
            case SRV_UM_MSG_BOX_SIM:
            {
                tb_folder = MMI_UM_UI_TB_FOLDER_SIM;
                break;
            }
        #ifdef __MMI_UM_REPORT_BOX__
            case SRV_UM_MSG_BOX_REPORT:
            {
                tb_folder = MMI_UM_UI_TB_FOLDER_REPORT;
                break;
            }
        #endif /* __MMI_UM_REPORT_BOX__ */
            default:
            {
                MMI_ASSERT(0);
                break;
            }
        }
    }
    else if (MMI_UM_FOLDER_MODE_CONVERSATION_BOX == folder_mode)
    {
        tb_folder = MMI_UM_UI_TB_FOLDER_CONVERSATION;
    }
    else if (MMI_UM_FOLDER_MODE_THREAD_MSG == folder_mode)
    {
        tb_folder = MMI_UM_UI_TB_FOLDER_THREAD_MSG;
    }
    else
    {
        MMI_ASSERT(0);
    }

    return tb_folder;
}
#endif /* __MMI_ICON_BAR_SUPPORT__ */


#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_menu_id_by_filter_type
 * DESCRIPTION
 *  Get the menu id by the filtering type
 * PARAMETERS
 *  filter_type:            [IN] filter type
 *
 * RETURNS
 *  Corresponding menu id
 *****************************************************************************/
 U32 mmi_um_ui_ut_get_menu_id_by_filter_type(srv_um_list_idx_enum filter_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = 0;

    switch (filter_type)
    {
        case SRV_UM_LIST_IDX_TIMESTAMP:
        {
            menu_id = MENU_ID_UM_SORT_BY_TIME;
            break;
        }
        case SRV_UM_LIST_IDX_ADDRESS:
        {
            menu_id = MENU_ID_UM_SORT_BY_RECIPIENT;
            break;
        }
        case SRV_UM_LIST_IDX_SUBJECT:
        {
            menu_id = MENU_ID_UM_SORT_BY_SUBJECT;
            break;
        }
        case SRV_UM_LIST_IDX_READ_STATUS:
        {
            menu_id = MENU_ID_UM_SORT_BY_READ_STATUS;
            break;
        }
        case SRV_UM_LIST_IDX_MSG_SIZE:
        {
            menu_id = MENU_ID_UM_SORT_BY_SIZE;
            break;
        }
        case SRV_UM_LIST_IDX_MSG_TYPE:
        {
            menu_id = MENU_ID_UM_SORT_BY_TYPE;
            break;
        }
        default:
        {
            ASSERT(0);
            break;
        }
    }

    return menu_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_filter_type_by_menu_id
 * DESCRIPTION
 *  Get the filtering type by menu id
 * PARAMETERS
 *  menu_id:                [IN] menu id
 *
 * RETURNS
 *  Corresponding filtering type
 *****************************************************************************/
srv_um_list_idx_enum mmi_um_ui_ut_get_filter_type_by_menu_id(U32 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_list_idx_enum filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter = SRV_UM_LIST_IDX_TIMESTAMP;

    switch (menu_id)
    {
        case MENU_ID_UM_SORT_BY_TIME:
        {
            filter = SRV_UM_LIST_IDX_TIMESTAMP;
            break;
        }
        case MENU_ID_UM_SORT_BY_RECIPIENT:
        {
            filter = SRV_UM_LIST_IDX_ADDRESS;
            break;
        }
        case MENU_ID_UM_SORT_BY_SUBJECT:
        {
            filter = SRV_UM_LIST_IDX_SUBJECT;
            break;
        }
        case MENU_ID_UM_SORT_BY_READ_STATUS:
        {
            filter = SRV_UM_LIST_IDX_READ_STATUS;
            break;
        }
        case MENU_ID_UM_SORT_BY_SIZE:
        {
            filter = SRV_UM_LIST_IDX_MSG_SIZE;
            break;
        }
        case MENU_ID_UM_SORT_BY_TYPE:
        {
            filter = SRV_UM_LIST_IDX_MSG_TYPE;
            break;
        }
        default:
        {
            ASSERT(0);
            break;
        }
    }

    return filter;
}
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */


#if defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_get_sim_id_by_menu_id
 * DESCRIPTION
 *  Get the sim type by menu id
 * PARAMETERS
 *  menu_id:                [IN] menu id
 *
 * RETURNS
 *  Corresponding sim type
 *****************************************************************************/
srv_um_sim_enum mmi_um_ui_ut_get_sim_id_by_menu_id(MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = SRV_UM_SIM_ALL;

    switch (menu_id)
    {
        case MENU_ID_UM_FILTER_BY_OPT_SIM1:
        {
            sim_id = SRV_UM_SIM_GSM_SIM1;
            break;
        }
        case MENU_ID_UM_FILTER_BY_OPT_SIM2:
        {
            sim_id = SRV_UM_SIM_GSM_SIM2;
            break;
        }
        #if (MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_UM_FILTER_BY_OPT_SIM3:
        {
            sim_id = SRV_UM_SIM_GSM_SIM3;
            break;
        }
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
        case MENU_ID_UM_FILTER_BY_OPT_SIM4:
        {
             sim_id = SRV_UM_SIM_GSM_SIM4;
             break;
        }
        #endif
        case MENU_ID_UM_FILTER_BY_OPT_ALL:
        {
            sim_id = SRV_UM_SIM_ALL;
            break;
        }
        default:
        {
            ASSERT(0);
            break;
        }
    }

    return sim_id;
}
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_update_item_by_menu_id
 * DESCRIPTION
 *  Update the string by menu id
 *      Draft (21)
 *      Outbox (1)
 *
 * PARAMETERS
 *  parent_menu_id          [IN]: Parent menu id
 *  menu_id                 [IN]: Menu id
 *  item_string             [OUT]: Buffer for items string
 *  msg_num_info            [IN]: Message number information
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_ut_update_item_by_menu_id(U16 parent_menu_id, U16 menu_id, U8 **item_string, U16 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U8 hint_asc[MAX_SUB_MENU_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_test_menu_item_hide(menu_id))
    {
        i = GetIndexOfStringId_Ext(parent_menu_id, menu_id);
        sprintf((S8 *)hint_asc, " (%d)", number);
        mmi_um_ui_ut_concate_str_with_num((S8 *)hint_asc, (S8 *)item_string[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_update_item_hint_by_menu_id
 * DESCRIPTION
 *  Update the string by single menu id
 *      Inbox
 *          10 messages
 *      Draft
 *          21 messages
 *      Outbox
 *          1 message
 *
 * PARAMETERS
 *  parent_menu_id          [IN]: Parent menu id
 *  menu_id                 [IN]: Menu id
 *  item_hint               [OUT]: Buffer for items hint string
 *  msg_num_info            [IN]: Message number information
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_ut_update_item_hint_by_menu_id(U16 parent_menu_id, U16 menu_id, U8 **item_hint, U16 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U8 hint_asc[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_test_menu_item_hide(menu_id))
    {
        i = GetIndexOfStringId_Ext(parent_menu_id, menu_id);
        sprintf((S8 *)hint_asc, "%d ", number);
        if (number > 1)
        {
            mmi_um_ui_ut_concate_str_with_msgs((S8 *)hint_asc, (S8 *)item_hint[i]);
        }
        else
        {
            mmi_um_ui_ut_concate_str_with_msg((S8 *)hint_asc, (S8 *)item_hint[i]);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_ut_check_all_msg_reentry
 * DESCRIPTION
 *  Check all support message reentry status. If there is msg ap says no, it
 *  will popup a notification to end user.
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_TRUE:   Could entry
 *  MMI_FALSE:  It could not reentry
 *****************************************************************************/
MMI_BOOL mmi_um_ui_ut_check_all_msg_reentry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    srv_um_msg_enum msg_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_type = SRV_UM_MSG_SMS;
    for (i = 0; i < SRV_UM_MAX_SUPPORT_MSG_TYPE ; i++, msg_type <<= 1)
    {
        if ((msg_type & g_um_ui_p->setting.support_msg_type) == msg_type)
        {
            if (MMI_FALSE == mmi_um_ui_adp_check_reentry(msg_type))
            {
                return MMI_FALSE;
            }
        }
    }

    return MMI_TRUE;
}
#endif /* __UM_SUPPORT__ */
