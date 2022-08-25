/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 * audio_def.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file defines all the audio registers used in audio module.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#if defined(MT6270A) || defined(MT6276) || defined(MT6573)
   #include "../../v2/inc/l1audio_def.h"
#elif defined(__SMART_PHONE_MODEM__) || defined(TK6516) || defined(MT6516)
   #include "../sp/l1audio_def.h"
#else

#ifndef __AUDIO_DEF_H
#define __AUDIO_DEF_H

#include "kal_public_api.h"
#include "audio_dsp_d2c_def.h"
#include "common_def.h"

#if defined(MT6260)
   #include "dpram_6260.h"
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)  
   #include "dpram_6261.h" 
#else
   #include "dpram_former.h"
#endif
/* -------------------------------------------------------------------------- */
/* ring buffer handling                                                       */
/* -------------------------------------------------------------------------- */

/*
   Example: define a ring buffer of 8 integers, put the value 3 and get it again:

   RINGBUFFER_T(int,8) myBuffer;
   RB_PUT( myBuffer, 3 );

   int value;
   RB_GET( myBuffer, value );
*/

//   size must be a power of two

#ifndef RINGBUFFER_T
#define RINGBUFFER_T(elemtype,size) \
   struct \
   { \
      volatile uint32 write; /* must be unsigned */ \
      volatile uint32 read;  /* must be unsigned */ \
      elemtype volatile queue[size]; \
   }

#define RB_SIZE( rb ) \
   ( sizeof( rb.queue ) / sizeof( *rb.queue ) )

#define RB_MASK( rb ) \
   ( RB_SIZE( rb ) - 1 )

#define RB_INIT( rb ) \
   ( rb.read = rb.write = 0 )

#define RB_COUNT( rb ) \
   ( rb.write - rb.read )

#define RB_FULL( rb ) \
   ( RB_COUNT( rb ) >= RB_SIZE( rb ) )

#define RB_EMPTY( rb ) \
   ( rb.write == rb.read )

#define RB_PUT( rb, value ) \
{ \
   ASSERT( !RB_FULL( rb ) ); \
   rb.queue[ rb.write & RB_MASK( rb ) ] = value; \
   ++rb.write; \
}

#define RB_GET( rb, value ) \
{ \
   ASSERT( !RB_EMPTY( rb ) ); \
   value = rb.queue[ rb.read & RB_MASK( rb ) ]; \
   ++rb.read; \
}

#define RB_PEEK( rb, value ) \
{ \
   ASSERT( !RB_EMPTY( rb ) ); \
   value = rb.queue[ rb.read & RB_MASK( rb ) ]; \
}

#define RB_PEEK_THROUGH( rb, idx, value ) \
{ \
   ASSERT( (rb.read+idx) < rb.write ); \
   value = rb.queue[ (rb.read+idx) & RB_MASK( rb ) ]; \
}

#define RB_CONSUME( rb ) \
{ \
   ASSERT( !RB_EMPTY( rb ) ); \
   ++rb.read; \
}

#define RB_UNPUT( rb, value ) \
{ \
   ASSERT( !RB_EMPTY( rb ) ); \
   --rb.write; \
   value = rb.queue[ rb.write & RB_MASK( rb ) ]; \
}

#define RB_UNGET( rb, value ) \
{ \
   ASSERT( !RB_FULL( rb ) ); \
   --rb.read; \
   rb.queue[ rb.read & RB_MASK( rb ) ] = value; \
}

#endif /* RINGBUFFER_T */


/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Feature Definitions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Definitions
//=============================================================================================
#define DSP_ENA_VM_INTERRUPT     0x0010   /* DSP to CPU interrupt for Voice Memo (SHARE_D2MCON) */
#define DSP_ENA_AVSYNC_INTERRUPT 0x0020   /* DSP to CPU interrupt for A/V Sync (SHARE_D2MCON) */
#define DP_AAC_CTRL_ASP          0x0001
#define DP_PCM_R_DIS             0x0002

