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
 *   mp4_muxer_adapter_v2.c
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
 ****************************************************************************/
#include "drv_features_video.h"

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VEENC_ROCODE", rodata = "DYNAMIC_CODE_VEENC_RODATA"
#endif

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_SUPPORT_MP4_MUXER_ADAPTER__

#include "kal_public_api.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "fs_type.h"

#include "vcodec_v2_trc.h"
#include "video_muxer_if_v2.h"
#include "mp4_muxer_adapter_v2.h"
#include "mp4_muxer_adapter_if_v2.h"
#include "mp4_muxer_adapter_meta_creation_v2.h"
#include "mp4_muxer_adapter_buffer_management_v2.h"

#define RECORD_STATUS_SUCCEED 0x4B4F4B4F
#define _MP4_SIZE_OF_TEMP_FILE_BUFFER 2048
#define _MP4_FILE_MERGE_NUM (6)
#define ONE_SEC_IN_MICROSEC (1000000)

#define SWAP_4(x)    (((x & 0x000000FF) << 24) |     \
                     ((x & 0x0000FF00) <<  8) |                 \
                     ((x & 0x00FF0000) >>  8) |                 \
                     ((x & 0xFF000000) >> 24))

#define _MP4_WRITEBUF32_BYPOS(_pau1Buffer, _u4Pos, _u4Data)            \
    do {                                                        \
        *(kal_uint32*)(_pau1Buffer + _u4Pos) = (_u4Data);  \
    } while (0)


typedef  VIDEO_ERROR_TYPE_T (*PFN_PROCESSBUFFER)(kal_uint8 *pu1Addr, kal_uint32 u4Size, kal_uint32 u4Auxiliary);

/******************************************************************************
* Static global variable(s)
******************************************************************************/
static MP4_MUXER_ADAPTER_STATE_T _rMP4ALMgr;
kal_uint32 u4VideoWriteThreshold = MP4_BITSTREAM_THRESHOLD;
static kal_uint32 _u4VideoDirectlyWriteThreshold = MP4_BITSTREAM_THRESHOLD;

/******************************************************************************
* Internal function
******************************************************************************/

/**
 * Error handler for FSAL function failure
 */
VIDEO_ERROR_TYPE_T MP4_FSALFailHdlr(STFSAL *const prFile)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_int32 i4FsError;

    i4FsError = FSAL_GetLastError(prFile);

    switch (i4FsError)
    {
    case FS_DISK_FULL:
        eError = VIDEO_ERROR_MUXER_DISK_FULL;
        break;

    case FS_MSDC_WRITE_SECTOR_ERROR:
        eError = VIDEO_ERROR_MUXER_NO_DISK;
        break;

    default:
        eError = VIDEO_ERROR_MUXER_FS_ERROR;
        break;
    }
    drv_trace1(TRACE_GROUP_10, MUX_MP4AL_FSAL_FAIL, eError);

    return eError;
}


/**
 * Open one file which file path is (pu2FileFolder + pu2FileName)
 */
static VIDEO_ERROR_TYPE_T _MP4_OpenFile(kal_wchar * const pu2FileFolder,
        kal_wchar * const pu2FileName, const kal_uint32 u4Flag, STFSAL * const prFSALFile)
{
    FS_HANDLE hFile = 0;
    FSAL_Status eFSALRet;

    // The function must promise it won't change the pu2FileFolder
    kal_wstrcat(pu2FileFolder, pu2FileName);
    hFile = FS_Open(pu2FileFolder, u4Flag);
    MuxerAdaptRemoveFileName(pu2FileFolder);

    if (hFile < 0)
    {
        return VIDEO_ERROR_MUXER_FS_ERROR;
    }

    eFSALRet = FSAL_Open_WithHandle(prFSALFile, (void*)hFile);
    if (eFSALRet != FSAL_OK)
    {
        FS_Close(hFile);
        return VIDEO_ERROR_MUXER_FS_ERROR;
    }

    return VIDEO_ERROR_NONE;
}


/**
 * Clear all temp files in working path
 */
static VIDEO_ERROR_TYPE_T _MP4_ClearTempFiles(kal_wchar* const pau2WorkingPath)
{
    int FSError;
    kal_wchar* const aszFileLst[] =
    {
        _MP4_VIDEO_FILE,
        _MP4_AUDIO_FILE,
        _MP4_TEMP_META_FILE,
        _MP4_REAL_META_FILE,
        _MP4_VIDEO_STTS_FILE,
        _MP4_VIDEO_STSZ_FILE,
        _MP4_VIDEO_STCO_FILE,
        _MP4_VIDEO_STSS_FILE
    };

    kal_int32 i4FileIdx = MP4_NUM_OF_FILE - 1;
    for (; i4FileIdx >= 0; i4FileIdx--)
    {
        kal_wstrcat(pau2WorkingPath, aszFileLst[i4FileIdx]);
        FSError = FS_Delete(pau2WorkingPath);
        if (FSError != 0)
        {
            drv_trace2(TRACE_GROUP_10, MUX_MP4AL_DELETE_FILE_FAIL, i4FileIdx, FSError);
        }
        MuxerAdaptRemoveFileName(pau2WorkingPath);
    }

    return VIDEO_ERROR_NONE;
}


/**
 * Open temp files according to specified scenario
 */
static VIDEO_ERROR_TYPE_T _MP4_OpenTempFiles(MUXER_SCENARIO_T eScenario)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    STFSAL      *const prFSALFile = _rMP4ALMgr.rMp4FileMgr.rFile;
    kal_wchar   *const pau2WorkingPath = _rMP4ALMgr.pau2WorkingPath;
    kal_wchar   *const pau2TempWorkingPath = (kal_wchar*)MuxerAdaptGetMemory(_MP4_SIZE_OF_FILE_NAME_BUFFER, KAL_FALSE);
    kal_uint32  u4Flag = _MP4_TEMP_FILE_ATTRIBUTES;

    kal_wstrcpy((void*)pau2TempWorkingPath, pau2WorkingPath);

    if (eScenario == MUXER_SCENARIO_RECORD)
    {
        _MP4_ClearTempFiles(pau2WorkingPath);
    }
    else if (eScenario == MUXER_SCENARIO_CREATE_FILE)
    {
        u4Flag = FS_READ_WRITE;
        eError = _MP4_OpenFile(pau2TempWorkingPath,
                _MP4_REAL_META_FILE, _MP4_TEMP_FILE_ATTRIBUTES, &prFSALFile[MP4_REAL_META_FILE]);
        if (eError !=  VIDEO_ERROR_NONE)
        {
            MuxerAdaptFreeMemory(pau2TempWorkingPath);
            return eError;
        }
    }
    else
    {
        _MP4_DEBUG_ASSERT();
    }

    do
    {
        VIDEO_ERR_BREAK(_MP4_OpenFile(pau2TempWorkingPath,
            _MP4_VIDEO_FILE, u4Flag, &prFSALFile[MP4_VIDEO_FILE]));

        VIDEO_ERR_BREAK(_MP4_OpenFile(pau2TempWorkingPath,
            _MP4_AUDIO_FILE, u4Flag, &prFSALFile[MP4_AUDIO_FILE]));

        VIDEO_ERR_BREAK(_MP4_OpenFile(pau2TempWorkingPath,
            _MP4_TEMP_META_FILE, u4Flag, &prFSALFile[MP4_TEMP_META_FILE]));

        VIDEO_ERR_BREAK(_MP4_OpenFile(pau2TempWorkingPath,
            _MP4_VIDEO_STTS_FILE, u4Flag, &prFSALFile[MP4_VIDEO_STTS_FILE]));

        VIDEO_ERR_BREAK(_MP4_OpenFile(pau2TempWorkingPath,
            _MP4_VIDEO_STSZ_FILE, u4Flag, &prFSALFile[MP4_VIDEO_STSZ_FILE]));

        VIDEO_ERR_BREAK(_MP4_OpenFile(pau2TempWorkingPath,
            _MP4_VIDEO_STCO_FILE, u4Flag, &prFSALFile[MP4_VIDEO_STCO_FILE]));

        VIDEO_ERR_BREAK(_MP4_OpenFile(pau2TempWorkingPath,
            _MP4_VIDEO_STSS_FILE, u4Flag, &prFSALFile[MP4_VIDEO_STSS_FILE]));
    } while(0);

    MuxerAdaptFreeMemory(pau2TempWorkingPath);

    return eError;
}

/**
 * Close all temp files
 */
static void _MP4_CloseTempFiles(void)
{
    kal_int32   i4FileIdx = MP4_NUM_OF_FILE - 1;
    STFSAL      *const prFSALFile = _rMP4ALMgr.rMp4FileMgr.rFile;

    for (; i4FileIdx >= 0; i4FileIdx--)
    {
        if(prFSALFile[i4FileIdx].hFile != -1)
        {
            FSAL_Close(&prFSALFile[i4FileIdx]);
            prFSALFile[i4FileIdx].hFile = -1;
        }
    }
}


/**
 * Check whether temp files have been opened
 */
static VIDEO_ERROR_TYPE_T _MP4_IsTempFileOpened(void)
{
    kal_int32   i4FileIdx = MP4_NUM_OF_FILE - 1;
    STFSAL      *const prFSALFile = _rMP4ALMgr.rMp4FileMgr.rFile;

    for (; i4FileIdx >= 0; i4FileIdx--)
    {
        if(prFSALFile[i4FileIdx].hFile == -1)
        {
            return VIDEO_ERROR_MUXER_FAILED_2_CREATE_FILE;
        }
    }

    return VIDEO_ERROR_NONE;
}


/**
 * Initialize Temp Meta file, write video/audio configure to file.
 */
