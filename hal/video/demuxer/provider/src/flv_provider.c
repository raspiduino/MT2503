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
 *   flv_provider.c
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
 ****************************************************************************/

#include "drv_features_video.h"

#ifdef __VE_FLV_FILE_FORMAT_SUPPORT__

#include "fsal.h"

#include "source_provider_if.h"
#include "media_common.h"

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "vcodec_v2_trc.h"
#include "video_dbg_v2.h"
#include "video_comm_v2.h"

#include "flv_provider.h"
#include "flv_parser.h"

#define FLV_MP_TRACE_GROUP TRACE_GROUP_2

#define FLV_PROVIDER_CHECK_CONTAINER_LEN 3
#define FLV_MP_VID_FPS_UPPER_BOUND (12000)
#define FLV_PROVIDER_MIN_ACCU_TIME (10)
#define FLV_MP_SAMPLE_NO_MAX (0xFFFFFFFF)
#define FLV_MP_DURATION_MARGIN (500)

#define FLV_MP_TRACE_PARSE_ERROR(x) kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_PARSER_ERROR, x, __LINE__);
#define FLV_MP_TRACE_FSAL_ERROR(x) kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_FSAL_ERROR, x, __LINE__);
#define FLV_MP_TRACE_RET_ERR(x) kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_RET_ERR, x, __LINE__);
#define FLV_MP_TRACE_ERROR(x) kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_ERROR, x, __LINE__);
#define FLV_PVDR_TRACE_3_VAL(v1,v2,v3) kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_3_VAL, v1, v2, v3, __LINE__);
#define FLV_MP_HAS_TRACK(_track_) ((self->track_no[_track_]) != FLV_RESERVED_TRACK_NO)


#ifndef __VE_SLIM_PROJECT__
#define FLV_START_LOGGING(sym)  VIDEO_START_LOGGING(sym)
#define FLV_STOP_LOGGING(sym) VIDEO_STOP_LOGGING(sym)
#else
#define FLV_START_LOGGING(sym)  do{}while(0);
#define FLV_STOP_LOGGING(sym) do{}while(0);
#endif

#ifdef FLV_PROVIDER_NO_ASSERT_TRACE
#undef FLV_ASSERT
#define FLV_ASSERT( exp )          \
{                           \
    do{}while(0);\
}

#define kal_trace(...)  do{}while(0);
#define video_dbg_trace(...)  do{}while(0);
#endif

/* Design for bitstream buffer size not enough for single frame
     Video: 512 bytes reading
     Audio: No data reading, but buffer header with silence is sent to maintain correct duration
 */
#define FLV_PARTIAL_DATA_READ

static FLV_PROVIDER_CTRL_T* pFLVProviderHdlr;

#if 0
/* under construction !*/
/* under construction !*/
#endif

#ifdef __VE_H264_DEC_SUPPORT__
/* 把parameter set的資料讀進來. AVCDecoderConfigurationRecord of H.264 */
static PROVIDER_ERROR_T _FLVProviderGetParameterSetData(FLV_PROVIDER_CTRL_T *self,
                                                    FLVParser *pFLVParser,
                                                    FLVMetaData*pFLVMetadata,
                                                    FLV_VIDEO_CODEC_FORMAT eVideoDecodeType)
{
    PU_VID_PARAM_SET_T *prVideoParamSetData;
    kal_uint32 u4ParamPosition;
    SP_API_T *prSrcAPI = self->prSourceAPI;

    FLV_ASSERT(self);

    prVideoParamSetData = self->prVideoParamSetData;

    if (!pFLVParser || !prVideoParamSetData)
    {
        FLV_ASSERT(0);
        return PROVIDER_ERROR;
    }

    // Get parameter set information
    // MPEG-4 or H.264
    //
    if (FLV_AVC == eVideoDecodeType)
    {
        // Get AVC information, size info of NAL
        prVideoParamSetData->u4NALuSizeInfo = pFLVMetadata->rAVCDecConfig.LengthSizeMinusOne + 1;
#ifdef __VE_DUMP_PROVIDER_BITSTREAM__
        kal_trace(TRACE_GROUP_1, VE_TRC_H264_NALUSIZELEN, prVideoParamSetData->u4NALuSizeInfo);
#endif
        /* Position is from numOfSequenceParameterSets */
        u4ParamPosition = pFLVMetadata->rAVCDecConfig.offset;
        prVideoParamSetData->u4ParamSetTotalSize = pFLVMetadata->rAVCDecConfig.totalSize;

        if (prVideoParamSetData->u4ParamSetTotalSize > FLV_MP_PARAMSET_LENGTH)
        {
            FLV_MP_TRACE_ERROR(prVideoParamSetData->u4ParamSetTotalSize);
            return PROVIDER_ERROR;
        }

        if (!(prVideoParamSetData->u4ParamSetTotalSize == 0))
        {
            prVideoParamSetData->pu1ParamSetBuff = (kal_uint8*)prSrcAPI->SPFN_MALLOC_CLA(self->prSourceHandle,
                                          prVideoParamSetData->u4ParamSetTotalSize, KAL_FALSE);
            FLV_ASSERT(prVideoParamSetData->pu1ParamSetBuff != NULL);
            kal_mem_set(prVideoParamSetData->pu1ParamSetBuff, 0, prVideoParamSetData->u4ParamSetTotalSize);

            // Read parameter sets from file system
            if((pFLVParser->eFSALErr=FSAL_Seek(pFLVParser->pstFSAL, u4ParamPosition))!=FSAL_OK)
            {
                FLV_MP_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
                return PROVIDER_ERROR;
            }
            if((pFLVParser->eFSALErr=FSAL_Read(pFLVParser->pstFSAL, prVideoParamSetData->pu1ParamSetBuff, prVideoParamSetData->u4ParamSetTotalSize))!=FSAL_OK)
            {
                FLV_MP_TRACE_FSAL_ERROR(pFLVParser->eFSALErr);
                return PROVIDER_ERROR;
            }

            // Obtain Parameter set NAL units
            ProviderUtilityGetParamSetNalUnits(self->prSourceAPI,self->prSourceHandle,
                                              prVideoParamSetData);
        }
    }

    kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_PARAM_SET_INFO,
              prVideoParamSetData->u4ParamSetTotalSize, prVideoParamSetData->u4NumOfNALuParamSet);

    return PROVIDER_ERROR_NONE;
}
#endif

