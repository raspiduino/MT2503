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
 * am.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Audio Manager(AM) for Audio Mode Changes
 *
 * Author:
 * -------
 * -------
 *
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
 *******************************************************************************/
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "l1d_data.h"
#include "string.h"
#include "media.h"
#include "l1audio_trace.h"
#include "audio_def.h"
#include "l1audio.h"
#include "afe.h"
#include "ddload.h"
#include "am.h"
#include "common_def.h"
#include "speech_def.h"
#include "afe_def.h"
#include "init.h"
#include "audio_sherif_bit_def.h"
#include "pcm4way.h"
#include "speech_enh_def.h"
#include "audcoeff_default.h"

#if defined(__BT_SUPPORT__) && !defined(__PCM_INTERFACE_SUPPORT__)
#include "bt_api.h"
#endif

#define AM_RECORD_SLEEP_TICK 40

#define AM_2G_RESYNC_THRESHOLD  1083
/* ========================================================================= */
uint32   SaveAndSetIRQMask( void );
void     RestoreIRQMask( uint32 );
int8     L1D_GetT2( void );
void     L1D_CCCDReset( void );
void     L1D_ENABLE_DTIRQ( void );
uint16   L1D_Get_Win_TQ_WRAP( void );
uint32   L1I_GetTimeStamp( void );
/* ========================================================================= */
#define  AM_STATE_KEYTONE  (1<<L1SP_KEYTONE  )
#define  AM_STATE_TONE     (1<<L1SP_TONE     )
#define  AM_STATE_SPEECH   (1<<L1SP_SPEECH   )
#define  AM_STATE_VOIP     (1<<(L1SP_MAX_AUDIO+0)   )
#define  AM_STATE_VOICE    (1<<L1SP_VOICE    )
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support DAI process
#else   // chip compile option
#define  AM_STATE_DAI      (1<<L1SP_DAI )
#endif  // chip compile option
#define  AM_STATE_AUDIO    (1<<L1SP_AUDIO )
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define  AM_STATE_SND_EFFECT  (1<<L1SP_SND_EFFECT)
#endif
#define  AM_STATE_AvBT     (1 << (L1SP_MAX_AUDIO + 1))
#define  AM_STATE_AVSYNC   (1 << (L1SP_MAX_AUDIO + 2))
#define  AM_STATE_DACA     (1 << (L1SP_MAX_AUDIO + 3))
#define  AM_STATE_AFE      (1 << (L1SP_MAX_AUDIO + 4))
#define  AM_STATE_PCMNWAY  (1 << (L1SP_MAX_AUDIO + 5))

#define AM_CONFLICT_STATE (AM_STATE_AFE + AM_STATE_SPEECH + AM_STATE_VOIP + AM_STATE_VOICE + AM_STATE_AUDIO) 

/*========  Speech State : record features in dedicated-mode speech  ========= */    
#define SP_STATE_VMR          (1 << 0)
#define SP_STATE_PCM8K_REC    (1 << 1)
#define SP_STATE_PCMNWAY      (1 << 2)
#define SP_STATE_DACA         (1 << 3)
#define SP_STATE_AFE          (1 << 4)
#define SP_STATE_VM_EPL_REC   (1 << 5)


/*========  VoIP State ======================================= */    
#define VOIP_STATE_VMR          (1 << 0)

#define VOIP_STATE_REC_ONLY_CAL (1 << 1)
#define VOIP_STATE_REC_PLAY_CAL (1 << 2)


/*=============  DSP&AFE IO types  ============================ */
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support DAI process
#define NORMAL_MODE        0
#define BT_CORDLESS_MODE   2
#define BT_EARPHONE_MODE   3
#else   // chip compile option
#define NORMAL_MODE        0
#define DAI_MODE           1
#define BT_CORDLESS_MODE   2
#define BT_EARPHONE_MODE   3
#endif  // chip compile option

/*============= low byte flags of *DP_AUDIO_PAR ============================ */
#define VOICE_INPUT_FILTER_FLAG     0x1 
#define VOICE_OUTPUT_FILTER_FLAG    0x2
#define VOICE_WB_AMR_FLAG           0x8 
#define VOICE_16K_SWITCH_FLAG       0x10                
#define VOICE_MIC_MUTE_FLAG         0x20
#if DSP_16K_SIDETONE_SUPPORT
#define VOICE_SIDETONE_FILTER_FLAG  0
#else
#define VOICE_SIDETONE_FILTER_FLAG  0x40 
#endif

#define  DSP_IO4_On()         { *SHARE2_D2MCON |= 0x10;  }
#define  DSP_IO5_On()         { *SHARE2_D2MCON |= 0x20;  }
#define  DSP_IO6_On()         { *SHARE2_D2MCON |= 0x40;  }

/* =========== Platform that DSP support upsample ========================== */
#define DSP_SUPPORT_UPSAMPLE  ( defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H) )

/* ========================================================================= */

/* To work around the bug of DSP when handover in short time,
   Do not set handover flag to DSP, but VBI_Reset and other setting remain */
#define NOT_HANDOVER_IN_SHORT_TIME

#define  VBI_Reset()          { *SHARE2_M2DI1 = 0x0838; \
                                L1Audio_Msg_VBI_RESET(); }
#define  VBI_End()            { *SHARE2_M2DI1 = 0x0839; \
                                L1Audio_Msg_VBI_END(); }

/* =========== Block Filter Switch Between old/New Usage===================== */
#if defined( NEW_BLOCK_FILTER_SUPPORT )
volatile kal_uint16 *g_Compen_Blk_Flt;
#endif

typedef struct {
   void     (*code)(kal_uint32);
   kal_uint32   data;
} AM_QFunction;

typedef enum
{
   SPH_VOICE_RECORD = 0,
   SPH_VOICE_PLAYBACK,
   SPH_VOICE_PCM2WAY_UL,
   SPH_VOICE_PCM2WAY_DL,
   SPH_TONE,
   SPH_BOTH_PATH = 0xFFFF
}  SPH_PATH_TYPE;
static struct {
#if defined( NOT_HANDOVER_IN_SHORT_TIME )
   kal_uint32    l1FN_HO;
#endif
   kal_uint16   state;
   kal_uint16   speech_mode;
   
#if defined(__BT_SUPPORT__)
   kal_uint16  bt_digital_gain;
   kal_uint16  bt_mic_gain;
#endif

#if __RELOAD_DSP_COEFF__
   kal_int16    in_coeff_tmp[45];
   kal_int16    out_coeff_tmp[45];
#endif
   kal_int16    speech_off_delay;
   kal_int16    afe_mode;

   kal_uint8    speech_state;
   kal_uint8	   voip_state;   
   kal_uint8    io_type;
   
   kal_int8     sub_channel;

   kal_bool     toneLoopbackRec;
   kal_bool     sp3g_flag;  
   kal_bool     fLoopBack;
#if defined(__AUDIO_BT_FORCE_VBI_RESET__)
   kal_bool fBTForceVBIReset;
   kal_bool fResetCount;
#endif

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   kal_bool pre_isWBLink;
#endif   

   RINGBUFFER_T(AM_QFunction,8) qfunc;
#if __SP3G_PLATFORM__
   RINGBUFFER_T(AM_QFunction,8) qfunc2;   // modem-unrelated
#endif
   SPH_PATH_TYPE DL_UL_path;
   AM_RECORD_FORMAT record_format;   
   kal_bool    afe_loopback_flag;

#if defined(__VAD_SUPPORT__)
   kal_uint16 bm_enc_mode;
   kal_uint16 bm_dec_mode;
#endif
    
#if defined(__PCM_CLOCK_SWITCH_SUPPORT__) || defined(__AUDIO_AT_CMD__)
    kal_bool pcm_clock_flag;
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)
} am;

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define IsWBLink(speech_codec) ((speech_codec) >= 0x20)
#elif defined(MT6256_S01) || defined(MT6255) || defined(MT6250)
#define IsWBLink(speech_codec) ((speech_codec) > 10)
#endif
/* --------------------------------------------------------------------------*/

//#if defined(__MT6253_AUD_DELAY_OFF_SUPPORT__) || defined(__MT6236_AUD_DELAY_OFF_SUPPORT__)
extern kal_uint8 AFE_GetAfeSate(void);
extern kal_uint8 AFE_Disable_IdleOffDelay(void);
//#endif

#if defined(MT6251) || defined(MT6256) || defined(MT6255)
extern kal_int16 AFE_GetDCOffSet(void);
#define DCOffSetRampUpSetp 3
#define DCOffSetRampDnSetp 4
#endif

#if __RELOAD_DSP_COEFF__
static void AM_ReloadDSPCoefficient( void );
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
static void am_set_cod_band(kal_bool is_WB);
#endif  // chip compile option

static void AM_Enqueue( void (*code)(uint32), uint32 data, bool isCritical )
{
   uint32 savedMask;
   AM_QFunction qf;

#if __RELOAD_DSP_COEFF__
   /* For 65nm process, MCU has to reload DSP coefficient at each wake-up */
   if (am.state == 0)
      AM_ReloadDSPCoefficient();
#else
   (void) isCritical;  // To avoid compile warning
#endif

   savedMask = SaveAndSetIRQMask();

   L1D_ENABLE_DTIRQ();

#if (__AM_DSP_IN_TASK__)
   RestoreIRQMask(savedMask);
#endif

   qf.code = code;
   qf.data = data;

#if __SP3G_PLATFORM__
   if (isCritical) {
      RB_PUT( am.qfunc, qf );
   } else {
      RB_PUT( am.qfunc2, qf );
   }
#elif __AM_DSP_IN_TASK__
   if (isCritical) {
      RB_PUT( am.qfunc, qf );
   } else {
      // Direct execute in MED task
      code( data );
   }
#else
   RB_PUT( am.qfunc, qf );
#endif

#if !(__AM_DSP_IN_TASK__)
   RestoreIRQMask(savedMask);
#endif
}

/* --------------------------------------------------------------------------*/
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
 #define AM_WriteAspParam(asp_type,asp_fs,del_w,del_m,isr_cycle,uFrameLen)   \
 {                                                                 \
    *DP_ASP_TYPE      = asp_type;                                  \
    *DP_ASP_FS        = asp_fs;                                    \
    *DP_ASP_DEL_W     = del_w;                                     \
    *DP_ASP_DEL_M     = del_m;                                     \
    *DSP_AUDIO_DEC_FRAME_LENGTH = uFrameLen;                        \
    *AUDIO_ISR_CYCLE  = isr_cycle;                                 \
    DSP_TONE_FORCE_KT_8K = 0x8000;                                 \
 }
#else
 #define AM_WriteAspParam(asp_type,asp_fs,del_w,del_m)             \
 {                                                                 \
    *DP_ASP_TYPE    = asp_type;                                    \
    *DP_ASP_FS      = asp_fs;                                      \
    *DP_ASP_DEL_W   = del_w;                                       \
    *DP_ASP_DEL_M   = del_m;                                       \
    DSP_TONE_FORCE_KT_8K = 0x8000;                                 \
 }
#endif
/* --------------------------------------------------------------------------*/

#define AM_WriteSpeechParameters( sc_flags, sc_mode, sd_mode )    \
{                                                                 \
   *DP_SC_MODE          = sd_mode | (sc_mode << 8);               \
   *DP_SC_VAD           = (sc_mode>2)? 1:0;                       \
   *DP_SC_FLAGS         = sc_flags;                               \
}

/* ========================================================================= */
const  uint16  DSP_PCM_DELAY_TABLE_SUBCH0[13][2] =
{    /*  SE      SD  */                    /*   SE  SD   */
// 2009/10/19 Daniel add for HR issue
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   { (0x00B5), 0x0139 },  /* T2 = 0 /13 */ /*  4.9 12.8  */
#else
   { (0x00B5), 0x01D9 },  /* T2 = 0 /13 */ /*  4.9 12.8  */
#endif
   { (0x0090), 0x01B4 },  /* T2 = 1 /14 */ /*  3.9 11.8  */
   { (0x006B), 0x018F },  /* T2 = 2 /15 */ /*  2.9 10.8  */
   { (0x0046), 0x016A },  /* T2 = 3 /16 */ /*  1.9  9.8  */
// 2009/10/19 Daniel add for HR issue
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   { (0x00C1), 0x0145 },  /* T2 = 4 /17 */ /*  5.2 13.1  */
#else
   { (0x00C1), 0x01E5 },  /* T2 = 4 /17 */ /*  5.2 13.1  */
#endif
   { (0x009C), 0x01C0 },  /* T2 = 5 /18 */ /*  4.2 12.1  */
   { (0x0077), 0x019B },  /* T2 = 6 /19 */ /*  3.2 11.1  */
   { (0x0052), 0x0176 },  /* T2 = 7 /20 */ /*  2.2 10.1  */
   { (0x002D), 0x0151 },  /* T2 = 8 /21 */ /*  1.2 13.5  */
   { (0x00A8), 0x01CC },  /* T2 = 9 /22 */ /*  4.5 12.5  */
   { (0x0083), 0x01A8 },  /* T2 = 10/23 */ /*  3.5 11.5  */
   { (0x005E), 0x0183 },  /* T2 = 11/24 */ /*  2.5 10.5  */
   { (0x0039), 0x015E }   /* T2 = 12/25 */ /*  1.5 13.8  */
};

const  uint16  DSP_PCM_DELAY_TABLE_SUBCH1[13][2] =
{      /*  SE      SD  */                       /*   SE  SD   */
// 2009/10/19 Daniel add for HR issue 
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   { (0x00B5)+0x25, 0x0139 },  /* T2 = 0 /13 */ /*  4.9 12.8  */
#else
   { (0x00B5)+0x25, 0x01D9 },  /* T2 = 0 /13 */ /*  4.9 12.8  */
#endif
   { (0x0090)+0x25, 0x01B4 },  /* T2 = 1 /14 */ /*  3.9 11.8  */
   { (0x006B)+0x25, 0x018F },  /* T2 = 2 /15 */ /*  2.9 10.8  */
   { (0x0046)+0x25, 0x016A },  /* T2 = 3 /16 */ /*  1.9  9.8  */
// 2009/10/19 Daniel add for HR issue
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   { (0x00C1)+0x25, 0x0145 },  /* T2 = 4 /17 */ /*  5.2 13.1  */
#else
   { (0x00C1)+0x25, 0x01E5 },  /* T2 = 4 /17 */ /*  5.2 13.1  */
#endif
   { (0x009C)+0x25, 0x01C0 },  /* T2 = 5 /18 */ /*  4.2 12.1  */
   { (0x0077)+0x25, 0x019B },  /* T2 = 6 /19 */ /*  3.2 11.1  */
   { (0x0052)+0x25, 0x0176 },  /* T2 = 7 /20 */ /*  2.2 10.1  */
   { (0x002D)+0x25, 0x0151 },  /* T2 = 8 /21 */ /*  1.2 13.5  */
   { (0x00A8)+0x25, 0x01CC },  /* T2 = 9 /22 */ /*  4.5 12.5  */
   { (0x0083)+0x25, 0x01A8 },  /* T2 = 10/23 */ /*  3.5 11.5  */
   { (0x005E)+0x25, 0x0183 },  /* T2 = 11/24 */ /*  2.5 10.5  */
   { (0x0039)+0x25, 0x015E }   /* T2 = 12/25 */ /*  1.5 13.8  */
};
/*....................................*/

#ifdef  L1D_TEST
const  uint16  DSP_PCM_DELAY_TABLE2[13][3] =
{  /*  SE             SD   */                   /*   SE   SD   */
   /*(78Mhz)-0x19=52Mhz    */
   { (0x0047)-0x19, 0x0274 },  /* T2 = 0 /13 */ /*  1.9  18.8  */
   { (0x00C2)-0x19, 0x024F },  /* T2 = 1 /14 */ /*  5.8  17.7  */
   { (0x009D)-0x19, 0x022A },  /* T2 = 2 /15 */ /*  4.7  16.6  */
   { (0x0079)-0x19, 0x02A5 },  /* T2 = 3 /16 */ /*  3.6  20.3  */
   { (0x0054)-0x19, 0x0280 },  /* T2 = 4 /17 */ /*  2.5  19.2  */
   { (0x002F)-0x19, 0x025C },  /* T2 = 5 /18 */ /*  1.4  18.1  */
   { (0x00AA)-0x19, 0x0237 },  /* T2 = 6 /19 */ /*  5.1  17.0  */
   { (0x0085)-0x19, 0x0212 },  /* T2 = 7 /20 */ /*  3.9  15.9  */
   { (0x0060)-0x19, 0x028D },  /* T2 = 8 /21 */ /*  2.8  19.5  */
   { (0x003B)-0x19, 0x0268 },  /* T2 = 9 /22 */ /*  1.7  18.4  */
   { (0x0091)-0x19, 0x0243 },  /* T2 = 10/23 */ /*  4.3  17.3  */
   { (0x006C)-0x19, 0x021E },  /* T2 = 11/24 */ /*  3.2  16.2  */
   { (0x0047)-0x19, 0x0274 }   /* T2 = 12/25 */ /*  1.9  18.8  */
};

const  uint16  DSP_WB_AMR_PCM_DELAY_TABLE2[13][3] =
{  /*  SE             SD   */                   /*   SE   SD   */
   /*(78Mhz)-0x41=52Mhz    */
   { (0x0047)-0x41, (0x0274)-0x14E },  /* T2 = 0 /13 */ /*  1.9  18.8  */
   { (0x00C2)-0x41, (0x024F)-0x14E },  /* T2 = 1 /14 */ /*  5.8  17.7  */
   { (0x009D)-0x41, (0x022A)-0x14E },  /* T2 = 2 /15 */ /*  4.7  16.6  */
   { (0x0079)-0x41, (0x02A5)-0x14E },  /* T2 = 3 /16 */ /*  3.6  20.3  */
   { (0x0054)-0x41, (0x0280)-0x14E },  /* T2 = 4 /17 */ /*  2.5  19.2  */
   { (0x002F)-0x41, (0x025C)-0x14E },  /* T2 = 5 /18 */ /*  1.4  18.1  */
   { (0x00AA)-0x41, (0x0237)-0x14E },  /* T2 = 6 /19 */ /*  5.1  17.0  */
   { (0x0085)-0x41, (0x0212)-0x14E },  /* T2 = 7 /20 */ /*  3.9  15.9  */
   { (0x0060)-0x41, (0x028D)-0x14E },  /* T2 = 8 /21 */ /*  2.8  19.5  */
   { (0x003B)-0x41, (0x0268)-0x14E },  /* T2 = 9 /22 */ /*  1.7  18.4  */
   { (0x0091)-0x41, (0x0243)-0x14E },  /* T2 = 10/23 */ /*  4.3  17.3  */
   { (0x006C)-0x41, (0x021E)-0x14E },  /* T2 = 11/24 */ /*  3.2  16.2  */
   { (0x0047)-0x41, (0x0274)-0x14E }   /* T2 = 12/25 */ /*  1.9  18.8  */
};
#endif

/*....................................*/
const  uint16  DSP_PCM_MARGIN_TABLE[] = {
   0x38+(16<<10)+(2<<8),     /* 1.2 : FR        */
   0x38+(12<<10)+(2<<8),     /* 1.2 : HR        */
   0x38+(16<<10)+(2<<8),     /* 1.2 : EFR       */   
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 12.2  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 10.2  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 7.95  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 7.4   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 6.7   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 5.9   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 5.15  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 4.75  */
#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01)
   0x96+(16<<10)+(2<<8),     /* AMR-WB 6.60     */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 8.85     */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 12.65    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 14.25    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 15.85    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 18.25    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 19.85    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 23.05    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 23.85    */
#endif
};

/*....................................*/

#ifdef  L1D_TEST
const  uint16  DSP_PCM_MARGIN_TABLE2[] = {
   0x45+(16<<10)+(2<<8),     /* 1.87 : FR       */
   0x46+(12<<10)+(2<<8),     /* 1.89 : HR       */
   0x45+(16<<10)+(2<<8),     /* 1.87 : EFR      */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 12.2 */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 10.2 */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 7.95 */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 7.4  */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 6.7  */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 5.9  */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 5.15 */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 4.75 */
#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01)
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 6.60     */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 8.85     */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 12.65    */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 14.25    */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 15.85    */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 18.25    */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 19.85    */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 23.05    */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 23.85    */
#endif
};
#endif

#ifdef __HQA_AUDIO__

const int16 Speech_All_Pass_FIR_Coeff[45] = 
   { /* All pass filter */
    32767,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0 
   };

#endif

#if DSP_SUPPORT_UPSAMPLE

/* FIR Coefficients for Upsampling */
const signed short UPSAMPLE_FIR[16] = 
{ 
    409, 1473, -4595, 11379, 23815, -1188, -1338, 1406, 
    1406, -1338, -1188, 23815, 11379, -4595, 1473, 409
};

static void AM_Write_Upsampling_Coeff(void)
{
   int I;
   const int16 *ptr;
   volatile uint16* dsp_ptr;

#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   dsp_ptr = DSP_PM_ADDR(0, 0x3F3A);
#elif defined(MT6256)
   dsp_ptr = DSP_PM_ADDR(0, 0x3FF0);
#else
   #error Need DSP guys give the Upsample FIR address
#endif

   ptr = UPSAMPLE_FIR;
   for (I=15; I>=0; I--)
      *dsp_ptr++ = *ptr++;

}
#endif

static kal_uint16 AM_Convert_Sample_Index(kal_uint16 freqInd)
{
   kal_uint16 freq;
   switch (freqInd) {
      case 0x00:  freq =  8000;  break;
      case 0x11:  freq = 11025;  break;
      case 0x12:  freq = 12000;  break;
      case 0x20:  freq = 16000;  break;
      case 0x21:  freq = 22050;  break;
      case 0x22:  freq = 24000;  break;
      case 0x40:  freq = 32000;  break;
      case 0x41:  freq = 44100;  break;
      case 0x42:  freq = 48000;  break;
      default:
         freq = 0;    // Avoid compile warning
   }
   return freq;  
}

static void AM_Write_Speech_Delay( uint16 speech_mode, int8 sub_channel, uint16 delay )
{
   uint16 n = (uint16)L1D_GetT2();

   if( n >= 13 )
      n -= 13;
#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01)
   if (speech_mode>=0x20)
      speech_mode-=(0x20-0x0B);
#endif
   ASSERT(speech_mode<(sizeof(DSP_PCM_MARGIN_TABLE)/sizeof(DSP_PCM_MARGIN_TABLE[0])));
#ifdef L1D_TEST
   if((PollLoopbackMode()==1)||(PollLoopbackMode()==2))
   {
      if ( speech_mode < 0x0B )
      {
         *DP_DEL_PCM_R     = DSP_PCM_DELAY_TABLE2[n][0];
         *DP_DEL_PCM_W     = DSP_PCM_DELAY_TABLE2[n][1];
         
      }
      else
      {
         *DP_DEL_PCM_R     = DSP_WB_AMR_PCM_DELAY_TABLE2[n][0];
         *DP_DEL_PCM_W     = DSP_WB_AMR_PCM_DELAY_TABLE2[n][1];
      }
      *DP_MARGIN_PCM_W  = DSP_PCM_MARGIN_TABLE2[speech_mode];
   }
   else
#endif
   {
      if (sub_channel == 0)
      {
         *DP_DEL_PCM_R     = DSP_PCM_DELAY_TABLE_SUBCH0[n][0];
         *DP_DEL_PCM_W     = DSP_PCM_DELAY_TABLE_SUBCH0[n][1];
      }
      else
      {
         *DP_DEL_PCM_R     = DSP_PCM_DELAY_TABLE_SUBCH1[n][0];
         *DP_DEL_PCM_W     = DSP_PCM_DELAY_TABLE_SUBCH1[n][1];
         n += 13;
      }
      L1Audio_Msg_AM_DELAY_TABLE( n );
      *DP_MARGIN_PCM_W  = DSP_PCM_MARGIN_TABLE[speech_mode];
   }
   *DP_SC_EVLUATE_DELAY = delay;
}

const  uint16  DSP_PCM_IDLE_DELAY_TABLE[7][3] =
{ 
   { 0x20, 0x20 , 0x4B+(16<<10)+(2<<8)}, // for AMR codec 
   { 0x20, 0x20 , 0x96+(16<<10)+(2<<8)}, // for speech codec except AMR 
   { 0x0A, 0x0A , 0x4F+(16<<10)+(2<<8)}, // for PCM8K_Playback.....
   { 0x0A, 0x0A , 0x28+(16<<10)+(2<<8)}, // for PCM16K  
   { 0x0A, 0x0A , 0x9F+(16<<10)+(2<<8)},  // for Keytone/Tone/ 
   { 0x0A, 0x0A , 0x96+(16<<10)+(2<<8)}, // for PCM8K_Playback/VoIP
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    { 27*8, 14*8, 0x96+(16<<10)+(2<<8)}  // for 3G Speech
#else   // chip compile option
   { 0x10, 0x100, 0x96+(16<<10)+(2<<8)}  // for 3G Speech    
#endif  // chip compile option
};

static void AM_Write_Idle_Delay( uint8 type )
{
   *DP_DEL_PCM_R        = DSP_PCM_IDLE_DELAY_TABLE[type][0];
   *DP_DEL_PCM_W        = DSP_PCM_IDLE_DELAY_TABLE[type][1];
   *DP_MARGIN_PCM_W     = DSP_PCM_IDLE_DELAY_TABLE[type][2];
   *DP_SC_EVLUATE_DELAY = 0;
}


/* Note: The speech pattern length for amr-wb can be calculated from
lenSpeechBitsAMR_WB in amr_table.h; therefore, remove them out.
Those for amr might be removed if vm.c does not handle amr any more. */
static const uint8 SpeechPatternLength[] = {
   (uint8)((260 + 15) / 16),           /*  FR       */
   (uint8)((112 + 15) / 16 + 1),       /*  HR       */
   (uint8)((244 + 15) / 16),           /* EFR       */
   (uint8)((244 + 15) / 16),           /* AMR 12.2K */
   (uint8)((204 + 15) / 16),           /* AMR 10.2K */
   (uint8)((159 + 15) / 16),           /* AMR 7.95K */
   (uint8)((148 + 15) / 16),           /* AMR 7.4K  */
   (uint8)((134 + 15) / 16),           /* AMR 6.7K  */
   (uint8)((118 + 15) / 16),           /* AMR 5.9K  */
   (uint8)((103 + 15) / 16),           /* AMR 5.15K */
   (uint8)(( 95 + 15) / 16),           /* AMR 4.75K */
#if defined(AMRWB_DECODE)
   (uint8)((132 + 15) / 16),           /* AMR-WB 6.60  */
   (uint8)((177 + 15) / 16),           /* AMR-WB 8.85  */
   (uint8)((253 + 15) / 16),           /* AMR-WB 12.65 */
   (uint8)((285 + 15) / 16),           /* AMR-WB 14.25 */
   (uint8)((317 + 15) / 16),           /* AMR-WB 15.85 */
   (uint8)((365 + 15) / 16),           /* AMR-WB 18.25 */
   (uint8)((397 + 15) / 16),           /* AMR-WB 19.85 */
   (uint8)((461 + 15) / 16),           /* AMR-WB 23.05 */
   (uint8)((477 + 15) / 16),           /* AMR-WB 23.85 */
#endif
};

bool AM_CodecMode_IsLegal(uint8 codec_mode)
{
   if (codec_mode <= 0xA) {
      return true;
   }
#if defined(AMRWB_DECODE)
   if ( (codec_mode >= 0x20) && (codec_mode <= 0x28) ) {
      return true;
   }
#endif
   return false;
}

uint16 AM_GetSpeechPatternLength( uint8 speech_mode )
{
   if( speech_mode >= 0x20 )
      speech_mode = speech_mode - 0x20 + 0x0B;
   if( speech_mode<(sizeof(SpeechPatternLength)/sizeof(SpeechPatternLength[0])))
      return (uint16)SpeechPatternLength[speech_mode];
   else
      return 0;
}

static const uint16 SpeechSilencePattern[][17] = {
   {  0x4820,0xD617,0x0284,0x2480,0x9249,0x8924,0x8002,0x4924,       /* FR       */
      0x2492,0x0289,0x2480,0x9249,0x8924,0x8002,0x4924,0x2492,
      0x0009                                                   },
   {  0x4E20,0x875E,0x5473,0x8482,0x00E9,0x0000,0x0000         },    /* HR       */
   {  0x7A10,0x092D,0xB55F,0x7C06,0x185C,0xDE06,0x4230,0x0103,       /* EFR      */
      0xA012,0x001A,0x0000,0x0000,0x0D6C,0x0000,0x0000,0x0000  },
   {  0x00e2,0x5dfc,0xf095,0xcd4e,0x24da,0x0e04,0xf0fb,0x4f2e,       /* AMR12.2  */
      0x4430,0x9fa8,0x0319,0x56c0,0xc144,0x0278,0x70ea,0x0004  },
   {  0xe00a,0xf2e7,0x516b,0x19a1,0xc10d,0x145a,0x4c96,0x25e0,       /* AMR10.2  */
      0x5ce6,0x17b9,0x0982,0x225d,0x00c4                       },
   {  0x033c,0xe5cd,0xd9fb,0x387f,0x420c,0x8c99,0x58d7,0x1156,       /* AMR7.95  */
      0x397f,0x1074                                            },
   {  0xe00a,0xf2e7,0x9ac5,0x4433,0x185b,0x3e05,0xdc64,0xc886,       /* AMR7.4   */
      0xcd2e,0x0000                                            },
   {  0xe00a,0xf2e7,0x7761,0x0486,0x0dd5,0xf47c,0x21b0,0xf547,       /* AMR6.7   */
      0x0002                                                   },
   {  0xe00a,0xf2e7,0xb196,0xa8ae,0xbcb7,0x6fb9,0x0193,0x002e  },    /* AMR5.9   */
   {  0x3c0a,0x7e51,0x652c,0x5e91,0xd023,0xea5a,0x005b         },    /* AMR5.15  */
   {  0x3c0a,0x3e51,0x6529,0x3a49,0x977f,0x3565                },    /* AMR4.75  */
#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01)
   {0xe00a,0xf2e7,0x7761,0x0486,0x0dd5,0xf47c,0x21b0,0xf547,0x0002},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000}     /* AMR-WB 6.60  */
#endif
};

void AM_GetSilencePattern(kal_uint32 mode, kal_uint16 *pData)
{
   memcpy(pData, SpeechSilencePattern[mode], 17*sizeof(uint16));
}

