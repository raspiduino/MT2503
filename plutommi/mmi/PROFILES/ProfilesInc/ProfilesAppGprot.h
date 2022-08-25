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
*  ProfilesAppGprot.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   ProfilesAppGprot.
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef PROFILES_APP_GPROT_H
#define PROFILES_APP_GPROT_H

#include "kal_general_types.h"
#include "MMIDataType.h"

/* Basic menu style profiles UI support */
#if defined(__MMI_BASIC_UI_STYLE__) || defined(__INLINE_CUI_SLIM_SELECT_ITEM_STYLE__)
    #define __MMI_PROF_BASIC_UI_STYLE__
#endif

/* the enum value should be same with srv_prof_internal_profile_enum */
typedef enum
{
#ifndef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
    MMI_PROFILE_NULL,       // SRV_PROF_PROFILE_NULL
#else
    MMI_PROFILE_ADD_NEW_PROF, //SRV_PROF_PROFILE_ADD
#endif
    MMI_PROFILE_GENERAL,    // SRV_PROF_PROFILE_1,
    MMI_PROFILE_SILENT,     // SRV_PROF_PROFILE_2,
    MMI_PROFILE_MEETING,    // SRV_PROF_PROFILE_3,
    MMI_PROFILE_OUTDOOR,    // SRV_PROF_PROFILE_4,
#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    MMI_PROFILE_MY_STYLE,   // SRV_PROF_PROFILE_5,
#elif defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    MMI_PROFILE_NEW_1,
    MMI_PROFILE_NEW_2,
    MMI_PROFILE_NEW_3,
    MMI_PROFILE_NEW_4,
    MMI_PROFILE_NEW_5,
    MMI_PROFILE_NEW_6,
    MMI_PROFILE_NEW_7,
    MMI_PROFILE_NEW_8,
    MMI_PROFILE_NEW_9,
    MMI_PROFILE_NEW_10,
#endif
    
    MMI_PROF_PROF_ID_BEGIN  = MMI_PROFILE_GENERAL,
#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    MMI_PROF_PROF_ID_END    = MMI_PROFILE_MY_STYLE,
#elif defined(__MMI_PROF_BASIC_UI_STYLE__)
    MMI_PROF_PROF_ID_END    = MMI_PROFILE_OUTDOOR,
#elif defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    MMI_PROF_PROF_ID_END    = MMI_PROFILE_NEW_10,   //MMI_PROFILE_MY_STYLE,
#endif
    MMI_PROF_PROF_ID_NUM    = MMI_PROF_PROF_ID_END - MMI_PROF_PROF_ID_BEGIN + 1
}mmi_prof_id_enum;


extern void mmi_profiles_entry_main_screen(void);

extern mmi_ret mmi_prof_app_init(mmi_event_struct *evt);

extern WCHAR * mmi_prof_get_profile_name(mmi_prof_id_enum profile_id);

extern MMI_BOOL mmi_prof_activate_profile(mmi_prof_id_enum profile_id, MMI_BOOL need_popup);

extern MMI_BOOL mmi_prof_deactivate_silent_profile(MMI_BOOL need_popup);

#ifdef __MMI_APP_MANAGER_SUPPORT__
extern MMI_ID mmi_profiles_launch_function(void *param, U32 param_size);
#endif

#ifdef __GAIN_TABLE_SUPPORT__
extern U16 mmi_prof_get_current_set_item(void);

typedef enum
{
    MMI_PROF_TYPE_RING,             
    MMI_PROF_TYPE_VIDEO_CALL,
    MMI_PROF_TYPE_POWER_ON,
    MMI_PROF_TYPE_POWER_OFF,
    MMI_PROF_TYPE_COVER_OPEN,
    MMI_PROF_TYPE_COVER_CLOSE,      
    MMI_PROF_TYPE_MESSAGE,
    MMI_PROF_TYPE_MMS,
    MMI_PROF_TYPE_SMS,
    MMI_PROF_TYPE_EMAIL,            
    MMI_PROF_TYPE_OTHERS,
    
    MMI_PROF_TYPE_MAX
} MMI_PROF_TONE_SETTING_TYPE;
#endif

extern U8 mmi_prof_get_profiles_enum_list_for_shell(U8* enum_ptr, U8 length);

#endif /*PROFILES_APP_GPROT_H*/
