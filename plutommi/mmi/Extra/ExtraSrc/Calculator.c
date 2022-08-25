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
 * Calculator.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Calculator application.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
  * Dec 11 2005 mtk01215
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**********************************************************************************
   Filename:      Calculator.c
   Author:        manju
   Date Created:  June-21-2003
   Contains:      Calculator
**********************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_CALCULATOR__
#include "Calculator.h"
#include "ProfilesSrvGprot.h"
#include "MMIDataType.h"
#include "wgui.h"
#include "gui_data_types.h"
#include "mmi_rp_app_calculator_def.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "mmi_frm_input_gprot.h"
#include "Unicodexdcl.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_non_specific_general_types.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "gui_effect_oem.h"
#include "gdi_include.h"
#include "gui.h"
#include "wgui_include.h"
#include "wgui_title.h"
#include "gui_typedef.h"
#include "mmi_frm_mem_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "app_buff_alloc.h"
#include "kal_public_api.h"
#include "gui_switch.h"
#include "CustDataRes.h"
#include "gui_config.h"
#include "gui_themes.h"
#include "PixcomFontEngine.h"
#include "lcd_sw_inc.h"
#include "CustThemesRes.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "idlegprot.h"
#include "menucuigprot.h"
#include "idlegprot.h"
#include "gui_image.h"
#include "gdi_include.h"
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif /* __MMI_TOUCH_FEEDBACK_SUPPORT__ */
#include "mmi_frm_input_gprot.h"
/* MTK Elvis for R2L characters */
//extern BOOL r2lMMIFlag;

#include "MMI_ap_dcm_config.h"
#define CALC_MAX_DIGITS (12)
#define CALC_MAX_BUFF_LEN        30
#define CALC_MAX_RESULT (999999999999.5)
#define CALC_MIN_RESULT (-999999999999.5)

#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_TOUCH_SCREEN__
#ifndef __CALC_FTE_SLIM_USE_SLICE_RES__
//#define __CALC_FTE_SLIM_USE_SLICE_RES__
#endif
#endif/*__MMI_TOUCH_SCREEN__*/
#endif/*__MMI_FTE_SUPPORT__*/
typedef struct
{
    DOUBLE Operand1;
    DOUBLE Operand2;
    DOUBLE MemValue;
    U16 Operator;
    WCHAR InputBuff[CALC_MAX_DIGITS + 2];
    gdi_image_cache_bmp_struct Cache;
    calc_button_struct *CurrHilite;
    MMI_BOOL ValidInput;
    MMI_BOOL MemAvail;
    U8 State;
 #ifndef __GDI_MEMORY_PROFILE_2__
    U8 *buf_calc_touch_top_layer;
 #endif
} calc_context_struct;

extern const U8 gCalcImgCoor[][2];

/* 
 * Local Function
 */

GDI_HANDLE calculator_touch_top_layer;
GDI_HANDLE cal_wall_paper_layer;

/* 
 * Global Variable
 */
calc_context_struct calc_cntx;
calc_context_struct *g_calc_cntx = &calc_cntx;
#ifdef __MMI_AP_DCM_CALC__
#pragma arm section rodata = "DYNAMIC_CODE_CALCULATOR_ROCODE",code = "DYNAMIC_CODE_CALCULATOR_RODATA"
#endif

//#ifdef __CALC_96_64_SOLUTION_SLIM__
#ifdef __MMI_MAINLCD_96X64__ 
S8 g_left_init = 3+1;
S8 g_right_init = 0-1;

S8 g_highlight_site_counter = 0;

kal_bool g_is_new_operand = KAL_TRUE;
#endif
MMI_BOOL g_current_r2l_flag = MMI_FALSE;
/* 
 * Global Function
 */
static void calc_move_text_cursor(BOOL r21flag, S32 x, S32 y, S32 offset);

/*
 * change double to UCS2String
 * point : point to the "."
 * intLen : length of integer part
 */
static void calc_ftoa(DOUBLE result,WCHAR* String)
{
    CHAR *point;
    S32 intLen;
    int i;
	U32 sign = MMI_FALSE;
	CHAR resultStr[2 * CALC_MAX_DIGITS + 2];  /* sign + 12 + . + 11 + \0 */
    
	sprintf(resultStr, "%.11f",result);
	point = strstr(resultStr,".");
	intLen = strcspn(resultStr,".");

    if(result >= CALC_MAX_RESULT || result <= CALC_MIN_RESULT)
	{
		return;
	}
	if(resultStr[0] == '-')    /* negative number */
	{
		sign = MMI_TRUE;
		intLen--;
	}
	if(intLen == CALC_MAX_DIGITS)
	{
		if(point[1] < '5')
		{
			point[0] = '\0';
		}
		if(point[1] >= '5')
		{
			point[0] = '\0';
			i = -1;
			while(point[i] == '9')
			{
				point[i] = '0';
				i--;
			}
			point[i]++;
		}
	}
	else if(intLen < CALC_MAX_DIGITS)
	{
		if(point[CALC_MAX_DIGITS - intLen] < '5')
		{
			i = 1;
			while(point[CALC_MAX_DIGITS - intLen -i]== '0')
			{
				i++;
			}
			if(point[CALC_MAX_DIGITS - intLen -i]== '.')
			{
				point[CALC_MAX_DIGITS - intLen - i] = '\0';
			}
			else
			{
				point[CALC_MAX_DIGITS - intLen - i + 1] = '\0';
			}
		}
		else if(point[CALC_MAX_DIGITS - intLen] >= '5')
		{
			i = 1;
			while((point[CALC_MAX_DIGITS - intLen - i] == '9')&& (CALC_MAX_DIGITS - intLen - i > 0))
			{
				i++;
			}
			if(i < CALC_MAX_DIGITS - intLen)
			{
				point[CALC_MAX_DIGITS - intLen - i]++;
				point[CALC_MAX_DIGITS - intLen - i + 1] = '\0';
			}
			else
			{
				point[0] = '\0';
				i = -1;
				while(point[i] == '9' && (-i) <= intLen)
				{
					point[i] = '0';
					i--;
				}
				if(-i <= intLen)
				{
					point[i]++;
				}
				/* 
					 99.99999999999 -> 100;
				   -999.99999999999 -> -1000
				*/
				else
				{
					if(sign == MMI_TRUE)
					{
						resultStr[0] = '-';
						resultStr[1] = '1';
						for(i=0; i<intLen; i++)
						{
							resultStr[i+2] = '0';
						}
						resultStr[intLen+2] = '\0';
					}
					else
					{
						resultStr[0] = '1';
						for(i=0; i<intLen; i++)
						{
							resultStr[i+1] = '0';
						}
						resultStr[intLen+1] = '\0';
					}	
				}
			}
		}
	}
	if((resultStr[0] == '-') && (resultStr[1] == '0') && (resultStr[2] == '\0'))
	{
	    resultStr[0] = '0';
		resultStr[1] = '\0';
	}

    mmi_asc_to_ucs2((CHAR *)String, resultStr);
}


/*****************************************************************************
 * FUNCTION
 *  calc_atof
 * DESCRIPTION
 *  Convert string to float
 * PARAMETERS
 *  s       [IN]        String to be converted
 * RETURNS
 *  float value of the string
 *****************************************************************************/
