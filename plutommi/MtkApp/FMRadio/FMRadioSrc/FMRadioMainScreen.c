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
*  FMRadioMainScreen.c
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__
#ifndef __MMI_FTE_SUPPORT__


#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#include "FMRadioMainScreen.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "kal_non_specific_general_types.h"
#include "gui_data_types.h"
#include "gui.h"
#include "CustDataRes.h"
#include "gdi_include.h"
#include "lcd_sw_inc.h"
#include "lcd_sw_rnd.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "gui_windows.h"
#include "gui_config.h"
#include "ScreenRotationGprot.h"
#include "mmi_rp_app_fmrdo_def.h"
#include "gui_themes.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "GlobalResDef.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "gui_font_size.h"
#include "PixcomFontEngine.h"

#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
#include "CustThemesRes.h"
extern MMI_theme *current_MMI_theme;
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 

#ifdef __MMI_FM_RADIO_ANIMATION__
#ifdef __RF_DESENSE_TEST__
#include "rf_desense_test.h"
#endif /*__RF_DESENSE_TEST__*/
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

#ifdef __MMI_SLIM_IMG_RES__
#define MMI_FMRDO_SLIM_BG_COLOR  gdi_act_color_from_rgb(255, 248, 248, 248)
#endif /* __MMI_SLIM_IMG_RES__ */

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
#define FMRDO_FALG_CLEAR(f)         ((f) = 0 )
#define FMRDO_FLAG_CHECK(f, b)      ((f) & (b))

typedef enum
{
    FMRDO_BTN_STATE_UP,
    FMRDO_BTN_STATE_DOWN,
    FMRDO_BTN_STATE_DISABLE,
    FMRDO_BTN_TOTAL
} fmrdo_btn_state_enum;


typedef struct
{
    S32 flag;
#ifdef __MMI_TOUCH_SCREEN__
    S32                         pen_event;
    mmi_pen_point_struct        LSK_points[4];
    mmi_pen_point_struct        RSK_points[4];
    mmi_pen_polygon_area_struct LSK_area;
    mmi_pen_polygon_area_struct RSK_area;
#endif

#ifdef __MMI_FM_RADIO_ANIMATION__
    gdi_handle  anim_layer;
    U8*         anim_layer_buf;
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_handle  osd_layer;
    gdi_handle  skin_layer;
    MMI_BOOL    is_skin_layer_drawn;
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

#ifdef __MMI_FM_RADIO_RDS__
    U16         rds_str1[MMI_FMRDO_RDS_PS_NAME_SIZE + MMI_FMRDO_RDS_RT_SIZE + 2];
#endif/*__MMI_FM_RADIO_RDS__*/

} fmrdo_main_draw_cntx;

static fmrdo_main_draw_cntx  *fmrdo_draw_cntx_p;
static fmrdo_main_draw_struct fmrdo_main_draw;  /* all memeber variables are zero initial */

extern mmi_fmrdo_struct g_fmrdo;                    /* defined in FMRadioSrc.c */
extern S32 UI_device_width;                         /* from gui_wrapper.c */
extern S32 UI_device_height;                        /* from gui_wrapper.c */
extern const mmi_fmrdo_skin_struct g_fmrdo_skins[]; /* defined in resource_fmradio_skins.c */
 

extern void kal_wsprintf(unsigned short *outstr, char *fmt, ...);

#if 0
/* under construction !*/
#endif

#ifdef __MMI_TOUCH_SCREEN__
/* MTK Leo add 20050301, add touch screen support for FM Radio */
typedef enum
{
    FMRDO_PEN_NONE,
    FMRDO_PEN_LSK,
    FMRDO_PEN_RSK,
    FMRDO_PEN_MAIN_STEP_UP,
    FMRDO_PEN_MAIN_STEP_DOWN,
    FMRDO_PEN_MAIN_POWER,
#ifdef __MMI_SLIM_IMG_RES__
    FMRDO_PEN_MAIN_SEARCH_UP,
    FMRDO_PEN_MAIN_SEARCH_DOWN,
#else
    FMRDO_PEN_MAIN_SEARCH,
    FMRDO_PEN_MAIN_SETTING,
    FMRDO_PEN_MAIN_VOLUME_INC,
    FMRDO_PEN_MAIN_VOLUME_DEC,
#endif /* __MMI_SLIM_IMG_RES__ */
    FMRDO_PEN_COUNT
} FMRDO_PEN_STATE;
typedef enum
{
    FMRDO_PEN_SK_UP,
    FMRDO_PEN_SK_DOWN
} FMRDO_SOFTKEY_STATE;
/* MTK Leo end */
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_init_for_theme
 * DESCRIPTION
 *  init colors and background image when theme changed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_init_for_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO_RDS__
   fmrdo_main_draw.rds_text_color = *(current_MMI_theme->title_text_color);
   fmrdo_main_draw.rds_text_border_color = *(current_MMI_theme->title_text_border_color);
#endif/*__MMI_FM_RADIO_RDS__*/

}
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 


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
    S32 w, h;

#if defined(__MMI_FM_RADIO_RECORD__)
    S32 w2, h2;
