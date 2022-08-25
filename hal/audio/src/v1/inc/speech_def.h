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
 * speech_def.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file defines all the speech registers used in audio module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#if defined(MT6270A) || defined(MT6276) || defined(MT6573)
   #include "../../v2/inc/l1audio_def.h"
#elif defined(__SMART_PHONE_MODEM__) || defined(TK6516) || defined(MT6516)
   #include "../sp/l1audio_def.h"
#else

#ifndef __SPEECH_DEF_H
#define __SPEECH_DEF_H

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

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Feature Definitions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#if defined(__DUAL_TALK_MODEM_SUPPORT__)  
#define __BT_SUPPORT__  //In 6252 W+C project, L1Audio is the only module to use BT. In this project, no BT task won't be invoked, so we add by myself to use the setMode(BT_Earphone)
#endif

#if defined(MT6260) || defined(MT6255) || defined(MT6250) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define NEW_BLOCK_FILTER_SUPPORT
#endif

/* -------------------------------------------------------------------------- */
/* VoRTP Support Definition                                                   */
/* -------------------------------------------------------------------------- */
#define VORTP_SUPPORT (defined(__VOIP__) && ( defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)))
#define VORTP_SUPPORT_G711_G726_VAD (defined(__VOIP__) && (defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)) )
#define VORTP_G711_G726_COMPENSATE_BY_CNG (defined(__VOIP__) && (defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)) )

#if (defined(__VOIP__) && (defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)) )
#define FIRST_CODEC RTP_AUDIO_G729 | RTP_AUDIO_G7231 | \
				         RTP_AUDIO_G726_16 | RTP_AUDIO_G726_24 | RTP_AUDIO_G726_32 | RTP_AUDIO_G726_40 | \
				         RTP_AUDIO_PCMA | RTP_AUDIO_PCMU
				         
#define SECOND_CODEC RTP_AUDIO_G729 | RTP_AUDIO_G7231 | \
				         RTP_AUDIO_G726_16 | RTP_AUDIO_G726_24 | RTP_AUDIO_G726_32 | RTP_AUDIO_G726_40 | \
				         RTP_AUDIO_PCMA | RTP_AUDIO_PCMU
#endif

/* -------------------------------------------------------------------------- */
/* SBC Support Definition                                                     */
/* -------------------------------------------------------------------------- */

//---------------------------- Need to verify for 6256E2-------START
#if defined(__BT_A2DP_PROFILE__) || defined(SBC_UNIT_TEST)
#define BT_A2DP_SBC_SUPPORT ( defined(MT6260) || defined(MT6255) || defined(MT6250) || defined(MT6261) || defined(MT2501) || defined(MT2502) )

#if !BT_A2DP_SBC_SUPPORT && defined(__MTK_TARGET__)
#error Bluetooth A2DP is only supported on MT6235, MT6235B, MT6253, MT6253E, MT6253L, MT6252, MT6252H,  MT6236, MT6256_S00.
#endif
/* DSP SHERIFs about Subband Analysis, these shall be defined in so_def.h */
#endif
//---------------------------- Need to verify for 6256E2-------END

#define _SPE_FOR_TEST_SIM_ ( !defined(__L1_STANDALONE__) && ( defined(MT6268) || defined(MT6235) || defined(MT6235B) ) )

//=============================================================================================
//                  HQA relative setting
//=============================================================================================
#if defined(__HQA_AUDIO__)
   #define __HQA_AUDIO_SPEECH_ENHANCEMENT_COMMON__ 0
   #define __HQA_AUDIO_AEC_NR_DRC__ 0
   #define __HQA_AUDIO_HARDWARE_AGC__ 0
#endif

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        SPEECH SHERIF BASE ADDRESS
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
   #define DP_SP_CODEC_CTRL_base(a)             (DPRAM2_base(DP2_SP_CODEC_CTRL_BASE)           +(a))     //cache-based DSP has no DPRAM
   #define DP_SP_AUDIO_INTERFACE_CTRL_base(a)   (DPRAM2_base(DP2_SP_AUDIO_INTERFACE_CTRL_BASE) +(a))
   #define DP_SP_KT_CTRL_base(a)                (DPRAM2_base(DP2_SP_KT_CTRL_BASE)              +(a))
   #define DP_SP_8kPCM_CTRL_base(a)             (DPRAM2_base(DP2_SP_8kPCM_CTRL_BASE)           +(a))
   #define DP_SP_VM_CTRL_base(a)                (DPRAM2_base(DP2_SP_VM_CTRL_BASE)              +(a))
   #define DP_SP_CTM_base(a)                    (DPRAM2_base(DP2_SP_CTM_BASE)                  +(a))
   #define DP_SP_AEC_CTRL_base(a)               (DPRAM2_base(DP2_SP_AEC_CTRL_BASE)             +(a))
   #define DP_SP_VR_CTRL_base(a)                (DPRAM2_base(DP2_SP_VR_CTRL_BASE)              +(a))
   #define DP_SP_AUDIO_CTRL_base(a)             (DPRAM2_base(DP2_SP_AUDIO_CTRL_BASE)           +(a))
   #define DP_SP_AUDIO_ENHANCE_base(a)          (DPRAM2_base(DP2_SP_AUDIO_ENHANCE_BASE)        +(a))
   #define DP_SP_Reserve_base(a)                (DPRAM2_base(DP2_Reserve_BASE)                 +(a))
   #define DP_AWB_8K_base(a)                    (DPRAM2_base(DP2_AWB_8K_BASE)                  +(a))
   #define DP_AWB_LINK_EXTEND_base(a)           (DPRAM2_base(DP2_AWB_LINK_EXTEND_BASE)         +(a))
   #define DP_SP_SPEECH_OTHER_base(a)           (DPRAM2_base(DP_SPEECH_OTHER_BASE)             +(a))
   #define DP_SP_SPEECH_RESERVED_base(a)        (DPRAM2_base(DP_SPEECH_RESERVED_BASE)          +(a))

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        SPEECH DSP Control
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  SPEECH Control Filed
//=============================================================================================
   #define DP_SC_FLAGS           DPRAM2_base(DP_SC_ADDR)            /* speech coder enabling flag [0]            */
                                                                    /* speech decoder enable flag [1]            */
                                                                    /* speech coder reset flag [4]               */
                                                                    /* speech decoder reset flag [5]             */
                                                                    /* 1'st speech coder flag [6]                */
                                                                    /* 1'st speech decoder flag [7]              */
                                                                    /* noise suppression enabling flag [8]       */
                                                                    /* VBI PCM read reset flag [9]               */
                                                                    /* VBI PCM write reset flag [10]             */
                                                                    /* Voice Memo - Record [11]                  */
                                                                    /* Voice Memo - Playback [13:12]             */
                                                                    /* AMR Rate Control [14]                     */
                                                                    /* AMR Handover Flag [15]                    */
   #define DP_DEL_PCM_R          DPRAM2_base(DP2_DEL_PCM_R)         /* delay for the VBI PCM read                */
   #define DP_DEL_PCM_W          DPRAM2_base(DP2_DEL_PCM_W)         /* delay for the start of speech decoder     */
   #define DP_MARGIN_PCM_W       DPRAM2_base(DP2_MARGIN_PCM_W)      /* margin for the VBI PCM write [7:0]        */
                                                                    /* SID detection threshold LOW [9:8]         */
                                                                    /* SID detection threshold High [15:10]      */
   #define DP_SC_MODE            DPRAM2_base(DP2_SC_MODE)           /* CODEC type for speech decoder [7:0]       */
                                                                    /* CODEC type for speech coder [15:8]        */
   #define DP_SC_VAD             DPRAM2_base(DP2_SC_VAD)            /* VAD: FR, HR, EFR, AMR1m AMR2              */
   #define DP_SC_MUTE            DPRAM2_base(DP2_SC_MUTE)           /* speech coder muting flag [0]              */
                                                                    /* speech decoder muting flag [1]            */
                                                                    /* Nsync reset mode [4]                      */
                                                                    /* Nsync followed by ETSI/Stepmind [5]       */
                                                                    /* Nsync reset value only used in MCU [15:8] */
   #define DP_NSYNC_NOT_ETSI_C   DPRAM2_base(DP2_Nsync_Not_ETSI_C)  //? Daniel
