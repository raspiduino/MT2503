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
 *   video_codec_schedule_control.c
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
#ifdef __VE_VIDEO_ARCHI_V2__
#include "vcodec_v2_trc.h"
#include "video_codec_schedule_control.h"
#include "video_types_v2.h"
#include "kal_trace.h"
#include "video_codec_utility_v2.h"
#include "video_codec_mem_v2.h"
#include "video_encoder_component_if_v2.h"
#include "video_dbg_v2.h"

#include "kal_general_types.h"
#include "kal_public_api.h"

#if 0
/* under construction !*/
/* under construction !*/
#endif

/******************************************************************************
* Static variable(s)
******************************************************************************/
static VCODEC_SCHEDULE_CTRL_T _rVCodecScheduleCtrl;


kal_bool _VideoCodecGetRingBufferNextAtomAddress(
    VIDEO_CORE_RING_BUFFER_MGR_T *prBufferMgr, // The ring buffer manager, allocated by user
    kal_uint8 *pu1CurrentAtom,
    kal_uint8 **ppu1NextAtom
)
{
    kal_uint32 i = 0;
    kal_uint8* pu1TempAddr = prBufferMgr->pu1Start;
    kal_uint8* pu1End = prBufferMgr->pu1Start + prBufferMgr->u4MaxNumberofAtoms * prBufferMgr->u4SizeOfAnAtom;

    ASSERT((prBufferMgr != NULL)
        &&(prBufferMgr->fgInitialized == KAL_TRUE));

    // Check if pu1CurrentAtom is one of the Atoms in the buffer
    for (i = 0; i < prBufferMgr->u4MaxNumberofAtoms; i++)
    {
        if (pu1TempAddr == pu1CurrentAtom)
        {
            break;
        }

        pu1TempAddr += prBufferMgr->u4SizeOfAnAtom;
        if (pu1TempAddr >= pu1End)
        {
            pu1TempAddr = prBufferMgr->pu1Start;
        }
    }

    ASSERT(i != prBufferMgr->u4MaxNumberofAtoms);

    // Get the next Atom
    pu1TempAddr += prBufferMgr->u4SizeOfAnAtom;
    if (pu1TempAddr >= pu1End)
    {
        pu1TempAddr = prBufferMgr->pu1Start;
    }
    *ppu1NextAtom = pu1TempAddr;

    return KAL_TRUE;
}

/******************************************************************************
*
******************************************************************************/
static void _VCodecCtrlUnifiedAddItem(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    kal_uint32 u4SavedMask;
    kal_bool fgValue;

    if(prBuffHeader == NULL)
    {
        drv_trace4(TRACE_GROUP_10, VDEC_ADD_JOB, eTaskMember, _rVCodecScheduleCtrl.rBufferMgr.u4NumberOfAtoms, 9999, 9999);
    }
    else
    {
        drv_trace4(TRACE_GROUP_10, VDEC_ADD_JOB, eTaskMember, _rVCodecScheduleCtrl.rBufferMgr.u4NumberOfAtoms, prBuffHeader->u8TimeStamp, (kal_uint32) prBuffHeader->pu1Buffer);
    }

    if(VCS_SCENARIO_NONE == _rVCodecScheduleCtrl.eScenario)
    {
        ASSERT(0);
    }
    else if (VCS_DECODER_ONLY == _rVCodecScheduleCtrl.eScenario)
    {
        ASSERT(eTaskMember == VCS_DECODER);
    }
    else if(VCS_ENCODER_ONLY == _rVCodecScheduleCtrl.eScenario)
    {
        ASSERT(eTaskMember == VCS_ENCODER);
    }

#ifdef _VCS_DEBUG_
    if(prBuffHeader != NULL)
    {
        kal_uint32 uIndex;
        u4SavedMask = SaveAndSetIRQMask();
        // critical section

        uIndex = eTaskMember - 1;
        _rVCodecScheduleCtrl.arTimeStamp[uIndex][_rVCodecScheduleCtrl.uWrite[uIndex]] = prBuffHeader->u8TimeStamp;
        _rVCodecScheduleCtrl.apu1Buffer[uIndex][_rVCodecScheduleCtrl.uWrite[uIndex]] = prBuffHeader->pu1Buffer;
        if(_rVCodecScheduleCtrl.uWrite[uIndex] >= VCodecScheduleCtrlRingbufferSize -1)
            _rVCodecScheduleCtrl.uWrite[uIndex] = 0;
        else
            _rVCodecScheduleCtrl.uWrite[uIndex]++;

        // ~critical section
        RestoreIRQMask(u4SavedMask);
    }
#endif
#if 0
/* under construction !*/
#else
    // critical section
    u4SavedMask = SaveAndSetIRQMask();
    fgValue = VideoCoreInsertToHeadofRingBuffer(&_rVCodecScheduleCtrl.rBufferMgr, (kal_uint8*)(&eTaskMember));
    RestoreIRQMask(u4SavedMask);
    // ~critical section

    ASSERT(fgValue);
#endif
    _rVCodecScheduleCtrl.i4Item[eTaskMember]++;
    return;
}


