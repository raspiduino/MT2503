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
 * FactoryModeQuickTest.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for Factory Mode Quick test
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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


#if defined __MMI_FM_CAMERA_PREVIEW__

#include "lcd_if.h"
#include "lcd_sw_rnd.h" /* LCD layer enable flag */
#include "mdi_datatype.h"
#include "med_api.h"    /* media task camera module */
#include "MMI_features_camera.h"
#include "resource_camera_skins.h"
#include "mdi_camera.h"
#include "CameraApp.h"

#if defined(ISP_SUPPORT)
#include "image_sensor.h"
#endif 
#endif /* __MMI_FM_CAMERA_PREVIEW__ */ 

#include "init.h"
#include "init_public.h"

#include "device.h"
#include "custom_em.h"
#ifdef __MMI_FM_KEYPAD_TEST__
#include "custom_fm.h"
#endif
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

/* For MRE version */
#include "vmsys.h"
#include  "stack_msgs.h"

#ifdef __GADGET_SUPPORT__
#include "WgtMgrSrvGprot.h"
#endif 

#include "PowerOnChargerProt.h"

#include "FileMgrSrvGProt.h"

#include "aud_main.h"
#include "FactoryModeConfig.h"
#include "FactoryModeProt.h"
#include "FactoryModeUtil.h"
//#include "AlarmGprot.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#define NOSENDKEY_CNT_START_SHOW   0
#define NOSENDKEY_CNT_START_HIDE   1
#define NOSENDKEY_CNT_STOP_SHOW    2
#define NOSENDKEY_UNCNT_STOP_SHOW  6
#define NOSENDKEY_UNCNT_STOP_HIDE  7

#define SENDKEY_CNT_START_SHOW     8
#define SENDKEY_CNT_START_HIDE     9
#define SENDKEY_CNT_STOP_SHOW      10
#define SENDKEY_UNCNT_STOP_SHOW    14
#define SENDKEY_UNCNT_STOP_HIDE    15

#define SENDKEYFLAG     0x08
#define CONTINUSFLAG    0x04
#define STOPFLAG        0x02
#define SHOWSCRNFLAG    0x01


/***************************************************************************** 
* typedef enum/struct/...
*****************************************************************************/

/***************************************************************************** 
* global val / function
*****************************************************************************/
extern U16 g_cameraStartFlag;
extern U8 gCurrentMode;

extern MMI_ID g_fm_gourp_id;

extern mmi_fm_item_cntxt_struct *g_fm_contxt;

/*-------------auto test-----------------*/
/* Auto Testing Settings */
extern S32 g_fm_PriorityValue ;
extern S16 g_fm_AutoTestListSize ;
extern U16 g_fm_HiliteAutoTestCurrSelIdx ;
extern U16 g_fm_HiliteAllTestListIdx ;
extern U16 g_fm_newPriority ;
extern AutoTestItemArray g_fm_nvramTestItemArray;
extern AutoTestResultArray g_fm_nvramTestResultArray;
extern rtc_format_struct g_fm_myclocktime;
extern PU8 g_fm_AutoTestSelectedItems[MAX_AUTO_TEST_ITEMS];

/* -----------Camera ------------- */
#if defined(__MMI_FM_CAMERA_PREVIEW__)
extern camera_context_struct g_camera_cntx;
extern const U8 camera_ev_command_map[];
extern const U8 camera_zoom_command_map[];
extern const U8 camera_effect_command_map[];
extern const U8 camera_wb_command_map[];
extern const U8 camera_banding_command_map[];
extern const U8 camera_jpg_size_command_map[];
extern const U8 camera_image_qty_command_map[];

/* extern gdi_color                     GDI_COLOR_BLACK; */
extern wgui_inline_item wgui_inline_items[];

extern gdi_handle wgui_base_layer;
extern gdi_handle wgui_layer_1;

#endif /* defined(__FM_CAMERA_PREVIEW__) */ 



#if defined(__MMI_FM_CAMERA_PREVIEW__)
extern void mmi_fm_camera_entry_sublcd_screen(void);
#endif 


#if defined(__MMI_FM_TC01_CAMERA_TEST__)
extern void mmi_fm_camera_test_entry_cam_test(void);
#endif

/*--- For Quick test setting----- */
extern void mmi_fm_select_auto_test_setting(void);
extern void mmi_fm_WriteTestResultToNVRAM(void);
extern void FM_SendStopAudioReq(U8 index);
extern void FM_SetGpioReq(U8 type, U8 level);
extern void gui_touch_feedback_enable_tone_internal(void);
extern void gui_touch_feedback_enable_vibrate_internal(void);
extern void gui_touch_feedback_disable_tone_internal(void);
extern void gui_touch_feedback_disable_vibrate_internal(void);
extern void mmi_fm_ReadTimeFromNVRAM(void);
extern void mmi_fm_WriteCurrentTimeToNVRAM(void);
extern void mmi_fm_ReadTestResultFromNVRAM(void);
extern void FM_SendADCStartReq(void);
extern void FM_SetGpioVirbateReq(U8 level);

extern void InitFactoryModeEvent(void);
extern void DeinitFactoryModeEvent(void);
/***************************************************************************** 
* static  function
*****************************************************************************/
/*-----------auto test-------------------*/
static void EntryFMAutoTestStart(void);
static void EntryFMAutoTestReport(void);
static void FM_InitAutoTest(void);
static U8 mmi_fm_auto_test_delete_history_hdlr(void);
#ifdef __SUPPORT_LED_FEATURE__
static void FM_AutoTest_LED(void);
#endif /* __SUPPORT_LED_FEATURE__ */
static void FM_AutoTest_CLAM(void);
static void FM_AutoTest_Version(void);
static void FM_AutoTest_Backlight(void);
static void FM_AutoTest_Keypad(void);
static void FM_AutoTest_LCD(void);
static void FM_AutoTest_Receiver(void);
static void FM_AutoTest_MIC(void);
static void FM_AutoTest_Speaker(void);
static void FM_AutoTest_Headset(void);
static void FM_AutoTest_Battery(void);
static void FM_AutoTest_Melody(void);
static void FM_AutoTest_VIB(void);
static void FM_AutoTest_NAND(void);
#ifdef __MMI_FM_UART_TEST__
static void FM_AutoTest_UART(void);
#endif
static void FM_AutoTest_Double_Speaker(void);
static void FM_AutoTest_CAMERA(void);
static void FM_AutoTest_MemoryCard(void);
#ifdef __MMI_TOUCH_SCREEN__
static void FM_AutoTest_Pen_Parallel_Test(void);
#endif /* __MMI_TOUCH_SCREEN__ */ 
static void FM_ReTest(void);
static void FM_Handle_Pass_Key_Press(void);
static void FM_Handle_Fail_Key_Press(void);

//static void FM_Autotest_Stop_Test(void);

static void mmi_fm_select_atv(void);
static void mmi_fm_highlight_atv(void);

static void mmi_fm_reenter_auto_test(void);
static void mmi_fm_enter_auto_test(void);
static void	mmi_fm_enter_autotest_nand(void);


/*=============== Auto Testing =============== */
const testlet Tests[MAX_AUTO_TEST_ITEMS] = {    /* Maximum name length = MAX_TEST_ITEM_NAME_LEN*ENCODING_LENGTH */
#ifdef __SUPPORT_LED_FEATURE__
    {"LED", FM_AutoTest_LED},
#endif
    {"Clam", FM_AutoTest_CLAM},
    {"Version", FM_AutoTest_Version},
    {"Backlight", FM_AutoTest_Backlight},
#ifndef __MMI_MAINLCD_96X64__
    {"LCD", FM_AutoTest_LCD},
#endif
    {"KeyPad", FM_AutoTest_Keypad},
    {"Recevier", FM_AutoTest_Receiver},
    {"MIC", FM_AutoTest_MIC},
    {"Speaker", FM_AutoTest_Speaker},
    {"Headset", FM_AutoTest_Headset},
    {"Battery", FM_AutoTest_Battery},
    {"Melody", FM_AutoTest_Melody},
    {"Vibrator", FM_AutoTest_VIB},
    {"NAND", FM_AutoTest_NAND},   
#ifdef __MMI_FM_UART_TEST__
    {"UART", FM_AutoTest_UART},
#endif
    {"Doublespeaker", FM_AutoTest_Double_Speaker},     /* 17 */
#ifndef __MMI_MAINLCD_96X64__
    {"CAMERA", FM_AutoTest_CAMERA},     /* 18 */
#endif
    {"MemoryCard", FM_AutoTest_MemoryCard}  /* 19 */
#ifdef __MMI_TOUCH_SCREEN__
    , {"ParallelLine", FM_AutoTest_Pen_Parallel_Test} /* 20 */
    , {"NxMPoint", FM_AutoTest_Pen_N_Cross_M_Test}        /* 21 */
#endif /* __MMI_TOUCH_SCREEN__ */ 
};


