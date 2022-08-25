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
 *   snd_effect.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Sound effect interface and driver, providing in-call background sound and sound event playback
 *     support FSAL stream input with Microsoft WAV format
 *
 * Author:
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
*                E X T E R N A L   R E F E R E N C E S
******************************************************************************
*/

#ifdef BGSND_ENABLE
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "PCMRB.h"
#include "string.h"
#include "l1d_reg.h"
#include "l1audio.h"
#include "audio_def.h"
#include "speech_def.h"
#include "media.h"


#include "afe.h"
#include "am.h"
#include "wav.h"
#include "fsal.h"
#include "vmi.h"

#if IS_EV_BOARD
//#include "alerter_sw.h"
#endif

#include "kal_trace.h"
#include "l1sp_trc.h"
#define L1SND_TRC_ON

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_app.h"
#endif

#if defined(AMR_CODEC)   
#include "amr_codec.h"
#define MAX_FRAME_LENGTH 64 //2^n
const kal_uint8 amrFrameLength[16] = {12, 13, 15, 17, 19, 20, 26, 31, 5, 0, 0, 0, 0, 0, 0, 0};
#endif

#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253)  || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
#define PAGE_NUM 2
#elif defined(MT6251)
#define PAGE_NUM 1
#elif defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define PAGE_NUM 5 
#else
#error Need indicate DM page of SND_EFFECT for new chip
#endif


/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define DP_BUFFER_DEFAULT_LEN       4096   /* The frame size of DSP. */
#define DSP_BUFFER_LEN              160
#define SND_RB_DEFAULT_THRESHOLD    512
#define MASTER_GAIN_FACTOR          12

/* DSP Sound Effect State */
#define DP_SND_STATE_IDLE           0     /* MCU: 0 -> 1 */
#define DP_SND_STATE_READY          1     /* DSP: 1 -> 2 */
#define DP_SND_STATE_PLAYING        2     /* MCU: 2 -> 3 */
#define DP_SND_STATE_STOPPED        3     /* DSP: 3 -> 0 */

#define SND_STATE_NORMAL            0
#define SND_STATE_STOPPING          1
//#define SND_APPLY_MCU_GAIN
//#define SND_CHECK_DATA

#define SND_GAIN_CONFIG   1 /* 0: right shamt, 1: multiplier */



/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/

#ifdef SND_CHECK_DATA
int16 snd_check_data[0x80000];
int16 *snd_check_w2;
#endif

//#define SND_UNIT_TEST
typedef struct {
   int16 formatTag;
   uint16 numChannels;
   uint32 sampleRate;
   uint32 avgBytesPerSec;   
   uint16 blockAlign;
   uint16 bitsPerSample;
   uint32 extHeaderOffset;
   uint16 extHeaderSize;
   uint32 dataChunkOffset;
   uint32 dataChunkSize;
} sndHeader;

typedef struct sndcontrol SndControl;
struct sndcontrol{
   uint16 aud_id;
   void (*SND_PutData)(SndControl *snd_ctrl);
   VMI_HANDLE   *vmi_handle;

#if defined(AMR_CODEC)   
   AMR_DecData  *amr_handle;
   kal_uint32   bsBuf8_r;
   kal_uint32   bsBuf8_w;
   kal_uint16   amr_dec_id;
#endif   
   
   Media_Event end_status;
   int16 level;
   kal_bool bULSPHFlag; /* if KAL_TRUE, mix uplink speech */
   kal_bool bDLSPHFlag; /* if KAL_TRUE, mix downlink speech */
   kal_int16 ULSNDGain; /* 0 ~ 100, digital gain for mixed uplink sound */
   kal_int16 DLSNDGain; /* 0 ~ 100, digital gain for mixed downlink sound */

   sndHeader info;
   int16 dsp_last_sample;  /* The last sample written to DSP buffer by MCU, for last-sample padding */
   dviAdpcm_State dvi_state;
   int16 dvi_data[4];
   uint16 dvi_blockCounter;
   uint8 dvi_dataCount;

   /* Ring buffer control variables */
   uint16 rb_threshold;
   uint16 rb_size;          /* Size of the ring buffer(word) */
   uint16 write;            /* R/W by MMI, R by WAV driver   */
   uint16 read;             /* R by MMI, R/W by WAV driver   */
   int16 *rb_base;         /* Pointer to the ring buffer    */
   int16       *spk_buffer;	   
   uint32 total_write_bytes;
   uint32 total_consume_bytes;
#if defined(__BT_SUPPORT__)
   uint16 snd_state;
#endif
   bool waiting;
   bool eof;              /* Flag indicating End-Of-File   */
   void *parent;
#ifdef _FWE_SUPPORT_
   void * src_handle;
#endif   
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
    uint32 hisr_state;  // 0: None
                        // 1: Receive UL interrupt
                        // 2: Receive DL interrupt
                        // 3: Receive UL interrupt first, then receive DL interrupt
                        // 4: Receive DL interrupt first, then receive UL interrupt
#endif  // chip compile option
} ;

typedef struct {
   kal_int8       repeat_count;
   kal_uint8      volume_level;
   kal_uint32     data;
   void           (*handler)( Media_Handle *handle, Media_Event event );
   void           *param;
} mhandle;

typedef struct {
  mhandle mh;
  SndControl snd_ctrl;
} sndMediaHandleInternal;


/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/
static int32 sndGetDataCount( SndControl *snd_ctrl );
static void sndGetReadBuffer( SndControl *snd_ctrl, int16 **buffer, uint32 *buf_len );

/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/


/*****************************************************************************
*                          F U N C T I O N S
******************************************************************************
*/
#ifdef _FWE_SUPPORT_ 
#include "blisrc_exp.h"

//SRC
typedef struct{
   void*        blisrc_handle;
   char*        bli_workBufPtr;
   kal_uint16   encInBufSize;
   kal_uint16   encInBuf_w;
   kal_uint16   encInBuf_r;
   kal_int16    *encInBuf;
} SRCHandle;

int16 temp[320];

void* allocSRC(int in_sr, int out_sr)
{
   kal_uint32 workBufSize;
   SRCHandle  *SRC_handle;

#ifdef L1SND_TRC_ON
    kal_trace(TRACE_GROUP_SND, L1SND_SND_ALLOC_SRC);
#endif

   SRC_handle = (SRCHandle*)audio_alloc_mem(sizeof(SRCHandle));
   ASSERT(SRC_handle);  
   
   BLI_GetMemSize(in_sr, 1, out_sr, 1, &workBufSize);   
   SRC_handle->bli_workBufPtr = (char*)audio_alloc_mem(workBufSize);
   ASSERT(SRC_handle->bli_workBufPtr != NULL);
   
   SRC_handle->blisrc_handle = BLI_Open(in_sr, 1, out_sr, 1, SRC_handle->bli_workBufPtr, audio_alloc_ext_mem_cacheable_simplified);

   SRC_handle->encInBufSize = 1024;   
   SRC_handle->encInBuf = (kal_int16*)audio_alloc_mem( SRC_handle->encInBufSize * sizeof(kal_int16) );
   ASSERT(SRC_handle->encInBuf != NULL);   
   SRC_handle->encInBuf_w = SRC_handle->encInBuf_r = 0;   
   
   return SRC_handle;  
}

void freeSRC(void* Handle){
   SRCHandle  *SRC_handle = (SRCHandle *)Handle;

#ifdef L1SND_TRC_ON
    kal_trace(TRACE_GROUP_SND, L1SND_SND_FREE_SRC);
#endif
   
#if 1       
   ASSERT(SRC_handle->blisrc_handle);
    
   BLI_Close(SRC_handle->blisrc_handle, audio_free_ext_mem_simplified);
   SRC_handle->blisrc_handle = NULL;

   audio_free_mem( (void **) &SRC_handle->bli_workBufPtr );
   SRC_handle->bli_workBufPtr = NULL;
   
   audio_free_mem( (void **) &SRC_handle->encInBuf );
   SRC_handle->encInBuf = 0;
   SRC_handle->encInBuf_r = SRC_handle->encInBuf_w = 0;   
   
   audio_free_mem( (void **) &SRC_handle );
#endif   
}

