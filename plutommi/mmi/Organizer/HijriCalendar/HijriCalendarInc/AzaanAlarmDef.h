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
 * AzaanAlarmDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Alarm application related screens.
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
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMI_AZAANDEF_H
#define __MMI_AZAANDEF_H

#include "MMIDataType.h"
#include "AlarmDef.h"
#include "custom_mmi_default_value.h"
#include "FileMgrSrvGprot.h"
typedef enum
{
    MMI_AZAAN_ALARM_FAJR,
    MMI_AZAAN_ALARM_ZUHR,
    MMI_AZAAN_ALARM_ASR,
    MMI_AZAAN_ALARM_MAGRIB,
    MMI_AZAAN_ALARM_ISHA,
    MMI_AZAAN_ALARM_TOTAL
}mmi_azaan_alarm_enum;

typedef enum
{    
    MMI_AZAAN_ALERT_VIBRATION_AND_RING,
    MMI_AZAAN_ALERT_RING,
    MMI_AZAAN_ALERT_VIBRATION,
    MMI_AZAAN_ALERT_TYPE_SETTING_NUM
}mmi_azaan_alert_type_enum;

#define MMI_AZAAN_TONE_LENGTH   ((41 + 1) * ENCODING_LENGTH)

/*typedef enum
{
    MMI_AZAAN_ALERT_VIBRATION_AND_RING,
    MMI_AZAAN_ALERT_RING,
    MMI_AZAAN_ALERT_VIBRATION,
    MMI_AZAAN_ALERT_TOTAL
}mmi_azaan_alert_type_enum;*/

/*typedef struct
{
    U8	Hour;
    U8	Min;
    U8	State;
    U8	AudioValue;
    U8	AlertType;
}mmi_hijri_azaan_nvram_struct;*/
#define AZAAN_ALARM_TONE_FILE 0X1208

typedef struct
{
    S32	CurrHighlightState;
    mmi_hijri_azaan_nvram_struct	AzaanAlmList[MMI_AZAAN_ALARM_TOTAL];
    S8	HourBuff[(HOUR_LENGTH + 1) *ENCODING_LENGTH];
    S8	MinBuff[(MINUTE_LENGTH + 1) *ENCODING_LENGTH];
    U8	CurrHighlightAlarm;
    U8 curr_hour;
    U8 curr_min;
    U16	CurrHighlightAudioValue;
    S32 CurrHighlightAlertType;
    S8*	AzaanAlmOnOffString[2];
    U8 tone_path[SRV_FMGR_PATH_BUFFER_SIZE];
    S8*	AzaanAlmAlertTypeStr[MMI_AZAAN_ALERT_TYPE_SETTING_NUM];
    U8 prof_tone_str[MMI_AZAAN_TONE_LENGTH];
    U8 is_save_to_history;
    U16 azaan_tone_index;
    U16 user_tag;
    S8 aud_curselitem_inline_index;
	MMI_BOOL is_tone_playing;
	U8 active_alm_idx;
	MMI_BOOL is_vibing;
}mmi_azaan_cntx_struct;

#endif /* __MMI_AZAANDEF_H */
