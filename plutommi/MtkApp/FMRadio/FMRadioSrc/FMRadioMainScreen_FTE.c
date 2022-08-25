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
*  FMRadioMainScreen_FTE.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio main screen drawing program
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__
#ifdef __MMI_FTE_SUPPORT__

#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#include "FMRadioMainScreen.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "kal_non_specific_general_types.h"
#include "wgui_categories_util.h"
#include "gui.h"
#include "CustDataRes.h"
#include "gdi_include.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "GlobalConstants.h"
#include "gui_windows.h"
#include "gui_config.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "lcd_sw_inc.h"
#include "gui_data_types.h"
#include "kal_release.h"
#include "mmi_rp_app_fmrdo_def.h"
#include "gui_switch.h"
#include "GlobalResDef.h"
#include "GpiosrvGprot.h"

#include "Wgui_softkeys.h"

#ifdef __MMI_WEARABLE_DEVICE__
#define MMI_SWATCH_BACK_MOVE_THRESHOLD_X  (LCD_WIDTH/3)
static MMI_BOOL g_swatch_is_pen_down = MMI_FALSE;
static mmi_pen_point_struct g_swatch_pen_down_pos = {0};
#endif  //__MMI_WEARABLE_DEVICE__

/* MTK Leo add 20050301, add touch screen support for FM Radio */
#ifdef __MMI_TOUCH_SCREEN__
#endif 
/* MTK Leo end */
#include "gui_font_size.h"

#include "gui_touch_feedback.h"
#ifdef __MMI_FM_RADIO_ANIMATION__
#ifdef __RF_DESENSE_TEST__
#include "rf_desense_test.h"
#endif /*__RF_DESENSE_TEST__*/
GDI_HANDLE fmrdo_anim_layer;
U8 *fmrdo_anim_layer_buf_ptr;
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

#ifndef __FTE_NON_SLIM_RES__
#define MMI_FMRDO_TEXT_HORZ_ACENTER     0x00000001
#define MMI_FMRDO_TEXT_HORZ_ALEFT       0x00000002
#define MMI_FMRDO_TEXT_HORZ_ARIGHT      0x00000004
#define MMI_FMRDO_TEXT_VERT_ACERTER     0x00000010
#define MMI_FMDRO_TEXT_VERT_ATOP        0x00000020
#define MMI_FMRDO_TEXT_VERT_ABOTTOM     0x00000040
#define MMI_FMRDO_TEXT_HAS_BORDER       0x00000100

#define MMI_FMRDO_FLAG_SCROLLING        0x00000001

#define FMRDO_FLAG_SET(f, b)        ((f) |= (b))
#define FMRDO_FLAG_RESET(f, b)      ((f) &= ~(b))
#define FMRDO_FALG_CLEAR(f)         ((f) &= 0 )
#define FMRDO_FLAG_CHECK(f, b)      ((f) & (b))
#endif


GDI_HANDLE fmrdo_osd_layer;
GDI_HANDLE fmrdo_skin_layer;
BOOL is_fmrdo_skin_layer_drawn = FALSE;

static fmrdo_main_draw_struct fmrdo_main_draw;  /* all memeber variables are zero initial */
U8 g_vol_displayed;
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
static U8 g_vol_highlight;
static S32 g_vol_ind_x, g_vol_ind_y;
#endif /*MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT*/
#if defined(__MMI_FM_RADIO_RECORD__)
U8 animate_count;
#endif 

#ifdef __MMI_FM_RADIO_RDS__
	U16	rds_str1[MMI_FMRDO_RDS_PS_NAME_SIZE + MMI_FMRDO_RDS_RT_SIZE + 2];
#endif/*__MMI_FM_RADIO_RDS__*/

#ifdef __MMI_FM_RADIO_ANIMATION__
#ifdef __RF_DESENSE_TEST__
#include "rf_desense_test.h"
#endif /*__RF_DESENSE_TEST__*/
#endif /*__MMI_FM_RADIO_ANIMATION__*/

extern mmi_fmrdo_struct g_fmrdo;                    /* defined in FMRadioSrc.c */
extern S32 UI_device_width;                         /* from gui_wrapper.c */
extern S32 UI_device_height;                        /* from gui_wrapper.c */
extern const mmi_fmrdo_skin_struct g_fmrdo_skins[]; /* defined in resource_fmradio_skins.c */
#define MMI_FMRDO_ANIMATE_FRAME_COUNT 5

extern void kal_wsprintf(unsigned short *outstr, char *fmt, ...);
extern BOOL r2lMMIFlag; /* definedi n gui_inputs.c */

#ifdef __MMI_TOUCH_SCREEN__
/* MTK Leo add 20050301, add touch screen support for FM Radio */
typedef enum
{
    FMRDO_PEN_NONE,
    FMRDO_PEN_LSK,
    FMRDO_PEN_RSK,
    FMRDO_PEN_MAIN_STEP_UP,
    FMRDO_PEN_MAIN_STEP_DOWN,
    FMRDO_PEN_MAIN_MEMO_UP,
    FMRDO_PEN_MAIN_MEMO_DOWN,
    FMRDO_PEN_MAIN_POWER,
    FMRDO_PEN_MAIN_REC,
    FMRDO_PEN_MAIN_VOL_MUTE,
    FMRDO_PEN_MAIN_VOLUME_IND,
    FMRDO_PEN_MAIN_VOL,
    FMRDO_PEN_MAIN_VOL_TOUCH,
    FMRDO_PEN_MAIN_REC_PAUSE,
    FMRDO_PEN_MAIN_REC_STOP,
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    FMRDO_PEN_MAIN_KEY_ONLY_SPEAKER_MUTE,
#endif
    FMRDO_PEN_MAIN_SEARCH,
    FMRDO_PEN_MAIN_SETTING,
    FMRDO_PEN_MAIN_VOLUME_INC,
    FMRDO_PEN_MAIN_VOLUME_DEC,
    FMRDO_PEN_COUNT
} FMRDO_PEN_STATE;
typedef enum
{
    FMRDO_PEN_SK_UP,
    FMRDO_PEN_SK_DOWN
} FMRDO_SOFTKEY_STATE;

S32 fmrdo_pen_event_on_object = FMRDO_PEN_NONE;
static mmi_pen_point_struct LSK_points[4];
static mmi_pen_point_struct RSK_points[4];
static mmi_pen_polygon_area_struct LSK_area;
static mmi_pen_polygon_area_struct RSK_area;

/* MTK Leo end */
extern MMI_BOOL mmi_pen_check_inside_polygon(mmi_pen_polygon_area_struct *polygon, mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 

extern void gui_draw_image_with_alpha_transparent(U8* img_ptr, S32 x, S32 y, S32 alpha);


#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #if defined(__MMI_FM_RADIO_RECORD__)
        void mmi_fmrdo_redraw_main_rec_sign(void);
    #endif
        void mmi_fmrdo_redraw_main_volume_key(void);
        static void mmi_fmrdo_support_keyonly_toggle_press_mute(void);
        static void mmi_fmrdo_support_keyonly_toggle_release_mute(void);
#endif

/* FOR FTE SLIM*/
#ifdef __MMI_FTE_SUPPORT_SLIM__
#ifdef __MMI_MAINLCD_240X400__
    #define FMRDO_SKIN_LINE_X       5
    #define FMRDO_SKIN_LINE_Y       298
    #define FMRDO_TOOL_BAR_HEIGHT   44

    #define FMRDO_VOLUME_BG_W       240
    #define FMRDO_VOLUME_BG_H       110
    #define FMRDO_VOLUME_TUNE_W     149
    #define FMRDO_VOLUME_TUNE_H     14

    #define FMRDO_RECORD_BG_W       240
    #define FMRDO_RECORD_BG_H       121
    #define FMRDO_RECORD_BTN_BG_W   78
    #define FMRDO_RECORD_BTN_BG_H   42
    #define FMRDO_RECORD_LK_X       33
    #define FMRDO_RECORD_LK_Y       168
    #define FMRDO_RECORD_RK_X       129
    #define FMRDO_RECORD_RK_Y       168
#else /* __MMI_MAINLCD_240X320__ */
    #define FMRDO_SKIN_LINE_X       6
    #define FMRDO_SKIN_LINE_Y       234
    #define FMRDO_TOOL_BAR_HEIGHT   38

    #define FMRDO_VOLUME_BG_W       240
    #define FMRDO_VOLUME_BG_H       95
    #define FMRDO_VOLUME_TUNE_W     149
    #define FMRDO_VOLUME_TUNE_H     14

    #define FMRDO_RECORD_BG_W       240
    #define FMRDO_RECORD_BG_H       121
    #define FMRDO_RECORD_BTN_BG_W   78
    #define FMRDO_RECORD_BTN_BG_H   42
    #define FMRDO_RECORD_LK_X       33
    #define FMRDO_RECORD_LK_Y       141
    #define FMRDO_RECORD_RK_X       129
    #define FMRDO_RECORD_RK_Y       141
#endif /* __MMI_MAINLCD_240X400__ */
#endif /* __MMI_FTE_SUPPORT_SLIM__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_is_record_allowed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  none        
 * RETURNS
 *  TRUE
 *****************************************************************************/
BOOL mmi_fmrdo_is_record_allowed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_FM_RADIO_BIND_EARPHONE__) && defined(__MMI_FM_RADIO_RECORD__) 
    if (!srv_earphone_is_plug_in())
    {
        return FALSE;  
    }
