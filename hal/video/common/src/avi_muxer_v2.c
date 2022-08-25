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
 *   avi_muxer_v2.c
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

#if defined(__VE_VIDEO_ARCHI_V2__)
#if defined(__VE_SUPPORT_AVI_MUXER__)

#include "kal_public_api.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "fs_type.h"

#include "video_muxer_if_v2.h"
#include "avi_muxer_v2.h"
#include "avi_muxer_if_v2.h"
#include "drv_comm.h"
#include "vcodec_v2_trc.h"
#include "video_buffer_management_v2.h"

//#define __DEBUG_AVI_MUXER__

#if defined(__DEBUG_AVI_MUXER__)
    #define _AVI_MUXER_ASSERT() do{ASSERT(0);}while(0)
#else
    #define _AVI_MUXER_ASSERT() do{}while(0)
#endif

VIDEO_ERROR_TYPE_T _AVI_MuxerFSWrite_Internal(FS_HANDLE rFileHandle, void * const pu1Data, const kal_uint32 u4Size);

//#define __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__

#define _AVI_INDEX_FILE_OFFSET  (_SIZE_4CC + _SIZE_CHUNK_SIZE)
#define _AVI_CHUNK_BUFFER_SIZE 512
#define _AVI_TEMP_FILE_COUNT    (3)
#define _AVI_MARGIN_SIZE    (2*32*1024)

#define _AVI_MUXER_FSWRITE(rhandle, pu1Data, u4Size) \
    do{                                                                 \
        VIDEO_ERROR_TYPE_T eFSRet = VIDEO_ERROR_NONE;                   \
        eFSRet = _AVI_MuxerFSWrite_Internal(rhandle, (void*)pu1Data, u4Size);    \
        if (VIDEO_ERROR_NONE != eFSRet)                                 \
        {                                                               \
            return eFSRet;                                              \
        }                                                               \
    }while(0)

static _AVI_MUXER_CTRL_T _rAVICtrl;
static _AVI_CONFIG_T _rAVIConfig;

static void _AVI_MuxerWriteBuffer32(kal_uint8 * const _pau1Buffer, kal_uint32 * const pu4Pos, kal_uint32 u4Data, const kal_uint32 u4Len)
{
    *(kal_uint8*)(_pau1Buffer + (*pu4Pos)) = ((u4Data) & 0xFF);
    *(kal_uint8*)(_pau1Buffer + (*pu4Pos) + 1) = ((u4Data) & 0xFF00) >> 8;
    *(kal_uint8*)(_pau1Buffer + (*pu4Pos) + 2) = ((u4Data) & 0xFF0000) >> 16;
    *(kal_uint8*)(_pau1Buffer + (*pu4Pos) + 3) = (u4Data) >> 24;
    ((*pu4Pos)) += 4;
}

static void _AVI_MuxerWriteList(kal_uint8 * const pau1Buffer, kal_uint32 * const pu4Pos, const kal_uint32 u4List, const kal_uint32 u4Size, const kal_uint32 u4FourCC)
{
    _AVI_MuxerWriteBuffer32(pau1Buffer, pu4Pos, u4List, 4);
    _AVI_MuxerWriteBuffer32(pau1Buffer, pu4Pos, u4Size, 4);
    _AVI_MuxerWriteBuffer32(pau1Buffer, pu4Pos, u4FourCC, 4);
}

static void _AVI_MuxerWriteChunk(kal_uint8 * const pau1Buffer, kal_uint32 * const pu4Pos, const kal_uint32 u4FourCC, const kal_uint32 u4Size, kal_uint8 *const pData)
{
    _AVI_MuxerWriteBuffer32(pau1Buffer, pu4Pos, u4FourCC, 4);
    _AVI_MuxerWriteBuffer32(pau1Buffer, pu4Pos, u4Size, 4);
    // Write N bytes
    kal_mem_cpy((kal_uint8*)pau1Buffer + (*pu4Pos), pData, u4Size);
    (*pu4Pos) += u4Size;
}


static void _AVI_AppendFileName2Path(
    kal_uint8 * const pau1FullFileName,                 // out
    const kal_wchar * const pau2FilePath,               // in
    const kal_wchar * const pau2AppendingFileName       // in
    )
{
    kal_wstrcpy((kal_wchar*)pau1FullFileName, pau2FilePath);
    MuxerAdaptRemoveFileName((kal_wchar*) pau1FullFileName);
    kal_wstrcat((kal_wchar*)pau1FullFileName, pau2AppendingFileName);
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerOpen(void)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;

    kal_mem_set((void*)_prCtrl, 0, sizeof(*_prCtrl));
    kal_mem_set((void*)&_rAVIConfig, 0, sizeof(_rAVIConfig));

    _rAVIConfig.pau2FilePath = MuxerGetMemory(_AVI_FILE_PATH_SIZE, KAL_FALSE);
    _rAVIConfig.pau2WorkingPath = MuxerGetMemory(_AVI_WORKING_PATH_SIZE, KAL_FALSE);
    _rAVIConfig.pau2FilePath[0] = 0;
    _rAVIConfig.pau2WorkingPath[0] = 0;
    return VIDEO_ERROR_NONE;
}

static kal_uint32 _AVI_MuxerRoundedAddOne(
    const kal_uint32 u4Augend,
    const kal_uint32 u4UpperBound)
{
    const kal_uint32 u4Addend = 1;
    kal_uint32 u4Tmp = u4Augend + u4Addend;

    return (u4Tmp > u4UpperBound)? (0):(u4Tmp);
}

static void _AVI_CloseFile(FS_HANDLE *prHandle)
{
    if (*prHandle > 0)
    {
        FS_Close(*prHandle);
        *prHandle = -1;
    }
}

static void _AVI_CloseAllFiles(void)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;

    _AVI_CloseFile(&_prCtrl->rDataHandle);
    _AVI_CloseFile(&_prCtrl->rIdxHandle);
    _AVI_CloseFile(&_prCtrl->rInfoHandle);
}

static FS_HANDLE _AVI_DeleteFileAndOpen(kal_uint8* const pau1DestFileNameBuffer, const kal_wchar* const pau2FilePath, const kal_wchar* const pau2FileName)
{
    FS_HANDLE rHandle;

    _AVI_AppendFileName2Path(pau1DestFileNameBuffer,
                             pau2FilePath,
                             pau2FileName);

    FS_Delete((kal_wchar*)pau1DestFileNameBuffer);
    rHandle = FS_Open((kal_wchar*) pau1DestFileNameBuffer, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);

    return rHandle;
}

static void _AVI_CallBack(const kal_uint32 u4Event, void* const pParam)
{
    _AVI_CONFIG_T* _prConfig = &_rAVIConfig;

    _prConfig->pfnCallback(u4Event, pParam);
}

static void _AVI_MuxerWrite2ActiveBuffAndUpdateStatus(_AVI_BUFFER_CTRL_T* const prBufferCtrl, kal_uint8* const pu1Data, const kal_uint32 u4Size)
{
    const kal_uint32 u4BuffIdx = prBufferCtrl->u1ActiveBuffIdx;
    const _AVI_BUFF_STATE_T eState = prBufferCtrl->aeBuffState[u4BuffIdx];
    const kal_uint32 u4BuffWritten = prBufferCtrl->au4BuffWritten[u4BuffIdx];
    const kal_uint8* const pu1BuffStart = prBufferCtrl->apu1Buff[u4BuffIdx];
    kal_uint8* pu1Buff;

    pu1Buff = (kal_uint8*)pu1BuffStart;
    pu1Buff += u4BuffWritten;

    drv_trace4(TRACE_GROUP_10, MUXAVI_WRITE_2_BUFFER, (kal_uint32)pu1Data, u4Size, (kal_uint32)pu1BuffStart, u4BuffWritten);

    if ((AVAILABLE != eState)||
        (prBufferCtrl->u4WriteThreshold < (u4BuffWritten + u4Size)))
    {
        AVI_ASSERT(0);
    }

    kal_mem_cpy((void*)pu1Buff, (void*)pu1Data, u4Size);
    prBufferCtrl->au4BuffWritten[u4BuffIdx] += u4Size;

    if (prBufferCtrl->u4WriteThreshold == prBufferCtrl->au4BuffWritten[u4BuffIdx])
    {
        drv_trace2(TRACE_GROUP_10, MUXAVI_BUFFER_RDY_2_WRITE, (kal_uint32)pu1BuffStart, prBufferCtrl->au4BuffWritten[u4BuffIdx]);
        prBufferCtrl->aeBuffState[u4BuffIdx] = WAITING_2_WRITE;
    }
}

static void _AVI_MuxerWrite2DataBuffer(kal_uint8* const pu1Data, const kal_uint32 u4Size)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    _AVI_BUFFER_CTRL_T* const prBufferCtrl = _prCtrl->prDataBuffCtrl;
    const kal_uint32 u4BuffIdx = prBufferCtrl->u1ActiveBuffIdx;
    kal_uint32 u4LeftOver = 0;
    const kal_uint32 u4WriteThreshold = prBufferCtrl->u4WriteThreshold;
    kal_uint8 *pu1ActiveBuffIdx = &prBufferCtrl->u1ActiveBuffIdx;

    u4LeftOver = u4WriteThreshold - prBufferCtrl->au4BuffWritten[u4BuffIdx];

    _prCtrl->u8CurrentFileSize += u4Size;

    if (u4Size < u4LeftOver)
    {
        _AVI_MuxerWrite2ActiveBuffAndUpdateStatus(prBufferCtrl, pu1Data, u4Size);
    }
    else
    {
        const kal_uint32 u4Param = MX_DATATYPE_DATA;
        kal_int32 i4RemainSize = u4Size - u4LeftOver;
        kal_uint32 u4Offset = u4LeftOver;

        _AVI_MuxerWrite2ActiveBuffAndUpdateStatus(prBufferCtrl, pu1Data, u4LeftOver);
        do
        {
            *pu1ActiveBuffIdx = _AVI_MuxerRoundedAddOne(*pu1ActiveBuffIdx, (_AVI_DATA_BUFF_NUM - 1));
            if (i4RemainSize < u4WriteThreshold)
            {
                _AVI_MuxerWrite2ActiveBuffAndUpdateStatus(prBufferCtrl, (pu1Data + u4Offset), i4RemainSize);
                i4RemainSize = 0;
                //u4Offset += i4RemainSize;  //not necessary actually
            }
            else
            {
                _AVI_MuxerWrite2ActiveBuffAndUpdateStatus(prBufferCtrl, (pu1Data + u4Offset), u4WriteThreshold);
                i4RemainSize -= u4WriteThreshold;
                u4Offset += u4WriteThreshold;

                if (i4RemainSize == 0)
                {
                    // Update index
                    *pu1ActiveBuffIdx = _AVI_MuxerRoundedAddOne(*pu1ActiveBuffIdx, (_AVI_DATA_BUFF_NUM - 1));
                }
            }
        }while(i4RemainSize > 0);

        _AVI_CallBack(AVI_EVENT_RDY_2_WRITE_DATA, (void*)&u4Param);
    }

    _prCtrl->u4TotalAVDataWritten += u4Size;
}

