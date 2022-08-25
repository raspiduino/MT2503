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
 *  PhoneBookRes.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for phonebook main function.
 *  Including initialize procedure, main menu, common utilities, etc.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_PHB_CALLER_RES__
#include "MMI_include.h"
#include "FileMgrSrvGProt.h"

#include "PhoneBookGprot.h"
#include "PhoneBookProt.h"
#include "PhoneBookResDef.h"
#include "PhoneBookCore.h"
#include "PhbSrvGprot.h"
#include "PhoneBookEditor.h"
#include "PhoneBookTypes.h"
#include "PhbCuiGprot.h"
#include "MenuCuiGprot.h"
#include "drm_gprot.h"

#include "CommonScreens.h"

#include "Conversions.h"

#include "GeneralDeviceGprot.h"

#if defined(__MMI_PHB_CALLER_VIDEO__)
#include "VdoPlyGProt.h"
#include "VdoPlyResDef.h"		/* Video Player String ID Enum */
#include "Mdi_datatype.h"
#include "Mdi_include.h"
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */ 
#if 0
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 
#endif

#include "UCMGprot.h"
#include "UcmSrvGprot.h"

#include "FileMgrCuiGprot.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "med_api.h"
#if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
#include "CameraCuiGprot.h"
#endif

#ifdef __MMI_PHB_UI_IN_TABS__
#include "toneselectorcuigprot.h"
#endif

#include "ProfilesSrvGprot.h"
#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_app_profiles_def.h"
#include "mdi_audio.h"

#if defined(__MMI_FILE_MANAGER__)
#include "FilemgrGprot.h"
#endif

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "custom_srv_prof_defs.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "mmi_frm_events_gprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mmi_rp_app_phonebook_def.h"
#include "fs_type.h"
#include "drm_def.h"
#include "fs_errcode.h"
#include "AlertScreen.h"
#include "GlobalResDef.h"
#include "gui_data_types.h"
#include "mmi_rp_file_type_def.h"
#include "string.h"
#include "FileMgrType.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_multimedia.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "DebugInitDef_Int.h"
#include "gdi_include.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "gdi_const.h"
#include "lcd_sw_rnd.h"
#include "stack_config.h"
#include "gdi_datatype.h"
#include "fs_func.h"
#include "gui.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_categories.h"
#include "MMI_features.h"
#include "custom_phb_config.h"
#include "wgui_categories_list.h"
#include "ps_public_enum.h"
#include "CustMenuRes.h"
/* auto add by kw_check end */

#include "USBSrvGprot.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif
#if defined(__MMI_IMAGE_CLIP_CUI__) && defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
#include "ImageClipCuiGprot.h"
#endif

#include "ToneSelectorCui.h"

#define MMI_PHB_IMAGE_MAX_SIZE      (20*1024)
#define MMI_PHB_IMAGE_MAX_WIDTH     160
#define MMI_PHB_IMAGE_MAX_HEIGHT    120


/*----------------------------------------------------------------*/
/* Local Variables                                                */
/*----------------------------------------------------------------*/
static U16 g_phb_last_ring_tone_id = 0;
static U16 g_phb_curr_ring_tone_id = 0;


/*----------------------------------------------------------------*/
/* Global Variables                                               */
/*----------------------------------------------------------------*/
#if 0
#if defined(__MMI_PHB_CALLER_VIDEO__)
#if defined(__MMI_SWFLASH__)
/* under construction !*/
#endif
#endif
#endif


/**
  * For contact resource setting
  */
mmi_phb_resource_struct g_mmi_phb_resource;
mmi_phb_caller_res_struct *g_mmi_phb_res_p;


static void mmi_phb_image_delete_from_phb_folder(void);
static U8 mmi_phb_get_image_index(U16);
static U16 mmi_phb_get_image_id(U8 index);
static void mmi_phb_choose_caller_pic_hilite_handler(S32 index);
static void mmi_phb_entry_image_delete(MMI_ID group_id);
static void mmi_phb_entry_image_delete_default_pic(void);
static MMI_BOOL mmi_phb_res_check_valid(U16 res_id, U16 *path);




#define MMI_PHB_RESOURCE_SETTING_RING
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_play_ring_tone_id
 * DESCRIPTION
 *  Plays the selected ringtone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_play_ring_tone_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* g_phb_last_ring_tone_id = g_phb_curr_ring_tone_id; */
    StopTimer(PHB_NOTIFYDURATION_TIMER);
    /* Play ring tone repeatedly */
    srv_prof_play_tone_with_id(
        SRV_PROF_TONE_PHONEBOOK,
        g_phb_curr_ring_tone_id,
        SRV_PROF_RING_TYPE_REPEAT,
        NULL);
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 550);
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, g_phb_curr_ring_tone_id);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_stop_ring_tone_id
 * DESCRIPTION
 *  Stops the currently played ringtone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_stop_ring_tone_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_last_ring_tone_id)
    {
        StopTimer(PHB_NOTIFYDURATION_TIMER);
        srv_prof_stop_tone(SRV_PROF_TONE_PHONEBOOK);
    }
    g_phb_last_ring_tone_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_build_ring_tone_list
 * DESCRIPTION
 *  Builds the ringtone list for inline selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_build_ring_tone_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, j;
    U8 ringToneTotalId, midiToneTotalId;
    U8 extMelodyCnt = 0;        /* For feature file manager associate. */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Default Factory Tones. */

    ringToneTotalId = AUD_ID_PROF_TONE_END - AUD_ID_PROF_TONE_BEGIN - 1;
    midiToneTotalId = AUD_ID_PROF_RING_END - AUD_ID_PROF_RING_BEGIN - 1;

    /* External Melody, select from file manager. */
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) && defined(__SRV_PHB_CALLER_RES_DATA_STORE__)
    extMelodyCnt = 1;
#endif

    g_mmi_phb_resource.total_ring_tone = 1 + ringToneTotalId
        + midiToneTotalId
        + extMelodyCnt;

    g_mmi_phb_resource.ring_tone_name_list[0] = (PU8) GetString(STR_GLOBAL_DEFAULT);
    g_mmi_phb_resource.ring_tone_list[0] = 0;
    mmi_ucs2cpy((CHAR*) subMenuData[0], GetString(STR_GLOBAL_DEFAULT));

    /* Default Factory Tones. */
    for (j = 0; j < ringToneTotalId; ++j)
    {
        //kal_wsprintf((WCHAR*)subMenuData[++i],"%w", GetString(STR_ID_SRV_PROF_TONE_1 + j));
        ++i;
        g_mmi_phb_resource.ring_tone_list[i] = j + AUD_ID_PROF_TONE_BEGIN + 1;
        g_mmi_phb_resource.ring_tone_name_list[i] = (PU8) GetString((U16) (STR_ID_SRV_PROF_TONE_1 + j));
    }

    for (j = 0; j < midiToneTotalId; ++j)
    {
        //kal_wsprintf((WCHAR*)subMenuData[++i],"%w", GetString(STR_ID_SRV_PROF_RING_1 + j));
        ++i;
        g_mmi_phb_resource.ring_tone_list[i] = j + AUD_ID_PROF_RING_BEGIN + 1;
        g_mmi_phb_resource.ring_tone_name_list[i] = (PU8) GetString((U16) (STR_ID_SRV_PROF_RING_1 + j));
    }

#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) && defined(__SRV_PHB_CALLER_RES_DATA_STORE__)
    g_mmi_phb_resource.ring_tone_list[++i] = MMI_RP_SRV_PROF_AUD_MAX;
    g_mmi_phb_resource.ring_tone_name_list[i] = (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECT_FILE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ring_tone_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for ringtones inline selection list
 * PARAMETERS
 *  ringToneIndex       [IN]        Ring tone id for play
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ring_tone_highlight_hdlr(S32 ringToneIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_stop_ring_tone_id();

    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 540);
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, ringToneIndex);

    if (ringToneIndex)
    {
        g_phb_curr_ring_tone_id = g_mmi_phb_resource.ring_tone_list[ringToneIndex];
        g_phb_last_ring_tone_id = g_phb_curr_ring_tone_id;

        if ((srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED) &&
            (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0))
        {
        #ifdef __MMI_SILENT_MEETING_PROFILE__
            if (srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED)
            {
                MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 541);
                g_phb_last_ring_tone_id = 0;
            }
            else
        #endif
            {
                MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 542);
                StartTimer(PHB_NOTIFYDURATION_TIMER, 1000, mmi_phb_play_ring_tone_id);
            }
        }
        else    
        {
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 543);
            g_phb_last_ring_tone_id = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_ring_tone_index
 * DESCRIPTION
 *  Gets the index of the current ringtone in ringtone list
 * PARAMETERS
 *  ring_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_phb_get_ring_tone_index(U16 ring_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_phb_resource.total_ring_tone; ++i)
    {
        if (g_mmi_phb_resource.ring_tone_list[i] == ring_id)
        {
            return i;
        }
    }
    return 0;
}


#ifdef __MMI_PHB_UI_IN_TABS__
mmi_ret mmi_phb_profiles_contact_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tone_selector_evt_struct * evt_cui = (cui_tone_selector_evt_struct *)evt;
    mmi_ret result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_TONE_SELECTOR_CLOSE_REQUEST:
            cui_tone_selector_close(evt_cui->sender_id);
            break;

        case EVT_ID_CUI_TONE_SELECTOR_RESULT:
        {
            if (evt_cui->is_default_sound)
            {
                g_mmi_phb_res_p->ring_id = evt_cui->selected_tone;
                g_mmi_phb_res_p->selected_ring_index = mmi_phb_get_ring_tone_index(evt_cui->selected_tone);
                g_mmi_phb_res_p->done = 1;
                *g_mmi_phb_res_p->ring_path = 0;
            }
            else
            {
                S32 ret;                
                srv_fmgr_fileinfo_struct file_info;

                ret = cui_tone_selector_get_selected_filepath(evt_cui->sender_id, 
                                                              &file_info, 
                                                              (WCHAR *)g_mmi_phb_res_p->ring_path, 
                                                              SRV_FMGR_PATH_BUFFER_SIZE);
                if (ret < 0)
                {
                    /* Do something*/
                }        
                else
                {
                    g_mmi_phb_resource.ring_tone_name_list[g_mmi_phb_resource.total_ring_tone - 1] =
                        (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
                    g_mmi_phb_res_p->ring_location = MMI_PHB_IMAGE_SELECT_PATH;
                    g_mmi_phb_res_p->selected_ring_index = g_mmi_phb_resource.total_ring_tone - 1;
					g_mmi_phb_res_p->ring_id = MMI_RP_SRV_PROF_AUD_MAX;
					g_mmi_phb_res_p->done = 1;
                }                
            } 
            break;
        }

        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}


void mmi_phb_entry_choose_caller_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id profile_gid;
    U16 highlight_tone_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((profile_gid = cui_tone_selector_create(g_mmi_phb_res_p->sg_id)) != GRP_ID_INVALID)
    {
    
        U16 filter = 0;
        
        CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_RING);
		
	#if defined(__SRV_PHB_CALLER_RES_DATA_STORE__) && defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) && defined(__MMI_PROFILES_EXT_FILE_SUPPORT__)
        CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_EXT_FILE);
        /* */
		if(g_mmi_phb_res_p->selected_ring_index == 0)
		{
			highlight_tone_id = CUI_TONESEL_RING_ID_BEGIN;
		}
        else if(g_mmi_phb_res_p->selected_ring_index != g_mmi_phb_resource.total_ring_tone- 1)
        {
		    highlight_tone_id = g_mmi_phb_resource.ring_tone_list[g_mmi_phb_res_p->selected_ring_index];
        }

	/*
		else
	     {
	        highlight_tone_id = CUI_TONESEL_RING_ID_BEGIN;
		}
	*/
    #else

		if(g_mmi_phb_res_p->selected_ring_index == 0)
		{
			highlight_tone_id = CUI_TONESEL_RING_ID_BEGIN;
		}
        else if(g_mmi_phb_res_p->selected_ring_index != g_mmi_phb_resource.total_ring_tone)
        {
		    highlight_tone_id = g_mmi_phb_resource.ring_tone_list[g_mmi_phb_res_p->selected_ring_index];
        }
	#endif	
		cui_tone_selector_set_filter(profile_gid, filter);
	
		//cui_tone_selector_set_filter(profile_gid, CUI_TONE_SELECTOR_FILTER_RING|CUI_TONE_SELECTOR_FILTER_EXT_FILE);
        cui_tone_selector_set_title_id(profile_gid, STR_ID_PHB_CALLER_RING, GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID));


        cui_tone_selector_set_highlight_tone(profile_gid, 
                highlight_tone_id);
        cui_tone_selector_run(profile_gid);
    }
    else
    {
        return;
    }
}
#endif


#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_option_ringtone_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of inline editor image field. Used when file manager exists.
 * PARAMETERS
 *  index       [IN]        Current inline selection index.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_edit_option_ringtone_highlight_hdlr(mmi_id menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) && defined(__SRV_PHB_CALLER_RES_DATA_STORE__)
    if (g_mmi_phb_res_p->selected_ring_index == (g_mmi_phb_resource.total_ring_tone - 1))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_RINGTONE_OPTION_SELECT, MMI_FALSE);
    }
    else
	#endif	
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_RINGTONE_OPTION_SELECT, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ringtone_check_data_space
 * DESCRIPTION
 *  Check free space in data record before save to phonebook.
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_ringtone_check_data_space(CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    BOOL drm_ret = TRUE;
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path != NULL)
    {
        fh = DRM_open_file((kal_wchar *)path, FS_READ_ONLY, DRM_PERMISSION_PLAY);

        if (fh >= FS_NO_ERROR)
        {
        #ifdef __DRM_SUPPORT__
            drm_ret = DRM_validate_forward_rule(fh, DRM_PERMISSION_PLAY);
        #endif /* __DRM_SUPPORT__ */
            DRM_close_file(fh);
            if (drm_ret == FALSE)
            {        
                mmi_phb_popup_display_ext(
                    STR_GLOBAL_DRM_PROHIBITED,
                    MMI_EVENT_FAILURE);
                return FALSE;
            }
        }
        else
        {
            mmi_phb_popup_display_ext(
                srv_fmgr_fs_error_get_string(fh),
                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(fh));

            return FALSE;
        }
    }

    result = srv_phb_datamgr_res_check_data_space(MMI_PHB_CONTACT_FIELD_RING);

    if (result != 0)
    {
        if (result < 0)
        {
            mmi_phb_popup_display_ext(
                srv_fmgr_fs_error_get_string(result),
                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result));
        }
        else
        {
            mmi_phb_popup_display_ext(
                STR_GLOBAL_NOT_ENOUGH_MEMORY,
                MMI_EVENT_FAILURE);
        }
        return FALSE;
    }
    
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_select_from_file_mamager
 * DESCRIPTION
 *  select image from file manager. enter file manager screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ringtone_select_from_file_mamager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_usb_app_unavailable_popup(0))
    {
        return;
    }

    FMGR_FILTER_INIT(&filter);

    FMGR_FILTER_SET_AUDIO(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);