DOUBLE calc_atof(WCHAR *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR out[CALC_MAX_BUFF_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcs_to_asc(out, s);
    return atof(out);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_calc_main_scrn_proc
 * DESCRIPTION
 *  proc function for main screen
 * PARAMETERS
 *  evt     [IN] 
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_calc_main_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  #ifndef __GDI_MEMORY_PROFILE_2__
    gdi_color_format cf = GDI_COLOR_FORMAT_16;
  #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id) {
    case EVT_ID_SCRN_ACTIVE:
        
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
        gui_screen_switch_effect_setup(0, 0, 0);
#endif

#if CALC_DRAW_BACKGROUND
   #ifdef __GDI_MEMORY_PROFILE_2__
        gdi_layer_create(0, 0, UI_device_width, UI_device_height, &calculator_touch_top_layer);
   #else
		g_calc_cntx->buf_calc_touch_top_layer = (U8 *)mmi_frm_scrmem_alloc_framebuffer(UI_device_width * UI_device_height * 2);
        gdi_layer_create_cf_using_outside_memory(cf, 0, 0, UI_device_width, UI_device_height, &calculator_touch_top_layer,g_calc_cntx->buf_calc_touch_top_layer,UI_device_width * UI_device_height * 2);
   #endif
        gdi_layer_get_active(&cal_wall_paper_layer);
   #ifdef __CALC_FTE_SLIM_USE_SLICE_RES__
	    	//must clear base layer to bg scrn; 
        gdi_layer_lock_frame_buffer();
				gui_draw_filled_area(0, 0, 0+UI_DEVICE_WIDTH-1, 0+UI_DEVICE_HEIGHT-1,current_MMI_theme->sub_menu_bkg_filler);
				gdi_layer_unlock_frame_buffer();
	#endif
        gdi_layer_set_blt_layer(calculator_touch_top_layer, 0, 0, 0);
        gdi_layer_push_and_set_active(calculator_touch_top_layer);
   #ifndef __CALC_FTE_SLIM_USE_SLICE_RES__
	      //FTE,no set, avoid status bar white bd color be shown;
        gdi_set_alpha_blending_source_layer(calculator_touch_top_layer);
   #endif
        gdi_layer_pop_and_restore_active();
#endif
        g_current_r2l_flag = mmi_fe_get_r2l_state();
        //对于Calculator APP必须强制设置r2l为false;
        mmi_fe_set_r2l_state(MMI_FALSE);
        calc_update();
        calc_register_input_hdlr();

        RedrawCategoryFunction = calc_update;
    
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
        gui_screen_switch_effect_run();
#endif

        break;

    case EVT_ID_SCRN_INACTIVE:

#if CALC_DRAW_BACKGROUND
        gdi_layer_flatten_to_base(calculator_touch_top_layer, 0, 0, 0);
        gdi_layer_free(calculator_touch_top_layer);
	 #ifndef __GDI_MEMORY_PROFILE_2__
	    calculator_touch_top_layer = NULL;
	    mmi_frm_scrmem_free(g_calc_cntx->buf_calc_touch_top_layer);
		g_calc_cntx->buf_calc_touch_top_layer = NULL;
	 #endif
    	gdi_layer_set_active(cal_wall_paper_layer);
		gdi_layer_set_blt_layer(cal_wall_paper_layer, 0, 0, 0);
#endif
        if (g_calc_cntx->Cache.buf_ptr != NULL)
        {
            mmi_frm_scrmem_free(g_calc_cntx->Cache.buf_ptr);
            g_calc_cntx->Cache.buf_ptr = NULL;
        }
        g_calc_cntx->CurrHilite = NULL;
		mmi_fe_set_r2l_state(g_current_r2l_flag);

        break;
        
    case EVT_ID_SCRN_DEINIT:

        CalcDeInit();
        
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}

#ifdef __MMI_AP_DCM_CALC__
#pragma arm section rodata,code
#endif

/*****************************************************************************
 * FUNCTION
 *  HighlightCalcMenu
 * DESCRIPTION
 *  Highlight handler of Calculator menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCalcMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(CalcPreEntryApp, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(CalcPreEntryApp, KEY_EVENT_UP);
}

#ifdef __MMI_AP_DCM_CALC__
#pragma arm section rodata = "DYNAMIC_CODE_CALCULATOR_ROCODE",code = "DYNAMIC_CODE_CALCULATOR_RODATA"
#endif

/*****************************************************************************
 * FUNCTION
 *  CalcDeInit
 * DESCRIPTION
 *  Free dynamic memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void CalcDeInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->Cache.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(g_calc_cntx->Cache.buf_ptr);
        g_calc_cntx->Cache.buf_ptr = NULL;
    }
	g_calc_cntx->CurrHilite = NULL;
}

static mmi_ret mmi_calc_main_group_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    	case EVT_ID_GROUP_DEINIT:
  	#ifdef __MMI_AP_DCM_CALC__
		  mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_CALCULATOR);
  	#endif

	    break;
    }
	return MMI_RET_OK;
}
#ifdef __MMI_AP_DCM_CALC__
#pragma arm section rodata,code
#endif
/*****************************************************************************
 * FUNCTION
 *  CalcPreEntryApp
 * DESCRIPTION
 *  Initialize data before entry calculator.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcPreEntryApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_AP_DCM_CALC__
      mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_CALCULATOR);
 #endif
    memset(g_calc_cntx, 0, sizeof(*g_calc_cntx));
    calc_set_number(CALC_0);

    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_CALC,
        mmi_calc_main_group_proc,
        g_calc_cntx,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_CALC, SCR_ID_CALC_APP, mmi_calc_main_scrn_proc, g_calc_cntx);
}


#ifdef __MMI_AP_DCM_CALC__
#pragma arm section rodata = "DYNAMIC_CODE_CALCULATOR_ROCODE",code = "DYNAMIC_CODE_CALCULATOR_RODATA"
#endif
static void calc_input_hdlr(U16 input)
{
    MMI_BOOL update = MMI_TRUE;
    calc_button_struct *hilight = g_calc_cntx->CurrHilite;
    S32 retval;

	MMI_ID current_active_grp_id = GRP_ID_INVALID;
	MMI_ID current_active_scrn_id = SCR_ID_INVALID;
#if CALC_NAVI_HILIGHT
    g_calc_cntx->CurrHilite = calc_get_button(input);
#endif

    if (input == CALC_CLEAR_ALL)
    {
        g_calc_cntx->Operand1 = 0;
        g_calc_cntx->Operand2 = 0;
        g_calc_cntx->MemValue = 0;
        calc_set_number(CALC_0);
        g_calc_cntx->State = CALC_STATE_OPERAND1;
    }
    else
    {
        switch (g_calc_cntx->State) {
        case CALC_STATE_EXCEPTION:
            if (input == CALC_CLEAR)
            {
                g_calc_cntx->Operand1 = 0;
                g_calc_cntx->Operand2 = 0;
                g_calc_cntx->MemValue = 0;
                calc_set_number(CALC_0);
                g_calc_cntx->State = CALC_STATE_OPERAND1;
            }
            else
            {
                update = MMI_FALSE;
                srv_prof_play_tone(SRV_PROF_TONE_ERROR, NULL);
            }
            break;

        case CALC_STATE_OPERAND1:

            if (input > CALC_NUM_BEGIN && input < CALC_NUM_END)
            {
                update = calc_append_number(input) ? MMI_TRUE : MMI_FALSE;
            }
            else if (input > CALC_OP_BEGIN && input < CALC_OP_END)
            {
                if (input != CALC_EQUAL)
                {
                    g_calc_cntx->Operator = input;
                    g_calc_cntx->Operand1 = calc_atof(g_calc_cntx->InputBuff);
                    g_calc_cntx->Operand2 = 0;
                    calc_set_number(CALC_0);
                    g_calc_cntx->State = CALC_STATE_OPERAND2;
                }
                else
                    update = MMI_FALSE;
            }
		 #ifndef __CALC_SLIM_FOR_61__
            else if (input > CALC_MEM_BEGIN && input < CALC_MEM_END)
            {
                update = calc_mem_input_hdlr(input);
            }
		 #endif/*__CALC_SLIM_FOR_61__*/
            else if (input == CALC_CLEAR)
            {
                update = calc_remove_number();
            }

            break;

        case CALC_STATE_OPERAND2:

            if (input > CALC_NUM_BEGIN && input < CALC_NUM_END)
            {
                update = calc_append_number(input) ? MMI_TRUE : MMI_FALSE;
				//一旦进入操作数2的状态，下次就是进行新的operand 动作；
			 //#ifdef __CALC_96_64_SOLUTION_SLIM__
			 #ifdef	__MMI_MAINLCD_96X64__
				g_is_new_operand = KAL_TRUE;
			 #endif/*__CALC_96_64_SOLUTION_SLIM__*/
            }
            else if (input > CALC_OP_BEGIN && input < CALC_OP_END)
            {
              #ifndef __CALC_SLIM_FOR_61__
                if (input == CALC_EQUAL || calc_number_inputed())
			  #else
			    if (input == CALC_EQUAL || g_calc_cntx->ValidInput)
			  #endif/*__CALC_SLIM_FOR_61__*/
                {
                    DOUBLE result;
                    g_calc_cntx->Operand2 = calc_atof(g_calc_cntx->InputBuff);
                    retval = calc_compute_result(
                                &result,
                                g_calc_cntx->Operand1,
                                g_calc_cntx->Operand2,
                                g_calc_cntx->Operator);
                    if (retval == CALC_RESULT_SUCC)
                    {
                        g_calc_cntx->Operand1 = result;
                        g_calc_cntx->Operand2 = 0;
                        if (input == CALC_EQUAL)
                        {
                            g_calc_cntx->Operator = 0;
						 #ifndef __CALC_SLIM_FOR_61__
                            calc_reset_number(result);
						 #else
						    calc_ftoa(result, g_calc_cntx->InputBuff);
    						g_calc_cntx->ValidInput = (MMI_BOOL)(result != 0);
						 #endif/*__CALC_SLIM_FOR_61__*/
                            g_calc_cntx->State = CALC_STATE_EQUAL;
                        }
                        else
                        {
                            g_calc_cntx->Operator = input;
                            calc_set_number(CALC_0);
                        }
                    }
                    else
				#ifndef __CALC_SLIM_FOR_61__
                        calc_exception_hdlr(retval);
				#else
					{
					    srv_prof_play_tone(SRV_PROF_TONE_ERROR, NULL);

					    g_calc_cntx->Operand1 = 0;
					    g_calc_cntx->Operand2 = 0;
					    g_calc_cntx->InputBuff[0] = L'0';
					    g_calc_cntx->InputBuff[1] = L'\0';
					    g_calc_cntx->State = CALC_STATE_EXCEPTION;

                    }
				#endif/*__CALC_SLIM_FOR_61__*/
                }
                else
                {
                    //update = !(input == g_calc_cntx->Operator);
                    if(input == g_calc_cntx->Operator)
						update = MMI_FALSE;
					else
						update = MMI_TRUE;
                    g_calc_cntx->Operator = input;
                }
            }
		#ifndef __CALC_SLIM_FOR_61__
            else if (input > CALC_MEM_BEGIN && input < CALC_MEM_END)
            {
                update = calc_mem_input_hdlr(input);
            }
		#endif/*__CALC_SLIM_FOR_61__*/
            else if (input == CALC_CLEAR)
            {
              #ifndef __CALC_SLIM_FOR_61__
                if (calc_number_inputed())
			  #else
			    if (g_calc_cntx->ValidInput)
			  #endif/*__CALC_SLIM_FOR_61__*/
                    update = calc_remove_number();
                else
                {
                    g_calc_cntx->Operator = 0;
				 #ifndef __CALC_SLIM_FOR_61__
                    calc_reset_number(g_calc_cntx->Operand1);
				 #else
				    calc_ftoa(g_calc_cntx->Operand1, g_calc_cntx->InputBuff);
    				g_calc_cntx->ValidInput = (MMI_BOOL)(g_calc_cntx->Operand1 != 0);
				 #endif/*__CALC_SLIM_FOR_61__*/
                    g_calc_cntx->Operand1 = 0;
                    g_calc_cntx->State = CALC_STATE_OPERAND1;
				 //#ifdef __CALC_96_64_SOLUTION_SLIM__
				 #ifdef __MMI_MAINLCD_96X64__
				    g_is_new_operand = KAL_TRUE;
			     #endif
                }
            }

            break;

        case CALC_STATE_EQUAL:

            if (input > CALC_NUM_BEGIN && input < CALC_NUM_END)
            {
                calc_set_number(input);
                g_calc_cntx->State = CALC_STATE_OPERAND1;
            }
            else if (input > CALC_OP_BEGIN && input < CALC_OP_END)
            {
                if (input != CALC_EQUAL)
                {
                    g_calc_cntx->Operator = input;
                    g_calc_cntx->Operand2 = 0;
                    calc_set_number(CALC_0);
                    g_calc_cntx->State = CALC_STATE_OPERAND2;
                }
                else
                {
                    update = MMI_FALSE;
                }
            }
		#ifndef __CALC_SLIM_FOR_61__
            else if (input > CALC_MEM_BEGIN && input < CALC_MEM_END)
            {
                update = calc_mem_input_hdlr(input);
                if (input == CALC_MR)
                    g_calc_cntx->State = CALC_STATE_OPERAND1;
            }
		#endif/*__CALC_SLIM_FOR_61__*/
            else if (input == CALC_CLEAR)
            {
                g_calc_cntx->Operand1 = 0;
                g_calc_cntx->Operand2 = 0;
                calc_set_number(CALC_0);
                g_calc_cntx->State = CALC_STATE_OPERAND1;
            }

            break;

        default:
            break;
        }
    }

    mmi_frm_get_active_scrn_id(&current_active_grp_id ,&current_active_scrn_id);
    if(update && current_active_grp_id == GRP_ID_CALC && current_active_scrn_id == SCR_ID_CALC_APP)
    //if (update)
    {
        calc_update_output();
        calc_update_softkey();
    }

    if (g_calc_cntx->CurrHilite != hilight)
    {
        calc_update_input();
    }

}

