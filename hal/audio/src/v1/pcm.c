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
 * pcm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   PCM recording/playback
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __L1_STANDALONE__ // avoid link error

#include "kal_public_api.h"
#include "reg_base.h"
#include "l1d_reg.h"

#include "l1audio.h"
#include "audio_def.h"
#include "speech_def.h"
#include "am.h"
#include "ddload.h"
#include "wav.h"
#include "afe.h"
#include "media.h"

#if defined(WAV_CODEC)

#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)
#define PAGE_NUM 2
#elif defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
#define PAGE_NUM 1
#elif defined(MT6256_S01) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define PAGE_NUM 5
#else
#error The new chip should define DM page number
#endif

#define WAV_ABORT_STATE 0x40

/* ------------------------------------------------------------------------------ */
static struct{
   mediaControl       *ctrl;
   /* PCM/ADPCM/ALAW/ULAW specific variables */
   kal_uint16         data[4];
   kal_uint8          data_size;
   kal_uint8          data_count;
   kal_bool           isPlayback;
   kal_uint16         (*GetSample)( const uint16 **pbuf );
   kal_bool           (*PutSample)( uint16 **pbuf, uint16 data );
   dviAdpcm_State     dvi_state;

   // For EOF Handling
   kal_bool           decode_EOF;
   kal_int16          dsp_last_sample;
   kal_int32          zeroCount;
   kal_uint32         MIC1_framesize;    
   kal_bool           isRecord;      
} pcm;

#define abs(v) (((v) > 0) ? (v) : (-(v)))
/* ------------------------------------------------------------------------------ */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else //L1AUDIO_IDMA_ALL_ADDRESS_MODE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //L1AUDIO_IDMA_ALL_ADDRESS_MODE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_PCMREC_ROCODE", rodata = "DYNAMIC_CODE_PCMREC_RODATA"
#endif
static void pcmReadFromDSP( void )
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 

#ifndef UPPER_BOUND
#define UPPER_BOUND(in,up)  ((in) > (up) ? (up) : (in))
#endif

    kal_uint16 *rb_addr, *rb_end;
    kal_int32 write_count = 0;
    kal_int32 count = mediaGetFreeSpace();
    kal_int32 I = (kal_int32)Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_BUF_IDLE_SE);;

    count = UPPER_BOUND(count, I);

    if (count == 0)
    {
        return;
    }

    rb_end  = &pcm.ctrl->rb_base[pcm.ctrl->rb_size];
    rb_addr = &pcm.ctrl->rb_base[pcm.ctrl->write];

    if (Media_IsRecordSilence())
    {
        for (I = 0; I < count; I++)
        {
            if (pcm.PutSample(&rb_addr, 0))
            {
                write_count++;
                if (rb_addr == rb_end)
                {
                    rb_addr = &pcm.ctrl->rb_base[0];
                }
            }
        }
    }
    else
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
    {
        volatile kal_uint16 *dspAddr = Pseudo_SAL_PcmEx_GetBuf(PSEUDO_SAL_PCMEX_BUF_SE);
        
        for (I = 0; I < count; I++)
        {
           if( pcm.PutSample( &rb_addr, *dspAddr++ ) ) 
           {
              write_count++;
              if( rb_addr == rb_end )
              {
                 rb_addr = &pcm.ctrl->rb_base[0];
              }
           }
        }
    }
#else
    {
        volatile kal_uint16 *dspAddr = Pseudo_SAL_PcmEx_GetBuf(PSEUDO_SAL_PCMEX_BUF_SE);
        kal_uint16 dummy = *dspAddr;
   
        for (I = 0; I < count; I++)
        {
            if (pcm.PutSample(&rb_addr, *IDMA_SHORT_ADDR)) 
            {
                write_count++;
                if (rb_addr == rb_end)
                {
                    rb_addr = &pcm.ctrl->rb_base[0];
                }
            }
        }
   }
#endif
#else   // chip compile option

#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
   volatile kal_uint16* idmaPtr;