#if defined(MT260)   
   #define DP_SC_EVLUATE_DELAY   DPRAM2_base(SPH_DEL_O)             /* DSP evaluate speech delay offset while MCU extend frame  */ //?Daniel
#else
   #define DP_SC_EVLUATE_DELAY   DP_SP_CODEC_CTRL_base(7)
#endif
   #define DP_Offset_Count       DPRAM2_base(DP2_Offset_Count)      /* Quater bits offset for Handover           */
   #define DP_NSYNC_VALUE        DPRAM2_base(DP2_Nsync_value)       /* Bsync value used in a handover            */


//=============================================================================================
//                  Audio control field  (Use Speech base)
//=============================================================================================
   #define DP_VOL_OUT_PCM          DPRAM2_base(SPH_DL_VOL)
   #define DP_AUDIO_PAR            DP_SP_AUDIO_INTERFACE_CTRL_base(1)          /* input filtering flag [0]                  */
                                                                               /* output filtring flag [1]                  */
                                                                               /* PCM samples must be sent to DAI port for BT connection [2] */
                                                                               /* PCM2WAY wb/nb Switch (0:NB/1:WB) [3]               */
                                                                               /* 16k Switch (0:DSP/1:HW) [4]               */
                                                                               /* DAI mode 0 [8]                            */
                                                                               /* DAI mode 1 [9]                            */
                                                                               /* DAI mode 2 [10]                           */
                                                                               /* DAI mode 3 [11]                           */
                                                                               /* BT cordless mode [12]                     */
                                                                               /* BT earphone mode [13]                     */
                                                                               /* speech mode [15]                          */
   #define DP_AFI_COEF_LEN         DP_SP_AUDIO_INTERFACE_CTRL_base(2)  /* length of input audio filter              */
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DP_AFI_COEF_ADD         DPRAM2_base(SPH_PM_ADDR_BKF_FLT_COEF_UL_NB) /* address of input audio filter             */
#else
   #define DP_AFI_COEF_ADD         DP_SP_AUDIO_INTERFACE_CTRL_base(3)  /* address of input audio filter             */
#endif
   #define DP_AFO_COEF_LEN         DP_SP_AUDIO_INTERFACE_CTRL_base(4)  /* length of output audio filter             */
   #define DP_VOL_IN_PCM           DP_SP_AUDIO_INTERFACE_CTRL_base(5)  /* gain on PCM input                         */
   #define DP_SIDETONE_VOL         DP_SP_AUDIO_INTERFACE_CTRL_base(6)  /* gain on side-tone                         */

//=============================================================================================
//                  Keytone & Tone
//=============================================================================================
   #define DSP_TONE_CTRL1        (DPRAM2_base(KEYTONE1_CTRL))      //(*DP_SP_KT_CTRL_base(0))
   #define DSP_TONE_CTRL2        (DPRAM2_base(KEYTONE2_CTRL))
   #define DSP_TONE_FORCE_KT_8K  (*DPRAM2_base(DP_ASP_FORCE_KT_8K))   //(*DP_SP_KT_CTRL_base(2))
   #define DSP_TONE_F1A          (*DPRAM2_base(KEYTONE1_FREQ))
   #define DSP_TONE_F1B          (*DPRAM2_base( (KEYTONE1_FREQ+1) ) )
   #define DSP_TONE_AMP1         (*DPRAM2_base( (KEYTONE1_FREQ+2) ) )
   #define DSP_TONE_F2A          (*DPRAM2_base(KEYTONE2_FREQ))
   #define DSP_TONE_F2B          (*DPRAM2_base( (KEYTONE2_FREQ+1) ) )
   #define DSP_TONE_AMP2         (*DPRAM2_base( (KEYTONE2_FREQ+2) ) )
   #define DP_KT_ATT             (*DPRAM2_base(DP_KEYTONE_ATT_GAIN))  //(*DP_SP_KT_CTRL_base(9))

//=============================================================================================
//                  Voice Memo
//=============================================================================================
   #define DSP_SD1_VM_0          DPRAM2_base(SPH_AP_SD_DATA_HDR)        /* SID indicator [2:1] & TAF[3] & BFI[5]     */
   #define DSP_SD1_VM_1          DPRAM2_base(SPH_AP_SD_DATA_HB)         /* information bits d[15:0]                  */
   #define DSP_SD1_VM_17         DPRAM2_base(SPH_AP_SD_DATA_HB+16)      /* information bits d[275:260]               */
   #define DSP_SD2_VM_0          DPRAM2_base(SPH_AP_SE_DATA_HDR)        /* SP flag [1]                               */
   #define DSP_SD2_VM_1          DPRAM2_base(SPH_AP_SE_DATA_HB)         /* information bits d[15:0]                  */
   #define DSP_SD2_VM_17         DPRAM2_base(SPH_AP_SE_DATA_HB+16)      /* information bits d[275:260]               */
   #define DSP_RX_TCH_S(m, n)    ((DPRAMADDR)(DP_SP_VM_CTRL_base(0)+(m*16+n)))
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DSP_TX_TCH_S(m, n)    ((DPRAMADDR)(DP_SP_VM_CTRL_base(32)+(m*16+n)))
   #define DSP_SC_TCH_MODE       DPRAM2_base(DP_Encoder_Used_Mode)
   #define DSP_SD_TCH_MODE       DPRAM2_base(DP_Decoder_Used_Mode)
   #define DSP_VM_DBG_INFO        DPRAM2_base(DP_VM_DBG_INFO)
   #define DSP_EPL_UL_ADDR1       DPRAM2_base(SPH_DM_ADDR_EPL_UL_PRE_BUF)
   #define DSP_EPL_UL_ADDR2       DPRAM2_base(SPH_DM_ADDR_EPL_UL_POS_BUF)
   #define DSP_EPL_DL_ADDR1       DPRAM2_base(SPH_DM_ADDR_EPL_DL_PRE_BUF)
   #define DSP_EPL_DL_ADDR2       DPRAM2_base(SPH_DM_ADDR_EPL_DL_POS_BUF)
   #define DSP_DUAL_MIC_ADDR      (*DPRAM2_base(SPH_DM_ADDR_SE2_PTR))
   #define DSP_EPL_BND            (*DPRAM2_base(SPH_EPL_BND))
#else
   #define DSP_TX_TCH_S(m, n)    ((DPRAMADDR)(DP_SP_VM_CTRL_base(18)+(m*16+n)))
   #define DSP_SC_TCH_MODE       DP_SP_VM_CTRL_base(0x23)
   #define DSP_SD_TCH_MODE       DP_SP_VM_CTRL_base(0x11)
#endif
   #define DSP_TX_TCH_S0_0       DPRAM2_base(SPH_2G_SE_DATA_HDR)
   #define DSP_RX_TCH_S0_0       DPRAM2_base(SPH_2G_SD_DATA_HDR)        //DP_SP_VM_CTRL_base(0x0)


#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define SPEEH_2G_SD_DATA_HDR    DPRAM2_base(SPH_2G_SD_DATA_HDR)
#define SPEEH_2G_SD_DATA_HB     DPRAM2_base(SPH_2G_SD_DATA_HB)
#endif

//=============================================================================================
//                  AMR-WB playback control  (Use Speech base)
//=============================================================================================
   #define DSP_SD1_AWB_VM_0      DPRAM2_base(DP_SD1_AWB_VM_0)    /* TX_Type [7:0] SE codec mode [15:8]    */
   #define DSP_SD1_AWB_VM_1      DPRAM2_base(DP_SD1_AWB_VM_0+1)  /* information bits d[15:0]              */
   #define DSP_SD2_AWB_VM_0      DPRAM2_base(DP_SD2_AWB_VM_0)    /* TX_Type [7:0] SE codec mode [15:8]    */
   #define DSP_SD2_AWB_VM_1      DPRAM2_base(DP_SD2_AWB_VM_0+1)  /* information bits d[15:0]              */
   #define DSP_SD2_AWB_VM_18     DPRAM2_base(DP_SD2_AWB_VM_18)   /* information bits d[303:288]           */
   #define DSP_AWB_SE_CTRL       DPRAM2_base(DP_AWB_SE_CTRL)
   #define DSP_AWB_SD_CTRL       DPRAM2_base(DP_AWB_SD_CTRL)

