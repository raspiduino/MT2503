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
 * FactoryModeDevice.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for Factory Mode Device, it include vibrator,LCD,LED,charger,
 *   ADC, PXS sensor, Memory card, UART, Nand flash
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 ********************************************************************************/
#include "MMI_features.h"
	 
#ifdef __MMI_FACTORY_MODE__

/*****************************************************************************
* Include Files                                                                
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

#if defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)
#include "Msdc_def.h"
#endif 

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

#ifdef __MMI_FM_RADIO__
#include "aud_defs.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_fmrdo_def.h"
#endif /*__PLUTO_MMI_PACKAGE__*/
#endif

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
#include "FactoryModeUtil.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#define  MAX_ADC_MAP_TAB_SIZE 5   /* size of adc_map_tab */

/***************************************************************************** 
* typedef enum/struct/...
*****************************************************************************/
/*This struct is for showing FM ADC */
typedef struct
{
	DCL_ADC_CHANNEL_TYPE_ENUM type;
	CHAR format[15]; 
	double adc_value;
	MMI_ID str_id;
}mmi_fm_adc_view_struct;


/*This table is for showing ADC menu list*/
mmi_fm_adc_view_struct adc_map_tab[5]=
{
		{DCL_VBAT_ADC_CHANNEL,		"%s %4.3f V",  0.0,   STR_ID_FM_VBAT},
		{DCL_VBATTMP_ADC_CHANNEL,	"%s %4.3f C",  0.0,   STR_ID_FM_BTEMP},
		{DCL_AUX_ADC_CHANNEL,		"%s %4.3f V",  0.0,   STR_ID_FM_VAUX},
		{DCL_VISENSE_ADC_CHANNEL,	"%s %4.3f A",  0.0,   STR_ID_FM_CURRENT},
		{DCL_VCHARGER_ADC_CHANNEL,	"%s %4.3f V",  0.0,   STR_ID_FM_VCHGR},
};




/***************************************************************************** 
* global val / function
*****************************************************************************/
#ifdef __VIBRATION_SPEAKER_SUPPORT__
    MMI_ID g_alertID;
#endif/* __VIBRATION_SPEAKER_SUPPORT__ */
/* common */
extern MMI_ID g_fm_gourp_id ;
extern mmi_fm_item_cntxt_struct *g_fm_contxt;

/*-------------- ADC -----------------*/
extern const unsigned char ADC_VBAT;
extern const unsigned char ADC_VISENSE;
extern const unsigned char ADC_VCHARGER;
extern const unsigned char ADC_ACCESSORYID;
extern const unsigned char ADC_VBATTMP;


extern testlet Tests[MAX_AUTO_TEST_ITEMS];


/***************************************************************************** 
* static  function
*****************************************************************************/
extern void UI_set_clip(S32 x1, S32 y1, S32 x2, S32 y2);
extern void UI_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c);
extern void UI_reset_text_clip(void);
extern void UI_set_font(UI_font_type f);
extern void UI_set_text_color(color c);
extern kal_bool NANDsanitycheck_Factory(void);
/* Vibrator */
static void mmi_fm_set_vibrator(gpio_device_vibrator_level_typedef type, U16 s, U8 vib);
static void mmi_fm_handle_vibrator_rsp(void);

/* LCD */
#ifndef __MMI_MAINLCD_96X64__
static void mmi_fm_exit_color_set_change(void);
static void mmi_fm_set_color_change(U8 color_r,U8 color_g,U8 color_b);
#endif /* __MMI_MAINLCD_96X64__ */


/* ADC */
//static void mmi_fm_exit_adc(void);
static void mmi_fm_stop_adc(void);
static void mmi_fm_update_adc(char * str, double adc_value, MMI_ID srt_id, U32 i);
static void mmi_fm_update_adc_hdlr(void *inMsg);
static void mmi_fm_prepare_adc_list(void);
static void mmi_fm_enter_adc_menu(void);


/* PXS sensor */
#ifdef __MMI_FM_PXS_SENSOR__
static void mmi_fm_pxs_sensor_obj_status_update_handle(U8 * str);
static void mmi_fm_pxs_sensor_obj_away_handle(void);
static void mmi_fm_pxs_sensor_obj_close_handle(void);
static void mmi_fm_exit_get_obj_status(void);
#endif

/* LED */
#ifdef __SUPPORT_LED_FEATURE__
static void mmi_fm_led_toggle_lsk(void);
static void mmi_fm_led_step_func(void);
#endif /* __SUPPORT_LED_FEATURE__ */



/***************************************************************************** 
* Code body
*****************************************************************************/

/* ------------- Send Message ---------------- */

#define MMI_FM_SEND_MSG

/*****************************************************************************
 * FUNCTION
 *  FM_SendMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
extern void FM_SendMsg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm((oslModuleType) MOD_L4C, (oslMsgType)msg_id, 
                        (oslParaType*)local_param_ptr, (oslPeerBuffType*)peer_buf_ptr);

}

/*****************************************************************************
 * FUNCTION
 *  FM_SendADCStartReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void FM_SendADCStartReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_SendMsg(MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_REQ, NULL, NULL);    
}

/*****************************************************************************
 * FUNCTION
 *  FM_SendADCStopReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void FM_SendADCStopReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_SendMsg(MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_REQ, NULL, NULL);
}


/*--------  Viberate  -------- */

#define MMI_FM_VIBRATOR

