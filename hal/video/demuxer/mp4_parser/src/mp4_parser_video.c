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
 * mp4_parser_video.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Parser, for handling visual-related boxes
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(__M3GPMP4_FILE_FORMAT_SUPPORT__)
#include "mp4_parser.h"
#include "vcodec_v2_trc.h"
#include "drv_features_video.h"
#include "kal_general_types.h"
#include "fsal.h"
#include "mp4_common.h"
#include "kal_trace.h"

#ifdef __VE_MM_DCM_SUPPORT__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VECOM_ROCODE", rodata = "DYNAMIC_CODE_VECOM_RODATA"
#endif

static MP4_Parser_Status mp4_parse_resolution(STMp4Parser *pstMp4Parser)
{
   kal_uint16 u2Width, u2Height;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

    //Sample Entry:8
    //Visual Sample Entry:16
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 24))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &u2Width))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].width = (kal_uint32)u2Width;

   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &u2Height))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].height = (kal_uint32)u2Height;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 50))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   #if MP4_PARSER_VERBOSE
	printf("width=%u, height=%u\n", u2Width, u2Height);
#endif
    return MP4_PARSER_OK;
}

/*
DESCRIPTION
	Parse Bitrate Box.
INPUT
	size: The size of Bitrate Box excluding Box
RETURN
	MP4_PARSER_OK: Successful
	other values: Error
*/
static MP4_Parser_Status mp4_parse_bitr(STMp4Parser *pstMp4Parser, long bitr_size)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   //avg bitrate:4
   //max bitrate:4
	if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, bitr_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
	Parse H263 Specific Box.
INPUT
	size: The size of H263 Specific Box excluding Box
RETURN
	MP4_PARSER_OK: Successful
	other values: Error
*/

static MP4_Parser_Status mp4_parse_d263(STMp4Parser *pstMp4Parser, long d263_size)
{
   MP4_Parser_Status ret;
   Parse_Box_Entry BoxInfo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

	/* H263 Decoder Specific Structure */
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 7))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
	d263_size-=7;

   if(d263_size==0)
      return MP4_PARSER_OK;

   /* optional Specific bitrate information */
	{

        if((ret=mp4_parse_box(pstMp4Parser, d263_size, &BoxInfo))!=MP4_PARSER_OK)
			return ret;
        BoxInfo.size -= BoxInfo.Len;

		if(BOX_TYPE_BITR==BoxInfo.type) {
			if((ret=mp4_parse_bitr(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
				return ret;
		} else
			return MP4_PARSER_BITR_BOX_EXPECTED;
	}

	return MP4_PARSER_OK;
}



/*
DESCRIPTION
	Parse Sample Entry H263.
INPUT
	size: The size of Sample Entry H263 excluding Box
RETURN
	MP4_PARSER_OK: Successful
	other values: Error
*/

MP4_Parser_Status mp4_parse_s263(STMp4Parser *pstMp4Parser, long s263_size)
{
    MP4_Parser_Status ret;
    Parse_Box_Entry BoxInfo;


    ret = mp4_parse_resolution(pstMp4Parser);
    if (ret != MP4_PARSER_OK)
    {
        return ret;
    }
    s263_size -= 78;

    /* H263 Specific Box */
    {

        if((ret=mp4_parse_box(pstMp4Parser, s263_size, &BoxInfo))!=MP4_PARSER_OK)
            return ret;
        s263_size -= BoxInfo.Len;
        BoxInfo.size -= BoxInfo.Len;
        if(BOX_TYPE_D263==BoxInfo.type)
        {
            if((ret=mp4_parse_d263(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
                return ret;
            s263_size -= BoxInfo.size;
        }
        else
        {
            return MP4_PARSER_D263_BOX_EXPECTED;
        }
    }

    if(s263_size) {
       if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, s263_size))!=FSAL_OK)
          return MP4_PARSER_FILE_SEEK_ERROR;
    }

    return MP4_PARSER_OK;
}

/*
DESCRIPTION
    Parse Sample Entry H264.
INPUT
    size: The size of Sample Entry H264 excluding Box
RETURN
    MP4_PARSER_OK: Successful
    other values: Error
*/
#ifdef __VE_H264_DEC_SUPPORT__
MP4_Parser_Status mp4_parse_h264(STMp4Parser *pstMp4Parser, long h264_size)
{
    kal_uint32 h264_size_local;
    kal_uint8 u1Buffer[5];
    STAVCInfo *pstAVCInfo = NULL;

    MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
    {
        kal_uint32 pos;

        pstAVCInfo = &(pstMp4Parser->stMp4AVC);
        MP4_PARSER_FILE_GET_CUR_POS(pos);
        pstAVCInfo->uConfigOffset = pos;
        if (h264_size <= 5)
        {
            pstAVCInfo->uConfigSize = h264_size;
            pstAVCInfo->uParameterSetOffset = pos + h264_size;
            pstAVCInfo->uParameterSetSize = 0;

            h264_size_local = 0;
        }
        else
        {
            pstAVCInfo->uConfigSize = 5;
            pstAVCInfo->uParameterSetOffset = pos + 5;
            pstAVCInfo->uParameterSetSize = h264_size - 5;

            FSAL_Read_Bytes(pstMp4Parser->pstFSAL, u1Buffer, 5);
            pstAVCInfo->configurationVersion = u1Buffer[0];
            pstAVCInfo->AVCProfileIndication = u1Buffer[1];
            pstAVCInfo->profile_compatibility = u1Buffer[2];
            pstAVCInfo->AVCLevelIndication = u1Buffer[3];
            pstAVCInfo->lengthSizeMinusOne = u1Buffer[4] & 0x3;

            h264_size_local = h264_size - 5;
        }
    }

    if(h264_size_local > 0)
    {
        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, h264_size_local))!=FSAL_OK)
            return MP4_PARSER_PARSE_ERROR;
    }

    return MP4_PARSER_OK;
}