/***************************************************************************** 
* Code body
*****************************************************************************/
#define MMI_FM_AUTO_TEST
	
/*--------------------------- AUTO TEST ----------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *	FM_ReTest
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
static void FM_ReTest(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_fm_common_struct *common_cntx;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	common_cntx = &(g_fm_contxt->common_contxt);
	
	/* currTestItem--; */
	common_cntx->sequence_counter = 0;	 /* Reset the sequence counter */
	common_cntx->TestExecuted[common_cntx->currTestItem] = FALSE;
	EntryFMAutoTestStart();
}

/*****************************************************************************
 * FUNCTION
 *	FM_Handle_Pass_Key_Press
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
static void FM_Handle_Pass_Key_Press(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

    mmi_fm_back_to_normal_state();    

	g_fm_nvramTestResultArray.result[g_fm_contxt->common_contxt.currTestItem] = FM_TEST_PASSED;
	g_fm_contxt->common_contxt.currTestItem++;
          
	mmi_fm_WriteTestResultToNVRAM();    

	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
    	
	EntryFMAutoTestStart();    
}

/*****************************************************************************
 * FUNCTION
 *	FM_Handle_Fail_Key_Press
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
static void FM_Handle_Fail_Key_Press(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/    
	mmi_fm_back_to_normal_state();

	g_fm_nvramTestResultArray.result[g_fm_contxt->common_contxt.currTestItem] = FM_TEST_FAILED;
	g_fm_contxt->common_contxt.currTestItem++;
	mmi_fm_WriteTestResultToNVRAM();

	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	
	EntryFMAutoTestStart();
}

/*****************************************************************************
 * FUNCTION
 *	FM_Autotest_set_key_handlers
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
extern void FM_Autotest_set_key_handlers(U8 is_reg_sendkey)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (is_reg_sendkey)
	SetKeyDownHandler(FM_ReTest, KEY_SEND);
	PowerAndEndKeyHandler();
	SetLeftSoftkeyFunction(FM_Handle_Pass_Key_Press, KEY_EVENT_UP);
	SetRightSoftkeyFunction(FM_Handle_Fail_Key_Press, KEY_EVENT_UP);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
static MMI_RET mmi_fm_auto_test_group_proc(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_GROUP_DEINIT:
			StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

			applib_mem_ap_free(g_fm_contxt);
			g_fm_contxt = 0;
			g_fm_gourp_id = 0;

			mmi_fm_auto_test_delete_history_hdlr();
			
			StopTimer(FM_LCD_COLOR_CHANGE_TIMER);
			FM_SendStopAudioReq(0);
			FM_SetGpioVirbateReq(VIBRATOR_OFF);
			
			FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
			mdi_audio_stop_id(TONE_KEY_NORMAL);
			
        //#ifdef __MMI_FM_CAMERA_PREVIEW__
        /* For camera */
        #ifdef __MMI_FM_CAMERA_PREVIEW__
			mmi_fm_close_camera();          
        #endif
			
			/* Enable tone internal */
			gui_touch_feedback_enable_tone_internal();
			gui_touch_feedback_enable_vibrate_internal();

            /* DCM Require */
            MMI_FM_DCM_POST_UNLOAD();
			break;			 
	}
	return MMI_RET_OK;	  
}

MMI_BOOL NeedInitAuto = MMI_FALSE; /*It is to mark if need sync nvram info*/

MMI_BOOL g_is_first_enter = MMI_TRUE;     /*It is to mark if first enter quicktest without testing*/

static void mmi_fm_reenter_auto_test(void)
{
	 NeedInitAuto = MMI_TRUE;
	
	 mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_ROOT);
	 mmi_fm_enter_auto_test();	 
}

static void mmi_frm_clearResult()
{
    U32 i;
    for (i = 0; i < g_fm_AutoTestListSize; i++)
	{
		g_fm_nvramTestResultArray.result[i] = FM_TEST_UNTESTED;
	}
}

/*****************************************************************************
 * FUNCTION
 *	mmi_fm_enter_auto_test
 * DESCRIPTION
 *	Enter quick test
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
static void mmi_fm_enter_auto_test(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U8 *guiBuffer;
	mmi_fm_common_struct *common_cntx;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	common_cntx = &(g_fm_contxt->common_contxt);

	 if (g_fm_contxt == NULL)
	 {
		//g_fm_contxt = MMI_FM_MALLOC(sizeof(mmi_fm_item_cntxt_struct));
		g_fm_contxt = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_FM_COMM_MEM,sizeof(mmi_fm_item_cntxt_struct));
		memset(g_fm_contxt, 0, sizeof(mmi_fm_item_cntxt_struct));
		mmi_fm_init_mem_contxt();
	 }
	 
	 //mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_ROOT);
	 if (mmi_frm_scrn_enter
	   (g_fm_gourp_id, 
		SCR_ID_FM_AUTO_TEST_ROOT, 
		NULL, 
		mmi_fm_enter_auto_test, 
		MMI_FRM_FULL_SCRN) != MMI_TRUE)
		{
			return;
		}
	

	common_cntx->autoTestMode = 1;

	guiBuffer =  mmi_frm_scrn_get_active_gui_buf();
	
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	kal_wsprintf((WCHAR *) common_cntx->EMFMUnicodeDisplayBuf,"%w\n\n\n\nEndkey: %w",
	GetString(STR_ID_FM_AUTO_TEST_ROOT),GetString(STR_GLOBAL_EXIT));
	
	ShowCategory7Screen(
		STR_ID_FM_AUTO_TEST_ROOT,
		NULL,
		STR_GLOBAL_START,
		IMG_GLOBAL_OK,
		STR_ID_FM_AUTO_TEST_REPORT,
		IMG_GLOBAL_BACK,
		(PU8) common_cntx->EMFMUnicodeDisplayBuf,
		guiBuffer);

	SetLeftSoftkeyFunction(EntryFMAutoTestStart, KEY_EVENT_UP);
	SetRightSoftkeyFunction(EntryFMAutoTestReport, KEY_EVENT_UP);

#ifdef __COSMOS_MMI_PACKAGE__    
	SetKeyUpHandler(EntryFMAutoTestReport, KEY_BACK);
#endif

	if (NeedInitAuto == TRUE)    /*Reenter quick test , need read NVRAM info*/
	{
		FM_InitAutoTest();
		NeedInitAuto = MMI_FALSE;
	}

	/* If first enter quick test and select report, the NVRAM default test reslut
	is wrong, and there is no info to justify if it is the first entry through NVRAM data.
	So add this code.
	If it is first entry of EM quick, g_fm_nvramTestResultArray.result[] should be set
	FM_TEST_UNTESTED */

	if (g_is_first_enter)
	{
		mmi_frm_clearResult();
	}
}

/*****************************************************************************
 * FUNCTION
 *	EntryFMAutoTestStart
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void EntryFMAutoTestStart(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U16 testitem;
	U8 *guiBuffer;

	mmi_fm_common_struct *common_cntx;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	/* currTestItem++; */
	common_cntx = &(g_fm_contxt->common_contxt);
	if (common_cntx->currTestItem == 0)  /* Testing just began, clear all tet results */
    {
        mmi_frm_clearResult();
		mmi_fm_ReadTimeFromNVRAM();
		g_is_first_enter = MMI_FALSE;
	}

	if (common_cntx->currTestItem < g_fm_AutoTestListSize)
	{
		/* Call test item according to the selected order */
		testitem = g_fm_nvramTestItemArray.priority[common_cntx->currTestItem];

		if (common_cntx->TestExecuted[common_cntx->currTestItem] == FALSE)	  /* prevent reentry of the same tests on interrupts */
		{
			/* Execute the test */
			//g_fm_contxt->common_contxt.NeedExitFunc = FALSE;
			(Tests[testitem].func) ();
			TONE_SetOutputVolume(255, 0);
			
			common_cntx->TestExecuted[common_cntx->currTestItem] = TRUE;
		}
	}
	else
	{
		
		mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);		
		if (mmi_frm_scrn_enter
		   (g_fm_gourp_id, 
			SCR_ID_FM_AUTO_TEST_START, 
			NULL, 
			NULL, 
			MMI_FRM_FULL_SCRN) != MMI_TRUE)
			{
				return;
			}
	  
		guiBuffer =  mmi_frm_scrn_get_active_gui_buf();
		ShowCategory7Screen(
			STR_ID_FM_AUTO_TEST_ROOT,
			NULL,//IMG_ID_FM_AUTO_TEST_ROOT,
			STR_ID_FM_AUTO_TEST_REPORT,
			IMG_GLOBAL_OK,
			STR_GLOBAL_DONE,
			IMG_GLOBAL_BACK,
			(PU8) GetString(STR_ID_FM_AUTO_TEST_ALLDONE),
			guiBuffer);

		SetLeftSoftkeyFunction(EntryFMAutoTestReport, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_fm_reenter_auto_test, KEY_EVENT_UP);
	}
}