#ifdef __DRM_V02__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF); 
#endif

    g_mmi_phb_res_p->child_id = cui_file_selector_create(
                                    g_mmi_phb_res_p->sg_id,
                                    (WCHAR*) L"root",
                                    &filter,
                                    CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                                    CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON | CUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON);

    if (g_mmi_phb_res_p->child_id > 0)
    {
        cui_file_selector_set_title(g_mmi_phb_res_p->child_id, 0, IMG_SCR_PBOOK_CAPTION);

        g_mmi_phb_res_p->curr_res_type = MMI_PHB_RES_RING;
        
        cui_file_selector_set_userdata(g_mmi_phb_res_p->child_id, (U32) g_mmi_phb_res_p);
        
        cui_file_selector_run(g_mmi_phb_res_p->child_id);
    }
    else
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            g_mmi_phb_res_p->sg_id,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ringtone_select_path_from_file_mamager
 * DESCRIPTION
 *  select a ringtone from file manager
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ringtone_select_path_from_file_manager(mmi_phb_caller_res_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //get selected path
    cui_file_selector_get_selected_filepath(
        res->child_id,
        NULL,
        (WCHAR *) res->ring_temp_path,
        (SRV_FMGR_PATH_MAX_LEN+1) * ENCODING_LENGTH);
    
    //Check ringtone content
    if (mmi_phb_ringtone_check_data_space((CHAR*)res->ring_temp_path))
    {
        mmi_wcscpy(res->ring_path, res->ring_temp_path);
    
        res->ring_location = MMI_PHB_IMAGE_SELECT_PATH;
        res->selected_ring_index = g_mmi_phb_resource.total_ring_tone - 1;
        g_mmi_phb_resource.ring_tone_name_list[g_mmi_phb_resource.total_ring_tone - 1] =
            (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
    
        mmi_popup_display_simple_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS,
            g_mmi_phb_res_p->sg_id,
            NULL);
    
        res->done = 1;
    
        cui_file_selector_close(res->child_id);
    }
}

#endif /* __MMI_PHB_UI_IN_TABS__ */


#define MMI_PHB_RESOURCE_SETTING_IMG
#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
mmi_ret mmi_phb_image_edit_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_ret result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            result = MMI_RET_DONT_CARE;
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_IMAGE_OPTION_VIEW)
            {
                mmi_phb_entry_image_view_ext(g_mmi_phb_save_contact_p->sg_id);
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_IMAGE_OPTION_SELECT)
            {
                mmi_phb_entry_choose_caller_pic();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_IMAGE_OPTION_DELETE)
            {
                mmi_phb_entry_image_delete(g_mmi_phb_save_contact_p->sg_id);
                if (mmi_frm_group_is_present(menu_evt->sender_id))
                {
                    cui_menu_close(menu_evt->sender_id);
                }
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }
        
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        
        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}
#endif /* !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__))) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_image_option
 * DESCRIPTION
 *  Phonebook associate image operation: View, Change, Remove.
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_image_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    menu_gid = cui_menu_create_and_run(
                   g_mmi_phb_res_p->sg_id,
                   CUI_MENU_SRC_TYPE_RESOURCE,
                   CUI_MENU_TYPE_OPTION,
                   MENU_ID_PHB_IMAGE_OPTION,
                   MMI_FALSE, NULL);

    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);

    
}


#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_image_view_default_pic
 * DESCRIPTION
 *  view selected picture, only for default pic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_image_view_default_pic_ext(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_frm_scrn_enter(
            scrn_data->group_id,
            SCR_VIEW_PICTURE,
            NULL,
            (FunctionPtr)mmi_phb_entry_image_view_default_pic_ext,
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        ShowCategory132Screen(
            (PU8) GetString(STR_GLOBAL_VIEW),
            IMG_SCR_PBOOK_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_mmi_phb_resource.image_id_list[g_mmi_phb_res_p->selected_pic_index],
            gui_buffer);
    }
}
#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_image_view
 * DESCRIPTION
 *  view selected picture. contain default picture and selected from file
 *  need to build image list, and set select_pic_index first
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_image_view_ext(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    if (g_mmi_phb_res_p->selected_pic_index == g_mmi_phb_resource.total_image_id - 1
        )
    {
        if (mmi_phb_usb_app_unavailable_popup(0))
        {
            return;
        }
        mmi_frm_scrn_first_enter(
            group_id,
            SCR_VIEW_PICTURE,
            (FunctionPtr) mmi_phb_image_view_from_phb_folder,
            NULL);
    }
    else
#endif    
    {
        mmi_frm_scrn_first_enter(
            group_id,
            SCR_VIEW_PICTURE,
            (FunctionPtr) mmi_phb_entry_image_view_default_pic_ext,
            NULL);
    }
#endif
}


void mmi_phb_entry_image_view(void)
{
#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
    mmi_phb_entry_image_view_ext(g_mmi_phb_save_contact_p->sg_id);
#endif
}


#ifdef __MMI_PHB_UI_IN_TABS__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_choose_caller_pic_done
 * DESCRIPTION
 *  choose default picture done function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_choose_caller_pic_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_mmi_phb_res_p->selected_pic_index = g_mmi_phb_res_p->highlight_index;
    g_mmi_phb_res_p->done = 1;
    
    mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        g_mmi_phb_res_p->sg_id,
        NULL);

    mmi_frm_scrn_close(g_mmi_phb_res_p->sg_id, SCR_ID_PHB_IMAGE_VIEW_IMAGE);
    mmi_frm_scrn_close(g_mmi_phb_res_p->sg_id, SCR_VIEW_PICTURE);
    mmi_frm_scrn_close(g_mmi_phb_res_p->sg_id, SCR_ID_PHB_TAB_EDIT_CALLER_PIC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_default_image_preview
 * DESCRIPTION
 *  default image preview before save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_default_image_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            g_mmi_phb_res_p->sg_id,
            SCR_VIEW_PICTURE,
            NULL,
            mmi_phb_default_image_preview,
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory132Screen(
            (PU8) GetString(STR_GLOBAL_VIEW),
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_mmi_phb_resource.image_id_list[g_mmi_phb_res_p->highlight_index],
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_phb_choose_caller_pic_done, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_choose_caller_pic_done, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_choose_caller_pic_hilite_handler
 * DESCRIPTION
 *  UI Tab style : choose picture hilite handler
 * PARAMETERS
 *  index           [in]        picture index = item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_choose_caller_pic_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_res_p->highlight_index = index;
    switch (g_mmi_phb_resource.image_id_list[index])
    {
    #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)  
        case 0x8000:
            SetLeftSoftkeyFunction(mmi_phb_image_select_from_file_mamager, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_phb_image_select_from_file_mamager, KEY_EVENT_UP);
            break;

    #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
        case 0xA000:
            SetLeftSoftkeyFunction(mmi_phb_image_select_from_camera, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_phb_image_select_from_camera, KEY_EVENT_UP);
            break;
    #endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
    #endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */

        default:
            SetLeftSoftkeyFunction(mmi_phb_default_image_preview, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_phb_default_image_preview, KEY_EVENT_UP);
            break;
            
    }
}
#endif /* __MMI_PHB_UI_IN_TAB__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_choose_caller_pic
 * DESCRIPTION
 *  UI Tab style : entry choose pic screen , not UI Tab: go to file to select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_choose_caller_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_res_p->sg_id != GRP_ID_PHB_GROUP)
    {
    #if defined(__MMI_PHB_UI_IN_TABS__) && !(defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
    /* for vodafone , go to file manager directly */
	#if 0
    #if defined(__MMI_OP12_PHB__)
    #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
    #else /* __MMI_OP12_PHB__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_OP12_PHB__) */
	#else
        U8 *gui_buffer;
        U32 i;

        if (mmi_frm_scrn_enter(
                g_mmi_phb_res_p->sg_id,
                SCR_ID_PHB_TAB_EDIT_CALLER_PIC,
                NULL,
                (FunctionPtr)mmi_phb_entry_choose_caller_pic,
                MMI_FRM_FULL_SCRN))
        {
            gui_buffer = mmi_frm_scrn_get_active_gui_buf();

            for (i = 0; i < g_mmi_phb_resource.total_image_id; i++)
            {
                subMenuDataPtrs[i] = g_mmi_phb_resource.image_name_list[i];
            }
        #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
            subMenuDataPtrs[g_mmi_phb_resource.total_image_id - 1] = (U8*)GetString(STR_ID_PHB_FMGR_IMAGE_SELECT_FILE);
        #endif
            RegisterHighlightHandler(mmi_phb_choose_caller_pic_hilite_handler);

            /* 8 Display Category Screen */
            ShowCategory89Screen(
                STR_ID_PHB_CALLER_PIC,
                GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_mmi_phb_resource.total_image_id,
                subMenuDataPtrs,
                NULL,
                0,
                g_mmi_phb_res_p->selected_pic_index,
                gui_buffer);

            /* 9.Register function with right softkey */
        }
	#endif

    #else /* __MMI_PHB_UI_IN_TAB__ */
    
    #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
        if (g_mmi_phb_res_p->selected_pic_index == g_mmi_phb_resource.total_image_id - 1)
        {
            mmi_phb_image_select_from_file_mamager();
        }
        else
        {
            MMI_ASSERT(0);
        }
    #endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */
    #endif /* __MMI_PHB_UI_IN_TAB__ */
    }
    else
    {
    #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
        if (g_mmi_phb_res_p->selected_pic_index == g_mmi_phb_resource.total_image_id - 1)
        {
            mmi_phb_image_select_from_file_mamager();
        }
        else
        {
            MMI_ASSERT(0);
        }
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_image_delete_default_pic
 * DESCRIPTION
 *  remove image reference. just use for UI_IN_TABS style
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_image_delete_default_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_res_p->image_location = MMI_PHB_IMAGE_NO_SELECT;
    
    mmi_popup_display_simple_ext(
        STR_GLOBAL_REMOVED,
        MMI_EVENT_SUCCESS,
        g_mmi_phb_res_p->sg_id,
        NULL);
        
#ifdef __MMI_PHB_UI_IN_TABS__
    g_mmi_phb_res_p->selected_pic_index = 0;
    g_mmi_phb_res_p->done = 1;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_image_delete
 * DESCRIPTION
 *  remove image reference
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_image_delete(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    if (g_mmi_phb_resource.image_id_list[g_mmi_phb_res_p->selected_pic_index] == 1
        )
    {
        mmi_phb_image_delete_from_phb_folder();
    }
    else
#endif    
    {
        mmi_phb_entry_image_delete_default_pic();
    }
}


#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
static void mmi_phb_select_image_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID sg_id = mmi_frm_group_get_active_id();
    mmi_phb_select_image_struct *res;
    cui_phb_select_image_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = (mmi_phb_select_image_struct*) mmi_frm_scrn_get_user_data(sg_id, SCR_ID_PHB_IMAGE_VIEW_IMAGE);
    
    MMI_ASSERT(res != NULL);

    evt.evt_id = EVT_ID_PHB_SELECT_IMAGE;
    evt.sender_id = res->sg_id;
    evt.size = sizeof(cui_phb_select_image_struct);
    evt.result = MMI_TRUE;
    evt.path = res->path;
    
    mmi_frm_group_post_to_parent(res->sg_id, (mmi_group_event_struct*)&evt);
}

void mmi_phb_select_image_preview(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_select_image_struct *res = (mmi_phb_select_image_struct*) scrn_data->user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_frm_scrn_enter(
            scrn_data->group_id,
            SCR_ID_PHB_IMAGE_VIEW_IMAGE,
            NULL, 
            (FunctionPtr)mmi_phb_select_image_preview,
            MMI_FRM_FULL_SCRN))
    {
        wgui_cat222_disable_err_msg_display();

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory222Screen(
            STR_GLOBAL_VIEW,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            GDI_COLOR_BLACK,
            NULL,
            (CHAR *) res->path,
            FALSE,
            mmi_phb_image_preview_callback,
            GDI_IMAGE_SRC_FROM_FILE);
        
        SetLeftSoftkeyFunction(mmi_phb_select_image_done, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_select_image_done, KEY_EVENT_UP);
    }
}


void mmi_phb_select_image(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    MMI_ID sg_id;
    mmi_phb_select_image_struct *user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    user_data = (mmi_phb_select_image_struct *) mmi_frm_group_get_user_data(group_id);

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            MMI_STR_ID str_id;
            mmi_event_notify_enum popup_type;
            str_id = mmi_usb_get_error_info(0, &popup_type);

            mmi_popup_display_simple_ext(
                str_id,
                popup_type,
                group_id,
                NULL);
            
            return;
        }
    }
#endif

    if (user_data->type == CUI_PHB_SELECT_IMG_FROM_FILE)
    {
        FMGR_FILTER_INIT(&filter);
#if defined(__GDI_MEMORY_PROFILE_2__)   /* Able to select jpeg file if supported */
        FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
#endif 
        FMGR_FILTER_SET(&filter, FMGR_TYPE_GIF);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);    
        FMGR_FILTER_SET(&filter, FMGR_TYPE_WBMP);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_WBM);
#if defined(GDI_USING_PNG)
        FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);
#endif 
#if defined(GDI_USING_M3D)
        FMGR_FILTER_SET(&filter, FMGR_TYPE_M3D);
#endif
    /* .SVG file is now not supported due to stack overflow */
#ifdef SVG12_SUPPORT
        FMGR_FILTER_SET(&filter, FMGR_TYPE_SVG);
