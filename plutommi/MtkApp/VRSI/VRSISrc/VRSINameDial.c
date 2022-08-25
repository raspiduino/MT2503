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
 * VRSINameDial.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is the name dial function of VRSI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef _MMI_VRSINAMEDIAL_C
#define _MMI_VRSINAMEDIAL_C

#include "MMIDataType.h"
#if defined(__MMI_VRSI__)
/*  Include: MMI header file */
#include "CommonScreens.h"
#include "ProtocolEvents.h"
/* ... Add More MMI header */

#include "med_main.h"
#include "med_api.h"
#include "mdi_audio.h"
#include "VRSIType.h"
#include "VRSIProt.h"

#include "PhoneBookGprot.h"
#include "PhbSrvGprot.h"
#include "PhbCuiGprot.h"


#include "UCMGProt.h"
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif  /*__MMI_DUAL_SIM_MASTER__*/

#ifdef __SYNCML_SUPPORT__
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */

#include "menucuigprot.h"
/*  Include: PS header file */
/* ... Add More PS header */
#include "mmi_rp_srv_vrsi_def.h"

#include "MMIDataType.h"
#include "custom_phb_config.h"
#include "smu_common_enums.h"
#include "kal_general_types.h"
#include "string.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "GeneralDeviceGprot.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_list.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "wgui_categories_popup.h"
#include "ps_public_enum.h"
/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
U16 vrsi_phb_entry_cnt;
U16 vrsi_phb_index[MMI_PHB_ENTRIES];
S32 vrsi_phb_tag_index[MMI_PHB_ENTRIES];

U16 *vrsi_dial_name_index[MMI_VRSI_MAX_ADD_ENTRY];
#if defined(__MTK_TARGET__)
__align(4)
#endif 
U16 vrsi_dial_name[MMI_VRSI_MAX_ADD_ENTRY][MMI_PHB_NAME_LENGTH];


/* 
 * Global Function
 */
#ifdef __GEMINI__
extern smu_sim_status_enum check_sim_status(kal_uint8 simInterface);
#else
extern smu_sim_status_enum check_sim_status(void);
#endif
extern mmi_ret mmi_vrsi_settings_event_proc(mmi_event_struct *evt);
#define MMI_VRSI_NDIAL_CENTRAL
#define MMI_VRSI_PHB_OPT_NUM_COUNT 3


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_phb_ready
 * DESCRIPTION
 *  Check if phonebook ready to add..
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_vrsi_ndial_central_phb_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    return mmi_phb_check_ready(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_add_all
 * DESCRIPTION
 *  This function add all dynamic central command for name dial.
 * PARAMETERS
 *  msg     [IN]        protocol handler callback message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_add_all(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, tag_num, add_count;
    U8 is_name_list[MMI_VRSI_MAX_ADD_ENTRY];
    U16 id_list[MMI_VRSI_MAX_ADD_ENTRY];
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Abort while adding central command. Will close engine in abort function, so return directly. */
    if (g_vrsi_cntx.vrsi_state != MMI_VRSI_STATE_ADDING_CMD)
    {
        return;
    }
	
	if (!mmi_phb_check_ready(MMI_TRUE))
	{        
        g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_CMD_NOT_READY;
        mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
        mdi_audio_vrsi_close();
        return;
    }
	
    add_count = g_vrsi_cntx.central_count;
	for (i = 0; i < MMI_VRSI_MAX_ADD_ENTRY; i++)
	{
		vrsi_dial_name_index[i] = (U16 *)&vrsi_dial_name[i][0];
	}
	memset((S8 *)vrsi_dial_name, 0, MMI_PHB_NAME_LENGTH * MMI_VRSI_MAX_ADD_ENTRY * 2);
	memset((S8 *)is_name_list, 0, MMI_VRSI_MAX_ADD_ENTRY);
	
    if (add_count < vrsi_phb_entry_cnt)
    {
        tag_num =
            ((vrsi_phb_entry_cnt - add_count) <
             MMI_VRSI_MAX_ADD_ENTRY) ? (vrsi_phb_entry_cnt - add_count) : MMI_VRSI_MAX_ADD_ENTRY;

        for (i = 0; i < tag_num; i++)
        {
        	ret = srv_phb_get_name(vrsi_phb_index[i + add_count], 
        							(U16 *)&vrsi_dial_name[i], MMI_PHB_NAME_LENGTH - 1);
        	if (ret < 0) 
        	{
        		break;
        	}
            is_name_list[i] = TRUE;
        }

        /* Get session id for each add operation */
        g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

        /* Add SI tags */
        media_aud_vrsi_add_tags(
            MOD_MMI,
            g_vrsi_cntx.session_id,
            (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
            tag_num,
            (U16 **)&vrsi_dial_name_index,
            (S32 *)&vrsi_phb_tag_index[add_count],
            is_name_list,
            id_list);

        add_count += tag_num;

        /* Print add fail messages. */
        mmi_vrsi_init_central_count_fail(tag_num, id_list, (S32 *)&vrsi_phb_tag_index[add_count]);
    }

    g_vrsi_cntx.central_count = add_count;

    /* More central command to add */
    if (add_count < vrsi_phb_entry_cnt)
    {
        mmi_vrsi_init_central_add_req();
    }
    else
    {
        mmi_vrsi_ndial_central_add_done();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_add_done
 * DESCRIPTION
 *  This function clear flag and add central command for next application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_add_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.central_count = 0;
    SetProtocolEventHandler(mmi_vrsi_scut_central_add_all, PRT_MMI_VRSI_ADD_CENTRAL_REQ);
    mmi_vrsi_init_central_add_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_add_single
 * DESCRIPTION
 *  This function add single dynamic central command for name dial.
 * PARAMETERS
 *  store_index     [IN]        index for command
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_add_single(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *name_list[1];
    S32 long_list[1];
    U8 is_name_list[1];
    U16 id_list[1];
    U16 name_buf[MMI_PHB_NAME_LENGTH];
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_vrsi_ndial_central_check_state_and_start())
    {
        return;
    }
	ret = srv_phb_get_name(store_index, name_buf, MMI_PHB_NAME_LENGTH - 1);
	if (ret < 0)
	{
		return;
	}
	
    name_list[0] = name_buf;
    long_list[0] = store_index;
    is_name_list[0] = TRUE;

    /* Get session id for each add operation */
    g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

    media_aud_vrsi_add_tags(
        MOD_MMI,
        g_vrsi_cntx.session_id,
        (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
        1,
        name_list,
        long_list,
        is_name_list,
        id_list);

    mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
    mdi_audio_vrsi_close();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_delete_single
 * DESCRIPTION
 *  This function delete single dynamic central command for name dial.
 * PARAMETERS
 *  store_index     [IN]        index for command
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_delete_single(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id[10]; /* delete at most 10 tags at one time, but there should be at most 2 tags (SI+SD) for one entry */
    S32 result;
    U16 tag_num = 0;
    kal_bool get_all;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete SD tag mapping table in NVRAM */
#if defined(__MMI_VRSI_TRAIN_TAG__)
    mmi_vrsi_train_util_del_tag(MMI_VRSI_APP_DIAL, store_index);
#endif 

    if (!mmi_vrsi_ndial_central_check_state_and_start())
    {
        return;
    }

    result = media_aud_vrsi_query_all_tag_ids(
                (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
                store_index,
                10,
                tag_id,
                &tag_num,
                &get_all);

    if (result != MED_RES_VRSI_OK)
    {
        mdi_audio_vrsi_close();
        return;
    }

    if (tag_num > 0)
    {
        media_aud_vrsi_del_tags(MOD_MMI, (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1], tag_num, tag_id);
    }

    mdi_audio_vrsi_close();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_change_single
 * DESCRIPTION
 *  This function change single dynamic central command for name dial.
 * PARAMETERS
 *  store_index     [IN]        index for command
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_change_single(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id[10]; /* delete at most 10 tags at one time, but there should be at most 2 tags (SI+SD) for one entry */
    S32 result;
    U16 tag_num = 0;
    kal_bool get_all;
    U16 *name_list[1];
    S32 long_list[1];
    U8 is_name_list[1];
    U16 name_buf[MMI_PHB_NAME_LENGTH];
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_vrsi_ndial_central_check_state_and_start())
    {
        return;
    }

    result = media_aud_vrsi_query_all_tag_ids(
                (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
                store_index,
                10,
                tag_id,
                &tag_num,
                &get_all);

    /* Delete SI tag but Keep SD tag */
    if ((result == MED_RES_VRSI_OK) && (tag_num > 0))
    {
        /* Remove SD tag from list before deleting */
    #if defined(__MMI_VRSI_TRAIN_TAG__)
        U16 sd_tag_id;
        U16 i, j;

        mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_DIAL, store_index, &sd_tag_id);

        for (i = 0; i < tag_num; i++)
        {
            if (tag_id[i] == sd_tag_id)
            {
                for (j = i; j < tag_num; j++)
                {
                    tag_id[j] = tag_id[j + 1];
                }
                tag_num--;
            }
        }
    #endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

        /* Delete SI tags */
        if (tag_num > 0)
        {
            media_aud_vrsi_del_tags(MOD_MMI, (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1], tag_num, tag_id);
        }
    }
    
	ret = srv_phb_get_name(store_index, name_buf, MMI_PHB_NAME_LENGTH - 1);
	if (ret < 0)
	{
		return;
	}

    /* Add SI tag back */
    name_list[0] = (U16*)name_buf;
    long_list[0] = store_index;
    is_name_list[0] = TRUE;

    /* Get session id for add operation */
    g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();
    media_aud_vrsi_add_tags(
        MOD_MMI,
        g_vrsi_cntx.session_id,
        (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
        1,
        name_list,
        long_list,
        is_name_list,
        tag_id);

    mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
    mdi_audio_vrsi_close();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_check_state_and_start
 * DESCRIPTION
 *  This function check VRSI engine state before add/delete/change.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_vrsi_ndial_central_check_state_and_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not initialized, wait for vrsi to add all central command. */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_CMD_NOT_READY)
    {
        return FALSE;
    }
    /*
     * Initializing, or Pause by other application ,
     * abort initial procedure and re-all all central command later.
     */
    else if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_ADDING_CMD ||
             g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_ADDING_PAUSE)
    {
        mmi_vrsi_init_central_abort();
        /* mmi_vrsi_init_central_add_all(); */
        return FALSE;
    }

    /* Should be in idle state here. init SI engine to add command */
    result = mdi_audio_vrsi_init(0, mmi_vrsi_mdi_callback_hdlr, NULL);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_VRSI_FUNC_MDI_INIT_RESULT, result);

    if (result != MED_RES_OK)
    {
        return FALSE;
    }

    return TRUE;
}

mmi_ret mmi_vrsi_phb_evt_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct* evt = (srv_phb_op_evt_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_PHB_ADD_CONTACT:
            mmi_vrsi_ndial_central_add_single(evt->store_index);
            break;
        case EVT_ID_PHB_DEL_CONTACT:
            mmi_vrsi_ndial_central_delete_single(evt->store_index);
            break;
        case EVT_ID_PHB_UPD_CONTACT:
            mmi_vrsi_ndial_central_change_single(evt->store_index);
            break;
        default: 
            break;
    }
    return MMI_RET_OK;  
}


#if defined(__MMI_VRSI_TRAIN_TAG__)


static mmi_ret mmi_vrsi_ndial_central_delete_sd_tag_in_sim_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, " [VR] mmi_vrsi_ndial_central_delete_sd_tag_in_sim_callback result = %d",evt->result);
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_OK:
            case MMI_ALERT_CNFM_YES:
                mmi_vrsi_ndial_central_delete_sd_tag_in_sim();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_vrsi_ndial_central_add_after_check();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_check_sim_change
 * DESCRIPTION
 *  This function check SIM change while enter idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_vrsi_ndial_central_check_sim_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.sdtag_sync == 0)    /* Not confirm yet. */
    {
    #ifdef __GEMINI__
        if (check_sim_status(0)== SMU_SIM_REPLACED || check_sim_status(1)== SMU_SIM_REPLACED)
    #else
        if (check_sim_status()== SMU_SIM_REPLACED)
    #endif
        {
            if (mmi_vrsi_ndial_central_count_tag_in_sim() > 0)
            {
                
                mmi_confirm_property_struct property;                
                mmi_confirm_property_init(&property, CNFM_TYPE_YESNO);
                property.parent_id = GRP_ID_VRSI;
                property.callback = mmi_vrsi_ndial_central_delete_sd_tag_in_sim_callback;
                mmi_confirm_display((UI_string_type)GetString(STR_ID_VRSI_REFRESH_SIM), MMI_EVENT_QUERY, &property);


                return TRUE;
            }
        }
    }

    g_vrsi_cntx.sdtag_sync = 1;
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_count_tag_in_sim
 * DESCRIPTION
 *  This function get the SD tags associate to SIM card.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_vrsi_ndial_central_count_tag_in_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if ((tag_list[i].app_id == MMI_VRSI_APP_DIAL) &&
            (tag_list[i].tag_long >= MMI_PHB_PHONE_ENTRIES) && (tag_list[i].tag_long < MMI_PHB_ENTRIES))
        {
            count++;
        }
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_delete_sd_tag_in_sim
 * DESCRIPTION
 *  This function delete all SD tags associate to SIM card
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_delete_sd_tag_in_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i, tag_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read out mapping table and build ID list */
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if ((tag_list[i].app_id == MMI_VRSI_APP_DIAL) && (tag_list[i].tag_long >= MMI_PHB_PHONE_ENTRIES) &&
            (tag_list[i].tag_long <= MMI_PHB_ENTRIES))
        {
            memset(&tag_list[i], 0xff, sizeof(vrsi_sd_tag_struct));
            tag_num++;
        }
    }

    /* delete mapping table only, the tag in engine will be deleted later when sync with engine */
    if (tag_num > 0)
    {
        /* Delete mapping in NVRAM */
        WriteRecord(
            NVRAM_EF_VRSI_TAG_LID,
            1,
            (void*)tag_list,
            MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct),
            &pError);
    }

    /* Continue to add all central command */
    mmi_vrsi_ndial_central_add_after_check();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_add_after_check
 * DESCRIPTION
 *  This function add central command after SIM change check.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_add_after_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.sdtag_sync = 1;

   mmi_frm_scrn_close_active_id();
    mmi_vrsi_init_central_add_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_update_sd_mapping
 * DESCRIPTION
 *  This function update NVRAM mapping table according to phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_update_sd_mapping(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i;
    U8 has_mapping = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if (tag_list[i].app_id == MMI_VRSI_APP_DIAL)
        {
            if (!srv_phb_check_entry_exist(tag_list[i].tag_long))
            {
                memset(&tag_list[i], 0xff, sizeof(vrsi_sd_tag_struct));
                has_mapping = 1;
            }
        }
    }

    if (has_mapping)
    {
        WriteRecord(
            NVRAM_EF_VRSI_TAG_LID,
            1,
            (void*)tag_list,
            MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct),
            &pError);
    }

}
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

