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
 * DCDV30Gprot.h
 *
 * Project:
 * --------
 * MAUI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _DCD_V30_GPROT_H
#define _DCD_V30_GPROT_H
     
#include "MMI_features.h"
#ifdef __MMI_OP01_DCD_V30__

#include "dcdagentdefine.h"
#include "MMIDatatype.h"
#include "kal_non_specific_general_types.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
#define DCD_GET_HOST_REQ_ID                     (0x0c0ccdcd)

#if defined (__MMI_MAINLCD_240X320__)
#define MAX_DCD_BACKGROUND_ITEM_NUM_PER_PAGE    6
#define MAX_DCD_CITY_ITEM_NUM_PER_PAGE          9
#elif defined (__MMI_MAINLCD_240X400__)
#define MAX_DCD_BACKGROUND_ITEM_NUM_PER_PAGE    6
#define MAX_DCD_CITY_ITEM_NUM_PER_PAGE          9
#elif defined(__MMI_MAINLCD_320X480__)
#define MAX_DCD_BACKGROUND_ITEM_NUM_PER_PAGE    6
#define MAX_DCD_CITY_ITEM_NUM_PER_PAGE          9
#endif

/*****************************************************************************
 * Enum
 *****************************************************************************/
typedef enum
{
    DCD_IDLE_SCROLL_MEDIUM_SPEED,
    DCD_IDLE_SCROLL_SLOW_SPEED,
    DCD_IDLE_SCROLL_FAST_SPEED,
    DCD_IDLE_SCROLL_SPEED_TOTAL
} dcd_idle_scroll_speed_enum;


/*****************************************************************************
 * Extern func
 *****************************************************************************/
/* from srv */
extern mmi_ret mmi_dcd_initialize(mmi_event_struct *event);
extern void mmi_dcd_finalize(void);
extern HDCD_Agent mmi_dcd_get_agent_handle(void);
extern MMI_BOOL mmi_dcd_is_switch_on(void);
extern MMI_BOOL mmi_dcd_is_main_syncing(void);
extern kal_uint32 mmi_dcd_get_acct_id(void);
extern void mmi_dcd_receive_da_file(
                S32 session_id,
                S32 mime_type,
                S32 mime_subtype,
                S32 action,
                PU16 filepath,
                PS8 url,
                PS8 mime_type_string);
extern SDK_RESULT mmi_dcd_app_message_proc(EDCD_MSG_CODE a_eMsgCode, BRVOID *a_pUserData, BRLONG a_nParam1, BRLONG a_nParam2);

/* from app */
extern void mmi_dcd_entry_channal_list_external(void);
extern void mmi_dcd_entry_channel_home_page(void);
extern void mmi_dcd_entry_city_search_edit(CHAR * string,CHAR * label);
extern void *mmi_dcd_get_agent_handle_ext(void);
extern S32 mmi_dcd_get_channel_count_ext(void* agent_handle);
extern void *mmi_dcd_get_current_channel_handle_ext(void* agent_handle);
extern WCHAR* mmi_dcd_get_channel_title_ext(void* channel_handle);
extern S32 mmi_dcd_get_channel_block_count_ext(void* channel_handle);
extern void * mmi_dcd_get_channel_block_handle_ext(void * channel_handle, S32 block_index);
extern S32 mmi_dcd_get_block_entry_count_ext(void* block_handle);
extern void * mmi_dcd_get_block_entry_handle_ext(void* block_handle, S32 entry_index);
extern WCHAR* mmi_dcd_get_entry_title(void* entry_handle);
extern S32 mmi_dcd_get_current_idle_channel_index(void);
extern void mmi_dcd_set_current_idle_channel_index(S32 current_index);
extern void mmi_dcd_entry_channel_detail_from_idle(void);
extern void mmi_dcd_entry_weather_channel_from_idle(void);
extern MMI_BOOL mmi_dcd_is_weather_channel(void * channel_handle);
extern void* mmi_dcd_get_weather_channel_ext(void * agent_handle);
extern void *mmi_dcd_get_default_city_ext(void * agent_handle,void * weather_channel_handle);
extern WCHAR *mmi_dcd_get_city_name_ext(void* city_handle);
extern WCHAR *mmi_dcd_get_city_temperature_ext(void* city_handle);
extern WCHAR* mmi_dcd_get_city_weather_image_ext(void* city_handle);
extern void mmi_dcd_city_weather_image_free_ext(void);
extern void mmi_dcd_set_news_image_ext(void* channel_handle);
extern WCHAR* mmi_dcd_get_news_image_ext();
extern void mmi_dcd_news_image_free_ext(void);
extern dcd_idle_scroll_speed_enum mmi_dcd_get_scroll_speed_ext(void);
extern void mmi_dcd_get_channel_list_status(S32 * channel_count, MMI_BOOL *preset_only);
extern MMI_BOOL mmi_dcd_is_switch_on_ext(void);
extern WCHAR* mmi_dcd_get_preset_summary_ext(void* agent_handle);
extern void mmi_dcd_preset_summary_free_ext(void);
#endif /* __MMI_OP01_DCD_V30__ */
#endif /* _DCD_V30_GPROT_H */

