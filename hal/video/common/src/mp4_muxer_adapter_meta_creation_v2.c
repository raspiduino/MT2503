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
 *   mp4_muxer_adapter_meta_creation_v2.c
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
#include "drv_features_video.h"

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VEENC_ROCODE", rodata = "DYNAMIC_CODE_VEENC_RODATA"
#endif

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_SUPPORT_MP4_MUXER_ADAPTER__

#include "dcl.h"
#include "vcodec_enc_demuxer_if.h"
#include "vcodec_v2_trc.h"
#include "video_buffer_management_v2.h"
#include "mp4_muxer_adapter_meta_creation_v2.h"

/******************************************************************************
* Internal macro definition
******************************************************************************/
#define MP4_RECORDER_ADJUST_TIMESTAMP_OF_FIRST_FRAME

#define MP4_VIDEO_TRACK_ID          1
#define MP4_VOS_MAX_LENGTH          100

#define AUDIO_FRAMEINFO_SIZE        8
#define AUDIO_FRAMEINFO_WORD_SIZE   2
#define FRAME_SIZE                  0
#define FRAME_COUNT                 1

#define PROCESS_STOP_TIME_STATUS_SUCCEED 0x4B4F4B4F

/******************************************************************************
* static global variables
******************************************************************************/
static MP4_VIDEO_STBL_MGR_T _rMP4VideoStblMgr;
static MP4_AUDIO_STBL_MGR_T _rMP4AudioStblMgr;
static kal_uint8 *_pau1IoBuffer;

/******************************************************************************
* Internal macro function
******************************************************************************/
#define SWAP_4(x)    (((x & 0x000000FF) << 24) |     \
                     ((x & 0x0000FF00) <<  8) |                 \
                     ((x & 0x00FF0000) >>  8) |                 \
                     ((x & 0xFF000000) >> 24))

#define SWAP_2(x)    (((x) & 0xFF) << 8) | ((unsigned short)(x) >> 8)
#define MATRIX_MULTIPLY(x, y) ((kal_uint32)((kal_int16)(x >> 16) * (kal_int16)(y >> 16)) << 16)

// Writer Buffer/File Utility
#define _MP4_WRITEFILE(_prFile,_pu1Data,_u4Len) \
    do {    \
        FSAL_ERR_RTN(_prFile, FSAL_Write(_prFile, _pu1Data, _u4Len));   \
    } while(0)

// Important: the macro is for writing data in aligned memory address
#define _MP4_WRITEBUF32(_pau1Buffer, _u4Pos, _u4Data)            \
    do {                                                        \
        *(kal_uint32*)(_pau1Buffer + _u4Pos) = SWAP_4(_u4Data);  \
        (_u4Pos) += 4;                                          \
    } while (0)

#define _MP4_WRITEBUF16(_pau1Buffer, _u4Pos, _u2Data)                        \
    do {                                                                    \
        *(kal_uint16*)(_pau1Buffer + _u4Pos) = SWAP_2(_u2Data); \
        (_u4Pos) += 2;                                                      \
    } while (0)

#define _MP4_WRITEBUF8(_pau1Buffer, _u4Pos, _u1Data)                 \
    do {                                                            \
        *(kal_uint8*)(_pau1Buffer + _u4Pos) = _u1Data;              \
        (_u4Pos) += 1;                                              \
    } while (0)

#define _MP4_WRITEBUF(_pau1Buffer, _u4Pos, _pu1Data, _u4Len)              \
    do {                                                                \
        kal_mem_cpy(_pau1Buffer + _u4Pos, _pu1Data, _u4Len);            \
        (_u4Pos) += _u4Len;                                             \
    } while (0)

void _MP4_WriteUnalignedBuf32(kal_uint8 *pau1Buffer, kal_uint32 *pu4Pos, kal_uint32 u4Data)
{
    *(kal_uint8*)(pau1Buffer + *pu4Pos) = (u4Data) >> 24;
    *(kal_uint8*)(pau1Buffer + *pu4Pos + 1) = ((u4Data) & 0xFF0000) >> 16;
    *(kal_uint8*)(pau1Buffer + *pu4Pos + 2) = ((u4Data) & 0xFF00) >> 8;
    *(kal_uint8*)(pau1Buffer + *pu4Pos + 3) = ((u4Data) & 0xFF);
    (*pu4Pos) += 4;
}

void _MP4_WriteUnalignedBuf16(kal_uint8 *pau1Buffer, kal_uint32 *pu4Pos, kal_uint16 u2Data)
{
    *(kal_uint8*)(pau1Buffer + *pu4Pos) = (u2Data) >> 8;
    *(kal_uint8*)(pau1Buffer + *pu4Pos + 1) = ((u2Data) & 0xFF);
    (*pu4Pos) += 2;
}

// Important: the macro is for writing data in aligned/unaligned memory address
#define _MP4_WRITEUNALIGNEDBUF32(_pau1Buffer, _u4Pos, _u4Data) _MP4_WriteUnalignedBuf32(_pau1Buffer, &_u4Pos, _u4Data)
#define _MP4_WRITEUNALIGNEDBUF16(_pau1Buffer, _u4Pos, _u4Data) _MP4_WriteUnalignedBuf16(_pau1Buffer, &_u4Pos, _u4Data)

/******************************************************************************
* Internal function
******************************************************************************/
/**
 * Increment totoal duration.
 */
__inline static void _MP4_STBL_AddTotalDuration(const kal_uint32 u4SampleDelta)
{
    // FIXME: Return error code on error.
    _rMP4VideoStblMgr.u4TotalDuration += u4SampleDelta;
    /*
    if (_rMP4VideoStblMgr.u4TotalDuration > 0xFF000000)
    {
    }
    */
}


__inline static VIDEO_ERROR_TYPE_T _MP4_STBL_ReadTotalDuration(STFSAL *const prTmpMetaFile, kal_uint32 *const pu4TotalDuration)
{
    VIDEO_ERROR_TYPE_T eError;

    VIDEO_ERR_RTN(MP4_ReadMeta(prTmpMetaFile, MP4_POS_V_DURATION,
        sizeof(*pu4TotalDuration), (kal_uint8*)pu4TotalDuration));

    return VIDEO_ERROR_NONE;
}


/**
 *
 */
static VIDEO_ERROR_TYPE_T _MP4_STBL_WriteTotalDuration(STFSAL *const prTmpMetaFile, const kal_uint32 u4TotalDuration)
{
    VIDEO_ERROR_TYPE_T eError;
    VIDEO_ERR_RTN(MP4_WriteMeta(prTmpMetaFile, MP4_POS_V_DURATION,
        sizeof(u4TotalDuration), (kal_uint8*)&u4TotalDuration));

    return VIDEO_ERROR_NONE;
}


/**
 * Add a new STTS entry, see ISO/IEC 14496-12 page 32
 */
__inline static void _MP4_STTS_AddOneEntry(MP4_STTS_BOX_T * const prStts, const kal_uint32 u4SampleCount,
        const kal_uint32 u4SampleDelta)
{
    MP4_STBL_BOX_BUFFER_MGR_T *const prBufferMgr = &prStts->rBufferMgr;
    kal_uint32 u4WriteWordIdx = prBufferMgr->u4WriteWordIdx;
    kal_uint32 u4UsedSize = prBufferMgr->u4UsedSize;
    kal_uint32 u4BoxSize = prBufferMgr->u4BoxSize;
    const kal_uint32 u4FreeSpace = MP4_STTS_ARRAY_SIZE_IN_BYTE - u4UsedSize;

    MP4_ASSERT(u4UsedSize < MP4_STTS_ARRAY_SIZE_IN_BYTE);
    MP4_ASSERT(u4FreeSpace > MP4_STTS_ENTRY_DATA_SIZE_IN_BYTE);

    prBufferMgr->pu4Data[u4WriteWordIdx] = SWAP_4(u4SampleCount);
    u4WriteWordIdx++;
    u4WriteWordIdx = (u4WriteWordIdx >= MP4_STTS_ARRAY_SIZE_IN_WORD) ? 0 : u4WriteWordIdx;  // wrap around
    u4UsedSize += sizeof(u4SampleCount);
    u4BoxSize += sizeof(u4SampleCount);

    prBufferMgr->pu4Data[u4WriteWordIdx] = SWAP_4(u4SampleDelta);
    u4WriteWordIdx++;
    u4WriteWordIdx = (u4WriteWordIdx >= MP4_STTS_ARRAY_SIZE_IN_WORD) ? 0 : u4WriteWordIdx;  // wrap around
    u4UsedSize += sizeof(u4SampleDelta);
    u4BoxSize += sizeof(u4SampleDelta);

    prBufferMgr->u4EntryCount++;
    prBufferMgr->u4WriteWordIdx = u4WriteWordIdx;
    prBufferMgr->u4UsedSize = u4UsedSize;
    prBufferMgr->u4BoxSize = u4BoxSize;

    prBufferMgr->u4TotalSize += 8;
}

/**
 * Add the meta data of one frame to STTS box buffers
 */
__inline static void _MP4_STTS_AddOneFrame(MP4_STTS_BOX_T * const prStts, MP4_FRAME_INFO_T *const prFrameInfo)
{
    MP4_STBL_BOX_BUFFER_MGR_T *const prBufferMgr = &prStts->rBufferMgr;
    if (prFrameInfo->fgFirstFrame == KAL_TRUE)
    {
        MP4_ASSERT(prStts->fgGotFirstFrame == KAL_FALSE &&
                    prBufferMgr->u4ReadWordIdx == 0 &&
                    prBufferMgr->u4WriteWordIdx == 0 &&
                    prBufferMgr->u4UsedSize == 0 &&
                    prBufferMgr->u4BoxSize == 0 &&
                    prBufferMgr->u4EntryCount == 0 &&
                    prBufferMgr->u4SampleCount == 0 &&
                    prStts->u4SampleDelta == 0 &&
                    prStts->fgHasFirstDelta == KAL_FALSE);

        // ISO/IEC 14496-12 page 32
        prBufferMgr->pu4Data[MP4_STTS_SIZE_OFFSET_IN_WORD] = SWAP_4(0);          // Zero out for now.
        kal_mem_cpy((void*)&prBufferMgr->pu4Data[MP4_STTS_TYPE_OFFSET_IN_WORD], (void*)"stts", 4);
        prBufferMgr->pu4Data[MP4_STTS_FLAGS_OFFSET_IN_WORD] = SWAP_4(0);
        prBufferMgr->pu4Data[MP4_STTS_ENTRY_COUNT_OFFSET_IN_WORD] = SWAP_4(0);   // Zero out for now.

        prBufferMgr->u4WriteWordIdx = MP4_STTS_HEADER_SIZE_IN_WORD;
        prBufferMgr->u4UsedSize = MP4_STTS_HEADER_SIZE_IN_BYTE;
        prBufferMgr->u4TotalSize = 16;
        prBufferMgr->u4BoxSize = MP4_STTS_HEADER_SIZE_IN_BYTE;

#ifdef MP4_RECORDER_ADJUST_TIMESTAMP_OF_FIRST_FRAME
        prStts->u8PrevTimeStamp = 0;    // Set the time stamp of the first frame to 0 on purpose!!!
#else
        prStts->u8PrevTimeStamp = prFrameInfo->u8TimeStamp;
#endif  // MP4_RECORDER_ADJUST_TIMESTAMP_OF_FIRST_FRAME
        prStts->fgGotFirstFrame = KAL_TRUE;
    }
    else
    {
        kal_uint64 u8SampleDelta;
        kal_uint32 u4SampleDelta;

        MP4_ASSERT(prStts->fgGotFirstFrame == KAL_TRUE);
        MP4_ASSERT(prFrameInfo->u8TimeStamp >= prStts->u8PrevTimeStamp);

        u8SampleDelta = prFrameInfo->u8TimeStamp - prStts->u8PrevTimeStamp;

        // Note: us -> timescale
        u4SampleDelta = (kal_uint32)VIDEO_ANYBASE_TO_ANYBASE(u8SampleDelta, 1000000, BOX_TIME_SCALE);

        MP4_ASSERT(u4SampleDelta < 0x01000000);
        _MP4_STBL_AddTotalDuration(u4SampleDelta);
        if (prStts->fgHasFirstDelta == KAL_FALSE)
        {
            prStts->u4SampleDelta = u4SampleDelta;
            prBufferMgr->u4SampleCount = 1;
            prStts->fgHasFirstDelta = KAL_TRUE;
        }
        else
        {
            if (prStts->u4SampleDelta != u4SampleDelta)
            {
                MP4_ASSERT(prBufferMgr->u4SampleCount != 0);
                _MP4_STTS_AddOneEntry(prStts, prBufferMgr->u4SampleCount, prStts->u4SampleDelta);
                prStts->u4SampleDelta = u4SampleDelta;
                prBufferMgr->u4SampleCount = 1;
            }
            else
            {
                prBufferMgr->u4SampleCount++;
                // ASSERT(prStts->u4SampleCount < 0xF0000000);
            }
        }
        prStts->u8PrevTimeStamp = prFrameInfo->u8TimeStamp;
    }
}

/*
 * Common function for adding one new entry
 */
static void _MP4_COMMON_AddOneEntry(MP4_STBL_BOX_BUFFER_MGR_T *const prBufferMgr, kal_uint32 u4BoxArraySize, kal_uint32 u4EntrySize, kal_uint32 u4Data)
{
    kal_uint32 u4WriteWordIdx = prBufferMgr->u4WriteWordIdx;
    kal_uint32 u4UsedSize = prBufferMgr->u4UsedSize;
    kal_uint32 u4BoxSize = prBufferMgr->u4BoxSize;
    const kal_uint32 u4FreeSpace = u4BoxArraySize - u4UsedSize;

    MP4_ASSERT(u4UsedSize < u4BoxArraySize);
    MP4_ASSERT(u4FreeSpace > u4EntrySize);

    prBufferMgr->pu4Data[u4WriteWordIdx] = SWAP_4(u4Data);
    u4WriteWordIdx++;
    u4WriteWordIdx = (u4WriteWordIdx >= (u4BoxArraySize >> 2)) ? 0 : u4WriteWordIdx;  // wrap around
    u4UsedSize += sizeof(u4Data);
    u4BoxSize += sizeof(u4Data);

    prBufferMgr->u4EntryCount++;
    MP4_ASSERT(prBufferMgr->u4EntryCount < 0xF0000000);
    prBufferMgr->u4WriteWordIdx = u4WriteWordIdx;
    prBufferMgr->u4UsedSize = u4UsedSize;
    prBufferMgr->u4BoxSize = u4BoxSize;
    prBufferMgr->u4TotalSize += 4;
}

/**
 * Add a new STTS entry, see ISO/IEC 14496-12 page 39
 */
__inline static void _MP4_STSZ_AddOneEntry(MP4_STSZ_BOX_T * const prStsz, const kal_uint32 u4SampleSize)
{
    _MP4_COMMON_AddOneEntry(&prStsz->rBufferMgr, MP4_STSZ_ARRAY_SIZE_IN_BYTE, MP4_STSZ_ENTRY_DATA_SIZE_IN_BYTE, u4SampleSize);
}

/**
 * Add the meta data of one frame to STSZ box buffers
 */
__inline static void _MP4_STSZ_AddOneFrame(MP4_STSZ_BOX_T * const prStsz, MP4_FRAME_INFO_T *const prFrameInfo)
{
    MP4_STBL_BOX_BUFFER_MGR_T *const prBufferMgr = &prStsz->rBufferMgr;
    if (prFrameInfo->fgFirstFrame == KAL_TRUE)
    {
        MP4_ASSERT(prStsz->fgGotFirstFrame == KAL_FALSE &&
                    prBufferMgr->u4ReadWordIdx == 0 &&
                    prBufferMgr->u4WriteWordIdx == 0 &&
                    prBufferMgr->u4UsedSize == 0 &&
                    prBufferMgr->u4BoxSize == 0 &&
                    prBufferMgr->u4SampleCount == 0);

        // ISO/IEC 14496-12 page 39
        prBufferMgr->pu4Data[MP4_STSZ_SIZE_OFFSET_IN_WORD] = SWAP_4(0);            // Zero out for now.
        kal_mem_cpy((void*)&prBufferMgr->pu4Data[MP4_STSZ_TYPE_OFFSET_IN_WORD], (void*)"stsz", 4);
        prBufferMgr->pu4Data[MP4_STSZ_FLAGS_OFFSET_IN_WORD] = SWAP_4(0);
        prBufferMgr->pu4Data[MP4_STSZ_SAMPLE_SIZE_OFFSET_IN_WORD] = SWAP_4(0);     // Zero out for now.
        prBufferMgr->pu4Data[MP4_STSZ_SAMPLE_COUNT_OFFSET_IN_WORD] = SWAP_4(0);    // Zero out for now.
        prBufferMgr->u4WriteWordIdx = MP4_STSZ_HEADER_SIZE_IN_WORD;
        prBufferMgr->u4UsedSize = MP4_STSZ_HEADER_SIZE_IN_BYTE;
        prBufferMgr->u4TotalSize = 16;
        prBufferMgr->u4BoxSize = MP4_STSZ_HEADER_SIZE_IN_BYTE;

        prStsz->fgGotFirstFrame = KAL_TRUE;
    }

    MP4_ASSERT(prStsz->fgGotFirstFrame == KAL_TRUE);
    prBufferMgr->u4SampleCount++;
    _MP4_STSZ_AddOneEntry(prStsz, prFrameInfo->u4FrameSize);  // Add rStsz.u4EntrySize to STSZ buffer.
}