#ifndef __CALC_SLIM_FOR_61__
static MMI_BOOL calc_mem_input_hdlr(U16 input)
{
    DOUBLE value;
    DOUBLE op1 = g_calc_cntx->MemValue;
    DOUBLE op2 = calc_atof(g_calc_cntx->InputBuff);
    S32 retval;
    U16 op;

    switch (input) {
    case CALC_MR:

        calc_reset_number(g_calc_cntx->MemValue);

        break;

    case CALC_MC:

        g_calc_cntx->MemValue = 0;

        break;

    case CALC_MP:
    case CALC_MM:

        op = (input == CALC_MP) ? CALC_PLUS : CALC_MINUS;
        
        retval = calc_compute_result(&value, op1, op2, op);
        if (retval == CALC_RESULT_SUCC)
            g_calc_cntx->MemValue = value;
        else
            g_calc_cntx->MemValue = 0;
            
        break;

    default:
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

static void calc_exception_hdlr(S32 result)
{
#if 0
#ifdef __MMI_OP02_0100__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#endif

    g_calc_cntx->Operand1 = 0;
    g_calc_cntx->Operand2 = 0;
    g_calc_cntx->InputBuff[0] = L'0';
    g_calc_cntx->InputBuff[1] = L'\0';
    g_calc_cntx->State = CALC_STATE_EXCEPTION;
}
#endif /*__CALC_SLIM_FOR_61__*/


static MMI_BOOL calc_append_number(U16 input)
{
    WCHAR *buff = g_calc_cntx->InputBuff;
    WCHAR *in = calc_string_format(input);
    S32 len = mmi_wcslen(buff);

    /* if operand2 = -(12 digit) || (12 digit) */
    {
        S32 max_len = len + ((input == CALC_00) ? 2:1);
        if (buff[0] == L'-')
            max_len --;

        if (max_len > CALC_MAX_DIGITS)
        {
            srv_prof_play_tone(SRV_PROF_TONE_ERROR, NULL);
            return MMI_FALSE;
        }
    }
    
    if (!g_calc_cntx->ValidInput)
    {
        if (input == CALC_0 || input == CALC_00)
            return MMI_FALSE;

        g_calc_cntx->ValidInput = MMI_TRUE;

        if (input != CALC_DOT)
        {
            mmi_wcscpy(buff, in);

            return MMI_TRUE;
        }
    }
    
    if (input == CALC_DOT && mmi_wcschr(buff, L'.'))
        return MMI_FALSE;

    mmi_wcscat(buff, in);

    return MMI_TRUE;
}

static MMI_BOOL calc_remove_number(void)
{
    WCHAR *buff = g_calc_cntx->InputBuff;
    S32 len = mmi_wcslen(buff);
    
    if (!g_calc_cntx->ValidInput)
        return MMI_FALSE;

    if (len > 1)
    {
        buff[len-1] = '\0';
        if (mmi_wcslen(buff) == 1 && buff[0] == L'0')
            g_calc_cntx->ValidInput = MMI_FALSE;
    }
    else
    {
        buff[0] = L'0';
        buff[1] = L'\0';
        g_calc_cntx->ValidInput = MMI_FALSE;
    }

    return MMI_TRUE;
}

static MMI_BOOL calc_set_number(U16 input)
{
    WCHAR *buff = g_calc_cntx->InputBuff;

    if (input == CALC_0 || input == CALC_00)
    {
        mmi_wcscpy(buff, calc_string_format(CALC_0));        
        g_calc_cntx->ValidInput = MMI_FALSE;
    }
    else
    {
        if (input == CALC_DOT)
            mmi_wcscpy(buff, L"0.");
        else
            mmi_wcscpy(buff, calc_string_format(input));

        g_calc_cntx->ValidInput = MMI_TRUE;
    }

    return MMI_TRUE;
}

#ifndef __CALC_SLIM_FOR_61__
static void calc_reset_number(DOUBLE num)
{
    calc_ftoa(num, g_calc_cntx->InputBuff);

    g_calc_cntx->ValidInput = (MMI_BOOL)(num != 0);
}


static MMI_BOOL calc_number_inputed(void)
{
    return g_calc_cntx->ValidInput;
}
#endif/*__CALC_SLIM_FOR_61__*/

static S32 calc_compute_result(DOUBLE *result, DOUBLE op1, DOUBLE op2, U16 op)
{
    S32 retval = CALC_RESULT_SUCC;

    switch (op) {
    case CALC_PLUS:
        
        *result = op1 + op2;
        
        break;
        
    case CALC_MINUS:
        
        *result = op1 - op2;
        
        break;

    case CALC_MULT:
        
        *result = op1 * op2;
        
        break;

    case CALC_DIV:

        if (op2 != 0)
            *result = op1 / op2;
        else
        {
            *result = 0;
            retval = CALC_RESULT_DIV0;
        }

        break;

    default:
        break;
    }

 #ifndef __CALC_SLIM_FOR_61__
    if (!calc_check_boundary(*result))
 #else
    if (*result>= CALC_MAX_RESULT || *result <= CALC_MIN_RESULT)
 #endif/*__CALC_SLIM_FOR_61__*/
    {
        *result = 0;
        retval = CALC_RESULT_EXCEED;
    }

    return retval;
}

static WCHAR *calc_string_format(U16 input)
{
    S32 i;

    for (i = 0; i < sizeof(g_calc_input_tab)/sizeof(calc_format_struct); i++)
    {
        if (g_calc_input_tab[i].input == input)
            return g_calc_input_tab[i].text;
    }

    return L"E";
}

#ifndef __CALC_SLIM_FOR_61__
static MMI_BOOL calc_check_boundary(DOUBLE result)
{
    if(result >= CALC_MAX_RESULT || result <= CALC_MIN_RESULT)
        return MMI_FALSE;

    return MMI_TRUE;
}
#endif/*__CALC_SLIM_FOR_61__*/


#if CALC_NAVI_HILIGHT
static U16 calc_navi_hilight(U8 key_code)
{
    U16 input = 0;
    calc_button_struct *hilight = g_calc_cntx->CurrHilite;

    if (g_calc_cntx->State == CALC_STATE_EXCEPTION)
    {
        srv_prof_play_tone(SRV_PROF_TONE_ERROR, NULL);
        return 0;
    }
 //#ifdef __CALC_96_64_SOLUTION_SLIM__
 #ifdef __MMI_MAINLCD_96X64__
    if (!hilight || (hilight && g_calc_cntx->State != CALC_STATE_EXCEPTION) )
 #else
    if (!hilight)
 #endif
    {
        switch (key_code) {
            
	  //#ifndef __CALC_96_64_SOLUTION_SLIM__
	  #ifndef __MMI_MAINLCD_96X64__
        case KEY_LEFT_ARROW:  input = CALC_MULT; break;
        case KEY_RIGHT_ARROW: input = CALC_DIV; break;
        case KEY_UP_ARROW:    input = CALC_PLUS; break;
        case KEY_DOWN_ARROW:  input = CALC_MINUS; break;
	  #else
	    case KEY_LEFT_ARROW:
            if(g_is_new_operand == KAL_TRUE)
            {
			   g_highlight_site_counter = g_left_init;
			   g_is_new_operand = KAL_FALSE;
            }
			
			g_highlight_site_counter--;

			if(g_highlight_site_counter < 0)
				g_highlight_site_counter += 4;
			
			if(g_highlight_site_counter%4 == 3)
			   input = CALC_MULT; 
			else if(g_highlight_site_counter%4 == 2)
			   input = CALC_DIV;
			else if(g_highlight_site_counter%4 == 1)
			   input = CALC_MINUS;
			else 
			   input = CALC_PLUS;

			break;
			
        case KEY_RIGHT_ARROW: 
			if(g_is_new_operand == KAL_TRUE)
			{
			   g_highlight_site_counter = g_right_init;
			   g_is_new_operand = KAL_FALSE;
			}
			
			g_highlight_site_counter++;

			if(g_highlight_site_counter > 4)
				g_highlight_site_counter -=4;
			
			if(g_highlight_site_counter%4 == 3)
			   input = CALC_MULT; 
			else if(g_highlight_site_counter%4 == 2)
			   input = CALC_DIV;
			else if(g_highlight_site_counter%4 == 1)
			   input = CALC_MINUS;
			else 
			   input = CALC_PLUS;
			
			break;
			
        case KEY_UP_ARROW:                       
			break;
        case KEY_DOWN_ARROW:                     
			break;
	  #endif/*__CALC_96_64_SOLUTION_SLIM__*/

        default: break;
        }
    }
    else if (KEY_LEFT_ARROW == key_code)
    {
        switch (hilight->input) {
            
	 #ifndef __CALC_SLIM_FOR_61__
        case CALC_MR:   input = CALC_DIV;  break;
        case CALC_MULT: input = CALC_MC; break;
        case CALC_MP:
        case CALC_MM:
	 #endif/*__CALC_SLIM_FOR_61__*/
        case CALC_PLUS:
        case CALC_MINUS:
        case CALC_DIV:  input = CALC_MULT; break;

        default: break;
        }
    }
    else if (KEY_RIGHT_ARROW == key_code)
    {
        switch (hilight->input) {
            
	  #ifndef __CALC_SLIM_FOR_61__
        case CALC_MC:   input = CALC_MULT; break;
        case CALC_DIV:  input = CALC_MR; break;
        case CALC_MP:
        case CALC_MM:
	  #endif/*__CALC_SLIM_FOR_61__*/
        case CALC_PLUS:
        case CALC_MINUS:
        case CALC_MULT: input = CALC_DIV; break;
            
        default: break;
        }
    }
    else if (KEY_UP_ARROW == key_code)
    {
        switch (hilight->input) {
            
	  #ifndef __CALC_SLIM_FOR_61__
        case CALC_MM:   input = CALC_MINUS; break;
        case CALC_PLUS:  

            calc_input_hdlr(CALC_EQUAL);
            input = CALC_MP; 
            break;

        case CALC_MC:
        case CALC_MR:
	  #endif/*__CALC_SLIM_FOR_61__*/
        case CALC_MINUS:
        case CALC_DIV:
        case CALC_MULT: input = CALC_PLUS; break;
            
        default: break;
        }
    }
    else if (KEY_DOWN_ARROW == key_code)
    {
        switch (hilight->input) {
            
	 #ifndef __CALC_SLIM_FOR_61__
        case CALC_MP:   input = CALC_PLUS; break;
        case CALC_MINUS:
            calc_input_hdlr(CALC_EQUAL);
            input = CALC_MM;
            break;

        case CALC_MC:
        case CALC_MR:
	 #endif/*__CALC_SLIM_FOR_61__*/
        case CALC_PLUS:
        case CALC_DIV:
        case CALC_MULT: input = CALC_MINUS; break;

        default: break;
        }
    }

    return input;
}
#endif

static mmi_ret calc_key_hdlr(mmi_event_struct *evt)
{
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    U8 key_code = key_evt->key_code;
    U8 key_type = key_evt->key_type;
    U16 input = 0;
    calc_button_struct *btn = NULL;

    if (key_evt->evt_id != EVT_ID_ON_KEY)
        return MMI_RET_OK;

    switch (key_code) {
    case KEY_BACKSPACE:
    case KEY_CLEAR:

        if (key_type == KEY_EVENT_DOWN)
            input = CALC_CLEAR;
        else if (key_type == KEY_LONG_PRESS)
            input = CALC_CLEAR_ALL;

        break;

#if CALC_NAVI_HILIGHT
    case KEY_UP_ARROW:
    case KEY_DOWN_ARROW:
    case KEY_LEFT_ARROW:
    case KEY_RIGHT_ARROW:
        
        if (key_type == KEY_EVENT_DOWN)
            input = calc_navi_hilight(key_code);
        
        break;
        
    case KEY_0:
    case KEY_1:
    case KEY_2:
    case KEY_3:
    case KEY_4:
    case KEY_5:
    case KEY_6:
    case KEY_7:
    case KEY_8:
    case KEY_9:

        if (key_type == KEY_EVENT_DOWN)
            input = CALC_0 + key_code - KEY_0;

        break;
        
    case KEY_POUND:

        if (key_type == KEY_EVENT_DOWN)
            input = CALC_DOT;

        break;
#endif
 
    default:
#if !CALC_NAVI_HILIGHT
        btn = calc_get_button_by_shortcut(key_code);
        if (btn)
        {
            if (key_type == KEY_EVENT_DOWN)
                calc_hilight_btn(btn);
            else if (key_type == KEY_EVENT_UP)
            {
                calc_lowlight_btn(btn);
                input = btn->input;
            }
        }
#endif
        break;
    }

    if (input)
        calc_input_hdlr(input);

    if (input || btn)
        return MMI_RET_KEY_HANDLED;

    return MMI_RET_OK;
}

static void calc_lsk_hdlr(void)
{
#if CALC_LSK_CLEAR
    calc_input_hdlr(CALC_CLEAR);
#else
    calc_input_hdlr(CALC_EQUAL);
#endif
}

static void calc_lsk_long_press_hdlr(void)
{
#if CALC_LSK_CLEAR 
    calc_input_hdlr(CALC_CLEAR_ALL);
#endif
}

static void calc_csk_down_hdlr(void)
{
    calc_button_struct *btn = NULL;
	
	btn = calc_get_button_by_shortcut(KEY_CSK);
	calc_hilight_btn(btn);
}

static void calc_csk_up_hdlr(void)
{
	calc_button_struct *btn = NULL;
	
	btn = calc_get_button_by_shortcut(KEY_CSK);
	calc_lowlight_btn(btn);
    calc_input_hdlr(CALC_EQUAL);
}

static void calc_rsk_up_hdlr(void)
{
#if CALC_LSK_CLEAR 
    mmi_frm_scrn_close_active_id();
#else
   #ifndef __CALC_SLIM_FOR_61__
    if (g_calc_cntx->State > CALC_STATE_OPERAND1 || calc_number_inputed())
   #else
    if (g_calc_cntx->State > CALC_STATE_OPERAND1 || g_calc_cntx->ValidInput)
   #endif/*__CALC_SLIM_FOR_61__*/
        calc_input_hdlr(CALC_CLEAR);
    else
        mmi_frm_scrn_close_active_id();
#endif
}

static void calc_rsk_long_press_hdlr(void)
{
#if !CALC_LSK_CLEAR 
  #ifndef __CALC_SLIM_FOR_61__
    if (g_calc_cntx->State > CALC_STATE_OPERAND1 || calc_number_inputed())
  #else
    if (g_calc_cntx->State > CALC_STATE_OPERAND1 || g_calc_cntx->ValidInput)
  #endif/*__CALC_SLIM_FOR_61__*/
        calc_input_hdlr(CALC_CLEAR_ALL);
#endif
}

#ifdef __MMI_TOUCH_SCREEN__
static void calc_pen_down_hdlr(mmi_pen_point_struct pt)
{
    gui_button_pen_enum type;
    calc_button_struct *btn;
    wgui_status_icon_bar_pen_enum status_icon_bar_event;
    S32 status_icon_id; 
	
    if(wgui_status_icon_bar_translate_pen_event(MMI_PEN_EVENT_DOWN,pt.x,pt.y,&status_icon_id,&status_icon_bar_event))
    {
		// tap status icon bar to drag down N-Center
	} 
    else if (translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_DOWN, pt.x, pt.y, &type))
    {
        execute_softkey_function(KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY);
    }
    else if (translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_DOWN, pt.x, pt.y, &type))
    {
        execute_softkey_function(KEY_EVENT_DOWN, MMI_RIGHT_SOFTKEY);
    }
    else if (translate_softkey_pen_event(MMI_CENTER_SOFTKEY, MMI_PEN_EVENT_DOWN, pt.x, pt.y, &type))
    {
        execute_softkey_function(KEY_EVENT_DOWN, MMI_CENTER_SOFTKEY);
    }
    else
    {
        btn = calc_get_button_by_pt(&pt);
        if (btn)
        {
            calc_hilight_btn(btn);
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif /* __MMI_TOUCH_FEEDBACK_SUPPORT__ */
        }
    }
}