//=============================================================================================
//                  PCM  (Use Speech base)
//=============================================================================================
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support state machine PCM record control
   #define DSP_SPH_8K_DIS_VBI_CTRL      DPRAM2_base(SPH_8K_DIS_VBI_CTRL)    
#else   // chip compile option
   #define DSP_PCM_REC_CTRL      DPRAM2_base(DP_ASP_WAV_REC_CTRL)       //DP_SP_8kPCM_CTRL_base(0)
#endif  // chip compile option

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
    // MT6260 uses common address look-up
#else
   #define DSP_PCM_REC_ADDR      DPRAM2_base(DP_8kPCM_MIC_REC_IDX)      //DP_SP_8kPCM_CTRL_base(1)
   #define DSP_PCM_REC_LEN       DPRAM2_base(DP_8kPCM_MIC_REC_LEN)      //DP_SP_8kPCM_CTRL_base(2)
   #define DSP_PCM_REC_ADDR2     DPRAM2_base(DP_8kPCM_SPK_REC_IDX)      //DP_SP_8kPCM_CTRL_base(3)
   #define DSP_PCM_REC_LEN2      DPRAM2_base(DP_8kPCM_SPK_REC_LEN)      //DP_SP_8kPCM_CTRL_base(4)
#endif
   #define DSP_PCM_DGAIN         DPRAM2_base(AUDIO_ASP_WAV_OUT_GAIN)    //DP_SP_AUDIO_INTERFACE_CTRL_base(7)

//=============================================================================================
//                  Audio control field (Use Speech base)
//=============================================================================================
   #define DSP_AUDIO_CTRL2       DPRAM2_base(DP_AUDIO_CTRL2)
   #define DSP_AUDIO_FLEXI_CTRL  DPRAM2_base(DP_Audio_Flexi_Ctrl)
  
//=============================================================================================
//                  EC / AEC / DMNR Control Registers
//=============================================================================================
   #define DP_EC_SUPP            DPRAM2_base(DP2_EC_SUPP)
   #define DP_ES_Time_Const      DPRAM2_base(DP2_ES_Time_Const)
   #define DP_ES_Vol_Const       DPRAM2_base(DP2_ES_Vol_Const)
   #define DP_AEC_CONTROL        DPRAM2_base(DP_AEC_CTRL)  //#define DP_AEC_CTRL           DP_SP_AEC_CTRL_base(1)
   #define DP_AEC2_CONTROL       DPRAM2_base(DP_EES_CTRL)
   #define DP_DMNR_CONTROL       DPRAM2_base(DP_DMNR_CTRL) // bit[0:1] dmnr state machine
                                                     // bit[4] calibraion control,  
                                                     // bit[5] DMNR NB coef set
                                                     // bit[6] DMNR WB coef set
                                                 
   #define DP_AEC_8K_CTRL        DPRAM2_base(DP_AEC_CONTROL_WORD)
 
//=============================================================================================
//                  Gain/Coeff/Compensation
//=============================================================================================
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DP_AFI_NB_UL_COEF_ADD   DPRAM2_base(SPH_PM_ADDR_BKF_FLT_COEF_UL_NB)
   #define DP_AFI_NB_DL_COEF_ADD   DPRAM2_base(SPH_PM_ADDR_BKF_FLT_COEF_DL_NB)
   #define DP_AFI_WB_UL_COEF_ADD   DPRAM2_base(SPH_PM_ADDR_BKF_FLT_COEF_UL_WB)	
   #define DP_AFI_WB_DL_COEF_ADD   DPRAM2_base(SPH_PM_ADDR_BKF_FLT_COEF_DL_WB)
   #define DP_SIDETONE_FLT_ADDR    DPRAM2_base(SPH_PM_ADDR_ST_FLT_COEF)
   #define DP_SRC_FLT_ADDR         DPRAM2_base(SPH_PM_ADDR_SRC_FLT_COEF)
   #define DP_DigiGain_Setting               DP_SP_AUDIO_INTERFACE_CTRL_base(7)
   #define DP_Audio_FltCoeff_Addr            DP_SP_AUDIO_INTERFACE_CTRL_base(8)
   #define DP_Audio_FltCoeff_Len             DP_SP_AUDIO_INTERFACE_CTRL_base(9)
   #define DP_16k_CompenFlt_Addr             DP_SP_AUDIO_INTERFACE_CTRL_base(12)
   #define DP_16k_CompenFlt_Flag             DP_SP_AUDIO_INTERFACE_CTRL_base(13)
   #define DP_16k_CompenFlt_Len              DP_SP_AUDIO_INTERFACE_CTRL_base(14)
#else
   #define DP_DigiGain_Setting               DPRAM2_base(AUDIO_ASP_WAV_OUT_GAIN)
   #define DP_Audio_FltCoeff_Addr            DPRAM2_base(DP_Audio_Flt_Coeff_Addr)
   #define DP_Audio_FltCoeff_Len             DPRAM2_base(DP_Audio_Flt_Coeff_Len)
   #define DP_16k_CompenFlt_Addr             DPRAM2_base(DP_16k_Compen_Flt_Addr)
   #define DP_16k_CompenFlt_Flag             DPRAM2_base(DP_16k_Compen_Flt_Flag)
   #define DP_16k_CompenFlt_Len              DPRAM2_base(DP_16k_Compen_Flt_Len)
#endif   

//=============================================================================================
//                  DAF/AAC/WMA playback control  (Use Speech base)
//=============================================================================================
   #define DAF_DSP_DGAIN                     DP_DigiGain_Setting  /* Digital Gain */ 
   #define AAC_DSP_DGAIN                     DP_DigiGain_Setting
   #define WMA_DSP_DGAIN                     DP_DigiGain_Setting

//=============================================================================================
//                  Uplink Comfort noise
//=============================================================================================
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DSP_UL_COMFORT_NOISE_THRESHOLD   (DPRAM2_base(DP_UL_COMFORT_NOISE_THRESHOLD))
   #define DSP_UL_COMFORT_NOISE_SHIFT       (DPRAM2_base(DP_UL_COMFORT_NOISE_SHIFT))
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)
   #define DP_UL_COMFORT_NOISE_THRESHOLD            (DPRAM2_base(0x2CE))
   #define DP_UL_COMFORT_NOISE_SHIFT                (DPRAM2_base(0x2CF))
#else
   #define DP_UL_COMFORT_NOISE_THRESHOLD            (DPRAM2_base(0x1DF))
   #define DP_UL_COMFORT_NOISE_SHIFT                (DPRAM2_base(0x1E0))
#endif   

//=============================================================================================
//                  NR Control
//=============================================================================================
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DSP_UL_NR_CTRL                   DPRAM2_base(DP_NR_CTRL) 
   #define DSP_DL_NR_CTRL                   DPRAM2_base(DP_DL_NR_CTRL)
   #define DP_SPE_DL_DLL_ENTRY              DPRAM2_base(SPH_ENH_DL_CTRL)
#else
#define DSP_UL_NR_CTRL         DPRAM2_base(0x1CB) 
#define DSP_DL_NR_CTRL         DPRAM2_base(0x1D6)
#define DP_SPE_DL_DLL_ENTRY    DPRAM2_base(0x11E) 
#endif   
   
//=============================================================================================
//                  Enhanced Audio Control Field
//=============================================================================================
   #define DP_SBSD_CTRL                     DPRAM2_base(DP_TEST_SIM_SBSD_CTRL)
   #define E_CTRL_HRFR                      DPRAM2_base(DP_ENHANCED_AUDIO_CTRL)
   #define E_CTRL_AMREFR                    DP_SP_AUDIO_CTRL_base(4)

   #define E_CTRL_HO                        DPRAM2_base(SPH_SCH_IMPROVE_CTRL)
  
   #define DP_DEBUG_ASSERT_CTRL             (DPRAM2_base(DEBUG_ASSERT_CTRL))

