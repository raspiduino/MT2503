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
 * vm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   VM recording/playback
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
#if defined(__VM_CODEC_SUPPORT__)

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "string.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "kal_trace.h"

#include "speech_def.h"
#include "common_def.h"
#include "l1audio.h"
#include "l1audio_trace.h"
#include "am.h"
#include "media.h"
#include "afe.h"
#include "l1sp_trc.h"
#include "l1audio_sph_trc.h"

#define VM_LOG_DEBUG
//#define VM_VR_RERECORD

#define VM_CTRL_UL         1
#define VM_CTRL_DL         2
#define VM_CTRL_SC_START   2
#define VM_CTRL_SD_START   6

#define VM_STATE_RECORD       0x1
#define VM_STATE_RECORD_PAUSE 0x2
#define VM_STATE_PLAY         0x4
#define VM_STATE_PLAY_PAUSE   0x8
#define VM_STATE_STOP         0x10 
#define VM_STATE_RECORD_STOP  0x20 // entering vmStop

#define VM_BASIC_VM_DATA_SIZE    37 //SyncWord(1), header(1), vm.control(1), counter(1), counter(1), 16*2
#define VM_2G_CTRL_DL_DEBUG_SIZE 44


#define VM_3G_DSP_DEBUG_SIZE     22 //DSP 15 + L1_info 2 + crc_result|DCH_On/Off 1 + s_value 1 + tpc_SIR_lta 1 + dpdch_SIR_lta 1 + TFCI_max_corr 1
#define VM_3G_MCU_DEBUG_SIZE     37 //buffer status 1 + UL 17 + DL 19
#define VM_3G_DEBUG_SIZE         ( VM_3G_DSP_DEBUG_SIZE + VM_3G_MCU_DEBUG_SIZE )
#define VM_3G324M_DSP_DEBUG_SIZE 22 //DSP 15 + L1_info 2 + crc_result|DCH_On/Off 1 + s_value 1 + tpc_SIR_lta 1 + dpdch_SIR_lta 1 + TFCI_max_corr 1
#define VM_3G324M_MCU_DEBUG_SIZE 37 //buffer status 1 + UL 17 + DL 19
#define VM_3G324M_DEBUG_SIZE     ( VM_3G324M_DSP_DEBUG_SIZE + VM_3G324M_MCU_DEBUG_SIZE )
#define VM_MAXIMUM_SAVE_SIZE     91 //VM_3G_MCU_DEBUG_SIZE + VM_BASIC_VM_DATA_SIZE

#if defined(_FWE_SUPPORT_)
   #define FOUR_PCM_SAVE_SIZE               (160+160+3+160+320+3)   //UL NB:160+160+2; DL WB:160+320+2
   #define MAX_PCM_BUF_SIZE                 (160+320+3)             //Max(UL PCM size, DL PCM size)
#else
   #define FOUR_PCM_SAVE_SIZE               (160+160+3+160+160+3)   //UL NB:160+160+2; DL WB:160+160+2
   #define MAX_PCM_BUF_SIZE                 (160+160+3)             //Max(UL PCM size, DL PCM size, REFMIC PCM size)
   
   #if defined(__DUAL_MIC_SUPPORT__)
      #define VM_REFMICPCM_DEBUG_SIZE       (164)                   //2 + 160 + 2 --> header , pcm , agc
      #define FIVE_PCM_SAVE_SIZE            ((160+160+3+160+160+3) + VM_REFMICPCM_DEBUG_SIZE)
   #endif
#endif


#define VM_BUFFER_SIZE           513

#ifndef UPPER_BOUND
#define UPPER_BOUND(in,up) ((in) > (up) ? (up) : (in))
#endif

#if defined(__UMTS_TDD128_MODE__)
#define VM_MAGIC_HEADER 0xAA11
#elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define VM_MAGIC_HEADER 0xAA88
#else
#define VM_MAGIC_HEADER 0xAA22
#endif

/* ------------------------------------------------------------------------------ */
static struct{
   mediaControl   *ctrl;   
   uint16          type;
   uint16         control;    /* control word for FR/HR/EFR                         */
                              /* bit  0-1:   Channel usage(bit0:UL,bit1:DL)         */
                              /* bit  2-5:   UL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit  6-9:   DL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit  10:    DP_TX_TCH_S0_0 data bit 1              */
                              /* bit 11-15:  DP_RX_TCH_S0_0 data bit 1-5            */

                              /* control word for AMR                               */
                              /* bit  0-1:   Channel usage(bit0:UL,bit1:DL)         */
                              /* bit  2-5:   UL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit  6-9:   DL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit 10-11:  DP_TX_TCH_S0_0 data bit 0-1            */
                              /* bit 12-15:  DP_RX_TCH_S0_0 data bit 1-3,5          */
   uint16         control_1;
   uint16         control_2;
   uint32         rb_data_len;  /* actual data size (in word) in ring buffer */
   int16          *vmBuf;    /* point to buffer for VM                              */   
   uint16         *pcmBuf;   /* point to buffer for 1st set UL-DL PCM data         */   
   uint16         debug_info; /* 0  : vm (speech codec data) only                   */
                              /* b1 : record 1st set of UL-DL PCM buffer for SPE    */
                              /* b2 : record 2nd set of UL-DL PCM buffer for SPE    */ 
   uint8          state;
   uint8          vm_lost; 
   uint8          vm_lost_count;
   uint8          pcm_lost_count;                                                                  
   uint8          sc_mode;
   uint8          sd_mode;
	 bool           isVocOn;  // please take care aboute the flag, it controls the entries of VmRecord
	 bool           isMediaVmRecord;  // please take care aboute the flag, it controls the entries of VmRecord
   uint32         pcm_save_size;
} vm;

#if defined( VM_LOG_DEBUG )
uint8   vm_counter;
#endif

#define VM_PCM_1ST_SET_RECORD_FLAG  0x1 
#define VM_PCM_2ND_SET_RECORD_FLAG  0x2
#define VM_VM_RECORD_FLAG           0x4
#define VM_PCM_REFMIC_RECORD_FLAG   0x8

#define TCH_VM_INT_FLAG             0x1 
#define TCH_PCM_INT_FLAG            0x2 

/* ------------------------------------------------------------------------------ */
#define  PUT_RECORD_DATA(val)                                  \
   {                                                           \
      if( vm.ctrl->read > vm.ctrl->write ) {                   \
         if( vm.ctrl->read - vm.ctrl->write > 1 )              \
            vm.ctrl->rb_base[vm.ctrl->write++] = (val);        \
      }                                                        \
      else if( vm.ctrl->read == 0 ) {                          \
         if( vm.ctrl->rb_size - vm.ctrl->write > 1 )           \
            vm.ctrl->rb_base[vm.ctrl->write++] = (val);        \
      }                                                        \
      else {                                                   \
         vm.ctrl->rb_base[vm.ctrl->write++] = (val);           \
         if( vm.ctrl->write == vm.ctrl->rb_size )              \
            vm.ctrl->write = 0;                                \
      }                                                        \
   }

#define GET_VM_LENGTH(vm_control, control)  AM_GetSpeechPatternLength((control >> VM_CTRL_SC_START) & 0x0F) \
                                + ((vm_control & VM_CTRL_DL)?(AM_GetSpeechPatternLength((control >> VM_CTRL_SD_START) & 0x0F)):0) \
                                + 6
                                //VM_MAGIC_HEADER, format, FN, FN_counter, vm.control
#define _EXTRA_LOG_FOR_BIT_TRUE_
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
extern kal_bool g_bNeedExtraLog;
#endif

#pragma arm section code="SECONDARY_ROCODE"

#if defined( VM_LOG_DEBUG )
static uint16 vmRecGetDebugSize(uint16 sc_mode, uint16 sd_mode, uint16 debug_info,uint32 mode)
{
   uint16 count = 0;
   
   if( mode == 1 && sd_mode > 2 && sd_mode < 11 && (vm.control & VM_CTRL_DL) ){
      count += VM_2G_CTRL_DL_DEBUG_SIZE;
   }
   if( mode >= 1 ){//speech mode
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
      if( L1SP_GetState() == L1SP_STATE_3G_SPEECH_ON )
         count += VM_3G_DEBUG_SIZE;
      else if( L1SP_GetState() == L1SP_STATE_3G324M_SPEECH_ON )
         count += VM_3G324M_DEBUG_SIZE;
#endif
   }
   return count;
}
#endif

//use this function instead of Media_WriteDataDone to avoid media.waiting false usage
static void vmWriteDataDone( uint32 len )
{
   vm.ctrl->write += len;
   if( vm.ctrl->write >= vm.ctrl->rb_size )
      vm.ctrl->write = 0;
}

