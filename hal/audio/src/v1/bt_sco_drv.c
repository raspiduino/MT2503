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
 *  BT_SCO_drv.c
 *
 * Project:
 * --------
 *  Maui_sw
 *
 * Description:
 * ------------
 *  BT SCO driver
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
#include "cvsd_codec_exp.h"
#include "audio_iirhpf_exp.h"
#include "eint.h"
#include "audio_def.h"
#include "bt_sco_app.h"


static const kal_int32  btsco_FilterCoeff_64K[4]={0x07F54A0C, 0xF017CB31, 0x07F2EB36, 0x7F41C0BE};
static const kal_int32  btsco_FilterCoeff_8K[4] ={0x07AB676D, 0xF0BB80B9, 0x079933A1, 0x79F9C5B0};
static const kal_uint32 btsco_PacketValidMask[6][6] = {{0x1   , 0x1<<1, 0x1<<2, 0x1<<3, 0x1<<4 , 0x1<<5 },  //30
                                                       {0x1   , 0x1   , 0x2   , 0x2   , 0x4    , 0x4    },  //60
                                                       {0x1   , 0x1   , 0x1   , 0x2   , 0x2    , 0x2    },  //90
                                                       {0x1   , 0x1   , 0x1   , 0x1   , 0      , 0      },  //120
                                                       {0x7   , 0x7<<3, 0x7<<6, 0x7<<9, 0x7<<12, 0x7<<15},  //10
                                                       {0x3   , 0x3<<1, 0x3<<3, 0x3<<4, 0x3<<6 , 0x3<<7 }}; //20

static const kal_uint8 btsco_PacketInfo[6][6] = {{ 30, 6, BT_SCO_PACKET_180/SCO_TX_ENCODE_SIZE, BT_SCO_PACKET_180/SCO_RX_PLC_SIZE},  //30
                                                 { 60, 3, BT_SCO_PACKET_180/SCO_TX_ENCODE_SIZE, BT_SCO_PACKET_180/SCO_RX_PLC_SIZE},  //60
                                                 { 90, 2, BT_SCO_PACKET_180/SCO_TX_ENCODE_SIZE, BT_SCO_PACKET_180/SCO_RX_PLC_SIZE},  //90
                                                 {120, 1, BT_SCO_PACKET_120/SCO_TX_ENCODE_SIZE, BT_SCO_PACKET_120/SCO_RX_PLC_SIZE},  //120
                                                 { 10,18, BT_SCO_PACKET_180/SCO_TX_ENCODE_SIZE, BT_SCO_PACKET_180/SCO_RX_PLC_SIZE},  //10
                                                 { 20, 9, BT_SCO_PACKET_180/SCO_TX_ENCODE_SIZE, BT_SCO_PACKET_180/SCO_RX_PLC_SIZE}}; //20
/*
static const kal_uint8 btsco_PacketInfo[6][6] = {{ 30, 6, 3, 6},  //30
                                                 { 60, 3, 3, 6},  //60
                                                 { 90, 2, 3, 6},  //90
                                                 {120, 1, 2, 4},  //120
                                                 { 10,18, 3, 6},  //10
                                                 { 20, 9, 3, 6}}; //20
*/

static struct{
   BT_SCO_TX *pTX;
   BT_SCO_RX *pRX;
   kal_uint8 *pStructMemory;
   kal_uint8 *pWorkingMemory;
   kal_uint8 *pTempPacketBuf;
   kal_uint16 uAudId;
   BT_SCO_STATE uState;
   kal_bool  fIsStructMemoryOnMED;
   kal_bool  fMute;
   kal_bool  is_cordless_on;
}btsco;

//=============================================================================================
//    BT SCO Internal Function
//=============================================================================================

static void btsco_DataTransfer(BT_SCO_DIRECT uDir, kal_uint8 *pSrc, kal_uint8 *pDst, kal_uint32 uBlockSize, kal_uint32 uBlockNum  )
{
   kal_int32 i, j;
   kal_uint32 u4SilencePattern = 0x55555555;
   kal_uint16 u2SilencePattern = 0x5555;
   if(uBlockSize == 60 || uBlockSize == 120 || uBlockSize == 20)
   {
      kal_uint32 *pSrc32 = (kal_uint32*)pSrc;
      kal_uint32 *pDst32 = (kal_uint32*)pDst;
      if(btsco.uState ==  BT_SCO_STATE_ENDING)
      {
         for(i=0 ; i<(uBlockSize*uBlockNum/4) ; i++)
         {
            *pDst32++ = u4SilencePattern;
         }
      }
      else
      {
         for(i=0 ; i<(uBlockSize*uBlockNum/4) ; i++)
         {
            *pDst32++ = *pSrc32++;
         }
      }
   }
   else
   {
      kal_uint16 *pSrc16 = (kal_uint16*)pSrc;
      kal_uint16 *pDst16 = (kal_uint16*)pDst;
      for(j=0 ; j< uBlockNum ; j++)
      {
         if(btsco.uState ==  BT_SCO_STATE_ENDING)
         {
            for(i=0 ; i<(uBlockSize/2) ; i++)
            {
               *pDst16++ = u2SilencePattern;
            }
         }
         else
         {
            for(i=0 ; i<(uBlockSize/2) ; i++)
            {
               *pDst16++ = *pSrc16++;
            }
         }
         if(uDir == BT_SCO_DIRECT_BT2ARM)
         {
            pSrc16++;
         }
         else
         {
            pDst16++;
         }
      }
   }
}


#if defined(__CVSD_DEBUG_RX__) || defined(__CVSD_DEBUG_TX__)
#define DEBUG_LENGTH (108000/4) //120*180
static kal_uint8 CVSD_BUFFER[DEBUG_LENGTH];
static kal_uint32 CVSD_W = 0;
#endif

static void btsco_ReadFromBT(BT_SCO_PACKET_LEN uLen, kal_uint32 uPacketLength, kal_uint32 uPacketNumber, kal_uint32 uBlockSize, kal_uint32 uControl)
{
   kal_int32 i;
   kal_uint8 *pSrc = (kal_uint8 *)(BTSRAM_BASE + *BT_SCO_HW_REG_PACKET_R);
   btsco_DataTransfer(BT_SCO_DIRECT_BT2ARM, pSrc, btsco.pTempPacketBuf, uPacketLength, uPacketNumber );
   for(i=0;i<uBlockSize;i++)
   {
      memcpy(btsco.pRX->PacketBuf[btsco.pRX->iPacket_w & SCO_RX_PACKET_MASK], btsco.pTempPacketBuf+(SCO_RX_PLC_SIZE*i), SCO_RX_PLC_SIZE);
      if((uControl & btsco_PacketValidMask[uLen][i]) == btsco_PacketValidMask[uLen][i])
      {
         btsco.pRX->PacketValid[btsco.pRX->iPacket_w & SCO_RX_PACKET_MASK] = 1 ; //packet valid
      }
      else
      {
         btsco.pRX->PacketValid[btsco.pRX->iPacket_w & SCO_RX_PACKET_MASK] = 0 ; //packet lost
      }
      btsco.pRX->iPacket_w++;
   }
#if defined(__CVSD_DEBUG_RX__)
   memcpy(&CVSD_BUFFER[CVSD_W], btsco.pTempPacketBuf, uBlockSize*SCO_RX_PLC_SIZE );
   CVSD_W+=uBlockSize*SCO_RX_PLC_SIZE;
   if(CVSD_W==DEBUG_LENGTH)
   {
      CVSD_W = 0;
   }
#endif   
   
}