void doSRC(void* Handle, int16* src, int src_len, int16* dst)
{
   int frame_len = src_len;   
   uint16 *ptr;
   kal_uint32 encInBufFreeSpace;  //in word
   kal_uint32 apmInBufDataCnt;    //in word   
   kal_uint32 ret;
   SRCHandle  *SRC_handle = (SRCHandle *)Handle;
#ifdef L1SND_TRC_ON
    kal_brief_trace(TRACE_GROUP_SND, L1SND_SND_DO_SRC);
#endif

#if 1  
   encInBufFreeSpace = SRC_handle->encInBufSize - SRC_handle->encInBuf_w;   
   
   encInBufFreeSpace = encInBufFreeSpace << 1; //convert to byte
   apmInBufDataCnt   = frame_len << 1; //convert to byte
   ASSERT(apmInBufDataCnt < encInBufFreeSpace);//DataOverflow
   
   ret=BLI_Convert(SRC_handle->blisrc_handle, src, &apmInBufDataCnt, SRC_handle->encInBuf + SRC_handle->encInBuf_w, &encInBufFreeSpace) >> 1;
   
   SRC_handle->encInBuf_w += encInBufFreeSpace >> 1;      
   ptr = SRC_handle->encInBuf;
   frame_len = encInBufFreeSpace >> 1;//FRAME_BUF_SIZE;
   //ASSERT(ret == FRAME_BUF_SIZE);

#ifdef L1SND_TRC_ON
    kal_brief_trace(TRACE_GROUP_SND, L1SND_SND_DO_SRC_DETAIL, ret, frame_len);
#endif
    
   {
   memcpy(dst, ptr, (frame_len)*sizeof(int16));
   }
   SRC_handle->encInBuf_r = frame_len;
   ASSERT(SRC_handle->encInBuf_w >= SRC_handle->encInBuf_r);
   if(SRC_handle->encInBuf_w - SRC_handle->encInBuf_r)
      memcpy(SRC_handle->encInBuf, SRC_handle->encInBuf + SRC_handle->encInBuf_r, (SRC_handle->encInBuf_w - SRC_handle->encInBuf_r)*sizeof(int16));
   SRC_handle->encInBuf_w = SRC_handle->encInBuf_w - SRC_handle->encInBuf_r;
   SRC_handle->encInBuf_r = 0;
#endif  
}
#endif

__inline void sndShiftReadPointer(SndControl *snd_ctrl, uint32 len )
{
   snd_ctrl->read += len;
   if(snd_ctrl->read == snd_ctrl->rb_size) 
      snd_ctrl->read = 0; 

	snd_ctrl->total_consume_bytes += (len<<1);	
}

#if defined(AMR_CODEC) 
static Media_Status amr_InitDecoder( SndControl *snd_ctrl )
{
	 kal_uint32 int_buf_size, tmp_buf_size, bs_buf_size, pcm_buf_size, uTempSize, uAmrSize, uReqSizeTotal;
   kal_uint8 *pBuffer = NULL;
   AMR_DecData *pDecData = NULL;
   
   {
      uTempSize = (sizeof(AMR_DecData) + 3) & ~0x3;
      AMRDec_GetBufferSize(&int_buf_size, &tmp_buf_size, &bs_buf_size, &pcm_buf_size);
      int_buf_size = (int_buf_size + 3) & ~0x3;
      tmp_buf_size = (tmp_buf_size + 3) & ~0x3;
      bs_buf_size = (bs_buf_size + 3) & ~0x3;
      pcm_buf_size = (pcm_buf_size + 3) & ~0x3;
      uAmrSize = int_buf_size + tmp_buf_size + bs_buf_size + pcm_buf_size;
   }   
   uReqSizeTotal = uTempSize + uAmrSize;  
   pBuffer = (kal_uint8 *)audio_alloc_mem_cacheable(uReqSizeTotal);
   
   if(!pBuffer)
   {
   	  return MEDIA_FAIL;
   }
   
   snd_ctrl->amr_handle = (void *)pBuffer;
   
   pDecData = (AMR_DecData *)snd_ctrl->amr_handle;
   
   pBuffer += (sizeof(AMR_DecData) + 3) & ~0x3;
   
   pDecData->int_buf = (void *)pBuffer;
   pBuffer += int_buf_size;
   pDecData->tmp_buf = (void *)pBuffer;
   pBuffer += tmp_buf_size;
   pDecData->bs_buf = (void *)pBuffer;
   pBuffer += bs_buf_size;
   pDecData->pcm_buf = (void *)pBuffer;
   pBuffer += pcm_buf_size;
   
   pDecData->decHandle = AMRDec_Init( pDecData->int_buf );
   
   snd_ctrl->bsBuf8_r = 0;
   snd_ctrl->bsBuf8_w = 0;
      
   return MEDIA_SUCCESS;
     
}

static void amr_DeInitDecoder( SndControl *snd_ctrl )
{
	 if(snd_ctrl->amr_handle)
	 {
	 	 audio_free_mem( (void **) &snd_ctrl->amr_handle);
	 }
	 snd_ctrl->amr_handle = NULL;
}
#endif

static void sndAUlawPCM_DecodeSample( SndControl *snd_ctrl, uint16 (*law2linear)( uint8 aval ) )
{
   uint16 dsp_sound_effect_len;
   int32 numSamples, numSamples_fill_silence, I;   
   int16 sample = snd_ctrl->dsp_last_sample;	
   bool sampleType = (snd_ctrl->info.bitsPerSample==8);
	int16 *write_ptr = snd_ctrl->spk_buffer;
		    
   dsp_sound_effect_len  = DSP_BUFFER_LEN;
   numSamples = sndGetDataCount(snd_ctrl)*(sampleType?2:1);

   if(numSamples > dsp_sound_effect_len)
      numSamples = dsp_sound_effect_len;
	
   for(I=numSamples; I>0; I-=(sampleType?2:1))
	{
      uint16 data = snd_ctrl->rb_base[snd_ctrl->read];     
      sample = (sampleType?(law2linear?law2linear(data&0x00FF):((data<<8)-0x8000)):data); 
		*write_ptr++ = sample;
      
      if(sampleType){
         sample = (law2linear?law2linear(data>>8):((data&0xFF00)-0x8000)); 
			*write_ptr++ = sample;
      }

		sndShiftReadPointer(snd_ctrl , 1);

	   if( snd_ctrl->total_consume_bytes >= snd_ctrl->info.dataChunkSize ){
			snd_ctrl->total_consume_bytes = 0;			
	   }
   }
	
   snd_ctrl->dsp_last_sample = sample;
	
   // Fill silence to DSP if buffer underflow
   numSamples_fill_silence = dsp_sound_effect_len - numSamples;
	
   for(I=numSamples_fill_silence ; I>0; I--){
		*write_ptr++ = snd_ctrl->dsp_last_sample; 		
   }
}

static void sndDVIADPCM_DecodeWord(uint16 data, SndControl *snd_ctrl )
{
   snd_ctrl->dvi_data[3] = dviAdpcm_Decode( (uint8)(data & 0xF), &snd_ctrl->dvi_state );
   snd_ctrl->dvi_data[2] = dviAdpcm_Decode( (uint8)((data >> 4) & 0xF), &snd_ctrl->dvi_state );
   snd_ctrl->dvi_data[1] = dviAdpcm_Decode( (uint8)((data >> 8) & 0xF), &snd_ctrl->dvi_state );
   snd_ctrl->dvi_data[0] = dviAdpcm_Decode( (uint8)((data >> 12) & 0xF), &snd_ctrl->dvi_state );
}

static void sndPutData_PCM( SndControl *snd_ctrl ) /* 16 bit linear pcm */
{
   sndAUlawPCM_DecodeSample( snd_ctrl, NULL );	
}

static void sndPutData_Alaw( SndControl *snd_ctrl ) /* A-law decoder */
{
   sndAUlawPCM_DecodeSample( snd_ctrl, alaw2linear );
}

static void sndPutData_Ulaw( SndControl *snd_ctrl )  /* U-law decoder */
{
   sndAUlawPCM_DecodeSample( snd_ctrl, ulaw2linear );
}

#if defined(AMR_CODEC)
static void sndPutData_AMR( SndControl *snd_ctrl )  /* amr decoder */
{
   AMR_DecData *pDecData = (AMR_DecData *)snd_ctrl->amr_handle;  
   kal_int16 *write_ptr = snd_ctrl->spk_buffer;	 
   kal_int32  rbWordCount = sndGetDataCount(snd_ctrl);
   kal_int16  *read_buf = NULL;
   kal_uint32 buf_len = 0;
   kal_uint32 bs_buf_free = 0;
   
   if(rbWordCount == 0)
   {
      return;
   }      
   sndGetReadBuffer( snd_ctrl, &read_buf, &buf_len );
   
   bs_buf_free = MAX_FRAME_LENGTH - snd_ctrl->bsBuf8_w - 1;   
   if((bs_buf_free>>1) < buf_len)
   {
   	  buf_len = bs_buf_free>>1 ;
   }
   memcpy( (kal_uint8*)pDecData->bs_buf+ snd_ctrl->bsBuf8_w, (kal_uint8*)read_buf, buf_len<<1);
   snd_ctrl->bsBuf8_w += buf_len<<1;
   
   sndShiftReadPointer(snd_ctrl , buf_len);
   
   if(snd_ctrl->bsBuf8_w < (MAX_FRAME_LENGTH>>1))
   {
   	 //underflow: fill silence
   	 memset(write_ptr,snd_ctrl->dsp_last_sample,DSP_BUFFER_LEN*sizeof(kal_int16));
   	 return;
   }
      
   {
   	  kal_uint8 *pReadBuf = pDecData->bs_buf;
   	  kal_uint8 toc = *pReadBuf;   	  
   	  kal_uint32 remain_data_count = 0;
   	  pDecData->uQualityBit = (toc >> 2) & 0x01;
      pDecData->uFrameType  = (toc >> 3) & 0x0F;
      pDecData->uCurrentFrameLen = amrFrameLength[pDecData->uFrameType];
      
      
      if(pDecData->uCurrentFrameLen + 1 <= snd_ctrl->bsBuf8_w)
      {
         AMR_Decode(pDecData->decHandle, pDecData->tmp_buf, (kal_int16*)write_ptr, pReadBuf+1, pDecData->uQualityBit, pDecData->uFrameType);
         snd_ctrl->bsBuf8_r = pDecData->uCurrentFrameLen + 1;
         pDecData->uCurrentFrameLen = 0; 
         remain_data_count = snd_ctrl->bsBuf8_w - snd_ctrl->bsBuf8_r;
         memcpy( (kal_uint8*)pDecData->bs_buf, (kal_uint8*)pDecData->bs_buf + snd_ctrl->bsBuf8_r, remain_data_count); 
         snd_ctrl->bsBuf8_r = 0;
         snd_ctrl->bsBuf8_w = remain_data_count;
         snd_ctrl->dsp_last_sample = *(write_ptr+DSP_BUFFER_LEN-1);               
      }
      else
      {
      	 //underflow: fill silence. Shall not reach here
      	 memset(write_ptr,snd_ctrl->dsp_last_sample,DSP_BUFFER_LEN*sizeof(kal_int16));
      }                          	  
   }  
   
}
#endif

