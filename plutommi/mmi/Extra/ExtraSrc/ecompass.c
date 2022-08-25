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
 * ecompass.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements ecompass application.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/***************** Ecompass Application implementation *********************/

/**************************************************************

   FILENAME    : ecompass.c

   PURPOSE     : ecompass application implementation

   REMARKS     : nil

   AUTHOR      : Manpreet Singh

   DATE        : 05/01/2009

**************************************************************/
#include "MMI_features.h"

#ifdef __MMI_ECOMPASS__
#include "ProtocolEvents.h"
//#include "CommonScreens.h"
//#include "mmi_rp_app_mainmenu_def.h"
//#include "ProfileGprots.h"
//#include "IdleAppDef.h"
#include "app_str.h"
//#include "IdleAppProt.h"
//#include "EcompassResDef.h"
#include "EcompassProt.h"
#include "EcompassDef.h"
#include "Gui_inputs.h"
//#include "gpioInc.h"
#include "E_compass_sensor.h"
#include "Mmi_msg_struct.h"
#include "Mmi_frm_scenario_gprot.h"
#include "Menucuigprot.h"
#include "Inlinecuigprot.h"
//#include "inlinecui.h"
//#include "CommonScreens.h"

/* RHR additions*/

#include "mmi_rp_app_ecompass_def.h"
#include "MMIDataType.h"
#include "AlertScreen.h"
#include "GlobalConstants.h"
#include "ImeGprot.h"
#include "GlobalResDef.h"
#include "MMI_common_app_trc.h"
#include "mmi_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "ec_nvram_header.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "stack_config.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_popup.h"
#include "CustDataRes.h"
#include "custom_events_notify.h"
#include "gui_data_types.h"
#include "mmi_frm_gprot.h"
#include "wgui_categories.h"
#include "Unicodexdcl.h"
#include "wgui_categories_list.h"
#include "PixcomFontEngine.h"
#include "wgui_inputs.h"
#include "custom_mmi_default_value.h"
#include "CommonScreensResDef.h"
#include "wgui_inline_edit.h"
#include "gui.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "IdleGprot.h"

mmi_ecompass_cntxt_struct g_ecompass_cntxt;

//g_ecompass_cntxt.DirectionList[MMI_EC_DRC_EAST] = (S8*) GetString(STR_ID_EC_EAST);
//g_ecompass_cntxt.DirectionList[MMI_EC_DRC_WEST] = (S8*) GetString(STR_ID_EC_WEST);

U16 g_direction_list[2] = {STR_ID_EC_EAST,STR_ID_EC_WEST};


/* prabhjot changed U32 to S8 */
S8 g_ecompass_number_buffer[MMI_EC_MAX_ANGLE * ENCODING_LENGTH];
mmi_ret mmi_ec_main_grp_proc(mmi_event_struct *evt);
mmi_ret mmi_ec_information_grp_proc(mmi_event_struct *evt);
mmi_ret mmi_ec_direction_grp_proc(mmi_event_struct *evt);
mmi_ret mmi_ec_options_proc(mmi_event_struct *evt);
mmi_ret mmi_ec_set_city_proc(mmi_event_struct *evt);
mmi_ret mmi_ec_dec_inline_proc(mmi_event_struct *evt);
mmi_ret mmi_ec_app_leave_proc(mmi_event_struct *evt);
mmi_ret mmi_ec_entry_frm_maual_calib_proc(mmi_event_struct *evt);
void mmi_ecompass_cancel_cali_entry_main_direction_screen(void);
mmi_ret mmi_ec_manual_calib_popup_callback(mmi_alert_result_evt_struct *evt);


void mmi_ecompass_get_calibration_status_callback(void *parameter, E_Compass_Sensor_Cali_Result_enum cali_result);
void mmi_ecompass_get_data_callback(void *parameter, E_Compass_Sensor_BuffState_enum state);

extern const S16 g_ecompass_deg_mecca[MMI_EC_MAX_CITIES];
extern const U16 g_ecompass_country_indices[MMI_EC_MAX_COUNTRIES + 1];
extern const U8 g_ecompass_country_multitap[MMI_EC_MULTITAP_COUNTRIES];
U8 hint_string[MMI_EC_HINTS_TOTAL][MAX_SUB_MENU_HINT_SIZE];
U8 g_hilited_city_index;/*variable to maintian the highlighted city index on the city screen*/
U8 g_set_city_gid;
U8 g_inline_id;
U8 g_options_scr_gid;

/*Below is the data set for inline decliantion screen */

#define ECOMPASS_DEC_ANGLE_MEASURE_CAPTION         (CUI_INLINE_ITEM_ID_BASE + 0)
#define ECOMPASS_DEC_ANGLE_MEASURE_EDIT            (CUI_INLINE_ITEM_ID_BASE + 1)
#define ECOMPASS_DEC_DIRECTION_CAPTION             (CUI_INLINE_ITEM_ID_BASE + 2)
#define ECOMPASS_DEC_DIRECTION_OPTION              (CUI_INLINE_ITEM_ID_BASE + 3)

static const cui_inline_item_caption_struct caption_dec_measure =  
{
    STR_ID_EC_DEC_ANGLE
};


static const cui_inline_item_text_edit_struct edit_dec_measure = 
{
    0, 0, MMI_EC_MAX_ANGLE, IMM_INPUT_TYPE_NUMERIC, NULL , NULL
};

static const cui_inline_item_caption_struct caption_direction = {STR_ID_EC_DEC_DIR};

static const cui_inline_item_select_struct direction_option = {MMI_EC_DRC_TOTAL, 0, g_direction_list}; 

static cui_inline_item_softkey_struct app_inline_softkey = {{
			                   {STR_GLOBAL_OK, 0}, 
			                   {STR_GLOBAL_BACK, 0},
			                   {0, IMG_GLOBAL_COMMON_CSK} }};

static const cui_inline_set_item_struct ec_inline_data[ ] =
{
    {ECOMPASS_DEC_ANGLE_MEASURE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void *)&caption_dec_measure},         
    {ECOMPASS_DEC_ANGLE_MEASURE_EDIT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_RIGHT_JUSTIFY, 0, (void *)&edit_dec_measure},
    
    {ECOMPASS_DEC_DIRECTION_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void *)&caption_direction},
    {ECOMPASS_DEC_DIRECTION_OPTION, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void *)&direction_option},
           
};    

static const cui_inline_struct g_initial_inline_data = {
    sizeof(ec_inline_data) / sizeof(cui_inline_set_item_struct),   /* item count */
    STR_ID_EC_SET_DEC,                                                                  /* screen title string id */

    #ifdef __MMI_FTE_SUPPORT__  	/* screen title icon id */
	0,
	#else
	IMG_ID_EC_ICON,
	#endif

    CUI_INLINE_SCREEN_DISABLE_DONE,  /* screen attribute, set flag what you want */   
    &app_inline_softkey,  /* if you want to set all softkey the same label/icon, you can set here */
    ec_inline_data  /* item special data array. */
};

/*Above is the data set for inline declination screen*/


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_init_app
 * DESCRIPTION
 *  Initialize Ecompass Application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* set hint handler */
	//SetHintHandler(ECOMPASS_OPTIONS_SET_DECLINATION, mmi_ecompass_hint_declination_menu);
	//SetHintHandler(ECOMPASS_OPTIONS_SET_LOCATION, mmi_ecompass_hint_location_menu);

	/* initialize NVRAM */
    mmi_ecompass_nvram_initialization();
	/* set protocol handlers */
    mmi_ecompass_set_protocols();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_nvram_initialization
 * DESCRIPTION
 *  Initialize Ecompass Application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_nvram_initialization(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 declination_array[MMI_EC_NUM_NVRAM_RECORDS] = {0};
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_INIT_EC_APP_START);
    memset(&g_ecompass_cntxt, 0, sizeof(g_ecompass_cntxt));

    /* get current selected city, get value from NVRAM */
    mmi_ecompass_get_current_city_nvram();

    /* get declination angle for that city, if less 250 index, read first record, otherwise read second record */
    if (g_ecompass_cntxt.curr_city_index < MMI_EC_NUM_NVRAM_RECORDS)
    {
        ReadRecord(NVRAM_EF_ECOMPASS_LID, 1, declination_array, NVRAM_EF_ECOMPASS_SIZE, &error);
        g_ecompass_cntxt.declination_angle = declination_array[g_ecompass_cntxt.curr_city_index];
    }
    else if ((g_ecompass_cntxt.curr_city_index >= MMI_EC_NUM_NVRAM_RECORDS) &&
             g_ecompass_cntxt.curr_city_index < MMI_EC_MAX_CITIES)
    {
        ReadRecord(NVRAM_EF_ECOMPASS_LID, 2, declination_array, NVRAM_EF_ECOMPASS_SIZE, &error);
        g_ecompass_cntxt.declination_angle =
            declination_array[g_ecompass_cntxt.curr_city_index - MMI_EC_NUM_NVRAM_RECORDS];
    }
    else
    {
        /* if record is greater than MAX, assert */
        ASSERT(0);
    }

    MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_INIT_EC_APP_FINISH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_set_protocols
 * DESCRIPTION
 *  Set protocols at entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_set_protocols(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_INIT_EC_APP_START);
   
    /* register calibration and data update callback */
    e_compass_sensor_cali_cb_registration(mmi_ecompass_get_calibration_status_callback, NULL);  /* cali status registration */
    e_compass_sensor_data_cb_registration(mmi_ecompass_get_data_callback, NULL);        /* data callback registration */

    /* set protocol handlers */
    SetProtocolEventHandler(mmi_ecompass_get_calibration_status_handler, MSG_ID_MMI_EC_CALI_STATE_IND);
    SetProtocolEventHandler(mmi_ecompass_get_data_update, MSG_ID_MMI_EC_DATA_VALUE_IND);

    MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_INIT_EC_APP_FINISH);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEcompassMenu
 * DESCRIPTION
 *  Highlight handler fn for ecompass.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEcompassMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
	
    EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_ecompass_entry_clb_choice_screen, KEY_EVENT_UP); 

    SetLeftSoftkeyFunction(mmi_ecompass_entry_clb_choice_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_ecompass_entry_clb_choice_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  HighlightEcompassLocationMenu
 * DESCRIPTION
 *  Select country highlight function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEcompassLocationMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_ecompass_entry_options_location_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  HighlightEcompassDeclinationMenu
 * DESCRIPTION
 *  Highlight function for declination angle input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEcompassDeclinationMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_ecompass_entry_options_declination_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  HighlightEcompassCalibrateMenu
 * DESCRIPTION
 *  Manual calibration highlight function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEcompassCalibrateMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_ecompass_entry_options_cali_manual_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_entry_clb_choice_screen
 * DESCRIPTION
 *  Entry fn for calibration choice screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_entry_clb_choice_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	U16 img_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_EC_MAIN, mmi_ec_main_grp_proc ,(void *)NULL);
    mmi_frm_group_enter(GRP_ID_EC_MAIN, MMI_FRM_NODE_NONE_FLAG);

    //EntryNewScreen(SCR_ID_EC_CLB_CHOICE, NULL, mmi_ecompass_entry_clb_choice_screen, NULL);

    if(mmi_frm_scrn_enter(
       GRP_ID_EC_MAIN, 
       SCR_ID_EC_CLB_CHOICE, 
       NULL, 
       mmi_ecompass_entry_clb_choice_screen, 
       MMI_FRM_FULL_SCRN))
    {
    	guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_EC_MAIN,SCR_ID_EC_CLB_CHOICE);
     
    e_compass_sensor_power_on();
    kal_prompt_trace(MOD_MMI, "Power On driver....");

    mmi_ecompass_init_app();
    kal_prompt_trace(MOD_MMI, "InitEcompassApp()");

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#ifdef __MMI_FTE_SUPPORT__
		img_id = 0;