static void calc_pen_move_hdlr(mmi_pen_point_struct pt)
{
    calc_button_struct *btn;
    wgui_status_icon_bar_pen_enum status_icon_bar_event;
    S32 status_icon_id; 
    
    btn = calc_get_button_by_pt(&pt);
	
    if(wgui_status_icon_bar_translate_pen_event(MMI_PEN_EVENT_MOVE,pt.x,pt.y,&status_icon_id,&status_icon_bar_event))
    {
		// tap status icon bar to drag down N-Center
	} 
    else if (btn)
    {
        calc_hilight_btn(btn);
    }
    else
    {
        calc_lowlight_btn(g_calc_cntx->CurrHilite);
    }
}

static void calc_pen_long_tap_hdlr(mmi_pen_point_struct pt)
{
    gui_button_pen_enum type;
    calc_button_struct *btn;
    wgui_status_icon_bar_pen_enum status_icon_bar_event;
    S32 status_icon_id;  
	
#ifndef __MMI_KEY_ONLY_NCENTER__    
    btn = calc_get_button_by_pt(&pt);

    if (btn && btn->input == CALC_CLEAR)
    {
        calc_lowlight_btn(btn);
        calc_input_hdlr(CALC_CLEAR_ALL);
    }
    else
#endif		
    {
        if(wgui_status_icon_bar_translate_pen_event(MMI_PEN_EVENT_LONG_TAP,pt.x,pt.y,&status_icon_id,&status_icon_bar_event))
        {
            // tap status icon bar to drag down N-Center
        } 
        else if (translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_LONG_TAP, pt.x, pt.y, &type) &&
			type == GUI_BUTTON_PEN_LONGTAP)
        {
            execute_softkey_function(KEY_LONG_PRESS, MMI_RIGHT_SOFTKEY);
        }
        else if (translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_LONG_TAP, pt.x, pt.y, &type) &&
			type == GUI_BUTTON_PEN_LONGTAP)
        {
            execute_softkey_function(KEY_LONG_PRESS, MMI_LEFT_SOFTKEY);
        }
    }
}

static void calc_pen_repeat_hdlr(mmi_pen_point_struct pt)
{
    calc_button_struct *btn;
    wgui_status_icon_bar_pen_enum status_icon_bar_event;
    S32 status_icon_id;  
    
    btn = calc_get_button_by_pt(&pt);

    if(wgui_status_icon_bar_translate_pen_event(MMI_PEN_EVENT_REPEAT,pt.x,pt.y,&status_icon_id,&status_icon_bar_event))
    {
        // tap status icon bar to drag down N-Center
    }
    else if (btn && btn->input > CALC_NUM_BEGIN && btn->input < CALC_NUM_END)
    {
        calc_input_hdlr(btn->input);
    }
}

