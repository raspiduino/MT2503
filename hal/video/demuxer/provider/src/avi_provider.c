/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2007
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
 *   avi_media_provider.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"

#if defined(__VE_SP_AVI__)

#include "kal_general_types.h"
#include "fs_type.h"
#include "fsal.h"
#include "source_provider_if.h"
#include "vcodec_v2_trc.h"
#include "avi_provider.h"
#include "SwDecodeFrameHeader.h"
//#include "video_codec_parser_utility_v2.h"
//#include "drm_gprot.h"

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VEDEC_ROCODE", rodata = "DYNAMIC_CODE_VEDEC_RODATA"
#endif

#define AVI_SP_READ_DATA(prFsal, pu1Buf, u4size)  \
do{                                               \
  eFsalRet = FSAL_Read(prFsal, pu1Buf, u4size);   \
  if (eFsalRet != FSAL_OK)                        \
  {                                               \
      goto FILE_READ_ERROR;                       \
  }                                               \
} while(0);   

static kal_bool _AviPaserCheckTag(kal_uint8 *pu1Str1, kal_uint8 *pu1Str2)
{
    //kal_uint32 *pu4Str1, *pu4Str2;

    //pu4Str1 = (kal_uint32 *)pu1Str1;
    //pu4Str2 = (kal_uint32 *)pu1Str2;

    if (strncmp((char*)pu1Str1, (char*)pu1Str2, 4) == 0)
    //if (*pu4Str1 == *pu4Str2)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }   
}

static kal_bool _AviPaserCheckSize(kal_uint8 *pu1Str1, kal_uint32 u4Size)
{
    kal_uint32 *pu4Str1;

    pu4Str1 = (kal_uint32 *)pu1Str1;
    
    if (*pu4Str1 == u4Size)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }   
}


static PROVIDER_ERROR_T _AviPaserReadData(STFSAL *prFsal, kal_uint8 *pu1Buf, kal_uint32 u4Size)
{
    FSAL_Status eRet;
    
    eRet = FSAL_Read(prFsal, pu1Buf, u4Size);

    if (eRet != FSAL_OK)
    { 
        AVI_SP_TRACE_FSAL_ERROR(eRet);         
        return PROVIDER_ERROR;
    }

    return PROVIDER_ERROR_NONE;
}

static PROVIDER_ERROR_T _AviParserCurrentPos(STFSAL *prFsal, kal_uint32 *pu4FilePos)
{
    FSAL_Status eRet;
    
    eRet = FSAL_GetCurPos(prFsal, pu4FilePos);

    if (eRet != FSAL_OK)
    {
        AVI_SP_TRACE_FSAL_ERROR(eRet);    
        return PROVIDER_ERROR; 
    }     

    return PROVIDER_ERROR_NONE;
}

/*
static kal_uint32 _AviParserGetNextChunk(STFSAL *prFsal, kal_uint8 *pu1SkipSize)
{
    kal_uint32 u4SkipSize;
    kal_uint32 u4FilePos;

    u4SkipSize = *((kal_uint32 *)pu1SkipSize);
    
    u4FilePos = _AviParserCurrentPos(prFsal);

    return u4SkipSize + u4FilePos;
}*/

static kal_bool _AviParserSkipFileSize(STFSAL *prFsal, kal_uint32 u4SkipSize, kal_uint32 u4FileSize)
{
    FSAL_Status eRet;

    if (u4SkipSize>=u4FileSize)
    {
        AVI_SP_TRACE_WARNING(u4SkipSize, u4FileSize, 0);
        return KAL_FALSE; // means that file end
    }

    eRet = FSAL_Seek(prFsal, u4SkipSize);

    if (eRet != FSAL_OK)
    {
        AVI_SP_TRACE_FSAL_ERROR(eRet);     
        return KAL_FALSE; 
    }   

    return KAL_TRUE;
}

static kal_uint64 _AviParserFrameToTime(kal_uint32 u4Frame, kal_uint32 u4Scale, kal_uint32 u4Rate)
{
    return (((kal_uint64)u4Frame * 1000 * u4Scale + u4Rate - 1) / u4Rate);
}

static kal_uint32 _AviParserTimeToFrame(kal_uint64 u8Time, kal_uint32 u4Scale, kal_uint32 u4Rate)
{
    return ((kal_uint32)(u8Time * u4Rate / u4Scale / 1000));
}

static kal_uint32 _AviParserTimeToSize(kal_uint64 u8Time, kal_uint32 u4AvgBytePerSec)
{
    return ((kal_uint32)(u8Time * u4AvgBytePerSec / 1000));
}

static kal_uint64 _AviParserSizeToTime(kal_uint32 u4Size,  kal_uint32 u4AvgBytePerSec)
{
    return (((kal_uint64)u4Size * 1000 + u4AvgBytePerSec - 1) /  u4AvgBytePerSec);
}

#ifdef __VE_SP_AVI_NON_IDX1_PLAYBACK__ 
static kal_uint32 _AviParserReadFourByte(kal_uint8 *pu1Addr)
{
    return (((kal_uint32)*pu1Addr) | ((kal_uint32)*(pu1Addr+1)<<8) | ((kal_uint32)*(pu1Addr+2)<<16) | ((kal_uint32)*(pu1Addr+3)<<24));
}
#endif

static kal_uint32  _AviParserRoundUpToPowerOfTwo(kal_uint32 u4Data, kal_uint32 u4N) 
{
    return (u4Data & ~(u4N - 1));
}

static media_codec_type_t _AviParserCheckVideoCodec(kal_uint32 u4Fourcc)
{
    kal_uint8 *pu1Byte;
    kal_int32 i; 
    
    pu1Byte = (kal_uint8*)&u4Fourcc;
    
    for(i = 0; i < 4; i++) 
    {                          
        if (pu1Byte[i] >= 'a')  
        {          
           pu1Byte[i] += 'A' - 'a';  
        }    
    }        

#ifdef  __VE_MJPEG_DEC_SW_SUPPORT__
    if (_AviPaserCheckTag(pu1Byte, AVI_SP_TAG_MJPG))
    {
        return MEDIA_CODEC_VID_MJPG;
    }
#endif    

#if defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__)
    if (_AviPaserCheckTag(pu1Byte, AVI_SP_TAG_H263) ||
        _AviPaserCheckTag(pu1Byte, AVI_SP_TAG_S263)
       )
    {
        return MEDIA_CODEC_VID_H263;
    }
    
    if (_AviPaserCheckTag(pu1Byte, AVI_SP_TAG_MP4V) ||
        _AviPaserCheckTag(pu1Byte, AVI_SP_TAG_XVID) ||
        _AviPaserCheckTag(pu1Byte, AVI_SP_TAG_DX50) ||
        _AviPaserCheckTag(pu1Byte, AVI_SP_TAG_DIVX) ||
        _AviPaserCheckTag(pu1Byte, AVI_SP_TAG_DIV5) ||
        _AviPaserCheckTag(pu1Byte, AVI_SP_TAG_3IVX) ||
        _AviPaserCheckTag(pu1Byte, AVI_SP_TAG_3IV2) ||
        _AviPaserCheckTag(pu1Byte, AVI_SP_TAG_RMP4) ||
        _AviPaserCheckTag(pu1Byte, AVI_SP_TAG_FMP4) 
       )
    {
        return MEDIA_CODEC_VID_MPEG4;
    }
#endif

#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    if (_AviPaserCheckTag(pu1Byte, AVI_SP_TAG_AVC1) ||
        _AviPaserCheckTag(pu1Byte, AVI_SP_TAG_DAVC) ||
        _AviPaserCheckTag(pu1Byte, AVI_SP_TAG_H264) ||
        _AviPaserCheckTag(pu1Byte, AVI_SP_TAG_X264)
       )
    {
        return MEDIA_CODEC_VID_H264;
    }
#endif

    return MEDIA_CODEC_NONE;
}

static media_codec_type_t _AviParserCheckAudioCodec(kal_uint16 u2Handle)
{
    if (u2Handle == AVI_SP_AUD_FORMAT_WAV_PCM)
    {
        return MEDIA_CODEC_AUD_PCM;
    }

    if (u2Handle == AVI_SP_AUD_FORMAT_MPEGLAYER3)
    {
        return MEDIA_CODEC_AUD_MPEGLAYER3;
    }    

#ifdef AAC_DECODE
    if (u2Handle == AVI_SP_AUD_FORMAT_FAAD_AAC ||
        u2Handle == AVI_SP_AUD_FORMAT_HDX4_AAC ||
        u2Handle == AVI_SP_AUD_FORMAT_MPEG2AAC ||        
        u2Handle == AVI_SP_AUD_FORMAT_AAC ||        
        u2Handle == AVI_SP_AUD_FORMAT_AAC2     
       )
    {
        return MEDIA_CODEC_AUD_AAC;
    }
#endif

#ifdef AMRWB_DECODE 
    if (u2Handle == AVI_SP_AUD_FORMAT_AMR_WB)
    {
        return MEDIA_CODEC_AUD_AMR_WB;
    }
#endif 

#ifdef AMR_CODEC
    if (u2Handle == AVI_SP_AUD_FORMAT_AMR_CBR ||  
        u2Handle == AVI_SP_AUD_FORMAT_AMR_VBR     
       )
    {
        return MEDIA_CODEC_AUD_AMR;
    }
#endif

#ifdef MUSICAM_DECODE
    if (u2Handle == AVI_SP_AUD_FORMAT_MPEG)
    {
        return MEDIA_CODEC_AUD_MPEG;
    }
#endif

    return MEDIA_CODEC_NONE;
}

static kal_uint32 _AviParserGetStreamNumber(kal_uint32 u4ChunkId)
{
    return ((((u4ChunkId & 0xFF) - 0x30) * 10) + 
            (((u4ChunkId & 0xFF00) >> 8) - 0x30));
}

static kal_uint64 _AviParserRefTiem2RealTime(SP_PORT_TYPE_T ePort, AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, kal_uint32 u4RefTime)
{
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    AVI_SP_STREAM_HEADER_T *prStreamHeader;
    kal_uint64 u8RealTime;
    kal_uint32 u4SelectNum;
    
    if (ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        prStreamHeader = &prParser->rVidStreamHdr[prAviProviderMgr->rVideoUserSetting.u4SelectNum];
        u8RealTime = _AviParserFrameToTime(u4RefTime, prStreamHeader->scale, prStreamHeader->rate);
    }
    else // Audio
    {
        u4SelectNum = prAviProviderMgr->rAudioUserSetting.u4SelectNum;
        prStreamHeader = &prParser->rAudStreamHdr[u4SelectNum];
        if (prStreamHeader->sample_size == 0)//VBR
        {
            u8RealTime = _AviParserFrameToTime(u4RefTime, prStreamHeader->scale, prStreamHeader->rate);
        }
        else
        {
            u8RealTime = _AviParserSizeToTime(u4RefTime, prParser->rAudFormatHdr[u4SelectNum].avg_byte_per_sec);
        }
    } 

    return u8RealTime;
}

static kal_uint32 _AviParserRealTiem2RefTime(SP_PORT_TYPE_T ePort, AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, kal_uint64 u8RealTime)
{
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    AVI_SP_STREAM_HEADER_T *prStreamHeader;
    kal_uint32 u4RefTime;
    kal_uint32 u4SelectNum;
    
    if (ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        prStreamHeader = &prParser->rVidStreamHdr[prAviProviderMgr->rVideoUserSetting.u4SelectNum];
        u4RefTime = _AviParserTimeToFrame(u8RealTime, prStreamHeader->scale, prStreamHeader->rate); 
    }
    else // Audio
    {
        u4SelectNum = prAviProviderMgr->rAudioUserSetting.u4SelectNum;
        prStreamHeader = &prParser->rAudStreamHdr[u4SelectNum];

        if (prStreamHeader->sample_size == 0) //VBR
        {
            u4RefTime = _AviParserTimeToFrame(u8RealTime, prStreamHeader->scale, prStreamHeader->rate); 
        }
        else
        {
            u4RefTime = _AviParserTimeToSize(u8RealTime, prParser->rAudFormatHdr[u4SelectNum].avg_byte_per_sec);
        }
    } 

    return u4RefTime;
}

static kal_bool _AviParserIsVideoKeyFrame(kal_uint32 u4Flag, SPIF_VIDEO_STREAM_INFO_T *prVideoStreamInfo)
{
    if (prVideoStreamInfo == NULL)
    {
        return (kal_bool)((u4Flag & AVI_SP_IF_KEY_FRAME) != 0);
    }
    else
    {
        return (kal_bool)((u4Flag & AVI_SP_IF_KEY_FRAME) != 0 || (prVideoStreamInfo->eCodecType == MEDIA_CODEC_VID_MJPG));
    }
}

/*
static void _AviParserIdx1MgrInit(AVI_SP_INDEX_T *prIndexEntry)
{
    AVI_SP_PARSER_INFO_T *prParser;
    
    // seek to start address
    _AviParserSkipFileSize(prIndexEntry->prFsal, prIndexEntry->u4EntryOffset , prIndexEntry->u4FileSize);
    prIndexEntry->u4CurrentRefTime;
    
}*/

static kal_bool _AviParserIdx1MgrGetNextIndex(AVI_SP_IDX1_MGR_T *prIdx1Mgr, AVI_SP_INDEX_T *prIndexEntry)
{     
    kal_uint32 u4CurrentStreamNum;

    while (prIdx1Mgr->u4EntryOffset<prIdx1Mgr->u4IndexEndAddr)
    {
        if (PROVIDER_ERROR_NONE != _AviParserCurrentPos(prIdx1Mgr->prFsal, &prIdx1Mgr->u4EntryOffset))
        {
            return KAL_FALSE;
        }
        if (PROVIDER_ERROR_NONE != _AviPaserReadData(prIdx1Mgr->prFsal, (kal_uint8 *)prIndexEntry, sizeof(AVI_SP_INDEX_T)))
        {
            return KAL_FALSE;
        }
        
        u4CurrentStreamNum = _AviParserGetStreamNumber(prIndexEntry->u4ChunkId);    
        
        if (u4CurrentStreamNum == prIdx1Mgr->u4StreamNum)
        {           
            prIdx1Mgr->u4CurrentRefTime = prIdx1Mgr->u4CurrentRefEndTime;
            if (prIdx1Mgr->fgVBR == KAL_TRUE) //VBR
            {
                prIdx1Mgr->u4CurrentRefEndTime += 1;                
            }
            else
            {
                prIdx1Mgr->u4CurrentRefEndTime += prIndexEntry->u4ChunkLength;
            }

            if (prIndexEntry->u4ChunkLength != 0)
            {
                prIndexEntry->u4ChunkOffset += prIdx1Mgr->u4AdjustSize;
                return KAL_TRUE;
            }
        }        
    } 
    
    return KAL_FALSE;
}

static kal_uint32 _AviParserSearchEntry(AVI_SP_VBR_ENTRY_T *prEntry, kal_uint32 u4SearchRefTime, kal_uint32 u4Start, kal_uint32 u4End)
{
    kal_uint32 u4Mid = (u4Start + u4End)/2;

    if (prEntry[u4Mid].u4ChunkIdx == u4SearchRefTime)
    {
        return u4Mid;
    }
    
    if (u4Start+1 >= u4End)
    {
       if (prEntry[u4End].u4ChunkIdx <= u4SearchRefTime)
       {
           return u4End;
       }
       else
       {
           return u4Start;
       }
    }
    
    if (prEntry[u4Mid].u4ChunkIdx < u4SearchRefTime)
    {
        return _AviParserSearchEntry(prEntry, u4SearchRefTime, u4Mid, u4End);
    }
    else
    {
        return _AviParserSearchEntry(prEntry, u4SearchRefTime, u4Start, u4Mid);
    }
}

static void _AviParserAddSeekTable(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, AVI_SP_SEEK_TABLE_T *prSeekTable, kal_uint32 u4Duration, kal_uint32 u4Addr)
{
    AVI_SP_SRC_HANDLE_T *prSrcHandle = &prAviProviderMgr->rSrcHandle;
    AVI_SP_VBR_ENTRY_T *prStartEntry = (AVI_SP_VBR_ENTRY_T *)prSeekTable->pvEntry;
    AVI_SP_VBR_ENTRY_T *prEntry = prStartEntry+prSeekTable->u4NumEntries;
    SP_API_T *prSrcAPI = prSrcHandle->prSourceAPI; 
    kal_uint32 u4I, u4New;

    if((prSeekTable->u4Counter % prSeekTable->u4Granularity) != 0)
    {
        prSeekTable->u4Counter++;
        prSeekTable->u4RangeRefEndTime += u4Duration;
        return;
    }

    prEntry->u4ChunkIdx = prSeekTable->u4RangeRefEndTime;
    prEntry->u4Offset = u4Addr;
    prSeekTable->u4NumEntries++;
    prSeekTable->u4Counter++;
    prSeekTable->u4RangeRefEndTime += u4Duration;

    // compress table
    if (prSeekTable->u4NumEntries == prSeekTable->u4MaxEntries)
    {        
        u4New = 1;
        for (u4I=2; u4I<prSeekTable->u4MaxEntries; u4I+=2)
        {
            prSrcAPI->SPFN_MEM_COPY((void *)(prStartEntry+u4New), 
                                                                               (void *)(prStartEntry+u4I), sizeof(AVI_SP_VBR_ENTRY_T));
            u4New++;
        }
        prSeekTable->u4NumEntries = u4New;
        prSeekTable->u4Granularity = prSeekTable->u4Granularity*2;
    }
}