/**
 * Add a new STTS entry, see ISO/IEC 14496-12 page 41
 */
__inline static void _MP4_STCO_AddOneEntry(MP4_STCO_BOX_T * const prStco, const kal_uint32 u4ChunkOffset)
{
    _MP4_COMMON_AddOneEntry(&prStco->rBufferMgr, MP4_STCO_ARRAY_SIZE_IN_BYTE, MP4_STCO_ENTRY_DATA_SIZE_IN_BYTE, u4ChunkOffset);
}


/**
 * Add the meta data of one frame to STCO box buffers
 */
__inline static void _MP4_STCO_AddOneFrame(MP4_STCO_BOX_T * const prStco, MP4_FRAME_INFO_T *const prFrameInfo)
{
    MP4_STBL_BOX_BUFFER_MGR_T *const prBufferMgr = &prStco->rBufferMgr;
    if (prFrameInfo->fgFirstFrame == KAL_TRUE)
    {
        MP4_ASSERT(prStco->fgGotFirstFrame == KAL_FALSE &&
                    prBufferMgr->u4ReadWordIdx == 0 &&
                    prBufferMgr->u4WriteWordIdx == 0 &&
                    prBufferMgr->u4UsedSize == 0 &&
                    prBufferMgr->u4BoxSize == 0 &&
                    prBufferMgr->u4EntryCount == 0 &&
                    prStco->u4ChunkOffset == 0 &&
                    prBufferMgr->u4SampleCount == 0);

        prBufferMgr->pu4Data[MP4_STCO_SIZE_OFFSET_IN_WORD] = SWAP_4(0);            // Zero out for now.
        kal_mem_cpy((void*)&prBufferMgr->pu4Data[MP4_STCO_TYPE_OFFSET_IN_WORD], (void*)"stco", 4);
        prBufferMgr->pu4Data[MP4_STCO_FLAGS_OFFSET_IN_WORD] = SWAP_4(0);
        prBufferMgr->pu4Data[MP4_STCO_ENTRY_COUNT_OFFSET_IN_WORD] = SWAP_4(0);     // Zero out for now.
        prBufferMgr->u4WriteWordIdx = MP4_STCO_HEADER_SIZE_IN_WORD;
        prBufferMgr->u4UsedSize = MP4_STCO_HEADER_SIZE_IN_BYTE;
        prBufferMgr->u4TotalSize = 16;
        prBufferMgr->u4BoxSize = MP4_STCO_HEADER_SIZE_IN_BYTE;

        prStco->u4ChunkOffset = MP4_BIT_STREAM_FILE_OFFSET_IN_BYTE;
        prStco->fgGotFirstFrame = KAL_TRUE;
    }
    else
    {
        MP4_ASSERT(prStco->fgGotFirstFrame == KAL_TRUE);
    }

    prBufferMgr->u4SampleCount++;

    if ((prBufferMgr->u4SampleCount % MP4_VSAMPLES_PER_CHUNK) == 1)
    {
        _MP4_STCO_AddOneEntry(prStco, prStco->u4ChunkOffset);
        if (prBufferMgr->u4SampleCount > MP4_VSAMPLES_PER_CHUNK)
        {
            prBufferMgr->u4SampleCount -= MP4_VSAMPLES_PER_CHUNK;
        }
    }

    prStco->u4ChunkOffset += prFrameInfo->u4FrameSize;
}

/**
 * Add a new STSS entry, see ISO/IEC 14496-12 page 34
 */
__inline static void _MP4_STSS_AddOneEntry(MP4_STSS_BOX_T * const prStss, const kal_uint32 u4SampleCount)
{
    _MP4_COMMON_AddOneEntry(&prStss->rBufferMgr, MP4_STSS_ARRAY_SIZE_IN_BYTE, MP4_STSS_ENTRY_DATA_SIZE_IN_BYTE, u4SampleCount);
}

/**
 * Add the meta data of one frame to STSS box buffers
 */
__inline static void _MP4_STSS_AddOneFrame(MP4_STSS_BOX_T * const prStss, MP4_FRAME_INFO_T *const prFrameInfo)
{
    MP4_STBL_BOX_BUFFER_MGR_T *const prBufferMgr = &prStss->rBufferMgr;
    if (prFrameInfo->fgFirstFrame == KAL_TRUE)
    {
        MP4_ASSERT(prStss->fgGotFirstFrame == KAL_FALSE &&
                    prBufferMgr->u4ReadWordIdx == 0 &&
                    prBufferMgr->u4WriteWordIdx == 0 &&
                    prBufferMgr->u4UsedSize == 0 &&
                    prBufferMgr->u4BoxSize == 0 &&
                    prBufferMgr->u4EntryCount == 0 &&
                    prBufferMgr->u4SampleCount == 0);

        prBufferMgr->pu4Data[MP4_STSS_SIZE_OFFSET_IN_WORD] = SWAP_4(0);            // Zero out for now.
        kal_mem_cpy((void*)&prBufferMgr->pu4Data[MP4_STSS_TYPE_OFFSET_IN_WORD], (void*)"stss", 4);
        prBufferMgr->pu4Data[MP4_STSS_FLAGS_OFFSET_IN_WORD] = SWAP_4(0);
        prBufferMgr->pu4Data[MP4_STSS_ENTRY_COUNT_OFFSET_IN_WORD] = SWAP_4(0);     // Zero out for now.
        prBufferMgr->u4WriteWordIdx = MP4_STSS_HEADER_SIZE_IN_WORD;
        prBufferMgr->u4UsedSize = MP4_STSS_HEADER_SIZE_IN_BYTE;
        prBufferMgr->u4TotalSize = 16;
        prBufferMgr->u4BoxSize = MP4_STSS_HEADER_SIZE_IN_BYTE;

        prStss->fgGotFirstFrame = KAL_TRUE;
    }

    MP4_ASSERT(prStss->fgGotFirstFrame == KAL_TRUE);
    prBufferMgr->u4SampleCount++;
    if (prFrameInfo->fgSyncFrame == KAL_TRUE)
    {
        _MP4_STSS_AddOneEntry(prStss, prBufferMgr->u4SampleCount);
    }
}


/**
 * Add the meta data of one frame to STSC box buffers
 */
__inline static void _MP4_STSC_AddOneFrame(MP4_STSC_BOX_T * const prStsc, MP4_FRAME_INFO_T *const prFrameInfo)
{
    prStsc->u4SampleCount++;
}


/**
 * Check whether data have to been written to file
 */
static kal_bool _MP4_HasData2Write(MP4_STBL_BOX_BUFFER_MGR_T *const prBufferMgr,
        const kal_uint32 u4BufferSize, const kal_uint32 u4ThresHold,
        kal_uint32 *const pu4DataAddr, kal_uint32 *const pu4DataSize)
{
    const kal_uint32 u4UsedSize = prBufferMgr->u4UsedSize;
    const kal_uint32 u4ReadWordIdx = prBufferMgr->u4ReadWordIdx;
    const kal_uint32 u4WriteWordIdx = prBufferMgr->u4WriteWordIdx;
    kal_uint32 * const pu4Data = prBufferMgr->pu4Data;

    *pu4DataAddr = 0, *pu4DataSize = 0;

    if (prBufferMgr->fgFlushBox == KAL_TRUE)
    {
        if (u4UsedSize == 0)
        {
            return KAL_FALSE;
        }
        else
        {
            if (u4ReadWordIdx < u4WriteWordIdx)
            {
                *pu4DataAddr = (kal_uint32)&pu4Data[u4ReadWordIdx];
                *pu4DataSize = (u4WriteWordIdx - u4ReadWordIdx) << 2;
            }
            else if (u4WriteWordIdx < u4ReadWordIdx)
            {
                *pu4DataAddr = (kal_uint32)&pu4Data[u4ReadWordIdx];
                *pu4DataSize = (u4BufferSize - u4ReadWordIdx) << 2;
            }
            else
            {
                MP4_ASSERT(0);
            }

            MP4_ASSERT(*pu4DataSize <= u4UsedSize);
            return KAL_TRUE;
        }
    }
    else
    {
        if (u4UsedSize == 0)
        {
            return KAL_FALSE;
        }
        else
        {
            kal_uint32 u4Leftover, u4Shortage;
            u4Leftover = (u4ReadWordIdx << 2) % u4ThresHold;
            u4Shortage = u4ThresHold - u4Leftover;
            if (u4UsedSize >= u4Shortage)
            {
                *pu4DataAddr = (kal_uint32)&pu4Data[u4ReadWordIdx];
                *pu4DataSize = u4Shortage;
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
        }
    }
}


/**
 * Write data to file
 */
static VIDEO_ERROR_TYPE_T _MP4_WriteSTBLData(STFSAL *const prFile,
        MP4_STBL_BOX_BUFFER_MGR_T *const prBufferMgr, const kal_uint32 u4BufferSize,
        const kal_uint32 u4DataAddr, const kal_uint32 u4DataSize)
{
    kal_uint32 u4NewReadWordIdx;
    kal_uint8 *pu1Addr;

    MP4_ASSERT(u4DataSize % 4 == 0);
    MP4_ASSERT(u4DataAddr == (kal_uint32)&prBufferMgr->pu4Data[prBufferMgr->u4ReadWordIdx]);

    FSAL_ERR_RTN(prFile, FSAL_Seek(prFile, prBufferMgr->u4WrittenSize));

    pu1Addr = (kal_uint8*)VideoCommExtBufferCacheableSwitchAlignMemory(u4DataAddr, u4DataSize, VIDEO_NON_CACHEABLE);
    FSAL_ERR_RTN(prFile, FSAL_Write(prFile, pu1Addr, u4DataSize));

#ifdef ENFORCE_WRITE
    FSAL_ERR_RTN(prFile, FSAL_CacheFlush(prFile));
#endif  // ENFORCE_WRITE

    // Update global variables...
    u4NewReadWordIdx = prBufferMgr->u4ReadWordIdx + (u4DataSize >> 2);
    MP4_ASSERT(u4NewReadWordIdx <= u4BufferSize);
    u4NewReadWordIdx = (u4NewReadWordIdx == u4BufferSize) ? 0 : u4NewReadWordIdx;  // wrap around
    prBufferMgr->u4ReadWordIdx = u4NewReadWordIdx;
    prBufferMgr->u4UsedSize -= u4DataSize;
    prBufferMgr->u4WrittenSize += u4DataSize;

    return VIDEO_ERROR_NONE;
}

/*
 *
 */
static VIDEO_ERROR_TYPE_T _MP4_COMMON_UpdateBoxHeader(STFSAL *const prFile,
        MP4_STBL_BOX_BUFFER_MGR_T *const prBufferMgr,
        kal_uint32 u4BoxSizeFileOffset,
        kal_uint32 u4BoxEntryCountFileOffset)
{
    kal_uint32 u4Data;

    // Update size of the box.
    FSAL_ERR_RTN(prFile, FSAL_Seek(prFile, u4BoxSizeFileOffset));

    u4Data = SWAP_4(prBufferMgr->u4BoxSize);

    FSAL_ERR_RTN(prFile, FSAL_Write(prFile, (kal_uint8*)&u4Data, sizeof(u4Data)));

    // Update entry_count of the box.
    FSAL_ERR_RTN(prFile, FSAL_Seek(prFile, u4BoxEntryCountFileOffset));

    u4Data = SWAP_4(prBufferMgr->u4EntryCount);
    FSAL_ERR_RTN(prFile, FSAL_Write(prFile, (kal_uint8*)&u4Data, sizeof(u4Data)));
    FSAL_ERR_RTN(prFile, FSAL_CacheFlush(prFile));

    return VIDEO_ERROR_NONE;
}

/**
 * Update Stts box header
 */
__inline static VIDEO_ERROR_TYPE_T _MP4_STTS_UpdateBoxHeader(STFSAL *const prSttsFile)
{
    return _MP4_COMMON_UpdateBoxHeader(prSttsFile, &_rMP4VideoStblMgr.rStts.rBufferMgr, MP4_STTS_SIZE_FILE_OFFSET, MP4_STTS_ENTRY_COUNT_FILE_OFFSET);
}


/**
 * Update Stsz box header
 */
__inline static VIDEO_ERROR_TYPE_T _MP4_STSZ_UpdateBoxHeader(STFSAL *const prStszFile)
{
    return _MP4_COMMON_UpdateBoxHeader(prStszFile, &_rMP4VideoStblMgr.rStsz.rBufferMgr, MP4_STSZ_SIZE_FILE_OFFSET, MP4_STSZ_SAMPLE_COUNT_FILE_OFFSET);
}


/**
 * Update Stco box header
 */
__inline static VIDEO_ERROR_TYPE_T _MP4_STCO_UpdateBoxHeader(STFSAL *const prStcoFile)
{
    return _MP4_COMMON_UpdateBoxHeader(prStcoFile, &_rMP4VideoStblMgr.rStco.rBufferMgr, MP4_STCO_SIZE_FILE_OFFSET, MP4_STCO_ENTRY_COUNT_FILE_OFFSET);
}


/**
 * Update Stss box header
 */
__inline static VIDEO_ERROR_TYPE_T _MP4_STSS_UpdateBoxHeader(STFSAL *const prStssFile)
{
    return _MP4_COMMON_UpdateBoxHeader(prStssFile, &_rMP4VideoStblMgr.rStss.rBufferMgr, MP4_STSS_SIZE_FILE_OFFSET, MP4_STSS_ENTRY_COUNT_FILE_OFFSET);
}


/**
 * Write/Update the box header of all stbl boxes if possible.
 */
static VIDEO_ERROR_TYPE_T _MP4_STBL_UpdateBoxHeader(MP4_FILE_MGR_T *const prMp4FileMgr)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    do
    {
        VIDEO_ERR_BREAK(_MP4_STTS_UpdateBoxHeader(&prMp4FileMgr->rFile[MP4_VIDEO_STTS_FILE]));
        VIDEO_ERR_BREAK(_MP4_STSZ_UpdateBoxHeader(&prMp4FileMgr->rFile[MP4_VIDEO_STSZ_FILE]));
        VIDEO_ERR_BREAK(_MP4_STCO_UpdateBoxHeader(&prMp4FileMgr->rFile[MP4_VIDEO_STCO_FILE]));
        VIDEO_ERR_BREAK(_MP4_STSS_UpdateBoxHeader(&prMp4FileMgr->rFile[MP4_VIDEO_STSS_FILE]));
    }while(0);

    return eError;
}


/**
 *
 */
__inline static VIDEO_ERROR_TYPE_T _MP4_STSZ_SetDataFlushing(void)
{
    _rMP4VideoStblMgr.rStsz.rBufferMgr.fgFlushBox = KAL_TRUE;

    return VIDEO_ERROR_NONE;
}


/**
 *
 */
__inline static VIDEO_ERROR_TYPE_T _MP4_STCO_SetDataFlushing(void)
{
    MP4_STCO_BOX_T * const prStco = &_rMP4VideoStblMgr.rStco;

    MP4_ASSERT(prStco->rBufferMgr.u4SampleCount <= MP4_VSAMPLES_PER_CHUNK);

    prStco->rBufferMgr.fgFlushBox = KAL_TRUE;

    return VIDEO_ERROR_NONE;
}


/**
 *
 */
__inline static VIDEO_ERROR_TYPE_T _MP4_STSC_SetDataFlushing(STFSAL *const prTmpMetaFile)
{
    MP4_STSC_BOX_T * const prStsc = &_rMP4VideoStblMgr.rStsc;
    VIDEO_ERROR_TYPE_T eError;

    // Store the sample count.
    VIDEO_ERR_RTN(MP4_WriteMeta(prTmpMetaFile, MP4_POS_STSC_SAMPLES,
        sizeof(prStsc->u4SampleCount), (kal_uint8*)&prStsc->u4SampleCount));

    return VIDEO_ERROR_NONE;
}


/**
 *
 */
