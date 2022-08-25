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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  BT_SCO_app.c
 *
 * Project:
 * --------
 *  Maui_sw
 *
 * Description:
 * ------------
 *  BT SCO application
 *
 * Author:
 * -------
 * -------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__CVSD_CODEC_SUPPORT__) 

#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "l1audio.h"
#include "speech_def.h"
#include "media.h"
#include "audio_enum.h"
#include "l1sp_trc.h"
#include "bt_sco_drv.h"
#include "bt_sco_app.h"
#include "pcm4way.h"
#include "pcmsink.h"
#include "audio_def.h"
#include "am.h"
#include "audcoeff_default.h"

static struct {
   kal_uint16      uSampleRate;
   kal_uint8       uChannelNumber;
   BT_SCO_APP_MODE uAppMode;
   P2W_App_Type    uP2WType;
   DACA_APP_TYPE   uDACAType;
   kal_bool        fDisableBessound;
} BT_SCO_APP;

//=============================================================================================
//    Speech Path common
//=============================================================================================

static void btsco_SpeechPath_ON(BT_SCO_APP_MODE uAppMode)
{
   BT_SCO_NB_SPEECH *pSpStruct = (BT_SCO_NB_SPEECH *)audio_alloc_mem_cacheable(sizeof(BT_SCO_NB_SPEECH));    
   pSpStruct->uAppMode = uAppMode;
   BT_SCO_Open(BT_SCO_MODE_CVSD, BT_SCO_LINK_BOTH);
   BT_SCO_SetCallback_TX(NULL, (void *)pSpStruct, 8000, 1, SPEECH_TX_FILTER);
   BT_SCO_SetCallback_RX(NULL, (void *)pSpStruct, 8000, 1, SPEECH_RX_FILTER, SPEECH_RX_PLC);
   BT_SCO_Start();
}

static void btscio_SpeechPath_OFF()
{
   BT_SCO_NB_SPEECH *pSpStruct;
   pSpStruct = (BT_SCO_NB_SPEECH*)BT_SCO_GetUserData(BT_SCO_LINK_TX_ONLY);
   BT_SCO_Stop();
   audio_free_mem( (void **) &pSpStruct);
   BT_SCO_Close();
}

//=============================================================================================
//    Loopback Path
//=============================================================================================

#if defined(__CVSD_LOOPBACK_TEST__)
static void BT_SCO_Loopback_Callback( void *pData )
{
   kal_uint8 *pInBuf, *pOutBuf; 
   kal_uint32 uInLen, uOutLen, i;
   if(BT_SCO_APP.uAppMode != BT_SCO_APP_MODE_LOOPBACK)
   {
      return;
   }
   for(i=0;i<4;i++)
   {
      kal_uint8 *pInBuf, *pOutBuf; 
      kal_uint32 uInLen, uOutLen;
      BT_SCO_GetReadBuffer_RX(&pInBuf, &uInLen);  
      BT_SCO_GetWriteBuffer_TX(&pOutBuf, &uOutLen);  
      uInLen  &= 0xFFFFFFFE;
      uOutLen &= 0xFFFFFFFE;
      kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_AUDIO_ZERO, uInLen, uOutLen, 0);
      if(uInLen < uOutLen)
      {
         uOutLen = uInLen;
      }
      memcpy( pOutBuf, pInBuf, uOutLen );
      BT_SCO_WriteDataDone_TX(uOutLen);  
      BT_SCO_ReadDataDone_RX(uOutLen);  
   }
}

void BT_SCO_LoopbackPath_ON()
{
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_ON);
   BT_SCO_Disable_All_APP();
   BT_SCO_Open(BT_SCO_MODE_CVSD, BT_SCO_LINK_BOTH);
   BT_SCO_SetCallback_TX(BT_SCO_Loopback_Callback, NULL, 8000, 1, 0);
   BT_SCO_SetCallback_RX(BT_SCO_Loopback_Callback, NULL, 8000, 1, 0, SPEECH_RX_PLC);
   BT_SCO_Start();
   BT_SCO_APP.uAppMode = BT_SCO_APP_MODE_LOOPBACK;
}