static void _AviParserBuildSeekTableIdx1(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, SP_PORT_TYPE_T eType, kal_uint32 u4TargetRefTime)
{
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    AVI_SP_FILE_T *prFile = &prAviProviderMgr->rFile;
    AVI_SP_MEM_INFO_T *prMemInfo = &prAviProviderMgr->rMemInfo;
    AVI_SP_INDEX_T *prIndex = (AVI_SP_INDEX_T *)prMemInfo->pu1TempBuf;

    kal_bool fgAudioEnable, fgVideoEnable;
    kal_uint32 u4Duration, u4SeekAddr;
    kal_uint32 u4AudioSelectNum = 0, u4AudioStreamIdx = 0, u4AudioSeekAddr = AVI_SP_FOUR_BYTE_MAX_VALUE;
    kal_uint32 u4VideoSelectNum = 0, u4VideoStreamIdx = 0, u4VideoSeekAddr = AVI_SP_FOUR_BYTE_MAX_VALUE;
    AVI_SP_STREAM_HEADER_T *prAudioStreamHdr = NULL;
    AVI_SP_SEEK_TABLE_T *prAudioSeekTable = NULL, *prVideoSeekTable = NULL;
    kal_uint32 u4Num, u4Type;    
    kal_uint32 u4CurrentRefTime = 0;
    SPIF_VIDEO_STREAM_INFO_T *prVideoStreamInfo = NULL;
        
    // load audio and video info
    fgAudioEnable = prAviProviderMgr->rAudioUserSetting.fgEnable;
    fgVideoEnable = prAviProviderMgr->rVideoUserSetting.fgEnable;
    
    if (fgAudioEnable == KAL_TRUE)
    {
        u4AudioSelectNum = prAviProviderMgr->rAudioUserSetting.u4SelectNum;
        u4AudioStreamIdx = prParser->rAudioInfo[u4AudioSelectNum].u4StreamIndex;
        prAudioStreamHdr = &prParser->rAudStreamHdr[u4AudioSelectNum];
        prAudioSeekTable = &prParser->rAudioSeekTable;
        u4AudioSeekAddr = prAudioSeekTable->u4LastFileAddr;
    }
    
    if (fgVideoEnable == KAL_TRUE)
    {
        u4VideoSelectNum = prAviProviderMgr->rVideoUserSetting.u4SelectNum;
        prVideoStreamInfo = &prParser->rVideoInfo[u4VideoSelectNum]; 
        u4VideoStreamIdx = prVideoStreamInfo->u4StreamIndex;
        prVideoSeekTable = &prParser->rVideoSeekTable;
        u4VideoSeekAddr = prVideoSeekTable->u4LastFileAddr;
    }

    if (u4AudioSeekAddr > u4VideoSeekAddr)
    {
        u4SeekAddr = u4VideoSeekAddr;
    }
    else
    {
        u4SeekAddr = u4AudioSeekAddr;
    }

    if (_AviParserSkipFileSize(&prFile->rFsalFileInfo, u4SeekAddr, prAviProviderMgr->rOpenInfo.u4DataSize) == KAL_FALSE)
    {
        // seek to file end
        return ;
    }

    while (u4CurrentRefTime <= u4TargetRefTime && u4SeekAddr<prParser->u4IndexEndAddr && prParser->fgAbort[eType] == KAL_FALSE)
    {            
        if (PROVIDER_ERROR_NONE != _AviPaserReadData(&prFile->rFsalFileInfo, prMemInfo->pu1TempBuf, sizeof(AVI_SP_INDEX_T)))
        {            
            break;
        }

        u4Num = _AviParserGetStreamNumber(prIndex->u4ChunkId);
        u4Type = prIndex->u4ChunkId & 0xffff0000;        
    
        // audio chunk
        if (fgAudioEnable == KAL_TRUE && 
             u4Num == u4AudioStreamIdx &&
             u4Type ==AVI_SP_TAG_XXWB_STREAM_TYPE &&
             u4SeekAddr >= u4AudioSeekAddr
           )
        {         
            if (prAudioStreamHdr->sample_size == 0) //VBR
            {
                u4Duration = 1;
                
            }
            else
            {
                u4Duration = prIndex->u4ChunkLength;
            }

            if (eType == SOURCE_PROVIDER_PORT_AUDIO)
            {
                u4CurrentRefTime = prAudioSeekTable->u4RangeRefEndTime;
            }
            
            // 
            _AviParserAddSeekTable(prAviProviderMgr, prAudioSeekTable, u4Duration, u4SeekAddr);            
        }
        else if (fgVideoEnable == KAL_TRUE && 
                    u4Num == u4VideoStreamIdx &&
                    (u4Type ==AVI_SP_TAG_XXDB_STREAM_TYPE || u4Type ==AVI_SP_TAG_XXDC_STREAM_TYPE)&&
                    u4SeekAddr >= u4VideoSeekAddr
                   )
        {
            // add to table
            if (_AviParserIsVideoKeyFrame(prIndex->u4Flag, prVideoStreamInfo) == KAL_TRUE)
            {
                if (eType == SOURCE_PROVIDER_PORT_VIDEO)
                {
                    u4CurrentRefTime = prVideoSeekTable->u4RangeRefEndTime;
                }
                _AviParserAddSeekTable(prAviProviderMgr, prVideoSeekTable, 1, u4SeekAddr);    
            }
            else
            {
                prVideoSeekTable->u4RangeRefEndTime += 1;
            }
        }

        if (prParser->u4IndexAddr == u4SeekAddr)
        {
            if (prIndex->u4ChunkOffset > prParser->u4MoviAddr)
            {
                prParser->u4MoviOffset = 0;
            }
            else
            {
                prParser->u4MoviOffset = prParser->u4MoviAddr;
            }
        }
        
        if (PROVIDER_ERROR_NONE != _AviParserCurrentPos(&prFile->rFsalFileInfo, &u4SeekAddr))
        {
            break;
        }
    }

    if (fgAudioEnable == KAL_TRUE)
    {
        if (prAudioSeekTable->u4LastFileAddr < u4SeekAddr)
        {
            prAudioSeekTable->u4LastFileAddr = u4SeekAddr;
         }
    }

    if (fgVideoEnable == KAL_TRUE)
    {
        if (prVideoSeekTable->u4LastFileAddr < u4SeekAddr)
        {
            prVideoSeekTable->u4LastFileAddr = u4SeekAddr;
        }
    }
}

static AVI_SP_VBR_ENTRY_T _AviParserSearchKeyFrameIdx1(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr,SP_SEARCH_DIR_T eDirect, SP_PORT_TYPE_T eType, kal_uint64 u8StartTime)
{  
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    AVI_SP_FILE_T *prFile = &prAviProviderMgr->rFile;
    SPIF_VIDEO_STREAM_INFO_T *prVideoStreamInfo = NULL;
    
    kal_uint32 u4EntryIdx, u4SearchRefTime;
    AVI_SP_VBR_ENTRY_T rTargetEnty = {0, 0};
    AVI_SP_VBR_ENTRY_T *prEntry;
    kal_uint32 u4SelectNum, u4StreamIndex;
    AVI_SP_SEEK_TABLE_T *prSeekTable;
    kal_bool fgChkKeyFrame;
    kal_bool fgVBR;

    if (eType == SOURCE_PROVIDER_PORT_VIDEO)
    {
        u4SelectNum = prAviProviderMgr->rVideoUserSetting.u4SelectNum;
        prVideoStreamInfo = &prParser->rVideoInfo[u4SelectNum];
        u4StreamIndex= prVideoStreamInfo->u4StreamIndex;
        prSeekTable = &prParser->rVideoSeekTable;
        fgChkKeyFrame = KAL_TRUE;
        fgVBR = KAL_TRUE;                             
    }
    else
    {
        u4SelectNum = prAviProviderMgr->rAudioUserSetting.u4SelectNum;
        u4StreamIndex= prParser->rAudioInfo[u4SelectNum].u4StreamIndex;
        prSeekTable = &prParser->rAudioSeekTable;        
        fgChkKeyFrame = KAL_FALSE;    

        if (prParser->rAudStreamHdr[u4SelectNum].sample_size == 0) //VBR
        {
            fgVBR = KAL_TRUE;
        }
        else
        {
            fgVBR = KAL_FALSE;
        }
    }

    u4SearchRefTime = _AviParserRealTiem2RefTime(eType, prAviProviderMgr, u8StartTime);

    if (eDirect == SOURCE_PROVIDER_SEARCH_FORWARD)
    {
        ASSERT(0);
    }
    
    // build table if out of region
    if (prSeekTable->u4RangeRefEndTime < u4SearchRefTime || prSeekTable->u4NumEntries == 0)
    {
        _AviParserBuildSeekTableIdx1(prAviProviderMgr, eType, u4SearchRefTime);
    }

    prEntry = (AVI_SP_VBR_ENTRY_T *)prSeekTable->pvEntry;

    // search in table
    if (prSeekTable->u4NumEntries != 0)
    {        
        u4EntryIdx = _AviParserSearchEntry(prEntry, u4SearchRefTime, 0, prSeekTable->u4NumEntries-1);
    }
    else
    {
        return rTargetEnty;
    }    

    prEntry = &prEntry[u4EntryIdx];   
    rTargetEnty.u4ChunkIdx = prEntry->u4ChunkIdx;
    rTargetEnty.u4Offset = prEntry->u4Offset;

    // check granularity
    if (prSeekTable->u4Granularity != 1)
    {
        AVI_SP_IDX1_MGR_T rIdx1Mgr;
        AVI_SP_INDEX_T rIndexEntry;
        kal_bool bRet;

        rIdx1Mgr.prFsal = &prFile->rFsalFileInfo;
        rIdx1Mgr.fgVBR = fgVBR;
        rIdx1Mgr.u4StreamNum = u4StreamIndex;
        rIdx1Mgr.u4EntryOffset = prEntry->u4Offset;
        rIdx1Mgr.u4CurrentRefTime = prEntry->u4ChunkIdx;
        rIdx1Mgr.u4CurrentRefEndTime = rIdx1Mgr.u4CurrentRefTime;
        rIdx1Mgr.u4IndexEndAddr= prParser->u4IndexEndAddr;
        rIdx1Mgr.u4AdjustSize = 0;

        // seek
        if (_AviParserSkipFileSize(rIdx1Mgr.prFsal, rIdx1Mgr.u4EntryOffset , prAviProviderMgr->rOpenInfo.u4DataSize) == KAL_FALSE)
        {   
            return rTargetEnty;
        }

        do{
            bRet =  _AviParserIdx1MgrGetNextIndex(&rIdx1Mgr, &rIndexEntry);

            if ((bRet == KAL_TRUE) &&
                ((fgChkKeyFrame == KAL_FALSE) || _AviParserIsVideoKeyFrame(rIndexEntry.u4Flag, prVideoStreamInfo) != 0))
            {   
                if (rIdx1Mgr.u4CurrentRefTime > u4SearchRefTime)
                {
                    break;
                }
                rTargetEnty.u4ChunkIdx = rIdx1Mgr.u4CurrentRefTime;
                rTargetEnty.u4Offset = rIdx1Mgr.u4EntryOffset;
            }
        } while (bRet == KAL_TRUE);
    }

    return rTargetEnty;
}

#ifdef __VE_SP_AVI_NON_IDX1_PLAYBACK__  
static AVI_SP_FRAME_TYPE_T _AviParserGetVideoFrameType(media_codec_type_t eCodec, kal_uint8 *pu1Buf, kal_uint32 u4Size)
{
    AVI_SP_FRAME_TYPE_T eRet = AVI_SP_FRAME_TYPE_UNKNOWN;
    VCODEC_DEC_FRAME_HDR_INPUT_T rInput; 
    VCODEC_DEC_FRAME_HDR_INFO_T rOutput;
    kal_bool fgTransfer = KAL_FALSE;

    rInput.eFlags = INPUT_FLAG_FRAME_TYPE;
    rInput.pByteStrm = pu1Buf;
    rInput.u4Len = u4Size;
    
    switch (eCodec)
    {
#ifdef  __VE_MJPEG_DEC_SW_SUPPORT__    
    case MEDIA_CODEC_VID_MJPG:
        eRet = AVI_SP_FRAME_TYPE_I;
        break;
#endif        
        
#if defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__)        
    case MEDIA_CODEC_VID_H263:
        {
            if (H263SwDecDecodeFrameHeader(&rInput, &rOutput) == VCODEC_DEC_FRAME_HDR_OK)
            {
                fgTransfer = KAL_TRUE;
            }
            else
            {
                ASSERT(0);
            }
        }
        break;

    case MEDIA_CODEC_VID_MPEG4:
        {
            if (MP4SwDecDecodeFrameHeader(&rInput, &rOutput) == VCODEC_DEC_FRAME_HDR_OK)
            {
                fgTransfer = KAL_TRUE;
            }
            else
            {
                ASSERT(0);
            }
        }
        break; 
#endif        

#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    case MEDIA_CODEC_VID_H264:
        {
            if (H264SwDecDecodeFrameHeader(&rInput, &rOutput) == VCODEC_DEC_FRAME_HDR_OK)
            {
                fgTransfer = KAL_TRUE;
            }
            else
            {
                ASSERT(0);
            }
        }
        break;        
#endif        

    default:
        ASSERT(0);
        eRet =   AVI_SP_FRAME_TYPE_UNKNOWN;
        break;
    }

    if (fgTransfer == KAL_TRUE)
    {
        if (rOutput.eFrameType == VCODEC_PIC_FRAMETYPE_I)
        {
            eRet = AVI_SP_FRAME_TYPE_I;
        }
    }

    return eRet;
}

static void _AviParserBuildSeekTableNoIdx1(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, SP_PORT_TYPE_T eType, kal_uint32 u4TargetRefTime)
{
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    AVI_SP_FILE_T *prFile = &prAviProviderMgr->rFile;
    AVI_SP_MEM_INFO_T *prMemInfo = &prAviProviderMgr->rMemInfo;

    kal_bool fgAudioEnable, fgVideoEnable;
    kal_uint32 u4ReadSize, u4Duration, u4SeekAddr;
    kal_uint32 u4AudioSelectNum = 0, u4AudioStreamIdx = 0, u4AudioSeekAddr = AVI_SP_FOUR_BYTE_MAX_VALUE;
    kal_uint32 u4VideoSelectNum = 0, u4VideoStreamIdx = 0, u4VideoSeekAddr = AVI_SP_FOUR_BYTE_MAX_VALUE;
    AVI_SP_STREAM_HEADER_T *prAudioStreamHdr = NULL;
    AVI_SP_SEEK_TABLE_T *prAudioSeekTable = NULL, *prVideoSeekTable = NULL;
    kal_uint32 u4Num, u4Type, u4Size;    
    kal_uint32 u4CurrentRefTime = 0;
        
    // load audio and video info
    fgAudioEnable = prAviProviderMgr->rAudioUserSetting.fgEnable;
    fgVideoEnable = prAviProviderMgr->rVideoUserSetting.fgEnable;
    
    if (fgAudioEnable == KAL_TRUE)
    {
        u4AudioSelectNum = prAviProviderMgr->rAudioUserSetting.u4SelectNum;
        u4AudioStreamIdx = prParser->rAudioInfo[u4AudioSelectNum].u4StreamIndex;
        prAudioStreamHdr = &prParser->rAudStreamHdr[u4AudioSelectNum];
        prAudioSeekTable = &prParser->rAudioSeekTable;
        u4AudioSeekAddr = prAudioSeekTable->u4LastFileAddr;
    }
    
    if (fgVideoEnable == KAL_TRUE)
    {
        u4VideoSelectNum = prAviProviderMgr->rVideoUserSetting.u4SelectNum;
        u4VideoStreamIdx = prParser->rVideoInfo[u4VideoSelectNum].u4StreamIndex;
        prVideoSeekTable = &prParser->rVideoSeekTable;
        u4VideoSeekAddr = prVideoSeekTable->u4LastFileAddr;
    }

    if (u4AudioSeekAddr > u4VideoSeekAddr)
    {
        u4SeekAddr = u4VideoSeekAddr;
    }
    else
    {
        u4SeekAddr = u4AudioSeekAddr;
    }

    while (u4CurrentRefTime <= u4TargetRefTime && prParser->fgAbort[eType] == KAL_FALSE)
    {
        if (_AviParserSkipFileSize(&prFile->rFsalFileInfo, u4SeekAddr, prAviProviderMgr->rOpenInfo.u4DataSize) == KAL_FALSE)
        {
            //return ;
            break;
        }
    
        // get "xxss size" of chunk
        if (PROVIDER_ERROR_NONE != _AviPaserReadData(&prFile->rFsalFileInfo, prMemInfo->pu1TempBuf, 8))
        {
            break;
        }
        u4Size = *(kal_uint32 *)prMemInfo->pu1TempBuf;
        u4Num = _AviParserGetStreamNumber(u4Size);
        u4Type = u4Size & AVI_SP_MASK_HIGH_TWO_BYTE;
        
        u4Size = *(kal_uint32 *)(prMemInfo->pu1TempBuf+4);
        u4Size = (u4Size + 1) & (0xfffffffe);
    
        // audio chunk
        if (fgAudioEnable == KAL_TRUE && 
             u4Num == u4AudioStreamIdx &&
             u4Type ==AVI_SP_TAG_XXWB_STREAM_TYPE &&
             u4SeekAddr >= u4AudioSeekAddr
           )
        {         
            if (prAudioStreamHdr->sample_size == 0) //VBR
            {
                u4Duration = 1;
                
            }
            else
            {
                u4Duration = u4Size;
            }

            if (eType == SOURCE_PROVIDER_PORT_AUDIO)
            {
                u4CurrentRefTime = prAudioSeekTable->u4RangeRefEndTime;
            }
            
            // 
            _AviParserAddSeekTable(prAviProviderMgr, prAudioSeekTable, u4Duration, u4SeekAddr);            
        }
        else if (fgVideoEnable == KAL_TRUE && 
                    u4Num == u4VideoStreamIdx &&
                    (u4Type ==AVI_SP_TAG_XXDB_STREAM_TYPE || u4Type ==AVI_SP_TAG_XXDC_STREAM_TYPE)&&
                    u4SeekAddr >= u4VideoSeekAddr
                   )
        {
            if (u4Size != 0)
            {
                // decide read size
                if (u4Size > AVI_SP_TEMP_BUF)
                {
                    u4ReadSize = AVI_SP_TEMP_BUF;
                }
                else
                {
                    u4ReadSize = u4Size;
                }
                
                // read partial data
                if (PROVIDER_ERROR_NONE != _AviPaserReadData(&prFile->rFsalFileInfo, prMemInfo->pu1TempBuf, u4ReadSize))
                {
                    break;
                }
    
                // add to table
                if (_AviParserGetVideoFrameType(prParser->rVideoInfo[u4VideoSelectNum].eCodecType, prMemInfo->pu1TempBuf, u4ReadSize) == AVI_SP_FRAME_TYPE_I)
                {
                    if (eType == SOURCE_PROVIDER_PORT_VIDEO)
                    {
                        u4CurrentRefTime = prVideoSeekTable->u4RangeRefEndTime;
                    }
                    _AviParserAddSeekTable(prAviProviderMgr, prVideoSeekTable, 1, u4SeekAddr);    
                }
                else
                {
                    prVideoSeekTable->u4RangeRefEndTime += 1;
                }
            }
            else
            {
                prVideoSeekTable->u4RangeRefEndTime += 1;
            }
        }
        else
        {
            u4ReadSize = 0;
        }
    
        u4SeekAddr = u4SeekAddr + 8 + u4Size;
    }

    if (fgAudioEnable == KAL_TRUE)
    {
        if (prAudioSeekTable->u4LastFileAddr < u4SeekAddr)
        {
            prAudioSeekTable->u4LastFileAddr = u4SeekAddr;
         }
    }

    if (fgVideoEnable == KAL_TRUE)
    {
        if (prVideoSeekTable->u4LastFileAddr < u4SeekAddr)
        {
            prVideoSeekTable->u4LastFileAddr = u4SeekAddr;
        }
    }
}