#endif

    if (g_fmrdo.state == FMRDO_STATE_RECORD ||
        g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE
    #if defined(__MMI_FM_RADIO_RECORD__)
        || (animate_count != 0)
    #endif
        )
    {
        return FALSE;  
    }
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_init_main_images
 * DESCRIPTION
 *  Initialize main draw structure for images
 * PARAMETERS
 *  skin_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_init_main_images(S32 skin_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, w2, h2;
    const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* LSK */
    fmrdo_main_draw.LSK.x = skin_p->lsk_img_x;
    fmrdo_main_draw.LSK.y = skin_p->lsk_img_y;
    fmrdo_main_draw.LSK.up_img = get_image(skin_p->lsk_img_id);
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    fmrdo_main_draw.LSK.down_img = get_image(skin_p->lsk_img_down_id);
#endif

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    #ifdef __MMI_TOUCH_SCREEN__
    LSK_area.num = 4;
    LSK_area.points = (mmi_pen_point_struct*) LSK_points;
    LSK_points[0].x = LSK_points[3].x = fmrdo_main_draw.LSK.x;
    LSK_points[1].x = LSK_points[2].x = fmrdo_main_draw.LSK.x + UI_device_width/2;
    LSK_points[0].y = LSK_points[1].y = fmrdo_main_draw.LSK.y;
    LSK_points[2].y = LSK_points[3].y = fmrdo_main_draw.LSK.y + MMI_softkey_height;
    #endif
    fmrdo_main_draw.LSK.w = UI_device_width/2;
    fmrdo_main_draw.LSK.h = MMI_softkey_height;
#else
    gui_measure_image(fmrdo_main_draw.LSK.up_img, &w, &h);
    #ifdef __MMI_TOUCH_SCREEN__
    LSK_area.num = 4;
    LSK_area.points = (mmi_pen_point_struct*) LSK_points;
    LSK_points[0].x = LSK_points[3].x = fmrdo_main_draw.LSK.x;
    LSK_points[1].x = LSK_points[2].x = fmrdo_main_draw.LSK.x + w + 30;
    LSK_points[0].y = LSK_points[1].y = fmrdo_main_draw.LSK.y;
    LSK_points[2].y = LSK_points[3].y = fmrdo_main_draw.LSK.y + h;
    #endif
    fmrdo_main_draw.LSK.w = w;
    fmrdo_main_draw.LSK.h = h;
#endif

    /* RSK */
    fmrdo_main_draw.RSK.x = skin_p->rsk_img_x;
    fmrdo_main_draw.RSK.y = skin_p->rsk_img_y;
    fmrdo_main_draw.RSK.up_img = get_image(skin_p->rsk_img_id);
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    fmrdo_main_draw.RSK.down_img = get_image(skin_p->rsk_img_down_id);
#endif

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    #ifdef __MMI_TOUCH_SCREEN__
    RSK_area.num = 4;
    RSK_area.points = (mmi_pen_point_struct*) RSK_points;
    RSK_points[0].x = RSK_points[3].x = fmrdo_main_draw.RSK.x;
    RSK_points[1].x = RSK_points[2].x = fmrdo_main_draw.RSK.x + UI_device_width/2;
    RSK_points[0].y = RSK_points[1].y = fmrdo_main_draw.RSK.y;
    RSK_points[2].y = RSK_points[3].y = fmrdo_main_draw.RSK.y + MMI_softkey_height;
    #endif
    fmrdo_main_draw.RSK.w = UI_device_width/2;
    fmrdo_main_draw.RSK.h = MMI_softkey_height;
#else
    gui_measure_image(fmrdo_main_draw.RSK.up_img, &w, &h);

    #ifdef __MMI_TOUCH_SCREEN__
    RSK_area.num = 4;
    RSK_area.points = (mmi_pen_point_struct*) RSK_points;
    RSK_points[0].x = RSK_points[3].x = fmrdo_main_draw.RSK.x - 30;
    RSK_points[1].x = RSK_points[2].x = fmrdo_main_draw.RSK.x + w;
    RSK_points[0].y = RSK_points[1].y = fmrdo_main_draw.RSK.y;
    RSK_points[2].y = RSK_points[3].y = fmrdo_main_draw.RSK.y + h;
    #endif
    fmrdo_main_draw.RSK.w = w;
    fmrdo_main_draw.RSK.h = h;
#endif

    /* channel name */
    fmrdo_main_draw.channel_name_text_border_color = gui_color(
                                                        skin_p->channel_name_text_border_color_r,
                                                        skin_p->channel_name_text_border_color_g,
                                                        skin_p->channel_name_text_border_color_b);
    fmrdo_main_draw.channel_name_text_color = gui_color(
                                                skin_p->channel_name_text_color_r,
                                                skin_p->channel_name_text_color_g,
                                                skin_p->channel_name_text_color_b);

#if defined(MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT) && defined(__MMI_FTE_SUPPORT_SLIM__)
    fmrdo_main_draw.line_img = (PU8) GetImage(skin_p->line_img_id);
    fmrdo_main_draw.line_img_x = skin_p->line_img_x;
    fmrdo_main_draw.line_img_y = skin_p->line_img_y;
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    fmrdo_main_draw.line_img_w = skin_p->line_img_w;    
    fmrdo_main_draw.line_img_h = skin_p->line_img_h;
    #endif
#elif defined(__MMI_FTE_SUPPORT_SLIM__)
    fmrdo_main_draw.bg_line = (PU8) GetImage(IMG_ID_FMRDO_SKIN_LINE);
#endif /* __MMI_FTE_SUPPORT_SLIM__ */

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    /* volume */
    fmrdo_main_draw.volume.bg_img = (PU8) GetImage(skin_p->volume_image_id);
    fmrdo_main_draw.volume.ind_img = (PU8) GetImage(skin_p->volume_image_ind_id);
    fmrdo_main_draw.volume.ind_hl_img = (PU8) GetImage(skin_p->volume_image_ind_hl_id);
    gui_measure_image(fmrdo_main_draw.volume.ind_hl_img, &w, &h);
    fmrdo_main_draw.volume.ind_w = w;
    fmrdo_main_draw.volume.ind_h = h;
    fmrdo_main_draw.volume.type = skin_p->volume_bar_type;  /* 0: horizontal, 1: vertical */
    fmrdo_main_draw.volume.x = skin_p->volume_bar_x;
    fmrdo_main_draw.volume.y = skin_p->volume_bar_y;
#ifdef __MMI_FTE_SUPPORT_SLIM__
    fmrdo_main_draw.volume.w = (S16) FMRDO_VOLUME_BG_W;
    fmrdo_main_draw.volume.h = (S16) FMRDO_VOLUME_BG_H;
#else
    gui_measure_image(fmrdo_main_draw.volume.bg_img, &w, &h);
    fmrdo_main_draw.volume.w = (S16) w;
    fmrdo_main_draw.volume.h = (S16) h;
#endif /* __MMI_FTE_SUPPORT_SLIM__ */
    fmrdo_main_draw.volume.ind_left_gap = skin_p->volume_ind_start_gap;
    fmrdo_main_draw.volume.ind_top_gap = skin_p->volume_ind_end_gap;
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

#ifdef __MMI_FM_RADIO_ANIMATION__
    /* animation */
    #ifdef __RF_DESENSE_TEST__
        if( rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION )
    #endif /*__RF_DESENSE_TEST__*/
        {
                fmrdo_main_draw.animation.x = skin_p->animation_x;
                fmrdo_main_draw.animation.y = skin_p->animation_y;
                fmrdo_main_draw.animation.animation_img = (PU8) GetImage(skin_p->animation_image_id);
        }
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    /* Volume mute */
    fmrdo_main_draw.vol_img.x = skin_p->volume_image_x;
    fmrdo_main_draw.vol_img.y = skin_p->volume_image_y;
    fmrdo_main_draw.vol_img.on_up_img = (PU8) GetImage(skin_p->volume_image_on_id);
    fmrdo_main_draw.vol_img.off_up_img = (PU8) GetImage(skin_p->volume_image_off_id);
    fmrdo_main_draw.vol_img.on_down_img = (PU8) GetImage(skin_p->volume_image_on_id);
    fmrdo_main_draw.vol_img.off_down_img = (PU8) GetImage(skin_p->volume_image_off_id);
    gui_measure_image(fmrdo_main_draw.vol_img.on_up_img, &w, &h);
    fmrdo_main_draw.vol_img.w = w;
    fmrdo_main_draw.vol_img.h = h;
    fmrdo_main_draw.vol_tune_img = (PU8) GetImage(skin_p->volume_image_tune_id);
    fmrdo_main_draw.vol_empty_img = (PU8) GetImage(skin_p->volume_image_empty_id);
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

    /* step down button */
    fmrdo_main_draw.step_down_button.up_img = (PU8) GetImage(skin_p->step_down_button_up_image_id);

    fmrdo_main_draw.step_down_button.x = skin_p->step_down_button_x;
    fmrdo_main_draw.step_down_button.y = skin_p->step_down_button_y;
    gui_measure_image(fmrdo_main_draw.step_down_button.up_img, &w, &h);
    fmrdo_main_draw.step_down_button.w = (S16) w;
    fmrdo_main_draw.step_down_button.h = (S16) h;

    /* step up button */
    fmrdo_main_draw.step_up_button.up_img = (PU8) GetImage(skin_p->step_up_button_up_image_id);

    fmrdo_main_draw.step_up_button.x = skin_p->step_up_button_x;
    fmrdo_main_draw.step_up_button.y = skin_p->step_up_button_y;
    gui_measure_image(fmrdo_main_draw.step_up_button.up_img, &w, &h);
    fmrdo_main_draw.step_up_button.w = (S16) w;
    fmrdo_main_draw.step_up_button.h = (S16) h;

    /* memo next button */
    fmrdo_main_draw.memo_up_button.up_img = (PU8) GetImage(skin_p->memo_up_button_up_image_id);

    fmrdo_main_draw.memo_up_button.x = skin_p->memo_up_button_x;
    fmrdo_main_draw.memo_up_button.y = skin_p->memo_up_button_y;
    gui_measure_image(fmrdo_main_draw.memo_up_button.up_img, &w, &h);
    fmrdo_main_draw.memo_up_button.w = (S16) w;
    fmrdo_main_draw.memo_up_button.h = (S16) h;

    /* memo previous button */
    fmrdo_main_draw.memo_dn_button.up_img = (PU8) GetImage(skin_p->memo_down_button_up_image_id);

    fmrdo_main_draw.memo_dn_button.x = skin_p->memo_down_button_x;
    fmrdo_main_draw.memo_dn_button.y = skin_p->memo_down_button_y;
    gui_measure_image(fmrdo_main_draw.memo_dn_button.up_img, &w, &h);
    fmrdo_main_draw.memo_dn_button.w = (S16) w;
    fmrdo_main_draw.memo_dn_button.h = (S16) h;

    /* power button */
    fmrdo_main_draw.power_button.on_up_img = (PU8) GetImage(skin_p->power_button_on_up_image_id);
    fmrdo_main_draw.power_button.off_up_img = (PU8) GetImage(skin_p->power_button_off_up_image_id);
    fmrdo_main_draw.power_button.x = skin_p->power_button_x;
    fmrdo_main_draw.power_button.y = skin_p->power_button_y;
    gui_measure_image(fmrdo_main_draw.power_button.on_up_img, &w, &h);
    fmrdo_main_draw.power_button.w = (S16) w;
    fmrdo_main_draw.power_button.h = (S16) h;

    /* Highlight image */
    fmrdo_main_draw.highlight_img.up_img = (PU8) GetImage(skin_p->highlight_img_id);
    gui_measure_image(fmrdo_main_draw.highlight_img.up_img, &w, &h);
    fmrdo_main_draw.highlight_img.w = (S16) w;
    fmrdo_main_draw.highlight_img.h = (S16) h;

    /* channel name */
    fmrdo_main_draw.channel_name.x = skin_p->channel_name_x;
    fmrdo_main_draw.channel_name.y = skin_p->channel_name_y;
    fmrdo_main_draw.channel_name.w = skin_p->channel_name_w;
    fmrdo_main_draw.channel_name.h = skin_p->channel_name_h;

    /* frequency */
    fmrdo_main_draw.frequency_y = skin_p->frequency_y;
    fmrdo_main_draw.freq_h_offset_x = skin_p->frequency_x;
#ifndef __FTE_NON_SLIM_RES__
	fmrdo_main_draw.freq_mhz_offset_x = skin_p->frequency_mhz_offset_x;
	fmrdo_main_draw.freq_mhz_offset_y = skin_p->frequency_mhz_offset;
#else
    fmrdo_main_draw.freq_base_num_id = skin_p->frequency_number_id_base;
    fmrdo_main_draw.freq_dot = get_image(skin_p->freq_dot_id);
    fmrdo_main_draw.freq_mhz = get_image(skin_p->freq_mhz_id);
    gui_measure_image(get_image(fmrdo_main_draw.freq_base_num_id), &w, &h);
    fmrdo_main_draw.frequency_h = h;
    fmrdo_main_draw.freq_ten_offset_x = fmrdo_main_draw.freq_h_offset_x + w;
    fmrdo_main_draw.freq_one_offset_x = fmrdo_main_draw.freq_ten_offset_x + w;
    w2 = w;
    h2 = h;
    fmrdo_main_draw.freq_dot_offset_x = fmrdo_main_draw.freq_one_offset_x + w;
    gui_measure_image(fmrdo_main_draw.freq_dot, &w, &h);
    fmrdo_main_draw.freq_dot_offset_y = fmrdo_main_draw.frequency_y + h2 - h;
    fmrdo_main_draw.freq_dec_offset_x = fmrdo_main_draw.freq_dot_offset_x + w;
#ifdef __MMI_MAINLCD_320X240__
	//fmrdo_main_draw.frequency_h = skin_p->frequency_h;
    fmrdo_main_draw.freq_mhz_offset_x = fmrdo_main_draw.freq_dot_offset_x;
#else 
    fmrdo_main_draw.freq_mhz_offset_x = fmrdo_main_draw.freq_dec_offset_x + w2;
#endif
//    gui_measure_image(fmrdo_main_draw.freq_mhz, &w, &h);
    fmrdo_main_draw.freq_mhz_offset_y = fmrdo_main_draw.frequency_y + skin_p->frequency_mhz_offset;
#endif    

#ifdef __MMI_FM_RADIO_RDS__
    fmrdo_main_draw.rds_text_border_color = gui_color(
                                                        skin_p->rds_text_border_color_r,
                                                        skin_p->rds_text_border_color_g,
                                                        skin_p->rds_text_border_color_b);
    fmrdo_main_draw.rds_text_color = gui_color(
                                                skin_p->rds_text_color_r,
                                                skin_p->rds_text_color_g,
                                                skin_p->rds_text_color_b);
    fmrdo_main_draw.rds_text.x = skin_p->rds_text_x;
    fmrdo_main_draw.rds_text.y = skin_p->rds_text_y;
    fmrdo_main_draw.rds_text.w = skin_p->rds_text_w;
    fmrdo_main_draw.rds_text.h = skin_p->rds_text_h;

    /*rds main*/
    fmrdo_main_draw.rds_ind.up_img = (PU8) GetImage(skin_p->rds_ind_up_image_id);
    fmrdo_main_draw.rds_ind.down_img = (PU8) GetImage(skin_p->rds_ind_down_image_id);
    fmrdo_main_draw.rds_ind.dis_img = (PU8) GetImage(skin_p->rds_ind_disable_image_id);
    fmrdo_main_draw.rds_ind.x = skin_p->rds_ind_x;
    fmrdo_main_draw.rds_ind.y = skin_p->rds_ind_y;
    gui_measure_image(fmrdo_main_draw.rds_ind.up_img, &w, &h);
    fmrdo_main_draw.rds_ind.w = (S16) w;
    fmrdo_main_draw.rds_ind.h = (S16) h;
	/*tp*/
    fmrdo_main_draw.tp_ind.up_img = (PU8) GetImage(skin_p->tp_ind_up_image_id);
    fmrdo_main_draw.tp_ind.down_img = (PU8) GetImage(skin_p->tp_ind_down_image_id);
    fmrdo_main_draw.tp_ind.dis_img = (PU8) GetImage(skin_p->tp_ind_disable_image_id);
    fmrdo_main_draw.tp_ind.x = skin_p->tp_ind_x;
    fmrdo_main_draw.tp_ind.y = skin_p->tp_ind_y;
    gui_measure_image(fmrdo_main_draw.tp_ind.up_img, &w, &h);
    fmrdo_main_draw.tp_ind.w = (S16) w;
    fmrdo_main_draw.tp_ind.h = (S16) h;
     /*af*/
    fmrdo_main_draw.af_ind.up_img = (PU8) GetImage(skin_p->af_ind_up_image_id);
    fmrdo_main_draw.af_ind.down_img = (PU8) GetImage(skin_p->af_ind_down_image_id);
    fmrdo_main_draw.af_ind.dis_img = (PU8) GetImage(skin_p->af_ind_disable_image_id);
    fmrdo_main_draw.af_ind.x = skin_p->af_ind_x;
    fmrdo_main_draw.af_ind.y = skin_p->af_ind_y;
    gui_measure_image(fmrdo_main_draw.af_ind.up_img, &w, &h);
    fmrdo_main_draw.af_ind.w = (S16) w;
    fmrdo_main_draw.af_ind.h = (S16) h;
#endif/*__MMI_FM_RADIO_RDS__*/

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    fmrdo_main_draw.speaker_image_on_up = (PU8)GetImage(skin_p->speaker_image_on_up_id);
	fmrdo_main_draw.speaker_image_off_up = (PU8)GetImage(skin_p->speaker_image_off_up_id);
    fmrdo_main_draw.speaker_image_on_down = (PU8)GetImage(skin_p->speaker_image_on_down_id);
    fmrdo_main_draw.speaker_image_off_down = (PU8)GetImage(skin_p->speaker_image_off_down_id);
    fmrdo_main_draw.speaker_image_x = skin_p->speaker_image_x;
    fmrdo_main_draw.speaker_image_y = skin_p->speaker_image_y;

    fmrdo_main_draw.volume_bg_image = (PU8)GetImage(skin_p->volume_bg_image_id);
    fmrdo_main_draw.volume_fg_image = (PU8)GetImage(skin_p->volume_fg_image_id);
    fmrdo_main_draw.volume_image_x = skin_p->volume_image_x;
    fmrdo_main_draw.volume_image_y = skin_p->volume_image_y;
#endif

#if defined(__MMI_FM_RADIO_RECORD__)

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    /* LSK */
    fmrdo_main_draw.LSK_resume_img_up = (PU8)GetImage(skin_p->LSK_resume_img_up_id);
    fmrdo_main_draw.LSK_resume_img_down = (PU8)GetImage(skin_p->LSK_resume_img_down_id);
    fmrdo_main_draw.LSK_pause_img_up = (PU8)GetImage(skin_p->LSK_pause_img_up_id);
    fmrdo_main_draw.LSK_pause_img_down = (PU8)GetImage(skin_p->LSK_pause_img_down_id);
    
    /* RSK */
    fmrdo_main_draw.RSK_stop_img_down = (PU8)GetImage(skin_p->RSK_stop_img_down_id);
    fmrdo_main_draw.RSK_stop_img_up = (PU8)GetImage(skin_p->RSK_stop_img_up_id);

    /*rec sign & rec time*/
    fmrdo_main_draw.rec_sgn_x = skin_p->rec_sgn_image_x;
    fmrdo_main_draw.rec_sgn_y = skin_p->rec_sgn_image_y;
    fmrdo_main_draw.rec_sgn_img = (PU8)GetImage(skin_p->rec_sgn_image_id);
    fmrdo_main_draw.rec_sgn_pause_img = (PU8)GetImage(skin_p->rec_sgn_pause_image_id);
#endif    

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    /* Record Indication Icon */
    fmrdo_main_draw.rec_button.on_up_img = (PU8) GetImage(skin_p->rec_button_image_id);
    fmrdo_main_draw.rec_button.off_up_img = (PU8) GetImage(skin_p->rec_button_dis_image_id);
    fmrdo_main_draw.rec_button.x = skin_p->rec_button_x;
    fmrdo_main_draw.rec_button.y = skin_p->rec_button_y;
    gui_measure_image(fmrdo_main_draw.rec_button.on_up_img, &w, &h);
    fmrdo_main_draw.rec_button.w = (S16) w;
    fmrdo_main_draw.rec_button.h = (S16) h;

    /* record bar */
    fmrdo_main_draw.rec_bar.bg_img = get_image(skin_p->rec_tool_bg_img_id);
    fmrdo_main_draw.rec_bar.x = skin_p->rec_tool_x;
    fmrdo_main_draw.rec_bar.y = skin_p->rec_tool_y;
#ifdef __MMI_FTE_SUPPORT_SLIM__
    fmrdo_main_draw.rec_bar.w = (S16) FMRDO_RECORD_BG_W;
    fmrdo_main_draw.rec_bar.h = (S16) FMRDO_RECORD_BG_H;
#else
    gui_measure_image(fmrdo_main_draw.rec_bar.bg_img, &w, &h);
    fmrdo_main_draw.rec_bar.w = (S16) w;
    fmrdo_main_draw.rec_bar.h = (S16) h;
#endif /* __MMI_FTE_SUPPORT_SLIM__ */

    /* record toggle icon */
    fmrdo_main_draw.bar_record_button.on_up_img = get_image(skin_p->rec_tool_rec_on_up_img_id);
    fmrdo_main_draw.bar_record_button.on_down_img = get_image(skin_p->rec_tool_rec_on_down_img_id);
    fmrdo_main_draw.bar_record_button.off_up_img = get_image(skin_p->rec_tool_rec_off_up_img_id);
    fmrdo_main_draw.bar_record_button.off_down_img = get_image(skin_p->rec_tool_rec_off_down_img_id);
    fmrdo_main_draw.bar_record_button.x = skin_p->rec_tool_rec_x;
    fmrdo_main_draw.bar_record_button.y = skin_p->rec_tool_rec_y;
    gui_measure_image(fmrdo_main_draw.bar_record_button.on_up_img, &w, &h);
    fmrdo_main_draw.bar_record_button.w = (S16) w;
    fmrdo_main_draw.bar_record_button.h = (S16) h;

    /* Stop push icon */
    fmrdo_main_draw.bar_stop_record.on_up_img = get_image(skin_p->rec_tool_stop_up_img_id);
    fmrdo_main_draw.bar_stop_record.on_down_img = get_image(skin_p->rec_tool_stop_down_img_id);
    fmrdo_main_draw.bar_stop_record.off_up_img = get_image(skin_p->rec_tool_stop_up_img_id);
    fmrdo_main_draw.bar_stop_record.off_down_img = get_image(skin_p->rec_tool_stop_down_img_id);
    fmrdo_main_draw.bar_stop_record.x = skin_p->rec_tool_stop_x;
    fmrdo_main_draw.bar_stop_record.y = skin_p->rec_tool_stop_y;
    gui_measure_image(fmrdo_main_draw.bar_stop_record.on_up_img, &w, &h);
    fmrdo_main_draw.bar_stop_record.w = (S16) w;
    fmrdo_main_draw.bar_stop_record.h = (S16) h;
#endif

    /* Record Duration */
    fmrdo_main_draw.rec_base_num_id = skin_p->rec_duration_number_id_base;
    fmrdo_main_draw.rec_num_col_id = skin_p->rec_duration_number_col_image_id;

    gui_measure_image((PU8) GetImage(fmrdo_main_draw.rec_base_num_id), &w, &h);
    gui_measure_image((PU8) GetImage(fmrdo_main_draw.rec_num_col_id), &w2, &h2);

    fmrdo_main_draw.timer_hr_0_offset_x = skin_p->rec_duration_x;
    fmrdo_main_draw.timer_hr_1_offset_x = fmrdo_main_draw.timer_hr_0_offset_x + w;
    fmrdo_main_draw.timer_col_0_offset_x = fmrdo_main_draw.timer_hr_1_offset_x + w;
    fmrdo_main_draw.timer_min_0_offset_x = fmrdo_main_draw.timer_col_0_offset_x + w2;
    fmrdo_main_draw.timer_min_1_offset_x = fmrdo_main_draw.timer_min_0_offset_x + w;
    fmrdo_main_draw.timer_col_1_offset_x = fmrdo_main_draw.timer_min_1_offset_x + w;
    fmrdo_main_draw.timer_sec_0_offset_x = fmrdo_main_draw.timer_col_1_offset_x + w2;
    fmrdo_main_draw.timer_sec_1_offset_x = fmrdo_main_draw.timer_sec_0_offset_x + w;

    fmrdo_main_draw.timer_offset_y = skin_p->rec_duration_y;
    fmrdo_main_draw.timer_offset_x2 = fmrdo_main_draw.timer_sec_1_offset_x + w;
    fmrdo_main_draw.timer_offset_y2 = fmrdo_main_draw.timer_offset_y + h;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_show_main
 * DESCRIPTION
 *  Show skin screen
 * PARAMETERS
 *  left_softkey        [IN]        
 *  right_softkey       [IN]        
 *  skin_index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_show_main(U16 left_softkey, U16 right_softkey, U8 skin_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FM_RADIO_ANIMATION__)
    S32 width, height, bufsize;
#endif 
#ifdef __MMI_FM_RADIO_RDS__
	const S32 cntx_size = sizeof(rds_str1);
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Init images, always get image in ENFB project */
	if(!g_fmrdo.in_main_screen)
	{	
		return;
	}
    if (!fmrdo_main_draw.is_ready)
    {
        mmi_fmrdo_init_main_images(skin_index);
        fmrdo_main_draw.is_ready = TRUE;
        fmrdo_main_draw.is_channel_name_scroll_ready = FALSE;
#ifdef __MMI_FM_RADIO_RDS__
        fmrdo_main_draw.is_rds_text_scroll_ready = FALSE;
#endif
    }
#ifdef __MMI_FM_RADIO_RDS__
	memset(rds_str1, 0, cntx_size);
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
    animate_count = 0;
#endif 

    gdi_layer_multi_layer_enable();
    /* get base layer as skin layer */
    gdi_layer_get_base_handle(&fmrdo_osd_layer);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_create(0, 0, UI_device_width, UI_device_height, &fmrdo_skin_layer);

#ifdef __MMI_FM_RADIO_ANIMATION__
#ifdef __RF_DESENSE_TEST__  
    if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
#endif /*__RF_DESENSE_TEST__*/
    {
        gdi_image_get_dimension(fmrdo_main_draw.animation.animation_img, &width, &height);
        if ((width > LCD_WIDTH) || (width < 0))
        {
            width = LCD_WIDTH;
        }
        if ((height > LCD_HEIGHT) || (height < 0))
        {
            height = LCD_HEIGHT;
        }
        bufsize = (width * height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
        fmrdo_anim_layer_buf_ptr = (U8*) mmi_frm_scrmem_alloc_framebuffer(bufsize);
        if (fmrdo_anim_layer_buf_ptr == NULL)
        {
            fmrdo_anim_layer_buf_ptr = (U8*) mmi_frm_scrmem_alloc_framebuffer(FMRDO_ANIM_BUFFER_SIZE_BASIC);
            MMI_ASSERT(fmrdo_anim_layer_buf_ptr != NULL);
            gdi_layer_create_using_outside_memory(
                g_fmrdo_skins[skin_index].animation_x,
                g_fmrdo_skins[skin_index].animation_y,
                FMRDO_ANIM_SIZE_BASIC_WIDTH,    /* animation minimum width on HVGA size */
                FMRDO_ANIM_SIZE_BASIC_HEIGHT,   /* animation minimum height on HVGA size */
                &fmrdo_anim_layer,
                (PU8) fmrdo_anim_layer_buf_ptr,
                (S32) FMRDO_ANIM_BUFFER_SIZE_BASIC);
        }
        else
        {
            gdi_layer_create_using_outside_memory(
                g_fmrdo_skins[skin_index].animation_x,
                g_fmrdo_skins[skin_index].animation_y,
                width,
                height,
                &fmrdo_anim_layer,
                (PU8) fmrdo_anim_layer_buf_ptr,
                (S32) bufsize);
        }
        gdi_layer_push_and_set_active(fmrdo_anim_layer);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
        gdi_layer_set_blt_layer(fmrdo_skin_layer, fmrdo_anim_layer, fmrdo_osd_layer, 0);
    }
#ifdef __RF_DESENSE_TEST__  
    else
    {
	    gdi_layer_set_blt_layer(fmrdo_skin_layer, fmrdo_osd_layer, 0, 0);
    }
#endif /*__RF_DESENSE_TEST__*/
#else /* __MMI_FM_RADIO_ANIMATION__ */ 
    gdi_layer_set_blt_layer(fmrdo_skin_layer, fmrdo_osd_layer, 0, 0);
#endif
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
    is_fmrdo_skin_layer_drawn = FALSE;

    clear_key_handlers();
    clear_left_softkey();
    clear_right_softkey();

    SetKeyDownHandler(mmi_fmrdo_redraw_main_LSK_down, KEY_LSK);
    SetKeyDownHandler(mmi_fmrdo_redraw_main_RSK_down, KEY_RSK);

    /* associate functions */
    ExitCategoryFunction = mmi_fmrdo_hide_main;
    RedrawCategoryFunction = mmi_fmrdo_redraw_main_all;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    /* draw screen */
    mmi_fmrdo_redraw_main_all();
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hide_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_hide_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);
#ifdef __MMI_FM_RADIO_RDS__
    gui_scrolling_text_stop(&fmrdo_main_draw.rds_text_scroll);
#endif
    
#ifdef __MMI_FM_RADIO_ANIMATION__
    if(fmrdo_anim_layer)
    {
        gdi_layer_free(fmrdo_anim_layer);
        fmrdo_anim_layer = NULL;
    }
#ifdef __RF_DESENSE_TEST__  
    if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
#endif /*__RF_DESENSE_TEST__*/
    {
        mmi_frm_scrmem_free((void*)fmrdo_anim_layer_buf_ptr);
        fmrdo_anim_layer_buf_ptr = NULL;
    }
#endif /*__MMI_FM_RADIO_ANIMATION__*/

    gdi_layer_flatten_to_base(fmrdo_skin_layer, fmrdo_osd_layer, 0, 0);

    gdi_layer_free(fmrdo_skin_layer);
    fmrdo_skin_layer = NULL;
    gdi_layer_multi_layer_disable();

    /* restore blt layer as base layer only */
    gdi_layer_set_blt_layer(fmrdo_osd_layer, 0, 0, 0);
 
#ifdef __MMI_TOUCH_SCREEN__
    fmrdo_pen_event_on_object = FMRDO_PEN_NONE;
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* associate functions */
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__

static void mmi_fmrdo_redraw_main_softkey_for_bt_box(MMI_BOOL is_left, MMI_BOOL is_down, U16 text_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 str_w, str_h;
    S32 x1, y1, x2, y2;
    S32 offset_x, offset_y, truncated_w;
    S32 softkey_width = 130;
    S32 x_start = is_left ? 0 : (UI_device_width/2 + 30);
    S32 y_start = UI_device_height - MMI_softkey_height;
    S32 offset_down = is_down ? 1 : 0;
    MMI_BOOL truncated = MMI_FALSE;
    WGUI_SOFTKEY_ENUM string_type = is_left ? MMI_LEFT_SOFTKEY : MMI_RIGHT_SOFTKEY;
    UI_string_type string_text = (UI_string_type) GetString(text_id);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));

    if(is_down)
    {
     	gui_set_text_color(*current_MMI_theme->LSK_down_text_color);
    	gui_set_text_border_color(*current_MMI_theme->softkey_down_text_border_color);
    }
    else
    {
    	gui_set_text_color(*current_MMI_theme->LSK_up_text_color);
        gui_set_text_border_color(*current_MMI_theme->softkey_text_border_color);
    }    

    gui_measure_string(string_text, &str_w, &str_h);
    truncated = wgui_softkey_get_offset(
                    string_text,
                    &offset_x, 
                    &offset_y, 
                    &truncated_w,
                    string_type,
                #ifdef __MMI_SCREEN_ROTATE__
                    mmi_frm_get_screen_rotate()
                #else
                    0
                #endif
                    );

    y1 = offset_y;
    y2 = offset_y + str_h;
