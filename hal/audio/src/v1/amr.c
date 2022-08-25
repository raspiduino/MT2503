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
 * amr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   AMR/AMR-WB codec driver, the storage format is used for
 *   storing AMR/AMR-WB speech frames in a file for sending via MMS.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "l1d_reg.h"

#include "media.h"
#include "audio_def.h"
#include "speech_def.h"
#include "l1audio.h"
#include "ddload.h"
#include "speech_enh_def.h"

#if defined(AMR_CODEC)

#include "amr_table.h"
#include "am.h"
#include "afe.h"
#include "vmi.h"

#define DSP_IDLE                     0
#define DSP_INITIALIZED              1
#define DSP_PLAYING                  2
#define DSP_RECORDING                2
#define DSP_STOP                     3

#define DEBUG_AMR_RAM_FILE 0
#define DEBUG_AMR_ROM_FILE 0
#define DEBUG_AMR_DSP 0

/* Turn on these only when determining the most appropriate size of the ring buffer */
#define AMR_CHECK_BUFFER_UNDERFLOW 0
#define AMR_CHECK_BUFFER_OVERFLOW 0

#define AMR_WRITE_FILE_HEADER 0
#define AMR_READ_FILE_HEADER 0

#define AMR_STATE_RECORD 1
#define AMR_STATE_RECORD_PAUSE 2
#define AMR_STATE_PLAY 3
#define AMR_STATE_PLAY_PAUSE 4
#define AMR_STATE_STOP 5

#if (defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H) ) && defined( AMRWB_ENCODE )
 #error should not release WB-AMR record on MT6251
#endif 

static kal_uint16 Tx_ordering_buffer[30];
static kal_uint16 Tx_data_buffer[30];

/* Note: can't record with odd frame length, unless modify ring buffer mechanism in media.c */

static struct{
   mediaControl   *ctrl;
   kal_uint8      state;
   kal_uint16     wType;
   kal_uint8      bCodecMode; /* Codec Mode for DSP Sherif Setting */
   kal_bool       bWideBand;
   kal_uint32     uRecordOverflowCount; /* number of frames that is waiting to be put into ring buffer */
   kal_bool       bOddFlag;
   kal_uint8      bOddData; /* buffers/store one byte when read/write from/to ring buffer */
   kal_bool       dedicated_mode;
#if DEBUG_AMR_RAM_FILE
   kal_uint8      bRamFileBuffer[80000];
   kal_uint32     uRamFileOffset;
#endif
} amr;

int amrGetDataCount( void )
{
   int32 count;

   count = (int32)amr.ctrl->write - (int32)amr.ctrl->read;
   if( count < 0 )
      count += amr.ctrl->rb_size;
   count <<= 1;
   if ( amr.bOddFlag == KAL_TRUE )
      count++;
   return count;
}

void media_buffer_put_byte(kal_uint8 bData) {
#if DEBUG_AMR_RAM_FILE
   if (amr.uRamFileOffset<sizeof(amr.bRamFileBuffer)) {
     amr.bRamFileBuffer[amr.uRamFileOffset++] = bData;
     amr.ctrl->write = (amr.uRamFileOffset+1)/2;
   }
#else
   if (amr.bOddFlag == KAL_TRUE) {
      kal_uint16 wVal;
      wVal = amr.bOddData | bData<<8;
      if( amr.ctrl->read > amr.ctrl->write ) {
         if( amr.ctrl->read - amr.ctrl->write > 1 )
            amr.ctrl->rb_base[amr.ctrl->write++] = wVal;
         else
            ASSERT(KAL_FALSE); /* media buffer overflow */
      } else if( amr.ctrl->read == 0 ) {
         if( amr.ctrl->rb_size - amr.ctrl->write > 1 )
            amr.ctrl->rb_base[amr.ctrl->write++] = wVal;
         else
            ASSERT(KAL_FALSE); /* media buffer overflow */
      } else {
         amr.ctrl->rb_base[amr.ctrl->write++] = wVal;
         if( amr.ctrl->write == amr.ctrl->rb_size )
            amr.ctrl->write = 0;
      }
      amr.bOddFlag = KAL_FALSE;
      return;
   } else if (amr.bOddFlag == KAL_FALSE) {
      amr.bOddData = bData;
      amr.bOddFlag = KAL_TRUE;
      return;
   }
#endif
}