/* To parse the FLV file for opening. Width, height, A/V codec types */
static PROVIDER_ERROR_T _FLVProviderOpenCore(FLV_PROVIDER_CTRL_T* self)
{
    PROVIDER_ERROR_T eRet = PROVIDER_ERROR_NONE;
    FSAL_Status eStatus;
    FLV_Parser_Status eParserReturn;
    kal_uint8 has_aud_track = FLV_RESERVED_TRACK_NO;
    kal_uint8 has_vid_track = FLV_RESERVED_TRACK_NO;
    FLV_VIDEO_CODEC_FORMAT eVideoType = FLV_VIDEO_UNDEFINED;
    FLV_AUDIO_CODEC_FORMAT eAudioType = FLV_AUDIO_UNDEFINED;
    kal_uint32 duration;
    kal_int32 fs_ret = 0;
    SP_API_T *prSrcAPI = self->prSourceAPI;
    SPIF_VIDEO_STREAM_INFO_T *pt_stream_vid_info = NULL;
    SPIF_AUDIO_STREAM_INFO_T *pt_stream_aud_info = NULL;
    kal_uint32 u4VideoRet = 0;
    kal_uint32 u4AudioRet = 0;

    FLV_ASSERT(self->eSrcType == MED_MODE_FILE || self->eSrcType == MED_MODE_PREVIEW);

    /* (1) open media for video (metadata parsing) */
    if (self->eSrcType!= MED_MODE_BUFFER)
    {
        eStatus = FSAL_Open(self->pt_fsal[FLV_TRACK_VIDEO], (void*)self->u_src.file_name, FSAL_READ_SHARED);
        if (FSAL_OK != eStatus)
        {
            FLV_MP_TRACE_RET_ERR(eStatus);
            return PROVIDER_ERROR;
        }
        self->file_handle = self->pt_fsal[FLV_TRACK_VIDEO]->hFile;

        FSAL_SetBuffer(self->pt_fsal[FLV_TRACK_VIDEO],
                       (kal_uint32)FLV_MP_FSAL_BUF_SIZE*4,
                       (kal_uint8*)self->p_fsal_buf[FLV_TRACK_VIDEO]);

        eStatus = FSAL_GetFileSize(self->pt_fsal[FLV_TRACK_VIDEO], &(self->file_size));
        if (eStatus != FSAL_OK)
        {
            FLV_MP_TRACE_FSAL_ERROR(eStatus);
            return PROVIDER_ERROR;
        }

        { // Set File System Seek Hint to speed File seek operation
            kal_uint32 i;
            kal_uint64 temp;

            for (i = 0; i < FLV_MP_SEEK_HINT_SIZE; i++)
            {
                temp = ((kal_uint64)self->file_size * (kal_uint64)(i + 1)) / (kal_uint64)(FLV_MP_SEEK_HINT_SIZE + 1);
                self->pt_fsal_seek_hint[i].Index = (kal_uint32)temp;
            }
        }

        fs_ret = FS_SetSeekHint(self->pt_fsal[FLV_TRACK_VIDEO]->hFile,
                                    FLV_MP_SEEK_HINT_SIZE,
                                    self->pt_fsal_seek_hint);
        if (fs_ret < 0)
        {
            FLV_MP_TRACE_FSAL_ERROR(fs_ret);
            return PROVIDER_ERROR;
        }
    }
    else
    {
        FSAL_Direct_SetRamFileSize(self->pt_fsal[FLV_TRACK_VIDEO], self->file_size);
        eStatus = FSAL_Open(self->pt_fsal[FLV_TRACK_VIDEO], (void*)self->u_src.file_buf_addr, FSAL_ROMFILE);
        if (eStatus != FSAL_OK)
        {
            FLV_MP_TRACE_FSAL_ERROR(eStatus);
            return PROVIDER_ERROR;
        }
    }

    /* (2) Activate parser. A/V codec, duration, index table building is performed */
    eParserReturn = FLV_Parse(self->ptFLVParser[FLV_TRACK_VIDEO],
        self->pt_fsal[FLV_TRACK_VIDEO], self->ptFLVMetaData);
    if(eParserReturn != FLV_PARSER_OK)
    {
        FLV_MP_TRACE_PARSE_ERROR(eParserReturn);
        return PROVIDER_ERROR;
    }

    /* Initialize seek parameters */
    kal_mem_set(&(self->t_seek_param), 0, sizeof(FLV_PVDR_SEEK_STRUCT)*FLV_TRACK_TOTAL);
    self->t_seek_param[FLV_TRACK_AUDIO].u4Offset= self->ptFLVMetaData->FirstAudioTagOffset;
    self->t_seek_param[FLV_TRACK_VIDEO].u4Offset= self->ptFLVMetaData->FirstVideoTagOffset;

    /*  (3) check if there is any supported video track */
    eParserReturn = FLV_GetTrackAvail(self->ptFLVMetaData, FLV_TRACK_VIDEO, &has_vid_track);
    if (!(self->eTrack & SOURCE_PROVIDER_TRACK_VIDEO))
    {
        has_vid_track = FLV_RESERVED_TRACK_NO;
    }
    else if (has_vid_track != FLV_RESERVED_TRACK_NO)
    {
        eVideoType = (FLV_VIDEO_CODEC_FORMAT)FLV_GetCodecType(self->ptFLVMetaData, FLV_TRACK_VIDEO);

#ifndef __VE_H264_DEC_SUPPORT__
        if (eVideoType == FLV_AVC)
        {
            has_vid_track = FLV_RESERVED_TRACK_NO;
        }
#endif

        if (eVideoType != FLV_AVC)
        {
            has_vid_track = FLV_RESERVED_TRACK_NO;
        }
    }
    self->track_no[FLV_TRACK_VIDEO] = has_vid_track;

    /* (4) check if there is any supported audio track */
    eParserReturn = FLV_GetTrackAvail(self->ptFLVMetaData, FLV_TRACK_AUDIO, &has_aud_track);
    if (!(self->eTrack & SOURCE_PROVIDER_TRACK_AUDIO))
    {
        has_aud_track = FLV_RESERVED_TRACK_NO;
    }
    else if (has_aud_track != FLV_RESERVED_TRACK_NO)
    {
        eAudioType = (FLV_AUDIO_CODEC_FORMAT)FLV_GetCodecType(self->ptFLVMetaData, FLV_TRACK_AUDIO);

        switch(eAudioType)
        {
        case FLV_AAC:
        #ifndef AAC_DECODE
            has_aud_track = FLV_RESERVED_TRACK_NO;
        #endif
            break;

        case FLV_MP3:
        case FLV_MP3_8K:
        #ifndef DAF_DECODE
            has_aud_track = FLV_RESERVED_TRACK_NO;
        #endif
            break;

        case FLV_LINEAR_PCM_LE:
        #ifndef WAV_CODEC
            has_aud_track = FLV_RESERVED_TRACK_NO;
        #endif
            break;

        default:
            has_aud_track = FLV_RESERVED_TRACK_NO;
            break;
        }

    }
    self->track_no[FLV_TRACK_AUDIO] = has_aud_track;

    /* (5) Video stream information acquisition */
    do
    {
        if (has_vid_track != FLV_RESERVED_TRACK_NO)
        {
            FLV_ASSERT(has_vid_track == FLV_TRACK_VIDEO);

            if (self->prVidStreamInfo == NULL)
            {
               self->prVidStreamInfo = (SPIF_VIDEO_STREAM_INFO_T *)prSrcAPI->SPFN_MALLOC_CLA(self->prSourceHandle,
                                                                   sizeof(SPIF_VIDEO_STREAM_INFO_T), KAL_FALSE);
               if (self->prVidStreamInfo == NULL)
               {
                   FLV_MP_TRACE_RET_ERR(MED_E_OPEN_FILE_FAIL);
                   u4VideoRet = 1;
                   break;
               }
               kal_mem_set(self->prVidStreamInfo, 0, sizeof(SPIF_VIDEO_STREAM_INFO_T));
            }
            pt_stream_vid_info = self->prVidStreamInfo;
            pt_stream_vid_info->u4StreamIndex = self->track_no[FLV_TRACK_VIDEO];

            eParserReturn = FLV_GetMediaDuration(self->ptFLVMetaData, &duration);
            if (eParserReturn != FLV_PARSER_OK)
            {
                u4VideoRet = 2;
                break;
            }
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            pt_stream_vid_info->u8Duration = duration; // milliseconds

            eParserReturn = FLV_GetVideoResolution(self->ptFLVMetaData,
                                                  &(pt_stream_vid_info->u4Width),
                                                  &(pt_stream_vid_info->u4Height));
            if (eParserReturn != FLV_PARSER_OK
                #if 0
/* under construction !*/
/* under construction !*/
                #endif
                )
            {
                u4VideoRet = 4;
                break;
            }
            pt_stream_vid_info->u4Fps = 0;
            eParserReturn = FLV_GetAverageBitRate(self->ptFLVMetaData,
                                                 &(pt_stream_vid_info->u4AvgBitrate),
                                                 FLV_TRACK_VIDEO);

            //if (duration > 0)
            {
                kal_uint32 fps = 0;

                FLV_GetFrameRate(self->ptFLVMetaData, &fps);
                fps /= 10;

                pt_stream_vid_info->u4Fps = fps;

                #if 0 // Not to block frame rate. Best effort decode & display
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
            }

            switch (eVideoType)
            {
            #ifdef __VE_H264_DEC_SUPPORT__
            case FLV_AVC:
                pt_stream_vid_info->eCodecType = MEDIA_CODEC_VID_H264;
                break;
            #endif

            default:
                u4VideoRet = 8;
                break;
            }

            if(!(self->eTrack & SOURCE_PROVIDER_TRACK_META))
            {
                // FLV provider is opened for stream information
                // Parameter set resources is NOT allocated

                switch (eVideoType)
                {
                #ifdef __VE_H264_DEC_SUPPORT__
                case FLV_AVC:
                    eRet = _FLVProviderGetParameterSetData(self,
                                                         self->ptFLVParser[FLV_TRACK_VIDEO],
                                                         self->ptFLVMetaData,
                                                         FLV_AVC);
                    if (eRet != PROVIDER_ERROR_NONE)
                    {
                        u4VideoRet = 6;
                        break;
                    }
                    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #endif
                    break;
                #endif

                default:
                    u4VideoRet = 8;
                    break;

                }

                eStatus = FSAL_Open_Attach(self->pt_fsal_mdat[FLV_TRACK_VIDEO], self->pt_fsal[FLV_TRACK_VIDEO]);
                if (eStatus != FSAL_OK)
                {
                    u4VideoRet = 9;
                    break;
                }
            }

            kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_HAS_VIDEO,
                      pt_stream_vid_info->eCodecType,
                      pt_stream_vid_info->u4Fps,
                      pt_stream_vid_info->u4AvgBitrate,
                      pt_stream_vid_info->u8Duration);

        }
    }while(0);
    if(u4VideoRet != 0)
    {
        if (self->prVidStreamInfo)
        {
            prSrcAPI->SPFN_FREE_CLA(self->prSourceHandle, self->prVidStreamInfo);
        }
        self->prVidStreamInfo = NULL;
        self->track_no[FLV_TRACK_VIDEO] = FLV_RESERVED_TRACK_NO;
        FLV_MP_TRACE_ERROR(u4VideoRet);
    }

    /* (6) Audio stream information acquisition */
    do
    {
        if (has_aud_track != FLV_RESERVED_TRACK_NO)
        {
            FLV_ASSERT(has_aud_track == FLV_TRACK_AUDIO);

            if (self->prAudStrmInfo == NULL)
            {
               self->prAudStrmInfo =
                   (SPIF_AUDIO_STREAM_INFO_T *)prSrcAPI->SPFN_MALLOC_CLA(self->prSourceHandle,
                                               sizeof(SPIF_AUDIO_STREAM_INFO_T), KAL_FALSE);
               if (self->prAudStrmInfo == NULL)
               {
                   u4AudioRet = 3;
                   break;
               }
               kal_mem_set(self->prAudStrmInfo, 0, sizeof(SPIF_AUDIO_STREAM_INFO_T));
            }
            pt_stream_aud_info = self->prAudStrmInfo;

            pt_stream_aud_info->u4StreamIndex = self->track_no[FLV_TRACK_AUDIO];

            eParserReturn = FLV_GetMediaDuration(self->ptFLVMetaData, &duration);

            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            pt_stream_aud_info->u8Duration= duration;

            pt_stream_aud_info->u2Channels = FLV_Audio_GetChannelCount(self->ptFLVMetaData);
            pt_stream_aud_info->u2BitsPerSample = FLV_Audio_GetSampleSize(self->ptFLVMetaData);
            pt_stream_aud_info->u4SampleRate = FLV_Audio_GetSampleRate(self->ptFLVMetaData);

            pt_stream_aud_info->u4FrameDuration = 0;
            pt_stream_aud_info->fgAddHeader = KAL_FALSE;

            switch (eAudioType)
            {
            case FLV_LINEAR_PCM: // (0)
            case FLV_ADPCM: //(1)
            case FLV_LINEAR_PCM_LE: //(3)
            case FLV_G711_ALAW_PCM: // (7)
            case FLV_G711_MULAW_PCM: // (8)
                pt_stream_aud_info->eCodecType = MEDIA_CODEC_AUD_PCM;
                break;

            case FLV_MP3: // (2)
            case FLV_MP3_8K: // (14)
                pt_stream_aud_info->eCodecType = MEDIA_CODEC_AUD_MPEGLAYER3;
                break;

            case FLV_AAC: // (10)
                pt_stream_aud_info->eCodecType = MEDIA_CODEC_AUD_AAC;
                pt_stream_aud_info->fgAddHeader = KAL_TRUE;
                break;

            default:
                u4AudioRet = 5;
                break;

            }

            if(!(self->eTrack & SOURCE_PROVIDER_TRACK_META))
            {
                // FLV provider is opened for stream information
                // FSAL resources is NOT allocated
                if (self->eSrcType != MED_MODE_BUFFER)
                {
                    eStatus = FSAL_Open(self->pt_fsal[FLV_TRACK_AUDIO], (void*)self->u_src.file_name, FSAL_READ_SHARED);
                }
                else
                {
                    FSAL_Direct_SetRamFileSize(self->pt_fsal[FLV_TRACK_AUDIO], self->file_size);
                    eStatus = FSAL_Open(self->pt_fsal[FLV_TRACK_AUDIO], (void*)self->u_src.file_buf_addr, FSAL_ROMFILE);
                }

                if (eStatus != FSAL_OK)
                {
                    u4AudioRet = 1;
                    break;
                }

                if (self->eSrcType != MED_MODE_BUFFER)
                {
                    fs_ret = FS_SetSeekHint(self->pt_fsal[FLV_TRACK_AUDIO]->hFile,
                                                FLV_MP_SEEK_HINT_SIZE,
                                                self->pt_fsal_seek_hint);
                    if (fs_ret < 0)
                    {
                        u4AudioRet = 2;
                        break;
                    }

                    FSAL_SetBuffer(self->pt_fsal[FLV_TRACK_AUDIO],
                                   (kal_uint32)FLV_MP_FSAL_AUD_BUF_SIZE*4,
                                   (kal_uint8*)self->p_fsal_buf[FLV_TRACK_AUDIO]);
                }

                eStatus = FSAL_Open_Attach(self->pt_fsal_mdat[FLV_TRACK_AUDIO], self->pt_fsal[FLV_TRACK_AUDIO]);
                if (eStatus != FSAL_OK)
                {
                    u4AudioRet = 6;
                    break;
                }
            }

            kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_HAS_AUDIO,
                      pt_stream_aud_info->eCodecType,
                      pt_stream_aud_info->u4SampleRate,
                      pt_stream_aud_info->u2BitsPerSample,
                      pt_stream_aud_info->u8Duration);

        }
    } while (0);
    if(u4AudioRet != 0)
    {
        if (self->prAudStrmInfo)
        {
            prSrcAPI->SPFN_FREE_CLA(self->prSourceHandle, self->prAudStrmInfo);
        }
        self->prAudStrmInfo = NULL;
        self->track_no[FLV_TRACK_AUDIO] = FLV_RESERVED_TRACK_NO;
        FLV_MP_TRACE_ERROR(u4AudioRet);
    }

    if (has_vid_track == FLV_RESERVED_TRACK_NO && has_aud_track == FLV_RESERVED_TRACK_NO)
    {
        if ((self->eTrack == SOURCE_PROVIDER_TRACK_VIDEO) || (self->eTrack == SOURCE_PROVIDER_TRACK_AUDIO))
        {
            FLV_MP_TRACE_RET_ERR(MED_E_NO_REQUIRED_TRACK);
            return PROVIDER_ERROR_NONE;
        }
        else
        {
            FLV_MP_TRACE_RET_ERR(MED_E_OPEN_FILE_FAIL);
            return PROVIDER_ERROR_NONE;
        }
    }

    /* (7) open FSAL for key table */
    eStatus = FSAL_Open(self->ptFLVMetaData->pt_fsal_key_table, (void*)self->u_src.file_name, FSAL_READ_SHARED);
    if (FSAL_OK != eStatus)
    {
        FLV_MP_TRACE_RET_ERR(eStatus);
        return PROVIDER_ERROR;
    }

    FSAL_SetBuffer(self->ptFLVMetaData->pt_fsal_key_table,
                   (kal_uint32)FLV_MP_FSAL_BUF_SIZE*4,
                   (kal_uint8*)self->ptFLVMetaData->p_fsal_key_table_buf);

    if(!(self->eTrack & SOURCE_PROVIDER_TRACK_META))
    {
        // Parse index table
        eParserReturn = FLV_BuildKeyTable(self->ptFLVParser[FLV_TRACK_VIDEO], self->ptFLVMetaData);
    }

    return PROVIDER_ERROR_NONE;
}

/* To initialize control structure and allocate core memory */
static void _FLVProviderSelfInit(FLV_PROVIDER_CTRL_T* self)
{
    SP_TRACK_T e_track = self->eTrack;
    flv_mp_track_buf_pool_aud* pt_track_pool_a = NULL;
    flv_mp_track_buf_pool_vid* pt_track_pool_v = NULL;
    flv_mp_common_buf_pool* pt_comn_pool = NULL;
    SP_API_T *prSrcAPI = self->prSourceAPI;

    self->prVidStreamInfo = NULL;
    self->prAudStrmInfo = NULL;

    // Video pool is required for parsing metadata
    self->pt_track_buf_pool_vid =
        (flv_mp_track_buf_pool_vid*)prSrcAPI->SPFN_MALLOC_CLA(self->prSourceHandle,
                                                              sizeof(flv_mp_track_buf_pool_vid), KAL_FALSE);
    pt_track_pool_v = self->pt_track_buf_pool_vid;
    FLV_ASSERT(pt_track_pool_v != NULL);
    self->pt_fsal[FLV_TRACK_VIDEO] = &pt_track_pool_v->t_fsal;
    self->p_fsal_buf[FLV_TRACK_VIDEO] = pt_track_pool_v->fsal_buf;
    self->pt_fsal_mdat[FLV_TRACK_VIDEO] = &pt_track_pool_v->t_fsal_mdat;

    self->ptFLVMetaData = prSrcAPI->SPFN_MALLOC_CLA(self->prSourceHandle, sizeof(FLVMetaData), KAL_FALSE);
    kal_mem_set(self->ptFLVMetaData, 0, sizeof(FLVMetaData));
    self->ptFLVMetaData->rKeyFrames.interval = 1;

    self->pt_comn_buf_pool =
        (flv_mp_common_buf_pool*)prSrcAPI->SPFN_MALLOC_CLA(self->prSourceHandle,
                                                           sizeof(flv_mp_common_buf_pool), KAL_FALSE);
    pt_comn_pool = self->pt_comn_buf_pool;
    FLV_ASSERT(pt_comn_pool != NULL);

    self->pt_fsal_seek_hint = pt_comn_pool->t_fsal_seek_hint;
    self->ptFLVMetaData->pt_fsal_key_table = &(pt_comn_pool->t_fsal_key_table);
    self->ptFLVMetaData->p_fsal_key_table_buf = pt_comn_pool->fsal_key_table_buf;

    // FLV parser memory allocation
    self->ptFLVParser[FLV_TRACK_VIDEO] = prSrcAPI->SPFN_MALLOC_CLA(self->prSourceHandle,
                                                                   sizeof(FLVParser), KAL_TRUE);
    kal_mem_set(self->ptFLVParser[FLV_TRACK_VIDEO], 0, sizeof(FLVParser));

    /* allocate video parameter set memory */
    if ((e_track & SOURCE_PROVIDER_TRACK_VIDEO) && (!(e_track & SOURCE_PROVIDER_TRACK_META)))
    {
        self->prVideoParamSetData = (PU_VID_PARAM_SET_T*)prSrcAPI->SPFN_MALLOC_CLA(self->prSourceHandle,
                                                  sizeof(PU_VID_PARAM_SET_T), KAL_FALSE);
        FLV_ASSERT(self->prVideoParamSetData != NULL);
        kal_mem_set(self->prVideoParamSetData, 0, sizeof(PU_VID_PARAM_SET_T));
    }

    if ((e_track & SOURCE_PROVIDER_TRACK_AUDIO) && (!(e_track & SOURCE_PROVIDER_TRACK_META)))
    {
        self->pt_track_buf_pool_aud =
            (flv_mp_track_buf_pool_aud*)prSrcAPI->SPFN_MALLOC_CLA(self->prSourceHandle,
                                                                      sizeof(flv_mp_track_buf_pool_aud), KAL_FALSE);
        pt_track_pool_a = self->pt_track_buf_pool_aud;
        FLV_ASSERT(pt_track_pool_a != NULL);
        self->pt_fsal[FLV_TRACK_AUDIO] = &pt_track_pool_a->t_fsal;
        self->p_fsal_buf[FLV_TRACK_AUDIO] = pt_track_pool_a->fsal_buf;
        self->pt_fsal_mdat[FLV_TRACK_AUDIO] = &pt_track_pool_a->t_fsal_mdat;

        self->ptFLVParser[FLV_TRACK_AUDIO] = prSrcAPI->SPFN_MALLOC_CLA(self->prSourceHandle,
                                                                       sizeof(FLVParser), KAL_TRUE);
        kal_mem_set(self->ptFLVParser[FLV_TRACK_AUDIO], 0, sizeof(FLVParser));

    }


}