#ifdef __MMI_BIDI_ALG__
    if(r2lMMIFlag)
    {
        x2 = offset_x;
        x1 = x2 - str_w ;
    }
    else
#endif
    {
        x1 = offset_x;
        x2 = x1 + str_w;
    }

    gdi_layer_lock_frame_buffer();
    gdi_layer_push_and_set_active(fmrdo_skin_layer);
    gdi_layer_push_and_set_clip(x_start, y_start, x_start + softkey_width, y_start + MMI_softkey_height - 1);
  
    if (is_down)
    {
        gui_draw_filled_area(
                  x_start, 
                  y_start,
                  x_start + softkey_width,
                  y_start + MMI_softkey_height - 1,                 
                  current_MMI_theme->softkey_lsk_down_filler);
    }
    else
    {
        gui_draw_filled_area(
                  x_start, 
                  y_start,
                  x_start + softkey_width, 
                  y_start + MMI_softkey_height - 1,
                  current_MMI_theme->softkey_bar_bkg_filler);
    }

    if(truncated)
    {
        gui_print_truncated_borderd_text(
            offset_x+1,
            offset_y+1,
            truncated_w, 
            string_text);
    }
    else
    {
#ifdef __MMI_BIDI_ALG__
        if(r2lMMIFlag)
        {
            gui_move_text_cursor(x2 + offset_down, y1 + offset_down);
        }
        else
#endif            
        {
            gui_move_text_cursor(x1 + offset_down, y1 + offset_down);
        }

        gui_print_bordered_text(string_text);
    }

    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();   
    gdi_layer_blt_previous(x_start, y_start, x_start + softkey_width, y_start + MMI_softkey_height - 1);    

}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_LSK_down
 * DESCRIPTION
 *  Draw LSK as down on main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_LSK_down(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    S32 diffx, diffy;
    #endif /*MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT*/

    #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    U16 lsk_text_id = STR_GLOBAL_OPTIONS;    
    #endif    
    PU8 draw_img = fmrdo_main_draw.LSK.down_img;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
#ifdef __FM_RADIO_HW_SEARCH__
    if(g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
    {
        return;
    }
#endif

#if defined(__MMI_FM_RADIO_RECORD__)
    if (g_fmrdo.state == FMRDO_STATE_RECORD)
    {    
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        lsk_text_id = STR_GLOBAL_PAUSE;
    #else
        draw_img = fmrdo_main_draw.LSK_pause_img_down;
    #endif
    }
    else if(g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        lsk_text_id = STR_GLOBAL_RESUME;
    #else
        draw_img = fmrdo_main_draw.LSK_resume_img_down;
    #endif
    }
#endif /* defined(__MMI_FM_RADIO_RECORD__) */
#else /* #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    if (g_fmrdo.state == FMRDO_STATE_RECORD ||
    #ifdef __FM_RADIO_HW_SEARCH__
        g_fmrdo.state == FMRDO_STATE_SEARCH_ONE ||
    #endif 
    #if defined(__MMI_FM_RADIO_RECORD__)
        (animate_count != 0) ||
    #endif
        g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
        return;
    }
#endif /* #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
	g_fmrdo.selected_button = FMRDO_BUTTON_LSK;
    g_fmrdo.is_button_down = MMI_TRUE;

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_fmrdo_redraw_main_softkey_for_bt_box(MMI_TRUE, MMI_TRUE, lsk_text_id);
    return;
#endif
    
    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);

    x1 = fmrdo_main_draw.LSK.x;
    y1 = fmrdo_main_draw.LSK.y;
    x2 = x1 + fmrdo_main_draw.LSK.w;
    y2 = y1 + fmrdo_main_draw.LSK.h;

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
     if (is_fmrdo_skin_layer_drawn)
     {
        diffx = fmrdo_main_draw.highlight_img.w - fmrdo_main_draw.LSK.w;
        diffy = fmrdo_main_draw.highlight_img.h - fmrdo_main_draw.LSK.h;
        x1 -= (diffx / 2);
        y1 -= (diffy / 2);
        x2 += ((1 + diffx) / 2);
        y2 += ((1 + diffy) / 2);
     }
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    /* button */
    if (is_fmrdo_skin_layer_drawn)
    {
        gdi_layer_push_and_set_active(fmrdo_skin_layer);
        gdi_layer_push_and_set_clip(fmrdo_main_draw.LSK.x, fmrdo_main_draw.LSK.y, fmrdo_main_draw.LSK.x+fmrdo_main_draw.LSK.w, fmrdo_main_draw.LSK.y+fmrdo_main_draw.LSK.h);

        gui_draw_filled_area(
					0, 
					UI_device_height - MMI_softkey_height,
					UI_device_width - 1,
					UI_device_height - 1,
					current_MMI_theme->softkey_bar_bkg_filler);

        gui_show_image(fmrdo_main_draw.LSK.x, fmrdo_main_draw.LSK.y, draw_img);
        gdi_layer_pop_clip();
        gdi_layer_pop_and_restore_active();

        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gui_show_image(x1, y1, draw_img);
    }
#else /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    /* button */
    gui_show_image(x1, y1, fmrdo_main_draw.highlight_img.up_img);
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    gdi_layer_pop_clip();
    
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2); 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_RSK_down
 * DESCRIPTION
 *  Draw RSK as down on main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_RSK_down(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    S32 diffx, diffy;
    #endif /*MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT*/
    #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    U16 rsk_text_id = STR_GLOBAL_BACK;   
    #endif   
    PU8 draw_img = fmrdo_main_draw.RSK.down_img;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
#ifdef __FM_RADIO_HW_SEARCH__
        if(g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
    {
        return;
    }
#endif

#if defined(__MMI_FM_RADIO_RECORD__)
    if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        rsk_text_id = STR_GLOBAL_STOP;
    #else
        draw_img = fmrdo_main_draw.RSK_stop_img_down;
    #endif
    }
#endif /* defined(__MMI_FM_RADIO_RECORD__) */
#else /* #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    if (g_fmrdo.state == FMRDO_STATE_RECORD ||
    #ifdef __FM_RADIO_HW_SEARCH__
        g_fmrdo.state == FMRDO_STATE_SEARCH_ONE ||
    #endif 
    #if defined(__MMI_FM_RADIO_RECORD__)
        (animate_count != 0) ||
    #endif
        g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
        return;
    }
#endif /* #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
	g_fmrdo.selected_button = FMRDO_BUTTON_RSK;
    g_fmrdo.is_button_down = TRUE;

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_fmrdo_redraw_main_softkey_for_bt_box(MMI_FALSE, MMI_TRUE, rsk_text_id);
    return;
#endif

    
    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);

    x1 = fmrdo_main_draw.RSK.x;
    y1 = fmrdo_main_draw.RSK.y;
    x2 = x1 + fmrdo_main_draw.RSK.w;
    y2 = y1 + fmrdo_main_draw.RSK.h;

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
     if (is_fmrdo_skin_layer_drawn)
     {
        diffx = fmrdo_main_draw.highlight_img.w - fmrdo_main_draw.RSK.w;
        diffy = fmrdo_main_draw.highlight_img.h - fmrdo_main_draw.RSK.h;
        x1 -= (diffx / 2);
        y1 -= (diffy / 2);
        x2 += ((1 + diffx) / 2);
        y2 += ((1 + diffy) / 2);
     }
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    /* button */
    if (is_fmrdo_skin_layer_drawn)
    {
        gdi_layer_push_and_set_active(fmrdo_skin_layer);
        gdi_layer_push_and_set_clip(fmrdo_main_draw.RSK.x, fmrdo_main_draw.RSK.y, fmrdo_main_draw.RSK.x+fmrdo_main_draw.RSK.w, fmrdo_main_draw.RSK.y+fmrdo_main_draw.RSK.h);


        gui_draw_filled_area(
						0, 
						UI_device_height - MMI_softkey_height,
						UI_device_width - 1,
						UI_device_height - 1,
						current_MMI_theme->softkey_bar_bkg_filler);

        gui_show_image(fmrdo_main_draw.RSK.x, fmrdo_main_draw.RSK.y, draw_img);
        gdi_layer_pop_clip();
        gdi_layer_pop_and_restore_active();

        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gui_show_image(x1, y1, draw_img);
    }
#else /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    /* button */
    gui_show_image(x1, y1, fmrdo_main_draw.highlight_img.up_img);
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

    gdi_layer_pop_clip();
    
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_LSK_up
 * DESCRIPTION
 *  Redraw LSK as UP on main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_LSK_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 diffx, diffy;
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    U16 lsk_text_id = STR_GLOBAL_OPTIONS;
#endif
    PU8 draw_img = fmrdo_main_draw.LSK.up_img;
    MMI_BOOL need_disable = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
#ifdef __FM_RADIO_HW_SEARCH__
    if (g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
    {
		need_disable = MMI_TRUE;
    }
#endif 
    
#if defined(__MMI_FM_RADIO_RECORD__)
    if (g_fmrdo.state == FMRDO_STATE_RECORD)
    {
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        lsk_text_id = STR_GLOBAL_PAUSE;
    #else
        draw_img = fmrdo_main_draw.LSK_pause_img_up;
    #endif
    }
    else if(g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        lsk_text_id = STR_GLOBAL_RESUME;
    #else
        draw_img = fmrdo_main_draw.LSK_resume_img_up;
    #endif
    }
#endif /* defined(__MMI_FM_RADIO_RECORD__) */
#else /* #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    if (g_fmrdo.state == FMRDO_STATE_RECORD ||
    #ifdef __FM_RADIO_HW_SEARCH__
        g_fmrdo.state == FMRDO_STATE_SEARCH_ONE ||
    #endif 
    #if defined(__MMI_FM_RADIO_RECORD__)
        (animate_count != 0) ||
    #endif
        g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
		need_disable = MMI_TRUE;
    }
#endif /* #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
	if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_LSK)
	{
        g_fmrdo.is_button_down = MMI_FALSE;
    }

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_fmrdo_redraw_main_softkey_for_bt_box(MMI_TRUE, MMI_FALSE, lsk_text_id);
    return;
#endif

    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);

    x1 = fmrdo_main_draw.LSK.x;
    y1 = fmrdo_main_draw.LSK.y;
    x2 = x1 + fmrdo_main_draw.LSK.w;
    y2 = y1 + fmrdo_main_draw.LSK.h;
    if (is_fmrdo_skin_layer_drawn)
    {
        diffx = fmrdo_main_draw.highlight_img.w - fmrdo_main_draw.LSK.w;
        diffy = fmrdo_main_draw.highlight_img.h - fmrdo_main_draw.LSK.h;
        x1 -= (diffx / 2);
        y1 -= (diffy / 2);
        x2 += ((1 + diffx) / 2);
        y2 += ((1 + diffy) / 2);
    }

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    /* button */
    if (is_fmrdo_skin_layer_drawn)
    {
        gdi_layer_push_and_set_active(fmrdo_skin_layer);
	    gdi_layer_push_and_set_clip(fmrdo_main_draw.LSK.x, fmrdo_main_draw.LSK.y, fmrdo_main_draw.LSK.x+fmrdo_main_draw.LSK.w, fmrdo_main_draw.LSK.y+fmrdo_main_draw.LSK.h);
		gui_draw_filled_area(
					  0, 
					  UI_device_height - MMI_softkey_height,
					  UI_device_width - 1,
					  UI_device_height - 1,
					  current_MMI_theme->softkey_bar_bkg_filler);

		if(need_disable)
		{
			gui_draw_image_with_alpha_transparent(
								   draw_img,
								  x1,
							   	  y1,
							   	  125);
		}
		else
		{
            gui_show_image(fmrdo_main_draw.LSK.x, fmrdo_main_draw.LSK.y, draw_img);
		}
        gdi_layer_pop_clip();
        gdi_layer_pop_and_restore_active();

        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gui_show_image(x1, y1, draw_img);
    }

    gdi_layer_pop_clip();
    
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_RSK_up
 * DESCRIPTION
 *  Redraw RSK as Up on main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_RSK_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 diffx, diffy;
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    U16 rsk_text_id = STR_GLOBAL_BACK;
#endif
    PU8 draw_img = fmrdo_main_draw.RSK.up_img;
	MMI_BOOL need_disable = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
#ifdef __FM_RADIO_HW_SEARCH__
    if (g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
    {
        need_disable = MMI_TRUE;
    }
#endif 

#if defined(__MMI_FM_RADIO_RECORD__)
    if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        rsk_text_id = STR_GLOBAL_STOP;
    #else
        draw_img = fmrdo_main_draw.RSK_stop_img_up;
    #endif
    }
#endif /* defined(__MMI_FM_RADIO_RECORD__) */
#else /* #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    if (g_fmrdo.state == FMRDO_STATE_RECORD ||
    #ifdef __FM_RADIO_HW_SEARCH__
        g_fmrdo.state == FMRDO_STATE_SEARCH_ONE ||
    #endif 
    #if defined(__MMI_FM_RADIO_RECORD__)
        (animate_count != 0) ||
    #endif
        g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
		need_disable = MMI_TRUE;
    }
#endif /* #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
   	if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_RSK)
	{
        g_fmrdo.is_button_down = MMI_FALSE;
	}
    
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_fmrdo_redraw_main_softkey_for_bt_box(MMI_FALSE, MMI_FALSE, rsk_text_id);
    return;
#endif


    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);

    x1 = fmrdo_main_draw.RSK.x;
    y1 = fmrdo_main_draw.RSK.y;
    x2 = x1 + fmrdo_main_draw.LSK.w;
    y2 = y1 + fmrdo_main_draw.LSK.h;
    if (is_fmrdo_skin_layer_drawn)
    {
        diffx = fmrdo_main_draw.highlight_img.w - fmrdo_main_draw.RSK.w;
        diffy = fmrdo_main_draw.highlight_img.h - fmrdo_main_draw.RSK.h;
        x1 -= (diffx / 2);
        y1 -= (diffy / 2);
        x2 += ((1 + diffx) / 2);
        y2 += ((1 + diffy) / 2);
    }

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    /* button */
    if (is_fmrdo_skin_layer_drawn)
    {
        gdi_layer_push_and_set_active(fmrdo_skin_layer);
	  gdi_layer_push_and_set_clip(fmrdo_main_draw.RSK.x, fmrdo_main_draw.RSK.y, fmrdo_main_draw.RSK.x+fmrdo_main_draw.RSK.w, fmrdo_main_draw.RSK.y+fmrdo_main_draw.RSK.h);

        gui_draw_filled_area(
					  0, 
					  UI_device_height - MMI_softkey_height,
					  UI_device_width - 1,
					  UI_device_height - 1,
					  current_MMI_theme->softkey_bar_bkg_filler);
	if(need_disable)
	{
	gui_draw_image_with_alpha_transparent(
						draw_img,
							  x1,
						   	  y1,
						   	  125);
	}
	else
	{
        gui_show_image(fmrdo_main_draw.RSK.x, fmrdo_main_draw.RSK.y, draw_img);
	}
        gdi_layer_pop_clip();
        gdi_layer_pop_and_restore_active();

        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gui_show_image(x1, y1, draw_img);
    }

    gdi_layer_pop_clip();
    
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2); 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scroll_channel_name_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scroll_channel_name_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
    gui_handle_scrolling_text(&fmrdo_main_draw.channel_name_scroll);
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_background
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_anim_blt_after_callback
 * DESCRIPTION
 *  redraw freq after animation draw, so alpha blending result is right
 * PARAMETERS
 *  result      [IN]        Animation draw result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_anim_blt_after_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_anim_blt_before_callback
 * DESCRIPTION
 *  redraw freq after animation draw, so alpha blending result is right
 * PARAMETERS
 *  result      [IN]        Animation draw result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_anim_blt_before_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < GDI_SUCCEED || g_fmrdo.in_main_screen != TRUE)
    {
        return;
    }

    mmi_fmrdo_set_alpha_blending_layer(TRUE);
    gdi_layer_push_and_set_active(fmrdo_osd_layer);

    if (g_fmrdo.normal_repeat_step_count != 0)
    {
        freq = g_fmrdo.step_freq;
    }
    else
    {
        freq = g_fmrdo.frequency;
    }
#ifdef __FM_RADIO_HW_SEARCH__
    if(g_fmrdo.state==FMRDO_STATE_SEARCH_ONE)
    {
        mmi_fmrdo_redraw_main_twinkle_searching(TRUE);
    }
    else
#endif/*__FM_RADIO_HW_SEARCH__*/
    mmi_fmrdo_redraw_main_frequency(freq, TRUE);
#ifdef __MMI_FM_RADIO_RDS__
    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_TP);
    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_AF);
