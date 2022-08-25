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
 * nvram_default_audio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is for customers to config/customize their audio related parameters to NVRAM Layer and
 *    Driver Layer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "nvram_default_audio.h"

#if defined(KLM2003_BB)
#define MICROPHONE_VOLUME     80
#define SIDE_TONE_VOLUME      96
#elif defined(CHICAGO2003_BB)
#define MICROPHONE_VOLUME     80
#define SIDE_TONE_VOLUME      80
#else
#define MICROPHONE_VOLUME     176
#define SIDE_TONE_VOLUME      0
#endif
#if defined(__NT55__)
#define GAIN_NOR_MED_VOL_MAX 4
#define GAIN_HED_MED_VOL_MAX 4  /*Headset*/
#define GAIN_HND_MED_VOL_MAX 4  /* Handfree*/ 
#define GAIN_TVO_VOL_MAX 4
#else
#define GAIN_NOR_MED_VOL_MAX 144
#define GAIN_HED_MED_VOL_MAX 112  /*Headset*/
#define GAIN_HND_MED_VOL_MAX 144  /* Handfree*/ 
#define GAIN_TVO_VOL_MAX (176-24)
#endif

#define GAIN_NOR_MED_VOL_STEP 4 /* 1=0.5dB as unit */
#define GAIN_HED_MED_VOL_STEP 4 /* 1=0.5dB as unit */
#define GAIN_HND_MED_VOL_STEP 4 /* 1=0.5dB as unit */
#define GAIN_TVO_VOL_STEP 4 /* 1=0.5dB as unit */

#define GAIN_TVO_VOL0			4   
#define GAIN_TVO_VOL1			61
#define GAIN_TVO_VOL2			94
#define GAIN_TVO_VOL3			127
#define GAIN_TVO_VOL4			164
#define GAIN_TVO_VOL5			180
#define GAIN_TVO_VOL6			196

#define GAIN_NOR_CTN_VOL    3
#define GAIN_NOR_CTN_VOL0		127
#define GAIN_NOR_CTN_VOL1		127
#define GAIN_NOR_CTN_VOL2		127
#define GAIN_NOR_CTN_VOL3		127
#define GAIN_NOR_CTN_VOL4		127
#define GAIN_NOR_CTN_VOL5		127
#define GAIN_NOR_CTN_VOL6		127

#define GAIN_NOR_KEY_VOL    3
#define GAIN_NOR_KEY_VOL0			16
#define GAIN_NOR_KEY_VOL1			32
#define GAIN_NOR_KEY_VOL2			48
#define GAIN_NOR_KEY_VOL3			64
#define GAIN_NOR_KEY_VOL4			80
#define GAIN_NOR_KEY_VOL5			96
#define GAIN_NOR_KEY_VOL6			112

#define GAIN_NOR_MIC_VOL    3
#define GAIN_NOR_MIC_VOL0	240
#define GAIN_NOR_MIC_VOL1	240
#define GAIN_NOR_MIC_VOL2	240
#define GAIN_NOR_MIC_VOL3	168
#define GAIN_NOR_MIC_VOL4	240
#define GAIN_NOR_MIC_VOL5	240
#define GAIN_NOR_MIC_VOL6	240

#define GAIN_NOR_GMI_VOL    3
#define GAIN_NOR_GMI_VOL0		48
#define GAIN_NOR_GMI_VOL1		64
#define GAIN_NOR_GMI_VOL2		80
#define GAIN_NOR_GMI_VOL3		96
#define GAIN_NOR_GMI_VOL4		112
#define GAIN_NOR_GMI_VOL5		128
#define GAIN_NOR_GMI_VOL6		144

#define GAIN_NOR_SPH_VOL    3
#define GAIN_NOR_SPH_VOL0		80
#define GAIN_NOR_SPH_VOL1		96
#define GAIN_NOR_SPH_VOL2	  112	
#define GAIN_NOR_SPH_VOL3		128
#define GAIN_NOR_SPH_VOL4		144
#define GAIN_NOR_SPH_VOL5		160
#define GAIN_NOR_SPH_VOL6		176