static VIDEO_ERROR_TYPE_T _MP4_InitTmpMetaFile(STFSAL * const prFSALTmpMeta)
{
    VIDEO_ERROR_TYPE_T  eError = VIDEO_ERROR_NONE;
    MUXER_VIDEO_CONFIG_T * const prVideoConfig = &_rMP4ALMgr.rVideoConfig;
    MUXER_AUDIO_CONFIG_T * const prAudioConfig = &_rMP4ALMgr.rAudioConfig;

    const kal_bool fgRecordAudio = prAudioConfig->fgRecordAudio;
    const kal_uint32 u4Width = prVideoConfig->u4FrameWidth;
    const kal_uint32 u4Height = prVideoConfig->u4FrameHeight;
    kal_uint8 *const pau1TempBuffer = (kal_uint8*)get_ctrl_buffer(_MP4_SIZE_OF_TEMP_FILE_BUFFER);
    if (pau1TempBuffer == NULL)
    {
        MP4_ASSERT(0);
    }

    drv_trace8(TRACE_GROUP_9, MUX_MP4AL_CONFIG,
        prVideoConfig->eEncoderType,
        prVideoConfig->u4FrameWidth,
        prVideoConfig->u4FrameHeight,
        prAudioConfig->eAudioFormat,
        prAudioConfig->fgRecordAudio,
        _rMP4ALMgr.u4TimeLimit,
        _rMP4ALMgr.u8FileSizeLimit >> 32,
        _rMP4ALMgr.u8FileSizeLimit & 0xFFFFFFFF);

    // video info
    do
    {
        kal_uint32 u4Data;
        kal_mem_set(pau1TempBuffer, 0, _MP4_SIZE_OF_TEMP_FILE_BUFFER);

        u4Data = prVideoConfig->eEncoderType;
        _MP4_WRITEBUF32_BYPOS(pau1TempBuffer, MP4_POS_V_CODEC_TYPE, u4Data);
        _MP4_WRITEBUF32_BYPOS(pau1TempBuffer, MP4_POS_V_WIDTH, u4Width);
        _MP4_WRITEBUF32_BYPOS(pau1TempBuffer, MP4_POS_V_HEIGHT, u4Height);

#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
        {
            // Support motion rotation
            kal_uint32 u4RotateAngle = prVideoConfig->eRotateAngle;
            kal_uint32 u4HorizontallyMirror = prVideoConfig->fgHorizontallyMirror;
            _MP4_WRITEBUF32_BYPOS(pau1TempBuffer, MP4_POS_V_ROTATEANGLE, u4RotateAngle);
            _MP4_WRITEBUF32_BYPOS(pau1TempBuffer, MP4_POS_V_HMIRROR, u4HorizontallyMirror);
        }
#endif

        // media info
        u4Data = fgRecordAudio;
        _MP4_WRITEBUF32_BYPOS(pau1TempBuffer, MP4_POS_RECORD_AUDIO, u4Data);  // record Audio

        // Size limited, disable pseudo merge
        {
            kal_bool fgPseudoMerge = KAL_TRUE;
            if (_rMP4ALMgr.u8FileSizeLimit != 0)
            {
                fgPseudoMerge = KAL_FALSE;
            }
            u4Data = fgPseudoMerge;
            _MP4_WRITEBUF32_BYPOS(pau1TempBuffer, MP4_POS_PSEUDO_MERGE, u4Data);  // pseudo merge
        }

        // audio info
        {
            const kal_uint32 u4ACodec = prAudioConfig->eAudioFormat;
            _MP4_WRITEBUF32_BYPOS(pau1TempBuffer, MP4_POS_A_CODEC_TYPE , u4ACodec);
        }

        {
            FSAL_Status eStatus = FSAL_Write(prFSALTmpMeta, (kal_uint8*)pau1TempBuffer, _MP4_SIZE_OF_TEMP_FILE_BUFFER);
            if (eStatus !=  FSAL_OK)
            {
                eError =  MP4_FSALFailHdlr(prFSALTmpMeta);
            }
        }
    }while(0);
    free_ctrl_buffer((void*)pau1TempBuffer);

    return eError;
}


/**
 * A wrapper for callback function
 */
static void _MP4_CallBack(kal_uint32 u4Event, void* pVoid, const kal_uint32 u4Line)
{
    drv_trace2(TRACE_GROUP_10, MUX_MP4AL_CALLBACK, u4Event, u4Line);
    _rMP4ALMgr.pfnCallBack(u4Event, pVoid);
}


/**
 * Process buffer described in MUXER_PROCESS_PARAM_T
 */
static VIDEO_ERROR_TYPE_T _MP4_ProcessBuf(MUXER_BUFFER_T * const parData, PFN_PROCESSBUFFER fnProcessBuffer, kal_uint32* pu4WrittenBufSize)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 u4PartitionIdx = 0;

    *pu4WrittenBufSize = 0;

    for (; u4PartitionIdx < MAX_BUFFER_PARTITION; u4PartitionIdx++)
    {
        MUXER_BUFFER_T *prData = parData + u4PartitionIdx;
        if (prData->fgValid == KAL_TRUE)
        {
            VIDEO_ERR_RTN(fnProcessBuffer(prData->pu1Addr, prData->u4Size, *pu4WrittenBufSize));
            *pu4WrittenBufSize += prData->u4Size;
        }
    }
    return VIDEO_ERROR_NONE;
}


/**
 * Write parameter set to temp meta file
 */
static VIDEO_ERROR_TYPE_T _MP4_WriteParameterSetBuf(kal_uint8 *pu1Addr, kal_uint32 u4Size, kal_uint32 u4Auxiliary)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    STFSAL * const prFSALTmpMeta = &_rMP4ALMgr.rMp4FileMgr.rFile[MP4_TEMP_META_FILE];
    const kal_uint32 u4VOSLength = u4Auxiliary;

    VIDEO_ERR_RTN(MP4_WriteMeta(prFSALTmpMeta, MP4_POS_VOS_DATA + u4VOSLength, u4Size, pu1Addr));

    return VIDEO_ERROR_NONE;
}


/**
 * Write sequence header to Temp meta file
 * @param paData pointer to buffer control
 * @param pPrivateData pointer to private data, ex: h.264 configuration data
 */
static VIDEO_ERROR_TYPE_T _MP4_WriteParameterSet(MUXER_BUFFER_T * const parData, void * const pPrivateData)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    STFSAL * const prFSALTmpMeta = &_rMP4ALMgr.rMp4FileMgr.rFile[MP4_TEMP_META_FILE];
    const VIDEO_ENCODER_TYPE_T eEncoderType = _rMP4ALMgr.rVideoConfig.eEncoderType;
    kal_uint32 u4VOSLength = 0;

    if (eEncoderType == VIDEO_ENCODER_MPEG4)
    {
        VIDEO_ERR_RTN(_MP4_ProcessBuf(parData, &_MP4_WriteParameterSetBuf, &u4VOSLength));
    }
    else if (eEncoderType == VIDEO_ENCODER_H264)
    {
        VIDEO_ERR_RTN(_MP4_ProcessBuf(parData, &_MP4_WriteParameterSetBuf, &u4VOSLength));
        MP4_WriteH264Configuration(prFSALTmpMeta, pPrivateData);
    }
    else
    {
        // H.263 Do nothing
    }
    VIDEO_ERR_RTN(MP4_WriteMeta(prFSALTmpMeta,
        MP4_POS_VOS_LENGTH, MP4_VOS_LENGTH, (kal_uint8*)&u4VOSLength));

    return VIDEO_ERROR_NONE;
}


/**
 * Process video sequence header
 */
static VIDEO_ERROR_TYPE_T _MP4_ProcessVSequenceHeader(MUXER_PROCESS_PARAM_T * const pParam)
{
    if (pParam->arData[0].fgValid == KAL_TRUE &&
        pParam->arData[0].u4Size > 0)
    {
        kal_uint32 u4DataType = MX_DATATYPE_VIDEO_SEQUENCE_HEADER;

        _rMP4ALMgr.fgGetParameterSet = KAL_TRUE;
        kal_mem_cpy(&_rMP4ALMgr.rParameterSet, pParam, sizeof(_rMP4ALMgr.rParameterSet));

        _MP4_CallBack(MP4_EVENT_RDY_2_WRITE_VIDEO, &u4DataType, __LINE__);
    }

    return VIDEO_ERROR_NONE;
}


/**
 * Common function, return data to upper-level component (muxer)
 */
static void _MP4_ReturnData(kal_uint32 u4DataType, kal_uint8* pu1Addr, kal_uint32 u4Size)
{
    MUXER_PROCESS_PARAM_T rParam;

    kal_mem_set(&rParam, 0, sizeof(rParam));
    rParam.u4DataType = u4DataType;
    rParam.arData[0].fgValid = KAL_TRUE;
    rParam.arData[0].pu1Addr = pu1Addr;
    rParam.arData[0].u4Size = u4Size;

    _MP4_CallBack(MP4_EVENT_RETURN_BUFFER, &rParam, __LINE__);
}


/**
 * If freed bit-stream exist, return bit-stream data to upper-level component (muxer)
 */
static kal_bool _MP4_ReturnBitStream(void)
{
    kal_uint32 u4Size;
    kal_uint8 *pu1Addr;
    kal_bool fgSuccess;

    fgSuccess = MP4_QueryFreedBitBuffer(&_rMP4ALMgr.rBitCtrlMgr,
        &pu1Addr, &u4Size);

    if (fgSuccess == KAL_FALSE)
    {
        return KAL_FALSE;
    }

    _MP4_ReturnData(MX_DATATYPE_VIDEO, pu1Addr, u4Size);
    MP4_FreeBitBufferUnit(&_rMP4ALMgr.rBitCtrlMgr);

    return KAL_TRUE;
}


/**
 * Return unfinished data, the case happens in size-limited or disk full
 */
static void _MP4_ReturnUnfinishedData(void)
{
    const kal_uint32 u4UnfinishedDataIdx = _rMP4ALMgr.u4UnfinishedDataIdx;
    kal_uint32 u4Idx = 0;
    MP4_UNFINISHED_DATA_T * const prUnfinishedData = _rMP4ALMgr.rUnfinishedData;

    for (; u4Idx <= u4UnfinishedDataIdx; u4Idx++)
    {
        if (prUnfinishedData[u4Idx].u4Size != 0)
        {
            MUXER_PROCESS_PARAM_T rParam;
            kal_mem_set(&rParam, 0, sizeof(rParam));

            rParam.u4DataType = MX_DATATYPE_VIDEO;
            rParam.arData[0].fgValid = KAL_TRUE;
            rParam.arData[0].pu1Addr = prUnfinishedData[u4Idx].pu1Addr;
            rParam.arData[0].u4Size = prUnfinishedData[u4Idx].u4Size;

            drv_trace2(TRACE_GROUP_9, MUX_MP4AL_RETURN_UNFINISHED_DATA,
                (kal_uint32)rParam.arData[0].pu1Addr,
                rParam.arData[0].u4Size);

            _MP4_CallBack(MP4_EVENT_RETURN_BUFFER, (void*)&rParam, __LINE__);
        }
        else
        {
            break;
        }
    }
}