static AVI_SP_VBR_ENTRY_T _AviParserSearchKeyFrameNoIdx1(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, SP_SEARCH_DIR_T eDirect, SP_PORT_TYPE_T eType, kal_uint64 u8StartTime)
{
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;

    AVI_SP_VBR_ENTRY_T rTargetEnty;
    AVI_SP_SEEK_TABLE_T *prSeekTable;    
    AVI_SP_VBR_ENTRY_T *prEntry;
    kal_uint32 u4SearchRefTime;
    kal_uint32 u4EntryIdx;    

    if (eType == SOURCE_PROVIDER_PORT_VIDEO)
    {
        prSeekTable = &prParser->rVideoSeekTable;
    }
    else
    {
        prSeekTable = &prParser->rAudioSeekTable;        
    }       

    u4SearchRefTime = _AviParserRealTiem2RefTime(eType, prAviProviderMgr, u8StartTime);

    if (eDirect == SOURCE_PROVIDER_SEARCH_FORWARD)
    {
        ASSERT(0);
    }

    // build table if out of region
    if (prSeekTable->u4RangeRefEndTime < u4SearchRefTime || prSeekTable->u4NumEntries == 0)
    {
        _AviParserBuildSeekTableNoIdx1(prAviProviderMgr, eType, u4SearchRefTime);
    }

    // search in table
    if (prSeekTable->u4NumEntries != 0)
    {
        prEntry = (AVI_SP_VBR_ENTRY_T *)prSeekTable->pvEntry;
        u4EntryIdx = _AviParserSearchEntry(prEntry, u4SearchRefTime, 0, prSeekTable->u4NumEntries-1);
        rTargetEnty.u4ChunkIdx = prEntry[u4EntryIdx].u4ChunkIdx;
        rTargetEnty.u4Offset= prEntry[u4EntryIdx].u4Offset;
        return rTargetEnty;
    }
    else
    {
        rTargetEnty.u4Offset = 0;
        rTargetEnty.u4ChunkIdx = 0;
        return rTargetEnty;
    }
}

#endif

static PROVIDER_ERROR_T _AviParserHeaderParse(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, STFSAL *prFsal, kal_uint32 u4FileSize, kal_uint8 *pu1TempBuf)
{
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    AVI_SP_STREAM_HEADER_T *prStreamHeader;
    SP_API_T *prSrcAPI = prAviProviderMgr->rSrcHandle.prSourceAPI; 
    SP_TRACK_T eOpenTrack = prAviProviderMgr->rOpenInfo.eOpenTrack;
    kal_uint32 u4NextPos;
    kal_uint32 u4FilePos;
    kal_uint32 u4StreamNum = 0;
    FSAL_Status eFsalRet;
    
    // Read 12 Bytes
    if (PROVIDER_ERROR == _AviPaserReadData(prFsal, pu1TempBuf, 12))  /* RIFF size AVI */
    {
        AVI_SP_TRACE_PARSER_ERROR(0);
        return PROVIDER_ERROR;
    }    
   
    if (_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_RIFF) == KAL_FALSE ||
        _AviPaserCheckTag((pu1TempBuf+8), AVI_SP_TAG_AVI) == KAL_FALSE)
    {
        AVI_SP_TRACE_PARSER_ERROR(0);
        return PROVIDER_ERROR;
    }

    while (1)
    {
        if (PROVIDER_ERROR == _AviParserCurrentPos(prFsal, &u4FilePos))
        {
            AVI_SP_TRACE_PARSER_ERROR(0);
            return PROVIDER_ERROR;
        }  

        if (u4FilePos >= u4FileSize)
        {
            /* teminate condition */
            break;
        }

        // terminate by source
        if (prParser->fgQuickClose == KAL_TRUE)
        {
            AVI_SP_TRACE_PARSER_ERROR(0);
            //prParser->fgQuickClose = KAL_FALSE;
            return PROVIDER_ERROR;
        }

        // Read 8 Bytes
        AVI_SP_READ_DATA(prFsal, pu1TempBuf, 8); /* fourCC size*/    
        _AviParserCurrentPos(prFsal, &u4FilePos);
        u4NextPos = u4FilePos + *((kal_uint32 *)(pu1TempBuf+4));
      
        if (_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_LIST) == KAL_TRUE) 
        {                        
            // Read 4 Bytes
            AVI_SP_READ_DATA(prFsal, pu1TempBuf, 4);
            if (_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_HEADER_LIST) == KAL_TRUE) /* LIST size hdrl */
            {
                // Read 8 Bytes
                AVI_SP_READ_DATA(prFsal, pu1TempBuf, 8); /* avih size */
                
                if (_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_AVI_HEADER) == KAL_FALSE ||
                     _AviPaserCheckSize((pu1TempBuf+4), sizeof(AVI_SP_FILE_HEADER_T)) == KAL_FALSE)
                {
                    AVI_SP_TRACE_PARSER_ERROR(0);
                    return PROVIDER_ERROR;
                }

                AVI_SP_READ_DATA(prFsal, (kal_uint8 *)&prParser->rFileHeader, sizeof(AVI_SP_FILE_HEADER_T));  /* fileHeader */

                _AviParserCurrentPos(prFsal, &u4NextPos);
            }
            else if (_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_STREAM_LIST) == KAL_TRUE) /* LIST size strl */
            {
                media_codec_type_t eCodec;
                kal_uint32 u4RealSize, u4DefineSize;
                    
                // Read 8 Bytes
                AVI_SP_READ_DATA(prFsal, pu1TempBuf, 8); /* strh size */

                /* strh size StreamHeader */
                u4RealSize = *((kal_uint32 *)(pu1TempBuf+4));
                u4DefineSize = sizeof(AVI_SP_STREAM_HEADER_T);
                
                if (_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_STREAM_HEADER) == KAL_FALSE ||
                     (u4RealSize < AVI_SP_STREAM_HEADER_SIZE))
                {
                    AVI_SP_TRACE_PARSER_ERROR(0);
                    return PROVIDER_ERROR;
                }

                if (u4RealSize < u4DefineSize)
                {
                    u4DefineSize = u4RealSize;
                }
                prStreamHeader = (AVI_SP_STREAM_HEADER_T *)pu1TempBuf; 
                AVI_SP_READ_DATA(prFsal, (kal_uint8 *)prStreamHeader, u4DefineSize); /* streamHeader */                

                if (u4RealSize>u4DefineSize)
                {
                    _AviParserCurrentPos(prFsal, &u4FilePos);
                    if (_AviParserSkipFileSize(prFsal, (u4FilePos+u4RealSize-u4DefineSize), u4FileSize) == KAL_FALSE)
						        {
						            break;
						        }
                }             

                if (_AviPaserCheckTag((kal_uint8 *)&prStreamHeader->fcc_type, AVI_SP_TAG_STREAM_TYPE_VID) == KAL_TRUE)
                {
                    if (prParser->u4VideoNum < AVI_SP_VID_STREAM_NUM &&
                        (eOpenTrack & SOURCE_PROVIDER_TRACK_VIDEO))
                    {
                        // obtain codec type
                        eCodec = _AviParserCheckVideoCodec(prStreamHeader->fcc_hdlr);

                        // check header info
                        if (eCodec != MEDIA_CODEC_NONE &&
                            prStreamHeader->scale != 0 &&
                            prStreamHeader->rate != 0)
                        {
                            SPIF_VIDEO_STREAM_INFO_T *prVideoStreamInfo;
                            AVI_SP_VIDEO_FORMAT_HEADER_T *prVideoFormatHeader;
                        
                            prSrcAPI->SPFN_MEM_COPY((void *)&prParser->rVidStreamHdr[prParser->u4VideoNum], 
                                                                                               (void *)prStreamHeader, sizeof(AVI_SP_STREAM_HEADER_T));

                            // Read 8 Bytes
                            AVI_SP_READ_DATA(prFsal, pu1TempBuf, 8); /* strf size */

                             /* strh size StreamHeader */
                            // The size of header could be larger than sizeof(AVI_SP_VIDEO_FORMAT_HEADER_T)
                            if (_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_STREAM_FORMAT) == KAL_FALSE)
                            {
                                AVI_SP_TRACE_PARSER_ERROR(0);
                                return PROVIDER_ERROR;
                            }

                            prVideoFormatHeader = &prParser->rVidFormatHdr[prParser->u4VideoNum];
                            AVI_SP_READ_DATA(prFsal, (kal_uint8 *)prVideoFormatHeader, sizeof(AVI_SP_VIDEO_FORMAT_HEADER_T)); /* videoFormatHeader */

                            // check video fromat header
                            if (prVideoFormatHeader->width !=0 &&
                                 prVideoFormatHeader->height != 0)
                            {
                                prVideoStreamInfo = &prParser->rVideoInfo[prParser->u4VideoNum];
                                prVideoStreamInfo->u4StreamIndex = u4StreamNum;
                                prVideoStreamInfo->eCodecType = eCodec;
                                prVideoStreamInfo->u8Duration = _AviParserFrameToTime(prStreamHeader->length, prStreamHeader->scale, prStreamHeader->rate);//prStreamHeader->length*prStreamHeader->scale*1000/prStreamHeader->rate;
                                prVideoStreamInfo->u4Fps = prStreamHeader->rate * 100 /prStreamHeader->scale;
                                prVideoStreamInfo->u4Width = prVideoFormatHeader->width;
                                prVideoStreamInfo->u4Height= prVideoFormatHeader->height;
                                prVideoStreamInfo->u4AvgBitrate = 0;

                                prParser->u4VideoNum++;
                            }
                        }
                    }
                }
                else if (_AviPaserCheckTag((kal_uint8 *)&prStreamHeader->fcc_type, AVI_SP_TAG_STREAM_TYPE_AUD) == KAL_TRUE)
                {
                    if (prParser->u4AudioNum < AVI_SP_AUD_STREAM_NUM&&
                        (eOpenTrack & SOURCE_PROVIDER_TRACK_AUDIO))
                    {
                        if (prStreamHeader->scale != 0 &&
                            prStreamHeader->rate != 0)
                        {
                            SPIF_AUDIO_STREAM_INFO_T *prAudioStreamInfo;
                            AVI_SP_AUDIO_FORMAT_HEADER_T *prAudioFormatHeader;
                                                    
                            prSrcAPI->SPFN_MEM_COPY((void *)&prParser->rAudStreamHdr[prParser->u4AudioNum], 
                                                                                              (void *)prStreamHeader, sizeof(AVI_SP_STREAM_HEADER_T));

                            // Read 8 Bytes
                            AVI_SP_READ_DATA(prFsal, pu1TempBuf, 8); /* strf size */

                             /* strh size StreamHeader */
                            if (_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_STREAM_FORMAT) == KAL_FALSE)
                            {
                                AVI_SP_TRACE_PARSER_ERROR(0);
                                return PROVIDER_ERROR;
                            }

                            prAudioFormatHeader = &prParser->rAudFormatHdr[prParser->u4AudioNum];
                            AVI_SP_READ_DATA(prFsal, (kal_uint8 *)prAudioFormatHeader, sizeof(AVI_SP_AUDIO_FORMAT_HEADER_T)); /* audioFormatHeader */

                            // obtain codec type
                            eCodec = _AviParserCheckAudioCodec(prAudioFormatHeader->format);

                            if (eCodec != MEDIA_CODEC_NONE)
                            {
                                prAudioStreamInfo = &prParser->rAudioInfo[prParser->u4AudioNum];
                                prAudioStreamInfo->u4StreamIndex = u4StreamNum;
                                prAudioStreamInfo->eCodecType = eCodec;
                                prAudioStreamInfo->u8Duration = _AviParserFrameToTime(prStreamHeader->length, prStreamHeader->scale, prStreamHeader->rate);//prStreamHeader->length*prStreamHeader->scale*1000/prStreamHeader->rate;                                
                                prAudioStreamInfo->u2Channels = prAudioFormatHeader->channels;
                                prAudioStreamInfo->u2BitsPerSample = prAudioFormatHeader->bit_per_sample;
                                prAudioStreamInfo->u4SampleRate = prAudioFormatHeader->sample_per_sec;
                                prAudioStreamInfo->u4FrameDuration = 0;
                                prAudioStreamInfo->fgAddHeader = KAL_FALSE;

                                prParser->u4AudioNum++;
                            }
                        }
                    }
                }
                //else
                //{
                    // encount unknow stream header                    
                //}

                // always jump to next
                // jump to next by u4NextPos

                u4StreamNum++;
            }
            else if (_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_MOVI) == KAL_TRUE)  /* LIST size movi */
            { 
                kal_uint32 *pu4Value = (kal_uint32 *)(pu1TempBuf+4);
                
                prParser->u4MoviAddr = u4NextPos - *pu4Value;

                // skip "movi"
                // jump to next by u4NextPos
            }
            //else
            //{
                // encount unknow list chunk
                // jump to next by u4NextPos
            //}
        }
        else if (_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_IDX1) == KAL_TRUE)
        {
            _AviParserCurrentPos(prFsal, &prParser->u4IndexAddr);

            prParser->u4IndexEndAddr = u4NextPos;

            // jump to next by u4NextPos
        }
        //else if (_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_JUNK) == KAL_TRUE)
        //{        
            // jump to next by u4NextPos
        //}
#ifdef __VE_VIDEO_CLIPPER_SUPPORT__        
        else if (_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_MAUI) == KAL_TRUE)
        {
            prParser->fgMtkFile = KAL_TRUE;
            // jump to next by u4NextPos
        }
#endif        
#ifdef __VE_PARSE_TRANSFORMATION_INFO__  
        else if(_AviPaserCheckTag(pu1TempBuf, AVI_SP_TAG_TRNS) == KAL_TRUE)
        {
            SPIF_TRANSFORMATION_INFO_T *prtransInfo =  (SPIF_TRANSFORMATION_INFO_T *)&(prParser->rTransformation);
            AVI_SP_READ_DATA(prFsal, (kal_uint8 *)&(prtransInfo->u2Rotation), 2);
            AVI_SP_READ_DATA(prFsal, (kal_uint8 *)&(prtransInfo->u1HorizontalMirror), 1);
            AVI_SP_READ_DATA(prFsal, (kal_uint8 *)&(prtransInfo->u1VertialMirror), 1);
            // jump to next by u4NextPos
        }
#endif
        //else
        //{
            // jump to next by u4NextPos
        //}

        if (_AviParserSkipFileSize(prFsal, u4NextPos, u4FileSize) == KAL_FALSE)
        {
            break;
        }
    }

    return PROVIDER_ERROR_NONE;

FILE_READ_ERROR:
    if (eFsalRet == FSAL_READ_OVER_EOF)
    {  
        AVI_SP_TRACE_WARNING(eFsalRet, 0, 0); 
        return PROVIDER_ERROR_NONE;  
    }                 
    else  
    {         
        AVI_SP_TRACE_FSAL_ERROR(eFsalRet); 
        return PROVIDER_ERROR;      
    }    
    
}