static void _AVI_MuxerWrite2IdxBuffer(kal_uint8* const pu1Data, const kal_uint32 u4Size)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    _AVI_BUFFER_CTRL_T* const prBufferCtrl = _prCtrl->prIdxBuffCtrl;
    const kal_uint32 u4BuffIdx = prBufferCtrl->u1ActiveBuffIdx;
    kal_uint32 u4LeftOver = 0;

    u4LeftOver = prBufferCtrl->u4WriteThreshold - prBufferCtrl->au4BuffWritten[u4BuffIdx];

    _prCtrl->u8CurrentFileSize += u4Size;

    if (u4Size < u4LeftOver)
    {
        _AVI_MuxerWrite2ActiveBuffAndUpdateStatus(prBufferCtrl, pu1Data, u4Size);
    }
    else
    {
        _AVI_MuxerWrite2ActiveBuffAndUpdateStatus(prBufferCtrl, pu1Data, u4LeftOver);
        prBufferCtrl->u1ActiveBuffIdx = _AVI_MuxerRoundedAddOne(u4BuffIdx, (_AVI_IDX_BUFF_NUM - 1));

#if defined(_SUPPORT_BIG_FRAME_SIZE_ONLY_)
        if (_prCtrl->u4IdxBufferSize == 0)
        {
            kal_mem_cpy(_prCtrl->u1IdxBuffer, (pu1Data + u4LeftOver), (u4Size - u4LeftOver));
            _prCtrl->u4IdxBufferSize = u4Size - u4LeftOver;
        }
        else
        {
            AVI_ASSERT(0);
        }
#else
        _AVI_MuxerWrite2ActiveBuffAndUpdateStatus(prBufferCtrl, (pu1Data + u4LeftOver), (u4Size - u4LeftOver));
#endif
        {
            kal_uint32 u4Tmp = MX_DATATYPE_IDX;
            _AVI_CallBack(AVI_EVENT_RDY_2_WRITE_IDX, (void*)&u4Tmp);
        }
    }
}

static void _AVI_MuxerInitializeBufferCtrl(
    _AVI_BUFFER_CTRL_T** const pprBufferCtrl,
    const kal_uint32 u4WriteThreshold,
    const kal_uint32 u4OneBufferSize,
    const kal_uint32 u4BufferNum)
{
    kal_uint32 i = 0;

    *pprBufferCtrl = (_AVI_BUFFER_CTRL_T*)MuxerAdaptGetMemory(sizeof(_AVI_BUFFER_CTRL_T), KAL_TRUE);
    kal_mem_set(*pprBufferCtrl, 0, sizeof(_AVI_BUFFER_CTRL_T));
    (*pprBufferCtrl)->u4WriteThreshold = u4WriteThreshold;
    (*pprBufferCtrl)->u4BufferNum = u4BufferNum;
    (*pprBufferCtrl)->u4BufferSize = u4OneBufferSize * u4BufferNum;

    do
    {
        (*pprBufferCtrl)->apu1Buff[i] = (kal_uint8*)MuxerAdaptGetMemory(u4OneBufferSize, KAL_TRUE);
        (*pprBufferCtrl)->aeBuffState[i] = AVAILABLE;
        (*pprBufferCtrl)->au4BuffWritten[i] = 0;
    }while(++i < u4BufferNum);
}

static void _AVI_MuxerDeInitializeBufferCtrl(
    _AVI_BUFFER_CTRL_T** const pprBufferCtrl,
    const kal_uint32 u4BufferNum)
{
    kal_uint32 i = 0;

    do
    {
        MuxerAdaptFreeMemory((*pprBufferCtrl)->apu1Buff[i]);
    }while(++i < u4BufferNum);

    MuxerAdaptFreeMemory(*pprBufferCtrl);
}

static kal_uint32 _AVI_MuxerGetDataFileOffset(const kal_bool fgRecordAudio)
{
    kal_uint32 u4Temp = 0;

    /* (RIFF.4.AVI .)*/
    u4Temp += _SIZE_LIST_TAG + _SIZE_LIST_SIZE + _SIZE_4CC;
    /* LIST.4.hdlr.avih.4.(file header)*/
    u4Temp += _SIZE_LIST_TAG + _SIZE_LIST_SIZE + _SIZE_4CC + _SIZE_4CC + _SIZE_CHUNK_SIZE + sizeof(_AVI_FILE_HEADER_T);
    /* LIST.4.strl.strh.4.(video header)*/
    u4Temp += _SIZE_LIST_TAG + _SIZE_LIST_SIZE + _SIZE_4CC + _SIZE_4CC + _SIZE_CHUNK_SIZE + sizeof(_AVI_STREAM_HEADER_T);
    /* .strf.4.(video format)*/
    u4Temp += _SIZE_4CC + _SIZE_CHUNK_SIZE + sizeof(_AVI_VIDEO_FORMAT_HEADER_T);
    if (KAL_TRUE == fgRecordAudio)
    {
        /* LIST.4.strl.strh.4.(audio header)*/
        u4Temp += _SIZE_LIST_TAG + _SIZE_LIST_SIZE + _SIZE_4CC + _SIZE_4CC + _SIZE_CHUNK_SIZE + sizeof(_AVI_STREAM_HEADER_T);
        /* .strf.4.(audio format)*/
        u4Temp += _SIZE_4CC + _SIZE_CHUNK_SIZE + sizeof(_AVI_AUDIO_FORMAT_HEADER_T);
    }
    /* .IUAM.4.(website)*/
    u4Temp += _SIZE_4CC + _SIZE_CHUNK_SIZE + _AVI_MTK_BOX_SIZE;

#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    // .TRNS.4.(rotation/mirror info)
    u4Temp += (_SIZE_4CC + _SIZE_CHUNK_SIZE + _AVI_TRNS_CHUNK_SIZE);
#endif
    /* LIST.4.movi.*/
    u4Temp += _SIZE_LIST_TAG + _SIZE_LIST_SIZE + _SIZE_4CC;

    return u4Temp;
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerInit(void)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    _AVI_CONFIG_T* const _prConfig = &_rAVIConfig;

    _prCtrl->pau1DataFileName = (kal_uint8*)MuxerAdaptGetMemory(_AVI_FILE_PATH_SIZE, KAL_TRUE);
    _prCtrl->pau1IdxFileName  = (kal_uint8*)MuxerAdaptGetMemory(_AVI_FILE_PATH_SIZE, KAL_TRUE);

    if (MUXER_SCENARIO_RECORD == _prConfig->eScenario)
    {
        // Get cluster size
        MuxerAdaptGetDiskInfo(_prConfig->pau2WorkingPath, &_prCtrl->u4ClusterSize, &_prCtrl->u8FreeDiskSize);


        /*
         * [AVI File Format] for MJPEG
         *
         * = Data File ========================
         * RIFF.4.AVI .
         *     LIST.4.hdlr.avih.4.(file header)
         *     LIST.4.strl.strh.4.(video header)
         *                .strf.4.(video format)
         *     LIST.4.strl.strh.4.(audio header)
         *                .strf.4.(audio format)
         *     JUNK.4.(junk)
         *     LIST.4.movi.xxdb.4.(video data)
         *                 xxdc.4.(video data)
         *                 xxwb.4.(audio data)
         * = Idx File =========================
         *            idx1.4.(list data)
         * ====================================
         */

        /* data file - avi header and data chunk file  */
        _prCtrl->rDataHandle = _AVI_DeleteFileAndOpen(_prCtrl->pau1DataFileName, _prConfig->pau2WorkingPath, _AVI_VISUAL_FILE);
        if (_prCtrl->rDataHandle <= 0)
        {
            goto ERROR_HANDLING;
        }
        /* seek to movi chunk */
        _prCtrl->u4AVDataOffset = _AVI_MuxerGetDataFileOffset(_prConfig->rAudioConfig.fgRecordAudio);

        /* idx file */
        _prCtrl->rIdxHandle = _AVI_DeleteFileAndOpen(_prCtrl->pau1IdxFileName, _prConfig->pau2WorkingPath, _AVI_IDX_FILE);
        if (_prCtrl->rIdxHandle <= 0)
        {
            goto ERROR_HANDLING;
        }

        _AVI_MuxerInitializeBufferCtrl(&_prCtrl->prDataBuffCtrl, _AVI_WRITEDATA_THRESHOLD,
                                        _AVI_ONE_DATA_BUFF_SIZE, _AVI_DATA_BUFF_NUM);

        _AVI_MuxerInitializeBufferCtrl(&_prCtrl->prIdxBuffCtrl, _AVI_WRITEINDEX_THRESHOLD,
                                        _AVI_ONE_IDX_BUFF_SIZE, _AVI_IDX_BUFF_NUM);

        _AVI_MuxerWrite2ActiveBuffAndUpdateStatus(_prCtrl->prDataBuffCtrl, NULL, _prCtrl->u4AVDataOffset);
        _AVI_MuxerWrite2ActiveBuffAndUpdateStatus(_prCtrl->prIdxBuffCtrl, NULL, _AVI_INDEX_FILE_OFFSET);

        // Intentionally open info file later than data file and idx file to avoid fragmentation after recording
        // due to open and delete this info file
        {
            kal_uint8* const pau1InfoFileName = (kal_uint8*)get_ctrl_buffer(_AVI_FILE_PATH_SIZE);
            _prCtrl->rInfoHandle = _AVI_DeleteFileAndOpen(pau1InfoFileName, _prConfig->pau2WorkingPath, _AVI_INFO_FILE);
            free_ctrl_buffer(pau1InfoFileName);
        }
        if (_prCtrl->rInfoHandle <= 0)
        {
            goto ERROR_HANDLING;
        }

        //Setup size limit
        {
            kal_uint64 *pu8SizeLimit = &_prConfig->u8SizeLimit;
            if (0 != *pu8SizeLimit)
            {
                _prCtrl->fgSetSizeLimit = KAL_TRUE;
                if (*pu8SizeLimit < _prCtrl->u8FreeDiskSize)
                {
                    _prCtrl->u8CurrentFileSize = _prCtrl->u4ClusterSize;
                }
                else
                {
                    *pu8SizeLimit = (_prCtrl->u8FreeDiskSize);
                    _prCtrl->u8CurrentFileSize = _prCtrl->u4ClusterSize * _AVI_TEMP_FILE_COUNT;
                }
            }
            else
            {
                _prCtrl->fgSetSizeLimit = KAL_FALSE;
                *pu8SizeLimit = _prCtrl->u8FreeDiskSize;
                _prCtrl->u8CurrentFileSize = _prCtrl->u4ClusterSize * _AVI_TEMP_FILE_COUNT;
            }

            if (*pu8SizeLimit >= _AVI_MAX_FILE_SIZE_OF_AVI_10)
            {
                *pu8SizeLimit = _AVI_MAX_FILE_SIZE_OF_AVI_10;
            }
        }
        //Setup time limit
        if (0 != _prConfig->u4TimeLimit)
        {
            const kal_uint32 u4SampleSize = _prConfig->rAudioConfig.u4AudioFrameSize;

            _prCtrl->u4MaxAudioDataWritten = ((_prConfig->u4TimeLimit + u4SampleSize - 1) / u4SampleSize) * u4SampleSize;
        }
        else
        {
            _prCtrl->u4MaxAudioDataWritten = 0;
        }
    }

    else if (MUXER_SCENARIO_CREATE_FILE == _prConfig->eScenario)
    {
    }
    else
    {
        _AVI_MUXER_ASSERT();
    }

    return VIDEO_ERROR_NONE;

ERROR_HANDLING:
    _AVI_CloseAllFiles();

    return VIDEO_ERROR_MUXER_ERROR;
}