/*****************************************************************************
 * FUNCTION
 *  FM_SetGpioReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void FM_SetGpioReq(U8 type, U8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_exe_gpio_level_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_exe_gpio_level_req_struct));
    msg_p->gpio_dev_type = type;
    msg_p->gpio_dev_level = level;
    FM_SendMsg(MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ, msg_p, NULL);
}


void FM_SetGpioLEDReq(U8 level)
{
    FM_SetGpioReq(GPIO_DEV_LED_STATUS_1, level);
    FM_SetGpioReq(GPIO_DEV_LED_STATUS_2, level);
    FM_SetGpioReq(GPIO_DEV_LED_STATUS_3, level);
}

void FM_SetGpioVirbateReq(U8 level)
{
    FM_SetGpioReq(GPIO_DEV_VIBRATOR, level);
}

#ifndef __MMI_FM_PLUTO_6261_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_set_vibrator
 * DESCRIPTION
 *  Set vibrator 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_set_vibrator(gpio_device_vibrator_level_typedef type, U16 s, U8 vib)
{
   FM_SetGpioVirbateReq(type);
   change_left_softkey(s, 0);
   g_fm_contxt->viberate_contxt.vib = vib; 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_first_vibrator_complete_cb
 * DESCRIPTION
 *  vibrator done called 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VIBRATION_SPEAKER_SUPPORT__
extern void mmi_first_vibrator_complete_cb(void)
{
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, g_fm_gourp_id, NULL);    
    mmi_frm_group_close(g_alertID);
}
#endif /* __VIBRATION_SPEAKER_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_select_vibrator
 * DESCRIPTION
 *  It is FM entry for vibrator test 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_vibrator(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VIBRATION_SPEAKER_SUPPORT__
    if(KAL_FALSE == Media_Is_Vibrator_Calibration())
    {
        // Invoke First Call API
        mdi_audio_vib_spk_calibration(mmi_first_vibrator_complete_cb);
        g_alertID = mmi_frm_group_create_ex(g_fm_gourp_id, GRP_ID_AUTO_GEN, NULL, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        if (mmi_frm_scrn_enter(g_alertID, g_alertID, NULL, NULL, MMI_FRM_SMALL_SCRN))
        {
	        /* display */
            ShowCategory63Screen((U8*)GetString(STR_ID_FM_VIBRATOR_3_1_FIRST), NULL, NULL);
        }
    }   
#endif /* __VIBRATION_SPEAKER_SUPPORT__ */
    if (g_fm_contxt->viberate_contxt.vib_status == MMI_FALSE)
    {
        mmi_fm_set_vibrator(VIBRATOR_ON, STR_GLOBAL_OFF,1);
        StartTimer(FM_VIB_TIMER, 1000, mmi_fm_handle_vibrator_rsp);
		g_fm_contxt->viberate_contxt.vib_status = KAL_TRUE;
    }
    else
    {
        mmi_fm_set_vibrator(VIBRATOR_OFF,STR_GLOBAL_ON,0);
        g_fm_contxt->viberate_contxt.vib_status = MMI_FALSE;
        StopTimer(FM_VIB_TIMER);
    }
    redraw_left_softkey();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_handle_vibrator_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_handle_vibrator_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_viberate_struct * viberate_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    viberate_cntx = &(g_fm_contxt->viberate_contxt);
    
    viberate_cntx->vib_status = KAL_TRUE;

    if (viberate_cntx->vib == 1)
    {
        viberate_cntx->vib = 0;
        FM_SetGpioVirbateReq(VIBRATOR_OFF);
    }
    else
    {
        viberate_cntx->vib = 1;
        FM_SetGpioVirbateReq(VIBRATOR_ON);
    }

    StartTimer(FM_VIB_TIMER, 1000, mmi_fm_handle_vibrator_rsp);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_vibrator_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_fm_vibrator_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fm_common_set_left_softkey(g_fm_contxt->viberate_contxt.vib_status);

}
#endif /* __MMI_FM_PLUTO_6261_SLIM__ */

#define MMI_FM_LCD
#ifndef __MMI_MAINLCD_96X64__
/*--------  LCD -------- */

