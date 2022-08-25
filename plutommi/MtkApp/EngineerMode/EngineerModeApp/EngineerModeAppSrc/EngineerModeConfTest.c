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
 *  EngineerModeConftest.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode conformance test.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
  *             HISTORY
  * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
  *------------------------------------------------------------------------------
  * $Log$
 *
 * 02 14 2012 feng.yang
 * removed!
 * .
 *
 * 11 05 2011 feng.yang
 * removed!
 * .
 *
 * 05 03 2011 feng.yang
 * removed!
 * .
 *
 * 04 11 2011 feng.yang
 * removed!
 * .
 *
 * 03 09 2011 yuxiong.feng
 * removed!
 * .
 *
 * 03 09 2011 yuxiong.feng
 * removed!
 * .
  *
  * 
  *
  *------------------------------------------------------------------------------
  * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
  *============================================================================
  ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_EM_CTM_CTA_TDD__


/*----------------------------------------------------------------------------*/
/* Comments                                                            								   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/

#include "EngineerModeConftest.h"

#include "EngineerModeResDef.h"

#include "ps_em_enum.h"

#include "mmi_rp_app_engineermode1_def.h"



#include"EngineerModeUtil.h"

#include "CommonScreens.h"

#include "ShutdownSrvGprot.h"

#include "Wgui_categories_util.h"



/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define MMI_EM_CONF_TEST_MENU_MAP_MAX         (4)
#define MAX_OPERATOR_TEST_ITEMS      (1)
/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
	typedef enum
	{
		MMI_EM_GET_CONF_TEST,
		MMI_EM_SET_CONF_TEST
	}mmi_em_conf_test_cmd_type_enum;
/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

typedef struct
{
	mmi_menu_id menu_id;
	ps_conf_test_mode_enum conf_test_mode;
	U32 test_profile;
}mmi_em_conf_test_menu_map_struct;


/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

static const mmi_em_conf_test_menu_map_struct mmi_em_conf_test_tab[] = 
{
		{MENU_ID_EM_CONFORMANCE_TEST_REALNW,        PS_CONF_TEST_NONE,  0X00000000},
		{MENU_ID_EM_CONFORMANCE_TEST_CTA,           PS_CONF_TEST_CTA,   0X00000000},
		{MENU_ID_EM_CONFORMANCE_TEST_FTA,           PS_CONF_TEST_FTA,   0X00000000},
		{MENU_ID_EM_CONFORMANCE_TEST_IOT,           PS_CONF_TEST_IOT,   0X00000000},
		
#ifdef __MMI_EM_CTA_OPERATOR_TEST__
		{MENU_ID_EM_CONFORMANCE_TEST_OPERATOR_TEST, PS_CONF_TEST_OPERATOR, 0X00000000},
#endif

	//	{MENU_ID_EM_CONFORMANCE_TEST_CTA_INTEGRITY, PS_CONF_TEST_CTA,   CTA_INTEGRITY_CHECK_BIT_FOR_MM},
	//	{MENU_ID_EM_CONFORMANCE_TEST_CTA_RLC,       PS_CONF_TEST_CTA,   CTA_RLC_BIT_FOR_RLC},
	//	{MENU_ID_EM_CONFORMANCE_TEST_CTA_K1297,     PS_CONF_TEST_CTA,   CTA_K1297_BIT_FOR_RRCE},
	//	{MENU_ID_EM_CONFORMANCE_TEST_CTA_SN,        PS_CONF_TEST_CTA,   CTA_SNCONFLICT_BIT_FOR_RLC_RRCE},
	//	{MENU_ID_EM_CONFORMANCE_TEST_CTA_CF,        PS_CONF_TEST_CTA,   CTA_CFQUERY_BIT_FOR_SS}
};


/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

static mmi_em_get_conform_test_param_rsp_struct g_get_rsp_param;
static mmi_em_set_conform_test_param_req_struct g_set_req_param;

U8 g_list_of_states[9] = {0,0,0,0,0,0,0,0,0};
U8 g_list_if_operator_test_states[MAX_OPERATOR_TEST_ITEMS] = {0};

//static mmi_menu_id g_menu_id;
static MMI_ID g_conf_test_id;
static MMI_ID g_conf_test_cta_id;


/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

//static mmi_ret mmi_em_conf_test_get_l4c_data(mmi_menu_id menu_id, mmi_em_conf_test_cmd_type_enum cmd_type);
static void mmi_em_conf_test_send_request(mmi_em_conf_test_cmd_type_enum cmd_type);
static void mmi_em_get_conf_test_res(void *inMsg);
static mmi_ret mmi_em_conf_test_proc(mmi_event_struct *evt);
static void mmi_em_set_conf_test_res(void *inMsg);
static void mmi_em_conf_test_cta_set_special(void);
static  void mmi_em_conf_test_enter_cta(void);
static  void mmi_em_conf_test_set_cta_common(void);

#ifdef  __MMI_EM_CTA_OPERATOR_TEST__

/* For conf test operator test */
static U32 mmi_em_conf_test_gen_operator_test_profile(U8 * list);
static void mmi_em_conf_test_set_operator_test_list(void);
static void mmi_em_conf_test_set_operator_test(MMI_ID gid);
static void mmi_em_conf_test_init_operator_test_status(MMI_ID gid);
static mmi_ret mmi_em_conf_test_operator_test_proc(mmi_event_struct *evt);
static void mmi_em_conf_test_enter_operator_test(void);