/* to trigger the update of write pointer, so that
the last byte can be recorded */
void media_buffer_flush()
{
   if (amr.bOddFlag == KAL_TRUE) {
      media_buffer_put_byte(0x7C); /* 'no-data' frame */
   }
}

void media_buffer_put_2bytes(kal_uint16 wData)
{
   media_buffer_put_byte((kal_uint8)(wData & 0xFF));
   media_buffer_put_byte((kal_uint8)(wData >> 8));
}

void media_buffer_put_nbytes(kal_uint8 *pBuf, int n) {
   int i=0;
   ASSERT(pBuf!=NULL);
   while(n-->0) {
      media_buffer_put_byte(pBuf[i++]);
   }
}

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_AMRREC_ROCODE", rodata = "DYNAMIC_CODE_AMRREC_RODATA"
#endif
static void amr_bit_ordering_sherif_to_file(kal_uint8 bTxType, kal_uint8 bFrameType, kal_uint16* pInData, kal_uint16* pOutData, kal_uint16 wLenBits)
{
   kal_uint16 i, k, p, q;

   k = 0;
#if defined( AMRWB_ENCODE ) && !defined( __AMRWB_SW_ENCODE__ )
   if (KAL_TRUE == amr.bWideBand) {
      const kal_uint16* pOrderingTable = tblAMR_WBOrder[bFrameType];
      for(i=0,p=0,q=0;i<wLenBits;i++) {
         if (bTxType==2) { /* Speech */
      	    k = (kal_uint16)pOrderingTable[i];
         } else if (bTxType==3) { /* SID first or SID update */
            k=i;
         } else {ASSERT(KAL_FALSE);}
         pOutData[q] |= (pInData[k/16] & AMR_get_tab[k%16]) ? AMR_ord_tab[p] : 0;
         if(++p==16) {  p=0; q++; }
      }
   } else
#endif
   {
      const kal_uint8* pOrderingTable = tblAMROrder[bFrameType];
      for(i=0,p=0,q=0;i<wLenBits;i++) {
         if (bTxType==2) { /* Speech */
      	    k = (kal_uint16)pOrderingTable[i];
         } else if (bTxType==3) { /* SID first or SID update */
            k=i;
         } else {ASSERT(KAL_FALSE);}
         pOutData[q] |= (pInData[k/16] & AMR_get_tab[k%16]) ? AMR_ord_tab[p] : 0;
         if(++p==16) {  p=0; q++; }
      }
   }
}