#define GAIN_NOR_SID_VOL    3
#define GAIN_NOR_SID_VOL0			SIDE_TONE_VOLUME
#define GAIN_NOR_SID_VOL1			SIDE_TONE_VOLUME
#define GAIN_NOR_SID_VOL2			SIDE_TONE_VOLUME
#define GAIN_NOR_SID_VOL3			SIDE_TONE_VOLUME
#define GAIN_NOR_SID_VOL4			SIDE_TONE_VOLUME
#define GAIN_NOR_SID_VOL5			SIDE_TONE_VOLUME
#define GAIN_NOR_SID_VOL6			SIDE_TONE_VOLUME

#define GAIN_NOR_MED_VOL    3
#define GAIN_NOR_MED_VOL0			48
#define GAIN_NOR_MED_VOL1			64
#define GAIN_NOR_MED_VOL2			80
#define GAIN_NOR_MED_VOL3			96
#define GAIN_NOR_MED_VOL4			112
#define GAIN_NOR_MED_VOL5			128
#define GAIN_NOR_MED_VOL6			144

/* define Gain For Headset */
/* speaker, microphone, loudspeaker, buzzer */
#define GAIN_HED_CTN_VOL    3
#define GAIN_HED_CTN_VOL0		4
#define GAIN_HED_CTN_VOL1		8
#define GAIN_HED_CTN_VOL2		16
#define GAIN_HED_CTN_VOL3		32
#define GAIN_HED_CTN_VOL4		64
#define GAIN_HED_CTN_VOL5		96
#define GAIN_HED_CTN_VOL6		127

#define GAIN_HED_KEY_VOL    3
#define GAIN_HED_KEY_VOL0		4
#define GAIN_HED_KEY_VOL1		8
#define GAIN_HED_KEY_VOL2		12
#define GAIN_HED_KEY_VOL3		16
#define GAIN_HED_KEY_VOL4		20
#define GAIN_HED_KEY_VOL5		24
#define GAIN_HED_KEY_VOL6		28

#define GAIN_HED_MIC_VOL		3
#define GAIN_HED_MIC_VOL0		180
#define GAIN_HED_MIC_VOL1		180
#define GAIN_HED_MIC_VOL2		180
#define GAIN_HED_MIC_VOL3		160
#define GAIN_HED_MIC_VOL4		180
#define GAIN_HED_MIC_VOL5		196
#define GAIN_HED_MIC_VOL6		212

#define GAIN_HED_GMI_VOL		3
#define GAIN_HED_GMI_VOL0		16
#define GAIN_HED_GMI_VOL1		32
#define GAIN_HED_GMI_VOL2		48
#define GAIN_HED_GMI_VOL3		64
#define GAIN_HED_GMI_VOL4		80
#define GAIN_HED_GMI_VOL5		96
#define GAIN_HED_GMI_VOL6		112

#define GAIN_HED_SPH_VOL    3
#define GAIN_HED_SPH_VOL0		16
#define GAIN_HED_SPH_VOL1		32
#define GAIN_HED_SPH_VOL2		48
#define GAIN_HED_SPH_VOL3		64
#define GAIN_HED_SPH_VOL4		80
#define GAIN_HED_SPH_VOL5		96
#define GAIN_HED_SPH_VOL6		112

#define GAIN_HED_SID_VOL    3
#define GAIN_HED_SID_VOL0		SIDE_TONE_VOLUME
#define GAIN_HED_SID_VOL1		SIDE_TONE_VOLUME
#define GAIN_HED_SID_VOL2		SIDE_TONE_VOLUME
#define GAIN_HED_SID_VOL3		SIDE_TONE_VOLUME
#define GAIN_HED_SID_VOL4		SIDE_TONE_VOLUME
#define GAIN_HED_SID_VOL5		SIDE_TONE_VOLUME
#define GAIN_HED_SID_VOL6		SIDE_TONE_VOLUME

