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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * flv_parser.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   FLV Parser
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
*******************************************************************************/

#include "drv_features_video.h"

#ifdef __VE_FLV_FILE_FORMAT_SUPPORT__

#include "app_ltlcom.h" //ilm_struct
#include "fsal.h"
#include "flv_parser.h"
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "vcodec_v2_trc.h"
#include "video_comm_v2.h"
#include "video_dbg_v2.h"

#include "string.h"

#define FLV_PARSER_TRACE_FSAL_ERROR(x) kal_trace(TRACE_GROUP_4, FLV_PARSER_FSAL_ERROR, x, __LINE__);
#define FLV_PARSER_TRACE_PARSE_ERROR(x) kal_trace(TRACE_GROUP_4, FLV_PARSER_PARSE_ERROR, x, __LINE__);
#define FLV_PARSER_INVALID_UINT_VALUE 0xFFFFFFFF

#define FLV_UNKNOWN_FRAME_FATE 120000 // 120 FPS

kal_mutexid eFLVParserMutex = 0;

static unsigned int unaligned24_be(const void *v)
{
    const unsigned char *p=v;
    return   ((((p[0]<<8)|p[1])<<8) | p[2]) ;
}

static double ConvIEEE754Double(const void *v)
{
    int i;
    double d8;
    kal_uint8 p[8];
    kal_uint8 *pb = (kal_uint8 *)v;

    for(i=7; i!=0; i--)
    {
        p[i] = pb[7-i];
    }

    d8 = *((double *)p);

    return d8;
}

/*
   Convert sampling frequency to sampling frequency index.
   Refer to 14496-3 Subpart 4
*/
static kal_uint8 _FLVParserConvertSamplingFreqToIndex(kal_uint32 uSamplingFreq)
{
   kal_uint8 u1SamplingFreqIndex;
   if (uSamplingFreq>=92017) u1SamplingFreqIndex = 0x0;
   else if (uSamplingFreq>=75132) u1SamplingFreqIndex = 0x1;
   else if (uSamplingFreq>=55426) u1SamplingFreqIndex = 0x2;
   else if (uSamplingFreq>=46009) u1SamplingFreqIndex = 0x3;
   else if (uSamplingFreq>=37566) u1SamplingFreqIndex = 0x4;
   else if (uSamplingFreq>=27713) u1SamplingFreqIndex = 0x5;
   else if (uSamplingFreq>=23004) u1SamplingFreqIndex = 0x6;
   else if (uSamplingFreq>=18783) u1SamplingFreqIndex = 0x7;
   else if (uSamplingFreq>=13856) u1SamplingFreqIndex = 0x8;
   else if (uSamplingFreq>=11502) u1SamplingFreqIndex = 0x9;
   else if (uSamplingFreq>=9391) u1SamplingFreqIndex = 0xa;
   else u1SamplingFreqIndex = 0xb;

   return u1SamplingFreqIndex;
}

static kal_uint32 _FLVParserConvertSamplingIndexToFreq(kal_uint8 uSamplingIdx)
{
   kal_uint32 u4SamplingFreq = 0;

   if (uSamplingIdx==0) u4SamplingFreq = 96000;
   else if (uSamplingIdx==1) u4SamplingFreq = 88200;
   else if (uSamplingIdx==2) u4SamplingFreq = 64000;
   else if (uSamplingIdx==3) u4SamplingFreq = 48000;
   else if (uSamplingIdx==4) u4SamplingFreq = 44100;
   else if (uSamplingIdx==5) u4SamplingFreq = 32000;
   else if (uSamplingIdx==6) u4SamplingFreq = 24000;
   else if (uSamplingIdx==7) u4SamplingFreq = 22050;
   else if (uSamplingIdx==8) u4SamplingFreq = 16000;
   else if (uSamplingIdx==9) u4SamplingFreq = 12000;
   else if (uSamplingIdx==10) u4SamplingFreq = 11025;
   else if (uSamplingIdx==11) u4SamplingFreq = 8000;
   else if (uSamplingIdx==12) u4SamplingFreq = 7350;
   else FLV_ASSERT(0);

   return u4SamplingFreq;
}

static FLV_Parser_Status flv_parse_decoder_config_14496_3_pce(FLVParser *pFLVParser, kal_uint32 *puBitCnt)
{
    FLV_ASSERT(0);
    return FLV_PARSER_OK;
}

static FLV_Parser_Status flv_parse_decoder_config_14496_3(FLVParser *pFLVParser,
    FLVMetaData*pFLVMetadata, kal_uint32 box_size)
{
    FLV_Parser_Status ret;
    kal_uint32 uBitCnt = 0;

    /* Audio Specific Config */
    kal_uint8 samplingFreqIndex;
    kal_uint32 samplingFreq;

    /* GA Specific Config */
    kal_uint8 frameLengthFlag;
    //kal_uint8 dependsOnCoreCoder;
    //kal_uint8 extensionFlag;
    kal_uint8 u1Var1;

    FLV_ASSERT(pFLVParser != NULL);

    if(box_size < 2) //at least need 2 bytes (16bits)
    {
        FLV_PARSER_TRACE_PARSE_ERROR(FLV_PARSER_PARSE_14496_3_BOXLENGTH_ERROR);
        return FLV_PARSER_PARSE_14496_3_BOXLENGTH_ERROR;
    }
    /* Refer to 14496-3 Subpart 1 */

    /* audio object type */
    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var1, 1))!=FSAL_OK)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
        return FLV_PARSER_FILE_READ_ERROR;
    }

    pFLVMetadata->bAudioObjectType = (u1Var1&0xF8) >> 3;
    uBitCnt += 5;

    samplingFreqIndex = (u1Var1&0x7) << 1;

    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var1, 1))!=FSAL_OK)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
        return FLV_PARSER_FILE_READ_ERROR;
    }

    samplingFreqIndex += (u1Var1&0x80) >> 7;
    uBitCnt += 4;

    if(samplingFreqIndex==0xf)
    {
        kal_uint32 u4temp;
        samplingFreq = u1Var1&0x7F;
        samplingFreq <<= 17;
        uBitCnt += 7;

        if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var1, 1))!=FSAL_OK)
        {
            FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
            return FLV_PARSER_FILE_READ_ERROR;
        }
        u4temp = u1Var1;
        samplingFreq += u4temp<<9;
        uBitCnt += 8;

        if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var1, 1))!=FSAL_OK)
        {
            FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
            return FLV_PARSER_FILE_READ_ERROR;
        }
        u4temp = u1Var1;
        samplingFreq += u4temp<<1;
        uBitCnt += 8;

        if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var1, 1))!=FSAL_OK)
        {
            FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
            return FLV_PARSER_FILE_READ_ERROR;
        }
        u4temp = (u1Var1&0x80) >> 7;
        samplingFreq += u4temp;
        uBitCnt += 8;

        pFLVMetadata->AudioSampleRate = samplingFreq;
        /* Refer to 14496-3 Subpart 4 */
        samplingFreqIndex = _FLVParserConvertSamplingFreqToIndex(samplingFreq);
    }
    else if(samplingFreqIndex==0xc)
    {
        /* Refer to 14496-3 Subpart 4 */
        samplingFreqIndex = 0xb;
    }
    else if(samplingFreqIndex==0xd || samplingFreqIndex==0xe)
    {
        FLV_PARSER_TRACE_PARSE_ERROR(FLV_PARSER_INVALID_AUDIO_SAMPLE_FREQ_IDX);
        return FLV_PARSER_INVALID_AUDIO_SAMPLE_FREQ_IDX;
    }

    pFLVMetadata->bAudioSamplingFreqIndex = samplingFreqIndex;

    /* channel configuration */
    pFLVMetadata->bAudioChannelConfig = (u1Var1&0x78) >> 3;
    uBitCnt += 4;
    if(pFLVMetadata->bAudioChannelConfig>0x02)
    {
        FLV_PARSER_TRACE_PARSE_ERROR(FLV_PARSER_AUDIO_TOO_MANY_CHANNEL);
        return FLV_PARSER_AUDIO_TOO_MANY_CHANNEL;
    }

    if(pFLVMetadata->bAudioObjectType == 5)
    {
        FLV_ASSERT(0);
    }

    /* GA Specific Config */
    /* Refer to 14496-3 Part 4 */

    /* frame length flag */
    frameLengthFlag = (u1Var1&0x4) >> 2;
    uBitCnt += 1;
    if(frameLengthFlag != 0)
    {
        FLV_PARSER_TRACE_PARSE_ERROR(FLV_PARSER_960_120_IMDCT_NOT_SUPPORT);
        return FLV_PARSER_960_120_IMDCT_NOT_SUPPORT;
    }

    /* depends on core coder */
    uBitCnt += 1;
    //if(dependsOnCoreCoder)
    //   return MP4_PARSER_SCALABLE_STREAM_NOT_SUPPORT;

    /* extension flag */
    //extensionFlag = u1Var1&0x1;
    uBitCnt += 1;


    if(pFLVMetadata->bAudioObjectType == 22)   // BSAC
    {
        uBitCnt += 16;
    }

    if(pFLVMetadata->bAudioChannelConfig == 0)
    {
        /* parse program_config_element */
        if((ret=flv_parse_decoder_config_14496_3_pce(pFLVParser, &uBitCnt))!=FLV_PARSER_OK)
        {
            return ret;
        }
    }

    box_size -= (uBitCnt+7)/8;

    FSAL_Skip_Bytes(pFLVParser->pstFSAL, box_size);

    return FLV_PARSER_OK;
}

static FLV_Parser_Status _AVCDecoderConfigRecParser(FLVParser *pFLVParser, AVCDecConfRecord *padr)
{
    kal_uint8 u1Var;

    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
        return FLV_PARSER_FILE_READ_ERROR;
    }
    padr->ConVer = u1Var;

    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
        return FLV_PARSER_FILE_READ_ERROR;
    }
    padr->profile = u1Var;

    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
        return FLV_PARSER_FILE_READ_ERROR;
    }
    padr->profile_comp = u1Var;

    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
        return FLV_PARSER_FILE_READ_ERROR;
    }
    padr->level = u1Var;

    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
        return FLV_PARSER_FILE_READ_ERROR;
    }
    padr->LengthSizeMinusOne = u1Var&0x3;

    FLV_PARSER_FILE_GET_CUR_POS(padr->offset);

    return FLV_PARSER_OK;
}