void AM_FillSilencePattern( volatile uint16 *addr, uint16 info, uint16 speech_mode )
{
#ifndef  L1D_TEST
   const uint16 *pat_info;
   uint32 I, len;
   if( speech_mode >= 0x20 )
      speech_mode = speech_mode - 0x20 + 0x0B;

   if( speech_mode >= (sizeof(SpeechPatternLength)/sizeof(SpeechPatternLength[0])) )
      return;

   pat_info = SpeechSilencePattern[speech_mode];
   len = (uint16)SpeechPatternLength[speech_mode];

   *addr++ = info;
   for( I = 0; I < len; I++ )
      *addr++ = *pat_info++;
#endif
}

/* -------------------------------------------------------------------------- */
bool AM_AudioManager( bool handover, uint16 speech_mode, int8 sub_channel )
{
   AM_QFunction func;

    {
        bool b2G_resync = false;
#if IS_SPEECH_RESYNC_SUPPORT
        {
            extern bool L1D_Get_Speech_Re_Sync_Flag(void);
            b2G_resync = L1D_Get_Speech_Re_Sync_Flag();
        }
#endif
        
        if (b2G_resync)
        {
            L1Audio_Msg_AM_2G_Resync(am.speech_mode, speech_mode);
        }
    }

   if (KAL_FALSE == L1Audio_IsInitiated())
      return false;

   if( speech_mode != am.speech_mode ){
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      kal_bool isWBLink = (kal_bool)IsWBLink(am.speech_mode);
      am.speech_mode = speech_mode;
      if(am.pre_isWBLink != isWBLink){
         AM_SetSRCCtrl();
         am.pre_isWBLink = isWBLink;
      }
#else
      am.speech_mode = speech_mode;
#endif
   }

   if( sub_channel != am.sub_channel )
      am.sub_channel = sub_channel;

   if( am.speech_off_delay > 0 ) {
      if( --am.speech_off_delay == 0 )
         AM_FillSilencePattern( DSP_TX_TCH_S0_0, 2, am.speech_mode );
   }

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support DAI process
    if( handover && (!am.sp3g_flag) )
#else   // chip compile option
    if( handover && (am.state & AM_STATE_DAI) == 0 && (!am.sp3g_flag) )
#endif  // chip compile option
    {
      if( am.state & AM_STATE_SPEECH ) {
         if(am.fLoopBack){   
            AM_WriteSpeechParameters(0x063a, am.speech_mode, am.speech_mode );      
         }else{
#if defined( NOT_HANDOVER_IN_SHORT_TIME )
            uint32 fn = L1I_GetTimeStamp();
            if( ( fn - am.l1FN_HO ) <= 13 )//(0x1CC / 8) / 4.615 + 1 = 12.45
            {/*do not set handover flag to work around DSP bug */
               AM_WriteSpeechParameters( (*DP_SC_FLAGS&0xF800) | 0x0633, am.speech_mode, am.speech_mode );
            } else
#endif
            AM_WriteSpeechParameters( (*DP_SC_FLAGS&0xF800) | 0x063B, am.speech_mode, am.speech_mode );
#if defined( NOT_HANDOVER_IN_SHORT_TIME )
            am.l1FN_HO = fn;
#endif
         }    
         AM_Write_Speech_Delay( am.speech_mode, am.sub_channel, L1D_Get_Win_TQ_WRAP() - TQ_WRAP_COUNT );
         AM_FillSilencePattern( DSP_TX_TCH_S0_0, 2, am.speech_mode );

         if( am.speech_mode > 2 &&  am.speech_mode <=10)
            *DSP_TX_TCH_S(0,17) = am.speech_mode << 8;
         L1Audio_Msg_AM_Handover( am.speech_mode );
#if defined(__MA_L1__)
/* under construction !*/
#endif
         VBI_Reset();
      }
      else if( !(am.state & AM_STATE_VOICE) ){      /* Not in speech mode or voice state, avoid corrupt AMR encoder memory*/
         AM_FillSilencePattern( DSP_TX_TCH_S0_0, 2, am.speech_mode );
      }
   }
   else if( !RB_EMPTY( am.qfunc ) ) {
      RB_GET( am.qfunc, func );
      func.code( func.data );
   }
#if !(__SP3G_PLATFORM__) && !(__CTIRQ_SLEEP_PLATFORM__)
   else {
      AFE_Manager();
   }
#endif

    {
#if (defined(__AUDIO_DSP_LOWPOWER__) || defined(__AUDIO_DSP_LOWPOWER_V2__))
        extern kal_bool AUDLP_Check_LowPower_Status(void);
        if (AUDLP_Check_LowPower_Status())
        {
            return (bool)0;                         //Dior modified for AUDLP
        }
        else
#endif
        {
            return (bool)(am.state != 0);
        }
    }
}

#if __SP3G_PLATFORM__
void AM_AudioManager_OS_Tick( void )
{
   uint32 savedMask;
   AM_QFunction func;

   savedMask = SaveAndSetIRQMask();
   if( !RB_EMPTY( am.qfunc2 ) ) {
      RB_GET( am.qfunc2, func );
      func.code( func.data );
   }
   else if( RB_EMPTY( am.qfunc ) ) {
      AFE_Manager();
   }
   RestoreIRQMask(savedMask);
}
#endif

void AM_FlushQFunction( void )
{
#ifndef  L1D_TEST

#if __SP3G_PLATFORM__
   while( (!RB_EMPTY(am.qfunc)) || (!RB_EMPTY(am.qfunc2)) )
      kal_sleep_task( 1 );
#else
   while( !RB_EMPTY(am.qfunc) )
      kal_sleep_task( 1 );
#endif

#endif
}

/* ========================================================================= */
/*   Interface Functions                                                     */
/* ========================================================================= */
static uint8 audio_coeff_flag = 0;
#define COMPEN_FILTER_SIZE 45

#if DSP_16K_SIDETONE_SUPPORT
const signed short Sidetone_FIR[31] = 
{ 
-4678, 11792,  407,  204,  407, -6978, 12257,  2929, -2945,  2929,
0, 0,  0,  0,  0, 0, 0,  0, 0,  0,
0, 0,  0,  0,  0, 0, 0,  0, 0,  0,
0
};

#else
const signed short Sidetone_FIR[31] = 
{ 
   287,   -37,  -407,  -201,   432,   541,  -305,  -936,   -48,  1292, 
   818, -1545, -2548,  1657,  9937, 14977,  9937,  1657, -2548, -1545, 
   818,  1292,   -48,  -936,  -305,   541,   432,  -201,  -407,   -37, 
   287 
};
#endif

#if defined(__VIBRATION_SPEAKER_SUPPORT__) && (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
static void AM_Write_Vibr_Sph_Notch_Flt (void)
{
    int I;
    const int16 *ptr         = (const int16 *)&VIBR_NVRAM_DATA.VIBR_NVRAM_SPH_FILTER_COEF[10];
    volatile uint16 *dsp_ptr = DSP_PM_ADDR(3, 0x026F);
    
    for (I = 15; I > 0; I--)
    {
        *dsp_ptr++ = *ptr++;
    }
    
    return;
}
#endif

static void AM_WriteSidetoneFIR( void )
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    {
        int I;
        const int16 *ptr         = Sidetone_FIR;
        volatile uint16 *dsp_ptr = Pseudo_SAL_Sidetone_GetFltCoefAddr();
        
        for (I = PSEUDO_SAL_FLTCOEFLEN_SIDETONE; I > 0; I--)
        {
            *dsp_ptr++ = *ptr++;
        }
    }
#else   // chip compile option
   int I;
   const int16 *ptr;
   volatile uint16* dsp_ptr;

   /* Write audio FIR filter coeficients */
#if defined(__VIBRATION_SPEAKER_SUPPORT__) && (defined(MT6250) || defined(MT6252))
   ptr = (const int16 *)&VIBR_NVRAM_DATA.VIBR_NVRAM_SPH_FILTER_COEF[0];
#else
   ptr = Sidetone_FIR;
#endif
#if defined(MT6256)
   dsp_ptr = DSP_PM_ADDR(2, 0x013A);
#elif defined(MT6255) || defined(MT6250)
   dsp_ptr = DSP_PM_ADDR(3, 0x013A);
#elif defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   dsp_ptr = DSP_PM_ADDR(0, 0x3FD1);
#else
   #error Need DSP guys give the sidetone FIR address
#endif

   for( I = 31; --I >= 0; )
      *dsp_ptr++ = *ptr++;
#endif  // chip compile option
}

static void AM_WriteSpeechCompensationFilter( const int16 in_coeff[45], const int16 out_coeff[45] )
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    {
        int i;
        volatile uint16 *dsp_ptr = Pseudo_SAL_BKF_GetFltCoefAddr_NB_UL();
        for (i = 0; i < PSEUDO_SAL_FLTCOEFLEN_BKF_NB; i++)
        {
#ifndef __HQA_AUDIO__
            *dsp_ptr ++ = *in_coeff++;
#else
            *dsp_ptr ++ = Speech_All_Pass_FIR_Coeff[i];
#endif
        }
    }
    
    {
        int i;
        volatile uint16 *dsp_ptr = Pseudo_SAL_BKF_GetFltCoefAddr_NB_DL();
        for (i = 0; i < PSEUDO_SAL_FLTCOEFLEN_BKF_NB; i++)
        {
#ifndef  __HQA_AUDIO__
            *dsp_ptr ++ = *out_coeff++;
#else
            *dsp_ptr ++ = Speech_All_Pass_FIR_Coeff[i];
#endif
        }
    }
#else   // chip compile option
   int i;
   volatile uint16* dsp_ptr;

   /* Write audio FIR filter coeficients */
   *DP_AFI_COEF_LEN = COMPEN_FILTER_SIZE;   
#if defined(MT6256)   
   dsp_ptr = DSP_PM_ADDR(2,DSP_IN_FIR_COEFF_IN_ADDR); //DSP_PM_ADDR(0,DSP_IN_FIR_COEFF_IN_ADDR);   //Scott101018
#elif defined(MT6255) || defined(MT6250)
   dsp_ptr = DSP_PM_ADDR(3,DSP_IN_FIR_COEFF_IN_ADDR); 
#else
   dsp_ptr = DSP_PM_ADDR(0,DSP_IN_FIR_COEFF_IN_ADDR);   
#endif   
   for( i=0; i<COMPEN_FILTER_SIZE; i++ )
#ifndef __HQA_AUDIO__    
      *dsp_ptr ++ = *in_coeff++;    
#else
      *dsp_ptr ++ = Speech_All_Pass_FIR_Coeff[i];      
#endif

   *DP_AFO_COEF_LEN = COMPEN_FILTER_SIZE;   
#if defined(MT6256)   
   dsp_ptr = DSP_PM_ADDR(2,DSP_OUT_FIR_COEFF_OUT_ADDR); //DSP_PM_ADDR(0,DSP_OUT_FIR_COEFF_OUT_ADDR);  //Scott101018  
#elif defined(MT6255) || defined(MT6250)
   dsp_ptr = DSP_PM_ADDR(3,DSP_OUT_FIR_COEFF_OUT_ADDR); //DSP_PM_ADDR(0,DSP_OUT_FIR_COEFF_OUT_ADDR);  //Scott101018  
#else
   dsp_ptr = DSP_PM_ADDR(0,DSP_OUT_FIR_COEFF_OUT_ADDR);    
#endif
   for( i=0; i<COMPEN_FILTER_SIZE; i++ )
#ifndef  __HQA_AUDIO__   
      *dsp_ptr ++ = *out_coeff++;
#else
      *dsp_ptr ++ = Speech_All_Pass_FIR_Coeff[i];      
#endif
#endif  // chip compile option
}

void AM_GetFirCoeffs(kal_int16 **in_coeff, kal_int16 **out_coeff)
{
#if __RELOAD_DSP_COEFF__
   *in_coeff  = (kal_int16 *)am.in_coeff_tmp;
   *out_coeff = (kal_int16 *)am.out_coeff_tmp;
#endif
}
void AM_WriteFirCoeffs( const int16 in_coeff[45], const int16 out_coeff[45] )
{
   if(am.toneLoopbackRec)
      return;

#if __RELOAD_DSP_COEFF__
   memcpy(am.in_coeff_tmp, in_coeff, 45*sizeof(int16));
   memcpy(am.out_coeff_tmp, out_coeff, 45*sizeof(int16));
#endif

   audio_coeff_flag = 1;

   /* Write audio FIR filter coeficients */
   AM_WriteSpeechCompensationFilter(in_coeff, out_coeff);

   /* enable input/output filtering */

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *COMPEN_BLOCK_FLT_PAR_PTR |= ( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
#if DSP_16K_SIDETONE_SUPPORT
   if( (!AM_IsAmInSpeechState()) && (!AM_IsAfeOn())) //after DSP_16K_SIDETONE_SUPPORT, always use SW IIR(for the case in speech change speech mode, do not switch IIR)
#endif
   {
   *DP_AUDIO_PAR |= VOICE_16K_SWITCH_FLAG;
                                        /* if 8->16K IIR is done by H/W */
   *AFE_VLB_CON &= ~(0x01<<3);                     /* if 8->16K IIR is done by H/W */
   }
#else /* all others use DSP IIR */
   *COMPEN_BLOCK_FLT_PAR_PTR |= ( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
                                        /* if 8->16K IIR is done by DSP */
   *AFE_VLB_CON |= (0x01<<3);                      /* if 8->16K IIR is done by DSP */
#endif
}

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
const signed short Audio_Flt_Coeff[82] =
{
    96,   162,   -92,  -488,  -302,   408,   372,  -660,  -780,   782,
  1272,  -958, -2094,  1088,  3458, -1200, -6426,  1266, 20318, 30834,
 20318,  1266, -6426, -1200,  3458,  1088, -2094,  -958,  1272,   782,
  -780,  -660,   372,   408,  -302,  -488,   -92,   162,    96,     0,
     0,  /* SRC Up-Sampling */
   -36,  -175,  -262,   -51,   277,   146,  -376,  -317,   489,   595,
  -597, -1034,   689,  1777,  -744, -3351,   727, 10500, 15852, 10500,
   727, -3351,  -744,  1777,   689, -1034,  -597,   595,   489,  -317,
  -376,   146,   277,   -51,  -262,  -175,   -36,     0,     0,     0,
     0  /* SRC Down-Sampling */
};

const signed short Sph_AGC_HP_Flt_Coeff[40] = DEFAULT_SPH_AGC_HP_FLT_COEF;

#else   // chip compile option
#if DSP_16K_SIDETONE_SUPPORT
const signed short Audio_Flt_Coeff[114] = 
{ 
    96,   162,   -92,  -488,  -302,   408,   372,  -660,  -780,   782,
  1272,  -958, -2094,  1088,  3458, -1200, -6426,  1266, 20318, 30834,
 20318,  1266, -6426, -1200,  3458,  1088, -2094,  -958,  1272,   782,
  -780,  -660,   372,   408,  -302,  -488,   -92,   162,    96,     0,
     0,     0,     0,     0,     0,     0,     0,/* DL SRC (8k task)*/
   -36,  -175,  -262,   -51,   277,   146,  -376,  -317,   489,   595,
  -597, -1034,   689,  1777,  -744, -3351,   727, 10500, 15852, 10500,
   727, -3351,  -744,  1777,   689, -1034,  -597,   595,   489,  -317,
  -376,   146,   277,   -51,  -262,  -175,   -36,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,/* UL SRC (8k task)*/
 -8009, 16194,  7884,-15768,  7884, -7758, 15943,  8192,-16384,  8192, /* UL WB HP-IIR (20ms task)*/
 -7322, 15221,  7162,-14324,  7162, -5371, 13169,  7162,-14324,  7162  /* UL NB HP-IIR (20ms task)*/
};
#else
const signed short Audio_Flt_Coeff[114] = 
{ 
   -26,   -52,    19,   104,    28,  -151,  -134,   150,   283,   -59,
  -441,  -164,   531,   521,  -461,  -999,    97,  1520,   734, -1997,
 -2562,  2330, 10084, 13890, 10084,  2330, -2562, -1997,   734,  1520,
    97,  -999,  -461,   521,   531,  -164,  -441,   -59,   283,   150,
  -134,  -151,    28,   104,    19,   -52,   -26,    59,    97,   -67,
  -160,    60,   241,   -28,  -339,   -39,   448,   153,  -564,  -333, 
   681,   605,  -790, -1023,   885,  1730,  -958, -3247,  1004, 10318, 
 15303, 10318,  1004, -3247,  -958,  1730,   885, -1023,  -790,   605, 
   681,  -333,	-564,   153,   448,   -39,  -339,   -28,   241,    60, 
  -160,   -67,    97,    59, -7153, 15272,  7650,-15301,  7650, -7153,
 15272,  7650,-15301,  7650, -7322, 15221,  7162,-14324,  7162, -5371,
 13169,  7162,-14324,  7162 
};
#endif
#endif  // chip compile option

static void AM_WriteAntiAliasFilter( void )
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    {   //SRC FIR coeff
        int I;
        const int16 *ptr         = Audio_Flt_Coeff;
        volatile uint16 *dsp_ptr = Pseudo_SAL_SRC_GetFltCoefAddr();
        for (I = PSEUDO_SAL_FLTCOEFLEN_SRC; I > 0; I--)
        {
            *dsp_ptr++ = *ptr++;
        }
    }
    
    {   //AGC HP IIR coeff
        int I;
        const int16 *ptr         = Sph_AGC_HP_Flt_Coeff;
        volatile uint16 *dsp_ptr = Pseudo_SAL_AGC_GetFltCoefAddr();
        for (I = PSEUDO_SAL_FLTCOEFLEN_AGC; I > 0; I--)
        {
            *dsp_ptr++ = *ptr++;
        }
    }
#else   // chip compile option
   volatile uint16* dsp_ptr;
   int I;
   const int16 *ptr;

   /* Write Audio filter coefficients */

   *DP_Audio_FltCoeff_Len = 47;
   ptr = Audio_Flt_Coeff;

#if defined(MT6256)
   dsp_ptr = DSP_PM_ADDR(2, 0x00C8);//DSP_DM_ADDR(2, 0x3319); //Scott101018
#elif defined(MT6255) || defined(MT6250)
   dsp_ptr = DSP_PM_ADDR(3, 0x00C8);  
#elif defined(MT6235) || defined(MT6235B)
   dsp_ptr = DSP_DM_ADDR(2, 0x3540);
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)
   dsp_ptr = DSP_DM_ADDR(2, 0x3319);
#elif defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   dsp_ptr = DSP_DM_ADDR(1, 0x3540);
#else
   #error Need DSP guys give the Firmware Anti-Aliasing address
#endif

#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   *DSP_UP_DOWN_SAMP_CTRL  = 1;
#endif

   for( I = 114; --I >= 0 ; )
      *dsp_ptr++ = *ptr++;
#endif  // chip compile option
}

#if !(defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) 
const signed short Audio_16k_Compen_filter[45] = { 
   -50,    58,  -115,   146,  -226,   460,  -620,  1086, -1756,  3535, 
 -8484, 31128, -8484,  3535, -1756,  1086,  -620,   460,  -226,   146, 
  -115,    58,   -50,     0,     0,     0,     0,     0,     0,     0, 
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
     0,     0,     0,     0,     0 
};

static void AM_Write16kCompensationFilter( void )
{   // We write the TX first, and then write RX.
   volatile uint16* dsp_ptr;
   int I;
   const int16 *ptr;

      /* Write 16k compensation filter coefficients */
#if defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   *DP_16k_CompenFlt_Len = 45;
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01)
   // For AWB Record
   *DP_AUDIO_16K_TX_FIR_LEN = 45;   // TX length
   *DP_AUDIO_16K_RX_FIR_LEN = 45;   // RX length
   *DP_AUDIO_16K_PAR_PATCH = 0x20;  // Copy the 16k compensation filter from DM to PM
#endif

      ptr = Audio_16k_Compen_filter;

#if defined(MT6256) 
   dsp_ptr = DSP_PM_ADDR(2, 0x027D); //DSP_DM_ADDR(2, 0x0F01); //Scott101018
#elif defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   dsp_ptr = DSP_PM_ADDR(0, 0x3FA4);
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)
   dsp_ptr = DSP_DM_ADDR(2, 0x0F01);
#else
   #error Need DSP guys give the 16k compensation filter address
#endif
      
   for( I = 45 ; --I >= 0 ; )
      *dsp_ptr++ = *ptr++;

#if defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01)
   /* We write the TX first, and then write RX.                    */
   /* Because we only use 45 taps currently, the others are zeros. */
   // TX zeros
   for( I = 45 ; --I >= 0 ; )
      *dsp_ptr++ = 0;
   
   // RX
   ptr = Audio_16k_Compen_filter;
   for( I = 45 ; --I >= 0 ; )
      *dsp_ptr++ = *ptr++;
   // RX zeros
   for( I = 45 ; --I >= 0 ; )
      *dsp_ptr++ = 0;
#endif
}
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// AGC Table is ROM in MT6260 DSP
#else   // chip compile option
#if defined(MT6256) ||	defined(MT6255)	|| defined(MT6250)   //MT6256_E2 and MT6255 in the future
const kal_uint16 AGC_DSP_Tables[47] = {
 2048,   2297,   2578,   2892,   3245,   3641,   4086,   4584,   5144,   5772,
 6476,   7266,   8153,   9148,  10264,  11516,  12922,  14498,  16267,  18252,
 20480, 22978,   25782,  28928,  32458,  36419,  40862,  45849,  51443,  57720,
 64763,  2048,    1825,   1626,   1449,   1292,   1151,   1026,    914,    815,       
  726,   647,     577,    514,    458,    408,    364
};
#else
const int16 AGC_DSP_Parameters[20]={
 1,   4, -14, -12, 1, 1024, 1,  800, -14, -10, 
 4, 511,  -4,   1, 5,    1, 2, 2047,  -9,  -6
};
#endif

static void AM_WriteAGCParam(void)
{
   int I;
   volatile kal_uint16 *addr;

#if defined(MT6256) ||	defined(MT6255)	|| defined(MT6250)//MT6256_E2 and MT6255 in the future
   addr = DSP2_PM_ADDR( PM_AGC_TABLE_PAGE, PM_AGC_TABLE_ADDR );
   for ( I = 0 ; I < 47 ; I++ )
      *addr++ = AGC_DSP_Tables[I];
#else
   addr = DSP2_DM_ADDR( DM_AGC_PARAMETER_PAGE, DM_AGC_PARAMETER_ADDR );
   for ( I = 0 ; I < 20 ; I++ )
      *addr++ = AGC_DSP_Parameters[I];
#endif
}
#endif  // chip compile option

#if __RELOAD_DSP_COEFF__

/* For 65nm process, MCU has to reload DSP coefficient at each wake-up */
static void AM_ReloadDSPCoefficient( void )
{
   AM_WriteSidetoneFIR();
   
   if(!am.toneLoopbackRec)
      AM_WriteSpeechCompensationFilter(am.in_coeff_tmp, am.out_coeff_tmp);

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// AGC Table is ROM in MT6260 DSP
#else   // chip compile option
   AM_WriteAGCParam();
#endif  // chip compile option
   AM_WriteAntiAliasFilter();

   if ( !(am.state & AM_STATE_SPEECH) )
      L1SP_Reload_SPE_Para();
   
#if defined(__DUAL_MIC_SUPPORT__)
   L1SP_Reload_DMNR_Para();
#endif //__DUAL_MIC_SUPPORT__
}
#endif


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_VMRecordOff( uint32 data );

#ifdef _BANDWIDTH_EXPENSION_SUPPORT_
void AM_SetBWExpn(bool on)
{
   if(on){
      *DP_Audio_FltCoeff_Addr |= 0x0001; //turn on FWE  
   }else{
      *DP_Audio_FltCoeff_Addr &= ~0x0001; //turn off FWE  
   }
}
#endif

static void AM_DSP_AfeOn( uint32 data )
{
   (void)data;   
   ASSERT_REBOOT(!am.afe_loopback_flag);   // Should not open AFE loopback twice
   ASSERT_REBOOT( !(am.state & (AM_STATE_SPEECH | AM_STATE_VOIP | AM_STATE_AUDIO)) ); 
   L1Audio_Msg_AM_Switch( AM_Switch_Name(11), L1AUDIO_Str_onoff(1) );

#if DSP_16K_SIDETONE_SUPPORT
   *AFE_VMCU_CON1 &= ~0x0200;
   #if defined(MT6256) || defined(MT6252) || defined(MT6236)
   if(!AFE_GetLoopbackStatus())
   #endif
   *AFE_VLB_CON |= (0x01<<3);
#endif
   am.DL_UL_path = SPH_BOTH_PATH;
   AFE_TurnOn8K();
   am.afe_loopback_flag = true;
}

void AM_AfeOn(kal_uint32 afe_mode)
{ 
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)   
   AFE_Stop_and_Wait_DelayOff(L1SP_SPEECH, ASP_FS_8K);
//#if defined(__MT6253_AUD_DELAY_OFF_SUPPORT__) || defined(__MT6236_AUD_DELAY_OFF_SUPPORT__) 
#else
    {
        kal_uint8 DisIdleCount = 3;
        
        while (AFE_GetAfeSate() == 2)   // afe IdleOff state
        {
            AFE_Disable_IdleOffDelay();
            kal_sleep_task(3);
            DisIdleCount--;
            if (!DisIdleCount)
            {
                break;
            }
        }
    }
#endif
  
   AM_Force_VBI_END_IN_TASK();
   AM_Enqueue( AM_DSP_AfeOn, false, true );
   am.afe_mode = afe_mode;
   if(afe_mode&L1SP_AFE_MODE_DL_OPEN)
      AFE_TurnOnSpeaker( L1SP_SPEECH );
   if(afe_mode&L1SP_AFE_MODE_UL_OPEN)
      AFE_TurnOnMicrophone( L1SP_SPEECH );
   
   AM_FlushQFunction();
}

static void AM_DSP_AfeOff( uint32 data )
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(11), L1AUDIO_Str_onoff(0) );
    ASSERT_REBOOT(am.afe_loopback_flag);   // Should not close AFE loopback twice
   am.afe_loopback_flag = false;
   
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
#if DSP_16K_SIDETONE_SUPPORT
   *AFE_VMCU_CON1 |= 0x0200;
   *AFE_VLB_CON &= ~(0x01<<3);
#endif

}

void AM_AfeOff( void )
{

#if defined(MT6256) || defined(MT6255) 
#ifndef  L1D_TEST
      AFE_TurnOffMicrophone( L1SP_SPEECH );
      AFE_TurnOffSpeaker( L1SP_SPEECH );
      kal_sleep_task(2);
#endif
#endif

#ifndef  L1D_TEST
   KT_StopAndWait();
   TONE_StopAndWait();
#endif

#if ( !defined(MT6256) && !defined(MT6255) ) 
#ifndef  L1D_TEST
   if(am.afe_mode&L1SP_AFE_MODE_UL_OPEN)
      AFE_TurnOffMicrophone( L1SP_SPEECH );
   if(am.afe_mode&L1SP_AFE_MODE_DL_OPEN)   
      AFE_TurnOffSpeaker( L1SP_SPEECH );
#endif
#endif
   am.afe_mode = -1; 
   AM_Enqueue( AM_DSP_AfeOff, false, false );

   AM_FlushQFunction();
}

bool AM_IsAfeOn( void )
{
   return am.afe_loopback_flag;
}
static void AM_DSP_SpeechOn( uint32 rat_mode )
{
   ASSERT_REBOOT(!am.afe_loopback_flag);   // Should not use AFE loopback and speech at the same time
   ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 
   L1Audio_Msg_AM_Switch( AM_Switch_Name(5), L1AUDIO_Str_onoff(1) );

   if ((am.state & AM_STATE_AVSYNC) && (*DP_A2V_INT_ENABLE == 0))
      *DP_A2V_INT_ENABLE = 3;

   am.speech_off_delay = 0;

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#if DSP_16K_SIDETONE_SUPPORT
    *AFE_VMCU_CON1 &= ~0x0200;
    *AFE_VLB_CON |= (0x01<<3);
#endif
   

    if (rat_mode == RAT_2G_MODE)
    {
        am.sp3g_flag = false;
        AM_DSP_SetSRCCtrl(0);
        am_set_cod_band(IsWBLink(am.speech_mode));
        Pseudo_SAL_2G_Call_Open(am.speech_mode, am.speech_mode, am.sub_channel);
    }
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
    else if (   rat_mode == RAT_3G_MODE
#ifdef __VIDEO_CALL_SUPPORT__
/* under construction !*/
#endif
            )
    {
        am.speech_mode = 0xA; // 4.75 NB AMR
        am.sp3g_flag = true;
        AM_DSP_SetSRCCtrl(0);
        am_set_cod_band(IsWBLink(am.speech_mode));
        Pseudo_SAL_3G_Call_Open(am.speech_mode, am.speech_mode, SP3G_IsDTXOn(), DSP_PCM_IDLE_DELAY_TABLE[6][0], DSP_PCM_IDLE_DELAY_TABLE[6][1], DSP_PCM_IDLE_DELAY_TABLE[6][2]);
    }
#endif

#else   // chip compile option
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
   if(rat_mode == RAT_3G_MODE
#ifdef __VIDEO_CALL_SUPPORT__
/* under construction !*/
#endif
   ){
      *DP_3G_STATE = 1;
      am.speech_mode = 0xA; // 4.75 NB AMR        
   }
#endif
#if defined(MT6256) || defined(MT6255) || defined(MT6250)
   {
   AM_DSP_SetSRCCtrl(0);
   }  
#endif

#ifdef AUTO_DAI
   AFE_TurnOff8K();              /* Turn Off 8K int. before turn on DAI   */
   AFE_TurnOnDAI();
   AFE_TurnOn8K();               /* Turn On 8K int   */
   *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x0800;   
   am.io_type = DAI_MODE;
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );
   AM_WriteSpeechParameters( 0x0600, am.speech_mode, am.speech_mode );
   am.state |= AM_STATE_DAI;
#else

#if DSP_16K_SIDETONE_SUPPORT
   *AFE_VMCU_CON1 &= ~0x0200;
   *DP_AUDIO_PAR &= ~(VOICE_16K_SWITCH_FLAG);
   #if defined(MT6256) || defined(MT6252) || defined(MT6236)
   if(!AFE_GetLoopbackStatus())
   #endif
   *AFE_VLB_CON |= (0x01<<3);