#define GAIN_HED_MED_VOL    3
#define GAIN_HED_MED_VOL0			16
#define GAIN_HED_MED_VOL1			32
#define GAIN_HED_MED_VOL2			48
#define GAIN_HED_MED_VOL3			64
#define GAIN_HED_MED_VOL4			80
#define GAIN_HED_MED_VOL5			96
#define GAIN_HED_MED_VOL6			112


/* define Gain For Handfree */
/* speaker, microphone, loudspeaker, buzzer */
#define GAIN_HND_CTN_VOL    3
#define GAIN_HND_CTN_VOL0			127
#define GAIN_HND_CTN_VOL1			127
#define GAIN_HND_CTN_VOL2			127
#define GAIN_HND_CTN_VOL3			127
#define GAIN_HND_CTN_VOL4			127
#define GAIN_HND_CTN_VOL5			127
#define GAIN_HND_CTN_VOL6			127
#if defined(__NT55__)
#define GAIN_HND_KEY_VOL      3
#define GAIN_HND_KEY_VOL0     16
#define GAIN_HND_KEY_VOL1     32
#define GAIN_HND_KEY_VOL2     48
#define GAIN_HND_KEY_VOL3     64
#define GAIN_HND_KEY_VOL4     80
#define GAIN_HND_KEY_VOL5     96
#define GAIN_HND_KEY_VOL6     112
#else
#define GAIN_HND_KEY_VOL    3
#define GAIN_HND_KEY_VOL0		16
#define GAIN_HND_KEY_VOL1		28
#define GAIN_HND_KEY_VOL2		40
#define GAIN_HND_KEY_VOL3		52
#define GAIN_HND_KEY_VOL4		64
#define GAIN_HND_KEY_VOL5		76
#define GAIN_HND_KEY_VOL6		88
#endif

#define GAIN_HND_MIC_VOL		3
#define GAIN_HND_MIC_VOL0		180
#define GAIN_HND_MIC_VOL1		180
#define GAIN_HND_MIC_VOL2		180
#define GAIN_HND_MIC_VOL3		200
#define GAIN_HND_MIC_VOL4		180
#define GAIN_HND_MIC_VOL5		196
#define GAIN_HND_MIC_VOL6		212

#define GAIN_HND_GMI_VOL		3
#define GAIN_HND_GMI_VOL0			48
#define GAIN_HND_GMI_VOL1			64
#define GAIN_HND_GMI_VOL2			80
#define GAIN_HND_GMI_VOL3			96
#define GAIN_HND_GMI_VOL4			112
#define GAIN_HND_GMI_VOL5			128
#define GAIN_HND_GMI_VOL6			144

#define GAIN_HND_SPH_VOL    3
#define GAIN_HND_SPH_VOL0			16
#define GAIN_HND_SPH_VOL1			32
#define GAIN_HND_SPH_VOL2			48
#define GAIN_HND_SPH_VOL3			64
#define GAIN_HND_SPH_VOL4			80
#define GAIN_HND_SPH_VOL5			96
#define GAIN_HND_SPH_VOL6			112

#define GAIN_HND_SID_VOL    3
#define GAIN_HND_SID_VOL0		SIDE_TONE_VOLUME
#define GAIN_HND_SID_VOL1		SIDE_TONE_VOLUME
#define GAIN_HND_SID_VOL2		SIDE_TONE_VOLUME
#define GAIN_HND_SID_VOL3		SIDE_TONE_VOLUME
#define GAIN_HND_SID_VOL4		SIDE_TONE_VOLUME
#define GAIN_HND_SID_VOL5		SIDE_TONE_VOLUME
#define GAIN_HND_SID_VOL6		SIDE_TONE_VOLUME

#define GAIN_HND_MED_VOL    3
#define GAIN_HND_MED_VOL0			48
#define GAIN_HND_MED_VOL1			64
#define GAIN_HND_MED_VOL2			80
#define GAIN_HND_MED_VOL3			96
#define GAIN_HND_MED_VOL4			112
#define GAIN_HND_MED_VOL5			128
#define GAIN_HND_MED_VOL6			144

