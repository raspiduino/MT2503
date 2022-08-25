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
 * mp4_parser_audio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Parser, for handling audio-related boxes
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
//#include "mp4_sample_data_audio.h"
#include "vcodec_v2_trc.h"

#include "kal_general_types.h"
#include "fsal.h"
#include "mp4_common.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "fs_errcode.h"

//extern void*  med_alloc_ext_mem(kal_int32 size);
//extern void   med_free_ext_mem(void** pointer);

#ifdef __VE_MM_DCM_SUPPORT__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VECOM_ROCODE", rodata = "DYNAMIC_CODE_VECOM_RODATA"
#endif

static const kal_uint32 samplingFrequencyFromIndex[16] = {
  96000, 88200, 64000, 48000, 44100, 32000, 24000, 22050,
  16000, 12000, 11025, 8000, 7350, 0, 0, 0
};
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
#endif

/*
   Convert sampling frequency to sampling frequency index.
   Refer to 14496-3 Subpart 4
*/
kal_uint32 convertSamplingFreqToIndex(kal_uint32 uSamplingFreq)
{
   kal_uint32 uSamplingFreqIndex;
   if (uSamplingFreq>=92017) uSamplingFreqIndex = 0x0;
   else if (uSamplingFreq>=75132) uSamplingFreqIndex = 0x1;
   else if (uSamplingFreq>=55426) uSamplingFreqIndex = 0x2;
   else if (uSamplingFreq>=46009) uSamplingFreqIndex = 0x3;
   else if (uSamplingFreq>=37566) uSamplingFreqIndex = 0x4;
   else if (uSamplingFreq>=27713) uSamplingFreqIndex = 0x5;
   else if (uSamplingFreq>=23004) uSamplingFreqIndex = 0x6;
   else if (uSamplingFreq>=18783) uSamplingFreqIndex = 0x7;
   else if (uSamplingFreq>=13856) uSamplingFreqIndex = 0x8;
   else if (uSamplingFreq>=11502) uSamplingFreqIndex = 0x9;
   else if (uSamplingFreq>=9391) uSamplingFreqIndex = 0xa;
   else uSamplingFreqIndex = 0xb;

   return uSamplingFreqIndex;
}


/*
DESCRIPTION
   Parse the Program Config Element of AudioSpecificConfig of 14496-3.
INPUT
   *puBitCnt: current bit offset
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_decoder_config_14496_3_pce(STMp4Parser *pstMp4Parser, kal_uint32 *puBitCnt)
{
   kal_uint32 uInitialBitCnt, discard_cnt;
   kal_uint8 element_instance_tag;
   kal_uint8 object_type;
   kal_uint8 sampling_freq_index;
   kal_uint8 num_front_channel_elements;
   kal_uint8 num_side_channel_elements;
   kal_uint8 num_back_channel_elements;
   kal_uint8 num_lfe_channel_elements;
   kal_uint8 num_assoc_data_elements;
   kal_uint8 num_valid_cc_elements;
   kal_uint8 mono_mixdown_present;
   kal_uint8 stereo_mixdown_present;
   kal_uint8 matrix_mixdown_idx_present;
   kal_uint8 discard;
   //kal_uint8 i;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL || puBitCnt!=NULL);

   uInitialBitCnt = *puBitCnt;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &element_instance_tag, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((element_instance_tag == 0) || (element_instance_tag == 1))
      pstMp4Parser->bAudioChannelConfig[pstMp4Parser->bCurTrack] = element_instance_tag + 1;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &object_type, 2))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &sampling_freq_index, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &num_front_channel_elements, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &num_side_channel_elements, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &num_back_channel_elements, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &num_lfe_channel_elements, 2))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &num_assoc_data_elements, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &num_valid_cc_elements, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   /* mono mixdown */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &mono_mixdown_present, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if(mono_mixdown_present) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &discard, 4))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
   }
   /* stereo mixdown */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &stereo_mixdown_present, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if(stereo_mixdown_present) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &discard, 4))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
   }
   /* matrix mixdown */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &matrix_mixdown_idx_present, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if(matrix_mixdown_idx_present) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &discard, 3))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
   }

    discard_cnt = ((num_front_channel_elements + num_side_channel_elements + num_back_channel_elements + num_valid_cc_elements) * 5) + 
        ((num_lfe_channel_elements + num_assoc_data_elements) * 4);
    
    *puBitCnt += discard_cnt;
   pstMp4Parser->uAudioPCEBitLength = (*puBitCnt)-uInitialBitCnt;

   return MP4_PARSER_OK;
}

static MP4_Parser_Status mp4_parse_wave(STMp4Parser *pstMp4Parser, long wave_size)
{
    Parse_Box_Entry BoxInfo;

    if(wave_size <= 0)
        return MP4_PARSER_PARSE_MP4A_BOXLENGTH_ERROR;

    while(wave_size > 8)
    {
        MP4_Parser_Status ret;

        if((ret=mp4_parse_box(pstMp4Parser, wave_size,&BoxInfo))!=MP4_PARSER_OK)
            return ret;
        wave_size -= BoxInfo.Len;
        BoxInfo.size -= BoxInfo.Len;

        switch(BoxInfo.type)
        {
            case BOX_TYPE_ESDS:
            if((ret=mp4_parse_esds(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            {
                ASSERT(0);
                return ret;
            }
            break;

            default: /* unrecognized type, skip the box */
             if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
                return MP4_PARSER_FILE_SEEK_ERROR;
          }
          wave_size -= BoxInfo.size;
    }

    if(wave_size > 0)
    {
        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, wave_size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
        wave_size = 0;
    }

    if(wave_size < 0)
        return MP4_PARSER_PARSE_MP4A_BOXLENGTH_ERROR;

    return MP4_PARSER_OK;
}

/*
DESCRIPTION
   Parse Sample Entry MP4A.
INPUT
   size: The size of Sample Entry MP4A excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/
MP4_Parser_Status mp4_parse_mp4a(STMp4Parser *pstMp4Parser, long mp4a_size)
{
    /* Sample Entry MP4A is a leaf node. */

    /* Audio Sample Entry */
    kal_uint16 channelcount = 0;
    kal_uint16 samplesize = 0;
    kal_uint32 samplerate = 0;
    kal_uint16 version = 0;
    Parse_Box_Entry BoxInfo;

    MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
    if(mp4a_size <= 0)
        return MP4_PARSER_PARSE_MP4A_BOXLENGTH_ERROR;

    if(mp4a_size >= 28)
    {
        /* Sample Entry */
        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 8))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
        mp4a_size-=8;

        /* Audio Sample Entry */
        if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &version))!=FSAL_OK)
            return MP4_PARSER_PARSE_ERROR;
        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 6))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
        if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &channelcount))!=FSAL_OK)
            return MP4_PARSER_PARSE_ERROR;
        if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &samplesize))!=FSAL_OK)
            return MP4_PARSER_PARSE_ERROR;
        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
        if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &samplerate))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;

        mp4a_size-=20;
    }
    else
    {
        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, mp4a_size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
        mp4a_size = 0;
    }
    pstMp4Parser->uAudioChannelCount[pstMp4Parser->bCurTrack] = channelcount;
    pstMp4Parser->uAudioSampleSize[pstMp4Parser->bCurTrack] = samplesize;
    pstMp4Parser->uAudioSampleRate[pstMp4Parser->bCurTrack] = samplerate>>16;
    pstMp4Parser->uAudioSampleDcrpVer = version;