/*****************************************************************************
 * FUNCTION
 *	FM_Handle_RTC_Stop_Key_Press
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
static void FM_Handle_RTC_Stop_Key_Press(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	g_fm_contxt->common_contxt.sequence_counter = 0;
	StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
	mmi_fm_WriteCurrentTimeToNVRAM();
	mmi_fm_reenter_auto_test();
}

/*****************************************************************************
 * FUNCTION
 *	FM_ManualTest_RTC
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void FM_ManualTest_RTC(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	CHAR uniBuf[240];
	
	U16 msec = 1000;
	U16 sec = 2;

	MYTIME t;
	rtc_format_struct currtime;

	mmi_fm_common_struct *common_cntx;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	//EntryNewScreen(SCR_ID_FM_RTC, NULL, NULL, NULL);

	common_cntx = &(g_fm_contxt->common_contxt);

	mmi_frm_scrn_close(g_fm_gourp_id,SCR_ID_FM_RTC);

		if (mmi_frm_scrn_enter
		 (g_fm_gourp_id, 
		  SCR_ID_FM_RTC, 
		  NULL,
		  NULL, 
		  MMI_FRM_FULL_SCRN) != MMI_TRUE)
		  {
		  	return;
		  }
	
	if (common_cntx->sequence_counter < sec)
	{
		common_cntx->sequence_counter++;
		StartTimer(FM_AUTO_TEST_COMMNON_TIMER, msec, FM_ManualTest_RTC);

		DTGetRTCTime(&t);

		/*
		currtime.rtc_sec = t.nSec;
		currtime.rtc_min = t.nMin;
		currtime.rtc_hour = t.nHour;
		currtime.rtc_day = t.nDay;
		currtime.rtc_mon = t.nMonth;
		*/

		//currtime = (rtc_format_struct)t;
		memcpy(&currtime,&t,sizeof(rtc_format_struct));
		
		currtime.rtc_wday = 0;
		currtime.rtc_year = (kal_uint8) (t.nYear - 2000);

		kal_wsprintf((WCHAR *) uniBuf,
		"Last RTC:\n%d.%d.%d %02d:%02d:%02d\nCurrent RTC:\n%d.%d.%d %02d:%02d:%02d\n\npoweroff in %d sec",
		2000 + g_fm_myclocktime.rtc_year,
			g_fm_myclocktime.rtc_mon,
			g_fm_myclocktime.rtc_day,
			g_fm_myclocktime.rtc_hour,
			g_fm_myclocktime.rtc_min,
			g_fm_myclocktime.rtc_sec,
			2000 + currtime.rtc_year,
			currtime.rtc_mon,
			currtime.rtc_day,
			currtime.rtc_hour,
			currtime.rtc_min,
			currtime.rtc_sec,
			sec - common_cntx->sequence_counter);

		ShowCategory7Screen(
			STR_ID_FM_AUTO_TEST_ROOT,
			NULL,//IMG_ID_FM_AUTO_TEST_ROOT,
			(U16) NULL,
			IMG_GLOBAL_OK,
			STR_GLOBAL_STOP,
			IMG_GLOBAL_BACK,
			(PU8) uniBuf,
			NULL);

		SetRightSoftkeyFunction(FM_Handle_RTC_Stop_Key_Press, KEY_EVENT_UP);
	}
	else
	{
		common_cntx->sequence_counter = 0;
		StopTimer(FM_AUTO_TEST_COMMNON_TIMER);

		mmi_fm_WriteCurrentTimeToNVRAM();
		g_fm_contxt->rtc_contxt.gFactoryAlarm = 1;
		FactorySetAlarm(3);
	}

}


void mmi_fm_set_auto_test_goback_func() 
{
		SetRightSoftkeyFunction( mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#if defined(__COSMOS_MMI_PACKAGE__)
	SetKeyUpHandler(mmi_frm_scrn_close_active_id, KEY_BACK);
#endif
}


void mmi_fm_set_auto_test_report(U32 untested, U8 *untested_items, U16 StringId, U8 *guiBuffer)
{
	U32 i = 0;

	mmi_fm_common_struct *common_cntx;

	common_cntx = &(g_fm_contxt->common_contxt);
	
	if (untested > 1)
	{
		sprintf((CHAR*) common_cntx->EMFMAsciiDisplayBuf, "\n\n%d Untested items:\n", untested);
	}
	else
	{
		sprintf((CHAR*) common_cntx->EMFMAsciiDisplayBuf, "\n\n1 Untested item:\n");
	}

	for (i = 0; i < untested; i++) 
	{
		CHAR str[40];

		if (i == untested - 1)
		{
			sprintf(str, "%d", 1 + untested_items[i]);
		}
		else
		{
			sprintf(str, "%d-", 1 + untested_items[i]);
		}

		strcat((CHAR*) common_cntx->EMFMAsciiDisplayBuf, (const CHAR*)str);
	}

	kal_wsprintf((WCHAR *) common_cntx->EMFMUnicodeDisplayBuf,
	"%w%s",
	GetString(StringId),(CHAR*) common_cntx->EMFMAsciiDisplayBuf);

	ShowCategory7Screen(
		STR_ID_FM_AUTO_TEST_REPORT,
		NULL,//IMG_ID_FM_AUTO_TEST_ROOT,
		(U16) NULL,
		IMG_GLOBAL_OK,
		STR_GLOBAL_BACK,
		IMG_GLOBAL_BACK,
		(PU8) common_cntx->EMFMUnicodeDisplayBuf,
		guiBuffer);

	SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);

   SetRightSoftkeyFunction(mmi_fm_reenter_auto_test, KEY_EVENT_UP);

}
/*****************************************************************************
 * FUNCTION
 *	EntryFMAutoTestReport
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void EntryFMAutoTestReport(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U8 *guiBuffer;
	U32 i, passed, failed, untested;
	U8 fail_items[MAX_AUTO_TEST_ITEMS];
	U8 untested_items[MAX_AUTO_TEST_ITEMS];

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
   NeedInitAuto = MMI_TRUE;

	 if (mmi_frm_scrn_enter
	     (g_fm_gourp_id, 
		   SCR_ID_FM_AUTO_TEST_REPORT, 
		   NULL, 
		   NULL, 
		   MMI_FRM_FULL_SCRN) != MMI_TRUE)
		{
			return;
		}
	 
	guiBuffer =  mmi_frm_scrn_get_active_gui_buf();
	
	for (i = 0, passed = 0, failed = 0, untested = 0; i < g_fm_AutoTestListSize; i++)
	{
		if (g_fm_nvramTestResultArray.result[i] == FM_TEST_UNTESTED)
		{
			untested_items[untested] = (U8) i;
			untested++;
		}
		else if (g_fm_nvramTestResultArray.result[i] == FM_TEST_FAILED)
		{
			fail_items[failed] = (U8) i;
			failed++;
		}
		else if (g_fm_nvramTestResultArray.result[i] >= FM_TEST_PASSED)
		{
			passed++;
		}
	}

	if (untested > 0)
	{
		mmi_fm_set_auto_test_report(untested, untested_items, STR_ID_FM_AUTO_TEST_UNFINISHED,guiBuffer);	  
	}
	else if (failed > 0)
	{
		mmi_fm_set_auto_test_report(failed, fail_items, STR_GLOBAL_FAILED, guiBuffer);
	}
	else
	{
		ShowCategory7Screen(
			STR_ID_FM_AUTO_TEST_REPORT,
			NULL,//IMG_ID_FM_AUTO_TEST_ROOT,
			STR_ID_FM_RTC,
			IMG_GLOBAL_OK,
			STR_GLOBAL_BACK,
			IMG_GLOBAL_BACK,
			(PU8) GetString(STR_ID_FM_AUTO_TEST_ALLPASSED),
			guiBuffer);

		SetLeftSoftkeyFunction(FM_ManualTest_RTC, KEY_EVENT_UP);
	   SetRightSoftkeyFunction(mmi_fm_reenter_auto_test, KEY_EVENT_UP);
	}

}

/*****************************************************************************
 * FUNCTION
 *	InitFactoryModeSetting
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void InitFactoryModeSetting(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	gCurrentMode = FACTORY_MODE;
	mdi_audio_suspend_background_play();
	mdi_audio_stop_all();
	srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_STOP);
}


/*****************************************************************************
 * FUNCTION
 *	FM_Autotest_test_done_USC2string
 * DESCRIPTION
 *	
 * PARAMETERS
 *	name		[IN]		
 * RETURNS
 *	void
 *****************************************************************************/