#endif
   AFE_TurnOn8K();

   if(am.fLoopBack){
      AM_WriteSpeechParameters( 0x0632, am.speech_mode, am.speech_mode );
   }else{
      if(rat_mode == RAT_2G_MODE)
      {
         AM_WriteSpeechParameters( 0x0633, am.speech_mode, am.speech_mode );
      }   
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
      else if(rat_mode == RAT_3G_MODE
#ifdef __VIDEO_CALL_SUPPORT__
/* under construction !*/
#endif
      ){
         kal_uint16 sc_flags;
         if( SP3G_IsDTXOn() )
            sc_flags = 0x637;
         else
            sc_flags = 0x633;
         AM_WriteSpeechParameters( sc_flags, am.speech_mode, am.speech_mode ); // DTX always on 
      }   
#endif
   }   
#endif
   if(rat_mode == RAT_2G_MODE)
   {
      AM_FillSilencePattern( DSP_TX_TCH_S0_0, 2, am.speech_mode );
      AM_Write_Speech_Delay( am.speech_mode,  am.sub_channel, L1D_Get_Win_TQ_WRAP() - TQ_WRAP_COUNT );
      am.sp3g_flag = false;
   }         
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
   else if(rat_mode == RAT_3G_MODE
#ifdef __VIDEO_CALL_SUPPORT__
/* under construction !*/
#endif
   ){
      AM_FillSilencePattern( DP_3G_UL_TX_TYPE, 2, am.speech_mode );  
      AM_Write_Idle_Delay(6);
      am.sp3g_flag = true;
   }
#endif
#ifndef L1D_TEST
   /* bit14 :the data of Speech DSP is avaible
      bit14 on  : Modem always sends the SpeechGood frame from Speech DSP, and at that time Driver fills the silence pattern. It causes MD send the silence pattern(good frame) to network
      bit14 off : Modem always sends the SpeechBad  frame into network. It will cause the better performance for continuity 
   */
   *E_CTRL_HO &= ~0x4000; 
   *E_CTRL_HO |=  0x0004;   // Enable ramp up in TCH
#endif    

#endif  // chip compile option

#ifdef _FWE_SUPPORT_
   AM_SetFWE(true);
#endif

#ifdef _BANDWIDTH_EXPENSION_SUPPORT_
/*  MagiHDvoice(N) transforms 8k speech into 16k speech.  Due to another function ¡§pre-clipping¡¨ in Loudspeaker mode, 
    this function should not be enabled in Loudspeaker Mode. */
   {
      extern const unsigned char Spk2In1;    
      if(  ((SPH_MODE_NORMAL == L1SP_GetSpeechMode()) && (Spk2In1 == 1)) ||
           (SPH_MODE_EARPHONE== L1SP_GetSpeechMode()) ){
            AM_SetBWExpn(true);   
      }
   }
#endif
   am.state |= AM_STATE_SPEECH;
   am.DL_UL_path = SPH_BOTH_PATH;
#if defined(__PCM_CLOCK_ALWAYS_ON__)
   // AFE_TurnOn8K();
#else   // defined(__PCM_CLOCK_ALWAYS_ON__)
   AFE_TurnOn8K();
#endif  // defined(__PCM_CLOCK_ALWAYS_ON__)
   
   VBI_Reset();

   
}


void AM_SpeechOn(uint32 rat_mode)
{   
#ifdef DSDA_VIA_PCM_INTERFACE
	// do nothing
#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)  
   AFE_Stop_and_Wait_DelayOff(L1SP_SPEECH, ASP_FS_8K);
#else
    {
        kal_uint8 DisIdleCount = 3;
        
        while (AFE_GetAfeSate() == 2)   // afe IdleOff state
        {
            AFE_Disable_IdleOffDelay();
            kal_sleep_task(3);
            DisIdleCount--;
            if (!DisIdleCount)
            {
                break;
            }
        }
    }
#endif

#if defined(__VIBRATION_SPEAKER_SUPPORT__) && (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
   AM_Write_Vibr_Sph_Notch_Flt();
#endif

   AM_Force_VBI_END_IN_TASK();
   AM_Enqueue(AM_DSP_SpeechOn, rat_mode, (bool)(rat_mode == RAT_2G_MODE));

#ifdef DSDA_VIA_PCM_INTERFACE
#else
   AFE_TurnOnSpeaker( L1SP_SPEECH );
   AFE_TurnOnMicrophone( L1SP_SPEECH );
#endif
   
   AM_FlushQFunction();
}

static void AM_DSP_SpeechOff( uint32 data )
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(5), L1AUDIO_Str_onoff(0) );
   am.speech_off_delay = 10;
   DP_KT_ATT = 0x0; // avoid SD buffer repeating if tone/keytone continues
   if( am.speech_state & SP_STATE_VMR )            /* call drop while conversation recording */
      AM_DSP_VMRecordOff( 0 );

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    am.state &= ~AM_STATE_SPEECH;
    if (am.state == 0)
    {
        VBI_End();
    }

#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
    if (am.sp3g_flag )
    {
        Pseudo_SAL_3G_Call_Close();
    }
    else
#endif
    {
        Pseudo_SAL_2G_Call_Close();
    }
    
    if ((am.state & ~AM_STATE_AUDIO) == 0)
    {
#if defined(__PCM_CLOCK_ALWAYS_ON__)
        // AFE_TurnOff8K();
#else   // defined(__PCM_CLOCK_ALWAYS_ON__)
        AFE_TurnOff8K();
#endif  // defined(__PCM_CLOCK_ALWAYS_ON__)
    }
#if DSP_16K_SIDETONE_SUPPORT
    *AFE_VMCU_CON1 |= 0x0200;
    *AFE_VLB_CON &= ~(0x01<<3);
#endif

#else   // chip compile option

#ifdef AUTO_DAI
   if( am.state & AM_STATE_DAI ) {
      AFE_TurnOffDAI();
      *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x8000; 
      am.io_type = NORMAL_MODE;
      L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) ); 
      am.state &= ~AM_STATE_DAI;
   }
#endif

   am.state &= ~AM_STATE_SPEECH;
   if( am.state == 0 ) 
      VBI_End();   

   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
#if DSP_16K_SIDETONE_SUPPORT
   *AFE_VMCU_CON1 |= 0x0200;
   *DP_AUDIO_PAR |= (VOICE_16K_SWITCH_FLAG);
   *AFE_VLB_CON &= ~(0x01<<3);
#endif

   *DP_SC_FLAGS &= 0xF800;
   *DP_SC_MUTE &= ~0x0002;
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
   if( am.sp3g_flag ){
      SP3G_SetRxTypeToNoData();
      *DP_3G_STATE = 0;
      am.sp3g_flag = false;
   }
#endif
   *E_CTRL_HO &= ~0x0004;   // Disable ramp up in TCH
   *E_CTRL_HO |=  0x4000;   
   
#endif  // chip compile option

#ifdef _FWE_SUPPORT_
   AM_SetFWE(false);
#endif   

#ifdef _BANDWIDTH_EXPENSION_SUPPORT_
/*  MagiHDvoice(N) transforms 8k speech into 16k speech.  Due to another function ¡§pre-clipping¡¨ in Loudspeaker mode, 
    this function should not be enabled in Loudspeaker Mode. */
   {
      extern const unsigned char Spk2In1;    
      if(  ((SPH_MODE_NORMAL == L1SP_GetSpeechMode()) && (Spk2In1 == 1)) ||
           (SPH_MODE_EARPHONE== L1SP_GetSpeechMode()) ){
            AM_SetBWExpn(false);   
      }
   }
#endif
}

void AM_SpeechOff( void )
{

#if defined(MT6256) || defined(MT6255) 
#ifndef  L1D_TEST
      AFE_TurnOffMicrophone( L1SP_SPEECH );
      AFE_TurnOffSpeaker( L1SP_SPEECH );
      kal_sleep_task(2);
#endif
#endif

#ifndef  L1D_TEST
   KT_StopAndWait();
   TONE_StopAndWait();
   DTMF_MCU_StopAndWait();
#endif

#if ( !defined(MT6256) && !defined(MT6255) ) 
#ifndef  L1D_TEST
#ifndef DSDA_VIA_PCM_INTERFACE
   AFE_TurnOffMicrophone( L1SP_SPEECH );
   AFE_TurnOffSpeaker( L1SP_SPEECH );
#endif // if NOT define  DSDA_VIA_PCM_INTERFACE
#endif
#endif

   AM_Enqueue( AM_DSP_SpeechOff, false, false );

   AM_FlushQFunction();
}

bool AM_IsSpeechOn( void )
{
   return( (bool)((am.state & AM_STATE_SPEECH) != 0) );
}

bool AM_IsAmInSpeechState( void )
{
	if ((am.state & (AM_STATE_SPEECH | AM_STATE_VOICE | AM_STATE_VOIP | AM_STATE_PCMNWAY)) != 0)
		return true;
	else 
		return false;
}

bool AM_IsNeedSpeechDSP( void )
{
   if( AM_IsToneOn()
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      && (AM_IsAudioPlaybackOn()==-1)     //Tone with audio is generated by DSP's audio(AudioTone)
#endif      
      )
        return true;
   if ((am.state & 
        (AM_STATE_KEYTONE | AM_STATE_SPEECH | AM_STATE_VOICE | AM_STATE_VOIP | AM_STATE_DACA
#if !defined(__CVSD_CODEC_SUPPORT__)
         |AM_STATE_AvBT    
         //|AM_STATE_SND_EFFECT /*Because AM_STATE_SND_EFFECT always follow AM_STATE_SPEECH, we skip it*/
#endif         
        )
    ))
       return true;
 
    return false;
}  

void AM_SetSpeechMode( uint16 speech_mode, int8 sub_channel )
{
   am.speech_mode = speech_mode;
   am.sub_channel = sub_channel;
}

#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
void AM_DSP_InterRAT_W2G( uint32 data )
{
   (void)data;
   if( !(am.state & AM_STATE_SPEECH) )
      return;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    VBI_End();
    Pseudo_SAL_3G_Call_Close();
    am.sp3g_flag = false;
    Pseudo_SAL_2G_Call_Open(am.speech_mode, am.speech_mode, am.sub_channel);
#else   // chip compile option
   //*DP_SC_FLAGS &= 0xF800;
   *DP_SC_MUTE &= ~0x0002;
   *DP_3G_STATE = 0;
   am.sp3g_flag = false;
   AM_WriteSpeechParameters( ((*DP_SC_FLAGS & 0xF800) | 0x0633), am.speech_mode, am.speech_mode );
   AM_FillSilencePattern( DSP_TX_TCH_S0_0, 2, am.speech_mode );
   AM_Write_Speech_Delay( am.speech_mode, am.sub_channel, L1D_Get_Win_TQ_WRAP() - TQ_WRAP_COUNT );
#endif  // chip compile option
   VBI_Reset();
   L1Audio_Msg_INTERRAT_W2G();
}

void AM_InterRAT_W2G()
{
   AM_Enqueue( AM_DSP_InterRAT_W2G, 0, true );
}

void AM_DSP_InterRAT_G2W( uint32 data )
{
   if( !(am.state & AM_STATE_SPEECH) )
      return;

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    VBI_End();
    Pseudo_SAL_2G_Call_Close();
    am.speech_mode = data;
    Pseudo_SAL_3G_Upd_Enc_Cod(data);//for 3g codec internal, MT6280
    Pseudo_SAL_3G_Upd_Dec_Cod(data);//for 3g codec internal, MT6280
    Pseudo_SAL_3G_Call_Open(data, data, SP3G_IsDTXOn(), 0, 0, DSP_PCM_IDLE_DELAY_TABLE[6][2]);
    am.sp3g_flag = true;
#else   // chip compile option
   //*DP_SC_FLAGS &= 0xF800;
   *DP_SC_MUTE &= ~0x0002;
   *DP_3G_STATE = 1;
   am.speech_mode = 0xA; // 4.75 NB AMR

    {
        kal_uint16 sc_flags = SP3G_IsDTXOn() ? 0x637 : 0x633;
        AM_WriteSpeechParameters( ((*DP_SC_FLAGS & 0xF800) | sc_flags), am.speech_mode, am.speech_mode ); // DTX always on 
    }
   AM_FillSilencePattern( DP_3G_UL_TX_TYPE, 2, am.speech_mode );  
   AM_Write_Idle_Delay(6);
   am.sp3g_flag = true;
#endif  // chip compile option
   VBI_Reset();
   L1Audio_Msg_INTERRAT_G2W();
}
void AM_InterRAT_G2W()
{
   AM_Enqueue( AM_DSP_InterRAT_G2W, 0, true );
}
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
static void am_set_cod_band(kal_bool is_WB)
{
    if (is_WB)
    {
        *DSP_SPH_8K_CTRL |= 0x8;
    }
    else
    {
        *DSP_SPH_8K_CTRL &= ~0x8;
    }
    
    return;
}
#endif  // chip compile option

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define LIMITER_INIT    (1<<0)  // limiter Init 0/1 : None/Done
#define UL_SRC_DS       (1<<1)  // UL SRC (DS)  main mic
#define DL_SRC_US       (1<<2)  // DL SRC (US)
#define SIDETONE_BIT    (1<<3)  // SideTone
// #define BIT4            (1<<4)
// #define BIT5            (1<<5)
#define UL2_SRC_DS      (1<<6)  // UL2 SRC (DS)  referece mic
#define UL_SRC_US       (1<<7)  // UL SRC (US) 0/1 : Off/On                               
#define DL_SRC_DS       (1<<8)  // DL SRC (DS) 0/1 : Off/On
// #define BIT9            (1<<9)
// #define BIT10           (1<<10)
// #define BIT11           (1<<11)
// #define BIT12           (1<<12)
#define BIT13           (1<<13)

void AM_DSP_SetSRCCtrl(uint32 data)
{
    kal_uint8 sph_mode = L1SP_GetSpeechMode();
    kal_bool isWBLink = (kal_bool)IsWBLink(am.speech_mode);
    kal_uint32 v = 0;
    (void)data;
    
    switch (sph_mode)
    {
        case SPH_MODE_NORMAL:
#if defined(_FWE_SUPPORT_)
            v = SIDETONE_BIT + UL_SRC_DS;   // This setting is only for MT6250; FixedWBEnhancement only is applied to DL
#elif defined(__DUAL_MIC_SUPPORT__)
            v = isWBLink ? SIDETONE_BIT : SIDETONE_BIT | DL_SRC_US | UL_SRC_DS | UL2_SRC_DS;
#else
            v = isWBLink ? SIDETONE_BIT : SIDETONE_BIT | DL_SRC_US | UL_SRC_DS;
#endif      
            break;
        case SPH_MODE_BT_EARPHONE:
        case SPH_MODE_BT_CARKIT:
#if defined(_FWE_SUPPORT_)
            v = DL_SRC_DS;
#else
#ifdef DSDA_VIA_PCM_INTERFACE
				v = isWBLink ? 0 : DL_SRC_US | UL_SRC_DS;
#else
            v = isWBLink ? DL_SRC_DS + UL_SRC_US : 0;
#endif
#endif      
            break;
        case SPH_MODE_EARPHONE:
#if defined(_FWE_SUPPORT_)
            v = SIDETONE_BIT + UL_SRC_DS;
#else
            v = isWBLink ? SIDETONE_BIT : SIDETONE_BIT | DL_SRC_US | UL_SRC_DS;
#endif        
            break;
        case SPH_MODE_LOUDSPK:
#if defined(_FWE_SUPPORT_)  
            v = UL_SRC_DS;
#else
            v = isWBLink ? 0 : DL_SRC_US | UL_SRC_DS;
#endif
            break;
        case SPH_MODE_BT_CORDLESS:
        case SPH_MODE_LINEIN_VIA_BT_CORDLESS:
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
            v = DL_SRC_US | UL_SRC_DS;
#else   // chip compile option
            v = DL_SRC_US | UL_SRC_DS | BIT13;
#endif  // chip compile option
            break;
    }

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    v |= ((*DSP_SPH_SFE_CTRL) & 0xE00);
#else   // chip compile option
    v |= ((*DP_SCR_CTRL) & 0xE00);
#endif  // chip compile option
#endif //__VIBRATION_SPEAKER_SUPPORT__

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    *DSP_SPH_SFE_CTRL = v | ((*DSP_SPH_SFE_CTRL) & 0x1);
#else   // chip compile option
    L1Audio_Msg_AM_SRC1((*DP_SCR_CTRL), am.speech_mode, sph_mode);
    *DP_SCR_CTRL = v | ((*DP_SCR_CTRL) & 0x1);
    L1Audio_Msg_AM_SRC2((*DP_SCR_CTRL), am.speech_mode, sph_mode);
#endif  // chip compile option
    
    return;
}

void AM_SetSRCCtrl(void)
{
    AM_Enqueue(AM_DSP_SetSRCCtrl, 0, true);
    AM_FlushQFunction();
}
#endif  // chip compile option

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support DAI process
#else   // chip compile option
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static const uint16 DAITEST_CMD_TABLE[] =
{  0x8000,    /* 0: DAI TEST MODE 0  */
   0x0200,    /* 1: DAI TEST MODE 1  */
   0x0400,    /* 2: DAI TEST MODE 2  */
   0x0800,    /* 3: DAI TEST MODE 3  */
   0x1000,    /* 4: BT Cordless Mode */
   0x2000,    /* 5: BT Earphone Mode */
   0x8000,    /* 6: Speech Mode      */
   0x0000     /* 7: NOne             */
};

static void AM_DSP_SetDAIMode( uint32 mode )
{  
   ASSERT(false);
}

void AM_SetDAIMode ( uint8 mode )
{
   ASSERT(false);
}

bool AM_IsDAIMode( void )
{
   ASSERT(false);
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif  // chip compile option

static void AM_DSP_VMRecordOn( uint32 speech_mode )
{
    ASSERT_REBOOT(!am.afe_loopback_flag);   // Should not use AFE loopback and VM record at the same time
   if ((am.state & AM_STATE_AVSYNC) && (*DP_A2V_INT_ENABLE == 0))
      *DP_A2V_INT_ENABLE = 3;

   if( am.state & AM_STATE_SPEECH ) {       /* Conversation Recording */
      ASSERT(!(am.speech_state & SP_STATE_VMR));
      *DP_SC_FLAGS |= 0x0800;
      *E_CTRL_HO   |= 0x0008;         /* Enable DSP debugging information of VM */
      am.speech_state |= SP_STATE_VMR;
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(0) , L1AUDIO_Str_onoff(1) );
   }
   else if	( am.state & AM_STATE_VOIP ) {    /* VoIP Recording */
      ASSERT(!(am.voip_state & VOIP_STATE_VMR));   
      
      if (speech_mode>=0x03 && speech_mode<=0x0A) { /* AMR */           
         *DP_SC_MUTE |= 0x0002;         
         AM_WriteSpeechParameters( 0x0D33, speech_mode, speech_mode ); /* Turn on speech decoder */                      
      }      
      
      am.voip_state |= VOIP_STATE_VMR;
      
      L1Audio_Msg_AM_Switch( AM_Switch_Name(10), L1AUDIO_Str_onoff(1) );

   }   
   else {                                    /* VM in idle mode */
#if defined(__KARAOKE_SUPPORT__)
   if(!Media_IsKaraoke())
#endif      
#if defined(__VAD_SUPPORT__)
      if ( !VAD_IsEnable() )
#endif
      ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );
      
      
#if defined(AMRWB_ENCODE)
#if defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
      if(speech_mode>=0x20 && speech_mode<=0x28) { /* AMR-WB */
         *COMPEN_BLOCK_FLT_PAR_PTR &= ~( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
         *DP_AUDIO_PAR |= (VOICE_WB_AMR_FLAG);
                                           /* Set AMR-WB bit */
         *DP_AUDIO_PAR &= ~( VOICE_SIDETONE_FILTER_FLAG );    /* Turn off sidetone */
         *DP_16k_CompenFlt_Flag = 1;
#if DSP_16K_SIDETONE_SUPPORT       
         *AFE_VLB_CON |= (0x01<<3);                /* Bypass hardware IIR filter */
#endif
         *AFE_VMCU_CON1 &= ~0x0200;
      }
#elif defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      if(speech_mode>=0x20 && speech_mode<=0x28) { /* AMR-WB */
         *COMPEN_BLOCK_FLT_PAR_PTR &= ~( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
         *DP_AUDIO_PAR |= (VOICE_WB_AMR_FLAG);
                                           /* Set AMR-WB bit */
         *DP_AUDIO_PAR &= ~( VOICE_SIDETONE_FILTER_FLAG );    /* Turn off sidetone */
         *DP_16k_CompenFlt_Flag = 1;
         *DP_AUDIO_16K_PAR_PATCH |= 0x1;
#if DSP_16K_SIDETONE_SUPPORT
         *AFE_VLB_CON |= (0x01<<3);                /* Bypass hardware IIR filter */
#endif
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
         *DP_SCR_CTRL = 0x0;
#endif         
         *AFE_VMCU_CON1 &= ~0x0200;
      }
#endif      
      if (speech_mode>=0x20 && speech_mode<=0x28) { /* AMR-WB */
         AM_WriteSpeechParameters( 0x0D31, speech_mode, speech_mode ); /* Turn off speech decoder */
         AM_Write_Idle_Delay(0);
      } else 
#endif//#if defined(AMRWB_ENCODE)
      if (speech_mode>=0x03 && speech_mode<=0x0A) { /* AMR */
         *DP_SC_MUTE |= 0x0002;
//         AM_FillSilencePattern( DSP_RX_TCH_S0_0, 0, speech_mode );
         AM_WriteSpeechParameters( 0x0D33, speech_mode, speech_mode ); /* Turn on speech decoder */
         AM_Write_Idle_Delay(0);
#if DSP_16K_SIDETONE_SUPPORT
         *AFE_VLB_CON |= (0x01<<3);                /* Bypass hardware IIR filter */
#endif                  
         
         #if defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
         *DP_SCR_CTRL = 0x2;
         *AFE_VMCU_CON1 &= ~0x0200;                  //using wide band
         #else //using narrow band
         *AFE_VMCU_CON1 |= 0x0200;
         #endif    
      } else { /* Voice Memo */
         *DP_SC_MUTE |= 0x0002;
//         AM_FillSilencePattern( DSP_RX_TCH_S0_0, 0, speech_mode );
         AM_WriteSpeechParameters( 0x0D33, speech_mode, speech_mode );
         AM_Write_Speech_Delay( speech_mode, 0, 0 );
      }
	  am.state |= AM_STATE_VOICE;
	  am.DL_UL_path = SPH_VOICE_RECORD;
	  AFE_TurnOn8K();
      VBI_Reset();
      
      L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(1) );
   }
   
}

void AM_VMRecordOn( uint16 speech_mode )
{
   TONE_StopAndWait();
   KT_StopAndWait();
   DTMF_MCU_StopAndWait();

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   if(!(am.state & AM_STATE_SPEECH) && (speech_mode <= 0xA) && !(am.state & AM_STATE_VOIP) )
#if defined(__KARAOKE_SUPPORT__)
     if(!Media_IsKaraoke())
#endif
      DSP_DynamicDownload( DDID_NOISE_REDUCTION );
#endif

   if( (am.state & (AM_STATE_SPEECH|AM_STATE_VOIP)) == 0 ) /* Not in Conversation Recording */
   {         
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)  	
      AFE_Stop_and_Wait_DelayOff(L1SP_VOICE, ASP_FS_8K); 
#else
        {
            kal_uint8 DisIdleCount = 3;
            
            while (AFE_GetAfeSate() == 2)   // afe IdleOff state
            {
                AFE_Disable_IdleOffDelay();
                kal_sleep_task(3);
                DisIdleCount--;
                if (!DisIdleCount)
                {
                    break;
                }
            }
        }
#endif
   }

#if defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01)
   // Rewrite 16k compensation filter
   AM_Write16kCompensationFilter();
#endif

   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) 
   {
      AFE_TurnOnMicrophone( L1SP_LINEIN );
      //kal_sleep_task(AM_RECORD_SLEEP_TICK);
   }
   else {
      if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) )
      {  
         AFE_TurnOnMicrophone( L1SP_VOICE );
         //kal_sleep_task(AM_RECORD_SLEEP_TICK);
      }   
   }
   
   AM_Enqueue( AM_DSP_VMRecordOn, speech_mode, false );

   AM_FlushQFunction(); 
   if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) ) {
   		l1sp_updateSpeAppMask(0xffff, false);
   		if(speech_mode <= 0xA){
#if defined(__KARAOKE_SUPPORT__)
         if(!Media_IsKaraoke())
#endif   
	      l1sp_updateSpeAppMask(SPH_ENH_MASK_ULNR|SPH_ENH_MASK_AGC, true);
         SetSpeechEnhancement(true);
      //SPE_SetULNR(true);
      }
   }    
}


static void AM_DSP_VMRecordOff( uint32 data )
{
   (void)data;
   
   *E_CTRL_HO   &= ~0x0008;   /* Disable DSP debugging information of VM */

   if(am.speech_state & SP_STATE_VMR) /* Conversation Recording */
   {
      am.speech_state &= ~SP_STATE_VMR;
      *DP_SC_FLAGS &= ~0x0800;
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(0) , L1AUDIO_Str_onoff(0) );
   }
   else if	( am.voip_state & VOIP_STATE_VMR ) {    /* VoIP Recording */
      
      am.voip_state &= ~VOIP_STATE_VMR;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(10), L1AUDIO_Str_onoff(0) );       
      if( am.state == 0 ) {
         VBI_End();
         AFE_TurnOff8K();
      }  
      *DP_SC_MUTE &= ~0x0002;
      *DP_SC_FLAGS = 0x0000;      
            
   }   
   else  /* VM in idle mode */ 
   {         
      am.state &= ~AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(0) );                               
      if( am.state == 0 ) {
         VBI_End();
         AFE_TurnOff8K();
      }  
      *DP_SC_MUTE &= ~0x0002;
      *DP_SC_FLAGS = 0x0000;
#if defined(AMRWB_ENCODE)
#if defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
      *DP_AUDIO_PAR &= ~(VOICE_WB_AMR_FLAG);
                                            /* AMR-WB: Turn off AMR-WB */
      *DP_AUDIO_PAR |= VOICE_SIDETONE_FILTER_FLAG; /* Turn on DSP IIR and enable sidetone filter */
      *DP_16k_CompenFlt_Flag = 0;          /* Switch 16k compensation filter off */
      //*AFE_VLB_CON &= ~(0x01<<3);                /* don't Bypass hardware IIR filter */
      //*AFE_VMCU_CON1 |= 0x0200;
#elif defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      *DP_AUDIO_PAR &= ~(VOICE_WB_AMR_FLAG);
                                            /* AMR-WB: Turn off AMR-WB */
      *DP_AUDIO_PAR |= VOICE_SIDETONE_FILTER_FLAG; /* Turn on DSP IIR and enable sidetone filter */
      *DP_16k_CompenFlt_Flag = 0;          /* Switch 16k compensation filter off */
      *DP_AUDIO_16K_PAR_PATCH &= ~0x1;
      //*AFE_VLB_CON &= ~(0x01<<3);                 /* don't Bypass hardware IIR filter */
      //*AFE_VMCU_CON1 |= 0x0200;
#endif
#endif
   }
   am.DL_UL_path = SPH_BOTH_PATH;
}

void AM_VMRecordOff( void )
{
   if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) ) {
#if defined(__KARAOKE_SUPPORT__)
     if(!Media_IsKaraoke())
#endif
   	  SetSpeechEnhancement(false);
	  l1sp_updateSpeAppMask(0xffff, true);
      //SPE_SetULNR(false);
   }
   
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOffMicrophone( L1SP_LINEIN );
   }
   else {      
#if defined(__VAD_SUPPORT__)
      if ( !(am.state & (AM_STATE_VOIP | AM_STATE_PCMNWAY) ) )
#else
      if ( !(am.state & AM_STATE_VOIP) )
#endif
      AFE_TurnOffMicrophone( L1SP_VOICE );
   }
   AM_Enqueue( AM_DSP_VMRecordOff, 0, false );
   AM_FlushQFunction();
}

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support VM playback
#else   // chip compile option
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void AM_VMWriteParameter(uint16 sc_mode, uint16 sd_mode, bool isReset)
{
   if(sc_mode > 2) {
#if defined(MT6268) || defined(MT6236) || defined(MT6236B)
      // For 3G VM file, we have two SDs
      AM_WriteSpeechParameters( 0x2622, sc_mode, sd_mode );
#else
      /* For AMR speech playback, One SD only */   
      AM_WriteSpeechParameters( 0x1622, sc_mode, sd_mode );
#endif
      AM_Write_Idle_Delay(0);
   } else {
      AM_WriteSpeechParameters( 0x2622, sc_mode, sd_mode );
      AM_Write_Speech_Delay( sc_mode, 0, 0 );
   }
   
#if defined(AMRWB_DECODE)
#if defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   if(sc_mode>=0x20 && sc_mode<=0x28) {   /* AMR-WB Mode */
      *DP_AUDIO_PAR &= ~VOICE_SIDETONE_FILTER_FLAG;   /* disable sidetone filter */
      *DP_AUDIO_PAR |= (VOICE_WB_AMR_FLAG);            
                                     /* AMR-WB: Set AMR-WB bit */
      *DP_16k_CompenFlt_Flag = 1;
      //*AFE_VLB_CON |= (0x01<<3);                /* AMR-WB: Bypass hardware IIR filter  */
   }
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   if(sc_mode>=0x20 && sc_mode<=0x28) {   /* AMR-WB Mode */
      *DP_AUDIO_PAR &= ~VOICE_SIDETONE_FILTER_FLAG;   /* disable sidetone filter */
      *DP_AUDIO_PAR |= (VOICE_WB_AMR_FLAG);            
                                     /* AMR-WB: Set AMR-WB bit */
      *DP_16k_CompenFlt_Flag = 1;
      *DP_AUDIO_16K_PAR_PATCH |= 0x1;
      //*AFE_VLB_CON |= (0x01<<3);                /* AMR-WB: Bypass hardware IIR filter  */
   }
#endif
#endif

   // Disable the bit 10 of E_CTRL_HO before VM playback
   //   to avoid the abonrmal AMR playback just after power on
   *E_CTRL_HO &= ~0x0400;

   if (isReset)
      VBI_Reset();
}