static void btsco_WriteToBT(BT_SCO_PACKET_LEN uLen, kal_uint32 uPacketLength, kal_uint32 uPacketNumber, kal_uint32 uBlockSize, kal_bool fFillSilence)
{
   kal_int32 i;
   kal_uint8 *pDst = (kal_uint8 *)(BTSRAM_BASE + *BT_SCO_HW_REG_PACKET_W);
   if(fFillSilence == KAL_TRUE)
   {
      kal_uint8 *pSrc = btsco.pTempPacketBuf;
      for(i=0;i<uPacketLength*uPacketNumber;i++)
      {
         *pSrc++ = 0x55;
      }
   }
   else
   {
      for(i=0;i<uBlockSize;i++)
      { 
         memcpy(btsco.pTempPacketBuf+(SCO_TX_ENCODE_SIZE*i), btsco.pTX->PacketBuf[btsco.pTX->iPacket_r & SCO_TX_PACKET_MASK], SCO_TX_ENCODE_SIZE);
         btsco.pTX->iPacket_r++;
      }
   }
   btsco_DataTransfer(BT_SCO_DIRECT_ARM2BT, btsco.pTempPacketBuf, pDst, uPacketLength, uPacketNumber );
#if defined(__CVSD_DEBUG_TX__)
   memcpy(&CVSD_BUFFER[CVSD_W], btsco.pTempPacketBuf, uPacketLength*uPacketNumber );
   CVSD_W+=uPacketLength*uPacketNumber;
   if(CVSD_W==DEBUG_LENGTH)
   {
      CVSD_W = 0;
   }
#endif
}

static void btsco_hisr(void *pData)
{
   kal_uint32 uPacketType, uPacketNumber, uPacketLength, uBufferCount_TX, uBufferCount_RX, uControl;
   kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_HISR, btsco.uState, 1);
   if(btsco.uState != BT_SCO_STATE_RUNNING & btsco.uState !=  BT_SCO_STATE_ENDING)
   {
      *BT_SCO_HW_REG_CONTROL &= ~BT_CVSD_CLEAR;
      return;
   }
   uControl = *BT_SCO_HW_REG_CONTROL;
   uPacketType = (uControl >> 18) & 0x7;
   kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_CONTROL, uControl, uPacketType, *BT_SCO_HW_REG_PACKET_W, *BT_SCO_HW_REG_PACKET_R);
   if( ((uControl>>31) & 1) == 0)
   {
      *BT_SCO_HW_REG_CONTROL &= ~BT_CVSD_CLEAR;
      return;
   }

   ASSERT(uPacketType < BT_SCO_CVSD_MAX);
   uPacketLength   = (kal_uint32)btsco_PacketInfo[uPacketType][0];
   uPacketNumber   = (kal_uint32)btsco_PacketInfo[uPacketType][1];
   uBufferCount_TX = (kal_uint32)btsco_PacketInfo[uPacketType][2];
   uBufferCount_RX = (kal_uint32)btsco_PacketInfo[uPacketType][3];
   if(btsco.pRX)
   {
      kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_COPY_RX, btsco.pRX->fOverflow, btsco.pRX->iPacket_w, btsco.pRX->iPacket_r, uBufferCount_RX);
      if(btsco.pRX->fOverflow)
      {
         if(btsco.pRX->iPacket_w - btsco.pRX->iPacket_r <= SCO_RX_PACKER_BUF_NUM - 2*uBufferCount_RX) 
         {
            //free space is larger then twice interrupt rx data size
            btsco.pRX->fOverflow = KAL_FALSE;
         }  
      }
      if(!btsco.pRX->fOverflow && (btsco.pRX->iPacket_w - btsco.pRX->iPacket_r <= SCO_RX_PACKER_BUF_NUM - uBufferCount_RX))
      {
         btsco_ReadFromBT(uPacketType, uPacketLength, uPacketNumber, uBufferCount_RX, uControl);
      }
      else
      {
         btsco.pRX->fOverflow = KAL_TRUE;
      }
   }

   if(btsco.pTX)
   {
      kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_COPY_TX, btsco.pTX->fUnderflow, btsco.pTX->iPacket_w, btsco.pTX->iPacket_r, uBufferCount_TX);
      if(btsco.pTX->fUnderflow)
      {
         //prepared data is larger then twice interrupt tx data size
         if(btsco.pTX->iPacket_w - btsco.pTX->iPacket_r >= 2*uBufferCount_TX)
         {
            btsco.pTX->fUnderflow = KAL_FALSE;
         }         
      }

      if(btsco.pTX->iPacket_w - btsco.pTX->iPacket_r < uBufferCount_TX)
      {
         btsco.pTX->fUnderflow = KAL_TRUE;
      }
      
	  if(btsco.pTX->fUnderflow || btsco.uState ==  BT_SCO_STATE_ENDING)
	  {  //silence
	     btsco_WriteToBT(uPacketType, uPacketLength, uPacketNumber, uBufferCount_TX, KAL_TRUE);
	  }
	  else
	  {  //cvsd packet
	     btsco_WriteToBT(uPacketType, uPacketLength, uPacketNumber, uBufferCount_TX, KAL_FALSE);
	  }
   }
   *BT_SCO_HW_REG_CONTROL &= ~BT_CVSD_CLEAR;
   L1Audio_SetEvent( btsco.uAudId, NULL );
}

static kal_uint32 btsco_GetMemorySize_4ByteAlign(BT_SCO_MODULE uModule)
{
   kal_uint32 uSize;
   switch(uModule)
   {
      case BT_SCO_MOD_CVSD_ENCODE: 
         uSize = (kal_uint32)CVSD_ENC_GetBufferSize();
         break;
      case BT_SCO_MOD_CVSD_DECODE: 
         uSize = (kal_uint32)CVSD_DEC_GetBufferSize();
         break;
      case BT_SCO_MOD_FILTER_TX: 
      case BT_SCO_MOD_FILTER_RX: 
         uSize = (kal_uint32)Audio_IIRHPF_GetBufferSize(1);
         break;
      case BT_SCO_MOD_PLC:
         uSize = (kal_uint32)g711plc_GetMemorySize();
         break;
      case BT_SCO_MOD_CVSD_TX_SRC:
#if defined(__DISABLE_BLISRC__)
         if(btsco.pTX->uSampleRate == 8000 || btsco.pTX->uSampleRate == 11025 || btsco.pTX->uSampleRate == 12000 )
         {
            BLI_GetMemSize(btsco.pTX->uSampleRate,btsco.pTX->uChannelNumber,32000,1,&uSize);
         }
         else
         {
            BLI_GetMemSize(btsco.pTX->uSampleRate,btsco.pTX->uChannelNumber>>1,32000,1,&uSize);
         }
#else
#if defined(__DISABLE_ARBITRARY_BLISRC__)
         if(btsco.pTX->uSampleRate == 11025)
         {
            BLI_GetMemSize(btsco.pTX->uSampleRate,btsco.pTX->uChannelNumber,32000,1,&uSize);
         }
         else
#endif
         {
            BLI_GetMemSize(btsco.pTX->uSampleRate,btsco.pTX->uChannelNumber,64000,1,&uSize);
         }
#endif
         break;
      case BT_SCO_MOD_CVSD_RX_SRC1:
#if defined(__DISABLE_BLISRC__)
         uSize = 0;
#else
         BLI_GetMemSize(64000,1,8000,1,&uSize);
#endif
         break;
      case BT_SCO_MOD_CVSD_RX_SRC2:
#if defined(__DISABLE_BLISRC__)
         uSize = 0;
#else
         BLI_GetMemSize(8000,1,btsco.pRX->uSampleRate,btsco.pRX->uChannelNumber,&uSize);
#endif
         break;
      case BT_SCO_MOD_PCM_RINGBUF_TX:
         uSize = SCO_TX_RINGBUFFER_SIZE;
         break;
      case BT_SCO_MOD_PCM_RINGBUF_RX:
         uSize = SCO_RX_RINGBUFFER_SIZE;
         break;
      default:
         ASSERT(0);
   }
   uSize = (uSize+3) & ~3 ;
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_GET_MEM, uModule, uSize);
   return uSize;
}