//=============================================================================================
//                  Options
//=============================================================================================
#define _AAC_DUAL_SCE_SUPPORT_  ( defined(MT6236) || defined(MT6256) || defined(MT6255) )
//#define AUDLP_DEBUG_ENABLE         //Dior, this only for debugging
#define APM_SUPPORT  ( ( defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) && !defined( MED_MODEM ) && !defined( MED_NOT_PRESENT ) )
// MT6236/55/56.. support APM, except MED_MODEM is defined for Modem only load

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       AUDIO SHERIF BASE ADDRESS
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
   #define DP_AUDIO_CTRL_base(a)              (DPRAM2_base(DP2_AUDIO_CTRL_FIELD_BASE)        +(a))
   #define DP_AV_SYNC_CTRL_base(a)            (DPRAM2_base(A2V_BASE)                         +(a))
   #define DP_WAV_CTRL_base(a)                (DPRAM2_base(DP2_WAV_CTRL_FIELD_BASE)          +(a))
   #define DP_WT_CTRL_base(a)                 (DPRAM2_base(DP2_WT_CTRL_FIELD_BASE)           +(a))
   #define DP_DAF_CTRL_base(a)                (DPRAM2_base(DP2_MP3_CTRL_FIELD_BASE)          +(a))
   #define DP_AUDIO_PP_CTRL_base(a)           (DPRAM2_base(DP2_AUDIO_PP_CTRL_BASE)           +(a))
   #define DP_EXTRA_APPLICATION_base(a)       (DPRAM2_base(DP2_EXTRA_APPLICATION_FILED_BASE) +(a))
   #define DP_DYNAMIC_LOAD_base(a)            (DPRAM2_base(DP2_Dynamic_Load_field_BASE)      +(a))


/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AUDIO DSP Decoder Control Sherifs
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  AUDIO DSP Playback Control
//=============================================================================================
   #define DP_ASP_TYPE                        DP_AUDIO_CTRL_base(0)
   #define DP_ASP_FS                          DP_AUDIO_CTRL_base(1)
   #define DP_ASP_DEL_W                       DP_AUDIO_CTRL_base(2)
   #define DP_ASP_DEL_M                       DP_AUDIO_CTRL_base(4)
   #define DSP_AUDIO_DEC_FRAME_LENGTH         DP_AUDIO_CTRL_base(3)
   
   // rename DP_AUDIO_DEC_FRAME_LENGTH DSP_AUDIO_DEC_FRAME_LENGTH
//=============================================================================================
//                  PCM DSP Playback Control
//=============================================================================================
   #define DSP_PCM_CTRL                       DP_WAV_CTRL_base(0)
   #define DSP_PCM_W                          DP_WAV_CTRL_base(1)
   #define DSP_PCM_R                          DP_WAV_CTRL_base(2)
   #define DSP_PCM_MS                         DP_WAV_CTRL_base(3)

/* -------------------------------------------------------------------------- */
/* AMR-WB playback control                                                    */
/* -------------------------------------------------------------------------- */
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   #define AWBPLUS_STATUS            DP_DAF_CTRL_base(0)
   #define AWBPLUS_FIFO_BASE         DP_DAF_CTRL_base(1)  /* Indicate start point for MCU to DSP stream transfer */
   #define AWBPLUS_CONFIG_BASE       DP_DAF_CTRL_base(2)  /* Indicate start point for MCU to DSP configuration   */
   #define AWBPLUS_ERROR_REPORT      DP_DAF_CTRL_base(3)  /* Indicate the error status                 */
#endif

/*  AMR_AWB_AUDIO_PATH_SUPPORT    */
   #define AMR_AWB_AUDIO_PATH_CTRL   DP_DAF_CTRL_base(0)


//=============================================================================================
//                  DAF DSP Decoder Control
//=============================================================================================
#if defined(DAF_DECODE)
   #define DAF_MAIN_CONTROL                   DP_DAF_CTRL_base(0)  // Start/Stop [0]
                                                                   // Pause      [1]
                                                                   // MP3 Reset  [2]
                                                                   // EQ_Enable  [3]
   #define DAF_CHKSUM_ENABLE                  DP_DAF_CTRL_base(1)
   #define DAF_FIFO_BASE                      DP_DAF_CTRL_base(2)  // Indicate start point for MCU to DSP stream transfer
   #define DAF_FIFO_LENGTH                    DP_DAF_CTRL_base(3)  // Indicate FIFO size
   #define DAF_DSP_READ_PTR                   DP_DAF_CTRL_base(4)  // Indicate the next word DSP will read
   #define DAF_MCU_WRITE_PTR                  DP_DAF_CTRL_base(5)  // Indicate the next word MCU will write
   #define MP3_FRAME_SIZE_TABLE_DM_PAGE       DP_DAF_CTRL_base(6)  //Indicate the frame size table (total 45 words) will be written to which page DM
   #define MP3_FRAME_SIZE_TABLE_BASE          DP_DAF_CTRL_base(7)  //Indicate the start point for MCU to wirte the frame size table (total 45 words)
   #define DAF_CHKSUM                         DP_DAF_CTRL_base(8)
  #if (DAF_DSP_BS_DMPATH)
   #define DAF_FRAME_COUNT_H                  DP_DAF_CTRL_base(9)
   #define DAF_FRAME_COUNT_L                  DP_DAF_CTRL_base(10)
  #endif
