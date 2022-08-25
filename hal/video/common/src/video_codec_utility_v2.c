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
 *   video_codec_utility_v2.c
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
 *
 *
 *
 ****************************************************************************/

#include "drv_features_video.h"
//#ifdef __VE_VIDEO_ARCHI_V2__
#include "drv_comm.h"
#include "video_codec_utility_v2.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#ifdef RING_BUFFER_FUNCTION_REENTRY_CHECKING
#define F_REENTRY_ENTER(__BIT__) \
do{   \
	kal_uint32 u4SavedMask;               \
	u4SavedMask = SaveAndSetIRQMask();    \
	if (prBufferMgr->u4ReentryFlag&(__BIT__) != 0) \
	{                  \
		ASSERT(0);     \
	}                  \
	prBufferMgr->u4ReentryFlag |= (__BIT__); \
	RestoreIRQMask(u4SavedMask);          \
}while(0)  
  
#define F_REENTRY_EXIT(__BIT__) \
do{   \
	kal_uint32 u4SavedMask;               \
	u4SavedMask = SaveAndSetIRQMask();    \
	prBufferMgr->u4ReentryFlag &= (~(__BIT__)); \
	RestoreIRQMask(u4SavedMask);          \
}while(0)    
#else
#define F_REENTRY_ENTER(__BIT__) do{}while(0)
#define F_REENTRY_EXIT(__BIT__) do{}while(0)
#endif

#ifdef __VE_MM_DCM_SUPPORT__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VECOM_ROCODE", rodata = "DYNAMIC_CODE_VECOM_RODATA"
#endif

/******************************************************************************
* Initialize a ring buffer manager and link each atom/unit in the buffer
* in series.
*
* Note:
*
*
* Context:
*
* Side effect:
******************************************************************************/
void VideoCoreInitRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr,     // The ring buffer manager, allocated by user
    kal_uint8   *pu1Buffer,                          // Start address of the ring buffer
    kal_uint32  u4MaxNumberofAtoms,                 // Total number of the units in the buffer
    kal_uint32  u4UnitSize                         // Size of an unit in byte
)
{
	if (prBufferMgr == NULL || pu1Buffer == NULL || u4MaxNumberofAtoms == 0 || u4UnitSize == 0)
	{
		ASSERT(0);
	}
	
    kal_mem_set((void*)prBufferMgr, 0, sizeof(VIDEO_CORE_RING_BUFFER_MGR_T));

    prBufferMgr->u4MaxNumberofAtoms = u4MaxNumberofAtoms;
    prBufferMgr->u4SizeOfAnAtom = u4UnitSize;
    prBufferMgr->pu1Start = pu1Buffer;
    prBufferMgr->u4Tail = 1;

    kal_mem_set((void*)(prBufferMgr->pu1Start), 0, (u4MaxNumberofAtoms*u4UnitSize));

    prBufferMgr->fgInitialized = KAL_TRUE;
}

/******************************************************************************
* De-initialize the ring buffer manager.
*
* Context:
*
* Side effect:
******************************************************************************/
void VideoCoreDeInitRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
)
{
	F_REENTRY_ENTER(VIDEO_CORE_DEINIT_RING_BUFFER);
	
	if (prBufferMgr == NULL || (prBufferMgr->fgInitialized == KAL_FALSE))
	{
		ASSERT(0);
	}
	
    kal_mem_set((void*)prBufferMgr, 0, sizeof(VIDEO_CORE_RING_BUFFER_MGR_T));

    prBufferMgr->fgInitialized = KAL_FALSE;
    
    F_REENTRY_EXIT(VIDEO_CORE_DEINIT_RING_BUFFER);
}

/******************************************************************************
* Initialize a ring buffer manager and link each atom/unit in the buffer
* in series.
*
* Note:
*
*
* Context:
*
* Side effect:
******************************************************************************/
void VideoCoreCleanRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr     // The ring buffer manager, allocated by user
)
{
	F_REENTRY_ENTER(VIDEO_CORE_CLEAN_RING_BUFFER);
		
    if ((prBufferMgr != NULL) && (prBufferMgr->fgInitialized == KAL_TRUE))
    {
        prBufferMgr->u4Head = 0;
        prBufferMgr->u4Tail = 1;
        prBufferMgr->u4NumberOfAtoms = 0;

        kal_mem_set((void*)(prBufferMgr->pu1Start), 0, (prBufferMgr->u4MaxNumberofAtoms*prBufferMgr->u4SizeOfAnAtom));
    }
    else
    {
        ASSERT(0);
    }
    
    F_REENTRY_EXIT(VIDEO_CORE_CLEAN_RING_BUFFER);
}

