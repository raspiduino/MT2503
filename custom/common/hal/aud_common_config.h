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
 * audio_common_config.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is for customers to config/customize their audio parameters to NVRAM Layer and
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __AUDIO_COMMON_CONFIG_H__
#define __AUDIO_COMMON_CONFIG_H__

#include "audcoeff_default.h"

/**
 * Audio Parameters
 */
//#define NVRAM_EF_AUDIO_PARAM_SIZE     1940
//#define NVRAM_EF_AUDIO_PARAM_TOTAL    1

/**************** Default value for speech common parameter ********************/
#define DEFAULT_SPEECH_COMMON_PARA \
{ \
     0, 55997, 31000, 10752, 32769,     0,     0,     0,     0,     0, \
     0,     0 \
}

#define DEFAULT_MEDIA_PLAYBACK_MAXIMUM_SWING 12800

/******************** Melody FIR definition ****************************/
#if defined(WT600K) || defined(WT300K)
#define DEFAULT_MELODY_FIR \
{ \
   -21,  -269,     7,   141,  -326,  -203,   257,  -396,  -472,  1323, \
   192, -6458, 15256, -6458,   192,  1323,  -472,  -396,   257,  -203, \
  -326,   141,     7,  -269,   -21 \
}
#else
/* for WT150K WT100K WT70K WT20K */
#define DEFAULT_MELODY_FIR \
{ \
54, -142, -169, 36, 88, -111, -553, -291, 737, -96, -1605, 560, 5836, 560,\
-1605, -96, 737, -291, -553, -111, 88, 36, -169, -142, 54, \
}
#endif

/****************** Compensation filter ********************************/
#define DEFAULT_COMPENSATION_FLT_NORMAL \
    { /* 0: Compensation Filter for Normal mode */\
     32767,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0  \
    }

#define DEFAULT_COMPENSATION_FLT_HEADSET \
    { /* 0: Compensation Filter for Headset mode */\
     32767,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0  \
    }

#define DEFAULT_COMPENSATION_FLT_LOUDSPEAKER \
    { /* 0: Compensation Filter for loudspeaker ringtone mode */\
     32767,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0  \
    }


#define DEFAULT_COMPENSATION_FLT \
{ \
	DEFAULT_COMPENSATION_FLT_NORMAL, \
	DEFAULT_COMPENSATION_FLT_HEADSET, \
	DEFAULT_COMPENSATION_FLT_LOUDSPEAKER \
}

/****************** BesLoudness coeffs ********************************/

#if defined(__BES_LOUDNESS_V4_SUPPORT__)
/* Compensation Filter HSF coeffs       */
/* BesLoudness also uses this coeffs    */ 
/* Cutoff Frequency: 200Hz              */
#define DEFAULT_AUDIO_COMPENSATION_SPK_HSF_COEFFS \
{ \
0x07DA170A, 0xF054253E, 0x07D1C95A, 0x7D56C298, 0x00000000, /* 48000 */ \
0x07D6C2CB, 0xF05B867E, 0x07CDBD5F, 0x7D19C2D2, 0x00000000, /* 44100 */ \
0x07C751CE, 0xF07DBC74, 0x07BAFE49, 0x7BFFC3DA, 0x00000000, /* 32000 */ \
0x07B4AD39, 0xF0A6FF56, 0x07A46981, 0x7AA6C515, 0x00000000, /* 24000 */ \
0x07AE1CEE, 0xF0B5836A, 0x079C79B2, 0x7A2CC583, 0x00000000, /* 22050 */ \
0x078FC91E, 0xF0F882BF, 0x0777E4C0, 0x77F1C777, 0x00000000, /* 16000 */ \
0x076B705A, 0xF148A5E6, 0x074C3E63, 0x7538C9C0, 0x00000000, /* 12000 */ \
0x075EB726, 0xF164A91C, 0x073D0346, 0x7441CA88, 0x00000000, /* 11025 */ \
0x07247309, 0xF1E4AE1A, 0x06F7957D, 0x6FC0CE05, 0x00000000, /*  8000 */ \
\
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 48000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 44100 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 32000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 24000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 22050 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 16000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 12000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 11025 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /*  8000 */ \
}

#define DEFAULT_AUDIO_COMPENSATION_SPK_LPF_COEFFS \
{ \
0x40000000, 0x00000000, 0x00000000, /* 48000 */ \
0x40000000, 0x00000000, 0x00000000, /* 44100 */ \
0x40000000, 0x00000000, 0x00000000, /* 32000 */ \
0x40000000, 0x00000000, 0x00000000, /* 24000 */ \
0x40000000, 0x00000000, 0x00000000, /* 22050 */ \
0x40000000, 0x00000000, 0x00000000, /* 16000 */ \
}
/* Compensation Filter BPF coeffs       */ 
#define DEFAULT_AUDIO_COMPENSATION_SPK_BPF_COEFFS \
{ \
/* filter 0 */ \
0x40000000, 0x00000000, 0x00000000,  /* 48000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 44100 */ \
0x40000000, 0x00000000, 0x00000000,  /* 32000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 24000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 22050 */ \
0x40000000, 0x00000000, 0x00000000,  /* 16000 */ \
/* filter 1 */ \
0x40000000, 0x00000000, 0x00000000,  /* 48000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 44100 */ \
0x40000000, 0x00000000, 0x00000000,  /* 32000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 24000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 22050 */ \
0x40000000, 0x00000000, 0x00000000,  /* 16000 */ \
/* filter 2 */ \
0x40000000, 0x00000000, 0x00000000,  /* 48000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 44100 */ \
0x40000000, 0x00000000, 0x00000000,  /* 32000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 24000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 22050 */ \
0x40000000, 0x00000000, 0x00000000,  /* 16000 */ \
/* filter 3 */ \
0x40000000, 0x00000000, 0x00000000,  /* 48000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 44100 */ \
0x40000000, 0x00000000, 0x00000000,  /* 32000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 24000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 22050 */ \
0x40000000, 0x00000000, 0x00000000,  /* 16000 */ \
/* filter 4 */ \
0x40000000, 0x00000000, 0x00000000,  /* 48000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 44100 */ \
0x40000000, 0x00000000, 0x00000000,  /* 32000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 24000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 22050 */ \
0x40000000, 0x00000000, 0x00000000,  /* 16000 */ \
/* filter 5 */ \
0x40000000, 0x00000000, 0x00000000,  /* 48000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 44100 */ \
0x40000000, 0x00000000, 0x00000000,  /* 32000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 24000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 22050 */ \
0x40000000, 0x00000000, 0x00000000,  /* 16000 */ \
}

/* Compensation Filter HSF coeffs       */
/* BesLoudness also uses this coeffs    */ 
/* Cutoff Frequency: 200Hz              */
#define DEFAULT_AUDIO_COMPENSATION_HDP_HSF_COEFFS \
{ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 48000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 44100 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 32000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 24000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 22050 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 16000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 12000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 11025 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /*  8000 */ \
\
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 48000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 44100 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 32000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 24000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 22050 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 16000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 12000 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /* 11025 */ \
0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, /*  8000 */ \
}