int need_close = 1;

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_lcd_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_lcd_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_exit_color_set_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_exit_color_set_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_contxt->common_contxt.sequence_counter = 0;
    StopTimer(FM_LCD_COLOR_CHANGE_TIMER);
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  FM_HandleInitialColor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  color_r     [IN]        
 *  color_g     [IN]        
 *  color_b     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void FM_HandleInitialColor(U8 color_r, U8 color_g, U8 color_b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute debug_print_font = {0, 0, 0, SMALL_FONT, 0, 0};
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = gui_color(color_r, color_g, color_b);
    UI_set_clip(0, 0, UI_device_width, UI_device_height);
    gdi_layer_set_source_key(FALSE, 0);
    UI_fill_rectangle(0, 0, UI_device_width, UI_device_height, c);
    UI_reset_text_clip();
    UI_set_font(&debug_print_font);
    c = gui_color(0, 0, 0);
    UI_set_text_color(c);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_set_color_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  color_r     [IN]        
 *  color_g     [IN]        
 *  color_b     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_set_color_change(U8 color_r,U8 color_g,U8 color_b)
{
    gui_lock_double_buffer();
    g_fm_contxt->common_contxt.sequence_counter++;
    FM_HandleInitialColor(color_r,color_g,color_b);
    StartTimer(FM_LCD_COLOR_CHANGE_TIMER, 1000, mmi_fm_handle_color_set_change);
    need_close = 1;
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_handle_color_set_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_handle_color_set_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_common_struct *common_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    common_cntx = &(g_fm_contxt->common_contxt);
    
    if (common_cntx->autoTestMode)
    {
           if (need_close)
           {
            mmi_frm_scrn_close(g_fm_gourp_id,SCR_ID_FM_AUTO_TEST_START);
               // need_close = 0;
           }
           if (mmi_frm_scrn_enter
           ( g_fm_gourp_id, 
             SCR_ID_FM_AUTO_TEST_START, 
             NULL, 
             mmi_fm_handle_color_set_change, 
             MMI_FRM_FULL_SCRN) != MMI_TRUE)
             return;
    }
    else
    {
           if (mmi_frm_scrn_enter
           ( g_fm_gourp_id, 
             SCR_ID_FM_LCD_AUTO, 
             NULL, 
             NULL, 
             MMI_FRM_FULL_SCRN) != MMI_TRUE)
             return;
    }

    switch (common_cntx->sequence_counter)
    {
        case 0:
            mmi_fm_set_color_change(255,0,0);
            break;
        case 1:
            mmi_fm_set_color_change(0,255,0);
            break;

        case 2:
            mmi_fm_set_color_change(0,0,255);
            break;

        case 3:
            mmi_fm_set_color_change(255,255,255);
            break;
            /* Lisen 05312005 */
        case 4:
            mmi_fm_set_color_change(0,0,0);
            break;
        default:
            common_cntx->sequence_counter = 0;
            StopTimer(FM_LCD_COLOR_CHANGE_TIMER);

            if (common_cntx->autoTestMode == 0)  /* Display the screen if not in autotest mode */
            {
                mmi_asc_to_ucs2((PS8) common_cntx->EMFMUnicodeDisplayBuf, 
                    (CHAR*) "Pass");
                ShowCategory7Screen(0, 0, STR_GLOBAL_OK, 0, STR_GLOBAL_BACK, 0, (U8*) g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf, NULL);
                SetLeftSoftkeyFunction(mmi_fm_exit_color_set_change, KEY_EVENT_UP);
                SetRightSoftkeyFunction(mmi_fm_exit_color_set_change, KEY_EVENT_UP);
            #if !defined(__COSMOS_MMI_PACKAGE__)                
                SetKeyUpHandler(mmi_fm_exit_color_set_change, KEY_ENTER);				
            #else /*__COSMOS_MMI_PACKAGE__*/
                SetKeyUpHandler(mmi_fm_exit_color_set_change, KEY_BACK);
            #endif /*__COSMOS_MMI_PACKAGE__*/
            }
            else
            {
                FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_LCD].name);
                ShowCategory7Screen(
                    STR_ID_FM_AUTO_TEST_RESULT,
                    NULL,
                    STR_ID_FM_AUTO_TEST_PASS,
                    IMG_GLOBAL_OK,
                    STR_ID_FM_AUTO_TEST_FAIL,
                    IMG_GLOBAL_BACK,
                    (PU8) common_cntx->EMFMUnicodeDisplayBuf,
                    NULL);

                FM_Autotest_set_key_handlers(1);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_set_show_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_set_show_color(U8 color_r, U8 color_g, U8 color_b)
{
    gui_lock_double_buffer();
    FM_HandleInitialColor(color_r, color_g, color_b);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_show_color
 * DESCRIPTION
 *  It is will be called by LCD, AT cmd LCD test
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_show_color(S32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(g_fm_gourp_id,GLOBAL_SCR_DUMMY);

    if (mmi_frm_scrn_enter
        (g_fm_gourp_id, 
        GLOBAL_SCR_DUMMY, 
        NULL, 
        NULL, 
        MMI_FRM_FULL_SCRN)!= MMI_TRUE)
     {
     	return;
     }

    SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    
    #ifdef __COSMOS_MMI_PACKAGE__    
    SetKeyUpHandler(mmi_frm_scrn_close_active_id, KEY_SEND);
    #endif

    switch (type)
    {
        case 0: /* Auto */
            g_fm_contxt->common_contxt.sequence_counter = 0;
            mmi_fm_handle_color_set_change();
            break;
        case 1: /* R */

            mmi_fm_set_show_color(255, 0, 0);
            break;

        case 2: /* G */

            mmi_fm_set_show_color(0, 255, 0);
            break;
            
        case 3: /* B */

            mmi_fm_set_show_color(0, 0, 255);
             break;
            
        case 4: /* W */
            mmi_fm_set_show_color(255, 255, 255);
            break;

            /* Lisen 05312005 */
        case 5: /* Black */
            mmi_fm_set_show_color(0, 0, 0);
             break;

        default:
            break;
    }

}

#ifndef __MMI_FM_PLUTO_6261_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_select_certain_lcd_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_certain_lcd_test(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fm_show_color(menu_evt->highlighted_menu_id - MENU_ID_FM_LCD_AUTO);
}
#endif /* __MMI_MAINLCD_96X64__ */
#endif /* __MMI_FM_PLUTO_6261_SLIM__ */


#define MMI_FM_ADC
/*------------------------  ADC  -------------------------------*/

extern void BatteryStatusRsp(void *);
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
 *  mmi_fm_stop_adc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_stop_adc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND, NULL);
	mmi_frm_set_single_protocol_event_handler(PRT_BATTERY_STATUS_IND, (PsIntFuncPtr)BatteryStatusRsp);
	
    FM_SendADCStopReq();
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_update_adc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_update_adc(char * str, double adc_value, MMI_ID srt_id, U32 i)
{    
    CHAR buffer[32];
	CHAR strr[20];
    
	mmi_ucs2_to_asc(strr,GetString(srt_id));
    sprintf(buffer, str,  strr, adc_value);    
    mmi_asc_to_ucs2((CHAR *) subMenuData[i], buffer);
    subMenuDataPtrs[i] = subMenuData[i];
}


/*****************************************************************************
 * FUNCTION
 *  FM_UpdateADCHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_update_adc_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U32 i = 0,j = 0;
    mmi_eq_adc_all_channel_ind_struct *adc_struct = (mmi_eq_adc_all_channel_ind_struct*) inMsg;
    MMI_ID gid;
    MMI_ID sid;

	DCL_HANDLE adc_handle;
	ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* update adc_value */
	adc_map_tab[0].adc_value = (double)adc_struct->vbat / 1000000.0;
	adc_map_tab[1].adc_value = (double)adc_struct->bat_temp / 1000.0;
	adc_map_tab[2].adc_value = (double)adc_struct->vaux / 1000000.0;
	adc_map_tab[3].adc_value = (double)adc_struct->charge_current / 1000000.0;
	adc_map_tab[4].adc_value = (double)adc_struct->vcharge / 1000000.0;
   
    mmi_frm_get_active_scrn_id(&gid,&sid);
    
    if (sid != SCR_ID_FM_ADC)
    {
        return;
    }
	adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
	if(adc_handle == DCL_HANDLE_INVALID)
	{
		 ASSERT(0);   
	}

    
	for (i=0,j=0; i<MAX_ADC_MAP_TAB_SIZE; i++)
	{
		adc_ch.u2AdcName = adc_map_tab[i].type;
		DclSADC_Control(adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);
		if (adc_ch.u1AdcPhyCh != DCL_ADC_ERR_CHANNEL_NO)
		{
		    if (((adc_struct->charge_current) & 0x80000000) && 
				adc_map_tab[i].type == DCL_VISENSE_ADC_CHANNEL)
         	{                
				memcpy(adc_map_tab[i].format, "%s n/a", 7);      // This is a special condition
			}
			else if (adc_map_tab[i].type == DCL_VISENSE_ADC_CHANNEL)
			{
				
				memcpy(adc_map_tab[i].format, "%s %4.3f A", 13);  
			}
			
	        mmi_fm_update_adc(adc_map_tab[i].format,adc_map_tab[i].adc_value,adc_map_tab[i].str_id,j);
            
            j++;
		}
	}

	DclSADC_Close(adc_handle);
	

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


		ShowCategory6Screen(
        STR_ID_FM_ADC,
        0,
        (U16) NULL,
        0,
        STR_GLOBAL_BACK,
        0,
        g_fm_contxt->adc_contxt.gFM_MenuItemNum,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        NULL);

    SetRightSoftkeyFunction(mmi_fm_stop_adc, KEY_EVENT_UP);
    
#ifdef __COSMOS_MMI_PACKAGE__    
    SetKeyUpHandler(mmi_fm_stop_adc, KEY_BACK);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  FM_PrepareADCList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_prepare_adc_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0;
    U8 * MenuItemNum;

	DCL_HANDLE adc_handle;
	ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MenuItemNum = &(g_fm_contxt->adc_contxt.gFM_MenuItemNum);
    *MenuItemNum = 0;

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
#endif

	adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
	if(adc_handle == DCL_HANDLE_INVALID)
	{
		 ASSERT(0);   
	}

	for (i=0,j=0; i<MAX_ADC_MAP_TAB_SIZE; i++)
	{
		adc_ch.u2AdcName = adc_map_tab[i].type;
		DclSADC_Control(adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);
		if (adc_ch.u1AdcPhyCh != DCL_ADC_ERR_CHANNEL_NO)
		{
	        mmi_fm_update_adc("%s %4.2f",adc_map_tab[i].adc_value,adc_map_tab[i].str_id,j);
			j++;
			(*MenuItemNum)++;
		}
		
	}

	DclSADC_Close(adc_handle);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_select_adc_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_adc_menu(void)
{
	mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND, 
	                                   (PsIntFuncPtr)mmi_fm_update_adc_hdlr);

    FM_SendADCStartReq();
    mmi_fm_enter_adc_menu();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_enter_adc_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_enter_adc_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 * MenuItemNum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MenuItemNum = &(g_fm_contxt->adc_contxt.gFM_MenuItemNum);
    mmi_frm_scrn_enter
        (g_fm_gourp_id, 
        SCR_ID_FM_ADC, 
        NULL, 
        mmi_fm_enter_adc_menu, 
        MMI_FRM_FULL_SCRN);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

#ifdef __MTK_TARGET__
    mmi_fm_prepare_adc_list();
#endif 

    if (*MenuItemNum < 1)
    {
        *MenuItemNum = 0;
    }

    ShowCategory6Screen(
        STR_ID_FM_ADC,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        *MenuItemNum,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_fm_stop_adc, KEY_EVENT_UP);
#ifdef __COSMOS_MMI_PACKAGE__    
    SetKeyUpHandler(mmi_fm_stop_adc, KEY_BACK);
#endif
}

