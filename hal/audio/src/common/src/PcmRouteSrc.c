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
 *   pcmRouteSrc.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The source component of PCM Route.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "l1audio.h"
#include "audio_enum.h"
#include "audio_def.h"
#include "OMX_Index.h"
#include "kal_trace.h"
#include "OMX_Types.h"
#include "AudCom.h"
#include "OMX_Core.h"
#include "common_def.h"
                     
#if APM_SUPPORT

#include <string.h>
#include "AudComUtil.h"
#include "PcmSource.h"
#include "l1sp_trc.h"

extern kal_bool Is_PutPcmrutOn(void);

static void PcmRouteSrc_OpenDevice(AudComHdlInt *ihdl)
{
   // Hook PCM Route, for I2S usage
   PcmRut_RegGetComponent( (AudComHdl *)ihdl );
   APM_Hook_PcmRut();

   ihdl->endStatus = MEDIA_NONE;
   ihdl->mediaStatus = COMPONENT_STATE_PLAY;
}

static void PcmRouteSrc_CloseDevice(AudComHdlInt *ihdl)
{
   // Unhook PCM Route
   if(Is_PutPcmrutOn())
      PcmRut_Stop();
   PcmRut_UnregGetComponent( (AudComHdl *)ihdl );
}


/*-----------------------------------------------------*/
/* The private member functions of PCM Route Source.   */
/*-----------------------------------------------------*/

static OMX_ERRORTYPE PcmRouteSrc_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) {
      return OMX_ErrorIncorrectStateOperation;
   }

   // Initialize memory
   pBufHdr = ACU_GetBufferHeader( hdl, 1 );
   if (pBufHdr == NULL) {
      // Input bitstream should be ready.
      return OMX_ErrorUndefined;
   }
   ihdl->isDspDecodeEOF =KAL_FALSE;
   PcmRouteSrc_OpenDevice(ihdl);

   return OMX_ErrorNone;
}

static OMX_ERRORTYPE PcmRouteSrc_Stop(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) {
      ihdl->mediaStatus = COMPONENT_STATE_IDLE;
      ihdl->endStatus = MEDIA_TERMINATED;
   } else {
      // Avoid re-entrance
      return OMX_ErrorNone;
   }
   
   PcmRouteSrc_CloseDevice(ihdl);
   
   kal_trace( TRACE_FUNC, L1AUDIO_STOP, ihdl->mediaType );

   return OMX_ErrorNone;
}


static OMX_ERRORTYPE PcmRouteSrc_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   switch (index) {
      case OMX_IndexParamMediaTekGetPCMInfo:
         {
            SinkParam *pParam = (SinkParam *)pStruct;
#if defined(__I2S_INPUT_MODE_SUPPORT__)
            extern kal_uint16 i2s_sample_rate;
            pParam->uSamplingFreq = i2s_sample_rate;
            pParam->uChannelNum   = 2;
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PCMRUT, 3, pParam->uSamplingFreq, pParam->uChannelNum,0,0,0,0);
#endif
         }
         break;
      default:
         return OMX_ErrorNotImplemented;
   }

   return OMX_ErrorNone;
}


/*------------------------------------------------*/
/* The public functions of PCM Route Source.      */
/*------------------------------------------------*/
OMX_U32 PcmRouteSrc_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;

   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for DAF private data
   uTempSize = (sizeof(PcmRut_SrcData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   return uReqSizeTotal;
}

OMX_ERRORTYPE PcmRouteSrcGen_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   OMX_U32 uBufSize;
   AudComHdlInt *ihdl;
   kal_uint8 *pBuffer8;
   
   *pHandle = NULL;
   
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   
   // Empty the memory
   uBufSize = PcmRouteSrc_GetMemSize();
   memset(pBuffer, 0, uBufSize);
   
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   ihdl->pPrivateData = (void *)pBuffer8;
   
   ihdl->mediaType = MEDIA_FORMAT_WAV;
   
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   ihdl->basic.Start = PcmRouteSrc_Start;
   ihdl->basic.Stop = PcmRouteSrc_Stop;
   ihdl->basic.SetParameter = PcmRouteSrc_SetParameter;
   ihdl->basic.Deinit = ACU_GenDeinit;
   
   {
      PcmRut_SrcData *pSrcData;
      
      pSrcData = (PcmRut_SrcData *)ihdl->pPrivateData;
      pSrcData->assoc_fc_aud_id = 0xFFFF;
   }
   
   return OMX_ErrorNone;
}

#endif
