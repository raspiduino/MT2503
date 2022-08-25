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
 * VRSICityQuery.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for query city time of VRSI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_VRSICITYQUERY_C
#define _MMI_VRSICITYQUERY_C
#include "MMI_features.h"
#if defined(__MMI_VRSI__)

/*  Include: MMI header file */

/* ... Add More MMI header */
#include "med_main.h"
#include "med_api.h"
#include "mdi_audio.h"
#include "VRSIType.h"
#include "VRSIProt.h"
#include "MainMenuDef.h"

/* World Clock Header */
#include "WorldClock.h"
#include "PhoneSetupGprots.h"
#include "PhoneSetup.h"
#include "Worldclockcuigprot.h"
#include "mmi_rp_srv_vrsi_def.h"



#include "MMIDataType.h"
#include "CustDataRes.h"
#include "stack_config.h"
#include "Unicodexdcl.h"
#include "custom_mmi_default_value.h"
#include "DateTimeType.h"
#include "app_datetime.h"
#include "string.h"
#include "stdio.h"
#include "GlobalResDef.h"
#include "MMI_features.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "menucuigprot.h"
#include "CommonScreensResDef.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "GlobalConstants.h"
#include "mmi_rp_app_worldclock_def.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "wgui_categories_list.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_util.h"

/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

/* 
 * Define
 */
#define MMI_VRSI_MAX_CITY_NUM 100

/* 
 * Local Variable
 */
#if (defined(__MMI_WORLD_CLOCK__) || defined(__MMI_VRE_WORLD_CLOCK__)) || defined(__MMI_VRSI_TRAIN_TAG__)
static U16 g_vrsi_city_index;
static U16 g_vrsi_city_count;
#endif
/* 
 * Local Function
 */

/* 
 * Global Variable
 */

/* 
 * Global Function
 */

#define MMI_VRSI_CITY_CENTRAL

extern mmi_ret mmi_vrsi_settings_event_proc(mmi_event_struct *evt);
/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_city_central_add_all
 * DESCRIPTION
 *  This function is add all city name as central command.
 * PARAMETERS
 *  msg     [IN]        Message from protocol event call back.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_city_central_add_all(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 long_list[MMI_VRSI_MAX_ADD_ENTRY];
    U16 *name_list[MMI_VRSI_MAX_ADD_ENTRY];
    U16 i, tag_num, add_count;
    U8 is_name_list[MMI_VRSI_MAX_ADD_ENTRY];
    U16 id_list[MMI_VRSI_MAX_ADD_ENTRY];
    U16 CityNum = NUMBER_OF_CITY - 1;   /* The first item is "none" */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Abort while adding central command. Will close engine in abort function, so return directly. */
    if (g_vrsi_cntx.vrsi_state != MMI_VRSI_STATE_ADDING_CMD)
    {
        return;
    }
    add_count = g_vrsi_cntx.central_count;

    if (add_count < CityNum)
    {
        tag_num = ((CityNum - add_count) < MMI_VRSI_MAX_ADD_ENTRY) ? (CityNum - add_count) : MMI_VRSI_MAX_ADD_ENTRY;

        for (i = 0; i < tag_num; i++)
        {
            name_list[i] = (U16*) GetString(TimeZoneData[i + add_count + 1].CityName); /* The first item is "none", add from second item */
            long_list[i] = i + add_count + MMI_VRSI_CMD_CITY_BASE;
            is_name_list[i] = FALSE;
        }

        /* Get session id for each add operation */
        g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

        /* Add SI tags */
        media_aud_vrsi_add_tags(
            MOD_MMI,
            g_vrsi_cntx.session_id,
            (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
            tag_num,
            name_list,
            long_list,
            is_name_list,
            id_list);

        add_count += tag_num;

        /* Print add fail messages. */
        mmi_vrsi_init_central_count_fail(tag_num, id_list, long_list);
    }

    g_vrsi_cntx.central_count = add_count;

    /* More central command to add */
    if (add_count < CityNum)
    {
        mmi_vrsi_init_central_add_req();
    }
    else
    {
        mmi_vrsi_init_central_done();
    }
}

#define MMI_VRSI_CITY_RCG


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_city_rcg_grammar1_result
 * DESCRIPTION
 *  This function idetify city index from recognition result.
 * PARAMETERS
 *  tag_num         [IN]        Tag number of recognition result
 *  long_list       [IN]        Id list of recognition result.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_city_rcg_grammar1_result(U16 tag_num, S32 *long_list)
{
#if defined(__MMI_WORLD_CLOCK__) || defined(__MMI_VRE_WORLD_CLOCK__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 CityNum = NUMBER_OF_CITY - 1;   /* The first item is "none" */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((long_list[0] >= MMI_VRSI_CMD_CITY_BASE) && (long_list[0] < MMI_VRSI_CMD_CITY_BASE + CityNum))
    {
        g_vrsi_city_index = (U16) long_list[0] - MMI_VRSI_CMD_CITY_BASE;

        /* Entry world clock screen. */
       // WcSetCityIndex(g_vrsi_city_index + 1);
        mmi_vrsi_entry_city_browse();

        /* Prompt time by TTS */
        mmi_vrsi_rcg_init(NULL);
        mmi_vrsi_city_time_prompt();
    }
    else
#endif /* defined(__MMI_WORLD_CLOCK__) */ 
    {
        mmi_vrsi_rcg_init(NULL);
        mmi_vrsi_city_not_exist_prompt();
    }
}

#if defined(__MMI_WORLD_CLOCK__) || defined(__MMI_VRE_WORLD_CLOCK__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_city_time_prompt
 * DESCRIPTION
 *  This function read out the city name using SD tag if exists. If not use TTS to read.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_city_time_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /* Check if there are SD tag. */
#if defined(__MMI_VRSI_TRAIN_TAG__)
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_vrsi_util_play_tag(
                MMI_VRSI_GRAMMAR_1,
                MMI_VRSI_APP_CITY,
                (U16) (g_vrsi_city_index + MMI_VRSI_CMD_CITY_BASE),
                mmi_vrsi_city_time_prompt1);
    if (result == MED_RES_OK)
    {
        return;
    }
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

    /* If not, play TTS */
    mmi_ucs2cpy(str_prompt, GetString(TimeZoneData[g_vrsi_city_index + 1].CityName));
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_city_time_prompt1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_city_time_prompt1
 * DESCRIPTION
 *  This function read out the time of the city.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_city_time_prompt1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];
    S8 str_temp1[6], str_temp2[12];

    MYTIME currTime, incTime;
    U8 HomeCity;
    FLOAT TimeDiff;
    S32 temp;
    U8 TimeFlag = 0;