#endif/*__MMI_FM_RADIO_RDS__*/
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO_ANIMATION__
    S32 width;
    S32 height;
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 
    BOOL is_record_allow = mmi_fmrdo_is_record_allowed();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!g_fmrdo.in_main_screen)
	{	
		return;
	}
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_and_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

    if (!is_fmrdo_skin_layer_drawn)
    {
        gdi_layer_push_and_set_active(fmrdo_skin_layer);
        /* main background */

     	gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->sub_menu_bkg_filler);
		gui_draw_filled_area(
				0, 
				UI_device_height - MMI_softkey_height,
				UI_device_width - 1,
				UI_device_height - 1,
				current_MMI_theme->softkey_bar_bkg_filler);
	#if defined(MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT) && defined(__MMI_FTE_SUPPORT_SLIM__)
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        gdi_image_draw_resized(fmrdo_main_draw.line_img_x, fmrdo_main_draw.line_img_y, fmrdo_main_draw.line_img_w, fmrdo_main_draw.line_img_h ,fmrdo_main_draw.line_img);
    #else
        gui_show_image(fmrdo_main_draw.line_img_x, fmrdo_main_draw.line_img_y, fmrdo_main_draw.line_img);
    #endif
	#elif defined(__MMI_FTE_SUPPORT_SLIM__)
		gdi_image_draw(FMRDO_SKIN_LINE_X, FMRDO_SKIN_LINE_Y, fmrdo_main_draw.bg_line);
	#endif
        mmi_fmrdo_redraw_main_LSK_up();
        mmi_fmrdo_redraw_main_RSK_up();
        mmi_fmrdo_redraw_main_push_button(
            FMRDO_BUTTON_STEP_DOWN,
            (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN)));
        mmi_fmrdo_redraw_main_push_button(
            FMRDO_BUTTON_STEP_UP,
            (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP)));
        mmi_fmrdo_redraw_main_push_button(
            FMRDO_BUTTON_MEMO_UP,
            (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_MEMO_DOWN)));
        mmi_fmrdo_redraw_main_push_button(
            FMRDO_BUTTON_MEMO_DOWN,
            (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_MEMO_UP)));
        mmi_fmrdo_redraw_main_toggle_button(
            FMRDO_BUTTON_POWER,
            (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_POWER)),
            g_fmrdo.is_power_on,
            TRUE);
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT 
        mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_REC, FALSE, is_record_allow, TRUE);
    #else
        mmi_fmrdo_redraw_main_volume_key();
    #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */    
    #ifdef __MMI_FM_RADIO_ANIMATION__
        mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, TRUE);
    #ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
        if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
    #endif /*__RF_DESENSE_TEST__*/
        {
        gdi_layer_push_and_set_active(fmrdo_anim_layer);
        fmrdo_main_draw.animation.img_handle = GDI_ERROR_HANDLE;
        if (g_fmrdo.is_power_on)
        {
            gdi_anim_set_draw_before_callback(mmi_fmrdo_anim_blt_before_callback);
            gdi_anim_set_draw_after_callback(mmi_fmrdo_anim_blt_after_callback);
            gdi_image_draw_animation(
                0,
                0,
                fmrdo_main_draw.animation.animation_img,
                &fmrdo_main_draw.animation.img_handle);
            /* gdi will not blt first frame, so we need blt it self */
            gdi_image_get_dimension(fmrdo_main_draw.animation.animation_img, &width, &height);
            gdi_layer_blt_previous(
                fmrdo_main_draw.animation.x,
                fmrdo_main_draw.animation.y,
                fmrdo_main_draw.animation.x + width,
                fmrdo_main_draw.animation.y + height);
        }
        else
        {
            gdi_image_draw(
                fmrdo_main_draw.animation.x,
                fmrdo_main_draw.animation.y,
                fmrdo_main_draw.animation.animation_img);
        }
        gdi_layer_pop_and_restore_active();
        }
    #endif /* __MMI_FM_RADIO_ANIMATION__ */
    
        /* tuner scale background */
        is_fmrdo_skin_layer_drawn = TRUE;
        gdi_layer_pop_and_restore_active();
    }

    gdi_layer_pop_clip();

#if (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)|| defined(__MMI_MAINLCD_320X240__))
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_set_alpha_blend_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        fmrdo_skin_layer);
    wgui_status_icon_bar_update();
#endif /* (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) */ 
    /* draw components */
    mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, TRUE);
#ifdef __MMI_FM_RADIO_RDS__
    mmi_fmrdo_rds_redraw_main_text();
    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_TP);
    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_AF);
#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
	if (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") == 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") == 0)
#endif
	{
		mmi_fmrdo_redraw_main_channel_name(0);
	}
#else
	mmi_fmrdo_redraw_main_channel_name(0);
#endif/*__MMI_FM_RADIO_RDS__*/
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}
#ifndef __FTE_NON_SLIM_RES__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_draw_simple_text
 * DESCRIPTION
 *  draw simple text
 * PARAMETERS
 *  button      [IN]        
 *  is_down     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fmrdo_util_draw_simple_text(const fmrdo_main_rect_struct *rect, U16* txt_p, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_x, str_y, str_w, str_h;
    S32 x1 = rect->x;
    S32 y1 = rect->y;
    S32 x2 = rect->x + rect->w - 1;
    S32 y2 = rect->y + rect->h - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == rect)
    {
        return;
    }
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    mmi_fmrdo_redraw_main_background(x1, y1, x2, y2);
    gdi_layer_pop_clip();
    
    if (NULL == txt_p)
    {
        return;
    }

    gui_measure_string(txt_p, &str_w, &str_h);
    if (FMRDO_FLAG_CHECK(flags, MMI_FMRDO_TEXT_HAS_BORDER))
    {
        str_w += 4;
        str_h += 2;
    }

    /* get coordinate-x */
    if (FMRDO_FLAG_CHECK(flags, MMI_FMRDO_TEXT_HORZ_ALEFT))
    {
        str_x = rect->x;
    }
    else if (FMRDO_FLAG_CHECK(flags, MMI_FMRDO_TEXT_HORZ_ARIGHT))
    {
        str_x = rect->x + rect->w - str_w - 1;
    }
    else
    {
        str_x = rect->x + ((rect->w - str_w) >> 1);
    }
    if (mmi_fe_get_r2l_state())
    {
        str_x += str_w;
        if (FMRDO_FLAG_CHECK(flags, MMI_FMRDO_TEXT_HAS_BORDER))
        {
            str_x -= 2;
        }
    }
    /* get coordinate-y */
    if (FMRDO_FLAG_CHECK(flags, MMI_FMDRO_TEXT_VERT_ATOP))
    {
        str_y = rect->y;
    }
    else if (FMRDO_FLAG_CHECK(flags, MMI_FMRDO_TEXT_VERT_ABOTTOM))
    {
        str_y = rect->y + rect->h - str_h - 1;
    }
    else
    {
        str_y = rect->y + ((rect->h - str_h) >> 1);
    }

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    gui_move_text_cursor(str_x, str_y);
    if (FMRDO_FLAG_CHECK(flags, MMI_FMRDO_TEXT_HAS_BORDER))
    {
        gui_print_bordered_text(txt_p);
    }
    else
    {
        gui_print_text(txt_p);
    }
    gdi_layer_pop_clip();
}
#endif 

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_frequency
 * DESCRIPTION
 *  Redraw frequency on main screen
 * PARAMETERS
 *  freq            [IN]        
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_frequency(U16 freq, BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FM_RADIO_ANIMATION__
    S32 x1, y1, x2, y2;
    S32 w, h;
#ifdef __MMI_MAINLCD_320X240__
    S32 mhz_x1, mhz_y1, mhz_x2, mhz_y2;
#endif 
#endif /* __MMI_FM_RADIO_ANIMATION__ */

#ifndef __FTE_NON_SLIM_RES__
    UI_character_type freq_str[7];
	UI_character_type temp[2];
	S32 str_w, str_h;
	UI_character_type freq_Mhz_str[4];
	S32 str_mhz_w, str_mhz_h;
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    stFontAttribute     Frequency_font = {1,0,0,DIALER_FONT,255,0};
    stFontAttribute     MHz_font = {1,0,0,MEDIUM_FONT,255,0 };
#else
    stFontAttribute     Frequency_font = {1,0,0,DIALER_FONT,255,0};
    stFontAttribute     MHz_font = {1,0,0,SMALL_FONT,255,0 };
#endif
	S32 flags = 0;
	fmrdo_main_rect_struct rect;
	const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[0];
	color text_color = gui_color(255, 255, 255);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO_ANIMATION__
    /* Need to blend animatiton with frequency so redraw both */
    if (!g_fmrdo.is_power_on)
    {
        mmi_fmrdo_animation_stop();
    }
    else
    {
        mmi_fmrdo_redraw_record_frequency(freq, (MMI_BOOL)is_shown);
    }
#else
    if (g_vol_displayed
#if defined(__MMI_FM_RADIO_RECORD__)
        || animate_count
#endif 
        )
    {
        return;
    }
#ifdef __FTE_NON_SLIM_RES__
    x1 = fmrdo_main_draw.freq_h_offset_x;
    y1 = fmrdo_main_draw.frequency_y;
    gui_measure_image(fmrdo_main_draw.freq_mhz, &w, &h);
    x2 = fmrdo_main_draw.freq_mhz_offset_x + w;
    y2 = y1 + fmrdo_main_draw.frequency_h;
    

    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#endif
#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
#ifdef __MMI_MAINLCD_320X240__
    mhz_x1 = fmrdo_main_draw.freq_mhz_offset_x;
    mhz_y1 = fmrdo_main_draw.freq_mhz_offset_y;
    mhz_x2 = mhz_x1 + w - 1;
    mhz_y2 = mhz_y1 + h - 1;
    gdi_layer_push_and_set_clip(
        mhz_x1,
        mhz_y1,
        mhz_x2,
        mhz_y2);
    gdi_bitblt_resized(
        fmrdo_skin_layer, 
        mhz_x1,
        mhz_y1,
        mhz_x2,
        mhz_y2,
        mhz_x1,
        mhz_y1,
        mhz_x2,
        mhz_y2);
    gdi_layer_pop_clip();
#endif 
#endif

    if (is_shown)
    {
   #ifndef __FTE_NON_SLIM_RES__
			gui_set_font(&Frequency_font);
			gui_set_text_color(text_color);
		    if ((freq / 1000) > 0)
			{
				mmi_ucs2ncpy((CHAR*)freq_str, (const CHAR *)gui_itoa((S32) (freq / 1000), (U16*) temp, 10), 1 );
				freq = freq % 1000;
				mmi_ucs2ncat((CHAR*)freq_str, (const CHAR *)gui_itoa((S32) (freq / 100), (U16*) temp, 10), 1 );
				freq = freq % 100;
			}
			else
			{
				mmi_ucs2ncpy((CHAR*)freq_str, (const CHAR *)gui_itoa((S32) (freq / 100), (U16*) temp, 10), 1 );
				freq = freq % 100;
			}
			mmi_ucs2ncat((CHAR*)freq_str, (const CHAR *)gui_itoa((S32) (freq / 10), (U16*) temp, 10), 1 );
			mmi_ucs2ncat((CHAR*)freq_str, (const CHAR *)L".", 1 );
			mmi_ucs2ncat((CHAR*)freq_str, (const CHAR *)gui_itoa((S32) (freq % 10), (U16*) temp, 10), 1 );
			gui_measure_string(freq_str, &str_w, &str_h);
			x1 = fmrdo_main_draw.freq_h_offset_x;
    		y1 = fmrdo_main_draw.frequency_y;
   			x2 = x1 + skin_p->frequency_w - 1 ;
		    y2 = y1 + skin_p->frequency_h - 1;
			gdi_layer_lock_frame_buffer();
    		mmi_fmrdo_set_alpha_blending_layer(TRUE);
    		gdi_layer_push_and_set_clip(x1, y1, x2, y2);
			gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
			rect.x = x1;
			rect.y = y1;
			rect.w = skin_p->frequency_w;
			rect.h = skin_p->frequency_h;
			mmi_fmrdo_util_draw_simple_text(&rect, freq_str, 
                FMRDO_FLAG_SET(flags, MMI_FMRDO_TEXT_HORZ_ARIGHT|MMI_FMRDO_TEXT_VERT_ACERTER));
	        gui_print_bordered_text(freq_str);
			gdi_layer_pop_clip();
    		mmi_fmrdo_set_alpha_blending_layer(FALSE);
    		gdi_layer_unlock_frame_buffer();
	    	gdi_layer_blt_previous(x1, y1, x2, y2);
			
			gdi_layer_lock_frame_buffer();
	    	mmi_fmrdo_set_alpha_blending_layer(TRUE);
			gui_set_font(&MHz_font);
			mmi_ucs2ncpy((CHAR*)freq_Mhz_str, (const CHAR *)L"MHz", 3 );
			gui_measure_string(freq_Mhz_str, &str_mhz_w, &str_mhz_h);
			x1 = fmrdo_main_draw.freq_mhz_offset_x;
    		y1 = fmrdo_main_draw.freq_mhz_offset_y + (str_h - str_mhz_h) - 1;
			x2 = fmrdo_main_draw.freq_mhz_offset_x + str_mhz_w - 1;
   			y2 = y1 + str_mhz_h;
    		gdi_layer_push_and_set_clip(x1, y1, x2, y2);
		    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
			rect.x = x1;
			rect.y = y1;
			rect.w = str_mhz_w;
			rect.h = str_mhz_h;
			mmi_fmrdo_util_draw_simple_text(&rect, freq_Mhz_str, 
                FMRDO_FLAG_SET(flags, MMI_FMRDO_TEXT_HORZ_ARIGHT|MMI_FMRDO_TEXT_VERT_ABOTTOM));
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            gui_print_text(freq_Mhz_str);
        #else
	        gui_print_bordered_text(freq_Mhz_str);
        #endif
			gdi_layer_pop_clip();
    		mmi_fmrdo_set_alpha_blending_layer(FALSE);
    		gdi_layer_unlock_frame_buffer();
    		gdi_layer_blt_previous(x1, y1, x2, y2);
	#else
        if ((freq / 1000) > 0)
        {
            gui_show_image(
                fmrdo_main_draw.freq_h_offset_x,
                y1,
                (PU8) GetImage((U16) (fmrdo_main_draw.freq_base_num_id + (freq / 1000))));
            freq = freq % 1000;
        }
        gui_show_image(
            fmrdo_main_draw.freq_ten_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.freq_base_num_id + (freq / 100))));
        freq = freq % 100;
        gui_show_image(
            fmrdo_main_draw.freq_one_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.freq_base_num_id + (freq / 10))));
        gui_show_image(
            fmrdo_main_draw.freq_dot_offset_x,
            fmrdo_main_draw.freq_dot_offset_y,
            fmrdo_main_draw.freq_dot);
        gui_show_image(
            fmrdo_main_draw.freq_dec_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.freq_base_num_id + (freq % 10))));
#ifdef __MMI_MAINLCD_320X240__
        gdi_layer_push_and_set_clip(
            mhz_x1,
            mhz_y1,
            mhz_x2,
            mhz_y2);
        gdi_push_and_set_alpha_blending_source_layer(fmrdo_osd_layer);
        gui_show_image(
            fmrdo_main_draw.freq_mhz_offset_x,
            fmrdo_main_draw.freq_mhz_offset_y,
            fmrdo_main_draw.freq_mhz);
        gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_clip();
#else /*__MMI_MAINLCD_320X240__*/
        gui_show_image(
            fmrdo_main_draw.freq_mhz_offset_x,
            fmrdo_main_draw.freq_mhz_offset_y,
            fmrdo_main_draw.freq_mhz);
#endif /*__MMI_MAINLCD_320X240__*/
#endif /*__MMI_FM_PLUTO_SLIM__*/
    }
	#ifdef __FTE_NON_SLIM_RES__
    gdi_layer_pop_clip();
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);
	#endif

#endif /* __MMI_FM_RADIO_ANIMATION__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_record_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_record_frequency(U16 freq, MMI_BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 w, h;
    #ifdef __MMI_MAINLCD_320X240__
		S32 mhz_x1, mhz_y1, mhz_x2, mhz_y2;
	#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = fmrdo_main_draw.freq_h_offset_x;
    y1 = fmrdo_main_draw.frequency_y;
    gui_measure_image(fmrdo_main_draw.freq_mhz, &w, &h);
    x2 = fmrdo_main_draw.freq_mhz_offset_x + w;
    y2 = y1 + fmrdo_main_draw.frequency_h;

    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);

    gdi_layer_push_and_set_active(fmrdo_skin_layer);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    
    gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->sub_menu_bkg_filler);

#ifdef __MMI_MAINLCD_320X240__
    mhz_x1 = fmrdo_main_draw.freq_mhz_offset_x;
    mhz_y1 = fmrdo_main_draw.freq_mhz_offset_y;
    mhz_x2 = mhz_x1 + w - 1;
    mhz_y2 = mhz_y1 + h - 1;
    gdi_layer_push_and_set_clip(
        mhz_x1,
        mhz_y1,
        mhz_x2,
        mhz_y2);
	gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->sub_menu_bkg_filler);

    gdi_bitblt_resized(
        fmrdo_skin_layer, 
        mhz_x1,
        mhz_y1,
        mhz_x2,
        mhz_y2,
        mhz_x1,
        mhz_y1,
        mhz_x2,
        mhz_y2);
    gdi_layer_pop_clip();
#endif 

    if (is_shown)
    {
        if ((freq / 1000) > 0)
        {
            gui_show_image(
                fmrdo_main_draw.freq_h_offset_x,
                y1,
                (PU8) GetImage((U16) (fmrdo_main_draw.freq_base_num_id + (freq / 1000))));
            freq = freq % 1000;
        }
        gui_show_image(
            fmrdo_main_draw.freq_ten_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.freq_base_num_id + (freq / 100))));
        freq = freq % 100;
        gui_show_image(
            fmrdo_main_draw.freq_one_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.freq_base_num_id + (freq / 10))));
        gui_show_image(
            fmrdo_main_draw.freq_dot_offset_x,
            fmrdo_main_draw.freq_dot_offset_y,
            fmrdo_main_draw.freq_dot);
        gui_show_image(
            fmrdo_main_draw.freq_dec_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.freq_base_num_id + (freq % 10))));
#ifdef __MMI_MAINLCD_320X240__
        gdi_layer_push_and_set_clip(
            mhz_x1,
            mhz_y1,
            mhz_x2,
            mhz_y2);
        //gdi_push_and_set_alpha_blending_source_layer(fmrdo_osd_layer);
        gui_show_image(
            fmrdo_main_draw.freq_mhz_offset_x,
            fmrdo_main_draw.freq_mhz_offset_y,
            fmrdo_main_draw.freq_mhz);
        //gdi_pop_and_restore_alpha_blending_source_layer();
        gdi_layer_pop_clip();
#else 
        gui_show_image(
            fmrdo_main_draw.freq_mhz_offset_x,
            fmrdo_main_draw.freq_mhz_offset_y,
            fmrdo_main_draw.freq_mhz);
#endif 
    }

    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2); 
}

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_reset_volume_bar
 * DESCRIPTION
 *  Clear volume bar
 * PARAMETERS
 *  freq            [IN]        
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_reset_volume_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_VOLUME)
    {
        StartTimer(FMRDO_VOLUME_DISPLAY_TMER, 2000, mmi_fmrdo_reset_volume_bar);
        return;
    }
    StopTimer(FMRDO_VOLUME_DISPLAY_TMER);
    g_vol_displayed = 0;
    g_vol_highlight = 0;
    if (g_fmrdo.in_main_screen)
    {
        gdi_layer_lock_frame_buffer();
        
        mmi_fmrdo_redraw_main_volumebar(g_fmrdo.volume, MMI_FALSE);
        mmi_fmrdo_redraw_record_frequency(g_fmrdo.frequency, MMI_FALSE);
        mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_TRUE);
        mmi_fmrdo_redraw_main_channel_name(0);

        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT);
    }
}
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