#define MMI_VRSI_NDIAL_COMMON


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_get_index
 * DESCRIPTION
 *  This function get the current highlight index
 * PARAMETERS
 *  nIndex      [IN]        current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_get_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.active_index = (U16) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_rcg_grammar1_result
 * DESCRIPTION
 *  This function handle the recognition result for grammar 1 in name dial scenario
 * PARAMETERS
 *  tag_num         [IN]        result tag number
 *  long_list       [IN]        result index list
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_rcg_grammar1_result(U16 tag_num, S32 *long_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Single Record */
    if (tag_num == 1)
    {
        store_index = (U16) long_list[0];
        g_vrsi_cntx.long_list[0] = store_index;

        /* Not a phonebook entry */
        if ((store_index >= MMI_PHB_ENTRIES) || !srv_phb_check_entry_exist(store_index))
        {
            /* Play prompt TTS for not found */
            mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_RCG_NOT_FOUND), mmi_vrsi_entry_rcg);
            return;
        }

        /* Post Command Selected */
        if (g_vrsi_cntx.post_cmd != 0)
        {
            mmi_vrsi_ndial_pre_confirm_dial(g_vrsi_cntx.post_cmd);
        }
        else    /* Multiple Number */
        {
            g_vrsi_cntx.retry = 0;
            g_vrsi_cntx.active_index = 0;
            mmi_vrsi_entry_ndial_multiple_number();
        }
    }
    /* Multiple Record */
    else if (tag_num > 1)
    {
        g_vrsi_cntx.long_list_num = (tag_num < MMI_VRSI_MAX_RCG_RESULT) ? tag_num : MMI_VRSI_MAX_RCG_RESULT;

        for (i = 0; (i < g_vrsi_cntx.long_list_num) && (i < MMI_VRSI_MAX_RCG_RESULT); i++)
        {
            g_vrsi_cntx.long_list[i] = (U16) long_list[i];
        }

        g_vrsi_cntx.retry = 0;
        g_vrsi_cntx.active_index = 0;
        mmi_vrsi_entry_ndial_multiple_record();
    }
    else
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_rcg_grammar1_result_check
 * DESCRIPTION
 *  This function check the recognition result for grammar 1 in name dial scenario
 * PARAMETERS
 *  tag_num         [IN]        result tag number
 *  long_list       [IN]        result index list
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_vrsi_ndial_rcg_grammar1_result_check(U16 tag_num, S32 *long_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U16 *index_list;
    U16 pos, temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index_list = OslMalloc(sizeof(U16) * tag_num);
    memset(index_list, 0xff, sizeof(U16) * tag_num);

    /* Build phonebook sorting index list */
    for (i = 0; i < tag_num; i++)
    {
        for (j = 0; j < vrsi_phb_entry_cnt; j++)
        {
            if (vrsi_phb_index[j] == long_list[i])
            {
                index_list[i] = j;
                break;
            }
        }
    }

    /* Sort result */
    pos = 0;
    while (pos < tag_num)
    {
        for (i = (pos + 1); i < tag_num; i++)
            if (index_list[pos] > index_list[i])
            {
                temp = index_list[pos];
                index_list[pos] = index_list[i];
                index_list[i] = temp;
            }
        pos++;
    }

    /* Count and assign valid item */
    temp = 0;
    for (i = 0; i < tag_num; i++)
        if (index_list[i] != 0xffff)
        {
            long_list[i] = vrsi_phb_index[index_list[i]];
            temp++;
        }

    OslMfree(index_list);
    return temp;
}