extern void FM_Autotest_test_done_USC2string(const CHAR *name)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	

	mmi_fm_common_struct *common_cntx;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	 common_cntx = &(g_fm_contxt->common_contxt);
	
#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
	if (common_cntx->currentTest == FM_AUTOTEST_MEMORYCARD)
	{
		kal_wsprintf((WCHAR *) common_cntx->EMFMUnicodeDisplayBuf,
		"%s (%d/%d)\n%w.\n\nSendkey: %w\nEndkey: %w",
		(CHAR*) name,common_cntx->currTestItem + 1, g_fm_AutoTestListSize,
		g_fm_contxt->memcard_contxt.CardType,GetString(STR_ID_FM_AUTO_TEST_RETEST),GetString(STR_GLOBAL_EXIT));
	}
	else
#endif /*(defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))*/
	{
	   kal_wsprintf((WCHAR *) common_cntx->EMFMUnicodeDisplayBuf,
		   "%s (%d/%d)\n%w.\n\nSendkey: %w\nEndkey: %w",
		   (CHAR*) name,common_cntx->currTestItem + 1, g_fm_AutoTestListSize,
		   GetString(STR_GLOBAL_DONE),GetString(STR_ID_FM_AUTO_TEST_RETEST),GetString(STR_GLOBAL_EXIT));		
	}
}


/*****************************************************************************
 * FUNCTION
 *	FM_InitAutoTest
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void FM_InitAutoTest(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mmi_fm_ReadSettingsFromNVRAM(FM_SETTINGINFO);
	mmi_fm_ReadSettingsFromNVRAM(FM_RESULTINFO);
	g_fm_contxt->common_contxt.currTestItem = 0;
	for (i = 0; i < MAX_AUTO_TEST_ITEMS; i++)
	{
		g_fm_contxt->common_contxt.TestExecuted[i] = FALSE;
	}
	InitFactoryModeSetting();
}

/*****************************************************************************
 * FUNCTION
 *	mmi_fm_auto_test_delete_history_hdlr
 * DESCRIPTION
 *	
 * PARAMETERS
 *	param		[?] 	
 * RETURNS
 *	
 *****************************************************************************/
U8 mmi_fm_auto_test_delete_history_hdlr(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	gCurrentMode = NORMAL_MODE;
	mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
	mdi_audio_start_background_timer();
	mdi_audio_resume_background_play();
	srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);
	//mmi_profiles_restore_activated_profile();
	return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_LED
 * DESCRIPTION
 *	
 * PARAMETERS
 *	counter_flag:	if flag==0 then sequence_counter++ else sequence_counter = 0
 *	timer_flag:    if timer_flag == 0 then start timer,else stop timer
 *	is_show:	if is_show==0, show category
 *	is_reg_sendkey:   if is_reg_sendkey==1 register sendkey or not register
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_auto_test_common(U8 param ,U8 * StringId, U16 duration, FuncPtr func)
{
    U8 is_reg_sendkey = (SENDKEYFLAG == (param & SENDKEYFLAG))?1:0;        

    if(0 == (param & CONTINUSFLAG))        
    {        
        g_fm_contxt->common_contxt.sequence_counter++;        
    }
    else
    {
        g_fm_contxt->common_contxt.sequence_counter = 0;
        
    }

    if(0 == (param & STOPFLAG))
    {
        StartTimer(FM_AUTO_TEST_COMMNON_TIMER, duration, func); 
    }
    else
    {
        StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    }    
    
    if(0 == (param & SHOWSCRNFLAG))
    {
        ShowCategory7Screen(
				STR_ID_FM_AUTO_TEST_ROOT,
				NULL,//IMG_ID_FM_AUTO_TEST_ROOT,
				STR_ID_FM_AUTO_TEST_PASS,
				IMG_GLOBAL_OK,
				STR_ID_FM_AUTO_TEST_FAIL,
				IMG_GLOBAL_BACK,
				(U8*) StringId,
				NULL);
    }    
	FM_Autotest_set_key_handlers(is_reg_sendkey);    
}


#ifdef __SUPPORT_LED_FEATURE__

#define MMI_FM_QUICK_TEST_LED

static void mmi_fm_enter_quick_test_led(void);


static void FM_AutoTest_LED(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	mmi_fm_enter_quick_test_led();
}



/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_LED
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_quick_test_led(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
    S8 *StringInfo = NULL;
    U8  UcTestInfo = NOSENDKEY_CNT_START_SHOW;
    U16 UsDuration = LED_DURATION;
    FuncPtr FMAutoLEDFunc = FM_AutoTest_LED;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	if (mmi_frm_scrn_enter
	   (g_fm_gourp_id, 
		SCR_ID_FM_AUTO_TEST_START, 
		NULL, 
		mmi_fm_enter_quick_test_led, 
		MMI_FRM_FULL_SCRN) != MMI_TRUE)
		{
			return;
		}
	
	g_fm_contxt->common_contxt.currentTest = FM_TEST_LED;
	
	switch (g_fm_contxt->common_contxt.sequence_counter)
	{
		case 0:
			FM_SetGpioReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
            StringInfo = (U8*)GetString(STR_ID_FM_AUTOTEST_LED_R);
			break;
		case 1:
			FM_SetGpioReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
			FM_SetGpioReq(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL5);
            StringInfo = (U8*)GetString(STR_ID_FM_AUTOTEST_LED_G);
			break;
		case 2:
			FM_SetGpioReq(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
			FM_SetGpioReq(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL5);
            StringInfo = (U8*)GetString(STR_ID_FM_AUTOTEST_LED_B);
			break;
		default:
			FM_SetGpioReq(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);
			FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_LED].name);
            
            UcTestInfo = SENDKEY_UNCNT_STOP_SHOW;
            StringInfo = g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf;
            UsDuration = 0;
            FMAutoLEDFunc = NULL;		  
	}
    
    mmi_fm_auto_test_common(UcTestInfo, StringInfo, UsDuration, FMAutoLEDFunc);
}

#endif /* __SUPPORT_LED_FEATURE__ */

#define MMI_FM_QUICK_TEST_CLAM

static void mmi_fm_enter_quick_test_clam(void);

void FM_AutoTest_CLAM(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	mmi_fm_enter_quick_test_clam();
	
}


/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_CLAM
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_quick_test_clam(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
   // EntryNewScreen(SCR_ID_FM_AUTO_TEST_START, ExitFMAutoTestStart, NULL, NULL);

	
	if (mmi_frm_scrn_enter
	   (g_fm_gourp_id, 
		SCR_ID_FM_AUTO_TEST_START, 
		NULL, 
		mmi_fm_enter_quick_test_clam, 
		MMI_FRM_FULL_SCRN) != MMI_TRUE)
		{
			return;
		}

	g_fm_contxt->common_contxt.currentTest = FM_TEST_CLAM_DETECT;

	switch (g_fm_contxt->common_contxt.sequence_counter)
	{
		case 0:
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_CLAM),CLAM_DURATION,FM_AutoTest_CLAM);
			break;
		default:
			FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_CLAM].name);
			
			mmi_fm_auto_test_common(SENDKEY_UNCNT_STOP_SHOW,(U8*)g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf,0,NULL);
	}
}

#define MMI_FM_QUICK_TEST_VERSION


static void mmi_fm_enter_quick_test_version(void);

void FM_AutoTest_Version(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	mmi_fm_enter_quick_test_version();
}