static void BT_SCO_LoopbackPath_OFF()
{
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_OFF);
   BT_SCO_Stop();
   BT_SCO_Close();
   BT_SCO_APP.uAppMode = BT_SCO_APP_MODE_DISABLE;
}
#endif

void BT_SCO_Speech_TX_HISR()
{
   kal_uint8 *pDst, *pSrc;
   kal_uint32 uOutByte, uFreeSpace, uRemainByte;
   BT_SCO_NB_SPEECH *pSpStruct;
   pSpStruct = (BT_SCO_NB_SPEECH*)BT_SCO_GetUserData(BT_SCO_LINK_TX_ONLY);
   BT_SCO_GetWriteBuffer_TX(&pDst, &uOutByte);
   uFreeSpace = BT_SCO_GetFreeSpace_TX();
   kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_TX_DATA, uOutByte, uFreeSpace);
   uOutByte = BT_SCO_CheckByte(BT_SCO_LINK_TX_ONLY, uOutByte);
   uFreeSpace = BT_SCO_CheckByte(BT_SCO_LINK_TX_ONLY, uFreeSpace);

   if(uOutByte >= NB_SPEECH_FRAME_SIZE)
   {
      pSrc = pDst;
   }
   else if(uFreeSpace >= NB_SPEECH_FRAME_SIZE)
   {
      pSrc = pSpStruct->ULBuf;
   }
   else
   { 
      kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_TX_OF, uFreeSpace);
      //overflow
      return;
   }

   if(pSpStruct->uAppMode == BT_SCO_APP_MODE_CORDLESS)
   {
      PCM2WAY_GetFromMic((kal_uint16*)pSrc);
   }
   else
   {
      DACA_GetFromSD((kal_uint16*)pSrc);
   }

   if(uOutByte >= NB_SPEECH_FRAME_SIZE)
   {
      BT_SCO_WriteDataDone_TX(NB_SPEECH_FRAME_SIZE);
   }
   else
   {//put to temp buffer first
      memcpy(pDst, pSrc, uOutByte);
      BT_SCO_WriteDataDone_TX(uOutByte);
      pSrc += uOutByte;
      uRemainByte = NB_SPEECH_FRAME_SIZE - uOutByte;
      BT_SCO_GetWriteBuffer_TX(&pDst, &uOutByte);
      uOutByte = BT_SCO_CheckByte(BT_SCO_LINK_TX_ONLY, uOutByte);
      ASSERT(uOutByte>=uRemainByte);
      memcpy(pDst, pSrc, uRemainByte);
      BT_SCO_WriteDataDone_TX(uRemainByte); 
   }
}

void BT_SCO_Speech_RX_HISR()
{
   kal_uint8 *pSrc, *pDst;
   kal_uint32 uInByte, uDataCount, uRemainByte, uDirectCopy=0;
   BT_SCO_NB_SPEECH *pSpStruct;
   pSpStruct = (BT_SCO_NB_SPEECH*)BT_SCO_GetUserData(BT_SCO_LINK_RX_ONLY);
   BT_SCO_GetReadBuffer_RX(&pSrc, &uInByte);
   uDataCount = BT_SCO_GetDataCount_RX();
   kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_RX_DATA, uInByte, uDataCount);
   uInByte = BT_SCO_CheckByte(BT_SCO_LINK_RX_ONLY, uInByte);
   uDataCount = BT_SCO_CheckByte(BT_SCO_LINK_RX_ONLY, uDataCount);
   if(uInByte >= NB_SPEECH_FRAME_SIZE)
   {
      uDirectCopy = 1;
   }
   else if(uDataCount >= NB_SPEECH_FRAME_SIZE)
   {
      pDst = pSpStruct->DLBuf;
      memcpy(pDst, pSrc, uInByte);
      pDst += uInByte;
      uRemainByte = NB_SPEECH_FRAME_SIZE - uInByte;
      BT_SCO_ReadDataDone_RX(uInByte);
      BT_SCO_GetReadBuffer_RX(&pSrc, &uInByte);
      ASSERT(uInByte>=uRemainByte);
      memcpy(pDst, pSrc, uRemainByte);
      BT_SCO_ReadDataDone_RX(uRemainByte);
      pSrc = pSpStruct->DLBuf;
   }
   else
   { 
      kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_RX_UF, uDataCount);
      return;
   }

   if(pSpStruct->uAppMode == BT_SCO_APP_MODE_CORDLESS)
   {
      PCM2WAY_PutToSpk((const kal_uint16*)pSrc);
   }
   else
   {
      DACA_PutToSE((const kal_uint16*)pSrc);
   }

   if(uDirectCopy)
   {
      BT_SCO_ReadDataDone_RX(NB_SPEECH_FRAME_SIZE);
   }

   if(pSpStruct->uAppMode == BT_SCO_APP_MODE_CORDLESS)
   {
      BT_SCO_Speech_TX_HISR();
   }
}

