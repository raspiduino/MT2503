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
*  AMMainScreen.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  AM Main Screen file.
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef AM_MAINSCREEN_H
#define AM_MAINSCREEN_H

#include "MMIDataType.h"
#include "gui_switch.h"
#include "gui_windows.h"
#include "AMDef.h"
#include "AMConfig.h"
#include "liblist.h"
#include "MREAppMgrSrvGprot.h"

#define MMI_AM_MS_SCROLL_TIME CFG_UI_TEXT_MENUITEM_SCROLL_TIME
#define MMI_AM_MS_TEXT_SCROLL_SIZE CFG_UI_TEXT_MENUITEM_SCROLL_SIZE
#define MMI_AM_MS_TEXT_SCROLL_GAP CFG_UI_TEXT_MENUITEM_SCROLL_GAP
#define MMI_AM_MS_TEXT_SCROLL_PAUSE CFG_UI_TEXT_MENUITEM_SCROLL_PAUSE

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* Structure to store main screen information */
typedef struct
{
    mmi_am_config_ms_struct *cfg;   /* am config */
    S32 page_start_idx;             /* page start index */
    S32 page_end_idx;               /* page endindex */
    mre_list_t *app_list;           /* current page apps - mmi_am_ms_app_struct */

    U16 sc_app_num;     /* number of Shortcut App on the current screen */
    U16 rom_app_num;    /* number of Rom App on the current screen */
    U16 vxp_app_num;

    MMI_BOOL is_able_to_download;
    scrolling_text scrolling_app_name;

    /* highlight info */
    S32 hl_idx; /* highlighted index */
    S32 hl_x1;
    S32 hl_x2;
    S32 hl_y1;
    S32 hl_y2;

    /* ZiMo scroll info */
    S32 scroll_x;   /* starting position of the string */
    S32 scroll_zone_x1;
    S32 scroll_zone_y1;
    S32 scroll_zone_x2;
    S32 scroll_zone_y2;
    S32 scroll_counter;
} mmi_am_ms_struct;

/* AM Main Screen App Display struct */
typedef struct
{
    S32 idx;                    /* display index in Category214 (start from 0) */
    MMI_BOOL is_hs_shortcut;    /* is the app set as home screen shortcut */
    MMI_BOOL is_bg_started;     /* is the app background start */

    U8 *p_icon;                         /* app icon pointer (gif) */
    U32 icon_size;
    U8 *p_name;                         /* app name pointer */
    U32 name_size;
    U32 name_len;                       /* app name length */
    // U16 path[MMI_AM_MAX_APP_FILE_PATH]; /* app full path */
    U16 path[SRV_MRE_APPMGR_FILEPATH_LEN];
    //U8   app_identification[MMI_APP_NAME_MAX_LEN+1];
    U32 app_unique_id;
} mmi_am_ms_app_struct;

/****************************************************************************
* Extern Global Function                                                            
*****************************************************************************/
/* build app list for display on Main Screen */
extern MMI_BOOL mmi_am_ms_build_app_list(void);

extern void mmi_am_ms_init(void);
extern void mmi_am_entry_main_scrn(void);
extern void mmi_am_ms_release_app_list(void);
extern void mmi_am_ms_release_app_list_all_nodes(void);
extern void mmi_am_ms_release_app_list_nodes_in_memory_card(void);
extern MMI_BOOL mmi_am_ms_is_app_download(S32 idx);
extern MMI_BOOL mmi_am_ms_is_app_bg_running(S32 idx);
extern MMI_BOOL mmi_am_ms_is_rom_app(S32 idx);

#ifdef MMI_AM_SHORTCUT_ENABLE
extern MMI_BOOL mmi_am_ms_is_app_set_hs_shortcut(S32 idx);
#endif 
extern U16 *mmi_am_ms_get_app_path_by_index(S32 idx);
extern U8 *mmi_am_ms_get_app_icon_by_index(S32 idx, U32 *icon_size);
extern void mmi_am_ms_delete_node_from_applist_by_index(S32 idx);
extern void mmi_am_ms_scrolling_text_stop(void);
extern void mmi_am_ms_set_app_download(S32 idx, S8 driver);
extern void mmi_am_ms_set_app_hs_shortcut(S32 idx);
extern void mmi_am_ms_set_app_bg_running(S32 idx, MMI_BOOL is_bg_running);
extern void mmi_am_ms_app_status_update(S32 idx);
extern void mmi_am_ms_remove_app_hs_shortcut(S32 idx);
extern void mmi_am_ms_shortcut_app_download_suc(S32 appid, U16 *app_path);

#endif /* AM_MAINSCREEN_H */ 

