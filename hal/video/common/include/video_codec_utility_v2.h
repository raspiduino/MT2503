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
 *   video_codec_utility_v2.h
 *
 * Project:
 * --------
 *	MTK
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
 * removed!
 *
 *
 ****************************************************************************/
#ifndef VIDEO_CODEC_UTILITY_V2_H
#define VIDEO_CODEC_UTILITY_V2_H

#include "drv_features_video.h"
//#ifdef __VE_VIDEO_ARCHI_V2__

#include "kal_general_types.h"

// for function reentry
//#define RING_BUFFER_FUNCTION_REENTRY_CHECKING

typedef struct
{
    kal_uint8 *pu1Start;     // Always point to &(pu1Atoms[0])
    kal_uint32 u4Head;        // Add item, Value increase
    kal_uint32 u4Tail;          // Add item, Vaule decrease
    kal_uint32  u4NumberOfAtoms;            // Number of atoms in the queue
    kal_uint32  u4MaxNumberofAtoms;         // Total number of atoms
    kal_bool    fgInitialized;              // Indicate the buffer is initialized
    kal_uint32  u4SizeOfAnAtom;             // Size of an atom
#ifdef RING_BUFFER_FUNCTION_REENTRY_CHECKING
    kal_uint32  u4ReentryFlag;              // function reentry 
#endif    
} VIDEO_CORE_RING_BUFFER_MGR_T;

void VideoCoreInitRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr,     // The ring buffer manager, allocated by user
    kal_uint8   *pu1Buffer,                          // Start address of the ring buffer
    kal_uint32  u4MaxNumberofAtoms,                 // Total number of the units in the buffer
    kal_uint32  u4UnitSize                         // Size of an unit in byte
);

void VideoCoreDeInitRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
);

void VideoCoreCleanRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr     // The ring buffer manager, allocated by user
);

kal_bool VideoCoreIsRingBufferEmpty(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
);

kal_bool VideoCoreIsRingBufferFull(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
);

kal_uint32 VideoCoreRingBufferUsedNum(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
);

kal_uint32 VideoCoreRingGetBufferMaxNum(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
);

kal_uint8*  VideoCoreRingGetBufferStart(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
);

kal_uint8*  VideoCoreRingGetBufferEnd(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
);

kal_uint8 * VideoCoreGetHeadofRingBufferAddr(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
);

kal_bool  VideoCoreConsumeHeadofRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
);

kal_bool VideoCoreRemoveFromHeadofRingBufferAddr(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr, // The ring buffer manager, allocated by user
    kal_uint8 *pu1NewAtom                      // A new atom to obtain the head of the ring buffer
);

kal_uint8 * VideoCoreGetNextHeadofRingBufferAddr(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
);

kal_bool  VideoCoreAddHeadofRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
);

kal_bool VideoCoreInsertToHeadofRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr, // The ring buffer manager, allocated by user
    kal_uint8 *pu1NewAtom                       // A new atom to be inserted to the head of the ring buffer
);

kal_uint8 * VideoCoreGetTailofRingBufferAddr(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
);

kal_bool  VideoCoreConsumeTailofRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
);

kal_bool VideoCoreRemoveFromTailofRingBufferAddr(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr, // The ring buffer manager, allocated by user
    kal_uint8 *pu1NewAtom                      // A new atom to obtain the tail of the ring buffer
);

kal_uint8 * VideoCoreGetNextTailofRingBufferAddr(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
);

kal_bool  VideoCoreAddTailofRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
);

kal_bool VideoCoreInsertToTailofRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr, // The ring buffer manager, allocated by user
    kal_uint8 *pu1NewAtom                       // A new atom to be inserted to the head of the ring buffer
);

typedef enum
{
    VIDEO_CORE_INIT_RING_BUFFER                     = (1<<0),
    VIDEO_CORE_DEINIT_RING_BUFFER                   = (1<<1),
    VIDEO_CORE_CLEAN_RING_BUFFER                    = (1<<2),
    VIDEO_CORE_IS_RING_BUFFER_EMPTY                 = (1<<3),
    VIDEO_CORE_IS_RING_BUFFER_FULL                  = (1<<4),
    VIDEO_CORE_RING_BUFFER_USED_NUM                 = (1<<5),
    VIDEO_CORE_RING_GET_BUFFER_MAX_NUM              = (1<<6),
    VIDEO_CORE_RING_GET_BUFFER_START                = (1<<7),
    VIDEO_CORE_RING_GET_BUFFER_END                  = (1<<8),
    VIDEO_CORE_GET_HEAD_OF_RING_BUFFER_ADDR         = (1<<9),
    VIDEO_CORE_CONSUME_HEAD_OF_RING_BUFFER          = (1<<10),
    VIDEO_CORE_REMOVE_FROM_HEAD_OF_RING_BUFFER_ADDR = (1<<11),
    VIDEO_CORE_GET_NEXT_HEAD_OF_RING_BUFFER_ADDR    = (1<<12),
    VIDEO_CORE_ADD_HEAD_OF_RING_BUFFER              = (1<<13),
    VIDEO_CORE_INSERT_TO_HEAD_OF_RING_BUFFER        = (1<<14),
    VIDEO_CORE_GET_TAIL_OF_RING_BUFFER_ADDR         = (1<<15),
    VIDEO_CORE_CONSUME_TAIL_OF_RING_BUFFER          = (1<<16),
    VIDEO_CORE_REMOVE_FROM_TAIL_OF_RING_BUFFER_ADDR = (1<<17),
    VIDEO_CORE_GET_NEXT_TAIL_OF_RING_BUFFER_ADDR    = (1<<18),
    VIDEO_CORE_ADD_TAIL_OF_RING_BUFFER              = (1<<19),
    VIDEO_CORE_INSERT_TO_TAIL_OF_RING_BUFFER        = (1<<20)
} VIDEO_CORE_FLAG;

//#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* VIDEO_CODEC_UTILITY_H */