/******************************************************************************
* Is the ring buffer empty?
*
* Context:
*
* Side effect:
******************************************************************************/
__inline kal_bool VideoCoreIsRingBufferEmpty(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
)
{
	F_REENTRY_ENTER(VIDEO_CORE_IS_RING_BUFFER_EMPTY);
		
    if ((prBufferMgr != NULL) && (prBufferMgr->fgInitialized == KAL_TRUE))
    {
        if (prBufferMgr->u4NumberOfAtoms == 0)
        {
        	F_REENTRY_EXIT(VIDEO_CORE_IS_RING_BUFFER_EMPTY);
            return KAL_TRUE;
        }
    }
    else
    {
        ASSERT(0);
    }

    F_REENTRY_EXIT(VIDEO_CORE_IS_RING_BUFFER_EMPTY);
    return KAL_FALSE;
}

/******************************************************************************
* Is the ring buffer full?
*
* Context:
*
* Side effect:
******************************************************************************/
__inline kal_bool VideoCoreIsRingBufferFull(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
)
{
	F_REENTRY_ENTER(VIDEO_CORE_IS_RING_BUFFER_FULL);
	
    if ((prBufferMgr != NULL) && (prBufferMgr->fgInitialized == KAL_TRUE))
    {
        if (prBufferMgr->u4NumberOfAtoms == prBufferMgr->u4MaxNumberofAtoms)
        {
        	F_REENTRY_EXIT(VIDEO_CORE_IS_RING_BUFFER_FULL);
            return KAL_TRUE;
        }
    }
    else
    {
        ASSERT(0);
    }

    F_REENTRY_EXIT(VIDEO_CORE_IS_RING_BUFFER_FULL);
    return KAL_FALSE;
}

/******************************************************************************
* The number of item exist in ring buffer
*
* Context:
*
* Side effect:
******************************************************************************/
kal_uint32 VideoCoreRingBufferUsedNum(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
)
{	
    kal_uint32 u4Num = 0;
    
	F_REENTRY_ENTER(VIDEO_CORE_RING_BUFFER_USED_NUM);

    if ((prBufferMgr != NULL) && (prBufferMgr->fgInitialized == KAL_TRUE))
    {
    	u4Num = prBufferMgr->u4NumberOfAtoms;
    }
    else
    {
        ASSERT(0);
    }
    
    F_REENTRY_EXIT(VIDEO_CORE_RING_BUFFER_USED_NUM);
    return u4Num;
}

/******************************************************************************
* The max number of item could exist in ring buffer
*
* Context:
*
* Side effect:
******************************************************************************/
kal_uint32 VideoCoreRingGetBufferMaxNum(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
)
{
	kal_uint32 u4Num = 0;
	
	F_REENTRY_ENTER(VIDEO_CORE_RING_GET_BUFFER_MAX_NUM);

    if ((prBufferMgr != NULL) && (prBufferMgr->fgInitialized == KAL_TRUE))
    {
        u4Num = prBufferMgr->u4MaxNumberofAtoms;
    }
    else
    {
        ASSERT(0);
    }
    
    F_REENTRY_EXIT(VIDEO_CORE_RING_GET_BUFFER_MAX_NUM);
    return u4Num;
}

/******************************************************************************
* The start address of ring buffer
*
* Context:
*
* Side effect:
******************************************************************************/
kal_uint8*  VideoCoreRingGetBufferStart(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
)
{
	kal_uint8 *pu1Addr = NULL;

	F_REENTRY_ENTER(VIDEO_CORE_RING_GET_BUFFER_START);
	
	if ((prBufferMgr != NULL) && (prBufferMgr->fgInitialized == KAL_TRUE))
    {
        pu1Addr = prBufferMgr->pu1Start;
    }
    else
    {
        ASSERT(0);
    }
    
    F_REENTRY_EXIT(VIDEO_CORE_RING_GET_BUFFER_START);
    return pu1Addr;
}