#endif 
    const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[skin_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
//    mmi_fmrdo_init_for_theme();
#else /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 

#if  defined (__MMI_SLIM_IMG_RES__)

#endif /* __MMI_SLIM_IMG_RES__ */

#ifdef __MMI_FM_RADIO_RDS__
    fmrdo_main_draw.rds_text_border_color = gui_color(
                                                        skin_p->rds_text_border_color_r,
                                                        skin_p->rds_text_border_color_g,
                                                        skin_p->rds_text_border_color_b);
    fmrdo_main_draw.rds_text_color = gui_color(
                                                skin_p->rds_text_color_r,
                                                skin_p->rds_text_color_g,
                                                skin_p->rds_text_color_b);
#endif/*__MMI_FM_RADIO_RDS__*/

#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 

#ifdef __MMI_SLIM_IMG_RES__
    fmrdo_main_draw.btn_bg_img = (PU8) GetImage(skin_p->button_bg_img_id);
    fmrdo_main_draw.btn_hl_img = (PU8) GetImage(skin_p->button_hl_img_id);
    fmrdo_main_draw.btn_disable_img = (PU8) GetImage(skin_p->button_disable_img_id);
    fmrdo_main_draw.title_bg_img = (PU8) GetImage(skin_p->title_bg_image_id);
    gdi_image_get_dimension_id(skin_p->button_bg_img_id, &w, &h);
    fmrdo_main_draw.btn_bg_w = w;
    fmrdo_main_draw.btn_bg_h = h;
#else
    /* background */
    fmrdo_main_draw.bg_img = (PU8) GetImage(skin_p->bg_image_id);
#endif /* __MMI_SLIM_IMG_RES__ */

    /* channel name */
    fmrdo_main_draw.channel_name.x = skin_p->channel_name_x;
    fmrdo_main_draw.channel_name.y = skin_p->channel_name_y;
    fmrdo_main_draw.channel_name.w = skin_p->channel_name_w;
    fmrdo_main_draw.channel_name.h = skin_p->channel_name_h;
#ifdef __MMI_FM_RADIO_RDS__
    fmrdo_main_draw.rds_text.x = skin_p->rds_text_x;
    fmrdo_main_draw.rds_text.y = skin_p->rds_text_y;
    fmrdo_main_draw.rds_text.w = skin_p->rds_text_w;
    fmrdo_main_draw.rds_text.h = skin_p->rds_text_h;
#endif/*__MMI_FM_RADIO_RDS__*/

    /* frequency */
    fmrdo_main_draw.frequency.x = skin_p->frequency_x;
    fmrdo_main_draw.frequency.y = skin_p->frequency_y;
    fmrdo_main_draw.frequency.w = skin_p->frequency_w;
    fmrdo_main_draw.frequency.h = skin_p->frequency_h;
#ifdef __MMI_SLIM_IMG_RES__
    fmrdo_main_draw.title.x = skin_p->title_x;
    fmrdo_main_draw.title.y = skin_p->title_y;
    fmrdo_main_draw.title.w = skin_p->title_w;
    fmrdo_main_draw.title.h = skin_p->title_h;
    
    fmrdo_main_draw.label.x = skin_p->label_x;
    fmrdo_main_draw.label.y = skin_p->label_y;
    fmrdo_main_draw.label.w = skin_p->label_w;
    fmrdo_main_draw.label.h = skin_p->label_h;
#endif /* __MMI_SLIM_IMG_RES__ */

    /* volume */
#ifdef __MMI_SLIM_IMG_RES__
    fmrdo_main_draw.volume.bg_img = (PU8) GetImage(skin_p->volume_bg_image_id);
#endif /* __MMI_SLIM_IMG_RES__ */
    fmrdo_main_draw.volume.fg_img = (PU8) GetImage(skin_p->volume_image_id);
    fmrdo_main_draw.volume.type = skin_p->volume_bar_type;  /* 0: horizontal, 1: vertical */
    fmrdo_main_draw.volume.x = skin_p->volume_bar_x;
    fmrdo_main_draw.volume.y = skin_p->volume_bar_y;
    gui_measure_image(fmrdo_main_draw.volume.fg_img, &w, &h);
    fmrdo_main_draw.volume.w = (S16) w;
    fmrdo_main_draw.volume.h = (S16) h;
    fmrdo_main_draw.volume.ind_start_gap = skin_p->volume_ind_start_gap;
    fmrdo_main_draw.volume.ind_end_gap = skin_p->volume_ind_end_gap;

#ifdef __MMI_FM_RADIO_ANIMATION__
    /* animation */
#ifdef __RF_DESENSE_TEST__
    if( rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION )
#endif /*__RF_DESENSE_TEST__*/
    {
    #ifdef __MMI_FM_SKIN_SYN_TO_THEME__
        fmrdo_main_draw.animation.x = 0;
        fmrdo_main_draw.animation.y = 0;
    #else /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 
        fmrdo_main_draw.animation.x = skin_p->animation_x;
        fmrdo_main_draw.animation.y = skin_p->animation_y;
    #endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 
        fmrdo_main_draw.animation.animation_img = (PU8) GetImage(skin_p->animation_image_id);
    }
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

#if (defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_SLIM_IMG_RES__)))
    /* volume inc & dec control */
    fmrdo_main_draw.volume_inc_button.x = skin_p->volume_inc_x;
    fmrdo_main_draw.volume_inc_button.y = skin_p->volume_inc_y;
    fmrdo_main_draw.volume_inc_button.up_img = (PU8) GetImage(skin_p->volume_inc_up_image_id);
    fmrdo_main_draw.volume_inc_button.down_img = (PU8) GetImage(skin_p->volume_inc_down_image_id);
    gui_measure_image(fmrdo_main_draw.volume_inc_button.up_img, &w, &h);
    fmrdo_main_draw.volume_inc_button.w = (S16) w;
    fmrdo_main_draw.volume_inc_button.h = (S16) h;
    fmrdo_main_draw.volume_inc_button.down = MMI_FALSE;

    fmrdo_main_draw.volume_dec_button.x = skin_p->volume_dec_x;
    fmrdo_main_draw.volume_dec_button.y = skin_p->volume_dec_y;
    fmrdo_main_draw.volume_dec_button.up_img = (PU8) GetImage(skin_p->volume_dec_up_image_id);
    fmrdo_main_draw.volume_dec_button.down_img = (PU8) GetImage(skin_p->volume_dec_down_image_id);
    gui_measure_image(fmrdo_main_draw.volume_dec_button.up_img, &w, &h);
    fmrdo_main_draw.volume_dec_button.w = (S16) w;
    fmrdo_main_draw.volume_dec_button.h = (S16) h;
    fmrdo_main_draw.volume_dec_button.down = MMI_FALSE;

    /* setting icon */
    fmrdo_main_draw.setting_button.x = skin_p->setting_x;
    fmrdo_main_draw.setting_button.y = skin_p->setting_y;
    fmrdo_main_draw.setting_button.up_img = (PU8) GetImage(skin_p->setting_up_image_id);
    fmrdo_main_draw.setting_button.down_img = (PU8) GetImage(skin_p->setting_down_image_id);
    gui_measure_image(fmrdo_main_draw.setting_button.up_img, &w, &h);
    fmrdo_main_draw.setting_button.w = (S16) w;
    fmrdo_main_draw.setting_button.h = (S16) h;
    fmrdo_main_draw.setting_button.down = MMI_FALSE;
    fmrdo_main_draw.volume_inc_button.dis_img = (PU8) GetImage(skin_p->volume_inc_disable_image_id);
    fmrdo_main_draw.volume_dec_button.dis_img = (PU8) GetImage(skin_p->volume_dec_disable_image_id);
#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    fmrdo_main_draw.setting_button.dis_img = (PU8) GetImage(skin_p->setting_disable_image_id);
#else 
    fmrdo_main_draw.setting_button.dis_img = NULL;
#endif 
#endif /* (defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_SLIM_IMG_RES__))) */ 

    /* tuner scale */
    fmrdo_main_draw.tuner_scale.bg_img = (PU8) GetImage(skin_p->tuner_scale_bg_image_id);
    fmrdo_main_draw.tuner_scale.ind_img = (PU8) GetImage(skin_p->tuner_scale_ind_image_id);
    fmrdo_main_draw.tuner_scale.type = skin_p->tuner_scale_type;        /* 0: horizontal, 1: vertical */
    fmrdo_main_draw.tuner_scale.x = skin_p->tuner_scale_x;
    fmrdo_main_draw.tuner_scale.y = skin_p->tuner_scale_y;
    gui_measure_image(fmrdo_main_draw.tuner_scale.bg_img, &w, &h);
    fmrdo_main_draw.tuner_scale.w = (S16) w;
    fmrdo_main_draw.tuner_scale.h = (S16) h;
    gui_measure_image(fmrdo_main_draw.tuner_scale.ind_img, &w, &h);
    fmrdo_main_draw.tuner_scale.ind_w = (S16) w;
    fmrdo_main_draw.tuner_scale.ind_h = (S16) h;
    fmrdo_main_draw.tuner_scale.ind_offset = skin_p->tunner_scale_ind_offset;
    fmrdo_main_draw.tuner_scale.ind_start_gap = skin_p->tuner_scale_start_gap;
    fmrdo_main_draw.tuner_scale.ind_end_gap = skin_p->tuner_scale_end_gap;

    /* step down button */
    fmrdo_main_draw.step_down_button.up_img = (PU8) GetImage(skin_p->step_down_button_up_image_id);
    fmrdo_main_draw.step_down_button.down_img = (PU8) GetImage(skin_p->step_down_button_down_image_id);
    fmrdo_main_draw.step_down_button.x = skin_p->step_down_button_x;
    fmrdo_main_draw.step_down_button.y = skin_p->step_down_button_y;
    gui_measure_image(fmrdo_main_draw.step_down_button.up_img, &w, &h);
    fmrdo_main_draw.step_down_button.w = (S16) w;
    fmrdo_main_draw.step_down_button.h = (S16) h;

    /* step up button */
    fmrdo_main_draw.step_up_button.up_img = (PU8) GetImage(skin_p->step_up_button_up_image_id);
    fmrdo_main_draw.step_up_button.down_img = (PU8) GetImage(skin_p->step_up_button_down_image_id);
    fmrdo_main_draw.step_up_button.x = skin_p->step_up_button_x;
    fmrdo_main_draw.step_up_button.y = skin_p->step_up_button_y;
    gui_measure_image(fmrdo_main_draw.step_up_button.up_img, &w, &h);
    fmrdo_main_draw.step_up_button.w = (S16) w;
    fmrdo_main_draw.step_up_button.h = (S16) h;

#ifdef __MMI_SLIM_IMG_RES__
    /* search down button */
    fmrdo_main_draw.search_down_button.up_img = (PU8) GetImage(skin_p->search_down_button_up_image_id);
    fmrdo_main_draw.search_down_button.down_img = (PU8) GetImage(skin_p->search_down_button_down_image_id);
    fmrdo_main_draw.search_down_button.x = skin_p->search_down_button_x;
    fmrdo_main_draw.search_down_button.y = skin_p->search_down_button_y;
    gui_measure_image(fmrdo_main_draw.search_down_button.up_img, &w, &h);
    fmrdo_main_draw.search_down_button.w = (S16) w;
    fmrdo_main_draw.search_down_button.h = (S16) h;

    /* search up button */
    fmrdo_main_draw.search_up_button.up_img = (PU8) GetImage(skin_p->search_up_button_up_image_id);
    fmrdo_main_draw.search_up_button.down_img = (PU8) GetImage(skin_p->search_up_button_down_image_id);
    fmrdo_main_draw.search_up_button.x = skin_p->search_up_button_x;
    fmrdo_main_draw.search_up_button.y = skin_p->search_up_button_y;
    gui_measure_image(fmrdo_main_draw.search_up_button.up_img, &w, &h);
    fmrdo_main_draw.search_up_button.w = (S16) w;
    fmrdo_main_draw.search_up_button.h = (S16) h;
#else /* __MMI_SLIM_IMG_RES__ */
    /* search button */
    fmrdo_main_draw.search_button.on_up_img = (PU8) GetImage(skin_p->search_button_on_up_image_id);
    fmrdo_main_draw.search_button.on_down_img = (PU8) GetImage(skin_p->search_button_on_down_image_id);
    fmrdo_main_draw.search_button.off_up_img = (PU8) GetImage(skin_p->search_button_off_up_image_id);
    fmrdo_main_draw.search_button.off_down_img = (PU8) GetImage(skin_p->search_button_off_down_image_id);
    fmrdo_main_draw.search_button.x = skin_p->search_button_x;
    fmrdo_main_draw.search_button.y = skin_p->search_button_y;
    gui_measure_image(fmrdo_main_draw.search_button.on_up_img, &w, &h);
    fmrdo_main_draw.search_button.w = (S16) w;
    fmrdo_main_draw.search_button.h = (S16) h;
#endif /* __MMI_SLIM_IMG_RES__ */

    /* power button */
    fmrdo_main_draw.power_button.on_up_img = (PU8) GetImage(skin_p->power_button_on_up_image_id);
    fmrdo_main_draw.power_button.on_down_img = (PU8) GetImage(skin_p->power_button_on_down_image_id);
    fmrdo_main_draw.power_button.off_up_img = (PU8) GetImage(skin_p->power_button_off_up_image_id);
    fmrdo_main_draw.power_button.off_down_img = (PU8) GetImage(skin_p->power_button_off_down_image_id);
    fmrdo_main_draw.power_button.x = skin_p->power_button_x;
    fmrdo_main_draw.power_button.y = skin_p->power_button_y;
    gui_measure_image(fmrdo_main_draw.power_button.on_up_img, &w, &h);
    fmrdo_main_draw.power_button.w = (S16) w;
    fmrdo_main_draw.power_button.h = (S16) h;
#ifdef __MMI_FM_RADIO_RDS__
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

#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    fmrdo_main_draw.step_down_button.dis_img = (PU8) GetImage(skin_p->step_down_button_disable_image_id);
    fmrdo_main_draw.step_up_button.dis_img = (PU8) GetImage(skin_p->step_up_button_disable_image_id);
    fmrdo_main_draw.search_button.dis_img = (PU8) GetImage(skin_p->search_button_disable_image_id);
    fmrdo_main_draw.power_button.dis_img = (PU8) GetImage(skin_p->power_button_disable_image_id);
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 
#if defined(__MMI_FM_RADIO_RECORD__)
    /* Record Indication Icon */
    fmrdo_main_draw.rec_button.on_up_img = (PU8) GetImage(skin_p->rec_button_image_id); /* Use same image for all */
    fmrdo_main_draw.rec_button.on_down_img = (PU8) GetImage(skin_p->rec_button_image_id);
    fmrdo_main_draw.rec_button.off_up_img = (PU8) GetImage(skin_p->rec_button_image_id);
    fmrdo_main_draw.rec_button.off_down_img = (PU8) GetImage(skin_p->rec_button_image_id);
#if (defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FM_SKIN_SYN_TO_THEME__))
    fmrdo_main_draw.rec_button.dis_img = (PU8) GetImage(skin_p->rec_button_dis_image_id);
    fmrdo_main_draw.rec_pause_button.dis_img = (PU8) NULL;
#endif 
    fmrdo_main_draw.rec_button.x = skin_p->rec_button_x;
    fmrdo_main_draw.rec_button.y = skin_p->rec_button_y;
    gui_measure_image(fmrdo_main_draw.rec_button.on_up_img, &w, &h);
    fmrdo_main_draw.rec_button.w = (S16) w;
    fmrdo_main_draw.rec_button.h = (S16) h;

    /* Pause Indication Icon */
    fmrdo_main_draw.rec_pause_button.on_up_img = (PU8) GetImage(skin_p->rec_pause_button_image_id);     /* Use same image for all */
    fmrdo_main_draw.rec_pause_button.on_down_img = (PU8) GetImage(skin_p->rec_pause_button_image_id);
    fmrdo_main_draw.rec_pause_button.off_up_img = (PU8) GetImage(skin_p->rec_pause_button_image_id);
    fmrdo_main_draw.rec_pause_button.off_down_img = (PU8) GetImage(skin_p->rec_pause_button_image_id);
    fmrdo_main_draw.rec_pause_button.x = skin_p->rec_button_x;
    fmrdo_main_draw.rec_pause_button.y = skin_p->rec_button_y;
    gui_measure_image(fmrdo_main_draw.rec_pause_button.on_up_img, &w, &h);
    fmrdo_main_draw.rec_pause_button.w = (S16) w;
    fmrdo_main_draw.rec_pause_button.h = (S16) h;

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
#ifdef __MMI_SLIM_IMG_RES__
    fmrdo_main_draw.timer_hr_1_offset_x += 2;
    fmrdo_main_draw.timer_col_0_offset_x += 2;
    fmrdo_main_draw.timer_min_0_offset_x += 2;
    fmrdo_main_draw.timer_min_1_offset_x += 4;
    fmrdo_main_draw.timer_col_1_offset_x += 4;
    fmrdo_main_draw.timer_sec_0_offset_x += 4;
    fmrdo_main_draw.timer_sec_1_offset_x += 6;
#endif /* __MMI_SLIM_IMG_RES__ */

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
#if (defined(__MMI_FM_SKIN_SYN_TO_THEME__) && defined(__MMI_FM_RADIO_ANIMATION__))
    S32 width, height, bufsize;
#endif 
    const S32 cntx_size = sizeof(fmrdo_main_draw_cntx);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Init images, always get image in ENFB project */
	if(!g_fmrdo.in_main_screen)
	{	
		return;
	}
    if (!fmrdo_main_draw.is_ready /*|| fmrdo_main_draw.skin_index != skin_index*/)
    {
        mmi_fmrdo_init_main_images(skin_index);
//        fmrdo_main_draw.skin_index = skin_index;
        fmrdo_main_draw.is_ready = MMI_TRUE;
        fmrdo_main_draw.is_channel_name_scroll_ready = MMI_FALSE;
#ifdef __MMI_FM_RADIO_RDS__
        fmrdo_main_draw.is_rds_text_scroll_ready = MMI_FALSE;
#endif
    }

    //allocate draw context memory
    fmrdo_draw_cntx_p = (fmrdo_main_draw_cntx*) mmi_frm_scrmem_alloc_framebuffer(cntx_size);
    memset(fmrdo_draw_cntx_p, 0, cntx_size);

#ifdef __MMI_TOUCH_SCREEN__
    fmrdo_draw_cntx_p->LSK_area.num = 4;
    fmrdo_draw_cntx_p->LSK_area.points = fmrdo_draw_cntx_p->LSK_points;
    fmrdo_draw_cntx_p->RSK_area.num = 4;
    fmrdo_draw_cntx_p->RSK_area.points = fmrdo_draw_cntx_p->RSK_points;
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_multi_layer_enable();

    /* get base layer as skin layer */
    gdi_layer_get_base_handle(&fmrdo_draw_cntx_p->osd_layer);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_create(0, 0, UI_device_width, UI_device_height, &fmrdo_draw_cntx_p->skin_layer);

#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
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
    fmrdo_draw_cntx_p->anim_layer_buf = (U8*) mmi_frm_scrmem_alloc_framebuffer(bufsize);
    if (NULL == fmrdo_draw_cntx_p->anim_layer_buf)
    {
        fmrdo_draw_cntx_p->anim_layer_buf = (U8*) mmi_frm_scrmem_alloc_framebuffer(FMRDO_ANIM_BUFFER_SIZE_BASIC);
        MMI_ASSERT(fmrdo_draw_cntx_p->anim_layer_buf != NULL);
        gdi_layer_create_using_outside_memory(
            g_fmrdo_skins[skin_index].animation_x,
            g_fmrdo_skins[skin_index].animation_y,
            FMRDO_ANIM_SIZE_BASIC_WIDTH,    /* animation minimum width on HVGA size */
            FMRDO_ANIM_SIZE_BASIC_HEIGHT,   /* animation minimum height on HVGA size */
            &fmrdo_draw_cntx_p->anim_layer,
            (PU8) fmrdo_draw_cntx_p->anim_layer_buf,
            (S32) FMRDO_ANIM_BUFFER_SIZE_BASIC);
    }
    else
    {
        gdi_layer_create_using_outside_memory(
            g_fmrdo_skins[skin_index].animation_x,
            g_fmrdo_skins[skin_index].animation_y,
            width,
            height,
            &fmrdo_draw_cntx_p->anim_layer,
            (PU8) fmrdo_draw_cntx_p->anim_layer_buf,
            (S32) bufsize);
    }
    gdi_layer_push_and_set_active(fmrdo_draw_cntx_p->anim_layer);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    gdi_layer_set_blt_layer(fmrdo_draw_cntx_p->skin_layer, 
                            fmrdo_draw_cntx_p->anim_layer, 
                            fmrdo_draw_cntx_p->osd_layer, 
                            0);
}
#else /* __MMI_FM_RADIO_ANIMATION__ */ 
    gdi_layer_set_blt_layer(fmrdo_draw_cntx_p->skin_layer, fmrdo_draw_cntx_p->osd_layer, 0, 0);
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 
#else /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 
    gdi_layer_set_blt_layer(fmrdo_draw_cntx_p->skin_layer, fmrdo_draw_cntx_p->osd_layer, 0, 0);
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
    fmrdo_draw_cntx_p->is_skin_layer_drawn = MMI_FALSE;
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