static void sndPutData_DVIADPCM( SndControl *snd_ctrl )  /* DVI-ADPCM decoder */
{
   int32 numSamples = snd_ctrl->dvi_dataCount;
	int32 numSamples_fill_silence;
   int32 rbWordCount, tmp1, tmp2, I;
	int32 elapse_sample=0;
   uint16 dp_sound_effect_len ;	
   uint16 sample = snd_ctrl->dsp_last_sample;   
	int16 *write_ptr = snd_ctrl->spk_buffer;	

   dp_sound_effect_len = DSP_BUFFER_LEN;
   rbWordCount = sndGetDataCount(snd_ctrl);

   tmp1 = (snd_ctrl->info.blockAlign>>1) - snd_ctrl->dvi_blockCounter; /* number of blocks (words) remained in current block */
	
   if(rbWordCount <= tmp1)
	{
      if(snd_ctrl->dvi_blockCounter > 0)
			numSamples += rbWordCount<<2;
      else if(rbWordCount >= 2)
      	numSamples += 1 + ((rbWordCount-2)<<2);
   }
   else
	{
      if(snd_ctrl->dvi_blockCounter > 0)
         numSamples += tmp1<<2;
      else
         numSamples += 1 + ((tmp1-2)<<2);
		
      rbWordCount -= tmp1;
      tmp1 = 1 + (((snd_ctrl->info.blockAlign>>1)-2)<<2); /* samples per block */
      tmp2 = snd_ctrl->info.blockAlign>>1; /* words per block */
		
      while(rbWordCount >= tmp2){
         numSamples += tmp1;
         rbWordCount -= tmp2;
      }

      if(rbWordCount >= 2)
        numSamples += 1 + ((rbWordCount-2)<<2);      
   }

	if(numSamples > dp_sound_effect_len) /* number of samples in rb */
      numSamples = dp_sound_effect_len;

   for(I=numSamples; I>0; I--)
	{
      int32 data = (int32)snd_ctrl->rb_base[ snd_ctrl->read ];
      if(snd_ctrl->dvi_dataCount == 0)
		{
         if(snd_ctrl->dvi_blockCounter == 0)
			{
            snd_ctrl->dvi_state.valpred = data;
            snd_ctrl->dvi_data[0] = (int16)data;

   			sndShiftReadPointer(snd_ctrl , 1);
            snd_ctrl->dvi_state.index = (int32)snd_ctrl->rb_base[ snd_ctrl->read ];

   			sndShiftReadPointer(snd_ctrl , 1);
            snd_ctrl->dvi_dataCount = 1;
            snd_ctrl->dvi_blockCounter = 2;
         }
         else
			{
            sndDVIADPCM_DecodeWord((uint16)data, snd_ctrl);

   			sndShiftReadPointer(snd_ctrl , 1);
            snd_ctrl->dvi_dataCount = 4;
            snd_ctrl->dvi_blockCounter++;
				
            if(snd_ctrl->dvi_blockCounter == (snd_ctrl->info.blockAlign>>1))
               snd_ctrl->dvi_blockCounter = 0;
         }
      }
      sample = snd_ctrl->dvi_data[--snd_ctrl->dvi_dataCount]; 
		*write_ptr++ = sample;

	   if( snd_ctrl->total_consume_bytes >= snd_ctrl->info.dataChunkSize )
		{
			snd_ctrl->total_consume_bytes = 0;				
   	   if(snd_ctrl->info.formatTag == 0x0011)
			{		
		     	dviAdpcm_Init( &snd_ctrl->dvi_state );
   		   snd_ctrl->dvi_dataCount = 0;
      		snd_ctrl->dvi_blockCounter = 0;			
	      }
			elapse_sample=I;
			break;
	   }
   }

   snd_ctrl->dsp_last_sample = sample;
  
   // Fill silence to DSP if buffer underflow   
	if(snd_ctrl->total_consume_bytes == 0)	
		numSamples_fill_silence = dp_sound_effect_len - elapse_sample; 
	else
	   numSamples_fill_silence = dp_sound_effect_len - numSamples; /* number of silence samples */

   for(I=numSamples_fill_silence ; I>0; I--){ 
		*write_ptr++ = snd_ctrl->dsp_last_sample; 		
   }
}

/* ------------------------------------------------------------------------------ */

static int32 sndGetFreeSpace( SndControl *snd_ctrl )
{
   int32 count;
   count = (int32)snd_ctrl->read - (int32)snd_ctrl->write - 1;
   if( count < 0 )
      count += (int32)snd_ctrl->rb_size;
   return count;
}

static int32 sndGetDataCount( SndControl *snd_ctrl )
{
   int32 count = (int32)snd_ctrl->write - (int32)snd_ctrl->read;
   if( count < 0 )
      count += snd_ctrl->rb_size;
   return count;
}

void sndCallbackTask(void *data)
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)data;  	
   handle->mh.handler( (Media_Handle *)handle, (Media_Event)handle->mh.data );	
   //L1Audio_InProcCall2( sndProcess, handle->mh.data, (void *) handle );	
}


static void sndSetEvent( SndControl *snd_ctrl, Media_Event event )
{
   mhandle *handle = (mhandle *)snd_ctrl->parent;
   handle->data = (kal_uint32)event;
   L1Audio_SetEvent( snd_ctrl->aud_id, (void *)handle );
}

static void sndDataRequest( SndControl *snd_ctrl )
{
   if( snd_ctrl->waiting || snd_ctrl->eof || (snd_ctrl->end_status != MEDIA_NONE) )
      return;
	
   if( sndGetFreeSpace(snd_ctrl) >= snd_ctrl->rb_threshold ) {
      sndSetEvent( snd_ctrl, MEDIA_DATA_REQUEST );
      snd_ctrl->waiting = true;
   }
}

static void sndUpdateMixer( SndControl *snd_ctrl )
{
   if(AM_IsSpeechOn())
   {
      *DSP_SOUND_EFFECT_SPH_STATE = ((snd_ctrl->bULSPHFlag==KAL_TRUE)?2:0) | ((snd_ctrl->bDLSPHFlag==KAL_TRUE)?1:0);		
   }	
   else
   {
      *DSP_SOUND_EFFECT_SPH_STATE = 0;			
   }	
   *DSP_SOUND_EFFECT_UL_GAIN = snd_ctrl->ULSNDGain;
   *DSP_SOUND_EFFECT_DL_GAIN = snd_ctrl->DLSNDGain;
}


__inline int16 sndSetSampleAmplitude(int16 sample, int16 arg)
{
   return((sample*arg)>>15);
}

#if VORTP_SUPPORT
void sndMixSNDToVMI( void *data )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)data;
   SndControl *snd_ctrl = &handle->snd_ctrl;
	PCMRB *rb= & snd_ctrl->vmi_handle->rb;   
   int32 write_cnt;	
   int32 I;
	int16 *write_ptr = snd_ctrl->spk_buffer;
	int16 *rb_write_ptr;	
   int16 gain = snd_ctrl->level;	
   
   if( snd_ctrl->end_status != MEDIA_NONE )
      return;   
 
   if(AM_IsULSpeechMuted() == true){
      snd_ctrl->vmi_handle->mix = 0;
   }
   else{
      snd_ctrl->vmi_handle->mix = 1;
   }

   snd_ctrl->SND_PutData(snd_ctrl);
   PCMRB_GetWriteBlock( rb , &rb_write_ptr, &write_cnt );
   ASSERT( write_cnt >= DSP_BUFFER_LEN );

	for(I=DSP_BUFFER_LEN; I>0 ; I-=4){
      *rb_write_ptr++ = ((*write_ptr++) * gain) >> 15;
      *rb_write_ptr++ = ((*write_ptr++) * gain) >> 15;
      *rb_write_ptr++ = ((*write_ptr++) * gain) >> 15;
      *rb_write_ptr++ = ((*write_ptr++) * gain) >> 15;		
	}

   PCMRB_ShiftWritePointer( rb, DSP_BUFFER_LEN );
	
   if( sndGetDataCount(snd_ctrl) == 0 && snd_ctrl->eof) 
	{
      snd_ctrl->end_status = MEDIA_END;
      sndSetEvent( snd_ctrl, MEDIA_END );
   }
   else
      sndDataRequest(snd_ctrl);
}
#endif