#ifdef __VOICE_CHANGER_SUPPORT__
void BT_SCO_Dedicate_TX_HISR(kal_uint16* buf, kal_uint16 len)
{
   kal_uint8 *pDst, *pSrc;
   kal_uint32 uOutByte, uFreeSpace, uRemainByte;
   BT_SCO_NB_SPEECH *pSpStruct;
   pSpStruct = (BT_SCO_NB_SPEECH*)BT_SCO_GetUserData(BT_SCO_LINK_TX_ONLY);
   BT_SCO_GetWriteBuffer_TX(&pDst, &uOutByte);
   uFreeSpace = BT_SCO_GetFreeSpace_TX();
   kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_TX_DATA, uOutByte, uFreeSpace);
   uOutByte = BT_SCO_CheckByte(BT_SCO_LINK_TX_ONLY, uOutByte);
   uFreeSpace = BT_SCO_CheckByte(BT_SCO_LINK_TX_ONLY, uFreeSpace);

   if(uOutByte >= NB_SPEECH_FRAME_SIZE)
   {
      pSrc = pDst;
   }
   else if(uFreeSpace >= NB_SPEECH_FRAME_SIZE)
   {
      pSrc = pSpStruct->ULBuf;
   }
   else
   { 
      kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_TX_OF, uFreeSpace);
      //overflow
      return;
   }
/*
   if(pSpStruct->uAppMode == BT_SCO_APP_MODE_CORDLESS)
   {
      PCM2WAY_GetFromMic((kal_uint16*)pSrc);
   }
   else
   {
      DACA_GetFromSD((kal_uint16*)pSrc);
   }
*/
   memcpy((kal_uint8*)pSrc,(kal_uint8*) buf,sizeof(kal_uint16)*len);

   if(uOutByte >= NB_SPEECH_FRAME_SIZE)
   {
      BT_SCO_WriteDataDone_TX(NB_SPEECH_FRAME_SIZE);
   }
   else
   {//put to temp buffer first
      memcpy(pDst, pSrc, uOutByte);
      BT_SCO_WriteDataDone_TX(uOutByte);
      pSrc += uOutByte;
      uRemainByte = NB_SPEECH_FRAME_SIZE - uOutByte;
      BT_SCO_GetWriteBuffer_TX(&pDst, &uOutByte);
      uOutByte = BT_SCO_CheckByte(BT_SCO_LINK_TX_ONLY, uOutByte);
      ASSERT(uOutByte>=uRemainByte);
      memcpy(pDst, pSrc, uRemainByte);
      BT_SCO_WriteDataDone_TX(uRemainByte); 
   }
}

void BT_SCO_Dedicate_RX_HISR(kal_uint16* buf)
{
   kal_uint8 *pSrc, *pDst;
   kal_uint32 uInByte, uDataCount, uRemainByte, uDirectCopy=0;
   BT_SCO_NB_SPEECH *pSpStruct;
   pSpStruct = (BT_SCO_NB_SPEECH*)BT_SCO_GetUserData(BT_SCO_LINK_RX_ONLY);
   BT_SCO_GetReadBuffer_RX(&pSrc, &uInByte);
   uDataCount = BT_SCO_GetDataCount_RX();
   kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_RX_DATA, uInByte, uDataCount);
   uInByte = BT_SCO_CheckByte(BT_SCO_LINK_RX_ONLY, uInByte);
   uDataCount = BT_SCO_CheckByte(BT_SCO_LINK_RX_ONLY, uDataCount);
   if(uInByte >= NB_SPEECH_FRAME_SIZE)
   {
      uDirectCopy = 1;
   }
   else if(uDataCount >= NB_SPEECH_FRAME_SIZE)
   {
      pDst = pSpStruct->DLBuf;
      memcpy(pDst, pSrc, uInByte);
      pDst += uInByte;
      uRemainByte = NB_SPEECH_FRAME_SIZE - uInByte;
      BT_SCO_ReadDataDone_RX(uInByte);
      BT_SCO_GetReadBuffer_RX(&pSrc, &uInByte);
      ASSERT(uInByte>=uRemainByte);
      memcpy(pDst, pSrc, uRemainByte);
      BT_SCO_ReadDataDone_RX(uRemainByte);
      pSrc = pSpStruct->DLBuf;
   }
   else
   { 
      kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_RX_UF, uDataCount);
      return;
   }