//    clear_key_handlers();
//    clear_left_softkey();
//    clear_right_softkey();
//    fmrdo_main_draw.LSK_text = (UI_string_type) GetString(left_softkey);
//    fmrdo_main_draw.RSK_text = (UI_string_type) GetString(right_softkey);
    set_softkey_label(get_string(STR_GLOBAL_OPTIONS), MMI_LEFT_SOFTKEY);
    set_softkey_label(get_string(STR_GLOBAL_BACK), MMI_RIGHT_SOFTKEY);

    SetKeyDownHandler(mmi_fmrdo_redraw_main_LSK_down, KEY_LSK);
    SetKeyDownHandler(mmi_fmrdo_redraw_main_RSK_down, KEY_RSK);

    /* associate functions */
    ExitCategoryFunction = mmi_fmrdo_hide_main;
    RedrawCategoryFunction = mmi_fmrdo_redraw_main_all;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    /* draw screen */
    mmi_fmrdo_redraw_main_all();
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif 
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


#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_flatten_to_base(fmrdo_draw_cntx_p->skin_layer, fmrdo_draw_cntx_p->osd_layer, 0, 0);

#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
#ifdef __MMI_FM_RADIO_ANIMATION__
#ifdef __RF_DESENSE_TEST__  
    if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
#endif /*__RF_DESENSE_TEST__*/
    {
        gdi_layer_free(fmrdo_draw_cntx_p->fmrdo_draw_cntx_p->anim_layer);
        mmi_frm_scrmem_free((void*)fmrdo_draw_cntx_p->anim_layer_buf);
        fmrdo_draw_cntx_p->anim_layer_buf = NULL;
    }
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 

    gdi_layer_free(fmrdo_draw_cntx_p->skin_layer);
    fmrdo_draw_cntx_p->skin_layer = NULL;
    gdi_layer_multi_layer_disable();

    /* restore blt layer as base layer only */
    gdi_layer_set_blt_layer(fmrdo_draw_cntx_p->osd_layer, 0, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
#if (defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_SLIM_IMG_RES__)))

    fmrdo_main_draw.volume_dec_button.down = MMI_FALSE;
    fmrdo_main_draw.volume_inc_button.down = MMI_FALSE;
    fmrdo_main_draw.setting_button.down = MMI_FALSE;

    fmrdo_draw_cntx_p->pen_event = FMRDO_PEN_NONE;
#endif /* (defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_SLIM_IMG_RES__))) */ 

#ifdef __MMI_FM_RADIO_ANIMATION__
    /* stop animation */
#ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
    if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
#endif /*__RF_DESENSE_TEST__*/
    {
        mmi_fmrdo_animation_stop();
    }
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

    //ry: release screnn meme
    if (NULL != fmrdo_draw_cntx_p)
    {
        mmi_frm_scrmem_free((void*)fmrdo_draw_cntx_p);
        fmrdo_draw_cntx_p = NULL;
    }

    /* associate functions */
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


void mmi_fmrdo_sk_config_set(void)
{
    register_default_hide_softkeys();
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(fmrdo_draw_cntx_p->osd_layer);
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif /*__GDI_MEMORY_PROFILE_2__*/
}


void mmi_fmrdo_sk_config_reset(void)
{
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
    gdi_layer_pop_and_restore_active();
#endif 
}


void mmi_fmrdo_change_sk(UI_string_type lsk_str, UI_string_type rsk_str)
{
    set_softkey_label(lsk_str, MMI_LEFT_SOFTKEY);
    set_softkey_label(rsk_str, MMI_RIGHT_SOFTKEY);

    reset_softkeys();
    mmi_fmrdo_sk_config_set();
    wgui_softkey_update();
    mmi_fmrdo_sk_config_reset();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_update_sk_area
 * DESCRIPTION
 *  P0 +------------+ p1
 *     |            |
 *     |            |
 *  p3 +----------- + p2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_update_sk_area(mmi_pen_point_struct *points, S32 x, S32 y, S32 w, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    points[0].y = points[1].y = y;
    points[2].y = points[3].y = y + h;
    if (mmi_fe_get_r2l_state())
    {
        points[0].x = points[3].x = x - w;
        points[1].x = points[2].x = x + 1; /* +1 for pen down case, sync with FW*/
     
    }
    else
    {
        points[0].x = points[3].x = x;
        points[1].x = points[2].x = x + w + 1; /* +1 for pen down case, sync with FW*/
    }
#endif /* __MMI_TOUCH_SCREEN__ */
}


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
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
#endif /* __MMI_TOUCH_SCREEN__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
    #endif /* __MMI_TOUCH_SCREEN__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
    #endif /* __MMI_TOUCH_SCREEN__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                        #ifdef __MMI_SCREEN_ROTATE__ 
/* under construction !*/
                        #else
/* under construction !*/
                        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TOUCH_SCREEN__ */
/* under construction !*/
/* under construction !*/
#ifdef __GDI_MEMORY_PROFILE_2__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __GDI_MEMORY_PROFILE_2__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_draw_button
 * DESCRIPTION
 *  draw button
 * PARAMETERS
 *  button      [IN]        
 *  x1          [IN]
 *  y1          [IN]
 *  x2          [IN]
 *  y2          [IN]
 *  is_down     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fmrdo_util_draw_button(PU8 img, const fmrdo_main_rect_struct *rect, fmrdo_btn_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bg_x1 = rect->x;
    S32 bg_y1 = rect->y;
#ifdef __MMI_SLIM_IMG_RES__
    S32 bg_x2 = bg_x1 + fmrdo_main_draw.btn_bg_w - 1;
    S32 bg_y2 = bg_y1 + fmrdo_main_draw.btn_bg_h - 1;
    S32 btn_x = bg_x1 + ((fmrdo_main_draw.btn_bg_w - rect->w) >> 1);
    S32 btn_y = bg_y1 + ((fmrdo_main_draw.btn_bg_h - rect->h) >> 1);
#else
    S32 bg_x2 = bg_x1 + rect->w - 1;
    S32 bg_y2 = bg_y1 + rect->h - 1;
#endif /* __MMI_SLIM_IMG_RES__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif
    gdi_layer_push_and_set_clip(bg_x1, bg_y1, bg_x2, bg_y2);

    if (NULL != img)
    {
    #ifdef __MMI_SLIM_IMG_RES__
        gui_show_image(bg_x1, bg_y1, fmrdo_main_draw.btn_bg_img);
        gui_show_image(btn_x, btn_y, img);
        if (FMRDO_BTN_STATE_UP != state)
        {
            PU8 img;
            img = (FMRDO_BTN_STATE_DOWN == state) ? 
                  fmrdo_main_draw.btn_hl_img : 
                  fmrdo_main_draw.btn_disable_img;
        #ifdef __GDI_MEMORY_PROFILE_2__
            gdi_push_and_set_alpha_blending_source_layer(fmrdo_draw_cntx_p->osd_layer);
        #endif /* __GDI_MEMORY_PROFILE_2__ */
            gdi_image_draw_resized(
                            bg_x1 + 1, 
                            bg_y1 + 1, 
                            fmrdo_main_draw.btn_bg_w - 2 , 
                            fmrdo_main_draw.btn_bg_h - 2, 
                            img);
        #ifdef __GDI_MEMORY_PROFILE_2__
            gdi_pop_and_restore_alpha_blending_source_layer();
        #endif /* __GDI_MEMORY_PROFILE_2__ */
        }
    #else /* __MMI_SLIM_IMG_RES__ */
        gui_show_image(bg_x1, bg_y1, img);
    #endif /* __MMI_SLIM_IMG_RES__ */
    }
    else
    {
        mmi_fmrdo_redraw_main_background(bg_x1, bg_y1, bg_x2, bg_y2);
    }    

    gdi_layer_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif 
    gdi_layer_blt_previous(bg_x1, bg_y1, bg_x2, bg_y2);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_draw_icon
 * DESCRIPTION
 *  draw button
 * PARAMETERS
 *  button      [IN]        
 *  x1          [IN]
 *  y1          [IN]
 *  x2          [IN]
 *  y2          [IN]
 *  is_down     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fmrdo_util_draw_icon(PU8 img, const fmrdo_main_rect_struct *rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = rect->x;
    S32 y1 = rect->y;
    S32 x2 = x1 + rect->w - 1;
    S32 y2 = y1 + rect->h - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    if (NULL != img)
    {
        gdi_image_draw(x1,y1,img);
    }
    else
    {
        mmi_fmrdo_redraw_main_background(x1, y1, x2, y2);
    }    

    gdi_layer_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif 
    gdi_layer_blt_previous(x1, y1, x2, y2);
}

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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.is_button_down = MMI_TRUE;
    mmi_fmrdo_sk_config_set();
    left_softkey_down();
    mmi_fmrdo_sk_config_reset();
#if 0
/* under construction !*/
#if defined (__MMI_FM_SKIN_SYN_TO_THEME__) || defined (__MMI_SLIM_IMG_RES__) 
/* under construction !*/
/* under construction !*/
#else 
/* under construction !*/
#endif 
#ifdef __MMI_SLIM_IMG_RES__
/* under construction !*/
#endif
/* under construction !*/
#endif
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.is_button_down = MMI_TRUE;
    mmi_fmrdo_sk_config_set();
    right_softkey_down();
    mmi_fmrdo_sk_config_reset();

#if 0
/* under construction !*/
#if defined (__MMI_FM_SKIN_SYN_TO_THEME__) || defined (__MMI_SLIM_IMG_RES__) 
/* under construction !*/
/* under construction !*/
#else 
/* under construction !*/
#endif 
#ifdef __MMI_SLIM_IMG_RES__
/* under construction !*/
#endif
/* under construction !*/
#endif 
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_sk_config_set();
    reset_softkey(MMI_LEFT_SOFTKEY);
    redraw_softkey(MMI_LEFT_SOFTKEY);
    mmi_fmrdo_sk_config_reset();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_sk_config_set();
    reset_softkey(MMI_RIGHT_SOFTKEY);
    redraw_softkey(MMI_RIGHT_SOFTKEY);
    mmi_fmrdo_sk_config_reset();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
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
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 
    gui_handle_scrolling_text(&fmrdo_main_draw.channel_name_scroll);
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif 
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
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    /* we don't set clip here because its caller will do that */
#if defined (__MMI_SLIM_IMG_RES__)
	gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->sub_menu_bkg_filler);
#else
    gui_show_image(0, 0, fmrdo_main_draw.bg_img);
#endif
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
}

#ifndef __MMI_FM_PLUTO_SLIM__
#ifdef __GDI_MEMORY_PROFILE_2__
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
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
}
#endif /* __GDI_MEMORY_PROFILE_2__ */


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
    if (result < GDI_SUCCEED || g_fmrdo.in_main_screen != MMI_TRUE)
    {
        return;
    }
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
    gdi_layer_push_and_set_active(fmrdo_draw_cntx_p->osd_layer);
#endif 
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
        mmi_fmrdo_redraw_main_twinkle_searching(MMI_TRUE);
    }
    else
#endif/*__FM_RADIO_HW_SEARCH__*/
    mmi_fmrdo_redraw_main_frequency(freq, MMI_TRUE);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
#endif 
}
#endif
#ifdef __MMI_FM_RADIO_ANIMATION__
static void mmi_fmrdo_animation_draw_still(void);
#endif /*__MMI_FM_RADIO_ANIMATION__*/

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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!g_fmrdo.in_main_screen)
	{	
		return;
	}
#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    mmi_fmrdo_init_for_theme();
#endif 

    gdi_layer_lock_frame_buffer();
    gdi_layer_push_and_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

#ifdef __GDI_MEMORY_PROFILE_2__
    if (!fmrdo_draw_cntx_p->is_skin_layer_drawn)
    {
        gdi_layer_push_and_set_active(fmrdo_draw_cntx_p->skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    #ifdef __MMI_FM_SKIN_SYN_TO_THEME__
        gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->special_screen_bkg_filler);
    #endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 
    #ifdef __MMI_SLIM_IMG_RES__
        gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->sub_menu_bkg_filler);
    #else
        gui_show_image(0, 0, fmrdo_main_draw.bg_img);
    #endif /* __MMI_SLIM_IMG_RES__ */