void amrRecordHisr( void )
{
   kal_uint32 uRBFreeCount;
   volatile kal_uint16 *pwSherifAddr;
   kal_uint8    FT, bCodecMode, Tx_Type;
   kal_uint16   uLenSpeechInSherif, i;
   kal_uint16   rd_bits,rd_bytes;

   FT = 0; 
   bCodecMode = 0;
   Tx_Type = 0;
   /**
    * Stop recording immediately after MMI commands Media_Stop.
    * In case that user is recodring while an incoming call comes in,
    * traffic channel will be corrupted, and can not continue to perform
    * recording normally.
    */
   if (amr.state != AMR_STATE_RECORD)
      return;

   if(Media_IsRecordSilence())
   {
      if (amr.bWideBand == KAL_TRUE) {
         media_buffer_put_byte(0x7C);
      } else {
         AM_GetSilencePattern(amr.wType, Tx_data_buffer);
         
         // bits ordering
         kal_mem_set(Tx_ordering_buffer, 0, sizeof(Tx_ordering_buffer));
         FT = 0x0A - amr.wType;
         rd_bits = lenSpeechBitsAMR[FT];
         rd_bytes = (rd_bits + 7)/8;
         
         amr_bit_ordering_sherif_to_file(2, FT, Tx_data_buffer, Tx_ordering_buffer, rd_bits);

         if (amr.ctrl->fTransmit) 
         {
            media_buffer_put_byte((kal_uint8)(FT<<4));
         } 
        
         /* put frame header to media buffer */
         media_buffer_put_byte((kal_uint8)((FT<<3) | (0x1<<2))); /* FT | FQI */
         
//         if (amr.ctrl->fTransmit) {
//            media_buffer_put_nbytes((kal_uint8*)Tx_data_buffer, rd_bytes);
//         } else {
            /* put ordering data to media buffer */
            media_buffer_put_nbytes((kal_uint8*)Tx_ordering_buffer, rd_bytes);
//         }
      }
      return;
   }

   /* check ring buffer fullness */
   uRBFreeCount = mediaGetFreeSpace(); /* in unit of words */
   if (uRBFreeCount>0)
      uRBFreeCount = uRBFreeCount * 2 - 1; /* in unit of bytes, -1 means potential pending byte in bOddData */

   /* put pending 'no-data' frame into ring buffer */
   if (amr.uRecordOverflowCount>0) {
      kal_uint32 uBytesToWrite;
      if (uRBFreeCount>=amr.uRecordOverflowCount) {
         uBytesToWrite = amr.uRecordOverflowCount;
         uRBFreeCount -= amr.uRecordOverflowCount;
         amr.uRecordOverflowCount = 0;
      } else {
      	 uBytesToWrite = uRBFreeCount;
      	 amr.uRecordOverflowCount -= uRBFreeCount;
      	 uRBFreeCount = 0;
      }
      for(i=0; i<uBytesToWrite; i++)
         media_buffer_put_byte(0x7C);
   }

   if (uRBFreeCount<61) { /* 8 bit frame header + max. 477 bits speech data */
      /* media buffer overflows */
#if AMR_CHECK_BUFFER_OVERFLOW
      /* If this happens, we have to enlarge the size of ring buffer. */
      ASSERT(KAL_FALSE);
#endif
      if(uRBFreeCount>1) {
         /* stuff 'no-data' frame */
         media_buffer_put_byte(0x7C);
      } else {
      	 amr.uRecordOverflowCount++;
      }
      return;
   }

#if DEBUG_AMR_DSP
   {
      kal_uint16 I, sc_mode;
      I = *DP_SC_MODE;
      sc_mode  = (I >> 8) & 0xFF;
      ASSERT_REBOOT((sc_mode>=0x20 && sc_mode<=0x28) || (sc_mode>=0x03 && sc_mode<=0x0A));
      I = *DP_AUDIO_PAR;
      if (amr.bWideBand) {
         ASSERT_REBOOT(I&0x08); /* check amr-wb flag has not been reset by other place */
      }
   }
#endif
#if defined(AMRWB_ENCODE) && !defined( __AMRWB_SW_ENCODE__ )
   if (amr.bWideBand == KAL_TRUE) {
      Tx_Type = *DP_AWB_TX_TCH_S0(0) & 0x0003;
      bCodecMode = ((*DP_AWB_SC_TCH_MODE) & 0xFF);
   } else
#endif
   {
      if (amr.dedicated_mode){
          Tx_Type = *DSP_TX_TCH_S(0,0) & 0x0003;
          bCodecMode = ((*DSP_SC_TCH_MODE >> 8) & 0x0F);
      } else {
          Tx_Type = *DSP_TX_TCH_S(0, 0) & 0x0003;
          bCodecMode = ((*DSP_TX_TCH_S(0, 17) >> 8) & 0x0F);
      }
   }

   /* get AMR frame type */
   if (bCodecMode>=0x03 && bCodecMode<=0x0A) {
      FT = 0x0A - bCodecMode;
   }
#if defined( AMRWB_ENCODE ) && !defined( __AMRWB_SW_ENCODE__ )
   else if (bCodecMode>=0x20 && bCodecMode<=0x28) {
      FT = bCodecMode - 0x20;
   }
#endif
   else {
      ASSERT(KAL_FALSE);
   }

   if (Tx_Type==0) { /* Tx_Type: No data */
      media_buffer_put_byte(0x7C);
      return;
   } else if (Tx_Type==1 || Tx_Type==3) { /* Tx_Type: SID First or SID Update */
      kal_uint16 SID_ord_buf[3];
      kal_uint16 SID_buffer[3];

      /* put SID frame header to media buffer */
      if (amr.bWideBand == KAL_TRUE) {
         media_buffer_put_byte(0x4C);
      } else {
         media_buffer_put_byte(0x44);
      }

      /* Get speech parameter bits */
#if defined( AMRWB_ENCODE ) && !defined( __AMRWB_SW_ENCODE__ )
      if (amr.bWideBand) {
      	 pwSherifAddr = DP_AWB_TX_TCH_S0(1);
      } else 
#endif
      {
         if(amr.dedicated_mode)
            pwSherifAddr = DSP_TX_TCH_S(0, 1);
         else
            pwSherifAddr = DSP_SD2_VM_1;
      }
      kal_mem_set(SID_buffer, 0, sizeof(SID_buffer));
      kal_mem_set(SID_ord_buf, 0, sizeof(SID_ord_buf));
      if (Tx_Type==3) { /* SID Update */
         
         for (i = 0; i < 3; i++ ) {
            SID_buffer[i] = *pwSherifAddr++;
         }
         amr_bit_ordering_sherif_to_file(Tx_Type, FT, SID_buffer, SID_ord_buf, 35);
         SID_ord_buf[2] |= AMR_ord_tab[3];  /* SID Type Indicator (STI) */
      }

      /* Mode Indication */
#if defined( AMRWB_ENCODE ) && !defined( __AMRWB_SW_ENCODE__ )
      if (amr.bWideBand == KAL_TRUE) {
         SID_ord_buf[2] |= (FT & 0x0008) ? AMR_ord_tab[4] : 0;
         SID_ord_buf[2] |= (FT & 0x0004) ? AMR_ord_tab[5] : 0;
         SID_ord_buf[2] |= (FT & 0x0002) ? AMR_ord_tab[6] : 0;
         SID_ord_buf[2] |= (FT & 0x0001) ? AMR_ord_tab[7] : 0;
      } else 
#endif
      {
         SID_ord_buf[2] |= (FT & 0x0001) ? AMR_ord_tab[4] : 0;
         SID_ord_buf[2] |= (FT & 0x0002) ? AMR_ord_tab[5] : 0;
         SID_ord_buf[2] |= (FT & 0x0004) ? AMR_ord_tab[6] : 0;
      }
      
      if (amr.ctrl->fTransmit) {
         media_buffer_put_nbytes((kal_uint8*)SID_buffer, 5);
      } else {
         media_buffer_put_nbytes((kal_uint8*)SID_ord_buf, 5);
      }
      return;
   } else if (Tx_Type==2) { /* TX_TYPE: SPEECH */
#if defined( AMRWB_ENCODE ) && !defined( __AMRWB_SW_ENCODE__ )
      if (amr.bWideBand == KAL_TRUE) {
         rd_bits = lenSpeechBitsAMR_WB[FT];
      } else
#endif
      {
         rd_bits = lenSpeechBitsAMR[FT];
      }
      rd_bytes = (rd_bits + 7)/8;
      uLenSpeechInSherif = (rd_bytes+1)/2;

      /* Get speech parameter bits */
#if defined( AMRWB_ENCODE ) && !defined( __AMRWB_SW_ENCODE__ )
      if (amr.bWideBand == KAL_TRUE){
         pwSherifAddr = DP_AWB_TX_TCH_S0( 1 );
         if ( uLenSpeechInSherif > 16) {//16 words from DP_AWB_TX_TCH_S0(1)
            for ( i = 0; i < 16; i++)
               Tx_data_buffer[i] = *pwSherifAddr++;
            pwSherifAddr = DP_AWB_TX_TCH_S17( 0 );
            for ( i = 16; i < uLenSpeechInSherif; i++ )
               Tx_data_buffer[i] = *pwSherifAddr++;
         }else
            for ( i = 0; i < uLenSpeechInSherif; i++ )
               Tx_data_buffer[i] = *pwSherifAddr++;
      }else
#endif
      {
         if(amr.dedicated_mode)
            pwSherifAddr = DSP_TX_TCH_S( 0, 1 );
         else
            pwSherifAddr = DSP_TX_TCH_S(0, 1);
         for (i=0; i<uLenSpeechInSherif; i++)
            Tx_data_buffer[i] = *pwSherifAddr++;
      }

      /* bits ordering */
      kal_mem_set(Tx_ordering_buffer, 0, sizeof(Tx_ordering_buffer));
      amr_bit_ordering_sherif_to_file(Tx_Type, FT, Tx_data_buffer, Tx_ordering_buffer, rd_bits);

      if (amr.ctrl->fTransmit) 
      {
         media_buffer_put_byte((kal_uint8)(FT<<4));
      } 

      /* put frame header to media buffer */
      media_buffer_put_byte((kal_uint8)((FT<<3) | (0x1<<2))); /* FT | FQI */

      
//      if (amr.ctrl->fTransmit) {
//         media_buffer_put_nbytes((kal_uint8*)Tx_data_buffer, rd_bytes);
//      } else {
         /* put ordering data to media buffer */
         media_buffer_put_nbytes((kal_uint8*)Tx_ordering_buffer, rd_bytes);
//      }
   } else {
      ASSERT(KAL_FALSE);
   }
}
#if defined(__VAD_SUPPORT__)

