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
 * AzaanAlarm.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Alarm application related screens.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "AzaanAlarmDef.h"
#include "AzaanAlarmProt.h"					//RHR remove

#ifdef __MMI_AZAAN_ALARM__
#include "GpioSrvGprot.h"
#include "AlarmProt.h"
#include "mdi_audio.h"
//#include "SimDetectionGexdcl.h"
#include "conversions.h"
#include "MMI_common_app_trc.h"
#include "ToneSelectorCuiGprot.h"
#include "BootupSrvGprot.h"
#include "ProfilesSrvGprot.h"
#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_app_profiles_def.h"
#include "FileMgrSrvGprot.h"
#include "Inlinecuigprot.h"

//RHR add begin

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_azaan_alarm_def.h"
#include "mmi_rp_app_alarm_def.h"
#include "AlertScreen.h"
//#include "kal_general_types.h"
#include "wgui_inline_edit.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
//#include "mmi_frm_history_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_events_gprot.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "AlarmDef.h"
#include "mmi_rp_app_uiframework_def.h"
#include "wgui_categories_list.h"
#include "mmi_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_scenario_gprot.h"
#include "CommonScreensResDef.h"
#include "gui_typedef.h"
#include "AlarmFrameworkProt.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "NotificationGprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "gui_data_types.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_popup.h"
//#include "SimDetectionDef.h"
#include "custom_srv_prof_defs.h"
#include "custom_led_patterns.h"  
#include "kal_general_types.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_common_app_trc.h"
    
//RHR add end

// charger app srv split
#include "PoweronChargerProt.h"
#include "mmi_rp_srv_reminder_def.h"
#include "gui_touch_feedback.h"

#include "UCMGProt.h"
#include "UcmSrvGprot.h"

mmi_azaan_cntx_struct g_azaan_alm_cntx_struct;


#define APP_SELECT1            CUI_INLINE_ITEM_ID_BASE+1
#define APP_TIME1              CUI_INLINE_ITEM_ID_BASE+2
#define APP_CAPTION1           CUI_INLINE_ITEM_ID_BASE+3
#define APP_DISP_ONLY          CUI_INLINE_ITEM_ID_BASE+4
#define APP_CAPTION2           CUI_INLINE_ITEM_ID_BASE+5
#define APP_SELECT2            CUI_INLINE_ITEM_ID_BASE+6

#define IS_IN_CALL() (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)

U16 g_azaan_alarm_alert_type_string[3] = 
{
    STR_ID_PROF_VIB_AND_RING,
    STR_ID_PROF_RING_ONLY,
    STR_ID_PROF_VIB_ONLY
};

U16 g_azaan_alarm_onoff_string_id[2] = 
{
    STR_GLOBAL_OFF,
    STR_GLOBAL_ON
};

const cui_inline_item_select_struct inline_select1 ={2, 0, g_azaan_alarm_onoff_string_id};

const cui_inline_set_item_time_struct inline_time1 = {{0, 0, 0, 0, 0, 0}, 0};

const cui_inline_item_caption_struct inline_caption1 = {STR_ID_AZAAN_TONE};

const cui_inline_item_display_only_struct inline_disp_only1 = {STR_GLOBAL_0, STR_GLOBAL_0};

const cui_inline_item_caption_struct inline_caption2 = {STR_ID_PROF_ALERT_TYPE};

const cui_inline_item_select_struct inline_select2 ={3, 0, g_azaan_alarm_alert_type_string};

const cui_inline_set_item_struct setting_inline[] = 
{
    {APP_SELECT1,      CUI_INLINE_ITEM_TYPE_SELECT  , IMG_STATUS, (void *)&inline_select1},

    {APP_TIME1,         CUI_INLINE_ITEM_TYPE_TIME,      IMG_TIME, (void *)&inline_time1},

    {APP_CAPTION1,      CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_AZAAN_ALM_TONE, (void *)&inline_caption1},

    {APP_DISP_ONLY,     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void *)&inline_disp_only1},

    {APP_CAPTION2,      CUI_INLINE_ITEM_TYPE_CAPTION,   ALARMS_SET_ALERT_TYPE_IMAGEID, (void* )&inline_caption2},

    {APP_SELECT2,        CUI_INLINE_ITEM_TYPE_SELECT,  0, (void *)&inline_select2},
    
};

const cui_inline_struct g_azaan_alarm_initial_data = 
{
    6,
    STR_GLOBAL_EDIT,
    0, 
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    setting_inline
};

static mmi_id cui_inline_azaan_alarm_gid;
static mmi_id cui_menu_azaan_alarm_parent_gid;
static mmi_ret mmi_azaan_alarm_group_proc(mmi_event_struct* evt);
static void mmi_azaan_alm_inline_select_handler(U32 inline_item_id, U32 param);
static void mmi_azaan_alm_inline_highlight_handler(U32 inline_item_id, U32 param);
static void mmi_azaan_alm_alert_pop_handler(mmi_alert_result_evt_struct *alert_evt);
static CHAR* mmi_azaan_check_tone_extension(const WCHAR* tone_string, const WCHAR *hide_ext);
static srv_prof_ret mmi_azaan_alarm_play_tone_callback(srv_prof_ret result);
static MMI_BOOL mmi_azaan_nmgr_expiry_callback(mmi_scenario_id scen_id, void *arg);


#define AZAAN_DEFAULT_RING_ID AUD_ID_PROF_RING1
#define AZAAN_TONE_IN_CALL SRV_PROF_TONE_SMS_INCALL

mmi_azaan_cntx_struct g_azaan_alm_cntx_struct;
U8 temp_tone_path[SRV_FMGR_PATH_BUFFER_SIZE];