/*
DESCRIPTION
	Parse Sample Entry H264.
INPUT
	size: The size of Sample Entry H264 excluding Box
RETURN
	MP4_PARSER_OK: Successful
	other values: Error
*/

MP4_Parser_Status mp4_parse_s264(STMp4Parser *pstMp4Parser, long s264_size)
{
   MP4_Parser_Status ret;
   Parse_Box_Entry BoxInfo;

   ret = mp4_parse_resolution(pstMp4Parser);
   if (ret != MP4_PARSER_OK)
   {
        return ret;
   }
   s264_size-=78;

   while(s264_size>=8) {

      if((ret=mp4_parse_box(pstMp4Parser, s264_size, &BoxInfo))!=MP4_PARSER_OK)
         return ret;

      s264_size -= BoxInfo.Len;
      BoxInfo.size -= BoxInfo.Len;

      if(SAMPLE_FMT_AVCC==BoxInfo.type) {
         /* H264 Specific Box */
         if((ret=mp4_parse_h264(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
      } else if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;

      s264_size -= BoxInfo.size;
   }

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, s264_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if (pstMp4Parser->stMp4AVC.uConfigOffset == 0)
      return MP4_PARSER_PARSE_ERROR;

   return MP4_PARSER_OK;
}
#endif

/*
DESCRIPTION
	Parse Sample Entry MP4V.
INPUT
	size: The size of Sample Entry MP4V excluding Box
RETURN
	MP4_PARSER_OK: Successful
	other values: Error
*/

MP4_Parser_Status mp4_parse_mp4v(STMp4Parser *pstMp4Parser, long mp4v_size)
{
   MP4_Parser_Status ret;
   Parse_Box_Entry BoxInfo;

   ret = mp4_parse_resolution(pstMp4Parser);
   if (ret != MP4_PARSER_OK)
   {
        return ret;
   }
   mp4v_size-=78;

   while(mp4v_size>=8) {

      if((ret=mp4_parse_box(pstMp4Parser, mp4v_size, &BoxInfo))!=MP4_PARSER_OK)
         return ret;
      mp4v_size-=BoxInfo.Len;
      BoxInfo.size -= BoxInfo.Len;

      if (BoxInfo.size>mp4v_size)
         return MP4_PARSER_PARSE_ERROR;

      switch(BoxInfo.type) {
      case BOX_TYPE_ESDS: /* ESDBox */
         if((ret=mp4_parse_esds(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      mp4v_size-=BoxInfo.size;
   }

   if(mp4v_size) {
      if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, mp4v_size))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;
   }

   return MP4_PARSER_OK;
}

MP4_Parser_Status mp4_parse_mjpg(STMp4Parser *pstMp4Parser, long mjpg_size)
{
    kal_uint16 width, height;

    MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

    /* Sample Entry */
    if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 8))!=FSAL_OK)
        return MP4_PARSER_FILE_SEEK_ERROR;
    mjpg_size-=8;

    /* Visual Sample Entry */
    if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 16))!=FSAL_OK)
        return MP4_PARSER_FILE_SEEK_ERROR;
    if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &width))!=FSAL_OK)
        return MP4_PARSER_PARSE_ERROR;
    pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].width = (kal_uint32)width;

    if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &height))!=FSAL_OK)
        return MP4_PARSER_PARSE_ERROR;
    pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].height = (kal_uint32)height;

    if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 50))!=FSAL_OK)
        return MP4_PARSER_FILE_SEEK_ERROR;

    mjpg_size-=70;

    if(mjpg_size)
    {
        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, mjpg_size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
    }

   return MP4_PARSER_OK;
}