#ifdef __GDI_MEMORY_PROFILE_2__
    #ifdef __MMI_SLIM_IMG_RES__
        gdi_image_draw_resized(fmrdo_main_draw.title.x,
                               fmrdo_main_draw.title.y,
                               fmrdo_main_draw.title.w,
                               fmrdo_main_draw.title.h,
                               fmrdo_main_draw.title_bg_img);
    #endif /* __MMI_SLIM_IMG_RES__ */
        /* tuner scale background */
        gui_show_image(
                fmrdo_main_draw.tuner_scale.x,
                fmrdo_main_draw.tuner_scale.y,
                fmrdo_main_draw.tuner_scale.bg_img);
        fmrdo_draw_cntx_p->is_skin_layer_drawn = MMI_TRUE;
        gdi_layer_pop_and_restore_active();
    }
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    gdi_layer_pop_clip();

    /* animation */
#ifdef __MMI_FM_RADIO_ANIMATION__
    if (g_fmrdo.is_power_on)
    {
        mmi_fmrdo_animation_start();
    }
    else
    {
        mmi_fmrdo_animation_draw_still();
    }
#endif /* __MMI_FM_RADIO_ANIMATION__ */

    show_softkey_background();
    reset_softkeys();
    wgui_softkey_update();
    

#if (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_set_alpha_blend_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        fmrdo_draw_cntx_p->skin_layer);
    wgui_status_icon_bar_update();
#endif /* (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) */ 
    /* draw components */
#if (defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FM_SKIN_SYN_TO_THEME__))
    if ((g_fmrdo.state !=  FMRDO_STATE_RECORD) && (g_fmrdo.state !=  FMRDO_STATE_RECORD_PAUSE))
    {
        gui_show_image(fmrdo_main_draw.rec_button.x, fmrdo_main_draw.rec_button.y, (PU8) GetImage(IMG_ID_FMRDO_SKIN_1_REC_DISABLE));
    }
#endif 

#ifdef __MMI_SLIM_IMG_RES__
    mmi_fmrdo_redraw_main_title();
    mmi_fmrdo_redraw_main_freq_label();
#endif /* __MMI_SLIM_IMG_RES__ */
    mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_TRUE);
    mmi_fmrdo_redraw_main_channel_tuner(g_fmrdo.frequency);
    mmi_fmrdo_redraw_main_volume();
#ifdef __MMI_FM_RADIO_RDS__
    mmi_fmrdo_rds_redraw_main_text();
    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_TP);
    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_AF);
#ifdef __MMI_SLIM_IMG_RES__
	if (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") == 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") == 0)
	{
		mmi_fmrdo_redraw_main_channel_name(0);
	}
#else
	mmi_fmrdo_redraw_main_channel_name(0);
#endif
#else/*__MMI_FM_RADIO_RDS__*/
    mmi_fmrdo_redraw_main_channel_name(0);
#endif/*__MMI_FM_RADIO_RDS__*/

    mmi_fmrdo_redraw_main_push_button(
        FMRDO_BUTTON_STEP_DOWN,
        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN)));
    mmi_fmrdo_redraw_main_push_button(
        FMRDO_BUTTON_STEP_UP,
        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP)));
#ifdef __MMI_SLIM_IMG_RES__
    mmi_fmrdo_redraw_main_push_button(
        FMRDO_BUTTON_SEARCH_DOWN,
        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_SEARCH_DOWN)));
    mmi_fmrdo_redraw_main_push_button(
        FMRDO_BUTTON_SEARCH_UP,
        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_SEARCH_UP)));
#else /* __MMI_SLIM_IMG_RES__ */
    if (g_fmrdo.is_power_on == MMI_TRUE)
    {
        mmi_fmrdo_redraw_main_toggle_button(
            FMRDO_BUTTON_SEARCH,
            (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_SEARCH)),
            g_fmrdo.is_search_on,
            MMI_TRUE);
    }
    else
    {
        mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_SEARCH, MMI_FALSE, MMI_FALSE, MMI_TRUE);
    }
#endif /* __MMI_SLIM_IMG_RES__ */
    mmi_fmrdo_redraw_main_toggle_button(
        FMRDO_BUTTON_POWER,
        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_POWER)),
        g_fmrdo.is_power_on,
        MMI_TRUE);
#if (defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_SLIM_IMG_RES__)))
    mmi_fmrdo_redraw_main_push_down_button(0, fmrdo_main_draw.volume_dec_button.down);
    mmi_fmrdo_redraw_main_push_down_button(1, fmrdo_main_draw.volume_inc_button.down);
    mmi_fmrdo_redraw_main_push_down_button(2, fmrdo_main_draw.setting_button.down);
#endif /* (defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_SLIM_IMG_RES__))) */ 

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

#ifdef __MMI_SLIM_IMG_RES__
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
void mmi_fmrdo_redraw_main_frequency(U16 freq, MMI_BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 flags = 0;
    fmrdo_main_rect_struct rect;
    UI_character_type str[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 

    rect.x = fmrdo_main_draw.frequency.x;
    rect.y = fmrdo_main_draw.frequency.y;
    rect.w = fmrdo_main_draw.frequency.w;
    rect.h = fmrdo_main_draw.frequency.h;
    
    if (is_shown)
    {
        /* in slim project, Powner on/off use same color */
        gui_set_text_color(*(current_MMI_theme->media_player_content_text_color));
        kal_wsprintf(str, "%d.%d", freq / 10, freq % 10);
    #if defined(__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__)
        gui_set_font(&MMI_small_font);
    #else
        gui_set_font(&MMI_large_font);
    #endif
        mmi_fmrdo_util_draw_simple_text(&rect, str, 
                FMRDO_FLAG_SET(flags, MMI_FMRDO_TEXT_HORZ_ACENTER|MMI_FMRDO_TEXT_VERT_ACERTER));
    }
    else
    {
        mmi_fmrdo_util_draw_simple_text(&rect, NULL, flags);
    }
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif
    gdi_layer_blt_previous(rect.x, rect.y, rect.x + rect.w - 1, rect.y + rect.h - 1);
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
    S32 flags = 0;
    UI_string_type str = NULL;
    UI_font_type channel_font = gui_font_get_type(GUI_FONT_SIZE_TITLE);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
    if (FMRDO_FLAG_CHECK(fmrdo_draw_cntx_p->flag, MMI_FMRDO_FLAG_SCROLLING))
    {
        gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);
        FMRDO_FLAG_RESET(fmrdo_draw_cntx_p->flag, MMI_FMRDO_FLAG_SCROLLING);
    }
    #ifdef __MMI_FM_RADIO_RDS__
			gui_scrolling_text_stop(&fmrdo_main_draw.rds_text_scroll);
		#endif
	gdi_layer_lock_frame_buffer();
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 

    gui_set_text_color(*(current_MMI_theme->title_text_color));
    gui_set_text_border_color(*(current_MMI_theme->title_text_border_color));
    gui_set_font(channel_font);
    gui_measure_string(str, &str_w, &str_h);

    if (str_w <= fmrdo_main_draw.channel_name.w - 4)
    {

        mmi_fmrdo_util_draw_simple_text(&fmrdo_main_draw.channel_name, str, 
                FMRDO_FLAG_SET(flags, MMI_FMRDO_TEXT_HORZ_ACENTER|MMI_FMRDO_TEXT_VERT_ACERTER|MMI_FMRDO_TEXT_HAS_BORDER));
    }
    else
    {
        gui_create_scrolling_text(
                &fmrdo_main_draw.channel_name_scroll,
                x1 + 2,
                y1 + (fmrdo_main_draw.channel_name.h - str_h) / 2,
                fmrdo_main_draw.channel_name.w - 4,
                fmrdo_main_draw.channel_name.h - 2,
                str,
                mmi_fmrdo_scroll_channel_name_hdlr,
                mmi_fmrdo_redraw_main_background,
                *(current_MMI_theme->title_text_color),
                *(current_MMI_theme->title_text_border_color));
        fmrdo_main_draw.channel_name_scroll.text_font = *channel_font;
        fmrdo_main_draw.channel_name_scroll.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;

        gdi_layer_push_and_set_clip(x1, y1, x2, y2);
		/* stop scrolling if necessary */
    	gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);
        mmi_fmrdo_redraw_main_background(x1, y1, x2, y2);
        
        /* scrolling */
        gui_change_scrolling_text(&fmrdo_main_draw.channel_name_scroll, str);
        gui_show_scrolling_text(&fmrdo_main_draw.channel_name_scroll);
        gdi_layer_pop_clip();
        
        FMRDO_FLAG_SET(fmrdo_draw_cntx_p->flag, MMI_FMRDO_FLAG_SCROLLING);
    }   
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif
	gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_title
 * DESCRIPTION
 *  Redraw channel name on main screen
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 flags = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif     
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(*(current_MMI_theme->title_text_color));
                    
    mmi_fmrdo_util_draw_simple_text(
        (const fmrdo_main_rect_struct *)&fmrdo_main_draw.title,
        (U16*)GetString(STR_ID_FMRDO_TITLE),
        MMI_FMRDO_TEXT_HORZ_ACENTER|MMI_FMRDO_TEXT_VERT_ACERTER);
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_freq_label
 * DESCRIPTION
 *  Redraw frequency label on main screen
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_freq_label(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 flags = 0;
    fmrdo_main_rect_struct rect;
    U16 str[8];
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 
        
    gui_set_font(&MMI_small_font);
    gui_set_text_color(UI_COLOR_BLACK);

    mmi_asc_to_ucs2((CHAR *)str, (CHAR*)"108");
    mmi_fmrdo_util_draw_simple_text(&fmrdo_main_draw.label, str, 
                        FMRDO_FLAG_SET(flags, MMI_FMRDO_TEXT_HORZ_ARIGHT|MMI_FMDRO_TEXT_VERT_ATOP));

    rect.w = fmrdo_main_draw.label.w >> 1;
    rect.x = fmrdo_main_draw.label.x;
    rect.y = fmrdo_main_draw.label.y;
    rect.h = fmrdo_main_draw.label.h; 
    mmi_asc_to_ucs2((CHAR *)str, (CHAR*)"87.5");
//    kal_wsprintf(str,"%d.%d",MIN_FM_FREQUENCY/10, MIN_FM_FREQUENCY%10);
    mmi_fmrdo_util_draw_simple_text(&rect, str, 
                        FMRDO_FLAG_SET(flags, MMI_FMRDO_TEXT_HORZ_ALEFT|MMI_FMDRO_TEXT_VERT_ATOP));

    FMRDO_FALG_CLEAR(flags);

//    kal_wsprintf(str,"%d",MAX_FM_FREQUENCY/10);

                        
#ifdef __GDI_MEMORY_PROFILE_2__
        mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif
}


#else
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
void mmi_fmrdo_redraw_main_frequency(U16 freq, MMI_BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;
    S32 x1 = fmrdo_main_draw.frequency.x;
    S32 y1 = fmrdo_main_draw.frequency.y;
    S32 x2 = fmrdo_main_draw.frequency.x + fmrdo_main_draw.frequency.w - 1;
    S32 y2 = fmrdo_main_draw.frequency.y + fmrdo_main_draw.frequency.h - 1;
#if !(defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
    S32 prefix_str_w, prefix_str_h;
#endif 
    S32 str_w, str_h;
    UI_character_type prefix_str[] = L"FM ";
    UI_character_type str[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);    
    /* background & text */
    mmi_fmrdo_redraw_main_background(x1, y1, x2, y2);

    if (is_shown)
    {
        if (g_fmrdo.is_power_on)
        {
            gui_set_text_color(*(current_MMI_theme->media_player_content_text_color));
        }
        else
        {
            gui_set_text_color(*(current_MMI_theme->cascade_menu_disabled_text_color));
        }

    #if (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
        kal_wsprintf(str, "%w%d.%d", prefix_str, freq / 10, freq % 10);
        gui_set_font(&MMI_large_font);
        gui_measure_string(str, &str_w, &str_h);

        x = x1 + (fmrdo_main_draw.frequency.w - str_w ) / 2;
        y = y1 + (fmrdo_main_draw.frequency.h - str_h) / 2;
        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x + str_w, y);
        }
        else
        {
            gui_move_text_cursor(x, y);
        }
    #ifdef __MMI_FM_SKIN_SYN_TO_THEME__
        gui_set_text_border_color(*current_MMI_theme->media_player_content_text_border_color);
        gui_print_bordered_text(str);
    #else 
        gui_print_text(str);
    #endif 
    #else 
        kal_wsprintf(str, "%d.%d", freq / 10, freq % 10);
        gui_set_font(&MMI_medium_font);
        gui_measure_string(str, &str_w, &str_h);
        gui_set_font(&MMI_small_font);
        gui_measure_string(prefix_str, &prefix_str_w, &prefix_str_h);

        x = x1 + (fmrdo_main_draw.frequency.w - str_w - prefix_str_w) / 2;
        y = y1 + (fmrdo_main_draw.frequency.h - str_h) / 2;

        /* prefix "FM " */
        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x + prefix_str_w - 1, y + str_h - prefix_str_h - 1);
        }
        else
        {
            gui_move_text_cursor(x, y + str_h - prefix_str_h - 1);
        }

    #if defined(__MMI_MAINLCD_240X320__)
        /* Animation size may be small and overlap with spectrum */
        gui_set_text_border_color(gui_color(0,0,0));
        gui_print_bordered_text(prefix_str);
    #else
    #ifdef __MMI_FM_SKIN_SYN_TO_THEME__
        gui_set_text_border_color(*current_MMI_theme->media_player_content_text_border_color);
        gui_print_bordered_text(prefix_str);
    #else 
        gui_print_text(prefix_str);
    #endif 
    #endif 
    #endif 

        /* frequency number */

    #if !(defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
        gui_set_font(&MMI_medium_font);
        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x + prefix_str_w + str_w - 1, y);
        }
        else
        {
            gui_move_text_cursor(x + prefix_str_w - 1, y);
        }
    #if defined(__MMI_MAINLCD_240X320__)
        gui_print_bordered_text(str);
    #else 
    #ifdef __MMI_FM_SKIN_SYN_TO_THEME__
        gui_set_text_border_color(*current_MMI_theme->media_player_content_text_border_color);
        gui_print_bordered_text(str);
    #else 
        gui_print_text(str);
    #endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    #endif /* !(defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) */
    }
    gdi_layer_pop_clip();

