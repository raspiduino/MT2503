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
 *   JavaAgencyUITextBox.h
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

#ifndef __JAVA_AGENCY_TEXTBOX_H__
#define __JAVA_AGENCY_TEXTBOX_H__

#ifdef __J2ME__

#include "MMI_include.h"
#include "jui_interface.h"

typedef struct
{
    kal_uint16 title[JUI_MAX_TITLE_LENGTH + 1];
    kal_int16 title_length;

    kal_uint16 ticker[JUI_MAX_TICKER_LENGTH + 1];
    kal_int16 ticker_length;

    kal_uint16 command_label[JUI_MAX_COMMAND_SUPPORT][JUI_MAX_COMMAND_LABLE_LENGTH+1];
    kal_int32 command_label_length[JUI_MAX_COMMAND_SUPPORT];
    kal_int32 command_id[JUI_MAX_COMMAND_SUPPORT];
    kal_int32 command_type[JUI_MAX_COMMAND_SUPPORT];
    kal_int32 command_num;

    kal_uint16 *text;
    kal_bool is_editable;
    kal_bool is_back2java;/*goto long event state or FG running state when exit textbox MAUI_03309642*/
    kal_int32 text_max_size;
    kal_int32 constraints;


    kal_int32 vm_id;

    void (*bring2Top_callback)(kal_int32 vm_id);
    void (*bring2Back_callback)(kal_int32 vm_id);

} mmi_java_ui_textbox_data_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint16 *title;
    kal_int32 title_length;
    
    kal_uint16 * ticker;
    kal_int32 ticker_length;
    
    kal_uint16 ** command_label;
    kal_int32 * command_label_lenght;
    kal_int32 * command_id;
    kal_int32 * command_type;
    kal_int32 command_num;

    kal_bool is_editable;
    
    kal_uint16 *  buffer;
    kal_uint16 *  text_buffer;
    kal_int32 text_length;
    kal_int32 max_size;
    
    kal_int32 constraints;

    kal_int32 vm_id;
    
    void (*callback)(kal_int32 vm_id);
    void (*bring2Top_callback)(kal_int32 vm_id);
    void (*bring2Back_callback)(kal_int32 vm_id);
}mmi_java_ui_textbox_show_req_struct;

 enum
{
    JAVA_UI_TEXTBOX_TITLE = 0,
    JAVA_UI_TEXTBOX_TICKER = 1,
    JAVA_UI_TEXTBOX_COMMAND = 2,
    JAVA_UI_TEXTBOX_TEXT = 3
};

extern void mmi_java_ui_textbox_init(void);

extern void mmi_java_ui_textbox_show_req(void * msg);
extern void mmi_java_ui_textbox_hide_req(void * msg);
extern void mmi_java_ui_textbox_update_title_req(void * msg);
extern void mmi_java_ui_textbox_update_ticker_req(void * msg);
extern void mmi_java_ui_textbox_update_text_req(void * msg);
extern void mmi_java_ui_textbox_update_command_req(void * msg);
extern void mmi_java_ui_textbox_bring_2_top_req(void * msg);
extern void mmi_java_ui_textbox_option_menu_hide_req(void * msg);
extern kal_bool mmi_java_ui_textbox_is_visible(kal_int32 vm_id);
extern kal_uint16 mmi_java_ui_textbox_get_screen_type();
extern void mmi_java_ui_textbox_set_screen_type(kal_uint16 type);
extern void mmi_java_ui_textbox_delete_phb_cui(void);
extern mmi_ret mmi_java_ui_textbox_set_number(mmi_event_struct *evt);
extern mmi_ret mmi_java_ui_textbox_set_number_prepare_proc(mmi_frm_asm_evt_struct *evt);


#endif /* __J2ME__ */

#endif /* __JAVA_AGENCY_TEXTBOX_H__ */

