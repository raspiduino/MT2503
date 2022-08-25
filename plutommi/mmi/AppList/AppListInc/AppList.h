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
 *  AppList.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AppList Applications v0.1
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _MMI_APPLIST_H_
#define _MMI_APPLIST_H_

#include "mmi_features.h"

#ifdef __MMI_LAUNCHER_APP_LIST__

#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "AppMgrSrvGprot.h"
#include "IdleMemCfg.h"
#include "AppListDef.h"
#include "AppListVLW.h"
#include "AppListDraw.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_APPLIST_INVALID_INDEX (-1) 
#define MMI_APPLIST_CACHE_INDEX (0x7FFFFFFF) 

#define APPLIST_ABS(a)  ((a) < 0 ? -(a) : (a))

#define __RANFOW_DEBUG__
#ifdef __RANFOW_DEBUG__
#ifndef __MTK_TARGET__
#define RANFOW_TRACE(format, ...) printf((format), ##__VA_ARGS__)
#else
#define RANFOW_TRACE(...) kal_prompt_trace(MOD_IDLE, __VA_ARGS__)
#endif
#else
#define RANFOW_TRACE(format, ...)
#endif

/***************************************************************************** 
 * Enum
 *****************************************************************************/
typedef enum
{
    MMI_APPLIST_AREA_TYPE_INVALID,
    MMI_APPLIST_AREA_TYPE_SLIDE,
    MMI_APPLIST_AREA_TYPE_INDICATOR_BAR,
    MMI_APPLIST_AREA_TYPE_SHORTCUT_BAR
}mmi_applist_area_type_enum;

typedef enum
{
    MMI_APPLIST_CELL_TYPE_PANEL,
    MMI_APPLIST_CELL_TYPE_SHORTCUT
}mmi_applist_cell_type_enum;

typedef enum
{
    MMI_APPLIST_CELL_STATE_UNSELECTED,
    MMI_APPLIST_CELL_STATE_TOUCHED,
    MMI_APPLIST_CELL_STATE_SELECTED
}mmi_applist_cell_state_enum;

typedef enum
{
    MMI_APPLIST_INDICATOR_STATE_DISABLE,
    MMI_APPLIST_INDICATOR_STATE_INACTIVE,
    MMI_APPLIST_INDICATOR_STATE_ACTIVE
}mmi_applist_indicator_state_enum;

typedef enum
{
    MMI_APPLIST_SLIDE_STATE_DISABLE,
    MMI_APPLIST_SLIDE_STATE_ENABLE,    
    MMI_APPLIST_SLIDE_STATE_ENABLE_EXPENDED,
    MMI_APPLIST_SLIDE_STATE_DISABLE_EXPENDED
}mmi_applist_slide_state_enum;

typedef enum
{
    MMI_APPLIST_MODE_NORMAL,
    MMI_APPLIST_MODE_EDIT,
#ifdef __MMI_APPLIST_BARREL_SUPPORT__
    MMI_APPLIST_MODE_EFFECT_PREVIEW,
#endif
    MMI_APPLIST_MODE_POPUP
}mmi_applist_mode_enum;

typedef enum
{
    MMI_APPLIST_MATRIX_TYPE_MOVE,
    MMI_APPLIST_MATRIX_TYPE_SCALE,
    MMI_APPLIST_MATRIX_TYPE_ROTATE
}mmi_applist_matrix_type_enum;

/* Assume cache three page */
typedef enum
{
    MMI_APPLIST_CACHE_TYPE_THIS,
    MMI_APPLIST_CACHE_TYPE_NEARBY,
    MMI_APPLIST_CACHE_TYPE_PREVIOUS,
    MMI_APPLIST_CACHE_TYPE_NEXT
}mmi_applist_cache_type_enum;

typedef enum
{
    MMI_APPLIST_WP_STATE_CLOSED,
    MMI_APPLIST_WP_STATE_OPENED,
    MMI_APPLIST_WP_STATE_PLAYING,    
}mmi_applist_wallpaper_state_enum;

typedef enum
{    
    MMI_APPLIST_WP_STOP_TYPE_NONE,
    MMI_APPLIST_WP_STOP_TYPE_EDIT_MODE  = (1<<0),
    MMI_APPLIST_WP_STOP_TYPE_PEN_DOWN   = (1<<1),
    MMI_APPLIST_WP_STOP_TYPE_SLIDE_BY_KEY = (1<<2) 
}mmi_applist_wp_stop_type_enum;