#ifdef __MMI_FM_RADIO_ANIMATION__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_animation_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_fmrdo_get_animation_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
    if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
#endif /*__RF_DESENSE_TEST__*/
    {
        return GDI_ERROR_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_animation_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_animation_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width;
    S32 height;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
    if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
#endif /*__RF_DESENSE_TEST__*/
    {
        mmi_fmrdo_set_alpha_blending_layer(TRUE);
        gdi_layer_push_and_set_active(fmrdo_anim_layer);

        /* animation */
    #ifdef __MMI_FM_RADIO_ANIMATION__
    #ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
        if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
    #endif /*__RF_DESENSE_TEST__*/
    {
        fmrdo_main_draw.animation.img_handle = GDI_ERROR_HANDLE;
        gdi_image_get_dimension(fmrdo_main_draw.animation.animation_img, &width, &height);

        gdi_anim_set_draw_before_callback(mmi_fmrdo_anim_blt_before_callback);
        gdi_anim_set_draw_after_callback(mmi_fmrdo_anim_blt_after_callback);
        gdi_image_draw_animation(
            0,
            0,
            fmrdo_main_draw.animation.animation_img,
            &fmrdo_main_draw.animation.img_handle);
        /* gdi will not blt first frame, so we need blt it self */
             gdi_layer_blt_previous(
            g_fmrdo_skins[g_fmrdo.skin_index].animation_x,
            g_fmrdo_skins[g_fmrdo.skin_index].animation_y,
            g_fmrdo_skins[g_fmrdo.skin_index].animation_x + width,
            g_fmrdo_skins[g_fmrdo.skin_index].animation_y + height);
    }
    #endif /* __MMI_FM_RADIO_ANIMATION__ */ 

        gdi_layer_pop_and_restore_active();
        mmi_fmrdo_set_alpha_blending_layer(FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_animation_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_animation_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1;
    S32 y1;
    S32 x2, y2;
    S32 width, height;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop animation */

#ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
    if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
#endif /*__RF_DESENSE_TEST__*/
    {  
        gdi_image_stop_animation(fmrdo_main_draw.animation.img_handle);
        fmrdo_main_draw.animation.img_handle = GDI_ERROR_HANDLE;
        if (!fmrdo_skin_layer)
        {
            return;
        }

        gdi_layer_lock_frame_buffer();

        mmi_fmrdo_set_alpha_blending_layer(TRUE);
        if (g_fmrdo.normal_repeat_step_count != 0)
        {
            mmi_fmrdo_redraw_record_frequency(g_fmrdo.step_freq, MMI_TRUE);
        }
        else
        {
            mmi_fmrdo_redraw_record_frequency(g_fmrdo.frequency, MMI_TRUE);
        }
		#ifdef __MMI_FM_RADIO_RDS__
			mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
	    	mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_TP);
    		mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_AF);
		#endif
        gdi_image_get_dimension(fmrdo_main_draw.animation.animation_img, &width, &height);

        gdi_layer_push_and_set_active(fmrdo_anim_layer);
        x1 = 0;
        y1 = 0;
        x2 = x1 + width;
        y2 = y1 + height;
        gdi_layer_push_and_set_clip(x1, y1, x2, y2);
        gdi_image_draw(
                    0,
                    0,
                    fmrdo_main_draw.animation.animation_img);
        gdi_layer_pop_clip();

        gdi_layer_pop_and_restore_active();
        mmi_fmrdo_set_alpha_blending_layer(FALSE);
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(x1, y1 + fmrdo_main_draw.animation.y, x2, y2 + fmrdo_main_draw.animation.y);
    }
}
#endif 

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_volumebar
 * DESCRIPTION
 *  Redraw frequency on main screen
 * PARAMETERS
 *  freq            [IN]        
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_volumebar(U8 volume, MMI_BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 delta, end_gap;
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* sometimes distortion happens in the displayed frequency, hence draw the frequency again */
    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_TRUE);
    x1 = fmrdo_main_draw.volume.x;
    y1 = fmrdo_main_draw.volume.y;
    x2 = x1 + fmrdo_main_draw.volume.w;
    y2 = y1 + fmrdo_main_draw.volume.h;

#ifdef __MMI_FTE_SUPPORT_SLIM__
    w = FMRDO_VOLUME_TUNE_W;
    h = FMRDO_VOLUME_TUNE_H;
#else
    gui_measure_image(fmrdo_main_draw.vol_tune_img, &w, &h); 
#endif /* __MMI_FTE_SUPPORT_SLIM__ */ 

    mmi_fmrdo_set_alpha_blending_layer(TRUE);

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    if (!is_shown)
    {
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        StartTimer(FMRDO_VOLUME_DISPLAY_TMER, 2000, mmi_fmrdo_reset_volume_bar);
    #ifdef __MMI_FTE_SUPPORT_SLIM__
        gdi_image_draw_resized(x1, y1, FMRDO_VOLUME_BG_W, FMRDO_VOLUME_BG_H ,fmrdo_main_draw.volume.bg_img);
    #else
        gui_show_image(x1, y1, fmrdo_main_draw.volume.bg_img);
    #endif /* __MMI_FTE_SUPPORT_SLIM__ */

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        mmi_fmrdo_redraw_bar_toggle_button(FMRDO_BUTTON_VOLUME, MMI_FALSE, !g_fmrdo.mute, MMI_TRUE);
#endif

    #ifndef __MMI_FTE_SUPPORT_SLIM__
        gui_show_image(
            x1 + fmrdo_main_draw.volume.ind_left_gap,
            y1 + fmrdo_main_draw.volume.ind_top_gap,
            fmrdo_main_draw.vol_empty_img);
    #endif /* __MMI_FTE_SUPPORT_SLIM__ */
        if (!g_fmrdo.mute)
        {
            gdi_layer_push_clip();
            if (fmrdo_main_draw.volume.type == 0)   /* 0: horizontal, 1: vertical */
            {
                end_gap = x2 - w - fmrdo_main_draw.volume.ind_left_gap;
                delta = ((U32)volume + 1) * (fmrdo_main_draw.volume.w - fmrdo_main_draw.volume.ind_left_gap - 
                    end_gap) / MAX_VOL_LEVEL;
                gdi_layer_set_clip(
                    x1 + fmrdo_main_draw.volume.ind_left_gap,
                    y1 + fmrdo_main_draw.volume.ind_top_gap,
                    x1 + fmrdo_main_draw.volume.ind_left_gap + delta - 1,
                    y1 + fmrdo_main_draw.volume.ind_top_gap + h);
                g_vol_ind_x = x1 + fmrdo_main_draw.volume.ind_left_gap + delta - (fmrdo_main_draw.volume.ind_w / 2);
                g_vol_ind_y = y1 + fmrdo_main_draw.volume.ind_top_gap + (h - fmrdo_main_draw.volume.ind_h) / 2;
            }
            else
            {
                end_gap = y2 - h - fmrdo_main_draw.volume.ind_top_gap;
                delta = ((U32)g_fmrdo.volume + 1) * (fmrdo_main_draw.volume.h - fmrdo_main_draw.volume.ind_top_gap -
                    end_gap) / MAX_VOL_LEVEL;
                gdi_layer_set_clip(
                    x1 + fmrdo_main_draw.volume.ind_left_gap,
                    y1 + fmrdo_main_draw.volume.ind_top_gap + h - delta,
                    x1 + fmrdo_main_draw.volume.ind_left_gap + w,
                    y1 + fmrdo_main_draw.volume.ind_top_gap + h);
                g_vol_ind_x = x1 + fmrdo_main_draw.volume.ind_left_gap + (w - fmrdo_main_draw.volume.ind_w) / 2;
                g_vol_ind_y = y1 + fmrdo_main_draw.volume.ind_top_gap + h - delta - (fmrdo_main_draw.volume.ind_h / 2);
            }
        #ifdef __MMI_FTE_SUPPORT_SLIM__
            gdi_image_draw_resized(
                x1 + fmrdo_main_draw.volume.ind_left_gap,
                y1 + fmrdo_main_draw.volume.ind_top_gap,
                w, h, fmrdo_main_draw.vol_tune_img);
        #else
            gui_show_image(
                x1 + fmrdo_main_draw.volume.ind_left_gap,
                y1 + fmrdo_main_draw.volume.ind_top_gap,
                fmrdo_main_draw.vol_tune_img);
        #endif
            gdi_layer_pop_clip();
        }
        else
        {
            if (fmrdo_main_draw.volume.type == 0)   /* 0: horizontal, 1: vertical */
            {
                g_vol_ind_x = x1 + fmrdo_main_draw.volume.ind_left_gap - (fmrdo_main_draw.volume.ind_w / 2);
                g_vol_ind_y = y1 + fmrdo_main_draw.volume.ind_top_gap + (h - fmrdo_main_draw.volume.ind_h) / 2;
            }
            else
            {
                g_vol_ind_x = x1 + fmrdo_main_draw.volume.ind_left_gap + (w - fmrdo_main_draw.volume.ind_w) / 2;
                g_vol_ind_y = y1 + fmrdo_main_draw.volume.ind_top_gap + h - (fmrdo_main_draw.volume.ind_h / 2);
            }
        }
        if (g_vol_highlight)
        {
            gui_show_image(
                g_vol_ind_x,
                g_vol_ind_y,
                fmrdo_main_draw.volume.ind_hl_img);
        }
        else
        {
            gui_show_image(
                g_vol_ind_x,
                g_vol_ind_y,
                fmrdo_main_draw.volume.ind_img);
        }
    }

    gdi_layer_pop_clip();
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);
}
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_volum_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button      [IN]        0 = volume_dec_button, 1 = volume_inc_button
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_volum_icon(U8 button)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hide_main_channel_name
 * DESCRIPTION
 *  Hide channel name on main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_hide_main_channel_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = fmrdo_main_draw.channel_name.x;
    S32 y1 = fmrdo_main_draw.channel_name.y;
    S32 x2 = fmrdo_main_draw.channel_name.x + fmrdo_main_draw.channel_name.w - 1;
    S32 y2 = fmrdo_main_draw.channel_name.y + fmrdo_main_draw.channel_name.h - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    
    /* stop scrolling if necessary */
    gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    
    gdi_layer_pop_clip();
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_channel_name
 * DESCRIPTION
 *  Redraw channel name on main screen
 * PARAMETERS
 *  other_str       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_channel_name(UI_string_type other_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = fmrdo_main_draw.channel_name.x;
    S32 y1 = fmrdo_main_draw.channel_name.y;
    S32 x2 = fmrdo_main_draw.channel_name.x + fmrdo_main_draw.channel_name.w - 1;
    S32 y2 = fmrdo_main_draw.channel_name.y + fmrdo_main_draw.channel_name.h - 1;
    S32 str_w, str_h;
    UI_string_type str;
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    UI_font_type channel_font = &MMI_medium_font;
#else
    UI_font_type channel_font = gui_font_get_type(GUI_FONT_SIZE_MATRIX);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vol_displayed || !g_fmrdo.in_main_screen
    #ifdef __MMI_FM_RADIO_RECORD__
        ||animate_count
    #endif
        )
    {
        return;
    }
#if 0
#ifdef __MMI_FM_RADIO_RDS__
/* under construction !*/
/* under construction !*/
#endif/*__MMI_FM_RADIO_RDS__*/
#endif
    if (other_str == 0)
    {
        if (g_fmrdo.channel_index >= 0)
        {
            str = fmrdo_main_draw.channel_name_str;
            kal_wsprintf(str, "%d. %w", g_fmrdo.channel_index + 1, g_fmrdo.channel_list.name[g_fmrdo.channel_index]);
        }
        else
        {
            str = (UI_string_type) GetString(STR_ID_FMRDO_TITLE);
        }
    }
    else
    {   
        str = other_str;
    }

    /* stop previous scroll text */
    if (!fmrdo_main_draw.is_channel_name_scroll_ready)
    {
        gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);
    }
    else
    {
        fmrdo_main_draw.is_channel_name_scroll_ready = TRUE;
    }
    gui_set_font(channel_font);
    gui_measure_string(str, &str_w, &str_h);
    gui_create_scrolling_text(
        &fmrdo_main_draw.channel_name_scroll,
        x1 + 2,
        y1 + 1,
        fmrdo_main_draw.channel_name.w - 4,
        fmrdo_main_draw.channel_name.h - 2,
        str,
        mmi_fmrdo_scroll_channel_name_hdlr,
        mmi_fmrdo_redraw_main_background,
        fmrdo_main_draw.channel_name_text_color,
        fmrdo_main_draw.channel_name_text_border_color);
    fmrdo_main_draw.channel_name_scroll.text_font = *channel_font;
    fmrdo_main_draw.channel_name_scroll.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;

    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    /* stop scrolling if necessary */
    gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);
	#ifdef __MMI_FM_RADIO_RDS__
		gui_scrolling_text_stop(&fmrdo_main_draw.rds_text_scroll);
	#endif
    //gui_set_font(channel_font);
    //gui_measure_string(str, &str_w, &str_h);
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    /* text */
    if (str_w > fmrdo_main_draw.channel_name.w - 4)
    {
        /* scrolling */
        gui_change_scrolling_text(&fmrdo_main_draw.channel_name_scroll, str);
        gui_show_scrolling_text(&fmrdo_main_draw.channel_name_scroll);
    }
    else
    {
        /* no scrolling */
        gdi_layer_push_and_set_clip(x1, y1, x2, y2);

        gui_set_text_color(fmrdo_main_draw.channel_name_text_color);
        gui_set_text_border_color(fmrdo_main_draw.channel_name_text_border_color);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(
                x1 + (fmrdo_main_draw.channel_name.w + str_w) / 2,
                y1 + 1);//(fmrdo_main_draw.channel_name.h - str_h) / 2);
        }
        else
        {
            gui_move_text_cursor(
                x1 + (fmrdo_main_draw.channel_name.w - str_w) / 2,
                y1 + 1);//(fmrdo_main_draw.channel_name.h - str_h) / 2);
        }
        gui_print_bordered_text(str);
        gdi_layer_pop_clip();
    }

    gdi_layer_pop_clip();
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);
#if 0
#ifdef __MMI_FM_RADIO_RDS__    
/* under construction !*/
#endif/*__MMI_FM_RADIO_RDS__*/
#endif
}


#ifdef __MMI_FM_RADIO_RDS__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_channel_name
 * DESCRIPTION
 *  Redraw channel name on main screen
 * PARAMETERS
 *  other_str       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_redraw_main_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = fmrdo_main_draw.rds_text.x;
    S32 y1 = fmrdo_main_draw.rds_text.y;
    S32 x2 = fmrdo_main_draw.rds_text.x + fmrdo_main_draw.rds_text.w - 1;
    S32 y2 = fmrdo_main_draw.rds_text.y + fmrdo_main_draw.rds_text.h - 1;
    S32 str_w, str_h;
    UI_string_type str;
    UI_font_type rds_font = gui_font_get_type(GUI_FONT_SIZE_MATRIX);
	const S32 cntx_size = sizeof(rds_str1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if((mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") == 0) && (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") == 0))
	{
		memset(rds_str1, 0, cntx_size);

    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        gdi_layer_lock_frame_buffer();
        mmi_fmrdo_set_alpha_blending_layer(TRUE);
    
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);

        mmi_fmrdo_set_alpha_blending_layer(FALSE);

        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(x1, y1, x2, y2);
    #endif
      
		return;
	}
    if(mmi_fmrdo_rds_is_on() && g_fmrdo.is_power_on)
    {
        str = fmrdo_main_draw.rds_text_str;
       	if (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") != 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") != 0)
        {
            kal_wsprintf(str, "%w. %w", g_fmrdo.rds.prog_name, g_fmrdo.rds.radio_text);    
        }
	    else if (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") != 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") == 0)
	    {
	         kal_wsprintf(str, "%w", g_fmrdo.rds.prog_name);
	    }
	    else if(mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") == 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") != 0)
	    {
	         kal_wsprintf(str, "%w",g_fmrdo.rds.radio_text);
	    }
        else
        {
	        str[0] = 0;
        }
		if(mmi_ucs2cmp((CHAR *)rds_str1, (CHAR *)str) != 0)
	    {
	        mmi_ucs2cpy((CHAR *)rds_str1, (CHAR *)str);
	    }
	    else
	    {
	        if(mmi_ucs2cmp((CHAR *)str, (CHAR *)"") != 0)
	        {
	            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_REDRAW_MAIN_TEXT_BOTH_STRINGS_SAME);
	            return;
	        }
	    }
        /* stop previous scroll text */
        if (!fmrdo_main_draw.is_rds_text_scroll_ready)
        {
            gui_scrolling_text_stop(&fmrdo_main_draw.rds_text_scroll);
        }
        else
        {
            fmrdo_main_draw.is_rds_text_scroll_ready = TRUE;
        }
        gui_set_font(rds_font);
        gui_create_scrolling_text(
            &fmrdo_main_draw.rds_text_scroll,
            x1 + 2,
            y1 + 1,
            fmrdo_main_draw.rds_text.w - 4,
            fmrdo_main_draw.rds_text.h - 2,
            str,
            mmi_fmrdo_scroll_rds_text_hdlr,
            mmi_fmrdo_redraw_main_background,
            fmrdo_main_draw.rds_text_color,
            fmrdo_main_draw.rds_text_border_color);
        fmrdo_main_draw.rds_text_scroll.text_font = *rds_font;
        fmrdo_main_draw.rds_text_scroll.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;

        gdi_layer_lock_frame_buffer();
        mmi_fmrdo_set_alpha_blending_layer(TRUE);
        gdi_layer_push_and_set_clip(x1, y1, x2, y2);

        /* stop scrolling if necessary */
   		gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);
        gui_scrolling_text_stop(&fmrdo_main_draw.rds_text_scroll);
        gui_measure_string(str, &str_w, &str_h);

        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);


        /* text */
        if (str_w > fmrdo_main_draw.rds_text.w - 4)
        {
            /* scrolling */
            gui_change_scrolling_text(&fmrdo_main_draw.rds_text_scroll, str);
            gui_show_scrolling_text(&fmrdo_main_draw.rds_text_scroll);
        }
        else
        {
            gdi_layer_push_and_set_clip(x1, y1, x2, y2);

            gui_set_text_color(fmrdo_main_draw.rds_text_color);
            gui_set_text_border_color(fmrdo_main_draw.rds_text_border_color);
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(
                    x1 + (fmrdo_main_draw.rds_text.w + str_w) / 2,
                    y1 + (fmrdo_main_draw.rds_text.h - str_h) / 2);
            }
            else
            {
                gui_move_text_cursor(
                    x1 + (fmrdo_main_draw.rds_text.w - str_w) / 2,
                    y1 + 1);// (fmrdo_main_draw.rds_text.h - str_h) / 2);
            }
            gui_print_bordered_text(str);
            gdi_layer_pop_clip();
        }

        gdi_layer_pop_clip();
        mmi_fmrdo_set_alpha_blending_layer(FALSE);
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
    else
    {
        gdi_layer_lock_frame_buffer();
        mmi_fmrdo_set_alpha_blending_layer(TRUE);
    
        gui_scrolling_text_stop(&fmrdo_main_draw.rds_text_scroll);
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);

        mmi_fmrdo_set_alpha_blending_layer(FALSE);

        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scroll_channel_name_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scroll_rds_text_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
    gui_handle_scrolling_text(&fmrdo_main_draw.rds_text_scroll);
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_rds_redraw_main_ind
 * DESCRIPTION
 *  Redraw push buttons on main screen
 * PARAMETERS
 *  button      [IN]        
 *  is_down     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_redraw_main_ind(U8 ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmrdo_main_ind_struct *ind_button_p;
    S32 x1, y1, x2, y2;
    PU8 draw_img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ind)
    {
        case FMRDO_RDS_IND_MAIN:
            ind_button_p = &fmrdo_main_draw.rds_ind;
            if(!mmi_fmrdo_rds_is_on())
            {
                draw_img = ind_button_p->down_img;
            }
            else
            {
                if((g_fmrdo.rds.status_mask & RT_RECIEVE) || (g_fmrdo.rds.status_mask & PS_RECIEVE))/*ps name recieved or rt recieved through flags*/
                {
                    draw_img = ind_button_p->up_img;
                }
                else
                {
                    draw_img = ind_button_p->down_img;
}
            }
            break;
        case FMRDO_RDS_IND_TP:
            ind_button_p = &fmrdo_main_draw.tp_ind;
            if(!mmi_fmrdo_rds_is_on())
            {
                draw_img = ind_button_p->down_img;
            }
            else
            {
                if(g_fmrdo.rds.status_mask & TP_RECIEVE)
                {
                    draw_img = ind_button_p->up_img;
                }
                else
                {
                    draw_img = ind_button_p->down_img;
                }
            }
            break;
        case FMRDO_RDS_IND_AF:
            ind_button_p = &fmrdo_main_draw.af_ind;
            if(!mmi_fmrdo_rds_is_on())
            {
                draw_img = ind_button_p->down_img;
            }
            else
            {
                if(g_fmrdo.rds.status_mask & AF_RECIEVE)
                {
                    draw_img = ind_button_p->up_img;
                }
                else
                {
                    draw_img = ind_button_p->down_img;
                }
            }
            break;
        default:
            return;
    }

    x1 = ind_button_p->x;
    y1 = ind_button_p->y;
    x2 = ind_button_p->x + ind_button_p->w - 1;
    y2 = ind_button_p->y + ind_button_p->h - 1;

    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
	gdi_layer_push_and_set_active(fmrdo_skin_layer);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

	gui_draw_filled_area(	0, 
										0,
										UI_device_width - 1,
										UI_device_height - 1,
										current_MMI_theme->sub_menu_bkg_filler);
    /* button */
    gui_show_image(x1, y1, draw_img);

    gdi_layer_pop_clip();
	gdi_layer_pop_and_restore_active();
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);

}
#endif/*__MMI_FM_RADIO_RDS__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_channel_tuner
 * DESCRIPTION
 *  Redraw tuner on main screen
 * PARAMETERS
 *  freq        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_channel_tuner(U16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Remove this function */
}

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_volume
 * DESCRIPTION
 *  Redraw volume indicator on main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_fmrdo_need_disable_push_button(FMRDO_BUTTON_VOLUME))
    {
        return;
    }
    if (!g_vol_displayed)
    {
        #ifndef __MMI_FM_PLUTO_SLIM__
        if(mmi_fmrdo_is_stepping_up()||mmi_fmrdo_is_stepping_down())
        {
            mmi_fmrdo_redraw_record_frequency(g_fmrdo.step_freq, MMI_TRUE);
            mmi_fmrdo_redraw_main_frequency(g_fmrdo.step_freq, MMI_FALSE);
        }
        else
		#endif	
        {
            mmi_fmrdo_redraw_record_frequency(g_fmrdo.frequency, MMI_TRUE);
        }
        mmi_fmrdo_hide_main_channel_name();
    }
    mmi_fmrdo_redraw_main_volumebar(g_fmrdo.volume, MMI_TRUE);
    g_vol_displayed = 1;
}
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_push_button
 * DESCRIPTION
 *  Redraw push buttons on main screen
 * PARAMETERS
 *  button      [IN]        
 *  is_down     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_push_button(U8 button, BOOL is_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmrdo_main_push_button_struct *push_button_p;
    S32 x1, y1, x2, y2;
    S32 diffx, diffy;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FM_RADIO_RECORD__)
    if(animate_count && !(g_fmrdo.state == FMRDO_STATE_RECORD)) 
    {
    #ifndef __RF_DESENSE_TEST__   
          return; 
    #endif
    }
