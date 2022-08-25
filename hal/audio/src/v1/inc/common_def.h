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
 *  The common definition used in audio module.
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
 *
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

#if defined(MT6270A) || defined(MT6276) || defined(MT6573) || defined(MT6575)
   #include "../../v2/inc/l1audio_def.h"
#elif defined(__SMART_PHONE_MODEM__) || defined(TK6516) || defined(MT6516)
   #include "../sp/l1audio_def.h"
#endif

#ifndef __COMMON_DEF_H
#define __COMMON_DEF_H

#include "kal_public_api.h"
#include "reg_base.h"
#include "l1d_reg.h"

#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
#undef IDMA_LONG
#undef IDMA_SHORT
#undef IDMA_CM0
#undef IDMA_PM0
#undef IDMA_DM0
#define IDMA_LONG    IDMA2_LONG
#define IDMA_SHORT   IDMA2_SHORT
#define IDMA_CM0	   IDMA2_CM0
#define IDMA_PM0	   IDMA2_PM0
#define IDMA_DM0	   IDMA2_DM0
#endif

/* -------------------------------------------------------------------------- */
/* Data Type Definition                                                       */
/* -------------------------------------------------------------------------- */
#ifndef uint16
typedef kal_uint16   uint16;
typedef kal_int16    int16;
typedef kal_uint32   uint32;
typedef kal_int32    int32;
typedef kal_uint8    uint8;
typedef kal_int8     int8;
typedef kal_bool     bool;
#define true         (kal_bool)(1==1)
#define false        (kal_bool)(1==0)
#endif

/* -------------------------------------------------------------------------- */
/* DSP Share Registers                                                        */
/* -------------------------------------------------------------------------- */
#if defined(MT6256_S01) || defined(MT6255)
#define SHARE_DSPCON    ((APBADDR)(SHAREG_base+0x0000))      /* DSP Control Register                      */
#define SHARE_M2DI1     ((APBADDR)(SHAREG_base+0x0004))      /* MCU-to-DSP Interrupt1 Register            */
#define SHARE_M2DI2     ((APBADDR)(SHAREG_base+0x0008))      /* MCU-to-DSP Interrupt2 Register            */
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6251)
#define SHARE_DSPCON    ((APBADDR)(SHAREG1_base+0x0000))     /* DSP Control Register                      */
#define SHARE_M2DI1     ((APBADDR)(SHAREG1_base+0x0004))     /* MCU-to-DSP Interrupt1 Register            */
#define SHARE_M2DI2     ((APBADDR)(SHAREG1_base+0x0008))     /* MCU-to-DSP Interrupt2 Register            */
#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define SHARE_DSPCON    ((APBADDR)(SHAREG2_base+0x0000))     /* DSP Control Register                      */
#define SHARE_M2DI1     ((APBADDR)(SHAREG2_base+0x0004))     /* MCU-to-DSP Interrupt1 Register            */
#define SHARE_M2DI2     ((APBADDR)(SHAREG2_base+0x0008))     /* MCU-to-DSP Interrupt2 Register            */
#else
#define SHARE_DSPCON    ((APBADDR)(SHARE_base+0x0000))       /* DSP Control Register                      */
#define SHARE_M2DI1     ((APBADDR)(SHARE_base+0x0004))       /* MCU-to-DSP Interrupt1 Register            */
#define SHARE_M2DI2     ((APBADDR)(SHARE_base+0x0008))       /* MCU-to-DSP Interrupt2 Register            */
#endif

#define SHARE_D2MCON    ((APBADDR)(SHARE_base+0x000C))       /* DSP-to-MCU Interrupt Control Register     */
#define SHARE_D2MSTA    ((APBADDR)(SHARE_base+0x0010))       /* DSP-to-MCU Interrupt Status Register      */
#define SHARE_D2MTID    ((APBADDR)(SHARE_base+0x0014))       /* DSP Task Identification Register          */