/**
 * Return all bit-stream to muxer
 */
__inline static void _MP4_ReturnAllBitStreams(void)
{
    kal_bool fgSuccess;

    do {
        MP4_MarkFirstUnitOnError(&_rMP4ALMgr.rBitCtrlMgr);
        fgSuccess = _MP4_ReturnBitStream();
    } while (fgSuccess == KAL_TRUE);
}


/**
 * Return all audio data to muxer
 */
__inline static void _MP4_ReturnAllAudioData(void)
{
    AUDIO_BUFFER_T  * const parAudioBuf = _rMP4ALMgr.rAudioMgr.arAudioBuf;
    kal_uint32 * const pu4AudioBufRIdx = &_rMP4ALMgr.rAudioMgr.u4AudioBufRIdx;
    kal_uint32 u4SectionIdx = MAX_AUDIO_BUFFER_SECTION;

    for (; u4SectionIdx > 0; u4SectionIdx--)
    {
        AUDIO_BUFFER_T * const prAudioBuf = &parAudioBuf[*pu4AudioBufRIdx];
        if (prAudioBuf->fgValid == KAL_TRUE)
        {
            _MP4_ReturnData(MX_DATATYPE_AUDIO, prAudioBuf->pu1Addr, prAudioBuf->u4OriSize);

            (*pu4AudioBufRIdx)++;
            if (*pu4AudioBufRIdx == MAX_AUDIO_BUFFER_SECTION)
            {
                *pu4AudioBufRIdx = 0;
            }
            kal_mem_set(prAudioBuf, 0, sizeof(*prAudioBuf));
        }
        else
        {
            break;
        }
    }
}


/**
 * Return all data to muxer, including video and audio
 */
static void _MP4_ReturnAllData(void)
{
    _MP4_ReturnAllBitStreams();
    _MP4_ReturnAllAudioData();
}


static FSAL_Status _MP4_WriteData2File(const MP4_FILE_HANDLE_TYPE_T eFileType, STFSAL* const prFile, kal_uint8 * const pu1Addr, const kal_uint32 u4Size)
{
    FSAL_Status eFSALRet;
    kal_uint32 u4StartTime, u4Duration;

    u4StartTime = video_get_current_time();
    eFSALRet = FSAL_Write(prFile, pu1Addr, u4Size);
    u4Duration = video_get_duration_ms(u4StartTime);

    if (eFileType == MP4_VIDEO_FILE)
    {
        _rMP4ALMgr.rInfo.u4AccuBitDataSize += u4Size;
        _rMP4ALMgr.rInfo.u4AccuBitDataDuration += u4Duration;
        if (u4Size > _rMP4ALMgr.rInfo.u4PeakBitDataSize)
        {
            _rMP4ALMgr.rInfo.u4PeakBitDataSize = u4Size;
        }
        if (u4Duration > _rMP4ALMgr.rInfo.u4PeakBitDataDuration)
        {
            _rMP4ALMgr.rInfo.u4PeakBitDataDuration = u4Duration;
        }

        drv_trace1(TRACE_GROUP_9, MUX_MP4AL_END_WRITE_VIDEO_FILE, u4Duration);
    }
    else if (eFileType == MP4_AUDIO_FILE)
    {
        drv_trace1(TRACE_GROUP_9, MUX_MP4AL_END_WRITE_AUDIO_FILE, u4Duration);
    }

    return eFSALRet;
}

/**
 * Write bit-stream data to the specified file.
 */
static VIDEO_ERROR_TYPE_T _MP4_WriteBitStream(kal_bool *pfgWriteResult)
{
    kal_uint32 u4Size;
    kal_uint8 *pu1Addr, *pu1NonCacheAddr;
    MP4_BIT_CTRL_MGR_T* const prBitCtrlMgr = &_rMP4ALMgr.rBitCtrlMgr;
    STFSAL* const prVideoFile = &_rMP4ALMgr.rMp4FileMgr.rFile[MP4_VIDEO_FILE];
    kal_bool fgSuccess;

    *pfgWriteResult = KAL_FALSE;
    fgSuccess = MP4_GetBitBuffer(prBitCtrlMgr, &pu1Addr, &u4Size);

    if (fgSuccess == KAL_TRUE)
    {
        // Write the data from "pu1Addr" to "pu1Addr + u4Size" (exclusive) to file.
        drv_trace2(TRACE_GROUP_10, MUX_MP4AL_BEGIN_WRITE_VIDEO_FILE, (kal_uint32)pu1Addr, u4Size);

        pu1NonCacheAddr = (kal_uint8*)VideoCommExtBufferCacheableSwitchAlignMemory(
            (kal_uint32)pu1Addr, u4Size, VIDEO_NON_CACHEABLE);

        FSAL_ERR_RTN(prVideoFile, _MP4_WriteData2File(MP4_VIDEO_FILE, prVideoFile, pu1NonCacheAddr, u4Size))
        *pfgWriteResult = KAL_TRUE;
    }

    return VIDEO_ERROR_NONE;
}


/**
 * Check whether bitstream need to be written to file
 */
static VIDEO_ERROR_TYPE_T _MP4_CheckAndWriteBitStream()
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    // Query whether bitstream need to be written to file
    if (MP4_QueryBitBufferStatus(&_rMP4ALMgr.rBitCtrlMgr) == KAL_TRUE)
    {
        kal_bool fgWriteResult = KAL_FALSE, fgReturnResult = KAL_FALSE;

        do
        {
            eError = _MP4_WriteBitStream(&fgWriteResult);
            fgReturnResult = _MP4_ReturnBitStream();
            if (((fgWriteResult == KAL_FALSE) && (fgReturnResult == KAL_FALSE))
                || eError != VIDEO_ERROR_NONE)
            {
                // 1. No bit-stream to write && no bit-stream to be returned.
                //    No bit-stream to write && returning bit-stream failed.
                // 2. Error happens
                break;
            }
        }while(1);
    }
    return eError;
}


/**
 * Check whether stbl data need to be written to file
 */
static VIDEO_ERROR_TYPE_T _MP4_CheckAndWriteStblData()
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    kal_bool fgHasData2Write = MP4_STBL_HasData2Write();
    if (fgHasData2Write == KAL_TRUE)
    {
        VIDEO_ERR_RTN(MP4_STBL_WriteData(&_rMP4ALMgr.rMp4FileMgr));
    }

    return VIDEO_ERROR_NONE;
}


/**
 * Process video buffer, add it to bitstream buffer control
 */
static VIDEO_ERROR_TYPE_T _MP4_ProcessVideoBuf(kal_uint8 *const pu1Addr, const kal_uint32 u4Size, const kal_uint32 u4Auxiliary)
{
    kal_bool fgSuccess;
    fgSuccess = MP4_AddBitBuffer(&_rMP4ALMgr.rBitCtrlMgr,
        (kal_uint32)pu1Addr, u4Size);

    if (fgSuccess == KAL_FALSE)
    {
        drv_trace1(TRACE_GROUP_10, MUX_MP4AL_BITSTREAM_BUFFER_FULL,
            (kal_uint32)pu1Addr);
        return VIDEO_ERROR_BUFF_FULL;
    }

    return VIDEO_ERROR_NONE;
}


/**
 * Process video data
 */
static VIDEO_ERROR_TYPE_T _MP4_ProcessVideoData(MUXER_PROCESS_PARAM_T * const pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 u4FrameSize = 0;

    // Todo: Make sure there is enough meta buffer for the new frame before processing bit-stream data.
    // see MP4_FW_Meta_IsFreeEnough

    // add buffer to bit-stream control mgr
    VIDEO_ERR_RTN(_MP4_ProcessBuf(pParam->arData, &_MP4_ProcessVideoBuf, &u4FrameSize));

    // add frame info to box buffer
    _rMP4ALMgr.u4TotalVFrames++;
    {
        MP4_FRAME_INFO_T rFrameInfo;
        rFrameInfo.fgFirstFrame = _rMP4ALMgr.u4TotalVFrames > 1 ? KAL_FALSE : KAL_TRUE;
        rFrameInfo.u8TimeStamp = pParam->u8TimeStamp;
        rFrameInfo.u4FrameSize = u4FrameSize;
        rFrameInfo.fgSyncFrame = pParam->u4FrameType == MX_FRAMETYPE_INTRA ? KAL_TRUE : KAL_FALSE;
        MP4_STBL_AddOneVFrame(&rFrameInfo);
    }

    if (MP4_QueryBitBufferStatus(&_rMP4ALMgr.rBitCtrlMgr) == KAL_TRUE ||
        MP4_STBL_HasData2Write() == KAL_TRUE)
    {
        kal_uint32 u4DataType = MX_DATATYPE_VIDEO;
        _MP4_CallBack(MP4_EVENT_RDY_2_WRITE_VIDEO, &u4DataType, __LINE__);
    }

    return VIDEO_ERROR_NONE;
}


/**
 * Parse AMR Data, then add frame info to audio STBL
 */
static VIDEO_ERROR_TYPE_T _MP4_ParseAMRData(const kal_uint8 u1AMRType, kal_uint8* const pu1Addr, const kal_uint32 u4Size, const kal_bool fgTruncateAudio)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint32 u4AMRBufPos = _rMP4ALMgr.u4AudioLeftOver;
    _rMP4ALMgr.u4AudioLeftOver = 0;

    // parse each audio frame
    while (u4AMRBufPos < u4Size)
    {
        kal_uint8 u1FrameHeader;
        kal_uint8 u1FrameLength;

        u1FrameHeader = pu1Addr[u4AMRBufPos];

        eError = MP4_ParseAMRHeader(u1AMRType, u1FrameHeader, &u1FrameLength);
        if (eError != VIDEO_ERROR_NONE)
        {
            drv_trace0(TRACE_GROUP_10, MUX_MP4AL_PARSE_AMR_FAIL);
            return eError;
        }

        u4AMRBufPos += (u1FrameLength + 1);

        /* Handle the case for partial frame */
        if (u4AMRBufPos > u4Size)
        {
            _rMP4ALMgr.u4AudioLeftOver = u4AMRBufPos - u4Size;

            // If we don't truncate audio, we assume the frame is complete.
            // If we truncate audio, we ignore the frame.
            if (fgTruncateAudio == KAL_FALSE)
            {
                eError = MP4_STBL_AddOneAFrame(&_rMP4ALMgr.rMp4FileMgr, u1FrameLength + 1);
            }

            break;
        }

        VIDEO_ERR_RTN(MP4_STBL_AddOneAFrame(&_rMP4ALMgr.rMp4FileMgr, u1FrameLength + 1)); // contains header
    }
    return eError;
}


