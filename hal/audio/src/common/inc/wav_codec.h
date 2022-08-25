/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   WAV_codec.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The header file of WAV codec.
 *
 * Author:
 * -------
 * -------
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef AAC_CODEC_DOT_H
#define AAC_CODEC_DOT_H

#include "wav_codec_exp.h"

/*********************************************/
/* Decoder Part                              */
/*********************************************/

#define WAVPAR_MAX_DATA_SEARCH_TIME 20

#define WAVDEC_MAX_GAIN        100

#define WAVDEC_BS_SIZE         512
#define WAVDEC_BS_BUFFER_SIZE  2048

#define WAVDEC_PARSER_BUFNUM   8
#define WAVDEC_PARSER_BUFSIZE  2048
#define WAVDEC_PARSER_RENDER_BUFNUM   2
#define WAVDEC_PARSER_RENDER_BUFSIZE  2048

#define WAVDEC_DECODER_BUFNUM  1
#define WAVDEC_DECODER_BUFSIZE WAVDEC_BS_SIZE*4

#define WAVDEC_RAMPDOWN_START_GAIN     0x7F00
#define WAVDEC_RAMPDOWN_SPEED          0x100

typedef struct {
   //For seek
   AudSeekInfo stSeekInfo;

   // File information
   kal_bool bIsDraStreaming;
   kal_bool bIsPCMStreaming;
      
   STFSAL stFSAL;
   STFSAL *pstFSAL;
   kal_uint32 uFileSize;
   kal_uint32 uOffset;
   kal_uint32 uTotalDecSamples;
   // File Cache Buffer
   
   kal_uint8  *pWorkBuf;
   kal_uint32 uWorkBufSize;
   kal_uint8  *pBsBuf;
   kal_uint32 uBsBufSize;
   kal_uint32 uBsBufRead;
   kal_uint32 uBsBufDataLen;
   WAV_DEC_HDL *pDecHdl;
   PCM_PARAM  pcmInfo;     
   AudResumeBuffer ResBuf;
   kal_uint32 uEOSOffset;
} WAV_ParData;


typedef struct {
   //For seek
   AudSeekInfo stSeekInfo;

   STFSAL *pstFSAL;
   kal_uint32 uFileSize;
   kal_uint32 uOffset;
   kal_uint32 uTotalDecSamples;
   
   kal_uint8  *pWorkBuf;
   kal_uint8  *pBsBuf;
   kal_uint32 uBsBufSize;
   kal_uint32 uBsBufRead;
   kal_uint32 uBsBufDataLen;

   kal_uint32 uPostSilenceCnt;
   WAV_DEC_HDL *pDecHdl;
   kal_uint32 uStartTime;
   kal_uint32 uCurrentTime;
   kal_uint8  uGain;
   kal_bool   bPostSilence;
   kal_bool   bEnableFillSilence;
   kal_bool   isPageLock;
   kal_int16  iLastSample_L;
   kal_int16  iLastSample_R;
   kal_uint16 uRampDownGain;
} WAV_DecData;

typedef struct {
   WAV_DEC_HDL *pDecHdl;
} WAV_Par2DecInfo;


typedef struct {
   WAV_FORMAT     format;
   kal_uint32     uDataChunkOffset;
   kal_uint32     uDataLength;
   kal_uint32     uBitRate;
   kal_uint32     uTotalDuration; //ms
   kal_uint16     uSampleRate;
   kal_uint8      uCilentType;
   kal_uint8      uChannelNum;
   kal_uint8      uBitPerSample;
   kal_bool       fUseRender;
   kal_bool       fDelayStop;
} WAV_FileInfo;

OMX_ERRORTYPE WavPar_Process_internal(AudComHdl *hdl);
void wavPageLock( AudComHdl *hdl , kal_bool bLock);


/*********************************************/
/* Encoder Part                              */
/*********************************************/
#define WAV_ENC_PAC_BUFFER_SIZE  256

typedef struct {
   WAV_FORMAT     format;
   kal_uint32     uDataLength;
   kal_uint32     uTotalDuration; //ms
   kal_uint32     uSampleRate;
   kal_uint32     uChannelNum;
   kal_uint32     uPcmPosition;
   
   // SWIP
   void           *pAllocBuf;
   WAV_ENC_HDL    *pHdl;
   void           *pcm_buffer;
   void           *bs_buffer;
   void           *int_buffer;
   kal_uint32     uPcmBufSize;
   kal_uint32     uBsBufSize;
   kal_uint32     uIntBufSize;   
} Wav_EncData;


#endif
