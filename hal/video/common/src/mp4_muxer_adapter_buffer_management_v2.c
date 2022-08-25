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
 *   mp4_muxer_adapter_buffer_management_v2.c
 *
 * Project:
 * --------
 *   MAUI
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
 ****************************************************************************/
#include "drv_features_video.h"

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VEENC_ROCODE", rodata = "DYNAMIC_CODE_VEENC_RODATA"
#endif

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_SUPPORT_MP4_MUXER_ADAPTER__

#include "vcodec_v2_trc.h"
#include "video_buffer_management_v2.h"
#include "mp4_muxer_adapter_v2.h"
#include "mp4_muxer_adapter_buffer_management_v2.h"

extern kal_uint32 u4VideoWriteThreshold;

/**
 * Initialize bitstream buffer control
 */
void MP4_InitBitBuffer(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr)
{
    kal_mem_set(prBitCtrlMgr, 0, sizeof(*prBitCtrlMgr));
}


/**
 * Add bit-stream information into the bit-stream control uints.
 */
kal_bool MP4_AddBitBuffer(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr,
        kal_uint32 u4Addr, kal_uint32 u4Size)
{
    MP4_BIT_CTRL_UNIT_T *prBitCtrlUnit = NULL;
    kal_uint32 u4FreeEntries, u4FreeSpace, u4ConsumedSize;
    kal_bool fgRet = KAL_FALSE;

    drv_trace2(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_ADD_INPUT, u4Addr, u4Size);

    MP4_ASSERT(prBitCtrlMgr->u4ReadIdx < MP4_BITSTREAM_CTRL_NUM);
    MP4_ASSERT(prBitCtrlMgr->u4WriteIdx < MP4_BITSTREAM_CTRL_NUM);
    MP4_ASSERT((prBitCtrlMgr->u4Entries + MP4_MAX_WASTED_BIT_CTRL_UNITS) <= MP4_BITSTREAM_CTRL_NUM);

    prBitCtrlMgr->u4BitstreamTotalSize += u4Size;

    // Calculate (not exactly) the free space for the accommodation of the input data.
    u4FreeEntries = MP4_BITSTREAM_CTRL_NUM - (prBitCtrlMgr->u4Entries + MP4_MAX_WASTED_BIT_CTRL_UNITS);
    u4FreeSpace = u4FreeEntries * u4VideoWriteThreshold;

    // Check whether bitstream control is overflow?
    if (u4Size > u4FreeSpace)
    {
        drv_trace4(TRACE_GROUP_10, MUX_MP4AL_BIT_BUFFER_FULL,
            prBitCtrlMgr->u4ReadIdx, prBitCtrlMgr->u4WriteIdx, u4FreeSpace, u4Size);
        fgRet = KAL_FALSE;
    }
    else
    {
        /* There are enough space in the bit-stream buffer control unit to
           accommodate the input data. */
        while (u4Size > 0)
        {
            prBitCtrlUnit = &prBitCtrlMgr->arBitCtrlUnit[prBitCtrlMgr->u4WriteIdx];

            // new control unit
            if (prBitCtrlUnit->u4Size == 0)
            {
                // Update prBitCtrlUnit->u4StartAddr in this case!
                MP4_ASSERT(prBitCtrlUnit->u4StartAddr == 0);
                MP4_ASSERT(prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_NOT_USED);

                // The size is larger than threshold
                if (u4Size >= (u4VideoWriteThreshold - prBitCtrlMgr->u4BitStreamOffset))
                {
                    u4ConsumedSize = u4VideoWriteThreshold - prBitCtrlMgr->u4BitStreamOffset;
                    prBitCtrlMgr->u4BitStreamOffset = 0;

                    prBitCtrlUnit->u4Size = u4ConsumedSize;
                    prBitCtrlUnit->u4StartAddr = u4Addr;
                    prBitCtrlUnit->eStatus = MP4_BIT_CTRL_UNIT_TO_BE_WRITTEN;

                    drv_trace8(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_ADD_WRITTEN,
                        prBitCtrlUnit->u4StartAddr, prBitCtrlUnit->u4Size,
                        prBitCtrlUnit->u4StartAddr + prBitCtrlUnit->u4Size,
                        prBitCtrlMgr->u4ReadIdx, prBitCtrlMgr->u4WriteIdx, u4ConsumedSize,
                        __LINE__, 0);

                    prBitCtrlMgr->u4Entries++;
                    prBitCtrlMgr->u4WriteIdx = (prBitCtrlMgr->u4WriteIdx + 1) % MP4_BITSTREAM_CTRL_NUM;
                    MP4_ASSERT(prBitCtrlMgr->u4ReadIdx != prBitCtrlMgr->u4WriteIdx);
                }
                else
                {
                    u4ConsumedSize = u4Size;
                    prBitCtrlUnit->u4Size = u4ConsumedSize;
                    prBitCtrlUnit->u4StartAddr = u4Addr;
                    prBitCtrlUnit->eStatus = MP4_BIT_CTRL_UNIT_TO_BE_COLLECTED;

                    drv_trace8(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_ADD_COLLECT,
                        prBitCtrlUnit->u4StartAddr, prBitCtrlUnit->u4Size,
                        prBitCtrlUnit->u4StartAddr + prBitCtrlUnit->u4Size,
                        prBitCtrlMgr->u4ReadIdx, prBitCtrlMgr->u4WriteIdx, u4ConsumedSize,
                        __LINE__, 0);
                }
            }
            else    // Append buffer to existed control unit
            {
                MP4_ASSERT(prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_TO_BE_COLLECTED);
                MP4_ASSERT(prBitCtrlUnit->u4Size < (u4VideoWriteThreshold - prBitCtrlMgr->u4BitStreamOffset));

                // bitstream reach to end
                if ((prBitCtrlUnit->u4StartAddr + prBitCtrlUnit->u4Size) != u4Addr)
                {
                    u4ConsumedSize = 0;
                    prBitCtrlMgr->u4BitStreamOffset = 0;
                    drv_trace8(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_ADD_OLD,
                        prBitCtrlUnit->u4StartAddr, prBitCtrlUnit->u4Size,
                        prBitCtrlUnit->u4StartAddr + prBitCtrlUnit->u4Size,
                        prBitCtrlMgr->u4ReadIdx, prBitCtrlMgr->u4WriteIdx, u4ConsumedSize,
                        __LINE__, 0);

                    prBitCtrlUnit->eStatus = MP4_BIT_CTRL_UNIT_TO_BE_WRITTEN;
                    prBitCtrlMgr->u4Entries++;
                    prBitCtrlMgr->u4WriteIdx = (prBitCtrlMgr->u4WriteIdx + 1) % MP4_BITSTREAM_CTRL_NUM;
                    MP4_ASSERT(prBitCtrlMgr->u4ReadIdx != prBitCtrlMgr->u4WriteIdx);
                    continue;
                }
                else
                {
                    // Do not update prBitCtrlUnit->u4StartAddr in this case!
                    if (u4Size >= (u4VideoWriteThreshold - prBitCtrlUnit->u4Size - prBitCtrlMgr->u4BitStreamOffset))
                    {
                        u4ConsumedSize = u4VideoWriteThreshold - prBitCtrlUnit->u4Size - prBitCtrlMgr->u4BitStreamOffset;
                        prBitCtrlMgr->u4BitStreamOffset = 0;
                        prBitCtrlUnit->u4Size += u4ConsumedSize;
                        prBitCtrlUnit->eStatus = MP4_BIT_CTRL_UNIT_TO_BE_WRITTEN;

                        drv_trace8(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_ADD_WRITTEN,
                            prBitCtrlUnit->u4StartAddr, prBitCtrlUnit->u4Size,
                            prBitCtrlUnit->u4StartAddr + prBitCtrlUnit->u4Size,
                            prBitCtrlMgr->u4ReadIdx, prBitCtrlMgr->u4WriteIdx, u4ConsumedSize,
                            __LINE__, 0);

                        prBitCtrlMgr->u4Entries++;
                        prBitCtrlMgr->u4WriteIdx = (prBitCtrlMgr->u4WriteIdx + 1) % MP4_BITSTREAM_CTRL_NUM;
                        MP4_ASSERT(prBitCtrlMgr->u4ReadIdx != prBitCtrlMgr->u4WriteIdx);
                    }
                    else
                    {
                        u4ConsumedSize = u4Size;
                        prBitCtrlUnit->u4Size += u4ConsumedSize;
                        drv_trace8(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_ADD_COLLECT,
                            prBitCtrlUnit->u4StartAddr, prBitCtrlUnit->u4Size,
                            prBitCtrlUnit->u4StartAddr + prBitCtrlUnit->u4Size,
                            prBitCtrlMgr->u4ReadIdx, prBitCtrlMgr->u4WriteIdx, u4ConsumedSize,
                            __LINE__, 0);
                        MP4_ASSERT(prBitCtrlUnit->u4Size < u4VideoWriteThreshold);
                        MP4_ASSERT(prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_TO_BE_COLLECTED);
                    }
                }
            }
            u4Size -= u4ConsumedSize;
            u4Addr += u4ConsumedSize;
            fgRet = KAL_TRUE;
        }
    }

    return fgRet;
}