/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_Version
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_quick_test_version(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)
	version_struct ver_struct;
#endif 

	mmi_fm_common_struct *common_cntx;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
   common_cntx = &(g_fm_contxt->common_contxt);
   

	if (mmi_frm_scrn_enter
		   (g_fm_gourp_id, 
			SCR_ID_FM_AUTO_TEST_START, 
			NULL, 
			mmi_fm_enter_quick_test_version, 
			MMI_FRM_FULL_SCRN) != MMI_TRUE)
	{
		return;
	}

	common_cntx->currentTest = FM_TEST_SW_VERSION;

	switch (common_cntx->sequence_counter)
	{
		case 0:

			
#if defined(__MTK_TARGET__)
			/* Get sturctured version number */
			INT_VersionNumbers(&ver_struct);

			/* MCU (SW Ver.) */
			memcpy(common_cntx->EMFMAsciiDisplayBuf, (CHAR*) ver_struct.mcu_sw, MAX_TEST_STRING_BUF - 2);
			mmi_asc_to_ucs2((CHAR*) common_cntx->EMFMUnicodeDisplayBuf, (CHAR*) g_fm_contxt->common_contxt.EMFMAsciiDisplayBuf);



#else /* defined(__MTK_TARGET__)) */ 
			/* For PC Simulatior */
			mmi_asc_to_ucs2((CHAR*) common_cntx->EMFMUnicodeDisplayBuf, (CHAR*) "MTK_SW.V0");
#endif /* defined(__MTK_TARGET__)) */ 

			mmi_fm_auto_test_common(SENDKEY_CNT_START_SHOW, (U8*)common_cntx->EMFMUnicodeDisplayBuf,VERSION_DURATION,FM_AutoTest_Version);

		break;
		default:
			FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_VERSION].name);
			mmi_fm_auto_test_common(SENDKEY_UNCNT_STOP_SHOW, (U8*)common_cntx->EMFMUnicodeDisplayBuf,0,NULL); 				
	}
}

#define MMI_FM_QUICK_TEST_BACKLIGHT

static void mmi_fm_enter_quick_test_backlight(void);

void FM_AutoTest_Backlight(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	mmi_fm_enter_quick_test_backlight();
}

/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_Backlight
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_quick_test_backlight(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
   // EntryNewScreen(SCR_ID_FM_AUTO_TEST_START, ExitFMAutoTestStart, NULL, NULL);

		if (mmi_frm_scrn_enter
		   (g_fm_gourp_id, 
			SCR_ID_FM_AUTO_TEST_START, 
			NULL, 
			mmi_fm_enter_quick_test_backlight, 
			MMI_FRM_FULL_SCRN) != MMI_TRUE)
			{
				return;
			}

	g_fm_contxt->common_contxt.currentTest = FM_TEST_BACKLIGHT;

	switch (g_fm_contxt->common_contxt.sequence_counter)
	{
		case 0:
		   

			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_BACKLIGHT),BACKLIGHT_DURATION,FM_AutoTest_Backlight);
			
			break;
			
		case 1: 		   
			FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
			FM_SetGpioReq(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL0);
			
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_BACKLIGHT),BACKLIGHT_DURATION,FM_AutoTest_Backlight);

			break;
			
		case 2:
			FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);

			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_BACKLIGHT),BACKLIGHT_DURATION,FM_AutoTest_Backlight);

			break;
			
		case 3:
			
			FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
			FM_SetGpioReq(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL5);

		  
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_BACKLIGHT),BACKLIGHT_DURATION,FM_AutoTest_Backlight);

			break;
			
		default:
			FM_SetGpioReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
			FM_SetGpioReq(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL0);

			FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_BACKLIGHT].name);
			
			mmi_fm_auto_test_common(SENDKEY_UNCNT_STOP_SHOW,(U8*)g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf,0,NULL);
			
	}

}

#define MMI_FM_QUICK_TEST_KEYPAD

/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_Keypad
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void FM_AutoTest_Keypad(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_fm_common_struct *common_cntx;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	common_cntx = &(g_fm_contxt->common_contxt);
#ifdef __MMI_FM_KEYPAD_TEST__
	common_cntx->currentTest = FM_TEST_KEYPAD;
	mmi_fm_select_keypad_test();
#else
	g_fm_nvramTestResultArray.result[common_cntx->currTestItem] = FM_TEST_PASSED;
	common_cntx->currTestItem++;
	mmi_fm_WriteTestResultToNVRAM();
	EntryFMAutoTestStart();
#endif
}

#define MMI_FM_QUICK_TEST_LCD
#ifndef __MMI_MAINLCD_96X64__
/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_LCD
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void FM_AutoTest_LCD(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	g_fm_contxt->common_contxt.currentTest = FM_TEST_LCD;

	g_fm_contxt->common_contxt.sequence_counter = 0;
	mmi_fm_handle_color_set_change();
}
#endif /* __MMI_MAINLCD_96X64__ */

#define MMI_FM_QUICK_TEST_RECEIVER

static void mmi_fm_enter_quick_test_receiver(void);


void FM_AutoTest_Receiver(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	mmi_fm_enter_quick_test_receiver();
}


/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_Receiver
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_quick_test_receiver(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_fm_common_struct *common_cntx;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	common_cntx = &(g_fm_contxt->common_contxt);
    
	
	if (mmi_frm_scrn_enter
	   (g_fm_gourp_id, 
		SCR_ID_FM_AUTO_TEST_START, 
		NULL, 
		mmi_fm_enter_quick_test_receiver, 
		MMI_FRM_FULL_SCRN) != MMI_TRUE)
		{
			return;
		}
	common_cntx->currentTest = FM_TEST_RECEIVER;
    

	FM_SendStopAudioReq(0);
    
	//Media_Stop();
	g_fm_contxt->eachloop_contxt.ReceiverTestOn = TRUE;
	FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
	/* play 1K tone */
	TONE_SetOutputVolume(255, 0);
	mdi_audio_play_id(TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_INFINITE);
    

	if(0 == common_cntx->sequence_counter)
	{	    
        mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_RECEIVER),RECEIVER_DURATION,FM_AutoTest_Receiver);
    }
    else
    {
       g_fm_contxt->eachloop_contxt.ReceiverTestOn = FALSE;
       FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
	   /* stop 1K tone */
	    mdi_audio_stop_id(TONE_KEY_NORMAL);
	    FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_RECEIVER].name);
	    mmi_fm_auto_test_common(SENDKEY_UNCNT_STOP_SHOW,(U8*)common_cntx->EMFMUnicodeDisplayBuf,0,NULL); 
    }
    
}

#define MMI_FM_QUICK_TEST_MIC

void mmi_fm_enter_quick_test_mic(void);


void FM_AutoTest_MIC(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	mmi_fm_enter_quick_test_mic();
}


/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_MIC
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_quick_test_mic(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_fm_common_struct *common_cntx;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
   // EntryNewScreen(SCR_ID_FM_AUTO_TEST_START, ExitFMAutoTestStart, NULL, NULL);
   common_cntx = &(g_fm_contxt->common_contxt);
    
	if (mmi_frm_scrn_enter
	   (g_fm_gourp_id, 
		SCR_ID_FM_AUTO_TEST_START, 
		NULL, 
		mmi_fm_enter_quick_test_mic, 
		MMI_FRM_FULL_SCRN) != MMI_TRUE)
		{
			return;
		}

	common_cntx->currentTest = (U8)FM_TEST_MIC;
  
	FM_SendStopAudioReq(0);
	//Media_Stop();
	g_fm_contxt->eachloop_contxt.EchoLoopTestOn = MMI_TRUE;
	FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
	/* open loopback */
	kal_sleep_task(kal_milli_secs_to_ticks(100));
	//mmi_fm_set_loopback(MMI_TRUE);
	aud_util_proc_in_med(MOD_MMI,
		mmi_fm_set_loopback,
		MMI_TRUE,
		NULL);

	switch (common_cntx->sequence_counter)
	{
		case 0:

			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_MIC),MIC_DURATION,FM_AutoTest_MIC);
				
			break;
			
		default:
			FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_MIC].name);
			mmi_fm_auto_test_common(SENDKEY_UNCNT_STOP_SHOW,(U8*)common_cntx->EMFMUnicodeDisplayBuf,0,NULL);
			
			
			g_fm_contxt->eachloop_contxt.EchoLoopTestOn = MMI_FALSE;
						/* close loopback */
			//mmi_fm_set_loopback(MMI_FALSE);
			aud_util_proc_in_med(MOD_MMI,
				mmi_fm_set_loopback,
				MMI_FALSE,
				NULL);
	}
}