#endif

/*******************************************************************************
* Function Realization 
*******************************************************************************/

#ifdef __MMI_EM_CTA_OPERATOR_TEST__

/*  For conf test operator test  */
/*
	Conf test -> Operator test -> XXX
	It is a new item for EM conf test
*/
#define CONF_TEST_OPERATOR_TEST
static U32 mmi_em_conf_test_gen_operator_test_profile(U8 * list)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U8 i;
	U32 bit_mask = 0;
	U32 bit_mask_array[]={
		OPERATOR_TEST_MS_USIM_COMPATIBLE
		};
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for(i=0 ; i<MAX_OPERATOR_TEST_ITEMS; i++)
	{
		if (g_list_if_operator_test_states[i] == 1)
			bit_mask = bit_mask | bit_mask_array[i];
	}
	return bit_mask;
}

static void mmi_em_conf_test_set_operator_test_list(void)
{
	g_set_req_param.conf_test_mode = PS_CONF_TEST_OPERATOR;
	g_set_req_param.test_profile = mmi_em_conf_test_gen_operator_test_profile(g_list_if_operator_test_states);
	mmi_em_conf_test_send_request(MMI_EM_SET_CONF_TEST);
	
}

static void mmi_em_conf_test_set_operator_test(MMI_ID gid)
{   
	cui_menu_get_checkbox_state(gid ,g_list_if_operator_test_states);

	mmi_display_popup_confirm((UI_string_type)GetString(STR_GLOBAL_YES),
        	    (PU8)GetImage(IMG_GLOBAL_YES),
        	    (UI_string_type)GetString(STR_GLOBAL_NO),
        	    (PU8)GetImage(IMG_GLOBAL_NO),
        	    (UI_string_type)GetString(STR_ID_EM_CONFORMANCE_TEST_SELECT_POWER_OFF),
        	    MMI_EVENT_QUERY);
	SetLeftSoftkeyFunction(mmi_em_conf_test_set_operator_test_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

static void mmi_em_conf_test_init_operator_test_status(MMI_ID gid)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bit_mask = 0;
    U8 list_of_operator_test[MAX_OPERATOR_TEST_ITEMS] = {0};

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bit_mask = g_get_rsp_param.test_profile;
	if ((bit_mask & OPERATOR_TEST_MS_USIM_COMPATIBLE) == OPERATOR_TEST_MS_USIM_COMPATIBLE)
    {
        list_of_operator_test[0] = 1;
    }
	cui_menu_set_checkbox_state(gid , list_of_operator_test);   
}

static mmi_ret mmi_em_conf_test_operator_test_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt; 

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	 switch (menu_evt->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
		{
		   mmi_em_conf_test_init_operator_test_status(menu_evt->sender_id);
			break;
		}
		case EVT_ID_CUI_MENU_ITEM_SELECT:
		{
			mmi_em_conf_test_set_operator_test(menu_evt->sender_id);
			cui_menu_close(menu_evt->sender_id);
			break;
		}
		
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
		{
			cui_menu_close(menu_evt->sender_id);
			break;
		}
		case EVT_ID_GROUP_DEINIT:
		{
			mmi_frm_group_close(GRP_ID_CONF_TEST_OPERATOR_TEST);
		}
		default:
		{
			break;
		}
	}

	return MMI_RET_OK;

}