/**
 * Query the bitstream control if there is any control unit to write to disk.
 * Note that the Read pointer (RP) is not updated.
 */
kal_bool MP4_QueryBitBufferStatus(MP4_BIT_CTRL_MGR_T * const prBitCtrlMgr)
{
    kal_uint32 u4ReadIdx;
    kal_bool fgFound = KAL_FALSE;

    MP4_ASSERT(prBitCtrlMgr->u4ReadIdx < MP4_BITSTREAM_CTRL_NUM);
    MP4_ASSERT(prBitCtrlMgr->u4WriteIdx < MP4_BITSTREAM_CTRL_NUM);
    u4ReadIdx = prBitCtrlMgr->u4ReadIdx;

    while (u4ReadIdx != prBitCtrlMgr->u4WriteIdx)
    {
        MP4_BIT_CTRL_UNIT_T *prBitCtrlUnit = NULL;
        prBitCtrlUnit = &prBitCtrlMgr->arBitCtrlUnit[u4ReadIdx];
        if (prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_TO_BE_WRITTEN)
        {
            fgFound = KAL_TRUE;
            drv_trace4(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_QUERY,
                prBitCtrlUnit->u4StartAddr, prBitCtrlUnit->u4Size,
                u4ReadIdx, prBitCtrlMgr->u4WriteIdx);
            break;
        }
        u4ReadIdx = (u4ReadIdx + 1) % MP4_BITSTREAM_CTRL_NUM;
    }
    if (fgFound == KAL_FALSE)
    {
        drv_trace2(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_QUERY_NONE,
            prBitCtrlMgr->u4ReadIdx, prBitCtrlMgr->u4WriteIdx);
    }

    return fgFound;
}