#if MP4_PARSER_VERBOSE
    printf("channel=%u, samplesize=%u, samplerate=%u\n",
        channelcount, samplesize, samplerate>>16);
#endif

    if(version == 1)
    {
        // QuickTime File Format. 4 fields (16 bytes) for version 1
        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 16))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
        mp4a_size -= 16;
    }

    while(mp4a_size > 8)
    {

        MP4_Parser_Status ret;

        if((ret=mp4_parse_box(pstMp4Parser, mp4a_size, &BoxInfo))!=MP4_PARSER_OK)
            return ret;
        mp4a_size-=BoxInfo.Len;
        BoxInfo.size -= BoxInfo.Len;

        switch(BoxInfo.type)
        {
            case BOX_TYPE_ESDS:
            if((ret=mp4_parse_esds(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            {
                return ret;
            }
            break;

            case BOX_TYPE_WAVE: // To support QuickTime File Format
            if((ret=mp4_parse_wave(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            {
                return ret;
            }
            break;

            default: /* unrecognized type, skip the box */
            if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
                return MP4_PARSER_FILE_SEEK_ERROR;
        }

        mp4a_size-=BoxInfo.size;
    }

    if(mp4a_size > 0)
    {
        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, mp4a_size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
        mp4a_size = 0;
    }

    if(mp4a_size < 0)
        return MP4_PARSER_PARSE_MP4A_BOXLENGTH_ERROR;

   return MP4_PARSER_OK;
}

/*
DESCRIPTION
   Parse AMR Specific Box.
INPUT
   size: The size of AMR Specific Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_damr(STMp4Parser *pstMp4Parser, long damr_size)
{
   //kal_uint16 mode_set;
   //kal_uint8 mode_change_period;
   kal_uint8 bFramesPerSample;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   /* AMR Decoder Specific Structure */
   //skip 5, mod set: 2, mod change period: 1
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 8))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &bFramesPerSample, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   damr_size-=9;

   pstMp4Parser->bFramesPerSample = bFramesPerSample;

   if(damr_size > 0)
   {
       if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, damr_size))!=FSAL_OK)
          return MP4_PARSER_PARSE_ERROR;
   }

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse Sample Entry SAMR or SAWB.
INPUT
   size: The size of Sample Entry SAMR or SAWB excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

MP4_Parser_Status mp4_parse_samr(STMp4Parser *pstMp4Parser, long samr_size)
{
   /* Sample Entry SAMR or SAWB is a leaf node. */
   MP4_Parser_Status ret;
   Parse_Box_Entry BoxInfo;

   /* Audio Sample Entry */
   kal_uint16 channelcount = 0;
   kal_uint16 samplesize = 0;
   kal_uint32 uSampleRate = 0;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);


   /* Sample Entry: 8 */
   /* Audio Sample Entry: 8 */
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 16))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &channelcount))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &samplesize))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &uSampleRate))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   pstMp4Parser->uAudioChannelCount[pstMp4Parser->bCurTrack] = channelcount;
   pstMp4Parser->uAudioSampleSize[pstMp4Parser->bCurTrack] = samplesize;
   pstMp4Parser->uAudioSampleRate[pstMp4Parser->bCurTrack] = uSampleRate;

   pstMp4Parser->bAudioSamplingFreqIndex[pstMp4Parser->bCurTrack] = convertSamplingFreqToIndex(uSampleRate>>16);

   samr_size-=28;

#if MP4_PARSER_VERBOSE
   printf("channel=%u, samplesize=%u, samplerate=%u\n",
      channelcount, samplesize, uSampleRate>>16);