/**
 * Parse audio data depending on audio codec
 */
static void _MP4_ParseAudioData(kal_uint8* const pu1Addr, const kal_uint32 u4Size, const kal_bool fgTruncateAudio)
{
    const kal_uint32 u4ACodec = _rMP4ALMgr.rAudioConfig.eAudioFormat;
    if (u4ACodec == MEDIA_FORMAT_AAC)
    {
    }
    else
    {
        kal_uint8 u1AMRType = (u4ACodec == MEDIA_FORMAT_AMR) ? 0 : 1; // 0:AMR, 1:AMR-WB
        _MP4_ParseAMRData(u1AMRType, pu1Addr, u4Size, fgTruncateAudio);
    }
}


/**
 * Process aduio data
 */
static VIDEO_ERROR_TYPE_T _MP4_ProcessAudioData(MUXER_PROCESS_PARAM_T *const pParam, const kal_uint32 u4SizeToBeWritten)
{
    kal_uint8*  const pu1Addr = pParam->arData[0].pu1Addr;
    const kal_uint32 u4Size = pParam->arData[0].u4Size;
    kal_bool fgTruncateAudio = KAL_FALSE;

    if (_rMP4ALMgr.rAudioConfig.fgRecordAudio == KAL_TRUE)
    {
        const kal_uint32 u4DataType = MX_DATATYPE_AUDIO;
        kal_uint32 * const pu4AudioBufWIdx = &_rMP4ALMgr.rAudioMgr.u4AudioBufWIdx;
        AUDIO_BUFFER_T  *const prAudioBuf = &_rMP4ALMgr.rAudioMgr.arAudioBuf[*pu4AudioBufWIdx];

        if (prAudioBuf->fgValid == KAL_FALSE)
        {
            // We assume audio only use one MUXER_BUFFER_T
            prAudioBuf->fgValid = KAL_TRUE;
            prAudioBuf->pu1Addr = pu1Addr;
            prAudioBuf->u4Size = u4SizeToBeWritten;
            prAudioBuf->u4OriSize = u4Size;

            if (prAudioBuf->u4Size != prAudioBuf->u4OriSize)
            {
                drv_trace2(TRACE_GROUP_10, MUX_MP4AL_TRUNCATE_AUDIO,
                    prAudioBuf->u4OriSize, prAudioBuf->u4Size);

                fgTruncateAudio = KAL_TRUE;
            }

            (*pu4AudioBufWIdx)++;
            if (*pu4AudioBufWIdx == MAX_AUDIO_BUFFER_SECTION)
            {
                *pu4AudioBufWIdx = 0;
            }
        }
        else
        {
            _MP4_DEBUG_ASSERT();
        }

        _rMP4ALMgr.rAudioMgr.u4AudioTotalSize += prAudioBuf->u4Size;
        _MP4_ParseAudioData(prAudioBuf->pu1Addr, prAudioBuf->u4Size, fgTruncateAudio);
        _MP4_CallBack(MP4_EVENT_RDY_2_WRITE_AUDIO, (void*)&u4DataType, __LINE__);
    }
    else
    {
        /*
            Although we don't record audio, we still need to parse audio frame
            to get audio duration.
        */
        _MP4_ParseAudioData(pu1Addr, u4Size, fgTruncateAudio);
        _MP4_ReturnData(MX_DATATYPE_AUDIO, pu1Addr, u4Size);
    }

    return VIDEO_ERROR_NONE;
}


/**
 * Write audio data to file
 */
static VIDEO_ERROR_TYPE_T _MP4_WriteAudioData()
{
    STFSAL * const prFSALAudio = &_rMP4ALMgr.rMp4FileMgr.rFile[MP4_AUDIO_FILE];
    AUDIO_BUFFER_T  * const parAudioBuf = _rMP4ALMgr.rAudioMgr.arAudioBuf;
    kal_uint32 * const pu4AudioBufRIdx = &_rMP4ALMgr.rAudioMgr.u4AudioBufRIdx;
    kal_uint32 u4SectionIdx = MAX_AUDIO_BUFFER_SECTION;


    for (; u4SectionIdx > 0; u4SectionIdx--)
    {
        AUDIO_BUFFER_T * const prAudioBuf = &parAudioBuf[*pu4AudioBufRIdx];

        if (prAudioBuf->fgValid == KAL_TRUE)
        {
            FSAL_Status eFSALRet = FSAL_OK;

            eFSALRet = _MP4_WriteData2File(MP4_AUDIO_FILE, prFSALAudio, prAudioBuf->pu1Addr, prAudioBuf->u4Size);
            // Return buffer
            {
                _MP4_ReturnData(MX_DATATYPE_AUDIO, prAudioBuf->pu1Addr, prAudioBuf->u4OriSize);

                (*pu4AudioBufRIdx)++;
                if (*pu4AudioBufRIdx == MAX_AUDIO_BUFFER_SECTION)
                {
                    *pu4AudioBufRIdx = 0;
                }
                kal_mem_set(prAudioBuf, 0, sizeof(*prAudioBuf));
            }

            if (eFSALRet != FSAL_OK)
            {
                return MP4_FSALFailHdlr(prFSALAudio);
            }
        }
        else
        {
            break;
        }
    }

    return VIDEO_ERROR_NONE;
}


/**
 *  Flush video bitstream to file
 */
static VIDEO_ERROR_TYPE_T _MP4_FlushVideoData()
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_bool fgNeedToFlush;
    fgNeedToFlush = MP4_MarkBitBufferForFlush(&_rMP4ALMgr.rBitCtrlMgr);

    if (fgNeedToFlush == KAL_TRUE)
    {
        VIDEO_ERR_RTN(_MP4_CheckAndWriteBitStream());
    }

    return VIDEO_ERROR_NONE;
}


/**
 *  Query whether temp files exist
 */
static VIDEO_ERROR_TYPE_T _MP4_QueryTempFileExist(kal_wchar* const pau2TempWorkingPath)
{
    kal_int32 i4FSRet;
    kal_wstrcat(pau2TempWorkingPath, _MP4_VIDEO_FILE);

    i4FSRet = FS_CheckFile(pau2TempWorkingPath);

    if (i4FSRet == FS_NO_ERROR)
    {
       return VIDEO_ERROR_MUXER_EXIST_TEMP_FILE;
    }

    return VIDEO_ERROR_MUXER_NO_TEMP_FILE;
}


/**
 * For size-limited or disk full, add data to unfinished list
 */
static VIDEO_ERROR_TYPE_T _MP4_AddUnfinishedData(kal_uint8 * const pu1Addr, const kal_uint32 u4Size, kal_uint32 u4Auxiliary)
{
    kal_uint32 *pu4UnfinishedDataIdx = &_rMP4ALMgr.u4UnfinishedDataIdx;
    MP4_UNFINISHED_DATA_T *prUnfinishedData;

    drv_trace2(TRACE_GROUP_10, MUX_MP4AL_ADD_UNFINISHED_DATA,
        (kal_uint32)pu1Addr,
        u4Size);

    prUnfinishedData = &_rMP4ALMgr.rUnfinishedData[*pu4UnfinishedDataIdx];
    if (prUnfinishedData->u4Size == 0)
    {
       prUnfinishedData->pu1Addr = pu1Addr;
       prUnfinishedData->u4Size = u4Size;
    }
    else
    {
        if ((prUnfinishedData->pu1Addr + prUnfinishedData->u4Size) == pu1Addr)
        {
            prUnfinishedData->u4Size += u4Size;
        }
        else
        {
            (*pu4UnfinishedDataIdx)++;
            MP4_ASSERT(*pu4UnfinishedDataIdx < MAX_UNFINISHED_DATA);

            prUnfinishedData = &_rMP4ALMgr.rUnfinishedData[*pu4UnfinishedDataIdx];
            prUnfinishedData->pu1Addr = pu1Addr;
            prUnfinishedData->u4Size = u4Size;
        }
    }
    return VIDEO_ERROR_NONE;
}


/**
 *  Check size-limited is reached or disk full
 */