/**
 * Get one unit of bit-stream info from the bit-stream info buffer.
 * Note that the Read pointer (RP) is not updated.
 */
kal_bool MP4_GetBitBuffer(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr,
        kal_uint8 **pu1Addr, kal_uint32 *pu4Size)
{
    kal_uint32 u4ReadIdx;
    kal_bool fgFound = KAL_FALSE;

    MP4_ASSERT(prBitCtrlMgr->u4ReadIdx < MP4_BITSTREAM_CTRL_NUM);
    MP4_ASSERT(prBitCtrlMgr->u4WriteIdx < MP4_BITSTREAM_CTRL_NUM);

    u4ReadIdx = prBitCtrlMgr->u4ReadIdx;
    while (u4ReadIdx != prBitCtrlMgr->u4WriteIdx)
    {
        MP4_BIT_CTRL_UNIT_T *prBitCtrlUnit = NULL;
        prBitCtrlUnit = &prBitCtrlMgr->arBitCtrlUnit[u4ReadIdx];
        if (prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_TO_BE_WRITTEN)
        {
            *pu1Addr = (kal_uint8*)prBitCtrlUnit->u4StartAddr;
            *pu4Size = prBitCtrlUnit->u4Size;

            MP4_ASSERT(*pu1Addr != NULL);
            MP4_ASSERT(*pu4Size > 0);

            prBitCtrlUnit->eStatus = MP4_BIT_CTRL_UNIT_TO_BE_FREED;
            fgFound = KAL_TRUE;

            drv_trace4(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_GET,
                prBitCtrlUnit->u4StartAddr, prBitCtrlUnit->u4Size,
                u4ReadIdx, prBitCtrlMgr->u4WriteIdx);
            break;
        }
        u4ReadIdx = (u4ReadIdx + 1) % MP4_BITSTREAM_CTRL_NUM;
    }
    if (fgFound == KAL_FALSE)
    {
        *pu1Addr = NULL;
        *pu4Size = 0;
        drv_trace2(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_GET_NONE,
            prBitCtrlMgr->u4ReadIdx, prBitCtrlMgr->u4WriteIdx);
    }

    return fgFound;

}


/**
 * Get one unit of bit-stream info which can be freed
 * Note that the Read pointer (RP) is not updated.
 */