#endif

   /* AMRSpecificBox */
   if(samr_size)
   {
      if(samr_size > 8)
      {
         if((ret=mp4_parse_box(pstMp4Parser, samr_size,&BoxInfo))!=MP4_PARSER_OK)
            return ret;

         BoxInfo.size -= BoxInfo.Len;
         if(BoxInfo.type==BOX_TYPE_DAMR) {
            if((ret=mp4_parse_damr(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
               return ret;
         } else
            return MP4_PARSER_DAMR_BOX_EXPECTED;
      }
      else if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, samr_size))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;
   }

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the AudioSpecificConfig of 14496-3.
INPUT
   size: The size of the decoder specific info.
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

MP4_Parser_Status mp4_parse_decoder_config_14496_3(STMp4Parser *pstMp4Parser, long box_size)
{
   MP4_Parser_Status ret;
   kal_uint32 uBitCnt = 0;

   /* Audio Specific Config */
   kal_uint8 audioObjectType;
   kal_uint8 samplingFreqIndex;
   kal_uint32 samplingFreq;

   /* GA Specific Config */
   kal_uint8 frameLengthFlag;
   kal_uint8 dependsOnCoreCoder;
   kal_uint8 extensionFlag;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   {
      kal_uint32 uSizeTmp;
      MP4_PARSER_FILE_GET_CUR_POS(uSizeTmp);
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_14496_3_STARTOFFSET, uSizeTmp);
#endif
   }

   if(box_size < 2)                //at least need 2 bytes (16bits)
       return MP4_PARSER_PARSE_14496_3_BOXLENGTH_ERROR;
   /* Refer to 14496-3 Subpart 1 */

   /* audio object type */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &audioObjectType, 5))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   pstMp4Parser->bAudioObjectType = audioObjectType;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &samplingFreqIndex, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if(samplingFreqIndex==0xf) {
      kal_uint8 freq[3];
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &freq[2], 8))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &freq[1], 8))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &freq[0], 8))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;

      samplingFreq = (freq[2]<<16) + (freq[1]<<8) + (freq[0]);

      /* Refer to 14496-3 Subpart 4 */
      samplingFreqIndex = convertSamplingFreqToIndex(samplingFreq);
   } else if(samplingFreqIndex==0xc) {
      /* Refer to 14496-3 Subpart 4 */
      samplingFreqIndex = 0xb;
   } else if(samplingFreqIndex==0xd || samplingFreqIndex==0xe) {
      return MP4_PARSER_PARSE_ERROR;
   }

   pstMp4Parser->bAudioSamplingFreqIndex[pstMp4Parser->bCurTrack] = samplingFreqIndex;

   /* channel configuration */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &(pstMp4Parser->bAudioChannelConfig[pstMp4Parser->bCurTrack]), 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if(pstMp4Parser->bAudioChannelConfig[pstMp4Parser->bCurTrack]>0x02)
      return MP4_PARSER_AUDIO_TOO_MANY_CHANNEL;

   /* GA Specific Config */
   /* Refer to 14496-3 Part 4 */

   /* frame length flag */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &frameLengthFlag, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if(frameLengthFlag!=0)
      return MP4_PARSER_960_120_IMDCT_NOT_SUPPORT;

   /* depends on core coder */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &dependsOnCoreCoder, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   //if(dependsOnCoreCoder)
   //   return MP4_PARSER_SCALABLE_STREAM_NOT_SUPPORT;

   /* extension flag */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &extensionFlag, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if(pstMp4Parser->bAudioObjectType ==22){  // BSAC
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, (kal_uint8 *)&(pstMp4Parser->uNumOfSubFrame), 5)) != FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;

      {
         kal_uint8 layerlen[2];
         if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &layerlen[1], 8))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;
         if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &layerlen[0], 3))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;

         pstMp4Parser->uLayerLength = (layerlen[1]<<3) + (layerlen[0]);
      }
   }

   if(pstMp4Parser->bAudioChannelConfig[pstMp4Parser->bCurTrack]==0) {
      /* parse program_config_element */
      MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->uAudioPCEFileOffset);

      if((ret=mp4_parse_decoder_config_14496_3_pce(pstMp4Parser, &uBitCnt))!=MP4_PARSER_OK)
         return ret;
   }

   box_size -= (uBitCnt+7)/8;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, box_size))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   return MP4_PARSER_OK;
}


static void putbits(unsigned char *in, unsigned int *bitcnt, int data, int data_length)
{
   int t,count;

   MP4_PARSER_ASSERT_NO_RET_VAL(data_length>0 && data_length<=16);

   t = *bitcnt;

   if( (t & 0x7)== 0)
      in[t>>3] = 0;

   if( (t & 0x7) + data_length  <= 8)
      in[(t>>3)] |= (data << (8-((t&0x7) + data_length)));
   else {
      count = (t&7) + data_length;
      in[(t>>3)] |= (data >> (data_length - 8 + (t&7)));
      count -= 8;

      if(count > 8) {
         in[(t>>3)+1] = (unsigned char)((data >> (count-8))&0xFF);
         in[(t>>3)+2] = (unsigned char)((data << (16-count))&0xFF);
      } else {
         in[(t>>3)+1] = (unsigned char)((data << (8-count))&0xFF);
      }
   }
   *bitcnt += data_length;
}

/*
 * Prepare only once for the whole stream.
 */
MP4_Parser_Status prepareADIFFrameHeader(STMp4Parser *pstMp4Parser)
{
   kal_uint32 uBitCnt;
   kal_uint32 uBitrate;
   kal_uint8 *pbHeader;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   pbHeader = pstMp4Parser->pbADIFFrameHeader;

   pstMp4Parser->uADIFHeaderReadOffset = 0;

   if(pstMp4Parser->uAudioAvgBitrate) { /* constant bitrate */
      uBitrate = pstMp4Parser->uAudioAvgBitrate;
   } else {
      uBitrate = pstMp4Parser->uAudioMaxBitrate;
   }

   /* adif_header */
   uBitCnt = 0;
   //uHeaderSize = 8 + pstMp4Parser->uAudioPCELength;
   putbits(pbHeader, &uBitCnt, 0x4144, 16); /* adif_id: AD */
   putbits(pbHeader, &uBitCnt, 0x4946, 16); /* adif_id: IF */
   putbits(pbHeader, &uBitCnt, 0, 1);     /* copyright id present */
   putbits(pbHeader, &uBitCnt, 1, 1);     /* original copy */
   putbits(pbHeader, &uBitCnt, 0, 1);     /* home */
   putbits(pbHeader, &uBitCnt, 1, 1);     /* bitstream type */
   putbits(pbHeader, &uBitCnt, (uBitrate>>7) & 0xFFFF, 16); /* bit rate */
   putbits(pbHeader, &uBitCnt, (uBitrate) & 0x7F, 7);    /* bit rate */
   putbits(pbHeader, &uBitCnt, 0x0, 4);      /* number of program config elements */
   MP4_PARSER_ASSERT(uBitCnt==63);

   /* program_config_element */
   {
      kal_int32 iBitLeft;
      kal_uint8 bPCE;

      if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSAL, pstMp4Parser->uAudioPCEFileOffset))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;

      iBitLeft = pstMp4Parser->uAudioPCEBitLength;
      while (iBitLeft > 0) {
         if ((pstMp4Parser->eFSALErr=FSAL_Read(pstMp4Parser->pstFSAL, &bPCE, 1))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;
         if (iBitLeft<8)
            putbits(pbHeader, &uBitCnt, bPCE, iBitLeft);
         else
            putbits(pbHeader, &uBitCnt, bPCE, 8);
         iBitLeft -= 8;
      }
   }

   /* byte alignment */
   if (uBitCnt%8 != 0)
      putbits(pbHeader, &uBitCnt, 0, 8-uBitCnt%8);

   /* comment_field_bytes */
   putbits(pbHeader, &uBitCnt, 0, 8);

   MP4_PARSER_ASSERT(uBitCnt%8 == 0);
   MP4_PARSER_ASSERT(uBitCnt<=ADIF_HEADER_SIZE*8);

   pstMp4Parser->uADIFFrameHeaderLen = uBitCnt/8;

   MP4_PARSER_ASSERT(pstMp4Parser->uADIFFrameHeaderLen ==
      (63 + pstMp4Parser->uAudioPCEBitLength + 7) / 8 + 1);

   return MP4_PARSER_OK;
}

