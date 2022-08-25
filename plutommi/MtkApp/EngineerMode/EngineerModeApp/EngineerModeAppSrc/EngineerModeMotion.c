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
 *   EngineerModeMotion.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Motion sensor engineer mode
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
#include "MMI_features.h"

#ifdef __MMI_EM_MOTION_APP__
#include "mmi_include.h"
#include "Fat_fs.h"     /* File System, must after "GlobalConstants.h" */
#include "SettingDefs.h"        /* popup sound */
#include "CommonScreens.h"      /* Popup */
#include "lcd_sw_rnd.h" /* lcd */
#include "lcd_if.h"     /* lcd */

#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_audio.h"  /* audio lib */
#include "kal_release.h"        /* kal */

//#include "SettingProfileEnum.h"
#include "ProfilesSrvGProt.h"

#include "GpioSrvGprot.h"

#include "MenuCuiGprot.h"

#include "EngineerModeUtil.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeResDef.h"
#include "EngineerModeAppResDef.h"
//#include "EngineerModeMotion.h"

#include "mmi_rp_app_engineermode1_def.h"

#include "FSEditorCuiGprot.h"


#include "SensorSrvGport.h"

#include "math.h"        /* atan */

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui.h"
#include "gdi_include.h"
#include "stdlib.h"
#include "gui_data_types.h"
#include "stack_config.h"
#include "gui_themes.h"
#include "kal_public_api.h"
#include "string.h"
#include "GpioSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"


#define MMI_DEV_APP_BALL_RADIO      (10)
#define MMI_DEV_APP_BALL_VG_STEP    (20)
#define MMI_DEV_APP_BALL_V_HIT      (30)
#define MMI_MOTION_BALL_INTERVAL    (100)
#define MMI_DEV_APP_BALL_V_MAX      (40)

#define PI (3.1415926)
#define MMI_MOTION_ROTATE_STEP      (15)
#define MMI_MOTION_ROTATE_INTERVAL  (50)
#define MMI_MOTION_360_DEGREE       (360)


#define MMI_MOTION_ADVANCED_SHAKE_POS    (2)
#define MMI_MOTION_ADVANCED_SHAKE_NEG    (1)
#define MMI_MOTION_ADVANCED_SHAKE_NONE   (0)




/*---------------------------------------------------------*/
/*    For set tap                                         */
/*-----------------------------------------------------------*/

/*globa*/

U32 g_gourp_set_tap_id;
U32 g_cui_set_tap_id;

U32 tap_plus_max_val = 0;
U32 tap_plus_min_val = 0;
U32 tap_threshold_max_val = 0;
U32 tap_threshold_min_val = 0;

/* inline enum */

typedef enum
{
    MMI_EM_MOTION_DRAW_BEGIN_LINE,
        MMI_EM_MOTION_DRAW_NEXT_LINE
}em_motion_line_enum;//Jerry

typedef enum
{
	MMI_EM_MOTION_STEP_LOW,
	MMI_EM_MOTION_STEP_MED,
	MMI_EM_MOTION_STEP_HIGH
}mmi_em_motion_step_mode_enum;


typedef enum
{
    MMI_EM_MOTION_TILT_NORMAL,
	MMI_EM_MOTION_TILT_RAW
}mmi_em_motion_tilt_mode_enum;


typedef enum
{
    MMI_EM_MOTION_SET_TAP_PLUS_CAPTION = CUI_INLINE_ITEM_ID_BASE + 1,
        MMI_EM_MOTION_SET_TAP_PLUS_EDITOR,
        MMI_EM_MOTION_SET_TAP_THRESHOLD_CAPTION,
        MMI_EM_MOTION_SET_TAP_THRESHOLD_EDITOR,
        MMI_EM_MOTION_SET_TAP_TOTAL
} mmi_em_motion_set_tap_inline_enum;

/* inline const */
cui_inline_item_caption_struct init_str[] = 
{
    STR_ID_EM_MOTION_SET_TAP_PLUS,
        STR_ID_EM_MOTION_SET_TAP_THRESHOLD    
};

cui_inline_item_text_edit_struct editor_buff[] = 
{
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
};

#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
static const cui_inline_set_item_struct set_tap_item[] =
{
    {MMI_EM_MOTION_SET_TAP_PLUS_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,    0, (void*)&init_str[0]},
    {MMI_EM_MOTION_SET_TAP_PLUS_EDITOR,      CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0, (void*)&editor_buff[0]},
    {MMI_EM_MOTION_SET_TAP_THRESHOLD_CAPTION,CUI_INLINE_ITEM_TYPE_CAPTION,    0, (void*)&init_str[1]},
    {MMI_EM_MOTION_SET_TAP_THRESHOLD_EDITOR, CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0, (void*)&editor_buff[1]},
};

static const cui_inline_struct set_tap_inline = 
{
    4,   /* item count */
        STR_ID_EM_DEV_MOTION_SET_TAP_PARA,  /* screen title string id */
        0, /* screen title icon id */
        CUI_INLINE_SCREEN_DISABLE_DONE,  
        NULL,
        //(cui_inline_set_item_struct*)inline_item
        set_tap_item
};
#endif


/*---------------------------------------------------------*/
/*    For set flip                                      */
/*-----------------------------------------------------------*/
/*
MMI_BOOL flipEnable;
float flipFilter;
float flipThreshold;
float tFlipDebounce;
float tFlipInterval;
*/

/*globa*/

U32 g_gourp_set_flip_id;
U32 g_cui_set_flip_id;

/* inline enum */

typedef enum
{
    MMI_EM_MOTION_SET_FLIP_ENABLE_CAPTION = CUI_INLINE_ITEM_ID_BASE + 1,
        MMI_EM_MOTION_SET_FLIP_ENABLE_EDITOR,
        MMI_EM_MOTION_SET_FLIP_FILTER_CAPTION,
        MMI_EM_MOTION_SET_FLIP_FILTER_EDITOR,
        MMI_EM_MOTION_SET_FLIP_THRESHOLD_CAPTION,
        MMI_EM_MOTION_SET_FLIP_THRESHOLD_EDITOR,
        MMI_EM_MOTION_SET_FLIP_DEBOUNCE_CAPTION,
        MMI_EM_MOTION_SET_FLIP_DEBOUNCE_EDITOR,
        MMI_EM_MOTION_SET_FLIP_INTERVAL_CAPTION,
        MMI_EM_MOTION_SET_FLIP_INTERVAL_EDITOR,
        MMI_EM_MOTION_SET_FLIP_TOTAL
} mmi_em_motion_set_flip_inline_enum;

/* inline const */
cui_inline_item_caption_struct flip_init_str[] = 
{
    STR_ID_EM_MOTION_SET_FLIP_ENABLE,
        STR_ID_EM_MOTION_SET_FLIP_FILTER,
        STR_ID_EM_MOTION_SET_FLIP_THRESHOLD,
        STR_ID_EM_MOTION_SET_FLIP_DEBOUNCE,
        STR_ID_EM_MOTION_SET_FLIP_INTERVAL,
};

cui_inline_item_text_edit_struct flip_editor_buff[] = 
{
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
};


static const cui_inline_set_item_struct set_flip_item[] =
{
    {MMI_EM_MOTION_SET_FLIP_ENABLE_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,    0, (void*)&flip_init_str[0]},
    {MMI_EM_MOTION_SET_FLIP_ENABLE_EDITOR,      CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0, (void*)&flip_editor_buff[0]},
    
    {MMI_EM_MOTION_SET_FLIP_FILTER_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,    0, (void*)&flip_init_str[1]},
    {MMI_EM_MOTION_SET_FLIP_FILTER_EDITOR,      CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0, (void*)&flip_editor_buff[1]},
    
    {MMI_EM_MOTION_SET_FLIP_THRESHOLD_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION,    0, (void*)&flip_init_str[2]},
    {MMI_EM_MOTION_SET_FLIP_THRESHOLD_EDITOR,   CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0, (void*)&flip_editor_buff[2]},
    
    {MMI_EM_MOTION_SET_FLIP_DEBOUNCE_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,    0, (void*)&flip_init_str[3]},
    {MMI_EM_MOTION_SET_FLIP_DEBOUNCE_EDITOR,    CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0, (void*)&flip_editor_buff[3]},
    
    {MMI_EM_MOTION_SET_FLIP_INTERVAL_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,    0, (void*)&flip_init_str[4]},
    {MMI_EM_MOTION_SET_FLIP_INTERVAL_EDITOR,    CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0, (void*)&flip_editor_buff[4]},
};

