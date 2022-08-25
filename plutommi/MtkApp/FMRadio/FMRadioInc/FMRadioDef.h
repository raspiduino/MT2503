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
*  FMRadioDef.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio id, const & macro definition
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef _FM_RADIO_DEF_H
#define _FM_RADIO_DEF_H

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__

#include "FMRadioResDef.h"
#include "nvram_common_defs.h"
#include "gdi_include.h"
#include "fmr_config_customize.h"

#if defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__) || defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_320X240__))
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        #define MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #endif
#endif

#define MAX_VOL_LEVEL 7
#define DEFAULT_FREQUENCY 987
#define MAX_MANUAL_INPUT_LEN 6
#define MAX_NAME_INPUT_LEN 12
#define MIN_FM_FREQUENCY FM_RADIO_MIN_FREQ //875
#define MAX_FM_FREQUENCY FM_RADIO_MAX_FREQ //1080
#define FM_BANDWIDTH (MAX_FM_FREQUENCY - MIN_FM_FREQUENCY + 1)
#define NORMAL_REAPEAT_STEP_TIME 2000
#define NORMAL_REAPEAT_STEP_PERIOD 200
#define FAST_REAPEAT_STEP_PERIOD 100
#define NORMAL_REAPEAT_STEP_COUNT (NORMAL_REAPEAT_STEP_TIME / NORMAL_REAPEAT_STEP_PERIOD)
#define TWINKLE_FREQUENCY_COUNT 5
#define TWINKLE_FREQUENCY_ON_TIME 200
#define TWINKLE_FREQUENCY_OFF_TIME 100
#define MMI_FMRDO_RECORD_RENAME_ID 57430

#define FM_SUB_BAND_NUM NVRAM_EF_FM_RADIO_CHANNEL       /* customizable in MMI_Fetures.h */
#define FM_RADIO_CHANNEL_NUM  NVRAM_EF_FM_RADIO_CHANNEL /* customizable in MMI_Fetures.h */

#define FM_SUB_BANDWIDTH ((FM_BANDWIDTH+FM_SUB_BAND_NUM-1)/FM_SUB_BAND_NUM)
#define FM_MARK_SIG(x) ((x) |= 0x80)
#define FM_SIG_MARK(x) ((x) & 0x80)
#define FM_SIG_LVL(x) ((x) & 0x7F)
#define FM_SUB_MARK(x,i) ((x)&(1<<(i)))
#define FM_MARK_SUB(x,i) ((x) |= (1<<(i)))

#if defined(__MMI_FM_RADIO_ANIMATION__)
#define FMRDO_ANIM_SIZE_BASIC_WIDTH 320
#define FMRDO_ANIM_SIZE_BASIC_HEIGHT 195
#define FMRDO_ANIM_BUFFER_SIZE_BASIC ((FMRDO_ANIM_SIZE_BASIC_WIDTH * FMRDO_ANIM_SIZE_BASIC_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL) >> 3)
#endif /* defined(__MMI_FM_RADIO_ANIMATION__)) */ 

#if defined(__MMI_FM_RADIO_RECORD__)
/* Note these defines should be the same as sound recorder */
#define MAX_FM_FILE_NAME_LEN     80
#define MAX_FM_PATH_LEN          25     /* The path is fixed. i.e "c:\audio\" */
#define MAX_FM_FULL_NAME_LEN     (MAX_FM_PATH_LEN+MAX_FM_FILE_NAME_LEN)

#define MAX_FM_INPUT_FILE_LEN    35     /* max file length for user to input */

#define FM_FILE_EXT_AMR L".amr"
#define FM_FILE_EXT_WAV L".wav"
#define FM_FILE_EXT_AWB L".awb"
#define FM_FILE_EXT_DAF L".mp3"

#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#ifdef __MMI_FM_RADIO_RDS__
/*need to define values*/
#define FMRDO_RDS_ON        0x0001 
#define PS_RECIEVE          0x0002
#define RT_RECIEVE          0x0004
#define AF_RECIEVE          0x0008
#define TP_RECIEVE          0x0010
#define FREQ_SWITCH         0x0020
#define RESET_ALL           0x0000
#define MMI_FMRDO_RDS_PS_NAME_SIZE  9
#define MMI_FMRDO_RDS_RT_SIZE       64