#define MMI_VRSI_NDIAL_MULTIPLE_NUMBER


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_multiple_number
 * DESCRIPTION
 *  Entry multiple number screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_multiple_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_prompt[(MMI_PHB_NAME_LENGTH + 60)];
    U8 loc_count;
    U16 name_buf[MMI_PHB_NAME_LENGTH];
    S32 ret;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	ret = srv_phb_get_name(g_vrsi_cntx.long_list[0], name_buf, MMI_PHB_NAME_LENGTH - 1);
	if (ret < 0)
	{
		return;
	}

    mmi_ucs2cpy((S8*)str_prompt, (S8*)name_buf);
    loc_count = mmi_vrsi_ndial_multiple_number_show_data((S8*)str_prompt);

    if (!loc_count)
    {
        mmi_vrsi_ndial_no_number_prompt();
        return;
    }
    else if (loc_count == 1)
    {
        g_vrsi_cntx.retry = 0;
        mmi_vrsi_entry_ndial_confirm_dial();
        return;
    }

    TurnOnBacklight(1);
    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI, 
       SCR_ID_VRSI_NAME_DIAL_MULTI_NUM, 
       mmi_vrsi_exit_ndial_multiple_number, 
       mmi_vrsi_entry_ndial_multiple_number, 
       MMI_FRM_FG_ONLY_SCRN);
    if (!entry_ret)
    {
        return;
    } 

    RegisterHighlightHandler(mmi_vrsi_entry_ndial_get_index);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        EnableCenterSoftkey( 0, IMG_GLOBAL_COMMON_CSK);
    }
    ShowCategory53Screen(
        STR_ID_VRSI_APP,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        STR_GLOBAL_DIAL,
        0,
        STR_GLOBAL_CANCEL,
        0,
        loc_count,
        subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        hintDataPtrs,
        0,
        g_vrsi_cntx.active_index,
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_multiple_number_pre_confirm, KEY_EVENT_UP);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        ChangeCenterSoftkey( 0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction( mmi_vrsi_ndial_multiple_number_pre_confirm, KEY_EVENT_UP);
    }
    SetKeyHandler(mmi_vrsi_ndial_multiple_number_pre_confirm, KEY_SEND, KEY_EVENT_UP);

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_2;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_NAME_DIAL;

    mmi_vrsi_ndial_multiple_number_prompt((S8*)str_prompt);

    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_ndial_multiple_number
 * DESCRIPTION
 *  Exit multiple number screen. Close engine if next screen is not in scenario.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_ndial_multiple_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scr_id;
    MMI_ID group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_get_active_scrn_id(&group_id, &scr_id);
    if ((scr_id == SCR_ID_VRSI_RCG_MAIN) ||
        (scr_id == SCR_ID_VRSI_NAME_DIAL_MULTI_NUM) || (scr_id == SCR_ID_VRSI_NAME_DIAL_CONFIRM))
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_multiple_number_in_history
 * DESCRIPTION
 *  Entry multiple number screen after retry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_multiple_number_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_prompt[(MMI_PHB_NAME_LENGTH + 60)];
    U8 loc_count;
    U16 name_buf[MMI_PHB_NAME_LENGTH];
    S32 ret;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	ret = srv_phb_get_name(g_vrsi_cntx.long_list[0], name_buf, MMI_PHB_NAME_LENGTH - 1);
	if (ret < 0)
	{
		return;
	}

    mmi_ucs2cpy((S8*)str_prompt, (S8*) name_buf);
    loc_count = mmi_vrsi_ndial_multiple_number_show_data((S8*)str_prompt);

    TurnOnBacklight(1);
    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI_RCG_MAIN, 
       SCR_ID_VRSI_NAME_DIAL_MULTI_NUM_IN_HISTORY, 
       NULL, 
       mmi_vrsi_entry_ndial_multiple_number_in_history, 
       MMI_FRM_FG_ONLY_SCRN);
    if (!entry_ret)
    {
        return;
    } 

    RegisterHighlightHandler(mmi_vrsi_entry_ndial_get_index);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    ShowCategory53Screen(
        STR_ID_VRSI_APP,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        STR_GLOBAL_DIAL,
        0,
        STR_GLOBAL_CANCEL,
        0,
        loc_count,
        subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        hintDataPtrs,
        0,
        g_vrsi_cntx.active_index,
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_multiple_number_pre_confirm, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsi_ndial_multiple_number_pre_confirm, KEY_SEND, KEY_EVENT_UP);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction( mmi_vrsi_ndial_multiple_number_pre_confirm, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_number_pre_confirm
 * DESCRIPTION
 *  Pre comfirm for select one of multilple number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_number_pre_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 store_index;
    U16 i = 0;
    U16 j = 0;    
    MMI_ID scr_id;
    MMI_ID group_id;
    MMI_BOOL ret;
    mmi_phb_num_type_enum  type[MMI_VRSI_PHB_OPT_NUM_COUNT];
    U8 order[MMI_VRSI_PHB_OPT_NUM_COUNT];
    U8 loc_count = 1;
    U8 mobile_count = 1;
    U8 home_count = 0;
    U8 office_count = 0;
    U8 fax_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];
    /* Get post command */
    //to do:
    if (g_vrsi_cntx.loc_num[0] && (g_vrsi_cntx.active_index == i++))
    {
        g_vrsi_cntx.post_cmd = VRSI_CMD2_MOBILE;
    }
    else
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        srv_phb_get_optional_number_order(store_index, order);

        for(i = 0; i < MMI_VRSI_PHB_OPT_NUM_COUNT; i++)
        {
            U16 number_buff[(MMI_PHB_NUMBER_LENGTH + 1) * ENCODING_LENGTH];
            ret = srv_phb_get_optional_number(store_index, (U32)(order[i]), number_buff, &type[i], MMI_PHB_NUMBER_LENGTH);
            if(ret)
            {
                if(mmi_ucs2strlen((S8*)number_buff))
                {
                     loc_count++;
                }
                else
                {
                    break;
                }
            }
        }
        for(j = 0; j < (loc_count - 1); j++)
        {
            switch(type[j])
            {
                case MMI_PHB_NUM_TYPE_MOBILE:
                    mobile_count++;
                    break;
                case MMI_PHB_NUM_TYPE_HOME:
                    home_count++;
                    break;
                case MMI_PHB_NUM_TYPE_OFFICE:
                    office_count++;
                    break;
                case MMI_PHB_NUM_TYPE_FAX:
                    fax_count++;
                    break;
                default:
                    break;                            
            }
            if(j == g_vrsi_cntx.active_index)
            {
                break;                                       
            }
        }
        switch(type[g_vrsi_cntx.active_index])
        {
            case MMI_PHB_NUM_TYPE_MOBILE:
                if(mobile_count == 1)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_MOBILE;
                }
                else if(mobile_count == 2)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_MOBILE2;
                }
                else if(mobile_count == 3)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_MOBILE3;
                }
                else if(mobile_count == 4)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_MOBILE4;
                }
                break;
            case MMI_PHB_NUM_TYPE_HOME:
                if(home_count == 1)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_HOME;
                }
                else if(home_count == 2)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_HOME2;
                }
                else if(home_count == 3)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_HOME3;
                }
                break;
            case MMI_PHB_NUM_TYPE_OFFICE:                            
                if(office_count == 1)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_BUSINESS;
                }
                else if(office_count == 2)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_BUSINESS2;
                }
                else if(office_count == 3)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_BUSINESS3;
                }
                break;
            case MMI_PHB_NUM_TYPE_FAX:
                if(fax_count == 1)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_FAX;
                 }
                else if(fax_count == 2)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_FAX2;
                }
                else if(fax_count == 3)
                {
                    g_vrsi_cntx.post_cmd = VRSI_CMD2_FAX3;
                }
                break;
            default:
                break;                            
        }
        #endif
    }
    /* Enter screen from screen not in VR session, so init engine again. */
   mmi_frm_get_active_scrn_id(&group_id, &scr_id);
    if (scr_id == SCR_ID_VRSI_NAME_DIAL_MULTI_NUM_IN_HISTORY)
    {
        mmi_vrsi_rcg_init(NULL);
    }
    else
    {
        mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
    }

    g_vrsi_cntx.retry = 0;
    mmi_vrsi_entry_ndial_confirm_dial();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_number_show_data
 * DESCRIPTION
 *  Prompt string for multiple number
 * PARAMETERS
 *  str_prompt      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vrsi_ndial_multiple_number_show_data(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    U16 len = MMI_PHB_NUMBER_LENGTH;
    U8 loc_count = 0;
    U8 post_cmd = VRSI_CMD2_NONE;
    MMI_BOOL ret;
    mmi_phb_num_type_enum type[MMI_VRSI_PHB_OPT_NUM_COUNT];
    U8 number_order[MMI_VRSI_PHB_OPT_NUM_COUNT];
    U8 mobile_count = 1;
    U8 home_count = 0;
    U8 office_count = 0;
    U8 fax_count = 0;
    U8 i, j;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vrsi_cntx.loc_num, 0, 4);

    store_index = g_vrsi_cntx.long_list[0];
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT));

    ret = srv_phb_get_number(store_index, (U16 *)hintData[loc_count], len);
    if (ret && mmi_ucs2strlen((S8*)hintData[loc_count]))
    {
        g_vrsi_cntx.loc_num[0] = 1;

        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE));
        mmi_ucs2ncpy(
            (S8*) subMenuData[loc_count],
            GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE),
            MAX_SUBMENU_CHARACTERS);	
        loc_count++;
        post_cmd = VRSI_CMD2_MOBILE;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    ret = srv_phb_get_optional_number_order(store_index,number_order);
    for(i = 0; i < MMI_VRSI_PHB_OPT_NUM_COUNT; i++)
    {
        ret = srv_phb_get_optional_number(store_index, (U32)(number_order[i]),(U16 *)hintData[loc_count], &type[i], len);
	if (ret)
	{
            if(mmi_ucs2strlen((S8*)hintData[loc_count]))
            {
                g_vrsi_cntx.loc_num[i+1] = 1;
		loc_count++;
            }
            else
	    {
                break;
            }
        }
    }

    
    for(i = 1; i < loc_count; i++)
    {
        U16 string_id = 0;
        U16 tts_string = 0;
        switch(type[i-1])
        {
            case MMI_PHB_NUM_TYPE_MOBILE:
                if(mobile_count == 1)
                {
                    tts_string = STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE2;
                    string_id = STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE;
                    post_cmd = VRSI_CMD2_MOBILE2;                    
                    mobile_count++;
                }
                else if(mobile_count == 2)
                {
                    tts_string = STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE3;
                    string_id = STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE;
                    post_cmd = VRSI_CMD2_MOBILE3;
                    mobile_count++;
                }
                else if(mobile_count == 3)
                {
                    tts_string = STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE4;
                    string_id = STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE;
                    post_cmd = VRSI_CMD2_MOBILE4;
                    mobile_count++;
                }
                break;
                
            case MMI_PHB_NUM_TYPE_HOME:
                if(home_count == 0)
                {
                    tts_string = STR_ID_VRSI_GRAMMAR2_PROMPT_HOME;
                    string_id = STR_ID_VRSI_GRAMMAR2_PROMPT_HOME;
                    post_cmd = VRSI_CMD2_HOME;
                    home_count++;
                }
                else if(home_count == 1)
                {
                    string_id = STR_ID_VRSI_GRAMMAR2_PROMPT_HOME2;
                    tts_string = STR_ID_VRSI_GRAMMAR2_PROMPT_HOME;
                    post_cmd = VRSI_CMD2_HOME2;
                    home_count++;
                }
                else if(home_count == 2)
                {
                    tts_string = STR_ID_VRSI_GRAMMAR2_PROMPT_HOME3;
                    string_id = STR_ID_VRSI_GRAMMAR2_PROMPT_HOME;
                    post_cmd = VRSI_CMD2_HOME3;
                    home_count++;
                }
                break;
            case MMI_PHB_NUM_TYPE_OFFICE:
                if(office_count == 0)
                {
                    tts_string = STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE;
                    string_id = STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE;                                        
                    post_cmd = VRSI_CMD2_BUSINESS;
                    office_count++;
                }
                else if(office_count == 1)
                {
                    tts_string = STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE2;
                    string_id = STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE;
                    post_cmd = VRSI_CMD2_BUSINESS2;
                    office_count ++;
                }
                else if(office_count == 2)
                {
                    tts_string = STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE3;
                    string_id = STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE;                                        
                    post_cmd = VRSI_CMD2_BUSINESS3;
                }
                break;
            case MMI_PHB_NUM_TYPE_FAX:
                if(fax_count == 0)
                {
                    tts_string = STR_ID_VRSI_GRAMMAR2_PROMPT_FAX;
                    string_id = STR_ID_VRSI_GRAMMAR2_PROMPT_FAX;
                    post_cmd = VRSI_CMD2_FAX;
                    fax_count++;
                }
                else if(fax_count == 1)
                {
                    tts_string = STR_ID_VRSI_GRAMMAR2_PROMPT_FAX2;
                    string_id = STR_ID_VRSI_GRAMMAR2_PROMPT_FAX;
                    post_cmd = VRSI_CMD2_FAX2;
                    fax_count ++;
                }
                else if(fax_count == 2)
                {
                    tts_string = STR_ID_VRSI_GRAMMAR2_PROMPT_FAX3;
                    string_id = STR_ID_VRSI_GRAMMAR2_PROMPT_FAX;
                    post_cmd = VRSI_CMD2_FAX3;
                    fax_count++;
                }
                break;

            default:
                break;            
        }
        
        mmi_ucs2cat(str_prompt, GetString(tts_string));
        mmi_ucs2ncpy(
            (S8*) subMenuData[i],
            GetString(string_id),
            MAX_SUBMENU_CHARACTERS);        
    }
    #endif
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_CANCEL));

    /* Assign post command for dial if there are only one number */
    if (loc_count == 1)
    {
        g_vrsi_cntx.post_cmd = post_cmd;
    }

    return loc_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_number_prompt
 * DESCRIPTION
 *  Prompt string for multiple number
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompt string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_number_prompt(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];

    /* Play SD tag if exists. */
    result = mmi_vrsi_util_play_name_tag(
                MMI_VRSI_GRAMMAR_1,
                MMI_VRSI_APP_DIAL,
                store_index,
                mmi_vrsi_ndial_multiple_number_prompt2);

    if (result == MED_RES_OK)
    {
        return;
    }

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_number_prompt2
 * DESCRIPTION
 *  Prompt string for multiple number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_number_prompt2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MMI_PHB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_prompt, 0, 2);
    mmi_vrsi_ndial_multiple_number_show_data(str_prompt);

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);
}