#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define SHARE2_M2DI1     SHARE_M2DI1                          /* MCU-to-DSP Interrupt1 Register            */
#define SHARE2_M2DI2     SHARE_M2DI2                          /* MCU-to-DSP Interrupt2 Register            */
#define SHARE2_D2MCON    SHARE_D2MCON                         /* DSP-to-MCU Interrupt Control Register     */
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6251)
/*  For Slave DSP  */
#define SHARE2_DSPCON   ((APBADDR)(SHAREG2_base+0x0000))      /* DSP Control Register                      */
#define SHARE2_M2DI1    ((APBADDR)(SHAREG2_base+0x0004))      /* MCU-to-DSP Interrupt1 Register            */
#define SHARE2_M2DI2    ((APBADDR)(SHAREG2_base+0x0008))      /* MCU-to-DSP Interrupt2 Register            */
#define SHARE2_D2MCON   ((APBADDR)(SHARE2_base+0x000C))      /* DSP-to-MCU Interrupt Control Register     */
#define SHARE2_D2MSTA   ((APBADDR)(SHARE2_base+0x0010))      /* DSP-to-MCU Interrupt Status Register      */
#define SHARE2_D2MTID   ((APBADDR)(SHARE2_base+0x0014))      /* DSP Task Identification Register          */
#elif defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
/*  For Slave DSP  */
#define SHARE2_DSPCON   ((APBADDR)(SHARE2_base+0x0000))      /* DSP Control Register                      */
#define SHARE2_M2DI1    ((APBADDR)(SHARE2_base+0x0004))      /* MCU-to-DSP Interrupt1 Register            */
#define SHARE2_M2DI2    ((APBADDR)(SHARE2_base+0x0008))      /* MCU-to-DSP Interrupt2 Register            */
#define SHARE2_D2MCON   ((APBADDR)(SHARE2_base+0x000C))      /* DSP-to-MCU Interrupt Control Register     */
#define SHARE2_D2MSTA   ((APBADDR)(SHARE2_base+0x0010))      /* DSP-to-MCU Interrupt Status Register      */
#define SHARE2_D2MTID   ((APBADDR)(SHARE2_base+0x0014))      /* DSP Task Identification Register          */
#endif

/* -------------------------------------------------------------------------- */
/* DSP to CPU interrupts fields                                               */
/* -------------------------------------------------------------------------- */
#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
#define DP2_D2C_TASK0            DPRAM2_base(0)         /* 1st FW tsk interrupt                      */
#define DP2_D2C_TASK1            DPRAM2_base(1)         /* 2nd FW tsk interrupt                      */
#define DP2_D2C_TASK2            DPRAM2_base(2)         /* 3rd FW tsk interrupt                      */
#define DP2_D2C_TASK3            DPRAM2_base(3)         /* 4th FW tsk interrupt                      */
#define DP2_D2C_TASK4            DPRAM2_base(4)         /* 5th FW tsk interrupt                      */
#define DP2_D2C_TASK5            DPRAM2_base(5)         /* 6th FW tsk interrupt                      */
#define DP2_D2C_TASK6            DPRAM2_base(6)         /* 7th FW tsk interrupt                      */
#define DP2_D2C_TASK7            DPRAM2_base(7)         /* 8th FW tsk interrupt                      */
#endif

#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
#define DP_D2C_TASK0            DP2_D2C_TASK0         /* 1st FW tsk interrupt                      */
#define DP_D2C_TASK1            DP2_D2C_TASK1         /* 2nd FW tsk interrupt                      */
#define DP_D2C_TASK2            DP2_D2C_TASK2         /* 3rd FW tsk interrupt                      */
#define DP_D2C_TASK3            DP2_D2C_TASK3         /* 4th FW tsk interrupt                      */
#define DP_D2C_TASK4            DP2_D2C_TASK4         /* 5th FW tsk interrupt                      */
#define DP_D2C_TASK5            DP2_D2C_TASK5         /* 6th FW tsk interrupt                      */
#define DP_D2C_TASK6            DP2_D2C_TASK6         /* 7th FW tsk interrupt                      */
#define DP_D2C_TASK7            DP2_D2C_TASK7         /* 8th FW tsk interrupt                      */
#endif

/* -------------------------------------------------------------------------- */
/* Internal definition of audio module                                        */
/* -------------------------------------------------------------------------- */
// For MT6251, we limit the DAF buffer size and its functionality.
#if defined(MT6251)
//   #define __REDUCE_DAF_BUFFER__
#endif