static kal_bool _AVI_MuxerCheckTempFile(const kal_wchar* const pwszWorkingPath, const kal_wchar* const pau2FileName)
{
    kal_wchar* const pau2TempFileName = (kal_wchar*)get_ctrl_buffer(_AVI_FILE_PATH_SIZE);
    kal_int32 i4FSRet;

    kal_wstrcpy(pau2TempFileName , pwszWorkingPath);
    MuxerAdaptRemoveFileName((kal_wchar*) pau2TempFileName);
    kal_wstrcat(pau2TempFileName , pau2FileName);
    i4FSRet = FS_CheckFile(pau2TempFileName);
    free_ctrl_buffer((void*)pau2TempFileName);

    if (i4FSRet == FS_NO_ERROR)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerDoesTempFileExist(const kal_wchar* const pwszWorkingPath)
{
    kal_bool fsExistDataFile = KAL_FALSE;
    kal_bool fgExistIdxFile = KAL_FALSE;
    kal_bool fgExistInfoFile = KAL_FALSE;

    fsExistDataFile = _AVI_MuxerCheckTempFile(pwszWorkingPath, _AVI_VISUAL_FILE);
    fgExistIdxFile = _AVI_MuxerCheckTempFile(pwszWorkingPath, _AVI_IDX_FILE);
    fgExistInfoFile = _AVI_MuxerCheckTempFile(pwszWorkingPath, _AVI_INFO_FILE);

    if ((KAL_TRUE == fsExistDataFile) &&
        (KAL_TRUE == fgExistIdxFile) &&
        (KAL_TRUE == fgExistInfoFile))
    {
        return VIDEO_ERROR_MUXER_EXIST_TEMP_FILE;
    }

    return VIDEO_ERROR_MUXER_NO_TEMP_FILE;
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerDirectlyGetParam(VIDEO_PARAM_TYPE_T eType, void *pParam)
{
    switch(eType)
    {
        case MUXER_IS_TEMP_FILE_EXISTED:
            return _AVI_MuxerDoesTempFileExist((kal_wchar*)pParam);
        case MUXER_GET_MIN_SPACE_TO_RECORD:
            {
                MUXER_GET_MIN_SPACE_T* const pTemp = (MUXER_GET_MIN_SPACE_T*)pParam;

                // the size of a raw video frame + one cluster size
                // (MPL doesn't know working path so we assumed cluster size is 32 *1024)
                pTemp->u4MinSpace = ((pTemp->u4Height * pTemp->u4Width * 3) >> 1) + (32 * 1024) * _AVI_TEMP_FILE_COUNT + (_AVI_MARGIN_SIZE); // visual/idx/info file overhead
            }
            break;
        case MUXER_GET_VIDEO_BITSTREAM_LEFTOVER:
        case MUXER_GET_AUDIO_HEADERSIZE:
            *(kal_uint32*)pParam = 0;
            break;

        default:
            return VIDEO_ERROR_MUXER_NOT_SUPPORT;
    }

    return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerGetParam(VIDEO_PARAM_TYPE_T eType, void *pParam)
{
    const _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;

    switch(eType)
    {
        case MUXER_GET_CURRENT_FILE_SIZE:
            *(kal_uint64*)pParam = _prCtrl->u8CurrentFileSize;
            break;
        case MUXER_GET_MEMORY_SIZE:
            if (_rAVIConfig.eScenario== MUXER_SCENARIO_CREATE_FILE)
            {
                *(kal_uint32*)pParam = AVI_MUXER_TOTAL_MERGE_FILE_EXT_MEM_SIZE;
            }
            else
            {
                *(kal_uint32*)pParam = AVI_MUXER_TOTAL_EXT_MEM_SIZE;
            }
            break;
        case MUXER_GET_RETURNING_VIDEO_BUFFER_NUMBER:
        case MUXER_GET_RETURNING_AUDIO_BUFFER_NUMBER:
            *(kal_uint32*)pParam = 1;
            break;
        default:
            return VIDEO_ERROR_MUXER_NOT_SUPPORT;
    }

    return VIDEO_ERROR_NONE;
}

static void _AVI_MuxerDeleteOneTempFile(
    const kal_wchar* const pwszWorkingPath,
    const kal_wchar* const pau2FileName)
{
    kal_wchar* const pau2TempFileName = (kal_wchar*)get_ctrl_buffer(_AVI_FILE_PATH_SIZE);

    kal_wstrcpy(pau2TempFileName, pwszWorkingPath);
    MuxerAdaptRemoveFileName(pau2TempFileName);
    kal_wstrcat(pau2TempFileName, pau2FileName);
    FS_Delete(pau2TempFileName);

    free_ctrl_buffer((void*)pau2TempFileName);
}

static void _AVI_MuxerDeleteTempFile(const kal_wchar* const pwszWorkingPath)
{
    _AVI_MuxerDeleteOneTempFile(pwszWorkingPath, _AVI_VISUAL_FILE);
    _AVI_MuxerDeleteOneTempFile(pwszWorkingPath, _AVI_IDX_FILE);
    _AVI_MuxerDeleteOneTempFile(pwszWorkingPath, _AVI_INFO_FILE);
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerDirectlySetParam(VIDEO_PARAM_TYPE_T eType, void *pParam)
{
    switch(eType)
    {
        case MUXER_CLEAR_TEMP_FILE:
            _AVI_MuxerDeleteTempFile((kal_wchar*)pParam);
            break;
        case MUXER_SET_VIDEO_WRITE_THRESHOLD:
            break;
        default:
            return VIDEO_ERROR_MUXER_NOT_SUPPORT;
    };

    return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerSetParam(VIDEO_PARAM_TYPE_T eType, void *pParam)
{
    _AVI_CONFIG_T* _prConfig = &_rAVIConfig;

    switch(eType)
    {
        case MUXER_SET_VIDEO_CONFIG:
            _prConfig->rVideoConfig = *(MUXER_VIDEO_CONFIG_T*)(pParam);
            break;
        case MUXER_SET_AUDIO_CONFIG:
            _prConfig->rAudioConfig = *(MUXER_AUDIO_CONFIG_T*)(pParam);
            break;
        case MUXER_SET_WORKING_PATH:
            kal_wstrcpy((void*)_prConfig->pau2WorkingPath, pParam);
            break;
        case MUXER_SET_FILE_NAME_PATH:
            kal_wstrcpy((void*)_prConfig->pau2FilePath, pParam);
            break;
        case MUXER_SET_CALLBACK:
            _prConfig->pfnCallback = (PFN_CALLBACK)(pParam);
            break;
        case MUXER_SET_SCENARIO:
            _prConfig->eScenario = *(MUXER_SCENARIO_T*)pParam;
            break;
        case MUXER_SET_SIZE_LIMIT:
            _prConfig->u8SizeLimit = *(kal_uint64*)(pParam);
            break;
        case MUXER_SET_TIME_LIMIT:
            _prConfig->u4TimeLimit = *(kal_uint32*)(pParam);
            break;
        case MUXER_SET_VIDEO_WRITE_THRESHOLD:
            break;
#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
        case MUXER_SET_TIME_LAPSE_FRAME_RATE:
            _prConfig->u4TLFrameRate = *(kal_uint32*)(pParam);
            break;
#endif
        default:
            return VIDEO_ERROR_MUXER_NOT_SUPPORT;
    };

    return VIDEO_ERROR_NONE;
}

static void _AVI_ReturnBitstream(const kal_uint32 u4DataType, const kal_uint64 * const pu8TimeStamp, kal_uint8* const pu1Addr, const kal_uint32 u4Size)
{
    MUXER_PROCESS_PARAM_T rParam;

    rParam.u4DataType = u4DataType;
    rParam.u8TimeStamp = *pu8TimeStamp;
    rParam.arData[0].fgValid = KAL_TRUE;
    rParam.arData[0].pu1Addr = pu1Addr;
    rParam.arData[0].u4Size = u4Size;
	rParam.arData[1].fgValid = KAL_FALSE;

    drv_trace4(TRACE_GROUP_10, MUXAVI_RETURN_BITSTREAM, u4DataType, (kal_uint32)pu1Addr, u4Size, 0);

    _AVI_CallBack(MP4_EVENT_RETURN_BUFFER, (void*)&rParam);
}

static kal_bool _AVI_ReachSizeLimit(const kal_uint64 u8SizeToBeAdded)
{
    const _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    const _AVI_CONFIG_T* _prConfig = &_rAVIConfig;

    if (_prCtrl->u8CurrentFileSize + u8SizeToBeAdded >= _prConfig->u8SizeLimit)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}

__inline static kal_uint32 _AVI_GetAudioSizeToWrite(const kal_uint32 u4TotalAudioSize)
{
    const _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    kal_uint32 u4RemainSpace = 0;
    kal_uint32 u4AudioSize = u4TotalAudioSize;

    if (0 != _prCtrl->u4MaxAudioDataWritten)
    {
        u4RemainSpace = _prCtrl->u4MaxAudioDataWritten - _prCtrl->u4AudioDataWritten;
        if (u4AudioSize > u4RemainSpace)
        {
            u4AudioSize = u4RemainSpace;
        }
    }

    return u4AudioSize;
}

static void _AVI_MuxerWriteIdx(
    const void * const u1Id,
    const kal_uint32 u4flag,
    const kal_uint32 u4ChunkOffset,
    const kal_uint32 u4ChunkLenght)
{
    _AVI_INDEX_T rIndex;
    kal_mem_cpy((void*)&rIndex.chunk_id, u1Id, 4);
    rIndex.flag = u4flag;
    rIndex.chunk_offset = u4ChunkOffset;
    rIndex.chunk_lenght = u4ChunkLenght;
    _AVI_MuxerWrite2IdxBuffer((kal_uint8*)(&rIndex), sizeof(rIndex));
}

#if defined(_SUPPORT_BIG_FRAME_SIZE_ONLY_)
__inline static kal_uint32 _AVI_MuxerGetDataBufferLeftOver(void)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    _AVI_BUFFER_CTRL_T* const prBufferCtrl = _prCtrl->prDataBuffCtrl;

    return prBufferCtrl->u4BufferSize - prBufferCtrl->au4BuffWritten[prBufferCtrl->u1ActiveBuffIdx];
}

static kal_bool _AVI_MuxerCheckDataBufferFull(const kal_uint32 u4DataType, const kal_uint32 u4Size, const MUXER_PROCESS_PARAM_T * const pParam)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    kal_uint32 u4DataBufferLeftOver = _AVI_MuxerGetDataBufferLeftOver();
    kal_uint32 u4DataSize = u4Size + 8;

    //if (u4DataSize > u4DataBufferLeftOver)
    {
        AVI_UNFINISHED_PARAM_T *const prUnfinishedBuffer = &_prCtrl->rUnfinishedBuffer;

        drv_trace4(TRACE_GROUP_10, MUXAVI_ADD_2_UNFINSIHED_BUFFER, u4DataType, u4DataSize, u4DataBufferLeftOver, 0);

        if (prUnfinishedBuffer->fgIsValid == KAL_TRUE)
        {
            AVI_ASSERT(0);
        }

        prUnfinishedBuffer->fgHeaderValid = KAL_TRUE;
        prUnfinishedBuffer->fgIsValid = KAL_TRUE;
        prUnfinishedBuffer->u4DataType = u4DataType;
        prUnfinishedBuffer->u4Size = u4Size;
        prUnfinishedBuffer->u8TimeStamp = pParam->u8TimeStamp;
        kal_mem_cpy(&prUnfinishedBuffer->arData, pParam->arData, MAX_BUFFER_PARTITION * sizeof(MUXER_BUFFER_T));
        {
            const kal_uint32 u4DataType = MX_DATATYPE_DATA;
            _AVI_CallBack(AVI_EVENT_RDY_2_WRITE_DATA, (void*)&u4DataType);
        }
        return KAL_TRUE;
    }

    return KAL_FALSE;
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerWriteData2FileSubDirect(kal_uint8 *pau1Buffer, kal_uint32 u4Size, kal_bool fgDirectWrite, kal_uint32 *pu4WrittenSize)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    _AVI_BUFFER_CTRL_T* const prBufferCtrl = _prCtrl->prDataBuffCtrl;
    const kal_uint32 u4BuffIdx = prBufferCtrl->u1ActiveBuffIdx;
    kal_uint8* const pu1BuffStart = prBufferCtrl->apu1Buff[u4BuffIdx];
    kal_uint32 u4WriteThreshold = prBufferCtrl->u4WriteThreshold;
    *pu4WrittenSize = 0;

    drv_trace2(TRACE_GROUP_10, MUXAVI_WRITE_DATA_2_FILE_SUB_DIRECT, fgDirectWrite, u4Size);

    do
    {
        kal_uint32 u4BuffWritten = prBufferCtrl->au4BuffWritten[u4BuffIdx];
        kal_uint32 u4LeftOver = u4WriteThreshold - u4BuffWritten;
        kal_uint32 u4Writting;
        kal_bool   fgDataBuuferUnitFull = KAL_FALSE;
        if ((u4Size - *pu4WrittenSize) > u4LeftOver)
        {
            u4Writting = u4LeftOver;
            fgDataBuuferUnitFull = KAL_TRUE;
        }
        else
        {
            u4Writting = (u4Size - *pu4WrittenSize);
        }

        _prCtrl->u4TotalAVDataWritten += u4Writting;
        _prCtrl->u8CurrentFileSize += u4Writting;
        {
            const _AVI_CONFIG_T* _prConfig = &_rAVIConfig;
            kal_uint32 u4ClusterSize;
            kal_uint64 u8FreeDiskSize;
            MuxerAdaptGetDiskInfo(_prConfig->pau2WorkingPath, &u4ClusterSize, &u8FreeDiskSize);
            drv_trace8(TRACE_GROUP_10, MUXAVI_WRITE_DATA_2_FILE_SUB_DIRECT_P, u4BuffWritten, u4LeftOver, u4Writting, *pu4WrittenSize, u4ClusterSize, u8FreeDiskSize & 0xFFFFFFFF, _prCtrl->u8CurrentFileSize & 0xFFFFFFFF, _prConfig->u8SizeLimit & 0xFFFFFFFF);
        }
        if (fgDirectWrite == KAL_TRUE)
        {
            /*
            Write data to file directly.
            */
            kal_uint8* pu1Buff = (pu1BuffStart + u4BuffWritten);
            kal_mem_cpy((void*)pu1Buff, (void*)(pau1Buffer + *pu4WrittenSize), u4Writting);
            prBufferCtrl->au4BuffWritten[u4BuffIdx] += u4Writting;
            *pu4WrittenSize += u4Writting;

            if (u4WriteThreshold == prBufferCtrl->au4BuffWritten[u4BuffIdx])
            {
                kal_uint8* pu1PA = NULL;
                pu1PA = (kal_uint8*)VideoCommExtBufferCacheableSwitchAlignMemory((kal_uint32)pu1BuffStart, u4WriteThreshold, VIDEO_NON_CACHEABLE);
                drv_trace4(TRACE_GROUP_10, MUXAVI_WRITE_DATA_2_FILE_SUB, u4BuffIdx, (kal_uint32)pu1PA, (kal_uint32)pu1BuffStart, u4WriteThreshold);

                _AVI_MUXER_FSWRITE(_prCtrl->rDataHandle, (void*)pu1PA, u4WriteThreshold);

                prBufferCtrl->au4BuffWritten[u4BuffIdx] = 0;
            }

            if (*pu4WrittenSize == u4Size)
            {
                break;
            }
        }
        else
        {
            const kal_uint32 u4DataType = MX_DATATYPE_DATA;
            _AVI_MuxerWrite2ActiveBuffAndUpdateStatus(prBufferCtrl, pau1Buffer, u4Writting);
            if (KAL_TRUE == fgDataBuuferUnitFull)
            {
                prBufferCtrl->u1ActiveBuffIdx = _AVI_MuxerRoundedAddOne(u4BuffIdx, (_AVI_DATA_BUFF_NUM - 1));
            }
            _AVI_CallBack(AVI_EVENT_RDY_2_WRITE_DATA, (void*)&u4DataType);
            *pu4WrittenSize += u4Writting;
            break; // Only do one time
        }
    }while(1);

    return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerWriteChunkHeader(kal_uint8 *pau1ChunkID, kal_uint32 u4Size)
{
    VIDEO_ERROR_TYPE_T eFSRet = VIDEO_ERROR_NONE;
    kal_uint32 u4WrittenSize;

    eFSRet = _AVI_MuxerWriteData2FileSubDirect(pau1ChunkID, 4, KAL_TRUE, &u4WrittenSize);
    if (VIDEO_ERROR_NONE != eFSRet)
    {
        return eFSRet;
    }

    eFSRet = _AVI_MuxerWriteData2FileSubDirect((kal_uint8*)(&u4Size), 4, KAL_TRUE, &u4WrittenSize);
    if (VIDEO_ERROR_NONE != eFSRet)
    {
        return eFSRet;
    }
    return eFSRet;
}

static void _AVI_MuxerWriteReturnUnfinishedData(void)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    AVI_UNFINISHED_PARAM_T  *const prUnfinishedBuffer = &_prCtrl->rUnfinishedBuffer;

    if (prUnfinishedBuffer->fgIsValid == KAL_TRUE)
    {
        if (prUnfinishedBuffer->u4DataType == MX_DATATYPE_VIDEO)
        {
            kal_uint32 i = MAX_BUFFER_PARTITION;
            do
            {
                MUXER_BUFFER_T * const prBuff = &prUnfinishedBuffer->arData[MAX_BUFFER_PARTITION - i];
                if (KAL_TRUE == prBuff->fgValid)
                {
                    _AVI_ReturnBitstream(prUnfinishedBuffer->u4DataType, &prUnfinishedBuffer->u8TimeStamp, prBuff->pu1Addr, prBuff->u4Size);
                }
            }while(--i != 0);
        }
        else
        {
            const MUXER_BUFFER_T * prBuff = &prUnfinishedBuffer->arData[0];
            _AVI_ReturnBitstream(prUnfinishedBuffer->u4DataType, &prUnfinishedBuffer->u8TimeStamp, prBuff->pu1Addr, prBuff->u4Size);
        }
        prUnfinishedBuffer->fgIsValid = KAL_FALSE;
    }
}

__inline static VIDEO_ERROR_TYPE_T _AVI_MuxerWriteUnfinishedData2FileSub(void)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    AVI_UNFINISHED_PARAM_T  *const prUnfinishedBuffer = &_prCtrl->rUnfinishedBuffer;
    VIDEO_ERROR_TYPE_T eFSRet = VIDEO_ERROR_NONE;

    if (prUnfinishedBuffer->fgIsValid == KAL_TRUE)
    {
        kal_uint32 i = MAX_BUFFER_PARTITION;
        drv_trace0(TRACE_GROUP_10, MUXAVI_WRITE_UNFINISHED_DATA_2_FILE_SUB);

        if (prUnfinishedBuffer->u4DataType == MX_DATATYPE_VIDEO)
        {
            kal_uint32 u4WrittenSize;
            if (prUnfinishedBuffer->fgHeaderValid == KAL_TRUE)
            {
                eFSRet = _AVI_MuxerWriteChunkHeader((kal_uint8*)&("00dc"), prUnfinishedBuffer->u4Size);
                if (VIDEO_ERROR_NONE != eFSRet)
                {
                    goto RETURN_VIDEO_BS;
                }
                prUnfinishedBuffer->fgHeaderValid = KAL_FALSE;
            }

            // Support partial video data writing
            // We will modify arData, and check whether data have witten to data buffer
            do
            {
                MUXER_BUFFER_T * const prBuff = &prUnfinishedBuffer->arData[MAX_BUFFER_PARTITION - i];
                if (KAL_TRUE == prBuff->fgValid)
                {
                    // If fgDirectWrite == KAL_FALSE, the function won't return error
                    _AVI_MuxerWriteData2FileSubDirect(prBuff->pu1Addr, prBuff->u4Size, KAL_FALSE, &u4WrittenSize);
                    _AVI_ReturnBitstream(MX_DATATYPE_VIDEO, &prUnfinishedBuffer->u8TimeStamp, prBuff->pu1Addr, u4WrittenSize);

                    prBuff->pu1Addr += u4WrittenSize;
                    prBuff->u4Size -= u4WrittenSize;

                    if (prBuff->u4Size == 0)
                    {
                        prBuff->fgValid = KAL_FALSE;
                    }
                    return VIDEO_ERROR_NONE;
                }
            }while(--i != 0);

            /* write idx */
            _AVI_MuxerWriteIdx((void*)&("00dc"), _AVI_IF_KEY_FRAME, _prCtrl->u4TotalAVDataWritten - prUnfinishedBuffer->u4Size - 8 + _prCtrl->u4AVDataOffset, prUnfinishedBuffer->u4Size);
            _prCtrl->u4VideoFrameNum++;

RETURN_VIDEO_BS:
            _AVI_MuxerWriteReturnUnfinishedData();
        }
        else if (prUnfinishedBuffer->u4DataType == MX_DATATYPE_AUDIO)
        {
            kal_uint32 u4WrittenSize;
            const MUXER_BUFFER_T * prBuff = &prUnfinishedBuffer->arData[0];

            /* write data */
            eFSRet = _AVI_MuxerWriteChunkHeader((kal_uint8*)&("01wb"), prUnfinishedBuffer->u4Size);
            if (VIDEO_ERROR_NONE != eFSRet)
            {
                goto RETURN_AUDIO_BS;
            }

            eFSRet = _AVI_MuxerWriteData2FileSubDirect(prBuff->pu1Addr, prUnfinishedBuffer->u4Size, KAL_TRUE, &u4WrittenSize);
            if (VIDEO_ERROR_NONE != eFSRet)
            {
                goto RETURN_AUDIO_BS;
            }

            _prCtrl->u4AudioDataWritten += prUnfinishedBuffer->u4Size;

            /* write idx */
            _AVI_MuxerWriteIdx((void*)&("01wb"), 0, _prCtrl->u4TotalAVDataWritten - prUnfinishedBuffer->u4Size - 8 + _prCtrl->u4AVDataOffset, prUnfinishedBuffer->u4Size);

RETURN_AUDIO_BS:
            _AVI_MuxerWriteReturnUnfinishedData();
        }
    }

    return eFSRet;
}

#endif

__inline static VIDEO_ERROR_TYPE_T _AVI_MuxerProcessAudioData(const MUXER_PROCESS_PARAM_T * const pParam)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    const _AVI_CONFIG_T* _prConfig = &_rAVIConfig;
    const MUXER_BUFFER_T * prBuff = NULL;
    kal_uint32 u4AudioSize = 0;
    kal_uint32 u4TotalAudioSize = 0;
    kal_int32  i4FSRet = _prCtrl->i4FSRet;
    VIDEO_ERROR_TYPE_T eRet = VIDEO_ERROR_NONE;

    // Assumed that audio data would use only arData[0]
    if ((KAL_FALSE == pParam->arData[0].fgValid) ||
        (KAL_TRUE  == pParam->arData[1].fgValid))
    {
        _AVI_MUXER_ASSERT();
    }

    /* audio data */
    /* 01wb, u4Size, raw data */
    /* 4     4     ... */
    prBuff = &pParam->arData[0];
    u4TotalAudioSize = prBuff->u4Size;

    if (KAL_TRUE == _prConfig->rAudioConfig.fgRecordAudio)
    {
        if (i4FSRet < 0)
        {
            eRet = VIDEO_ERROR_MUXER_FS_ERROR;
            goto RETURN_AUDIO_BS;
        }
        else if (KAL_TRUE == _AVI_ReachSizeLimit(u4TotalAudioSize + 8 + sizeof(_AVI_INDEX_T)))
        {
            if (KAL_TRUE == _prCtrl->fgSetSizeLimit)
            {
                eRet = VIDEO_ERROR_MUXER_REACH_SIZE_LIMIT;
            }
            else
            {
                eRet = VIDEO_ERROR_MUXER_DISK_FULL;
            }
            goto RETURN_AUDIO_BS;
        }

        u4AudioSize = _AVI_GetAudioSizeToWrite(u4TotalAudioSize);

        {

#if defined(_SUPPORT_BIG_FRAME_SIZE_ONLY_)
            kal_bool fgBufferFull = _AVI_MuxerCheckDataBufferFull(MX_DATATYPE_AUDIO, u4AudioSize, pParam);
            if (fgBufferFull == KAL_TRUE)
            {
                return VIDEO_ERROR_NONE; // Don't return buffer
            }
#else
            //else
            {
                /* write data */
                _AVI_MuxerWrite2DataBuffer((kal_uint8*)(&("01wb")), 4);
                _AVI_MuxerWrite2DataBuffer((kal_uint8*)(&u4AudioSize), 4);
                _AVI_MuxerWrite2DataBuffer(prBuff->pu1Addr, u4AudioSize);

                _prCtrl->u4AudioDataWritten += u4AudioSize;

                /* write idx */
                _AVI_MuxerWriteIdx((void*)&("01wb"), 0, _prCtrl->u4TotalAVDataWritten - u4AudioSize - 8 + _prCtrl->u4AVDataOffset, u4AudioSize);
            }
#endif
        }
    }
    else
    {
        // In the case of audio off, audio data would be simply bypassed
    }

RETURN_AUDIO_BS:
    _AVI_ReturnBitstream(MX_DATATYPE_AUDIO, &pParam->u8TimeStamp, prBuff->pu1Addr, u4TotalAudioSize);
    return eRet;
}

__inline static VIDEO_ERROR_TYPE_T _AVI_MuxerProcessVideoData(const MUXER_PROCESS_PARAM_T * const pParam)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    const MUXER_BUFFER_T * prBuff = NULL;
    kal_int32 i4FSRet = _prCtrl->i4FSRet;
    VIDEO_ERROR_TYPE_T eRet = VIDEO_ERROR_NONE;

    kal_uint32 i = MAX_BUFFER_PARTITION;
    kal_uint32 u4VideoSize = 0;

    if (KAL_TRUE == pParam->arData[0].fgValid)
    {
        u4VideoSize += pParam->arData[0].u4Size;
    }

    if (KAL_TRUE == pParam->arData[1].fgValid)
    {
        u4VideoSize += pParam->arData[1].u4Size;
    }

    if (i4FSRet < 0)
    {
        eRet = VIDEO_ERROR_MUXER_FS_ERROR;
        goto RETURN_VIDEO_BS;
    }
    else if (KAL_TRUE == _AVI_ReachSizeLimit(u4VideoSize + 8 + sizeof(_AVI_INDEX_T)))
    {
        if (KAL_TRUE == _prCtrl->fgSetSizeLimit)
        {
            eRet = VIDEO_ERROR_MUXER_REACH_SIZE_LIMIT;
        }
        else
        {
            eRet = VIDEO_ERROR_MUXER_DISK_FULL;
        }
        goto RETURN_VIDEO_BS;
    }

    {
#if defined(_SUPPORT_BIG_FRAME_SIZE_ONLY_)
        kal_bool fgBufferFull = _AVI_MuxerCheckDataBufferFull(MX_DATATYPE_VIDEO, u4VideoSize, pParam);
        if (fgBufferFull == KAL_TRUE)
        {
            return VIDEO_ERROR_NONE;// Don't return buffer
        }
#else
        //else
        {
            /* video data */
            /* 00db, size, raw data */
            /* 4     4     ... */

            /* write data */
            _AVI_MuxerWrite2DataBuffer((kal_uint8*)(&("00dc")), 4);
            _AVI_MuxerWrite2DataBuffer((kal_uint8*)(&u4VideoSize), 4);
            do
            {
                prBuff = &pParam->arData[MAX_BUFFER_PARTITION - i];
                if (KAL_TRUE == prBuff->fgValid)
                {
                    _AVI_MuxerWrite2DataBuffer(prBuff->pu1Addr, prBuff->u4Size);
                }
            }while(--i != 0);

            /* write idx */
            _AVI_MuxerWriteIdx((void*)&("00dc"), _AVI_IF_KEY_FRAME, _prCtrl->u4TotalAVDataWritten - u4VideoSize - 8 + _prCtrl->u4AVDataOffset, u4VideoSize);
            _prCtrl->u4VideoFrameNum++;
        }
#endif
    }
RETURN_VIDEO_BS:
    i = MAX_BUFFER_PARTITION;
    do
    {
        prBuff = &pParam->arData[MAX_BUFFER_PARTITION - i];
        if (KAL_TRUE == prBuff->fgValid)
        {
            _AVI_ReturnBitstream(MX_DATATYPE_VIDEO, &pParam->u8TimeStamp, prBuff->pu1Addr, prBuff->u4Size);
        }
    }while(--i != 0);

    return eRet;
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerProcessData(MUXER_PROCESS_PARAM_T * pParam)
{
    VIDEO_ERROR_TYPE_T eRet = VIDEO_ERROR_NONE;

    if (MX_DATATYPE_AUDIO == pParam->u4DataType)
    {
        eRet = _AVI_MuxerProcessAudioData(pParam);
    }
    else if (MX_DATATYPE_VIDEO == pParam->u4DataType)
    {
        eRet = _AVI_MuxerProcessVideoData(pParam);
    }

    return eRet;
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerFSWrite_Internal(FS_HANDLE rFileHandle, void * const pu1Data, const kal_uint32 u4Size)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    kal_int32 i4FSRet = _prCtrl->i4FSRet;
    kal_uint32 u4WrittenSize = 0;

    i4FSRet = FS_Write(rFileHandle, (void*)pu1Data, u4Size, &u4WrittenSize);
    _prCtrl->i4FSRet = i4FSRet;

    if (FS_DISK_FULL == i4FSRet)
    {
        return VIDEO_ERROR_MUXER_DISK_FULL;
    }
    else if (i4FSRet < 0)
    {
        return VIDEO_ERROR_MUXER_ERROR;
    }

    if (u4WrittenSize != u4Size)
    {
        return VIDEO_ERROR_MUXER_DISK_FULL;
    }

    return VIDEO_ERROR_NONE;

}

static VIDEO_ERROR_TYPE_T _AVI_MuxerWriteData2FileSub(
    _AVI_BUFFER_CTRL_T* const prBufferCtrl,
    FS_HANDLE* const prFSHandle,
    const kal_uint32 u4BufferNumber,
    const kal_bool fgFlush)
{
    kal_uint8* pu1PA = NULL;
    kal_uint8  u4NextWriteIdx = 0;
    kal_uint8* pu1Addr = NULL;
    kal_uint32 u4Size = 0;

    while((WAITING_2_WRITE == prBufferCtrl->aeBuffState[prBufferCtrl->u1Next2WriteBuffidx])
        ||((KAL_TRUE == fgFlush) && (0 != prBufferCtrl->au4BuffWritten[prBufferCtrl->u1Next2WriteBuffidx])))
    {
        u4NextWriteIdx = prBufferCtrl->u1Next2WriteBuffidx;
        pu1Addr = prBufferCtrl->apu1Buff[u4NextWriteIdx];
        u4Size = prBufferCtrl->au4BuffWritten[u4NextWriteIdx];

        pu1PA = (kal_uint8*)VideoCommExtBufferCacheableSwitchAlignMemory((kal_uint32)pu1Addr,u4Size, VIDEO_NON_CACHEABLE);
        drv_trace4(TRACE_GROUP_10, MUXAVI_WRITE_DATA_2_FILE_SUB, u4NextWriteIdx, (kal_uint32)pu1PA, (kal_uint32)pu1Addr, u4Size);

        _AVI_MUXER_FSWRITE(*prFSHandle, (void*)pu1PA, u4Size);

        prBufferCtrl->aeBuffState[u4NextWriteIdx] = AVAILABLE;
        prBufferCtrl->au4BuffWritten[u4NextWriteIdx] = 0;
        prBufferCtrl->u1Next2WriteBuffidx = _AVI_MuxerRoundedAddOne(u4NextWriteIdx, (u4BufferNumber - 1));
    }
    return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerWriteData2File(MUXER_WRITE_PARAM_T * pParam)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    _AVI_CONFIG_T* _prConfig = &_rAVIConfig;
    kal_bool fgWriteData = (MX_DATATYPE_DATA == pParam->u4DataType)?(KAL_TRUE):(KAL_FALSE);
    kal_bool fgWriteIdx = (MX_DATATYPE_IDX == pParam->u4DataType)?(KAL_TRUE):(KAL_FALSE);
    kal_bool fgWriteInfo = KAL_FALSE;
    VIDEO_ERROR_TYPE_T eFSRet = VIDEO_ERROR_NONE;

    if (MX_DATATYPE_ALL == pParam->u4DataType)
    {
        if (KAL_FALSE == pParam->fgFlush)
        {
            _AVI_MUXER_ASSERT();
        }

        fgWriteData = KAL_TRUE;
        fgWriteIdx = KAL_TRUE;
        fgWriteInfo = KAL_TRUE;
    }

    if (KAL_TRUE == fgWriteData)
    {
        drv_trace0(TRACE_GROUP_10, MUXAVI_WRITE_DATA_2_FILE);
        eFSRet = _AVI_MuxerWriteData2FileSub(_prCtrl->prDataBuffCtrl, &_prCtrl->rDataHandle, _AVI_DATA_BUFF_NUM, pParam->fgFlush);
        if (VIDEO_ERROR_NONE != eFSRet)
        {

#if defined(_SUPPORT_BIG_FRAME_SIZE_ONLY_)
            _AVI_MuxerWriteReturnUnfinishedData();
#endif
            return eFSRet;
        }

#if defined(_SUPPORT_BIG_FRAME_SIZE_ONLY_)
        eFSRet = _AVI_MuxerWriteUnfinishedData2FileSub();
        if (VIDEO_ERROR_NONE != eFSRet)
        {
            return eFSRet;
        }
#endif
    }

    if (KAL_TRUE == fgWriteIdx)
    {
        drv_trace0(TRACE_GROUP_10, MUXAVI_WRITE_IDX_2_FILE);
        eFSRet = _AVI_MuxerWriteData2FileSub(_prCtrl->prIdxBuffCtrl, &_prCtrl->rIdxHandle, _AVI_IDX_BUFF_NUM, pParam->fgFlush);
        if (VIDEO_ERROR_NONE != eFSRet)
        {
            return eFSRet;
        }
#if defined(_SUPPORT_BIG_FRAME_SIZE_ONLY_)
        if (_prCtrl->u4IdxBufferSize != 0)
        {
            _AVI_BUFFER_CTRL_T* const prBufferCtrl = _prCtrl->prIdxBuffCtrl;
            drv_trace1(TRACE_GROUP_10, MUXAVI_WRITE_IDX_BUFFER, _prCtrl->u4IdxBufferSize);
            _AVI_MuxerWrite2ActiveBuffAndUpdateStatus(prBufferCtrl, _prCtrl->u1IdxBuffer, _prCtrl->u4IdxBufferSize);
            _prCtrl->u4IdxBufferSize = 0;

            eFSRet = _AVI_MuxerWriteData2FileSub(_prCtrl->prIdxBuffCtrl, &_prCtrl->rIdxHandle, _AVI_IDX_BUFF_NUM, pParam->fgFlush);
            if (VIDEO_ERROR_NONE != eFSRet)
            {
                return eFSRet;
            }
        }
#endif
    }

    if (KAL_TRUE == fgWriteInfo)
    {
        _AVI_INFO_T rInfo;

        rInfo.u4AudioDataWritten = _prCtrl->u4AudioDataWritten;
        rInfo.u4TotalAVDataWritten = _prCtrl->u4TotalAVDataWritten;
        rInfo.u4VideoFrameNum = _prCtrl->u4VideoFrameNum;
        rInfo.rAudioConfig = _prConfig->rAudioConfig;
        rInfo.rVideoConfig = _prConfig->rVideoConfig;
#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
        rInfo.u4TLFrameRate = _prConfig->u4TLFrameRate;
#endif
        drv_trace0(TRACE_GROUP_10, MUXAVI_WRITE_INFO);
        _AVI_MUXER_FSWRITE(_prCtrl->rInfoHandle, (void*)&rInfo, sizeof(rInfo));
    }

    return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerCreateFile(void)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    _AVI_CONFIG_T* const _prConfig = &_rAVIConfig;
    kal_uint32 u4Size;
    kal_uint32 u4FileSize;
    kal_uint32 u4StuffSize;  /* stuff trash at the end of the cluster for pseudo merge */
    kal_uint8* pau1DataFileName;
    kal_uint8* pau1IdxFileName;
    kal_wchar* pau2FileNamePath;
    kal_uint32 u4VideoScale = 0;
    kal_uint32 u4VideoRate = 0;

    kal_uint16  u2VideoWidth;
    kal_uint16  u2VideoHeight;
    kal_uint32  u4AudioSampleRate;
    kal_uint32  u4AudioBitPerSample;
    kal_uint32  u4VideoFrameNum;
    kal_uint8  au1Buffer[_AVI_CHUNK_BUFFER_SIZE];
    kal_uint32 u4BufferPos = 0;
    MUXER_AUDIO_CONFIG_T *prAudioConfig = &_prConfig->rAudioConfig;
    MUXER_VIDEO_CONFIG_T *prVideoConfig = &_prConfig->rVideoConfig;
    kal_bool fgRecordAudio;

#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
    kal_uint32 u4TLFrameRate = 0;
#endif

    pau1DataFileName = _prCtrl->pau1DataFileName;
    pau1IdxFileName = _prCtrl->pau1IdxFileName;
    pau2FileNamePath = &_prConfig->pau2WorkingPath[0];

    _AVI_AppendFileName2Path(pau1DataFileName, pau2FileNamePath, _AVI_VISUAL_FILE);
    _AVI_AppendFileName2Path(pau1IdxFileName, pau2FileNamePath, _AVI_IDX_FILE);

    _prCtrl->rDataHandle = FS_Open((kal_wchar*) pau1DataFileName, FS_READ_WRITE);
    if (0 >= _prCtrl->rDataHandle)
    {
        return VIDEO_ERROR_MUXER_FAILED_2_CREATE_FILE;
    }

    _prCtrl->rIdxHandle = FS_Open((kal_wchar*) pau1IdxFileName, FS_READ_WRITE);
    if (0 >= _prCtrl->rIdxHandle)
    {
        return VIDEO_ERROR_MUXER_FAILED_2_CREATE_FILE;
    }

    {
        int iFSError;
        kal_uint32  u4ReadSize;
        _AVI_INFO_T rInfo;
        kal_uint8 *pau1InfoFileName = (kal_uint8*)get_ctrl_buffer(_AVI_FILE_PATH_SIZE);
        kal_bool fgSuccess = KAL_TRUE;

        _AVI_AppendFileName2Path(pau1InfoFileName, pau2FileNamePath, _AVI_INFO_FILE);
        _prCtrl->rInfoHandle = FS_Open((kal_wchar*)pau1InfoFileName, FS_READ_WRITE);

        do
        {
            if (0 >= _prCtrl->rInfoHandle)
            {
                fgSuccess = KAL_FALSE;
                break;
            }

#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
            {
                // For backward-compatible check
                kal_uint32 u4InfoFileSize;
                FS_GetFileSize(_prCtrl->rInfoHandle, &u4InfoFileSize);
                if (u4InfoFileSize != sizeof(rInfo))
                {
                    fgSuccess = KAL_FALSE;
                    break;
                }
            }
#endif
            kal_mem_set((void*)&rInfo, 0, sizeof(rInfo));
            iFSError = FS_Read(_prCtrl->rInfoHandle, (void*)&rInfo, sizeof(rInfo), &u4ReadSize);
            _AVI_CloseFile(&_prCtrl->rInfoHandle);

            if (iFSError != FS_NO_ERROR || u4ReadSize == 0)
            {
                fgSuccess = KAL_FALSE;
                break;
            }

            FS_Delete((kal_wchar*)pau1InfoFileName);
            _prCtrl->u4VideoFrameNum = rInfo.u4VideoFrameNum;
            _prCtrl->u4AudioDataWritten = rInfo.u4AudioDataWritten;
            _prCtrl->u4TotalAVDataWritten = rInfo.u4TotalAVDataWritten;
            *prVideoConfig = rInfo.rVideoConfig;
            *prAudioConfig = rInfo.rAudioConfig;

#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
            u4TLFrameRate = rInfo.u4TLFrameRate;
#endif
        }while(0);

        free_ctrl_buffer(pau1InfoFileName);
        if (fgSuccess == KAL_FALSE)
        {
            return VIDEO_ERROR_MUXER_FAILED_2_CREATE_FILE;
        }
    }

    u4VideoFrameNum = _prCtrl->u4VideoFrameNum;
    if ((0 == u4VideoFrameNum)||
        (0 == _prCtrl->u4TotalAVDataWritten))
    {
        return VIDEO_ERROR_MUXER_FAILED_2_CREATE_FILE;
    }

    u4AudioSampleRate = prAudioConfig->u4AudioSampleRate;
    u4AudioBitPerSample = prAudioConfig->u4AudioBitPerSample;

    // normally, width/height should not exceed 65535...
    u2VideoWidth = (kal_uint16)prVideoConfig->u4FrameWidth;
    u2VideoHeight = (kal_uint16)prVideoConfig->u4FrameHeight;

    /* original's fps might not very accurate since camera's incoming frame timing is not so accurate */
    /* update scale and rate based on frame count and audio len */
    /* audio is 8K PCM (16bit) */
    u4VideoScale = 1000;
    fgRecordAudio = prAudioConfig->fgRecordAudio;
    if ((KAL_TRUE == fgRecordAudio)&&
        (0 != _prCtrl->u4AudioDataWritten))
    {
        u4VideoRate =
            (kal_uint32)((kal_uint64)(u4VideoFrameNum) * u4VideoScale * (u4AudioSampleRate * u4AudioBitPerSample / 8) /
            (kal_uint64)(_prCtrl->u4AudioDataWritten));
    }
    else
    {
#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
        if (u4TLFrameRate != 0)
        {
            u4VideoRate = u4TLFrameRate / 10 * u4VideoScale;
        }
        else
#endif
        {
            u4VideoRate = prVideoConfig->u4VideoFrameRate / 10 * u4VideoScale;
        }
    }

    /*
     * [AVI File Format] for MJPEG
     *
     * = Data File ========================
     * RIFF.4.AVI .
     *     LIST.4.hdlr.avih.4.(file header)
     *     LIST.4.strl.strh.4.(video header)
     *                .strf.4.(video format)
     *     LIST.4.strl.strh.4.(audio header)
     *                .strf.4.(audio format)
     *     JUNK.4.(junk)
     *     LIST.4.movi.xxdb.4.(video data)
     *                 xxdc.4.(video data)
     *                 xxwb.4.(audio data)
     * = Idx File =========================
     *            idx1.4.(list data)
     * ====================================
     */

    /* fill to fit cluster size */
    {
        kal_uint32 u4ClusterSize;
        u4ClusterSize = FS_GetClusterSize((kal_uint32) pau2FileNamePath[0]);
        FS_GetFileSize(_prCtrl->rDataHandle, &u4FileSize);

        u4StuffSize = u4ClusterSize - (u4FileSize % u4ClusterSize);
    }

    /* data size + idx size */
    {
        kal_uint32 u4RIFFSize;
        u4RIFFSize = u4FileSize + u4StuffSize;
        FS_GetFileSize(_prCtrl->rIdxHandle, &u4FileSize);
        u4RIFFSize += u4FileSize;

        /* seek to begin */
        FS_Seek(_prCtrl->rDataHandle, 0, FS_FILE_BEGIN);

        /* RIFF.4.AVI . */
        _AVI_MuxerWriteList(au1Buffer, &u4BufferPos, _AVI_TAG_RIFF, u4RIFFSize, _AVI_TAG_AVI);
    }

    /* LIST.4.hdlr.avih.4.(file header) */
    {
        _AVI_FILE_HEADER_T rFileHeader;
        kal_mem_set((void*)&rFileHeader, 0, sizeof(rFileHeader));
        rFileHeader.micro_sec_per_frame = (kal_uint64)(u4VideoScale * 1000000 / u4VideoRate);
        rFileHeader.flag = 272; /* ? */
        rFileHeader.total_frame = u4VideoFrameNum;
        rFileHeader.num_of_stream = 2;
        rFileHeader.width = u2VideoWidth;
        rFileHeader.height = u2VideoHeight;

        u4Size = _AVI_MuxerGetDataFileOffset(fgRecordAudio) -
                _SIZE_LIST_TAG - _SIZE_LIST_SIZE - _SIZE_4CC -
                _SIZE_LIST_TAG - _SIZE_LIST_SIZE - _SIZE_4CC -
                _SIZE_4CC - _SIZE_CHUNK_SIZE;
        _AVI_MuxerWriteList(au1Buffer, &u4BufferPos, _AVI_TAG_LIST, u4Size, _AVI_TAG_HEADER_LIST);
        _AVI_MuxerWriteChunk(au1Buffer, &u4BufferPos, _AVI_TAG_AVI_HEADER, sizeof(_AVI_FILE_HEADER_T), (kal_uint8 *)&rFileHeader);
    }
    /* LIST.4.strl.strh.4.(video header)
       .strf.4.(video format) */
    {
        _AVI_STREAM_HEADER_T rVideoHeader;
        _AVI_VIDEO_FORMAT_HEADER_T u4VideoFormat;

        kal_mem_set((void*)&rVideoHeader, 0, sizeof(rVideoHeader));
        strncpy((char*)&rVideoHeader.fcc_type, (char*)&_AVI_TAG_STREAM_TYPE_VID, 4);
        strncpy((char*)&rVideoHeader.fcc_hdlr, (char*)&_AVI_TAG_MJPG, 4);
        rVideoHeader.scale = u4VideoScale;
        rVideoHeader.rate = u4VideoRate;
        rVideoHeader.length = u4VideoFrameNum;
        rVideoHeader.quality = 0xFFFFFFFF;//-1;  /* default */
        rVideoHeader.rect_right = u2VideoWidth;
        rVideoHeader.rect_bottom = u2VideoHeight;

        kal_mem_set((void*)&u4VideoFormat, 0, sizeof(u4VideoFormat));
        u4VideoFormat.size = 40;
        u4VideoFormat.width = u2VideoWidth;
        u4VideoFormat.height = u2VideoHeight;
        u4VideoFormat.planes = 1;
        u4VideoFormat.bit_count = 24;
        u4VideoFormat.compression = 1196444237;  /* ? */
        u4VideoFormat.size_image = u2VideoWidth * u2VideoHeight * 3;       /* image buffer size */

        /*
         *     strl.strh.4.(video header)
         *         .strf.4.(video format)
         */
        /* _AVI_STREAM_HEADER_T = 52 */
        /* _AVI_VIDEO_FORMAT_HEADER_T = 40 */
        /* 20 + 52 + 40 = 112 */

        u4Size = _SIZE_LIST_SIZE + _SIZE_4CC + _SIZE_LIST_SIZE + sizeof(_AVI_STREAM_HEADER_T) + _SIZE_4CC + _SIZE_LIST_SIZE + sizeof(_AVI_VIDEO_FORMAT_HEADER_T);
        _AVI_MuxerWriteList(au1Buffer, &u4BufferPos, _AVI_TAG_LIST, u4Size, _AVI_TAG_STREAM_LIST);
        _AVI_MuxerWriteChunk(au1Buffer, &u4BufferPos, _AVI_TAG_STREAM_HEADER, sizeof(_AVI_STREAM_HEADER_T), (kal_uint8 *)&rVideoHeader);
        _AVI_MuxerWriteChunk(au1Buffer, &u4BufferPos, _AVI_TAG_STREAM_FORMAT, sizeof(_AVI_VIDEO_FORMAT_HEADER_T), (kal_uint8 *)&u4VideoFormat);
    }
    /* LIST.4.strl.strh.4.(audio header)
       .strf.4.(audio format) */
    if (KAL_TRUE == fgRecordAudio)
    {
        _AVI_STREAM_HEADER_T rAudioHeader;
        _AVI_AUDIO_FORMAT_HEADER_T u4AudioFormat;

        kal_mem_set((void*)&rAudioHeader, 0, sizeof(rAudioHeader));
        strncpy((char*)&rAudioHeader.fcc_type, (char*)&_AVI_TAG_STREAM_TYPE_AUD, 4);
        rAudioHeader.scale = 1;
        rAudioHeader.rate = u4AudioSampleRate;
        rAudioHeader.length = _prCtrl->u4AudioDataWritten / (u4AudioBitPerSample / 8);
        rAudioHeader.quality = 0xFFFFFFFF;//-1;
        rAudioHeader.sample_size = 2;

        kal_mem_set((void*)&u4AudioFormat, 0, sizeof(u4AudioFormat));
        u4AudioFormat.format = _AVI_AUD_FORMAT_WAV_PCM;
        u4AudioFormat.channels = prAudioConfig->u4AudioChannelNum;
        u4AudioFormat.sample_per_sec = u4AudioSampleRate;
        u4AudioFormat.avg_byte_per_sec = u4AudioSampleRate * u4AudioBitPerSample / 8;
        u4AudioFormat.block_align = 2;
        u4AudioFormat.bit_per_sample = u4AudioBitPerSample;
        u4AudioFormat.size = 21834;  /* ingorne in PCM format ? */
        /*
         *     strl.strh.4.(audio header)
         *         .strf.4.(audio format)
         */
        /* _AVI_STREAM_HEADER_T = 52 */
        /* _AVI_AUDIO_FORMAT_HEADER_T = 20 */
        /* 20 + 52 + 20 = 92 */

        u4Size = _SIZE_LIST_SIZE + _SIZE_4CC + _SIZE_LIST_SIZE + sizeof(_AVI_STREAM_HEADER_T) + _SIZE_4CC + _SIZE_LIST_SIZE + sizeof(_AVI_AUDIO_FORMAT_HEADER_T);
        _AVI_MuxerWriteList(au1Buffer, &u4BufferPos, _AVI_TAG_LIST, u4Size, _AVI_TAG_STREAM_LIST);

        /* audio stream header */
        _AVI_MuxerWriteChunk(au1Buffer, &u4BufferPos, _AVI_TAG_STREAM_HEADER, sizeof(_AVI_STREAM_HEADER_T), (kal_uint8 *)&rAudioHeader);

        /* audio format */
        _AVI_MuxerWriteChunk(au1Buffer, &u4BufferPos, _AVI_TAG_STREAM_FORMAT, sizeof(_AVI_AUDIO_FORMAT_HEADER_T), (kal_uint8 *)&u4AudioFormat);
    }
    /* add iuam.4 (MTK box) */
    _AVI_MuxerWriteChunk(au1Buffer, &u4BufferPos, _AVI_TAG_IUAM, _AVI_MTK_BOX_SIZE, (kal_uint8 *)&_AVI_MTK_BOX_CONTENT);
#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    {
        _AVI_TRANSFORMATION_INFO_T rTransformationInfo;
        kal_mem_set(&rTransformationInfo, 0, sizeof(rTransformationInfo));

        switch (prVideoConfig->eRotateAngle)
        {
        case MUXER_ROTATE_90_CW:
            {
                rTransformationInfo.u2Rotation= 90;
            }
            break;
        case MUXER_ROTATE_180_CW:
            {
                rTransformationInfo.u2Rotation = 180;
            }
            break;
        case MUXER_ROTATE_270_CW:
            {
                rTransformationInfo.u2Rotation = 270;
            }
            break;
        default:
            break;
        }

        if (prVideoConfig->fgHorizontallyMirror == KAL_TRUE)
        {
            rTransformationInfo.u1HorizontalMirror = 1;;
        }
        // add TRNS.4 (rotation/mirror info)
        _AVI_MuxerWriteChunk(au1Buffer, &u4BufferPos, _AVI_TAG_TRNS, _AVI_TRNS_CHUNK_SIZE, (kal_uint8*)&rTransformationInfo);
    }
#endif
    /* LIST.4.movi. */
    u4Size = _SIZE_4CC + _prCtrl->u4TotalAVDataWritten + u4StuffSize;
    _AVI_MuxerWriteList(au1Buffer, &u4BufferPos, _AVI_TAG_LIST, u4Size, _AVI_TAG_MOVI);
    _AVI_MUXER_FSWRITE(_prCtrl->rDataHandle, au1Buffer, u4BufferPos);

    /* add idx1.4 */
    FS_Seek(_prCtrl->rIdxHandle, 0, FS_FILE_BEGIN);
    FS_GetFileSize(_prCtrl->rIdxHandle, &u4FileSize);
    _AVI_MUXER_FSWRITE(_prCtrl->rIdxHandle, &_AVI_TAG_IDX1, 4);
    u4FileSize -= 8;
    _AVI_MUXER_FSWRITE(_prCtrl->rIdxHandle, &u4FileSize, 4);

    /* close file first to merge */
    _AVI_CloseFile(&_prCtrl->rDataHandle);
    _AVI_CloseFile(&_prCtrl->rIdxHandle);

    /* merge data and idx file into AVI file */
    {
        kal_int32 i4Ret = 0;
        i4Ret = FS_PseudoMerge((kal_wchar*) pau1DataFileName, (kal_wchar*) pau1IdxFileName);
        if (FS_NO_ERROR != i4Ret)
        {
            return VIDEO_ERROR_MUXER_FAILED_2_CREATE_FILE;
        }
    }

    {
        kal_int32 i4Attribute;
        kal_wchar *pau2DestFilePath = _prConfig->pau2FilePath;
        FS_Rename((kal_wchar*) pau1DataFileName, (kal_wchar*) pau2DestFilePath);

        i4Attribute = FS_GetAttributes((kal_wchar*) pau2DestFilePath);
        i4Attribute &= (~FS_ATTR_HIDDEN);
        FS_SetAttributes((kal_wchar*) pau2DestFilePath, i4Attribute);
    }
    return VIDEO_ERROR_NONE;
}