static const cui_inline_struct set_flip_inline = 
{
    10,   /* item count */
        STR_ID_EM_DEV_MOTION_SET_FLIP_PARA,  /* screen title string id */
        0, /* screen title icon id */
        CUI_INLINE_SCREEN_DISABLE_DONE,  
        NULL,
        //(cui_inline_set_item_struct*)inline_item
        set_flip_item
};


/*---------------------------------------------------------*/
/*    main structure                                     */
/*-----------------------------------------------------------*/

typedef struct
{
    mmi_id cur_gid;
    mmi_id cui_menu_id;
    mmi_id other_gid;
    mmi_id cui_editor_id;
    
    U16 direct_sen[3];
    
    S32 old_angle;
    S32 new_angle;
    S32 index;
    srv_sensor_motion_shake_sensitive_enum sensitive;
    MMI_BOOL direct;
    
    S32 accx;
    S32 accy;
    S32 vx;
    S32 vy;
    S32 x;
    S32 y;
    U8  shake_text_line;
    U8  angle_threshold;
    MMI_BOOL is_start_other_task_app;
    mdi_handle detail_info_handle;
    mdi_handle tilt_normal_handle;
    mdi_handle tilt_detail_handle;
    mdi_handle shake_handle;	
} mmi_em_motion_cntx_struct;


/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

mmi_em_motion_cntx_struct *mmi_em_motion_cntx;
SRV_SENSOR_HANDLE g_handle;

U32 g_double_tap_count = 0;
U32 g_tap_count = 0;
U32 g_turnover_count = 0;
U32 g_step_count = 0;
U32 g_shake_count_x = 0;
U32 g_shake_count_y = 0;
U32 g_shake_count_z = 0;
U32 g_drop_count = 0;


/*----------------------------------------------------------------------------*/
/* Static function define                                                           */
/*----------------------------------------------------------------------------*/
static void mmi_em_motion_tilt_detail_info_callback(
                                                    srv_sensor_type_enum sensor_type, 
                                                    void *sensor_data, 
                                                    void *user_data  );

static void mmi_em_motion_tilt_normal_to_axis_callback(
                                                       srv_sensor_type_enum            type,
                                                       void                           *sensor_data, 
                                                       void                            *user_data);

static void mmi_em_motion_tilt_detail_callback(
                                               srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data);

static void mmi_em_motion_tilt_detail_interval(void);
static void mmi_em_motion_tilt_normal_rotate_to_interval(void);
static void mmi_em_motion_exit_app(void);

static void mmi_em_motion_shake_callback(srv_sensor_type_enum sensor_type,
                                         void *sensor_data, void *user_data);

static void mmi_em_motion_enter_set_direct_sen(void);

mmi_ret mmi_em_motion_set_direct_sen_proc(mmi_event_struct *evt);


/* ------For porting mcube------ */

static void mmi_em_motion_advanced_shake_callback(
                                                  srv_sensor_type_enum sensor_type, 
                                                  void *sensor_data, 
                                                  void *user_data  );

/*set flip*/
static void mmi_em_motion_set_flip_para();
static mmi_ret mmi_em_motion_set_flip_proc(mmi_event_struct *param);
static void mmi_em_motion_write_flip_para();
/*set tap*/
#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
static void mmi_em_motion_set_tap_para();
static mmi_ret mmi_em_motion_set_tap_proc(mmi_event_struct *param);
static void mmi_em_motion_write_tap_para();
static void mmi_em_motion_read_tap_para(U16 str[][10]);
static S32 mmi_em_hexstr_to_intnum_2(CHAR * str);
#endif



/*----------------------------------------------------------------------------*/
/* Static funtion                                                             */
/*----------------------------------------------------------------------------*/

#define MMI_EM_MOTION_COMMON_FUNC

//Jerry
/*****************************************************************************
* FUNCTION
*  mmi_em_motion_draw_init
* DESCRIPTION
*  init draw
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
void mmi_em_motion_draw_init(UI_font_type font,color text_color, gdi_color bg_color, U8* text_hight)
{
    gui_set_font(font);
    gui_set_text_color(text_color);
    *text_hight = gui_get_character_height();
    gdi_layer_clear(bg_color);
}


//Jerry
/*****************************************************************************
* FUNCTION
*  mmi_em_motion_draw_text
* DESCRIPTION
*  draw text on screen
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
void mmi_em_motion_draw_text(U32 start_x, U32 internal, S32 text_hight,UI_string_type content, em_motion_line_enum start_line)
{
    static U32 start_y = 0;
    
    if (start_line == MMI_EM_MOTION_DRAW_NEXT_LINE)
        start_y += internal * text_hight;
    else
        start_y = text_hight;
    gui_move_text_cursor(start_x, start_y);
    gui_print_text(content);
}




#define MMI_EM_ADVANCED_SHAKE
void mmi_em_motion_advanced_shake_callback( srv_sensor_type_enum sensor_type, 
                                           void *sensor_data, 
                                           void *user_data  )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type my_scr_wtext[100];
    
    
    srv_sensor_motion_advanced_shake_struct *p_tilt;
    
    U8 text_hight;
    
    U8 i = 0;  /*x*/
    U8 j = 0;  /*y*/
    U8 k = 0;  /*z*/
    
    U8 shake_x,shake_y,shake_z;
    U8 shakeData = 0;
    
    char * shake_direction_x[3] = {
        {"shake left"},
        {"shake right"},
        {"None"}
    };
    char * shake_direction_y[3] = {
        {"shake bottom"},
        {"shake top"},
        {"None"}
    };
    char * shake_direction_z[3] = {
        {"shake back"},
        {"shake front"},	
        {"None"}
    };
    
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_tilt = (srv_sensor_motion_advanced_shake_struct *)sensor_data;
    
    shakeData = p_tilt->direction;
    
    shake_x = shakeData & 0x03;
    shake_y = (shakeData & 0x0C) >>2;
    shake_z = (shakeData & 0x30 )>> 4;
    
    
    switch(shake_x)
    {
    case MMI_MOTION_ADVANCED_SHAKE_NEG:
        i = 0;
        g_shake_count_x++;
        break;
        
    case MMI_MOTION_ADVANCED_SHAKE_POS:
        i = 1;
        g_shake_count_x++;
        break;
        
    default:
        i = 2;
        break;
    }
    
    switch(shake_y)
    {
    case MMI_MOTION_ADVANCED_SHAKE_NEG:
        j = 0;
        g_shake_count_y++;
        break;
        
    case MMI_MOTION_ADVANCED_SHAKE_POS:
        j = 1;
        g_shake_count_y++;
        break;
        
    default:
        j = 2;
        break;
    }
    switch(shake_z)
    {
    case MMI_MOTION_ADVANCED_SHAKE_NEG:
        k = 0;
        g_shake_count_z++;
        break;
        
    case MMI_MOTION_ADVANCED_SHAKE_POS:
        k = 1;
        g_shake_count_z++;
        break;
        
    default:
        k = 2;
        break;
    }
    
    //Jerry
    
    mmi_em_motion_draw_init(&MMI_medium_font, gui_color(255, 255, 255),
        GDI_COLOR_BLACK, &text_hight);
    
    /* x axis */
    kal_wsprintf(my_scr_wtext,"Shake action (x) %s",shake_direction_x[i]);
    mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_BEGIN_LINE);
    
    kal_wsprintf(my_scr_wtext,"Shake count (x) %d",g_shake_count_x);
    mmi_em_motion_draw_text(10, 1, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_NEXT_LINE);
    
    /* y axis */
    kal_wsprintf(my_scr_wtext,"Shake action (y) %s",shake_direction_y[j]);
    mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_NEXT_LINE);
    
    kal_wsprintf(my_scr_wtext,"Shake count (y) %d",g_shake_count_y);
    mmi_em_motion_draw_text(10, 1, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_NEXT_LINE);
    
    /* z axis */
    kal_wsprintf(my_scr_wtext,"Shake action (z) %s",shake_direction_z[k]);
    mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_NEXT_LINE);
    
    kal_wsprintf(my_scr_wtext,"Shake count (z) %d",g_shake_count_z);
    mmi_em_motion_draw_text(10, 1, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_NEXT_LINE);
    
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}




