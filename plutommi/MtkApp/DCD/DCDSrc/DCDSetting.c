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
*  DCDSetting.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   DCD setting
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
*******************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OP01_DCD__
#include "MenuCUIGprot.h"
#include "inlinecuigprot.h"
#include "mmi_rp_app_dcd_def.h"
#include "DCDGProt.h"
#include "DCDProt.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "kal_general_types.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "plx_dcd_wrapper.h"
#include "sdktypedef.h"
#include "dcdagentdefine.h"
#include "dcdagentinterface.h"
#include "gui_data_types.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "string.h"
#include "mmi_frm_scenario_gprot.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_util.h"
#include "Unicodexdcl.h"
#include "gui_inputs.h"
#include "app_mem.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalConstants.h"
#include "app_buff_alloc.h"
#include "stdio.h"
/* for flymode app/srv split */
#include "ModeSwitchSrvGProt.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define     MMI_DCD_SWITCH_ITEM_ON      0
#define     MMI_DCD_SWITCH_ITEM_OFF     1
#define     MMI_DCD_UPDATE_LOG_BUF_SEZE 1024

/* dcd setting item(summary)*/
typedef enum
{
#ifdef  CFG_DCD_IDLE_DISPLAY_SWITCH
	DCD_IDLE_DISPLAY_SWITCH,
#endif
	DCD_IDLE_SCROLL_SPEED,
	DCD_READ_STORY_DISPLAY,
	DCD_DISPLAY_SETTING_COUNT
} mmi_dcd_setting_item_enum;

typedef struct
{
    S32      count;
    S32      highlight_item;
    U16      caption_str_id;
    S8 **    str_list;
} mmi_dcd_setting_item_struct;



/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static S8 *g_help_text_p = NULL;
static S8 *g_log_buf_p;
static U8 is_dcd_setting_init = 0;
static mmi_dcd_setting_data_struct	g_dcd_setting_data;
static mmi_dcd_setting_item_struct  g_dcd_setting_items[] = 
{
    {DCD_SCRL_SPEED_TOTAL,             0, STR_ID_DCD_SCROLL_SPEED,       NULL},
    {DCD_IDLE_READ_STORY_DISPLAY_TOTAL,0, STR_ID_DCD_READ_STORY_DISPLAY, NULL }
};

/* Inline CUI */
static cui_inline_item_caption_struct  dcd_caption_scroll_speed =
{
    STR_ID_DCD_SCROLL_SPEED
};

static cui_inline_item_caption_struct  dcd_caption_read_display =
{
    STR_ID_DCD_READ_STORY_DISPLAY
};

static U16 dcd_select_str_scroll_speed[] = 
{
    STR_GLOBAL_MEDIUM,
    STR_GLOBAL_SLOW,
    STR_GLOBAL_FAST
};    

static cui_inline_item_select_struct  dcd_select_scroll_speed = 
{
    3,
    0,
    dcd_select_str_scroll_speed
};

static U16 dcd_select_str_read_display[] = 
{
    STR_GLOBAL_ON,
    STR_GLOBAL_OFF
};    

static cui_inline_item_select_struct  dcd_select_read_display = 
{
    2,
    0,
    dcd_select_str_read_display
};

static cui_inline_item_softkey_struct  dcd_inline_sofkey = 
{ 
    {
	    {STR_GLOBAL_OK,     IMG_GLOBAL_OK}, 
	    {STR_GLOBAL_BACK,   IMG_GLOBAL_BACK},
	    {0,                 IMG_GLOBAL_COMMON_CSK} 
    }
};

static cui_inline_set_item_struct  dcd_inline_items[] = 
{
    {DCD_APP_INLINE_CAPTION_SCROLL_SPEED,   CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L1, &dcd_caption_scroll_speed},
    {DCD_APP_INLINE_SELECT_SCROLL_SPEED,    CUI_INLINE_ITEM_TYPE_SELECT,    0,             &dcd_select_scroll_speed},
    {DCD_APP_INLINE_CAPTION_READ_DISPLAY,   CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L2, &dcd_caption_read_display},
    {DCD_APP_INLINE_SELECT_READ_DISPLAY,    CUI_INLINE_ITEM_TYPE_SELECT,    0,             &dcd_select_read_display},
};