void amrBabyMonitorRecordHisr( void )
{
   kal_uint32 uRBFreeCount;
   volatile kal_uint16 *pwSherifAddr;
   kal_uint8    FT, bCodecMode, Tx_Type;
   kal_uint16   uLenSpeechInSherif, i;
   kal_uint16   rd_bits,rd_bytes;

   FT = 0; 
   bCodecMode = 0;
   Tx_Type = 0;
   /**
    * Stop recording immediately after MMI commands Media_Stop.
    * In case that user is recodring while an incoming call comes in,
    * traffic channel will be corrupted, and can not continue to perform
    * recording normally.
    */
   if (amr.state != AMR_STATE_RECORD)
      return;

   if(Media_IsRecordSilence())
   {
      AM_GetSilencePattern(amr.wType, Tx_data_buffer);
      
      // bits ordering
      kal_mem_set(Tx_ordering_buffer, 0, sizeof(Tx_ordering_buffer));
      FT = 0x0A - amr.wType;
      rd_bits = lenSpeechBitsAMR[FT];
      rd_bytes = (rd_bits + 7)/8;
      
      amr_bit_ordering_sherif_to_file(2, FT, Tx_data_buffer, Tx_ordering_buffer, rd_bits);

      /* put frame header to media buffer */
      media_buffer_put_byte((kal_uint8)((FT<<3) | (0x1<<2))); /* FT | FQI */
      
      if (amr.ctrl->fTransmit) {
         media_buffer_put_nbytes((kal_uint8*)Tx_data_buffer, rd_bytes);
      } else {
         /* put ordering data to media buffer */
         media_buffer_put_nbytes((kal_uint8*)Tx_ordering_buffer, rd_bytes);
      }
      return;
   }

   /* check ring buffer fullness */
   uRBFreeCount = mediaGetFreeSpace(); /* in unit of words */
   if (uRBFreeCount>0)
      uRBFreeCount = uRBFreeCount * 2 - 1; /* in unit of bytes, -1 means potential pending byte in bOddData */

   /* put pending 'no-data' frame into ring buffer */
   if (amr.uRecordOverflowCount>0) {
      kal_uint32 uBytesToWrite;
      if (uRBFreeCount>=amr.uRecordOverflowCount) {
         uBytesToWrite = amr.uRecordOverflowCount;
         uRBFreeCount -= amr.uRecordOverflowCount;
         amr.uRecordOverflowCount = 0;
      } else {
      	 uBytesToWrite = uRBFreeCount;
      	 amr.uRecordOverflowCount -= uRBFreeCount;
      	 uRBFreeCount = 0;
      }
      for(i=0; i<uBytesToWrite; i++)
         media_buffer_put_byte(0x7C);
   }

   if (uRBFreeCount<61) { /* 8 bit frame header + max. 477 bits speech data */
      /* media buffer overflows */
      if(uRBFreeCount>1) {
         /* stuff 'no-data' frame */
         media_buffer_put_byte(0x7C);
      } else {
      	 amr.uRecordOverflowCount++;
      }
      return;
   }
   
   Tx_Type = *DP_3G_UL_TX_TYPE & 0x3;
   bCodecMode = DP_3G_UL_TX_MODE_REPORT;

   /* get AMR frame type */
   if (bCodecMode>=0x03 && bCodecMode<=0x0A) {
      FT = 0x0A - bCodecMode;
   }
   else {
      ASSERT(KAL_FALSE);
   }

   if (Tx_Type==2) { /* TX_TYPE: SPEECH */
      {
         rd_bits = lenSpeechBitsAMR[FT];
      }
      rd_bytes = (rd_bits + 7)/8;
      uLenSpeechInSherif = (rd_bytes+1)/2;

      /* Get speech parameter bits */
      {
         pwSherifAddr = DSP_SPH_3G_SE_DATA_HB;
         for (i=0; i<uLenSpeechInSherif; i++)
            Tx_data_buffer[i] = *pwSherifAddr++;
      }

      /* bits ordering */
      kal_mem_set(Tx_ordering_buffer, 0, sizeof(Tx_ordering_buffer));
      amr_bit_ordering_sherif_to_file(Tx_Type, FT, Tx_data_buffer, Tx_ordering_buffer, rd_bits);

      /* put frame header to media buffer */
      media_buffer_put_byte((kal_uint8)((FT<<3) | (0x1<<2))); /* FT | FQI */

      /* put ordering data to media buffer */
      media_buffer_put_nbytes((kal_uint8*)Tx_ordering_buffer, rd_bytes);
   }
}