__inline static VIDEO_ERROR_TYPE_T _MP4_STTS_SetDataFlushing(STFSAL *const prTmpMetaFile)
{
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 u4Data;
    MP4_STTS_BOX_T * const prStts = &_rMP4VideoStblMgr.rStts;

    // Store the time stamp of the last frame.
    VIDEO_ERR_RTN(MP4_WriteMeta(prTmpMetaFile, MP4_POS_STTS_LAST_TIME_STAMP,
        sizeof(prStts->u8PrevTimeStamp), (kal_uint8*)&prStts->u8PrevTimeStamp));

    // Store u4SampleDelta, u4SampleCount, fgGotFirstFrame, and fgHasFirstDelta.
    u4Data = prStts->fgGotFirstFrame;
    VIDEO_ERR_RTN(MP4_WriteMeta(prTmpMetaFile, MP4_POS_STTS_GOT_FIRST_FRAME,
        sizeof(u4Data), (kal_uint8*)&u4Data));

    u4Data = prStts->fgHasFirstDelta;
    VIDEO_ERR_RTN(MP4_WriteMeta(prTmpMetaFile, MP4_POS_STTS_HAS_FIRST_DELTA,
        sizeof(u4Data), (kal_uint8*)&u4Data));

    u4Data = prStts->u4SampleDelta;
    VIDEO_ERR_RTN(MP4_WriteMeta(prTmpMetaFile, MP4_POS_STTS_SAMPLE_DELTA,
        sizeof(u4Data), (kal_uint8*)&u4Data));

    u4Data = prStts->rBufferMgr.u4SampleCount;
    VIDEO_ERR_RTN(MP4_WriteMeta(prTmpMetaFile, MP4_POS_STTS_SAMPLE_COUNT,
        sizeof(u4Data), (kal_uint8*)&u4Data));

    // Update total duration.
    _MP4_STBL_WriteTotalDuration(prTmpMetaFile, _rMP4VideoStblMgr.u4TotalDuration);

    _rMP4VideoStblMgr.rStts.rBufferMgr.fgFlushBox = KAL_TRUE;

    return VIDEO_ERROR_NONE;
}


/**
 *
 */
__inline static VIDEO_ERROR_TYPE_T _MP4_STSS_SetDataFlushing(void)
{
    _rMP4VideoStblMgr.rStss.rBufferMgr.fgFlushBox = KAL_TRUE;

    return VIDEO_ERROR_NONE;
}


/**
 * Flag the stbl box's flush
 */
VIDEO_ERROR_TYPE_T _MP4_STBL_SetDataFlushing(STFSAL *const prTmpMetaFile)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    do
    {
        VIDEO_ERR_BREAK(_MP4_STTS_SetDataFlushing(prTmpMetaFile));
        VIDEO_ERR_BREAK(_MP4_STSC_SetDataFlushing(prTmpMetaFile));
        VIDEO_ERR_BREAK(_MP4_STSZ_SetDataFlushing());
        VIDEO_ERR_BREAK(_MP4_STCO_SetDataFlushing());
        VIDEO_ERR_BREAK(_MP4_STSS_SetDataFlushing());
    }while(0);

    return eError;
}


/**
 *
 */
static void _MP4_STBL_ClearDataFlushing(void)
{
    _rMP4VideoStblMgr.rStts.rBufferMgr.fgFlushBox = KAL_FALSE;
    _rMP4VideoStblMgr.rStsz.rBufferMgr.fgFlushBox = KAL_FALSE;
    _rMP4VideoStblMgr.rStco.rBufferMgr.fgFlushBox = KAL_FALSE;
    _rMP4VideoStblMgr.rStss.rBufferMgr.fgFlushBox = KAL_FALSE;
}


/**
 *
 */
static VIDEO_ERROR_TYPE_T _MP4_STTS_ProcessStopTime(STFSAL *const prTmpMetaFile,
        STFSAL *const prSttsFile, kal_uint64 *const pu8StopTime)
{
    VIDEO_ERROR_TYPE_T eError;
    MP4_STTS_BOX_T * const prStts = &_rMP4VideoStblMgr.rStts;
    kal_uint64 u8SampleDelta = 0, u8LastTimeStamp = 0;
    kal_uint32 u4SampleDelta = 0, u4PrevSampleDelta, u4PrevSampleCount, u4Data;
    kal_uint32 u4BoxSize, u4EntryCount, u4FileSize;
    kal_bool fgGotFirstFrame, fgHasFirstDelta;

    // Check whether process stop time have been executed before.
    {
        kal_uint32 u4ProcessStopTimeStatus = 0;
        VIDEO_ERR_RTN(MP4_ReadMeta(prTmpMetaFile, MP4_POS_PROCESS_STOP_TIME_STATUS,
                sizeof(u4ProcessStopTimeStatus), (kal_uint8*)&u4ProcessStopTimeStatus));
        if (u4ProcessStopTimeStatus == PROCESS_STOP_TIME_STATUS_SUCCEED)
        {
            drv_trace0(TRACE_GROUP_10, MUX_MP4AL_PROCESS_TIME_HAVE_BEEN_DONE);
            return VIDEO_ERROR_NONE;
        }
    }

    VIDEO_ERR_RTN(MP4_ReadMeta(prTmpMetaFile, MP4_POS_STTS_LAST_TIME_STAMP,
        sizeof(u8LastTimeStamp), (kal_uint8*)&u8LastTimeStamp));

    // Error handler
    if (*pu8StopTime <= u8LastTimeStamp)
    {
        u4SampleDelta = 0;
        drv_trace4(TRACE_GROUP_10, MUX_MP4AL_PROCESS_STOP_TIME,
            (kal_uint32)(*pu8StopTime >> 32), (kal_uint32)(*pu8StopTime & 0xFFFFFFFF),
            (kal_uint32)(u8LastTimeStamp >> 32), (kal_uint32)(u8LastTimeStamp & 0xFFFFFFFF));
    }
    else
    {
        u8SampleDelta = *pu8StopTime - u8LastTimeStamp;
        u4SampleDelta = (kal_uint32)VIDEO_ANYBASE_TO_ANYBASE(u8SampleDelta, 1000000, BOX_TIME_SCALE);
        if (u4SampleDelta >= 0x01000000)
        {
            return VIDEO_ERROR_MUXER_FS_ERROR;
        }
    }

    // Update total duration.
    VIDEO_ERR_RTN(_MP4_STBL_ReadTotalDuration(prTmpMetaFile, &_rMP4VideoStblMgr.u4TotalDuration));
    _MP4_STBL_AddTotalDuration(u4SampleDelta);
    VIDEO_ERR_RTN(_MP4_STBL_WriteTotalDuration(prTmpMetaFile, _rMP4VideoStblMgr.u4TotalDuration));

    // Read u4SampleDelta, u4SampleCount, fgGotFirstFrame, and fgHasFirstDelta.
    VIDEO_ERR_RTN(MP4_ReadMeta(prTmpMetaFile, MP4_POS_STTS_GOT_FIRST_FRAME,
        sizeof(u4Data), (kal_uint8*)&u4Data));

    fgGotFirstFrame = (kal_bool)u4Data;

    VIDEO_ERR_RTN(MP4_ReadMeta(prTmpMetaFile, MP4_POS_STTS_HAS_FIRST_DELTA,
        sizeof(u4Data), (kal_uint8*)&u4Data));

    fgHasFirstDelta = (kal_bool)u4Data;

    VIDEO_ERR_RTN(MP4_ReadMeta(prTmpMetaFile, MP4_POS_STTS_SAMPLE_DELTA,
        sizeof(u4Data), (kal_uint8*)&u4Data));

    u4PrevSampleDelta = u4Data;

    VIDEO_ERR_RTN(MP4_ReadMeta(prTmpMetaFile, MP4_POS_STTS_SAMPLE_COUNT,
        sizeof(u4Data), (kal_uint8*)&u4Data));

    u4PrevSampleCount = u4Data;

    // FIXME: Read u4BoxSize and u4EntryCount.
    VIDEO_ERR_RTN(MP4_ReadMeta(prSttsFile, MP4_STTS_SIZE_FILE_OFFSET,
        sizeof(u4Data), (kal_uint8*)&u4Data));

    u4BoxSize = SWAP_4(u4Data);

    VIDEO_ERR_RTN(MP4_ReadMeta(prSttsFile, MP4_STTS_ENTRY_COUNT_FILE_OFFSET,
        sizeof(u4Data), (kal_uint8*)&u4Data));

    u4EntryCount = SWAP_4(u4Data);

    // Calculate the duration of the last frame.
    if (fgGotFirstFrame == KAL_FALSE)
    {
        return VIDEO_ERROR_MUXER_NO_VIDEO_FRAME_ENCODED;
    }

    if (fgHasFirstDelta == KAL_FALSE)
    {
        u4PrevSampleDelta = u4SampleDelta;
        u4PrevSampleCount = 1;
        fgHasFirstDelta = KAL_TRUE;
    }
    else
    {
        if (u4PrevSampleDelta != u4SampleDelta)
        {
            if (u4PrevSampleCount == 0)
            {
                return VIDEO_ERROR_MUXER_FS_ERROR;
            }

            // Seek to end of file, and write u4SampleCount and u4SampleDelta.
            FSAL_ERR_RTN(prSttsFile, FSAL_GetFileSize(prSttsFile, &u4FileSize));

            u4Data = SWAP_4(u4PrevSampleCount);
            VIDEO_ERR_RTN(MP4_WriteMeta(prSttsFile, u4FileSize, sizeof(u4Data), (kal_uint8*)&u4Data));

            u4BoxSize += sizeof(u4PrevSampleCount);

            FSAL_ERR_RTN(prSttsFile, FSAL_GetFileSize(prSttsFile, &u4FileSize));
            u4Data = SWAP_4(u4PrevSampleDelta);
            VIDEO_ERR_RTN(MP4_WriteMeta(prSttsFile, u4FileSize, sizeof(u4Data), (kal_uint8*)&u4Data));

            if (u4BoxSize != u4FileSize)
            {
                return VIDEO_ERROR_MUXER_INCORRECT_FILE_SIZE;
            }
            u4BoxSize += sizeof(u4PrevSampleDelta);
            u4EntryCount++;

            u4PrevSampleDelta = u4SampleDelta;
            u4PrevSampleCount = 1;
        }
        else
        {
            u4PrevSampleCount++;
        }
    }

    // Seek to end of file, and write u4SampleCount and u4SampleDelta.
    FSAL_ERR_RTN(prSttsFile, FSAL_GetFileSize(prSttsFile, &u4FileSize));

    u4Data = SWAP_4(u4PrevSampleCount);
    VIDEO_ERR_RTN(MP4_WriteMeta(prSttsFile, u4FileSize, sizeof(u4Data), (kal_uint8*)&u4Data));

    if (u4BoxSize != u4FileSize)
    {
        return VIDEO_ERROR_MUXER_INCORRECT_FILE_SIZE;
    }
    u4BoxSize += sizeof(u4PrevSampleCount);

    FSAL_ERR_RTN(prSttsFile, FSAL_GetFileSize(prSttsFile, &u4FileSize));

    u4Data = SWAP_4(u4PrevSampleDelta);
    VIDEO_ERR_RTN(MP4_WriteMeta(prSttsFile, u4FileSize, sizeof(u4Data), (kal_uint8*)&u4Data));

    if (u4BoxSize != u4FileSize)
    {
        return VIDEO_ERROR_MUXER_INCORRECT_FILE_SIZE;
    }
    u4BoxSize += sizeof(u4PrevSampleDelta);
    u4EntryCount++;

    // Update box size.
    prStts->rBufferMgr.u4BoxSize = u4BoxSize;
    u4BoxSize = SWAP_4(u4BoxSize);
    VIDEO_ERR_RTN(MP4_WriteMeta(prSttsFile, MP4_STTS_SIZE_FILE_OFFSET,
        sizeof(u4BoxSize), (kal_uint8*)&u4BoxSize));

    // Update entry count.
    prStts->rBufferMgr.u4EntryCount = u4EntryCount;
    u4EntryCount = SWAP_4(u4EntryCount);
    VIDEO_ERR_RTN(MP4_WriteMeta(prSttsFile, MP4_STTS_ENTRY_COUNT_FILE_OFFSET,
        sizeof(u4EntryCount), (kal_uint8*)&u4EntryCount));
    {
        kal_uint32 u4ProcessStopTimeStatus = PROCESS_STOP_TIME_STATUS_SUCCEED;
        VIDEO_ERR_RTN(MP4_WriteMeta(prTmpMetaFile, MP4_POS_PROCESS_STOP_TIME_STATUS,
                sizeof(u4ProcessStopTimeStatus), (kal_uint8*)&u4ProcessStopTimeStatus));
    }
    return VIDEO_ERROR_NONE;
}


/**
 * Compute how many number of seconds has elapsed since 1904 midnight.  The time
 * vaule is used for setting the creation time of recorded files.
 */
static kal_uint32 _MP4_GetCurTime(void)
{
    kal_uint32 u4AdditionDay;
    kal_uint32 u4Time;
    DCL_HANDLE rtcHandle;
    RTC_CTRL_GET_TIME_T rRtcTime;
    DCL_STATUS eStatus;

    static const kal_uint16 u2MonthDay[12] =
    {
        0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
    };

    rtcHandle = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    // FIXME: Check rtcHandle here.
    kal_mem_set((void*)&rRtcTime, 0, sizeof(rRtcTime));
    eStatus = DclRTC_Control(rtcHandle, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T*)&rRtcTime);
    if (eStatus != STATUS_OK) { MP4_ASSERT(0); }
    eStatus = DclRTC_Close(rtcHandle);
    if (eStatus != STATUS_OK) { MP4_ASSERT(0); }

    u4AdditionDay = (((rRtcTime.u1Year - 1) - 1904) / 4) + 1;
    u4Time = (((2000 + rRtcTime.u1Year - 1904) * 365 * 24 * 60* 60) +
        (u2MonthDay[rRtcTime.u1Mon - 1] + rRtcTime.u1Day + u4AdditionDay) * 24 * 60 * 60 +
        ((rRtcTime.u1Hour * 60 + rRtcTime.u1Min) * 60) + rRtcTime.u1Sec);

    if (((rRtcTime.u1Year & 0x03) == 0) && (rRtcTime.u1Mon > 2))
    {
        u4Time += 24 * 60 * 60;
    }

    return u4Time;
}

#ifdef __ENABLE_STBL_PSEUDO_MERGE__
static VIDEO_ERROR_TYPE_T _MP4_ProduceSkip(STFSAL *const prFSALFile, kal_uint32 u4ClusterSize)
{
    kal_uint32 u4FileSize, u4FileClusterSize;
    kal_uint32 u4FreeBoxSize;

    FSAL_ERR_RTN(prFSALFile, FSAL_GetFileSize(prFSALFile, &u4FileSize));

    if (u4FileSize % u4ClusterSize != 0)
    {
        kal_uint32 u4FileSizeWithSkipBox = u4FileSize + 8; // SKIP BOX

        u4FileClusterSize = ((u4FileSizeWithSkipBox + u4ClusterSize - 1) / u4ClusterSize) * u4ClusterSize;
        u4FreeBoxSize = SWAP_4(u4FileClusterSize - u4FileSize);

        FSAL_ERR_RTN(prFSALFile, FSAL_Seek(prFSALFile, u4FileSize));
        FSAL_ERR_RTN(prFSALFile, FSAL_Write(prFSALFile, (kal_uint8 *)&u4FreeBoxSize, sizeof(u4FreeBoxSize)));
        FSAL_ERR_RTN(prFSALFile, FSAL_Write(prFSALFile, (kal_uint8 *)"SKIP", 4));
        FSAL_ERR_RTN(prFSALFile, FSAL_Seek(prFSALFile, u4FileClusterSize));
    }

    return VIDEO_ERROR_NONE;
}
#endif

/**
 * only video stbl box can use the function
 */