#define DEFAULT_AUDIO_COMPENSATION_HDP_LPF_COEFFS \
{ \
0x40000000, 0x00000000, 0x00000000, /* 48000 */ \
0x40000000, 0x00000000, 0x00000000, /* 44100 */ \
0x40000000, 0x00000000, 0x00000000, /* 32000 */ \
0x40000000, 0x00000000, 0x00000000, /* 24000 */ \
0x40000000, 0x00000000, 0x00000000, /* 22050 */ \
0x40000000, 0x00000000, 0x00000000, /* 16000 */ \
}
/* Compensation Filter BPF coeffs       */ 
#define DEFAULT_AUDIO_COMPENSATION_HDP_BPF_COEFFS \
{ \
/* filter 0 */ \
0x40000000, 0x00000000, 0x00000000,  /* 48000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 44100 */ \
0x40000000, 0x00000000, 0x00000000,  /* 32000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 24000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 22050 */ \
0x40000000, 0x00000000, 0x00000000,  /* 16000 */ \
/* filter 1 */ \
0x40000000, 0x00000000, 0x00000000,  /* 48000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 44100 */ \
0x40000000, 0x00000000, 0x00000000,  /* 32000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 24000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 22050 */ \
0x40000000, 0x00000000, 0x00000000,  /* 16000 */ \
/* filter 2 */ \
0x40000000, 0x00000000, 0x00000000,  /* 48000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 44100 */ \
0x40000000, 0x00000000, 0x00000000,  /* 32000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 24000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 22050 */ \
0x40000000, 0x00000000, 0x00000000,  /* 16000 */ \
/* filter 3 */ \
0x40000000, 0x00000000, 0x00000000,  /* 48000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 44100 */ \
0x40000000, 0x00000000, 0x00000000,  /* 32000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 24000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 22050 */ \
0x40000000, 0x00000000, 0x00000000,  /* 16000 */ \
/* filter 4 */ \
0x40000000, 0x00000000, 0x00000000,  /* 48000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 44100 */ \
0x40000000, 0x00000000, 0x00000000,  /* 32000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 24000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 22050 */ \
0x40000000, 0x00000000, 0x00000000,  /* 16000 */ \
/* filter 5 */ \
0x40000000, 0x00000000, 0x00000000,  /* 48000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 44100 */ \
0x40000000, 0x00000000, 0x00000000,  /* 32000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 24000 */ \
0x40000000, 0x00000000, 0x00000000,  /* 22050 */ \
0x40000000, 0x00000000, 0x00000000,  /* 16000 */ \
}

#define DEFAULT_BESLOUDNESS_ATT_TIME 164
#define DEFAULT_BESLOUDNESS_REL_TIME 16400

#else
/* Compensation Filter HSF coeffs       */
/* BesLoudness also uses this coeffs    */ 
/* Cutoff Frequency: 200Hz              */
#define DEFAULT_AUDIO_COMPENSATION_HSF_COEFFS \
{ \
0x07DA170A, 0xF054253E, 0x07D1C95A, 0x7D56C298, /*    48000 */ \
0x07D6C2CB, 0xF05B867E, 0x07CDBD5F, 0x7D19C2D2, /*    44100 */ \
0x07C751CE, 0xF07DBC74, 0x07BAFE49, 0x7BFFC3DA, /*    32000 */ \
0x07B4AD39, 0xF0A6FF56, 0x07A46981, 0x7AA6C515, /*    24000 */ \
0x07AE1CEE, 0xF0B5836A, 0x079C79B2, 0x7A2CC583, /*    22050 */ \
0x078FC91E, 0xF0F882BF, 0x0777E4C0, 0x77F1C777, /*    16000 */ \
0x076B705A, 0xF148A5E6, 0x074C3E63, 0x7538C9C0, /*    12000 */ \
0x075EB726, 0xF164A91C, 0x073D0346, 0x7441CA88, /*    11025 */ \
0x07247309, 0xF1E4AE1A, 0x06F7957D, 0x6FC0CE05, /*     8000 */ \
}

/* Compensation Filter BPF coeffs       */ 
#define DEFAULT_AUDIO_COMPENSATION_BPF_COEFFS \
{ \
/* filter 0 */ \
0x40000000, 0x00000000, 0x00000000,  /*    48000 */ \
0x40000000, 0x00000000, 0x00000000,  /*    44100 */ \
0x40000000, 0x00000000, 0x00000000,  /*    32000 */ \
0x40000000, 0x00000000, 0x00000000,  /*    24000 */ \
0x40000000, 0x00000000, 0x00000000,  /*    22050 */ \
0x40000000, 0x00000000, 0x00000000,  /*    16000 */ \
/* filter 1 */ \
0x40000000, 0x00000000, 0x00000000,  /*    48000 */ \
0x40000000, 0x00000000, 0x00000000,  /*    44100 */ \
0x40000000, 0x00000000, 0x00000000,  /*    32000 */ \
0x40000000, 0x00000000, 0x00000000,  /*    24000 */ \
0x40000000, 0x00000000, 0x00000000,  /*    22050 */ \
0x40000000, 0x00000000, 0x00000000,  /*    16000 */ \
/* filter 2 */ \
0x40000000, 0x00000000, 0x00000000,  /*    48000 */ \
0x40000000, 0x00000000, 0x00000000,  /*    44100 */ \
0x40000000, 0x00000000, 0x00000000,  /*    32000 */ \
0x40000000, 0x00000000, 0x00000000,  /*    24000 */ \
0x40000000, 0x00000000, 0x00000000,  /*    22050 */ \
0x40000000, 0x00000000, 0x00000000,  /*    16000 */ \
/* filter 3 */ \
0x40000000, 0x00000000, 0x00000000,  /*    48000 */ \
0x40000000, 0x00000000, 0x00000000,  /*    44100 */ \
0x40000000, 0x00000000, 0x00000000,  /*    32000 */ \
0x40000000, 0x00000000, 0x00000000,  /*    24000 */ \
0x40000000, 0x00000000, 0x00000000,  /*    22050 */ \
0x40000000, 0x00000000, 0x00000000,  /*    16000 */ \
}

#define DEFAULT_BESLOUDNESS_GAIN_PROFILE_FORGET_FACT_TABLE \
{ \
0x7E77, 0x0189, /*    48000 */ \
0x7E54, 0x01AC, /*    44100 */ \
0x7DB4, 0x024C, /*    32000 */ \
0x7CF2, 0x030E, /*    24000 */ \
0x7CAE, 0x0352, /*    22050 */ \
0x7B72, 0x048E, /*    16000 */ \
0x79F7, 0x0609, /*    12000 */ \
0x7972, 0x068E, /*    11025 */ \
0x770E, 0x08F2, /*     8000 */ \
}
#endif

#define DEFAULT_BESLOUDNESS_GAINMAP_IN  \
{ -45, -35, -19, -18,  0 }