#endif 
	if(!g_fmrdo.in_main_screen)
	{
		return;
	}
    switch (button)
    {
        case FMRDO_BUTTON_STEP_UP:
            push_button_p = &fmrdo_main_draw.step_up_button;
            break;
        case FMRDO_BUTTON_STEP_DOWN:
            push_button_p = &fmrdo_main_draw.step_down_button;
            break;
        case FMRDO_BUTTON_MEMO_UP:
            push_button_p = &fmrdo_main_draw.memo_up_button;
            break;
        case FMRDO_BUTTON_MEMO_DOWN:
            push_button_p = &fmrdo_main_draw.memo_dn_button;
            break;
        default:
            return;
    }
    x1 = push_button_p->x;
    y1 = push_button_p->y;
    x2 = push_button_p->x + push_button_p->w - 1;
    y2 = push_button_p->y + push_button_p->h - 1;
    if (is_fmrdo_skin_layer_drawn)
    {
        diffx = fmrdo_main_draw.highlight_img.w - push_button_p->w;
        diffy = fmrdo_main_draw.highlight_img.h - push_button_p->h;
        x1 -= (diffx / 2);
        y1 -= (diffy / 2);
        x2 += ((1 + diffx) / 2);
        y2 += ((1 + diffy) / 2);
    }

    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    if (!is_fmrdo_skin_layer_drawn)
    {
        gui_show_image(x1, y1, push_button_p->up_img);
    }
    else if (is_down)
    {
        gui_show_image(x1, y1, fmrdo_main_draw.highlight_img.up_img);
    }
    else
    {
        if (mmi_fmrdo_need_disable_button(button))
        {
        gdi_layer_push_and_set_active(fmrdo_skin_layer);
		 gdi_layer_push_and_set_clip(x1, y1, x2, y2);
		gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->sub_menu_bkg_filler);
		gui_draw_image_with_alpha_transparent(
							  push_button_p->up_img,
							  x1,
						   	  y1,
						   	  125); 
		 gdi_layer_pop_clip();
		gdi_layer_pop_and_restore_active();
        }
        else
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        }
    }

    gdi_layer_pop_clip();
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    if (is_fmrdo_skin_layer_drawn && g_vol_displayed)
    {
        mmi_fmrdo_reset_volume_bar();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_need_disable_button
 * DESCRIPTION
 *  Decide whether button needs to be disabled
 * PARAMETERS
 *  button          [IN]        
 * RETURNS
 *  TRUE
 *****************************************************************************/
pBOOL mmi_fmrdo_need_disable_button(U8 button)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (button)
    {
        case FMRDO_BUTTON_POWER:
    #ifndef __RF_DESENSE_TEST__
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        case FMRDO_BUTTON_SEARCH:
    #endif
        case FMRDO_BUTTON_STEP_UP:
        case FMRDO_BUTTON_STEP_DOWN:
    #endif /* __RF_DESENSE_TEST__ */
        case FMRDO_BUTTON_MEMO_UP:
        case FMRDO_BUTTON_MEMO_DOWN:
            if (g_fmrdo.state == FMRDO_STATE_RECORD ||
                g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE
        #if defined(__MMI_FM_RADIO_RECORD__)
                || (animate_count != 0)
        #endif
                )
            {
                return TRUE;
            }
            break;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_toggle_button
 * DESCRIPTION
 *  Redraw toggle buttons on main screen
 * PARAMETERS
 *  button          [IN]        
 *  is_down         [IN]        
 *  is_on           [IN]        
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_toggle_button(U8 button, BOOL is_down, BOOL is_on, BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmrdo_main_toggle_button_struct *toggle_button_p;
    S32 x1, y1, x2, y2;
    PU8 draw_img = NULL;
    S32 diffx, diffy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FM_RADIO_RECORD__)
    if(animate_count && !(g_fmrdo.state == FMRDO_STATE_RECORD)) 
    {
        return; 
    }
#endif 
	if(!g_fmrdo.in_main_screen)
    {
		return;
	}

    switch (button)
    {
        case FMRDO_BUTTON_POWER:
            toggle_button_p = &fmrdo_main_draw.power_button;
            break;
            
    #if defined(__MMI_FM_RADIO_RECORD__)
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        case FMRDO_BUTTON_REC:
            toggle_button_p = &fmrdo_main_draw.rec_button;
            break;
     #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    #endif /* __MMI_FM_RADIO_RECORD__ */ 
    
        default:
            return;
    }
    diffx = fmrdo_main_draw.highlight_img.w - toggle_button_p->w;
    diffy = fmrdo_main_draw.highlight_img.h - toggle_button_p->h;
    x1 = toggle_button_p->x - (diffx / 2);
    y1 = toggle_button_p->y - (diffy / 2);
    x2 = x1 + toggle_button_p->w + diffx - 1;
    y2 = y1 + toggle_button_p->h + diffy - 1;

    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    if (is_on)
    {
        draw_img = toggle_button_p->on_up_img;
    }
    else
    {
        draw_img = toggle_button_p->off_up_img;
    }
    if (is_fmrdo_skin_layer_drawn)
    {	
        gdi_layer_push_and_set_active(fmrdo_skin_layer);
		gdi_layer_push_and_set_clip(x1, y1, x2, y2);
		gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->sub_menu_bkg_filler);
		if (mmi_fmrdo_need_disable_button(button))
		{ 	
			gui_draw_image_with_alpha_transparent(
								  draw_img,
								  x1,
							   	  y1,
							   	  125); 
		}
		else
		{
			gui_show_image(toggle_button_p->x, toggle_button_p->y, draw_img);
		}
		gdi_layer_pop_clip();
       	gdi_layer_pop_and_restore_active();
        	if (is_down)
        	{
            	gui_show_image(x1, y1, fmrdo_main_draw.highlight_img.up_img);
        	}
        	else    /* Clear to background */
        	{
            	gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        	}
    	}
    else
    {
        gui_show_image(x1, y1, draw_img);
    }
    gdi_layer_pop_clip();
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    if (is_fmrdo_skin_layer_drawn && g_vol_displayed)
    {
        mmi_fmrdo_reset_volume_bar();
    }
#endif 
}

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_toggle_button
 * DESCRIPTION
 *  Redraw toggle buttons on main screen
 * PARAMETERS
 *  button          [IN]        
 *  is_down         [IN]        
 *  is_on           [IN]        
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_bar_toggle_button(U8 button, BOOL is_down, BOOL is_on, BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmrdo_bar_toggle_button_struct *toggle_button_p;
    S32 x1, y1, x2, y2;
    S32 y_offset = 0;
#ifdef __MMI_FTE_SUPPORT_SLIM__
    S32 btn_bg_x1, btn_bg_y1, btn_bg_x2, btn_bg_y2;
    PU8 btn_bg_img = NULL;
#endif  /* __MMI_FTE_SUPPORT_SLIM__ */
    PU8 draw_img = NULL;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (button)
    {
    #if defined(__MMI_FM_RADIO_RECORD__)
        case FMRDO_BUTTON_REC_PAUSE:
        #ifdef __MMI_FTE_SUPPORT_SLIM__
            if (is_down)
            {
                btn_bg_img = (PU8) GetImage(IMG_ID_FMRDO_SKIN_REC_BTN_DOWN);
            }
            else
            {
                btn_bg_img = (PU8) GetImage(IMG_ID_FMRDO_SKIN_REC_BTN_UP);
            }
            btn_bg_x1 = FMRDO_RECORD_LK_X;
            btn_bg_y1 = FMRDO_RECORD_LK_Y;
        #endif /* __MMI_FTE_SUPPORT_SLIM__ */
            y_offset = ((UI_device_height - fmrdo_main_draw.rec_bar.y) * (MMI_FMRDO_ANIMATE_FRAME_COUNT - animate_count) / MMI_FMRDO_ANIMATE_FRAME_COUNT);
            toggle_button_p = &fmrdo_main_draw.bar_record_button;
            break;
        case FMRDO_BUTTON_REC_STOP:
        #ifdef __MMI_FTE_SUPPORT_SLIM__
            if (is_down)
            {
                btn_bg_img = (PU8) GetImage(IMG_ID_FMRDO_SKIN_REC_BTN_DOWN);
            }
            else
            {
                btn_bg_img = (PU8) GetImage(IMG_ID_FMRDO_SKIN_REC_BTN_UP);
            }
            btn_bg_x1 = FMRDO_RECORD_RK_X;
            btn_bg_y1 = FMRDO_RECORD_RK_Y;
        #endif /* __MMI_FTE_SUPPORT_SLIM__ */
            y_offset = ((UI_device_height - fmrdo_main_draw.rec_bar.y) * (MMI_FMRDO_ANIMATE_FRAME_COUNT - animate_count) / MMI_FMRDO_ANIMATE_FRAME_COUNT);
            toggle_button_p = &fmrdo_main_draw.bar_stop_record;
            break;
    #endif /* __MMI_FM_RADIO_RECORD__ */
        case FMRDO_BUTTON_VOLUME:
            toggle_button_p = &fmrdo_main_draw.vol_img;
            break;
        default:
            return;
    }
    x1 = toggle_button_p->x;
    y1 = y_offset + toggle_button_p->y;
    x2 = x1 + toggle_button_p->w - 1;
    y2 = y1 + toggle_button_p->h - 1;

    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
#ifdef __MMI_FTE_SUPPORT_SLIM__
    if (btn_bg_img != NULL)
    {
        btn_bg_y1 += y_offset;
        btn_bg_x2 = btn_bg_x1 + FMRDO_RECORD_BTN_BG_W - 1;
        btn_bg_y2 = btn_bg_y1 + FMRDO_RECORD_BTN_BG_H - 1;
    }
    else
    {
        btn_bg_x1 = x1;
        btn_bg_y1 = y1;
        btn_bg_x2 = x2;
        btn_bg_y2 = y2;
    }
    gdi_layer_push_and_set_clip(btn_bg_x1, btn_bg_y1, btn_bg_x2, btn_bg_y2);
#else
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
#endif /* __MMI_FTE_SUPPORT_SLIM__ */

    if (is_on)
    {
        if (is_down)
        {
            draw_img = toggle_button_p->on_down_img;
        }
        else
        {
            draw_img = toggle_button_p->on_up_img;
        }
    }
    else
    {
        if (is_down)
        {
            draw_img = toggle_button_p->off_down_img;
        }
        else
        {
            draw_img = toggle_button_p->off_up_img;
        }
    }

#ifdef __MMI_FTE_SUPPORT_SLIM__
    gdi_draw_solid_rect(btn_bg_x1, btn_bg_y1, btn_bg_x2, btn_bg_y2, GDI_COLOR_TRANSPARENT);
#else
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#endif /* __MMI_FTE_SUPPORT_SLIM__ */

#ifdef __MMI_FTE_SUPPORT_SLIM__
    if (btn_bg_img != NULL)
    {
        gdi_image_draw_resized(btn_bg_x1,
                               btn_bg_y1,
                               FMRDO_RECORD_BTN_BG_W,
                               FMRDO_RECORD_BTN_BG_H,
                               btn_bg_img);
        gdi_push_and_set_alpha_blending_source_layer(fmrdo_osd_layer);
    }
#endif /* __MMI_FTE_SUPPORT_SLIM__ */

    if (is_shown)
    {
        gui_show_image(x1, y1, draw_img);
    }

#ifdef __MMI_FTE_SUPPORT_SLIM__
    if (btn_bg_img != NULL)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
#endif /* __MMI_FTE_SUPPORT_SLIM__ */

    gdi_layer_pop_clip();
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
#ifdef __MMI_FTE_SUPPORT_SLIM__
    gdi_layer_blt_previous(btn_bg_x1, btn_bg_y1, btn_bg_x2, btn_bg_y2);
#else
    gdi_layer_blt_previous(x1, y1, x2, y2);
#endif /* __MMI_FTE_SUPPORT_SLIM__ */
}
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_restore_main_SK
 * DESCRIPTION
 *  Redraw main screen LSK and RSK for restore back to play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_restore_main_SK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_LSK_up();
    mmi_fmrdo_redraw_main_RSK_up();
    //g_fmrdo.is_button_down = FALSE;
}


#ifdef __FM_RADIO_HW_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_twinkle_searching
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_twinkle_searching(BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __FM_RADIO_HW_SEARCH__ */ 

/* MTK Leo add 20050301, add touch screen support for FM Radio */
#ifdef __MMI_TOUCH_SCREEN__

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_push_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button      [IN]        0 = volume_dec_button, 1 = volume_inc_button
 *  is_down     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_push_down_button(U8 button, BOOL is_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (button == 0 || button == 1)
    {
        if (is_down)
        {
            g_fmrdo.selected_button = FMRDO_BUTTON_VOLUME;
            mmi_fmrdo_redraw_main_volume();
            g_fmrdo.is_button_down = MMI_TRUE;
        }
        else
        {
            g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
            g_fmrdo.is_button_down = MMI_FALSE;
        }
    }
}
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_pen_down_hdlr
 * DESCRIPTION
 *  Pen down event handler for main screen
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i = FMRDO_PEN_LSK;
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[g_fmrdo.skin_index];
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_pen_polygon_area_struct empty_area;
    mmi_pen_point_struct empty_area_points[4];
    #endif /*MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT*/
    U8 is_touch_feedback = 0;      // Flag to determine whether the touch is valid or not 

    S32 icon_id;
    wgui_status_icon_bar_pen_enum evt_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_WEARABLE_DEVICE__
    g_swatch_is_pen_down = MMI_TRUE;
    g_swatch_pen_down_pos.x = pos.x;
    g_swatch_pen_down_pos.y = pos.y;
    #endif  //__MMI_WEARABLE_DEVICE__
    
    fmrdo_pen_event_on_object = FMRDO_PEN_NONE;

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
#if defined(__MMI_FM_RADIO_RECORD__)
    if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
    #ifndef __RF_DESENSE_TEST__
        i = FMRDO_PEN_MAIN_REC_PAUSE;
    #endif /* __RF_DESENSE_TEST__ */
    }