/* To free allocated memory */
static void _FLVProviderSelfDeinit(FLV_PROVIDER_CTRL_T* self)
{
    SP_API_T *prSrcAPI = self->prSourceAPI;

    FSAL_Close(self->pt_fsal[FLV_TRACK_AUDIO]);
    FSAL_Close(self->pt_fsal[FLV_TRACK_VIDEO]);
    FSAL_Close(self->ptFLVMetaData->pt_fsal_key_table);
    // 不用檢查回傳值, 因為可能沒有FSAL_Open.

    if (self->pt_track_buf_pool_aud)
    {
        prSrcAPI->SPFN_FREE_CLA(self->prSourceHandle, self->pt_track_buf_pool_aud);
    }
    self->pt_track_buf_pool_aud = NULL;
    if (self->pt_track_buf_pool_vid)
    {
        prSrcAPI->SPFN_FREE_CLA(self->prSourceHandle, self->pt_track_buf_pool_vid);
    }
    self->pt_track_buf_pool_vid = NULL;

    if (self->prVidStreamInfo)
    {
        prSrcAPI->SPFN_FREE_CLA(self->prSourceHandle, self->prVidStreamInfo);
    }
    self->prVidStreamInfo = NULL;

    if(self->ptFLVParser[FLV_TRACK_AUDIO])
    {
        prSrcAPI->SPFN_FREE_CLA(self->prSourceHandle, self->ptFLVParser[FLV_TRACK_AUDIO]);
    }
    self->ptFLVParser[FLV_TRACK_AUDIO] = NULL;

    if(self->ptFLVParser[FLV_TRACK_VIDEO])
    {
        prSrcAPI->SPFN_FREE_CLA(self->prSourceHandle, self->ptFLVParser[FLV_TRACK_VIDEO]);
    }
    self->ptFLVParser[FLV_TRACK_VIDEO] = NULL;

    prSrcAPI->SPFN_FREE_CLA(self->prSourceHandle, self->ptFLVMetaData);
    self->ptFLVMetaData = NULL;

    if (self->pt_comn_buf_pool)
    {
        prSrcAPI->SPFN_FREE_CLA(self->prSourceHandle, self->pt_comn_buf_pool);
    }
    self->pt_comn_buf_pool = NULL;

    if (self->prVideoParamSetData)
    {
        if (self->prVideoParamSetData->pu1ParamSetBuff)
        {
            prSrcAPI->SPFN_FREE_CLA(self->prSourceHandle, self->prVideoParamSetData->pu1ParamSetBuff);
        }
        self->prVideoParamSetData->pu1ParamSetBuff = NULL;
        if (self->prVideoParamSetData->prNALCTRLBuff)
        {
            prSrcAPI->SPFN_FREE_CLA(self->prSourceHandle, self->prVideoParamSetData->prNALCTRLBuff);
        }
        self->prVideoParamSetData->prNALCTRLBuff = NULL;

        prSrcAPI->SPFN_FREE_CLA(self->prSourceHandle, self->prVideoParamSetData);
        self->prVideoParamSetData = NULL;
    }
}

static media_error_t _FLVProviderPrevKeyFramebyTime(FLV_PROVIDER_CTRL_T* self,
    FLVParser* pstParser,
    kal_uint32 SeekTime,
    kal_uint32 *pKeyIndex, kal_uint32 *pOffset, kal_uint32 *pTime,
    FLV_Track_Type eTrackType)
{
    FLV_PVDR_SEEK_STRUCT *pSeekParam = &(self->t_seek_param[eTrackType]);
    FLV_Parser_Status eParserRet;
    kal_uint32 u4Time, u4Offset, u4Index;
    FSAL_Status eFSALRet;

    if((SeekTime<=pSeekParam->u4SeekTime) && (SeekTime>=pSeekParam->u4KeyTime))
    {
        FLV_ASSERT(pSeekParam->u4Offset != 0);
        *pKeyIndex = pSeekParam->u4SampleIndex;
        *pOffset = pSeekParam->u4Offset;
        *pTime = pSeekParam->u4KeyTime;
        if(pSeekParam->u4SampleIndex == FLV_MP_SAMPLE_NO_MAX)
        {
            return MED_E_NO_MORE_DATA;
        }
    }
    else
    {
        eParserRet = FLV_PrevKeyFramebyTime(pstParser, self->ptFLVMetaData,
            SeekTime, pKeyIndex, pOffset, pTime,
            eTrackType);
        u4Time = *pTime;
        u4Offset = *pOffset;
        u4Index = *pKeyIndex;

        if(FLV_PARSER_OK != eParserRet)
        {
            FLV_MP_TRACE_PARSE_ERROR(eParserRet);
            if(eParserRet == FLV_PARSER_FAST_BREAK)
            {
                return MED_E_ABORTED;
            }
            return MED_E_PARSER_ERROR;
        }
        else
        {
            if(eTrackType == FLV_TRACK_AUDIO)
            {
                eFSALRet = FSAL_Seek(pstParser->pstFSAL, u4Offset);
                if(FSAL_OK != eFSALRet)
                {
                    FLV_MP_TRACE_FSAL_ERROR(eFSALRet);
                    return MED_E_FSAL_ERROR;
                }
                // Find the audio sample nearest to seek time
                while(1)
                {
                    eParserRet = FLV_Tag(pstParser);
                    if(eParserRet != FLV_PARSER_OK)
                    {
                        break;
                    }
                    if (AUDIO_TAG == pstParser->FLVTAG_TagType)
                    {
                        if(pstParser->FLVTAG_Timestamp > SeekTime)
                        {
                            break;
                        }
                        u4Index++;
                        u4Time = pstParser->FLVTAG_Timestamp;
                        FSAL_GetCurPos(pstParser->pstFSAL, &u4Offset);
                        u4Offset -= FLV_TAG_LENGTH;
                    }

                    eFSALRet = FSAL_Skip_Bytes(pstParser->pstFSAL, pstParser->FLVTAG_DataSize+FLV_PREV_TAG_SIZE_LENGTH);
                    if(FSAL_OK != eFSALRet)
                    {
                        FLV_MP_TRACE_FSAL_ERROR(eFSALRet);
                        return MED_E_FSAL_ERROR;
                    }
                }
            }

            *pTime = u4Time;
            *pOffset = u4Offset;
            *pKeyIndex = u4Index;

            // V duration > A duration case. Seek to the point where there is V but no A.
            if((eParserRet != FLV_PARSER_OK) &&(u4Time+FLV_MP_DURATION_MARGIN < SeekTime))
            {
                *pTime = SeekTime;
                *pKeyIndex = FLV_MP_SAMPLE_NO_MAX;
                *pOffset = FLV_MP_SAMPLE_NO_MAX;

                pSeekParam->u4SeekTime = SeekTime;
                pSeekParam->u4KeyTime = *pTime;
                pSeekParam->u4SampleIndex = *pKeyIndex;
                pSeekParam->u4Offset = *pOffset;
                return MED_E_NO_MORE_DATA;
            }

            pSeekParam->u4SeekTime = SeekTime;
            pSeekParam->u4KeyTime = *pTime;
            pSeekParam->u4SampleIndex = *pKeyIndex;
            pSeekParam->u4Offset = *pOffset;

        }
    }
    return MED_S_OK;
}

static void FLVProviderMediaDataAlloc(FLV_PROVIDER_CTRL_T* prFLVProviderCtrl,
                                     kal_uint8** pp_sample, SP_PORT_TYPE_T ePort)
{
    kal_uint32 start;
    kal_uint32 offset;
    kal_uint32 rd_idx;
    FLV_PVDR_BATCH_READ_STRUCT *ptBatch;
    FLV_Track_Type eType;

    eType = FLV_TRACK_AUDIO;
    if(ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        eType = FLV_TRACK_VIDEO;
    }
    ptBatch = &(prFLVProviderCtrl->t_batch[eType]);

    rd_idx = ptBatch->read_idx;
    start = (kal_uint32)ptBatch->p_mem_start;
    offset = ptBatch->offset[rd_idx] - ptBatch->offset[0];
    if(ptBatch->skipsize[rd_idx] > 0)
    {
        offset -= ptBatch->skipsize[rd_idx];
    }
    *pp_sample = (kal_uint8*)(start + offset);

    ptBatch->read_idx++;
}

static void FLVProviderMediaDataDealloc(FLV_PROVIDER_CTRL_T* prFLVProviderCtrl, SP_PORT_TYPE_T ePort)
{
    FLV_Track_Type eType;

    eType = FLV_TRACK_AUDIO;
    if(ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        eType = FLV_TRACK_VIDEO;
    }

    prFLVProviderCtrl->t_batch[eType].read_idx--;

    // FLV provider will re-allocate memory for payload if resend is needed
    if(prFLVProviderCtrl->rFrameInfo[eType].pu1Payload != NULL)
    {
        FLV_ASSERT(MEDIA_CODEC_VID_H264 == prFLVProviderCtrl->prVidStreamInfo->eCodecType &&
                   SOURCE_PROVIDER_PORT_VIDEO == ePort);
        prFLVProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prFLVProviderCtrl->prSourceHandle,
                                                      prFLVProviderCtrl->rFrameInfo[eType].pu1Payload);
    }
}

static void FLVProviderBatchMemoReset(FLV_PROVIDER_CTRL_T* prFLVProviderCtrl, SP_PORT_TYPE_T ePort)
{
    FLV_Track_Type eType;
    FLV_PVDR_BATCH_READ_STRUCT *ptBatch;

    eType = FLV_TRACK_AUDIO;
    if(ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        eType = FLV_TRACK_VIDEO;
    }
    ptBatch = &(prFLVProviderCtrl->t_batch[eType]);

    ptBatch->LastMemStart = NULL;
    ptBatch->LastReadAmount = 0;
    ptBatch->LastReadOffset = 0;
}

static void FLVProviderBatchReset(FLV_PROVIDER_CTRL_T* prFLVProviderCtrl, SP_PORT_TYPE_T ePort)
{
    kal_uint32 i;
    FLV_Track_Type eType;
    FLV_PVDR_BATCH_READ_STRUCT *ptBatch;

    eType = FLV_TRACK_AUDIO;
    if(ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        eType = FLV_TRACK_VIDEO;
    }
    ptBatch = &(prFLVProviderCtrl->t_batch[eType]);

    ptBatch->p_mem_start = NULL;
    for (i = 0; i < FLV_MP_BATCH_READ_MAX; i++)
    {
        ptBatch->offset[i] = 0;
        ptBatch->size[i] = 0;
        ptBatch->flags[i] = 0;
        ptBatch->DecTime[i] = 0;
        ptBatch->DispTime[i] = 0;
        ptBatch->skipsize[i] = 0;
    }
    ptBatch->frame_idx_start= prFLVProviderCtrl->curr_sample_no[eType];
    ptBatch->curr_frame_idx = prFLVProviderCtrl->curr_sample_no[eType];
    ptBatch->read_idx = 0;
    ptBatch->write_idx = 0;

}