#endif
#if defined(__DRM_V02__)
        FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif /* defined(__DRM_V02__) */
        FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
        
        sg_id = cui_file_selector_create(
                    group_id,
                    (WCHAR*) L"root",
                    &filter,
                    CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                    CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON | CUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON | CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FOLDER);

        cui_file_selector_set_title(sg_id, 0, IMG_SCR_PBOOK_CAPTION);

        cui_file_selector_run(sg_id);
    }
    else if (user_data->type == CUI_PHB_SELECT_IMG_CAMERA)
    {
    #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)    
        sg_id = cui_camera_create(group_id);
    
        if (sg_id > 0)
        {
            cui_camera_run_struct camera_struct;
            cui_camera_struct_init(&camera_struct);
            cui_camera_run(sg_id, &camera_struct);
        }
        else
        {
            // error handler
        }
    #endif        
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_view_from_phb_folder
 * DESCRIPTION
 *  view image from selected file path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_view_from_phb_folder(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh = 0;
    BOOL drm_ret = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_mmi_phb_res_p->image_location == MMI_PHB_IMAGE_FOR_ENTRY)          /* An Image in Phonebook folder */
        || (g_mmi_phb_res_p->image_location == MMI_PHB_IMAGE_SELECT_PATH)     /* An Image in select path */
        || (g_mmi_phb_res_p->image_location == MMI_PHB_IMAGE_CALLER_GROUP)    /* An Image in Caller Group Folder */
        )       
    {
        fh = DRM_open_file((kal_wchar *)g_mmi_phb_res_p->img_path, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);

        if (fh >= FS_NO_ERROR)
        {
        #ifdef __DRM_SUPPORT__
            drm_ret = DRM_validate_forward_rule(fh, DRM_PERMISSION_DISPLAY);
        #endif
        
            DRM_close_file(fh);
            if (drm_ret == MMI_FALSE)
            {
                mmi_frm_scrn_close(scrn_data->group_id, scrn_data->scrn_id);
                mmi_popup_display_simple_ext(
                    STR_GLOBAL_DRM_PROHIBITED,
                    MMI_EVENT_FAILURE,
                    scrn_data->group_id,
                    NULL);
                return;
            }
        }
        else
        {
            mmi_frm_scrn_close(scrn_data->group_id, scrn_data->scrn_id);
            mmi_popup_display_simple_ext(
                srv_fmgr_fs_error_get_string(fh),
                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(fh),
                scrn_data->group_id,
                NULL);
            return;
        }
        
        if (mmi_frm_scrn_enter(
                scrn_data->group_id,
                scrn_data->scrn_id,
                NULL,
                (FunctionPtr)mmi_phb_image_view_from_phb_folder,
                MMI_FRM_FULL_SCRN))
        {
            ShowCategory222Screen(
                STR_GLOBAL_VIEW,
                IMG_SCR_PBOOK_CAPTION,
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                GDI_COLOR_BLACK,
                (CHAR*) NULL,
                (CHAR*) g_mmi_phb_res_p->img_path,
                FALSE,
                NULL,
                GDI_IMAGE_SRC_FROM_FILE);

            return;
        }
    }

    mmi_frm_scrn_close(scrn_data->group_id, scrn_data->scrn_id);
    mmi_popup_display_simple_ext(
        STR_ID_PHB_FMGR_IMAGE_NO_SELECT,
        MMI_EVENT_FAILURE,
        scrn_data->group_id,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_select_from_file_mamager
 * DESCRIPTION
 *  select image from file manager. enter file manager screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_select_from_file_mamager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_usb_app_unavailable_popup(0))
    {
        return;
    }

    FMGR_FILTER_INIT(&filter);
#if defined(__GDI_MEMORY_PROFILE_2__)   /* Able to select jpeg file if supported */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
#endif 
    FMGR_FILTER_SET(&filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);    
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WBMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WBM);
#if defined(GDI_USING_PNG)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);
#endif 
#if defined(GDI_USING_M3D)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_M3D);
#endif
/* .SVG file is now not supported due to stack overflow */
#ifdef SVG12_SUPPORT
    FMGR_FILTER_SET(&filter, FMGR_TYPE_SVG);
#endif
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif /* defined(__DRM_V02__) */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    g_mmi_phb_res_p->child_id = cui_file_selector_create(
                                    g_mmi_phb_res_p->sg_id,
                                    (WCHAR*) L"root",
                                    &filter,
                                    CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                                    CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON | CUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON | CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FOLDER);

    if (g_mmi_phb_res_p->child_id > 0)
    {
        cui_file_selector_set_title(g_mmi_phb_res_p->child_id, 0, IMG_SCR_PBOOK_CAPTION);

        g_mmi_phb_res_p->curr_res_type = MMI_PHB_RES_IMAGE;
        
        cui_file_selector_set_userdata(g_mmi_phb_res_p->child_id, (U32) g_mmi_phb_res_p);
        
        cui_file_selector_run(g_mmi_phb_res_p->child_id);
    }
    else
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            g_mmi_phb_res_p->sg_id,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_preview
 * DESCRIPTION
 *  phb image preview function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_image_preview(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_caller_res_struct *res = (mmi_phb_caller_res_struct*) scrn_data->user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(TRC_MMI_PHB_IMAGE_PREVIEW, res->sg_id, res->selected_pic_index);
    
    if (mmi_frm_scrn_enter(
            scrn_data->group_id,
            SCR_ID_PHB_IMAGE_VIEW_IMAGE,
            NULL, 
            (FunctionPtr)mmi_phb_image_preview,
            MMI_FRM_FULL_SCRN))
    {
        wgui_cat222_disable_err_msg_display();

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory222Screen(
            STR_GLOBAL_VIEW,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            GDI_COLOR_BLACK,
            NULL,
            (CHAR *) res->img_temp_path,
            FALSE,
            mmi_phb_image_preview_callback,
            GDI_IMAGE_SRC_FROM_FILE);
        
        SetLeftSoftkeyFunction(mmi_phb_image_select_from_file_mamager_done, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_image_select_from_file_mamager_done, KEY_EVENT_UP);
    }
}


#if defined(__MMI_IMAGE_CLIP_CUI__) && defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_clip_image
 * DESCRIPTION
 *  entry clip image cui
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_clip_image(mmi_phb_caller_res_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL file_supported;
	WCHAR *file_path;
	MMI_ID cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	file_path = (WCHAR*)(res->img_temp_path);

    file_supported = cui_image_clip_is_file_format_supported(file_path);
    if(file_supported)
    {
    	cui_gid = cui_image_clip_create(res->sg_id, file_path, NULL);
    	cui_image_clip_set_dest_size(cui_gid, INLINE_FTE_CAPTION_THUMBNAIL_WIDTH, INLINE_FTE_CAPTION_THUMBNAIL_HEIGHT);
    	cui_image_clip_run(cui_gid);
    }
    else
    {
        if (mmi_phb_image_check_valid_image((CHAR*)file_path, MMI_FALSE))
        {
            mmi_frm_scrn_first_enter(
               res->sg_id,
               SCR_ID_PHB_IMAGE_VIEW_IMAGE,
               (FunctionPtr) mmi_phb_image_preview,
               res);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_clip_image_finish
 * DESCRIPTION
 *  copy image file path after clipper finish
 * PARAMETERS
 *  file path of image clipper
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_clip_image_finish(WCHAR* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_wcscpy(g_mmi_phb_res_p->img_path, file_path);
	g_mmi_phb_res_p->image_location = MMI_PHB_IMAGE_SELECT_PATH;
    g_mmi_phb_res_p->selected_pic_index = g_mmi_phb_resource.total_image_id - 1;
    g_mmi_phb_resource.image_name_list[g_mmi_phb_resource.total_image_id - 1] =
        (U8*)GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);

	mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        g_mmi_phb_res_p->sg_id,
        NULL);

    g_mmi_phb_res_p->done = 1;
    cui_file_selector_close(g_mmi_phb_res_p->child_id);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_select_path_from_file_mamager
 * DESCRIPTION
 *  select a picture from file manager
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_select_path_from_file_mamager(mmi_phb_caller_res_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /**
     * get selected path
     */
    cui_file_selector_get_selected_filepath(
        res->child_id,
        NULL,
        (WCHAR *) res->img_temp_path,
        (SRV_FMGR_PATH_MAX_LEN+1) * ENCODING_LENGTH);
    
    /**
     * Check image content
     */
#if defined(__MMI_IMAGE_CLIP_CUI__) && defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
	mmi_phb_entry_clip_image(res);
#else
    if (mmi_phb_image_check_valid_image((CHAR*) res->img_temp_path, MMI_FALSE))
    {
        mmi_frm_scrn_first_enter(
            res->sg_id,
            SCR_ID_PHB_IMAGE_VIEW_IMAGE,
            (FunctionPtr) mmi_phb_image_preview,
            res);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_select_from_file_mamager_done
 * DESCRIPTION
 *  call back of select image from file manager.
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_select_from_file_mamager_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id = g_mmi_phb_res_p->sg_id;
    mmi_phb_caller_res_struct *res;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = (mmi_phb_caller_res_struct*) mmi_frm_scrn_get_user_data(sg_id, SCR_ID_PHB_IMAGE_VIEW_IMAGE);
    
    MMI_ASSERT(res != NULL);
    
    mmi_wcscpy(res->img_path, res->img_temp_path);
    
    res->image_location = MMI_PHB_IMAGE_SELECT_PATH;
    res->selected_pic_index = g_mmi_phb_resource.total_image_id - 1;
    g_mmi_phb_resource.image_name_list[g_mmi_phb_resource.total_image_id - 1] =
        (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);

    mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        sg_id,
        NULL);

    res->done = 1;

    cui_file_selector_close(res->child_id);
    
    mmi_frm_scrn_close(sg_id, SCR_ID_PHB_IMAGE_VIEW_IMAGE);
#ifdef __MMI_PHB_UI_IN_TABS__
    mmi_frm_scrn_close(sg_id, SCR_ID_PHB_TAB_EDIT_CALLER_PIC);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_delete_from_phb_folder
 * DESCRIPTION
 *  delete reference of selected image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_image_delete_from_phb_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_IMAGE_DELETE_FROM_FOLDER);
    
    if (g_mmi_phb_res_p->image_location == MMI_PHB_IMAGE_NO_SELECT)
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_FMGR_IMAGE_NO_SELECT,
            MMI_EVENT_FAILURE,
            g_mmi_phb_res_p->sg_id,
            NULL);
    }
    else
    {
        g_mmi_phb_res_p->image_location = MMI_PHB_IMAGE_NO_SELECT;
        g_mmi_phb_resource.image_name_list[g_mmi_phb_resource.total_image_id - 1] =
            (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECT_FILE);
        
        mmi_popup_display_simple_ext(
            STR_GLOBAL_REMOVED,
            MMI_EVENT_SUCCESS,
            g_mmi_phb_res_p->sg_id,
            NULL);
    }

    g_mmi_phb_res_p->done = 1;
    
#ifdef __MMI_PHB_UI_IN_TABS__
    /**
     * For tab style, should reset the pic index to default one
     */
    g_mmi_phb_res_p->selected_pic_index = 0;  
#endif   
}


#if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_avatar_image_select_from_file_manager
 * DESCRIPTION
 *  select image from file manager. enter file manager screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_select_from_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_usb_app_unavailable_popup(0))
    {
        return;
    }
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        mmi_phb_ucm_app_entry_error_message();    
        return;
    }

    g_mmi_phb_res_p->child_id = cui_camera_create(g_mmi_phb_res_p->sg_id);

    if (g_mmi_phb_res_p->child_id > 0)
    {
        cui_camera_run_struct camera_struct;
        cui_camera_struct_init(&camera_struct);
        cui_camera_run(g_mmi_phb_res_p->child_id, &camera_struct);
    }
    else
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            g_mmi_phb_res_p->sg_id,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_camera_cui_res_handle
 * DESCRIPTION
 *  select image from file manager. enter file manager screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_camera_cui_res_handle(WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_image_check_valid_image((CHAR*) path, MMI_TRUE))
    {
        mmi_wcscpy(g_mmi_phb_res_p->img_path, path);
        
        g_mmi_phb_res_p->image_location = MMI_PHB_IMAGE_SELECT_PATH;
        g_mmi_phb_res_p->selected_pic_index = g_mmi_phb_resource.total_image_id - 1;
        g_mmi_phb_resource.image_name_list[g_mmi_phb_resource.total_image_id - 1] =
            (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
        
        mmi_popup_display_simple_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS,
            g_mmi_phb_res_p->sg_id,
            NULL);

        g_mmi_phb_res_p->done = 1;

        mmi_frm_scrn_close(g_mmi_phb_res_p->sg_id, SCR_ID_PHB_TAB_EDIT_CALLER_PIC);
    }
}
#endif/* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */

#if defined(__MMI_FILE_MANAGER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_check_valid_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_phb_image_check_valid_image(CHAR *path, MMI_BOOL auto_resize)
{
#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    U16 image_type;
    CHAR *error_str_ptr;
    BOOL drm_ret = TRUE;
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check image file extension in advance. */
    fh = DRM_open_file((kal_wchar *)path, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);

    if (fh >= FS_NO_ERROR)
    {
    #ifdef __DRM_SUPPORT__
        drm_ret = DRM_validate_forward_rule(fh, DRM_PERMISSION_DISPLAY);
    #endif /* __DRM_SUPPORT__ */
        DRM_close_file(fh);
        if (drm_ret == FALSE)
        {
            mmi_phb_popup_display_ext(
                STR_GLOBAL_DRM_PROHIBITED,
                MMI_EVENT_FAILURE);
            return MMI_FALSE;
        }
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_ERROR,
            MMI_EVENT_FAILURE);
        return MMI_FALSE;
    }

    image_type = gdi_image_get_type_from_file((CHAR*) path);
    if ((image_type != GDI_IMAGE_TYPE_JPG_FILE) && (image_type != GDI_IMAGE_TYPE_GIF_FILE) &&
#if defined(GDI_USING_PNG)
        (image_type != GDI_IMAGE_TYPE_PNG_FILE) &&
#endif 
#if defined(GDI_USING_M3D)
        (image_type != GDI_IMAGE_TYPE_M3D_FILE) &&
#endif 
/* .SVG file is now not supported due to stack overflow */
#if defined(SVG12_SUPPORT)
        (image_type != GDI_IMAGE_TYPE_SVG_FILE) &&
#endif
        (image_type != GDI_IMAGE_TYPE_BMP_FILE) &&
        (image_type != GDI_IMAGE_TYPE_WBMP_FILE))
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_UNSUPPORTED_FORMAT,
            MMI_EVENT_FAILURE);
        return MMI_FALSE;
    }

    result = srv_phb_datamgr_res_check_data_space(MMI_PHB_CONTACT_FIELD_IMAGE);
    if (result != 0)
    {
        if (result < 0)
        {
            mmi_phb_popup_display_ext(
                srv_fmgr_fs_error_get_string(result),
                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result));
        }
        else
        {
            mmi_phb_popup_display_ext(
                STR_GLOBAL_NOT_ENOUGH_MEMORY,
                MMI_EVENT_FAILURE);
        }
        return MMI_FALSE;
    }

    /*
     * Check image content, check if the image header can be parsed correctly
     * Check image "size", "width", "height", value can be customize in file manage app.
     */
    if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_CALLER_PICTURE, path, &error_str_ptr))
    {
        if (auto_resize)
        {
            S32 buf_size = 0;
            U8 *buf_ptr = NULL;
            S32 height, width, encoded_file_size;
            gdi_image_get_dimension_file((CHAR*)path, (S32*) &(width), (S32*) &(height));
            if ((width * height) > (MMI_PHB_IMAGE_MAX_WIDTH * MMI_PHB_IMAGE_MAX_HEIGHT))
            {
                width = MMI_PHB_IMAGE_MAX_WIDTH;
                height = MMI_PHB_IMAGE_MAX_HEIGHT;
            }
            buf_size = (width * height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
            buf_size = ((buf_size + 3) / 4) * 4;
            media_get_ext_buffer(MOD_MMI, (void **)&buf_ptr, buf_size);
            if (buf_ptr != NULL)
            {
                GDI_RESULT gdi_ret;
                WCHAR* tmp_path = 
                    mmi_phb_mem_malloc((SRV_FMGR_PATH_MAX_LEN + 1)* sizeof(WCHAR), SRV_PHB_MEMORY_TYPE_CTR);
                kal_wsprintf(tmp_path, "%w.jpg", path);
                FS_Delete(tmp_path);
                gdi_ret = gdi_image_encode_file_to_jpeg_with_exp_size(
                            path,
                            (CHAR*)tmp_path,
                            width,
                            height,
                            buf_ptr,
                            buf_size,
                            MMI_PHB_IMAGE_MAX_SIZE,
                            &encoded_file_size);
                media_free_ext_buffer(MOD_MMI, (void **)&buf_ptr);
                FS_Delete((WCHAR*)path);
                if (gdi_ret == GDI_SUCCEED)
                {
                    FS_Rename(tmp_path, (WCHAR*)path);
                    if (mmi_fmgr_util_file_limit_check(FMGR_LIMIT_CALLER_PICTURE, path, &error_str_ptr))
                    {
                    	  mmi_phb_mem_free(tmp_path);
                        return MMI_TRUE;
                    }
                }
                else
                {
                    error_str_ptr = GetString(STR_GLOBAL_FILE_NOT_FOUND);
                }
                FS_Delete(tmp_path);
                mmi_phb_mem_free(tmp_path);
            }
        }
        mmi_phb_popup_display(
            (UI_string_type) error_str_ptr, 
            MMI_EVENT_FAILURE);
        return MMI_FALSE;
    }
    return MMI_TRUE;
#else
    return MMI_TRUE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_preview_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_preview_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0)
    {
        MMI_ID sg_id = mmi_frm_group_get_active_id();
        
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);
        ChangeRightSoftkey(0, 0);

        mmi_popup_display_simple_ext(
            STR_GLOBAL_UNSUPPORTED_FORMAT,
            MMI_EVENT_FAILURE,
            sg_id,
            NULL);

        mmi_frm_scrn_close(sg_id, SCR_ID_PHB_IMAGE_VIEW_IMAGE);
        SetLeftSoftkeyFunction(UI_dummy_function, KEY_EVENT_UP);
    }
}
#endif /* defined(__MMI_FILE_MANAGER__) */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_build_image_list
 * DESCRIPTION
 *  Builds Images list for inline selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_build_image_list(void)
{
#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
#if !defined(LOW_COST_SUPPORT) && !defined(__MMI_FTE_SUPPORT_SLIM__) && !defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
    U8 j;
    U8 maxSystemImages = 4;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* System Default Image */
#if !defined(LOW_COST_SUPPORT) && !defined(__MMI_FTE_SUPPORT_SLIM__) && !defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
    g_mmi_phb_resource.total_image_id = 1 + maxSystemImages;
#else
    g_mmi_phb_resource.total_image_id = 1;
#endif

    /* System Default Image */
    g_mmi_phb_resource.image_name_list[0] = (PU8) GetString(STR_GLOBAL_DEFAULT);
    g_mmi_phb_resource.image_id_list[0] = IMG_PHB_DEFAULT;

#if !defined(LOW_COST_SUPPORT) && !defined(__MMI_FTE_SUPPORT_SLIM__) && !defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
    for (j = 0; j < maxSystemImages; ++j)
    {
        g_mmi_phb_resource.image_name_list[++i] = (PU8) GetString((U16) (STR_PICTURE_1 + j));
        g_mmi_phb_resource.image_id_list[i] = IMG_PHB_PICTURE1 + j;
    }
#endif

    /* Select Image From File Manager */
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)