static VIDEO_ERROR_TYPE_T _MP4_CopyBox(MP4_BOX_MGR_T *const prBoxMgr, STFSAL *const prFSALRealMeta, STFSAL *const prBoxFile)
{
#ifdef __ENABLE_STBL_PSEUDO_MERGE__
    if (prBoxMgr->fgUsePseudoMerge == KAL_TRUE)
    {
        kal_uint32 u4FileSize;
        VIDEO_ERROR_TYPE_T eError;
        VIDEO_ERR_RTN(_MP4_ProduceSkip(prBoxFile, prBoxMgr->u4ClusterSize));

        FSAL_ERR_RTN(prBoxFile, FSAL_GetFileSize(prBoxFile, &u4FileSize));
        prBoxMgr->u4STBLReservedSize += u4FileSize;
        return VIDEO_ERROR_NONE;
    }
#endif
    {
        kal_uint32 u4FileSize, u4IoSize, u4WrittenSize = 0;
        kal_uint32 u4Pos;

        FSAL_ERR_RTN(prBoxFile, FSAL_GetFileSize(prBoxFile, &u4FileSize));
        FSAL_ERR_RTN(prBoxFile, FSAL_GetCurPos(prBoxFile, &u4Pos));

        while (u4FileSize > 0)
        {
            u4IoSize = (u4FileSize >= MP4_VIDEO_IO_BUFFER_SIZE_IN_BYTE) ? MP4_VIDEO_IO_BUFFER_SIZE_IN_BYTE : u4FileSize;

            FSAL_ERR_RTN(prBoxFile, FSAL_Seek(prBoxFile, u4WrittenSize));
            FSAL_ERR_RTN(prBoxFile, FSAL_Read(prBoxFile, _pau1IoBuffer, u4IoSize));
            FSAL_ERR_RTN(prFSALRealMeta, FSAL_Write(prFSALRealMeta, _pau1IoBuffer, u4IoSize));

            u4WrittenSize += u4IoSize;
            u4FileSize -= u4IoSize;
        }
    }

    return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T _MP4_ProduceAvcc(MP4_FILE_MGR_T *const prMp4FileMgr,
    kal_uint8  * const pau1Stsd, kal_uint32 * const pu4BufPos)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    kal_uint8 au1Buffer[MP4_POS_H264_MAX_SIZE - MP4_POS_H264_BASE];
    kal_uint8 u1NumOfSPS, u1NumOfPPS;
    kal_uint32 u4Data, *pu4Data, u4VOSOffset = 0;
    kal_uint32 u4AvccBufPos = *pu4BufPos;
    STFSAL *const prFSALTmpMeta = &prMp4FileMgr->rFile[MP4_TEMP_META_FILE];

    pu4Data = &u4Data;

    FSAL_ERR_RTN(prFSALTmpMeta, FSAL_Seek(prFSALTmpMeta, MP4_POS_H264_BASE));
    FSAL_ERR_RTN(prFSALTmpMeta, FSAL_Read(prFSALTmpMeta, au1Buffer, sizeof(au1Buffer)));

    _MP4_WRITEUNALIGNEDBUF32(pau1Stsd, *pu4BufPos, 0);                       // Size
    _MP4_WRITEBUF(pau1Stsd, *pu4BufPos, (kal_uint8*)"avcC", 4);     // format
    _MP4_WRITEBUF8(pau1Stsd, *pu4BufPos, 0x1);                      // configurationVersion

    _MP4_WRITEBUF8(pau1Stsd, *pu4BufPos, au1Buffer[MP4_POS_H264_PROF_IND - MP4_POS_H264_BASE]);
    _MP4_WRITEBUF8(pau1Stsd, *pu4BufPos, au1Buffer[MP4_POS_H264_PROF_COMPAT - MP4_POS_H264_BASE]);
    _MP4_WRITEBUF8(pau1Stsd, *pu4BufPos, au1Buffer[MP4_POS_H264_LEVLE_IND - MP4_POS_H264_BASE]);
    _MP4_WRITEBUF8(pau1Stsd, *pu4BufPos, 0xFC | (au1Buffer[MP4_POS_H264_LEN_SIZE - MP4_POS_H264_BASE] & 0x3));

    u1NumOfSPS = au1Buffer[MP4_POS_H264_NUM_OF_SPS - MP4_POS_H264_BASE] & 0x1F;
    _MP4_WRITEBUF8(pau1Stsd, *pu4BufPos, 0xE0 | u1NumOfSPS);

    // Write Sequence Parameter Sets.
    while (u1NumOfSPS > 0)
    {
        kal_uint16 u2SPSSize;
        kal_uint8 au1Data[MP4_MAX_SPS_SIZE];

        VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_VOS_DATA, 4, (kal_uint8 *)pu4Data));
        u2SPSSize = (kal_uint16)SWAP_4(u4Data);
        if (u2SPSSize > MP4_MAX_SPS_SIZE) { MP4_ASSERT(0); }
        u4VOSOffset += 4;
        _MP4_WRITEUNALIGNEDBUF16(pau1Stsd, *pu4BufPos, u2SPSSize);

        if ((MP4_POS_VOS_DATA + u4VOSOffset + u2SPSSize) > MP4_POS_VOS_LENGTH)
        {
            MP4_ASSERT(0);
        }

        VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_VOS_DATA + u4VOSOffset, u2SPSSize, au1Data));
        u4VOSOffset += u2SPSSize;
        _MP4_WRITEBUF(pau1Stsd, *pu4BufPos, au1Data, u2SPSSize);
        u1NumOfSPS--;
    }

    u1NumOfPPS = au1Buffer[MP4_POS_H264_NUM_OF_PPS - MP4_POS_H264_BASE];
    _MP4_WRITEBUF8(pau1Stsd, *pu4BufPos, u1NumOfPPS);

    // Write Picture Parameter Sets.
    while (u1NumOfPPS > 0)
    {
        kal_uint16 u2PPSSize;
        kal_uint8 au1Data[MP4_MAX_PPS_SIZE];

        VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_VOS_DATA + u4VOSOffset, 4, (kal_uint8 *)pu4Data));
        u2PPSSize = (kal_uint16)SWAP_4(u4Data);

        if (u2PPSSize > MP4_MAX_PPS_SIZE) { MP4_ASSERT(0); }
        u4VOSOffset += 4;
        _MP4_WRITEUNALIGNEDBUF16(pau1Stsd, *pu4BufPos, u2PPSSize);

        if ((MP4_POS_VOS_DATA + u4VOSOffset + u2PPSSize) > MP4_POS_VOS_LENGTH)
        {
            MP4_ASSERT(0);
        }

        VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_VOS_DATA + u4VOSOffset, u2PPSSize, au1Data));
        u4VOSOffset += u2PPSSize;
        _MP4_WRITEBUF(pau1Stsd, *pu4BufPos, au1Data, u2PPSSize);
        u1NumOfPPS--;
    }

    _MP4_WRITEUNALIGNEDBUF32(pau1Stsd, u4AvccBufPos, *pu4BufPos - u4AvccBufPos); // Avcc size

    return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T _MP4_ProduceVisualSampleEntry(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    const kal_uint32  u4VCodec = prBoxMgr->u4VCodec;
    kal_uint32  u4VosLength;
    STFSAL *const prFSALTmpMeta = &prMp4FileMgr->rFile[MP4_TEMP_META_FILE];
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4VisualSampleBufPos = 0, u4StsdBufPos = 0;
    kal_uint32 u4BufPos = 0;
    kal_uint8  * const pau1Stsd= (kal_uint8 *)prBoxMgr->uBoxData.au1Stsd;

    // moov->trak->minf->stbl->stsd
    u4StsdBufPos = u4BufPos;
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);                   // stsd size
    _MP4_WRITEBUF(pau1Stsd, u4BufPos, (kal_uint8*)"stsd", 4);  // stsd
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);                   // version, flags
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 1);                   // number of entries

    u4VisualSampleBufPos = u4BufPos;
    if (u4VCodec == VIDEO_ENCODER_MPEG4)
    {
        _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0xadU);                // mpeg4 Size
        _MP4_WRITEBUF(pau1Stsd, u4BufPos, (kal_uint8*)"mp4v", 4);  // dref
    }
    else if (u4VCodec == VIDEO_ENCODER_H264)
    {
        _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);
        _MP4_WRITEBUF(pau1Stsd, u4BufPos, (kal_uint8*)"avc1", 4);   // dref
    }
    else
    {
        _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);                     // s263 size
        _MP4_WRITEBUF(pau1Stsd, u4BufPos, (kal_uint8*)"s263", 4);   // dref
    }

    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);       // reserved
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 1);       // reserved + data_reference_index
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);       // pre_defined + reserved
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);       // pre_defined[0]
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);       // pre_defined[1]
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);       // pre_defined[2]
    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, prBoxMgr->u4Width); // width
    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, prBoxMgr->u4Height);// height
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0x480000);// (pre-defined) horizontal resolution
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0x480000);// (pre-defined) vertical resolution
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0x0);     // reserved
    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, 0x1);     // pre-defined frame_count

    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, 0);       // strCompressorName[0]
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);       // strCompressorName[4]
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);       // strCompressorName[8]
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);       // strCompressorName[12]
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);       // strCompressorName[16]
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);       // strCompressorName[20]
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);       // strCompressorName[24]
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);       // strCompressorName[28]
    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, 0);
    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, 24);      // (pre-defined) depth

    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, 0xffff);  // (pre-defined) -1

    if (u4VCodec == VIDEO_ENCODER_MPEG4)
    {
        VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_VOS_LENGTH, 4, (kal_uint8*)&u4VosLength));  // Leroy: Redundant

        _MP4_WRITEUNALIGNEDBUF32(pau1Stsd, u4BufPos, (49 + u4VosLength));              //size
        _MP4_WRITEBUF(pau1Stsd, u4BufPos, (kal_uint8*)"esds", 4);
        _MP4_WRITEUNALIGNEDBUF32(pau1Stsd, u4BufPos, 0x0);
        _MP4_WRITEUNALIGNEDBUF32(pau1Stsd, u4BufPos, 0x03808080U);                      //DESC 3
        _MP4_WRITEBUF8(pau1Stsd, u4BufPos, (u4VosLength+ 32));                //length
        _MP4_WRITEUNALIGNEDBUF16(pau1Stsd, u4BufPos, 0x01);                            //content
        _MP4_WRITEBUF8(pau1Stsd, u4BufPos, 0x0);                              //content
        _MP4_WRITEUNALIGNEDBUF32(pau1Stsd, u4BufPos, 0x04808080U);                      //DESC 4
        _MP4_WRITEBUF8(pau1Stsd, u4BufPos, (u4VosLength + 18));               //length
        _MP4_WRITEUNALIGNEDBUF16(pau1Stsd, u4BufPos, 0x2011);
        _MP4_WRITEBUF8(pau1Stsd, u4BufPos, (((prBoxMgr->u4Width*prBoxMgr->u4Height*3/2)& 0xff0000) >> 16));  //max frame length
        _MP4_WRITEUNALIGNEDBUF16(pau1Stsd, u4BufPos, ((kal_uint16)((prBoxMgr->u4Width*prBoxMgr->u4Height*3/2) & 0xffff)));
        _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 512000);                          //maxBitrate
        _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 256000);                          //avgBitrate
        _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0x05808080U);                      //DESC 5
        _MP4_WRITEBUF8(pau1Stsd, u4BufPos, u4VosLength);

        if (u4VosLength > MP4_VOS_MAX_LENGTH)
        {
            // exceeds array size
            drv_trace0(TRACE_GROUP_9, MUX_MP4AL_BROKEN_VOS_DATA);
            return VIDEO_ERROR_MUXER_FS_ERROR;
        }

        VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_VOS_DATA, u4VosLength, pau1Stsd + u4BufPos));

        if (((pau1Stsd[u4BufPos] << 24) + (pau1Stsd[u4BufPos+1] << 16) + (pau1Stsd[u4BufPos+2] << 8) + pau1Stsd[u4BufPos+3]) != 0x1b0)
        {
            drv_trace0(TRACE_GROUP_9, MUX_MP4AL_BROKEN_VOS_DATA);
            return VIDEO_ERROR_MUXER_FS_ERROR;
        }

        u4BufPos += u4VosLength;
        _MP4_WRITEUNALIGNEDBUF32(pau1Stsd, u4BufPos, 0x06808080U); //DESC 6
        _MP4_WRITEBUF8(pau1Stsd, u4BufPos, 0x01);      //length
        _MP4_WRITEBUF8(pau1Stsd, u4BufPos, 0x02);
    }
    else if (u4VCodec == VIDEO_ENCODER_H264)
    {
        _MP4_ProduceAvcc(prMp4FileMgr, pau1Stsd, &u4BufPos);
    }
    else
    {
        _MP4_WRITEUNALIGNEDBUF32(pau1Stsd, u4BufPos, 0xF);
        _MP4_WRITEBUF(pau1Stsd, u4BufPos, (kal_uint8*)"d263MTK ", 8);
        _MP4_WRITEUNALIGNEDBUF16(pau1Stsd, u4BufPos, 0x0a);
        _MP4_WRITEBUF8(pau1Stsd, u4BufPos, 0x0);
    }
    // Update size
    *(kal_uint32*)(pau1Stsd + u4VisualSampleBufPos) = SWAP_4(u4BufPos - u4VisualSampleBufPos);
    *(kal_uint32*)(pau1Stsd + u4StsdBufPos) = SWAP_4(u4BufPos - u4StsdBufPos); // stsd size

    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Stsd, u4BufPos);

    return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T _MP4_ProduceSamr(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4AudioSampleBufPos = 0, u4StsdBufPos = 0, u4DameBufPos = 0;
    kal_uint32 u4BufPos = 0;
    kal_uint8  *pau1Stsd= (kal_uint8 *)prBoxMgr->uBoxData.au1Stsd;
    // moov->trak->minf->stbl->stsd
    u4StsdBufPos = u4BufPos;
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);                      // stsd size
    _MP4_WRITEBUF(pau1Stsd, u4BufPos, (kal_uint8*)"stsd", 4);    // stsd
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);                      // version, flags
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 1);                      // number of entries

    u4AudioSampleBufPos = u4BufPos;
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0xadU);                  // samr Size
    if (prBoxMgr->u4ACodec == MEDIA_FORMAT_AMR_WB)
    {
        _MP4_WRITEBUF(pau1Stsd, u4BufPos, (kal_uint8*)"sawb", 4);    // dref
    }
    else
    {
        _MP4_WRITEBUF(pau1Stsd, u4BufPos, (kal_uint8*)"samr", 4);    // dref
    }
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);      // reserved
    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, 0);      // reserveddata_reference_index
    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, 1);      // data_reference_index

    // AudioSampleEntry - amr
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);      // reserved
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);      // reserved
    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, 2);      // channel count
    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, 16);     // sample size
    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, 0);      // predefined
    _MP4_WRITEBUF16(pau1Stsd, u4BufPos, 0);      // reserved
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, prBoxMgr->u4TimeScale << 16); // time scale

    // damr
    u4DameBufPos = u4BufPos;
    _MP4_WRITEBUF32(pau1Stsd, u4BufPos, 0);                      // damr Size
    _MP4_WRITEBUF(pau1Stsd, u4BufPos, (kal_uint8*)"damr", 4);    // dref

    // AMR Decoder Specific Structure
    _MP4_WRITEBUF(pau1Stsd, u4BufPos, (kal_uint8*)"MTK ", 4);    // vendor
    _MP4_WRITEBUF8(pau1Stsd, u4BufPos, 0);                       // decoder version
    _MP4_WRITEUNALIGNEDBUF16(pau1Stsd, u4BufPos, 0x81FF);                 // mode_set
    _MP4_WRITEBUF8(pau1Stsd, u4BufPos, 0);                       // mode change period
    _MP4_WRITEBUF8(pau1Stsd, u4BufPos, 1);                       // frame per sample

    // update box size
    *(kal_uint32*)(pau1Stsd + u4DameBufPos) = SWAP_4(u4BufPos - u4DameBufPos);
    *(kal_uint32*)(pau1Stsd + u4AudioSampleBufPos) = SWAP_4(u4BufPos - u4AudioSampleBufPos);
    *(kal_uint32*)(pau1Stsd + u4StsdBufPos) = SWAP_4(u4BufPos - u4StsdBufPos); // stsd size

    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Stsd, u4BufPos);

    return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T _MP4_ProduceAudioSampleEntry(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    if (prBoxMgr->u4ACodec == MEDIA_FORMAT_AAC)
    {
    }
    else
    {
        return _MP4_ProduceSamr(prMp4FileMgr, prBoxMgr);
    }

    return VIDEO_ERROR_NONE;

}