static void mmi_em_conf_test_enter_operator_test(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MMI_ID menu_cui_id;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

	mmi_frm_group_create(GRP_ID_CONF_TEST, GRP_ID_CONF_TEST_OPERATOR_TEST, mmi_em_conf_test_operator_test_proc, NULL);
    mmi_frm_group_enter(GRP_ID_CONF_TEST_OPERATOR_TEST, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    menu_cui_id = cui_menu_create(
            GRP_ID_CONF_TEST_OPERATOR_TEST,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_APPMAIN,
            MENU_ID_EM_CONFORMANCE_TEST_OPERATOR_TEST_2,
            MMI_TRUE,
            NULL);
	 cui_menu_run(menu_cui_id); 
}

#endif /*__MMI_EM_CTA_OPERATOR_TEST__*/


#define OTHERS
/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_conf_test_send_request(mmi_em_conf_test_cmd_type_enum cmd_type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* test */
	mmi_em_set_conform_test_param_req_struct  *msg_set_req;


	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_set_req = OslConstructDataPtr(sizeof(mmi_em_set_conform_test_param_req_struct)); /* alloc contrl buffer for message*/
    
	switch(cmd_type)
	{
		case MMI_EM_GET_CONF_TEST:
		{
			EngineerModeSendMsg(MSG_ID_MMI_EM_GET_CONFORM_TEST_PARAM_REQ, NULL, NULL);
			break;
		}
		case MMI_EM_SET_CONF_TEST:
		{         
            msg_set_req->conf_test_mode =  g_set_req_param.conf_test_mode;
            msg_set_req->test_profile = g_set_req_param.test_profile;    
            EngineerModeSendMsg(MSG_ID_MMI_EM_SET_CONFORM_TEST_PARAM_REQ, msg_set_req, NULL);
			break;
		}
		default:
			break;
	}		
}






/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_get_conf_test_res(void *inMsg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_em_get_conform_test_param_rsp_struct *rsp_p = inMsg;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (rsp_p->result < 0 || rsp_p == NULL)
    {
        mmi_display_popup(
            (UI_string_type)GetString(STR_ID_EM_CONFORMANCE_TEST_GET_DATA_FAIL), 
            MMI_EVENT_FAILURE);
        return;                 /* getting L4C data fail */
    }

    g_get_rsp_param.conf_test_mode = rsp_p->conf_test_mode;
	g_get_rsp_param.test_profile = rsp_p->test_profile;
	g_get_rsp_param.result = rsp_p->result;

	mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_CONF_TEST, mmi_em_conf_test_proc, NULL);
    mmi_frm_group_enter(GRP_ID_CONF_TEST, MMI_FRM_NODE_SMART_CLOSE_FLAG);


    g_conf_test_id = cui_menu_create(
            GRP_ID_CONF_TEST,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_APPMAIN,
            MENU_ID_EM_CONFORMANCE_TEST_2,
            MMI_TRUE,
            NULL);
	 cui_menu_run(g_conf_test_id);
}

/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_set_conf_test_res(void *inMsg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_em_set_conform_test_param_rsp_struct *rsp_p = inMsg;


	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result < 0 || rsp_p == NULL)
	{
		/* un-successful */
		 mmi_display_popup(
            (UI_string_type)GetString(STR_ID_EM_CONFORMANCE_TEST_SET_DATA_FAIL), 
            MMI_EVENT_FAILURE);
	}	
	else if (rsp_p->result >= 0)
	{
		/* successful : power off*/
		srv_shutdown_normal_start(APP_ENGINEERMODE1);
		
	}
	
}

/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
U8 mmi_em_conf_test_get_index(mmi_menu_id menu_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 U8 index = 0;
	 U32 i;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(i=0 ; i<MMI_EM_CONF_TEST_MENU_MAP_MAX ; i++)
	{
		if (menu_id == mmi_em_conf_test_tab[i].menu_id)
		{
			index = i;
			break;
		}
	}
	return index;
	
	
}

/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_conf_test_set_realnw(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 U8 index;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	index = mmi_em_conf_test_get_index(MENU_ID_EM_CONFORMANCE_TEST_REALNW);
	
	g_set_req_param.conf_test_mode = mmi_em_conf_test_tab[index].conf_test_mode;
	g_set_req_param.test_profile = mmi_em_conf_test_tab[index].test_profile;
	mmi_em_conf_test_send_request(MMI_EM_SET_CONF_TEST);
	
}