#else
		img_id = IMG_ID_EC_ICON,;
#endif

	ShowCategory21Screen(
        STR_ID_EC_CALIBRATION,		
		img_id,		
        STR_GLOBAL_YES,
        IMG_GLOBAL_OK,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_EC_CHOICE,
        guiBuffer);

	SetCenterSoftkeyFunction(mmi_ecompass_entry_information_screen, KEY_EVENT_UP); 
    SetLeftSoftkeyFunction(mmi_ecompass_entry_information_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_ecompass_entry_main_from_clb_choice, KEY_EVENT_UP);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ec_main_grp_choice
 * DESCRIPTION
 *  Proc function for ecompass group
 * PARAMETERS
 *  Event type  - mmi_event_struct *evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ec_main_grp_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        
        case EVT_ID_SCRN_GOBACK :
            break;

        case EVT_ID_GROUP_DEINIT:
            //mmi_ecompass_deinitialize();
			break;

		case EVT_ID_GROUP_EXIT:            
			break;

		case EVT_ID_GROUP_INACTIVE:
			break;

		case EVT_ID_GROUP_GOBACK:
			break;
			
    	default:
    	  	break;
    }
    return MMI_RET_OK;	
	   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_entry_main_from_clb_choice
 * DESCRIPTION
 *  Entry fn for rotation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_entry_main_from_clb_choice(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	e_compass_sensor_manual_init();                 /*  init driver when user denies to calibrate at entry */
    g_ecompass_cntxt.sgnstn = MMI_EC_SIGSTN_WEAK;   /* by default it is weak if no calibration done */

    mmi_ecompass_entry_direction_main_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_entry_information_screen
 * DESCRIPTION
 *  Entry fn for rotation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_entry_information_screen(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	U16 img_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //EntryNewScreen(SCR_ID_EC_ROTATION, NULL, mmi_ecompass_entry_information_screen, NULL);

    //mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_EC_INFORMATION, mmi_ec_information_grp_proc ,(void *)NULL);
    //mmi_frm_group_enter(GRP_ID_EC_INFORMATION, MMI_FRM_NODE_NONE_FLAG);

    if(mmi_frm_scrn_enter(
       GRP_ID_EC_MAIN, 
       SCR_ID_EC_ROTATION, 
       NULL, 
       mmi_ecompass_entry_information_screen, 
       MMI_FRM_FULL_SCRN))
    {

    /* delete calibration choice screen when reach information screen */
       //DeleteScreenIfPresent(SCR_ID_EC_CLB_CHOICE);
       mmi_frm_scrn_close(GRP_ID_EC_MAIN, SCR_ID_EC_CLB_CHOICE);

       //guiBuffer = GetCurrGuiBuffer(SCR_ID_EC_ROTATION);
       guiBuffer = mmi_frm_scrn_get_gui_buf (GRP_ID_EC_MAIN, SCR_ID_EC_ROTATION);	

    e_compass_sensor_manual_init();                 /*  in case user changes his location we need to call this function to get initial data */

    g_ecompass_cntxt.sgnstn = MMI_EC_SIGSTN_WEAK;   /* by default it is weak if no calibration done */

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#ifdef __MMI_FTE_SUPPORT__
			img_id = 0;
#else
			img_id = IMG_ID_EC_ICON,;
#endif

    ShowCategory21Screen(
        STR_ID_EC_CALIBRATION,
        img_id,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        STR_ID_EC_ROTATION,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_ecompass_start_cali_show_processing, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_ecompass_start_cali_show_processing, KEY_EVENT_UP);
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ec_information_grp_proc
 * DESCRIPTION
 *  Proc function for ecompass informatio screen group
 * PARAMETERS
 *  Event type  - mmi_event_struct *evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ec_information_grp_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {		
    	default:
    	  	break;
    }
    return MMI_RET_OK;	
	   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_start_cali_show_processing
 * DESCRIPTION
 *  To start calibration at driver end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_start_cali_show_processing(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_CALI_STARTED);
 
    /* call driver API to start calibration */
	/* on completion of calibration, driver will send CALI_FINISHED indication */
    e_compass_sensor_start_cali();

	/* show processing screen */
    mmi_ecompass_entry_processing_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_entry_processing_screen
 * DESCRIPTION
 *  Entry fn for Animation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_entry_processing_screen(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_frm_scrn_enter(
       GRP_ID_EC_MAIN, 
       SCR_ID_EC_ANIMATION, 
       NULL, 
       mmi_ecompass_entry_processing_screen, 
       MMI_FRM_SCRN_GROUP))
    {
		//EntryNewScreen(SCR_ID_EC_ANIMATION, NULL, mmi_ecompass_entry_processing_screen, NULL);

    /* delete information screen when reach processing screen */
	    //DeleteScreenIfPresent(SCR_ID_EC_ROTATION);
        mmi_frm_scrn_close(GRP_ID_EC_MAIN, SCR_ID_EC_ROTATION);

    /* delete main direction screen if exists, remember to clear the delete screen callback handler before deleting screen */

        mmi_frm_scrn_set_leave_proc (GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION, NULL);
		//SetDelScrnIDCallbackHandler(SCR_ID_EC_DIRECTION, (HistoryDelCBPtr) NULL);

		//if (IsScreenPresent(SCR_ID_EC_DIRECTION))        
		if (mmi_frm_scrn_is_present (GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION, MMI_FRM_NODE_ALL_FLAG))
	{
            mmi_frm_scrn_close(GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION);
			//DeleteNScrId(SCR_ID_EC_DIRECTION);
    }

        guiBuffer = mmi_frm_scrn_get_gui_buf (GRP_ID_EC_MAIN, SCR_ID_EC_ANIMATION);	
	    //guiBuffer = GetCurrGuiBuffer(SCR_ID_EC_ANIMATION);
#ifdef __MMI_FTE_SUPPORT__
	img_id = 0;
#else
	img_id = IMG_ID_EC_ICON,;
#endif


    ShowCategory66Screen(
        STR_ID_EC_CALIBRATION,
        img_id,
        0,
        0,
        STR_GLOBAL_ABORT,
        IMG_GLOBAL_BACK,
        (PU8) GetString(STR_ID_EC_CALIBRATING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        guiBuffer);
	
    SetRightSoftkeyFunction(mmi_ecompass_cancel_cali_processing_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_ecompass_cancel_cali_go_to_idle, KEY_END, KEY_EVENT_DOWN);

	/* prabhjot : set delete screen callback handler to deinitialize ecompass in case processing screen is deleted by pressing END key */
        mmi_frm_scrn_set_leave_proc (GRP_ID_EC_MAIN, SCR_ID_EC_ANIMATION, mmi_ec_app_leave_proc);
		//SetDelScrnIDCallbackHandler(SCR_ID_EC_ANIMATION, (HistoryDelCBPtr) mmi_ecompass_deinitialize);
    }
}


/*****************************************************************************
 * FUNCTION
 mmi_ec_app_leave_proc
 * DESCRIPTION
 *  Leave proc fo animation screen for the Ecompass feature
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_ec_app_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     switch (evt->evt_id)
    {
        case EVT_ID_GROUP_EXIT:
            mmi_ecompass_deinitialize();
            break;

		//case EVT_ID_SCRN_DELETE_REQ:
			//mmi_ecompass_deinitialize();
       
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_cancel_cali_processing_screen
 * DESCRIPTION
 *  Entry fn for Main direction screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_cancel_cali_processing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	e_compass_sensor_cancel_cali();

        do {
	mmi_popup_property_struct arg;
	mmi_popup_property_init(&arg);
	arg.callback = mmi_alert_normal_exit_helper;
	arg.user_tag = (void *)(mmi_ecompass_cancel_cali_entry_main_direction_screen);
	mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_EC_CALI_ABORTED)), MMI_EVENT_SUCCESS, &arg);
	} while(0);

	//mmi_display_popupcallback(
        //    (UI_string_type)GetString(STR_ID_EC_CALI_ABORTED), 
        //    MMI_EVENT_SUCCESS, 
        //mmi_ecompass_cancel_cali_entry_main_direction_screen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_cancel_cali_entry_main_direction_screen
 * DESCRIPTION
 *  pre netry function for main direction screen from processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_cancel_cali_entry_main_direction_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //mmi_frm_scrn_close_active_id();	
    mmi_frm_group_close(g_options_scr_gid);
    //mmi_frm_group_close(GRP_ID_EC_INFORMATION);
	mmi_ecompass_entry_direction_main_screen();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_cancel_cali_go_to_idle
 * DESCRIPTION
 *  callback function to show ecompass popup and go back idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_cancel_cali_go_to_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    e_compass_sensor_cancel_cali();

        do {
	mmi_popup_property_struct arg;
	mmi_popup_property_init(&arg);
	arg.callback = mmi_alert_normal_exit_helper;
	arg.user_tag = (void *)(mmi_idle_display);
	mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_EC_CALI_ABORTED)), MMI_EVENT_SUCCESS, &arg);
	} while(0);

	//mmi_display_popupcallback(
        //   (UI_string_type)GetString(STR_ID_EC_CALI_ABORTED), 
        //    MMI_EVENT_SUCCESS, 
        //mmi_idle_display);
}

U8 location_string[MAX_SUB_MENU_HINT_SIZE];
/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_entry_direction_main_screen
 * DESCRIPTION
 *  Entry fn for Main direction screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_entry_direction_main_screen(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;   /* Buffer holding history data */
    U16 mecca_deg_from_north = 0;
    S16 error;
    S32 declination_array[MMI_EC_NUM_NVRAM_RECORDS] = {0};
    U8 sigsts_string[MMI_EC_SIGSTN_LEN * ENCODING_LENGTH];
    U8 mecca_string[(MMI_EC_MECCA_STR_LEN + 1) * ENCODING_LENGTH];
	S16 local_north;

    #if defined(__MMI_FTE_SUPPORT__)
		S32 count;
		S32 selected_country_index;
		S32 selected_city_index;
    #endif
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	//mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_EC_DIRECTION, mmi_ec_direction_grp_proc ,(void *)NULL);
    //mmi_frm_group_enter(GRP_ID_EC_DIRECTION, MMI_FRM_NODE_NONE_FLAG);

    if(mmi_frm_scrn_enter(
       GRP_ID_EC_MAIN, 
       SCR_ID_EC_DIRECTION, 
       NULL, 
       mmi_ecompass_entry_direction_main_screen, 
       MMI_FRM_FULL_SCRN))
    {
		//EntryNewScreen(SCR_ID_EC_DIRECTION, NULL, mmi_ecompass_entry_direction_main_screen, NULL);

        /*doubt regarding the modified API*/

         mmi_frm_scrn_set_leave_proc (GRP_ID_EC_MAIN, SCR_ID_EC_ANIMATION, NULL);
		//SetDelScrnIDCallbackHandler(SCR_ID_EC_ANIMATION, (HistoryDelCBPtr) NULL);       
		//mmi_frm_scrn_set_leave_proc (GRP_ID_EC_MAIN, SCR_ID_EC_ANIMATION, NULL);

		//DeleteScreenIfPresent(SCR_ID_EC_ANIMATION);
        mmi_frm_scrn_close(GRP_ID_EC_MAIN, SCR_ID_EC_ANIMATION);
      
        mmi_frm_scrn_close(GRP_ID_EC_MAIN,SCR_ID_EC_CLB_CHOICE);

    	//guiBuffer = GetCurrGuiBuffer(SCR_ID_EC_DIRECTION);
        guiBuffer = mmi_frm_scrn_get_gui_buf (GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION);	

   	memset(&mecca_string, 0, sizeof(mecca_string));
	memset(&sigsts_string, 0, sizeof(sigsts_string));

    mmi_ecompass_signal_string(sigsts_string);  /* get signal status */

    mmi_ecompass_get_current_city_nvram();  /* get current city */

    if (g_ecompass_cntxt.curr_city_index < MMI_EC_NUM_NVRAM_RECORDS)
    {
        ReadRecord(NVRAM_EF_ECOMPASS_LID, 1, declination_array, NVRAM_EF_ECOMPASS_SIZE, &error);
        g_ecompass_cntxt.declination_angle = declination_array[g_ecompass_cntxt.curr_city_index];
    }
    else if ((g_ecompass_cntxt.curr_city_index >= MMI_EC_NUM_NVRAM_RECORDS) &&
             g_ecompass_cntxt.curr_city_index < MMI_EC_MAX_CITIES)
    {
        ReadRecord(NVRAM_EF_ECOMPASS_LID, 2, declination_array, NVRAM_EF_ECOMPASS_SIZE, &error);
        g_ecompass_cntxt.declination_angle =
            declination_array[g_ecompass_cntxt.curr_city_index - MMI_EC_NUM_NVRAM_RECORDS];
    }
    else
    {
        ASSERT(0);
    }

    local_north = mmi_ecompass_calculate_north_declination(); /* calculating Geographic North */

    mecca_deg_from_north = g_ecompass_deg_mecca[g_ecompass_cntxt.curr_city_index] + local_north;

    if (mecca_deg_from_north > 360) /* if angle in greater than 360 */
    {
        mecca_deg_from_north = mecca_deg_from_north - 360;
    }

    mmi_ecompass_mecca_title_string(mecca_string);  /* get direction in the circle */



    /*code below is to get the location string - this is provided in case of FTE support*/		
    #if defined(__MMI_FTE_SUPPORT__)
		memset((S8*) location_string, 0, MAX_SUB_MENU_HINT_SIZE);
	
	    /* for loop has no statement, it helps to reach the right index */
		for (count = 0; g_ecompass_country_indices[count] <= g_ecompass_cntxt.curr_city_index; count++);
	
		selected_country_index = g_ecompass_country_indices[count - 1];
		selected_city_index = g_ecompass_cntxt.curr_city_index - selected_country_index;
	
		mmi_ucs2ncpy((S8*) location_string, (S8*) GetString((U16) (STR_ID_EC_CNTR_BASE + count)), MAX_SUB_MENU_HINT_SIZE);
		mmi_ucs2ncat((S8*) location_string, (S8*) GetString((U16) STR_ID_EC_COMMA), MAX_SUB_MENU_HINT_SIZE - mmi_ucs2strlen(location_string));
		mmi_ucs2ncat((S8*) location_string, (S8*) GetString((U16) (STR_ID_EC_CT_BASE + 1 + selected_country_index + selected_city_index)), MAX_SUB_MENU_HINT_SIZE - mmi_ucs2strlen(location_string));

    	wgui_cat126_set_location_info((WCHAR *)location_string);
    #endif /*__MMI_FTE_SUPPORT__*/
	
    /* 3 Display Category Screen */
    ShowCategory126Screen(
        (UI_string_type) mecca_string,
        0,
        get_string(STR_GLOBAL_OPTIONS),
        0,
        get_string(STR_GLOBAL_BACK),
        0,
        (UI_string_type) sigsts_string,
		local_north,
        mecca_deg_from_north,
        guiBuffer);

        mmi_frm_scrn_set_leave_proc (GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION, mmi_ec_app_leave_proc);
    	//SetDelScrnIDCallbackHandler(SCR_ID_EC_DIRECTION, (HistoryDelCBPtr) mmi_ecompass_deinitialize);
        //mmi_frm_scrn_set_leave_proc (GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION, mmi_ecompass_deinitialize);

    SetLeftSoftkeyFunction(mmi_ecompass_entry_options_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_ecompass_exit_from_app, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ec_direction_grp_proc
 * DESCRIPTION
 *  Proc function for ecompass informatio screen group
 * PARAMETERS
 *  Event type  - mmi_event_struct *evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ec_direction_grp_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {		
    	default:
    	  	break;
    }
    return MMI_RET_OK;	
	   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_exit_from_app
 * DESCRIPTION
 *  fn for stopping Main direction screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_exit_from_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ecompass_deinitialize();
    //mmi_frm_scrn_close (GRP_ID_EC_MAIN, SCR_ID_EC_CLB_CHOICE);
    //mmi_frm_scrn_close_active_id();
	//DeleteScreenIfPresent(SCR_ID_EC_CLB_CHOICE);
    //mmi_frm_group_close(GRP_ID_EC_DIRECTION);
	//mmi_frm_group_close(GRP_ID_EC_INFORMATION);	
    mmi_frm_group_close(GRP_ID_EC_MAIN);
	//GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_exit_app_endkey
 * DESCRIPTION
 *  fn for exiting at enf key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_exit_app_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ecompass_deinitialize();

    if ((IsScreenPresent(SCR_ID_EC_ANIMATION)) || (GetActiveScreenId() == (U16) SCR_ID_EC_ANIMATION))
    {
        e_compass_sensor_cancel_cali();

		mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_EC_CALI_ABORTED)), MMI_EVENT_SUCCESS, NULL);
        mmi_frm_scrn_close (GRP_ID_EC_MAIN, SCR_ID_EC_CLB_CHOICE); 
		//DeleteScreenIfPresent(SCR_ID_EC_CLB_CHOICE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_deinitialize
 * DESCRIPTION
 *  power off the sensor and reset protocol handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_deinitialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	e_compass_sensor_power_off();   /* power off sensor */
    SetProtocolEventHandler(NULL, MSG_ID_MMI_EC_CALI_STATE_IND);        /* set protocols to NULL */
    SetProtocolEventHandler(NULL, MSG_ID_MMI_EC_DATA_VALUE_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_entry_options_screen
 * DESCRIPTION
 *  Entry fn for displaying Options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_entry_options_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MMI_EC_OPTION_TOTAL];
	U8 *hint_list[MMI_EC_OPTION_TOTAL];
    U16 num_of_item;
    U16 nDispAttribute;
    U8 *guiBuffer;
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    g_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_EC_OPTIONS, mmi_ec_options_proc, NULL);
    mmi_frm_group_enter(g_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_options_scr_gid = cui_menu_create(
             g_id, 
             CUI_MENU_SRC_TYPE_RESOURCE, 
             CUI_MENU_TYPE_FROM_RESOURCE, 
             ECOMPASS_OPTIONS_MENU, 
             MMI_TRUE, 
             NULL);

    cui_menu_set_default_title_image(g_options_scr_gid,(UI_image_type)GetImage(IMG_ID_EC_ICON));
    cui_menu_run(g_options_scr_gid);
	
    /*
    EntryNewScreen(SCR_ID_EC_OPTIONS, NULL, mmi_ecompass_entry_options_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_EC_OPTIONS);

    num_of_item = GetNumOfChild(ECOMPASS_OPTIONS_MENU);
    nDispAttribute = GetDispAttributeOfItem(ECOMPASS_OPTIONS_MENU);
    GetSequenceStringIds(ECOMPASS_OPTIONS_MENU, str_item_list);
    SetParentHandler(ECOMPASS_OPTIONS_MENU);
	ConstructHintsList(ECOMPASS_OPTIONS_MENU, hint_list);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_ID_EC_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        str_item_list,
        (U16*) gIndexIconsImageList,
        hint_list,
        0,
        0,
        guiBuffer);
        */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wgtmgr_options_proc
 * DESCRIPTION
 *  This function is the group event proc of Ecompass options screen group
 * PARAMETERS
 *  evt: [IN] group event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ec_options_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    { 
        case EVT_ID_CUI_MENU_LIST_ENTRY:

			/*hint data set for the location and decliantion menu items*/
			{
				   mmi_ecompass_hint_location_menu();
				cui_menu_set_item_hint(g_options_scr_gid, ECOMPASS_OPTIONS_SET_LOCATION, (WCHAR *)hint_string[MMI_EC_HINTS_LOCATION]);  				
        	}

            {
				mmi_ecompass_hint_declination_menu();
				cui_menu_set_item_hint(g_options_scr_gid, ECOMPASS_OPTIONS_SET_DECLINATION, (WCHAR *)hint_string[MMI_EC_HINTS_DECLINATION]);
			}
			
            break;
		
        case EVT_ID_CUI_MENU_ITEM_SELECT:    

			switch (menu_evt->highlighted_menu_id)
            {
                case ECOMPASS_OPTIONS_SET_LOCATION:	
                   mmi_ecompass_entry_options_location_screen();
                   break;

                case ECOMPASS_OPTIONS_SET_DECLINATION:	
				   mmi_ecompass_entry_options_declination_screen();
                   break;

                case ECOMPASS_OPTIONS_CALIBRATE:
                   mmi_ecompass_entry_options_cali_manual_screen();
 				   break;
				            
                default:
                    MMI_ASSERT(0);
                    break;

            }

	    	break;
		
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:           
            break;
       
	    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);		   
            break;

    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_hint_location_menu
 * DESCRIPTION
 *  sets hint data for location menu
 * PARAMETERS
 *  U16 index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_hint_location_menu()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count;
	S32 selected_country_index;
	S32 selected_city_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset((S8*) hint_string[MMI_EC_HINTS_LOCATION], 0, sizeof(hint_string[MMI_EC_HINTS_LOCATION]));

	/* for loop has no statement, it helps to reach the right index */
	for (count = 0; g_ecompass_country_indices[count] <= g_ecompass_cntxt.curr_city_index; count++);

	selected_country_index = g_ecompass_country_indices[count - 1];
	selected_city_index = g_ecompass_cntxt.curr_city_index - selected_country_index;

	mmi_ucs2ncpy((S8*) hint_string[MMI_EC_HINTS_LOCATION], (S8*) GetString((U16) (STR_ID_EC_CNTR_BASE + count)), MAX_SUB_MENU_HINT_SIZE);
	mmi_ucs2ncat((S8*) hint_string[MMI_EC_HINTS_LOCATION], (S8*) GetString((U16) STR_ID_EC_COMMA), MAX_SUB_MENU_HINT_SIZE);
	mmi_ucs2ncat((S8*) hint_string[MMI_EC_HINTS_LOCATION], (S8*) GetString((U16) (STR_ID_EC_CT_BASE + 1 + selected_country_index + selected_city_index)), MAX_SUB_MENU_HINT_SIZE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_entry_options_location_screen
 * DESCRIPTION
 *  Select country entry function. Make list of countries to be displayed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_entry_options_location_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 country_cat = 0;
	U16 img_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_frm_scrn_enter(
       GRP_ID_EC_OPTIONS, 
       SCR_ID_EC_SET_COUNTRY, 
       mmi_ecompass_exit_set_country, 
       mmi_ecompass_entry_options_location_screen, 
       MMI_FRM_FULL_SCRN))
    {
        
    /*
    EntryNewScreen(
        SCR_ID_EC_SET_COUNTRY,
        mmi_ecompass_exit_set_country,
        mmi_ecompass_entry_options_location_screen,
        NULL);
      */      
    //DeleteScreenIfPresent(SCR_ID_EC_DECLINATION);
    //guiBuffer = GetCurrGuiBuffer(SCR_ID_EC_SET_COUNTRY);

	mmi_frm_scrn_close(GRP_ID_EC_OPTIONS, SCR_ID_EC_DECLINATION);
	guiBuffer = mmi_frm_scrn_get_gui_buf (GRP_ID_EC_MAIN, SCR_ID_EC_SET_COUNTRY);	

    mmi_ecompass_construct_country_list();

	country_cat = mmi_ecompass_get_current_country_index_cat();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#ifdef __MMI_FTE_SUPPORT__
	img_id = 0;
#else
	img_id = IMG_ID_EC_ICON,;
#endif

#ifndef __MMI_BASIC_UI_STYLE__
	ShowCategory284Screen (
        STR_ID_EC_COUNTRY,
        img_id,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_EC_MAX_COUNTRIES - 1,
        mmi_ecompass_country_async_callback,
        NULL,
        country_cat,
        guiBuffer);	
#else
	wgui_cat1032_show(
            (WCHAR*) GetString(STR_ID_EC_COUNTRY),
		    (PU8) GetImage(img_id),
            (WCHAR*) GetString(STR_GLOBAL_OK),
            (PU8) GetImage(IMG_GLOBAL_OK),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            MMI_EC_MAX_COUNTRIES - 1,
            mmi_ecompass_country_async_callback_ext,
            NULL,
            country_cat,
            0,    
            0,
            0,
            guiBuffer,
            NULL);
#endif
    RegisterHighlightHandler(mmi_ecompass_country_idx_hilite_handler);

    if (IsEnglishSet())
    {
        wgui_setup_multitap_functions(
            WGUI_MULTITAP_TYPE_UPPERCASE_ABC_NO_NUMBER,
            mmi_ecompass_multi_tap_hdlr,
            mmi_ecompass_multi_tap_complete_hdlr);
    }

    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_ecompass_set_hilited_item_country, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_ecompass_set_hilited_item_country, KEY_EVENT_UP);
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_country_async_callback
 * DESCRIPTION
 *  This function is callback function for generating asynchronous list.
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         [?]
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_ecompass_country_async_callback(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy(
        (S8*) str_buff,
        (S8*) GetString((U16) (STR_ID_EC_CNTR_BASE + 1 + item_index)),
        MAX_SUBMENU_CHARACTERS);

    *img_buff_p = NULL;

    return TRUE;
}

#ifdef __MMI_BASIC_UI_STYLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_country_async_callback_ext
 * DESCRIPTION
 * 
 * PARAMETERS
 *    
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_ecompass_country_async_callback_ext(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
	S32 i;

	for (i = 0; i< data_size; i++)
	{
		mmi_ecompass_country_async_callback(start_index, menu_data[i].item_list[0], &menu_data[i].image_list[0], 0);
		start_index++;
	}
	return data_size;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_construct_country_list
 * DESCRIPTION
 *  This function is to make list of all countries
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_construct_country_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_EC_MAX_COUNTRIES; i++)  /* change to max_countries */
    {
        g_ecompass_cntxt.countryDataPtr[i] = (PU8) (GetString((U16) (STR_ID_EC_CNTR_BASE + 1 + i)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_country_idx_hilite_handler
 * DESCRIPTION
 *  Selects current selected iindex
 * PARAMETERS
 *  cityIndex       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_country_idx_hilite_handler(S32 cityIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ecompass_cntxt.hilited_country = (U32) cityIndex;
    MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_COUNTRY_HILITE, g_ecompass_cntxt.hilited_country);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_multi_tap_hdlr
 * DESCRIPTION
 *  Multitap handling
 *  Functionality:
 * PARAMETERS
 *  inp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_multi_tap_hdlr(UI_character_type inp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = mmi_ecompass_get_nearby_idx(inp);
    if (idx != MMI_EC_MAX_COUNTRIES)
    {
        g_ecompass_cntxt.hilited_country = idx;
    }

    dynamic_list_goto_item((S32) g_ecompass_cntxt.hilited_country);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_multi_tap_complete_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_multi_tap_complete_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_list_goto_item((S32) g_ecompass_cntxt.hilited_country);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_get_nearby_idx
 * DESCRIPTION
 *  For multitap handling
 * PARAMETERS
 *  inp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_ecompass_get_nearby_idx(UI_character_type inp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curr_char = 0;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((inp >= (UI_character_type) 'A' && inp <= (UI_character_type) 'Z') ||
        (inp >= (UI_character_type) 'a' && inp <= (UI_character_type) 'z'))
    {
        for (i = 0; i < MMI_EC_MAX_COUNTRIES; i++)
        {
            memcpy(&curr_char, g_ecompass_cntxt.countryDataPtr[i], ENCODING_LENGTH);
            if (curr_char == inp)
            {
                return (U8) (i);
            }
        }

      /*  if (i == MMI_EC_MAX_COUNTRIES)
        {
            return i;
        }
        else
        {
            return 0;
        }*/
		if ((inp >= (UI_character_type) 'A' && inp <= (UI_character_type) 'Z'))
		{
			return (g_ecompass_country_multitap[inp - 65]);
		}
		else if ((inp >= (UI_character_type) 'a' && inp <= (UI_character_type) 'z'))
		{
			return (g_ecompass_country_multitap[inp - 97]);
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_exit_set_country
 * DESCRIPTION
 *  Multitap handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_exit_set_country(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_reset_multitap();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_set_hilited_item_country
 * DESCRIPTION
 *  Stores index of selected country
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_set_hilited_item_country(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = (U8) GetHighlightedItem();
    g_ecompass_cntxt.hilited_country = g_ecompass_country_indices[idx];
    g_ecompass_cntxt.hilited_country_next = g_ecompass_country_indices[idx + 1];
    mmi_ecompass_entry_set_city_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_entry_set_city_screen
 * DESCRIPTION
 *  Entry function for displaying list of cities
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_entry_set_city_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 index;
    mmi_id g_id, group_id;
	U16 curr_selected_country;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_EC_SET_CITY, mmi_ec_set_city_proc, NULL);
    mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);


    //curr_selected_country = mmi_ecompass_get_current_country_index_cat();
    g_set_city_gid = cui_menu_create(
             group_id, 
             CUI_MENU_SRC_TYPE_RESOURCE, 
             CUI_MENU_TYPE_OPTION, 
             ECOMPASS_COUNTRY_MENU, 
             MMI_FALSE, 
             NULL);

    //SetLeftSoftkeyFunction(mmi_ecompass_current_city_index, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    cui_menu_set_default_title_image(g_set_city_gid, (UI_image_type)GetImage(IMG_ID_EC_ICON));
    cui_menu_run(g_set_city_gid);
        
	//EntryNewScreen(SCR_ID_EC_SET_CITY, NULL, mmi_ecompass_entry_set_city_screen, NULL);
    //guiBuffer = GetCurrGuiBuffer(SCR_ID_EC_SET_CITY);        
	//guiBuffer = mmi_frm_scrn_get_gui_buf (GRP_ID_EC_MAIN, SCR_ID_EC_SET_CITY);		
	
    /* static list upto number of cities in a country */
    
    /*

    for (index = 0; index < num_cities; index++)
    {
        itemlist[index] = (U8*) GetString((U16) (STR_ID_EC_CT_BASE + 1 + g_ecompass_cntxt.hilited_country + index));
        ItemIcons[index] = (U8*) GetImage((U16) (IMG_GLOBAL_L1 + index));
    }

    ShowCategory174Screen(
        (PU8) GetString(STR_ID_EC_CITY),
        (PU8) GetImage(IMG_ID_EC_ICON),
        (PU8) GetString(STR_GLOBAL_OK),
        0,
        (PU8) GetString(STR_GLOBAL_BACK),
        0,
        num_cities,
        itemlist,
        ItemIcons,
        0,
        0,
        city_cat_index,
        guiBuffer);
       */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ec_set_city_proc
 * DESCRIPTION
 *  This function is the group event proc of set city screen group
 * PARAMETERS
 *  evt: [IN] group event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ec_set_city_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

   	U8 index = 0;
	U8 num_cities = 0;
	//U8 *ItemIcons[MMI_EC_MAX_CIT_SCR];
    //U8 *itemlist[MMI_EC_MAX_CIT_SCR];
	S32 city_cat_index = 0;
    S32 country_index = 0;
	mmi_menu_id root_ids[MMI_EC_MAX_CIT_SCR];

	
	cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    { 
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
           	 num_cities = g_ecompass_cntxt.hilited_country_next - g_ecompass_cntxt.hilited_country;

    		//if (guiBuffer == NULL)
    		//{
    			country_index = mmi_ecompass_get_current_country_index_cat();
        		if (g_ecompass_cntxt.hilited_country == g_ecompass_country_indices[country_index])
				{
	    			city_cat_index = mmi_ecompass_get_current_city_index_cat();
				}
    		//}
            
			if(menu_evt->parent_menu_id == ECOMPASS_COUNTRY_MENU)
			{
                
    			for (index = 0; index < num_cities; index++)
    			{
                    root_ids[index] = ECOMPASS_CITY1 + index;										    			
				}
                
				cui_menu_set_currlist(g_set_city_gid, num_cities, root_ids);

				for (index = 0; index < num_cities; index++)
				{				
     				cui_menu_set_item_string(g_set_city_gid,
					                         root_ids[index], (UI_string_type)(GetString(STR_ID_EC_CT_BASE + g_ecompass_cntxt.hilited_country + index + 1)));

				}
			}
            cui_menu_set_currlist_title(g_set_city_gid,(WCHAR *)GetString(STR_ID_EC_CITY),NULL);
			cui_menu_set_currlist_flags(g_set_city_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
			cui_menu_set_currlist_highlighted_id(g_set_city_gid, root_ids[city_cat_index]);

		}
        break;
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        

            switch (menu_evt->highlighted_menu_id)
            {
			case ECOMPASS_CITY1:    
				//case ECOMPASS_CITY1:
				 g_hilited_city_index = ECOMPASS_CITY1 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();
                 break;
			   
            case ECOMPASS_CITY2:
				 g_hilited_city_index = ECOMPASS_CITY2 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();                
                 break;
   
		    case ECOMPASS_CITY3:
				 g_hilited_city_index = ECOMPASS_CITY3 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();
                 break;
								
			case ECOMPASS_CITY4:
				 g_hilited_city_index = ECOMPASS_CITY4 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();				
                 break;

		    case ECOMPASS_CITY5:
				 g_hilited_city_index = ECOMPASS_CITY5 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();
                 break;
			   
            case ECOMPASS_CITY6:
				 g_hilited_city_index = ECOMPASS_CITY6 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();                
                 break;
   
		    case ECOMPASS_CITY7:
				 g_hilited_city_index = ECOMPASS_CITY7 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();
                 break;
								
			case ECOMPASS_CITY8:
				 g_hilited_city_index = ECOMPASS_CITY8 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();				
                 break;

	        case ECOMPASS_CITY9:
				 g_hilited_city_index = ECOMPASS_CITY9 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();
                 break;
			   
            case ECOMPASS_CITY10:
				 g_hilited_city_index = ECOMPASS_CITY10 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();                
                 break;
   
		    case ECOMPASS_CITY11:
				 g_hilited_city_index = ECOMPASS_CITY11 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();
                 break;
								
			case ECOMPASS_CITY12:
				 g_hilited_city_index = ECOMPASS_CITY12 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();				
                 break;			

			case ECOMPASS_CITY13:
				 g_hilited_city_index = ECOMPASS_CITY10 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();				
				 break;
					
			case ECOMPASS_CITY14:
				 g_hilited_city_index = ECOMPASS_CITY11 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();
				 break;
												 
		    case ECOMPASS_CITY15:
				 g_hilited_city_index = ECOMPASS_CITY12 - ECOMPASS_CITY1;
				 mmi_ecompass_current_city_index();			 
				 break;								   

			default:

			     MMI_ASSERT(0);
				 break;  
            }

			break;
		
			
        //case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:

	    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
           cui_menu_close(menu_evt->sender_id);		   
           break;

    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_current_city_index
 * DESCRIPTION
 *  Stores selected city index and calculates current city
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_current_city_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	g_ecompass_cntxt.hilited_city = g_hilited_city_index;     
	//g_ecompass_cntxt.hilited_city = (U8) GetHighlightedItem();
    g_ecompass_cntxt.curr_city_index = g_ecompass_cntxt.hilited_country + g_ecompass_cntxt.hilited_city;

    MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_CURR_CITY, g_ecompass_cntxt.curr_city_index);

    /* save current city to NVRAM */
    WriteValue(NVRAM_EC_DEFAULT_CITY, &(g_ecompass_cntxt.curr_city_index), DS_SHORT, &error);

    mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, NULL);
    
    

	mmi_frm_scrn_set_leave_proc (GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION, NULL);
	//SetDelScrnIDCallbackHandler(SCR_ID_EC_DIRECTION, (HistoryDelCBPtr) NULL);

	/*for debug purpose*/
	mmi_frm_scrn_close(GRP_ID_EC_OPTIONS, SCR_ID_EC_SET_COUNTRY);	
    //mmi_frm_scrn_close(GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION);
	//DeleteUptoScrID(SCR_ID_EC_DIRECTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_entry_options_cali_manual_screen
 * DESCRIPTION
 *  Entry functio for manual calibration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_entry_options_cali_manual_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.softkey[0].str = (WCHAR *)((UI_string_type)GetString(STR_GLOBAL_YES));
	arg.softkey[2].str = (WCHAR *)((UI_string_type)GetString(STR_GLOBAL_NO));
	arg.callback = (mmi_proc_func)mmi_ec_manual_calib_popup_callback;
	mmi_confirm_display((WCHAR *)((UI_string_type)GetString(STR_ID_EC_MAN_CHOICE)), MMI_EVENT_QUERY, &arg);
	} while(0);

    //SetLeftSoftkeyFunction(mmi_ecompass_pre_entry_information_screen, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id,KEY_EVENT_UP);
	//SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  Call back for confirm popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ec_manual_calib_popup_callback(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
           mmi_ecompass_pre_entry_information_screen();
		   break;  

		case MMI_ALERT_CNFM_NO:
           mmi_frm_scrn_close_active_id(); 
			// handle softkey event here
			break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_pre_entry_information_screen
 * DESCRIPTION
 *  Pre Entry function for manual calibration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_pre_entry_information_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	//mmi_frm_set_active_group(GRP_ID_EC_MAIN);
    
    mmi_frm_group_close(GRP_ID_EC_MAIN);
	mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_EC_MAIN, mmi_ec_entry_frm_maual_calib_proc ,(void *)NULL);
	mmi_frm_group_enter(GRP_ID_EC_MAIN, MMI_FRM_NODE_NONE_FLAG);
     
		
   //mmi_frm_set_active_group(GRP_ID_EC_MAIN);
	//mmi_frm_scrn_close(GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION);
    //mmi_frm_set_active_group(GRP_ID_EC_MAIN);
	mmi_ecompass_entry_information_screen();
	//SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


mmi_ret mmi_ec_entry_frm_maual_calib_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	switch (evt->evt_id)
	{
		
		case EVT_ID_GROUP_ENTER :
			mmi_ecompass_entry_information_screen();	
			break;

		case EVT_ID_GROUP_DEINIT:
			//mmi_ecompass_deinitialize();
			break;

		case EVT_ID_GROUP_EXIT: 		   
			break;

		case EVT_ID_GROUP_INACTIVE:
			break;

		case EVT_ID_GROUP_GOBACK:
			break;
			
		default:
			break;
	}
	return MMI_RET_OK;	
	   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_hint_declination_menu
 * DESCRIPTION
 *  set hint data for decliantion menu
 * PARAMETERS
 *  U16 index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_hint_declination_menu()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 declination_cat = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	memset((S8*) hint_string[MMI_EC_HINTS_DECLINATION], 0, sizeof(hint_string[MMI_EC_HINTS_DECLINATION]));

	if (g_ecompass_cntxt.declination_angle > 0)
    {
        app_ucs2_itoa(
            (S32) g_ecompass_cntxt.declination_angle,
            (kal_int8*) hint_string[MMI_EC_HINTS_DECLINATION],
            MMI_EC_DECIMAL_RADIX);

		mmi_ucs2ncat((S8*) hint_string[MMI_EC_HINTS_DECLINATION], (S8*) GetString((U16) STR_ID_EC_DEGREE), MAX_SUB_MENU_HINT_SIZE);
		mmi_ucs2ncat((S8*) hint_string[MMI_EC_HINTS_DECLINATION], (S8*) GetString((U16) STR_ID_EC_COMMA), MAX_SUB_MENU_HINT_SIZE);
		mmi_ucs2ncat((S8*) hint_string[MMI_EC_HINTS_DECLINATION], GetString(STR_ID_EC_WEST), MAX_SUB_MENU_HINT_SIZE);
}
    else if (g_ecompass_cntxt.declination_angle <= 0)
    {
        declination_cat = -1 * (g_ecompass_cntxt.declination_angle);
        app_ucs2_itoa((S32) declination_cat, (kal_int8*) hint_string[MMI_EC_HINTS_DECLINATION], MMI_EC_DECIMAL_RADIX);

		mmi_ucs2ncat((S8*) hint_string[MMI_EC_HINTS_DECLINATION], (S8*) GetString((U16) STR_ID_EC_DEGREE), MAX_SUB_MENU_HINT_SIZE);
		mmi_ucs2ncat((S8*) hint_string[MMI_EC_HINTS_DECLINATION], (S8*) GetString((U16) STR_ID_EC_COMMA), MAX_SUB_MENU_HINT_SIZE);
		mmi_ucs2ncat((S8*) hint_string[MMI_EC_HINTS_DECLINATION], GetString(STR_ID_EC_EAST), MAX_SUB_MENU_HINT_SIZE);
    }
	else
	{
		ASSERT(0);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_entry_options_declination_screen
 * DESCRIPTION
 *  Entry function of setting declination.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_entry_options_declination_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer = NULL;
    U16 inputBufferSize = 0;    /* added for inline edit history */
    S32 declination_cat = 0;
	U8 val = 1;
    mmi_id g_id;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_EC_DEC_INLINE, mmi_ec_dec_inline_proc, NULL);
    mmi_frm_group_enter(g_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	//EntryNewScreen(SCR_ID_EC_DECLINATION, mmi_ecompass_exit_inline, NULL, NULL);
    //guiBuffer = GetCurrGuiBuffer(SCR_ID_EC_DECLINATION);
	
    g_inline_id = cui_inline_create(g_id, &g_initial_inline_data);

    //cui_inline_set_title(g_inline_id, STR_ID_EC_SET_DEC, IMG_ID_EC_ICON);  

    guiBuffer = mmi_frm_scrn_get_gui_buf (GRP_ID_EC_OPTIONS, SCR_ID_EC_DECLINATION);


	if (guiBuffer == NULL)
    {
		if(g_ecompass_cntxt.declination_angle > 0)
		{
			app_ucs2_itoa(
			(S32) g_ecompass_cntxt.declination_angle,
                (kal_int8*) g_ecompass_number_buffer,
                MMI_EC_DECIMAL_RADIX);
			g_ecompass_cntxt.declination_direc = MMI_EC_DRC_WEST;
		}
        else if (g_ecompass_cntxt.declination_angle < 0)
		{
			declination_cat = -1 * (g_ecompass_cntxt.declination_angle);
            app_ucs2_itoa((S32) declination_cat, (kal_int8*) g_ecompass_number_buffer, MMI_EC_DECIMAL_RADIX);
            g_ecompass_cntxt.declination_direc = MMI_EC_DRC_EAST;
        }
        else if (g_ecompass_cntxt.declination_angle == 0)
        {
            app_ucs2_itoa(
                (S32) g_ecompass_cntxt.declination_angle,
                (kal_int8*) g_ecompass_number_buffer,
                MMI_EC_DECIMAL_RADIX);
			g_ecompass_cntxt.declination_direc = MMI_EC_DRC_EAST;
		}
        else
        {
            ASSERT(0);
        }
    }

	cui_inline_set_value(g_inline_id, ECOMPASS_DEC_ANGLE_MEASURE_EDIT, (void *)g_ecompass_number_buffer);
    cui_inline_set_value(g_inline_id, ECOMPASS_DEC_DIRECTION_OPTION, (void *)g_ecompass_cntxt.declination_direc);
	
	cui_inline_run(g_inline_id); 

    //InitializeCategory57Screen();

    //DisableCategory57ScreenDone();

    //mmi_ecompass_setinline_declination();

    //inputBuffer = mmi_frm_scrn_get_input_buf(GRP_ID_EC_OPTIONS, SCR_ID_EC_DECLINATION);

    //if (inputBuffer != NULL)    /* added for inline edit history */
    //{
    //    SetCategory57Data(wgui_inline_items, MMI_EC_SIN_TOTAL, inputBuffer);    /* sets the data */
    //}
	//RegisterHighlightHandler(HighlightEcInputItem);

    /*
    ShowCategory57Screen(
        STR_ID_EC_SET_DEC,
        IMG_ID_EC_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_EC_SIN_TOTAL,
        NULL,
        wgui_inline_items,
        (S32) NULL,
        guiBuffer);
        */
    //DisableCategory57ScreenDone();

    //SetLeftSoftkeyFunction(mmi_ecompass_get_direction, KEY_EVENT_UP);
    //SetCategory57RightSoftkeyFunctions(NULL, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ec_dec_inline_proc
 * DESCRIPTION
 *  This function is the group event proc of Ecompass declination inline screen group
 * PARAMETERS
 *  evt: [IN] group event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ec_dec_inline_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    { 
        case EVT_ID_CUI_INLINE_SUBMIT:
			cui_inline_get_value(g_inline_id, ECOMPASS_DEC_ANGLE_MEASURE_EDIT , g_ecompass_number_buffer);
            cui_inline_get_value(g_inline_id, ECOMPASS_DEC_DIRECTION_OPTION ,&g_ecompass_cntxt.declination_direc);
			mmi_ecompass_get_direction();
        	break;

        case EVT_ID_CUI_INLINE_SET_KEY:
		break;	

		case EVT_ID_CUI_INLINE_CSK_PRESS:
		break;

		case EVT_ID_CUI_INLINE_NOTIFY:
		break;

		case EVT_ID_CUI_INLINE_REDRAW:
		break;

		case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
			
			//cui_inline_set_value(g_inline_id, ECOMPASS_DEC_DIRECTION_OPTION, (void *)&g_ecompass_cntxt.declination_direc);
        	//cui_inline_set_value(g_inline_id, ECOMPASS_DEC_ANGLE_MEASURE_EDIT, (void *)&g_ecompass_cntxt.declination_angle);
		break;

		case EVT_ID_CUI_INLINE_MAX:
		break;		

		case EVT_ID_CUI_INLINE_GROUP_DEINIT:
		break;

		case EVT_ID_CUI_INLINE_ABORT:
			cui_inline_close(g_inline_id);
			break;

}

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_go_back_inline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_go_back_inline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_EC_DECLINATION);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_declination_settings_inlineitem_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ecompass_declination_settings_inlineitem_highlight_hdlr(S32 index)
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
 *  mmi_ecompass_setinline_declination
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_setinline_declination(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(FALSE);
    g_ecompass_cntxt.DirectionList[MMI_EC_DRC_EAST] = (S8*) GetString(STR_ID_EC_EAST);
    g_ecompass_cntxt.DirectionList[MMI_EC_DRC_WEST] = (S8*) GetString(STR_ID_EC_WEST);
    
    /* angle caption */
    SetInlineItemActivation(&wgui_inline_items[MMI_EC_SIN_AC], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[MMI_EC_SIN_AC], (U8*) GetString(STR_ID_EC_DEC_ANGLE));
    SetInlineItemFullWidth(&wgui_inline_items[MMI_EC_SIN_AC]);

    /* angle */
    SetInlineItemActivation(&wgui_inline_items[MMI_EC_SIN_AN], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[MMI_EC_SIN_AN],
        (U8*) g_ecompass_number_buffer,
        MMI_EC_MAX_ANGLE,
        IMM_INPUT_TYPE_NUMERIC); 

    RightJustifyInlineItem(&wgui_inline_items[MMI_EC_SIN_AN]);
    SetInlineItemFullWidth(&wgui_inline_items[MMI_EC_SIN_AN]);
    EnableInlineItemBoundary(&wgui_inline_items[MMI_EC_SIN_AN]);
    /* g_ecompass_cntxt.declination_angle = (S8) gui_atoi((UI_string_type) g_ecompass_number_buffer); */

    MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_INLINE_ANGLE, g_ecompass_cntxt.declination_angle);

    /* direction caption */
    SetInlineItemActivation(&wgui_inline_items[MMI_EC_SIN_DC], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[MMI_EC_SIN_DC], (U8*) GetString(STR_ID_EC_DEC_DIR));
    SetInlineItemFullWidth(&wgui_inline_items[MMI_EC_SIN_DC]);

    /* direction */
    SetInlineItemActivation(&wgui_inline_items[MMI_EC_SIN_DR], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[MMI_EC_SIN_DR],
        MMI_EC_DRC_TOTAL,
        (U8 **) g_ecompass_cntxt.DirectionList,
        (S32*) & g_ecompass_cntxt.declination_direc);
    RegisterInlineSelectHighlightHandler(
        &wgui_inline_items[MMI_EC_SIN_DR],
        mmi_ecompass_declination_settings_inlineitem_highlight_hdlr);
    MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_INLINE_DIR, g_ecompass_cntxt.declination_direc);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEcInputItem
 * DESCRIPTION
 *  Highlight handler of inline editor in input screen.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEcInputItem(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_ecompass_get_direction, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_get_direction
 * DESCRIPTION
 *  Calculate declination angle and write it to NVRAM
 * PARAMETERS
 *  void
 *  index(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_get_direction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 declination_array[MMI_EC_NUM_NVRAM_RECORDS] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //CloseCategory57Screen();

    if ((gui_strlen((UI_string_type) g_ecompass_number_buffer) < 1) ||
        (gui_strlen((UI_string_type) g_ecompass_number_buffer) > MMI_EC_MAX_ANGLE))
    {      
		mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_EMPTY)), MMI_EVENT_FAILURE, NULL);  
        return;
    }
    
    if ((U32) (gui_atoi((UI_string_type) g_ecompass_number_buffer)) > MMI_EC_DIR_TST)
	{
       mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_EC_RANGE)), MMI_EVENT_FAILURE, NULL);
        return;
	}
  
    g_ecompass_cntxt.declination_angle = (S32) gui_atoi((UI_string_type) g_ecompass_number_buffer);

    if ((U8) g_ecompass_cntxt.declination_direc == MMI_EC_DRC_EAST)
    {
        g_ecompass_cntxt.declination_angle = (S32) (-1 * (g_ecompass_cntxt.declination_angle));
    }

    MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_ANG_FINAL, g_ecompass_cntxt.declination_angle);

    if (g_ecompass_cntxt.curr_city_index < MMI_EC_NUM_NVRAM_RECORDS)
    {
        ReadRecord(NVRAM_EF_ECOMPASS_LID, 1, declination_array, NVRAM_EF_ECOMPASS_SIZE, &error);
        declination_array[g_ecompass_cntxt.curr_city_index] = g_ecompass_cntxt.declination_angle;
        WriteRecord(NVRAM_EF_ECOMPASS_LID, 1, declination_array, NVRAM_EF_ECOMPASS_SIZE, &error);
    }
    else if ((g_ecompass_cntxt.curr_city_index >= MMI_EC_NUM_NVRAM_RECORDS) &&
             g_ecompass_cntxt.curr_city_index < MMI_EC_MAX_CITIES)
    {
        ReadRecord(NVRAM_EF_ECOMPASS_LID, 2, declination_array, NVRAM_EF_ECOMPASS_SIZE, &error);
        declination_array[g_ecompass_cntxt.curr_city_index - MMI_EC_NUM_NVRAM_RECORDS] =
            g_ecompass_cntxt.declination_angle;
        WriteRecord(NVRAM_EF_ECOMPASS_LID, 2, declination_array, NVRAM_EF_ECOMPASS_SIZE, &error);
    }
    else
    {
        ASSERT(0);
    }

    mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, NULL);
   
    mmi_frm_scrn_set_leave_proc (GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION, NULL);
	cui_inline_close(g_inline_id);
	//SetDelScrnIDCallbackHandler(SCR_ID_EC_DIRECTION, (HistoryDelCBPtr) NULL);
    //DeleteUptoScrID(SCR_ID_EC_DIRECTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_calculate_north_declination
 * DESCRIPTION
 *  Calculate geographic Nprth
 * PARAMETERS
 *  void
 *  index(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_ecompass_calculate_north_declination(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 local_north = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    local_north = g_ecompass_cntxt.curr_north + g_ecompass_cntxt.declination_angle;

	/* if angle is less than ZERO, pass same value as positive to category, 
	forexample, if angle is -10, make it +10 and pass to category */
	local_north = 360 - local_north;

	if (local_north < MMI_EC_DIR_ZERO)
	{
		local_north = MMI_EC_DIR_TST + local_north;
	}
	else if (local_north > 360)
    {
		local_north = local_north - 360;
	}
	return local_north;

    MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_NORTH_WITH_DEC_ANG, g_ecompass_cntxt.curr_north);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_get_current_city_nvram
 * DESCRIPTION
 *  Read current city from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_get_current_city_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_EC_DEFAULT_CITY, &(g_ecompass_cntxt.curr_city_index), DS_SHORT, &error);    /* get current city from NVRAM */
	
	if( g_ecompass_cntxt.curr_city_index > MMI_EC_MAX_CITIES)
	{
		ASSERT(0);
	}

    MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_CURR_CITY_NVRAM_READ, g_ecompass_cntxt.curr_city_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_mecca_title_string
 * DESCRIPTION
 *  Build mecca string
 * PARAMETERS
 *  mecca_string        [?]     
 * RETURNS
 *  UI_string_type(?)
 *****************************************************************************/