static kal_uint32 _MP4_CheckSizeLimit(MUXER_PROCESS_PARAM_T * pParam, kal_bool *pfgReachThreshold)
{
    kal_uint32 u4InputSize = 0;
    *pfgReachThreshold = KAL_FALSE;

    if (pParam->arData[0].fgValid == KAL_TRUE)
    {
        u4InputSize += pParam->arData[0].u4Size;
    }
    if (pParam->arData[1].fgValid == KAL_TRUE)
    {
        u4InputSize += pParam->arData[1].u4Size;
    }

    // If fgRcordAudio is False
    if (pParam->u4DataType == MX_DATATYPE_AUDIO &&
        _rMP4ALMgr.rAudioConfig.fgRecordAudio == KAL_FALSE)
    {
        return u4InputSize;
    }

    {
        kal_uint32 u4ReservedAudioSize = 0;
        const kal_uint32 u4FtypSize = 24;   // Ftyp box size is fixed
        const kal_uint32 u4Mdat = 8;
        kal_uint32 u4ReservedAudioFrameCount = 0;
        kal_uint32 u4VideoSize, u4VideoBoxSize;
        kal_uint32 u4AudioSize = 0, u4AudioBoxSize = 0;
        kal_uint32 u4ClusterSize = _rMP4ALMgr.u4ClusterSize;
        kal_uint64 *pu8CurrentFileSize = &_rMP4ALMgr.u8CurrentFileSize;
        kal_uint64 u8CurrentFileDiskSize = 0;
        kal_bool fgRecordAudio = _rMP4ALMgr.rAudioConfig.fgRecordAudio;
        MP4_GET_BOX_SIZE_T Param;

        // Audio Part
        if (fgRecordAudio == KAL_TRUE)
        {
            if (pParam->u4DataType == MX_DATATYPE_VIDEO)
            {
                kal_uint32 u4VideoDuration = MP4_GetVideoDuration() + (ONE_SEC_IN_MICROSEC / (_rMP4ALMgr.rVideoConfig.u4VideoFrameRate / 10));
                kal_uint32 u4AudioDuration = MP4_GetAudioFrameCount() * TIME_PER_AMR_FRAME;

                if (u4VideoDuration > u4AudioDuration)
                {
                    u4ReservedAudioFrameCount = ((u4VideoDuration - u4AudioDuration) / TIME_PER_AMR_FRAME) + 1;
                    u4ReservedAudioSize = (u4ReservedAudioFrameCount * SIZE_PER_AMR_FRAME);
                }
            }

            u4AudioBoxSize = MP4_GetAudioBoxSize(u4ReservedAudioFrameCount);
            u4AudioSize = u4Mdat + _rMP4ALMgr.rAudioMgr.u4AudioTotalSize + u4ReservedAudioSize;
        }

        // Video Part
        u4VideoSize = u4FtypSize + u4Mdat + _rMP4ALMgr.rBitCtrlMgr.u4BitstreamTotalSize;
        MP4_GetVideoBoxSize(&Param);
        u4VideoBoxSize = Param.u4DefaultBoxSize + Param.u4StcoBoxSize + Param.u4StssBoxSize +
        Param.u4StszBoxSize + Param.u4SttsBoxSize;

        *pu8CurrentFileSize = u4VideoSize + u4AudioSize + u4VideoBoxSize + u4AudioBoxSize;

        drv_trace8(TRACE_GROUP_9, MUX_MP4AL_SIZE_LIMITED,
            (kal_uint32)_rMP4ALMgr.u8FileSizeLimit,
            u4InputSize,
            (kal_uint32)*pu8CurrentFileSize, u4VideoSize, u4VideoBoxSize, u4AudioSize, u4AudioBoxSize, u4ReservedAudioSize);

        //  For disk full case. Because we use "copy" method to append data into real meta,
        //  so we need to reserve disk buffer.

        if (fgRecordAudio == KAL_TRUE)
        {
            u4AudioSize += u4ClusterSize; // Reserved one more cluster.
        }

        {
            kal_uint32 u4ExtraSizeOverhead = 0;
            kal_uint32 u4RealMetaSize = 0;
            kal_uint32 u4TempMetaSize = MP4_GetTempFileSize();

            // Create file extra overhead
            u4RealMetaSize = u4AudioBoxSize + u4VideoBoxSize;
            MP4_CLUSTERALIGNEDSIZE(u4RealMetaSize, u4ClusterSize);

            if (_rMP4ALMgr.fgEnableSizeLimit == KAL_TRUE)
            {
                u4ExtraSizeOverhead = u4AudioSize + u4RealMetaSize * 2; // Audio + Real Meta
            }
            else
            {
                u4ExtraSizeOverhead = u4RealMetaSize; // Real Meta file
            }
            MP4_CLUSTERALIGNEDSIZE(u4ExtraSizeOverhead, u4ClusterSize);

            // Recording
            MP4_CLUSTERALIGNEDSIZE(u4VideoSize, u4ClusterSize);
            MP4_CLUSTERALIGNEDSIZE(u4AudioSize, u4ClusterSize);
            MP4_CLUSTERALIGNEDSIZE(u4TempMetaSize, u4ClusterSize);
            MP4_CLUSTERALIGNEDSIZE(Param.u4StcoBoxSize, u4ClusterSize);
            MP4_CLUSTERALIGNEDSIZE(Param.u4StssBoxSize, u4ClusterSize);
            MP4_CLUSTERALIGNEDSIZE(Param.u4StszBoxSize, u4ClusterSize);
            MP4_CLUSTERALIGNEDSIZE(Param.u4SttsBoxSize, u4ClusterSize);


            u4VideoBoxSize = Param.u4StcoBoxSize + Param.u4StssBoxSize +
                            Param.u4StszBoxSize + Param.u4SttsBoxSize;

            u8CurrentFileDiskSize = u4VideoSize + u4AudioSize + u4VideoBoxSize + u4TempMetaSize + u4ExtraSizeOverhead;
            drv_trace8(TRACE_GROUP_9, MUX_MP4AL_DISK_FULL,
                        _rMP4ALMgr.u8FreeDiskSize >> 32, _rMP4ALMgr.u8FreeDiskSize & 0xFFFFFFFF,
                        u4InputSize,
                        u8CurrentFileDiskSize & 0xFFFFFFFF,
                        u4VideoSize, u4VideoBoxSize, u4AudioSize, u4ExtraSizeOverhead);
        }

        // Check threshold
        if ((_rMP4ALMgr.u8FileSizeLimit > 0 && ((*pu8CurrentFileSize + u4InputSize) >= _rMP4ALMgr.u8FileSizeLimit)) ||
            (u8CurrentFileDiskSize + u4InputSize) >= _rMP4ALMgr.u8FreeDiskSize)
        {
            if (pParam->u4DataType == MX_DATATYPE_VIDEO)
            {
                kal_uint32 u4FrameSize;
                _MP4_ProcessBuf(pParam->arData, &_MP4_AddUnfinishedData, &u4FrameSize);
                *pfgReachThreshold = KAL_TRUE;
            }
            else if (pParam->u4DataType == MX_DATATYPE_AUDIO)
			{
				// Need to truncate audio
				kal_uint32 u4TruncatedInputSize = 0;
				if (_rMP4ALMgr.u8FileSizeLimit > 0 && *pu8CurrentFileSize >= _rMP4ALMgr.u8FileSizeLimit)
				{
					u4TruncatedInputSize = 0;
				}
				else
				{
					if (_rMP4ALMgr.u8FileSizeLimit > *pu8CurrentFileSize)
					{
						u4TruncatedInputSize = _rMP4ALMgr.u8FileSizeLimit - *pu8CurrentFileSize;
					}
					else if(_rMP4ALMgr.u8FreeDiskSize > u8CurrentFileDiskSize)
					{
						u4TruncatedInputSize = _rMP4ALMgr.u8FreeDiskSize - u8CurrentFileDiskSize;
					}
					else
					{
						u4TruncatedInputSize = 0;
					}
				}
				
				u4InputSize = (u4InputSize < u4TruncatedInputSize)?u4InputSize:u4TruncatedInputSize;
			}
            else
            {
                _MP4_DEBUG_ASSERT();
            }
        }
        else
        {
            *pu8CurrentFileSize += u4InputSize;
        }
    }

    return u4InputSize;
}


/**
 *  Merge src file to dest file
 */
static VIDEO_ERROR_TYPE_T _MP4_MergeFile(STFSAL *prFSALSrc, STFSAL *prFSALDst)
{
    kal_uint32 u4SrcSize;
    kal_uint32 u4DstSize;
    kal_uint8* pu1MergeBuffer = NULL, *pau1NonCachableBuffer = NULL;

    FSAL_ERR_RTN(prFSALSrc, FSAL_GetFileSize(prFSALSrc, &u4SrcSize));
    FSAL_ERR_RTN(prFSALDst, FSAL_GetFileSize(prFSALDst, &u4DstSize));
    FSAL_ERR_RTN(prFSALDst, FSAL_Seek(prFSALDst, u4DstSize));
    FSAL_ERR_RTN(prFSALSrc, FSAL_Seek(prFSALSrc, 0));

    pu1MergeBuffer = (kal_uint8*)MuxerAdaptGetMemory(MP4_MERGE_FILE_BUFFER_SIZE_IN_BYTE, KAL_TRUE);
    pau1NonCachableBuffer = (kal_uint8*)VideoCommExtBufferCacheableSwitchAlignMemory(
        (kal_uint32)pu1MergeBuffer, MP4_VIDEO_IO_BUFFER_SIZE_IN_BYTE, VIDEO_NON_CACHEABLE);

    if (pau1NonCachableBuffer == NULL)
    {
        return VIDEO_ERROR_BUFF_FULL;
    }

    while (u4SrcSize >= MP4_MERGE_FILE_BUFFER_SIZE_IN_BYTE)
    {
        FSAL_ERR_RTN(prFSALSrc, FSAL_Read(prFSALSrc, pau1NonCachableBuffer, MP4_MERGE_FILE_BUFFER_SIZE_IN_BYTE));
        FSAL_ERR_RTN(prFSALDst, FSAL_Write(prFSALDst, pau1NonCachableBuffer, MP4_MERGE_FILE_BUFFER_SIZE_IN_BYTE));

        u4SrcSize -= MP4_MERGE_FILE_BUFFER_SIZE_IN_BYTE;
    }

    // remainded data
    if (u4SrcSize)
    {
        FSAL_ERR_RTN(prFSALSrc, FSAL_Read(prFSALSrc, pau1NonCachableBuffer, u4SrcSize));
        FSAL_ERR_RTN(prFSALDst, FSAL_Write(prFSALDst, pau1NonCachableBuffer, u4SrcSize));

        u4SrcSize = 0;
    }

    MuxerAdaptFreeMemory(pu1MergeBuffer);

    return VIDEO_ERROR_NONE;
}


/**
 * Dump video bitstream information
 */
static void  _MP4_DumpInfo(void)
{
    kal_uint64 u8Rate, u8Size, u8Time;
    kal_uint32 u4Rate;
    MP4_INFO_T * const prInfo = &_rMP4ALMgr.rInfo;

    u8Size = prInfo->u4AccuBitDataSize;
    u8Time = prInfo->u4AccuBitDataDuration;
    if (u8Time != 0)
    {
        u8Rate = (u8Size * 1000) / u8Time;
        u4Rate = (kal_uint32)u8Rate;
    }
    else
    {
        u8Rate = 0;
        u4Rate = 0;
    }

    drv_trace4(TRACE_GROUP_9, MUX_MP4AL_BIT_INFO_AVERAGE,
        prInfo->u4AccuBitDataSize,
        prInfo->u4AccuBitDataDuration, u4Rate, 0);

    drv_trace2(TRACE_GROUP_9, MUX_MP4AL_BIT_INFO_PEAK,
        prInfo->u4PeakBitDataSize,
        prInfo->u4PeakBitDataDuration);
}


static VIDEO_ERROR_TYPE_T _MP4_PseudoMerge(kal_wchar * const pau2FilePath1, kal_wchar * const pau2TempWorkingPath, kal_wchar * const pau2FileName)
{
    kal_int32 i4FSError;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    kal_wstrcat(pau2TempWorkingPath, pau2FileName);
    i4FSError = FS_PseudoMerge(pau2FilePath1, pau2TempWorkingPath);

    if (i4FSError != FS_NO_ERROR)
    {
        drv_trace0(TRACE_GROUP_10, MUX_MP4AL_PSEUDO_MERGE_FAIL);
        eError = VIDEO_ERROR_MUXER_FS_ERROR;
    }

    MuxerAdaptRemoveFileName(pau2TempWorkingPath);

    return eError;
}

