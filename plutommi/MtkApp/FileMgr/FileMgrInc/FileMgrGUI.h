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
 *  FileManagerDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager internal prototype header.
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#if defined (__MMI_FILE_MANAGER__)

#ifndef _FMGR_GUI_H_
#define _FMGR_GUI_H_

//#ifndef _FMGR_INTERNAL_SOURCE_C_
//#error "This header is only for FileManager source!"
//#endif

#define MMI_FILE_MANAGER_DEBUG  /* FMGR Debug usage */

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "FileMgrProt.h"
#include "MMIDataType.h"
#include "FileMgrGProt.h"
#include "gui_typedef.h"
#include "FileMgrInstance.h"

/****************************************************************************
* Define
*****************************************************************************/

/********************************* Setting **********************************/

#ifndef __MMI_SLIM_FILE_MANAGER__
#define FMGR_GUI_APP_STYLE          FMGR_DISPLAY_TYPE_BANNER_LIST
#define FMGR_GUI_APP_SEL_STYLE      FMGR_DISPLAY_TYPE_BANNER_LIST
#define FMGR_GUI_APP_MS_STYLE       FMGRI_DISPLAY_TYPE_MARK_SEVERL_LIST

#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
    #ifdef __OP12__
    #define FMGR_GUI_OTHER_STYLE        FMGRI_DISPLAY_TYPE_EXPAND_LIST
    #define FMGR_GUI_OTHER_SEL_STYLE    FMGRI_DISPLAY_TYPE_EXPAND_LIST
    #define FMGR_GUI_OTHER_MS_STYLE     FMGRI_DISPLAY_TYPE_EXPAND_MS_LIST
    #else
    #define FMGR_GUI_OTHER_STYLE        FMGR_DISPLAY_TYPE_SIMPLE_LIST
    #define FMGR_GUI_OTHER_SEL_STYLE    FMGR_DISPLAY_TYPE_SIMPLE_LIST
    #define FMGR_GUI_OTHER_MS_STYLE     FMGRI_DISPLAY_TYPE_MARK_SEVERL_LIST
    #endif
#else
    #define FMGR_GUI_OTHER_STYLE        FMGR_DISPLAY_TYPE_BANNER_LIST
    #define FMGR_GUI_OTHER_SEL_STYLE    FMGR_DISPLAY_TYPE_BANNER_LIST
    #define FMGR_GUI_OTHER_MS_STYLE     FMGRI_DISPLAY_TYPE_MARK_SEVERL_LIST
#endif
#else /* __MMI_SLIM_FILE_MANAGER__ */
#define FMGR_GUI_APP_STYLE          FMGR_DISPLAY_TYPE_BANNER_LIST
#define FMGR_GUI_APP_SEL_STYLE      FMGR_DISPLAY_TYPE_BANNER_LIST
#define FMGR_GUI_APP_MS_STYLE       FMGRI_DISPLAY_TYPE_MARK_SEVERL_LIST

#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
    #ifdef __OP12__
    #define FMGR_GUI_OTHER_STYLE        FMGRI_DISPLAY_TYPE_EXPAND_LIST
    #define FMGR_GUI_OTHER_SEL_STYLE    FMGRI_DISPLAY_TYPE_EXPAND_LIST
    #define FMGR_GUI_OTHER_MS_STYLE     FMGRI_DISPLAY_TYPE_EXPAND_MS_LIST
    #else
    #define FMGR_GUI_OTHER_STYLE        FMGR_DISPLAY_TYPE_BANNER_LIST
    #define FMGR_GUI_OTHER_SEL_STYLE    FMGR_DISPLAY_TYPE_BANNER_LIST
    #define FMGR_GUI_OTHER_MS_STYLE     FMGRI_DISPLAY_TYPE_MARK_SEVERL_LIST
    #endif
#else
    #define FMGR_GUI_OTHER_STYLE        FMGR_DISPLAY_TYPE_BANNER_LIST
    #define FMGR_GUI_OTHER_SEL_STYLE    FMGR_DISPLAY_TYPE_BANNER_LIST
    #define FMGR_GUI_OTHER_MS_STYLE     FMGRI_DISPLAY_TYPE_MARK_SEVERL_LIST
#endif
#endif /* __MMI_SLIM_FILE_MANAGER__ */
/********************************** Macro **********************************/

#ifdef __FMGR_FTE_TOOLBAR_SUPPORT__
#define FMGR_FTE_TB_MAX_COUNT   3

#endif

/********************************** Enum  **********************************/

#ifdef __FMGR_FTE_TOOLBAR_SUPPORT__
typedef enum {

    FMGR_FTE_TB_UPDATE_BY_MENU_STATE = 0
    ,FMGR_FTE_TB_UPDATE_DISABLE_ALL
    
} mmi_fmgri_gui_tb_update_enum;
#endif


/********************************* Typedef ********************************/
#ifdef _FMGR_INTERNAL_SOURCE_C_

/* FMGR FS Data context structure */
typedef struct mmi_fmgr_gui_context_struct
{    
    U8 instance_id;
    U8 refresh_timer_on;
    S32 prefer_index;
    mmi_fmgr_instance_struct *instance;
#ifdef __FMGR_FTE_TOOLBAR_SUPPORT__
    U16 tb_count;
    U16 tb_menus[FMGR_FTE_TB_MAX_COUNT];
#endif
}mmi_fmgr_gui_context_struct;

/****************************************************************************
* Global variable
*****************************************************************************/
extern mmi_fmgr_gui_context_struct* fmgr_gui_p;


/****************************************************************************
* Global Function
*****************************************************************************/
extern void mmi_fmgri_gui_init(void);
extern void mmi_fmgri_gui_display_list(U8 instance_id, U32 file_count, U8 *guiBuffer);

/* Smallp added */
/* return arrow key flag, so that instance know which arrow key is used by this type 
 * Ex. Matrix style need 4-way key 
 */
extern U8   mmi_fmgri_gui_query_display_type_key(fmgr_display_type_enum type);

/* Sort_enhance */
extern void mmi_fmgri_gui_display_progress(U8 instance_id, U8 *guiBuffer);
extern void mmi_fmgri_gui_update_progress(U8 instance_id, U32 progress, U32 total);

/* Format tool api */
extern void mmi_fmgri_gui_format_size(U64 file_size, U16* buffer, S32 buffer_length);

#ifdef __FMGR_FTE_TOOLBAR_SUPPORT__
extern void mmi_fmgri_gui_toolbar_init(const U16* btn_menus, const gui_icon_bar_item_resource_struct* btn_resources, U16 btn_count);
extern void mmi_fmgri_gui_toolbar_update(mmi_fmgri_gui_tb_update_enum type);
#endif

extern void mmi_fmgri_gui_set_softkeys(mmi_fmgri_key_binding_flag sk_type, U16 string_id, U16 icon_id);

/****************************************************************************
* Local Function
*****************************************************************************/
extern void fmgr_gui_display_drv_list(S32 highlightId, U32 file_count, U8 *guiBuffer);
extern void fmgr_gui_display_file_list(S32 highlightId, U32 file_count, U8 *guiBuffer);


#endif /* _FMGR_INTERNAL_SOURCE_C_ */

#endif /* _FMGR_GUI_H_ */

#endif /* #if defined (__MMI_FILE_MANAGER__) */