static kal_uint32 _ParseAMF(FLVParser *pFLVParser, void *pResult, void *pRemainder,
    kal_uint32 *ByteCount, FLVMetaData *pMetadata)
{
    kal_uint8 type;
    kal_uint8 u1Var;
    kal_uint16 u2Var;
    kal_uint32 u4Var;
    kal_uint32 uRemainder;
    kal_uint32 Length;
    kal_uint8 u1AMFBuffer[32];
    kal_uint8 PrecisionDouble[8];
    kal_uint32 i;
    kal_uint32 ParsedByteCount = 0;
    kal_uint32 u4ParseCount;
    double dResult;

    /* Active Message Format */
    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &type, 1))!=FSAL_OK)
    {
        return FLV_PARSER_FILE_READ_ERROR;
    }
    ParsedByteCount += 1;

    switch(type)
    {
        case AMF_Number:
            if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, PrecisionDouble, 8))!=FSAL_OK)
            {
                return FLV_PARSER_FILE_READ_ERROR;
            }
            dResult = ConvIEEE754Double(PrecisionDouble);
            if(pResult != NULL)
            {
                u4Var = (kal_uint32)dResult;
                *((kal_uint32*)pResult) = u4Var;
            }
            if(pRemainder != NULL)
            {
                u4Var = (kal_uint32)((dResult-u4Var)*1000);
                *((kal_uint32*)pRemainder) = u4Var;
            }
            ParsedByteCount += 8;
            break;

        case AMF_Boolean:
            if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
            {
                return FLV_PARSER_FILE_READ_ERROR;
            }
            ParsedByteCount += 1;
            if(u1Var == 0)
            {
                *((kal_uint32*)pResult) = 0;
            }
            else
            {
                *((kal_uint32*)pResult) = 1;
            }
            break;

        case AMF_String:
            if((pFLVParser->eFSALErr=FSAL_Read_UINT16(pFLVParser->pstFSAL, &u2Var))!=FSAL_OK)
            {
                return FLV_PARSER_FILE_READ_ERROR;
            }
            Length = u2Var;
            if(Length < 32)
            {
                if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, u1AMFBuffer, Length))!=FSAL_OK)
                {
                    return FLV_PARSER_FILE_READ_ERROR;
                }
            }
            else
            {
                FSAL_Skip_Bytes(pFLVParser->pstFSAL, Length);
            }

            ParsedByteCount += (2+Length);
            break;

        case AMF_Reference:
            if((pFLVParser->eFSALErr=FSAL_Read_UINT16(pFLVParser->pstFSAL, &u2Var))!=FSAL_OK)
            {
                return FLV_PARSER_FILE_READ_ERROR;
            }
            ParsedByteCount += 2;
            break;

        case AMF_Object:
        case AMF_ECMAArray:
            if(type == AMF_ECMAArray)
            {
                if((pFLVParser->eFSALErr=FSAL_Read_UINT(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
                {
                    return FLV_PARSER_FILE_READ_ERROR;
                }
                ParsedByteCount += 4;
                Length = u4Var;
            }
            else
            {
            }

            while (1)
            {
                /* SCRIPTDATASTRING */
                if((pFLVParser->eFSALErr=FSAL_Read_UINT16(pFLVParser->pstFSAL, &u2Var))!=FSAL_OK)
                {
                    FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
                    return FLV_PARSER_FILE_READ_ERROR;
                }
                ParsedByteCount += 2;
                Length = u2Var;

                if(Length == 0)
                {
                    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
                    {
                        return FLV_PARSER_FILE_READ_ERROR;
                    }
                    ParsedByteCount += 1;
                    if(u1Var != 9)
                    {
                        kal_uint32 uOffset;

                        /* 一分鐘手機進化.flv has this problem. */
                        //FLV_ASSERT(0);
                        ParsedByteCount -= 3;
                        FLV_PARSER_TRACE_PARSE_ERROR(u1Var);
                        FSAL_GetCurPos(pFLVParser->pstFSAL, &uOffset);
                        FSAL_Seek(pFLVParser->pstFSAL, uOffset-3);
                    }
                    break;
                }

                if(Length < 32)
                {
                    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, u1AMFBuffer, Length))!=FSAL_OK)
                    {
                        return FLV_PARSER_FILE_READ_ERROR;
                    }
                    u1AMFBuffer[Length] = 0; // String ending character
                }
                else
                {
                    // Not reading this string
                    FSAL_Skip_Bytes(pFLVParser->pstFSAL, Length);
                    u1AMFBuffer[0] = 0; // String ending character
                }

                ParsedByteCount += Length;


                if(strcmp((char *)u1AMFBuffer, "filepositions") == 0)
                {
                    pMetadata->rKeyFrames.eFileOffset = FLV_KEYFRAME_START;
                }
                else if(strcmp((char *)u1AMFBuffer, "times") == 0)
                {
                    pMetadata->rKeyFrames.eTime = FLV_KEYFRAME_START;
                }

                /* SCRIPTDATAVALUE */
                if(FLV_PARSER_OK != _ParseAMF(pFLVParser, &u4Var, &uRemainder, &u4ParseCount, pMetadata))
                {
                    FLV_ASSERT(0);
                }
                else
                {
                    ParsedByteCount += u4ParseCount;
                }

                if(strcmp((char *)u1AMFBuffer, "width") == 0)
                {
                    pMetadata->width = u4Var;
                }
                else if(strcmp((char *)u1AMFBuffer, "height") == 0)
                {
                    pMetadata->height = u4Var;
                }
                else if(strcmp((char *)u1AMFBuffer, "audiocodecid") == 0)
                {
                    pMetadata->AudioCodecId = (FLV_AUDIO_CODEC_FORMAT)u4Var;
                }
                else if(strcmp((char *)u1AMFBuffer, "audiodatarate") == 0)
                {
                    pMetadata->AudioDataRate = u4Var;
                }
                else if(strcmp((char *)u1AMFBuffer, "audiodelay") == 0)
                {
                    pMetadata->AudioDelay = u4Var*1000 + uRemainder;
                }
                else if(strcmp((char *)u1AMFBuffer, "audiosamplerate") == 0)
                {
                    pMetadata->AudioSampleRate = u4Var;
                }
                else if(strcmp((char *)u1AMFBuffer, "audiosamplesize") == 0)
                {
                    pMetadata->AudioSampleSize = u4Var;
                }
                else if(strcmp((char *)u1AMFBuffer, "duration") == 0)
                {
                    pMetadata->duration = u4Var*1000 + uRemainder;
                }
                else if(strcmp((char *)u1AMFBuffer, "framerate") == 0)
                {
                    pMetadata->VideoFrameRate = u4Var*1000 + uRemainder;
                }
                else if(strcmp((char *)u1AMFBuffer, "stereo") == 0)
                {
                    if(u4Var == 0)
                    {
                        pMetadata->stereo = KAL_FALSE;
                    }
                    else
                    {
                        pMetadata->stereo = KAL_TRUE;
                    }
                }
                else if(strcmp((char *)u1AMFBuffer, "videocodecid") == 0)
                {
                    pMetadata->VideoCodecId = (FLV_VIDEO_CODEC_FORMAT)u4Var;
                }
                else if(strcmp((char *)u1AMFBuffer, "videodatarate") == 0)
                {
                    pMetadata->VideoDataRate = u4Var;
                }

            }
            break;

        case AMF_StrictArray:
        {
            kal_uint32 *pKeyframe = NULL;
            KeyFrameStatus *pstatus = NULL;
            kal_uint32 offset = 0;

            if((pFLVParser->eFSALErr=FSAL_Read_UINT(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
            {
                return FLV_PARSER_FILE_READ_ERROR;
            }
            ParsedByteCount += 4;
            Length = u4Var;

            if(pMetadata->rKeyFrames.eFileOffset == FLV_KEYFRAME_START)
            {
                if(pMetadata->rKeyFrames.eTime == FLV_KEYFRAME_START)
                {
                    FLV_ASSERT(0); //printf("Keyframe Fileoffset/Time data error!!!\n");
                }
                if(pMetadata->rKeyFrames.Real_Count == 0)
                {
                    pMetadata->rKeyFrames.Real_Count = Length;
                }
                else
                {
                    if(pMetadata->rKeyFrames.Real_Count != Length)
                    {
                        FLV_ASSERT(0);
                    }
                }
                pKeyframe = pMetadata->rKeyFrames.au4FileVOffset;
                pstatus = &pMetadata->rKeyFrames.eFileOffset;
                FLV_PARSER_FILE_GET_CUR_POS(offset);
                pMetadata->rKeyFrames.KeyOffestStart = offset;
            }
            else if(pMetadata->rKeyFrames.eTime == FLV_KEYFRAME_START)
            {
                if(pMetadata->rKeyFrames.eFileOffset == FLV_KEYFRAME_START)
                {
                    FLV_ASSERT(0); //printf("Keyframe Fileoffset/Time data error!!!\n");
                }
                if(pMetadata->rKeyFrames.Real_Count== 0)
                {
                    pMetadata->rKeyFrames.Real_Count = Length;
                }
                else
                {
                    if(pMetadata->rKeyFrames.Real_Count != Length)
                    {
                        FLV_ASSERT(0);
                    }
                }
                pKeyframe = pMetadata->rKeyFrames.au4Time;
                pstatus = &pMetadata->rKeyFrames.eTime;
                FLV_PARSER_FILE_GET_CUR_POS(offset);
                pMetadata->rKeyFrames.KeyTimestart = offset;
            }

            for(i=0; i<Length; i++)
            {
                if(i == FLV_MAX_KEYFRAME_STORE)
                {
                    kal_uint32 skipsize = 0;

                    // 一筆fileoffset或time是TYPE(1) + DOUBLE(8)
                    skipsize = (Length-FLV_MAX_KEYFRAME_STORE)*9;

                    // 第一次進來只能存(FLV_MAX_KEYFRAME_STORE)筆，剩下的要skip掉，後面playback用到時再讀
                    if((pFLVParser->eFSALErr=FSAL_Skip_Bytes(pFLVParser->pstFSAL, skipsize))!=FSAL_OK)
                    {
                        return FLV_PARSER_FILE_READ_ERROR;
                    }
                    ParsedByteCount += skipsize;
                    break;
                }

                if(FLV_PARSER_OK != _ParseAMF(pFLVParser, &u4Var, &uRemainder, &u4ParseCount, pMetadata))
                {
                    FLV_ASSERT(0);
                }
                else
                {
                    ParsedByteCount += u4ParseCount;
                }
                if(pKeyframe != NULL)
                {
                    pKeyframe[i] = u4Var;
                    if(pKeyframe == pMetadata->rKeyFrames.au4Time)
                    {
                        pKeyframe[i] = u4Var*1000 + uRemainder;
                    }
                }
            }
            pMetadata->rKeyFrames.last_index = i-1;
            if(pstatus != NULL)
            {
                *pstatus = FLV_KEYFRAME_PARSED;
            }
            break;
        }
        case AMF_Date:
            // DOUBLE + SI16
            if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, u1AMFBuffer, 10))!=FSAL_OK)
            {
                return FLV_PARSER_FILE_READ_ERROR;
            }
            ParsedByteCount += 10;
            break;

        case AMFLongString:
            if((pFLVParser->eFSALErr=FSAL_Read_UINT(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
            {
                return FLV_PARSER_FILE_READ_ERROR;
            }
            ParsedByteCount += 4;
            Length = u4Var;
            if(Length < 32)
            {
                if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, u1AMFBuffer, Length))!=FSAL_OK)
                {
                    return FLV_PARSER_FILE_READ_ERROR;
                }
            }
            else
            {
                FSAL_Skip_Bytes(pFLVParser->pstFSAL, Length);
            }
            ParsedByteCount += Length;
            break;

        default:
            FLV_ASSERT(0);
            break;
    }

    *ByteCount = ParsedByteCount;
    return FLV_PARSER_OK;
}