static VIDEO_ERROR_TYPE_T _MP4_ProduceStsd(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{

    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        return _MP4_ProduceVisualSampleEntry(prMp4FileMgr, prBoxMgr);
    }
    else if (prBoxMgr->eTrakType == AUDIO_TRACK)
    {
        return _MP4_ProduceAudioSampleEntry(prMp4FileMgr, prBoxMgr);
    }

    return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T _MP4_ProduceStts(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        STFSAL *prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
        // Write STTS
        VIDEO_ERR_RTN(_MP4_CopyBox(prBoxMgr, prFSALRealMeta, &prMp4FileMgr->rFile[MP4_VIDEO_STTS_FILE]));
    }
    else if (prBoxMgr->eTrakType == AUDIO_TRACK)
    {
        STFSAL *prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
        kal_uint32 u4SttsBufPos = 0;
        kal_uint32 u4BufPos = 0;
        kal_uint8  *pau1Stts= (kal_uint8 *)prBoxMgr->uBoxData.au1Stts;

        u4SttsBufPos = u4BufPos;
        _MP4_WRITEBUF32(pau1Stts, u4BufPos, 0);                      // stsd size
        _MP4_WRITEBUF(pau1Stts, u4BufPos, (kal_uint8*)"stts", 4);    // stsd
        _MP4_WRITEBUF32(pau1Stts, u4BufPos, 0);                      // version, flags
        _MP4_WRITEBUF32(pau1Stts, u4BufPos, 1);                      // entry count

        // sample count
        _MP4_WRITEBUF32(pau1Stts, u4BufPos, prBoxMgr->u4AFrameCount);

        // sample delta
        _MP4_WRITEBUF32(pau1Stts, u4BufPos, prBoxMgr->u4ASamplePerFrame);

        // update box size
        *(kal_uint32*)(pau1Stts + u4SttsBufPos) = SWAP_4(u4BufPos);

        _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Stts, u4BufPos);
    }

    return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T _MP4_ProduceStsc(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    kal_uint32 u4TotalFrame;
    kal_uint32 u4StscEntry;
    kal_uint32 u4Num;
    STFSAL *const prFSALTmpMeta = &prMp4FileMgr->rFile[MP4_TEMP_META_FILE];
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4BufPos = 0;
    kal_uint8  *const pau1Stsc= prBoxMgr->uBoxData.au1Stsc;
    kal_uint32 u4SamplesPerChunk;

    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_STSC_SAMPLES, 4, (kal_uint8*)&u4TotalFrame));

        u4SamplesPerChunk = MP4_VSAMPLES_PER_CHUNK;
    }
    else
    {
        u4TotalFrame = prBoxMgr->u4AFrameCount;
        u4SamplesPerChunk = MP4_ASAMPLES_PER_CHUNK;
    }

    u4StscEntry = 0;

    _MP4_WRITEBUF32(pau1Stsc, u4BufPos, 0);                      // stsc size
    _MP4_WRITEBUF(pau1Stsc, u4BufPos, (kal_uint8*)"stsc", 4);    // stsc
    _MP4_WRITEBUF32(pau1Stsc, u4BufPos, 0);                      // version + flags
    _MP4_WRITEBUF32(pau1Stsc, u4BufPos, 0);                      // entry count

    // Deal with the samples that are multiples of MP4_FILE_DEFAULT_CHUNK_SAMPLE_NUM.
    _MP4_WRITEBUF32(pau1Stsc, u4BufPos, 1);                      // first chunk number
    _MP4_WRITEBUF32(pau1Stsc, u4BufPos, u4SamplesPerChunk);      // samples per chunck
    _MP4_WRITEBUF32(pau1Stsc, u4BufPos, 1);                      // sample description ID

    u4StscEntry++;

    // Deal with the remaing samples "u4TotalFrame % MP4_FILE_DEFAULT_CHUNK_SAMPLE_NUM".
    if (((u4TotalFrame % u4SamplesPerChunk) != 0) &&
        (u4TotalFrame > u4SamplesPerChunk))
    {
        u4Num = u4TotalFrame / u4SamplesPerChunk;
        _MP4_WRITEBUF32(pau1Stsc, u4BufPos, u4Num + 1);          // first chunk number

        // the sample numbers of the last chunk
        _MP4_WRITEBUF32(pau1Stsc, u4BufPos, u4TotalFrame % u4SamplesPerChunk); //samples per chunck
        _MP4_WRITEBUF32(pau1Stsc, u4BufPos, 1);                  // sample description ID
        u4StscEntry++;
    }

    // update the box size
    *(kal_uint32*)pau1Stsc = SWAP_4(u4BufPos);

    // write the entry number
    *(kal_uint32*)(pau1Stsc + 12) = SWAP_4(u4StscEntry);                              // number of entries

    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Stsc, u4BufPos);

    return VIDEO_ERROR_NONE;

}


static VIDEO_ERROR_TYPE_T _MP4_ProduceStsz(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];

    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        VIDEO_ERR_RTN(_MP4_CopyBox(prBoxMgr, prFSALRealMeta, &prMp4FileMgr->rFile[MP4_VIDEO_STSZ_FILE]));
    }
    else
    {
        kal_uint8  *pau1Stsz= prBoxMgr->uBoxData.au1Stsz;
        kal_uint32 u4BufPos = 0;
        kal_uint32 u4FrameInfoIdx = 0, u4FrameInfoCount = 0;
        kal_uint32 u4StszBoxPos, u4FilePos = 0;
        kal_uint32 u4FrameInfo[AUDIO_FRAMEINFO_WORD_SIZE];
        STFSAL *const prFSALTmpMeta = &prMp4FileMgr->rFile[MP4_TEMP_META_FILE];

        VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_A_FRAMEINFO_COUNT, 4, (kal_uint8*)&u4FrameInfoCount));

        FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4StszBoxPos));

        _MP4_WRITEBUF32(pau1Stsz, u4BufPos, 0);                         // stsz size
        _MP4_WRITEBUF(pau1Stsz, u4BufPos, (kal_uint8*)"stsz", 4);       // stsz
        _MP4_WRITEBUF32(pau1Stsz, u4BufPos, 0);                         // version + flags
        // Noto: we use fixed value because AMR and AMR-WB's sample size is constant,
        // for AAC, please fix it.

        if (u4FrameInfoCount == 1)
        {
            VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_A_FRAMEINFO_START, AUDIO_FRAMEINFO_SIZE, (kal_uint8*)&u4FrameInfo));
            _MP4_WRITEBUF32(pau1Stsz, u4BufPos, u4FrameInfo[0]);            // sample size
            _MP4_WRITEBUF32(pau1Stsz, u4BufPos, prBoxMgr->u4AFrameCount);   // sample count
            _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Stsz, u4BufPos);
        }
        else
        {
            _MP4_WRITEBUF32(pau1Stsz, u4BufPos, 0);                         // sample size
            _MP4_WRITEBUF32(pau1Stsz, u4BufPos, prBoxMgr->u4AFrameCount);   // sample count

            // Except for sample size, write data firstly.
            _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Stsz, u4BufPos);
            u4BufPos = 0;

            for (; u4FrameInfoIdx < u4FrameInfoCount; u4FrameInfoIdx++)
            {
                kal_uint32 u4FrameIdx = 0, u4FrameCount;
                u4FilePos = MP4_A_FRAMEINFO_START + u4FrameInfoIdx * AUDIO_FRAMEINFO_SIZE;

                VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, u4FilePos, AUDIO_FRAMEINFO_SIZE, (kal_uint8*)&u4FrameInfo));

                u4FrameCount = u4FrameInfo[FRAME_COUNT];
                for (; u4FrameIdx < u4FrameCount; u4FrameIdx++)
                {
                    _MP4_WRITEBUF32(_pau1IoBuffer, u4BufPos, u4FrameInfo[FRAME_SIZE]);
                    if (u4BufPos == MP4_VIDEO_IO_BUFFER_SIZE_IN_BYTE)
                    {
                        _MP4_CHECK_ABORT_SAVING(); // The macro might return directly.
                        _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)_pau1IoBuffer, u4BufPos);
                        u4BufPos = 0;
                    }
                    else if (u4BufPos > MP4_VIDEO_IO_BUFFER_SIZE_IN_BYTE)
                    {
                        MP4_ASSERT(0);
                    }
                }
            }

            if (u4BufPos > 0)
            {
                _MP4_CHECK_ABORT_SAVING();  // The macro might return directly.
                _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)_pau1IoBuffer, u4BufPos);
            }
        }
        // update box size
        FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4FilePos));

        FSAL_ERR_RTN(prFSALRealMeta, FSAL_Write_UINT_AT(prFSALRealMeta, u4FilePos - u4StszBoxPos, u4StszBoxPos));
    }

    return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T _MP4_ProduceStco(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];

    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
#ifdef __ENABLE_STBL_PSEUDO_MERGE__
        /*
            We assume that stco is produced in the end, so it doesn't need
            to be cluster-size boundary. Don't change the order of producing stbl box casually.
        */
        if (prBoxMgr->fgUsePseudoMerge == KAL_TRUE)
        {
            kal_uint32 u4FileSize;
            STFSAL *const prBoxFile = &prMp4FileMgr->rFile[MP4_VIDEO_STCO_FILE];
            FSAL_ERR_RTN(prBoxFile, FSAL_GetFileSize(prBoxFile, &u4FileSize));
            prBoxMgr->u4STBLReservedSize += u4FileSize;
            return VIDEO_ERROR_NONE;
        }
#endif
        VIDEO_ERR_RTN(_MP4_CopyBox(prBoxMgr, prFSALRealMeta, &prMp4FileMgr->rFile[MP4_VIDEO_STCO_FILE]));
    }
    else
    {
        kal_uint8  *pau1Stco= prBoxMgr->uBoxData.au1Stco;
        kal_uint32 u4BufPos = 0;
        kal_uint32 u4StcoBoxPos, u4FilePos = 0;
        kal_uint32 u4ChunkCount;
        STFSAL *const prFSALTmpMeta = &prMp4FileMgr->rFile[MP4_TEMP_META_FILE];

        FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4StcoBoxPos));

        _MP4_WRITEBUF32(pau1Stco, u4BufPos, 0);                      // stco size
        _MP4_WRITEBUF(pau1Stco, u4BufPos, (kal_uint8*)"stco", 4);    // stco
        _MP4_WRITEBUF32(pau1Stco, u4BufPos, 0);                      // version + flags

        u4ChunkCount = (prBoxMgr->u4AFrameCount + MP4_ASAMPLES_PER_CHUNK - 1) / MP4_ASAMPLES_PER_CHUNK;

        _MP4_WRITEBUF32(pau1Stco, u4BufPos, u4ChunkCount);  // chunk count (audio)

        // chunk offset
        if( u4ChunkCount > 0 )
        {
            kal_uint32 u4FilePos = 0;
            kal_uint32 u4FrameInfoIdx = 0, u4FrameInfoCount = 0;
            kal_uint32 u4TotalFrameCount = 0, u4ChunkOffset = 8 + prBoxMgr->u4AudioDataOffset;
            kal_uint32 u4FrameInfo[AUDIO_FRAMEINFO_WORD_SIZE];

            VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_A_FRAMEINFO_COUNT, 4, (kal_uint8*)&u4FrameInfoCount));

            for (; u4FrameInfoIdx < u4FrameInfoCount; u4FrameInfoIdx++)
            {
                kal_uint32 u4FrameIdx = 0, u4FrameCount;
                u4FilePos = MP4_A_FRAMEINFO_START + u4FrameInfoIdx * AUDIO_FRAMEINFO_SIZE;

                VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, u4FilePos, AUDIO_FRAMEINFO_SIZE, (kal_uint8*)&u4FrameInfo));

                u4FrameCount = u4FrameInfo[FRAME_COUNT];
                for (; u4FrameIdx < u4FrameCount; u4FrameIdx++)
                {
                    u4TotalFrameCount++;

                    if (u4TotalFrameCount % MP4_ASAMPLES_PER_CHUNK == 1)
                    {
                        _MP4_WRITEBUF32(pau1Stco, u4BufPos, u4ChunkOffset);

                        if (u4BufPos >= sizeof(prBoxMgr->uBoxData.au1Stco) - 5)
                        {
                            _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Stco, u4BufPos);
                            u4BufPos = 0;
                        }
                    }

                    u4ChunkOffset += u4FrameInfo[FRAME_SIZE];
                }
            }
        }

        if (u4BufPos > 0)
        {
            _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Stco, u4BufPos);
        }


        // update box size
        FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4FilePos));

        // update box size
        FSAL_ERR_RTN(prFSALRealMeta, FSAL_Write_UINT_AT(prFSALRealMeta, u4FilePos - u4StcoBoxPos, u4StcoBoxPos));
    }

    return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T _MP4_ProduceStss(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];

    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        VIDEO_ERR_RTN(_MP4_CopyBox(prBoxMgr, prFSALRealMeta, &prMp4FileMgr->rFile[MP4_VIDEO_STSS_FILE]));
    }

    return VIDEO_ERROR_NONE;
}


__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceStbl(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    VIDEO_ERROR_TYPE_T eError;

    kal_uint32 u4StblBoxPos, u4FilePos;
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4BufPos = 0;
    kal_uint8 *const pau1Stbl = prBoxMgr->uBoxData.au1Stbl;

    // moov->trak->mdia->minf->stbl
    FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4StblBoxPos));

    _MP4_WRITEBUF32(pau1Stbl, u4BufPos, 0x0);                 // stbl size
    _MP4_WRITEBUF(pau1Stbl, u4BufPos, (kal_uint8*)"stbl", 4);  // stbl

    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Stbl, u4BufPos);

    // STSD
    VIDEO_ERR_RTN(_MP4_ProduceStsd(prMp4FileMgr, prBoxMgr));

    // STTS
    VIDEO_ERR_RTN(_MP4_ProduceStts(prMp4FileMgr, prBoxMgr));

    // STSC
    VIDEO_ERR_RTN(_MP4_ProduceStsc(prMp4FileMgr, prBoxMgr));

    // Write STSZ.
    VIDEO_ERR_RTN(_MP4_ProduceStsz(prMp4FileMgr, prBoxMgr));

    // Write STSS
    VIDEO_ERR_RTN(_MP4_ProduceStss(prMp4FileMgr, prBoxMgr));

    // Write STCO
    VIDEO_ERR_RTN(_MP4_ProduceStco(prMp4FileMgr, prBoxMgr));

#ifdef __ENABLE_STBL_PSEUDO_MERGE__
    /*
        If we use pseudo merge, real meta file must be cluster-size boundary,
        so we insert dummy box.
    */
    if (prBoxMgr->fgUsePseudoMerge == KAL_TRUE &&
        prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        VIDEO_ERR_RTN(_MP4_ProduceSkip(prFSALRealMeta, prBoxMgr->u4ClusterSize));
    }
#endif

    FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4FilePos));
    // update box size
    FSAL_ERR_RTN(prFSALRealMeta, FSAL_Write_UINT_AT(prFSALRealMeta, u4FilePos - u4StblBoxPos + prBoxMgr->u4STBLReservedSize, u4StblBoxPos));

    return VIDEO_ERROR_NONE;
}


__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceDinf(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4BufPos = 0;
    kal_uint8 *const pau1Dinf= prBoxMgr->uBoxData.au1Dinf;

    _MP4_WRITEBUF32(pau1Dinf, u4BufPos, 0);                      // Size
    _MP4_WRITEBUF(pau1Dinf, u4BufPos, (kal_uint8*)"dinf", 4);    // dinf
    _MP4_WRITEBUF32(pau1Dinf, u4BufPos, 0x01C);                  // Size
    _MP4_WRITEBUF(pau1Dinf, u4BufPos, (kal_uint8*)"dref", 4);    // dref
    _MP4_WRITEBUF32(pau1Dinf, u4BufPos, 0);                      // version + flag
    _MP4_WRITEBUF32(pau1Dinf, u4BufPos, 1);                      // number of entries
    _MP4_WRITEBUF32(pau1Dinf, u4BufPos, 0xc);                    // Size
    _MP4_WRITEBUF(pau1Dinf, u4BufPos, (kal_uint8*)"url ", 4);    // type = url
    _MP4_WRITEBUF32(pau1Dinf, u4BufPos, 1);                      // version + flag

    // update the box size
    *(kal_uint32*)pau1Dinf = SWAP_4(u4BufPos);

    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Dinf, u4BufPos);

    return VIDEO_ERROR_NONE;
}


__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceSmhd(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4BufPos = 0;
    kal_uint8 *const pau1Smhd= prBoxMgr->uBoxData.au1Smhd;

    _MP4_WRITEBUF32(pau1Smhd, u4BufPos, 0);                     // smhd size
    _MP4_WRITEBUF(pau1Smhd, u4BufPos, (kal_uint8*)"smhd", 4);    // smhd
    _MP4_WRITEBUF32(pau1Smhd, u4BufPos, 0);                      // version + flag
    _MP4_WRITEBUF32(pau1Smhd, u4BufPos, 0x0);                    // balance + reserved

    // update the box size
    *(kal_uint32*)pau1Smhd = SWAP_4(u4BufPos);

    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Smhd, u4BufPos);

    return VIDEO_ERROR_NONE;
}


__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceVmhd(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4BufPos = 0;
    kal_uint8 *const pau1Vmhd= prBoxMgr->uBoxData.au1Vmhd;

    _MP4_WRITEBUF32(pau1Vmhd, u4BufPos, 0);                      // vmhd size
    _MP4_WRITEBUF(pau1Vmhd, u4BufPos, (kal_uint8*)"vmhd", 4);    // vmhd
    _MP4_WRITEBUF32(pau1Vmhd, u4BufPos, 1);                      // version + flag
    _MP4_WRITEBUF32(pau1Vmhd, u4BufPos, 0x0);                    // Predefined
    _MP4_WRITEBUF32(pau1Vmhd, u4BufPos, 0x0);                    // Predefined

    // update the box size
    *(kal_uint32*)pau1Vmhd = SWAP_4(u4BufPos);

    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Vmhd, u4BufPos);

    return VIDEO_ERROR_NONE;
}