#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif 
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
    UI_font_type channel_font = gui_font_get_type(GUI_FONT_SIZE_TITLE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
        fmrdo_main_draw.is_channel_name_scroll_ready = MMI_TRUE;
    }
    gui_measure_string(str, &str_w, &str_h);
    gui_create_scrolling_text(
        &fmrdo_main_draw.channel_name_scroll,
        x1 + 2,
        y1 + (fmrdo_main_draw.channel_name.h - str_h) / 2,
        fmrdo_main_draw.channel_name.w - 4,
        fmrdo_main_draw.channel_name.h - 2,
        str,
        mmi_fmrdo_scroll_channel_name_hdlr,
        mmi_fmrdo_redraw_main_background,
        *(current_MMI_theme->title_text_color),
        *(current_MMI_theme->title_text_border_color));
    fmrdo_main_draw.channel_name_scroll.text_font = *channel_font;
    fmrdo_main_draw.channel_name_scroll.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;

#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    mmi_fmrdo_redraw_main_background(x1, y1, x2, y2);
    
    /* stop scrolling if necessary */
    gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);

    gui_set_font(channel_font);
    gui_measure_string(str, &str_w, &str_h);
    /* text */
    if (str_w > fmrdo_main_draw.channel_name.w - 4)
    {
        /* scrolling */
        gui_change_scrolling_text(&fmrdo_main_draw.channel_name_scroll, str);
        gui_show_scrolling_text(&fmrdo_main_draw.channel_name_scroll);
    }
    else
    {
        gui_set_text_color(*(current_MMI_theme->title_text_color));
        gui_set_text_border_color(*(current_MMI_theme->title_text_border_color));
        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(
                x1 + (fmrdo_main_draw.channel_name.w + str_w) / 2,
                y1 + (fmrdo_main_draw.channel_name.h - str_h) / 2);
        }
        else
        {
            gui_move_text_cursor(
                x1 + (fmrdo_main_draw.channel_name.w - str_w) / 2,
                y1 + (fmrdo_main_draw.channel_name.h - str_h) / 2);
        }
        gui_print_bordered_text(str);
    }
    gdi_layer_pop_clip();
    
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif
    gdi_layer_blt_previous(x1, y1, x2, y2);
}
#endif /*__MMI_SLIM_IMG_RES__*/


#ifdef __MMI_FM_RADIO_RDS__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_rds_redraw_main_text
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
    UI_font_type rds_font = gui_font_get_type(GUI_FONT_SIZE_TITLE);
#if defined (__MMI_SLIM_IMG_RES__)
	const S32 cntx_size = sizeof(fmrdo_draw_cntx_p->rds_str1);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_REDRAW_MAIN_TEXT_ENTRY);
#if defined (__MMI_SLIM_IMG_RES__)
	if((mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") == 0) && (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") == 0))
	{
		memset((PS8)fmrdo_draw_cntx_p->rds_str1, 0, cntx_size);
		return;
	}
#endif
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
    if(mmi_ucs2cmp((CHAR *)fmrdo_draw_cntx_p->rds_str1, (CHAR *)str) != 0)
    {
        mmi_ucs2cpy((CHAR *)fmrdo_draw_cntx_p->rds_str1, (CHAR *)str);
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
        fmrdo_main_draw.is_rds_text_scroll_ready = MMI_TRUE;
    }

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


#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    
    /* stop scrolling if necessary */
    gui_scrolling_text_stop(&fmrdo_main_draw.rds_text_scroll);
#if defined (__MMI_SLIM_IMG_RES__)
	gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);
#endif
    gui_set_font(rds_font);
    gui_measure_string(str, &str_w, &str_h);

    mmi_fmrdo_redraw_main_background(x1, y1, x2, y2);

    /* text */
    if (str_w > fmrdo_main_draw.rds_text.w - 4)
    {
        /* scrolling */
        gui_change_scrolling_text(&fmrdo_main_draw.rds_text_scroll, str);
        gui_set_text_color(fmrdo_main_draw.rds_text_color);
        gui_set_text_border_color(fmrdo_main_draw.rds_text_border_color);
        gui_show_scrolling_text(&fmrdo_main_draw.rds_text_scroll);
    }
    else
    {
        /* no scrolling */
        gui_set_text_color(fmrdo_main_draw.rds_text_color);
        gui_set_text_border_color(fmrdo_main_draw.rds_text_border_color);
        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(
                x1 + (fmrdo_main_draw.rds_text.w + str_w) / 2,
                y1 + (fmrdo_main_draw.rds_text.h - str_h) / 2);
        }
        else
        {
            gui_move_text_cursor(
                x1 + (fmrdo_main_draw.rds_text.w - str_w) / 2,
                y1 + (fmrdo_main_draw.rds_text.h - str_h) / 2);
        }
        gui_print_bordered_text(str);
    }

    gdi_layer_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif 
    }
    else
    {
    #ifdef __GDI_MEMORY_PROFILE_2__
        mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
    #endif 
        gui_scrolling_text_stop(&fmrdo_main_draw.rds_text_scroll);
    #ifndef __GDI_MEMORY_PROFILE_2__ 
	#if defined (__MMI_SLIM_IMG_RES__)
 		gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->sub_menu_bkg_filler);
	#else
        gui_show_image(0, 0, fmrdo_main_draw.bg_img);
    #endif 
    #endif 
    #ifdef __GDI_MEMORY_PROFILE_2__
        mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
    #endif 
    }
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
void mmi_fmrdo_scroll_rds_text_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 
    gui_handle_scrolling_text(&fmrdo_main_draw.rds_text_scroll);
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif 
}
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
void mmi_fmrdo_rds_redraw_main_ind(U8 ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmrdo_main_ind_struct *ind_button_p = NULL;
    S32 x1, y1, x2, y2;
    PU8 draw_img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_RDS_REDRAW_MAIN_IND_IND_RECEIVED,ind);
    switch (ind)
    {
        case FMRDO_RDS_IND_MAIN:
            ind_button_p = &fmrdo_main_draw.rds_ind;
            if(((g_fmrdo.rds.status_mask & RT_RECIEVE) || (g_fmrdo.rds.status_mask & PS_RECIEVE) || (g_fmrdo.rds.status_mask & TP_RECIEVE) || (g_fmrdo.rds.status_mask & AF_RECIEVE)) && (g_fmrdo.rds.rds_setting.is_rds_on))/*ps name recieved or rt recieved through flags*/
            {
                draw_img = ind_button_p->up_img;
            }
            else if (g_fmrdo.rds.rds_setting.is_rds_on)
            {
                draw_img = ind_button_p->down_img;
            }
            else
            {
                draw_img = ind_button_p->dis_img;
            }
            break;
        case FMRDO_RDS_IND_TP:
            ind_button_p = &fmrdo_main_draw.tp_ind;
            if((g_fmrdo.rds.status_mask & TP_RECIEVE) && g_fmrdo.rds.rds_setting.is_tp_on)
            {
                draw_img = ind_button_p->up_img;
            }
            else if(g_fmrdo.rds.rds_setting.is_tp_on)
            {
                draw_img = ind_button_p->down_img;
            }
            else
            {
                draw_img = ind_button_p->dis_img;
            }
            break;
        case FMRDO_RDS_IND_AF:
            ind_button_p = &fmrdo_main_draw.af_ind;
            if(g_fmrdo.rds.status_mask & AF_RECIEVE && g_fmrdo.rds.rds_setting.is_af_on)
            {
                draw_img = ind_button_p->up_img;
            }
            else if(g_fmrdo.rds.rds_setting.is_af_on)
            {
                draw_img = ind_button_p->down_img;
            }
            else
            {
                draw_img = ind_button_p->dis_img;
            }
            break;
        default:
            return;
    }

    x1 = ind_button_p->x;
    y1 = ind_button_p->y;
    x2 = ind_button_p->x + ind_button_p->w - 1;
    y2 = ind_button_p->y + ind_button_p->h - 1;

#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    /* button */
    gui_show_image(x1, y1, draw_img);
    gdi_layer_pop_clip();
    
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif 

    gdi_layer_blt_previous(x1, y1, x2, y2);
}
#endif /*__MMI_FM_RADIO_RDS__*/

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
    S32 x1 = fmrdo_main_draw.tuner_scale.x;
    S32 y1 = fmrdo_main_draw.tuner_scale.y;
    S32 x2 = fmrdo_main_draw.tuner_scale.x + fmrdo_main_draw.tuner_scale.w - 1;
    S32 y2 = fmrdo_main_draw.tuner_scale.y + fmrdo_main_draw.tuner_scale.h - 4;
    S32 delta;
#ifndef __GDI_MEMORY_PROFILE_2__
    MMI_BOOL outside = MMI_FALSE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmrdo_main_draw.tuner_scale.type == 0)  /* 0: horizontal, 1: vertical */
    {
        if (fmrdo_main_draw.tuner_scale.ind_offset < 0)
        {
            y1 += fmrdo_main_draw.tuner_scale.ind_offset;
        }
        delta = fmrdo_main_draw.tuner_scale.y + 
                fmrdo_main_draw.tuner_scale.ind_offset + 
                fmrdo_main_draw.tuner_scale.ind_h - 1;
        if (delta > y2)
        {
            y2 = delta;
        #ifndef __GDI_MEMORY_PROFILE_2__
            outside = MMI_TRUE;
        #endif 
        }
    }
    else
    {
        if (fmrdo_main_draw.tuner_scale.ind_offset < 0)
        {
            x1 += fmrdo_main_draw.tuner_scale.ind_offset;
        }
        delta = fmrdo_main_draw.tuner_scale.x + 
                fmrdo_main_draw.tuner_scale.ind_offset + 
                fmrdo_main_draw.tuner_scale.ind_w - 1;
        if (delta > x2)
        {
            x2 = delta;
        #ifndef __GDI_MEMORY_PROFILE_2__
            outside = MMI_TRUE;
        #endif 
        }
    }

#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    if (outside)
    {
    #if  defined (__MMI_SLIM_IMG_RES__)
  		gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->sub_menu_bkg_filler);
	#else
        gui_show_image(0, 0, fmrdo_main_draw.bg_img);   /* background */
	#endif
    }
    /* tuner scale background */
    gui_show_image(fmrdo_main_draw.tuner_scale.x, fmrdo_main_draw.tuner_scale.y, fmrdo_main_draw.tuner_scale.bg_img);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* tuner scale indicator */
    if (fmrdo_main_draw.tuner_scale.type == 0)  /* 0: horizontal, 1: vertical */
    {
        S32 w = fmrdo_main_draw.tuner_scale.w - fmrdo_main_draw.tuner_scale.ind_start_gap -
            fmrdo_main_draw.tuner_scale.ind_end_gap - fmrdo_main_draw.tuner_scale.ind_w;
        gui_show_image(
            fmrdo_main_draw.tuner_scale.x + fmrdo_main_draw.tuner_scale.ind_start_gap + (freq - MIN_FM_FREQUENCY) * w / FM_BANDWIDTH,
            fmrdo_main_draw.tuner_scale.y + fmrdo_main_draw.tuner_scale.ind_offset,
            fmrdo_main_draw.tuner_scale.ind_img);
    }
    else
    {
        S32 h = fmrdo_main_draw.tuner_scale.h - fmrdo_main_draw.tuner_scale.ind_start_gap -
            fmrdo_main_draw.tuner_scale.ind_end_gap - fmrdo_main_draw.tuner_scale.ind_h;
        gui_show_image(
            fmrdo_main_draw.tuner_scale.x + fmrdo_main_draw.tuner_scale.ind_offset,
            fmrdo_main_draw.tuner_scale.y + fmrdo_main_draw.tuner_scale.ind_start_gap + (freq - MIN_FM_FREQUENCY) * h / FM_BANDWIDTH,
            fmrdo_main_draw.tuner_scale.ind_img);
    }

    gdi_layer_pop_clip();    
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif
    gdi_layer_blt_previous(x1, y1, x2, y2);
}


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
    S32 x1 = fmrdo_main_draw.volume.x;
    S32 y1 = fmrdo_main_draw.volume.y;
    S32 x2 = fmrdo_main_draw.volume.x + fmrdo_main_draw.volume.w - 1;
    S32 y2 = fmrdo_main_draw.volume.y + fmrdo_main_draw.volume.h - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    mmi_fmrdo_redraw_main_background(x1, y1, x2, y2);