void mmi_em_motion_advanced_shake_test()
{
    MMI_BOOL entry_ret;
    srv_sensor_motion_advanced_shake_struct   init;
    
    init.direction = 0x00;
    
    
    entry_ret = mmi_frm_scrn_enter (mmi_em_motion_cntx->cur_gid, SCR_ID_EM_MOTION_APP_SHOW, mmi_em_motion_exit_app, mmi_em_motion_advanced_shake_test, MMI_FRM_UNKNOW_SCRN);
    
    if (!entry_ret)
    {
        return;
    }
    
    mmi_em_motion_advanced_shake_callback(SRV_SENSOR_MOTION_ADVANCED_SHAKE, &init, NULL);
    
    g_handle = 
        srv_sensor_start_listen(SRV_SENSOR_MOTION_ADVANCED_SHAKE, NULL ,mmi_em_motion_advanced_shake_callback, NULL);
    
#ifndef __COSMOS_MMI_PACKAGE__	  
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
#endif 
    
}

#define MMI_EM_MOTION_TURNOVER
void mmi_em_motion_turnover_callback( srv_sensor_type_enum sensor_type, 
                                     void *sensor_data, 
                                     void *user_data  )
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type my_scr_wtext[100];
    
    
    srv_sensor_motion_turnover_struct *p_turnover;
    
    U8 text_hight;
    
    char * turnover_action[3] = {
        {"back to front"},
        {"front to back"},
        {"None"}
    };
    
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    kal_prompt_trace(MOD_MMI,"[EM_motion] %d",sensor_type);
    
    
    p_turnover = (srv_sensor_motion_turnover_struct *)sensor_data;
    
    if (p_turnover->direction == SRV_SENSOR_MOTION_TURNOVER_UP)
    {
        /*back to front*/
        i = 0;
        g_turnover_count++;
        
    }
    else if (p_turnover->direction == SRV_SENSOR_MOTION_TURNOVER_DOWN)
    {
        /*front to back*/
        i = 1;
        g_turnover_count++;
    }
    else
    {i = 2;}
    
    
    mmi_em_motion_draw_init(&MMI_medium_font, gui_color(255, 255, 255),
        GDI_COLOR_BLACK, &text_hight);
    
    kal_wsprintf(my_scr_wtext,"Turnover count: %d",g_turnover_count);
    mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_BEGIN_LINE);
    
    kal_wsprintf(my_scr_wtext,"Turnover action: %s",turnover_action[i]);
    mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_NEXT_LINE);
    
    
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);    
    
}


void mmi_em_motion_turnover()
{	
    MMI_BOOL entry_ret;
    srv_sensor_motion_turnover_struct   init;
    
    init.direction = SRV_SENSOR_MOTION_TURNOVER_NONE;
    
    
    entry_ret = mmi_frm_scrn_enter (mmi_em_motion_cntx->cur_gid, SCR_ID_EM_MOTION_APP_SHOW, mmi_em_motion_exit_app, mmi_em_motion_turnover, MMI_FRM_UNKNOW_SCRN);
    
    if (!entry_ret)
    {
        return;
    }
    
    mmi_em_motion_turnover_callback(SRV_SENSOR_MOTION_TURNOVER, &init, NULL);
    g_handle = 
        srv_sensor_start_listen(SRV_SENSOR_MOTION_TURNOVER, NULL ,mmi_em_motion_turnover_callback, NULL);
    
#ifndef __COSMOS_MMI_PACKAGE__    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
#endif 
    
}



#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
/* Tap test */

#define MMI_EM_MOTION_TAP
void mmi_em_motion_tap_callback(
                                srv_sensor_type_enum sensor_type, 
                                void *sensor_data, 
                                void *user_data  )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type my_scr_wtext[100];
    module_type module_id;
    
    srv_sensor_motion_tap_struct *p_tap;
    
    U8 text_hight, text_line = 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(SRV_SENSOR_MOTION_TAP == sensor_type);
    
    kal_prompt_trace(MOD_MMI,"[EM_motion] %d",sensor_type);
    
    p_tap = (srv_sensor_motion_tap_struct *)sensor_data;
    
    if (p_tap->tap_direct == SRV_SENSOR_MOTION_TAP_DONE)
    {
        /*SRV_SENSOR_MOTION_TAP_DONE means detecting tap*/
        g_tap_count++;
    }
    
    mmi_em_motion_draw_init(&MMI_medium_font, gui_color(255, 255, 255),
        GDI_COLOR_BLACK, &text_hight);
    
    kal_wsprintf(my_scr_wtext,"Tap: %d",g_tap_count);
    mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_BEGIN_LINE);
    
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}



void mmi_em_motion_tap()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sensor_motion_tap_struct   init;
    //srv_sensor_motion_tap_cfg_struct tap_oritation_support;  /*tap configure*/
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    entry_ret = mmi_frm_scrn_enter (mmi_em_motion_cntx->cur_gid, SCR_ID_EM_MOTION_APP_SHOW, mmi_em_motion_exit_app, mmi_em_motion_tap, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
    
    /*支持z轴tap，tap手机屏幕或背面有响应*/
    //	tap_oritation_support.tap_direct = SRV_SENSOR_MOTION_TAP_Z_SUPPORT; 
    
    mmi_em_motion_tap_callback(SRV_SENSOR_MOTION_TILT, &init, NULL);
    
    g_handle = 
        srv_sensor_start_listen(SRV_SENSOR_MOTION_TAP , NULL ,
        mmi_em_motion_tap_callback, NULL);
    
#ifndef __COSMOS_MMI_PACKAGE__    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
#endif 
}


/* double tap test */


#define MMI_EM_MOTION_DOUBLE_TAP

void mmi_em_motion_double_tap_callback(
                                       srv_sensor_type_enum sensor_type, 
                                       void *sensor_data, 
                                       void *user_data  )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type my_scr_wtext[100];
    module_type                     module_id;
    
    srv_sensor_motion_double_tap_struct *p_tap;
    
    U8 text_hight, text_line = 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    kal_prompt_trace(MOD_MMI,"[EM_motion] %d",sensor_type);
    
    p_tap = (srv_sensor_motion_double_tap_struct *)sensor_data;
    
    if (p_tap->double_tap_direct == SRV_SENSOR_MOTION_TAP_DONE)
    {
        /*SRV_SENSOR_MOTION_TAP_FRONT means detecting tap*/
        g_double_tap_count++;
    }
    
    mmi_em_motion_draw_init(&MMI_medium_font, gui_color(255, 255, 255),
        GDI_COLOR_BLACK, &text_hight);
    
    kal_wsprintf(my_scr_wtext,"Double Tap: %d",g_double_tap_count);
    mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_BEGIN_LINE);
    
    
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


void mmi_em_motion_double_tap()
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    srv_sensor_motion_double_tap_struct	init;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/	
    entry_ret = mmi_frm_scrn_enter (mmi_em_motion_cntx->cur_gid, SCR_ID_EM_MOTION_APP_SHOW, mmi_em_motion_exit_app, mmi_em_motion_double_tap, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
    
    
    mmi_em_motion_double_tap_callback(SRV_SENSOR_MOTION_DOUBLE_TAP, &init, NULL);
    g_handle = 
        srv_sensor_start_listen(SRV_SENSOR_MOTION_DOUBLE_TAP , NULL ,mmi_em_motion_double_tap_callback, NULL);
    
#ifndef __COSMOS_MMI_PACKAGE__    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
#endif 
}