/******************************************************************************
*
******************************************************************************/
static void _VCodecCtrlUnifiedCleanItem(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VCODEC_SCHEDULE_TASK_MEMBER_T* peAtom = NULL;
    kal_uint8* pu1AtomAddr = NULL;
    kal_uint32 u4SavedMask;

    if(prBuffHeader == NULL)
    {
        drv_trace4(TRACE_GROUP_10, VDEC_CLEAN_JOB, eTaskMember, _rVCodecScheduleCtrl.rBufferMgr.u4NumberOfAtoms, 9999, 9999);
    }
    else
    {
        drv_trace4(TRACE_GROUP_10, VDEC_CLEAN_JOB, eTaskMember, _rVCodecScheduleCtrl.rBufferMgr.u4NumberOfAtoms, prBuffHeader->u8TimeStamp, (kal_uint32) prBuffHeader->pu1Buffer);
    }

    if(VCS_SCENARIO_NONE == _rVCodecScheduleCtrl.eScenario)
    {
        ASSERT(0);
    }
    else if (VCS_DECODER_ONLY == _rVCodecScheduleCtrl.eScenario)
    {
        ASSERT(eTaskMember == VCS_DECODER);
    }
    else if(VCS_ENCODER_ONLY == _rVCodecScheduleCtrl.eScenario)
    {
        ASSERT(eTaskMember == VCS_ENCODER);
    }

#ifdef  _VCS_DEBUG_
    if(prBuffHeader != NULL)
    {
        kal_uint32 uIndex;

        u4SavedMask = SaveAndSetIRQMask();
        // critical section

        uIndex = eTaskMember - 1;
//        ASSERT(prBuffHeader->u8TimeStamp == _rVCodecScheduleCtrl.arTimeStamp[uIndex][_rVCodecScheduleCtrl.uRead[uIndex]]);
        ASSERT(prBuffHeader->pu1Buffer== _rVCodecScheduleCtrl.apu1Buffer[uIndex][_rVCodecScheduleCtrl.uRead[uIndex]]);

        if(_rVCodecScheduleCtrl.uRead[uIndex] >= VCodecScheduleCtrlRingbufferSize - 1)
            _rVCodecScheduleCtrl.uRead[uIndex] = 0;
        else
            _rVCodecScheduleCtrl.uRead[uIndex]++;

        _rVCodecScheduleCtrl.eLastItem = eTaskMember;

        // ~critical section
        RestoreIRQMask(u4SavedMask);
    }
#endif
#if 0
/* under construction !*/
#else
    pu1AtomAddr = VideoCoreGetTailofRingBufferAddr(&_rVCodecScheduleCtrl.rBufferMgr);
    if (pu1AtomAddr != NULL)
#endif
    {
        peAtom = (VCODEC_SCHEDULE_TASK_MEMBER_T*)(pu1AtomAddr);

        if (eTaskMember != *peAtom)
        {
            ASSERT(_rVCodecScheduleCtrl.eFlushItem == eTaskMember);
             _rVCodecScheduleCtrl.eFlushItem = VCS_NONE;
             return;
        }

        *peAtom = VCS_TASK_MEMBER_MAX;
#if 0
/* under construction !*/
#else
        {
        	  VCODEC_SCHEDULE_TASK_MEMBER_T eDummy;
            u4SavedMask = SaveAndSetIRQMask();// critical section
            _rVCodecScheduleCtrl.i4Item[eTaskMember]--;
            ASSERT(VideoCoreRemoveFromTailofRingBufferAddr(&_rVCodecScheduleCtrl.rBufferMgr, (kal_uint8 *)&eDummy));
            RestoreIRQMask(u4SavedMask);    // ~critical section
        }
#endif
    }
    else
    {
        ASSERT(0);
    }

    if(_rVCodecScheduleCtrl.i4Item[eTaskMember]<0)
    {
        ASSERT(0);
    }

    drv_trace2(TRACE_GROUP_10, VDEC_JOB_STAT, _rVCodecScheduleCtrl.i4Item[VCS_ENCODER], _rVCodecScheduleCtrl.i4Item[VCS_DECODER]);

    return;
}


