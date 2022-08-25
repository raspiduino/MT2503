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
 * AudCoeff.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
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
 *
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __AUDCOEFF_H__
#define __AUDCOEFF_H__

/******************** INPUT FIR ********************************/

#define SPEECH_INPUT_FIR_COEFF_NORMAL_DEFAULT \
   { /* 0: Input FIR coefficients for 2G/3G Normal mode */ \
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

#define SPEECH_INPUT_FIR_COEFF_HEADSET_DEFAULT \
   { /* 1: Input FIR coefficients for 2G/3G/VoIP Headset mode */ \
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

#define SPEECH_INPUT_FIR_COEFF_HANDFREE_DEFAULT \
   { /* 2: Input FIR coefficients for 2G/3G Handfree mode */ \
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

#define SPEECH_INPUT_FIR_COEFF_BT_DEFAULT \
   { /* 3: Input FIR coefficients for 2G/3G/VoIP BT mode */ \
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

#define SPEECH_INPUT_FIR_COEFF_VOIP_NORMAL_DEFAULT \
   { /* 4: Input FIR coefficients for VoIP Normal mode */ \
      506,  -287,   250,  -214,   566, \
      221,    76,  1036,  -329,  1006, \
      574,  -224,  -589,  2436, -1079, \
     1366, -3116,  2142, -3633,  3436, \
   -11302, 20674, 20674,-11302,  3436, \
    -3633,  2142, -3116,  1366, -1079, \
     2436,  -589,  -224,   574,  1006, \
     -329,  1036,    76,   221,   566, \
     -214,   250,  -287,   506,     0 \
   }

#define SPEECH_INPUT_FIR_COEFF_VOIP_HANDFREE_DEFAULT \
   { /* 5: Input FIR coefficients for VoIP Handfree mode */ \
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

#define SPEECH_INPUT_FIR_COEFF_DEFAULT \
{ \
    SPEECH_INPUT_FIR_COEFF_NORMAL_DEFAULT, \
    SPEECH_INPUT_FIR_COEFF_HEADSET_DEFAULT, \
    SPEECH_INPUT_FIR_COEFF_HANDFREE_DEFAULT, \
    SPEECH_INPUT_FIR_COEFF_BT_DEFAULT, \
    SPEECH_INPUT_FIR_COEFF_VOIP_NORMAL_DEFAULT, \
    SPEECH_INPUT_FIR_COEFF_VOIP_HANDFREE_DEFAULT \
}

/******************** OUTPUT FIR ********************************/

#define SPEECH_OUTPUT_FIR_COEFF_NORMAL_DEFAULT \
   { /* 0: Output FIR coefficients for 2G/3G Normal mode */ \
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

#define SPEECH_OUTPUT_FIR_COEFF_HEADSET_DEFAULT \
   { /* 1: Output FIR coefficients for 2G/3G/VoIP Headset mode */ \
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

#define SPEECH_OUTPUT_FIR_COEFF_HANDFREE_DEFAULT \
   { /* 2: Output FIR coefficients for 2G/3G Handfree mode */ \
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

#define SPEECH_OUTPUT_FIR_COEFF_BT_DEFAULT \
   { /* 3: Output FIR coefficients for 2G/3G/VoIP BT mode */ \
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

#define SPEECH_OUTPUT_FIR_COEFF_VOIP_NORMAL_DEFAULT \
   { /* 4: Output FIR coefficients for VoIP Normal mode */ \
      173,  -287,   196,  -405,  -496, \
     -204,  -721,    85,  -772,   -72, \
     -112, -1557,  -215,   413,   191, \
     1049,   820,   766,  -805,  9594, \
   -16362, 20674, 20674,-16362,  9594, \
     -805,   766,   820,  1049,   191, \
      413,  -215, -1557,  -112,   -72, \
     -772,    85,  -721,  -204,  -496, \
     -405,   196,  -287,   173,     0 \
   }

#define SPEECH_OUTPUT_FIR_COEFF_VOIP_HANDFREE_DEFAULT \
   { /* 5: Output FIR coefficients for VoIP Handfree mode */ \
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

#define SPEECH_OUTPUT_FIR_COEFF_DEFAULT \
{ \
    SPEECH_OUTPUT_FIR_COEFF_NORMAL_DEFAULT, \
    SPEECH_OUTPUT_FIR_COEFF_HEADSET_DEFAULT, \
    SPEECH_OUTPUT_FIR_COEFF_HANDFREE_DEFAULT, \
    SPEECH_OUTPUT_FIR_COEFF_BT_DEFAULT, \
    SPEECH_OUTPUT_FIR_COEFF_VOIP_NORMAL_DEFAULT, \
    SPEECH_OUTPUT_FIR_COEFF_VOIP_HANDFREE_DEFAULT \
}

#endif //__AUDCOEFF_H__

