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
 *   AudCom.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The header file for basic audio component
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef AUD_COMP_DOT_H
#define AUD_COMP_DOT_H

//#include "OMX_Component.h"
#include "l1audio.h"
#include "OMX_Core.h"
#include "OMX_Types.h"
#include "OMX_Index.h"

/*------------------------------------------------*/
/* Audio Component Handle and Callback            */
/*------------------------------------------------*/

typedef struct {
   OMX_U32 uSamplingFreq;
   OMX_U32 uChannelNum;
   OMX_U8  uPreSilence;
} APM_ComData;

typedef struct audCompHdl AudComHdl;

struct audCompHdl {
   OMX_ERRORTYPE (*Start)(AudComHdl *hdl);
   OMX_ERRORTYPE (*Stop)(AudComHdl *hdl);
   OMX_ERRORTYPE (*Deinit)(AudComHdl *hdl);
   OMX_ERRORTYPE (*EmptyThisBuffer)(AudComHdl *hdl, OMX_BUFFERHEADERTYPE *pBufHdr);
   OMX_ERRORTYPE (*FillThisBuffer)(AudComHdl *hdl, OMX_BUFFERHEADERTYPE *pBufHdr);
   OMX_ERRORTYPE (*Process)(AudComHdl *hdl);
   OMX_ERRORTYPE (*GetMetaData)(AudComHdl *hdl, OMX_PTR pMetaData);
   OMX_ERRORTYPE (*SetParameter)(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct);
};

typedef struct audCompCallback{
   OMX_ERRORTYPE (*EventHandler)(
      AudComHdl *hdl,
      void *pFWData,
      OMX_EVENTTYPE eEvent,
      OMX_U32 nData1,
      OMX_U32 nData2,
      void *pEventData);
   OMX_ERRORTYPE (*EmptyBufferDone)(
      AudComHdl *hdl,
      void *pFWData,
      OMX_BUFFERHEADERTYPE *pBufHdr);
   OMX_ERRORTYPE (*FillBufferDone)(
      AudComHdl *hdl,
      void *pFWData,
      OMX_BUFFERHEADERTYPE *pBufHdr);
} AudComCallback;

/*------------------------------------------------*/
/* Parameter Structure for Audio Post-Processing. */
/*------------------------------------------------*/

typedef struct {
   OMX_U32 uSamplingFreq;
   OMX_U32 uChannelNumber;
   OMX_U32 mode;
} BesLoudnessParam;

typedef struct {
   OMX_U32 uSamplingFreq;
   OMX_U32 uChannelNumber;
   OMX_S16 mag[8];
} BesEQParam;

typedef struct {
   OMX_U32 uSamplingFreq;
   OMX_U32 uChannelNumber;
   OMX_U32 mode;
} BesLiveParam;

typedef struct {
   OMX_U32 uSamplingFreq;
   OMX_U32 uChannelNumber;
   OMX_U32 mode;
} BesSurroundParam;

typedef struct {
   OMX_U32 uSamplingFreq;
   OMX_U32 uChannelNumber;
   OMX_U32 mode;
   OMX_U8  uEnabled;
} BesTSParam;

typedef struct {
   OMX_U32 uSamplingFreq;
   OMX_U32 uChannelNumber;
   OMX_U32 uFilterTap; 
   OMX_S16 *pCoeff;
} BesCFParam;

typedef struct {
   OMX_U32 uSamplingFreq;
   OMX_U32 uChannelNumber;
   OMX_U32 uAccInputSample;
   OMX_U32 uAccOutputSample;
} BesTsProcessInfo;

/*------------------------------------------------*/
/* Parameter Structure for Decoder.               */
/*------------------------------------------------*/
typedef struct {
   OMX_U32 uSamplingFreq;
   OMX_U32 uDecFrameNum;
   OMX_U8 uChannelNum;
   OMX_U8 uSbr;
   OMX_U8 uPS;
} AacDecParam;

