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
 *   FactoryModeTouchPanel.c
 *
 * Project:
 * --------
 *   11A
 *
 * Description:
 * ------------
 *   FM Touch panel
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#include "dcmgr.h"
#elif defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "MMI_ap_dcm_config.h"  
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_A__ */
     
#if defined(__MMI_AP_DCM_FM__)
#pragma arm section rodata = "DYNAMIC_CODE_FM_RODATA" , code = "DYNAMIC_CODE_FM_ROCODE"
#elif defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_FM_RODATA" , code = "DYNAMIC_CODE_COSMOS_FM_ROCODE"
#endif /* #ifdef __MMI_AP_DCM_FM__ */


#include "MMI_features.h"
#ifdef __MMI_FACTORY_MODE__
#ifdef __MMI_FM_TOUCH_PANEL_ACCURACY_TEST__
#include "MMI_include.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "GlobalMenuItems.h"
#include "Dcl.h"
#include "math.h"
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "Gdi_include.h"
#include "gui_themes.h"
#include "AlertScreen.h"
#include "Gui.h"
#include "wgui_categories_util.h"
#include "Menucuigprot.h"
#include "mmi_frm_input_gprot.h"

//#include "FactoryModeResDef.h"
#include "mmi_rp_app_factorymode_def.h"
#include "FactoryModeProt.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define MMI_FM_TP_TEST_JITTER_NUM        5
#define MMI_FM_TP_TEST_LINER_NUM         5  
#define MMI_FM_TP_TEST_LINER_END_LENGTH  3
#define MMI_FM_TP_TEST_TEXT_LEN         16

#define FM_TP_TEST_BG_COLOR                     GDI_COLOR_WHITE
#define FM_TP_TEST_LINE_BG_COLOR                GDI_COLOR_BLACK
#define FM_TP_TEST_LINE_FG_COLOR                GDI_COLOR_GREEN
#define FM_TP_TEST_CIRCAL_COLOR                 GDI_COLOR_GREEN
#define FM_TP_TEST_CIRCAL_PASS_COLOR            GDI_COLOR_GREEN
#define FM_TP_TEST_CIRCAL_FAIL_COLOR            GDI_COLOR_RED
#define FM_TP_TEST_TRANSPARENT_COLOR            GDI_COLOR_BLUE

#define FM_TP_TEST_TEXT_BG_COLOR                gui_color(0,0,0)
#define FM_TP_TEST_TEXT_FG_COLOR                gui_color(255,0,0)
#define FM_TP_TEST_TEXT_RESULT_COLOR            gui_color(255,0,0)


#define MMI_FM_TP_LINE_ARROW_LEN    10
#define MMI_FM_TP_LINE_DOWN         0
#define MMI_FM_TP_LINE_RIGHT        1
#define MMI_FM_TP_LINE_UP           2
#define MMI_FM_TP_LINE_LEFT         3
#define MMI_FM_TP_LINE_RIGHT_DOWN   4
#define MMI_FM_TP_LINE_LEFT_DOWN    5

#define MMI_FM_TP_ABSSUB(a, b)  (((a) > (b))? ((a) - (b)) : ((b) - (a)))
#define MMI_FM_TP_MAX(a, b)    (((a) > (b)) ? (a) : (b))
#define MMI_FM_TP_MIN(a, b)    (((a) < (b)) ? (a) : (b))

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef void (* mmi_fm_tp_pen_hdlr) (void *, mmi_pen_event_type_enum, mmi_pen_point_struct *, U32);
typedef void (* mmi_fm_tp_data_deinit) (void *);
typedef void (* mmi_fm_tp_draw_bg) (void *);

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
    S16 x1;
    S16 y1;
    S16 x2;
    S16 y2;    
}mmi_fm_tp_rect_struct;



typedef struct
{
    mmi_pen_point_struct p1;
    mmi_pen_point_struct p2;
}mmi_fm_tp_line_struct;

typedef struct
{
    U16             pen_register;
    U16             item_id;
    U16             is_test_finish;
    U16             is_fail;
    gdi_handle      layer_handle;
    gdi_handle      base_handle;
    MMI_ID          group_id; 
    void*           item_data;
    U32             dump_screen;

    mmi_pen_point_struct    fail_position;
    mmi_fm_tp_pen_hdlr      pen_hdlr_func;
    mmi_fm_tp_draw_bg       draw_bg_func;
    mmi_fm_tp_data_deinit   data_deinit_func; 
    mmi_fm_tp_rect_struct   coordinate_rect;
    mmi_fm_tp_rect_struct   pressure_rect;
}mmi_fm_tp_test_item_struct;

typedef struct
{    
    U16     cur_line;
    S32     non_border_pass_criterion;
    
    mmi_fm_tp_test_item_struct  *parent;
    mmi_pen_point_struct        last_point;    
    mmi_fm_tp_line_struct       lines[MMI_FM_TP_TEST_LINER_NUM];
}mmi_fm_tp_test_liner_struct;

typedef struct
{
    U16     cur_point;
    S32     non_border_pass_criterion;

    mmi_fm_tp_test_item_struct  *parent; 
    mmi_pen_point_struct        last_point;       
    mmi_pen_point_struct        point[MMI_FM_TP_TEST_JITTER_NUM];     
}mmi_fm_tp_test_jitter_struct;


/***************************************************************************** 
 * Extern function 
 *****************************************************************************/
#define EXTERN_FUNCTION
extern void tst_dump_gdi_snapshot(kal_uint32 tokey);


/***************************************************************************** 
 * Static function 
 *****************************************************************************/ 
#define STATIC_FUNCTION
#define TEST_LINER
static void mmi_fm_tp_test_liner_verify(mmi_fm_tp_test_liner_struct *context,
                                                mmi_pen_point_struct *pos,
                                                mmi_pen_event_type_enum pen_type);