typedef enum
{
    FMRDO_RDS_IND_MAIN,
    FMRDO_RDS_IND_TP,
    FMRDO_RDS_IND_AF,
    FMRDO_RDS_IND_TOTAL
}fmrdo_rds_ind_enum;
typedef enum
{
    FMRDO_RDS_SETTING_MAIN,
    FMRDO_RDS_SETTING_AF_CAP,
    FMRDO_RDS_SETTING_AF,
    FMRDO_RDS_SETTING_TP_CAP,
    FMRDO_RDS_SETTING_TP,
    FMRDO_RDS_SETTING_NUM
} fmrdo_rds_setting_item_enum;
typedef enum
{
    FMRDO_RDS_SETTING_STATE_OFF,
    FMRDO_RDS_SETTING_STATE_ON,
    FMRDO_RDS_SETTING_STATE_NUM
} fmrdo_rds_setting;
#endif/*__MMI_FM_RADIO_RDS__*/ 

typedef enum
{
    FMRDO_STATE_NOT_READY = 0,
    FMRDO_STATE_READY,
    FMRDO_STATE_RECORD,
    FMRDO_STATE_RECORD_PAUSE,
    FMRDO_STATE_SEARCH_ONE,
    FMRDO_STATE_SEARCH_ALL,
    FMRDO_STATE_BT_CONNECTING,
    NO_OF_FMRDO_STATE
} fmrdo_state_enum;

#ifdef __MMI_FTE_SUPPORT__
typedef enum
{
    FMRDO_BUTTON_NONE,
    FMRDO_BUTTON_POWER,
    FMRDO_BUTTON_STEP_UP,
    FMRDO_BUTTON_STEP_DOWN,
    FMRDO_BUTTON_MEMO_UP,
    FMRDO_BUTTON_MEMO_DOWN,
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    FMRDO_BUTTON_REC,
    FMRDO_BUTTON_REC_PAUSE,
    FMRDO_BUTTON_REC_STOP,
#endif
    FMRDO_BUTTON_LSK,
    FMRDO_BUTTON_RSK,
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    FMRDO_BUTTON_VOLUME,
    FMRDO_BUTTON_SEARCH,
#else
    FMRDO_BUTTON_SPEAKER,
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    FMRDO_BUTTON_TOTAL
} fmrdo_main_button_enum;

#else /* __MMI_FTE_SUPPORT__ */
 
typedef enum
{
    FMRDO_BUTTON_NONE,
    FMRDO_BUTTON_POWER,
#ifdef __MMI_SLIM_IMG_RES__
    FMRDO_BUTTON_SEARCH_UP,
    FMRDO_BUTTON_SEARCH_DOWN,
#else
    FMRDO_BUTTON_SEARCH,
#endif /* __MMI_SLIM_IMG_RES__ */
    FMRDO_BUTTON_STEP_UP,
    FMRDO_BUTTON_STEP_DOWN,
    FMRDO_BUTTON_REC,
    FMRDO_BUTTON_REC_PAUSE,
    FMRDO_BUTTON_TOTAL
} fmrdo_main_button_enum;

#endif /* __MMI_FTE_SUPPORT__ */

/* Number of FM Radio Main Option */
typedef enum
{
    FMRDO_MAIN_OPTION_CHANNEL_LIST,
    FMRDO_MAIN_OPTION_MANUAL_INPUT,
    FMRDO_MAIN_OPTION_PRESET_AUTO_SEARCH,
    FMRDO_MAIN_OPTION_SETTINGS,
#if defined(__MMI_FM_RADIO_RECORD__)
    FMRDO_MAIN_OPTION_RECORD,
    FMRDO_MAIN_OPTION_FILE_LIST,
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
    FMRDO_MAIN_OPTION_TOTAL
} fmrdo_main_option_item_enum;

#if defined(__MMI_FM_RADIO_RECORD__)

typedef enum
{
    FM_QUALITY_LOW,
    FM_QUALITY_HIGH,
    NO_OF_QUALITY
} fmrdo_record_quality;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#endif /* __MMI_FM_RADIO__ */ 
#endif /* _FM_RADIO_DEF_H */ 