#define MMI_EM_MOTION_STEP

mmi_em_motion_step_callback(srv_sensor_type_enum sensor_type, 
                            void *sensor_data, 
                            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type my_scr_wtext[100];
    module_type module_id;
    
    srv_sensor_motion_step_struct *p_tap;
    
    U8 text_hight, text_line = 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    kal_prompt_trace(MOD_MMI,"[EM_motion] %d",sensor_type);
    
    p_tap = (srv_sensor_motion_step_struct *)sensor_data;
    
    if (p_tap->action == SRV_SENSOR_MOTION_ACTION_STEP)
    {
        /*SRV_SENSOR_MOTION_TAP_FRONT means detecting tap*/
        g_step_count++;
    }
    
    mmi_em_motion_draw_init(&MMI_medium_font, gui_color(255, 255, 255),
        GDI_COLOR_BLACK, &text_hight);
    
    kal_wsprintf(my_scr_wtext,"Step: %d",g_step_count);
    mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_BEGIN_LINE);
    
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

void mmi_em_motion_step(mmi_em_motion_step_mode_enum step_sens)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    srv_sensor_motion_step_struct init;
    MMI_BOOL entry_ret;
	srv_sensor_motion_step_cfg_struct step_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
	switch (step_sens)
	{
	    case MMI_EM_MOTION_STEP_LOW:
			step_mode.sensitive = SRV_SENSOR_MOTION_STEP_LOW;
			break;
		case MMI_EM_MOTION_STEP_MED:
			step_mode.sensitive = SRV_SENSOR_MOTION_STEP_MEDIUM;
			break;
		case MMI_EM_MOTION_STEP_HIGH:
			step_mode.sensitive = SRV_SENSOR_MOTION_STEP_HIGH;
			break;
	}
    entry_ret = mmi_frm_scrn_enter (mmi_em_motion_cntx->cur_gid, SCR_ID_EM_MOTION_APP_SHOW, mmi_em_motion_exit_app, mmi_em_motion_step, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
    
    init.action = SRV_SENSOR_MOTION_STEP_NULL;
    
    mmi_em_motion_step_callback(SRV_SENSOR_MOTION_STEP, &init, NULL);
    
    g_handle = 
        srv_sensor_start_listen(SRV_SENSOR_MOTION_STEP , &step_mode ,mmi_em_motion_step_callback, NULL);
    
    
#ifndef __COSMOS_MMI_PACKAGE__    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
#endif 
    
}

#define MMI_EM_MOTION_DROP

mmi_em_motion_drop_callback(srv_sensor_type_enum sensor_type, 
                            void *sensor_data, 
                            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type my_scr_wtext[100];
    module_type module_id;
    
    srv_sensor_motion_drop_struct *p_tap;
    
    U8 text_hight, text_line = 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    kal_prompt_trace(MOD_MMI,"[EM_motion] %d",sensor_type);
    
    p_tap = (srv_sensor_motion_drop_struct *)sensor_data;
    
    if (p_tap->action == SRV_SENSOR_MOTION_ACTION_DROP)
    {
        /*SRV_SENSOR_MOTION_TAP_FRONT means detecting tap*/
        g_drop_count++;
    }
    
    
    mmi_em_motion_draw_init(&MMI_medium_font, gui_color(255, 255, 255),
        GDI_COLOR_BLACK, &text_hight);
    
    kal_wsprintf(my_scr_wtext,"Drop: %d",g_drop_count);
    mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_BEGIN_LINE);
    
    
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


void mmi_em_motion_drop()
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    srv_sensor_motion_drop_struct init;
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter (mmi_em_motion_cntx->cur_gid, SCR_ID_EM_MOTION_APP_SHOW, mmi_em_motion_exit_app, mmi_em_motion_drop, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
    init.action = SRV_SENSOR_MOTION_DROP_NULL;
    
    mmi_em_motion_drop_callback(SRV_SENSOR_MOTION_DROP, &init, NULL);
    
    g_handle = 
        srv_sensor_start_listen(SRV_SENSOR_MOTION_DROP , NULL ,mmi_em_motion_drop_callback, NULL);
    
    
#ifndef __COSMOS_MMI_PACKAGE__    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
#endif 
    
}

#endif /*__MOTION_SENSOR_ADVANCED_GESTURE__*/



/* new gesture: Set tap and Set flip*/

#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__

#define MMI_EM_SET_TAP
/*----------------------- Set tap item --------------------------------*/

static S32 mmi_em_hexstr_to_intnum_2(CHAR * str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 len;
    S32 i;
    S32 res = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(str);
    for (i = len - 1; i >= 0; i-- )
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            //number
            res = res + ( str[i] - '0' ) *  pow(16,len-1-i); 
        }
        else if(str[i] >= 'a' && str[i] <= 'f')
        {
            //char
            res = res + ( str[i] - 'a' + 10) *  pow(16,len-1-i); 
        }
        else if(str[i] >= 'A' && str[i] <= 'F')
        {
            //char
            res = res + ( str[i] - 'A' + 10) *  pow(16,len-1-i); 
        }
        else
        {
            res = 0;
            break;
        }
    }
    if (i>=0)
    {
        // invalid value
        return -111;
    }
    return res;
}





static void mmi_em_motion_read_tap_para(U16 str[][10])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     
    U8 tmp_str[2][20] = {0};
    
    srv_sensor_motion_get_tap_struct para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_em_pxs_sensor_read_param_val(&em_param);
    
    srv_sensor_motion_get_parameters(SRV_SENSOR_MOTION_SET_TAP,&para);
    
    tap_plus_max_val = para.get_tap_plus.max_val;
    tap_plus_min_val = para.get_tap_plus.min_val;
    tap_threshold_max_val = para.get_tap_threshold.max_val;
    tap_threshold_min_val = para.get_tap_threshold.min_val;
    
    kal_prompt_trace(MOD_MMI,"[EM set tap] tap_plus_max_val %x, tap_plus_min_val %x,tap_threshold_max_val %x, tap_threshold_min_val %x",
        para.get_tap_plus.max_val,para.get_tap_plus.min_val,
        para.get_tap_plus.max_val,para.get_tap_plus.min_val);
    
    sprintf((char *)tmp_str[0], "%x" ,para.get_tap_plus.curr_val);
    sprintf((char *)tmp_str[1], "%x" ,para.get_tap_threshold.curr_val);
    
    
    
    mmi_asc_n_to_ucs2((CHAR*)str[0] , (CHAR*) tmp_str[0], 6);
    mmi_asc_n_to_ucs2((CHAR*)str[1] , (CHAR*) tmp_str[1], 6);
    
}


static void mmi_em_motion_write_tap_para()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sensor_motion_set_tap_struct set_tap_para;
    U8 tmp_str[2][20] = {0};
    U8 output_buffer[2][20] = {0};
    U8 i = 0;
    U8 j = 0;
    U32 tap_para[2] = {0};
    MMI_BOOL flag = MMI_TRUE;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0,j=1; i<2; i++,j=j+2)
    {
        cui_inline_get_value(g_cui_set_tap_id, set_tap_item[j].item_id, tmp_str[i]);
        mmi_ucs2_n_to_asc(output_buffer[i],tmp_str[i],10);	
        if (mmi_em_hexstr_to_intnum_2(output_buffer[i]) != -111)
            tap_para[i] = mmi_em_hexstr_to_intnum_2(output_buffer[i]);
        else
        {
            flag = MMI_FALSE;
            break;
        }
    }
    
    kal_prompt_trace(MOD_MMI,"[EM set tap]tap %d, Tap_plus %d",
        tap_para[0],tap_para[1]);
    
    if(tap_para[0]>tap_plus_max_val || tap_para[0]<tap_plus_min_val
        || tap_para[1]>tap_threshold_max_val ||  tap_para[1]<tap_threshold_min_val)
    {
        flag = MMI_FALSE;    /* Out of range */
    }
    if (!flag)
    {
        /* Out of range */
        kal_prompt_trace(MOD_MMI,"OUT of range!!!!!!");
        
        mmi_frm_scrn_close_active_id();
        cui_inline_close(g_cui_set_tap_id); 
        
        mmi_popup_display_simple((WCHAR*)GetString(STR_ID_EM_DEV_MOTION_OUT_OF_RANGE), 
            MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        return;
    }
    
    set_tap_para.set_tap_plus = tap_para[0];
    set_tap_para.set_tap_threshold = tap_para[1];
    
    kal_prompt_trace(MOD_MMI,"[EM set tap]str tap %s, str Tap_plus %s",
        output_buffer[0],output_buffer[1]);
    
    
    
    srv_sensor_motion_set_parameters(SRV_SENSOR_MOTION_SET_TAP,&set_tap_para);
    
    mmi_frm_scrn_close_active_id();
    cui_inline_close(g_cui_set_tap_id); 
}