#endif

	 kal_int32 I, count, write_count = 0;
   kal_uint16 *rb_addr, *rb_end, ptr_addr;

   count = mediaGetFreeSpace();

   if ( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K )
      I = DSP_PCM_16K_REC_LEN;
   else
      I = (kal_int32)(*DSP_PCM_REC_LEN);
   if( I < count )
      count = I;
   if( count == 0 )
      return;

   rb_end   = &pcm.ctrl->rb_base[pcm.ctrl->rb_size];
   rb_addr  = &pcm.ctrl->rb_base[pcm.ctrl->write];

   if(Media_IsRecordSilence())
   {
      for( I = 0; I < count; I++ )
      {
         if( pcm.PutSample( &rb_addr, 0 ) ) 
         {
            write_count++;
            if( rb_addr == rb_end )
            {
               rb_addr = &pcm.ctrl->rb_base[0];
            }
         }
      }
   }
   else
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
   {
      if ( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K )
      { 
         ptr_addr = *DSP2_DM_ADDR(PAGE_NUM, DSP_PCM_16K_REC_PTR);
         idmaPtr=DSP2_DM_ADDR(PAGE_NUM, ptr_addr);
      
      }
      else
      {
         idmaPtr=DSP_DM_ADDR(PAGE_NUM, *DSP_PCM_REC_ADDR);
      }
      for( I = 0; I < count; I++ )
      {
         if( pcm.PutSample( &rb_addr, *idmaPtr++ ) ) 
         {
            write_count++;
            if( rb_addr == rb_end )
            {
               rb_addr = &pcm.ctrl->rb_base[0];
            }
         }
      }
   }
#else// L1AUDIO_IDMA_ALL_ADDRESS_MODE
   {
      kal_uint16 dummy;
      if ( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K )
      { 
         ptr_addr = *DSP2_DM_ADDR(PAGE_NUM, DSP_PCM_16K_REC_PTR);
         dummy    = *DSP2_DM_ADDR(PAGE_NUM, ptr_addr);
      }
      else
      {
         dummy = *DSP_DM_ADDR(PAGE_NUM, *DSP_PCM_REC_ADDR);
      }
   
      for( I = 0; I < count; I++ )
      {
         if( pcm.PutSample( &rb_addr, *IDMA_SHORT_ADDR ) ) 
         {
            write_count++;
            if( rb_addr == rb_end )
            {
               rb_addr = &pcm.ctrl->rb_base[0];
            }
         }
      }
   }
#endif
#endif  // chip compile option
   pcm.MIC1_framesize = write_count;
   pcm.ctrl->write += write_count;
   if( pcm.ctrl->write >= pcm.ctrl->rb_size )
   {
      pcm.ctrl->write -= pcm.ctrl->rb_size;
   }
}
#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

uint32 pcmGetFrameIntensity()
{  
   int framesize = pcm.MIC1_framesize;
   if( pcm.isRecord && ( framesize > 0))
   {
      uint16 I;
      int32 sum=0, v;      
      int16 *rb_end    = (int16 *)&pcm.ctrl->rb_base[pcm.ctrl->rb_size-1];
      int16 *rb_start  = (int16 *)&pcm.ctrl->rb_base[0];      
      int16 *pBuf      = (int16 *)pcm.ctrl->rb_base;
      
      int32 w_idx = pcm.ctrl->write;

      if(w_idx >= pcm.ctrl->rb_size)
         w_idx -= pcm.ctrl->rb_size;
      
      if(w_idx == 0){
         w_idx = pcm.ctrl->rb_size - 1;
      }else{
         w_idx -- ;
      }
         
      pBuf = (int16 *)&pcm.ctrl->rb_base[w_idx];
      
      for ( I = 0; I < framesize ; I++, pBuf--){         
         v = *pBuf;
         sum += abs(v);         
         if(pBuf == rb_start)
            pBuf = rb_end;
      }
       
      return (uint32)(sum / framesize);
   }else
      return 0;    
}

/* ------------------------------------------------------------------------------ */
static kal_uint16 pcmGetSample( const kal_uint16 **pbuf )
{
   kal_uint16 dat = **pbuf;
   *pbuf = *pbuf + 1;
   return dat;
}

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_PCMREC_ROCODE", rodata = "DYNAMIC_CODE_PCMREC_RODATA"
#endif
static kal_bool pcmPutSample( kal_uint16 **pbuf, kal_uint16 data )
{
   **pbuf = data;
   *pbuf = *pbuf + 1;
   return true;
}
#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