static void btsco_DestroyModule()
{
   if(btsco.pTX)
   {
      if(btsco.pTX->pSRCHandle)
      {
         BLI_Close(btsco.pTX->pSRCHandle, audio_free_ext_mem_simplified);
         btsco.pTX->pSRCHandle = NULL;
      }
   }
#if !defined(__DISABLE_BLISRC__)
   if(btsco.pRX)
   {
      if(btsco.pRX->pSRCHandle_1)
      {
         BLI_Close(btsco.pRX->pSRCHandle_1, audio_free_ext_mem_simplified);
      }
      if(btsco.pRX->pSRCHandle_2)
      {
         BLI_Close(btsco.pRX->pSRCHandle_2, audio_free_ext_mem_simplified);
      }
   }
#endif
}

static void btsco_InitialModule(BT_SCO_MODULE uModule, kal_uint8 *pBuf)
{
   ASSERT(pBuf);
   switch(uModule)
   {
      case BT_SCO_MOD_CVSD_ENCODE: 
         btsco.pTX->pEncHandle = CVSD_ENC_Init((kal_int8*)pBuf);
         break;
      case BT_SCO_MOD_CVSD_DECODE: 
         btsco.pRX->pDecHandle = CVSD_DEC_Init((kal_int8*)pBuf);
         break;
      case BT_SCO_MOD_FILTER_TX: 
         btsco.pTX->pHPFHandle = Audio_IIRHPF_Init((kal_int8*)pBuf, btsco_FilterCoeff_8K, 1);
         break;
      case BT_SCO_MOD_FILTER_RX: 
         btsco.pRX->pHPFHandle = Audio_IIRHPF_Init((kal_int8*)pBuf, btsco_FilterCoeff_64K, 1);
         break;
      case BT_SCO_MOD_PLC:
         g711plc_construct((void *)pBuf);
         btsco.pRX->pPLCHandle = (void*)pBuf;
         break;
      case BT_SCO_MOD_CVSD_TX_SRC:
#if defined(__DISABLE_BLISRC__)
         if(btsco.pTX->uSampleRate == 8000 || btsco.pTX->uSampleRate == 11025 || btsco.pTX->uSampleRate == 12000 )
         {
            btsco.pTX->pSRCHandle = (void*)BLI_Open(btsco.pTX->uSampleRate,btsco.pTX->uChannelNumber,32000,1,(kal_int8*)pBuf, audio_alloc_ext_mem_cacheable_simplified);
         }
         else
         {
            btsco.pTX->pSRCHandle = (void*)BLI_Open(btsco.pTX->uSampleRate>>1,btsco.pTX->uChannelNumber,32000,1,(kal_int8*)pBuf, audio_alloc_ext_mem_cacheable_simplified);
         }
#else
#if defined(__DISABLE_ARBITRARY_BLISRC__)
         if(btsco.pTX->uSampleRate == 11025)
         {
            btsco.pTX->pSRCHandle = (void*)BLI_Open(btsco.pTX->uSampleRate,btsco.pTX->uChannelNumber,32000,1,(kal_int8*)pBuf, audio_alloc_ext_mem_cacheable_simplified);
         }
         else
#endif
         {
            btsco.pTX->pSRCHandle = (void*)BLI_Open(btsco.pTX->uSampleRate,btsco.pTX->uChannelNumber,64000,1,(kal_int8*)pBuf, audio_alloc_ext_mem_cacheable_simplified);
         }
#endif
         break;
      case BT_SCO_MOD_CVSD_RX_SRC1:
#if !defined(__DISABLE_BLISRC__)
         btsco.pRX->pSRCHandle_1 = (void*)BLI_Open(64000,1,8000,1,(kal_int8*)pBuf, audio_alloc_ext_mem_cacheable_simplified);
#endif
         break;
      case BT_SCO_MOD_CVSD_RX_SRC2:
#if !defined(__DISABLE_BLISRC__)
         btsco.pRX->pSRCHandle_2 = (void*)BLI_Open(8000,1,btsco.pRX->uSampleRate,btsco.pRX->uChannelNumber,(kal_int8*)pBuf, audio_alloc_ext_mem_cacheable_simplified);
#endif
         break;
      case BT_SCO_MOD_PCM_RINGBUF_TX:
         btsco.pTX->RingBuffer.rb_base = pBuf;
         btsco.pTX->RingBuffer.rb_size = SCO_TX_RINGBUFFER_SIZE;
         if(btsco.pRX==NULL)
         {
            btsco.pTX->RingBuffer.write = btsco.pTX->RingBuffer.rb_size>>2;
         }
         break;
      case BT_SCO_MOD_PCM_RINGBUF_RX:
         btsco.pRX->RingBuffer.rb_base = pBuf;
         btsco.pRX->RingBuffer.rb_size = SCO_RX_RINGBUFFER_SIZE;
         break;
      default:
         ASSERT(0);
   }
}

static Media_Status btsco_SetHandle(void(*pCallback)( void *pData ), void *pData, kal_uint32 uSampleRate, kal_uint32 uChannelNumber, kal_uint32 uEnableFilter, kal_uint32 uIsTX)
{
   ASSERT(btsco.uState==BT_SCO_STATE_INIT || btsco.uState==BT_SCO_STATE_READY);   
   if(uChannelNumber != 1 && uChannelNumber != 2)
   {
      return MEDIA_UNSUPPORTED_CHANNEL;
   }
   if( uSampleRate != 8000  && uSampleRate != 11025 && uSampleRate != 12000 && 
       uSampleRate != 16000 && uSampleRate != 22050 && uSampleRate != 24000 && 
       uSampleRate != 32000 && uSampleRate != 44100 && uSampleRate != 48000 )
   {
      return MEDIA_UNSUPPORTED_FREQ;
   }

   if(uIsTX)
   {
      ASSERT(btsco.pTX);
      btsco.pTX->pCallback      = pCallback;
      btsco.pTX->uSampleRate    = (kal_uint16)uSampleRate;
      btsco.pTX->uChannelNumber = (kal_uint8)uChannelNumber;
      btsco.pTX->pUserData      = pData;
      btsco.pTX->fEnableFilter  = uEnableFilter;
   }
   else
   { 
      ASSERT(btsco.pRX);
      btsco.pRX->pCallback      = pCallback;
      btsco.pRX->uSampleRate    = (kal_uint16)uSampleRate;
      btsco.pRX->uChannelNumber = (kal_uint8)uChannelNumber;
      btsco.pRX->pUserData      = pData;
      btsco.pRX->fEnableFilter  = uEnableFilter;
      if(btsco.pRX->uSampleRate != 8000 || btsco.pRX->uChannelNumber != 1)
      {
         btsco.pRX->fEnableSRC2 = KAL_TRUE;
      }
   }
   btsco.uState=BT_SCO_STATE_READY;
   return MEDIA_SUCCESS;
}

static void btsco_GetReadBuffer_TX(kal_uint8 **pBuf, kal_uint32 *pLen)
{
   ASSERT(btsco.pTX->RingBuffer.rb_base);
   rbGetReadBuffer(&btsco.pTX->RingBuffer, pBuf, pLen);
}

static void btsco_ReadDataDone_TX(kal_uint32 uLen)
{
   ASSERT(btsco.pTX->RingBuffer.rb_base);
   rbReadDataDone(&btsco.pTX->RingBuffer, uLen);
}

kal_int32 btsco_GetFreeSpace_RX()
{
   ASSERT(btsco.pRX->RingBuffer.rb_base);
   rbGetFreeSpace(&btsco.pRX->RingBuffer);
}

