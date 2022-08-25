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
 *  SmsAppSetting.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application Setting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SMS_APP_SETTING_H__
#define __SMS_APP_SETTING_H__
#include "MMI_features.h"
#include "MMIDataType.h"

#include "MessagesMiscell.h"
#include "l4c_aux_struct.h"

#ifndef MAX_DIGITS_SMS
#define MAX_DIGITS_SMS           21     /* Maximum number of digits in sms source/destination */
#endif

#ifndef MAX_PROFILE_NAME_LEN
#define MAX_PROFILE_NAME_LEN     30     /* check with ps */
#endif

#ifndef MAX_LFOUR_PROFILES
#define MAX_LFOUR_PROFILES                4
#endif

#ifndef MAX_LFOUR_VP
#define MAX_LFOUR_VP                   7
#endif

#ifndef MAX_LFOUR_MSG_TYPE
#define MAX_LFOUR_MSG_TYPE             5
#endif

#ifndef MAX_PROFILE_EDIT_ITEMS
#ifdef __MMI_MESSAGES_SMS_EMAIL__
#define MAX_PROFILE_EDIT_ITEMS   5
#else /* __MMI_MESSAGES_SMS_EMAIL__ */ 
#define MAX_PROFILE_EDIT_ITEMS   4
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */ 
#endif

#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
typedef struct
{
    U16 simUsed;
    U16 simTotal;
    U16 meUsed;
    U16 meTotal;
    U8 prefStorage;
} mmi_sms_mem_status_struct;
#endif /* defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__) */ 

typedef struct
{
    l4c_number_struct scAddr;
    U8 profile; /* SMS_DEST_NO_ENUM */
    U8 para;    /* MMI_PARA_ENUM */
    U8 vp;      /* smsal_vp_enum */
    U8 pid;     /* smsal_pid_enum */
    U8 dcs;     /* smsal_dcs_enum */
} mmi_sms_active_profile_struct;

typedef struct
{
    S32 vpIndex;
    S32 msgTypeIndex;
    U8 profileName[(MAX_PROFILE_NAME_LEN *ENCODING_LENGTH) + ENCODING_LENGTH];
    U8 profileNameDcs;
    U8 profileIndex;
    U8 scAddress[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    U8 emailAddress[(MAX_DIGITS_SMS * ENCODING_LENGTH) + ENCODING_LENGTH];
#endif
} mmi_sms_profile_edit_struct;

typedef struct
{
    U8 currReqProfileNo;
    U8 currMaxPsProfiles;
    U8 profileNameLength;
    U8 profileName[MAX_LFOUR_PROFILES][(MAX_PROFILE_NAME_LEN *ENCODING_LENGTH) + ENCODING_LENGTH];
} mmi_sms__profile_list_struct; /* msg_profile_list_struct; */

extern void mmi_sms_set_msg_menu_highlight_handler(void); /* mmi_msg_set_msg_menu_highlight_handler */
extern void mmi_sms_highlight_msg_settings_profile_edit(void);
#ifdef __SMS_CLOUD_SUPPORT__
extern MMI_BOOL mmi_sms_check_cloud_processing(void);
#endif
#endif /* __SMS_APP_SETTING_H__ */ 