static void mmi_fm_tp_test_liner_pen_hdlr(void *item_data,
                                            mmi_pen_event_type_enum pen_type,
                                            mmi_pen_point_struct *pos,
                                            U32 pressure);
static void mmi_fm_tp_test_liner_data_init(mmi_fm_tp_test_item_struct* item);
static void mmi_fm_tp_test_liner_draw_bg(void *item_data);

#define TEST_JITTER
static void mmi_fm_tp_test_jitter_verify(mmi_fm_tp_test_jitter_struct *context,
                                                mmi_pen_point_struct *pos,
                                                mmi_pen_event_type_enum pen_type);
static void mmi_fm_tp_test_jitter_pen_hdlr(void *item_data,
                                            mmi_pen_event_type_enum pen_type,
                                            mmi_pen_point_struct *pos,
                                            U32 pressure);
static void mmi_fm_tp_test_jitter_data_init(mmi_fm_tp_test_item_struct* item);
static void mmi_fm_tp_test_jitter_draw_bg(void *item_data);

#define TEST_ITEM
static S32 mmi_fm_tp_test_get_len_two_point(mmi_pen_point_struct* p1,
                                                mmi_pen_point_struct* p2);
static S32 mmi_fm_tp_test_len_point_to_segment(mmi_pen_point_struct* p1,
                                                mmi_pen_point_struct* p2,
                                                mmi_pen_point_struct* p);
static U32 mmi_fm_tp_get_pixel_from_um(U32 um_length);
static void mmi_fm_tp_get_custom_data(TouchPanel_EM_custom_data_struct *custom_data);
static void mmi_fm_tp_test_draw_result(U32 is_pass, mmi_pen_point_struct *pos);
static void mmi_fm_tp_test_draw_text_rect(mmi_fm_tp_rect_struct *rect, U16 *text, color text_color);
static void mmi_fm_tp_test_goback(void);

static void mmi_fm_tp_test_item_draw_line_with_arrow(mmi_pen_point_struct *p1,
                                                        mmi_pen_point_struct *p2,
                                                        gdi_color color);
static void mmi_fm_tp_test_item_draw_order_num(S32 x, S32 y, S32 number);
static void mmi_fm_tp_test_draw_pos_and_press(mmi_fm_tp_test_item_struct * item,
                                                mmi_pen_point_struct *pos,
                                                U32 pressure, 
                                                color text_color);
static MMI_RET mmi_fm_tp_test_item_pen_proc(mmi_event_struct *param);
static void mmi_fm_tp_test_item_data_init(mmi_fm_tp_test_item_struct *item);
static void mmi_fm_tp_test_item_draw_bg(mmi_fm_tp_test_item_struct * item);
static void mmi_fm_tp_test_item_set_hdlr(mmi_fm_tp_test_item_struct * item);
static void mmi_fm_tp_test_item_prepare(mmi_fm_tp_test_item_struct * item);
static MMI_RET mmi_fm_tp_test_item_proc(mmi_event_struct *param);
static void mmi_fm_tp_test_item_exit_screen(mmi_scrn_essential_struct* ess);
static void mmi_fm_tp_test_item_enter_screen(mmi_scrn_essential_struct* ess);
static void mmi_fm_tp_test_item_enter(MMI_ID parent_id, U32 item_id);


#define TOUCH_PANEL
static void mmi_fm_touch_panel_select_hdlr(cui_menu_event_struct *evt);
static MMI_RET mmi_fm_touch_panel_proc(mmi_event_struct *param);
extern void mmi_fm_touch_panel_entry(void);
static void mmi_fm_tp_set_rect(mmi_fm_tp_rect_struct *rect, U32 x1, U32 y1, U32 w, U32 h);



/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#define GLOBAL_VARIABLE
static mmi_fm_tp_test_liner_struct  g_mmi_fm_tp_test_liner;
static mmi_fm_tp_test_jitter_struct g_mmi_fm_tp_test_jitter;
static mmi_fm_tp_test_item_struct  g_mmi_fm_tp_test_item;


#define TEST_LINER
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_tp_test_liner_verify
 * DESCRIPTION
 *  verify current point's pass crerition 
 * PARAMETERS
 *  context     [IN]  linear-horizontal context
 *  pos         [IN]  current coordinate of point 
 *  pen_type    [IN]    down/move/up and so on    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_tp_test_liner_verify(mmi_fm_tp_test_liner_struct *context,
                                                mmi_pen_point_struct *pos,
                                                mmi_pen_event_type_enum pen_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 is_fail;
    U32 index;
    S32 length;
    mmi_fm_tp_line_struct *lines = context->lines;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = context->cur_line;
    if (MMI_PEN_EVENT_DOWN == pen_type)
    {
        length = mmi_fm_tp_test_get_len_two_point(&lines[index].p1, pos);
    }
    else if (MMI_PEN_EVENT_UP == pen_type)
    {
        length = mmi_fm_tp_test_get_len_two_point(&lines[index].p2, pos);
    }
    else
    {
        length = mmi_fm_tp_test_len_point_to_segment(&lines[index].p1, &lines[index].p2, pos);
    }
    is_fail = (length > context->non_border_pass_criterion) ? 1 : 0;
      
    if (!context->parent->is_fail)
    {
		 context->parent->is_fail = is_fail; 
    }      
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_tp_test_liner_pen_hdlr
 * DESCRIPTION
 *  pen handler of touch panel line test  
 * PARAMETERS
 *  item_data   [IN]    
 *  pen_type    [IN]    down/move/up
 *  pos         [IN]    coordinate of point
 *  pressure    [IN]    pressure        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_tp_test_liner_pen_hdlr(void *item_data,
                                            mmi_pen_event_type_enum pen_type,
                                            mmi_pen_point_struct *pos,
                                            U32 pressure)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_tp_test_liner_struct *context = (mmi_fm_tp_test_liner_struct *)item_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (context->cur_line >= MMI_FM_TP_TEST_LINER_NUM)
    {
        return;
    }    
    mmi_fm_tp_test_liner_verify(context, pos, pen_type);
    
    switch (pen_type)
    {
        case MMI_PEN_EVENT_MOVE:
            gdi_draw_line(context->last_point.x, context->last_point.y, pos->x, pos->y, FM_TP_TEST_LINE_FG_COLOR);        
            break;

        case MMI_PEN_EVENT_UP:
            gdi_draw_line(context->last_point.x, context->last_point.y, pos->x, pos->y, FM_TP_TEST_LINE_FG_COLOR);
            context->cur_line ++;
            if (context->cur_line == MMI_FM_TP_TEST_LINER_NUM)
            {
                context->parent->is_test_finish = 1;
            }
            break;
            
        default:
            break;
    }
    mmi_fm_tp_test_draw_pos_and_press(context->parent, pos, pressure, FM_TP_TEST_TEXT_FG_COLOR);
    context->last_point.x = pos->x;
    context->last_point.y = pos->y;  
}


