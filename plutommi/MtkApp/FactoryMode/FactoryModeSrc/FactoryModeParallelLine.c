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
 * FactoryModeParallelline.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is Factory Mode Parallelline test
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
static void mmi_fm_end_pen_parallel_test(void);
static void mmi_fm_pen_parallel_test_pen_down(mmi_pen_point_struct pos);
static void mmi_fm_pen_parallel_test_pen_move(mmi_pen_point_struct pos);
static void mmi_fm_pen_parallel_test_pen_up(mmi_pen_point_struct pos);
static void mmi_fm_set_g_pen_parallel(
        S16 first_x1,
        S16 first_y1,
        S16 first_x2,
        S16 first_y2,
        S16 second_x1,
        S16 second_y1,
        S16 second_x2,
        S16 second_y2,
        S16 first_point_x,    
        S16 first_point_y,    
        S16 second_point_x,   
        S16 second_point_y   
);
static void mmi_fm_pen_parallel_test_setup_coordinates(void);
static void mmi_fm_pen_parallel_test_display(void);

static void mmi_fm_end_pen_parallel_test(void);



/***************************************************************************** 
* Code body
*****************************************************************************/
static const S16 gFMPenPointOffset = 10;	/* Offset around start and end point */


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_pen_parallel_test_pen_down
 * DESCRIPTION
 *  This function handles pen down events on Parallel Lines Test screen
 * PARAMETERS
 *  pos     [IN]        
 *  mmi_pen_point_struct(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_pen_parallel_test_pen_down(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL inside_region = FALSE;
    long x, y;
    mmi_fm_parallelline_NxMpoint_struct *parallelline_NxMpoint_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parallelline_NxMpoint_cntx = &(g_fm_contxt->parallelline_NxMpoint_contxt);
    
    x = (pos.x - parallelline_NxMpoint_cntx->gFMPenParallel_first_point_x)
          * (pos.x - parallelline_NxMpoint_cntx->gFMPenParallel_first_point_x);
    y = (pos.y - parallelline_NxMpoint_cntx->gFMPenParallel_first_point_y) 
          * (pos.y - parallelline_NxMpoint_cntx->gFMPenParallel_first_point_y);

    if ((x + y) <= (gFMPenPointOffset* gFMPenPointOffset))
    {
        /* Starting from Top */
        inside_region = TRUE;
        parallelline_NxMpoint_cntx->gFM_pen_test_start_from_top = TRUE; 
        //gFM_pen_test_start_from_top = TRUE;
    }
    else
    {
        x = (pos.x - parallelline_NxMpoint_cntx->gFMPenParallel_second_point_x)
            * (pos.x - parallelline_NxMpoint_cntx->gFMPenParallel_second_point_x);
        y = (pos.y - parallelline_NxMpoint_cntx->gFMPenParallel_second_point_y) 
            * (pos.y - parallelline_NxMpoint_cntx->gFMPenParallel_second_point_y);

        if ((x + y) <= (gFMPenPointOffset * gFMPenPointOffset))
        {
            /* Starting from Bottom */
            inside_region = TRUE;
            parallelline_NxMpoint_cntx->gFM_pen_test_start_from_top = FALSE;
        }
    }
    if (inside_region)
    {
        parallelline_NxMpoint_cntx->gFMPenPreviousPoint.x = pos.x;
        parallelline_NxMpoint_cntx->gFMPenPreviousPoint.y = pos.y;
        parallelline_NxMpoint_cntx->gFMPenTestCapture = MMI_TRUE;
        parallelline_NxMpoint_cntx->gFMPenLineColor = gui_color(0, 150, 0);
    }
    else
    {
        parallelline_NxMpoint_cntx->gFMPenPreviousPoint.x = -1;
        parallelline_NxMpoint_cntx->gFMPenPreviousPoint.y = -1;
        wgui_general_pen_down_hdlr(pos);
        parallelline_NxMpoint_cntx->gFMPenTestCapture = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_pen_parallel_test_pen_move
 * DESCRIPTION
 *  This function handles pen move events on Parallel Lines Test screen
 * PARAMETERS
 *  pos     [IN]        
 *  mmi_pen_point_struct(?)
 * RETURNS
 *  void
 * REMARKS
 *  If pen is moved outside parallel lines test fails
 *****************************************************************************/
static void mmi_fm_pen_parallel_test_pen_move(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float first_x1 ;
    float first_x2 ;
    float first_y1 ;
    float first_y2 ;
    float second_x1 ;
    float second_x2 ;
    float second_y1 ;
    float second_y2 ;
    BOOL inside_region = FALSE;
    float xdiff1, xdiff2, test1, test2;

    mmi_fm_parallelline_NxMpoint_struct *parallelline_NxMpoint_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parallelline_NxMpoint_cntx = &(g_fm_contxt->parallelline_NxMpoint_contxt);

    
   first_x1 = parallelline_NxMpoint_cntx->gFMPenParallel_first_x1;
   first_x2 = parallelline_NxMpoint_cntx->gFMPenParallel_first_x2;
   first_y1 = parallelline_NxMpoint_cntx->gFMPenParallel_first_y1;
   first_y2 = parallelline_NxMpoint_cntx->gFMPenParallel_first_y2;
   second_x1 = parallelline_NxMpoint_cntx->gFMPenParallel_second_x1;
   second_x2 = parallelline_NxMpoint_cntx->gFMPenParallel_second_x2;
   second_y1 = parallelline_NxMpoint_cntx->gFMPenParallel_second_y1;
   second_y2 = parallelline_NxMpoint_cntx->gFMPenParallel_second_y2;
    
    if (!parallelline_NxMpoint_cntx->gFMPenTestCapture)
    {
        wgui_general_pen_move_hdlr(pos);
        return;
    }

    xdiff1 = (first_x2 - first_x1);
    xdiff2 = (second_x2 - second_x1);

    if (0 == xdiff1 || 0 == xdiff2)
    {
        ASSERT(0);
        return;
    }

    test1 = pos.y - first_y1 - ((first_y2 - first_y1) * (pos.x - first_x1)) / (xdiff1);
    test2 = pos.y - second_y1 - ((second_y2 - second_y1) * (pos.x - second_x1)) / (xdiff2);

    switch (parallelline_NxMpoint_cntx->gFMPenParallel_test_type)
    {
        case PARALLEL_TEST_1:
        {
            if ((test1 < 0) && (test2 > 0))
            {
                inside_region = TRUE;
            }
        }
            break;
        case PARALLEL_TEST_2:
        {
            if ((test1 > 0) && (test2 < 0))
            {
                inside_region = TRUE;
            }
        }
            break;
        default:
            ASSERT(0);
            return;
    }
    if (inside_region)
    {
        gui_lock_double_buffer();
        gui_push_clip();
        gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
        gui_line(parallelline_NxMpoint_cntx->gFMPenPreviousPoint.x, parallelline_NxMpoint_cntx->gFMPenPreviousPoint.y, pos.x, pos.y, parallelline_NxMpoint_cntx->gFMPenLineColor);
        gui_pop_clip();
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            PEN_MIN(parallelline_NxMpoint_cntx->gFMPenPreviousPoint.x, pos.x),
            PEN_MIN(parallelline_NxMpoint_cntx->gFMPenPreviousPoint.y, pos.y),
            PEN_MAX(parallelline_NxMpoint_cntx->gFMPenPreviousPoint.x, pos.x),
            PEN_MAX(parallelline_NxMpoint_cntx->gFMPenPreviousPoint.y, pos.y));
        parallelline_NxMpoint_cntx->gFMPenPreviousPoint.x = pos.x;
        parallelline_NxMpoint_cntx->gFMPenPreviousPoint.y = pos.y;
    }
    else
    {
        parallelline_NxMpoint_cntx->gFMPenPreviousPoint.x = -1;
        parallelline_NxMpoint_cntx->gFMPenPreviousPoint.y = -1;
        wgui_general_pen_move_hdlr(pos);
        parallelline_NxMpoint_cntx->gFMPenTestCapture = MMI_FALSE;
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, 1000, 0);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_pen_parallel_test_pen_up
 * DESCRIPTION
 *  This function handles pen UP event on Parallel Lines Test screen
 * PARAMETERS
 *  pos     [IN]        
 *  mmi_pen_point_struct(?)
 * RETURNS
 *  void
 * REMARKS
 *  When pen is UP is should be with in a predefined area (calculated by gFMPenPointOffset)
 *  of the end point of the test
 *****************************************************************************/
static void mmi_fm_pen_parallel_test_pen_up(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_parallelline_NxMpoint_struct *parallelline_NxMpoint_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parallelline_NxMpoint_cntx = &(g_fm_contxt->parallelline_NxMpoint_contxt);
    
    if (!parallelline_NxMpoint_cntx->gFMPenTestCapture)
    {
        wgui_general_pen_up_hdlr(pos);
    }
    else
    {
        long x, y;
        S16 result = 0;

        if (parallelline_NxMpoint_cntx->gFM_pen_test_start_from_top)
        {
            x = (pos.x - parallelline_NxMpoint_cntx->gFMPenParallel_second_point_x) * (pos.x - g_fm_contxt->parallelline_NxMpoint_contxt.gFMPenParallel_second_point_x);
            y = (pos.y - parallelline_NxMpoint_cntx->gFMPenParallel_second_point_y) * (pos.y - g_fm_contxt->parallelline_NxMpoint_contxt.gFMPenParallel_second_point_y);
            if ((x + y) < (gFMPenPointOffset * gFMPenPointOffset))
            {
                result = 1;
            }
        }
        else
        {
            x = (pos.x - parallelline_NxMpoint_cntx->gFMPenParallel_first_point_x) * (pos.x - g_fm_contxt->parallelline_NxMpoint_contxt.gFMPenParallel_first_point_x);
            y = (pos.y - parallelline_NxMpoint_cntx->gFMPenParallel_first_point_y) * (pos.y - g_fm_contxt->parallelline_NxMpoint_contxt.gFMPenParallel_first_point_y);
            if ((x + y) < (gFMPenPointOffset * gFMPenPointOffset))
            {
                result = 1;
            }
        }

        if (result)
        {
            if (PARALLEL_TEST_1 == parallelline_NxMpoint_cntx->gFMPenParallel_test_type)
            {
                DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, 1000, 0);
                parallelline_NxMpoint_cntx->gFMPenParallel_test_type = PARALLEL_TEST_2;
            }
            else if (PARALLEL_TEST_2 == parallelline_NxMpoint_cntx->gFMPenParallel_test_type)
            {
                parallelline_NxMpoint_cntx->addtohistory = FALSE;
               // EntryNewScreen(SCR_ID_FM_PARALLEL_PEN, NULL, NULL, NULL);
               /*
                    mmi_frm_scrn_enter
                      (g_fm_gourp_id, 
                      SCR_ID_FM_PARALLEL_PEN, 
                      NULL,
                      NULL, 
                      MMI_FRM_FULL_SCRN);
                */
                
                
                if (g_fm_contxt->common_contxt.autoTestMode == 0)
                {
                    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, 1000, 0);
                    mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_PARALLEL_PEN);
                    parallelline_NxMpoint_cntx->gFMPenParallel_test_type = PARALLEL_TEST_1;
                }
                else
                {
                		mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_PARALLEL_PEN);
										mmi_frm_scrn_enter
										(g_fm_gourp_id, 
										 SCR_ID_FM_PARALLEL_PEN, 
										 NULL,
										 NULL, 
										 MMI_FRM_FULL_SCRN);
                    FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_PARALLEL_LINE].name);
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
                    parallelline_NxMpoint_cntx->gFMPenParallel_test_type = PARALLEL_TEST_1;
                }
            }
        }
        else
        {
            parallelline_NxMpoint_cntx->gFMPenPreviousPoint.x = -1;
            parallelline_NxMpoint_cntx->gFMPenPreviousPoint.y = -1;
            parallelline_NxMpoint_cntx->gFMPenTestCapture = MMI_FALSE;
            parallelline_NxMpoint_cntx->gFMPenLineColor = gui_color(0, 0, 0);
            wgui_general_pen_up_hdlr(pos);
            DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, 1000, 0);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_set_g_pen_parallel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *
 *****************************************************************************/