static void calc_pen_up_hdlr(mmi_pen_point_struct pt)
{
    gui_button_pen_enum type;
    calc_button_struct *btn;
    wgui_status_icon_bar_pen_enum status_icon_bar_event;
    S32 status_icon_id; 

    if(wgui_status_icon_bar_translate_pen_event(MMI_PEN_EVENT_UP,pt.x,pt.y,&status_icon_id,&status_icon_bar_event))
    {
        // tap status icon bar to drag down N-Center
    }
    else if (translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_UP, pt.x, pt.y, &type) &&
        type == GUI_BUTTON_PEN_UP_INSIDE)
    {
        execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
    }
    else if (translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_UP, pt.x, pt.y, &type) &&
        type == GUI_BUTTON_PEN_UP_INSIDE)
    {
        execute_softkey_function(KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
    }
    else if (translate_softkey_pen_event(MMI_CENTER_SOFTKEY, MMI_PEN_EVENT_UP, pt.x, pt.y, &type) &&
        type == GUI_BUTTON_PEN_UP_INSIDE)
    {
        execute_softkey_function(KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
    }
    else
    {
        btn = calc_get_button_by_pt(&pt);
        if (btn && btn == g_calc_cntx->CurrHilite)
        {
            calc_lowlight_btn(btn);
            calc_input_hdlr(btn->input);
        }
        else if (g_calc_cntx->CurrHilite)
        {
            calc_lowlight_btn(g_calc_cntx->CurrHilite);
        }
    }
}
#endif

static void calc_register_input_hdlr(void)
{
    register_default_hide_softkeys();

    mmi_frm_scrn_set_key_proc(GRP_ID_CALC, SCR_ID_CALC_APP, calc_key_hdlr);    

    SetLeftSoftkeyFunction(calc_lsk_hdlr, KEY_EVENT_UP); 
#ifndef __MMI_KEY_ONLY_NCENTER__	
    SetLeftSoftkeyFunction(calc_lsk_long_press_hdlr, KEY_LONG_PRESS);
#endif
    SetRightSoftkeyFunction(calc_rsk_up_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(calc_rsk_long_press_hdlr, KEY_LONG_PRESS);
    SetCenterSoftkeyFunction(calc_csk_up_hdlr, KEY_EVENT_UP);    
	SetCenterSoftkeyFunction(calc_csk_down_hdlr, KEY_EVENT_DOWN); 

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(calc_pen_down_hdlr);
    mmi_pen_register_up_handler(calc_pen_up_hdlr);
    mmi_pen_register_move_handler(calc_pen_move_hdlr);
    mmi_pen_register_repeat_handler(calc_pen_repeat_hdlr);
    mmi_pen_register_long_tap_handler(calc_pen_long_tap_hdlr);
#endif
}

static void calc_hilight_btn(calc_button_struct *btn)
{
    calc_rect_struct *region;
    gdi_handle active_layer;
	MMI_ID current_active_grp_id = GRP_ID_INVALID;
	MMI_ID current_active_scrn_id = SCR_ID_INVALID;
 #ifdef __CALC_FTE_SLIM_USE_SLICE_RES__
	stFontAttribute font;
	S32 h,w;
    char input_num[2] = "\0";
	//calc_input_enum input_enum;
	char input_double_num[3] = "00\0";
    char dot = '.';
	WCHAR convert_to_ucs2[4];
	memset((char*)convert_to_ucs2 , 0x00 ,sizeof(convert_to_ucs2));
 #endif

    mmi_frm_get_active_scrn_id(&current_active_grp_id ,&current_active_scrn_id);
    if (!btn || btn == g_calc_cntx->CurrHilite || !(current_active_grp_id == GRP_ID_CALC && current_active_scrn_id == SCR_ID_CALC_APP)) return;

    if (g_calc_cntx->CurrHilite)
        calc_lowlight_btn(g_calc_cntx->CurrHilite);
    
    g_calc_cntx->CurrHilite = btn;

    region = &btn->region;
    
    if (g_calc_cntx->Cache.buf_ptr == NULL)
    {
        U32 size = region->width * region->height * (gdi_layer_get_bit_per_pixel() / 3);
        g_calc_cntx->Cache.buf_ptr = (U8 *)mmi_frm_scrmem_alloc(size);
    }

    gdi_layer_push_and_set_clip(
        region->left, region->top,
        region->left + region->width - 1,
        region->top + region->height - 1);

    gdi_image_cache_bmp_get(
        region->left, region->top,
        region->left + region->width - 1,
        region->top + region->height - 1,
        &g_calc_cntx->Cache);

    gdi_layer_pop_clip();

    gdi_layer_lock_frame_buffer();
    gdi_layer_push_and_set_clip(
        region->left, region->top,
        region->left + region->width - 1,
        region->top + region->height - 1);

    gdi_layer_get_active(&active_layer);
    gdi_push_and_set_alpha_blending_source_layer(active_layer);
#ifdef __MMI_SLIM_IMG_RES__
  #ifndef __CALC_SLIM_FOR_61__
    gdi_image_draw_resized(
        region->left, region->top,
        region->width, region->height,
        (U8 *)GetImage(btn->image));
  #else
    //对于+, x, /还是使用原有的流程，利用Image资源进行绘制；
    if(btn->image != 0)
		 gdi_image_draw_resized(
	        region->left, region->top,
	        region->width, region->height,
	        (U8 *)GetImage(btn->image));
	//slim处理，把-号资源移除，直接使用source code来画；
	else
	    gdi_draw_frame_rect(
	        		btn->region.left + 1, 
	        		btn->region.top + (btn->region.height - 4)/2,
	        		btn->region.left + 1 + btn->region.width -3,
	        		//btn->region.top + btn->region.height,
	        		btn->region.top + (btn->region.height - 4)/2 + 3,
	        		gdi_act_color_from_rgb(CALC_INPUT_SUB_COLOR),
	        		gdi_act_color_from_rgb(CALC_INPUT_SUB_COLOR),
	        		0);
  #endif/*__CALC_SLIM_FOR_61__*/
    //在highlight的背景上，绘制对应的数字；
#ifdef __CALC_FTE_SLIM_USE_SLICE_RES__

//if(btn->input != CALC_PLUS && btn->input != CALC_MINUS && btn->input != CALC_MULT && btn->input != CALC_DIV && btn->input != CALC_EQUAL)
if(btn->input != CALC_EQUAL)
{
   if(btn->input != CALC_PLUS && btn->input != CALC_MINUS && btn->input != CALC_MULT && btn->input != CALC_DIV && btn->input != CALC_EQUAL)
   {
      font = MMI_large_font;
      font.size = CALC_FONT_SIZE;
   }
   else
   {
      //font = MMI_medium_font;
      //font.size = MEDIUM_FONT;
      font = MMI_small_font;
	  font.size = SMALL_FONT;
   }

    switch(btn->input)
    {
       case CALC_1:
	   	 input_num[0] = '1';
		 break;

	   case CALC_2:
	   	 input_num[0] = '2';
		 break;

	   case CALC_3:
	   	 input_num[0] = '3';
		 break;

	   case CALC_4:
	   	 input_num[0] = '4';
		 break;

	   case CALC_5:
	   	 input_num[0] = '5';
		 break;

	   case CALC_6:
	   	 input_num[0] = '6';
		 break;

	   case CALC_7:
	   	 input_num[0] = '7';
		 break;

	   case CALC_8:
	   	 input_num[0] = '8';
		 break;

	   case CALC_9:
	   	 input_num[0] = '9';
		 break;

	   case CALC_0:
	   	 input_num[0] = '0';
		 break;

	   case CALC_00:
	   	 //input_double_num = "00";
		 input_num[0] = 0;
		 break;

	   case CALC_DOT:
	   	 input_num[0] = '.';
		 break;

	   case CALC_PLUS:
	   	 input_num[0] = '+';
		 break;

	   case CALC_MINUS:
	   	 input_num[0] = '-';
		 break; 

	   case CALC_MULT:
	   	 input_num[0] = 'x';
		 break; 

	   case CALC_DIV:
	   	 input_num[0] = '/';
		 break; 
    }
	
    gui_set_font(&font);
    {
        color c = CALC_FONT_COLOR;
        gui_set_text_color(c);
    }

	h = gui_get_character_height();

    if(input_num[0] == 0)
    {
	   //w = gui_get_string_width(input_double_num);
	   w = gui_get_character_width('0') * 2;
    }
	else
	{
	   w = gui_get_character_width((UI_character_type)input_num);
    }

	 			//输出. 字符，坐标微调；
				if(input_num[0] == dot)
					calc_move_text_cursor(
					0,
					region->left + (region->width - w)*3/4, 
					region->top + (region->height -h)/2  ,
					0);
				//输出00字串，坐标微调；
				else if(input_num[0] == 0)	
					calc_move_text_cursor(
					0,
					region->left + (region->width - w)/2, 
					region->top + (region->height -h)*3/4 ,
					0);
				//输出+ -，需要分别微调；
				else if(input_num[0] == '+')
					calc_move_text_cursor(
					0,
					region->left + (region->width - w)*11/20, 
					region->top + (region->height -h)*3/4 ,
					0);
				else if(input_num[0] == '-')
					calc_move_text_cursor(
					0,
					region->left + (region->width - w)*13/20, 
					region->top + (region->height -h)*1/2 ,
					0);
				//输出X  /  字符，坐标微调；
				else if(input_num[0] == 'x' || input_num[0] == '/')
					calc_move_text_cursor(
					0,
					region->left + (region->width - w), 
					region->top + (region->height -h)*2/4 ,
					0);
				else 
				   calc_move_text_cursor(
					0,
					region->left + (region->width - w)*3/4, 
					region->top + (region->height -h)*3/4 ,
					0);

    
	if(input_num[0]  == 0)
	{
	   mmi_asc_to_ucs2((char*)convert_to_ucs2 , input_double_num);
	   gui_print_text(convert_to_ucs2);
	}
	else
	{
	   mmi_asc_to_ucs2((char*)convert_to_ucs2 , input_num);
	   gui_print_text(convert_to_ucs2);
	}
}
    
#endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
#else
#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) 
    gdi_image_draw_resized(
        region->left, region->top,
        region->width, region->height,
        (U8 *)GetImage(btn->image));
    //在highlight的背景上，绘制对应的数字；
#ifdef __CALC_FTE_SLIM_USE_SLICE_RES__

//if(btn->input != CALC_PLUS && btn->input != CALC_MINUS && btn->input != CALC_MULT && btn->input != CALC_DIV && btn->input != CALC_EQUAL)
if(btn->input != CALC_EQUAL)
{
   if(btn->input != CALC_PLUS && btn->input != CALC_MINUS && btn->input != CALC_MULT && btn->input != CALC_DIV && btn->input != CALC_EQUAL)
   {
      font = MMI_large_font;
      font.size = CALC_FONT_SIZE;
   }
   else
   {
    #if defined(__MMI_MAINLCD_240X400__)
      //font = MMI_medium_font;
      //font.size = MEDIUM_FONT;
      font = MMI_small_font;
	  font.size = SMALL_FONT;
	#elif defined(__MMI_MAINLCD_320X480__)
	  if(btn->input == CALC_MINUS)
	  {
	     font = MMI_large_font;      //HVGA - 专门要用大字体；
	  	 font.size = CALC_FONT_SIZE; 
	  }
	  else
	  {
	  	font = MMI_medium_font;      //HVGA +  x / 要用中字体；
	  	font.size = MEDIUM_FONT; 
	  }
    #endif
   }

    switch(btn->input)
    {
       case CALC_1:
	   	 input_num[0] = '1';
		 break;

	   case CALC_2:
	   	 input_num[0] = '2';
		 break;

	   case CALC_3:
	   	 input_num[0] = '3';
		 break;

	   case CALC_4:
	   	 input_num[0] = '4';
		 break;

	   case CALC_5:
	   	 input_num[0] = '5';
		 break;

	   case CALC_6:
	   	 input_num[0] = '6';
		 break;

	   case CALC_7:
	   	 input_num[0] = '7';
		 break;

	   case CALC_8:
	   	 input_num[0] = '8';
		 break;

	   case CALC_9:
	   	 input_num[0] = '9';
		 break;

	   case CALC_0:
	   	 input_num[0] = '0';
		 break;

	   case CALC_00:
	   	 //input_double_num = "00";
		 input_num[0] = 0;
		 break;

	   case CALC_DOT:
	   	 input_num[0] = '.';
		 break;

	   case CALC_PLUS:
	   	 input_num[0] = '+';
		 break;

	   case CALC_MINUS:
	   	 input_num[0] = '-';
		 break; 

	   case CALC_MULT:
	   	 input_num[0] = 'x';
		 break; 

	   case CALC_DIV:
	   	 input_num[0] = '/';
		 break; 
    }
	
    gui_set_font(&font);
    {
        color c = CALC_FONT_COLOR;
        gui_set_text_color(c);
    }

	h = gui_get_character_height();

    if(input_num[0] == 0)
    {
	   //w = gui_get_string_width(input_double_num);
	   w = gui_get_character_width('0') * 2;
    }
	else
	{
	   w = gui_get_character_width((UI_character_type)input_num);
    }

         #if defined(__MMI_MAINLCD_240X400__)
                //针对240X400进行坐标的微调；
	 			//输出. 字符，坐标微调；
				if(input_num[0] == dot)
					calc_move_text_cursor(
					0,
					region->left + (region->width - w)*3/4, 
					region->top + (region->height -h)/2  ,
					0);
				//输出00字串，坐标微调；
				else if(input_num[0] == 0)	
					calc_move_text_cursor(
					0,
					region->left + (region->width - w)/2, 
					region->top + (region->height -h)*3/4 ,
					0);
				//输出+  -  字符，坐标微调；
				else if(input_num[0] == '+' || input_num[0] == '-')
					calc_move_text_cursor(
					0,
					region->left + (region->width - w)*11/16, 
					region->top + (region->height -h)*3/8 ,
					0);
				//输出X  /  字符，坐标微调；
				else if(input_num[0] == 'x' || input_num[0] == '/')
					calc_move_text_cursor(
					0,
					region->left + (region->width - w), 
					region->top + (region->height -h)*2/4 ,
					0);
				else 
				   calc_move_text_cursor(
					0,
					region->left + (region->width - w)*3/4, 
					region->top + (region->height -h)*3/4 ,
					0);
		 #elif defined(__MMI_MAINLCD_320X480__)
		   //针对320X480进行坐标的微调；
           //输出. 字符，坐标微调；
			 if(input_num[0] == dot)
				 calc_move_text_cursor(
				 0,
				 region->left + (region->width - w)*3/4, 
				 region->top + (region->height -h)*2  ,  //有调整；
				 0);
			//输出00字串，坐标微调；
			 else if(input_num[0] == 0)  
				 calc_move_text_cursor(
				 0,
				 region->left + (region->width - w)/2, 
				 region->top + (region->height -h)*3/4 ,
				 0);
			 //输出+  -  字符，坐标分别微调；
			 else if(input_num[0] == '+')
					calc_move_text_cursor(
					0,
					region->left + (region->width - w)*5/8 - 2, 
					region->top + (region->height -h)*7/8 +2 ,
					0);
			 else if(input_num[0] == '-')
					calc_move_text_cursor(
					0,
					region->left + (region->width - w)*3/4 + 2, 
					region->top + (region->height -h)*5/8 + 15,
					0);			 
			 //输出X  /  字符，坐标分别微调；
			 else if(input_num[0] == 'x')
				calc_move_text_cursor(
					0,
					region->left + (region->width - w)*1/2 + 2, 
					region->top + (region->height -h)*3/4 - 2,
					0);
			 else if(input_num[0] == '/')
				calc_move_text_cursor(
					0,
					region->left + (region->width - w)*1/2 + 5, 
					region->top + (region->height -h)*3/4 - 2,
					0);
			 else 
				calc_move_text_cursor(
				 0,
				 region->left + (region->width - w)*5/8,  //有调整；
				 region->top + (region->height -h)*3/4 ,
				 0);
		 #endif

    
	if(input_num[0]  == 0)
	{
	   mmi_asc_to_ucs2((char*)convert_to_ucs2 , input_double_num);
	   gui_print_text(convert_to_ucs2);
	}
	else
	{
	   mmi_asc_to_ucs2((char*)convert_to_ucs2 , input_num);
	   gui_print_text(convert_to_ucs2);
	}
}
    
  #endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
 #else
    //480*800还是保留原图；
    gdi_image_draw(region->left, region->top, (U8 *)GetImage(btn->image));
#endif
#endif/*__MMI_SLIM_IMG_RES__*/
    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_clip();

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        region->left, region->top,
        region->left + region->width - 1,
        region->top + region->height - 1);
}


static void calc_lowlight_btn(calc_button_struct *btn)
{
    calc_rect_struct *region;
	MMI_ID current_active_grp_id = GRP_ID_INVALID;
	MMI_ID current_active_scrn_id = SCR_ID_INVALID;

    mmi_frm_get_active_scrn_id(&current_active_grp_id ,&current_active_scrn_id);
	
    if (!btn || !(current_active_grp_id == GRP_ID_CALC && current_active_scrn_id == SCR_ID_CALC_APP)) return;

    region = &btn->region;

    gdi_layer_lock_frame_buffer();
    gdi_layer_push_and_set_clip(
        region->left, region->top,
        region->left + region->width - 1,
        region->top + region->height - 1);

    gdi_image_cache_bmp_draw(region->left, region->top, &g_calc_cntx->Cache);
    
    gdi_layer_pop_clip();

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        region->left, region->top,
        region->left + region->width - 1,
        region->top + region->height - 1);

    if (g_calc_cntx->Cache.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(g_calc_cntx->Cache.buf_ptr);
        g_calc_cntx->Cache.buf_ptr = NULL;
    }
    
    g_calc_cntx->CurrHilite = NULL;
}