static mmi_ret mmi_em_motion_set_tap_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    cui_event_inline_abort_struct *evt_abort = (cui_event_inline_abort_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:  
        mmi_display_popup_confirm((UI_string_type)GetString(STR_GLOBAL_YES),
            (PU8)GetImage(IMG_GLOBAL_YES),
            (UI_string_type)GetString(STR_GLOBAL_NO),
            (PU8)GetImage(IMG_GLOBAL_NO),
            (UI_string_type)GetString(STR_GLOBAL_SAVE),
            MMI_EVENT_QUERY);
        SetLeftSoftkeyFunction(mmi_em_motion_write_tap_para, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        
        break;
        
    case EVT_ID_CUI_INLINE_ABORT:
        
        cui_inline_close(evt_abort->sender_id);
        
        break;
        
    case EVT_ID_GROUP_DEINIT:
        mmi_frm_group_close(g_gourp_set_tap_id);
        break;
        
    default:
        break;
    }
    return MMI_RET_OK;	  
}




static void mmi_em_motion_set_tap_para()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     
    U16 cui_inline_id;
    U16 tap_read_para[2][10] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gourp_set_tap_id = mmi_frm_group_create(mmi_em_motion_cntx->cur_gid,
        GRP_ID_AUTO_GEN, mmi_em_motion_set_tap_proc, NULL);
    
    mmi_frm_group_enter(g_gourp_set_tap_id, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
    
    g_cui_set_tap_id = cui_inline_id = cui_inline_create(g_gourp_set_tap_id, &set_tap_inline);
    
    cui_inline_set_text_len(cui_inline_id,MMI_EM_MOTION_SET_TAP_PLUS_EDITOR,9);
    cui_inline_set_text_len(cui_inline_id,MMI_EM_MOTION_SET_TAP_THRESHOLD_EDITOR,9);
    
    
    mmi_em_motion_read_tap_para(tap_read_para);
    
    cui_inline_set_value(cui_inline_id,MMI_EM_MOTION_SET_TAP_PLUS_EDITOR, tap_read_para[0]);
    cui_inline_set_value(cui_inline_id,MMI_EM_MOTION_SET_TAP_THRESHOLD_EDITOR, tap_read_para[1]);
    
    
    cui_inline_run(cui_inline_id);
}


#endif /*__MOTION_SENSOR_ADVANCED_GESTURE__*/




#define MMI_EM_SET_FLIP
/*--------------------- set flip  --------------------------*/

static void mmi_em_motion_read_flip_para(U16 str[][10])
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/	 
    U8 tmp_str[5][20] = {0};
    
    srv_sensor_motion_flip_para_struct para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    srv_sensor_motion_get_parameters(SRV_SENSOR_MOTION_SET_TAP,&para);
    
    srv_sensor_motion_get_parameters(SRV_SENSOR_MOTION_SET_FLIP,&para);
    
    
    sprintf((char *)tmp_str[0], "%d" ,((para.flipEnable==MMI_TRUE)?1:0));
    sprintf((char *)tmp_str[1], "%f" ,para.flipFilter);
    sprintf((char *)tmp_str[2], "%f" ,para.flipThreshold);
    sprintf((char *)tmp_str[3], "%f" ,para.tFlipDebounce);
    sprintf((char *)tmp_str[4], "%f" ,para.tFlipInterval);
    
    mmi_asc_n_to_ucs2((CHAR*)str[0] , (CHAR*) tmp_str[0], 6);
    mmi_asc_n_to_ucs2((CHAR*)str[1] , (CHAR*) tmp_str[1], 6);
    mmi_asc_n_to_ucs2((CHAR*)str[2] , (CHAR*) tmp_str[2], 6);
    mmi_asc_n_to_ucs2((CHAR*)str[3] , (CHAR*) tmp_str[3], 6);
    mmi_asc_n_to_ucs2((CHAR*)str[4] , (CHAR*) tmp_str[4], 6);
    
}

static void mmi_em_motion_write_flip_para()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 input_tmp_str[5][20] = {0};
    U8 output_tmp_str[5][20] = {0};
    U8 i = 0;
    U8 j = 0;
    MMI_BOOL flip_enable = MMI_TRUE;
    MMI_BOOL flag = MMI_TRUE; 
    float flip_para[4] = {0};
    
    srv_sensor_motion_flip_para_struct set_flip_para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0,j=1; i<5; i++,j=j+2)
    {
        cui_inline_get_value(g_cui_set_flip_id, set_flip_item[j].item_id, input_tmp_str[i]);
        if (j == 1)
        {
            if (input_tmp_str[i][0] == '0')
                flip_enable = MMI_FALSE;
            else if(input_tmp_str[i][0] == '1')
                flip_enable = MMI_TRUE;
            else
                flag = MMI_FALSE; /* Invalid parameter */
        }
        else
        {
            mmi_ucs2_n_to_asc(output_tmp_str[i],input_tmp_str[i],10);	
            flip_para[i-1] = strtod(output_tmp_str[i],NULL);	
        }
    }
    
    if (flip_para[0]>1.0 || flip_para[0]<0.3
        || flip_para[1]>0.0 || flip_para[1]<-0.5
        || flip_para[2]>2.0 || flip_para[2]<0.1
        || flip_para[3]>1.5 || flip_para[3]<0.6)
    {
        /* Out of range */
        flag = MMI_FALSE;	
    }
    
    if (!flag)
    {
        mmi_frm_scrn_close_active_id();
        cui_inline_close(g_cui_set_flip_id);
        
        mmi_popup_display_simple((WCHAR*)GetString(STR_ID_EM_DEV_MOTION_OUT_OF_RANGE), 
            MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        return;
    }
    
    set_flip_para.flipEnable = flip_enable;
    set_flip_para.flipFilter = flip_para[0];
    set_flip_para.flipThreshold = flip_para[1];
    set_flip_para.tFlipDebounce = flip_para[2];
    set_flip_para.tFlipInterval = flip_para[3];
    
    srv_sensor_motion_set_parameters(SRV_SENSOR_MOTION_SET_FLIP,&set_flip_para);
    
    kal_prompt_trace(MOD_MMI,"[EM set flip]Filter %s, Threshold %s, Debounce %s, Interval %s",
        input_tmp_str[1],input_tmp_str[2],input_tmp_str[3],input_tmp_str[4]);
    
    
    mmi_frm_scrn_close_active_id();
    cui_inline_close(g_cui_set_flip_id);
}


static mmi_ret mmi_em_motion_set_flip_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    cui_event_inline_abort_struct *evt_abort = (cui_event_inline_abort_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:  
        mmi_display_popup_confirm((UI_string_type)GetString(STR_GLOBAL_YES),
            (PU8)GetImage(IMG_GLOBAL_YES),
            (UI_string_type)GetString(STR_GLOBAL_NO),
            (PU8)GetImage(IMG_GLOBAL_NO),
            (UI_string_type)GetString(STR_GLOBAL_SAVE),
            MMI_EVENT_QUERY);
        SetLeftSoftkeyFunction(mmi_em_motion_write_flip_para, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        
        break;
        
    case EVT_ID_CUI_INLINE_ABORT:
        
        cui_inline_close(evt_abort->sender_id);
        
        break;
        
    case EVT_ID_GROUP_DEINIT:
        mmi_frm_group_close(g_gourp_set_flip_id);
        break;
        
    default:
        break;
    }
    return MMI_RET_OK;	  
}