static void mmi_fm_set_g_pen_parallel(
        S16 first_x1,
        S16 first_y1,
        S16 first_x2,
        S16 first_y2,
        S16 second_x1,
        S16 second_y1,
        S16 second_x2,
        S16 second_y2,
        S16 first_point_x,    
        S16 first_point_y,    
        S16 second_point_x,   
        S16 second_point_y   
)
{

    mmi_fm_parallelline_NxMpoint_struct *parallelline_NxMpoint_cntx;
    parallelline_NxMpoint_cntx = &(g_fm_contxt->parallelline_NxMpoint_contxt);
    
    parallelline_NxMpoint_cntx->gFMPenParallel_first_x1 = first_x1;
    parallelline_NxMpoint_cntx->gFMPenParallel_first_y1 = first_y1;
    parallelline_NxMpoint_cntx->gFMPenParallel_first_x2 = first_x2;
    parallelline_NxMpoint_cntx->gFMPenParallel_first_y2 = first_y2;
    
    parallelline_NxMpoint_cntx->gFMPenParallel_second_x1 = second_x1;
    parallelline_NxMpoint_cntx->gFMPenParallel_second_y1 = second_y1;
    parallelline_NxMpoint_cntx->gFMPenParallel_second_x2 = second_x2;
    parallelline_NxMpoint_cntx->gFMPenParallel_second_y2 = second_y2;
    
    parallelline_NxMpoint_cntx->gFMPenParallel_first_point_x = first_point_x;
    parallelline_NxMpoint_cntx->gFMPenParallel_first_point_y = first_point_y;
    parallelline_NxMpoint_cntx->gFMPenParallel_second_point_x = second_point_x;
    parallelline_NxMpoint_cntx->gFMPenParallel_second_point_y = second_point_y;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_pen_parallel_test_setup_coordinates
 * DESCRIPTION
 *  This function sets up coordinates according to type of test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  FIRST TEST :: \\
 *  SECOND TEST :: //
 *****************************************************************************/
static void mmi_fm_pen_parallel_test_setup_coordinates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_fm_contxt->parallelline_NxMpoint_contxt.gFMPenParallel_test_type)
    {
        case PARALLEL_TEST_1:
        {
            mmi_fm_set_g_pen_parallel
                (0,20,UI_device_width - 20,UI_device_height,20,0,UI_device_width,UI_device_height - 20,
                8,8,UI_device_width - 8,UI_device_height - 8);

        }
            break;
        case PARALLEL_TEST_2:
        {
            mmi_fm_set_g_pen_parallel
                (UI_device_width - 20,0,0,UI_device_height - 20,UI_device_width,20,20,UI_device_height,
                UI_device_width - 8,8,8,UI_device_height - 8);
        }
            break;
        default:
            ASSERT(0);
            break;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_pen_parallel_test_display
 * DESCRIPTION
 *  This function displays Parallel lines and start and end points of the test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  FIRST TEST :: \\
 *  SECOND TEST :: //
 *****************************************************************************/
static void mmi_fm_pen_parallel_test_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_parallelline_NxMpoint_struct *parallelline_NxMpoint_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_screen();
    gui_lock_double_buffer();

    parallelline_NxMpoint_cntx = &(g_fm_contxt->parallelline_NxMpoint_contxt);

    gui_line(
        parallelline_NxMpoint_cntx->gFMPenParallel_first_x1,
        parallelline_NxMpoint_cntx->gFMPenParallel_first_y1,
        parallelline_NxMpoint_cntx->gFMPenParallel_first_x2,
        parallelline_NxMpoint_cntx->gFMPenParallel_first_y2,
        gui_color(255, 0, 0));
    gui_line(
        parallelline_NxMpoint_cntx->gFMPenParallel_second_x1,
        parallelline_NxMpoint_cntx->gFMPenParallel_second_y1,
        parallelline_NxMpoint_cntx->gFMPenParallel_second_x2,
        parallelline_NxMpoint_cntx->gFMPenParallel_second_y2,
        gui_color(255, 0, 0));

    gui_line(
        parallelline_NxMpoint_cntx->gFMPenParallel_first_point_x - 5,
        parallelline_NxMpoint_cntx->gFMPenParallel_first_point_y - 5,
        parallelline_NxMpoint_cntx->gFMPenParallel_first_point_x + 5,
        parallelline_NxMpoint_cntx->gFMPenParallel_first_point_y + 5,
        gui_color(0, 0, 0));
    gui_line(
        parallelline_NxMpoint_cntx->gFMPenParallel_first_point_x + 5,
        parallelline_NxMpoint_cntx->gFMPenParallel_first_point_y - 5,
        parallelline_NxMpoint_cntx->gFMPenParallel_first_point_x - 5,
        parallelline_NxMpoint_cntx->gFMPenParallel_first_point_y + 5,
        gui_color(0, 0, 0));
    gui_line(
        parallelline_NxMpoint_cntx->gFMPenParallel_second_point_x - 5,
        parallelline_NxMpoint_cntx->gFMPenParallel_second_point_y - 5,
        parallelline_NxMpoint_cntx->gFMPenParallel_second_point_x + 5,
        parallelline_NxMpoint_cntx->gFMPenParallel_second_point_y + 5,
        gui_color(0, 0, 0));
    gui_line(
        parallelline_NxMpoint_cntx->gFMPenParallel_second_point_x + 5,
        parallelline_NxMpoint_cntx->gFMPenParallel_second_point_y - 5,
        parallelline_NxMpoint_cntx->gFMPenParallel_second_point_x - 5,
        parallelline_NxMpoint_cntx->gFMPenParallel_second_point_y + 5,
        gui_color(0, 0, 0));

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

}