/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_liner_data_init
  * DESCRIPTION
  *  mmi_fm_tp_test_liner_data_init
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void
  *****************************************************************************/
static void mmi_fm_tp_test_liner_data_init(mmi_fm_tp_test_item_struct* item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 string_width;
    S32 string_height;
    S32 layer_width;
    S32 layer_height;
    S32 border_range;
    S32 non_border_pass_criterion;
    mmi_fm_tp_test_liner_struct *context;
    TouchPanel_EM_custom_data_struct custom_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->data_deinit_func = NULL;
    item->draw_bg_func = mmi_fm_tp_test_liner_draw_bg;
    item->pen_hdlr_func = mmi_fm_tp_test_liner_pen_hdlr;
    item->pen_register = ((0X01 << MMI_PEN_EVENT_DOWN) | (0X01 << MMI_PEN_EVENT_UP)) | 
                            (0X01 << MMI_PEN_EVENT_MOVE);
    item->fail_position.x = UI_device_width / 2;
    item->fail_position.y = UI_device_height / 2;
        
    item->item_data = &g_mmi_fm_tp_test_liner;
    context = (mmi_fm_tp_test_liner_struct *)item->item_data;
    memset(context, 0, sizeof(mmi_fm_tp_test_liner_struct));
    context->parent = item;

    mmi_fm_tp_get_custom_data(&custom_data);
    non_border_pass_criterion= mmi_fm_tp_get_pixel_from_um(custom_data.non_border_pass_criterion);
    border_range = mmi_fm_tp_get_pixel_from_um(custom_data.border_range);
    item->dump_screen = custom_data.Dump_Screen ? 1: 0;

    context->non_border_pass_criterion = non_border_pass_criterion;
    
    context->lines[0].p1.x = border_range + non_border_pass_criterion / 2;
    context->lines[0].p1.y = border_range + non_border_pass_criterion / 2;
    context->lines[0].p2.x = context->lines[0].p1.x;
    context->lines[0].p2.y = UI_device_height - 1 - 2 * (border_range + non_border_pass_criterion);
    
    context->lines[1].p1.x = border_range + non_border_pass_criterion / 2;
    context->lines[1].p1.y = UI_device_height - 1 - border_range - non_border_pass_criterion / 2;
    context->lines[1].p2.x = UI_device_width -1 - 2 * (border_range + non_border_pass_criterion);
    context->lines[1].p2.y = context->lines[1].p1.y;

    context->lines[2].p1.x = UI_device_width -1 - border_range - non_border_pass_criterion / 2;
    context->lines[2].p1.y = UI_device_height -1 - border_range - non_border_pass_criterion / 2;
    context->lines[2].p2.x = context->lines[2].p1.x;
    context->lines[2].p2.y = 2*(border_range + non_border_pass_criterion);
    
    context->lines[3].p1.x = UI_device_width -1 - border_range - non_border_pass_criterion / 2;
    context->lines[3].p1.y = border_range + non_border_pass_criterion / 2;
    context->lines[3].p2.x = 2*(border_range + non_border_pass_criterion);
    context->lines[3].p2.y = context->lines[3].p1.y;
    
    context->lines[4].p1.x = 2*(border_range + non_border_pass_criterion);
    context->lines[4].p1.y = 2*(border_range + non_border_pass_criterion);
    context->lines[4].p2.x = UI_device_width -1 - 2 * (border_range + non_border_pass_criterion);
    context->lines[4].p2.y = UI_device_height -1 - 2 * (border_range + non_border_pass_criterion);
    
    context->cur_line = 0;
    context->last_point.x = context->last_point.y = -1;

    gui_measure_string(L"(888, 888)", &string_width, &string_height);
    layer_width = string_width + 4;
    layer_height = UI_device_height - 2 * (border_range + non_border_pass_criterion);
    gdi_layer_create(UI_device_width / 2 - layer_width / 2,
                          border_range + non_border_pass_criterion,
                          layer_width,
                          layer_height, 
                          &(context->parent->layer_handle)); 
    mmi_fm_tp_set_rect(&(item->coordinate_rect), 0, 5, layer_width, string_height);
    mmi_fm_tp_set_rect(&(item->pressure_rect), 0, layer_height - string_height - 5, layer_width, string_height); 
}