static void btsco_GetWriteBuffer_RX(kal_uint8 **pBuf, kal_uint32 *pLen)
{
   ASSERT(btsco.pRX->RingBuffer.rb_base);
   rbGetWriteBuffer(&btsco.pRX->RingBuffer, pBuf, pLen);
}

static void btsco_WriteDataDone_RX(kal_uint32 uLen)
{
   ASSERT(btsco.pRX->RingBuffer.rb_base);
   rbWriteDataDone(&btsco.pRX->RingBuffer, uLen);
}

static void btsco_process_TX_CVSD()
{
   kal_int32 iCount=0;
   while(1)
   {
      for(iCount = 0 ; iCount < 2 ; iCount++)
      {  //downsample
         kal_uint8 *pInBuf;
         kal_uint32 uInByte=0, uOutByte=0, uConsumeByte=0;
         if(SCO_TX_PCM64K_BUF_SIZE != btsco.pTX->uPcmBuf_w)
         {
            btsco_GetReadBuffer_TX(&pInBuf, &uInByte);
            kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_TX_RAW, uInByte, btsco.pTX->uPcmBuf_w);
            uInByte= BT_SCO_CheckByte(BT_SCO_LINK_TX_ONLY, uInByte);
            if( (btsco.pTX->uChannelNumber==1 && uInByte<2) || (btsco.pTX->uChannelNumber==2 && uInByte<4) )
            {
               return;
            }
            uOutByte = SCO_TX_PCM64K_BUF_SIZE - btsco.pTX->uPcmBuf_w;
#if defined(__DISABLE_BLISRC__) || defined(__DISABLE_ARBITRARY_BLISRC__)
#if defined(__DISABLE_BLISRC__)
            if(btsco.pTX->uSampleRate == 8000 || btsco.pTX->uSampleRate == 11025 || btsco.pTX->uSampleRate == 12000 )
#elif defined(__DISABLE_ARBITRARY_BLISRC__)
            if(btsco.pTX->uSampleRate == 11025)
#endif
            {
               kal_int16 *pDst_64k, *pDst_32k;
               uOutByte >>=1;
               pDst_64k = (kal_int16 *)(&btsco.pTX->PcmBuf_64k[btsco.pTX->uPcmBuf_w]);
               pDst_32k = (kal_int16 *)btsco.pTX->PcmBuf_32k;
               uConsumeByte = BLI_Convert(btsco.pTX->pSRCHandle, (kal_int16 *)pInBuf, &uInByte, pDst_32k, &uOutByte);
               if(uOutByte)
			   {
			      apm_UpsampleMono(pDst_32k, pDst_64k, btsco.pTX->pSrcPreSample, uOutByte>>1, 2);
			   }
               uOutByte <<= 1;
            }
            else
#endif
            {
               uConsumeByte = BLI_Convert(btsco.pTX->pSRCHandle, (kal_int16 *)pInBuf, &uInByte, (kal_int16 *)(&btsco.pTX->PcmBuf_64k[btsco.pTX->uPcmBuf_w]), &uOutByte);
            }
            kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_TX_SRC, uConsumeByte, uOutByte);
            btsco.pTX->uPcmBuf_w += uOutByte;
            btsco_ReadDataDone_TX(uConsumeByte);
         }
      }
      if(SCO_TX_PCM64K_BUF_SIZE == btsco.pTX->uPcmBuf_w) 
      {
         if(btsco.pTX->iPacket_w - btsco.pTX->iPacket_r < SCO_TX_PACKER_BUF_NUM)
         {
            kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_TX_CVSD, btsco.pTX->iPacket_w, btsco.pTX->iPacket_r, btsco.pTX->fEnableFilter);
            if(btsco.pTX->fEnableFilter)
            {  //filter
               kal_int32 iInSample = SCO_TX_PCM64K_BUF_SIZE>>1;
               kal_int32 iOutSample = SCO_TX_PCM64K_BUF_SIZE>>1;
               Audio_IIRHPF_Process(btsco.pTX->pHPFHandle, (kal_int16*)btsco.pTX->PcmBuf_64k, &iInSample, (kal_int16*)btsco.pTX->PcmBuf_64k, &iOutSample);
            }
            {  //encode
               kal_int32 iInSample = SCO_TX_PCM64K_BUF_SIZE>>1;
               kal_int32 iOutByte = SCO_TX_ENCODE_SIZE;
               kal_int32 iGain = 0x7FFF;
               if(btsco.fMute)
               {
                  iGain = 0;
               }
               CVSD_ENC_Process(btsco.pTX->pEncHandle, (kal_int16*)btsco.pTX->PcmBuf_64k, &iInSample, &btsco.pTX->PacketBuf[btsco.pTX->iPacket_w & SCO_TX_PACKET_MASK][0], &iOutByte, iGain);
               btsco.pTX->uPcmBuf_w = 0;
               btsco.pTX->iPacket_w++;
            }
         }
         else
         {
            return;
         }
      }
   }
}