static VIDEO_ERROR_TYPE_T _MP4_DumpTempFileSize()
{
    kal_uint32 u4VideoFileSize, u4AudioFileSize;
    kal_uint32 u4SttsFileSize, u4StszFileSize, u4StssFileSize, u4StcoFileSize;

    STFSAL *prFile = _rMP4ALMgr.rMp4FileMgr.rFile;
    STFSAL *prFSALVideo = &prFile[MP4_VIDEO_FILE];
    STFSAL *prFSALAudio = &prFile[MP4_AUDIO_FILE];
    STFSAL *prFSALStts = &prFile[MP4_VIDEO_STTS_FILE];
    STFSAL *prFSALStsz = &prFile[MP4_VIDEO_STSZ_FILE];
    STFSAL *prFSALStss = &prFile[MP4_VIDEO_STSS_FILE];
    STFSAL *prFSALStco = &prFile[MP4_VIDEO_STCO_FILE];

    FSAL_ERR_RTN(prFSALVideo, FSAL_GetFileSize(prFSALVideo, &u4VideoFileSize));
    FSAL_ERR_RTN(prFSALAudio, FSAL_GetFileSize(prFSALAudio, &u4AudioFileSize));
    FSAL_ERR_RTN(prFSALStts, FSAL_GetFileSize(prFSALStts, &u4SttsFileSize));
    FSAL_ERR_RTN(prFSALStsz, FSAL_GetFileSize(prFSALStsz, &u4StszFileSize));
    FSAL_ERR_RTN(prFSALStss, FSAL_GetFileSize(prFSALStss, &u4StssFileSize));
    FSAL_ERR_RTN(prFSALStco, FSAL_GetFileSize(prFSALStco, &u4StcoFileSize));

    drv_trace8(TRACE_GROUP_9, MUX_MP4AL_CREATEFILE_TEMP_FILE_SIZE,
                u4VideoFileSize, u4AudioFileSize,
                u4SttsFileSize, u4StszFileSize, u4StssFileSize, u4StcoFileSize, 0, 0);
    return VIDEO_ERROR_NONE;
}


/******************************************************************************
* Exported function
******************************************************************************/

/**
 * Open MP4 adaptation layer
 */
static VIDEO_ERROR_TYPE_T _MP4_MuxerAdapterOpen(void)
{
    kal_int32   u4FileIdx = MP4_NUM_OF_FILE - 1;
    STFSAL      *const prFSALFile = _rMP4ALMgr.rMp4FileMgr.rFile;

    kal_mem_set(&_rMP4ALMgr, 0, sizeof(_rMP4ALMgr));

    // File handle default value should be -1
    for (; u4FileIdx >= 0; u4FileIdx--)
    {
        prFSALFile[u4FileIdx].hFile = -1;
    }

    _rMP4ALMgr.pau2FilePath = (kal_wchar*)MuxerAdaptGetMemory(_MP4_SIZE_OF_FILE_NAME_BUFFER, KAL_FALSE);
    _rMP4ALMgr.pau2WorkingPath = (kal_wchar*)MuxerAdaptGetMemory(_MP4_SIZE_OF_FILE_NAME_BUFFER, KAL_FALSE);
    u4VideoWriteThreshold = MP4_BITSTREAM_THRESHOLD;

    return VIDEO_ERROR_NONE;
}


/**
 * Allocate system resource including memory,¡Ketc.
 * Initialize control structures
 * To simplify the initialization, all the parameters would be set through pfnSetParam() before this function is called
 */
static VIDEO_ERROR_TYPE_T _MP4_MuxerAdapterInit(void)
{
    VIDEO_ERROR_TYPE_T  eError = VIDEO_ERROR_NONE;

    drv_trace0(TRACE_GROUP_10, MUX_MP4AL_INIT);

    MP4_ASSERT(_rMP4ALMgr.pfnCallBack != NULL);

    // Get cluster size
    MuxerAdaptGetDiskInfo(_rMP4ALMgr.pau2WorkingPath, &_rMP4ALMgr.u4ClusterSize, &_rMP4ALMgr.u8FreeDiskSize);

    switch (_rMP4ALMgr.eScenario)
    {
    case MUXER_SCENARIO_RECORD:
        {
            STFSAL *prFSAL;
            do
            {
                VIDEO_ERR_BREAK(_MP4_OpenTempFiles(_rMP4ALMgr.eScenario));
                prFSAL = _rMP4ALMgr.rMp4FileMgr.rFile;

                MP4_InitMeta(KAL_TRUE);
                MP4_InitBitBuffer(&_rMP4ALMgr.rBitCtrlMgr);
                VIDEO_ERR_BREAK(_MP4_InitTmpMetaFile(&prFSAL[MP4_TEMP_META_FILE]));

                if (_rMP4ALMgr.rAudioConfig.fgRecordAudio == KAL_TRUE)
                {
                    VIDEO_ERR_BREAK(MP4_GenAudioFileHeader(&prFSAL[MP4_AUDIO_FILE]));
                }
                VIDEO_ERR_BREAK(MP4_GenVideoFileHeader(&prFSAL[MP4_VIDEO_FILE],
                    &prFSAL[MP4_TEMP_META_FILE], &_rMP4ALMgr.rBitCtrlMgr.u4BitStreamOffset));

                // Time-limited
                if (_rMP4ALMgr.u4TimeLimit != 0)
                {
                    if (_rMP4ALMgr.rAudioConfig.eAudioFormat == MEDIA_FORMAT_AMR)
                    {
                        kal_uint32 u4AudioFrameLimit =  _rMP4ALMgr.u4TimeLimit / TIME_PER_AMR_FRAME;
                        MP4_SetAudioTimeLimit(u4AudioFrameLimit);
                    }
                }
            }while(0);

            if (eError !=  VIDEO_ERROR_NONE)
            {
                _MP4_CloseTempFiles();
                return eError;
            }
        }
        break;
    case MUXER_SCENARIO_CREATE_FILE:
        {
            _MP4_OpenTempFiles(_rMP4ALMgr.eScenario);
            MP4_InitMeta(KAL_FALSE);
        }
        break;
    default:
        {
            _MP4_DEBUG_ASSERT();
        }
        break;
    };

    return VIDEO_ERROR_NONE;
}

/**
 * Remember not to assert un-recognized parameters, return error instead
 */
static VIDEO_ERROR_TYPE_T _MP4_MuxerAdapterGetParam(VIDEO_PARAM_TYPE_T eType, void *pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    switch (eType)
    {
    case MUXER_GET_MEMORY_SIZE:
        {
            if (_rMP4ALMgr.eScenario == MUXER_SCENARIO_CREATE_FILE)
            {
                *(kal_uint32*)pParam = MP4_MUXER_TOTAL_CREATEFILE_MEM_SIZE;
            }
            else
            {
                *(kal_uint32*)pParam = MP4_MUXER_TOTAL_RECORD_MEM_SIZE;
            }
        }
        break;
    case MUXER_GET_CURRENT_FILE_SIZE:
        {
            *(kal_uint64*)pParam = _rMP4ALMgr.u8CurrentFileSize;
        }
        break;
    case MUXER_GET_RETURNING_VIDEO_BUFFER_NUMBER:
        {
            *(kal_uint32*)pParam = MP4_QueryWrittenBufferCount(&_rMP4ALMgr.rBitCtrlMgr);
        }
        break;
    case MUXER_GET_RETURNING_AUDIO_BUFFER_NUMBER:
        {
            *(kal_uint32*)pParam = 1; // TODO: FIXME
        }
        break;
    default:
        {
            return VIDEO_ERROR_MUXER_NOT_SUPPORT;
        }
    }

    drv_trace1(TRACE_GROUP_10, MUX_MP4AL_GET_PARAM, (kal_uint32)eType);

    return eError;
}


/**
 * Remember not to assert un-recognized parameters, return error instead
 */
static VIDEO_ERROR_TYPE_T _MP4_MuxerAdapterSetParam(VIDEO_PARAM_TYPE_T eType, void *pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace1(TRACE_GROUP_10, MUX_MP4AL_SET_PARAM, (kal_uint32)eType);

    switch (eType)
    {
    case MUXER_SET_SCENARIO:
        {
            _rMP4ALMgr.eScenario = *(MUXER_SCENARIO_T *)(pParam);
        }
        break;
    case MUXER_SET_VIDEO_CONFIG:
        {
            _rMP4ALMgr.rVideoConfig = *(MUXER_VIDEO_CONFIG_T*)(pParam);
        }
        break;
    case MUXER_SET_AUDIO_CONFIG:
        {
            _rMP4ALMgr.rAudioConfig = *(MUXER_AUDIO_CONFIG_T*)(pParam);
        }
        break;

    case MUXER_SET_FILE_NAME_PATH:
        {
            kal_wstrcpy((void*)_rMP4ALMgr.pau2FilePath, pParam);
        }
        break;

    case MUXER_SET_WORKING_PATH:
        {
            kal_wstrcpy((void*)_rMP4ALMgr.pau2WorkingPath, pParam);
            MuxerAdaptRemoveFileName(_rMP4ALMgr.pau2WorkingPath);
        }
        break;

    case MUXER_SET_CALLBACK:
        {
            _rMP4ALMgr.pfnCallBack = (PFN_CALLBACK)pParam;
        }
        break;
    case MUXER_SET_SIZE_LIMIT:
        {
            _rMP4ALMgr.u8FileSizeLimit = *(kal_uint64*)pParam;

            // Size-limited
            if (_rMP4ALMgr.u8FileSizeLimit != 0)
            {
                _rMP4ALMgr.fgEnableSizeLimit = KAL_TRUE;
            }
            else
            {
                _rMP4ALMgr.fgEnableSizeLimit = KAL_FALSE;
            }
        }
        break;
    case MUXER_SET_TIME_LIMIT:
        {
            _rMP4ALMgr.u4TimeLimit = *(kal_uint32*)pParam;
        }
        break;
    case MUXER_SET_VIDEO_WRITE_THRESHOLD:
        {
            kal_uint32 u4WriteThreshold = *(kal_uint32*)pParam;
            if (u4WriteThreshold != 0)
            {
                u4VideoWriteThreshold = u4WriteThreshold;
            }
        }
        break;
#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
    case MUXER_SET_TIME_LAPSE_FRAME_RATE:
        {
            kal_uint32 u4TLFrameRate = *(kal_uint32*)pParam;
            if (u4TLFrameRate != 0)
            {
                _rMP4ALMgr.u4TLFrameDuration = ONE_SEC_IN_MICROSEC / (u4TLFrameRate / 10);
            }
        }
        break;
#endif
    default:
        {
            return VIDEO_ERROR_MUXER_NOT_SUPPORT;
        }
    };
    return eError;
}