static void mmi_em_motion_set_flip_para()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     
    U16 cui_inline_id;
    U16 flip_read_para[5][10] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gourp_set_flip_id = mmi_frm_group_create(mmi_em_motion_cntx->cur_gid,
        GRP_ID_AUTO_GEN, mmi_em_motion_set_flip_proc, NULL);
    
    mmi_frm_group_enter(g_gourp_set_flip_id, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
    
    g_cui_set_flip_id = cui_inline_id = cui_inline_create(g_gourp_set_flip_id, &set_flip_inline);
    
    cui_inline_set_text_len(cui_inline_id,MMI_EM_MOTION_SET_FLIP_ENABLE_EDITOR,6);
    cui_inline_set_text_len(cui_inline_id,MMI_EM_MOTION_SET_FLIP_FILTER_EDITOR,6);;
    cui_inline_set_text_len(cui_inline_id,MMI_EM_MOTION_SET_FLIP_THRESHOLD_EDITOR,6);
    cui_inline_set_text_len(cui_inline_id,MMI_EM_MOTION_SET_FLIP_DEBOUNCE_EDITOR,6);
    cui_inline_set_text_len(cui_inline_id,MMI_EM_MOTION_SET_FLIP_INTERVAL_EDITOR,6);
    
    mmi_em_motion_read_flip_para(flip_read_para);
    
    cui_inline_set_value(cui_inline_id,MMI_EM_MOTION_SET_FLIP_ENABLE_EDITOR, flip_read_para[0]);
    cui_inline_set_value(cui_inline_id,MMI_EM_MOTION_SET_FLIP_FILTER_EDITOR, flip_read_para[1]);
    cui_inline_set_value(cui_inline_id,MMI_EM_MOTION_SET_FLIP_THRESHOLD_EDITOR, flip_read_para[2]);
    cui_inline_set_value(cui_inline_id,MMI_EM_MOTION_SET_FLIP_DEBOUNCE_EDITOR, flip_read_para[3]);
    cui_inline_set_value(cui_inline_id,MMI_EM_MOTION_SET_FLIP_INTERVAL_EDITOR, flip_read_para[4]);
    
    
    cui_inline_run(cui_inline_id);
}


#define MMI_EM_MOTION_TILT_DETAIL

srv_sensor_motion_tilt_cfg_struct tilt_mode;


/*****************************************************************************
* FUNCTION
*  mmi_em_motion_tilt_detail_info_callback
* DESCRIPTION
*  tilt detail information callback funciton
* PARAMETERS
*  direct      direction of the phone
*  action      the action of user
*  *detail_p   pointer of the detail info
* RETURNS
*  void
*****************************************************************************/
void mmi_em_motion_tilt_detail_info_callback(
                                             srv_sensor_type_enum sensor_type, 
                                             void *sensor_data, 
                                             void *user_data  )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type my_scr_wtext[100];
    
    
    srv_sensor_motion_tilt_struct *p_tilt;
    
    U8 text_hight;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/*
    if((count++)%10 > 0)
    {
        return;
    }
    */
    
    
    
    p_tilt = (srv_sensor_motion_tilt_struct *)sensor_data;
    
    mmi_em_motion_draw_init(&MMI_medium_font, gui_color(255, 255, 255),
        GDI_COLOR_BLACK, &text_hight);
    
	if(tilt_mode.sensitive == SRV_SENSOR_MOTION_NORMAL_TILT)
	{
	    kal_wsprintf(my_scr_wtext,"---Filter noise---");
        mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_BEGIN_LINE);
	}
	else
	{
	    kal_wsprintf(my_scr_wtext,"---Raw data ---");
    mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_BEGIN_LINE);
	}
    
    kal_wsprintf(my_scr_wtext,"angle: gx=%5d gy=%5d gz=%5d",p_tilt->angle.gx, p_tilt->angle.gy, p_tilt->angle.gz);
    mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_NEXT_LINE);
    
    kal_wsprintf(my_scr_wtext,"acc  : ax=%5d ay=%5d az=%5d",
        p_tilt->acc.x, 
        p_tilt->acc.y, 
        p_tilt->acc.z);
	
	mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_NEXT_LINE);

	
	/*

	mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_NEXT_LINE);

	kal_wsprintf(my_scr_wtext,"---Filter noise---");

	mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_NEXT_LINE);

	 kal_wsprintf(my_scr_wtext,"acc  : ax=%5d ay=%5d az=%5d",
        p_tilt->acc_filter_noise.x, 
        p_tilt->acc_filter_noise.y, 
        p_tilt->acc_filter_noise.z);

	mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_NEXT_LINE);
	
	 kal_wsprintf(my_scr_wtext,"angle: gx=%5d gy=%5d gz=%5d",
	 	p_tilt->angle_filter_noise.gx, p_tilt->angle_filter_noise.gy, p_tilt->angle_filter_noise.gz);
	 

	 
    mmi_em_motion_draw_text(10, 2, text_hight, my_scr_wtext, MMI_EM_MOTION_DRAW_NEXT_LINE);
    
    */
    
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

/*****************************************************************************
* FUNCTION
*  mmi_em_motion_tilt_detail_info_app
* DESCRIPTION
*  The entry of detail information show application
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_motion_tilt_detail_info_app(mmi_em_motion_tilt_mode_enum sens)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sensor_motion_tilt_struct   init;
    MMI_BOOL entry_ret;
	
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (sens == MMI_EM_MOTION_TILT_NORMAL)
    {
        tilt_mode.sensitive = SRV_SENSOR_MOTION_NORMAL_TILT;
    }
	else
	{
	    tilt_mode.sensitive = SRV_SENSOR_MOTION_RAW_TILT;
	}
	
    entry_ret = mmi_frm_scrn_enter (mmi_em_motion_cntx->cur_gid, SCR_ID_EM_MOTION_APP_SHOW, mmi_em_motion_exit_app, mmi_em_motion_tilt_detail_info_app, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
    init.acc.x = 0;
    init.acc.y = 0;
    init.acc.z = 0;
    init.angle.gx = 0;
    init.angle.gy = 0;
    init.angle.gz = 0;
    
    mmi_em_motion_tilt_detail_info_callback(SRV_SENSOR_MOTION_TILT, &init, NULL);
	
    g_handle = 
        srv_sensor_start_listen(SRV_SENSOR_MOTION_TILT , &tilt_mode ,mmi_em_motion_tilt_detail_info_callback, NULL);

#ifndef __COSMOS_MMI_PACKAGE__    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
#endif 
    
}


#ifdef __MTK_INTERNAL__
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
#ifndef __COSMOS_MMI_PACKAGE__    
/* under construction !*/
#else
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MTK_INTERNAL__*/

