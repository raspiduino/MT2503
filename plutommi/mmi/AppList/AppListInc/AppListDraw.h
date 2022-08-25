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
 *  AppListDraw.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AppList Draw
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
#ifndef _MMI_APPLIST_DRAW_H_
#define _MMI_APPLIST_DRAW_H_

#include "mmi_features.h"


#ifdef __MMI_LAUNCHER_APP_LIST__

#include "gdi_linear_transform.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define GET_CELL_X(type, cell_x) \
    ((type == MMI_APPLIST_CELL_TYPE_SHORTCUT) ? cell_x : (cell_x - applist_p->slide_region.x))
#define GET_FINAL_CELL_X(type, cell_x) \
    ((type == MMI_APPLIST_CELL_TYPE_SHORTCUT) ? cell_x : (applist_p->slide_region.anima_node_p ? (cell_x - applist_p->slide_region.anima_node_p->to.pos_x) : (cell_x - applist_p->slide_region.x)))

#define GET_G_CELL_X(type, cell_x) \
    ((type == MMI_APPLIST_CELL_TYPE_SHORTCUT) ? cell_x : (cell_x + applist_p->slide_region.x))
#define GET_FINAL_G_CELL_X(type, cell_x) \
    ((type == MMI_APPLIST_CELL_TYPE_SHORTCUT) ? cell_x : (applist_p->slide_region.anima_node_p ? (cell_x + applist_p->slide_region.anima_node_p->to.pos_x) : (cell_x + applist_p->slide_region.x)))

#define MMI_APPLIST_DRAW_INFO_NUM (MMI_APPLIST_APP_COUNT_PER_PAGE * 2)

/* Float, Fixed conversion */
#define APPLIST_X_TO_F(x)                   ((float)x / 65536.0f)
#define APPLIST_F_TO_X(x)                   (S32)((x) * 65536.0f)
#define APPLIST_PI                          (3.1415926f)
#define APPLIST_DEG_TO_RAD(x)               ((float)((float)(x)) * APPLIST_PI / 180.0f)
#define APPLIST_RAD_TO_DEG(x)               ((float)((float)(x)) * 180.0f / APPLIST_PI)

#ifdef __MMI_FTE_SUPPORT__
#define APPLIST_PIXES_PER_POINT (3)
#else  //__MMI_FTE_SUPPORT__
#define APPLIST_PIXES_PER_POINT (4)
#endif  //__MMI_FTE_SUPPORT__

/***************************************************************************** 
 * Enum
 *****************************************************************************/

typedef enum
{
    MMI_APPLIST_ANIMA_TYPE_POSITION_X,
    MMI_APPLIST_ANIMA_TYPE_POSITION,    
    MMI_APPLIST_ANIMA_TYPE_OPACITY,
    MMI_APPLIST_ANIMA_TYPE_RESIZE,
    MMI_APPLIST_ANIMA_TYPE_ROTATE,
}mmi_applist_anima_type_enum;

typedef enum
{
    MMI_APPLIST_DIR_UP,
    MMI_APPLIST_DIR_DOWN,
    MMI_APPLIST_DIR_LEFT,
    MMI_APPLIST_DIR_RIGHT
}mmi_applist_dir_enum;

/***************************************************************************** 
 * Structure
 *****************************************************************************/

typedef struct
{
    S32 x;
    S32 y;
}mmi_applist_position;

typedef struct
{
    S32 x1;
    S32 y1;
    S32 x2;
    S32 y2;
}mmi_applist_rect;

typedef struct
{
    mmi_applist_position pos;
    U8 opacity;
    float resize;

    S32 cache_idx;
    srv_appmgr_app_package_type_enum type;
    #ifndef __MMI_APPLIST_ONLY_ICON_SUPPORT__
    U8 name_len;
    #endif
    /* image icon */
    mmi_image_src_type_enum image_type; 
    U8 *image_ptr;
    U32 image_len;
    union
    {
        MMI_ID res_id;  
        WCHAR path[MMI_MAX_FILE_NAME_LEN+1]; 
    } image;    

    U32 app_id;
    
    /* app name */
    mmi_app_package_name_struct  name; 
}mmi_applist_cell_struct;

typedef struct mmi_applist_anima_node_struct_t
{
    mmi_applist_anima_type_enum type;
    union
    {
        S32 pos_x;
        mmi_applist_position pos;
        U8 opacity;
        float resize;
        float rotate;
    }from; 
    union
    {
        S32 pos_x;
        mmi_applist_position pos;
        U8 opacity;
        float resize;
        float rotate;
    }to;      

    union
    {
        S32 *pos_x;
        mmi_applist_position *pos;
        U8 *opacity;
        float *resize;
        float *rotate;
    }target;
    
    U32 duration;
    U32 start_time;   
    struct mmi_applist_anima_node_struct_t *next;
}mmi_applist_anima_node_struct;

typedef struct
{    
    S32 x;
    mmi_applist_anima_node_struct *anima_node_p;
    mmi_applist_dir_enum slide_dir;
}mmi_applist_slide_region_info_struct;

#ifdef G2D_SUPPORT
typedef struct
{    
    float angle;
    mmi_applist_anima_node_struct *anima_node_p;    
}mmi_applist_shake_info_struct;
#endif

typedef struct
{    
    gdi_lt_matrix_struct transform;   
    float pos_z;  
    U8 opacity;
}mmi_applist_draw_info_struct;


/***************************************************************************** 
 * Function
 *****************************************************************************/

void mmi_applist_reset_anima_queue(void);
void mmi_applist_update_anima_data(void);

void mmi_applist_remove_slide_x_anima(void);
void mmi_applist_change_slide_x_anima(S32 x);

void mmi_applist_change_pos_anima(
                mmi_applist_position *target_pos, 
                mmi_applist_position *new_pos, 
                U32 cur_time);

void mmi_applist_change_cell_resize_anima(
        mmi_applist_cell_struct *cell_p, 
        float new_resize, 
        U32 cur_time);
#ifdef __MMI_APPLIST_EDIT_WITH_BG__
void mmi_applist_draw_icon_bg_in_cache(void);
#else
void mmi_applist_add_shake_anima(U32 cur_time);
void mmi_applist_remove_shake_anima(void);
#endif
void mmi_applist_draw_panel(void);
void mmi_applist_draw_app_download_icon_in_cache(void);
void mmi_applist_draw_indicator_in_cache(void);

#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
void mmi_applist_draw_app_uninstall_icon_in_cache(void);
#endif

#ifdef __MMI_APPLIST_KEY_SUPPORT__
void mmi_applist_draw_highlight_frame_in_cache(void);

#ifdef __MMI_APPLIST_ONLY_ICON_SUPPORT__
void mmi_applist_draw_title(void);
#endif /* __MMI_APPLIST_ONLY_ICON_SUPPORT__ */
#endif //__MMI_APPLIST_KEY_SUPPORT__


#endif /* __MMI_LAUNCHER_APP_LIST__ */

#endif /* _MMI_APPLIST_DRAW_H_ */