#endif 
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    for (; i < FMRDO_PEN_MAIN_SEARCH; i++)
    {
        switch (i)
        {
            case FMRDO_PEN_LSK:
                area = (mmi_pen_polygon_area_struct*) & LSK_area;
                point = pos;
                break;
            case FMRDO_PEN_RSK:
                area = (mmi_pen_polygon_area_struct*) & RSK_area;
                point = pos;
                break;
            case FMRDO_PEN_MAIN_STEP_UP:
                area = (mmi_pen_polygon_area_struct*) & skin_p->step_up_button_area;
                point.x = pos.x - skin_p->step_up_button_x;
                point.y = pos.y - skin_p->step_up_button_y;
                break;
            case FMRDO_PEN_MAIN_STEP_DOWN:
                area = (mmi_pen_polygon_area_struct*) & skin_p->step_down_button_area;
                point.x = pos.x - skin_p->step_down_button_x;
                point.y = pos.y - skin_p->step_down_button_y;
                break;
            case FMRDO_PEN_MAIN_MEMO_UP:
                area = (mmi_pen_polygon_area_struct*) & skin_p->memo_inc_button_area;
                point.x = pos.x - skin_p->memo_up_button_x;
                point.y = pos.y - skin_p->memo_up_button_y;
                break;
            case FMRDO_PEN_MAIN_MEMO_DOWN:
                area = (mmi_pen_polygon_area_struct*) & skin_p->memo_dec_button_area;
                point.x = pos.x - skin_p->memo_down_button_x;
                point.y = pos.y - skin_p->memo_down_button_y;
                break;
            case FMRDO_PEN_MAIN_POWER:
                area = (mmi_pen_polygon_area_struct*) & skin_p->power_button_area;
                point.x = pos.x - skin_p->power_button_x;
                point.y = pos.y - skin_p->power_button_y;
                break;
            #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            case FMRDO_PEN_MAIN_KEY_ONLY_SPEAKER_MUTE:
                area = (mmi_pen_polygon_area_struct*) & skin_p->key_only_speaker_mute_area;
                point.x = pos.x - skin_p->speaker_image_x;
                point.y = pos.y - skin_p->speaker_image_y;
                break;
            #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
        #if defined(__MMI_FM_RADIO_RECORD__)
   #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            case FMRDO_PEN_MAIN_REC:
                area = (mmi_pen_polygon_area_struct*) & skin_p->record_button_area;
                point.x = pos.x - skin_p->rec_button_x;
                point.y = pos.y - skin_p->rec_button_y;
                break;
   #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
        #endif 
        #if 0 // if support mute button as clickable (maybe supported later)
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

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT

            case FMRDO_PEN_MAIN_VOLUME_IND:
                if (g_vol_displayed)
                {
                    area = (mmi_pen_polygon_area_struct*) & skin_p->VOL_ind_area;
                    point.x = pos.x - g_vol_ind_x;
                    point.y = pos.y - g_vol_ind_y;
                }
                else
                {
                    continue;
                }
                break;
            case FMRDO_PEN_MAIN_VOL:
                if (g_vol_displayed)
                {
                    area = (mmi_pen_polygon_area_struct*) & skin_p->VOL_area;
                    point.x = pos.x - skin_p->volume_bar_x;
                    point.y = pos.y - skin_p->volume_bar_y;
                }
                else
                {
                    continue;
                }
                break;
            case FMRDO_PEN_MAIN_VOL_TOUCH:
            #ifdef __RF_DESENSE_TEST__
               if (g_fmrdo.state != FMRDO_STATE_RECORD && g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE)
               {
            #endif /* __RF_DESENSE_TEST__ */
                if (!g_vol_displayed)
                {
                    empty_area_points[0].x = empty_area_points[3].x = 0;
                    empty_area_points[1].x = empty_area_points[2].x = UI_device_width;
                    empty_area_points[0].y = empty_area_points[1].y = MMI_BUTTON_BAR_HEIGHT;
                    empty_area_points[2].y = empty_area_points[3].y = skin_p->step_up_button_y;
                    empty_area.points = (mmi_pen_point_struct*) empty_area_points;
                    empty_area.num = 4;
                    area = (mmi_pen_polygon_area_struct*) & empty_area;
                    point = pos;
                }
                else
                {
                    continue;
                }
            #ifdef __RF_DESENSE_TEST__
                }
            #endif /* __RF_DESENSE_TEST__ */
                break;

#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

        #if defined(__MMI_FM_RADIO_RECORD__)
  #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            case FMRDO_PEN_MAIN_REC_STOP:
                area = (mmi_pen_polygon_area_struct*) & skin_p->record_stop_area;
                point.x = pos.x - skin_p->rec_tool_stop_x;
                point.y = pos.y - skin_p->rec_tool_stop_y;
                break;
            case FMRDO_PEN_MAIN_REC_PAUSE:
                area = (mmi_pen_polygon_area_struct*) & skin_p->record_pause_area;
                point.x = pos.x - skin_p->rec_tool_rec_x;
                point.y = pos.y - skin_p->rec_tool_rec_y;
                break;
   #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
        #endif 
            default:
                continue;
                /* TODO: Skin_p freq_area to be removed */
        }
        if (mmi_pen_check_inside_polygon(area, point))
        {
            fmrdo_pen_event_on_object = i;
            is_touch_feedback = 1;
            break;
        }
    }

	if(fmrdo_pen_event_on_object != FMRDO_PEN_MAIN_VOLUME_IND && fmrdo_pen_event_on_object != FMRDO_PEN_MAIN_VOL && is_fmrdo_skin_layer_drawn && g_vol_displayed)
	{
		fmrdo_pen_event_on_object = FMRDO_PEN_NONE;
	}	
    switch (fmrdo_pen_event_on_object)
    {
        case FMRDO_PEN_LSK:
            mmi_fmrdo_redraw_main_LSK_down();
            ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
            break;
        case FMRDO_PEN_RSK:
            mmi_fmrdo_redraw_main_RSK_down();
            ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
            break;
        case FMRDO_PEN_MAIN_STEP_UP:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_STEP_UP))
            {
                mmi_fmrdo_press_step_up_button();
            }
            break;
        case FMRDO_PEN_MAIN_STEP_DOWN:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_STEP_DOWN))
            {
                mmi_fmrdo_press_step_down_button();
            }
            break;
        case FMRDO_PEN_MAIN_MEMO_UP:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_MEMO_UP))
            {
                mmi_fmrdo_press_memo_up_button();
            }
            break;
        case FMRDO_PEN_MAIN_MEMO_DOWN:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_MEMO_DOWN))
            {
                mmi_fmrdo_press_memo_down_button();
            }
            break;
        case FMRDO_PEN_MAIN_POWER:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_POWER))
            {
                mmi_fmrdo_press_power_button();
            }
            break;
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT   
        case FMRDO_PEN_MAIN_SEARCH:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_SEARCH))
            {
                mmi_fmrdo_press_search_button();
            }
            break;
 #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    #if defined(__MMI_FM_RADIO_RECORD__)
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        case FMRDO_PEN_MAIN_REC:
            if (mmi_fmrdo_is_record_allowed())
            {
                mmi_fmrdo_press_record_button();
            }
            break;
    #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    #endif 

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        case FMRDO_PEN_MAIN_VOL:
            mmi_fmrdo_translate_volume(&point, MMI_FALSE);
            break;
        case FMRDO_PEN_MAIN_VOL_MUTE:
            mmi_fmrdo_press_toggle_mute();
            break;
        case FMRDO_PEN_MAIN_VOL_TOUCH:
            if (!mmi_fmrdo_need_disable_push_button(FMRDO_BUTTON_VOLUME))
            {
                mmi_fmrdo_redraw_main_volume();
            }
            break;
        case FMRDO_PEN_MAIN_VOLUME_IND:
            g_vol_highlight = 1;
            mmi_fmrdo_redraw_main_volumebar(g_fmrdo.volume, MMI_TRUE);
            break;
 #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        case FMRDO_PEN_MAIN_KEY_ONLY_SPEAKER_MUTE:
            mmi_fmrdo_support_keyonly_toggle_press_mute();
            break;
#endif

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT

    #if defined(__MMI_FM_RADIO_RECORD__)
        case FMRDO_PEN_MAIN_REC_STOP:
            if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_press_record_stop();
            }
            break;
        case FMRDO_PEN_MAIN_REC_PAUSE:
            if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_press_record_pause();
            }
            break;
    #endif 
    #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT*/
		default:
		#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
			if (is_fmrdo_skin_layer_drawn && g_vol_displayed)
    		{
       			mmi_fmrdo_reset_volume_bar();
    		}
			else
        #endif
			#ifdef __MMI_TOUCH_SCREEN__
            {
                wgui_status_icon_bar_translate_pen_event(
                    MMI_PEN_EVENT_DOWN,
                    pos.x,
                    pos.y,
                    &icon_id,
                    &evt_type);
            }
            #endif
			break;
    }
/* Touch Feedback */   
#ifdef __MMI_FTE_SUPPORT__
    if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
	{
		switch (fmrdo_pen_event_on_object)
	    {
	    	case FMRDO_PEN_MAIN_STEP_UP:
	        case FMRDO_PEN_MAIN_STEP_DOWN:
	        case FMRDO_PEN_MAIN_MEMO_UP:
	        case FMRDO_PEN_MAIN_MEMO_DOWN:
	        case FMRDO_PEN_MAIN_POWER:
	        	is_touch_feedback = 0;
				break;
			default:
				break;
		}
	}
    if (is_touch_feedback)
    {
        if(g_fmrdo.is_power_on)
        {
		    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN_VIBRATE);
        }
        else
        {
        #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
        #endif /*__MMI_TOUCH_FEEDBACK_SUPPORT__*/
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__  
/* under construction !*/
	#endif /*__MMI_TOUCH_FEEDBACK_SUPPORT__*/
        }

	}

#endif /* __MMI_FTE_SUPPORT__ */

    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_pen_long_tap_hdlr
 * DESCRIPTION
 *  Pen up event handler for main screen
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_pen_long_tap_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;
    BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

    S32 icon_id;
    wgui_status_icon_bar_pen_enum evt_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_power_on)
    {
        return;
    }
    switch (fmrdo_pen_event_on_object)
    {
    case FMRDO_PEN_MAIN_STEP_UP:
        if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_STEP_UP))
        {
            StopTimer(FMRDO_REPEAT_STEP_TIMER);
            mmi_fmrdo_redraw_main_push_button(
                g_fmrdo.selected_button,
                g_fmrdo.is_button_down);
            if (is_freq_changed)
            {
                freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to increase it again */
            }
            else
            {
                /* frequency is not changed during button press down so we need to increase it */
                if (g_fmrdo.frequency < MAX_FM_FREQUENCY)
                {
                    freq = g_fmrdo.frequency + 1;
                }
                else
                {
                    freq = MIN_FM_FREQUENCY;
                }
            }
        #ifdef __FM_RADIO_HW_SEARCH__
            if (is_freq_changed)
            {
            mmi_fmrdo_hw_search_frequency_start(freq, MMI_TRUE);
			}
			else
			{
				mmi_fmrdo_hw_search_frequency_start(g_fmrdo.frequency, MMI_TRUE);
			}
        #else 
            mmi_fmrdo_redraw_main_channel_name((UI_string_type) GetString(STR_GLOBAL_SEARCHING));
            if (is_freq_changed)
            {
            mmi_fmrdo_search_frequency_start(freq, MMI_TRUE);
			}
			else
			{
				mmi_fmrdo_search_frequency_start(g_fmrdo.frequency, MMI_TRUE);
			}
        #endif 
        }
        break;
    case FMRDO_PEN_MAIN_STEP_DOWN:
        if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_STEP_DOWN))
        {
            StopTimer(FMRDO_REPEAT_STEP_TIMER);
            mmi_fmrdo_redraw_main_push_button(
                g_fmrdo.selected_button,
                g_fmrdo.is_button_down);
            if (is_freq_changed)
            {
                freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to decrease it again */
            }
            else
            {
                /* frequency is not changed during button press down so we need to decrease it */
                if (g_fmrdo.frequency > MIN_FM_FREQUENCY)
                {
                    freq = g_fmrdo.frequency - 1;
                }
                else
                {
                    freq = MAX_FM_FREQUENCY;
                }
            }
        #ifdef __FM_RADIO_HW_SEARCH__
			if (is_freq_changed)
            {
            mmi_fmrdo_hw_search_frequency_start(freq, MMI_FALSE);
			}
			else
			{
				mmi_fmrdo_hw_search_frequency_start(g_fmrdo.frequency, MMI_FALSE);
			}
        #else 
            mmi_fmrdo_redraw_main_channel_name((UI_string_type) GetString(STR_GLOBAL_SEARCHING));
			if (is_freq_changed)
            {
            mmi_fmrdo_search_frequency_start(freq, MMI_FALSE);
			}
			else
			{
				mmi_fmrdo_search_frequency_start(g_fmrdo.frequency, MMI_FALSE);
			}
        #endif 
        }
        break;
    default:
        wgui_status_icon_bar_translate_pen_event(
            MMI_PEN_EVENT_LONG_TAP,
            pos.x,
            pos.y,
            &icon_id,
            &evt_type);
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_pen_up_hdlr
 * DESCRIPTION
 *  Pen up event handler for main screen
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_id;
    wgui_status_icon_bar_pen_enum evt_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_WEARABLE_DEVICE__
    if (g_swatch_is_pen_down && ((pos.x - g_swatch_pen_down_pos.x) > MMI_SWATCH_BACK_MOVE_THRESHOLD_X))  //swipe right
    {
        mmi_frm_scrn_close_active_id();
        g_swatch_is_pen_down = MMI_FALSE;
        return;
    }
    #endif  //__MMI_WEARABLE_DEVICE__
    switch (fmrdo_pen_event_on_object)
    {
        case FMRDO_PEN_MAIN_STEP_UP:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_STEP_UP))
            {
                mmi_fmrdo_release_step_up_button();
            }
            break;
        case FMRDO_PEN_MAIN_STEP_DOWN:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_STEP_DOWN))
            {
                mmi_fmrdo_release_step_down_button();
            }
            break;
        case FMRDO_PEN_MAIN_MEMO_UP:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_MEMO_UP))
            {            
            #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                mmi_fmrdo_pre_release_memo_up_button();
            #else
                mmi_fmrdo_release_memo_up_button();
            #endif
            }
            break;
        case FMRDO_PEN_MAIN_MEMO_DOWN:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_MEMO_DOWN))
            {
            #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                mmi_fmrdo_pre_release_memo_down_button();
            #else
                mmi_fmrdo_release_memo_down_button();
            #endif
            }
            break;
        case FMRDO_PEN_MAIN_POWER:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_POWER))
            {
                mmi_fmrdo_release_power_button();
            }
            break;
        case FMRDO_PEN_LSK:
            if (g_fmrdo.is_button_down)
            {
                ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
            }
            break;
        case FMRDO_PEN_RSK:
            if (g_fmrdo.is_button_down)
            {
                ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_UP);
            }
            break;

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        case FMRDO_PEN_MAIN_KEY_ONLY_SPEAKER_MUTE:
            mmi_fmrdo_support_keyonly_toggle_release_mute();
            break;
#else /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    #if defined(__MMI_FM_RADIO_RECORD__)
        case FMRDO_PEN_MAIN_REC:
            mmi_fmrdo_release_record();
            break;
    #endif 
        case FMRDO_PEN_MAIN_VOL_MUTE:
            if (g_vol_displayed)
            {
                mmi_fmrdo_release_toggle_mute();
            }
            break;
        case FMRDO_PEN_MAIN_VOLUME_IND:
            if (g_vol_highlight)
            {
                g_vol_highlight = 0;
                mmi_fmrdo_redraw_main_volumebar(g_fmrdo.volume, MMI_TRUE);
            }
            break;
    #if defined(__MMI_FM_RADIO_RECORD__)
        case FMRDO_PEN_MAIN_REC_STOP:
            mmi_fmrdo_release_record_stop();
            break;
        case FMRDO_PEN_MAIN_REC_PAUSE:
            mmi_fmrdo_release_record_pause();
            break;
    #endif 
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
        default:
            wgui_status_icon_bar_translate_pen_event(
                MMI_PEN_EVENT_UP,
                pos.x,
                pos.y,
                &icon_id,
                &evt_type);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_pen_move_hdlr
 * DESCRIPTION
 *  Pen move event handler for main screen
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[g_fmrdo.skin_index];
    S32 icon_id;
    wgui_status_icon_bar_pen_enum evt_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fmrdo_pen_event_on_object)
    {
        case FMRDO_PEN_MAIN_STEP_UP:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_STEP_UP))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->step_up_button_area;
                point.x = pos.x - skin_p->step_up_button_x;
                point.y = pos.y - skin_p->step_up_button_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_press_step_up_button();
                }
                else
                {
                    U16 freq;
                    BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

                    StopTimer(FMRDO_REPEAT_STEP_TIMER);
                    g_fmrdo.is_button_down = FALSE;
                    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
                    if (is_freq_changed)
                    {
                        freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to increase it again */
                        mmi_fmrdo_set_frequency(freq);
                    }

                    g_fmrdo.normal_repeat_step_count = 0;
                    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
                }
            }
            break;
        case FMRDO_PEN_MAIN_STEP_DOWN:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_STEP_DOWN))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->step_down_button_area;
                point.x = pos.x - skin_p->step_down_button_x;
                point.y = pos.y - skin_p->step_down_button_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_press_step_down_button();
                }
                else
                {
                    U16 freq;
                    BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

                    StopTimer(FMRDO_REPEAT_STEP_TIMER);
                    g_fmrdo.is_button_down = FALSE;
                    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
                    if (is_freq_changed)
                    {
                        freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to increase it again */
                        mmi_fmrdo_set_frequency(freq);
                    }

                    g_fmrdo.normal_repeat_step_count = 0;
                    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
                }
            }
            break;
        case FMRDO_PEN_MAIN_MEMO_DOWN:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_MEMO_DOWN))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->memo_dec_button_area;
                point.x = pos.x - skin_p->memo_down_button_x;
                point.y = pos.y - skin_p->memo_down_button_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_press_memo_down_button();
                }
                else
                {
                    g_fmrdo.is_button_down = FALSE;
                    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
                    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
                }
            }
            break;
        case FMRDO_PEN_MAIN_MEMO_UP:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_MEMO_UP))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->memo_inc_button_area;
                point.x = pos.x - skin_p->memo_up_button_x;
                point.y = pos.y - skin_p->memo_up_button_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_press_memo_up_button();
                }
                else
                {
                    g_fmrdo.is_button_down = FALSE;
                    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
                    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
                }
            }
            break;
        case FMRDO_PEN_MAIN_POWER:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_POWER))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->power_button_area;
                point.x = pos.x - skin_p->power_button_x;
                point.y = pos.y - skin_p->power_button_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_press_power_button();
                }
                else
                {
                    g_fmrdo.is_button_down = FALSE;
                    mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_power_on, TRUE);
                    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
                }
            }
            break;
        case FMRDO_PEN_LSK:
            if (mmi_pen_check_inside_polygon(&LSK_area, pos))
            {
                mmi_fmrdo_redraw_main_LSK_down();
            }
            else
            {
                mmi_fmrdo_redraw_main_LSK_up();
                g_fmrdo.is_button_down = FALSE;
            }
            break;
        case FMRDO_PEN_RSK:
            if (mmi_pen_check_inside_polygon(&RSK_area, pos))
            {
                mmi_fmrdo_redraw_main_RSK_down();
            }
            else
            {
                mmi_fmrdo_redraw_main_RSK_up();
                g_fmrdo.is_button_down = FALSE;
            }
            break;
    #if defined(__MMI_FM_RADIO_RECORD__)
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT 
        case FMRDO_PEN_MAIN_REC:
            if (mmi_fmrdo_is_record_allowed())
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->record_button_area;
                point.x = pos.x - skin_p->rec_button_x;
                point.y = pos.y - skin_p->rec_button_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_press_record_button();
                }
                else
                {
                    g_fmrdo.is_button_down = MMI_FALSE;
                    mmi_fmrdo_redraw_main_toggle_button(
                            g_fmrdo.selected_button, 
                            g_fmrdo.is_button_down, 
                            TRUE, 
                            TRUE);
                    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
                }
            }
            break;
       #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    #endif 

    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT 
        case FMRDO_PEN_MAIN_VOL_MUTE:
            if (g_vol_displayed)
            {
                StartTimer(FMRDO_VOLUME_DISPLAY_TMER, 2000, mmi_fmrdo_reset_volume_bar);
                area = (mmi_pen_polygon_area_struct*) & skin_p->VOL_mute_area;
                point.x = pos.x - skin_p->volume_image_x;
                point.y = pos.y - skin_p->volume_image_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_press_toggle_mute();
                }
                else
                {
                    g_fmrdo.is_button_down = MMI_FALSE;
                    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
                }
            }
            break;
        case FMRDO_PEN_MAIN_VOL_TOUCH:
            if (!mmi_fmrdo_need_disable_push_button(FMRDO_BUTTON_VOLUME) && g_vol_displayed)
            {
                StartTimer(FMRDO_VOLUME_DISPLAY_TMER, 2000, mmi_fmrdo_reset_volume_bar);
            }
            break;
        case FMRDO_PEN_MAIN_VOL:
            if (g_vol_displayed)
            {
                StartTimer(FMRDO_VOLUME_DISPLAY_TMER, 2000, mmi_fmrdo_reset_volume_bar);
            }
            break;
        case FMRDO_PEN_MAIN_VOLUME_IND:
            if (g_vol_highlight)
            {
                StartTimer(FMRDO_VOLUME_DISPLAY_TMER, 2000, mmi_fmrdo_reset_volume_bar);
                area = (mmi_pen_polygon_area_struct*) & skin_p->VOL_area;
                point.x = pos.x - skin_p->volume_bar_x;
                point.y = pos.y - skin_p->volume_bar_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_translate_volume(&point, MMI_TRUE);
                }
                else
                {
                    g_fmrdo.is_button_down = MMI_FALSE;
                    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
                }
            }
            break;
      #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    #if defined(__MMI_FM_RADIO_RECORD__)

    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT 
        case FMRDO_PEN_MAIN_REC_STOP:
            area = (mmi_pen_polygon_area_struct*) & skin_p->record_stop_area;
            point.x = pos.x - skin_p->rec_tool_stop_x;
            point.y = pos.y - skin_p->rec_tool_stop_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_fmrdo_press_record_stop();
            }
            else
            {
                g_fmrdo.is_button_down = MMI_FALSE;
                mmi_fmrdo_redraw_bar_toggle_button(
                    g_fmrdo.selected_button,
                    g_fmrdo.is_button_down,
                    MMI_TRUE,
                    MMI_TRUE);
                g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
            }
            break;
        case FMRDO_PEN_MAIN_REC_PAUSE:
                area = (mmi_pen_polygon_area_struct*) & skin_p->record_pause_area;
                point.x = pos.x - skin_p->rec_tool_rec_x;
                point.y = pos.y - skin_p->rec_tool_rec_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_fmrdo_press_record_pause();
            }
            else
            {
                g_fmrdo.is_button_down = MMI_FALSE;
                mmi_fmrdo_redraw_bar_toggle_button(
                    g_fmrdo.selected_button,
                    g_fmrdo.is_button_down,
                    (g_fmrdo.state == FMRDO_STATE_RECORD),
                    MMI_TRUE);
                g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
            }
            break;
        #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT  */
    #endif 
    #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        case FMRDO_PEN_MAIN_KEY_ONLY_SPEAKER_MUTE:
            area = (mmi_pen_polygon_area_struct*) & skin_p->key_only_speaker_mute_area;
            point.x = pos.x - skin_p->speaker_image_x;
            point.y = pos.y - skin_p->speaker_image_y;
            if(mmi_pen_check_inside_polygon(area, point))
            {
                mmi_fmrdo_support_keyonly_toggle_press_mute();
            }
            else
            {
                g_fmrdo.is_button_down = MMI_FALSE;
                mmi_fmrdo_redraw_main_volume_key();
                g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
            }
            break;
    #endif
        default:
            wgui_status_icon_bar_translate_pen_event(
                MMI_PEN_EVENT_MOVE,
                pos.x,
                pos.y,
                &icon_id,
                &evt_type);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_pen_repeat_hdlr
 * DESCRIPTION
 *  Pen repeat event handler for main screen
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#endif /* __MMI_TOUCH_SCREEN__ */ 
/* MTK Leo end */

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_need_disable_push_button
 * DESCRIPTION
 *  Pen repeat event handler for main screen
 * PARAMETERS
 *  button     [IN]        selected button
 * RETURNS
 *  Disabled
 *****************************************************************************/