#define MMI_VRSI_NDIAL_MULTIPLE_RECORD


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_multiple_record
 * DESCRIPTION
 *  Entry function for multiple duplicated record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_multiple_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *name_ptr[MMI_VRSI_MAX_RCG_RESULT];
    U16 str_prompt[MMI_PHB_NAME_LENGTH + 60];
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Prepare hint data */
    mmi_vrsi_ndial_multiple_record_show_hint((U16**)name_ptr);

    TurnOnBacklight(1);
    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI, 
       SCR_ID_VRSI_NAME_DIAL_MULTI_RECORD, 
       mmi_vrsi_exit_ndial_multiple_record, 
       mmi_vrsi_entry_ndial_multiple_record, 
       MMI_FRM_FG_ONLY_SCRN);   
    if (!entry_ret)
    {
        return;
    } 

    RegisterHighlightHandler(mmi_vrsi_entry_ndial_get_index);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        EnableCenterSoftkey( 0, IMG_GLOBAL_COMMON_CSK);
    }
    ShowCategory53Screen(
        STR_ID_VRSI_APP,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_CANCEL,
        0,
        g_vrsi_cntx.long_list_num,
        (U8**)name_ptr,
        (U16*) gIndexIconsImageList,
        hintDataPtrs,
        0,
        g_vrsi_cntx.active_index,
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_multiple_record_to_single_record, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsi_ndial_multiple_record_to_single_record, KEY_SEND, KEY_EVENT_UP);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        ChangeCenterSoftkey( 0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_vrsi_ndial_multiple_record_to_single_record, KEY_EVENT_UP);
    }
    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_3;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_NAME_DIAL;

    /*Play first prompt only*/
    mmi_ucs2cpy((S8*)str_prompt, GetString(STR_ID_VRSI_GRAMMAR3_PROMPT));
    mmi_vrsi_util_play_tts((U16*) str_prompt,
    mmi_vrsi_ndial_multiple_record_prompt2);
    
    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_ndial_multiple_record
 * DESCRIPTION
 *  Exit function for multiple duplicated record, will exit VR session if next screen is not
 *  In vr scenario
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_ndial_multiple_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scr_id;
    MMI_ID group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //scr_id = mmi_frm_scrn_get_active_id();
    mmi_frm_get_active_scrn_id(&group_id, &scr_id);
    if ((scr_id == SCR_ID_VRSI_RCG_MAIN) ||
        (scr_id == SCR_ID_VRSI_NAME_DIAL_MULTI_RECORD) ||
        (scr_id == SCR_ID_VRSI_NAME_DIAL_MULTI_NUM) || (scr_id == SCR_ID_VRSI_NAME_DIAL_CONFIRM))
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_multiple_record_in_history
 * DESCRIPTION
 *  Entry function for multiple duplicated record after retry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_multiple_record_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *name_ptr[MMI_VRSI_MAX_RCG_RESULT];
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Prepare hint data */
    mmi_vrsi_ndial_multiple_record_show_hint(name_ptr);

    TurnOnBacklight(1);
    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI, 
       SCR_ID_VRSI_NAME_DIAL_MULTI_RECORD_IN_HISTORY, 
       NULL, 
       mmi_vrsi_entry_ndial_multiple_record_in_history, 
       MMI_FRM_FG_ONLY_SCRN); 
    if (!entry_ret)
    {
        return;
    } 

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    RegisterHighlightHandler(mmi_vrsi_entry_ndial_get_index);

    ShowCategory53Screen(
        STR_ID_VRSI_APP,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_CANCEL,
        0,
        g_vrsi_cntx.long_list_num,
        (U8**)name_ptr,
        (U16*) gIndexIconsImageList,
        hintDataPtrs,
        0,
        g_vrsi_cntx.active_index,
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_multiple_record_to_single_record, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsi_ndial_multiple_record_to_single_record, KEY_SEND, KEY_EVENT_UP);
    
    ChangeCenterSoftkey( 0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_vrsi_ndial_multiple_record_to_single_record, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_record_to_single_record
 * DESCRIPTION
 *  Prompt message for multiple record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_record_to_single_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 long_list[1];
    MMI_ID scr_id;
    MMI_ID group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Enter screen from screen not in VR session, so init engine again. */
    //scr_id = mmi_frm_scrn_get_active_id();
    mmi_frm_get_active_scrn_id( &group_id, &scr_id);
    if (scr_id == SCR_ID_VRSI_NAME_DIAL_MULTI_RECORD_IN_HISTORY)
    {
        mmi_vrsi_rcg_init(NULL);
    }
    else
    {
        mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
    }

    long_list[0] = g_vrsi_cntx.long_list[g_vrsi_cntx.active_index];
    mmi_vrsi_ndial_rcg_grammar1_result(1, long_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_record_show_data
 * DESCRIPTION
 *  Prompt message for multiple record
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompt message string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_record_show_data(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 name_buf[MMI_PHB_NAME_LENGTH];
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Prepare prompt string */
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_GRAMMAR3_PROMPT));
    ret = srv_phb_get_name(g_vrsi_cntx.long_list[0], name_buf, MMI_PHB_NAME_LENGTH - 1);
	if (ret < 0)
	{
		return;
	}
    mmi_ucs2cat(str_prompt, (S8*) name_buf);
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR3_PROMPT_SELECT));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_record_show_hint
 * DESCRIPTION
 *  Prompt message for multiple record
 * PARAMETERS
 *  name_ptr        [IN/OUT]        hint pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_record_show_hint(U16 **name_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 store_index;
    S8 number_buff[(MMI_PHB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
    S32 ret;
	S32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Prepare hint list data */
    for (i = 0; i < g_vrsi_cntx.long_list_num; i++)
    {
        store_index = g_vrsi_cntx.long_list[i];
        srv_phb_get_name(store_index, (U16*)name_ptr[i], MMI_PHB_NAME_LENGTH);
        srv_phb_get_number(store_index, (U16 *)number_buff, MMI_PHB_NUMBER_LENGTH);
        mmi_ucs2ncpy((S8*) hintData[i], number_buff, MAX_SUBMENU_CHARACTERS);
        hintDataPtrs[i] = hintData[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_record_prompt2
 * DESCRIPTION
 *  Prompt message for multiple record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_record_prompt2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_prompt[(MMI_PHB_NAME_LENGTH + 60)];
    S32 result;
    U16 store_index;
    U16 name_buf[MMI_PHB_NAME_LENGTH];
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];

    /* Play SD tag if exists. */
    result = mmi_vrsi_util_play_name_tag(
                MMI_VRSI_GRAMMAR_1,
                MMI_VRSI_APP_DIAL,
                store_index,
                mmi_vrsi_ndial_multiple_record_prompt3);

    if (result == MED_RES_OK)
    {
        return;
    }
	ret = srv_phb_get_name(store_index, name_buf, MMI_PHB_NAME_LENGTH - 1);
	if (ret < 0)
	{
		return;
	}

    /* Play SI instead */
    mmi_ucs2cat((S8*)str_prompt, (S8*)name_buf);

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_ndial_multiple_record_prompt3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_record_prompt3
 * DESCRIPTION
 *  Prompt message for multiple record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_record_prompt3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MMI_PHB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR3_PROMPT_SELECT));

    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);
}