static VIDEO_ERROR_TYPE_T _MP4_MuxerAdapterDirectlyGetParam(VIDEO_PARAM_TYPE_T eType, void *pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    switch (eType)
    {
    case MUXER_IS_TEMP_FILE_EXISTED:
        {
            // Note: the function must be independent of other code.
            kal_wchar* const pau2WorkingPath = (kal_wchar*)pParam;
            kal_wchar *pau2TempFileWorkingPath = (kal_wchar*)get_ctrl_buffer(_MP4_SIZE_OF_FILE_NAME_BUFFER); // for API-based function call
            kal_wstrcpy((void*)pau2TempFileWorkingPath, pau2WorkingPath);
            MuxerAdaptRemoveFileName(pau2TempFileWorkingPath);
            eError =  _MP4_QueryTempFileExist(pau2TempFileWorkingPath);
            free_ctrl_buffer((void*)pau2TempFileWorkingPath);
        }
    break;
    case MUXER_GET_MIN_SPACE_TO_RECORD:
        {
            MUXER_GET_MIN_SPACE_T *prMinSpaceParam = (MUXER_GET_MIN_SPACE_T *)pParam;
            {
                /*
                We assume only one video frame,
                a. one video YUV frame size
                b. video box
                c. audio box
                */
                prMinSpaceParam->u4MinSpace = (prMinSpaceParam->u4Width * prMinSpaceParam->u4Height * 3 / 2) + // YUV420
                                            (DEFAULT_VIDEO_BOX_SIZE + MIN_VIDEO_STBL_SIZE) +
                                            (DEFAULT_AUDIO_BOX_SIZE + MIN_AUDIO_STBL_SIZE) +
                                            (32 * 1024) * _MP4_FILE_MERGE_NUM;  // File merge overhead
            }
        }
        break;

    case MUXER_GET_VIDEO_BITSTREAM_LEFTOVER:
        {
            // Please note MP4_BITSTREAM_FILE_HEADER mighe be changed
            *(kal_uint32*)pParam = _u4VideoDirectlyWriteThreshold - MP4_BITSTREAM_FILE_HEADER;
#if !defined(__VE_SLIM_PROJECT__)
            drv_trace1(TRACE_GROUP_9, MUX_MP4AL_VIDEO_WRITE_THRESHOLD, *(kal_uint32*)pParam);
#endif
        }
        break;
    case MUXER_GET_AUDIO_HEADERSIZE:
        {
            *(kal_uint32*)pParam = 8;
        }
        break;
    default:
        {
            return VIDEO_ERROR_MUXER_NOT_SUPPORT;
        }
    };

    return eError;
}


static VIDEO_ERROR_TYPE_T _MP4_MuxerAdapterDirectlySetParam(VIDEO_PARAM_TYPE_T eType, void *pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    switch (eType)
    {
    case MUXER_CLEAR_TEMP_FILE:
        {
            // Note: the function must be independent of other code.
            kal_wchar* const pau2WorkingPath = (kal_wchar*)pParam;
            kal_wchar *pau2TempFileWorkingPath = (kal_wchar*)get_ctrl_buffer(_MP4_SIZE_OF_FILE_NAME_BUFFER); // for API-based function call
            kal_wstrcpy((void*)pau2TempFileWorkingPath, pau2WorkingPath);
            MuxerAdaptRemoveFileName(pau2TempFileWorkingPath);
            eError = _MP4_ClearTempFiles(pau2TempFileWorkingPath);
            free_ctrl_buffer((void*)pau2TempFileWorkingPath);
        }
    break;
    case MUXER_SET_VIDEO_WRITE_THRESHOLD:
        {
            kal_uint32 u4WriteThreshold = *(kal_uint32*)pParam;
            if (u4WriteThreshold != 0)
            {
                _u4VideoDirectlyWriteThreshold = *(kal_uint32*)pParam;
            }
            else
            {
                _u4VideoDirectlyWriteThreshold = MP4_BITSTREAM_THRESHOLD;
            }
        }
        break;
    default:
        {
            return VIDEO_ERROR_MUXER_NOT_SUPPORT;
        }
    };

    return eError;
}


/**
 * Process video/audio data
 * Both video/audio data would be frame-based
 * Callback Muxer if the adapter needs to write data to file
 * Race condition: processing audio and video may run on different tasks
 */
static VIDEO_ERROR_TYPE_T _MP4_MuxerAdapterProcessData(MUXER_PROCESS_PARAM_T * pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace8(TRACE_GROUP_10, MUX_MP4AL_PROCESS_Data,
        pParam->u4DataType, (kal_uint32)(pParam->u8TimeStamp & 0xFFFFFFFF), pParam->u4FrameType,
        pParam->arData[0].fgValid, pParam->arData[0].u4Size,
        pParam->arData[1].fgValid, pParam->arData[1].u4Size, (kal_uint32)pParam->pPrivateData);

    // video or audio
    switch (pParam->u4DataType)
    {
    case MX_DATATYPE_VIDEO_SEQUENCE_HEADER:
        {
            eError = _MP4_ProcessVSequenceHeader(pParam);
        }
        break;
    case MX_DATATYPE_VIDEO:
        {
            kal_bool fgReachThreshold = KAL_FALSE;
            _MP4_CheckSizeLimit(pParam, &fgReachThreshold);
            if (fgReachThreshold == KAL_TRUE)
            {
                if (_rMP4ALMgr.fgEnableSizeLimit == KAL_TRUE)
                {
                    return VIDEO_ERROR_MUXER_REACH_SIZE_LIMIT;
                }
                else
                {
                    return VIDEO_ERROR_MUXER_DISK_FULL;
                }
            }

            eError = _MP4_ProcessVideoData(pParam);
        }
        break;
    case MX_DATATYPE_AUDIO:
        {
            kal_bool fgReachThreshold = KAL_FALSE;
            kal_uint32 u4SizeToBeWritten = _MP4_CheckSizeLimit(pParam, &fgReachThreshold);
            eError = _MP4_ProcessAudioData(pParam, u4SizeToBeWritten);
        }
        break;
    default:
        {
            _MP4_DEBUG_ASSERT();
        }
    };

    return eError;
}

/**
 * Process file-system-related operations about either audio or video
 * Note that one parameter would be used to specify to process either audio or video, process the data accordingly.
 * Process video data when Muxer specified audio is not allowed since audio data may be processed in high priority task
 * Race condition: processing audio and video may run on different tasks
 */
static VIDEO_ERROR_TYPE_T _MP4_MuxerAdapterWriteData2File(MUXER_WRITE_PARAM_T * pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    drv_trace1(TRACE_GROUP_10, MUX_MP4AL_WRITE_Data, pParam->u4DataType);
    switch (pParam->u4DataType)
    {
    case MX_DATATYPE_VIDEO_SEQUENCE_HEADER:
        {
            MUXER_PROCESS_PARAM_T * const prParameterSet = &_rMP4ALMgr.rParameterSet;

            if (_rMP4ALMgr.fgGetParameterSet == KAL_TRUE)
            {
                eError = _MP4_WriteParameterSet(prParameterSet->arData,
                    prParameterSet->pPrivateData);
                if (eError != VIDEO_ERROR_NONE)
                {
                    _MP4_CallBack(MP4_EVENT_RETURN_BUFFER, &_rMP4ALMgr.rParameterSet, __LINE__);
                    _MP4_ReturnAllData();
                    return eError;
                }

                _MP4_CallBack(MP4_EVENT_RETURN_BUFFER, &_rMP4ALMgr.rParameterSet, __LINE__);
                _rMP4ALMgr.fgGetParameterSet = KAL_FALSE;
            }
        }
        break;
    case MX_DATATYPE_VIDEO:
        {
            // check bitstream
            if ((eError = _MP4_CheckAndWriteBitStream()) != VIDEO_ERROR_NONE)
            {
                _MP4_ReturnAllData();
                return eError;
            }

            // check metadata
            if ((eError = _MP4_CheckAndWriteStblData()) != VIDEO_ERROR_NONE)
            {
                _MP4_ReturnAllData();
                return eError;
            }
        }
        break;
    case MX_DATATYPE_AUDIO:
        {
            if ((eError = _MP4_WriteAudioData()) != VIDEO_ERROR_NONE)
            {
                _MP4_ReturnAllData();
                return eError;
            }
        }
        break;
    case MX_DATATYPE_ALL:
        {
            if (pParam->fgFlush == KAL_TRUE)
            {
                kal_uint32 u4TotalAFrames;
                kal_uint64 u8StopTime;
                kal_uint32 u4RecordStatus = RECORD_STATUS_SUCCEED;
                STFSAL *prFSALTmpMeta = &_rMP4ALMgr.rMp4FileMgr.rFile[MP4_TEMP_META_FILE];

                VIDEO_ERR_RTN(_MP4_FlushVideoData());
                VIDEO_ERR_RTN(_MP4_WriteAudioData());
                VIDEO_ERR_RTN(MP4_STBL_FlushData(&_rMP4ALMgr.rMp4FileMgr));
                _MP4_ReturnUnfinishedData();

                u4TotalAFrames = MP4_GetAudioFrameCount();
                VIDEO_ERR_RTN(MP4_WriteMeta(prFSALTmpMeta, MP4_POS_RECORD_STATUS, 4, (kal_uint8*)&u4RecordStatus));

#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
                // For time lapse, use video duration and ignore audio duration
                if (_rMP4ALMgr.u4TLFrameDuration != 0)
                {
                    u8StopTime = MP4_GetVideoDuration() + _rMP4ALMgr.u4TLFrameDuration;
                }
                else
#endif
                {
                    VIDEO_ERR_RTN(MP4_WriteMeta(prFSALTmpMeta, MP4_POS_A_FRAME_COUNT, 4, (kal_uint8*)&u4TotalAFrames));
                    u8StopTime = u4TotalAFrames * TIME_PER_AMR_FRAME;

                    if (_rMP4ALMgr.u4TimeLimit != 0)
                    {
                        if (u8StopTime > _rMP4ALMgr.u4TimeLimit)
                        {
                            u8StopTime = _rMP4ALMgr.u4TimeLimit;
                        }
                    }
                }

                VIDEO_ERR_RTN(MP4_WriteMeta(prFSALTmpMeta, MP4_POS_STOP_TIME, 8, (kal_uint8*)&u8StopTime));
            }
            else
            {
                _MP4_DEBUG_ASSERT();
            }
        }
        break;
    default:
        {
            _MP4_DEBUG_ASSERT();
        }
    };

    return VIDEO_ERROR_NONE;
}