/******************************************************************************
* The end address of ring buffer
*
* Context:
*
* Side effect:
******************************************************************************/
kal_uint8*  VideoCoreRingGetBufferEnd(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr  // The ring buffer manager, allocated by user
)
{
	kal_uint8 *pu1Addr = NULL;
	
	F_REENTRY_ENTER(VIDEO_CORE_RING_GET_BUFFER_END);

	if ((prBufferMgr != NULL) && (prBufferMgr->fgInitialized == KAL_TRUE))
    {
        pu1Addr = (prBufferMgr->pu1Start + (prBufferMgr->u4MaxNumberofAtoms - 1)*prBufferMgr->u4SizeOfAnAtom);
    }
    else
    {
        ASSERT(0);
    }
    
    F_REENTRY_EXIT(VIDEO_CORE_RING_GET_BUFFER_END);
    return pu1Addr;
}

/******************************************************************************
* Get the address of the atom at the head of the ring buffer.
*
* Context:
*
* Side effect:
******************************************************************************/
kal_uint8 * VideoCoreGetHeadofRingBufferAddr(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
)
{
    kal_uint8 *pu1Atom;
    
	F_REENTRY_ENTER(VIDEO_CORE_GET_HEAD_OF_RING_BUFFER_ADDR);
   
    if (KAL_TRUE == VideoCoreIsRingBufferEmpty(prBufferMgr))
    {
    	F_REENTRY_EXIT(VIDEO_CORE_GET_HEAD_OF_RING_BUFFER_ADDR);
        return NULL;
    }

    pu1Atom = prBufferMgr->pu1Start + (prBufferMgr->u4Head*prBufferMgr->u4SizeOfAnAtom);
    
    F_REENTRY_EXIT(VIDEO_CORE_GET_HEAD_OF_RING_BUFFER_ADDR);
    return pu1Atom;
}

/******************************************************************************
* Consume one atom in head of ring buffer. The u1Head value decrease.
*
* Context:
*
* Side effect:
******************************************************************************/
kal_bool  VideoCoreConsumeHeadofRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
)
{
	F_REENTRY_ENTER(VIDEO_CORE_CONSUME_HEAD_OF_RING_BUFFER);
	
    if (KAL_TRUE == VideoCoreIsRingBufferEmpty(prBufferMgr))
    {
    	F_REENTRY_EXIT(VIDEO_CORE_CONSUME_HEAD_OF_RING_BUFFER);
        return KAL_FALSE;
    }

    if (prBufferMgr->u4Head == 0)
    {
        prBufferMgr->u4Head = prBufferMgr->u4MaxNumberofAtoms-1;
    }
    else
    {
        prBufferMgr->u4Head--;
    }
    prBufferMgr->u4NumberOfAtoms--;    

    F_REENTRY_EXIT(VIDEO_CORE_CONSUME_HEAD_OF_RING_BUFFER);
    return KAL_TRUE;
}

/******************************************************************************
* Get the address of the atom at the head of the ring buffer and comsume one item.
*
* Context:
*
* Side effect:
******************************************************************************/
kal_bool VideoCoreRemoveFromHeadofRingBufferAddr(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr, // The ring buffer manager, allocated by user
    kal_uint8 *pu1NewAtom                      // A new atom to obtain the head of the ring buffer
)
{
    kal_uint8 *pu1Atom;
   
	F_REENTRY_ENTER(VIDEO_CORE_REMOVE_FROM_HEAD_OF_RING_BUFFER_ADDR);
   
    if ((pu1NewAtom != NULL)
        &&(prBufferMgr != NULL)
        &&(prBufferMgr->fgInitialized == KAL_TRUE))
    {    
    	pu1Atom = VideoCoreGetHeadofRingBufferAddr(prBufferMgr);
	    if (pu1Atom != NULL)
	    {
	    	kal_mem_cpy((void*)(pu1NewAtom), (void*)(pu1Atom), prBufferMgr->u4SizeOfAnAtom);  // Store new atom
	    	kal_mem_set((void*)(pu1Atom), 0, prBufferMgr->u4SizeOfAnAtom); // Set memory with 0
	        VideoCoreConsumeHeadofRingBuffer(prBufferMgr);
	        
	        F_REENTRY_EXIT(VIDEO_CORE_REMOVE_FROM_HEAD_OF_RING_BUFFER_ADDR);
	        return KAL_TRUE;
	    }
	}
    else
    {
        ASSERT(0);
        F_REENTRY_EXIT(VIDEO_CORE_REMOVE_FROM_HEAD_OF_RING_BUFFER_ADDR);
        return KAL_FALSE;
    }

    F_REENTRY_EXIT(VIDEO_CORE_REMOVE_FROM_HEAD_OF_RING_BUFFER_ADDR);
    return KAL_FALSE; 
}