//=============================================================================================
//                  Uplink WB AMR in TCH buffer
//=============================================================================================
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DP_AUDIO_16K_PAR_PATCH         DP_AWB_8K_base(0) 
   #define DP_AUDIO_16K_TX_VOL            DP_AWB_8K_base(1)    // 16K WB UpLink path digital gain
   #define DP_AUDIO_16K_RX_VOL            DP_AWB_8K_base(2)    // 16K WB DownLink path digital gain
   #define DP_AUDIO_16K_TX_FIR_LEN        DP_AWB_8K_base(4)
   #define DP_AUDIO_16K_RX_FIR_LEN        DP_AWB_8K_base(5)
   #define DP_AWB_TX_TCH_S0(n)            DP_AWB_LINK_EXTEND_base(0x0+(n))
   #define DP_AWB_TX_TCH_S17(n)           DP_AWB_LINK_EXTEND_base(0x11+(n))
   #define DP_AWB_SC_TCH_MODE             DP_AWB_LINK_EXTEND_base(0x1F)
#elif defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   #define DP_AWB_TX_TCH_S0(n)   DP_SP_VM_CTRL_base(0x35+(n))
   #define DP_AWB_TX_TCH_S17(n)  DP_SP_VM_CTRL_base(0x46+(n))
   #define DP_AWB_SC_TCH_MODE    DP_SP_VM_CTRL_base(0x54)
#endif

/* ------------------------------------------------------------------------------------------------------------------- */
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DSP_SE_BUF_PTR                   (*DPRAM2_base(SPH_DM_ADDR_SE_PTR)) 
   #define DSP_SD_BUF_PTR                   (*DPRAM2_base(SPH_DM_ADDR_SD_PTR)) 
   #define DP_TCH_PCM_REC_ENA    DPRAM2_base(SPH_PCM_REC_CTRL)          //DP_SP_8kPCM_CTRL_base(5)
#elif defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H) || defined(MT6256_S01) || defined(MT6255) || defined(MT6250)
   #define DP_TCH_UL_PTR         DP_SP_8kPCM_CTRL_base(7)
   #define DP_TCH_UL_LEN         DP_SP_8kPCM_CTRL_base(8)
   #define DP_TCH_UL_BUF_ADDR0   DP_SP_8kPCM_CTRL_base(9)
   #define DP_TCH_UL_BUF_LEN     DP_SP_8kPCM_CTRL_base(10)
   #define DP_TCH_DL_PTR         DP_SP_8kPCM_CTRL_base(11)
   #define DP_TCH_DL_LEN         DP_SP_8kPCM_CTRL_base(12)
   #define DP_TCH_DL_BUF_ADDR0   DP_SP_8kPCM_CTRL_base(13)
   #define DP_TCH_DL_BUF_LEN     DP_SP_8kPCM_CTRL_base(14)
   #define DP_TCH_PCM_REC_ENA    DP_SP_8kPCM_CTRL_base(5)
#else
   #error new DSP TCH REC address is required for new CHIPSET
#endif

//=============================================================================================
//                  Sound Effect   (Use Speech base)
//=============================================================================================
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DSP_SOUND_EFFECT_UL_ADDR         DPRAM2_base(SPH_DM_ADDR_BGS_UL_BUF)
   #define DSP_SOUND_EFFECT_DL_ADDR         DPRAM2_base(SPH_DM_ADDR_BGS_DL_BUF)
   #define DSP_SOUND_EFFECT_LEN_UL          DPRAM2_base(SPH_BGS_LEN_UL)        
   #define DSP_SOUND_EFFECT_LEN_DL          DPRAM2_base(SPH_BGS_LEN_DL)        
#else 
   #define DSP_SOUND_EFFECT_ADDR            DPRAM2_base(DP_BGS_ADDR)
   #define DSP_SOUND_EFFECT_LEN             DPRAM2_base(DP_BGS_LEN)
#endif    

   #define DSP_SOUND_EFFECT_CTRL            DPRAM2_base(SPH_BGS_CTRL)
   #define DSP_SOUND_EFFECT_SPH_STATE       DPRAM2_base(SPH_BGS_MIX)
   #define DSP_SOUND_EFFECT_UL_GAIN         DPRAM2_base(SPH_BGS_UL_GAIN)
   #define DSP_SOUND_EFFECT_DL_GAIN         DPRAM2_base(SPH_BGS_DL_GAIN) 
   #define DSP_PCM_REC_INT                  DPRAM2_base(DP_D2C_SPEECH_UL_INT)
   #define DSP_SOUND_EFFECT_INT             DPRAM2_base(DP_D2C_SPEECH_DL_INT)
   #define DSP_DEAD_INTERRUPT               DPRAM2_base(DP_DSP_DEAD_INT)
   #define DSP_UP_DOWN_SAMP_CTRL            DPRAM2_base(DP_UP_DOWN_SAMPL_CTRL)
   
//=============================================================================================
//                  CTM
//=============================================================================================
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DP_PCM_EX_CTRL                   (*DP_SP_CTM_base(2))
   #define DP_PCM_EX_PTR                    (*DP_SP_CTM_base(5))
   #define DP_PCM_EX_UL_LEN                 (*DP_SP_CTM_base(6))
   #define DP_PCM_EX_DL_LEN                 (*DP_SP_CTM_base(7))
   #define DP_CTM_CODEC_CTRL                (*DP_SP_CTM_base(3))    // 4 LSBs for DSP CTM state
   #define DP_CTM_COSIM_CONTROL             (*DP_SP_CTM_base(10))
   #define DP_BFI_FACCH_REPORT              (*DP_SP_CTM_base(4))
   #define DP_CTM_AMRCODEBOOK_GAIN_LIMIT   (*DP_SP_CTM_base(8))
   #define DP_CTM_AMRCODEBOOK_GAIN_UPDATE  (*DP_SP_CTM_base(9))
#elif defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   #define DP_PCM_EX_CTRL                   (*DPRAM2_base(0x197))
   #define DP_PCM_EX_PTR                    (*DPRAM2_base(0x19a))
   #define DP_PCM_EX_UL_LEN                 (*DPRAM2_base(0x19b))
   #define DP_PCM_EX_DL_LEN                 (*DPRAM2_base(0x19c))   
   #define DP_CTM_CODEC_CTRL                (*DPRAM2_base(0x198))    // 4 LSBs for DSP CTM state
   #define DP_CTM_COSIM_CTRL                (*DPRAM2_base(0x19F))
   #define DP_BFI_FACCH_REPORT              (*DPRAM2_base(0x199))
   #define DP_CTM_AMR_CODEBOOK_GAIN_LIMIT   (*DPRAM2_base(0x19D))
   #define DP_CTM_AMR_CODEBOOK_GAIN_UPDATE  (*DPRAM2_base(0x19E))   
#endif

//=============================================================================================
//                  8K limiter control
//=============================================================================================
   #define DP_8K_LIMITER_CTRL               DPRAM2_base(DP2_8k_SP_CTRL) //DPRAM2_base(0x01DB)
   #define DP_SCR_CTRL                      DPRAM2_base(DP2_8k_SP_CTRL) //DPRAM2_base(0x01DB)

//=============================================================================================
//                  SBC Support Definition
//=============================================================================================
   #define DP_SB_CTRL                       (*DPRAM2_base(D2_SBC_control))
   #define DP_SB_WRITE                      (*DPRAM2_base(D2_SBC_DSP_W_PTR))
   #define DP_SB_READ                       (*DPRAM2_base(D2_SBC_MCU_R_PTR))
   #define DP_SB_PARAM                      (*DPRAM2_base(D2_SBC_parameter))
   #define DP_SB_BASE                       (*DPRAM2_base(D2_SBC_Base_address))
   #define DP_SB_LENGTH                     (*DPRAM2_base(D2_SBC_buffer_length))  
   
//=============================================================================================
//                  3G Speech Sherif Address
//=============================================================================================
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DP_3G_STATE                      (DPRAM2_base(SPH_3G_CTRL))     
   #define DP_3G_UL_SC_MODE                 (DPRAM2_base(SPH_3G_SE_RATE_UPDATE))
   #define DP_3G_DL_SD_MODE                 (DPRAM2_base(SPH_3G_SD_RATE_UPDATE))
   #define DP_3G_UL_TX_TYPE                 (DPRAM2_base(DP_3G_TX_VM_0)) 
   #define DP_3G_DL_RX_TYPE                 (DPRAM2_base(DP_3G_RX_VM_0))
   #define DP_3G_UL_TX_ADDR                 (DPRAM2_base(SPH_3G_SE_DATA_HB)) 
   #define DP_3G_DL_RX_ADDR                 (DPRAM2_base(SPH_3G_SD_DATA_HB)) 
   #define DP_3G_UL_TX_MODE_REPORT          (*DPRAM2_base(DP_Encoder_Used_Mode))
   #define DP_3G_DL_RX_MODE_REPORT          (*DPRAM2_base(DP_Decoder_Used_Mode))
   #define DP_SPH_3G_SYNC                   (*DPRAM2_base(DP_SPH_3G_SYNC_FLAG))   