/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_conf_test_enter_realnw(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_display_popup_confirm((UI_string_type)GetString(STR_GLOBAL_YES),
        	    (PU8)GetImage(IMG_GLOBAL_YES),
        	    (UI_string_type)GetString(STR_GLOBAL_NO),
        	    (PU8)GetImage(IMG_GLOBAL_NO),
        	    (UI_string_type)GetString(STR_ID_EM_CONFORMANCE_TEST_SELECT_POWER_OFF),
        	    MMI_EVENT_QUERY);
	SetLeftSoftkeyFunction(mmi_em_conf_test_set_realnw, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_conf_test_set_fta(void)
{
   	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 U8 index;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	index = mmi_em_conf_test_get_index(MENU_ID_EM_CONFORMANCE_TEST_FTA);
	
	g_set_req_param.conf_test_mode = mmi_em_conf_test_tab[index].conf_test_mode;
	g_set_req_param.test_profile = mmi_em_conf_test_tab[index].test_profile;
	mmi_em_conf_test_send_request(MMI_EM_SET_CONF_TEST); 
}
/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_conf_test_enter_fta(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_display_popup_confirm((UI_string_type)GetString(STR_GLOBAL_YES),
        	    (PU8)GetImage(IMG_GLOBAL_YES),
        	    (UI_string_type)GetString(STR_GLOBAL_NO),
        	    (PU8)GetImage(IMG_GLOBAL_NO),
        	    (UI_string_type)GetString(STR_ID_EM_CONFORMANCE_TEST_SELECT_POWER_OFF),
        	    MMI_EVENT_QUERY);
	SetLeftSoftkeyFunction(mmi_em_conf_test_set_fta, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_conf_test_set_iot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 U8 index;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	index = mmi_em_conf_test_get_index(MENU_ID_EM_CONFORMANCE_TEST_IOT);
	
	g_set_req_param.conf_test_mode = mmi_em_conf_test_tab[index].conf_test_mode;
	g_set_req_param.test_profile = mmi_em_conf_test_tab[index].test_profile;
	mmi_em_conf_test_send_request(MMI_EM_SET_CONF_TEST); 
}


/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_conf_test_enter_iot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_display_popup_confirm((UI_string_type)GetString(STR_GLOBAL_YES),
        	    (PU8)GetImage(IMG_GLOBAL_YES),
        	    (UI_string_type)GetString(STR_GLOBAL_NO),
        	    (PU8)GetImage(IMG_GLOBAL_NO),
        	    (UI_string_type)GetString(STR_ID_EM_CONFORMANCE_TEST_SELECT_POWER_OFF),
        	    MMI_EVENT_QUERY);
	SetLeftSoftkeyFunction(mmi_em_conf_test_set_iot, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);   
}



/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_conf_test_init_cta_status(MMI_ID gid)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 bit_mask;
    U8 list_of_states[9] = {0,0,0,0,0,0,0,0,0};

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bit_mask = g_get_rsp_param.test_profile;
    if ((bit_mask & CTA_INTEGRITY_CHECK_BIT_FOR_MM) == CTA_INTEGRITY_CHECK_BIT_FOR_MM)
    {
        list_of_states[0] = 1;
    }
    if ((bit_mask & CTA_TL1_BIT_FOR_TL1) == CTA_TL1_BIT_FOR_TL1)
    {
        list_of_states[1] = 1;
    }
    if ((bit_mask & CTA_K1297_BIT_FOR_RRCE) == CTA_K1297_BIT_FOR_RRCE)
    {
        list_of_states[2] = 1;
    }
    if ((bit_mask & CTA_SNCONFLICT_BIT_FOR_RLC_RRCE) == CTA_SNCONFLICT_BIT_FOR_RLC_RRCE)
    {
        list_of_states[3] = 1;
    }
    if ((bit_mask & CTA_CFQUERY_BIT_FOR_SS) == CTA_CFQUERY_BIT_FOR_SS)
    {
        list_of_states[4] = 1;
    }
    if ((bit_mask & CTA_PLMN_LOCK_BIT_FOR_CSCE) == CTA_PLMN_LOCK_BIT_FOR_CSCE)
    {
        list_of_states[5] = 1;
    }
    if ((bit_mask & CTA_OPEN_MEAS_BIT_FOR_CSCE) == CTA_OPEN_MEAS_BIT_FOR_CSCE)
    {
        list_of_states[6] = 1;
    }
    if ((bit_mask & CTA_DISABLE_DPA_BIT_FOR_RRCE) == CTA_DISABLE_DPA_BIT_FOR_RRCE)
    {
        list_of_states[7] = 1;
    }
    if ((bit_mask & CTA_OPEN_INVALID_INTRA_CELL_REPORT__BIT_FOR_MEME) == CTA_OPEN_INVALID_INTRA_CELL_REPORT__BIT_FOR_MEME)
    {
        list_of_states[8] = 1;
    }
    cui_menu_set_checkbox_state(gid , list_of_states);   
}

/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_conf_test_cta_special(MMI_ID gid)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 cnt = 0;
    UI_string_type string;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

        cui_menu_get_checkbox_state(gid ,g_list_of_states);

    for(i=0; i<9; i++)
    {
        if(g_list_of_states[i] == 1)
            cnt++;
    }

    if (cnt == 0)
    {
        string = (UI_string_type)GetString(STR_ID_EM_CONFORMANCE_TEST_SELECT_COMMON_POWER_OFF);
    }
    else if (cnt > 1)
    {
        string = (UI_string_type)GetString(STR_ID_EM_CONFORMANCE_TEST_SELECT_MULTIPLE_POWER_OFF);
    }
    else
    {
        string = (UI_string_type)GetString(STR_ID_EM_CONFORMANCE_TEST_SELECT_POWER_OFF);
    }
    
	mmi_display_popup_confirm((UI_string_type)GetString(STR_GLOBAL_YES),
        	    (PU8)GetImage(IMG_GLOBAL_YES),
        	    (UI_string_type)GetString(STR_GLOBAL_NO),
        	    (PU8)GetImage(IMG_GLOBAL_NO),
        	    string,
        	    MMI_EVENT_QUERY);
	SetLeftSoftkeyFunction(mmi_em_conf_test_cta_set_special, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}

/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_conf_test_cta_set_special(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i;
    U32 bit_mask = 0;
    U32 bit_mask_array[]={
        CTA_INTEGRITY_CHECK_BIT_FOR_MM ,        
        CTA_TL1_BIT_FOR_TL1,                      
        CTA_K1297_BIT_FOR_RRCE,                   
        CTA_SNCONFLICT_BIT_FOR_RLC_RRCE,          
        CTA_CFQUERY_BIT_FOR_SS,
        CTA_PLMN_LOCK_BIT_FOR_CSCE,              
        CTA_OPEN_MEAS_BIT_FOR_CSCE,              
        CTA_DISABLE_DPA_BIT_FOR_RRCE,            
        CTA_OPEN_INVALID_INTRA_CELL_REPORT__BIT_FOR_MEME};                 

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  


    for(i=0 ; i<9; i++)
    {
        if (g_list_of_states[i] == 1)
            bit_mask = bit_mask | bit_mask_array[i];
    }

    g_set_req_param.conf_test_mode = PS_CONF_TEST_CTA;
    g_set_req_param.test_profile = bit_mask;

    mmi_em_conf_test_send_request(MMI_EM_SET_CONF_TEST);
    
    
}

/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static mmi_ret mmi_em_conf_test_cta_proc(mmi_event_struct *evt)
{
	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt; 

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
           mmi_em_conf_test_init_cta_status(menu_evt->sender_id);
            break;
        }

		case EVT_ID_CUI_MENU_ITEM_SELECT:
		{
			mmi_em_conf_test_cta_special(menu_evt->sender_id);
            cui_menu_close(menu_evt->sender_id);
			break;
		}
        

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
			cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
        {
            break;
        }
    }

    return MMI_RET_OK;
	
}