static void sndHisr(void *data)
{
    sndMediaHandleInternal *handle = (sndMediaHandleInternal *)data;
    SndControl *snd_ctrl = &handle->snd_ctrl;
    Snd_Param *param = (Snd_Param *)handle->mh.param;
    
    int16 *write_ptr = snd_ctrl->spk_buffer;
    
    if (   snd_ctrl->end_status != MEDIA_NONE
        || *DSP_SOUND_EFFECT_CTRL != DP_SND_STATE_PLAYING)
    {
        return;
    }
#if defined(AMR_CODEC)     
    if(param->format == MEDIA_FORMAT_AMR)
    {
    	 L1Audio_SetEvent( snd_ctrl->amr_dec_id, snd_ctrl );
    }
    else
#endif    	
    {
       snd_ctrl->SND_PutData(snd_ctrl);
    }
#if defined(__BT_SUPPORT__)
    if (snd_ctrl->snd_state == SND_STATE_STOPPING)
    {
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
        uint16 dsp_sound_effect_len = *DSP_SOUND_EFFECT_LEN_UL;
#else   // chip compile option
        uint16 dsp_sound_effect_len = *DSP_SOUND_EFFECT_LEN;
#endif  // chip compile option
        memset(write_ptr, 0, dsp_sound_effect_len * sizeof(uint16));
    }
#endif

    sndUpdateMixer(snd_ctrl);
    
#ifdef _FWE_SUPPORT_
    if (AM_IsFWEOn())
    {
#if defined(MT6250)
        SRCHandle* handle = snd_ctrl->src_handle;
        doSRC(handle, write_ptr, 160, temp);
        
        IDMA_WriteToDSP(DSP_DM_ADDR(5, 0x2081), (kal_uint16 *)temp,      (kal_uint32)320);  //DL WB
        IDMA_WriteToDSP(DSP_DM_ADDR(5, 0x1F41), (kal_uint16 *)write_ptr, (kal_uint32)160);  //UL NB
        IDMA_WriteToDSP(DSP_DM_ADDR(5, 0x1FE1), (kal_uint16 *)write_ptr, (kal_uint32)160);  //UL NB
        write_ptr += 160;
#elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
        uint16 dsp_sound_effect_dl_addr = *DSP_SOUND_EFFECT_DL_ADDR;
        uint16 dsp_sound_effect_dl_len  = *DSP_SOUND_EFFECT_LEN_DL;
        uint16 dsp_sound_effect_ul_addr = *DSP_SOUND_EFFECT_UL_ADDR;
        uint16 dsp_sound_effect_ul_len  = *DSP_SOUND_EFFECT_LEN_UL;
        SRCHandle* handle = snd_ctrl->src_handle;
        
        ASSERT(dsp_sound_effect_dl_len == 320);
        ASSERT(dsp_sound_effect_ul_len == 160);
        doSRC(handle, write_ptr, 160, temp);
        
        IDMA_WriteToDSP(DSP_DM_ADDR(PAGE_NUM, dsp_sound_effect_dl_addr), (kal_uint16 *)temp,      (kal_uint32)dsp_sound_effect_dl_len); //DL WB
        IDMA_WriteToDSP(DSP_DM_ADDR(PAGE_NUM, dsp_sound_effect_ul_addr), (kal_uint16 *)write_ptr, (kal_uint32)dsp_sound_effect_ul_len); //UL NB
        write_ptr += 160;
#endif  // chip compile option
	}
	else
#endif	   
    {
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
        uint16 dsp_sound_effect_dl_addr = *DSP_SOUND_EFFECT_DL_ADDR;
        uint16 dsp_sound_effect_dl_len  = *DSP_SOUND_EFFECT_LEN_DL;
        uint16 dsp_sound_effect_ul_addr = *DSP_SOUND_EFFECT_UL_ADDR;
        uint16 dsp_sound_effect_ul_len  = *DSP_SOUND_EFFECT_LEN_UL;
        
        ASSERT(dsp_sound_effect_dl_len == dsp_sound_effect_ul_len); // UL / DL should both be 160 in this case
        IDMA_WriteToDSP(DSP_DM_ADDR(PAGE_NUM, dsp_sound_effect_dl_addr), (kal_uint16 *)write_ptr, (kal_uint32)dsp_sound_effect_dl_len); //DL NB
        IDMA_WriteToDSP(DSP_DM_ADDR(PAGE_NUM, dsp_sound_effect_ul_addr), (kal_uint16 *)write_ptr, (kal_uint32)dsp_sound_effect_ul_len); //UL NB
        write_ptr += dsp_sound_effect_dl_len;
#else   // chip compile option
        uint16 dsp_sound_effect_addr = *DSP_SOUND_EFFECT_ADDR;
        uint16 dsp_sound_effect_len  = *DSP_SOUND_EFFECT_LEN;
        
        IDMA_WriteToDSP(DSP_DM_ADDR(PAGE_NUM, dsp_sound_effect_addr), (kal_uint16 *)write_ptr, (kal_uint32)dsp_sound_effect_len);
        write_ptr += dsp_sound_effect_len;
#endif  // chip compile option
    }
    
    if (sndGetDataCount(snd_ctrl) == 0 && snd_ctrl->eof)
    {
        *DSP_SOUND_EFFECT_CTRL = DP_SND_STATE_STOPPED;
        snd_ctrl->end_status = MEDIA_END;
        sndSetEvent(snd_ctrl, MEDIA_END);
    }
    else
    {
        sndDataRequest(snd_ctrl);
    }
    
    return;
}

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
static void snd_hisr_ul(void *data)
{
    sndMediaHandleInternal *handle = (sndMediaHandleInternal *)data;   
    SndControl *snd_ctrl = &handle->snd_ctrl;
    
    if (snd_ctrl->hisr_state == 0 || snd_ctrl->hisr_state == 1)
    {
        snd_ctrl->hisr_state = 1;
    }
    else if (snd_ctrl->hisr_state == 2)
    {
        snd_ctrl->hisr_state = 4;
        sndHisr(data);
        snd_ctrl->hisr_state = 0;
    }
    else
    {
        ASSERT(0);
    }
    return;
}

static void snd_hisr_dl(void *data)
{
    sndMediaHandleInternal *handle = (sndMediaHandleInternal *)data;   
    SndControl *snd_ctrl = &handle->snd_ctrl;
    
    if (snd_ctrl->hisr_state == 0 || snd_ctrl->hisr_state == 2)
    {
        snd_ctrl->hisr_state = 2;
    }
    else if (snd_ctrl->hisr_state == 1)
    {
        snd_ctrl->hisr_state = 3;
        sndHisr(data);
        snd_ctrl->hisr_state = 0;
    }
    else
    {
        ASSERT(0);
    }
    return;
}
#endif  // chip compile option

/* ------------------------------------------------------------------------------ */

static void sndDataFinished( SndControl *snd_ctrl )
{
   snd_ctrl->eof = true;
}

static void sndWriteDataDone( SndControl *snd_ctrl, uint32 len )
{
   snd_ctrl->write += len;
   if( snd_ctrl->write >= snd_ctrl->rb_size )
      snd_ctrl->write = 0;
   snd_ctrl->waiting = false;
}

static void sndGetWriteBuffer( SndControl *snd_ctrl, int16 **buffer, uint32 *buf_len )
{
   int32 count;
   if( snd_ctrl->read > snd_ctrl->write )
      count = (int32)snd_ctrl->read - (int32)snd_ctrl->write - 1;
   else if( snd_ctrl->read == 0 )
      count = (int32)snd_ctrl->rb_size - (int32)snd_ctrl->write - 1;
   else
      count = (int32)snd_ctrl->rb_size - (int32)snd_ctrl->write;

   *buffer = &snd_ctrl->rb_base[snd_ctrl->write];
   *buf_len = (uint32)count;
}


static void sndGetReadBuffer( SndControl *snd_ctrl, int16 **buffer, uint32 *buf_len )
{
   int32 count;
   if( snd_ctrl->write > snd_ctrl->read )
      count = (int32)snd_ctrl->write - (int32)snd_ctrl->read;
   else 
      count = (int32)snd_ctrl->rb_size - (int32)snd_ctrl->read;

   *buffer = &snd_ctrl->rb_base[snd_ctrl->read];
   *buf_len = (uint32)count;
}