#elif defined(MT6256_S01) || defined(MT6255) || defined(MT6250)
   #define DP_3G_STATE                      (DPRAM2_base(DP_3G_mode)) 
   #define DP_3G_UL_SC_MODE                 (DPRAM2_base(DP_3G_SC_Type))   
   #define DP_3G_DL_SD_MODE                 (DPRAM2_base(DP_3G_SD_Type)) 
   #define DP_3G_UL_TX_TYPE                 (DPRAM2_base(DP_3G_TX_VM_0)) 
   #define DP_3G_DL_RX_TYPE                 (DPRAM2_base(DP_3G_RX_VM_0))
   #define DP_3G_UL_TX_ADDR                 (DPRAM2_base(SPH_3G_SE_DATA_HB)) 
   #define DP_3G_DL_RX_ADDR                 (DPRAM2_base(SPH_3G_SD_DATA_HB)) 
   #define DP_3G_UL_TX_MODE_REPORT          (*DP_SP_VM_CTRL_base(0x54))
   #define DP_3G_DL_RX_MODE_REPORT          (*DP_SP_VM_CTRL_base(0x42))
#else
   #define DP_3G_STATE        (DPRAM2_base(0x1FA)) 
   #define DP_3G_UL_SC_MODE   (DPRAM2_base(0x1C5))
   #define DP_3G_UL_TX_TYPE   (DPRAM2_base(0x183)) 
   #define DP_3G_UL_TX_ADDR   (DPRAM2_base(0x184)) 
   #define DP_3G_DL_SD_MODE   (DPRAM2_base(0x1C6)) 
   #define DP_3G_DL_RX_TYPE   (DPRAM2_base(0x171))
   #define DP_3G_DL_RX_ADDR   (DPRAM2_base(0x172)) 
   #define DP_3G_UL_TX_MODE_REPORT (*DPRAM2_base(0x194))
   #define DP_3G_DL_RX_MODE_REPORT (*DPRAM2_base(0x182))
#endif
   #define DP2_3G_debug_info0	(*DPRAM_base(0x1B7))
   #define DP2_3G_debug_info1	(*DPRAM_base(0x1B8))
   #define DP2_3G_debug_info7	(*DPRAM_base(0x1BE))

//=============================================================================================
//                  DSP Speech Control
//=============================================================================================
   #define DSP_SPEECH_DEBUG_MODE            (DPRAM2_base(DP2_SPEECH_DEBUG_MODE))

//=============================================================================================
//                  BlueTooth Mode Control Field (Sign-extension / linear / gain mode)
//=============================================================================================
   #define DP_BT_PATCH_CTRL                  DPRAM2_base(SPH_BT_CTRL)
   #define DP_BT_MODE_CTRL                   DPRAM2_base(SPH_BT_MODE)

   
//=============================================================================================
//                  To indicate CSD channel types
//=============================================================================================
   #define DSP_TCH_S0_FLAGS                 DPRAM2_base(DP_TCH_S0_FLAGS)

//=============================================================================================
//                  DataCard Interface
//=============================================================================================
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DSP_DACA_CTRL                     (*DPRAM2_base(SPH_DACA_CTRL))
   #define DSP_DACA_PTR_UL                    (*DP_SP_SPEECH_RESERVED_base(7)) 
   #define DSP_DACA_PTR_DL                    (*DP_SP_SPEECH_RESERVED_base(8))
   #define DSP_DACA_UL_INT                    DP_SP_SPEECH_RESERVED_base(0x9)   
   #define DSP_DACA_DL_INT                    DP_SP_SPEECH_RESERVED_base(0xa) 
#endif

//=============================================================================================
//                  TDDNC
//=============================================================================================
#if TDDNC_SUPPORT
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DP_TDDNC_CTRL                 DPRAM2_base(DP_TDNC_CTRL)
#else
   #define DP_TDDNC_CTRL                 DPRAM2_base(DP_AEC_CTRL)
#endif
#endif

//=============================================================================================
//                  DSP Interrupt
//=============================================================================================
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DSP_D2C_SPEECH_UL_INT            DPRAM2_base(DP_D2C_SPEECH_UL_INT)
   #define DSP_D2C_SPEECH_DL_INT            DPRAM2_base(DP_D2C_SPEECH_DL_INT)   
#endif  

//=============================================================================================
//                  Others
//=============================================================================================
#if defined(__CACHED_BASE_DSP__) //only MT6256_E2
   #define DSP_AGC_SW_GAIN1             DPRAM2_base(DP_AGC_SW_GAIN1) //(DPRAM2_base(0x1FE)), DMNR Calibration AGC 
   #define DSP_AGC_SW_GAIN2             DPRAM2_base(DP_AGC_SW_GAIN2) //(DPRAM2_base(0x1FF)), DMNR Calibration AGC
#endif

#define COMPEN_BLOCK_FLT_PAR            DPRAM2_base(DP2_COMPEN_BLOCK_FILTER)

#if defined(NEW_BLOCK_FILTER_SUPPORT)
#define COMPEN_BLOCK_FLT_PAR_PTR g_Compen_Blk_Flt   // For Swtich between old/new usage
#else
#define COMPEN_BLOCK_FLT_PAR_PTR DP_AUDIO_PAR       // For Swtich between old/new usage
#endif

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        SPEECH DSP Control Including DM/PM Addr Define
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  DUAL MIC Control
//=============================================================================================
#if defined(__DUAL_MIC_SUPPORT__)
   #define DSP_DUALMIC_CTRL          DPRAM2_base(SPH_DUMIC_CTRL) //(DSP_DM_ADDR(0, (0x3DA6))) //DPRAM2_base(0x2E1) //Scott101018
#endif

//=============================================================================================
//                  Speech Engineer Parameter
//=============================================================================================
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
    #define SPH_EMP_PAGE (5)
    #define DSP_SPH_EMP_ADDR    DPRAM2_base(SPH_DM_ADDR_EMP)
#else   // chip compile option
#if defined(MT6256) || defined(MT6280)
   #define SPH_EMP_PAGE (5)
   #define SPH_EMP_ADDR (0x31BE)
#elif defined(MT6255) || defined(MT6250)
   #define SPH_EMP_PAGE (5)
   #define SPH_EMP_ADDR (0x31C7)
#elif defined(MT6236) || defined(MT6236B) || defined(MT6235) || defined(MT6235B) || defined(MT6268)
   #define SPH_EMP_PAGE (2)
   #define SPH_EMP_ADDR (0x3F96)
#elif defined(MT6252) || defined(MT6252H) || defined(MT6253) || defined(MT6251) 
   #define SPH_EMP_PAGE (1)
   #define SPH_EMP_ADDR (0x3F96)
#else
   #error new DSP speech enhancement parameter address is required for new CHIPSET
#endif

#define DSP_CPARA_ADDR   (DSP_DM_ADDR(SPH_EMP_PAGE, SPH_EMP_ADDR))
#define DSP_VPARA_ADDR   (DSP_DM_ADDR(SPH_EMP_PAGE, (SPH_EMP_ADDR+8)))
#define DSP_MPARA_ADDR   (DSP_DM_ADDR(SPH_EMP_PAGE, (SPH_EMP_ADDR+12)))
#endif  // chip compile option

//=============================================================================================
//                  DSP Internal memory access
//=============================================================================================
#if defined(MT6256) || defined(TK6280) || defined(MT6280)
   #define DSP_IN_FIR_COEFF_IN_ADDR    0x0223 
   #define DSP_OUT_FIR_COEFF_OUT_ADDR  0x0250 
#elif defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DSP_IN_FIR_COEFF_IN_ADDR    0x018B 
   #define DSP_OUT_FIR_COEFF_OUT_ADDR  0x01B8 
#elif defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6251) || defined(MT6252) || defined(MT6252H)
   #define DSP_IN_FIR_COEFF_IN_ADDR    0x3F4A
   #define DSP_OUT_FIR_COEFF_OUT_ADDR  0x3F77