kal_bool MP4_QueryFreedBitBuffer(MP4_BIT_CTRL_MGR_T *const prBitCtrlMgr,
        kal_uint8 **pu1Addr, kal_uint32 *pu4Size)
{
    MP4_BIT_CTRL_UNIT_T *prBitCtrlUnit = NULL;
    kal_bool fgRet = KAL_FALSE;

    MP4_ASSERT(prBitCtrlMgr->u4ReadIdx < MP4_BITSTREAM_CTRL_NUM);
    MP4_ASSERT(prBitCtrlMgr->u4WriteIdx < MP4_BITSTREAM_CTRL_NUM);
    if (prBitCtrlMgr->u4ReadIdx == prBitCtrlMgr->u4WriteIdx)
    {
        *pu1Addr = NULL;
        *pu4Size = 0;
        drv_trace1(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_EMPTY, __LINE__);
    }
    else
    {
        prBitCtrlUnit = &prBitCtrlMgr->arBitCtrlUnit[prBitCtrlMgr->u4ReadIdx];
        drv_trace1(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_FIRST_CONTROL_UNIT_STATUS,
            (kal_uint32)prBitCtrlUnit->eStatus);
        if (prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_TO_BE_FREED)
        {
            MP4_ASSERT(prBitCtrlUnit->u4StartAddr != 0);
            MP4_ASSERT(prBitCtrlUnit->u4Size != 0);
            *pu1Addr = (kal_uint8*)prBitCtrlUnit->u4StartAddr;
            *pu4Size = prBitCtrlUnit->u4Size;
            fgRet = KAL_TRUE;
        }
    }

    return fgRet;
}


/**
 * Mark all bitstream buffer status to "TO_BE_WRITTEN"
 */
kal_bool MP4_MarkBitBufferForFlush(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr)
{
    MP4_BIT_CTRL_UNIT_T *prBitCtrlUnit = NULL;
    kal_uint32 u4ReadIdx;
    kal_bool fgRet = KAL_FALSE;


    MP4_ASSERT(prBitCtrlMgr->u4ReadIdx < MP4_BITSTREAM_CTRL_NUM);
    MP4_ASSERT(prBitCtrlMgr->u4WriteIdx < MP4_BITSTREAM_CTRL_NUM);

    drv_trace1(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_MARK_FOR_FLUSH_WRITE_INDEX,
        prBitCtrlMgr->u4WriteIdx);

    // Scan from the current READ INDEX to WRITE INDEX for data to be flushed.
    u4ReadIdx = prBitCtrlMgr->u4ReadIdx;
    while (1)
    {
        prBitCtrlUnit = &prBitCtrlMgr->arBitCtrlUnit[u4ReadIdx];
        drv_trace4(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_MARK_FOR_FLUSH,
            prBitCtrlUnit->u4StartAddr, prBitCtrlUnit->u4Size,
            prBitCtrlUnit->eStatus, u4ReadIdx);
        if (u4ReadIdx == prBitCtrlMgr->u4WriteIdx)
        {
            if (prBitCtrlUnit->u4Size > 0)
            {
                MP4_ASSERT(prBitCtrlUnit->u4StartAddr != 0);
                MP4_ASSERT(prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_TO_BE_COLLECTED);
                prBitCtrlUnit->eStatus = MP4_BIT_CTRL_UNIT_TO_BE_WRITTEN;
                // Update the WRITE INDEX.
                prBitCtrlMgr->u4Entries++;
                prBitCtrlMgr->u4WriteIdx = (prBitCtrlMgr->u4WriteIdx + 1) % MP4_BITSTREAM_CTRL_NUM;
                MP4_ASSERT(prBitCtrlMgr->u4ReadIdx != prBitCtrlMgr->u4WriteIdx);
                // Because at least 1 entry and at most 2 entries are wasted,
                // the ASSERT above should never happen.
                fgRet = KAL_TRUE;
            }
            break;
        }
        else
        {
            if (prBitCtrlUnit->u4Size > 0)
            {
                if (prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_TO_BE_FREED)
                {
                    drv_trace0(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_FREE_SLOT);
                }
                else
                {
                    MP4_ASSERT(prBitCtrlUnit->u4StartAddr != 0);
                    MP4_ASSERT((prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_TO_BE_WRITTEN) ||
                        (prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_TO_BE_COLLECTED));
                    prBitCtrlUnit->eStatus = MP4_BIT_CTRL_UNIT_TO_BE_WRITTEN;
                    fgRet = KAL_TRUE;
                }
            }
        }
        u4ReadIdx = (u4ReadIdx + 1) % MP4_BITSTREAM_CTRL_NUM;
    }

    return fgRet;
}


