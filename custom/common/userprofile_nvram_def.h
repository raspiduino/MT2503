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
 * userprofile_nvram_def.h
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

#ifndef __USERPROFILE_NVRAM_DEF_H__
#define __USERPROFILE_NVRAM_DEF_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*
 *   Include Headers
 */
#include "kal_general_types.h"

/*
 *   NVRAM Basic Headers
 */
#include "nvram_data_items.h"
#include "nvram_defs.h"


/*
 *   User Headers
 */
#include "custom_mmi_default_value.h"


/*
 *   LID Enums
 */
 
typedef enum
{
    NVRAM_EF_SRV_PROF_SETTING_LID           = NVRAM_LID_GRP_USERPROFILE(0),
    NVRAM_EF_SRV_PROF_EXT_MELODY_LID        = NVRAM_LID_GRP_USERPROFILE(1),

/*
 *  Last LID of GPS Group
 */
    NVRAM_EF_USERPROFILE_LAST_LID           = NVRAM_LID_GRP_USERPROFILE(255)
}nvram_lid_userprofile_enum;


/*
 *   Verno
 */
#define NVRAM_EF_SRV_PROF_SETTING_LID_VERNO             "001"
#define NVRAM_EF_SRV_PROF_EXT_MELODY_LID_VERNO          "001"


/*
 * Record Size/Total Records
 */
/* Profile Srv*/
#ifndef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
#define NVRAM_SRV_PROF_PROFILES_TOTAL_NUM   5
#define NVRAM_SRV_PROF_EXT_MELODY_NUM    20
#else
#define NVRAM_SRV_PROF_PROFILES_TOTAL_NUM   14
#define NVRAM_SRV_PROF_EXT_MELODY_NUM    70
#endif

#if defined(__MMI_PROF_SLIM_PROFILES__)
  #ifdef NVRAM_SRV_PROF_EXT_MELODY_NUM
    #undef NVRAM_SRV_PROF_EXT_MELODY_NUM
  #endif
    #define NVRAM_SRV_PROF_EXT_MELODY_NUM 3
#endif

#define NVRAM_SRV_FMGR_PATH_MAX_LEN 259 /* SRV_FMGR_PATH_MAX_LEN */

#if 0
/* under construction !*/
/* under construction !*/
#endif

#define NVRAM_SRV_PROF_RECORD_SIZE     sizeof(nvram_srv_prof_setting_struct)
#define NVRAM_SRV_PROF_RECORD_TOTAL    NVRAM_SRV_PROF_PROFILES_TOTAL_NUM

/* External Melody */
#define NVRAM_EF_SRV_PROF_EXT_MELODY_SIZE   sizeof(nvram_srv_prof_ext_melody_info_struct)
#define NVRAM_EF_SRV_PROF_EXT_MELODY_TOTAL  NVRAM_SRV_PROF_EXT_MELODY_NUM


/*
 *   Data Structure
 */
/* Profile Service Structure*/
typedef struct
{
    kal_uint8 ring_vol;                 /* ring volume level */
    kal_uint8 keypad_vol;               /* keypad volume level */
    kal_uint8 msg_vol;                  /* message volume level */
    kal_uint8 media_vol;                /* message volume level */

    kal_uint8 alert_type;               /* alert type */
    kal_bool noti_sound;                /* notification sound */
    kal_bool vibrate;                   /* if can vibrate */
    kal_uint8 ring_type;                /* ring type */
    kal_bool intelligent_call_alert;    /* intelligent call alert */
    kal_bool system_alert;              /* system alert */
    kal_uint8 led_pattern;              /* led color pattern */
    kal_uint8 keypad_tone_type;         /* keypad tone type */
    kal_uint8 touch_vol;                /* touch feddback volume level */
    kal_uint8 touch_vib;                /* touch feedback vibration level */

    kal_uint16 power_on_tone;            /* power on tone */
    kal_uint16 power_off_tone;           /* power off tone */
    kal_bool power_on_off_tone;          /* powr on/off tone switcher */
    kal_uint16 cover_open_tone;          /* cover open tone */
    kal_uint16 cover_close_tone;         /* cover close tone */

    kal_uint16 sms_tone[4];             /* sms tone */
    kal_uint16 mms_tone[4];             /* mms tone */
    kal_uint16 email_tone[4];           /* email tone */
    kal_uint16 voice_tone[4];           /* voice tone */
    kal_uint16 mt_call_tone[4];         /* mt call tone */
    kal_uint16 vt_call_tone[4];         /* vt call tone */
} nvram_srv_prof_setting_struct;

/* external melody info struct*/
typedef struct
{
    kal_uint16 filefullpath[NVRAM_SRV_FMGR_PATH_MAX_LEN+1];
}nvram_srv_prof_ext_melody_info_struct;


#ifndef NEPTUNE_MMI 
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) && !defined(__IOT__)
    extern nvram_ltable_entry_struct logical_data_item_table_userprofile[];
#endif  /* NEPTUNE_MMI */
#endif  /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#ifdef __cplusplus
}
#endif 

#endif /* __USERPROFILE_NVRAM_DEF_H__ */ 