static VIDEO_ERROR_TYPE_T _AVI_MuxerDeInit(void)
{
    _AVI_MUXER_CTRL_T* const _prCtrl = &_rAVICtrl;
    _AVI_CONFIG_T* const _prConfig = &_rAVIConfig;

    if (MUXER_SCENARIO_RECORD == _prConfig->eScenario)
    {
        _AVI_MuxerDeInitializeBufferCtrl(&_prCtrl->prDataBuffCtrl,_AVI_DATA_BUFF_NUM);
        _AVI_MuxerDeInitializeBufferCtrl(&_prCtrl->prIdxBuffCtrl,_AVI_IDX_BUFF_NUM);
    }
    _AVI_CloseAllFiles();
    MuxerAdaptFreeMemory(_prCtrl->pau1DataFileName);
    MuxerAdaptFreeMemory(_prCtrl->pau1IdxFileName);

    return VIDEO_ERROR_NONE;
}
static VIDEO_ERROR_TYPE_T _AVI_MuxerClose(void)
{
    MuxerFreeMemory(_rAVIConfig.pau2FilePath);
    MuxerFreeMemory(_rAVIConfig.pau2WorkingPath);
    return VIDEO_ERROR_NONE;
}

static const MUXER_ADAPT_API_T _API =
{
    _AVI_MuxerOpen,
    _AVI_MuxerInit,
    _AVI_MuxerGetParam,
    _AVI_MuxerSetParam,
    _AVI_MuxerDirectlyGetParam,
    _AVI_MuxerDirectlySetParam,
    _AVI_MuxerProcessData,
    _AVI_MuxerWriteData2File,
    _AVI_MuxerCreateFile,
    _AVI_MuxerDeInit,
    _AVI_MuxerClose
};

MUXER_ADAPT_API_T* AVIMuxerGetHandle(void)
{

    return (MUXER_ADAPT_API_T* )&_API;
}

#endif // __VE_SUPPORT_AVI_MUXER__
#endif // __VE_VIDEO_ARCHI_V2__

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