/*------------------------------------------------*/
/* Parameter Structure for Encoder.               */
/*------------------------------------------------*/
typedef struct {
   OMX_U16 mode;
} AmrEncParam;

typedef struct {
   OMX_U8  *pHeader;
   OMX_U32 uLength;
} WavEncHeaderInfo;

/*------------------------------------------------*/
/* Parameter Structure for Source.                */
/*------------------------------------------------*/
typedef struct {
   Media_Format format;
   OMX_U32 uSamplingFreq;
   OMX_U32 uChannelNum;
} SrcParam;

typedef struct {
   // Input: Bitwise: bit0 represent 8kHz, bit8 represent 48kHz
   // 8kHz, 11kHz, 12kHz, 16kHz, 22kHz, 24kHz, 32kHz, 44kHz, 48kHz
   OMX_U16 fMonoSR;
   OMX_U16 fStereoSR;
   
   // Output
   OMX_U32 uSourceSamplingFreq;
   OMX_U32 uSourceChannelNum;
   OMX_U32 uEncodeSamplingFreq;
   OMX_U32 uEncodeChannelNum;
} SrcCapParam;

/*------------------------------------------------*/
/* Parameter Structure for Sink.                  */
/*------------------------------------------------*/
typedef struct {
   OMX_U32 uSamplingFreq;
   OMX_U32 uChannelNum;
} SinkParam;

/*------------------------------------------------*/
/* Parameter Structure for PCM Route Source.      */
/*------------------------------------------------*/
typedef struct {
   OMX_U32 assoc_fc_audi_id;
} PcmRouteSrcParam;

/*------------------------------------------------*/
/* The basic functions of Audio Component.        */
/*------------------------------------------------*/

/*------------------------------------------------*/
/* Render.                                        */
/*------------------------------------------------*/
OMX_U32 PcmRender_GetMemSize( void );

OMX_ERRORTYPE PcmRender_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For PCM render
OMX_U32 PcmSink_GetMemSize( void );
OMX_ERRORTYPE PcmSink_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback,
   OMX_U32        uSamplingRate,
   OMX_U32        uChannelNum
);

OMX_ERRORTYPE PcmSinkGen_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

kal_uint32 PcmSink_GetCurrentTime( void );

kal_uint32 AudioDrain_GetCurrentTimeFromTS( void );
OMX_ERRORTYPE AudioDrain_Check_SR_CH(kal_uint32 uSampleRate, kal_uint32 uChannelNum);

/*------------------------------------------------*/
/* Parser.                                        */
/*------------------------------------------------*/

// For DRA decoder
OMX_U32 DraDec_GetMemSize( void );
OMX_ERRORTYPE DraDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For WAV decoder
OMX_U32 WavPar_GetMemSize( void );
OMX_ERRORTYPE WavPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For DAF parser
OMX_U32 DafPar_GetMemSize( void );
OMX_ERRORTYPE DafPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);
OMX_ERRORTYPE DafParGen_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For AAC parser
OMX_U32 AacPar_GetMemSize( void );
OMX_ERRORTYPE AacPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

OMX_U32 M4aPar_GetMemSize( void );
OMX_ERRORTYPE M4aPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback,
   OMX_STRING     pURI
);

// For AMR parser
OMX_U32 AmrPar_GetMemSize( void );
OMX_ERRORTYPE AmrPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For AWB parser
OMX_U32 AwbPar_GetMemSize( void );
OMX_ERRORTYPE AwbPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For Cook parser
OMX_U32 CookPar_GetMemSize( void );
OMX_ERRORTYPE CookPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback,
   OMX_STRING     pURI
);

// For Ape parser
OMX_U32 ApePar_GetMemSize( void );
OMX_ERRORTYPE ApePar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

OMX_U32 VorbisPar_GetMemSize( void );
OMX_ERRORTYPE VorbisPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

OMX_U32 WmaPar_GetMemSize( void );
OMX_ERRORTYPE WmaPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

OMX_U32 FlacPar_GetMemSize( void );
OMX_ERRORTYPE FlacPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

