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
 ****************************************************************************/
#ifndef __VA2_UTIL_BUFFER_HEADER_QUEUE_H__
#define __VA2_UTIL_BUFFER_HEADER_QUEUE_H__

#if defined(__VIDEO_ARCHI_V2__)
/****************************************************************************
 * include directives
 ****************************************************************************/
#include "video_types_v2.h"

/// \def va2_util_buffer_header_queue
/// @{
/****************************************************************************
 * local type definitions and macros
 ****************************************************************************/
typedef struct va2_util_buf_hdr_q_item_struct va2_util_buf_hdr_q_item_t;
struct va2_util_buf_hdr_q_item_struct
{
  VIDEO_BUFFERHEADER_TYPE_T   buffer_header;
  va2_util_buf_hdr_q_item_t   *prev;
  va2_util_buf_hdr_q_item_t   *next;
};

typedef struct
{
  va2_util_buf_hdr_q_item_t   *head;
  va2_util_buf_hdr_q_item_t   *tail;
  kal_uint32                  size;
} va2_util_buf_hdr_q_t;

typedef struct
{
  va2_util_buf_hdr_q_t        to_be_processed_q;
  va2_util_buf_hdr_q_t        to_be_returned_q;
  va2_util_buf_hdr_q_item_t   *curr_dspl_buf_hdr;
  va2_util_buf_hdr_q_item_t   *q_item_pool;
  kal_uint32                  q_item_pool_size;
} va2_util_buf_hdr_q_handle_t;

/****************************************************************************
 * external functions
 ****************************************************************************/
/**
 *  Enqueue item to q.
 *  @return None
 *  @param  va2_util_buf_hdr_q_t *q, pointer to a queue.
 *  @param  va2_util_buf_hdr_q_item_t *item, pointer to a queue item to be enqueued.
 */
extern void 
va2_util_buf_hdr_enqueue(
  va2_util_buf_hdr_q_t *q, 
  va2_util_buf_hdr_q_item_t *item);

/**
 *  Dequeue from q
 *  @return va2_util_buf_hdr_q_item_t*, pointer to the item dequeued from q. NULL if fails.
 *  @param  va2_util_buf_hdr_q_t *q, pointer to a queue.
 */
extern va2_util_buf_hdr_q_item_t* 
va2_util_buf_hdr_dequeue(
  va2_util_buf_hdr_q_t *q);

/**
 *  Peak the head of the q
 *  @return va2_util_buf_hdr_q_item_t*, pointer to the head of q, NULL if q is empty.
 *  @param  va2_util_buf_hdr_q_t *q, pointer to a queue.
 */
extern va2_util_buf_hdr_q_item_t* 
va2_util_buf_hdr_q_peek(
  va2_util_buf_hdr_q_t *q);

/** 
 *  Remove all queue items from src to dst. src will be empty after this function call.
 *  @return None.
 *  @param  va2_util_buf_hdr_q_t *dst, the pointer to the destination queue.
 *  @param  va2_util_buf_hdr_q_t *src, the pointer to the source queue.
 */
extern void 
va2_util_buf_hdr_remove_all_q_items(
  va2_util_buf_hdr_q_t *dst, 
  va2_util_buf_hdr_q_t *src);

/**
 *  Remove the tail of q and return it.
 *  @return va2_util_buf_hdr_q_item_t*, a pointer to the tail of q.
 *  @parma  va2_util_buf_hdr_q_t *q, a pointer to a queue, tail of which is to be removed.
 */
extern va2_util_buf_hdr_q_item_t* 
va2_util_buf_hdr_remove_q_tail(
  va2_util_buf_hdr_q_t *q);

/**
 *  Get an empty q item from pool.
 *  @return va2_util_buf_hdr_q_item_t*, a pointer to an empty queue item.
 *  @param  va2_util_buf_hdr_q_handle_t *handle, the handle to buffer header queue control block.
 */
extern va2_util_buf_hdr_q_item_t* 
va2_util_buf_hdr_get_empty_q_item(
  va2_util_buf_hdr_q_handle_t *handle);

/**
 *  Reset the buffer header queue control block.
 *  @return None.
 *  @param  va2_util_buf_hdr_q_handle_t *handle, the handle to buffer header queue control block.
 */
extern void 
va2_util_buf_hdr_reset_buffer_header_queues(
  va2_util_buf_hdr_q_handle_t *handle);

/**
 *  Put all items in to_be_processed_q to to_be_returned_q, only keep the latest one as the curr
 *  @return None.
 *  @param  va2_util_buf_hdr_q_handle_t *handle, the handle to buffer header queue control block.
 */
extern void 
va2_util_buf_hdr_advance_to_the_latest_buffer_header(
  va2_util_buf_hdr_q_handle_t *handle);

/// @}

#endif  // #if defined(__VIDEO_ARCHI_V2__)
#endif  // #ifndef __VA2_UTIL_BUFFER_HEADER_QUEUE_H__