/******************************************************************************
* Get the next free address of the atom at the head of the ring buffer.
*
* Context:
*
* Side effect:
******************************************************************************/
kal_uint8 * VideoCoreGetNextHeadofRingBufferAddr(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
)
{
    kal_uint8 *pu1Atom;
    kal_uint32 u4Temp;
    
	F_REENTRY_ENTER(VIDEO_CORE_GET_NEXT_HEAD_OF_RING_BUFFER_ADDR);

    if (KAL_TRUE == VideoCoreIsRingBufferFull(prBufferMgr))
    {
    	F_REENTRY_EXIT(VIDEO_CORE_GET_NEXT_HEAD_OF_RING_BUFFER_ADDR);
        return NULL;
    }

    u4Temp = prBufferMgr->u4Head+1;
    if (u4Temp == prBufferMgr->u4MaxNumberofAtoms)
    {
        u4Temp = 0;
    }

    pu1Atom = prBufferMgr->pu1Start + (u4Temp*prBufferMgr->u4SizeOfAnAtom);

    F_REENTRY_EXIT(VIDEO_CORE_GET_NEXT_HEAD_OF_RING_BUFFER_ADDR);
    return pu1Atom;

}

/******************************************************************************
* Add one atom in head of ring buffer. The u1Head value increase.
*
* Context:
*
* Side effect:
******************************************************************************/
kal_bool  VideoCoreAddHeadofRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
)
{
    kal_uint32 u4Temp;
    
	F_REENTRY_ENTER(VIDEO_CORE_ADD_HEAD_OF_RING_BUFFER);

    if (KAL_TRUE == VideoCoreIsRingBufferFull(prBufferMgr))
    {
    	F_REENTRY_EXIT(VIDEO_CORE_ADD_HEAD_OF_RING_BUFFER);
        return KAL_FALSE;
    }

    u4Temp = prBufferMgr->u4Head+1;
    if (u4Temp == prBufferMgr->u4MaxNumberofAtoms)
    {
        u4Temp = 0;
    }

    prBufferMgr->u4Head = u4Temp;
    prBufferMgr->u4NumberOfAtoms++;

    F_REENTRY_EXIT(VIDEO_CORE_ADD_HEAD_OF_RING_BUFFER);
    return KAL_TRUE;
}

/******************************************************************************
* Copy the data pointed to by prNewAtom to the atom pointed by pu1HeadAtom
*
* Context:
*
* Side effect:
******************************************************************************/
kal_bool VideoCoreInsertToHeadofRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr, // The ring buffer manager, allocated by user
    kal_uint8 *pu1NewAtom                       // A new atom to be inserted to the head of the ring buffer
)
{
    kal_uint8* pu1HeadAtom;
    
	F_REENTRY_ENTER(VIDEO_CORE_INSERT_TO_HEAD_OF_RING_BUFFER);

    if ((pu1NewAtom != NULL)
        &&(prBufferMgr != NULL)
        &&(prBufferMgr->fgInitialized == KAL_TRUE))
    {
        pu1HeadAtom = VideoCoreGetNextHeadofRingBufferAddr(prBufferMgr);
        if(NULL != pu1HeadAtom)
        {
            kal_mem_cpy((void*)(pu1HeadAtom), (void*)(pu1NewAtom), prBufferMgr->u4SizeOfAnAtom);  // Store new atom
            VideoCoreAddHeadofRingBuffer(prBufferMgr);
            F_REENTRY_EXIT(VIDEO_CORE_INSERT_TO_HEAD_OF_RING_BUFFER);
            return KAL_TRUE;
        }
    }
    else
    {
        ASSERT(0);
        F_REENTRY_EXIT(VIDEO_CORE_INSERT_TO_HEAD_OF_RING_BUFFER);
        return KAL_FALSE;
    }

    F_REENTRY_EXIT(VIDEO_CORE_INSERT_TO_HEAD_OF_RING_BUFFER);
    return KAL_FALSE;
}