#define MMI_FM_PXS_SENSOR

#ifdef __MMI_FM_PXS_SENSOR__

/*------------ FM PXS ------------*/

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_fm_pxs_sensor_obj_status_update_handle(U8 * str)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/   
    S32 width = 0, height = 0;
    stFontAttribute     MMI_small_font = {   0,0,0,DIALER_FONT,0,1    };
    stFontAttribute debug_print_font = {0, 0, 0, DIALER_FONT, 0, 0};
    
    color c;

    U8 view_str[14] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    gui_lock_double_buffer();

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

     c = gui_color(255, 255, 255);

     UI_fill_rectangle(
         0,
         40,
         MAIN_LCD_device_width-1,
         MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT,
         c);

     UI_set_font(&debug_print_font);
     c = gui_color(0, 0, 0);
     UI_set_text_color(c);
 
    mmi_asc_n_to_ucs2((CHAR*)view_str , (CHAR*) str, 5);
   
    gui_set_font(&MMI_small_font);
    gui_measure_string((UI_string_type) view_str, &width, &height);
    gui_move_text_cursor(90, 50);
    gui_print_text((UI_string_type) view_str);

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_fm_pxs_sensor_obj_away_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     
    U8 temp_str[6] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     sprintf((char *)temp_str, "AWAY");
     mmi_fm_pxs_sensor_obj_status_update_handle(temp_str); 