#else
   #error new DSP FIR address is required for new CHIPSET
#endif

//=============================================================================================
//                  AudioPlayback Via BT SCO link address and control
//=============================================================================================
#define DP_AUDIO_VIA_8KBT_CTRL              DPRAM2_base(DP2_AUDIO_VIA_BT_CTRL)
#define DP_AUDIO_VIA_8KBT_INT               DPRAM2_base(DP2_AUDIO_VIA_BT_INT)
#define DP_VSBT_CTRL                        DPRAM2_base(DP_VBI_SYNC_BT_Earphone_CTRL)

#if defined(MT6256) || defined(MT6255) || defined(MT6250)
   #if defined(MT6256_S01)
   #define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x337F
   #elif defined(MT6255)
   #define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x31FC
   #elif defined(MT6250)
   #define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x3388
   #endif
   #define BT_AUDIO_PLAYBACK_SD_ADDR        0x3200
   #define BT_AUDIO_PLAYBACK_SD_BUF_LEN     320
   #define BT_AUDIO_PLAYBACK_SD_PAGE_NUM    5
#elif defined(MT6235) || defined(MT6235B)
   #define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x3928
   #define BT_AUDIO_PLAYBACK_SD_ADDR        0x3600
   #define BT_AUDIO_PLAYBACK_SD_BUF_LEN     320
   #define BT_AUDIO_PLAYBACK_SD_PAGE_NUM    2
#elif defined(MT6253) 
   #define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x3846
   #define BT_AUDIO_PLAYBACK_SD_ADDR        0x3600
   #define BT_AUDIO_PLAYBACK_SD_BUF_LEN     320
   #define BT_AUDIO_PLAYBACK_SD_PAGE_NUM    2
#elif defined(MT6252) || defined(MT6252H)
   #define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x3841
   #define BT_AUDIO_PLAYBACK_SD_ADDR        0x3600
   #define BT_AUDIO_PLAYBACK_SD_BUF_LEN     320
   #define BT_AUDIO_PLAYBACK_SD_PAGE_NUM    2
#elif defined(MT6236) || defined(MT6236B) || defined(MT6268)
   #define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x39BC
   #define BT_AUDIO_PLAYBACK_SD_ADDR        0x3600
   #define BT_AUDIO_PLAYBACK_SD_BUF_LEN     320
   #define BT_AUDIO_PLAYBACK_SD_PAGE_NUM    2
#elif defined(MT6251)
   #define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x3847
   #define BT_AUDIO_PLAYBACK_SD_ADDR        0x3600
   #define BT_AUDIO_PLAYBACK_SD_BUF_LEN     320
   #define BT_AUDIO_PLAYBACK_SD_PAGE_NUM    1
#endif   

//=============================================================================================
//                  DSP AGC control
//=============================================================================================
   #define DSP_AGC_CTRL                    (DPRAM2_base(DP2_AGC_CTRL))
   #define DSP_AGC_GAIN                    (DPRAM2_base(DP2_AGC_GAIN))

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define FLTCOEF_TYPE_AGC_ADDR       0x11A
// AGC Table is ROM in MT6260 DSP
#elif defined(MT6256)
   #define PM_AGC_TABLE_PAGE        0x2
   #define PM_AGC_TABLE_ADDR        0x0159
#elif defined(MT6255) || defined(MT6250)
   #define PM_AGC_TABLE_PAGE        0x3
   #define PM_AGC_TABLE_ADDR        0x0159
#elif defined(MT6252) || defined(MT6252H) || defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6251)
   #define DM_AGC_PARAMETER_PAGE    0x2
   #define DM_AGC_PARAMETER_ADDR    0x321D
#elif defined(MT6236) || defined(MT6236B) || defined(MT6268)
   #define DM_AGC_PARAMETER_PAGE    0x2
   #define DM_AGC_PARAMETER_ADDR    0x329A
#endif

//=============================================================================================
//                  DSP adapt voice analog gain
//=============================================================================================
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DP2_ADAPT_VOL_INT        DP_SP_AUDIO_INTERFACE_CTRL_base(16)
   #define DP2_ADAPT_VOL            DP_SP_AUDIO_INTERFACE_CTRL_base(17)
#elif defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6516) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6251)
   #define DP2_ADAPT_VOL_INT        DPRAM2_base(0x29C)
   #define DP2_ADAPT_VOL            DPRAM2_base(0x29D)
#elif defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   #define DP2_ADAPT_VOL_INT        DPRAM2_base(0x33E)
   #define DP2_ADAPT_VOL            DPRAM2_base(0x33F)
#else
   #define DP2_ADAPT_VOL_INT        DPRAM_base(0x2E3)
   #define DP2_ADAPT_VOL            DPRAM_base(0x2E4)
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DSP_SPH_APP_MODE                  (*DPRAM2_base(SPH_APP_MODE))	 
   #define DSP_SPH_VOLTE_JBM_CTRL            (*DPRAM2_base(SPH_VOLTE_JBM_CTRL))	
#endif

//=============================================================================================
//                  Others
//=============================================================================================
#if defined(MT6250) || defined(MT6255) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   #define DSP_GSM_MODE             DSP_DM_ADDR(0, 0x38E3)
#else
   #define LOGI_CHANNEL_BASE             0x0051
   #define DSP_GSM_MODE             ((DPRAMADDR)(DPRAM_CPU_base+(LOGI_CHANNEL_BASE+0x000)*2))
#endif

#define DSP_16K_SIDETONE_SUPPORT ( defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) )

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define DSP_PCM_FRM_PEAK_UL     DPRAM2_base(SPH_PCM_FRM_PEAK_UL)
#define DSP_PCM_FRM_PEAK_DL     DPRAM2_base(SPH_PCM_FRM_PEAK_DL)
#endif  // chip compile option

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define DSP_IID_SPEECH_UL_ID    1
#define DSP_IID_SPEECH_DL_ID    2
#define DSP_SPH_D2C_UL_INT					DPRAM2_base(DP_D2C_SPEECH_UL_INT)
#define DSP_SPH_D2C_DL_INT					DPRAM2_base(DP_D2C_SPEECH_DL_INT)
#define DSP_SPH_PNW_CTRL_UL                 DPRAM2_base(SPH_PNW_CTRL_UL)
#define DSP_SPH_PNW_CTRL_DL                 DPRAM2_base(SPH_PNW_CTRL_DL)
#define DSP_SPH_UL_COMFORT_NOISE_THRESHOLD  DPRAM2_base(DP_UL_COMFORT_NOISE_THRESHOLD)
#define DSP_SPH_UL_COMFORT_NOISE_SHIFT      DPRAM2_base(DP_UL_COMFORT_NOISE_SHIFT)
#define DSP_SPH_ENH_DL_CTRL                 DPRAM2_base(SPH_ENH_DL_CTRL)
#define DSP_SPH_ENH_UL_CTRL                 DPRAM2_base(SPH_ENH_UL_CTRL)
#define DSP_SPH_SE_BUF_PTR				    DPRAM2_base(SPH_DM_ADDR_SE_PTR)
#define DSP_SPH_SD_BUF_PTR				    DPRAM2_base(SPH_DM_ADDR_SD_PTR)
#define DSP_SPH_SE2_BUF_PTR				    DPRAM2_base(SPH_DM_ADDR_SE2_PTR)
#define DSP_SPH_DACA_CTRL                   DPRAM2_base(SPH_DACA_CTRL)
#define DSP_SPH_DACA_LEN_UL                 DPRAM2_base(SPH_DACA_LEN_UL)
#define DSP_SPH_DACA_LEN_DL                 DPRAM2_base(SPH_DACA_LEN_DL)
#define DSP_SPH_PNW_BUF_UL1				    DPRAM2_base(SPH_DM_ADDR_PNW_UL1_BUF)
#define DSP_SPH_PNW_BUF_UL2				    DPRAM2_base(SPH_DM_ADDR_PNW_UL2_BUF)
#define DSP_SPH_PNW_BUF_DL1				    DPRAM2_base(SPH_DM_ADDR_PNW_DL1_BUF)
#define DSP_SPH_PNW_BUF_DL2				    DPRAM2_base(SPH_DM_ADDR_PNW_DL2_BUF)
#define DSP_SPH_DACA_UL_BUF				    DPRAM2_base(SPH_DM_ADDR_DACA_UL_BUF)
#define DSP_SPH_DACA_DL_BUF				    DPRAM2_base(SPH_DM_ADDR_DACA_DL_BUF)
#define DSP_SPH_PNW_LEN_UL				    DPRAM2_base(SPH_PNW_LEN_UL)
#define DSP_SPH_PNW_LEN_DL				    DPRAM2_base(SPH_PNW_LEN_DL)