/*****************************************************************************
 * FUNCTION
 *  FM_ParallelTestEndKeyTimeout
 * DESCRIPTION
 *  This function handles Long Press of End Key on Parallel Line Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_end_pen_parallel_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_contxt->parallelline_NxMpoint_contxt.addtohistory = FALSE;
    g_fm_contxt->parallelline_NxMpoint_contxt.gFMPenParallel_test_type = PARALLEL_TEST_1;
       
    //FM_HandleKeypadEndout();
    
    if (g_fm_contxt->common_contxt.autoTestMode == 0)
       mmi_frm_scrn_close_active_id();
    else
    {       
         mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_PARALLEL_PEN);
                            mmi_frm_scrn_enter
                            (g_fm_gourp_id, 
                             SCR_ID_FM_PARALLEL_PEN, 
                             NULL,
                             NULL, 
                             MMI_FRM_FULL_SCRN);
        FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_PARALLEL_LINE].name);
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
 *  EntryFMPenParallelTest
 * DESCRIPTION
 *  This function is Entry function of Parallel Line Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_pen_parallel_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_parallelline_NxMpoint_struct *parallelline_NxMpoint_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parallelline_NxMpoint_cntx = &(g_fm_contxt->parallelline_NxMpoint_contxt);

    
    parallelline_NxMpoint_cntx->addtohistory = FALSE;

    mmi_frm_scrn_enter
          (g_fm_gourp_id, 
          SCR_ID_FM_PARALLEL_PEN, 
          NULL,
          mmi_fm_select_pen_parallel_test, 
          MMI_FRM_FULL_SCRN);

    parallelline_NxMpoint_cntx->addtohistory = TRUE;

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fm_end_pen_parallel_test, KEY_END, KEY_EVENT_LONG_PRESS);
    parallelline_NxMpoint_cntx->gFMPenPreviousPoint.x = -1;
    parallelline_NxMpoint_cntx->gFMPenPreviousPoint.y = -1;

    mmi_fm_pen_parallel_test_setup_coordinates();
    entry_full_screen();
    mmi_fm_pen_parallel_test_display();

    wgui_register_pen_down_handler(mmi_fm_pen_parallel_test_pen_down);
    wgui_register_pen_move_handler(mmi_fm_pen_parallel_test_pen_move);
    wgui_register_pen_up_handler(mmi_fm_pen_parallel_test_pen_up);
    wgui_register_pen_repeat_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_long_tap_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_abort_handler(mmi_pen_dummy_hdlr);
}

#endif /* __MMI_TOUCH_SCREEN__ */

#endif /*__MMI_FACTORY_MODE__*/

#if (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__))
#pragma arm section rodata , code
#endif /* (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)) */