#endif

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

kal_uint8 media_buffer_get_byte() {
   if (amr.bOddFlag == KAL_TRUE) {
      amr.bOddFlag = KAL_FALSE;
      return amr.bOddData;
   } else if (amr.bOddFlag == KAL_FALSE) {
      if (amr.ctrl->read != amr.ctrl->write) {
      	 kal_uint16 wVal = amr.ctrl->rb_base[amr.ctrl->read++];
         if (amr.ctrl->read >= amr.ctrl->rb_size)
            amr.ctrl->read = 0;
         amr.bOddData = (kal_uint8)(wVal >> 8);
         amr.bOddFlag = KAL_TRUE;
         return (kal_uint8)(wVal & 0x00FF);
      }
      /* XXX: media ring buffer underflow */
      ASSERT(amr.ctrl->read != amr.ctrl->write);
   } else {
      ASSERT(KAL_FALSE);
   }
   return 0;
}

kal_uint8 media_buffer_peek_byte() {
   if (amr.bOddFlag == KAL_TRUE) {
      return amr.bOddData;
   } else if (amr.bOddFlag == KAL_FALSE) {
      if (amr.ctrl->read != amr.ctrl->write) {
      	 kal_uint16 wVal = amr.ctrl->rb_base[amr.ctrl->read];
         return (kal_uint8)(wVal & 0x00FF);
      }
      /* XXX: media ring buffer underflow */
      ASSERT(amr.ctrl->read != amr.ctrl->write);
   } else {
      ASSERT(KAL_FALSE);
   }
   return 0;
}