static void sndFillBuffer( sndMediaHandleInternal *handle, bool bIsStarted ) /* return the repeat status */
{
   SndControl *snd_ctrl = &handle->snd_ctrl;
   Snd_Param *param = (Snd_Param *)handle->mh.param;
   uint32 I;
   FSAL_Status status;

   for(I=0; I<2; I++)
   { /* 2-stage filling */
  	  uint32 nBytes;
     	int16 *write_ptr;
      uint32 write_len;

     	sndGetWriteBuffer( snd_ctrl, &write_ptr, &write_len );
		
      if(write_len == 0)
  	      break;
			
      nBytes = write_len<<1;
	
  	  if(nBytes > (snd_ctrl->info.dataChunkSize-snd_ctrl->total_write_bytes))
     	{
     	   nBytes = snd_ctrl->info.dataChunkSize-snd_ctrl->total_write_bytes;
		  }
      
      
      nBytes &= ~1;
	    if( nBytes==0 )
     	{
     	    break;
	    }
	    
      status = FSAL_Read( param->pstFSAL, (kal_uint8 *)write_ptr, nBytes );
      
  	  if( FSAL_OK != status )
     	{		
			    if((FSAL_READ_ERROR == status) || (FSAL_FATAL_ERROR == status))
			    {
			    	sndSetEvent( snd_ctrl, MEDIA_ERROR );
			    	return;
			    }
		
        	if( FSAL_DEVICE_BUSY == status )
          {
#ifdef L1SND_TRC_ON
  	         kal_trace( TRACE_INFO, L1SND_DATACHUNK_SIZE, -1 );
#endif
     	      snd_ctrl->waiting = false;
        	}
          break; // snd_ctrl->waiting will be hold to true
  	   }

     	sndWriteDataDone( snd_ctrl, nBytes>>1 );
      snd_ctrl->total_write_bytes += nBytes;		
  	}
	
#ifdef L1SND_TRC_ON
   kal_trace( TRACE_GROUP_SND, L1SND_FILLBUFFER, snd_ctrl->total_write_bytes );
#endif

   if( !bIsStarted )
      return;

   if( snd_ctrl->total_write_bytes >= snd_ctrl->info.dataChunkSize )
	 {
       if( handle->mh.repeat_count == 1 )
	 	   {			
          sndDataFinished(snd_ctrl);
          return;
       }
       else      
	 	   {
	 		    status = FSAL_Seek(param->pstFSAL, snd_ctrl->info.dataChunkOffset);
          if( FSAL_OK != status )
          {
	 			      sndSetEvent( snd_ctrl, MEDIA_ERROR );					
	 			      return;
          }
	 			
          snd_ctrl->total_write_bytes = 0;
   
	 		    if( handle->mh.repeat_count > 1 )
             handle->mh.repeat_count--;		
   
          L1Audio_SetEvent( snd_ctrl->aud_id, (void *)handle );           				
          return;
       }
   }

   return;
}

void sndProcess( Media_Handle *hdl )
{ 
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;   
   Media_Event event = (Media_Event)handle->mh.data;
   SndControl *snd_ctrl = &handle->snd_ctrl;
   
   if(event == MEDIA_DATA_REQUEST){
      if( snd_ctrl->end_status==MEDIA_NONE ) {

			sndFillBuffer( handle, true );
      }
   }
   return;
}

/* ------------------------------------------------------------------------------ */
#define RIFF_ID  0x46464952
#define MTK_ID  0x2044544D
#define WAVE_ID  0x45564157
#define FMT_ID  0x20746D66
#define DATA_ID  0x61746164

static bool sndParser(STFSAL *pstFSAL, sndHeader *info) /* Parse RIFF/MTK header, fmt Chunk, seek data Chunk */
{
   uint32 curPos=0, fileSize;
   uint32 cache_32;
   int32 extendedHeaderSize;
   uint16 cache_16;   
   
   if( FSAL_OK != FSAL_GetFileSize(pstFSAL, (kal_uint32 *)&fileSize) )
      return false;
   if( FSAL_OK != FSAL_Seek(pstFSAL, 0) )
      return false;

   /* Parse Chunk ID, RIFF/MTK */
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK)
      return false;
   curPos += 4;

   /* Parse WAV info */
   if(cache_32 == RIFF_ID){ /* RIFF file */
      curPos += 4;
      if(FSAL_Seek(pstFSAL, curPos) != FSAL_OK) /* Skip Chunk Data Size */
         return false;
      if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK)
         return false;
      curPos += 4;
      if(cache_32 != WAVE_ID)
         return false;
   }
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
#endif
   else 
      return false;
   
   /* Seek RIFF fmt Chunk */
   while(1){
      if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK)
         return false;
      curPos += 4;

      if(cache_32 == FMT_ID)
         break;

      if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK) /* Get Chunk Size */
         return false;
      curPos += 4;
      curPos += cache_32;
      if(FSAL_Seek(pstFSAL, curPos) != FSAL_OK) /* Skip Chunk Data */
         return false;
   }

   /* Parse RIFF fmt Chunk */
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK) /* Get Chunk Size */
      return false;
   curPos += 4;
   extendedHeaderSize = (int32)cache_32-16;
   if(extendedHeaderSize < 0) /* fmt Chunk Size should be > 16 */
      return false;

   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_16, 2) != FSAL_OK) /* Get formatTag */
      return false;
   curPos += 2;
   info->formatTag = cache_16;
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_16, 2) != FSAL_OK) /* Get numChannel */
      return false;
   curPos += 2;
   info->numChannels = cache_16;
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK) /* Get sampleRate */
      return false;
   curPos += 4;
   info->sampleRate = cache_32;
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK) /* Get avgBytesPerSec */
      return false;
   curPos += 4;
   info->avgBytesPerSec = cache_32;
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_16, 2) != FSAL_OK) /* Get blockAlign */
      return false;
   curPos += 2;
   info->blockAlign = cache_16;
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_16, 2) != FSAL_OK) /* Get bitsPerSample */
      return false;
   curPos += 2;
   info->bitsPerSample = cache_16;

   /* Locate Extended Header */
   if(extendedHeaderSize > 2){
      if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_16, 2) != FSAL_OK) /* Get bitsPerSample */
         return false;
      curPos += 2;
      extendedHeaderSize -= 2;
      
      info->extHeaderOffset = curPos;
      info->extHeaderSize = ((uint16)extendedHeaderSize < cache_16)? (uint16)extendedHeaderSize: cache_16;
   }
   else{
      info->extHeaderOffset = 0;
      info->extHeaderSize = 0;
   }
	
   curPos += extendedHeaderSize;
   if(FSAL_Seek(pstFSAL, curPos) != FSAL_OK) /* Skip Extended Header */
      return false;

   /* Seek data Chunk */   
   while(1){
      if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK)
         return false;
      curPos += 4;

      if(cache_32 == DATA_ID)
         break;

      if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK) /* Get Chunk Size */
         return false;
      curPos += 4;
      curPos += cache_32;
      if(FSAL_Seek(pstFSAL, curPos) != FSAL_OK) /* Skip Chunk Data */
         return false;
   }

   /* Get RIFF data Chunk */
   if(FSAL_Read(pstFSAL, (kal_uint8 *)&cache_32, 4) != FSAL_OK) /* Get Chunk Size */
      return false;
   curPos += 4;
   info->dataChunkOffset = curPos;
   info->dataChunkSize = (cache_32<(fileSize-curPos))?cache_32:(fileSize-curPos);

   info->dataChunkSize &= ~1;

   return true;
}

/* ------------------------------------------------------------------------------ */

/*
 * Description
 * ---------
 *   The function is used to check if the sound format of a FSAL instance is supported 
 *   by this SND interface.
 *
 * Syntax
 * ---------
 *   Media_Status SND_GetFormat( STFSAL *pstFSAL, Media_Format *pFormat );
 *
 * where
 *   pstFSAL   The pointer to the FSAL instance
 *   pFormat   The pointer to the sound format of the FSAL instance. It is valid only 
 *             when the function return
 *
 * Return Value
 * ---------
 *   Media_Status   Return MEDIA_SUCCESS if this SND interface supports the sound 
 *                  format of the FSAL instance. Return MEDIA_BAD_FORMAT otherwise.
 */
Media_Status SND_GetFormat(STFSAL *pstFSAL, Media_Format *pFormat)
{
   sndHeader info;
   
#if defined(AMR_CODEC) 
   if(*pFormat == MEDIA_FORMAT_AMR)
   {
   	  kal_uint32 FirstFrameOffset;
    	Media_Format uMediaType; 
    	
    	uMediaType = amrChkFileHeader(pstFSAL, &FirstFrameOffset);
    	
    	if(uMediaType != MEDIA_FORMAT_AMR)
      {
        return MEDIA_BAD_FORMAT;
      }
      *pFormat = uMediaType;      
   }
   else
#endif
   {
      if(sndParser(pstFSAL, &info) == false)
         return MEDIA_BAD_FORMAT;
      if( (info.numChannels != 1) || 
      	(info.sampleRate != 8000) || 
      	(info.dataChunkSize < 2) )
         return MEDIA_BAD_FORMAT;
      
      switch( info.formatTag ) {
         case 0x0001:
         	  if(info.bitsPerSample != 16 && info.bitsPerSample != 8)
         	     return MEDIA_BAD_FORMAT;
            *pFormat = MEDIA_FORMAT_PCM_8K;
         	  break;
         case 0x0006:
         	  if(info.bitsPerSample != 8)
               return MEDIA_BAD_FORMAT;
            *pFormat = MEDIA_FORMAT_G711_ALAW;
            break;
         case 0x0007:
         	  if(info.bitsPerSample != 8)
               return MEDIA_BAD_FORMAT;
            *pFormat = MEDIA_FORMAT_G711_ULAW;
            break;
         case 0x0011:
            if(info.bitsPerSample != 4)
               return MEDIA_BAD_FORMAT;
         	  if((info.blockAlign&1) != 0)
         	     return MEDIA_BAD_FORMAT;
         	  *pFormat = MEDIA_FORMAT_DVI_ADPCM;
         	  break;	  
         default:
            return MEDIA_BAD_FORMAT;
      }
   }
   return MEDIA_SUCCESS;
}