static void vmWriteVmToMB(uint32 vm_len, uint16 *p_vm_buf)
{   // A frame of VM must be written to MB
    uint16 *p_buf = NULL;
    uint32 buf_len = 0;
    uint32 I;
    
    Media_GetWriteBuffer(&p_buf, &buf_len);
    buf_len = UPPER_BOUND(buf_len, vm_len);
    
    for (I = buf_len; I > 0; I--)
    {
        *p_buf++ = *p_vm_buf++;
    }
    
    vmWriteDataDone(buf_len);
    
    if (vm_len > buf_len)
    {
        vm_len -= buf_len;
        Media_GetWriteBuffer(&p_buf, &buf_len);
        for (I = vm_len; I > 0; I--)
        {
            *p_buf++ = *p_vm_buf++;
        }
        vmWriteDataDone(vm_len);
    }
    
    return;
}

static void vocWriteVocToCatcher( uint32 vmLen, uint16 *vmBuf )
{
    uint32 len  = vmLen << 1;
    uint16 *buf = vmBuf;
    
    kal_dev_trace(TRACE_GROUP_VOC, VOC_LENGTH, len);
    
    while (len > 1000)
    {
        tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)buf, 1000);
        buf += 500;
        len -= 1000;
    }
    
    tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)buf, len);
    
    return;
}

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
typedef struct{
	uint16 enc_mode;
	uint16 dec_mode;
	uint16 enc_hdr;
	uint16 dec_hdr;
	volatile uint16 *enc_hb_addr;
	volatile uint16 *dec_hb_addr;
	volatile uint16 *dbgInfo_addr;
	volatile uint16 *enh_dbgInfo_addr;
} Sal_VM_Frame;

Sal_VM_Frame vmfrm_t;

#define SAL_VM_DBGINFO_LEN 56
#define SAL_VM_ENH_DBGINFO_LEN 69
#define SAL_VM_DRV_DBGINFO_LEN 20

void SALI_VM_GetFrame(uint8 rat, Sal_VM_Frame *vmfrm)
{   // rat == 0 -> 2g
	vmfrm->enc_mode     = *DSP_SPH_Encoder_Used_Mode;
	vmfrm->dec_mode     = *DSP_SPH_Decoder_Used_Mode;
	vmfrm->dbgInfo_addr = DSP_SPH_VM_DBG_INFO;
    
	if (rat == 0)
    {   // 2g
        vmfrm->enc_hdr     = *DSP_SPH_2G_SE_DATA_HDR;
        vmfrm->enc_hb_addr = DSP_SPH_2G_SE_DATA_HB;
        vmfrm->dec_hdr     = *DSP_SPH_2G_SD_DATA_HDR;
        vmfrm->dec_hb_addr = DSP_SPH_2G_SD_DATA_HB;
	}
	else if(rat == 1)
    {   // 3g
	    vmfrm->enc_hdr     = *DSP_SPH_3G_SE_DATA_HDR;
	    vmfrm->enc_hb_addr = DSP_SPH_3G_SE_DATA_HB;
	    vmfrm->dec_hdr     = *DSP_SPH_3G_SD_DATA_HDR;
	    vmfrm->dec_hb_addr = DSP_SPH_3G_SD_DATA_HB;
	}
    
	vmfrm->enh_dbgInfo_addr = 0;    //DSP_DM_ADDR(6, *DSP_SPH_ENH_DEBUG_ADDR);
	
	return;
}


void vmRecordHisr(void)
{
    volatile uint16   *addr;
    uint16   I, sc_mode, sd_mode, sc_len, sd_len;
    uint16   *vmBuf;
    uint32   vmLen = 0;
    
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
    if (   L1SP_GetState() == L1SP_STATE_3G_SPEECH_ON
        || L1SP_GetState() == L1SP_STATE_3G324M_SPEECH_ON)
    {
        return;
    }
#endif
    
    if (vm.state != VM_STATE_RECORD)
    {
        return;
    }
    
#if defined(__MA_L1__)
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
    
    vmBuf = (uint16 *)vm.vmBuf;
#if defined(VM_LOG_DEBUG)
    if (vmBuf[0] == VM_MAGIC_HEADER)
    {   // Already buffer VM
        I =   (uint16)(vmBuf[1] >> 3)
            + AM_GetSpeechPatternLength((vmBuf[5]>> 1) & 0x3F) 
            + ((vm.control_2 & 1)?(AM_GetSpeechPatternLength((vmBuf[6] >> 1) & 0x3F)):0) 
            + 7;
        
        if (vm.isMediaVmRecord)
        {
            if (mediaGetFreeSpace() < I)
            {
                return;
            }
            else
            {
                vmWriteVmToMB((uint32)I, vmBuf);
                vm.vm_lost_count = 0;
                vm.vmBuf[0] = 0;
                vm.vmBuf[1] = 0;
                vm.vmBuf[2] = 0;
            }
        }
        else if(vm.isVocOn)
        {
            vocWriteVocToCatcher((uint32)I, vmBuf);
            vm.vm_lost_count = 0;
            vm.vmBuf[0] = 0;
            vm.vmBuf[1] = 0;
            vm.vmBuf[2] = 0;
        }
    }
#endif
    
	SALI_VM_GetFrame(0, &vmfrm_t);
    
    sc_mode = vmfrm_t.enc_mode;
    sd_mode = vmfrm_t.dec_mode;
/*  Turn off by WH Hsu
    if (sd_mode > 2)
    {
        sc_mode = (*DSP_SC_TCH_MODE >> 8) & 0x0F;
        sd_mode = (*DSP_SD_TCH_MODE >> 8) & 0x0F;
    }
*/

#if defined( VM_LOG_DEBUG )
    // For catcher log codec information
    if (   vm.sc_mode != sc_mode
        || vm.sd_mode != sd_mode)
    {
        L1Audio_Msg_SPEECH_CODEC(L1SP_Speech_Codec_Mode(sc_mode), L1SP_Speech_Codec_Mode(sd_mode));
        vm.sc_mode = sc_mode;
        vm.sd_mode = sd_mode;
    }
#endif
   
   ASSERT_REBOOT( (sc_len = AM_GetSpeechPatternLength(sc_mode)) > 0 );
   ASSERT_REBOOT( (sd_len = AM_GetSpeechPatternLength(sd_mode)) > 0 );

   	vm.control_1 = (sc_mode << 1) | (vm.control_1 & 1);
	vm.control_2 = (sd_mode << 1) | (vm.control_2 & 1);

	if(sc_mode > 2){
	I = vmfrm_t.enc_hdr & 3;//bit0, bit1
	vm.control_1 = vm.control_1 | (I << 7); //Tx
	}
	else{
	I = (vmfrm_t.enc_hdr & 2);//sp_flag
	vm.control_1 = vm.control_1 | (I << 10); 
	//add 3G_Mode here, where is dsp's 3g mode indicator
	}

	if(sd_mode > 2){
	I = (vmfrm_t.dec_hdr & 14) >> 1;//bit1, bit2, bit3
	vm.control_2 = vm.control_2 | (I << 7);	// Rx
	}
	else{
	I = (vmfrm_t.dec_hdr & 0x3E);
	vm.control_2 = vm.control_2 | (I << 10);
	}


   {
      extern uint32 L1I_GetTimeStamp( void );
      uint32 J;

      *vmBuf++ = VM_MAGIC_HEADER;
      J = L1SP_GetState();
      I = (uint16)( ( (SAL_VM_DBGINFO_LEN + SAL_VM_ENH_DBGINFO_LEN + SAL_VM_DRV_DBGINFO_LEN) << 3 ) | J);				  
      *vmBuf++ = I;
      *vmBuf++ = VM_VM_RECORD_FLAG;
      J = L1I_GetTimeStamp();
      I = (uint16)(J & 0xFFFF);
      *vmBuf++ = I;
      I = (uint16)((J >> 16) + ((uint32)vm_counter << 8));
      *vmBuf++ = I;
      vm_counter++;
   }

   	*vmBuf++ = vm.control_1;
	*vmBuf++ = vm.control_2;

   
 	if( vm.control_1 & 1 ) {
		addr = vmfrm_t.enc_hb_addr;
		vmLen += sc_len;
		for( I = 0; I < sc_len; I++ )
			*vmBuf++ = *addr++;
	}

	if( vm.control_2 & 1 ) {
		addr = vmfrm_t.dec_hb_addr;
		vmLen += sc_len;
		for( I = 0; I < sd_len; I++ )
			*vmBuf++ = *addr++;

	 addr = vmfrm_t.dbgInfo_addr;  
	 for( I = 0; I < SAL_VM_DBGINFO_LEN; I++ )
				*vmBuf++ = *addr++;

	 //addr = vmfrm_t.enh_dbgInfo_addr;  
	 for( I = 0; I < SAL_VM_ENH_DBGINFO_LEN; I++ )
				*vmBuf++ = 0;

	 for(I = 0; I < SAL_VM_DRV_DBGINFO_LEN; I++){
			    *vmBuf++ = 0;
		}

	}

}