static PROVIDER_ERROR_T _AviProviderFillBuffIdx1(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, SP_PORT_TYPE_T eType, AVI_SP_CONTROL_T *prControl)
{
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    AVI_SP_FILE_T *prFile = &prAviProviderMgr->rFile;
    void *pvSrcHandle = prAviProviderMgr->rSrcHandle.pvSourceHandle;
    SP_API_T *prSrcAPI = prAviProviderMgr->rSrcHandle.prSourceAPI;    
    AVI_SP_IDX1_MGR_T *prIndx1Status = &prControl->rIndexStatus;
    AVI_SP_INDEX_T *prCurrentIndex = &prControl->rCurrentIndex;
    VIDEO_CORE_RING_BUFFER_MGR_T *prList = &prControl->rList;
    SPIF_VIDEO_STREAM_INFO_T *prVideoStreamInfo = NULL;
#ifdef __VE_SP_AVI_PROFILE__
    AVI_SP_PROFILE_T *prProfile = &prAviProviderMgr->rProfile;
    kal_uint32 *pu4DirectRead, *pu4IndxRead, *pu4ExitGap, *pu4ExitFull;
#endif

    STFSAL *prFsal;
    kal_uint32 u4GapLimit, u4MinFetchSize;
    kal_uint32 u4ChunkSize, u4ChunkSizeAlign, u4FirstOffset, u4FirstOffsetAlign, u4FirstDiff, u4GapSumSize, u4GapSize, u4FetchSize;  
    kal_uint32 u4BuffSize, u4BuffAddr;    
    FSAL_Status rFsalRet;
    AVI_SP_SEEK_TABLE_T *prSeekTable;
    kal_bool fgOneData = KAL_FALSE;

    if (eType == SOURCE_PROVIDER_PORT_AUDIO)
    {
        u4GapLimit = AVI_SP_AUDIO_GAP_SIZE;
        u4MinFetchSize = AVI_SP_AUDIO_MIN_FETCH_SIZE;
        prFsal = &prFile->rFsalAudio;
        prSeekTable = &prParser->rAudioSeekTable;
#ifdef __VE_SP_AVI_PROFILE__
        pu4DirectRead = &prProfile->u4AudioDirectRead;
        pu4IndxRead = &prProfile->u4AudioIdxRead;
        pu4ExitGap = &prProfile->u4AudioExitGap;
        pu4ExitFull = &prProfile->u4AudioExitFull;
#endif
    }
    else
    {
        u4GapLimit = AVI_SP_VIDEO_GAP_SIZE;
        u4MinFetchSize = AVI_SP_VIDEO_MIN_FETCH_SIZE;
        prFsal = &prFile->rFsalVideo;
        prSeekTable = &prParser->rVideoSeekTable;
        prVideoStreamInfo = &prParser->rVideoInfo[prAviProviderMgr->rVideoUserSetting.u4SelectNum];
#ifdef __VE_SP_AVI_PROFILE__
        pu4DirectRead = &prProfile->u4VideoDirectRead;
        pu4IndxRead = &prProfile->u4VideoIdxRead;
        pu4ExitGap = &prProfile->u4VideoExitGap;
        pu4ExitFull = &prProfile->u4VideoExitFull;
#endif        
    }    
    
    // Obtain first chunk size
    u4FirstOffset = prCurrentIndex->u4ChunkOffset;
    u4FirstOffsetAlign = _AviParserRoundUpToPowerOfTwo(u4FirstOffset, AVI_SP_FASL_SECTOR_SIZE);
    u4FirstDiff = u4FirstOffset-u4FirstOffsetAlign; 
    u4ChunkSize = prCurrentIndex->u4ChunkLength + u4FirstDiff;
    u4ChunkSizeAlign = _AviParserRoundUpToPowerOfTwo((u4ChunkSize + AVI_SP_FASL_SECTOR_SIZE -1), AVI_SP_FASL_SECTOR_SIZE);
    u4GapSumSize = 0;
    
    if (u4ChunkSizeAlign > prSrcAPI->SPFN_BITSTREAM_BUF_SIZE(pvSrcHandle, eType)) // chunk is large than total buffer size
    {
    
#ifdef __VE_SP_AVI_LOG_HIGH__
        drv_trace4(AVI_SP_TRACE_HIGH_GROUP, AVI_SP_BIG_CHUNK, eType, u4FirstOffset, prCurrentIndex->u4ChunkLength, prIndx1Status->u4CurrentRefTime);
#endif  

        fgOneData = KAL_TRUE;
        
        u4ChunkSize = AVI_SP_FASL_SECTOR_SIZE;
        u4BuffAddr = prSrcAPI->SPFN_BITSTREAM_BUF_QUERY_AVAILABLE_SIZE(pvSrcHandle, eType, u4ChunkSize, &u4BuffSize);
        if (u4BuffSize == 0)
        {
            //AVI_SP_TRACE_PARSER_ERROR(0);
            return PROVIDER_ERROR_WAIT_RESOURCE;
        }
               
        if (eType == SOURCE_PROVIDER_PORT_VIDEO)
        {                    
            u4ChunkSize = _AviParserRoundUpToPowerOfTwo(u4BuffSize, AVI_SP_FASL_SECTOR_SIZE);
        }        

        
        // add partial data flag
        prCurrentIndex->u4Flag |= AVI_SP_IF_MTK_PARTIAL_DATA;
                
        /*
               AVI_SP_TRACE_PARSER_ERROR(0);
               return PROVIDER_ERROR_NOT_SUPPORT;
               */
    }
    else
    {
        // Obtain available buffer
        if (u4MinFetchSize < u4ChunkSizeAlign)
        {
            u4MinFetchSize = u4ChunkSizeAlign;
        }
    
        u4BuffAddr = prSrcAPI->SPFN_BITSTREAM_BUF_QUERY_AVAILABLE_SIZE(pvSrcHandle, eType, u4MinFetchSize, &u4BuffSize);
        if (u4BuffSize == 0)
        {
            //AVI_SP_TRACE_PARSER_ERROR(0);
            return PROVIDER_ERROR_WAIT_RESOURCE;
        }
        else
        {
            u4BuffSize =  _AviParserRoundUpToPowerOfTwo(u4BuffSize, AVI_SP_FASL_SECTOR_SIZE);
            if (u4MinFetchSize>u4BuffSize)
            {
                ASSERT(0);
            }
        }
    }
    
    // reset list
    VideoCoreCleanRingBuffer(prList);
    
    // Collect frame chunk to list
    do
    {
        // check whether list is full
        if (VideoCoreIsRingBufferFull(prList) == KAL_TRUE)
        {
            break;
        }
    
        // build index table
        if (prSeekTable->u4RangeRefEndTime < prIndx1Status->u4CurrentRefEndTime)
        {
            kal_bool fgAdd2Table;
            kal_uint32 u4Duration;
            
            if (eType == SOURCE_PROVIDER_PORT_VIDEO)
            {
                if (_AviParserIsVideoKeyFrame(prCurrentIndex->u4Flag, prVideoStreamInfo) != 0)
                {
                    fgAdd2Table = KAL_TRUE;
                    u4Duration = 1;
                }
                else
                {
                    fgAdd2Table = KAL_FALSE;
                    prSeekTable->u4RangeRefEndTime++;
                }
            }
            else
            {
                fgAdd2Table = KAL_TRUE;

                if (prIndx1Status->fgVBR == KAL_TRUE)
                {
                    u4Duration = 1;
                }
                else
                {
                    u4Duration = prCurrentIndex->u4ChunkLength;
                }
            }

            if (fgAdd2Table == KAL_TRUE)
            {
                _AviParserAddSeekTable(prAviProviderMgr, prSeekTable, u4Duration, prIndx1Status->u4EntryOffset);
            }
            prSeekTable->u4LastFileAddr = prIndx1Status->u4EntryOffset + sizeof(AVI_SP_INDEX_T);
        }
    
        // record time
        prCurrentIndex->u4ChunkId = prIndx1Status->u4CurrentRefTime;
    
        // put into list
        VideoCoreInsertToHeadofRingBuffer(prList, (kal_uint8 *)prCurrentIndex);
    
        // get next chunk
        if (_AviParserIdx1MgrGetNextIndex(prIndx1Status, prCurrentIndex) == KAL_FALSE)
        {
            // EOF
            prControl->eEof = AVI_SP_EOF_WAIT_SEND;
            break;
        }
        
#ifdef __VE_SP_AVI_PROFILE__
        *pu4IndxRead = *pu4IndxRead+1;
#endif
        
        // check whether chunk put into list
        u4GapSize = prCurrentIndex->u4ChunkOffset-(u4FirstOffsetAlign+u4ChunkSize);
        u4GapSumSize += u4GapSize;
    
        if ((u4GapSumSize>u4GapLimit && u4GapSumSize>(u4ChunkSize/5)) ||
             (_AviParserRoundUpToPowerOfTwo((u4ChunkSize+u4GapSize+prCurrentIndex->u4ChunkLength + AVI_SP_FASL_SECTOR_SIZE-1), AVI_SP_FASL_SECTOR_SIZE) > u4BuffSize ||
             fgOneData == KAL_TRUE)
           )
        {
#ifdef __VE_SP_AVI_PROFILE__
            if (u4GapSumSize>u4GapLimit)
            {
                *pu4ExitGap = *pu4ExitGap+1;
            }
            else
            {
                *pu4ExitFull = *pu4ExitFull+1;
            }
#endif        
            break;
        }  
        u4ChunkSize += (u4GapSize+prCurrentIndex->u4ChunkLength);
    } while (1);
    
    // seek file
    rFsalRet = FSAL_Direct_Seek(prFsal, u4FirstOffsetAlign);
    if (rFsalRet != FSAL_OK)
    {
        AVI_SP_TRACE_FSAL_ERROR(rFsalRet);
        return PROVIDER_ERROR_DELAY_REPORT_WITH_EOF;
    }
    
    // adjust fetch size to align 
    u4FetchSize = _AviParserRoundUpToPowerOfTwo((u4ChunkSize+AVI_SP_FASL_SECTOR_SIZE-1), AVI_SP_FASL_SECTOR_SIZE);
    if (u4FetchSize>u4BuffSize)
    {
        ASSERT(0);
    }

    // avoid alignment size excess file size
    if (u4FirstOffsetAlign+u4FetchSize > prAviProviderMgr->rOpenInfo.u4DataSize)
    {
        u4FetchSize = u4ChunkSize;
    }

    // read data to buffer
    rFsalRet = FSAL_Direct_Read(prFsal, (kal_uint8 *)u4BuffAddr, u4FetchSize);
    if (rFsalRet != FSAL_OK)
    {
        AVI_SP_TRACE_FSAL_ERROR(rFsalRet);
        return PROVIDER_ERROR_DELAY_REPORT_WITH_EOF;
    }
#ifdef __VE_SP_AVI_PROFILE__
    *pu4DirectRead = *pu4DirectRead+1;
#endif
    
    prControl->u4BuffStartAddr = u4BuffAddr+u4FirstDiff;
    prControl->u4BuffSize = u4ChunkSize-u4FirstDiff;
    
#ifdef __VE_SP_AVI_LOG_LOW__
    drv_trace4(AVI_SP_TRACE_LOW_GROUP, AVI_SP_IDX1_FILL_BUFF, eType, prIndx1Status->u4CurrentRefTime, u4BuffAddr, u4ChunkSize);
#endif

    return PROVIDER_ERROR_NONE;
}

static PROVIDER_ERROR_T _AviProviderDemuxDataIdx1(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, SP_PORT_TYPE_T eType, AVI_SP_CONTROL_T *prControl, kal_uint32 *pu4Time)
{
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    void *pvSrcHandle = prAviProviderMgr->rSrcHandle.pvSourceHandle;
    SP_API_T *prSrcAPI = prAviProviderMgr->rSrcHandle.prSourceAPI;     
    VIDEO_CORE_RING_BUFFER_MGR_T *prList = &prControl->rList;
    AVI_SP_MEM_INFO_T *prMemInfo = &prAviProviderMgr->rMemInfo;
    SPIF_VIDEO_STREAM_INFO_T *prVideoStreamInfo = NULL;

    kal_uint32 u4SelectNum; 
    SPIF_PROVIDER_FRAME_INFO_T rFrameInfo;  
    AVI_SP_INDEX_T *prListItem, *prListFirstItem;        
    kal_uint64 u8CurrentTime;
    kal_bool fgUpdateBufAddr = KAL_TRUE;
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    SPIF_H264_DECODER_PAYLOAD_INFO_T rPayload;
#endif        

    // assign variable
    if (eType == SOURCE_PROVIDER_PORT_AUDIO)
    {
        prControl = &prAviProviderMgr->rAudioControl;
        u4SelectNum = prAviProviderMgr->rAudioUserSetting.u4SelectNum;
        prListFirstItem = &prMemInfo->prAListItem[1];
    }
    else
    {
        prControl = &prAviProviderMgr->rVideoControl;
        u4SelectNum = prAviProviderMgr->rVideoUserSetting.u4SelectNum;  
        prListFirstItem = &prMemInfo->prVListItem[1];
        prVideoStreamInfo = &prParser->rVideoInfo[u4SelectNum];
    }     
    
    //obtain item from list
    prListItem = (AVI_SP_INDEX_T *)VideoCoreGetTailofRingBufferAddr(prList);            

    // set frame info
    prSrcAPI->SPFN_MEM_SET((void *)&rFrameInfo, 0, sizeof(rFrameInfo));
    rFrameInfo.pu1Addr = (kal_uint8 *)(prControl->u4BuffStartAddr+ prListItem->u4ChunkOffset -prListFirstItem->u4ChunkOffset);
    rFrameInfo.u4FrameSize = prListItem->u4ChunkLength;
    rFrameInfo.u8Timestamp = _AviParserRefTiem2RealTime(eType, prAviProviderMgr, prListItem->u4ChunkId);

    u8CurrentTime = rFrameInfo.u8Timestamp;
    if (u8CurrentTime > prControl->u8EndTime)
    {
        prControl->eEof = AVI_SP_EOF_WAIT_SEND;
        VideoCoreCleanRingBuffer(prList);
        return PROVIDER_ERROR_NOT_FINISH;
    }

    // error handle
    if (prListItem->u4Flag&AVI_SP_IF_MTK_PARTIAL_DATA)
    {
        if (eType == SOURCE_PROVIDER_PORT_AUDIO)
        {
            rFrameInfo.pu1Addr = (kal_uint8 *)0;
            rFrameInfo.u4FrameSize = 0;
            rFrameInfo.fgSilent = KAL_TRUE;
            fgUpdateBufAddr = KAL_FALSE;
        }
        else
        {
            rFrameInfo.pu1Addr = (kal_uint8 *)prControl->u4BuffStartAddr;
            rFrameInfo.u4FrameSize = prControl->u4BuffSize;
        }
    }    

    if (eType == SOURCE_PROVIDER_PORT_AUDIO)
    {
        rFrameInfo.fgKeyFrame = KAL_TRUE;
    }
    else
    {               
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
        if (prVideoStreamInfo->eCodecType == MEDIA_CODEC_VID_H264)
        {
            rFrameInfo.u4PayloadNum = 1;
            rFrameInfo.u4PayloadSize = 8;
            rPayload.u4Address = (kal_uint32)rFrameInfo.pu1Addr;
            rPayload.u4Length = rFrameInfo.u4FrameSize;
            rFrameInfo.pu1Payload = (kal_uint8 *)&rPayload;
        }
#endif 
        rFrameInfo.fgKeyFrame = _AviParserIsVideoKeyFrame(prListItem->u4Flag, prVideoStreamInfo);
    }

    // sned to source
    if (prSrcAPI->SPFN_ADD_ONE_DATA(pvSrcHandle, eType, &rFrameInfo) == PROVIDER_ERROR_WAIT_RESOURCE)
    {
        return PROVIDER_ERROR_WAIT_RESOURCE;
    }

    // consume one item in list
    VideoCoreConsumeTailofRingBuffer(prList);

    // updata buffer write pointer
    if (fgUpdateBufAddr == KAL_TRUE)
    {
        prSrcAPI->SPFN_BITSTREAM_BUF_UPDATA_ADD(pvSrcHandle, eType, (kal_uint32)(rFrameInfo.pu1Addr+rFrameInfo.u4FrameSize));
    }
   
    *pu4Time = (kal_uint32)(u8CurrentTime - prControl->u8CurrentTime);
    prControl->u8CurrentTime = u8CurrentTime;

#ifdef __VE_SP_AVI_LOG_LOW__
    drv_trace4(AVI_SP_TRACE_LOW_GROUP, AVI_SP_IDX1_DEMUX_DATA, eType, rFrameInfo.u8Timestamp, prList->u4Head, prList->u4Tail);
#endif

    if (VideoCoreIsRingBufferEmpty(prList) == KAL_FALSE)
    {
        return PROVIDER_ERROR_NOT_FINISH;
    }
    else
    {
        return PROVIDER_ERROR_NONE;
    }

}

#ifdef __VE_SP_AVI_NON_IDX1_PLAYBACK__ 
static PROVIDER_ERROR_T _AviProviderFillBuffNoIdx1(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, SP_PORT_TYPE_T eType, AVI_SP_CONTROL_T *prControl)
{
    AVI_SP_NO_INDEX_CTRL_T *prNoIdnxCtrl = &prControl->rNoIndexCtrl;
    AVI_SP_FILE_T *prFile = &prAviProviderMgr->rFile;
    void *pvSrcHandle = prAviProviderMgr->rSrcHandle.pvSourceHandle;
    SP_API_T *prSrcAPI = prAviProviderMgr->rSrcHandle.prSourceAPI;
#ifdef __VE_SP_AVI_PROFILE__
    AVI_SP_PROFILE_T *prProfile = &prAviProviderMgr->rProfile;
    kal_uint32 *pu4DirectRead;
#endif    

    STFSAL *prFsal;
    kal_uint32 u4MinFetchSize, u4LeftSize, u4CurFileAddr;
    kal_uint32 u4SeekAddr = 0;
    kal_uint32 u4BuffSize, u4BuffAddr;    
    FSAL_Status rFsalRet;

    if (eType == SOURCE_PROVIDER_PORT_AUDIO)
    {
        u4MinFetchSize = AVI_SP_AUDIO_MIN_FETCH_SIZE;
        prFsal = &prFile->rFsalAudio;
#ifdef __VE_SP_AVI_PROFILE__
        pu4DirectRead = &prProfile->u4AudioDirectRead;
#endif        
    }
    else
    {
        u4MinFetchSize = AVI_SP_VIDEO_MIN_FETCH_SIZE;
        prFsal = &prFile->rFsalVideo;
#ifdef __VE_SP_AVI_PROFILE__
        pu4DirectRead = &prProfile->u4VideoDirectRead;
#endif         
    }
    
    // seek
    if (prNoIdnxCtrl->eFetch != AVI_SP_FETCH_MIN)
    {
        if (prNoIdnxCtrl->eFetch == AVI_SP_FETCH_SKIP)
        {
            u4SeekAddr = prNoIdnxCtrl->u4DataOffset + (prNoIdnxCtrl->u4FetchSize - prControl->u4BuffSize);
            prNoIdnxCtrl->u4FetchSize = 0;
        }
        else if (prNoIdnxCtrl->eFetch == AVI_SP_FETCH_FORCE)
        {
            u4SeekAddr = prNoIdnxCtrl->u4DataOffset - prControl->u4BuffSize;
        }
        else
        {
            ASSERT(0);
        }
    
        if (_AviParserSkipFileSize(prFsal, u4SeekAddr, prAviProviderMgr->rOpenInfo.u4DataSize) == KAL_FALSE)
        {
            if (u4SeekAddr>=prAviProviderMgr->rOpenInfo.u4DataSize)
            {
                // end of file
                prControl->eEof = AVI_SP_EOF_WAIT_SEND;
                return PROVIDER_ERROR_NONE;
            }
            else
            {
                return PROVIDER_ERROR_DELAY_REPORT_WITH_EOF;
            }
        }
        prNoIdnxCtrl->eFetch = AVI_SP_FETCH_MIN;
    }
    
    if (prNoIdnxCtrl->u4FetchSize > u4MinFetchSize)
    {
        u4MinFetchSize = prNoIdnxCtrl->u4FetchSize;
    }
    
    if (PROVIDER_ERROR == _AviParserCurrentPos(prFsal, &u4CurFileAddr))
    {
        return PROVIDER_ERROR_DELAY_REPORT_WITH_EOF;
    }
    u4LeftSize = prAviProviderMgr->rOpenInfo.u4DataSize - u4CurFileAddr;
    if (u4MinFetchSize >  u4LeftSize)
    {
        if (u4LeftSize == 0)
        {
            // end of file
            prControl->eEof = AVI_SP_EOF_WAIT_SEND;
            return PROVIDER_ERROR_NONE;
        }
        else
        {
            u4MinFetchSize = u4LeftSize;
        }
    }
    
    // Obtain available buffer
    u4BuffAddr = prSrcAPI->SPFN_BITSTREAM_BUF_QUERY_AVAILABLE_SIZE(pvSrcHandle, eType, u4MinFetchSize, &u4BuffSize);
    if (u4BuffSize == 0)
    {
        return PROVIDER_ERROR_WAIT_RESOURCE;
    }
    
    // to do: check performance with fetch size and block audio read
    // read data from file
    rFsalRet = FSAL_Direct_Read(prFsal, (kal_uint8 *)u4BuffAddr, u4MinFetchSize);
    if (rFsalRet != FSAL_OK)
    {            
        AVI_SP_TRACE_FSAL_ERROR(rFsalRet);
        return PROVIDER_ERROR_DELAY_REPORT_WITH_EOF;
    }
#ifdef __VE_SP_AVI_PROFILE__
    *pu4DirectRead = *pu4DirectRead+1;
#endif    
    
    prControl->u4BuffStartAddr = u4BuffAddr;
    prControl->u4BuffSize = u4MinFetchSize;
    _AviParserCurrentPos(prFsal, &prNoIdnxCtrl->u4DataOffset);

    #ifdef __VE_SP_AVI_LOG_LOW__
    drv_trace4(AVI_SP_TRACE_LOW_GROUP, AVI_SP_NO_IDX1_FILL_BUFF, eType, u4BuffAddr, u4MinFetchSize, prNoIdnxCtrl->u4DataOffset);
    #endif

    return PROVIDER_ERROR_NONE;
}