#endif //DAF_DECODE

//=============================================================================================
//                  AAC DSP Decoder Control
//=============================================================================================
#if defined(AAC_DECODE)
   #define AAC_MAIN_CONTROL                   DP_DAF_CTRL_base(0)  /* Start/Stop [0]                            */
   #define AAC_STATUS                         DP_DAF_CTRL_base(1)
   #define AAC_FIFO_BASE                      DP_DAF_CTRL_base(2)  /* Indicate start point for MCU to DSP stream transfer */
   #define AAC_FIFO_LENGTH                    DP_DAF_CTRL_base(3)  /* Indicate FIFO size                        */
   #define AAC_DSP_READ_PTR                   DP_DAF_CTRL_base(4)  /* Indicate the next word DSP will read      */
   #define AAC_MCU_WRITE_PTR                  DP_DAF_CTRL_base(5)  /* Indicate the next word MCU will write     */
   #define AAC_ERROR_REPORT                   DP_DAF_CTRL_base(6)  /* Indicate the error status                 */
   #define AAC_DSP_REPORT                     DP_DAF_CTRL_base(7)  /* Checksum DSP status check                 */
   #define AACPS_CHKSUM_ENABLE                DP_DAF_CTRL_base(6)  /* Indicate the error status */
   #define AACPS_OUTPUT_CHK_SUM               DP_DAF_CTRL_base(7)  /* Checksum DSP status check */
   #define AAC_DUAL_SCE                       DP_DAF_CTRL_base(8)  /* Dual SCE channel control */
   #define AAC_ALLERROR_REPORT                DP_DAF_CTRL_base(9)  /* Report all AAC decoding error */
   #define AAC_PS_CONTROL                     DP_DAF_CTRL_base(0)
   #define AACPS_BS_FLAG                      DP_DAF_CTRL_base(1)
   #define AAC_PS_BITSTR_ADDRESS              DP_DAF_CTRL_base(2)
   #define AAC_PS_BITSTR_Length               DP_DAF_CTRL_base(3)
   #define AAC_PS_PCM_ADDRESS                 DP_DAF_CTRL_base(4)
   #define AAC_PS_PCM_DMOVLAY                 DP_DAF_CTRL_base(5)
   #define AAC_PS_PCM_CHECKSUM                DP_DAF_CTRL_base(6)
   
 #if defined(MT6256) ||  defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   #define AAC_OUT_DATA_PAGENUM               DP_DAF_CTRL_base(11)
   #define AAC_OUT_PCM_ADDRESS                DP_DAF_CTRL_base(12)
   #define AAC_OUT_SBRBS_ADDRESS              DP_DAF_CTRL_base(13)
   #define AAC_OUT_SBRPCM_ADDRESS             DP_DAF_CTRL_base(14)
   #define AAC_DSPDEC_FOR_SBR                 DP_DAF_CTRL_base(15)
 #endif // defined(MT6256_S01) ||  defined(MT6255)
#endif //AAC_DECODE

//=============================================================================================
//                  BSAC DSP Decoder Control
//=============================================================================================
#if defined(BSAC_DECODE)
/* under construction !*/
/* under construction !*/
#endif //BSAC_DECODE

//=============================================================================================
//                  AAC PLUS DSP Decoder Control
//=============================================================================================
#if defined(AAC_PLUS_DECODE)
   #define AACPLUS_STATUS                     DP_DAF_CTRL_base(0x20) 