#define MMI_EM_MOTION_SHAKE
/*****************************************************************************
* FUNCTION
*  mmi_em_motion_shake_callback
* DESCRIPTION
*  the callback of shake detection
* PARAMETERS
*  param       shake direction
* RETURNS
*  void
*****************************************************************************/
void mmi_em_motion_shake_callback(srv_sensor_type_enum sensor_type,
                                  void *sensor_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type my_scr_wtext[100];
    U8 wtext_shake[][20]= 
    {{"SHAKE NULL"},   {"SHAKEING"}};
    U8 text_hight;
    srv_sensor_motion_shake_struct * p_shake;
    U8 index = 0;
    em_motion_line_enum draw_line = MMI_EM_MOTION_DRAW_BEGIN_LINE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_shake = (srv_sensor_motion_shake_struct *)sensor_data;
    if(p_shake->action == SRV_SENSOR_MOTION_SHAKING)
    {
        index = 1;
    }
    else
    {
        index = 0;
    }
    mmi_em_motion_draw_init(&MMI_large_font, gui_color(255, 255, 255),
        GDI_COLOR_BLACK, &text_hight);
    
    mmi_em_motion_cntx->shake_text_line++;
    if (mmi_em_motion_cntx->shake_text_line > 10)
    {
        mmi_em_motion_cntx->shake_text_line = 1;
        draw_line = MMI_EM_MOTION_DRAW_BEGIN_LINE;
    }
    else if (mmi_em_motion_cntx->shake_text_line > 1)
        draw_line = MMI_EM_MOTION_DRAW_NEXT_LINE; 
    
    kal_wsprintf(my_scr_wtext,"[%d]%s",mmi_em_motion_cntx->shake_text_line, wtext_shake[index]);
    mmi_em_motion_draw_text(10, 1, text_hight, my_scr_wtext, draw_line);
    
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

/*****************************************************************************
* FUNCTION
*  mmi_em_motion_shake_app
* DESCRIPTION
*  start shake detect app
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_motion_shake_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    srv_sensor_motion_shake_cfg_struct shake_sensitive;
    srv_sensor_motion_shake_struct    shake_action; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter (mmi_em_motion_cntx->cur_gid, SCR_ID_EM_MOTION_APP_SHOW, mmi_em_motion_exit_app, mmi_em_motion_shake_app, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
    shake_sensitive.sensitive = mmi_em_motion_cntx->sensitive;
    shake_action.action = SRV_SENSOR_MOTION_SHAKE_NULL;
    mmi_em_motion_cntx->shake_text_line = 0;
    mmi_em_motion_shake_callback(SRV_SENSOR_MOTION_SHAKE,&shake_action,NULL);
    g_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_SHAKE, &shake_sensitive ,mmi_em_motion_shake_callback,NULL);
    
#ifndef __COSMOS_MMI_PACKAGE__    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
#endif 
}


#define EM_MOTION_NORMAL_TILT
//Jerry
/*****************************************************************************
* FUNCTION
*  mmi_em_rotate_direct
* DESCRIPTION
*  provide the action of rotation
* PARAMETERS
* old_angle       the old angle of object
* new_angle       the new angle of object
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_em_rotate_direct(S32 old_angle, S32 new_angle)
{
    MMI_BOOL direct;
    if (old_angle == 0 && new_angle == 270)
        old_angle = 360;
    if (old_angle == 270 && new_angle == 0)
        new_angle = 360;
    
    direct = (new_angle > old_angle) ? MMI_TRUE : MMI_FALSE;

    kal_prompt_trace(MOD_MMI,"[mcube][em]old_angle:%d, new_angle:%d, direct:%d",
    old_angle, new_angle, direct);
    
    return direct;
    
}

/*****************************************************************************
* FUNCTION
*  mmi_em_motion_tilt_normal_rotate_to_interval
* DESCRIPTION
*  Rotate action update function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
//Jerry
void mmi_em_motion_tilt_normal_rotate_to_interval(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 r, i;
    S32 bl_r[4], bl_angle[4], bl_x[4], bl_y[4];
    double f_angle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (mmi_em_motion_cntx->new_angle != mmi_em_motion_cntx->old_angle)
    {
        if (mmi_em_motion_cntx->direct == MMI_TRUE)
        {
            mmi_em_motion_cntx->old_angle += MMI_MOTION_ROTATE_STEP;
        }
        else
        {
            mmi_em_motion_cntx->old_angle -= MMI_MOTION_ROTATE_STEP;
            if (mmi_em_motion_cntx->old_angle < 0)
            {
                mmi_em_motion_cntx->old_angle += MMI_MOTION_360_DEGREE;
            }
        }
        if (abs(abs(mmi_em_motion_cntx->new_angle) - abs(mmi_em_motion_cntx->old_angle)) <= MMI_MOTION_ROTATE_STEP * 2)
        {
            mmi_em_motion_cntx->old_angle = mmi_em_motion_cntx->new_angle;
        }
        else
        {
            mmi_em_motion_cntx->old_angle %= MMI_MOTION_360_DEGREE;
            gui_start_timer(MMI_MOTION_ROTATE_INTERVAL,mmi_em_motion_tilt_normal_rotate_to_interval);
        }
    }

    gdi_layer_clear(GDI_COLOR_BLACK);
    if (UI_device_width > UI_device_height)
    {
        r = UI_device_height/2 - 10;
    }
    else
    {
        r = UI_device_width/2 - 10;
    }
    bl_r[0] = r;    bl_angle[0] = 0;
    bl_r[1] = r/2;  bl_angle[1] = 120;
    bl_r[2] = r/2;  bl_angle[2] = 0;
    bl_r[3] = r/2;  bl_angle[3] = 240;
    
    f_angle = mmi_em_motion_cntx->old_angle;
    for (i = 0; i<4 ; i++)
    {
        bl_y[i] = (S32)(UI_device_height/2 - 1 + bl_r[i] * cos(PI * (f_angle + bl_angle[i])/ 180));
        bl_x[i] = (S32)(UI_device_width/2 - 1 + bl_r[i] * sin(PI * (f_angle + bl_angle[i])/ 180));
    }
    for (i = 0; i<3 ; i++)
    {
        gdi_draw_line(bl_x[i],bl_y[i], bl_x[i+1], bl_y[i+1],GDI_COLOR_GREEN);
    }
    gdi_draw_line(bl_x[0],bl_y[0], bl_x[3], bl_y[3],GDI_COLOR_GREEN);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

/*****************************************************************************
* FUNCTION
*  mmi_em_motion_tilt_normal_rotate_to
* DESCRIPTION
*  set the posiotn want the object rotate to
* PARAMETERS
*  new_angle       the new angle of object
* RETURNS
*  void
*****************************************************************************/
void mmi_em_motion_tilt_normal_rotate_to(S32 new_angle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //Jerry
    mmi_em_motion_cntx->new_angle = new_angle % MMI_MOTION_360_DEGREE;
    mmi_em_motion_cntx->direct = mmi_em_rotate_direct(mmi_em_motion_cntx->old_angle, 
        mmi_em_motion_cntx->new_angle);//rotate_direct;
    mmi_em_motion_tilt_normal_rotate_to_interval();
}

/*****************************************************************************
* FUNCTION
*  mmi_em_motion_tilt_normal_to_axis_callback
* DESCRIPTION
*  tilt normal application callback function
* PARAMETERS
*  direct      direction of the phone
*  action      the action of user
*  *detail_p   pointer of the detail info
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_motion_tilt_normal_to_axis_callback(
                                                       srv_sensor_type_enum            type,
                                                       void                           *sensor_data, 
                                                       void                            *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 angle = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    srv_sensor_motion_direct_struct *p_direct;
    p_direct = (srv_sensor_motion_direct_struct *)sensor_data;
    
    
    switch (p_direct->direct)
    {
    case SRV_SENSOR_MOTION_ANGLE_GX0:
        angle = 90;
        break;
    case SRV_SENSOR_MOTION_ANGLE_GY0:
        angle = 180;
        break;
    case SRV_SENSOR_MOTION_ANGLE_GX180:
        angle = 270;
        break;
    case SRV_SENSOR_MOTION_ANGLE_GY180:
        angle = 0;
        break;
    default:
        return;
    }
    
    mmi_em_motion_tilt_normal_rotate_to(angle);
    //Jerry
}

/*****************************************************************************
* FUNCTION
*  mmi_em_motion_tilt_normal_app
* DESCRIPTION
*  tilt normal app entry
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_motion_tilt_normal_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sensor_motion_direct_cfg_struct threshold;
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter (mmi_em_motion_cntx->cur_gid, SCR_ID_EM_MOTION_APP_SHOW, mmi_em_motion_exit_app, mmi_em_motion_tilt_normal_app, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
    //mmi_em_motion_stop_all();
    gdi_layer_clear(GDI_COLOR_BLACK);
    mmi_em_motion_tilt_normal_rotate_to(0);//Jerry
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    
    threshold.angle_threshold = mmi_em_motion_cntx->angle_threshold;
    
    g_handle  = 
        srv_sensor_start_listen(SRV_SENSOR_MOTION_DIRECT ,&threshold,mmi_em_motion_tilt_normal_to_axis_callback,NULL);
    
#ifndef __COSMOS_MMI_PACKAGE__    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
#endif 
}



#define MMI_EM_MOTION_EXIT

/*****************************************************************************
* FUNCTION
*  mmi_em_motion_stop_all
* DESCRIPTION
*  stop all motion detection
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_em_motion_stop_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sensor_stop_listen(g_handle);
    kal_prompt_trace(MOD_MMI,"[EM_motion]srv_sensor_stop_listen %d",g_handle);
    g_handle = -1;

	#ifdef  __MTK_INTERNAL__
/* under construction !*/
	#endif /* __MTK_INTERNAL__*/

    gui_cancel_timer(mmi_em_motion_tilt_normal_rotate_to_interval);
	    
    g_tap_count = 0;
    g_double_tap_count = 0;
    g_turnover_count = 0;
    g_step_count = 0;
    g_shake_count_x = 0;
    g_shake_count_y = 0;
    g_shake_count_z = 0;
    
    g_drop_count = 0;
    
}