static void calc_update_input(void)
{
    S32 x, y, width, height;
#ifdef __CALC_FTE_SLIM_USE_SLICE_RES__
    calc_button_struct *btn;
    S32 i;
	stFontAttribute font;
	S32 h,w;
    char input_num[2] = "\0";
	//calc_input_enum input_enum;
	char input_double_num[3] = "00\0";
    char dot = '.';
	WCHAR convert_to_ucs2[4];

	calc_rect_struct *region;
	
	memset((char*)convert_to_ucs2 , 0x00 ,sizeof(convert_to_ucs2));
 #endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
//#ifdef __CALC_96_64_SOLUTION_SLIM__
 #ifdef __MMI_MAINLCD_96X64__
	WCHAR *op = NULL;
    //S32 left, top , w = 0;
    calc_input_enum i = CALC_NUM_BEGIN;

    stFontAttribute font;

    font = MMI_large_font;
    //font.size = CALC_FONT_SIZE;
    font.size = MEDIUM_FONT;
	
    gui_set_font(&font);
    {
        color c = CALC_FONT_COLOR;
        gui_set_text_color(c);
    }
#endif/*__CALC_96_64_SOLUTION_SLIM__*/
    gdi_layer_lock_frame_buffer();
    
#if CALC_DRAW_BACKGROUND    

  //#ifndef __CALC_96_64_SOLUTION_SLIM__
  #ifndef __MMI_MAINLCD_96X64__
    x = CALC_BG_X;
    y = CALC_BG_Y;
  #else
    x = CALC_BG_X_FOR_96_64;  //0
    y = CALC_BG_Y_FOR_96_64;  //28
  #endif/*__CALC_96_64_SOLUTION_SLIM__*/
 
#else
    //96*64 Touch Panel Suport is OFF;
   //#ifndef __CALC_96_64_SOLUTION_SLIM__
   #ifndef __MMI_MAINLCD_96X64__
    x = CALC_KEYPAD_X;
    y = CALC_KEYPAD_Y;
   #else
    x = CALC_BG_X_FOR_96_64;  //0
    y = CALC_BG_Y_FOR_96_64;  //28
  #endif/*__CALC_96_64_SOLUTION_SLIM__*/
    
#endif

//#ifndef __CALC_96_64_SOLUTION_SLIM__
#ifndef __MMI_MAINLCD_96X64__
   #ifndef __CALC_FTE_SLIM_USE_SLICE_RES__
    gdi_image_get_dimension((U8 *)GetImage(IMG_ID_CALC_MAIN), &width, &height);
  #else
    gdi_image_get_dimension((U8 *)GetImage(IMG_ID_CALC_MAIN_COUNT), &width, &height);
   #endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
#else
    width = 96;
    height = 20 + 2;//由于softkey height调整；
  #endif/*__CALC_96_64_SOLUTION_SLIM__*/
   
#ifndef __CALC_FTE_SLIM_USE_SLICE_RES__
    //pluto slim;
    //gdi_layer_push_and_set_clip(x, y, x+width-1, y+height-1);
    //把整个计算器区域都要设置为剪切区域；
    gdi_layer_push_and_set_clip(0, CALC_BG_Y, UI_DEVICE_WIDTH-1, UI_DEVICE_HEIGHT-1);
#else
    //FTE 把整个计算器区域都要设置为剪切区域；
    gdi_layer_push_and_set_clip(x, y, x+UI_DEVICE_WIDTH-1, y+UI_DEVICE_HEIGHT-1);
#endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
  //#ifdef __CALC_96_64_SOLUTION_SLIM__
  #ifdef __MMI_MAINLCD_96X64__
    //gdi_layer_clear(GDI_COLOR_BLACK);//不能整个背景Layer刷黑，否则，背光灭再返回，显示全黑；
    gdi_draw_frame_rect(
        		x, y,
        		x + width -1,
        		y + height -1,
        		gdi_act_color_from_rgb(CALC_INPUT_BGCOLOR),
        		gdi_act_color_from_rgb(CALC_OUTPUT_BDCOLOR),
        		0);
  #endif
  //#ifndef __CALC_96_64_SOLUTION_SLIM__
  #ifndef __MMI_MAINLCD_96X64__
    #ifndef __CALC_FTE_SLIM_USE_SLICE_RES__
    //pluto slim;
    //首先绘制整个背景；
    gui_draw_filled_area(0, 0, 0+UI_DEVICE_WIDTH-1, 0+UI_DEVICE_HEIGHT-1,current_MMI_theme->sub_menu_bkg_filler);
    gdi_image_draw(x, y, (U8 *)GetImage(IMG_ID_CALC_MAIN));
   #else
	 //FTE 首先绘制整个背景；
	 gui_draw_filled_area(0, 0, 0+UI_DEVICE_WIDTH-1, 0+UI_DEVICE_HEIGHT-1,current_MMI_theme->sub_menu_bkg_filler);
	 
    //绘制加减乘除输入区域；
    #if defined(__MMI_MAINLCD_240X320__)
	 gdi_image_draw(147, 153, (U8 *)GetImage(IMG_ID_CALC_MAIN_COUNT));  //240*320  QVGA
	#elif defined(__MMI_MAINLCD_240X400__)
	 gdi_image_draw(147, 153 + 35, (U8 *)GetImage(IMG_ID_CALC_MAIN_COUNT)); //240*400  WQVGA
	#else //defined(__MMI_MAINLCD_320X480__)
	 gdi_image_draw(198, 226, (U8 *)GetImage(IMG_ID_CALC_MAIN_COUNT)); //320*480   HVGA
	#endif
	
    //绘制数字输入区域；
	 for(i = 0; i < 12; i++)
	 {
		 btn = &g_calc_input_nonhilight_layout[i];
		 region = &btn->region;
		 
		 /*gdi_image_draw_resized(
		 g_calc_input_nonhilight_layout[i].region.left, g_calc_input_nonhilight_layout[i].region.top,
		 g_calc_input_nonhilight_layout[i].region.width, g_calc_input_nonhilight_layout[i].region.height,
		 (U8 *)GetImage(g_calc_input_nonhilight_layout[i].image));*/
		 gdi_image_draw_resized(
		 region->left, region->top,
		 region->width, region->height,
		 (U8 *)GetImage(btn->image));
		 
	
		 if(btn->input != CALC_PLUS && btn->input != CALC_MINUS && btn->input != CALC_MULT && btn->input != CALC_DIV && btn->input != CALC_EQUAL)
		 {
			 font = MMI_large_font;
			 font.size = CALC_FONT_SIZE;
	
			 switch(btn->input)
			 {
				case CALC_1:
				  input_num[0] = '1';
				  break;
	
				case CALC_2:
				  input_num[0] = '2';
				  break;
	
				case CALC_3:
				  input_num[0] = '3';
				  break;
	
				case CALC_4:
				  input_num[0] = '4';
				  break;
	
				case CALC_5:
				  input_num[0] = '5';
				  break;
	
				case CALC_6:
				  input_num[0] = '6';
				  break;
	
				case CALC_7:
				  input_num[0] = '7';
				  break;
	
				case CALC_8:
				  input_num[0] = '8';
				  break;
	
				case CALC_9:
				  input_num[0] = '9';
				  break;
	
				case CALC_0:
				  input_num[0] = '0';
				  break;
	
				case CALC_00:
				  //input_double_num = "00";
				  input_num[0] = 0;
				  break;
	
				case CALC_DOT:
				  input_num[0] = '.';
				  break;
			 
			 }
			 
			 gui_set_font(&font);
			 {
				 color c = CALC_FONT_COLOR_INPUT;
				 gui_set_text_color(c);
			 }
	
			 h = gui_get_character_height();
	
			 if(input_num[0] == 0)
			 {
				//w = gui_get_string_width(input_double_num);
				w = gui_get_character_width('0') * 2;
			 }
			 else
			 {
				w = gui_get_character_width((UI_character_type)input_num);
			 }
	 #if defined(__MMI_MAINLCD_240X320__)||defined(__MMI_MAINLCD_240X400__)
            //输出. 字符，坐标微调；
			 if(input_num[0] == dot)
				 calc_move_text_cursor(
				 0,
				 region->left + (region->width - w)*3/4, 
				 region->top + (region->height -h)/2  ,
				 0);
			//输出00字串，坐标微调；
			 else if(input_num[0] == 0)  
				 calc_move_text_cursor(
				 0,
				 region->left + (region->width - w)/2, 
				 region->top + (region->height -h)*3/4 ,
				 0);
			 else 
				calc_move_text_cursor(
				 0,
				 region->left + (region->width - w)*3/4, 
				 region->top + (region->height -h)*3/4 ,
				 0);
	#elif defined(__MMI_MAINLCD_320X480__)
           //输出. 字符，坐标微调；
			 if(input_num[0] == dot)
				 calc_move_text_cursor(
				 0,
				 region->left + (region->width - w)*3/4, 
				 region->top + (region->height -h)*2  ,  //有调整；
				 0);
			//输出00字串，坐标微调；
			 else if(input_num[0] == 0)  
				 calc_move_text_cursor(
				 0,
				 region->left + (region->width - w)/2, 
				 region->top + (region->height -h)*3/4 ,
				 0);
			 else 
				calc_move_text_cursor(
				 0,
				 region->left + (region->width - w)*5/8,  //有调整；
				 region->top + (region->height -h)*3/4 ,
				 0);
	#endif  
			 
			 if(input_num[0]  == 0)
			 {
				mmi_asc_to_ucs2((char*)convert_to_ucs2 , input_double_num);
				gui_print_text(convert_to_ucs2);
			 }
			 else
			 {
				mmi_asc_to_ucs2((char*)convert_to_ucs2 , input_num);
				gui_print_text(convert_to_ucs2);
			 }
		 }
	 }
	 
#endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
  #else  
	 for(i = CALC_PLUS; i <= CALC_MULT ; i++)
	 {
	    op = calc_string_format(i);    
	    if (op)
	    {
	        calc_move_text_cursor(0 , g_calc_input_layout[i-3].region.left,g_calc_input_layout[i-3].region.top, 0);
	        gui_print_text(op);
	    }
	 }
  #endif/*__CALC_96_64_SOLUTION_SLIM__*/
    gdi_layer_pop_clip();


#if CALC_NAVI_HILIGHT
    {
        calc_button_struct *btn = g_calc_cntx->CurrHilite;

        if (btn)
        {
         //#ifndef __CALC_96_64_SOLUTION_SLIM__
		 #ifndef __MMI_MAINLCD_96X64__
            gdi_image_draw(btn->region.left, btn->region.top, (U8 *)GetImage(btn->image));
		 #else
            gdi_draw_frame_rect(
        		btn->region.left, btn->region.top,
        		btn->region.left + btn->region.width -1-2,
        		btn->region.top + btn->region.height -1-3,
        		gdi_act_color_from_rgb(CALC_HIGHLIGHT_BGCOLOR),
        		gdi_act_color_from_rgb(CALC_OUTPUT_BDCOLOR),
        		0);

			 {
			 color c2 = CALC_HIGHLIGHT_TEXT_COLOR;
             gui_set_text_color(c2);
			 }
			 
		        op = calc_string_format(btn->input);    
    			if (op)
    			{
        			calc_move_text_cursor(0 , btn->region.left, btn->region.top, 0);
        			gui_print_text(op);
     			}
		 #endif/*__CALC_96_64_SOLUTION_SLIM__*/
        }
    }
#endif
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x, y, x+width-1, y+height-1);
}


