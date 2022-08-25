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
 *  MediaAppPanel.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Panel for multi-media Apps.
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
 ****************************************************************************/

#ifndef _MEDIA_APP_PANEL_H_
#define _MEDIA_APP_PANEL_H_

#include "MMI_features.h"

#include "MMIDataType.h"
#include "gdi_include.h"
#include "mmi_frm_input_gprot.h"

typedef enum
{
    BTN_STAT_UP = 0,
    BTN_STAT_DOWN
} med_btn_stat_t;

/*
 * Icon buttons which has 3 images to indicate its state
 * Normal icon, pressed icon, disable icon
 */
typedef struct
{
    med_btn_stat_t  stat;
    MMI_IMG_ID      icon_press;
    MMI_IMG_ID      icon_up;
    MMI_IMG_ID      icon_disable;
} med_btn3_t;

/*
 * Icon buttons which has 4 images to indicate its state
 * Button icon, background, highlight mask, disable mask
 */
typedef struct
{
    med_btn_stat_t  stat;
    MMI_IMG_ID      icon;
    MMI_IMG_ID      icon_bg;
    MMI_IMG_ID      icon_hl_mask;
    MMI_IMG_ID      icon_dis_mask;
} med_btn4_t;

typedef struct
{
    med_btn_stat_t stat;
    CHAR *ptxt;
} med_txtbtn_t;

typedef struct
{
    S32 val;
} med_prog_t;

#define MED_BTN_MASK        0x10
#define MED_PROGESS_MASK    0x20

#define MED_ITEM_IS_BTN(type)     ((type) & MED_BTN_MASK)

typedef enum
{
    MED_ITEM_BTN3 = (MED_BTN_MASK | 1),
    MED_ITEM_BTN4 =  (MED_BTN_MASK | 2),
    MED_ITEM_TXTBTN = (MED_BTN_MASK | 3),
    MED_ITEM_PROGRESS = (MED_PROGESS_MASK | 1),
} med_panel_item_type_t;

typedef enum
{
    MED_PANEL_BG_TYPE_COLOR = 0,
    MED_PANEL_BG_TYPE_IMG,
    MED_PANEL_BG_TYPE_LAYER,
    MED_PANEL_BG_TYPE_CUST
} med_panel_bg_type_enum;

typedef void (*mmi_med_panel_draw_bg) (GDI_HANDLE h_dest_layer, S32 x1, S32 y1, S32 x2, S32 y2, void *userData);

typedef struct
{
    mmi_med_panel_draw_bg   draw;
    void                    *userData;
    union
    {
        GDI_COLOR   bgColor;
        GDI_HANDLE  bgLyr;
        struct
        {
            MMI_IMG_ID  id;
            GDI_HANDLE  blendLyr;
            S32         x;
            S32         y;
            S32         w;
            S32         h;
        }bgImg;
    }bgData;
} med_panel_bg_struct;

struct med_panel_item;
typedef void (*mmi_med_panel_item_draw) (const struct med_panel_item *pitem, GDI_HANDLE h_dest_layer,
                                         S32 enable, med_panel_bg_struct *pBgData);

typedef struct med_panel_item
{
    med_panel_item_type_t type;
    S32 x, y, w, h; /* layer coordination */
    U32 id;
    mmi_med_panel_item_draw draw;
    union
    {
        med_btn3_t btn3;
        med_btn4_t btn4;
        med_txtbtn_t txtbtn;
        med_prog_t prog;
    } data;
} med_panel_item_t;

typedef enum
{
    /* Button event */
    MED_EVT_BTN_DOWN,
    MED_EVT_BTN_UP,
    MED_EVT_BTN_PRE_UP, /* toggle button can change icon on this event */
    MED_EVT_BTN_CANCEL, /* move outside when down */

    /* Progress item event */
    MED_EVT_PROG_VAL_CHANGE
} med_panel_evt_t;
typedef void (*med_panel_cb_t) (U32 id, med_panel_evt_t event, void *userdata);