kal_uint8 const NVRAM_EF_CUST_ACOUSTIC_DATA_DEFAULT[] = {
     /* Normal: Call Tone, Keypad Tone, Microphone, GMI Tone, Speech Tone, Side Tone */ 
      GAIN_NOR_CTN_VOL0,GAIN_NOR_CTN_VOL1, GAIN_NOR_CTN_VOL2, GAIN_NOR_CTN_VOL3, GAIN_NOR_CTN_VOL4, GAIN_NOR_CTN_VOL5, GAIN_NOR_CTN_VOL6,
      GAIN_NOR_KEY_VOL0, GAIN_NOR_KEY_VOL1, GAIN_NOR_KEY_VOL2, GAIN_NOR_KEY_VOL3, GAIN_NOR_KEY_VOL4, GAIN_NOR_KEY_VOL5, GAIN_NOR_KEY_VOL6, 
      GAIN_NOR_MIC_VOL0, GAIN_NOR_MIC_VOL1, GAIN_NOR_MIC_VOL2, GAIN_NOR_MIC_VOL3, GAIN_NOR_MIC_VOL4, GAIN_NOR_MIC_VOL5, GAIN_NOR_MIC_VOL6, 
      GAIN_NOR_GMI_VOL0, GAIN_NOR_GMI_VOL1, GAIN_NOR_GMI_VOL2, GAIN_NOR_GMI_VOL3, GAIN_NOR_GMI_VOL4, GAIN_NOR_GMI_VOL5, GAIN_NOR_GMI_VOL6, 
      GAIN_NOR_SPH_VOL0, GAIN_NOR_SPH_VOL1, GAIN_NOR_SPH_VOL2, GAIN_NOR_SPH_VOL3, GAIN_NOR_SPH_VOL4, GAIN_NOR_SPH_VOL5, GAIN_NOR_SPH_VOL6, 
      GAIN_NOR_SID_VOL0, GAIN_NOR_SID_VOL1, GAIN_NOR_SID_VOL2, GAIN_NOR_SID_VOL3, GAIN_NOR_SID_VOL4, GAIN_NOR_SID_VOL5, GAIN_NOR_SID_VOL6, 
      GAIN_NOR_MED_VOL0,GAIN_NOR_MED_VOL1, GAIN_NOR_MED_VOL2, GAIN_NOR_MED_VOL3, GAIN_NOR_MED_VOL4, GAIN_NOR_MED_VOL5, GAIN_NOR_MED_VOL6
   , 
     /* Handset: Call Tone, Keypad Tone, Microphone, GMI Tone, Speech Tone */ 
      GAIN_HED_CTN_VOL0, GAIN_HED_CTN_VOL1, GAIN_HED_CTN_VOL2, GAIN_HED_CTN_VOL3, GAIN_HED_CTN_VOL4, GAIN_HED_CTN_VOL5, GAIN_HED_CTN_VOL6, 
      GAIN_HED_KEY_VOL0, GAIN_HED_KEY_VOL1, GAIN_HED_KEY_VOL2, GAIN_HED_KEY_VOL3, GAIN_HED_KEY_VOL4, GAIN_HED_KEY_VOL5, GAIN_HED_KEY_VOL6, 
      GAIN_HED_MIC_VOL0, GAIN_HED_MIC_VOL1, GAIN_HED_MIC_VOL2, GAIN_HED_MIC_VOL3, GAIN_HED_MIC_VOL4, GAIN_HED_MIC_VOL5, GAIN_HED_MIC_VOL6, 
      GAIN_HED_GMI_VOL0, GAIN_HED_GMI_VOL1, GAIN_HED_GMI_VOL2, GAIN_HED_GMI_VOL3, GAIN_HED_GMI_VOL4, GAIN_HED_GMI_VOL5, GAIN_HED_GMI_VOL6, 
      GAIN_HED_SPH_VOL0, GAIN_HED_SPH_VOL1, GAIN_HED_SPH_VOL2, GAIN_HED_SPH_VOL3, GAIN_HED_SPH_VOL4, GAIN_HED_SPH_VOL5, GAIN_HED_SPH_VOL6, 
      GAIN_HED_SID_VOL0, GAIN_HED_SID_VOL1, GAIN_HED_SID_VOL2, GAIN_HED_SID_VOL3, GAIN_HED_SID_VOL4, GAIN_HED_SID_VOL5, GAIN_HED_SID_VOL6, 
      GAIN_HED_MED_VOL0,GAIN_HED_MED_VOL1, GAIN_HED_MED_VOL2, GAIN_HED_MED_VOL3, GAIN_HED_MED_VOL4, GAIN_HED_MED_VOL5, GAIN_HED_MED_VOL6
   , 
     /* Handfree: Call Tone, Keypad Tone, Microphone, GMI Tone, Speech Tone */  
     GAIN_HND_CTN_VOL0, GAIN_HND_CTN_VOL1, GAIN_HND_CTN_VOL2, GAIN_HND_CTN_VOL3, GAIN_HND_CTN_VOL4, GAIN_HND_CTN_VOL5, GAIN_HND_CTN_VOL6, 
     GAIN_HND_KEY_VOL0,  GAIN_HND_KEY_VOL1, GAIN_HND_KEY_VOL2, GAIN_HND_KEY_VOL3, GAIN_HND_KEY_VOL4, GAIN_HND_KEY_VOL5, GAIN_HND_KEY_VOL6, 
     GAIN_HND_MIC_VOL0,  GAIN_HND_MIC_VOL1, GAIN_HND_MIC_VOL2, GAIN_HND_MIC_VOL3, GAIN_HND_MIC_VOL4, GAIN_HND_MIC_VOL5, GAIN_HND_MIC_VOL6, 
     GAIN_HND_GMI_VOL0,  GAIN_HND_GMI_VOL1, GAIN_HND_GMI_VOL2, GAIN_HND_GMI_VOL3, GAIN_HND_GMI_VOL4, GAIN_HND_GMI_VOL5, GAIN_HND_GMI_VOL6, 
     GAIN_HND_SPH_VOL0,  GAIN_HND_SPH_VOL1, GAIN_HND_SPH_VOL2, GAIN_HND_SPH_VOL3, GAIN_HND_SPH_VOL4, GAIN_HND_SPH_VOL5, GAIN_HND_SPH_VOL6, 
     GAIN_HND_SID_VOL0,  GAIN_HND_SID_VOL1, GAIN_HND_SID_VOL2, GAIN_HND_SID_VOL3, GAIN_HND_SID_VOL4, GAIN_HND_SID_VOL5, GAIN_HND_SID_VOL6, 
     GAIN_HND_MED_VOL0, GAIN_HND_MED_VOL1, GAIN_HND_MED_VOL2, GAIN_HND_MED_VOL3, GAIN_HND_MED_VOL4, GAIN_HND_MED_VOL5, GAIN_HND_MED_VOL6
   ,  
   /* Normal volume: CTN, SPK, MIC, BUZ, SPH, SID, MED */
   GAIN_NOR_CTN_VOL, GAIN_NOR_KEY_VOL, GAIN_NOR_MIC_VOL, GAIN_NOR_GMI_VOL, GAIN_NOR_SPH_VOL, GAIN_NOR_SID_VOL, GAIN_NOR_MED_VOL,
   /* Headset volume: CTN, SPK, MIC, BUZ, SPH, SID, MED */
   GAIN_HED_CTN_VOL, GAIN_HED_KEY_VOL, GAIN_HED_MIC_VOL, GAIN_HED_GMI_VOL, GAIN_HED_SPH_VOL, GAIN_HED_SID_VOL, GAIN_HED_MED_VOL,
   /* Handfree volume: CTN, SPK, MIC, BUZ, SPH, SID, MED */
   GAIN_HND_CTN_VOL, GAIN_HND_KEY_VOL, GAIN_HND_MIC_VOL, GAIN_HND_GMI_VOL, GAIN_HND_SPH_VOL, GAIN_HND_SID_VOL, GAIN_HND_MED_VOL
   
   /* Normal, Headset, Handfree mode melody volume gains */
   ,GAIN_NOR_MED_VOL_MAX, GAIN_HED_MED_VOL_MAX, GAIN_HND_MED_VOL_MAX,GAIN_TVO_VOL_MAX,
   /* Normal, Headset, Handfree mode melody volume gain steps */
   GAIN_NOR_MED_VOL_STEP, GAIN_HED_MED_VOL_STEP, GAIN_HND_MED_VOL_STEP,GAIN_TVO_VOL_STEP,
   /* TV out volume gains*/
   GAIN_TVO_VOL0, GAIN_TVO_VOL1, GAIN_TVO_VOL2, GAIN_TVO_VOL3, GAIN_TVO_VOL4, GAIN_TVO_VOL5, GAIN_TVO_VOL6
};