#ifdef __VE_MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

#if defined(__VIDEO_ARCHI_V2__)
MP4_Parser_Status MP4_Video_TimeToSampleNo(STMp4Parser *pstMp4Parser, kal_uint64 uMiliSecond, kal_uint32 *puVideoSampleNo)
{
   MP4_Parser_Status ret;
   kal_uint64 uDecodeTime;
   kal_uint32 uTimeScale;
   kal_uint32 ucSampleNo;
   MP4_PARSER_CHECK_ARG(puVideoSampleNo!=NULL);

   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uTimeScale, MP4_TRACK_VIDEO))!=MP4_PARSER_OK)
      goto MP4_Video_TimeToSampleNo_end;

   uDecodeTime = uMiliSecond * uTimeScale / 1000;

   if ((ret=MP4_GetSampleNumber(pstMp4Parser, &ucSampleNo, uDecodeTime, MP4_TRACK_VIDEO))!=MP4_PARSER_OK)
      goto MP4_Video_TimeToSampleNo_end;

   *puVideoSampleNo = ucSampleNo;
   ret = MP4_PARSER_OK;

MP4_Video_TimeToSampleNo_end:
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_VIDEO_TIMETOSAMPLENO, (int)uMiliSecond, (int)(*puVideoSampleNo),(int)ret);
#endif

   return ret;
}
#ifdef PGDL_SUPPORT
MP4_Parser_Status MP4_Video_GetAvailableDur(STMp4Parser *pstMp4Parser, kal_uint32 *puVideoDuration)
{
    MP4_Parser_Status ret;
    kal_uint32 uVidDuration, uVideoSampleNo, uSampleOffset, start_index=0, end_index=0, uVideoLastSampleNo;
    kal_uint32 file_size, uVideoTimeScale, uStep,queued_frame_number;
    kal_uint32 uVidDurationMs;
    kal_uint32 u4FrameSize;
    STMp4Track *prTrack;

    FSAL_GetFileSize(pstMp4Parser->pstFSAL, &file_size);

    //*puVideoDuration = 216576;
    //return MP4_PARSER_OK;

    *puVideoDuration = 0;
    // duration in sample count
    if ((ret=MP4_GetMediaDuration(pstMp4Parser, &uVidDuration, MP4_TRACK_VIDEO))!=MP4_PARSER_OK) {
        //video_dbg_trace(PDL_VidDuration_Error, uVidDuration);
        return ret;
    }
    if (uVidDuration==0) {
        //video_dbg_trace(PDL_VidDuration_Error, uVidDuration);
        return MP4_PARSER_PARSE_ERROR;
    }

    if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uVideoTimeScale, MP4_TRACK_VIDEO))!=MP4_PARSER_OK) {
        //video_dbg_trace(PDL_VidTimeScale_Error, uVideoTimeScale);
        return ret;
    }
#if 0
/* under construction !*/
/* under construction !*/
#endif
    prTrack = &(pstMp4Parser->stMp4Track[pstMp4Parser->bVideoTrack]);
    uVideoLastSampleNo = prTrack->uSampleCount;

    uStep = uVideoLastSampleNo/64;
    uVidDurationMs = (kal_uint64)uVidDuration * (kal_uint64)1000 / (kal_uint64)uVideoTimeScale;

    uVideoSampleNo = prTrack->uGetAvaDurCurSampleCnt;