#endif //AAC_PLUS_DECODE

//=============================================================================================
//                  WMA DSP Decoder Control
//=============================================================================================
#if defined(WMA_DECODE)
   #define WMA_STATUS                         DP_DAF_CTRL_base(0)  // Idle/Init/Running/End
   #define WMA_DEBUG                          DP_DAF_CTRL_base(1)  // Checksum DSP status check
   #define WMA_BUFFER_LENGTH                  DP_DAF_CTRL_base(2)  // Indicate FIFO size
   #define WMA_BUFFER_BASE                    DP_DAF_CTRL_base(3)  // Indicate FIFO base
   #define WMA_BUFFER_DSP_READ                DP_DAF_CTRL_base(3)  // Indicate the next word DSP will read
   #define WMA_BUFFER_MCU_WRITE               DP_DAF_CTRL_base(4)  // Indicate the next word MCU will write
   #define WMA_NUM_CHANNELS                   DP_DAF_CTRL_base(5)
   #define WMA_SAMPLING_RATE                  DP_DAF_CTRL_base(6)
   #define WMA_VERSION_NUMBER                 DP_DAF_CTRL_base(7)
   #define WMA_BYTES_PER_SECONDS              DP_DAF_CTRL_base(8)
   #define WMA_PACKET_LENGTH                  DP_DAF_CTRL_base(0x20) //DPRAM2_base(0x22F)
   #define WMA_ENCODE_OPT                     DP_DAF_CTRL_base(0x21) //DPRAM2_base(0x230) (Encode Option)
   #define WMA_Soft_Reset                     DP_DAF_CTRL_base(0x29) //DPRAM2_base(0x0238)
   #define WMA_TOTAL_FRAME                    DP_DAF_CTRL_base(0x2A) //DPRAM2_base(0x0239)
#endif //WMA_DECODE

//=============================================================================================
//                  COOK DSP Decoder Control
//=============================================================================================

   #define COOK_MAIN_CONTROL                  DP_DAF_CTRL_base(0)
   #define COOK_SHERIF_PARAM_1                DP_DAF_CTRL_base(1)
   #define COOK_SHERIF_PARAM_2                DP_DAF_CTRL_base(2)  
   #define COOK_SHERIF_PARAM_3                DP_DAF_CTRL_base(3) 
   #define COOK_SHERIF_PARAM_4                DP_DAF_CTRL_base(4)  //for debug usage

//=============================================================================================
//                  MIDI DSP Synthesizer Control
//=============================================================================================
#if defined(DSP_WT_SYN)
   #define DP_WT_CTRL                         (*DP_WT_CTRL_base(0))
   #define DP_WT_EVT_COUNT                    (*DP_WT_CTRL_base(23))
   #define DP_WT_EFFECT                       (*DP_WT_CTRL_base(3))
   #define DP_WT_VOLUME                       (*DP_WT_CTRL_base(18))
   #define DP_WT_VOLUME2                      (*DP_WT_CTRL_base(19))
   #define DP_WT_ADDR_LO                      (*DP_WT_CTRL_base(12))
   #define DP_WT_ADDR_HI                      (*DP_WT_CTRL_base(13))
   #define DP_WT_INST_VOL_LO                  (*DP_WT_CTRL_base(14))
   #define DP_WT_INST_VOL_HI                  (*DP_WT_CTRL_base(15))
   #define DP_WT_EQPARA_LO                    (*DP_WT_CTRL_base(16))
   #define DP_WT_EQPARA_HI                    (*DP_WT_CTRL_base(17))
   #define DP_WT_RTMIDI_ADDR_LO               (*DP_WT_CTRL_base(20))
   #define DP_WT_RTMIDI_ADDR_HI               (*DP_WT_CTRL_base(21))
   #define DP_WT_RESET_CTRLR                  (*DP_WT_CTRL_base(22))
   #define DSP_WAV_PLAYEDINDEX(n)             (*DP_WT_CTRL_base(4+2*(n)))
#endif //DSP_WT_SYN

//=============================================================================================
//                  AMR/AWB DSP Decoder Control
//=============================================================================================
   #define AMR_AWB_AUDIO_PATH_CTRL            DP_DAF_CTRL_base(0)
   #define AMR_PARAM1                         DP_DAF_CTRL_base(1)
   #define AMR_PARAM2                         DP_DAF_CTRL_base(2)

