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
* comm_post_event.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is intends for post event handler .
*
* Author:
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "Device.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "string.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stdio.h"
#include "comm_post_event.h"
#include "bcm_trc.h"
#include "Bcm_btcmUtility.h"


/*****************************************************************************
 * Global Variable                                                             
 *****************************************************************************/

/* static event table info, e.g. table pointer, num. of table items */

/* Post event link list */
static mmi_post_evt_node_struct *post_evt_header = NULL;
static kal_uint8 post_evt_num = 0;

//ADM
KAL_ADM_ID post_evt_adm_pool_id = NULL;
static kal_uint8 post_evt_adm_pool[POST_EVENT_ADM_POOL_SIZE];  


/*****************************************************************************
 * Extern data and function                                                             
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  comm_post_event_create_adm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS VALUES
 *  void
 *****************************************************************************/
void comm_post_event_create_adm(void)
{

	/*----------------------------------------------------------------*/
    /* Local Variables												 */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
	//Create ADM
	if (post_evt_adm_pool != NULL && post_evt_adm_pool_id == 0)
	{
		post_evt_adm_pool_id = kal_adm_create((void*)post_evt_adm_pool,
                                                    POST_EVENT_ADM_POOL_SIZE,
                                                    NULL,
                                                    KAL_FALSE);
	}
    ASSERT(post_evt_adm_pool_id != NULL);
}

/*****************************************************************************
 * FUNCTION
 *  comm_post_event_delete_adm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS VALUES
 *  void
 *****************************************************************************/
void comm_post_event_delete_adm(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Delete ADM */
    if (post_evt_adm_pool_id != NULL)
    {
        ret = kal_adm_delete(post_evt_adm_pool_id);

        ASSERT(ret == KAL_SUCCESS);
        post_evt_adm_pool_id = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  comm_post_event_adm_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_size		[IN]
 *  RETURNS VALUES
 *  void*
 *****************************************************************************/
void *comm_post_event_adm_alloc(U32 mem_size)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = kal_adm_alloc(post_evt_adm_pool_id, (kal_uint32)mem_size);

	if (!ptr)
	{
		ASSERT(ptr);
	}
	return ptr;
}

/*****************************************************************************
 * FUNCTION
 *  comm_post_event_adm_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr		[IN]
 *  RETURNS VALUES
 *  void
 *****************************************************************************/
void comm_post_event_adm_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (post_evt_adm_pool_id && (ptr != NULL))
    {
        kal_adm_free(post_evt_adm_pool_id, ptr);
		ptr = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  enqueue_post_evt
 * DESCRIPTION
 *  Enqueue event into post event queue.
 * PARAMETERS
 *  evt_p             [IN]  event structure pointer;
 *  evt_flag          [IN]  post event type;
 *  RETURNS VALUES
 *  void
 *****************************************************************************/
void enqueue_post_evt(void *evt_p, kal_uint8 evt_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_node_struct *position, *tmp_cell;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != evt_p);
	if (NULL == evt_p)
		return;
	
    if (!post_evt_header)
    {
        post_evt_header = comm_post_event_adm_alloc(sizeof(mmi_post_evt_node_struct));
		if (post_evt_header)
        	memset(post_evt_header, 0, sizeof(mmi_post_evt_node_struct));
    }
    for (position = post_evt_header; position->next != NULL; position = position->next);
    /* position should point to previous cell */
        
    tmp_cell = comm_post_event_adm_alloc(sizeof(mmi_post_evt_node_struct));
	if (NULL != tmp_cell)
	{
    	tmp_cell->flag = evt_flag;
	    tmp_cell->evt_p = evt_p;
	    tmp_cell->next = position->next;    /* NULL */
	    position->next = tmp_cell;
	    post_evt_num++;
	    POST_EVT_TRC(TRC_ENQ_POST_EVT, evt_p, evt_flag, post_evt_num);
	}
	else if (NULL == tmp_cell)
	{
		comm_post_event_adm_free(((mmi_post_event_proc_struct*)evt_p)->evt_p);
		comm_post_event_adm_free(evt_p);
	}
}


/*****************************************************************************
 * FUNCTION
 *  dequeue_post_evt
 * DESCRIPTION
 *  Dequeue post event with designated event type.
 * PARAMETERS
 *  evt_flag             [IN]  post event type;
 * RETURNS
 *  void *
 *****************************************************************************/
void *dequeue_post_evt(kal_uint8 *evt_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_node_struct *position;
    void *evt_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!post_evt_header)
    {
      	POST_EVT_TRC(TRC_DEQ_POST_EVT_NULL);
        return NULL;
	}
    position = post_evt_header->next;
    if (!position)
    {
     	POST_EVT_TRC(TRC_DEQ_POST_EVT_EMPTY);
        return NULL;
    }
    post_evt_header->next = position->next;
    evt_p = position->evt_p;
    *evt_flag = position->flag;
    comm_post_event_adm_free(position);
    ASSERT(NULL != evt_p);

    if (!post_evt_header->next)
    {
        comm_post_event_adm_free(post_evt_header);
		post_evt_header = NULL;
    }
    post_evt_num--;
    POST_EVT_TRC(TRC_DEQ_POST_EVT, evt_p, ((mmi_post_event_proc_struct *)evt_p)->evt_p->evt_id, *evt_flag, post_evt_num);

    return evt_p;
}