/******************************************************************************
*
******************************************************************************/
static VCODEC_SCHEDULE_TASKQUEUE_T _VCodecCtrlUnifiedGetTaskControl(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember)
{
    VCODEC_SCHEDULE_TASK_MEMBER_T* peAtom = NULL;
    kal_uint8* pu1AtomAddr = NULL;


    drv_trace4(TRACE_GROUP_10, VDEC_GET_TASK, eTaskMember, _rVCodecScheduleCtrl.i4Item[eTaskMember], _rVCodecScheduleCtrl.arBuffer[_rVCodecScheduleCtrl.rBufferMgr.u4Tail], 0);
#if 0
/* under construction !*/
#else
    pu1AtomAddr = VideoCoreGetTailofRingBufferAddr(&_rVCodecScheduleCtrl.rBufferMgr);
    if(pu1AtomAddr != NULL)
#endif
    {
        peAtom = (VCODEC_SCHEDULE_TASK_MEMBER_T*)(pu1AtomAddr);

        ASSERT((*peAtom == VCS_ENCODER)||(*peAtom == VCS_DECODER));

        if (eTaskMember == *peAtom)
        {
            return VCS_TASKQUEUE_EXPECTED_TARGET;
        }
        else
        {
            void* pDummy = NULL;
            if (VCS_CODEC_BOTH == _rVCodecScheduleCtrl.eScenario)
            {
                if (eTaskMember == VCS_ENCODER)
                {
                    _rVCodecScheduleCtrl.pfnWakeupDEC(pDummy);
                }
                else if (eTaskMember == VCS_DECODER)
                {
                    _rVCodecScheduleCtrl.pfnWakeupENC(pDummy);
                }
            }
            return VCS_TASKQUEUE_NOT_EXPECTED_TARGET;
        }
    }
    else
    {
        return VCS_TASKQUEUE_EMPTY;
    }
}


