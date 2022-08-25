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
 *  EngineerModeTouchPanel.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode Touch Pannel related items, 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_EM_MISC_TOUCH_SCREEN__)
#include "kal_general_types.h"
#include "Dcl.h"
#include "math.h"
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "Gdi_include.h"
#include "gui_themes.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "Gui.h"
#include "wgui_categories_util.h"
#include "Inlinecuigprot.h"
#include "Menucuigprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeUtil.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "EngineerModeTouchPanel.h"


#if !defined(__MTK_TARGET__) && defined(__MTK_INTERNAL__) 
/* under construction !*/
#endif

#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 


#if defined(__MMI_EM_TP_UT__)
void mmi_em_tp_log_dprintf(char *fmt, ...)
{
    va_list l;
    char buf[1024];    
    va_start(l, fmt);        
    vsprintf(buf, fmt, l);

#ifndef __MTK_TARGET__
    kal_print(buf);
#endif
}


void mmi_em_tp_test()
{
    U32 i;
    DCL_HANDLE handle;
    DCL_CTRL_MICRONMETER_COORD_T data;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DclSTS_Open(DCL_TS, 0);
    memset(&data, 0, sizeof(DCL_CTRL_MICRONMETER_COORD_T));

    for(i = 1; i<= 4; i++)
    {
        data.x_coord = UI_device_width * i / 4;
        data.y_coord = UI_device_height * i / 4;
    
        DclSTS_Control(handle, STS_CMD_CTRL_COORD_TO_MICRONMETER, (DCL_CTRL_DATA_T*)&data);
        mmi_em_tp_log_dprintf("from pixel to um:((w_pixel, h_pixel), (w_um, h_um)) = ((%d, %d), (%d, %d))", data.x_coord, data.y_coord, data.x_micronmeter, data.y_micronmeter);

        data.x_coord = 0;
        data.y_coord = 0;
        DclSTS_Control(handle, STS_CMD_CTRL_MICRONMETER_TO_COORD, (DCL_CTRL_DATA_T*)&data);
        mmi_em_tp_log_dprintf("from um to pixel:((w_pixel, h_pixel), (w_um, h_um)) = ((%d, %d), (%d, %d))", data.x_coord, data.y_coord, data.x_micronmeter, data.y_micronmeter);
    }
}
#endif /*__MMI_EM_TP_UT__*/


  
/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define EM_TOUCH_SCREEN_PARAM_SETTING
#define EM_TP_ABSSUB(a, b)  (((a) > (b))? ((a) - (b)) : ((b) - (a)))
#define EM_TP_MIN(a, b)     ((a) < (b) ? (a) : (b))
#define EM_TP_MAX(a, b)     ((a) < (b) ? (b) : (a))


#define EM_TP_PARAM_SETTING_TITLE_LEN           32
#define EM_TP_PARAM_SETTING_EDIT_BUFFER_LEN     10
#define EM_TP_PARAM_SETTING_ITEM_NUM            16

/*inline items */
#define EM_TP_PARAM_SETTING_INLINE_CAPTION  (CUI_INLINE_ITEM_ID_BASE + 1)
#define EM_TP_PARAM_SETTING_INLINE_EDIT     (CUI_INLINE_ITEM_ID_BASE + 2)

#define EM_TP_ACC_TEXT_LEN                      32
#define EM_TP_ACC_LINE_ARROW_LEN                10
#define EM_TP_ACC_BG_COLOR                      GDI_COLOR_WHITE
#define EM_TP_ACC_LINE_BG_COLOR                 GDI_COLOR_BLACK
#define EM_TP_ACC_LINE_FG_COLOR                 GDI_COLOR_RED
#define EM_TP_ACC_CIRCLE_BG_COLOR               GDI_COLOR_BLACK
#define EM_TP_ACC_CIRCLE_FG_COLOR               GDI_COLOR_RED
#define EM_TP_ACC_TRANSPARENT_COLOR             GDI_COLOR_BLUE
#define EM_TP_ACC_TEXT_BG_COLOR                 gui_color(0,255,0)
#define EM_TP_ACC_TEXT_FG_COLOR                 gui_color(255,0,0)
#define EM_TP_ACC_TEXT_ERROR_COLOR              gui_color(255,0,0)
#define EM_TP_ACC_CIRCLE_FG_R                   2
#define EM_TP_ACC_FAIL_LEN                      5
#define EM_TP_ACC_FAIL_COLOR                    GDI_COLOR_RED

#define EM_TP_ACC_PASS_CRETIRION_LINE_COLOR     gdi_act_color_from_rgb(255, 199, 53, 202)
/* pen event registe, if item registe, item will receive pen event corresponding*/
#define EM_TP_ACC_PEN_DOWN_REG                  0X0001
#define EM_TP_ACC_PEN_MOVE_REG                  0X0002
#define EM_TP_ACC_PEN_REPEAT_REG                0X0004
#define EM_TP_ACC_PEN_UP_REG                    0X0008

#define EM_TP_ACC_TEST1_CIRCLE_NUM              13
#define EM_TP_ACC_TEST1_BORDER_WIDTH_UM         5000
#define EM_TP_ACC_TEST1_SEG_NUM                 4
#define EM_TP_ACC_TEST1_PEN_POINT_R             2

#define EM_TP_ACC_LINEAR_HORIZ_LINE_NUMBER      9 
#define EM_TP_ACC_LINEAR_VER_LINE_NUMBER        9
#define EM_TP_ACC_CIRCUIT_LINE_NUMBER           1
//#define EM_TP_ACC_CIRCUIT_SEG_LEN               10000
#define EM_TP_ACC_RECT_LINE_NUMBER              1
#define EM_TP_ACC_FUNNEL_LINE_NUMBER            1
#define EM_TP_ACC_DUAL_RECT_LINE_NUMBER         1
//#define EM_TP_ACC_JITTER_PITCH_LEN              10000

#define EM_TP_ACC_PEN_POINT_R                   2
#define EM_TP_ACC_PRESSURE_VALUE                1000

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
typedef enum
{
    TP_ACC_PEN_DOWN = 0,
    TP_ACC_PEN_MOVE,
    TP_ACC_PEN_UP,
    TP_ACC_PEN_REPEATE,
    
    TP_ACC_PEN_TYPE_END_OF_ENUM 
}em_tp_acc_pen_type_enum;

typedef enum
{
    TP_ACC_LINE_LEFT = 0,
    TP_ACC_LINE_RIGHT,
    TP_ACC_LINE_UP,
    TP_ACC_LINE_DOWN,
    
    TP_ACC_LINE_DIRECTION_END_OF_ENUM 
}em_tp_acc_line_direction_enum;



typedef enum
{
    TP_CIRCUIT_START = 1,
    TP_CIRCUIT_UP,
    TP_CIRCUIT_RIGHT,
    TP_CIRCUIT_DOWN,
    TP_CIRCUIT_LEFT,
    TP_CIRCUIT_UP_RIGHT,
    TP_CIRCUIT_RIGHT_DOWN,
    TP_CIRCUIT_DOWN_LEFT,
    TP_CIRCUIT_LEFT_UP,
    
    TP_CIRCUIT_DIRECTION_END_OF_ENUM    
}em_tp_acc_circuit_direction_enum;


/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef void (* em_tp_pen_hdlr) (void *, em_tp_acc_pen_type_enum, mmi_pen_point_struct, U32);
typedef void (* em_tp_data_deinit) (void *);
typedef void (* em_tp_draw_bg) (void *);

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
    U16 x;      /* position x */
    U16 y;      /* position y */
}em_tp_point_struct;

typedef struct
{
    U16 cx;      
    U16 cy;
    U32 r;
}em_tp_circle_struct;


typedef struct
{
    mmi_pen_point_struct p1;
    mmi_pen_point_struct p2;
    mmi_pen_point_struct p3;
}em_tp_triple_struct;


typedef struct
{
    S16 x1;
    S16 y1;
    S16 x2;
    S16 y2;    
}em_tp_rect_struct;

typedef struct
{
    S32 min;
    S32 max;
}em_tp_param_setting_item_range;

typedef struct
{
    U16     current_item;
    U16     caption[EM_TP_PARAM_SETTING_TITLE_LEN];
    U16     text_buffer[EM_TP_PARAM_SETTING_EDIT_BUFFER_LEN];
    MMI_ID  group_id;
    TouchPanel_EM_custom_data_struct custom_data;      /*  item value */
    TP_PARAM_RANGE param_range;                        /*item value range */
 }em_tp_param_setting_struct;

typedef struct
{    
    U16         item_id;
    U16         is_auto_test;
    U16         is_test_finish;
    U16         is_error_happen;
    U16         cur_index;
    U16         pen_num;
    
    U16         layer_offset_x;
    U16         layer_offset_y;
    U16         layer_width;
    U16         layer_height;
    gdi_handle  layer_handle;
    
    U32         pen_register;
    S32         character_h;    
    MMI_ID      group_id; 
    void        *item_data;
    S32         fail_distance;

    U32                 dump_screen;
    em_tp_point_struct  fail_rigion;
    mmi_pen_point_struct  fail_position;
    em_tp_rect_struct   coordinate_rect;
    em_tp_rect_struct   pressure_rect; 
    
    em_tp_pen_hdlr      pen_hdlr_func;
    em_tp_draw_bg       draw_bg_func;
    em_tp_data_deinit   data_deinit_func;
}em_tp_acc_item_struct;

typedef struct
{    
    U32         border_range;
    U32         border_pass_criterion;
    U32         non_border_pass_criterion;

    em_tp_acc_item_struct   *parent; 
    em_tp_circle_struct     circles[EM_TP_ACC_TEST1_CIRCLE_NUM];
    em_tp_point_struct      nums[EM_TP_ACC_TEST1_CIRCLE_NUM];   
}em_tp_acc_test1_struct;

typedef struct
{   
    S32     non_border_pass_criterion;

    em_tp_acc_item_struct   *parent; 
    mmi_pen_point_struct    last_point; 
}em_tp_acc_linear_slope_struct;

typedef struct
{  
    S16         gap_width;  
    S32         non_border_pass_criterion;

    em_tp_acc_item_struct   *parent; 
    mmi_pen_point_struct    last_point;  
}em_tp_acc_linear_ver_struct;

typedef struct
{   
    S16     gap_height;  
    S32     non_border_pass_criterion;   

    em_tp_acc_item_struct   *parent; 
    mmi_pen_point_struct    last_point; 
}em_tp_acc_linear_horiz_struct;

typedef struct
{   
    U16         border_width;
    U16         border_height; 
    U16         x_num;
    U16         y_num;
    U16         pitch_x;
    U16         pitch_y;
    U32         last_index;
    U8          *line_direction;  
    S32         non_border_pass_criterion;

    em_tp_acc_item_struct   *parent; 
    mmi_pen_point_struct    last_point;        
}em_tp_acc_circuit_struct;

typedef struct
{   
    S32     non_border_pass_criterion;  

    em_tp_acc_item_struct   *parent; 
    mmi_pen_point_struct    last_point;
    em_tp_rect_struct       line_rect; 
}em_tp_acc_rect_struct;

typedef struct
{   
    S32 non_border_pass_criterion;

    em_tp_acc_item_struct   *parent; 
    mmi_pen_point_struct    last_point;
    em_tp_rect_struct       line_area_rect;  
}em_tp_acc_funnel_struct;

typedef struct
{   
    S32     non_border_pass_criterion;

    em_tp_acc_item_struct   *parent; 
    mmi_pen_point_struct last_point;
    mmi_pen_point_struct   line_area_points[6];
    em_tp_rect_struct    border_rect;
}em_tp_acc_dual_rect_struct;

typedef struct
{   
    U16         cur_point;
    U16         num_point;
    U16         num_x;
    U16         num_y;
    U16         pitch_x;
    U16         pitch_y;    
    S32         border_range;
    S32         border_pass_criterion;
    S32         non_border_pass_criterion;  

    em_tp_acc_item_struct   *parent; 
    em_tp_circle_struct     *circles_ptr;    
}em_tp_acc_jitter_struct;

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef void (* em_tp_data_init) (em_tp_acc_item_struct *);
 

#define STATIC_FUNCTION
/***************************************************************************** 
 * Static function 
 *****************************************************************************/ 
static void mmi_em_tp_param_setting_inline_submit_hdlr(cui_event_inline_submit_struct *submit); 
static void mmi_em_tp_param_setting_init_inline_items_value(mmi_id inline_id, 
                                                 em_tp_param_setting_struct* param_setting); 
static void mmi_em_tp_param_setting_construct_inline_editor(cui_inline_struct* inline_struct, 
                                                             U16 menu_id);
static void mmi_em_tp_get_param_range(TP_PARAM_RANGE *param_range);
static void mmi_em_tp_get_param_item_range(TP_PARAM_RANGE *range,U32 item, kal_int32 *min, kal_int32 *max);

static MMI_BOOL mmi_em_tp_is_ctp(void);
static void mmi_em_tp_param_setting_hide_rtp_items(MMI_ID cui_menu_id);
static void mmi_em_tp_ctrl_custom_data(TouchPanel_EM_custom_data_struct *custom_data,
                                        TP_CTRL_PARAM_TYPE type);
static void mmi_em_tp_ctrl_custom_data_item(TouchPanel_EM_custom_data_struct *custom_data, 
                                            U32 item,
                                            kal_uint32 *value,
                                            TP_CTRL_PARAM_TYPE type);
static void mmi_em_tp_param_setting_select_hdlr(mmi_event_struct *param);
static void mmi_em_tp_param_setting_fill_inline_item(MMI_ID inline_id);
static MMI_RET mmi_em_tp_param_setting_proc(mmi_event_struct *param);
static MMI_RET mmi_em_tp_param_setting_inline_proc(mmi_event_struct *param);

#define ACC_TEST_ITEM
static void mmi_em_tp_acc_item_enter(MMI_ID parent_id, U32 item);
static void mmi_em_tp_acc_item_enter_screen(mmi_scrn_essential_struct* ess);
static void mmi_em_tp_acc_item_exit_screen(mmi_scrn_essential_struct* ess);
static MMI_RET mmi_em_tp_acc_item_proc(mmi_event_struct *param);
static void mmi_em_tp_acc_item_data_init(em_tp_acc_item_struct *item);
static void mmi_em_acc_item_data_deinit(em_tp_acc_item_struct *item);
static void mmi_em_tp_acc_item_draw_bg(em_tp_acc_item_struct *item);
static void mmi_em_tp_acc_item_set_hdlr(em_tp_acc_item_struct * item);
static void mmi_em_tp_acc_item_prepare(em_tp_acc_item_struct * item);
static MMI_RET mmi_em_tp_acc_item_pen_proc(mmi_event_struct *param);
static void mmi_em_tp_acc_item_rsk_hdlr(void);
static void mmi_em_tp_acc_item_test_next(em_tp_acc_item_struct *item);
static void mmi_em_tp_acc_item_test_finish_hdlr(em_tp_acc_item_struct *item);
static void mmi_em_tp_acc_item_draw_error(MMI_ID parent_id, U16* error_string);
static void mmi_em_tp_acc_item_general_pen_hdlr(mmi_pen_point_struct* last_point, 
                                                mmi_pen_point_struct* now_point,
                                                em_tp_acc_pen_type_enum pen_type);