typedef enum
{
    MMI_APPLIST_SLIDE_BY_PEN,
    MMI_APPLIST_SLIDE_BY_KEY
} mmi_applist_slide_type_enum;

typedef enum
{
    MMI_APPLIST_STATE_NONE,         //launcher is not active
    MMI_APPLIST_STATE_FIRST_ENTER,  //first enter launcher
    MMI_APPLIST_STATE_ENTER,        //enter launcher
    MMI_APPLIST_STATE_NORMAL,       //launcher is normal running
    MMI_APPLIST_STATE_RESET,        //exit from edit mode
    MMI_APPLIST_STATE_AUTOSLIDE,    //launcher auto slide by pen moving in edit mode
    MMI_APPLIST_STATE_CYCLIC,       //launcher cyclic by key
    MMI_APPLIST_STATE_SLIDING,      //sliding
} mmi_applist_state_enum;

/***************************************************************************** 
 * Structure
 *****************************************************************************/

typedef struct
{
    MMI_EVT_PARAM_HEADER
    U32 app_id;
} mmi_applist_launch_event_struct;

typedef struct
{
    U8 buffer[MMI_APPLIST_APP_CACHE_SIZE];
}mmi_applist_cache_struct;

typedef struct
{
    mmi_applist_area_type_enum type;
    S32 index;
} mmi_applist_hit_area_struct;

typedef struct
{
    mmi_applist_cell_state_enum state;
    mmi_applist_cell_type_enum type;
    S32 index;    
    mmi_applist_position pen_shift;
    
    mmi_applist_cell_struct *cell_p;
} mmi_applist_focus_cell_struct;

#ifdef __MMI_APPLIST_KEY_SUPPORT__
typedef struct
{
    gdi_handle hilight_handle;
    mmi_applist_cell_type_enum type;
    S32 index; 
    mmi_applist_cell_type_enum pre_type;
    S32 pre_index;

    mmi_applist_cell_struct *cell_p;
    #ifndef __MMI_APPLIST_ONLY_ICON_SUPPORT__
    U32 scroll_x;
    #endif
}mmi_applist_hilight_frame_info_struct;

#endif /* __MMI_APPLIST_KEY_SUPPORT__ */

/* when moving cell in edit mode, if the page we move to is full, the last cell will be cached */
typedef struct
{    
    mmi_applist_cell_struct *cell_p;
    S32 page_idx;
}mmi_applist_cache_cell_struct;

typedef struct
{    
    mmi_applist_indicator_state_enum state;
    mmi_applist_position pos;    
}mmi_applist_page_indicator_struct;

#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
typedef struct
{
    S32 idx;
    mmi_applist_cell_type_enum cell_type;
} mmi_applist_user_tag;
#endif