OMX_U32 A2dpPar_GetMemSize( void );
OMX_ERRORTYPE A2dpPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

/*------------------------------------------------*/
/* Decoder.                                       */
/*------------------------------------------------*/

// For WAV decoder
OMX_U32 WavDec_GetMemSize( void );
OMX_ERRORTYPE WavDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For DAF decoder
OMX_U32 DafDec_GetMemSize( void );
OMX_ERRORTYPE DafDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For AAC decoder
OMX_U32 AacDec_GetMemSize( void );
OMX_ERRORTYPE AacDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For AMR decoder
OMX_U32 AmrDec_GetMemSize( void );
OMX_ERRORTYPE AmrDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For AWB decoder
OMX_U32 AwbDec_GetMemSize( void );
OMX_ERRORTYPE AwbDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For Cook decoder
OMX_U32 CookDec_GetMemSize( void );
OMX_ERRORTYPE CookDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For Ape decoder
OMX_U32 ApeDec_GetMemSize( void );
OMX_ERRORTYPE ApeDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

OMX_U32 VorbisDec_GetMemSize( void );
OMX_ERRORTYPE VorbisDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

OMX_U32 VorbisStrmDec_GetMemSize( void );
OMX_ERRORTYPE VorbisStrmDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

OMX_U32 WmaDec_GetMemSize( void );
OMX_ERRORTYPE WmaDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

OMX_U32 FlacDec_GetMemSize( void );
OMX_ERRORTYPE FlacDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

OMX_U32 SbcStrmDec_GetMemSize( void );
OMX_ERRORTYPE SbcStrmDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

/*------------------------------------------------*/
/* Post-Processing.                               */
/*------------------------------------------------*/
// BesLoudness
OMX_U32 BesLoudness_GetMemSize( void );
OMX_ERRORTYPE BesLoudness_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// BesEQ
OMX_U32 BesEQ_GetMemSize( void );
OMX_ERRORTYPE BesEQ_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// BesLive
OMX_U32 BesLive_GetMemSize( void );
OMX_ERRORTYPE BesLive_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// BesSurround
OMX_U32 BesSurround_GetMemSize( void );
OMX_ERRORTYPE BesSurround_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// BesTS
OMX_U32 BesTS_GetMemSize( void );
OMX_ERRORTYPE BesTS_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// BesLive
OMX_U32 BesCF_GetMemSize( void );
OMX_ERRORTYPE BesCF_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// Audio Post-Processing Manager
OMX_U32 APMCom_GetMemSize( void );
OMX_ERRORTYPE APMCom_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

void APM_HOOK_Sink_Handler(AudComHdl *hdl);
void APM_UNHOOK_Sink_Handler(AudComHdl *hdl);

/*------------------------------------------------*/
/* Source.                                        */
/*------------------------------------------------*/
OMX_U32 PcmSrc_GetMemSize( void );
OMX_ERRORTYPE PcmSrc_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

/*------------------------------------------------*/
/* Speech enhancement.                            */
/*------------------------------------------------*/
OMX_U32 SphEnh_GetMemSize( void );
OMX_ERRORTYPE SphEnh_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

/*------------------------------------------------*/
/* Sample Rate Convert.                           */
/*------------------------------------------------*/
OMX_U32 SRC_GetMemSize( void );
OMX_ERRORTYPE SRC_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

/*------------------------------------------------*/
/* Encoder.                                       */
/*------------------------------------------------*/
// For AMR encoder
OMX_U32 AmrEnc_GetMemSize( void );
OMX_ERRORTYPE AmrEnc_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For AMR DSP encoder
OMX_U32 AmrDspEnc_GetMemSize( void );
OMX_ERRORTYPE AmrDspEnc_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For AWB encoder
OMX_U32 AwbEnc_GetMemSize( void );
OMX_ERRORTYPE AwbEnc_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For Vorbis encoder
OMX_U32 VorbisEncComp_GetMemSize( void );
OMX_ERRORTYPE VorbisEncComp_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For Wav encoder
OMX_U32 WavEnc_GetMemSize( void );
OMX_ERRORTYPE WavEnc_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For VM DSP encoder
OMX_U32 VmDspEnc_GetMemSize( void );
OMX_ERRORTYPE VmDspEnc_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