/******************************************************************************
* Get the address of the atom at the tail of the ring buffer.
*
* Context:
*
* Side effect:
******************************************************************************/
kal_uint8 * VideoCoreGetTailofRingBufferAddr(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
)
{
    kal_uint8 *pu1Atom;
    
	F_REENTRY_ENTER(VIDEO_CORE_GET_TAIL_OF_RING_BUFFER_ADDR);

    if (KAL_TRUE == VideoCoreIsRingBufferEmpty(prBufferMgr))
    {
    	F_REENTRY_EXIT(VIDEO_CORE_GET_TAIL_OF_RING_BUFFER_ADDR);
        return NULL;
    }

    pu1Atom = prBufferMgr->pu1Start + (prBufferMgr->u4Tail*prBufferMgr->u4SizeOfAnAtom);    

    F_REENTRY_EXIT(VIDEO_CORE_GET_TAIL_OF_RING_BUFFER_ADDR);
    return pu1Atom;
}

/******************************************************************************
* Consume one atom in tail of ring buffer. The u1Tail value increase.
*
* Context:
*
* Side effect:
******************************************************************************/
kal_bool  VideoCoreConsumeTailofRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
)
{
	F_REENTRY_ENTER(VIDEO_CORE_CONSUME_TAIL_OF_RING_BUFFER);

    if (KAL_TRUE == VideoCoreIsRingBufferEmpty(prBufferMgr))
    {
    	F_REENTRY_EXIT(VIDEO_CORE_CONSUME_TAIL_OF_RING_BUFFER);
        return KAL_FALSE;
    }

    prBufferMgr->u4Tail++;
    if (prBufferMgr->u4Tail == prBufferMgr->u4MaxNumberofAtoms)
    {
        prBufferMgr->u4Tail = 0;
    }
    prBufferMgr->u4NumberOfAtoms--;
    
    F_REENTRY_EXIT(VIDEO_CORE_CONSUME_TAIL_OF_RING_BUFFER);
    return KAL_TRUE;
}

/******************************************************************************
* Get the address of the atom at the tail of the ring buffer and comsume one item.
*
* Context:
*
* Side effect:
******************************************************************************/
kal_bool VideoCoreRemoveFromTailofRingBufferAddr(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr, // The ring buffer manager, allocated by user
    kal_uint8 *pu1NewAtom                      // A new atom to obtain the tail of the ring buffer
)
{
    kal_uint8 *pu1Atom;
    
	F_REENTRY_ENTER(VIDEO_CORE_REMOVE_FROM_TAIL_OF_RING_BUFFER_ADDR);
   
    if ((pu1NewAtom != NULL)
        &&(prBufferMgr != NULL)
        &&(prBufferMgr->fgInitialized == KAL_TRUE))
    {    
    	pu1Atom = VideoCoreGetTailofRingBufferAddr(prBufferMgr);
	    if (pu1Atom != NULL)
	    {
	    	kal_mem_cpy((void*)(pu1NewAtom), (void*)(pu1Atom), prBufferMgr->u4SizeOfAnAtom);  // Store new atom
	    	kal_mem_set((void*)(pu1Atom), 0, prBufferMgr->u4SizeOfAnAtom); // Set memory with 0
	        VideoCoreConsumeTailofRingBuffer(prBufferMgr);
	        F_REENTRY_EXIT(VIDEO_CORE_REMOVE_FROM_TAIL_OF_RING_BUFFER_ADDR);
	        return KAL_TRUE;
	    }
	}
    else
    {
        ASSERT(0);
        F_REENTRY_EXIT(VIDEO_CORE_REMOVE_FROM_TAIL_OF_RING_BUFFER_ADDR);
        return KAL_FALSE;
    }

    F_REENTRY_EXIT(VIDEO_CORE_REMOVE_FROM_TAIL_OF_RING_BUFFER_ADDR);
    return KAL_FALSE; 
}