static void btsco_process_RX_CVSD()
{
   kal_int32 iCount=0;
   while(1)
   {
      if(SCO_RX_PCM8K_BUF_SIZE == btsco.pRX->uPcmBuf_r)
      {
         //decode 30 byte cvsd
         if(btsco.pRX->iPacket_w != btsco.pRX->iPacket_r)
         {
            kal_int16 *pDst, *pSrc;
            kal_bool fPacketValid = KAL_FALSE;
            kal_int32 iOutSample=0, iInByte=0, I;
            iInByte=SCO_RX_PLC_SIZE;
            iOutSample=SCO_RX_PCM64K_BUF_SIZE>>1;
            kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_RX_CVSD, btsco.pRX->iPacket_w, btsco.pRX->iPacket_r, btsco.pRX->fEnableFilter, btsco.pRX->fEnablePLC);
            CVSD_DEC_Process(btsco.pRX->pDecHandle, &btsco.pRX->PacketBuf[btsco.pRX->iPacket_r & SCO_RX_PACKET_MASK][0], &iInByte, (kal_int16*)btsco.pRX->PcmBuf_64k, &iOutSample);
            fPacketValid = btsco.pRX->PacketValid[btsco.pRX->iPacket_r & SCO_RX_PACKET_MASK];
            //btsco.pRX->iPacket_r++;
            {
               kal_uint32 uOutByte=0, uInByte=0, uConsumeByte=0;
               uInByte = SCO_RX_PCM64K_BUF_SIZE;
               uOutByte = SCO_RX_PCM8K_BUF_SIZE;
#if defined(__DISABLE_BLISRC__)
               apm_DownsampleFilter1((kal_int16 *)btsco.pRX->PcmBuf_64k  , (kal_int16 *)btsco.pRX->PcmBuf_64k_2, btsco.pRX->pStack_64K, SCO_RX_PCM64K_BUF_SIZE>>1); //64->32
               apm_DownsampleFilter2((kal_int16 *)btsco.pRX->PcmBuf_64k_2, (kal_int16 *)btsco.pRX->PcmBuf_64k  , btsco.pRX->pStack_32K, SCO_RX_PCM64K_BUF_SIZE>>2); //32->16
               apm_DownsampleFilter3((kal_int16 *)btsco.pRX->PcmBuf_64k  , (kal_int16 *)btsco.pRX->PcmBuf_64k_2, btsco.pRX->pStack_16K, SCO_RX_PCM64K_BUF_SIZE>>3); //16->8
               pSrc = (kal_int16 *)btsco.pRX->PcmBuf_64k_2;
               pDst = (kal_int16 *)btsco.pRX->PcmBuf_8k;
               for(I=0;I<SCO_RX_PCM64K_BUF_SIZE>>4;I++)
               {
                  *pDst++ = *pSrc++;
               }
#else
               uConsumeByte = BLI_Convert(btsco.pRX->pSRCHandle_1, (kal_int16 *)btsco.pRX->PcmBuf_64k, &uInByte, (kal_int16 *)btsco.pRX->PcmBuf_8k, &uOutByte);  
               ASSERT(uConsumeByte == SCO_RX_PCM64K_BUF_SIZE);
#endif
            }
            if(btsco.pRX->fEnablePLC)
            {  //do PLC
               kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_RX_PLC);
               if(btsco.pRX->PacketValid[btsco.pRX->iPacket_r & SCO_RX_PACKET_MASK])
               {  //packet not lost
                  g711plc_addtohistory(btsco.pRX->pPLCHandle, (short *)btsco.pRX->PcmBuf_8k);
               }
               else
               {  //packet lost
                  g711plc_dofe(btsco.pRX->pPLCHandle, (short *)btsco.pRX->PcmBuf_8k);
                  kal_trace(TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_RX_PLC_PKT_LOST, btsco.pRX->iPacket_r);
               }
            }
            if(btsco.pRX->fEnableFilter)
            {  //do filter
               kal_int32 iInSample = SCO_RX_PCM8K_BUF_SIZE>>1;
               kal_int32 iOutSample = SCO_RX_PCM8K_BUF_SIZE>>1;
               Audio_IIRHPF_Process(btsco.pRX->pHPFHandle, (kal_int16*)btsco.pRX->PcmBuf_8k, &iInSample, (kal_int16*)btsco.pRX->PcmBuf_8k, &iOutSample);
            }
            btsco.pRX->iPacket_r++;
            btsco.pRX->uPcmBuf_r=0;
         }
         else
         {  //cvsd buffer empty
            return;
         }
      }
      for(iCount = 0 ; iCount < 2 ; iCount++)
      {
         kal_uint32 uInByte=0, uOutByte=0, uConsumeByte=0, uTotalSpace=0;
         kal_uint8 *pOutBuf;
         btsco_GetWriteBuffer_RX(&pOutBuf, &uOutByte);
         uTotalSpace = btsco_GetFreeSpace_RX();
         kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_RX_RAW, uOutByte, uTotalSpace, btsco.pRX->uPcmBuf_r);
         uOutByte = BT_SCO_CheckByte(BT_SCO_LINK_RX_ONLY, uOutByte);
         if( (btsco.pRX->uChannelNumber==1 && uOutByte<2) || (btsco.pRX->uChannelNumber==2 && uOutByte<4) )
         {  //output buffer is empty
            return;
         }
         if(btsco.pRX->fEnableSRC2)
         {  //output is not 8k mono
#if defined(__DISABLE_BLISRC__)
            ASSERT(0);
#else
            uInByte = SCO_RX_PCM8K_BUF_SIZE - btsco.pRX->uPcmBuf_r;
            uConsumeByte = BLI_Convert(btsco.pRX->pSRCHandle_2, (short *)(btsco.pRX->PcmBuf_8k + btsco.pRX->uPcmBuf_r), &uInByte, (short *)pOutBuf, &uOutByte);  
#endif
         }
         else
         {  //output is 8k mono
            uConsumeByte = SCO_RX_PCM8K_BUF_SIZE - btsco.pRX->uPcmBuf_r;    
            if(uConsumeByte>uOutByte)
            {
               uConsumeByte = uOutByte;
            }
            memcpy(pOutBuf, (btsco.pRX->PcmBuf_8k + btsco.pRX->uPcmBuf_r), uConsumeByte);
            uOutByte = uConsumeByte;
         }
         btsco.pRX->uPcmBuf_r += uConsumeByte;
         btsco_WriteDataDone_RX(uOutByte);
         if(SCO_RX_PCM8K_BUF_SIZE == btsco.pRX->uPcmBuf_r)
         {
            break;
         }
      }
   }
}

static void btsco_process(void *pData)
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROCESS, btsco.uState, btsco.pRX, btsco.pTX);
   if(btsco.uState != BT_SCO_STATE_RUNNING)
   {
      return;
   }
   if(btsco.pRX)
   {
      btsco_process_RX_CVSD();
      if(btsco.pRX->pCallback)
      {
         btsco.pRX->pCallback(btsco.pRX->pUserData);
      }
   }
   if(btsco.pTX)
   {
      btsco_process_TX_CVSD();
      if(btsco.pTX->pCallback)
      {
         btsco.pTX->pCallback(btsco.pTX->pUserData);
      }
   }
}

//=============================================================================================
//    BT SCO Export Interface
//=============================================================================================

void BT_SCO_GetReadBuffer_RX(kal_uint8 **pBuf, kal_uint32 *pLen)
{
   ASSERT(btsco.pRX->RingBuffer.rb_base);
   rbGetReadBuffer(&btsco.pRX->RingBuffer, pBuf, pLen);
}

void BT_SCO_ReadDataDone_RX(kal_uint32 uLen)
{
   ASSERT(btsco.pRX->RingBuffer.rb_base);
   rbReadDataDone(&btsco.pRX->RingBuffer, uLen);
}

kal_int32 BT_SCO_GetDataCount_RX()
{
   ASSERT(btsco.pRX->RingBuffer.rb_base);
   rbGetDataCount(&btsco.pRX->RingBuffer);
}

void BT_SCO_GetWriteBuffer_TX(kal_uint8 **pBuf, kal_uint32 *pLen)
{
   ASSERT(btsco.pTX->RingBuffer.rb_base);
   rbGetWriteBuffer(&btsco.pTX->RingBuffer, pBuf, pLen);
}

void BT_SCO_WriteDataDone_TX(kal_uint32 uLen)
{
   ASSERT(btsco.pTX->RingBuffer.rb_base);
   rbWriteDataDone(&btsco.pTX->RingBuffer, uLen);
}

kal_int32 BT_SCO_GetFreeSpace_TX()
{
   ASSERT(btsco.pTX->RingBuffer.rb_base);
   rbGetFreeSpace(&btsco.pTX->RingBuffer);
}

void *BT_SCO_GetUserData(BT_SCO_LINK uLink)
{
   if(uLink==BT_SCO_LINK_TX_ONLY && btsco.pTX)  
   {
      return btsco.pTX->pUserData;
   }
   else if(uLink==BT_SCO_LINK_RX_ONLY && btsco.pRX)  
   {
      return btsco.pRX->pUserData;
   }
   return 0;
}

kal_uint32 BT_SCO_GetChannelNumber(BT_SCO_LINK uLink)
{
   if(uLink==BT_SCO_LINK_TX_ONLY && btsco.pTX)  
   {
      return (kal_uint32)(btsco.pTX->uChannelNumber);
   }
   else if(uLink==BT_SCO_LINK_RX_ONLY && btsco.pRX)  
   {
      return (kal_uint32)(btsco.pRX->uChannelNumber);
   }
   return 0;
}

kal_uint32 BT_SCO_CheckByte(BT_SCO_LINK uLink, kal_uint32 uPcmByte)
{
   kal_uint32 uChannelNumber = BT_SCO_GetChannelNumber(uLink);
   if(uChannelNumber==1)
   {
      return (uPcmByte & 0xFFFFFFFE);
   }
   else
   {
      return (uPcmByte & 0xFFFFFFFC);
   }
}

Media_Status BT_SCO_SetCallback_TX(void(*pCallback)( void *pData ), void *pData, kal_uint32 uSampleRate, kal_uint32 uChannelNumber, kal_uint32 uEnableFilter)
{
   memset(btsco.pTX, 0, sizeof(BT_SCO_TX));
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_SET_TX, btsco.uState, uSampleRate, uChannelNumber, uEnableFilter, pCallback);
   return btsco_SetHandle(pCallback, pData, uSampleRate, uChannelNumber, uEnableFilter, 1);
}