__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceMinf(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    VIDEO_ERROR_TYPE_T eError;

    kal_uint32 u4MinfBoxPos, u4FilePos;
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4BufPos = 0;
    kal_uint8 *const pau1Minf= prBoxMgr->uBoxData.au1Minf;

    // moov->trak->mdia->minf
    FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4MinfBoxPos));

    _MP4_WRITEBUF32(pau1Minf, u4BufPos, 0x0);                 // minf size
    _MP4_WRITEBUF(pau1Minf, u4BufPos, (kal_uint8*)"minf", 4);  // minf
    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Minf, u4BufPos);

    // moov->trak->mdia->minf->vmhd
    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        eError = _MP4_ProduceVmhd(prMp4FileMgr, prBoxMgr);
    }
    else
    {
        eError = _MP4_ProduceSmhd(prMp4FileMgr, prBoxMgr);
    }

    if (eError != VIDEO_ERROR_NONE)
    {
        return eError;
    }

    // moov->trak->mdia->minf->dinf
    VIDEO_ERR_RTN(_MP4_ProduceDinf(prMp4FileMgr, prBoxMgr));

    // moov->trak->mdia->minf->stbl
    VIDEO_ERR_RTN(_MP4_ProduceStbl(prMp4FileMgr, prBoxMgr));

    FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4FilePos));

    // update box size
    FSAL_ERR_RTN(prFSALRealMeta, FSAL_Write_UINT_AT(prFSALRealMeta, u4FilePos - u4MinfBoxPos + prBoxMgr->u4STBLReservedSize, u4MinfBoxPos));

    return VIDEO_ERROR_NONE;
}


__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceHdlr(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4BufPos = 0;
    kal_uint8 *const pau1Hdlr= prBoxMgr->uBoxData.au1Hdlr;

    _MP4_WRITEBUF32(pau1Hdlr, u4BufPos, 0x21);
    _MP4_WRITEBUF(pau1Hdlr, u4BufPos, (kal_uint8*)"hdlr", 4);
    _MP4_WRITEBUF32(pau1Hdlr, u4BufPos, 0x0);                 // version + flag
    _MP4_WRITEBUF32(pau1Hdlr, u4BufPos, 0x0);                 // reserved
    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        _MP4_WRITEBUF(pau1Hdlr, u4BufPos, (kal_uint8*)"vide", 4);  // handler type
    }
    else
    {
        _MP4_WRITEBUF(pau1Hdlr, u4BufPos, (kal_uint8*)"soun", 4);  // handler type
    }
    _MP4_WRITEBUF32(pau1Hdlr, u4BufPos, 0x0);                 // reserved
    _MP4_WRITEBUF32(pau1Hdlr, u4BufPos, 0x0);                 // reserved
    _MP4_WRITEBUF32(pau1Hdlr, u4BufPos, 0x0);                 // reserved

    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        _MP4_WRITEBUF8(pau1Hdlr, u4BufPos, 0x0);                  // string length
    }
    else
    {
        kal_uint8 pBuf[] = "MTK Sound Handler"; // Todo: remove it?
        _MP4_WRITEBUF(pau1Hdlr, u4BufPos, pBuf, sizeof(pBuf));    // string
    }

    // update the box size
    *(kal_uint32*)pau1Hdlr = SWAP_4(u4BufPos);

    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Hdlr, u4BufPos);

    return VIDEO_ERROR_NONE;
}


__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceMdhd(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4BufPos = 0;
    kal_uint8 *const pau1Mdhd= prBoxMgr->uBoxData.au1Mdhd;

    _MP4_WRITEBUF32(pau1Mdhd, u4BufPos, 0x20);                // mdhd size
    _MP4_WRITEBUF(pau1Mdhd, u4BufPos, (kal_uint8*)"mdhd", 4);  // mdhd
    _MP4_WRITEBUF32(pau1Mdhd, u4BufPos, 0x0);                             // version + flags
    _MP4_WRITEBUF32(pau1Mdhd, u4BufPos, prBoxMgr->u4CreateTime);          // create time
    _MP4_WRITEBUF32(pau1Mdhd, u4BufPos, prBoxMgr->u4CreateTime);          // modification time
    _MP4_WRITEBUF32(pau1Mdhd, u4BufPos, prBoxMgr->u4TimeScale);           // time scale

    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        _MP4_WRITEBUF32(pau1Mdhd, u4BufPos, prBoxMgr->u4VDuration); // video duration
        _MP4_WRITEBUF32(pau1Mdhd, u4BufPos, 0x0);                   // language + reserved
    }
    else
    {
        _MP4_WRITEBUF32(pau1Mdhd, u4BufPos, prBoxMgr->u4ADuration); // audio duration
        _MP4_WRITEBUF32(pau1Mdhd, u4BufPos, 0x15C70000);            // language + reserved
    }

    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Mdhd, u4BufPos);

    return VIDEO_ERROR_NONE;
}


__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceMdia(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    VIDEO_ERROR_TYPE_T eError;

    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4MdiaBoxPos, u4FilePos;
    kal_uint32 u4BufPos = 0;
    kal_uint8 *const pau1Mdia = prBoxMgr->uBoxData.au1Mdia;

    // moov->trak->mdia (media information)
    FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4MdiaBoxPos));

    _MP4_WRITEBUF32(pau1Mdia, u4BufPos, 0x0);                    // mdia size
    _MP4_WRITEBUF(pau1Mdia, u4BufPos, (kal_uint8*)"mdia", 4);    // mdia
    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Mdia, u4BufPos);

    // moov->trak->mdia->mdhd
    VIDEO_ERR_RTN(_MP4_ProduceMdhd(prMp4FileMgr, prBoxMgr));

    // moov->trak->mdia->hdlr
    VIDEO_ERR_RTN(_MP4_ProduceHdlr(prMp4FileMgr, prBoxMgr));

    // moov->trak->mdia->minf
    VIDEO_ERR_RTN(_MP4_ProduceMinf(prMp4FileMgr, prBoxMgr));

    FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4FilePos));

    // update box size
    FSAL_ERR_RTN(prFSALRealMeta, FSAL_Write_UINT_AT(prFSALRealMeta, u4FilePos - u4MdiaBoxPos + prBoxMgr->u4STBLReservedSize, u4MdiaBoxPos));

    return VIDEO_ERROR_NONE;
}

#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
__inline static VIDEO_ERROR_TYPE_T _MP4_DoTransformMatrix(MUXER_ROTATION_ANGLE_T eRotateAngle,
            kal_bool fgHorizontallyMirror, kal_uint32 pau4Matrix[][3])
{
    // Rotate
    switch (eRotateAngle)
    {
    case MUXER_ROTATE_90_CW:
        {
            pau4Matrix[0][0] = 0x00000000;
            pau4Matrix[0][1] = 0x00010000;
            pau4Matrix[1][0] = 0xFFFF0000;
            pau4Matrix[1][1] = 0x00000000;
        }
        break;
    case MUXER_ROTATE_180_CW:
        {
            pau4Matrix[0][0] = 0xFFFF0000;
            pau4Matrix[1][1] = 0xFFFF0000;
        }
        break;
    case MUXER_ROTATE_270_CW:
        {
            pau4Matrix[0][0] = 0x00000000;
            pau4Matrix[0][1] = 0xFFFF0000;
            pau4Matrix[1][0] = 0x00010000;
            pau4Matrix[1][1] = 0x00000000;
        }
        break;
    default:
        break;
    }

    // Horizontally Mirror
    if (fgHorizontallyMirror == KAL_TRUE)
    {
        kal_uint32 u4Row;
        kal_uint32 u4Column;
        // We only support rotation, no translation, so default translation value is zero
        kal_uint32 au4OutMatrix[3][3] = {0x00000000, 0x00000000, 0x00000000,
                                         0x00000000, 0x00000000, 0x00000000,
                                         0x00000000, 0x00000000, 0x40000000};

        // Horizontal mirror matrix
        kal_uint32 au4HorizontMatrix[3][3] = {0xFFFF0000, 0x00000000, 0x00000000,
                                              0x00000000, 0x00010000, 0x00000000,
                                              0x00000000, 0x00000000, 0x40000000};

        for(u4Row = 0; u4Row < 2; u4Row++)
        {
            for(u4Column = 0; u4Column < 2; u4Column++)
            {
                au4OutMatrix[u4Row][u4Column] = (MATRIX_MULTIPLY(pau4Matrix[u4Row][0], au4HorizontMatrix[0][u4Column]) +
                                                 MATRIX_MULTIPLY(pau4Matrix[u4Row][1], au4HorizontMatrix[1][u4Column]));
            }
        }
        kal_mem_cpy(pau4Matrix, au4OutMatrix, sizeof(au4OutMatrix));
    }
    return VIDEO_ERROR_NONE;
}
#endif

__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceTkhd(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4BufPos = 0;
    kal_uint8 *const pau1Tkhd = prBoxMgr->uBoxData.au1Tkhd;
    kal_uint32 au4Matrix[3][3] = {0x00010000, 0x00000000, 0x00000000,
                                  0x00000000, 0x00010000, 0x00000000,
                                  0x00000000, 0x00000000, 0x40000000};

    // flag = 0x7: track_enabled, track_in_movie, track_in_preview
    _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, 0x5c);                // tkhd size
    _MP4_WRITEBUF(pau1Tkhd, u4BufPos, (kal_uint8*)"tkhd", 4);  // tkhd
    _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, 0x7);                 // version + flags
    _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, prBoxMgr->u4CreateTime);        // create time
    _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, prBoxMgr->u4CreateTime);        // modification time

    _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, prBoxMgr->u4TrakID++);//Track ID
    _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, 0x0);                 // Reserved

    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, prBoxMgr->u4VDuration);       // video duration
    }
    else
    {
        _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, prBoxMgr->u4ADuration);       // audio duration
    }

    _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, 0x0);                 // Reserved
    _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, 0x0);                 // Reserved
    _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, 0x0);                 // Layer + Alternative group

    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, 0x00000000);          // volume + Reserved
#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
        _MP4_DoTransformMatrix(prBoxMgr->eRotateAngle, prBoxMgr->fgHorizontallyMirror, au4Matrix);
#endif
    }
    else
    {
        _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, 0x01000000);          // volume + Reserved
    }

    // Write matrix
    {
        kal_uint32 x,y;
        for (x = 0; x < 3; x++)
        {
            for(y = 0; y < 3; y++)
            {
                _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, au4Matrix[x][y]);
            }
        }
    }

    if (prBoxMgr->eTrakType == VIDEO_TRACK)
    {
        _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, (prBoxMgr->u4Width << 16));     // width in pixels
        _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, (prBoxMgr->u4Height << 16));    // height in pixels
    }
    else
    {
        _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, 0);      // width in pixels
        _MP4_WRITEBUF32(pau1Tkhd, u4BufPos, 0);      // height in pixels
    }
    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Tkhd, u4BufPos);

    return VIDEO_ERROR_NONE;
}


__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceTrak(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    VIDEO_ERROR_TYPE_T eError;

    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4VTrakBoxPos, u4FilePos;
    kal_uint32 u4BufPos = 0;
    kal_uint8 *const pau1Trak = prBoxMgr->uBoxData.au1Trak;

    // moov->video track
    FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4VTrakBoxPos));

    _MP4_WRITEBUF32(pau1Trak, u4BufPos, 0x0);                  // trak size
    _MP4_WRITEBUF(pau1Trak, u4BufPos, (kal_uint8*)"trak", 4);  // trak
    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Trak, u4BufPos);

    // moov->trak->tkhd (track header)
    VIDEO_ERR_RTN(_MP4_ProduceTkhd(prMp4FileMgr, prBoxMgr));

    // moov->trak->mdia (media information)
    VIDEO_ERR_RTN(_MP4_ProduceMdia(prMp4FileMgr, prBoxMgr));

    FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4FilePos));

    // update box size
    FSAL_ERR_RTN(prFSALRealMeta, FSAL_Write_UINT_AT(prFSALRealMeta, u4FilePos - u4VTrakBoxPos + prBoxMgr->u4STBLReservedSize, u4VTrakBoxPos));

    return VIDEO_ERROR_NONE;
}


__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceIods(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    const kal_uint32 u4VCodec = prBoxMgr->u4VCodec;
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4BufPos = 0;
    kal_uint8 *const pau1Iods= prBoxMgr->uBoxData.au1Iods;

    if (u4VCodec != VIDEO_ENCODER_H263)
    {
        _MP4_WRITEBUF32(pau1Iods, u4BufPos, 0x2A);                // iods size
        _MP4_WRITEBUF(pau1Iods, u4BufPos, (kal_uint8*)"iods", 4);  // iods
        _MP4_WRITEBUF32(pau1Iods, u4BufPos, 0x0);                 // version + flags
        _MP4_WRITEBUF32(pau1Iods, u4BufPos, 0x10808080U);          // ??
        _MP4_WRITEBUF32(pau1Iods, u4BufPos, 0x19004FFFU);
        _MP4_WRITEBUF32(pau1Iods, u4BufPos, 0xFFFF03FF);
        _MP4_WRITEBUF32(pau1Iods, u4BufPos, 0x0E808080U);
        _MP4_WRITEBUF32(pau1Iods, u4BufPos, 0x04000000);
        _MP4_WRITEBUF32(pau1Iods, u4BufPos, 0x020E8080U);
        _MP4_WRITEBUF32(pau1Iods, u4BufPos, 0x80040000);
        _MP4_WRITEBUF16(pau1Iods, u4BufPos, 0x0003);

        _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Iods, u4BufPos);
    }

    return VIDEO_ERROR_NONE;
}


/**
 *  Write the box of signature 'IUAM' for video clipper.
 */
__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceIuam(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{

    kal_uint32 u4DataLen;
    kal_uint8 au1Signature[] = "http://www.mediatek.com";
    kal_uint8  *pau1Iuam = prBoxMgr->uBoxData.au1Iuam;
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    const kal_uint32 u4TRNSBoxSize = 12;
    kal_uint32 u4BufPos = 0;

    // Size of 'IUAM' box
    // "- 1" is used because the trailing null character is not counted.
    u4DataLen = 8 + sizeof(au1Signature) - 1;
#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    u4DataLen += u4TRNSBoxSize;
#endif
    _MP4_WRITEBUF32(pau1Iuam, u4BufPos, u4DataLen);             // iuam size
    _MP4_WRITEBUF(pau1Iuam, u4BufPos, (kal_uint8*)"IUAM", 4);   // iuam

    // "- 1" is used because the trailing null character is not counted.
    u4DataLen = sizeof(au1Signature) - 1;
    _MP4_WRITEBUF(pau1Iuam, u4BufPos, au1Signature, u4DataLen);

#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    // Write "TRNS" Box
    _MP4_WRITEUNALIGNEDBUF32(pau1Iuam, u4BufPos, u4TRNSBoxSize);                // ROMR size
    _MP4_WRITEBUF(pau1Iuam, u4BufPos, (kal_uint8*)"TRNS", 4);           // ROMR
    {
        kal_uint16 u2RotateAngle = 0;
        switch(prBoxMgr->eRotateAngle)
        {
        case MUXER_ROTATE_90_CW:
            {
                u2RotateAngle = 90;
            }
            break;
        case MUXER_ROTATE_180_CW:
            {
                u2RotateAngle = 180;
            }
            break;
        case MUXER_ROTATE_270_CW:
            {
                u2RotateAngle = 270;
            }
            break;
        default:
            break;
        }
        _MP4_WRITEUNALIGNEDBUF16(pau1Iuam, u4BufPos, u2RotateAngle); // Rotate Angle
        _MP4_WRITEBUF8(pau1Iuam, u4BufPos, prBoxMgr->fgHorizontallyMirror ? 1 : 0);  // Horizontally Mirror
        _MP4_WRITEBUF8(pau1Iuam, u4BufPos, 0);  // Vertically Mirror
    }
#endif
    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Iuam, u4BufPos);

    return VIDEO_ERROR_NONE;
}



