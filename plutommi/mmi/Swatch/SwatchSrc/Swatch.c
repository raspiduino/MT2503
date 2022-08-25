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
 *  Swatch.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Swatch
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "mmi_features.h"

#ifdef __MMI_WEARABLE_DEVICE__
#include "globalresdef.h"
#include "gdi_include.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "gui_effect_oem.h"
#include "Wgui_categories_util.h"
#include "MiscFunctions.h"
#include "app_datetime.h"
#include "mmi_common_app_trc.h"
#include "mmi_trc_int.h"
#include "mmi_frm_input_gprot.h"
#include "idlememcfg.h"
#include "gpiosrvgprot.h"
#include "Swatch.h"
#include "SwatchGprot.h"
#include "mmi_rp_app_idle_swatch_def.h"

#ifdef __MTK_TARGET__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

/*
SWLA labels:
DB -- Draw Background
UC -- Update Clock
UAP  -- Update AP
UAPE  -- Update AP ext
*/




static mmi_idle_swatch_context_struct g_mmi_idle_swatch_cntx;
mmi_idle_swatch_context_struct *g_idle_swatch_p = &g_mmi_idle_swatch_cntx;


static mmi_idle_swatch_config_table g_swatch_config_table[] =
{
/* Swatch 1 -- Analog */
{
    /* Clock */
    {
        MMI_IDLE_SWATCH_CLOCK_TYPE_ANALOG,  //type
        {0, 0, MMI_IDLE_SWATCH_WIDTH, MMI_IDLE_SWATCH_HEIGHT-21/*AP area height*/},  //area
        {
            29, 29,  //bg_x, bg_y
            119, 119,  //center_x, center_y
            IMG_ID_IDLE_SWATCH_ANALOG_1_CLOCK_BG,  //bg_img_id
            IMG_ID_IDLE_SWATCH_ANALOG_1_HOUR_HAND,  //hour_hand_img_id
            IMG_ID_IDLE_SWATCH_ANALOG_1_MINUTE_HAND,  //minute_hand_img_id
            IMG_ID_IDLE_SWATCH_ANALOG_1_SECOND_HAND  //second_hand_img_id
        }  //data
    },
    /* AP */
    2, //ap_num
    {
        /* Step */
        {
            MMI_FALSE,  //count_is_left_of_hint
            MMI_FALSE,  //add_zero
            MMI_IDLE_SWATCH_AP_STEP,  //app
            MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE,  //hint_type
            MMI_IDLE_SWATCH_AP_INFO_TYPE_TEXT,  //count_type
            0,  //count
            mmi_idle_swatch_get_pedometer_data,  //update_func
            {0, 220, MMI_IDLE_SWATCH_WIDTH/2, MMI_IDLE_SWATCH_HEIGHT},  //area
            {
                4, MMI_IDLE_SWATCH_HEIGHT-23,  //x, y
                IMG_ID_IDLE_SWATCH_ANALOG_1_STEPS,  //image_id
                0  //image_gap
            },  //hint_data
            {
                32, 220,  //x, y
                NULL,  //text_id
                12, //font_size
                {0, 186, 255}  //font_color
            }  //count_data
        },
        /* Calorie */
        {
            MMI_TRUE,  //count_is_left_of_hint
            MMI_FALSE,  //add_zero
            MMI_IDLE_SWATCH_AP_CALORIE,  //app
            MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE,  //hint_type
            MMI_IDLE_SWATCH_AP_INFO_TYPE_TEXT,  //count_type
            0,  //count
            mmi_idle_swatch_get_pedometer_data,  //update_func
            {MMI_IDLE_SWATCH_WIDTH/2, 220, MMI_IDLE_SWATCH_WIDTH, MMI_IDLE_SWATCH_HEIGHT},  //area
            {
                MMI_IDLE_SWATCH_WIDTH-23, MMI_IDLE_SWATCH_HEIGHT-23,  //x, y
                IMG_ID_IDLE_SWATCH_ANALOG_1_CALORIES,  //image_id
                0  //image_gap
            },  //hint_data
            {
                206, 220,  //x, y
                NULL,  //text_id
                12, //font_size
                {0, 186, 255}  //font_color
            }  //count_data
        }
    }
},
/* Swatch 2 -- Digital */
{
    /* Clock */
    {
        MMI_IDLE_SWATCH_CLOCK_TYPE_DIGITAL,  //type
        {0, 0, MMI_IDLE_SWATCH_WIDTH, MMI_IDLE_SWATCH_HEIGHT-35},  //area
        {
            0, MMI_IDLE_SWATCH_HEIGHT-86,  //bg_x, bg_y
            26, 50,  //hour_x, hour_y
            160, 55,  //minute_x, minute_y
            160, 99,  //ampm_x, ampm_y
            4, 0,  //hour_num_gap, minute__num_gap
            IMG_ID_IDLE_SWATCH_DIGITAL_1_CLOCK_BG,  //bg_img_id
            IMG_ID_IDLE_SWATCH_DIGITAL_1_HOUR_NUM_0,  //hour_num_img_id
            IMG_ID_IDLE_SWATCH_DIGITAL_1_MINUTE_NUM_0,  //minute_num_img_id
            IMG_ID_IDLE_SWATCH_DIGITAL_1_AM,  //am_img_id
            IMG_ID_IDLE_SWATCH_DIGITAL_1_PM,  //pm_img_id
            MMI_TRUE  //add_zero
        }  //data
    },
    /* AP */
    2, //ap_num
    {
        /* Step */
        {
            MMI_FALSE,  //count_is_left_of_hint
            MMI_FALSE,  //add_zero
            MMI_IDLE_SWATCH_AP_STEP,  //app
            MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE,  //hint_type  hint is useless in this style
            MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE,  //count_type  count will use image in this style
            0,  //count
            mmi_idle_swatch_get_pedometer_data,  //update_func
            {0, MMI_IDLE_SWATCH_HEIGHT-35, MMI_IDLE_SWATCH_WIDTH/2, MMI_IDLE_SWATCH_HEIGHT},  //area
            {
                0, 0,  //x, y
                NULL,  //image_id
                0  //image_gap
            },  //hint_data
            {
                14, MMI_IDLE_SWATCH_HEIGHT-34,  //x, y
                IMG_ID_IDLE_SWATCH_DIGITAL_1_COUNT_NUM_0,  //image_id
                0  //image_gap
            }  //count_data
        },
        /* Calorie */
        {
            MMI_FALSE,  //count_is_left_of_hint
            MMI_FALSE,  //add_zero
            MMI_IDLE_SWATCH_AP_CALORIE,  //app
            MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE,  //hint_type  hint is useless in this style
            MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE,  //count_type  count will use image in this style
            0,  //count
            mmi_idle_swatch_get_pedometer_data,  //update_func
            {MMI_IDLE_SWATCH_WIDTH/2, MMI_IDLE_SWATCH_HEIGHT-35, MMI_IDLE_SWATCH_WIDTH, MMI_IDLE_SWATCH_HEIGHT},  //area
            {
                0, 0,  //x, y
                NULL,  //image_id
                0  //image_gap
            },  //hint_data
            {
                133, MMI_IDLE_SWATCH_HEIGHT-34,  //x, y
                IMG_ID_IDLE_SWATCH_DIGITAL_1_COUNT_NUM_0,  //image_id
                0  //image_gap
            }  //count_data
        }
    }
},
/* Swatch 3 -- Digital */
{
    /* Clock */
    {
        MMI_IDLE_SWATCH_CLOCK_TYPE_DIGITAL,  //type
        {0, 0, MMI_IDLE_SWATCH_WIDTH, MMI_IDLE_SWATCH_HEIGHT-33},  //area
        {
            0, 0,  //bg_x, bg_y
            60, 81,  //hour_x, hour_y
            149, 90,  //minute_x, minute_y
            149, 112,  //ampm_x, ampm_y
            1, 0,  //hour_num_gap, minute__num_gap
            IMG_ID_IDLE_SWATCH_DIGITAL_2_CLOCK_BG,  //bg_img_id
            IMG_ID_IDLE_SWATCH_DIGITAL_2_HOUR_NUM_0,  //hour_num_img_id
            IMG_ID_IDLE_SWATCH_DIGITAL_2_MINUTE_NUM_0,  //minute_num_img_id
            IMG_ID_IDLE_SWATCH_DIGITAL_2_AM,  //am_img_id
            IMG_ID_IDLE_SWATCH_DIGITAL_2_PM,  //pm_img_id
            MMI_TRUE  //add_zero
        }  //data
    },
    /* AP */
    2, //ap_num
    {
        /* Step */
        {
            MMI_FALSE,  //count_is_left_of_hint
            MMI_FALSE,  //add_zero
            MMI_IDLE_SWATCH_AP_STEP,  //app
            MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE,  //hint_type  hint is useless in this style
            MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE,  //count_type  count will use image in this style
            0,  //count
            mmi_idle_swatch_get_pedometer_data,  //update_func
            {0, MMI_IDLE_SWATCH_HEIGHT-33, MMI_IDLE_SWATCH_WIDTH/2, MMI_IDLE_SWATCH_HEIGHT},  //area
            {
                0, 0,  //x, y
                NULL,  //image_id
                0  //image_gap
            },  //hint_data
            {
                56, MMI_IDLE_SWATCH_HEIGHT-32,  //x, y
                IMG_ID_IDLE_SWATCH_DIGITAL_2_COUNT_NUM_0,  //image_id
                0  //image_gap
            }  //count_data
        },
        /* Calorie */
        {
            MMI_TRUE,  //count_is_left_of_hint
            MMI_FALSE,  //add_zero
            MMI_IDLE_SWATCH_AP_CALORIE,  //app
            MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE,  //hint_type  hint is useless in this style
            MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE,  //count_type  count will use image in this style
            0,  //count
            mmi_idle_swatch_get_pedometer_data,  //update_func
            {MMI_IDLE_SWATCH_WIDTH/2, MMI_IDLE_SWATCH_HEIGHT-33, MMI_IDLE_SWATCH_WIDTH, MMI_IDLE_SWATCH_HEIGHT},  //area
            {
                0, 0,  //x, y
                NULL,  //image_id
                0  //image_gap
            },  //hint_data
            {
                MMI_IDLE_SWATCH_WIDTH-56, MMI_IDLE_SWATCH_HEIGHT-32,  //x, y
                IMG_ID_IDLE_SWATCH_DIGITAL_2_COUNT_NUM_0,  //image_id
                0  //image_gap
            }  //count_data
        }
    }
},
};