typedef struct
{   
    MMI_ID parent_gid;
    void *app_mem_pool;
    KAL_ADM_ID adm_pool_id;
    #if defined(__MMI_PHNSET_APPICON_SUPPORT__) || defined(__MMI_DOWNLOADABLE_APPICON_SUPPORT__)
    MMI_BOOL is_cached;
    MMI_BOOL theme_changed;
    #endif

    #ifdef __MMI_APPLIST_SMART_ASM__
    MMI_BOOL can_cache_cell;
    #endif
    
    /* base layer */
    PU8 base_layer_buf_ptr;
    
    /* NVRAM */
    mmi_applist_data_struct data;

    /* app download icon */
    gdi_handle download_icon_handle;

    #ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
    gdi_handle uninstall_icon_handle;
    U32 installed_id[MMI_APPLIST_PANEL_APP_NUM];
    mmi_applist_user_tag user_tag;
    #endif

    /* preinstall app id */
    U32 preinstall_id[MMI_APPLIST_PANEL_APP_NUM];
    
    MMI_BOOL mainmenu_need_sync;

    #ifdef __MMI_APPLIST_CACHE_APP_NAME__
    mmi_app_package_name_struct app_name[MMI_APPLIST_ENTRY_NUM];
    #endif
    
    mmi_applist_state_enum state;
    
    #ifdef __MMI_FONT_EFFECTS__
    stFontAttributeNode *font_attr;
    #endif

    //TODO: maybe reuse nvram data space
    mmi_applist_cell_struct *bar_cell[MMI_APPLIST_BAR_APP_NUM];
    mmi_applist_cell_struct *panel_cell[MMI_APPLIST_PANEL_APP_NUM];

    /* indicator */
    PU8 indicator_ptr;  //first is highlight and second is normal
    mmi_applist_page_indicator_struct indicator[MMI_APPLIST_MAX_PAGE_NUM];

    #ifdef __MMI_APPLIST_EDIT_WITH_BG__
    gdi_handle icon_bg_handle;
    #else
    mmi_applist_shake_info_struct shake_info;
    #endif

    mmi_applist_slide_region_info_struct slide_region;
    mmi_applist_slide_type_enum slide_type;
    mmi_applist_cell_struct *cell_pool;
    
    mmi_applist_anima_node_struct *anima_node_pool;
    mmi_applist_anima_node_struct *used_anima_tail;
    S32 empty_anima_index;

    mmi_applist_cache_struct *cache_pool;
    MMI_BOOL cache_used[MMI_APPLIST_APP_CACHE_NUM];
    S32 empty_cache_index;
    
    /* wallaper layer */
    gdi_handle wallpaper_layer_handle;
    #if !defined(__GDI_MEMORY_PROFILE_2__)
    PU8 wallpaper_layer_buf_ptr;
    #endif
    U32 blt_layer_flag;
    U32 play_layer_flag;
    
    /* status_bar_layer_handle */
    gdi_handle status_bar_layer_handle;
    PU8 status_bar_buf_ptr;

    /* panel layer handle */
    gdi_handle panel_layer_handle;
    PU8 panel_layer_buf_ptr;

    #ifdef __MMI_APPLIST_ONLY_ICON_SUPPORT__    
    /* title layer */
    gdi_handle title_layer_handle;
    PU8 title_layer_buf_ptr;
    #endif
    
    /* Wallpaper config */
    mmi_applist_vlw_config wp_config;
    mmi_applist_vlw_client wp_client;
    mmi_applist_wallpaper_state_enum wp_state;    
    mmi_applist_wp_stop_type_enum wp_stop_type;
    
    mmi_applist_mode_enum mode;
    S32 edit_page_num;
    mmi_applist_focus_cell_struct focus_cell;

    mmi_applist_cache_cell_struct cache_cell;

    mmi_applist_slide_state_enum slide_state;
    mmi_applist_hit_area_struct hit_area;
    
    #if defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_point_struct pen_down_pos;
    mmi_pen_point_struct pen_last_pos;
    U32 pen_down_tick;
    S32 pen_down_page_idx;
    #endif   
    
    mmi_applist_dir_enum long_press_dir;
    #ifdef __MMI_APPLIST_KEY_SUPPORT__
    mmi_applist_hilight_frame_info_struct hilight_frame;
    U32 key_down_tick;
    #ifdef __MMI_APPLIST_KEY_LOOP__
    MMI_BOOL is_loop;  //loop from 0 to max or reverse
    #endif
    #endif /* __MMI_APPLIST_KEY_SUPPORT__ */
}mmi_applist_context_struct;

extern const mmi_app_package_name_struct g_mmi_applist_default_order[];
extern const S32 mmi_applist_default_order_count;
extern mmi_applist_context_struct *applist_p;

extern void mmi_applist_organize_cell(mmi_applist_hit_area_struct *hit_area);
extern void mmi_applist_load_data(void);
extern void mmi_applist_init_cell_info(void);
extern S32 mmi_applist_get_current_page_num(void);

extern S32 mmi_applist_get_bar_start_x(void);

extern S32 mmi_applist_get_last_panel_index(void);
extern void mmi_applist_get_cell_position(
                mmi_applist_cell_type_enum cell_type,
                S32 cell_idx,
                mmi_applist_position *pos);