static void AM_DSP_VMPlaybackOn( uint32 vm_control )
{
   uint16 sc_mode, sd_mode;
   uint32 style;

    ASSERT_REBOOT(!am.afe_loopback_flag);   // Should not use AFE loopback and VM playback at the same time
#if defined( __BT_AUDIO_VIA_SCO__ ) && !defined(__CVSD_CODEC_SUPPORT__)  //AMR/AWB can output via VBI and BT SCO link at the same time
      if (AM_IsBluetoothOn()){
   		*DP_VSBT_CTRL |= 0x1;
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#if defined(_FWE_SUPPORT_)  
         *DP_SCR_CTRL = 0x100;
#else
   	   *DP_SCR_CTRL = 0x4;
#endif   	   
#endif 
   	}
#endif
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   // FIX the speech hardware (AFE) on wide band
   *AFE_VMCU_CON1 &= ~0x0200; 
#endif

   ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );

   if ((am.state & AM_STATE_AVSYNC) && (*DP_A2V_INT_ENABLE == 0))
      *DP_A2V_INT_ENABLE = 3;

   /**
    * style:
    * bit0 : MEDIA_VMP_AS_SPEECH(0) or MEDIA_VMP_AS_RINGTONE(1)
    * bit1 : MEDIA_VMP_AMR(0) or MEDIA_VMP_AMR_WB(2)
    */
   style = vm_control >> 16;
   
   L1Audio_Msg_AM_Switch( AM_Switch_Name(7), L1AUDIO_Str_onoff(1) );

#if defined(AMRWB_DECODE)
   if ( (uint32)MEDIA_VMP_AMR_WB == (style&0x02)) {
      sc_mode = (vm_control>>2) & 0xFF;
      sd_mode = 0;
   } else
#endif
   { //narrow band
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
		//AFE hard ware is wideband AFE_VMCU_CON1[9] = 0'b. 
		//DSP internal works on narrow band.
		//DSP needs to do SR
   *DP_SCR_CTRL = 0x4;   
#endif 

      /* control --> | 4bit:sd_mode | 4bit:sc_mode | 1bit:DL | 1bit:UL | */
      sc_mode = (vm_control>>2) & 0xF;
      sd_mode = (vm_control>>6) & 0xF;
   }

   if( sc_mode == 0 )
      sc_mode = sd_mode;
   if( sd_mode == 0 )
      sd_mode = sc_mode;

   AM_VMWriteParameter(sc_mode, sd_mode, true);
   
   am.state |= AM_STATE_VOICE;
   am.DL_UL_path = SPH_VOICE_PLAYBACK;
   AFE_TurnOn8K();   
}

void AM_VMPlaybackOn( uint16 control, uint32 style )
{
	 AFE_Stop_and_Wait_DelayOff(L1SP_VOICE, ASP_FS_8K);
   if( !AM_IsSpeechOn() )
   {  // Download DSP SBC code
      uint16 amr_sd_mode = (control&0x3C) >> 2;
      uint16 awb_sd_mode = (control&0xFC) >> 2;
      if( (0x03<=amr_sd_mode && 0x0A>=amr_sd_mode) )
      {
         // DSP dynamic download should be done before setting Audio Flexile flag.
         //   Otherwise, 8k interrupt is avtive in keytone, then DSP jumps from ROM to RAM.
         //   At this time, the RAM may be wrong address
#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01) || defined(MT6253E) || defined(MT6253L)
          DSP_DynamicDownload( DDID_AMRSBC );
          *DSP_AUDIO_FLEXI_CTRL |= (FLEXI_VBI_ENABLE | FLEXI_SD_ENABLE);
#elif defined(AUDIO_AMR_RUNS_SPPECH_PATH_ON)
          DSP_DynamicDownload( DDID_NONE );   //sylvia remove AMRSBCDDID_AMRSBC
          *DSP_AUDIO_FLEXI_CTRL |= (FLEXI_VBI_ENABLE | FLEXI_SD_ENABLE);
#endif
      }
      (void)awb_sd_mode;

#if defined(__BES_TS_SUPPORT__) && !defined(__AUDIO_COMPONENT_SUPPORT__)
      *DP2_AUDIO_PP_CONTROL |= 0x0001;
      AudioPP_TS_Activate(true);
#endif



#if APM_SUPPORT
      if (0x20<=awb_sd_mode && 0x28>=awb_sd_mode)
         APM_Activate(ASP_TYPE_VOICE, ASP_FS_16K);
      else
         APM_Activate(ASP_TYPE_VOICE, ASP_FS_8K);
#endif
   }

   AM_Enqueue( AM_DSP_VMPlaybackOn, (style<<16) | control, false );
	AM_FlushQFunction(); 
	
	l1sp_updateSpeAppMask(0xffff, false);
   SetSpeechEnhancement(true);
   
   if( (uint32)MEDIA_VMP_AS_SPEECH == (style&0x01)) {
      AFE_TurnOnSpeaker( L1SP_SPEECH );
   }
   else { /* MEDIA_VMP_AS_RINGTONE */
      AFE_TurnOnSpeaker( L1SP_VOICE );
   }
}

static void AM_DSP_VMPlaybackOff( uint32 style )
{
   (void)style;

#if defined( __BT_AUDIO_VIA_SCO__ ) && !defined(__CVSD_CODEC_SUPPORT__)//AMR/AWB can output via VBI and BT SCO link at the same time
   if (AM_IsBluetoothOn()){
		*DP_VSBT_CTRL &= ~0x1;
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
		*DP_SCR_CTRL = 0x0;
#endif
	}
#endif
   
   L1Audio_Msg_AM_Switch( AM_Switch_Name(7), L1AUDIO_Str_onoff(0) );   

   am.state &= ~AM_STATE_VOICE;
   if( am.state == 0 ) 
      VBI_End();      
   
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
   *DP_SC_FLAGS   = 0x0000;
   am.DL_UL_path = SPH_BOTH_PATH;
   // Enable the bit 10 of E_CTRL_HO before VM playback
   //   to avoid the abonrmal AMR playback just after power on
   *E_CTRL_HO |= 0x0400;

#if defined(AMRWB_DECODE)
#if defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   *DP_AUDIO_PAR &= ~(VOICE_WB_AMR_FLAG);	
                                     /* AMR-WB: Turn off AMR-WB */
   *DP_AUDIO_PAR |= VOICE_SIDETONE_FILTER_FLAG; /* Enable sidetone filter */
   *DP_16k_CompenFlt_Flag = 0;
   //*AFE_VLB_CON &= ~(0x01<<3);      /* AMR-WB: if 8->16K IIR is done by H/W */
#elif defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *DP_AUDIO_PAR &= ~(VOICE_WB_AMR_FLAG);	
                                     /* AMR-WB: Turn off AMR-WB */
   *DP_AUDIO_PAR |= VOICE_SIDETONE_FILTER_FLAG; /* Enable sidetone filter */
   *DP_16k_CompenFlt_Flag = 0;
   *DP_AUDIO_16K_PAR_PATCH &= ~0x1;
   //*AFE_VLB_CON &= ~(0x01<<3);      /* AMR-WB: if 8->16K IIR is done by H/W */
#endif
#endif
}


void AM_VMPlaybackOff( uint32 style )
{
   SetSpeechEnhancement(false);
	l1sp_updateSpeAppMask(0xffff, true);   
#if APM_SUPPORT
   APM_Deactivate();
#endif

   if( (uint32)MEDIA_VMP_AS_SPEECH == (style & 0x01)) {
      AFE_TurnOffSpeaker( L1SP_SPEECH );
   }
   else {    /* MEDIA_VMP_AS_RINGTONE */
      AFE_TurnOffSpeaker( L1SP_VOICE );
   }
#if defined(__BT_A2DP_PROFILE__) && !defined(SBC_UNIT_TEST)
   SBC_Close();
#endif


#if defined(__BES_TS_SUPPORT__) && !defined(__AUDIO_COMPONENT_SUPPORT__)
   AudioPP_Close();
#endif

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *DSP_AUDIO_FLEXI_CTRL &= ~(FLEXI_VBI_ENABLE | FLEXI_SD_ENABLE);
#endif

   AM_Enqueue( AM_DSP_VMPlaybackOff, style, false );
   /* Resume Digital Gain for Speech Mode */
   AFE_SetDigitalGain( L1SP_VOICE, 100 );
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif  // chip compile option

static void AM_DSP_Melody( uint32 data )
{
    ASSERT(false);
}

void AM_MelodyOn( void )
{
   ASSERT(false);
}

void AM_MelodyOff( void )
{
    ASSERT(false);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_KeyToneOn( uint32 data )
{
   (void)data;
   ASSERT(!(am.state & AM_STATE_KEYTONE));
   L1Audio_Msg_AM_Switch( AM_Switch_Name(0), L1AUDIO_Str_onoff(1) );
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   if(!AM_IsSpeechOn()) {
   	  // AFE hard ware is wideband AFE_VMCU_CON1[9] = 0'b. 
		  // DSP internal works on narrow band.
		  // DSP needs to do SRC		  
      *AFE_VMCU_CON1 &= ~0x0200;
      *DP_SCR_CTRL = 0x4;
   }
#endif
   am.state |= AM_STATE_KEYTONE;
   am.DL_UL_path = SPH_TONE;
   AFE_TurnOn8K();
   if( (am.state & ~AM_STATE_AVSYNC) == 0 ) { 
      AM_Write_Idle_Delay(4);
      VBI_Reset();
   }
   
}

void AM_KeyToneOn( void )
{
   #if defined(MT6251) || defined(MT6256) || defined(MT6255)
   kal_uint8 delay4DCOffSet;
   kal_int16 DCOffSet;
   #endif

   AFE_Stop_and_Wait_DelayOff(L1SP_KEYTONE, ASP_FS_8K);
#if defined(MT6236) || defined(MT6236B) || defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   if(AM_IsSpeechOn())
   {
      AM_Enqueue( AM_DSP_KeyToneOn, 0, false );
      AFE_TurnOnSpeaker( L1SP_KEYTONE );
   }
   else
   {
#if defined(__GAIN_TABLE_SUPPORT__)
      kal_uint32 total_gain, silence_gain;
      total_gain = AFE_GetOutputGainControl(L1SP_KEYTONE);
      silence_gain = (total_gain & 0x0003FFFF) | 0x04000000;
      AFE_SetOutputGainControl(L1SP_KEYTONE, silence_gain);
#else   
      kal_uint8 vol1;
      kal_int8 dgain_index;
      AFE_GetOutputVolume(L1SP_KEYTONE, &vol1, &dgain_index);
      if (vol1 != 0)
      {
         AFE_SetOutputVolume(L1SP_KEYTONE, 1, dgain_index);
      }
#endif   
      AFE_TurnOnSpeaker( L1SP_KEYTONE );
      kal_sleep_task(3);
      AM_Enqueue( AM_DSP_KeyToneOn, 0, false );
      AM_FlushQFunction();
      
#if defined(__GAIN_TABLE_SUPPORT__)   
      AFE_SetOutputGainControl(L1SP_KEYTONE, total_gain);
#else
      AFE_SetOutputVolume(L1SP_KEYTONE, vol1, dgain_index);
#endif
   }
#elif defined(MT6251) || defined(MT6256) || defined(MT6255)
   DCOffSet = AFE_GetDCOffSet();
   if(DCOffSet<0)
      DCOffSet = 0 - DCOffSet;
   delay4DCOffSet = 1 + (DCOffSet / DCOffSetRampUpSetp) + 1 + (DCOffSet / DCOffSetRampDnSetp) + 1;
   
   AM_Enqueue( AM_DSP_KeyToneOn, 0, false );
   AM_FlushQFunction();
   //kal_sleep_task(1);
   AFE_TurnOnSpeaker( L1SP_KEYTONE );
   if(AFE_GetOutputDevice(L1SP_KEYTONE) & L1SP_BUFFER_EXT)
         kal_sleep_task(2/*delay4DCOffSet*/); //for dc compensation  
   else
         kal_sleep_task(1);
#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   AM_Enqueue( AM_DSP_KeyToneOn, 0, false );
   AM_FlushQFunction();
   AFE_TurnOnSpeaker( L1SP_KEYTONE );
#else
   AM_Enqueue( AM_DSP_KeyToneOn, 0, false );
   AFE_TurnOnSpeaker( L1SP_KEYTONE );
#endif
}

static void AM_DSP_KeyToneOff( uint32 data )
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(0), L1AUDIO_Str_onoff(0) );
   am.state &= ~AM_STATE_KEYTONE;

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   if(am.state==0)
#endif 	
   {
      if(( am.state == 0 ) || ((am.state & ~AM_STATE_AVSYNC)==0 && (*DP_A2V_INT_ENABLE == 0)))
         VBI_End();      
      
      if( (am.state & ~AM_STATE_AUDIO) == 0 )
         AFE_TurnOff8K();
   }
   am.DL_UL_path = SPH_BOTH_PATH;
}

void AM_KeyToneOff( void )
{
   AFE_TurnOffSpeaker( L1SP_KEYTONE );
   AM_Enqueue( AM_DSP_KeyToneOff, 0, false );
}

bool AM_IsKeyToneOn( void )
{
   if (am.state & AM_STATE_KEYTONE)
      return true;
   return false;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_ToneOn( uint32 data )
{
   (void)data;
   ASSERT(!(am.state & AM_STATE_TONE));
   L1Audio_Msg_AM_Switch( AM_Switch_Name(1), L1AUDIO_Str_onoff(1) );
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   if(!AM_IsSpeechOn()) {
   	  // AFE hard ware is wideband AFE_VMCU_CON1[9] = 0'b. 
		  // DSP internal works on narrow band.
		  // DSP needs to do SRC		  
      *AFE_VMCU_CON1 &= ~0x0200;
      *DP_SCR_CTRL = 0x4;
   }
#endif
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   if( AM_IsAudioPlaybackOn()== -1 )
#endif
   am.state |= AM_STATE_TONE;
   am.DL_UL_path = SPH_TONE;
      AFE_TurnOn8K();
   if( (am.state & ~AM_STATE_AVSYNC) == 0) {          
      AM_Write_Idle_Delay(4);
      VBI_Reset();
   }
   
}

void AM_ToneOn( void )
{
    AFE_Stop_and_Wait_DelayOff(L1SP_TONE, ASP_FS_8K);
    
#if defined(MT6236) || defined(MT6236B) || defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
#if defined(__GAIN_TABLE_SUPPORT__)
    {
        kal_uint32 total_gain   = AFE_GetOutputGainControl(L1SP_TONE); 
        kal_uint32 silence_gain = (total_gain & 0x0003FFFF) | 0x04000000;
        AFE_SetOutputGainControl(L1SP_TONE, silence_gain);
        AFE_TurnOnSpeaker( L1SP_TONE );
        kal_sleep_task(3);
        AM_Enqueue( AM_DSP_ToneOn, 0, false );
        AM_FlushQFunction();
        AFE_SetOutputGainControl(L1SP_TONE, total_gain);
    }
#else
    {
        kal_uint8 vol1 = 0;
        kal_int8 dgain_index = 0;
        AFE_GetOutputVolume(L1SP_TONE, &vol1, &dgain_index);
        if (vol1 != 0)
        {
            AFE_SetOutputVolume(L1SP_TONE, 1, dgain_index);
        }
        AFE_TurnOnSpeaker( L1SP_TONE );
        kal_sleep_task(3);
        AM_Enqueue( AM_DSP_ToneOn, 0, false );
        AM_FlushQFunction();
        AFE_SetOutputVolume(L1SP_TONE, vol1, dgain_index);
    }
#endif
#elif defined(MT6251) || defined(MT6256) || defined(MT6255)
    {
        // kal_uint8 delay4DCOffSet;
        kal_int16 DCOffSet = AFE_GetDCOffSet();
        if (DCOffSet < 0)
        {
            DCOffSet = 0 - DCOffSet;
        }
        
        //delay4DCOffSet = 1 + (DCOffSet / DCOffSetRampUpSetp) + 1 + (DCOffSet / DCOffSetRampDnSetp) + 1;
        
        AM_Enqueue(AM_DSP_ToneOn, 0, false);
        AM_FlushQFunction();
        AFE_TurnOnSpeaker(L1SP_TONE);
        if (AFE_GetOutputDevice(L1SP_TONE) & L1SP_BUFFER_EXT)
        {   // For DC compensation
            kal_sleep_task(2);  // Sleep 2 ticks instead of delay4DCOffSet
        }
        else
        {
            kal_sleep_task(1);
        }
    }
#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    AM_Enqueue(AM_DSP_ToneOn, 0, false);
    AM_FlushQFunction();
    kal_sleep_task(1);
    AFE_TurnOnSpeaker(L1SP_TONE);
#else
    AM_Enqueue(AM_DSP_ToneOn, 0, false);
    AFE_TurnOnSpeaker(L1SP_TONE);
#endif
}

static void AM_DSP_ToneOff( uint32 data )
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(1), L1AUDIO_Str_onoff(0) );
   am.state &= ~AM_STATE_TONE;

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   if(am.state==0)   
#endif 	
   {  
      if(( am.state == 0 ) || ((am.state & ~AM_STATE_AVSYNC)==0 && (*DP_A2V_INT_ENABLE == 0)))
         VBI_End();     
      
      if( (am.state & ~AM_STATE_AUDIO) == 0 )
         AFE_TurnOff8K();
   }
   am.DL_UL_path = SPH_BOTH_PATH;
}

void AM_ToneOff( void )
{
   AFE_TurnOffSpeaker( L1SP_TONE ); 
   AM_Enqueue( AM_DSP_ToneOff, 0, false );
}

bool AM_IsToneOn( void )
{
   if (am.state & AM_STATE_TONE)
      return true;
   return false;
}


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_PCM8K_PlaybackOn( uint32 data )
{
   (void)data;

   if ((am.state & AM_STATE_AVSYNC) && (*DP_A2V_INT_ENABLE == 0))
      *DP_A2V_INT_ENABLE = 3;
   
   
#ifdef BGSND_ENABLE
   if ( data == 1 )
   {
      ASSERT(!(am.state & AM_STATE_SND_EFFECT));
      am.state |= AM_STATE_SND_EFFECT;                                    
      L1Audio_Msg_AM_Switch( AM_Switch_Name(9), L1AUDIO_Str_onoff(1) );         
   }
   else
#endif /* ...BGSND_ENABLE */
   {
        ASSERT_REBOOT(!am.afe_loopback_flag);   // Should not use AFE loopback and PCM 8k playbck at the same time
      ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );       
      am.state |= AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(2), L1AUDIO_Str_onoff(1) );
   }
   am.DL_UL_path = SPH_VOICE_PLAYBACK;
   AFE_TurnOn8K();
   if( am.state == 0 ) {            
      AM_Write_Idle_Delay(2);
      VBI_Reset();
   }
}

void AM_PCM8K_PlaybackOn( void )
{
   AFE_Stop_and_Wait_DelayOff(L1SP_VOICE, ASP_FS_8K);
   AM_Enqueue( AM_DSP_PCM8K_PlaybackOn, 0, false );
   if(!(am.state & AM_STATE_SPEECH))
      AFE_TurnOnSpeaker( L1SP_VOICE );

   AM_FlushQFunction();
	
	l1sp_updateSpeAppMask(0xffff, false);
   SetSpeechEnhancement(true);   
}

static void AM_DSP_PCM8K_PlaybackOff( uint32 data )
{
   (void)data;
	   
#ifdef BGSND_ENABLE
   if( data == 1 )
   {
      am.state &= ~AM_STATE_SND_EFFECT;                  
      L1Audio_Msg_AM_Switch( AM_Switch_Name(9), L1AUDIO_Str_onoff(0) );         
   }
   else
#endif /* ...BGSND_ENABLE */
   {      
      am.state &= ~AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(2), L1AUDIO_Str_onoff(0) );
   }
   if( am.state == 0 ) 
      VBI_End();      
   
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
   am.DL_UL_path = SPH_BOTH_PATH;
}

void AM_PCM8K_PlaybackOff( bool wait )
{
   SetSpeechEnhancement(false);
   l1sp_updateSpeAppMask(0xffff, true);  
	   
   AFE_TurnOffSpeaker( L1SP_VOICE );
   AM_Enqueue( AM_DSP_PCM8K_PlaybackOff, 0, false );
   
   if( wait ) 
      AM_FlushQFunction();
      
   /* for unmute after TTS stop */      
   kal_sleep_task(2);  // wait until AFE_Event_Handler process AFE_TurnOffSpeaker( L1SP_AUDIO ), then do the unmute
   AFE_SetHardwareMute(false);                 
}

#ifdef BGSND_ENABLE
bool AM_IsBgsndOn( void ){
   if (am.state & AM_STATE_SND_EFFECT)
      return true;
   return false;
}
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_PCM16K_PlaybackOn( uint32 data )
{
   (void)data;
    ASSERT_REBOOT(!am.afe_loopback_flag);   // Should not use AFE loopback and PCM 16k playback at the same time
   ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 
   L1Audio_Msg_AM_Switch( AM_Switch_Name(3), L1AUDIO_Str_onoff(1) );

   if ((am.state & AM_STATE_AVSYNC) && (*DP_A2V_INT_ENABLE == 0))
      *DP_A2V_INT_ENABLE = 3;
   
   *DP_AUDIO_PAR |= VOICE_WB_AMR_FLAG;               
   AM_Write_Idle_Delay(3);   
   am.state |= AM_STATE_VOICE;
   am.DL_UL_path = SPH_VOICE_PLAYBACK;
   AFE_TurnOn8K();   
   VBI_Reset();
   
   
}

void AM_PCM16K_PlaybackOn( void )
{
	 AFE_Stop_and_Wait_DelayOff(L1SP_VOICE, ASP_FS_8K);
   AM_Enqueue( AM_DSP_PCM16K_PlaybackOn, 0, false );
   AFE_TurnOnSpeaker( L1SP_VOICE );

   AM_FlushQFunction();
		
	l1sp_updateSpeAppMask(0xffff, false);
   SetSpeechEnhancement(true);   
}

static void AM_DSP_PCM16K_PlaybackOff( uint32 data )
{
   (void)data;
	   
   L1Audio_Msg_AM_Switch( AM_Switch_Name(3), L1AUDIO_Str_onoff(0) );
   
   am.state &= ~AM_STATE_VOICE;
   *DP_AUDIO_PAR &= ~VOICE_WB_AMR_FLAG;
   if( am.state == 0 ) 
      VBI_End();     
   
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
   am.DL_UL_path = SPH_BOTH_PATH;
}

void AM_PCM16K_PlaybackOff( bool wait )
{
   SetSpeechEnhancement(false);
   l1sp_updateSpeAppMask(0xffff, true);   
	   
   AFE_TurnOffSpeaker( L1SP_VOICE );
   AM_Enqueue( AM_DSP_PCM16K_PlaybackOff, 0, false );
   
   if( wait )
      AM_FlushQFunction();
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

uint32 AM_GetRecordFormat(){
   return am.record_format;
}

static void AM_DSP_PCM16K_RecordOn( uint32 data )
{
   (void)data;
#if defined(__KARAOKE_SUPPORT__)
   if(!Media_IsKaraoke())
#endif
    // ASSERT_REBOOT(!am.afe_loopback_flag); // This line is commented since PCM 16k record is allowed to be concurrent with AFE loopback
   ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );
   am.record_format = AM_RECORD_16K;

   if ((am.state & AM_STATE_AVSYNC) && (*DP_A2V_INT_ENABLE == 0))
      *DP_A2V_INT_ENABLE = 3;

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   if(BT_EARPHONE_MODE == am.io_type)
      *DP_SCR_CTRL = 0x80;
   else   
      *DP_SCR_CTRL = 0x0;
#endif

#if defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   *COMPEN_BLOCK_FLT_PAR_PTR &= ~( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
   *DP_AUDIO_PAR |= (VOICE_WB_AMR_FLAG);
   *DP_AUDIO_PAR &= ~( VOICE_SIDETONE_FILTER_FLAG );
   *DP_16k_CompenFlt_Flag = 1;
#if DSP_16K_SIDETONE_SUPPORT
   *AFE_VLB_CON |= (0x01<<3);                /* Bypass hardware IIR filter*/
#endif
   *AFE_VMCU_CON1 &= ~0x0200;
#elif  defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *COMPEN_BLOCK_FLT_PAR_PTR &= ~( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
   *DP_AUDIO_PAR |= (VOICE_WB_AMR_FLAG);
   *DP_AUDIO_PAR &= ~( VOICE_SIDETONE_FILTER_FLAG );
   *DP_16k_CompenFlt_Flag = 1;
   *DP_AUDIO_16K_PAR_PATCH |= 0x1;
#if DSP_16K_SIDETONE_SUPPORT
   *AFE_VLB_CON |= (0x01<<3);                /* Bypass hardware IIR filter*/
#endif
   *AFE_VMCU_CON1 &= ~0x0200;
#endif      
   *DP_SC_MUTE |= 0x0002;
   *DP_SC_FLAGS = 0x0D00; //disable speech coder
   
   AM_Write_Idle_Delay(3);//16K PCM
  
   am.state |= AM_STATE_VOICE;
   am.DL_UL_path = SPH_VOICE_RECORD;
   AFE_TurnOn8K();
   VBI_Reset();
   
   L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(1) );
}

void AM_PCM16K_RecordOn( void )
{
   TONE_StopAndWait();
   KT_StopAndWait();
   DTMF_MCU_StopAndWait();

   ASSERT( !( am.state & AM_STATE_SPEECH ) );
#if DSP_16K_SIDETONE_SUPPORT
   if(!(am.state & AM_STATE_SPEECH) )
#if defined(MT6268) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252) || defined(MT6251)
      DSP_DynamicDownload( DDID_NOISE_REDUCTION );
#else
#if defined(__KARAOKE_SUPPORT__)
      if(!Media_IsKaraoke())
#endif
#if DPCHIP_DDL_AWB && ( defined(AMRWB_DECODE) || defined(AMRWB_ENCODE) )
      DSP_DynamicDownload( DDID_AWB );
#else
      DSP_DynamicDownload( DDID_NOISE_REDUCTION );     
#endif
#endif
#endif

#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      AFE_Stop_and_Wait_DelayOff(L1SP_VOICE, ASP_FS_8K);
#else
   if( (am.state & AM_STATE_SPEECH) == 0 ) /* Not in Conversation Recording */
   {
        kal_uint8 DisIdleCount = 3;
        
        while (AFE_GetAfeSate() == 2)   // afe IdleOff state
        {
            AFE_Disable_IdleOffDelay();
            kal_sleep_task(3);
            DisIdleCount--;
            if (!DisIdleCount)
            {
                break;
            }
        }
   }
#endif
#if defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01)
   AM_Write16kCompensationFilter();
#endif

   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) 
   {
      AFE_TurnOnMicrophone( L1SP_LINEIN );
      //kal_sleep_task(AM_RECORD_SLEEP_TICK);
   }
   else
   {
      AFE_TurnOnMicrophone( L1SP_VOICE );
      //kal_sleep_task(AM_RECORD_SLEEP_TICK);
   }

   AM_Enqueue( AM_DSP_PCM16K_RecordOn, 0, false );
   AM_FlushQFunction();

#if defined(__KARAOKE_SUPPORT__)
      if(Media_IsKaraoke())
      {
      	 return;
      }	
#endif      
      	
   if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) ) {
#if defined(__BT_SUPPORT__)
      if(!AM_IsBTCordlessMode()) 
#endif
      {
#ifdef WB_SPE_SUPPORT    
      l1sp_updateSpeAppMask(0xffff, false);
      l1sp_updateSpeAppMask(SPH_ENH_MASK_ULNR|SPH_ENH_MASK_AGC, true);
      SetSpeechEnhancement(true);
      //SPE_SetULNR(true);
#else // no wb speech enhancement support. 
      l1sp_updateSpeAppMask(0xffff, false);
      l1sp_updateSpeAppMask(SPH_ENH_MASK_AGC, true);
      SetSpeechEnhancement(true);
#endif //WB_SPE_SUPPORT
    
      }
   }

}

static void AM_DSP_PCM16K_RecordOff( uint32 data )
{
   (void)data;

   am.state &= ~AM_STATE_VOICE;
   am.record_format = AM_RECORD_NONE;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(0) );                               
   if( am.state == 0 ) {
      VBI_End();
      AFE_TurnOff8K();
   }  
   am.DL_UL_path = SPH_BOTH_PATH;
   *DP_SC_MUTE &= ~0x0002;
   *DP_SC_FLAGS = 0x0000;

#if defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   *COMPEN_BLOCK_FLT_PAR_PTR |= ( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
   *DP_AUDIO_PAR &= ~(VOICE_WB_AMR_FLAG);
                                            /* AMR-WB: Turn off AMR-WB */
   *DP_AUDIO_PAR |= VOICE_SIDETONE_FILTER_FLAG;
   *DP_16k_CompenFlt_Flag = 0;          /* Switch 16k compensation filter off */
   //*AFE_VLB_CON &= ~(0x01<<3);                 /* AMR-WB: if 8->16K IIR is done by H/W */
   //*AFE_VMCU_CON1 |= 0x0200;
#elif defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *COMPEN_BLOCK_FLT_PAR_PTR |= ( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
   *DP_AUDIO_PAR &= ~(VOICE_WB_AMR_FLAG);
                                            /* AMR-WB: Turn off AMR-WB */
   *DP_AUDIO_PAR |= VOICE_SIDETONE_FILTER_FLAG;
   *DP_16k_CompenFlt_Flag = 0;          /* Switch 16k compensation filter off */
   *DP_AUDIO_16K_PAR_PATCH &= ~0x1;
   //*AFE_VLB_CON &= ~(0x01<<3);                 /* AMR-WB: if 8->16K IIR is done by H/W */
   //*AFE_VMCU_CON1 |= 0x0200;
#endif

}