MP4_Parser_Status prepareAACFrameHeader(STMp4Parser *pstMp4Parser)
{
   MP4_Parser_Status ret;
   MP4_Audio_Type eAudioType;

   eAudioType = MP4_GetAudioType(pstMp4Parser);
   if ((eAudioType != MP4_AUDIO_AAC) && (eAudioType != MP4_AUDIO_BSAC))
      return MP4_PARSER_OK;

   if (pstMp4Parser->bAudioChannelConfig[pstMp4Parser->bAudioTrack]==0) {
      /* Generate ADIF stream */
      pstMp4Parser->bAddADIFFrameHeader = KAL_TRUE;
      if ((ret=prepareADIFFrameHeader(pstMp4Parser))!=MP4_PARSER_OK)
         return ret;
   } else {
      /* Generate ADTS stream */
      pstMp4Parser->bAddADTSFrameHeader = KAL_TRUE;
   }

   return MP4_PARSER_OK;
}

kal_uint16 MP4_Audio_GetChannelCount(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   return pstMp4Parser->uAudioChannelCount[pstMp4Parser->bAudioTrack];
}

kal_uint16 MP4_Audio_GetSampleSize(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   return pstMp4Parser->uAudioSampleSize[pstMp4Parser->bAudioTrack];
}

kal_uint32 MP4_Audio_GetSamplingFreq(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if((pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] == MP4_AUDIO_AAC) ||
      (pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] == MP4_AUDIO_BSAC))
   {
      return samplingFrequencyFromIndex[pstMp4Parser->bAudioSamplingFreqIndex[pstMp4Parser->bAudioTrack]];
   }
   else if(pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] == MP4_AUDIO_AMR)
   {
      return 8000;
   }
   else if(pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] == MP4_AUDIO_AMR_WB)
   {
      return 16000;
   }
   else if(pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] == MP4_AUDIO_MP3)
   {
       return pstMp4Parser->uAudioSampleRate[pstMp4Parser->bAudioTrack];
   }
   else
   {
      MP4_PARSER_ASSERT(0);
   }
}

#ifdef __VE_MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

kal_uint8 MP4_Audio_GetChannelNum(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if((pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] == MP4_AUDIO_AAC) ||
      (pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] == MP4_AUDIO_BSAC)){
      kal_uint8 bAudioChannelConfig = pstMp4Parser->bAudioChannelConfig[pstMp4Parser->bAudioTrack];

      if(bAudioChannelConfig)
         return bAudioChannelConfig;
      else{
         return 2; // Not support
      }
   }else // AMR or AWB
      return 1;
}

extern MP4_Parser_Status mp4_parse_sinf(STMp4Parser *pstMp4Parser, kal_int32 sinf_size);
/*
DESCRIPTION
   Parse Sample Entry MP4A.
INPUT
   size: The size of Sample Entry MP4A excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

kal_uint8 mp4_audio_amr_get_frame_per_sample(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   return pstMp4Parser->bFramesPerSample;
}

/*
 * Prepare for every audio sample of the whole stream.
 */
void prepareADTSFrameHeader(STMp4Parser *pstMp4Parser, kal_uint8* pbFrameHeader, kal_uint32 uSampleSize)
{
   kal_uint32 uBitCnt;

   MP4_PARSER_ASSERT_NO_RET_VAL(pstMp4Parser!=NULL);
   MP4_PARSER_ASSERT_NO_RET_VAL(pbFrameHeader!=NULL);

   /* adts_fixed_header */
   uBitCnt = 0;
   putbits(pbFrameHeader, &uBitCnt, 0xFFF, 12); // syncword
   putbits(pbFrameHeader, &uBitCnt, 0, 1);      // ID
   putbits(pbFrameHeader, &uBitCnt, 0, 2);      // Layer
   putbits(pbFrameHeader, &uBitCnt, 1, 1);      // Protection absent
   putbits(pbFrameHeader, &uBitCnt, 1, 2);      // Profile
   putbits(pbFrameHeader, &uBitCnt, MP4_Audio_GetFreqIndex(pstMp4Parser), 4); // sample_frequency_index
   putbits(pbFrameHeader, &uBitCnt, 0, 1);      // private_bit
   putbits(pbFrameHeader, &uBitCnt, pstMp4Parser->bAudioChannelConfig[pstMp4Parser->bAudioTrack], 3); // Channel_configuration
   putbits(pbFrameHeader, &uBitCnt, 1, 1);      // original_copy
   putbits(pbFrameHeader, &uBitCnt, 0, 1);      // Home

   /* adts_variable_header */
   putbits(pbFrameHeader, &uBitCnt, 0, 1);      // copy_identification_bit
   putbits(pbFrameHeader, &uBitCnt, 0, 1);      // copy_identification_byte
   putbits(pbFrameHeader, &uBitCnt, uSampleSize + ADTS_HEADER_SIZE, 13); // length
   putbits(pbFrameHeader, &uBitCnt, 0x7FF, 11); // buffer_fullness
   putbits(pbFrameHeader, &uBitCnt, 0, 2);      // no_raw_data_blocks_in_frame
   MP4_PARSER_ASSERT_NO_RET_VAL(uBitCnt==56);
}

kal_uint32 MP4_Audio_GetSampleRate(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   return pstMp4Parser->uAudioSampleRate[pstMp4Parser->bAudioTrack];
}

kal_uint8 MP4_Audio_GetFreqIndex(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   return pstMp4Parser->bAudioSamplingFreqIndex[pstMp4Parser->bAudioTrack];
}

MP4_Parser_Status MP4_Audio_SetFSAL(STMp4Parser *pstMp4Parser, STFSAL *pstFSALAudio)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL || pstFSALAudio!=NULL);

   pstMp4Parser->pstFSALAudio = pstFSALAudio;

   return MP4_PARSER_OK;
}