#if defined(MT6268) || defined(MT6235) || defined(MT6235B)
#define USE_EXT_AMPLIFIER
#endif

#define __CTIRQ_SLEEP_PLATFORM__ ( defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) )
#if ((defined(MT6255) || defined(MT6250) || defined(MT6260)|| defined(MT6261) || defined(MT2501) || defined(MT2502)) && defined(__FMRADIO_I2S_SUPPORT__)) 
#define __INTERAL_FM_VIA_I2S__
#endif

#if defined(MT6251) || defined(MT6256_S00) || defined(MT6256_S01) || defined(MT6255)
#define __I2S_FOC_SUPPORT__ //for I2S slave mode
#endif

#define BESLOUDNESS_I2S_MODE_LOUDSPEAKER 0x1E
#define BESLOUDNESS_I2S_MODE_EARPHONE    0x1F

/* For Audio AMR runs speech path*/
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define AUDIO_AMR_RUNS_SPPECH_PATH_ON
#endif
#define I2S_FILTER_SUPPORT ( defined(MT6255) )

//if I2S_UNIT_TEST is defined, 
//press *1# for I2S_Open with sampling rate 32000
//press *2# for I2S_Open with sampling rate 44100
//press *3# for I2S_Open with sampling rate 48000
//go to recorder to record raw I2S data (stereo in PCM format)
//remove first 44 byte header for PCM raw data
//press *4# for I2S_Close

//#define __HQA_AUDIO__

//#define __I2S_UNIT_TEST__
//#define  __KARAOKE_DVT_TEST__
//#define __CVSD_LOOPBACK_TEST__

#if defined(__I2S_UNIT_TEST__) || defined(__KARAOKE_DVT_TEST__) || defined(__CVSD_LOOPBACK_TEST__)
#define KEYTONE_DEBUG 1
#endif

//#define L1AUDIO_IDMA_ALL_ADDRESS_MODE  //always use all address mode

#if defined(__BT_AUDIO_VIA_SCO__) && ( defined(MT6252) || defined(MT6253) || defined(MT6255) )
#define __AUDIO_BT_FORCE_VBI_RESET__
#endif

/* ----------------------------------------------------*/
/* Definition component DSP codec driver  [non-SWIP]   */
/* ----------------------------------------------------*/
#define AAC_DSP_COMP     (defined(MT6256_S01) || defined(MT6255) || defined(MT6250) || ( !defined(__KARAOKE_SUPPORT__) && (defined(MT6260)|| defined(MT6261) || defined(MT2501) || defined(MT2502))))
#define AMR_DSP_COMP     (defined(MT6256_S01) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
#define DAF_DSP_COMP     0
#define COOK_DSP_COMP    0

// 20100602 KH add for different driver
#if defined(MT6276) || defined(MT6573) || defined(MT6575)
   #define __DSP_CHIP_DUALMAC__
#else
   #define __DSP_CHIP_FD216__ 
#endif

//change mcu and dsp share memory to internal memory [chip after MT6256_S01]
#if defined(MT6255) || defined(MT6250) || defined(MT6260)|| defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define _DSP_INTERSHAREMEM_EN_ 
#define L1AUDIO_IDMA_ALL_ADDRESS_MODE
#endif

//Video playback MPL interface
#if !defined(__SMART_PHONE_MODEM__) && !defined(__L1_STANDALONE__) && !defined(MED_MODEM)
#define __AUDIO_STREAMING_NON_RINGBUFFER_SUPPORT__  
#endif

#define TDDNC_SUPPORT (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))

#if defined(MT6250) || (!TDDNC_SUPPORT && (defined(MT6260)|| defined(MT6261) || defined(MT2501) || defined(MT2502)))
#define _FWE_SUPPORT_
#define _BANDWIDTH_EXPENSION_SUPPORT_
#endif

#define DAF_DSP_BS_DMPATH  defined(MT6256_S00)

#define AMR_AWB_AUDIO_PATH_SUPPORT 1

#if defined(AMRWB_ENCODE)
#if defined(MT6255)
#define __AMRWB_SW_ENCODE__
#endif
#endif
// Execute AM_DSP in MED task
#define __AM_DSP_IN_TASK__ ( defined(MT6250) || defined(MT6260)|| defined(MT6261) || defined(MT2501) || defined(MT2502) )