static void calc_move_text_cursor(BOOL r21flag, S32 x, S32 y, S32 offset)
{
    if (r21flag)
    {
        gui_move_text_cursor(x + offset, y);
    }
    else
    {
        gui_move_text_cursor(x, y);
    }	
    return;
}


static void calc_update_output(void)
{
    WCHAR *op = NULL, t_out[32];
//#ifndef __CALC_96_64_SOLUTION_SLIM__
#ifndef	__MMI_MAINLCD_96X64__
    calc_rect_struct out = g_calc_output_layout;
#else
    calc_rect_struct out = {0, 0, 96, 28};
#endif
    S32 w, h, x, y1, y2, h_margin, line_height;
    stFontAttribute font;

    font = MMI_large_font;
//#ifndef __CALC_96_64_SOLUTION_SLIM__
#ifndef	__MMI_MAINLCD_96X64__
    font.size = CALC_FONT_SIZE;
#else
    font.size = MEDIUM_FONT;
    
#endif/*__CALC_96_64_SOLUTION_SLIM__*/
    gui_set_font(&font);
    {
        color c = CALC_FONT_COLOR;
        gui_set_text_color(c);
    }

    gdi_layer_lock_frame_buffer();

//#ifndef __CALC_96_64_SOLUTION_SLIM__
#ifndef __MMI_MAINLCD_96X64__
#if CALC_DRAW_BACKGROUND
    gdi_layer_push_and_set_clip(
        out.left, out.top,
        out.left + out.width -1,
        out.top + out.height -1);
 #ifndef __CALC_FTE_SLIM_USE_SLICE_RES__
    gdi_image_draw(CALC_BG_X, CALC_BG_Y, (U8 *)GetImage(IMG_ID_CALC_MAIN));
 #else
    //FTE Slim绘制背景；
    gui_draw_filled_area(0, 0, 0+UI_DEVICE_WIDTH-1, 0+UI_DEVICE_HEIGHT-1,current_MMI_theme->sub_menu_bkg_filler);
 #endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
    gdi_layer_pop_clip();
#else
    gdi_layer_reset_clip();
    gdi_draw_frame_rect(
        out.left, out.top,
        out.left + out.width -1,
        out.top + out.height -1,
        gdi_act_color_from_rgb(CALC_OUTPUT_BGCOLOR),
        gdi_act_color_from_rgb(CALC_OUTPUT_BDCOLOR),
        CALC_BORDER_WIDTH);
#endif
#else
   gdi_layer_reset_clip();
    gdi_draw_frame_rect(
        out.left, out.top,
        out.left + out.width -1,
        out.top + out.height -1,
        gdi_act_color_from_rgb(CALC_OUTPUT_BGCOLOR),
        gdi_act_color_from_rgb(CALC_OUTPUT_BDCOLOR),
        CALC_BORDER_WIDTH);
#endif/*__CALC_96_64_SOLUTION_SLIM__*/

    out.left += CALC_BORDER_WIDTH;
    out.top += CALC_BORDER_WIDTH + 1;
    out.width -= 2*CALC_BORDER_WIDTH;
    out.height -= 2*CALC_BORDER_WIDTH;

    h_margin = out.width * 2 /100;
    
    h = gui_get_character_height();
    line_height = out.height / CALC_OUTPUT_LINES;
    y1 = out.top + (line_height*(CALC_OUTPUT_LINES-2)) + (line_height-h);
    y2 = out.top + (line_height*(CALC_OUTPUT_LINES-1)) + (line_height-h);

//#ifndef __CALC_96_64_SOLUTION_SLIM__
#ifndef __MMI_MAINLCD_96X64__
#if CALC_MEM_SUPPORT
    #if !CALC_DRAW_BACKGROUND
    w = gui_get_character_width(L'[');
    calc_move_text_cursor(
        mmi_fe_get_r2l_state(),
        out.left + h_margin -1, 
        out.top + (line_height-h)+1,
        w);
    gui_print_text(L"[");
    #endif
    calc_ftoa(g_calc_cntx->MemValue, t_out);
        
    #if !CALC_DRAW_BACKGROUND
        mmi_wcscat(t_out, L"]"); /* for touch, no "]" in memory area */
    #endif        
    w = gui_get_string_width(t_out);
    calc_move_text_cursor(
        mmi_fe_get_r2l_state(),
        out.left + out.width - h_margin - w - 1, 
        out.top + (line_height-h)+1,
        w);
    gui_print_text(t_out);
#endif
#endif

    // Line oprand2, only available in specific case
    if (g_calc_cntx->State == CALC_STATE_OPERAND2)
    {
        calc_ftoa(g_calc_cntx->Operand1, t_out);
        
        w = gui_get_string_width(t_out);
        x = out.left + out.width - h_margin - w - 1, 
		//操作数1的位置适当上移；
	 //#ifdef __CALC_96_64_SOLUTION_SLIM__
	 #ifdef __MMI_MAINLCD_96X64__
		y1 -= 3;
	 #endif
		calc_move_text_cursor(mmi_fe_get_r2l_state(), x, y1, w);

        gui_print_text(t_out);
    }

    // Line oprand1, always available
    w = gui_get_string_width(g_calc_cntx->InputBuff);

    x = out.left + out.width - h_margin - w - 1, 
    //操作数2的位置适当上移；
  //#ifdef __CALC_96_64_SOLUTION_SLIM__
  #ifdef __MMI_MAINLCD_96X64__
	y2 -= 2;
  #endif
  
   //FTE Slim 操作数2的位置适当上移；
 #ifdef __CALC_FTE_SLIM_USE_SLICE_RES__
	y2 -= line_height/4;
 #endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
	calc_move_text_cursor(mmi_fe_get_r2l_state(), x, y2, w);

    gui_print_text(g_calc_cntx->InputBuff);

    // Operator indicator, only available in specific case
    if (CALC_STATE_EQUAL == g_calc_cntx->State) 
    {
        op = calc_string_format(CALC_EQUAL);
    }
    else if (CALC_STATE_EXCEPTION == g_calc_cntx->State)
    {
        op = L"E";
    }
    else if (CALC_STATE_OPERAND2 == g_calc_cntx->State)
    {
        op = calc_string_format(g_calc_cntx->Operator);
    }
    
    if (op)
    {
        S32 h_op, h_num;
        w = gui_get_string_width(op);
        x = out.left + h_margin -1;
        gui_measure_character(op[0], &w, &h_op);
        gui_measure_character(L'0', &w, &h_num);
        y2 += (h_num-h_op)/2;
        calc_move_text_cursor(mmi_fe_get_r2l_state(), x, y2, w);
        gui_print_text(op);
    }

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(	
        out.left, out.top,
        out.left + out.width -1,
        out.top + out.height -1);
}