if(uVideoSampleNo<uVideoLastSampleNo)
{
    if(uVideoSampleNo > 0)
        uVideoSampleNo -= 1;

    if (uStep==0)  // Some file may contain less than 16 samples.
        uStep = 1;

    while(1) // For coarse search.
    {

        if ((ret=MP4_GetSampleOffset(pstMp4Parser, uVideoSampleNo, &uSampleOffset, MP4_TRACK_VIDEO))!=MP4_PARSER_OK) {
            //video_dbg_trace(PDL_GetSampleOffset_Error1, uSampleOffset*10000+uVideoSampleNo);
            return ret;
        }

        if((kal_int32)file_size <= (kal_int32)uSampleOffset){
            break;
        }else{
            if( (uVideoSampleNo + uStep) < uVideoLastSampleNo ) {
                uVideoSampleNo += uStep;
            } else {
                uVideoSampleNo = uVideoLastSampleNo;
                break;
            }
        }

    }

    if (uStep == 1) {
        end_index = uVideoSampleNo;
    } else {
        if(end_index < start_index){
            end_index = start_index;
        } else {
            start_index = prTrack->uGetAvaDurCurSampleCnt;
            end_index = uVideoSampleNo;
            // Binary Search
            while ((kal_int32)(end_index-start_index)>1) { // For finer search
                kal_uint32 middle_index = (start_index + end_index) / 2;

                if ((ret=MP4_GetSampleOffset(pstMp4Parser, middle_index, &uSampleOffset, MP4_TRACK_VIDEO))!=MP4_PARSER_OK) {
                    //video_dbg_trace(PDL_GetSampleOffset_Error2, uSampleOffset*10000+uVideoSampleNo);
                    return ret;
                }

#ifdef MP4_PARSER_TRC_LOG
    kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_VIDEO_GETAVAILABLEDUR, file_size, uVideoSampleNo, uSampleOffset, start_index, middle_index, end_index);
#endif
                if ((kal_int32)file_size > (kal_int32)uSampleOffset)
                    start_index = middle_index;
                else
                    end_index = middle_index;
            }
            if ((end_index > start_index) && (end_index < uVideoLastSampleNo))   // Set to the smaller one to avoid the sample offset of end_index > real file_size except for end_index = the last sample case.
                end_index = start_index;
        }
    }

    prTrack->uGetAvaDurCurSampleCnt = end_index;

    if (end_index == 0)
    {
        // Get 1st sample size
        ret = MP4_GetSampleSize(pstMp4Parser, 0, &u4FrameSize, MP4_TRACK_VIDEO);
        if (ret != MP4_PARSER_OK)
        {
            return ret;
        }
    }
    if ((end_index==0)&&((kal_int32)file_size < (kal_int32)(uSampleOffset + u4FrameSize))) // for the case that downloads partial the first 1 sample
    {
        *puVideoDuration = 0;
    }
    else if ((end_index==1)&&((kal_int32)file_size < (kal_int32)(uSampleOffset))) // for the case that downloads partial the first 1 sample
        *puVideoDuration = 0;
    else {
        kal_uint64 tmp_dur=0;
        //*puVideoDuration = (kal_uint64)end_index * (kal_uint64)uVidDurationMs / (kal_uint64)uVideoLastSampleNo;  // not precise enough.

        /*MAUI_00786245, Scott, Need to reserve the queued frame*/
        queued_frame_number = 18; //Currently we don't know the codec type
        if(end_index != uVideoSampleNo)
        {
            if(end_index <= queued_frame_number)
                end_index =1;
            else
                end_index = end_index - queued_frame_number;
        }

        MP4_GetDecodeTime(pstMp4Parser, end_index, &tmp_dur, MP4_TRACK_VIDEO);
        *puVideoDuration = (kal_uint32)((tmp_dur*1000)/uVideoTimeScale);
    }

    if (*puVideoDuration != 0) {
        //video_dbg_trace(PDL_GetAvailDur_GT_0, end_index*100000 + (kal_int32)file_size);
        //drv_trace4(TRACE_GROUP_10, VIDEO_PDL_GETAVAILDUR1, pstMp4Parser->stMp4Track[pstMp4Parser->bVideoTrack].uGetAvaDurCurSampleCnt, end_index, uVideoLastSampleNo, file_size);
        //drv_trace4(TRACE_GROUP_10, VIDEO_PDL_GETAVAILDUR2, uVidDuration, uVideoTimeScale, uVidDurationMs, *puVideoDuration);

    } else {
        //video_dbg_trace(PDL_GetAvailDur_EQ_0, video_get_current_time());
    }
}
else
{
    *puVideoDuration = uVidDurationMs;
}
    return MP4_PARSER_OK;
}
#endif /* PGDL_SUPPORT */
#endif /* defined(__VIDEO_ARCHI_V2__) */

#if 0
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
#if MP4_PARSER_VERBOSE
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
#if MP4_PARSER_VERBOSE
/* under construction !*/
#endif
#if 0
/* under construction !*/
/* under construction !*/
#endif
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
#if MP4_PARSER_VERBOSE
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if 0

#endif //(__M3GPMP4_FILE_FORMAT_SUPPORT__)