/*****************************************************************************
 * FUNCTION
 *  comm_init_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt		[IN]
 *  evt_id		[IN]
 *  size		[IN]
 *  RETURNS VALUES
 *  void
 *****************************************************************************/
void comm_init_event(mmi_event_struct *evt, kal_uint16 evt_id, kal_uint16 size)
{
	if (NULL == evt)
	{
		return;
	}
    memset(evt, 0, size);
    evt->evt_id = evt_id;
    evt->size = size;
}


/*****************************************************************************
 * FUNCTION
 *  comm_send_event
 * DESCRIPTION
 *  Send directly event to designated proc with user data.
 * PARAMETERS
 *  evt              [IN]
 *  proc             [IN]
 *  user_data        [IN]
 * RETURN VALUES
 *  MMI_RET_OK: Emit the event to the specific proc function without return value from the receiver.
 *  Others: Emit the event to the specific proc function and carry the return value from the receiver.
 *****************************************************************************/
kal_uint32 comm_send_event(mmi_event_struct *evt, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (NULL == evt || NULL == proc)
		return RET_ERR_SEND_EVT;
	
    evt->user_data = user_data;

    return proc(evt);
}



/*****************************************************************************
 * FUNCTION
 *  comm_post_event
 * DESCRIPTION
 *  Send post event to designated proc with user data, it will be invoked after current  function flow .
 * PARAMETERS
 *  evt              [IN]   event structure pointer;
 *  proc             [IN]   process handler
 *  user_data        [IN]   user data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void comm_post_event(mmi_event_struct *evt, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_event_proc_struct *post_evt_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(evt != NULL && proc != NULL);
	if (NULL == evt || NULL == proc)
		return;
	
    POST_EVT_TRC(TRC_POST_EVT, evt, evt->evt_id, evt->size, proc, user_data);
    /* Copy event struct and push into post evt queue */
    post_evt_p = comm_post_event_adm_alloc(sizeof(mmi_post_event_proc_struct));
	if (NULL == post_evt_p)
		return;
    post_evt_p->evt_p = comm_post_event_adm_alloc(evt->size);
	if (NULL == post_evt_p->evt_p)
		return;
    memcpy(post_evt_p->evt_p, evt, evt->size);
    post_evt_p->proc = proc;
    post_evt_p->evt_p->user_data = user_data;
	
    enqueue_post_evt((void *)post_evt_p, POST_EVT);
}

/*****************************************************************************
 * FUNCTION
 *  comm_invoke_post_event
 * DESCRIPTION
 *  Emit post events, the callback of this events will be invoked after current 
 *  function flow.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_RET_ERR_NO_POST_EVENT if there is no post event,
 *  Return MMI_RET_ERR_UNKNOWN_EVT_FLAG if can't find event flag,
 *  otherwise return result of callback function;
 *****************************************************************************/