static void calc_update_softkey(void)
{
    gdi_layer_lock_frame_buffer();

    gdi_layer_push_and_set_clip(0, 0, UI_DEVICE_WIDTH-1, UI_DEVICE_HEIGHT-MMI_SOFTKEY_BAR_HEIGHT-1);
    
    show_softkey_background();

#if CALC_LSK_CLEAR
    ChangeLeftSoftkey(STR_GLOBAL_CLEAR, IMG_GLOBAL_CLEAR);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#else
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
  #ifndef __CALC_SLIM_FOR_61__
    if (g_calc_cntx->State > CALC_STATE_OPERAND1 || calc_number_inputed())
  #else
    if (g_calc_cntx->State > CALC_STATE_OPERAND1 || g_calc_cntx->ValidInput)
  #endif/*__CALC_SLIM_FOR_61__*/
        ChangeRightSoftkey(STR_GLOBAL_CLEAR, IMG_GLOBAL_BACK);
    else
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#endif

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    show_left_softkey();
    show_right_softkey();
    show_softkey(MMI_CENTER_SOFTKEY);

    gdi_layer_pop_clip();

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH-1, UI_DEVICE_HEIGHT-MMI_SOFTKEY_BAR_HEIGHT-1);
}

static void calc_update(void)
{
    gdi_layer_lock_frame_buffer();
    gdi_layer_reset_clip();

#if CALC_DRAW_BACKGROUND
    gdi_layer_push_and_set_clip(0, 0, UI_DEVICE_WIDTH-1, UI_DEVICE_HEIGHT-1);
    gdi_layer_pop_clip();
    
    gdi_layer_set_active(calculator_touch_top_layer);
#else
    clear_screen();
#endif

#if CALC_SHOW_STATUS_ICON
    show_title_status_icon();
#endif

#if CALC_DRAW_TITLE
    wgui_title_change(GetRootTitleIcon(EXTRA_CALCULATOR_MENU), 0, (PU8)GetString(STR_ID_CALC_MENU), WGUI_TITLE_CHANGE_ICON | WGUI_TITLE_CHANGE_TEXT);
    wgui_title_show(GUI_TITLE_PART_ALL);
#endif

    calc_update_input();
    calc_update_output();
    calc_update_softkey();    

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH-1, UI_DEVICE_HEIGHT-1);
}

#if CALC_NAVI_HILIGHT
static calc_button_struct *calc_get_button(U16 input)
{
    S32 i;

    if (!input) return NULL;
    
    for (i = 0; i < sizeof(g_calc_input_layout)/sizeof(calc_button_struct); i++)
    {
        if (g_calc_input_layout[i].input == input)
            return (calc_button_struct *)&g_calc_input_layout[i];
    }

    return NULL;
}
#endif

static calc_button_struct *calc_get_button_by_shortcut(U8 shortcut)
{
    S32 i;

    for (i = 0; i < sizeof(g_calc_input_layout)/sizeof(calc_button_struct); i++)
    {
        if (g_calc_input_layout[i].shortcut == shortcut)
            return (calc_button_struct *)&g_calc_input_layout[i];
    }

    return NULL;
}

#ifdef __MMI_TOUCH_SCREEN__
static calc_button_struct *calc_get_button_by_pt(mmi_pen_point_struct *pt)
{
    S32 i;

    for (i = 0; i < sizeof(g_calc_input_layout)/sizeof(calc_button_struct); i++)
    {
        const calc_rect_struct *region = &g_calc_input_layout[i].region;
        if ((pt->x > region->left && pt->x < region->left+region->width) &&
            (pt->y > region->top && pt->y < region->top+region->height))
            return (calc_button_struct *)&g_calc_input_layout[i];
    }

    return NULL;
}
#endif

#ifdef __MMI_AP_DCM_CALC__
#pragma arm section rodata,code
#endif
#endif /* __MMI_CALCULATOR__ */ 