Media_Status BT_SCO_SetCallback_RX(void(*pCallback)( void *pData ), void *pData, kal_uint32 uSampleRate, kal_uint32 uChannelNumber, kal_uint32 uEnableFilter, kal_uint32 uEnablePLC)
{
   memset(btsco.pRX, 0, sizeof(BT_SCO_RX));
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_SET_RX, btsco.uState, uSampleRate, uChannelNumber, uEnableFilter, uEnablePLC, pCallback);
   if(uSampleRate == 8000 && uEnablePLC)
   {
      btsco.pRX->fEnablePLC = 1;
   }
   return btsco_SetHandle(pCallback, pData, uSampleRate, uChannelNumber, uEnableFilter, 0);
}

void BT_SCO_Start()
{
   kal_uint32 uTotalMemory = 0;
   kal_uint8  *pBuf = NULL;
   ASSERT(btsco.uState==BT_SCO_STATE_READY);   
   if(btsco.pTX)
   {
      uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PCM_RINGBUF_TX);
      uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_ENCODE);
      uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_TX_SRC);
      if(btsco.pTX->fEnableFilter)
      {
         uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_FILTER_TX);
      }
   }
   if(btsco.pRX)
   {
      uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PCM_RINGBUF_RX);
      uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_DECODE);
      uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_RX_SRC1);
      if(btsco.pRX->fEnableFilter)
      {
         uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_FILTER_RX);
      }
      if(btsco.pRX->fEnablePLC)
      {
         uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PLC);
      }
      if(btsco.pRX->fEnableSRC2)
      {
         uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_RX_SRC2);
      }
   }
   btsco.pWorkingMemory = pBuf = (kal_uint8 *)audio_alloc_mem_cacheable(uTotalMemory);                 
   ASSERT(btsco.pWorkingMemory);   
   if(btsco.pTX)
   {
      btsco_InitialModule(BT_SCO_MOD_CVSD_ENCODE, pBuf);
      pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_ENCODE);
      btsco_InitialModule(BT_SCO_MOD_CVSD_TX_SRC, pBuf);
      pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_TX_SRC);
      btsco_InitialModule(BT_SCO_MOD_PCM_RINGBUF_TX, pBuf);
      pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PCM_RINGBUF_TX);
      if(btsco.pTX->fEnableFilter)
      {
         btsco_InitialModule(BT_SCO_MOD_FILTER_TX, pBuf);
         pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_FILTER_TX);
      }
   }
   if(btsco.pRX)
   {
      btsco_InitialModule(BT_SCO_MOD_CVSD_DECODE, pBuf);
      pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_DECODE);
      btsco_InitialModule(BT_SCO_MOD_CVSD_RX_SRC1, pBuf);
      pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_RX_SRC1);
      btsco_InitialModule(BT_SCO_MOD_PCM_RINGBUF_RX, pBuf);
      pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PCM_RINGBUF_RX);
      if(btsco.pRX->fEnableFilter)
      {
         btsco_InitialModule(BT_SCO_MOD_FILTER_RX, pBuf);
         pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_FILTER_RX);
      }
      if(btsco.pRX->fEnablePLC)
      {
         btsco_InitialModule(BT_SCO_MOD_PLC, pBuf);
         pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PLC);
      }
      if(btsco.pRX->fEnableSRC2)
      {
         btsco_InitialModule(BT_SCO_MOD_CVSD_RX_SRC2, pBuf);
         pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_RX_SRC2);
      }
   }
   btsco.uAudId = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( btsco.uAudId, btsco_process );
   btsco.uState=BT_SCO_STATE_RUNNING;
    //EINT_SW_Debounce_Modify(BT_EINT, 1);
    //EINT_Registration(BT_EINT, KAL_TRUE, KAL_FALSE, btsco_hisr, KAL_TRUE ); //auto unmask
   //EINT_Set_HW_Debounce(BT_EINT, 3);
   //EINT_Registration(BT_EINT, KAL_FALSE, KAL_FALSE, btsco_hisr, KAL_TRUE ); //auto unmask
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_START, btsco.uState);
}


void BT_SCO_Open(BT_SCO_MODE uMode, BT_SCO_LINK uLink)
{
   kal_uint32 uTxMemSize = 0, uRxMemSize = 0;
   kal_uint8 *pAllocMemory;
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_OPEN, btsco.uState, uMode, uLink);
   ASSERT(btsco.uState == BT_SCO_STATE_IDLE);
   if(uLink == BT_SCO_LINK_TX_ONLY || uLink == BT_SCO_LINK_BOTH)
   {
      uTxMemSize += (sizeof(BT_SCO_TX)+3)& ~0x3;
   }
   if(uLink == BT_SCO_LINK_RX_ONLY || uLink == BT_SCO_LINK_BOTH)
   {
      uRxMemSize += (sizeof(BT_SCO_RX)+3)& ~0x3;
   } 

   if (uTxMemSize+uRxMemSize+BT_SCO_PACKET_180 > 2048)
   {
      btsco.pStructMemory = pAllocMemory = (kal_uint8 *)audio_alloc_mem_cacheable(uTxMemSize+uRxMemSize+BT_SCO_PACKET_180);
      btsco.fIsStructMemoryOnMED = KAL_TRUE;
   }
   else
   {
      btsco.pStructMemory = pAllocMemory = (kal_uint8 *)get_ctrl_buffer( uTxMemSize+uRxMemSize+BT_SCO_PACKET_180 );
      memset(pAllocMemory, 0, uTxMemSize+uRxMemSize+BT_SCO_PACKET_180);
   }
   
   ASSERT(pAllocMemory);
   if(uLink == BT_SCO_LINK_TX_ONLY || uLink == BT_SCO_LINK_BOTH)
   {
      btsco.pTX = (BT_SCO_TX*)pAllocMemory;
      pAllocMemory += uTxMemSize;
   }
   if(uLink == BT_SCO_LINK_RX_ONLY || uLink == BT_SCO_LINK_BOTH)
   {
      btsco.pRX = (BT_SCO_RX*)pAllocMemory;
      pAllocMemory += uRxMemSize;
   } 
   btsco.pTempPacketBuf = (kal_uint8 *)pAllocMemory;
   btsco.uState = BT_SCO_STATE_INIT;
}

void BT_SCO_Stop()
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_STOP, btsco.uState);
   ASSERT(btsco.uState == BT_SCO_STATE_RUNNING);
   btsco.uState = BT_SCO_STATE_ENDING;
   kal_sleep_task(10); //flush zero (22.5*2 msec) 
   //EINT_Mask(BT_EINT); 
   L1Audio_FreeAudioID( btsco.uAudId );
   btsco_DestroyModule();
   audio_free_mem( (void **) &btsco.pWorkingMemory);
   btsco.uState = BT_SCO_STATE_INIT;
   btsco.uAudId = 0;
   btsco.pWorkingMemory = NULL;
}

void BT_SCO_Close()
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_CLOSE, btsco.uState);
   ASSERT(btsco.uState == BT_SCO_STATE_INIT);

   if (btsco.fIsStructMemoryOnMED)
      audio_free_mem( (void **) &btsco.pStructMemory);
   else
      free_ctrl_buffer(btsco.pStructMemory);

   btsco.pStructMemory = NULL;
   btsco.pTempPacketBuf = NULL;
   btsco.pTX = NULL;
   btsco.pRX = NULL;
   btsco.uState = BT_SCO_STATE_IDLE;
   btsco.fIsStructMemoryOnMED = KAL_FALSE;
}