//=============================================================================================
//                  IPCOMMON DSP Control
//=============================================================================================
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   #define DP_IPS_CTRL                        DP_DAF_CTRL_base(0)
   #define DP_IPS_KEY                         DP_DAF_CTRL_base(1)
#endif //__IPS_SUPPORT__

//=============================================================================================
//                  AUDIO Tone Control
//=============================================================================================
   #define DSP_TONE_CTRL1_AUD    DP_AUDIO_PP_CTRL_base(0x11) //DPRAM2_base(0x3DF1)
   #define DSP_TONE_CTRL2_AUD    DP_AUDIO_PP_CTRL_base(0x12) //DPRAM2_base(0x3DF2)

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       AUDIO DSP Functionalities Control Sherifs
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  DSP SLOW IDLE Control
//=============================================================================================
   #define DP_SLOW_IDLE_CTRL                  (*DPRAM2_base(DP_SLOW_IDLE_DIVIDER))

//=============================================================================================
//                  AV Sync Control
//=============================================================================================
   #define DP_A2V_INT_ENABLE                  DP_AV_SYNC_CTRL_base(0)   // State change controller
   #define DP_A2V_INT_CNT                     DP_AV_SYNC_CTRL_base(1)   // Audio interrupt count
   #define DP_A2V_INT_STAMP                   DP_AV_SYNC_CTRL_base(2)   // Time for DSP to trigger MCU for display
   #define DP_A2V_AUDIO_FRAME_COUNT           DP_AV_SYNC_CTRL_base(3)   // Audio frame count
   #define DP_A2V_VIDEO_FRAME_COUNT           DP_AV_SYNC_CTRL_base(4)   // Video frame count

/*doug rename
A2V_INT_ENABLE   DP_A2V_INT_ENABLE
A2V_INT_CNT      DP_A2V_INT_CNT
A2V_INT_STAMP    DP_A2V_INT_STAMP
A2V_AUDIO_FRAME_COUNT DP_A2V_AUDIO_FRAME_COUNT
A2V_VIDEO_FRAME_COUNT DP_A2V_VIDEO_FRAME_COUNT
*/
//=============================================================================================
//                  DC Compensation Control
//=============================================================================================
//#if (__AFE_SW_DC_COMPENSATION__)
   #define  DP_DC_COMP_CTRL                   DP_EXTRA_APPLICATION_base(0)
   #define  DP_DC_VALUE                       DP_EXTRA_APPLICATION_base(1)
   #define  DP_DC_GAIN                        DP_EXTRA_APPLICATION_base(2)
   #define  DP_DC_CTRL_01                     DP_AUDIO_PP_CTRL_base(4)
   #define  DP_DC_CTRL_02                     DP_EXTRA_APPLICATION_base(4)
   #define  DP_DC_CTRL_03                     DP_EXTRA_APPLICATION_base(5)
//#endif //__DC_COMPENSATION_SUPPORT__

//=============================================================================================
//                  Audio Low Power V2 Control
//=============================================================================================
#if defined(__AUDIO_DSP_LOWPOWER_V2__)
   #define AUDLP_D2M_COUNT                    DP_DAF_CTRL_base(0x04)
   #define AUDLP_MCUBUFF_THRESHOLD            DP_DAF_CTRL_base(0x05)
   #define AUDLP_MCUBUFF_SIZE                 DP_DAF_CTRL_base(0x06)
#endif //__AUDIO_DSP_LOWPOWER_V2__

//=============================================================================================
//                  I2S Recording Control
//=============================================================================================
   #define I2S_REC_PAGE_NUM                   DP_DAF_CTRL_base(2)
   #define I2S_REC_BUF_ADDR                   DP_DAF_CTRL_base(1)
   #define I2S_REC_BUF_LENG                   2304

#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   #define I2S_PLAYERROR_CONTROL              DP_DAF_CTRL_base(4)
   #define I2S_PLAYERROR_INFO                 DP_DAF_CTRL_base(5)
#endif

  #define I2S_HPF_CTRL                        DP_DAF_CTRL_base(3)
  