//     kal_prompt_trace(MOD_MMI, "[SRV_SENSOR_PXS] Away EVT!");
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_fm_pxs_sensor_obj_close_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     
    U8 temp_str[6] = {0};
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     sprintf((char *)temp_str, "CLOSE");
     
     mmi_fm_pxs_sensor_obj_status_update_handle(temp_str);  

 //    kal_prompt_trace(MOD_MMI, "[SRV_SENSOR_PXS] Close EVT!");
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_fm_exit_get_obj_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    srv_sensor_pxs_turn_off();
    mmi_frm_cb_dereg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE,mmi_fm_pxs_sensor_obj_close_handle,NULL);
		mmi_frm_cb_dereg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY,mmi_fm_pxs_sensor_obj_away_handle,NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_enter_pxs
 * DESCRIPTION
 *  It is extern entry for FM PXS sensor
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_fm_enter_pxs(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   srv_sensor_pxs_turn_on();   
  
   mmi_frm_scrn_enter
     (g_fm_gourp_id, 
     SCR_ID_FM_PXS_RAW_DATA, 
     mmi_fm_exit_get_obj_status,
     mmi_fm_enter_pxs, 
     MMI_FRM_FULL_SCRN);
   
   ShowCategory7Screen(0, 0, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, NULL);
   SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
   mmi_fm_pxs_sensor_obj_away_handle();
       
   mmi_frm_cb_reg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE,mmi_fm_pxs_sensor_obj_close_handle,NULL);
   mmi_frm_cb_reg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY,mmi_fm_pxs_sensor_obj_away_handle,NULL);
   
}

#endif /*__MMI_FM_PXS_SENSOR__*/

#define MMI_FM_LED
#if defined(__SUPPORT_LED_FEATURE__) && !defined(__MMI_FM_PLUTO_6261_SLIM__)
/*------------------------ LED -------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_led_highlight
 * DESCRIPTION
 *  It is extern entry for led highlight
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_fm_led_highlight(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    U32 *HighlightIdx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HighlightIdx = &(g_fm_contxt->led_contxt.gFM_HighlightIdx);
    
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_FM_LED_MAIN:    /* Main LCM BL */
            *HighlightIdx = 0;
            break;
    #ifdef __MMI_SUBLCD__
        case MENU_ID_FM_LED_SUB:     /* Sub LCM BL */
    #endif
             *HighlightIdx = 1;
             break;
        case MENU_ID_FM_LED_KEYPAD:    /* Keypad LED */
            *HighlightIdx = 2;
            break;

        #ifndef __MMI_HIDE_STATUS_LED_R__
        case MENU_ID_FM_LED_STATUS_R:   /* Status LED R */
            *HighlightIdx = 3;
            break;
        #endif /* __MMI_HIDE_STATUS_LED_R__ */ 

        #ifndef __MMI_HIDE_STATUS_LED_G__
        case MENU_ID_FM_LED_STATUS_G:   /* Status LED G */
            *HighlightIdx = 4;
            break;
        #endif /* __MMI_HIDE_STATUS_LED_G__ */ 

        #ifndef __MMI_HIDE_STATUS_LED_B__
            case MENU_ID_FM_LED_STATUS_B:          /* Status LED B */
            *HighlightIdx = 5;
            break;
        #endif /* __MMI_HIDE_STATUS_LED_B__ */ 

        default:
            break;
    }

    /* Show LSK on / off */
    mmi_fm_common_set_left_softkey(FM_IS_SET(g_fm_contxt->led_contxt.FM_LEDState, *HighlightIdx));   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_led_toggle_lsk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_led_toggle_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_led_struct *led_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    led_cntx = &(g_fm_contxt->led_contxt);
    
    FM_STATE_TOGGLE(led_cntx->FM_LEDState, led_cntx->gFM_HighlightIdx);
    mmi_fm_common_set_left_softkey(FM_IS_SET(led_cntx->FM_LEDState, led_cntx->gFM_HighlightIdx));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_led_step_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_led_step_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_led_struct *led_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    led_cntx = &(g_fm_contxt->led_contxt);
    
    if (led_cntx->sequence_counter < LED_LIGHT_LEVEL_MAX)
    {
        switch (led_cntx->gFM_HighlightIdx)
        {
            case 0:    /* Main LCM BL */
        #ifdef __MMI_SUBLCD__
            case 1:     /* Sub LCM BL */
        #endif
                FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, led_cntx->sequence_counter);
                StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 200, mmi_fm_led_step_func);
                break;
            case 2:    /* Keypad LED */
                FM_SetGpioReq(GPIO_DEV_LED_KEY, led_cntx->sequence_counter);
                StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 200, mmi_fm_led_step_func);
                break;

        #ifndef __MMI_HIDE_STATUS_LED_R__
            case 3:   /* Status LED R */
                FM_SetGpioReq(GPIO_DEV_LED_STATUS_1, led_cntx->sequence_counter);
                StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 200, mmi_fm_led_step_func);
                break;
        #endif /* __MMI_HIDE_STATUS_LED_R__ */ 

        #ifndef __MMI_HIDE_STATUS_LED_G__
            case 4:   /* Status LED G */
                FM_SetGpioReq(GPIO_DEV_LED_STATUS_2, led_cntx->sequence_counter);
                StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 200, mmi_fm_led_step_func);
                break;
        #endif /* __MMI_HIDE_STATUS_LED_G__ */ 

        #ifndef __MMI_HIDE_STATUS_LED_B__
            case 5:   /* Status LED B */
                FM_SetGpioReq(GPIO_DEV_LED_STATUS_3, led_cntx->sequence_counter);
                StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 200, mmi_fm_led_step_func);
                break;
        #endif /* __MMI_HIDE_STATUS_LED_B__ */ 

            default:
                led_cntx->sequence_counter = 0;
                StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
                break;
        }

        led_cntx->sequence_counter++;
    }
    else
    {
        led_cntx->sequence_counter = 0;
        StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

        /* Robin 0830 for Cannon+ SRC 3782 */
    #if 0
/* under construction !*/
/* under construction !*/
	#ifndef __MMI_HIDE_STATUS_LED_R__   
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
	#ifndef __MMI_HIDE_STATUS_LED_G__   
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
	#ifndef __MMI_HIDE_STATUS_LED_B__   
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
    }
}