/******************************************************************************
*
******************************************************************************/
static kal_int32 _VCodecCtrlUnifiedGetContItemNum(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember)
{
    VCODEC_SCHEDULE_TASK_MEMBER_T* peAtom = NULL;
    VCODEC_SCHEDULE_TASK_MEMBER_T* peNextAtom = NULL;
    kal_uint8* pu1AtomAddr = NULL;
    kal_uint8* pu1NextAtomAddr = NULL;
    kal_int32 i4Count = 0;
#if 0
/* under construction !*/
#else
    pu1AtomAddr = VideoCoreGetTailofRingBufferAddr(&_rVCodecScheduleCtrl.rBufferMgr);
    if(pu1AtomAddr == NULL)
    {
        return 0;
    }
#endif
    peAtom = (VCODEC_SCHEDULE_TASK_MEMBER_T*)(pu1AtomAddr);

    //ASSERT(*peAtom == eTaskMember);
    if (*peAtom != eTaskMember)
    {
        i4Count = 0;
        return i4Count;
    }
    else
    {
        i4Count++;
    }
#if 0
/* under construction !*/
#else
    _VideoCodecGetRingBufferNextAtomAddress(&_rVCodecScheduleCtrl.rBufferMgr, pu1AtomAddr, &pu1NextAtomAddr);
#endif
    peNextAtom = (VCODEC_SCHEDULE_TASK_MEMBER_T*)(pu1NextAtomAddr);

    while(*peNextAtom == eTaskMember)
    {
        // Enter the do-while loop indicates that at least one item is in the queue, so we do the ++ operation before checking next one
        i4Count++;

        pu1AtomAddr = pu1NextAtomAddr;
#if 0
/* under construction !*/
#else
        _VideoCodecGetRingBufferNextAtomAddress(&_rVCodecScheduleCtrl.rBufferMgr, pu1AtomAddr, &pu1NextAtomAddr);
#endif
        peNextAtom = (VCODEC_SCHEDULE_TASK_MEMBER_T*)(pu1NextAtomAddr);
    }


    if (i4Count == _rVCodecScheduleCtrl.rBufferMgr.u4NumberOfAtoms)
    {
        if (VCS_CODEC_BOTH == _rVCodecScheduleCtrl.eScenario)
        {
            i4Count = -1;    //For check resource blocking
        }
        else
        {
            i4Count = 0;    //Only the same task item in ringbuffer.
        }
    }

    return i4Count;
}


/******************************************************************************
*
******************************************************************************/
static void _VCodecCtrlUnifiedFlushItem(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember)
{
    kal_uint32 u4SavedMask;
    kal_uint32 u4Count;
    kal_uint32 i;
    VCODEC_SCHEDULE_TASK_MEMBER_T eKeepMember = VCS_NONE;

#ifdef _VCS_DEBUG_
    kal_uint32 uIndex = eTaskMember - 1;


    if(uIndex >= VCS_TASK_MEMBER_MAX )
    {
        ASSERT(0);
    }
    _rVCodecScheduleCtrl.uRead[uIndex] = 0;
    _rVCodecScheduleCtrl.uWrite[uIndex] = 0;

#endif

    if (_rVCodecScheduleCtrl.rBufferMgr.u4NumberOfAtoms == 0)
    {
        return;
    }

    drv_trace4(TRACE_GROUP_10, VDEC_FLUSHING_JOB,_rVCodecScheduleCtrl.i4Item[eTaskMember], eTaskMember, _rVCodecScheduleCtrl.rBufferMgr.u4NumberOfAtoms, (kal_uint32) _rVCodecScheduleCtrl.rBufferMgr.u4Head);

     _rVCodecScheduleCtrl.eFlushItem = eTaskMember;


    if ( _rVCodecScheduleCtrl.eFlushItem == VCS_ENCODER)
    {
        if (VCS_CODEC_BOTH == _rVCodecScheduleCtrl.eScenario)
        {
            eKeepMember = VCS_DECODER;
        }
        else
        {
            eKeepMember = VCS_NONE;
        }
    }
    else if ( _rVCodecScheduleCtrl.eFlushItem == VCS_DECODER)
    {
        if (VCS_CODEC_BOTH == _rVCodecScheduleCtrl.eScenario)
        {
            eKeepMember = VCS_ENCODER;
        }
        else
        {
            eKeepMember = VCS_NONE;
        }
    }
    else
    {
        ASSERT(0);
    }

    u4SavedMask = SaveAndSetIRQMask();
    // critical section

    u4Count = _rVCodecScheduleCtrl.rBufferMgr.u4NumberOfAtoms - _rVCodecScheduleCtrl.i4Item[eTaskMember];
    ASSERT(u4Count <= _rVCodecScheduleCtrl.rBufferMgr.u4MaxNumberofAtoms);

    _rVCodecScheduleCtrl.i4Item[VCS_ENCODER] = 0;
    _rVCodecScheduleCtrl.i4Item[VCS_DECODER] = 0;
#if 0
/* under construction !*/
/* under construction !*/
#else
    VideoCoreCleanRingBuffer(&_rVCodecScheduleCtrl.rBufferMgr);
#endif
    // ~critical section
    RestoreIRQMask(u4SavedMask);

    drv_trace1(TRACE_GROUP_10, VDEC_FLUSH_FLAG, _rVCodecScheduleCtrl.eFlushItem);

    if(eKeepMember != VCS_NONE)
    {
        for (i = 0; i < u4Count; i++)
        {
            _VCodecCtrlUnifiedAddItem(eKeepMember, NULL);
        }
    }

    drv_trace4(TRACE_GROUP_10, VDEC_FLUSHED_JOB, _rVCodecScheduleCtrl.i4Item[eTaskMember], eTaskMember,  _rVCodecScheduleCtrl.rBufferMgr.u4NumberOfAtoms, (kal_uint32)_rVCodecScheduleCtrl.rBufferMgr.u4Head);
    drv_trace2(TRACE_GROUP_10, VDEC_JOB_STAT, _rVCodecScheduleCtrl.i4Item[VCS_ENCODER], _rVCodecScheduleCtrl.i4Item[VCS_DECODER]);

    return;
}