/**
 * Create the recorded file, including the audio and the video part
 * Create the file with pseudo merge or not should be configurable
 */
static VIDEO_ERROR_TYPE_T _MP4_MuxerAdapterCreateFile(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    kal_uint32  u4AudioFileSize, u4VideoFileSize, u4VideoMdatszPos;
    kal_bool    fgUsePseudoMerge, fgRecordAudio;
    STFSAL *prFSALVideo, *prFSALAudio, *prFSALTmpMeta, *prFSALRealMeta;
    kal_uint32  u4ClusterSize = _rMP4ALMgr.u4ClusterSize;
    kal_uint32 	u4Data;
    kal_uint32 u4RecordStatus;
    STFSAL *prFile = _rMP4ALMgr.rMp4FileMgr.rFile;

    VIDEO_ERR_RTN(_MP4_IsTempFileOpened());

    prFSALVideo = &prFile[MP4_VIDEO_FILE];
    prFSALAudio = &prFile[MP4_AUDIO_FILE];
    prFSALTmpMeta = &prFile[MP4_TEMP_META_FILE];
    prFSALRealMeta = &prFile[MP4_REAL_META_FILE];

    VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta,
        MP4_POS_PSEUDO_MERGE, 4, (kal_uint8*)&u4Data));
    fgUsePseudoMerge = (kal_bool)u4Data;

    VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta,
        MP4_POS_RECORD_STATUS, 4, (kal_uint8*)&u4RecordStatus));

    drv_trace8(TRACE_GROUP_9, MUX_MP4AL_CREATEFILE_DISK_INFO,
            fgUsePseudoMerge,
            u4RecordStatus,
            _rMP4ALMgr.u8FreeDiskSize >> 32, _rMP4ALMgr.u8FreeDiskSize & 0xFFFFFFFF,
            _rMP4ALMgr.u4ClusterSize, 0, 0, 0);

    if (u4RecordStatus != RECORD_STATUS_SUCCEED || u4ClusterSize == 0)
    {
        return VIDEO_ERROR_MUXER_FAILED_2_CREATE_FILE;
    }

    // Audio part
    {
        // Read "Record Audio" info
        VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta, MP4_POS_RECORD_AUDIO,
                                    4, (kal_uint8*)&u4Data));
        fgRecordAudio = (kal_bool)u4Data;

        if (fgRecordAudio == KAL_TRUE)
        {
            FSAL_ERR_RTN(prFSALAudio, FSAL_GetFileSize(prFSALAudio, &u4AudioFileSize));
            FSAL_ERR_RTN(prFSALAudio, FSAL_Seek(prFSALAudio, 0));

            if (fgUsePseudoMerge == KAL_TRUE)
            {
                MP4_CLUSTERALIGNEDSIZE(u4AudioFileSize, u4ClusterSize);
            }

            FSAL_ERR_RTN(prFSALAudio, FSAL_Write_UINT(prFSALAudio, u4AudioFileSize));
        }
    }


    // Video part
    {
        VIDEO_ERR_RTN(MP4_STBL_SettleDown(&_rMP4ALMgr.rMp4FileMgr));

        // Update video mdat box size
        FSAL_ERR_RTN(prFSALVideo, FSAL_GetFileSize(prFSALVideo, &u4VideoFileSize));

        if (fgUsePseudoMerge == KAL_TRUE)
        {
            MP4_CLUSTERALIGNEDSIZE(u4VideoFileSize, u4ClusterSize);
        }

        VIDEO_ERR_RTN(MP4_ReadMeta(prFSALTmpMeta,
            MP4_POS_V_MDAT_SIZE, sizeof(u4VideoMdatszPos), (kal_uint8*)&u4VideoMdatszPos));

        FSAL_ERR_RTN(prFSALVideo, FSAL_Write_UINT_AT(prFSALVideo,
                u4VideoFileSize - u4VideoMdatszPos, u4VideoMdatszPos));
    }

#if !defined(__VE_SLIM_PROJECT__)
    _MP4_DumpTempFileSize();
#endif

    _MP4_CHECK_ABORT_SAVING();
    VIDEO_ERR_RTN(MP4_CreateMetaFile(&_rMP4ALMgr.rMp4FileMgr, fgUsePseudoMerge, u4ClusterSize, fgRecordAudio, u4VideoFileSize));
    _MP4_CHECK_ABORT_SAVING();
    {
        kal_wchar *pau2FilePath = _rMP4ALMgr.pau2FilePath;
        kal_wchar *pau2WorkingPath = _rMP4ALMgr.pau2WorkingPath;
        kal_wchar *pau2FilePath1 = (kal_wchar*)MuxerAdaptGetMemory(_MP4_SIZE_OF_FILE_NAME_BUFFER, KAL_FALSE);
        kal_wchar *pau2TempWorkingPath = (kal_wchar*)MuxerAdaptGetMemory(_MP4_SIZE_OF_FILE_NAME_BUFFER, KAL_FALSE);

        kal_wstrcpy((void*)pau2FilePath1, pau2WorkingPath);
        kal_wstrcpy((void*)pau2TempWorkingPath, pau2FilePath1);

        kal_wstrcat(pau2FilePath1, _MP4_VIDEO_FILE);

        do
        {
            if (fgUsePseudoMerge == KAL_TRUE)
            {
                _MP4_CloseTempFiles();

                // Merge audio/video bistream
                if (fgRecordAudio == KAL_TRUE)
                {
                    VIDEO_ERR_BREAK(_MP4_PseudoMerge(pau2FilePath1, pau2TempWorkingPath, _MP4_AUDIO_FILE));
                }

                // Merge av bitstream file and av real meta file
                VIDEO_ERR_BREAK(_MP4_PseudoMerge(pau2FilePath1, pau2TempWorkingPath, _MP4_REAL_META_FILE));

#ifdef __ENABLE_STBL_PSEUDO_MERGE__
                VIDEO_ERR_BREAK(_MP4_PseudoMerge(pau2FilePath1, pau2TempWorkingPath, _MP4_VIDEO_STTS_FILE));
                VIDEO_ERR_BREAK(_MP4_PseudoMerge(pau2FilePath1, pau2TempWorkingPath, _MP4_VIDEO_STSZ_FILE));
                VIDEO_ERR_BREAK(_MP4_PseudoMerge(pau2FilePath1, pau2TempWorkingPath, _MP4_VIDEO_STSS_FILE));
                VIDEO_ERR_BREAK(_MP4_PseudoMerge(pau2FilePath1, pau2TempWorkingPath, _MP4_VIDEO_STCO_FILE));
#endif

            }
            else
            {
                if (fgRecordAudio == KAL_TRUE)
                {
                    VIDEO_ERR_BREAK(_MP4_MergeFile(prFSALAudio, prFSALVideo));

                    // Delete audio file first
                    FSAL_Close(prFSALAudio);
                    prFSALAudio->hFile = -1;
                    kal_wstrcat(pau2WorkingPath, _MP4_AUDIO_FILE);
                    FS_Delete(pau2WorkingPath);
                    MuxerAdaptRemoveFileName(pau2WorkingPath);

                }

                VIDEO_ERR_BREAK(_MP4_MergeFile(prFSALRealMeta, prFSALVideo));
                _MP4_CloseTempFiles();
            }

            // Rename to file name specified by MMI
            {
                kal_uint32  u4Attribute;
                FS_Rename(pau2FilePath1, pau2FilePath);
                u4Attribute = FS_GetAttributes(pau2FilePath);
                u4Attribute &= ~FS_ATTR_HIDDEN;
                FS_SetAttributes(pau2FilePath, (kal_uint8)u4Attribute);
            }
        } while(0);

        MuxerAdaptFreeMemory(pau2FilePath1);
        MuxerAdaptFreeMemory(pau2TempWorkingPath);

        _MP4_CloseTempFiles();
        _MP4_ClearTempFiles(pau2WorkingPath);
    }

    return eError;
}


/**
 * Release system resource including memory,¡Ketc.
 * De-initialize control structures
 */
static VIDEO_ERROR_TYPE_T _MP4_MuxerAdapterDeInit(void)
{
    drv_trace0(TRACE_GROUP_10, MUX_MP4AL_DEINIT);

    if (_rMP4ALMgr.eScenario == MUXER_SCENARIO_RECORD)
    {
        MP4_DeInitMeta(KAL_TRUE);
    }
    else
    {
        MP4_DeInitMeta(KAL_FALSE);
    }
    _MP4_CloseTempFiles();
    _MP4_DumpInfo();

    return VIDEO_ERROR_NONE;
}


/**
 *
 */
static VIDEO_ERROR_TYPE_T _MP4_MuxerAdapterClose(void)
{
    MuxerAdaptFreeMemory(_rMP4ALMgr.pau2FilePath);
    MuxerAdaptFreeMemory(_rMP4ALMgr.pau2WorkingPath);
    return VIDEO_ERROR_NONE;
}


static const MUXER_ADAPT_API_T _MP4AdapterAPI =
{
    _MP4_MuxerAdapterOpen,
    _MP4_MuxerAdapterInit,
    _MP4_MuxerAdapterGetParam,
    _MP4_MuxerAdapterSetParam,
    _MP4_MuxerAdapterDirectlyGetParam,
    _MP4_MuxerAdapterDirectlySetParam,
    _MP4_MuxerAdapterProcessData,
    _MP4_MuxerAdapterWriteData2File,
    _MP4_MuxerAdapterCreateFile,
    _MP4_MuxerAdapterDeInit,
    _MP4_MuxerAdapterClose
};

MUXER_ADAPT_API_T* MP4MuxerAdapterGetHandle(void)
{
    return (MUXER_ADAPT_API_T* )&_MP4AdapterAPI;
}

#endif  // __VE_SUPPORT_MP4_MUXER_ADAPTER__
#endif  // __VE_VIDEO_ARCHI_V2__

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