void BT_SCO_Init()
{
   EINT_Set_HW_Debounce(BT_EINT, 3);
   EINT_Registration(BT_EINT, KAL_FALSE, KAL_FALSE, btsco_hisr, KAL_TRUE ); //auto unmask
   btsco.is_cordless_on = KAL_FALSE;
}

void BT_SCO_Mute(kal_bool fMute)
{
   btsco.fMute = fMute;
}

//=============================================================================================
//    CVSD Loopback for HQA
//=============================================================================================

#if defined(__CVSD_LOOPBACK_TEST__)

#include "med_utility.h"
#include "fsal.h"

#define CVSD_LOOPBACK_DATA_BUFFER_SIZE  (18000 ) //should be muliple of 120 and 180
#define CVSD_LOOPBACK_FSAL_BUFFER_SIZE  (1024  )

static struct {
   STFSAL       FileHandle; 
   kal_uint8    *pDataBuffer;
   kal_uint8    *pFSALBuffer;
   kal_uint32   uCurrentRead;
   kal_uint32   uCurrentWrite;
   kal_char     filename[40];   
   kal_uint32   uTotalPacket;
   kal_uint32   uLostPacket;
   kal_uint32   uErrorCnt;

}cvsd_record;

static struct {
   STFSAL       FileHandle; 
   kal_uint8    *pDataBuffer;
   kal_uint8    *pFSALBuffer;
   kal_char     filename[40];   
   kal_uint32   uCurrentRead;
   kal_uint32   uCurrentWrite;
   kal_uint32   uFileOffset;
   kal_uint32   uFileSize;
   kal_uint32   uErrorCnt;
}cvsd_playback;

static struct{
   kal_uint8    uPacketType; 
   kal_uint8    uDataLength; 
   kal_bool     fWaiting;
   kal_bool     fEOF;
   kal_bool     fRuning;
   kal_uint32   uState;
}cvsd_loopback;

static kal_uint32 CVSD_Loopback_ReadFile(kal_uint8 *pBuf, kal_uint32 uReadBytes)
{
   FSAL_Status uStatus;
   if(cvsd_playback.uFileOffset + uReadBytes < cvsd_playback.uFileSize)
   {
      FSAL_Seek( &cvsd_playback.FileHandle, cvsd_playback.uFileOffset);
      uStatus = FSAL_Read_Bytes( &cvsd_playback.FileHandle, pBuf, uReadBytes);
      ASSERT(uStatus == FSAL_OK);
      cvsd_playback.uFileOffset += uReadBytes;
      return uReadBytes;
   }
   return 0;
}

static void CVSD_Loopback_Stop_InMed(kal_uint32 arg1, void* arg2)
{
   FSAL_Status uStatus;
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_STOP_MED,cvsd_record.uLostPacket, cvsd_record.uTotalPacket);
   if(cvsd_loopback.fRuning)
   {
      EINT_Mask(BT_EINT); 
      cvsd_loopback.fRuning = KAL_FALSE;
      uStatus = FSAL_Close( &cvsd_record.FileHandle );
      ASSERT( FSAL_OK == uStatus );
      uStatus = FSAL_Close( &cvsd_playback.FileHandle );
      ASSERT( FSAL_OK == uStatus );
      audio_free_mem( (void **)&cvsd_record.pDataBuffer );
   }
}

static void CVSD_Loopback_Callback(kal_uint32 arg1, void* arg2)
{   
   if(!cvsd_loopback.fRuning)
   {
      kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_CALLBACK_1, cvsd_loopback.fRuning);
      return;
   }
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_CALLBACK_2, cvsd_playback.uCurrentWrite, cvsd_playback.uCurrentRead, cvsd_record.uCurrentWrite, cvsd_record.uCurrentRead );

   //RX
   while( cvsd_record.uCurrentRead < cvsd_record.uCurrentWrite )
   {
      FSAL_Status uStatus;
      uStatus = FSAL_Write( &cvsd_record.FileHandle, &cvsd_record.pDataBuffer[ cvsd_record.uCurrentRead % CVSD_LOOPBACK_DATA_BUFFER_SIZE ] , cvsd_loopback.uDataLength );
      ASSERT( FSAL_OK == uStatus );
      cvsd_record.uCurrentRead += cvsd_loopback.uDataLength;
   }

   //TX
   if(!cvsd_loopback.fEOF)
   {
      while(CVSD_LOOPBACK_DATA_BUFFER_SIZE - ( cvsd_playback.uCurrentWrite - cvsd_playback.uCurrentRead) )
      {
         kal_uint32 uReadLength = 0;
         uReadLength = CVSD_Loopback_ReadFile(&cvsd_playback.pDataBuffer[ cvsd_playback.uCurrentWrite % CVSD_LOOPBACK_DATA_BUFFER_SIZE ], cvsd_loopback.uDataLength );
         if(uReadLength==0)
         {
            cvsd_loopback.fEOF = KAL_TRUE;
            L1Audio_InProcCall(CVSD_Loopback_Stop_InMed, NULL, NULL);
            break;
         }
         cvsd_playback.uCurrentWrite += cvsd_loopback.uDataLength;
      }
   }
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_CALLBACK_3, cvsd_playback.uCurrentWrite, cvsd_playback.uCurrentRead, cvsd_record.uCurrentWrite, cvsd_record.uCurrentRead );
   cvsd_loopback.fWaiting = KAL_FALSE;
}

static void CVSD_Loopback_hisr(void *pData)
{
   kal_uint32 uPacketType, uPacketNumber, uPacketLength, uBufferCount_TX, uBufferCount_RX, uControl, uDataLength, i;
   kal_uint8 *pSrc, *pDst;
   if(!cvsd_loopback.fRuning)
   {
      kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_HISR_1, cvsd_loopback.fRuning);
      return;
   }
   uControl = *BT_SCO_HW_REG_CONTROL;
   pSrc = (kal_uint8 *)(BTSRAM_BASE + *BT_SCO_HW_REG_PACKET_R);
   pDst = (kal_uint8 *)(BTSRAM_BASE + *BT_SCO_HW_REG_PACKET_W);
   uPacketType = (uControl >> 18) & 0x7;
   ASSERT(uPacketType < BT_SCO_CVSD_MAX);
   uPacketLength   = (kal_uint32)btsco_PacketInfo[uPacketType][0];
   uPacketNumber   = (kal_uint32)btsco_PacketInfo[uPacketType][1];
   uBufferCount_TX = (kal_uint32)btsco_PacketInfo[uPacketType][2];
   uBufferCount_RX = (kal_uint32)btsco_PacketInfo[uPacketType][3];
   cvsd_loopback.uPacketType = uPacketType;
   cvsd_loopback.uDataLength = uDataLength = uPacketNumber*uPacketLength;
   ASSERT(cvsd_record.uCurrentWrite >= cvsd_record.uCurrentRead);
   ASSERT(cvsd_playback.uCurrentWrite >= cvsd_playback.uCurrentRead);
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_HISR_2, uPacketType, uControl, pDst, pSrc);
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_HISR_3, cvsd_playback.uCurrentWrite, cvsd_playback.uCurrentRead, cvsd_record.uCurrentWrite, cvsd_record.uCurrentRead );
   if( ((uControl>>31) & 1) == 0)
   {
      return;
   }
   else
   {
      *BT_SCO_HW_REG_CONTROL &= ~BT_CVSD_INTERRUPT;
   }

   //RX
   if( CVSD_LOOPBACK_DATA_BUFFER_SIZE - (cvsd_record.uCurrentWrite - cvsd_record.uCurrentRead) >= uDataLength )
   {
      btsco_DataTransfer(BT_SCO_DIRECT_BT2ARM, pSrc, &cvsd_record.pDataBuffer[ cvsd_record.uCurrentWrite % CVSD_LOOPBACK_DATA_BUFFER_SIZE ], uPacketLength, uPacketNumber );
      //cvsd_record.uCurrentWrite += uDataLength;
      for(i=0;i<uPacketNumber;i++)
      {
         cvsd_record.uTotalPacket++;
         if( ((uControl>>i)&1) == 0)
         {
            cvsd_record.uLostPacket++;
            if(cvsd_record.pDataBuffer[ cvsd_record.uCurrentWrite % CVSD_LOOPBACK_DATA_BUFFER_SIZE ] == 0x55)
            {
               kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_RX_PACKET_LOST, cvsd_record.uLostPacket, cvsd_record.uTotalPacket);
            }
            else
            {
               kal_brief_trace(TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_RX_CRC_ERROR, cvsd_record.uLostPacket, cvsd_record.uTotalPacket);
               memset(&cvsd_record.pDataBuffer[ cvsd_record.uCurrentWrite % CVSD_LOOPBACK_DATA_BUFFER_SIZE ], 0x55, uPacketLength);
            }
         }
         cvsd_record.uCurrentWrite += uPacketLength;
      }
   }
   else
   {
      cvsd_record.uErrorCnt++;
      kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_RX_OVERFLOW, cvsd_record.uErrorCnt);
   }

   //TX
   if(cvsd_playback.uCurrentWrite - cvsd_playback.uCurrentRead >= uDataLength )
   {
      btsco_DataTransfer(BT_SCO_DIRECT_ARM2BT, &cvsd_playback.pDataBuffer[ cvsd_playback.uCurrentRead % CVSD_LOOPBACK_DATA_BUFFER_SIZE ], pDst, uPacketLength, uPacketNumber );
      cvsd_playback.uCurrentRead += uDataLength;
   }
   else
   {
      cvsd_playback.uErrorCnt++;
      kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_TX_UNDERFLOW, cvsd_playback.uErrorCnt);
   }
   /*
   for(i=0;i<uPacketNumber;i++)
   {
      cvsd_record.uTotalPacket++;
      if( ((uControl>>i)&1) == 0)
      {
         cvsd_record.uLostPacket++;
         kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_RX_PACKET_LOST, cvsd_record.uLostPacket, cvsd_record.uTotalPacket);
      }
   }
   */
   *BT_SCO_HW_REG_CONTROL &= ~BT_CVSD_CLEAR;
   if(!cvsd_loopback.fWaiting)
   {
      L1Audio_InProcCall(CVSD_Loopback_Callback, NULL, NULL);
      cvsd_loopback.fWaiting = KAL_TRUE;
   }
}