#ifdef __MMI_SLIM_IMG_RES__
    gui_show_image(x1, y1, fmrdo_main_draw.volume.bg_img);
#endif /* __MMI_SLIM_IMG_RES__ */

    /* volume */
	if (!g_fmrdo.mute)
    {
    if (fmrdo_main_draw.volume.type == 0)   /* 0: horizontal, 1: vertical */
    {
    #ifdef __MMI_SLIM_IMG_RES__
        S32 delta = ((U32) g_fmrdo.volume) * (fmrdo_main_draw.volume.w - fmrdo_main_draw.volume.ind_start_gap -
                                                  fmrdo_main_draw.volume.ind_end_gap) / (MAX_VOL_LEVEL - 1);
	#else
        S32 delta = ((U32) g_fmrdo.volume) * (fmrdo_main_draw.volume.w - fmrdo_main_draw.volume.ind_start_gap -
                                                  fmrdo_main_draw.volume.ind_end_gap) / MAX_VOL_LEVEL;
	#endif
        gdi_layer_set_clip(x1, y1, x1 + fmrdo_main_draw.volume.ind_start_gap + delta - 1, y2);
    }
    else
    {
    #ifdef __MMI_SLIM_IMG_RES__
		S32 delta = ((U32) g_fmrdo.volume) * (fmrdo_main_draw.volume.h - fmrdo_main_draw.volume.ind_start_gap -
                                                  fmrdo_main_draw.volume.ind_end_gap) / (MAX_VOL_LEVEL - 1);
	#else
        S32 delta = ((U32) g_fmrdo.volume) * (fmrdo_main_draw.volume.h - fmrdo_main_draw.volume.ind_start_gap -
                                                  fmrdo_main_draw.volume.ind_end_gap) / MAX_VOL_LEVEL;
	#endif
        gdi_layer_set_clip(x1, y2 - fmrdo_main_draw.volume.ind_start_gap - delta - 1, x2, y2);
    }
	if (g_fmrdo.volume > 0)
	{
    gui_show_image(x1, y1, fmrdo_main_draw.volume.fg_img);
	}
	}
    gdi_layer_pop_clip();
    
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif 
    gdi_layer_blt_previous(x1, y1, x2, y2);
}


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
void mmi_fmrdo_redraw_main_push_button(U8 button, MMI_BOOL is_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmrdo_main_push_button_struct *push_button_p;
    fmrdo_main_rect_struct        btn_rect;  
    fmrdo_btn_state_enum          state;
    PU8 draw_img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
#ifdef __MMI_SLIM_IMG_RES__
    case FMRDO_BUTTON_SEARCH_UP:
        push_button_p = &fmrdo_main_draw.search_up_button;
        break;
    case FMRDO_BUTTON_SEARCH_DOWN:
        push_button_p = &fmrdo_main_draw.search_down_button;
        break;
#endif /* __MMI_SLIM_IMG_RES__ */
    default:
        return;
    }
#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    if (mmi_fmrdo_need_disable_button(button))
    {
        state = FMRDO_BTN_STATE_DISABLE;
        draw_img = push_button_p->dis_img;
    }
    else
#elif defined(__MMI_SLIM_IMG_RES__)
    if (mmi_fmrdo_need_disable_button(button))
    {
        state = FMRDO_BTN_STATE_DISABLE;
        draw_img = push_button_p->down_img;
    }
    else  
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */ 
    {
        if (is_down)
        {
            state = FMRDO_BTN_STATE_DOWN;
            draw_img = push_button_p->down_img;
        }
        else
        {
            state = FMRDO_BTN_STATE_UP;
            draw_img = push_button_p->up_img;
        }
    }

    btn_rect.x = push_button_p->x;
    btn_rect.y = push_button_p->y;
    btn_rect.w = push_button_p->w;
    btn_rect.h = push_button_p->h;
    mmi_fmrdo_util_draw_button(
                    draw_img, 
                    &btn_rect, 
                    state);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_need_disable_button
 * DESCRIPTION
 *  Decide whether button needs to be disabled
 * PARAMETERS
 *  button          [IN]        
 * RETURNS
 *  MMI_TRUE
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

#ifdef __MMI_SLIM_IMG_RES__
    case FMRDO_BUTTON_SEARCH_UP:
    case FMRDO_BUTTON_SEARCH_DOWN:
        if (!g_fmrdo.is_power_on)
        {
            return MMI_TRUE;
        }
#else /* __MMI_SLIM_IMG_RES__ */
    case FMRDO_BUTTON_SEARCH:
#endif /* __MMI_SLIM_IMG_RES__ */
    case FMRDO_BUTTON_POWER:        
    case FMRDO_BUTTON_STEP_UP:
    case FMRDO_BUTTON_STEP_DOWN:
        if (g_fmrdo.state == FMRDO_STATE_RECORD ||
    #ifdef __FM_RADIO_HW_SEARCH__
            g_fmrdo.state == FMRDO_STATE_SEARCH_ONE ||
    #endif 
            g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
        {
            return MMI_TRUE;
        }
        break;
#if (defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FM_SKIN_SYN_TO_THEME__))
    case FMRDO_BUTTON_REC_PAUSE:
    case FMRDO_BUTTON_REC:
        if ((g_fmrdo.state !=  FMRDO_STATE_RECORD) && (g_fmrdo.state !=  FMRDO_STATE_RECORD_PAUSE))
        {
            return MMI_TRUE;
        }
#endif 
    }
    return MMI_FALSE;
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
void mmi_fmrdo_redraw_main_toggle_button(U8 button, MMI_BOOL is_down, MMI_BOOL is_on, MMI_BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmrdo_main_toggle_button_struct *toggle_button_p;
    fmrdo_main_rect_struct        btn_rect;  
    fmrdo_btn_state_enum          state = FMRDO_BTN_STATE_UP;
    PU8 draw_img = NULL;
#ifdef __MMI_SLIM_IMG_RES__
    MMI_BOOL is_icon = MMI_FALSE;
#endif /* __MMI_SLIM_IMG_RES__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!g_fmrdo.in_main_screen)
    {
		return;
	}

    switch (button)
    {
        case FMRDO_BUTTON_POWER:
            toggle_button_p = &fmrdo_main_draw.power_button;
            break;
    #ifndef __MMI_SLIM_IMG_RES__
        case FMRDO_BUTTON_SEARCH:
            toggle_button_p = &fmrdo_main_draw.search_button;
            break;
    #endif /* __MMI_SLIM_IMG_RES__ */
    #if defined(__MMI_FM_RADIO_RECORD__)
        case FMRDO_BUTTON_REC:
            toggle_button_p = &fmrdo_main_draw.rec_button;
        #ifdef __MMI_SLIM_IMG_RES__
            is_icon = MMI_TRUE;
        #endif /* __MMI_SLIM_IMG_RES__ */
            break;
        case FMRDO_BUTTON_REC_PAUSE:
            toggle_button_p = &fmrdo_main_draw.rec_pause_button;
        #ifdef __MMI_SLIM_IMG_RES__
            is_icon = MMI_TRUE;
        #endif /* __MMI_SLIM_IMG_RES__ */
            break;
    #endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
        default:
            return;
    }

    if (is_shown)
    {
        /* button */
    #ifdef __MMI_FM_SKIN_SYN_TO_THEME__
        //if (draw_img == NULL)
        if (mmi_fmrdo_need_disable_button(button))
        {
            state = FMRDO_BTN_STATE_DISABLE;
            draw_img = toggle_button_p->dis_img;
        }
        else 
    #endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */
        {
            if (is_on)
            {
                if (is_down)
                {
                    state = FMRDO_BTN_STATE_DOWN;
                    draw_img = toggle_button_p->on_down_img;
                }
                else
                {
                    state = FMRDO_BTN_STATE_UP;
                    draw_img = toggle_button_p->on_up_img;
                }
            }
            else
            {
                if (is_down)
                {
                    state = FMRDO_BTN_STATE_DOWN;
                    draw_img = toggle_button_p->off_down_img;
                }
                else
                {
                    state = FMRDO_BTN_STATE_UP;
                    draw_img = toggle_button_p->off_up_img;
                }
            }
        #ifdef __MMI_SLIM_IMG_RES__
            if (mmi_fmrdo_need_disable_button(button))
            {
                state = FMRDO_BTN_STATE_DISABLE;
            }
        #endif /* __MMI_SLIM_IMG_RES__ */ 
        }
    }
    
    btn_rect.x = toggle_button_p->x;
    btn_rect.y = toggle_button_p->y;
    btn_rect.w = toggle_button_p->w;
    btn_rect.h = toggle_button_p->h;
#ifdef __MMI_SLIM_IMG_RES__
    if (is_icon)
    {
        mmi_fmrdo_util_draw_icon(draw_img, &btn_rect);
    }
    else
#endif /* __MMI_SLIM_IMG_RES__ */    
    {
        mmi_fmrdo_util_draw_button(draw_img, &btn_rect, state);
    }
}


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
    mmi_fmrdo_change_sk(get_string(STR_GLOBAL_OPTIONS), get_string(STR_GLOBAL_BACK));
//    fmrdo_main_draw.LSK_text = (UI_string_type) GetString(STR_GLOBAL_OPTIONS);
//    fmrdo_main_draw.RSK_text = (UI_string_type) GetString(STR_GLOBAL_BACK);

    SetKeyDownHandler(mmi_fmrdo_redraw_main_LSK_down, KEY_LSK);
    SetKeyDownHandler(mmi_fmrdo_redraw_main_RSK_down, KEY_RSK);

//    mmi_fmrdo_redraw_main_LSK_up();
//    mmi_fmrdo_redraw_main_RSK_up();
    //g_fmrdo.is_button_down = MMI_FALSE;
}


#ifdef __FM_RADIO_HW_SEARCH__
#ifndef __MMI_FM_PLUTO_SLIM__

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
void mmi_fmrdo_redraw_main_twinkle_searching(MMI_BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = fmrdo_main_draw.frequency.x;
    S32 y1 = fmrdo_main_draw.frequency.y;
    S32 x2 = fmrdo_main_draw.frequency.x + fmrdo_main_draw.frequency.w - 1;
    S32 y2 = fmrdo_main_draw.frequency.y + fmrdo_main_draw.frequency.h - 1;
    S32 flag = 0;
    U16 *str = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_shown)
    {
        str = (UI_string_type) GetString(STR_GLOBAL_SEARCHING);
    }    

#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif
    if (is_shown)
    {
        gui_set_text_color(*(current_MMI_theme->media_player_content_text_color));
        gui_set_font(&MMI_medium_font);
    #if defined(__MMI_MAINLCD_240X320__) && (!defined(__MMI_SLIM_IMG_RES__))
        FMRDO_FLAG_SET(flag, MMI_FMRDO_TEXT_HAS_BORDER);
        gui_set_text_border_color(gui_color(0,0,0));
    #endif
        mmi_fmrdo_util_draw_simple_text(&fmrdo_main_draw.frequency, str,
                    FMRDO_FLAG_SET(flag, MMI_FMRDO_TEXT_HORZ_ACENTER|MMI_FMRDO_TEXT_VERT_ACERTER));
    }

#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif 
    gdi_layer_blt_previous(x1-2, y1-2, x2, y2);
}
#endif
#endif /* __FM_RADIO_HW_SEARCH__ */ 