#else   // chip compile option
void vmRecordHisr(void)
{
   volatile uint16   *addr;
   uint16   I, sc_mode, sd_mode, sc_len, sd_len;
   uint16   *vmBuf;
   uint32   vmLen = 0;

#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
   if( L1SP_GetState() == L1SP_STATE_3G_SPEECH_ON || L1SP_GetState() == L1SP_STATE_3G324M_SPEECH_ON )
      return;
#endif

   if( vm.state != VM_STATE_RECORD )
      return;

#if defined(__MA_L1__)
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

   vmBuf = (uint16 *)vm.vmBuf;
#if defined( VM_LOG_DEBUG )
   if( vmBuf[0] == VM_MAGIC_HEADER ){  //already buffer VM
      I = (uint16)( vmBuf[1] >> 3 ) + GET_VM_LENGTH(vm.control, vmBuf[5]);

      if(vm.isMediaVmRecord)
      {
         if( mediaGetFreeSpace() < I )
         {
            return;
         }
         else
         {
            vmWriteVmToMB( (uint32)I, vmBuf );
            vm.vm_lost_count = 0;
            vm.vmBuf[0] = 0;
            vm.vmBuf[1] = 0;
            vm.vmBuf[2] = 0;
         }
      }
      else if(vm.isVocOn)         
      {
         vocWriteVocToCatcher( (uint32)I, vmBuf );
         vm.vm_lost_count = 0;
         vm.vmBuf[0] = 0;
         vm.vmBuf[1] = 0;
         vm.vmBuf[2] = 0;
      }
   }
#endif

   I        = *DP_SC_MODE;
   sc_mode  = (I >> 8) & 0x0F;
   sd_mode  = I & 0x0F;
/*   if( sd_mode > 2 ) {
      sc_mode = (*DSP_SC_TCH_MODE >> 8) & 0x0F;
      sd_mode = (*DSP_SD_TCH_MODE >> 8) & 0x0F;
   } Turn off by WH Hsu */
   if( sc_mode>2 && sc_mode<11 ){
   	I = *DSP_RX_TCH_S(0,17) >> 8;
	sd_mode = I & 0x1F;
   	I = *DSP_TX_TCH_S(0,17) >> 8;
	sc_mode = I & 0x1F;
   }
#if defined( VM_LOG_DEBUG )
   /*for catcher log codec information*/
   if( vm.sc_mode != sc_mode || vm.sd_mode != sd_mode ){
      L1Audio_Msg_SPEECH_CODEC( L1SP_Speech_Codec_Mode(sc_mode), L1SP_Speech_Codec_Mode(sd_mode) );
      vm.sc_mode = sc_mode;
      vm.sd_mode = sc_mode;
   }
#endif
   
   ASSERT_REBOOT( (sc_len = AM_GetSpeechPatternLength(sc_mode)) > 0 );
   ASSERT_REBOOT( (sd_len = AM_GetSpeechPatternLength(sd_mode)) > 0 );
   if( sc_mode <= 2 ) {
      vm.control =((*DSP_RX_TCH_S(0,0) & 0x3E) << 10) |
                  ((*DSP_TX_TCH_S(0,0) & 2)<< 9 ) |
                  (sd_mode << VM_CTRL_SD_START) |
                  (sc_mode << VM_CTRL_SC_START) |
                  (vm.control & 3);
   }
   else {
      I = *DSP_RX_TCH_S(0,0) >> 1;
      I = ((I & 0x10)>>1) | (I & 0x07);
      vm.control =(I << 12) |
                  ((*DSP_TX_TCH_S(0,0) & 3)<< 10 ) |
                  (sd_mode << VM_CTRL_SD_START) |
                  (sc_mode << VM_CTRL_SC_START) |
                  (vm.control & 3);
   }

#if defined( VM_LOG_DEBUG )
   {
      extern uint32 L1I_GetTimeStamp( void );
      uint32 J;

      *vmBuf++ = VM_MAGIC_HEADER;
      J = L1SP_GetState();
      I = (uint16)( ( vmRecGetDebugSize(sc_mode, sd_mode, vm.debug_info, J) << 3 ) | J);             
      *vmBuf++ = I;
      *vmBuf++ = VM_VM_RECORD_FLAG;
      J = L1I_GetTimeStamp();
      I = (uint16)(J & 0xFFFF);
      *vmBuf++ = I;
      I = (uint16)((J >> 16) + ((uint32)vm_counter << 8));
      *vmBuf++ = I;
      vm_counter++;
   }
#endif
#if !defined (VM_VR_RERECORD)
   if( vm.ctrl->format != MEDIA_FORMAT_VRD ){
      *vmBuf++ = vm.control;
      vmLen++;
   }
#endif
   if( vm.control & VM_CTRL_UL ) {
      addr = DSP_TX_TCH_S( 0, 1 );
      vmLen += sc_len;
      for( I = 0; I < sc_len; I++ )
         *vmBuf++ = *addr++;
   }

   if( vm.control & VM_CTRL_DL ) {
      addr = DSP_RX_TCH_S( 0, 1 );
      vmLen += sc_len;
      for( I = 0; I < sd_len; I++ )
         *vmBuf++ = *addr++;

#if defined( VM_LOG_DEBUG )
      if( sd_mode>2 && sd_mode<11 ){
         addr = DSP_RX_TCH_S( 0, 17);
         *vmBuf++ = *addr++;	// Rx
         addr = DSP_TX_TCH_S( 0, 17);
         *vmBuf++ = *addr++;	// Tx
#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01) || defined(MT6255) || defined(MT6250) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
         addr = (volatile uint16 *)DP_SP_VM_CTRL_base(0x24);
#else
         addr = (volatile uint16 *)DP_SP_VM_CTRL_base(0x1b7);
#endif
         for( I = 0; I < 42 ; I++ )
            *vmBuf++ = *addr++;
      }
#endif
   }
}
#endif  // chip compile option

#pragma arm section

#define  GET_PLAYBACK_DATA(val)                            \
      if( vm.ctrl->read != vm.ctrl->write ) {              \
         (val) = vm.ctrl->rb_base[vm.ctrl->read++];        \
         vm.rb_data_len -= 1;                              \
         if( vm.ctrl->read >= vm.ctrl->rb_size )           \
            vm.ctrl->read = 0;                             \
      }                                                    \
      else {                                               \
         return;                                           \
      }

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
//  MT6260 does not support VM playback
#else   // chip compile option
static void vm_playback( void )
{
   volatile uint16 *addr;
   uint16   I, control, sc_mode, sd_mode, data_len, data;
#if defined( VM_LOG_DEBUG )
   uint16   dummy_tmp;
#endif

   while( 1 ) {
      if( vm.ctrl->format != MEDIA_FORMAT_VRD && vm.ctrl->format != MEDIA_FORMAT_VRSI) {
#if defined( VM_LOG_DEBUG )
         do {
            GET_PLAYBACK_DATA( control );
         } while( control != VM_MAGIC_HEADER );
         GET_PLAYBACK_DATA( control );       /* ignore frame number(0~15)                 */
         GET_PLAYBACK_DATA( control );       /* ignore frame number(16~24) and time stamp */
#endif
         GET_PLAYBACK_DATA( control );
         if( (control&3) == 0 )
            continue;
      }
      else
         control = 0x401;

      sc_mode = (control >> VM_CTRL_SC_START) & 0x0F;
      sd_mode = (control >> VM_CTRL_SD_START) & 0x0F;
      if( sc_mode != sd_mode && (sc_mode <= 2 || sd_mode <= 2) )
         continue;
      break;
   }

   if( control & VM_CTRL_UL ) {
      addr = DSP_SD2_VM_0;
      if( sc_mode <= 2 )
         *addr++ = (control >> 9) & 2;       /* Write real AMR UL data */
      else
         *addr++ = (control >> 10) & 3;      /* Write real AMR UL data */
      data_len = AM_GetSpeechPatternLength(sc_mode);
      for( I = 0; I < data_len; I++ )
         GET_PLAYBACK_DATA( *addr++ );
   }
   else {                                             /* No UL data */
      sc_mode = sd_mode;
      AM_FillSilencePattern( DSP_SD2_VM_0, 2, sc_mode );
   }
   if( sc_mode > 2 )
      *DSP_SD2_VM_17 = sc_mode;

   if( (control & VM_CTRL_DL) == 0 ) {                /* No DL data */
      sd_mode = sc_mode;
      AM_FillSilencePattern( DSP_SD1_VM_0, 0, sd_mode );
   }
   else if( control & 0x8000 ) {                      /* bad speech */
      AM_FillSilencePattern( DSP_SD1_VM_0, 0, sd_mode );
      data_len = AM_GetSpeechPatternLength(sd_mode);
      for( I = 0; I < data_len; I++ )
         GET_PLAYBACK_DATA( data );
   }
   else {
      addr = DSP_SD1_VM_0;
      if( sd_mode <= 2 )
         *addr++ = (control >> 10) & 0x3E;
      else {
         I = (control >> 12);
         *addr++ = ((I & 8) << 2) + ((I & 7) << 1);
      }
      data_len = AM_GetSpeechPatternLength(sd_mode);
      for( I = 0; I < data_len; I++ )
         GET_PLAYBACK_DATA( *addr++ );
   }
#if defined( VM_LOG_DEBUG )
   if( sd_mode>2 && sd_mode<11 && (control & VM_CTRL_DL) ){
    	GET_PLAYBACK_DATA( dummy_tmp );
    	GET_PLAYBACK_DATA( dummy_tmp );
      for( I = 0; I <42; I++ )
         GET_PLAYBACK_DATA( dummy_tmp );
   }
#endif
   if( sd_mode > 2 )
      *DSP_SD1_VM_17 = sd_mode;

   if( (vm.control==0) || ((vm.control & 0x3FC) != (control & 0x3FC)) ) {
      vm.control = control;
      /* Set Digital Gain for Voice Memo */
      AFE_SetDigitalGain( L1SP_VOICE, 100 );
      AM_VMPlaybackOn( control, vm.ctrl->param.vm );
   }
}

