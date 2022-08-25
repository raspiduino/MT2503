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
 *   JavaAgencySettings.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __JAVA_AGENCY_SETTINGS_H__
#define __JAVA_AGENCY_SETTINGS_H__

#if defined(__J2ME__) && defined(__PLUTO_MMI_PACKAGE__)

#include "MMI_features.h"
#include "wgui_inline_edit.h"
#include "MMIDataType.h"
#include "kal_general_types.h"

#define JAVA_SETTING_NETWORK_ACCESS_CAPTION              CUI_INLINE_ITEM_ID_BASE+J2ME_SETTING_NETWORK_ACCESS*2
#define JAVA_SETTING_NETWORK_ACCESS_SELECT                  JAVA_SETTING_NETWORK_ACCESS_CAPTION+1
#define JAVA_SETTING_AUTO_INVOCATION_CAPTION           CUI_INLINE_ITEM_ID_BASE+J2ME_SETTING_AUTO_INVOCATION*2
#define JAVA_SETTING_AUTO_INVOCATION_SELECT               JAVA_SETTING_AUTO_INVOCATION_CAPTION+1
#define JAVA_SETTING_MESSAGING_CAPTION                     CUI_INLINE_ITEM_ID_BASE+J2ME_SETTING_MESSAGING*2
#define JAVA_SETTING_MESSAGING_SELECT                         JAVA_SETTING_MESSAGING_CAPTION+1
#define JAVA_SETTING_MULTIMEDIA_CAPTION         CUI_INLINE_ITEM_ID_BASE+J2ME_SETTING_MULTIMEDIA*2
#define JAVA_SETTING_MULTIMEDIA_SELECT            JAVA_SETTING_MULTIMEDIA_CAPTION+1
#define JAVA_SETTING_FILE_READ_CAPTION                      CUI_INLINE_ITEM_ID_BASE+J2ME_SETTING_DATA_READ*2
#define JAVA_SETTING_FILE_READ_SELECT                          JAVA_SETTING_FILE_READ_CAPTION+1
#define JAVA_SETTING_FILE_WRITE_CAPTION          CUI_INLINE_ITEM_ID_BASE+J2ME_SETTING_DATA_WRITE*2
#define JAVA_SETTING_FILE_WRITE_SELECT                  JAVA_SETTING_FILE_WRITE_CAPTION+1
#define JAVA_SETTING_LOCAL_CONNECTIVITY_CAPTION        CUI_INLINE_ITEM_ID_BASE+J2ME_SETTING_LOCAL_CONNECTIVITY*2
#define JAVA_SETTING_LOCAL_CONNECTIVITY_SELECT                           JAVA_SETTING_LOCAL_CONNECTIVITY_CAPTION+1
#ifdef SUPPORT_JSR_179
#define JAVA_SETTING_LOVAL_LOCATION_ACCESS_CAPTION         CUI_INLINE_ITEM_ID_BASE+J2ME_SETTING_LOCATION_ACCESS*2
#define JAVA_SETTING_LOVAL_LOCATION_ACCESS_SELECT         JAVA_SETTING_LOVAL_LOCATION_ACCESS_CAPTION+1
#endif
#ifdef SUPPORT_JSR_177
#define JAVA_SETTING_SECURITY_TRUST_CAPTION         CUI_INLINE_ITEM_ID_BASE+J2ME_SETTING_SATSA*2
#define JAVA_SETTING_SECURITY_TRUST_SELECT         JAVA_SETTING_SECURITY_TRUST_CAPTION+1
#endif
#ifdef SUPPORT_JSR_257
#define JAVA_SETTING_CONTACTLESS_COMMUNICATION_CAPTION         CUI_INLINE_ITEM_ID_BASE+J2ME_SETTING_CONTACTLESS_COMMUNICATION*2
#define JAVA_SETTING_CONTACTLESS_COMMUNICATION_SELECT         JAVA_SETTING_CONTACTLESS_COMMUNICATION_CAPTION+1
#endif

#define MAX_MEMORY_SIZE 16