/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_liner_draw_bg
  * DESCRIPTION
  *  draw background
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_liner_draw_bg(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 string_width;
    S32 string_height;
    mmi_pen_point_struct num;
    mmi_fm_tp_test_liner_struct *context = (mmi_fm_tp_test_liner_struct *)item_data;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_string(L"8", &string_width, &string_height);
    for (i = 0; i < MMI_FM_TP_TEST_LINER_NUM; ++i)
    {
        mmi_fm_tp_test_item_draw_line_with_arrow(&context->lines[i].p1,
                                                    &context->lines[i].p2,
                                                    FM_TP_TEST_LINE_BG_COLOR);
        /*draw order number*/
        num.x = context->lines[i].p1.x;
        num.y = context->lines[i].p1.y;
        if (num.x + string_width >= UI_device_width)
        {
            num.x = UI_device_width - 1 - string_width;
        }
        if (num.y + string_height >= UI_device_height)
        {
            num.y = UI_device_height - string_height - 1;
        }
        mmi_fm_tp_test_item_draw_order_num(num.x, num.y, i + 1);
    }
}


#define TEST_JITTER
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_tp_test_jitter_verify
 * DESCRIPTION
 *  verify current point's pass crerition 
 * PARAMETERS
 *  context     [IN]  
 *  pos         [IN]  current coordinate of point 
 *  pen_type    [IN]  down/move/up    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_tp_test_jitter_verify(mmi_fm_tp_test_jitter_struct *context,
                                                mmi_pen_point_struct *pos,
                                                mmi_pen_event_type_enum pen_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S32 r;
    S32 len_x;
    S32 len_y;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len_x = pos->x - context->point[context->cur_point].x;
    len_y = pos->y - context->point[context->cur_point].y;
    r = context->non_border_pass_criterion;
    if (!context->parent->is_fail)
    {
        context->parent->is_fail = len_x * len_x + len_y * len_y > r * r ? 1 : 0;
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_tp_test_jitter_pen_hdlr
 * DESCRIPTION
 *  pen handler of touch panel line test
 * PARAMETERS
 *  item_data   [IN]    
 *  pen_type    [IN]    down/move/up
 *  pos         [IN]    coordinate of point
 *  pressure    [IN]    pressure        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_tp_test_jitter_pen_hdlr(void *item_data,
                                            mmi_pen_event_type_enum pen_type,
                                            mmi_pen_point_struct *pos,
                                            U32 pressure)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_tp_test_jitter_struct *context = (mmi_fm_tp_test_jitter_struct *)item_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (context->cur_point >= MMI_FM_TP_TEST_JITTER_NUM)
    {
        return;
    }    
    mmi_fm_tp_test_jitter_verify(context, pos, pen_type);

    
    switch (pen_type)
    {
        case MMI_PEN_EVENT_DOWN:
            gdi_draw_solid_circle(pos->x, pos->y, 2, FM_TP_TEST_LINE_FG_COLOR);
            break;
            
        case MMI_PEN_EVENT_MOVE:
            gdi_draw_line(context->last_point.x, context->last_point.y, pos->x, pos->y, FM_TP_TEST_LINE_FG_COLOR);        
            break;

        case MMI_PEN_EVENT_UP:
            gdi_draw_line(context->last_point.x, context->last_point.y, pos->x, pos->y, FM_TP_TEST_LINE_FG_COLOR);
            if (0 == context->parent->is_fail)
            {
                gdi_draw_solid_circle(context->point[context->cur_point].x,
                                context->point[context->cur_point].y,
                                context->non_border_pass_criterion,
                                FM_TP_TEST_CIRCAL_PASS_COLOR);        
            }
            else
            {
                gdi_draw_solid_circle(context->point[context->cur_point].x,
                                context->point[context->cur_point].y,
                                context->non_border_pass_criterion,
                                FM_TP_TEST_CIRCAL_FAIL_COLOR);
            }
            context->cur_point++;
            
            if (context->cur_point == MMI_FM_TP_TEST_JITTER_NUM)
            {
    			context->parent->is_test_finish = 1;
            }
            break;

        default:
            break;
    }
    mmi_fm_tp_test_draw_pos_and_press(context->parent, pos, pressure, FM_TP_TEST_TEXT_FG_COLOR);
    context->last_point.x = pos->x;
    context->last_point.y = pos->y; 
}


/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_jitter_data_init
  * DESCRIPTION
  *  mmi_fm_tp_test_jitter_data_init
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void
  *****************************************************************************/
static void mmi_fm_tp_test_jitter_data_init(mmi_fm_tp_test_item_struct* item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S32 string_width;
    S32 string_height;
    S32 layer_width;
    S32 layer_height;

    mmi_fm_tp_test_jitter_struct *context;
    TouchPanel_EM_custom_data_struct custom_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->data_deinit_func = NULL;
    item->draw_bg_func = mmi_fm_tp_test_jitter_draw_bg;
    item->pen_hdlr_func = mmi_fm_tp_test_jitter_pen_hdlr;

    item->pen_register = ((0X01 << MMI_PEN_EVENT_DOWN) | (0X01 << MMI_PEN_EVENT_UP)) | 
                            ((0X01 << MMI_PEN_EVENT_REPEAT) | (0X01 << MMI_PEN_EVENT_LONG_TAP)) | 
                            (0x01 << MMI_PEN_EVENT_MOVE);
    item->fail_position.x = UI_device_width / 4;
    item->fail_position.y = UI_device_height / 2;
        
    item->item_data = &g_mmi_fm_tp_test_jitter;
    context = (mmi_fm_tp_test_jitter_struct *)item->item_data;
    context->parent = item;

    mmi_fm_tp_get_custom_data(&custom_data);
    context->non_border_pass_criterion = mmi_fm_tp_get_pixel_from_um(custom_data.non_border_pass_criterion);
    item->dump_screen = custom_data.Dump_Screen ? 1: 0;

    context->point[0].x = UI_device_width / 4 + context->non_border_pass_criterion / 2;
    context->point[0].y = UI_device_height / 4 + context->non_border_pass_criterion / 2;

    context->point[1].x = UI_device_width - UI_device_width / 4 - context->non_border_pass_criterion / 2;
    context->point[1].y = UI_device_height/ 4 + context->non_border_pass_criterion / 2;

    context->point[2].x = UI_device_width / 2;
    context->point[2].y = UI_device_height / 2;

    context->point[3].x = UI_device_width / 4 + context->non_border_pass_criterion / 2;
    context->point[3].y = UI_device_height - UI_device_height / 4 - context->non_border_pass_criterion / 2;

    context->point[4].x = UI_device_width - UI_device_width / 4 - context->non_border_pass_criterion / 2;
    context->point[4].y = UI_device_height - UI_device_height / 4 - context->non_border_pass_criterion / 2;
    
    context->cur_point= 0;
    gui_measure_string(L"(888, 888)", &string_width, &string_height);

    layer_width = UI_device_width;
    layer_height = string_height + 2;
    gdi_layer_create(0,
                    UI_device_height / 4 + context->non_border_pass_criterion + 5,
                    layer_width,
                    layer_height, 
                    &(context->parent->layer_handle)); 

    mmi_fm_tp_set_rect(&(item->coordinate_rect), 0 , 0, string_width, layer_height);
    mmi_fm_tp_set_rect(&(item->pressure_rect), UI_device_width/2, 0, string_width, layer_height);    
}


/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_jitter_draw_bg
  * DESCRIPTION
  *  draw background
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_jitter_draw_bg(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    
    mmi_fm_tp_test_jitter_struct *context = (mmi_fm_tp_test_jitter_struct *)item_data;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_FM_TP_TEST_JITTER_NUM; ++i)
    {
        gdi_draw_circle(context->point[i].x, 
                            context->point[i].y, 
                            context->non_border_pass_criterion,
                            FM_TP_TEST_LINE_BG_COLOR);
        
        mmi_fm_tp_test_item_draw_order_num(context->point[i].x + context->non_border_pass_criterion,
                                    context->point[i].y,
                                    i + 1);
    }  
}

