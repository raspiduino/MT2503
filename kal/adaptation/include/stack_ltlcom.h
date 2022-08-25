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
 *   stack_ltlcom.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the extern declarations and macros for
 *   using the Inter Layer Message structure.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#ifndef _STACK_LTLCOM_H
#define _STACK_LTLCOM_H

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"

extern void free_int_ilm(ilm_struct *ilm_ptr, kal_char* file_name, kal_uint32 line);

/*************************************************************************
 * Prototype of functions used in the FSM tables of modules
 *************************************************************************/
typedef void (* fsm_func_ptr)(local_para_struct *,
                              peer_buff_struct *);

/*************************************************************************
 * Exported Function Prototypes
 *************************************************************************/
/*
  NOTE: User must take care about the usage of this API, 
        if the message is sent to the same task, the message
        will be sent to internal queue, task must process the 
        internal queue. Otherwise, internal queue will full.
*/
#define SEND_ILM( src_mod, dest_mod, sap, ilm_ptr)\
{ \
   ilm_ptr->src_mod_id  = src_mod;  \
   ilm_ptr->dest_mod_id = dest_mod; \
   ilm_ptr->sap_id = sap; \
   if (mod_task_g[src_mod] == mod_task_g[dest_mod]) { \
     msg_send_int_queue(ilm_ptr); \
   } else { \
     msg_send_ext_queue(ilm_ptr); \
   } \
}

#if defined(DEBUG_KAL) && defined(DEBUG_ITC)
#define free_ilm(ilm_ptr) \
{\
   if ((ilm_ptr)->src_mod_id != MOD_TIMER) \
      free_int_ilm((ilm_ptr), (kal_char*)__FILE__, __LINE__ ); \
}
#else
#define free_ilm(ilm_ptr)\
{\
   if ((ilm_ptr)->src_mod_id != MOD_TIMER) \
      free_int_ilm((ilm_ptr), NULL, 0); \
}
#endif /* DEBUG_ITC */

#define SEND_APP_ILM( src_mod, sap, ilm_ptr )\
{\
  ilm_ptr->sap_id      = sap;\
  ilm_ptr->src_mod_id  = src_mod;\
  ilm_ptr->dest_mod_id = MOD_APP;\
  (*app_send_fptr_g)(ilm_ptr);\
}

/*************************************************************************
 * Generic functions used by send_ilm
 *************************************************************************/
extern kal_bool msg_send_ext_queue(ilm_struct *ilm_ptr);

extern kal_bool msg_send_ext_queue_to_head(ilm_struct *ilm_ptr);

extern kal_bool msg_send_int_queue(ilm_struct *ilm_ptr);

extern ilm_struct *allocate_ilm(module_type module_id);

extern kal_bool cancel_ilm(module_type module_id);

extern kal_bool msg_get_ext_queue_info(kal_msgqid task_ext_qid,
                                       kal_uint32 *messages);

extern kal_bool msg_get_ext_queue_length(kal_msgqid task_ext_qid, kal_uint32 *length);

extern kal_status receive_msg_ext_q( kal_msgqid task_ext_qid,
                                     ilm_struct *ilm_ptr);
extern kal_status receive_msg_ext_q_for_stack( kal_msgqid task_ext_qid,
                                     ilm_struct *ilm_ptr);
                                     
extern kal_bool receive_msg_int_q(task_indx_type task_indx, ilm_struct *ilm_ptr);

extern void remove_hdr_of_peer_buff( peer_buff_struct *peer_buff_ptr,
                                     kal_uint16 hdr_len);

extern void update_peer_buff_hdr(peer_buff_struct *peer_buff_ptr,
                                 kal_uint16        new_hdr_len,
                                 kal_uint16        new_pdu_len,
                                 kal_uint16        new_tail_len);

extern void* get_pdu_ptr(peer_buff_struct *peer_buff_ptr, kal_uint16 *length_ptr);

#if defined(DEBUG_KAL) && defined(DEBUG_BUF2)
/* Function     : construct_uplane_local_para()
 * Input        :
 *  local_pra_size:
 *                Length of local para contents.
 *  direction:
 *                direction of transfer. TD_UL,TD_DL or TD_CTRL.
 *  alloc_fptr:
 *                Pointer to the memory allocation function.
 *  status_ptr:
 *                address of memory location where the status
 *                of the buffer pool from where memory allocation is
 *                done is returned.
 * Return       : Returns a valid pointer on success. NULL on
 *                failure. If *status_ptr contains FLC_SDU_STATUS_UTHR_HIT
 *                or FLC_SDU_STATUS_LTHR_HIT, the caller should
 *                initiate flow control operations.
 *
 * Description  : Function allocates a local parameter structure
 *                of length local_para_size. The memory allocation is
 *                done using the function pointed by 'alloc_fptr'.
 *                This API should be used for only the
 *                data request and data indication primitives
 *                between application and protocol stack.( RLC<->App,
 *                RABM<->App ).
 */
#define construct_uplane_local_para(local_para_size, direction, alloc_fptr, status_ptr) \
        construct_int_uplane_local_para(local_para_size, ((kal_uint32)direction & (kal_uint32)TD_RESET) != 0), alloc_fptr, status_ptr , __FILE__, __LINE__)

/* Function     : free_uplane_local_para().
 * Input        :
 *   local_para:
 *      Pointer to the local parameter structure.
 *   free_fptr:
 *      Pointer to the function to be used for freeing local parameter.
 *   status_ptr:
 *      Address of the memory location at which the buffer status is
 *      returned.
 * Return       : None.
 *
 * Description  : API frees the local parameter structure created
 *                using 'construct_uplane_local_para()'. This API
 *                should be used only for the data transfer and data
 *                receive primitives between application and stack.
 *                (Application<->RLC, Application<->RABM).The free_fptr
 *                should point to the SDU buffer free function
 *                provided by application at call setup time.
 *                The caller should take flow control actions if
 *                *status_ptr contains FLC_SDU_STATUS_LTHR_HIT
 *                or FLC_SDU_STATUS_UTHR_HIT.
 */
#define free_uplane_local_para( local_para,free_fptr, status_ptr) \
        free_int_uplane_local_para(local_para, free_fptr, status_ptr, __FILE__, __LINE__)

/* Function     : free_uplane_peer_buff()
 * Input        :
 *   local_para:
 *      Pointer to the peer buffer structure.
 *   free_fptr:
 *      Pointer to the function to be used for freeing local parameter.
 *   status_ptr:
 *      Address of the memory location at which the buffer status is
 *      returned.
 * Return       : None.
 *
 * Description  : Function frees the peer buffer structure created
 *                using 'construct_uplane_peer_buff()'. This primitive
 *                should be used for only the data
 *                request and data indication primitives between
 *                application and protocol stack.( RLC<->App,
 *                RABM<->App ). The free_fptr should point to the
 *                SDU buffer free function provided by application
 *                at call setup time. The caller should take
 *                flow control actions if *status_ptr contains
 *                FLC_SDU_STATUS_LTHR_HIT or FLC_SDU_STATUS_UTHR_HIT.
 */
#define free_uplane_peer_buff( pdu_ptr, free_fptr, status_ptr) \
        free_int_uplane_peer_buff(pdu_ptr, free_fptr, status_ptr, __FILE__, __LINE__)

#else   /* DEBUG_KAL && DEBUG_BUF2 */

#endif /* DEBUG_KAL && DEBUG_BUF2 */


#endif /* _STACK_LTLCOM_H */