static void mmi_em_conf_test_enter_cta_special(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    mmi_frm_scrn_close_active_id();
    mmi_frm_group_create(GRP_ID_CONF_TEST, GRP_ID_CONF_TEST_CTA, mmi_em_conf_test_cta_proc, NULL);
    mmi_frm_group_enter(GRP_ID_CONF_TEST_CTA, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    

    g_conf_test_cta_id = cui_menu_create(
            GRP_ID_CONF_TEST_CTA,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_APPMAIN,
            MENU_ID_EM_CONFORMANCE_TEST_CTA,
            MMI_TRUE,
            NULL);
	 cui_menu_run(g_conf_test_cta_id);
    
}



static  void mmi_em_conf_test_set_cta_common(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 U8 index;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	index = mmi_em_conf_test_get_index(MENU_ID_EM_CONFORMANCE_TEST_CTA);
	
	g_set_req_param.conf_test_mode = mmi_em_conf_test_tab[index].conf_test_mode;
	g_set_req_param.test_profile = mmi_em_conf_test_tab[index].test_profile;
	mmi_em_conf_test_send_request(MMI_EM_SET_CONF_TEST); 
    
}

/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static  void mmi_em_conf_test_enter_cta(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_display_popup_confirm((UI_string_type)GetString(STR_GLOBAL_YES),
        	    (PU8)GetImage(IMG_GLOBAL_YES),
        	    (UI_string_type)GetString(STR_GLOBAL_NO),
        	    (PU8)GetImage(IMG_GLOBAL_NO),
        	    (UI_string_type)GetString(STR_ID_EM_CONFORMANCE_TEST_SELECT_COMMON_POWER_OFF),
        	    MMI_EVENT_QUERY);
	SetLeftSoftkeyFunction(mmi_em_conf_test_set_cta_common, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_em_conf_test_enter_cta_special, KEY_EVENT_UP);

/*
    mmi_frm_group_create(GRP_ID_CONF_TEST, GRP_ID_CONF_TEST_CTA, mmi_em_conf_test_cta_proc, NULL);
    mmi_frm_group_enter(GRP_ID_CONF_TEST_CTA, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    

    g_conf_test_cta_id = cui_menu_create(
            GRP_ID_CONF_TEST_CTA,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_APPMAIN,
            MENU_ID_EM_CONFORMANCE_TEST_CTA,
            MMI_TRUE,
            NULL);
	 cui_menu_run(g_conf_test_cta_id);
	 */
	

}



/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static mmi_ret mmi_em_conf_test_select_mainmenu_proc(mmi_menu_id menu_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (menu_id)
	{
		case MENU_ID_EM_CONFORMANCE_TEST_REALNW:
		{
			mmi_em_conf_test_enter_realnw();	/*Set Real NW*/		
			break;
		}
		case MENU_ID_EM_CONFORMANCE_TEST_CTA:
		{
			mmi_em_conf_test_enter_cta();       /*enter CTA*/
			break;
		}
		case MENU_ID_EM_CONFORMANCE_TEST_FTA:
		{
            mmi_em_conf_test_enter_fta();	   /*Set FTA (common) --tmp*/	
            break;
		}
		case MENU_ID_EM_CONFORMANCE_TEST_IOT:
		{
            mmi_em_conf_test_enter_iot();	   /*Set IOT (common) --tmp*/
			break;
		}
		
		
#ifdef __MMI_EM_CTA_OPERATOR_TEST__
		case MENU_ID_EM_CONFORMANCE_TEST_OPERATOR_TEST:
		{
			mmi_em_conf_test_enter_operator_test();      /*Set Ms USIM_COMPATIBLE*/
			break;
		}
#endif


		default:
			break;
	}

    return MMI_RET_OK;
	
}


/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static mmi_ret mmi_em_conf_test_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);			
			cui_menu_set_currlist_highlighted_id(g_conf_test_id ,mmi_em_conf_test_tab[g_get_rsp_param.conf_test_mode - PS_CONF_TEST_NONE].menu_id);  /* Show setting status */
            //cui_menu_get_currlist_menu_id_from_index( menu_evt->sender_id, g_get_rsp_param.conf_test_mode - PS_CONF_TEST_NONE)
            break;
        }

		case EVT_ID_CUI_MENU_ITEM_SELECT:
		{
			mmi_em_conf_test_select_mainmenu_proc(menu_evt->highlighted_menu_id);
			break;
		}



        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
			cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
        {
            break;
        }
    }

    return MMI_RET_OK;
}
//#error "fddffd"
/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_conf_test_enter_main()
{

	 mmi_em_conf_test_send_request(MMI_EM_GET_CONF_TEST);   /*get setting val from L4C ,and it can only be called once*/
}

/*****************************************************************************              
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void mmi_em_conf_test_highlight_hdlr(cui_menu_event_struct *event)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Init */
  //  mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_GET_CONFORM_TEST_PARAM_RSP ,mmi_em_get_conf_test_res ,MMI_FALSE);
  //  mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_SET_CONFORM_TEST_PARAM_RSP ,mmi_em_set_conf_test_res, MMI_FALSE);
  //  SetLeftSoftkeyFunction(mmi_em_conf_test_enter_main, KEY_EVENT_UP); 

    switch(event->highlighted_menu_id)
    {
        case MENU_ID_EM_CONFORMANCE_TEST:
        {
           mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_GET_CONFORM_TEST_PARAM_RSP ,mmi_em_get_conf_test_res ,MMI_FALSE);
           mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_SET_CONFORM_TEST_PARAM_RSP ,mmi_em_set_conf_test_res, MMI_FALSE);
           mmi_em_conf_test_enter_main();
        }
    }
}



#endif /*__MMI_EM_CTM_CTA_TDD__*/



