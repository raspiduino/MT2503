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
 *    
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    
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
 *
 * removed!
 * removed!
 * removed!
 *
 ****************************************************************************/
#if defined(__VIDEO_ARCHI_V2__)
/****************************************************************************
 * include directives
 ****************************************************************************/
#include "va2_util_buffer_header_queue.h"
#include "kal_public_api.h"
#include "video_types_v2.h"

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_RENDER_ROCODE", rodata = "DYNAMIC_CODE_RENDER_ROCODE"
#endif

#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  extern kal_uint32 SaveAndSetIRQMask(void);
  extern void RestoreIRQMask(kal_uint32);
#endif

/****************************************************************************
 * external function bodies
 ****************************************************************************/
void 
va2_util_buf_hdr_enqueue(
  va2_util_buf_hdr_q_t *q, 
  va2_util_buf_hdr_q_item_t *item)
{
#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  kal_uint32 save_irq_mask;
#endif

  if ((NULL == q) || (NULL == item))
  {
    ASSERT(0);
  }

#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  save_irq_mask = SaveAndSetIRQMask();
#endif
  if ((NULL == q->tail) && (NULL == q->head) && (0 == q->size))
  {
    q->head = item;
    q->tail = item;
    q->size = 1;
    item->prev = NULL;
    item->next = NULL;
  }
  else
  {
    q->tail->next = item;
    item->prev = q->tail;
    item->next = NULL;
    q->tail = item;
    q->size += 1;
  }
#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  RestoreIRQMask(save_irq_mask);
#endif
}

va2_util_buf_hdr_q_item_t* 
va2_util_buf_hdr_dequeue(
  va2_util_buf_hdr_q_t *q)
{
#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  kal_uint32 save_irq_mask;
#endif
  
  if (NULL == q)
  {
    ASSERT(0);
  }

#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  save_irq_mask = SaveAndSetIRQMask();
#endif
  if (0 != q->size)
  {
    va2_util_buf_hdr_q_item_t *item = q->head;
    
    q->head = item->next;
    q->size -= 1;
    if (0 == q->size)
    {
      q->tail = NULL;
    }
    item->prev = NULL;
    item->next = NULL;

#if defined (MT6276) || defined(MT6256) || defined(MT6255)
    RestoreIRQMask(save_irq_mask);
#endif

    return item;
  }
#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  RestoreIRQMask(save_irq_mask);
#endif

  return NULL;
}

va2_util_buf_hdr_q_item_t* 
va2_util_buf_hdr_q_peek(
  va2_util_buf_hdr_q_t *q)
{
  if (NULL == q)
  {
    ASSERT(0);
  }

  return q->head;
}

void 
va2_util_buf_hdr_remove_all_q_items(
  va2_util_buf_hdr_q_t *dst, 
  va2_util_buf_hdr_q_t *src)
{
#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  kal_uint32 save_irq_mask;
#endif
  
  if ((NULL == dst) || (NULL == src))
  {
    ASSERT(0);
  }

#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  save_irq_mask = SaveAndSetIRQMask();
#endif
  if (0 == dst->size)
  {
    dst->head = src->head;
    dst->tail = src->tail;
    dst->size += src->size;

    src->head = NULL;
    src->tail = NULL;
    src->size = 0;
  }
  else
  {
    if (0 == src->size)
    {
//      ASSERT(NULL == src->head);
//      ASSERT(NULL == src->tail);
    }
    else
    {
//      ASSERT(NULL != src->head);
      dst->tail->next = src->head;
      src->head->prev = dst->tail;
//      ASSERT(NULL != src->tail);
      dst->tail = src->tail;
      dst->size += src->size;

      src->head = NULL;
      src->tail = NULL;
      src->size = 0;
    }
  }
#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  RestoreIRQMask(save_irq_mask);
#endif
}

va2_util_buf_hdr_q_item_t* 
va2_util_buf_hdr_remove_q_tail(
  va2_util_buf_hdr_q_t *q)
{
#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  kal_uint32 save_irq_mask;
#endif
  
  va2_util_buf_hdr_q_item_t *item = NULL;

  if (NULL == q)
  {
    ASSERT(0);
  }

#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  save_irq_mask = SaveAndSetIRQMask();
#endif
  if (0 == q->size)
  {
  }
  else if (1 == q->size)
  {
//    ASSERT(NULL != q->head);
    item = q->head;
    item->prev = NULL;
    item->next = NULL;

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
  }
  else
  {
 //   ASSERT(NULL != q->tail);
    item = q->tail;
 //   ASSERT(NULL != item->prev);
    q->tail = item->prev;
    q->tail->next = NULL;
    q->size -= 1;
    item->prev = NULL;
 //   ASSERT(NULL == item->next);
  }
#if defined (MT6276) || defined(MT6256) || defined(MT6255)
  RestoreIRQMask(save_irq_mask);
#endif

  return item;
}

/**
 *  @todo naive version, to be optimized...
 */
va2_util_buf_hdr_q_item_t* 
va2_util_buf_hdr_get_empty_q_item(
  va2_util_buf_hdr_q_handle_t *handle)
{
  if (NULL == handle)
  {
    ASSERT(0);
  }

  if (NULL != handle->q_item_pool)
  {
    kal_int32 i = handle->q_item_pool_size;
    for (; --i >= 0 ;)
    {
      va2_util_buf_hdr_q_item_t* curr_q_item = &handle->q_item_pool[i];
      if ((NULL == curr_q_item->next) && 
          (NULL == curr_q_item->prev) && 
          (0 == curr_q_item->buffer_header.u4BuffSize))
      {
        return curr_q_item;
      }
    }
  }

  return NULL;
}

void 
va2_util_buf_hdr_reset_buffer_header_queues(
  va2_util_buf_hdr_q_handle_t *handle)
{
  if (NULL == handle)
  {
    ASSERT(0);
  }

  handle->curr_dspl_buf_hdr = NULL;

  // clear to_be_processed_q + to_be_returned_q
  kal_mem_set((void*) &(handle->to_be_processed_q), 0x0, sizeof(va2_util_buf_hdr_q_t)*2);

  kal_mem_set((void*) handle->q_item_pool, 0x0, 
              sizeof(va2_util_buf_hdr_q_item_t)*(handle->q_item_pool_size));
}

void 
va2_util_buf_hdr_advance_to_the_latest_buffer_header(
  va2_util_buf_hdr_q_handle_t *handle)
{
  if (NULL == handle)
  {
    ASSERT(0);
  }

  if (0 != handle->to_be_processed_q.size)
  {
    if (NULL != handle->curr_dspl_buf_hdr)
    {
      va2_util_buf_hdr_enqueue(&(handle->to_be_returned_q), handle->curr_dspl_buf_hdr);
      handle->curr_dspl_buf_hdr = NULL;
    }  
    va2_util_buf_hdr_remove_all_q_items(&(handle->to_be_returned_q), &(handle->to_be_processed_q));
    handle->curr_dspl_buf_hdr = va2_util_buf_hdr_remove_q_tail(&(handle->to_be_returned_q));
  }
}

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

#endif  // #if defined(__VIDEO_ARCHI_V2__)