typedef enum
{
    MMI_JAVA_SETTING_JAVA_AUD,
    MMI_JAVA_SETTING_JAVA_BKLIGHT,        
    MMI_JAVA_SETTING_JAVA_VIB,
#ifdef SUPPORT_JAVA_NET_ICON_SETTING
/* under construction !*/
#endif
#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    MMI_JAVA_SETTING_JAVA_VK,
#endif

#ifdef JAVA_SETTING_SHOW_FREE_STORAGE
    MMI_JAVA_SETTING_JAVA_STORAGE,
#endif
    MMI_JAVA_SETTING_JAVA_HEAP,
    MMI_JAVA_SETTING_JAVA_ITEM_COUNT
} mmi_java_global_setting_inline_enum;

typedef struct
{

#define MAX_WAP_PROF_SUM 16

    UI_string_type java_aud_str[8];
    S32 java_aud_selected;

    UI_string_type java_vib_str[2];
    S32 java_vib_selected;

#ifdef SUPPORT_JAVA_NET_ICON_SETTING
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    UI_string_type java_vk_permission_str[3];
    S32 java_vk_permission_selected;
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 

#ifdef JAVA_SETTING_SHOW_FREE_STORAGE
    UI_string_type java_storage_str[1];
    S32 java_storage_selected;
    UI_character_type java_storage_strs[1][MAX_MEMORY_SIZE];
#endif

    UI_string_type java_heap_str[1];
    S32 java_heap_selected;
    UI_character_type java_heap_strs[1][MAX_MEMORY_SIZE];

    /* inline selection item */
    InlineItem inline_java_items[MMI_JAVA_SETTING_JAVA_ITEM_COUNT *2];      /* one for caption, one for selection */

    UI_string_type java_bklight_str[2];
    S32 java_bklight_selected;    
} mmi_java_global_setting_inline_data_struct;

typedef struct
{
    mmi_java_global_setting_inline_data_struct setting_inline;
    #ifdef OGDR_SECURITY_SETTING
    S32 domain_selected;
    S32 total_domain;
    U16 domains[11][30];  /* 10+1 (Reset) */
    S32 real_total_domain;
    U16 real_domains_str_id[10]; 
    S32 domain_status[10];
    #endif
} mmi_java_global_setting_and_security_cntx_struct;

typedef enum
{
    JAVA_AUDIO_CAPTION = CUI_INLINE_ITEM_ID_BASE,
    JAVA_AUDIO_SELECT,
    JAVA_BKLIGHT_CAPTION,
    JAVA_BKLIGHT_SELECT,
    JAVA_VIB_CAPTION,
    JAVA_VIB_SELECT,
    JAVA_NET_ICON_CAPTION,
    JAVA_NET_ICON_SELECT,
    JAVA_VK_CAPTION,
    JAVA_VK_SELECT,
    JAVA_NETWORK_SETTING_CAPTION,
    JAVA_NETWORK_SETTING,
    JAVA_STORAGE_CAPTION,
    JAVA_STORAGE_SIZE,
    JAVA_HEAP_SIZE_CAPTION,
    JAVA_HEAP_SIZE,
    JAVA_SETTINGS_TOTAL
} mmi_java_settings_inline_item_enum;

typedef enum
{
    MMI_JAVA_SETTING_AUD = 0,
    MMI_JAVA_SETTING_BKL,
    MMI_JAVA_SETTING_VIB,
#ifdef SUPPORT_JAVA_NET_ICON_SETTING
/* under construction !*/
#endif
#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    MMI_JAVA_SETTING_VK,
#endif
    MMI_JAVA_NW_SETTING,
#ifdef JAVA_SETTING_SHOW_FREE_STORAGE
    MMI_JAVA_SETTING_STOR,
#endif
    MMI_JAVA_HEAP,
    MMI_JAVA_SETTING_TOTAL
} mmi_java_enum_setting_item_number;

#endif /* __J2ME__ */

#endif /* __JAVA_AGENCY_SETTINGS_H__ */
