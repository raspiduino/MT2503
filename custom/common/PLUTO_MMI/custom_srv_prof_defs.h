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
 * Filename:
 * ---------
 *  custom_srv_prof_defs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#ifndef CUSTOM_SRV_PROF_DEF_H
#define CUSTOM_SRV_PROF_DEF_H

typedef enum
{
    SRV_PROF_AUD_TONE1 = 101,
    SRV_PROF_AUD_TONE2,
    SRV_PROF_AUD_TONE3,
    SRV_PROF_AUD_TONE4,
    SRV_PROF_AUD_TONE5,
    SRV_PROF_AUD_TONE6,
    SRV_PROF_AUD_TONE7,
    SRV_PROF_AUD_TONE8,
    SRV_PROF_AUD_TONE9,
    SRV_PROF_AUD_TONE10,
    SRV_PROF_AUD_TONE_END_OF_ENUM
}srv_prof_aud_tone_enum;


typedef enum
{
    SRV_PROF_AUD_RING1 = 151,
    SRV_PROF_AUD_RING2,
    SRV_PROF_AUD_RING3,
    SRV_PROF_AUD_RING4,
    SRV_PROF_AUD_RING5,
    SRV_PROF_AUD_RING6,
    SRV_PROF_AUD_RING7,
    SRV_PROF_AUD_RING8,
    SRV_PROF_AUD_RING9,
    SRV_PROF_AUD_RING10,
    SRV_PROF_AUD_RING11,
    SRV_PROF_AUD_RING12,
    SRV_PROF_AUD_RING13,
    SRV_PROF_AUD_RING14,
    SRV_PROF_AUD_RING15,
    SRV_PROF_AUD_RING16,
    SRV_PROF_AUD_RING17,
    SRV_PROF_AUD_RING18,
    SRV_PROF_AUD_RING19,
    SRV_PROF_AUD_RING20,
    SRV_PROF_AUD_RING_END_OF_ENUM
}srv_prof_aud_ring_enum;


/* This enum defined the ring type */
typedef enum
{
    SRV_PROF_RING_TYPE_REPEAT,         /* Ringing */
    SRV_PROF_RING_TYPE_ASCENDING,      /* Acending */
    SRV_PROF_RING_TYPE_ONCE,           /* Once */
    SRV_PROF_RING_TYPE_BEEP_ONCE,      /* Beep once */
    SRV_PROF_RING_TYPE_END_OF_ENUM     /* End of enum */
}srv_prof_ring_type_enum;


/* This enum defined the 7 level volume */
typedef enum
{
    SRV_PROF_VOL_LEVEL_0,       /* Level 0 */
    SRV_PROF_VOL_LEVEL_1,       /* Level 1 */
    SRV_PROF_VOL_LEVEL_2,       /* Level 2 */
    SRV_PROF_VOL_LEVEL_3,       /* Level 3 */
    SRV_PROF_VOL_LEVEL_4,       /* Level 4 */
    SRV_PROF_VOL_LEVEL_5,       /* Level 5 */
    SRV_PROF_VOL_LEVEL_6,       /* Level 6 */
    SRV_PROF_VOL_LEVEL_7,       /* Level 7 */
    SRV_PROF_VOL_LEVEL_END_OF_ENUM /* End of enum */
}srv_prof_vol_level_enum;

/* This enum defined the meida volume */
typedef enum
{
    SRV_PROF_MEDIA_VOL_LEVEL_0,       /* Level 0 */
    SRV_PROF_MEDIA_VOL_LEVEL_1,       /* Level 1 */
    SRV_PROF_MEDIA_VOL_LEVEL_2,       /* Level 2 */
    SRV_PROF_MEDIA_VOL_LEVEL_3,       /* Level 3 */
    SRV_PROF_MEDIA_VOL_LEVEL_4,       /* Level 4 */
    SRV_PROF_MEDIA_VOL_LEVEL_5,       /* Level 5 */
    SRV_PROF_MEDIA_VOL_LEVEL_6,       /* Level 6 */
    SRV_PROF_MEDIA_VOL_LEVEL_7,       /* Level 7 */
    SRV_PROF_MEDIA_VOL_LEVEL_8,       /* Level 8 */
    SRV_PROF_MEDIA_VOL_LEVEL_9,       /* Level 9 */
    SRV_PROF_MEDIA_VOL_LEVEL_10,      /* Level 10 */
    SRV_PROF_MEDIA_VOL_LEVEL_11,      /* Level 11 */
    SRV_PROF_MEDIA_VOL_LEVEL_12,      /* Level 12 */
    SRV_PROF_MEDIA_VOL_LEVEL_13,      /* Level 13 */
    SRV_PROF_MEDIA_VOL_LEVEL_14,      /* Level 14 */
    SRV_PROF_MEDIA_VOL_LEVEL_15,      /* Level 15 */
    SRV_PROF_MEDIA_VOL_LEVEL_16,      /* Level 16 */
    SRV_PROF_MEDIA_VOL_LEVEL_END_OF_ENUM /* End of enum */
}srv_prof_media_vol_level_enum;