static PROVIDER_ERROR_T _AviProviderDemuxDataNoIdx1(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, SP_PORT_TYPE_T eType, AVI_SP_CONTROL_T *prControl, kal_uint32 *pu4Time)
{
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    void *pvSrcHandle = prAviProviderMgr->rSrcHandle.pvSourceHandle;
    SP_API_T *prSrcAPI = prAviProviderMgr->rSrcHandle.prSourceAPI; 
    AVI_SP_NO_INDEX_CTRL_T *prNoIdnxCtrl = &prControl->rNoIndexCtrl;
    
    kal_uint32 u4SelectNum, u4StreamIndex;
    AVI_SP_SEEK_TABLE_T *prSeekTable;
    SPIF_PROVIDER_FRAME_INFO_T rFrameInfo;   
    kal_uint8 *pu1Buf;
    kal_uint32 u4BufEndAddr;    
    kal_uint32 u4Temp, u4FixedSize, u4Num, u4Type, u4Duration;
    kal_uint32 u4FileAddr;
    kal_bool fgAdd2Table;  
    PROVIDER_ERROR_T eRet = PROVIDER_ERROR_NONE;
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    SPIF_H264_DECODER_PAYLOAD_INFO_T rPayload;
#endif    
    kal_bool fgLargeChunk = KAL_FALSE;
    kal_bool fgUpdateBufAddr = KAL_TRUE;

    // assign variable
    if (eType == SOURCE_PROVIDER_PORT_AUDIO)
    {
        u4SelectNum = prAviProviderMgr->rAudioUserSetting.u4SelectNum;
        u4StreamIndex = prParser->rAudioInfo[u4SelectNum].u4StreamIndex;
        prSeekTable = &prParser->rAudioSeekTable;
    }
    else
    {
        u4SelectNum = prAviProviderMgr->rVideoUserSetting.u4SelectNum;
        u4StreamIndex = prParser->rVideoInfo[u4SelectNum].u4StreamIndex;
        prSeekTable = &prParser->rVideoSeekTable;
    }        
    
    pu1Buf = (kal_uint8 *)prControl->u4BuffStartAddr;
    u4BufEndAddr = (kal_uint32)pu1Buf+prControl->u4BuffSize;    
    u4FileAddr = prNoIdnxCtrl->u4DataOffset -prControl->u4BuffSize;

    do{
        // at least 8 bytes for (xxss size)
        if (((kal_uint32)pu1Buf+8) > u4BufEndAddr)
        {
            prNoIdnxCtrl->eFetch = AVI_SP_FETCH_FORCE;
            prNoIdnxCtrl->u4FetchSize = 8;
            break;
        }
        
        // get xxss
        u4Temp = _AviParserReadFourByte(pu1Buf);
        pu1Buf += 4;
        u4Num = _AviParserGetStreamNumber(u4Temp);
        u4Type = u4Temp & 0xffff0000;

        // get chunk size     
        u4Temp = _AviParserReadFourByte(pu1Buf);
        u4FixedSize = (u4Temp + 1) & (0xfffffffe);
        pu1Buf += 4;
        
        if (u4StreamIndex == u4Num)
        {                
            if (eType == SOURCE_PROVIDER_PORT_AUDIO &&
                (u4Type == AVI_SP_TAG_XXWB_STREAM_TYPE)
               )
            {                                        
                // check chunk size
                // large than 
                if (u4FixedSize>AVI_SP_AUDIO_MIN_FETCH_SIZE)
                {
                    if (u4FixedSize+8 > prSrcAPI->SPFN_BITSTREAM_BUF_SIZE(pvSrcHandle, eType)) // chunk is large than total buffer size
                    {
                        // skip audio chunk
                        //  to do: error handle
                        //AVI_SP_TRACE_PARSER_ERROR(0);
                        //return PROVIDER_ERROR_NOT_SUPPORT;
                        
                        fgLargeChunk = KAL_TRUE;
                        fgUpdateBufAddr = KAL_FALSE;                         
                    }
                }                            
            }        
            else if (eType == SOURCE_PROVIDER_PORT_VIDEO &&
                         (u4Type == AVI_SP_TAG_XXDB_STREAM_TYPE || u4Type == AVI_SP_TAG_XXDC_STREAM_TYPE)
                       )
            {
                // check chunk size
                // large than 
                if (u4FixedSize>AVI_SP_VIDEO_MIN_FETCH_SIZE)
                {
                    if (u4FixedSize+8 > prSrcAPI->SPFN_BITSTREAM_BUF_SIZE(pvSrcHandle, eType)) // chunk is large than total buffer size
                    {
                        // skip audio chunk
                        //  to do: error handle
                        //AVI_SP_TRACE_PARSER_ERROR(0);
                        //return PROVIDER_ERROR_NOT_SUPPORT;

                        fgLargeChunk = KAL_TRUE;
                    }
                }
            }
            else
            {
                ASSERT(0);
            }

            // fetch data is too few, 
            if (u4FixedSize > (u4BufEndAddr - (kal_uint32)pu1Buf) && (fgLargeChunk == KAL_FALSE))
            {
                prNoIdnxCtrl->eFetch = AVI_SP_FETCH_FORCE;
                prNoIdnxCtrl->u4FetchSize = u4FixedSize+8;
                pu1Buf = pu1Buf -8;
                break;
            }

            // set frame info
            prSrcAPI->SPFN_MEM_SET((void *)&rFrameInfo, 0, sizeof(rFrameInfo));
            rFrameInfo.pu1Addr = pu1Buf;
            rFrameInfo.u4FrameSize = u4Temp;
            rFrameInfo.u8Timestamp = _AviParserRefTiem2RealTime(eType, prAviProviderMgr, prNoIdnxCtrl->u4CurRefEndTime);

            if (rFrameInfo.u8Timestamp > prControl->u8EndTime)
            {
                prControl->eEof = AVI_SP_EOF_WAIT_SEND;
                return PROVIDER_ERROR_NOT_FINISH;
            }

            if (eType == SOURCE_PROVIDER_PORT_AUDIO)
            {
                if (fgLargeChunk == KAL_TRUE)
                {
                    rFrameInfo.pu1Addr = (kal_uint8 *)0;
                    rFrameInfo.u4FrameSize = 0;
                    rFrameInfo.fgSilent = KAL_TRUE;
                }
                rFrameInfo.fgKeyFrame = KAL_TRUE;
            }
            else
            {               
                if (fgLargeChunk == KAL_TRUE)
                {
                    rFrameInfo.u4FrameSize = u4BufEndAddr - (kal_uint32)pu1Buf;
                }
                
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
                if (prParser->rVideoInfo[u4SelectNum].eCodecType == MEDIA_CODEC_VID_H264)
                {
                    rFrameInfo.u4PayloadNum = 1;
                    rFrameInfo.u4PayloadSize = 8;
                    rPayload.u4Address = (kal_uint32)rFrameInfo.pu1Addr;
                    rPayload.u4Length = rFrameInfo.u4FrameSize;
                    rFrameInfo.pu1Payload = (kal_uint8 *)&rPayload;
                }
#endif 
                //rFrameInfo.fgKeyFrame = (prListItem->u4Flag&AVI_SP_IF_KEY_FRAME)?(KAL_TRUE):(KAL_FALSE);
            }

            // sned to source
            if (u4Temp != 0)
            {
                if (prSrcAPI->SPFN_ADD_ONE_DATA(pvSrcHandle, eType, &rFrameInfo) == PROVIDER_ERROR_WAIT_RESOURCE)
                {
                    //prControl->u4BuffStartAddr = (kal_uint32)pu1Buf -8; // un-uese buffer start address
                    //prControl->u4BuffSize = u4BufEndAddr - prControl->u4BuffStartAddr; // un-uese buffer size         
                    //return PROVIDER_ERROR_WAIT_RESOURCE;
                    pu1Buf = pu1Buf -8; // un-uese buffer start address
                    eRet = PROVIDER_ERROR_WAIT_RESOURCE;
                    break;
                }

                // updata buffer write pointer
                if (fgUpdateBufAddr == KAL_TRUE)
                {
                    prSrcAPI->SPFN_BITSTREAM_BUF_UPDATA_ADD(pvSrcHandle, eType, (kal_uint32)(pu1Buf+rFrameInfo.u4FrameSize));
                }
            }

            // update ref end time
            if (prNoIdnxCtrl->fgVBR == KAL_TRUE)
            {                    
                prNoIdnxCtrl->u4CurRefEndTime++;
                u4Duration = 1;
            }
            else
            {
                prNoIdnxCtrl->u4CurRefEndTime += u4Temp;
                u4Duration = u4Temp;
            }

            if (prNoIdnxCtrl->u4CurRefEndTime>prSeekTable->u4RangeRefEndTime)
            {
                //
                if (eType == SOURCE_PROVIDER_PORT_VIDEO)
                {
                    // obtain frame type
                    if (_AviParserGetVideoFrameType(prParser->rVideoInfo[u4SelectNum].eCodecType, pu1Buf, rFrameInfo.u4FrameSize) == AVI_SP_FRAME_TYPE_I)
                    {
                        fgAdd2Table = KAL_TRUE;
                    }
                    else
                    {
                        fgAdd2Table = KAL_FALSE;
                        prSeekTable->u4RangeRefEndTime++;
                    }
                }
                else
                {
                    fgAdd2Table = KAL_TRUE;
                }

                if (fgAdd2Table == KAL_TRUE)
                {
                    _AviParserAddSeekTable(prAviProviderMgr, prSeekTable, u4Duration, 
                                                                          (u4FileAddr + (kal_uint32)pu1Buf -(kal_uint32)prControl->u4BuffStartAddr -8));
                }
                prSeekTable->u4LastFileAddr = u4FileAddr + (kal_uint32)pu1Buf -(kal_uint32)prControl->u4BuffStartAddr + u4FixedSize;
            }

            *pu4Time = (kal_uint32)(rFrameInfo.u8Timestamp - prControl->u8CurrentTime);
            prControl->u8CurrentTime = rFrameInfo.u8Timestamp;
            
            if (fgLargeChunk == KAL_TRUE)
            {
                #ifdef __VE_SP_AVI_LOG_HIGH__
                drv_trace4(AVI_SP_TRACE_HIGH_GROUP, AVI_SP_BIG_CHUNK, eType, (u4FileAddr + (kal_uint32)pu1Buf -(kal_uint32)prControl->u4BuffStartAddr), 
                                                                      u4Temp, (prNoIdnxCtrl->u4CurRefEndTime-u4Duration));
                #endif
                
                prNoIdnxCtrl->eFetch = AVI_SP_FETCH_SKIP;
                if (eType == SOURCE_PROVIDER_PORT_VIDEO)
                {
                    prNoIdnxCtrl->u4FetchSize = u4FixedSize - rFrameInfo.u4FrameSize;
                    pu1Buf = (kal_uint8 *)u4BufEndAddr;
                }
                else
                {
                    prNoIdnxCtrl->u4FetchSize = u4FixedSize+8;
                    pu1Buf = pu1Buf -8;
                }                 
                break;
            }
            
            pu1Buf += u4FixedSize;

            eRet = PROVIDER_ERROR_NOT_FINISH;
            break;
        }
        else // skip un-selected chunk
        {
            // fetch data is too few, 
            if (u4FixedSize > (u4BufEndAddr - (kal_uint32)pu1Buf))
            {
                prNoIdnxCtrl->eFetch = AVI_SP_FETCH_SKIP;
                prNoIdnxCtrl->u4FetchSize = u4FixedSize+8;
                pu1Buf = pu1Buf -8;
                break;
            }
            pu1Buf += u4FixedSize;
        }
    } while (1);

    prControl->u4BuffStartAddr = (kal_uint32)pu1Buf; // un-uese buffer start address
    prControl->u4BuffSize = u4BufEndAddr - prControl->u4BuffStartAddr; // un-uese buffer size         

#ifdef __VE_SP_AVI_LOG_LOW__
    if (eRet == PROVIDER_ERROR_NOT_FINISH)
    {
        drv_trace4(AVI_SP_TRACE_LOW_GROUP, AVI_SP_NO_IDX1_DEMUX_DATA, eType, rFrameInfo.u8Timestamp, (kal_uint32)pu1Buf, (u4BufEndAddr-(kal_uint32)pu1Buf));
    }
    else
    {
        drv_trace4(AVI_SP_TRACE_LOW_GROUP, AVI_SP_NO_IDX1_DEMUX_DATA2, eType, eRet, prNoIdnxCtrl->eFetch, prNoIdnxCtrl->u4FetchSize);
    }
#endif

    return eRet;

}

#endif

static AVI_SP_VBR_ENTRY_T _AviProviderSearchKeyFrame(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr,SP_SEARCH_DIR_T eDirect, SP_PORT_TYPE_T eType, kal_uint64 u8StartTime)
{
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    
    // can't seek
    if (prParser->u4IndexAddr == 0)
    {        
#ifdef __VE_SP_AVI_NON_IDX1_PLAYBACK__
        return _AviParserSearchKeyFrameNoIdx1(prAviProviderMgr, eDirect, eType, u8StartTime);
#else
        AVI_SP_VBR_ENTRY_T rTargetEnty = {0,0};
        rTargetEnty.u4Offset = 0;
        return rTargetEnty;
#endif        
    }
    else
    {
        return _AviParserSearchKeyFrameIdx1(prAviProviderMgr, eDirect, eType, u8StartTime);
    }
}

static PROVIDER_ERROR_T _AviProviderFillBuff(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, SP_PORT_TYPE_T eType)
{
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    AVI_SP_CONTROL_T *prControl;
    PROVIDER_ERROR_T eRet = PROVIDER_ERROR_NONE;

    if (eType == SOURCE_PROVIDER_PORT_AUDIO)
    {
        prControl = &prAviProviderMgr->rAudioControl;
    }
    else
    {
        prControl = &prAviProviderMgr->rVideoControl;
    }

    if (prControl->eEof != AVI_SP_EOF_NONE)
    {
        return PROVIDER_ERROR_NONE;
    }

    if (prParser->u4IndexAddr == 0)
    {        
#ifndef __VE_SP_AVI_NON_IDX1_PLAYBACK__
        ASSERT(0);
#else
        eRet = _AviProviderFillBuffNoIdx1(prAviProviderMgr, eType, prControl);
#endif
    }
    else // index support
    {
        eRet =  _AviProviderFillBuffIdx1(prAviProviderMgr, eType, prControl);
    }

    // To send eof when meet error
    if (eRet == PROVIDER_ERROR_DELAY_REPORT_WITH_EOF)
    {
        if (prParser->u4IndexAddr != 0)
        {
            VideoCoreCleanRingBuffer(&prControl->rList);
        }
        prControl->eEof = AVI_SP_EOF_WAIT_SEND;
        prControl->eError = PROVIDER_ERROR_DELAY_REPORT_WITH_EOF;
        eRet = PROVIDER_ERROR_NONE;
    }

    return eRet;
}