static cui_inline_struct  dcd_inline_screen = 
{
    4,
    STR_ID_DCD_IDLE_DISPLAY, 
    IMG_ID_DCD_SUB_ICON,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    &dcd_inline_sofkey,
    dcd_inline_items
};

//static void mmi_dcd_settings_fill_inline_struct(void);
//static void mmi_dcd_settings_read_inline_struct(void);
//static void mmi_dcd_settings_set_data_struct(void);
//static void mmi_dcd_idle_display_settings_highlight_hdlr(S32 index);
static void mmi_dcd_settings_save_done(MMI_BOOL success);
static void mmi_dcd_enter_help_info_page(void);
static void mmi_dcd_help_info_callback(S32 selected_idx);
static void mmi_dcd_switch_off_done(void);
static void mmi_dcd_exit_help_info(void);
static void mmi_dcd_entry_switch_off_prompt_ext(void);

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
mmi_dcd_setting_data_struct *g_mmi_dcd_setting_cntx_p = &g_dcd_setting_data;

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_settings_init
 * DESCRIPTION
 *  Initialize the browser application whenever user enters into the wap menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_settings_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_DCD_SETTING_DATA_LID, 1, &g_dcd_setting_data, NVRAM_EF_DCD_SETTING_DATA_SIZE, &error);
    if (error != NVRAM_READ_SUCCESS);
    g_dcd_setting_data.dcd_flymode = !srv_mode_switch_is_network_service_available();
	is_dcd_setting_init = 1;

    // dcd_custom_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_switch
 * DESCRIPTION
 *  switch on or off in phone setup
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_switch(BOOL on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8  is_dcd_on;
    MMI_BOOL   dcd_switch;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (is_dcd_setting_init == 0)
	{
		g_dcd_setting_data.dcd_switch = on;
		return;
	}

    dcd_switch = mmi_dcd_is_switch_on();
	MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SWITCH_TO_SYNC, g_dcd_setting_data.dcd_switch, on);
    
    g_dcd_setting_data.dcd_switch = on; /* enable switch from PhoneSetup*/

    is_dcd_on = g_dcd_setting_data.dcd_switch && (!g_dcd_setting_data.dcd_flymode);
    if (dcd_switch != is_dcd_on) 
    {
        if (is_dcd_on)
        {
            mmi_dcd_show_reset();
            mmi_dcd_set_normal_entry(MMI_TRUE);
            mmi_dcd_set_normal_exit(MMI_FALSE);
        }
        mmi_dcd_switch_to_sync(is_dcd_on);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_flymode_switch_hdlr
 * DESCRIPTION
 *  fly mode switch hdlr
 * PARAMETERS
 *          
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_flymode_switch_finish_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    MMI_BOOL on, dcd_switch;
    kal_uint8  is_dcd_on;
    srv_mode_switch_notify_struct *switch_evt = (srv_mode_switch_notify_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (switch_evt->gsm_select_mode == SRV_MODE_SWITCH_FLIGHT_MODE)
    {
        on = MMI_TRUE;
    }
    else
    {
        on = MMI_FALSE;
    }
    
    if (is_dcd_setting_init == 0)
    {
        g_dcd_setting_data.dcd_flymode = on;
    }
    else
    {
        if (g_dcd_setting_data.dcd_flymode != on)
        {
            dcd_switch = mmi_dcd_is_switch_on();
            g_dcd_setting_data.dcd_flymode = on;    
            is_dcd_on = g_dcd_setting_data.dcd_switch && (!g_dcd_setting_data.dcd_flymode);
            if (dcd_switch != is_dcd_on) 
            {
                if (is_dcd_on)
                {
                    mmi_dcd_show_reset();
                    mmi_dcd_set_normal_entry(MMI_TRUE);
                    mmi_dcd_set_normal_exit(MMI_FALSE);
                }
                mmi_dcd_switch_to_sync(is_dcd_on); 
            }
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_settings_screen
 * DESCRIPTION
 *  Entry function for dcd settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_idle_display_settings_screen(void)
{
    MMI_ID  cui_id;
    S32     select_index;

    cui_id = cui_inline_create(g_dcd_grp_id, &dcd_inline_screen);
    if (cui_id != GRP_ID_INVALID)
    {
	    if (g_dcd_setting_data.dcd_scroll_speed >= DCD_SCRL_SPEED_TOTAL)
	    {
            select_index = 0;
	    }
	    else 
	    {
		    select_index = g_dcd_setting_data.dcd_scroll_speed;
	    }
        cui_inline_set_value(cui_id, DCD_APP_INLINE_SELECT_SCROLL_SPEED, (void *)select_index);

	    /* read story display */
	    if (g_dcd_setting_data.dcd_read_item_display >= DCD_IDLE_READ_STORY_DISPLAY_TOTAL)
        {
            select_index = 0;
	    }
	    else 
	    {
		    select_index = g_dcd_setting_data.dcd_read_item_display;
        }
        cui_inline_set_value(cui_id, DCD_APP_INLINE_SELECT_READ_DISPLAY, (void *)select_index);

	    cui_inline_run(cui_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_write_setting_value
 * DESCRIPTION
 *  write setting value to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: success / MMI_FALSE: error
 *****************************************************************************/
MMI_BOOL mmi_dcd_write_setting_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	WriteRecord(NVRAM_EF_DCD_SETTING_DATA_LID, 1, &g_dcd_setting_data, NVRAM_EF_DCD_SETTING_DATA_SIZE, &error);
	if ( error == NVRAM_WRITE_SUCCESS )
    {
        return MMI_TRUE;
    }

	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_scroll_speed
 * DESCRIPTION
 *  set scroll speed to DCD engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_set_scroll_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	BRINT  speed; /* milliseconds */
    EDCD_AGENT_RESULT   result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (g_dcd_setting_data.dcd_scroll_speed)
	{
	    case DCD_SCRL_SPEED_FAST:
		    speed = 200;
		    break;
		
	    case DCD_SCRL_SPEED_NORMAL:
		    speed = 400;
		    break;

	    case DCD_SCRL_SPEED_SLOW:
		    speed = 800;
		    break;

	    default:
		    speed = 400;
		    break;
	}
	/* g_dcd_setting_data.dcd_scroll_speed need to mapping */
	result = emDCDAgent_SetConfigScrollSpeed(g_dcd_agent.agent_handle, speed);
    if (result != eDCD_SUCCESS)
    {   
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_read_item_display
 * DESCRIPTION
 *  set read item display on IDLE
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_set_read_item_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	BRBOOL              hide; 
    EDCD_AGENT_RESULT   result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_dcd_setting_data.dcd_read_item_display == DCD_IDLE_READ_STORY_DISPLAY_ON)
	{
        hide = 0;
    }
    else
    {
        hide = 1;
    }

    result = emDCDAgent_SetConfigHideReadEntryMode(g_dcd_agent.agent_handle, hide);

    if (result != eDCD_SUCCESS)
    {   
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_settings_save_done
 * DESCRIPTION
 *  Function to Fill valuses in inine edit screen
 * PARAMETERS
 *  success     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_settings_save_done(MMI_BOOL success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( success )
    {
        string = (UI_string_type)GetString(STR_GLOBAL_DONE);
        mmi_popup_display((WCHAR*)string, MMI_EVENT_SUCCESS, NULL);
    }
    else 
    {
        string = (UI_string_type)GetString(STR_GLOBAL_ERROR);
        mmi_popup_display((WCHAR*)string, MMI_EVENT_FAILURE, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_idle_display_settings_save
 * DESCRIPTION
 *  Function to Fill valuses in inine edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_idle_display_settings_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL success;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	success = mmi_dcd_write_setting_value();
    mmi_dcd_settings_save_done(success);
 
	mmi_dcd_set_scroll_speed();
    mmi_dcd_set_read_item_display();
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
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_settings_reset
 * DESCRIPTION
 * PARAMETERS  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_settings_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  success;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear update log */
    memset(g_dcd_update_log_p, 0, sizeof(mmi_dcd_update_log_struct));
    /* default value responding to the value defined in nvram_common_config.c */
    g_mmi_dcd_setting_cntx_p->dcd_conn_mode         = 1;
    g_mmi_dcd_setting_cntx_p->dcd_scroll_speed      = 0;
    g_mmi_dcd_setting_cntx_p->dcd_read_item_display = 0;
    g_mmi_dcd_setting_cntx_p->dcd_idle_display      = 0;
    g_mmi_dcd_setting_cntx_p->dcd_restore           = 0xFF;
    g_mmi_dcd_setting_cntx_p->dcd_switch            = 0x01;
    
    mmi_dcd_reset_to_sync();
    success = mmi_dcd_write_setting_value();
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);

    if (g_dcd_manual_update_p->scr_id == SCR_ID_DCD_STORY_LIST)
    {
        mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_STORY_LIST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_setting_reset_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_setting_reset_confirm_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {        
        mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
        
        switch (alert->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_dcd_settings_reset();
                break;

            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_settings_reset_confirm
 * DESCRIPTION
 * PARAMETERS  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_settings_reset_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str[32];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str, (S8*) get_string(STR_ID_DCD_RESTORE_FACTORY));
    mmi_ucs2cat(str, (S8*) get_string(STR_ID_DCD_QUESTION_MARK));

    do {
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_dcd_setting_reset_confirm_callback;
    mmi_confirm_display((WCHAR *)str, MMI_EVENT_QUERY, &arg);
    } while(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_help_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_help_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *guiBuffer;
    S8  *str_buf;
    S32 text_size = 0, ucs2_text_len = 0;
    S8  *find_text_p = NULL;
    static HILITE_STR hilite_item[1];

    /*-----------------------------------------------------------  -----*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_HELP, mmi_dcd_exit_help_info, mmi_dcd_entry_help_info, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    text_size = mmi_ucs2strlen(GetString(STR_ID_DCD_HELP_INFO1));
    text_size += mmi_ucs2strlen(GetString(STR_ID_DCD_HELP_INFO2));
    text_size += mmi_ucs2strlen(GetString(STR_ID_DCD_HELP_INFO3));
    text_size += mmi_ucs2strlen(GetString(STR_ID_DCD_HELP_INFO4));
    text_size += mmi_ucs2strlen(GetString(STR_ID_DCD_HELP_INFO5));
    text_size += mmi_ucs2strlen(GetString(STR_ID_DCD_HELP_INFO6));
    text_size += mmi_ucs2strlen(GetString(STR_ID_DCD_HELP_INFO7));
    ucs2_text_len = (text_size + 1)* 2;
    
    g_help_text_p = (S8 *) applib_mem_screen_alloc(ucs2_text_len);
    
    mmi_ucs2cpy(g_help_text_p, (S8 *)GetString(STR_ID_DCD_HELP_INFO1));
    mmi_ucs2cat(g_help_text_p, (S8 *)GetString(STR_ID_DCD_HELP_INFO2));
    mmi_ucs2cat(g_help_text_p, (S8 *)GetString(STR_ID_DCD_HELP_INFO3));
    mmi_ucs2cat(g_help_text_p, (S8 *)GetString(STR_ID_DCD_HELP_INFO4));
    mmi_ucs2cat(g_help_text_p, (S8 *)GetString(STR_ID_DCD_HELP_INFO5));
    mmi_ucs2cat(g_help_text_p, (S8 *)GetString(STR_ID_DCD_HELP_INFO6));
    mmi_ucs2cat(g_help_text_p, (S8 *)GetString(STR_ID_DCD_HELP_INFO7));

    str_buf = GetString(STR_ID_DCD_MORE);
    find_text_p =  g_help_text_p + ucs2_text_len - (mmi_ucs2strlen(str_buf) + 1) * 2;

    hilite_item[0].str_addr = (S8*) find_text_p;
    hilite_item[0].length = mmi_ucs2strlen(str_buf);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory228Screen(
        STR_GLOBAL_HELP,
        IMG_ID_DCD_SUB_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) g_help_text_p,
        text_size,
        hilite_item,
        1,
        mmi_dcd_help_info_callback,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_dcd_enter_help_info_page, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dcd_enter_help_info_page, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_exit_help_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_exit_help_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_help_text_p)
    {
        applib_mem_screen_free(g_help_text_p);
    }
    g_help_text_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_help_info_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_help_info_callback(S32 selected_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(selected_idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_enter_help_info_page
 * DESCRIPTION
 *  dcd launch wap browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_enter_help_info_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_set_url_type(MMI_DCD_URL_HELP);
    mmi_dcd_launch_wap_browser();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_setting_conn_mode_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_setting_conn_mode_save(U8 conn_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  success;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONN_TO_SYNC, conn_mode, g_dcd_setting_data.dcd_conn_mode);

	if (g_dcd_setting_data.dcd_conn_mode != conn_mode)
	{
        g_dcd_setting_data.dcd_conn_mode = conn_mode;
	    success = mmi_dcd_write_setting_value();
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);

		mmi_dcd_conn_to_sync(g_dcd_setting_data.dcd_conn_mode);
	}
    else
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_setting_switch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_setting_conn_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid = cui_menu_create(
                        g_dcd_grp_id,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_APPMAIN,
                        MENU_ID_DCD_CONN_MODE,
                        MMI_TRUE,
                        NULL);

    if (menu_gid != GRP_ID_INVALID)
    {
        if (g_mmi_dcd_setting_cntx_p->dcd_conn_mode == 0)
        {
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_DCD_CONN_MODE_ALWAYS);
        }
        else if (g_mmi_dcd_setting_cntx_p->dcd_conn_mode == 1)
        {
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_DCD_CONN_MODE_HOME_ONLY);
        }
        else if (g_mmi_dcd_setting_cntx_p->dcd_conn_mode == 2)
        {
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_DCD_CONN_MODE_MANUAL);
        }
        cui_menu_set_default_title_image(menu_gid, get_image(IMG_ID_DCD_SUB_ICON));
        cui_menu_run(menu_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_exit_setting_update_log
 * DESCRIPTION
 * PARAMETERS   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_exit_setting_update_log(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_log_buf_p)
    {
        free_ctrl_buffer(g_log_buf_p);        
        g_log_buf_p = NULL;            
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_setting_update_log
 * DESCRIPTION
 *  Display update log.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_setting_update_log(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    S8 dt_buf_asc[48];
    S8 dt_buf_ucs2[96];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_UPDATE_LOG, mmi_dcd_exit_setting_update_log, mmi_dcd_entry_setting_update_log, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    g_log_buf_p = NULL;
    g_log_buf_p = (S8*)get_ctrl_buffer(MMI_DCD_UPDATE_LOG_BUF_SEZE);

    if (g_dcd_update_log_p->last_year != 0)
    {
        /* last sync time */
        mmi_ucs2cpy(g_log_buf_p, (S8 *)GetString(STR_ID_DCD_LAST_SYNC_TIME));
        mmi_ucs2cat(g_log_buf_p, (S8 *)L"\n");

        sprintf(dt_buf_asc, "%04d-%02d-%02d %02d:%02d:%02d", 
                g_dcd_update_log_p->last_year,
                g_dcd_update_log_p->last_month,
                g_dcd_update_log_p->last_day,
                g_dcd_update_log_p->last_hour,
                g_dcd_update_log_p->last_minute,
                g_dcd_update_log_p->last_second);
        mmi_asc_to_ucs2((S8 *)dt_buf_ucs2, (S8*)dt_buf_asc);

        mmi_ucs2cat(g_log_buf_p, (S8 *)dt_buf_ucs2);
        mmi_ucs2cat(g_log_buf_p, (S8 *)L"\n");

        /* last sync result */
        mmi_ucs2cat(g_log_buf_p, (S8 *)GetString(STR_ID_DCD_LAST_SYNC_RESULT));
        mmi_ucs2cat(g_log_buf_p, (S8 *)L"\n");

        if (g_dcd_update_log_p->sync_result == 1) /* success */
        {
            mmi_ucs2cat(g_log_buf_p, (S8 *)GetString(STR_ID_DCD_SYNC_SUCCESS));
            mmi_ucs2cat(g_log_buf_p, (S8 *)L"\n");
        } 
        else if (g_dcd_update_log_p->sync_result == 2) /* syncing */
        {
            mmi_ucs2cat(g_log_buf_p, (S8 *)GetString(STR_ID_DCD_SYNCING));
            mmi_ucs2cat(g_log_buf_p, (S8 *)L"\n");
        }
        else if (g_dcd_update_log_p->sync_result == 3) /* canceled */
        {
            mmi_ucs2cat(g_log_buf_p, (S8 *)GetString(STR_ID_DCD_CANCELLED));
            mmi_ucs2cat(g_log_buf_p, (S8 *)L"\n");
        }
        else
        {
            U16  fail_cause_str;
            S32  err_code;
            mmi_ucs2cat(g_log_buf_p, (S8 *)GetString(STR_ID_DCD_SYNC_FAILURE));
            mmi_ucs2cat(g_log_buf_p, (S8 *)L"\n");

            /* fail cause */
            err_code = mmi_dcd_get_sync_err_code();
            if (err_code != -1) /* -1 means that sync is canceled. */
            {
                mmi_ucs2cat(g_log_buf_p, (S8 *)GetString(STR_ID_DCD_FAIL_CAUSE));
                mmi_ucs2cat(g_log_buf_p, (S8 *)L"\n");
                fail_cause_str = STR_ID_DCD_SYNC_ERRCODE_701 + (U16)err_code;
                mmi_ucs2cat(g_log_buf_p, (S8 *)GetString(fail_cause_str));
			    mmi_ucs2cat(g_log_buf_p, (S8 *)L"\n");
            }
        }

        /* next sync time */
        if (g_dcd_update_log_p->next_year != 0)
        {
            mmi_ucs2cat(g_log_buf_p, (S8 *)GetString(STR_ID_DCD_NEXT_SYNC_TIME));
            mmi_ucs2cat(g_log_buf_p, (S8 *)L"\n");

            sprintf(dt_buf_asc, "%04d-%02d-%02d %02d:%02d:%02d", 
                    g_dcd_update_log_p->next_year,
                    g_dcd_update_log_p->next_month,
                    g_dcd_update_log_p->next_day,
                    g_dcd_update_log_p->next_hour,
                    g_dcd_update_log_p->next_minute,
                    g_dcd_update_log_p->next_second);
            mmi_asc_to_ucs2((S8 *)dt_buf_ucs2, (S8 *)dt_buf_asc);

            mmi_ucs2cat(g_log_buf_p, (S8 *)dt_buf_ucs2);
        }
    }
    else /* no sync log */
    {
        mmi_ucs2cpy(g_log_buf_p, (S8 *)GetString(STR_ID_DCD_NO_UPDATE_LOG));
    }

    ShowCategory74Screen(
        STR_ID_DCD_UPDATE_LOG,
        IMG_ID_DCD_SUB_ICON,
        0, 0,
        STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
        (U8*)g_log_buf_p,
        512,
        gui_buffer);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_switch_off_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_switch_off_confirm_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {        
        mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
        
        switch (alert->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_dcd_entry_switch_off_prompt_ext();
                break;

            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_switch_off_prompt
 * DESCRIPTION
 *  mmi_dcd_entry_switch_off_prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_switch_off_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_dcd_switch_off_confirm_callback;
    mmi_confirm_display((WCHAR *)get_string(STR_ID_DCD_SWITCH_OFF_ASK), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_switch_off_prompt_ext
 * DESCRIPTION
 *  mmi_dcd_entry_switch_off_prompt_ext
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_switch_off_prompt_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_SETTING_SWITCH_OFF_PROMPT, NULL, mmi_dcd_entry_switch_off_prompt_ext, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory21Screen(
        STR_GLOBAL_SETTINGS,
        IMG_ID_DCD_SUB_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        STR_ID_DCD_PURCHASE_EXIST,
        gui_buffer);
   
    SetLeftSoftkeyFunction(mmi_dcd_switch_off_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dcd_switch_off_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_switch_off_done
 * DESCRIPTION
 *  mmi_dcd_switch_off_done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_switch_off_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_setting_data.dcd_switch = 0;
    mmi_dcd_write_setting_value();
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);

    if ((g_dcd_grp_id != 0) && mmi_frm_group_is_present(g_dcd_grp_id))
    {
        mmi_frm_group_close(g_dcd_grp_id);
    }

    mmi_dcd_switch(MMI_FALSE);
}


#endif /* __MMI_OP01_DCD__ */