/* ------------------------------------------------------------------------------ */
void vmPlaybackHisr( void )
{
   int32 count;

   if (vm.state != VM_STATE_PLAY)
      return;

   vm_playback();
   count = (int32)vm.ctrl->write - (int32)vm.ctrl->read;
   if( count < 0 )
      count += vm.ctrl->rb_size;
   if( vm.ctrl->eof && (count < 17 || (vm.rb_data_len == 0
      && vm.ctrl->format == MEDIA_FORMAT_VRD))) {
      AM_VMPlaybackOff( vm.ctrl->param.vm );
      mediaSetEvent( MEDIA_END );
   }
}
/* ------------------------------------------------------------------------------ */
#endif  // chip compile option

#if defined(__DUAL_MIC_SUPPORT__)
// Setting for recording PCM data from reference mic
#if defined(MT6256_S01)
#define REFMIC_PAGE_NUM 5
#else
#error The new chip should define DM page number
#endif

#endif

// Setting for recording 2nd set UL-DL PCM data 

#if  defined(MT6235) || defined(MT6235B)
#define PCM1_UL_PAGE_NUM   2       
#define PCM1_UL_BUF_ADDR   0x1860  
#define PCM2_UL_PAGE_NUM   2       
#define PCM2_UL_BUF_ADDR   0x17C0  
#define PCM1_DL_PAGE_NUM   2       
#define PCM1_DL_BUF_ADDR   0x1680  
#define PCM2_DL_PAGE_NUM   2       
#define PCM2_DL_BUF_ADDR   0x1720  

#elif defined(MT6255)
#define PCM1_UL_PAGE_NUM   5
#define PCM1_UL_BUF_ADDR   0x1CC1
#define PCM2_UL_PAGE_NUM   5
#define PCM2_UL_BUF_ADDR   0x1B81
#define PCM1_DL_PAGE_NUM   5
#define PCM1_DL_BUF_ADDR   0x1901
#define PCM2_DL_PAGE_NUM   5
#define PCM2_DL_BUF_ADDR   0x1A41

#elif defined(MT6256_S01)
#define PCM1_UL_PAGE_NUM   5
#define PCM1_UL_BUF_ADDR   0x21C1
#define PCM2_UL_PAGE_NUM   5
#define PCM2_UL_BUF_ADDR   0x2081
#define PCM1_DL_PAGE_NUM   5
#define PCM1_DL_BUF_ADDR   0x1E01
#define PCM2_DL_PAGE_NUM   5
#define PCM2_DL_BUF_ADDR   0x1F41

#define PCM3_UL_PAGE_NUM   5
#define PCM3_UL_BUF_ADDR   0x2B36

#elif defined(MT6253) 
#define PCM1_UL_PAGE_NUM   1
#define PCM1_UL_BUF_ADDR   0x1860
#define PCM2_UL_PAGE_NUM   1
#define PCM2_UL_BUF_ADDR   0x17C0
#define PCM1_DL_PAGE_NUM   1
#define PCM1_DL_BUF_ADDR   0x1680
#define PCM2_DL_PAGE_NUM   1
#define PCM2_DL_BUF_ADDR   0x1720

#elif defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
#define PCM1_UL_PAGE_NUM   2
#define PCM1_UL_BUF_ADDR   0x0A41
#define PCM2_UL_PAGE_NUM   2
#define PCM2_UL_BUF_ADDR   0x0AE1
#define PCM1_DL_PAGE_NUM   2
#define PCM1_DL_BUF_ADDR   0x0901
#define PCM2_DL_PAGE_NUM   2
#define PCM2_DL_BUF_ADDR   0x09A1

#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)
#define PCM1_UL_PAGE_NUM   2
#define PCM1_UL_BUF_ADDR   0x0DC1
#define PCM2_UL_PAGE_NUM   2
#define PCM2_UL_BUF_ADDR   0x0C81
#define PCM1_DL_PAGE_NUM   2
#define PCM1_DL_BUF_ADDR   0x0A01
#define PCM2_DL_PAGE_NUM   2
#define PCM2_DL_BUF_ADDR   0x0B41

#elif defined(MT6251)
#define PCM1_UL_PAGE_NUM   2
#define PCM1_UL_BUF_ADDR   0x06E1
#define PCM2_UL_PAGE_NUM   2
#define PCM2_UL_BUF_ADDR   0x0641
#define PCM1_DL_PAGE_NUM   2
#define PCM1_DL_BUF_ADDR   0x0501
#define PCM2_DL_PAGE_NUM   2
#define PCM2_DL_BUF_ADDR   0x05A1

#elif defined(MT6250)
#define PCM1_UL_PAGE_NUM   5
#define PCM1_UL_BUF_ADDR   0x1D61
#define PCM2_UL_PAGE_NUM   5
#define PCM2_UL_BUF_ADDR   0x1CC1
#define PCM1_DL_PAGE_NUM   5
#define PCM1_DL_BUF_ADDR   0x36b9
#define PCM2_DL_PAGE_NUM   5
#define PCM2_DL_BUF_ADDR   0x1B81

#elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// NEED TO REVIEW!!!
#define PCM1_UL_PAGE_NUM   7
#define PCM1_UL_BUF_ADDR   (*DSP_EPL_UL_ADDR1)
#define PCM2_UL_PAGE_NUM   7
#define PCM2_UL_BUF_ADDR   (*DSP_EPL_UL_ADDR2)
#define PCM1_DL_PAGE_NUM   7
#define PCM1_DL_BUF_ADDR   (*DSP_EPL_DL_ADDR1)
#define PCM2_DL_PAGE_NUM   7
#define PCM2_DL_BUF_ADDR   (*DSP_EPL_DL_ADDR2)

#else 
#error The new chip should define EPL address
#endif 

#define NB_FRAME_BUF_SIZE (160)
#define WB_FRAME_BUF_SIZE (320)

extern int32 mediaGetFreeSpace( void );

#pragma arm section code="SECONDARY_ROCODE"

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

#define VM_PCM_BAND_FLAG_UL_PRE		0x0010
#define VM_PCM_BAND_FLAG_UL_POS		0x0020
#define VM_PCM_BAND_FLAG_DL_PRE		0x0040
#define VM_PCM_BAND_FLAG_DL_POS		0x0080
#define VM_PCM_BAND_FLAG_UL2_POS	0x0100

#if defined(__DUAL_MIC_SUPPORT__)
static void vmRefMic_AGC_PcmRecord( bool isToVoc, volatile uint16 *addr, uint16 len )
{
    uint16 *buf = vm.pcmBuf;
    uint16 logsize = len + 2 + 2;
    
    *buf++ = (vm.vm_lost_count << 8) + vm.pcm_lost_count;
    *buf++ = vm_counter;
    IDMA_ReadFromDSP(buf, addr, len);
    buf += len;
    *buf++ = *DSP_SPH_AGC_SW_GAIN1;
    *buf   = *DSP_SPH_AGC_SW_GAIN2;

    if (isToVoc)
    {
		vocWriteVocToCatcher(logsize, vm.pcmBuf);
    }
    else
    {   // Normal VM process
        vmWriteVmToMB(logsize, vm.pcmBuf);
	}
	
	return;
}
#endif