#define MMI_FM_QUICK_TEST_SPEAKER

void mmi_fm_enter_quick_test_speaker(void);


void FM_AutoTest_Speaker(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	mmi_fm_enter_quick_test_speaker();
}


/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_Speaker
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_quick_test_speaker(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_fm_common_struct *common_cntx;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	//EntryNewScreen(SCR_ID_FM_AUTO_TEST_START, ExitFMAutoTestStart, NULL, NULL);
	common_cntx = &(g_fm_contxt->common_contxt);
	
	
	  
	if (mmi_frm_scrn_enter
		 (g_fm_gourp_id, 
		  SCR_ID_FM_AUTO_TEST_START, 
		  NULL, 
		  mmi_fm_enter_quick_test_speaker, 
		  MMI_FRM_FULL_SCRN) != MMI_TRUE)
	{
		return;
	}

	common_cntx->currentTest = FM_TEST_SPEAKER;

    
	FM_SendStopAudioReq(0);
	g_fm_contxt->loudspk_contxt.LoudSpkTestOn = MMI_TRUE;
	FM_SendSetAudioModeReq(AUD_MODE_LOUDSPK);

    kal_sleep_task(kal_milli_secs_to_ticks(800));
    
	// play 1K tone
	TONE_SetOutputVolume(255, 0);	
	mdi_audio_play_id(TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_INFINITE);
    
    
	switch (common_cntx->sequence_counter)
	{
		case 0:
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_SPEAKER),SPEAKER_DURATION,FM_AutoTest_Speaker);

			break;
		default:
			FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_SPEAKER].name);
			mmi_fm_auto_test_common(SENDKEY_UNCNT_STOP_SHOW,(U8*)common_cntx->EMFMUnicodeDisplayBuf,0,NULL);
			g_fm_contxt->loudspk_contxt.LoudSpkTestOn = MMI_FALSE;
			FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
			/* stop 1K tone */
			mdi_audio_stop_id(TONE_KEY_NORMAL);
			
			break;
	}
}

#define MMI_FM_QUICK_TEST_HEADSET

void mmi_fm_enter_quick_test_headset(void);


void FM_AutoTest_Headset(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	mmi_fm_enter_quick_test_headset();
}


/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_Headset
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_quick_test_headset(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_fm_common_struct *common_cntx;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
   // EntryNewScreen(SCR_ID_FM_AUTO_TEST_START, ExitFMAutoTestStart, NULL, NULL);
   common_cntx = &(g_fm_contxt->common_contxt);
	
	
	if (mmi_frm_scrn_enter
	   (g_fm_gourp_id, 
		SCR_ID_FM_AUTO_TEST_START, 
		NULL, 
		mmi_fm_enter_quick_test_headset, 
		MMI_FRM_FULL_SCRN) != MMI_TRUE)
		{
			return;
		}
		

	common_cntx->currentTest = FM_TEST_HEADSET;

    
	FM_SendStopAudioReq(0);
	//Media_Stop();
	g_fm_contxt->eachloop_contxt.HeadsetTestOn = TRUE;
	FM_SendSetAudioModeReq(AUD_MODE_HEADSET);
	// open loopback
	kal_sleep_task(kal_milli_secs_to_ticks(800));
	//mmi_fm_set_loopback(MMI_TRUE);
	aud_util_proc_in_med(MOD_MMI,
				mmi_fm_set_loopback,
				MMI_TRUE,
				NULL);
	

	switch (common_cntx->sequence_counter)
	{
		case 0:
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_HEADSET),HEADSET_DURATION,FM_AutoTest_Headset);
			
			break;
		default:

			FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_HEADSET].name);
			g_fm_contxt->eachloop_contxt.HeadsetTestOn = FALSE;

			/* set headset mode */
			FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
			/* close loopback */
			kal_sleep_task(kal_milli_secs_to_ticks(800));
			//mmi_fm_set_loopback(MMI_FALSE);
			    aud_util_proc_in_med(MOD_MMI,
				mmi_fm_set_loopback,
				MMI_FALSE,
				NULL);
			
			mmi_fm_auto_test_common(SENDKEY_CNT_STOP_SHOW,(U8*)common_cntx->EMFMUnicodeDisplayBuf,0,NULL);

	}
}

/*****************************************************************************
 * FUNCTION
 *	FM_AutoTestUpdateADCHdlr
 * DESCRIPTION
 *	
 * PARAMETERS
 *	inMsg		[?] 	
 * RETURNS
 *	void
 *****************************************************************************/
void FM_AutoTestUpdateADCHdlr(void *inMsg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	double vbat, temp;
	mmi_eq_adc_all_channel_ind_struct *adc_struct = (mmi_eq_adc_all_channel_ind_struct*) inMsg;
	mmi_fm_common_struct *common_cntx;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	common_cntx = &(g_fm_contxt->common_contxt);
	
	vbat = ((double)adc_struct->vbat) / 1000000.0;
	temp = ((double)adc_struct->bat_temp) / 1000.0;

	if (vbat < VBAT_LOWER_BOUNDARY || vbat > VBAT_UPPER_BOUNDARY)
	{
		sprintf(
			(CHAR*) common_cntx->EMFMAsciiDisplayBuf,
			"%s%4.2f V\nValid Range:\n%4.2f V - %4.2f V\n\nsuggest: FAIL",
			"vbat=",
			vbat,
			VBAT_LOWER_BOUNDARY,
			VBAT_UPPER_BOUNDARY);
	}
	else if (temp < TEMP_LOWER_BOUNDARY || temp > TEMP_UPPER_BOUNDARY)
	{
		sprintf(
			(CHAR*) common_cntx->EMFMAsciiDisplayBuf,
			"%s%4.2f C\nValid Range:\n%d C - %d C\n\nsuggest: FAIL",
			"temp=",
			temp,
			TEMP_LOWER_BOUNDARY,
			TEMP_UPPER_BOUNDARY);
	}	
	else
	{
	    sprintf((CHAR*) common_cntx->EMFMAsciiDisplayBuf, "BATTERY OK!");		
	}

	mmi_asc_to_ucs2((CHAR *) common_cntx->EMFMUnicodeDisplayBuf, (CHAR*) common_cntx->EMFMAsciiDisplayBuf);


   mmi_frm_scrn_enter
		  (g_fm_gourp_id, 
		   GLOBAL_SCR_DUMMY, 
		   NULL, 
		   NULL, 
		   MMI_FRM_FULL_SCRN);
	mmi_frm_scrn_close_active_id();

	
	mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND, 
									NULL);
	
	mmi_frm_set_single_protocol_event_handler(PRT_BATTERY_STATUS_IND, 
									(PsIntFuncPtr)BatteryStatusRsp);

	FM_SendADCStopReq();
}


#define MMI_FM_QUICK_TEST_BATTERY_CHARGER

void mmi_fm_autotest_battery_charger()
{	
	switch (g_fm_contxt->common_contxt.sequence_counter)
	{
		case 0:
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_HIDE,0,ADC_DURATION,mmi_fm_autotest_battery_charger);

			break;
		default:
			mmi_fm_auto_test_common(SENDKEY_UNCNT_STOP_HIDE,0,0,NULL);
			
	}
}


static void mmi_fm_enter_quick_test_battery(void);


/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_Battery
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void FM_AutoTest_Battery(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	g_fm_contxt->common_contxt.currentTest = FM_TEST_BATTERY;

	mmi_frm_set_single_protocol_event_handler(MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND, 
									(PsIntFuncPtr)FM_AutoTestUpdateADCHdlr);

	FM_SendADCStartReq();

    mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);

	mmi_fm_enter_quick_test_battery();
}

static void mmi_fm_enter_quick_test_battery(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_fm_common_struct *common_cntx = &(g_fm_contxt->common_contxt);

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
   
    if (mmi_frm_scrn_enter
	   (g_fm_gourp_id, 
	    SCR_ID_FM_AUTO_TEST_START, 
	    NULL, 
	    mmi_fm_enter_quick_test_battery, 
	    MMI_FRM_FULL_SCRN) != MMI_TRUE)
	  {
	 		return;
	  }

   ShowCategory7Screen(
		STR_ID_FM_AUTO_TEST_RESULT,
		NULL,//IMG_ID_FM_AUTO_TEST_ROOT,
		STR_ID_FM_AUTO_TEST_PASS,
		IMG_GLOBAL_OK,
		STR_ID_FM_AUTO_TEST_FAIL,
		IMG_GLOBAL_BACK,
		(PU8) common_cntx->EMFMUnicodeDisplayBuf,
		NULL);

	mmi_fm_autotest_battery_charger();
}