/*------------------------------------------------*/
/* Packer.                                        */
/*------------------------------------------------*/
// For AMR packer
OMX_U32 AmrPack_GetMemSize( void );
OMX_ERRORTYPE AmrPack_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For Wav packer
OMX_U32 WavPack_GetMemSize( void );
OMX_ERRORTYPE WavPack_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

// For PCM packer
OMX_U32 PcmPack_GetMemSize( void );
OMX_ERRORTYPE PcmPack_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

/*------------------------------------------------*/
/* PCM Route source.                              */
/*------------------------------------------------*/
OMX_U32 PcmRouteSrc_GetMemSize( void );

OMX_ERRORTYPE PcmRouteSrcGen_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

OMX_ERRORTYPE PcmRouteSrc_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback,
   OMX_STRING     pURI
);

OMX_ERRORTYPE PcmRouteSrcGen_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
);

/*------------------------------------------------*/
/* Splitter/Joiner.                               */
/*------------------------------------------------*/
// Audio Mixer
OMX_U32 AudioMixer_GetMemSize(void);
OMX_ERRORTYPE AudioMixer_Init(
   AudComHdl**     ppHandle,
   void*           pBuffer,
   void*           pFWData,
   AudComCallback* pCallback
);

/*------------------------------------------------*/
/* Seek.                                          */
/*------------------------------------------------*/
void DafSeekWithResume( AudComHdl *hdl );


typedef enum {
   MTKAUD_PARSER_PCM = 100,
   MTKAUD_PARSER_WAV,
   MTKAUD_PARSER_AMR,
   MTKAUD_PARSER_AMR_WB,
   MTKAUD_PARSER_DAF,
   MTKAUD_PARSER_AAC,
   MTKAUD_PARSER_M4A,
   MTKAUD_PARSER_DRA,
   MTKAUD_PARSER_COOK,
   MTKAUD_PARSER_APE,
   MTKAUD_PARSER_VORBIS,
   MTKAUD_PARSER_VORBIS_STRM,
   MTKAUD_PARSER_WMA,
   MTKAUD_PARSER_FLAC,
   MTKAUD_PARSER_A2DP,

   MTKAUD_DECODER_PCM = 200, 
   MTKAUD_DECODER_WAV,
   MTKAUD_DECODER_AMR,
   MTKAUD_DECODER_AMR_WB,
   MTKAUD_DECODER_DAF,
   MTKAUD_DECODER_AAC,
   MTKAUD_DECODER_M4A,
   MTKAUD_DECODER_DRA,
   MTKAUD_DECODER_COOK,
   MTKAUD_DECODER_APE,
   MTKAUD_DECODER_VORBIS,
   MTKAUD_DECODER_VORBIS_STRM,
   MTKAUD_DECODER_WMA,
   MTKAUD_DECODER_FLAC,
   MTKAUD_DECODER_SBC,

   MTKAUD_PCMRUT      = 300, 
   MTKAUD_TS,
   MTKAUD_APM, 

   MTKAUD_PCMSINK     = 400, 
   MTKAUD_PCMSINK_GEN,
   
   MTKAUD_PCMSOURCE   = 800,
   
   MTKAUD_ENHANCEMENT = 900,
   
   MTKAUD_SR_CONVERT  = 1000,
   
   MTKAUD_ENCODER_WAV = 1100,
   MTKAUD_ENCODER_AMR,
   MTKAUD_ENCODER_OGG,
   MTKAUD_ENCODER_VM,
   
   MTKAUD_PACKER_PCM  = 1200,
   MTKAUD_PACKER_WAV
   
}MTKAUD_COMPONENT_LIST;

#endif