void AM_PCM16K_RecordOff( bool wait )
{
   ASSERT( !( am.state & AM_STATE_SPEECH ) );


   if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) ) {
#if defined(__BT_SUPPORT__)
      if(!AM_IsBTCordlessMode()) 
#endif
      {
      	SetSpeechEnhancement(false);
#ifdef WB_SPE_SUPPORT          
      ////SPE_SetULNR(false);
	  l1sp_updateSpeAppMask(0xffff, true);
#else //no wb speech enhancement
      l1sp_updateSpeAppMask(0xffff, true);
#endif //WB_SPE_SUPPORT

      }
   }


   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOffMicrophone( L1SP_LINEIN );
   }
   else {      
#if defined(__VAD_SUPPORT__)
      if (!(am.state & AM_STATE_PCMNWAY))
#endif
         AFE_TurnOffMicrophone( L1SP_VOICE );
   }
   AM_Enqueue( AM_DSP_PCM16K_RecordOff, 0, false );
   
   if( wait )
      AM_FlushQFunction();
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_PCM8K_RecordOn(uint32 data)
{
    (void)data;
    // ASSERT_REBOOT(!am.afe_loopback_flag); // This line is commented since PCM 8k record is allowed to be concurrent with AFE loopback
    if ((am.state & AM_STATE_AVSYNC) && (*DP_A2V_INT_ENABLE == 0))
    {
        *DP_A2V_INT_ENABLE = 3;
    }
    
    am.record_format = AM_RECORD_8K;
    
    if ( (am.state & AM_STATE_SPEECH)
#if defined (__BT_DIALER_SUPPORT__)
          || (am.state & AM_STATE_VOIP )
#endif      	
    )
    {   // Conversation Recording
        ASSERT(!(am.speech_state & SP_STATE_PCM8K_REC));
        *DP_TCH_PCM_REC_ENA |= 0x0001;
        am.speech_state |= SP_STATE_PCM8K_REC;
        L1Audio_Msg_AM_SetSpeech(AM_Speech_Feature_Name(1), L1AUDIO_Str_onoff(1));
    }
    else
    {
#if defined(__KARAOKE_SUPPORT__)
        if(!Media_IsKaraoke())
        {
            ASSERT_REBOOT(!(am.state & AM_CONFLICT_STATE));
        }
#else
        ASSERT_REBOOT(!(am.state & AM_CONFLICT_STATE));
#endif   	

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
        *DP_TCH_PCM_REC_ENA |= 0x0001;
#endif  // chip compile option
        
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#if defined(__KARAOKE_SUPPORT__)
        if (Media_IsKaraoke())
        {
            *DP_SCR_CTRL = 0x0;
        }
        else
#endif
        {
            *DP_SCR_CTRL = BT_EARPHONE_MODE == am.io_type ? 0x0 : 0x2;
            *AFE_VMCU_CON1 &= ~0x0200;
	    }
#else
        *AFE_VMCU_CON1 |= 0x0200;
#endif  
        
        *DP_SC_MUTE |= 0x0002;
        *DP_SC_MODE =  0x0000; // Dummy set to DSP FR Speech Decoder
        *DP_SC_FLAGS|= 0x0022; // Dummy Enable DSP SD Task Since DP_SC_MUTE is set to 2
        AM_Write_Idle_Delay(2);
		am.state |= AM_STATE_VOICE;
		am.DL_UL_path = SPH_VOICE_RECORD;
        AFE_TurnOn8K();
        VBI_Reset();
        
        L1Audio_Msg_AM_Switch(AM_Switch_Name(4), L1AUDIO_Str_onoff(1));
#if DSP_16K_SIDETONE_SUPPORT
        *AFE_VLB_CON |= (0x01<<3);  // Bypass hardware IIR filter
#endif
    }
    
    return;
}

void AM_PCM8K_RecordOn( void )
{
    TONE_StopAndWait();
    KT_StopAndWait();
    DTMF_MCU_StopAndWait();
    
    if (   !(am.state & AM_STATE_SPEECH)
#if defined(__BT_SUPPORT__)
        && !AM_IsBTCordlessMode()
#endif
#if defined(__KARAOKE_SUPPORT__)
        && !Media_IsKaraoke()
#endif
       )
    {
        DSP_DynamicDownload(DDID_NOISE_REDUCTION);
    }
    
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    AFE_Stop_and_Wait_DelayOff(L1SP_VOICE, ASP_FS_8K);
#else
    if ((am.state & AM_STATE_SPEECH) == 0)  // Not in Conversation Recording
    {
        kal_uint8 DisIdleCount = 3;
        
        while (AFE_GetAfeSate() == 2)   // afe IdleOff state
        {
            AFE_Disable_IdleOffDelay();
            kal_sleep_task(3);
            DisIdleCount--;
            if (!DisIdleCount)
            {
                break;
            }
        }
    }
#endif

   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) 
   {
      AFE_TurnOnMicrophone( L1SP_LINEIN );
      //kal_sleep_task(AM_RECORD_SLEEP_TICK);
   }
   else {
      if(!(am.state & AM_STATE_SPEECH))
      {
         AFE_TurnOnMicrophone( L1SP_VOICE );
         //kal_sleep_task(AM_RECORD_SLEEP_TICK);
      }   
   }
   
   AM_Enqueue( AM_DSP_PCM8K_RecordOn, 0, false );
   AM_FlushQFunction();

   if(!(am.state & AM_STATE_SPEECH))
#if defined(__BT_SUPPORT__)
      if(!AM_IsBTCordlessMode())
#endif
#if defined(__KARAOKE_SUPPORT__)
        if(!Media_IsKaraoke())
#endif
         {
            //SPE_SetULNR(true);   
            l1sp_updateSpeAppMask(0xffff, false);
            l1sp_updateSpeAppMask(SPH_ENH_MASK_ULNR|SPH_ENH_MASK_AGC, true);
            SetSpeechEnhancement(true);
         }
}

static void AM_DSP_PCM8K_RecordOff(uint32 data)
{
    (void)data;
    
    am.record_format = AM_RECORD_NONE;
    
    if (am.speech_state & SP_STATE_PCM8K_REC)
    {
        am.speech_state &= ~SP_STATE_PCM8K_REC;
        *DP_TCH_PCM_REC_ENA &= ~0x0001; // Disable DSP control bit for WAV record in TCH mode
        L1Audio_Msg_AM_SetSpeech(AM_Speech_Feature_Name(1), L1AUDIO_Str_onoff(0));
    }
    else
    {
        am.state &= ~AM_STATE_VOICE;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
        *DP_TCH_PCM_REC_ENA &= ~0x0001;
#endif  // chip compile option
        *DP_SC_FLAGS &= ~0x0022;
        *DP_SC_MUTE &= ~0x0002;
        L1Audio_Msg_AM_Switch(AM_Switch_Name(4), L1AUDIO_Str_onoff(0));
    }
    
    if (am.state == 0)
    {
        VBI_End();
    }
    
    if ((am.state & ~AM_STATE_AUDIO) == 0)
    {
        AFE_TurnOff8K();
    }
    am.DL_UL_path = SPH_BOTH_PATH;
    return;
}

void AM_PCM8K_RecordOff( bool wait )
{
   if(!(am.state & AM_STATE_SPEECH))
#if defined(__BT_SUPPORT__)
      if(!AM_IsBTCordlessMode())
#endif
#if defined(__KARAOKE_SUPPORT__)
        if(!Media_IsKaraoke())
#endif
      {
      //SPE_SetULNR(false);        
        SetSpeechEnhancement(false);
	    l1sp_updateSpeAppMask(0xffff, true);
      }
   
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOffMicrophone( L1SP_LINEIN );
   }
   else {      
#if defined(__VAD_SUPPORT__)
      if(!(am.state & (AM_STATE_SPEECH | AM_STATE_PCMNWAY)))
#else
      if(!(am.state & AM_STATE_SPEECH))
#endif
      	{
         AFE_TurnOffMicrophone( L1SP_VOICE );
      	}
   }
   AM_Enqueue( AM_DSP_PCM8K_RecordOff, 0, false );
   
   if( wait )
      AM_FlushQFunction();
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
static void AM_DSP_VM_EPL_RecordOn(uint32 data)
{
    (void)data;
    
    if (am.state & AM_STATE_SPEECH)
    {   // Conversation Recording
        ASSERT(!(am.speech_state & SP_STATE_VM_EPL_REC));
        *DP_TCH_PCM_REC_ENA |= 0x0002;
        am.speech_state |= SP_STATE_VM_EPL_REC;
        L1Audio_Msg_AM_SetSpeech(AM_Speech_Feature_Name(4), L1AUDIO_Str_onoff(1));
    }
    else
    {
        ASSERT(0);
    }
    
    return;
}

void AM_VM_EPL_RecordOn(void)
{
    TONE_StopAndWait();
    KT_StopAndWait();
    DTMF_MCU_StopAndWait();
    
    AM_Enqueue(AM_DSP_VM_EPL_RecordOn, 0, false);
    AM_FlushQFunction();
    return;
}

static void AM_DSP_VM_EPL_RecordOff(uint32 data)
{
    (void)data;
    
    if (am.speech_state & SP_STATE_VM_EPL_REC)
    {
        am.speech_state &= ~SP_STATE_VM_EPL_REC;
        *DP_TCH_PCM_REC_ENA &= ~0x0002;
        L1Audio_Msg_AM_SetSpeech(AM_Speech_Feature_Name(4), L1AUDIO_Str_onoff(0));
    }
    else
    {
        ASSERT(0);
    }
    
    return;
}

void AM_VM_EPL_RecordOff(void)
{
    AM_Enqueue(AM_DSP_VM_EPL_RecordOff, 0, false);
    AM_FlushQFunction();
    return;
}
#endif  // chip compile option

static void AM_DSP_AudioPlaybackOn( uint32 data )
{
   kal_uint16 asp_type, asp_fs, isr_cycle = 0, del_m = 0, del_w = 0x20, uFrameLen = ASP_FRAMELEN_PCM;
   kal_uint8 uSDInterruptNumber = 1;
    ASSERT_REBOOT(!am.afe_loopback_flag);   // Should not use AFE loopback and audio playback at the same time
   ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 
   asp_type = (kal_uint16)(data>>16);
   asp_fs = (kal_uint16)data;
    if ((am.state & AM_STATE_AVSYNC) && (*DP_A2V_INT_ENABLE == 0))
    {
        //extern void Media_A2V_AddFirstFrameInterruptDelay(kal_uint16 asp_type);
        //Media_A2V_AddFirstFrameInterruptDelay(asp_type);
        *DP_A2V_INT_ENABLE = 3;
    }

   switch( asp_type )
   {
      case ASP_TYPE_PCM_HI:
      case ASP_TYPE_IPS:
         del_m = ASP_DELM_PCM_HIGFS;
         if(((*DP2_AUDIO_PP_CONTROL)&0x0020) == 0)
         {
            if((asp_fs&0xFF)<=ASP_FS_12K)
            {
               del_m = ASP_DELM_PCM_LOWFS;        
            }
            else if((asp_fs&0xFF)<=ASP_FS_24K)
            {
               del_m = ASP_DELM_PCM_MEDFS;              
            }
         }
         #if defined(__KARAOKE_SUPPORT__)         
         if(Media_IsKaraoke())
         {
            switch (asp_fs&0xFF)
            {
            	  case ASP_FS_8K:  uFrameLen =  480;  break;
                case ASP_FS_11K: uFrameLen =  660;  break;
                case ASP_FS_12K: uFrameLen =  720;  break;
                case ASP_FS_16K: uFrameLen =  960;  break;
                case ASP_FS_22K: uFrameLen = 1320;  break;
                case ASP_FS_24K: uFrameLen = 1440;  break;
                case ASP_FS_32K: uFrameLen = 1920;  break;
                case ASP_FS_44K: uFrameLen = 2688;  break;
                case ASP_FS_48K: uFrameLen = 2880;  break;
            }            
         }        
         #endif              
         isr_cycle = uFrameLen;
         break;
      case ASP_TYPE_AAC:
      case ASP_TYPE_AAC_SBR_ARM:
         uFrameLen = ASP_FRAMELEN_AAC;
         del_m = ASP_DELM_AAC;   
         isr_cycle = del_m;
         if((asp_fs&0xFF)<=ASP_FS_12K)
         {
            uSDInterruptNumber <<= 2;
            isr_cycle = isr_cycle>>2;
         }
         else if((asp_fs&0xFF)<=ASP_FS_24K)
         {
            uSDInterruptNumber <<= 1;
            isr_cycle = isr_cycle>>1;
         }
         if(AudioPP_GetTSRate() < 100)
         {
            uSDInterruptNumber <<= 1;
            isr_cycle = isr_cycle>>1;
         }
         break;
      case ASP_TYPE_AWBDEC:
         uFrameLen = ASP_FRAMELEN_AWB;
         del_m = ASP_DELM_AWBDEC;  
         isr_cycle = del_m;   
         break;   
      case ASP_TYPE_AMR:
         uFrameLen = ASP_FRAMELEN_AMR;
         del_m = ASP_DELM_AMR;    
         isr_cycle = del_m;    
         break;
      case ASP_TYPE_I2SBypass:
         uFrameLen = ASP_FRAMELEN_I2S;
         del_m = ASP_DELM_I2SBypass;
         isr_cycle = del_m;
         break;
      default:
         ASSERT(0);
   }
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   if(VIBR_IsPlayingDummy())
   {
      del_w = 0x100;
   }
#endif  


#if defined(__KARAOKE_SUPPORT__)
   if(Media_IsKaraoke())
   {
   	  del_w = 0x10;
   }
#endif     

#if !defined( MED_MODEM )
    {
        extern void PcmRut_SetInterruptNumberPerFrame(kal_uint8 uNumber);
        PcmRut_SetInterruptNumberPerFrame(uSDInterruptNumber);
    }
#endif
   AM_WriteAspParam( asp_type, asp_fs, del_w, del_m, isr_cycle, uFrameLen);
#else
   AM_WriteAspParam( asp_type, asp_fs, del_w, del_m );   
#endif
   AM_Write_Idle_Delay(2);

#if defined(__BT_AUDIO_VIA_SCO__) && !defined(__CVSD_CODEC_SUPPORT__)  
   if ( AM_IsBluetoothOn() )
   {
#if defined(MT6255) && defined(EXT_DAC_SUPPORT) 
      if( (AFE_GetOutputDevice(L1SP_AUDIO)&L1SP_BUFFER_EXT)!=L1SP_BUFFER_EXT )
#endif   
      {
         AFE_TurnOn8K();
      }
   }
#endif

   VBI_Reset();
   
#if defined(__BT_AUDIO_VIA_SCO__) && !defined(__CVSD_CODEC_SUPPORT__)
   if ( AM_IsBluetoothOn() )
   {
      *DP_SC_FLAGS = 0x0600;
      *COMPEN_BLOCK_FLT_PAR_PTR &= ~( VOICE_OUTPUT_FILTER_FLAG );
      *DP_AUDIO_VIA_8KBT_CTRL |= 0x0001;
      am.state |= AM_STATE_AvBT;
   }
#endif

   am.state |= AM_STATE_AUDIO;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(8), L1AUDIO_Str_onoff(1) );
}

void AM_AudioPlaybackOn( uint16 asp_type, uint16 asp_fs )
{
   kal_uint8 uFunction;
   kal_bool fForceOffVoice = KAL_FALSE;
   kal_uint32 uSampleRate=AM_Convert_Sample_Index(asp_fs);

#if defined(__PCM_CLOCK_SWITCH_SUPPORT__)
    PCM_CLK_Deactivate();
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)

#if defined(__AUDIO_COMPONENT_SUPPORT__) && !defined( MED_MODEM )
    {
        extern void PcmSink_SetGainStep(kal_uint32 uSampleRate);
        extern kal_bool PcmSink_IsToneRuning(void);
        extern kal_bool PcmSink_IsKeytoneRuning(void);
        PcmSink_SetGainStep(uSampleRate);
        uFunction = PcmSink_IsToneRuning() ? L1SP_TONE : PcmSink_IsKeytoneRuning() ? L1SP_KEYTONE : L1SP_AUDIO;
    }
#else
    uFunction = L1SP_AUDIO;
#endif
   //AFE_Stop_and_Wait_DelayOff(uFunction, (kal_uint32)asp_fs);
   AFE_Stop_and_Wait_DelayOff(L1SP_AUDIO, (kal_uint32)asp_fs);

#ifndef  L1D_TEST
#if defined(MT6255)
   if(AM_IsToneOn())
   {
      TONE_StopAndWait();
      AM_FlushQFunction();
      kal_sleep_task(2); //to wait for voice clk off
   }
   if(AM_IsKeyToneOn())
   {
      KT_StopAndWait();
      AM_FlushQFunction();
      kal_sleep_task(2); //to wait for voice clk off 
   }
      if( (am.state & ~AM_STATE_AUDIO) != 0 )
      {
         AM_FlushQFunction();
         kal_sleep_task(3); //to wait for voice clk off 
      }
      
      if(!AFE_IsKaraok())
      {
         if( *AFE_VMCU_CON&0x0001 )
         {
            kal_sleep_task(1);
            if( *AFE_VMCU_CON&0x0001 )
            {
               _Afe_TurnOff_Spk_8kClk();
               fForceOffVoice = KAL_TRUE;
            }
         }
      }
#endif
   
#if defined(__KARAOKE_SUPPORT__)
   if(Media_IsKaraoke())
   {
      kal_uint32 freq = (uint32)asp_fs;
      if(freq==ASP_FS_8K || freq==ASP_FS_11K || freq==ASP_FS_12K)
      {
         *AFE_VMCU_CON1 |= 0x0200;
      }
   }
#endif

#if defined(AUDIO_COMPENSATION_ENABLE) 
   if(!AFE_IsInDelayOff())
   {
      Audio_Compensation_Activate(AM_Convert_Sample_Index(asp_fs));
   }
#endif
#if defined (__BT_AUDIO_VIA_SCO__) && defined(__CVSD_CODEC_SUPPORT__)
   BT_SCO_AudioPath_SetInfo(uSampleRate, 2);
   if(L1SP_IsBluetoothOn())
   {
      BT_SCO_AudioPath_ON();
   }
#endif
#if defined (__BT_AUDIO_VIA_SCO__) && !defined(__CVSD_CODEC_SUPPORT__)
   AVB_SetInfo(uSampleRate, 2);
   if(AM_IsBluetoothOn())
   {
      AVB_Open();
   }
#endif
#if defined ( __BT_A2DP_PROFILE__)
   SBC_SetInfo(uSampleRate, 2);
   if(SBC_IsOn())
   {
      mhdlHookPcmRut();
   }
#endif

#if defined(__AUDIO_COMPONENT_SUPPORT__) && !defined(MED_MODEM)
   PcmSink_UpdateGain();
#endif

#if defined(__BES_TS_SUPPORT__) 
   if (Media_IsDSPDec())
   {
      *DP2_AUDIO_PP_CONTROL |= 0x0001;
      AudioPP_TS_Activate(KAL_FALSE);
   }
#endif  // __BES_TS_SUPPORT__
#endif  // L1D_TEST


#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   DSP_DynamicDownload( DDID_VSG );
#endif //__VIBRATION_SPEAKER_SUPPORT__


#if defined(MT6255)
   {
      kal_uint8 delay4DCOffSet=0;
      kal_int16 DCOffSet = AFE_GetDCOffSet();
      if(DCOffSet<0)
      {
         DCOffSet = 0 - DCOffSet;
      }
      delay4DCOffSet = 1 + (DCOffSet / DCOffSetRampUpSetp) + 1 + (DCOffSet / DCOffSetRampDnSetp) + 1;
      AFE_TurnOnAudioClock( (uint8)asp_fs&0xFF );
      AFE_SetSamplingRate( (uint32)asp_fs );       
      AM_Enqueue( AM_DSP_AudioPlaybackOn, ((uint32)asp_type << 16) + (uint32)asp_fs, KAL_FALSE );
      AM_FlushQFunction();   
      AFE_TurnOnSpeaker( uFunction );   
      if(AFE_GetOutputDevice( uFunction ) & L1SP_BUFFER_EXT)
      {
         kal_sleep_task(2); //for dc compensation 
         //kal_sleep_task(delay4DCOffSet); //for dc compensation 
      }
      else
         kal_sleep_task(1);    
   }
#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      *DP2_AUDIO_ASP_COMMON_FLAG_1 |= AUD_BIT_COMFLG1_PCMPLAY_RAMCODE_PATH;
      AFE_TurnOnAudioClock( (uint8)asp_fs&0xFF );
      AFE_SetSamplingRate( (uint32)asp_fs );       
      AM_Enqueue( AM_DSP_AudioPlaybackOn, ((uint32)asp_type << 16) + (uint32)asp_fs, KAL_FALSE );
      AM_FlushQFunction();      
      AFE_TurnOnSpeaker( uFunction );   
#endif

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   if(!VIBR_IsPlayingDummy())
   {  
      VIBR_Vibration_Activate();
   }
#endif //__VIBRATION_SPEAKER_SUPPORT__

#if defined(__PCM_CLOCK_SWITCH_SUPPORT__)
    if (PCM_CLK_Is_Enabled())
    {
        PCM_CLK_Activate();
    }
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)

#if defined(MT6255) 
   if(fForceOffVoice)
   {
      if( (am.state & ~AM_STATE_AUDIO) != 0 ) 
      {
         if( (*AFE_VMCU_CON&0x0001)==0 )
         {
            AFE_TurnOn8K();
         }
      }
   }
#endif
}

static void AM_DSP_AudioPlaybackOff( uint32 data )
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(8), L1AUDIO_Str_onoff(0) );
   
   am.state &= ~AM_STATE_AUDIO;
   
   if (!(am.state & AM_STATE_AVSYNC)) {
      AFE_TurnOffAudioClock();
   #if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      AM_WriteAspParam( ASP_TYPE_VOICE, ASP_FS_8K, 95, 95, *AUDIO_ISR_CYCLE, 0 );
   #else
      AM_WriteAspParam( ASP_TYPE_VOICE, ASP_FS_8K, 95, 95 );
   #endif
   }
   
   AFE_TurnOffWTDMA();
#if defined(__BT_AUDIO_VIA_SCO__) && !defined(__CVSD_CODEC_SUPPORT__)
   if (AM_IsBluetoothOn()){
      *DP_AUDIO_VIA_8KBT_CTRL &= ~0x0001;
      am.state &= ~AM_STATE_AvBT;
   }
#endif
   
   if( am.state == 0 ) {

      #if __AFE_SW_DC_COMPENSATION__
      if (!AFE_IsDCCompRequried())
      #endif 
      VBI_End();
   }
   
   if ( (am.state & ~AM_STATE_AVSYNC) == 0) {
      AFE_TurnOff8K(); /*Turn off 8k clock which was turned on before keypad pressing.*/
   }

   *DSP_AUDIO_CTRL2 &= ~(DP_AAC_CTRL_ASP | DP_PCM_R_DIS);

#if defined(__KARAOKE_SUPPORT__)
   if (AFE_IsKaraok())
   {
   	  Media_SetKaraoke(KAL_FALSE);
   }
#endif
   
}

void AM_AudioPlaybackOff( bool wait )
{
   DTMF_MCU_StopAndWait();
   
#if defined(__PCM_CLOCK_SWITCH_SUPPORT__)
    PCM_CLK_Deactivate();
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)
   
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   if(!VIBR_IsPlayingDummy())
   {
      VIBR_Vibration_Deactivate();
   }
#endif //__VIBRATION_SPEAKER_SUPPORT__

#if APM_SUPPORT
#if defined ( __BT_AUDIO_VIA_SCO__ ) && !defined(__CVSD_CODEC_SUPPORT__)
   if( AM_IsBluetoothOn() )         // avoid eSCO re-transmit packet and produce pulse noise,
      if( wait ) AVB_Flush();       // flush some silence.
#endif

#if defined ( __BT_AUDIO_VIA_SCO__ )
#if defined(__CVSD_CODEC_SUPPORT__)
   BT_SCO_Disable_All_APP();
   BT_SCO_AudioPath_SetInfo(0, 0);
#else   
   AVB_Close();
   AVB_SetInfo(0, 0);
#endif   
#endif   

#if !defined(__AUDIO_COMPONENT_SUPPORT__)
   APM_Deactivate();
#endif
#endif

#if defined(__BT_A2DP_PROFILE__) && !defined(SBC_UNIT_TEST)
   if( wait ) SBC_Close();
#endif

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   TONE_StopAndWait();
#endif
   AFE_TurnOffSpeaker( L1SP_AUDIO );
   AFE_TurnOffSpeaker( L1SP_TONE );
   AFE_TurnOffSpeaker( L1SP_KEYTONE );
#if defined(__KARAOKE_SUPPORT__) // to avoid pop noise
   if(AFE_IsKaraok())
   	 kal_sleep_task(3);  
#endif 

   AM_Enqueue( AM_DSP_AudioPlaybackOff, 0, false );
   if( wait ) 
      AM_FlushQFunction();

#ifndef  L1D_TEST

#if defined ( __BT_A2DP_PROFILE__)
   SBC_SetInfo(0, 2);
#endif

#if defined(__BES_TS_SUPPORT__) 
#if defined(__AUDIO_COMPONENT_SUPPORT__)
   if (Media_IsDSPDec())
#endif 
      AudioPP_Close();      /* Turn off audio post process*/
#endif  // __BES_TS_SUPPORT__

#endif  // L1D_TEST

#if 1 //APM_SUPPORT
   if (wait)
   {
      kal_sleep_task(2);  // wait until AFE_Event_Handler process AFE_TurnOffSpeaker( L1SP_AUDIO ), then do the unmute
      AFE_SetHardwareMute(false);
   }   
#endif
#if defined(__BES_EQ_SUPPORT__) || defined(AUDIO_COMPENSATION_ENABLE)
//allow AFE turn off audio clock first to avoid pop from EQ if rapid open audio again
   kal_sleep_task(2);
#else
   #if defined(MT6255) 
   kal_sleep_task(2);
   #endif
#endif
  
   AFE_WaitReleaseVoltage();

#if defined(__AUDIO_COMPONENT_SUPPORT__) && !defined( MED_MODEM )
   PcmSink_FreeSoundBuffer();
   Media_SetSampleRate(0);  
   Media_SetAudioFormat(MEDIA_FORMAT_WAV); 
#endif

#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *DP2_AUDIO_ASP_COMMON_FLAG_1 &= ~AUD_BIT_COMFLG1_PCMPLAY_RAMCODE_PATH;
#endif

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   if(!VIBR_IsPlayingDummy())
   {
      VIBR_Vibration_Activate();
   }
#endif //__VIBRATION_SPEAKER_SUPPORT__

#if defined(__PCM_CLOCK_SWITCH_SUPPORT__)
    if (PCM_CLK_Is_Enabled())
    {
        PCM_CLK_Activate();
    }
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)

}

int16 AM_IsAudioPlaybackOn( void )
{
   if( am.state & AM_STATE_AUDIO )
      return( *DP_ASP_FS );
   return -1;
}

int16 AM_IsIdleState( void )
{
   if( am.state == 0 )
      return true;
   return false;
}

bool AM_IsVMPlaybackOn( void )
{
   if( am.state & AM_STATE_VOICE)
      return true;
   return false;
}

bool AM_IsVoiceOn( void )
{
   if( am.state & ~AM_STATE_AUDIO)
      return true;
   return false;
}

/* ==========================================================================*/
static void AM_DSP_AVSync_On( uint32 data )
{
   if (am.state & (AM_STATE_SPEECH | AM_STATE_VOICE | AM_STATE_AUDIO)) {
      *DP_A2V_INT_ENABLE = 3;
   }

   am.state |= AM_STATE_AVSYNC;
}

void AM_AVSync_On( void )
{
   AM_Enqueue( AM_DSP_AVSync_On, 0, false );
}

static void AM_DSP_AVSync_Off( uint32 data )
{
   am.state &= ~AM_STATE_AVSYNC;
   *DP_A2V_INT_ENABLE = 0;

   if (!(am.state & AM_STATE_AUDIO)) {
      AFE_TurnOffAudioClock();
   #if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      AM_WriteAspParam( ASP_TYPE_VOICE, ASP_FS_8K, 95, 95, *AUDIO_ISR_CYCLE, 0 );
   #else
      AM_WriteAspParam( ASP_TYPE_VOICE, ASP_FS_8K, 95, 95 );
   #endif
   }

   if (am.state == 0 ) {
      VBI_End();
      AFE_TurnOff8K();
   }
}

void AM_AVSync_Off( void )
{
   AM_Enqueue( AM_DSP_AVSync_Off, 0, false );
}

bool AM_IsAVsyncOn( void )
{
   if (am.state & AM_STATE_AVSYNC)
      return true;
   else
      return false;
}

bool AM_IsAuioAVSyncState( void )
{
   if ((am.state & AM_STATE_AVSYNC) || (am.state & AM_STATE_AUDIO))
      return true;
   else
      return false;
}

/* ==========================================================================*/
void AM_MuteULSpeech( bool mute )
{
   if( mute ) 
      *DP_SC_MUTE |= 0x0001;   
   else 
      *DP_SC_MUTE &= ~0x0001;   
}

bool AM_IsULSpeechMuted( void )
{
   if(*DP_SC_MUTE & 0x1)
      return true; 
   else 
      return false;    
}