/*
 * Description
 * ---------
 *   The function sets the output device.
 *
 * Syntax
 * ---------
 *   void SND_SetOutputDevice( kal_uint8 device );
 *
 * where
 *   device   The output device (L1SP_SPEAKER1, L1SP_SPEAKER2, L1SP_LOUD_SPEAKER)
 *
 * Return Value
 * ---------
 *   None
 */
void SND_SetOutputDevice( kal_uint8 device )
{
   if( !AM_IsSpeechOn() && !AM_IsVoIPOn())
      AFE_SetOutputDevice( L1SP_SND_EFFECT, device );
}

/*
 * Description
 * ---------
 *   The function sets the playback mode. The function can be invoked after the media 
 *   handle is opened and during the media handle is playing.
 *
 * Syntax
 * ---------
 *   void SND_ConfigULMixer( Media_Handle *hdl, kal_bool bULSPHFlag, kal_int8 ULSNDGain );
 *   void SND_ConfigDLMixer( Media_Handle *hdl, kal_bool bDLSPHFlag, kal_int8 DLSNDGain );
 *
 * where
 *   hdl   The media handle
 *   bULSPHFlag   Mixer switch for uplink speech
 *   ULSNDGain   Sound effect gain for uplink mixer
 *   bDLSPHFlag   Mixer switch for downlink speech
 *   DLSNDGain   Sound effect gain for downlink mixer
 *
 * Return Value
 * ---------
 *   None
 */
void SND_ConfigULMixer( Media_Handle *hdl, kal_bool bULSPHFlag, kal_int8 ULSNDGain )
{
   kal_int16 gain = 0;
   ASSERT(ULSNDGain>=0 && ULSNDGain<=7);
   if( ULSNDGain!=0 )
      gain = (kal_int16)(32767>>(7 - ULSNDGain));
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.bULSPHFlag = bULSPHFlag;
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.ULSNDGain = gain;

   ((sndMediaHandleInternal *)hdl)->snd_ctrl.level = gain;
   
#ifdef L1SND_TRC_ON
   kal_trace( TRACE_INFO, L1SND_CONFIG_ULMIXER, bULSPHFlag, ULSNDGain );
#endif
}
void SND_ConfigDLMixer( Media_Handle *hdl, kal_bool bDLSPHFlag, kal_int8 DLSNDGain )
{
   kal_int16 gain = 0;
   ASSERT(DLSNDGain>=0 && DLSNDGain<=7);
   if( DLSNDGain!=0 )
      gain = (kal_int16)(32767>>(7 - DLSNDGain));
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.bDLSPHFlag = bDLSPHFlag;
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.DLSNDGain = gain;

   ((sndMediaHandleInternal *)hdl)->snd_ctrl.level = gain;
	
#ifdef L1SND_TRC_ON
   kal_trace( TRACE_INFO, L1SND_CONFIG_DLMIXER, bDLSPHFlag, DLSNDGain );
#endif
}

/*
 * Description
 * ---------
 *   The function opens a handle for background sound playback. It should be invoked 
 *   before any other operation.
 *
 * Syntax
 * ---------
 *   Media_Handle *SND_Open(void(*handler)(Media_Handle *, Media_Event ), 
 *   Snd_Param **param);
 *
 * where
 *   handler   A callback function used for handling MEDIA_END event.
 *   param     Specific parameter for the background sound playback.
 *
 * Return Value
 * ---------
 *   Media_Handle   The media handle
 */
 
//#include "med_utility.h"
//extern void*  med_alloc_aud_mem(kal_int32 size);
//extern void   med_free_aud_mem(void** pointer);

 Media_Handle *SND_Open(void(*handler)(Media_Handle *, Media_Event ), Snd_Param **param)
{
   sndMediaHandleInternal *handle;
   Snd_Param *pparam;
   SndControl *snd_ctrl;
	kal_uint32 buf_len;	
   kal_uint8 *ctrl_buffer;	
		
#ifdef L1SND_TRC_ON
   kal_trace( TRACE_GROUP_SND, L1SND_ENTER_SND_OPEN );
#endif

   ASSERT( handler != 0 );

	buf_len = sizeof(sndMediaHandleInternal)
				  + sizeof(Snd_Param)
		        + 2*DP_BUFFER_DEFAULT_LEN*sizeof(int16) 
		        + 2*DSP_BUFFER_LEN*sizeof(int16);
	
	ctrl_buffer = (kal_uint8 *)audio_alloc_mem(buf_len);
	ASSERT(ctrl_buffer != NULL);

   handle = (sndMediaHandleInternal *)ctrl_buffer;
   ctrl_buffer += sizeof(sndMediaHandleInternal);
   
   pparam = (Snd_Param *)ctrl_buffer;
   ctrl_buffer += sizeof(Snd_Param);
   
   pparam->pstFSAL = NULL; // Should be initiated by caller 
   pparam->repeats = 1; // default 
   pparam->format = (Media_Format)-1; // Should be initiated by caller 

   snd_ctrl = &handle->snd_ctrl;
   snd_ctrl->bULSPHFlag = KAL_TRUE;
   snd_ctrl->bDLSPHFlag = KAL_TRUE;
   snd_ctrl->ULSNDGain = 32767; // default: full scale
   snd_ctrl->DLSNDGain = 32767; // default: full scale
#if defined(__BT_SUPPORT__)
   snd_ctrl->snd_state = 0;
#endif

   if(AM_IsVoIPOn() == false)
		sndUpdateMixer(snd_ctrl);
   
   snd_ctrl->aud_id = L1Audio_GetAudioID();
   snd_ctrl->rb_threshold = SND_RB_DEFAULT_THRESHOLD;
   snd_ctrl->rb_size = 2*DP_BUFFER_DEFAULT_LEN;
   snd_ctrl->rb_base = (int16 *)ctrl_buffer;

   ctrl_buffer += 2*DP_BUFFER_DEFAULT_LEN*sizeof(int16);
   snd_ctrl->spk_buffer = (int16 *)ctrl_buffer;
   snd_ctrl->level = 32767;
   snd_ctrl->parent = (void *)handle;

   handle->mh.handler = handler;
   handle->mh.volume_level = 100;
   handle->mh.param = (void *)pparam;
	
   L1Audio_SetEventHandler( snd_ctrl->aud_id, sndCallbackTask );	
   AFE_SetOutputVolume( L1SP_SND_EFFECT, 200, 0 );
	
   *param = pparam;

#ifdef _FWE_SUPPORT_   
   snd_ctrl->src_handle = allocSRC(8000, 16000);
#endif   

   return((Media_Handle *)handle);
}

/*
 * Description
 * ---------
 *   The function starts the background sound playback of the media handle.
 *
 * Syntax
 * ---------
 *   Media_Status SND_Play( Media_Handle *hdl );
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   Media_Status   MEDIA_SUCCESS => Background sound has been played.
 *                  MEDIA_REENTRY	=> Reentrance has occurred. Operation aborted.
 *                  MEDIA_NOT_INITIALIZED =>	The media handle is invalid. Operation 
 *                                            aborted.
 *                  MEDIA_BAD_FORMAT =>	Bad sound format. Operation aborted.
 */
Media_Status SND_Play( Media_Handle *hdl )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;   
   SndControl *snd_ctrl = &handle->snd_ctrl;
   Snd_Param *param = (Snd_Param *)handle->mh.param;
	kal_int32 rb_buffer_size	= 2*DSP_BUFFER_LEN*sizeof(int16); 

#if defined(AMR_CODEC)  
  kal_uint32 uAmrSize;
  kal_uint32  int_buf_size, tmp_buf_size, bs_buf_size, pcm_buf_size;
  kal_uint8 *pBuffer = NULL;
#endif

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif
   PcmSink_TerminateSound();

#ifdef L1SND_TRC_ON
    kal_trace( TRACE_GROUP_SND, L1SND_ENTER_SND_PLAY );
#endif
    
    ASSERT(param->pstFSAL != NULL);
    
    if (L1Audio_CheckFlag( snd_ctrl->aud_id ))
    {
        return MEDIA_REENTRY;
    }
    
    if (snd_ctrl->rb_base == (int16*)0)
    {
        return MEDIA_NOT_INITIALIZED;
    }
    
    handle->mh.repeat_count = param->repeats;
    
    snd_ctrl->read            = 0;
    snd_ctrl->write           = 0;
    snd_ctrl->eof             = false;
   
    snd_ctrl->dsp_last_sample = 0;
    snd_ctrl->end_status      = MEDIA_NONE;
    snd_ctrl->waiting         = false;