#define MMI_FM_QUICK_TEST_MELODY

void mmi_fm_enter_quick_test_melody(void);


void FM_AutoTest_Melody(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	mmi_fm_enter_quick_test_melody();
}


/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_Melody
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_quick_test_melody(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	//EntryNewScreen(SCR_ID_FM_AUTO_TEST_START, ExitFMAutoTestStart, NULL, NULL);

	
	
	if (mmi_frm_scrn_enter
	   (g_fm_gourp_id, 
		SCR_ID_FM_AUTO_TEST_START, 
		NULL, 
		mmi_fm_enter_quick_test_melody, 
		MMI_FRM_FULL_SCRN) != MMI_TRUE)
		{
			return;
		}

	g_fm_contxt->common_contxt.currentTest = FM_TEST_MELODY;


	switch (g_fm_contxt->common_contxt.sequence_counter)
	{
		case 0:
			
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_MELODY),MELODY_DURATION,FM_AutoTest_Melody);
			g_fm_contxt->eachloop_contxt.RingToneTestOn = TRUE;
			Media_SetOutputVolume(255, 0);
			/* stop MIDI */
			FM_SendStopAudioReq(0);
			/* play MIDI_1 */
			FM_SendPlayAudioReq(0);
			
			break;
		default:
			FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_MELODY].name);
			g_fm_contxt->eachloop_contxt.RingToneTestOn = FALSE;
			FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
			/* stop MIDI */
			FM_SendStopAudioReq(0);
			mmi_fm_auto_test_common(SENDKEY_UNCNT_STOP_SHOW,(U8*)g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf,0,NULL);

	}
}

#define MMI_FM_QUICK_TEST_VIB

void mmi_fm_enter_quick_test_vib(void);


void FM_AutoTest_VIB(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	mmi_fm_enter_quick_test_vib();
}

/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_VIB
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_quick_test_vib(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	//EntryNewScreen(SCR_ID_FM_AUTO_TEST_START, ExitFMAutoTestStart, NULL, NULL);

	
	if (mmi_frm_scrn_enter
	    (g_fm_gourp_id, 
		  SCR_ID_FM_AUTO_TEST_START, 
	  	NULL, 
		  mmi_fm_enter_quick_test_vib, 
	  	MMI_FRM_FULL_SCRN) != MMI_TRUE)
	  {
	  	return;
	  }

	g_fm_contxt->common_contxt.currentTest = FM_TEST_VIB;


	switch (g_fm_contxt->common_contxt.sequence_counter)
	{
		case 0:
        case 2:
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_VIB),VIB_DURATION,FM_AutoTest_VIB);
			FM_SetGpioVirbateReq(VIBRATOR_ON);
			break;	
            
		case 1:
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTO_TEST_FAIL),VIB_DURATION,FM_AutoTest_VIB);
			FM_SetGpioVirbateReq(VIBRATOR_OFF);
			break;	
            
		default:
			FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_VIB].name);
			mmi_fm_auto_test_common(SENDKEY_UNCNT_STOP_SHOW,(U8*) g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf,0,NULL);
			FM_SetGpioVirbateReq(VIBRATOR_OFF);	
	}
}


#define MMI_FM_QUICK_TEST_NAND

/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_NAND
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void FM_AutoTest_NAND(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	mmi_fm_enter_autotest_nand();
}


/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_NAND
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_autotest_nand(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/  
	if (mmi_frm_scrn_enter
	   (g_fm_gourp_id, 
		SCR_ID_FM_AUTO_TEST_START, 
		NULL, 
		mmi_fm_enter_autotest_nand, 
		MMI_FRM_FULL_SCRN) != MMI_TRUE)
		{
			return;
		}

	g_fm_contxt->common_contxt.currentTest = FM_TEST_NAND;


	switch (g_fm_contxt->common_contxt.sequence_counter)
	{
		case 0:
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_NAND),3000,FM_AutoTest_NAND);			   		
			   		
			break;
		case 1:
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_HIDE,0,2000,FM_AutoTest_NAND);		
			mmi_fm_select_nand_flash();
			break;

		default:
			FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_NAND].name);
			mmi_fm_auto_test_common(SENDKEY_UNCNT_STOP_SHOW,(U8*) g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf,0,NULL);
	}
}


#define MMI_FM_QUICK_TEST_UART

/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_UART
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
#ifdef __MMI_FM_UART_TEST__
void FM_AutoTest_UART(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
   // EntryNewScreen(SCR_ID_FM_AUTO_TEST_START, ExitFMAutoTestStart, NULL, NULL);
   mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	
	if (mmi_frm_scrn_enter
	    (g_fm_gourp_id, 
		   SCR_ID_FM_AUTO_TEST_START, 
		   NULL, 
		   FM_AutoTest_UART, 
		   MMI_FRM_FULL_SCRN) != MMI_TRUE)
	{
		return;
	}

	g_fm_contxt->common_contxt.currentTest = FM_TEST_UART;


	switch (g_fm_contxt->common_contxt.sequence_counter)
	{
		case 0:
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_UART),1000,FM_AutoTest_UART);
			
			break;
		case 1:
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_HIDE,0,2000,FM_AutoTest_UART);
			mmi_fm_select_uart();	//EntryFMUARTMenu();
					
			break;

		default:
			FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_UART].name);
			mmi_fm_auto_test_common(SENDKEY_UNCNT_STOP_SHOW,(U8*) g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf,0,NULL);
	}
}

#endif /*__MMI_FM_UART_TEST__*/

#define MMI_FM_QUICK_TEST_DOUBLE_SPEAKER

void mmi_fm_enter_quick_test_double_spk(void);


void FM_AutoTest_Double_Speaker(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
	mmi_fm_enter_quick_test_double_spk();
}




/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_Double_Speaker
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_quick_test_double_spk(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	if (mmi_frm_scrn_enter
	   (g_fm_gourp_id, 
		SCR_ID_FM_AUTO_TEST_START, 
		NULL, 
		mmi_fm_enter_quick_test_double_spk, 
		MMI_FRM_FULL_SCRN) != MMI_TRUE)
		{
			return;
		}

	g_fm_contxt->common_contxt.currentTest = FM_TEST_DOUBLE_SPEAKER;

	FM_SendStopAudioReq(0);
	//Media_Stop();
	g_fm_contxt->loudspk_contxt.LoudSpkTestOn = MMI_TRUE;
	FM_SendSetAudioModeReq(AUD_MODE_LOUDSPK);
	/* play 1K tone */
	TONE_SetOutputVolume(255, 0);

	/* sequence_counter=0; */
	switch (g_fm_contxt->common_contxt.sequence_counter)
	{
		case 0:
			mdi_audio_play_id(TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_INFINITE);
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_LEFT_SPEAKER),SPEAKER_DURATION,FM_AutoTest_Double_Speaker);

			break;
		case 1:

			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_GLOBAL_STOP),1000,FM_AutoTest_Double_Speaker);
			mdi_audio_stop_id(TONE_KEY_NORMAL);
				
			break;
		case 2:
			mdi_audio_play_id(TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_INFINITE);
			mmi_fm_auto_test_common(NOSENDKEY_CNT_START_SHOW,(U8*) GetString(STR_ID_FM_AUTOTEST_RIGHT_SPEAKER),SPEAKER_DURATION,FM_AutoTest_Double_Speaker);
				
			break;
		default:
			FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_DOUBLE_SPEAKER].name);
			mmi_fm_auto_test_common(SENDKEY_UNCNT_STOP_SHOW,(U8*) g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf,0,NULL);
			g_fm_contxt->loudspk_contxt.LoudSpkTestOn = MMI_FALSE;

			FM_SendSetAudioModeReq(AUD_MODE_NORMAL);
			/* stop 1K tone */
			mdi_audio_stop_id(TONE_KEY_NORMAL);
	}
}