kal_uint16 media_buffer_get_2bytes() {
   kal_uint8 buf1, buf2;
   buf1 = media_buffer_get_byte();
   buf2 = media_buffer_get_byte();
   return (kal_uint16)(buf1 | buf2<<8);
}

void media_buffer_get_nbytes(kal_uint8 *buf, kal_uint32 uLen) {
   kal_uint32 i=0;
   ASSERT(buf!=NULL);
   while(uLen-->0) {
      buf[i++] = media_buffer_get_byte();
   }
}

kal_uint8 media_buffer_peek_nbytes(kal_uint8 *buf, kal_uint32 uLen) {
   kal_uint32 uOrigRead = amr.ctrl->read;
   kal_bool bOrigOddFlag = amr.bOddFlag;
   kal_uint8 bOrigOddData = amr.bOddData;

   media_buffer_get_nbytes(buf, uLen);

   amr.ctrl->read = uOrigRead;
   amr.bOddFlag = bOrigOddFlag;
   amr.bOddData = bOrigOddData;
   return 0;
}

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_AMRREC_ROCODE", rodata = "DYNAMIC_CODE_AMRREC_RODATA"
#endif
void amrRecord( mediaControl *ctrl, kal_uint16 type )
{
   amr.ctrl = ctrl;
   amr.state = AMR_STATE_RECORD;
   amr.bOddFlag = KAL_FALSE;
   amr.wType = type;
   amr.uRecordOverflowCount = 0;
#if DEBUG_AMR_RAM_FILE
   amr.uRamFileOffset = 0;
#endif
   amr.dedicated_mode = AM_IsSpeechOn();
   
   ctrl->read = ctrl->write = ctrl->uOffset;
#if VMI_SUPPORT   
   if(AM_IsVoIPOn() == true)
   {
      VMI_PutAllToSE(true);
   }
#endif
   
#if !defined(__VAD_SUPPORT__)
   *DP_SC_MUTE = 0x0002;   /* uplink path only */
#endif

   /*
    * Stuff no-data frame first to handle the situation when DSP issues
    * interrupt to MCU for recording, but at that time the AMR codec in DSP
    * has not finished its job.
    */
#if defined( AMRWB_ENCODE ) && !defined( __AMRWB_SW_ENCODE__ )
   if (MEDIA_FORMAT_AMR_WB==ctrl->format) { /* AMR-WB */

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   DSP_DynamicDownload( DDID_AWB );
   *DSP_AWB_SE_CTRL = DSP_INITIALIZED;
#elif defined(MT6268)
   DSP_DynamicDownload( DDID_NOISE_REDUCTION );
#endif

      amr.bWideBand = KAL_TRUE;
#if AMR_WRITE_FILE_HEADER
      media_buffer_put_nbytes((kal_uint8*)"#!AMR-WB\n", 9); /* magic number  "#!AMR-WB\n" */
#endif
      ASSERT(type>=0x20 && type<=0x28);
      *DP_AWB_TX_TCH_S0(0) &= 0xFC;  /* Tx_type "No data" */
      *DP_AWB_SC_TCH_MODE &= 0xFF00;
      *DP_AWB_SC_TCH_MODE |= 0x0020; /* SC Mode: 4.75kbps */
   } else 
#endif
   if (MEDIA_FORMAT_AMR==ctrl->format || MEDIA_FORMAT_AMR_TRANSMIT==ctrl->format) { /* AMR */
      amr.bWideBand = KAL_FALSE;
#if AMR_WRITE_FILE_HEADER
      media_buffer_put_nbytes((kal_uint8*)"#!AMR\n", 6); /* magic number  "#!AMR\n" */
#endif
      ASSERT(type>=0x03 && type<=0x0A);
      if (amr.dedicated_mode){
         *DSP_TX_TCH_S(0,0) &= 0xFC; /* Tx_type "No data" */
         *DSP_SC_TCH_MODE &= 0xF0FF;
         *DSP_SC_TCH_MODE |= 0x0900; /* SC mode: 5.15kbps */
      } else {
         *DSP_SD2_VM_0 &= 0xFC;       /* Tx_type "No data" */
         *DSP_SD2_VM_17 &= 0xF0FF;
         *DSP_SD2_VM_17 |= 0x0900;    /* SC mode: 5.15kbps */
      }
   } else {
      ASSERT(KAL_FALSE);
   }
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#if defined(__VAD_SUPPORT__)
   Media_Hook_Record_HISR (DP_D2C_3G_DONE_UL, NULL);
#else
   Media_Hook_Record_HISR (DP_D2C_VM_REC_INT, NULL);
#endif
#endif  // chip compile option

#if defined(__VAD_SUPPORT__)
   AM_BabyMonitor_RecordOn( (kal_uint16)type );
   Pseudo_SAL_3G_Upd_Enc_Cod( (kal_uint16)type );
#else
   AM_VMRecordOn( (kal_uint16)type );
#endif

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#if defined( AMRWB_ENCODE ) && !defined( __AMRWB_SW_ENCODE__ )
   if (MEDIA_FORMAT_AMR_WB == ctrl->format ){
      kal_uint32 I;
      kal_uint16 ctl;
      volatile kal_uint16* ptr;

      ptr = DSP_AWB_SE_CTRL;
      for( I = 0; ; I++ ) {
         ctl = *ptr;
         if( ctl == DSP_RECORDING )                /* DSP returns to idle state */
            break;
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
   }
#endif
#endif
}
#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

kal_uint16 amrSetAndGetInitialCodecMode()
{
   kal_uint16 wInitialCodecMode;
#if defined( AMRWB_DECODE )
   if (KAL_TRUE==amr.bWideBand) {
      amr.bCodecMode = 0x20;
      wInitialCodecMode = (0x20<<2);
   } else
#endif
   {
      amr.bCodecMode = 0x03;
      wInitialCodecMode = (0x03<<2) | (0x03<<6);
   }
   return wInitialCodecMode;
}

#if (defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)) && !defined( __AMRWB_SW_ENCODE__ )
void amrWBStopCtrl(bool isPlayback)
{
   uint16 I, ctl;
   volatile uint16* ptr;

   ptr = ((isPlayback == true )?DSP_AWB_SD_CTRL:DSP_AWB_SE_CTRL);

   if(*ptr == DSP_PLAYING || *ptr == DSP_RECORDING){
      amr.state = AMR_STATE_STOP;
      *ptr = DSP_STOP;
   }
   for( I = 0; ; I++ ) {
      ctl = *ptr;
      if( ctl == DSP_IDLE )                /* DSP returns to idle state */
         break;
      ASSERT_REBOOT( I < 20 );
      kal_sleep_task( 2 );
   }
}
#endif

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_AMRREC_ROCODE", rodata = "DYNAMIC_CODE_AMRREC_RODATA"
#endif
void amrStop( mediaControl *ctrl )
{
   (void) ctrl;
   switch(amr.state) {
      case AMR_STATE_RECORD:
      case AMR_STATE_RECORD_PAUSE:

#if defined(AMRWB_ENCODE) && !defined( __AMRWB_SW_ENCODE__ )
         if(amr.bWideBand)
            amrWBStopCtrl(false);
#endif

         *DP_SC_MUTE = 0x0000;

#if defined(__VAD_SUPPORT__)
         AM_BabyMonitor_RecordOff();
#else
         AM_VMRecordOff();
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
         Media_Unhook_Record_HISR ();
#endif  // chip compile option
         media_buffer_flush();
         break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(AMRWB_DECODE) && (defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) )
/* under construction !*/
/* under construction !*/
#endif
#if AMR_AWB_AUDIO_PATH_SUPPORT
/* under construction !*/
/* under construction !*/
#else // AMR_AWB_AUDIO_PATH_SUPPORT
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
/* under construction !*/
#else   // chip compile option
/* under construction !*/
#endif  // chip compile option
#endif
/* under construction !*/
#endif
      default:
         ASSERT(KAL_FALSE);
   }
#if VMI_SUPPORT     
   VMI_PutAllToSE(false);
#endif   
   amr.state = AMR_STATE_STOP;
}