FLV_Parser_Status FLV_Tag(FLVParser *pFLVParser)
{
    kal_uint8 u1Var;
    kal_uint32 u4Var;

    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
    {
        if(pFLVParser->eFSALErr == FSAL_READ_OVER_EOF)
        {
            return FLV_PARSER_FILE_READ_EOF;
        }
        else
        {
            return FLV_PARSER_FILE_READ_ERROR;
        }
    }
    pFLVParser->FLVTAG_Filter = (u1Var&FLV_TAG_FILTER)>>FLV_TAG_FILTER_OFFSET;
    pFLVParser->FLVTAG_TagType = (u1Var&FLV_TAG_TAGTYPE);

    if((pFLVParser->eFSALErr=FSAL_Read_UINT24(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
    {
        return FLV_PARSER_FILE_READ_ERROR;
    }
    pFLVParser->FLVTAG_DataSize = u4Var;

    if((pFLVParser->eFSALErr=FSAL_Read_UINT24(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
    {
        return FLV_PARSER_FILE_READ_ERROR;
    }
    if(pFLVParser->FLVTAG_DataSize <= 0)
    {
        FLV_PARSER_TRACE_PARSE_ERROR(pFLVParser->FLVTAG_DataSize);
        return FLV_PARSER_FILE_READ_ERROR;
    }

    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
    {
        return FLV_PARSER_FILE_READ_ERROR;
    }

    pFLVParser->FLVTAG_TimestampExtended = u1Var;

    pFLVParser->FLVTAG_Timestamp = u1Var;
    pFLVParser->FLVTAG_Timestamp = (pFLVParser->FLVTAG_Timestamp<<24) | u4Var;
    pFLVParser->CompositionTimeOffset = 0;

    if((pFLVParser->eFSALErr=FSAL_Read_UINT24(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
    {
        return FLV_PARSER_FILE_READ_ERROR;
    }
    pFLVParser->FLVTAG_StreamID = u4Var;

    if(pFLVParser->FLVTAG_StreamID != 0)
    {
        FLV_PARSER_TRACE_PARSE_ERROR(pFLVParser->FLVTAG_StreamID);
        //FLV_ASSERT(0);
        return FLV_PARSER_FILE_READ_ERROR;
    }

    return FLV_PARSER_OK;

}

FLV_Parser_Status FLV_Tag_Buf(FLVParser *pFLVParser, kal_uint8* start, kal_uint32 length)
{
    kal_uint8 u1Var;
    kal_uint32 u4Var;

    if(length < FLV_TAG_LENGTH)
    {
        return FLV_PARSER_BUFFER_READ_OVER;
    }

    u1Var = start[0];
    pFLVParser->FLVTAG_Filter = (u1Var&FLV_TAG_FILTER)>>FLV_TAG_FILTER_OFFSET;
    pFLVParser->FLVTAG_TagType = (u1Var&FLV_TAG_TAGTYPE);

    u4Var = unaligned24_be(start+1);
    pFLVParser->FLVTAG_DataSize = u4Var;
    if(pFLVParser->FLVTAG_DataSize <= 0)
    {
        FLV_PARSER_TRACE_PARSE_ERROR(pFLVParser->FLVTAG_DataSize);
        return FLV_PARSER_FILE_READ_ERROR;
    }

    u4Var = unaligned24_be(start+1+3);

    u1Var = start[1+3+3];

    pFLVParser->FLVTAG_TimestampExtended = u1Var;

    pFLVParser->FLVTAG_Timestamp = u1Var;
    pFLVParser->FLVTAG_Timestamp = (pFLVParser->FLVTAG_Timestamp<<24) | u4Var;
    pFLVParser->CompositionTimeOffset = 0;

    u4Var = unaligned24_be(start+1+3+3+1);
    pFLVParser->FLVTAG_StreamID = u4Var;

    if(pFLVParser->FLVTAG_StreamID != 0)
    {
        FLV_PARSER_TRACE_PARSE_ERROR(pFLVParser->FLVTAG_StreamID);
        //FLV_ASSERT(0);
        return FLV_PARSER_FILE_READ_ERROR;
    }

    return FLV_PARSER_OK;

}

FLV_Parser_Status FLV_ScriptData(FLVParser *pFLVParser, FLVMetaData *pMetadata)
{
    kal_uint32 u4ElapsedCount = 0;
    kal_uint32 u4Var;
    kal_uint32 uRemainder;
    kal_uint32 u4ParseCount = 0;

    while(u4ElapsedCount < pFLVParser->FLVTAG_DataSize)
    {
        if(FLV_PARSER_OK != _ParseAMF(pFLVParser, &u4Var, &uRemainder, &u4ParseCount, pMetadata))
        {
            FLV_ASSERT(0);
        }
        else
        {
            u4ElapsedCount += u4ParseCount;
        }
    }

    //FLV_ASSERT(u4ElapsedCount == pFLVParser->FLVTAG_DataSize);

    // Tag Size
    if((pFLVParser->eFSALErr=FSAL_Read_UINT(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
        return FLV_PARSER_FILE_READ_ERROR;
    }
    /* 一分鐘手機進化.flv has this problem. */
    //FLV_ASSERT((pFLVParser->FLVTAG_DataSize+FLV_TAG_LENGTH) == u4Var);
    if((pFLVParser->FLVTAG_DataSize+FLV_TAG_LENGTH) != u4Var)
    {
        FLV_PARSER_TRACE_PARSE_ERROR(u4Var);
    }

    return FLV_PARSER_OK;
}

FLV_Parser_Status FLV_AudioTag(FLVParser *pFLVParser, FLVMetaData *pMetadata)
{
    kal_uint8 SoundFormat;
    kal_uint8 SoundRate;
    kal_uint8 SoundSize;
    kal_uint8 SoundType;
    kal_uint8 AACPacketType;
    kal_uint8 u1Var;
    kal_uint32 u4Var;
    FLV_Parser_Status ret;

    FLV_ASSERT(pFLVParser->FLVTAG_TagType == AUDIO_TAG);

    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
    {
        return FLV_PARSER_FILE_READ_ERROR;
    }
    SoundFormat = (u1Var&0xF0) >> 4;
    SoundRate = (u1Var&0xC) >> 2;
    SoundSize = (u1Var&0x2) >> 1;
    SoundType = u1Var&0x1;

    pMetadata->AudioCodecId = (FLV_AUDIO_CODEC_FORMAT)SoundFormat;
    pMetadata->stereo = KAL_FALSE;
    if(SoundType != 0)
    {
        pMetadata->stereo = KAL_TRUE;
    }
    switch(SoundFormat)
    {
        case FLV_LINEAR_PCM:
        case FLV_ADPCM:
        case FLV_LINEAR_PCM_LE:
        case FLV_G711_ALAW_PCM:
        case FLV_G711_MULAW_PCM:
        break;

        default:
        if(SoundRate == 0)
        {
            pMetadata->AudioSampleRate = 11025/2;
        }
        else if(SoundRate == 1)
        {
            pMetadata->AudioSampleRate = 11025;
        }
        else if(SoundRate == 2)
        {
            pMetadata->AudioSampleRate = 22050;
        }
        else // if(SoundRate == 3)
        {
            pMetadata->AudioSampleRate = 44100;
        }
        break;
    }

    if(SoundSize == 0)
    {
        pMetadata->AudioSampleSize = 8;
    }
    else
    {
        pMetadata->AudioSampleSize = 16;
    }

    if(SoundFormat == FLV_SOUND_FORMAT_AAC)
    {
        if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
        {
            return FLV_PARSER_FILE_READ_ERROR;
        }

        AACPacketType = u1Var;
        if(AACPacketType == 0)
        {
            kal_uint32 offset1, offset2;

            kal_trace(TRACE_GROUP_4, FLV_PARSER_AUDIO_CONFIG,
                SoundFormat, SoundRate, SoundSize, SoundType);

            FLV_PARSER_FILE_GET_CUR_POS(offset1);
            ret = flv_parse_decoder_config_14496_3(pFLVParser, pMetadata,
                pFLVParser->FLVTAG_DataSize-2);
            FLV_PARSER_FILE_GET_CUR_POS(offset2);
            if(ret != FLV_PARSER_OK)
            {
                FLV_ASSERT(pFLVParser->FLVTAG_DataSize > (offset2-offset1));
                FSAL_Skip_Bytes(pFLVParser->pstFSAL, pFLVParser->FLVTAG_DataSize-(offset2-offset1)-2);

                FLV_PARSER_TRACE_PARSE_ERROR(ret);
                ret = FLV_PARSER_PARSE_14496_3_ERROR;
            }
            else
            {
                ret = FLV_PARSER_AUDIO_CONFIG_OK;
            }
        }
        else
        {
            FSAL_Skip_Bytes(pFLVParser->pstFSAL, pFLVParser->FLVTAG_DataSize-2);
            ret = FLV_PARSER_AUDIO_DATA_OK;
        }

    }
    else
    {
        FSAL_Skip_Bytes(pFLVParser->pstFSAL, pFLVParser->FLVTAG_DataSize-1);
        ret = FLV_PARSER_AUDIO_DATA_OK;
    }

#if 0  // AAC data
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // Tag Size
    if((pFLVParser->eFSALErr=FSAL_Read_UINT(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
        return FLV_PARSER_FILE_READ_ERROR;
    }

    if ((pFLVParser->FLVTAG_DataSize+FLV_TAG_LENGTH) != u4Var)
    {
        FLV_PARSER_TRACE_PARSE_ERROR(u4Var);
        //FLV_ASSERT(0);
        ret = FLV_PARSER_FILE_READ_ERROR;
    }

    return ret;
}

FLV_Parser_Status FLV_VideoTag(FLVParser *pFLVParser, FLVMetaData *pMetadata)
{
    kal_uint8 FrameType;
    kal_uint8 CodecID;
    kal_uint8 AVCPacketType = 0xFF;
    kal_uint32 u4Var;
    kal_uint8 u1Var;
    kal_int32 CompositionTime;
    unsigned int VideoDataParsed = 0;
    #if 0
/* under construction !*/
    #endif
    FLV_Parser_Status eParserStatus;
    FLV_Parser_Status ret;

    /* VideoTagHeader */
    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
        return FLV_PARSER_FILE_READ_ERROR;
    }
    VideoDataParsed += 1;
    FrameType = (u1Var&0xF0) >> 4;
    CodecID = u1Var&0xF;

    pMetadata->VideoCodecId = (FLV_VIDEO_CODEC_FORMAT)CodecID;
    pFLVParser->VideoFrameType = FrameType;
    if(FrameType == 5) // video info/command frame
    {
        // 1 U8 existed only
        if((pFLVParser->eFSALErr=FSAL_Skip_Bytes(pFLVParser->pstFSAL,
            pFLVParser->FLVTAG_DataSize-VideoDataParsed))!=FSAL_OK)
        {
            FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
            return FLV_PARSER_FILE_READ_ERROR;
        }
        FLV_PARSER_TRACE_PARSE_ERROR(FLV_PARSER_VIDEO_FRAME_TYPE_NOT_SUPPORT);
        ret = FLV_PARSER_VIDEO_FRAME_TYPE_NOT_SUPPORT;
    }
    else
    {
        /* VideoTagBody */
        if(!(CodecID == FLV_AVC))
        {
            FLV_PARSER_TRACE_PARSE_ERROR(FLV_PARSER_VIDEO_FORMAT_NOT_SUPPORT);
            FSAL_Skip_Bytes(pFLVParser->pstFSAL, pFLVParser->FLVTAG_DataSize-VideoDataParsed);
            ret = FLV_PARSER_VIDEO_FORMAT_NOT_SUPPORT;
        }
        else
        {
            if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
            {
                FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
                return FLV_PARSER_FILE_READ_ERROR;
            }
            VideoDataParsed += 1;
            AVCPacketType = u1Var;

            u4Var = 0;
            if((pFLVParser->eFSALErr=FSAL_Read_UINT24(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
            {
                FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
                return FLV_PARSER_FILE_READ_ERROR;
            }
            VideoDataParsed += 3;
            if((u4Var&0x800000) != 0)
            {
                CompositionTime = -(0x1000000 - u4Var);
            }
            else
            {
                CompositionTime = u4Var;
            }
            pFLVParser->CompositionTimeOffset = CompositionTime;

            if(AVCPacketType == 0)
            {
                if(pFLVParser->FLVTAG_DataSize > (VideoDataParsed+FLV_AVCDECCONFSIZEMIN))
                {
                    pMetadata->rAVCDecConfig.totalSize =
                        pFLVParser->FLVTAG_DataSize - VideoDataParsed - FLV_AVCDECCONFSIZEMIN;
                    eParserStatus = _AVCDecoderConfigRecParser(pFLVParser, &(pMetadata->rAVCDecConfig));
                    if(eParserStatus != FLV_PARSER_OK)
                    {
                        // _AVCDecoderConfigRecParser only error at FSAL
                        FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
                        return FLV_PARSER_FILE_READ_ERROR;
                    }
                    VideoDataParsed += FLV_AVCDECCONFSIZEMIN;
                }
                else
                {
                    pMetadata->rAVCDecConfig.totalSize = 0;
                }

                FSAL_Skip_Bytes(pFLVParser->pstFSAL, pFLVParser->FLVTAG_DataSize-VideoDataParsed);
                ret = FLV_PARSER_VIDEO_CONFIG_OK;
            }
            else if(AVCPacketType == 1)
            {
                FSAL_Skip_Bytes(pFLVParser->pstFSAL, pFLVParser->FLVTAG_DataSize-VideoDataParsed);
                ret = FLV_PARSER_VIDEO_DATA_OK;
            }
            else if(AVCPacketType == 2)
            {
                ret = FLV_PARSER_VIDEO_PKT_EOS;
            }
            else
            {
                //AVCPacketType Error!!!
                FLV_PARSER_TRACE_PARSE_ERROR(AVCPacketType);
                //FLV_ASSERT(0);
                ret = FLV_PARSER_VIDEO_FORMAT_NOT_SUPPORT;
            }
        }
    }

    // Tag Size
    if((pFLVParser->eFSALErr=FSAL_Read_UINT(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
        return FLV_PARSER_FILE_READ_ERROR;
    }

    if ((pFLVParser->FLVTAG_DataSize+FLV_TAG_LENGTH) != u4Var)
    {
        FLV_PARSER_TRACE_PARSE_ERROR(u4Var);
        //FLV_ASSERT(0);
        ret = FLV_PARSER_FILE_READ_ERROR;
    }
    return ret;
}

FLV_Parser_Status FLV_VideoTag_Buf(FLVParser *pFLVParser, FLVMetaData *pMetadata,
    kal_uint8* start, kal_uint32 length)
{
    kal_uint8 FrameType;
    kal_uint8 CodecID;
    kal_uint8 AVCPacketType = 0xFF;
    kal_uint32 u4Var;
    kal_uint8 u1Var;
    kal_int32 CompositionTime;
    unsigned int VideoDataParsed = 0;

    FLV_ASSERT(length);

    /* VideoTagHeader */
    u1Var = start[0];
    VideoDataParsed += 1;
    FrameType = (u1Var&0xF0) >> 4;
    CodecID = u1Var&0xF;
    pFLVParser->VideoFrameType = FrameType;

    if(FrameType == 5) // video info/command frame
    {
        FLV_PARSER_TRACE_PARSE_ERROR(FLV_PARSER_VIDEO_FRAME_TYPE_NOT_SUPPORT);
        return FLV_PARSER_VIDEO_FRAME_TYPE_NOT_SUPPORT;
    }
    else
    {
        /* VideoTagBody */
        if(!(CodecID == FLV_AVC))
        {
            FLV_PARSER_TRACE_PARSE_ERROR(FLV_PARSER_VIDEO_FORMAT_NOT_SUPPORT);
        }
        else
        {
            u1Var = start[1];
            VideoDataParsed += 1;
            AVCPacketType = u1Var;

            u4Var = 0;
            u4Var = unaligned24_be(start+1+1);
            VideoDataParsed += 3;
            if((u4Var&0x800000) != 0)
            {
                CompositionTime = -(0x1000000 - u4Var);
            }
            else
            {
                CompositionTime = u4Var;
            }
            pFLVParser->CompositionTimeOffset = CompositionTime;

            if(AVCPacketType == 2) // AVC end of sequence
            {
                return FLV_PARSER_VIDEO_PKT_EOS;
            }

        }
    }

    FLV_ASSERT(length >= VideoDataParsed);

    return FLV_PARSER_OK;
}

FLV_Parser_Status FLV_Parse(FLVParser *pFLVParser, STFSAL *pstFSAL, FLVMetaData *ptMetaData)
{
    kal_uint32 u4Var;
    kal_uint8 u1Var;
    kal_bool bParseVideoConfig = KAL_TRUE; // Need to parse video config
    kal_bool bParseAudioConfig = KAL_FALSE; // Need to parse audio config
    FLV_Parser_Status eParserStatus;
    kal_uint32 ElapsedTime;
    kal_uint32 offset = 0;
    kal_uint32 u4VideoFPS = 0;
    kal_uint32 u4VideoFPSTemp = 0;
    kal_uint32 u4AudioFPS = 0;
    kal_uint32 uFileSize;
    kal_uint32 uVideoFirstTimestamp = 0;
    kal_uint32 uAudioFirstTimestamp = 0;

    FLV_PARSER_CHECK_ARG(pFLVParser != NULL);
    FLV_PARSER_CHECK_ARG(pstFSAL != NULL);
    FLV_PARSER_CHECK_ARG(ptMetaData != NULL);

    ElapsedTime = video_get_current_time();

    if (eFLVParserMutex== 0)
    {
        eFLVParserMutex = kal_create_mutex("FLV_PARSER_MUTEX");
    }

    pFLVParser->pstFSAL = pstFSAL;
    FSAL_GetFileSize(pFLVParser->pstFSAL, &uFileSize);

    // Signature
    if((pFLVParser->eFSALErr=FSAL_Read_UINT24(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
    {
        return FLV_PARSER_FILE_READ_ERROR;
    }

    if(u4Var != FLV_FILE_START)
    {
        return FLV_PARSER_INVALID_HEADER;
    }

    // Version
    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
    {
        return FLV_PARSER_FILE_READ_ERROR;
    }
    ptMetaData->version = u1Var;

    // TypeFlags
    if((pFLVParser->eFSALErr=FSAL_Read_Bytes(pFLVParser->pstFSAL, &u1Var, 1))!=FSAL_OK)
    {
        return FLV_PARSER_FILE_READ_ERROR;
    }
    if( (u1Var & FLV_HEADER_TYPE_FLAGS_RESERVED_BITS5) != 0)
    {
        // todou (45).f4v has non-zero value
        FLV_PARSER_TRACE_PARSE_ERROR(u1Var);
        //FLV_ASSERT(0);
    }
    #if 0
/* under construction !*/
    #else
    ptMetaData->FLVHeader_TypeFlagsAudio = 1;
    #endif


    if( (u1Var & FLV_HEADER_TYPE_FLAGS_RESERVED_BITS1) != 0)
    {
        FLV_ASSERT(0);
    }

    #if 0
/* under construction !*/
    #else
    ptMetaData->FLVHeader_TypeFlagsVideo = 1;
    #endif

    // DataOffset
    if((pFLVParser->eFSALErr=FSAL_Read_UINT(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
    {
        return FLV_PARSER_FILE_READ_ERROR;
    }
    ptMetaData->FLVHeader_DataOffset = u4Var;

    // PreviousTagSize0
    if((pFLVParser->eFSALErr=FSAL_Read_UINT(pFLVParser->pstFSAL, &u4Var))!=FSAL_OK)
    {
        return FLV_PARSER_FILE_READ_ERROR;
    }
    if(u4Var != 0)
    {
        // todou (45).f4v encode PreviousTagSize as "love"
        FLV_PARSER_TRACE_PARSE_ERROR(u4Var);
    }

    if(FLV_PARSER_OK != FLV_Tag(pFLVParser))
    {
        FLV_PARSER_TRACE_PARSE_ERROR(pFLVParser->FLVTAG_TagType);
        return FLV_PARSER_FILE_READ_ERROR;
    }

    if(pFLVParser->FLVTAG_TagType != SCRIPT_DATA_TAG)
    {
        // script data should be at the beginning.
        #if 0
/* under construction !*/
/* under construction !*/
        #else
        kal_trace(TRACE_GROUP_4, FLV_PARSER_NO_SCRIPTDATA);
        FLV_PARSER_FILE_GET_CUR_POS(offset);
        FSAL_Seek(pFLVParser->pstFSAL, offset-FLV_TAG_LENGTH);
        #endif
    }
    else
    {
        if(FLV_PARSER_OK != FLV_ScriptData(pFLVParser, ptMetaData))
        {
            FLV_ASSERT(0);
        }
    }

    if(ptMetaData->FLVHeader_TypeFlagsVideo == 0)
    {
        bParseVideoConfig = KAL_FALSE;
    }
    if((ptMetaData->FLVHeader_TypeFlagsAudio != 0) &&
       (ptMetaData->AudioCodecId == FLV_SOUND_FORMAT_AAC))
    {
        bParseAudioConfig = KAL_TRUE;
    }

    ptMetaData->FirstAudioTagOffset = 0;
    ptMetaData->FirstVideoTagOffset = 0;

    if(ptMetaData->FLVHeader_TypeFlagsVideo != 0)
    {
        u4VideoFPS = ptMetaData->VideoFrameRate;
        if(u4VideoFPS/1000 > 120)
        {
            // 太奇怪的數字, 用bitstream資料重算
            u4VideoFPS = 0;
            ptMetaData->VideoFrameRate = 0;
        }
    }
    else
    {
        u4VideoFPS = 0xFFFFFFFF;
    }

    if(ptMetaData->FLVHeader_TypeFlagsAudio == 0)
    {
        ptMetaData->AudioFrameRate = 0xFFFFFFFF;
    }

    if((ptMetaData->FLVHeader_TypeFlagsVideo == 0) &&
        (ptMetaData->FLVHeader_TypeFlagsAudio == 0))
    {
        FLV_PARSER_TRACE_PARSE_ERROR(FLV_PARSER_AVCODEC_NOT_SUPPORT);
        return FLV_PARSER_AVCODEC_NOT_SUPPORT;
    }

    while(FLV_Tag(pFLVParser) == FLV_PARSER_OK)
    {
        FLV_PARSER_FILE_GET_CUR_POS(offset);

        if(pFLVParser->FLVTAG_TagType == VIDEO_TAG)
        {
            eParserStatus = FLV_VideoTag(pFLVParser, ptMetaData);
            if((eParserStatus == FLV_PARSER_VIDEO_CONFIG_OK) ||
               (eParserStatus == FLV_PARSER_VIDEO_DATA_OK) ||
               (eParserStatus == FLV_PARSER_VIDEO_PKT_EOS) ||
               (eParserStatus == FLV_PARSER_VIDEO_FRAME_TYPE_NOT_SUPPORT))
            {
                if((bParseVideoConfig == KAL_TRUE))
                {
                    if(ptMetaData->VideoCodecId == FLV_AVC)
                    {
                        FLV_ASSERT(eParserStatus == FLV_PARSER_VIDEO_CONFIG_OK);
                    }
                    bParseVideoConfig = KAL_FALSE;
                }

                if(eParserStatus == FLV_PARSER_VIDEO_DATA_OK)
                {
                    if((ptMetaData->VideoFrameNum == 0) &&
                       (pFLVParser->VideoFrameType == FLV_KEY_FRAME))
                    {
                        ptMetaData->FirstVideoTagOffset = offset - FLV_TAG_LENGTH;
                        uVideoFirstTimestamp = pFLVParser->FLVTAG_Timestamp;
                        ptMetaData->VideoFrameNum++;
                    }
                    else if(ptMetaData->VideoFrameNum > 0)
                    {
                        ptMetaData->VideoFrameNum++;
                    }

                    if ((ptMetaData->VideoFrameNum>1) &&
                        ((pFLVParser->FLVTAG_Timestamp-uVideoFirstTimestamp)/ptMetaData->VideoFrameNum)>0)
                    {
                        u4VideoFPSTemp =  1000*1000 /
                            ((pFLVParser->FLVTAG_Timestamp-uVideoFirstTimestamp)/ptMetaData->VideoFrameNum);
                    }

                    if(ptMetaData->VideoFrameNum == 10)
                    {
                        u4VideoFPS = u4VideoFPSTemp;
                    }
                }
            }
            else
            {
                bParseVideoConfig = KAL_FALSE;
                ptMetaData->FLVHeader_TypeFlagsVideo = 0;
                u4VideoFPS = 0xFFFFFFFF;
                FLV_ASSERT((eParserStatus == FLV_PARSER_VIDEO_FORMAT_NOT_SUPPORT) ||
                           (eParserStatus == FLV_PARSER_FILE_READ_ERROR));
            }
        }
        else if(pFLVParser->FLVTAG_TagType == AUDIO_TAG)
        {
            eParserStatus = FLV_AudioTag(pFLVParser, ptMetaData);
            FLV_ASSERT((eParserStatus == FLV_PARSER_AUDIO_CONFIG_OK) ||
               (eParserStatus == FLV_PARSER_AUDIO_DATA_OK) ||
               (eParserStatus == FLV_PARSER_PARSE_14496_3_ERROR) ||
               (eParserStatus == FLV_PARSER_FILE_READ_ERROR))
            if((bParseAudioConfig == KAL_TRUE))
            {
                FLV_ASSERT((eParserStatus == FLV_PARSER_AUDIO_CONFIG_OK) ||
                           (eParserStatus == FLV_PARSER_PARSE_14496_3_ERROR));
                bParseAudioConfig = KAL_FALSE;
            }

            if(eParserStatus == FLV_PARSER_AUDIO_DATA_OK)
            {
                if(ptMetaData->AudioFrameNum == 0)
                {
                    ptMetaData->FirstAudioTagOffset = offset - FLV_TAG_LENGTH;
                    ptMetaData->LatestAudioTagOffset = ptMetaData->FirstAudioTagOffset;
                    uAudioFirstTimestamp = pFLVParser->FLVTAG_Timestamp;

                }
                ptMetaData->AudioFrameNum++;

                if ((ptMetaData->AudioFrameNum>1) &&
                    ((pFLVParser->FLVTAG_Timestamp-uAudioFirstTimestamp)/ptMetaData->AudioFrameNum)>0)
                {
                    u4AudioFPS =  1000*1000 /
                        ((pFLVParser->FLVTAG_Timestamp-uAudioFirstTimestamp)/ptMetaData->AudioFrameNum);
                }
            }
            if(eParserStatus == FLV_PARSER_FILE_READ_ERROR)
            {
                bParseAudioConfig = KAL_FALSE;
                ptMetaData->FLVHeader_TypeFlagsAudio = 0;
                u4AudioFPS = 0xFFFFFFFF;
            }
            if(ptMetaData->AudioFrameNum == 10)
            {
                ptMetaData->AudioFrameRate = u4AudioFPS;
            }
        }
        else if(pFLVParser->FLVTAG_TagType == SCRIPT_DATA_TAG)
        {
            FLV_PARSER_TRACE_PARSE_ERROR(SCRIPT_DATA_TAG);
            FSAL_Skip_Bytes(pFLVParser->pstFSAL, pFLVParser->FLVTAG_DataSize+FLV_PREV_TAG_SIZE_LENGTH);
        }
        else
        {
            // Error file
            //FLV_ASSERT(0);
            FSAL_Skip_Bytes(pFLVParser->pstFSAL, pFLVParser->FLVTAG_DataSize+FLV_PREV_TAG_SIZE_LENGTH);
        }
        if((u4VideoFPS > 0) && (ptMetaData->AudioFrameRate > 0))
        {
            if(ptMetaData->FLVHeader_TypeFlagsVideo != 0)
            {
                if(ptMetaData->FirstVideoTagOffset > 0)
                {
                    // 為了避免AVC config之後先來audio data再來video data
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (((ptMetaData->AudioFrameNum >= 10) && (ptMetaData->VideoFrameNum == 0)) ||
            ((ptMetaData->VideoFrameNum >= 10) && (ptMetaData->AudioFrameNum == 0)))
        {
            // Bad A/V interleave
            kal_trace(TRACE_GROUP_4, FLV_PARSER_NO_A_V_DATA, pFLVParser->FLVTAG_Timestamp,
                ptMetaData->AudioFrameNum, ptMetaData->VideoFrameNum);
            break;
        }

        if(ptMetaData->fgFastBreak == KAL_TRUE)
        {
            // The fast break parameter is set.
            video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_FLVPVDR_FAST_BREAK, __LINE__);
            kal_trace(TRACE_GROUP_4, FLV_PARSER_MEET_FAST_BREAK, __LINE__);
            return FLV_PARSER_FAST_BREAK;
        }
    }

    // 可能一張 audio/video 也沒有
    //FLV_ASSERT((bParseVideoConfig == KAL_FALSE) && (bParseAudioConfig == KAL_FALSE));

    if(ptMetaData->FirstVideoTagOffset == 0)
    {
        // No Video data or only video data header
        ptMetaData->FLVHeader_TypeFlagsVideo = 0;
    }
    if(ptMetaData->FirstAudioTagOffset == 0)
    {
        // No Video data or only video data header
        ptMetaData->FLVHeader_TypeFlagsAudio = 0;
    }

    if(ptMetaData->FLVHeader_TypeFlagsVideo != 0)
    {
        if(ptMetaData->VideoFrameRate == 0)
        {
            ptMetaData->VideoFrameRate = u4VideoFPS;
            if(u4VideoFPS == 0)
            {
                if(u4VideoFPSTemp > 0)
                {
                    ptMetaData->VideoFrameRate = u4VideoFPSTemp;
                }
                else
                {
                    // unknown frame rate...
                    ptMetaData->VideoFrameRate = FLV_UNKNOWN_FRAME_FATE;
                }
            }
        }
    }
    if(ptMetaData->FLVHeader_TypeFlagsAudio != 0)
    {
        if(ptMetaData->AudioFrameRate == 0)
        {
            if(u4AudioFPS > 0)
            {
                ptMetaData->AudioFrameRate = u4AudioFPS;
            }
            else
            {
                // unknown frame rate...
                ptMetaData->AudioFrameRate = FLV_UNKNOWN_FRAME_FATE;
            }
        }
    }

    if(ptMetaData->duration == 0)
    {
        // Use the timestamp of last frame as duration
        FSAL_Seek(pFLVParser->pstFSAL, uFileSize-FLV_PREV_TAG_SIZE_LENGTH);
        FSAL_Read_UINT(pFLVParser->pstFSAL, &u4Var);
        FSAL_Seek(pFLVParser->pstFSAL, uFileSize-FLV_PREV_TAG_SIZE_LENGTH-u4Var);
        if(FLV_PARSER_OK == FLV_Tag(pFLVParser))
        {
            ptMetaData->duration = pFLVParser->FLVTAG_Timestamp;
        }
    }

    ElapsedTime = video_get_duration_ms(ElapsedTime);
    ptMetaData->u4ParseTime = ElapsedTime;

    return FLV_PARSER_OK;
}

FLV_Parser_Status FLV_BuildKeyTable(FLVParser *pFLVParser, FLVMetaData *ptMetaData)
{
    kal_uint32 i;
    kal_uint32 keyFrameCount;
    FLV_KeyFrameTable *pKeyTable;
    kal_uint32 uFileSize;
    FLV_Parser_Status eParserStatus;
    kal_uint32 u4VideoFPS;

    FSAL_GetFileSize(pFLVParser->pstFSAL, &uFileSize);

    pKeyTable = &(ptMetaData->rKeyFrames);
    keyFrameCount = pKeyTable->Real_Count;
    u4VideoFPS = ptMetaData->VideoFrameRate;

    if(ptMetaData->FLVHeader_TypeFlagsVideo != 0)
    {
        i=0;
        if(keyFrameCount > 0)
        {
            FLV_ASSERT(pKeyTable->KeyOffestStart != 0);

            while((i<FLV_MAX_KEYFRAME_STORE) && (i<pKeyTable->Real_Count))
            {
                if(pKeyTable->au4FileVOffset[i] > uFileSize)
                {
                    break;
                }
                FSAL_Seek(pFLVParser->pstFSAL, pKeyTable->au4FileVOffset[i]);
                FLV_Tag(pFLVParser);
                if(pFLVParser->FLVTAG_TagType != VIDEO_TAG)
                {
                    FLV_PARSER_TRACE_PARSE_ERROR(pFLVParser->FLVTAG_TagType);
                    pKeyTable->au4Time[i] = pFLVParser->FLVTAG_Timestamp; //為什麼加offset的話會audio error?
                    pKeyTable->au4VFrmIdx[i] = FLV_PARSER_INVALID_UINT_VALUE;
                    i++;
                    continue;
                }

                eParserStatus = FLV_VideoTag(pFLVParser, ptMetaData);
                if(!((eParserStatus == FLV_PARSER_VIDEO_CONFIG_OK) ||
                       (eParserStatus == FLV_PARSER_VIDEO_DATA_OK) ||
                       (eParserStatus == FLV_PARSER_VIDEO_PKT_EOS) ||
                       (eParserStatus == FLV_PARSER_VIDEO_FRAME_TYPE_NOT_SUPPORT)))
                {
                    FLV_PARSER_TRACE_PARSE_ERROR(eParserStatus);
                    pKeyTable->au4Time[i] = pFLVParser->FLVTAG_Timestamp; //為什麼加offset的話會audio error?
                    pKeyTable->au4VFrmIdx[i] = FLV_PARSER_INVALID_UINT_VALUE;
                    i++;
                    continue;
                }
                pKeyTable->au4Time[i] = pFLVParser->FLVTAG_Timestamp; //為什麼加offset的話會audio error?
                pKeyTable->au4VFrmIdx[i] = (kal_uint32)((kal_uint64)(pFLVParser->FLVTAG_Timestamp)*u4VideoFPS/1000000);
                if(eParserStatus == FLV_PARSER_VIDEO_PKT_EOS) // AVC end of sequence
                {
                  FLV_ASSERT(i>0);
                  pKeyTable->au4Time[i] = pKeyTable->au4Time[i-1];
                  pKeyTable->au4VFrmIdx[i] = pKeyTable->au4VFrmIdx[i-1];
                }
                // audio的後面要用到時再算
                i++;
            }
            pKeyTable->valid_end_idx = i - 1;
        }
        else
        {
        #ifdef __VE_FLV_PSEUDO_KEY_TABLE__
            pKeyTable->au4FileVOffset[0] = ptMetaData->FirstVideoTagOffset;
            pKeyTable->au4Time[0] = 0;
            pKeyTable->au4VFrmIdx[0] = 0;
            pKeyTable->valid_end_idx = 0;
            pKeyTable->MaxReadOffset = pKeyTable->au4FileVOffset[0];
            pKeyTable->MaxReadTime= 0;
        #endif
        }
    }
    else
    {
        pKeyTable->Real_Count = 0;
        #ifdef __VE_FLV_PSEUDO_KEY_TABLE__
        pKeyTable->au4FileVOffset[0] = ptMetaData->FirstAudioTagOffset;
        pKeyTable->au4Time[0] = 0;
        pKeyTable->au4VFrmIdx[0] = 0;
        pKeyTable->valid_end_idx = 0;
        pKeyTable->MaxReadOffset = pKeyTable->au4FileVOffset[0];
        pKeyTable->MaxReadTime= 0;
        #endif
    }

    return FLV_PARSER_OK;
}

FLV_Parser_Status FLV_GetTrackAvail(FLVMetaData* pFLVMetadata, FLV_Track_Type eTrackType, kal_uint8 *has_this_track)
{
    FLV_ASSERT((pFLVMetadata != NULL) && (has_this_track != NULL));

    *has_this_track = 0xFF;

    if(eTrackType == FLV_TRACK_AUDIO)
    {
        if(pFLVMetadata->FLVHeader_TypeFlagsAudio != 0)
        {
            *has_this_track = FLV_TRACK_AUDIO;
        }
    }
    else if(eTrackType == FLV_TRACK_VIDEO)
    {
        if(pFLVMetadata->FLVHeader_TypeFlagsVideo != 0)
        {
            *has_this_track = FLV_TRACK_VIDEO;
        }
    }
    else
    {
        *has_this_track = FLV_RESERVED_TRACK_NO;
    }
    return FLV_PARSER_OK;
}

kal_uint32 FLV_GetCodecType(FLVMetaData* pFLVMetadata, FLV_Track_Type eTrackType)
{
    kal_uint32 ret = 0xFFFFFFFF;

    FLV_ASSERT(pFLVMetadata != NULL);

    if(eTrackType == FLV_TRACK_AUDIO)
    {
        ret = FLV_AUDIO_UNDEFINED;
        if(pFLVMetadata->FLVHeader_TypeFlagsAudio != 0)
        {
            ret = pFLVMetadata->AudioCodecId;
        }
    }
    else if(eTrackType == FLV_TRACK_VIDEO)
    {
        ret = FLV_VIDEO_UNDEFINED;
        if(pFLVMetadata->FLVHeader_TypeFlagsVideo != 0)
        {
            ret = pFLVMetadata->VideoCodecId;
        }
    }
    return ret;
}

FLV_Parser_Status FLV_GetMediaDuration(FLVMetaData* pFLVMetadata, kal_uint32 *pDuration)
{
    FLV_ASSERT((pFLVMetadata != NULL) && (pDuration != NULL));

    *pDuration = pFLVMetadata->duration;

    return FLV_PARSER_OK;
}

FLV_Parser_Status FLV_GetVideoResolution(FLVMetaData* pFLVMetadata, kal_uint32 *width, kal_uint32 *height)
{
    FLV_ASSERT((pFLVMetadata != NULL) && (width != NULL) && (height != NULL));

    *width = pFLVMetadata->width;
    *height = pFLVMetadata->height;

    return FLV_PARSER_OK;
}

FLV_Parser_Status FLV_GetAverageBitRate(FLVMetaData* pFLVMetadata, kal_uint32 *bitrate, FLV_Track_Type eTrackType)
{
    FLV_ASSERT((pFLVMetadata != NULL) && (bitrate != NULL));
    *bitrate = 0;
    if(eTrackType == FLV_TRACK_VIDEO)
    {
        *bitrate = pFLVMetadata->VideoDataRate;
    }
    else if(eTrackType == FLV_TRACK_AUDIO)
    {
        *bitrate = pFLVMetadata->AudioDataRate;
    }

    return FLV_PARSER_OK;
}

FLV_Parser_Status FLV_GetFrameRate(FLVMetaData* pFLVMetadata, kal_uint32 *fps)
{
    FLV_ASSERT((pFLVMetadata != NULL) && (fps != NULL));

    *fps = pFLVMetadata->VideoFrameRate;

    return FLV_PARSER_OK;
}

kal_uint16 FLV_Audio_GetChannelCount(FLVMetaData* pFLVMetadata)
{
    FLV_ASSERT(pFLVMetadata!=NULL);

    if(pFLVMetadata->AudioCodecId == FLV_AAC)
    {
        return (kal_uint16)pFLVMetadata->bAudioChannelConfig;
    }
    else
    {
        if(pFLVMetadata->stereo != 0)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
}

kal_uint16 FLV_Audio_GetSampleSize(FLVMetaData* pFLVMetadata)
{
    FLV_ASSERT(pFLVMetadata!=NULL);

    return (kal_uint16)pFLVMetadata->AudioSampleSize;
}

kal_uint32 FLV_Audio_GetSampleRate(FLVMetaData* pFLVMetadata)
{
    kal_uint32 u4Freq;

    FLV_ASSERT(pFLVMetadata!=NULL);

    if(pFLVMetadata->AudioCodecId == FLV_AAC)
    {
        if(pFLVMetadata->bAudioSamplingFreqIndex == 0xF)
        {
            u4Freq = pFLVMetadata->AudioSampleRate;
        }
        else
        {
            u4Freq = _FLVParserConvertSamplingIndexToFreq(pFLVMetadata->bAudioSamplingFreqIndex);
        }
    }
    else
    {
        u4Freq = pFLVMetadata->AudioSampleRate;
    }

    return u4Freq;
}

FLV_Parser_Status FLV_PrevKeyFramebyTime(FLVParser* pstParser, FLVMetaData* pFLVMetadata,
    kal_uint32 SeekTime,
    kal_uint32 *pKeyIndex, kal_uint32 *pOffset, kal_uint32 *pTime,
    FLV_Track_Type eTrackType)
{
  FLV_KeyFrameTable *ptKeyFrames = &(pFLVMetadata->rKeyFrames);
  FLV_Parser_Status eParserStatus;
  kal_uint32 i = 0;
  FSAL_Status eFSALStatus = FSAL_OK;
  kal_uint32 uFileSize;
  kal_bool fgBinarySearch = KAL_TRUE;

  FLV_ASSERT((pFLVMetadata != NULL) && (pKeyIndex != NULL) && (pOffset != NULL) && (pTime != NULL)
     && (pFLVMetadata->pt_fsal_key_table != NULL) && (pFLVMetadata->p_fsal_key_table_buf != NULL))

  kal_trace(TRACE_GROUP_4, FLV_PARSER_PREV_KEY_FRAME_INPUT,
    eTrackType, SeekTime);

  VIDEO_START_LOGGING("FV3");
  if(ptKeyFrames->Real_Count > 0)
  {
    if((SeekTime < ptKeyFrames->au4Time[0]) ||
       (SeekTime > ptKeyFrames->au4Time[ptKeyFrames->valid_end_idx]))
    {
      // key table not cache to the seek point

      kal_bool found = KAL_FALSE;
      kal_uint32 u4KeyIndex = 0;
      kal_uint8 PrecisionDouble[8];
      kal_uint8 type;
      kal_uint32 u4Var;
      kal_uint32 u4VideoFPS = 0;
      double dResult;

      /* With key frame (meta) case */
      if(SeekTime < ptKeyFrames->au4Time[0])
      {
        if(ptKeyFrames->last_index == ptKeyFrames->valid_end_idx)
        {
          /* key table的頭已經是index table的第一筆了 */
        }
        else
        {
          u4KeyIndex = ptKeyFrames->last_index-ptKeyFrames->valid_end_idx;

          // 先找到小於等於seek time的那一筆
          while((found == KAL_FALSE) && (((kal_int32)u4KeyIndex)>=0))
          {
            eFSALStatus = FSAL_Seek(pFLVMetadata->pt_fsal_key_table, ptKeyFrames->KeyTimestart+(u4KeyIndex*9));
            if (eFSALStatus != FSAL_OK)
            {
              FLV_ASSERT(0);
              FLV_PARSER_TRACE_FSAL_ERROR(eFSALStatus);
              return FLV_PARSER_FILE_ACCESS_ERROR;
            }
            if((pstParser->eFSALErr=FSAL_Read_Bytes(pFLVMetadata->pt_fsal_key_table, &type, 1))!=FSAL_OK)
            {
              return FLV_PARSER_FILE_READ_ERROR;
            }
            FLV_ASSERT(type == 0);
            if((pstParser->eFSALErr=FSAL_Read_Bytes(pFLVMetadata->pt_fsal_key_table, PrecisionDouble, 8))!=FSAL_OK)
            {
              return FLV_PARSER_FILE_READ_ERROR;
            }

            dResult = ConvIEEE754Double(PrecisionDouble);
            u4Var = (kal_uint32)(dResult*1000);
            if(u4Var <= SeekTime)
            {
              found = KAL_TRUE;
              break;
            }
            if(u4KeyIndex == 0)
            {
                break;
            }
            u4KeyIndex--;
          }
        }
      }
      else // (SeekTime > ptKeyFrames->au4Time[ptKeyFrames->valid_end_idx])
      {
        if(ptKeyFrames->last_index == ptKeyFrames->Real_Count-1)
        {
          /* keytable 已經存到最後一筆了*/
        }
        else
        {
          u4KeyIndex = ptKeyFrames->last_index;
          eFSALStatus = FSAL_Seek(pFLVMetadata->pt_fsal_key_table, ptKeyFrames->KeyTimestart+(u4KeyIndex*9));
          if (eFSALStatus != FSAL_OK)
          {
            FLV_ASSERT(0);
            FLV_PARSER_TRACE_FSAL_ERROR(eFSALStatus);
            return FLV_PARSER_FILE_ACCESS_ERROR;
          }

          // 先找到大於等於seek time的那一筆
          while((found == KAL_FALSE) && (u4KeyIndex<ptKeyFrames->Real_Count))
          {
            if((pstParser->eFSALErr=FSAL_Read_Bytes(pFLVMetadata->pt_fsal_key_table, &type, 1))!=FSAL_OK)
            {
              return FLV_PARSER_FILE_READ_ERROR;
            }
            FLV_ASSERT(type == 0);
            if((pstParser->eFSALErr=FSAL_Read_Bytes(pFLVMetadata->pt_fsal_key_table, PrecisionDouble, 8))!=FSAL_OK)
            {
              return FLV_PARSER_FILE_READ_ERROR;
            }

            dResult = ConvIEEE754Double(PrecisionDouble);
            u4Var = (kal_uint32)(dResult*1000);
            if(u4Var >= SeekTime)
            {
              found = KAL_TRUE;
              break;
            }
            u4KeyIndex++;
          }
          if(found == KAL_TRUE)
          {
              // u4KeyIndex這一筆的time應該會< seek time
              u4KeyIndex -= 1;
          }
          else
          {
              // Seek到檔尾, SeekTime >  最後一張key frame time
              found = KAL_TRUE;
              FLV_ASSERT(u4KeyIndex == ptKeyFrames->Real_Count);
              u4KeyIndex = ptKeyFrames->Real_Count - FLV_MAX_KEYFRAME_STORE;
          }
        }
      }// (SeekTime > ptKeyFrames->au4Time[ptKeyFrames->valid_end_idx])

      if(found == KAL_TRUE)
      {
        FLV_ASSERT(u4KeyIndex < ptKeyFrames->Real_Count);
        // 從u4KeyIndex開始存FLV_MAX_KEYFRAME_STORE筆或是存到底

        eFSALStatus = FSAL_Seek(pFLVMetadata->pt_fsal_key_table, ptKeyFrames->KeyOffestStart+(u4KeyIndex*9));
        if (eFSALStatus != FSAL_OK)
        {
          FLV_PARSER_TRACE_FSAL_ERROR(eFSALStatus);
          return FLV_PARSER_FILE_ACCESS_ERROR;
        }
        i = 0;
        while((i<FLV_MAX_KEYFRAME_STORE) && (u4KeyIndex+i<ptKeyFrames->Real_Count))
        {
          if((pstParser->eFSALErr=FSAL_Read_Bytes(pFLVMetadata->pt_fsal_key_table, &type, 1))!=FSAL_OK)
          {
            return FLV_PARSER_FILE_READ_ERROR;
          }
          FLV_ASSERT(type == 0);
          if((pstParser->eFSALErr=FSAL_Read_Bytes(pFLVMetadata->pt_fsal_key_table, PrecisionDouble, 8))!=FSAL_OK)
          {
            return FLV_PARSER_FILE_READ_ERROR;
          }

          dResult = ConvIEEE754Double(PrecisionDouble);
          u4Var = (kal_uint32)dResult;
          ptKeyFrames->au4FileVOffset[i] = u4Var;
          i++;
        }
        ptKeyFrames->valid_end_idx = i-1;
        ptKeyFrames->last_index = u4KeyIndex+i-1;

        eFSALStatus = FSAL_Seek(pFLVMetadata->pt_fsal_key_table, ptKeyFrames->KeyTimestart+(u4KeyIndex*9));
        if (eFSALStatus != FSAL_OK)
        {
          FLV_PARSER_TRACE_FSAL_ERROR(eFSALStatus);
          return FLV_PARSER_FILE_ACCESS_ERROR;
        }
        i = 0;
        u4VideoFPS = pFLVMetadata->VideoFrameRate/1000;

        FSAL_GetFileSize(pstParser->pstFSAL, &uFileSize);

        while(i<=ptKeyFrames->valid_end_idx)
        {
            if(ptKeyFrames->au4FileVOffset[i] > uFileSize)
            {
                FLV_ASSERT(i>0);
                ptKeyFrames->valid_end_idx = i-1;
                ptKeyFrames->last_index = u4KeyIndex+i-1;
                break;
            }
            FSAL_Seek(pstParser->pstFSAL, ptKeyFrames->au4FileVOffset[i]);
            FLV_Tag(pstParser);
            //FLV_ASSERT(pstParser->FLVTAG_TagType == VIDEO_TAG);
            if(pstParser->FLVTAG_TagType != VIDEO_TAG)
            {
                FLV_PARSER_TRACE_PARSE_ERROR(pstParser->FLVTAG_TagType);
                ptKeyFrames->au4Time[i] = pstParser->FLVTAG_Timestamp; //為什麼加offset的話會audio error?
                ptKeyFrames->au4VFrmIdx[i] = FLV_PARSER_INVALID_UINT_VALUE;
                i++;
                continue;
            }
            eParserStatus = FLV_VideoTag(pstParser, pFLVMetadata);
            if(!((eParserStatus == FLV_PARSER_VIDEO_CONFIG_OK) ||
                   (eParserStatus == FLV_PARSER_VIDEO_DATA_OK) ||
                   (eParserStatus == FLV_PARSER_VIDEO_PKT_EOS) ||
                   (eParserStatus == FLV_PARSER_VIDEO_FRAME_TYPE_NOT_SUPPORT)))
            {
                FLV_PARSER_TRACE_PARSE_ERROR(eParserStatus);
                ptKeyFrames->au4Time[i] = pstParser->FLVTAG_Timestamp;
                ptKeyFrames->au4VFrmIdx[i] = FLV_PARSER_INVALID_UINT_VALUE;
                i++;
                continue;
            }
            ptKeyFrames->au4Time[i] = pstParser->FLVTAG_Timestamp;
            ptKeyFrames->au4VFrmIdx[i] = (kal_uint32)((kal_uint64)(pstParser->FLVTAG_Timestamp)*u4VideoFPS/1000);
            if(eParserStatus == FLV_PARSER_VIDEO_PKT_EOS) // AVC end of sequence
            {
              FLV_ASSERT(i>0);
              ptKeyFrames->au4Time[i] = ptKeyFrames->au4Time[i-1];
              ptKeyFrames->au4VFrmIdx[i] = ptKeyFrames->au4VFrmIdx[i-1];
            }
            i++;
            // audio的後面要用到時再算
        }

      }
      else //(found == KAL_FALSE)
      {
          FLV_ASSERT((ptKeyFrames->last_index == ptKeyFrames->valid_end_idx) ||
                 (u4KeyIndex == 0) ||
                 (ptKeyFrames->last_index == ptKeyFrames->Real_Count-1) ||
                 (u4KeyIndex == ptKeyFrames->Real_Count-1));
      }
    }

  }
  else
  {
      /* No key frame */
      if(SeekTime == 0)
      {
        *pTime = 0;
        *pKeyIndex = 0;
        if(eTrackType == FLV_TRACK_VIDEO)
        {
          *pOffset = pFLVMetadata->FirstVideoTagOffset;
        }
        else
        {
          *pOffset = pFLVMetadata->FirstAudioTagOffset;
        }
        fgBinarySearch = KAL_FALSE;
      }
      else
      {
        kal_uint32 CurOffset = pFLVMetadata->LatestAudioTagOffset;
        kal_uint32 CurTime = pFLVMetadata->LatestAudioTagTime;

        #ifdef __VE_FLV_PSEUDO_KEY_TABLE__
        CurTime = FLV_GetPseuKeyTableMaxTime(pFLVMetadata, &CurOffset);
        if(CurTime <= SeekTime)
        {
          /* Build seek table */
          eFSALStatus = FSAL_Seek(pstParser->pstFSAL, CurOffset);
          if (eFSALStatus != FSAL_OK)
          {
            FLV_PARSER_TRACE_FSAL_ERROR(eFSALStatus);
            return FLV_PARSER_FILE_ACCESS_ERROR;
          }
          while(FLV_Tag(pstParser) == FLV_PARSER_OK)
          {
              FSAL_GetCurPos(pstParser->pstFSAL, &CurOffset);

              if((pFLVMetadata->FLVHeader_TypeFlagsVideo != 0) &&
                 (pstParser->FLVTAG_TagType == VIDEO_TAG))
              {
                eParserStatus = FLV_VideoTag(pstParser, pFLVMetadata);

                if(eParserStatus == FLV_PARSER_VIDEO_DATA_OK)
                {
                  if(pstParser->VideoFrameType == FLV_KEY_FRAME)
                  {
                    FLV_BuildPseuKeyTable(pFLVMetadata,
                        pstParser->FLVTAG_Timestamp, CurOffset-FLV_TAG_LENGTH);
                  }
                }
                FLV_UpdatePseuKeyTableMaxRead(pFLVMetadata, pstParser->FLVTAG_Timestamp, CurOffset-FLV_TAG_LENGTH);
                if(pstParser->FLVTAG_Timestamp >= SeekTime)
                {
                    break;
                }
              }
              else if((pFLVMetadata->FLVHeader_TypeFlagsVideo == 0) &&
                      (pstParser->FLVTAG_TagType == AUDIO_TAG))
              {
                FLV_ASSERT(pFLVMetadata->FLVHeader_TypeFlagsAudio != 0);
                eParserStatus = FLV_AudioTag(pstParser, pFLVMetadata);

                if(eParserStatus == FLV_PARSER_AUDIO_DATA_OK)
                {
                  FLV_BuildPseuKeyTable(pFLVMetadata,
                      pstParser->FLVTAG_Timestamp, CurOffset-FLV_TAG_LENGTH);
                  FLV_UpdatePseuKeyTableMaxRead(pFLVMetadata, pstParser->FLVTAG_Timestamp, CurOffset-FLV_TAG_LENGTH);
                  if(pstParser->FLVTAG_Timestamp >= SeekTime)
                  {
                      break;
                  }
                }
              }
              else
              {
                eFSALStatus = FSAL_Skip_Bytes(pstParser->pstFSAL, pstParser->FLVTAG_DataSize+4);
              }

              if(FSAL_OK != eFSALStatus)
              {
                FLV_PARSER_TRACE_FSAL_ERROR(eFSALStatus);
                return FLV_PARSER_FILE_ACCESS_ERROR;
              }
              if(pFLVMetadata->fgFastBreak == KAL_TRUE)
              {
                // The fast break parameter is set.
                video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_FLVPVDR_FAST_BREAK, __LINE__);
                kal_trace(TRACE_GROUP_4, FLV_PARSER_MEET_FAST_BREAK, __LINE__);
                return FLV_PARSER_FAST_BREAK;
              }
          }
        }
        #else
        *pTime = 0;
        *pKeyIndex = 0;
        if(eTrackType == FLV_TRACK_VIDEO)
        {
          *pOffset = pFLVMetadata->FirstVideoTagOffset;
          FLV_PARSER_TRACE_PARSE_ERROR(FLV_PARSER_METADATA_ERROR);
          return FLV_PARSER_METADATA_ERROR;
        }
        else
        {
          kal_uint32 uAudioFPS = pFLVMetadata->AudioFrameRate;

          FLV_ASSERT(uAudioFPS != 0);
          if(CurTime <= SeekTime)
          {
            *pTime = CurTime;
            *pKeyIndex = (kal_uint32)((kal_uint64)CurTime*uAudioFPS/1000000);
            *pOffset = CurOffset;
          }
          else
          {
            kal_uint32 uTagSize = 0;

            // 找之前<= SeekTime的audio frame
            FSAL_Seek(pstParser->pstFSAL, CurOffset-FLV_PREV_TAG_SIZE_LENGTH);
            FSAL_Read_UINT(pstParser->pstFSAL, &uTagSize);
            FSAL_Seek(pstParser->pstFSAL, CurOffset-(FLV_PREV_TAG_SIZE_LENGTH+uTagSize));
            while(FLV_Tag(pstParser) == FLV_PARSER_OK)
            {
              if((pstParser->FLVTAG_TagType == AUDIO_TAG) &&
                 (pstParser->FLVTAG_Timestamp <= SeekTime))
              {
                FSAL_GetCurPos(pstParser->pstFSAL, &CurOffset);
                eParserStatus = FLV_AudioTag(pstParser, pFLVMetadata);
                if(eParserStatus == FLV_PARSER_AUDIO_CONFIG_OK)
                {
                  // 已經往前找到最前面了
                  FLV_ASSERT(0);
                  break;
                }
                else if(eParserStatus == FLV_PARSER_AUDIO_DATA_OK)
                {
                  *pTime = pstParser->FLVTAG_Timestamp;
                  *pKeyIndex = (kal_uint32)((kal_uint64)(pstParser->FLVTAG_Timestamp)*uAudioFPS/1000000);
                  *pOffset = CurOffset - FLV_TAG_LENGTH;
                  break;
                }
                else
                {
                  FLV_PARSER_TRACE_PARSE_ERROR(eParserStatus);
                  break;
                }
              }
              else
              {
                FSAL_GetCurPos(pstParser->pstFSAL, &CurOffset);
                FSAL_Seek(pstParser->pstFSAL, CurOffset-(FLV_PREV_TAG_SIZE_LENGTH+FLV_TAG_LENGTH));
                FSAL_Read_UINT(pstParser->pstFSAL, &uTagSize);
                FSAL_Seek(pstParser->pstFSAL, CurOffset-(FLV_PREV_TAG_SIZE_LENGTH+FLV_TAG_LENGTH+uTagSize));
              }
            }
          }
        }
        fgBinarySearch = KAL_FALSE;
        #endif
      }
  }

  if(fgBinarySearch == KAL_TRUE)
  {
    //Binary search Key frame index
    kal_uint32 start = 0;
    kal_uint32 mid = 0;
    kal_uint32 end = ptKeyFrames->valid_end_idx;
    kal_uint32 hit = 0;

    if(ptKeyFrames->au4Time[1] == ptKeyFrames->au4Time[0])
    {
      // key table的第0筆和第1筆都是timestamp 0的那張，只是第0筆是header
      start = 1;
    }

    while ((end-start)>1)
    {
      mid = (start+end)>>1;
      if(SeekTime >= ptKeyFrames->au4Time[mid])
        start = mid;
      else
        end = mid;
    }
    if(SeekTime >= ptKeyFrames->au4Time[end])
    {
      hit = end;
    }
    else
    {
      hit = start;
    }

    *pTime = ptKeyFrames->au4Time[hit];

    if(ptKeyFrames->au4VFrmIdx[hit] == FLV_PARSER_INVALID_UINT_VALUE)
    {
        return FLV_PARSER_METADATA_ERROR;
    }

    if((eTrackType == FLV_TRACK_VIDEO) ||
       ((eTrackType == FLV_TRACK_AUDIO) && (pFLVMetadata->FLVHeader_TypeFlagsVideo == 0)))
    {
      *pKeyIndex = ptKeyFrames->au4VFrmIdx[hit];
      *pOffset = ptKeyFrames->au4FileVOffset[hit];
      if(*pTime == 0)
      {
          *pKeyIndex = 0;
          *pOffset = pFLVMetadata->FirstVideoTagOffset;
          if(eTrackType == FLV_TRACK_AUDIO)
          {
            *pOffset = pFLVMetadata->FirstAudioTagOffset;
          }

      }
    }
    else // FLV_TRACK_AUDIO
    {
      kal_uint32 uAOffset = 0;
      kal_uint32 uTagSize = 0;
      kal_bool bAFound = KAL_FALSE;

      FLV_ASSERT(pFLVMetadata->FLVHeader_TypeFlagsAudio != 0);

      // Key table裡面存的是video frame的offset和index
      eFSALStatus = FSAL_Seek(pstParser->pstFSAL, ptKeyFrames->au4FileVOffset[hit]);
      if (eFSALStatus != FSAL_OK)
      {
        FLV_PARSER_TRACE_FSAL_ERROR(eFSALStatus);
        return FLV_PARSER_FILE_ACCESS_ERROR;
      }

      // 找這張video key frame之前最近的audio frame
      bAFound = KAL_FALSE;
      FSAL_GetCurPos(pstParser->pstFSAL, &uAOffset);
      FSAL_Seek(pstParser->pstFSAL, uAOffset-FLV_PREV_TAG_SIZE_LENGTH);
      FSAL_Read_UINT(pstParser->pstFSAL, &uTagSize);
      FSAL_Seek(pstParser->pstFSAL, uAOffset-(FLV_PREV_TAG_SIZE_LENGTH+uTagSize));
      while(FLV_Tag(pstParser) == FLV_PARSER_OK)
      {
        if(pstParser->FLVTAG_TagType == AUDIO_TAG)
        {
          kal_uint32 uAudioFPS = pFLVMetadata->AudioFrameRate;

          FLV_ASSERT(uAudioFPS != 0);
          FSAL_GetCurPos(pstParser->pstFSAL, &uAOffset);
          eParserStatus = FLV_AudioTag(pstParser, pFLVMetadata);
          if(eParserStatus == FLV_PARSER_AUDIO_CONFIG_OK)
          {
            // 已經往前找到最前面了
            break;
          }
          else if(eParserStatus == FLV_PARSER_AUDIO_DATA_OK)
          {
            *pTime = pstParser->FLVTAG_Timestamp;
            *pKeyIndex = (kal_uint32)((kal_uint64)(pstParser->FLVTAG_Timestamp)*uAudioFPS/1000000);
            *pOffset = uAOffset - FLV_TAG_LENGTH;
            bAFound = KAL_TRUE;
            break;
          }
          else
          {
            FLV_PARSER_TRACE_PARSE_ERROR(eParserStatus);
            break;
          }
        }
        else
        {
          FSAL_GetCurPos(pstParser->pstFSAL, &uAOffset);
          FSAL_Seek(pstParser->pstFSAL, uAOffset-(FLV_PREV_TAG_SIZE_LENGTH+FLV_TAG_LENGTH));
          FSAL_Read_UINT(pstParser->pstFSAL, &uTagSize);
          FSAL_Seek(pstParser->pstFSAL, uAOffset-(FLV_PREV_TAG_SIZE_LENGTH+FLV_TAG_LENGTH+uTagSize));
        }
      }

      if(bAFound == KAL_FALSE)
      {
        // 如果往前找沒有的話 (第一張video key frame前面都沒有audio frame)
        eFSALStatus = FSAL_Seek(pstParser->pstFSAL, ptKeyFrames->au4FileVOffset[hit]);
        if (eFSALStatus != FSAL_OK)
        {
          FLV_PARSER_TRACE_FSAL_ERROR(eFSALStatus);
          return FLV_PARSER_FILE_ACCESS_ERROR;
        }
        while(FLV_Tag(pstParser) == FLV_PARSER_OK)
        {
          if(pstParser->FLVTAG_TagType == AUDIO_TAG)
          {
            kal_uint32 uAudioFPS = pFLVMetadata->AudioFrameRate;
            kal_uint32 uAOffset = 0;

            FSAL_GetCurPos(pstParser->pstFSAL, &uAOffset);
            *pTime = pstParser->FLVTAG_Timestamp;
            *pKeyIndex = (kal_uint32)((kal_uint64)(pstParser->FLVTAG_Timestamp)*uAudioFPS/1000000);
            *pOffset = uAOffset - FLV_TAG_LENGTH;
            bAFound = KAL_TRUE;
            break;
          }
          else
          {
              FSAL_Skip_Bytes(pstParser->pstFSAL, pstParser->FLVTAG_DataSize+FLV_PREV_TAG_SIZE_LENGTH);
          }
        }
      }

      if(bAFound != KAL_TRUE)
      {
          return FLV_PARSER_FILE_ACCESS_ERROR;
      }
    }
  }

  kal_trace(TRACE_GROUP_4, FLV_PARSER_PREV_KEY_FRAME_OUTPUT,
    *pTime, *pOffset, *pKeyIndex);

  VIDEO_STOP_LOGGING("FV3");
  return FLV_PARSER_OK;
}

kal_bool ValidateFLVFormat(void* FileName)
{
    FSAL_Status eStatus;
    STFSAL tFsal;
    kal_uint32 FileData;
    kal_bool ret = KAL_FALSE;

    eStatus = FSAL_Open(&tFsal, FileName, FSAL_READ_SHARED);
    if(FSAL_OK != eStatus)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(eStatus);
        return KAL_FALSE;
    }

    // FLV Signature
    if((eStatus=FSAL_Read_UINT24(&tFsal, &FileData))!=FSAL_OK)
    {
        ret = KAL_FALSE;
    }

    if(FileData != FLV_FILE_START)
    {
        ret = KAL_FALSE;
    }
    else
    {
        ret = KAL_TRUE;
    }

    eStatus = FSAL_Close(&tFsal);

    return ret;
}

kal_bool ValidateF4VFormat(void* FileName)
{
    FSAL_Status eStatus;
    STFSAL tFsal;
    kal_uint32 FileData;
    kal_bool ret = KAL_FALSE;

    eStatus = FSAL_Open(&tFsal, FileName, FSAL_READ_SHARED);
    if(FSAL_OK != eStatus)
    {
        FLV_PARSER_TRACE_FSAL_ERROR(eStatus);
        return KAL_FALSE;
    }

    // F4V File Type 4CC code == "f4v " or "isom"
    if((eStatus=FSAL_Read_UINT(&tFsal, &FileData))!=FSAL_OK)
    {
        ret = KAL_FALSE;
    }
    if((eStatus=FSAL_Read_UINT(&tFsal, &FileData))!=FSAL_OK)
    {
        ret = KAL_FALSE;
    }
    if(FileData == 0x66747970) /* "ftyp" */
    {
        if((eStatus=FSAL_Read_UINT(&tFsal, &FileData))!=FSAL_OK)
        {
            ret = KAL_FALSE;
        }
        else
        {
            if((FileData == 0x66347620) /* f4v */  ||
               (FileData == 0x69736F6D) /* isom */)
            {
                ret = KAL_TRUE;
            }
        }
    }

    eStatus = FSAL_Close(&tFsal);
    return ret;
}

#ifdef __VE_FLV_PSEUDO_KEY_TABLE__
void FLV_BuildPseuKeyTable(FLVMetaData *pMetadata, kal_uint32 uTime, kal_uint32 uOffset)
{
    FLV_KeyFrameTable *ptKeyFrames = &(pMetadata->rKeyFrames);
    kal_uint32 i = 0;
    kal_uint32 u4VideoFPS = pMetadata->VideoFrameRate;
    kal_uint32 u4AudioFPS = pMetadata->AudioFrameRate;


    // ptKeyFrames->valid_end_idx reached FLV_MAX_KEYFRAME_STORE handling

    FLV_ASSERT(ptKeyFrames->Real_Count == 0);

    kal_take_mutex(eFLVParserMutex);

    if(uTime >= pMetadata->rKeyFrames.MaxReadTime)
    {
        if((ptKeyFrames->valid_end_idx+1) >= FLV_MAX_KEYFRAME_STORE)
        {
            // Full. Subsample the key frames
            ptKeyFrames->interval <<= 1;
            ptKeyFrames->accum = 0;
            for(i=0; i<FLV_MAX_KEYFRAME_STORE; i+=2)
            {
                ptKeyFrames->au4FileVOffset[i/2] = ptKeyFrames->au4FileVOffset[i];
                ptKeyFrames->au4Time[i/2] = ptKeyFrames->au4Time[i];
                ptKeyFrames->au4VFrmIdx[i/2] = ptKeyFrames->au4VFrmIdx[i];
            }
            ptKeyFrames->valid_end_idx /= 2;
        }

        ptKeyFrames->accum = (ptKeyFrames->accum+1)%ptKeyFrames->interval;
        if(ptKeyFrames->accum == 0)
        {
            ptKeyFrames->valid_end_idx++;
            i = ptKeyFrames->valid_end_idx;
            ptKeyFrames->au4FileVOffset[i] = uOffset;
            ptKeyFrames->au4Time[i] = uTime;
            ptKeyFrames->au4VFrmIdx[i] = (kal_uint32)((kal_uint64)uTime*u4VideoFPS/1000000);
            if(pMetadata->FLVHeader_TypeFlagsVideo == 0)
            {
                // Audio only playback case
                ptKeyFrames->au4VFrmIdx[i] = (kal_uint32)((kal_uint64)uTime*u4AudioFPS/1000000);
            }
        }
    }
    kal_give_mutex(eFLVParserMutex);
}

kal_uint32 FLV_GetPseuKeyTableMaxTime(FLVMetaData *pMetadata, kal_uint32* puOffset)
{
    kal_take_mutex(eFLVParserMutex);
    *puOffset = pMetadata->rKeyFrames.MaxReadOffset;
    kal_give_mutex(eFLVParserMutex);

    return pMetadata->rKeyFrames.MaxReadTime;
}

void FLV_UpdatePseuKeyTableMaxRead(FLVMetaData *pMetadata, kal_uint32 uTime, kal_uint32 uOffset)
{
    if(uTime > pMetadata->rKeyFrames.MaxReadTime)
    {
        kal_take_mutex(eFLVParserMutex);
        pMetadata->rKeyFrames.MaxReadOffset = uOffset;
        pMetadata->rKeyFrames.MaxReadTime= uTime;
        kal_give_mutex(eFLVParserMutex);
    }
}

#endif /* __VE_FLV_PSEUDO_KEY_TABLE__ */


#endif /* __VE_FLV_FILE_FORMAT_SUPPORT__ */