/*****************************************************************************
* FUNCTION
*  mmi_em_motion_exit_app
* DESCRIPTION
*  when exit motion app close all opens
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_motion_exit_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_motion_stop_all();
    srv_backlight_turn_off();
    kal_prompt_trace(MOD_MMI,"[EM_motion]mmi_em_motion_exit_app");
}

#define EM_MOTION_ENT_PROC
/*****************************************************************************
* FUNCTION
*  mmi_em_motion_group_proc
* DESCRIPTION
*   
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/

mmi_ret mmi_em_motion_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_event = (cui_menu_event_struct*)evt;
    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
        mmi_frm_group_close(mmi_em_motion_cntx->cur_gid);
        if (mmi_em_motion_cntx)
        {
            MMI_EM_FREE(mmi_em_motion_cntx);
            mmi_em_motion_cntx = NULL;
        }
        break;
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        if(menu_event->parent_menu_id == MENU_ID_EM_DEV_MOTION_APP_MAIN
			|| menu_event->parent_menu_id == MENU_ID_EM_DEV_MOTION_SHAKE)
        {
            cui_menu_set_currlist_flags(menu_event->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        }
        break;
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_event->sender_id);
        break;
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        switch (menu_event->highlighted_menu_id)
        {
        case MENU_ID_EM_DEV_MOTION_TILT_NORMAL:
            mmi_em_motion_tilt_normal_app();
            break;
			
	#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif /*__MTK_INTERNAL__*/

	
		case MENU_ID_EM_DEV_MOTION_SEN_HIGH:
			mmi_em_motion_cntx->sensitive = SRV_SENSOR_MOTION_SHAKE_STRONG;
			mmi_em_motion_shake_app();
		   // mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_OK), MMI_EVENT_SUCCESS, mmi_em_motion_cntx->cur_gid, NULL);
			break;
		case MENU_ID_EM_DEV_MOTION_SEN_NORMAL:
			mmi_em_motion_cntx->sensitive = SRV_SENSOR_MOTION_SHAKE_MEDIUM;
			//mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_OK), MMI_EVENT_SUCCESS, mmi_em_motion_cntx->cur_gid, NULL);
			mmi_em_motion_shake_app();
			break;
		case MENU_ID_EM_DEV_MOTION_SEN_LOW:
			mmi_em_motion_cntx->sensitive = SRV_SENSOR_MOTION_SHAKE_WEAK;
			//mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_OK), MMI_EVENT_SUCCESS, mmi_em_motion_cntx->cur_gid, NULL);
			mmi_em_motion_shake_app();
			break;
	
        case MENU_ID_EM_DEV_MOTION_DRAW_DETAIL:
            mmi_em_motion_tilt_detail_info_app(MMI_EM_MOTION_TILT_RAW);
            break;

		case MENU_ID_EM_DEV_MOTION_DRAW_DETAIL_FILTER_NOISE:
			mmi_em_motion_tilt_detail_info_app(MMI_EM_MOTION_TILT_NORMAL);
            break;
			
        case MENU_ID_EM_DEV_MOTION_ADVANCED_SHAKE:
            mmi_em_motion_advanced_shake_test();
            break;
        case MENU_ID_EM_DEV_MOTION_TURNOVER:
            mmi_em_motion_turnover();
            break;
            
#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
        case MENU_ID_EM_DEV_MOTION_TAP:
            mmi_em_motion_tap();
            break;
        case MENU_ID_EM_DEV_MOTION_DOUBLE_TAP:
            mmi_em_motion_double_tap();
            break;
            
		/*
        case MENU_ID_EM_DEV_MOTION_STEP:
            mmi_em_motion_step();
            break;
        */

		case MENU_ID_EM_DEV_MOTION_STEP:
			break;

		case MENU_ID_EM_DEV_MOTION_STEP_SEN_HIGH:
			mmi_em_motion_step(MMI_EM_MOTION_STEP_HIGH);
			break;
		case MENU_ID_EM_DEV_MOTION_STEP_SEN_NORMAL:
			mmi_em_motion_step(MMI_EM_MOTION_STEP_MED);
			break;
		case MENU_ID_EM_DEV_MOTION_STEP_SEN_LOW:
			mmi_em_motion_step(MMI_EM_MOTION_STEP_LOW);
			break;
            
        case MENU_ID_EM_DEV_MOTION_DROP:
            mmi_em_motion_drop();
            break;
            
        case MENU_ID_EM_DEV_MOTION_SET_TAP_PARA:
            mmi_em_motion_set_tap_para();
            break;
#endif /*__MOTION_SENSOR_ADVANCED_GESTURE__*/
            
        case MENU_ID_EM_DEV_MOTION_SET_FLIP_PARA:
            mmi_em_motion_set_flip_para();
            break;
		case MENU_ID_EM_DEV_MOTION_SHAKE:
			break;
            
        default:
            cui_menu_close(menu_event->sender_id);
            break;
        }
        break;
    }
    return MMI_RET_OK;
}

#define MMI_EM_MOTION_DRAW_MAINSCR
/*****************************************************************************
* FUNCTION
*  mmi_em_motion_sensor_entry
* DESCRIPTION
*  enter em motion sensor screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_em_motion_sensor_draw_mainscr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mmi_em_motion_cntx != NULL);
    mmi_em_motion_cntx->cui_menu_id = cui_menu_create(
        mmi_em_motion_cntx->cur_gid, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_FROM_RESOURCE, 
        MENU_ID_EM_DEV_MOTION_APP_MAIN, 
        MMI_TRUE, 
        NULL);
    cui_menu_run(mmi_em_motion_cntx->cui_menu_id);
}

#define EM_MOTION_ENTERY
/*****************************************************************************
* FUNCTION
*  mmi_em_motion_sensor_entry
* DESCRIPTION
*  enter em motion sensor screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_em_motion_sensor_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cur_gid;
    // MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_gid = mmi_frm_group_create (GRP_ID_ROOT,  GRP_ID_AUTO_GEN, mmi_em_motion_group_proc, NULL);
    mmi_frm_group_enter(cur_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    ASSERT (mmi_em_motion_cntx == NULL);
    mmi_em_motion_cntx = (mmi_em_motion_cntx_struct*)MMI_EM_MALLOC(sizeof(mmi_em_motion_cntx_struct));
    memset(mmi_em_motion_cntx, 0, sizeof(mmi_em_motion_cntx_struct));
    mmi_em_motion_cntx->detail_info_handle = -1;
    mmi_em_motion_cntx->shake_handle = -1;
    mmi_em_motion_cntx->tilt_detail_handle = -1;
    mmi_em_motion_cntx->tilt_normal_handle = -1;
    mmi_em_motion_cntx->cur_gid = cur_gid;
    mmi_em_motion_cntx->direct_sen[0] = 0;
    mmi_em_motion_cntx->direct_sen[1] = 0;
    mmi_em_motion_cntx->direct_sen[2] = 0;
    mmi_em_motion_cntx->angle_threshold = 30;
    mmi_em_motion_sensor_draw_mainscr();
}



#endif /*__MMI_EM_MOTION_APP__*/