#if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
    g_mmi_phb_resource.total_image_id++;
    g_mmi_phb_resource.image_name_list[++i] = (U8*) GetString(STR_ID_PHB_CALLER_IMAGE_FROM_CAMERA);
    g_mmi_phb_resource.image_id_list[i] = 0xA000;
#endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */

    g_mmi_phb_resource.total_image_id++;
    g_mmi_phb_resource.image_name_list[++i] = (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECT_FILE);
    g_mmi_phb_resource.image_id_list[i] = 0x8000;
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */
#else
    g_mmi_phb_resource.total_image_id = 1;
    g_mmi_phb_resource.image_name_list[0] = (U8*) GetString(STR_GLOBAL_DEFAULT);
    g_mmi_phb_resource.image_id_list[0] = IMG_PHB_DEFAULT;
#endif
}


static U16 mmi_phb_get_image_id(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_phb_resource.image_id_list[index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_image_index
 * DESCRIPTION
 *  Gets the index of the current image tag in  images list
 * PARAMETERS
 *  img_id         [IN]        Image for lookup
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_phb_get_image_index(U16 img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* An external video resource */
    if (img_id & 0x8000)
    {
        return (U8) (g_mmi_phb_resource.total_image_id - 1);
    }

    /* An internal video resource, mask it to get resource id */
    img_id &= 0x3FFF;
    
    if (img_id)
    {
        for (i = 0; i < g_mmi_phb_resource.total_image_id; ++i)
        {
            if (g_mmi_phb_resource.image_id_list[i] == img_id)
            {
                return i;
            }
        }
        return 0;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_option_image_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of inline editor image field. Used when file manager exists.
 * PARAMETERS
 *  index       [IN]        Current inline selection index.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_edit_option_image_highlight_hdlr(mmi_id menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_IMAGE_OPTION_SELECT, MMI_TRUE);
#if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_IMAGE_OPTION_CAMERA, MMI_TRUE);
#endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
#endif
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_IMAGE_OPTION_VIEW, MMI_TRUE);

#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    switch (g_mmi_phb_resource.image_id_list[g_mmi_phb_res_p->selected_pic_index])
    {
    #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)  
        case 0x8000:
            if (g_mmi_phb_res_p->image_location == MMI_PHB_IMAGE_SELECT_PATH
                || g_mmi_phb_res_p->image_location == MMI_PHB_IMAGE_FOR_ENTRY
                || g_mmi_phb_res_p->image_location == MMI_PHB_IMAGE_CALLER_GROUP)
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_IMAGE_OPTION_VIEW, MMI_FALSE);
            }
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_IMAGE_OPTION_SELECT, MMI_FALSE);
            break;
    #endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */
    #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
        case 0xA000:
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_IMAGE_OPTION_CAMERA, MMI_FALSE);
            break;
    #endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
        default:
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_IMAGE_OPTION_VIEW, MMI_FALSE);
            break;
    }
#endif    
}


#define MMI_PHB_RESOURCE_SETTING_VIDEO

#if defined(__MMI_PHB_CALLER_VIDEO__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_build_video_list
 * DESCRIPTION
 *  Builds Video list for inline selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_build_video_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* System Default video */
    g_mmi_phb_resource.video_name_list[count] = (U8*) GetString(STR_GLOBAL_DEFAULT);
    g_mmi_phb_resource.video_id_list[count] = 0;
    g_mmi_phb_resource.total_video_id = 1;
#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SWFLASH__ */
#endif

    for (i = 0; i < 1; i++)
    {
        g_mmi_phb_resource.video_name_list[++count] = (U8*) GetString((U16) (STR_ID_PHB_VIDEO_1 + i));
        g_mmi_phb_resource.video_id_list[count] = VDO_ID_PHB_MTCALL_1 + i;
        g_mmi_phb_resource.total_video_id++;
    }
#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SWFLASH__ */
#endif

    /* Select From File */
    g_mmi_phb_resource.video_name_list[++count] = (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECT_FILE);
    g_mmi_phb_resource.video_id_list[count] = 0x8000;
    g_mmi_phb_resource.total_video_id++;
}


U16 mmi_phb_get_video_id(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_phb_resource.video_id_list[index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_video_index
 * DESCRIPTION
 *  Retrieve video list index by video id.
 * PARAMETERS
 *  video_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phb_get_video_index(U16 video_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* An external video resource */
    if (video_id & 0x8000)
    {
    #if 0
    #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SWFLASH__ */
	#endif
        return (U8) (g_mmi_phb_resource.total_video_id - 1);
    }

    /* An internal video resource, mask it to get resource id */
    video_id &= 0x3FFF;

    if (video_id)
    {
        for (i = 0; i < (g_mmi_phb_resource.total_video_id - 1); i++)
        {
            if (video_id == g_mmi_phb_resource.video_id_list[i])
            {
                return i;
            }
        }
    }

    return 0;
}


static U8 g_phb_video_option_type; /* 0: all menu option, 1: default video option */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_highlight_hdlr
 * DESCRIPTION
 *  This highlight hdlr is for video setting in Non tab edit screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == (g_mmi_phb_resource.total_video_id - 1))
    {
        if (g_mmi_phb_res_p->video_location == MMI_PHB_IMAGE_SELECT_PATH
            || g_mmi_phb_res_p->video_location == MMI_PHB_IMAGE_FOR_ENTRY
            || g_mmi_phb_res_p->video_location == MMI_PHB_IMAGE_CALLER_GROUP)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_phb_video_pre_entry_file_option, KEY_EVENT_UP);
            #ifndef __MMI_PHB_SLIM__
            ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_PLAY);
			#endif
            SetCenterSoftkeyFunction(mmi_phb_entry_video_view, KEY_EVENT_UP);
        }
        else
        {
            ChangeLeftSoftkey(STR_GLOBAL_SELECT, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_phb_video_select_from_file_mamager, KEY_EVENT_UP);

            ChangeCenterSoftkey(0, IMG_NONE);
            SetCenterSoftkeyFunction(mmi_phb_video_select_from_file_mamager, KEY_EVENT_UP);
        }
    }
#if 0	
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifndef __MMI_PHB_SLIM__
/* under construction !*/
			#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifndef __MMI_PHB_SLIM__
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SWFLASH__ */
#endif
    else if (index != 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_phb_entry_video_default_option, KEY_EVENT_UP);
        #ifndef __MMI_PHB_SLIM__
        ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_PLAY);
		#endif
        SetCenterSoftkeyFunction(mmi_phb_entry_video_view, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);

        ChangeCenterSoftkey(0, 0);
        ClearKeyHandler(KEY_CSK, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_exit_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_exit_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
}


#if defined(__MMI_PHB_UI_IN_TABS__) && !(defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
//#if !defined(__MMI_OP12_PHB__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_choose_caller_video_done
 * DESCRIPTION
 *  For choose default video in tab edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_choose_caller_video_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_res_p->done = 1;
    g_mmi_phb_res_p->selected_video_index = g_mmi_phb_res_p->highlight_index;
    
    mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        g_mmi_phb_res_p->sg_id,
        NULL);

    mmi_frm_scrn_close(g_mmi_phb_res_p->sg_id, SCR_ID_PHB_VIDEO_OPTION);
    mmi_frm_scrn_close(g_mmi_phb_res_p->sg_id, SCR_ID_PHB_TAB_EDIT_CALLER_VIDEO);
    mmi_frm_scrn_close(g_mmi_phb_res_p->sg_id, SCR_ID_PHB_VIDEO_VIEW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_default_video_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_default_video_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 video_id;
    PU8 gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_id = g_mmi_phb_resource.video_id_list[g_mmi_phb_res_p->highlight_index];

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
    #if defined(__MMI_BACKGROUND_CALL__)
        if (mmi_frm_is_in_backward_scenario())
        {
            if (mmi_frm_scrn_enter(
                    g_mmi_phb_res_p->sg_id,
                    SCR_ID_PHB_VIDEO_VIEW,
                    NULL,
                    mmi_phb_entry_default_video_preview,
                    MMI_FRM_FULL_SCRN))
            {
                gui_buffer = mmi_frm_scrn_get_active_gui_buf();

                ShowCategory141Screen(
                    STR_GLOBAL_PLAY,
                    GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    (U8*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL),
                    0,
                    gui_buffer);
            }
            return;
        }
        else
    #endif
        {
            mmi_phb_ucm_app_entry_error_message();    
            return;
        }
    }
    else if ((video_id != 0) && !(video_id & 0x8000))
    {
        if (mmi_frm_scrn_enter(
                g_mmi_phb_res_p->sg_id,
                SCR_ID_PHB_VIDEO_VIEW,
                mmi_phb_video_exit_preview,
                mmi_phb_entry_default_video_preview,
                MMI_FRM_FULL_SCRN))
        {
            mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

            gui_buffer = mmi_frm_scrn_get_active_gui_buf();
		#if 0	
        #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SWFLASH__ */
		#endif
            {
            #ifdef __DRM_SUPPORT__
                S32 drm_video_flag = WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME | WGUI_CATVDO_DRM_DISABLE_CONSUME_COUNT | WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME_LIMIT_STOP;
                wgui_catvdo_set_drm_flag(drm_video_flag);
            #endif /* __DRM_SUPPORT__ */
                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

                ShowCategory225Screen(
                    STR_GLOBAL_PLAY,                    /* title_str */
                    IMG_SCR_PBOOK_CAPTION,              /* title_icon */
                    STR_GLOBAL_OK,                                  /* lsk_str */
                    IMG_GLOBAL_OK,                                  /* lsk_icon */
                    STR_GLOBAL_BACK,                    /* rsk_str */
                    IMG_GLOBAL_BACK,                    /* rsk_icon */
                    video_id,                           /* video_id */
                    NULL,                               /* video_filename */
                    1,                                  /* repeat_count */
                    TRUE,                               /* is_visual_update */
                    (BOOL)(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED),   /* is_play_audio */
                    TRUE,                               /* is_lcd_no_sleep */
                    GDI_COLOR_WHITE,                    /* bg_color */
                    mmi_phb_video_view_callback,
                    gui_buffer);
            }
            SetLeftSoftkeyFunction(mmi_phb_choose_caller_video_done, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_phb_choose_caller_video_done, KEY_EVENT_UP);
        }
    }
    else
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_ERROR,
            MMI_EVENT_FAILURE,
            g_mmi_phb_res_p->sg_id,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_choose_caller_video_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_choose_caller_video_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_res_p->highlight_index = index;

    if (index == (g_mmi_phb_resource.total_video_id - 1))
    {
        SetLeftSoftkeyFunction(mmi_phb_video_select_from_file_mamager, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phb_video_select_from_file_mamager, KEY_EVENT_UP);
    }