/******************************************************************************
* Initialization
******************************************************************************/
void VCodecCtrlDeinit(void)
{
    VideoCoreDeInitRingBuffer(&_rVCodecScheduleCtrl.rBufferMgr);
    _rVCodecScheduleCtrl.fgInitRingBuffer   =   KAL_FALSE;
    _rVCodecScheduleCtrl.eScenario          =   VCS_SCENARIO_NONE;
    _rVCodecScheduleCtrl.eFlushItem         =   VCS_NONE;

    _rVCodecScheduleCtrl.pfnAddItem         =   NULL;
    _rVCodecScheduleCtrl.pfnCleanItem       =   NULL;
    _rVCodecScheduleCtrl.pfnGetTaskCtrl     =   NULL;
    _rVCodecScheduleCtrl.pfnGetContItemNum  =   NULL;
    _rVCodecScheduleCtrl.pfnFlushItem       =   NULL;
}


/******************************************************************************
*
******************************************************************************/
kal_bool VCodecCtrlInit(VCODEC_SCHEDULE_SCENARIO_T eScenario)
{
    if (_rVCodecScheduleCtrl.eScenario == VCS_SCENARIO_NONE)
    {
        kal_mem_set((void*)&_rVCodecScheduleCtrl, 0, sizeof(VCODEC_SCHEDULE_CTRL_T));
    }

    _rVCodecScheduleCtrl.eScenario = eScenario;

    if (KAL_FALSE == _rVCodecScheduleCtrl.fgInitRingBuffer)
    {
        // Initialize ring buffer
        // Note that the init function would set all the elements to 0, which is VCS_NONE in this case
#if 0
/* under construction !*/
/* under construction !*/
#else
        VideoCoreInitRingBuffer(&_rVCodecScheduleCtrl.rBufferMgr, &_rVCodecScheduleCtrl.arBuffer[0], VCodecScheduleCtrlRingbufferSize, sizeof(VCODEC_SCHEDULE_TASK_MEMBER_T));
#endif
        _rVCodecScheduleCtrl.eFlushItem = VCS_NONE;
        _rVCodecScheduleCtrl.fgInitRingBuffer = KAL_TRUE;
    }

    _rVCodecScheduleCtrl.pfnAddItem = _VCodecCtrlUnifiedAddItem;
    _rVCodecScheduleCtrl.pfnCleanItem = _VCodecCtrlUnifiedCleanItem;
    _rVCodecScheduleCtrl.pfnGetTaskCtrl = _VCodecCtrlUnifiedGetTaskControl;
    _rVCodecScheduleCtrl.pfnGetContItemNum = _VCodecCtrlUnifiedGetContItemNum;
    _rVCodecScheduleCtrl.pfnFlushItem= _VCodecCtrlUnifiedFlushItem;

    return KAL_TRUE;
}