#if defined(AMR_CODEC)    
    if(param->format == MEDIA_FORMAT_AMR || param->format ==MEDIA_FORMAT_AMR_WB)
    {
    	 kal_uint32 FirstFrameOffset;
    	 Media_Format uMediaType; 
    	 Media_Status result;
    	 kal_uint32 fileLen;
    	 uMediaType = amrChkFileHeader(param->pstFSAL, &FirstFrameOffset);
    	 
    	 if(uMediaType != MEDIA_FORMAT_AMR)
       {
         return MEDIA_BAD_FORMAT;
       }
       
       result = amr_InitDecoder(snd_ctrl);
       if(result != MEDIA_SUCCESS)
       {
      	  return MEDIA_FAIL; 
       }
       if (MEDIA_FORMAT_AMR == uMediaType ) 
       { 
          snd_ctrl->info.sampleRate = 8000;
          snd_ctrl->info.dataChunkOffset = FirstFrameOffset;
       }
       else
       {
      	  return MEDIA_BAD_FORMAT;
       }   	       	
       snd_ctrl->SND_PutData = sndPutData_AMR;
       FSAL_GetFileSize(param->pstFSAL, &fileLen);         	     	     	 
       snd_ctrl->info.dataChunkSize = fileLen - FirstFrameOffset;
       snd_ctrl->amr_dec_id = L1Audio_GetAudioID();
       L1Audio_SetEventHandler( snd_ctrl->amr_dec_id, snd_ctrl->SND_PutData );
    }
    else
#endif
    {    	 
        if (sndParser(param->pstFSAL, &snd_ctrl->info) == false)
        {
            return MEDIA_BAD_FORMAT;
        }
        
        if (   snd_ctrl->info.numChannels != 1
            || snd_ctrl->info.sampleRate != 8000
            || snd_ctrl->info.dataChunkSize < 2)
        {
            return MEDIA_BAD_FORMAT;
        }
        switch (snd_ctrl->info.formatTag)
        {
            case 0x0001:
                if (snd_ctrl->info.bitsPerSample != 16 && snd_ctrl->info.bitsPerSample != 8)
                {
                    return MEDIA_BAD_FORMAT;
                }
                param->format = MEDIA_FORMAT_PCM_8K;
                snd_ctrl->SND_PutData = sndPutData_PCM;
                break;
            case 0x0006:
                if (snd_ctrl->info.bitsPerSample != 8)
                {
                    return MEDIA_BAD_FORMAT;
                }
                param->format = MEDIA_FORMAT_G711_ALAW;
                snd_ctrl->SND_PutData = sndPutData_Alaw;
                break;
            case 0x0007:
                if (snd_ctrl->info.bitsPerSample != 8)
                {
                    return MEDIA_BAD_FORMAT;
                }
                param->format = MEDIA_FORMAT_G711_ULAW;
                snd_ctrl->SND_PutData = sndPutData_Ulaw;
                break;
            case 0x0011:
                if (snd_ctrl->info.bitsPerSample != 4 || (snd_ctrl->info.blockAlign & 1) != 0)
                {
                    return MEDIA_BAD_FORMAT;
                }
                param->format = MEDIA_FORMAT_DVI_ADPCM;
                snd_ctrl->SND_PutData = sndPutData_DVIADPCM;
                dviAdpcm_Init(&snd_ctrl->dvi_state);
                break;               
            default:
                return MEDIA_BAD_FORMAT;
        }
    }
    if (FSAL_OK != FSAL_Seek(param->pstFSAL, snd_ctrl->info.dataChunkOffset))
    {
        return MEDIA_FAIL;
    }
    
    snd_ctrl->total_consume_bytes = 0;
    snd_ctrl->total_write_bytes   = 0;
    snd_ctrl->dvi_dataCount       = 0;
    snd_ctrl->dvi_blockCounter    = 0;
   sndFillBuffer( handle, false );

   L1Audio_SetFlag( snd_ctrl->aud_id );

#ifdef L1SND_TRC_ON
    kal_trace(TRACE_INFO, L1SND_DATACHUNK_SIZE, snd_ctrl->info.dataChunkSize);
#endif
    
#if VORTP_SUPPORT
    if (AM_IsVoIPOn() == true)
    {
        snd_ctrl->vmi_handle = VMI_GetHandle(VMI_DIR_DL, (uint8 *)snd_ctrl->spk_buffer , rb_buffer_size);
        ASSERT(snd_ctrl->vmi_handle != NULL);
        snd_ctrl->vmi_handle->mix        = 1;
        snd_ctrl->vmi_handle->session_id = 0xffffAA55;
        snd_ctrl->vmi_handle->callback   = NULL;
        snd_ctrl->vmi_handle->host_data  = (void *)0;
        {
            VMI_STATUS eStatus = VMI_Start(snd_ctrl->vmi_handle);
            ASSERT(eStatus ==VMI_STATUS_SUCCESS);   // PCM4WAY Start
        }
        Vortp_HookSndHandler(sndMixSNDToVMI, handle);
    }
    else
#endif
	{		    
        snd_ctrl->vmi_handle = NULL;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
        snd_ctrl->hisr_state = 0;
        L1Audio_HookHisrHandler(DP_D2C_BGS_UL, snd_hisr_ul, (void *)handle);
        L1Audio_HookHisrHandler(DP_D2C_BGS_DL, snd_hisr_dl, (void *)handle);
#else   // chip compile option
        L1Audio_HookHisrHandler(SND_EFFECT_MAGIC_NO, sndHisr, (void *)handle);
#endif  // chip compile option
        KT_StopAndWait();
        AM_SND_PlaybackOn();
        *DSP_SOUND_EFFECT_CTRL = DP_SND_STATE_READY;
        {
            uint32 I = 0;
            do 
            {
                if (*DSP_SOUND_EFFECT_CTRL == DP_SND_STATE_PLAYING || snd_ctrl->end_status == MEDIA_END)
                {
                    break;
                }
                ASSERT_REBOOT(I < 20);
                kal_sleep_task(2);
                I++;
            } while(1);
        }
    }
#if defined(__CVSD_CODEC_SUPPORT__) 
    if (L1SP_IsSpeechOn())
    {
        kal_uint32 uCurrentSpMode = L1SP_GetSpeechMode();
        if (uCurrentSpMode == SPH_MODE_BT_EARPHONE || uCurrentSpMode == SPH_MODE_BT_CARKIT)
        {
            BT_SCO_Disable_All_APP();
            BT_SCO_SpeechPath_ON(BT_SCO_APP_SPEECH_PATH_BOTH);
        }
    }
#endif
   return MEDIA_SUCCESS;
}

/*
 * Description
 * ---------
 *   The function stops the background sound playback of the media handle.
 *
 * Syntax
 * ---------
 *   void SND_Stop( Media_Handle *hdl );
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   None
 */
void SND_Stop( Media_Handle *hdl )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;   
   SndControl *snd_ctrl = &handle->snd_ctrl;
   Snd_Param *param = (Snd_Param *)handle->mh.param;

#ifdef L1SND_TRC_ON
    kal_trace(TRACE_GROUP_SND, L1SND_ENTER_SND_STOP);
#endif
    
    if (!L1Audio_CheckFlag( snd_ctrl->aud_id ))
    {
        return;
    }
    
    snd_ctrl->waiting = true;   // Forbid data request
    
    switch (param->format)
    {
        case MEDIA_FORMAT_PCM_8K:
        case MEDIA_FORMAT_G711_ALAW:
        case MEDIA_FORMAT_G711_ULAW:
        case MEDIA_FORMAT_DVI_ADPCM:
        case MEDIA_FORMAT_AMR:
            {
                snd_ctrl->end_status = MEDIA_TERMINATED;
#if VORTP_SUPPORT        	
                if (AM_IsVoIPOn() == true)
                {
                    Vortp_UnhookSndHandler();
                    {
                        VMI_STATUS eStatus = VMI_FreeHandle(snd_ctrl->vmi_handle);
                        ASSERT(eStatus == VMI_STATUS_SUCCESS);
                    }
                }
                else
#endif
                {
                    if (*DSP_SOUND_EFFECT_CTRL == DP_SND_STATE_PLAYING)
                    {
#if defined(__BT_SUPPORT__)
                        snd_ctrl->snd_state = SND_STATE_STOPPING;
                        kal_sleep_task(20); // Flush for eSCO
#endif
                        *DSP_SOUND_EFFECT_CTRL = DP_SND_STATE_STOPPED;  // Give ABORT command to the DSP
                    }
                    {
                        uint32 I = 0;
                        do
                        {
                            // DSP returns to idle state
                            if (*DSP_SOUND_EFFECT_CTRL == DP_SND_STATE_IDLE)
                            {
                                break;
                            }
                            ASSERT_REBOOT(I < 20);
                            kal_sleep_task(2);
                            I++;
                        } while(1);
                    }
                    AM_SND_PlaybackOff(true);
#if defined(AMR_CODEC) 
                    if(param->format == MEDIA_FORMAT_AMR)
                    {
                    	 amr_DeInitDecoder(snd_ctrl);
                    	 L1Audio_FreeAudioID( snd_ctrl->amr_dec_id );
                    }
#endif                    
#if defined(__BT_SUPPORT__)
                    snd_ctrl->snd_state = SND_STATE_NORMAL;
#endif
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
                    L1Audio_UnhookHisrHandler(DP_D2C_BGS_UL);
                    L1Audio_UnhookHisrHandler(DP_D2C_BGS_DL);
#else   // chip compile option
                    L1Audio_UnhookHisrHandler(SND_EFFECT_MAGIC_NO);
#endif  // chip compile option
                }
            }
            break;
        default:
            ASSERT(KAL_FALSE);
            break;
    }
    
    L1Audio_ClearFlag(snd_ctrl->aud_id);
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
    VIBR_Vibration_Activate();