static MMI_BOOL g_display_only_changed;
static U8 g_azaan_tone_path[SRV_FMGR_PATH_BUFFER_SIZE];
extern wgui_inline_item wgui_inline_items[];
 
 
/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_highlight_azaan_alarm
 * DESCRIPTION
 *  Highlight handler for Azaan alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_highlight_azaan_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_azaan_entry_main_menu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_azaan_entry_main_menu, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_entry_main_menu
 * DESCRIPTION
 *  Entry function for the Azaan alarm application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer, i;
    U16 alarm_states_icon[NUM_OF_AZAAN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AZAAN_LIST, NULL, mmi_azaan_entry_main_menu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_AZAAN_LIST);

    if (guiBuffer == NULL)
    {
        g_azaan_alm_cntx_struct.CurrHighlightAlarm = 0;
    }
    /* construct displayed string and icon */
    for (i = 0; i < MMI_AZAAN_ALARM_TOTAL; i++)
    {
        mmi_ucs2cpy((S8*)subMenuDataPtrs[i], (S8*)GetString((U16)(STR_ID_AZAAN_FAJR + i)));

        if (g_azaan_alm_cntx_struct.AzaanAlmList[i].State == SET_STATE)
        {
            alarm_states_icon[i] = CHECKBOX_ON_IMAGE_ID;
        }
        else
        {
            alarm_states_icon[i] = CHECKBOX_OFF_IMAGE_ID;
        }
    }

    ShowCategory53Screen(
        STR_ID_AZAAN_ALARM,
        GetRootTitleIcon(ORGANIZER_ALARM_MENU),
        STR_GLOBAL_EDIT,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_AZAAN_ALARM_TOTAL,
        subMenuDataPtrs,
        alarm_states_icon,
        0,
        0,
        (S32) g_azaan_alm_cntx_struct.CurrHighlightAlarm,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_azaan_prepare_inline, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_azaan_prepare_inline, KEY_EVENT_UP);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_azaan_prepare_inline, KEY_EVENT_UP);

    RegisterHighlightHandler(mmi_azaan_higlight_alm_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_higlight_alm_index
 * DESCRIPTION
 *  Highlight handler of alarm item in azaan alarm screen.
 *  Store current highlight index.
 * PARAMETERS
 *  nIndex      [IN]        Index of current highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_higlight_alm_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_azaan_alm_cntx_struct.CurrHighlightAlarm = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_prepare_inline
 * DESCRIPTION
 *  Prepares for the inline editor screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_prepare_inline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_ORG_AZAAN_CURRENT_ALARM, g_azaan_alm_cntx_struct.CurrHighlightAlarm);
    i = g_azaan_alm_cntx_struct.CurrHighlightAlarm;
    g_display_only_changed = MMI_FALSE;
    /* fill inline selection strings */
    /*g_azaan_alm_cntx_struct.AzaanAlmOnOffString[0] = GetString(STR_GLOBAL_OFF);
    g_azaan_alm_cntx_struct.AzaanAlmOnOffString[1] = GetString(STR_GLOBAL_ON);

    g_azaan_alm_cntx_struct.AzaanAlmAlertTypeStr[MMI_AZAAN_ALERT_VIBRATION_AND_RING] = GetString((U16) STR_VIBRATION_AND_RING);
    g_azaan_alm_cntx_struct.AzaanAlmAlertTypeStr[MMI_AZAAN_ALERT_RING] = GetString((U16) STR_RING);
    g_azaan_alm_cntx_struct.AzaanAlmAlertTypeStr[MMI_AZAAN_ALERT_VIBRATION] = GetString((U16) STR_VIBRATION_ONLY);*/

    /* time string */
    /*AlmGetStringValue(g_azaan_alm_cntx_struct.HourBuff, g_azaan_alm_cntx_struct.AzaanAlmList[i].Hour);
    AlmGetStringValue(g_azaan_alm_cntx_struct.MinBuff, g_azaan_alm_cntx_struct.AzaanAlmList[i].Min);*/
    g_azaan_alm_cntx_struct.curr_hour = g_azaan_alm_cntx_struct.AzaanAlmList[i].Hour;
    g_azaan_alm_cntx_struct.curr_min = g_azaan_alm_cntx_struct.AzaanAlmList[i].Min;

    g_azaan_alm_cntx_struct.CurrHighlightState = g_azaan_alm_cntx_struct.AzaanAlmList[i].State;

    if (g_azaan_alm_cntx_struct.AzaanAlmList[i].AudioValue > 0)
    {
        g_azaan_alm_cntx_struct.CurrHighlightAudioValue = g_azaan_alm_cntx_struct.AzaanAlmList[i].AudioValue;
        if (g_azaan_alm_cntx_struct.AzaanAlmList[i].AudioValue == AZAAN_ALARM_TONE_FILE)
        {
            mmi_ucs2cpy((S8 *)g_azaan_alm_cntx_struct.tone_path, (S8 *)g_azaan_alm_cntx_struct.AzaanAlmList[i].tone_path);
        }
    }
    else
    {
        g_azaan_alm_cntx_struct.CurrHighlightAudioValue = AZAAN_DEFAULT_RING_ID;
    }
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_ORG_AZAAN_HIGHLIGHT_AUDIO, g_azaan_alm_cntx_struct.CurrHighlightAudioValue);

    g_azaan_alm_cntx_struct.CurrHighlightAlertType = g_azaan_alm_cntx_struct.AzaanAlmList[i].AlertType;

    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_ORG_AZAAN_HIGHLIGHT_ALERT, g_azaan_alm_cntx_struct.CurrHighlightAlertType);

    mmi_azaan_entry_azaan_alm_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_entry_azaan_alm_edit
 * DESCRIPTION
 *  Display inline editor screen of alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_entry_azaan_alm_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_azaan_alarm_parent_gid = mmi_frm_group_create(
                                        GRP_ID_ROOT, 
                                        GRP_ID_AUTO_GEN, 
                                        mmi_azaan_alarm_group_proc, 
                                        NULL);
    mmi_frm_group_enter(cui_menu_azaan_alarm_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_inline_azaan_alarm_gid = cui_inline_create(
                                    cui_menu_azaan_alarm_parent_gid,
                                    &g_azaan_alarm_initial_data);

    //RegisterHighlightHandler(mmi_azaan_inline_edit_highlight_handler);
    if (cui_inline_azaan_alarm_gid != GRP_ID_INVALID)
    {
    

    mmi_azaan_fill_inline();
    cui_inline_set_title_icon(cui_inline_azaan_alarm_gid, GetRootTitleIcon(ORGANIZER_ALARM_MENU));

	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_ORG_AZAAN_EXT_TONE_CHANGED, g_display_only_changed);
        /*if (g_display_only_changed == TRUE)
    {
        if ((GetInlineDoneFlag(guiBuffer) == 0))
        {
            SetInlineDoneFlag(guiBuffer);
        }
        set_wgui_inline_list_menu_status(1);
        g_display_only_changed = FALSE;
        }*/
        cui_inline_run(cui_inline_azaan_alarm_gid);
    }
    else
    {
        cui_inline_close(cui_inline_azaan_alarm_gid);
        mmi_frm_group_close(cui_menu_azaan_alarm_parent_gid);
    }
    }
	

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_group_proc
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_azaan_alarm_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
   //     mmi_frm_group_close(cui_inline_azaan_alarm_gid);
        break;
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
    {
        if (g_display_only_changed)
        {
    		U16 sel_tone;
            U16 string_id;
    		CHAR* tone_string;
            U32 scr_attr = cui_inline_get_screen_attributes(cui_inline_azaan_alarm_gid);
            
            if (!(scr_attr & CUI_INLINE_SCREEN_CHANGED))
            {
                cui_inline_set_screen_attributes(cui_inline_azaan_alarm_gid, 
                                                 CUI_INLINE_SET_ATTRIBUTE, 
                                                 CUI_INLINE_SCREEN_CHANGED);
            }
            //mmi_alm_get_tone_string(&temp_string);
    		
				sel_tone = g_azaan_alm_cntx_struct.CurrHighlightAudioValue;
		    if(g_azaan_alm_cntx_struct.CurrHighlightAudioValue == AZAAN_ALARM_TONE_FILE)
		    {
		        /*mmi_ucs2cpy((S8*) temp_tone_path, (S8*) g_azaan_alm_cntx_struct.tone_path);
                srv_fmgr_path_hide_extension((WCHAR *)temp_tone_path);
                tone_string = (S8*)srv_fmgr_path_get_filename_ptr((WCHAR *)temp_tone_path);*/
                if (srv_fmgr_fs_path_exist((const WCHAR *)g_azaan_alm_cntx_struct.tone_path) < 0)
		        {
			        string_id = srv_prof_get_string_id_from_srv_audio_id(AZAAN_DEFAULT_RING_ID);
        			
        	        if (string_id != NULL)
    		        {
    			        tone_string = GetString(string_id);
    			        g_azaan_alm_cntx_struct.CurrHighlightAudioValue = AZAAN_DEFAULT_RING_ID;
    		        }
			        else
			        {
                        g_azaan_alm_cntx_struct.CurrHighlightAudioValue = 0;
                        tone_string = GetString(STR_GLOBAL_EMPTY);
			        }
		        }
		        else
		        {
		            tone_string = mmi_azaan_check_tone_extension((const WCHAR *)g_azaan_alm_cntx_struct.tone_path, L"mp3");
                }
		    }
		    else if ((string_id = srv_prof_get_string_id_from_srv_audio_id(sel_tone)) != 0)
		    {
		        tone_string = GetString(string_id);
		    }		    
		    else
		    {
		        tone_string = GetString(STR_GLOBAL_EMPTY_LIST);
		    }
		
		    cui_inline_set_value(cui_inline_azaan_alarm_gid, 
		                         APP_DISP_ONLY, 
		                         (void*) tone_string);

            g_display_only_changed = MMI_FALSE;
            }

            break;
    }
    case EVT_ID_CUI_INLINE_SUBMIT:
    {
        mmi_azaan_save_confirm();
        
        break;
    }    

    case EVT_ID_CUI_INLINE_NOTIFY:
    {
        cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct *)evt;
        if (inline_evt->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
        {
            mmi_azaan_alm_inline_highlight_handler(
                inline_evt->item_id, // - CUI_INLINE_ITEM_ID_BASE,
                inline_evt->param);
        }
        else if (inline_evt->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
        {
            mmi_azaan_alm_inline_select_handler(
                inline_evt->item_id,
                inline_evt->param);
        }
    }
    break;
            
    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *abortEvt = (cui_event_inline_abort_struct*) evt;
            cui_inline_close(abortEvt->sender_id);
        }
            
        break;
            
    case EVT_ID_CUI_INLINE_GROUP_DEINIT:
    {
#if defined(__MMI_ALM_CUSTOMIZE_TONE__) && defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
            //mmi_frm_scrmem_free((void*)g_alm_ext_melody_short_name_ptr);
           g_azaan_ext_melody_struct.ext_melody_short_name_ptr = NULL;
#endif /*defined(__MMI_ALM_CUSTOMIZE_TONE__) && defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)*/

    }
    break;

    case EVT_ID_ALERT_QUIT:
    {
        mmi_azaan_alm_alert_pop_handler((mmi_alert_result_evt_struct *)evt);
    }
    break;
        
    default:
        break;
    }
	
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_tone_notify_hdlr
 * DESCRIPTION
 *  Notify azaan alarm about memory card related events.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_azaan_tone_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/

	
    /*----------------------------------------------------------------*/
    /* Code Body                                                     					 */
    /*----------------------------------------------------------------*/
	switch(event->evt_id)
    {
       	case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT: /* MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT */
    	{
			//srv_fmgr_notification_dev_plug_event_struct *fmgr_plug
	                //= (srv_fmgr_notification_dev_plug_event_struct*)event;
	
	if (g_azaan_alm_cntx_struct.is_tone_playing)
	{
              mdi_audio_stop_all();
	       g_azaan_alm_cntx_struct.is_tone_playing= MMI_FALSE;
				mmi_azaan_play_azaan_tone();
	}
    }
	break;
	
    default:
        break;
    }
	return MMI_RET_OK;
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_check_tone_extension
 * DESCRIPTION
 *  Initialize inline structure of input screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static CHAR* mmi_azaan_check_tone_extension(const WCHAR* tone_string, const WCHAR *hide_ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/
    CHAR* temp_string;
	WCHAR *ext_ptr;
	const WCHAR *const_ext_ptr;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                     					 */
    /*----------------------------------------------------------------*/
	temp_string = (S8*)srv_fmgr_path_get_filename_ptr((WCHAR*)tone_string);
	const_ext_ptr = srv_fmgr_path_get_extension_const_ptr(tone_string);
	
	if (const_ext_ptr == NULL)
	{
		return temp_string;
	}
	if (mmi_ucs2icmp((const CHAR*)const_ext_ptr, (const CHAR*)hide_ext) != 0)
	{
		return temp_string;
	}
	
    /* Only show file name */
	mmi_ucs2cpy(g_azaan_tone_path, temp_string);
	ext_ptr = srv_fmgr_path_get_extension_ptr((WCHAR*)g_azaan_tone_path);
	*(ext_ptr - 1) = 0;
	
	return g_azaan_tone_path;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_inline_select_handler
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  inline    :[IN] inline id
 *  param     :[IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_azaan_alm_inline_select_handler(U32 inline_item_id, U32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inline_item_id == APP_SELECT1)
    {
        cui_inline_get_value(cui_inline_azaan_alarm_gid, 
                             (U16)(APP_SELECT1), 
                             (void*)&g_azaan_alm_cntx_struct.CurrHighlightState);
    }
    else if (inline_item_id == APP_SELECT2)
    {
        cui_inline_get_value(cui_inline_azaan_alarm_gid, 
                             (U16)(APP_SELECT2), 
                             &g_azaan_alm_cntx_struct.CurrHighlightAlertType);
    }

    }
	

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_inline_highlight_handler
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_azaan_alm_inline_highlight_handler(U32 inline_item_id, U32 param)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inline_item_id == APP_CAPTION1 || inline_item_id == APP_DISP_ONLY)
    {
        cui_inline_set_softkey_icon(cui_inline_azaan_alarm_gid, 
                                        APP_DISP_ONLY, 
                                        MMI_LEFT_SOFTKEY, 
                                        0);

        cui_inline_set_softkey_icon(cui_inline_azaan_alarm_gid, 
                                        APP_DISP_ONLY, 
                                        MMI_CENTER_SOFTKEY,
                                        IMG_GLOBAL_COMMON_CSK);

        cui_inline_set_softkey_text(cui_inline_azaan_alarm_gid, 
                                    APP_DISP_ONLY, 
                                    MMI_LEFT_SOFTKEY, 
                                    STR_GLOBAL_SELECT);
        //SetLeftSoftkeyFunction(mmi_azaan_entry_tone_selector, KEY_EVENT_UP);
        wgui_inline_set_lsk_function(mmi_azaan_entry_tone_selector);
        SetCenterSoftkeyFunction(mmi_azaan_entry_tone_selector, KEY_EVENT_UP);
        
    
        /*ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        cui_inline_set_softkey_icon(g_alm_cntx.curr_gid, 
                                    CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_STRING, 
                                    MMI_LEFT_SOFTKEY, 
                                    0);

        cui_inline_set_softkey_text(g_alm_cntx.curr_gid, 
                                    CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_STRING, 
                                    MMI_LEFT_SOFTKEY, 
                                    0);
        }
        else
        {
            cui_inline_set_softkey_icon(g_alm_cntx.curr_gid, 
                                        CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_STRING, 
                                        MMI_LEFT_SOFTKEY, 
                                        IMG_GLOBAL_OPTIONS);

            cui_inline_set_softkey_text(g_alm_cntx.curr_gid, 
                                        CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_STRING, 
                                        MMI_LEFT_SOFTKEY, 
                                        STR_GLOBAL_OPTIONS);
            
            SetLeftSoftkeyFunction(mmi_alm_entry_aud_opt_fmrdo, KEY_EVENT_UP);
        }*/
    }  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_alert_pop_handler
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_azaan_alm_alert_pop_handler(mmi_alert_result_evt_struct *alert_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 user_tag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(alert_evt->result)
    {
        case MMI_POPUP_NORMAL_EXIT:
			user_tag = *(U16*)alert_evt->user_tag;
            if (user_tag == STR_GLOBAL_SAVED)
            {
                mmi_frm_group_close(cui_inline_azaan_alarm_gid);
            }            
            break;

        case MMI_ALERT_CNFM_YES:
			//user_tag = *(U16*)alert_evt->user_tag;
            //if (user_tag == STR_GLOBAL_SAVE_ASK)
            //{
                mmi_azaan_save_inline();
            //}
            /*else if (user_tag == STR_ID_ALM_DISABLE_ASK)
            {
                //
                g_azaan_alm_cntx_struct.CurrHighlightState = 0;
                mmi_azaan_save_inline();
            }*/

            break;
                
        case MMI_ALERT_CNFM_NO:
			//user_tag = *(U16*)alert_evt->user_tag;
            //if (user_tag == STR_GLOBAL_SAVE_ASK)

            //{
                //mmi_azaan_go_back_main_menu();
            mmi_frm_group_close(cui_inline_azaan_alarm_gid);
            /*}
            else
            {
                mmi_frm_scrn_close_active_id();
            }*/
            
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_save_confirm
 * DESCRIPTION
 *  Displays confirmation pop-up to save the azaan alarm's changed settings.
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg_confirm;
    mmi_popup_property_struct arg_popup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_azaan_alm_cntx_struct.CurrHighlightAudioValue == AZAAN_ALARM_TONE_FILE)
    {
        if (srv_fmgr_fs_path_exist((WCHAR *)g_azaan_alm_cntx_struct.tone_path) < 0)
        {
            mmi_popup_property_init(&arg_popup);
        
            arg_popup.parent_id = cui_inline_azaan_alarm_gid;
            arg_popup.callback = (mmi_proc_func)mmi_azaan_alm_alert_pop_handler;
            g_azaan_alm_cntx_struct.user_tag = STR_GLOBAL_INVALID_FILENAME;
            arg_popup.user_tag = &g_azaan_alm_cntx_struct.user_tag;
            
            mmi_popup_display((WCHAR*)GetString(STR_ID_AZAAN_ALM_TONE_FILE_NOT_AVAILABLE),
                              MMI_EVENT_FAILURE, 
                              &arg_popup); 

            return;
        }
    }
    mmi_confirm_property_init(&arg_confirm, CNFM_TYPE_YESNO);
    arg_confirm.parent_id = cui_inline_azaan_alarm_gid;
    arg_confirm.callback = (mmi_proc_func)mmi_azaan_alm_alert_pop_handler;
    
    g_azaan_alm_cntx_struct.user_tag = STR_GLOBAL_SAVE_ASK;
    arg_confirm.user_tag = &g_azaan_alm_cntx_struct.user_tag;
    
    mmi_confirm_display((WCHAR*)GetString(STR_GLOBAL_SAVE_ASK), 
                        MMI_EVENT_QUERY, 
                        &arg_confirm);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_save_inline
 * DESCRIPTION
 *  Save azaan alarm to nvram and set/cancel azaan alarm to driver accordingly.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_save_inline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_azaan_is_inline_editor_changed(g_azaan_alm_cntx_struct.CurrHighlightAlarm))
    {
        i = g_azaan_alm_cntx_struct.CurrHighlightAlarm;
        
        g_azaan_alm_cntx_struct.AzaanAlmList[i].State = (U8) g_azaan_alm_cntx_struct.CurrHighlightState;
        g_azaan_alm_cntx_struct.AzaanAlmList[i].Hour = g_azaan_alm_cntx_struct.curr_hour;
        g_azaan_alm_cntx_struct.AzaanAlmList[i].Min = g_azaan_alm_cntx_struct.curr_min;

        if (g_azaan_alm_cntx_struct.CurrHighlightAudioValue != 0)
        {
            g_azaan_alm_cntx_struct.AzaanAlmList[i].AudioValue = (U16) g_azaan_alm_cntx_struct.CurrHighlightAudioValue;

            if (g_azaan_alm_cntx_struct.AzaanAlmList[i].AudioValue == AZAAN_ALARM_TONE_FILE)
            {
                mmi_ucs2cpy((S8*)g_azaan_alm_cntx_struct.AzaanAlmList[i].tone_path, (S8*)g_azaan_alm_cntx_struct.tone_path);
        }
        }
        else    /* Should not enter here because it already check before save */
        {
            g_azaan_alm_cntx_struct.AzaanAlmList[i].AudioValue = AZAAN_DEFAULT_RING_ID;
        }

        g_azaan_alm_cntx_struct.AzaanAlmList[i].AlertType = (U8) g_azaan_alm_cntx_struct.CurrHighlightAlertType;

        mmi_azaan_save_to_nvram();

		srv_reminder_cancel(SRV_REMINDER_TYPE_AZAAN, i);
		
        if (g_azaan_alm_cntx_struct.CurrHighlightState == SET_STATE)
        {
            MYTIME time;
			
			GetDateTime(&time);
			time.nHour = g_azaan_alm_cntx_struct.curr_hour;;
			time.nMin = g_azaan_alm_cntx_struct.curr_min;
			time.nSec = 0;

			time = srv_reminder_calc_time(&time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
            
            srv_reminder_set(SRV_REMINDER_TYPE_AZAAN, &time, i);
            //AlmSetAlarm((U8) (i + ALM_AZAAN_START));
        }
    }

        //mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_SAVED)), MMI_EVENT_SUCCESS, NULL);
    mmi_popup_property_init(&arg);
    
    arg.parent_id = GRP_ID_ROOT;//GRP_ID_ALM_EDITOR;
    arg.callback = (mmi_proc_func)mmi_azaan_alm_alert_pop_handler;
	g_azaan_alm_cntx_struct.user_tag = STR_GLOBAL_SAVED;
    arg.user_tag = &g_azaan_alm_cntx_struct.user_tag;
    
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED),
                      MMI_EVENT_SUCCESS, 
                      &arg);

        //DeleteUptoScrID(SCR_ID_AZAAN_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_is_inline_editor_changed
 * DESCRIPTION
 *  To check if azaan alarm is changed in inline editor screen.
 * PARAMETERS
 *  index       [IN]        Index of inline selection
 * RETURNS
 *  TURE if azaan alarm is changed; otherwise, FLASE.
 *****************************************************************************/
