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
 * FactoryModeSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is Factory Mode NxM point test
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
 ******************************************************************************/
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

#if defined(__MMI_TOUCH_SCREEN__)


/*****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "ps_public_struct.h"
#include "stack_config.h"
#include "mmi_frm_input_gprot.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "GpioSrvGprot.h"
#include "gpiosrvgprot.h"
#include "Unicodexdcl.h"
#include "stdio.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"

#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_util.h"
#include "kal_public_api.h"
#include "mmi_frm_history_gprot.h"
#include "CustMenuRes.h"
#include "GlobalMenuItems.h"
#include "wgui_categories_list.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "string.h"
#include "mmi_frm_nvram_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "nvram_defs.h"
#include "gui.h"
#include "FontRes.h"
#include "gdi_include.h"
#include "wgui_categories.h"
#include "custom_mmi_default_value.h"
#include "wgui.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_msg_struct.h"
#include "AlarmFrameworkProt.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "wgui_touch_screen.h"
#include "gui_config.h"
#include "SensorSrvGport.h"

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "PixcomFontEngine.h"

#include "resource_audio.h"
#include "IdleAppDef.h"
//#include "FactoryModeDef.h"

#include "EngineerModeUtil.h"
#include "EngineerModeGprot.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_audio.h"
#include "CommonScreens.h"
#include "fmt_struct.h"

#include "mmi_rp_srv_gpio_def.h"
#include "wgui_categories.h"

#include "dcl.h"

#include "init.h"
#include "device.h"
#include "custom_em.h"

#include "custom_equipment.h"
//#include "custom_hw_default.h"
#include "nvram_data_items.h"
#include "nvram_interface.h"
#include "lcd_sw_inc.h"
#include "resource_verno.h"

#ifdef __MTK_TARGET__
#include "l1audio.h"
#else 
#define L1SP_Tones kal_uint16
#endif 

#include "datetimetype.h"
#include "app_datetime.h"

#include "adc_channel.h"
#include "ShutdownSrvGprot.h"

#include "mmi_rp_app_factorymode_def.h"
#include "MenuCuiGprot.h"
#include "FactoryModeGProt.h"


#ifdef __GADGET_SUPPORT__
#include "WgtMgrSrvGprot.h"
#endif

#include "FactoryModeConfig.h"
#include "FactoryModeProt.h"


/***************************************************************************** 
* Define
*****************************************************************************/


/***************************************************************************** 
* typedef enum/struct/...
*****************************************************************************/


/***************************************************************************** 
* global val / function
*****************************************************************************/
extern MMI_ID g_fm_gourp_id;

extern mmi_fm_item_cntxt_struct *g_fm_contxt;

extern testlet Tests[MAX_AUTO_TEST_ITEMS];


/***************************************************************************** 
* static  function
*****************************************************************************/
static void mmi_fm_n_by_m_test_init_status(void);
static BOOL mmi_fm_n_by_m_pen_test_status(void);
static void mmi_fm_n_by_m_test_display(void);
static void mmi_fm_n_by_m_test_translate_pen_position(mmi_pen_point_struct pos, S32 *row, S32 *col);
static void mmi_fm_n_by_m_test_pen_down(mmi_pen_point_struct pos);
static void mmi_fm_end_pen_n_cross_test(void);