void mmi_fm_led_process(mmi_fm_led_struct *led_cntx, U8 type)
{
    if (FM_IS_SET(led_cntx->FM_LEDState, led_cntx->gFM_HighlightIdx))//((b & (0x1 << a)) >> a)
    {
        mmi_fm_led_step_func();
    }
    else
    {
        FM_SetGpioReq(type, LED_LIGHT_LEVEL0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_select_led
 * DESCRIPTION
 *  It is extern entry for led select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_led(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    mmi_fm_led_struct *led_cntx;
    U8 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    led_cntx = &(g_fm_contxt->led_contxt);
    
    mmi_fm_led_toggle_lsk();
    led_cntx->sequence_counter = 0;
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_FM_LED_MAIN:    /* Main LCM BL */
    #ifdef __MMI_SUBLCD__
        case MENU_ID_FM_LED_SUB:     /* Sub LCM BL */
    #endif
            type = GPIO_DEV_LED_MAINLCD;            
        case MENU_ID_FM_LED_KEYPAD:             /* Keypad LED */           
            type = GPIO_DEV_LED_KEY;  
    #ifndef __MMI_HIDE_STATUS_LED_R__
        case MENU_ID_FM_LED_STATUS_R:           /* Status LED R */
            type = GPIO_DEV_LED_STATUS_1;            
    #endif                                      /* __MMI_HIDE_STATUS_LED_R__ */ 
    #ifndef __MMI_HIDE_STATUS_LED_G__
        case MENU_ID_FM_LED_STATUS_G:           /* Status LED G */
            type = GPIO_DEV_LED_STATUS_2;            
    #endif                                      /* __MMI_HIDE_STATUS_LED_G__ */ 
    #ifndef __MMI_HIDE_STATUS_LED_B__
        case MENU_ID_FM_LED_STATUS_B:           /* Status LED B */
            type = GPIO_DEV_LED_STATUS_3;
            mmi_fm_led_process(led_cntx, type);
            break;
        #endif /* __MMI_HIDE_STATUS_LED_B__ */ 

        default:
            break;
    }
}
#endif /* define(__SUPPORT_LED_FEATURE__) && !define(__MMI_FM_PLUTO_6261_SLIM__ */

#define MMI_FM_MEMORY_CARD

/*--------  15:  Memory card -------- */

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))

/*****************************************************************************
 * FUNCTION
 *  FM_MemoryCardReq
 * DESCRIPTION
 *  This function will be called by FM and quick test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void FM_MemoryCardReq(void)
{
#if ( !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_memcard_struct *memcard_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcard_cntx = &(g_fm_contxt->memcard_contxt);
    
    ClearInputEventHandler(MMI_DEVICE_KEY);

    memcard_cntx->Card_Response_Received = FALSE;

    memcard_cntx->FM_Card_Status.present = KAL_FALSE;

    mmi_frm_send_ilm((oslModuleType) MOD_FMT, MSG_ID_MMI_FMT_GET_MSDC_STATUS_REQ, 
                        (oslParaType*)NULL, NULL);

   memcard_cntx->Card_Response_Sent = TRUE;

#endif /* ( !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)) */ 
}