#if defined(MT6261) || defined(MT2501) || defined(MT2502)
#define DSP_SPH_BAND_FLAG				        DSP_DM_ADDR(5, 0x372A)
#elif defined(MT6260)
#define DSP_SPH_BAND_FLAG               DSP_DM_ADDR(5, 0x370B)
#endif
#define DSP_SPH_FLT_COEF_ADDR_ST		    DPRAM2_base(SPH_PM_ADDR_ST_FLT_COEF)
#define DSP_SPH_FLT_COEF_ADDR_BKF_NB_UL	    DPRAM2_base(SPH_PM_ADDR_BKF_FLT_COEF_UL_NB)
#define DSP_SPH_FLT_COEF_ADDR_BKF_NB_DL	    DPRAM2_base(SPH_PM_ADDR_BKF_FLT_COEF_DL_NB)
#define DSP_SPH_FLT_COEF_ADDR_SRC		    DPRAM2_base(SPH_PM_ADDR_SRC_FLT_COEF)
#define DSP_SPH_SCH_IMPROVE_CTRL 		    DPRAM2_base(SPH_SCH_IMPROVE_CTRL)
#define DSP_SPH_2G_SE_DATA_HDR              DPRAM2_base(SPH_2G_SE_DATA_HDR)
#define DSP_SPH_3G_SE_DATA_HDR			    DPRAM2_base(SPH_3G_SE_DATA_HDR)
#define DSP_SPH_3G_SD_DATA_HDR			    DPRAM2_base(SPH_3G_SD_DATA_HDR)
#define DSP_SPH_COD_CTRL	                DPRAM2_base(SPH_COD_CTRL)
#define DSP_SPH_3G_CTRL					    DPRAM2_base(SPH_3G_CTRL)
#define DSP_SPH_HR_FR_CTRL 				    DPRAM2_base(DP_ENHANCED_AUDIO_CTRL)
#define DSP_SPH_8K_CTRL                     DPRAM2_base(SPH_8K_CTRL)
#define DSP_SPH_SFE_CTRL                    DPRAM2_base(SPH_SFE_CTRL)
#define DSP_SPH_COD_MODE                    DPRAM2_base(SPH_COD_MODE)
#define DSP_SPH_COD_VAD                     DPRAM2_base(DP2_SC_VAD)
#define DSP_SPH_DEL_R                       DPRAM2_base(SPH_DEL_R)
#define DSP_SPH_DEL_W                       DPRAM2_base(SPH_DEL_W)
#define DSP_SPH_DEL_M                       DPRAM2_base(SPH_DEL_M)
#define DSP_SPH_DEL_O                       DPRAM2_base(SPH_DEL_O)
#define DSP_SPH_3G_SE_RATE                  DPRAM2_base(SPH_3G_SE_RATE_UPDATE)
#define DSP_SPH_3G_SD_RATE                  DPRAM2_base(SPH_3G_SD_RATE_UPDATE)
#define DSP_SPH_Encoder_Used_Mode 		DPRAM2_base(DP_Encoder_Used_Mode)
#define DSP_SPH_Decoder_Used_Mode       DPRAM2_base(DP_Decoder_Used_Mode)
#define DSP_SPH_VM_DBG_INFO				DPRAM2_base(DP_VM_DBG_INFO)
#define DSP_SPH_2G_SD_DATA_HDR			DPRAM2_base(SPH_2G_SD_DATA_HDR)
#define DSP_SPH_2G_SE_DATA_HB			DPRAM2_base(SPH_2G_SE_DATA_HB)
#define DSP_SPH_2G_SD_DATA_HB			DPRAM2_base(SPH_2G_SD_DATA_HB)
#define DSP_SPH_3G_SE_DATA_HB			DPRAM2_base(SPH_3G_SE_DATA_HB)
#define DSP_SPH_3G_SD_DATA_HB			DPRAM2_base(SPH_3G_SD_DATA_HB)
#define DSP_SPH_EPL_UL_PRE_BUF			DPRAM2_base(SPH_DM_ADDR_EPL_UL_PRE_BUF)
#define DSP_SPH_EPL_UL_POS_BUF			DPRAM2_base(SPH_DM_ADDR_EPL_UL_POS_BUF)
#define DSP_SPH_EPL_DL_PRE_BUF			DPRAM2_base(SPH_DM_ADDR_EPL_DL_PRE_BUF)
#define DSP_SPH_EPL_DL_POS_BUF			DPRAM2_base(SPH_DM_ADDR_EPL_DL_POS_BUF)
#define DSP_SPH_EPL_BND					DPRAM2_base(SPH_EPL_BND)
#define DSP_SPH_AGC_SW_GAIN1 			DPRAM2_base(DP_AGC_SW_GAIN1)
#define DSP_SPH_AGC_SW_GAIN2 			DPRAM2_base(DP_AGC_SW_GAIN2)
#define DSP_AFE_VDSP_CON_CTRL 			DPRAM2_base(SPH_AFE_VDSP_CON_CTRL)

#define PNW_ENBLE               (1<<8)
#define DATA_SELECT_AFTER_ENH   (1<<9)  
#define USE_D2M_PATH            (1<<10)
#define USE_M2D_PATH            (1<<11)

#define SPH_APP_MODE_NONE        0
#define SPH_APP_MODE_VOIP        1
#define SPH_APP_MODE_CALL_2G     2
#define SPH_APP_MODE_CALL_3G     3
#define SPH_APP_MODE_CALL_4G     4
#define SPH_APP_MODE_AVS         5
#define SPH_APP_MODE_PCM_ROUNTER 6
#define SPH_APP_MODE_PCM_OTHER   7