/* MTK Leo add 20050301, add touch screen support for FM Radio */
#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_push_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button      [IN]        0 = volume_dec_button, 1 = volume_inc_button, 2 = setting_button
 *  is_down     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_push_down_button(U8 button, MMI_BOOL is_down)
{
#if (!defined(__MMI_SLIM_IMG_RES__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmrdo_main_push_down_button_struct *push_down_button_p, *inc_button_p, *dec_button_p;
    S32 x1, y1, x2, y2;
    S32 ax1 = 0, ay1 = 0, ax2 = 0, ay2 = 0;
    MMI_BOOL need_update_another = MMI_FALSE;
    PU8 draw_img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (button)
    {
        case 0:
            push_down_button_p = &fmrdo_main_draw.volume_dec_button;
            break;
        case 1:
            push_down_button_p = &fmrdo_main_draw.volume_inc_button;
            break;
        case 2:
            push_down_button_p = &fmrdo_main_draw.setting_button;
            break;
        default:
            return;
    }
    x1 = (S32)(push_down_button_p->x);
    y1 = (S32)(push_down_button_p->y);
    x2 = (S32)(push_down_button_p->x + push_down_button_p->w - 1);
    y2 = (S32)(push_down_button_p->y + push_down_button_p->h - 1);
    push_down_button_p->down = is_down;
    g_fmrdo.is_button_down = is_down;
    if (mmi_fmrdo_need_disable_push_button((fmrdo_main_button_enum)button))
    {
        draw_img = push_down_button_p->dis_img;
    }
    if (draw_img == NULL)
    {
        if (is_down)
        {
            draw_img = push_down_button_p->down_img;
        }
        else
        {
            draw_img = push_down_button_p->up_img;
        }
    }

#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    mmi_fmrdo_redraw_main_background(x1, y1, x2, y2);
    /* reach disable value */
    gui_show_image(x1, y1, draw_img);
    /* first time resume from disable value */
    /* volume to 1 by press inc button, need redraw dec butten */
    if (g_fmrdo.volume == 1 && button == 1 && is_down == MMI_FALSE)
    {
        dec_button_p = &fmrdo_main_draw.volume_dec_button;
        ax1 = dec_button_p->x;
        ay1 = dec_button_p->y;
        ax2 = dec_button_p->x + dec_button_p->w - 1;
        ay2 = dec_button_p->y + dec_button_p->h - 1;
        gdi_layer_set_clip(ax1, ay1, ax2, ay2);
        gui_show_image(ax1, ay1, dec_button_p->up_img);
        need_update_another = MMI_TRUE;
    }
    /* volume to MAX-2 by press dec button, need redraw inc butten */
    else if (g_fmrdo.volume == MAX_VOL_LEVEL - 2 && button == 0 && is_down == MMI_FALSE)
    {
        inc_button_p = &fmrdo_main_draw.volume_inc_button;
        ax1 = inc_button_p->x;
        ay1 = inc_button_p->y;
        ax2 = inc_button_p->x + inc_button_p->w - 1;
        ay2 = inc_button_p->y + inc_button_p->h - 1;
        gdi_layer_set_clip(ax1, ay1, ax2, ay2);
        gui_show_image(ax1, ay1, inc_button_p->up_img);
        need_update_another = MMI_TRUE;
    }
    gdi_layer_pop_clip();
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif 

    gdi_layer_blt_previous(x1, y1, x2, y2);
    if (MMI_TRUE == need_update_another)
    {
        gdi_layer_blt_previous(ax1, ay1, ax2, ay2);
    }
#endif /* (!defined(__MMI_SLIM_IMG_RES__) */
}


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
#if (!defined(__MMI_SLIM_IMG_RES__))
    if (button == 0)
    {
        mmi_fmrdo_redraw_main_push_down_button(button, fmrdo_main_draw.volume_dec_button.down);
    }
    else if (button == 1)
    {
        mmi_fmrdo_redraw_main_push_down_button(button, fmrdo_main_draw.volume_inc_button.down);
    }
#endif /* #if (!defined(__MMI_SLIM_IMG_RES__) */
}


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
    S16 i;
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[g_fmrdo.skin_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmrdo_draw_cntx_p->pen_event = FMRDO_PEN_NONE;

    for (i = FMRDO_PEN_LSK; i < FMRDO_PEN_COUNT; i++)
    {
        switch (i)
        {
            case FMRDO_PEN_LSK:
                area = (mmi_pen_polygon_area_struct*) & fmrdo_draw_cntx_p->LSK_area;
                point = pos;
                break;
            case FMRDO_PEN_RSK:
                area = (mmi_pen_polygon_area_struct*) & fmrdo_draw_cntx_p->RSK_area;
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
            case FMRDO_PEN_MAIN_POWER:
                area = (mmi_pen_polygon_area_struct*) & skin_p->power_button_area;
                point.x = pos.x - skin_p->power_button_x;
                point.y = pos.y - skin_p->power_button_y;
                break;
        #ifdef __MMI_SLIM_IMG_RES__
            case FMRDO_PEN_MAIN_SEARCH_UP:
                area = (mmi_pen_polygon_area_struct*) & skin_p->search_up_button_area;
                point.x = pos.x - skin_p->search_up_button_x;
                point.y = pos.y - skin_p->search_up_button_y;
                break;
            case FMRDO_PEN_MAIN_SEARCH_DOWN:
                area = (mmi_pen_polygon_area_struct*) & skin_p->search_down_button_area;
                point.x = pos.x - skin_p->search_down_button_x;
                point.y = pos.y - skin_p->search_down_button_y;
                break;
        #else /* __MMI_SLIM_IMG_RES__ */
            case FMRDO_PEN_MAIN_SEARCH:
                area = (mmi_pen_polygon_area_struct*) & skin_p->search_button_area;
                point.x = pos.x - skin_p->search_button_x;
                point.y = pos.y - skin_p->search_button_y;
                break;
            case FMRDO_PEN_MAIN_SETTING:
                area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
                point.x = pos.x - skin_p->setting_x;
                point.y = pos.y - skin_p->setting_y;
                break;
            case FMRDO_PEN_MAIN_VOLUME_INC:
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_inc_area;
                point.x = pos.x - skin_p->volume_inc_x;
                point.y = pos.y - skin_p->volume_inc_y;
                break;
            case FMRDO_PEN_MAIN_VOLUME_DEC:
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_dec_area;
                point.x = pos.x - skin_p->volume_dec_x;
                point.y = pos.y - skin_p->volume_dec_y;
                break;
        #endif /* __MMI_SLIM_IMG_RES__ */
                /* TODO: Skin_p freq_area to be removed */
        }
        if (mmi_pen_check_inside_polygon(area, point))
        {
            fmrdo_draw_cntx_p->pen_event = i;
            break;
        }
    }

    switch (fmrdo_draw_cntx_p->pen_event)
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
            if (!mmi_fmrdo_need_disable_button((U8)FMRDO_BUTTON_STEP_UP))
            {
                mmi_fmrdo_press_step_up_button();
            }
            break;
        case FMRDO_PEN_MAIN_STEP_DOWN:
            if (!mmi_fmrdo_need_disable_button((U8)FMRDO_BUTTON_STEP_DOWN))
            {
                mmi_fmrdo_press_step_down_button();
            }
            break;
        case FMRDO_PEN_MAIN_POWER:
            if (!mmi_fmrdo_need_disable_button((U8)FMRDO_BUTTON_POWER))
            {
                mmi_fmrdo_press_power_button();
            }
            break;
    #ifdef __MMI_SLIM_IMG_RES__
        case FMRDO_PEN_MAIN_SEARCH_UP:
            if (!mmi_fmrdo_need_disable_button((U8)FMRDO_BUTTON_SEARCH_UP))
            {
                mmi_fmrdo_press_search_up_button();
            }
            break;
        case FMRDO_PEN_MAIN_SEARCH_DOWN:
            if (!mmi_fmrdo_need_disable_button((U8)FMRDO_BUTTON_SEARCH_DOWN))
            {
                mmi_fmrdo_press_search_down_button();
            }
            break;
    #else /* __MMI_SLIM_IMG_RES__ */
        case FMRDO_PEN_MAIN_SEARCH:
            if (!mmi_fmrdo_need_disable_button((U8)FMRDO_BUTTON_SEARCH))
            {
                mmi_fmrdo_press_search_button();
            }
            break;
        case FMRDO_PEN_MAIN_SETTING:
            if (!mmi_fmrdo_need_disable_push_button((fmrdo_main_button_enum)2))
            {
                mmi_fmrdo_redraw_main_push_down_button((U8)2, MMI_TRUE);
            }
            break;
        case FMRDO_PEN_MAIN_VOLUME_INC:
            if (!mmi_fmrdo_need_disable_push_button((fmrdo_main_button_enum)1))
            {
                mmi_fmrdo_redraw_main_push_down_button((U8)1, MMI_TRUE);
                mmi_fmrdo_inc_volume();
            }
            break;
        case FMRDO_PEN_MAIN_VOLUME_DEC:
            if (!mmi_fmrdo_need_disable_push_button((fmrdo_main_button_enum)0))
            {
                mmi_fmrdo_redraw_main_push_down_button((U8)0, MMI_TRUE);
                mmi_fmrdo_dec_volume();
            }
            break;
    #endif /* (!defined(__MMI_SLIM_IMG_RES__) */
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fmrdo_draw_cntx_p->pen_event)
    {
        case FMRDO_PEN_MAIN_STEP_UP:
            if (!mmi_fmrdo_need_disable_button((U8)FMRDO_BUTTON_STEP_UP))
            {
                mmi_fmrdo_release_step_up_button();
            }
            break;
        case FMRDO_PEN_MAIN_STEP_DOWN:
            if (!mmi_fmrdo_need_disable_button((U8)FMRDO_BUTTON_STEP_DOWN))
            {
                mmi_fmrdo_release_step_down_button();
            }
            break;
        case FMRDO_PEN_MAIN_POWER:
            if (!mmi_fmrdo_need_disable_button((U8)FMRDO_BUTTON_POWER))
            {
                mmi_fmrdo_release_power_button();
            }
            break;
    #ifdef __MMI_SLIM_IMG_RES__
        case FMRDO_PEN_MAIN_SEARCH_UP:
            if (!mmi_fmrdo_need_disable_button((U8)FMRDO_BUTTON_SEARCH_UP))
            {
                mmi_fmrdo_release_search_up_button();
            }
            break;
        case FMRDO_PEN_MAIN_SEARCH_DOWN:
            if (!mmi_fmrdo_need_disable_button((U8)FMRDO_BUTTON_SEARCH_DOWN))
            {
                mmi_fmrdo_release_search_down_button();
            }
            break;
    #else /* __MMI_SLIM_IMG_RES__ */
        case FMRDO_PEN_MAIN_SEARCH:
            if (!mmi_fmrdo_need_disable_button((U8)FMRDO_BUTTON_SEARCH))
            {
                mmi_fmrdo_release_search_button();
            }
            break;
	#ifndef __MMI_FM_PLUTO_SLIM__
        case FMRDO_PEN_MAIN_SETTING:
            if (!mmi_fmrdo_need_disable_push_button((fmrdo_main_button_enum)2))
            {
                mmi_pen_point_struct point;
                const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[g_fmrdo.skin_index];
                mmi_pen_polygon_area_struct *area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
                point.x = pos.x - skin_p->setting_x;
                point.y = pos.y - skin_p->setting_y;
                mmi_fmrdo_redraw_main_push_down_button((U8)2, MMI_FALSE);
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_entry_settings();
                }
            }
            break;
	#endif
        case FMRDO_PEN_MAIN_VOLUME_DEC:
            if (!mmi_fmrdo_need_disable_push_button((fmrdo_main_button_enum)0))
            {
                mmi_fmrdo_redraw_main_push_down_button((U8)0, MMI_FALSE);
            }
            else
            {
                g_fmrdo.is_button_down = MMI_FALSE;
                fmrdo_main_draw.volume_dec_button.down = MMI_FALSE;
            }
            break;
        case FMRDO_PEN_MAIN_VOLUME_INC:
            if (!mmi_fmrdo_need_disable_push_button((fmrdo_main_button_enum)1))
            {
                mmi_fmrdo_redraw_main_push_down_button(1, MMI_FALSE);
            }
            else
            {
                g_fmrdo.is_button_down = MMI_FALSE;
                fmrdo_main_draw.volume_inc_button.down = MMI_FALSE;
            }
            break;
     #endif /* __MMI_SLIM_IMG_RES__ */
        case FMRDO_PEN_LSK:
            if (mmi_pen_check_inside_polygon(&fmrdo_draw_cntx_p->LSK_area, pos))
            {
                ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
            }
            break;
        case FMRDO_PEN_RSK:
            if (mmi_pen_check_inside_polygon(&fmrdo_draw_cntx_p->RSK_area, pos))
            {
                ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_UP);
            }
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fmrdo_draw_cntx_p->pen_event)
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
                    MMI_BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

                    StopTimer(FMRDO_REPEAT_STEP_TIMER);
                    g_fmrdo.is_button_down = MMI_FALSE;
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
                    MMI_BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

                    StopTimer(FMRDO_REPEAT_STEP_TIMER);
                    g_fmrdo.is_button_down = MMI_FALSE;
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
                    g_fmrdo.is_button_down = MMI_FALSE;
                    mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_power_on, MMI_TRUE);
                    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
                }
            }
            break;
    #ifdef __MMI_SLIM_IMG_RES__
        case FMRDO_PEN_MAIN_SEARCH_UP:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_SEARCH_UP))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->search_up_button_area;
                point.x = pos.x - skin_p->search_up_button_x;
                point.y = pos.y - skin_p->search_up_button_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_press_search_up_button();
                }
                else
                {
                    U16 freq;
                    MMI_BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

                    StopTimer(FMRDO_REPEAT_STEP_TIMER);
                    g_fmrdo.is_button_down = MMI_FALSE;
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
        case FMRDO_PEN_MAIN_SEARCH_DOWN:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_SEARCH_DOWN))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->search_down_button_area;
                point.x = pos.x - skin_p->search_down_button_x;
                point.y = pos.y - skin_p->search_down_button_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_press_search_down_button();
                }
                else
                {
                    U16 freq;
                    MMI_BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

                    StopTimer(FMRDO_REPEAT_STEP_TIMER);
                    g_fmrdo.is_button_down = MMI_FALSE;
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
    #else /* __MMI_SLIM_IMG_RES__ */
        case FMRDO_PEN_MAIN_SEARCH:
            if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_SEARCH))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->search_button_area;
                point.x = pos.x - skin_p->search_button_x;
                point.y = pos.y - skin_p->search_button_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_press_search_button();
                }
                else
                {
                    g_fmrdo.is_button_down = MMI_FALSE;
                    mmi_fmrdo_redraw_main_toggle_button(
                        g_fmrdo.selected_button,
                        g_fmrdo.is_button_down,
                        g_fmrdo.is_search_on,
                        MMI_TRUE);
                    g_fmrdo.selected_button = (U8)FMRDO_BUTTON_NONE;
                }
            }
            break;
        case FMRDO_PEN_MAIN_SETTING:
            if (!mmi_fmrdo_need_disable_push_button((fmrdo_main_button_enum)2))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
                point.x = pos.x - skin_p->setting_x;
                point.y = pos.y - skin_p->setting_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_redraw_main_push_down_button((U8)2, MMI_TRUE);
                }
                else
                {
                    mmi_fmrdo_redraw_main_push_down_button((U8)2, MMI_FALSE);
                }
            }
            break;
        case FMRDO_PEN_MAIN_VOLUME_INC:
            if (!mmi_fmrdo_need_disable_push_button((fmrdo_main_button_enum)1))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_inc_area;
                point.x = pos.x - skin_p->volume_inc_x;
                point.y = pos.y - skin_p->volume_inc_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_redraw_main_push_down_button((U8)1, MMI_TRUE);
                }
                else
                {
                    mmi_fmrdo_redraw_main_push_down_button((U8)1, MMI_FALSE);
                }
            }
            break;
        case FMRDO_PEN_MAIN_VOLUME_DEC:
            if (!mmi_fmrdo_need_disable_push_button((fmrdo_main_button_enum)0))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_dec_area;
                point.x = pos.x - skin_p->volume_dec_x;
                point.y = pos.y - skin_p->volume_dec_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_redraw_main_push_down_button((U8)0, MMI_TRUE);
                }
                else
                {
                    mmi_fmrdo_redraw_main_push_down_button((U8)0, MMI_FALSE);
                }
            }
            break;
    #endif /* (!defined(__MMI_SLIM_IMG_RES__) */
        case FMRDO_PEN_LSK:
            if (mmi_pen_check_inside_polygon(&fmrdo_draw_cntx_p->LSK_area, pos))
            {
                mmi_fmrdo_redraw_main_LSK_down();
            }
            else
            {
                mmi_fmrdo_redraw_main_LSK_up();
                g_fmrdo.is_button_down = MMI_FALSE;
            }
            break;
        case FMRDO_PEN_RSK:
            if (mmi_pen_check_inside_polygon(&fmrdo_draw_cntx_p->RSK_area, pos))
            {
                mmi_fmrdo_redraw_main_RSK_down();
            }
            else
            {
                mmi_fmrdo_redraw_main_RSK_up();
                g_fmrdo.is_button_down = MMI_FALSE;
            }
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
#if (!defined(__MMI_SLIM_IMG_RES__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[g_fmrdo.skin_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fmrdo_draw_cntx_p->pen_event)
    {
        case FMRDO_PEN_MAIN_VOLUME_DEC:
            if (!mmi_fmrdo_need_disable_push_button((fmrdo_main_button_enum)0))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_dec_area;
                point.x = pos.x - skin_p->volume_dec_x;
                point.y = pos.y - skin_p->volume_dec_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_dec_volume();
                    mmi_fmrdo_redraw_main_push_down_button((U8)0, MMI_TRUE);
                }
            }
            break;
        case FMRDO_PEN_MAIN_VOLUME_INC:
            if (!mmi_fmrdo_need_disable_push_button((fmrdo_main_button_enum)1))
            {
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_inc_area;
                point.x = pos.x - skin_p->volume_inc_x;
                point.y = pos.y - skin_p->volume_inc_y;
                if (mmi_pen_check_inside_polygon(area, point))
                {
                    mmi_fmrdo_inc_volume();
                    mmi_fmrdo_redraw_main_push_down_button((U8)1, MMI_TRUE);
                }
            }
            break;
    }
