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
 * VRSINameQuery.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for name query of VRSI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef _MMI_VRSINAMEQUERY_C
#define _MMI_VRSINAMEQUERY_C

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */

/* ... Add More MMI header */
#include "med_main.h"
#include "VRSIType.h"
#include "VRSIProt.h"

#include "PhoneBookGprot.h"
#include "PhbSrvGprot.h"
#include "PhbCuiGprot.h"


//#if defined(__FLIGHT_MODE_SUPPORT__)
//#include "SimDetectionGprot.h"
//#endif 

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif 
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif  /*__MMI_DUAL_SIM_MASTER__*/

#include "mmi_rp_srv_vrsi_def.h"

#include "MMI_features.h"
#include "MMIDataType.h"
#include "custom_phb_config.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "mmi_frm_scenario_gprot.h"
#include "ps_public_enum.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
static mmi_id vrsi_name_query_p_id;
static mmi_id vrsi_name_query_c_id;
/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern U16 vrsi_phb_entry_cnt;
extern U16 vrsi_phb_index[];
extern S32 vrsi_phb_tag_index[];

/* 
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_rcg_grammar1_result
 * DESCRIPTION
 *  This function handle the recognition result for grammar 1 in name query scenario
 * PARAMETERS
 *  tag_num         [IN]        result tag number
 *  long_list       [IN]        result index list
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_rcg_grammar1_result(U16 tag_num, S32 *long_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U16 min_name_id = 0xffff, min_store_index = 0xffff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the first entry in phonebook list order */
    for (i = 0; i < tag_num; i++)
    {
        for (j = 0; j < vrsi_phb_entry_cnt; j++)
        {
            if (vrsi_phb_index[j] == long_list[i])
            {
                if (j < min_name_id)
                {
                    min_name_id = j;
                    min_store_index = long_list[i];
                }
                break;
            }

        }
    }

    if (min_store_index < MMI_PHB_ENTRIES)
    {
        /* Only handle first record for name query */
        g_vrsi_cntx.long_list[0] = min_store_index;
        g_vrsi_cntx.active_index = min_name_id;

       // g_phb_cntx.highlight_entry = min_name_id;
        g_vrsi_cntx.retry = 0;

        mmi_vrsi_pre_entry_nquery_list();
    }
    else    /* Not in name list, try result in city list */
    {
        mmi_vrsi_city_rcg_grammar1_result(tag_num, long_list);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_grammar5_prompt
 * DESCRIPTION
 *  Prompt message of name query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_grammar5_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MMI_PHB_NAME_LENGTH + 60) * ENCODING_LENGTH];
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = vrsi_phb_index[g_vrsi_cntx.active_index];

    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_TTS_FOUND));

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_5;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_NAME_QUERY;

    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_nquery_grammar5_prompt2);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_grammar5_prompt2
 * DESCRIPTION
 *  Prompt message of name query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_grammar5_prompt2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MMI_PHB_NAME_LENGTH + 60) * ENCODING_LENGTH];
    S32 result;
    U16 store_index;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = vrsi_phb_index[g_vrsi_cntx.active_index];

    /* Play SD tag if exists. */
    result = mmi_vrsi_util_play_name_tag(MMI_VRSI_GRAMMAR_1, MMI_VRSI_APP_DIAL, store_index, mmi_vrsi_nquery_grammar5_prompt3);

    if (result == MED_RES_OK)
    {
        return;
    }

    /* Play SI instead */
    memset((S8 *)str_prompt, 0, (MMI_PHB_NAME_LENGTH + 60) * ENCODING_LENGTH);
    result = srv_phb_get_name(store_index, (U16 *)str_prompt, MMI_PHB_NAME_LENGTH); 
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR5_PROMPT));

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_grammar5_prompt3
 * DESCRIPTION
 *  Prompt message of name query
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_grammar5_prompt3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MMI_PHB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR5_PROMPT));

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_get_index
 * DESCRIPTION
 *  Highlight index callback function
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_get_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //g_phb_cntx.active_index = (U16) nIndex;
    //g_phb_cntx.highlight_entry = (U16) nIndex;
    g_vrsi_cntx.active_index =  (U16) nIndex;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_name_query_proc
 * DESCRIPTION
 *  mmi_vrsi_name_query_proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_vrsi_name_query_proc(mmi_event_struct *evt)
{
    cui_phb_list_contact_highlight_struct *highlight_contact_result;
    cui_phb_select_contact_result_struct *select_contact_result;
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_name_query_proc");
    switch(evt->evt_id)
    {
        case EVT_ID_PHB_LIST_CONTACT_HIGHLIGHT:
            highlight_contact_result = (cui_phb_list_contact_highlight_struct *)evt;
            g_vrsi_cntx.active_index = highlight_contact_result->highlight_store_index;
            kal_prompt_trace(MOD_MMI, "mmi_vrsi_name_query_proc2, index  = %d",g_vrsi_cntx.active_index );
            break;
        case EVT_ID_PHB_SELECT_CONTACT:
            select_contact_result = (cui_phb_select_contact_result_struct*)evt;
            kal_prompt_trace(MOD_MMI, "mmi_vrsi_name_query_proc3 index = %d", g_vrsi_cntx.active_index );
            mmi_vrsi_nquery_pre_dial();
            cui_phb_list_select_contact_close(vrsi_name_query_c_id);
            break;
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            kal_prompt_trace(MOD_MMI, "mmi_vrsi_name_query_proc4");
            cui_phb_list_select_contact_close(vrsi_name_query_c_id);
            break;
		
	default:
		break;
    }
		
    return MMI_RET_OK;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_name_query_prompt_inject
 * DESCRIPTION
 *  mmi_vrsi_name_query_prompt_inject
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_name_query_prompt_inject(void)
{
    mmi_vrsi_nquery_grammar5_prompt();
    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_pre_entry_nquery_list
 * DESCRIPTION
 *  Pre enter name query list function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_pre_entry_nquery_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Check if it can be list in advance
     */
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_pre_entry_nquery_list");
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }
    else if (vrsi_phb_entry_cnt == 0)
    {
    	//failure
    	mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, GRP_ID_VRSI, 0);
        return;
    }

    vrsi_name_query_p_id = mmi_frm_group_create(GRP_ID_VRSI, GRP_ID_VRSI_NAME_QUERY_LIST1, mmi_vrsi_name_query_proc, NULL);
	if (vrsi_name_query_p_id == GRP_ID_INVALID)
	{
	    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_ERROR),MMI_EVENT_FAILURE, GRP_ID_VRSI, 0);
		return;
	}
	mmi_frm_group_enter(vrsi_name_query_p_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    vrsi_name_query_c_id = cui_phb_list_select_contact_create(vrsi_name_query_p_id);
	if (vrsi_name_query_c_id == GRP_ID_INVALID)
	{
  	    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_ERROR),MMI_EVENT_FAILURE, GRP_ID_VRSI, 0);
		return;
	}

	cui_phb_list_select_contact_set_storage(vrsi_name_query_c_id, PHB_STORAGE_MAX);
    cui_phb_list_contact_set_first_highlight_index(vrsi_name_query_c_id, (S32)g_vrsi_cntx.active_index);
    //cui_phb_list_contact_set_extra_handle(vrsi_name_query_c_id, mmi_vrsi_name_query_prompt_inject);	
    cui_phb_list_select_contact_run(vrsi_name_query_c_id);
  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_nquery_list1_in_history
 * DESCRIPTION
 *  Entry name query result list after retry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_nquery_list1_in_history(void)
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
 *  mmi_vrsi_nquery_pre_entry_option
 * DESCRIPTION
 *  List screen key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_pre_entry_option(void)
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
 *  mmi_vrsi_nquery_pre_dial
 * DESCRIPTION
 *  List screen key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_pre_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 pbnumstring[(MMI_PHB_NUMBER_LENGTH+1+1)*ENCODING_LENGTH];
	mmi_ucm_make_call_para_struct make_call_para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_vrsi_nquery_pre_dial, index  = %d",g_vrsi_cntx.active_index );
    srv_phb_get_number(g_vrsi_cntx.active_index, (U16 *)pbnumstring, MMI_PHB_NUMBER_LENGTH); /* BCD number format. */
    mmi_ucm_init_call_para(&make_call_para);     
    make_call_para.ucs2_num_uri = (U16*)pbnumstring;
    mmi_ucm_call_launch(0, &make_call_para);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_goto_previous
 * DESCRIPTION
 *  List screen key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_goto_previous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.retry = 0;
    ExecuteCurrKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);    /* Simulate Up Key */

    mmi_vrsi_nquery_grammar5_prompt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_nquery_goto_next
 * DESCRIPTION
 *  List screen key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_nquery_goto_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.retry = 0;
    ExecuteCurrKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);  /* Simulate Down Key */

    mmi_vrsi_nquery_grammar5_prompt();
}

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_VRSINAMEQUERY_C */ /* #ifndef _MMI_VRSINAMEQUERY_C */