/*
   if(pSpStruct->uAppMode == BT_SCO_APP_MODE_CORDLESS)
   {
      PCM2WAY_PutToSpk((const kal_uint16*)pSrc);
   }
   else
   {
      DACA_PutToSE((const kal_uint16*)pSrc);
   }
*/

   memcpy((kal_uint8*)buf,(kal_uint8*)pSrc,NB_SPEECH_FRAME_SIZE);
  
   if(uDirectCopy)
   {
      BT_SCO_ReadDataDone_RX(NB_SPEECH_FRAME_SIZE);
   }

   if(pSpStruct->uAppMode == BT_SCO_APP_MODE_CORDLESS)
   {
      BT_SCO_Speech_TX_HISR();
   }
}
#endif

//=============================================================================================
//    Speech Path
//=============================================================================================

void BT_SCO_SpeechPath_ON(BT_SCO_APP_SPEECH_PATH uPath)
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_ON);
   
#if !defined(__BT_AUDIO_VIA_SCO__)
	 if(AM_IsAudioPlaybackOn() != -1)
	 {
	 	return;
	 }
   else 
#endif
   if(AM_IsConflictState())
   {
      if(uPath == BT_SCO_APP_SPEECH_PATH_BTDL)  
      {
         BT_SCO_APP.uDACAType = DACA_APP_TYPE_ACTIVE_UL_NB;
      }
      else if(uPath == BT_SCO_APP_SPEECH_PATH_BTUL)
      {
         BT_SCO_APP.uDACAType = DACA_APP_TYPE_ACTIVE_DL_NB;
      }
      else
      {
         BT_SCO_APP.uDACAType = DACA_APP_TYPE_ACTIVE_UL_DL_NB;
      }
   }
   else
   {
      if(uPath == BT_SCO_APP_SPEECH_PATH_BTDL)  
      {
         BT_SCO_APP.uDACAType = DACA_APP_TYPE_IDLE_UL_NB;
      }
      else if(uPath == BT_SCO_APP_SPEECH_PATH_BTUL)
      {
         BT_SCO_APP.uDACAType = DACA_APP_TYPE_IDLE_DL_NB;
      }
      else
      {
         BT_SCO_APP.uDACAType = DACA_APP_TYPE_IDLE_UL_DL_NB;
      }
   }
   btsco_SpeechPath_ON(BT_SCO_APP_MODE_SPEECH);
   #ifdef __VOICE_CHANGER_SUPPORT__
   if(!(AM_IsSpeechOn()&& L1SP_GetVoiceChangerMode()!= SPH_VC_NORMAL))
   #endif
       DACA_Start(BT_SCO_Speech_TX_HISR, BT_SCO_Speech_RX_HISR, BT_SCO_APP.uDACAType);
   BT_SCO_APP.uAppMode = BT_SCO_APP_MODE_SPEECH;
}

static void BT_SCO_SpeechPath_OFF()
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_OFF);
   #ifdef __VOICE_CHANGER_SUPPORT__
   if(!(AM_IsSpeechOn()&& L1SP_GetVoiceChangerMode()!= SPH_VC_NORMAL))
   #endif
       DACA_Stop(BT_SCO_APP.uDACAType);
   BT_SCO_APP.uAppMode = BT_SCO_APP_MODE_DISABLE;
   btscio_SpeechPath_OFF();
}

//=============================================================================================
//    Cordless Path
//=============================================================================================