// For 3G
#define __SP3G_PLATFORM__ ( defined(MT6268) )

// For 65nm
#define __RELOAD_DSP_COEFF__  ( defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
#define __RELOAD_HW_COEFF__  ( defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))

// For DSP-ARM separated HW
#define __DSP_WAKEUP_EVENT__ (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))

#if defined(MT6256) || defined(MT6276)
    #define MAX_AUD_EQ_BAND_NUM 20
#elif defined(MT6255)
    #define MAX_AUD_EQ_BAND_NUM 10
#elif defined(MT6252) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
    #define MAX_AUD_EQ_BAND_NUM 5
#else
    #define MAX_AUD_EQ_BAND_NUM 8
#endif

/*
                           +------- Main Feature Version
                           |+------ Sub Feature Version
                           ||+----- Bug Fix Version
                           |||
    BES_LOUDNESS_VERSION 0xABC
                           |||
            +--------------+||
            | +-------------+|
            | | +------------+
            | | |
    Version 3.9.0: 
        Remove frame delay
    Version 4.0.0: 
        Allow attack / release profile to be adjustable at the initialization stage
        Add some 2nd-order IIR filters (+1 HPF, +1 LPF, +2 BPFs)
    Version 4.1.0:
        Increase the filter coefficient precision for headphone compensation filter (HCF)
    Version 4.2.0: (Plan)
        Apply different filter to L / R channels for stereo loudspeaker
*/ 
#define BES_LOUDNESS_VERSION 0x410

#if defined(__AUDIO_COMPONENT_SUPPORT__) && !defined( MED_MODEM ) && !defined(__AUDIO_ULTRA_SLIM__)
#define __AUDIO_MIXER_SUPPORT__     
#endif

#if defined(__AUDIO_ULTRA_SLIM__)
//#define __DISABLE_BLISRC__      
#elif defined(__LOW_COST_SUPPORT_COMMON__)
//#define __DISABLE_ARBITRARY_BLISRC__
#endif

#if defined(MT6268) || defined(MT6252H) || defined(MT6252) || defined(MT6236) || defined(MT6236B) || defined(MT6256)  
#define __AUDIO_NOT_SUPPORTED__  //phased out projects
#endif 

#if (defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
// MT6250 is centralize-sleepmode, but MP already, not change
// This compile option should be enabled from MT6280,MT6583,MT6260,etc.
#define __AUDIO_POWERON_RESET_DSP__
#endif

#if ((defined(MT6261) || defined(MT2501) || defined(MT2502))&& defined(__DUAL_TALK_MODEM_SUPPORT__))
#define DSDA_VIA_PCM_INTERFACE
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// #define __PCM_CLOCK_SWITCH_SUPPORT__
#if defined (__PCM_CLOCK_SWITCH_SUPPORT__)
//  #define __PCM_CLOCK_ALWAYS_ON__ 
#endif
// #define __PCM_INTERFACE_SUPPORT__
#if defined (__PCM_INTERFACE_SUPPORT__)
  #define __BT_SUPPORT__
#endif	
#endif

/* -------------------------------------------------------------------------- */
/* Hardware Definition                                                        */
/* -------------------------------------------------------------------------- */
#define IS_EV_BOARD  (defined(MT6235_EVB) || defined(MT6253_EVB) || defined(MT6236_EVB) || defined(MT6256_S00_EVB) || defined(MT6251_EVB) || defined(MT6253E_EVB) || defined(MT6253L_EVB)|| defined(MT6252_EVB) || defined(MT6252H_EVB) )

/* -------------------------------------------------------------------------- */
/* Assertion check                                                            */
/* -------------------------------------------------------------------------- */
#define ASSERT_REBOOT(st)  EXT_ASSERT(st,0,0,0)
#define DSP_DATA_CARD_INTERFACE_SUPPORT  (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) )


// sample back prepared
#if defined(MT6261) || defined(MT2501) || defined(MT2502)
//#define CHIP_BACK_SPH_PHONE_CALL
//#define CHIP_BACK_BYPASS
#endif


#endif //__COMMON_DEF_H
