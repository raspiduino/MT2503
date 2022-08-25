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
 *   amr_codec.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The header file of amr codec.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef AMR_CODEC_DOT_H
#define AMR_CODEC_DOT_H

#include "fsal.h"

#include "l1audio.h"
#include "amr_codec_exp.h"
#include "awb_codec_exp.h"
#include "AudComUtil.h"
#include "ast.h"

#define AMRDEC_PARSER_BUFNUM   2
#define AMRDEC_PARSER_BUFSIZE  2048
#define AMRDEC_DECODER_BUFNUM  1
#if defined(AMRWB_DECODE)
#define AMRDEC_DECODER_BUFSIZE 320 * 2 * 8
#else
#define AMRDEC_DECODER_BUFSIZE 160 * 2 * 8
#endif

#define AMR_HEADER_LENGTH 9
#define AMR_FRAME_DURATION 20000000

#define AMR_FRAME_SIZE 160
#define AWB_FRAME_SIZE 320

/*------------------------------------------------*/
/* Structure of AMR parser.                       */
/*------------------------------------------------*/
typedef struct {
   STFSAL *pstFSAL;
   AudResumeBuffer ResBuf;   
   kal_uint32 uFileSize;
   kal_uint32 uOffset;
} AMR_ParData;

/*------------------------------------------------*/
/* Structure of AMR decoder.                      */
/*------------------------------------------------*/
typedef struct {
	 kal_uint32   vm;
   kal_uint32   uFrameDur;
   kal_uint32   uSampleRate;
   kal_bool     bIsStereo;
   kal_bool     bIsWideBand;
} AMR_FrameInfo;

typedef struct {
   kal_uint32 resumeFrameOffset;
   kal_uint32 uCurrentFrameLen;
   kal_uint32 uBufferedFrameLen;
   kal_uint32 uFramePCMLen;
   kal_uint32 vm;
   // SWIP
   AMR_DEC_HANDLE *decHandle;
   AWB_DEC_HANDLE *wbDecHandle;
   void           *pAssignedBuf;
   void           *int_buf;
   void           *tmp_buf;
   void           *bs_buf;
   void           *pcm_buf;

   // DSP
   kal_uint16        Tx_ordering_buffer[30];
   kal_uint16        Tx_data_buffer[30]; 
   
   kal_uint8  uQualityBit;
   kal_uint8  uFrameType;
   kal_uint8  bCodecMode;
   kal_bool   isPageLock;
   kal_bool   bWideBand;
   kal_bool   bIsError;
   kal_bool   bUnderflow;

} AMR_DecData;

/*------------------------------------------------*/
/* Structure of AMR parser.                       */
/*------------------------------------------------*/
typedef struct {
   Media_Format format;
   
   // File information
   kal_bool fWriteHeaderDone;
   kal_bool fMedSet;
   STFSAL *pstFSAL;
   kal_uint32 uFileSize;
} AMR_PackData;

/*------------------------------------------------*/
/* Structure of AMR encoder.                      */
/*------------------------------------------------*/
#define MAX_AMR_FRAME_SIZE 61
#define AMR_SAMPLE_PER_FRAME 160

typedef struct {
   kal_uint32     uSampleRate;
   kal_uint8      uChannelNum;
   kal_bool       bWideBand;
   
   // For SWIP
   kal_uint8      mode;
   kal_uint8      *pAllocBuf;
   AMR_ENC_HANDLE *amrHandle;
   AWB_ENC_HANDLE *awbHandle;
   kal_uint8      *int_buffer;
   kal_uint8      *tmp_buffer;
   kal_uint8      *bs_buffer;
   kal_uint8      *pcm_buffer;
   kal_uint16     uPcmFrameSize;
   kal_uint16     uPcmWrite;
} AMR_EncData;

typedef struct {
   kal_uint32     aud_id;
   
   kal_uint32     uSampleRate;
   kal_uint8      uChannelNum;
   kal_bool       bWideBand;
   kal_uint8      mode;
   kal_uint8      uSilenceCount;
   
   kal_uint16     Tx_data_buffer[30];
   kal_uint16     Tx_ordering_buffer[30];
} AMR_DspEncData;

/*------------------------------------------------*/
/* Constant array.                                */
/*------------------------------------------------*/
extern const kal_uint8 amrFrameLength[16];
extern const kal_uint8 awbFrameLength[16];

OMX_ERRORTYPE AmrPar_Process_Internal(AudComHdl *hdl);
Media_Format amrChkFileHeader( STFSAL *pstFSAL, kal_uint32 *uOffset);
AST_Status amrParseFileHeader(void *hdlptr, kal_uint32 *FirstFrameOffset, kal_uint32 *uFrameDur);
AST_Status amrParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum);
kal_uint32 amrGetByteRate( STFSAL *pstFSAL , Media_Format uMediaType, kal_uint32 uOffset);

void amrEnc_WriteSilence(AudComHdl *hdl, kal_uint32 mode);

#endif