kal_int32 comm_invoke_post_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *evt_p;
    kal_uint8 evt_flag;
    kal_int32 result = RET_ERR_INVOKE_POST_EVT;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (post_evt_num == 0)
    {
        POST_EVT_TRC(TRC_INVOKE_POST_EVT_NULL);
        result = RET_ERR_NO_POST_EVENT;
    }
    else
    {
        POST_EVT_TRC(TRC_INVOKE_POST_EVT_BEGIN, post_evt_num);
    }

    
    do
    {
        while (NULL != (evt_p = dequeue_post_evt(&evt_flag)))
        {
            ASSERT(NULL != evt_p);
         
            if (evt_flag == POST_EVT)
            {
                mmi_post_event_proc_struct *post_evt_p = (mmi_post_event_proc_struct *)evt_p;

                result = post_evt_p->proc(post_evt_p->evt_p);
            
                comm_post_event_adm_free(post_evt_p->evt_p);
                comm_post_event_adm_free(post_evt_p);
            }
            else
            {
                ASSERT(0);
                result = RET_ERR_UNKNOWN_EVT_FLAG;
            }
        }
    }while (post_evt_num);
    
    ASSERT(post_evt_num == 0);
    POST_EVT_TRC(TRC_INVOKE_POST_EVT_END, post_evt_num);

    return result;
}


/*BCM UT function*/
#ifdef __POST_EVENT_DEBUG__

static kal_uint32 comm_post_event_ut_proc1(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	POST_EVT_TRACE("[POST_EVT]comm_post_event_ut_proc1<evt = 0x%x, evt_id = %d, user_data = 0x%x>", evt, evt->evt_id, evt->user_data);
	return 0;
}
static kal_uint32 comm_post_event_ut_proc2(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	POST_EVT_TRACE("[POST_EVT]comm_post_event_ut_proc2<evt = 0x%x, evt_id = %d, user_data = 0x%x>", evt, evt->evt_id, evt->user_data);
	return 0;
}
static kal_uint32 comm_post_event_ut_proc3(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	POST_EVT_TRACE("[POST_EVT]comm_post_event_ut_proc3<evt = 0x%x, evt_id = %d, user_data = 0x%x>", evt, evt->evt_id, evt->user_data);
	return 0;
}

static kal_uint32 comm_post_event_ut_proc4(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	POST_EVT_TRACE("[POST_EVT]comm_post_event_ut_proc4<evt = 0x%x, evt_id = %d, user_data = 0x%x>", evt, evt->evt_id, evt->user_data);
	return 0;
}

static kal_uint32 comm_post_event_ut_proc5(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	POST_EVT_TRACE("[POST_EVT]comm_post_event_ut_proc5<evt = 0x%x, evt_id = %d, user_data = 0x%x>", evt, evt->evt_id, evt->user_data);
	return 0;
}


static kal_uint32 comm_send_event_ut_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	POST_EVT_TRACE("[POST_EVT]comm_send_event_ut_proc<evt = 0x%x, evt_id = %d, user_data = 0x%x>", evt, evt->evt_id, evt->user_data);
	return 0;
}

