/****************************************************************************
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
 *    video_renderer_task_thread_pool.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    The moudle is a common interface for video renderer to send messages to
 *    thread pool and request sw execution on target task. Multiple execution 
 *    request simultaneously is allowed since the module is designed base on 
 *    message queue, the latter request will be queued after early one, but the 
 *    user must handle the sequence itself.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 06 2011 chelun.tsai
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VIDEO_RENDERER_TASK_THREAD_POOL_H__
#define __VIDEO_RENDERER_TASK_THREAD_POOL_H__

/****************************************************************************
 * macro definitions
 ****************************************************************************/

/****************************************************************************
 * Include directives
 ****************************************************************************/
#include "kal_general_types.h"
#include "app_ltlcom.h"          /* Task message communiction */

/****************************************************************************
 * type definitions
 ****************************************************************************/
typedef void (*video_renderer_task_exec_func_t)(void *);

/****************************************************************************
 * external symbol prototypes and declarations
 ****************************************************************************/

/* function to send request message to task. Caller can be HSIR or TASK, but can not be LISR.
 * ret : KAL_TRUE for success and KAL_FALSE for fail.
 * exec_task_name : a string specify the the target task. Only support "MOD_CAL" now.
 * exec_func : the user function for execution. User should pay attention to stack size since it will be 
 *             called from target task.
 * exec_param : the user param for user exection function.
 * exec_param_size : user param size.
 */
kal_bool video_renderer_task_req_msg(
  void * exec_task_name,
  video_renderer_task_exec_func_t exec_func,
  void * exec_param,
  kal_uint32 exec_param_size);

/*
 * function for target task to execution, user who submit reuqest should not call this.
 * ilm_msg : lim message
 */
void video_renderer_task_req_hdlr(ilm_struct *ilm_msg);

#endif // __VIDEO_RENDERER_TASK_THREAD_POOL_H__