//=============================================================================================
//                  Audio Post-Processing Control
//=============================================================================================
   // MT6235/36/55/68.. support APM, except MED_MODEM is defined for Modem only load
   #define DP2_AUDIO_PP_CONTROL               DP_AUDIO_PP_CTRL_base(0)
   #define AUDIO_PP_3D_Table_Address          DP_AUDIO_PP_CTRL_base(1)
   #define DP2_AUDIO_PP_TS_SPEED              DP_AUDIO_PP_CTRL_base(2)
   #define PPED_PCM_FILLED_ACK                DP_AUDIO_PP_CTRL_base(6)
   #define DP_AUDIO_DEL_CNTR_THRESHOLD        DP_AUDIO_PP_CTRL_base(11)
   #define DSP_PCM_CGAIN                      DP_AUDIO_PP_CTRL_base(12)
   #define DSP_PCM_GAINSTEP                    DP_AUDIO_PP_CTRL_base(1)
     
#if defined(MT6252)
   #define AUD_UPPER_BOUND                    DP_AUDIO_PP_CTRL_base(7)
   #define VS_DIGI_GAIN                       DP_AUDIO_PP_CTRL_base(8)
   #define VS_CENTER_FREQ                     DP_AUDIO_PP_CTRL_base(9)
   #define VS_MOD_FREQ                        DP_AUDIO_PP_CTRL_base(10)
   #define VS_DELTA_FREQ                      DP_AUDIO_PP_CTRL_base(12)
   #define PP_IIR_COEF_BASE                   DP_AUDIO_PP_CTRL_base(13)
#endif

#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   #define AUD_VSG_CTRL                     DP_AUDIO_PP_CTRL_base(0x5)
   #define VS_MOD_FREQ                      DP_AUDIO_PP_CTRL_base(0x6)
   #define VS_CENTER_FREQ                   DP_AUDIO_PP_CTRL_base(0x7)
   #define VS_DIGI_GAIN                     DP_AUDIO_PP_CTRL_base(0x8)
#endif

   #define AUDIO_DBG_SHERIF                 DP_AUDIO_PP_CTRL_base(0x3)
   #define Audio_32k_Record_Ctrl            DP_AUDIO_PP_CTRL_base(0xc)

//rename note: AUD_UPPER_BOUND AUD_PP_UPPER_BOUND
//rename note: VS_DIGI_GAIN    AUD_PP_VS_DIGI_GAIN
//             Audio_debug_sherif1 AUDIO_DBG_SHERIF
   #define PCMRUT_BUF_PAGENUM                 DPRAM2_base(PCM_Rount_Data_Pagenum)
   #define PCMRUT_BUF_ADDR                    DPRAM2_base(PCM_Rount_Data_Address)
   #define PCMRUT_BUF_LENGTH                  DPRAM2_base(PCM_Rount_Data_Length)
   #define PCMRUT_BUF_LENGTH_I                DPRAM2_base(AUDIO_PP_TS_APM_to_DSP_Length)
   
/*
doug rename
DP2_AUDIO_PP_CTRL DP2_AUDIO_PP_CONTROL
AUDIO_PP_TS_SPEED DP2_AUDIO_PP_TS_SPEED
*/   

//=============================================================================================
//                 playback control for Audio DSP Low Power
//=============================================================================================