static void vm4WayPcmRecord(volatile uint16 *ul_addr, uint16 ul_len, volatile uint16 *dl_addr, uint16 dl_len)
{
    uint16 *buf = vm.pcmBuf;
    uint16 logsize = ul_len + dl_len + 2;
    
    // Header for record 1st set of UL-DL PCM data
    *buf++ = (vm.vm_lost_count << 8) + vm.pcm_lost_count;
    *buf++ = vm_counter;
    
    IDMA_ReadFromDSP(buf         , ul_addr, ul_len);    // Uplink
    IDMA_ReadFromDSP(buf + ul_len, dl_addr, dl_len);    // Downlink
    
    vmWriteVmToMB(logsize, vm.pcmBuf);
    
    return;
}

static void voc4WayPcmRecord(volatile uint16* ul_addr, uint16 ul_len, volatile uint16* dl_addr, uint16 dl_len)
{
    uint16 *buf = vm.pcmBuf;
    uint16 logsize = ul_len + dl_len + 2;
    
    // Header for record 1st set of UL-DL PCM data 
    *buf++ = (vm.vm_lost_count << 8) + vm.pcm_lost_count;
    *buf++ = vm_counter;

	// Make it interleave
    IDMA_ReadFromDSP(buf         , ul_addr, ul_len);    // Uplink
    IDMA_ReadFromDSP(buf + ul_len, dl_addr, dl_len);    // Downlink
    
    vocWriteVocToCatcher(logsize, vm.pcmBuf);
    
    return;
}

typedef struct{
	uint16 ul_pre_len;
	uint16 ul_pos_len;
	uint16 dl_pre_len;
	uint16 dl_pos_len;
	uint16 ul2_pos_len;
	volatile uint16 *ul_pre_buf;
	volatile uint16 *ul_pos_buf;
	volatile uint16 *dl_pre_buf;
	volatile uint16 *dl_pos_buf;
	volatile uint16 *ul2_pos_buf;
} Sal_EPL_Frame;

Sal_EPL_Frame eplfrm_t;

void SALI_EPL_GetFrame(Sal_EPL_Frame *eplfrm)
{
	eplfrm->ul_pre_buf  = DSP_DM_ADDR(5, *DSP_SPH_EPL_UL_PRE_BUF);
	eplfrm->ul_pos_buf  = DSP_DM_ADDR(5, *DSP_SPH_EPL_UL_POS_BUF);
	eplfrm->dl_pre_buf  = DSP_DM_ADDR(5, *DSP_SPH_EPL_DL_PRE_BUF);
	eplfrm->dl_pos_buf  = DSP_DM_ADDR(5, *DSP_SPH_EPL_DL_POS_BUF);
	eplfrm->ul2_pos_buf = DSP_DM_ADDR(5, *DSP_SPH_SE2_BUF_PTR);
    eplfrm->ul_pre_len  = *DSP_SPH_EPL_BND & 0x0001 ? 320 : 160;
    eplfrm->ul_pos_len  = *DSP_SPH_EPL_BND & 0x0002 ? 320 : 160;
    eplfrm->dl_pre_len  = *DSP_SPH_EPL_BND & 0x0004 ? 320 : 160;
    eplfrm->dl_pos_len  = *DSP_SPH_EPL_BND & 0x0008 ? 320 : 160;
    eplfrm->ul2_pos_len = *DSP_SPH_EPL_BND & 0x0010 ? 320 : 160;
	return;
}

#define AA88_GET_VM_LENGTH(vmctrl_1, vmctrl_2) AM_GetSpeechPatternLength((vmctrl_1>> 1) & 0x3F) \
+ ((vmctrl_2 & 1)?(AM_GetSpeechPatternLength((vmctrl_2 >> 1) & 0x3F)):0) + 7

void vmTchPcmRecordHisr(void *param)
{
    uint32 I, tmp = 0;
    uint16 dummy;
    uint16 *buf, *mBuf;
    uint16 pcmsize;
    
    if (vm.state != VM_STATE_RECORD)
    {
        return;
    }
    
	SALI_EPL_GetFrame(&eplfrm_t);
    
    pcmsize = 0;
    if (vm.debug_info & VM_PCM_1ST_SET_RECORD_FLAG)
    {
        pcmsize += eplfrm_t.ul_pre_len + eplfrm_t.dl_pre_len;
    }
    if (vm.debug_info & VM_PCM_2ND_SET_RECORD_FLAG)
    {
        pcmsize += eplfrm_t.ul_pos_len + eplfrm_t.dl_pos_len;
    }
    if (vm.debug_info & VM_PCM_REFMIC_RECORD_FLAG)
    {
        pcmsize += eplfrm_t.ul2_pos_len;
    }
    
    buf = (uint16 *)vm.vmBuf;
    if (buf[0] == VM_MAGIC_HEADER)
    {   // Already buffer VM
        tmp = (buf[1] >> 3) + pcmsize;  // Debug size
        I = tmp + AA88_GET_VM_LENGTH(vm.control_1, vm.control_2);
    }
    else
    {
        tmp = pcmsize;          // Debug size(only PCM)
        I = pcmsize + 3 + 2;    // Plus sync word and format and 2 timestamp
    }
    
    buf[2] &= 0xfe0f;   // Clean the epl band flag
    if (eplfrm_t.ul_pre_len == 320)
    {
        buf[2] |= VM_PCM_BAND_FLAG_UL_PRE;
    }
    if (eplfrm_t.ul_pos_len == 320)
    {
        buf[2] |= VM_PCM_BAND_FLAG_UL_POS;
    }
    if (eplfrm_t.dl_pre_len == 320)
    {
        buf[2] |= VM_PCM_BAND_FLAG_DL_PRE;
    }
    if (eplfrm_t.dl_pos_len == 320)
    {
        buf[2] |= VM_PCM_BAND_FLAG_DL_POS;
    }
    if (eplfrm_t.ul2_pos_len == 320)
    {
        buf[2] |= VM_PCM_BAND_FLAG_UL2_POS;
    }
    
    if (vm.isMediaVmRecord)
    {
        if (mediaGetFreeSpace() < I)
        {
            vm.pcm_lost_count++;
            return;
        }
        else
        {
            buf[0] = VM_MAGIC_HEADER;
            buf[1] = (uint16)(tmp << 3) | ( L1SP_GetState());
            buf[2] |= ( vm.debug_info & (VM_PCM_REFMIC_RECORD_FLAG + VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG) );
        }
        
        I -= pcmsize;
        vmWriteVmToMB(I, buf);
    }
    else if(vm.isVocOn)
    {
        buf[0] = VM_MAGIC_HEADER;
        buf[1] = (uint16)(tmp << 3) | ( L1SP_GetState()) ;
        buf[2] |= ( vm.debug_info & (VM_PCM_REFMIC_RECORD_FLAG + VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG) );
        I -= pcmsize;
        vocWriteVocToCatcher(I, buf);
    }
    
    if (vm.isMediaVmRecord)
    {
        vm4WayPcmRecord(eplfrm_t.ul_pre_buf, eplfrm_t.ul_pre_len, eplfrm_t.dl_pre_buf, eplfrm_t.dl_pre_len);
        vm4WayPcmRecord(eplfrm_t.ul_pos_buf, eplfrm_t.ul_pos_len, eplfrm_t.dl_pos_buf, eplfrm_t.dl_pos_len);
        
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
        if (vm.debug_info & VM_PCM_REFMIC_RECORD_FLAG)
	   	{
            vmRefMic_AGC_PcmRecord(false, eplfrm_t.ul2_pos_buf, eplfrm_t.ul2_pos_len);
	   	}
#endif
    }
    else if (vm.isVocOn)
    {
        voc4WayPcmRecord(eplfrm_t.ul_pre_buf, eplfrm_t.ul_pre_len, eplfrm_t.dl_pre_buf, eplfrm_t.dl_pre_len);
        voc4WayPcmRecord(eplfrm_t.ul_pos_buf, eplfrm_t.ul_pos_len, eplfrm_t.dl_pos_buf, eplfrm_t.dl_pos_len);
        
#if defined(__DUAL_MIC_SUPPORT__)
        if(vm.debug_info & VM_PCM_REFMIC_RECORD_FLAG)
        {
            vmRefMic_AGC_PcmRecord(true, eplfrm_t.ul2_pos_buf, eplfrm_t.ul2_pos_len);
        }
#endif
    }
    
    // Reset
    vm.vmBuf[0] = 0;
    vm.vmBuf[1] = 0;
    vm.vmBuf[2] = 0;
    vm.pcm_lost_count = 0;
    
    return;
}
#else   // chip compile option

#define USE_WB_PCM (0x1)
#define USE_NB_PCM (0x0)