static media_error_t FLVProviderSeekKeyFrame(FLV_PROVIDER_CTRL_T* self, kal_uint32 SeekTime, FLV_Track_Type type)
{
    FSAL_Status eFSALRet;
    kal_uint32 KeyIndex, Offset, Time;
    STFSAL* pt_fsal;
    FLVParser *ptParser;
    kal_uint32 u4HdrLength = 0;
    FLV_Parser_Status eParserRet = FLV_PARSER_OK;
    FLV_PVDR_BATCH_READ_STRUCT *ptBatch = &(self->t_batch[type]);
    media_error_t eRet;

    FLV_ASSERT((type == FLV_TRACK_AUDIO) || (type == FLV_TRACK_VIDEO));
    pt_fsal = self->pt_fsal[type];
    ptParser = self->ptFLVParser[type];
    ptParser->pstFSAL = pt_fsal;

    eRet = _FLVProviderPrevKeyFramebyTime(self, ptParser,
        SeekTime, &KeyIndex, &Offset, &Time,
        type);

    if(MED_E_NO_MORE_DATA == eRet)
    {
        ptBatch->curr_frame_offset = 0;
        ptBatch->curr_frame_size = 0;
        ptBatch->curr_frame_flags = 0;
        ptBatch->curr_frame_dec_time = 0;
        ptBatch->curr_frame_disp_time = 0;
        self->curr_sample_no[type] = FLV_MP_SAMPLE_NO_MAX;
        return MED_S_OK;
    }
    else if(MED_S_OK != eRet)
    {
        FLV_MP_TRACE_ERROR(eRet);
        return eRet;
    }

    eFSALRet = FSAL_Seek(pt_fsal, Offset);
    if(FSAL_OK != eFSALRet)
    {
        FLV_MP_TRACE_FSAL_ERROR(eFSALRet);
        return MED_E_FSAL_ERROR;
    }

    eParserRet = FLV_Tag(ptParser);
    if(FLV_PARSER_OK != eParserRet)
    {
        FLV_MP_TRACE_PARSE_ERROR(eParserRet);
        return MED_E_PARSER_ERROR;
    }
    if(type == FLV_TRACK_VIDEO)
    {
        FLV_ASSERT(ptParser->FLVTAG_TagType == VIDEO_TAG);
        eParserRet = FLV_VideoTag(ptParser, self->ptFLVMetaData);
        if(eParserRet != FLV_PARSER_VIDEO_DATA_OK)
        {
            if(eParserRet == FLV_PARSER_VIDEO_PKT_EOS)
            {
                // AVC end of sequence is received
                ptBatch->curr_frame_offset = 0;
                ptBatch->curr_frame_size = 0;
                ptBatch->curr_frame_flags = 0;
                ptBatch->curr_frame_dec_time = 0;
                ptBatch->curr_frame_disp_time = 0;
                self->curr_sample_no[type] = FLV_MP_SAMPLE_NO_MAX;
                return MED_S_OK;
            }
            else
            {
                FLV_MP_TRACE_PARSE_ERROR(eParserRet);
                return MED_E_PARSER_ERROR;
            }
        }
        u4HdrLength = FLV_VIDEO_TAG_HDR_LENGTH;
    }
    else // Audio
    {
        FLV_ASSERT(ptParser->FLVTAG_TagType == AUDIO_TAG);
        eParserRet = FLV_AudioTag(ptParser, self->ptFLVMetaData);
        if(eParserRet != FLV_PARSER_AUDIO_DATA_OK)
        {
            FLV_MP_TRACE_PARSE_ERROR(eParserRet);
            return MED_E_PARSER_ERROR;
        }

        if(self->ptFLVMetaData->AudioCodecId == FLV_AAC)
        {
            u4HdrLength = FLV_AUDIO_TAG_HDR_LENGTH_AAC;
        }
        else
        {
            u4HdrLength = FLV_AUDIO_TAG_HDR_LENGTH;
        }
    }

    self->curr_sample_no[type] = KeyIndex;
    ptBatch->curr_frame_offset = Offset+FLV_TAG_LENGTH+u4HdrLength;
    ptBatch->curr_frame_size = ptParser->FLVTAG_DataSize-u4HdrLength;
    ptBatch->curr_frame_dec_time = ptParser->FLVTAG_Timestamp;
    if(((kal_int32)(ptParser->CompositionTimeOffset + ptParser->FLVTAG_Timestamp)) < 0)
    {
        ptBatch->curr_frame_disp_time = ptBatch->curr_frame_dec_time;
    }
    else
    {
        ptBatch->curr_frame_disp_time =
            ptParser->FLVTAG_Timestamp + ptParser->CompositionTimeOffset;
    }

    ptBatch->curr_frame_flags = 0;
    if((type == FLV_TRACK_VIDEO) && (ptParser->VideoFrameType == FLV_KEY_FRAME))
    {
        ptBatch->curr_frame_flags |= FLV_FLAG_KEY_FRAME;
    }

    // 把最近一次的audio frame file offset and time記下來. for auido seek (pause/resume)
    if(type == FLV_TRACK_AUDIO)
    {
        self->ptFLVMetaData->LatestAudioTagOffset = Offset;
        self->ptFLVMetaData->LatestAudioTagTime = ptParser->FLVTAG_Timestamp;
    }

    return MED_S_OK;
}

static media_error_t FLVProviderSeekNextFrame(FLV_PROVIDER_CTRL_T* self, FLV_Track_Type type,
    kal_uint8* start, kal_uint32 length, kal_uint32 *ReadOffset)
{
    FLVParser *ptParser;
    FLV_Parser_Status eParserRet = FLV_PARSER_OK;
    kal_uint32 u4HdrLength = 0;
    kal_uint32 CurrFrameFlags = 0;
    kal_uint32 offset = 0;
    kal_uint32 cur_offset;
    FLV_PVDR_BATCH_READ_STRUCT *ptBatch = &(self->t_batch[type]);
    kal_uint8 u1MatchType;

    cur_offset = ptBatch->curr_frame_offset +
        ptBatch->curr_frame_size + FLV_PREV_TAG_SIZE_LENGTH +
        *ReadOffset;

    ptParser = self->ptFLVParser[type];

    if(type == FLV_TRACK_VIDEO)
    {
        u4HdrLength = FLV_VIDEO_TAG_HDR_LENGTH;
        u1MatchType = VIDEO_TAG;
    }
    else
    {
        if(self->ptFLVMetaData->AudioCodecId == FLV_AAC)
        {
            u4HdrLength = FLV_AUDIO_TAG_HDR_LENGTH_AAC;
        }
        else
        {
            u4HdrLength = FLV_AUDIO_TAG_HDR_LENGTH;
        }
        u1MatchType = AUDIO_TAG;
    }

    if (ptBatch->curr_frame_idx !=  FLV_MP_SAMPLE_NO_MAX)
    {
        while (1)
        {
            CurrFrameFlags = 0;

            if(length < offset)
            {
                eParserRet = FLV_PARSER_BUFFER_READ_OVER;
                *ReadOffset = offset;
                break;
            }
            eParserRet = FLV_Tag_Buf(ptParser, start+offset, length-offset);
            offset += FLV_TAG_LENGTH;

            if (eParserRet != FLV_PARSER_OK)
            {
                FLV_MP_TRACE_PARSE_ERROR(eParserRet);
                if(eParserRet == FLV_PARSER_BUFFER_READ_OVER)
                {
                    *ReadOffset = offset - FLV_TAG_LENGTH;
                    break; /* 讀到Buffer尾巴了 */
                }
                else
                {
                    //FLV_ASSERT(0);
                    return MED_E_PARSER_ERROR;
                }
            }

            if (AUDIO_TAG == ptParser->FLVTAG_TagType)
            {
    #ifdef __VE_FLV_PSEUDO_KEY_TABLE__
                if((self->ptFLVMetaData->FLVHeader_TypeFlagsVideo == 0) &&
                   (self->ptFLVMetaData->rKeyFrames.Real_Count == 0))
                {
                    FLV_ASSERT(self->ptFLVMetaData->FLVHeader_TypeFlagsAudio != 0);
                    FLV_BuildPseuKeyTable(self->ptFLVMetaData,
                        ptParser->FLVTAG_Timestamp, cur_offset);
                    FLV_UpdatePseuKeyTableMaxRead(self->ptFLVMetaData, ptParser->FLVTAG_Timestamp, cur_offset);
                }
    #endif
            }

            else if (VIDEO_TAG == ptParser->FLVTAG_TagType)
            {
                if(length < offset+FLV_VIDEO_TAG_HDR_LENGTH)
                {
                    eParserRet = FLV_PARSER_BUFFER_READ_OVER;
                    *ReadOffset = offset - FLV_TAG_LENGTH;
                    break;
                }
                eParserRet = FLV_VideoTag_Buf(ptParser, self->ptFLVMetaData, start+offset, length-offset);
                if(ptParser->VideoFrameType == FLV_KEY_FRAME)
                {
                    CurrFrameFlags |= FLV_FLAG_KEY_FRAME;
                    #ifdef __VE_FLV_PSEUDO_KEY_TABLE__
                    if ((eParserRet == FLV_PARSER_OK) &&
                        (self->ptFLVMetaData->FLVHeader_TypeFlagsVideo != 0) &&
                       (self->ptFLVMetaData->rKeyFrames.Real_Count == 0))
                    {
                        FLV_BuildPseuKeyTable(self->ptFLVMetaData,
                            ptParser->FLVTAG_Timestamp, cur_offset+offset-FLV_TAG_LENGTH);
                    }
                    #endif
                }
                #ifdef __VE_FLV_PSEUDO_KEY_TABLE__
                if((self->ptFLVMetaData->FLVHeader_TypeFlagsVideo != 0) &&
                   (self->ptFLVMetaData->rKeyFrames.Real_Count == 0))
                {
                    FLV_UpdatePseuKeyTableMaxRead(self->ptFLVMetaData, ptParser->FLVTAG_Timestamp, cur_offset+offset-FLV_TAG_LENGTH);
                }
                #endif

            }

            if (u1MatchType == ptParser->FLVTAG_TagType)
            {
                if(length < offset+u4HdrLength)
                {
                    eParserRet = FLV_PARSER_BUFFER_READ_OVER;
                    *ReadOffset = offset - FLV_TAG_LENGTH;
                    break;
                }
                if(type == FLV_TRACK_VIDEO)
                {
                    if(eParserRet == FLV_PARSER_VIDEO_FRAME_TYPE_NOT_SUPPORT)
                    {
                        offset += ptParser->FLVTAG_DataSize+FLV_PREV_TAG_SIZE_LENGTH;
                        continue;
                    }

                }
                offset += u4HdrLength;
                break;
            }
            else
            {
                offset += ptParser->FLVTAG_DataSize+FLV_PREV_TAG_SIZE_LENGTH;

                #if 1 // 0335.flv duration is 3:53, but audio only 0:23.940
                if((ptParser->FLVTAG_Timestamp > ptBatch->curr_frame_disp_time) &&
                   (ptParser->FLVTAG_Timestamp - ptBatch->curr_frame_disp_time > 2000))
                {
                    kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_BAD_INTERLEAVE,
                        ptParser->FLVTAG_Timestamp, ptBatch->curr_frame_disp_time);
                    // 過2秒都還找不到下一筆對應的audio/video
                    eParserRet = FLV_PARSER_FILE_READ_EOF;
                    break;
                }
                #endif
            }
        }

        /* 2種情況會跳出while loop. 讀到Buffer 尾巴 or 找到對應的data */
        if(eParserRet == FLV_PARSER_BUFFER_READ_OVER)
        {
            return MED_S_FALSE;
        }
        else if(eParserRet == FLV_PARSER_VIDEO_PKT_EOS)
        {
            return MED_S_PLAY_FINISH;
        }
        else if(eParserRet == FLV_PARSER_FILE_READ_EOF)
        {
            return MED_S_PLAY_FINISH;
        }
        else
        {
            FLV_ASSERT(eParserRet == FLV_PARSER_OK);
            ptBatch->curr_frame_offset = cur_offset+offset;
            ptBatch->curr_frame_size = ptParser->FLVTAG_DataSize-u4HdrLength;
            ptBatch->curr_frame_flags = CurrFrameFlags;
            ptBatch->curr_frame_dec_time = ptParser->FLVTAG_Timestamp;

            if(((kal_int32)(ptParser->CompositionTimeOffset + ptParser->FLVTAG_Timestamp)) < 0)
            {
                ptBatch->curr_frame_disp_time = ptBatch->curr_frame_dec_time;
            }
            else
            {
                ptBatch->curr_frame_disp_time =
                    ptParser->FLVTAG_Timestamp + ptParser->CompositionTimeOffset;
            }

            ptBatch->curr_frame_idx++;

        }

    }

    return MED_S_OK;

}

