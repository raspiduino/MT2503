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
 *   MedAdapt.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The header file for MED adaptation
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef AUD_COMP_ADAPT_DOT_H
#define AUD_COMP_ADAPT_DOT_H

#include "fsal.h"

#include "l1audio.h"
#include "OMX_Types.h"
#include "OMX_Core.h"
#include "AudCom.h"
#include "PcmSource.h"
#include "ast.h"
#include "dpmgr.h"


/*------------------------------------------------*/
/* Definition for component-based recording.      */
/*------------------------------------------------*/
#define COMPONENT_SOURCE_REQUIRED       (1)
#define COMPONENT_ENHANCEMENT_REQUIRED  (2)
#define COMPONENT_ENCODER_DSP_REQUIRED  (8)

/*------------------------------------------------*/
/* Buffer requirement for component.              */
/*------------------------------------------------*/
#define BITSTREAM_SIZE 4096
#define PARSER_OUTPUT_BUFFERHEADER_NUMBER 2

#define DECODED_PCM_BUFFER_SIZE 4608
#define DECODER_OUTPUT_BUFFERHEADER_NUMBER 4

#define PP_OUTPUT_BUFFER_SIZE 4608
#define PP_OUTPUT_BUFFERHEADER_NUMBER 4

/*------------------------------------------------*/
/* Parameter Structure for parser used by MED.    */
/*------------------------------------------------*/
// The parameter for parser
typedef struct {
   STFSAL *pstFSAL;
   void                   *pFileInfo;
} AcuFileParam;

typedef struct {
   STFSAL *pstFSAL;
   void                   *pFileInfo;
} AcuParseParam;

// Linked list of component handle and node
typedef struct acu_hdl_node AcHdlNode;

struct acu_hdl_node {
   AudComHdl *curHdl;
   void      *pBuffer;
   AudComHdl *prev;
   AudComHdl *next;
   AcHdlNode *pPrevNode;
   AcHdlNode *pNextNode;
   kal_uint8 *pAllocBuf;
};

// The structure of internal playback handle

#define MAX_COMPONENT_LIST_SIZE 5

typedef struct {
   OMX_U32 (*ParGetMemSize)( void );
   OMX_ERRORTYPE (*ParInit)(
      AudComHdl      **pHandle,
      void           *pBuffer,
      void           *pFWData,
      AudComCallback *pCallback,
      OMX_STRING     pURI);
   
   OMX_U32 (*DecGetMemSize)( void );
   OMX_ERRORTYPE (*DecInit)(
      AudComHdl      **pHandle,
      void           *pBuffer,
      void           *pFWData,
      AudComCallback *pCallback);

   OMX_U32 (*PPGetMemSize)( void );
   OMX_ERRORTYPE (*PPInit)(
      AudComHdl      **pHandle,
      void           *pBuffer,
      void           *pFWData,
      AudComCallback *pCallback);
   
   OMX_U32 (*SinkGetMemSize)( void );
   OMX_ERRORTYPE (*SinkInit)(
      AudComHdl      **pHandle,
      void           *pBuffer,
      void           *pFWData,
      AudComCallback *pCallback,
      OMX_U32        uSamplingRate,
      OMX_U32        uChannelNum);
   
   // For seek table to parse header and frame
   AST_Status (*ParseHeader)(void *ptrhdl, kal_uint32 *FirstFrameOffset);
   AST_Status (*ParseFrame)(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum);
   
} MHPB_Func;

// The structure of internal hooked component
typedef struct {
   OMX_U32 (*GetMemSize)( void );
   OMX_ERRORTYPE (*Init)(
      AudComHdl      **pHandle,
      void           *pBuffer,
      void           *pFWData,
      AudComCallback *pCallback);
   OMX_U32 OutputBufferSize;
   OMX_U32 OutputBufferNum;
} MHPB_CompList;

