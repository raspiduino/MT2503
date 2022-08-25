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
 *   DAF_codec.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The header file of DAF codec.
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef DAF_CODEC_DOT_H
#define DAF_CODEC_DOT_H

#include "fsal.h"
#include "media.h"

#include "AudComUtil.h"
#include "mp3_dec_exp.h"

/*------------------------------------------------*/
/* Structure of DAF parser.                       */
/*------------------------------------------------*/
// MAX search length of Frame Header Sync.
#define MAX_FRAME_CHECK_LEN    (4608)
#define MP3FrmLen_MIN_BS_SIZE  4*1024
#define MAX_CONTINUOUS_ERROR_LEN 4096
#define FILE_CACHE_BUFFER_SIZE 1024

#if defined(MT6256)
#define MP3DEC_PARSER_BUFNUM   3
#else
#define MP3DEC_PARSER_BUFNUM   2
#endif
#define MP3DEC_PARSER_BUFSIZE  8192
#define MP3DEC_DECODER_BUFNUM  1
#define MP3DEC_DECODER_BUFSIZE 4608

typedef struct {
   // File information
   kal_uint32 uOffset;
   kal_bool fMedSet;
   STFSAL stFSAL;
   STFSAL *pstFSAL;
   kal_uint32 uFileSize;
   kal_uint32 uHdrOffset;

   // Frame length information
   kal_uint16 wFrameSizeTbl[15];
   kal_uint16 wExistFrmSizeTbl[15];
   kal_uint32 wFSTblIdx;

   // Header information
   kal_uint16 wHeader1;
   kal_uint16 wHeader2;
   kal_uint32 uSampleRate;
   kal_uint64 uSamplesPerFrame;
   kal_uint64 frameDur; // in ms * 10E-6

   // File Cache Buffer
   kal_uint8 pCacheBuf[FILE_CACHE_BUFFER_SIZE];
   
   // Temp buffer for ID3 tag
   kal_uint8 pTempBuf[ID3V2_HEADER_LEN];
   
   // File handle information
   AcuFileParam stFile;

   // For streaming
   Media_Ext_DAF_strm strmInfo;

   //For Resume
   AudResumeBuffer ResBuf;
} DAF_ParData;

/*------------------------------------------------*/
/* Structure of DAF decoder.                      */
/*------------------------------------------------*/
#if defined(MT6225)
#define DAF_PAGE_NUM 0
#elif defined(MT6253T) || defined(MT6253) 
#define DAF_PAGE_NUM 1
#else
#define DAF_PAGE_NUM 2
#endif

typedef struct {
   // For SWIP
   Mp3dec_handle  *decHandle;
   void           *work1_buf;
   void           *work2_buf;
   void           *bs_buf;
   void           *pcm_buf;
   kal_uint32     aud_id_decoder;
   
   kal_uint32     w1Size;
   kal_uint32     w2Size;
   kal_uint32     bsSize;
   kal_uint32     pcmSize;
   
   // Flag
   kal_uint32     uRead;
   kal_uint32     uWrite;
   kal_uint8      errorFrame;
   kal_bool       isBsEOF;
   kal_bool       fDecoderError;
   kal_bool       fDecoderSuccess;
   kal_bool       fUnderflow;
   kal_bool       fFirstDecode;

} DAF_DecData;

/*------------------------------------------------*/
/* Function for Audio Seek Table.                 */
/*------------------------------------------------*/
#include "ast.h"

AST_Status DafParseHeader(void *ptrhdl, kal_uint32 *FirstFrameOffset, kal_uint32 *uFrameDur);
AST_Status DafParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum);

OMX_ERRORTYPE DafPar_Process_Internal(AudComHdl *hdl);

kal_bool dafIsFakeSyncWord(kal_uint16 w1, kal_uint16 w2);
kal_uint32 dafGetSamplingRate(kal_uint32 MPEGver, kal_uint32 srIdx);
kal_bool MP3FrmLen_GetFrmLenTableInternal(
   kal_int16 frameLengthTable[15], /* [Output] the frame length table        */
   kal_int32 *firstFHPosition,     /* [Output] If the return value is 1, it is the position of the first valid frame header (in bytes).
                                            Else, it means the size of garbage data in the input Bitstream buffer (in bytes) */
   const kal_uint8 *pBS_BUF,       /* [Input] bitstream buffer base address  */
   kal_int32  uBS_BUF_Size,        /* [Input] bitstream buffer size          */
   const kal_uint8* pBS_Read);     /* [Input] bitstream buffer read pointer  */

#endif