#ifdef __MMI_WORLDCLOCK_DST__
    MYTIME dstTime;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&currTime);

    /* Get time zone difference */
    HomeCity = PhnsetGetHomeCity() + 1;
   // TimeDiff = WcTimeZoneDiff(g_vrsi_city_index + 1, HomeCity);
    TimeDiff = GetTimeZone(g_vrsi_city_index + 1) - GetTimeZone(HomeCity);
    memset(&incTime, 0, sizeof(MYTIME));

    if (TimeDiff < 0)
    {
        TimeDiff = TimeDiff * (-1);
        TimeFlag = 1;
    }

    temp = (S32) (TimeDiff * 60);

    incTime.nDay = (U8) (TimeDiff / 24);
    incTime.nHour = ((S32) TimeDiff) % 24;
    incTime.nMin = temp % 60;

    if (TimeFlag)   /* decrement */
    {
        DecrementTime(currTime, incTime, &currTime);
    }
    else
    {
        IncrementTime(currTime, incTime, &currTime);
    }

#ifdef __MMI_WORLDCLOCK_DST__
    if (HomeCity != g_wc_cntx.CurrCityIndex)    /* not home city */
    {
        memset(&dstTime, 0, sizeof(MYTIME));
        dstTime.nHour = 1;
        if (g_wc_cntx.DSTForeign && g_phnset_cntx_p->currentDST)        /* both date light saving is on */
        {
            /* do nothing */
        }
        else if (g_phnset_cntx_p->currentDST)   /* only home city turns on DST */
        {
            DecrementTime(currTime, dstTime, &currTime);
        }
        else if (g_wc_cntx.DSTForeign)  /* only foreign city turns on DST */
        {
            IncrementTime(currTime, dstTime, &currTime);
        }
    }
#endif /* __MMI_WORLDCLOCK_DST__ */ 

    /* Prepare TTS prompt string */
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_CITY_TIME));

    if (!PhnsetGetTimeFormat())  /* current time format is 12 hours*/
    {
        if (currTime.nHour == 0)
        {
            currTime.nHour = 12;
            mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_CITY_TIME_AM));
        }
        else if (currTime.nHour < 12)
        {
            mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_CITY_TIME_AM));
        }
        else if (currTime.nHour == 12)
        {
            mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_CITY_TIME_PM));
        }
        else
        {
            currTime.nHour -= 12;
            mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_CITY_TIME_PM));
        }
    }

    sprintf(str_temp1, "%02d ", currTime.nHour);
    mmi_asc_to_ucs2(str_temp2, str_temp1);
    mmi_ucs2cat(str_prompt, str_temp2);
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_CITY_TIME_HOUR));

    sprintf(str_temp1, "%02d ", currTime.nMin);
    mmi_asc_to_ucs2(str_temp2, str_temp1);
    mmi_ucs2cat(str_prompt, str_temp2);
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_CITY_TIME_MINUTE));

    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_close);

}


