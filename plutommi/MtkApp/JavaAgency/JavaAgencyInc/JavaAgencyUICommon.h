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
 *   JavaAgencyUICommon.h
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
 ****************************************************************************/

#ifndef __JAVA_AGENCY_UI_COMMON_H__
#define __JAVA_AGENCY_UI_COMMON_H__
#ifdef __J2ME__

#include "jui_interface.h"

#define MMI_JAVA_UI_COMMON_SYMBOL_CALLBACK_MAX_NUM  2

typedef enum
{
    MMI_JAVA_UI_SCREEN_TYPE_JAVA = 0,
    MMI_JAVA_UI_SCREEN_TYPE_JAVA_MMI,
    MMI_JAVA_UI_SCREEN_TYPE_UNKNOWN,
    MMI_JAVA_UI_SCREEN_TYPE_TOTAL
}MMI_JAVA_UI_SCREEN_TYPE_ENUM;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_display_icon;
    kal_bool is_reset;
    kal_int32 vm_id;
}mmi_java_ui_common_update_status_icon_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    jui_widget_touch_feedback_enum touch_feedback_type;
    kal_int32 vm_id;
}mmi_java_ui_common_touch_feedback_play_req;

typedef kal_int32 (* mmi_java_ui_common_add_extra_symbol_callback)(
                    kal_uint8 *out,
                    kal_int32 out_max,
                    kal_uint8 **in,
                    kal_int32 in_max);
typedef kal_bool (*mmi_java_ui_common_is_need_add_extra_symbol_callback)();

extern void mmi_java_ui_common_init(void);
extern kal_int32 mmi_java_ui_common_add_extra_symbol(
                    kal_uint8 *out,
                    kal_int32 out_max,
                    kal_uint8 **in,
                    kal_int32 in_max);

extern void mmi_java_ui_common_reset_mmi_status_icon(kal_int32 vm_id);
extern void mmi_java_ui_common_update_mmi_status_icon(void *msg);
extern void mmi_java_ui_common_update_mmi_status_audio_icon(void * msg);
extern void mmi_java_ui_common_touch_feedback_play_handler(void * msg);

extern kal_bool mmi_java_ui_common_register_add_extra_symbol_callback(mmi_java_ui_common_add_extra_symbol_callback callback);
extern kal_bool mmi_java_ui_common_unregister_add_extra_symbol_callback(mmi_java_ui_common_add_extra_symbol_callback callback);
extern kal_bool mmi_java_ui_common_register_is_need_add_extra_symbol_callback(mmi_java_ui_common_is_need_add_extra_symbol_callback callback);
extern kal_bool mmi_java_ui_common_unregister_is_need_add_extra_symbol_callback(mmi_java_ui_common_is_need_add_extra_symbol_callback callback);
#endif /* __J2ME__ */

#endif /* __JAVA_AGENCY_UI_COMMON_H__ */