#if 0	
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SWFLASH__ */
#endif
    else if (index != 0)
    {
        SetLeftSoftkeyFunction(mmi_phb_entry_default_video_preview, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phb_entry_default_video_preview, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_phb_choose_caller_video_done, KEY_EVENT_UP);        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phb_choose_caller_video_done, KEY_EVENT_UP);
    }
}
//#endif
#endif /* defined(__MMI_PHB_UI_IN_TABS__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_choose_caller_video
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_choose_caller_video(void)
{
    if (g_mmi_phb_res_p->sg_id != GRP_ID_PHB_GROUP)
    {
    #if defined(__MMI_PHB_UI_IN_TABS__) && !(defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
    #if 0
    #if defined(__MMI_OP12_PHB__)
/* under construction !*/
    #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
/* under construction !*/
    #endif
    #else /* __MMI_OP12_PHB__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_SWFLASH__
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_OP12_PHB__) */
	#else
	    U8 *guiBuffer;
        U8 i;

        if (mmi_frm_scrn_enter(
                g_mmi_phb_res_p->sg_id,
                SCR_ID_PHB_TAB_EDIT_CALLER_VIDEO,
                NULL,
                (FunctionPtr)mmi_phb_entry_choose_caller_video,
                MMI_FRM_FULL_SCRN))
        {
            guiBuffer = mmi_frm_scrn_get_active_gui_buf();

            RegisterHighlightHandler(mmi_phb_choose_caller_video_hilite_handler);

            if (guiBuffer == NULL)
            {
                g_mmi_phb_res_p->highlight_index = g_mmi_phb_res_p->selected_video_index;
            }

            for (i = 0; i < g_mmi_phb_resource.total_video_id; i++)
            {
                subMenuDataPtrs[i] = g_mmi_phb_resource.video_name_list[i];
            }

            subMenuDataPtrs[g_mmi_phb_resource.total_video_id - 1] = (U8*)GetString(STR_ID_PHB_FMGR_IMAGE_SELECT_FILE);
        #if 0
		#ifdef __MMI_SWFLASH__
/* under construction !*/
        #endif
		#endif

            ShowCategory89Screen(
                STR_ID_PHB_ASSOCIATE_VIDEO,
                GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_mmi_phb_resource.total_video_id,
                subMenuDataPtrs,
                NULL,
                0,
                g_mmi_phb_res_p->selected_video_index,
                guiBuffer);
        }
	#endif
    #else /* __MMI_PHB_UI_IN_TABS__ */
    
        if (g_mmi_phb_res_p->selected_video_index == g_mmi_phb_resource.total_video_id - 1)
        {
            mmi_phb_video_select_from_file_mamager();
        }
	#if 0	
    #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif
        else
        {
            MMI_ASSERT(0);
        }
    #endif /* __MMI_PHB_UI_IN_TAB__ */
    }
    else
    {
        if (g_mmi_phb_res_p->selected_video_index == g_mmi_phb_resource.total_video_id - 1)
        {
            mmi_phb_video_select_from_file_mamager();
        }
	#if 0	
    #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif
        else
        {
            MMI_ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_video_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_video_view_ext(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FunctionPtr entry_proc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_mmi_phb_res_p->selected_video_index == (g_mmi_phb_resource.total_video_id - 1))
	#if 0	
    #ifdef __MMI_SWFLASH__
/* under construction !*/
    #endif /* __MMI_SWFLASH__ */
	#endif
        )
    {
        entry_proc = (FunctionPtr)mmi_phb_video_view_from_file;
    }
    else
    {
        entry_proc = (FunctionPtr)mmi_phb_video_view_from_default;
    }

    mmi_frm_scrn_first_enter(
        group_id,
        SCR_ID_PHB_VIDEO_VIEW,
        entry_proc,
        NULL);
}


void mmi_phb_entry_video_view(void)
{
    mmi_phb_entry_video_view_ext(g_mmi_phb_save_contact_p->sg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_delete_default_reference
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_video_delete_default_reference(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                                */
    /*----------------------------------------------------------------*/
    g_mmi_phb_res_p->video_audio = 1;
    g_mmi_phb_res_p->video_location = MMI_PHB_IMAGE_NO_SELECT;
    g_mmi_phb_res_p->done = 1;
    
#ifdef __MMI_PHB_UI_IN_TABS__
    g_mmi_phb_res_p->selected_video_index = 0;
#endif
    mmi_popup_display_simple_ext(
        STR_GLOBAL_REMOVED,
        MMI_EVENT_SUCCESS,
        group_id,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_delete_reference
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_delete_reference(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_mmi_phb_res_p->selected_video_index == (g_mmi_phb_resource.total_video_id - 1))
	#if 0	
    #ifdef __MMI_SWFLASH__
/* under construction !*/
    #endif /* __MMI_SWFLASH__ */
	#endif
        )
    {
        mmi_phb_video_delete_file_reference(group_id);
    }
    else
    {
        mmi_phb_video_delete_default_reference(group_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_delete_file_reference
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_delete_file_reference(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_res_p->video_location == MMI_PHB_IMAGE_NO_SELECT)
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_FMGR_IMAGE_NO_SELECT,
            MMI_EVENT_FAILURE,
            group_id,
            NULL);
    }
    else
    {
        g_mmi_phb_res_p->video_location = MMI_PHB_IMAGE_NO_SELECT;
    #if 0
    #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SWFLASH__ */
	#endif

        g_mmi_phb_resource.video_name_list[g_mmi_phb_resource.total_video_id - 1] =
            (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECT_FILE);

        mmi_popup_display_simple_ext(
            STR_GLOBAL_REMOVED,
            MMI_EVENT_SUCCESS,
            group_id,
            NULL);
    }
    
    g_mmi_phb_res_p->video_audio = 1;    
    g_mmi_phb_res_p->done = 1;
#ifdef __MMI_PHB_UI_IN_TABS__
    g_mmi_phb_res_p->selected_video_index = 0;   
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_video_default_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_video_default_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_video_option_type = 1;
    mmi_phb_entry_video_file_option();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_pre_entry_file_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_pre_entry_file_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_video_option_type = 0;
    mmi_phb_entry_video_file_option();
}


mmi_ret mmi_phb_video_edit_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_ret result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            result = MMI_RET_DONT_CARE;
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            MMI_ID sg_id = g_mmi_phb_save_contact_p->sg_id;

            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_PHB_VIDEO_FILE_VIEW:
                    mmi_phb_entry_video_view_ext(sg_id);
                    break;

                case MENU_ID_PHB_VIDEO_FILE_SELECT:
                    mmi_phb_entry_choose_caller_video();
                    break;

                case MENU_ID_PHB_VIDEO_FILE_DELETE:
                    mmi_phb_video_delete_reference(sg_id);
                    break;

                case MENU_ID_PHB_VIDEO_FILE_SETTING:
                    mmi_phb_entry_video_audio_option(sg_id);
                    break;

                default:
                    result = MMI_RET_DONT_CARE;
                    break; 
            }
            break;
        }
        
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        
        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_video_file_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_video_file_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_gid = cui_menu_create(
               g_mmi_phb_res_p->sg_id,
               CUI_MENU_SRC_TYPE_RESOURCE,
               CUI_MENU_TYPE_OPTION,
               MENU_ID_PHB_VIDEO_FILE_OPTION,
               MMI_FALSE, NULL);
    
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIDEO_FILE_DELETE, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIDEO_FILE_SELECT, MMI_FALSE);

        /* if video is default in list stype, then hide  delete/change menu. because user can press arrow key to select */
        if (g_phb_video_option_type == 1)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIDEO_FILE_DELETE, MMI_TRUE);
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIDEO_FILE_SELECT, MMI_TRUE);
        }
    }

    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);

    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_view_from_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_view_from_default(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 video_id;
    MMI_BOOL is_play_audio = (MMI_BOOL)(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED);
    PU8 gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_id = g_mmi_phb_resource.video_id_list[g_mmi_phb_res_p->selected_video_index];

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
    #if defined(__MMI_BACKGROUND_CALL__)
        if (mmi_frm_is_in_backward_scenario())
        {
            if (mmi_frm_scrn_enter(
                    scrn_data->group_id, 
                    SCR_ID_PHB_VIDEO_VIEW,
                    NULL,
                    (FunctionPtr)mmi_phb_video_view_from_default,
                    MMI_FRM_FULL_SCRN))
            {
                gui_buffer = mmi_frm_scrn_get_active_gui_buf();
                
                ShowCategory141Screen(
                    STR_GLOBAL_PLAY,
                    GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    (U8*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL),
                    0,
                    gui_buffer);
            }
            return;
        }
        else
    #endif
        {
            mmi_frm_scrn_close(scrn_data->group_id, scrn_data->scrn_id);
            mmi_phb_ucm_app_entry_error_message();    
            return;
        }
    }

    if ((video_id != 0) && !(video_id & 0x8000))
    {
        if (mmi_frm_scrn_enter(
                scrn_data->group_id, 
                SCR_ID_PHB_VIDEO_VIEW,
                mmi_phb_video_exit_preview,
                (FunctionPtr)mmi_phb_video_view_from_default,
                MMI_FRM_FULL_SCRN))
        {
            mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

            gui_buffer = mmi_frm_scrn_get_active_gui_buf();
		#if 0	
        #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SWFLASH__ */
		#endif
            {
            #ifdef __DRM_SUPPORT__
                S32 drm_video_flag = WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME | WGUI_CATVDO_DRM_DISABLE_CONSUME_COUNT | WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME_LIMIT_STOP;
                wgui_catvdo_set_drm_flag(drm_video_flag);
            #endif /* __DRM_SUPPORT__ */

                ShowCategory225Screen(
                    STR_GLOBAL_PLAY,                    /* title_str */
                    IMG_SCR_PBOOK_CAPTION,              /* title_icon */
                    0,                                  /* lsk_str */
                    0,                                  /* lsk_icon */
                    STR_GLOBAL_BACK,                    /* rsk_str */
                    IMG_GLOBAL_BACK,                    /* rsk_icon */
                    video_id,                           /* video_id */
                    NULL,                               /* video_filename */
                    (U16)1,                                  /* repeat_count */
                    TRUE,                               /* is_visual_update */
                    is_play_audio,   /* is_play_audio */
                    TRUE,                               /* is_lcd_no_sleep */
                    GDI_COLOR_WHITE,                    /* bg_color */
                    mmi_phb_video_view_callback,
                    gui_buffer);
            }
        }
    }
    else
    {
        mmi_frm_scrn_close(scrn_data->group_id, scrn_data->scrn_id);
        mmi_popup_display_simple_ext(
            STR_GLOBAL_ERROR,
            MMI_EVENT_FAILURE,
            scrn_data->group_id,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_view_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        Play result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_view_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum result_type;
    MMI_ID_TYPE error_string_id;
    MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0)
    {
        ChangeLeftSoftkey(0, 0);
        ChangeRightSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);
        
        error_string_id = mdi_util_get_mdi_error_info(result,&result_type);

        group_id = mmi_phb_cntx_mgr_get_current_sg_id();
        
        mmi_popup_display_simple_ext(
            error_string_id,
            result_type,
            group_id,
            NULL);

        /* delete to file select screen again */
        mmi_frm_scrn_close(group_id, SCR_ID_PHB_VIDEO_VIEW);
        SetLeftSoftkeyFunction(UI_dummy_function, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_view_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_view_from_file(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    FS_HANDLE file_handle;
    MMI_BOOL drm_ret = MMI_TRUE;
    MMI_BOOL is_play_audio = (MMI_BOOL)(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
    #if defined(__MMI_BACKGROUND_CALL__)
        if (mmi_frm_is_in_backward_scenario())
        {
            if (mmi_frm_scrn_enter(
                    scrn_data->group_id, 
                    SCR_ID_PHB_VIDEO_VIEW,
                    NULL,
                    (FunctionPtr)mmi_phb_video_view_from_file,
                    MMI_FRM_FULL_SCRN))
            {
                gui_buffer = mmi_frm_scrn_get_active_gui_buf();
                
                ShowCategory141Screen(
                    STR_GLOBAL_PLAY,
                    GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    (U8*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL),
                    0,
                    gui_buffer);
            }
            return;
        }
        else
    #endif
        {
            mmi_frm_scrn_close(scrn_data->group_id, scrn_data->scrn_id);
            mmi_phb_ucm_app_entry_error_message();    
            return;
        }
    }

    if ((g_mmi_phb_res_p->selected_video_index == g_mmi_phb_resource.total_video_id - 1
            && g_mmi_phb_res_p->video_location == MMI_PHB_IMAGE_SELECT_PATH)
    #if 0        
    #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SWFLASH__ */
	#endif
       ) 
    {
        {
            file_handle = DRM_open_file((kal_wchar *)g_mmi_phb_res_p->video_path, FS_READ_ONLY, DRM_PERMISSION_PLAY);

            if (file_handle >= FS_NO_ERROR)
            {
            #ifdef __DRM_SUPPORT__
                drm_ret = DRM_validate_forward_rule(file_handle, DRM_PERMISSION_PLAY);
            #endif /* __DRM_SUPPORT__ */
                DRM_close_file(file_handle);
                if (drm_ret == MMI_FALSE)
                {
                    mmi_frm_scrn_close(scrn_data->group_id, scrn_data->scrn_id);
                    mmi_popup_display_simple_ext(
                        STR_GLOBAL_DRM_PROHIBITED,
                        MMI_EVENT_FAILURE,
                        scrn_data->group_id,
                        NULL);
                    return;
                }
                if (mmi_frm_scrn_enter(
                    scrn_data->group_id, 
                    SCR_ID_PHB_VIDEO_VIEW,
                    mmi_phb_video_exit_preview,
                    (FunctionPtr)mmi_phb_video_view_from_file,
                    MMI_FRM_FULL_SCRN))
                {
                    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

                    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
                #if 0
                #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif /* __MMI_SWFLASH__ */
				#endif
                    {
                    #ifdef __DRM_SUPPORT__
                        S32 drm_video_flag = WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME | WGUI_CATVDO_DRM_DISABLE_CONSUME_COUNT | WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME_LIMIT_STOP;
                        wgui_catvdo_set_drm_flag(drm_video_flag);
                    #endif
                        ShowCategory225Screen(
                            STR_GLOBAL_PLAY,                    /* title_str */
                            IMG_SCR_PBOOK_CAPTION,              /* title_icon */
                            0,                                  /* lsk_str */
                            0,                                  /* lsk_icon */
                            STR_GLOBAL_BACK,                    /* rsk_str */
                            IMG_GLOBAL_BACK,                    /* rsk_icon */
                            0,                                  /* video_id */
                            (CHAR*) g_mmi_phb_res_p->video_path,  /* video_filename */
                            (U16)1,                             /* repeat_count */
                            TRUE,                               /* is_visual_update */
                            is_play_audio,                      /* is_play_audio */
                            TRUE,                               /* is_lcd_no_sleep */
                            GDI_COLOR_WHITE,                    /* bg_color */
                            mmi_phb_video_view_callback,
                            gui_buffer);
                    }
                }
            }
            else
            {
                mmi_frm_scrn_close(scrn_data->group_id, scrn_data->scrn_id);
                mmi_popup_display_simple_ext(
                    srv_fmgr_fs_error_get_string(file_handle),
                    (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(file_handle),
                    scrn_data->group_id,
                    NULL);
            }
        }
    }
    else
    {
        mmi_frm_scrn_close(scrn_data->group_id, scrn_data->scrn_id);
        mmi_popup_display_simple_ext(
            STR_ID_PHB_FMGR_IMAGE_NO_SELECT,
            MMI_EVENT_FAILURE,
            scrn_data->group_id,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_play_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        Play result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_play_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum result_type;
    MMI_ID_TYPE error_string_id;
    MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_video_select_from_file_mamager_done, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);
        ChangeRightSoftkey(0, 0);

        error_string_id = mdi_util_get_mdi_error_info(result,&result_type);
        group_id = mmi_phb_cntx_mgr_get_current_sg_id();
        mmi_popup_display_simple_ext(
            error_string_id,
            result_type,
            group_id,
            NULL);

        mmi_frm_scrn_close(group_id, SCR_ID_PHB_VIDEO_PREVIEW);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_select_from_file_mamager_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_select_from_file_mamager_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_caller_res_struct *res;
    mmi_id sg_id = g_mmi_phb_res_p->sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = (mmi_phb_caller_res_struct*) mmi_frm_scrn_get_user_data(sg_id, SCR_ID_PHB_VIDEO_PREVIEW);
    
    MMI_ASSERT(res != NULL);
    
    mmi_wcscpy(res->video_path, res->video_temp_path);
    res->video_location = MMI_PHB_IMAGE_SELECT_PATH;
    res->selected_video_index = g_mmi_phb_resource.total_video_id - 1;
    
    g_mmi_phb_resource.video_name_list[g_mmi_phb_resource.total_video_id - 1] =
        (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
    
    mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        sg_id,
        NULL);

    res->done = 1;

    cui_file_selector_close(res->child_id);
    
#ifdef __MMI_PHB_UI_IN_TABS__
    mmi_frm_scrn_close(sg_id, SCR_ID_PHB_TAB_EDIT_CALLER_VIDEO);
#endif
    mmi_frm_scrn_close(sg_id, SCR_ID_PHB_VIDEO_PREVIEW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_video_preview(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
#ifdef __DRM_SUPPORT__
    S32 drm_video_flag = WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME | WGUI_CATVDO_DRM_DISABLE_CONSUME_COUNT | WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME_LIMIT_STOP;
#endif
    MMI_BOOL is_play_audio = (MMI_BOOL)(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED);
    mmi_phb_caller_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
    #if defined(__MMI_BACKGROUND_CALL__)
        if (mmi_frm_is_in_backward_scenario())
        {
            if (mmi_frm_scrn_enter(
                    scrn_data->group_id,
                    SCR_ID_PHB_VIDEO_PREVIEW,
                    NULL,
                    (FunctionPtr)mmi_phb_video_preview,
                    MMI_FRM_FULL_SCRN))
            {
                gui_buffer = mmi_frm_scrn_get_active_gui_buf();
                
                ShowCategory141Screen(
                    STR_GLOBAL_PLAY,
                    GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    (U8*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL),
                    0,
                    gui_buffer);
                
            }
        }
        else
    #endif
        {
            mmi_frm_scrn_close(scrn_data->group_id, scrn_data->scrn_id);
            mmi_phb_ucm_app_entry_error_message();    
        }
    }
    else if (mmi_frm_scrn_enter(
                scrn_data->group_id,
                SCR_ID_PHB_VIDEO_PREVIEW,
                mmi_phb_video_exit_preview,
                (FunctionPtr)mmi_phb_video_preview,
                MMI_FRM_FULL_SCRN))
    {
        mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    #ifdef __DRM_SUPPORT__
        wgui_catvdo_set_drm_flag(drm_video_flag);
    #endif

        res = (mmi_phb_caller_res_struct *) scrn_data->user_data;

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory225Screen(
            STR_GLOBAL_PLAY,                    /* title_str */
            IMG_SCR_PBOOK_CAPTION,              /* title_icon */
            STR_GLOBAL_OK,                      /* lsk_str */
            IMG_GLOBAL_OK,                      /* lsk_icon */
            STR_GLOBAL_BACK,                    /* rsk_str */
            IMG_GLOBAL_BACK,                    /* rsk_icon */
            0,                                  /* video_id */
            (CHAR*) res->video_temp_path,      /* video_filename */
            (U16)1,                                  /* repeat_count */
            TRUE,                               /* is_visual_update */
            is_play_audio,   /* is_play_audio */
            TRUE,                               /* is_lcd_no_sleep */
            GDI_COLOR_WHITE,                    /* bg_color */
            mmi_phb_video_play_callback,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_phb_video_select_from_file_mamager_done, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_video_select_from_file_mamager_done, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_select_from_file_mamager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_select_from_file_mamager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL,
            MMI_EVENT_FAILURE,
            g_mmi_phb_res_p->sg_id,
            NULL);
    }
    else if (!mmi_phb_usb_app_unavailable_popup(0))
    {
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_VIDEO(&filter);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    #if defined(__DRM_V02__)
        FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
    #endif /* defined(__DRM_V02__) */

        g_mmi_phb_res_p->child_id = cui_file_selector_create(
                                        g_mmi_phb_res_p->sg_id,
                                        (WCHAR*) L"root",
                                        &filter,
                                        CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                                        CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON | CUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON | CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FOLDER);

        if (g_mmi_phb_res_p->child_id > 0)
        {
            cui_file_selector_set_title(g_mmi_phb_res_p->child_id, 0, IMG_SCR_PBOOK_CAPTION);

            g_mmi_phb_res_p->curr_res_type = MMI_PHB_RES_VIDEO;
            
            cui_file_selector_set_userdata(g_mmi_phb_res_p->child_id, (U32) g_mmi_phb_res_p);
            
            cui_file_selector_run(g_mmi_phb_res_p->child_id);
        }
        else
        {
            mmi_popup_display_simple_ext(
                STR_GLOBAL_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                g_mmi_phb_res_p->sg_id,
                NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_select_path_from_file_mamager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_select_path_from_file_mamager(mmi_phb_caller_res_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /**
     * get selected path
     */
    cui_file_selector_get_selected_filepath(
        res->child_id,
        NULL,
        (WCHAR *) res->video_temp_path,
        (SRV_FMGR_PATH_MAX_LEN+1) * ENCODING_LENGTH);

    /* Check File Path Length */
    if (mmi_phb_video_check_data_space((CHAR*) res->video_temp_path))
    {
        mmi_frm_scrn_first_enter(
            res->sg_id,
            SCR_ID_PHB_VIDEO_PREVIEW,
            (FunctionPtr) mmi_phb_video_preview,
            res);            
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_save_contact_notify
 * DESCRIPTION
 *  write save notify to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_set_video_audio(MMI_ID group_id, U8 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_res_p->video_audio != value)
    {
        g_mmi_phb_res_p->video_audio = value;
        g_mmi_phb_res_p->done = 1;
    }

    mmi_popup_display_simple_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS,
        group_id,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_audio_menu_cui_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phb_video_audio_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            if (menu_evt->parent_menu_id == MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_ON)
            {
                mmi_phb_set_video_audio(g_mmi_phb_res_p->sg_id, MMI_PHB_EDIT_VIDEO_OPTION_AUDIO_ON);
                cui_menu_close(((cui_menu_event_struct*)evt)->sender_id);
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_OFF)
            {
                mmi_phb_set_video_audio(g_mmi_phb_res_p->sg_id, MMI_PHB_EDIT_VIDEO_OPTION_AUDIO_OFF);
                cui_menu_close(((cui_menu_event_struct*)evt)->sender_id);
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
            break;
        }

        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}


void mmi_phb_entry_video_audio_option(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_gid = cui_menu_create(
                       group_id,
                       CUI_MENU_SRC_TYPE_RESOURCE,
                       CUI_MENU_TYPE_APPSUB,
                       MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET,
                       MMI_FALSE, NULL);
    
    cui_menu_set_currlist_flags(menu_gid, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
    
    if (g_mmi_phb_res_p->video_audio)
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_ON);
    }
    else
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_OFF);
    }

    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);

    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_check_data_space
 * DESCRIPTION
 *  Check free space in data record before save to phonebook.
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_phb_video_check_data_space(CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *error_str_ptr;
    S32 result;
    BOOL drm_ret = TRUE;
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (path != NULL)
	{
		fh = DRM_open_file((kal_wchar *)path, FS_READ_ONLY, DRM_PERMISSION_PLAY);

		if (fh >= FS_NO_ERROR)
		{
	    #ifdef __DRM_SUPPORT__
			drm_ret = DRM_validate_forward_rule(fh, DRM_PERMISSION_PLAY);
	    #endif /* __DRM_SUPPORT__ */
			DRM_close_file(fh);

            if (drm_ret == FALSE)
            {        
                mmi_phb_popup_display_ext(
                    STR_GLOBAL_DRM_PROHIBITED,
                    MMI_EVENT_FAILURE);

                return MMI_FALSE;
            }
		}
		else
		{
            mmi_phb_popup_display_ext(
                srv_fmgr_fs_error_get_string(fh),
                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(fh));

            return MMI_FALSE;
		}
	}

    result = srv_phb_datamgr_res_check_data_space(MMI_PHB_CONTACT_FIELD_VIDEO);

    if (result != 0)
    {
        if (result < 0)
        {
            mmi_popup_display_ext(
                srv_fmgr_fs_error_get_string(result),
                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result),
                NULL);
        }
        else
        {
            mmi_popup_display_ext(
                STR_GLOBAL_NOT_ENOUGH_MEMORY,
                MMI_EVENT_FAILURE,
                NULL);
        }

        return MMI_FALSE;
    }
    else if (path && !mmi_fmgr_util_file_limit_check(FMGR_LIMIT_CALLER_VIDEO, path, &error_str_ptr))
    {
        mmi_phb_popup_display(
            (UI_string_type) error_str_ptr,
            MMI_EVENT_FAILURE);

        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}

#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_PHB_UI_IN_TABS__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_BACKGROUND_CALL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SWFLASH__ */
#endif


//#ifndef __MMI_PHB_UI_IN_TABS__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_option_video_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of inline editor image field. Used when file manager exists.
 * PARAMETERS
 *  index       [IN]        Current inline selection index.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_edit_option_video_highlight_hdlr(mmi_id menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_PLAY, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_SELECT, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET, MMI_TRUE);

    if (g_mmi_phb_res_p->selected_video_index == (g_mmi_phb_resource.total_video_id - 1))
    {
        if (g_mmi_phb_res_p->video_location == MMI_PHB_IMAGE_SELECT_PATH)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_PLAY, MMI_FALSE);
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_SELECT, MMI_FALSE);
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET, MMI_FALSE);
            //cui_menu_set_non_leaf_item(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_SELECT, MMI_FALSE);
        }
    }
    else if (g_mmi_phb_res_p->selected_video_index != 0)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_PLAY, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET, MMI_FALSE);
        //cui_menu_set_non_leaf_item(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET, MMI_FALSE);
    }
}
//#endif