MMI_ID mmi_vrsi_city_query_proc(mmi_event_struct *param)
{
    cui_worldclock_event_struct *wc_evt = (cui_worldclock_event_struct *)param;
    U8 ret = 0;

    switch(wc_evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            if(g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
            {
                mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);                        
                mmi_vrsi_rcg_close();
            }
            break;
            
        case CUI_WC_SELECT_EVENT_OK:
           #ifdef __MMI_WC_TZ_SUPPORT__
            ret = mmi_wc_entry_from_phnset();
           #endif
            if (ret == 1)
            {
                PhnsetSetHomeCity();
            }
      #ifdef __MMI_DUAL_CLOCK__
            else if (ret == 2)
            {
                PhnsetSetForeignCity();
            }
      #endif /* __MMI_DUAL_CLOCK__ */
            break;

        case CUI_WC_SELECT_EVENT_CANCEL:
        case CUI_WC_SELECT_EVENT_CLOSE_REQ:   
            if(g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
            {
                mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);                        
                mmi_vrsi_rcg_close();
            }
            cui_worldclock_close(wc_evt->sender_id);
            mmi_frm_group_close(GRP_ID_VRSI_SET_CITY);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_city_browse
 * DESCRIPTION
 *  Entry function to the wolrd clock map. Will assign exit function for VRSI here.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_city_browse(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID sub_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 //   EntryWcBrowseCityEx(mmi_vrsi_entry_city_browse, mmi_vrsi_exit_city_browse);
    if (mmi_frm_group_is_present(GRP_ID_VRSI_SET_CITY))
	{
		mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_NOT_AVAILABLE, GRP_ID_VRSI, 0);
		return;
	}	
   /* 
    cui_worldclock_set_current_city(g_vrsi_city_index + 1);
    cui_worldclock_launch();	
   */
   
    mmi_frm_group_create(GRP_ID_VRSI, GRP_ID_VRSI_SET_CITY, mmi_vrsi_city_query_proc, NULL);
    mmi_frm_group_enter(GRP_ID_VRSI_SET_CITY, MMI_FRM_NODE_SMART_CLOSE_FLAG);    
    sub_id = cui_worldclock_create(GRP_ID_VRSI_SET_CITY);
    mmi_vrsi_rcg_init(NULL);
    cui_worldclock_set_current_city(g_vrsi_city_index + 1);
    cui_worldclock_run(sub_id);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_city_browse
 * DESCRIPTION
 *  Exit function of world clock map. Will close VRSI engine before leave.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_city_browse(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
   // ExitWcBrowseCity();
}
#endif /* defined(__MMI_WORLD_CLOCK__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_city_not_exist_prompt
 * DESCRIPTION
 *  This function prompt no city exist.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_city_not_exist_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_RCG_NOT_FOUND));
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_CITY_ITEM));
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_SPEAK_AGAIN_PROMPT));

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}

#define MMI_VRSI_CITY_TRAINING
#if defined(__MMI_VRSI_TRAIN_TAG__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_city_list_highlight_hdlr
 * DESCRIPTION
 *  highlight function for city list.
 * PARAMETERS
 *  index       [IN]        Highlight position.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_city_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_city_index = (U16) index;
}

mmi_ret mmi_vrsi_citylist_proc(mmi_event_struct *evt)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    /*************************Menu CUI event***************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_vrsi_city_pre_entry_train_main();
            break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            break;
            
    /**********************Alert CUI event*************************/
        case EVT_ID_ALERT_QUIT:
            break;        
        
        default:
            break;
    }
    return MMI_RET_OK;
}


#ifdef __MMI_FTE_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_kuro_list_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vrsi_cityquery_list_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag_loc;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return;
    }
    mmi_frm_group_create(GRP_ID_VRSI, GRP_ID_VRSI_TRAIN_OPTION_MAIN, mmi_vrsi_settings_event_proc, (void*)NULL); 

    mmi_frm_group_enter(GRP_ID_VRSI_TRAIN_OPTION_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    g_vrsi_cntx.long_name_ptr = (U16*) GetString(TimeZoneData[g_vrsi_city_index + 1].CityName);
    g_vrsi_cntx.long_list[0] = MMI_VRSI_CMD_CITY_BASE + g_vrsi_city_index;
    g_vrsi_cntx.long_list_num = 1;

    g_vrsi_cntx.curr_app = MMI_VRSI_APP_CITY;

    tag_loc = mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_CITY, g_vrsi_cntx.long_list[0], NULL);
    if(tag_loc < 0xff)
    {
        mmi_vrsi_train_option_delete_confirm();
    }
    else
    {
        mmi_vrsi_train_option_pre_add();
    }
    
    return;
}
#endif