enum
{
    PANEL_STAT_INIT = 0,
    PANEL_STAT_DOWN_ITEM,   /* Pen down in enabled-item area */
    PANEL_STAT_DOWN_N_ITEM, /* Pen down in none-item or disabled-item area */
    PANEL_STAT_DOWN_DISABLE /* Pen down item was disabled */
};

typedef struct
{
    GDI_HANDLE h_layer;

    S32 x, y, w, h;     /* LCD coordination */
    S32 enable_flag;    /* enable or disable of eache item */
    S32 update_flag;    /* if need to update */
    U32 item_count;
    S32 down_index;
    S32 pen_stat;

    med_panel_item_t    *pitems;
    med_panel_bg_struct bg;

    med_panel_cb_t callback;
    void *usrdata;
} med_panel_t;

/* API */
#define MED_PANEL_MAX_ITEMS     30

typedef U32 med_panel_handle;
typedef U32 med_panel_item_handle;

extern med_panel_handle mmi_med_create_panel(
                            med_panel_t *pbuf,
                            GDI_HANDLE h_layer,
                            S32 x,
                            S32 y,
                            S32 w,
                            S32 h,
                            med_panel_item_t items[],
                            U32 count);
extern void mmi_med_panel_init_color_bg(med_panel_handle h_panel, GDI_COLOR bg_color);
extern void mmi_med_panel_init_img_bg(
                med_panel_handle h_panel,
                MMI_IMG_ID img_id,
                GDI_HANDLE blend_layer,
                S32 x,
                S32 y,
                S32 w,
                S32 h);
extern void mmi_med_panel_init_layer_bg(med_panel_handle h_panel, GDI_HANDLE bg_layer);
extern void mmi_med_panel_init_custom_bg(med_panel_handle h_panel, mmi_med_panel_draw_bg draw, void *userData);
extern void mmi_med_panel_init_btn3(med_panel_item_t *pbtn);
extern void mmi_med_panel_init_btn4(med_panel_item_t *pbtn);
extern void mmi_med_panel_init_txtbtn(med_panel_item_t *ptxtbtn);
extern void mmi_med_panel_init_prog(med_panel_item_t *pprog);

extern void mmi_med_destroy_panel(med_panel_handle h_panel);

#ifdef __MMI_TOUCH_SCREEN__

extern MMI_BOOL mmi_med_panel_pendown(med_panel_handle h_panel, mmi_pen_point_struct pos);
extern MMI_BOOL mmi_med_panel_penup(med_panel_handle h_panel);
extern MMI_BOOL mmi_med_panel_penmove(med_panel_handle h_panel, mmi_pen_point_struct pos);
extern MMI_BOOL mmi_med_panel_penabort(med_panel_handle h_panel, mmi_pen_abort_type_enum type);
extern void mmi_med_panel_set_cb(med_panel_handle h_panel, med_panel_cb_t event_cb, void *usrdata);

#endif /* __MMI_TOUCH_SCREEN__ */

extern void mmi_med_panel_enable_item(med_panel_handle h_panel, U32 id);
extern void mmi_med_panel_disable_item(med_panel_handle h_panel, U32 id);
extern void mmi_med_panel_press_item(med_panel_handle h_panel, U32 id);
extern void mmi_med_panel_up_item(med_panel_handle h_panel, U32 id);

/*
 * is_update :
 *  MMI_TRUE: only redraw the items updated
 *  MMI_FALSE: redraw all the items
 */
extern void mmi_med_panel_redraw(med_panel_handle h_panel, MMI_BOOL is_update);

extern void mmi_med_prog_set_val(med_panel_handle h_panel, U32 index, S32 val);
extern S32 mmi_med_prog_get_val(med_panel_handle h_panel, U32 index);

#endif /* _MEDIA_APP_PANEL_H_ */ 