__inline static VIDEO_ERROR_TYPE_T _MP4_ProduceMvhd(MP4_FILE_MGR_T *const prMp4FileMgr,
    MP4_BOX_MGR_T *const prBoxMgr)
{
    kal_uint32 u4NextTrackId = MP4_VIDEO_TRACK_ID + 1;
    STFSAL *const prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];
    kal_uint32 u4BufPos = 0;
    kal_uint8 *const pau1Mvhd= prBoxMgr->uBoxData.au1Mvhd;

    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x6c);                   // mvhd size
    _MP4_WRITEBUF(pau1Mvhd, u4BufPos, (kal_uint8*)"mvhd", 4);     // mvhd
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x0);                    // version + flags

    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, prBoxMgr->u4CreateTime); // create time
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, prBoxMgr->u4CreateTime); // modification time
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, prBoxMgr->u4TimeScale);  // time scale
    if (prBoxMgr->u4ADuration != 0)
    {
        _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, prBoxMgr->u4ADuration);  // use audio duration
    }
    else
    {
        // error handler.
        _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, prBoxMgr->u4VDuration);  // use video duration
    }
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00010000);          // preferred rate
    _MP4_WRITEBUF16(pau1Mvhd, u4BufPos, 0x0100);              // preferred volume
    _MP4_WRITEBUF16(pau1Mvhd, u4BufPos, 0x0000);              // reserved
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // reserved
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // reserved
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00010000);          // matrix[0]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // matrix[1]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // matrix[2]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // matrix[3]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00010000);          // matrix[4]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // matrix[5]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // matrix[6]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // matrix[7]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x40000000);          // matrix[8]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // predefined[0]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // predefined[1]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // predefined[2]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // predefined[3]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // predefined[4]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, 0x00000000);          // predefined[5]
    _MP4_WRITEBUF32(pau1Mvhd, u4BufPos, u4NextTrackId);       // Tode: fix, next track ID

    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Mvhd, u4BufPos);

    return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T _MP4_GetAudioInfo(kal_uint32 u4ACodec, kal_uint32 *pu4SamplePerFrame, kal_uint32 *pu4TimeScale, kal_uint32 *pu4SampleSize)
{
    if (u4ACodec == MEDIA_FORMAT_AMR)
    {
        *pu4TimeScale = 8000;
        *pu4SamplePerFrame = 160;
        *pu4SampleSize = 32;
    }
    else if (u4ACodec == MEDIA_FORMAT_AMR_WB)
    {
        *pu4TimeScale = 16000;
        *pu4SamplePerFrame = 320;
        // *pu4SampleSize = ??
    }
    else if (u4ACodec == MEDIA_FORMAT_AAC)
    {
        // For future extension
    }

    return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T _MP4_WriteAFrameSize(STFSAL *const prTmpMetaFile, kal_uint32 *pu4FilePos, kal_uint32 u4FrameSize, kal_uint32 u4FrameCount)
{
    if (u4FrameCount > 0)
    {
        VIDEO_ERROR_TYPE_T eError;
        kal_uint32 u4FrameInfo[AUDIO_FRAMEINFO_WORD_SIZE];
        u4FrameInfo[FRAME_SIZE] = u4FrameSize;
        u4FrameInfo[FRAME_COUNT] = u4FrameCount;
        VIDEO_ERR_RTN(MP4_WriteMeta(prTmpMetaFile, *pu4FilePos, AUDIO_FRAMEINFO_SIZE, (kal_uint8 *)u4FrameInfo));
        *pu4FilePos += AUDIO_FRAMEINFO_SIZE;
    }
    return VIDEO_ERROR_NONE;
}


static VIDEO_ERROR_TYPE_T _MP4_WriteBoxData(MP4_FILE_MGR_T *const prMp4FileMgr, MP4_STBL_BOX_BUFFER_MGR_T * const prBufferMgr, const MP4_FILE_HANDLE_TYPE_T eFileType,
                                            const kal_uint32 u4BoxArraySize, const kal_uint32 u4BoxThreshold)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 u4DataAddr, u4DataSize;
    STFSAL *const prFile = prMp4FileMgr->rFile;

    if (_MP4_HasData2Write(prBufferMgr,
        u4BoxArraySize, u4BoxThreshold, &u4DataAddr, &u4DataSize) == KAL_TRUE)
    {
        drv_trace2(TRACE_GROUP_9, MUX_MP4AL_WRITE_STBL_DATA, eFileType, u4DataSize);
        VIDEO_ERR_RTN(_MP4_WriteSTBLData(&prFile[eFileType], prBufferMgr,
                                        u4BoxArraySize, u4DataAddr, u4DataSize));
    }

    return VIDEO_ERROR_NONE;
}

/******************************************************************************
* Exported function
******************************************************************************/
/**
 * Allocate video STBL buffer
 */
void MP4_InitMeta(kal_bool fgRecording)
{
    kal_uint8 *pau1IoBuffer;
    kal_uint32 **ppu4SttsData = &_rMP4VideoStblMgr.rStts.rBufferMgr.pu4Data;
    kal_uint32 **ppu4StszData = &_rMP4VideoStblMgr.rStsz.rBufferMgr.pu4Data;
    kal_uint32 **ppu4StcoData = &_rMP4VideoStblMgr.rStco.rBufferMgr.pu4Data;
    kal_uint32 **ppu4StssData = &_rMP4VideoStblMgr.rStss.rBufferMgr.pu4Data;

    kal_mem_set((void*)&_rMP4VideoStblMgr, 0, sizeof(_rMP4VideoStblMgr));
    kal_mem_set((void*)&_rMP4AudioStblMgr, 0, sizeof(_rMP4AudioStblMgr));
    _pau1IoBuffer = NULL;

    if (fgRecording == KAL_TRUE)
    {
        // Alocate box buffer
        *ppu4SttsData = (kal_uint32*)MuxerAdaptGetMemory(MP4_STTS_ARRAY_SIZE_IN_BYTE, KAL_TRUE);
        *ppu4StszData = (kal_uint32*)MuxerAdaptGetMemory(MP4_STSZ_ARRAY_SIZE_IN_BYTE, KAL_TRUE);
        *ppu4StcoData = (kal_uint32*)MuxerAdaptGetMemory(MP4_STCO_ARRAY_SIZE_IN_BYTE, KAL_TRUE);
        *ppu4StssData = (kal_uint32*)MuxerAdaptGetMemory(MP4_STSS_ARRAY_SIZE_IN_BYTE, KAL_TRUE);

        MP4_ASSERT(*ppu4SttsData != NULL &&
                    *ppu4StszData != NULL &&
                    *ppu4StcoData != NULL &&
                    *ppu4StssData != NULL);

#if !defined(__VE_SLIM_PROJECT__)
        kal_mem_set((void*)*ppu4SttsData, 0, MP4_STTS_ARRAY_SIZE_IN_BYTE);
        kal_mem_set((void*)*ppu4StszData, 0, MP4_STSZ_ARRAY_SIZE_IN_BYTE);
        kal_mem_set((void*)*ppu4StcoData, 0, MP4_STCO_ARRAY_SIZE_IN_BYTE);
        kal_mem_set((void*)*ppu4StssData, 0, MP4_STSS_ARRAY_SIZE_IN_BYTE);
#endif
        _rMP4AudioStblMgr.u4FilePos = MP4_A_FRAMEINFO_START;
    }
    else
    {
        pau1IoBuffer = (kal_uint8*)MuxerAdaptGetMemory(MP4_VIDEO_IO_BUFFER_SIZE_IN_BYTE, KAL_TRUE);
        _pau1IoBuffer = (kal_uint8*)VideoCommExtBufferCacheableSwitchAlignMemory(
            (kal_uint32)pau1IoBuffer, MP4_VIDEO_IO_BUFFER_SIZE_IN_BYTE, VIDEO_NON_CACHEABLE);

        MP4_ASSERT(_pau1IoBuffer != NULL);

#if !defined(__VE_SLIM_PROJECT__)
        kal_mem_set((void*)_pau1IoBuffer, 0, MP4_VIDEO_IO_BUFFER_SIZE_IN_BYTE);
#endif
    }
}


/**
 * Free video STBL buffer
 */
void MP4_DeInitMeta(kal_bool fgRecording)
{
    if (fgRecording == KAL_TRUE)
    {
        MuxerAdaptFreeMemory(_rMP4VideoStblMgr.rStts.rBufferMgr.pu4Data);
        MuxerAdaptFreeMemory(_rMP4VideoStblMgr.rStsz.rBufferMgr.pu4Data);
        MuxerAdaptFreeMemory(_rMP4VideoStblMgr.rStco.rBufferMgr.pu4Data);
        MuxerAdaptFreeMemory(_rMP4VideoStblMgr.rStss.rBufferMgr.pu4Data);
#if !defined(__VE_SLIM_PROJECT__)
        _rMP4VideoStblMgr.rStts.rBufferMgr.pu4Data = NULL;
        _rMP4VideoStblMgr.rStsz.rBufferMgr.pu4Data = NULL;
        _rMP4VideoStblMgr.rStco.rBufferMgr.pu4Data = NULL;
        _rMP4VideoStblMgr.rStss.rBufferMgr.pu4Data = NULL;
#endif
    }
    else
    {
        MuxerAdaptFreeMemory(_pau1IoBuffer);
        _pau1IoBuffer = NULL;
    }
}


/**
 * Read the specified number (u4Size) of data from the offset (u4Offset) in the
 * specified file "*prFileHandle", and put the data into "*pu1Data".
 *
 * @return If the function succeeds, the return value is VIDEO_ERROR_NONE
 * Otherwise, an error code is returned.
 */
VIDEO_ERROR_TYPE_T MP4_ReadMeta(STFSAL *const prFileHandle, const kal_uint32 u4Offset,
        const kal_uint32 u4Size, kal_uint8 *const pu1Data)
{
    FSAL_ERR_RTN(prFileHandle, FSAL_Seek(prFileHandle, u4Offset));
    FSAL_ERR_RTN(prFileHandle, FSAL_Read(prFileHandle, pu1Data, u4Size));

    return VIDEO_ERROR_NONE;
}


/**
 *
 */
VIDEO_ERROR_TYPE_T MP4_WriteMeta(STFSAL * const prFileHandle, const kal_uint32 u4Offset,
        const kal_uint32 u4Size, kal_uint8 * const pu1Data)
{
    FSAL_ERR_RTN(prFileHandle, FSAL_Seek(prFileHandle, u4Offset));
    FSAL_ERR_RTN(prFileHandle, FSAL_Write(prFileHandle, pu1Data, u4Size));
    return VIDEO_ERROR_NONE;
}


VIDEO_ERROR_TYPE_T MP4_WriteH264Configuration(STFSAL *const prFileHandle, void * const pPrivateData)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 u4BufPos = 0;
    kal_uint8 au1Buffer[MP4_POS_H264_MAX_SIZE - MP4_POS_H264_BASE];
    H264_ENC_CONF_REC * const prH264Configuration = (H264_ENC_CONF_REC *)pPrivateData;

    _MP4_WRITEBUF8(au1Buffer, u4BufPos, prH264Configuration->u1ProfileIDC);
    _MP4_WRITEBUF8(au1Buffer, u4BufPos, prH264Configuration->u1ProfileComp);
    _MP4_WRITEBUF8(au1Buffer, u4BufPos, prH264Configuration->u1LevelIDC);
    _MP4_WRITEBUF8(au1Buffer, u4BufPos, prH264Configuration->u1LengthMinusOne);
    _MP4_WRITEBUF8(au1Buffer, u4BufPos, prH264Configuration->u1NumOfSPS);
    _MP4_WRITEBUF8(au1Buffer, u4BufPos, prH264Configuration->u1NumOfPPS);

    FSAL_ERR_RTN(prFileHandle, FSAL_Seek(prFileHandle, MP4_POS_H264_BASE));
    FSAL_ERR_RTN(prFileHandle, FSAL_Write(prFileHandle, au1Buffer, sizeof(au1Buffer)));

    return eError;
}


/**
 * Add the meta data of one frame to stbl buffers (stbl boxes)
 * @param prFrameInfo pointer to frame info
 *
 * @return If the function succeeds, the return value is VIDEO_ERROR_NONE
 * Otherwise, an error code is returned.
 */
VIDEO_ERROR_TYPE_T  MP4_STBL_AddOneVFrame(MP4_FRAME_INFO_T *const prFrameInfo)
{
    _MP4_STTS_AddOneFrame(&_rMP4VideoStblMgr.rStts, prFrameInfo);
    _MP4_STSC_AddOneFrame(&_rMP4VideoStblMgr.rStsc, prFrameInfo);
    _MP4_STSZ_AddOneFrame(&_rMP4VideoStblMgr.rStsz, prFrameInfo);
    _MP4_STCO_AddOneFrame(&_rMP4VideoStblMgr.rStco, prFrameInfo);
    _MP4_STSS_AddOneFrame(&_rMP4VideoStblMgr.rStss, prFrameInfo);

    return VIDEO_ERROR_NONE;
}


/**
 * Write the header of the video file.
 * @param prFSALVideo pointer to Video FSAL structure.
 * @param prFSALTmpMeta pointer to Temp Meta FSAL structure.
 *
 * @return If the function succeeds, the return value is VIDEO_ERROR_NONE
 * Otherwise, an error code is returned.
 */
VIDEO_ERROR_TYPE_T MP4_GenVideoFileHeader(STFSAL *const prFSALVideo, STFSAL *const prFSALTmpMeta,
        kal_uint32 *const pu4BitStreamOffset)
{
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 u4MdatPos;

    // FIXME: Seek to the start of the video bit-stream file?
    FSAL_ERR_RTN(prFSALVideo, FSAL_Seek(prFSALVideo, 0));

    // write video file headers
    FSAL_ERR_RTN(prFSALVideo, FSAL_Write_UINT(prFSALVideo, 24));  // size (4 bytes in length)
    FSAL_ERR_RTN(prFSALVideo, FSAL_Write_Bytes(prFSALVideo, (kal_uint8 *)"ftyp3gp4", 8));
    FSAL_ERR_RTN(prFSALVideo, FSAL_Write_UINT(prFSALVideo, 0x400));
    FSAL_ERR_RTN(prFSALVideo, FSAL_Write_Bytes(prFSALVideo, (kal_uint8 *)"3gp4isom", 8));

    // write mdat position to meta file, it will be used when create file
    FSAL_ERR_RTN(prFSALVideo, FSAL_GetCurPos(prFSALVideo, &u4MdatPos));

    VIDEO_ERR_RTN(MP4_WriteMeta(prFSALTmpMeta, MP4_POS_V_MDAT_SIZE, 4, (kal_uint8*)&u4MdatPos));

    // write mdat header to video file
    FSAL_ERR_RTN(prFSALVideo, FSAL_Write_UINT(prFSALVideo, 0));
    FSAL_ERR_RTN(prFSALVideo, FSAL_Write_Bytes(prFSALVideo, (kal_uint8 *)"mdat", 4));
    FSAL_ERR_RTN(prFSALVideo, FSAL_GetCurPos(prFSALVideo, pu4BitStreamOffset));

    return VIDEO_ERROR_NONE;
}


/**
 * Query if there is any data to write in any one of the stbl buffers.
 *
 * @return If the function succeeds, the return value is VIDEO_ERROR_NONE
 * Otherwise, an error code is returned.
 */
kal_bool MP4_STBL_HasData2Write(void)
{
    kal_uint32 u4DataAddr, u4DataSize;
    kal_bool fgHasDataToWrite = KAL_FALSE;

    do
    {
        if (_MP4_HasData2Write(&_rMP4VideoStblMgr.rStts.rBufferMgr,
            MP4_STTS_ARRAY_SIZE_IN_WORD, MP4_STTS_ARRAY_THRESHOLD_IN_BYTE, &u4DataAddr, &u4DataSize) == KAL_TRUE)
        {
            fgHasDataToWrite = KAL_TRUE;
            break;
        }


        if (_MP4_HasData2Write(&_rMP4VideoStblMgr.rStsz.rBufferMgr,
            MP4_STSZ_ARRAY_SIZE_IN_WORD, MP4_STSZ_ARRAY_THRESHOLD_IN_BYTE, &u4DataAddr, &u4DataSize) == KAL_TRUE)
        {
            fgHasDataToWrite = KAL_TRUE;
            break;
        }

        if (_MP4_HasData2Write(&_rMP4VideoStblMgr.rStco.rBufferMgr,
            MP4_STCO_ARRAY_SIZE_IN_WORD, MP4_STCO_ARRAY_THRESHOLD_IN_BYTE, &u4DataAddr, &u4DataSize) == KAL_TRUE)
        {
            fgHasDataToWrite = KAL_TRUE;
            break;
        }

        if (_MP4_HasData2Write(&_rMP4VideoStblMgr.rStss.rBufferMgr,
            MP4_STSS_ARRAY_SIZE_IN_WORD, MP4_STSS_ARRAY_THRESHOLD_IN_BYTE, &u4DataAddr, &u4DataSize) == KAL_TRUE)
        {
            fgHasDataToWrite = KAL_TRUE;
            break;
        }
    }while(0);

    return fgHasDataToWrite;
}


/**
 * Write any of the meta boxes if it has data to write.
 *
 * @return If the function succeeds, the return value is VIDEO_ERROR_NONE
 * Otherwise, an error code is returned.
 */