static uint32 vm_set_pcm_size(uint16 prev_addr)
{
    uint32 pcm_size;

#if defined(_FWE_SUPPORT_)
    if (PCM1_DL_BUF_ADDR == prev_addr)
    {   // Make sure it is DL address
        pcm_size = NB_FRAME_BUF_SIZE+WB_FRAME_BUF_SIZE+3;
    }
    else
#endif  //  _FWE_SUPPORT_
    {
        pcm_size = NB_FRAME_BUF_SIZE+NB_FRAME_BUF_SIZE+3;
    }
    
    return pcm_size;
}

static void vm_read_buffer(uint16 prev_page, uint16 prev_addr, uint16 post_page, uint16 post_addr)
{
    uint16 *buf = vm.pcmBuf;
    uint16 third_word;
    uint32 dl_frame_buf_size;

#if defined(_FWE_SUPPORT_)
    if (PCM1_DL_BUF_ADDR == prev_addr)
    {   // Make sure it is DL address
        third_word        = (USE_WB_PCM<<1) + (USE_NB_PCM<<0);
        dl_frame_buf_size = WB_FRAME_BUF_SIZE;
    }
    else
#endif  //  _FWE_SUPPORT_
    {
        third_word        = (USE_NB_PCM<<1) + (USE_NB_PCM<<0);
        dl_frame_buf_size = NB_FRAME_BUF_SIZE;
    }
    
    // Header for record set of UL-DL PCM data
    *buf++ = (vm.vm_lost_count << 8) + vm.pcm_lost_count;   // 1st word in header
    *buf++ = vm_counter;                                    // 2nd word in header
    *buf++ = third_word;                                    // 3rd word in header --> Set BandInfo for PCM; bit0:Prev-PCM, bit1:Post-PCM
    
    IDMA_ReadFromDSP(buf, DSP_DM_ADDR(prev_page, prev_addr), NB_FRAME_BUF_SIZE);   // Uplink
    buf += NB_FRAME_BUF_SIZE;
    IDMA_ReadFromDSP(buf, DSP_DM_ADDR(post_page, post_addr), dl_frame_buf_size);   // Downlink
    
    return;
}

#if defined(__DUAL_MIC_SUPPORT__)
static void vmRefMic_AGC_PcmRecord( void )
{
    uint32 I, tmp = 0;
    uint16 dummy;
    uint16 *buf = vm.pcmBuf;
    uint16 *mBuf;
    
    *buf++ = (vm.vm_lost_count << 8) + vm.pcm_lost_count;
    *buf++ = vm_counter;
    
    {   // RefMic
        IDMA_ReadFromDSP(buf                        , DSP_DM_ADDR(REFMIC_PAGE_NUM, PCM3_UL_BUF_ADDR), (uint32)NB_FRAME_BUF_SIZE);
        IDMA_ReadFromDSP(buf + NB_FRAME_BUF_SIZE    , DSP_DM_ADDR(REFMIC_PAGE_NUM, 0x37B9), (uint32)1);
        IDMA_ReadFromDSP(buf + NB_FRAME_BUF_SIZE + 1, DSP_DM_ADDR(REFMIC_PAGE_NUM, 0x37BE), (uint32)1);
    }
    
    vmWriteVmToMB(VM_REFMICPCM_DEBUG_SIZE, vm.pcmBuf);
    
    return;
}

static void vocRefMic_AGC_PcmRecord( void )
{
    uint16 *buf = vm.pcmBuf;
   
    *buf++ = (vm.vm_lost_count << 8) + vm.pcm_lost_count;
    *buf++ = vm_counter;
   
    {   // RefMic
        IDMA_ReadFromDSP(buf,                         DSP_DM_ADDR(REFMIC_PAGE_NUM, PCM3_UL_BUF_ADDR), (uint32)NB_FRAME_BUF_SIZE);
        IDMA_ReadFromDSP(buf + NB_FRAME_BUF_SIZE,     DSP_DM_ADDR(REFMIC_PAGE_NUM, 0x37B9),           (uint32)1);
        IDMA_ReadFromDSP(buf + NB_FRAME_BUF_SIZE + 1, DSP_DM_ADDR(REFMIC_PAGE_NUM, 0x37BE),           (uint32)1);
    }
    
    vocWriteVocToCatcher(VM_REFMICPCM_DEBUG_SIZE, vm.pcmBuf);
    
    return;
}
#endif  // __DUAL_MIC_SUPPORT__

static void vm4WayPcmRecord(uint16 prev_page, uint16 prev_addr, uint16 post_page, uint16 post_addr)
{
    uint32 pcm_size = vm_set_pcm_size(prev_addr);
    
    vm_read_buffer(prev_page, prev_addr, post_page, post_addr);
    
    vmWriteVmToMB(pcm_size, vm.pcmBuf);
    
    return;
}

static void voc4WayPcmRecord(uint16 prev_page, uint16 prev_addr, uint16 post_page, uint16 post_addr)
{
    uint32 pcm_size = vm_set_pcm_size(prev_addr);
    
    vm_read_buffer(prev_page, prev_addr, post_page, post_addr);
    
    {   // Write to VOC
        vocWriteVocToCatcher(pcm_size, vm.pcmBuf);
    }
    
    return;
}

void vmTchPcmRecordHisr(void *param)
{
    uint32 I, tmp = 0;
    uint16 dummy;
    uint16 *buf, *mBuf;
    
    if (vm.state != VM_STATE_RECORD)
    {
        return;
    }
    
    buf = (uint16 *)vm.vmBuf;
    if (buf[0] == VM_MAGIC_HEADER)
    {   // Already buffer VM
        tmp = ( buf[1] >> 3 ) + vm.pcm_save_size;   // Debug size
        I = tmp + GET_VM_LENGTH(vm.control, buf[5]);
    }
    else
    {
        tmp = vm.pcm_save_size;   // Debug size (only PCM)
        I = vm.pcm_save_size + 3; // Plus sync word and format
    }
    
    if (vm.isMediaVmRecord)
    {
        if (mediaGetFreeSpace() < I)
        {
            vm.pcm_lost_count++;
            return;
        }
        else
        {
            buf[0] = VM_MAGIC_HEADER;
            buf[1] = (uint16)(tmp << 3) | ( L1SP_GetState());
            buf[2] |= (vm.debug_info & (VM_PCM_REFMIC_RECORD_FLAG + VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG));
        }
        Media_GetWriteBuffer(&mBuf, &tmp);
        I -= vm.pcm_save_size;
        if (tmp > I)
        {
            tmp = I;
        }
        
        for (dummy = (uint16)tmp; dummy > 0; dummy--)
        {
            *mBuf++ = *buf++;
        }
        vmWriteDataDone(tmp);
        I -= tmp;
        if ((int32)I > 0)
        {
            Media_GetWriteBuffer(&mBuf, &tmp);
            for (dummy = (uint16)I; dummy > 0; dummy--)
            {
                *mBuf++ = *buf++;
            }
            vmWriteDataDone( I );
        }
    }
    else if(vm.isVocOn)
    {
        buf[0] = VM_MAGIC_HEADER;
        buf[1] = (uint16)(tmp << 3) | ( L1SP_GetState()) ;
        buf[2] |= ( vm.debug_info & (VM_PCM_REFMIC_RECORD_FLAG + VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG) );
        I -= vm.pcm_save_size;
        vocWriteVocToCatcher(I, buf);
    }
    
    ASSERT(*DP_TCH_UL_LEN == NB_FRAME_BUF_SIZE);    // Uplink frame size
    ASSERT(*DP_TCH_DL_LEN == NB_FRAME_BUF_SIZE);    // Downlink frame size
    
    if (vm.isMediaVmRecord)
    {
        if (vm.debug_info & VM_PCM_1ST_SET_RECORD_FLAG)
        {
            vm4WayPcmRecord(PCM1_UL_PAGE_NUM, PCM1_UL_BUF_ADDR, PCM2_UL_PAGE_NUM, PCM2_UL_BUF_ADDR);
        }
        
        if (vm.debug_info & VM_PCM_2ND_SET_RECORD_FLAG)
        {
            vm4WayPcmRecord(PCM1_DL_PAGE_NUM, PCM1_DL_BUF_ADDR, PCM2_DL_PAGE_NUM, PCM2_DL_BUF_ADDR);
        }
    }
    else if(vm.isVocOn)
    {
        voc4WayPcmRecord(PCM1_UL_PAGE_NUM, PCM1_UL_BUF_ADDR, PCM2_UL_PAGE_NUM, PCM2_UL_BUF_ADDR);
        voc4WayPcmRecord(PCM1_DL_PAGE_NUM, PCM1_DL_BUF_ADDR, PCM2_DL_PAGE_NUM, PCM2_DL_BUF_ADDR);
    }
    
#if defined(__DUAL_MIC_SUPPORT__)
    if (vm.debug_info & VM_PCM_REFMIC_RECORD_FLAG)
    {
        vmRefMic_AGC_PcmRecord();
    }
#endif

    // Reset
    vm.vmBuf[0] = 0;
    vm.vmBuf[1] = 0;
    vm.vmBuf[2] = 0;
    vm.pcm_lost_count = 0;
    
    return;
}
#endif  // chip compile option