#endif /* __MMI_PHB_CALLER_VIDEO__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_res_check_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res_id                  [IN]
 *  path                    [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phb_res_check_valid(U16 res_id, U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FILE_MANAGER__
    if (path[0])
    {
        if (srv_fmgr_fs_path_exist((WCHAR*)path) >= 0)
        {
            valid = MMI_TRUE;
        }
    }
#endif

    return valid;
}


void mmi_phb_contact_res_config(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //contact ring tone
    mmi_phb_build_ring_tone_list();

#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) && defined(__SRV_PHB_CALLER_RES_DATA_STORE__)
    if (g_mmi_phb_res_p->ring_location != MMI_PHB_IMAGE_NO_SELECT)
    {
        g_mmi_phb_resource.ring_tone_name_list[g_mmi_phb_resource.total_ring_tone - 1] =
                (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
    }
#endif

    //contact video
#if defined(__MMI_PHB_CALLER_VIDEO__)
    mmi_phb_build_video_list();

    if (g_mmi_phb_res_p->video_location != MMI_PHB_IMAGE_NO_SELECT)       /* Change Inline select prompt message. */
    {
    #if 0
    #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_SWFLASH__) */
	#endif
        {
            g_mmi_phb_resource.video_name_list[g_mmi_phb_resource.total_video_id - 1] =
                (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
        }
    }
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */ 

#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
    mmi_phb_build_image_list();
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    if (g_mmi_phb_res_p->image_location != MMI_PHB_IMAGE_NO_SELECT)
    {
        if (g_mmi_phb_res_p->image_location == MMI_PHB_IMAGE_SELECT_PATH) /* Change Inline select prompt message. */
        {
            g_mmi_phb_resource.image_name_list[g_mmi_phb_resource.total_image_id - 1] =
                (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
        }
    }    
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */ 
#endif
}


void mmi_phb_contact_build_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_build_ring_tone_list();
    mmi_phb_build_image_list();
#if defined(__MMI_PHB_CALLER_VIDEO__)
    mmi_phb_build_video_list();
#endif

    g_mmi_phb_res_p->ring_location = MMI_PHB_IMAGE_NO_SELECT;

#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) && defined(__SRV_PHB_CALLER_RES_DATA_STORE__)
    if (g_mmi_phb_res_p->ring_path[0] != 0)
    {
        if (srv_fmgr_fs_path_exist((WCHAR*)g_mmi_phb_res_p->ring_path) >= 0)
        {
            g_mmi_phb_res_p->selected_ring_index = g_mmi_phb_resource.total_ring_tone - 1;
            g_mmi_phb_resource.ring_tone_name_list[g_mmi_phb_resource.total_ring_tone - 1] =
                (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
            g_mmi_phb_res_p->ring_location = MMI_PHB_IMAGE_SELECT_PATH;
			g_mmi_phb_res_p->ring_id = MMI_RP_SRV_PROF_AUD_MAX;
        }
        else
        {
            g_mmi_phb_res_p->selected_ring_index = 0;
        }
    }
    else
#endif
    {
        g_mmi_phb_res_p->selected_ring_index = mmi_phb_get_ring_tone_index(g_mmi_phb_res_p->ring_id);
        g_mmi_phb_res_p->ring_location = MMI_PHB_IMAGE_NO_SELECT;
    }

#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
    g_mmi_phb_res_p->selected_pic_index = mmi_phb_get_image_index(g_mmi_phb_res_p->img_id);
    g_mmi_phb_res_p->image_location = MMI_PHB_IMAGE_NO_SELECT;
    
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    if (g_mmi_phb_res_p->img_id & 0x8000)
    {
        if (mmi_phb_res_check_valid(g_mmi_phb_res_p->img_id, g_mmi_phb_res_p->img_path))
        {
            if (g_mmi_phb_res_p->selected_pic_index == g_mmi_phb_resource.total_image_id - 1)
            {
                g_mmi_phb_resource.image_name_list[g_mmi_phb_resource.total_image_id - 1] =
                    (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
                
                g_mmi_phb_res_p->image_location = MMI_PHB_IMAGE_SELECT_PATH;
            }
        }
        else
        {
            g_mmi_phb_res_p->selected_pic_index = 0;
        }
    }
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */ 
#endif

#if defined(__MMI_PHB_CALLER_VIDEO__)
    g_mmi_phb_res_p->selected_video_index = mmi_phb_get_video_index(g_mmi_phb_res_p->video_id);
    g_mmi_phb_res_p->video_location = MMI_PHB_IMAGE_NO_SELECT;

    /* set audio tone */
    if (g_mmi_phb_res_p->video_id & 0x4000 || g_mmi_phb_res_p->selected_video_index == 0)
    {
        g_mmi_phb_res_p->video_audio = MMI_TRUE;
    }
    else
    {
        g_mmi_phb_res_p->video_audio = MMI_FALSE;
    }
        
    if (g_mmi_phb_res_p->video_id & 0x8000)
    {
        /* Check if can load video path */
        if (mmi_phb_res_check_valid(g_mmi_phb_res_p->video_id, g_mmi_phb_res_p->video_path))
        {
            /* Change Inline select prompt message. */
            if (g_mmi_phb_res_p->selected_video_index == g_mmi_phb_resource.total_video_id - 1)
            {
                g_mmi_phb_resource.video_name_list[g_mmi_phb_resource.total_video_id - 1] =
                    (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
                
                g_mmi_phb_res_p->video_location = MMI_PHB_IMAGE_SELECT_PATH;
            }
		#if 0	
        #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SWFLASH__ */
		#endif
        }
        else
        {
            g_mmi_phb_res_p->selected_video_index = 0;
        }
    }
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */ 

}


void mmi_phb_contact_res_value_save(
        mmi_phb_contact_info_struct *contact_cntx,
        mmi_phb_caller_res_struct *caller_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(caller_res != NULL && contact_cntx != NULL);

    /* ring */
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) && defined(__SRV_PHB_CALLER_RES_DATA_STORE__)
    if (caller_res->selected_ring_index != g_mmi_phb_resource.total_ring_tone - 1)
    {
        caller_res->ring_location = MMI_PHB_IMAGE_NO_SELECT;
    }
    else if (caller_res->selected_ring_index == g_mmi_phb_resource.total_ring_tone - 1 &&
        caller_res->ring_location != MMI_PHB_IMAGE_SELECT_PATH)
    {
        caller_res->selected_ring_index = 0;
        caller_res->ring_location = MMI_PHB_IMAGE_NO_SELECT;
    }
#endif

    contact_cntx->ring_tone_id = g_mmi_phb_resource.ring_tone_list[caller_res->selected_ring_index];
    if (caller_res->ring_location == MMI_PHB_IMAGE_NO_SELECT)
    {
        contact_cntx->ring_tone[0] = 0;
    }
    else
    {
        mmi_wcscpy(contact_cntx->ring_tone, caller_res->ring_path);
    }

    /* image */
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    if ((caller_res->selected_pic_index != g_mmi_phb_resource.total_image_id - 1)
        )
    {
        caller_res->image_location = MMI_PHB_IMAGE_NO_SELECT;
    }
    else if ((caller_res->selected_pic_index == g_mmi_phb_resource.total_image_id - 1)
        && (caller_res->image_location != MMI_PHB_IMAGE_SELECT_PATH))
    {
        caller_res->selected_pic_index = 0;
        caller_res->image_location = MMI_PHB_IMAGE_NO_SELECT;
    }
#endif

    contact_cntx->picture_id = mmi_phb_get_image_id((U8)caller_res->selected_pic_index);
    if (caller_res->image_location == MMI_PHB_IMAGE_NO_SELECT)
    {
        contact_cntx->picture[0] = 0;
    }
    else
    {
        mmi_wcscpy(contact_cntx->picture, caller_res->img_path);
    }

    /* video */
#if defined(__MMI_PHB_CALLER_VIDEO__)
    if ((caller_res->selected_video_index != g_mmi_phb_resource.total_video_id - 1) /* De-select the file if selection is not from file. */
    #if 0
    #ifdef __MMI_SWFLASH__
/* under construction !*/
    #endif
    #endif
        )
    {
        caller_res->video_location = MMI_PHB_IMAGE_NO_SELECT;
    }
    else if ((caller_res->selected_video_index == g_mmi_phb_resource.total_video_id - 1)
        && (caller_res->video_location != MMI_PHB_IMAGE_SELECT_PATH))
    {
        caller_res->selected_video_index = 0;
        caller_res->video_location = MMI_PHB_IMAGE_NO_SELECT;
    }
#if 0	
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* def __MMI_SWFLASH__ */
#endif

    contact_cntx->video_id = mmi_phb_get_video_id((U8) caller_res->selected_video_index);

    if (caller_res->video_audio)
    {
        contact_cntx->video_id |= 0x4000;
    }
    
    if (caller_res->video_location == MMI_PHB_IMAGE_NO_SELECT)
    {
        contact_cntx->video[0] = 0;
    }
    else
    {
        mmi_wcscpy(contact_cntx->video, caller_res->video_path);
    }
#endif
}


void mmi_phb_contact_res_value_assign(
        mmi_id sg_id,
        mmi_phb_caller_res_struct *caller_res,
        mmi_phb_contact_info_struct *contact_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(caller_res != NULL && contact_cntx != NULL);
    caller_res->sg_id = sg_id;
    caller_res->done = MMI_FALSE;

    caller_res->ring_id = contact_cntx->ring_tone_id;
    mmi_wcscpy(caller_res->ring_path, contact_cntx->ring_tone);

    caller_res->img_id = contact_cntx->picture_id;
    mmi_wcscpy(caller_res->img_path, contact_cntx->picture);

#if defined(__MMI_PHB_CALLER_VIDEO__)
    caller_res->video_id = contact_cntx->video_id;
    mmi_wcscpy(caller_res->video_path, contact_cntx->video);
#endif    
}


void mmi_phb_fmgr_cui_res_handle(cui_file_selector_result_event_struct *file_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_caller_res_struct *res;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_select->result > 0)
    {
        res = (mmi_phb_caller_res_struct*)cui_file_selector_get_userdata(file_select->sender_id);
        switch (res->curr_res_type)
        {
        #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
            case MMI_PHB_RES_IMAGE:
            {
                mmi_phb_image_select_path_from_file_mamager(res);
                break;
            }
            case MMI_PHB_RES_RING:
            {
                mmi_phb_ringtone_select_path_from_file_manager(res);
                break;
            }
        #endif

        #if defined(__MMI_PHB_CALLER_VIDEO__)
            case MMI_PHB_RES_VIDEO:
            {
                mmi_phb_video_select_path_from_file_mamager(res);
                break;
            }
        #if 0
        #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        #endif
        #endif
            default:
                MMI_ASSERT(0);
                break;
        }
    }
    else if (file_select->result == 0)
    {
        cui_file_selector_close(file_select->sender_id);
    }
    else
    {
        /* filemgr will popup up the error, app maybe also should handle it at here */
        cui_file_selector_close(file_select->sender_id);
    }
}


#define MMI_PHB_INTERFACE_FOR_VRSD_DIAL
#if defined(__MMI_FILE_MANAGER__)
#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
#ifdef __MMI_PHB_CALLER_GROUP__
static U8 g_mmi_phb_grp_id[MMI_PHB_GROUP_COUNT];
static U8 g_mmi_phb_grp_highlight_id;

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fmgr_pre_edit_callergrp
 * DESCRIPTION
 *  pre check for associate image to a existing phonebook caller group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_fmgr_pre_edit_callergrp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_group_info_struct group_info;
    mmi_phb_filemgr_caller_res_struct *res;
    S32 item_index = 0;
#if defined(__MMI_PHB_CALLER_VIDEO__)
    U8 video_audio = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&group_info, 0, sizeof(srv_phb_group_info_struct));  
    srv_phb_get_group_info(g_mmi_phb_grp_highlight_id, &group_info);

    res = (mmi_phb_filemgr_caller_res_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_RES);

    if (res->recv_res_from == MMI_PHB_RECV_RES_IMAGE
        || res->recv_res_from == MMI_PHB_RECV_RES_AVATAR_IMAGE)
    {
        mmi_phb_build_image_list();

        if (res->recv_res_from == MMI_PHB_RECV_RES_IMAGE)
        {
            item_index = g_mmi_phb_resource.total_image_id - 1;
        }
    
        group_info.image_id = g_mmi_phb_resource.image_id_list[item_index];
        group_info.res_type |= SRV_PHB_RES_TYPE_IMAGE_FILE;
        mmi_wcscpy(group_info.image_path, res->res_path);

        srv_phb_update_group_info(g_mmi_phb_grp_highlight_id, &group_info);
         
        mmi_phb_popup_display_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS);
    }
    /* audio setting */
    else if (res->recv_res_from == MMI_PHB_RECV_RES_AUDIO)
    {
        group_info.ringtone_id = res->recv_res_id;
        srv_phb_update_group_info(g_mmi_phb_grp_highlight_id, &group_info);

        mmi_phb_popup_display_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS);
    }
    /* video setting */
#if defined(__MMI_PHB_CALLER_VIDEO__)
    else if (res->recv_res_from == MMI_PHB_RECV_RES_VIDEO
             || res->recv_res_from == MMI_PHB_RECV_RES_AVATAR_VIDEO
             || res->recv_res_from == MMI_PHB_RECV_RES_SWFLASH)
    {
        mmi_phb_build_video_list();
        
        if (res->recv_res_from == MMI_PHB_RECV_RES_VIDEO)
        {
            item_index = g_mmi_phb_resource.total_video_id - 1;
            video_audio = 1; /* Turn on video's audio by default */
        }
	#if 0	
    #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SWFLASH__ */
	#endif
        group_info.video_id = g_mmi_phb_resource.video_id_list[item_index];
        group_info.res_type |= SRV_PHB_RES_TYPE_VIDEO_FILE;

        if (video_audio == 1)
        {
            group_info.video_id = group_info.video_id | 0x4000;
            group_info.res_type |= SRV_PHB_RES_TYPE_VIDEO_SOUND_ON;
        }
        mmi_wcscpy(group_info.video_path, res->res_path);
        srv_phb_update_group_info(g_mmi_phb_grp_highlight_id, &group_info);
        mmi_phb_popup_display_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS);
    }