/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_get_pedometer_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app
 *  count
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_get_pedometer_data(MMI_IDLE_SWATCH_AP_ENUM app, U32* count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_swatch_pedometer_data pedometer_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_swatch_p->pedometer_cb != NULL)
    {
        g_idle_swatch_p->pedometer_cb(&pedometer_data);
        if (app == MMI_IDLE_SWATCH_AP_STEP)
        {
            *count = pedometer_data.steps;
        }
        else if (app == MMI_IDLE_SWATCH_AP_CALORIE)
        {
            *count = pedometer_data.calories;
        }

        MMI_TRACE(MOD_MMI_COMMON_APP, TRC_IDLE_SWATCH_TEST, 0, *count);
        if (*count >= MMI_IDLE_SWATCH_AP_COUNT_MAX_NUM)
        {
            *count = (U32)MMI_IDLE_SWATCH_AP_COUNT_MAX_NUM - 1;
        }
    }
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_pedometer_resgiter_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_pedometer_resgiter_callback(mmi_idle_swatch_pedometer_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_swatch_p->pedometer_cb = cb;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_setting_draw_ok
 * DESCRIPTION
 *  This function is used to draw the ok button.
 * PARAMETERS
 *  is_press [IN]
 *  need_blt [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_setting_draw_ok(MMI_BOOL is_press, MMI_BOOL need_blt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = MMI_IDLE_SWATCH_PREVIEW_OK_X_OFFSET;
    y1 = MMI_IDLE_SWATCH_PREVIEW_OK_Y_OFFSET;
    x2 = MMI_IDLE_SWATCH_PREVIEW_OK_X_OFFSET + MMI_IDLE_SWATCH_PREVIEW_OK_WIDTH;
    y2 = MMI_IDLE_SWATCH_PREVIEW_OK_Y_OFFSET + MMI_IDLE_SWATCH_PREVIEW_OK_HEIGHT;

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    
    //ok
    if (is_press)
    {
        gdi_image_draw_id(x1, y1, IMG_ID_IDLE_SWATCH_PREVIEW_OK_DOWN);
    }
    else
    {
        gdi_image_draw_id(x1, y1, IMG_ID_IDLE_SWATCH_PREVIEW_OK);
    }

    gdi_layer_pop_clip();

    if (need_blt)
    {
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_setting_draw_preview
 * DESCRIPTION
 *  This function is used to draw preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_setting_draw_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width, image_height;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_setting_draw_preview,moving_x=%d,ssp_state:%d\n", g_idle_swatch_p->moving_x, g_idle_swatch_p->ssp_state);
    x1 = 0;
    y1 = MMI_status_bar_height;
    x2 = MMI_IDLE_SWATCH_WIDTH;
    y2 = MMI_IDLE_SWATCH_HEIGHT;
    
    if (mmi_frm_scrn_get_active_id() != SCR_ID_SWATCH_SETTING)
    {
        return;
    }
    
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);

    #ifdef __MMI_TOUCH_SCREEN__
    if (g_idle_swatch_p->ssp_state != MMI_IDLE_SWATCH_SETTING_SSP_STATE_NONE)
    {
        U8 i, swatch_num = sizeof(g_swatch_config_table) / sizeof(mmi_idle_swatch_config_table);

        //preview
        for (i = 0; i < swatch_num; i++)
        {
            S32 left_x = (i-g_idle_swatch_p->setting_swatch_index)*MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE+g_idle_swatch_p->moving_x+MMI_IDLE_SWATCH_SETTING_START_X_IN_MOVE;
            S32 right_x = left_x + MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE;
            if ((left_x > 0 && left_x < MMI_IDLE_SWATCH_WIDTH) ||
                (right_x > 0 && right_x < MMI_IDLE_SWATCH_WIDTH))
            {
                //draw bg
                gdi_image_draw_resized_id(left_x, MMI_IDLE_SWATCH_PREVIEW_BG_Y, MMI_IDLE_SWATCH_PREVIEW_BG_WIDTH, MMI_IDLE_SWATCH_PREVIEW_BG_HEIGHT, IMG_ID_IDLE_SWATCH_PREVIEW_BG);
                
                gdi_image_get_dimension_id(IMG_ID_IDLE_SWATCH_PREVIEW_1+i, &image_width, &image_height);
                gdi_image_draw_id(left_x+(MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE-image_width)/2,
                    MMI_IDLE_SWATCH_PREVIEW_CENTER_Y-image_height/2-(image_height%2 > 0 ? 1 : 0), 
                    IMG_ID_IDLE_SWATCH_PREVIEW_1+i);
            }
            //loop
            else if (MMI_IDLE_SWATCH_ABS(i-g_idle_swatch_p->setting_swatch_index) == swatch_num-1)
            {
                if (g_idle_swatch_p->setting_swatch_index == 0)
                {
                    //show the last
                    left_x = -MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE+g_idle_swatch_p->moving_x+MMI_IDLE_SWATCH_SETTING_START_X_IN_MOVE;
                    right_x = left_x + MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE;
                    if ((left_x > 0 && left_x < MMI_IDLE_SWATCH_WIDTH) ||
                        (right_x > 0 && right_x < MMI_IDLE_SWATCH_WIDTH))
                    {
                        //draw bg
                        gdi_image_draw_resized_id(left_x, MMI_IDLE_SWATCH_PREVIEW_BG_Y, MMI_IDLE_SWATCH_PREVIEW_BG_WIDTH, MMI_IDLE_SWATCH_PREVIEW_BG_HEIGHT, IMG_ID_IDLE_SWATCH_PREVIEW_BG);
                        
                        gdi_image_get_dimension_id(IMG_ID_IDLE_SWATCH_PREVIEW_1+i, &image_width, &image_height);
                        gdi_image_draw_id(left_x+(MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE-image_width)/2,
                            MMI_IDLE_SWATCH_PREVIEW_CENTER_Y-image_height/2-(image_height%2 > 0 ? 1 : 0), 
                            IMG_ID_IDLE_SWATCH_PREVIEW_1+i);
                    }
                }
                else
                {
                    //show the first
                    left_x = MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE+g_idle_swatch_p->moving_x+MMI_IDLE_SWATCH_SETTING_START_X_IN_MOVE;
                    right_x = left_x + MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE;
                    if ((left_x > 0 && left_x < MMI_IDLE_SWATCH_WIDTH) ||
                        (right_x > 0 && right_x < MMI_IDLE_SWATCH_WIDTH))
                    {
                        //draw bg
                        gdi_image_draw_resized_id(left_x, MMI_IDLE_SWATCH_PREVIEW_BG_Y, MMI_IDLE_SWATCH_PREVIEW_BG_WIDTH, MMI_IDLE_SWATCH_PREVIEW_BG_HEIGHT, IMG_ID_IDLE_SWATCH_PREVIEW_BG);
                        
                        gdi_image_get_dimension_id(IMG_ID_IDLE_SWATCH_PREVIEW_1+i, &image_width, &image_height);
                        gdi_image_draw_id(left_x+(MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE-image_width)/2,
                            MMI_IDLE_SWATCH_PREVIEW_CENTER_Y-image_height/2-(image_height%2 > 0 ? 1 : 0), 
                            IMG_ID_IDLE_SWATCH_PREVIEW_1+i);
                    }
                }
            }
        }
        
        //there are three previews
        if (MMI_IDLE_SWATCH_ABS(g_idle_swatch_p->moving_x) >= MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE)
        {
            S32 left_x, right_x;
            
            if (g_idle_swatch_p->setting_swatch_index == 0)
            {
                left_x = -2 * MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE+g_idle_swatch_p->moving_x+MMI_IDLE_SWATCH_SETTING_START_X_IN_MOVE;
                right_x = left_x + MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE;
                if ((left_x > 0 && left_x < MMI_IDLE_SWATCH_WIDTH) ||
                    (right_x > 0 && right_x < MMI_IDLE_SWATCH_WIDTH))
                {
                    //draw bg
                    gdi_image_draw_resized_id(left_x, MMI_IDLE_SWATCH_PREVIEW_BG_Y, MMI_IDLE_SWATCH_PREVIEW_BG_WIDTH, MMI_IDLE_SWATCH_PREVIEW_BG_HEIGHT, IMG_ID_IDLE_SWATCH_PREVIEW_BG);
                    
                    gdi_image_get_dimension_id(IMG_ID_IDLE_SWATCH_PREVIEW_1+swatch_num-2, &image_width, &image_height);
                    gdi_image_draw_id(left_x+(MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE-image_width)/2,
                        MMI_IDLE_SWATCH_PREVIEW_CENTER_Y-image_height/2-(image_height%2 > 0 ? 1 : 0), 
                        IMG_ID_IDLE_SWATCH_PREVIEW_1+swatch_num-2);
                }
            }
            else if (g_idle_swatch_p->setting_swatch_index == swatch_num-1)
            {
                left_x = 2 * MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE+g_idle_swatch_p->moving_x+MMI_IDLE_SWATCH_SETTING_START_X_IN_MOVE;
                right_x = left_x + MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE;
                if ((left_x > 0 && left_x < MMI_IDLE_SWATCH_WIDTH) ||
                    (right_x > 0 && right_x < MMI_IDLE_SWATCH_WIDTH))
                {
                    //draw bg
                    gdi_image_draw_resized_id(left_x, MMI_IDLE_SWATCH_PREVIEW_BG_Y, MMI_IDLE_SWATCH_PREVIEW_BG_WIDTH, MMI_IDLE_SWATCH_PREVIEW_BG_HEIGHT, IMG_ID_IDLE_SWATCH_PREVIEW_BG);
                    
                    gdi_image_get_dimension_id(IMG_ID_IDLE_SWATCH_PREVIEW_1+1, &image_width, &image_height);
                    gdi_image_draw_id(left_x+(MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE-image_width)/2,
                        MMI_IDLE_SWATCH_PREVIEW_CENTER_Y-image_height/2-(image_height%2 > 0 ? 1 : 0), 
                        IMG_ID_IDLE_SWATCH_PREVIEW_1+1);
                }
            }
            else
            {
                if (g_idle_swatch_p->setting_swatch_index - 1 == 0)
                {
                    left_x = -2 * MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE+g_idle_swatch_p->moving_x+MMI_IDLE_SWATCH_SETTING_START_X_IN_MOVE;
                    right_x = left_x + MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE;
                    if ((left_x > 0 && left_x < MMI_IDLE_SWATCH_WIDTH) ||
                        (right_x > 0 && right_x < MMI_IDLE_SWATCH_WIDTH))
                    {
                        //draw bg
                        gdi_image_draw_resized_id(left_x, MMI_IDLE_SWATCH_PREVIEW_BG_Y, MMI_IDLE_SWATCH_PREVIEW_BG_WIDTH, MMI_IDLE_SWATCH_PREVIEW_BG_HEIGHT, IMG_ID_IDLE_SWATCH_PREVIEW_BG);
                        
                        gdi_image_get_dimension_id(IMG_ID_IDLE_SWATCH_PREVIEW_1+swatch_num-1, &image_width, &image_height);
                        gdi_image_draw_id(left_x+(MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE-image_width)/2,
                            MMI_IDLE_SWATCH_PREVIEW_CENTER_Y-image_height/2-(image_height%2 > 0 ? 1 : 0), 
                            IMG_ID_IDLE_SWATCH_PREVIEW_1+swatch_num-1);
                    }
                }
                if (g_idle_swatch_p->setting_swatch_index + 1 == swatch_num-1)
                {
                    left_x = 2 * MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE+g_idle_swatch_p->moving_x+MMI_IDLE_SWATCH_SETTING_START_X_IN_MOVE;
                    right_x = left_x + MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE;
                    if ((left_x > 0 && left_x < MMI_IDLE_SWATCH_WIDTH) ||
                        (right_x > 0 && right_x < MMI_IDLE_SWATCH_WIDTH))
                    {
                        //draw bg
                        gdi_image_draw_resized_id(left_x, MMI_IDLE_SWATCH_PREVIEW_BG_Y, MMI_IDLE_SWATCH_PREVIEW_BG_WIDTH, MMI_IDLE_SWATCH_PREVIEW_BG_HEIGHT, IMG_ID_IDLE_SWATCH_PREVIEW_BG);
                        
                        gdi_image_get_dimension_id(IMG_ID_IDLE_SWATCH_PREVIEW_1, &image_width, &image_height);
                        gdi_image_draw_id(left_x+(MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE-image_width)/2,
                            MMI_IDLE_SWATCH_PREVIEW_CENTER_Y-image_height/2-(image_height%2 > 0 ? 1 : 0), 
                            IMG_ID_IDLE_SWATCH_PREVIEW_1);
                    }
                }
            }
        }
        
        gdi_layer_pop_clip();
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
    else
    #endif  //__MMI_TOUCH_SCREEN__
    {
        //draw bg
        gdi_image_draw_resized_id(MMI_IDLE_SWATCH_PREVIEW_BG_X, MMI_IDLE_SWATCH_PREVIEW_BG_Y, MMI_IDLE_SWATCH_PREVIEW_BG_WIDTH, MMI_IDLE_SWATCH_PREVIEW_BG_HEIGHT, IMG_ID_IDLE_SWATCH_PREVIEW_BG);
        
        //left arrow
        gdi_image_draw_id(MMI_IDLE_SWATCH_PREVIEW_ARROW_X_OFFSET, MMI_IDLE_SWATCH_PREVIEW_ARROW_Y_OFFSET, IMG_ID_IDLE_SWATCH_PREVIEW_LEFT);
        //right arrow
        gdi_image_draw_id(MMI_IDLE_SWATCH_WIDTH-MMI_IDLE_SWATCH_PREVIEW_ARROW_X_OFFSET-MMI_IDLE_SWATCH_PREVIEW_ARROW_WIDTH, 
            MMI_IDLE_SWATCH_PREVIEW_ARROW_Y_OFFSET, IMG_ID_IDLE_SWATCH_PREVIEW_RIGHT);
        //ok button
        mmi_idle_swatch_setting_draw_ok(MMI_FALSE, MMI_FALSE);

        //preview
        gdi_image_get_dimension_id(IMG_ID_IDLE_SWATCH_PREVIEW_1+g_idle_swatch_p->setting_swatch_index, &image_width, &image_height);
        gdi_image_draw_id((MMI_IDLE_SWATCH_WIDTH-image_width)/2, MMI_IDLE_SWATCH_PREVIEW_CENTER_Y-image_height/2-(image_height%2 > 0 ? 1 : 0), 
            IMG_ID_IDLE_SWATCH_PREVIEW_1+g_idle_swatch_p->setting_swatch_index);
        gdi_layer_pop_clip();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_setting_show_preview
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category9100 screen.
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_setting_show_preview(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_swatch_setting_draw_preview();
}


#if defined(__MMI_TOUCH_SCREEN__)

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_setting_ssp_free_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_setting_ssp_free_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_setting_ssp_free_run,moving_x:%d\n", g_idle_swatch_p->moving_x);
    gui_cancel_timer(mmi_idle_swatch_setting_ssp_free_run);
    
    if (mmi_frm_scrn_get_active_id() != SCR_ID_SWATCH_SETTING)
    {
        return;
    }
    
    if (MMI_IDLE_SWATCH_ABS(g_idle_swatch_p->moving_x) > 0)
    {
        g_idle_swatch_p->ssp_state = MMI_IDLE_SWATCH_SETTING_SSP_STATE_FREE_RUN;
        if (g_idle_swatch_p->moving_x > 0)
        {
            g_idle_swatch_p->moving_x -= MMI_IDLE_SWATCH_SETTING_FREE_RUN_SPEED;
            g_idle_swatch_p->moving_x = g_idle_swatch_p->moving_x < 0 ? 0 : g_idle_swatch_p->moving_x;
        }
        else
        {
            g_idle_swatch_p->moving_x += MMI_IDLE_SWATCH_SETTING_FREE_RUN_SPEED;
            g_idle_swatch_p->moving_x = g_idle_swatch_p->moving_x > 0 ? 0 : g_idle_swatch_p->moving_x;
        }
        mmi_idle_swatch_setting_draw_preview();
        gui_start_timer(MMI_IDLE_SWATCH_SETTING_FREE_RUN_DELAY, mmi_idle_swatch_setting_ssp_free_run);
    }
    else
    {
        g_idle_swatch_p->ssp_state = MMI_IDLE_SWATCH_SETTING_SSP_STATE_NONE;
        dm_redraw_category_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_setting_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos      :[IN]   coordinate of point      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_setting_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_swatch_p->setting_pre_point.x = pos.x;
    g_idle_swatch_p->setting_pre_point.y = pos.y;
    if (g_idle_swatch_p->ssp_state == MMI_IDLE_SWATCH_SETTING_SSP_STATE_NONE &&
        pos.x > (MMI_IDLE_SWATCH_PREVIEW_OK_X_OFFSET-MMI_IDLE_SWATCH_PREVIEW_OK_THRESHOLD) &&
        pos.x < (MMI_IDLE_SWATCH_PREVIEW_OK_X_OFFSET+MMI_IDLE_SWATCH_PREVIEW_OK_WIDTH+MMI_IDLE_SWATCH_PREVIEW_OK_THRESHOLD) &&
        pos.y > (MMI_IDLE_SWATCH_PREVIEW_OK_Y_OFFSET-MMI_IDLE_SWATCH_PREVIEW_OK_THRESHOLD) &&
        pos.y < (MMI_IDLE_SWATCH_PREVIEW_OK_Y_OFFSET+MMI_IDLE_SWATCH_PREVIEW_OK_HEIGHT+MMI_IDLE_SWATCH_PREVIEW_OK_THRESHOLD))
    {
        g_idle_swatch_p->is_selected = MMI_TRUE;
        mmi_idle_swatch_setting_draw_ok(MMI_TRUE, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_setting_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos      :[IN]   coordinate of point      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_setting_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x_diff = pos.x - g_idle_swatch_p->setting_pre_point.x;
    S16 y_diff = pos.y - g_idle_swatch_p->setting_pre_point.y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_setting_pen_move_hdlr,pos.x:%d,pre_point.x:%d,moving_x:%d\n", pos.x, g_idle_swatch_p->setting_pre_point.x, g_idle_swatch_p->moving_x);
    if (MMI_IDLE_SWATCH_ABS(x_diff) > MMI_IDLE_SWATCH_SETTING_MOVE_THRESHOLD || MMI_IDLE_SWATCH_ABS(y_diff) > MMI_IDLE_SWATCH_SETTING_MOVE_THRESHOLD
        || !g_idle_swatch_p->is_selected)
    {
        g_idle_swatch_p->is_selected = MMI_FALSE;
        g_idle_swatch_p->ssp_state = MMI_IDLE_SWATCH_SETTING_SSP_STATE_MOVE;
        g_idle_swatch_p->moving_x += x_diff;
        g_idle_swatch_p->setting_pre_point.x = pos.x;
        g_idle_swatch_p->setting_pre_point.y = pos.y;
        mmi_idle_swatch_setting_draw_preview();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_setting_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos      :[IN]   coordinate of point      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_setting_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_setting_pen_up_hdlr,moving_x:%d\n", g_idle_swatch_p->moving_x);
    if (g_idle_swatch_p->is_selected)
    {
        S16 error;
        g_idle_swatch_p->swatch_index = g_idle_swatch_p->setting_swatch_index;
        //write swatch index record
        WriteValue(NVRAM_IDLE_SWATCH_INDEX, &(g_idle_swatch_p->swatch_index), DS_BYTE, &error);
        mmi_frm_group_close(GRP_ID_SWATCH_SETTING);
    }
    else
    {
        U8 swatch_num = sizeof(g_swatch_config_table) / sizeof(mmi_idle_swatch_config_table);
        S8 swatch_offset = MMI_IDLE_SWATCH_ABS(g_idle_swatch_p->moving_x / MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE);

        if (swatch_offset > 0)
        {
            if (g_idle_swatch_p->moving_x > 0)
            {
                if (g_idle_swatch_p->setting_swatch_index >= swatch_offset)
                {
                    g_idle_swatch_p->setting_swatch_index -= swatch_offset;
                }
                else
                {
                    g_idle_swatch_p->setting_swatch_index = swatch_num - (swatch_offset - g_idle_swatch_p->setting_swatch_index);
                }
            }
            else
            {
                if (g_idle_swatch_p->setting_swatch_index + swatch_offset < swatch_num)
                {
                    g_idle_swatch_p->setting_swatch_index += swatch_offset;
                }
                else
                {
                    g_idle_swatch_p->setting_swatch_index = swatch_offset - (swatch_num - g_idle_swatch_p->setting_swatch_index);
                }
            }
            g_idle_swatch_p->moving_x = g_idle_swatch_p->moving_x % MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE;
        }
        if (MMI_IDLE_SWATCH_ABS(g_idle_swatch_p->moving_x) > MMI_IDLE_SWATCH_SETTING_MOVE_SWITCH_THRESHOLD)
        {
            if (g_idle_swatch_p->moving_x < 0)
            {
                if (g_idle_swatch_p->setting_swatch_index < (swatch_num-1))
                {
                    g_idle_swatch_p->setting_swatch_index++;
                }
                else
                {
                    g_idle_swatch_p->setting_swatch_index = 0;
                }
            }
            else
            {
                if (g_idle_swatch_p->setting_swatch_index > 0)
                {
                    g_idle_swatch_p->setting_swatch_index--;
                }
                else
                {
                    g_idle_swatch_p->setting_swatch_index = swatch_num - 1;
                }
            }
            
            if (g_idle_swatch_p->moving_x > 0)
            {
                g_idle_swatch_p->moving_x = g_idle_swatch_p->moving_x - MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE;
            }
            else
            {
                g_idle_swatch_p->moving_x = g_idle_swatch_p->moving_x + MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE;
            }
        }
        
        mmi_idle_swatch_setting_ssp_free_run();;
    }
    
    g_idle_swatch_p->is_selected = MMI_FALSE;
}

#endif  //defined(__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_setting_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_setting_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_swatch_p->setting_swatch_index = g_idle_swatch_p->swatch_index;
    #ifdef __MMI_TOUCH_SCREEN__
    g_idle_swatch_p->moving_x = 0;
    g_idle_swatch_p->ssp_state = MMI_IDLE_SWATCH_SETTING_SSP_STATE_NONE;
    #endif  //__MMI_TOUCH_SCREEN__    
    
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_ENTER_MAINMENU); 
    
    entry_full_screen();
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    
    dm_register_category_controlled_callback(mmi_idle_swatch_setting_show_preview);
    wgui_cat_setup_category_default_history(MMI_CAT9100_ID, NULL, NULL);
    dm_redraw_category_screen();
    
    clear_key_handlers();
#if defined(__MMI_TOUCH_SCREEN__)
    wgui_clear_pen_handlers();
    wgui_register_pen_down_handler(mmi_idle_swatch_setting_pen_down_hdlr);
    wgui_register_pen_move_handler(mmi_idle_swatch_setting_pen_move_hdlr);
    wgui_register_pen_up_handler(mmi_idle_swatch_setting_pen_up_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_setting_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param      :[IN]   event      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_idle_swatch_setting_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            break;
        }
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_idle_swatch_setting_entry();
            break;
        }
        case EVT_ID_SCRN_INACTIVE:
        case EVT_ID_SCRN_DEINIT:
        {            
            gui_cancel_timer(mmi_idle_swatch_setting_ssp_free_run);
            clear_key_handlers();
            #if defined(__MMI_TOUCH_SCREEN__)
            wgui_clear_pen_handlers();
            #endif  //defined(__MMI_TOUCH_SCREEN__)
            break;
        }
    }
    
    return MMI_RET_OK;
}


#if defined(__MMI_TOUCH_SCREEN__)

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos      :[IN]   coordinate of point      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_pen_down_hdlr(mmi_pen_point_struct pos)
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
 *  mmi_idle_swatch_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos      :[IN]   coordinate of point      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryMainMenuFromIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_long_tap_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos      :[IN]   coordinate of point      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_long_tap_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_create_ex(
        g_idle_swatch_p->group_id, 
        GRP_ID_SWATCH_SETTING, 
        mmi_idle_swatch_setting_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    MMI_ASSERT(group_id != GRP_ID_INVALID);
    StopTimer(IDLE_SWATCH_UPDATE_TIMER);

    mmi_frm_scrn_create(
         GRP_ID_SWATCH_SETTING, 
         SCR_ID_SWATCH_SETTING, 
         mmi_idle_swatch_setting_proc,   
        NULL);
}

#endif  //defined(__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_register_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_register_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetKeyHandler(EntryMainMenuFromIdleScreen, KEY_POWER, KEY_EVENT_UP);     
    SetKeyHandler(EntryMainMenuFromIdleScreen, KEY_END, KEY_EVENT_UP); 
    
#if defined(__MMI_TOUCH_SCREEN__)
    wgui_register_pen_down_handler(mmi_idle_swatch_pen_down_hdlr);
    wgui_register_pen_long_tap_handler(mmi_idle_swatch_long_tap_hdlr);
    wgui_register_pen_up_handler(mmi_idle_swatch_pen_up_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_create_adm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_create_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Create MemoryPool */
    if (g_idle_swatch_p->app_mem_pool != NULL && g_idle_swatch_p->adm_pool_id == NULL)
    {
        g_idle_swatch_p->adm_pool_id = kal_adm_create((void*)g_idle_swatch_p->app_mem_pool,
                                                    MMI_IDLE_SWATCH_MEM_SIZE,
                                                    NULL,
                                                    KAL_FALSE);
        ASSERT(g_idle_swatch_p->adm_pool_id != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_delete_adm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_delete_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Delete ADM */
    if (g_idle_swatch_p->adm_pool_id != NULL)
    {
        ret = kal_adm_delete(g_idle_swatch_p->adm_pool_id);

        ASSERT(ret == KAL_SUCCESS);
        g_idle_swatch_p->adm_pool_id = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_alloc_adm_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_alloc_adm_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
    
    /* Update layer */
    g_idle_swatch_p->update_layer_buf_ptr =
        (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(g_idle_swatch_p->adm_pool_id, MMI_IDLE_SWATCH_UPDATE_LAYER_BUFFER_SIZE);
    MMI_ASSERT(g_idle_swatch_p->update_layer_buf_ptr != NULL);
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_32_PARGB,
        0,
        0,
        MMI_IDLE_SWATCH_WIDTH,
        MMI_IDLE_SWATCH_HEIGHT,
        &g_idle_swatch_p->update_layer_handle,
        g_idle_swatch_p->update_layer_buf_ptr,
        MMI_IDLE_SWATCH_UPDATE_LAYER_BUFFER_SIZE);
    MMI_ASSERT(g_idle_swatch_p->update_layer_handle != NULL);
    
    /* Status bar layer */
    g_idle_swatch_p->status_icon_bar_layer_buf_ptr =
        (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(g_idle_swatch_p->adm_pool_id, MMI_IDLE_SWATCH_STATUS_BAR_BUFFER_SIZE);
    MMI_ASSERT(g_idle_swatch_p->status_icon_bar_layer_buf_ptr != NULL);
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_32_PARGB,
        0,
        0,
        MMI_IDLE_SWATCH_WIDTH,
        MMI_STATUS_BAR_HEIGHT,
        &g_idle_swatch_p->status_icon_bar_layer_handle,
        g_idle_swatch_p->status_icon_bar_layer_buf_ptr,
        MMI_IDLE_SWATCH_STATUS_BAR_BUFFER_SIZE);    
    MMI_ASSERT(g_idle_swatch_p->status_icon_bar_layer_handle != NULL); 
    
    gdi_layer_push_and_set_active(g_idle_swatch_p->status_icon_bar_layer_handle);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR, g_idle_swatch_p->status_icon_bar_layer_handle);

    /* Set status bar's blending layer */
    wgui_status_icon_bar_set_alpha_blend_layer(
        WGUI_STATUS_ICON_BAR_H_BAR, g_idle_swatch_p->update_layer_handle);

    /* Register draw-background callback */
    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_H_BAR,
        hide_status_icons_bar0_by_transparent);

    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);

    /* Temp layer */
    g_idle_swatch_p->temp_layer_buf_ptr =
        (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(g_idle_swatch_p->adm_pool_id, MMI_IDLE_SWATCH_TEMP_LAYER_BUFFER_SIZE);
    MMI_ASSERT(g_idle_swatch_p->temp_layer_buf_ptr != NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_free_adm_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_free_adm_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* Free update layer */ 
    if (g_idle_swatch_p->update_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_idle_swatch_p->update_layer_handle);
        g_idle_swatch_p->update_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (g_idle_swatch_p->update_layer_buf_ptr != NULL)
    {
        kal_adm_free(g_idle_swatch_p->adm_pool_id, (void*)g_idle_swatch_p->update_layer_buf_ptr);
        g_idle_swatch_p->update_layer_buf_ptr = NULL;
    }
    
    /* Free status bar layer */  
    wgui_status_icon_bar_reset_alpha_blend_layer(WGUI_STATUS_ICON_BAR_H_BAR);

    if (g_idle_swatch_p->status_icon_bar_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        /* Reset status bar layer config */
        wgui_status_icon_bar_set_target_layer(
            WGUI_STATUS_ICON_BAR_H_BAR, GDI_ERROR_HANDLE);

        gdi_layer_free(g_idle_swatch_p->status_icon_bar_layer_handle);
        g_idle_swatch_p->status_icon_bar_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (g_idle_swatch_p->status_icon_bar_layer_buf_ptr != NULL)
    {
        kal_adm_free(g_idle_swatch_p->adm_pool_id, (void*)g_idle_swatch_p->status_icon_bar_layer_buf_ptr);
        g_idle_swatch_p->status_icon_bar_layer_buf_ptr = NULL;
    }

    /* Free temp layer */ 
    if (g_idle_swatch_p->temp_layer_buf_ptr != NULL)
    {
        kal_adm_free(g_idle_swatch_p->adm_pool_id, (void*)g_idle_swatch_p->temp_layer_buf_ptr);
        g_idle_swatch_p->temp_layer_buf_ptr = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_alloc_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_alloc_pool()
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RANFOW_TRACE("[SWATCH]total memory need:%d\n", MMI_IDLE_SWATCH_MEM_SIZE);
    
    /* allocate memory from App-Based ASM */
    if (g_idle_swatch_p->app_mem_pool == NULL)
    {
        g_idle_swatch_p->app_mem_pool = mmi_frm_asm_alloc_r(
            g_idle_swatch_p->group_id, MMI_IDLE_SWATCH_MEM_SIZE);
        
        ASSERT(g_idle_swatch_p->app_mem_pool != NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_free_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_free_pool()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* allocate memory from App-Based ASM */
    if (g_idle_swatch_p->app_mem_pool != NULL)
    {
        mmi_frm_asm_free_r(g_idle_swatch_p->group_id, g_idle_swatch_p->app_mem_pool);
        g_idle_swatch_p->app_mem_pool = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 swatch_num = sizeof(g_swatch_config_table) / sizeof(mmi_idle_swatch_config_table);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_base_handle(&g_idle_swatch_p->base_layer_handle);
    
    /* Allocate pool & create ADM */
    mmi_idle_swatch_alloc_pool();
    mmi_idle_swatch_create_adm();
    mmi_idle_swatch_alloc_adm_layer();

    mmi_idle_swatch_register_event_handler();

    //read swatch index record
    ReadValue(NVRAM_IDLE_SWATCH_INDEX, &(g_idle_swatch_p->swatch_index), DS_BYTE, &error);
    if (g_idle_swatch_p->swatch_index > swatch_num)
    {
        g_idle_swatch_p->swatch_index = swatch_num - 1;
    }

    g_idle_swatch_p->is_active = MMI_TRUE;
    g_idle_swatch_p->update_type = MMI_IDLE_SWATCH_UPDATE_ALL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_blt_previous
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_blt_previous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_blt(g_idle_swatch_p->base_layer_handle,
        g_idle_swatch_p->update_layer_handle,
        g_idle_swatch_p->status_icon_bar_layer_handle,
        NULL,
        0, 0, MMI_IDLE_SWATCH_WIDTH, MMI_IDLE_SWATCH_HEIGHT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_print_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_print_text(S32 x, S32 y, U8 font_size, color font_color, UI_string_type text, MMI_BOOL count_is_left_of_hint)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute font = {0};
    S32 str_width, str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    font.type = 1;
    font.bold = 1;
    font.italic = 0;
    font.underline = 0;
    font.type = 1;
    font.oblique = 0;
    font.size = 
    font.size = (font_size | 0x80);
    gui_set_font(&font);    

    if (count_is_left_of_hint)
    {
        gui_measure_string(text, &str_width, &str_height);
        gui_move_text_cursor(x - str_width, y);
    }
    else
    {
        gui_move_text_cursor(x, y);
    }
    
    gui_set_text_color(font_color);
    gui_print_text(text);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_draw_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_draw_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_draw_bg start\n");
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("DB", SA_start);
#endif

    gdi_layer_push_and_set_active(g_idle_swatch_p->base_layer_handle);
    gdi_layer_clear_background(GDI_COLOR_BLACK);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);

    //Clock bg
    if (g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.type == MMI_IDLE_SWATCH_CLOCK_TYPE_ANALOG)
    {
        mmi_idle_swatch_analog_clock *analog_clock = (mmi_idle_swatch_analog_clock*)&(g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.data);
        if (analog_clock->bg_img_id)
        {
            gdi_image_draw_id(analog_clock->bg_x, analog_clock->bg_y, analog_clock->bg_img_id);
        }
    }
    else
    {
        mmi_idle_swatch_digital_clock *digital_clock = (mmi_idle_swatch_digital_clock*)&(g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.data);
        if (digital_clock->bg_img_id)
        {
            gdi_image_draw_id(digital_clock->bg_x, digital_clock->bg_y, digital_clock->bg_img_id);
        }
    }

    //AP bg
    for (i = 0; i < (U8)MMI_IDLE_SWATCH_AP_NUM; i++)
    {
        if (g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[i].hint_type == MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE)
        {
            mmi_idle_swatch_ap_image_info *hint_image = (mmi_idle_swatch_ap_image_info*)&(g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[i].hint_data);
            if (hint_image->image_id)
            {
                gdi_image_draw_id(hint_image->x, hint_image->y, hint_image->image_id);
            }
        }
        else
        {
            mmi_idle_swatch_ap_text_info *hint_text = (mmi_idle_swatch_ap_text_info*)&(g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[i].hint_data);
            mmi_idle_swatch_print_text(hint_text->x, hint_text->y, hint_text->font_size, hint_text->font_color, (UI_string_type)GetString(hint_text->text_id), MMI_FALSE);
        }
    }
    
    gdi_layer_pop_and_restore_active();
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("DB", SA_stop);
#endif
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_draw_bg end\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_get_analog_clock_minute_tick
 * DESCRIPTION
 *  update when minute tick
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_get_analog_clock_minute_tick(U8 *hour_hand_counter, U8 *minute_hand_counter, U8 *second_hand_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME t;
    U8 h, m, s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GetDateTime(&t);
    DTGetRTCTime(&t);
    m = t.nMin;
    s = t.nSec;
    *minute_hand_counter = m;
    *second_hand_counter = s;
    h = t.nHour;
    h++;
    if (h > 12)
    {
        h -= 12;
    }
    *hour_hand_counter = (h - 1) * 5;
    *hour_hand_counter += m / 12;
    if (*minute_hand_counter >= 60)
    {
        *minute_hand_counter = 0;
    }
    if (*second_hand_counter >= 60)
    {
        *second_hand_counter = 0;
    }
    if ((*minute_hand_counter % 12) == 0)
    {
        if (*hour_hand_counter >= 60)
        {
            *hour_hand_counter = 0;
        }
    }
}


static const FLOAT g_idle_swatch_clock_sin_table[] = 
{
    (FLOAT) - 0.99999820, (FLOAT) - 0.99431727, (FLOAT) - 0.97773360, (FLOAT) - 0.95042917,
        (FLOAT) - 0.91270313,
        (FLOAT)-0.86496924, (FLOAT)-0.80775119, (FLOAT)-0.74167587,
    (FLOAT) - 0.66746803, (FLOAT) - 0.58594175, (FLOAT) - 0.49799022, (FLOAT) - 0.40457821,
        (FLOAT) - 0.30673042,
        (FLOAT)-0.20551889, (FLOAT)-0.10205382, (FLOAT)0.00000000,
    (FLOAT) 0.10457040, (FLOAT) 0.20799418, (FLOAT) 0.30913729, (FLOAT) 0.40689072, (FLOAT) 0.50018258,
        (FLOAT) 0.58798990,
        (FLOAT)0.66934994, (FLOAT)0.74337050,
    (FLOAT) 0.80923998, (FLOAT) 0.86623616, (FLOAT) 0.91373403, (FLOAT) 0.95121274, (FLOAT) 0.97826142,
        (FLOAT) 0.99458343,
        (FLOAT)0.99999980, (FLOAT)0.99445115,
    (FLOAT) 0.97799831, (FLOAT) 0.95082172, (FLOAT) 0.91321931, (FLOAT) 0.86560342, (FLOAT) 0.80849624,
        (FLOAT) 0.74252372,
        (FLOAT)0.66840956, (FLOAT)0.58696629,
    (FLOAT) 0.49908672, (FLOAT) 0.40573486, (FLOAT) 0.30793410, (FLOAT) 0.20675662, (FLOAT) 0.10331227,
    
        (FLOAT) - 0.00126490,
        (FLOAT)-0.10582843, (FLOAT)-0.20923132,
    (FLOAT) - 0.31033998, (FLOAT) - 0.40804598, (FLOAT) - 0.50127753, (FLOAT) - 0.58901256,
        (FLOAT) - 0.67028925,
        (FLOAT)-0.74421601, (FLOAT)-0.80998244, (FLOAT)-0.86686752,
    (FLOAT)-0.91424734, (FLOAT)-0.95160225, (FLOAT)-0.97852297, (FLOAT)-0.99471414,
};


static const FLOAT g_idle_swatch_clock_cos_table[] = 
{
    (FLOAT) 0.00189735, (FLOAT) 0.10645731, (FLOAT) 0.20984996, (FLOAT) 0.31094114, (FLOAT) 0.40862330,
        (FLOAT) 0.50182489,
        (FLOAT)0.58952354, (FLOAT)0.67075845,
    (FLOAT) 0.74463846, (FLOAT) 0.81035318, (FLOAT) 0.86718264, (FLOAT) 0.91450340, (FLOAT) 0.95179643,
        (FLOAT) 0.97865315,
        (FLOAT)0.99477888, (FLOAT)1.00000000,
    (FLOAT) 0.99451749, (FLOAT) 0.97813006, (FLOAT) 0.95101742, (FLOAT) 0.91347684, (FLOAT) 0.86591997,
        (FLOAT) 0.80886827,
        (FLOAT)0.74294728, (FLOAT)0.66887989,
    (FLOAT) 0.58747821, (FLOAT) 0.49963478, (FLOAT) 0.40631283, (FLOAT) 0.30853576, (FLOAT) 0.20737548,
        (FLOAT) 0.10394131,
        (FLOAT)-0.00063245, (FLOAT)-0.10519940,
    (FLOAT) - 0.20861283, (FLOAT) - 0.30973870, (FLOAT) - 0.40746839, (FLOAT) - 0.50073018,
        (FLOAT) - 0.58850135,
        (FLOAT)-0.66981977, (FLOAT)-0.74379342, (FLOAT)-0.80961137,
    (FLOAT) - 0.86655204, (FLOAT) - 0.91399082, (FLOAT) - 0.95140769, (FLOAT) - 0.97839241,
        (FLOAT) - 0.99464897,
        (FLOAT)-0.99999920, (FLOAT)-0.99438440, (FLOAT)-0.97786617,
    (FLOAT) - 0.95062563, (FLOAT) - 0.91296138, (FLOAT) - 0.86528656, (FLOAT) - 0.80812388,
        (FLOAT) - 0.74209994,
        (FLOAT)-0.66793902, (FLOAT)-0.58645414, (FLOAT)-0.49853857,
    (FLOAT)-0.40515651, (FLOAT)-0.30733233, (FLOAT)-0.20613779, (FLOAT)-0.10268295,
};


#ifdef G2D_SUPPORT

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_set_identity
 * DESCRIPTION
 *  
 * PARAMETERS
 *  matrix
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_set_identity(mmi_idle_swatch_matrix_struct *matrix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    matrix->m[0] = 1;
    matrix->m[1] = 0;
    matrix->m[2] = 0;
    matrix->m[3] = 0;
    matrix->m[4] = 1;
    matrix->m[5] = 0;
    matrix->m[6] = 0;
    matrix->m[7] = 0;
    matrix->m[8] = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_set_traslation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  matrix
 *  tx
 *  ty
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_set_traslation(mmi_idle_swatch_matrix_struct *matrix, float tx, float ty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_swatch_set_identity(matrix);
    matrix->m[2] = tx;
    matrix->m[5] = ty;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_rotate_z
 * DESCRIPTION
 *             | cos(a)  -sin(a)  0  |
 * Rz(a) = | sin(a)  cos(a)    0  |
 *             | 0          0          1 |
 *
 *  VfxMatrix3x3Ex::setRotateByZ
 * PARAMETERS
 *  matrix
 *  angle
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_rotate_z(mmi_idle_swatch_matrix_struct *matrix, U8 angle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_swatch_set_identity(matrix);
    matrix->m[0] = matrix->m[4] = g_idle_swatch_clock_cos_table[angle];
    matrix->m[3] = g_idle_swatch_clock_sin_table[angle];
    matrix->m[1] = -matrix->m[3];
    //matrix->m[1] = g_idle_swatch_clock_sin_table[angle];
    //matrix->m[3] = -matrix->m[1];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_matrix_multiply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_matrix_multiply(mmi_idle_swatch_matrix_struct *matrix_a, mmi_idle_swatch_matrix_struct *matrix_b, mmi_idle_swatch_matrix_struct *matrix_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Column major matrix multiplication */
    matrix_out->m[0] = matrix_a->m[0] * matrix_b->m[0] + matrix_a->m[3] * matrix_b->m[1] + matrix_a->m[6] * matrix_b->m[2];
    matrix_out->m[3] = matrix_a->m[0] * matrix_b->m[3] + matrix_a->m[3] * matrix_b->m[4] + matrix_a->m[6] * matrix_b->m[5];
    matrix_out->m[6] = matrix_a->m[0] * matrix_b->m[6] + matrix_a->m[3] * matrix_b->m[7] + matrix_a->m[6] * matrix_b->m[8];

    matrix_out->m[1] = matrix_a->m[1] * matrix_b->m[0] + matrix_a->m[4] * matrix_b->m[1] + matrix_a->m[7] * matrix_b->m[2];
    matrix_out->m[4] = matrix_a->m[1] * matrix_b->m[3] + matrix_a->m[4] * matrix_b->m[4] + matrix_a->m[7] * matrix_b->m[5];
    matrix_out->m[7] = matrix_a->m[1] * matrix_b->m[6] + matrix_a->m[4] * matrix_b->m[7] + matrix_a->m[7] * matrix_b->m[8];

    matrix_out->m[2] = matrix_a->m[2] * matrix_b->m[0] + matrix_a->m[5] * matrix_b->m[1] + matrix_a->m[8] * matrix_b->m[2];
    matrix_out->m[5] = matrix_a->m[2] * matrix_b->m[3] + matrix_a->m[5] * matrix_b->m[4] + matrix_a->m[8] * matrix_b->m[5];
    matrix_out->m[8] = matrix_a->m[2] * matrix_b->m[6] + matrix_a->m[5] * matrix_b->m[7] + matrix_a->m[8] * matrix_b->m[8];

}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_image_rotate_with_g2d
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_image_rotate_with_g2d(U16 center_x, U16 center_y, U16 image_id, S32 image_width, S32 image_height, U8 angle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, image_layer_buff_size;
    PU8 image_layer_buff_ptr;
    gdi_handle image_layer_handle;
    mmi_idle_swatch_matrix_struct matrix_translation, matrix_rotate_z, matrix_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_layer_buff_size = (image_width*image_height*GDI_MAINLCD_BIT_PER_PIXEL*2) >> 3;
    //if it assert, you have to check the configure of MMI_IDLE_SWATCH_TEMP_LAYER_BUFFER_SIZE in IdleMemCfg.h
    MMI_ASSERT(image_layer_buff_size <= MMI_IDLE_SWATCH_TEMP_LAYER_BUFFER_SIZE);
    image_layer_buff_ptr = g_idle_swatch_p->temp_layer_buf_ptr;
    MMI_ASSERT(image_layer_buff_ptr != NULL);
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_32_PARGB,
        0,
        0,
        image_width,
        image_height,
        &image_layer_handle,
        (PU8)image_layer_buff_ptr,
        image_layer_buff_size);
    MMI_ASSERT(image_layer_handle != NULL);
    gdi_layer_push_and_set_active(image_layer_handle);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_image_draw_id(0, 0, image_id);
    gdi_layer_pop_and_restore_active();    

    mmi_idle_swatch_set_traslation(&matrix_translation, -image_width * 0.5, -image_height * 0.5);
    mmi_idle_swatch_rotate_z(&matrix_rotate_z, (angle+15)%60); 
    mmi_idle_swatch_matrix_multiply(&matrix_translation, &matrix_rotate_z, &matrix_result);
    matrix_result.m[2] += center_x;
    matrix_result.m[5] += center_y;
    
    gdi_2d_linear_transfrom(
        matrix_result.m,
        image_layer_handle,
        0,
        0,
        image_width,
        image_height,
        0,
        0,
        MMI_IDLE_SWATCH_WIDTH,
        MMI_IDLE_SWATCH_HEIGHT,
        GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
        GDI_COLOR_TRANSPARENT,
        GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,
        0);

    gdi_layer_free(image_layer_handle);
}

#endif  //G2D_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_image_rotate
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_image_rotate(U16 center_x, U16 center_y, U16 image_id, S32 image_width, S32 image_height, U8 angle, U16 clock_x, U16 clock_y, S32 clock_width, S32 clock_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef G2D_SUPPORT
    mmi_idle_swatch_image_rotate_with_g2d(center_x, center_y, image_id, image_width, image_height, angle);
#else  //G2D_SUPPORT
    S32 i, j, image_layer_buff_size, clock_layer_buff_size;
    PU8 image_layer_buff_ptr, clock_layer_buff_ptr;
    gdi_handle image_layer_handle, clock_layer_handle;
    S32 radius;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_push_and_set_alpha_blending_source_layer(g_idle_swatch_p->update_layer_handle);
    
    image_layer_buff_size = (image_width*image_height*GDI_MAINLCD_BIT_PER_PIXEL*2) >> 3;
    //if it assert, you have to check the configure of MMI_IDLE_SWATCH_TEMP_LAYER_BUFFER_SIZE in IdleMemCfg.h
    MMI_ASSERT(image_layer_buff_size <= MMI_IDLE_SWATCH_TEMP_LAYER_BUFFER_SIZE);
    image_layer_buff_ptr = g_idle_swatch_p->temp_layer_buf_ptr;
    MMI_ASSERT(image_layer_buff_ptr != NULL);
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_32_PARGB,
        0,
        0,
        image_width,
        image_height,
        &image_layer_handle,
        (PU8)image_layer_buff_ptr,
        image_layer_buff_size);
    MMI_ASSERT(image_layer_handle != NULL);
    gdi_layer_push_and_set_active(image_layer_handle);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_image_draw_id(0, 0, image_id);
    gdi_layer_pop_and_restore_active();

    clock_layer_buff_size = (clock_width*clock_height*GDI_MAINLCD_BIT_PER_PIXEL*2) >> 3;
    //if it assert, you have to check the configure of MMI_IDLE_SWATCH_TEMP_LAYER_BUFFER_SIZE in IdleMemCfg.h
    MMI_ASSERT((image_layer_buff_size+clock_layer_buff_size) <= MMI_IDLE_SWATCH_TEMP_LAYER_BUFFER_SIZE);
    clock_layer_buff_ptr = g_idle_swatch_p->temp_layer_buf_ptr + image_layer_buff_size;
    MMI_ASSERT(clock_layer_buff_ptr != NULL);
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_32_PARGB,
        0,
        0,
        clock_width,
        clock_height,
        &clock_layer_handle,
        clock_layer_buff_ptr,
        clock_layer_buff_size);
    MMI_ASSERT(clock_layer_handle != NULL);
    gdi_layer_push_and_set_active(clock_layer_handle);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    
    radius = image_height / 2;
    center_x -= clock_x;
    center_y -= clock_y;
    angle = (angle+15)%60;
    for(i = 0; i < image_height; i++)
    {
        for(j = 0; j < image_width; j++)
        {
            float x0, y0;
            S32 x1, y1, x_offset_from_center, y_offset_from_center;

            x_offset_from_center = j - image_width / 2;
            y_offset_from_center = i - radius;
            
            x0 = x_offset_from_center * g_idle_swatch_clock_cos_table[angle] - y_offset_from_center * g_idle_swatch_clock_sin_table[angle];
            y0 = x_offset_from_center * g_idle_swatch_clock_sin_table[angle] + y_offset_from_center * g_idle_swatch_clock_cos_table[angle];
            
            x1 = (S32)x0;
            y1 = (S32)y0;
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            //memcpy((g_idle_swatch_p->update_layer_buf_ptr + (center_y + y1) * MMI_IDLE_SWATCH_WIDTH * 4 + (center_x + x1) * 4), (image_layer_buff_ptr + i * image_width * 4 + j * 4), 4);
            memcpy((clock_layer_buff_ptr + (center_y + y1) * clock_width * 4 + (center_x + x1) * 4), (image_layer_buff_ptr + i * image_width * 4 + j * 4), 4);
       }
    }

    gdi_layer_push_and_set_active(clock_layer_handle);
    gdi_layer_set_position(clock_x, clock_y);
    gdi_layer_pop_and_restore_active();
    gdi_layer_set_background(0);
    gdi_layer_flatten_with_clipping((gdi_handle)gdi_act_layer, clock_layer_handle, NULL, NULL);

    gdi_layer_free(image_layer_handle);
    gdi_layer_free(clock_layer_handle);
    
    gdi_pop_and_restore_alpha_blending_source_layer();
#endif  //G2D_SUPPORT
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_get_number_bit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  number [IN] U32
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_idle_swatch_get_number_bit(U32 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number < 10)
    {
        return 1;
    }
    
    for (i = MMI_IDLE_SWATCH_AP_COUNT_MAX_BIT; i > 0; i--)
    {
        U32 divisor = 1;
        for (j = 0; j < i; j++)
        {
            divisor *= 10;
        }
        if ((number / divisor) > 0)
        {
            return (i+1);
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_draw_number_image
 * DESCRIPTION
 *  Draw Number Image
 * PARAMETERS
 *  number [IN] U32
 *  num_0_img_id [IN] MMI_ID
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_draw_number_image(U16 x, U16 y, U32 number, MMI_ID num_0_img_id, U8 bit, S16 gap, MMI_BOOL count_is_left_of_hint)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, num_width, num_height;
    U16 current_x, current_y;
    U8 draw_bit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(number < MMI_IDLE_SWATCH_AP_COUNT_MAX_NUM);

    gdi_image_get_dimension_id(num_0_img_id, &num_width, &num_height);

    MMI_ASSERT(num_width > 0 && num_height > 0);

    if (bit == 0)
    {
        draw_bit = mmi_idle_swatch_get_number_bit(number);
    }
    else
    {
        draw_bit = bit;
    }
    
    MMI_ASSERT(draw_bit > 0 && draw_bit <= MMI_IDLE_SWATCH_AP_COUNT_MAX_NUM);
    
    //Draw Number
    if (count_is_left_of_hint)
    {
        current_x = x - num_width * draw_bit;
    }
    else
    {
        current_x = x;
    }
    current_y = y;
    
    for (i = 0; i < draw_bit - 1; i++)
    {
        U16 divisor = 1, num_to_draw = 0;
        for (j = 0; j < draw_bit-i-1; j++)
        {
            divisor *= 10;
        }
        num_to_draw = number / divisor;
        number -= num_to_draw * divisor;
        
        gdi_image_draw_id(current_x, current_y, num_0_img_id + num_to_draw);
        current_x += num_width + gap;
    }
    
    gdi_image_draw_id(current_x, current_y, num_0_img_id + number);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_update_clock_by_minute
 * DESCRIPTION
 *  it will be called in DateTimerProc, use for update digital clock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_update_clock_by_minute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.type == MMI_IDLE_SWATCH_CLOCK_TYPE_DIGITAL &&
        g_idle_swatch_p->is_active)
    {
        mmi_idle_swatch_update_clock();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_update_clock_by_second
 * DESCRIPTION
 *  it will be called in DateTimerProc, use for update analog clock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_update_clock_by_second(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
 *  mmi_idle_swatch_update_clock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_update_clock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_update_clock start,is_active:%d,is_lcd_sleep:%d\n", g_idle_swatch_p->is_active, srv_backlight_is_lcd_sleep());
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("UC", SA_start);
#endif

    if (!g_idle_swatch_p->is_active)
    {
        return;
    }
    
    gdi_layer_push_and_set_active(g_idle_swatch_p->update_layer_handle);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_push_and_set_clip(g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.area.x1,
        g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.area.y1,
        g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.area.x2,
        g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.area.y2);

    gdi_draw_solid_rect(g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.area.x1,
        g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.area.y1,
        g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.area.x2,
        g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.area.y2,
        GDI_COLOR_TRANSPARENT);

    if (g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.type == MMI_IDLE_SWATCH_CLOCK_TYPE_ANALOG)
    {
        U8 hour_hand_counter, minute_hand_counter, second_hand_counter;
        S32 image_width, image_height, clock_width, clock_height;
        
        mmi_idle_swatch_analog_clock *analog_clock = (mmi_idle_swatch_analog_clock*)&(g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.data);
        
        mmi_idle_swatch_get_analog_clock_minute_tick(&hour_hand_counter, &minute_hand_counter, &second_hand_counter);
        RANFOW_TRACE("[SWATCH]hour_hand_counter=%d,minute_hand_counter=%d,second_hand_counter=%d\n", hour_hand_counter, minute_hand_counter, second_hand_counter);

        gdi_image_get_dimension_id(analog_clock->bg_img_id, &clock_width, &clock_height);
        
        //Draw hour hand
        gdi_image_get_dimension_id(analog_clock->hour_hand_img_id, &image_width, &image_height);
        mmi_idle_swatch_image_rotate(
            analog_clock->center_x,
            analog_clock->center_y,
            analog_clock->hour_hand_img_id,
            image_width,
            image_height,
            hour_hand_counter,
            analog_clock->bg_x,
            analog_clock->bg_y,
            clock_width,
            clock_height);
        
        //Draw minute hand
        gdi_image_get_dimension_id(analog_clock->minute_hand_img_id, &image_width, &image_height);
        mmi_idle_swatch_image_rotate(
            analog_clock->center_x,
            analog_clock->center_y,
            analog_clock->minute_hand_img_id,
            image_width,
            image_height,
            minute_hand_counter,
            analog_clock->bg_x,
            analog_clock->bg_y,
            clock_width,
            clock_height);
        
        //Draw second hand
        gdi_image_get_dimension_id(analog_clock->second_hand_img_id, &image_width, &image_height);
        mmi_idle_swatch_image_rotate(
            analog_clock->center_x,
            analog_clock->center_y,
            analog_clock->second_hand_img_id,
            image_width,
            image_height,
            second_hand_counter,
            analog_clock->bg_x,
            analog_clock->bg_y,
            clock_width,
            clock_height);
    }
    else
    {
        MYTIME t;
        U8 bit = 0;
        S16 offset = 0;  //for special clock to adjust x when hour is largger than 10
        S16 hour_offset = 0;  //for special clock to adjust hour offset when hour is largger than 10
        mmi_idle_swatch_digital_clock *digital_clock = (mmi_idle_swatch_digital_clock*)&(g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.data);
        
        //GetDateTime(&t);
        DTGetRTCTime(&t);

        if (digital_clock->add_zero)
        {
            bit = 2;
        }

        //special case of Digital Clock 1
        if (g_idle_swatch_p->swatch_index == 1 &&
            t.nHour > 9)
        {
            offset = -6;
        }

        //special case of Digital Clock 2
        if (g_idle_swatch_p->swatch_index == 2 &&
            t.nHour > 9)
        {
            hour_offset = -8;
        }
        
        //Draw am/pm
        if (t.nHour >= 12)
        {
            t.nHour -= 12;
            gdi_image_draw_id(digital_clock->ampm_x+offset, digital_clock->ampm_y, digital_clock->pm_img_id);
        }
        else
        {
            gdi_image_draw_id(digital_clock->ampm_x+offset, digital_clock->ampm_y, digital_clock->am_img_id);
        }
        //Draw hour
        mmi_idle_swatch_draw_number_image(digital_clock->hour_x+offset, digital_clock->hour_y, t.nHour, digital_clock->hour_num_0_img_id, bit, digital_clock->hour_num_gap+hour_offset, MMI_FALSE);
        //Draw minute
        mmi_idle_swatch_draw_number_image(digital_clock->minute_x+offset, digital_clock->minute_y, t.nMin, digital_clock->minute_num_0_img_id, bit, digital_clock->minute_num_gap, MMI_FALSE);
    }
    
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
    mmi_idle_swatch_blt_previous();
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("UC", SA_stop);
#endif
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_update_clock end\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_update_ap_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_update_ap_ext(U8 index, U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_update_ap_ext start,is_active:%d,is_lcd_sleep:%d\n", g_idle_swatch_p->is_active, srv_backlight_is_lcd_sleep());    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("UAPE", SA_stop);
#endif
    
    if (!g_idle_swatch_p->is_active)
        return;

    //update count
    g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].update_func(
        g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].app,
        &(g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].count));
    
    gdi_layer_push_and_set_active(g_idle_swatch_p->update_layer_handle);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);

    gdi_layer_push_and_set_clip(g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].area.x1,
        g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].area.y1,
        g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].area.x2,
        g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].area.y2);
    

    gdi_draw_solid_rect(g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].area.x1,
        g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].area.y1,
        g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].area.x2,
        g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].area.y2,
        GDI_COLOR_TRANSPARENT);

    if (g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].count_type == MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE)
    {
        mmi_idle_swatch_ap_image_info *count_image = (mmi_idle_swatch_ap_image_info*)&(g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].count_data);
        U8 bit = 0;

        if (g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].add_zero)
        {
            bit = MMI_IDLE_SWATCH_AP_COUNT_MAX_BIT;
        }
        mmi_idle_swatch_draw_number_image(count_image->x, count_image->y,
            g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].count,
            count_image->image_id, bit, count_image->image_gap,
            g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].count_is_left_of_hint);
    }
    else
    {
        mmi_idle_swatch_ap_text_info *count_text = (mmi_idle_swatch_ap_text_info*)&(g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].count_data);
        U16 ap_str[MMI_IDLE_SWATCH_AP_NAME_MAX_LEN] = {0};
        memset(ap_str, 0, MMI_IDLE_SWATCH_AP_NAME_MAX_LEN);
        kal_wsprintf(ap_str, "%d", g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].count);
        
        mmi_idle_swatch_print_text(count_text->x, count_text->y, count_text->font_size, count_text->font_color,
            (UI_string_type)ap_str,
            g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[index].count_is_left_of_hint);
    }
    
    gdi_layer_pop_clip();

    gdi_layer_pop_and_restore_active();
    mmi_idle_swatch_blt_previous();
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("UAPE", SA_stop);
#endif
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_update_ap_ext end\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_update_ap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_update_ap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_update_ap start\n");
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("UAP", SA_stop);
#endif

    for (i = 0; i < (U8)MMI_IDLE_SWATCH_AP_NUM; i++)
    {
        mmi_idle_swatch_update_ap_ext(i, g_swatch_config_table[g_idle_swatch_p->swatch_index].ap[i].count);
    }
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("UAP", SA_stop);
#endif
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_update_ap end\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_swatch_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_swatch_p->update_type == MMI_IDLE_SWATCH_UPDATE_ALL)
    {
        mmi_idle_swatch_update_clock();
        mmi_idle_swatch_update_ap();
    }
    else if (g_idle_swatch_p->update_type == MMI_IDLE_SWATCH_UPDATE_AP)
    {
        mmi_idle_swatch_update_ap();
    }
    else if (g_idle_swatch_p->update_type == MMI_IDLE_SWATCH_UPDATE_CLOCK)
    {
        mmi_idle_swatch_update_clock();
    }

    if (g_swatch_config_table[g_idle_swatch_p->swatch_index].clock.type == MMI_IDLE_SWATCH_CLOCK_TYPE_DIGITAL)
    {
        g_idle_swatch_p->update_type = MMI_IDLE_SWATCH_UPDATE_AP;
    }

    StartTimer(IDLE_SWATCH_UPDATE_TIMER, MMI_IDLE_SWATCH_ANALOG_UPDATE_DELAY, mmi_idle_swatch_update);
}
  
    
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_idle_swatch_event_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(evt);
    RANFOW_TRACE("[SWATCH]mmi_idle_swatch_event_handler,evt_id=%d\n", evt->evt_id);

    switch (evt->evt_id)
    {
        case EVT_ID_GPIO_LCD_SLEEP_OUT:
        {
            if (mmi_frm_group_get_active_id() == g_idle_swatch_p->group_id)
            {
                mmi_idle_swatch_update();
            }
            break;
        }
        case EVT_ID_GPIO_LCD_SLEEP_IN:
        {
            break;
        }
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  group_id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_enter(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MOD_MMI_COMMON_APP, TRC_IDLE_SWATCH_ENTER, 100);
    MMI_ASSERT(group_id != GRP_ID_INVALID);

    g_idle_swatch_p->group_id = group_id;
    mmi_idle_swatch_init();
    
    entry_full_screen();
    gdi_layer_multi_layer_enable();
    //gdi_layer_set_blt_layer(g_idle_swatch_p->base_layer_handle, g_idle_swatch_p->update_layer_handle, 0, 0);

    mmi_idle_swatch_draw_bg();    
    mmi_idle_swatch_update();

    wgui_status_icon_bar_close_clock();
    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_swatch_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_swatch_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MOD_MMI_COMMON_APP, TRC_IDLE_SWATCH_EXIT, 100);
    StopTimer(IDLE_SWATCH_UPDATE_TIMER);

    mmi_idle_swatch_blt_previous();
    gdi_layer_flatten_previous_to_base();
    
    gdi_layer_multi_layer_disable();
    leave_full_screen();
    
    /* release ADM */
    mmi_idle_swatch_free_adm_layer();
    /* Free pool & delete ADM */
    mmi_idle_swatch_free_pool();
    mmi_idle_swatch_delete_adm();
    
    g_idle_swatch_p->base_layer_handle = NULL;
    g_idle_swatch_p->update_layer_handle = NULL;
    g_idle_swatch_p->status_icon_bar_layer_handle = NULL;
    g_idle_swatch_p->status_icon_bar_layer_buf_ptr = NULL;
    g_idle_swatch_p->is_active = MMI_FALSE;
}