typedef struct {
   MHdl  mh;

   void *pAllocBuf;
   AcHdlNode ParNode;
   AcHdlNode DecNode;

   void *pAudioDrainAllocBuf;
   AcHdlNode APMNode;
   AcHdlNode TSNode;
   AcHdlNode SinkNode;
   AcHdlNode RouteNode;

   OMX_U32 numComp;
   AcHdlNode NodeArray[MAX_COMPONENT_LIST_SIZE];

   // For seek table
   AudioSeekTable *AudioSeekTbl;
   STFSAL         *pstFSAL;
   kal_uint32 uGetDurProgress;
   kal_uint32 uFileSize;
   kal_uint32 uOffset;
   kal_uint32 frameDur;
   kal_bool   endflag;
   kal_bool   fIspAllocBufOnMED;
   DPMGR_Region region;
   AST_Status (*ParseHeader)(void *ptrhdl, kal_uint32 *FirstFrameOffset, kal_uint32 *uFrameDuration);
   AST_Status (*ParseFrame)(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum);
   // public info for cilent
   void *pPublicInfo;

#if defined(__AUDIO_RECORD_DYNAMIC_HOOK_SUPPORT__)
   // Component-based recording
   kal_bool  fNodeUsed[MAX_COMPONENT_LIST_SIZE];
   kal_bool  fDspEncode;
   MHPB_CompList const *pSwEncFunc;
   MHPB_CompList const *pDspEncFunc;
   kal_uint32 (*EncDecision)(void);
   Pcm_SourceFormat stFormat;
   
   // For linked list
   AcHdlNode *pNodeStart;
   AcHdlNode *pNodeEnd;
   
   AcHdlNode *pNodeSource;
   AcHdlNode *pNodeSphEnh;
   AcHdlNode *pNodeSRC;
   AcHdlNode *pNodeEncode;
   AcHdlNode *pNodePack;
#endif

} MHPB_Internal;

/*------------------------------------------------*/
/* Export function for adaptation.                */
/*------------------------------------------------*/
MHdl *MH_Playback_Open(
   void(*handler)( MHdl *handle, Media_Event event ),
   STFSAL *pstFSAL,
   MHPB_Func *pFuncs);

MHdl *MH_Component_List_Open(
   void(*handler)( MHdl *handle, Media_Event event ),
   STFSAL *pstFSAL,
   MHPB_CompList const *pFunc[]);

MHdl *MH_Component_Open(
   void(*handler)( MHdl *handle, Media_Event event ),
   STFSAL *pstFSAL,
   MHPB_CompList const *pParFunc,
   MHPB_CompList const *pDecFunc);

MHdl *MH_Rec_Component_Open(
   void(*handler)( MHdl *handle, Media_Event event ),
   MHPB_CompList const *pEncFunc,
   MHPB_CompList const *pPackFunc);

MHdl *MH_Rec_Direct_Open(
   void(*handler)( MHdl *handle, Media_Event event ),
   MHPB_CompList const *pEncFunc,
   MHPB_CompList const *pPackFunc);

Media_Status GenCompStop( MHdl *hdl );

void BesTS_SetHandle(AudComHdl *pCurHdl);
void BesTS_SetAudioHandle(AudComHdl *pCurHdl, kal_uint32 uSampleRate, kal_uint32 uChannelNum);
void BesTS_FreeAudioHandle(void);
void AudioDrain_SetTSParam(void);
OMX_ERRORTYPE AudioDrain_Free(MHPB_Internal *ihdl);
OMX_ERRORTYPE AudioDrain_Stop(MHPB_Internal *ihdl);
OMX_ERRORTYPE AudioDrain_Start(MHPB_Internal *ihdl, kal_uint32 uSampleRate, kal_uint32 uChannelNum);
AudComHdl* AudioDrain_Init(MHPB_Internal *ihdl, AudComHdl *PrevHdl);
OMX_ERRORTYPE AudioRoute2Drain_Init(MHPB_Internal **ihdl, kal_uint16 fc_aud_id);
OMX_ERRORTYPE AudioRoute2Drain_Start(MHPB_Internal *ihdl);
OMX_ERRORTYPE AudioRoute2Drain_Stop(MHPB_Internal *ihdl);
OMX_ERRORTYPE AudioRoute2Drain_Free(MHPB_Internal *ihdl);
extern AudComCallback AudComGenCallbacks;
void DummyHisr_AudioV2( void *data);

/*------------------------------------------------*/
/* Export function for adaptation.                */
/*------------------------------------------------*/
extern const MHPB_CompList DirectPackFunc;

#endif