#define MMI_VRSI_NDIAL_CONFIRM


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_pre_confirm_dial
 * DESCRIPTION
 *  confirm dial location before dial
 * PARAMETERS
 *  dial_loc        [IN]        select location
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_pre_confirm_dial(U8 dial_loc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 filed_flag = 0;
    U16 store_index;
    U16 number_buff[(MMI_PHB_NUMBER_LENGTH + 1)*ENCODING_LENGTH];
    U8 confirm_dial = 0;
    MMI_BOOL ret;
    mmi_phb_num_type_enum type[MMI_VRSI_PHB_OPT_NUM_COUNT];
    U32 filed[3];
    U8 number_order[MMI_VRSI_PHB_OPT_NUM_COUNT];
    U8 loc_count = 1;
    U8 i, j;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];
    memset(number_buff, 0, 2);
    if (g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE)
    {    	
        U32 length = 0;
    	ret = srv_phb_get_number(store_index,(U16 *)number_buff, MMI_PHB_NUMBER_LENGTH);
        length = mmi_ucs2strlen((S8*)number_buff);
        if (ret && length)
        {
            confirm_dial = 1;
        }
    }
    else
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        ret = srv_phb_get_optional_number_order(store_index, number_order);
        for(i = 0; i < MMI_VRSI_PHB_OPT_NUM_COUNT; i++)
        {

            ret = srv_phb_get_optional_number(store_index, (U32)number_order[i], number_buff, &type[i], MMI_PHB_NUMBER_LENGTH);
            if (ret)
            {
                if(mmi_ucs2strlen((S8*)number_buff)) 
                {
                    loc_count++;
                }
                else
                {
                    break;
                }
            }  
        }

        {
            j = 0;
            switch(g_vrsi_cntx.post_cmd) 
            {            
                case VRSI_CMD2_MOBILE2:
                case VRSI_CMD2_MOBILE3:  
                case VRSI_CMD2_MOBILE4:  
                     for(i = 0; i < loc_count; i++)
                     {                        
                        if(type[i] == MMI_PHB_NUM_TYPE_MOBILE)
                        {
                            j++;
                            if((j == 1 && g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE2) ||
                                (j == 2 && g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE3) ||
                                (j == 3 && g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE4))
                            {
                                confirm_dial = 1;
                                break;
                            }
                        }
                     }
                     break;
                     
                case VRSI_CMD2_HOME:
                case VRSI_CMD2_HOME2:
                case VRSI_CMD2_HOME3:
                    for(i = 0; i < loc_count; i++)
                     {                        
                        if(type[i] == MMI_PHB_NUM_TYPE_HOME)
                        {
                            j++;
                            if((j == 1 && g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME) ||
                                (j == 2 && g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME2) ||
                                (j == 3 && g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME3))
                            {
                                confirm_dial = 1;
                                break;
                            }
                        }
                     }
                     break;

                 case VRSI_CMD2_BUSINESS:
                 case VRSI_CMD2_BUSINESS2:
                 case VRSI_CMD2_BUSINESS3:
                    for(i = 0; i <loc_count; i++)
                     {                        
                        if(type[i] == MMI_PHB_NUM_TYPE_OFFICE)
                        {
                            j++;
                            if((j == 1 && g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS) ||
                                (j == 2 && g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS2) ||
                                (j == 3 && g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS3))
                            {
                                confirm_dial = 1;
                                break;
                            }
                        }
                     }
                     break;
                     
                 case VRSI_CMD2_FAX:
                 case VRSI_CMD2_FAX2:
                 case VRSI_CMD2_FAX3:
                     for(i = 0; i < loc_count ; i++)
                     {                        
                         if(type[i] == MMI_PHB_NUM_TYPE_FAX)
                         {
                             j++;
                             if((j == 1 && g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX) ||
                                (j == 2 && g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX2) ||
                                (j == 3 && g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX3))
                             {
                                 confirm_dial = 1;
                                 break;
                             }
                         }
                      }
                      break;                     
               
                default:
                    confirm_dial = 0;
                    break;
                    
            }
        }   
        #endif
    }   
    if (confirm_dial)
    {
        g_vrsi_cntx.retry = 0;
        mmi_vrsi_entry_ndial_confirm_dial();
    }
    else
    {
        mmi_vrsi_ndial_no_number_prompt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_confirm_dial
 * DESCRIPTION
 *  entry function of confirm dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_confirm_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MMI_PHB_NAME_LENGTH + 60) * ENCODING_LENGTH];
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_ndial_confirm_dial_show_data(str_prompt);

    TurnOnBacklight(1);
    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI, 
       SCR_ID_VRSI_NAME_DIAL_CONFIRM, 
       mmi_vrsi_exit_ndial_confirm_dial, 
       mmi_vrsi_entry_ndial_confirm_dial, 
       MMI_FRM_FG_ONLY_SCRN); 
    if (!entry_ret)
    {
        return;
    } 
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        EnableCenterSoftkey( 0, IMG_GLOBAL_COMMON_CSK);
    }
    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_CANCEL,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message string */
        IMG_GLOBAL_QUESTION, /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_dial_entry, KEY_EVENT_UP);

    mmi_ucm_handle_sendkeys_for_call(mmi_vrsi_ndial_dial_entry_for_sendkey,KEY_EVENT_DOWN);   
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_vrsi_ndial_dial_entry, KEY_EVENT_UP);
    }

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_4;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_NAME_DIAL;

    /*Play first prompt only*/
    mmi_vrsi_ndial_confirm_dial_show_data1(str_prompt);
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_ndial_confirm_dial_prompt2);

    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_ndial_confirm_dial
 * DESCRIPTION
 *  exit function for confirm dial. Will exit VR session if next screen is not in VR session.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_ndial_confirm_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scr_id;
    MMI_ID group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_get_active_scrn_id(&group_id, &scr_id);
    if ((scr_id == SCR_ID_VRSI_RCG_MAIN) || /* Speak command again */
        (scr_id == SCR_ID_VRSI_NAME_DIAL_CONFIRM))
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_confirm_dial_in_history
 * DESCRIPTION
 *  entry function of confirm dial screen after retry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_confirm_dial_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MMI_PHB_NAME_LENGTH + 60) * ENCODING_LENGTH];
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_ndial_confirm_dial_show_data(str_prompt);

    TurnOnBacklight(1);
    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI_RCG_MAIN, 
       SCR_ID_VRSI_NAME_DIAL_CONFIRM_IN_HISTORY, 
       NULL, 
       mmi_vrsi_entry_ndial_confirm_dial_in_history, 
       MMI_FRM_FG_ONLY_SCRN); 
    if (!entry_ret)
    {
        return;
    } 
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        GetRootTitleIcon(MENU_ID_VRSI_SETTING),
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_CANCEL,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message string */
        IMG_GLOBAL_QUESTION, /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_dial_entry, KEY_EVENT_UP);

    mmi_ucm_handle_sendkeys_for_call(mmi_vrsi_ndial_dial_entry_for_sendkey,KEY_EVENT_DOWN);   
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_vrsi_ndial_dial_entry, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_confirm_dial_show_data
 * DESCRIPTION
 *  prompt message of confirm dial.
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompr string.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_confirm_dial_show_data(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_ndial_confirm_dial_show_data1(str_prompt);
    mmi_vrsi_ndial_confirm_dial_show_data2(str_prompt);
    mmi_vrsi_ndial_confirm_dial_show_data3(str_prompt);

    /* Replace \r\n as space to avoid show oversize on screen. */
    for (i = 0; i < (MMI_PHB_NAME_LENGTH + 59) * ENCODING_LENGTH; i = i + 2)
    {
        if (str_prompt[i] == 0x0D && str_prompt[i + 1] == 0x00 &&
            str_prompt[i + 2] == 0x0A && str_prompt[i + 3] == 0x00)
        {
            str_prompt[i] = 0x20;
            str_prompt[i + 2] = 0x20;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_confirm_dial_show_data1
 * DESCRIPTION
 *  prompt message of confirm dial.
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompr string.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_confirm_dial_show_data1(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_DIAL_PROMPT));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_confirm_dial_show_data2
 * DESCRIPTION
 *  prompt message of confirm dial.
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompr string.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_confirm_dial_show_data2(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    U16 name_buf[MMI_PHB_NAME_LENGTH];
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];
	ret = srv_phb_get_name(store_index, name_buf, MMI_PHB_NAME_LENGTH - 1);
	if (ret < 0)
	{
		return;
	}    
    mmi_ucs2cat((S8*)str_prompt, (S8*)name_buf);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_confirm_dial_show_data3
 * DESCRIPTION
 *  prompt message of confirm dial.
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompr string.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_confirm_dial_show_data3(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    if (g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE   ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE2  ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE3  ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE4)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE));
    }
    else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME ||
         g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME2    ||
         g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME3)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_HOME));
    }
    else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS2     ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS3)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE));
    }
    else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX     ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX2         ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX3)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_FAX));
    }

    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR4_PROMPT));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_confirm_dial_prompt2
 * DESCRIPTION
 *  prompt message of confirm dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_confirm_dial_prompt2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_prompt[(MMI_PHB_NAME_LENGTH + 60)];
    S32 result;
    U16 store_index;
    U16 name_buf[MMI_PHB_NAME_LENGTH];
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];

    /* Play SD tag if exists. */
    result = mmi_vrsi_util_play_name_tag(MMI_VRSI_GRAMMAR_1, MMI_VRSI_APP_DIAL, store_index, mmi_vrsi_ndial_confirm_dial_prompt3);

    if (result == MED_RES_OK)
    {
        return;
    }
	ret = srv_phb_get_name(store_index, name_buf, MMI_PHB_NAME_LENGTH - 1);
	if (ret < 0)
	{
		return;
	}

    /* Play SI instead */
    mmi_ucs2cat((S8*)str_prompt, (S8*) name_buf);

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_ndial_confirm_dial_prompt3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_confirm_dial_prompt3
 * DESCRIPTION
 *  prompt message of confirm dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_confirm_dial_prompt3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MMI_PHB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_prompt, 0, 2);
    mmi_vrsi_ndial_confirm_dial_show_data3(str_prompt);

    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_no_number_show_data
 * DESCRIPTION
 *  prompt message for no number to dial.
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompt string.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_no_number_show_data(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //yaling
    if (g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE2 ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE3 ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE3)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE));
    }
    else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME2    ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME3)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_HOME));
    }
    else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS2     ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS3)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE));
    }
    else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX  ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX2      ||
        g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX3)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_FAX));
    }

    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_TTS_NUMBER_NO_DATA));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_no_number_prompt
 * DESCRIPTION
 *  prompt message for no number to dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_no_number_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_prompt[(MMI_PHB_NAME_LENGTH + 60)];
    S32 result;
    U16 name_buf[MMI_PHB_NAME_LENGTH];
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_vrsi_cntx.curr_scenario = VRSI_CMD1_EXIT;

    /* Play SD tag if exists. */
    result = mmi_vrsi_util_play_name_tag(
                MMI_VRSI_GRAMMAR_1,
                MMI_VRSI_APP_DIAL,
                g_vrsi_cntx.long_list[0],
                mmi_vrsi_ndial_no_number_prompt2);

    if (result == MED_RES_OK)
    {
        return;
    }
	ret = srv_phb_get_name(g_vrsi_cntx.long_list[0], name_buf, MMI_PHB_NAME_LENGTH - 1);
	if (ret < 0)
	{
		return;
	}

    mmi_ucs2cpy((S8*)str_prompt, (S8*) name_buf);
    mmi_vrsi_ndial_no_number_show_data((S8*)str_prompt);

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_no_number_prompt2
 * DESCRIPTION
 *  prompt message for no number to dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_no_number_prompt2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MMI_PHB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_prompt, 0, 2);
    mmi_vrsi_ndial_no_number_show_data(str_prompt);

    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_dial_entry
 * DESCRIPTION
 *  Entry function for no number to dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_dial_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 filed_flag = 0;
    U16 store_index;
    U16 number_buff[(MMI_PHB_NUMBER_LENGTH + 1)*ENCODING_LENGTH];
    mmi_ucm_make_call_para_struct make_call_para;
    mmi_phb_num_type_enum type[MMI_VRSI_PHB_OPT_NUM_COUNT];
    U8 number_order[MMI_VRSI_PHB_OPT_NUM_COUNT];
    U8 loc_count = 0;
    U8 i, j = 0;
    U8 confirm_dial;
    MMI_BOOL ret= 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];

    memset((S8 *)number_buff, 0, 2);

    if (g_vrsi_cntx.post_cmd == 0 || g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE)
    {
        srv_phb_get_number(store_index, number_buff, MMI_PHB_NUMBER_LENGTH);
    }
    else 
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        ret = srv_phb_get_optional_number_order(store_index, number_order);
        for(i = 0; i < MMI_VRSI_PHB_OPT_NUM_COUNT; i++)
        {
            ret = srv_phb_get_optional_number(store_index, (U32)number_order[i], number_buff, &type[i], MMI_PHB_NUMBER_LENGTH);
            if (ret)
            {
                if(mmi_ucs2strlen((S8*)number_buff))
                {
                    loc_count++;
                }
                else
                {
                    break;
                }
            }  
        }
    
        j = 0;
        switch(g_vrsi_cntx.post_cmd) 
        {  
            case VRSI_CMD2_MOBILE2:
            case VRSI_CMD2_MOBILE3:  
            case VRSI_CMD2_MOBILE4:  
                 for(i = 0; i < loc_count ; i++)
                 {                        
                    if(type[i] == MMI_PHB_NUM_TYPE_MOBILE)
                    {
                        j++;
                        if((j == 1 && g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE2) ||
                            (j == 2 && g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE3) ||
                            (j == 3 && g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE4))
                        {
                            confirm_dial = 1;
                            break;
                        }
                    }
                 }
                 break;
                 
            case VRSI_CMD2_HOME:
            case VRSI_CMD2_HOME2:
            case VRSI_CMD2_HOME3:
                for(i = 0; i < loc_count; i++)
                 {                        
                    if(type[i] == MMI_PHB_NUM_TYPE_HOME)
                    {
                        j++;
                        if((j == 1 && g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME) ||
                            (j == 2 && g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME2) ||
                            (j == 3 && g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME3))
                        {
                            confirm_dial = 1;
                            break;
                        }
                    }
                 }
                 break;

             case VRSI_CMD2_BUSINESS:
             case VRSI_CMD2_BUSINESS2:
             case VRSI_CMD2_BUSINESS3:
                for(i = 0; i < loc_count; i++)
                 {                        
                    if(type[i] == MMI_PHB_NUM_TYPE_OFFICE)
                    {
                        j++;
                        if((j == 1 && g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS) ||
                            (j == 2 && g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS2) ||
                            (j == 3 && g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS3))
                        {
                            confirm_dial = 1;
                            break;
                        }
                    }
                 }
                 break;
                 
             case VRSI_CMD2_FAX:
             case VRSI_CMD2_FAX2:
             case VRSI_CMD2_FAX3:
                 for(i = 0; i < loc_count; i++)
                 {                        
                     if(type[i] == MMI_PHB_NUM_TYPE_FAX)
                     {
                         j++;
                         if((j == 1 && g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX) ||
                            (j == 2 && g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX2) ||
                            (j == 3 && g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX3))
                         {
                             confirm_dial = 1;
                             break;
                         }
                     }
                  }
                  break;                     
           
            default:
                confirm_dial = 0;
                break;
                
        }
        if(confirm_dial)
        {
            filed_flag = number_order[i];
            ret = srv_phb_get_optional_number(store_index, filed_flag, number_buff, NULL , MMI_PHB_NUMBER_LENGTH);
        }
        #endif
    }

    if (mmi_ucs2strlen((S8 *)number_buff))
    {
        U16 i = 0;

        /* simulate the behavior as dial from phonebook list */
        for (i = 0; i < vrsi_phb_entry_cnt; i++)
            if (vrsi_phb_index[i] == store_index)
            {
                break;
            }

       g_vrsi_cntx.active_index = i;

        /* close recognition precedure before make call */
        mmi_vrsi_rcg_close();
        
        mmi_ucm_init_call_para(&make_call_para);     
        make_call_para.ucs2_num_uri = (U16*)number_buff;
        mmi_ucm_call_launch(0, &make_call_para);      
	       
    }
    else
    {
        mmi_vrsi_ndial_no_number_prompt();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_dial_entry_for_sendkey
 * DESCRIPTION
 *  Entry function for no number to dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_dial_entry_for_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 filed_flag = 0;
    U16 store_index;
    U16 number_buff[(MMI_PHB_NUMBER_LENGTH + 1)*ENCODING_LENGTH];
    mmi_ucm_make_call_para_struct sendkey_makecall_para;
    mmi_phb_num_type_enum type[MMI_VRSI_PHB_OPT_NUM_COUNT];
    U8 number_order[MMI_VRSI_PHB_OPT_NUM_COUNT];
    U8 loc_count = 0;
    U8 i, j ;
    U8 confirm_dial = 0;
    MMI_BOOL ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];

    memset(number_buff, 0, 2);

    if (g_vrsi_cntx.post_cmd == 0 || g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE)
    {
        srv_phb_get_number(store_index, number_buff, MMI_PHB_NUMBER_LENGTH);
    }
    else
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        ret = srv_phb_get_optional_number_order(store_index, number_order);
        for(i = 0; i < MMI_VRSI_PHB_OPT_NUM_COUNT; i++)
        {
            ret = srv_phb_get_optional_number(store_index, (U32)number_order[i], number_buff, &type[i], MMI_PHB_NUMBER_LENGTH);
            if (ret)
            {
                if(mmi_ucs2strlen((S8*)number_buff))
                {
                    loc_count++;
                }
                else
                {
                    break;
                }
            }
        }
    
        j = 0;
        switch(g_vrsi_cntx.post_cmd) 
        {   
            case VRSI_CMD2_MOBILE2:
            case VRSI_CMD2_MOBILE3:  
            case VRSI_CMD2_MOBILE4:  
                 for(i = 0; i < loc_count; i++)
                 {                        
                    if(type[i] == MMI_PHB_NUM_TYPE_MOBILE)
                    {
                        j++;
                        if((j == 1 && g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE2) ||
                            (j == 2 && g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE3) ||
                            (j == 3 && g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE4))
                        {
                            confirm_dial = 1;
                            break;
                        }
                    }
                 }
                 break;
                 
            case VRSI_CMD2_HOME:
            case VRSI_CMD2_HOME2:
            case VRSI_CMD2_HOME3:
                for(i = 0; i < loc_count ; i++)
                 {                        
                    if(type[i] == MMI_PHB_NUM_TYPE_HOME)
                    {
                        j++;
                        if((j == 1 && g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME) ||
                            (j == 2 && g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME2) ||
                            (j == 3 && g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME3))
                        {
                            confirm_dial = 1;
                            break;
                        }
                    }
                 }
                 break;

             case VRSI_CMD2_BUSINESS:
             case VRSI_CMD2_BUSINESS2:
             case VRSI_CMD2_BUSINESS3:
                for(i = 0; i < loc_count; i++)
                 {                        
                    if(type[i] == MMI_PHB_NUM_TYPE_OFFICE)
                    {
                        j++;
                        if((j == 1 && g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS) ||
                            (j == 2 && g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS2) ||
                            (j == 3 && g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS3))
                        {
                            confirm_dial = 1;
                            break;
                        }
                    }
                 }
                 break;
                 
             case VRSI_CMD2_FAX:
             case VRSI_CMD2_FAX2:
             case VRSI_CMD2_FAX3:
                 for(i = 0; i < loc_count ; i++)
                 {                        
                     if(type[i] == MMI_PHB_NUM_TYPE_FAX)
                     {
                         j++;
                         if((j == 1 && g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX) ||
                            (j == 2 && g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX2) ||
                            (j == 3 && g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX3))
                         {
                             confirm_dial = 1;
                             break;
                         }
                     }
                  }
                  break;                     
           
            default:
                confirm_dial = 0;
                break;
        }
        if(confirm_dial)
        {
            filed_flag = (U32)number_order[i];
            ret = srv_phb_get_optional_number(store_index, filed_flag, number_buff, NULL , MMI_PHB_NUMBER_LENGTH);
        }
        #endif
    }

 
    if (mmi_ucs2strlen((S8 *)number_buff))
    {
        U16 k = 0;

        /* simulate the behavior as dial from phonebook list */
        for (k = 0; i < vrsi_phb_entry_cnt; k++)
        if (vrsi_phb_index[k] == store_index)
            {
                break;
            }

		g_vrsi_cntx.active_index = k;


        /* close recognition precedure before make call */
        mmi_vrsi_rcg_close();        

        mmi_ucm_init_call_para_for_sendkey(&sendkey_makecall_para); 
        sendkey_makecall_para.ucs2_num_uri = (U16 *)number_buff;   
        mmi_ucm_call_launch(0, &sendkey_makecall_para);
      
    }
    else
    {
        mmi_vrsi_ndial_no_number_prompt();
    }
}

