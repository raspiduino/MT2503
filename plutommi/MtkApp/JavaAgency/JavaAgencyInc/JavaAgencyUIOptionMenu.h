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
 *   JavaAgencyUIOptionMenu.h
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

#ifndef __JAVA_AGENCY_OPTION_MENU_H__
#define __JAVA_AGENCY_OPTION_MENU_H__

#ifdef __J2ME__ 

#include "mmi_include.h"
#include "jui_interface.h"

typedef enum
{
    J2ME_OPTION_MENU_TYPE_JAVA,
    J2ME_OPTION_MENU_TYPE_TEXTBOX,
    J2ME_OPTION_MENU_TYPE_END
} mmi_java_ui_option_menu_type_enum;

typedef struct
{
    kal_uint16 title[JUI_MAX_TITLE_LENGTH + 1];
    kal_int32 title_length;
    kal_uint16 *command_label[JUI_MAX_COMMAND_SUPPORT];
    kal_int32 command_label_length[JUI_MAX_COMMAND_SUPPORT];
    kal_int32 command_id[JUI_MAX_COMMAND_SUPPORT];
    kal_int32 command_num;

    void (* screen_disppear_callback)(kal_int32 vm_id);
    kal_int16 selected_index;
    kal_bool submitted; /*MAUI_03309642*/

    kal_uint8 ** icons;

    kal_int32 vm_id;

} mmi_java_ui_option_menu_data_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint16 *title;
    kal_int32 title_length;
    kal_uint16 **command_label;
    kal_int32 * command_label_length;
    kal_int32 * command_id;
    kal_int32 command_num;
    kal_int32 vm_id;
    void (*callback)(kal_int32 vm_id);

    void (*screen_disppear_callback)(kal_int32 vm_id);
}mmi_java_ui_option_menu_show_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint16 *title;
    kal_int32 title_length;
    kal_uint16 **command_label;
    kal_int32 * command_label_length;
    kal_int32 * command_id;
    kal_int32 command_num;
    kal_int32 vm_id;
    void (*callback)(kal_int32 vm_id);

    void (*screen_disppear_callback)(kal_int32 vm_id);
}mmi_java_ui_popup_show_req_struct;


extern void mmi_java_ui_option_menu_init(void);
extern void mmi_java_ui_option_menu_show_req(void *msg_struct);
extern void mmi_java_ui_option_menu_hide_req(void *msg_struct);
#ifdef __USE_JUI_POPUP__
extern void mmi_java_ui_popup_show_req(void *msg_struct);
extern void mmi_java_ui_popup_hide_req(void *msg_struct);
#endif

#ifdef __COSMOS_MMI_PACKAGE__
extern void vapp_java_ui_option_menu_exit_screen(void);
#endif


#endif /* __J2ME__ */

#endif /* __JAVA_AGENCY_OPTION_MENU_H__ */