VIDEO_ERROR_TYPE_T MP4_STBL_WriteData(MP4_FILE_MGR_T *const prMp4FileMgr)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 u4StartTime, u4Duration;

    drv_trace0(TRACE_GROUP_10, MUX_MP4AL_BEGIN_WRITE_STBL_FILE);

    u4StartTime = video_get_current_time();
    do
    {
        MP4_STBL_BOX_BUFFER_MGR_T *prBufferMgr = &_rMP4VideoStblMgr.rStts.rBufferMgr;

        VIDEO_ERR_BREAK(_MP4_WriteBoxData(prMp4FileMgr, prBufferMgr,
                                        MP4_VIDEO_STTS_FILE, MP4_STTS_ARRAY_SIZE_IN_WORD,
                                        MP4_STTS_ARRAY_THRESHOLD_IN_BYTE));


        prBufferMgr = &_rMP4VideoStblMgr.rStsz.rBufferMgr;
        VIDEO_ERR_BREAK(_MP4_WriteBoxData(prMp4FileMgr, prBufferMgr,
                                        MP4_VIDEO_STSZ_FILE, MP4_STSZ_ARRAY_SIZE_IN_WORD,
                                        MP4_STSZ_ARRAY_THRESHOLD_IN_BYTE));

        prBufferMgr = &_rMP4VideoStblMgr.rStco.rBufferMgr;
        VIDEO_ERR_BREAK(_MP4_WriteBoxData(prMp4FileMgr, prBufferMgr,
                                        MP4_VIDEO_STCO_FILE, MP4_STCO_ARRAY_SIZE_IN_WORD,
                                        MP4_STCO_ARRAY_THRESHOLD_IN_BYTE));

        prBufferMgr = &_rMP4VideoStblMgr.rStss.rBufferMgr;
        VIDEO_ERR_BREAK(_MP4_WriteBoxData(prMp4FileMgr, prBufferMgr,
                                        MP4_VIDEO_STSS_FILE, MP4_STSS_ARRAY_SIZE_IN_WORD,
                                        MP4_STSS_ARRAY_THRESHOLD_IN_BYTE));

    }while(0);

    u4Duration = video_get_duration_ms(u4StartTime);
    drv_trace1(TRACE_GROUP_9, MUX_MP4AL_END_WRITE_STBL_FILE, u4Duration);

    return eError;
}


VIDEO_ERROR_TYPE_T MP4_STBL_FlushData(MP4_FILE_MGR_T *const prMp4FileMgr)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    do
    {
        STFSAL *prTmpMetaFile = &prMp4FileMgr->rFile[MP4_TEMP_META_FILE];
        VIDEO_ERR_BREAK(_MP4_STBL_SetDataFlushing(prTmpMetaFile));
        VIDEO_ERR_BREAK(MP4_STBL_WriteData(prMp4FileMgr));
        VIDEO_ERR_BREAK(_MP4_STBL_UpdateBoxHeader(prMp4FileMgr));
        {
            kal_uint32 u4FrameInfoCount;

            VIDEO_ERR_BREAK(_MP4_WriteAFrameSize(prTmpMetaFile, &_rMP4AudioStblMgr.u4FilePos,
                _rMP4AudioStblMgr.u4PrevFrameSize, _rMP4AudioStblMgr.u4FrameCount));

            u4FrameInfoCount = (_rMP4AudioStblMgr.u4FilePos - MP4_A_FRAMEINFO_START) / AUDIO_FRAMEINFO_SIZE;
            VIDEO_ERR_BREAK(MP4_WriteMeta(prTmpMetaFile, MP4_A_FRAMEINFO_COUNT, 4, (kal_uint8 *)&u4FrameInfoCount));
        }
        _MP4_STBL_ClearDataFlushing();
    }while(0);

    return eError;
}


/**
 * Process the STOP even.
 * @param prMp4FileMgr pointer to file mgr
 *
 * @return If the function succeeds, the return value is VIDEO_ERROR_NONE
 * Otherwise, an error code is returned.
 */
VIDEO_ERROR_TYPE_T MP4_STBL_SettleDown(MP4_FILE_MGR_T *const prMp4FileMgr)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    STFSAL *const prTmpMetaFile = &prMp4FileMgr->rFile[MP4_TEMP_META_FILE];

    do
    {
        kal_uint64 u8StopTime;
        VIDEO_ERR_BREAK(MP4_ReadMeta(prTmpMetaFile, MP4_POS_STOP_TIME,
            sizeof(kal_uint64), (kal_uint8*)&u8StopTime));

        VIDEO_ERR_BREAK(_MP4_STTS_ProcessStopTime(prTmpMetaFile,
            &prMp4FileMgr->rFile[MP4_VIDEO_STTS_FILE], &u8StopTime));
    }while(0);

    return eError;
}


VIDEO_ERROR_TYPE_T MP4_STBL_AddOneAFrame(MP4_FILE_MGR_T *const prMp4FileMgr, kal_uint32 u4FrameSize)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    STFSAL *const prTmpMetaFile = &prMp4FileMgr->rFile[MP4_TEMP_META_FILE];

    MP4_ASSERT(u4FrameSize != 0);

    // For time-limit.
    if (_rMP4AudioStblMgr.u4MaxFrameCount != 0 &&
        _rMP4AudioStblMgr.u4TotalFrameCount >= _rMP4AudioStblMgr.u4MaxFrameCount)
    {
        drv_trace1(TRACE_GROUP_9, MUX_MP4AL_AUDIO_TIME_LIMIT, _rMP4AudioStblMgr.u4MaxFrameCount);
        return VIDEO_ERROR_NONE;
    }

    if (_rMP4AudioStblMgr.u4PrevFrameSize == 0)
    {
        kal_uint32 u4FrameInfoCount = 0;
        _rMP4AudioStblMgr.u4PrevFrameSize = u4FrameSize;
        _rMP4AudioStblMgr.u4FrameCount = 1;

        VIDEO_ERR_RTN(MP4_WriteMeta(prTmpMetaFile, MP4_A_FRAMEINFO_COUNT, 4, (kal_uint8 *)&u4FrameInfoCount));
    }
    else
    {
        if (_rMP4AudioStblMgr.u4PrevFrameSize == u4FrameSize)
        {
           _rMP4AudioStblMgr.u4FrameCount++;
        }
        else
        {
            VIDEO_ERR_RTN(_MP4_WriteAFrameSize(prTmpMetaFile, &_rMP4AudioStblMgr.u4FilePos,
                _rMP4AudioStblMgr.u4PrevFrameSize, _rMP4AudioStblMgr.u4FrameCount));

            _rMP4AudioStblMgr.u4PrevFrameSize = u4FrameSize;
            _rMP4AudioStblMgr.u4FrameCount = 1;
        }
    }

    _rMP4AudioStblMgr.u4TotalFrameCount++;

    return eError;
}

/**
 * Write the header of the aidop file.
 * @param prFSALVideo pointer to audio FSAL structure.
 *
 * @return If the function succeeds, the return value is VIDEO_ERROR_NONE
 * Otherwise, an error code is returned.
 */
VIDEO_ERROR_TYPE_T MP4_GenAudioFileHeader(STFSAL *const prFSALAudio)
{
    // write mdat header to audio file
    FSAL_ERR_RTN(prFSALAudio, FSAL_Write_UINT(prFSALAudio, 0));
    FSAL_ERR_RTN(prFSALAudio, FSAL_Write_Bytes(prFSALAudio, (kal_uint8 *)"mdat", 4));

    return VIDEO_ERROR_NONE;
}


VIDEO_ERROR_TYPE_T MP4_ParseAMRHeader(kal_uint8 u1AMRType, kal_uint8 u1FrameHeader, kal_uint8 *pu1FrameLength)
{
    kal_uint8 u1FrameType;
    kal_uint8 u1FQI;

    static const kal_uint16 lenSpeechBitsAMR[] =
    {
        95, 103, 118, 134, 148, 159, 204, 244, 39
    };

    u1FrameType = (u1FrameHeader >> 3) & 0x0F;
    u1FQI = (u1FrameHeader >> 2) & 0x01;
    if (u1FQI == 0)
    {
        return VIDEO_ERROR_PARSER_ERROR;
    }

    if (u1AMRType == 0)
    {
        u1FQI = 8;   // AMR
    }
    else
    {
        u1FQI = 9;   // AMR-WB
    }

    if (u1FrameType <= u1FQI)
    {
        *pu1FrameLength = (lenSpeechBitsAMR[u1FrameType] + 7) / 8;
    }
    else if (u1FrameType == 15)
    {
        *pu1FrameLength = 0;
    }
    else
    {
        return VIDEO_ERROR_PARSER_ERROR;
    }


    return VIDEO_ERROR_NONE;
}



/**
 *
 */
VIDEO_ERROR_TYPE_T MP4_CreateMetaFile(MP4_FILE_MGR_T *const prMp4FileMgr,
                                    const kal_bool fgUsePseudoMerge,
                                    const kal_uint32 u4ClusterSize,
                                    const kal_bool fgRecordAudio,
                                    const kal_uint32 u4VideoFileSize)
{
    VIDEO_ERROR_TYPE_T eError;
    STFSAL     *prFSALTmpMeta, *prFSALRealMeta;
    kal_uint32 u4MoovBoxPos, u4FilePos;
    kal_uint32 u4BufPos = 0;
#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    kal_uint32 u4TempData;
#endif
    // box information used when create file
    MP4_BOX_MGR_T rBoxMgr;
    kal_uint8  *pau1Moov = rBoxMgr.uBoxData.au1Moov;

    prFSALTmpMeta = &prMp4FileMgr->rFile[MP4_TEMP_META_FILE];
    prFSALRealMeta = &prMp4FileMgr->rFile[MP4_REAL_META_FILE];

    // Initialize BoxMgr
    rBoxMgr.u4CreateTime    = _MP4_GetCurTime();
    rBoxMgr.u4TimeScale = BOX_TIME_SCALE;
    rBoxMgr.u4TrakID = MP4_VIDEO_TRACK_ID;
    rBoxMgr.u4ClusterSize = u4ClusterSize;
    rBoxMgr.fgUsePseudoMerge = fgUsePseudoMerge;

    VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_V_CODEC_TYPE, 4, (kal_uint8*)&rBoxMgr.u4VCodec));
    VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_V_WIDTH, 4, (kal_uint8*)&rBoxMgr.u4Width));
    VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_V_HEIGHT, 4, (kal_uint8*)&rBoxMgr.u4Height));
    VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_V_DURATION, 4, (kal_uint8*)&rBoxMgr.u4VDuration));

#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_V_ROTATEANGLE, 4, (kal_uint8*)&u4TempData));
    // For backward-compatiable
    if (u4TempData < MUXER_ROTATE_0_CW || u4TempData > MUXER_ROTATE_270_CW)
    {
        rBoxMgr.eRotateAngle = MUXER_ROTATE_0_CW;
    }
    else
    {
        rBoxMgr.eRotateAngle = (MUXER_ROTATION_ANGLE_T)u4TempData;
    }

    VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_V_HMIRROR, 4, (kal_uint8*)&u4TempData));
    // For backward-compatiable
    if (u4TempData > 1)
    {
        rBoxMgr.fgHorizontallyMirror = KAL_FALSE;
    }
    else
    {
        rBoxMgr.fgHorizontallyMirror = (kal_bool)u4TempData;
    }
#endif

    VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_A_CODEC_TYPE, 4, (kal_uint8*)&rBoxMgr.u4ACodec));
    VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_A_FRAME_COUNT, 4, (kal_uint8*)&rBoxMgr.u4AFrameCount));

    _MP4_GetAudioInfo(rBoxMgr.u4ACodec, &rBoxMgr.u4ASamplePerFrame, &rBoxMgr.u4ATimeScale, &rBoxMgr.u4ASampleSize);
    rBoxMgr.u4ADuration = rBoxMgr.u4AFrameCount * rBoxMgr.u4ASamplePerFrame;

    // moov
    FSAL_ERR_RTN(prFSALRealMeta, FSAL_Seek(prFSALRealMeta, 0));
    FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4MoovBoxPos));

    _MP4_WRITEBUF32(pau1Moov, u4BufPos, 0x0);                 // moov size
    _MP4_WRITEBUF(pau1Moov, u4BufPos, (kal_uint8*)"moov", 4);  // moov
    _MP4_WRITEFILE(prFSALRealMeta, (kal_uint8*)pau1Moov, u4BufPos);

    // moov->mvhd
    VIDEO_ERR_RTN(_MP4_ProduceMvhd(prMp4FileMgr, &rBoxMgr));

    // moov->iods
    VIDEO_ERR_RTN(_MP4_ProduceIods(prMp4FileMgr, &rBoxMgr));

    // moov->iuam
    VIDEO_ERR_RTN(_MP4_ProduceIuam(prMp4FileMgr, &rBoxMgr));

    // moov->audio trak
    if (fgRecordAudio == KAL_TRUE)
    {
        rBoxMgr.eTrakType = AUDIO_TRACK;
        rBoxMgr.u4STBLReservedSize = 0;
        rBoxMgr.u4AudioDataOffset = u4VideoFileSize;

        VIDEO_ERR_RTN(_MP4_ProduceTrak(prMp4FileMgr, &rBoxMgr));
    }

    // moov->video trak
    rBoxMgr.eTrakType = VIDEO_TRACK;
    rBoxMgr.u4STBLReservedSize = 0;

    VIDEO_ERR_RTN(_MP4_ProduceTrak(prMp4FileMgr, &rBoxMgr));

    FSAL_ERR_RTN(prFSALRealMeta, FSAL_GetCurPos(prFSALRealMeta, &u4FilePos));

    // update box size
    FSAL_ERR_RTN(prFSALRealMeta, FSAL_Write_UINT_AT(prFSALRealMeta, u4FilePos - u4MoovBoxPos + rBoxMgr.u4STBLReservedSize, u4MoovBoxPos));
    FS_Commit(prFSALRealMeta->hFile);

    return VIDEO_ERROR_NONE;
}


void MP4_GetVideoBoxSize(MP4_GET_BOX_SIZE_T *const pParam)
{
    const kal_uint32 u4SttsEntrySize = 8;
    const kal_uint32 u4StcoEntrySize = 4;
    const kal_uint32 u4SkipBoxSize = 8;

    pParam->u4DefaultBoxSize = DEFAULT_VIDEO_BOX_SIZE + STSD_MAX_SIZE + STSC_MAX_SIZE;
    pParam->u4StszBoxSize = _rMP4VideoStblMgr.rStsz.rBufferMgr.u4TotalSize + u4SkipBoxSize;
    pParam->u4StcoBoxSize = _rMP4VideoStblMgr.rStco.rBufferMgr.u4TotalSize + u4StcoEntrySize;
    pParam->u4SttsBoxSize = _rMP4VideoStblMgr.rStts.rBufferMgr.u4TotalSize + u4SttsEntrySize + u4SkipBoxSize;
    pParam->u4StssBoxSize = _rMP4VideoStblMgr.rStss.rBufferMgr.u4TotalSize + u4SkipBoxSize;
}


kal_uint32 MP4_GetAudioBoxSize(const kal_uint32 u4ReservedAudioFrameCount)
{
    kal_uint32 u4StszSize = 0;
    kal_uint32 u4StcoSize = 0;
    const kal_uint32 u4StszHeaderSize = 20;
    const kal_uint32 u4StcoHeaderSize = 16;

    kal_uint32 u4AFrameCount = _rMP4AudioStblMgr.u4TotalFrameCount + u4ReservedAudioFrameCount;
    u4StszSize =  u4StszHeaderSize + u4AFrameCount * 4;
    u4StcoSize =  u4StcoHeaderSize + ((u4AFrameCount / MP4_ASAMPLES_PER_CHUNK) + 1) * 4;

    return  (DEFAULT_AUDIO_BOX_SIZE) +
            (STSD_A_SIZE + STTS_A_SIZE + STSC_MAX_SIZE)+
            (u4StszSize + u4StcoSize);
}


kal_uint32 MP4_GetAudioFrameCount(void)
{
    return _rMP4AudioStblMgr.u4TotalFrameCount;
}


kal_uint32 MP4_GetVideoDuration(void)
{
    return _rMP4VideoStblMgr.u4TotalDuration * (1000000 / BOX_TIME_SCALE);
}

void MP4_SetAudioTimeLimit(kal_uint32 u4MaxFrameCount)
{
    _rMP4AudioStblMgr.u4MaxFrameCount = u4MaxFrameCount;
}

kal_uint32 MP4_GetTempFileSize(void)
{
    return _rMP4AudioStblMgr.u4FilePos;
}

#endif  // __VE_SUPPORT_MP4_MUXER_ADAPTER__
#endif  // __VE_VIDEO_ARCHI_V2__

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

