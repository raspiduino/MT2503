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
 *    Video_renderer_task_thread_pool.c
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
 * 03 15 2012 peter.wang
 * removed!
 * .
 *
 * 12 06 2011 chelun.tsai
 * removed!
 * .
 *
 * 12 06 2011 chelun.tsai
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * macro definitions
 ****************************************************************************/

/****************************************************************************
 * Include directives
 ****************************************************************************/
#include "Video_renderer_task_thread_pool.h"
#include "kal_general_types.h"
#include "app_ltlcom.h"          /* Task message communiction */

/****************************************************************************
 * type definitions
 ****************************************************************************/
typedef struct
{
  LOCAL_PARA_HDR
  video_renderer_task_exec_func_t exec_func;
  void * exec_param;
}_video_renderer_task_local_param_t;


/****************************************************************************
 * local variables
 ****************************************************************************/

/****************************************************************************
 * utilities
 ****************************************************************************/
#if (!defined(DRV_IDP_6252_SERIES))

#if defined(__MTK_TARGET__)
// move out form demand page
#pragma arm section code="SECONDARY_ROCODE"
#pragma arm section rodata="SECONDARY_RODATA"
#endif

kal_bool video_renderer_task_req_msg(
  void * exec_task_name,
  video_renderer_task_exec_func_t exec_func,
  void * exec_param,
  kal_uint32 exec_param_size)
{
#if defined(__MTK_TARGET__)
#if (defined(ISP_SUPPORT))

  _video_renderer_task_local_param_t *ilm_param;
  ilm_struct *p_ilm = NULL;
  module_type eActiveModuleId;
  kal_uint32 local_param_size;
  kal_uint32 construct_size;

  // Here, I utilize some behavior of arm compilier for struct "_video_renderer_task_local_param_t"
  // 1. For exec_param, it is a pointer, and it's size must be 4 byte
  // 2. The start address of struct must be 4 byte align
  // 3. The start address of exec_param in the struct must be 4 byte align
  // Then I will put the input exec_param to stuct exec_param
  
  local_param_size = sizeof(_video_renderer_task_local_param_t);
  construct_size = local_param_size - 4 + exec_param_size; // -4 is the size of exec_param in the struct

  ilm_param = (_video_renderer_task_local_param_t*) 
                  construct_local_para(construct_size, TD_CTRL);
  ASSERT(NULL != ilm_param);

  ilm_param->exec_func = exec_func;
  kal_mem_cpy(&(ilm_param->exec_param), exec_param, exec_param_size);

  eActiveModuleId = stack_get_active_module_id();
  p_ilm = allocate_ilm(eActiveModuleId);
  ASSERT(NULL != p_ilm);

  // check target task
  // Why not use return KAL_FALSE to instead
  // When ilm was allocated but not send to msg queue, ASSERT will happen when next
  // user to try to allocate ilm in the same thread
  if (NULL == exec_task_name)
  {
    ASSERT(0);
  }
  else
  {
    if (0 == strcmp(exec_task_name, "MOD_CAL"))
    {
      p_ilm->dest_mod_id = MOD_CAL;
      p_ilm->sap_id = CAL_SAP;
      p_ilm->msg_id = (msg_type) MSG_ID_CAL_VIDEO_RENDERER_REQ;
    }
    else
    {
      ASSERT(0);
    }
  }

  p_ilm->src_mod_id = eActiveModuleId;
  p_ilm->local_para_ptr = (local_para_struct*) ilm_param;
  p_ilm->peer_buff_ptr = NULL;

  msg_send_ext_queue(p_ilm);

  return KAL_TRUE;

#else //#if (defined(ISP_SUPPORT))
  return KAL_FALSE;
#endif //#if (defined(ISP_SUPPORT))

#else //#if defined(__MTK_TARGET__)
  return KAL_FALSE;
#endif //#if defined(__MTK_TARGET__)
}


void video_renderer_task_req_hdlr(ilm_struct *ilm_msg)
{
#if defined(__MTK_TARGET__)

  _video_renderer_task_local_param_t *local_para_ptr;
  video_renderer_task_exec_func_t exec_func;
  void * exec_param;

  ASSERT(NULL != ilm_msg);
  ASSERT(KAL_FALSE == kal_if_hisr());
  ASSERT(KAL_FALSE == kal_if_lisr());
  
  // get ilm parameters
  local_para_ptr = (_video_renderer_task_local_param_t*) ilm_msg->local_para_ptr;
  ASSERT(NULL != local_para_ptr);

  exec_func = local_para_ptr->exec_func;
  exec_param = &(local_para_ptr->exec_param);

  // do execution 
  if (exec_func)
  {
    exec_func(exec_param);
  }

#endif //#if defined(__MTK_TARGET__)
}

#endif //#if (!defined(DRV_IDP_6252_SERIES))