BOOL mmi_azaan_is_inline_editor_changed(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_set_item_time_struct inline_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(cui_inline_azaan_alarm_gid, 
                         APP_TIME1, 
                         &inline_time);
    
    g_azaan_alm_cntx_struct.curr_hour = (U8)inline_time.date_time.hour;
    g_azaan_alm_cntx_struct.curr_min = (U8)inline_time.date_time.minute;
    if (
           (g_azaan_alm_cntx_struct.AzaanAlmList[index].State != g_azaan_alm_cntx_struct.CurrHighlightState) ||
           (g_azaan_alm_cntx_struct.AzaanAlmList[index].Hour != g_azaan_alm_cntx_struct.curr_hour) || (g_azaan_alm_cntx_struct.AzaanAlmList[index].Min != g_azaan_alm_cntx_struct.curr_min))
    {
        return TRUE;
    }
    else if (g_azaan_alm_cntx_struct.AzaanAlmList[index].AudioValue != g_azaan_alm_cntx_struct.CurrHighlightAudioValue)
    {
        return TRUE;
    }
    else if (g_azaan_alm_cntx_struct.AzaanAlmList[index].AlertType != (U8) g_azaan_alm_cntx_struct.CurrHighlightAlertType)
    {
        return TRUE;
    }
    else if (mmi_ucs2cmp((S8*) g_azaan_alm_cntx_struct.AzaanAlmList[index].tone_path, (S8*) g_azaan_alm_cntx_struct.tone_path))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_save_to_nvram
 * DESCRIPTION
 *  Write azaan alarm data to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_save_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_AZAAN_ALARM_LID, 
                (U16)(g_azaan_alm_cntx_struct.CurrHighlightAlarm + 1), 
                (void*)&g_azaan_alm_cntx_struct.AzaanAlmList[(U8)g_azaan_alm_cntx_struct.CurrHighlightAlarm], 
                NVRAM_AZAAN_ALARM_SIZE, 
                &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_entry_tone_selector
 * DESCRIPTION
 *  Tone list generating API
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_entry_tone_selector(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id azaan_gid;
    mmi_id ts_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    azaan_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_azaan_group_proc, NULL); 
    mmi_frm_group_enter(azaan_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if ((ts_gid = cui_tone_selector_create(azaan_gid)) != GRP_ID_INVALID)
    {
        U16 filter = 0;
        
        CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_RING);
        //CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_TYPE_MIDI);
        CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_EXT_FILE);
        cui_tone_selector_set_filter(ts_gid, filter);
        cui_tone_selector_set_title_id(ts_gid, STR_ID_AZAAN_TONE, GetRootTitleIcon(ORGANIZER_ALARM_MENU));
        cui_tone_selector_set_highlight_tone (ts_gid, g_azaan_alm_cntx_struct.CurrHighlightAudioValue/*selected_tone_id*/);
        
        cui_tone_selector_run(ts_gid);
    }
    else
    {
        mmi_frm_group_close(azaan_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_azaan_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tone_selector_evt_struct * evt_cui;
    //mmi_profiles_tone_struct tonesetup;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_TONE_SELECTOR_CLOSE_REQUEST:
        {
            evt_cui = (cui_tone_selector_evt_struct *)evt;
            cui_tone_selector_close(evt_cui->sender_id);
            break;
        }
        case EVT_ID_CUI_TONE_SELECTOR_RESULT:
        {
            evt_cui = (cui_tone_selector_evt_struct *)evt;
            if (evt_cui->is_default_sound)
            {
            g_azaan_alm_cntx_struct.CurrHighlightAudioValue = evt_cui->selected_tone;
            g_display_only_changed = MMI_TRUE;
            break;
        }
            else
            {
                S32 ret;                
                srv_fmgr_fileinfo_struct file_info;
                
                ret = cui_tone_selector_get_selected_filepath(evt_cui->sender_id, 
                                                              &file_info, 
                                                              (WCHAR *)g_azaan_alm_cntx_struct.tone_path, 
                                                              SRV_FMGR_PATH_BUFFER_SIZE);
                if (ret < 0)
                {
                    /* Do something*/
                }
                else
                {
                    g_azaan_alm_cntx_struct.CurrHighlightAudioValue = AZAAN_ALARM_TONE_FILE;
                    g_display_only_changed = MMI_TRUE;
                }
            }
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_fill_inline
 * DESCRIPTION
 *  Initialize inline structure of input screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_fill_inline()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_set_item_time_struct time_struct;
    applib_time_struct curr_time;
    U16 sel_tone;
    CHAR *tone_string;
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* ON/OFF */
    cui_inline_set_value(cui_inline_azaan_alarm_gid, 
                         APP_SELECT1, 
                         (void*)g_azaan_alm_cntx_struct.CurrHighlightState);
    cui_inline_set_item_attributes(cui_inline_azaan_alarm_gid, 
                                   APP_SELECT1,
                                   CUI_INLINE_SET_ATTRIBUTE,
                                   CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT);

    /* time */
    GetDateTime(&curr_time);

    time_struct.date_format = 0;
    time_struct.date_time.year = curr_time.nYear;
    time_struct.date_time.month = curr_time.nMonth;
    time_struct.date_time.day = curr_time.nDay;

    time_struct.date_time.hour = g_azaan_alm_cntx_struct.AzaanAlmList[g_azaan_alm_cntx_struct.CurrHighlightAlarm].Hour;
    time_struct.date_time.minute = g_azaan_alm_cntx_struct.AzaanAlmList[g_azaan_alm_cntx_struct.CurrHighlightAlarm].Min;
    time_struct.date_time.second = curr_time.nSec;

    cui_inline_set_value(cui_inline_azaan_alarm_gid, 
                         APP_TIME1, 
                         &time_struct);
    cui_inline_set_item_attributes(cui_inline_azaan_alarm_gid, 
                                   APP_TIME1,
                                   CUI_INLINE_SET_ATTRIBUTE,
                                   CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT);
    sel_tone = g_azaan_alm_cntx_struct.CurrHighlightAudioValue;
    if(g_azaan_alm_cntx_struct.CurrHighlightAudioValue == AZAAN_ALARM_TONE_FILE)
    {
        if (srv_fmgr_fs_path_exist((const WCHAR *)g_azaan_alm_cntx_struct.tone_path) < 0)
		{
			string_id = srv_prof_get_string_id_from_srv_audio_id(AZAAN_DEFAULT_RING_ID);
			
        	if (string_id != NULL)
    		{
    			tone_string = GetString(string_id);
    			g_azaan_alm_cntx_struct.CurrHighlightAudioValue = AZAAN_DEFAULT_RING_ID;
    		}
			else
			{
                g_azaan_alm_cntx_struct.CurrHighlightAudioValue = 0;
                tone_string = GetString(STR_GLOBAL_EMPTY);
			}
		}
		else
		{
		    tone_string = mmi_azaan_check_tone_extension((const WCHAR *)g_azaan_alm_cntx_struct.tone_path, L"mp3");
        }
    }
    else if ((string_id = srv_prof_get_string_id_from_srv_audio_id(sel_tone)) != 0)
    {
        tone_string = GetString(string_id);
    }
    
    else
    {
        tone_string = GetString(STR_GLOBAL_EMPTY_LIST);
    }

    cui_inline_set_value(cui_inline_azaan_alarm_gid, 
                         APP_DISP_ONLY, 
                         (void*) tone_string);
    cui_inline_set_value(cui_inline_azaan_alarm_gid, 
                         APP_SELECT2, 
                         (void*) g_azaan_alm_cntx_struct.CurrHighlightAlertType);
    cui_inline_set_item_attributes(cui_inline_azaan_alarm_gid, 
                                   APP_SELECT2,
                                   CUI_INLINE_SET_ATTRIBUTE,
                                   CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_time_editor_callback
 * DESCRIPTION
 *  Callback function for inline time editor.
 * PARAMETERS
 *  string_buffer       [IN/OUT]        Buffer to store the result of time
 *  hours_buffer        [IN]            Buffer to store hour string
 *  min_buffer          [IN]            Buffer to store minute string
 *  AM_PM_flag          [IN]            Flag to indicate the time format of time string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_time_editor_callback(U8 *string_buffer, U8 *hours_buffer, U8 *min_buffer, U8 *AM_PM_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) string_buffer, (S8*) hours_buffer);
    mmi_ucs2cat((S8*) string_buffer, (S8*) L":");
    mmi_ucs2cat((S8*) string_buffer, (S8*) min_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_exit_alm_screen
 * DESCRIPTION
 *  Exit function for inline editor screen of alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_exit_alm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_AZAAN_EDITOR, mmi_azaan_entry_azaan_alm_edit);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_alm_init_cb
 * DESCRIPTION
 *  Set callback functions needed by alarm framework.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
// void mmi_azaan_alm_init_cb(void)
//{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_alm_set_start_index(ALM_TYPE_AZAAN, ALM_AZAAN_START);
//    AlmSetExpiryTimeCB(ALM_TYPE_AZAAN, mmi_azaan_alm_expiry_time_callback);
//    AlmSetExpiryHandlerCB(ALM_TYPE_AZAAN, mmi_azaan_alm_expiry_callback);
//    AlmSetInitHandlerCB(ALM_TYPE_AZAAN, mmi_azaan_alm_init_nvram, mmi_azaan_alm_reinit_queue_callback);
//    AlmSetStopAlarmCB(ALM_TYPE_AZAAN, mmi_azaan_alm_stop_handler);
//}

/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_alm_init_cb_hdlr
 * DESCRIPTION
 *  Set callback function needed by azaan alarm
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_azaan_alm_init_cb_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_reminder_evt_struct *remdr_evt;
	U16 period;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
	{
		return MMI_RET_OK;
	}
	
	remdr_evt = (srv_reminder_evt_struct *)evt;
	if (remdr_evt->reminder_type != SRV_REMINDER_TYPE_AZAAN && 
		remdr_evt->reminder_type != SRV_REMINDER_TYPE_TOTAL)
	{
		return MMI_RET_OK;
	}
	
	switch(remdr_evt->notify)
	{
		case SRV_REMINDER_NOTIFY_INIT:
			mmi_azaan_alm_init_nvram();
			break;
			
		case SRV_REMINDER_NOTIFY_EXPIRY:
			mmi_azaan_alm_expiry_callback(remdr_evt->usr_data, &period, !remdr_evt->pwr_off);
			break;

		case SRV_REMINDER_NOTIFY_DEINIT:
			mmi_azaan_alm_stop_handler();
			break;
		case SRV_REMINDER_NOTIFY_REINIT:
			mmi_azaan_alm_reinit_queue_callback();
			break;

		default:
			break;
}

	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_alm_expiry_time_callback
 * DESCRIPTION
 *  Callback handler to get information of alarm expiry setting.
 * PARAMETERS
 *  index           [IN]            
 *  alarmTime       [IN/OUT]             
 *  Freq            [IN/OUT]             
 *  WeekDays        [IN/OUT]             
 *  preReminder     [IN/OUT]        Expiry time set by user
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_alm_expiry_time_callback(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME *preReminder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&currTime);
    alarmTime->nYear = currTime.nYear;
    alarmTime->nMonth = currTime.nMonth;
    alarmTime->nDay = currTime.nDay;
    alarmTime->DayIndex = DOW(alarmTime->nYear, alarmTime->nMonth, alarmTime->nDay);

    alarmTime->nHour = g_azaan_alm_cntx_struct.AzaanAlmList[index].Hour;
    alarmTime->nMin = g_azaan_alm_cntx_struct.AzaanAlmList[index].Min;
    *Freq = ALM_FREQ_EVERYDAY;
    *WeekDays = 0;
}

//MMI_BOOL mmi_azaan_alm_expiry_entry(mmi_scenario_id scen_id, void *arg)
//{
//    mmi_azaan_indication_screen();
//
//    return MMI_TRUE;
//}

/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_alm_expiry_callback
 * DESCRIPTION
 *  CallBack handler to execute alarm expiry.
 * PARAMETERS
 *  index           [IN]        
 *  period          [?]         
 *  power_on        [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_azaan_alm_expiry_callback(U8 index, U16 *period, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL ret;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

	g_azaan_alm_cntx_struct.active_alm_idx = index;
	
    if (power_on)
    {
        update_mainlcd_dt_display();
    }
    else
    {
        AlmInitLCDModule();
    }

	ret = mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_REMINDER_AZAAN,
                                         MMI_EVENT_REMINDER_ALARM,
                                         mmi_azaan_nmgr_expiry_callback,
                                         NULL);

    if (ret)
    {
        return ALM_HAS_IND;
    }
 
    return ALM_HAS_NO_IND;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_alm_init_nvram
 * DESCRIPTION
 *  Fills the azaan alarm list data structure with values from the NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_alm_init_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 index;
    //U8 nvram_buf[NVRAM_AZAAN_ALARM_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < NUM_OF_AZAAN; index++)
    {
    	ReadRecord(NVRAM_EF_AZAAN_ALARM_LID, 
    	            (index + 1), 
    	            (void*)&g_azaan_alm_cntx_struct.AzaanAlmList[index], 
    	            NVRAM_AZAAN_ALARM_SIZE, 
    	            &error);
    	//memcpy(g_azaan_alm_cntx_struct.AzaanAlmList[index], nvram_buf, NVRAM_AZAAN_ALARM_SIZE);
    }

	g_azaan_alm_cntx_struct.active_alm_idx = 0xFF;
	g_azaan_alm_cntx_struct.is_tone_playing = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_alm_reinit_queue_callback
 * DESCRIPTION
 *  Callback handler of reiniting azaan alarm to alarm queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_alm_reinit_queue_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < NUM_OF_AZAAN; index++)
    {
        if (g_azaan_alm_cntx_struct.AzaanAlmList[index].State == 1)
        {
            MYTIME time;
			
			GetDateTime(&time);
			time.nHour = g_azaan_alm_cntx_struct.AzaanAlmList[index].Hour;
			time.nMin = g_azaan_alm_cntx_struct.AzaanAlmList[index].Min;
			time.nSec = 0;

			time = srv_reminder_calc_time(&time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
			srv_reminder_set(SRV_REMINDER_TYPE_AZAAN, &time, index);
            //AlmInsertIntoQueue((U8) (index + ALM_AZAAN_START), FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_alm_stop_handler
 * DESCRIPTION
 *  Stop handler for azaan alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_alm_stop_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
    g_azaan_alm_cntx_struct.is_save_to_history = 0;

    srv_backlight_turn_off();

    mmi_azaan_stop_azaan_tone();

	mmi_frm_end_scenario(MMI_SCENARIO_ID_REMINDER_AZAAN);

    i = g_azaan_alm_cntx_struct.active_alm_idx;

    if (i >= NUM_OF_AZAAN)
    {
        return;
    }

    mmi_exit_azaan_ind_screen();
	srv_reminder_notify_finish(MMI_TRUE);

	//g_azaan_alm_cntx_struct.active_alm_idx = NUM_OF_AZAAN;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_indication_screen
 * DESCRIPTION
 *  Display indication screen and play alarm tone when alarm expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_indication_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 almindex = g_azaan_alm_cntx_struct.active_alm_idx;
	
    MYTIME currTime;
    U8 timeString[SIZE_OF_ALARM_STRING];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	 if (!mmi_frm_scrn_enter(
             GRP_ID_AZAAN_IND, 
             SCR_ID_AZAAN_ALM_INDICATION, 
             mmi_azaan_exit_indication_screen, 
             (FuncPtr)mmi_azaan_indication_screen, 
             MMI_FRM_FULL_SCRN))
    {
    	return;
    }
	 
    StopTimer(ALARM_TIMER_WAIT_FOR_CALL);
    if (!IsMyTimerExist(ALARM_ALERT_NOTIFYDURATION_TIMER))
    {
        StartTimer(ALARM_ALERT_NOTIFYDURATION_TIMER, ALM_EXPIRE_DURATION, mmi_azaan_alm_stop_handler);
    }
    //DeleteScreenIfPresent(SCR_ID_AZAAN_ALM_INDICATION);
    mmi_frm_start_scenario(MMI_SCENARIO_ID_REMINDER_AZAAN);
    //EntryNewScreen(SCR_ID_AZAAN_ALM_INDICATION, mmi_azaan_exit_indication_screen, NULL, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_AZAAN_ALM_INDICATION, (HistoryDelCBPtr)mmi_azaan_stop_alarm_by_delete_screen);
    DeleteScreenIfPresent(SCR_ID_ALM_PWRON_CONFIRM);

    mdi_audio_suspend_background_play();
    
    mmi_ucs2cpy((S8*) subMenuDataPtrs, GetString((S16) (STR_ID_AZAAN_FAJR + almindex)));
    GetDateTime(&currTime);
    time_string(&currTime, (UI_string_type) timeString, DT_IDLE_SCREEN);
    mmi_ucs2cat((S8*) subMenuDataPtrs, (S8*) L"\n");
    mmi_ucs2cat((S8*) subMenuDataPtrs, (S8*) timeString);
    
    /* flush key because alarm if some key is not released, the alarm may be stopped */
    ClearKeyEvents();

    g_azaan_alm_cntx_struct.is_save_to_history = 1;

    guiBuffer = GetCurrGuiBuffer(SCR_ID_AZAAN_ALM_INDICATION);        

    ShowCategory121Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        (U8*)subMenuDataPtrs,
        ALARM_ANIMATION_INDICATION_IMAGEID,
        guiBuffer,
        1);

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    SetLeftSoftkeyFunction(mmi_azaan_alm_stop_handler, KEY_EVENT_UP);
    SetKeyHandler(mmi_azaan_alm_stop_handler, KEY_END, KEY_EVENT_DOWN);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_azaan_alm_stop_handler, KEY_EVENT_UP);

    /* register END key for power on alarm */
    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_ALARM)
    {
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        
    #ifdef __MMI_POWER_ON_OFF_BY_POWER_KEY__     
    	ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    	
        ClearKeyHandler(KEY_POWER, KEY_EVENT_UP);
        ClearKeyHandler(KEY_POWER, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_azaan_handle_end_key, KEY_POWER, KEY_LONG_PRESS);                
    #else
    	SetKeyHandler(mmi_azaan_handle_end_key, KEY_END, KEY_LONG_PRESS);
    #endif
        
        mmi_charbat_update_status_icon();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_stop_alarm_by_delete_screen
 * DESCRIPTION
 *  When azaan alarm screen is deleted by USB, the callback function will be executed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/    
U8 mmi_azaan_stop_alarm_by_delete_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
	srv_reminder_notify_finish(MMI_TRUE);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_play_azaan_tone
 * DESCRIPTION
 *  Play azaan alarm tone if it's not playing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_play_azaan_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 alarm_index = g_azaan_alm_cntx_struct.active_alm_idx;
    U8 alert_type;
    srv_prof_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(alarm_index < NUM_OF_AZAAN);
	
    alert_type = g_azaan_alm_cntx_struct.AzaanAlmList[alarm_index].AlertType;
    if (alert_type == ALM_ALERT_VIBRATION)
    {
        return;
    }
	
    if (!g_azaan_alm_cntx_struct.is_tone_playing)
        { 
        if (mmi_is_redrawing_bk_screens())
        {
            return;
        }
        
	g_azaan_alm_cntx_struct.is_tone_playing = MMI_TRUE;
			
        if (g_azaan_alm_cntx_struct.AzaanAlmList[alarm_index].AudioValue == AZAAN_ALARM_TONE_FILE)
        {
            ret = srv_prof_play_tone_with_filepath(
                                                SRV_PROF_TONE_ALARM, 
                                                (WCHAR*)g_azaan_alm_cntx_struct.AzaanAlmList[alarm_index].tone_path, 
                                                SRV_PROF_RING_TYPE_REPEAT, 
                                                mmi_azaan_alarm_play_tone_callback);
             if (ret == SRV_PROF_RET_FAIL)
             {
                 srv_prof_play_tone_with_id(SRV_PROF_TONE_ALARM, 
                                        AZAAN_DEFAULT_RING_ID, 
                       SRV_PROF_RING_TYPE_REPEAT, 
                       NULL);
            }
  
        }
        else
        {
            srv_prof_play_tone_with_id(SRV_PROF_TONE_ALARM, 
                g_azaan_alm_cntx_struct.AzaanAlmList[alarm_index].AudioValue,
                                     SRV_PROF_RING_TYPE_REPEAT, 
                                     NULL);
        }
    }
    }

/*****************************************************************************
* FUNCTION
*  mmi_alm_play_tone_callback
* DESCRIPTION
*  Get Snooze Interval
* PARAMETERS
*  void
* RETURNS
*  Snooze interval
*****************************************************************************/
static srv_prof_ret mmi_azaan_alarm_play_tone_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 alarm_index = g_alm_frm_cntx.CurrAlmIndex - ALM_AZAAN_START;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RETURN_VAL_IF_FAIL(alarm_index < NUM_OF_AZAAN, SRV_PROF_RET_NO);
	
    if (result != SRV_PROF_RET_PLAY_FINISHED)
    {
        srv_prof_play_tone(SRV_PROF_TONE_ALARM, NULL);
    }
     
    return SRV_PROF_RET_YES;
}

#define NMGR_HANDLER
/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_nmgr_evt_tone_handlr
 * DESCRIPTION
 *  Display indication screen and play alarm tone when alarm expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_azaan_nmgr_evt_tone_handlr(void *param)
{
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
#endif
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_custom_evt_struct *evt = (mmi_nmgr_custom_evt_struct*)param;
    U8 azaan_index = g_azaan_alm_cntx_struct.active_alm_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    if (evt->scenario_id != MMI_SCENARIO_ID_REMINDER_AZAAN)
    {
       return MMI_RET_OK;
}

    if (azaan_index >= NUM_OF_AZAAN)
    {
        return MMI_RET_OK;
    }

#ifdef __MMI_ALM_ALERT_TYPE__
    if (g_azaan_alm_cntx_struct.AzaanAlmList[azaan_index].AlertType == ALM_ALERT_VIBRATION)
    {
        return MMI_RET_OK;
    }
#endif
	if (mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_REMINDER_AZAAN,
										  mmi_azaan_nmgr_expiry_callback,
										  NULL))
	{
        if ((mmi_frm_get_active_scenario_id() == MMI_SCENARIO_ID_USB_WEBCAM) || IS_IN_CALL())
    	{
            /* Play a notification ring tone if in web camera screen */
            srv_prof_play_tone(AZAAN_TONE_IN_CALL,NULL);
    	}
        return MMI_RET_OK;
}

    mmi_azaan_play_azaan_tone();
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_ind_proc
 * DESCRIPTION
 *  Group event process function for azaan indication
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_azaan_ind_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        mmi_frm_group_close(GRP_ID_AZAAN_IND);
        break;
        
    default:
        break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_nmgr_expiry_callback
 * DESCRIPTION
 *  Display indication screen and play alarm tone when alarm expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_azaan_nmgr_expiry_callback(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_alm_frm_cntx.CurrAlmIndex == 0xFF)
	{
		return MMI_TRUE;
	}
    //g_mmi_alm_self_close = MMI_TRUE;
	//mmi_frm_group_close(GRP_ID_ALM_IND);

	mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AZAAN_IND, mmi_azaan_ind_proc, NULL);
   	mmi_frm_group_enter(GRP_ID_AZAAN_IND, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_azaan_indication_screen();
    
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_play_vib
 * DESCRIPTION
 *  Display indication screen and play alarm tone when alarm expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_azaan_play_vib(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_custom_evt_struct *evt = (mmi_nmgr_custom_evt_struct*)param;
	U8 alert_type;
    U8 alarm_index = g_azaan_alm_cntx_struct.active_alm_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	RETURN_VAL_IF_FAIL(alarm_index < NUM_OF_AZAAN, MMI_RET_OK);
	
    if (evt->scenario_id != MMI_SCENARIO_ID_REMINDER_AZAAN)
    {
		return MMI_RET_OK;
}

	if (mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_REMINDER_AZAAN,
										  mmi_azaan_nmgr_expiry_callback,
										  NULL))
	{
        return MMI_RET_OK;
	}

	alert_type = g_azaan_alm_cntx_struct.AzaanAlmList[alarm_index].AlertType;
	

#if defined (__MMI_ALM_ALERT_TYPE__)
    switch (alert_type)
    {
        case MMI_AZAAN_ALERT_VIBRATION_AND_RING:
        case MMI_AZAAN_ALERT_VIBRATION:
            srv_vibrator_on();
            gui_touch_feedback_disable_vibrate();
            g_azaan_alm_cntx_struct.is_vibing = MMI_TRUE;
            break;

        default:
            break;
    }
#elif defined(__MMI_PROFILE_ALERT_TYPE_DOMINANT__)
	MMI_ALM_TRACE1(MMI_ALM_EVT_VIB_HDLR, 3);
    if (srv_prof_if_can_ring)
    {
        srv_vibrator_on();
        gui_touch_feedback_disable_vibrate();
        g_azaan_alm_cntx_struct.is_vibing = MMI_TRUE;
    } 
#endif /* __MMI_PROFILE_ALERT_TYPE_DOMINANT__ */

    return MMI_RET_OK;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_stop_vibrate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_azaan_stop_vibrate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__MMI_ALM_ALERT_TYPE__) || defined (__MMI_PROFILE_ALERT_TYPE_DOMINANT__)
	 U8 alert_type;