void AM_Init( void )
{
   am.record_format = AM_RECORD_NONE;
   am.DL_UL_path = SPH_BOTH_PATH;
   RB_INIT( am.qfunc );
#if defined( NOT_HANDOVER_IN_SHORT_TIME )
   am.l1FN_HO = 0;
#endif
   am.state = 0;
   am.speech_mode = 0;
   am.sub_channel = 0;
   am.speech_off_delay = 0;
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   am.pre_isWBLink = KAL_FALSE;   
#endif
   AM_FillSilencePattern( DSP_TX_TCH_S0_0, 2, am.speech_mode );

#if defined( NEW_BLOCK_FILTER_SUPPORT )
   g_Compen_Blk_Flt = COMPEN_BLOCK_FLT_PAR;
#endif

   am.afe_mode          = -1;
   *DP_ASP_DEL_W        = 95;
   *DP_ASP_DEL_M        = 95;

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    Pseudo_SAL_Dsp_Sph_Init();
    Pseudo_SAL_Set_Sph_Nml_Mod(true);
#else   // chip compile option
#endif  // chip compile option

   AM_WriteSidetoneFIR();

#ifndef L1D_TEST
   *E_CTRL_HRFR         = 0x0E;
   *E_CTRL_AMREFR       = 0x00;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// Don't set in MT6260
#else   // chip compile option
   *E_CTRL_HO           = 0x0401;  // AMR _Type update bit 9, HO_SID_Update bit 8
#endif  // chip compile option
#endif
   // Initialization for EC/AEC/EES
   *DP_EC_SUPP        = 0;
   *DP_AEC_CONTROL       = 0;
#if TDDNC_SUPPORT
   *DP_TDDNC_CTRL     = 0;
#endif    

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// Don't set in MT6260
#else   // chip compile option
   /* bit14 :the data of Speech DSP is avaible
      Before speech on, if Modem always sends the SpeechBad frame to network, it causes CC connection fails
   */   
   *E_CTRL_HO         |=0x4010;//check repeat hardbit as bad frame, no effect for this bit in MT6280, wayne
   //enable this bit to get better speech quality when HO
#endif  // chip compile option

   if( audio_coeff_flag == 0 ) {
      AM_WriteFirCoeffs( Speech_Input_FIR_Coeff[0], Speech_Output_FIR_Coeff[0] );
   }

   AM_WriteAntiAliasFilter();
#if defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01)   
   AM_Write16kCompensationFilter();
#endif
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// AGC Table is ROM in MT6260 DSP
#else   // chip compile option
   AM_WriteAGCParam();
#endif  // chip compile option

#if defined(AEC_ENABLE)
   *DP_AEC_8K_CTRL = 0;
#endif    
   *DP_EC_SUPP = 0;
   *DP_NSYNC_NOT_ETSI_C &= ~0x20;
   *DP_AUDIO_PAR = 0x8000;
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   AM_WriteAspParam( ASP_TYPE_VOICE, ASP_FS_8K, 95, 95, *AUDIO_ISR_CYCLE, 0 );
#else 
   AM_WriteAspParam( ASP_TYPE_VOICE, ASP_FS_8K, 95, 95 );
#endif
   DSP_IO4_On();
   DSP_IO5_On(); 
   DSP_IO6_On(); 
   am.io_type = NORMAL_MODE;  
   am.speech_state = 0;
   am.voip_state = 0;   
   am.fLoopBack = false; 
   am.sp3g_flag = false;
   am.toneLoopbackRec = false;
   am.afe_loopback_flag = false;


#if defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   // Temp solution for sidetone. From FIR to IIR
   *COMPEN_BLOCK_FLT_PAR_PTR |= 4;
#endif

#if defined(__VAD_SUPPORT__)
   am.bm_enc_mode = 0x3;
   am.bm_dec_mode = 0x3;
#endif

#if defined(__PCM_CLOCK_SWITCH_SUPPORT__) || defined(__AUDIO_AT_CMD__)
    am.pcm_clock_flag = KAL_FALSE;
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)
}

/* ========================================================================= */
/*   Bluetooth control Functions                                             */
/* ========================================================================= */
#if defined(__BT_SUPPORT__) || defined(__PCM_INTERFACE_SUPPORT__)
#if !defined(__CVSD_CODEC_SUPPORT__) && !defined(__PCM_INTERFACE_SUPPORT__)
extern const unsigned short default_bt_pcm_in_vol;
extern const unsigned short default_bt_pcm_out_vol;
#endif
static void AM_DSP_BluetoothOn( uint32 data )
{
   // If BT is turned on already, return directly.
   if( AM_IsBluetoothOn() )
      return;
                           
   // Adjust the uplink and downlink gain
   am.bt_digital_gain = *DP_VOL_OUT_PCM;   
   am.bt_mic_gain = *DP_VOL_IN_PCM;

   if (data != 0x1000) {
#if defined(__PCM_CLOCK_ALWAYS_ON__)
      // AFE_TurnOff8K_Direct();
#else   // defined(__PCM_CLOCK_ALWAYS_ON__)
      AFE_TurnOff8K_Direct();
#endif  // defined(__PCM_CLOCK_ALWAYS_ON__)
      //AFE_Mute(true);
   }
#if !defined(__CVSD_CODEC_SUPPORT__)
   // 13-bit sample
#if defined(__PCM_INTERFACE_SUPPORT__)
   if ( 0 ) {
#else
   if ( BtRadio_Get_PCM_SignExtension() ) {//SignExtension mode(13bit) cannot apply digital gain
#endif
      // Sign-extension mode
      *DP_BT_PATCH_CTRL = 0;
      *DP_BT_MODE_CTRL  = 0x0008;
   } else {  //Only Linear mode(16bit) can apply digital gain
      // Zero-pending
      *DP_BT_PATCH_CTRL = 0x0002;
      *DP_BT_MODE_CTRL  = 0;
   }

   
   // Transfer
#if defined(__PCM_INTERFACE_SUPPORT__)
   if ( 0 ) {
#else   
   if ( BtRadio_Get_PCM_LSBFirst() ) {
#endif
      // LSB first
      *DP_BT_PATCH_CTRL |= 0x0010;
   } else {
      // MSB first
      *DP_BT_PATCH_CTRL &= ~(0x0010);
   }

   //set mode and uplink gain
#if defined(__PCM_INTERFACE_SUPPORT__)
   *DP_BT_PATCH_CTRL |= (0x100 & 0xff00); //0x100 is UL default setting 0dB
#else
   *DP_BT_PATCH_CTRL |= (default_bt_pcm_in_vol & 0xff00);
#endif
#endif
#if defined(__GAIN_TABLE_SUPPORT__)
   AFE_SetRefresh();
#else
   #if !defined(__CVSD_CODEC_SUPPORT__)
   #if defined(__PCM_INTERFACE_SUPPORT__) 
   *DP_VOL_OUT_PCM = 0x1400;  //0x1000 is DL default setting 0dB
   #else
   *DP_VOL_OUT_PCM = default_bt_pcm_out_vol;
   #endif
#endif
#endif

   if(data == 0x1000)
   {
      ASSERT(am.state == 0);

      *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x1000;      
#if defined(__PCM_CLOCK_ALWAYS_ON__)
      //AFE_TurnOnBluetooth(0);
	  am.DL_UL_path = SPH_BOTH_PATH;
        //AFE_TurnOn8K();
#else   // defined(__PCM_CLOCK_ALWAYS_ON__)
      AFE_TurnOnBluetooth(0);
	  am.DL_UL_path = SPH_BOTH_PATH;
      AFE_TurnOn8K(); 
#endif  // defined(__PCM_CLOCK_ALWAYS_ON__)
      am.io_type = BT_CORDLESS_MODE;            
   }   
   else 
   {
      if(am.state == 0)    
      {
         *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x2000;
#if defined(__PCM_CLOCK_ALWAYS_ON__)
         //AFE_TurnOnBluetooth(0);
#else   // defined(__PCM_CLOCK_ALWAYS_ON__)
         AFE_TurnOnBluetooth(0);
#endif  // defined(__PCM_CLOCK_ALWAYS_ON__)
      }   
      else 
      {                
         *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x2000;
#if defined(__PCM_CLOCK_ALWAYS_ON__)
         //AFE_TurnOnBluetooth(0);                    
#else   // defined(__PCM_CLOCK_ALWAYS_ON__)
         AFE_TurnOnBluetooth(0);                    
#endif  // defined(__PCM_CLOCK_ALWAYS_ON__)
         if(am.state & AM_STATE_SPEECH)         
            AM_FillSilencePattern( DSP_TX_TCH_S0_0, 2, am.speech_mode ); 

         #if defined(MT6255)
         if ( !(SW_SEC_0 == INT_SW_SecVersion() && (AM_IsAudioPlaybackOn() != -1)))
         #endif
            
#if defined(__BT_AUDIO_VIA_SCO__) && !defined(__CVSD_CODEC_SUPPORT__)
         if ( AM_IsAudioPlaybackOn() != -1 ){
            *DP_SC_FLAGS = 0x0600;
            *COMPEN_BLOCK_FLT_PAR_PTR &= ~( VOICE_OUTPUT_FILTER_FLAG );
            am.state |= AM_STATE_AvBT;
         }else if ( AM_IsVMPlaybackOn() ){
            *DP_VSBT_CTRL |= 0x1;
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#if defined(_FWE_SUPPORT_)  
            *DP_SCR_CTRL = 0x100;
#else
   	      *DP_SCR_CTRL = 0x4;
#endif   	   
#endif
         }
#endif
         am.DL_UL_path = SPH_BOTH_PATH;
         {
#if defined(__PCM_CLOCK_ALWAYS_ON__)
            // AFE_TurnOn8K();
#else   // defined(__PCM_CLOCK_ALWAYS_ON__)
            AFE_TurnOn8K();
#endif  // defined(__PCM_CLOCK_ALWAYS_ON__)
         }
         if(am.state & ( AM_STATE_SPEECH | AM_STATE_VOICE ) )
            VBI_Reset();

#if defined(__AUDIO_BT_FORCE_VBI_RESET__)
         if ( AM_IsBTForceVBIReset() )
            am.fResetCount = KAL_TRUE;
#endif

#if defined(__BT_AUDIO_VIA_SCO__) && !defined(__CVSD_CODEC_SUPPORT__)
         if(am.state & AM_STATE_AvBT )
            *DP_AUDIO_VIA_8KBT_CTRL |= 0x0001;
#endif
      }
      am.io_type = BT_EARPHONE_MODE;                                   
   }
   
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );        
}

static void AM_DSP_BluetoothOff( uint32 data )
{
   // If BT is turned off already, return directly.
   if( !AM_IsBluetoothOn() )
      return;
#if defined(__PCM_CLOCK_ALWAYS_ON__)
   //AFE_TurnOff8K_Direct();
#else   // defined(__PCM_CLOCK_ALWAYS_ON__)
   AFE_TurnOff8K_Direct();
#endif  // defined(__PCM_CLOCK_ALWAYS_ON__)

   //AFE_Mute(false);
   *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x8000;
#if defined(__PCM_CLOCK_ALWAYS_ON__)
   //AFE_TurnOffBluetooth();    
#else   // defined(__PCM_CLOCK_ALWAYS_ON__)
   AFE_TurnOffBluetooth();    
#endif  // defined(__PCM_CLOCK_ALWAYS_ON__)

   // Set linear mode (zero pending)
   *DP_BT_MODE_CTRL = 0x0000;
#if !defined(__GAIN_TABLE_SUPPORT__)
   *DP_VOL_OUT_PCM = am.bt_digital_gain;
#endif
   *DP_VOL_IN_PCM = am.bt_mic_gain;

   if( am.state != 0 )     
   {  
#if defined(__BT_AUDIO_VIA_SCO__) && !defined(__CVSD_CODEC_SUPPORT__)
      if (AM_IsAudioPlaybackOn() != -1){
         *DP_AUDIO_VIA_8KBT_CTRL &= ~0x0001;
         am.state &= ~AM_STATE_AvBT;
      }else if (AM_IsVMPlaybackOn()){
         *DP_VSBT_CTRL &= ~0x1;
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
         *DP_SCR_CTRL = 0x0;
#endif
      }
#endif
      if(am.state & AM_STATE_SPEECH) 
         AM_FillSilencePattern( DSP_TX_TCH_S0_0, 2, am.speech_mode );
#if defined(MT6255) ||  defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
        // video playback : audio + sync (audio clock)
        // video record    : voice + sync (8k    clock)
        // avb             : audio + voice                  
      if(AM_IsNeedSpeechDSP())  //After 6250, if want to turn on 8k and audio clock at the same time, it must turn on audio clock first , then 8k clock; Before 6250, in this scenario, it always turns on 8k clock.
#endif          
      {
         am.DL_UL_path = SPH_BOTH_PATH;
#if defined(__PCM_CLOCK_ALWAYS_ON__)
         // AFE_TurnOn8K();
#else   // defined(__PCM_CLOCK_ALWAYS_ON__)
         AFE_TurnOn8K();
#endif  // defined(__PCM_CLOCK_ALWAYS_ON__)
      }
      if(am.state & AM_STATE_SPEECH)    
         VBI_Reset();
   }
   
   am.io_type = NORMAL_MODE; 
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );                                     
}

//*******************************************************************//
//*   bt_mode:        1 for cordless mode, 2 for earphone mode      *//
//*   bt_sync_type:   0 for short sync, 1 for long sync             *//
//*   bt_sync_length: range from 1 to 8                             *//
//*******************************************************************//
extern const unsigned char Bluetooth_Sync_Type;
extern const unsigned char Bluetooth_Sync_Length;
void AM_BluetoothOn( uint8 bt_mode )
{
   uint32 param;          // bt_mode will be either 1 for cordless mode, or 2 for earphone mode
   param = bt_mode;          // bt_mode will be either 1 for cordless mode, or 2 for earphone mode

   AFE_Stop_and_Wait_DelayOff(L1SP_SPEECH, ASP_FS_8K);
   DTMF_MCU_StopAndWait();
   TONE_StopAndWait();
   KT_StopAndWait();
   param <<= 12;
   param |= (Bluetooth_Sync_Type << 3);    // bt_sync_type will be either 0 for short sync, or 1 for long sync
   param |= (Bluetooth_Sync_Length - 1);   // 1 <= bt_sync_length <= 8
   AM_Enqueue( AM_DSP_BluetoothOn, param, false );
   
   AM_FlushQFunction();
#if defined ( __BT_AUDIO_VIA_SCO__ ) && !defined(__CVSD_CODEC_SUPPORT__)
   if( AM_IsAudioPlaybackOn() != -1 )
   {
      AVB_Open();
   }
#endif
}

void AM_BluetoothOff( void )
{
#if defined ( __BT_AUDIO_VIA_SCO__ ) && !defined(__CVSD_CODEC_SUPPORT__)
   if( AM_IsAudioPlaybackOn() != -1 )         // avoid eSCO re-transmit packet and produce pulse noise,
      AVB_Flush();                            // flush some silence.
#endif

   TONE_StopAndWait();
   KT_StopAndWait();
   DTMF_MCU_StopAndWait();
   AM_Enqueue( AM_DSP_BluetoothOff, 0, false );
   AM_FlushQFunction();

#if defined ( __BT_AUDIO_VIA_SCO__ ) && !defined(__CVSD_CODEC_SUPPORT__)
   AVB_Close();
#endif

}

bool AM_IsBluetoothOn( void )
{
    kal_uint16 aud_id;
    bool isBT = false;
    
    if (!L1Audio_IsInitiated())
    {
        return false;
    }
    
    if (!kal_if_hisr() && !kal_if_lisr())
    {
        aud_id = L1Audio_GetAudioID();
        L1Audio_SetFlag(aud_id);
    }
    
#if defined(MT6255)
    if (SW_SEC_0 == INT_SW_SecVersion() && AM_IsAudioPlaybackOn() != -1)
    {
        isBT = false;
    }
    else
#endif
    {
        isBT = (bool)((*DP_AUDIO_PAR & 0x3000) != 0);
    }
    
    if (!kal_if_hisr() && !kal_if_lisr())
    {
        L1Audio_ClearFlag(aud_id);
        L1Audio_FreeAudioID(aud_id);
    }
    
    return isBT;
}

bool AM_IsBTCordlessMode( void )
{
   return (L1SP_GetSpeechMode() == SPH_MODE_BT_CORDLESS);
   //return( (*DP_AUDIO_PAR&0x1000)!=0 );
}

#endif   // __BT_SUPPORT__
/* ========================================================================= */


#ifdef BGSND_ENABLE
void AM_SND_PlaybackOn( void )
{
   AM_Enqueue( AM_DSP_PCM8K_PlaybackOn, 1, false );
   if( !AM_IsSpeechOn() ) AFE_TurnOnSpeaker( L1SP_SND_EFFECT );

   AM_FlushQFunction();
}

void AM_SND_PlaybackOff( bool wait )
{
   AFE_TurnOffSpeaker( L1SP_SND_EFFECT );
   AM_Enqueue( AM_DSP_PCM8K_PlaybackOff, 1, false );
   
   if( wait )
      AM_FlushQFunction();
}
#endif /* ...BGSND_ENABLE */

/* ========================================================================= */
/*   PCM_EX control Functions                                            */
/* ========================================================================= */

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
static void am_set_pcm_ex_config (Pseudo_Sal_PCMEx_t *p_cfg, PCM_Ex_Config *p_config, kal_bool idle, kal_bool swi_on, Pseudo_Sal_PcmEx_Type_t type_t, Pseudo_Sal_PcmBand_Config_t band_t)
{
    p_cfg->idle   = idle;
    p_cfg->swi_on = swi_on;
    
    p_cfg->type = type_t;
    p_cfg->band = band_t;
    
    p_cfg->UL_M2D_on       = p_config->UL_M2D_on;
	p_cfg->UL_D2M_on       = p_config->UL_D2M_on;
	p_cfg->UL_is_after_enh = p_config->UL_is_after_enh;
	p_cfg->DL_M2D_on       = p_config->DL_M2D_on;
	p_cfg->DL_D2M_on       = p_config->DL_D2M_on;
	p_cfg->DL_is_after_enh = p_config->DL_is_after_enh;
    
    return;
}
#endif  // chip compile option

void AM_DSP_PCM_EX_On(uint32 type)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    PCM_Ex_Config *p_config = (PCM_Ex_Config *)type;
    kal_uint32 am_type = p_config->am_type;
    Pseudo_Sal_PcmEx_Type_t     type_t = PSEUDO_SAL_PCMEX_TYPE_DACA;
    Pseudo_Sal_PcmBand_Config_t band_t = p_config->bandInfo;
    kal_bool idle = false;
    
    if (!(am.state & AM_STATE_SPEECH))
    {
        *AFE_VMCU_CON1 &= ~0x0200;  // Fix AFE into WB
    }
    
    if (   am_type != AM_PCMEX_TYPE_DACA_DEDICATION
        && am_type != AM_PCMEX_TYPE_DEDICATION
       )
    {
        *AFE_VLB_CON |= (0x01<<3);
    }
    
    switch (am_type)
    {
        case AM_PCMEX_TYPE_DACA_DEDICATION:     // 100: // DACA ACTIVE
        case AM_PCMEX_TYPE_DACA_IDLE_WO_ENH:    // 101: // DACA IDLE
            {
                if (am_type == AM_PCMEX_TYPE_DACA_DEDICATION)
                {
                    ASSERT(!(am.speech_state & SP_STATE_DACA));
#ifndef L1D_TEST
                    am.speech_state |= SP_STATE_DACA;
                    L1Audio_Msg_AM_SetSpeech(AM_Speech_Feature_Name(3), L1AUDIO_Str_onoff(1));
#endif
                }
                else
                {
                    ASSERT(!(am.state & AM_STATE_DACA));
                    idle = am.state == 0 ? true : false;
                    am.state |= AM_STATE_DACA;
                }
                am.DL_UL_path = SPH_BOTH_PATH;
                // type_t & band_t are both initialized to DACA values
            }
            break;
        case AM_PCMEX_TYPE_DEDICATION:  // 0:   // PCM4WAY CTM
        case AM_PCMEX_TYPE_IDLE_WO_ENH: // 1:   // PCM2WAY Voice
        case AM_PCMEX_TYPE_IDLE:        // 2:   // PCM2WAY VoIP
            {
                if (am_type == AM_PCMEX_TYPE_DEDICATION)
                {
                    ASSERT(!(am.speech_state & SP_STATE_PCMNWAY));
#ifndef L1D_TEST
                    am.speech_state |= SP_STATE_PCMNWAY;
                    L1Audio_Msg_AM_SetSpeech(AM_Speech_Feature_Name(2), L1AUDIO_Str_onoff(1));
#endif
                }
                else
                {
                    ASSERT_REBOOT(!am.afe_loopback_flag);
#if defined(__VAD_SUPPORT__)
                    if ( !VAD_IsEnable() )
#endif
                       ASSERT_REBOOT(!(am.state & AM_CONFLICT_STATE));
                    idle = am.state == 0 ? true : false;
#if defined(__VAD_SUPPORT__)
                    am.state |= AM_STATE_PCMNWAY;
#else
                    am.state |= am_type == AM_PCMEX_TYPE_IDLE_WO_ENH ? AM_STATE_VOICE : AM_STATE_VOIP;
#endif
                }
			    
			    type_t = PSEUDO_SAL_PCMEX_TYPE_PNW;
				if( (p_config->UL_D2M_on || p_config->UL_M2D_on)&& !(p_config->DL_M2D_on) &&!(p_config->DL_D2M_on) ) // 
        		{
        			am.DL_UL_path = SPH_VOICE_PCM2WAY_UL;
				}
				else if ( (p_config->DL_D2M_on || p_config->DL_M2D_on)&& !(p_config->UL_M2D_on) &&!(p_config->UL_D2M_on))
				{
					am.DL_UL_path = SPH_VOICE_PCM2WAY_DL;

				}
				else 
				{
					am.DL_UL_path = SPH_BOTH_PATH;
				}
            }
            break;
        default:
            ASSERT(0);
            break;
    }

    {
        Pseudo_Sal_PCMEx_t cfg;
        am_set_pcm_ex_config (&cfg, p_config, idle, true, type_t, band_t);
      
        if (idle == true)
        {
            cfg.delR = DSP_PCM_IDLE_DELAY_TABLE[5][0];
            cfg.delW = DSP_PCM_IDLE_DELAY_TABLE[5][1];
            cfg.delM = DSP_PCM_IDLE_DELAY_TABLE[5][2];
            AFE_TurnOn8K();
        }
        Pseudo_SAL_PcmEx_Config(&cfg);
    }
    
    return;
#else   // chip compile option
#if defined(MT6256) || defined(MT6255) || defined(MT6250)
   if( !(am.state & AM_STATE_SPEECH) )
      *AFE_VMCU_CON1 &= ~0x0200;    //fix AFE into WB
      
	if((0 != type) && (100 != type)){ //case in dedicate mode
	   //disable hw IIR (bypass). --> request by YT
	   //and use the SW SRC
	   *DP_AUDIO_PAR &= ~(0x10); //VOICE_16K_SWITCH_FLAG, using software SRC
	   *AFE_VLB_CON |= (0x01<<3);  /* Bypass hardware IIR filter */

	   //Setup the SW SRC
	   if(BT_EARPHONE_MODE == am.io_type){//only single MIC
		  if(PCM2Way_GetFormat() == PCMNWAY_BAND_INFO_WB){
			 *DP_SCR_CTRL = 0x180; 
		  }else if ((PCM2Way_GetFormat() == PCMNWAY_BAND_INFO_NB) ||
					(PCM2Way_GetFormat() == PCMNWAY_BAND_INFO_UNSET)){
			 *DP_SCR_CTRL = 0x0;		  
		  }
	   } else { 
		  if(PCM2Way_GetFormat() == PCMNWAY_BAND_INFO_WB){//single/dual MIC use the same setting
			 *DP_SCR_CTRL = 0x0;
		  }else if ((PCM2Way_GetFormat() == PCMNWAY_BAND_INFO_NB) ||
					(PCM2Way_GetFormat() == PCMNWAY_BAND_INFO_UNSET)){
#if defined(__DUAL_MIC_SUPPORT__) 
			 //*DP_SCR_CTRL = 0x47; 
			 *DP_SCR_CTRL = 0x46; //call 0x4e
#else
			 //*DP_SCR_CTRL = 0x7; 
			 *DP_SCR_CTRL = 0x6; //call 0x6
#endif                     
		  }else{ //never been here
			  ASSERT(0);  
		  } 			 
	   }			  
	}
#endif            

   switch(type)
   {
      case 100:  //DACA ACTIVE
         ASSERT(!(am.speech_state & SP_STATE_DACA)); 
#ifndef L1D_TEST
         am.speech_state |= SP_STATE_DACA;
         L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(3) , L1AUDIO_Str_onoff(1) );
#endif                   
         break;         
      case 101:  //DACA IDLE
         ASSERT_REBOOT( !(am.state & AM_STATE_DACA) ); 
		 am.state |= AM_STATE_DACA;
         AFE_TurnOn8K();
         if(am.state == 0)
         {                 
            AM_Write_Idle_Delay(5);
            VBI_Reset();
         }         
                  
         break;         	
      case 0:  //PCM4WAY CTM
         ASSERT(!(am.speech_state & SP_STATE_PCMNWAY)); 
#ifndef L1D_TEST
         // add codes to enable VM log
         //*DP_SC_FLAGS |= 0x0800;  // conversion recording in speech call
         //*E_CTRL_HO   |= 0x08;         /* Enable DSP debugging information of VM */
         am.speech_state |= SP_STATE_PCMNWAY;
         L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(2) , L1AUDIO_Str_onoff(1) );
#endif                   
         break;
         
      case 1:  //PCM2WAY Voice
         ASSERT_REBOOT(!am.afe_loopback_flag);   // Should not use AFE loopback and PCM 2 way at the same time      	
         ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 
		 am.state |= AM_STATE_VOICE;
         AFE_TurnOn8K();
         if(am.state == 0)
         {                 
            AM_Write_Idle_Delay(5);
            VBI_Reset();
         }         
                  
         break;
         
      case 2:  //PCM2WAY VoIP
         ASSERT_REBOOT(!am.afe_loopback_flag);   // Should not use AFE loopback and PCM 2 way at the same time      	
         ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 
		 am.state |= AM_STATE_VOIP;
         AFE_TurnOn8K();
         if(am.state == 0)
         {                 
            AM_Write_Idle_Delay(5);
            VBI_Reset();
         }        
                                    
         break;

	  case P2W_APP_TYPE_REC_ONLY_CAL: //3: record only dmnr calibration
       ASSERT_REBOOT(!am.afe_loopback_flag);   // Should not use AFE loopback and PCM 2 way at the same time	  	
	  	 ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 
		 am.state |= AM_STATE_VOIP;
         AFE_TurnOn8K();
		 if(am.state == 0)
         {                 
            AM_Write_Idle_Delay(5);
            VBI_Reset();
         }
		  
		 ASSERT_REBOOT( !(am.voip_state & VOIP_STATE_REC_ONLY_CAL) ); 
		 am.voip_state |= VOIP_STATE_REC_ONLY_CAL;
	  	 break;
		 
	  case P2W_APP_TYPE_REC_PLAY_CAL: //4: record and play dmnr calibration
        ASSERT_REBOOT(!am.afe_loopback_flag);   // Should not use AFE loopback and PCM 2 way at the same time	  	
	     ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 
		 am.state |= AM_STATE_VOIP;
         AFE_TurnOn8K();
		 if(am.state == 0)
         {                 
            AM_Write_Idle_Delay(5);
            VBI_Reset();
         }
		  
		 ASSERT_REBOOT( !(am.voip_state & VOIP_STATE_REC_PLAY_CAL) ); 
		 am.voip_state |= VOIP_STATE_REC_PLAY_CAL;
	  	 break;
		 
      default:
         ASSERT(0);
         break;                 
   }   

    
    return;
#endif  // chip compile option
}

void AM_DSP_PCM_EX_Off(uint32 type)
{   
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    PCM_Ex_Config *p_config = (PCM_Ex_Config *)type;
    kal_uint32 am_type = p_config->am_type;
    Pseudo_Sal_PcmEx_Type_t type_t = PSEUDO_SAL_PCMEX_TYPE_PNW;
    kal_bool idle = false;

    switch (am_type)
    {
        case AM_PCMEX_TYPE_DACA_DEDICATION:     // 100: // DACA ACTIVE
      	case AM_PCMEX_TYPE_DACA_IDLE_WO_ENH:    // 101: // DACA IDLE
      	    {
                if (am_type == AM_PCMEX_TYPE_DACA_DEDICATION)
                {
                    am.speech_state &= ~SP_STATE_DACA;
                    L1Audio_Msg_AM_SetSpeech(AM_Speech_Feature_Name(3), L1AUDIO_Str_onoff(0));
                }
                else
                {
                    am.state &= ~AM_STATE_DACA;
                    idle = am.state == 0 ? true : false;
                }
                
                type_t = PSEUDO_SAL_PCMEX_TYPE_DACA;
      	    }
            break;
        case AM_PCMEX_TYPE_DEDICATION:  // PCM4WAY CTM
        case AM_PCMEX_TYPE_IDLE_WO_ENH: // PCM2WAY Voice
        case AM_PCMEX_TYPE_IDLE:        // PCM2WAY VoIP
            {
                if (am_type == AM_PCMEX_TYPE_DEDICATION)
                {
                    am.speech_state &= ~SP_STATE_PCMNWAY;
                    L1Audio_Msg_AM_SetSpeech(AM_Speech_Feature_Name(2), L1AUDIO_Str_onoff(0));
                }
                else
                {
#if defined(__VAD_SUPPORT__)
                    am.state &= ~AM_STATE_PCMNWAY;
#else
                    am.state &= am_type == AM_PCMEX_TYPE_IDLE_WO_ENH ? ~AM_STATE_VOICE : ~AM_STATE_VOIP;
#endif
                    idle = am.state == 0 ? true : false;
                }
                
                type_t = PSEUDO_SAL_PCMEX_TYPE_PNW;
            }
            break;
        default:
            ASSERT(0);
            break;
    }

    {
        Pseudo_Sal_PCMEx_t cfg;
        am_set_pcm_ex_config (&cfg, p_config, idle, false, type_t, PSEUDO_SAL_PCM_NARROWBAND);
        Pseudo_SAL_PcmEx_Config(&cfg);
    }    
    
    if (idle)
    {
        AFE_TurnOff8K();
    }
    am.DL_UL_path = SPH_BOTH_PATH;
    if (   am_type != AM_PCMEX_TYPE_DACA_DEDICATION
        && am_type != AM_PCMEX_TYPE_DEDICATION
#if defined(__VAD_SUPPORT__)
        && (am.state == 0)
#endif
       )
    {
        *AFE_VLB_CON &= ~(0x01<<3);
    }
    
    return;
#else   // chip compile option
   switch(type)
   {
      case 100:  //DACA ACTIVE
         am.speech_state &= ~SP_STATE_DACA;
         L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(3) , L1AUDIO_Str_onoff(0) );                   
         break;         
      case 101:  //DACA IDLE
         am.state &= ~AM_STATE_DACA;
         if( am.state == 0 ) {
            VBI_End();        
            AFE_TurnOff8K(); 
         }      
         break;                  	
      case 0:  //PCM4WAY CTM
         // add codes to stop VM log
         //*E_CTRL_HO   &= 0xFFF7;   /* Disable DSP debugging information of VM */
         //*DP_SC_FLAGS &= ~0x0800;
         am.speech_state &= ~SP_STATE_PCMNWAY;
         L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(2) , L1AUDIO_Str_onoff(0) );                   
         break;
         
      case 1:  //PCM2WAY Voice
         am.state &= ~AM_STATE_VOICE;
         if( am.state == 0 ) {
            VBI_End();        
            AFE_TurnOff8K(); 
         }      
         break;
         
      case 2:  //PCM2WAY VoIP
         am.state &= ~AM_STATE_VOIP;         
         if( am.state == 0 ) {
            VBI_End();        
            AFE_TurnOff8K();
         }                                        
         break;

	  case P2W_APP_TYPE_REC_ONLY_CAL: //3: PCM2Way record only (for calibration)
         am.voip_state &= ~VOIP_STATE_REC_ONLY_CAL;
	  	 am.state &= ~AM_STATE_VOIP;
		 if( am.state == 0 ) {
            VBI_End();        
            AFE_TurnOff8K();
         } 
	  	 break;

	  case P2W_APP_TYPE_REC_PLAY_CAL: //4: PCM2Way record and play (for calibration)
	  	 am.voip_state &= ~VOIP_STATE_REC_PLAY_CAL;
	  	 am.state &= ~AM_STATE_VOIP;
		 if( am.state == 0 ) {
            VBI_End();        
            AFE_TurnOff8K();
         } 
	  	 break;
		 
      default:
         ASSERT(0);
         break;                  
   }    

   if((0 != type) && (100 != type)){//case in dedicate mode
      //enable hw IIR(reset to defulat). --> request by YT
      //and reset to use HW SRC
      *AFE_VLB_CON &= ~(0x01<<3);  /* do not bypass hardware IIR filter */
      *DP_AUDIO_PAR |= 0x10; //(VOICE_16K_SWITCH_FLAG); //using hw src by default

   }
    
    return;