#ifdef FLV_PARTIAL_DATA_READ
/* Seek next frame without buffer */
static media_error_t FLVProviderSeekNextFrameWoBuf(FLV_PROVIDER_CTRL_T* self, FLV_Track_Type type)
{
    FSAL_Status eFSALRet;
    kal_uint32 cur_offset;
    FLV_Parser_Status eParserRet = FLV_PARSER_OK;
    unsigned char MatchType;
    FLVParser *ptParser;
    kal_uint32 CurrFrameFlags = 0;
    STFSAL* pt_fsal;
    FLV_Parser_Status (*pfnTagParser)(FLVParser *, FLVMetaData *)= NULL;
    kal_uint32 u4HdrLength = 0;
    FLV_PVDR_BATCH_READ_STRUCT *ptBatch = &(self->t_batch[type]);

    pt_fsal = self->pt_fsal[type];
    ptParser = self->ptFLVParser[type];
    ptParser->pstFSAL = pt_fsal; // Video FSAL handle

    eFSALRet = FSAL_Seek(pt_fsal, ptBatch->curr_frame_offset+ptBatch->curr_frame_size+FLV_PREV_TAG_SIZE_LENGTH);
    if(FSAL_OK != eFSALRet)
    {
        FLV_MP_TRACE_FSAL_ERROR(eFSALRet);
        return MED_E_FSAL_ERROR;
    }

    if(type == FLV_TRACK_AUDIO)
    {
        MatchType = AUDIO_TAG;
        pfnTagParser = FLV_AudioTag;
        u4HdrLength = FLV_AUDIO_TAG_HDR_LENGTH;
    }
    else // if(type == FLV_TRACK_VIDEO)
    {
        MatchType = VIDEO_TAG;
        pfnTagParser = FLV_VideoTag;
        u4HdrLength = FLV_VIDEO_TAG_HDR_LENGTH;
    }

    if (ptBatch->curr_frame_idx !=  FLV_MP_SAMPLE_NO_MAX)
    {
        while (1)
        {
            CurrFrameFlags = 0;
            eFSALRet = FSAL_GetCurPos(pt_fsal, &cur_offset);
            if(FSAL_OK != eFSALRet)
            {
                FLV_MP_TRACE_FSAL_ERROR(eFSALRet);
                return MED_E_FSAL_ERROR;
            }

            eParserRet = FLV_Tag(ptParser);
            if (eParserRet != FLV_PARSER_OK)
            {
                FLV_MP_TRACE_PARSE_ERROR(eParserRet);
                if(eParserRet == FLV_PARSER_FILE_READ_EOF)
                {
                    break; //讀到最後一筆了
                }
                else
                {
                    return MED_E_PARSER_ERROR;
                }
            }

            if (MatchType == ptParser->FLVTAG_TagType)
            {
                eParserRet = pfnTagParser(ptParser, self->ptFLVMetaData);
                if(type == FLV_TRACK_VIDEO)
                {
                    if(ptParser->VideoFrameType == FLV_KEY_FRAME)
                    {
                        CurrFrameFlags |= FLV_FLAG_KEY_FRAME;
                    }
                }
                break;
            }
            else
            {
                eFSALRet = FSAL_Skip_Bytes(pt_fsal, ptParser->FLVTAG_DataSize+4);
                if(FSAL_OK != eFSALRet)
                {
                    FLV_MP_TRACE_FSAL_ERROR(eFSALRet);
                    return MED_E_FSAL_ERROR;
                }
                #if 1 // 0335.flv duration is 3:53, but audio only 0:23.940
                if((ptParser->FLVTAG_Timestamp > ptBatch->curr_frame_disp_time) &&
                   (ptParser->FLVTAG_Timestamp - ptBatch->curr_frame_disp_time > 2000))
                {
                    kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_BAD_INTERLEAVE,
                        ptParser->FLVTAG_Timestamp, ptBatch->curr_frame_disp_time);
                    // 過2秒都還找不到下一筆對應的audio/video
                    eParserRet = FLV_PARSER_FILE_READ_EOF;
                    break;
                }
                #endif
            }

        }

        /* 2種情況會跳出while loop. 讀到檔尾 or 找到對應的data */
        if ((eParserRet == FLV_PARSER_FILE_READ_EOF) ||
            (eParserRet == FLV_PARSER_VIDEO_PKT_EOS))
        {
            ptBatch->curr_frame_offset = 0;
            ptBatch->curr_frame_size = 0;
            ptBatch->curr_frame_flags = 0;
            ptBatch->curr_frame_dec_time = 0;
            ptBatch->curr_frame_disp_time = 0;
            ptBatch->curr_frame_idx = FLV_MP_SAMPLE_NO_MAX;
            return MED_S_PLAY_FINISH;
        }
        else
        {
            ASSERT((eParserRet == FLV_PARSER_AUDIO_DATA_OK) ||
                   (eParserRet == FLV_PARSER_VIDEO_DATA_OK));
            ptBatch->curr_frame_offset = cur_offset+FLV_TAG_LENGTH+u4HdrLength;
            ptBatch->curr_frame_size = ptParser->FLVTAG_DataSize-u4HdrLength;
            ptBatch->curr_frame_flags = CurrFrameFlags;
            ptBatch->curr_frame_dec_time = ptParser->FLVTAG_Timestamp;
            ptBatch->curr_frame_disp_time =
                ptParser->FLVTAG_Timestamp + ptParser->CompositionTimeOffset;
            ptBatch->curr_frame_idx++;
        }

    }

    return MED_S_OK;
}
#endif

#define FLV_READBTM_ALIGH 512
#define FLV_ALIGNMENT_READ_OVERHEAD 3072
#define FLV_BTMBUFFER_ALIGH 4

static media_error_t FLVProviderBatchRead(FLV_PROVIDER_CTRL_T* prFLVProviderCtrl, SP_PORT_TYPE_T ePort)
{
    FLV_Track_Type eType = FLV_TRACK_AUDIO;
    kal_uint32 batch_size = 0;
    media_error_t ret = MED_S_OK;
    kal_uint32 u_frame_size = 0;
    kal_uint32 wr_idx;
    kal_uint8* p_batch;
    STFSAL* pt_fsal;
    FSAL_Status eFSALStatus;
    kal_bool bFileEnd = KAL_FALSE;
    kal_uint32 uInitOffset;
    kal_bool SecondFound = KAL_FALSE;
    kal_uint32 uReadOffset = 0;
    kal_uint8 *BufStart;
    kal_uint32 BufLength;
    kal_uint32 uAlreadyRead;
    kal_uint32 uElapsedTime;
    kal_uint32 u4ActualBufSize = 0;
    kal_uint32 u4TotalSize;
    kal_uint32 reason = 0;
    kal_uint32 u4AlignOffset = 0;
    kal_uint32 u4HdrLength = 0;
    kal_uint32 u4InterAlignOffset = 0, u4InterAlignDiff = 0;
#ifdef FLV_PARTIAL_DATA_READ
    kal_uint32 u4RequiredSize = 0;
    kal_uint32 u4PartialData = 0;
#endif

    FLV_PVDR_BATCH_READ_STRUCT *ptBatch;

    if(ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        eType = FLV_TRACK_VIDEO;
        u4HdrLength = FLV_VIDEO_TAG_HDR_LENGTH;
    }
    else if(ePort == SOURCE_PROVIDER_PORT_AUDIO)
    {
        eType = FLV_TRACK_AUDIO;
        u4HdrLength = FLV_AUDIO_TAG_HDR_LENGTH;
        if(prFLVProviderCtrl->ptFLVMetaData->AudioCodecId == FLV_AAC)
        {
            u4HdrLength = FLV_AUDIO_TAG_HDR_LENGTH_AAC;
        }
    }
    else
    {
        FLV_ASSERT(0);
    }
    ptBatch = &(prFLVProviderCtrl->t_batch[eType]);

    if (!prFLVProviderCtrl->fgSelectedTrack[eType] ||
        ptBatch->curr_frame_idx == FLV_MP_SAMPLE_NO_MAX ||
        ptBatch->read_idx != ptBatch->write_idx)
    {
        return MED_S_OK;
    }

    kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_BATCH_READ_START, ePort, ptBatch->curr_frame_idx);

    FLV_START_LOGGING("FVR");
    pt_fsal = prFLVProviderCtrl->pt_fsal_mdat[eType];
    u4TotalSize = prFLVProviderCtrl->prSourceAPI->SPFN_BITSTREAM_BUF_SIZE(prFLVProviderCtrl->prSourceHandle, ePort);

    FLVProviderBatchReset(prFLVProviderCtrl, ePort);

    // Size of the 1st frame to read
    u_frame_size = ptBatch->curr_frame_size;

#ifdef FLV_PARTIAL_DATA_READ
    u4RequiredSize = u_frame_size+FLV_PREV_TAG_SIZE_LENGTH+FLV_TAG_LENGTH
                     +u4HdrLength+FLV_ALIGNMENT_READ_OVERHEAD;
    if(u4RequiredSize > u4TotalSize)
    {
        u4PartialData |= FLV_FLAG_PARTIAL_DATA;
        kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_FRAME_SIZE_LARGE, eType,
        ptBatch->curr_frame_size, ptBatch->curr_frame_offset);

        ptBatch->curr_frame_flags |= FLV_FLAG_PARTIAL_DATA;
        if(eType == FLV_TRACK_VIDEO)
        {
            u_frame_size = FLV_READBTM_ALIGH;
        }
        else
        {
            u_frame_size = 0;
        }
    }
