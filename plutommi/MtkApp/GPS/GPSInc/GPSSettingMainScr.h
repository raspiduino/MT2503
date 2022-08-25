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
 * GPSSetting.h
 *
 * Project:
 * --------
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __GPSSETTINGMAINSCR_H__
#define __GPSSETTINGMAINSCR_H__

#include "nvram_common_defs.h"
#include "InlineCuiGprot.h"
#include "MMIDataType.h"
#include "common_nvram_editor_data_item.h"
#include "DataAccountGProt.h"
#include "DtcntSrvGprot.h"
#include "ImeGprot.h"
#include "gui_virtual_keyboard_language_type.h"
#include "kal_general_types.h"
#include "GPSSetting.h"

#if defined(__GPS_SUPPORT__)

#define MMI_GPS_BT_MAX_NAME_LEN     32
#define MMI_GPS_BT_MAX_PORT_NUM     20
#define MMI_GPS_MAX_PORT_BUFFER_LEN 6

#if defined(__GPS_SUPPORT__) && defined(__BT_GPS_SUPPORT__)
/* under construction !*/
#else
#define MMI_GPS_SELECT_ITEM_MAX     2
#endif

#define MMI_GPS_SIM_CARD_NUMBER     (NVRAM_EF_GPS_MMI_SIM_DATA_TOTAL)

typedef enum
{
    MMI_GPS_SETTING_INLINE_GPS_CAPTION =(CUI_INLINE_ITEM_ID_BASE + 0),
    MMI_GPS_SETTING_INLINE_GPS_SELECT,
    MMI_GPS_SETTING_INLINE_PROFILE_CAPTION,
    MMI_GPS_SETTING_INLINE_PROFILE_SELECT,
    MMI_GPS_SETTING_INLINE_TIME_SYNC_CAPTION,
    MMI_GPS_SETTING_INLINE_TIME_SYNC_SELECT,
    MMI_GPS_SETTING_INLINE_EM_ENTRY_CAPTION,
    MMI_GPS_SETTING_INLINE_EM_ENTRY_DISP,

    MMI_GPS_SETTING_INLINE_PREFER_SIM_CAPTION,
    MMI_GPS_SETTING_INLINE_PREFER_SIM_SELECT,
    MMI_GPS_SETTING_INLINE_SIM1_CAPTION,
    MMI_GPS_SETTING_INLINE_SIM1_DISP,
    MMI_GPS_SETTING_INLINE_SIM2_CAPTION,
    MMI_GPS_SETTING_INLINE_SIM2_DISP,
    MMI_GPS_SETTING_INLINE_SIM3_CAPTION,
    MMI_GPS_SETTING_INLINE_SIM3_DISP,
    MMI_GPS_SETTING_INLINE_SIM4_CAPTION,
    MMI_GPS_SETTING_INLINE_SIM4_DISP,
    MMI_GPS_SETTING_INLINE_SIM5_CAPTION,
    MMI_GPS_SETTING_INLINE_SIM5_DISP,

    MMI_GPS_EDIT_PROFILE_INLINE_GPS_CAPTION,
    MMI_GPS_EDIT_PROFILE_INLINE_GPS_TEXT,
    MMI_GPS_EDIT_PROFILE_INLINE_ADDR_CAPTION,
    MMI_GPS_EDIT_PROFILE_INLINE_ADDR_TEXT,
    MMI_GPS_EDIT_PROFILE_INLINE_DA_CAPTION,
    MMI_GPS_EDIT_PROFILE_INLINE_DA_SELECT,
    MMI_GPS_EDIT_PROFILE_INLINE_PORT_CAPTION,
    MMI_GPS_EDIT_PROFILE_INLINE_PORT_TEXT,

    MMI_GPS_SETTING_AGPS_INLINE_AGPS_CAPTION,
    MMI_GPS_SETTING_AGPS_INLINE_AGPS_SELECT,
    MMI_GPS_SETTING_AGPS_INLINE_PROFILE_CAPTION,
    MMI_GPS_SETTING_AGPS_INLINE_PROFILE_DISP,
    MMI_GPS_SETTING_AGPS_INLINE_SEND_LOC_CAPTION,
    MMI_GPS_SETTING_AGPS_INLINE_SEND_LOC_SELECT,
    MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_CAPTION,
    MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_SELECT,

    MMI_GPS_EDIT_PROFILE_INLINE_TEMP,
    MMI_GPS_SETTING_INLINE_CUI_BASE_END
}mmi_gps_setting_inline_cui_base_enum;

typedef struct
{
    U8                      dumy1;               /*4 bytes align    1 bytes*/
    U16                     device_name[MMI_GPS_BT_MAX_NAME_LEN];      /*BT device name   64 bytes*/
    U8                      port;               /*UART port numbe    1 byter*/
    U8                      receiver;           /*user setting of if use receiver 1 byte*/
                                                        /*86 bytes inall*/
    U8                      dumyend[92 - 86];    /*dumy data for develop*/
} mmi_gps_setting_nvram_struct;


#if defined(__MMI_SPP_SUPPORT__) && defined(__BT_GPS_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct
{
    mmi_id cur_gid;
    mmi_id inline_gid;
    mmi_id inline_agps_setting_gid;
    mmi_id inline_profile_gid;
    mmi_id menu_agps_profile_gid;
    mmi_gps_nvram_settings_struct settings;
    mmi_gps_setting_nvram_struct nvram;
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    mmi_gps_nvram_single_sim_settings_struct *current_sim_p;
    U8 agps_setting_nvram;
    U8* agps_selected_p[3];
    S32 agps_selected_item;
    U8 buffer[MMI_GPS_SIM_CARD_NUMBER][1024];
#endif
#if defined(__AGPS_USER_PLANE__)
    U8 cur_profile;
    nvram_ef_agps_profile_struct agps_profile[NVRAM_EF_AGPS_PROFILE_TOTAL];
    nvram_ef_agps_profile_struct agps_profile_temp;
    U32 data_account_temp;
    U8 agps_profile_port_buffer[MMI_GPS_MAX_PORT_BUFFER_LEN * 2];
    U8 data_account_name[(MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH];
    U16 title_str_id;
    mmi_imm_input_mode_enum *input_mode_list_p;
#if 0
/* under construction !*/
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
/* under construction !*/
#endif
#endif
    U32 input_type;
    S32 buffer_size;
    U8 cur_edit_index;
    U8 app_id;
#endif
    S32 uart_port;
    S32 gps_selected_item;
    MMI_BOOL    is_modified;           /*user setting of if use reveiver*/
    MMI_BOOL    is_profile_modified;           /*user setting of if use reveiver*/
    MMI_BOOL is_uart_inited;
    U8* gps_selected_p[MMI_GPS_SELECT_ITEM_MAX];
#if defined(__MMI_SPP_SUPPORT__) && defined(__BT_GPS_SUPPORT__)
/* under construction !*/
#endif
    U8 time_sync_nvram;
    U8 em_mode_setting;
    U8* time_sync_selected_p[2];
    S32 time_sync_selected_item;
    U8 curr_sim;
}mmi_gps_setting_context_struct;

#if defined(__MMI_SPP_SUPPORT__) && defined(__BT_GPS_SUPPORT__)
/* under construction !*/
#endif

#endif //#if defined(__GPS_SUPPORT__)

#endif /* __GPSSETTINGMAINSCR_H__ */