/**********************************************************
*
*   Interface between schedule control and enc/dec
*
**********************************************************/

/******************************************************************************
*
******************************************************************************/
#ifdef __VE_VCODEC_TASK_CONTROL__
void VCodecCtrlRegister(VCODEC_SCHEDULE_TASK_MEMBER_T eMember, PFN_VCODEC_WAKEUP_T pfnWakeUp)
{
#ifdef _VCS_DEBUG_
    kal_uint32 uCount = 0;
    kal_uint32 uIndex = 0;

    switch(eMember)
    {
        case VCS_ENCODER:
        case VCS_DECODER:
            uIndex = eMember - 1;
            break;
        default:
            ASSERT(0);
    };

    if(uIndex >= VCS_TASK_MEMBER_MAX)
    {
        ASSERT(0);
    }
    _rVCodecScheduleCtrl.uRead[uIndex] = 0;
    _rVCodecScheduleCtrl.uWrite[uIndex] = 0;
    for(uCount = 0; uCount < VCodecScheduleCtrlRingbufferSize; uCount++)
    {
        _rVCodecScheduleCtrl.arTimeStamp[uIndex][uCount] = 0;
        _rVCodecScheduleCtrl.apu1Buffer[uIndex][uCount] = 0;
    }

        _rVCodecScheduleCtrl.eLastItem= VCS_NONE;
#endif

    drv_trace2(TRACE_GROUP_10, VCSC_REG, _rVCodecScheduleCtrl.eScenario, eMember);

    switch(eMember){
    case VCS_ENCODER:
        if (VCS_SCENARIO_NONE == _rVCodecScheduleCtrl.eScenario)
        {
            // Schedule control is un-initialized, initialized as recorder
            VCodecCtrlInit(VCS_ENCODER_ONLY);
        }
        else if (VCS_DECODER_ONLY == _rVCodecScheduleCtrl.eScenario)
        {
            // Re-initialized as Video call schedule control
            VCodecCtrlInit(VCS_CODEC_BOTH);
        }
        else
        {
            ASSERT(0);
        }
        _rVCodecScheduleCtrl.pfnWakeupENC = pfnWakeUp;
    break;

    case VCS_DECODER:
        if (VCS_SCENARIO_NONE == _rVCodecScheduleCtrl.eScenario)
        {
            // Schedule control is un-initialized, initialized as player
            VCodecCtrlInit(VCS_DECODER_ONLY);
        }
        else if (VCS_ENCODER_ONLY == _rVCodecScheduleCtrl.eScenario)
        {
            // Re-initialized as Video call schedule control
            VCodecCtrlInit(VCS_CODEC_BOTH);
        }
        else
        {
            ASSERT(0);
        }
        _rVCodecScheduleCtrl.pfnWakeupDEC = pfnWakeUp;
    break;

    default:
        ASSERT(0);
    break;
    };
}
#endif

/******************************************************************************
*
******************************************************************************/
#ifdef __VE_VCODEC_TASK_CONTROL__
void VCodecCtrlDeRegister(VCODEC_SCHEDULE_TASK_MEMBER_T eMember)
{
    drv_trace2(TRACE_GROUP_10, VCSC_DEREG, _rVCodecScheduleCtrl.eScenario, eMember);
    switch(eMember){
    case VCS_ENCODER:
        ASSERT(_rVCodecScheduleCtrl.i4Item[VCS_ENCODER] == 0);
        if (VCS_ENCODER_ONLY == _rVCodecScheduleCtrl.eScenario)
        {
            VCodecCtrlDeinit();
        }
        else if (VCS_CODEC_BOTH == _rVCodecScheduleCtrl.eScenario)
        {
            _rVCodecScheduleCtrl.eScenario = VCS_DECODER_ONLY;
        }
        else
        {
            ASSERT(0);
        }
        _rVCodecScheduleCtrl.pfnWakeupENC = NULL;
    break;

    case VCS_DECODER:
        ASSERT(_rVCodecScheduleCtrl.i4Item[VCS_DECODER] == 0);
        if (VCS_DECODER_ONLY == _rVCodecScheduleCtrl.eScenario)
        {
            VCodecCtrlDeinit();
        }
        else if (VCS_CODEC_BOTH == _rVCodecScheduleCtrl.eScenario)
        {
            _rVCodecScheduleCtrl.eScenario = VCS_ENCODER_ONLY;
        }
        else
        {
            ASSERT(0);
        }
        _rVCodecScheduleCtrl.pfnWakeupDEC = NULL;
    break;

    default:
        ASSERT(0);
    break;
    };
}
#endif