/*****************************************************************************
 * FUNCTION
 *  EntryFMMemoryCardMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_memory_card(void)
{
#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_fm_common_struct *common_cntx;
    mmi_fm_memcard_struct *memcard_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    common_cntx = &(g_fm_contxt->common_contxt);
    memcard_cntx = &(g_fm_contxt->memcard_contxt);

    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

    if (memcard_cntx->FM_Card_Status.present == TRUE)
    {
        switch (memcard_cntx->FM_Card_Status.type) 
        {
            case MS_CARD:
                mmi_asc_to_ucs2((CHAR*) common_cntx->EMFMUnicodeDisplayBuf, "\nMS_CARD.");
                break;
            case SD_CARD:
                mmi_asc_to_ucs2((CHAR*) common_cntx->EMFMUnicodeDisplayBuf, "\nSD_CARD.");
                break;
            case MMC_CARD:
                mmi_asc_to_ucs2((CHAR*) common_cntx->EMFMUnicodeDisplayBuf, "\nMMC_CARD.");
                break;
            default:
                mmi_asc_to_ucs2((CHAR*) common_cntx->EMFMUnicodeDisplayBuf, "\nError!!!");
        }
    }
    else
    {
        if (memcard_cntx->Card_Response_Received == FALSE)
        {   /* Keep waiting..... */
            if (memcard_cntx->Card_Response_Sent == FALSE)
            {
                FM_MemoryCardReq();
            }
            StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 300, mmi_fm_select_memory_card);
            mmi_asc_to_ucs2((CHAR*) common_cntx->EMFMUnicodeDisplayBuf, "\nPlease Wait....");
        }
        else
        {   /* No Card inserted. */
            mmi_asc_to_ucs2((CHAR*) common_cntx->EMFMUnicodeDisplayBuf, "\nNo Card.");
        }
    }

    mmi_frm_scrn_close(g_fm_gourp_id,SCR_ID_FM_MEMORY_CARD);
    mmi_frm_scrn_enter
         (g_fm_gourp_id, 
          SCR_ID_FM_MEMORY_CARD, 
          NULL,
          NULL, 
          MMI_FRM_FULL_SCRN);
    
    if (memcard_cntx->Card_Response_Sent == FALSE)
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    }
    else
    {
        guiBuffer = NULL;
    }

    ShowCategory7Screen(
        STR_GLOBAL_MEMORY_CARD,
        NULL,
        (U16) NULL,
        (U16) NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) common_cntx->EMFMUnicodeDisplayBuf,
        guiBuffer);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    mmi_fm_set_general_goback_function();

#endif /* (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)) */ 
}

#endif /* (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)) */ 


#define MMI_FM_UART
/*--------  UART -------- */

/* This item have been phase out! */

#ifdef __MMI_FM_UART_TEST__
#ifndef __MMI_FM_PLUTO_6261_SLIM__
void mmi_fm_pre_uart_hint(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 uart_MenuData[MAX_SUB_MENU_SIZE];
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_asc_to_ucs2((CHAR*) uart_MenuData, (CHAR*) "UART2 must be free!");
    cui_menu_set_item_hint(menu_evt->sender_id, MENU_ID_FM_UART, (UI_string_type) uart_MenuData);
}

/*****************************************************************************
 * FUNCTION
 *  FM_UARTResponseHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void FM_UARTResponseHandler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // UART_Response_Received = TRUE;
    g_fm_contxt->uart_contxt.UART_Response_Received = TRUE;
}

#ifdef __FM_UART_TEST_ON_UART1__
#define port_to_test uart_port1
#else 
#define port_to_test uart_port2
#endif 


static kal_uint16 mmi_fm_uart_put_bytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{

	DCL_HANDLE handle;
	UART_CTRL_PUT_BYTES_T data;

	data.u4OwenrId = ownerid;
	data.u2Length = Length;
	data.puBuffaddr = Buffaddr;

    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
    return data.u2RetSize;
}

static kal_uint16 mmi_fm_uart_get_bytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{

    DCL_HANDLE handle;
    UART_CTRL_GET_BYTES_T data;

    data.u4OwenrId = ownerid;
    data.u2Length = Length;
    data.puBuffaddr = Buffaddr;
    data.pustatus = status;
    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
    return data.u2RetSize;

}


/*****************************************************************************
 * FUNCTION
 *  FM_WriteReadUART
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_WriteReadUART(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#define TEST_INFO_LENGTH 10
    kal_uint8 put_buffer[] = "1234567890";
    kal_uint8 get_buffer[TEST_INFO_LENGTH];
    kal_uint32 read_length = 0;
    kal_uint32 send_length;
    kal_uint8 status = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_length = mmi_fm_uart_put_bytes(port_to_test, (kal_uint8*) put_buffer, (kal_uint16) TEST_INFO_LENGTH, MOD_MMI);

    if (send_length != TEST_INFO_LENGTH)    /* Send error or incomplete */
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, 1000, 0);
    }
    else
    {
        memset((void*)get_buffer, 0, TEST_INFO_LENGTH);
        kal_sleep_task(100);
        read_length = mmi_fm_uart_get_bytes(port_to_test, get_buffer, TEST_INFO_LENGTH, &status, MOD_MMI);

        if ((read_length == TEST_INFO_LENGTH) && !strncmp((void*)put_buffer, (void*)get_buffer, TEST_INFO_LENGTH))
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_OK), IMG_GLOBAL_OK, 0, 1000, 0);
        }
        else    /* Error case */
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, 1000, 0);
        }
    }
}

static module_type mmi_fm_uart_get_owner_id(UART_PORT port)
{

	DCL_HANDLE handle;
	UART_CTRL_OWNER_T data;

	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_GET_OWNER_ID, (DCL_CTRL_DATA_T*)&data);
	return (module_type)(data.u4OwenrId);
	
}

static void mmi_fm_uart_set_owner_id(UART_PORT port, module_type ownerid)
{

	DCL_HANDLE handle;
	UART_CTRL_OWNER_T data;
	data.u4OwenrId = ownerid;

	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*)&data);

}