/***************************************************************************** 
* Code body
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_n_by_m_test_init_status
 * DESCRIPTION
 *  This function initializes image status array of the points
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_n_by_m_test_init_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (x = 0; x < TOUCH_N_ROWS; x++)
    {
        for (y = 0; y < TOUCH_N_COLS; y++)
        {
            g_fm_contxt->parallelline_NxMpoint_contxt.gFMPenNByMStatus[x][y] = IMAGE_SHOW;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_n_by_m_pen_test_status
 * DESCRIPTION
 *  This function checks image status array of the points to see if all the images
 *  have been clicked
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_fm_n_by_m_pen_test_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (x = 0; x < TOUCH_N_ROWS; x++)
    {
        for (y = 0; y < TOUCH_N_COLS; y++)
        {
            if (IMAGE_SHOW == g_fm_contxt->parallelline_NxMpoint_contxt.gFMPenNByMStatus[x][y])
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_n_by_m_test_display
 * DESCRIPTION
 *  This function displays point images according to image status array of the points
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_n_by_m_test_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 r, c, x, y;

    mmi_fm_parallelline_NxMpoint_struct *parallelline_NxMpoint_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parallelline_NxMpoint_cntx = &(g_fm_contxt->parallelline_NxMpoint_contxt);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_push_clip();
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    clear_screen();
    for (r = 0; r < TOUCH_N_ROWS; r++)
    {
        for (c = 0; c < TOUCH_N_COLS; c++)
        {
            if (IMAGE_SHOW == parallelline_NxMpoint_cntx->gFMPenNByMStatus[r][c])
            {
                x = parallelline_NxMpoint_cntx->gFMPenNByMStartx
                     + c * (parallelline_NxMpoint_cntx->gFMPenNByMImageWidth + TOUCH_COL_MARGIN);
                y = parallelline_NxMpoint_cntx->gFMPenNByMStarty + r * (parallelline_NxMpoint_cntx->gFMPenNByMImageHeight + TOUCH_ROW_MARGIN);
                gui_show_image(x, y, wgui_get_list_menu_icon(c, (MMI_ID_TYPE)(IMG_GLOBAL_L1 + c)));               
            }
        }
    }
    gui_pop_clip();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width, UI_device_height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_n_by_m_test_translate_pen_position
 * DESCRIPTION
 *  This function translates pen position on N Cross M points test screen
 * PARAMETERS
 *  pos     [IN]        
 *  row     [?]         
 *  col     [?]         
 *  mmi_pen_point_struct(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_n_by_m_test_translate_pen_position(mmi_pen_point_struct pos, S32 *row, S32 *col)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 end_x, end_y, x, y, r, c, x1, y1, image_height, image_width, start_x, start_y;
    mmi_fm_parallelline_NxMpoint_struct *parallelline_NxMpoint_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parallelline_NxMpoint_cntx = &(g_fm_contxt->parallelline_NxMpoint_contxt);
    x = pos.x;
    y = pos.y;
    *row = -1;
    *col = -1;
    start_x = parallelline_NxMpoint_cntx->gFMPenNByMStartx;
    start_y = parallelline_NxMpoint_cntx->gFMPenNByMStarty;
    image_height = parallelline_NxMpoint_cntx->gFMPenNByMImageHeight;
    image_width = parallelline_NxMpoint_cntx->gFMPenNByMImageWidth;
    end_x = start_x + TOUCH_N_COLS * image_width + (TOUCH_N_COLS - 1) * TOUCH_COL_MARGIN;
    end_y = start_y + TOUCH_N_ROWS * image_height + (TOUCH_N_ROWS - 1) * TOUCH_ROW_MARGIN;

    if (PEN_CHECK_BOUND(x, y, start_x, start_y, end_x, end_y))
    {
        for (y1 = start_y, r = 0; y1 < end_y; y1 += image_height + TOUCH_ROW_MARGIN, r++)
        {
            if (y > y1 && y < y1 + image_height)
            {
                *row = r;
            }
        }
        for (x1 = start_x, c = 0; x1 < end_x; x1 += image_width + TOUCH_COL_MARGIN, c++)
        {
            if (x > x1 && x < x1 + image_width)
            {
                *col = c;
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_n_by_m_test_pen_down
 * DESCRIPTION
 *  This function handles Pen Down Events on N Cross M Points screen
 * PARAMETERS
 *  pos     [IN]        
 *  mmi_pen_point_struct(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_n_by_m_test_pen_down(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fm_n_by_m_test_translate_pen_position(pos, &x, &y);

    if (-1 != x && -1 != y)
    {
        g_fm_contxt->parallelline_NxMpoint_contxt.gFMPenNByMStatus[x][y] = IMAGE_HIDE;
    }
    if (mmi_fm_n_by_m_pen_test_status())
    {
        if (0 == g_fm_contxt->common_contxt.autoTestMode)
        {
            if (!mmi_frm_scrn_enter
                    (g_fm_gourp_id, 
                     SCR_ID_FM_N_CROSS_M_PEN, 
                     NULL,
                     NULL, 
                     MMI_FRM_FULL_SCRN))
            {
                return;
            }
            
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, 1000, 0);
        }
        else
        {  		
		    if (!mmi_frm_scrn_enter
		            (g_fm_gourp_id, 
		             SCR_ID_FM_AUTO_TEST_START,//SCR_ID_FM_N_CROSS_M_PEN, 
		             NULL,
    		         (FuncPtr)mmi_fm_n_by_m_test_pen_down, 
		             MMI_FRM_FULL_SCRN))
            {      
		        return;
            }

            wgui_register_general_pen_handler(); 
            FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_N_CROSS_M_POINTS].name);
            
            ShowCategory7Screen(
                STR_ID_FM_AUTO_TEST_ROOT,
                NULL,
                STR_ID_FM_AUTO_TEST_PASS,
                IMG_GLOBAL_OK,
                STR_ID_FM_AUTO_TEST_FAIL,
                IMG_GLOBAL_BACK,
                (PU8) g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf,
                NULL); 
 
            FM_Autotest_set_key_handlers(1); 
        }
    }
    else
    {
        mmi_fm_n_by_m_test_display();
    }
}

/*****************************************************************************
 * FUNCTION
 *  FM_AutoTest_Pen_N_Cross_M_Test
 * DESCRIPTION
 *  This function sets is for N Cross M point test in Auto Test Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void FM_AutoTest_Pen_N_Cross_M_Test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_contxt->common_contxt.currentTest = FM_TEST_PEN_N_CROSS_M_POINTS;

	mmi_frm_scrn_close(g_fm_gourp_id,SCR_ID_FM_N_CROSS_M_PEN);

	mmi_frm_scrn_close(g_fm_gourp_id,SCR_ID_FM_AUTO_TEST_START);
	
    mmi_fm_select_pen_n_cross_test();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_end_pen_n_cross_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_end_pen_n_cross_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_fm_contxt->common_contxt.autoTestMode == 0)  /*Not auto test */
    {
         if (!mmi_frm_scrn_enter
          (g_fm_gourp_id, 
            GLOBAL_SCR_DUMMY, 
            NULL,
            NULL, 
            MMI_FRM_FULL_SCRN))
            return;
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        /* Auto test */        
         mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);//SCR_ID_FM_N_CROSS_M_PEN);
                            if (!mmi_frm_scrn_enter
                            (g_fm_gourp_id, 
         SCR_ID_FM_AUTO_TEST_START,//SCR_ID_FM_N_CROSS_M_PEN, 
                             NULL,
                             NULL, 
                             MMI_FRM_FULL_SCRN))
                             return;
        FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_N_CROSS_M_POINTS].name);
        ShowCategory7Screen(
            STR_ID_FM_AUTO_TEST_ROOT,
            NULL,
            STR_ID_FM_AUTO_TEST_PASS,
            IMG_GLOBAL_OK,
            STR_ID_FM_AUTO_TEST_FAIL,
            IMG_GLOBAL_BACK,
            (PU8) g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf,
            NULL);
        FM_Autotest_set_key_handlers(1);       
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_select_pen_n_cross_test
 * DESCRIPTION
 *  This function is Entry Function of N Cross M Points screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_pen_n_cross_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_fm_parallelline_NxMpoint_struct *parallelline_NxMpoint_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // EntryNewScreen(SCR_ID_FM_N_CROSS_M_PEN, NULL, NULL, NULL);
   parallelline_NxMpoint_cntx = &(g_fm_contxt->parallelline_NxMpoint_contxt);

   if (g_fm_contxt->common_contxt.autoTestMode == 0)  /*Not auto test */
   {
		  if (mmi_frm_scrn_enter
			   (g_fm_gourp_id, 
				   SCR_ID_FM_N_CROSS_M_PEN, 
				   NULL,
				   NULL, 
				   MMI_FRM_FULL_SCRN) != MMI_TRUE)
		   return;
   }
   else
   {
   if (mmi_frm_scrn_enter
      (g_fm_gourp_id, 
		   SCR_ID_FM_AUTO_TEST_START, 
      NULL,
      mmi_fm_select_pen_n_cross_test, 
      MMI_FRM_FULL_SCRN) != MMI_TRUE)
      return;
   }

    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);
    
    gui_measure_image(wgui_get_list_menu_icon(0, IMG_GLOBAL_L1), &(parallelline_NxMpoint_cntx->gFMPenNByMImageWidth), &(parallelline_NxMpoint_cntx->gFMPenNByMImageHeight));
   
    parallelline_NxMpoint_cntx->gFMPenNByMStartx =
        (UI_device_width - ((TOUCH_N_COLS * parallelline_NxMpoint_cntx->gFMPenNByMImageWidth) + (TOUCH_N_COLS - 1) * TOUCH_COL_MARGIN)) / 2;
    parallelline_NxMpoint_cntx->gFMPenNByMStarty =
        (UI_device_height - ((TOUCH_N_ROWS * parallelline_NxMpoint_cntx->gFMPenNByMImageHeight) + (TOUCH_N_ROWS - 1) * TOUCH_ROW_MARGIN)) / 2;

    ASSERT(parallelline_NxMpoint_cntx->gFMPenNByMStartx >= 0 && parallelline_NxMpoint_cntx->gFMPenNByMStartx <= UI_device_width);
    ASSERT(parallelline_NxMpoint_cntx->gFMPenNByMStarty >= 0 && parallelline_NxMpoint_cntx->gFMPenNByMStarty <= UI_device_height);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fm_end_pen_n_cross_test, KEY_END, KEY_EVENT_LONG_PRESS);
    mmi_fm_n_by_m_test_init_status();
    entry_full_screen();
    mmi_fm_n_by_m_test_display();

    wgui_restore_list_menu_slim_style();
     
    wgui_register_pen_up_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_down_handler(mmi_fm_n_by_m_test_pen_down);
    wgui_register_pen_move_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_repeat_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_long_tap_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_abort_handler(mmi_pen_dummy_hdlr);
}

#endif /* __MMI_TOUCH_SCREEN__ */

#endif /*__MMI_FACTORY_MODE__*/

#if (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__))
#pragma arm section rodata , code
#endif /* (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)) */