/******************************************************************************
* Get the next free address of the atom at the tail of the ring buffer.
*
* Context:
*
* Side effect:
******************************************************************************/
kal_uint8 * VideoCoreGetNextTailofRingBufferAddr(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
)
{
    kal_uint8 *pu1Atom;
    kal_uint32 u4Temp;
    
	F_REENTRY_ENTER(VIDEO_CORE_GET_NEXT_TAIL_OF_RING_BUFFER_ADDR);

    if (KAL_TRUE == VideoCoreIsRingBufferFull(prBufferMgr))
    {
    	F_REENTRY_EXIT(VIDEO_CORE_GET_NEXT_TAIL_OF_RING_BUFFER_ADDR);
        return NULL;
    }

    u4Temp = prBufferMgr->u4Tail;
    if (u4Temp == 0)
    {
        u4Temp = prBufferMgr->u4MaxNumberofAtoms-1;
    }
    else
    {
        u4Temp--;
    }

    pu1Atom = prBufferMgr->pu1Start + (u4Temp*prBufferMgr->u4SizeOfAnAtom);
    
    F_REENTRY_EXIT(VIDEO_CORE_GET_NEXT_TAIL_OF_RING_BUFFER_ADDR);
    return pu1Atom;

}

/******************************************************************************
* Add one atom in tail of ring buffer. The u1Tail value decrease.
*
* Context:
*
* Side effect:
******************************************************************************/
kal_bool  VideoCoreAddTailofRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr // The ring buffer manager, allocated by user
)
{
    kal_uint32 u4Temp;
    
	F_REENTRY_ENTER(VIDEO_CORE_ADD_TAIL_OF_RING_BUFFER);

    if (KAL_TRUE == VideoCoreIsRingBufferFull(prBufferMgr))
    {
    	F_REENTRY_EXIT(VIDEO_CORE_ADD_TAIL_OF_RING_BUFFER);
        return KAL_FALSE;
    }

    u4Temp = prBufferMgr->u4Tail;
    if (u4Temp == 0)
    {
        u4Temp = prBufferMgr->u4MaxNumberofAtoms-1;
    }
    else
    {
        u4Temp--;
    }

    prBufferMgr->u4Tail = u4Temp;
    prBufferMgr->u4NumberOfAtoms++;

    F_REENTRY_EXIT(VIDEO_CORE_ADD_TAIL_OF_RING_BUFFER);
    return KAL_TRUE;
}

/******************************************************************************
* Copy the data pointed to by prNewAtom to the atom pointed by pu1HeadAtom
*
* Context:
*
* Side effect:
******************************************************************************/
kal_bool VideoCoreInsertToTailofRingBuffer(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr, // The ring buffer manager, allocated by user
    kal_uint8 *pu1NewAtom                       // A new atom to be inserted to the head of the ring buffer
)
{
    kal_uint8* pu1HeadAtom;
    
	F_REENTRY_ENTER(VIDEO_CORE_INSERT_TO_TAIL_OF_RING_BUFFER);

    if ((pu1NewAtom != NULL)
        &&(prBufferMgr != NULL)
        &&(prBufferMgr->fgInitialized == KAL_TRUE))
    {
        pu1HeadAtom = VideoCoreGetNextTailofRingBufferAddr(prBufferMgr);
        if(NULL != pu1HeadAtom)
        {
            kal_mem_cpy((void*)(pu1HeadAtom), (void*)(pu1NewAtom), prBufferMgr->u4SizeOfAnAtom);  // Store new atom
            VideoCoreAddTailofRingBuffer(prBufferMgr);
            F_REENTRY_EXIT(VIDEO_CORE_INSERT_TO_TAIL_OF_RING_BUFFER);
            return KAL_TRUE;
        }
    }
    else
    {
        ASSERT(0);
        F_REENTRY_EXIT(VIDEO_CORE_INSERT_TO_TAIL_OF_RING_BUFFER);
        return KAL_FALSE;
    }

    F_REENTRY_EXIT(VIDEO_CORE_INSERT_TO_TAIL_OF_RING_BUFFER);
    return KAL_FALSE;
}

#ifdef __VE_MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

//#endif /*__VE_VIDEO_ARCHI_V2__*/