#endif   
}

/*
 * Description
 * ---------
 *   The function closes the media handle.
 *
 * Syntax
 * ---------
 *   Media_Status SND_Close(Media_Handle *hdl);
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   Media_Status   MEDIA_SUCCESS => the operation is complete.
 */
Media_Status SND_Close(Media_Handle *hdl){
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   SndControl *snd_ctrl = &handle->snd_ctrl;
   kal_uint8 *ctrl_buffer = (kal_uint8 *)handle;

#ifdef _FWE_SUPPORT_   
    freeSRC(snd_ctrl->src_handle);
    snd_ctrl->src_handle = NULL;
#endif

#ifdef L1SND_TRC_ON
   kal_trace( TRACE_GROUP_SND, L1SND_ENTER_SND_CLOSE );
#endif 

   L1Audio_FreeAudioID( snd_ctrl->aud_id );
   audio_free_mem( (void **)&ctrl_buffer ); 
	
   return MEDIA_SUCCESS;
}

#ifdef SND_APPLY_MCU_GAIN
/*
 * Description
 * ---------
 *   The function sets the digital gain of background sound. The function can be 
 *   invoked after the media handle is opened and during the media handle is playing.
 *
 * Syntax
 * ---------
 *   Media_Status SND_SetLevel( Media_Handle *hdl, kal_uint8 level );
 *
 * where
 *   hdl     The media handle
 *   level   Volume level (0~100).
 *           Note 1: The default value is 100(maximum volume). 
 *           Note 2: A level value larger than 100 will change nothing and cause the 
 *                   return value to be MEDIA_FAIL.
 *           Note 3: The volume level 0 will mute the background sound at both downlink 
 *                   and uplink.
 *
 * Return Value
 * ---------
 *   Media_Status   MEDIA_SUCCESS => the operation is complete.
 *                  MEDIA_FAIL    => otherwise
 */
Media_Status SND_SetLevel( Media_Handle *hdl, kal_uint8 level )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   SndControl *snd_ctrl = &handle->snd_ctrl;
   if(level>100)
      return MEDIA_FAIL;
   
   hdl->volume_level= level;
   snd_ctrl->level = ((int16)level*level*26843)>>13;
   return(MEDIA_SUCCESS);
}

/*
 * Description
 * ---------
 *   Get the current volume level setting.
 *
 * Syntax
 * ---------
 *   kal_uint8 SND_GetLevel( Media_Handle *hdl );
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   kal_uint8   current volume level setting
 */
kal_uint8 SND_GetLevel( Media_Handle *hdl )
{
   return(hdl->volume_level);
}
#endif




//#define SND_UNIT_TEST

#if defined (SND_UNIT_TEST)   /* SND Unit Test */
/*
extern uint16 snd_test_data3[41080];
extern uint16 snd_test_data4[15739];
extern uint16 snd_test_data5[28949];
extern uint16 snd_test_data6[31475];

uint16 *snd_test_data_a[4] = {snd_test_data3, snd_test_data4, snd_test_data5, snd_test_data6};
uint32 sz_snd_test_data_a[4] = {
   41080*2, 15739*2, 28949*2, 31475*2};
uint16 select_test_data = 3;
*/


kal_char play_filename[40] = "bgsnd1.wav";
kal_uint16 *pPlayFileBuffer;


STFSAL snd_file;
Media_Handle *snd_hdl=NULL;
Snd_Param *snd_param;
#ifdef SND_APPLY_MCU_GAIN
int8 snd_level = 100;
#endif
uint8  snd_play_flag = 0;
uint8 snd_repeats = 0;
uint8  snd_output_buffer;       /* 1 for L1SP_SPEAKER1, 2 for L1SP_SPEAKER2 1, 4 for L1SP_LOUD_SPEAKER */

kal_bool snd_ul_sph_flag = KAL_TRUE;
kal_bool snd_dl_sph_flag = KAL_TRUE;
kal_int8 snd_ul_gain = 5;
kal_int8 snd_dl_gain = 5;
//kal_int8 snd_ul_gain = 50;
//kal_int8 snd_dl_gain = 50;





void snd_ut_event_handler( Media_Handle *handle, Media_Event event )
{
   switch( event )
   {      
      case MEDIA_DATA_REQUEST:
         sndProcess(handle);
         break;
      case MEDIA_END:
         SND_Stop(handle);
         SND_Close(handle);
         snd_hdl = NULL;
         snd_play_flag = 0;
         break;
      case MEDIA_REPEATED:
         break;
      default:
         ASSERT( 0 );
   }
}

bool snd_ut_snd_play( kal_wchar *play_filename )
{
	 FSAL_Status eFSALStatus;
   if( snd_play_flag == 0 )
   {
		kal_wchar filename[40];	

      snd_output_buffer = L1SP_LOUD_SPEAKER;

//FSAL Open

		pPlayFileBuffer = audio_alloc_mem(1024);
		kal_wsprintf(filename , "%w" , play_filename);
    eFSALStatus =  FSAL_Open(&snd_file , filename , FSAL_READ);
		ASSERT( FSAL_OK == eFSALStatus);
		FSAL_SetBuffer( &snd_file ,  1024, (kal_uint8 *) &pPlayFileBuffer[0]);
		
		kal_trace(TRACE_GROUP_SND, L1SND_SND_UT_SND_PLAY_FSAL_OPEN);


//SND Open		
    snd_hdl = SND_Open(snd_ut_event_handler, &snd_param);
		
		kal_trace(TRACE_GROUP_SND, L1SND_SND_UT_SND_PLAY_OPEN);


//SND assign snd_param		
      snd_param->pstFSAL = &snd_file;
      snd_param->repeats = snd_repeats; /* not necessary, default 1 */
      SND_SetOutputDevice( snd_output_buffer );



//SND Config UL/DL Mixer
      SND_ConfigULMixer(snd_hdl, snd_ul_sph_flag, snd_ul_gain);
      SND_ConfigDLMixer(snd_hdl, snd_dl_sph_flag, snd_dl_gain);

		  kal_trace(TRACE_GROUP_SND, L1SND_SND_UT_SND_PLAY_CONFIG);
		
#ifdef SND_APPLY_MCU_GAIN
      SND_SetLevel(snd_hdl, snd_level);
#endif

//SND Play
      SND_Play(snd_hdl);
		  kal_trace(TRACE_GROUP_SND, L1SND_SND_UT_SND_PLAY_PLAY);
		
      snd_play_flag = 1;
      return true;
   }
   else
   {
      SND_Stop(snd_hdl);
      SND_Close(snd_hdl);
      FSAL_Close( &snd_file );
      snd_hdl = NULL;      
      snd_play_flag = 0;
		  audio_free_mem( (void **) &pPlayFileBuffer);			
      return false;
   }
}


void snd_ut_config( kal_bool flag ){
   if(flag==KAL_TRUE){
      snd_ul_gain += 1;
      snd_dl_gain += 1;
   }
   else{
      snd_ul_gain -= 1;
      snd_dl_gain -= 1;
   }

   if(snd_ul_gain>7)
      snd_ul_gain = 7;
   else if(snd_ul_gain<0)
      snd_ul_gain = 0;

   if(snd_dl_gain>7)
      snd_dl_gain = 7;
   else if(snd_dl_gain<0)
      snd_dl_gain = 0;

   SND_ConfigULMixer(snd_hdl, snd_ul_sph_flag, snd_ul_gain);
   SND_ConfigDLMixer(snd_hdl, snd_dl_sph_flag, snd_dl_gain);
}



#ifdef SND_APPLY_MCU_GAIN
void snd_ut_set_level( bool dir ){
  if(dir==true)
    snd_level += 12;
  else
    snd_level -= 12;
  
  if(snd_level > 100)
    snd_level = 100;
  else if(snd_level < 0)
     snd_level = 0;

  if(snd_hdl != NULL)
     SND_SetLevel(snd_hdl, snd_level);
}
#endif /* ...SND_APPLY_MCU_GAIN */

#endif /* ...SND_UNIT_TEST */

#endif /* ...BGSND_ENABLE */