#endif /* __MMI_PHB_CALLER_VIDEO__ */
    else
    {
        /* error handler */
        mmi_phb_popup_display_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE);
    }
    /* delete screen history */
    mmi_frm_scrn_close(GRP_ID_PHB_RES, SCR_CALLER_GROUPS);
}



static S32 mmi_phb_group_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Index used to fill menu data should be in range 0 to (data_size - 1) */
    for (index = 0; index < data_size; index++)
    {
        srv_phb_get_group_name(g_mmi_phb_grp_id[index + item_index], (U16*)menu_data[index].item_list[0], MAX_SUBMENU_CHARACTERS);

        menu_data[index].image_list[0] = get_image(gIndexIconsImageList[index + item_index]);
    }
    
    return data_size;
}


void mmi_phb_entry_group_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_mmi_phb_grp_highlight_id = g_mmi_phb_grp_id[index];
}


void mmi_phb_entry_callergroup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 num_of_grp;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }
    
    num_of_grp = srv_phb_get_group_list(g_mmi_phb_grp_id, NULL, PHB_STORAGE_NVRAM);

    if (num_of_grp == 0)
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_NO_GROUP,
            MMI_EVENT_FAILURE,
            GRP_ID_PHB_RES,
            NULL);
        mmi_frm_scrn_close(GRP_ID_PHB_RES, SCR_ID_PHB_FMGR_SAVE_OPTION);
        return;
    }

    if (mmi_frm_scrn_enter(
            GRP_ID_PHB_RES,
            SCR_CALLER_GROUPS,
            NULL,
            mmi_phb_entry_callergroup,
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        RegisterHighlightHandler(mmi_phb_entry_group_highlight_hdlr);

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        
        wgui_cat1032_show(
                (WCHAR*) GetString(STR_SCR_CALLER_GROUP_CAPTION),
                (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
                (WCHAR*) GetString(STR_GLOBAL_OK),
                (PU8) GetImage(IMG_GLOBAL_OK),
                (WCHAR*) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                num_of_grp,
                mmi_phb_group_get_item,
                NULL,
                0,
                0,    
                IMG_GLOBAL_L1,
                0,
                gui_buffer,
                NULL);

        SetLeftSoftkeyFunction(mmi_phb_fmgr_pre_edit_callergrp, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_fmgr_pre_edit_callergrp, KEY_EVENT_UP);

        mmi_frm_scrn_close(GRP_ID_PHB_RES, SCR_ID_PHB_FMGR_SAVE_OPTION);
    }
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


static void mmi_phb_caller_res_cb(S32 result, U16 store_index, void *user_data)
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
 *  mmi_phb_fmgr_pre_edit_entry
 * DESCRIPTION
 *  pre check for associate image to a existing phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_fmgr_pre_edit_entry(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct *info;    
    mmi_phb_filemgr_caller_res_struct *res;
    U16 *path;
    U16 res_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store_index >= MMI_PHB_PHONE_ENTRIES)    /* ERROR!, Record in NVRAM only */
    {
        MMI_ASSERT(0);
        return;
    }
    
    info = (srv_phb_contact_info_struct*) mmi_phb_mem_malloc(sizeof(srv_phb_contact_info_struct), SRV_PHB_MEMORY_TYPE_CTR);

    info->field_mask = 0;
    info->field_data.res_type = 0;

    path = (U16*) mmi_phb_mem_malloc(sizeof(U16) * (SRV_FMGR_PATH_MAX_LEN + 1), SRV_PHB_MEMORY_TYPE_CTR);
    
    res = (mmi_phb_filemgr_caller_res_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_RES);
    if (res->recv_res_from == MMI_PHB_RECV_RES_IMAGE)
    {
        mmi_phb_build_image_list();
        res_id = g_mmi_phb_resource.image_id_list[g_mmi_phb_resource.total_image_id - 1];
        mmi_wcscpy(path, res->res_path);

        info->field_data.image_id = res_id;
        info->field_data.res_type |= SRV_PHB_RES_TYPE_IMAGE_FILE;
        info->field_data.image_path = path;
        info->field_mask |= SRV_PHB_ENTRY_FIELD_PIC;
    }
    else if (res->recv_res_from == MMI_PHB_RECV_RES_AUDIO)
    {
        mmi_phb_build_ring_tone_list();
        info->field_data.ringtone_id = res->recv_res_id;        
        info->field_mask |= SRV_PHB_ENTRY_FIELD_RING;
    }
#if defined(__MMI_PHB_CALLER_VIDEO__)
    else if (res->recv_res_from == MMI_PHB_RECV_RES_VIDEO)
    {
        mmi_phb_build_video_list();
        res_id = g_mmi_phb_resource.video_id_list[g_mmi_phb_resource.total_video_id - 1];
        mmi_wcscpy(path, res->res_path);

        info->field_data.video_id = res_id | 0x4000;
        info->field_data.res_type |= SRV_PHB_RES_TYPE_VIDEO_FILE | SRV_PHB_RES_TYPE_VIDEO_SOUND_ON;
        info->field_data.video_path = path;
        info->field_mask |= SRV_PHB_ENTRY_FIELD_VIDEO;
    }
#if 0	
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SWFLASH__ */ 
#endif
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */ 

    srv_phb_oplib_update_contact(
        store_index,
        info,
        mmi_phb_caller_res_cb,
        NULL);

    mmi_phb_popup_display_ext(
        STR_GLOBAL_DONE,
        MMI_EVENT_SUCCESS);

    mmi_phb_mem_free(info);
    mmi_phb_mem_free(path);    
}


void mmi_phb_fmgr_edit_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    mmi_phb_filemgr_caller_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    res = (mmi_phb_filemgr_caller_res_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_RES);
    
    sg_id = cui_phb_list_select_contact_create(GRP_ID_PHB_RES);
    res->sg_id = sg_id;

    cui_phb_list_select_contact_set_storage(sg_id, PHB_STORAGE_NVRAM);

    cui_phb_list_select_contact_run(sg_id);
    
    mmi_frm_scrn_close(GRP_ID_PHB_RES, SCR_ID_PHB_FMGR_SAVE_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fmgr_pre_add_entry
 * DESCRIPTION
 *  pre check for associate image from file manager to a new phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_fmgr_pre_add_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    mmi_phb_filemgr_caller_res_struct *res;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }

    if (mmi_phb_check_storage_full(PHB_STORAGE_NVRAM, MMI_TRUE))
    {
        return;
    }

    res = (mmi_phb_filemgr_caller_res_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_RES);
    
    sg_id = cui_phb_save_contact_create(GRP_ID_PHB_RES);

    res->sg_id = sg_id;
    
    cui_phb_save_contact_set_res(
        sg_id,
        res->res_path,
        res->recv_res_id,
        res->recv_res_from);

    cui_phb_save_contact_set_storage(sg_id, PHB_STORAGE_NVRAM);
    
    cui_phb_save_contact_run(sg_id);
    
    mmi_frm_scrn_close(GRP_ID_PHB_RES, SCR_ID_PHB_FMGR_SAVE_OPTION);
}