#endif

    do
    {
        uInitOffset = ptBatch->curr_frame_offset;

        if(u_frame_size == 0)
        {
            #ifdef FLV_PARTIAL_DATA_READ
            if(ptBatch->curr_frame_flags & FLV_FLAG_PARTIAL_DATA)
            {
                break;
            }
            #endif
            // Size of zero, error
            reason = 4;
            ret = MED_E_PARSER_ERROR;
            break;
        }
        if (u_frame_size >= prFLVProviderCtrl->file_size || u_frame_size >= u4TotalSize)
        {
            reason = 5;
            ret = MED_E_CORRUPTED_DATA;
            break;
        }

        if((ptBatch->LastReadOffset <= uInitOffset) &&
           (ptBatch->LastReadAmount >= ((uInitOffset - ptBatch->LastReadOffset) +
                                          u_frame_size+FLV_PREV_TAG_SIZE_LENGTH+FLV_TAG_LENGTH+u4HdrLength+
                                          FLV_ALIGNMENT_READ_OVERHEAD)))
        {
           // The bitstream is read last time
           p_batch = ptBatch->LastMemStart;
           ptBatch->p_mem_start = ptBatch->LastMemStart + (uInitOffset - ptBatch->LastReadOffset);
           batch_size = ptBatch->LastReadAmount;
           u4AlignOffset = ptBatch->LastReadOffset;

           if(ptBatch->LastReadOffset+ptBatch->LastReadAmount == prFLVProviderCtrl->file_size)
           {
               bFileEnd = KAL_TRUE;
           }
        }
        else
        {
            p_batch = (kal_uint8 *)prFLVProviderCtrl->prSourceAPI->SPFN_BITSTREAM_BUF_QUERY_AVAILABLE_SIZE(
                                                        prFLVProviderCtrl->prSourceHandle,
                                                        ePort,
                                                        (u_frame_size+FLV_PREV_TAG_SIZE_LENGTH+FLV_TAG_LENGTH+u4HdrLength
                                                        +FLV_ALIGNMENT_READ_OVERHEAD),
                                                        &u4ActualBufSize);
            /* check if there is enough free memory */
            if (p_batch == NULL)
            {
                reason = 6;
                ret = MED_E_OUT_OF_MEMORY;
                break;
            }

            FLV_ASSERT(u4ActualBufSize >= FLV_ALIGNMENT_READ_OVERHEAD);
            batch_size = u4ActualBufSize/FLV_READBTM_ALIGH*FLV_READBTM_ALIGH;

            uElapsedTime = video_get_current_time();
            u4AlignOffset = ptBatch->curr_frame_offset/FLV_READBTM_ALIGH*FLV_READBTM_ALIGH;
            eFSALStatus = FSAL_Seek(prFLVProviderCtrl->pt_fsal_mdat[eType], u4AlignOffset);

            if (eFSALStatus != FSAL_OK)
            {
                reason = 3;
                ret = MED_E_FSAL_ERROR;
                break;
            }

            if(prFLVProviderCtrl->file_size-u4AlignOffset < batch_size)
            {
                // The left part in the file is smaller than batch size
                batch_size = prFLVProviderCtrl->file_size-u4AlignOffset;
                bFileEnd = KAL_TRUE;
            }

            eFSALStatus = FSAL_Read(prFLVProviderCtrl->pt_fsal_mdat[eType], p_batch, batch_size);
            if (eFSALStatus != FSAL_OK)
            {
                reason = 7;
                ret = MED_E_FSAL_ERROR;
                break;
            }
            ptBatch->count++;
            ptBatch->accum_size += batch_size;
            uElapsedTime = video_get_duration_ms(uElapsedTime);
            ptBatch->accum_time += uElapsedTime;

            #if 1 /* Memo the read bitstraem */
            ptBatch->LastReadOffset = u4AlignOffset;
            ptBatch->LastReadAmount = batch_size;
            ptBatch->LastMemStart = p_batch;
            #endif

            ptBatch->p_mem_start = p_batch;
            if(ptBatch->curr_frame_offset - u4AlignOffset != 0)
            {
                ptBatch->p_mem_start = p_batch + (ptBatch->curr_frame_offset - u4AlignOffset);
            }

            if(ePort == SOURCE_PROVIDER_PORT_VIDEO)
            {
                kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_BATCH_READ_VIDEO,
                      ptBatch->curr_frame_idx, batch_size, uElapsedTime,
                      p_batch);
            }
            else
            {
                kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_BATCH_READ_AUDIO,
                      ptBatch->curr_frame_idx, batch_size, uElapsedTime,
                      p_batch);
            }
        }

        if ((ptBatch->curr_frame_offset + u_frame_size) > prFLVProviderCtrl->file_size)
        {
            reason = 8;
            ret = MED_E_CORRUPTED_DATA;
            break;
        }
    } while(0);

    if(ret != MED_S_OK)
    {
        FLV_STOP_LOGGING("FVR");
        FLV_MP_TRACE_RET_ERR(ret);
        FLV_PVDR_TRACE_3_VAL(reason, u_frame_size, u4TotalSize);
        return ret;
    }

    wr_idx = ptBatch->write_idx;
    ptBatch->size[wr_idx] = u_frame_size;
    ptBatch->offset[wr_idx] = ptBatch->curr_frame_offset;
    ptBatch->flags[wr_idx] = ptBatch->curr_frame_flags;
    ptBatch->DecTime[wr_idx] = ptBatch->curr_frame_dec_time;
    ptBatch->DispTime[wr_idx] = ptBatch->curr_frame_disp_time;

    #ifdef FLV_PARTIAL_DATA_READ
    if(ptBatch->curr_frame_flags & FLV_FLAG_PARTIAL_DATA)
    {
        FLV_STOP_LOGGING("FVR");

        ret = FLVProviderSeekNextFrameWoBuf(prFLVProviderCtrl, eType);
        ptBatch->write_idx++;
        FLV_PVDR_TRACE_3_VAL(ret, ptBatch->curr_frame_size, ptBatch->curr_frame_offset);
        return ret;
    }
    #endif

    FLV_ASSERT(batch_size >= (u_frame_size+FLV_PREV_TAG_SIZE_LENGTH));

    uReadOffset = 0;
    BufStart = ptBatch->p_mem_start+(u_frame_size+FLV_PREV_TAG_SIZE_LENGTH);
    BufLength = batch_size-(u_frame_size+FLV_PREV_TAG_SIZE_LENGTH)-(ptBatch->curr_frame_offset - u4AlignOffset);

    uAlreadyRead = 0; /* 為了找第2張的頭所skip掉的量 */

    while(SecondFound == KAL_FALSE)
    {
        uReadOffset = uAlreadyRead;

         /* update curr_frame_idx/curr_frame_offset/curr_frame_size/curr_frame_flags */
        ret = FLVProviderSeekNextFrame(prFLVProviderCtrl, eType, BufStart+u4InterAlignDiff,
            BufLength-u4InterAlignDiff, &uReadOffset);

        if (ret != MED_S_OK)
        {
            if(ret == MED_E_PARSER_ERROR)
            {
                FLV_MP_TRACE_PARSE_ERROR(ret);
                FLV_STOP_LOGGING("FVR");
                return MED_E_CORRUPTED_DATA;
            }
            else if ((bFileEnd == KAL_TRUE) ||
                (ret == MED_S_PLAY_FINISH))
            {
                // 已經找到檔尾了 || AVC end of sequence is received
                ptBatch->curr_frame_offset = 0;
                ptBatch->curr_frame_size = 0;
                ptBatch->curr_frame_flags = 0;
                ptBatch->curr_frame_dec_time = 0;
                ptBatch->curr_frame_disp_time = 0;
                ptBatch->curr_frame_idx = FLV_MP_SAMPLE_NO_MAX;
                SecondFound = KAL_TRUE;
            }
            else
            {
                kal_uint32 uInterElapsedTime;
                kal_uint32 u4BufAlignOffset = 0;

                uInterElapsedTime = video_get_current_time();
                FLV_ASSERT(uReadOffset > 0);
                uAlreadyRead += uReadOffset;

                // Make buffer start to be 4-byte alignment
                u4BufAlignOffset = FLV_BTMBUFFER_ALIGH - ((kal_uint32)BufStart%FLV_BTMBUFFER_ALIGH);
                //BufStart = (kal_uint8 *)(((kal_uint32)BufStart+FLV_BTMBUFFER_ALIGH-1)/FLV_BTMBUFFER_ALIGH*FLV_BTMBUFFER_ALIGH);
                BufStart += u4BufAlignOffset;
                BufLength = (BufLength-u4BufAlignOffset)/FLV_READBTM_ALIGH*FLV_READBTM_ALIGH;

                // batch_size讀得進第1張, 但找不到第2張的頭的情況

                u4InterAlignOffset = (uAlreadyRead+ptBatch->curr_frame_offset+ptBatch->curr_frame_size+FLV_PREV_TAG_SIZE_LENGTH)/
                    FLV_READBTM_ALIGH * FLV_READBTM_ALIGH;
                u4InterAlignDiff = (uAlreadyRead+ptBatch->curr_frame_offset+ptBatch->curr_frame_size+FLV_PREV_TAG_SIZE_LENGTH)-u4InterAlignOffset;

                if(prFLVProviderCtrl->file_size-u4InterAlignOffset < BufLength)
                {
                    // File剩下還沒讀的小於batch size
                    BufLength = prFLVProviderCtrl->file_size-u4InterAlignOffset;
                    bFileEnd = KAL_TRUE;
                }

                eFSALStatus = FSAL_Seek(pt_fsal, u4InterAlignOffset);
                if (eFSALStatus != FSAL_OK)
                {
                    FLV_MP_TRACE_FSAL_ERROR(eFSALStatus);
                    FLV_STOP_LOGGING("FVR");
                    return MED_E_FSAL_ERROR;
                }
                eFSALStatus = FSAL_Read(pt_fsal, BufStart, BufLength);
                if (eFSALStatus != FSAL_OK)
                {
                    FLV_MP_TRACE_FSAL_ERROR(eFSALStatus);
                    FLV_STOP_LOGGING("FVR");
                    return MED_E_FSAL_ERROR;
                }
                ptBatch->count++;
                ptBatch->accum_size += BufLength;
                uInterElapsedTime = video_get_duration_ms(uInterElapsedTime);
                ptBatch->accum_time += uInterElapsedTime;

            #if 1 /* Memo the read bitstraem */
                ptBatch->LastReadOffset = u4InterAlignOffset;
                ptBatch->LastReadAmount = BufLength;
                ptBatch->LastMemStart = BufStart;
            #endif
                if(ePort == SOURCE_PROVIDER_PORT_VIDEO)
                {
                    kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_BATCH_READ_VIDEO,
                          ptBatch->curr_frame_idx, BufLength, uInterElapsedTime,
                          BufStart);
                }
                else
                {
                    kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_BATCH_READ_AUDIO,
                          ptBatch->curr_frame_idx, BufLength, uInterElapsedTime,
                          BufStart);
                }
            }
        }
        else
        {
            SecondFound = KAL_TRUE;
        }
    }

    batch_size = BufLength + (u_frame_size+FLV_PREV_TAG_SIZE_LENGTH)+(uInitOffset - u4AlignOffset);
    if(BufStart != ptBatch->p_mem_start+(u_frame_size+FLV_PREV_TAG_SIZE_LENGTH))
    {
        FLV_ASSERT(BufStart>ptBatch->p_mem_start+(u_frame_size+FLV_PREV_TAG_SIZE_LENGTH));
        uAlreadyRead -= BufStart-(ptBatch->p_mem_start+(u_frame_size+FLV_PREV_TAG_SIZE_LENGTH));
        batch_size += BufStart-(ptBatch->p_mem_start+(u_frame_size+FLV_PREV_TAG_SIZE_LENGTH));
    }

    uAlreadyRead -= u4InterAlignDiff;

    ptBatch->write_idx++;

    while (ptBatch->curr_frame_idx != FLV_MP_SAMPLE_NO_MAX &&
           ptBatch->write_idx < FLV_MP_BATCH_READ_MAX)
    {
        u_frame_size = ptBatch->curr_frame_size;

        wr_idx = ptBatch->write_idx;
        ptBatch->size[wr_idx] = u_frame_size;
        ptBatch->offset[wr_idx] = ptBatch->curr_frame_offset;
        ptBatch->flags[wr_idx] = ptBatch->curr_frame_flags;
        ptBatch->DecTime[wr_idx] = ptBatch->curr_frame_dec_time;
        ptBatch->DispTime[wr_idx] = ptBatch->curr_frame_disp_time;
        ptBatch->skipsize[wr_idx] = uAlreadyRead;

        if(batch_size < (ptBatch->curr_frame_offset+u_frame_size+FLV_PREV_TAG_SIZE_LENGTH
                         -uInitOffset-uAlreadyRead) + (uInitOffset - u4AlignOffset))
        {
            reason = 1;
            break;
        }

        uReadOffset = 0;

        BufStart = ptBatch->p_mem_start+(ptBatch->curr_frame_offset+u_frame_size+FLV_PREV_TAG_SIZE_LENGTH-uInitOffset-uAlreadyRead);
        BufLength = batch_size-(ptBatch->curr_frame_offset+u_frame_size+FLV_PREV_TAG_SIZE_LENGTH-uInitOffset-uAlreadyRead)-(uInitOffset - u4AlignOffset);
        ret = FLVProviderSeekNextFrame(prFLVProviderCtrl, eType, BufStart, BufLength, &uReadOffset);
        /* update curr_frame_idx/curr_frame_offset/curr_frame_size/curr_frame_flags */

        if (ret != MED_S_OK)
        {
            if(ret == MED_E_PARSER_ERROR)
            {
                FLV_MP_TRACE_PARSE_ERROR(ret);
                FLV_STOP_LOGGING("FVR");
                return MED_E_CORRUPTED_DATA;
            }
            else if(bFileEnd == KAL_TRUE)
            {
                ptBatch->curr_frame_offset = 0;
                ptBatch->curr_frame_size = 0;
                ptBatch->curr_frame_flags = 0;
                ptBatch->curr_frame_dec_time = 0;
                ptBatch->curr_frame_disp_time = 0;
                ptBatch->curr_frame_idx = FLV_MP_SAMPLE_NO_MAX;
            }
            else
            {
                reason = 2;
                break;
            }
        }

        ptBatch->write_idx++;
    }
    FLV_PVDR_TRACE_3_VAL(reason, u_frame_size, u4ActualBufSize);

    FLV_STOP_LOGGING("FVR");

    kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_BATCH_READ_END, ePort, ptBatch->curr_frame_idx);
    if(ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_BATCH_READ_VIDEO_THUP,
              ptBatch->count, ptBatch->accum_time/ptBatch->count,
              ptBatch->accum_size/ptBatch->count,
              (ptBatch->accum_size/(ptBatch->accum_time+1)));
    }
    else
    {
        kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_BATCH_READ_AUDIO_THUP,
              ptBatch->count, ptBatch->accum_time/ptBatch->count,
              ptBatch->accum_size/ptBatch->count,
              (ptBatch->accum_size/(ptBatch->accum_time+1)));
    }

    return MED_S_OK;
}

/*
  MED_S_OK for EOS not reached
  MED_E_OUT_OF_MEMORY for EOS sent fail
  MED_S_PLAY_FINISH for EOS sent successful
  MED_E_ABORTED for EOS sent due to corrupted data
*/
static media_error_t FLVProviderCheckEOSNotify(FLV_PROVIDER_CTRL_T* prFLVProviderCtrl, SP_PORT_TYPE_T ePort)
{
    SPIF_PROVIDER_FRAME_INFO_T *prFrameInfo;
    FLV_PVDR_BATCH_READ_STRUCT *ptBatch;
    FLV_Track_Type eType;

    eType = FLV_TRACK_AUDIO;
    if(ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        eType = FLV_TRACK_VIDEO;
    }
    ptBatch = &(prFLVProviderCtrl->t_batch[eType]);

    prFrameInfo = &(prFLVProviderCtrl->rFrameInfo[eType]);
    if (!prFLVProviderCtrl->afgEos[eType])
    {
        if (((ptBatch->read_idx == (ptBatch->write_idx))
            &&(ptBatch->curr_frame_idx == FLV_MP_SAMPLE_NO_MAX))
            ||
            prFLVProviderCtrl->demux_time[eType] > (prFLVProviderCtrl->prVidStreamInfo->u8Duration + FLV_MP_DURATION_MARGIN)
            ||
            ((prFLVProviderCtrl->eSrcType == MED_MODE_PREVIEW) && (prFLVProviderCtrl->sample_no_start[eType]+1 == prFLVProviderCtrl->curr_sample_no[eType])))
        {
            memset(prFrameInfo, 0, sizeof(SPIF_PROVIDER_FRAME_INFO_T));
            prFrameInfo->fgEof = KAL_TRUE;
            prFrameInfo->u8Timestamp = prFLVProviderCtrl->demux_time[eType] + 30;

            if(prFLVProviderCtrl->bad_sample_no[eType] != FLV_MP_SAMPLE_NO_MAX)
            {
                // To stop at the point data corrupted, not to the stream duration
                prFrameInfo->u8Timestamp = prFLVProviderCtrl->demux_time[eType] + 30;
            }

            if (prFLVProviderCtrl->prSourceAPI->SPFN_ADD_ONE_DATA(prFLVProviderCtrl->prSourceHandle,
                                                                  ePort, prFrameInfo) == PROVIDER_ERROR_WAIT_RESOURCE)
            {
                return MED_E_OUT_OF_MEMORY;
            }
            // EOS sent successfully
            kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_EOS, ePort, __LINE__);
            prFLVProviderCtrl->afgEos[eType] = KAL_TRUE;
            if(prFLVProviderCtrl->bad_sample_no[eType] != FLV_MP_SAMPLE_NO_MAX)
            {
                return MED_E_ABORTED;
            }
            return MED_S_PLAY_FINISH;
        }
    }
    return MED_S_OK;
}

/*****************************************************************************
 * FUNCTION
 *  FLVProviderDemuxSampleAV
 * DESCRIPTION
 *  This function is to demux one sample data for specific track type.
 * PARAMETERS
 *  prFLVProviderCtrl             [IN]    flv provider context.
 *  ePort                               [IN]    Track type
 * RETURNS
 *  media_error_t
 *****************************************************************************/