void mmi_ecompass_mecca_title_string(U8 mecca_string[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 mecca_deg_from_north = 0;
    U8 mecca_int_to_str[(MMI_EC_MECCA_STR_LEN + 1) * ENCODING_LENGTH];
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	memset(&mecca_int_to_str, 0, sizeof(mecca_int_to_str));
    memset(mecca_string, 0, sizeof(mecca_string));

    mecca_deg_from_north = g_ecompass_deg_mecca[g_ecompass_cntxt.curr_city_index] 
		                   + g_ecompass_cntxt.curr_north;

    if (mecca_deg_from_north > MMI_EC_DIR_TST)
    {
        mecca_deg_from_north = mecca_deg_from_north - MMI_EC_DIR_TST;
    }

    /* Building Mecca string */
    mmi_ucs2ncpy((S8*) mecca_string, (S8*) GetString(STR_ID_EC_MECCA), (MMI_EC_MECCA_STR_LEN + 1));

    if ((mecca_deg_from_north >= MMI_EC_DIR_ZERO) && (mecca_deg_from_north <= MMI_EC_DIR_NIN))
    {
        string_id = STR_ID_EC_NE;
    }
    else if ((mecca_deg_from_north > MMI_EC_DIR_NIN) && (mecca_deg_from_north <= MMI_EC_DIR_OET))
    {
        string_id = STR_ID_EC_SE;
    }
    else if ((mecca_deg_from_north > MMI_EC_DIR_OET) && (mecca_deg_from_north <= MMI_EC_DIR_TSY))
    {
        string_id = STR_ID_EC_SW;
    }
    else
    {
        string_id = STR_ID_EC_NW;
    }

    /* prabhjot: add direction string to the main mecca string */
    mmi_ucs2ncat(
        (S8*) mecca_string,
        (S8*) GetString(string_id),
        (MMI_EC_MECCA_STR_LEN + 1) - gui_strlen((UI_string_type) (mecca_string)));

    app_ucs2_itoa(
        (S32) mecca_deg_from_north,
        (kal_int8*) mecca_int_to_str,
        MMI_EC_DECIMAL_RADIX);

    mmi_ucs2ncat(
        (S8*) mecca_string,
        (S8*) mecca_int_to_str,
        (MMI_EC_MECCA_STR_LEN + 1) - gui_strlen((UI_string_type) (mecca_string)));
    mmi_ucs2ncat(
        (S8*) mecca_string,
        (S8*) GetString(STR_ID_EC_DEGREE),
        (MMI_EC_MECCA_STR_LEN + 1) - gui_strlen((UI_string_type) (mecca_string)));
    /* end building Mecca string */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_signal_string
 * DESCRIPTION
 *  Build signal string
 * PARAMETERS
 *  sigsts_string           
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
void mmi_ecompass_signal_string(U8 sigsts_string[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	memset(sigsts_string, 0, sizeof(sigsts_string));

    if (g_ecompass_cntxt.sgnstn == MMI_EC_SIGSTN_WEAK)
    {
        mmi_ucs2ncpy((S8*) sigsts_string, GetString(STR_ID_EC_NEED_CALI), MMI_EC_SIGSTN_LEN);
    }
    else
    {
        mmi_ucs2ncpy((S8*) sigsts_string, GetString(STR_ID_EC_STRONG_SIG), MMI_EC_SIGSTN_LEN);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_exit_inline
 * DESCRIPTION
 *  Exit function for set declination
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_exit_inline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;    /* added for inline edit history */
    history Historyecompass;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    CloseCategory57Screen();
    Historyecompass.scrnID = SCR_ID_EC_DECLINATION;
    Historyecompass.entryFuncPtr = mmi_ecompass_entry_options_declination_screen;
    GetCategory57History(Historyecompass.guiBuffer);
    mmi_ucs2cpy((S8*) Historyecompass.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (U16) GetCategory57DataSize();        /* added for inline edit history */
    GetCategory57Data((U8*) Historyecompass.inputBuffer);   /* added for inline edit history */
    AddNHistory(Historyecompass, inputBufferSize);          /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_get_calibration_status_callback
 * DESCRIPTION
 *  Callback function for calibration finish
 * PARAMETERS
 *  parameter       [?]         
 *  state           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_get_calibration_status_callback(void *parameter, E_Compass_Sensor_Cali_Result_enum cali_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_ecompass_msg_struct *msg_data_ptr;
	U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	result = (U8) cali_result;
	/* keep the calibration status here, show error popup accordingly */
	mmi_ecompass_set_cali_result(result);

    msg_data_ptr = OslConstructDataPtr(sizeof(mmi_ecompass_msg_struct));
    message.oslMsgId = MSG_ID_MMI_EC_CALI_STATE_IND;
    message.oslDataPtr = (oslParaType*) msg_data_ptr;
    message.oslPeerBuffPtr = NULL;
    message.oslSrcId = MOD_EC_TASK;
    message.oslDestId = MOD_MMI;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_get_data_callback
 * DESCRIPTION
 *  Callback function for getting new data
 * PARAMETERS
 *  parameter       [?]         
 *  state           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_get_data_callback(void *parameter, E_Compass_Sensor_BuffState_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_ecompass_msg_struct *msg_data_ptr;
    kal_bool status;
    E_CompassSensorDataStruct north_angle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data_ptr = OslConstructDataPtr(sizeof(mmi_ecompass_msg_struct));

    status = e_compass_sensor_get_data(&north_angle);

    if (status) /* change value only if some data is got from driver else value--can be 0 */
    {
        msg_data_ptr->ec_data = north_angle.angle;
    }
    else
    {
        msg_data_ptr->ec_data = 0;
    }
    message.oslMsgId = MSG_ID_MMI_EC_DATA_VALUE_IND;
    message.oslDataPtr = (oslParaType*) msg_data_ptr;
    message.oslPeerBuffPtr = NULL;
    message.oslSrcId = MOD_EC_TASK;
    message.oslDestId = MOD_MMI;
    OslMsgSendExtQueue(&message);
}

/* prabhjot add this function to maintain history if calibration is interrupted */


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_go_back_from_calibration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_go_back_from_calibration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct new_node_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_ID_EC_ANIMATION != GetExitScrnID())
    {
        new_node_info.id = SCR_ID_EC_DIRECTION;
        new_node_info.entry_proc = (mmi_proc_func)mmi_ecompass_entry_direction_main_screen;
	
        mmi_frm_scrn_replace (GRP_ID_EC_MAIN, SCR_ID_EC_ANIMATION, &new_node_info);    
		//HistoryReplace(SCR_ID_EC_ANIMATION, SCR_ID_EC_DIRECTION, mmi_ecompass_entry_direction_main_screen);
        mmi_frm_scrn_set_leave_proc (GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION, mmi_ec_app_leave_proc); 
		//SetDelScrnIDCallbackHandler(SCR_ID_EC_DIRECTION, (HistoryDelCBPtr) mmi_ecompass_deinitialize);
        GoBackHistory();
    }
    else
    {
        mmi_ecompass_entry_direction_main_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_get_calibration_status_handler
 * DESCRIPTION
 *  Handler invoked on getting ind from driver callback
 * PARAMETERS
 *  calMsg      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_get_calibration_status_handler(void *calMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_frm_node_struct new_node_info;
	mmi_frm_node_struct new_node_info2;
	mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (mmi_ecompass_get_cali_result() == MMI_EC_SIGSTN_STRONG)
	{
    g_ecompass_cntxt.sgnstn = MMI_EC_SIGSTN_STRONG;
		mmi_ecompass_set_cali_result(MMI_TRUE);

        /*
		 do {
		mmi_popup_property_struct arg;
		mmi_popup_property_init(&arg);
		arg.callback = mmi_alert_normal_exit_helper;
		arg.user_tag = (void *)(mmi_ecompass_cancel_cali_entry_main_direction_screen);
		mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, &arg);
		} while(0);
        */
	mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, NULL);
	}
	else if (mmi_ecompass_get_cali_result() == MMI_EC_SIGSTN_WEAK)
	{
		g_ecompass_cntxt.sgnstn = MMI_EC_SIGSTN_WEAK;
		mmi_ecompass_set_cali_result(MMI_TRUE);


		 
		mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_EC_CALI_FAIL)), MMI_EVENT_FAILURE, NULL);
	}
	else
	{
		ASSERT(0);
	}

	mmi_ecompass_set_cali_result(MMI_TRUE);
	MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_CALI_IND_DRIVER, g_ecompass_cntxt.sgnstn);

    new_node_info.id = SCR_ID_EC_DIRECTION;
    new_node_info.entry_proc = (mmi_proc_func)mmi_ecompass_entry_direction_main_screen;


    mmi_frm_scrn_replace (GRP_ID_EC_MAIN, SCR_ID_EC_ANIMATION, &new_node_info);
	//HistoryReplace(SCR_ID_EC_ANIMATION, SCR_ID_EC_DIRECTION, mmi_ecompass_entry_direction_main_screen);
	/* set delete screen callback handler as this screen can be deleted by pressing END key even when it is not on the top */
    //mmi_ecompass_entry_direction_main_screen();
    //mmi_frm_scrn_replace(GRP_ID_ROOT, SCR_ID_EC_DIRECTION, &new_node_info2);
    mmi_frm_scrn_set_leave_proc (GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION, mmi_ec_app_leave_proc);
	//SetDelScrnIDCallbackHandler(SCR_ID_EC_DIRECTION, (HistoryDelCBPtr) mmi_ecompass_deinitialize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_get_data_update
 * DESCRIPTION
 *  Function for getting data from driver data callback
 * PARAMETERS
 *  dataMsg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_get_data_update(void *dataMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_ecompass_msg_struct *dataVal = (mmi_ecompass_msg_struct*) dataMsg;
    U16 mecca_deg_from_north = 0;
    U8 mecca_string[(MMI_EC_MECCA_STR_LEN + 1) * ENCODING_LENGTH] = {0};
	S16 local_north;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ecompass_cntxt.curr_north = (S16) dataVal->ec_data;
    MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_MAG_NOR_FRM_DRV, g_ecompass_cntxt.curr_north);

    if ((mmi_frm_scrn_get_active_id() == (U16) SCR_ID_EC_DIRECTION))
    {
        /* calculating geographic north, declination is already known from bootup or after main if updated */
        local_north = mmi_ecompass_calculate_north_declination();
        mecca_deg_from_north = g_ecompass_deg_mecca[g_ecompass_cntxt.curr_city_index] + local_north;     /* curr.north is changed by north_declination */

        if (mecca_deg_from_north > 360) /* if angle in greater than 360 */
        {
            mecca_deg_from_north = mecca_deg_from_north - 360;  /* to show mecca from north calculated above */
        }

        MMI_TRACE(MMI_COMMON_TRC_G2_EXTRA, MMI_ECOMPASS_NOR_PLUS_MECCA_ANG, mecca_deg_from_north);


        mmi_ecompass_mecca_title_string(mecca_string);  /* get direction in the circle */

        wgui_cat126_update_degree((U16) local_north, (U16) mecca_deg_from_north, (UI_string_type) mecca_string);        /* update mecca,north direction and mecca string at top */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_lcd_sleepin_handler
 * DESCRIPTION
 *  Function to Turn off sensor when backlight goes off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//void mmi_ecompass_lcd_sleepin_handler(void)
mmi_ret mmi_ecompass_lcd_sleepin_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_frm_scrn_is_present(GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)) || (mmi_frm_scrn_get_active_id() == (U16) SCR_ID_EC_DIRECTION))
    {
    e_compass_sensor_power_off();   /* power off sensor */
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_lcd_sleepout_handler
 * DESCRIPTION
 *  Function to Turn on sensor when backlight resumes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//void mmi_ecompass_lcd_sleepout_handler(void)
mmi_ret mmi_ecompass_lcd_sleepout_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
	
	
	if ((mmi_frm_scrn_is_present(GRP_ID_EC_MAIN, SCR_ID_EC_DIRECTION, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)) || (mmi_frm_scrn_get_active_id() == (U16) SCR_ID_EC_DIRECTION))
    {
    e_compass_sensor_power_on();    /* power off sensor */
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_get_current_country_index_cat
 * DESCRIPTION
 *  Function to get index of current country to be displayed on screen
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_ecompass_get_current_country_index_cat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S32 country_idx  = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_ecompass_country_indices[country_idx] <= g_ecompass_cntxt.curr_city_index)
   {
	   country_idx++;
   }

   --country_idx;
   return country_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_get_current_city_index_cat
 * DESCRIPTION
 *  Function to get index of current city to be displayed on screen
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_ecompass_get_current_city_index_cat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S32 country_idx  = 0;
	 S32 city_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	 country_idx = mmi_ecompass_get_current_country_index_cat();
    city_idx = g_ecompass_cntxt.curr_city_index - g_ecompass_country_indices[country_idx];
	 return city_idx;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_set_cali_result
 * DESCRIPTION
 *  set calibration result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ecompass_set_cali_result(U8 cali_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_ecompass_cntxt.cali_result = cali_result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ecompass_get_cali_result
 * DESCRIPTION
 *  get calibration result
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
pBOOL mmi_ecompass_get_cali_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_ecompass_cntxt.cali_result;
}

#endif /* __MMI_ECOMPASS__ */ 