#define MMI_VRSI_NDIAL_TRAIN_CENTRAL
#if defined(__MMI_VRSI_TRAIN_TAG__)
U16 g_vrsi_phb_list_index;
U16 g_vrsi_phb_list_count;


void mmi_vrsi_phb_pre_entry_train_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag_loc;
    U16 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_phb_sort_index_to_store_index(PHB_STORAGE_MAX, g_vrsi_phb_list_index);
    g_vrsi_cntx.long_name_ptr = (U16*) vrsi_dial_name[g_vrsi_phb_list_index];
    srv_phb_get_name(index, g_vrsi_cntx.long_name_ptr, MMI_PHB_NAME_LENGTH);
    g_vrsi_cntx.long_list[0] = index;
    g_vrsi_cntx.long_list_num = 1;

    g_vrsi_cntx.curr_app = MMI_VRSI_APP_DIAL;

    tag_loc = mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_DIAL, index, NULL);

    /* Modify, Playback, or delete exists voice tag. */
    if (tag_loc < 0xff)
    {
        /* mmi_vrsi_entry_ndial_train_del(); */
        mmi_vrsi_entry_train_option_del();
    }
    /* No tag exists, add new tag */
    else
    {
        mmi_vrsi_entry_train_option_add();
    }
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
static void mmi_vrsi_phb_list_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag_loc;
    U16 string_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return;
    }
    mmi_frm_group_create(GRP_ID_VRSI, GRP_ID_VRSI_TRAIN_OPTION_MAIN, mmi_vrsi_settings_event_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_VRSI_TRAIN_OPTION_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    index = srv_phb_sort_index_to_store_index(PHB_STORAGE_MAX, g_vrsi_phb_list_index);
    g_vrsi_cntx.long_name_ptr = (U16*) vrsi_dial_name[g_vrsi_phb_list_index];
    srv_phb_get_name(index, g_vrsi_cntx.long_name_ptr, MMI_PHB_NAME_LENGTH);
    g_vrsi_cntx.long_list[0] = index;
    g_vrsi_cntx.long_list_num = 1;

    g_vrsi_cntx.curr_app = MMI_VRSI_APP_DIAL;

    tag_loc = mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_DIAL, index, NULL);

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