#endif 
	 U8 alarm_index = g_azaan_alm_cntx_struct.active_alm_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (g_azaan_alm_cntx_struct.is_vibing)
    {
#if defined (__MMI_ALM_ALERT_TYPE__)

		alert_type = g_azaan_alm_cntx_struct.AzaanAlmList[alarm_index].AlertType;

		switch (alert_type)
        {
            case ALM_ALERT_VIBRATION_AND_RING:
            case ALM_ALERT_VIBRATION:
                srv_vibrator_off();
                gui_touch_feedback_enable_vibrate();
                break;

            default:
                break;
        }
#elif defined(__MMI_PROFILE_ALERT_TYPE_DOMINANT__)
        srv_vibrator_off();
#endif

        g_azaan_alm_cntx_struct.is_vibing = MMI_FALSE; 
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_stop_azaan_tone
 * DESCRIPTION
 *  Stops Azaan Alarm Tone that is playing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_stop_azaan_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

#if defined (__MMI_ALM_ALERT_TYPE__) || defined (__MMI_PROFILE_ALERT_TYPE_DOMINANT__)
     U8 alert_type;
#endif 
     U8 alarm_index = g_azaan_alm_cntx_struct.active_alm_idx;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

     RETURN_IF_FAIL(alarm_index < NUM_OF_AZAAN);

     if (g_azaan_alm_cntx_struct.is_tone_playing)
     {
#if defined (__MMI_ALM_ALERT_TYPE__)

         alert_type = g_azaan_alm_cntx_struct.AzaanAlmList[alarm_index].AlertType;

         switch (alert_type)
         {
             case ALM_ALERT_VIBRATION_AND_RING:
             case ALM_ALERT_RING:
		    	srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
                 break;
             default:
                 break;
}
#else /* __MMI_ALM_ALERT_TYPE__ */
             srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
#endif
         g_azaan_alm_cntx_struct.is_tone_playing = MMI_FALSE;

         mdi_audio_resume_background_play();
     }

     mmi_azaan_stop_vibrate();
	 
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_exit_indication_screen
 * DESCRIPTION
 *  Exit function of azaan alarm indication screen.
 *  If exits screen because of interrupts, add screen to history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_exit_indication_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_azaan_stop_azaan_tone();

    mdi_audio_resume_background_play();

    mmi_frm_end_scenario(MMI_SCENARIO_ID_REMINDER_AZAAN);

    //if (g_azaan_alm_cntx_struct.is_save_to_history) /* add screen to history */
    //{
    //    GenericExitScreen(SCR_ID_AZAAN_ALM_INDICATION, mmi_azaan_indication_screen);
    //}

	//g_azaan_alm_cntx_struct.active_alm_idx = NUM_OF_AZAAN;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_go_back_main_menu
 * DESCRIPTION
 *  Display indication screen and play azaan alarm tone when alarm expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_go_back_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_AZAAN_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_azaan_handle_end_key
 * DESCRIPTION
 *  End key handler of azaan alarm indication screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_azaan_handle_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_azaan_stop_azaan_tone();
//    EntryAlmPwronScreen();
    //AlmSendPowerOn();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_exit_azaan_ind_screen
 * DESCRIPTION
 *  Exit azaan alarm indication screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_exit_azaan_ind_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_AZAAN_ALM_INDICATION)
    {
            GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_AZAAN_ALM_INDICATION);
    }
}

#endif /* __MMI_AZAAN_ALARM__ */