void BT_SCO_Cordless_ON(kal_uint32 uSampleRate, kal_uint32 uChannelNumber)
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_CORDLESS_ON);
   
   KT_StopAndWait();
   TONE_StopAndWait();
   PcmSink_TerminateSound();  
   
   if(AM_IsConflictState())
   {
      BT_SCO_APP.uP2WType = P2W_APP_TYPE_UNDER_CALL;
   }
   else
   {
      BT_SCO_APP.uP2WType = P2W_APP_TYPE_VOIP;
   }
   BT_SCO_Set_Cordless_On(KAL_TRUE);
   btsco_SpeechPath_ON(BT_SCO_APP_MODE_CORDLESS);
   PCM2WAY_Start(BT_SCO_Speech_RX_HISR, BT_SCO_APP.uP2WType);
   BT_SCO_APP.uAppMode = BT_SCO_APP_MODE_CORDLESS;
}

static void BT_SCO_Cordless_OFF()
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_CORDLESS_OFF);
#if defined(BT_DIALER_SPE_FOR_LOUDSPEAKER) || defined(BT_DIALER_SPE_FOR_RECEIVER)
    if (BT_SCO_Is_Cordless_On())
    {
        SetSpeechEnhancement(false);
    }
#endif  // BT dialer SPE
   PCM2WAY_Stop(BT_SCO_APP.uP2WType);
   BT_SCO_APP.uAppMode = BT_SCO_APP_MODE_DISABLE;
   btscio_SpeechPath_OFF();
   BT_SCO_Set_Cordless_On(KAL_FALSE);
}

//=============================================================================================
//    Audio Playback
//=============================================================================================
#if defined (__BT_AUDIO_VIA_SCO__)
kal_uint32 BT_SCO_AudioWriteSilence(kal_uint32 uSampleCount)
{
   kal_uint32 uCopyWord=0, uOutByte=0, i, j, uOrigSrcWord, uChannelNumber, uOutWord;
   kal_uint8 *pDst;
   if(BT_SCO_APP.uAppMode != BT_SCO_APP_MODE_AUDIO)
   {
      return 0;
   }
   uOrigSrcWord = uSampleCount;
   for(i=0;i<2;i++)
   {
      kal_int16 *pBuf;
      BT_SCO_GetWriteBuffer_TX(&pDst, &uOutByte);  
      uOutWord = uOutByte >> 1;
      if(uOutWord > uSampleCount)
      {
         uOutWord = uSampleCount;
      }
      memset( pDst, 0, uOutWord*sizeof(kal_uint16) );
      BT_SCO_WriteDataDone_TX(uOutWord<<1);  
      uCopyWord    += uOutWord;
      uSampleCount -= uOutWord;
   }
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_AUDIO_ZERO, uOrigSrcWord, uCopyWord, uOrigSrcWord-uCopyWord);
   return uCopyWord;
}

kal_uint32 BT_SCO_AudioWriteData(kal_uint16 *pSrc16, kal_uint32 uSrcWord, kal_bool fMono2Stereo)
{
   kal_uint32 uCopyWord=0, uOutByte=0, i, j, uOrigSrcWord=0, uOutWord=0;
   kal_uint8 *pDst;
   if(BT_SCO_APP.uAppMode != BT_SCO_APP_MODE_AUDIO)
   {
      return 0;
   }
   uOrigSrcWord = uSrcWord;
   for(i=0;i<2;i++)
   {
      kal_uint16 *pDst16;
      BT_SCO_GetWriteBuffer_TX(&pDst, &uOutByte);  
      pDst16 = (kal_uint16*)pDst;
      uOutWord = uOutByte >> 1;
      if(fMono2Stereo)
      {
         uOutWord = uOutWord >> 1;
         if(uOutWord > uSrcWord)
         {
            uOutWord = uSrcWord;
         }
         for(j=0;j<uOutWord;j++)
         {
            *pDst16++ = *pSrc16;
            *pDst16++ = *pSrc16++;
         }
         uSrcWord -= uOutWord;
         BT_SCO_WriteDataDone_TX(uOutWord<<2);  
      }
      else
      {
         if(uOutWord > uSrcWord)
         {
            uOutWord = uSrcWord;
         }
         memcpy(pDst16, pSrc16, uOutWord*sizeof(kal_uint16));
         pSrc16   += uOutWord;
         uSrcWord -= uOutWord;
         BT_SCO_WriteDataDone_TX(uOutWord<<1);  
      }
      uCopyWord += uOutWord;
   }
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_AUDIO_DATA, uOrigSrcWord, uCopyWord, uOrigSrcWord-uCopyWord, fMono2Stereo);
   return uCopyWord;
}