extern S32 mmi_applist_get_current_page_idx(void);
extern S32 mmi_applist_get_cell_idx(S32 page_idx, S32 step_x, S32 step_y);
extern void mmi_applist_auto_slide(void);
extern void mmi_applist_cancel_auto_slide(void);
extern void mmi_applist_remove_cell(mmi_applist_cell_type_enum cell_type, S32 remove_idx);
extern S32 mmi_applist_add_panel_cell(S32 add_idx);
extern void mmi_applist_put_cache_cell(void);
extern void mmi_applist_reset_focus_cell(void);
extern void mmi_applist_set_indicator_info(S32 page_idx);
extern S32 mmi_applist_compact_page(void);
extern void mmi_applist_slide_to_page(S32 page_idx);
extern void mmi_applist_validate_slide_x(void);
extern void mmi_applist_save_data(void);
extern MMI_BOOL mmi_applist_if_hit_area_has_cell(mmi_applist_hit_area_struct *hit_area);
extern void mmi_applist_get_page_cell_idx(S32 page_idx, S32 *idx_from, S32 *idx_to);
extern void mmi_applist_cache_bar_cell(void);
extern void mmi_applist_cache_page(MMI_BOOL cache_page[], S32 *cell_start, S32 *cell_end);
extern U32 mmi_applist_get_cur_time(void);
extern void mmi_applist_blt_previous(void);

#ifdef __MMI_APPLIST_CACHE_PATH_APP_ICON__
extern void mmi_applist_delete_app_icon_cache_adm(void);
#endif
#if defined(__MMI_APPLIST_KEY_SUPPORT__) && !defined(__MMI_APPLIST_ONLY_ICON_SUPPORT__)
extern void mmi_applist_scroll_cell_string(void);
#endif

extern U32 mmi_applist_get_cell_id(mmi_applist_cell_type_enum type, S32 index);
extern mmi_applist_cell_struct *mmi_applist_get_cell_ptr(mmi_applist_cell_type_enum type, S32 index);
extern void mmi_applist_matrix_multiply(float *a, float *b, float *out);
extern void mmi_applist_get_panel_cell_location(
                S32 cell_idx, S32 *page_idx, S32 *step_x, S32 *step_y);
extern void mmi_applist_get_matrix(
                mmi_applist_matrix_type_enum type, 
                float value1,
                float value2,
                gdi_lt_matrix_struct *out);
extern S32 mmi_applist_draw_slide_area_icon(void);
extern float mmi_applist_sin(float rad);
extern float mmi_applist_cos(float rad);
extern void mmi_applist_wallpaper_blt(void);
extern void mmi_applist_open_wallpaper(void);
extern void mmi_applist_close_wallpaper(void);
extern void mmi_applist_start_wallpaper(void);
extern void mmi_applist_stop_wallpaper(mmi_applist_wp_stop_type_enum type);
extern void mmi_applist_delay_start_wallpaper(mmi_applist_wp_stop_type_enum type, S32 ms);

extern void mmi_applist_quiet_cache(void);

extern MMI_BOOL mmi_applist_is_preinstall(U32 app_id);
#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
extern MMI_BOOL mmi_applist_is_installed_app(U32 app_id);
extern void mmi_applist_get_installed_app_id(void);
#endif

#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_applist_get_hit_area(S32 pos_x, S32 pos_y, mmi_applist_hit_area_struct *hit_area);
extern S32 mmi_applist_get_indicator_hit_index(S32 pos_x, S32 pos_y);
extern void mmi_applist_reposition_cell(void);
extern void mmi_applist_update_focus_cell_pos(void);
extern void mmi_applist_get_reposition_hit_area(S32 pos_x, S32 pos_y, mmi_applist_hit_area_struct *hit_area);
extern void mmi_applist_set_focus_cell_info(void);
extern void mmi_applist_change_slide_x(mmi_pen_point_struct pos);
#endif
#ifdef __MMI_APPLIST_KEY_SUPPORT__ 
extern S32 mmi_applist_get_final_page_idx(void);
extern void mmi_applist_init_hilight_index_in_page(void);
extern void mmi_applist_arrow_key_press(mmi_applist_dir_enum dir);
extern void mmi_applist_init_hilight_frame(S32 page_idx);
extern void mmi_applist_arrow_key_press_cyclic(void);

#endif /* __MMI_APPLIST_KEY_SUPPORT__ */

#if defined(__MMI_PHNSET_APPICON_SUPPORT__) || defined(__MMI_DOWNLOADABLE_APPICON_SUPPORT__)
extern MMI_BOOL mmi_applist_cache_theme_icon(void);
#endif

#endif /* __MMI_LAUNCHER_APP_LIST__ */ 
#endif /* _MMI_APPLIST_H_ */ 