#if defined(__BT_SPEAKER_SUPPORT__)
#define DEFAULT_BESLOUDNESS_GAINMAP_OUT \
{  12,  12,  12,  12, -0}
#else
#define DEFAULT_BESLOUDNESS_GAINMAP_OUT \
{   0,  12,  12,  12, -0}
#endif

#define DEFAULT_BESLOUDNESS_WS_GAIN_MAX  0x399A
#define DEFAULT_BESLOUDNESS_WS_GAIN_MIN  0x2666
#define DEFAULT_BESLOUDNESS_FILTER_FIRST 0




#define DEFAULT_AUDIO_COMPENSATION_FILTER_SW \
{ \
  { \
    { /* 0: Compensation Filter for Normal mode, Sample rate: 48000 */\
     32767,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0  \
    }, \
    { /* 0: Compensation Filter for Normal mode, Sample rate: 24000 */\
     32767,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0  \
    }, \
    { /* 0: Compensation Filter for Normal mode, Sample rate: 12000 */\
     32767,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0  \
    }, \
  }, \
  { \
    { /* 0: Compensation Filter for Headset mode, Sample rate: 48000 */\
     32767,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0  \
    }, \
    { /* 0: Compensation Filter for Headset mode, Sample rate: 24000 */ \
     32767,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0  \
    }, \
    { /* 0: Compensation Filter for Headset mode, Sample rate: 12000 */\
     32767,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0  \
    }, \
  }, \
  { \
    { /* 0: Compensation Filter for loudspeaker ringtone mode, Sample rate: 48000 */\
     32767,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0  \
    }, \
    { /* 0: Compensation Filter for loudspeaker ringtone mode, Sample rate: 24000 */\
     32767,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0  \
    }, \
    { /* 0: Compensation Filter for loudspeaker ringtone mode, Sample rate: 12000 */\
     32767,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0, \
         0,     0,     0,     0,     0  \
    }\
  }\
}

// Flexible EQ initial parameter default value
#if defined(MT6256) || defined(MT6276)
// 20 bands
#define DEFAULT_BES_EQ_FLEXIBLE_INITIAL_PARAMETER \
{ \
0x14, 0x00, 0xC8, 0x00, 0x82, 0x00, 0xAA, 0x00, 0xDE, 0x00, \
0x23, 0x01, 0x7C, 0x01, 0xF0, 0x01, 0x88, 0x02, 0x4F, 0x03, \
0x52, 0x04, 0xA5, 0x05, 0x60, 0x07, 0xA2, 0x09, 0x95, 0x0C, \
0x70, 0x10, 0x78, 0x15, 0x0B, 0x1C, 0xA1, 0x24, 0xD9, 0x2F, \
0x40, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x34, 0x00, 0x44, 0x00, \
0x5A, 0x00, 0x74, 0x00, 0x97, 0x00, 0xC6, 0x00, 0x04, 0x01, \
0x53, 0x01, 0xBB, 0x01, 0x42, 0x02, 0xF3, 0x02, 0xDB, 0x03, \
0x09, 0x05, 0x92, 0x06, 0x96, 0x08, 0x38, 0x0B, 0xA7, 0x0E, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00,  \
}
#elif defined(MT6255)
// 10 bands
#define DEFAULT_BES_EQ_FLEXIBLE_INITIAL_PARAMETER \
{ \
0x0A, 0x00, 0xC8, 0x00, 0xAF, 0x00, 0x34, 0x01, 0x1E, 0x02, \
0xBA, 0x03, 0x8C, 0x06, 0x83, 0x0B, 0x3B, 0x14, 0x8F, 0x23, \
0x40, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x85, 0x00, 0xEA, 0x00, 0x9B, 0x01, \
0xD5, 0x02, 0xF7, 0x04, 0xBA, 0x08, 0x53, 0x0F, 0xF1, 0x1A, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, \
}
#elif defined(MT6252) || defined(MT6250)
// 5 bands
#define DEFAULT_BES_EQ_FLEXIBLE_INITIAL_PARAMETER \
{ \
0x05, 0x00, 0xC8, 0x00, 0x63, 0x01, 0xF0, 0x04, 0x92, 0x11, \
0x40, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x8D, 0x03, 0xA4, 0x0C, 0xF4, 0x2C, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, \
}
#else
// 8 bands
#define DEFAULT_BES_EQ_FLEXIBLE_INITIAL_PARAMETER \
{ \
0x08, 0x00, 0xC8, 0x00, 0xCE, 0x00, 0xAA, 0x01, 0x70, 0x03, \
0x19, 0x07, 0xA8, 0x0E, 0x45, 0x1E, 0x40, 0x1F, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0xDC, 0x00, 0xC6, 0x01, 0xA9, 0x03, \
0x8F, 0x07, 0x9C, 0x0F, 0x3E, 0x20, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00,                                                 \
}
#endif