void comm_post_event_enqueue_ut(void)
{
	/*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	 int i = 0;
	 mmi_event_struct evt1;
	 mmi_event_struct evt2;
	 mmi_event_struct evt3;
	 mmi_event_struct evt4;
	 mmi_event_struct evt5;
	 
	 mmi_post_evt_node_struct * temp_cell;
	 mmi_post_event_proc_struct *evt_p;
	 
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 POST_EVT_TRACE("[POST_EVT]comm_post_event_enqueue_ut <before enqueue buf size left is %d>", kal_adm_get_total_left_size(post_evt_adm_pool_id));
	 mmi_frm_init_event(&evt1, i++ ,sizeof(evt1));
	 mmi_frm_send_event(&evt1, comm_send_event_ut_proc, NULL);
     mmi_frm_post_event(&evt1, comm_post_event_ut_proc1, NULL);
	 comm_init_event(&evt2, i++ ,sizeof(evt2));
	 comm_send_event(&evt2, comm_send_event_ut_proc, NULL);
     comm_post_event(&evt2, comm_post_event_ut_proc2, NULL);
	 MMI_FRM_INIT_EVENT(&evt3, i++);
	 MMI_FRM_SEND_EVENT(&evt3, comm_send_event_ut_proc, NULL);
     MMI_FRM_POST_EVENT(&evt3, comm_post_event_ut_proc3, NULL);
	 MMI_FRM_INIT_EVENT(&evt4, i++);
     MMI_FRM_POST_EVENT(&evt4, comm_post_event_ut_proc4, NULL);
	 MMI_FRM_INIT_EVENT(&evt5, i++);
     MMI_FRM_POST_EVENT(&evt5, comm_post_event_ut_proc5, NULL);

	 POST_EVT_TRACE("[POST_EVT]comm_post_event_enqueue_ut <after enqueue buf size left is %d>", kal_adm_get_total_left_size(post_evt_adm_pool_id));

	 if (post_evt_header != NULL)
	 {
	 	 temp_cell = post_evt_header;
		 POST_EVT_TRACE("[POST_EVT]comm_post_event_enqueue_ut <post event queue, post evt num is %d>", post_evt_num);
		 POST_EVT_TRACE("[POST_EVT]comm_post_event_enqueue_ut <post event queue header is 0x%x, flag =%d, evt_p = 0x%x, next = 0x%x>", \
		 	post_evt_header, post_evt_header->flag, post_evt_header->evt_p, post_evt_header->next);
		 
		 while (temp_cell->next != NULL)
		 {
		 	temp_cell = temp_cell->next;
		 	POST_EVT_TRACE("[POST_EVT]comm_post_event_enqueue_ut <post event queue item is 0x%x>", \
		 	temp_cell, temp_cell->flag);	
			POST_EVT_TRACE("[POST_EVT]comm_post_event_enqueue_ut <post event queue item evt_p = 0x%x, next = 0x%x>", \
		 	temp_cell->evt_p, temp_cell->next);	
			evt_p = (mmi_post_event_proc_struct*)temp_cell->evt_p;
			
			POST_EVT_TRACE("[POST_EVT]comm_post_event_enqueue_ut <post event queue evt info is evt_adr = 0x%x, evt_id =%d>", \
		 	evt_p->evt_p, evt_p->evt_p->evt_id);	
			POST_EVT_TRACE("[POST_EVT]comm_post_event_enqueue_ut <post event queue evt info evt_size = %d, user_data = 0x%x>", \
		 	evt_p->evt_p->size, evt_p->evt_p->user_data);
		 }
	 }
	 

	 
}


void comm_post_event_dequeue_ut(void)
{
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 comm_invoke_post_event();
	 comm_invoke_post_event();
	 POST_EVT_TRACE("[POST_EVT]comm_post_event_dequeue_ut <after dequeue buf size left is %d>", kal_adm_get_total_left_size(post_evt_adm_pool_id));
}

void comm_post_event_ut(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   */
    /*----------------------------------------------------------------*/
	int i = 0;
	mmi_event_struct evt1;
	mmi_event_struct evt2;
	mmi_event_struct evt3;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	POST_EVT_TRACE("[POST_EVT]comm_post_event_ut begin");
	for (i=0; i<100; i++)
	{
		MMI_FRM_INIT_EVENT(&evt1, 1); 
		MMI_FRM_POST_EVENT(&evt1, comm_post_event_ut_proc1, NULL);
		MMI_FRM_INIT_EVENT(&evt2, 2); 
		MMI_FRM_POST_EVENT(&evt2, comm_post_event_ut_proc2, NULL);
		MMI_FRM_INIT_EVENT(&evt3, 3); 
		MMI_FRM_POST_EVENT(&evt3, comm_post_event_ut_proc3, NULL);
		comm_invoke_post_event();
	}
	POST_EVT_TRACE("[POST_EVT]comm_post_event_ut end post_evt buf %d", kal_adm_get_total_left_size(post_evt_adm_pool_id));

}

#endif