/******************************************************************************
* Context: This function runs in the context of MED, IDP_VR1
* Function Attribute: Re-entry, Race condition
******************************************************************************/
#ifdef __VE_VCODEC_TASK_CONTROL__
void VCodecCtrlAddItem(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_START_LOGGING("CSR");
    _rVCodecScheduleCtrl.pfnAddItem(eTaskMember, prBuffHeader);
    VIDEO_STOP_LOGGING("CSR");
}
#endif


/******************************************************************************
* Context: This function runs in the context of V2DEC.
* Function Attribute: No re-entry, no race condition
******************************************************************************/
#ifdef __VE_VCODEC_TASK_CONTROL__
void VCodecCtrlCleanItem(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_START_LOGGING("CSR");
    _rVCodecScheduleCtrl.pfnCleanItem(eTaskMember, prBuffHeader);
    VIDEO_STOP_LOGGING("CSR");
}
#endif


/******************************************************************************
* Context: This function runs in the context of V2DEC.
* Function Attribute: No re-entry, no race condition
******************************************************************************/
#ifdef __VE_VCODEC_TASK_CONTROL__
void VCodecCtrlMoveItem(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember)
{
    VIDEO_START_LOGGING("CSR");
    _rVCodecScheduleCtrl.pfnAddItem(eTaskMember, NULL);
    _rVCodecScheduleCtrl.pfnCleanItem(eTaskMember, NULL);
    VIDEO_STOP_LOGGING("CSR");
}
#endif

/******************************************************************************
* Context: This function runs in the context of V2DEC.
* Function Attribute: No re-entry, no race condition
******************************************************************************/
#ifdef __VE_VCODEC_TASK_CONTROL__
VCODEC_SCHEDULE_TASKQUEUE_T VCodecCtrlGetTaskControl(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember)
{
    VCODEC_SCHEDULE_TASKQUEUE_T fgresult = VCS_TASKQUEUE_EMPTY;

    VIDEO_START_LOGGING("CSR");
    fgresult = _rVCodecScheduleCtrl.pfnGetTaskCtrl(eTaskMember);
    VIDEO_STOP_LOGGING("CSR");

    return fgresult;
}
#endif


/******************************************************************************
* Context: This function runs in the context of V2DEC.
******************************************************************************/
#ifdef __VE_VCODEC_TASK_CONTROL__
kal_int32 VCodecCtrlGetContinuousItemNum(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember)
{
    kal_int32 i4Result = 0;

    VIDEO_START_LOGGING("CSR");
    i4Result = _rVCodecScheduleCtrl.pfnGetContItemNum(eTaskMember);
    VIDEO_STOP_LOGGING("CSR");

    return i4Result;
}
#endif


/******************************************************************************
* Context: This function runs in the context of V2DEC.
******************************************************************************/
#ifdef __VE_VCODEC_TASK_CONTROL__
void VCodecFlushItem(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember)
{
    drv_trace1(TRACE_GROUP_10,VCSC_FLUSH, eTaskMember);

    VIDEO_START_LOGGING("CSR");
    _rVCodecScheduleCtrl.pfnFlushItem(eTaskMember);
    VIDEO_STOP_LOGGING("CSR");
}
#endif


#endif /*__VE_VIDEO_ARCHI_V2__*/