#if defined(DEFAULT_VS_CENTER_FREQ_153)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    153,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15855,   7980, -15931,   7980,             \
         -7788,  15939,   8180, -16332,   8180,             \
         -7948,  16104,   8190, -16348,   8190,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEA8433, 0x3DEA7D5C, 0xC2880000,  /* 48000 */    \
        0x3DC6847C, 0x3DC67CB5, 0xC3280000,  /* 44100 */    \
        0x3CF0862E, 0x3CF07BFC, 0xC3C80000,  /* 32000 */    \
        0x3B818917, 0x3B817A92, 0xC5040000,  /* 24000 */    \
        0x3B3489B4, 0x3B34793D, 0xC63D0000,  /* 22050 */    \
        0x39928D10, 0x3992765F, 0xC8A50000,  /* 16000 */    \
        0x37EB9084, 0x37EB7351, 0xCB000000,  /* 12000 */    \
        0x36F6927D, 0x36F671D6, 0xCC280000,  /* 11025 */    \
        0x349C9789, 0x349C6F7A, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEA8433, 0x3DEA7A1A, 0xC5A10000,  /* 48000 */    \
        0x3DC6847C, 0x3DC67A14, 0xC5A10000,  /* 44100 */    \
        0x3CF0862E, 0x3CF07761, 0xC80C0000,  /* 32000 */    \
        0x3B818917, 0x3B8172B0, 0xCC280000,  /* 24000 */    \
        0x3B3489B4, 0x3B347298, 0xCC280000,  /* 22050 */    \
        0x39928D10, 0x39926E3F, 0xCF8E0000,  /* 16000 */    \
        0x37EB9084, 0x37EB699D, 0xD2D70000,  /* 12000 */    \
        0x36F6927D, 0x36F666C2, 0xD4F70000,  /* 11025 */    \
        0x349C9789, 0x349C5DBC, 0xDA0D0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_156)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    156,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15854,   7980, -15930,   7980,             \
         -7788,  15938,   8180, -16331,   8180,             \
         -7948,  16104,   8190, -16347,   8190,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEA8433, 0x3DEA7D5C, 0xC2880000,  /* 48000 */    \
        0x3DC6847C, 0x3DC67CB5, 0xC3280000,  /* 44100 */    \
        0x3CF0862E, 0x3CF07BFC, 0xC3C80000,  /* 32000 */    \
        0x3B818917, 0x3B817A92, 0xC5040000,  /* 24000 */    \
        0x3B3589B4, 0x3B35793D, 0xC63D0000,  /* 22050 */    \
        0x39948D10, 0x3994765F, 0xC8A50000,  /* 16000 */    \
        0x37ED9084, 0x37ED7351, 0xCB000000,  /* 12000 */    \
        0x36F9927D, 0x36F971D6, 0xCC280000,  /* 11025 */    \
        0x34A09789, 0x34A06F7A, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEA8433, 0x3DEA7A1A, 0xC5A10000,  /* 48000 */    \
        0x3DC6847C, 0x3DC67A14, 0xC5A10000,  /* 44100 */    \
        0x3CF0862E, 0x3CF07761, 0xC80C0000,  /* 32000 */    \
        0x3B818917, 0x3B8172B0, 0xCC280000,  /* 24000 */    \
        0x3B3589B4, 0x3B357298, 0xCC280000,  /* 22050 */    \
        0x39948D10, 0x39946E3F, 0xCF8E0000,  /* 16000 */    \
        0x37ED9084, 0x37ED699D, 0xD2D70000,  /* 12000 */    \
        0x36F9927D, 0x36F966C2, 0xD4F70000,  /* 11025 */    \
        0x34A09789, 0x34A05DBC, 0xDA0D0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_159)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    159,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15853,   7980, -15929,   7980,             \
         -7788,  15937,   8180, -16330,   8180,             \
         -7948,  16103,   8190, -16346,   8190,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEA8433, 0x3DEA7D5C, 0xC2880000,  /* 48000 */    \
        0x3DC6847C, 0x3DC67CB5, 0xC3280000,  /* 44100 */    \
        0x3CF1862E, 0x3CF17BFC, 0xC3C80000,  /* 32000 */    \
        0x3B828917, 0x3B827A92, 0xC5040000,  /* 24000 */    \
        0x3B3689B4, 0x3B36793D, 0xC63D0000,  /* 22050 */    \
        0x39958D10, 0x3995765F, 0xC8A50000,  /* 16000 */    \
        0x37EF9084, 0x37EF7351, 0xCB000000,  /* 12000 */    \
        0x36FB927D, 0x36FB71D6, 0xCC280000,  /* 11025 */    \
        0x34A49789, 0x34A46F7A, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEA8433, 0x3DEA7A1A, 0xC5A10000,  /* 48000 */    \
        0x3DC6847C, 0x3DC67A14, 0xC5A10000,  /* 44100 */    \
        0x3CF1862E, 0x3CF17761, 0xC80C0000,  /* 32000 */    \
        0x3B828917, 0x3B8272B0, 0xCC280000,  /* 24000 */    \
        0x3B3689B4, 0x3B367298, 0xCC280000,  /* 22050 */    \
        0x39958D10, 0x39956E3F, 0xCF8E0000,  /* 16000 */    \
        0x37EF9084, 0x37EF699D, 0xD2D70000,  /* 12000 */    \
        0x36FB927D, 0x36FB66C2, 0xD4F70000,  /* 11025 */    \
        0x34A49789, 0x34A45DBC, 0xDA0D0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_162)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    162,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15852,   7979, -15926,   7979,             \
         -7788,  15936,   8179, -16327,   8179,             \
         -7948,  16102,   8189, -16343,   8189,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEA8433, 0x3DEA7D5C, 0xC2880000,  /* 48000 */    \
        0x3DC6847C, 0x3DC67CB5, 0xC3280000,  /* 44100 */    \
        0x3CF1862E, 0x3CF17BFC, 0xC3C80000,  /* 32000 */    \
        0x3B828917, 0x3B827A92, 0xC5040000,  /* 24000 */    \
        0x3B3689B4, 0x3B36793D, 0xC63D0000,  /* 22050 */    \
        0x39958D10, 0x3995765F, 0xC8A50000,  /* 16000 */    \
        0x37F19084, 0x37F17351, 0xCB000000,  /* 12000 */    \
        0x36FD927D, 0x36FD71D6, 0xCC280000,  /* 11025 */    \
        0x34A89789, 0x34A86F7A, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEA8433, 0x3DEA7A1A, 0xC5A10000,  /* 48000 */    \
        0x3DC6847C, 0x3DC67A14, 0xC5A10000,  /* 44100 */    \
        0x3CF1862E, 0x3CF17761, 0xC80C0000,  /* 32000 */    \
        0x3B828917, 0x3B8272B0, 0xCC280000,  /* 24000 */    \
        0x3B3689B4, 0x3B367298, 0xCC280000,  /* 22050 */    \
        0x39958D10, 0x39956E3F, 0xCF8E0000,  /* 16000 */    \
        0x37F19084, 0x37F1699D, 0xD2D70000,  /* 12000 */    \
        0x36FD927D, 0x36FD66C2, 0xD4F70000,  /* 11025 */    \
        0x34A89789, 0x34A85DBC, 0xDA0D0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_165)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    165,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15851,   7978, -15923,   7978,             \
         -7788,  15935,   8178, -16324,   8178,             \
         -7868,  16109,   8188, -16340,   8188,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEA8433, 0x3DEA7D5C, 0xC2880000,  /* 48000 */    \
        0x3DC6847C, 0x3DC67CB5, 0xC3280000,  /* 44100 */    \
        0x3CF1862E, 0x3CF17BFC, 0xC3C80000,  /* 32000 */    \
        0x3B838917, 0x3B837A92, 0xC5040000,  /* 24000 */    \
        0x3B3789B4, 0x3B37793D, 0xC63D0000,  /* 22050 */    \
        0x39968D10, 0x3996765F, 0xC8A50000,  /* 16000 */    \
        0x37F39084, 0x37F37351, 0xCB000000,  /* 12000 */    \
        0x36FF927D, 0x36FF71D6, 0xCC280000,  /* 11025 */    \
        0x34AC9789, 0x34AC6F7A, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEA8433, 0x3DEA7A1A, 0xC5A10000,  /* 48000 */    \
        0x3DC6847C, 0x3DC67A14, 0xC5A10000,  /* 44100 */    \
        0x3CF1862E, 0x3CF17761, 0xC80C0000,  /* 32000 */    \
        0x3B838917, 0x3B8372B0, 0xCC280000,  /* 24000 */    \
        0x3B3789B4, 0x3B377298, 0xCC280000,  /* 22050 */    \
        0x39968D10, 0x39966E3F, 0xCF8E0000,  /* 16000 */    \
        0x37F39084, 0x37F3699D, 0xD2D70000,  /* 12000 */    \
        0x36FF927D, 0x36FF66C2, 0xD4F70000,  /* 11025 */    \
        0x34AC9789, 0x34AC5DBC, 0xDA0D0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_168)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    168,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15851,   7980, -15925,   7980,             \
         -7788,  15935,   8180, -16326,   8180,             \
         -7948,  16100,   8190, -16342,   8190,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEA8433, 0x3DEA7D5C, 0xC2880000,  /* 48000 */    \
        0x3DC6847C, 0x3DC67CB5, 0xC3280000,  /* 44100 */    \
        0x3CF1862E, 0x3CF17BFC, 0xC3C80000,  /* 32000 */    \
        0x3B838917, 0x3B837A92, 0xC5040000,  /* 24000 */    \
        0x3B3789B4, 0x3B37793D, 0xC63D0000,  /* 22050 */    \
        0x39988D10, 0x3998765F, 0xC8A50000,  /* 16000 */    \
        0x37F59084, 0x37F57351, 0xCB000000,  /* 12000 */    \
        0x3701927D, 0x370171D6, 0xCC280000,  /* 11025 */    \
        0x34B09789, 0x34B06F7A, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEA8433, 0x3DEA7A12, 0xC5A10000,  /* 48000 */    \
        0x3DC6847C, 0x3DC67A0A, 0xC5A10000,  /* 44100 */    \
        0x3CF1862E, 0x3CF1774F, 0xC80C0000,  /* 32000 */    \
        0x3B838917, 0x3B8372B0, 0xCC280000,  /* 24000 */    \
        0x3B3789B4, 0x3B377298, 0xCC280000,  /* 22050 */    \
        0x39988D10, 0x39986E3F, 0xCF8E0000,  /* 16000 */    \
        0x37F59084, 0x37F5699D, 0xD2D70000,  /* 12000 */    \
        0x3701927D, 0x370166C2, 0xD4F70000,  /* 11025 */    \
        0x34B09789, 0x34B05DBC, 0xDA0D0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_171)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    171,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15850,   7980, -15924,   7980,             \
         -7788,  15934,   8180, -16325,   8180,             \
         -7948,  16099,   8190, -16341,   8190,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEB8433, 0x3DEB7D5C, 0xC2880000,  /* 48000 */    \
        0x3DC7847C, 0x3DC77CB5, 0xC3280000,  /* 44100 */    \
        0x3CF2862E, 0x3CF27BFC, 0xC3C80000,  /* 32000 */    \
        0x3B848917, 0x3B847A92, 0xC5040000,  /* 24000 */    \
        0x3B3889B4, 0x3B38793D, 0xC63D0000,  /* 22050 */    \
        0x39998D10, 0x3999765F, 0xC8A50000,  /* 16000 */    \
        0x37F79084, 0x37F77351, 0xCB000000,  /* 12000 */    \
        0x3704927D, 0x370471D6, 0xCC280000,  /* 11025 */    \
        0x34B49789, 0x34B46F7A, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEB8433, 0x3DEB7A12, 0xC5A10000,  /* 48000 */    \
        0x3DC7847C, 0x3DC77A0A, 0xC5A10000,  /* 44100 */    \
        0x3CF2862E, 0x3CF2774F, 0xC80C0000,  /* 32000 */    \
        0x3B848917, 0x3B8472B0, 0xCC280000,  /* 24000 */    \
        0x3B3889B4, 0x3B387298, 0xCC280000,  /* 22050 */    \
        0x39998D10, 0x39996E3F, 0xCF8E0000,  /* 16000 */    \
        0x37F79084, 0x37F7699D, 0xD2D70000,  /* 12000 */    \
        0x3704927D, 0x370466C2, 0xD4F70000,  /* 11025 */    \
        0x34B49789, 0x34B45DBC, 0xDA0D0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_174)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    174,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15849,   7981, -15925,   7981,             \
         -7788,  15933,   8181, -16326,   8181,             \
         -7948,  16098,   8191, -16342,   8191,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEB8433, 0x3DEB7D5C, 0xC2880000,  /* 48000 */    \
        0x3DC7847C, 0x3DC77CB5, 0xC3280000,  /* 44100 */    \
        0x3CF2862E, 0x3CF27BFC, 0xC3C80000,  /* 32000 */    \
        0x3B858917, 0x3B857A92, 0xC5040000,  /* 24000 */    \
        0x3B3889B4, 0x3B38793D, 0xC63D0000,  /* 22050 */    \
        0x399A8D10, 0x399A765F, 0xC8A50000,  /* 16000 */    \
        0x37F99084, 0x37F97351, 0xCB000000,  /* 12000 */    \
        0x3706927D, 0x370671D6, 0xCC280000,  /* 11025 */    \
        0x34B99789, 0x34B96F7A, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEB8433, 0x3DEB7A12, 0xC5A10000,  /* 48000 */    \
        0x3DC7847C, 0x3DC77A0A, 0xC5A10000,  /* 44100 */    \
        0x3CF2862E, 0x3CF2774F, 0xC80C0000,  /* 32000 */    \
        0x3B858917, 0x3B8572B0, 0xCC280000,  /* 24000 */    \
        0x3B3889B4, 0x3B387298, 0xCC280000,  /* 22050 */    \
        0x399A8D10, 0x399A6E3F, 0xCF8E0000,  /* 16000 */    \
        0x37F99084, 0x37F9699D, 0xD2D70000,  /* 12000 */    \
        0x3706927D, 0x370666C2, 0xD4F70000,  /* 11025 */    \
        0x34B99789, 0x34B95DBC, 0xDA0D0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_177)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    177,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15855,   8050, -16058,   8050,             \
         -7788,  15938,   8192, -16343,   8192,             \
         -7997,  16151,   8187, -16335,   8187,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEA8434, 0x3DEA7D5D, 0xC2890000,  /* 48000 */    \
        0x3DC7847D, 0x3DC77CB5, 0xC3290000,  /* 44100 */    \
        0x3CF2862F, 0x3CF27BFC, 0xC3C80000,  /* 32000 */    \
        0x3B858918, 0x3B857A93, 0xC5050000,  /* 24000 */    \
        0x3B3989B5, 0x3B39793E, 0xC63D0000,  /* 22050 */    \
        0x399C8D10, 0x399C765F, 0xC8A50000,  /* 16000 */    \
        0x37FB9084, 0x37FB7351, 0xCB000000,  /* 12000 */    \
        0x3709927D, 0x370971D7, 0xCC290000,  /* 11025 */    \
        0x34BD978A, 0x34BD6F7B, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEA8434, 0x3DEA7A1B, 0xC5A10000,  /* 48000 */    \
        0x3DC7847D, 0x3DC77A14, 0xC5A10000,  /* 44100 */    \
        0x3CF2862F, 0x3CF27762, 0xC80D0000,  /* 32000 */    \
        0x3B858918, 0x3B8572B0, 0xCC290000,  /* 24000 */    \
        0x3B3989B5, 0x3B397298, 0xCC290000,  /* 22050 */    \
        0x399C8D10, 0x399C6E40, 0xCF8F0000,  /* 16000 */    \
        0x37FB9084, 0x37FB699E, 0xD2D70000,  /* 12000 */    \
        0x3709927D, 0x370966C2, 0xD4F70000,  /* 11025 */    \
        0x34BD978A, 0x34BD5DBC, 0xDA0E0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_180)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    180,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15855,   8050, -16057,   8050,             \
         -7788,  15938,   8192, -16342,   8192,             \
         -8061,  16217,   8187, -16334,   8187,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEA8434, 0x3DEA7D5D, 0xC2890000,  /* 48000 */    \
        0x3DC7847D, 0x3DC77CB5, 0xC3290000,  /* 44100 */    \
        0x3CF2862F, 0x3CF27BFC, 0xC3C80000,  /* 32000 */    \
        0x3B858918, 0x3B857A93, 0xC5050000,  /* 24000 */    \
        0x3B3989B5, 0x3B39793E, 0xC63D0000,  /* 22050 */    \
        0x399D8D10, 0x399D765F, 0xC8A50000,  /* 16000 */    \
        0x37FD9084, 0x37FD7351, 0xCB000000,  /* 12000 */    \
        0x370C927D, 0x370C71D7, 0xCC290000,  /* 11025 */    \
        0x34C2978A, 0x34C26F7B, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEA8434, 0x3DEA7A1B, 0xC5A10000,  /* 48000 */    \
        0x3DC7847D, 0x3DC77A14, 0xC5A10000,  /* 44100 */    \
        0x3CF2862F, 0x3CF27762, 0xC80D0000,  /* 32000 */    \
        0x3B858918, 0x3B8572B0, 0xCC290000,  /* 24000 */    \
        0x3B3989B5, 0x3B397298, 0xCC290000,  /* 22050 */    \
        0x399D8D10, 0x399D6E40, 0xCF8F0000,  /* 16000 */    \
        0x37FD9084, 0x37FD699E, 0xD2D70000,  /* 12000 */    \
        0x370C927D, 0x370C66C2, 0xD4F70000,  /* 11025 */    \
        0x34C2978A, 0x34C25DBC, 0xDA0E0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_183)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    183,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15855,   8050, -16056,   8050,             \
         -7788,  15938,   8192, -16341,   8192,             \
         -8061,  16217,   8187, -16333,   8187,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEB8434, 0x3DEB7D5D, 0xC2890000,  /* 48000 */    \
        0x3DC7847D, 0x3DC77CB5, 0xC3290000,  /* 44100 */    \
        0x3CF3862F, 0x3CF37BFC, 0xC3C80000,  /* 32000 */    \
        0x3B868918, 0x3B867A93, 0xC5050000,  /* 24000 */    \
        0x3B3A89B5, 0x3B3A793E, 0xC63D0000,  /* 22050 */    \
        0x399E8D10, 0x399E765F, 0xC8A50000,  /* 16000 */    \
        0x38009084, 0x38007351, 0xCB000000,  /* 12000 */    \
        0x370E927D, 0x370E71D7, 0xCC290000,  /* 11025 */    \
        0x34B797A8, 0x34B76E1E, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEB8434, 0x3DEB7A1B, 0xC5A10000,  /* 48000 */    \
        0x3DC7847D, 0x3DC77A14, 0xC5A10000,  /* 44100 */    \
        0x3CF3862F, 0x3CF37762, 0xC80D0000,  /* 32000 */    \
        0x3B868918, 0x3B8672B0, 0xCC290000,  /* 24000 */    \
        0x3B3A89B5, 0x3B3A7298, 0xCC290000,  /* 22050 */    \
        0x399E8D10, 0x399E6E40, 0xCF8F0000,  /* 16000 */    \
        0x38009084, 0x3800699E, 0xD2D70000,  /* 12000 */    \
        0x370E927D, 0x370E66C2, 0xD4F70000,  /* 11025 */    \
        0x34B797A8, 0x34B75EA6, 0xDA0E0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_186)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    186,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7676,  15822,   8050, -16054,   8050,             \
         -7788,  15938,   8192, -16339,   8192,             \
         -8029,  16184,   8187, -16331,   8187,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEB8434, 0x3DEB7D5D, 0xC2890000,  /* 48000 */    \
        0x3DC7847D, 0x3DC77CB5, 0xC3290000,  /* 44100 */    \
        0x3CF3862F, 0x3CF37BFC, 0xC3C80000,  /* 32000 */    \
        0x3B868918, 0x3B867A93, 0xC5050000,  /* 24000 */    \
        0x3B3B89B5, 0x3B3B793E, 0xC63D0000,  /* 22050 */    \
        0x399F8D10, 0x399F765F, 0xC8A50000,  /* 16000 */    \
        0x38029084, 0x38027351, 0xCB000000,  /* 12000 */    \
        0x3711927D, 0x371171D7, 0xCC290000,  /* 11025 */    \
        0x34BC97A8, 0x34BC6E1E, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEB8434, 0x3DEB7A1B, 0xC5A10000,  /* 48000 */    \
        0x3DC7847D, 0x3DC77A14, 0xC5A10000,  /* 44100 */    \
        0x3CF3862F, 0x3CF37762, 0xC80D0000,  /* 32000 */    \
        0x3B868918, 0x3B8672B0, 0xCC290000,  /* 24000 */    \
        0x3B3B89B5, 0x3B3B7298, 0xCC290000,  /* 22050 */    \
        0x399F8D10, 0x399F6E40, 0xCF8F0000,  /* 16000 */    \
        0x38029084, 0x3802699E, 0xD2D70000,  /* 12000 */    \
        0x3711927D, 0x371166C2, 0xD4F70000,  /* 11025 */    \
        0x34BC97A8, 0x34BC5EA6, 0xDA0E0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_189)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    189,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15855,   8050, -16053,   8050,             \
         -7788,  15938,   8192, -16338,   8192,             \
         -8061,  16217,   8187, -16330,   8187,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3DEB8434, 0x3DEB7D5D, 0xC2890000,  /* 48000 */    \
        0x3DC7847D, 0x3DC77CB5, 0xC3290000,  /* 44100 */    \
        0x3CF3862F, 0x3CF37BFC, 0xC3C80000,  /* 32000 */    \
        0x3B878918, 0x3B877A93, 0xC5050000,  /* 24000 */    \
        0x3B3C89B5, 0x3B3C793E, 0xC63D0000,  /* 22050 */    \
        0x39A18D10, 0x39A1765F, 0xC8A50000,  /* 16000 */    \
        0x38049084, 0x38047351, 0xCB000000,  /* 12000 */    \
        0x3713927D, 0x371371D7, 0xCC290000,  /* 11025 */    \
        0x34C097A8, 0x34C06E1E, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3DEB8434, 0x3DEB7A1B, 0xC5A10000,  /* 48000 */    \
        0x3DC7847D, 0x3DC77A14, 0xC5A10000,  /* 44100 */    \
        0x3CF3862F, 0x3CF37762, 0xC80D0000,  /* 32000 */    \
        0x3B878918, 0x3B8772B0, 0xCC290000,  /* 24000 */    \
        0x3B3C89B5, 0x3B3C7298, 0xCC290000,  /* 22050 */    \
        0x39A18D10, 0x39A16E40, 0xCF8F0000,  /* 16000 */    \
        0x38049084, 0x3804699E, 0xD2D70000,  /* 12000 */    \
        0x3713927D, 0x371366C2, 0xD4F70000,  /* 11025 */    \
        0x34C097A8, 0x34C05EA6, 0xDA0E0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_192)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    192,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7708,  15855,   8050, -16051,   8050,             \
         -7788,  15938,   8192, -16336,   8192,             \
         -8061,  16217,   8187, -16328,   8187,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3E1083EB, 0x3E107D5D, 0xC2890000,  /* 48000 */    \
        0x3DE38446, 0x3DE37CB5, 0xC3290000,  /* 44100 */    \
        0x3D1885E7, 0x3D187BFC, 0xC3C80000,  /* 32000 */    \
        0x3C4A8794, 0x3C4A7A93, 0xC5050000,  /* 24000 */    \
        0x3BD1888B, 0x3BD1793E, 0xC63D0000,  /* 22050 */    \
        0x3A338BEF, 0x3A33765F, 0xC8A50000,  /* 16000 */    \
        0x38938F6C, 0x38937351, 0xCB000000,  /* 12000 */    \
        0x37EA90D6, 0x37EA71D7, 0xCC290000,  /* 11025 */    \
        0x354A96A2, 0x354A6E1E, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3E1083EB, 0x3E107ABE, 0xC5050000,  /* 48000 */    \
        0x3DE38446, 0x3DE37AB8, 0xC5050000,  /* 44100 */    \
        0x3D1885E7, 0x3D187805, 0xC7730000,  /* 32000 */    \
        0x3C4A8794, 0x3C4A75E0, 0xC93D0000,  /* 24000 */    \
        0x3BD1888B, 0x3BD17524, 0xC9D50000,  /* 22050 */    \
        0x3A338BEF, 0x3A3370C9, 0xCD4E0000,  /* 16000 */    \
        0x38938F6C, 0x38936C21, 0xD0AA0000,  /* 12000 */    \
        0x37EA90D6, 0x37EA6A85, 0xD1C30000,  /* 11025 */    \
        0x354A96A2, 0x354A611B, 0xD80F0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_195)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    195,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7393,  15528,   8050, -16049,   8050,             \
         -7788,  15938,   8192, -16334,   8192,             \
         -8061,  16217,   8187, -16326,   8187,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3E1083EB, 0x3E107D5D, 0xC2890000,  /* 48000 */    \
        0x3DE38446, 0x3DE37CB5, 0xC3290000,  /* 44100 */    \
        0x3D1885E7, 0x3D187BFC, 0xC3C80000,  /* 32000 */    \
        0x3C4A8794, 0x3C4A7A93, 0xC5050000,  /* 24000 */    \
        0x3BD2888B, 0x3BD2793E, 0xC63D0000,  /* 22050 */    \
        0x3A348BEF, 0x3A34765F, 0xC8A50000,  /* 16000 */    \
        0x38968F6C, 0x38967351, 0xCB000000,  /* 12000 */    \
        0x37ED90D6, 0x37ED71D7, 0xCC290000,  /* 11025 */    \
        0x354F96A2, 0x354F6E1E, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3E1083EB, 0x3E107ABE, 0xC5050000,  /* 48000 */    \
        0x3DE38446, 0x3DE37AB8, 0xC5050000,  /* 44100 */    \
        0x3D1885E7, 0x3D187805, 0xC7730000,  /* 32000 */    \
        0x3C4A8794, 0x3C4A75E0, 0xC93D0000,  /* 24000 */    \
        0x3BD2888B, 0x3BD27524, 0xC9D50000,  /* 22050 */    \
        0x3A348BEF, 0x3A3470C9, 0xCD4E0000,  /* 16000 */    \
        0x38968F6C, 0x38966C21, 0xD0AA0000,  /* 12000 */    \
        0x37ED90D6, 0x37ED6A85, 0xD1C30000,  /* 11025 */    \
        0x354F96A2, 0x354F611B, 0xD80F0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_198)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    198,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7393,  15528,   8050, -16048,   8050,             \
         -7788,  15938,   8192, -16334,   8192,             \
         -8061,  16217,   8187, -16326,   8187,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3E1083EB, 0x3E107D5D, 0xC2890000,  /* 48000 */    \
        0x3DE38446, 0x3DE37CB5, 0xC3290000,  /* 44100 */    \
        0x3D1885E7, 0x3D187BFC, 0xC3C80000,  /* 32000 */    \
        0x3C4B8794, 0x3C4B7A93, 0xC5050000,  /* 24000 */    \
        0x3BD3888B, 0x3BD3793E, 0xC63D0000,  /* 22050 */    \
        0x3A368BEF, 0x3A36765F, 0xC8A50000,  /* 16000 */    \
        0x38988F6C, 0x38987351, 0xCB000000,  /* 12000 */    \
        0x37F090D6, 0x37F071D7, 0xCC290000,  /* 11025 */    \
        0x355496A2, 0x35546E1E, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3E1083EB, 0x3E107ABE, 0xC5050000,  /* 48000 */    \
        0x3DE38446, 0x3DE37AB8, 0xC5050000,  /* 44100 */    \
        0x3D1885E7, 0x3D187805, 0xC7730000,  /* 32000 */    \
        0x3C4B8794, 0x3C4B75E0, 0xC93D0000,  /* 24000 */    \
        0x3BD3888B, 0x3BD37524, 0xC9D50000,  /* 22050 */    \
        0x3A368BEF, 0x3A3670C9, 0xCD4E0000,  /* 16000 */    \
        0x38988F6C, 0x38986C21, 0xD0AA0000,  /* 12000 */    \
        0x37F090D6, 0x37F06A85, 0xD1C30000,  /* 11025 */    \
        0x355496A2, 0x3554611B, 0xD80F0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_201)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    201,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7238,  15365,   8050, -16046,   8050,             \
         -7788,  15938,   8192, -16332,   8192,             \
         -8078,  16233,   8187, -16324,   8187,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3E1083EB, 0x3E107D5D, 0xC2890000,  /* 48000 */    \
        0x3DE38446, 0x3DE37CB5, 0xC3290000,  /* 44100 */    \
        0x3D1985E7, 0x3D197BFC, 0xC3C80000,  /* 32000 */    \
        0x3C4C8794, 0x3C4C7A93, 0xC5050000,  /* 24000 */    \
        0x3BD4888B, 0x3BD4793E, 0xC63D0000,  /* 22050 */    \
        0x3A378BEF, 0x3A37765F, 0xC8A50000,  /* 16000 */    \
        0x389A8F6C, 0x389A7351, 0xCB000000,  /* 12000 */    \
        0x37F390D6, 0x37F371D7, 0xCC290000,  /* 11025 */    \
        0x355996A2, 0x35596E1E, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3E1083EB, 0x3E107ABE, 0xC5050000,  /* 48000 */    \
        0x3DE38446, 0x3DE37AB8, 0xC5050000,  /* 44100 */    \
        0x3D1985E7, 0x3D197805, 0xC7730000,  /* 32000 */    \
        0x3C4C8794, 0x3C4C75E0, 0xC93D0000,  /* 24000 */    \
        0x3BD4888B, 0x3BD47524, 0xC9D50000,  /* 22050 */    \
        0x3A378BEF, 0x3A3770C9, 0xCD4E0000,  /* 16000 */    \
        0x389A8F6C, 0x389A6C21, 0xD0AA0000,  /* 12000 */    \
        0x37F390D6, 0x37F36A85, 0xD1C30000,  /* 11025 */    \
        0x355996A2, 0x3559611B, 0xD80F0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_204)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    204,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7238,  15365,   8050, -16045,   8050,             \
         -7836,  15987,   8192, -16331,   8192,             \
         -8078,  16233,   8187, -16323,   8187,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3E1083EB, 0x3E107D5D, 0xC2890000,  /* 48000 */    \
        0x3DE48446, 0x3DE47CB5, 0xC3290000,  /* 44100 */    \
        0x3D1985E7, 0x3D197BFC, 0xC3C80000,  /* 32000 */    \
        0x3C4C8794, 0x3C4C7A93, 0xC5050000,  /* 24000 */    \
        0x3BD4888B, 0x3BD4793E, 0xC63D0000,  /* 22050 */    \
        0x3A388BEF, 0x3A38765F, 0xC8A50000,  /* 16000 */    \
        0x389D8F6C, 0x389D7351, 0xCB000000,  /* 12000 */    \
        0x37F690D6, 0x37F671D7, 0xCC290000,  /* 11025 */    \
        0x355E96A2, 0x355E6E1E, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3E1083EB, 0x3E107ABE, 0xC5050000,  /* 48000 */    \
        0x3DE48446, 0x3DE47AB8, 0xC5050000,  /* 44100 */    \
        0x3D1985E7, 0x3D197805, 0xC7730000,  /* 32000 */    \
        0x3C4C8794, 0x3C4C75E0, 0xC93D0000,  /* 24000 */    \
        0x3BD4888B, 0x3BD47524, 0xC9D50000,  /* 22050 */    \
        0x3A388BEF, 0x3A3870C9, 0xCD4E0000,  /* 16000 */    \
        0x389D8F6C, 0x389D6C21, 0xD0AA0000,  /* 12000 */    \
        0x37F690D6, 0x37F66A85, 0xD1C30000,  /* 11025 */    \
        0x355E96A2, 0x355E611B, 0xD80F0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_207)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    207,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7238,  15365,   8050, -16043,   8050,             \
         -7836,  15987,   8192, -16329,   8192,             \
         -8078,  16233,   8187, -16321,   8187,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3E1083EB, 0x3E107D5D, 0xC2890000,  /* 48000 */    \
        0x3DE48446, 0x3DE47CB5, 0xC3290000,  /* 44100 */    \
        0x3D1A85E7, 0x3D1A7BFC, 0xC3C80000,  /* 32000 */    \
        0x3C4D8794, 0x3C4D7A93, 0xC5050000,  /* 24000 */    \
        0x3BD5888B, 0x3BD5793E, 0xC63D0000,  /* 22050 */    \
        0x3A3A8BEF, 0x3A3A765F, 0xC8A50000,  /* 16000 */    \
        0x389F8F6C, 0x389F7351, 0xCB000000,  /* 12000 */    \
        0x37F890D6, 0x37F871D7, 0xCC290000,  /* 11025 */    \
        0x356396A2, 0x35636E1E, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3E1083EB, 0x3E107ABE, 0xC5050000,  /* 48000 */    \
        0x3DE48446, 0x3DE47AB8, 0xC5050000,  /* 44100 */    \
        0x3D1A85E7, 0x3D1A7805, 0xC7730000,  /* 32000 */    \
        0x3C4D8794, 0x3C4D75E0, 0xC93D0000,  /* 24000 */    \
        0x3BD5888B, 0x3BD57524, 0xC9D50000,  /* 22050 */    \
        0x3A3A8BEF, 0x3A3A70C9, 0xCD4E0000,  /* 16000 */    \
        0x389F8F6C, 0x389F6C21, 0xD0AA0000,  /* 12000 */    \
        0x37F890D6, 0x37F86A85, 0xD1C30000,  /* 11025 */    \
        0x356396A2, 0x3563611B, 0xD80F0000,  /*  8000 */    \
    }                                                       \
}
#elif defined(DEFAULT_VS_CENTER_FREQ_210)
#define DEFAULT_VIBR_INITIAL_PARAMETER                      \
{                                                           \
    KAL_FALSE,                                              \
    210,                                                    \
    {                                                       \
         -4678,  11792,    407,    204,    407,             \
         -6978,  12257,   2929,  -2945,   2929,             \
         -7085,  15202,   8050, -16041,   8050,             \
         -7836,  15987,   8192, -16327,   8192,             \
         -8078,  16233,   8187, -16319,   8187,             \
             0,      0,      0,      0,      0,             \
             0                                              \
    },                                                      \
    {                                                       \
        /* filter 0 */                                      \
        0x3E1183EB, 0x3E117D5D, 0xC2890000,  /* 48000 */    \
        0x3DE48446, 0x3DE47CB5, 0xC3290000,  /* 44100 */    \
        0x3D1A85E7, 0x3D1A7BFC, 0xC3C80000,  /* 32000 */    \
        0x3C4D8794, 0x3C4D7A93, 0xC5050000,  /* 24000 */    \
        0x3BD6888B, 0x3BD6793E, 0xC63D0000,  /* 22050 */    \
        0x3A3B8BEF, 0x3A3B765F, 0xC8A50000,  /* 16000 */    \
        0x38A28F6C, 0x38A27351, 0xCB000000,  /* 12000 */    \
        0x37FB90D6, 0x37FB71D7, 0xCC290000,  /* 11025 */    \
        0x356196B1, 0x35616E1E, 0xCE700000,  /*  8000 */    \
        /* filter 1 */                                      \
        0x3E1183EB, 0x3E117ABE, 0xC5050000,  /* 48000 */    \
        0x3DE48446, 0x3DE47AB8, 0xC5050000,  /* 44100 */    \
        0x3D1A85E7, 0x3D1A7805, 0xC7730000,  /* 32000 */    \
        0x3C4D8794, 0x3C4D75E0, 0xC93D0000,  /* 24000 */    \
        0x3BD6888B, 0x3BD67524, 0xC9D50000,  /* 22050 */    \
        0x3A3B8BEF, 0x3A3B70C9, 0xCD4E0000,  /* 16000 */    \
        0x38A28F6C, 0x38A26C21, 0xD0AA0000,  /* 12000 */    \
        0x37FB90D6, 0x37FB6A85, 0xD1C30000,  /* 11025 */    \
        0x356196B1, 0x3561611B, 0xD80F0000,  /*  8000 */    \
    }                                                       \
}
#else
#define DEFAULT_VIBR_INITIAL_PARAMETER \
{ \
  0\
}
#endif


#endif /* __AUDIO_COMMON_CONFIG_H__ */