mmi_ret mmi_phb_fmgr_edit_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
	mmi_ret result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            if (menu_evt->parent_menu_id == MENU_ID_PHB_FMGR_SAVE_OPTION)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_FMGR_SAVE_NEW)
            {
                mmi_phb_fmgr_pre_add_entry();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_FMGR_SAVE_LIST)
            {
                mmi_phb_fmgr_edit_contact();
            }
        #ifdef __MMI_PHB_CALLER_GROUP__
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_FMGR_SAVE_CALLGRP)
            {
                mmi_phb_entry_callergroup();
            }
        #endif /* __MMI_PHB_CALLER_GROUP__ */
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }
        
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        
        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_fmgr_save_option
 * DESCRIPTION
 *  Entry function for save image from file manager option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_fmgr_save_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_gid = cui_menu_create_and_run(
                   GRP_ID_PHB_RES,
                   CUI_MENU_SRC_TYPE_RESOURCE,
                   CUI_MENU_TYPE_OPTION,
                   MENU_ID_PHB_FMGR_SAVE_OPTION,
                   MMI_FALSE, NULL);

    cui_menu_set_currlist_left_softkey_by_id(menu_gid, STR_GLOBAL_SELECT);
    
}


#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fmgr_select_image_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fmgr_select_image_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_fmgr_save_option();
    
    mmi_frm_scrn_close(GRP_ID_PHB_RES, SCR_ID_PHB_IMAGE_VIEW_IMAGE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_preview_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fmgr_image_preview_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *error_str_ptr;
    mmi_phb_filemgr_caller_res_struct *res;
    mmi_id sg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0)
    {
        ChangeLeftSoftkey(0, 0);
        ChangeRightSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);

        sg_id = GRP_ID_PHB_RES;

        if (sg_id == GRP_ID_INVALID)
        {
            return;
        }
        
        res = (mmi_phb_filemgr_caller_res_struct*) mmi_frm_scrn_get_user_data(sg_id, SCR_ID_PHB_IMAGE_VIEW_IMAGE);
        
        if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_CALLER_PICTURE, (CHAR*)res->res_path, &error_str_ptr))
        {
            mmi_popup_display_simple(
                (UI_string_type) error_str_ptr,
                MMI_EVENT_FAILURE,
                sg_id,
                NULL);
        }
        else
        {
            mmi_popup_display_simple_ext(
                STR_GLOBAL_UNSUPPORTED_FORMAT,
                MMI_EVENT_FAILURE,
                sg_id,
                NULL);
        }

        mmi_frm_scrn_close(sg_id, SCR_ID_PHB_IMAGE_VIEW_IMAGE);
        SetLeftSoftkeyFunction(UI_dummy_function, KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fmgr_image_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fmgr_image_preview(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_filemgr_caller_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            scrn_data->group_id,
            SCR_ID_PHB_IMAGE_VIEW_IMAGE,
            NULL,
            (FunctionPtr)mmi_phb_fmgr_image_preview,
            MMI_FRM_FULL_SCRN))
    {
        res = (mmi_phb_filemgr_caller_res_struct*) scrn_data->user_data;
            
        /* entry cat222 to decode and display a image from file */
        wgui_cat222_disable_err_msg_display();

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory222Screen(
            STR_GLOBAL_VIEW,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            GDI_COLOR_BLACK,
            (CHAR*) NULL,
            (CHAR*) res->res_path,
            FALSE,
            mmi_phb_fmgr_image_preview_callback,
            GDI_IMAGE_SRC_FROM_FILE);

        SetLeftSoftkeyFunction(mmi_phb_fmgr_select_image_done, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_fmgr_select_image_done, KEY_EVENT_UP);
    }
}


#if defined(__MMI_IMAGE_CLIP_CUI__) && defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_use_as_clip_image
 * DESCRIPTION
 *  entry clip image cui from file manager which option is use as.
 * PARAMETERS
 *  file path and group id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_use_as_clip_image(WCHAR *path, mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL file_supported; 
	MMI_ID cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 	
	file_supported = cui_image_clip_is_file_format_supported(path);
	if(file_supported)
	{
		cui_gid = cui_image_clip_create(sg_id, path, NULL);
		cui_image_clip_set_dest_size(cui_gid, INLINE_FTE_CAPTION_THUMBNAIL_WIDTH, INLINE_FTE_CAPTION_THUMBNAIL_HEIGHT);
		cui_image_clip_run(cui_gid);
	} 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_clip_image_finish
 * DESCRIPTION
 *  copy image file path after clipper finish
 * PARAMETERS
 *  file path of image clipper
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_use_as_clip_image_finish(CHAR* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_filemgr_caller_res_struct *user_data = (mmi_phb_filemgr_caller_res_struct*)mmi_frm_group_get_user_data(GRP_ID_PHB_RES);
    MMI_ID menu_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_build_image_list();
    mmi_ucs2cpy((CHAR*)user_data->res_path, file_path);
    user_data->recv_res_from = MMI_PHB_RECV_RES_IMAGE;
    user_data->recv_res_id = mmi_phb_get_image_id((U8)(g_mmi_phb_resource.total_image_id - 1));
    
    menu_gid = cui_menu_create_and_run(
        GRP_ID_PHB_RES,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPSUB,
        MENU_ID_PHB_FMGR_SAVE_OPTION,
        MMI_FALSE, NULL); 

}
#endif
#endif


#if defined(__MMI_PHB_CALLER_VIDEO__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fmgr_select_video_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fmgr_select_video_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_fmgr_save_option();
    mmi_frm_scrn_close(GRP_ID_PHB_RES, SCR_ID_PHB_VIDEO_VIEW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fmgr_video_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fmgr_video_preview(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    MMI_BOOL is_play_audio = (MMI_BOOL)(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED);
    mmi_phb_filemgr_caller_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
    #if defined(__MMI_BACKGROUND_CALL__)
        if (mmi_frm_is_in_backward_scenario())
        {
            if (mmi_frm_scrn_enter(
                    scrn_data->group_id,
                    SCR_ID_PHB_VIDEO_VIEW,
                    NULL,
                    (FunctionPtr)mmi_phb_fmgr_video_preview,
                    MMI_FRM_FULL_SCRN))
            {
                gui_buffer = mmi_frm_scrn_get_active_gui_buf();
                
                ShowCategory141Screen(
                    STR_GLOBAL_PLAY,
                    GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    (U8*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL),
                    0,
                    gui_buffer);
                
            }
        }
        else
    #endif
        {
            mmi_frm_scrn_close(scrn_data->group_id, scrn_data->scrn_id);
            mmi_phb_ucm_app_entry_error_message();    
        }
    }

    else if (mmi_frm_scrn_enter(
            scrn_data->group_id,
            SCR_ID_PHB_VIDEO_VIEW,
            mmi_phb_video_exit_preview,
            (FunctionPtr)mmi_phb_fmgr_video_preview,
            MMI_FRM_FULL_SCRN))
    {
        mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        res = (mmi_phb_filemgr_caller_res_struct*) scrn_data->user_data;
	#if 0	
    #ifdef __MMI_SWFLASH__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SWFLASH__ */
	#endif
        {
        #ifdef __DRM_SUPPORT__
            S32 drm_video_flag = WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME | WGUI_CATVDO_DRM_DISABLE_CONSUME_COUNT | WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME_LIMIT_STOP;
            wgui_catvdo_set_drm_flag(drm_video_flag);
        #endif
            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

            ShowCategory225Screen(
                STR_GLOBAL_PLAY,         /* title_str */
                IMG_SCR_PBOOK_CAPTION,              /* title_icon */
                STR_GLOBAL_OK,                      /* lsk_str */
                IMG_GLOBAL_OK,                      /* lsk_icon */
                STR_GLOBAL_BACK,                    /* rsk_str */
                IMG_GLOBAL_BACK,                    /* rsk_icon */
                0,                                  /* video_id */
                (CHAR*) res->res_path,        /* video_filename */
                1,                                  /* repeat_count */
                TRUE,                               /* is_visual_update */
                is_play_audio,   /* is_play_audio */
                TRUE,                               /* is_lcd_no_sleep */
                GDI_COLOR_WHITE,                    /* bg_color */
                mmi_phb_video_view_callback,
                gui_buffer);
        
            SetLeftSoftkeyFunction(mmi_phb_fmgr_select_video_done, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_phb_fmgr_select_video_done, KEY_EVENT_UP);
        }
    }
}
#endif /* __MMI_PHB_CALLER_VIDEO__ */


#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
static mmi_ret mmi_phb_fmgr_res_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_filemgr_caller_res_struct *res;
    mmi_ret menu_cui_proc;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = (mmi_phb_filemgr_caller_res_struct *) evt->user_data;

    menu_cui_proc = mmi_phb_fmgr_edit_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }
    
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_INACTIVE:
        {
            if (mmi_frm_scrn_get_count(res->sg_id) == 0)
            {
                mmi_frm_group_close(res->sg_id);
            }
            break;
        }

        case EVT_ID_GROUP_DEINIT:
            if (res)
            {
                mmi_phb_mem_free(res);
                res = NULL;
            }
            break;
            
        case EVT_ID_PHB_SELECT_CONTACT:
            mmi_phb_fmgr_pre_edit_entry(((cui_phb_select_contact_result_struct*) evt)->store_index);
            cui_phb_list_select_contact_close(res->sg_id);
            break;
            
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            cui_phb_list_select_contact_close(res->sg_id);
            break;
            
        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
            cui_phb_save_contact_close(res->sg_id);
            break;

    #if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__) && defined(__MMI_IMAGE_CLIP_CUI__)
		case EVT_ID_CUI_IMAGE_CLIP_CLOSE_REQUEST:
		{
			cui_image_clip_close(((cui_image_clip_evt_struct*)evt)->sender_id);
			break;
		}

		case EVT_ID_CUI_IMAGE_CLIP_RESULT_SUCCESS:
		{
			cui_image_clip_evt_struct *clip_result = (cui_image_clip_evt_struct*)evt;
			mmi_phb_use_as_clip_image_finish((CHAR*)clip_result->save_file_path);
			break;
		}
	#endif
        
        default:
            break;
    }
 
    return MMI_RET_OK;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fmgr_from_file_mgr
 * DESCRIPTION
 *  forward function for file manager application
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_fmgr_from_file_mgr(CHAR *path)
{
#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_filemgr_caller_res_struct *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }
    if (path == NULL)
    {
        mmi_phb_popup_display_ext(
            STR_ID_PHB_FMGR_IMAGE_NO_SELECT,
            MMI_EVENT_FAILURE);
        return;
    }

    user_data = (mmi_phb_filemgr_caller_res_struct *) mmi_phb_mem_malloc(sizeof(mmi_phb_filemgr_caller_res_struct), SRV_PHB_MEMORY_TYPE_ADM);
    user_data->sg_id = GRP_ID_PHB_RES;
    
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_PHB_RES,
        mmi_phb_fmgr_res_proc,
        user_data,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

#if defined(__MMI_IMAGE_CLIP_CUI__) && defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
    if (srv_fmgr_types_find_group_by_filename_str((WCHAR*) path) == FMGR_GROUP_IMAGE)
    {  
        mmi_phb_use_as_clip_image((WCHAR*)path, GRP_ID_PHB_RES);
        return;
    }
#endif
        
#if defined(__MMI_PHB_CALLER_VIDEO__)
    if (srv_fmgr_types_find_group_by_filename_str((WCHAR*) path) == FMGR_GROUP_VIDEO)
    {
        if (mmi_phb_video_check_data_space(path))
        {
            mmi_phb_build_video_list();
            mmi_ucs2cpy((CHAR*)user_data->res_path, path);
            user_data->recv_res_from = MMI_PHB_RECV_RES_VIDEO;
            user_data->recv_res_id = mmi_phb_get_video_id((U8) (g_mmi_phb_resource.total_video_id - 1));
            user_data->recv_res_id |= 0x4000;

            mmi_frm_scrn_first_enter(
                GRP_ID_PHB_RES,
                SCR_ID_PHB_VIDEO_VIEW,
                (FunctionPtr)mmi_phb_fmgr_video_preview,
                user_data);            
        }
    }
    /* Check image content */
    else if (mmi_phb_image_check_valid_image(path, MMI_FALSE))
#else /* defined(__MMI_PHB_CALLER_VIDEO__) */ 

    /* Check image content */
    if (mmi_phb_image_check_valid_image(path, MMI_FALSE))
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */ 
    {
        mmi_phb_build_image_list();
        mmi_ucs2cpy((CHAR *) user_data->res_path, path);
        user_data->recv_res_from = MMI_PHB_RECV_RES_IMAGE;
        user_data->recv_res_id = mmi_phb_get_image_id((U8) (g_mmi_phb_resource.total_image_id - 1));
    
        mmi_frm_scrn_first_enter(
            GRP_ID_PHB_RES,
            SCR_ID_PHB_IMAGE_VIEW_IMAGE,
            (FunctionPtr)mmi_phb_fmgr_image_preview,
            user_data);
    }
#endif
}


void mmi_phb_res_use_as_enabler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Disable in 1 case: 1. file is EMS/ANM */
#ifdef __MMI_MESSAGES_EMS__
    if (fileinfo->type == FMGR_TYPE_EMS ||
        fileinfo->type == FMGR_TYPE_ANM)
    {
        mmi_frm_hide_menu_item(item_id);
        return;
    }
#endif

#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    if(fileinfo->type == FMGR_TYPE_MAV)
    {
        mmi_frm_hide_menu_item(item_id);
        return;
    }
#endif

#ifndef SVG12_SUPPORT
    if (fileinfo->type == FMGR_TYPE_SVG)
    {
        mmi_frm_hide_menu_item(item_id);
        return;
    }
#endif
}


void mmi_phb_res_use_as_handler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_fmgr_from_file_mgr((CHAR*)filepath);
    mmi_fmgr_close_option_screen();
}

#endif /* defined(__MMI_FILE_MANAGER__) */ 

#endif /* __MMI_PHB_CALLER_RES__ */