#endif /* (!defined(__MMI_SLIM_IMG_RES__) */
}


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
        case 0:
            if ((g_fmrdo.mute)
        #ifdef __FM_RADIO_HW_SEARCH__
            || (g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
        #endif 
            )
            {
                return MMI_TRUE;
            }
            break;
        case 1:
            if ((g_fmrdo.volume == MAX_VOL_LEVEL - 1)
        #ifdef __FM_RADIO_HW_SEARCH__
            || (g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
        #endif 
            )
            {
                return MMI_TRUE;
            }
            break;
        case 2:
            if (g_fmrdo.state == FMRDO_STATE_RECORD ||
        #ifdef __FM_RADIO_HW_SEARCH__
                g_fmrdo.state == FMRDO_STATE_SEARCH_ONE ||
        #endif 
                g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
            {
                return MMI_TRUE;
            }
            break;
    }
    return MMI_FALSE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 
/* MTK Leo end */

#ifdef __MMI_FM_RADIO_ANIMATION__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_animation_draw_still
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fmrdo_animation_draw_still(void)
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
    #ifdef __GDI_MEMORY_PROFILE_2__
        mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
    #ifdef __MMI_FM_SKIN_SYN_TO_THEME__
        gdi_layer_push_and_set_active(fmrdo_draw_cntx_p->anim_layer);
    #else 
        gdi_layer_push_and_set_active(fmrdo_draw_cntx_p->skin_layer);
    #endif 
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
        gdi_image_draw(
                fmrdo_main_draw.animation.x,
                fmrdo_main_draw.animation.y,
                fmrdo_main_draw.animation.animation_img);

    #ifdef __GDI_MEMORY_PROFILE_2__
        gdi_layer_pop_and_restore_active();
        mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
    #endif
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
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    gdi_layer_push_and_set_active(fmrdo_draw_cntx_p->anim_layer);
#else 
    gdi_layer_push_and_set_active(fmrdo_draw_cntx_p->skin_layer);
#endif 
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* animation */
#ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
    if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
#endif /*__RF_DESENSE_TEST__*/
{
    fmrdo_main_draw.animation.img_handle = GDI_ERROR_HANDLE;
    gdi_anim_set_draw_before_callback(mmi_fmrdo_anim_blt_before_callback);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_anim_set_draw_after_callback(mmi_fmrdo_anim_blt_after_callback);
#endif 
    gdi_image_draw_animation(
        fmrdo_main_draw.animation.x,
        fmrdo_main_draw.animation.y,
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

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif
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
#ifndef __MMI_FM_SKIN_SYN_TO_THEME__
    S32 x1, y1, x2, y2;
    S32 width, height;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop animation */

#ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
    if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
#endif /*__RF_DESENSE_TEST__*/

{
    if (fmrdo_main_draw.animation.img_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(fmrdo_main_draw.animation.img_handle);
        fmrdo_main_draw.animation.img_handle = GDI_ERROR_HANDLE;
    #ifndef __MMI_FM_SKIN_SYN_TO_THEME__
        if (!fmrdo_draw_cntx_p->skin_layer)
        {
            return;
        }

    #ifdef __GDI_MEMORY_PROFILE_2__
        mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);

        gdi_image_get_dimension(fmrdo_main_draw.animation.animation_img, &width, &height);

        gdi_layer_push_and_set_active(fmrdo_draw_cntx_p->skin_layer);
        x1 = fmrdo_main_draw.animation.x;
        y1 = fmrdo_main_draw.animation.y;
        x2 = x1 + width;
        y2 = y1 + height;
        gdi_layer_push_and_set_clip(x1, y1, x2, y2);
        gdi_image_draw(
            fmrdo_main_draw.animation.x,
            fmrdo_main_draw.animation.y,
            fmrdo_main_draw.animation.animation_img);
        gdi_layer_pop_clip();

        gdi_layer_pop_and_restore_active();
        if (g_fmrdo.normal_repeat_step_count != 0)
        {
            mmi_fmrdo_redraw_main_frequency(g_fmrdo.step_freq, MMI_TRUE);
        }
        else
        {
            mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_TRUE);
        }
        mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
        gdi_layer_blt_previous(x1, y1, x2, y2);
    #endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */
    #endif 
    }
}
}


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
    return fmrdo_main_draw.animation.img_handle;
}
}
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    fmrdo_main_draw.LSK_text = (UI_string_type) GetString(STR_GLOBAL_PAUSE);
//    fmrdo_main_draw.RSK_text = (UI_string_type) GetString(STR_GLOBAL_STOP);
    mmi_fmrdo_change_sk(get_string(STR_GLOBAL_PAUSE), get_string(STR_GLOBAL_STOP));

#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
    mmi_fmrdo_redraw_disabled_buttons();
#endif 
//    mmi_fmrdo_redraw_main_LSK_up();
//    mmi_fmrdo_redraw_main_RSK_up();
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
//    fmrdo_main_draw.LSK_text = (UI_string_type) GetString(STR_GLOBAL_CONTINUE);
//    fmrdo_main_draw.RSK_text = (UI_string_type) GetString(STR_GLOBAL_STOP);
    mmi_fmrdo_change_sk(get_string(STR_GLOBAL_CONTINUE), get_string(STR_GLOBAL_STOP));

//    mmi_fmrdo_redraw_main_LSK_up();
//    mmi_fmrdo_redraw_main_RSK_up();
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
void mmi_fmrdo_redraw_main_time_duration(MMI_BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    U32 rec_time;
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
    x2 = fmrdo_main_draw.timer_offset_x2;
    y2 = fmrdo_main_draw.timer_offset_y2;

#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_TRUE);
#endif 

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    mmi_fmrdo_redraw_main_background(x1, y1, x2, y2);
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
#ifdef __GDI_MEMORY_PROFILE_2__
    mmi_fmrdo_set_alpha_blending_layer(MMI_FALSE);
#endif 

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
    set_softkey_label(get_string(STR_GLOBAL_STOP), MMI_LEFT_SOFTKEY);
    set_softkey_label(NULL, MMI_RIGHT_SOFTKEY);

    reset_softkeys();
    mmi_fmrdo_sk_config_set();
    wgui_softkey_update();
    mmi_fmrdo_sk_config_reset();
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
    set_softkey_label(NULL, MMI_RIGHT_SOFTKEY);
    reset_softkeys();
    mmi_fmrdo_sk_config_set();
    wgui_softkey_update();
    mmi_fmrdo_sk_config_reset();
}

#endif /* __FM_RADIO_HW_SEARCH__ */ 

#ifdef __GDI_MEMORY_PROFILE_2__
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
void mmi_fmrdo_set_alpha_blending_layer(MMI_BOOL set)
{
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
            gdi_push_and_set_alpha_blending_source_layer(fmrdo_draw_cntx_p->skin_layer);
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
}

#endif 


#ifdef __MMI_FM_SKIN_SYN_TO_THEME__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_disabled_buttons
 * DESCRIPTION
 *  Redraw screen components
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_push_button(
        FMRDO_BUTTON_STEP_DOWN,
        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN)));
    mmi_fmrdo_redraw_main_push_button(
        FMRDO_BUTTON_STEP_UP,
        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP)));
    mmi_fmrdo_redraw_main_toggle_button(
        FMRDO_BUTTON_SEARCH,
        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_SEARCH)),
        g_fmrdo.is_search_on,
        MMI_TRUE);
    mmi_fmrdo_redraw_main_toggle_button(
        FMRDO_BUTTON_POWER,
        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_POWER)),
        g_fmrdo.is_power_on,
        MMI_TRUE);
#if (defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_SLIM_IMG_RES__)))
    mmi_fmrdo_redraw_main_push_down_button(0, fmrdo_main_draw.volume_dec_button.down);
    mmi_fmrdo_redraw_main_push_down_button(1, fmrdo_main_draw.volume_inc_button.down);
    mmi_fmrdo_redraw_main_push_down_button(2, fmrdo_main_draw.setting_button.down);
#endif /* (defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_SLIM_IMG_RES__))) */ 
#if (defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FM_SKIN_SYN_TO_THEME__))
    mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_REC, MMI_FALSE, MMI_TRUE, MMI_TRUE);
#endif 
}
#endif /* __MMI_FM_SKIN_SYN_TO_THEME__ */

#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_FM_RADIO__ */ 