MP4_Parser_Status MP4_Audio_Seek_To_Video(STMp4Parser *pstMp4Parser, kal_uint64 uVideoDecodeTime, kal_uint32 *puAudioSampleNo)
{
   MP4_Parser_Status ret;
   kal_uint64 uAudioDecodeTime;
   kal_uint32 uVideoTimeScale;
   kal_uint32 uAudioTimeScale;
   kal_uint64 uChkDecTime;

   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uVideoTimeScale, MP4_TRACK_VIDEO))!=MP4_PARSER_OK)
      return ret;

   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uAudioTimeScale, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      return ret;

   uAudioDecodeTime = uVideoDecodeTime * uAudioTimeScale / uVideoTimeScale;
   if ((ret=MP4_GetSampleNumber(pstMp4Parser, puAudioSampleNo, uAudioDecodeTime, MP4_TRACK_AUDIO ))!=MP4_PARSER_OK)
      return ret;

#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_AUDIO_SEEK_TO_VIDEO,*puAudioSampleNo ,(int)(uVideoDecodeTime*1000 / uVideoTimeScale));
#endif
    //Dior add for avoid DeltaTime of audio is too large and make A/V sync fail.
   ret = MP4_GetDecodeTime( pstMp4Parser, *puAudioSampleNo, &uChkDecTime, MP4_TRACK_AUDIO );
   if( (uAudioDecodeTime - uChkDecTime) > (uAudioTimeScale * 4) )  //set 4 secs as threashold to check if bad table data
      return MP4_PARSER_NO_SUCH_SAMPLE;


   return MP4_PARSER_OK;
}