static media_error_t FLVProviderDemuxSampleAV(FLV_PROVIDER_CTRL_T* prFLVProviderCtrl,
                                                          SP_PORT_TYPE_T ePort,
                                                          kal_uint32 *pu4Time)
{
    kal_uint8* p_sample  = NULL;
    kal_uint32 u_sample_size;
    kal_uint64 composition_time = 0;
    kal_uint32 curr_time = 0; // in ms
    media_error_t ret;
    kal_uint32 rd_idx;
    kal_uint32 wr_idx;
    SPIF_PROVIDER_FRAME_INFO_T *prFrameInfo;
    FLV_PVDR_BATCH_READ_STRUCT *ptBatch;
    FLV_Track_Type eType;

    eType = FLV_TRACK_AUDIO;
    if(ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        eType = FLV_TRACK_VIDEO;
    }
    ptBatch = &(prFLVProviderCtrl->t_batch[eType]);

    if (!prFLVProviderCtrl->fgSelectedTrack[eType])
    {
        return MED_S_FALSE;
    }

    prFrameInfo = &(prFLVProviderCtrl->rFrameInfo[eType]);

    rd_idx = ptBatch->read_idx;
    wr_idx = ptBatch->write_idx;

    FLV_ASSERT(prFLVProviderCtrl->curr_sample_no[eType] == (ptBatch->frame_idx_start + rd_idx));

    memset(prFrameInfo, 0, sizeof(SPIF_PROVIDER_FRAME_INFO_T));

    if (rd_idx != wr_idx)
    {
        u_sample_size = ptBatch->size[rd_idx];

        if ((u_sample_size > 0)
            #ifdef FLV_PARTIAL_DATA_READ
            ||
            ((u_sample_size == 0) && (ptBatch->flags[rd_idx] & FLV_FLAG_PARTIAL_DATA))
            #endif
            )
        {
            FLVProviderMediaDataAlloc(prFLVProviderCtrl, &p_sample, ePort);

            prFrameInfo->pu1Addr = p_sample;
            prFrameInfo->u4FrameSize = u_sample_size;
            prFrameInfo->u4PayloadSize = 0;
            prFrameInfo->pu1Payload = NULL;
            prFrameInfo->fgHeader = KAL_FALSE;
            prFrameInfo->fgKeyFrame = KAL_FALSE;
            if(ptBatch->flags[rd_idx] & FLV_FLAG_KEY_FRAME)
            {
                prFrameInfo->fgKeyFrame = KAL_TRUE;
            }

            #ifdef FLV_PARTIAL_DATA_READ
            if((u_sample_size == 0) && (ptBatch->flags[rd_idx] & FLV_FLAG_PARTIAL_DATA))
            {
                FLV_ASSERT(ePort == SOURCE_PROVIDER_PORT_AUDIO);
                prFrameInfo->fgSilent = KAL_TRUE;
            }
            #endif

        }
        else
        {
            ptBatch->read_idx++;
        }

        if(SOURCE_PROVIDER_PORT_VIDEO == ePort)
        {
        #ifdef __VE_H264_DEC_SUPPORT__
            if (MEDIA_CODEC_VID_H264 == prFLVProviderCtrl->prVidStreamInfo->eCodecType &&
                u_sample_size > prFLVProviderCtrl->prVideoParamSetData->u4NALuSizeInfo)
            {
                ret = ProviderUtilityGetAvcSampleNALU(prFLVProviderCtrl->prSourceAPI,
                                                     prFLVProviderCtrl->prSourceHandle,
                                                     prFrameInfo,
                                                     prFLVProviderCtrl->prVideoParamSetData->u4NALuSizeInfo);
                if (ret != MED_S_OK)
                {
                    FLV_MP_TRACE_RET_ERR(MED_E_OUT_OF_MEMORY);
                    FLVProviderMediaDataDealloc(prFLVProviderCtrl, SOURCE_PROVIDER_PORT_VIDEO);
                    return MED_E_OUT_OF_MEMORY;
                }
            }
        #endif
        }

        composition_time = ptBatch->DispTime[rd_idx];
        curr_time = composition_time;

        if(SOURCE_PROVIDER_PORT_VIDEO == ePort)
        {
            if (prFLVProviderCtrl->sample_no_start[FLV_TRACK_VIDEO] == prFLVProviderCtrl->curr_sample_no[FLV_TRACK_VIDEO] &&
                curr_time > prFLVProviderCtrl->start_time[FLV_TRACK_VIDEO])
            {
                curr_time = prFLVProviderCtrl->start_time[FLV_TRACK_VIDEO];
            }
        }

        if (!(prFLVProviderCtrl->sample_no_start[eType] == prFLVProviderCtrl->curr_sample_no[eType]))
        {
            if(curr_time > prFLVProviderCtrl->demux_time[eType])
            {
                // the duration this demux data can be played
                *pu4Time = curr_time - prFLVProviderCtrl->demux_time[eType];
            }
        }


        prFLVProviderCtrl->demux_time[eType] = curr_time;

        if ((u_sample_size > 0)
            #ifdef FLV_PARTIAL_DATA_READ
            ||
            ((u_sample_size == 0) && (ptBatch->flags[rd_idx] & FLV_FLAG_PARTIAL_DATA))
            #endif
            )

        {
            prFrameInfo->u8Timestamp = curr_time;
            if (prFLVProviderCtrl->prSourceAPI->SPFN_ADD_ONE_DATA(prFLVProviderCtrl->prSourceHandle,
                                                                  ePort, prFrameInfo) == PROVIDER_ERROR_WAIT_RESOURCE)
            {
                FLVProviderMediaDataDealloc(prFLVProviderCtrl, ePort);
                return MED_E_OUT_OF_MEMORY;
            }
            if(u_sample_size > 0)
            {
                prFLVProviderCtrl->prSourceAPI->SPFN_BITSTREAM_BUF_UPDATA_ADD(prFLVProviderCtrl->prSourceHandle,
                    ePort, (kal_uint32)p_sample+u_sample_size);
            }
        }

        if(prFrameInfo->pu1Payload != NULL)
        {
            FLV_ASSERT(MEDIA_CODEC_VID_H264 == prFLVProviderCtrl->prVidStreamInfo->eCodecType &&
                       SOURCE_PROVIDER_PORT_VIDEO == ePort);
            prFLVProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prFLVProviderCtrl->prSourceHandle,
                                                          prFrameInfo->pu1Payload);
        }
        prFLVProviderCtrl->curr_sample_no[eType]++;
    }

    ret = FLVProviderCheckEOSNotify(prFLVProviderCtrl, ePort);
    return ret;
}

static PROVIDER_ERROR_T FLVProviderParseAV(void *prHandle, kal_uint32 *pu4Time,
                                                   SP_PORT_TYPE_T ePort)
{
    media_error_t eRet;
    FLV_PROVIDER_CTRL_T *prFLVProviderCtrl = (FLV_PROVIDER_CTRL_T *)prHandle;
    FLV_Track_Type eType;

    eType = FLV_TRACK_AUDIO;
    if(ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        eType = FLV_TRACK_VIDEO;
    }

    *pu4Time = FLV_PROVIDER_MIN_ACCU_TIME;

    eRet = FLVProviderBatchRead(prFLVProviderCtrl, ePort);
    if (eRet != MED_S_OK)
    {
        if (eRet == MED_E_CORRUPTED_DATA ||
            eRet == MED_E_PARSER_ERROR ||
            eRet == MED_E_FSAL_ERROR)
        {
            FLVProviderBatchReset(prFLVProviderCtrl, ePort);
            prFLVProviderCtrl->bad_sample_no[eType] = prFLVProviderCtrl->t_batch[eType].curr_frame_idx;
            prFLVProviderCtrl->t_batch[eType].curr_frame_idx = FLV_MP_SAMPLE_NO_MAX;
            if(prFLVProviderCtrl->curr_sample_no[eType] == 0)
            {
                // No data is sent.
                // If any data are sent, EOS is notified with PROVIDER_ERROR_DELAY_REPORT_WITH_EOF returned.
                return PROVIDER_ERROR;
            }
        }

        if (eRet == MED_E_OUT_OF_MEMORY)
        {
            return PROVIDER_ERROR_WAIT_RESOURCE;
        }
    }

    eRet = FLVProviderDemuxSampleAV(prFLVProviderCtrl, ePort, pu4Time);

    if (eRet != MED_S_OK)
    {
        if (eRet == MED_E_CORRUPTED_DATA ||
            eRet == MED_E_PARSER_ERROR ||
            eRet == MED_E_FSAL_ERROR)
        {
            prFLVProviderCtrl->bad_sample_no[eType] = prFLVProviderCtrl->curr_sample_no[eType];
        }

        if (eRet == MED_E_OUT_OF_MEMORY)
        {
            return PROVIDER_ERROR_WAIT_RESOURCE;
        }
        else if (eRet == MED_S_PLAY_FINISH)
        {
            // EOS
            return PROVIDER_ERROR_EOF;
        }
        else if (eRet == MED_E_ABORTED)
        {
            // EOS due to data corrupted
            return PROVIDER_ERROR_DELAY_REPORT_WITH_EOF;
        }
    }

    return PROVIDER_ERROR_NONE;
}

static PROVIDER_ERROR_T FLVProviderOpen(void* const prHandle, SPIF_PROVIDER_OPEN_INFO_T *prInfo)
{
    FLV_PROVIDER_CTRL_T *prFLVProviderCtrl = (FLV_PROVIDER_CTRL_T *)prHandle;
    PROVIDER_ERROR_T eRet;

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_FLVPVDR_OPEN, prInfo->eOpenTrack);

    prFLVProviderCtrl->eSrcType = prInfo->eOpenType;
    prFLVProviderCtrl->eTrack = prInfo->eOpenTrack;
    if (prFLVProviderCtrl->eSrcType != MED_MODE_BUFFER)
    {
        prFLVProviderCtrl->prSourceAPI->SPFN_MEM_COPY(prFLVProviderCtrl->u_src.file_name, (void *)prInfo->pu1Data,
                                MPL_MAX_FILE_NAME_LEN * sizeof(kal_wchar));
    }
    else
    {
        prFLVProviderCtrl->u_src.file_buf_addr = (kal_uint32)prInfo->pu1Data;
        prFLVProviderCtrl->file_size = prInfo->u4DataSize;
    }

    _FLVProviderSelfInit(prFLVProviderCtrl);

    eRet = _FLVProviderOpenCore(prFLVProviderCtrl);
    if (eRet != PROVIDER_ERROR_NONE)
    {
        _FLVProviderSelfDeinit(prFLVProviderCtrl);
        return eRet;
    }

    return PROVIDER_ERROR_NONE;
}

static PROVIDER_ERROR_T FLVProviderClose(void* const prHandle)
{
    FLV_PROVIDER_CTRL_T *prFLVProviderCtrl = (FLV_PROVIDER_CTRL_T *)prHandle;

    _FLVProviderSelfDeinit(prFLVProviderCtrl);
    return PROVIDER_ERROR_NONE;
}

static PROVIDER_ERROR_T FLVProviderInit(void* const prHandle)
{
    return PROVIDER_ERROR_NONE;
}

static PROVIDER_ERROR_T FLVProviderDeInit(void* const prHandle)
{
    return PROVIDER_ERROR_NONE;
}

static PROVIDER_ERROR_T FLVProviderGetParameter(void* const prHandle, const PROVIDER_PARAM_TYPE_T eCmd, void * pParam)
{
    FLV_PROVIDER_CTRL_T *prFLVProviderCtrl = (FLV_PROVIDER_CTRL_T *)prHandle;
    PROVIDER_ERROR_T ePvdrRet = PROVIDER_ERROR_NONE;
    kal_uint32 timestart, timeelapsed;

    timestart = video_get_current_time();

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_FLVPVDR_GET_PARAM, eCmd);
    kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_GET_PARAM, eCmd);

    switch (eCmd)
    {
        case PROVIDER_PARAM_VID_STREAM_INFO:
            {
                SPIF_STREAM_INFO_T *prStreamInfo = (SPIF_STREAM_INFO_T *)pParam;
                SPIF_VIDEO_STREAM_INFO_T *prVidStrmInfo = prFLVProviderCtrl->prVidStreamInfo;

                prStreamInfo->pvStreamInfo = NULL;
                prStreamInfo->fgSupport = KAL_FALSE;
                prStreamInfo->u4Num = 0;

                if(prVidStrmInfo != NULL)
                {
                    prStreamInfo->u4Num = 1;
                    prStreamInfo->fgSupport = KAL_TRUE;
                    prStreamInfo->pvStreamInfo = (void *)prVidStrmInfo;
                }
            }
            break;

        case PROVIDER_PARAM_AUD_STREAM_INFO:
            {
                SPIF_STREAM_INFO_T *prStreamInfo = (SPIF_STREAM_INFO_T *)pParam;
                SPIF_AUDIO_STREAM_INFO_T *prAudStrmInfo = (SPIF_AUDIO_STREAM_INFO_T *)prFLVProviderCtrl->prAudStrmInfo;

                prStreamInfo->pvStreamInfo = NULL;
                prStreamInfo->fgSupport = KAL_FALSE;
                prStreamInfo->u4Num = 0;

                if(prAudStrmInfo != NULL)
                {
                    prStreamInfo->u4Num = 1;
                    prStreamInfo->fgSupport = KAL_TRUE;
                    prStreamInfo->pvStreamInfo = (void *)prAudStrmInfo;
                }
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
                //kal_mem_set(pParam, 0, sizeof(SPIF_META_DATA_T));
            }
            break;

        case PROVIDER_PARAM_META_CAPABILITY:
            {
                SP_CAPABILITY_T *prCap = (SP_CAPABILITY_T *)pParam;
                *prCap = SOURCE_RPOVIDER_NONE;
                #ifndef __VE_FLV_PSEUDO_KEY_TABLE__
                if(prFLVProviderCtrl->ptFLVMetaData->rKeyFrames.Real_Count > 0)
                #endif
                {
                    *prCap = SOURCE_PROVIDER_SEEK;
                }
            }

            break;

        case PROVIDER_PARAM_KEY_FRAME_TIME:
            {
                SPIF_KEY_FRAME_TIME_T *prKeyFrameTime = (SPIF_KEY_FRAME_TIME_T *)pParam;
                SP_PORT_TYPE_T eType = prKeyFrameTime->ePort;
                FLV_Track_Type eTrackType = (eType == SOURCE_PROVIDER_PORT_AUDIO) ? FLV_TRACK_AUDIO : FLV_TRACK_VIDEO;
                media_error_t eRet;
                kal_uint32 uFrmIdx, uOffset, uTime;

                FLV_ASSERT(prKeyFrameTime->eDirect == SOURCE_PROVIDER_SEARCH_BACKWARD);

                prFLVProviderCtrl->ptFLVParser[eTrackType]->pstFSAL = prFLVProviderCtrl->pt_fsal[eTrackType];
                eRet = _FLVProviderPrevKeyFramebyTime(prFLVProviderCtrl,
                    prFLVProviderCtrl->ptFLVParser[eTrackType], (kal_uint32)(prKeyFrameTime->u8StartTime),
                &uFrmIdx, &uOffset, &uTime,
                eTrackType);

                if(MED_E_NO_MORE_DATA == eRet)
                {
                    FLV_MP_TRACE_PARSE_ERROR(eRet);
                }
                else if(MED_S_OK != eRet)
                {
                    FLV_MP_TRACE_PARSE_ERROR(eRet);
                    ePvdrRet = PROVIDER_ERROR;
                    if(eRet == MED_E_ABORTED)
                    {
                        ePvdrRet = PROVIDER_ERROR_TERMINATE;
                    }
                    break;
                }
                prKeyFrameTime->u8KeyFrameTime = uTime;
                kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_GET_KEYTIME, eType,
                    (kal_uint32)(prKeyFrameTime->u8StartTime),(kal_uint32) prKeyFrameTime->u8KeyFrameTime);
            }
            break;
        case PROVIDER_PARAM_DRM_FSAL:
        {
            SPIF_DRM_INFO_T *prDrmInfo = (SPIF_DRM_INFO_T *)pParam;

            prDrmInfo->file_handle = prFLVProviderCtrl->file_handle;
        }
        break;

        default:
            ePvdrRet = PROVIDER_ERROR;;
            break;
    }

    timeelapsed = video_get_duration_ms(timestart);
    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_FLVPVDR_GET_PARAM, timeelapsed);
    return ePvdrRet;
}