void vmTchRecordHisr(void *param)
{
   if( vm.state != VM_STATE_RECORD )
      return;
   
   if( L1SP_GetState() != L1SP_STATE_2G_SPEECH_ON )
      return;
      
   if (vm.isMediaVmRecord && mediaGetFreeSpace() < VM_MAXIMUM_SAVE_SIZE)
   {
      vm.vm_lost = 1; 
      vm.vm_lost_count ++;
      mediaDataNotification();
      return;       
   }
   
   vm.vm_lost = 0;
   vmRecordHisr();
   mediaIncRecordTime();  //for update record time
   mediaDataNotification();        
}

#pragma arm section

extern void SP3G_Start_VM( void ); 
extern void SP3G_Stop_VM( void ); 
extern bool SP3G_VM_Status( void ); 

void vmSpeechOnHandler( void *state ) 
{
   if ((vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG)) == 0x3)
   {     
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      AM_VM_EPL_RecordOn();
#else   // chip compile option
      AM_PCM8K_RecordOn(); 
#endif  // chip compile option
   }
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
   SP3G_Start_VM();
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   L1Audio_HookHisrHandler( DP_D2C_VM_REC_INT, vmTchRecordHisr, 0 );
#else   // chip compile option
   L1Audio_HookHisrHandler( DP_D2C_SE_SD_DONE, vmTchRecordHisr, 0 );
#endif  // chip compile option
   AM_VMRecordOn( (uint16)vm.type );
}

void vmSpeechOffHandler( void *state ) 
{      
   if ((vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG)) == 0x3)
   {      
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      AM_VM_EPL_RecordOff();
#else   // chip compile option
      AM_PCM8K_RecordOff(false);
#endif  // chip compile option
   }
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
   SP3G_Stop_VM();
#endif
   *DP_SC_MUTE = 0x0000;

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   L1Audio_UnhookHisrHandler( DP_D2C_VM_REC_INT );
#else   // chip compile option
   L1Audio_UnhookHisrHandler( DP_D2C_SE_SD_DONE );
#endif  // chip compile option
   AM_VMRecordOff();
}


void vmRecord( mediaControl *ctrl, uint16 type, kal_bool isVoc )
{
   kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;
   
   if(isVoc)
   {
      ASSERT(vm.isVocOn == false);			
      vm.isVocOn = true;
      if(vm.isMediaVmRecord)  // vm already start
      {
         return;
      }
   }
   else
   {
      ASSERT(vm.isMediaVmRecord == false);
      vm.ctrl = ctrl;
      vm.isMediaVmRecord = true;
      if(vm.isVocOn)  // vm already start
      {
         return;
      }
   }

   vm.type = type;
   vm.state = VM_STATE_RECORD;

   vm.vmBuf = (int16 *)get_ctrl_buffer( VM_BUFFER_SIZE );
   memset( vm.vmBuf, 0, VM_BUFFER_SIZE );

   if( AM_IsSpeechOn() ) {
      vm.control = 0x0003;
	  vm.control_1 = 0x0001;
	  vm.control_2 = 0x0001;
      vm.debug_info = L1Audio_GetDebugInfo(VM_DEBUG_INFO);

      if(!tst_trace_check_ps_filter_off(TRACE_GROUP_EPL, &module_id, 0x2))
      {
         vm.debug_info |= 0x3;
      }
		  
      if ((vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG)) == 0x3)
      {
         #if defined(__DUAL_MIC_SUPPORT__)
         vm.debug_info |= VM_PCM_REFMIC_RECORD_FLAG;
         if(vm.debug_info & VM_PCM_REFMIC_RECORD_FLAG){
            vm.pcm_save_size = FIVE_PCM_SAVE_SIZE;
         }else
         #endif
         {
            vm.pcm_save_size = FOUR_PCM_SAVE_SIZE;
         } 
         vm.pcmBuf = (uint16 *)get_ctrl_buffer( MAX_PCM_BUF_SIZE * sizeof(short) );
         vm.pcm_lost_count = 0; 
         vm.vm_lost  = 1; // to force save VM first     
         vm.vm_lost_count = 0;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
         L1Audio_HookHisrHandler( DP_D2C_VMEPL_REC_INT, vmTchPcmRecordHisr, 0 );
#else   // chip compile option
         L1Audio_HookHisrHandler( DP_D2C_PCM_TCH_R, vmTchPcmRecordHisr, 0 );
#endif  // chip compile option

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
         AM_VM_EPL_RecordOn();
#else   // chip compile option
         AM_PCM8K_RecordOn(); 
#endif  // chip compile option
      }
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
      SP3G_Start_VM();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      g_bNeedExtraLog = KAL_TRUE;
#endif
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
         L1Audio_HookHisrHandler( DP_D2C_VM_REC_INT, vmTchRecordHisr, 0 );
#else   // chip compile option
         L1Audio_HookHisrHandler( DP_D2C_SE_SD_DONE, vmTchRecordHisr, 0 );
#endif  // chip compile option

      AM_VMRecordOn( (uint16)type );
      L1SP_Register_Service(vmSpeechOnHandler, vmSpeechOffHandler);
   }
   else {
      // for idle-mode recording , will use DP_D2C_SE_DONE , through mediaHisr -> vmRecordHisr
      vm.control = 0x0003;
	  vm.control_1 = 0x0001;
	  vm.control_2 = 0x0001;
      *DP_SC_MUTE = 0x0002;

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      Media_Hook_Record_HISR(DP_D2C_VM_REC_INT, NULL);
#endif  // chip compile option

      AM_VMRecordOn( (uint16)type );
   }
}

Media_Status vmPlay( mediaControl *ctrl )
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support VM playback
    return MEDIA_UNSUPPORTED_OPERATION;
#else   // chip compile option
   uint32 dummy_32;

   vm.ctrl = ctrl;
   vm.state = VM_STATE_PLAY;
   vm.control = 0;

/* VRD parser */
   if(vm.ctrl->format == MEDIA_FORMAT_VRD){
         /* Check to see if header is invalid, "MTKV" or "CYBV" chunk descriptor */
      if( rb_GetDWord( &dummy_32 ) == false || (dummy_32 != 0x564B544D && dummy_32 != 0x56425943))
         return MEDIA_BAD_FORMAT;

      rb_SkipNWord( 3 ); /* skip chunk size and ID field*/

      if( rb_GetDWord( &dummy_32 ) == false || dummy_32 != 0x45434F56 ) /* "VOCE" chunk descriptor */
         return MEDIA_BAD_FORMAT;

         // Get the VOCE ckSize
      if( rb_GetDWord( &vm.rb_data_len ) == false )
         return MEDIA_BAD_FORMAT;

      vm.rb_data_len >>= 1; /* change data length in word */
   }

   vm_playback();
   return MEDIA_SUCCESS;
#endif  // chip compile option
}

void vmStop( mediaControl *ctrl )
{
   (void) ctrl;

   ASSERT((vm.isVocOn == true) || (vm.isMediaVmRecord == true));
   if(vm.isVocOn)
   {
			vm.isVocOn = false; 
      if(vm.isMediaVmRecord)  //still another need vm
      {		
         return;
      }
   } 
   else  //record vm from media
   {
      vm.isMediaVmRecord = false;
      if(vm.isVocOn)  //still another need vm
      {			
         return;
      }
   }
      
   if(vm.control & 0x02)
   {
      vm.state = VM_STATE_RECORD_STOP;
      if ((vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG)) == 0x3)
      {    
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
         AM_VM_EPL_RecordOff();
         L1Audio_UnhookHisrHandler( DP_D2C_VMEPL_REC_INT );
#else   // chip compile option
         AM_PCM8K_RecordOff(false);
         L1Audio_UnhookHisrHandler( DP_D2C_PCM_TCH_R );
#endif  // chip compile option
         free_ctrl_buffer(vm.pcmBuf);
         
      }
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      L1Audio_UnhookHisrHandler(DP_D2C_VM_REC_INT);
#else   // chip compile option
      L1Audio_UnhookHisrHandler(DP_D2C_SE_SD_DONE);
#endif  // chip compile option
      L1SP_UnRegister_Service();
   }
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   else if (vm.control & 0x1)
   {  // Idle VM record (UL only)
      vm.state = VM_STATE_RECORD_STOP;
      Media_Unhook_Record_HISR();
   }