#define PSEUDO_SAL_APP_TYPE_2GCall 0
#define PSEUDO_SAL_APP_TYPE_3GCall 1
#define PSEUDO_SAL_FLTCOEFLEN_SIDETONE  31
#define PSEUDO_SAL_FLTCOEFLEN_BKF_NB 	45
#define PSEUDO_SAL_FLTCOEFLEN_BKF_WB 	90
#define PSEUDO_SAL_FLTCOEFLEN_SRC 		82
#define PSEUDO_SAL_FLTCOEFLEN_AGC 		40
#define PSEUDO_SALI_FLTCOEF_TYPE_SIDETONE  0
#define PSEUDO_SALI_FLTCOEF_TYPE_BKF_NB_UL 1
#define PSEUDO_SALI_FLTCOEF_TYPE_BKF_NB_DL 2
#define PSEUDO_SALI_FLTCOEF_TYPE_BKF_WB_UL 3
#define PSEUDO_SALI_FLTCOEF_TYPE_BKF_WB_DL 4
#define PSEUDO_SALI_FLTCOEF_TYPE_SRC       5
#define PSEUDO_SALI_FLTCOEF_TYPE_AGC       6
#define PSEUDO_SALI_FLTCOEF_TYPE_DMNR_NB   7
#define PSEUDO_SALI_FLTCOEF_TYPE_DMNR_WB   8
#define PSEUDO_SAL_3G_RX_SPEECH_GOOD  0
#define PSEUDO_SAL_3G_RX_SPEECH_BAD   4
#define PSEUDO_SAL_3G_RX_SID_FIRST    6
#define PSEUDO_SAL_3G_RX_SID_UPDATE   8
#define PSEUDO_SAL_3G_RX_SID_BAD      10
#define PSEUDO_SAL_3G_RX_NO_DATA      14
#define PSEUDO_SAL_DSPINT_PRIO_REC_EPL  1   //uplink
#define PSEUDO_SAL_DSPINT_PRIO_REC_PCM  2   //uplink
#define PSEUDO_SAL_DSPINT_PRIO_REC_VM   3   //downlink
#define PSEUDO_SAL_DSPINT_PRIO_3G_DL    4
#define PSEUDO_SAL_DSPINT_PRIO_3G_UL    5
#define PSEUDO_SAL_DSPINT_PRIO_PNW_DL   6
#define PSEUDO_SAL_DSPINT_PRIO_PNW_UL   7
#define PSEUDO_SAL_DSPINT_PRIO_DACA_DL  8
#define PSEUDO_SAL_DSPINT_PRIO_DACA_UL  9
#define PSEUDO_SAL_DSPINT_PRIO_BGS_DL   10  //downlink, ping pong
#define PSEUDO_SAL_DSPINT_PRIO_BGS_UL   11
#define PSEUDO_SAL_DSPINT_PRIO_AVBT     12
#define PSEUDO_SAL_DSPINT_PRIO_MAX      13
#define PSEUDO_SAL_DSPINT_ID_REC_EPL    (1 << PSEUDO_SAL_DSPINT_PRIO_REC_EPL)
#define PSEUDO_SAL_DSPINT_ID_REC_PCM    (1 << PSEUDO_SAL_DSPINT_PRIO_REC_PCM)
#define PSEUDO_SAL_DSPINT_ID_REC_VM     (1 << PSEUDO_SAL_DSPINT_PRIO_REC_VM)
#define PSEUDO_SAL_DSPINT_ID_3G_DL      (1 << PSEUDO_SAL_DSPINT_PRIO_3G_DL)
#define PSEUDO_SAL_DSPINT_ID_3G_UL      (1 << PSEUDO_SAL_DSPINT_PRIO_3G_UL)
#define PSEUDO_SAL_DSPINT_ID_PNW_DL     (1 << PSEUDO_SAL_DSPINT_PRIO_PNW_DL)
#define PSEUDO_SAL_DSPINT_ID_PNW_UL     (1 << PSEUDO_SAL_DSPINT_PRIO_PNW_UL)
#define PSEUDO_SAL_DSPINT_ID_DACA_DL    (1 << PSEUDO_SAL_DSPINT_PRIO_DACA_DL)
#define PSEUDO_SAL_DSPINT_ID_DACA_UL    (1 << PSEUDO_SAL_DSPINT_PRIO_DACA_UL)
#define PSEUDO_SAL_DSPINT_ID_BGS_DL     (1 << PSEUDO_SAL_DSPINT_PRIO_BGS_DL)
#define PSEUDO_SAL_DSPINT_ID_BGS_UL     (1 << PSEUDO_SAL_DSPINT_PRIO_BGS_UL)
#define PSEUDO_SAL_DSPINT_ID_AVBT       (1 << PSEUDO_SAL_DSPINT_PRIO_AVBT)
#define PSEUDO_SALI_PARAMETER_TYPE_COMMON 0
#define PSEUDO_SALI_PARAMETER_TYPE_MODE   1
#define PSEUDO_SALI_PARAMETER_TYPE_VOL    2

typedef enum{
	PSEUDO_SAL_PCMEX_PNW_BUF_UL1 = 0,//D2M
	PSEUDO_SAL_PCMEX_PNW_BUF_UL2,//M2D
	PSEUDO_SAL_PCMEX_PNW_BUF_DL1,//D2M
	PSEUDO_SAL_PCMEX_PNW_BUF_DL2,//M2D
	PSEUDO_SAL_PCMEX_DACA_BUF_UL,
	PSEUDO_SAL_PCMEX_DACA_BUF_DL,
	PSEUDO_SAL_PCMEX_BUF_SE,
	PSEUDO_SAL_PCMEX_BUF_SE2,//mic2
	PSEUDO_SAL_PCMEX_BUF_SD,
	PSEUDO_SAL_PCMEX_BUF_IDLE_SE
}Pseudo_Sal_PcmEx_BufId_t;

typedef enum {
    PSEUDO_SAL_PCMEX_TYPE_PNW = 0,
    PSEUDO_SAL_PCMEX_TYPE_DACA,
    PSEUDO_SAL_PCMEX_TYPE_REC_NML,
    PSEUDO_SAL_PCMEX_TYPE_REC_EPL
} Pseudo_Sal_PcmEx_Type_t;

typedef enum {
    PSEUDO_SAL_PCMEX_OFF = 0,
    PSEUDO_SAL_PCMEX_ON,
    PSEUDO_SAL_PCMEX_RDY
} Pseudo_Sal_PcmEx_State_t;

typedef enum {
    PSEUDO_SAL_PCM_NARROWBAND = 0,
    PSEUDO_SAL_PCM_WIDEBAND,
    PSEUDO_SAL_PCM_UNDEFINED
} Pseudo_Sal_PcmBand_Config_t;

typedef struct {
	bool idle;
	bool swi_on;
	
	uint16 delR;
	uint16 delW;
	uint16 delM;

	Pseudo_Sal_PcmEx_Type_t type;
	Pseudo_Sal_PcmBand_Config_t band;   // Effective only if idle is true

	// For PNW
	bool UL_M2D_on;
	bool UL_D2M_on;
	bool UL_is_after_enh;
	bool DL_M2D_on;
	bool DL_D2M_on;
	bool DL_is_after_enh;
} Pseudo_Sal_PCMEx_t;

volatile uint16* Pseudo_SAL_PcmEx_GetBuf(Pseudo_Sal_PcmEx_BufId_t id);
uint16 Pseudo_SAL_PcmEx_GetBufLen(Pseudo_Sal_PcmEx_BufId_t id);
volatile uint16* Pseudo_SAL_Sidetone_GetFltCoefAddr(void);
volatile uint16* Pseudo_SAL_BKF_GetFltCoefAddr_NB_UL(void);
volatile uint16* Pseudo_SAL_BKF_GetFltCoefAddr_NB_DL(void);
volatile uint16* Pseudo_SAL_SRC_GetFltCoefAddr(void);
volatile uint16* Pseudo_SAL_AGC_GetFltCoefAddr(void);
void Pseudo_SAL_Dsp_Sph_Init(void);
void Pseudo_SAL_Set_Sph_Nml_Mod(uint32 on);
void Pseudo_SAL_2G_Call_Open(uint32 enc_mod, uint32 dec_mod, uint32 sub_channel);
void Pseudo_SAL_3G_Call_Open(uint32 enc_mod, uint32 dec_mod, uint32 dtx, uint32 delR, uint32 delW, uint32 delM);
void Pseudo_SAL_2G_Call_Close(void);
void Pseudo_SAL_3G_Call_Close(void);
void Pseudo_SAL_3G_Upd_Enc_Cod(uint32 enc_mod);
void Pseudo_SAL_3G_Upd_Dec_Cod(uint32 dec_mod);
void Pseudo_SAL_PcmEx_Config(Pseudo_Sal_PCMEx_t *cfg);
void Pseudo_SAL_PcmEx_SetStateUL(Pseudo_Sal_PcmEx_Type_t type, Pseudo_Sal_PcmEx_State_t sta);
void Pseudo_SAL_PcmEx_SetStateDL(Pseudo_Sal_PcmEx_Type_t type, Pseudo_Sal_PcmEx_State_t sta);
bool Pseudo_SAL_PcmEx_CheckStateUL(Pseudo_Sal_PcmEx_Type_t type, Pseudo_Sal_PcmEx_State_t sta);
bool Pseudo_SAL_PcmEx_CheckStateDL(Pseudo_Sal_PcmEx_Type_t type, Pseudo_Sal_PcmEx_State_t sta);
void Pseudo_SAL_ENH_SetULPath(bool on);
void Pseudo_SAL_3G_SetDtx(bool on);
void Pseudo_SAL_3G_Set_RxType(uint16 rx_type);
bool Pseudo_SAL_DSPINT_Resolve(uint16 iid, uint32 *sph_int);
volatile uint16 *Pseudo_SAL_CommonPar_GetBuf(void);
volatile uint16 *Pseudo_SAL_ModePar_GetBuf(void);
volatile uint16 *Pseudo_SAL_VolPar_GetBuf(void);
#else   // chip compile option
// No pseudo SAL
#endif  // chip compile option

#if defined(__PCM_CLOCK_SWITCH_SUPPORT__)
void PCM_CLK_Init (void);
kal_bool PCM_CLK_Is_Enabled (void);
void PCM_CLK_Activate (void);
void PCM_CLK_Deactivate (void);
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)

#endif  //__SPEECH_DEF_H
#endif /* __SMART_PHONE_MODEM__ */