/*****************************************************************************
 * FUNCTION
 *  EntryFMUARTMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_uart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern kal_bool tst_switch_logging_port(UART_PORT old_port, UART_PORT new_port);
    extern UART_PORT   TST_PORT ;
    extern UART_PORT   TST_PORT_L1;

    module_type UART_Owner = MOD_NIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UART_Owner = mmi_fm_uart_get_owner_id(port_to_test);

    if (TST_PORT == uart_port2 || TST_PORT_L1 == uart_port2)
    {
        tst_switch_logging_port(port_to_test, uart_port_null);
    }
    
    mmi_fm_uart_set_owner_id(port_to_test, MOD_MMI);
    FM_WriteReadUART();
    
    if (TST_PORT == uart_port2 || TST_PORT_L1 == uart_port2)
    {    	
        tst_switch_logging_port(uart_port_null, port_to_test);
    }
    
    mmi_fm_uart_set_owner_id((UART_PORT)port_to_test, UART_Owner);
}

#endif /* __MMI_FM_UART_TEST__*/
#endif /* __MMI_FM_PLUTO_6261_SLIM__ */

#define MMI_FM_NAND_FLASH

/*----------------------Nand flash---------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_select_nand_flash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_nand_flash(void)
{
#ifdef NAND_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

    if (NANDsanitycheck_Factory() == KAL_TRUE)
    {
        mmi_popup_display_simple(
        (WCHAR*) get_string(STR_ID_FM_AUTO_TEST_PASS),
         MMI_EVENT_SUCCESS,
         g_fm_gourp_id,
         NULL);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_FAILED), IMG_GLOBAL_ERROR, 0, 1000, 0);
    }
#endif /* NAND_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_gpio_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  port        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_gpio_start(kal_uint8 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fm_gpio_writeIO(1, port);
}

void mmi_fm_gpio_writeIO(kal_uint8 data, kal_uint8 port)
{
	DCL_HANDLE handle;
    
	handle=DclGPIO_Open(DCL_GPIO, port);	

    if(0 == data)
		DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
	else if(1 == data)
		DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
	
	DclGPIO_Close(handle);	
}



#define MMI_FM_MOTION_SENSOR_CALI

#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__

static mmi_ret mmi_fm_motion_sensor_cali_finished_handle()
{
	mmi_popup_display_simple(
        (WCHAR*) get_string(STR_ID_FM_MOTION_SENSOR_CALI_FINISHED),
         MMI_EVENT_SUCCESS,
         g_fm_gourp_id,
         NULL);

	 return MMI_RET_OK;
}

static mmi_ret mmi_fm_motion_sensor_cali_timeout_handle()
{
	mmi_popup_display_simple(
        (WCHAR*) get_string(STR_ID_FM_MOTION_SENSOR_CALI_TIMEOUT),
         MMI_EVENT_FAILURE,
         g_fm_gourp_id,
         NULL);

	 return MMI_RET_OK;
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
#endif



void mmi_fm_start_sensor_cali()
{
	mmi_frm_cb_reg_event(EVT_ID_SENSOR_MOTION_CALI_FINISHED,mmi_fm_motion_sensor_cali_finished_handle,NULL);
	mmi_frm_cb_reg_event(EVT_ID_SENSOR_MOTION_CALI_TIMEOUT,mmi_fm_motion_sensor_cali_timeout_handle,NULL);
	//mmi_frm_cb_reg_event(EVT_ID_SENSOR_MOTION_CALI_WRITE_FAIL,mmi_fm_motion_sensor_cali_fail_reslut_handle,NULL);

	srv_sensor_motion_start_cali();

}

static void mmi_fm_exit_motion_sensor_cali()
{
	
	mmi_frm_cb_dereg_event(EVT_ID_SENSOR_MOTION_CALI_FINISHED,mmi_fm_motion_sensor_cali_finished_handle,NULL);
	mmi_frm_cb_dereg_event(EVT_ID_SENSOR_MOTION_CALI_TIMEOUT,mmi_fm_motion_sensor_cali_timeout_handle,NULL);
	//mmi_frm_cb_dereg_event(EVT_ID_SENSOR_MOTION_CALI_WRITE_FAIL,mmi_fm_motion_sensor_cali_fail_reslut_handle,NULL);
	srv_sensor_motion_stop_cali();
}

extern void mmi_fm_motion_sensor_cali(void)
{
	 mmi_frm_scrn_enter
     (g_fm_gourp_id, 
     SCR_ID_FM_MOTION_CALI, 
     mmi_fm_exit_motion_sensor_cali,
     mmi_fm_motion_sensor_cali, 
     MMI_FRM_FULL_SCRN);
   
   ShowCategory7Screen(STR_ID_FM_MOTION_SENSOR_CALI
   , 0, STR_GLOBAL_OK, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, GetString(STR_ID_FM_MOTION_SENSOR_CALI_NOTIFICATION), NULL);

   SetLeftSoftkeyFunction(mmi_fm_start_sensor_cali,KEY_EVENT_UP);
   SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
   
}

#endif /*MOTION_SENSOR_SUPPORT*/


#if (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__))
#pragma arm section rodata , code
#endif /* (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)) */

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))

/*****************************************************************************
 * FUNCTION
 *  FM_MemoryCardResponseHandler
 * DESCRIPTION
 *  This API will be use by FM and FileMgr
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void FM_MemoryCardResponseHandler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_memcard_struct *memcard_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    
    if (g_fm_contxt != NULL)
    {
        memcard_cntx = &(g_fm_contxt->memcard_contxt);
        memcard_cntx->Card_Response_Received = TRUE;
        memcpy((void*)&(memcard_cntx->FM_Card_Status), info, sizeof(mmi_fmt_get_msdc_status_rsp_strcut));
        memcard_cntx->Card_Response_Sent = FALSE;
    }
}

#endif /* (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)) */

#endif /* __MMI_FACTORY_MODE__ */