/**
 * Clear the first control unit, and update the Read pointer (RP).
 */
void MP4_FreeBitBufferUnit(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr)
{
    MP4_BIT_CTRL_UNIT_T *prBitCtrlUnit = NULL;

    MP4_ASSERT(prBitCtrlMgr->u4ReadIdx < MP4_BITSTREAM_CTRL_NUM);
    MP4_ASSERT(prBitCtrlMgr->u4WriteIdx < MP4_BITSTREAM_CTRL_NUM);
    if (prBitCtrlMgr->u4ReadIdx == prBitCtrlMgr->u4WriteIdx)
    {
        MP4_ASSERT(0);
    }
    prBitCtrlUnit = &prBitCtrlMgr->arBitCtrlUnit[prBitCtrlMgr->u4ReadIdx];
    drv_trace4(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_FREE,
        prBitCtrlUnit->u4StartAddr, prBitCtrlUnit->u4Size,
        prBitCtrlMgr->u4ReadIdx, prBitCtrlMgr->u4WriteIdx);
    MP4_ASSERT(prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_TO_BE_FREED);

    // Reset control unit
    kal_mem_set(prBitCtrlUnit, 0, sizeof(*prBitCtrlUnit));

    prBitCtrlMgr->u4Entries--;
    prBitCtrlMgr->u4ReadIdx = (prBitCtrlMgr->u4ReadIdx + 1) % MP4_BITSTREAM_CTRL_NUM;

    return;
}


/**
 * Mark the first control unit as "to be freed" if its status is "to be written".
 * This function is used when there is disk I/O error and bit stream buffer needs
 * to be returned to the Encoder component.
 */
void MP4_MarkFirstUnitOnError(MP4_BIT_CTRL_MGR_T *prBitCtrlMgr)
{
    MP4_BIT_CTRL_UNIT_T *prBitCtrlUnit = NULL;

    if (prBitCtrlMgr->u4ReadIdx >= MP4_BITSTREAM_CTRL_NUM) { MP4_ASSERT(0); }
    if (prBitCtrlMgr->u4WriteIdx >= MP4_BITSTREAM_CTRL_NUM) { MP4_ASSERT(0); }
    if (prBitCtrlMgr->u4ReadIdx == prBitCtrlMgr->u4WriteIdx)
    {
        drv_trace1(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_EMPTY, __LINE__);
    }
    else
    {
        prBitCtrlUnit = &prBitCtrlMgr->arBitCtrlUnit[prBitCtrlMgr->u4ReadIdx];
        drv_trace1(TRACE_GROUP_9, MUX_MP4AL_BIT_BUFFER_FIRST_CONTROL_UNIT_STATUS,
            (kal_uint32)prBitCtrlUnit->eStatus);
        if (prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_TO_BE_WRITTEN)
        {
            if (prBitCtrlUnit->u4StartAddr == 0) { MP4_ASSERT(0); }
            if (prBitCtrlUnit->u4Size == 0) { MP4_ASSERT(0); }
            prBitCtrlUnit->eStatus = MP4_BIT_CTRL_UNIT_TO_BE_FREED;
        }
    }
}

kal_uint32 MP4_QueryWrittenBufferCount(MP4_BIT_CTRL_MGR_T * const prBitCtrlMgr)
{
    kal_uint32 u4ReadIdx;
    kal_uint32 u4Count = 0;

    MP4_ASSERT(prBitCtrlMgr->u4ReadIdx < MP4_BITSTREAM_CTRL_NUM);
    MP4_ASSERT(prBitCtrlMgr->u4WriteIdx < MP4_BITSTREAM_CTRL_NUM);
    u4ReadIdx = prBitCtrlMgr->u4ReadIdx;

    while (u4ReadIdx != prBitCtrlMgr->u4WriteIdx)
    {
        MP4_BIT_CTRL_UNIT_T *prBitCtrlUnit = NULL;
        prBitCtrlUnit = &prBitCtrlMgr->arBitCtrlUnit[u4ReadIdx];
        if (prBitCtrlUnit->eStatus == MP4_BIT_CTRL_UNIT_TO_BE_WRITTEN)
        {
            u4Count++;
        }
        u4ReadIdx = (u4ReadIdx + 1) % MP4_BITSTREAM_CTRL_NUM;
    }

    return u4Count;
}


#endif  // __VE_SUPPORT_MP4_MUXER_ADAPTER__
#endif  // __VE_VIDEO_ARCHI_V2__

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