#endif  // chip compile option
}


void  AM_PCM_EX_On( uint32 type )
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    PCM_Ex_Config *p_config = (PCM_Ex_Config *)type;
    uint32 am_type = p_config->am_type;
#if defined(__VAD_SUPPORT__)
    kal_uint8 aud_func = L1SP_VOICE;
#else
    kal_uint8 aud_func = L1SP_MAX_AUDIO;
#endif
    
#if defined(__VAD_SUPPORT__)
    if ( !VAD_IsEnable() )
#endif
       AFE_Stop_and_Wait_DelayOff(L1SP_SPEECH, ASP_FS_8K);
    
    if (   am_type == AM_PCMEX_TYPE_IDLE 
        || am_type == AM_PCMEX_TYPE_DACA_IDLE
       )
    {
        AFE_SetDigitalGain(L1SP_SPEECH, 100);
#if defined(AEC_ENABLE)
#if defined(__KARAOKE_SUPPORT__)
        if(!Media_IsKaraoke())
#endif
        {
            DSP_DynamicDownload(DDID_NOISE_REDUCTION);
        }
#endif
        aud_func = L1SP_SPEECH;
    }
    else if(!(am.state & AM_STATE_SPEECH)) 
    {
        aud_func = L1SP_VOICE;
    }
    
#if defined(__VIBRATION_SPEAKER_SUPPORT__) && (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
    AM_Write_Vibr_Sph_Notch_Flt();
#endif

    AM_Enqueue(AM_DSP_PCM_EX_On, type, false);

    // turn on speaker or microhpone by different AM application type. 
    {
#if defined(__CVSD_CODEC_SUPPORT__)
        kal_uint32 uCurrentSpMode = L1SP_GetSpeechMode();
        if (   uCurrentSpMode != SPH_MODE_BT_EARPHONE
            && uCurrentSpMode != SPH_MODE_BT_CARKIT
           )
#endif
        {
            if(aud_func < L1SP_MAX_AUDIO)
            {
                if (am_type == P2W_APP_TYPE_REC_ONLY_CAL)
                {   // Case when calibration with record only
                    AFE_TurnOnMicrophone(aud_func);
                }
                else
                {   // Default
#if defined(__VAD_SUPPORT__)
                    if ( !VAD_IsEnable() )
#endif
                        AFE_TurnOnSpeaker(aud_func);
                    
                    AFE_TurnOnMicrophone(aud_func);
                }
            }
        }
    }
    
    AM_FlushQFunction();
    
    if (am_type == AM_PCMEX_TYPE_IDLE)
    {
        l1sp_updateSpeAppMask(0xffff, false);
        l1sp_updateSpeAppMask(SPH_ENH_MASK_ULNR|SPH_ENH_MASK_AGC|SPH_ENH_MASK_AEC|SPH_ENH_MASK_DLNR, true);
        SetSpeechEnhancement(true);
    }
    
#else   // chip compile option
   kal_uint32 uCurrentSpMode;
   kal_uint8 aud_func = L1SP_MAX_AUDIO;
   AFE_Stop_and_Wait_DelayOff(L1SP_SPEECH, ASP_FS_8K);
   if( type == P2W_APP_TYPE_VOIP || P2W_APP_TYPE_REC_ONLY_CAL == type || P2W_APP_TYPE_REC_PLAY_CAL == type ) 
   {
      AFE_SetDigitalGain( L1SP_SPEECH, 100 );  
#if defined(AEC_ENABLE)
#if defined(__KARAOKE_SUPPORT__)
        if(!Media_IsKaraoke())
#endif
        {
            DSP_DynamicDownload(DDID_NOISE_REDUCTION);
        }
#endif
      aud_func = L1SP_SPEECH;
   }
   else if(!(am.state & AM_STATE_SPEECH))
      aud_func = L1SP_VOICE;

   AM_Enqueue( AM_DSP_PCM_EX_On, type, false );
   
#if defined(__CVSD_CODEC_SUPPORT__)
   uCurrentSpMode = L1SP_GetSpeechMode();
   if( uCurrentSpMode != SPH_MODE_BT_EARPHONE && uCurrentSpMode != SPH_MODE_BT_CARKIT )
#endif
   {   
      if(aud_func < L1SP_MAX_AUDIO)
      {
   	     if(type == P2W_APP_TYPE_REC_ONLY_CAL)
	     { //case when calibration with record only
    	    AFE_TurnOnMicrophone( aud_func );
	     }
	     else 
	     { //default
    	    AFE_TurnOnSpeaker( aud_func );
    	    AFE_TurnOnMicrophone( aud_func );
   	     }
      }
   }
#endif  // chip compile option
    
    return;
}


void  AM_PCM_EX_Off( uint32 type )
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    PCM_Ex_Config *p_config = (PCM_Ex_Config *)type;
    uint32 am_type = p_config->am_type;
#if defined(__VAD_SUPPORT__)
    kal_uint8 aud_func = L1SP_VOICE;
#else
    kal_uint8 aud_func = L1SP_MAX_AUDIO;
#endif
    if (am_type == AM_PCMEX_TYPE_IDLE)
    {
        SetSpeechEnhancement(false);
        l1sp_updateSpeAppMask(0xffff, false);
    }

    if (   am_type == AM_PCMEX_TYPE_IDLE 
        || am_type == AM_PCMEX_TYPE_DACA_IDLE
       )
    {
        aud_func = L1SP_SPEECH;
    }
    else
    {
        aud_func = L1SP_VOICE;
    }

    // turn off speaker or microhpone by different AM application type. 
    if (aud_func < L1SP_MAX_AUDIO)
    {
        if (am_type == P2W_APP_TYPE_REC_ONLY_CAL)
        {   //case when calibration with record only
#if defined(__VAD_SUPPORT__)
            if (!(am.state & AM_STATE_VOICE))
#endif
               AFE_TurnOffMicrophone(aud_func);
        }
        else
        {
#if !defined(__VAD_SUPPORT__)
            AFE_TurnOffSpeaker(aud_func);
#endif
#if defined(__VAD_SUPPORT__)
            if (!(am.state & AM_STATE_VOICE))
#endif
               AFE_TurnOffMicrophone(aud_func);
        }
    }
    
    AM_Enqueue(AM_DSP_PCM_EX_Off, type, false);
    AM_FlushQFunction();
#else   // chip compile option
   kal_uint8 aud_func = L1SP_MAX_AUDIO;

   //if( type == 2 )
   if( type == P2W_APP_TYPE_VOIP || P2W_APP_TYPE_REC_ONLY_CAL == type || P2W_APP_TYPE_REC_PLAY_CAL == type ) 
      aud_func = L1SP_SPEECH;
   else if(!(am.state & AM_STATE_SPEECH))
      aud_func = L1SP_VOICE;

   if(aud_func < L1SP_MAX_AUDIO)
   {
   	  if(type == P2W_APP_TYPE_REC_ONLY_CAL){ //case when calibration with record only
	      AFE_TurnOffMicrophone( aud_func );
   	  } else {
	      AFE_TurnOffSpeaker( aud_func );
    	  AFE_TurnOffMicrophone( aud_func );
   	  }
   }

   AM_Enqueue( AM_DSP_PCM_EX_Off, type, false );
   AM_FlushQFunction();
#endif  // chip compile option
    
    return;
}

bool AM_IsVoIPOn( void )
{
   return( (bool)((am.state & AM_STATE_VOIP) != 0) );
}

/* ========================================================================= */
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
void AM_SetPostProcessCtrl( uint16 ppMask, uint16 ppCtrl )
{
   uint32 savedMask;
   uint16 pp_ctrl_cache;

   savedMask = SaveAndSetIRQMask();
   pp_ctrl_cache = *DP2_AUDIO_PP_CONTROL & ~ppMask;
   pp_ctrl_cache |= ((ppCtrl & ppMask) | 0x0001);
   *DP2_AUDIO_PP_CONTROL |= pp_ctrl_cache;
   RestoreIRQMask(savedMask);
}

void AM_ClearPostProcessCtrl( uint16 ppMask )
{
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   *DP2_AUDIO_PP_CONTROL &= ~ppMask;
   RestoreIRQMask(savedMask);
}
#endif
uint16 AM_Status( void ) 
{
   return am.state;   
}

void AM_EnableToneLoopBackFlag( kal_bool param )
{
   if(param)
      am.toneLoopbackRec = KAL_TRUE;
   else
      am.toneLoopbackRec = KAL_FALSE;
}

/* ========================================================================= */
/*   Functions for Modem LoopBack Test                                       */
/* ========================================================================= */

bool AM_IsLoopBackTest( void )
{   
   return am.fLoopBack; 
}

void AM_SetLoopBackTest(bool enable)
{
   if(AM_IsSpeechOn()) 
   {  
      if(enable)   
         *DP_SC_FLAGS = 0x632;            
      else if(am.fLoopBack)    
         *DP_SC_FLAGS = 0x633;       
   }         
   am.fLoopBack = enable;          
} 

/* ========================================================================= */
/*   Functions for Buletooth Cordless Mode                                   */
/* ========================================================================= */
static void AM_DSP_BTCordlessOn( uint32 data )
{
   (void)data;
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   //disable hw IIR (bypass). --> request by YT
   //and use the SW SRC
   *DP_AUDIO_PAR &= ~(0x10); //VOICE_16K_SWITCH_FLAG, using software SRC
   *AFE_VLB_CON |= (0x01<<3);  /* Bypass hardware IIR filter */

   //Setup the SW SRC
   *DP_SCR_CTRL = 0x2006; 
#endif
   
   AFE_TurnOnSpeaker( L1SP_VOICE );
   AFE_TurnOnMicrophone( L1SP_VOICE );
   am.state |= AM_STATE_VOICE;
   am.DL_UL_path = SPH_BOTH_PATH;
   AFE_TurnOn8K();
   if ( am.state == 0 ) {
      VBI_Reset();
   }
   
}

void AM_BTCordlessOn( void )
{
   AM_Enqueue( AM_DSP_BTCordlessOn, 0, false );
   
   AM_FlushQFunction();
}

static void AM_DSP_BTCordlessOff( uint32 data )
{
   (void)data;
   am.state &= ~AM_STATE_VOICE;
   if ( am.state == 0 ) {
      VBI_End();      
      AFE_TurnOff8K();
   }
   am.DL_UL_path = SPH_BOTH_PATH;
   AFE_TurnOffMicrophone( L1SP_VOICE );
   AFE_TurnOffSpeaker( L1SP_VOICE );
}

void AM_BTCordlessOff( void )
{
   AM_Enqueue( AM_DSP_BTCordlessOff, 0, false );
   
   AM_FlushQFunction();
}

#if defined(__PCM_CLOCK_SWITCH_SUPPORT__) || defined(__AUDIO_AT_CMD__)
static void AM_DSP_PCMClockOn (uint32 data)
{
    (void)data;
    
    if (AFE_IsInOffState())
    {
        *DSP_AFE_VDSP_CON_CTRL |= 0x1;
        AFE_SetSwitchPCMBitClk(KAL_TRUE);
        am.DL_UL_path = SPH_BOTH_PATH;
        AFE_TurnOn8K();
        VBI_Reset();
        am.pcm_clock_flag = KAL_TRUE;
    }
    
    return;
}

void AM_PCMClockOn (void)
{
    AM_Enqueue(AM_DSP_PCMClockOn, 0, false);
    AM_FlushQFunction();
    return;
}

static void AM_DSP_PCMClockOff (uint32 data)
{
    (void)data;
    
    if (am.pcm_clock_flag)
    {
        VBI_End();
        AFE_TurnOff8K_Direct();
        am.pcm_clock_flag = KAL_FALSE;
        AFE_SetSwitchPCMBitClk(KAL_FALSE);
        *DSP_AFE_VDSP_CON_CTRL &= ~0x1;
    }
    
    return;
}

void AM_PCMClockOff (void)
{
    AM_Enqueue(AM_DSP_PCMClockOff, 0, false);
    AM_FlushQFunction();
    return;
}
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)

bool AM_IsConflictState( void )
{
   if( am.state & AM_CONFLICT_STATE )
      return true;
   else
      return false;
}

#ifdef _FWE_SUPPORT_
void AM_SetFWE(bool on)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    if (on)
    {
        *DSP_SPH_SCH_IMPROVE_CTRL |= 0x0020;
    }
    else
    {
        *DSP_SPH_SCH_IMPROVE_CTRL &= ~0x0020;
    }
#else   // chip compile option
   if(on){
      *DSP_AUDIO_CTRL2 |= 0x4000; //turn on FWE  
   }else{
      *DSP_AUDIO_CTRL2 &= ~0x4000; //turn off FWE  
   }
#endif  // chip compile option
}

bool AM_IsFWEOn( void )
{      
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    return ((*DSP_SPH_SCH_IMPROVE_CTRL) & 0x0020)? true : false;
#else   // chip compile option
   return ((*DSP_AUDIO_CTRL2) & 0x4000)? true : false;
#endif  // chip compile option
}
#endif

#if defined( NEW_BLOCK_FILTER_SUPPORT )
//Run under task level
void AM_SwitchCompFilter( kal_uint16 par )
{
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   if( par == 0 ){
      *DP_AUDIO_PAR &= ~( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
      g_Compen_Blk_Flt = COMPEN_BLOCK_FLT_PAR;
   }
   else{
      *COMPEN_BLOCK_FLT_PAR_PTR &= ~( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
      g_Compen_Blk_Flt = DP_AUDIO_PAR;
   }
   RestoreIRQMask(savedMask);
   savedMask = (kal_uint32)g_Compen_Blk_Flt;
   L1Audio_Msg_SWITCH_FILT( par, savedMask );
}
void AM_TurnOnBlockFilter( void )
{
   AFE_TurnOnFIR( L1SP_SPEECH );
}

void AM_TurnOffBlockFilter( void )
{
   AFE_TurnOffFIR( L1SP_SPEECH );
}
#endif

void AM_16KWBOn(void)
{
/*
     VMODE4K	DSP data mode selection
0	8k mode
1	4k mode

*/   
#if defined(MT6268)

   *COMPEN_BLOCK_FLT_PAR_PTR &= ~( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
   *DP_AUDIO_PAR |= (VOICE_WB_AMR_FLAG);
   *DP_AUDIO_PAR &= ~( VOICE_SIDETONE_FILTER_FLAG );
   *DP_16k_CompenFlt_Flag = 0;
   *DP_AUDIO_16K_PAR_PATCH &= ~ (kal_uint16)((0x1 << 0)| (0x1 << 1) | (0x1 << 3) | (0x1 << 4));
   *VLBCR |= (0x01<<3);                /* Bypass hardware IIR filter*/
   *AFE_VAC_DCON1 &= ~0x0200;

/*
    kal_prompt_trace(MOD_L1SP,"COMPEN_BLOCK_FLT_PAR_PTR[%08x]  = (%04x) \r\n", COMPEN_BLOCK_FLT_PAR_PTR, *COMPEN_BLOCK_FLT_PAR_PTR);
    kal_prompt_trace(MOD_L1SP,"DP_AUDIO_PAR[%08x]              = (%04x) \r\n", DP_AUDIO_PAR, *DP_AUDIO_PAR);
    kal_prompt_trace(MOD_L1SP,"DP_16k_CompenFlt_Flag[%08x]    = (%04x) \r\n", DP_16k_CompenFlt_Flag, *DP_16k_CompenFlt_Flag);
    kal_prompt_trace(MOD_L1SP,"VLBCR[%08x]                     = (%04x) \r\n", VLBCR, *VLBCR);    
    kal_prompt_trace(MOD_L1SP,"AFE_VAC_DCON1[%08x]             = (%04x) \r\n", AFE_VAC_DCON1, *AFE_VAC_DCON1);    
    kal_prompt_trace(MOD_L1SP,"DP_AUDIO_16K_PAR_PATCH[%08x]    = (%04x) \r\n", DP_AUDIO_16K_PAR_PATCH, *DP_AUDIO_16K_PAR_PATCH);    
*/
#endif

}

void AM_VBIEnd(void)
{
    VBI_End();
}

#if defined(__IPS_SUPPORT__)
void Security_DSP_AudioPlaybackOn(void)
{
   _AfeForceTurnOnAudioClock();
#if defined(MT6236) || defined(MT6236B)
   AM_DSP_AudioPlaybackOn( (ASP_TYPE_PCM_HI<<16) + ASP_FS_48K );
#elif defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   AM_DSP_AudioPlaybackOn( (ASP_TYPE_IPS<<16) + ASP_FS_48K );
#endif
}
void Security_DSP_AudioPlaybackOff(void)
{
   _AfeForceTurnOffAudioClock();
#if defined(MT6236) || defined(MT6236B)
   AM_DSP_AudioPlaybackOff((ASP_TYPE_PCM_HI<<16) + ASP_FS_48K );
#elif defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   AM_DSP_AudioPlaybackOff((ASP_TYPE_IPS<<16) + ASP_FS_48K );
#endif
}
#endif // defined(__IPS_SUPPORT__)

#if __AFE_SW_DC_COMPENSATION__
kal_bool AM_IsVBIEnd(void)
{
    return (*SHARE2_M2DI1 == 0x0839) ?  KAL_TRUE : KAL_FALSE;
}

kal_bool AM_IsVBIReset(void)
{
    return (*SHARE2_M2DI1 == 0x0838) ?  KAL_TRUE : KAL_FALSE;
}

#endif

static void AM_DSP_VBI_END()
{
   VBI_End();
}

void AM_Force_VBI_END_IN_TASK()
{
#if __AFE_SW_DC_COMPENSATION__
   if (kal_if_hisr() || kal_if_lisr())
   {
      ASSERT(0);
   }
   AM_FlushQFunction();
   if(AM_IsVBIReset()){
      AM_Enqueue( AM_DSP_VBI_END, NULL, false);
      kal_sleep_task(1);
   }
#endif
}

#if defined(__AUDIO_BT_FORCE_VBI_RESET__)
void AM_BT_Force_VBI_Reset(kal_bool enable)
{
   am.fBTForceVBIReset = enable;
   if (!enable)
      am.fResetCount = KAL_FALSE;
}

kal_bool AM_IsBTForceVBIReset(void)
{
   return am.fBTForceVBIReset;
}

void AM_BT_ExecuteVBIReset(void)
{
   if (am.fResetCount) {
      am.fResetCount = KAL_FALSE;
      VBI_Reset();
   }
}
#endif
kal_uint32 AM_Get2GResyncThreshold(void)
{
   return AM_2G_RESYNC_THRESHOLD;
}    

kal_uint8 AM_GetDLULPath(void)
{
  if((!(am.state & AM_STATE_SPEECH)) || (am.DL_UL_path != SPH_BOTH_PATH)) 
  {
    if((am.DL_UL_path == SPH_VOICE_RECORD) || (am.DL_UL_path == SPH_VOICE_PCM2WAY_UL))     
		return UL_PATH; //ul
	else if((am.DL_UL_path == SPH_VOICE_PLAYBACK)||(am.DL_UL_path == SPH_VOICE_PCM2WAY_DL))
		return DL_PATH;//dl
  }
 
  return DL_UL_BOTH_PATH; //dl+ul
 
}

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

static struct
{
    uint8   device;
    uint8   enc_mod;
    uint8   dec_mod;
    uint8   sub_channel;
    uint8   dtx;
    bool    fwe;
} pseudo_sal_impl;

static const uint16 CodecSilencePattern[][17] = {
   {  0x4820,0xD617,0x0284,0x2480,0x9249,0x8924,0x8002,0x4924,          
      0x2492,0x0289,0x2480,0x9249,0x8924,0x8002,0x4924,0x2492,                          
      0x0009                                                   },       /* FR           */                
   {  0x4E20,0x875E,0x5473,0x8482,0x00E9,0x0000,0x0000         },       /* HR           */
   {  0x7A10,0x092D,0xB55F,0x7C06,0x185C,0xDE06,0x4230,0x0103,          
      0xA012,0x001A,0x0000,0x0000,0x0D6C,0x0000,0x0000,0x0000  },       /* EFR          */                
   {  0x00e2,0x5dfc,0xf095,0xcd4e,0x24da,0x0e04,0xf0fb,0x4f2e,          
      0x4430,0x9fa8,0x0319,0x56c0,0xc144,0x0278,0x70ea,0x0004  },       /* AMR12.2      */                
   {  0xe00a,0xf2e7,0x516b,0x19a1,0xc10d,0x145a,0x4c96,0x25e0,          
      0x5ce6,0x17b9,0x0982,0x225d,0x00c4                       },       /* AMR10.2      */                
   {  0x033c,0xe5cd,0xd9fb,0x387f,0x420c,0x8c99,0x58d7,0x1156,          
      0x397f,0x1074                                            },       /* AMR7.95      */                
   {  0xe00a,0xf2e7,0x9ac5,0x4433,0x185b,0x3e05,0xdc64,0xc886,          
      0xcd2e,0x0000                                            },       /* AMR7.4       */                
   {  0xe00a,0xf2e7,0x7761,0x0486,0x0dd5,0xf47c,0x21b0,0xf547,          
      0x0002                                                   },       /* AMR6.7       */                
   {  0xe00a,0xf2e7,0xb196,0xa8ae,0xbcb7,0x6fb9,0x0193,0x002e  },       /* AMR5.9       */
   {  0x3c0a,0x7e51,0x652c,0x5e91,0xd023,0xea5a,0x005b         },       /* AMR5.15      */
   {  0x3c0a,0x3e51,0x6529,0x3a49,0x977f,0x3565                },       /* AMR4.75      */
   {0xe00a,0xf2e7,0x7761,0x0486,0x0dd5,0xf47c,0x21b0,0xf547,0x0002},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000}     /* AMR-WB 6.60  */
};

static const uint8 CodecPatternLength[] = {
   (uint8)((260 + 15) / 16),           /*  FR       */
   (uint8)((112 + 15) / 16 + 1),       /*  HR       */
   (uint8)((244 + 15) / 16),           /* EFR       */
   (uint8)((244 + 15) / 16),           /* AMR 12.2K */
   (uint8)((204 + 15) / 16),           /* AMR 10.2K */
   (uint8)((159 + 15) / 16),           /* AMR 7.95K */
   (uint8)((148 + 15) / 16),           /* AMR 7.4K  */
   (uint8)((134 + 15) / 16),           /* AMR 6.7K  */
   (uint8)((118 + 15) / 16),           /* AMR 5.9K  */
   (uint8)((103 + 15) / 16),           /* AMR 5.15K */
   (uint8)(( 95 + 15) / 16),           /* AMR 4.75K */
   (uint8)((132 + 15) / 16),           /* AMR-WB 6.60  */
   (uint8)((177 + 15) / 16),           /* AMR-WB 8.85  */
   (uint8)((253 + 15) / 16),           /* AMR-WB 12.65 */
   (uint8)((285 + 15) / 16),           /* AMR-WB 14.25 */
   (uint8)((317 + 15) / 16),           /* AMR-WB 15.85 */
   (uint8)((365 + 15) / 16),           /* AMR-WB 18.25 */
   (uint8)((397 + 15) / 16),           /* AMR-WB 19.85 */
   (uint8)((461 + 15) / 16),           /* AMR-WB 23.05 */
   (uint8)((477 + 15) / 16),           /* AMR-WB 23.85 */
};

const uint16 DSP_2GSCH_MARGIN_TABLE[] = {
   0x38+(16<<10)+(2<<8),     /* 1.2 : FR        */
   0x38+(12<<10)+(2<<8),     /* 1.2 : HR        */
   0x38+(16<<10)+(2<<8),     /* 1.2 : EFR       */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 12.2  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 10.2  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 7.95  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 7.4   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 6.7   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 5.9   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 5.15  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 4.75  */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 6.60     */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 8.85     */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 12.65    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 14.25    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 15.85    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 18.25    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 19.85    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 23.05    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 23.85    */
};

const uint16 DSP_2GSCH_DELAY_TABLE_SUBCH0[13][2] =
{    /*  SE      SD  */                    /*   SE  SD   */
   { (0x00B5), 0x0139 },  /* T2 = 0 /13 */ /*  4.9 12.8  */
   { (0x0090), 0x01B4 },  /* T2 = 1 /14 */ /*  3.9 11.8  */
   { (0x006B), 0x018F },  /* T2 = 2 /15 */ /*  2.9 10.8  */
   { (0x0046), 0x016A },  /* T2 = 3 /16 */ /*  1.9  9.8  */
   { (0x00C1), 0x0145 },  /* T2 = 4 /17 */ /*  5.2 13.1  */
   { (0x009C), 0x01C0 },  /* T2 = 5 /18 */ /*  4.2 12.1  */
   { (0x0077), 0x019B },  /* T2 = 6 /19 */ /*  3.2 11.1  */
   { (0x0052), 0x0176 },  /* T2 = 7 /20 */ /*  2.2 10.1  */
   { (0x002D), 0x0151 },  /* T2 = 8 /21 */ /*  1.2 13.5  */
   { (0x00A8), 0x01CC },  /* T2 = 9 /22 */ /*  4.5 12.5  */
   { (0x0083), 0x01A8 },  /* T2 = 10/23 */ /*  3.5 11.5  */
   { (0x005E), 0x0183 },  /* T2 = 11/24 */ /*  2.5 10.5  */
   { (0x0039), 0x015E }   /* T2 = 12/25 */ /*  1.5 13.8  */
};

const uint16 DSP_2GSCH_DELAY_TABLE_SUBCH1[13][2] =
{      /*  SE      SD  */                       /*   SE  SD   */
   { (0x00B5)+0x25, 0x0139 },  /* T2 = 0 /13 */ /*  4.9 12.8  */
   { (0x0090)+0x25, 0x01B4 },  /* T2 = 1 /14 */ /*  3.9 11.8  */
   { (0x006B)+0x25, 0x018F },  /* T2 = 2 /15 */ /*  2.9 10.8  */
   { (0x0046)+0x25, 0x016A },  /* T2 = 3 /16 */ /*  1.9  9.8  */
   { (0x00C1)+0x25, 0x0145 },  /* T2 = 4 /17 */ /*  5.2 13.1  */
   { (0x009C)+0x25, 0x01C0 },  /* T2 = 5 /18 */ /*  4.2 12.1  */
   { (0x0077)+0x25, 0x019B },  /* T2 = 6 /19 */ /*  3.2 11.1  */
   { (0x0052)+0x25, 0x0176 },  /* T2 = 7 /20 */ /*  2.2 10.1  */
   { (0x002D)+0x25, 0x0151 },  /* T2 = 8 /21 */ /*  1.2 13.5  */
   { (0x00A8)+0x25, 0x01CC },  /* T2 = 9 /22 */ /*  4.5 12.5  */
   { (0x0083)+0x25, 0x01A8 },  /* T2 = 10/23 */ /*  3.5 11.5  */
   { (0x005E)+0x25, 0x0183 },  /* T2 = 11/24 */ /*  2.5 10.5  */
   { (0x0039)+0x25, 0x015E }   /* T2 = 12/25 */ /*  1.5 13.8  */
};

static volatile uint16* Pseudo_SALI_PcmEx_GetBuf(Pseudo_Sal_PcmEx_BufId_t id)
{
	
	volatile uint16 *addr = 0;

	switch(id){
		
		case PSEUDO_SAL_PCMEX_PNW_BUF_UL1:
			addr = DSP_SPH_PNW_BUF_UL1;
			break;
		case PSEUDO_SAL_PCMEX_PNW_BUF_UL2:
			addr = DSP_SPH_PNW_BUF_UL2;
			break;
		case PSEUDO_SAL_PCMEX_PNW_BUF_DL1:
			addr = DSP_SPH_PNW_BUF_DL1;
			break;		
		case PSEUDO_SAL_PCMEX_PNW_BUF_DL2:
			addr = DSP_SPH_PNW_BUF_DL2;
			break;
		case PSEUDO_SAL_PCMEX_DACA_BUF_UL:
			addr = DSP_SPH_DACA_UL_BUF;
			break;
		case PSEUDO_SAL_PCMEX_DACA_BUF_DL:
			addr = DSP_SPH_DACA_DL_BUF;
			break;
		case PSEUDO_SAL_PCMEX_BUF_SE:
			addr = DSP_DM_ADDR(5, *DSP_SPH_SE_BUF_PTR);
			break;
		case PSEUDO_SAL_PCMEX_BUF_SD:
			addr = DSP_DM_ADDR(5, *DSP_SPH_SD_BUF_PTR);
			break;	
        case PSEUDO_SAL_PCMEX_BUF_SE2:  // Not supported in MT6260
		default:
			ASSERT(0);
			break;
	}

	return DSP_DM_ADDR(5, *addr);
}

static uint16 Pseudo_SALI_PcmEx_GetBufLen(Pseudo_Sal_PcmEx_BufId_t id)
{
    uint16 len = 0;

	switch(id)
	{
		case PSEUDO_SAL_PCMEX_PNW_BUF_UL1:
		case PSEUDO_SAL_PCMEX_PNW_BUF_UL2:
			len = *DSP_SPH_PNW_LEN_UL;
			break;
		case PSEUDO_SAL_PCMEX_PNW_BUF_DL1:
		case PSEUDO_SAL_PCMEX_PNW_BUF_DL2:
			len = *DSP_SPH_PNW_LEN_DL;
			break;
		case PSEUDO_SAL_PCMEX_BUF_SE:
			len = *DSP_SPH_BAND_FLAG & 0x4 ? 320 : 160; // bit2 --> codec band, bit1 --> sch DL band, bit0 --> sch UL band
			break;
		case PSEUDO_SAL_PCMEX_BUF_SD:
			len = *DSP_SPH_BAND_FLAG & 0x2 ? 320 : 160; // bit2 --> codec band, bit1 --> sch DL band, bit0 --> sch UL band
			break;
		case PSEUDO_SAL_PCMEX_DACA_BUF_UL:
		    len = *DSP_SPH_DACA_LEN_UL;
		    break;
		case PSEUDO_SAL_PCMEX_DACA_BUF_DL:
			len = *DSP_SPH_DACA_LEN_DL;
			break;
        case PSEUDO_SAL_PCMEX_BUF_IDLE_SE:
            len = *DSP_SPH_BAND_FLAG & 0x1 ? 320 : 160; // bit2 --> codec band, bit1 --> sch DL band, bit0 --> sch UL band
            break;
        case PSEUDO_SAL_PCMEX_BUF_SE2:  // MT6260 does not support dual microphone
		default:
			ASSERT(0);
			break;
	}

	return len;
}

static volatile uint16* Pseudo_SALI_GetFltCoefAddr(uint8 type)
{
	volatile uint16 *addr = 0;
	
	switch(type)
	{
		case PSEUDO_SALI_FLTCOEF_TYPE_SIDETONE:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_ST);
			break;
		case PSEUDO_SALI_FLTCOEF_TYPE_BKF_NB_UL:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_BKF_NB_UL);
			break;
		case PSEUDO_SALI_FLTCOEF_TYPE_BKF_NB_DL:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_BKF_NB_DL);
			break;
		case PSEUDO_SALI_FLTCOEF_TYPE_SRC:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_SRC);
			break;	
		case PSEUDO_SALI_FLTCOEF_TYPE_AGC:
			addr = DSP_PM_ADDR(3, FLTCOEF_TYPE_AGC_ADDR);
			break;	
		case PSEUDO_SALI_FLTCOEF_TYPE_DMNR_NB:      // MT6260 does not support dual microphone
		case PSEUDO_SALI_FLTCOEF_TYPE_DMNR_WB:      // MT6260 does not support dual microphone
        case PSEUDO_SALI_FLTCOEF_TYPE_BKF_WB_UL:    // MT6260 does not support wideband block filter
		case PSEUDO_SALI_FLTCOEF_TYPE_BKF_WB_DL:    // MT6260 does not support wideband block filter
		default:
            ASSERT_REBOOT(0);
	}

	return addr;
}

