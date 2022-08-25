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
 *  EngineerModeCommUI.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Engineer mode common UI header file.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef _MMI_EM_COMM_UI_H
#define _MMI_EM_COMM_UI_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "CommonScreens.h"
#include "wgui_inline_edit.h"

#include "MenuCuiGprot.h"
#include "EngineerModeGProt.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_EM_INDEX_ICON_LIST              ((U16*)gIndexIconsImageList)
#define MMI_EM_INLINE_ICON_LIST             ((U16*)gTwoLineIndexIconsImageList)

#define MMI_EM_NUM_VALUE_MIN_THRESHOLD      (0x0)
#define MMI_EM_NUM_VALUE_MAX_THRESHOLD      (0xFFFFFFFF)
#define MMI_EM_NUM_VALUE_INVALID            (0xFFFFFFFF)

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef void (*mmi_em_num_editor_notify_func)(MMI_BOOL is_accept, U32 output_num, MMI_ID editor_gid, void* user_data);


/***************************************************************************** 
 * Enum 
 *****************************************************************************/

#define MMI_EM_NUM_EDITOR_TITLE_LEN (20)

typedef struct
{
    MMI_ID  parent_gid;  /* parent group id */
    MMI_STR_ID title_id;
    const WCHAR* text;
    void *user_data;
} mmi_em_text_viewer_struct;

typedef struct
{
    MMI_ID  parent_gid;   // The parent_gid value for user to input, if no, the default value is em root group id.
    MMI_STR_ID title_id;  // The title_id value for user to input, if no, the default value is gived by function.
    U32 min;              // The minimum value for user to input if no, please set to MMI_EM_NUM_VALUE_MIN_THRESHOLD.
    U32 max;              // The maximum value for user to input, if no, please set to MMI_EM_NUM_VALUE_MAX_THRESHOLD.
    S32 value;            // The value for user to input, if no, please set to MMI_EM_NUM_VALUE_INVALID.
    U32 input_type;
    U16 title_str[MMI_EM_NUM_EDITOR_TITLE_LEN];
    mmi_em_num_editor_notify_func notify;
    void* user_data;
} mmi_em_num_editor_struct;

/* Structure for EM main menu event*/
typedef struct {
    MMI_EVT_PARAM_HEADER
    evt_id_em_menu_list_enum menu_evt_type;
    cui_menu_event_struct    *menu_evt;
} mmi_evt_em_menu_struct;

typedef struct
{
    U16 title_id;
    U16 left_softkey;
    U16 left_softkey_icon;
    U16 right_softkey;
    U16 right_softkey_icon;
    U16 message_icon;
    U8 *message;
    WCHAR message_data[40];
    FuncPtr lsk_func;
    FuncPtr rsk_func;
    FuncPtr esk_func;
    FuncPtr enter_func;
    FuncPtr exit_func;
    MMI_ID group_id;
    MMI_ID scrn_id;
} mmi_em_progress_cntx_struct;

/* EM root group*/
extern MMI_ID mmi_em_enter_root_group(void);

extern mmi_ret mmi_em_close_root_group(void);

extern MMI_ID mmi_em_get_root_group(void);

/* EM main menu*/
extern MMI_ID mmi_em_get_main_menu(void);

/* EM main menu event handler*/
extern mmi_ret mmi_em_reg_menu_event_handler(
                   evt_id_em_menu_list_enum menu_event_id, 
                   mmi_menu_id menu_id,
                   mmi_proc_func callback);
                   
extern mmi_ret mmi_em_unreg_menu_event_handler(
                   evt_id_em_menu_list_enum menu_event_id, 
                   mmi_menu_id menu_id,
                   mmi_proc_func callback);
                   
extern void mmi_em_show_text_viewer(mmi_em_text_viewer_struct* data);

extern void mmi_em_show_num_editor(mmi_em_num_editor_struct *data);

extern void mmi_em_show_progress_scrn(mmi_em_progress_cntx_struct* cntx);

extern void mmi_em_close_progress_scrn(void);

extern void mmi_em_progress_sftkey_null_hdlr(void);
#endif /* _MMI_EM_COMM_UI_H*/
