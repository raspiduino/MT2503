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
 * comm_post_event.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for post Events.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef COMM_POST_EVENT_H
#define COMM_POST_EVENT_H

#include "Bcmadp.h"

/***************************************************************************** 
* Define
*****************************************************************************/


/* Post event type recorded in link list node */
#define POST_EVT  1

//error code
#define RET_ERR_INVOKE_POST_EVT -1
#define RET_ERR_SEND_EVT -2
#define RET_ERR_NO_POST_EVENT  -3
#define RET_ERR_UNKNOWN_EVT_FLAG -4

//post event max num
#define POST_EVENT_MAX_NUM  5
//post event ADM pool
#define POST_EVENT_ADM_POOL_SIZE    (sizeof(mmi_post_evt_node_struct) + sizeof(mmi_post_event_proc_struct)+\
											+ sizeof(mmi_event_struct) + 64) * POST_EVENT_MAX_NUM									

		 
/***************************************************************************** 
* Typedef 
*****************************************************************************/


typedef struct
{
    mmi_event_struct *evt_p;
    mmi_proc_func proc;
} mmi_post_event_proc_struct;

typedef struct _mmi_post_evt_node_struct
{
	kal_uint8 flag;
	void *evt_p;
	struct _mmi_post_evt_node_struct *next;
} mmi_post_evt_node_struct;


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *	comm_init_event
 * DESCRIPTION
 *	Initialize event structure.
 * PARAMETERS
 *	_evt :			   [IN]    event structure pointer;
 *	_evt_id :		   [IN]    event id;
 * RETURNS
 *	void
 *****************************************************************************/
extern void comm_init_event(mmi_event_struct *evt, kal_uint16 evt_id, kal_uint16 size);
	
#define MMI_FRM_INIT_EVENT(_evt, _evt_id)\
		 comm_init_event((mmi_event_struct *)_evt, _evt_id, sizeof(*(_evt)))
#define mmi_frm_init_event comm_init_event
		 
		 

/*****************************************************************************
 * FUNCTION
 *  comm_send_event
 * DESCRIPTION
 *  Send directly event to designated proc with user data.
 * PARAMETERS
 *  evt :              [IN]   event structure pointer;
 *  proc :             [IN]   process handler;
 *  user_data :        [IN]   user data pointer;
 * RETURN VALUES
 *  MMI_RET_OK: Emit the event to the specific proc function without return value from the receiver.
 *  Others: Emit the event to the specific proc function and carry the return value from the receiver.
 *****************************************************************************/
extern kal_uint32 comm_send_event(mmi_event_struct *evt, mmi_proc_func proc, void *user_data);

#define MMI_FRM_SEND_EVENT(_evt, _proc, _user_data)\
        comm_send_event((mmi_event_struct *)(_evt), (mmi_proc_func)(_proc), (void *)(_user_data))
#define mmi_frm_send_event comm_send_event

/*****************************************************************************
 * FUNCTION
 *  comm_post_event
 * DESCRIPTION
 *  Send post event to designated proc with user data, it will be invoked after current
 *  function flow and before next input event like key, pen, timer, primitive.
 * PARAMETERS
 *  evt :              [IN]   event structure pointer;
 *  proc :             [IN]   process handler;
 *  user_data :        [IN]   user data pointer;
 * RETURNS
 *  void
 *****************************************************************************/
extern void comm_post_event(mmi_event_struct *evt, mmi_proc_func proc, void *user_data);

#define MMI_FRM_POST_EVENT(_evt, _proc, _user_data)\
        comm_post_event((mmi_event_struct *)(_evt), (mmi_proc_func)(_proc), (void *)(_user_data))
#define mmi_frm_post_event comm_post_event


extern kal_int32 comm_invoke_post_event(void);
extern void comm_post_event_create_adm(void);


/*post event ut*/

//#define __POST_EVENT_DEBUG__

#ifdef __POST_EVENT_DEBUG__
#define POST_EVT_TRACE(...) kal_prompt_trace(MOD_BCM, __VA_ARGS__)

extern void comm_post_event_enqueue_ut(void);
extern void comm_post_event_dequeue_ut(void);
extern void comm_post_event_ut(void);

#endif



#endif /* COMM_POST_EVENT_H */ 