static PROVIDER_ERROR_T FLVProviderSetParameter(void* const prHandle, const PROVIDER_PARAM_TYPE_T eCmd, void * pParam)
{
    FLV_PROVIDER_CTRL_T *prFLVProviderCtrl = (FLV_PROVIDER_CTRL_T *)prHandle;
    PROVIDER_ERROR_T eRet = PROVIDER_ERROR_NONE;
    SPIF_STREAM_T *prStream;
    SP_PORT_TYPE_T ePort;
    kal_uint8* pu1Sample;
    SP_API_T *prSrcAPI = prFLVProviderCtrl->prSourceAPI;
    SPIF_PROVIDER_FRAME_INFO_T rFrameInfo;
    kal_uint32 timestart, timeelapsed;

    timestart = video_get_current_time();

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_FLVPVDR_SET_PARAM, eCmd);
    kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_SET_PARAM, eCmd);

    switch (eCmd)
    {
        case PROVIDER_PARAM_SEEK_TIME:
        {
            SPIF_SEEK_TIME_T *prSeekTime = (SPIF_SEEK_TIME_T *)pParam;
            media_error_t e_ret = MED_S_OK;
            FLV_Track_Type eType;

            ePort = prSeekTime->eType;
            eType = FLV_TRACK_AUDIO;
            if(ePort == SOURCE_PROVIDER_PORT_VIDEO)
            {
                eType = FLV_TRACK_VIDEO;
            }
            prFLVProviderCtrl->afgEos[eType] = KAL_FALSE;
            prFLVProviderCtrl->bad_sample_no[eType] = FLV_MP_SAMPLE_NO_MAX;
            prFLVProviderCtrl->start_time[eType] = (kal_uint32)prSeekTime->u8StartTime;
            prFLVProviderCtrl->stop_time = (kal_uint32)prSeekTime->u8EndTime;

            e_ret = FLVProviderSeekKeyFrame(prFLVProviderCtrl, prFLVProviderCtrl->start_time[eType], eType);
            if (e_ret != MED_S_OK)
            {
                FLV_MP_TRACE_RET_ERR(e_ret);
                eRet = PROVIDER_ERROR;
                if(MED_E_ABORTED == e_ret)
                {
                    eRet = PROVIDER_ERROR_TERMINATE;
                }
                break;
            }

            kal_trace(FLV_MP_TRACE_GROUP, VID_TRC_FLVMP_SET_SEEKTIME, eType,
                prFLVProviderCtrl->start_time[eType], prFLVProviderCtrl->stop_time, prFLVProviderCtrl->curr_sample_no[eType]);

            prFLVProviderCtrl->sample_no_start[eType] = prFLVProviderCtrl->curr_sample_no[eType];
            FLVProviderBatchMemoReset(prFLVProviderCtrl, ePort);
            FLVProviderBatchReset(prFLVProviderCtrl, ePort);
        }
        break;

        case PROVIDER_PARAM_SELECT_STREAM:
        {
            FLV_Track_Type eType;
            prStream = (SPIF_STREAM_T *)pParam;

            eType = FLV_TRACK_AUDIO;
            if(prStream->eType == SOURCE_PROVIDER_PORT_VIDEO)
            {
                eType = FLV_TRACK_VIDEO;
            }
            prFLVProviderCtrl->fgSelectedTrack[eType] = KAL_TRUE;
        }
        break;

        case PROVIDER_PARAM_DESELECT_STREAM:
        {
            FLV_Track_Type eType;
            prStream = (SPIF_STREAM_T *)pParam;

            eType = FLV_TRACK_AUDIO;
            if(prStream->eType == SOURCE_PROVIDER_PORT_VIDEO)
            {
                eType = FLV_TRACK_VIDEO;
            }
            prFLVProviderCtrl->fgSelectedTrack[eType] = KAL_FALSE;
        }
        break;

        case PROVIDER_PARAM_SEND_HEADER:
        {
            SPIF_SNED_HEADER_T *prSendHeader = (SPIF_SNED_HEADER_T *)pParam;

            if (prSendHeader->fgVideo == KAL_TRUE)
            {
            #ifdef __VE_H264_DEC_SUPPORT__
            SPIF_H264_DECODER_PAYLOAD_INFO_T *prPayload = NULL;
            FLV_VIDEO_CODEC_FORMAT eVideoType;
            PU_VID_PARAM_SET_T* prParameterSet;
            kal_uint32 u4ActualBufSize;

            eVideoType = (FLV_VIDEO_CODEC_FORMAT)FLV_GetCodecType(prFLVProviderCtrl->ptFLVMetaData, FLV_TRACK_VIDEO);
            FLV_ASSERT(FLV_AVC == eVideoType);

            prParameterSet = prFLVProviderCtrl->prVideoParamSetData;
            if((eVideoType == FLV_AVC) && (prParameterSet->u4ParamSetTotalSize == 0))
            {
                // H.264 w/o SPS/PPS in container
                break;
            }
            pu1Sample = (kal_uint8 *)prFLVProviderCtrl->prSourceAPI->SPFN_BITSTREAM_BUF_QUERY_AVAILABLE_SIZE(
                                    prFLVProviderCtrl->prSourceHandle, SOURCE_PROVIDER_PORT_VIDEO, prParameterSet->u4ParamSetTotalSize, &u4ActualBufSize);
            FLV_ASSERT(pu1Sample);
            prSrcAPI->SPFN_MEM_COPY((void *)pu1Sample, (void *)prParameterSet->pu1ParamSetBuff, prParameterSet->u4ParamSetTotalSize);
            prFLVProviderCtrl->prSourceAPI->SPFN_BITSTREAM_BUF_UPDATA_ADD(prFLVProviderCtrl->prSourceHandle, SOURCE_PROVIDER_PORT_VIDEO, (kal_uint32)pu1Sample + prParameterSet->u4ParamSetTotalSize);

            memset(&rFrameInfo, 0, sizeof(SPIF_PROVIDER_FRAME_INFO_T));
            rFrameInfo.pu1Addr = pu1Sample;
            rFrameInfo.u4FrameSize = prParameterSet->u4ParamSetTotalSize;
            if (eVideoType == FLV_AVC)
            {
                kal_uint32 i;

                rFrameInfo.u4PayloadNum = prParameterSet->u4NumOfNALuParamSet;
                rFrameInfo.u4PayloadSize = sizeof(SPIF_H264_DECODER_PAYLOAD_INFO_T) * prParameterSet->u4NumOfNALuParamSet;
                prPayload = (SPIF_H264_DECODER_PAYLOAD_INFO_T *)prSrcAPI->SPFN_MALLOC_CLA(prFLVProviderCtrl->prSourceHandle,
                                                                                     rFrameInfo.u4PayloadSize, KAL_FALSE);
                for(i = 0; i < prParameterSet->u4NumOfNALuParamSet; i++)
                {
                    prPayload[i].u4Address = (kal_uint32)pu1Sample +
                                             (prParameterSet->prNALCTRLBuff[i].u4Address - (kal_uint32)prParameterSet->pu1ParamSetBuff);
                    prPayload[i].u4Length = prParameterSet->prNALCTRLBuff[i].u4Length;
                }
                rFrameInfo.pu1Payload = (kal_uint8 *)prPayload;
            }
            else
            {
                rFrameInfo.u4PayloadSize = 0;
                rFrameInfo.pu1Payload = NULL;
                rFrameInfo.u4PayloadNum = 0;
            }
            rFrameInfo.fgHeader = KAL_TRUE;
            rFrameInfo.u8Timestamp = 0;
            rFrameInfo.fgEof = rFrameInfo.fgKeyFrame = rFrameInfo.fgSilent = KAL_FALSE;
            if (prSrcAPI->SPFN_ADD_ONE_DATA(prFLVProviderCtrl->prSourceHandle,
                                            SOURCE_PROVIDER_PORT_VIDEO, &rFrameInfo) == PROVIDER_ERROR_WAIT_RESOURCE)
            {
                FLV_ASSERT(0);
                return PROVIDER_ERROR_WAIT_RESOURCE;
            }
            if(prPayload != NULL)
            {
                prFLVProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prFLVProviderCtrl->prSourceHandle, prPayload);
            }
            #endif
            }
        }
        break;

        case PROVIDER_PARAM_QUICK_CLOSE:
        case PROVIDER_PARAM_ABORT_PROCESS:
        {
            SPIF_ABORT_INFO_T *prAbort = (SPIF_ABORT_INFO_T *)pParam;

            prFLVProviderCtrl->ptFLVMetaData->fgFastBreak = prAbort->fgEnable;
        }
        break;

        default:
            eRet = PROVIDER_ERROR;
        break;
    }

    timeelapsed = video_get_duration_ms(timestart);
    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_FLVPVDR_SET_PARAM, timeelapsed);

    return eRet;
}

static PROVIDER_ERROR_T FLVProviderParseVideo(void* const prHandle, kal_uint32 *pu4Time)
{
    return FLVProviderParseAV(prHandle, pu4Time, SOURCE_PROVIDER_PORT_VIDEO);
}

static PROVIDER_ERROR_T FLVProviderParseAudio(void* const prHandle, kal_uint32 *pu4Time)
{
    return FLVProviderParseAV(prHandle, pu4Time, SOURCE_PROVIDER_PORT_AUDIO);
}


static const PROVIDER_API_T rFLVProviderAPI =
{
    FLVProviderOpen,
    FLVProviderClose,
    FLVProviderInit,
    FLVProviderDeInit,
    FLVProviderGetParameter,
    FLVProviderSetParameter,
    FLVProviderParseVideo,
    FLVProviderParseAudio
#ifdef __VE_SUBTITLE_SUPPORT__
    ,NULL
#endif
};

PROVIDER_ERROR_T FLVProviderGetHandle(void* const prSrcMgr, SP_API_T* const prSrcAPI, SPIF_PROVIDER_HANDLE_T *prPrvHdlr)
{
    FLV_PROVIDER_CTRL_T *prFLVProviderCtrl;

    if (prSrcMgr == NULL || prSrcAPI == NULL || prPrvHdlr == NULL)
    {
        FLV_ASSERT(0);
        return PROVIDER_ERROR;
    }
    prFLVProviderCtrl = (FLV_PROVIDER_CTRL_T *)prSrcAPI->SPFN_MALLOC_CLA(prSrcMgr, sizeof(FLV_PROVIDER_CTRL_T), KAL_TRUE);
    if(prFLVProviderCtrl == NULL)
    {
        return PROVIDER_ERROR;
    }
    memset(prFLVProviderCtrl, 0, sizeof(FLV_PROVIDER_CTRL_T));
    prFLVProviderCtrl->prSourceAPI = prSrcAPI;
    prFLVProviderCtrl->prSourceHandle = prSrcMgr;
    prPrvHdlr->pvHandle = (void *)prFLVProviderCtrl;
    prPrvHdlr->prAPI = (PROVIDER_API_T *)&rFLVProviderAPI;

    pFLVProviderHdlr = prFLVProviderCtrl;
    FLV_ASSERT(pFLVProviderHdlr != NULL);
    return PROVIDER_ERROR_NONE;
}

PROVIDER_ERROR_T FLVProviderReleaseHandle(void* const pvHandle)
{
    FLV_PROVIDER_CTRL_T *prFLVProviderCtrl = (FLV_PROVIDER_CTRL_T *)pvHandle;

    prFLVProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prFLVProviderCtrl->prSourceHandle, pvHandle);
    return PROVIDER_ERROR_NONE;
}

kal_bool FLVProviderCheckIntegrity(kal_uint8 *pu1Buf, kal_uint32 u4Len)
{
    kal_uint32 FileData = 0;
    kal_bool ret = KAL_FALSE;

    if (u4Len < FLV_PROVIDER_CHECK_CONTAINER_LEN)
    {
        return KAL_FALSE;
    }

    // FLV Signature
    FileData = pu1Buf[0] | (pu1Buf[1]<<8) | (pu1Buf[2]<<16);

    if(FileData != FLV_FILE_START)
    {
        ret = KAL_FALSE;
    }
    else
    {
        ret = KAL_TRUE;
    }

    return ret;
}

#endif /* __VE_FLV_FILE_FORMAT_SUPPORT__ */