static kal_uint16 alawGetSample( const kal_uint16 **pbuf )
{
   if( pcm.data_count == 0 ) {
      kal_uint16 data = **pbuf;
      pcm.data[1] = alaw2linear( (kal_uint8)(data & 0xFF) );
      pcm.data[0] = alaw2linear( (kal_uint8)(data >> 8) );
      *pbuf = *pbuf + 1;
      pcm.data_count = 2;
   }
   return pcm.data[--pcm.data_count];
}

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_PCMREC_ROCODE", rodata = "DYNAMIC_CODE_PCMREC_RODATA"
#endif
static kal_bool alawPutSample( kal_uint16 **pbuf, kal_uint16 data )
{
   pcm.data[pcm.data_count++] = data;
   if( pcm.data_count == 2 ) {
      **pbuf = (kal_uint16)linear2alaw( (kal_int16)pcm.data[0] ) +
               ((kal_uint16)linear2alaw( (kal_int16)pcm.data[1] ) << 8);
      *pbuf = *pbuf + 1;
      pcm.data_count = 0;
      return true;
   }
   return false;
}
#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

static kal_uint16 ulawGetSample( const kal_uint16 **pbuf )
{
   if( pcm.data_count == 0 ) {
      kal_uint16 data = **pbuf;
      pcm.data[1] = ulaw2linear( (kal_uint8)(data & 0xFF) );
      pcm.data[0] = ulaw2linear( (kal_uint8)(data >> 8) );
      *pbuf = *pbuf + 1;
      pcm.data_count = 2;
   }
   return pcm.data[--pcm.data_count];
}

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_PCMREC_ROCODE", rodata = "DYNAMIC_CODE_PCMREC_RODATA"
#endif
static kal_bool ulawPutSample( kal_uint16 **pbuf, kal_uint16 data )
{
   pcm.data[pcm.data_count++] = data;
   if( pcm.data_count == 2 ) {
      **pbuf = (kal_uint16)linear2ulaw( (kal_int16)pcm.data[0] ) +
               ((kal_uint16)linear2ulaw( (kal_int16)pcm.data[1] ) << 8);
      *pbuf = *pbuf + 1;
      pcm.data_count = 0;
      return true;
   }
   return false;
}
#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

static kal_uint16 dviGetSample( const kal_uint16 **pbuf )
{
   if( pcm.data_count == 0 ) {
      kal_uint16 data = **pbuf;
      pcm.data[3] = dviAdpcm_Decode( (kal_uint8)(data & 0xF), &pcm.dvi_state );
      pcm.data[2] = dviAdpcm_Decode( (kal_uint8)((data >> 4) & 0xF), &pcm.dvi_state );
      pcm.data[1] = dviAdpcm_Decode( (kal_uint8)((data >> 8) & 0xF), &pcm.dvi_state );
      pcm.data[0] = dviAdpcm_Decode( (kal_uint8)((data >> 12) & 0xF), &pcm.dvi_state );
      *pbuf = *pbuf + 1;
      pcm.data_count = 4;
   }
   return pcm.data[--pcm.data_count];
}

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_PCMREC_ROCODE", rodata = "DYNAMIC_CODE_PCMREC_RODATA"
#endif
static kal_bool dviPutSample( kal_uint16 **pbuf, kal_uint16 data )
{
   pcm.data[pcm.data_count++] = data;
   if( pcm.data_count == 4 ) {
      **pbuf = dviAdpcm_Encode( pcm.data[0], &pcm.dvi_state ) |
               (dviAdpcm_Encode( pcm.data[1], &pcm.dvi_state ) << 4) |
               (dviAdpcm_Encode( pcm.data[2], &pcm.dvi_state ) << 8) |
               (dviAdpcm_Encode( pcm.data[3], &pcm.dvi_state ) << 12);
      *pbuf = *pbuf + 1;
      pcm.data_count = 0;
      return true;
   }
   return false;
}
#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

/* ------------------------------------------------------------------------------ */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(_DSP_INTERSHAREMEM_EN_)    
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if APM_SUPPORT
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_PCMREC_ROCODE", rodata = "DYNAMIC_CODE_PCMREC_RODATA"
#endif
void pcmRecordHisr( void )
{
#if defined(_DSP_INTERSHAREMEM_EN_)    
    *DP2_AUDIO_ASP_TASK4_DM_HANDSHAKE = 0;
#endif
    
    if (pcm.ctrl->end_status == MEDIA_TERMINATED)
    {
        return;
    }
    
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support state machine PCM record control
#else   // chip compile option
    if (*DSP_PCM_REC_CTRL == 0 && pcm.ctrl->format != MEDIA_FORMAT_PCM_16K)
    {   // DSP returns to idle state
        AM_PCM8K_RecordOff(false);
        mediaSetEvent(pcm.ctrl->end_status);
        return;
    }
#endif  // chip compile option
    
    pcmReadFromDSP();
    
    return;
}
#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