/* This enum defined the ring type */
typedef enum
{
    SRV_PROF_VIB_LEVEL_0,       /* Level 0 */
    SRV_PROF_VIB_LEVEL_1,       /* Level 1 */
    SRV_PROF_VIB_LEVEL_2,       /* Level 2 */
    SRV_PROF_VIB_LEVEL_3,       /* Level 3 */
    SRV_PROF_VIB_LEVEL_END_OF_ENUM /* End of enum */
}srv_prof_vib_level_enum;


/* This enum defined the ring play type */
typedef enum
{
    SRV_PROF_ALERT_TYPE_INVALID,       /* Invalid */
    SRV_PROF_ALERT_TYPE_RING,          /* Ringing */
    SRV_PROF_ALERT_TYPE_VIB_ONLY,      /* Vibrate only */
    SRV_PROF_ALERT_TYPE_VIB_AND_RING,  /* Vibrate and ring */
    SRV_PROF_ALERT_TYPE_VIB_THEN_RING, /* Vibrate then ring */
    SRV_PROF_ALERT_TYPE_SILENT,        /* Silent */
    SRV_PROF_ALERT_TYPE_END_OF_ENUM    /* End of enum */
}srv_prof_alert_type_enum;


/* This enum defined LED patterns */
typedef enum
{
    SRV_PROF_LED_NONE,                  /* None */
    SRV_PROF_LED_PATTERN_1,             /* Color 1 */
    SRV_PROF_LED_PATTERN_2,             /* Color 2 */
    SRV_PROF_LED_PATTERN_3,             /* Color 3 */
    SRV_PROF_LED_PATTERN_4,             /* Color 4 */
    SRV_PROF_LED_PATTERN_5,             /* Color 5 */
    SRV_PROF_LED_PATTERN_6,             /* Color 6 */
    SRV_PROF_LED_PATTERN_END_OF_ENUM    /* End of enum */
}srv_prof_led_pattern_enum;


/* This enum defined the keypad tone type */
typedef enum
{
    SRV_PROF_KEYPAD_SILENT,             /* Silent */
    SRV_PROF_KEYPAD_CLICK,              /* Click */
    SRV_PROF_KEYPAD_TONE,               /* Tone */
    SRV_PROF_KEYPAD_NUM_1,              /* Special number key 1 */
    SRV_PROF_KEYPAD_NUM_2,              /* Special number key 2 */
    SRV_PROF_KEYPAD_NUM_3,              /* Special number key 3 */
    SRV_PROF_KEYPAD_NUM_4,              /* Special number key 4 */
    SRV_PROF_KEYPAD_NUM_5,              /* Special number key 5 */
    SRV_PROF_KEYPAD_NUM_6,              /* Special number key 6 */
    SRV_PROF_KEYPAD_CUST_1,             /* Customer 1 */
    SRV_PROF_KEYPAD_CUST_2,             /* Customer 2 */
    SRV_PROF_KEYPAD_CUST_3,             /* Customer 3 */
    SRV_PROF_KEYPAD_CUST_4,             /* Customer 4 */
    SRV_PROF_KEYPAD_CUST_5,             /* Customer 5 */
    SRV_PROF_KEYPAD_CUST_6,             /* Customer 6 */
    SRV_PROF_KEYPAD_END_OF_ENUM 
}srv_prof_keypad_tone_type_enum;

#endif /* CUSTOM_SRV_PROF_DEF_H */

