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
 *   The header file for audio component utility function. (Internal Use)
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

#ifndef AUD_COMP_UTIL_DOT_H
#define AUD_COMP_UTIL_DOT_H

#include "AudCom.h"
#include "MedAdapt.h"
#include "l1audio.h"
#include "fsal.h"
#include "ast.h"
#include "OMX_Types.h"
#include "OMX_Core.h"

// Must be power of 2
#if defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)    
#define BUFQSIZE 32
#else
#define BUFQSIZE 16
#endif

/*------------------------------------------------*/
/* For resume operation.                          */
/*------------------------------------------------*/

typedef struct {
   kal_uint32    uOffset[2];
   kal_uint32    uFrame[2];
   kal_uint8     uIndex;
} AudResumeBuffer;

/*------------------------------------------------*/
/* For seek operation.                            */
/*------------------------------------------------*/

typedef struct {
   kal_uint32 msStartTime;
   kal_uint32 msStopTime;
   AudioSeekTable *AudioSeekTbl;
} AudSeekInfo;


typedef struct {
   OMX_U32              read;
   OMX_U32              write;
   OMX_BUFFERHEADERTYPE *element[BUFQSIZE];
   OMX_BUFFERHEADERTYPE *pCurBufHdr;
} BufferQueue;

typedef struct {
   kal_uint32 uSampleFreq;
   kal_uint32 uChannel;
} PcmBufferInfo;

typedef struct {
   kal_uint32 uFrameDur; //nsec
   kal_uint32 uCurrentFrame;
   kal_uint32 uCurrentOffset;
   AudResumeBuffer *pResBuf;
} BsBufferInfo;


typedef struct {
   // The basic function, MUST put at first
   AudComHdl basic;
   
   // The basic information
   AudComCallback *callbacks;
   void *pFWData;
   void *pPrivateData;

   // Buffer Header Queue
   BufferQueue InputQ;
   BufferQueue OutputQ;

   // DSP buffer information
   kal_uint16 dsp_rb_base;
   kal_uint16 dsp_rb_size;
   kal_uint16 dsp_rb_end;
   
   // Status of component
   kal_uint8 aud_id;
   kal_uint8 aud_id_decoder;
   Media_Format mediaType;
   kal_uint8 mediaStatus;
   kal_uint8 endStatus;
   kal_uint8 dspStatus;
   kal_uint32 data;
   
   // Stream information
   kal_bool isEOF;
   kal_bool Decode_EOF;
   kal_bool isTimeUP;
   kal_bool isDspDecodeEOF;
   kal_bool isHookDecHISR;
   kal_bool isAUDLP;
   kal_bool isEOFSet;
   kal_bool isProcessDone;
   
   // DSP information
   kal_uint16 errorReport;
   kal_uint16 wDspReadIdx;
   kal_uint16 DSP_Write_Idx;
   kal_int32 DSP_Data_Cnt;
   
   // Media Handle
   MHdl *mhdl;
   
   // PCM information
   PcmBufferInfo pcmInfo;

   // PCM information
   BsBufferInfo bsInfo;
} AudComHdlInt;

#define COMPONENT_STATE_NONE         0
#define COMPONENT_STATE_PLAY         1
#define COMPONENT_STATE_RECORD       1
#define COMPONENT_STATE_PAUSE        2
#define COMPONENT_STATE_IDLE         3
#define COMPONENT_STATE_READY        4
#define COMPONENT_STATE_READY_SET    5
#define COMPONENT_STATE_TERMINATE    6

typedef enum {
   MEDIA_BUFFER_SUCCESS,
   MEDIA_BUFFER_EOF,
   MEDIA_BUFFER_NOT_READY
} Media_BufferEvent;


/*------------------------------------------------*/
/* Initialization of ACU.                         */
/*------------------------------------------------*/
void ACU_Init( void );

/*------------------------------------------------*/
/* The utility functions for audio component.     */
/*------------------------------------------------*/

// Queue operation
void ACU_Queue_Init(BufferQueue *queue);
void ACU_Queue_Enqueue(BufferQueue *queue, OMX_BUFFERHEADERTYPE *pBufHdr);
OMX_BUFFERHEADERTYPE *ACU_Queue_Dequeue(BufferQueue *queue);
OMX_BUFFERHEADERTYPE *ACU_Queue_Peek(BufferQueue *queue);
OMX_U32 ACU_Queue_Count(BufferQueue *queue);
OMX_BOOL ACU_Queue_IsFull(BufferQueue *queue);
kal_bool ACU_IsFlushed(void);

OMX_BUFFERHEADERTYPE *ACU_GetBufferHeader(AudComHdl *hdl, OMX_U32 dir);
void ACU_FlushBufferQueue(AudComHdl *hdl);
Media_BufferEvent ACU_PeekByte(AudComHdl *hdl, kal_uint8 *uData);
OMX_U32 ACU_PeekDataCount(AudComHdl *hdl);
OMX_U32 ACU_PeekSpaceCount(AudComHdl *hdl);
OMX_U32 ACU_PeekFreeCount(AudComHdl *hdl);
OMX_BOOL ACU_PeekIsEOS(AudComHdl *hd);
void ACU_PeekNBytes(AudComHdl *hdl, OMX_U8 *pBufDest, OMX_U32 uLenDest);
void ACU_PeekNByteDone(AudComHdl *hdl, OMX_U32 uLenDest);

// Handle initialization/de-init
OMX_ERRORTYPE ACU_InitHdl(AudComHdl *hdl, void *pFWData, AudComCallback *pCallback);
OMX_ERRORTYPE ACU_ParGenStop(AudComHdl *hdl);
OMX_ERRORTYPE ACU_GenDeinit(AudComHdl *hdl);