/* ------------------------------------------------------------------------------ */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(CYBERON_DIC_TTS) || defined(IFLY_TTS) || defined(SINOVOICE_TTS) || defined(VRSI_ENABLE)
/* under construction !*/
#if defined(CYBERON_DIC_TTS) || defined(IFLY_TTS) || defined(SINOVOICE_TTS)
/* under construction !*/
/* under construction !*/
#endif
#if defined(VRSI_ENABLE)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined( DSP_WT_SYN ) && !defined(__AUDIO_COMPONENT_SUPPORT__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_PCMREC_ROCODE", rodata = "DYNAMIC_CODE_PCMREC_RODATA"
#endif
void pcmRecordTurnOnDSP(void)
{
   if ( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K ){
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
      Media_Hook_Record_HISR (DP_D2C_VM_REC_INT, NULL);
#endif  // chip compile option
      AM_PCM16K_RecordOn();    // no need to control *DP_AWB_SE_CTRL
   }
   else                       //8K PCM
   {  
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support state machine PCM record control
      Media_Hook_Record_HISR (DP_D2C_PCM_REC_INT, NULL);
      AM_PCM8K_RecordOn();
#else   // chip compile option
      kal_uint16 I;
      *DSP_PCM_REC_CTRL  = 0x200;
      AM_PCM8K_RecordOn();
      for( I = 0; ; I++ ) {
         if( *DSP_PCM_REC_CTRL == 0x400 )
            break;
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
#endif  // chip compile option
   }
   pcm.isRecord = true;      
}
#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

void pcmTurnOffDSP(void)
{
   {                              /* PCM Record */
      if ( pcm.ctrl->format == MEDIA_FORMAT_PCM_16K ){
         AM_PCM16K_RecordOff ( true );// no need to wait *DP_AWB_SE_CTRL
      } else {  
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support state machine PCM record control
         AM_PCM8K_RecordOff( true );
#else   // chip compile option
         {
            kal_uint16 I, ctl;
            for( I = 0; ; I++ ) {
               ctl = *DSP_PCM_REC_CTRL;
               if( ctl == 0 )                /* DSP returns to idle state */
                  break;
               if( ctl == 0x400 )
                  *DSP_PCM_REC_CTRL = 0x800;  /* give ABORT command to the DSP */
               ASSERT_REBOOT( I < 20 );
               kal_sleep_task( 2 );
            }
            AM_PCM8K_RecordOff( true );
         }
#endif  // chip compile option
      }
   }

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   Media_Unhook_Record_HISR();
#endif  // chip compile option
   
   pcm.isRecord = false;      
}

/* ------------------------------------------------------------------------------ */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_PCMREC_ROCODE", rodata = "DYNAMIC_CODE_PCMREC_RODATA"
#endif
void pcmRecord( mediaControl *ctrl )
{   
   pcm.ctrl = ctrl;
   pcm.data_count  = 0;
   pcm.isPlayback = false;
   switch( pcm.ctrl->format ) {
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
         pcm.PutSample = pcmPutSample;
         pcm.data_size = 1;
         break;
      case MEDIA_FORMAT_G711_ALAW:
         pcm.PutSample = alawPutSample;
         pcm.data_size = 2;
         break;
      case MEDIA_FORMAT_G711_ULAW:
         pcm.PutSample = ulawPutSample;
         pcm.data_size = 2;
         break;
      case MEDIA_FORMAT_DVI_ADPCM:
         pcm.PutSample = dviPutSample;
         pcm.data_size = 4;
         dviAdpcm_Init( &pcm.dvi_state );
         break;
   }
   ctrl->end_status = MEDIA_NONE;
   pcmRecordTurnOnDSP();
}
#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

void pcmPause( mediaControl *mctrl )
{
#if 1 //APM_SUPPORT
   if (AM_IsAudioPlaybackOn()!=-1)
      AFE_SetHardwareMute(true);
#endif

   pcm.ctrl->end_status = MEDIA_TERMINATED;
   pcmTurnOffDSP();
}

void pcmResume( mediaControl *ctrl )
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   {
      ctrl->end_status = MEDIA_NONE;
      pcmRecordTurnOnDSP();
   }
}

void pcmStop( mediaControl *ctrl )
{
   (void) ctrl;

   pcm.ctrl->end_status = MEDIA_TERMINATED;
   pcmTurnOffDSP();
}

/* ------------------------------------------------------------------------------ */

#endif // #if defined(WAV_CODEC)
#endif