pBOOL mmi_fmrdo_need_disable_push_button(fmrdo_main_button_enum button)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (button)
    {
    case FMRDO_BUTTON_VOLUME:
        if (g_fmrdo.state == FMRDO_STATE_RECORD ||
    #ifdef __FM_RADIO_HW_SEARCH__
            g_fmrdo.state == FMRDO_STATE_SEARCH_ONE ||
    #endif 
    #if defined(__MMI_FM_RADIO_RECORD__)
            (animate_count != 0) ||
    #endif
            g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
        {
            return TRUE;
        }
        break;
    default:
        break;
    }
    return FALSE;
}
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */


#if defined(__MMI_FM_RADIO_RECORD__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_change_main_SK_record
 * DESCRIPTION
 *  Redraw main screen LSK and RSK for record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_change_main_SK_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_record_allow  = mmi_fmrdo_is_record_allowed();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_LSK_up();
    mmi_fmrdo_redraw_main_RSK_up();
    mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_STEP_UP, MMI_FALSE);
    mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_STEP_DOWN, MMI_FALSE);
    mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_MEMO_UP, MMI_FALSE);
    mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_MEMO_DOWN, MMI_FALSE);
#if defined(__MMI_FM_RADIO_RECORD__)
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_REC, MMI_FALSE, is_record_allow, TRUE);
#else
    mmi_fmrdo_redraw_main_volume_key();
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
#endif 
// TODO: modified for key only 2.0 , show grey button
    mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, g_fmrdo.is_button_down, FALSE, TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_change_main_SK_pause
 * DESCRIPTION
 *  Redraw main screen LSK and RSK for pause
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_change_main_SK_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_time_duration
 * DESCRIPTION
 *  Draw time duration for FM radio record
 * PARAMETERS
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_time_duration(BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    U32 rec_time = 4232;
    U16 hour, min, sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rec_time = (U32) (g_fmrdo.rec.duration * 0.004615 + 0.5);

    hour = rec_time / 3600;
    min = (rec_time - hour * 3600) / 60;
    sec = (rec_time - hour * 3600 - min * 60);

    x1 = fmrdo_main_draw.timer_hr_0_offset_x;
    y1 = fmrdo_main_draw.timer_offset_y;
    x2 = fmrdo_main_draw.timer_offset_x2 - 1;
    y2 = fmrdo_main_draw.timer_offset_y2 - 1;

    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    if (is_shown)
    {
        /* hh:mm:ss */
        gui_show_image(
            fmrdo_main_draw.timer_hr_0_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.rec_base_num_id + (hour / 10))));
        gui_show_image(
            fmrdo_main_draw.timer_hr_1_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.rec_base_num_id + (hour % 10))));
        gui_show_image(fmrdo_main_draw.timer_col_0_offset_x, y1, (PU8) GetImage(fmrdo_main_draw.rec_num_col_id));
        gui_show_image(
            fmrdo_main_draw.timer_min_0_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.rec_base_num_id + (min / 10))));
        gui_show_image(
            fmrdo_main_draw.timer_min_1_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.rec_base_num_id + (min % 10))));
        gui_show_image(fmrdo_main_draw.timer_col_1_offset_x, y1, (PU8) GetImage(fmrdo_main_draw.rec_num_col_id));
        gui_show_image(
            fmrdo_main_draw.timer_sec_0_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.rec_base_num_id + (sec / 10))));
        gui_show_image(
            fmrdo_main_draw.timer_sec_1_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.rec_base_num_id + (sec % 10))));
    }

    gdi_layer_pop_clip();
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);
}
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 


#ifdef __FM_RADIO_HW_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_change_main_SK_hw_searching
 * DESCRIPTION
 *  Redraw main screen LSK and RSK for record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_change_main_SK_hw_searching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_clear_main_RSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_clear_main_RSK(UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#endif /* __FM_RADIO_HW_SEARCH__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_set_alpha_blending_layer
 * DESCRIPTION
 *  Set alpha blending layer for displaying FM Radio components
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_set_alpha_blending_layer(BOOL set)
{
#ifdef __GDI_MEMORY_PROFILE_2__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (set)
    {
        if (count == 0)
        {
            gdi_push_and_set_alpha_blending_source_layer(fmrdo_skin_layer);
        }
        count++;
    }
    else
    {
        if (count == 1)
        {
            gdi_pop_and_restore_alpha_blending_source_layer();
        }
        count--;
    }
    ASSERT(count >= 0);
    
#endif
}


#if defined(__MMI_FM_RADIO_RECORD__)
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_record_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_record_bar(MMI_BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 y_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    y_offset = (UI_device_height - fmrdo_main_draw.rec_bar.y) / MMI_FMRDO_ANIMATE_FRAME_COUNT;
    x1 = 0;
    y1 = fmrdo_main_draw.rec_bar.y + ((MMI_FMRDO_ANIMATE_FRAME_COUNT - animate_count) * y_offset);
    x2 = fmrdo_main_draw.rec_bar.w;
    y2 = y1 + fmrdo_main_draw.rec_bar.h + y_offset; // to clear previous image
 
    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT); 
    if (is_shown)
    {
    #ifdef __MMI_FTE_SUPPORT_SLIM__
        gdi_image_draw_resized(x1,
                               y1,
                               fmrdo_main_draw.rec_bar.w,
                               fmrdo_main_draw.rec_bar.h,
                               fmrdo_main_draw.rec_bar.bg_img);
    #else
        gui_show_image(x1, y1, fmrdo_main_draw.rec_bar.bg_img);
    #endif /* __MMI_FTE_SUPPORT_SLIM__ */
        mmi_fmrdo_redraw_bar_toggle_button(FMRDO_BUTTON_REC_PAUSE, MMI_FALSE, MMI_TRUE, MMI_TRUE);
        mmi_fmrdo_redraw_bar_toggle_button(FMRDO_BUTTON_REC_STOP, MMI_FALSE, MMI_TRUE, MMI_TRUE);
    }

    gdi_layer_pop_clip();
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width, UI_device_height);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_update_record_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_update_record_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (animate_count < MMI_FMRDO_ANIMATE_FRAME_COUNT)
    {
        animate_count++;
        gui_start_timer(40, mmi_fmrdo_update_record_bar);
    }
    else
    {
        mmi_fmrdo_send_record_req();
        return;
    }
    mmi_fmrdo_redraw_main_record_bar(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hide_record_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_hide_record_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_record_bar(MMI_FALSE);
    animate_count = 0;
    mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_TRUE);
    mmi_fmrdo_redraw_record_frequency(g_fmrdo.frequency, MMI_FALSE);
    gui_cancel_timer(mmi_fmrdo_update_record_bar);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_start_record_bar_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_start_record_bar_animation()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (animate_count)
    {
        return;
    }
    animate_count = 0;
    mmi_fmrdo_redraw_record_frequency(g_fmrdo.frequency, MMI_TRUE);
    gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);
    mmi_fmrdo_hide_main_channel_name();
    StopTimer(FMRDO_TWINKLE_FREQUENCY_TIMER);
    StopTimer(FMRDO_VOLUME_DISPLAY_TMER);
    g_vol_displayed = 0;
    g_vol_highlight = 0;
    mmi_fmrdo_redraw_main_volumebar(g_fmrdo.volume, MMI_FALSE);
    mmi_fmrdo_update_record_bar();
}
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_disabled_buttons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_disabled_buttons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_record_allow  = mmi_fmrdo_is_record_allowed();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_fmrdo_hide_record_bar();
    #endif
    mmi_fmrdo_redraw_main_LSK_up();
    mmi_fmrdo_redraw_main_RSK_up();
    mmi_fmrdo_redraw_main_channel_name(0);
    mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_STEP_UP, MMI_FALSE);
    mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_STEP_DOWN, MMI_FALSE);
    mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_MEMO_UP, MMI_FALSE);
    mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_MEMO_DOWN, MMI_FALSE);
#if defined(__MMI_FM_RADIO_RECORD__)
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_REC, MMI_FALSE, is_record_allow, TRUE);
#else
    mmi_fmrdo_redraw_main_volume_key();
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
#endif 
}
#endif 

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_translate_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_translate_volume(mmi_pen_point_struct *point, MMI_BOOL move)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 start, vol_offset;
    S32 w, h;
    S32 touch_offset, bar_size;
    S32 diff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT_SLIM__
    w = FMRDO_VOLUME_TUNE_W;
    h = FMRDO_VOLUME_TUNE_H;
#else
    gui_measure_image(fmrdo_main_draw.vol_tune_img, &w, &h);
#endif /* __MMI_FTE_SUPPORT_SLIM__ */
    if (fmrdo_main_draw.volume.type == 0)   /* 0: horizontal, 1: vertical */
    {
        start = fmrdo_main_draw.volume.ind_left_gap;
        bar_size = w;
        touch_offset = point->x - start;
    }
    else
    {
        start = fmrdo_main_draw.volume.ind_top_gap;
        bar_size = h;
        touch_offset = point->y - start;
    }

    if (g_fmrdo.mute)
    {
        if (touch_offset < 0)
        {
            mmi_fmrdo_redraw_main_volumebar(g_fmrdo.volume, MMI_TRUE);
            return;
        }
        vol_offset = 0;
    }
    else
    {
        vol_offset = (g_fmrdo.volume + 1) * bar_size / MAX_VOL_LEVEL;
    }

    if (move)
    {
        diff = (touch_offset - vol_offset) * MAX_VOL_LEVEL / bar_size;
    }
    else
    {
        diff = touch_offset - vol_offset;
    }

    if (diff > 0)
    {
        mmi_fmrdo_inc_volume();
    }
    else if (diff < 0)
    {
        mmi_fmrdo_dec_volume();
    }
}

#endif

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_volume
 * DESCRIPTION
 *  Redraw volume indicator on main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_volume_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w,h;
    S32 speaker_x1, speaker_y1;
	S32	speaker_x2, speaker_y2;
    S32 volume_x1, volume_x2, volume_y1, volume_y2;
    
    S32 delta;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
#endif 

    gui_measure_image(fmrdo_main_draw.speaker_image_on_up, &w, &h);
    speaker_x1 = fmrdo_main_draw.speaker_image_x;
    speaker_y1 = fmrdo_main_draw.speaker_image_y;
	speaker_x2 = fmrdo_main_draw.speaker_image_x + w - 1;
	speaker_y2 = fmrdo_main_draw.speaker_image_y + h - 1;
    gui_measure_image(fmrdo_main_draw.volume_bg_image, &w, &h);
    volume_x1 = fmrdo_main_draw.volume_image_x;
    volume_y1 = fmrdo_main_draw.volume_image_y;
    volume_x2 = fmrdo_main_draw.volume_image_x + w - 1;
    volume_y2 = fmrdo_main_draw.volume_image_y + h - 1;
    
    gdi_layer_push_and_set_active(fmrdo_skin_layer);
    gdi_layer_push_and_set_clip(speaker_x1, speaker_y1, volume_x2, volume_y2);
	
    gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->sub_menu_bkg_filler);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
       
   gdi_layer_push_and_set_clip(speaker_x1, speaker_y1, volume_x2, volume_y2);
       
    if(g_fmrdo.mute)
    {
        if (g_fmrdo.is_button_down == TRUE)
        {
	        gdi_layer_push_and_set_active(fmrdo_skin_layer);
			gui_show_image(speaker_x1, speaker_y1, fmrdo_main_draw.speaker_image_off_up);
			gdi_layer_pop_and_restore_active();
			gdi_draw_solid_rect(speaker_x1, speaker_y1, speaker_x2, speaker_y2, GDI_COLOR_TRANSPARENT);
        	gui_show_image(speaker_x1, speaker_y1, fmrdo_main_draw.speaker_image_off_down);
        }
        else
        {
            gui_show_image(speaker_x1, speaker_y1, fmrdo_main_draw.speaker_image_off_up);
        }
            gui_show_image(volume_x1, volume_y1, fmrdo_main_draw.volume_bg_image);
    }
    else
    {
        if (g_fmrdo.is_button_down == TRUE)
        {
    	    gdi_layer_push_and_set_active(fmrdo_skin_layer);
	        gui_show_image(speaker_x1, speaker_y1, fmrdo_main_draw.speaker_image_on_up);
			gdi_layer_pop_and_restore_active();
			gdi_draw_solid_rect(speaker_x1, speaker_y1, speaker_x2, speaker_y2, GDI_COLOR_TRANSPARENT);
        	gui_show_image(speaker_x1, speaker_y1, fmrdo_main_draw.speaker_image_on_down);
        }
        else
        {
            gui_show_image(speaker_x1, speaker_y1, fmrdo_main_draw.speaker_image_on_up);
        }
        gui_show_image(volume_x1, volume_y1, fmrdo_main_draw.volume_bg_image);

    }

        delta = (((U32)g_fmrdo.volume) * w ) /(MAX_VOL_LEVEL - 1);
        if(!g_fmrdo.volume)
        {
            gdi_layer_set_clip(volume_x1, volume_y1, volume_x1 + delta, volume_y1);
        }
        else
        {
            gdi_layer_set_clip(volume_x1, volume_y1, volume_x1 + delta, volume_y2);
        }
        gui_show_image(volume_x1, volume_y1, fmrdo_main_draw.volume_fg_image);
    

    gdi_layer_pop_clip();
    
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
#endif 
    gdi_layer_blt_previous(speaker_x1, speaker_y1, volume_x2, volume_y2);
}

static void mmi_fmrdo_support_keyonly_toggle_press_mute(void)
{
     if (g_fmrdo.is_button_down)
    {
        return;
    }
    g_fmrdo.selected_button = FMRDO_BUTTON_SPEAKER;
    g_fmrdo.is_button_down = TRUE;

    mmi_fmrdo_redraw_main_volume_key();
}

static void mmi_fmrdo_support_keyonly_toggle_release_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_SPEAKER)
    {
        g_fmrdo.is_button_down = FALSE;
        if (g_fmrdo.mute && (g_fmrdo.volume == 0))
        {
            mmi_fmrdo_redraw_main_volume_key();
            return ;
        }
        
        g_fmrdo.mute = !g_fmrdo.mute;
        WriteValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
        if (g_fmrdo.mute)
        {
            g_fmrdo.prev_volume = g_fmrdo.volume;
            //mdi_fmr_mute(1);
            mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
        }
        else
        {
            //mdi_fmr_mute(0);
            mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_FALSE);
            mmi_fmrdo_set_volume(g_fmrdo.prev_volume);
        }
        mmi_fmrdo_redraw_main_volume_key();
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}

#if defined(__MMI_FM_RADIO_RECORD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_time_duration
 * DESCRIPTION
 *  Draw time duration for FM radio record
 * PARAMETERS
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_rec_sign(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1,y1,x2,y2;
    S32 w,h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    x1 = fmrdo_main_draw.rec_sgn_x;
    y1 = fmrdo_main_draw.rec_sgn_y;

    gui_measure_image(fmrdo_main_draw.rec_sgn_img, &w, &h);

    x2 = x1 + w;
    y2 = y1 + h;

    gdi_layer_lock_frame_buffer();
    mmi_fmrdo_set_alpha_blending_layer(TRUE);
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);

    if (g_fmrdo.state == FMRDO_STATE_RECORD)
    {
        gui_show_image(x1,y1, fmrdo_main_draw.rec_sgn_img);
    }
    else if(g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
        gui_show_image(x1,y1,fmrdo_main_draw.rec_sgn_pause_img);
    }

    gdi_layer_pop_clip();
    mmi_fmrdo_set_alpha_blending_layer(FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);
}
#endif /* defined(__MMI_FM_RADIO_RECORD__) */

#endif /*MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT*/

#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_FM_RADIO__ */ 

