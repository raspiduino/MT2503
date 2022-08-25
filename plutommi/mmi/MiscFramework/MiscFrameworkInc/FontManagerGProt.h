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
 * FontManagerGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
 *
 * Author:
 * -------
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
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
 *============================================================================
 ****************************************************************************/
#ifndef __FONT_MANAGER_GPROT_H__
#define __FONT_MANAGER_GPROT_H__

#include "FileMgrGProt.h"
#include "MenuCuiGprot.h"

    #include "gui_data_types.h"
    #include "fs_type.h"
    
/*****************************************************************************
 * Definitions
 *****************************************************************************/
#define MMI_FONT_MGR_MAX_HINT_NUM 10

/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef enum
{
	MMI_FONT_MGR_SUCCESS,
	MMI_FONT_MGR_FAIL,
	MMI_FONT_MGR_ERROR,
	MMI_FONT_MGR_TOTAL
} mmi_font_mgr_event_type_enum;

/* Global data for font resource on memory card */
typedef struct
{
    UI_character_type name[256];
    FS_HANDLE handle;
    UI_character_type fontName[64];
    FS_FileLocationHint hint[MMI_FONT_MGR_MAX_HINT_NUM];
} mmi_font_mgr_font_file_resource_struct;


#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)

/* event for EVT_ID_GUI_INPUTS_CURSOR_CHANGED */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    U32 error_msg;    
} mmi_font_mgr_err_evt_struct;


typedef union
{
	FS_DOSDateTime date_time;
	U32 last_modified;
}mmi_font_mgr_last_modified_date_union;


extern MMI_BOOL mmi_font_mgr_init(void);
extern void mmi_font_mgr_highlight_setting_handler(void);

extern void mmi_font_mgr_option_install_handler(void);
extern void mmi_font_mgr_option_uninstall_handler(void);
extern void mmi_font_mgr_get_font_info(mmi_font_mgr_font_file_resource_struct** font, S32* num, S16** priority_list);
extern MMI_BOOL mmi_font_mgr_drv_remove_hdlr(S8* drv_letter);
extern MMI_BOOL mmi_font_mgr_error_handler(U32 err);
extern mmi_ret mmi_font_mgr_menu_handler(cui_menu_event_struct *evt, mmi_id parent_gid);

/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_option_handler
 * DESCRIPTION
 *  options handler
 * PARAMETERS
 *  item_id       : [IN]       menu item id
 *  filepath      : [IN]       file path
 *  fileinfo      : [IN]       file information
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_font_mgr_option_handler(mmi_menu_id item_id, const WCHAR* filepath, 
                     const srv_fmgr_fileinfo_struct* fileinfo);

extern mmi_ret mmi_fmgr_font_mgr_notify_hdlr(mmi_event_struct* evt);

extern void mmi_font_mgr_show_popup(WCHAR* str, mmi_font_mgr_event_type_enum evt);
extern void mmi_font_mgr_font_list_option_priority_change_handler(void);
extern mmi_ret mmi_font_mgr_usb_ms_plug_in_hdlr(mmi_event_struct *para);
extern mmi_ret mmi_font_mgr_usb_ms_plug_out_hdlr(mmi_event_struct *para);

#ifdef __COSMOS_MMI_PACKAGE__

extern void mmi_font_mgr_get_font_list(U32 index, U8 **fontNamePtrs);
extern U32 mmi_font_mgr_get_font_options_count(void);
extern MMI_BOOL mmi_font_mgr_is_system_font(void);
extern void mmi_font_mgr_get_font_options_list(U32 index, U8 **fontOptionsPtrs);
extern void mmi_font_set_selected_font(U32 index);
extern U32 mmi_font_mgr_get_font_num(void);
extern MMI_BOOL mmi_font_mgr_install_new_font(S8* file_name);
extern void mmi_font_mgr_uninstall_font(void);
extern void mmi_font_mgr_activate_font(void);
extern void mmi_font_mgr_activate_cancel(void);
extern void mmi_font_mgr_activate_exit(void);
extern U8 mmi_font_get_selected_font_priority(void);
extern MMI_BOOL mmi_font_set_selected_font_priority(U8 priority);
extern MMI_BOOL mmi_font_mgr_uninstall_font_ms_mode(void);


#else

mmi_ret mmi_font_mgr_setting_proc(mmi_event_struct *param);

#endif

#endif

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
extern MMI_BOOL mmi_font_mgr_open_font(U16 id, S32 *size);
extern void* mmi_font_mgr_get_font_file_handle(U16 resid);
#endif


#endif
 