static pBOOL mmi_vrsi_phb_get_list_item(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    index = srv_phb_sort_index_to_store_index(PHB_STORAGE_MAX, (U16)item_idx);  
   
    srv_phb_get_name(index, (U16*)str_buff, MMI_PHB_NAME_LENGTH);          
    if (mmi_vrsi_train_util_get_loc_in_list(MMI_VRSI_APP_DIAL, (U16)(index), tag_list) !=
       0xff)
    {
        *img_buff_p = (PU8) GetImage(IMG_ID_VRSI_APP);
    }
    else
    {
        switch (srv_phb_get_storage(index))
        {
            case PHB_STORAGE_SIM:
                
            #ifdef	__MMI_DUAL_SIM_MASTER__
/* under construction !*/
            #else    
                *img_buff_p = get_image(IMG_ID_VRSI_SIM);
            #endif
                break;
                
            case PHB_STORAGE_SIM2:
                *img_buff_p = get_image(IMG_ID_VRSI_SIM2);
                break;
                
            case PHB_STORAGE_NVRAM:
                *img_buff_p = get_image(IMG_ID_VRSI_PHONE);
                break;
                
            default:
                break;
        }
    }
    return MMI_TRUE;
}



void mmi_vrsi_phb_list_highlight_hdlr(S32 index)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_phb_list_index = index;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_select_contact_proc
 * DESCRIPTION
 *  mmi_vrsi_select_contact_proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_vrsi_select_contact_proc(mmi_event_struct *evt)
{
	cui_phb_select_contact_result_struct* select_contact_result;
	cui_menu_event_struct *menu_evt;
	
    menu_evt = (cui_menu_event_struct*)evt;
	switch(evt->evt_id)
		{
	case EVT_ID_PHB_SELECT_CONTACT:
			select_contact_result = (cui_phb_select_contact_result_struct*)evt;
			mmi_vrsi_ndial_train_list_callback(select_contact_result->store_index);		   
			break;
	
	 case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
		  cui_phb_list_select_contact_close(menu_evt->sender_id);
				break;
		  default:
				break;
		}
		
		return MMI_RET_OK;

}