// Buffer operation
void ACU_GetReadBuffer(AudComHdl *hdl, OMX_U8 **buffer, OMX_U32 *uLen);
void ACU_ReadDataDone(AudComHdl *hdl, OMX_U32 uLen);
void ACU_GetWriteBuffer(AudComHdl *hdl, OMX_U8 **buffer, OMX_U32 *uLen);
void ACU_WriteDataDone(AudComHdl *hdl, OMX_U32 uLen);
void ACU_WriteDataDone_ImmediateCallback(AudComHdl *hdl, OMX_U32 uLen);
void ACU_GetWriteBuffer_Threshold(AudComHdl *hdl, OMX_U8 **buffer, OMX_U32 *uLen, OMX_U32 uThreshold);
void ACU_GetNBytes(AudComHdl *hdl, OMX_U8 *pBufDest, OMX_U32 uLenDest);

// DSP data operation
void ACU_WriteDataToDSP(
   AudComHdl *hdl,
   kal_uint16 *dspWritePtr,
   kal_uint16 *dspReadPtr,
   kal_uint32 pageNum
);
OMX_ERRORTYPE ACU_DSPDecoderProcess(AudComHdl *hdl);
void ACU_DSPEofHandler(AudComHdlInt *ihdl);

// Set EOS
void ACU_SetEOS(AudComHdl *hdl);

// Send command to l1audio task
void ACU_SendCommand(AudComHdlInt *ihdl, OMX_U32 type, OMX_U32 event, OMX_U32 data1, OMX_U32 data2, void *pData);
void ACU_SendProcessCommandl(AudComHdlInt *ihdl);
void ACU_SendEndCommandl(MHPB_Internal *ihdl);
void ACU_SendProcessDoneCommandl(AudComHdlInt *ihdl);
/*------------------------------------------------*/
/* PCM route service.                             */
/*------------------------------------------------*/
void PcmRut_GetInfo( kal_uint32 *numSample_get, kal_uint32 *numSample_put);
void PcmRut_GetData( kal_uint16 *pSampleBuf);
void PcmRut_PutData( kal_uint16 *pSampleBuf );
void PcmRut_PutData_Silence( void );
void PcmRut_Start( void (*PcmRutHisrHandler)(void) );
void PcmRut_Stop( void );

void PcmRut_RegGetComponent(AudComHdl *hdl);
void PcmRut_UnregGetComponent(AudComHdl *hdl);
void PcmRut_RegPutComponent(AudComHdl *hdl);
void PcmRut_UnregPutComponent(AudComHdl *hdl);

/* Internal use for application */
void PcmRut_HookedHisrHander( void );

void APM_Hook_PcmRut(void);
void MH_FlushPostProcess(AudComHdl *hdlSink);
void MH_RegPutComponent(AudComHdl *hdlDec);
void MH_UnregPutComponent(AudComHdl *hdlDec);

/*------------------------------------------------*/
/* The utility functions for file operation.      */
/*------------------------------------------------*/
#define FILE_CACHE_BUFFER_SIZE 1024

OMX_ERRORTYPE ACU_FileOpenForRead(STFSAL *pstFSAL, kal_char *pPath, kal_uint8 *pCacheBuf);
OMX_ERRORTYPE ACU_FileOpenForWrite(STFSAL *pstFSAL, kal_char *pPath, kal_uint8 *pCacheBuf);
OMX_ERRORTYPE ACU_FileRead(AudComHdl *hdl, STFSAL *pstFSAL, kal_uint32 *uOffset);
OMX_ERRORTYPE ACU_FileReadGeneral(AudComHdl *hdl, STFSAL *pstFSAL, kal_uint32 *uOffset, kal_uint32 uBoundary);
OMX_ERRORTYPE ACU_FileWrite(AudComHdl *hdl, STFSAL *pstFSAL, kal_uint32 *length);
OMX_ERRORTYPE ACU_GetBytesFromFile(STFSAL *pstFSAL, kal_uint32 *uOffset, kal_uint32 *num_bytes, kal_uint8 *ptr);
OMX_ERRORTYPE ACU_PutToBuffer(AudComHdl *hdl, kal_uint8 *pSrcBuf, kal_uint32 *ulength);
OMX_ERRORTYPE ACU_PutToBuffer_Threshold(AudComHdl *hdl, kal_uint8 *pSrcBuf, kal_uint32 *ulength, kal_uint32 uThreshold);
void ACU_SkipID3Tag(STFSAL *pstFSAL, kal_uint32 *fileOffset, kal_uint8 *ptr);


/*------------------------------------------------*/
/* Operate the linked list of audio component.    */
/*------------------------------------------------*/


/*------------------------------------------------*/
/* Function for Audio Seek Table.                 */
/*------------------------------------------------*/
void AudAstBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress, kal_bool fLimitFrameNumber);
kal_uint32 AudAstGetCacheDur(MHdl *hdl);
kal_uint32 AudAstGetTotalDuration( MHdl *hdl );
void DafAstSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, void *param );
kal_bool DafSeek(AudComHdl *hdl, kal_bool fCacheEnable);

void ACU_SetResumePoint(AudResumeBuffer *pResBuf, kal_uint32 uOffset, kal_uint32 uFrameNum);
void ACU_GetResumePoint(AudResumeBuffer *pResBuf, kal_uint32 *uOffset, kal_uint32 *uFrameNum);
void ACU_LoadResumeInfo(AudComHdl *hdl);

#endif