MP4_Parser_Status MP4_Audio_Seek(STMp4Parser *pstMp4Parser, kal_uint32 uAudioSampleNo)
{
   MP4_Parser_Status ret;
   kal_uint32 uAudioSampleCount;
   kal_uint32 uAudioTimeScale;
   kal_uint64 uAudioDecodeTime;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   pstMp4Parser->uAudioReadSampleNo = uAudioSampleNo;
   pstMp4Parser->uAudioReadSampleOffset = 0;
   pstMp4Parser->uADTSHeaderReadOffset = 0;

   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uAudioTimeScale, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      goto MP4_Audio_Seek_Err;

   if ((ret=MP4_GetSampleCount(pstMp4Parser, MP4_TRACK_AUDIO, &uAudioSampleCount))!=MP4_PARSER_OK)
      goto MP4_Audio_Seek_Err;

   if ((ret=MP4_GetDecodeTime(pstMp4Parser, uAudioSampleNo, &uAudioDecodeTime, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      goto MP4_Audio_Seek_Err;

   pstMp4Parser->uAudioSeekPointTime = uAudioDecodeTime * 1000 / uAudioTimeScale;

   if (uAudioSampleNo < uAudioSampleCount) {
      if ((ret=MP4_GetSampleOffset(pstMp4Parser, uAudioSampleNo, &(pstMp4Parser->uAudioReadSampleFileOffset), MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
         goto MP4_Audio_Seek_Err;
   }

MP4_Audio_Seek_Err:
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_AUDIO_SEEK, (int)uAudioSampleNo ,(int)pstMp4Parser->uAudioSeekPointTime, (int)ret);
#endif
   return ret;
}



/*
 * Invoke MP4_GetSampleOffset_Next for optimization
 */
MP4_Parser_Status MP4_Audio_Seek_Internal(STMp4Parser *pstMp4Parser, kal_uint32 uAudioSampleNo)
{
   MP4_Parser_Status ret;
   kal_uint32 uAudioSampleCount;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   pstMp4Parser->uAudioReadSampleNo = uAudioSampleNo;
   pstMp4Parser->uAudioReadSampleOffset = 0;
   pstMp4Parser->uADTSHeaderReadOffset = 0;

   if ((ret=MP4_GetSampleCount(pstMp4Parser, MP4_TRACK_AUDIO, &uAudioSampleCount))!=MP4_PARSER_OK)
      return ret;

   if (uAudioSampleNo<uAudioSampleCount) {
      if ((ret=MP4_GetSampleOffset_Next(pstMp4Parser, &(pstMp4Parser->uAudioReadSampleFileOffset), MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
         return ret;
   }

   return MP4_PARSER_OK;
}

/* Update some variables after reading some data */
#define MP4_AUDIO_READ_UPDATE(uLen) \
   *uReadSize += (uLen); \
   pBuf += (uLen); \
   uSizeLeft -= (uLen)

/**
 * Read audio samples as a contiguous stream.
 * Note that fsal_direct_seek must be done immediately before fsal_direct_read,
 * to avoid the situation
 * that when accessing sample tables, file position has been changed.
 */
MP4_Parser_Status MP4_Audio_Read(STMp4Parser *pstMp4Parser, kal_uint8* pBuf, kal_uint32 uSize, kal_uint32 *uReadSize)
{
   MP4_Parser_Status ret;
   kal_uint32 uSizeLeft = uSize;
   kal_uint32 uCurSampleSize;
   kal_uint32 uCurSampleOffset;
   kal_uint32 uSampleCount;
   kal_uint32 uFileOffset;
   kal_uint8 *pbADTSFrameHeader;
   kal_uint8 *pbADIFFrameHeader;
#ifdef MP4_PARSER_TRC_LOG   
   kal_uint32 err_index;
#endif   
   STFSAL *pstFSALAudio = pstMp4Parser->pstFSALAudio;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL || pstFSALAudio !=NULL || pBuf!=NULL || uReadSize!=NULL);

   /* Initialize some local variables */
   *uReadSize = 0;
#ifdef MP4_PARSER_TRC_LOG    
   err_index = 0;
#endif   
   pbADTSFrameHeader = pstMp4Parser->pbADTSFrameHeader;
   pbADIFFrameHeader = pstMp4Parser->pbADIFFrameHeader;

   /* consider when there is no audio track or audio sample number is 0 */
   if ((ret=MP4_GetSampleCount(pstMp4Parser, MP4_TRACK_AUDIO, &uSampleCount))!=MP4_PARSER_OK)
   {
#ifdef MP4_PARSER_TRC_LOG    
      err_index = 0x0002;
#endif      
      goto MP4_Audio_Read_err; //return ret;
   }
   if (pstMp4Parser->uAudioReadSampleNo >= uSampleCount)
   {
#ifdef MP4_PARSER_TRC_LOG    
      err_index = 0x0004;
#endif      
      ret = MP4_PARSER_READ_EOF;
      goto MP4_Audio_Read_err;
   }

   {  /* Update File Size */
      FSAL_Status fret;

      fret = FSAL_Direct_GetFileSize(pstFSALAudio, &(pstFSALAudio->uFileSize));
      if (fret != FSAL_OK)
      {
#ifdef MP4_PARSER_TRC_LOG       
         err_index = 0x0006;
#endif         
         ret = MP4_PARSER_READ_EOF;
         goto MP4_Audio_Read_err;
      }
   }

   if ((ret=MP4_GetSampleSize(pstMp4Parser, pstMp4Parser->uAudioReadSampleNo, &uCurSampleSize, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
   {
#ifdef MP4_PARSER_TRC_LOG    
      err_index = 0x0008;
#endif      
      goto MP4_Audio_Read_err;
   }
   uCurSampleOffset = pstMp4Parser->uAudioReadSampleOffset;
   uFileOffset = pstMp4Parser->uAudioReadSampleFileOffset;
   if (KAL_TRUE == pstMp4Parser->bAddADIFFrameHeader) {
      /* handle the case if the ADTS frame header has not been read out completely */
      if (pstMp4Parser->uADIFHeaderReadOffset < pstMp4Parser->uADIFFrameHeaderLen) {
         kal_uint32 uADIFFrameSizeLeft = pstMp4Parser->uADIFFrameHeaderLen - pstMp4Parser->uADIFHeaderReadOffset;
         if (uADIFFrameSizeLeft >= uSizeLeft) {
            kal_mem_cpy(pBuf, pbADIFFrameHeader + pstMp4Parser->uADIFHeaderReadOffset, uSizeLeft);
            pstMp4Parser->uADIFHeaderReadOffset += uSizeLeft;
            MP4_AUDIO_READ_UPDATE(uSizeLeft);
            return MP4_PARSER_OK;
         } else {
            kal_mem_cpy(pBuf, pbADIFFrameHeader + pstMp4Parser->uADIFHeaderReadOffset, uADIFFrameSizeLeft);
            pstMp4Parser->uADIFHeaderReadOffset = pstMp4Parser->uADIFFrameHeaderLen;
            MP4_AUDIO_READ_UPDATE(uADIFFrameSizeLeft);
         }
      }
   }

   if (KAL_TRUE == pstMp4Parser->bAddADTSFrameHeader) {
      /* handle the case if the ADTS frame header has been read partially */
      if (pstMp4Parser->uADTSHeaderReadOffset < ADTS_HEADER_SIZE) {
         kal_uint32 uADTSFrameSizeLeft = ADTS_HEADER_SIZE - pstMp4Parser->uADTSHeaderReadOffset;
         prepareADTSFrameHeader(pstMp4Parser, pbADTSFrameHeader, uCurSampleSize);
         if (uADTSFrameSizeLeft >= uSizeLeft) {
            kal_mem_cpy(pBuf, pbADTSFrameHeader + pstMp4Parser->uADTSHeaderReadOffset, uSizeLeft);
            pstMp4Parser->uADTSHeaderReadOffset += uSizeLeft;
            MP4_AUDIO_READ_UPDATE(uSizeLeft);
            return MP4_PARSER_OK;
         } else {
            kal_mem_cpy(pBuf, pbADTSFrameHeader + pstMp4Parser->uADTSHeaderReadOffset, uADTSFrameSizeLeft);
            pstMp4Parser->uADTSHeaderReadOffset = ADTS_HEADER_SIZE;
            MP4_AUDIO_READ_UPDATE(uADTSFrameSizeLeft);
         }
      }
   }

   /* handle the case if the current sample has been read partially */
   if (pstMp4Parser->uAudioReadSampleOffset!=0) {
      kal_uint32 uCurSampleSizeLeft = uCurSampleSize - uCurSampleOffset;
      uFileOffset += pstMp4Parser->uAudioReadSampleOffset;
      if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSALAudio, uFileOffset))!=FSAL_OK)
      {
#ifdef MP4_PARSER_TRC_LOG       
         err_index = 0x000a;
#endif         
         ret = MP4_PARSER_FILE_SEEK_ERROR;
         goto MP4_Audio_Read_err;
      }
      if (uCurSampleSizeLeft > uSizeLeft) {
         {

            if(pstFSALAudio->uFileSize < (uFileOffset+uSizeLeft))
            {
#ifdef MP4_PARSER_TRC_LOG             
               err_index = 0x000c;
#endif               
               ret = MP4_PARSER_READ_EOF;
               goto MP4_Audio_Read_err;
            }
         }
         if ((pstMp4Parser->eFSALErr=FSAL_Read(pstFSALAudio, pBuf, uSizeLeft))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;
         pstMp4Parser->uAudioReadSampleOffset += uSizeLeft;
         MP4_AUDIO_READ_UPDATE(uSizeLeft);
         return MP4_PARSER_OK;
      } else {

         if(pstFSALAudio->uFileSize < (uFileOffset + uCurSampleSizeLeft))
         {
#ifdef MP4_PARSER_TRC_LOG          
            err_index = 0x000e;
#endif            
            ret = MP4_PARSER_READ_EOF;
            goto MP4_Audio_Read_err;

         }
         if ((pstMp4Parser->eFSALErr=FSAL_Read(pstFSALAudio, pBuf, uCurSampleSizeLeft))!=FSAL_OK)
         {
#ifdef MP4_PARSER_TRC_LOG         
            err_index = 0x0010;
#endif            
            ret = MP4_PARSER_FILE_READ_ERROR;
            goto MP4_Audio_Read_err;

         }
         MP4_AUDIO_READ_UPDATE(uCurSampleSizeLeft);
         /* read out the current sample, seek to next sample */
         if ((ret=MP4_Audio_Seek_Internal(pstMp4Parser, pstMp4Parser->uAudioReadSampleNo+1))!=MP4_PARSER_OK)
         {
#ifdef MP4_PARSER_TRC_LOG          
            err_index = 0x0012;
#endif            
            goto MP4_Audio_Read_err;
         }
      }
   }

   while(uSizeLeft > 0 && pstMp4Parser->uAudioReadSampleNo < uSampleCount) {
      if ((ret=MP4_GetSampleSize(pstMp4Parser, pstMp4Parser->uAudioReadSampleNo, &uCurSampleSize, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      {
#ifdef MP4_PARSER_TRC_LOG       
         err_index = 0x0014;
#endif         
         goto MP4_Audio_Read_err;
      }
      uFileOffset = pstMp4Parser->uAudioReadSampleFileOffset;
      if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSALAudio, uFileOffset))!=FSAL_OK)
      {
#ifdef MP4_PARSER_TRC_LOG       
         err_index = 0x0016;
#endif         
         ret = MP4_PARSER_FILE_SEEK_ERROR;
         goto MP4_Audio_Read_err;
      }
      if (KAL_TRUE == pstMp4Parser->bAddADTSFrameHeader) {
         if (pstMp4Parser->uADTSHeaderReadOffset < ADTS_HEADER_SIZE) {
            kal_uint32 uADTSFrameSizeLeft = ADTS_HEADER_SIZE - pstMp4Parser->uADTSHeaderReadOffset;
            prepareADTSFrameHeader(pstMp4Parser, pbADTSFrameHeader, uCurSampleSize);
            if (uADTSFrameSizeLeft >= uSizeLeft) {
               kal_mem_cpy(pBuf, pbADTSFrameHeader + pstMp4Parser->uADTSHeaderReadOffset, uSizeLeft);
               pstMp4Parser->uADTSHeaderReadOffset += uSizeLeft;
               MP4_AUDIO_READ_UPDATE(uSizeLeft);
               break;
            } else {
               kal_mem_cpy(pBuf, pbADTSFrameHeader + pstMp4Parser->uADTSHeaderReadOffset, uADTSFrameSizeLeft);
               pstMp4Parser->uADTSHeaderReadOffset = ADTS_HEADER_SIZE;
               MP4_AUDIO_READ_UPDATE(uADTSFrameSizeLeft);
            }
         }
      }
      if (uCurSampleSize > uSizeLeft) {
         {

            if(pstFSALAudio->uFileSize < (uFileOffset+uSizeLeft))
            {
#ifdef MP4_PARSER_TRC_LOG             
               err_index = 0x0018;
#endif               
               ret = MP4_PARSER_READ_EOF;
               goto MP4_Audio_Read_err;
            }
         }
         if((pstMp4Parser->eFSALErr=FSAL_Read(pstFSALAudio, pBuf, uSizeLeft))!=FSAL_OK)
         {
#ifdef MP4_PARSER_TRC_LOG          
            err_index = 0x001a;
#endif            
            ret = MP4_PARSER_FILE_READ_ERROR;
            goto MP4_Audio_Read_err;
         }
         pstMp4Parser->uAudioReadSampleOffset = uSizeLeft;
         MP4_AUDIO_READ_UPDATE(uSizeLeft);
         break;
      } else {
         {

            if(pstFSALAudio->uFileSize < (uFileOffset+uCurSampleSize))
            {
#ifdef MP4_PARSER_TRC_LOG             
               err_index = 0x001c;
#endif               
               ret = MP4_PARSER_READ_EOF;
               goto MP4_Audio_Read_err;
            }
         }
         if ((pstMp4Parser->eFSALErr=FSAL_Read(pstFSALAudio, pBuf, uCurSampleSize))!=FSAL_OK)
         {
#ifdef MP4_PARSER_TRC_LOG          
            err_index = 0x001e;
#endif            
            ret = MP4_PARSER_FILE_READ_ERROR;
            goto MP4_Audio_Read_err;
         }
         MP4_AUDIO_READ_UPDATE(uCurSampleSize);
         if ((ret=MP4_Audio_Seek_Internal(pstMp4Parser, pstMp4Parser->uAudioReadSampleNo+1))!=MP4_PARSER_OK)
         {
#ifdef MP4_PARSER_TRC_LOG          
            err_index = 0x0020;
#endif            
            goto MP4_Audio_Read_err;
         }
      }
   }

   if (pstMp4Parser->uAudioReadSampleNo >= uSampleCount)
   {
#ifdef MP4_PARSER_TRC_LOG    
      err_index = 0x0022;
#endif      
      ret = MP4_PARSER_READ_EOF;
      goto MP4_Audio_Read_err;
   }
   else
      return MP4_PARSER_OK;

MP4_Audio_Read_err:
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_AUDIO_READ_ERR,pstMp4Parser->uParserFinish, (int)ret, (int)err_index );
#endif
   return ret;
}

MP4_Parser_Status MP4_Audio_TimeToSampleNo(STMp4Parser *pstMp4Parser, kal_uint64 uMiliSecond, kal_uint32 *puAudioSampleNo )
{
   MP4_Parser_Status ret;
   kal_uint64 uAudioDecodeTime = 0;
   kal_uint32 uAudioTimeScale;
   kal_uint32 ucAudioSampleNo;

   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uAudioTimeScale, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      goto MP4_Audio_TimeToSampleNo_end;

   uAudioDecodeTime = uMiliSecond * uAudioTimeScale / 1000;

   if ((ret=MP4_GetSampleNumber(pstMp4Parser, &ucAudioSampleNo, uAudioDecodeTime, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      goto MP4_Audio_TimeToSampleNo_end;

   *puAudioSampleNo = ucAudioSampleNo;
   ret = MP4_PARSER_OK;
#ifdef MP4_PARSER_IGNORE_AUDLASTSAMPLE
   {
   	kal_uint32 uAudioSampleCount;
      if ((ret=MP4_GetSampleCount(pstMp4Parser, MP4_TRACK_AUDIO, &uAudioSampleCount))!=MP4_PARSER_OK)
         return ret;
      if (ucAudioSampleNo == (uAudioSampleCount-1))
      {
         ret = MP4_PARSER_AUDLAST_IGNORE;
      }
   }
#endif
MP4_Audio_TimeToSampleNo_end:
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_AUDIO_TIMETOSAMPLENO, (int)uMiliSecond, (int)(*puAudioSampleNo),(int)ret);
#endif

   if (ret != MP4_PARSER_OK)
   {
      kal_uint32 uAudioSampleCount;
      kal_uint32 uDuration;

      if ((MP4_PARSER_OK == MP4_GetSampleCount(pstMp4Parser, MP4_TRACK_AUDIO, &uAudioSampleCount)) &&
          (MP4_PARSER_OK == MP4_GetMediaDuration(pstMp4Parser, &uDuration, MP4_TRACK_AUDIO)))
      {
         if (uAudioDecodeTime <= uDuration)
         {
            *puAudioSampleNo = uAudioSampleCount - 1;
            ret = MP4_PARSER_OK;
         }
      }
   }

   return ret;
}

#ifdef PGDL_SUPPORT
MP4_Parser_Status MP4_Audio_GetAvailableDur(STMp4Parser *pstMp4Parser, kal_uint32 *puAudioDuration )
{
   MP4_Parser_Status ret;
   kal_uint32 uAudDuration, uAudioSampleNo, uSampleOffset, start_index, end_index, uAudioLastSampleNo;
   kal_uint32 file_size, uAudioTimeScale;
   kal_uint32 *pGetAvaDurCurSampleCnt;

   FSAL_GetFileSize(pstMp4Parser->pstFSAL, &file_size);

   *puAudioDuration = 0;
   pGetAvaDurCurSampleCnt = &pstMp4Parser->stMp4Track[pstMp4Parser->bAudioTrack].uGetAvaDurCurSampleCnt;
// duration in sample count
   if ((ret=MP4_GetMediaDuration(pstMp4Parser, &uAudDuration, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      return ret;

   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uAudioTimeScale, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      return ret;
// duration in ms
   uAudDuration = (kal_uint32)((kal_uint64)uAudDuration * (kal_uint64)1000 / (kal_uint64)uAudioTimeScale);

   //if ((ret=MP4_Audio_TimeToSampleNo(pstMp4Parser, uAudDuration, &uAudioLastSampleNo))!=MP4_PARSER_OK)
   //   return ret;

   uAudioLastSampleNo = pstMp4Parser->stMp4Track[pstMp4Parser->bAudioTrack].uSampleCount;
   uAudioSampleNo = *pGetAvaDurCurSampleCnt;
if(uAudioSampleNo<uAudioLastSampleNo)
{
   if(uAudioSampleNo > 0)
      uAudioSampleNo -= 1;
   
   while(1)
   {

	  if ((ret=MP4_GetSampleOffset(pstMp4Parser, uAudioSampleNo, &uSampleOffset, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
         return ret;

	  if((kal_int32)file_size <= (kal_int32)uSampleOffset){
         break;
	  }else{
         if( (uAudioSampleNo+ CHNUK_SAMPLE_NO) < uAudioLastSampleNo )
	         uAudioSampleNo += CHNUK_SAMPLE_NO;
		   else{
		      uAudioSampleNo = uAudioLastSampleNo;
		      break;
		   }
	  }

   }

   start_index = *pGetAvaDurCurSampleCnt;
   end_index = uAudioSampleNo;

// Binary Search
   if(end_index < start_index){
      end_index = start_index;
   }else{
       while ((kal_int32)(end_index-start_index)>1) {
          kal_uint32 middle_index = (start_index + end_index) / 2;

          if ((ret=MP4_GetSampleOffset(pstMp4Parser, middle_index, &uSampleOffset, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
             return ret;

#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_AUDIO_GETAVAILABLEDUR, file_size, uAudioSampleNo, uSampleOffset, start_index, middle_index, end_index);
#endif

          if ((kal_int32)file_size > (kal_int32)uSampleOffset)
             start_index = middle_index;
          else
             end_index = middle_index;
       }
	  if ((end_index > start_index) && (end_index < uAudioLastSampleNo))
	  	end_index = start_index;
   }


   *pGetAvaDurCurSampleCnt = end_index;
   *puAudioDuration = (kal_uint32)((kal_uint64)end_index * (kal_uint64)uAudDuration / (kal_uint64)uAudioLastSampleNo);
}
else
{
	*puAudioDuration = uAudDuration;

}
   return MP4_PARSER_OK;
}
#endif

MP4_Parser_Status MP4_Audio_GetCurReadOffset(STMp4Parser *pstMp4Parser, kal_uint32 *puCurrReadOffset)
{
   MP4_Parser_Status ret;
   kal_uint32 uAudioSampleCount, uAudioSampleOffset, uAudioSampleSize;
   kal_uint32 file_size;
   MP4_PARSER_CHECK_ARG(puCurrReadOffset!=NULL);

   *puCurrReadOffset = 0;
   uAudioSampleCount = 0;
   ret = MP4_PARSER_OK;

   if ((ret=MP4_GetSampleCount(pstMp4Parser, MP4_TRACK_AUDIO, &uAudioSampleCount))!=MP4_PARSER_OK)
      goto MP4_GetAudioCurrReadOffset_end;

   if (pstMp4Parser->uAudioReadSampleNo < uAudioSampleCount)
   {
      if ((ret=MP4_GetSampleOffset(pstMp4Parser, pstMp4Parser->uAudioReadSampleNo, &uAudioSampleOffset, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
         goto MP4_GetAudioCurrReadOffset_end;
      if ((ret=MP4_GetSampleSize(pstMp4Parser, pstMp4Parser->uAudioReadSampleNo, &uAudioSampleSize, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
         goto MP4_GetAudioCurrReadOffset_end;
      *puCurrReadOffset = uAudioSampleOffset + uAudioSampleSize;
   }
   else if (pstMp4Parser->uAudioReadSampleNo == uAudioSampleCount)
   {
      FSAL_Status eRet;

      eRet = FSAL_GetFileSize(pstMp4Parser->pstFSAL, &file_size);
      if(eRet != FSAL_OK){
         ret = MP4_PARSER_FILE_READ_ERROR;
         goto MP4_GetAudioCurrReadOffset_end;
      }
      *puCurrReadOffset = file_size;
   }
   else
      ret = MP4_PARSER_NO_SUCH_SAMPLE;

MP4_GetAudioCurrReadOffset_end:
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_AUDIO_GETCURREADOFFSET, pstMp4Parser->uAudioReadSampleNo, uAudioSampleCount, *puCurrReadOffset, ret);
#endif
   return ret;
}

#endif //(__M3GPMP4_FILE_FORMAT_SUPPORT__)