void amrPause(mediaControl *ctrl)
{
   switch(amr.state) {
      case AMR_STATE_RECORD:

#if defined(AMRWB_ENCODE) && !defined( __AMRWB_SW_ENCODE__ )
         if(amr.bWideBand)
            amrWBStopCtrl(false);
#endif

         *DP_SC_MUTE = 0x0000;

#if defined(__VAD_SUPPORT__)
         AM_BabyMonitor_RecordOff();
#else
         AM_VMRecordOff();
#endif
         amr.state = AMR_STATE_RECORD_PAUSE;
         break;
#if 0
/* under construction !*/
/* under construction !*/
#if defined(AMRWB_DECODE) && ( defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
/* under construction !*/
/* under construction !*/
#endif
#if AMR_AWB_AUDIO_PATH_SUPPORT
/* under construction !*/
/* under construction !*/
#else // AMR_AWB_AUDIO_PATH_SUPPORT
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
/* under construction !*/
#else   // chip compile option
/* under construction !*/
#endif  // chip compile option
#endif
/* under construction !*/
/* under construction !*/
#endif
      default:
         ASSERT(KAL_FALSE);
   }
   
#if VMI_SUPPORT     
   VMI_PutAllToSE(false);
#endif   
   
}

void amrResume(mediaControl *ctrl)
{
   //kal_uint16 wCodecMode;

   switch(amr.state) {
      case AMR_STATE_RECORD_PAUSE:

#if VMI_SUPPORT        	
         if(AM_IsVoIPOn() == true)
         {
            VMI_PutAllToSE(true);
         }
#endif
         
#if !defined(__VAD_SUPPORT__)
         *DP_SC_MUTE = 0x0002;   /* uplink path only */
#endif

#if defined(AMRWB_ENCODE) && !defined( __AMRWB_SW_ENCODE__ )
         if(amr.bWideBand) {
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
            DSP_DynamicDownload( DDID_AWB );
            *DSP_AWB_SE_CTRL = DSP_INITIALIZED;
#elif defined(MT6268)
            DSP_DynamicDownload( DDID_NOISE_REDUCTION );
#endif
         }
#endif

#if defined(__VAD_SUPPORT__)
         AM_BabyMonitor_RecordOn( amr.wType );
#else
         AM_VMRecordOn( amr.wType );
#endif
         amr.state = AMR_STATE_RECORD;

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#if defined( AMRWB_ENCODE ) && !defined( __AMRWB_SW_ENCODE__ )
         if (MEDIA_FORMAT_AMR_WB == ctrl->format ){
            kal_uint32 I;
            kal_uint16 ctl;
            volatile kal_uint16* ptr;

            ptr = DSP_AWB_SE_CTRL;
            for( I = 0; ; I++ ) {
               ctl = *ptr;
               if( ctl == DSP_RECORDING )                /* DSP returns to idle state */
                  break;
               ASSERT_REBOOT( I < 20 );
               kal_sleep_task( 2 );
            }
         }
#endif
#endif

         break;
      default:
         ASSERT(KAL_FALSE);
   }
}
#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

void amrUpdateLevel()
{
#if AMR_AWB_AUDIO_PATH_SUPPORT
   AFE_SetDigitalGain( L1SP_AUDIO, amr.ctrl->level );
#else
   AFE_SetDigitalGain( L1SP_VOICE, amr.ctrl->level );
#endif // #if AMR_AWB_AUDIO_PATH_SUPPORT
}

#endif   // #if defined(AMR_CODEC)