#ifdef __CUI_SWATCH_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  cui_swatch_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_swatch_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MOD_MMI_COMMON_APP, TRC_IDLE_SWATCH_PROC, event->evt_id);
    switch (event->evt_id)
    {
        case EVT_ID_SCRN_INACTIVE:
            mmi_idle_swatch_exit();
            break;
        case EVT_ID_SCRN_ACTIVE:
            mmi_idle_swatch_enter(g_idle_swatch_p->group_id);
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_swatch_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  group_id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_swatch_create(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (g_idle_swatch_p->is_active)
    //    return;
    
    MMI_ASSERT(group_id != GRP_ID_INVALID);
    g_idle_swatch_p->group_id = group_id;
    g_idle_swatch_p->group_id = mmi_frm_group_create(group_id, GRP_ID_CUI_SWATCH, cui_swatch_proc, NULL);  
    MMI_ASSERT(g_idle_swatch_p->group_id != GRP_ID_INVALID);
}


/*****************************************************************************
 * FUNCTION
 *  cui_swatch_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_swatch_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_enter(g_idle_swatch_p->group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_create(g_idle_swatch_p->group_id, SCR_ID_CUI_SWATCH, (FuncPtr)cui_swatch_proc, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_swatch_create_and_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  group_id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_swatch_create_and_run(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_swatch_create(group_id);
    cui_swatch_run();
}


/*****************************************************************************
 * FUNCTION
 *  cui_swatch_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_swatch_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(g_idle_swatch_p->group_id);
}

#endif  //__CUI_SWATCH_SUPPORT__

#endif /* __MMI_WEARABLE_DEVICE__ */ 