static kal_bool CVSD_Loopback_Open_File()
{
   kal_wchar filename_rec[40];
   kal_wchar filename_ply[40];
   kal_int16 drv_letter;
   if(L1Audio_GetDebugInfo(5)==0)  //SD card
   {
      kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_OPEN_FILE_SD);
      drv_letter = FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );
   }
   else
   {
      kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_OPEN_FILE_INTERNAL);
      drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);    
   }
   kal_wsprintf( filename_ply, "%c:\\%s", drv_letter, cvsd_playback.filename );
   kal_wsprintf( filename_rec, "%c:\\%s", drv_letter, cvsd_record.filename );
   if( FSAL_OK != FSAL_Open( &cvsd_record.FileHandle, filename_rec, FSAL_WRITE ) )
   {
      kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_OPEN_FILE_FAIL_REC);
      return KAL_FALSE;
   }
   if( FSAL_OK != FSAL_Open( &cvsd_playback.FileHandle, filename_ply, FSAL_READ ) )
   {
      kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_OPEN_FILE_FAIL_PLAY);
      return KAL_FALSE;
   }
  return KAL_TRUE;
}

static void CVSD_Loopback_Start_InMed(kal_uint32 arg1, void* arg2)
{
   kal_uint32 uReadLength;
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_START_MED, cvsd_loopback.fRuning);
   ASSERT(!cvsd_loopback.fRuning);
   cvsd_record.pDataBuffer = (kal_uint8 *)audio_alloc_mem_cacheable(2*CVSD_LOOPBACK_DATA_BUFFER_SIZE + 2*CVSD_LOOPBACK_FSAL_BUFFER_SIZE);  
   cvsd_playback.pDataBuffer = cvsd_record.pDataBuffer   + CVSD_LOOPBACK_DATA_BUFFER_SIZE;
   cvsd_record.pFSALBuffer   = cvsd_playback.pDataBuffer + CVSD_LOOPBACK_DATA_BUFFER_SIZE;
   cvsd_playback.pFSALBuffer = cvsd_record.pFSALBuffer   + CVSD_LOOPBACK_FSAL_BUFFER_SIZE;
   ASSERT(cvsd_record.pDataBuffer);
   FSAL_SetBuffer( &cvsd_record.FileHandle  , CVSD_LOOPBACK_FSAL_BUFFER_SIZE, cvsd_record.pFSALBuffer );   
   FSAL_SetBuffer( &cvsd_playback.FileHandle, CVSD_LOOPBACK_FSAL_BUFFER_SIZE, cvsd_playback.pFSALBuffer );   
   if( KAL_FALSE == CVSD_Loopback_Open_File() )
   {
      audio_free_mem( (void **)&cvsd_record.pDataBuffer );
      return;   
   }
   FSAL_GetFileSize(&cvsd_playback.FileHandle, &cvsd_playback.uFileSize);
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_FILE_SIZE, cvsd_playback.uFileSize);
   uReadLength = CVSD_Loopback_ReadFile(&cvsd_playback.pDataBuffer[ cvsd_playback.uCurrentWrite % CVSD_LOOPBACK_DATA_BUFFER_SIZE ], CVSD_LOOPBACK_DATA_BUFFER_SIZE );
   ASSERT(!cvsd_loopback.fEOF);
   ASSERT(uReadLength == CVSD_LOOPBACK_DATA_BUFFER_SIZE);
   cvsd_playback.uCurrentWrite += CVSD_LOOPBACK_DATA_BUFFER_SIZE;
   cvsd_loopback.fRuning = KAL_TRUE;
   EINT_Mask(BT_EINT); 
   //EINT_SW_Debounce_Modify(BT_EINT, 1);
   //EINT_Registration(BT_EINT, KAL_TRUE, KAL_FALSE, CVSD_Loopback_hisr, KAL_TRUE ); //auto unmask
   EINT_Set_HW_Debounce(BT_EINT, 3);
   EINT_Registration(BT_EINT, KAL_FALSE, KAL_FALSE, CVSD_Loopback_hisr, KAL_TRUE ); //auto unmask
}

void CVSD_Loopback_Start(kal_char *play_filename , kal_char *record_filename)
{
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_START, cvsd_loopback.fRuning);
   ASSERT(!cvsd_loopback.fRuning);
   memset(&cvsd_record  , 0, sizeof(cvsd_record));
   memset(&cvsd_playback, 0, sizeof(cvsd_playback));
   memset(&cvsd_loopback, 0, sizeof(cvsd_loopback));
   strcpy(cvsd_playback.filename, play_filename);
   strcpy(cvsd_record.filename, record_filename);
   L1Audio_InProcCall(CVSD_Loopback_Start_InMed, NULL, NULL); 
}

void CVSD_Loopback_Stop()
{
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_LB_STOP, cvsd_loopback.fRuning);
   L1Audio_InProcCall(CVSD_Loopback_Stop_InMed, NULL, NULL); 
}

#endif //__CVSD_LOOPBACK_TEST__

void BT_SCO_Set_Cordless_On(kal_bool is_cordless_on)
{
    btsco.is_cordless_on = is_cordless_on;
    return;
}

kal_bool BT_SCO_Is_Cordless_On(void)
{
    return btsco.is_cordless_on;
}

#endif //__CVSD_CODEC_SUPPORT__