#define TEST_ITEM
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_tp_test_get_len_two_point
 * DESCRIPTION
 *  get the length of two point. 
 * PARAMETERS
 *  p1     [IN]     point 1
 *  p2     [IN]     point 2
 * RETURNS
 *  S32    
 *****************************************************************************/
static S32 mmi_fm_tp_test_get_len_two_point(mmi_pen_point_struct* p1,
                                                mmi_pen_point_struct* p2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len_x;
    S32 len_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len_x = p2->x - p1->x;
    len_y = p2->y - p1->y;
    return (S32)sqrt((double)(len_x * len_x + len_y * len_y));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_tp_test_len_point_to_segment
 * DESCRIPTION
 *  get the length that point 'p' to a segment which is composed of  p1 and p2
 *  "http://blog.csdn.net/kome2000/archive/2009/07/27/4383086.aspx"
 * PARAMETERS
 *  p1      [IN]
 *  p2      [IN]
 *  p       [IN]    pen position
 * RETURNS
 *  S32     
 *****************************************************************************/
static S32 mmi_fm_tp_test_len_point_to_segment(mmi_pen_point_struct* p1,
                                                mmi_pen_point_struct* p2,
                                                mmi_pen_point_struct* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct vector1;
    mmi_pen_point_struct vector2;
    mmi_pen_point_struct p3;
    S32 r_p1p2_p1p;
    S32 length_2_p1_p2; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vector1.x = p2->x - p1->x;
    vector1.y = p2->y - p1->y;

    vector2.x = p->x - p1->x;
    vector2.y = p->y - p1->y;
    
    r_p1p2_p1p = vector1.x * vector2.x + vector1.y * vector2.y;
    if (r_p1p2_p1p < 0)
        return mmi_fm_tp_test_get_len_two_point(p1, p);
    
    length_2_p1_p2 = vector1.x * vector1.x + vector1.y * vector1.y;
    if (r_p1p2_p1p > length_2_p1_p2)
        return mmi_fm_tp_test_get_len_two_point(p2, p);

    p3.x = p1->x + vector1.x * r_p1p2_p1p / length_2_p1_p2;
    p3.y = p1->y + vector1.y * r_p1p2_p1p / length_2_p1_p2;
    return mmi_fm_tp_test_get_len_two_point(&p3, p);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_tp_get_pixel_from_um
 * DESCRIPTION
 *  mmi_fm_tp_get_pixel_from_um 
 * PARAMETERS
 *  um_length     [IN] length in um
 * RETURNS
 *  S32    
 *****************************************************************************/
static U32 mmi_fm_tp_get_pixel_from_um(U32 um_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_HANDLE handle;
    DCL_CTRL_MICRONMETER_COORD_T data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    memset(&data, 0, sizeof(DCL_CTRL_MICRONMETER_COORD_T));
    data.x_micronmeter = um_length;
    data.y_micronmeter = 0;
    handle = DclSTS_Open(DCL_TS, 0);
    DclSTS_Control(handle, STS_CMD_CTRL_MICRONMETER_TO_COORD, (DCL_CTRL_DATA_T*)&data);
    return data.x_coord;
#else /*__MTK_TARGET__*/
     return 8 * um_length / 1000;
#endif /*__MTK_TARGET__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_tp_get_custom_data
 * DESCRIPTION
 *  mmi_fm_tp_get_custom_data 
 * PARAMETERS
 *  custom_data     [IN]
 * RETURNS
 *  S32    
 *****************************************************************************/
static void mmi_fm_tp_get_custom_data(TouchPanel_EM_custom_data_struct *custom_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_HANDLE handle;
    DCL_CTRL_CUSTOM_PARAM_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MTK_TARGET__
        data.type = TP_PARAM_GET;
        data.pEmData = custom_data;
        memset(custom_data, 0, sizeof(TouchPanel_EM_custom_data_struct));
        
        handle = DclSTS_Open(DCL_TS, 0);
        if (DCL_HANDLE_INVALID != handle)
        {
            DclSTS_Control(handle, STS_CMD_CTRL_CUSTOM_PARAM, (DCL_CTRL_DATA_T*)&data);
        }
    #else /*__MTK_TARGET__*/ 
        {       
            custom_data->ts_debounce_time = 10;
            custom_data->touch_panel_cali_check_offset = 1;
            custom_data->min_pen_move_offset = 1;
            custom_data->hand_writing_max_offset = 100;
            custom_data->nonhand_writing_max_offset = 100;
            custom_data->max_stroke_move_offset = 1;
            custom_data->multiple_point_selection = 1;
            custom_data->touch_pressure_threshold_high = 2000;
            custom_data->pressure_check_boundary = 500;
            custom_data->pressure_shifting_boundary = 300;
            custom_data->border_pass_criterion = 2000;
            custom_data->non_border_pass_criterion = 6000;
            custom_data->border_range = 2000;
            custom_data->reserve_parameter1 = 0;
            custom_data->reserve_parameter2 = 0;
            custom_data->reserve_parameter3 = 0;
            custom_data->width = 240;
            custom_data->height = 400;
        }
    #endif /*__MTK_TARGET__*/     
}

/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_draw_result
  * DESCRIPTION
  *  mmi_fm_tp_test_draw_result
  * PARAMETERS
  *  is_pass        [IN]
  *  pos            [IN]  position where draw pass result
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_draw_result(U32 is_pass, mmi_pen_point_struct *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_w;
    S32 string_h;
    U16 text[MMI_FM_TP_TEST_TEXT_LEN];
    mmi_fm_tp_rect_struct rect;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_pass)
    {
        kal_wsprintf(text, "PASS");
    }
    else
    {
        kal_wsprintf(text, "FAIL");
    }
    gui_measure_string(text,&string_w, &string_h);
    mmi_fm_tp_set_rect(&rect, pos->x - string_w / 2, pos->y, string_w, string_h);
    mmi_fm_tp_test_draw_text_rect(&rect, text, FM_TP_TEST_TEXT_RESULT_COLOR);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_draw_text_rect
  * DESCRIPTION
  *  mmi_fm_tp_test_draw_text_rect
  * PARAMETERS
  *  rect           [IN]   rect where text printed
  *  text_color     [IN]   text color
  *  text           [IN]   text to print    
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_draw_text_rect(mmi_fm_tp_rect_struct *rect, U16 *text, color text_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(rect->x1, rect->y1, rect->x2, rect->y2);         
    gui_move_text_cursor(rect->x1, rect->y1);
    gui_set_text_color(text_color);
    gui_print_text(text);
    gui_pop_clip();
}

/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_goback
  * DESCRIPTION
  *  go back to last screen
  * PARAMETERS
  *  void   
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
/*
    MMI_ID group_id;
    group_id = mmi_frm_group_get_active_id();
    mmi_frm_group_close(group_id); */
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_draw_pos_and_press
  * DESCRIPTION
  *  mmi_fm_tp_test_draw_pos_and_press
  * PARAMETERS
  *  item           [IN]
  *  pos            [IN]
  *  pressure       [IN]
  *  text_color     [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_draw_pos_and_press(mmi_fm_tp_test_item_struct * item,
                                                mmi_pen_point_struct *pos,
                                                U32 pressure, 
                                                color text_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 text[MMI_FM_TP_TEST_TEXT_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/             
    gdi_layer_set_active(item->layer_handle);
    gdi_layer_clear(FM_TP_TEST_TRANSPARENT_COLOR);
    gdi_layer_set_source_key(TRUE, FM_TP_TEST_TRANSPARENT_COLOR);
    /*draw point coordination*/
    kal_wsprintf(text,"(%d, %d)", pos->x, pos->y);
    mmi_fm_tp_test_draw_text_rect(&item->coordinate_rect, text, text_color);

    /* draw pressure */
    kal_wsprintf(text, "%d", pressure);
    mmi_fm_tp_test_draw_text_rect(&item->pressure_rect, text, text_color);
    gdi_layer_set_active(item->base_handle);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_item_pen_proc
 * DESCRIPTION
 *  pen proc function of touch panel accuracy item
 * PARAMETERS
 *  param        [IN]
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static MMI_RET mmi_fm_tp_test_item_pen_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_touch_data_struct *touch_data;
    mmi_fm_tp_test_item_struct *item = (mmi_fm_tp_test_item_struct *)param->user_data;
    mmi_multi_touch_event_struct *evt = (mmi_multi_touch_event_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item->is_test_finish)
    {
        return MMI_RET_OK;
    }    
    if (EVT_ID_ON_TOUCH == param->evt_id && item->pen_hdlr_func)
    {
        touch_data = evt->touch_data; 
        if (item->pen_register & (0X01 << touch_data->event))
        {
            gui_lock_double_buffer();
            if (touch_data->merge_num > 0 && touch_data->merge_points)
            {
                U32 i;
                for (i = 0; i < touch_data->merge_num; i++)
                {
                    item->pen_hdlr_func(item->item_data,
                                    touch_data->event,
                                    &touch_data->merge_points[i].pos,
                                    touch_data->merge_area[i]);
                }
            }
            item->pen_hdlr_func(item->item_data,
                                    touch_data->event,
                                    &touch_data->currpos.pos,
                                    touch_data->area);
            if (item->is_fail == 1 && MMI_PEN_EVENT_UP == touch_data->event)
            {
                item->is_test_finish = 1;
                mmi_fm_tp_test_draw_result(0, &item->fail_position);      
            }
            else if (item->is_test_finish)
            {
                mmi_fm_tp_test_draw_result(1, &item->fail_position);
            }
            gdi_layer_set_blt_layer(item->base_handle, item->layer_handle, 0, 0);
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height- 1);
            
            #ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /*__MTK_INTERNAL__*/
            
        }        
    }
    return MMI_RET_OK;
}


/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_item_data_init
  * DESCRIPTION
  *  mmi_fm_tp_test_item_data_init
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_item_data_init(mmi_fm_tp_test_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->item_data = 0;
    item->is_fail = 0;
    item->is_test_finish = 0;
    
    gdi_layer_get_base_handle(&item->base_handle);
    switch (item->item_id)
    {
        case MENU_ID_FM_TOUCH_PANEL_LINER_TEST:
            mmi_fm_tp_test_liner_data_init(item);
            break;

        case MENU_ID_FM_TOUCH_PANEL_JITTER_TEST:
            mmi_fm_tp_test_jitter_data_init(item);
            break;

        default:
            MMI_ASSERT(0);
    }    
}

/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_item_draw_bg
  * DESCRIPTION
  *  mmi_fm_tp_test_item_draw_bg
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_item_draw_bg(mmi_fm_tp_test_item_struct * item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gdi_draw_solid_rect(0, 0, UI_device_width-1, UI_device_height-1, FM_TP_TEST_BG_COLOR);
    item->draw_bg_func(item->item_data);
    gdi_layer_set_blt_layer(item->base_handle, 0, 0, 0);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height- 1);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_item_set_hdlr
  * DESCRIPTION
  *  set key&pen handler
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_item_set_hdlr(mmi_fm_tp_test_item_struct * item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__    
    SetKeyHandler(mmi_fm_tp_test_goback, KEY_RSK, KEY_EVENT_UP);
#else   /*__COSMOS_MMI_PACKAGE__*/
	SetKeyHandler(mmi_fm_tp_test_goback, KEY_BACK, KEY_EVENT_UP);
#endif  /*__COSMOS_MMI_PACKAGE__*/ 

    mmi_frm_touch_set_mode(MMI_FRM_SINGLE_TOUCH);
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_2, MMI_PEN_SAMPLING_PERIOD_2);
    mmi_frm_touch_register_proc(mmi_fm_tp_test_item_pen_proc, item);    
}

/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_item_prepare
  * DESCRIPTION
  *  do anything to prepare test 
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_item_prepare(mmi_fm_tp_test_item_struct * item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->is_test_finish = 0;
    gui_set_font(&MMI_small_font);
    mmi_fm_tp_test_item_data_init(item);
    mmi_fm_tp_test_item_draw_bg(item);
    mmi_fm_tp_test_item_set_hdlr(item);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_item_draw_order_num
  * DESCRIPTION
  *  mmi_fm_tp_test_item_draw_order_num 
  * PARAMETERS
  *  x,y        [IN] where to draw
  *  number     [IN] the order number that to draw
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_item_draw_order_num(S32 x, S32 y, S32 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 text[MMI_FM_TP_TEST_TEXT_LEN];   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    kal_wsprintf(text,"%d", number);
    gui_set_text_color(FM_TP_TEST_TEXT_BG_COLOR);
    gui_move_text_cursor(x, y);
    gui_print_text(text);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_tp_test_item_draw_line_with_arrow
 * DESCRIPTION
 *  draw line with arrow
 * PARAMETERS
 *  p1          [IN]  start point
 *  p2          [IN]  end point
 *  color       [IN]  line color
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_fm_tp_test_item_draw_line_with_arrow(mmi_pen_point_struct *p1,
                                                        mmi_pen_point_struct *p2,
                                                        gdi_color color)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x_sqr;
    S32 y_sqr;
    S32 len_sqr;
    S32 len_p1_p2;
    mmi_pen_point_struct inter;
    mmi_pen_point_struct p3;
    mmi_pen_point_struct p4;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x_sqr = (p1->x - p2->x) * (p1->x - p2->x);
    y_sqr = (p1->y - p2->y) * (p1->y - p2->y);
    len_sqr = MMI_FM_TP_LINE_ARROW_LEN * MMI_FM_TP_LINE_ARROW_LEN;
    
    len_p1_p2 = mmi_fm_tp_test_get_len_two_point(p1, p2);
    inter.x = p2->x + (p1->x - p2->x) * MMI_FM_TP_LINE_ARROW_LEN / len_p1_p2;
    inter.y = p2->y + (p1->y - p2->y) * MMI_FM_TP_LINE_ARROW_LEN / len_p1_p2;

    if (x_sqr + y_sqr != 0)
    {
        p3.x = inter.x + (S32)sqrt((double)(len_sqr * y_sqr / (x_sqr + y_sqr)));
        p4.x = inter.x - (S32)sqrt((double)(len_sqr * y_sqr / (x_sqr + y_sqr)));
        if (p1->y != p2->y)
        {
            p3.y = inter.y - (p1->x - p2->x)*(p3.x - inter.x) / (p1->y - p2->y);
            p4.y = inter.y - (p1->x - p2->x)*(p4.x - inter.x) / (p1->y - p2->y);
        }
        else
        {
            p3.y = inter.y - MMI_FM_TP_LINE_ARROW_LEN;
            p4.y = inter.y + MMI_FM_TP_LINE_ARROW_LEN;
        }
        gdi_draw_line(p1->x, p1->y, p2->x, p2->y, color);
        gdi_draw_line(p3.x, p3.y, p2->x, p2->y, color);
        gdi_draw_line(p4.x, p4.y, p2->x, p2->y, color);   
    }     
}

/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_item_proc
  * DESCRIPTION
  *  mmi_fm_tp_test_item_proc
  * PARAMETERS
  *  param        [IN]
  * RETURNS
  *  MMI_RET 
  *****************************************************************************/
static MMI_RET mmi_fm_tp_test_item_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_tp_test_item_struct *test_item = (mmi_fm_tp_test_item_struct *)(param->user_data);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EVT_ID_GROUP_DEINIT == param->evt_id)
    {
        if (test_item)
        {
            if (test_item->item_data)
            {
                test_item->item_data = NULL;
            }
        }                
    }
    return MMI_RET_OK;
}


/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_item_exit_screen
  * DESCRIPTION
  *  mmi_fm_tp_test_item_exit_screen
  * PARAMETERS
  *  ess        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_item_exit_screen(mmi_scrn_essential_struct* ess)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_tp_test_item_struct *item = (mmi_fm_tp_test_item_struct *)(ess->user_data);
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item->data_deinit_func)
    {
        item->data_deinit_func(item->item_data);
    }
    if (item->item_data)
    {
        item->item_data = NULL;
    }
    if (item->layer_handle)
    {
        gdi_layer_free(item->layer_handle);
        item->layer_handle = 0;
    }
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_item_enter_screen
  * DESCRIPTION
  *  mmi_fm_tp_test_item_enter_screen
  * PARAMETERS
  *  ess        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_item_enter_screen(mmi_scrn_essential_struct* ess)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_tp_test_item_struct *item = (mmi_fm_tp_test_item_struct *)(ess->user_data);
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (! mmi_frm_scrn_enter(ess->group_id,
                    ess->scrn_id,
                    (FuncPtr)mmi_fm_tp_test_item_exit_screen, 
                    (FuncPtr)mmi_fm_tp_test_item_enter_screen,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    mmi_fm_tp_test_item_prepare(item);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_test_item_enter
  * DESCRIPTION
  *  mmi_fm_tp_test_item_enter
  * PARAMETERS
  *  parent_id      [IN]    parent group id
  *  item           [IN]    test item    
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_test_item_enter(MMI_ID parent_id, U32 item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_tp_test_item_struct *item;
    MMI_ID group_id;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = (mmi_fm_tp_test_item_struct*)&g_mmi_fm_tp_test_item;
    memset(item, 0, sizeof(mmi_fm_tp_test_item_struct));
    
    item->item_id = item_id;
    group_id = mmi_frm_group_create_ex(parent_id,
                                        GRP_ID_AUTO_GEN,
                                        mmi_fm_tp_test_item_proc,
                                        (void *)item,
                                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    item->group_id = group_id;
    
    mmi_frm_scrn_first_enter(group_id, 
                        SCR_ID_FM_TOUCH_PANEL, 
                        (FuncPtr)mmi_fm_tp_test_item_enter_screen,
                        item); 
}

#define TOUCH_PANEL
/*****************************************************************************
  * FUNCTION
  *  mmi_fm_tp_set_rect
  * DESCRIPTION
  *  mmi_fm_tp_set_rect
  * PARAMETERS
  *  rect           [IN]    
  *  x1             [IN]
  *  y1             [IN]
  *  w              [IN]
  *  h              [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_tp_set_rect(mmi_fm_tp_rect_struct *rect, U32 x1, U32 y1, U32 w, U32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(rect);
    rect->x1 = x1;
    rect->y1 = y1;
    rect->x2 = x1 + w;
    rect->y2 = y1 + w;
}

/*****************************************************************************
  * FUNCTION
  *  mmi_fm_touch_panel_select_hdlr
  * DESCRIPTION
  *  mmi_fm_touch_panel_select_hdlr
  * PARAMETERS
  *  evt            [IN]    cui menu event 
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_fm_touch_panel_select_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->highlighted_menu_id == MENU_ID_FM_TOUCH_PANEL_LINER_TEST || 
                    evt->highlighted_menu_id == MENU_ID_FM_TOUCH_PANEL_JITTER_TEST);
    group_id = mmi_frm_group_get_active_id();    
    mmi_fm_tp_test_item_enter(group_id, evt->highlighted_menu_id);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_fm_touch_panel_proc
  * DESCRIPTION
  *  mmi_fm_touch_panel_proc
  * PARAMETERS
  *  param            [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static MMI_RET mmi_fm_touch_panel_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_fm_touch_panel_select_hdlr(evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(evt->sender_id);
            break;

        default:
            break;        
    }
    return MMI_RET_OK;
}

/*****************************************************************************
  * FUNCTION
  *  mmi_fm_touch_panel_entry
  * DESCRIPTION
  *  mmi_fm_touch_panel_entry
  * PARAMETERS
  *  void
  * RETURNS
  *  void 
  *****************************************************************************/
extern void mmi_fm_touch_panel_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_FM_ROOT))
    {
        mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_FM_ROOT,NULL, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }   

    group_id = mmi_frm_group_create_ex(GRP_ID_FM_ROOT,
                             GRP_ID_FM_TOUCH_PANEL,
                             mmi_fm_touch_panel_proc,
                             NULL,
                             MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_menu_create_and_run(group_id, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_APPSUB, 
                            MENU_ID_FM_TOUCH_PANEL, 
                            MMI_TRUE, 
                            0);
#if defined(__COSMOS_MMI_PACKAGE__)
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
#endif /*__COSMOS_MMI_PACKAGE__*/
}


/*****************************************************************************
  * FUNCTION
  *  mmi_fm_highlight_touch_screen
  * DESCRIPTION
  *  mmi_fm_highlight_touch_screen
  * PARAMETERS
  *  void
  * RETURNS
  *  void 
  *****************************************************************************/
void mmi_fm_highlight_touch_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_fm_touch_panel_entry, KEY_EVENT_UP);


    #ifndef __COSMOS_MMI_PACKAGE__    
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_RSK, KEY_EVENT_UP);
    #else   /*__COSMOS_MMI_PACKAGE__*/
	SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
    #endif  /*__COSMOS_MMI_PACKAGE__*/ 
    
    mmi_fm_common_set_left_softkey(STR_GLOBAL_OK);
}

#endif /*__MMI_FM_TOUCH_PANEL_ACCURACY_TEST__*/
#endif  /* __MMI_FACTORY_MODE__*/
#if (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__))
#pragma arm section rodata , code
#endif /* (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)) */