static void Pseudo_SALI_AppSpec_Control(uint8 app_type, uint8 on)
{
	switch(app_type)
	{
		case PSEUDO_SAL_APP_TYPE_2GCall:
		    if (on)
            {
                DSP_SPH_APP_MODE = SPH_APP_MODE_CALL_2G;
                *DSP_SPH_SCH_IMPROVE_CTRL &= ~0x4000; //Enable DSH_2G_UL_CRC
            }
            else
            {
                DSP_SPH_APP_MODE = SPH_APP_MODE_NONE;
                *DSP_SPH_SCH_IMPROVE_CTRL |=  0x4000;
            }
            break;
		case PSEUDO_SAL_APP_TYPE_3GCall:
			if (on)
            {
                DSP_SPH_APP_MODE = SPH_APP_MODE_CALL_3G;
	   		    *DSP_SPH_SCH_IMPROVE_CTRL &= ~0x4000; //Enable DSH_2G_UL_CRC
			}
			else
            {
                DSP_SPH_APP_MODE = SPH_APP_MODE_NONE;
		   	    *DSP_SPH_SCH_IMPROVE_CTRL |=  0x4000; 
			}
			break;
	}
}

static void Pseudo_SALI_Disable_Codec()
{
    *DSP_SPH_COD_CTRL &= 0xFF00;
}

static void Pseudo_SALI_3G_Set_RxType(uint16 rx_type)
{
	*DSP_SPH_3G_SD_DATA_HDR = rx_type & 0xE;
}

static void Pseudo_SALI_Set_3G(bool on)
{
    *DSP_SPH_3G_CTRL = on ? 1 : 0;
}

static void Pseudo_SALI_Init()
{
	*DSP_SPH_HR_FR_CTRL = 0x0E;
	*DSP_SPH_SCH_IMPROVE_CTRL = 0x0405;
    
    pseudo_sal_impl.device = 0;
    pseudo_sal_impl.enc_mod = 0;
    pseudo_sal_impl.dec_mod = 0;
    pseudo_sal_impl.sub_channel = 0;
    
    pseudo_sal_impl.fwe = false;
}

static void Pseudo_SALI_Enable_Codec(uint16 enc_mod, uint16 dec_mod)
{
    pseudo_sal_impl.enc_mod = enc_mod;
    pseudo_sal_impl.dec_mod = dec_mod;
    
    *DSP_SPH_COD_MODE = dec_mod | (enc_mod << 8);               
    *DSP_SPH_COD_VAD = enc_mod > 2 ? 1 : 0;
    *DSP_SPH_COD_CTRL |= 0x33;
}

static void Pseudo_SALI_Set_Sph_Nml_Mod(bool on)
{
    if (on)
    {
        *DSP_SPH_8K_CTRL |= 0x8000;
    }
	else
    {
        *DSP_SPH_8K_CTRL &= ~0x8000;
    }
}

static void Pseudo_SALI_Fill_Enc_Silence(uint8 app_type, uint16 codec)
{
    volatile uint16 *addr = 0;
    
    if (app_type == PSEUDO_SAL_APP_TYPE_2GCall)
    {
        addr = DSP_SPH_2G_SE_DATA_HDR;
    }
	else if (app_type == PSEUDO_SAL_APP_TYPE_3GCall)
    {
        addr = DSP_SPH_3G_SE_DATA_HDR;
    }
	else
    {
        ASSERT(0);
    }
    
    if (codec >= 0x20)
    {
        codec = codec - 0x20 + 0x0B;
    }
    
    if (codec >= (sizeof(CodecPatternLength)/sizeof(CodecPatternLength[0])))
    {
        return;
    }
    
    {
        const uint16 *pat_info = CodecSilencePattern[codec];
        uint32 len = (uint16)CodecPatternLength[codec];
        uint32 I;

        *addr++ = 2;
        for (I = 0; I < len; I++)
        {
            *addr++ = *pat_info++;
        }
    }
}

static void Pseudo_SALI_Set_2G_Sch_Delay(uint8 codec_mod, uint8 subchannel)
{
    uint16 n = (uint16)L1D_GetT2();
	uint16 delay = L1D_Get_Win_TQ_WRAP() - TQ_WRAP_COUNT;

	pseudo_sal_impl.sub_channel = subchannel;

    if (n >= 13)
    {
        n -= 13;
    }

    if (codec_mod >= 0x20)
    {
        codec_mod -= 0x20 - 0x0B;
    }
    
    ASSERT(codec_mod < (sizeof(DSP_2GSCH_MARGIN_TABLE)/sizeof(DSP_2GSCH_MARGIN_TABLE[0])));
    
    if (subchannel == 0)
    {
        *DSP_SPH_DEL_R = DSP_2GSCH_DELAY_TABLE_SUBCH0[n][0];
        *DSP_SPH_DEL_W = DSP_2GSCH_DELAY_TABLE_SUBCH0[n][1];
    }
    else
    {
        *DSP_SPH_DEL_R = DSP_2GSCH_DELAY_TABLE_SUBCH1[n][0];
        *DSP_SPH_DEL_W = DSP_2GSCH_DELAY_TABLE_SUBCH1[n][1];
        n += 13;
    }
    
    *DSP_SPH_DEL_M = DSP_2GSCH_MARGIN_TABLE[codec_mod];
    *DSP_SPH_DEL_O = delay;
}

static void Pseudo_SALI_3G_SetDtx(bool on)
{
    pseudo_sal_impl.dtx = on;
    
    if (on)
    {
        *DSP_SPH_COD_CTRL |= 0x4;
    }
	else
    {
        *DSP_SPH_COD_CTRL &= ~0x4;
    }
}

static void Pseudo_SALI_Set_Sch_Delay(uint16 delR, uint16 delW, uint16 delM, uint16 delO)
{
    *DSP_SPH_DEL_R = delR;
    *DSP_SPH_DEL_W = delW;
    *DSP_SPH_DEL_M = delM;
    *DSP_SPH_DEL_O = delO;
}

static void Pseudo_SALI_Upd_3G_Enc_Rate(uint16 enc_mod)
{
	*DSP_SPH_3G_SE_RATE = enc_mod;
}

static void Pseudo_SALI_Upd_3G_Dec_Rate(uint16 dec_mod)
{
	*DSP_SPH_3G_SD_RATE = dec_mod;
}

static bool Pseudo_SALI_Int_Resolve(uint16 iid, uint32 *sph_int)
{
    uint32 val = 0;
    uint16 mask = 0;
    volatile uint16 *ptr = 0;
    bool from_sph = true;

    switch (iid)
    {
        case DSP_IID_SPEECH_UL_ID:
            mask = *DSP_SPH_D2C_UL_INT;
            if (mask & 0x0001)
            {
                val += PSEUDO_SAL_DSPINT_ID_REC_PCM;
            }
            if (mask & 0x0002)
            {
                val += PSEUDO_SAL_DSPINT_ID_REC_EPL;
            }
            if (mask & 0x0004)
            {
                val += PSEUDO_SAL_DSPINT_ID_PNW_UL;
            }
		    if (mask & 0x0008)
            {
                val += PSEUDO_SAL_DSPINT_ID_DACA_UL;
            }
		    if (mask & 0x0010)
            {
                val += PSEUDO_SAL_DSPINT_ID_3G_UL;
            }
            if (mask & 0x0020)
            {
                val += PSEUDO_SAL_DSPINT_ID_BGS_UL;
            }
            *DSP_SPH_D2C_UL_INT = 0;
            break;
        case DSP_IID_SPEECH_DL_ID:
            mask = *DSP_SPH_D2C_DL_INT;
            if (mask & 0x0001)
            {
                val += PSEUDO_SAL_DSPINT_ID_REC_VM;
            }
		    if (mask & 0x0004)
            {
                val += PSEUDO_SAL_DSPINT_ID_PNW_DL;
            }
		    if (mask & 0x0008)
            {
                val += PSEUDO_SAL_DSPINT_ID_DACA_DL;
            }
		    if (mask & 0x0010)
            {
                val += PSEUDO_SAL_DSPINT_ID_3G_DL;
            }
		    if (mask & 0x0020)
            {
                val += PSEUDO_SAL_DSPINT_ID_BGS_DL;
            }
		    if (mask & 0x0040)
            {
                val += PSEUDO_SAL_DSPINT_ID_AVBT;
            }
            *DSP_SPH_D2C_DL_INT = 0;
            break;
        default:
            from_sph = false;
            break;
    }
    
    *sph_int = val;
    return from_sph;
}

static void Pseudo_SALI_PcmEx_Config(Pseudo_Sal_PCMEx_t *cfg)
{
    switch (cfg->type)
    {
        case PSEUDO_SAL_PCMEX_TYPE_PNW:
            {
                kal_uint16 ctrl_UL = *DSP_SPH_PNW_CTRL_UL;
                kal_uint16 ctrl_DL = *DSP_SPH_PNW_CTRL_DL;
                
                ctrl_UL = cfg->UL_M2D_on       ? ctrl_UL | (0x0001 << 11) : ctrl_UL & ~(0x0001 << 11);
                ctrl_UL = cfg->UL_D2M_on       ? ctrl_UL | (0x0001 << 10) : ctrl_UL & ~(0x0001 << 10);
                ctrl_UL = cfg->UL_is_after_enh ? ctrl_UL | (0x0001 <<  9) : ctrl_UL & ~(0x0001 <<  9);
                ctrl_DL = cfg->DL_M2D_on       ? ctrl_DL | (0x0001 << 11) : ctrl_DL & ~(0x0001 << 11);
                ctrl_DL = cfg->DL_D2M_on       ? ctrl_DL | (0x0001 << 10) : ctrl_DL & ~(0x0001 << 10);
                ctrl_DL = cfg->DL_is_after_enh ? ctrl_DL | (0x0001 <<  9) : ctrl_DL & ~(0x0001 <<  9);
                
                *DSP_SPH_PNW_CTRL_UL = ctrl_UL;
                *DSP_SPH_PNW_CTRL_DL = ctrl_DL;
            }
            break;
        case PSEUDO_SAL_PCMEX_TYPE_DACA:
            {
                if (cfg->band == PSEUDO_SAL_PCM_NARROWBAND)
                {
                    *DSP_SPH_DACA_CTRL |=  0x0100;
                }
	        	else
                {
                    *DSP_SPH_DACA_CTRL &= ~0x0100;
                }
            }
            break;
        default:
            ASSERT_REBOOT(0);
            break;
    }
    		
	// An idle PNA, DACA or recording application
	if (cfg->idle)
    {
        if (cfg->swi_on)
        {
            AM_DSP_SetSRCCtrl(0);
            am_set_cod_band((kal_bool)(cfg->band == PSEUDO_SAL_PCM_WIDEBAND));
            Pseudo_SALI_Set_Sch_Delay(cfg->delR, cfg->delW, cfg->delM, 0);
            VBI_Reset();
        }
        else
        {
            VBI_End();
        }
	}
}

static void Pseudo_SALI_PcmEx_SetState(uint8 is_DL, Pseudo_Sal_PcmEx_Type_t type, Pseudo_Sal_PcmEx_State_t sta)
{
    ASSERT_REBOOT(sta == PSEUDO_SAL_PCMEX_ON || sta == PSEUDO_SAL_PCMEX_OFF);
    ASSERT(type == PSEUDO_SAL_PCMEX_TYPE_PNW || type == PSEUDO_SAL_PCMEX_TYPE_DACA);
    
    if (type == PSEUDO_SAL_PCMEX_TYPE_PNW)
    {
        volatile uint16 *addr = is_DL ? DSP_SPH_PNW_CTRL_DL : DSP_SPH_PNW_CTRL_UL;
        
		if (sta == PSEUDO_SAL_PCMEX_ON)
        {
            *addr = (*addr & 0xfff0) | 0x0101;
        }
        else 
        {
            *addr = (*addr & 0xfef0);
		}
	}
	else
    {
        volatile uint16 *addr = DSP_SPH_DACA_CTRL;
        
        if (is_DL)
        {
			if (sta == PSEUDO_SAL_PCMEX_ON)
            {
                *addr = (*addr & 0xff0f) + 0x0010;
            }
			else
            {
                *addr = (*addr & 0xff0f);
            }
		}
		else
        {
			if (sta == PSEUDO_SAL_PCMEX_ON)
            {
                *addr = (*addr & 0xfff0) + 0x0001;
            }
			else
            {
                *addr = (*addr & 0xfff0);
            }
		}
	}
    
    return;
}

static bool Pseudo_SALI_PcmEx_CheckState(uint8 is_DL, Pseudo_Sal_PcmEx_Type_t type, Pseudo_Sal_PcmEx_State_t sta)
{
    bool ret = false;
    
    ASSERT(type == PSEUDO_SAL_PCMEX_TYPE_PNW || type == PSEUDO_SAL_PCMEX_TYPE_DACA);
    
    if (type == PSEUDO_SAL_PCMEX_TYPE_PNW)
    {
        if (is_DL)
        {
            ret = ((*DSP_SPH_PNW_CTRL_DL & 0xf) == sta);
        }
        else
        {
            ret = ((*DSP_SPH_PNW_CTRL_UL & 0xf) == sta);
        }
	}
	else
    {
        if (is_DL)
        {
            ret = ((*DSP_SPH_DACA_CTRL >> 4 & 0xf) == sta);
        }
        else
        {
            ret = ((*DSP_SPH_DACA_CTRL      & 0xf) == sta);
        }
	}

	return ret;
}

static void Pseudo_SALI_ENH_PathEnable(uint8 is_DL, bool on)
{
    *DSP_SPH_UL_COMFORT_NOISE_THRESHOLD = 32;
	*DSP_SPH_UL_COMFORT_NOISE_SHIFT     = (uint16)-12;
    
    if (is_DL)
	{
		if(on)
        {
            *DSP_SPH_ENH_DL_CTRL |=  0x0004;
        }
		else
        {
            *DSP_SPH_ENH_DL_CTRL &= ~0x0004;
        }
	}
	else
    {
        if (on)
        {
            *DSP_SPH_ENH_UL_CTRL |=  0x0002;
        }
		else
        {
            *DSP_SPH_ENH_UL_CTRL &= ~0x0002;
        }
	}
}

volatile uint16 *Pseudo_SALI_Parameter_GetAddr(uint8 type)
{
    volatile uint16 *addr = 0;
    
    switch (type)
    {
        case PSEUDO_SALI_PARAMETER_TYPE_COMMON:
            addr = DSP_DM_ADDR(SPH_EMP_PAGE, *DSP_SPH_EMP_ADDR);
            break;
        case PSEUDO_SALI_PARAMETER_TYPE_MODE:
            addr = DSP_DM_ADDR(SPH_EMP_PAGE, (*DSP_SPH_EMP_ADDR + 12));
            break;
        case PSEUDO_SALI_PARAMETER_TYPE_VOL:
            addr = DSP_DM_ADDR(SPH_EMP_PAGE, (*DSP_SPH_EMP_ADDR + 8));
            break;
        default:
            ASSERT_REBOOT(false);
            break;
	}
    
    return addr;
}

volatile uint16* Pseudo_SAL_PcmEx_GetBuf(Pseudo_Sal_PcmEx_BufId_t id)
{
	return Pseudo_SALI_PcmEx_GetBuf(id);
}

uint16 Pseudo_SAL_PcmEx_GetBufLen(Pseudo_Sal_PcmEx_BufId_t id)
{
	return Pseudo_SALI_PcmEx_GetBufLen(id);
}

volatile uint16* Pseudo_SAL_Sidetone_GetFltCoefAddr()
{
	return Pseudo_SALI_GetFltCoefAddr(PSEUDO_SALI_FLTCOEF_TYPE_SIDETONE);
}

volatile uint16* Pseudo_SAL_BKF_GetFltCoefAddr_NB_UL()
{
	return Pseudo_SALI_GetFltCoefAddr(PSEUDO_SALI_FLTCOEF_TYPE_BKF_NB_UL);
}

volatile uint16* Pseudo_SAL_BKF_GetFltCoefAddr_NB_DL()
{
	return Pseudo_SALI_GetFltCoefAddr(PSEUDO_SALI_FLTCOEF_TYPE_BKF_NB_DL);
}

volatile uint16* Pseudo_SAL_SRC_GetFltCoefAddr()
{
	return Pseudo_SALI_GetFltCoefAddr(PSEUDO_SALI_FLTCOEF_TYPE_SRC);
}

volatile uint16* Pseudo_SAL_AGC_GetFltCoefAddr()
{
	return Pseudo_SALI_GetFltCoefAddr(PSEUDO_SALI_FLTCOEF_TYPE_AGC);
}

void Pseudo_SAL_3G_Set_RxType(uint16 rx_type)
{
    Pseudo_SALI_3G_Set_RxType(rx_type);
}

void Pseudo_SAL_Dsp_Sph_Init()
{
    Pseudo_SALI_Init();
}

void Pseudo_SAL_Set_Sph_Nml_Mod(uint32 on)
{
    Pseudo_SALI_Set_Sph_Nml_Mod(on);
}

void Pseudo_SAL_2G_Call_Open(uint32 enc_mod, uint32 dec_mod, uint32 sub_channel)
{
   Pseudo_SALI_Enable_Codec(enc_mod, dec_mod);
   Pseudo_SALI_Fill_Enc_Silence(PSEUDO_SAL_APP_TYPE_2GCall, enc_mod);
   Pseudo_SALI_Set_2G_Sch_Delay(enc_mod, sub_channel);	
   Pseudo_SALI_AppSpec_Control(PSEUDO_SAL_APP_TYPE_2GCall, 1);
}

void Pseudo_SAL_3G_Call_Open(uint32 enc_mod, uint32 dec_mod, uint32 dtx, uint32 delR, uint32 delW, uint32 delM)
{
   Pseudo_SALI_Set_3G(true);
   Pseudo_SALI_Enable_Codec(enc_mod, dec_mod);
   Pseudo_SALI_Upd_3G_Enc_Rate(enc_mod);
   Pseudo_SALI_Upd_3G_Dec_Rate(dec_mod);
   Pseudo_SALI_3G_SetDtx(dtx);
   Pseudo_SALI_Fill_Enc_Silence(PSEUDO_SAL_APP_TYPE_3GCall, enc_mod);
   Pseudo_SALI_Set_Sch_Delay(delR, delW, delM, 0);
   Pseudo_SALI_AppSpec_Control(PSEUDO_SAL_APP_TYPE_3GCall, 1);
}

void Pseudo_SAL_2G_Call_Close()
{
    Pseudo_SALI_Disable_Codec();
 	Pseudo_SALI_AppSpec_Control(PSEUDO_SAL_APP_TYPE_2GCall, 0);
}

void Pseudo_SAL_3G_Call_Close()
{
    Pseudo_SALI_Disable_Codec();
    Pseudo_SALI_3G_Set_RxType(PSEUDO_SAL_3G_RX_NO_DATA);
    Pseudo_SALI_Set_3G(false);
	Pseudo_SALI_AppSpec_Control(PSEUDO_SAL_APP_TYPE_3GCall, 0);
}

void Pseudo_SAL_3G_Upd_Enc_Cod(uint32 enc_mod)
{
    Pseudo_SALI_Upd_3G_Enc_Rate(enc_mod);
}

void Pseudo_SAL_3G_Upd_Dec_Cod(uint32 dec_mod)
{	
    Pseudo_SALI_Upd_3G_Dec_Rate(dec_mod);
}

bool Pseudo_SAL_DSPINT_Resolve(uint16 iid, uint32 *sph_int)
{
    return Pseudo_SALI_Int_Resolve(iid, sph_int);
}

void Pseudo_SAL_PcmEx_Config(Pseudo_Sal_PCMEx_t *cfg)
{
    ASSERT_REBOOT(cfg != 0);
    Pseudo_SALI_PcmEx_Config(cfg);
}

void Pseudo_SAL_PcmEx_SetStateUL(Pseudo_Sal_PcmEx_Type_t type, Pseudo_Sal_PcmEx_State_t sta)
{
	Pseudo_SALI_PcmEx_SetState(0, type, sta);
}

void Pseudo_SAL_PcmEx_SetStateDL(Pseudo_Sal_PcmEx_Type_t type, Pseudo_Sal_PcmEx_State_t sta)
{
	Pseudo_SALI_PcmEx_SetState(1, type, sta);
}

bool Pseudo_SAL_PcmEx_CheckStateUL(Pseudo_Sal_PcmEx_Type_t type, Pseudo_Sal_PcmEx_State_t sta)
{
	return Pseudo_SALI_PcmEx_CheckState(0, type, sta);
}

bool Pseudo_SAL_PcmEx_CheckStateDL(Pseudo_Sal_PcmEx_Type_t type, Pseudo_Sal_PcmEx_State_t sta)
{
	return Pseudo_SALI_PcmEx_CheckState(1, type, sta);
}

void Pseudo_SAL_ENH_SetULPath(bool on)
{
	Pseudo_SALI_ENH_PathEnable(0, on);
}

void Pseudo_SAL_3G_SetDtx(bool on)
{
	Pseudo_SALI_3G_SetDtx(on);
}

volatile uint16 *Pseudo_SAL_CommonPar_GetBuf(void)
{
	return Pseudo_SALI_Parameter_GetAddr(PSEUDO_SALI_PARAMETER_TYPE_COMMON);
}

volatile uint16 *Pseudo_SAL_ModePar_GetBuf(void)
{
	return Pseudo_SALI_Parameter_GetAddr(PSEUDO_SALI_PARAMETER_TYPE_MODE);
}

volatile uint16 *Pseudo_SAL_VolPar_GetBuf(void)
{
    return Pseudo_SALI_Parameter_GetAddr(PSEUDO_SALI_PARAMETER_TYPE_VOL);
}

#else   // chip compile option
// No pseudo SAL
#endif  // chip compile option


// Talk to baby
#if defined(__VAD_SUPPORT__)

static void AM_DSP_BabyMonitor_RecordOn( kal_uint32 codec_mode )
{
   if ((am.state & AM_STATE_AVSYNC) && (*DP_A2V_INT_ENABLE == 0))
      *DP_A2V_INT_ENABLE = 3;
   
   AFE_TurnOn8K();
   
   am.bm_enc_mode = codec_mode;
   if (!(am.state & AM_STATE_SPEECH)) {
      Pseudo_SAL_3G_Call_Open(am.bm_enc_mode, am.bm_dec_mode, KAL_FALSE, DSP_PCM_IDLE_DELAY_TABLE[6][0], DSP_PCM_IDLE_DELAY_TABLE[6][1], DSP_PCM_IDLE_DELAY_TABLE[6][2]);
   }
   
#if DSP_16K_SIDETONE_SUPPORT
   *AFE_VLB_CON |= (0x01<<3);                /* Bypass hardware IIR filter */
#endif 
   
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *DP_SCR_CTRL |= 0x2;
   *AFE_VMCU_CON1 &= ~0x0200;                  //using wide band
#endif
   
   VBI_Reset();

   am.state |= AM_STATE_VOICE;
}

void AM_BabyMonitor_RecordOn( kal_uint32 codec_mode )
{
#ifndef  L1D_TEST
   KT_StopAndWait();
   TONE_StopAndWait();
#endif
   
   if (!(am.state & AM_STATE_SPEECH))
      DSP_DynamicDownload( DDID_NOISE_REDUCTION );
   
   AM_Force_VBI_END_IN_TASK();
   
   AFE_TurnOnMicrophone( L1SP_VOICE );
   
   AM_Enqueue( AM_DSP_BabyMonitor_RecordOn, codec_mode, false );
   AM_FlushQFunction();
   
   if (!(am.state & AM_STATE_SPEECH)) {
      l1sp_updateSpeAppMask(0xffff, false);
      l1sp_updateSpeAppMask(SPH_ENH_MASK_ULNR|SPH_ENH_MASK_AGC|SPH_ENH_MASK_AEC, true);
      SetSpeechEnhancement(true);
   }
}

void AM_DSP_BabyMonitor_RecordOff( void )
{
   if (!(am.state & AM_STATE_SPEECH)) {
      Pseudo_SAL_3G_Call_Close();
   }
   
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *DP_SCR_CTRL &= ~0x2;
#endif
   
   am.state &= ~AM_STATE_VOICE;
   
   if ( am.state == 0 ) {
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      *AFE_VMCU_CON1 |= 0x0200;                  //using wide band
#endif
      VBI_End();
      AFE_TurnOff8K();
   }
}

void AM_BabyMonitor_RecordOff( void )
{
#ifndef  L1D_TEST
   KT_StopAndWait();
   TONE_StopAndWait();
#endif

   if (!(am.state & AM_STATE_SPEECH)) {
      SetSpeechEnhancement(false);
      l1sp_updateSpeAppMask(0xffff, true);
   }
   
   if (!(am.state & AM_STATE_PCMNWAY)) {
      AFE_TurnOffMicrophone( L1SP_VOICE );
   }
   
   AM_Enqueue( AM_DSP_BabyMonitor_RecordOff, 0, false );
   AM_FlushQFunction();
}

static void AM_DSP_BabyMonitor_PlaybackOn( kal_uint32 codec_mode )
{
   AFE_TurnOn8K();
   
   am.bm_dec_mode = codec_mode;
   if (!(am.state & AM_STATE_VOICE)) {
      Pseudo_SAL_3G_Call_Open(am.bm_enc_mode, am.bm_dec_mode, KAL_FALSE, DSP_PCM_IDLE_DELAY_TABLE[6][0], DSP_PCM_IDLE_DELAY_TABLE[6][1], DSP_PCM_IDLE_DELAY_TABLE[6][2]);
   }
   
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *DP_SCR_CTRL |= 0x4;
   *AFE_VMCU_CON1 &= ~0x0200;                  //using wide band
#endif
   
   VBI_Reset();

   am.state |= AM_STATE_SPEECH;
}

void AM_BabyMonitor_PlaybackOn( kal_uint32 codec_mode )
{
#ifndef  L1D_TEST
   KT_StopAndWait();
   TONE_StopAndWait();
#endif
   
   if (!(am.state & AM_STATE_VOICE))
      DSP_DynamicDownload( DDID_NOISE_REDUCTION );
   
   AM_Force_VBI_END_IN_TASK();
   
   AM_Enqueue( AM_DSP_BabyMonitor_PlaybackOn, codec_mode, KAL_FALSE );
   AM_FlushQFunction();
   AFE_TurnOnSpeaker( L1SP_VOICE );
   
   if (!(am.state & AM_STATE_VOICE)) {
      l1sp_updateSpeAppMask(0xffff, false);
      l1sp_updateSpeAppMask(SPH_ENH_MASK_ULNR|SPH_ENH_MASK_AGC|SPH_ENH_MASK_AEC, true);
      SetSpeechEnhancement(true);
   }
}

void AM_DSP_BabyMonitor_PlaybackOff( void )
{
   if (!(am.state & AM_STATE_VOICE)) {
      Pseudo_SAL_3G_Call_Close();
   }

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *DP_SCR_CTRL &= ~0x4;
#endif

   am.state &= ~AM_STATE_SPEECH;
   
   if ( am.state == 0 ) {
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      *AFE_VMCU_CON1 |= 0x0200;                  //using wide band
#endif
      VBI_End();
      AFE_TurnOff8K();
   }
}

void AM_BabyMonitor_PlaybackOff( void )
{
#ifndef  L1D_TEST
   KT_StopAndWait();
   TONE_StopAndWait();
#endif

   if (!(am.state & AM_STATE_VOICE)) {
      SetSpeechEnhancement(false);
      l1sp_updateSpeAppMask(0xffff, true);
   }
   
   AFE_TurnOffSpeaker( L1SP_VOICE );
   
   AM_Enqueue( AM_DSP_BabyMonitor_PlaybackOff, 0, false );
   AM_FlushQFunction();
}

kal_bool AM_IsBabyMonitor_PlaybackOn( void )
{
   if (am.state & AM_STATE_AUDIO)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

#endif