static void mmi_em_tp_acc_item_draw_pass_cretirion_line(S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_em_tp_acc_item_draw_pass_cretirion_rect(S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_em_tp_acc_item_draw_pass_cretirion_triple(em_tp_triple_struct *pTri);



#define TEST_1_ACCURACY
static void mmi_em_tp_acc_test1_data_init(em_tp_acc_item_struct *item);
static void mmi_em_tp_acc_test1_draw_bg(void *item_data);
static void mmi_em_tp_acc_test1_pen_hdlr(void *item_data, 
                                em_tp_acc_pen_type_enum  pen_type, 
                                mmi_pen_point_struct pos,
                                U32 pressure);
static void mmi_em_tp_acc_test1_verify(em_tp_acc_test1_struct *context, mmi_pen_point_struct pos);


#define  TEST_2_SLOPE
static void mmi_em_tp_acc_linear_slope_data_init(em_tp_acc_item_struct * item);
static void mmi_em_tp_acc_linear_slope_draw_bg(void *item_data);

static void mmi_em_tp_acc_linear_slope_pen_hdlr(void *item_data,
                                                em_tp_acc_pen_type_enum pen_type,
                                                mmi_pen_point_struct pos,
                                                U32 pressure);

static void mmi_em_tp_acc_linear_slope_verify(em_tp_acc_linear_slope_struct *context,
                                                mmi_pen_point_struct pos,
                                                em_tp_acc_pen_type_enum pen_type);
static void mmi_em_tp_acc_linear_slope_draw_criterion_lines(em_tp_acc_linear_slope_struct *context);


#define TEST_3_HORIZONTAL
static void mmi_em_tp_acc_linear_ver_data_init(em_tp_acc_item_struct * item);
static void mmi_em_tp_acc_linear_ver_draw_bg(void *item_data);
static void mmi_em_tp_acc_linear_ver_pen_hdlr(void *item_data,
                                                em_tp_acc_pen_type_enum pen_type,
                                                mmi_pen_point_struct pos,
                                                U32 pressure);
static void mmi_em_tp_acc_linear_ver_verify(em_tp_acc_linear_ver_struct *context,
                                                mmi_pen_point_struct pos,
                                                em_tp_acc_pen_type_enum pen_type);



#define TEST_4_VERTICAL
static void mmi_em_tp_acc_linear_horiz_data_init(em_tp_acc_item_struct * item);
static void mmi_em_tp_acc_linear_horiz_draw_bg(void *item_data);
static void mmi_em_tp_acc_linear_horiz_pen_hdlr(void *item_data,
                                            em_tp_acc_pen_type_enum pen_type,
                                            mmi_pen_point_struct pos,
                                            U32 pressure);
static void mmi_em_tp_acc_linear_horiz_verify(em_tp_acc_linear_horiz_struct *context,
                                                mmi_pen_point_struct pos,
                                                em_tp_acc_pen_type_enum pen_type);

#define TEST_5_CIRCUIT
static void mmi_em_tp_acc_circuit_data_init(em_tp_acc_item_struct * item);
static void mmi_em_tp_acc_circuit_data_deinit(void *item_data);
static void mmi_em_tp_acc_circuit_draw_bg(void *item_data);
static void mmi_em_tp_acc_circuit_pen_hdlr(void *item_data,
                                            em_tp_acc_pen_type_enum pen_type,
                                            mmi_pen_point_struct pos,
                                            U32 pressure);
static void mmi_em_tp_acc_circuit_verify(em_tp_acc_circuit_struct *context, 
                                            mmi_pen_point_struct pos,
                                            em_tp_acc_pen_type_enum pen_type);
static MMI_BOOL mmi_em_tp_acc_circuit_is_implented(U8* rect, U32 num_x, U32 num_y, S32 x, S32 y);
static void mmi_em_tp_acc_circuit_implent_rect(em_tp_acc_circuit_struct *context);


#define TEST_6
static void mmi_em_tp_acc_rect_data_init(em_tp_acc_item_struct * item);
static void mmi_em_tp_acc_rect_draw_bg(void *item_data);
static void mmi_em_tp_acc_rect_pen_hdlr(void *item_data,
                                        em_tp_acc_pen_type_enum pen_type,
                                        mmi_pen_point_struct pos,
                                        U32 pressure);
static void mmi_em_tp_acc_rect_verify(em_tp_acc_rect_struct *context,
                                        mmi_pen_point_struct pos,
                                        em_tp_acc_pen_type_enum pen_type);
static void mmi_em_tp_acc_rect_draw_criterion_lines(em_tp_acc_rect_struct *context);

#define TEST_7
static void mmi_em_tp_acc_funnel_data_init(em_tp_acc_item_struct * item);
static void mmi_em_tp_acc_funnel_draw_bg(void *item_data);
static void mmi_em_tp_acc_funnel_pen_hdlr(void *item_data,
                                            em_tp_acc_pen_type_enum pen_type,
                                            mmi_pen_point_struct pos,
                                            U32 pressure);
static void mmi_em_tp_acc_funnel_verify(em_tp_acc_funnel_struct *context,
                                                mmi_pen_point_struct pos,
                                                em_tp_acc_pen_type_enum pen_type);
static void mmi_em_tp_acc_funnel_draw_criterion_lines(em_tp_acc_funnel_struct *context);


#define TEST_8_DUAL_RECT
static void mmi_em_tp_acc_dual_rect_data_init(em_tp_acc_item_struct * item);
static void mmi_em_tp_acc_dual_rect_draw_bg(void *item_data);
static void mmi_em_tp_acc_dual_rect_pen_hdlr(void *item_data,
                                            em_tp_acc_pen_type_enum pen_type,
                                            mmi_pen_point_struct pos,
                                            U32 pressure);
static void mmi_em_tp_acc_dual_rect_verify(em_tp_acc_dual_rect_struct *context, 
                                            mmi_pen_point_struct pos,
                                            em_tp_acc_pen_type_enum pen_type);
static void mmi_em_tp_acc_dual_rect_draw_criterion_lines(em_tp_acc_dual_rect_struct *context);
     

#define TEST_9_JITTER
static void mmi_em_tp_acc_jitter_data_init(em_tp_acc_item_struct * item);
static void mmi_em_tp_acc_jitter_data_deinit(void *item_data);
static void mmi_em_tp_acc_jitter_draw_bg(void *item_data);
static void mmi_em_tp_acc_jitter_pen_hdlr(void *item_data,
                                            em_tp_acc_pen_type_enum pen_type,
                                            mmi_pen_point_struct pos,
                                            U32 pressure);
static void mmi_em_tp_acc_jitter_verify(em_tp_acc_jitter_struct *context, 
                                            mmi_pen_point_struct pos);


#define TEST_ACCURACY
static void mmi_em_tp_acc_draw_text_rect(em_tp_rect_struct *text_rect, 
                                        U16 *text, 
                                        U32 bg_color, 
                                        MMI_BOOL is_need_bg_color);
static void mmi_em_tp_acc_draw_line_direction(S32 x1, 
                                            S32 y1, 
                                            S32 x2, 
                                            S32 y2, 
                                            gdi_color color, 
                                            em_tp_acc_line_direction_enum direction);

static void mmi_em_tp_acc_draw_position_and_pressure(em_tp_acc_item_struct* item,
                                                        mmi_pen_point_struct *pos,
                                                        S32  pressure,
                                                        U32  bg_color);
static void mmi_em_tp_acc_draw_text(U16* text, S32 x, S32 y, color text_color);
static void mmi_em_tp_acc_draw_result(em_tp_acc_item_struct *item);
static void mmi_em_tp_acc_draw_int(U32 x, U32 y, U32 value);
static void mmi_em_tp_acc_set_rect(em_tp_rect_struct *rect, U32 x1, U32 y1, U32 x2, U32 y2);
#if 0
/* under construction !*/
/* under construction !*/
#endif
static U32 mmi_em_tp_acc_get_pixel_from_um(U32 width_um);
static U32 mmi_em_tp_acc_get_um_from_pixel(U32 width_pixel);
static void mmi_em_tp_accucary_test_select_hdlr(mmi_event_struct *param);
static MMI_RET mmi_em_tp_accuracy_proc(mmi_event_struct *param);


#ifdef __MMI_EM_TP_UT_ON_MODIS__
static void mmi_em_tp_ctrl_custom_data_on_modis(TouchPanel_EM_custom_data_struct *custom_data,
                                        TP_CTRL_PARAM_TYPE type);
static void mmi_em_tp_get_param_range_on_modis(TP_PARAM_RANGE *param_range);
static U32 mmi_em_tp_acc_get_pixel_from_um_on_modis(U32 width_um);
static U32 mmi_em_tp_acc_get_um_from_pixel_on_modis(U32 width_pixel);
#endif /*__MMI_EM_TP_UT_ON_MODIS__*/

/*----------------------------------------------------------------------------*/
/* extern function                                                            */
/*----------------------------------------------------------------------------*/
extern void tst_dump_gdi_snapshot(kal_uint32 tokey);


/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

const em_tp_data_init g_data_init_func[] = { 
            NULL,
            mmi_em_tp_acc_test1_data_init,
            mmi_em_tp_acc_linear_slope_data_init,
            mmi_em_tp_acc_linear_horiz_data_init,
            mmi_em_tp_acc_linear_ver_data_init,
            mmi_em_tp_acc_circuit_data_init,
            mmi_em_tp_acc_rect_data_init,
            mmi_em_tp_acc_funnel_data_init,
            mmi_em_tp_acc_dual_rect_data_init,
            mmi_em_tp_acc_jitter_data_init
            };




/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_param_setting_inline_submit_hdlr
  * DESCRIPTION
  *  touch panel parameter setting inline submit handler  
  * PARAMETERS
  *  submit      [IN] 
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_param_setting_inline_submit_hdlr(cui_event_inline_submit_struct *submit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR  acsii_value[EM_TP_PARAM_SETTING_EDIT_BUFFER_LEN];
    WCHAR ucs2_value[EM_TP_PARAM_SETTING_EDIT_BUFFER_LEN];
    kal_int32 min;
    kal_int32 max;
    kal_int32 value;
    em_tp_param_setting_struct *param_setting;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_setting = (em_tp_param_setting_struct *)submit->user_data;
    cui_inline_get_value(submit->sender_id, EM_TP_PARAM_SETTING_INLINE_EDIT, ucs2_value);
    mmi_ucs2_to_asc(acsii_value, (CHAR*) ucs2_value);
    if (0 == acsii_value[0])
    {
		value = 0;
    }
    else
    {
		value = atoi(acsii_value);
    }    
    mmi_em_tp_get_param_item_range(&(param_setting->param_range), param_setting->current_item, &min, &max);

    /*if the value exceed the range, change it to the min or the max*/
    if ( value < min)
    {
        value = min;
    }
    else if (value > max)
    {
        value = max;
    }
    mmi_em_tp_ctrl_custom_data_item(&(param_setting->custom_data), param_setting->current_item, &value, TP_PARAM_SET);
    mmi_em_tp_ctrl_custom_data(&(param_setting->custom_data), TP_PARAM_SET);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_param_setting_inline_proc
  * DESCRIPTION
  *  touch panel parameter setting inline proc 
  * PARAMETERS
  *  param      [IN] 
  * RETURNS
  *  MMI_ID 
  *****************************************************************************/
static MMI_RET mmi_em_tp_param_setting_inline_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
            {
                cui_event_inline_submit_struct *evt = (cui_event_inline_submit_struct *)param;
                mmi_em_tp_param_setting_inline_submit_hdlr(evt);
                cui_inline_close(evt->sender_id);
                break;
            }            

        case EVT_ID_CUI_INLINE_ABORT:
            {
                cui_event_inline_abort_struct *evt = (cui_event_inline_abort_struct *)param;
                cui_inline_close(evt->sender_id);
                break;
            }            

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_param_setting_construct_inline_editor
  * DESCRIPTION
  *  touch panel parameter setting construct inlien editor
  * PARAMETERS
  *  inline_struct      [IN]
  *  menu_id            [IN] touch panel parameter setting menu id, 
  *                         diffrent menu id construct diffrent inline title 
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_param_setting_construct_inline_editor(cui_inline_struct* inline_struct, 
                                                             U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    index = menu_id - MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DEBOUNCE_TIME;    
    inline_struct->title = index + STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DEBOUNCE_TIME;    
    inline_struct->items_count = 0;
    inline_struct->title_icon = 0;
    inline_struct->screen_flag = CUI_INLINE_SCREEN_DISABLE_DONE | CUI_INLINE_SCREEN_LOOP;
    inline_struct->softkey = NULL;
    inline_struct->items = NULL;
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_param_setting_fill_inline_item
  * DESCRIPTION
  *  touch panel parameter setting fill inlien item
  * PARAMETERS
  *  inline_id      [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_param_setting_fill_inline_item(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_item_caption_struct item_cap;
    cui_inline_item_text_edit_struct item_text = {0};
    cui_inline_set_item_struct  item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    item_cap.string_id = 0;
    item.item_id = EM_TP_PARAM_SETTING_INLINE_CAPTION;
    item.item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    item.item_data = &item_cap;
    item.image_id = 0;
    cui_inline_insert_item(inline_id, CUI_INLINE_INSERT_TAIL, &item);

    item_text.buffer_size = EM_TP_PARAM_SETTING_EDIT_BUFFER_LEN;        
    item_text.input_type = IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC;
    item.image_id = 0;
    item.item_id = EM_TP_PARAM_SETTING_INLINE_EDIT;
    item.item_data = (void*)&item_text;
    item.item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
    cui_inline_insert_item(inline_id, CUI_INLINE_INSERT_TAIL, &item);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_param_setting_change_inline_caption_string
  * DESCRIPTION
  *  touch panel parameter setting fill inlien item
  * PARAMETERS
  *  inline_id      [IN]
  *  param_setting  [IN] 
  *                      
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_param_setting_init_inline_items_value(MMI_ID inline_id,
                                        em_tp_param_setting_struct   *param_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 min;
    kal_int32 max;
    kal_uint32 item_value;
    TP_PARAM_RANGE *range = &(param_setting->param_range);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_em_tp_get_param_item_range(range, param_setting->current_item, &min, &max);

    switch (param_setting->current_item)
    {
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DEBOUNCE_TIME:
            kal_wsprintf((WCHAR *)param_setting->caption, 
                            "%w%d~%d ms", 
                            get_string(STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RANGE),
                            min, 
                            max);            
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_CALIB_CHECK_OFFSET:
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_HIGN_THRESHOLD:
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_CHECK_BOUNDARY:
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_SHIFTING:
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_1:
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_2:
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_3:
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DUMP_SCREEN:
            kal_wsprintf((WCHAR *)param_setting->caption, 
                            "%w%d~%d", 
                            get_string(STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RANGE),
                            min, 
                            max);
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_BORDER_PASS_CRITERION:
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_NON_BORDER_PASS_CRITERION:
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_BORDER_RANGE:
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_ITEM_INTERVAL:
            kal_wsprintf((WCHAR *)param_setting->caption, 
                            "%w%d~%d um",
                            get_string(STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RANGE),
                            min, 
                            max);            
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MIN_PEN_MOVE_OFFSET:
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_HANDWRITE_OFFSET:
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_NON_HANDWRITE_OFFSET: 
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_STROKE_OFFSET:
             kal_wsprintf((WCHAR *)param_setting->caption,
                            "%w%d~%d pixel",
                            get_string(STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RANGE),
                            min, 
                            max);
             break;
             
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MULTI_POING_SELECTION:
            kal_wsprintf((WCHAR *)param_setting->caption,
                            "%w%d~%d points",
                            get_string(STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RANGE),
                            min, 
                            max);
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }       
    cui_inline_set_value(inline_id, EM_TP_PARAM_SETTING_INLINE_CAPTION, param_setting->caption);
    mmi_em_tp_ctrl_custom_data_item(&(param_setting->custom_data), 
										param_setting->current_item,
										&item_value,
										TP_PARAM_GET);
    kal_wsprintf((WCHAR *)param_setting->text_buffer, "%d", item_value);
    cui_inline_set_value(inline_id, EM_TP_PARAM_SETTING_INLINE_EDIT, param_setting->text_buffer);   
}



/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_param_setting_hilite_hdlr
  * DESCRIPTION
  *  touch panel parameter setting item hight light handler
  * PARAMETERS
  *  param        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_param_setting_hilite_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     
    U16 hilite[EM_TP_PARAM_SETTING_EDIT_BUFFER_LEN];
    kal_uint32 value; 
    em_tp_param_setting_struct *param_setting; 
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;   
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->highlighted_menu_id >= MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DEBOUNCE_TIME&&
         evt->highlighted_menu_id <= MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_3);
        param_setting = (em_tp_param_setting_struct *)param->user_data;       
        mmi_em_tp_ctrl_custom_data_item(&param_setting->custom_data, evt->highlighted_menu_id, &value, TP_PARAM_GET);
        mmi_wcs_itow(value, (WCHAR*)hilite, 10);
        cui_menu_set_item_hint(evt->sender_id, evt->highlighted_menu_id, hilite);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_param_setting_select_hdlr
  * DESCRIPTION
  *  touch panel parameter setting item select handler
  * PARAMETERS
  *  param        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_param_setting_select_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id, inline_id;
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
    em_tp_param_setting_struct *param_setting;
    cui_inline_struct inline_struct;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->highlighted_menu_id >= MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DEBOUNCE_TIME&&
         evt->highlighted_menu_id <= MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_3);
    
    {
        param_setting = (em_tp_param_setting_struct *)param->user_data;
        param_setting->current_item = evt->highlighted_menu_id;
        
        group_id = mmi_frm_group_create_ex(param_setting->group_id, 
                                    GRP_ID_AUTO_GEN, 
                                    mmi_em_tp_param_setting_inline_proc, 
                                    param_setting,
                                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    
        mmi_em_tp_param_setting_construct_inline_editor(&inline_struct, evt->highlighted_menu_id);
        inline_id = cui_inline_create(group_id, &inline_struct);        
        mmi_em_tp_param_setting_fill_inline_item(inline_id);
        mmi_em_tp_param_setting_init_inline_items_value(inline_id, param_setting);
        cui_inline_run(inline_id);
    }
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_param_setting_proc
  * DESCRIPTION
  *  touch panel parameter setting proc (cui menu proc)
  * PARAMETERS
  *  param        [IN]
  * RETURNS
  *  MMI_RET 
  *****************************************************************************/
static MMI_RET mmi_em_tp_param_setting_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
    em_tp_param_setting_struct *param_setting;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            {
                if (param->user_data)
                {
                    param_setting = (em_tp_param_setting_struct *)param->user_data;
				    mmi_em_tp_ctrl_custom_data(&(param_setting->custom_data), TP_PARAM_SET);
                    MMI_EM_FREE(param->user_data);
                }
                break;
            }

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            mmi_em_tp_param_setting_hilite_hdlr(param);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_em_tp_param_setting_select_hdlr(param);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
//            param_setting = (em_tp_param_setting_struct *)param->user_data;
//            mmi_em_tp_ctrl_custom_data(&(param_setting->custom_data), TP_PARAM_SET);
            cui_menu_close(evt->sender_id);
            break;

        default:
            break;        
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_is_ctp
 * DESCRIPTION
 *  current touch panel is ctp
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL        return MMI_TRUE if ctp, or return MMI_FALSE
 *****************************************************************************/
static MMI_BOOL mmi_em_tp_is_ctp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    DCL_HANDLE handle;
    DCL_TP_TYPE_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    memset(&data, 0, sizeof(DCL_TP_TYPE_T));
    handle = DclSTS_Open(DCL_TS, 0);
    DclSTS_Control(handle, STS_CMD_QUERY_TP_TYPE, (DCL_CTRL_DATA_T*)&data);

    #if defined(__MMI_EM_TP_UT__)
    mmi_em_tp_log_dprintf("[EM][TP]mmi_em_tp_is_ctp: tp_type = %d", data.TouchPanelType);
    #endif /*__MMI_EM_TP_UT__*/
    
    if (data.TouchPanelType == CTP_Type)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_param_setting_hide_rtp_items
 * DESCRIPTION
 *  if current touch panel is ctp, hide items which belong to rtp. 
 * PARAMETERS
 *  cui_menu_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_param_setting_hide_rtp_items(MMI_ID cui_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/                
    if (mmi_em_tp_is_ctp())
    {
        cui_menu_set_item_hidden(cui_menu_id, MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DEBOUNCE_TIME, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_id, MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_CALIB_CHECK_OFFSET, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_id, MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MULTI_POING_SELECTION, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_id, MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_HIGN_THRESHOLD, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_id, MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_CHECK_BOUNDARY, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_id, MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_SHIFTING, MMI_TRUE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_ctrl_custom_data
 * DESCRIPTION
 *  set/get touch panel custom data
 * PARAMETERS
 *  custom_data     [IN/OUT]  set(IN) get(OUT)
 *  type            [IN]      indicate set or get 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_ctrl_custom_data(TouchPanel_EM_custom_data_struct *custom_data,
                                        TP_CTRL_PARAM_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_HANDLE handle;
    DCL_CTRL_CUSTOM_PARAM_T data; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EM_TP_UT_ON_MODIS__
    mmi_em_tp_ctrl_custom_data_on_modis(custom_data, type);
    return;
    #endif /*__MMI_EM_TP_UT_ON_MODIS__*/
    
    data.type = type;
    data.pEmData = custom_data;
    if (TP_PARAM_SET != type)
    {
        memset(custom_data, 0, sizeof(TouchPanel_EM_custom_data_struct));
    }
    handle = DclSTS_Open(DCL_TS, 0);
    if (DCL_HANDLE_INVALID != handle)
    {
        DclSTS_Control(handle, STS_CMD_CTRL_CUSTOM_PARAM, (DCL_CTRL_DATA_T*)&data);
    }
    
    #if defined(__MMI_EM_TP_UT__)
    mmi_em_tp_log_dprintf("[EM][TP]: type = %d, params = (%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)",
                            type, 
                            custom_data->ts_debounce_time,
                            custom_data->touch_panel_cali_check_offset,
                            custom_data->min_pen_move_offset,
                            custom_data->hand_writing_max_offset,
                            custom_data->nonhand_writing_max_offset,
                            custom_data->max_stroke_move_offset,
                            custom_data->multiple_point_selection,
                            custom_data->touch_pressure_threshold_high,
                            custom_data->pressure_check_boundary,
                            custom_data->pressure_shifting_boundary,
                            custom_data->border_pass_criterion,
                            custom_data->non_border_pass_criterion,
                            custom_data->border_range,
                            custom_data->jitter_circuit_interval,
                            custom_data->Dump_Screen);
    #endif /*__MMI_EM_TP_UT__*/
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_ctrl_custom_data_item
  * DESCRIPTION
  *  set/get touch panel custom data item
  * PARAMETERS
  *  custom_data        [IN]
  *  item               [IN]
  *  value              [IN/OUT]    set(IN) get(OUT)
  *  type               [IN]        indicate set or get
  * RETURNS
  *  void
  *****************************************************************************/
static void mmi_em_tp_ctrl_custom_data_item(TouchPanel_EM_custom_data_struct *custom_data, 
                                            U32 item,
                                            kal_uint32 *value,
                                            TP_CTRL_PARAM_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 *p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item)
    {
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DEBOUNCE_TIME:
            p = &custom_data->ts_debounce_time;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_CALIB_CHECK_OFFSET:
            p = &custom_data->touch_panel_cali_check_offset;          
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MIN_PEN_MOVE_OFFSET:
            p = &custom_data->min_pen_move_offset;
            break;
            
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_HANDWRITE_OFFSET:
            p = &custom_data->hand_writing_max_offset;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_NON_HANDWRITE_OFFSET:
            p = &custom_data->nonhand_writing_max_offset;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_STROKE_OFFSET:
            p = &custom_data->max_stroke_move_offset;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MULTI_POING_SELECTION:
            p = &custom_data->multiple_point_selection;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_HIGN_THRESHOLD:
            p = &custom_data->touch_pressure_threshold_high;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_CHECK_BOUNDARY:
            p = &custom_data->pressure_check_boundary;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_SHIFTING:
            p = &custom_data->pressure_shifting_boundary;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_BORDER_PASS_CRITERION:
            p = &custom_data->border_pass_criterion;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_NON_BORDER_PASS_CRITERION:
            p = &custom_data->non_border_pass_criterion;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_BORDER_RANGE:
            p = &custom_data->border_range;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_ITEM_INTERVAL:
            p = &custom_data->jitter_circuit_interval;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DUMP_SCREEN:
            p = &custom_data->Dump_Screen;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_1:
            p = &custom_data->reserve_parameter1;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_2:
            p = &custom_data->reserve_parameter2;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_3:
            p = &custom_data->reserve_parameter3;
            break;

        default:
            break;
    }

    if (p)
    {
        
        if (TP_PARAM_GET == type)
        {
            *value = *p;
        }
        else if (TP_PARAM_SET == type)
        {
            *p = *value;
        }
        else
        {
            MMI_ASSERT(0);
        }
    }  
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_get_param_range
  * DESCRIPTION
  *  mmi_em_tp_get_param_range
  * PARAMETERS
  *  param_range        [OUT]
  *
  * RETURNS
  *  void
  *****************************************************************************/
static void mmi_em_tp_get_param_range(TP_PARAM_RANGE *param_range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_HANDLE handle;
    DCL_CTRL_CUSTOM_PARAM_RANGE_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_TP_UT_ON_MODIS__
    mmi_em_tp_get_param_range_on_modis(param_range);
    return;
#endif /*__MMI_EM_TP_UT_ON_MODIS__*/

    data.type = TP_PARAM_GET;
    data.pEmDataRange = param_range;
    handle = DclSTS_Open(DCL_TS, 0);
    DclSTS_Control(handle, STS_CMD_CTRL_CUSTOM_PARAM_RANGE, (DCL_CTRL_DATA_T*)&data);
    
    #if defined(__MMI_EM_TP_UT__)
    {
        U32 i;
        kal_int32 *p =(kal_int32 *)param_range;
        for(i = 0; i< 15; i++)
        {
            mmi_em_tp_log_dprintf("[EM][TP]: get_param_range: i = %d, (min, max) = (%d, %d)\n",
                                i, *p, *(p+1));
            p += 2;
        }
    }
    #endif /*__MMI_EM_TP_UT__*/
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_get_param_item_range
  * DESCRIPTION
  *  mmi_em_tp_get_param_item_range
  * PARAMETERS
  *  range          [IN]
  *  item           [IN]
  *  min            [OUT]
  *  max            [OUT]
  * RETURNS
  *  void
  *****************************************************************************/
static void mmi_em_tp_get_param_item_range(TP_PARAM_RANGE *range,U32 item, kal_int32 *min, kal_int32 *max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item)
    {
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DEBOUNCE_TIME:
            *min = range->ts_debounce_time_min;
            *max = range->ts_debounce_time_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_CALIB_CHECK_OFFSET:
            *min = range->touch_panel_cali_check_offset_min;
            *max = range->touch_panel_cali_check_offset_max;          
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MIN_PEN_MOVE_OFFSET:
            *min = range->min_pen_move_offset_min;
            *max = range->min_pen_move_offset_max;
            break;
            
        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_HANDWRITE_OFFSET:
            *min = range->hand_writing_max_offset_min;
            *max = range->hand_writing_max_offset_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_NON_HANDWRITE_OFFSET:
            *min = range->nonhand_writing_max_offset_min;
            *max = range->nonhand_writing_max_offset_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_STROKE_OFFSET:
            *min = range->max_stroke_move_offset_min;
            *max = range->max_stroke_move_offset_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MULTI_POING_SELECTION:
            *min = range->multiple_point_selection_min;
            *max = range->multiple_point_selection_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_HIGN_THRESHOLD:
            *min = range->touch_pressure_threshold_high_min;
            *max = range->touch_pressure_threshold_high_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_CHECK_BOUNDARY:
            *min = range->pressure_check_boundary_min;
            *max = range->pressure_check_boundary_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_SHIFTING:
            *min = range->pressure_shifting_boundary_min;
            *max = range->pressure_shifting_boundary_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_BORDER_PASS_CRITERION:
            *min = range->border_pass_criterion_min;
            *max = range->border_pass_criterion_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_NON_BORDER_PASS_CRITERION:
            *min = range->nonborder_pass_criterion_min;
            *max = range->nonborder_pass_criterion_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_BORDER_RANGE:
            *min = range->border_range_min;
            *max = range->border_range_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_ITEM_INTERVAL:
            *min = range->jitter_circuit_interval_min;
            *max = range->jitter_circuit_interval_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DUMP_SCREEN:
            *min = range->Dump_Screen_min;
            *max = range->Dump_Screen_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_1:
            *min = range->reserve_parameter1_min;
            *max = range->reserve_parameter1_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_2:
            *min = range->reserve_parameter2_min;
            *max = range->reserve_parameter2_max;
            break;

        case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_3:
            *min = range->reserve_parameter3_min;
            *max = range->reserve_parameter3_max;
            break;

        default:
            break;
    }   
}

 /*****************************************************************************
  * FUNCTION
  *  mmi_em_misc_tp_param_setting_enter
  * DESCRIPTION
  *  engineer mode ->misc -> touch screen ->parameter setting entry
  * PARAMETERS
  *  parent_id        [IN]     parent group id
  * RETURNS
  *  void
  *****************************************************************************/
void mmi_em_misc_tp_param_setting_enter(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID cui_id;
    em_tp_param_setting_struct *param_setting;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_setting = (em_tp_param_setting_struct *)MMI_EM_MALLOC(sizeof(em_tp_param_setting_struct));
    if (!param_setting)
        return;
    memset(param_setting, 0, sizeof(em_tp_param_setting_struct));  
    mmi_em_tp_ctrl_custom_data(&(param_setting->custom_data), TP_PARAM_GET);
    mmi_em_tp_get_param_range(&(param_setting->param_range));

    group_id = mmi_frm_group_create_ex(parent_id, 
                                        GRP_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING,
                                        mmi_em_tp_param_setting_proc, 
                                        (void *)param_setting,
                                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    param_setting->group_id = group_id;
    
    cui_id = cui_menu_create_and_run(group_id, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_APPSUB, 
                            MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING, 
                            MMI_TRUE, 
                            param_setting);    
    
    mmi_em_tp_param_setting_hide_rtp_items(cui_id);
}


#define TEST_1_ACCURACY

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_test1_verify
 * DESCRIPTION
 *  verify the point is pass
 * PARAMETERS
 *  context        [IN]
 *  pos            [IN]
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_em_tp_acc_test1_verify(em_tp_acc_test1_struct *context, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len2;
    U32 fail_distance;
    U32 fail_criterion;
    mmi_pen_point_struct center;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    center.x = context->circles[context->parent->cur_index].cx;
    center.y = context->circles[context->parent->cur_index].cy;
    len2 = (center.x - pos.x) * (center.x - pos.x) + (center.y - pos.y) * (center.y - pos.y);
    fail_criterion = context->circles[context->parent->cur_index].r;
#ifdef __MMI_EM_TP_UT__
    mmi_em_tp_log_dprintf("[EM][TP]test1_verify: circle(x, y ,r )= (%d, %d, %d), Pos(x, y) = (%d, %d)\n",
                           center.x, center.y, fail_criterion, pos.x, pos.y);
#endif
    if (len2 > fail_criterion * fail_criterion)
    {
        fail_distance = (U32)sqrt((double)len2);
        if (fail_distance == fail_criterion)
        {
			fail_distance += 1;
        }
    #ifdef __MMI_EM_TP_UT__
        mmi_em_tp_log_dprintf("[EM][TP]test1_verify: fail_distance = %d\n", fail_distance);
    #endif
        if (fail_distance > (U32)context->parent->fail_distance)
        {
            context->parent->fail_distance = fail_distance;
            context->parent->fail_position.x = pos.x;
            context->parent->fail_position.y = pos.y;
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_test1_data_init
 * DESCRIPTION
 *   data init
 * PARAMETERS
 *  context        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_test1_data_init(em_tp_acc_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 col;
    U32 row;
    U32 index;
    S32 per_width;
    S32 per_height;
    S32 character_w;
    U32 x_offset;
    TouchPanel_EM_custom_data_struct custom_data;
    em_tp_acc_test1_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->pen_num = EM_TP_ACC_TEST1_CIRCLE_NUM;
    item->data_deinit_func = NULL;
    item->draw_bg_func = mmi_em_tp_acc_test1_draw_bg;
    item->pen_hdlr_func = mmi_em_tp_acc_test1_pen_hdlr;
    item->pen_register = EM_TP_ACC_PEN_DOWN_REG | EM_TP_ACC_PEN_UP_REG;
    
    context = (em_tp_acc_test1_struct *)MMI_EM_MALLOC(sizeof(em_tp_acc_test1_struct));
    item->item_data = context;
    context->parent = item;

    mmi_em_tp_ctrl_custom_data(&custom_data, TP_PARAM_GET);
    context->border_range = mmi_em_tp_acc_get_pixel_from_um(custom_data.border_range);
    context->border_pass_criterion = mmi_em_tp_acc_get_pixel_from_um(custom_data.border_pass_criterion);
    context->non_border_pass_criterion = mmi_em_tp_acc_get_pixel_from_um(custom_data.non_border_pass_criterion);
    
    per_width = (UI_device_width - context->border_range) / EM_TP_ACC_TEST1_SEG_NUM;
    per_height = (UI_device_height- context->border_range) / EM_TP_ACC_TEST1_SEG_NUM; 

    /*circle init row 1 3 5*/
    index = 0;
    for (row = 0; row < 3; ++row )
    {
        for (col = 0; col < 3; ++col)
        {
            context->circles[index].cx = context->border_range / 2 + col * 2 * per_width;
            context->circles[index].cy = context->border_range / 2 + row * 2 * per_height;
            if (6 == index)
            {
                context->circles[index].r = context->non_border_pass_criterion;
            }
            else
            {
                context->circles[index].r = context->border_pass_criterion;
            }
            if (0 == context->circles[index].r)
            {
                context->circles[index].r = 1;
            }
            index ++;
        }
        index += 2;
    }

    /*circle init row 2 4*/
    index = 3;
    for (row = 0; row < 2; ++row )
    {
        for (col = 0; col < 2; ++col)
        {
            context->circles[index].cx = context->border_range / 2 + per_width + col * 2 * per_width;
            context->circles[index].cy = context->border_range / 2 + per_height+ row * 2 * per_height;
            context->circles[index++].r = context->non_border_pass_criterion;
        }
        index += 3;
    }

    /* init nums */
    character_w = gui_get_character_width('8');
    for (index = 0; index < EM_TP_ACC_TEST1_CIRCLE_NUM; ++index)
    {
        if (2 == index || 7 == index)
        {
            x_offset = 0 - context->circles[index].r - character_w;
        }
        else if (12 == index)
        {
            x_offset = 0 - context->circles[index].r - 2 * character_w;
        }
        else
        {
            x_offset= context->circles[index].r;
        }
        context->nums[index].x = context->circles[index].cx + x_offset;
        if (context->circles[index].cy < item->character_h / 2)
        {
            context->nums[index].y = 0;
        }
        else if (UI_device_height - context->circles[index].cy < item->character_h / 2)
        {
            context->nums[index].y = UI_device_height - item->character_h;
        }
        else
        {
            context->nums[index].y = context->circles[index].cy - item->character_h / 2;
        }            
    }

    item->layer_width = 2 * per_width;
    item->layer_height = per_height + item->character_h;
    item->layer_offset_x = context->circles[3].cx;
    item->layer_offset_y = context->circles[3].cy + (per_height - item->character_h)/ 2;

    /*coordinate rect*/
    mmi_em_tp_acc_set_rect(&item->coordinate_rect, 
                            0,
                            0,
                            item->layer_width,
                            item->character_h);

    /*pressure rect*/
    mmi_em_tp_acc_set_rect(&item->pressure_rect, 
                            0,
                            per_height,
                            item->layer_width,
                            per_height + item->character_h);
   
    item->fail_rigion.x = per_width;
    item->fail_rigion.y = UI_device_height - per_height;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_test1_draw_bg
 * DESCRIPTION
 *   draw backgroud
 * PARAMETERS
 *  item_data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_test1_draw_bg(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    em_tp_acc_test1_struct *context = (em_tp_acc_test1_struct *)item_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*draw non border rect*/
    gdi_draw_rect(context->border_range,
                    context->border_range,
                    UI_device_width - context->border_range,
                    UI_device_height - context->border_range,
                    EM_TP_ACC_LINE_BG_COLOR);

    /*draw circle*/
    for (i = 0; i < EM_TP_ACC_TEST1_CIRCLE_NUM; ++i)
    {
        gdi_draw_solid_circle(context->circles[i].cx, 
                            context->circles[i].cy,
                            context->circles[i].r,
                            EM_TP_ACC_CIRCLE_BG_COLOR);

    }
    for (i = 0; i < EM_TP_ACC_TEST1_CIRCLE_NUM; ++i)
    {
        mmi_em_tp_acc_draw_int(context->nums[i].x, context->nums[i].y, i + 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_test1_pen_hdlr
 * DESCRIPTION
 *  engineer mode touch panel accuracy test1 pen handler
 * PARAMETERS
 *  item_data   [IN]    
 *  pen_type    [IN]    down/move/up
 *  pos         [IN]    coordinate of point
 *  pressure    [IN]    pressure
 * RETURNS
 *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_test1_pen_hdlr(void *item_data, 
                                em_tp_acc_pen_type_enum  pen_type, 
                                mmi_pen_point_struct pos,
                                U32 pressure)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_test1_struct *context = (em_tp_acc_test1_struct *)item_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    if (TP_ACC_PEN_DOWN == pen_type)
    {
        mmi_em_tp_acc_test1_verify(context, pos);
        
        gdi_draw_solid_circle(pos.x, pos.y, EM_TP_ACC_CIRCLE_FG_R, EM_TP_ACC_CIRCLE_FG_COLOR);
    }
}

#define TEST_2_SLOPE
/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_linear_slope_verify
 * DESCRIPTION
 *  verify current point's pass crerition 
 * PARAMETERS
 *  context     [IN]  linear slope context
 *  pos         [IN]  current coordinate of point
 *  pen_type    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_linear_slope_verify(em_tp_acc_linear_slope_struct *context,
                                                mmi_pen_point_struct pos,
                                                em_tp_acc_pen_type_enum pen_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 line_x = 0; 
    S32 line_y = 0; 
    S32 distance = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TP_ACC_PEN_DOWN == pen_type)
    {
        if (context->parent->cur_index == 0)
        {
            distance = EM_TP_MAX(pos.x, pos.y);
        }
        else
        {
            distance = EM_TP_MAX(UI_device_width - 1 - pos.x, pos.y);
        }
    }
    else if (TP_ACC_PEN_UP == pen_type)
    {
        if (context->parent->cur_index == 0)
        {
            distance = EM_TP_MAX(UI_device_width - 1 - pos.x, UI_device_height - 1 - pos.y);
        }
        else
        {
            distance = EM_TP_MAX(pos.x, UI_device_height - 1 - pos.y);
        }
    }
    else 
    {
        if (context->parent->cur_index == 0)
        {
            line_x = (UI_device_width - 1) * pos.y / (UI_device_height - 1);
            line_y = (UI_device_height - 1) * pos.x / (UI_device_width - 1);
        }
        else if (context->parent->cur_index == 1)
        {
            line_x = (UI_device_width - 1) - (UI_device_width - 1) * pos.y / (UI_device_height - 1);
            line_y = (UI_device_height  -1) - (UI_device_height - 1) * pos.x / (UI_device_width - 1);
        }
        distance = EM_TP_MIN(EM_TP_ABSSUB(line_x, pos.x), EM_TP_ABSSUB(line_y, pos.y));
    }    
    
    if (distance > context->non_border_pass_criterion && distance > context->parent->fail_distance)
    {
		context->parent->fail_distance = distance;
        context->parent->fail_position.x = pos.x;
        context->parent->fail_position.y = pos.y;
	}  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_linear_slope_pen_hdlr
 * DESCRIPTION
 *  pen  handler of touch panel accuracy linear-slope 
 * PARAMETERS
 *  item_data   [IN]    
 *  pen_type    [IN]    down/move/up
 *  pos         [IN]    coordinate of point
 *  pressure    [IN]    pressure
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_linear_slope_pen_hdlr(void *item_data,
                                                em_tp_acc_pen_type_enum pen_type,
                                                mmi_pen_point_struct pos,
                                                U32 pressure)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_linear_slope_struct *context = (em_tp_acc_linear_slope_struct *)item_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_em_tp_acc_linear_slope_verify(context, pos, pen_type);
    mmi_em_tp_acc_item_general_pen_hdlr(&context->last_point, &pos, pen_type);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_linear_slope_data_init
  * DESCRIPTION
  *  mmi_em_tp_acc_linear_slope_data_init
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_linear_slope_data_init(em_tp_acc_item_struct * item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_linear_slope_struct *context;
    TouchPanel_EM_custom_data_struct custom_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->pen_num = 2;
    item->data_deinit_func = NULL;
    item->draw_bg_func = mmi_em_tp_acc_linear_slope_draw_bg;
    item->pen_hdlr_func = mmi_em_tp_acc_linear_slope_pen_hdlr;
    item->pen_register = EM_TP_ACC_PEN_DOWN_REG | EM_TP_ACC_PEN_UP_REG | EM_TP_ACC_PEN_MOVE_REG;
    
    context = (em_tp_acc_linear_slope_struct *)MMI_EM_MALLOC(sizeof(em_tp_acc_linear_slope_struct));
    item->item_data = context;
    context->parent = item;
    
    context->last_point.x = context->last_point.y = -1;

    item->layer_width = UI_device_width / 2;
    item->layer_height = UI_device_height;
    item->layer_offset_x = UI_device_width / 4;
    item->layer_offset_y = 0;
    
    mmi_em_tp_acc_set_rect(&(item->coordinate_rect), 
                             0, 
                             0,
                             UI_device_width / 2,
                             item->character_h);
    mmi_em_tp_acc_set_rect(&(item->pressure_rect), 
                            0, 
                            UI_device_height - item->character_h, 
                            UI_device_width / 2, 
                            UI_device_height);
    
    item->fail_rigion.x = UI_device_width / 8;
    item->fail_rigion.y = UI_device_height / 2;    
    mmi_em_tp_ctrl_custom_data(&custom_data, TP_PARAM_GET);
    context->non_border_pass_criterion = mmi_em_tp_acc_get_pixel_from_um(custom_data.non_border_pass_criterion);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_linear_slope_draw_bg
  * DESCRIPTION
  *  draw background
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_linear_slope_draw_bg(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_w;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    character_w = gui_get_character_width('8');
    gdi_draw_line(0, 0, UI_device_width-1, UI_device_height-1, EM_TP_ACC_LINE_BG_COLOR);    
    gdi_draw_line(UI_device_width - 2, 
                    UI_device_height-2 - EM_TP_ACC_LINE_ARROW_LEN, 
                    UI_device_width-2, 
                    UI_device_height - 2, 
                    EM_TP_ACC_LINE_BG_COLOR);
    gdi_draw_line(UI_device_width - 2 - EM_TP_ACC_LINE_ARROW_LEN,
                    UI_device_height-2,
                    UI_device_width-2,
                    UI_device_height - 2,
                    EM_TP_ACC_LINE_BG_COLOR);
    mmi_em_tp_acc_draw_int(0, 1, 1);

    gdi_draw_line(UI_device_width-1, 0, 0, UI_device_height-1, EM_TP_ACC_LINE_BG_COLOR);
    gdi_draw_line(1,
                    UI_device_height- 2 - EM_TP_ACC_LINE_ARROW_LEN, 
                    1,
                    UI_device_height-2,
                    EM_TP_ACC_LINE_BG_COLOR);
    gdi_draw_line(1 + EM_TP_ACC_LINE_ARROW_LEN, 
                    UI_device_height-2, 
                    1, 
                    UI_device_height-2, 
                    EM_TP_ACC_LINE_BG_COLOR);
    mmi_em_tp_acc_draw_int(UI_device_width- 1 - character_w, 1, 2);

    /*draw pass line*/
    mmi_em_tp_acc_linear_slope_draw_criterion_lines((em_tp_acc_linear_slope_struct *)item_data);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_linear_slope_draw_criterion_lines
  * DESCRIPTION
  *  draw background
  * PARAMETERS
  *  context        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_linear_slope_draw_criterion_lines(em_tp_acc_linear_slope_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x_offset;
    S32 y_offset;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*draw pass line*/
      
    if (UI_device_width < UI_device_height)
    {
        x_offset = context->non_border_pass_criterion;
        y_offset = x_offset * UI_device_height / UI_device_width;
    }
    else
    {
        y_offset = context->non_border_pass_criterion;
        x_offset = y_offset * UI_device_width/ UI_device_height;
    }      
    
    mmi_em_tp_acc_item_draw_pass_cretirion_line(0, y_offset, 
                           UI_device_width - 1 - x_offset, UI_device_height);
    mmi_em_tp_acc_item_draw_pass_cretirion_line(x_offset, 0, 
                           UI_device_width - 1, UI_device_height - 1 - y_offset);
    mmi_em_tp_acc_item_draw_pass_cretirion_line(0, UI_device_height - 1 - y_offset,
                        UI_device_width - 1 - x_offset, 0);
    mmi_em_tp_acc_item_draw_pass_cretirion_line(x_offset, UI_device_height - 1, 
                           UI_device_width - 1, y_offset);
}

#define TEST_3_VERTICAL
/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_linear_ver_verify
 * DESCRIPTION
 *  verify current point's pass crerition 
 * PARAMETERS
 *  context     [IN]  linear-vertical context
 *  pos         [IN]  current coordinate of point
 *  pen_type    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_linear_ver_verify(em_tp_acc_linear_ver_struct *context,
                                                mmi_pen_point_struct pos,
                                                em_tp_acc_pen_type_enum pen_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 gap;
    S32 gap_x;
    S32 gap_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gap_x = EM_TP_ABSSUB((context->parent->cur_index + 1) * context->gap_width, pos.x);
    if (TP_ACC_PEN_DOWN == pen_type)
    {
        gap_y = pos.y;
        gap = EM_TP_MAX(gap_x, gap_y);
    }
    else if(TP_ACC_PEN_UP == pen_type)
    {
        gap_y = UI_device_height - pos.y;
        gap = EM_TP_MAX(gap_x, gap_y);
    }
    else
    {
        gap = gap_x;
    }
    if ( gap > context->non_border_pass_criterion && gap > context->parent->fail_distance)
    {           
        context->parent->fail_distance = gap;
        context->parent->fail_position.x = pos.x;
        context->parent->fail_position.y = pos.y;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_linear_ver_pen_hdlr
 * DESCRIPTION
 *  pen handler of touch panel accuracy linear-vertical
 * PARAMETERS
 *  item_data   [IN]    
 *  pen_type    [IN]    down/move/up
 *  pos         [IN]    coordinate of point
 *  pressure    [IN]    pressure        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_linear_ver_pen_hdlr(void *item_data,
                                                em_tp_acc_pen_type_enum pen_type,
                                                mmi_pen_point_struct pos,
                                                U32 pressure)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_linear_ver_struct *context = (em_tp_acc_linear_ver_struct *)item_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_em_tp_acc_linear_ver_verify(context, pos, pen_type);
    mmi_em_tp_acc_item_general_pen_hdlr(&context->last_point, &pos, pen_type);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_linear_ver_data_init
  * DESCRIPTION
  *  mmi_em_tp_acc_linear_ver_data_init
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_linear_ver_data_init(em_tp_acc_item_struct * item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    em_tp_acc_linear_ver_struct *context;
    TouchPanel_EM_custom_data_struct custom_data;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->pen_num = EM_TP_ACC_LINEAR_HORIZ_LINE_NUMBER;
    item->draw_bg_func = mmi_em_tp_acc_linear_ver_draw_bg;
    item->pen_hdlr_func = mmi_em_tp_acc_linear_ver_pen_hdlr;
    item->pen_register = EM_TP_ACC_PEN_DOWN_REG | EM_TP_ACC_PEN_UP_REG | EM_TP_ACC_PEN_MOVE_REG;
    item->data_deinit_func = NULL;
    
	item->item_data = MMI_EM_MALLOC(sizeof(em_tp_acc_linear_ver_struct));	
	context = (em_tp_acc_linear_ver_struct *)item->item_data;
    context->parent = item;
    
    context->gap_width = UI_device_width / (EM_TP_ACC_LINEAR_HORIZ_LINE_NUMBER + 1);
    context->last_point.x = context->last_point.y = -1;
    
    mmi_em_tp_acc_set_rect(&(item->coordinate_rect), 
                                0, 
                                0, 
                                UI_device_width / 2,
                                item->character_h);
    mmi_em_tp_acc_set_rect(&(item->pressure_rect),
                                UI_device_width/2 + 1, 
                                0, 
                                UI_device_width-1, 
                                item->character_h);
    item->fail_rigion.x = UI_device_width/4;
    item->fail_rigion.y = UI_device_height/2;    
    mmi_em_tp_ctrl_custom_data(&custom_data, TP_PARAM_GET);
    context->non_border_pass_criterion = mmi_em_tp_acc_get_pixel_from_um(custom_data.non_border_pass_criterion);

    item->layer_width = UI_device_width;
    item->layer_height = item->character_h;
    item->layer_offset_x = 0;
    item->layer_offset_y = UI_device_height / 4;
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_linear_ver_draw_bg
  * DESCRIPTION
  *  draw background
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_linear_ver_draw_bg(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 x = 0;
    em_tp_acc_linear_ver_struct *context = (em_tp_acc_linear_ver_struct *)item_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < EM_TP_ACC_LINEAR_HORIZ_LINE_NUMBER; ++i)
    {
        x += context->gap_width;
        mmi_em_tp_acc_draw_line_direction( x, 
                                            0,
                                            x,
                                            UI_device_height-1, 
                                            EM_TP_ACC_LINE_BG_COLOR,
                                            TP_ACC_LINE_DOWN);
        /*draw start position*/
        mmi_em_tp_acc_draw_int(x + 1, 1, i + 1);
    }    
}

#define TEST_4_HORIZONTAL
/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_linear_horiz_verify
 * DESCRIPTION
 *  verify current point's pass crerition 
 * PARAMETERS
 *  context     [IN]  linear-horizontal context
 *  pos         [IN]  current coordinate of point     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_linear_horiz_verify(em_tp_acc_linear_horiz_struct *context,
                                                mmi_pen_point_struct pos,
                                                em_tp_acc_pen_type_enum pen_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S32 gap;
    S32 gap_x;
    S32 gap_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gap_y = EM_TP_ABSSUB((context->parent->cur_index + 1) * context->gap_height, pos.y);

    if (TP_ACC_PEN_DOWN == pen_type)
    {
        gap_x = pos.x;
        gap = EM_TP_MAX(gap_x, gap_y);
    }
    else if(TP_ACC_PEN_UP == pen_type)
    {
        gap_x = UI_device_width - pos.x;
        gap = EM_TP_MAX(gap_x, gap_y);
    }
    else
    {
        gap = gap_y;
    }
    
    if ( gap > context->non_border_pass_criterion && gap > context->parent->fail_distance)
    {           
        context->parent->fail_distance = gap;
        context->parent->fail_position.x = pos.x;
        context->parent->fail_position.y = pos.y;
    } 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_linear_horiz_pen_hdlr
 * DESCRIPTION
 *  pen handler of touch panel accuracy linear-horizental 
 * PARAMETERS
 *  item_data   [IN]    
 *  pen_type    [IN]    down/move/up
 *  pos         [IN]    coordinate of point
 *  pressure    [IN]    pressure        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_linear_horiz_pen_hdlr(void *item_data,
                                            em_tp_acc_pen_type_enum pen_type,
                                            mmi_pen_point_struct pos,
                                            U32 pressure)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_linear_horiz_struct *context = (em_tp_acc_linear_horiz_struct *)item_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    mmi_em_tp_acc_linear_horiz_verify(context, pos, pen_type);
    mmi_em_tp_acc_item_general_pen_hdlr(&context->last_point, &pos, pen_type);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_linear_horiz_data_init
  * DESCRIPTION
  *  mmi_em_tp_acc_linear_horiz_data_init
  * PARAMETERS
  *  context        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_linear_horiz_data_init(em_tp_acc_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    em_tp_acc_linear_horiz_struct *context;
    TouchPanel_EM_custom_data_struct custom_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->pen_num = EM_TP_ACC_LINEAR_VER_LINE_NUMBER;
    item->data_deinit_func = NULL;
    item->draw_bg_func = mmi_em_tp_acc_linear_horiz_draw_bg;
    item->pen_hdlr_func = mmi_em_tp_acc_linear_horiz_pen_hdlr;
    item->pen_register = EM_TP_ACC_PEN_DOWN_REG | EM_TP_ACC_PEN_UP_REG | EM_TP_ACC_PEN_MOVE_REG;
    
    item->item_data = MMI_EM_MALLOC(sizeof(em_tp_acc_linear_horiz_struct));
    context = (em_tp_acc_linear_horiz_struct *)item->item_data;
    context->parent = item;
    
    context->gap_height = UI_device_height / (EM_TP_ACC_LINEAR_VER_LINE_NUMBER + 1);
    context->last_point.x = context->last_point.y = -1;
    
    mmi_em_tp_acc_set_rect(&(item->coordinate_rect), 0, 0, UI_device_width/2, item->character_h);
    mmi_em_tp_acc_set_rect(&(item->pressure_rect), UI_device_width/2 + 1, 0, UI_device_width - 1, item->character_h);
    item->fail_rigion.x = UI_device_width / 4;
    item->fail_rigion.y = UI_device_height / 2;  
    
    mmi_em_tp_ctrl_custom_data(&custom_data, TP_PARAM_GET);
    context->non_border_pass_criterion = mmi_em_tp_acc_get_pixel_from_um(custom_data.non_border_pass_criterion);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_linear_horiz_draw_bg
  * DESCRIPTION
  *  draw background
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_linear_horiz_draw_bg(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 y = 0;
    em_tp_acc_linear_horiz_struct *context = (em_tp_acc_linear_horiz_struct *)item_data;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    for (i = 0; i < EM_TP_ACC_LINEAR_VER_LINE_NUMBER; ++i)
    {
        y += context->gap_height;
        mmi_em_tp_acc_draw_line_direction( 0, 
                                            y, 
                                            UI_device_width-1, 
                                            y, 
                                            EM_TP_ACC_LINE_BG_COLOR,
                                            TP_ACC_LINE_RIGHT);
        /*draw start position*/
        mmi_em_tp_acc_draw_int(1, y - context->parent->character_h, i + 1);
    }  
}


#define TEST_5_CIRCUIT
/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_circuit_is_implented
 * DESCRIPTION
 *  check circuit small rect is implented 
 * PARAMETERS
 *  rect        [IN]  rect array
 *  num_x       [IN]  rect's number of x     
 *  num_y       [IN]  rect's number of y
 *  x           [IN]  the x of item which will be checked  
 *  y           [IN]  the y of item which will be checked
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_em_tp_acc_circuit_is_implented(U8* rect, U32 num_x, U32 num_y, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    index = x + y * num_x;
    if (x < 0 || x >= (S32)num_x || y < 0 || y >= (S32)num_y || rect[index] != 0)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_circuit_implent_rect
 * DESCRIPTION
 *  implent rect array which for verify 
 * PARAMETERS
 *  context     [IN]  in order to get the end position'index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_circuit_implent_rect(em_tp_acc_circuit_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cur_index;
    U8* rect;
    U32 num_x;
    U32 num_y;
    S32 x;
    S32 y;
    U32 lastDir;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context->last_index = 0;
    x = 0;
    y = context->y_num - 1;
    lastDir= TP_CIRCUIT_START;
    rect = context->line_direction;
    num_x = context->x_num;
    num_y = context->y_num;

    while(1)
    {
        cur_index = x + y * num_x;
        switch(lastDir)
        {
            case TP_CIRCUIT_START:
            case TP_CIRCUIT_UP:
                if (!mmi_em_tp_acc_circuit_is_implented(rect, num_x, num_y, x, y-1))
                {
                     rect[cur_index] = TP_CIRCUIT_UP;
                     y -= 1;
                     lastDir = TP_CIRCUIT_UP;
                }
                else if(!mmi_em_tp_acc_circuit_is_implented(rect, num_x, num_y, x + 1, y))
                {
                     if (lastDir == TP_CIRCUIT_START)
                         rect[cur_index] = TP_CIRCUIT_RIGHT;    
                     else
                         rect[cur_index] = TP_CIRCUIT_UP_RIGHT;
                     x += 1;
                     lastDir = TP_CIRCUIT_RIGHT;
                }
                else
                {
                     rect[cur_index] = TP_CIRCUIT_UP;
                     context->last_index = cur_index;
                }
                break;

            case TP_CIRCUIT_RIGHT:
                if (!mmi_em_tp_acc_circuit_is_implented(rect, num_x, num_y, x + 1, y))
                {
                     rect[cur_index] = TP_CIRCUIT_RIGHT;
                     x += 1;
                }
                else if(!mmi_em_tp_acc_circuit_is_implented(rect, num_x, num_y, x, y + 1))
                {
                     rect[cur_index] = TP_CIRCUIT_RIGHT_DOWN;
                      y += 1;
                     lastDir = TP_CIRCUIT_DOWN;
                }
                else
                {
                     rect[cur_index] = TP_CIRCUIT_RIGHT;
                     context->last_index = cur_index;
                }
                break;
     
            case TP_CIRCUIT_DOWN:
                if (!mmi_em_tp_acc_circuit_is_implented(rect, num_x, num_y, x, y + 1))
                {
                     rect[cur_index] = TP_CIRCUIT_DOWN;
                     y += 1;
                }
                else if(!mmi_em_tp_acc_circuit_is_implented(rect, num_x, num_y, x - 1, y))
                {
                     rect[cur_index] = TP_CIRCUIT_DOWN_LEFT;
                     x -= 1;
                     lastDir = TP_CIRCUIT_LEFT;
                }
                else
                {
                     rect[cur_index] = TP_CIRCUIT_DOWN;
                     context->last_index = cur_index;
                }
                break;    
     
            case TP_CIRCUIT_LEFT:
                if (!mmi_em_tp_acc_circuit_is_implented(rect, num_x, num_y, x - 1, y))
                {
                     rect[cur_index] = TP_CIRCUIT_LEFT;
                     x -= 1;
                }
                else if(!mmi_em_tp_acc_circuit_is_implented(rect, num_x, num_y, x, y - 1))
                {
                     rect[cur_index] = TP_CIRCUIT_LEFT_UP;
                     y -= 1;
                     lastDir = TP_CIRCUIT_UP;
                }
                else
                {
                     rect[cur_index] = TP_CIRCUIT_LEFT;
                     context->last_index = cur_index;
                }
                break;   

            default:
                break;
        }
        if (context->last_index)
           break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_circuit_verify
 * DESCRIPTION
 *  verify current point's pass crerition 
 * PARAMETERS
 *  context     [IN]  two rect context
 *  pos         [IN]  current coordinate of point
 *  pen_type    [IN]  pen_type: down / up / move ...  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_circuit_verify(em_tp_acc_circuit_struct *context,
                                                mmi_pen_point_struct pos,
                                                em_tp_acc_pen_type_enum pen_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 gap;
    U32 index;
    S32 index_x;
    S32 index_y;    
    S32 center_x;
    S32 center_y;
    U32 solute_x;
    U32 solute_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TP_ACC_PEN_DOWN == pen_type || TP_ACC_PEN_UP == pen_type)
    {
        if (TP_ACC_PEN_DOWN == pen_type)
        {
            /*distance pos and start point*/
            index_x = 0;
            index_y = context->y_num - 1;
        }
        else
        {
            /*distance pos and end point*/
            index = context->last_index;
            index_x = index % context->x_num;
            index_y = index / context->x_num;
        }        
        center_x = index_x * context->pitch_x + context->border_width + context->pitch_x / 2;
        center_y = index_y * context->pitch_y + context->border_height + context->pitch_y / 2;
        gap = EM_TP_MAX(EM_TP_ABSSUB(pos.x, center_x), EM_TP_ABSSUB(pos.y, center_y));
    }
    else
    {
        index_x = (pos.x - context->border_width) / context->pitch_x;
        index_y = (pos.y - context->border_height) / context->pitch_y;
        if (index_x < 0)
        {
            index_x = 0;
        }
        else if(index_x >= context->x_num)
        {
            index_x = context->x_num - 1;
        }
        if (index_y < 0)
        {
            index_y = 0;
        }
        else if(index_y >= context->y_num)
        {
            index_y = context->y_num - 1;
        }
        
        index = index_x + index_y * context->x_num;
        center_x = index_x * context->pitch_x + context->border_width + context->pitch_x / 2;
        center_y = index_y * context->pitch_y + context->border_height + context->pitch_y / 2;
        switch (context->line_direction[index])
        {
        	case TP_CIRCUIT_UP:
            case TP_CIRCUIT_DOWN:
                gap = EM_TP_ABSSUB(pos.x, center_x);
                break;

            case TP_CIRCUIT_RIGHT:
            case TP_CIRCUIT_LEFT: 
                gap = EM_TP_ABSSUB(pos.y, center_y);
                break;

            case TP_CIRCUIT_UP_RIGHT:
                /* only used for pitch_x == pitch_y */
                solute_x = pos.x - (center_x - context->pitch_x / 2);
                solute_y = pos.y - (center_y - context->pitch_y / 2);
                if (solute_x < solute_y)
                {
                   gap =  EM_TP_ABSSUB(pos.x, center_x);
                }
                else
                {
                    gap = EM_TP_ABSSUB(pos.y, center_y);
                }                
                break;

            case TP_CIRCUIT_RIGHT_DOWN:
                /* only used for pitch_x == pitch_y */
                solute_x = (center_x + context->pitch_x / 2) - pos.x;
                solute_y = pos.y - (center_y - context->pitch_y / 2);
                if (solute_x < solute_y)
                {
                   gap =  EM_TP_ABSSUB(pos.x, center_x);
                }
                else
                {
                    gap = EM_TP_ABSSUB(pos.y, center_y);
                }         
                break;

            case TP_CIRCUIT_DOWN_LEFT:                
                /* only used for pitch_x == pitch_y */
                solute_x = (center_x + context->pitch_x / 2) - pos.x;
                solute_y = (center_y + context->pitch_y / 2) - pos.y;
                if (solute_x < solute_y)
                {
                   gap =  EM_TP_ABSSUB(pos.x, center_x);
                }
                else
                {
                    gap = EM_TP_ABSSUB(pos.y, center_y);
                }                
                break;

            case TP_CIRCUIT_LEFT_UP:
                /* only used for pitch_x == pitch_y */
                solute_x = pos.x - (center_x - context->pitch_x / 2);
                solute_y = (center_y + context->pitch_y / 2) - pos.y;
                if (solute_x < solute_y)
                {
                   gap =  EM_TP_ABSSUB(pos.x, center_x);
                }
                else
                {
                    gap = EM_TP_ABSSUB(pos.y, center_y);
                }                
                break;

            default:
                gap = 0;
                break;                
                
        }
    }
    if (gap > context->non_border_pass_criterion && gap > context->parent->fail_distance)
	{
		context->parent->fail_distance = gap;
        context->parent->fail_position.x = pos.x;
        context->parent->fail_position.y = pos.y;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_circuit_pen_hdlr
 * DESCRIPTION
 *  pen handler of touch panel accuracy two rect 
 * PARAMETERS
 *  item_data   [IN]    
 *  pen_type    [IN]    down/move/up
 *  pos         [IN]    coordinate of point
 *  pressure    [IN]    pressure        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_circuit_pen_hdlr(void *item_data,
                                            em_tp_acc_pen_type_enum pen_type,
                                            mmi_pen_point_struct pos,
                                            U32 pressure)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_circuit_struct *context = (em_tp_acc_circuit_struct *)item_data;
    mmi_pen_point_struct center;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TP_ACC_PEN_DOWN != pen_type)
    {
        center.x = (pos.x + context->last_point.x) / 2;
        center.y = (pos.y + context->last_point.y) / 2;
        mmi_em_tp_acc_circuit_verify(context, center, TP_ACC_PEN_MOVE);
    }
    mmi_em_tp_acc_circuit_verify(context, pos,pen_type);    
    mmi_em_tp_acc_item_general_pen_hdlr(&context->last_point, &pos, pen_type);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_circuit_data_init
  * DESCRIPTION
  *  mmi_em_tp_acc_circuit_data_init
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_circuit_data_init(em_tp_acc_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_circuit_struct *context;
    TouchPanel_EM_custom_data_struct custom_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->pen_num = EM_TP_ACC_CIRCUIT_LINE_NUMBER;
    item->data_deinit_func = mmi_em_tp_acc_circuit_data_deinit;
    item->draw_bg_func = mmi_em_tp_acc_circuit_draw_bg;
    item->pen_hdlr_func= mmi_em_tp_acc_circuit_pen_hdlr;
    item->pen_register = EM_TP_ACC_PEN_DOWN_REG | EM_TP_ACC_PEN_UP_REG | EM_TP_ACC_PEN_MOVE_REG ;
    
    item->item_data = MMI_EM_MALLOC(sizeof(em_tp_acc_circuit_struct));
    memset(item->item_data, 0, sizeof(em_tp_acc_circuit_struct));
    context = (em_tp_acc_circuit_struct *)item->item_data; 
    context->parent = item;

    mmi_em_tp_ctrl_custom_data(&custom_data, TP_PARAM_GET);
    
    context->pitch_x = mmi_em_tp_acc_get_pixel_from_um(custom_data.jitter_circuit_interval);
    context->pitch_y = context->pitch_x;
    if (context->pitch_x > UI_device_width || context->pitch_y > UI_device_height)
    {
        context->pitch_x = EM_TP_MIN(UI_device_width, UI_device_height);
        context->pitch_y = context->pitch_x;
    }
    if (0 == context->pitch_x || 0 == context->pitch_y)
    {
        /* error hanppy */
        mmi_em_tp_acc_item_draw_error(item->group_id, (U16*)L"pitch can't be 0. please check!");
        item->is_error_happen = 1;
        return;
    }
   
    context->border_width = (UI_device_width % context->pitch_x) / 2;
    context->border_height = (UI_device_height % context->pitch_y) / 2;

    /* for verify */
    context->x_num = UI_device_width / context->pitch_x;
    context->y_num = UI_device_height / context->pitch_y;

    context->line_direction = MMI_EM_MALLOC((context->x_num * context->y_num) * sizeof(U8));
    memset(context->line_direction, 0, context->x_num * context->y_num * sizeof(U8));

    mmi_em_tp_acc_circuit_implent_rect(context);
   
    context->non_border_pass_criterion = mmi_em_tp_acc_get_pixel_from_um(custom_data.non_border_pass_criterion);

    item->layer_width = UI_device_width;
    item->layer_height = item->character_h;
    item->layer_offset_x = 0;
    item->layer_offset_y = UI_device_height / 2;

    mmi_em_tp_acc_set_rect(&(item->coordinate_rect), 
                        0, 
                        0, 
                        item->layer_width / 2,
                        item->layer_height);
    mmi_em_tp_acc_set_rect(&(item->pressure_rect), 
                        item->layer_width / 2 + 1, 
                        0,
                        item->layer_width - 1,
                        item->layer_height); 
    item->fail_rigion.x = 0;
    item->fail_rigion.y = UI_device_height / 2 + item->character_h;
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_circuit_data_deinit
  * DESCRIPTION
  *  mmi_em_tp_acc_circuit_data_deinit
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_circuit_data_deinit(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_circuit_struct *context = (em_tp_acc_circuit_struct *)item_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context->line_direction)
    {
        MMI_EM_FREE(context->line_direction);
        context->line_direction = 0;
    }
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_circuit_draw_bg
  * DESCRIPTION
  *  draw background
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_circuit_draw_bg(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 x1;
    U32 y1;
    U32 x2;
    U32 y2;
    em_tp_acc_circuit_struct *context;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    context = (em_tp_acc_circuit_struct *)item_data;

    /* draw lines*/
    x1 = context->border_width + context->pitch_x / 2;
    y1 = context->border_height + context->pitch_y / 2;
    x2 = x1 + context->pitch_x * (context->x_num - 1);
    y2 = y1 + context->pitch_y * (context->y_num - 1);
    while ( x1 <= x2 && y1 <= y2)
    {
        if ( x1 == x2 || y1 == y2)
        {
            gdi_draw_line(x1, y1, x2, y2, EM_TP_ACC_LINE_BG_COLOR);
            break;
        }
        else
        {
            gdi_draw_line(x1, y2, x1, y1, EM_TP_ACC_LINE_BG_COLOR);
            gdi_draw_line(x1, y1, x2, y1, EM_TP_ACC_LINE_BG_COLOR);
            gdi_draw_line(x2, y1, x2, y2, EM_TP_ACC_LINE_BG_COLOR);
            gdi_draw_line(x2, y2, x1 + context->pitch_x, y2, EM_TP_ACC_LINE_BG_COLOR);
            if (y2 - context->pitch_y >= y1 + context->pitch_y) /*must is ">=" not ">"*/
            {
                gdi_draw_line(x1 + context->pitch_x, y2, x1 + context->pitch_x, y2 - context->pitch_y, EM_TP_ACC_LINE_BG_COLOR);
            }
            x1 += context->pitch_x;
            x2 -= context->pitch_x;
            y1 += context->pitch_y;
            y2 -= context->pitch_y;
        }        
    }

    /*draw start position*/
    {
        x1 = context->border_width + context->pitch_x / 2;
        y1 = context->border_height + context->pitch_y / 2 + (context->y_num - 1) * context->pitch_y;
        mmi_em_tp_acc_draw_int(x1, EM_TP_MIN((S32)y1, UI_device_height - context->parent->character_h), 1);
    }
}


#define TEST_6_RECT
/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_rect_verify
 * DESCRIPTION
 *  verify current point's pass crerition 
 * PARAMETERS
 *  context     [IN]  rectangle context
 *  pos         [IN]  current coordinate of point
 *  pen_type    [IN]  pen_type: down / up / move ...
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_rect_verify(em_tp_acc_rect_struct *context,
                                                mmi_pen_point_struct pos,
                                                em_tp_acc_pen_type_enum pen_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 gap_x = 0;
    S32 gap_y = 0;
    S32 gap = 0;
    em_tp_rect_struct *rc = &(context->line_rect);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TP_ACC_PEN_DOWN == pen_type || TP_ACC_PEN_UP == pen_type)
    {
        /*distance pos and start(end) point*/
        gap = EM_TP_MAX(EM_TP_ABSSUB(pos.x, rc->x1), EM_TP_ABSSUB(pos.y, rc->y1));
    }
    else
    {
        if (pos.x >= rc->x1 && pos.x <= rc->x2 && pos.y >= rc->y1 && pos.y <= rc->y2)
        {
            /* in border rect*/
            gap_x = EM_TP_MIN(EM_TP_ABSSUB(pos.x , rc->x1), EM_TP_ABSSUB(pos.x, rc->x2));
            gap_y = EM_TP_MIN(EM_TP_ABSSUB(pos.y, rc->y1), EM_TP_ABSSUB(pos.y, rc->y2));
            gap = EM_TP_MIN(gap_x, gap_y);    
        }
        else
        {
            /*out of border rect, ohly used for border_width == border_height*/
            if ((pos.x <= rc->x1) && (pos.x <= pos.y) && (pos.x <= UI_device_height - pos.y))
            {
                gap = rc->x1 - pos.x;
            }
            else if ((pos.x >= rc->x2) && 
                        (UI_device_width - pos.x < pos.y) && 
                        (UI_device_width - pos.x <= UI_device_height - pos.y))
            {
               gap = pos.x - rc->x2;
            }
            else
            {
                gap = EM_TP_MIN(EM_TP_ABSSUB(pos.y, rc->y1), EM_TP_ABSSUB(pos.y, rc->y2));
            }   
        }
    }

    if (gap > context->non_border_pass_criterion && gap > context->parent->fail_distance)
    {
        context->parent->fail_distance = gap;
        context->parent->fail_position.x = pos.x;
        context->parent->fail_position.y = pos.y;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_rect_pen_hdlr
 * DESCRIPTION
 *  pen handler of touch panel accuracy rectangle 
 * PARAMETERS
 *  item_data   [IN]    
 *  pen_type    [IN]    down/move/up
 *  pos         [IN]    coordinate of point
 *  pressure    [IN]    pressure        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_rect_pen_hdlr(void *item_data,
                                    em_tp_acc_pen_type_enum pen_type,
                                    mmi_pen_point_struct pos,
                                    U32 pressure)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_rect_struct *context = (em_tp_acc_rect_struct *)item_data;
    mmi_pen_point_struct center;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    if (TP_ACC_PEN_DOWN != pen_type)
    {
        center.x = (pos.x + context->last_point.x) / 2;
        center.y = (pos.y + context->last_point.y) / 2;
        mmi_em_tp_acc_rect_verify(context, center, TP_ACC_PEN_MOVE);
    }
    mmi_em_tp_acc_rect_verify(context, pos,pen_type);    
    mmi_em_tp_acc_item_general_pen_hdlr(&context->last_point, &pos, pen_type);  
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_rect_data_init
  * DESCRIPTION
  *  mmi_em_tp_acc_rect_data_init
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_rect_data_init(em_tp_acc_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 boder_length;
    em_tp_acc_rect_struct *context;
    TouchPanel_EM_custom_data_struct custom_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->pen_num = EM_TP_ACC_RECT_LINE_NUMBER;
    item->data_deinit_func = NULL;
    item->draw_bg_func = mmi_em_tp_acc_rect_draw_bg;
    item->pen_hdlr_func = mmi_em_tp_acc_rect_pen_hdlr;
    item->pen_register = EM_TP_ACC_PEN_DOWN_REG | EM_TP_ACC_PEN_UP_REG | EM_TP_ACC_PEN_MOVE_REG;

    item->item_data = MMI_EM_MALLOC(sizeof(em_tp_acc_rect_struct));
    context = (em_tp_acc_rect_struct *)item->item_data;
    context->parent = item;
    
    context->last_point.x = context->last_point.y = -1;

    item->layer_width = UI_device_width / 2;
    item->layer_height = 2 * item->character_h + 2;
    item->layer_offset_x = UI_device_width / 4;
    item->layer_offset_y = UI_device_height / 2 - item->character_h;
    
    mmi_em_tp_acc_set_rect(&(item->coordinate_rect), 
                        0, 
                        0, 
                        UI_device_width / 2,
                        item->character_h);
    mmi_em_tp_acc_set_rect(&(item->pressure_rect), 
                        item->coordinate_rect.x1, 
                        item->coordinate_rect.y2, 
                        item->coordinate_rect.x2,
                        item->coordinate_rect.y2 + item->character_h);    
    item->fail_rigion.x = item->pressure_rect.x1;
    item->fail_rigion.y = item->layer_offset_y + item->pressure_rect.y2 + 4;    
    
    mmi_em_tp_ctrl_custom_data(&custom_data, TP_PARAM_GET);
    boder_length = mmi_em_tp_acc_get_pixel_from_um(custom_data.border_range);
    mmi_em_tp_acc_set_rect(&(context->line_rect), 
                        boder_length, 
                        boder_length,
                        UI_device_width -1 - boder_length,
                        UI_device_height -1 - boder_length);
    context->non_border_pass_criterion = mmi_em_tp_acc_get_pixel_from_um(custom_data.non_border_pass_criterion);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_rect_draw_bg
  * DESCRIPTION
  *  draw background
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_rect_draw_bg(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_h;
    em_tp_acc_rect_struct *context = (em_tp_acc_rect_struct *)item_data;
    em_tp_rect_struct *rc = &(context->line_rect);
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_tp_acc_draw_line_direction(rc->x1, rc->y1, rc->x2, rc->y1, EM_TP_ACC_LINE_BG_COLOR,TP_ACC_LINE_RIGHT);
    mmi_em_tp_acc_draw_line_direction(rc->x2, rc->y1, rc->x2, rc->y2, EM_TP_ACC_LINE_BG_COLOR,TP_ACC_LINE_DOWN);
    mmi_em_tp_acc_draw_line_direction(rc->x2, rc->y2, rc->x1, rc->y2, EM_TP_ACC_LINE_BG_COLOR,TP_ACC_LINE_LEFT);
    mmi_em_tp_acc_draw_line_direction(rc->x1, rc->y2, rc->x1, rc->y1, EM_TP_ACC_LINE_BG_COLOR,TP_ACC_LINE_UP);

    /*draw start position*/
    character_h = context->parent->character_h;
    mmi_em_tp_acc_draw_int(rc->x1 + 1, EM_TP_MAX(rc->y1, character_h) - character_h, 1);

    /*draw pass criterion lines*/
    mmi_em_tp_acc_rect_draw_criterion_lines(context);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_rect_draw_criterion_lines
  * DESCRIPTION
  *  mmi_em_tp_acc_rect_draw_criterion_lines
  * PARAMETERS
  *  context        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_rect_draw_criterion_lines(em_tp_acc_rect_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset = context->non_border_pass_criterion;
    
    // draw cretirion pass out_lines    
    mmi_em_tp_acc_item_draw_pass_cretirion_rect(EM_TP_MAX(context->line_rect.x1 - offset, 0),
                                    EM_TP_MAX(context->line_rect.y1 - offset, 0),
                                    EM_TP_MIN(context->line_rect.x2 + offset, UI_device_width - 1),
                                    EM_TP_MIN(context->line_rect.y2 + offset, UI_device_height - 1));
    // draw cretirion pass inner_lines    
    mmi_em_tp_acc_item_draw_pass_cretirion_rect(context->line_rect.x1 + offset,
                                    context->line_rect.y1 + offset,
                                    context->line_rect.x2 - offset,
                                    context->line_rect.y2 - offset);
}

#define TEST_7_FUNNEL
/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_funnel_verify
 * DESCRIPTION
 *  verify current point's pass crerition 
 * PARAMETERS
 *  context     [IN]  funnel context
 *  pos         [IN]  current coordinate of point 
 *  pen_type    [IN]  pen_type: down / up / move ...
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_funnel_verify(em_tp_acc_funnel_struct *context,
                                                mmi_pen_point_struct pos,
                                                em_tp_acc_pen_type_enum pen_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S32 x1;
    S32 x2;
    S32 gap_x;
    S32 gap_y;
    S32 gap;
    em_tp_rect_struct *rc = &context->line_area_rect;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TP_ACC_PEN_DOWN == pen_type || TP_ACC_PEN_UP == pen_type)
    {
        /*distance pos and start(end) point*/
        gap = EM_TP_MAX(EM_TP_ABSSUB(pos.x, rc->x1), EM_TP_ABSSUB(pos.y, rc->y1));
    }
    else
    {
        if (pos.y <= rc->y1 + context->non_border_pass_criterion)
        {
            if (pos.x - rc->x2 > context->non_border_pass_criterion)
            {
                gap = pos.x - rc->x2;
            }
            else if (rc->x1 - pos.x > context->non_border_pass_criterion)
            {
                gap = rc->x1 - pos.x;
            }
            else
            {
                gap = EM_TP_ABSSUB(rc->y1, pos.y);
            }        
        }
        else if (pos.y >= rc->y2 - context->non_border_pass_criterion)
        {
            if (pos.x - rc->x2 > context->non_border_pass_criterion)
            {
                gap = pos.x - rc->x2;
            }
            else if (rc->x1 - pos.x > context->non_border_pass_criterion)
            {
                gap = rc->x1 - pos.x;
            }
            else
            {
                gap = EM_TP_ABSSUB(rc->y2, pos.y);
            }
        }
        else
        {
            /*       (x2-x1)y + x1y2 - x2y1     */
            /*   x = ------------------------   */
            /*               y2-y1              */

            /* (x1, y1) -> (x2, y2)*/
            x1 = ((rc->x2 - rc->x1) * pos.y + rc->x1 * rc->y2 - rc->x2 * rc->y1) / (rc->y2 - rc->y1 );

            /* (x2, y1) -> (x1, y2)*/
            x2 = ((rc->x1 - rc->x2) * pos.y + rc->x2 * rc->y2 - rc->x1 * rc->y1) / (rc->y2 - rc->y1 );

            gap_x = EM_TP_MIN(EM_TP_ABSSUB(x1, pos.x), EM_TP_ABSSUB(x2, pos.x));
            gap_y = EM_TP_MIN(EM_TP_ABSSUB(rc->y1, pos.y), 
                                EM_TP_ABSSUB(rc->y2, pos.y));
            gap = EM_TP_MIN(gap_x, gap_y);
        }
	}

    if ( gap > context->non_border_pass_criterion && gap > context->parent->fail_distance)
    {
        context->parent->fail_distance = gap;
        context->parent->fail_position.x = pos.x;
        context->parent->fail_position.y = pos.y;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_funnel_pen_hdlr
 * DESCRIPTION
 *  pen handler of touch panel accuracy funnel 
 * PARAMETERS
 *  item_data   [IN]    
 *  pen_type    [IN]    down/move/up
 *  pos         [IN]    coordinate of point        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_funnel_pen_hdlr(void *item_data,
                                            em_tp_acc_pen_type_enum pen_type,
                                            mmi_pen_point_struct pos,
                                            U32 pressure)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_funnel_struct *context = (em_tp_acc_funnel_struct *)item_data;
    mmi_pen_point_struct center;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TP_ACC_PEN_DOWN != pen_type)
    {
        center.x = (pos.x + context->last_point.x) / 2;
        center.y = (pos.y + context->last_point.y) / 2;
        mmi_em_tp_acc_funnel_verify(context, center, TP_ACC_PEN_MOVE);
    }
    mmi_em_tp_acc_funnel_verify(context, pos,pen_type);    
    mmi_em_tp_acc_item_general_pen_hdlr(&context->last_point, &pos, pen_type);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_funnel_data_init
  * DESCRIPTION
  *  mmi_em_tp_acc_funnel_data_init
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_funnel_data_init(em_tp_acc_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 boder_length;    	
    em_tp_acc_funnel_struct *context;
    TouchPanel_EM_custom_data_struct custom_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->pen_num = EM_TP_ACC_FUNNEL_LINE_NUMBER;
    item->data_deinit_func = NULL;
    item->draw_bg_func = mmi_em_tp_acc_funnel_draw_bg;
    item->pen_hdlr_func = mmi_em_tp_acc_funnel_pen_hdlr;
    item->pen_register = EM_TP_ACC_PEN_DOWN_REG | EM_TP_ACC_PEN_UP_REG | EM_TP_ACC_PEN_MOVE_REG;
    
    item->item_data = MMI_EM_MALLOC(sizeof(em_tp_acc_funnel_struct));
    context = (em_tp_acc_funnel_struct *)item->item_data;
    context->parent = item;
    
    context->last_point.x = context->last_point.y = -1;

    item->layer_width = UI_device_width;
    item->layer_height = item->character_h + 2;
    item->layer_offset_x = 0;
    item->layer_offset_y = (UI_device_height - item->character_h)/2;
    mmi_em_tp_acc_set_rect(&(item->coordinate_rect), 
                        0, 
                        0, 
                        UI_device_width / 3,
                        item->character_h);
    mmi_em_tp_acc_set_rect(&(item->pressure_rect), 
                        UI_device_width - item->coordinate_rect.x2, 
                        item->coordinate_rect.y1, 
                        UI_device_width - 1,
                        item->coordinate_rect.y2);    
    item->fail_rigion.x = item->coordinate_rect.x1;
    item->fail_rigion.y = item->layer_offset_y + item->coordinate_rect.y2 + item->character_h;  
    
    mmi_em_tp_ctrl_custom_data(&custom_data, TP_PARAM_GET);
    boder_length = mmi_em_tp_acc_get_pixel_from_um(custom_data.border_range);
    mmi_em_tp_acc_set_rect(&(context->line_area_rect), 
                        boder_length, 
                        boder_length,
                        UI_device_width - 1- boder_length,
                        UI_device_height - 1 - boder_length);
    context->non_border_pass_criterion = mmi_em_tp_acc_get_pixel_from_um(custom_data.non_border_pass_criterion);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_funnel_draw_bg
  * DESCRIPTION
  *  draw background
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_funnel_draw_bg(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_h;
    em_tp_acc_funnel_struct *context = (em_tp_acc_funnel_struct *)item_data;
    em_tp_rect_struct *rc = &(context->line_area_rect);
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_em_tp_acc_draw_line_direction(rc->x1, rc->y1, rc->x2, rc->y1, EM_TP_ACC_LINE_BG_COLOR, TP_ACC_LINE_RIGHT);
       
    gdi_draw_line(rc->x2, rc->y1, rc->x1, rc->y2, EM_TP_ACC_LINE_BG_COLOR);
    gdi_draw_line(rc->x1 + 3, rc->y2 - EM_TP_ACC_LINE_ARROW_LEN, rc->x1, rc->y2, EM_TP_ACC_LINE_BG_COLOR);
    gdi_draw_line(rc->x1 + EM_TP_ACC_LINE_ARROW_LEN, rc->y2 - 3, rc->x1, rc->y2, EM_TP_ACC_LINE_BG_COLOR);
    
    mmi_em_tp_acc_draw_line_direction(rc->x1, rc->y2, rc->x2, rc->y2, EM_TP_ACC_LINE_BG_COLOR, TP_ACC_LINE_RIGHT);
    
    gdi_draw_line(rc->x2, rc->y2, rc->x1, rc->y1, EM_TP_ACC_LINE_BG_COLOR);
    gdi_draw_line(rc->x1+3, rc->y1 + EM_TP_ACC_LINE_ARROW_LEN, rc->x1, rc->y1, EM_TP_ACC_LINE_BG_COLOR); 
    gdi_draw_line(rc->x1+EM_TP_ACC_LINE_ARROW_LEN, rc->y1 + 3, rc->x1, rc->y1, EM_TP_ACC_LINE_BG_COLOR);

    /*draw start position*/
    character_h = context->parent->character_h;
    mmi_em_tp_acc_draw_int(rc->x1 + 1, EM_TP_MAX(rc->y1, character_h) - character_h, 1);

    /*draw pass cretirion line*/
    mmi_em_tp_acc_funnel_draw_criterion_lines(context);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_funnel_draw_criterion_lines
  * DESCRIPTION
  *  mmi_em_tp_acc_funnel_draw_criterion_lines
  * PARAMETERS
  *  context        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_funnel_draw_criterion_lines(em_tp_acc_funnel_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 x_offset;
    S32 y_offset;
    S32 delta_x;
    S32 delta_y;
    em_tp_triple_struct triple;
    mmi_pen_point_struct *points;
    em_tp_rect_struct *rc = &(context->line_area_rect);    
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /*draw pass cretirion line*/       
    if (UI_device_width < UI_device_height)
    {
        x_offset = context->non_border_pass_criterion;
    }
    else
    {
        y_offset = context->non_border_pass_criterion;
        x_offset = y_offset * (UI_device_width - 2 * y_offset)/ (UI_device_height - 2 * y_offset);
    }

    delta_x = context->non_border_pass_criterion * (rc->x2 - rc->x1) / (rc->y2 - rc->y1);
    delta_y = x_offset * (rc->y2 - rc->y1) / (rc->x2 - rc->x1);
    
    triple.p1.x = rc->x1 + delta_x + x_offset;
    triple.p1.y = rc->y1 + context->non_border_pass_criterion;
    triple.p2.x = rc->x2 - delta_x - x_offset;
    triple.p2.y = rc->y1 + context->non_border_pass_criterion;
    triple.p3.x = UI_device_width / 2;
    triple.p3.y = UI_device_height / 2 - delta_y;
    if (triple.p1.x < triple.p2.x && triple.p1.y < triple.p3.y)
        mmi_em_tp_acc_item_draw_pass_cretirion_triple(&triple);
    else
        gdi_draw_solid_circle((rc->x1 + rc->x2 + UI_device_width / 2) / 3, (2 * rc->y1 + UI_device_height / 2)/3, 
                                    2, EM_TP_ACC_PASS_CRETIRION_LINE_COLOR);

    triple.p1.y = rc->y2 - context->non_border_pass_criterion;
    triple.p2.y = rc->y2 - context->non_border_pass_criterion;
    triple.p3.y = UI_device_height / 2 + delta_y;
    if (triple.p1.x < triple.p2.x && triple.p1.y > triple.p3.y)
        mmi_em_tp_acc_item_draw_pass_cretirion_triple(&triple);
    else
        gdi_draw_solid_circle((rc->x1 + rc->x2 + UI_device_width / 2) / 3, (2 * rc->y2 + UI_device_height / 2)/3, 
                                    2, EM_TP_ACC_PASS_CRETIRION_LINE_COLOR);

    points = OslMalloc(14 * sizeof(mmi_pen_point_struct));
    points[0].x = EM_TP_MAX(rc->x1 - context->non_border_pass_criterion, 0);
    points[0].y = EM_TP_MAX(rc->y1 - context->non_border_pass_criterion, 0);
    points[1].x = EM_TP_MIN(rc->x2 + context->non_border_pass_criterion, UI_device_width - 1);
    points[1].y = points[0].y;
    points[2].x = points[1].x;
    points[2].y = rc->y1 + context->non_border_pass_criterion;
    points[3].x = EM_TP_MIN(rc->x2 + context->non_border_pass_criterion - delta_x, UI_device_width - 1);
    points[3].y = points[2].y;
    points[4].x = UI_device_width / 2 + context->non_border_pass_criterion;
    points[4].y = UI_device_height / 2;
    points[5].x = points[3].x;
    points[5].y = rc->y2 - context->non_border_pass_criterion;
    points[6].x = points[2].x;
    points[6].y = points[5].y;
    points[7].x = points[6].x;
    points[7].y = EM_TP_MIN(rc->y2 + context->non_border_pass_criterion, UI_device_height - 1);
    points[8].x = points[0].x;
    points[8].y = points[7].y;
    points[9].x = points[0].x;
    points[9].y = points[6].y;
    points[10].x = EM_TP_MAX(rc->x1 - context->non_border_pass_criterion + delta_x, 0);
    points[10].y = points[9].y;
    points[11].x = UI_device_width / 2 - context->non_border_pass_criterion;
    points[11].y = UI_device_height / 2;
    points[12].x = points[10].x;
    points[12].y = points[3].y;
    points[13].x = points[0].x;
    points[13].y = points[12].y;

    for (i = 0; i< 14; i++)
    {
        mmi_em_tp_acc_item_draw_pass_cretirion_line(points[i].x, points[i].y, 
                                                    points[(i+1)%14].x, points[(i+1)%14].y);
    }        
    OslMfree(points);    
}


#define TEST_8_DUAL_RECT
/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_dual_rect_verify
 * DESCRIPTION
 *  verify current point's pass crerition 
 * PARAMETERS
 *  context     [IN]  two rect context
 *  pos         [IN]  current coordinate of point
 *  pen_type    [IN]  pen_type: down / up / move ...
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_dual_rect_verify(em_tp_acc_dual_rect_struct *context,
                                                mmi_pen_point_struct pos,
                                                em_tp_acc_pen_type_enum pen_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_rect_struct *rc = &context->border_rect;
    S32 gap_x;
    S32 gap_y; 
    S32 gap;
    S32 criterion = context->non_border_pass_criterion;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TP_ACC_PEN_DOWN == pen_type || TP_ACC_PEN_UP == pen_type)
    {
        /*distance pos and start(end) point*/
        gap = EM_TP_MAX(EM_TP_ABSSUB(pos.x, rc->x1), EM_TP_ABSSUB(pos.y, rc->y1));
    }
    else
    {
        if ((pos.x <= UI_device_width / 2) && (pos.y <= UI_device_height / 2))
        {
            /* left up 1/4 rect*/
            if (pos.x >= rc->x1 && pos.y >= rc->y1)
            {
                gap_x = EM_TP_MIN(pos.x - rc->x1, UI_device_width / 2 - pos.x);
                gap_y = EM_TP_MIN(pos.y - rc->y1, UI_device_height / 2 - pos.y);
                gap = EM_TP_MIN(gap_x, gap_y);
            }
            else
            {
                if (pos.x <= pos.y)
                {
                    gap = rc->x1 - pos.x;
                }
                else
                {
                    gap = rc->y1 - pos.y;
                }
            }
        }
        else if ((pos.x >= UI_device_width / 2) && (pos.y >= UI_device_height / 2))
        {
            /* right down 1/4 rect*/
            if (pos.x <= rc->x2 && pos.y <= rc->y2)
            {
                gap_x = EM_TP_MIN(rc->x2 - pos.x, pos.x - UI_device_width / 2);
                gap_y = EM_TP_MIN(rc->y2 - pos.y, pos.y - UI_device_height / 2);
                gap = EM_TP_MIN(gap_x, gap_y);
            }
            else
            {
                if (UI_device_width - pos.x <= UI_device_height - pos.y)
                {
                    gap = pos.x - rc->x2;
                }
                else
                {
                    gap = pos.y - rc->y2;
                }
            }
        }
        else if ((pos.x >= UI_device_width / 2) && (pos.y <= UI_device_height / 2))
        {
            /* right up 1/4 rect */
            if ((pos.y <= rc->y1) && (pos.x - UI_device_width / 2 <= rc->y1 - pos.y))
            {
                gap = rc->y1 - pos.y;
            }
            else if ((pos.x >= rc->x2) && (pos.x - rc->x2 >= UI_device_height / 2 - pos.y))
            {
                gap = pos.x - rc->x2;
            }
            else
            {
                gap_x = pos.x - UI_device_width / 2;
                gap_y = UI_device_height / 2 - pos.y;
                gap = EM_TP_MIN(gap_x, gap_y);
            }            
        }
        else
        {
            /* left down 1/4 rect */
            if ((pos.x <= rc->x1) && (rc->x1 - pos.x >= pos.y - UI_device_height / 2))
            {
    			gap = rc->x1 - pos.y;
            }
            else if ((pos.y >= rc->y2) && (UI_device_width / 2 - pos.x <= pos.y - rc->y2))
            {
    			gap = pos.y - rc->y2;
            }
            else
            {
    			gap_x = UI_device_width / 2 - pos.x;
                gap_y =pos.y - UI_device_height / 2;
                gap = EM_TP_MIN(gap_x, gap_y);
            }
        }
    }
    
    if (gap > criterion && gap > context->parent->fail_distance)
    {
        context->parent->fail_distance = gap;
        context->parent->fail_position.x = pos.x;
        context->parent->fail_position.y = pos.y;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_dual_rect_pen_hdlr
 * DESCRIPTION
 *  pen handler of touch panel accuracy two rect 
 * PARAMETERS
 *  item_data   [IN]    
 *  pen_type    [IN]    down/move/up
 *  pos         [IN]    coordinate of point
 *  pressure    [IN]    pressure        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_dual_rect_pen_hdlr(void *item_data,
                                            em_tp_acc_pen_type_enum pen_type,
                                            mmi_pen_point_struct pos,
                                            U32 pressure)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_dual_rect_struct *context = (em_tp_acc_dual_rect_struct *)item_data;
    mmi_pen_point_struct center;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TP_ACC_PEN_DOWN != pen_type)
    {
        center.x = (pos.x + context->last_point.x) / 2;
        center.y = (pos.y + context->last_point.y) / 2;
        mmi_em_tp_acc_dual_rect_verify(context, center, TP_ACC_PEN_MOVE);
    }
    mmi_em_tp_acc_dual_rect_verify(context, pos,pen_type);
    mmi_em_tp_acc_item_general_pen_hdlr(&context->last_point, &pos, pen_type);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_dual_rect_data_init
  * DESCRIPTION
  *  mmi_em_tp_acc_dual_rect_data_init
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_dual_rect_data_init(em_tp_acc_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 border_length;
    em_tp_acc_dual_rect_struct *context;
    TouchPanel_EM_custom_data_struct custom_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->data_deinit_func = NULL;
    item->pen_num = EM_TP_ACC_DUAL_RECT_LINE_NUMBER;
    item->draw_bg_func = mmi_em_tp_acc_dual_rect_draw_bg;
    item->pen_hdlr_func= mmi_em_tp_acc_dual_rect_pen_hdlr;
    item->pen_register = EM_TP_ACC_PEN_DOWN_REG | EM_TP_ACC_PEN_UP_REG | EM_TP_ACC_PEN_MOVE_REG;
    
    item->item_data = MMI_EM_MALLOC(sizeof(em_tp_acc_dual_rect_struct));
    context = (em_tp_acc_dual_rect_struct *)item->item_data;
    context->parent = item;
    
    context->last_point.x = context->last_point.y = -1;

    item->layer_width = UI_device_width;
    item->layer_height = UI_device_height *3 / 4 + item->character_h;
    item->layer_offset_x = 0;
    item->layer_offset_y = 0;
    mmi_em_tp_acc_set_rect(&(item->coordinate_rect), 
                        UI_device_width * 2 / 3, 
                        UI_device_height/ 4, 
                        UI_device_width,
                        UI_device_height/ 4 + item->character_h);
    mmi_em_tp_acc_set_rect(&(item->pressure_rect), 
                        UI_device_width / 4, 
                        UI_device_height *3 / 4,
                        UI_device_width/2 - 10,
                        UI_device_height *3 / 4 + item->character_h); 
    item->fail_rigion.x = 10;
    item->fail_rigion.y = UI_device_height / 2;   
    
    mmi_em_tp_ctrl_custom_data(&custom_data, TP_PARAM_GET);
    border_length = mmi_em_tp_acc_get_pixel_from_um(custom_data.border_range);
    context->line_area_points[0].x = border_length;
    context->line_area_points[0].y = border_length;    
    context->line_area_points[1].x = UI_device_width/2;
    context->line_area_points[1].y = border_length;    
    context->line_area_points[2].x = UI_device_width/2;
    context->line_area_points[2].y = UI_device_height - border_length;    
    context->line_area_points[3].x = UI_device_width - border_length;
    context->line_area_points[3].y = UI_device_height - border_length;    
    context->line_area_points[4].x = UI_device_width - border_length;
    context->line_area_points[4].y = UI_device_height/2;    
    context->line_area_points[5].x = border_length;
    context->line_area_points[5].y = UI_device_height/2;     

    mmi_em_tp_acc_set_rect(&context->border_rect, 
                                border_length,
                                border_length,
                                UI_device_width - 1 - border_length,
                                UI_device_height - 1 - border_length);
    
    context->non_border_pass_criterion = mmi_em_tp_acc_get_pixel_from_um(custom_data.non_border_pass_criterion);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_dual_rect_draw_bg
  * DESCRIPTION
  *  draw background
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_dual_rect_draw_bg(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 character_h;
    em_tp_acc_dual_rect_struct *context;
    em_tp_acc_line_direction_enum direction;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context = (em_tp_acc_dual_rect_struct *)item_data;
    for (i = 0; i< 6; i++)
    {
        if (0 == i || 2 == i)
        {
            direction = TP_ACC_LINE_RIGHT;
        }
        else if ( 1 == i)
        {
            direction = TP_ACC_LINE_DOWN;
        }
        else if ( 4 == i)
        {
            direction = TP_ACC_LINE_LEFT;
        }
        else
        {
            direction = TP_ACC_LINE_UP;
        }
        mmi_em_tp_acc_draw_line_direction(context->line_area_points[i].x, 
                        context->line_area_points[i].y,
                        context->line_area_points[(i + 1)%6].x,
                        context->line_area_points[(i + 1)%6].y,
                        EM_TP_ACC_LINE_BG_COLOR,
                        direction);
    } 
    character_h = context->parent->character_h;
    /*draw start position*/
    mmi_em_tp_acc_draw_int(context->line_area_points[0].x + 1, 
                            EM_TP_MAX(context->line_area_points[0].y, character_h) - character_h, 1);


    /*draw pass criterion line*/
    mmi_em_tp_acc_dual_rect_draw_criterion_lines(context);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_dual_rect_draw_criterion_lines
  * DESCRIPTION
  *  mmi_em_tp_acc_dual_rect_draw_criterion_lines
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_dual_rect_draw_criterion_lines(em_tp_acc_dual_rect_struct *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 offset;
    mmi_pen_point_struct *out_lines;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset = context->non_border_pass_criterion;
    mmi_em_tp_acc_item_draw_pass_cretirion_rect(context->line_area_points[0].x + offset,
                                                context->line_area_points[0].y + offset,
                                                context->line_area_points[1].x - offset,
                                                context->line_area_points[5].y - offset);
    mmi_em_tp_acc_item_draw_pass_cretirion_rect(context->line_area_points[1].x + offset,
                                                context->line_area_points[4].y + offset,
                                                context->line_area_points[3].x - offset,
                                                context->line_area_points[3].y - offset);

    out_lines = OslMalloc(8 * sizeof(mmi_pen_point_struct));
    out_lines[0].x = EM_TP_MAX(context->line_area_points[0].x - offset, 0);
    out_lines[0].y = EM_TP_MAX(context->line_area_points[0].y - offset, 0);
    out_lines[1].x = EM_TP_MIN(context->line_area_points[1].x + offset, UI_device_width - 1);
    out_lines[1].y = out_lines[0].y;
    out_lines[2].x = out_lines[1].x;
    out_lines[2].y = EM_TP_MAX(context->line_area_points[4].y - offset, 0);
    out_lines[3].x = EM_TP_MIN(context->line_area_points[4].x + offset, UI_device_width - 1);
    out_lines[3].y = out_lines[2].y;
    out_lines[4].x = out_lines[3].x;
    out_lines[4].y = EM_TP_MIN(context->line_area_points[3].y + offset, UI_device_height - 1);
    out_lines[5].x = EM_TP_MAX(context->line_area_points[2].x - offset, 0);
    out_lines[5].y = out_lines[4].y;
    out_lines[6].x = out_lines[5].x;
    out_lines[6].y = EM_TP_MIN(context->line_area_points[5].y + offset, UI_device_height - 1);
    out_lines[7].x = out_lines[0].x;
    out_lines[7].y = out_lines[6].y; 
    for(i =0; i< 8; i++)
    {
        mmi_em_tp_acc_item_draw_pass_cretirion_line(out_lines[i].x,
                                                    out_lines[i].y,
                                                    out_lines[(i+1)%8].x,
                                                    out_lines[(i+1)%8].y);
    }
    OslMfree(out_lines);
}

#define TEST_9_JITTER
/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_jitter_verify
 * DESCRIPTION
 *  verify current point's pass crerition 
 * PARAMETERS
 *  context     [IN]  two rect context
 *  pos         [IN]  current coordinate of point     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_jitter_verify(em_tp_acc_jitter_struct *context,
                                                mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fail_distance;
    S32 fail_criterion;
    U32 cur_point;
    S32 len2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_point = context->parent->cur_index;

    len2 = (pos.x - context->circles_ptr[cur_point].cx) * (pos.x - context->circles_ptr[cur_point].cx) + 
        (pos.y - context->circles_ptr[cur_point].cy) * (pos.y - context->circles_ptr[cur_point].cy);
    fail_criterion = context->circles_ptr[cur_point].r;
    if (len2 > fail_criterion * fail_criterion)
    {
        fail_distance = (S32)sqrt((double)len2);
        if (fail_distance == fail_criterion)
        {
			fail_distance += 1;
        }
        if (fail_distance > context->parent->fail_distance)
        {
            context->parent->fail_distance = fail_distance;
            context->parent->fail_position.x = pos.x;
            context->parent->fail_position.y = pos.y;
        }
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_jitter_pen_hdlr
 * DESCRIPTION
 *  pen handler of touch panel accuracy two rect 
 * PARAMETERS
 *  item_data   [IN]    
 *  pen_type    [IN]    down/move/up
 *  pos         [IN]    coordinate of point
 *  pressure    [IN]    pressure
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_jitter_pen_hdlr(void *item_data,
                                            em_tp_acc_pen_type_enum pen_type,
                                            mmi_pen_point_struct pos,
                                            U32 pressure)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_jitter_struct *context = (em_tp_acc_jitter_struct *)item_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_tp_acc_jitter_verify(context, pos);
    if (TP_ACC_PEN_UP != pen_type)
    {
        gdi_draw_solid_circle(pos.x, pos.y, EM_TP_ACC_CIRCLE_FG_R, EM_TP_ACC_CIRCLE_FG_COLOR);
    }
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_jitter_data_init
  * DESCRIPTION
  *  mmi_em_tp_acc_jitter_data_init
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_jitter_data_init(em_tp_acc_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 pitch;
    U32 index;
    U32 index_x;
    U32 index_y;
    em_tp_acc_jitter_struct *context;
    TouchPanel_EM_custom_data_struct custom_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->data_deinit_func = mmi_em_tp_acc_jitter_data_deinit;
    item->draw_bg_func = mmi_em_tp_acc_jitter_draw_bg;
    item->pen_hdlr_func= mmi_em_tp_acc_jitter_pen_hdlr;
    item->pen_register = EM_TP_ACC_PEN_DOWN_REG | 
                        EM_TP_ACC_PEN_UP_REG | 
                        EM_TP_ACC_PEN_MOVE_REG |
                        EM_TP_ACC_PEN_REPEAT_REG;
    
    item->item_data = MMI_EM_MALLOC(sizeof(em_tp_acc_jitter_struct));
    context = (em_tp_acc_jitter_struct *)item->item_data;
    context->parent = item;

    mmi_em_tp_ctrl_custom_data(&custom_data, TP_PARAM_GET);    
    context->border_range = mmi_em_tp_acc_get_pixel_from_um(custom_data.border_range);
    context->non_border_pass_criterion = mmi_em_tp_acc_get_pixel_from_um(custom_data.non_border_pass_criterion);
    context->border_pass_criterion = mmi_em_tp_acc_get_pixel_from_um(custom_data.border_pass_criterion);
    pitch = mmi_em_tp_acc_get_pixel_from_um(custom_data.jitter_circuit_interval);
    if (0 == pitch)
    {
        pitch = 50;
    }
    else if (pitch > (U32)(UI_device_width - context->border_range) ||
                pitch > (U32)(UI_device_height- context->border_range))
    {
        pitch = EM_TP_MIN(UI_device_width, UI_device_height) - context->border_range;
    }
    context->pitch_x = pitch;
    context->pitch_y = pitch;
       
    context->num_x = (UI_device_width - context->border_range) / pitch + 1;
    context->num_y = (UI_device_height - context->border_range ) / pitch + 1;
    context->num_point = context->num_x * context->num_y;
    context->cur_point = 0;
    item->pen_num = context->num_point;

    context->circles_ptr = MMI_EM_MALLOC(sizeof(em_tp_circle_struct) * context->num_point);
    for (index = 0; index < context->num_point; ++index)
    {
        index_x = index % context->num_x;
        index_y = index / context->num_x;
        context->circles_ptr[index].cx = context->border_range / 2 +  
							(UI_device_width - context->border_range ) * index_x / (context->num_x - 1);
        context->circles_ptr[index].cy = context->border_range / 2 +  
                            (UI_device_height - context->border_range ) * index_y / (context->num_y - 1);
        if (0 == index_x ||  context->num_x - 1 == index_x || 0 == index_y || context->num_y - 1 == index_y)
        {
            context->circles_ptr[index].r = context->border_pass_criterion;
        }
        else
        {
            context->circles_ptr[index].r = context->non_border_pass_criterion;
        }        
    }

    item->layer_width = UI_device_width;
    item->layer_height = item->character_h;
    item->layer_offset_x = 0;
    item->layer_offset_y = 0;

    mmi_em_tp_acc_set_rect(&(item->coordinate_rect), 
                        0, 
                        0, 
                        item->layer_width / 2,
                        item->layer_height);
    mmi_em_tp_acc_set_rect(&(item->pressure_rect), 
                        item->layer_width / 2 + 1, 
                        0,
                        item->layer_width - 1,
                        item->layer_height);
     
    item->fail_rigion.x = item->coordinate_rect.x1;
    item->fail_rigion.y = UI_device_height / 2 + item->coordinate_rect.y2 + 4;
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_jitter_data_deinit
  * DESCRIPTION
  *  mmi_em_tp_acc_jitter_data_deinit
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_jitter_data_deinit(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_jitter_struct *context = (em_tp_acc_jitter_struct *)item_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context->circles_ptr)
    {
        MMI_EM_FREE(context->circles_ptr);
        context->circles_ptr = 0;
    }
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_jitter_draw_bg
  * DESCRIPTION
  *  draw background
  * PARAMETERS
  *  item_data        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_jitter_draw_bg(void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    S32 string_w;
    S32 string_h;
    em_tp_acc_jitter_struct *context;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    context = (em_tp_acc_jitter_struct *)item_data;    
    gdi_draw_rect(context->border_range, 
                    context->border_range, 
                    UI_device_width - context->border_range, 
                    UI_device_height- context->border_range, 
                    EM_TP_ACC_LINE_BG_COLOR); 
    gui_measure_string(L"88", &string_w, &string_h);
    
    for (index = 0; index < context->num_point; ++index)
    {
        gdi_draw_solid_circle(context->circles_ptr[index].cx,
                                context->circles_ptr[index].cy,
                                context->circles_ptr[index].r,
                                EM_TP_ACC_CIRCLE_BG_COLOR);
    }

    for (index = 0; index < context->num_point; index += context->num_x)
    {
        /*draw circle sequence number at the first one of one row*/
        if ((context->circles_ptr[0].r + context->circles_ptr[1].r + string_w < context->pitch_x) &&
                (context->circles_ptr[0].r + context->circles_ptr[1 + context->num_x].r + string_w < context->pitch_x))
        {
            mmi_em_tp_acc_draw_int(context->circles_ptr[index].cx + context->circles_ptr[index].r,
                EM_TP_MAX((context->circles_ptr[index].cy - string_h / 2), 0),
                index + 1);
        }
        else
        {
            mmi_em_tp_acc_draw_int(EM_TP_MAX(context->circles_ptr[index].cx - string_w / 2, 0),
                EM_TP_MAX((context->circles_ptr[index].cy - string_h / 2), 0),
                index + 1);
        }
    }
}


#define ACC_TEST_ITEM

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_item_draw_pass_cretirion_line
 * DESCRIPTION
 *  mmi_em_tp_acc_item_draw_pass_cretirion_line
 * PARAMETERS
 *  x1, y1        [IN] point one's coordinate
 *  x2, y2        [IN] point two's coordinate
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_em_tp_acc_item_draw_pass_cretirion_line(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bitvalues[6] = {1,1,1,0,0,0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_line_style(x1, y1, x2, y2, EM_TP_ACC_PASS_CRETIRION_LINE_COLOR, sizeof(bitvalues),bitvalues);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_item_draw_pass_cretirion_rect
 * DESCRIPTION
 *  mmi_em_tp_acc_item_draw_pass_cretirion_rect
 * PARAMETERS
 *  x1, y1, x2, y2        [IN] rect's coordinate
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_em_tp_acc_item_draw_pass_cretirion_rect(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x1 >=x2 || y1 >= y2)
    {
        gdi_draw_solid_circle((x1+x2)/2, (y1+y2)/2, 2, EM_TP_ACC_PASS_CRETIRION_LINE_COLOR);
    }
    else
    {
		mmi_em_tp_acc_item_draw_pass_cretirion_line(x1, y1, x2, y1);
		mmi_em_tp_acc_item_draw_pass_cretirion_line(x2, y1, x2, y2);
		mmi_em_tp_acc_item_draw_pass_cretirion_line(x2, y2, x1, y2);
		mmi_em_tp_acc_item_draw_pass_cretirion_line(x1, y2, x1, y1);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_item_draw_pass_cretirion_triple
 * DESCRIPTION
 *  mmi_em_tp_acc_item_draw_pass_cretirion_triple
 * PARAMETERS
 *  pTri        [IN]
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_em_tp_acc_item_draw_pass_cretirion_triple(em_tp_triple_struct *pTri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_tp_acc_item_draw_pass_cretirion_line(pTri->p1.x, pTri->p1.y, pTri->p2.x, pTri->p2.y);
    mmi_em_tp_acc_item_draw_pass_cretirion_line(pTri->p2.x, pTri->p2.y, pTri->p3.x, pTri->p3.y);
    mmi_em_tp_acc_item_draw_pass_cretirion_line(pTri->p3.x, pTri->p3.y, pTri->p1.x, pTri->p1.y);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_item_general_pen_hdlr
 * DESCRIPTION
 *  mmi_em_tp_acc_item_general_pen_hdlr
 * PARAMETERS
 *  last_point          [IN]
 *  mow_point           [IN]
 *  pen_type            [IN]
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static void mmi_em_tp_acc_item_general_pen_hdlr(mmi_pen_point_struct* last_point, 
                                                mmi_pen_point_struct* now_point,
                                                em_tp_acc_pen_type_enum pen_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TP_ACC_PEN_MOVE == pen_type || TP_ACC_PEN_UP == pen_type)
    {
        gdi_draw_line(last_point->x, last_point->y, now_point->x, now_point->y, EM_TP_ACC_LINE_FG_COLOR);
    }
    last_point->x = now_point->x;
    last_point->y = now_point->y;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_item_draw_error
 * DESCRIPTION
 *  mmi_em_tp_acc_item_draw_error
 * PARAMETERS
 *  error_string        [IN]
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static void mmi_em_tp_acc_item_draw_error(MMI_ID parent_id, U16* error_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple(error_string, MMI_EVENT_INFO, parent_id, NULL);    
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
static MMI_RET mmi_em_tp_acc_item_pen_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_touch_data_struct *touch_data;
    em_tp_acc_pen_type_enum pen_type;
    em_tp_acc_item_struct *item = (em_tp_acc_item_struct *)param->user_data;
    mmi_multi_touch_event_struct *evt = (mmi_multi_touch_event_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (EVT_ID_ON_TOUCH == param->evt_id && item->pen_hdlr_func)
    {
        touch_data = evt->touch_data;
        pen_type = TP_ACC_PEN_TYPE_END_OF_ENUM;
        switch (touch_data->event)
        {
            case MMI_PEN_EVENT_DOWN:
                if (item->pen_register & EM_TP_ACC_PEN_DOWN_REG)
                {
                    pen_type = TP_ACC_PEN_DOWN;
                }
                break;

            case MMI_PEN_EVENT_UP:
                if (item->pen_register & EM_TP_ACC_PEN_UP_REG)
                {
                    pen_type = TP_ACC_PEN_UP;
                }
                break;

           case MMI_PEN_EVENT_MOVE:
                if (item->pen_register & EM_TP_ACC_PEN_MOVE_REG)
                {
                    pen_type = TP_ACC_PEN_MOVE;
                }
                break;

           case MMI_PEN_EVENT_REPEAT:
                if (item->pen_register & EM_TP_ACC_PEN_REPEAT_REG)
                {
                    pen_type = TP_ACC_PEN_REPEATE;
                }
                break;   
           default:
                break;
        }
        if (pen_type != TP_ACC_PEN_TYPE_END_OF_ENUM)
        {
            if (!item->is_test_finish && item->cur_index < item->pen_num)
            {
                gui_lock_double_buffer();
                item->pen_hdlr_func(item->item_data,
                                    pen_type,
                                    touch_data->currpos.pos,
                                    touch_data->area);
                
                if (TP_ACC_PEN_UP == pen_type)
                {
                    item->cur_index++;
                    if (item->cur_index == item->pen_num)
                    {
                        mmi_em_tp_acc_draw_result(item);
                        item->is_test_finish = 1;
                    }
                    if (item->is_test_finish)
                    {
                        mmi_em_tp_acc_item_test_finish_hdlr(item);
                    }
                }
                else
                {
                    /*draw coordination and pressure value*/
                    mmi_em_tp_acc_draw_position_and_pressure(item,
                                                &touch_data->currpos.pos,
                                                touch_data->area,
                                                EM_TP_ACC_BG_COLOR);
                }               
                
                gui_unlock_double_buffer();
                gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
            }            
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_item_rsk_hdlr
 * DESCRIPTION
 *  right softkey handler
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_tp_acc_item_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_item_data_init
  * DESCRIPTION
  *  mmi_em_tp_acc_item_data_init
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_item_data_init(em_tp_acc_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TouchPanel_EM_custom_data_struct custom_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->character_h = gui_get_character_height();
    item->item_data = 0;
    item->cur_index = 0;
    item->fail_distance = 0;
    item->layer_width = 0;
    item->layer_height = 0;

    mmi_em_tp_ctrl_custom_data(&custom_data, TP_PARAM_GET);
    item->dump_screen = custom_data.Dump_Screen;
    
    if ( g_data_init_func[item->item_id - MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_AUTO])
    {
        g_data_init_func[item->item_id - MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_AUTO](item);
        if (item->layer_width == 0 || item->layer_height == 0)
        {
            item->layer_handle = 0;
        }
        else
        {
            gdi_layer_create(item->layer_offset_x,
                                item->layer_offset_y,
                                item->layer_width,
                                item->layer_height,
                                &(item->layer_handle));
        }
    }   
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_item_draw_bg
  * DESCRIPTION
  *  mmi_em_tp_acc_item_draw_bg
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_item_draw_bg(em_tp_acc_item_struct * item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle base_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gdi_draw_solid_rect(0, 0, UI_device_width, UI_device_height, EM_TP_ACC_BG_COLOR);
    item->draw_bg_func(item->item_data);
    gdi_layer_get_base_handle(&base_handle);
    gdi_layer_set_blt_layer(base_handle, 0, 0, 0);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height- 1);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_item_set_hdlr
  * DESCRIPTION
  *  set key&pen handler
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_item_set_hdlr(em_tp_acc_item_struct * item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__    
    SetKeyHandler(mmi_em_tp_acc_item_rsk_hdlr, KEY_RSK, KEY_EVENT_UP);
#else   /*__COSMOS_MMI_PACKAGE__*/
	SetKeyHandler(mmi_em_tp_acc_item_rsk_hdlr, KEY_BACK, KEY_EVENT_UP);
#endif  /*__COSMOS_MMI_PACKAGE__*/ 

    if (0 == item->is_error_happen)
    {
        mmi_frm_touch_set_mode(MMI_FRM_SINGLE_TOUCH);
        mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_2, MMI_PEN_SAMPLING_PERIOD_2);
        mmi_frm_touch_register_proc(mmi_em_tp_acc_item_pen_proc, item);
    }    
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_item_prepare
  * DESCRIPTION
  *  do anything to prepare test 
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_item_prepare(em_tp_acc_item_struct * item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->is_test_finish = 0;
    item->is_error_happen = 0;
    gui_set_font(&MMI_small_font);
    mmi_em_tp_acc_item_data_init(item);
    if (item->is_error_happen)
    {
        mmi_frm_group_set_attribute(item->group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_frm_scrn_close(item->group_id, SCR_ID_EM_MISC_TOUCH_SCREEN_ACC_ACCURACY);
    }
    else
    {
        mmi_em_tp_acc_item_draw_bg(item);
        mmi_em_tp_acc_item_set_hdlr(item);
    }
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_item_test_finish_hdlr
  * DESCRIPTION
  *  mmi_em_tp_acc_item_test_finish_hdlr
  * PARAMETERS
  *  item           [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_item_test_finish_hdlr(em_tp_acc_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item->dump_screen)
    {
        tst_dump_gdi_snapshot(0);
    }    
    if (item->is_auto_test && item->item_id <= MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_JITTER)
    {
        mmi_em_tp_acc_item_test_next(item);
    }
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_item_test_next
  * DESCRIPTION
  *  mmi_em_tp_acc_item_test_next
  * PARAMETERS
  *  item        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_item_test_next(em_tp_acc_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_acc_item_data_deinit(item);
    if (item->item_id == MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_JITTER)
    {
        item->item_id = MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_ACCURACY;
    }
    else
    {
        item->item_id++;
    }    
    mmi_em_tp_acc_item_prepare(item);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_item_proc
  * DESCRIPTION
  *  engineer mode touch panel accuracy item proc
  * PARAMETERS
  *  param        [IN]
  * RETURNS
  *  MMI_RET 
  *****************************************************************************/
static MMI_RET mmi_em_tp_acc_item_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_item_struct *test_item = (em_tp_acc_item_struct *)(param->user_data);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            if (test_item)
            {
                if (test_item->item_data)
                {
                    MMI_EM_FREE(test_item->item_data);
                    test_item->item_data = NULL;
                }
                MMI_EM_FREE(param->user_data);
            }                
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_acc_item_data_deinit
 * DESCRIPTION
 *  mmi_em_acc_item_data_deinit
 * PARAMETERS
 *  item        [IN]
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_em_acc_item_data_deinit(em_tp_acc_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item->layer_handle)
    {
        gdi_layer_free(item->layer_handle);
        item->layer_handle = 0;
    }
    if (item->data_deinit_func)
    {
        item->data_deinit_func(item->item_data);
    }
    if (item->item_data)
    {
        MMI_EM_FREE(item->item_data);
        item->item_data = NULL;
    }
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_item_exit_screen
  * DESCRIPTION
  *  engineer mod touch panel accucacy test item exit screen
  * PARAMETERS
  *  ess        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_item_exit_screen(mmi_scrn_essential_struct* ess)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_item_struct *item = (em_tp_acc_item_struct *)(ess->user_data);
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_acc_item_data_deinit(item);
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_item_enter_screen
  * DESCRIPTION
  *  engineer mod touch panel accucacy test item enter screen
  * PARAMETERS
  *  ess        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_item_enter_screen(mmi_scrn_essential_struct* ess)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_item_struct *item = (em_tp_acc_item_struct *)(ess->user_data);
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (! mmi_frm_scrn_enter(ess->group_id,
                    ess->scrn_id,
                    (FuncPtr)mmi_em_tp_acc_item_exit_screen, 
                    (FuncPtr)mmi_em_tp_acc_item_enter_screen,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    mmi_em_tp_acc_item_prepare(item);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_item_enter
  * DESCRIPTION
  *  engineer mode ->misc -> touch screen ->accuracy test -> ....
  * PARAMETERS
  *  parent_id      [IN]    parent group id
  *  item           [IN]    test item    
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_item_enter(MMI_ID parent_id, U32 item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_tp_acc_item_struct *item;
    MMI_ID group_id;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = (em_tp_acc_item_struct*)MMI_EM_MALLOC(sizeof(em_tp_acc_item_struct));
    memset(item, 0, sizeof(em_tp_acc_item_struct));

    if (MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_AUTO == item_id)
    {
        item->is_auto_test = 1;
        item_id ++;
    }
    else
    {
        item->is_auto_test = 0;
    }
    item->item_id = item_id;
    group_id = mmi_frm_group_create_ex(parent_id,
                                        GRP_ID_AUTO_GEN,
                                        mmi_em_tp_acc_item_proc,
                                        (void *)item,
                                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    item->group_id = group_id;
    mmi_frm_scrn_first_enter(group_id, 
                        SCR_ID_EM_MISC_TOUCH_SCREEN_ACC_ACCURACY, 
                        (FuncPtr)mmi_em_tp_acc_item_enter_screen, 
                        item);
}

#define ACC_TEST
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_get_pixel_from_um
 * DESCRIPTION
 *  trance length from um to pixel
 * PARAMETERS
 *  width_mm        [IN]
 * RETURNS
 *  U32   return the pixel value from um 
 *****************************************************************************/
static U32 mmi_em_tp_acc_get_pixel_from_um(U32 width_um)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    DCL_HANDLE handle;
    DCL_CTRL_MICRONMETER_COORD_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_TP_UT_ON_MODIS__
    return mmi_em_tp_acc_get_pixel_from_um_on_modis(width_um);
#endif /*__MMI_EM_TP_UT_ON_MODIS__*/
    
    memset(&data, 0, sizeof(DCL_CTRL_MICRONMETER_COORD_T));
    data.x_micronmeter = width_um;
    data.y_micronmeter = 0;
    handle = DclSTS_Open(DCL_TS, 0);
    DclSTS_Control(handle, STS_CMD_CTRL_MICRONMETER_TO_COORD, (DCL_CTRL_DATA_T*)&data);
    return data.x_coord;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_get_um_from_pixel
 * DESCRIPTION
 *  mmi_em_tp_acc_get_um_from_pixel
 * PARAMETERS
 *  width_pixel        [IN]
 * RETURNS
 *  U32   return the um value from pixel 
 *****************************************************************************/
static U32 mmi_em_tp_acc_get_um_from_pixel(U32 width_pixel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    DCL_HANDLE handle;
    DCL_CTRL_MICRONMETER_COORD_T data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_TP_UT_ON_MODIS__
    return mmi_em_tp_acc_get_um_from_pixel_on_modis(width_pixel);
#endif /*__MMI_EM_TP_UT_ON_MODIS__*/
    
    memset(&data, 0, sizeof(DCL_CTRL_MICRONMETER_COORD_T));
    data.x_coord = width_pixel;
    data.y_coord = 0;
    handle = DclSTS_Open(DCL_TS, 0);
    DclSTS_Control(handle, STS_CMD_CTRL_COORD_TO_MICRONMETER, (DCL_CTRL_DATA_T*)&data);
    return data.x_micronmeter;
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_draw_line_direction
  * DESCRIPTION
  *  draw line with arrow
  * PARAMETERS
  *  x1, y1, x2, y2 [IN]  line start & end point coordination
  *  color          [IN]   line color
  *  direction      [IN]   line direciont  ex: "----->"  is TP_ACC_LINE_RIGHT   
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_draw_line_direction(S32 x1, 
                                            S32 y1, 
                                            S32 x2, 
                                            S32 y2, 
                                            gdi_color color, 
                                            em_tp_acc_line_direction_enum direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*draw point coordination*/
    gdi_draw_line(x1, y1, x2, y2, color);
    switch (direction)
    {
        case TP_ACC_LINE_LEFT:
            gdi_draw_line(x2 + EM_TP_ACC_LINE_ARROW_LEN, y2 + EM_TP_ACC_LINE_ARROW_LEN, x2, y2, color);
            gdi_draw_line(x2 + EM_TP_ACC_LINE_ARROW_LEN, y2 - EM_TP_ACC_LINE_ARROW_LEN, x2, y2, color);
            break;

        case TP_ACC_LINE_RIGHT:
            gdi_draw_line(x2 - EM_TP_ACC_LINE_ARROW_LEN, y2 - EM_TP_ACC_LINE_ARROW_LEN, x2, y2, color);
            gdi_draw_line(x2 - EM_TP_ACC_LINE_ARROW_LEN, y2 + EM_TP_ACC_LINE_ARROW_LEN, x2, y2, color);            
            break;
       
        case TP_ACC_LINE_DOWN:
            gdi_draw_line(x2 + EM_TP_ACC_LINE_ARROW_LEN, y2 - EM_TP_ACC_LINE_ARROW_LEN, x2, y2, color);
            gdi_draw_line(x2 - EM_TP_ACC_LINE_ARROW_LEN, y2 - EM_TP_ACC_LINE_ARROW_LEN, x2, y2, color);
            break;

        case TP_ACC_LINE_UP:            
            gdi_draw_line(x2 - EM_TP_ACC_LINE_ARROW_LEN, y2 + EM_TP_ACC_LINE_ARROW_LEN, x2, y2, color);
            gdi_draw_line(x2 + EM_TP_ACC_LINE_ARROW_LEN, y2 + EM_TP_ACC_LINE_ARROW_LEN, x2, y2, color);
            break;

        default:
            break;
    }
}



/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_draw_position_and_pressure
  * DESCRIPTION
  *  draw pen point value in pos_rect & pressure value in press_rect.
  *  if is_need_bg_color is MMI_TRUE, the texts have bg color of bg_color
  * PARAMETERS
  *  item               [IN]   
  *  pos                [IN]   pen position
  *  pressure           [IN]   pressure value    
  *  bg_color           [IN]   text background color
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_draw_position_and_pressure(em_tp_acc_item_struct* item,
                                                        mmi_pen_point_struct *pos,
                                                        S32  pressure,
                                                        U32  bg_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle base_handle;
    MMI_BOOL is_need_bg_color;
    U16 text[EM_TP_ACC_TEXT_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*draw point coordination*/
    if (item->layer_handle)
    {
        gdi_layer_get_active(&base_handle);
        gdi_layer_set_active(item->layer_handle);
        gdi_layer_clear(EM_TP_ACC_TRANSPARENT_COLOR);
        gdi_layer_set_source_key(TRUE, EM_TP_ACC_TRANSPARENT_COLOR);
        is_need_bg_color = MMI_FALSE;
    }
    else
    {
        is_need_bg_color = MMI_TRUE;
    }
    kal_wsprintf(text,"(%d, %d)", pos->x, pos->y);
    mmi_em_tp_acc_draw_text_rect(&item->coordinate_rect, text, bg_color, is_need_bg_color);

    /* draw pressure */
    kal_wsprintf(text, "%d", pressure);
    mmi_em_tp_acc_draw_text_rect(&item->pressure_rect, text, bg_color, is_need_bg_color);
    if (item->layer_handle)
    {
        gdi_layer_set_active(base_handle);
        gdi_layer_set_blt_layer(base_handle, item->layer_handle, 0, 0);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_draw_text
 * DESCRIPTION
 *  mmi_em_tp_acc_draw_text
 * PARAMETERS
 *  text                [IN]   text to print    
 *  x, y                [IN]   the position where text to draw
 *  text_color          [IN]   text color 
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_em_tp_acc_draw_text(U16* text, S32 x, S32 y, color text_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_text_color(text_color);
    gui_move_text_cursor(x, y);
    gui_print_text(text);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_draw_fail_position
 * DESCRIPTION
 *  mmi_em_tp_acc_draw_fail_position
 * PARAMETERS
 *  pos               [IN]
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_em_tp_acc_draw_fail_position(mmi_pen_point_struct *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_line(pos->x - EM_TP_ACC_FAIL_LEN, pos->y - EM_TP_ACC_FAIL_LEN, 
                    pos->x + EM_TP_ACC_FAIL_LEN, pos->y + EM_TP_ACC_FAIL_LEN, EM_TP_ACC_FAIL_COLOR);
    gdi_draw_line(pos->x - EM_TP_ACC_FAIL_LEN, pos->y + EM_TP_ACC_FAIL_LEN, 
                    pos->x + EM_TP_ACC_FAIL_LEN, pos->y - EM_TP_ACC_FAIL_LEN, EM_TP_ACC_FAIL_COLOR);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_draw_result
  * DESCRIPTION
  *  mmi_em_tp_acc_draw_result
  * PARAMETERS
  *  item               [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_draw_result(em_tp_acc_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length;
    U32 string_w;
    U16 text[EM_TP_ACC_TEXT_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item->fail_distance > 0)
    {
        length = mmi_em_tp_acc_get_um_from_pixel((U32)item->fail_distance);
        kal_wsprintf(text, "%w %d um", get_string(STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_FAIL), length);
        mmi_em_tp_acc_draw_fail_position(&item->fail_position);
    }
    else
    {
        kal_wsprintf(text, "Pass");
    }    
    string_w = gui_get_string_width(text);
    mmi_em_tp_acc_draw_text(text,
                (UI_device_width - string_w) / 2,
                (S32)item->fail_rigion.y, 
                EM_TP_ACC_TEXT_FG_COLOR);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_draw_int
  * DESCRIPTION
  *  draw fail-distance value from pos
  * PARAMETERS
  *  x, y               [IN]   start point where  to draw 
  *  value              [IN]   
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_tp_acc_draw_int(U32 x, U32 y, U32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 text[EM_TP_ACC_TEXT_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*draw point coordination*/
    kal_wsprintf(text, "%d", value);
    mmi_em_tp_acc_draw_text(text, x, y, EM_TP_ACC_TEXT_BG_COLOR);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_tp_acc_draw_text_rect
 * DESCRIPTION
 *  mmi_em_tp_acc_draw_text_rect
 * PARAMETERS
 *  text_rect          [IN]   rect where text printed
 *  bg_color           [IN]   rect color
 *  text               [IN]   text to print    
 *  is_need_bg_color   [IN]   if is MMI_TRUE, use bg_color to render text's background, or no;
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_em_tp_acc_draw_text_rect(em_tp_rect_struct *text_rect, U16 *text, U32 bg_color, MMI_BOOL is_need_bg_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*draw point coordination*/
    gui_push_clip();
    gui_set_clip(text_rect->x1, text_rect->y1, text_rect->x2, text_rect->y2);
    if (is_need_bg_color)
    {
        gdi_draw_solid_rect(text_rect->x1, text_rect->y1, text_rect->x2, text_rect->y2, bg_color);    
    }
    mmi_em_tp_acc_draw_text(text, text_rect->x1, text_rect->y1, EM_TP_ACC_TEXT_FG_COLOR);
    gui_pop_clip();
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_acc_set_rect
  * DESCRIPTION
  *  set rect value
  * PARAMETERS
  *  rect           [IN]
  *  x1, y1, x2, y2 [IN]   coordinate
  * RETURNS
  *  U32   return the boder width 
  *****************************************************************************/
static void mmi_em_tp_acc_set_rect(em_tp_rect_struct *rect, U32 x1, U32 y1, U32 x2, U32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rect->x1 = x1;
    rect->y1 = y1;
    rect->x2 = x2;
    rect->y2 = y2;
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_accucary_test_select_hdlr
  * DESCRIPTION
  *  touch pannel accucacy test item select handler
  * PARAMETERS
  *  param        [IN]
  * RETURNS
  *  MMI_RET 
  *****************************************************************************/
static void mmi_em_tp_accucary_test_select_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( evt->highlighted_menu_id >= MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_AUTO && 
        evt->highlighted_menu_id <= MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_JITTER)
    {
        mmi_em_tp_acc_item_enter(GRP_ID_EM_MISC_TOUCH_SCREEN_ACCUCARY, evt->highlighted_menu_id);
    }
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_accuracy_proc
  * DESCRIPTION
  *  touch pannel accucacy test proc
  * PARAMETERS
  *  param        [IN]
  * RETURNS
  *  MMI_RET 
  *****************************************************************************/
static MMI_RET mmi_em_tp_accuracy_proc(mmi_event_struct *param)
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
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_em_tp_accucary_test_select_hdlr(param);
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
  *  mmi_em_misc_tp_accuracy_enter
  * DESCRIPTION
  *  engineer mode ->misc -> touch screen ->accuracy test entry
  * PARAMETERS
  *  parent_id        [IN]   parent group id
  * RETURNS
  *  void 
  *****************************************************************************/
void mmi_em_misc_tp_accuracy_enter(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_create_ex(parent_id,
                                        GRP_ID_EM_MISC_TOUCH_SCREEN_ACCUCARY,
                                        mmi_em_tp_accuracy_proc,
                                        NULL,
                                        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_create_and_run(group_id, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_APPSUB, 
                            MENU_ID_EM_MISC_TOUCH_SCREEN_ACCURACY, 
                            MMI_TRUE, 
                            NULL);
}


#define EM_TP_PARAM_RESET
/*****************************************************************************
  * FUNCTION
  *  mmi_em_tp_param_reset_proc
  * DESCRIPTION
  *  touch panel parameter reset confirm result proc, when user select "yes", the
  *  evt_id is MMI_ALERT_CNFM_YES, select "no", evt_id is MMI_ALERT_CNFM_NO
  * PARAMETERS
  *  param        [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static MMI_RET mmi_em_tp_param_reset_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_ALERT_CNFM_YES == alert->result)
    {
        TouchPanel_EM_custom_data_struct custom_data;
        mmi_em_tp_ctrl_custom_data(&custom_data, TP_PARAM_RESET);
    }
    return MMI_RET_OK;     
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_misc_tp_param_setting_enter
  * DESCRIPTION
  *  engineer mode ->misc -> touch screen ->parameter reset entry
  * PARAMETERS
  *  parent_id        [IN]     parent group id
  * RETURNS
  *  void
  *****************************************************************************/
void mmi_em_misc_tp_param_reset_enter(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_display_confirm(STR_GLOBAL_RESET,
			               parent_id,
			               MMI_EVENT_QUERY,
			               mmi_em_tp_param_reset_proc);
}




#ifdef __MMI_EM_TP_UT_ON_MODIS__
static void mmi_em_tp_ctrl_custom_data_on_modis(TouchPanel_EM_custom_data_struct *custom_data,
                                        TP_CTRL_PARAM_TYPE type)
{
    static TouchPanel_EM_custom_data_struct data = {10, 6, 8, 200,100,1,7,6000,0, 2000,800,2000,2000,5000,15000,0,0,0,
                                                    0, 0};
    if (TP_PARAM_GET == type)
    {
        memcpy((void *)custom_data, (const void *)&data, sizeof(TouchPanel_EM_custom_data_struct));
    }
    else if (TP_PARAM_SET == type)
    {
        memcpy((void *)&data, (const void *)custom_data, sizeof(TouchPanel_EM_custom_data_struct));
    }
    else
    {
        TouchPanel_EM_custom_data_struct temp = {10, 6, 8, 200,100,1,7,6000, 0, 2000,800,2000,2000,5000,15000,0,0,0,
                                                    0, 0};
        memcpy((void *)&data, (const void *)&temp, sizeof(TouchPanel_EM_custom_data_struct));
    }
}

static void mmi_em_tp_get_param_range_on_modis(TP_PARAM_RANGE *param_range)
{
 /*----------------------------------------------------------------*/
 /* Local Variables                                                */
 /*----------------------------------------------------------------*/

 /*----------------------------------------------------------------*/
 /* Code Body                                                      */
 /*----------------------------------------------------------------*/
 param_range->ts_debounce_time_min = 1;
 param_range->ts_debounce_time_max = 50;
 param_range->touch_panel_cali_check_offset_min = 1;
 param_range->touch_panel_cali_check_offset_max = 20;

 param_range->min_pen_move_offset_min = 1;
 param_range->min_pen_move_offset_max = 300;
 param_range->hand_writing_max_offset_min = 1;
 param_range->hand_writing_max_offset_max = 300;
 param_range->nonhand_writing_max_offset_min = 1;
 param_range->nonhand_writing_max_offset_max = 300;
 param_range->max_stroke_move_offset_min = 1;
 param_range->max_stroke_move_offset_max = 300;
 param_range->multiple_point_selection_min = 1;
 param_range->multiple_point_selection_max = 10;
 param_range->touch_pressure_threshold_high_min = 100;
 param_range->touch_pressure_threshold_high_max = 20000;
 param_range->pressure_check_boundary_min = 1;
 param_range->pressure_check_boundary_max = 3000;
 param_range->pressure_shifting_boundary_min = 300;
 param_range->pressure_shifting_boundary_max = 2000;
 param_range->border_pass_criterion_min = 1000;
 param_range->border_pass_criterion_max = 10000;
 param_range->nonborder_pass_criterion_min = 1000;
 param_range->nonborder_pass_criterion_max = 10000;
 param_range->border_range_min = 1000;
 param_range->border_range_max = 10000;
 param_range->jitter_circuit_interval_min = 5000;
 param_range->jitter_circuit_interval_max = 20000;
 param_range->Dump_Screen_min = 0;
 param_range->Dump_Screen_max = 1;
 param_range->reserve_parameter1_min = 0;
 param_range->reserve_parameter1_max = 0;       
 param_range->reserve_parameter2_min = 0;
 param_range->reserve_parameter2_max = 0;
 param_range->reserve_parameter3_min = 0;
 param_range->reserve_parameter3_max = 0;  
}

static U32 mmi_em_tp_acc_get_pixel_from_um_on_modis(U32 width_um)
{ 
    return 4 * width_um / 1000;
}

static U32 mmi_em_tp_acc_get_um_from_pixel_on_modis(U32 width_pixel)
{
    return width_pixel * 1000 / 4;
}

#endif /*__MMI_EM_TP_UT_ON_MODIS__*/

#endif  /*defined(__MMI_EM_MISC_TOUCH_SCREEN__)*/