void BT_SCO_AudioPath_ON()
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_AUDIO_ON, BT_SCO_APP.uSampleRate, BT_SCO_APP.uChannelNumber);
   PcmSink_StartBT(PCMSINK_BT_SCO);
#if defined(__AUDIO_COMPONENT_SUPPORT__)
   BT_SCO_Disable_All_APP();
#endif

#if APM_SUPPORT
#if defined(__AUDIO_ULTRA_SLIM__)
   BT_SCO_APP.fDisableBessound = KAL_TRUE;
   AudioPP_DisableBesSound();
#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   if(BT_SCO_APP.uSampleRate > 32000)
   {
      BT_SCO_APP.fDisableBessound = KAL_TRUE;
      AudioPP_DisableBesSound();
   }
#endif
#endif

   mhdlHookPcmRut();
   BT_SCO_Open(BT_SCO_MODE_CVSD, BT_SCO_LINK_TX_ONLY);
   BT_SCO_SetCallback_TX(NULL, NULL, BT_SCO_APP.uSampleRate, BT_SCO_APP.uChannelNumber, AUDIO_TX_FILTER);
   BT_SCO_Start();
   BT_SCO_APP.uAppMode = BT_SCO_APP_MODE_AUDIO;
}

static void BT_SCO_AudioPath_OFF()
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_AUDIO_OFF);
#if defined(__AUDIO_COMPONENT_SUPPORT__)
   PcmSink_StopBT(PCMSINK_BT_SCO);
#endif
   BT_SCO_Stop();
   BT_SCO_Close();
   BT_SCO_APP.uAppMode = BT_SCO_APP_MODE_DISABLE;
#if APM_SUPPORT
   if(BT_SCO_APP.fDisableBessound)
   {
      BT_SCO_APP.fDisableBessound = KAL_FALSE;
      AudioPP_EnableBesSound(); 
   }
#endif
}

void BT_SCO_AudioPath_SetInfo(kal_uint16 uSampleRate, kal_uint8 uChannelNumber)
{
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_AUDIO_SETINFO, uSampleRate, uChannelNumber);
   BT_SCO_APP.uSampleRate    = uSampleRate;
   BT_SCO_APP.uChannelNumber = uChannelNumber;
}
#endif

void BT_SCO_Disable_All_APP()
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_DISABLE_ALL, BT_SCO_APP.uAppMode);
#if defined (__BT_AUDIO_VIA_SCO__)
   if(BT_SCO_APP.uAppMode == BT_SCO_APP_MODE_AUDIO)
   {
      BT_SCO_AudioPath_OFF();
   }
   else
#endif
   if(BT_SCO_APP.uAppMode == BT_SCO_APP_MODE_SPEECH)
   {
      BT_SCO_SpeechPath_OFF();
   }
   else if(BT_SCO_APP.uAppMode == BT_SCO_APP_MODE_CORDLESS)
   {
      BT_SCO_Cordless_OFF();
   }
#if defined(__CVSD_LOOPBACK_TEST__)
   else if(BT_SCO_APP.uAppMode == BT_SCO_APP_MODE_LOOPBACK)
   {
      BT_SCO_LoopbackPath_OFF();
   }
#endif
   BT_SCO_APP.uAppMode = BT_SCO_APP_MODE_DISABLE;
}

BT_SCO_APP_MODE BT_SCO_GetCurrentMode()
{
#if defined (__BT_DIALER_SUPPORT__)
   return BT_SCO_APP.uAppMode == BT_SCO_APP_MODE_CORDLESS ? BT_SCO_APP_MODE_SPEECH : BT_SCO_APP.uAppMode;
#else
   return BT_SCO_APP.uAppMode;
#endif   
}




#endif //__CVSD_CODEC_SUPPORT__