//for only debug
   #define DEBUG_AUDMA_PORT                   DP_DAF_CTRL_base(0x0F)
                                              
   #define MP3LP_PST_Base                     DP_DAF_CTRL_base(0x011 + 0x1)
   #define MP3LP_PST_Length                   DP_DAF_CTRL_base(0x011 + 0x2)
   #define MP3LP_DM_BsBuf_Base                DP_DAF_CTRL_base(0x011 + 0x3)
   #define MP3LP_DM_BsBuf_Length              DP_DAF_CTRL_base(0x011 + 0x4)
   #define MP3LP_Err_Return                   DP_DAF_CTRL_base(0x011 + 0x5)
                                              
   #define MP3LP_Err_Report                   DP_DAF_CTRL_base(0x011 + 0x6)
   #define MP3LP_PST_ReadPtr                  DP_DAF_CTRL_base(0x011 + 0x7)
   #define MP3LP_PST_WritePtr                 DP_DAF_CTRL_base(0x011 + 0x8)
   #define MP3LP_DM_READ_PTR                  DP_DAF_CTRL_base(0x011 + 0x9)
   #define MP3LP_DM_WRITE_PTR                 DP_DAF_CTRL_base(0x011 + 0xA)
                                              
   #define MP3LP_Config                       DP_DAF_CTRL_base(0x011 + 0xB)
    
   #define AAC_DSP_AFT_READSPECTAL            DP_DAF_CTRL_base(0x10)      
   #define AAC_DSP_AFT_SCALESPECTRAL          DP_DAF_CTRL_base(0x11)      
   #define AAC_DSP_BEF_FFT                    DP_DAF_CTRL_base(0x12)      
   #define AAC_DSP_AFT_FFT                    DP_DAF_CTRL_base(0x13)      
   #define AAC_DSP_PreviousData               DP_DAF_CTRL_base(0x14)      
   #define AAC_DSP_BEF_WIND                   DP_DAF_CTRL_base(0x15)      
   #define AAC_DSP_AFT_WIND                   DP_DAF_CTRL_base(0x16)      
   #define AAC_IO_CHKSUM_ENABLE               DP_DAF_CTRL_base(0x17)      
   #define AAC_IO_CHKSUM_VALUE                DP_DAF_CTRL_base(0x18)      
   #define DBG_IO_ENA_CHG_IMASK               DP_DAF_CTRL_base(0x19)      
   #define DBG_IO_CHG_IMASK_VALUE             DP_DAF_CTRL_base(0x1A)      
   #define AAC_Final_Checksum                 DP_DAF_CTRL_base(0x1B)  
   #define AAC_Table_Checksum                 DP_DAF_CTRL_base(0x1C)      
   #define DBG_IO_CHKSUM_SET_OUTPUT_PMPTR     DP_DYNAMIC_LOAD_base(0x3)      
   #define DBG_IO_ENA_CHKSUM_ONPM             DP_DYNAMIC_LOAD_base(0x4)      


//=============================================================================================
//                  Others
//=============================================================================================
   #define DP2_AUDIO_ASP_COMMON_FLAG_1        DP_EXTRA_APPLICATION_base(0)   //DPRAM2_base(0x3DF5)
   #define AUDIO_RAMP_DOWN_ENABLE             DP_EXTRA_APPLICATION_base(1)
   #define AUDIO_ISR_CYCLE                    DP_EXTRA_APPLICATION_base(2)
   #define DP2_AUDIO_ASP_COMMON_FLAG_2        DP_EXTRA_APPLICATION_base(3) 
   #define DP2_AUDIO_ASP_D2M_COUNT            DP_EXTRA_APPLICATION_base(4)
   #define DP2_AUDIO_ASP_TASK4_DM_HANDSHAKE   DP_EXTRA_APPLICATION_base(5)   //DPRAM2_base(0x3DFA)


// rename; AUDIO_RAMPDOWN_ENABLE AUDIO_RAMP_DOWN_ENABLE


/* -------------------------------------------------------------------------- */
/* PCM 16kHz Record                                                           */
/* -------------------------------------------------------------------------- */
#if defined(MT6235) || defined(MT6235B) || defined(MT6253) 
   #define DSP_PCM_16K_REC_ADDR   0x22F8
   #define DSP_PCM_16K_REC_PTR    0x31B4 
#elif defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   #define DSP_PCM_16K_REC_ADDR   0x0A00
   #define DSP_PCM_16K_REC_PTR    0x31B4 
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)
   #define DSP_PCM_16K_REC_ADDR   0x2ADC
   #define DSP_PCM_16K_REC_PTR    0x322D 	
#elif defined(MT6255)
   #define DSP_PCM_16K_REC_PTR    0x31FD
#elif defined(MT6250)
   #define DSP_PCM_16K_REC_PTR    0x3389
#elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   //#define DSP_PCM_16K_REC_PTR    0x3389  //speech driver owner need modified 
#elif defined(MT6256_S01)
   #define DSP_PCM_16K_REC_ADDR   0x2ADC  //just for compiling, maybe delete in 56E2DVT
   #define DSP_PCM_16K_REC_PTR    0x3380
#elif defined(MT6251)
   #define DSP_PCM_16K_REC_ADDR   0x0A00
   #define DSP_PCM_16K_REC_PTR    0x31B4
#endif




#endif //__AUDIO_DEF_H
#endif