static PROVIDER_ERROR_T _AviProviderDemuxData(AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr, SP_PORT_TYPE_T eType, kal_uint32 *pu4Time)
{
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    void *pvSrcHandle = prAviProviderMgr->rSrcHandle.pvSourceHandle;
    SP_API_T *prSrcAPI = prAviProviderMgr->rSrcHandle.prSourceAPI;  
    AVI_SP_CONTROL_T *prControl;    
    SPIF_PROVIDER_FRAME_INFO_T rFrameInfo;    

    // assign variable
    if (eType == SOURCE_PROVIDER_PORT_AUDIO)
    {
        prControl = &prAviProviderMgr->rAudioControl;
    }
    else
    {
        prControl = &prAviProviderMgr->rVideoControl;
    }           

    // check whether send eof
    if (prControl->eEof == AVI_SP_EOF_DONE)
    {
        return PROVIDER_ERROR_NONE;
    }
    else if (prControl->eEof == AVI_SP_EOF_WAIT_SEND)
    {
        VIDEO_CORE_RING_BUFFER_MGR_T *prList = &prControl->rList;
        kal_bool fgSendEof = KAL_TRUE;
        
        if (prParser->u4IndexAddr != 0)
        {
            // avoid run this function when __VE_SP_AVI_NON_IDX1_PLAYBACK__ enable
            if (VideoCoreIsRingBufferEmpty(prList) == KAL_FALSE)
            {
                fgSendEof = KAL_FALSE;
            }
        }

        if (fgSendEof == KAL_TRUE)
        {
            prSrcAPI->SPFN_MEM_SET((void *)&rFrameInfo, 0, sizeof(rFrameInfo));
            
#ifdef __VE_SP_AVI_NON_IDX1_PLAYBACK__  
            if (prParser->u4IndexAddr == 0)
            {
                rFrameInfo.u8Timestamp = _AviParserRefTiem2RealTime(eType, prAviProviderMgr, prControl->rNoIndexCtrl.u4CurRefEndTime);
            }
            else
#endif
            {
                rFrameInfo.u8Timestamp = _AviParserRefTiem2RealTime(eType, prAviProviderMgr, prControl->rIndexStatus.u4CurrentRefEndTime);
            }
            
            rFrameInfo.fgEof = KAL_TRUE;

            // sned to source
            if (prSrcAPI->SPFN_ADD_ONE_DATA(pvSrcHandle, eType, &rFrameInfo) == PROVIDER_ERROR_WAIT_RESOURCE)
            {
                return PROVIDER_ERROR_WAIT_RESOURCE;
            }

            prControl->eEof = AVI_SP_EOF_DONE;

            #ifdef __VE_SP_AVI_LOG_LOW__
            drv_trace2(AVI_SP_TRACE_LOW_GROUP, AVI_SP_DEMUX_EOF, eType, rFrameInfo.u8Timestamp);
            #endif

            if (prControl->eError == PROVIDER_ERROR_DELAY_REPORT_WITH_EOF)
            {
                return prControl->eError;
            }
            else
            {
                return PROVIDER_ERROR_EOF;
            }
        }
    }

    if (prParser->u4IndexAddr == 0)
    {        
#ifndef __VE_SP_AVI_NON_IDX1_PLAYBACK__
        ASSERT(0);
        return PROVIDER_ERROR;
#else
        return _AviProviderDemuxDataNoIdx1(prAviProviderMgr, eType, prControl, pu4Time);
#endif    
    }
    else // index support
    {
        return _AviProviderDemuxDataIdx1(prAviProviderMgr, eType, prControl, pu4Time);
    }
}

static PROVIDER_ERROR_T _AviProviderParse(void *pvHandle, kal_uint32 *pu4Time, SP_PORT_TYPE_T eType)
{
    AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr = (AVI_SP_PROVIDER_CONTEXT_T *)pvHandle;
    AVI_SP_CONTROL_T *prControl = (eType == SOURCE_PROVIDER_PORT_VIDEO)?(&prAviProviderMgr->rVideoControl):(&prAviProviderMgr->rAudioControl);
    PROVIDER_ERROR_T rRet = PROVIDER_ERROR_NONE;
    
    if (pvHandle == NULL || pu4Time == NULL)
    {
        AVI_SP_TRACE_PARAMETER_ERROR((kal_uint32)pvHandle, (kal_uint32)pu4Time, 0);
        #ifdef __VE_SP_AVI_ASSERT__
        ASSERT(0);
        #endif
        return PROVIDER_ERROR;
    }

    switch (prControl->eState)
    {
    case AVI_SP_STATE_FILL_BUFF:
        rRet = _AviProviderFillBuff(prAviProviderMgr, eType);
        *pu4Time = 0;
        if (rRet != PROVIDER_ERROR_NONE)
        {
            return rRet;
        }
        else 
        {
            prControl->eState = AVI_SP_STATE_DEMUX_DATA;
        }
        break;
        
    case AVI_SP_STATE_DEMUX_DATA:
        rRet = _AviProviderDemuxData(prAviProviderMgr, eType, pu4Time);
        if (rRet != PROVIDER_ERROR_NONE)
        {
            return rRet;
        }
        else
        {
             prControl->eState = AVI_SP_STATE_FILL_BUFF;
        }
        break;
    }

#ifdef __VE_SP_AVI_LOG_FUNC__
    drv_trace4(AVI_SP_TRACE_FUNC_GROUP, AVI_SP_PARSE, eType, prControl->eState, rRet, (kal_uint32)pvHandle);
#endif
      
    return rRet;
}