static pBOOL mmi_vrsi_city_get_list_item(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);
    string_id = TimeZoneData[item_idx + 1].CityName;
    mmi_ucs2ncpy((S8*) str_buff, (S8*) GetString(string_id), MAX_SUBMENU_CHARACTERS);
    if (mmi_vrsi_train_util_get_loc_in_list(MMI_VRSI_APP_CITY, (U16)(MMI_VRSI_CMD_CITY_BASE + item_idx), tag_list) !=
       0xff)
    {
        *img_buff_p = (PU8) GetImage(IMG_ID_VRSI_APP);
    }
    else
    {
        *img_buff_p =(PU8) GetImage(ORGANIZER_MENU_WORLDCLOCK_IMAGEID);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_city_list
 * DESCRIPTION
 *  Entry function of city list for SD trainging.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_city_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 CityList[MMI_VRSI_MAX_CITY_NUM];
    U16 ImageList[MMI_VRSI_MAX_CITY_NUM];
    U16 i, CityNum;
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NUMBER_OF_CITY <= MMI_VRSI_MAX_CITY_NUM);

    CityNum = NUMBER_OF_CITY - 1;


    mmi_frm_group_create(GRP_ID_VRSI_TRAIN_TAG_MAIN, GRP_ID_VRSI_TRAIN_CITY_LIST, mmi_vrsi_citylist_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_VRSI_TRAIN_CITY_LIST, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI_TRAIN_CITY_LIST, 
       SCR_ID_VRSI_TRAIN_CITY_LIST, 
       NULL, 
       mmi_vrsi_entry_city_list, 
       MMI_FRM_UNKNOW_SCRN);


    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_VRSI_TRAIN_CITY_LIST, SCR_ID_VRSI_TRAIN_CITY_LIST);
    /* Assign city string and image */
    if (guiBuffer == NULL)
    {
        g_vrsi_city_index = 0;
    }

    if (!LIST_MENU)
    {
        ShowCategory353Screen(
              (U8*)GetString(STR_ID_VRSI_CITY_LIST),
              GetRootTitleIcon(MENU_ID_VRSI_SETTING),
              NULL,
              NULL,
              STR_GLOBAL_BACK,
              IMG_GLOBAL_BACK,
              0,
              NULL,
              NULL,
              NULL,
              1,
              0,
              NULL);
          
       ClearKeyEvents();
    }
    else
    {
          RegisterHighlightHandler(mmi_vrsi_city_list_highlight_hdlr);
          EnableCenterSoftkey( 0, IMG_GLOBAL_OPTION_CSK);
          ShowCategory183Screen(
              get_string(STR_ID_VRSI_CITY_LIST),
              get_image(GetRootTitleIcon(MENU_ID_VRSI_SETTING)),
              get_string(STR_GLOBAL_OPTIONS),
              get_image(IMG_GLOBAL_OPTIONS),
              get_string(STR_GLOBAL_BACK),
              get_image(IMG_GLOBAL_BACK),
              CityNum,
              mmi_vrsi_city_get_list_item, 
              NULL,
              NULL,
              MMI_FALSE,
              NULL,
              guiBuffer);  
           ClearKeyEvents();

#ifdef __MMI_FTE_SUPPORT__ 
    wgui_register_tap_callback(mmi_vrsi_cityquery_list_tap_callback);
#endif
    }
    SetLeftSoftkeyFunction(mmi_vrsi_city_pre_entry_train_main, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_vrsi_city_pre_entry_train_main, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_city_pre_entry_train_main
 * DESCRIPTION
 *  Pre entry function of train SD tag option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_city_pre_entry_train_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag_loc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.long_name_ptr = (U16*) GetString(TimeZoneData[g_vrsi_city_index + 1].CityName);
    g_vrsi_cntx.long_list[0] = MMI_VRSI_CMD_CITY_BASE + g_vrsi_city_index;
    g_vrsi_cntx.long_list_num = 1;

    g_vrsi_cntx.curr_app = MMI_VRSI_APP_CITY;

    tag_loc = mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_CITY, g_vrsi_cntx.long_list[0], NULL);

    /* Modify, Playback, or delete exists voice tag. */
    if (tag_loc < 0xff)
    {
        mmi_vrsi_entry_train_option_del();
    }
    /* No tag exists, add new tag */
    else
    {
        mmi_vrsi_entry_train_option_add();
    }

}

#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ /* #if defined(__MMI_VRSI_TRAIN_TAG__) */

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_VRSICITYQUERY_C */ /* #ifndef _MMI_VRSICITYQUERY_C */