mmi_ret mmi_vrsi_phb_proc(mmi_event_struct *evt)
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
            mmi_vrsi_phb_pre_entry_train_main();
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



/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_train_list_pre_entry
 * DESCRIPTION
 *  Pre entry phonebook list to select an entry to train SD tags.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_train_list_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U8* gui_buffer;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
    	return;
    }
    ret = srv_phb_get_used_contact(PHB_STORAGE_MAX);
	if (ret <= 0)
	{
	    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY),MMI_EVENT_FAILURE, GRP_ID_VRSI, 0);
		return;
	}	
	
    mmi_frm_group_create(GRP_ID_VRSI_TRAIN_TAG_MAIN, GRP_ID_VRSI_TRAIN_PHB_LIST, mmi_vrsi_phb_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_VRSI_TRAIN_PHB_LIST, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
       GRP_ID_VRSI_TRAIN_PHB_LIST, 
       SCR_ID_VRSI_TRAIN_PHB_LIST, 
       NULL, 
       mmi_vrsi_ndial_train_list_pre_entry, 
       MMI_FRM_UNKNOW_SCRN);


    gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_VRSI_TRAIN_PHB_LIST, SCR_ID_VRSI_TRAIN_PHB_LIST);
    
    if (gui_buffer == NULL)
    {
        g_vrsi_phb_list_count = ret;      
        g_vrsi_phb_list_index = 0;
    }
    if (!g_vrsi_phb_list_count)
    {
         ShowCategory353Screen(
           (U8*)GetString(STR_ID_VRSI_DAIL_LIST),
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
        EnableCenterSoftkey( 0, IMG_GLOBAL_OPTION_CSK);
        RegisterHighlightHandler(mmi_vrsi_phb_list_highlight_hdlr);
        ShowCategory183Screen(
           get_string(STR_ID_VRSI_DAIL_LIST),
           get_image(GetRootTitleIcon(MENU_ID_VRSI_SETTING)),
           get_string(STR_GLOBAL_OPTIONS),
           get_image(IMG_GLOBAL_OPTIONS),
           get_string(STR_GLOBAL_BACK),
           get_image(IMG_GLOBAL_BACK),
           g_vrsi_phb_list_count,
           mmi_vrsi_phb_get_list_item, 
           NULL,
           NULL,
           MMI_FALSE,
           NULL,
           gui_buffer);  
        ClearKeyEvents();
#ifdef __MMI_FTE_SUPPORT__ 
        wgui_register_tap_callback(mmi_vrsi_phb_list_tap_callback);
#endif
        SetCenterSoftkeyFunction(mmi_vrsi_phb_pre_entry_train_main, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_vrsi_phb_pre_entry_train_main, KEY_EVENT_UP);
    }       
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_train_list_callback
 * DESCRIPTION
 *  Callback function for train SD tag after select an entry from phonebook.
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_train_list_callback(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag_loc;
    S32 index;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_phb_store_index_to_sort_index(PHB_STORAGE_MAX, store_index);
    g_vrsi_cntx.long_name_ptr = (U16*) vrsi_dial_name[index];  
     srv_phb_get_name(store_index, g_vrsi_cntx.long_name_ptr, MMI_PHB_NAME_LENGTH);
    g_vrsi_cntx.long_list[0] = store_index;
    g_vrsi_cntx.long_list_num = 1;

    g_vrsi_cntx.curr_app = MMI_VRSI_APP_DIAL;

    tag_loc = mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_DIAL, store_index, NULL);

    /* Modify, Playback, or delete exists voice tag. */
    if (tag_loc < 0xff)
    {
        /* mmi_vrsi_entry_ndial_train_del(); */
        mmi_vrsi_entry_train_option_del();
    }
    /* No tag exists, add new tag */
    else
    {
        mmi_vrsi_entry_train_option_add();
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_delete_contact_callback
 * DESCRIPTION
 *  mmi_vrsi_delete_contact_callback
 * PARAMETERS
 *  SelectedDate        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_vrsi_delete_contact_callback(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct* evt = (srv_phb_op_evt_struct*)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_vrsi_train_util_del_tag(MMI_VRSI_APP_DIAL, evt->store_index);
	
    return MMI_RET_OK;    
}


#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ /* #if defined(__MMI_VRSI_TRAIN_TAG__) */


#else /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */

mmi_ret mmi_vrsi_phb_evt_hdlr(mmi_event_struct* param)
{
    /* dummy */
    return MMI_RET_OK;  
}

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_VRSINAMEDIAL_C */ /* #ifndef _MMI_VRSINAMEDIAL_C */