static PROVIDER_ERROR_T _AviProviderInitSeekTable(AVI_SP_PARSER_INFO_T *prParser, void *pvSrcHandle, SP_API_T *prSrcAPI, SP_PORT_TYPE_T eType)
{
    AVI_SP_SEEK_TABLE_T *prSeekTable; 

    if (eType == SOURCE_PROVIDER_PORT_VIDEO)
    {
        prSeekTable = &prParser->rVideoSeekTable;
    }
    else
    {
        prSeekTable = &prParser->rAudioSeekTable;
    }
    
    prSeekTable->u4MaxEntries = AVI_SP_INDEX_MAX_ENTRIES;
    prSeekTable->u4Granularity = 1;
    if (prParser->u4IndexAddr == 0)
    {
        prSeekTable->u4LastFileAddr = (prParser->u4MoviAddr+4);
    }
    else
    {
        prSeekTable->u4LastFileAddr = prParser->u4IndexAddr;
    }
    // allocate memory for Video index
    prSeekTable->pvEntry = prSrcAPI->SPFN_MALLOC_CLA(pvSrcHandle, 
                                                     sizeof(AVI_SP_VBR_ENTRY_T)*AVI_SP_INDEX_MAX_ENTRIES,
                                                     KAL_FALSE);  
    if (prSeekTable->pvEntry == NULL)
    {
        AVI_SP_TRACE_PARAMETER_ERROR(eType, 0, 0);
        return PROVIDER_ERROR;
    }
    return PROVIDER_ERROR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  AviProviderOpen
 * DESCRIPTION
 *  This function is used to open avi provider.
 * PARAMETERS
 *  prHandle             [IN]     the handle of the avi provider.
 *  prInfo             [IN]     the open file information.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
static PROVIDER_ERROR_T AviProviderOpen(void *pvHandle, SPIF_PROVIDER_OPEN_INFO_T *prInfo)
{
    AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr = (AVI_SP_PROVIDER_CONTEXT_T *)pvHandle;
    void *pvSrcHandle = prAviProviderMgr->rSrcHandle.pvSourceHandle;
    SP_API_T *prSrcAPI = prAviProviderMgr->rSrcHandle.prSourceAPI;
    AVI_SP_FILE_T *prFile = &prAviProviderMgr->rFile;
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    AVI_SP_MEM_INFO_T *prMemInfo = &prAviProviderMgr->rMemInfo;
    FSAL_Status eRet;
    kal_int32 i4DrmRet;
    SPIF_OPEN_INFO_T rOpenFile;
    kal_uint32 u4FileSize;
    kal_uint32 u4I;
    //kal_int8 *pu1TempBuf;

    if (pvHandle == NULL || prInfo == NULL)
    {
        AVI_SP_TRACE_PARAMETER_ERROR((kal_uint32)pvHandle, (kal_uint32)prInfo, 0);
        #ifdef __VE_SP_AVI_ASSERT__
        ASSERT(0);
        #endif
        return PROVIDER_ERROR;
    }

#ifdef __VE_SP_AVI_LOG_FUNC__
    drv_trace4(AVI_SP_TRACE_FUNC_GROUP, AVI_SP_OPEN, prInfo->eOpenTrack, prInfo->eOpenType, 0, (kal_uint32)pvHandle);
#endif

    prAviProviderMgr->rOpenInfo = *prInfo;

    rOpenFile.prFileHandle = &prFile->rFsalFileInfo;
    rOpenFile.pu1Data = prInfo->pu1Data;
    rOpenFile.u4Size = prInfo->u4DataSize;

    if (prInfo->eOpenType != MED_MODE_BUFFER)
    {
        rOpenFile.fgBufMode = KAL_FALSE;

        rOpenFile.fgSetBuffer = KAL_TRUE;
        prFile->pu1FileInfoBuf = (void *)prSrcAPI->SPFN_MALLOC_CLA(pvSrcHandle, AVI_SP_FASL_FILE_INFO_BUF, KAL_FALSE);
        if (prFile->pu1FileInfoBuf == NULL)
        {
            AVI_SP_TRACE_PARAMETER_ERROR(0, 0, 0);
            return PROVIDER_ERROR;
        }
        rOpenFile.pu1SetBuf = prFile->pu1FileInfoBuf ;
        rOpenFile.u4SetBufSize = AVI_SP_FASL_FILE_INFO_BUF;
        
        rOpenFile.fgSetSeekHint = KAL_FALSE;        

        // open file 
        if (prSrcAPI->SPFN_BASE_FILE_OPEN(&rOpenFile) != PROVIDER_ERROR_NONE)
        {
            return PROVIDER_ERROR;
        }

        // get file size
        eRet = FSAL_GetFileSize(&prFile->rFsalFileInfo, &u4FileSize);
        if (eRet != FSAL_OK)
        {
            AVI_SP_TRACE_FSAL_ERROR(eRet);
            goto OPEN_ERR_HANDLE_1;
            //return PROVIDER_ERROR;
        }

        // prepare seek hint
        #ifdef __LOW_COST_SUPPORT_ULC__
        prFile->prSeekHintBuf = NULL;
        #else
        prFile->prSeekHintBuf = (FS_FileLocationHint *)prSrcAPI->SPFN_MALLOC_CLA(pvSrcHandle, (AVI_SP_FASL_SEEK_HINT_IDX * sizeof(FS_FileLocationHint)), KAL_FALSE);
        if (prFile->prSeekHintBuf == NULL)
        {
            AVI_SP_TRACE_PARAMETER_ERROR(0, 0, 0);
            goto OPEN_ERR_HANDLE_1;
        }      
        for (u4I = 0; u4I < AVI_SP_FASL_SEEK_HINT_IDX; u4I++)
        {
            prFile->prSeekHintBuf[u4I].Index = 
                (kal_uint32)((kal_uint64)u4FileSize * (kal_uint64)(u4I + 1) / (kal_uint64)(AVI_SP_FASL_SEEK_HINT_IDX + 1));
        }

        i4DrmRet = FSAL_SetSeekHint(&prFile->rFsalFileInfo, AVI_SP_FASL_SEEK_HINT_IDX, (void *)prFile->prSeekHintBuf);
        //i4DrmRet = DRM_set_seek_hint(prFile->rFsalFileInfo.hFile, AVI_SP_FASL_SEEK_HINT_IDX, prFile->prSeekHintBuf);
        if (i4DrmRet < 0)
        {
            AVI_SP_TRACE_FSAL_ERROR(i4DrmRet);
            goto OPEN_ERR_HANDLE_1;
        }
        #endif

        // save file size
        prAviProviderMgr->rOpenInfo.u4DataSize = u4FileSize;
    }
    else
    {
        rOpenFile.fgBufMode = KAL_TRUE;

        // open file 
        if (prSrcAPI->SPFN_BASE_FILE_OPEN(&rOpenFile) != PROVIDER_ERROR_NONE)
        {
            return PROVIDER_ERROR;
        }
    }

    prMemInfo->pu1TempBuf = (kal_uint8 *)prSrcAPI->SPFN_MALLOC_CLA(pvSrcHandle, AVI_SP_TEMP_BUF, KAL_FALSE);
    if (prMemInfo->pu1TempBuf == NULL)
    {
        AVI_SP_TRACE_PARAMETER_ERROR(0, 0, 0);
        goto OPEN_ERR_HANDLE_1;
    }

    // parser header
    if (_AviParserHeaderParse(prAviProviderMgr, &prFile->rFsalFileInfo, prAviProviderMgr->rOpenInfo.u4DataSize, prMemInfo->pu1TempBuf) != PROVIDER_ERROR_NONE)
    {
        goto OPEN_ERR_HANDLE_1;
    }

    //prSrcAPI->SPFN_FREE_CLA(pvSrcHandle, (void *)pu1TempBuf);

    if (prParser->u4MoviAddr == 0
#ifndef __VE_SP_AVI_NON_IDX1_PLAYBACK__ 
         || (prParser->u4IndexAddr == 0)
#endif         
       )
    {
        AVI_SP_TRACE_PARAMETER_ERROR(prParser->u4MoviAddr, prParser->u4IndexAddr, 0);
        goto OPEN_ERR_HANDLE_1;
    }

    // allocate resource
    if (!(prInfo->eOpenTrack & SOURCE_PROVIDER_TRACK_META))
    {
        if ((prInfo->eOpenTrack & SOURCE_PROVIDER_TRACK_VIDEO) &&
             prParser->u4VideoNum != 0
           )
        {
            prAviProviderMgr->rVideoUserSetting.fgEnable = KAL_TRUE;
            
            rOpenFile.prFileHandle = &prFile->rFsalVideo;
            if (prInfo->eOpenType != MED_MODE_BUFFER)
            {
                rOpenFile.fgSetBuffer = KAL_FALSE;
                #ifdef __LOW_COST_SUPPORT_ULC__
                rOpenFile.fgSetSeekHint = KAL_FALSE; 
                #else
                rOpenFile.fgSetSeekHint = KAL_TRUE; 
                rOpenFile.prSeekHint = prFile->prSeekHintBuf;
                #endif
                rOpenFile.u4SetHintSize = AVI_SP_FASL_SEEK_HINT_IDX;
            }
         
            if (prSrcAPI->SPFN_BASE_FILE_OPEN(&rOpenFile) != PROVIDER_ERROR_NONE)
            {
                goto OPEN_ERR_HANDLE_1;
            }

            if (prParser->u4IndexAddr != 0)
            {
                rOpenFile.prFileHandle = &prFile->rFsalVideoIdx;
                if (prInfo->eOpenType != MED_MODE_BUFFER)
                {
                    rOpenFile.fgSetBuffer = KAL_TRUE;
                    prFile->pu1VideoIdxBuf= (void *)prSrcAPI->SPFN_MALLOC_CLA(pvSrcHandle, AVI_SP_FASL_INDEX_BUF, KAL_FALSE);
                    if (prMemInfo->pu1TempBuf == NULL)
                    {
                        AVI_SP_TRACE_PARAMETER_ERROR(0, 0, 0);
                        FSAL_Close(&prFile->rFsalVideo);
                        goto OPEN_ERR_HANDLE_1;
                    }
                    rOpenFile.pu1SetBuf = prFile->pu1VideoIdxBuf;
                    rOpenFile.u4SetBufSize = AVI_SP_FASL_INDEX_BUF;
                    //rOpenFile.fgSetSeekHint = KAL_TRUE; 
                    //rOpenFile.prSeekHint = prFile->prSeekHintBuf;
                    //rOpenFile.u4SetHintSize = AVI_SP_FASL_SEEK_HINT_IDX;
                }
             
                if (prSrcAPI->SPFN_BASE_FILE_OPEN(&rOpenFile) != PROVIDER_ERROR_NONE)
                {
                    FSAL_Close(&prFile->rFsalVideo);
                    goto OPEN_ERR_HANDLE_1;
                }     

                prMemInfo->prVListItem = prSrcAPI->SPFN_MALLOC_CLA(pvSrcHandle, AVI_SP_VIDEO_LIST_ITEM_NUM*sizeof(AVI_SP_INDEX_T), KAL_FALSE);
                if (prMemInfo->prVListItem == NULL)
                {
                    AVI_SP_TRACE_PARAMETER_ERROR(0, 0, 0);
                    goto OPEN_ERR_HANDLE_2;
                }
            }

            //if (prParser->u4IndexAddr == 0)
            {
                if (_AviProviderInitSeekTable(prParser, pvSrcHandle, prSrcAPI, SOURCE_PROVIDER_PORT_VIDEO) != PROVIDER_ERROR_NONE)
                {
                    goto OPEN_ERR_HANDLE_2;
                }    
            }
        }

        if ((prInfo->eOpenTrack & SOURCE_PROVIDER_TRACK_AUDIO) &&
             prParser->u4AudioNum != 0
           )
        {
            prAviProviderMgr->rAudioUserSetting.fgEnable = KAL_TRUE;
    
            rOpenFile.prFileHandle = &prFile->rFsalAudio;
            if (prInfo->eOpenType != MED_MODE_BUFFER)
            {
                rOpenFile.fgSetBuffer = KAL_FALSE;
                #ifdef __LOW_COST_SUPPORT_ULC__
                rOpenFile.fgSetSeekHint = KAL_FALSE; 
                #else
                rOpenFile.fgSetSeekHint = KAL_TRUE; 
                rOpenFile.prSeekHint = prFile->prSeekHintBuf;
                #endif
                rOpenFile.u4SetHintSize = AVI_SP_FASL_SEEK_HINT_IDX;
            }
         
            if (prSrcAPI->SPFN_BASE_FILE_OPEN(&rOpenFile) != PROVIDER_ERROR_NONE)
            {
                goto OPEN_ERR_HANDLE_2;
            }

            if (prParser->u4IndexAddr != 0)
            {
                rOpenFile.prFileHandle = &prFile->rFsalAudioIdx;
                if (prInfo->eOpenType != MED_MODE_BUFFER)
                {
                    rOpenFile.fgSetBuffer = KAL_TRUE;
                    prFile->pu1AudioIdxBuf= (void *)prSrcAPI->SPFN_MALLOC_CLA(pvSrcHandle, AVI_SP_FASL_INDEX_BUF, KAL_FALSE);
                    if (prFile->pu1AudioIdxBuf == NULL)
                    {
                        AVI_SP_TRACE_PARAMETER_ERROR(0, 0, 0);
                        FSAL_Close(&prFile->rFsalAudio);
                        goto OPEN_ERR_HANDLE_2;
                    }
                    rOpenFile.pu1SetBuf = prFile->pu1AudioIdxBuf;
                    rOpenFile.u4SetBufSize = AVI_SP_FASL_INDEX_BUF;
                    //rOpenFile.fgSetSeekHint = KAL_TRUE; 
                    //rOpenFile.prSeekHint = prFile->prSeekHintBuf;
                    //rOpenFile.u4SetHintSize = AVI_SP_FASL_SEEK_HINT_IDX;
                }
             
                if (prSrcAPI->SPFN_BASE_FILE_OPEN(&rOpenFile) != PROVIDER_ERROR_NONE)
                {
                    FSAL_Close(&prFile->rFsalAudio);
                    goto OPEN_ERR_HANDLE_2;
                }

                prMemInfo->prAListItem = prSrcAPI->SPFN_MALLOC_CLA(pvSrcHandle, AVI_SP_AUDIO_LIST_ITEM_NUM*sizeof(AVI_SP_INDEX_T), KAL_FALSE);
                if (prMemInfo->prAListItem == NULL)
                {
                    AVI_SP_TRACE_PARAMETER_ERROR(0, 0, 0);
                    goto OPEN_ERR_HANDLE_3;
                }
            }

            //if (prParser->u4IndexAddr == 0)
            {
                if (_AviProviderInitSeekTable(prParser, pvSrcHandle, prSrcAPI, SOURCE_PROVIDER_PORT_AUDIO) != PROVIDER_ERROR_NONE)
                {
                    goto OPEN_ERR_HANDLE_3;
                }  
            }      
        }
    }
    
    return PROVIDER_ERROR_NONE;

OPEN_ERR_HANDLE_3:
    if ((prInfo->eOpenTrack & SOURCE_PROVIDER_TRACK_AUDIO) &&
         prParser->u4AudioNum != 0)
    {
        FSAL_Close(&prFile->rFsalAudio);
        if (prParser->u4IndexAddr != 0)
        {
            FSAL_Close(&prFile->rFsalAudioIdx);
        }
    } 

OPEN_ERR_HANDLE_2:
    if ((prInfo->eOpenTrack & SOURCE_PROVIDER_TRACK_VIDEO) &&
         prParser->u4VideoNum != 0)
    {
        FSAL_Close(&prFile->rFsalVideo);
        if (prParser->u4IndexAddr != 0)
        {
            FSAL_Close(&prFile->rFsalVideoIdx);
        }
    }    

OPEN_ERR_HANDLE_1:    
    //close file
    FSAL_Close(&prFile->rFsalFileInfo);

    return PROVIDER_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  AviProviderClose
 * DESCRIPTION
 *  This function is used to close avi provider
 * PARAMETERS
 *  pvHandle             [IN]     the handle of the avi provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/                                                      
static PROVIDER_ERROR_T AviProviderClose(void *pvHandle)
{
    AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr = (AVI_SP_PROVIDER_CONTEXT_T *)pvHandle;
    void *pvSrcHandle = prAviProviderMgr->rSrcHandle.pvSourceHandle;
    SP_API_T *prSrcAPI = prAviProviderMgr->rSrcHandle.prSourceAPI;    
    AVI_SP_FILE_T *prFile = &prAviProviderMgr->rFile;
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    AVI_SP_MEM_INFO_T *prMemInfo = &prAviProviderMgr->rMemInfo;
    SP_TRACK_T eOpenTrack = prAviProviderMgr->rOpenInfo.eOpenTrack;

    if (pvHandle == NULL)
    {
        AVI_SP_TRACE_PARAMETER_ERROR((kal_uint32)pvHandle, 0, 0);
        #ifdef __VE_SP_AVI_ASSERT__
        ASSERT(0);
        #endif
        return PROVIDER_ERROR;
    }

#ifdef __VE_SP_AVI_LOG_FUNC__
        drv_trace1(AVI_SP_TRACE_FUNC_GROUP, AVI_SP_CLOSE, (kal_uint32)pvHandle);
#endif

    //close file
    FSAL_Close(&prFile->rFsalFileInfo);
    if ((eOpenTrack & SOURCE_PROVIDER_TRACK_VIDEO) &&
         prParser->u4VideoNum != 0)
    {
        FSAL_Close(&prFile->rFsalVideo);
        if (prParser->u4IndexAddr != 0)
        {
            FSAL_Close(&prFile->rFsalVideoIdx);
        }
    }

    if ((eOpenTrack & SOURCE_PROVIDER_TRACK_AUDIO) &&
         prParser->u4AudioNum != 0
       )
    {
        FSAL_Close(&prFile->rFsalAudio);
        if (prParser->u4IndexAddr != 0)
        {
            FSAL_Close(&prFile->rFsalAudioIdx);
        }    
    }

    // FASL
    prSrcAPI->SPFN_FREE_CLA(pvSrcHandle, (void *)prFile->prSeekHintBuf);
    prSrcAPI->SPFN_FREE_CLA(pvSrcHandle, (void *)prFile->pu1FileInfoBuf);
    prSrcAPI->SPFN_FREE_CLA(pvSrcHandle, (void *)prFile->pu1VideoIdxBuf);
    prSrcAPI->SPFN_FREE_CLA(pvSrcHandle, (void *)prFile->pu1AudioIdxBuf);

    // seek table    
    prSrcAPI->SPFN_FREE_CLA(pvSrcHandle, (void *)prParser->rVideoSeekTable.pvEntry);
    prSrcAPI->SPFN_FREE_CLA(pvSrcHandle, (void *)prParser->rAudioSeekTable.pvEntry);  

    // temp buffer
    prSrcAPI->SPFN_FREE_CLA(pvSrcHandle, (void *)prMemInfo->pu1TempBuf);

    // index list
    prSrcAPI->SPFN_FREE_CLA(pvSrcHandle, (void *)prMemInfo->prVListItem);
    prSrcAPI->SPFN_FREE_CLA(pvSrcHandle, (void *)prMemInfo->prAListItem);

    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  AviProviderInit
 * DESCRIPTION
 *  This function is used to Initialize avi provider.
 * PARAMETERS
 *  prHandle             [IN]     the handle of the avi provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/         
static PROVIDER_ERROR_T AviProviderInit(void *pvHandle)
{
    AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr = (AVI_SP_PROVIDER_CONTEXT_T *)pvHandle;
    SP_API_T *prSrcAPI = prAviProviderMgr->rSrcHandle.prSourceAPI;      
    kal_uint32 u4Size;

    if (pvHandle == NULL)
    {
        AVI_SP_TRACE_PARAMETER_ERROR((kal_uint32)pvHandle, 0, 0);
        #ifdef __VE_SP_AVI_ASSERT__
        ASSERT(0);
        #endif    
        return PROVIDER_ERROR;
    }

#ifdef __VE_SP_AVI_LOG_FUNC__
    drv_trace1(AVI_SP_TRACE_FUNC_GROUP, AVI_SP_INIT, (kal_uint32)pvHandle);
#endif

    u4Size = sizeof(AVI_SP_CONTROL_T);
    prSrcAPI->SPFN_MEM_SET((void *)&prAviProviderMgr->rAudioControl, 0, u4Size);
    prSrcAPI->SPFN_MEM_SET((void *)&prAviProviderMgr->rVideoControl, 0, u4Size);
    
    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  AviProviderDeInit
 * DESCRIPTION
 *  This function is used to de-initialize avi provider.
 * PARAMETERS
 *  prHandle             [IN]     the handle of the avi provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/   
static PROVIDER_ERROR_T AviProviderDeInit(void *pvHandle)
{
    //AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr = (AVI_SP_PROVIDER_CONTEXT_T *)pvHandle;    
    
    if (pvHandle == NULL)
    {
        AVI_SP_TRACE_PARAMETER_ERROR((kal_uint32)pvHandle, 0, 0);
        #ifdef __VE_SP_AVI_ASSERT__
        ASSERT(0);
        #endif
        return PROVIDER_ERROR;
    }   

#ifdef __VE_SP_AVI_LOG_FUNC__
    drv_trace1(AVI_SP_TRACE_FUNC_GROUP, AVI_SP_DEINIT, (kal_uint32)pvHandle);
#endif

    //Do nothing.

    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  AviProviderGetParameter
 * DESCRIPTION
 *  This function is used to get parameter from mp4 provider.
 * PARAMETERS
 *  prHandle             [IN]     the pointer of the buffer in the file beginning.
 *  eCmd             [IN]     the command which used to get parameter.
 *  pParam             [IN] the parameter which source want to get from mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
static PROVIDER_ERROR_T AviProviderGetParameter(void *pvHandle, PROVIDER_PARAM_TYPE_T eCmd, void * pParam)
{
    AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr = (AVI_SP_PROVIDER_CONTEXT_T *)pvHandle;    
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    //SP_API_T *prSrcAPI = prAviProviderMgr->rSrcHandle.prSourceAPI;
    PROVIDER_ERROR_T eError = PROVIDER_ERROR_NONE;
        
    if (pvHandle == NULL)
    {
        AVI_SP_TRACE_PARAMETER_ERROR((kal_uint32)pvHandle, 0, 0);
        #ifdef __VE_SP_AVI_ASSERT__
        ASSERT(0);
        #endif
        return PROVIDER_ERROR;
    }   

    switch (eCmd)
    {
    case PROVIDER_PARAM_VID_STREAM_INFO:
        {
            SPIF_STREAM_INFO_T *prStreamInfo = (SPIF_STREAM_INFO_T *)pParam;
            if (prParser->u4VideoNum != 0)
            {
                prStreamInfo->fgSupport = KAL_TRUE;
                prStreamInfo->u4Num = prParser->u4VideoNum;
                prStreamInfo->pvStreamInfo = &prParser->rVideoInfo;                              
            }
            else
            {
                prStreamInfo->fgSupport = KAL_FALSE;                  
            }
            
            #ifdef __VE_SP_AVI_LOG_HIGH__
            {
                SPIF_VIDEO_STREAM_INFO_T *prVStreamInfo = &prParser->rVideoInfo[0];
                drv_trace8(AVI_SP_TRACE_HIGH_GROUP, AVI_SP_GET_VIDEO_STREAM_INFO, prStreamInfo->fgSupport, prStreamInfo->u4Num, (kal_uint32)prStreamInfo->pvStreamInfo,
                                                                                  prVStreamInfo->u4StreamIndex, prVStreamInfo->eCodecType, prVStreamInfo->u8Duration,
                                                                                  prVStreamInfo->u4Width, prVStreamInfo->u4Height);
            }
            #endif             
        }
        break;
        
    case PROVIDER_PARAM_AUD_STREAM_INFO:
        {
            SPIF_STREAM_INFO_T *prStreamInfo = (SPIF_STREAM_INFO_T *)pParam;
            if (prParser->u4AudioNum != 0)
            {
                prStreamInfo->fgSupport = KAL_TRUE;
                prStreamInfo->u4Num = prParser->u4VideoNum;
                prStreamInfo->pvStreamInfo = &prParser->rAudioInfo;                     
            }
            else
            {
                prStreamInfo->fgSupport = KAL_FALSE;                  
            }  

            #ifdef __VE_SP_AVI_LOG_HIGH__
            {
                SPIF_AUDIO_STREAM_INFO_T *prAStreamInfo = &prParser->rAudioInfo[0];
                drv_trace8(AVI_SP_TRACE_HIGH_GROUP, AVI_SP_GET_AUDIO_STREAM_INFO, prStreamInfo->fgSupport, prStreamInfo->u4Num, (kal_uint32)prStreamInfo->pvStreamInfo,
                                                                                  prAStreamInfo->u4StreamIndex, prAStreamInfo->eCodecType, prAStreamInfo->u8Duration,
                                                                                  prAStreamInfo->u4SampleRate, prAStreamInfo->fgAddHeader);
            }
            #endif              
        }
        break;
        
#ifdef __VE_SUBTITLE_SUPPORT__
    case PROVIDER_PARAM_SUBS_STREAM_INFO:
        {
            SPIF_STREAM_INFO_T *prStreamInfo = (SPIF_STREAM_INFO_T *)pParam;
            prStreamInfo->fgSupport = KAL_FALSE;
        }
        break;
#endif
        
    case PROVIDER_PARAM_META_DATA:
        {
            //SPIF_META_DATA_T *prFileMetaData = (SPIF_META_DATA_T *)pParam;
            //prSrcAPI->SPFN_MEM_SET(pParam, 0, sizeof(SPIF_META_DATA_T));
        }
        break;
        
    case PROVIDER_PARAM_META_CAPABILITY:
        {
            SP_CAPABILITY_T *peCapabiltiy = (SP_CAPABILITY_T *)pParam;

#ifndef __VE_SP_AVI_NON_IDX1_PLAYBACK__
            if (prParser->u4IndexAddr != 0)
#endif                
            {
                *peCapabiltiy |= SOURCE_PROVIDER_SEEK;
            }

            #ifdef __VE_SP_AVI_LOG_HIGH__
            drv_trace1(AVI_SP_TRACE_HIGH_GROUP, AVI_SP_GET_CAPABILITY, *peCapabiltiy);
            #endif    
        }
        break;
    case PROVIDER_PARAM_KEY_FRAME_TIME:
        {
            SPIF_KEY_FRAME_TIME_T *prKeyFrameTime = (SPIF_KEY_FRAME_TIME_T *)pParam;
            AVI_SP_VBR_ENTRY_T rEntry;

            if ((prParser->u4VideoNum == 0 && prKeyFrameTime->ePort == SOURCE_PROVIDER_PORT_VIDEO) ||
                (prParser->u4AudioNum == 0 && prKeyFrameTime->ePort == SOURCE_PROVIDER_PORT_AUDIO))
            {
                rEntry.u4ChunkIdx = 0;
                rEntry.u4Offset   = 0;                           
            }
            else
            {
                rEntry = _AviProviderSearchKeyFrame(prAviProviderMgr, prKeyFrameTime->eDirect, prKeyFrameTime->ePort, prKeyFrameTime->u8StartTime);
            }

            if (prParser->fgAbort[prKeyFrameTime->ePort] == KAL_TRUE)
            {
                //prParser->fgAbort[prKeyFrameTime->ePort] = KAL_FALSE;
                eError = PROVIDER_ERROR_TERMINATE;
            }
            else if (rEntry.u4Offset != 0)
            {
                prKeyFrameTime->u8KeyFrameTime = _AviParserRefTiem2RealTime(prKeyFrameTime->ePort, prAviProviderMgr, rEntry.u4ChunkIdx);                            

                if (prKeyFrameTime->ePort == SOURCE_PROVIDER_PORT_AUDIO)
                {
                    if ((prKeyFrameTime->u8StartTime >= prParser->rAudioInfo[prAviProviderMgr->rAudioUserSetting.u4SelectNum].u8Duration) &&
                        (prKeyFrameTime->u8StartTime > _AviParserRefTiem2RealTime(SOURCE_PROVIDER_PORT_AUDIO, prAviProviderMgr, prParser->rAudioSeekTable.u4RangeRefEndTime)))
                    {
                        prKeyFrameTime->u8KeyFrameTime = prKeyFrameTime->u8StartTime;
                    }
                }
            }
            else
            {         
                eError = PROVIDER_ERROR;
            }

            #ifdef __VE_SP_AVI_LOG_HIGH__
            drv_trace4(AVI_SP_TRACE_HIGH_GROUP, AVI_SP_GET_KEY_FRAME_TIME, prKeyFrameTime->u8StartTime, prKeyFrameTime->u8KeyFrameTime, rEntry.u4ChunkIdx, rEntry.u4Offset);
            #endif  
        }
        break;
        
    //case PROVIDER_PARAM_TIME_TO_FRAME:
        //eError = PROVIDER_ERROR;   // we don't need support.
        //break;
            
    //case PROVIDER_PARAM_FRAME_TO_TIME:
        //eError = PROVIDER_ERROR;   // we don't need support.
        //break;
            
    case PROVIDER_PARAM_DRM_FSAL:
        {
            SPIF_DRM_INFO_T *prDrmInfo = (SPIF_DRM_INFO_T *)pParam;

            prDrmInfo->file_handle = (kal_int32)(&prAviProviderMgr->rFile.rFsalFileInfo);
        }
        break;

#ifdef __VE_VIDEO_CLIPPER_SUPPORT__            
    case PROVIDER_PARAM_MTK_FILE:
        {
            kal_bool *pfgMtkFile = (kal_bool *)pParam;

            *pfgMtkFile = prParser->fgMtkFile;
        }
        break;
#endif        
            
#ifdef __VE_PARSE_TRANSFORMATION_INFO__
    case PROVIDER_PARAM_TRANSFORMATION_INFO:
        {
            SPIF_TRANSFORMATION_INFO_T *prtransInfo =  (SPIF_TRANSFORMATION_INFO_T *)pParam;
            *prtransInfo = prParser->rTransformation;
        }
        break;
#endif        
            
    default:
        eError = PROVIDER_ERROR;   // we don't need support.
        break;
    }

#ifdef __VE_SP_AVI_LOG_FUNC__
    drv_trace4(AVI_SP_TRACE_FUNC_GROUP, AVI_SP_GET_PARAM, eCmd, eError, 0, (kal_uint32)pvHandle);
#endif

    return eError;
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderSetParameter
 * DESCRIPTION
 *  This function is used to set parameter to mp4 provider
 * PARAMETERS
 *  prHandle             [IN]     the pointer of the buffer in the file beginning.
 *  eCmd             [IN]     the command which used to set parameter.
 *  pParam             [OUT] the parameter which source want to set to mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
static PROVIDER_ERROR_T AviProviderSetParameter(void *pvHandle, PROVIDER_PARAM_TYPE_T eCmd, void * pParam)
{
    AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr = (AVI_SP_PROVIDER_CONTEXT_T *)pvHandle;    
    AVI_SP_PARSER_INFO_T *prParser = &prAviProviderMgr->rParser;
    AVI_SP_FILE_T *prFile = &prAviProviderMgr->rFile;
    SP_API_T *prSrcAPI = prAviProviderMgr->rSrcHandle.prSourceAPI;    
    PROVIDER_ERROR_T eError = PROVIDER_ERROR_NONE;

    if (pvHandle == NULL)
    {
        AVI_SP_TRACE_PARAMETER_ERROR((kal_uint32)pvHandle, 0, 0);
        return PROVIDER_ERROR;
    } 

    switch (eCmd)
    {
    case PROVIDER_PARAM_SEEK_TIME:
        {
            SPIF_SEEK_TIME_T *prSeekTime = (SPIF_SEEK_TIME_T *)pParam;
            AVI_SP_MEM_INFO_T *prMemInfo = &prAviProviderMgr->rMemInfo;
            AVI_SP_STREAM_HEADER_T *prStreamHeader;  
            AVI_SP_VBR_ENTRY_T rEntry;
            AVI_SP_IDX1_MGR_T *prIndexStatus;
            AVI_SP_CONTROL_T *prControl;
            AVI_SP_INDEX_T *prCurrentIndex;
            STFSAL * prFsal;
            kal_bool fgVBR;
            AVI_SP_INDEX_T *prListItem;
            kal_uint32 u4SelectNum, u4StreamIndex, u4RefTime, u4ListNum;

            // obtain key fram index
            rEntry = _AviProviderSearchKeyFrame(prAviProviderMgr, SOURCE_PROVIDER_SEARCH_BACKWARD, prSeekTime->eType, prSeekTime->u8StartTime);
            #ifdef __VE_SP_AVI_LOG_HIGH__
            {
                drv_trace4(AVI_SP_TRACE_HIGH_GROUP, AVI_SP_SET_FRAME_TIME, prSeekTime->eType,  prSeekTime->u8StartTime, rEntry.u4ChunkIdx, rEntry.u4Offset);
            }
            #endif  
            if (prParser->fgAbort[prSeekTime->eType] == KAL_TRUE)
            {
                //prParser->fgAbort[prSeekTime->ePort] = KAL_FALSE;
                eError = PROVIDER_ERROR_TERMINATE;
                break;
            }
            
            if (rEntry.u4Offset == 0)
            {
                AVI_SP_TRACE_PARAMETER_ERROR(prSeekTime->eType, prSeekTime->u8StartTime, 0);
                eError = PROVIDER_ERROR;
                break;
            }

            if (prSeekTime->eType == SOURCE_PROVIDER_PORT_AUDIO)
            {
                prControl = &prAviProviderMgr->rAudioControl;                     
                u4SelectNum = prAviProviderMgr->rAudioUserSetting.u4SelectNum;
                u4StreamIndex= prParser->rAudioInfo[u4SelectNum].u4StreamIndex;
                prStreamHeader = &prParser->rAudStreamHdr[u4SelectNum];                    
                
                if (prStreamHeader->sample_size == 0) //VBR
                {
                    fgVBR = KAL_TRUE;
                }
                else
                {
                    fgVBR = KAL_FALSE;
                }

                // avoid audio jump back     
                // 1. video duraton is large than audio duration, 2. seek excess audio duration
                if ((prSeekTime->u8StartTime >= prParser->rAudioInfo[u4SelectNum].u8Duration) &&
                    (prSeekTime->u8StartTime > _AviParserRefTiem2RealTime(SOURCE_PROVIDER_PORT_AUDIO, prAviProviderMgr, prParser->rAudioSeekTable.u4RangeRefEndTime)))
                {
                    prControl->eEof = AVI_SP_EOF_WAIT_SEND;
                    if (prParser->u4IndexAddr != 0)
                    {
                        VideoCoreInitRingBuffer(&prControl->rList, (kal_uint8 *)prMemInfo->prAListItem, 
                                                AVI_SP_AUDIO_LIST_ITEM_NUM, sizeof(AVI_SP_INDEX_T));
                    }
                    break;
                }
            }
            else
            {
                prControl = &prAviProviderMgr->rVideoControl;                    
                u4SelectNum = prAviProviderMgr->rVideoUserSetting.u4SelectNum;
                u4StreamIndex= prParser->rVideoInfo[u4SelectNum].u4StreamIndex;
                prStreamHeader = &prParser->rVidStreamHdr[u4SelectNum];
                fgVBR = KAL_TRUE;
            }     

            u4RefTime = rEntry.u4ChunkIdx;

            // set control variable
            prSrcAPI->SPFN_MEM_SET(prControl, 0, sizeof(AVI_SP_CONTROL_T));
            prControl->u8StartTime = prSeekTime->u8StartTime;
            prControl->u8EndTime = prSeekTime->u8EndTime;
            prControl->fgSendEof = prSeekTime->fgEndTimeSendEof;
            
            if (prParser->u4IndexAddr == 0)
            {
#ifdef __VE_SP_AVI_NON_IDX1_PLAYBACK__            
                AVI_SP_NO_INDEX_CTRL_T *prNoIdnxCtrl = &prControl->rNoIndexCtrl;

                if (prSeekTime->eType == SOURCE_PROVIDER_PORT_AUDIO)
                {
                    prFsal = &prFile->rFsalAudio;
                }
                else
                {
                    prFsal = &prFile->rFsalVideo;
                }
                
                prNoIdnxCtrl->fgVBR = fgVBR;
                prNoIdnxCtrl->eFetch = AVI_SP_FETCH_MIN;
                prNoIdnxCtrl->u4DataOffset = rEntry.u4Offset;
                prNoIdnxCtrl->u4CurRefEndTime = u4RefTime;

                // seek
                if(_AviParserSkipFileSize(prFsal, prNoIdnxCtrl->u4DataOffset , prAviProviderMgr->rOpenInfo.u4DataSize) == KAL_FALSE)
                {
                    eError = PROVIDER_ERROR;
                    break;
                }    
#endif
            }
            else
            {            
                if (prSeekTime->eType == SOURCE_PROVIDER_PORT_AUDIO)
                {
                    prFsal = &prFile->rFsalAudioIdx;
                    prListItem = prMemInfo->prAListItem;
                    u4ListNum = AVI_SP_AUDIO_LIST_ITEM_NUM;
                }
                else
                {
                    prFsal = &prFile->rFsalVideoIdx;
                    prListItem = prMemInfo->prVListItem;
                    u4ListNum = AVI_SP_VIDEO_LIST_ITEM_NUM;
                }            
                                         
                //prSrcAPI->SPFN_MEM_SET(prControl, 0, sizeof(AVI_SP_CONTROL_T));
                //prControl->u8StartTime = prSeekTime->u8StartTime;
                //prControl->u8EndTime = prSeekTime->u8EndTime;
                //prControl->fgSendEof = prSeekTime->fgEndTimeSendEof;

                // set index management
                prIndexStatus = &prControl->rIndexStatus;
                prIndexStatus->prFsal = prFsal;
                prIndexStatus->fgVBR = fgVBR;
                prIndexStatus->u4StreamNum = u4StreamIndex;
                prIndexStatus->u4EntryOffset = rEntry.u4Offset;
                prIndexStatus->u4CurrentRefTime = u4RefTime;
                prIndexStatus->u4CurrentRefEndTime = u4RefTime;
                prIndexStatus->u4IndexEndAddr = prParser->u4IndexEndAddr;
                prIndexStatus->u4AdjustSize = prParser->u4MoviOffset + AVI_SP_MOVI_CHUNK_OVERHEAD;
              
                // seek
                if(_AviParserSkipFileSize(prIndexStatus->prFsal, prIndexStatus->u4EntryOffset , prAviProviderMgr->rOpenInfo.u4DataSize) == KAL_FALSE)
                {        
                    eError = PROVIDER_ERROR;
                    break;
                }

                // get next one
                prCurrentIndex = &prControl->rCurrentIndex;
                if (_AviParserIdx1MgrGetNextIndex(prIndexStatus, prCurrentIndex) == KAL_FALSE)
                {             
                    eError = PROVIDER_ERROR;
                    break;
                }

                // set list control
                VideoCoreInitRingBuffer(&prControl->rList, (kal_uint8 *)prListItem, u4ListNum, sizeof(AVI_SP_INDEX_T));

            }
        }
        break;
        
    case PROVIDER_PARAM_SELECT_STREAM:
        {
            SPIF_STREAM_T *prStream;
            kal_uint32 u4I;
            prStream = (SPIF_STREAM_T *)pParam;
            
            if (prStream->eType == SOURCE_PROVIDER_PORT_AUDIO)
            {
                SPIF_AUDIO_STREAM_INFO_T *prStreamInfo = &prParser->rAudioInfo[0];

                for (u4I=0; u4I<prParser->u4AudioNum; u4I++)
                {
                    if (prStreamInfo[u4I].u4StreamIndex == prStream->u1Track)
                    {
                        //prParser->u4SelectAudio = u4I;
                        prAviProviderMgr->rAudioUserSetting.u4SelectNum = u4I;
                        //prAviProviderMgr->rAudioControl.fgStreamEnable = KAL_TRUE;
                        break;
                    }
                }
                
                if (u4I == prParser->u4AudioNum)
                {
                    AVI_SP_TRACE_PARAMETER_ERROR(u4I, prParser->u4AudioNum, 0);
#ifdef __VE_SP_AVI_ASSERT__                
                    ASSERT(0);
#endif
                    eError =  PROVIDER_ERROR;
                }                
            }
            else
            {
                SPIF_VIDEO_STREAM_INFO_T *prStreamInfo = &prParser->rVideoInfo[0];

                for (u4I=0; u4I<prParser->u4VideoNum; u4I++)
                {
                    if (prStreamInfo[u4I].u4StreamIndex == prStream->u1Track)
                    {
                        //prParser->u4SelectVideo = u4I;
                        prAviProviderMgr->rVideoUserSetting.u4SelectNum = u4I;
                        //prAviProviderMgr->rVideoControl.fgStreamEnable = KAL_TRUE;
                        break;
                    }
                }
                if (u4I >= prParser->u4VideoNum)
                {
                    AVI_SP_TRACE_PARAMETER_ERROR(u4I, prParser->u4VideoNum, 0);
#ifdef __VE_SP_AVI_ASSERT__                
                    ASSERT(0);
#endif
                    eError = PROVIDER_ERROR;
                }
            }
        }
        break;
        
    //case PROVIDER_PARAM_DESELECT_STREAM:
    //    {      
    //    }        
    //    break;
        
    case PROVIDER_PARAM_SEND_HEADER:
        // do noting
        break;
        
    case PROVIDER_PARAM_QUICK_CLOSE:
        prParser->fgQuickClose = KAL_TRUE;
        break;
        
    case PROVIDER_PARAM_ABORT_PROCESS:
        {
            SPIF_ABORT_INFO_T *prAbort = (SPIF_ABORT_INFO_T *)pParam;
            prParser->fgAbort[prAbort->eType] = prAbort->fgEnable;
        }
        
        break;
        
    default:
        eError = PROVIDER_ERROR;
        break;
    }

#ifdef __VE_SP_AVI_LOG_FUNC__
    drv_trace4(AVI_SP_TRACE_FUNC_GROUP, AVI_SP_SET_PARAM, eCmd, eError, 0, (kal_uint32)pvHandle);
#endif    

    return eError;
}

/*****************************************************************************
 * FUNCTION
 *  AviProviderParseVideo
 * DESCRIPTION
 *  This function is used to read video bitstream and demux one video sample.
 * PARAMETERS
 *  prHandle             [IN]     the handle of the mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/   
static PROVIDER_ERROR_T AviProviderParseVideo(void *pvHandle, kal_uint32 *pu4Time)
{
    return _AviProviderParse(pvHandle, pu4Time, SOURCE_PROVIDER_PORT_VIDEO);
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderParseAudio
 * DESCRIPTION
 *  This function is used to read audio bitstream and demux one audio sample
 * PARAMETERS
 *  prHandle             [IN]     the handle of the mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/                                                  
static PROVIDER_ERROR_T AviProviderParseAudio(void *pvHandle, kal_uint32 *pu4Time)
{
    return _AviProviderParse(pvHandle, pu4Time, SOURCE_PROVIDER_PORT_AUDIO);
}

static const PROVIDER_API_T rAviProviderAPI =
{
    AviProviderOpen,
    AviProviderClose,
    AviProviderInit,
    AviProviderDeInit,
    AviProviderGetParameter,
    AviProviderSetParameter,
    AviProviderParseVideo,
    AviProviderParseAudio
#ifdef __VE_SUBTITLE_SUPPORT__
    ,NULL
#endif
};

/*****************************************************************************
 * FUNCTION
 *  AviProviderGetHandle
 * DESCRIPTION
 *  This function is used to get the handle of mp4 provider, and send source component's handle and APIs.
 * PARAMETERS
 *  pvSrcHandle        [IN]     the handle of the source component.
 *  prSrcAPI             [IN]     APIs which provided by source component.
 *  prPrvHdlr            [OUT]    the handle of the mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
PROVIDER_ERROR_T AviProviderGetHandle(void *pvSrcHandle, SP_API_T *prSrcAPI, SPIF_PROVIDER_HANDLE_T *prPrvHdlr)
{
    AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr;
    kal_uint32 u4ContextSize = sizeof(AVI_SP_PROVIDER_CONTEXT_T);
    AVI_SP_SRC_HANDLE_T *prSrcHandle;

    if (pvSrcHandle == NULL || prSrcAPI == NULL || prPrvHdlr == NULL)
    {
        AVI_SP_TRACE_PARAMETER_ERROR((kal_uint32)pvSrcHandle, (kal_uint32)prSrcAPI, (kal_uint32)prPrvHdlr);
        #ifdef __VE_SP_AVI_ASSERT__
        ASSERT(0);
        #endif
        return PROVIDER_ERROR;
    }

    // Help to do: performance testing in cache
    prAviProviderMgr = (AVI_SP_PROVIDER_CONTEXT_T *)prSrcAPI->SPFN_MALLOC_CLA(pvSrcHandle, u4ContextSize, KAL_TRUE);
    if (prAviProviderMgr == NULL)
    {
        AVI_SP_TRACE_PARAMETER_ERROR(0, 0, 0);
        return PROVIDER_ERROR;
    }

    // initial avi context
    kal_mem_set(prAviProviderMgr, 0, u4ContextSize);

    prSrcHandle = &prAviProviderMgr->rSrcHandle;
    prSrcHandle->pvSourceHandle= pvSrcHandle;
    prSrcHandle->prSourceAPI = prSrcAPI;
    
    prPrvHdlr->pvHandle = (void *)prAviProviderMgr;
    prPrvHdlr->prAPI = (PROVIDER_API_T *)&rAviProviderAPI;

#ifdef __VE_SP_AVI_LOG_FUNC__
    {
        kal_uint32 u4Size = u4ContextSize + AVI_SP_FASL_FILE_INFO_BUF + (AVI_SP_FASL_SEEK_HINT_IDX * sizeof(FS_FileLocationHint)) + AVI_SP_TEMP_BUF + 
                                       AVI_SP_FASL_INDEX_BUF + AVI_SP_VIDEO_LIST_ITEM_NUM*sizeof(AVI_SP_INDEX_T) + sizeof(AVI_SP_VBR_ENTRY_T)*AVI_SP_INDEX_MAX_ENTRIES +
                                       AVI_SP_FASL_INDEX_BUF + AVI_SP_AUDIO_LIST_ITEM_NUM*sizeof(AVI_SP_INDEX_T) + sizeof(AVI_SP_VBR_ENTRY_T)*AVI_SP_INDEX_MAX_ENTRIES;        
        drv_trace8(AVI_SP_TRACE_FUNC_GROUP, AVI_SP_GET_HANDLE, (kal_uint32)pvSrcHandle, (kal_uint32)prSrcAPI, (kal_uint32)prAviProviderMgr, (kal_uint32)&rAviProviderAPI, u4Size, 0, 0, 0);
    }
#endif
    
    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  AviProviderReleaseHandle
 * DESCRIPTION
 *  This function is used to release the handle of mp4 provider.
 * PARAMETERS
 *  pvHandle             [IN]     the handle of the mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
PROVIDER_ERROR_T AviProviderReleaseHandle(void* pvHandle)
{
    AVI_SP_PROVIDER_CONTEXT_T *prAviProviderMgr = (AVI_SP_PROVIDER_CONTEXT_T *)pvHandle;
    AVI_SP_SRC_HANDLE_T *prSrcHandle = &prAviProviderMgr->rSrcHandle;

    if (pvHandle == NULL)
    {
        AVI_SP_TRACE_PARAMETER_ERROR((kal_uint32)pvHandle, 0, 0);
        #ifdef __VE_SP_AVI_ASSERT__
        ASSERT(0);
        #endif
        return PROVIDER_ERROR;
    }

#ifdef __VE_SP_AVI_PROFILE__
    {
        AVI_SP_PROFILE_T *prProfile = &prAviProviderMgr->rProfile;
        drv_trace8(AVI_SP_TRACE_FUNC_GROUP, AVI_SP_PARSER_READ_PROFILE, prProfile->u4AudioDirectRead, prProfile->u4AudioExitGap, prProfile->u4AudioExitFull, prProfile->u4AudioIdxRead, 
                                                                        prProfile->u4VideoDirectRead, prProfile->u4VideoExitGap, prProfile->u4VideoExitFull, prProfile->u4VideoIdxRead);
    }
#endif

    prSrcHandle->prSourceAPI->SPFN_FREE_CLA(prSrcHandle->pvSourceHandle, pvHandle);

#ifdef __VE_SP_AVI_LOG_FUNC__
    drv_trace1(AVI_SP_TRACE_FUNC_GROUP, AVI_SP_RELEASE_HANDLE, (kal_uint32)pvHandle);
#endif

    return PROVIDER_ERROR_NONE;
}

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

/*****************************************************************************
 * FUNCTION
 *  AviProviderCheckIntegrity
 * DESCRIPTION
 *  This function is used to check current file is avi container or not.
 * PARAMETERS
 *  pu1Buf             [IN]     the pointer of the buffer in the file beginning.
 *  u4Len             [IN]     size of check buffer.
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool AviProviderCheckIntegrity(kal_uint8 *pu1Buf, kal_uint32 u4Len)
{
    if (pu1Buf == NULL || u4Len < AVI_SP_PROVIDER_CHECK_INTEGRITY_LEN)
    {
        AVI_SP_TRACE_PARAMETER_ERROR((kal_uint32)pu1Buf, u4Len, AVI_SP_PROVIDER_CHECK_INTEGRITY_LEN);
        #ifdef __VE_SP_AVI_ASSERT__
        ASSERT(0);
        #endif
        return KAL_FALSE;
    }

#ifdef __VE_SP_AVI_LOG_FUNC__
        drv_trace2(AVI_SP_TRACE_FUNC_GROUP, AVI_SP_CHECK_INTEGRITY, (kal_uint32)pu1Buf, u4Len);
#endif

    if (strncmp((char*)pu1Buf, (char*)AVI_SP_TAG_RIFF, 4) != 0)
    {
        return KAL_FALSE;
    }
    
    if (strncmp((char*)(pu1Buf+8), (char*)AVI_SP_TAG_AVI, 4) != 0)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


#endif /* #if defined(__VE_SP_AVI__)  */