#endif  // chip compile option

   switch(vm.state) {
      case VM_STATE_RECORD_PAUSE:
         break;
      case VM_STATE_RECORD:
      case VM_STATE_RECORD_STOP:
         AM_VMRecordOff();
         *DP_SC_MUTE = 0x0000;
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
         if(SP3G_VM_Status())
            SP3G_Stop_VM();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         g_bNeedExtraLog = KAL_FALSE;
#endif
#endif
         break;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support VM playback
#else   // chip compile option
      case VM_STATE_PLAY:
      case VM_STATE_PLAY_PAUSE:
         AM_VMPlaybackOff(vm.ctrl->param.vm);
         break;
#endif  // chip compile option
      default:
         ASSERT(KAL_FALSE);
   }

   if( vm.vmBuf != NULL ){
      free_ctrl_buffer( vm.vmBuf );
      vm.vmBuf = NULL;
   }

   vm.state = VM_STATE_STOP;
}

void vmPause(mediaControl *ctrl)
{
   switch(vm.state) {
      case VM_STATE_RECORD:
         if((vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG)) == 0x3 && AM_IsSpeechOn())
         {
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
            AM_VM_EPL_RecordOff();
#else   // chip compile option
            AM_PCM8K_RecordOff(false);
#endif  // chip compile option
         }
         *DP_SC_MUTE = 0x0000;
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
         if(SP3G_VM_Status())
            SP3G_Stop_VM();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         g_bNeedExtraLog = KAL_FALSE;
#endif
#endif
         AM_VMRecordOff();
         vm.state = VM_STATE_RECORD_PAUSE;
         break;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support VM playback
#else   // chip compile option
      case VM_STATE_PLAY:
         AM_VMPlaybackOff(vm.ctrl->param.vm);
         vm.state = VM_STATE_PLAY_PAUSE;
         break;
#endif  // chip compile option
      default:
         ASSERT(KAL_FALSE);
   }
}

void vmResume(mediaControl *ctrl)
{
   switch(vm.state) {
      case VM_STATE_RECORD_PAUSE:
         if( AM_IsSpeechOn() ) {
            vm.control = 0x0003;
            if((vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG)) == 0x3)
            {
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
               AM_VM_EPL_RecordOn();
#else   // chip compile option
               AM_PCM8K_RecordOn(); 
#endif  // chip compile option
            }
         }
         else {
            vm.control = 0x0003;
            *DP_SC_MUTE = 0x0002;
         }
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
         SP3G_Start_VM();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         g_bNeedExtraLog = KAL_TRUE;
#endif
#endif
         AM_VMRecordOn( (uint16)vm.type );
         vm.state = VM_STATE_RECORD;
         break;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support VM playback
#else   // chip compile option
      case VM_STATE_PLAY_PAUSE:
         vm.state = VM_STATE_PLAY;
         vm.control = 0;
         vm_playback();
         break;
#endif  // chip compile option
      default:
         ASSERT(KAL_FALSE);
   }
}
/* ------------------------------------------------------------------------------ */

extern uint32 L1I_GetTimeStamp( void );
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
extern void UL1D_RXBRP_GET_INFO_FOR_SPEECH_VM(kal_int16* tpc_SIR_lta, kal_int16* dpdch_SIR_lta, kal_int16* TFCI_max_corr);
void sp3g_vmRecordService( uint32 *l1_info, uint16 crc_result, uint16 buf_status, uint16 *ul_frame_data, uint16* dl_frame_data, uint8 dl_count )
{
   volatile uint16   *addr;
   uint16   I, sc_mode, sd_mode, sc_len, sd_len; 
   uint16   *vmBuf;
   uint32 J;
   uint8 *ptr;
   
   mediaIncRecordTime();  //for update record time

   vmBuf = (uint16 *)vm.vmBuf;
   if( vmBuf[0] == VM_MAGIC_HEADER ){//already buffer VM
      J = (uint32)( vmBuf[1] >> 3 ) + GET_VM_LENGTH(vm.control, vmBuf[5]);
      if( mediaGetFreeSpace() < J ){
         vm.vm_lost = 1;
         vm.vm_lost_count++;
         return;
      }
      else{
         vmWriteVmToMB( J, vmBuf );
         // Reset
         vm.vmBuf[0] = 0;
         vm.vmBuf[1] = 0;
         vm.vmBuf[2] = 0;
      }
   }
   vm.vm_lost_count = 0;
   
   I = DP_3G_DL_RX_MODE_REPORT >> 8;
	sd_mode = I & 0x1F;
   I = DP_3G_UL_TX_MODE_REPORT >> 8;
	sc_mode = I & 0x1F;
   
   ASSERT_REBOOT( (sc_len = AM_GetSpeechPatternLength(sc_mode)) > 0 );
   ASSERT_REBOOT( (sd_len = AM_GetSpeechPatternLength(sd_mode)) > 0 );
   
   I = *DP_3G_DL_RX_TYPE >> 1;

   I = ((I & 0x10)>>1) | (I & 0x07);
   vm.control =(I << 12) |
               ((*DP_3G_UL_TX_TYPE & 3)<< 10 ) |
               (sd_mode << VM_CTRL_SD_START) |
               (sc_mode << VM_CTRL_SC_START) |
               0x3; 
   kal_dev_trace( TRACE_INFO, VM_CONTROL, vm.control );
   // record syn_word for VM_LOG_DEBUG 
      
   *vmBuf++ = VM_MAGIC_HEADER;
   J = L1SP_GetState();
   I = (uint16)( ( vmRecGetDebugSize(sc_mode, sd_mode, vm.debug_info, J) << 3 ) | J);
   *vmBuf++ = I;
   *vmBuf++ = VM_VM_RECORD_FLAG ;          //VM
   J = L1I_GetTimeStamp();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   if( g_bNeedExtraLog )
   	  kal_dev_trace( TRACE_INFO, VM_SP3G_VM_L1T, J );
#endif
   I = (uint16)(J & 0xFFFF);
   *vmBuf++ = I;
   I = (uint16)((J >> 16) + ((uint32)vm_counter << 8));
   *vmBuf++ = I;
   vm_counter++;
   
   // record vm control value    
   *vmBuf++ = vm.control;
   
   // record UL data    
   addr = DP_3G_UL_TX_ADDR;
   for( I = 0; I < sc_len; I++ )
      *vmBuf++ = *addr++;
      
   // record DL data    
   addr = DP_3G_DL_RX_ADDR;
   for( I = 0; I < sd_len; I++ )
      *vmBuf++ = *addr++;
   
   // record debug information    
   *vmBuf++ = DP_3G_DL_RX_MODE_REPORT;	// Rx
   *vmBuf++ = DP_3G_UL_TX_MODE_REPORT;	// Tx
   addr = DPRAM2_base(0x164);
   for( I = 0; I <13; I++ )  // DSP current debug info inside SHERIF 
      *vmBuf++ = *addr++;

   if( L1SP_GetState() == L1SP_STATE_3G_SPEECH_ON || L1SP_GetState() == L1SP_STATE_3G324M_SPEECH_ON ){
      kal_int16 tpc_SIR_lta, dpdch_SIR_lta, TFCI_max_corr;
      uint32 l1Info, s_value;
      if( l1_info == NULL ){
         l1Info = 0;
         tpc_SIR_lta = 0;
         dpdch_SIR_lta = 0;
         TFCI_max_corr = 0;
         s_value = 0;
      }else{
         l1Info = l1_info[1];
         tpc_SIR_lta = l1_info[4];
         dpdch_SIR_lta = l1_info[5];
         TFCI_max_corr = l1_info[6];
         s_value = l1_info[3];
      }
      I = (uint16)(l1Info & 0xFFFF);
      *vmBuf++ = I;
      I = (uint16)(l1Info >> 16);
      *vmBuf++ = I;
      *vmBuf++ = crc_result;
      *vmBuf++ = (uint16)((s_value >= 32767)? 32767 : s_value);//s_value
#if defined( __MTK_UL1_FDD__ )// only MTK 3G has this function
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
      *vmBuf++ = (uint16)tpc_SIR_lta;
      *vmBuf++ = (uint16)dpdch_SIR_lta;
      *vmBuf++ = (uint16)TFCI_max_corr;
   }
   
   *vmBuf++ = buf_status;    // buffer status;
   
   //UL
   for( I = 0 ; I < 17 ; I ++)
      *vmBuf++ = *ul_frame_data++;
   //DL
   ptr = (uint8 *)dl_frame_data;
   if( dl_count > 0 ){
      J = 19;
      ASSERT( (/* *ptr >= 0 && */ *ptr <= 8 ) || *ptr == 15 );
   }
   else{
      J = 0;
   }
      
   for( I = 0 ; I < (uint16)J ; I ++)
      *vmBuf++ = *dl_frame_data++;
   for( I = (uint16)J ; I < 19 ; I ++)
      *vmBuf++ = 0;
   mediaDataNotification();
}
#endif // __UMTS_RAT__ || defined( __UMTS_TDD128_MODE__ )

#endif