#define MMI_FM_QUICK_TEST_CAMERA
#ifndef __MMI_MAINLCD_96X64__
/*****************************************************************************
 * FUNCTION
 *	EntryFMCameraTransientScreen
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
static void EntryFMCameraTransientScreen(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);  
	
	if (mmi_frm_scrn_enter
	   (g_fm_gourp_id, 
		SCR_ID_FM_AUTO_TEST_START, 
		NULL, 
		FM_AutoTest_CAMERA, 
		MMI_FRM_FULL_SCRN) != MMI_TRUE)
		{
			return;
		}
	
	FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_CAMERA].name);

	ShowCategory7Screen(
		STR_ID_FM_AUTO_TEST_RESULT,
		NULL,//IMG_ID_FM_AUTO_TEST_ROOT,
		STR_ID_FM_AUTO_TEST_PASS,
		IMG_GLOBAL_OK,
		STR_ID_FM_AUTO_TEST_FAIL,
		IMG_GLOBAL_BACK,
		(PU8) g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf,
		NULL);

	FM_Autotest_set_key_handlers(1);

}


/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_CAMERA
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void FM_AutoTest_CAMERA(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

    static U16 isRedraw = 0;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	g_fm_contxt->common_contxt.currentTest = FM_TEST_CAMERA;

#ifdef __MMI_FM_CAMERA_PREVIEW__

	switch (g_fm_contxt->common_contxt.sequence_counter)
	{
		case 0:
            if(0 == isRedraw)
            {

			g_fm_contxt->common_contxt.sequence_counter++;
			mmi_fm_camera_entry_preview_screen();
			StartTimer(FM_AUTO_TEST_COMMNON_TIMER, CAMERA_DURATION, FM_AutoTest_CAMERA);
            }
			break;
		default:
            isRedraw = 1;

			g_fm_contxt->common_contxt.sequence_counter = 0;
			StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
			mmi_fm_close_camera();
			EntryFMCameraTransientScreen();
			
            isRedraw = 0;
	}
 
#else
	{
	    EntryFMCameraTransientScreen();	
	}
#endif

}
#endif /* __MMI_MAINLCD_96X64__ */

#define MMI_FM_QUICK_TEST_MEMORYCARD

void mmi_fm_enter_quick_test_memorycard(void);



void FM_AutoTest_MemoryCard(void)
{
	mmi_frm_scrn_close(g_fm_gourp_id,SCR_ID_FM_AUTO_TEST_START);//SCR_ID_FM_MEMORY_CARD);
	mmi_fm_enter_quick_test_memorycard();
}




/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_MemoryCard
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void mmi_fm_enter_quick_test_memorycard(void)
{
#if defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	UI_character_type text1[32];
	U8 u8text[32];

	mmi_fm_memcard_struct *memcard_cntx;
#endif /* defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__) */ 

	mmi_fm_common_struct *common_cntx;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	common_cntx = &(g_fm_contxt->common_contxt);
	
	common_cntx->currentTest = FM_TEST_MEMORYCARD;

	
	if (mmi_frm_scrn_enter
		(g_fm_gourp_id,
		SCR_ID_FM_AUTO_TEST_START,//SCR_ID_FM_MEMORY_CARD,
		NULL,
		mmi_fm_enter_quick_test_memorycard,
		MMI_FRM_FULL_SCRN) != MMI_TRUE)
		{
			return;
		}

   // EntryNewScreen(SCR_ID_FM_MEMORY_CARD, NULL, FM_AutoTest_MemoryCard, NULL);

#if defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)
	memcard_cntx = &(g_fm_contxt->memcard_contxt);

	if (common_cntx->sequence_counter < 6)
	{
		if (memcard_cntx->FM_Card_Status.present == TRUE)
		{
			common_cntx->sequence_counter = 6;
			switch (memcard_cntx->FM_Card_Status.type)
			{
				case MS_CARD:
					mmi_asc_to_ucs2((CHAR*) memcard_cntx->CardType, "MS_CARD.");
					break;
				case SD_CARD:
					mmi_asc_to_ucs2((CHAR*) memcard_cntx->CardType, "SD_CARD.");
					break;
				case MMC_CARD:
					mmi_asc_to_ucs2((CHAR*) memcard_cntx->CardType, "MMC_CARD.");
					break;
				default:
					mmi_asc_to_ucs2((CHAR*) memcard_cntx->CardType, "Error!!!");
			}
			StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 300, FM_AutoTest_MemoryCard);
		}
		else
		{
			common_cntx->sequence_counter++;

			if (memcard_cntx->Card_Response_Sent == FALSE)
			{
				FM_MemoryCardReq();
			}

			sprintf(
				(CHAR*) u8text,
				"\nPlease Insert Memory Card....%d",
				(MEMORYCARD_DURATION / 1000) - common_cntx->sequence_counter);
			mmi_asc_to_ucs2((CHAR*) text1, (CHAR*) u8text);

			
			ShowCategory7Screen(
				STR_GLOBAL_MEMORY_CARD,
				NULL,
				STR_ID_FM_AUTO_TEST_PASS,
				0,
				STR_ID_FM_AUTO_TEST_FAIL,
				0,
				(PU8) text1,
				NULL);
							  
			FM_Autotest_set_key_handlers(1);

			StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 1000, FM_AutoTest_MemoryCard);
			if ((common_cntx->sequence_counter >= (MEMORYCARD_DURATION / 1000) - 1) && memcard_cntx->FM_Card_Status.present == FALSE)
			{	/* No Card inserted. */
				mmi_asc_to_ucs2((CHAR*) memcard_cntx->CardType, "No Card.");

                //StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
				//StartTimer(FM_AUTO_TEST_COMMNON_TIMER, 300, FM_AutoTest_MemoryCard);
				//common_cntx->sequence_counter++;

				common_cntx->sequence_counter = 6;
			}
		}
	}
	else
#endif /* defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__) */ 
	{
		common_cntx->sequence_counter = 0;
		StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
		FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_MEMORYCARD].name);
		ShowCategory7Screen(
			STR_ID_FM_AUTO_TEST_RESULT,
			NULL,//IMG_ID_FM_AUTO_TEST_ROOT,
			STR_ID_FM_AUTO_TEST_PASS,
			IMG_GLOBAL_OK,
			STR_ID_FM_AUTO_TEST_FAIL,
			IMG_GLOBAL_BACK,
			(PU8) common_cntx->EMFMUnicodeDisplayBuf,
			NULL);

		FM_Autotest_set_key_handlers(1);
	}
}

#define MMI_FM_QUICK_TEST_TOUCH_SCREEN


#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *	FM_AutoTest_Pen_Parallel_Test
 * DESCRIPTION
 *	This function is for Parallel line Test in Auto Test mode
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void FM_AutoTest_Pen_Parallel_Test(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	g_fm_contxt->common_contxt.currentTest = FM_TEST_PEN_PARALLEL_LINES;
	mmi_fm_select_pen_parallel_test();
}

#endif /*__MMI_TOUCH_SCREEN__*/


/*****************************************************************************
 * FUNCTION
 *	EntryFMMenuAutoTestProcess
 * DESCRIPTION
 *	
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void EntryFMMenuAutoTestProcess(void)
{
    /*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    InitFactoryModeEvent();
    
	/* Disable tone internal */
	gui_touch_feedback_disable_tone_internal();
	gui_touch_feedback_disable_vibrate_internal();
	
	/* create group and init ASM  */	
	g_fm_contxt = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_FM_COMM_MEM,sizeof(mmi_fm_item_cntxt_struct));
	
	if (g_fm_contxt == NULL)
	{
		DisplayPopup((PU8) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY), NULL, 0, 1000, 0);
        MMI_FM_DCM_POST_UNLOAD();
		return; 		   
	}
	
	g_fm_gourp_id = mmi_frm_group_create(GRP_ID_ROOT,
					   GRP_ID_AUTO_GEN, mmi_fm_auto_test_group_proc, NULL);
	mmi_frm_group_enter(g_fm_gourp_id, MMI_FRM_NODE_NONE_FLAG);
	
	if (g_fm_contxt != NULL)
	{
	   memset(g_fm_contxt, 0, sizeof(mmi_fm_item_cntxt_struct));
	   mmi_fm_init_mem_contxt();
	}

	FM_InitAutoTest();
	/* Enter auto test */
	mmi_fm_enter_auto_test();
}


#if (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__))
#pragma arm section rodata , code
#endif /* (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)) */


/*****************************************************************************
 * FUNCTION
 *	EntryFMMenuAutoTest
 * DESCRIPTION
 *	extern API. *#87#
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
extern void EntryFMMenuAutoTest(void)
{
    /*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    
    MMI_FM_DCM_LOAD();
    
    EntryFMMenuAutoTestProcess();
}
#endif