const nvram_ef_audio_equalizer_struct NVRAM_EF_AUDIO_EQUALIZER_DEFAULT[] =
{
    NVRAM_EF_AUDIO_EQUALIZER_COUNT,         // Count
    0,										// Index
#if defined(__BES_EQ_FLEXIBLE_SUPPORT__) 
    {   // Preset gains
        // 5 bands
//        // Less obvious (for headphone)
//        {   0,   0,   0,   0,   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Normal
//        {  48,  28,  -8,   0,   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Bass
//        {  16,  10,  29,  32,  25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Dance
//        {  40, -11,  -9,  12,  41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Classical
//        {   0,  -5,   9,  32,  57,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Treble
//        {  40,  -4,   3,  -4,  41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Party
//        { -11,  20,  33,  -6, -16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Pop
//        {  48,  -1, -14,  18,  49,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Rock

        // More obvious (for loudspeaker)
        {   0,   0,   0,   0,   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Normal
        {  74,  47, -47, -13, -56,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Bass
        {  74, -69,  39,  42,  25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Dance
        {   0,   6, -13, -14, -72,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Classical
        { -56,   2, -29,  46,  81,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Treble
        {  74, -10,   5,  -5,  65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Party
        { -24,  63, -17, -21, -32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Pop
        {  58, -57, -16,  21,  73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}, // Rock
    },
#else
    {
   	  {   0,   0,   0,   0,   0,    0,    0,    0},   /* Normal */
      {  60,  20,   0, -20, -50,  -80, -100, -110},   /* Base */
      {   0,   0, -10, -40, -60,  -70,  -70,    0},   /* Dance */
      {   0,   0,   0,   0, -20,  -70,  -70, -100},   /* Classical */
      {   0,  10,  30,  50,  80,  110,  110,  120},   /* Treble */          
      {  70,  70,   0,   0,   0,    0,    0,   70},   /* Party */          
      {  80,  60,  50,  10, -10,  -30,  -30,  -20},   /* Pop */          
      {   0, -30, -20,  20,  50,   90,  110,  110}    /* Rock */
    },
#endif   
    {
        {'N',0,'o',0,'r',0,'m',0,'a',0,'l',0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0,0,0},
	    {'B',0,'a',0,'s',0,'s',0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0,0,0},
	    {'D',0,'a',0,'n',0,'c',0,'e',0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0,0,0},
	    {'C',0,'l',0,'a',0,'s',0,'s',0,'i',0,'c',0,'a',0,'l',0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0,0,0},
	    {'T',0,'r',0,'e',0,'b',0,'l',0,'e',0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0,0,0},
	    {'P',0,'a',0,'r',0,'t',0,'y',0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0,0,0},
	    {'P',0,'o',0,'p',0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0,0,0},
	    {'R',0,'o',0,'c',0,'k',0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0,0,0},
	    {'R',0,'e',0,'s',0,'t',0,'o',0,'r',0,'e',0,' ',0,'F',0,'a',0,'c',0,'t',0,'o',0,'r',0,'y',0,' ',0,'D',0,'e',0,'f',0,'a',0,'u',0,'l',0,'t',0,0,0},
    }
};

const nvram_ef_audio_bes_eq_flexible_struct NVRAM_EF_AUDIO_BES_EQ_FLEXIBLE_DEFAULT[] =
{	
	 DEFAULT_BES_EQ_FLEXIBLE_INITIAL_PARAMETER
};


