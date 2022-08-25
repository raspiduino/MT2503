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
 *    SyncmlOTAP.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML OTA provisioning appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================== 
 *******************************************************************************/

/*****************************************************************************
* Include
*****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_SYNCML_CCA_SUPPORT__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "cbm_consts.h"
#include "custom_mmi_default_value.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMI_conn_app_trc.h"
#include "mmi_conn_app_trc.h"
#include "kal_trace.h"
#include "mmi_frm_mem_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "Unicodexdcl.h"
#include "mmi_rp_srv_syncml_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "string.h"
#include "stack_config.h"
#include "mmi_frm_events_gprot.h"
#include "CustDataRes.h"
#include "stdio.h"
#include "wgui_categories_util.h"
#include "wgui_categories_text_viewer.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "GlobalConstants.h"
#include "AlertScreen.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "wgui_categories_list.h"
#include "cbm_api.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "conversions.h" 
#include "CommonScreens.h"
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include <ctype.h> 

#include "CentralConfigAgentGProt.h"  
#include "mmi_rp_app_cca_def.h"
#include "ccasrvgprot.h"

#include "mmi2syncml_struct.h"
#include "dtcntsrvgprot.h"
#include "DataAccountGProt.h"
#include "app_url.h"

#include "NwUsabSrvGprot.h"



/******************************************************************************
 *	Define
 ******************************************************************************/
#define MMI_SYNCML_OTA_NO_PROXY "@CCA@GEN@"
#define MMI_SYNCML_OTA_CAL_NAME_TOTAL  2
#define MMI_SYNCML_OTA_TASK_NAME_TOTAL 1


/******************************************************************************
 *	Static function declaration
 ******************************************************************************/
static mmi_syncml_ota_cntx_struct *mmi_syncml_new_ota_cntx(U16 conf_id, S32 doc_hdl);

static void mmi_syncml_cca_config_rsp(cca_status_enum status);
static S16 mmi_syncml_new_otap_profile(mmi_syncml_ota_cntx_struct *cntx);
static void mmi_syncml_init_slim_profile(mmi_syncml_account_struct *prof);
static U8 mmi_syncml_get_valid_profile_num(void);
static void mmi_syncml_entry_installation(void);
static void mmi_syncml_find_empty_profile(void);
static void mmi_syncml_next_profile(void);
static void mmi_syncml_entry_replacement(void);
static void mmi_syncml_free_syncml_ota_cntx(void);
static void mmi_syncml_replace_profile(void);
static void mmi_syncml_replacement_highlight_hdlr(S32 index);
static void mmi_syncml_show_info(U16 msg_id);
static void mmi_syncml_goback_from_replace_screen(void);
static void mmi_syncml_exit_install(void);
static void mmi_syncml_display_skip_confirm(void);
//static S32 mmi_syncml_atoi_for_ipaddr(const S8 *s);
static CHAR* mmi_syncml_stristr(const CHAR *src_str, const CHAR *tbf_str);
static mmi_ret mmi_syncml_group_otap_install_proc(mmi_event_struct * param);

static cca_status_enum mmi_syncml_proc_cca_nodes
(
	S32 doc_hdl, 
	S32 node_hdl, 
	U16 symbol, 
	cca_iterator_struct *param_list, 
	void *user_data
);

static void mmi_syncml_set_proxy_for_account
(
	mmi_syncml_ota_cntx_struct *cntx,  
	S16 index_prof
);

static cca_status_enum mmi_syncml_parser_node_proxy
(
	mmi_syncml_ota_proxy_cntx_struct* new_proxy,
	cca_iterator_struct *param_list,
	void* usr_data
);

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
static cca_status_enum mmi_syncml_parser_node_bootstrap
(
	cca_iterator_struct *param_list,
	void *usr_data
);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

static cca_status_enum mmi_syncml_parser_node_app
(
	mmi_syncml_account_struct* new_account,
	cca_iterator_struct *param_list,
	U8 prof_idx,
	void *usr_data
);

static cca_status_enum mmi_syncml_parser_node_app_addr
(
	mmi_syncml_account_struct* new_account,
	cca_iterator_struct *param_list
);

static cca_status_enum mmi_syncml_parser_node_app_authinfo
(
	mmi_syncml_account_struct* new_account,
	cca_iterator_struct *param_list
);

static cca_status_enum mmi_syncml_parser_node_resource
(
	mmi_syncml_account_struct* new_prof,
    cca_iterator_struct *param_list
);

static MMI_BOOL mmi_syncml_check_string
(
	CHAR* out_buff, 
	const CHAR* in_buff, 
	U8 max_len, 
	MMI_BOOL trunk_flag
);

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
static U8 mmi_syncml_is_update_match
(
	mmi_syncml_account_struct *new_prof,
	void* usr_data
);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

static U8 mmi_syncml_get_db_type(const CHAR* db_name);

static cbm_sim_id_enum syncml_ota_sim_cca2cbm(mmi_sim_enum cca_sim_id);
static mmi_sim_enum syncml_ota_sim_cbm2cca(cbm_sim_id_enum cbm_sim_id);

static MMI_BOOL mmi_syncml_is_empty_profile(U8 record_id);
static MMI_BOOL mmi_syncml_install_new_account(U8 idx);
static MMI_BOOL mmi_syncml_is_ascii_format(CHAR *dest);
static void mmi_syncml_skip_profile_yes(void);
static void mmi_syncml_finish_provisioing_hdlr(void);


/******************************************************************************
 *	Global Function declaration
 ******************************************************************************/
extern CHAR *syncml_itoa(S32 value, CHAR *s, S32 radix);
extern int applib_url_check_ip(const char* addr , int len);


/******************************************************************************
 * Static variable declaration
 ******************************************************************************/
static const U16 mmi_cca_syncml_map_tbl[] = 
 {
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, 
    	MMI_CCA_NS_SYNCML_PROXY,0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PORT, 
    	MMI_CCA_NS_SYNCML_PORT, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PXAUTHINFO, 
    	MMI_CCA_NS_SYNCML_PXAUTHINFO, 0xFFFF, 
    CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF,
    	MMI_CCA_NS_SYNCML_NAPDEF, 0xFFFF,
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    CCA_NS_TRIGNODE, CCA_NS_OMA_BOOTSTRAP,
    	MMI_CCA_NS_SYNCML_BOOTSTRAP, 0xFFFF,
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION,
    	MMI_CCA_NS_SYNCML_APPLICATION, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPADDR,
    	MMI_CCA_NS_SYNCML_APPADDR, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPAUTH, 
    	MMI_CCA_NS_SYNCML_APPAUTH, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_RESOURCE,
    	MMI_CCA_NS_SYNCML_RESOURCE,0xFFFF
 };

/*
 * Task and Calendar db has the same mime type, 
 * so SyncmlOTA do opaque match under the fllowing two tables.
 */
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
static const CHAR mmi_syncml_cal_dbname[MMI_SYNCML_OTA_CAL_NAME_TOTAL][MAX_SYNCML_DATABASE_ADDR_LEN] = 
{
    "event",
	"cal",
};
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
static const CHAR mmi_syncml_task_dbname[MMI_SYNCML_OTA_TASK_NAME_TOTAL][MAX_SYNCML_DATABASE_ADDR_LEN] = 
{
    "task",
};
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

static mmi_syncml_ota_cntx_struct *g_syncml_ota_context;
static U8 g_syncml_ota_next_profile;

/* only for dm update */
static MMI_BOOL g_syncml_ota_use_proxy_flag; 
/*
 * For the sake of read-only profile, 
 * map name to index at the replacement screen. 
 */
static U8 g_syncml_name_idx_map_tbl[MMI_MAX_SYNCML_ACCOUNTS];


/*****************************************************************************
 * Function definition
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to syncml
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_proc_cca_doc(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_configure_ind_struct* new_doc;
    mmi_syncml_account_struct *temp_nvram_buf;  
    U8 i;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_doc = (mmi_cca_app_configure_ind_struct*)param;
    MMI_ASSERT(new_doc != NULL);
    
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_PROC_CCA, new_doc->config_id, new_doc->hConfig);
    
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	/* check the provisioning type */
    if (new_doc->prov_type != MMI_CCA_PROV_TYPE_OTA_PROV)
	{
		mmi_syncml_cca_config_rsp(CCA_STATUS_INVALID_SETTING);
		return;
	}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    /* Init control block and save the ID/handle for the response msg.*/
    g_syncml_ota_context = mmi_syncml_new_ota_cntx(new_doc->config_id, new_doc->hConfig);   
    g_syncml_ota_context->sim_id = (U16)syncml_ota_sim_cca2cbm((mmi_sim_enum)new_doc->sim_id); /* config sim id */

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    g_syncml_ota_context->prov_flag = new_doc->prov_flag;
#endif

    /* this flag is to control re-entry SCR_ID_SYNC_OTA_PROFILE_INSTALL 
	 * for installing next profile. 
	 */
    g_syncml_ota_next_profile = 0;   
    /* Extract data syncml settings from CCA configuration document, and store 
       settings in the temporary storage. */
    mmi_cca_doc_process(
                new_doc->hConfig, 
                mmi_cca_syncml_map_tbl,
                sizeof(mmi_cca_syncml_map_tbl) / sizeof(U16),
                NULL, 
                mmi_syncml_proc_cca_nodes, 
                g_syncml_ota_context);
    
    /* No valid profile */
    if (mmi_syncml_get_valid_profile_num() == 0 || g_syncml_ota_context->total_valid == 0) 
    {        
        /* Now, terminate the SYNCML OTA provisioning application. */
        mmi_syncml_cca_config_rsp(CCA_STATUS_INVALID_SETTING);
        mmi_syncml_free_syncml_ota_cntx();
        return;
    }

    /* Setup callback to free memory and send message back to CCA when users
       press END key and return to idle screen, or when the app exits. */
    /*read current profile name list from NVRAM*/
    temp_nvram_buf = (mmi_syncml_account_struct *)OslMalloc(sizeof(mmi_syncml_account_struct));
    if (temp_nvram_buf == NULL) 
    {
        mmi_syncml_cca_config_rsp(CCA_STATUS_FAIL);
        mmi_syncml_free_syncml_ota_cntx();
        return;
    }
   
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {    
        mmi_syncml_read_account_from_nvram((U8)(i + 1), (void*)temp_nvram_buf);
        mmi_ucs2cpy((CHAR *)g_syncml_ota_context->currentprofnamelist[i],(CHAR *)temp_nvram_buf->account_name);
    }
    
    OslMfree(temp_nvram_buf);
    
    /* Ready to install profiles. */
    mmi_frm_group_create(mmi_cca_get_root_group(), GRP_ID_SYNC_OTAP_INSTALL, mmi_syncml_group_otap_install_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SYNC_OTAP_INSTALL, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_syncml_entry_installation();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_group_otap_install_proc
 * DESCRIPTION
 *  This function allocates and initializes the control block of SYNCML OTA
 *  provisioning application.
 * PARAMETERS
 *  cca_sim_id		[IN]
 * RETURNS
 *  Return cca sim id
 *****************************************************************************/
static mmi_ret mmi_syncml_group_otap_install_proc(mmi_event_struct * param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        {
            /* provisioning complete normally */
            if(g_syncml_ota_context->iter >= g_syncml_ota_context->num_profiles)
            {
                mmi_syncml_finish_provisioing_hdlr();
            }
            /* abort install by goback from installation or replacement */
            else
            {
                mmi_syncml_exit_install();
            }
            break;
        }
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        {
            /* abort install by press endkey */
            mmi_syncml_exit_install();
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_syncml_free_syncml_ota_cntx();
            break;
        }
        default:
            break;
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  syncml_ota_sim_cca2cbm
 * DESCRIPTION
 *  This function allocates and initializes the control block of SYNCML OTA
 *  provisioning application.
 * PARAMETERS
 *  cca_sim_id		[IN]
 * RETURNS
 *  Return cca sim id
 *****************************************************************************/
static cbm_sim_id_enum syncml_ota_sim_cca2cbm(mmi_sim_enum cca_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_sim_id_enum new_sim_id = CBM_SIM_ID_SIM1;//cbm_sim_id_enum new_sim_id = MMI_SIM1; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cca_sim_id == MMI_SIM_NONE)
    {
        cca_sim_id = srv_nw_usab_get_one_usable_sim();
    }

    switch(cca_sim_id)
    {
        case MMI_SIM1:
            new_sim_id = CBM_SIM_ID_SIM1;
            break;
        case MMI_SIM2:
            new_sim_id = CBM_SIM_ID_SIM2;
            break;
        case MMI_SIM3:
            new_sim_id = CBM_SIM_ID_SIM3;
            break;
        case MMI_SIM4:
            new_sim_id = CBM_SIM_ID_SIM4;
            break;
        default:
            break;
    }
    
    return new_sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  syncml_ota_sim_cca2cbm
 * DESCRIPTION
 *  This function allocates and initializes the control block of SYNCML OTA
 *  provisioning application.
 * PARAMETERS
 *  cca_sim_id		[IN]
 * RETURNS
 *  Return cca sim id
 *****************************************************************************/
static mmi_sim_enum syncml_ota_sim_cbm2cca(cbm_sim_id_enum cbm_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_sim_enum new_sim_id = MMI_SIM1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(cbm_sim_id)
    {
        case CBM_SIM_ID_SIM1:
            new_sim_id = MMI_SIM1;
            break;
        case CBM_SIM_ID_SIM2:
            new_sim_id = MMI_SIM2;
            break;
        case CBM_SIM_ID_SIM3:
            new_sim_id = MMI_SIM3;
            break;
        case CBM_SIM_ID_SIM4:
            new_sim_id = MMI_SIM4;
            break;
        default:
            break;
    }
    return new_sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_new_ota_cntx
 * DESCRIPTION
 *  This function allocates and initializes the control block of SYNCML OTA
 *  provisioning application.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  On success, return the address of control block. On error, return NULL.
 *****************************************************************************/
static mmi_syncml_ota_cntx_struct *mmi_syncml_new_ota_cntx(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_ota_cntx_struct *cntx;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_NEW_OTA_CNTX );
    cntx = (mmi_syncml_ota_cntx_struct *)OslMalloc(sizeof(mmi_syncml_ota_cntx_struct));
    if (cntx == NULL) 
    {
        MMI_ASSERT(!"SyncmlOta Malloc Error!");
    }
    
    memset(cntx, 0, sizeof(mmi_syncml_ota_cntx_struct));
    /* Save the identifier for this configuration process. */
    cntx->conf_id = conf_id;
    cntx->doc_hdl = doc_hdl;
    /* Initialize the index for replacement to an invalid index. */
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++) 
    {
        cntx->dst_idx[i] = SYNCML_INVALID_IDX;
    }    
    return cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_proc_cca_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]            Configuration document handle
 *  node_hdl        [IN]            The node handle
 *  symbol          [IN]            The converted node symbol
 *  param_list      [IN]            List of parameters in the node
 *  user_data       [IN]            User data         
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
static cca_status_enum mmi_syncml_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_ota_proxy_cntx_struct *new_proxy;
    mmi_syncml_account_struct *new_prof;
    mmi_syncml_ota_cntx_struct *cntx;
    
    cca_status_enum status = CCA_STATUS_OK;
    S16 index_profile;
	S16 index_proxy;
	    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_syncml_ota_cntx_struct*)user_data;
    index_profile = cntx->num_profiles;
    index_proxy = cntx->num_proxy;
    
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_CCA_NODES, symbol);
    switch (symbol)
    {
    		
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
		case MMI_CCA_NS_SYNCML_BOOTSTRAP:
		{
			/* for TPS */
			status = mmi_syncml_parser_node_bootstrap(param_list, user_data);
			break;
		}
#endif

        case MMI_CCA_NS_SYNCML_PROXY:
		{
            if ((cntx->num_proxy + 1) > MMI_MAX_SYNCML_ACCOUNTS)
            {
                return CCA_STATUS_OK;
            }
            new_proxy = &cntx->proxy[index_proxy];
            status = mmi_syncml_parser_node_proxy(new_proxy, param_list, user_data);
			if (status != CCA_STATUS_OK)
			{
				return status;
			}
            break;
        }   
        
        case MMI_CCA_NS_SYNCML_APPLICATION:
        {
            /* When start process this node,we predefine all the node proxy have already been processed */            
            /* Prepare a storage for the new profile. And get the new index. */
            if ((index_profile = mmi_syncml_new_otap_profile(cntx)) < 0)
            {
                return CCA_STATUS_FAIL;
            }
            
            cntx->num_profiles++;
            new_prof = cntx->profile[index_profile];
			status = mmi_syncml_parser_node_app(new_prof, param_list, (U8)index_profile, user_data);
            if (status != CCA_STATUS_OK)
        	{
        		cntx->isvalidprof[index_profile] = MMI_FALSE;
        		return status;
        	}
            else
            {
                cntx->isvalidprof[index_profile] = MMI_TRUE;
                
                /* config proxy for account */
    			mmi_syncml_set_proxy_for_account(cntx, index_profile);
            }
            break;
        }

		/* for oma dm update */
        case MMI_CCA_NS_SYNCML_APPADDR:
		{
            new_prof = cntx->profile[index_profile - 1];
			status = mmi_syncml_parser_node_app_addr(new_prof, param_list);
            if (status != CCA_STATUS_OK)
        	{
        		cntx->isvalidprof[index_profile] = MMI_FALSE;
        		return status;
        	}

			break;
		}
		
        case MMI_CCA_NS_SYNCML_APPAUTH:
        {
			if (!cntx->isvalidprof[index_profile - 1])
			{
				break;
			}
			
            new_prof = cntx->profile[index_profile - 1];
            status = mmi_syncml_parser_node_app_authinfo(new_prof, param_list);
			if (status != CCA_STATUS_OK)
			{
				cntx->isvalidprof[index_profile - 1] = MMI_FALSE;
			}
            break;
        }
        
        case MMI_CCA_NS_SYNCML_RESOURCE:
        {
			if (!cntx->isvalidprof[index_profile - 1])
			{
				break;
			}
            new_prof = cntx->profile[index_profile - 1];
            status = mmi_syncml_parser_node_resource(new_prof, param_list);
            break;          
        }
        
        default:
            return CCA_STATUS_OK;
                        
    }
    
    return status;
}


#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_parser_node_bootstrap
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  cntx        ota context ptr
 *  index_prof  the target profile index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static cca_status_enum mmi_syncml_parser_node_bootstrap
(
	cca_iterator_struct *param_list,
	void *usr_data
)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_ota_cntx_struct *cntx;
	cca_core_data_struct *param;
	cca_status_enum state = CCA_STATUS_OK;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(param_list != NULL && usr_data != NULL);
	cntx = (mmi_syncml_ota_cntx_struct*)usr_data;
	
	/* Only get the first provurl*/
	if (cntx->opr_flag & SYNCML_OTA_OPR_PROV_MASK)
	{
		return CCA_STATUS_OK;
	}
	else
	{
		cntx->opr_flag |= SYNCML_OTA_OPR_PROV_MASK;
	}
	
	while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
	{
        switch (param->id)
        {                 				
        	case CCA_NS_OMA_PROVURL: /* for (TPS) (Trusted Provisioning Server) */
				if (param->values.s[0] != NULL && strlen(param->values.s[0]) > 0)
				{
					state = 
						mmi_cca_generate_hash_value(param->values.s[0], 
												    cntx->prov_url_hash,
												    MAX_SYNCML_HASH_BUF_LEN);

					if (state != CCA_STATUS_OK)
				 	{
				 		memcpy(cntx->prov_url_hash, "\0", 1);
				 	}
				}
				else 
				{
					memcpy(cntx->prov_url_hash, "\0", 1);
				}
				break;
				
			default:
				break;
        }
	}
    
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_PARSE_BOOTSTRAP, cntx->opr_flag, state);
    
	return CCA_STATUS_OK;
}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_parser_node_app
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  cntx        ota context ptr
 *  index_prof  the target profile index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static cca_status_enum mmi_syncml_parser_node_app
(
	mmi_syncml_account_struct* new_account,
	cca_iterator_struct *param_list,
	U8 prof_idx,
	void *usr_data
)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_ota_cntx_struct *cntx;
	cca_core_data_struct *param;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(new_account != NULL && param_list != NULL && usr_data != NULL);
	cntx = (mmi_syncml_ota_cntx_struct*)usr_data;
	
    while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
    {   
        switch (param->id)
        {
            case CCA_NS_OMA_APPID:
                /*syncml appid is "w5" */
                if (param->values.s[0] != NULL)
                {
                    if (strcmp((CHAR *)param->values.s[0], (CHAR *)"w5") != 0)
                    {
                        return CCA_STATUS_FAIL;
                    }
                    
                }
                break;
        
            case CCA_NS_OMA_NAME: 
                if (strlen(param->values.s[0]) > 0)
                {
					mmi_chset_utf8_to_ucs2_string(
                        new_account->account_name, 
						MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH, 
						(U8 *)param->values.s[0]);
                }
                break;
        
            case CCA_NS_OMA_TO_PROXY:
				mmi_syncml_check_string((CHAR*)&cntx->app_to_proxy[prof_idx], 
										param->values.s[0], 
										MAX_SYNCML_PROXY_ID_LEN,
										MMI_TRUE);
                break;
                
            case CCA_NS_OMA_ADDR:
				cntx->isvalidprof[prof_idx] = 
					mmi_syncml_check_string((CHAR*)&new_account->server_address, 
											param->values.s[0], 
											MAX_SYNCML_SERVER_ADDR_LEN,
											MMI_FALSE);
			
                break;

				
            default:
                break;
				
        } /* switch */
    } /* while */

	return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_parser_node_app_addr
 * DESCRIPTION
 *  parse appaddress node from OMA DM
 * PARAMETERS
 *  new_account        [IN]		profile info
 *  param_list  	   [IN]		param list
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
static cca_status_enum mmi_syncml_parser_node_app_addr
(
	mmi_syncml_account_struct* new_account,
	cca_iterator_struct *param_list
)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cca_core_data_struct *param;
	cca_status_enum status;
	MMI_BOOL ret = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(new_account != NULL && param_list != NULL);
	
    while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
    {   
        switch (param->id)
        {
            case CCA_NS_OMA_ADDR:			
				ret = mmi_syncml_check_string((CHAR*)&new_account->server_address, 
											param->values.s[0], 
											MAX_SYNCML_SERVER_ADDR_LEN,
											MMI_FALSE);

                break;
				
			default:
				break;
    	}
	}
	
	if (ret)
	{
		status = CCA_STATUS_OK;
	}
	else
	{
		status = CCA_STATUS_FAIL;
	}
	MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_PARSE_APP_ADDR, status);
	return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_parser_node_app_authinfo
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  new_account        [IN]		profile info
 *  param_list  	   [IN]		param list
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static cca_status_enum mmi_syncml_parser_node_app_authinfo
(
	mmi_syncml_account_struct* new_account,
	cca_iterator_struct *param_list
)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cca_core_data_struct *param;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(new_account != NULL && param_list != NULL);
	
    while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
    {   
        switch (param->id)
        {
            case CCA_NS_OMA_AAUTHLEVEL: 
                /*Predefine this param is received earlier than any other params of this node.
                If authlevel is not CCA_NS_VAL_CLIENT,we pass this node*/
                 if (param->values.i[0] != 0)
                 {
                    if (param->values.i[0] != CCA_NS_VAL_CLIENT)
                    {
                        MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_PARSE_APP_ADDR_AUTH, param->values.i[0]);
                        return CCA_STATUS_FAIL;
                    }
                 } 
                break;    
                 
            case CCA_NS_OMA_AAUTHNAME:
				mmi_syncml_check_string((CHAR*)&new_account->server_username, 
				     					param->values.s[0], 
										MAX_SYNCML_USERNAME,
										MMI_TRUE);						
                break;
                
            case CCA_NS_OMA_AAUTHSECRET:
				mmi_syncml_check_string((CHAR*)&new_account->server_password, 
										param->values.s[0], 
										MAX_SYNCML_PASSWORD,
										MMI_TRUE);						
                break;            

            default:
                break;
                
        }
    }
	
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_parser_node_proxy
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  cntx        ota context ptr
 *  index_prof  the target profile index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static cca_status_enum mmi_syncml_parser_node_proxy
(
	mmi_syncml_ota_proxy_cntx_struct* new_proxy,
	cca_iterator_struct *param_list,
	void* usr_data
)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cca_core_data_struct *param;
	cca_status_enum cca_state = CCA_STATUS_FAIL;
	mmi_syncml_ota_cntx_struct *cntx;
	U8 barer_type;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(new_proxy != NULL && param_list != NULL && usr_data != NULL);
	cntx = (mmi_syncml_ota_cntx_struct*)usr_data;
	
    while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
    {   
        switch (param->id)
        {
            case CCA_NS_OMA_PROXY_ID:
			{
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
				if (strlen(param->values.s[0]) > 0 && mmi_syncml_is_ascii_format(param->values.s[0]))
				{
					cca_state = 
						mmi_cca_generate_hash_value(param->values.s[0], 
												    new_proxy->proxy_id_hash, 
													MAX_SYNCML_HASH_BUF_LEN);
					if (cca_state != CCA_STATUS_OK)
					{
						memcpy((void*)&new_proxy->proxy_id_hash, "\0", 1);
					}
				}
				else
				{
					memcpy((void*)&new_proxy->proxy_id_hash, "\0", 1);
				}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

             	mmi_syncml_check_string((CHAR*)&new_proxy->proxy_id, 
										param->values.s[0], 
										MAX_SYNCML_PROXY_ID_LEN,
										MMI_TRUE);
                break;
        	}  

            case CCA_NS_DATAACCTID:
            {
                /* If data isn't ABM_E_SOCKET_BEARER_GSM_GPRS ,we pass this node */
                barer_type = srv_dtcnt_get_bearer_type(param->values.i[0], SRV_DTCNT_ACCOUNT_PRIMARY);
                
                MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_PARSE_PROXY, barer_type, param->values.i[0]);
                
				if (barer_type != SRV_DTCNT_BEARER_GPRS && barer_type != SRV_DTCNT_BEARER_WIFI)
				{
					memset(new_proxy, 0, sizeof(mmi_syncml_ota_proxy_cntx_struct));
					return CCA_STATUS_FAIL;
				}
				else
                {
                    new_proxy->valid = MMI_TRUE;
                    cntx->num_proxy++;
                  	new_proxy->dataaccountid = (U32)param->values.i[0];
                }
                break;  
            }
            
            default:
                break;
                
        }                
    }

	return cca_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_parser_node_resource
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  cntx        ota context ptr
 *  index_prof  the target profile index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static cca_status_enum mmi_syncml_parser_node_resource(mmi_syncml_account_struct* new_prof,
													   cca_iterator_struct *param_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cca_core_data_struct *param;
	
    CHAR accept[MAX_SYNCML_MIME_LEN] = {0};           /*"text/x-vcalendar" or "text/x-vcard"*/
    CHAR temp_db_addr[MAX_SYNCML_DATABASE_ADDR_LEN] = {0};
    CHAR temp_db_username[MAX_SYNCML_USERNAME] = {0};    
    CHAR temp_db_password[MAX_SYNCML_PASSWORD] = {0}; 
    U8 flag_address = 0;
    U8 flag_username = 0;
    U8 flag_password = 0;
	U8 db_type = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(new_prof != NULL && param_list != NULL);

    /* we can't confirm the four node order;
        CCA_NS_OMA_URI,CCA_NS_OMA_AAUTHNAME,CCA_NS_OMA_AAUTHSECRET,CCA_NS_OMA_AACCEPT
    */
	
	while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
	{   
        MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_PARSE_RESOURCE, param->id);

        switch (param->id)
        {
            case CCA_NS_OMA_AAUTHTYPE:
                /*reversed */
                break;    
                
            case CCA_NS_OMA_AACCEPT:
				mmi_syncml_check_string(
					(CHAR*)&accept,
					param->values.s[0], 
					MAX_SYNCML_MIME_LEN,
					MMI_TRUE);
				
                if (strcmp((CHAR *)accept, (CHAR *)"text/x-vcard") == 0)
                {
                    if (flag_address == 1)
                    {
                    	mmi_syncml_check_string(
							(CHAR*)&new_prof->contact_address, 
							(CHAR*)&temp_db_addr, 
							MAX_SYNCML_DATABASE_ADDR_LEN,
							MMI_TRUE);
                        flag_address = 0;
                    }
                    if (flag_username == 1)
                    {
                    	mmi_syncml_check_string(
							(CHAR*)&new_prof->contact_username, 
							(CHAR*)&temp_db_username, 
							MAX_SYNCML_USERNAME,
							MMI_TRUE);
                        flag_username = 0;
                    }
                    if (flag_password == 1)
                    {
                    	mmi_syncml_check_string(
							(CHAR*)&new_prof->contact_password, 
							(CHAR*)&temp_db_password, 
							MAX_SYNCML_PASSWORD,
							MMI_TRUE);
                        
                        flag_password = 0;
                    }
                }

                else if (strcmp((CHAR *)accept, (CHAR *)"text/x-vcalendar") == 0)
                {
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
                    if (db_type == SYNCML_DB_CALENDAR)
                    {
                       if (flag_address == 1)
                        {                                	
    	                    mmi_syncml_check_string(
    							(CHAR*)&new_prof->calendar_address, 
    							(CHAR*)&temp_db_addr, 
    							MAX_SYNCML_DATABASE_ADDR_LEN,
    							MMI_TRUE);
                            
                            flag_address = 0;
                        }
                        if (flag_username == 1)
                        {
                             mmi_syncml_check_string(
    							(CHAR*)&new_prof->calendar_username, 
    							(CHAR*)&temp_db_username, 
    							MAX_SYNCML_USERNAME,
    							MMI_TRUE);                                    
                            flag_username = 0;
                        }
                        if (flag_password == 1)
                        {
                        	mmi_syncml_check_string(
    							(CHAR*)&new_prof->calendar_password, 
    							(CHAR*)&temp_db_password, 
    							MAX_SYNCML_PASSWORD,
    							MMI_TRUE);
                            flag_password = 0;
                        }
                    }

#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
                    if (db_type == SYNCML_DB_TASK)
                    {
                        if (flag_address == 1)
                        {                                	
    	                    mmi_syncml_check_string(
    							(CHAR*)&new_prof->task_address, 
    							(CHAR*)&temp_db_addr, 
    							MAX_SYNCML_DATABASE_ADDR_LEN,
    							MMI_TRUE);
                            
                            flag_address = 0;
                        }
                        if (flag_username == 1)
                        {
                             mmi_syncml_check_string(
    							(CHAR*)&new_prof->task_username, 
    							(CHAR*)&temp_db_username, 
    							MAX_SYNCML_USERNAME,
    							MMI_TRUE);                                    
                            flag_username = 0;
                        }
                        if (flag_password == 1)
                        {
                        	mmi_syncml_check_string(
    							(CHAR*)&new_prof->task_password, 
    							(CHAR*)&temp_db_password, 
    							MAX_SYNCML_PASSWORD,
    							MMI_TRUE);
                            flag_password = 0;
                        }
                    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
                }
                
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__                                           
                else if (strcmp((CHAR *)accept, (CHAR *)"text/plain") == 0)
                {
                    if (flag_address == 1)
                    {
                    	mmi_syncml_check_string(
							(CHAR*)&new_prof->note_address, 
							(CHAR*)&temp_db_addr, 
							MAX_SYNCML_DATABASE_ADDR_LEN,
							MMI_TRUE);
                        flag_address = 0;
                    }
                    if (flag_username == 1)
                    {
                    	mmi_syncml_check_string(
							(CHAR*)&new_prof->note_username, 
							(CHAR*)&temp_db_username, 
							MAX_SYNCML_USERNAME,
							MMI_TRUE);
                        flag_username = 0;
                    }
                    if (flag_password == 1)
                    {
                    	mmi_syncml_check_string(
							(CHAR*)&new_prof->note_password, 
							(CHAR*)&temp_db_password, 
							MAX_SYNCML_PASSWORD,
							MMI_TRUE);
                        
                        flag_password = 0;
                    }
                }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__                            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__                            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

                else
                {
                    flag_address = 0;
                    flag_username = 0;
                    flag_password = 0;
                }
                break;
                
            case CCA_NS_OMA_URI:
                  
                if (strcmp((CHAR *)accept, (CHAR *)"text/x-vcard") == 0)
                {
                    mmi_syncml_check_string(
						(CHAR*)&new_prof->contact_address, 
						param->values.s[0], 
						MAX_SYNCML_DATABASE_ADDR_LEN,
						MMI_TRUE);
                }

                else if (strcmp((CHAR *)accept, (CHAR *)"text/x-vcalendar") == 0)
                {
                    db_type = mmi_syncml_get_db_type(param->values.s[0]);
                    
  
                    /* If calendar address already fill, then give it to task */
                    /* if (strlen((CHAR*)&new_prof->calendar_address) != 0)
                    {
                        db_type = SYNCML_DB_TASK;
                    }
                    */
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
                    if (db_type == SYNCML_DB_CALENDAR)
                    {
                        mmi_syncml_check_string(
    						(CHAR*)&new_prof->calendar_address, 
    						param->values.s[0], 
    						MAX_SYNCML_DATABASE_ADDR_LEN,
    						MMI_TRUE);
                    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */    
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
                    if (db_type == SYNCML_DB_TASK)
                    {
                        mmi_syncml_check_string(
    						(CHAR*)&new_prof->task_address, 
    						param->values.s[0], 
    						MAX_SYNCML_DATABASE_ADDR_LEN,
    						MMI_TRUE);    
                    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
                }
                
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__                                
                else if (strcmp((CHAR *)accept, (CHAR *)"text/plain") == 0)
                {
                    mmi_syncml_check_string(
						(CHAR*)&new_prof->note_address, 
						param->values.s[0], 
						MAX_SYNCML_DATABASE_ADDR_LEN,
						MMI_TRUE);
                }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */             

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__                                 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */ 

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__                                 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

                else/*accept has not been received*/
                {
                    flag_address = 1;
                	mmi_syncml_check_string(
						(CHAR*)&temp_db_addr, 
						param->values.s[0], 
						MAX_SYNCML_DATABASE_ADDR_LEN,
						MMI_TRUE);
                    /* Only Calendar and Task has this type */
                    db_type = mmi_syncml_get_db_type(param->values.s[0]);
                }
                break;
        
            case CCA_NS_OMA_AAUTHNAME:

                if (strcmp((CHAR *)accept, (CHAR *)"text/x-vcard") == 0)
                {
                	mmi_syncml_check_string(
						(CHAR*)&new_prof->contact_username, 
						param->values.s[0], 
						MAX_SYNCML_USERNAME,
						MMI_TRUE);                                    
                }
                else if (strcmp((CHAR *)accept, (CHAR *)"text/x-vcalendar") == 0)
                {
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
                    if (db_type == SYNCML_DB_CALENDAR)
                    {
                     	mmi_syncml_check_string(
    						(CHAR*)&new_prof->calendar_username, 
    						param->values.s[0], 
    						MAX_SYNCML_USERNAME,
    						MMI_TRUE);                   
                    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
                    if (db_type == SYNCML_DB_TASK)
                    {
                      	mmi_syncml_check_string(
    						(CHAR*)&new_prof->task_username, 
    						param->values.s[0], 
    						MAX_SYNCML_USERNAME,
    						MMI_TRUE);                      
                    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
                }
                
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__                
                else if (strcmp((CHAR *)accept, (CHAR *)"text/plain") == 0)
                {
                	mmi_syncml_check_string(
						(CHAR*)&new_prof->note_username, 
						param->values.s[0], 
						MAX_SYNCML_USERNAME,
						MMI_TRUE);                                    
                }              
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

                else/*accept has not been received*/
                {
                    flag_username = 1;
					 mmi_syncml_check_string(
						(CHAR*)&temp_db_username, 
						param->values.s[0], 
						MAX_SYNCML_USERNAME,
                    	MMI_TRUE);
                }
                
                break;
                
            case CCA_NS_OMA_AAUTHSECRET:
                
                if (strcmp((CHAR *)accept, (CHAR *)"text/x-vcard") == 0)
                {
                     mmi_syncml_check_string(
						(CHAR*)&new_prof->contact_password, 
						param->values.s[0], 
						MAX_SYNCML_PASSWORD,
                    	MMI_TRUE);                                    
                }

                else if (strcmp((CHAR *)accept, (CHAR *)"text/x-vcalendar") == 0)
                {
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
                    if (db_type == SYNCML_DB_CALENDAR)
                    {
                        mmi_syncml_check_string(
    						(CHAR*)&new_prof->calendar_password, 
    						param->values.s[0], 
    						MAX_SYNCML_PASSWORD,
                        	MMI_TRUE);
                    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
                    if (db_type == SYNCML_DB_TASK)
                    {
                        mmi_syncml_check_string(
    						(CHAR*)&new_prof->task_password, 
    						param->values.s[0], 
    						MAX_SYNCML_PASSWORD,
                        	MMI_TRUE);
                    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
                }
                
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__                
                else if (strcmp((CHAR *)accept, (CHAR *)"text/plain") == 0)
                {
                     mmi_syncml_check_string(
						(CHAR*)&new_prof->note_password, 
						param->values.s[0], 
						MAX_SYNCML_PASSWORD,
                    	MMI_TRUE);                                    
                }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

                else/*accept has not been received*/
                {
                    flag_password = 1;
					mmi_syncml_check_string(
						(CHAR*)&temp_db_password, 
						param->values.s[0], 
						MAX_SYNCML_PASSWORD,
                    	MMI_TRUE); 
                    
                }
                break;            
        
            default:
                break;
                
        }

    }
	return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_check_string
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  cntx        ota context ptr
 *  index_prof  the target profile index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_syncml_check_string(CHAR* out_buff, const CHAR* in_buff, U8 max_len, MMI_BOOL trunk_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(out_buff != NULL);
	if (in_buff == NULL || 
		(strlen(in_buff) == 0) ||
		!mmi_syncml_is_ascii_format((CHAR*)in_buff))
	{
		return MMI_FALSE;
	}
	
	if (strlen(in_buff) < max_len)
	{
		strcpy(out_buff, in_buff);
	}
	else if (trunk_flag) /* trunk the input string */
	{
		strncpy(out_buff, in_buff, max_len - 1);
	}
	else
	{
		return MMI_FALSE;
	}
	return MMI_TRUE;
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_proxy_for_account
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  cntx        ota context ptr
 *  index_prof  the target profile index
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
static void mmi_syncml_set_proxy_for_account(mmi_syncml_ota_cntx_struct *cntx,  S16 index_prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL proxy_check_flag = MMI_TRUE;
	srv_dtcnt_sim_type_enum sim_id;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cntx->num_proxy; i++)
    {
        /* for dm update:
        * If dm update and the original is use proxy, client should check the matchment.
        * ,if original use-proxy flag is 0, client will don't check the matchment and copy to memo directly
        */
        if ((cntx->opr_flag & SYNCML_OTA_OPR_DM_UPDATE_MASK) && !g_syncml_ota_use_proxy_flag)
        {
           proxy_check_flag = MMI_FALSE;
        }

        if (proxy_check_flag && !cntx->proxy[i].valid)
        {
           continue;
        }
       
		srv_dtcnt_get_sim_preference(&sim_id);
		if (sim_id == SRV_DTCNT_SIM_TYPE_NONE)
		{
			sim_id = SRV_DTCNT_SIM_TYPE_1;
		}
        /* If find out specified proxy */
        if (strcmp((CHAR *)cntx->app_to_proxy[index_prof], (CHAR *)cntx->proxy[i].proxy_id) == 0)
        {      
            if (cntx->proxy[i].dataaccountid == 0)
            {   
                cntx->profile[index_prof]->account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_CONN;
                cntx->profile[index_prof]->net_id[sim_id - 1] = CBM_DEFAULT_ACCT_ID;  
            }
            else
            {               
                cntx->profile[index_prof]->account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_CONN;
                cntx->profile[index_prof]->net_id[sim_id - 1] = cntx->proxy[i].dataaccountid;   
            }
            
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
            /* copy valid hash to profile */
            memcpy((CHAR *)cntx->profile[index_prof]->proxy_id_hash, (CHAR *)cntx->proxy[i].proxy_id_hash, MAX_SYNCML_HASH_BUF_LEN);
#endif  

            MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_SET_PROXY_FOR_ACCOUNT, i, cntx->profile[index_prof]->net_id[sim_id - 1]); 

            return;
            
       } /* if*/
       
   } /* for_i */

   /* If No matched proxy, we will set default account */
   if (i == cntx->num_proxy)
   {
       MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_PARSE_ERROR_NO_MATCH_PX); 
       cntx->profile[index_prof]->net_id[sim_id - 1] = CBM_DEFAULT_ACCT_ID;
       cntx->profile[index_prof]->account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_CONN;
   }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_free_syncml_ota_cntx
 * DESCRIPTION
 *  The function frees memory of the control block, and clears the global ptr.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_free_syncml_ota_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Nothing to do. Return. */
    if (g_syncml_ota_context == NULL) 
    {
        return;
    }    
    /* Free all profiles. */
    for (i = 0; i < g_syncml_ota_context->num_profiles; i++) 
    {
        if (g_syncml_ota_context->profile[i] == NULL) 
        {
            continue;
        }
        OslMfree(g_syncml_ota_context->profile[i]);
        g_syncml_ota_context->profile[i] = NULL;
    }
    /* Free the control block. */
    OslMfree(g_syncml_ota_context);
    g_syncml_ota_context = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_valid_profile_num
 * DESCRIPTION
 *  This function checks if there is any valid profile. every valid coming profile
 *  can be active.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_syncml_get_valid_profile_num(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    mmi_syncml_account_struct *new_prof;
    U8 num_prof = 0; /* sanity check for valid profile */
	U8 i;
     
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/   

    g_syncml_ota_context->total_valid = 0;
	for (i = 0; i < g_syncml_ota_context->num_profiles; i++)
	{
	    new_prof = g_syncml_ota_context->profile[i];

        MMI_PRINT(
            MOD_MMI_CONN_APP, 
            MMI_CONN_TRC_G2_SYNCML, 
            "mmi_syncml_get_valid_profile_num => server_addr = %s, contact_addr = %s, calendar_addr = %s", 
            new_prof->server_address,
            new_prof->contact_address,
            new_prof->calendar_address);

	    if (new_prof != NULL && g_syncml_ota_context->isvalidprof[i])
		{
		    if (applib_url_is_valid((const char *)new_prof->server_address) != 0 ||
				strcmp((CHAR*)new_prof->server_address, (CHAR*)"http://") == 0)
			{
				g_syncml_ota_context->isvalidprof[i] = MMI_FALSE;
                new_prof->account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_SVR;
				MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_PARSE_ERROR_SERVER_IP, i);
                continue; /* to check the next buffered profile */
			}
            else
            {
			    new_prof->account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_SVR;
            }
          
            /* check contact address */
           
            if (strlen((CHAR *)new_prof->contact_address) == 0 ||
                strcmp((CHAR *)new_prof->contact_address, (CHAR *)"./") == 0)
            {   
                new_prof->account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_CON;
			} 
            else 
            {
                new_prof->account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_CON;   
            }

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__            
            /* check calendar address */
            if (strlen((CHAR *)new_prof->calendar_address) == 0 ||
                strcmp((CHAR *)new_prof->calendar_address, (CHAR *)"./") == 0)
			{	            
                new_prof->account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_CAL;
			} 
            else
            {
                new_prof->account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_CAL;
            }  
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__            
            /* check task address */ 
            if (strlen((CHAR *)new_prof->task_address) == 0 ||
                strcmp((CHAR *)new_prof->task_address, (CHAR *)"./") == 0)
            {   
                new_prof->account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_TASK;
            }
            else
            {
                new_prof->account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_TASK;    
            }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */ 

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__            
            /* check note address */ 
            if (strlen((CHAR *)new_prof->note_address) == 0 ||
                strcmp((CHAR *)new_prof->note_address, (CHAR *)"./") == 0)
            {   
                new_prof->account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_NOTE;
            }
            else
            {
                new_prof->account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_NOTE;    
            }           
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */ 

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

            MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_GET_VALID_PROFILE_NUM, i, new_prof->account_validation);

            if (g_syncml_ota_context->isvalidprof[i] &&
				!(g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_DM_UPDATE_MASK))
            {
            #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
            	U8 update_prof_idx;
                
				update_prof_idx = mmi_syncml_is_update_match(new_prof, (void*)g_syncml_ota_context);
                
                MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_IS_UPDATE_MATCH_RETURN, update_prof_idx);

                if (update_prof_idx != SYNCML_INVALID_IDX)
				{
					/*
					 * If the profile is in use, and can be update, then set it to false.
					 */
					g_syncml_ota_context->dst_idx[i] = update_prof_idx;
				}
			#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
				g_syncml_ota_context->total_valid++;	
            }

            num_prof++;
		}

	} /* for num_profiles */
    
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_VALID_PROF_NUM, g_syncml_ota_context->total_valid, num_prof);

    return num_prof;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_installation
 * DESCRIPTION
 *  This function shows information about a incoming profile. And ask users
 *  whether they want to install the profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_installation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tmp[MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH];
    CHAR tmpnum[4 * ENCODING_LENGTH];
    mmi_syncml_account_struct *prof;
    U8 *gui_buffer;
    CHAR *info;    
    U8 current_valid;
    U8 i;
	U16 title_icon;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Obtain the current interesting profile. */
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_ENTRY_INSTALL, g_syncml_ota_context->iter);

    /* get the first valid profile */
    while(g_syncml_ota_context->iter < MMI_MAX_SYNCML_ACCOUNTS)
    {
        if (!g_syncml_ota_context->isvalidprof[g_syncml_ota_context->iter])
        {
            g_syncml_ota_context->iter++;
        }
        else
        {
            break;
        }
    }

    prof = (mmi_syncml_account_struct *)g_syncml_ota_context->profile[g_syncml_ota_context->iter];

    /* Obtain a global buffer to show messages. */
    info = (CHAR *)subMenuData;

    current_valid = 0;
    for (i = 0; i < g_syncml_ota_context->iter + 1; i++)
    {
        if (g_syncml_ota_context->isvalidprof[i])
        {
            current_valid++;
        }
    }
	
  	/*--------------------------
     *  	Install Setting	   |	 
     *--------------------------
     * Synchronization
     * Account: 1/3
     *  Update existing profile
     *  
     * Account name:Account 1
     *
     * Server address:http://www.mobical.net/...
     *
     * Database address:contact
	 *
     * Database address:calendar
     *
     *--------------------------
     * Install |		| Skip |
     *--------------------------
     */
     
    /* APP NAME */
    mmi_ucs2cpy(info, GetString(STR_ID_CCA_SYNCMLDS));
	mmi_ucs2cat(info, (CHAR *)L"\n");
	
    /* Current profile num */
    mmi_ucs2cat(info, GetString(STR_ID_SYNC_PROFILE));
    mmi_ucs2cat(info, GetString(STR_ID_SYNCML_COLON)); 
    mmi_ucs2cat(info, (CHAR *)L" ");   
    sprintf((CHAR *)&tmpnum,"%d",current_valid);
    memset(tmp,0,sizeof(tmp));
    mmi_asc_n_to_ucs2(
                (CHAR *) tmp,
                (CHAR *) tmpnum,
                strlen((CHAR*)&tmpnum));
    mmi_ucs2cat(info, (CHAR *)tmp);
    mmi_ucs2cat(info, (CHAR *)L"/");
    sprintf((CHAR*)&tmpnum, "%d", g_syncml_ota_context->total_valid);

	memset(tmp,0,sizeof(tmp));
    mmi_asc_n_to_ucs2(
                (CHAR *) tmp,
                (CHAR *) tmpnum,
                strlen((CHAR*)&tmpnum));
    mmi_ucs2cat(info, (CHAR *)tmp); 
	
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__  
    if (g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter] != SYNCML_INVALID_IDX)
	{
		/* Show Update infomation */
		mmi_ucs2cat(info, (CHAR *)L"\n");
		mmi_ucs2cat(info, GetString(STR_ID_CCA_UPDATE_PROFILE));	 
	}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

	mmi_ucs2cat(info, (CHAR *)L"\n\n"); 
	mmi_ucs2cat(info, GetString(STR_ID_SYNC_PROFILE_NAME));
	mmi_ucs2cat(info, GetString(STR_ID_SYNCML_COLON));
	mmi_ucs2cat(info, (CHAR *)L" "); 
	mmi_ucs2cat(info, (CHAR *)prof->account_name);
	
    /* Server address */
    mmi_ucs2cat(info, (CHAR *)L"\n\n");
    mmi_ucs2cat(info, GetString(STR_ID_SYNC_SERVER_ADDRESS));
    memset(tmp,0,sizeof(tmp));
    mmi_ucs2cat(info, GetString(STR_ID_SYNCML_COLON));
    mmi_ucs2cat(info, (CHAR *)L" "); 
            mmi_asc_n_to_ucs2(
            (CHAR *) tmp,
            (CHAR *) prof->server_address,
            strlen((CHAR*)prof->server_address));
    mmi_ucs2cat(info, (CHAR *)tmp); 
    
    /* Contact address */    
	if (prof->account_validation & MMI_SYNCML_ACCOUNT_VALID_MASK_CON)
    {
        memset(tmp, 0,MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(
                (CHAR *) tmp,
                (CHAR *) prof->contact_address,
                strlen((CHAR*)prof->contact_address));
        mmi_ucs2cat(info, (CHAR *)L"\n\n");
		mmi_ucs2cat(info, GetString(STR_ID_SYNC_APP_PHB));
        mmi_ucs2cat(info, GetString(STR_ID_SYNC_DATABASE_ADDRESS_1));
        mmi_ucs2cat(info, GetString(STR_ID_SYNCML_COLON));
        mmi_ucs2cat(info, (CHAR *)L" "); 
        mmi_ucs2cat(info, (CHAR *)tmp);
   }
   
    /* Calendar address */
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__    
	if (prof->account_validation & MMI_SYNCML_ACCOUNT_VALID_MASK_CAL)
    {
		memset(tmp, 0,MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH);
		mmi_asc_n_to_ucs2(
            (CHAR *) tmp,
            (CHAR *) prof->calendar_address,
            strlen((CHAR*)prof->calendar_address));       
		mmi_ucs2cat(info, (CHAR *)L"\n\n");                   
		mmi_ucs2cat(info, GetString(STR_ID_SYNC_APP_CAL));
		mmi_ucs2cat(info, GetString(STR_ID_SYNC_DATABASE_ADDRESS_1));
		mmi_ucs2cat(info, GetString(STR_ID_SYNCML_COLON));
		mmi_ucs2cat(info, (CHAR *)L" "); 
		mmi_ucs2cat(info, (CHAR *)tmp);
	}
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
    
    /* Task address */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__       
	if (prof->account_validation & MMI_SYNCML_ACCOUNT_VALID_MASK_TASK)
    {
		memset(tmp, 0,MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH);
		mmi_asc_n_to_ucs2(
            (CHAR *) tmp,
            (CHAR *) prof->task_address,
            strlen((CHAR*)prof->task_address));      
		mmi_ucs2cat(info, (CHAR *)L"\n\n");
		mmi_ucs2cat(info, GetString(STR_ID_SYNC_APP_TASK));
		mmi_ucs2cat(info, GetString(STR_ID_SYNC_DATABASE_ADDRESS_1));
		mmi_ucs2cat(info, GetString(STR_ID_SYNCML_COLON));
		mmi_ucs2cat(info, (CHAR *)L" "); 
		mmi_ucs2cat(info, (CHAR *)tmp);
	}
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

    /* Note address */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__ 
    if (prof->account_validation & MMI_SYNCML_ACCOUNT_VALID_MASK_NOTE)
    {
        memset(tmp, 0, MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(
            (CHAR *) tmp,
            (CHAR *) prof->note_address,
            strlen((CHAR*)prof->note_address));
        mmi_ucs2cat(info, (CHAR *)L"\n\n");    
		mmi_ucs2cat(info, GetString(STR_ID_SYNC_APP_NOTE));
        mmi_ucs2cat(info, GetString(STR_ID_SYNC_DATABASE_ADDRESS_1));
        mmi_ucs2cat(info, GetString(STR_ID_SYNCML_COLON));
        mmi_ucs2cat(info, (CHAR *)L" "); 
        mmi_ucs2cat(info, (CHAR *)tmp);
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
 
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_ENTRY_INSTALL_INFO);

    /* Email address */ 
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
    
    /* Bookmark address */
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

    if (!mmi_frm_scrn_enter(
         GRP_ID_SYNC_OTAP_INSTALL,
         SCR_ID_SYNC_OTA_PROFILE_INSTALL, 
         NULL, 
         mmi_syncml_entry_installation, 
         MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    
	if (g_syncml_ota_next_profile)
	{
		/* if this flag be set, we should treat it as a new profile to install
		 * so we need to clear guibuffer (ex. scroll bar position)
		 */
		gui_buffer = NULL;
		g_syncml_ota_next_profile = 0;
	}
	else
	{
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
	}
    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

#if defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_12MATRIX__) 
    title_icon = GetRootTitleIcon(MAIN_MENU_OP_SERVICES_MENUID);
#else
    title_icon = GetRootTitleIcon(MENU_ID_SYNCML_MAIN);
#endif /* __MMI_OP01_MENU_9MATRIX__ */

    ShowCategory74Screen(
        STR_ID_CCA_INSTALL_SETTING,
        title_icon,  
        STR_GLOBAL_INSTALL,
        IMG_GLOBAL_YES,
        STR_ID_CCA_SKIP,
        IMG_GLOBAL_NO,
        (U8 *)info,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        gui_buffer);  

    SetLeftSoftkeyFunction(mmi_syncml_find_empty_profile, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_display_skip_confirm, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_syncml_find_empty_profile, KEY_EVENT_UP);
    /* for endkey, close the active group by frm, and handle goback endkey event */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_new_ota_profile
 * DESCRIPTION
 *  This function allocates a temporary storage for SYNC profile. And it will 
 *  turn on the flag such that we can process subsequent nodes/parameters
 *  again.
 * PARAMETERS
 *  cntx            [IN]            control block for SYNC OTA provisioning
 * RETURNS
 *  On success, return the index of the newly allocated profile. Otherwise, 
 *  return -1, i.e., an invalid index.
 *****************************************************************************/
static S16 mmi_syncml_new_otap_profile(mmi_syncml_ota_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* No more temporary profile storage. */
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_NEW_OTA_PROF, cntx->num_profiles);
    
    if (cntx->num_profiles >= MMI_MAX_SYNCML_ACCOUNTS) 
    {
        return -1;
    }
    
    /* Obtain the index. */
    index = cntx->num_profiles;
    
    /* Allocate memory for the profile. */
    cntx->profile[index] = (mmi_syncml_account_struct *)OslMalloc(sizeof(mmi_syncml_account_struct));
    if (cntx->profile[index] == NULL) 
    {
        return -1;
    }
    
    /* Initialize the allocated slim SYNCML profile. */
    mmi_syncml_init_slim_profile(cntx->profile[index]);

    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_init_slim_profile
 * DESCRIPTION
 *  This function initializes a slim SYNCML profile.
 * PARAMETERS
 *  prof            [OUT]           Profile to be initialized
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_init_slim_profile(mmi_syncml_account_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(prof, 0, sizeof(mmi_syncml_account_struct));
    mmi_ucs2cpy((CHAR *)prof->account_name, (CHAR *)DEFAULT_CCA_PROFILE_NAME);
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	memcpy((PU8)prof->prov_url_hash, "\0", 1);
	memcpy((PU8)prof->proxy_id_hash, "\0", 1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_find_empty_profile
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
static void mmi_syncml_find_empty_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *prof;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Find an empty profile. */
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_FIND_EMPTY_PROF );

    /* once entry install, delete account related screen */
    mmi_frm_group_close(GRP_ID_SYNC_MAIN);
    mmi_frm_group_close(GRP_ID_SYNC_APP_SYNC);
    /* delete editor screen that do not enter from sync main menu */
    mmi_frm_group_close(GRP_ID_SYNC_EDIT);
    
	/* first update account if exsit updateble account */
	if (g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter] != SYNCML_INVALID_IDX)
	{
		if (
#ifdef __MMI_SYNCML_DEVICE_SYNC__
            !mmi_syncml_is_device_sync() &&
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
            mmi_syncml_is_sync_now() &&
			g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter] == (g_mmi_syncml_cntx.active_account - 1))
		{  
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_ID_CCA_PROFILE_IN_USE), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL); 
            
            /* will goback install screen */
    		return;
		}
		else
		{		
            if (mmi_syncml_install_new_account(g_syncml_ota_context->iter))
            {      
    			g_syncml_ota_context->opr_flag |= SYNCML_OTA_OPR_UPDATE_MASK;
            }
            mmi_syncml_next_profile(); 
            return;
		}
	}

    /* then, enter install if have not been replaced */
	if (!(g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_REPLACE_MASK))
	{
	    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
	    {
	        /* empty acount : server address and all database address are empty */
	        if (mmi_syncml_is_empty_profile(i)) 
	        {

	            g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter] = i;
                
	            prof = g_syncml_ota_context->profile[g_syncml_ota_context->iter];
                
	            /*Update profile name to be saved in NVRAM*/
	            if(mmi_ucs2cmp((CHAR*)prof->account_name, (CHAR*)L"New Account") == 0)
	            {
	                mmi_ucs2cpy((CHAR *)g_syncml_ota_context->currentprofnamelist[i], 
	                           GetString((U16) (STR_ID_SYNC_PROFILE_ID1 + i)));                  
	            }
	            else
	            {
	                mmi_ucs2cpy((CHAR *)g_syncml_ota_context->currentprofnamelist[i], 
	                           (CHAR*)prof->account_name);
	            }				     
                
				if (mmi_syncml_install_new_account(g_syncml_ota_context->iter))
                {                   
                    g_syncml_ota_context->opr_flag |= SYNCML_OTA_OPR_INSTALL_MASK;
                }
                
                mmi_syncml_next_profile();            
                return;
	        }
	    }
	}

    /* only replacement if there is no updateble and empty account */
    mmi_frm_scrn_close(GRP_ID_SYNC_OTAP_INSTALL, SCR_ID_SYNC_OTA_PROFILE_REPLACE);
    mmi_syncml_entry_replacement();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_empty_profile
 * DESCRIPTION
 *  This function examines whether the i-th slot in the profile list is empty.
 * PARAMETERS
 *  i               [IN]            Used to specify i-th profile
 * RETURNS
 *  Return TRUE when profile is empty. Otherwise, return FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_syncml_is_empty_profile(U8 record_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *old_nvram_prof;
    S16 error;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < g_syncml_ota_context->num_profiles; i++)
    {
        if (g_syncml_ota_context->dst_idx[i] == record_id)
        {
            return MMI_FALSE; 
        }
    }
    
    old_nvram_prof = (mmi_syncml_account_struct *)OslMalloc(sizeof(mmi_syncml_account_struct));
    if (old_nvram_prof == NULL)
    {
        MMI_ASSERT(0);
    }
    
    ReadRecord(NVRAM_EF_SYNCML_ACCOUNT_LID, 
               (U16)(record_id + 1), 
               (void*)old_nvram_prof, 
               NVRAM_EF_SYNCML_ACCOUNT_SIZE,
               &error); 
    
    if(
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
		!old_nvram_prof->read_only &&
#endif
       (strcmp((CHAR *) old_nvram_prof->contact_address, "./") == 0) &&
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
       (strcmp((CHAR *) old_nvram_prof->calendar_address, "./") == 0) &&
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
       (strcmp((CHAR *) old_nvram_prof->task_address, "./") == 0) &&
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
       (strcmp((CHAR *) old_nvram_prof->note_address, "./") == 0) &&
#endif
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */
       MMI_TRUE)
    {
        /* for PC sync */
        if (mmi_ucs2strlen((CHAR *) old_nvram_prof->server_address) == 0)
        {
            OslMfree(old_nvram_prof);
            return MMI_TRUE;
        }
        /* for internet sync */
        if ((old_nvram_prof->transport_type == MMI_SYNCML_TRANS_TYPE_INTERNET)
            && (strcmp((CHAR *) old_nvram_prof->server_address, "http://") == 0))
        {
            OslMfree(old_nvram_prof);
            return MMI_TRUE;
        }
    }          

    OslMfree(old_nvram_prof);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_finish_provisioing_hdlr
 * DESCRIPTION
 *  This function is used to handle CCA msg after provisioning complete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_finish_provisioing_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Priority of these rsp enum:
     *      ENDKEY > UPDATED > OK > SKIPPED > INVALID */

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__	
    /* When at leaset 1 profile is matched and updated successfully */
    if (g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_UPDATE_MASK)
    {
        mmi_syncml_cca_config_rsp(CCA_STATUS_SETTING_UPDATED);
    }    
    /* When at lease 1 profile has been installed successfylly and no profile is updated */
    else if ((g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_INSTALL_MASK)
        || (g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_REPLACE_MASK))
#else   /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    if ((g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_INSTALL_MASK)
        || (g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_REPLACE_MASK))
#endif  /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    {
        mmi_syncml_cca_config_rsp(CCA_STATUS_OK);
    }
    /* When user skipped the installation of all profiles ,causing no profiles installed. */
    else if (g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_SKIP_MASK)
    {
        mmi_syncml_cca_config_rsp(CCA_STATUS_SETTING_SKIPPED);
    }
    else
    {
        MMI_ASSERT(!"Syncml Ota should not be here");
        mmi_syncml_cca_config_rsp(CCA_STATUS_INVALID_SETTING);
    }       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_next_profile
 * DESCRIPTION
 *  This function leads us to process next incoming profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_next_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_NEXT_PROF );

    /* Increase the index of the iterator to process next profile. */
    g_syncml_ota_context->iter++;

    /* Whether there is another profile needed to be installed. */
    if (g_syncml_ota_context->iter < g_syncml_ota_context->num_profiles) 
    {
        if (g_syncml_ota_context->isvalidprof[g_syncml_ota_context->iter])
        {
			g_syncml_ota_next_profile = 1;
            
            /* now, can not enter one screen twice, so we should close firstly */
            mmi_frm_scrn_close(GRP_ID_SYNC_OTAP_INSTALL, SCR_ID_SYNC_OTA_PROFILE_INSTALL);
            
            mmi_syncml_entry_installation();
        }
        else
        {
            mmi_syncml_next_profile();
        }
    } 
    else 
    {
		/* complete provisioning normally */
		mmi_frm_group_close(GRP_ID_SYNC_OTAP_INSTALL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_otap_replace_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_otap_replace_leave_proc(mmi_event_struct *param)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter] = SYNCML_INVALID_IDX;
        }
        default:
            break;
    }

    return MMI_RET_OK;        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_replacement
 * DESCRIPTION
 *  This function shows all SYNCML profiles installed on the system such that 
 *  users can select an existing profile to be replaced.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_replacement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_account_struct *temp_nvram_buf;
    U8 *prof_name[MMI_MAX_SYNCML_ACCOUNTS];
    U8 *gui_buffer;
	U8 num_prof_edit = 0;
    U8 i;
	U16 title_icon;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_ENTRY_REPLACE );

    /* Initialize an invalid used index of an existing profile. */
    g_syncml_ota_context->in_use = SYNCML_INVALID_IDX;   

    if (mmi_syncml_is_sync_now()
#ifdef __MMI_SYNCML_DEVICE_SYNC__
        && !mmi_syncml_is_device_sync()
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
        )
    {
        g_syncml_ota_context->in_use = g_mmi_syncml_cntx.active_account - 1;
    }

	temp_nvram_buf = (mmi_syncml_account_struct *)OslMalloc(sizeof(mmi_syncml_account_struct));

    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {    
        mmi_syncml_read_account_from_nvram((U8)(i + 1), (void*)temp_nvram_buf);
      	/*
      	 *	read only profile will not be showed in this list.
      	 */
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
		if (!temp_nvram_buf->read_only)
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
		{
			g_syncml_name_idx_map_tbl[num_prof_edit] = i;
			mmi_ucs2cpy((CHAR *)g_syncml_ota_context->currentprofnamelist[num_prof_edit],(CHAR *)temp_nvram_buf->account_name);
			prof_name[num_prof_edit] = (U8*)g_syncml_ota_context->currentprofnamelist[num_prof_edit];
			num_prof_edit++;
		}
    }
	OslMfree(temp_nvram_buf);
	temp_nvram_buf = NULL;
	
	/* All the profile is read only ?*/
	if (num_prof_edit == 0)
	{
		mmi_syncml_show_info(STR_ID_SYNC_NO_PROF_REPLACE);
        mmi_frm_group_close(GRP_ID_SYNC_OTAP_INSTALL);
		return;
	}
    
    if (!mmi_frm_scrn_enter(
         GRP_ID_SYNC_OTAP_INSTALL,
         SCR_ID_SYNC_OTA_PROFILE_REPLACE, 
         NULL, 
         mmi_syncml_entry_replacement, 
         MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    RegisterHighlightHandler(mmi_syncml_replacement_highlight_hdlr);
        
    mmi_frm_scrn_set_leave_proc(GRP_ID_SYNC_OTAP_INSTALL, SCR_ID_SYNC_OTA_PROFILE_REPLACE, mmi_syncml_otap_replace_leave_proc);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
#if defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_12MATRIX__)
    title_icon = GetRootTitleIcon(MAIN_MENU_OP_SERVICES_MENUID);
#else
    title_icon = GetRootTitleIcon(MENU_ID_SYNCML_MAIN);
#endif /* __MMI_OP01_MENU_9MATRIX__ */ 
	
    ShowCategory53Screen(
        STR_ID_CCA_REPLACE_SETTING,
        title_icon,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_prof_edit,
        prof_name,
        (U16 *)gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_syncml_replace_profile, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_goback_from_replace_screen,KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_syncml_replace_profile, KEY_EVENT_UP);
    /* for endkey, close the active group by frm, and handle goback endkey event */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_replace_profile
 * DESCRIPTION
 *  This function shows a confirmation screen to confirm a replacement.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_replace_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The profile is in use. Can't be replaced. */
    if (g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter] == g_syncml_ota_context->in_use)
    {
        mmi_popup_display_simple(
            (WCHAR*)get_string(STR_ID_CCA_PROFILE_IN_USE), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);   

        /* will goback replacement screen */
        g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter] = SYNCML_INVALID_IDX;
    }

    else
    {
        mmi_ucs2cpy((CHAR *)g_syncml_ota_context->currentprofnamelist[g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter]], 
            (CHAR *)g_syncml_ota_context->profile[g_syncml_ota_context->iter]->account_name);        
        
    	if (mmi_syncml_install_new_account(g_syncml_ota_context->iter))
        {   
            g_syncml_ota_context->opr_flag |= SYNCML_OTA_OPR_REPLACE_MASK;
        }
        
        mmi_syncml_next_profile();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_install_new_account
 * DESCRIPTION
 *  This function installs each incoming profile that has been chosen to 
 *  install.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of installed profiles.
 *****************************************************************************/
static MMI_BOOL mmi_syncml_install_new_account(U8 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *old_account = NULL;
    mmi_syncml_account_struct *new_account;
    U8 account_index = g_syncml_ota_context->dst_idx[idx];
	srv_dtcnt_sim_type_enum sim_id;
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(idx < g_syncml_ota_context->num_profiles);
	
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_INSTALL_PROF );
    
    if (!g_syncml_ota_context->isvalidprof[idx] ||
        (g_syncml_ota_context->dst_idx[idx] == SYNCML_INVALID_IDX)) 
    {
        return MMI_FALSE;
    }
    
    new_account = g_syncml_ota_context->profile[idx];  
    
    old_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    ReadRecord(
        NVRAM_EF_SYNCML_ACCOUNT_LID,
        (U8)(account_index + 1), 
        (void*)old_account,
        NVRAM_EF_SYNCML_ACCOUNT_SIZE,
        &error);   
		
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__	
	new_account->account_id = old_account->account_id;
	new_account->type = MMI_SYNCML_ACCOUNT_TYPE_OTA; /* provisioning type */
	new_account->read_only = old_account->read_only;
	memcpy(new_account->prov_url_hash, g_syncml_ota_context->prov_url_hash, MAX_SYNCML_HASH_BUF_LEN);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    /* save old account setting */
    new_account->app_to_sync = old_account->app_to_sync;  
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    new_account->sync_type = old_account->sync_type;   
#endif
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#endif
    new_account->regular_sync = old_account->regular_sync;  
    
    new_account->sync_report_status = old_account->sync_report_status; 
 
    /* update global variables */
    g_mmi_syncml_cntx.account_validation[account_index] = new_account->account_validation; 

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    g_mmi_syncml_cntx.transport_type[account_index] = MMI_SYNCML_TRANS_TYPE_INTERNET;
#endif 
    new_account->transport_type = MMI_SYNCML_TRANS_TYPE_INTERNET;
    
    mmi_ucs2cpy((CHAR*)g_mmi_syncml_cntx.account_name_display[account_index], (CHAR*)new_account->account_name);

    OslMfree(old_account);
    
    /* here check the field of the valid profile */
    /* If default account name is "New Account, should set the default value "Account 1/2/3"" */
    if (mmi_ucs2cmp((CHAR*)new_account->account_name, (CHAR*)L"New Account") == 0)
    {     
        mmi_ucs2cpy((CHAR*)new_account->account_name, (CHAR*)L"");        
    }
    if (strlen((CHAR*)new_account->contact_address) == 0)
    {
        strcpy((CHAR*)new_account->contact_address, "./");
    }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    if (strlen((CHAR*)new_account->calendar_address) == 0)
    {
        strcpy((CHAR*)new_account->calendar_address, "./");
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    if (strlen((CHAR*)new_account->task_address) == 0)
    {
        strcpy((CHAR*)new_account->task_address, "./");
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (strlen((CHAR*)new_account->note_address) == 0)
    {
        strcpy((CHAR*)new_account->note_address, "./");
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

	srv_dtcnt_get_sim_preference(&sim_id);
	if (sim_id == SRV_DTCNT_SIM_TYPE_NONE)
	{
		sim_id = SRV_DTCNT_SIM_TYPE_1;
	}

    /* delete this net_id for data account */
    mmi_dtcnt_subscribe_account(
        old_account->net_id[sim_id - 1], 
        CBM_INVALID_NWK_ACCT_ID, 
        STR_ID_SYNC_APP_ID1 + account_index, 
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN));
#endif

    /* encode app id and sim id */
    new_account->net_id[sim_id - 1] = 
    	cbm_encode_data_account_id(
            new_account->net_id[sim_id - 1],                        /* raw data account id */
            (cbm_sim_id_enum)g_syncml_ota_context->sim_id,               /* SIM info */
            0,                                          /* app id   */
            KAL_FALSE);                                 /* always ask feature */

    /* add a new net_id for data account */
    mmi_dtcnt_subscribe_account(
        CBM_INVALID_NWK_ACCT_ID, 
        new_account->net_id[sim_id - 1], 
        STR_ID_SYNC_APP_ID1 + account_index, 
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN));
#endif

    WriteRecord(
        NVRAM_EF_SYNCML_ACCOUNT_LID,
        (U8)(account_index + 1), 
        (void*)new_account,
        NVRAM_EF_SYNCML_ACCOUNT_SIZE, 
        &error);
    
    if (error != NVRAM_WRITE_SUCCESS) 
    {
        MMI_ASSERT(0);
    }
	        
#if defined(__MMI_NCENTER_SUPPORT__)
	if (mmi_syncml_necnter_is_unfinish_account(account_index + 1))
	{
		mmi_syncml_ncenter_sync_unfinish_destroy(MMI_SYNCML_NOTIFICATION_SYNC_REMOTE);
	}
#endif	
			
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_replacement_highlight_hdlr
 * DESCRIPTION
 *  This highlight handler remembers the item chosen to be replaced.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_replacement_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter] = g_syncml_name_idx_map_tbl[index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_show_info
 * DESCRIPTION
 *  This function shows a notification screen with the specified message.
 * PARAMETERS
 *  msg_id          [IN]            Message to be shown
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_show_info(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_popup_display_simple(
		(WCHAR*)get_string(msg_id), 
		MMI_EVENT_FAILURE, 
		GRP_ID_ROOT, 
		NULL);          
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_goback_from_replace_screen
 * DESCRIPTION
 *  This function will clear the  and gobackhistory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_goback_from_replace_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_ota_context->dst_idx[g_syncml_ota_context->iter] = SYNCML_INVALID_IDX;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_ascii_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest             [IN]    
 * RETURNS 0,1
 *  
 *****************************************************************************/
static MMI_BOOL mmi_syncml_is_ascii_format(CHAR *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *p = dest;  
    U8 ansii_max_value = 255;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*p != '\0')
    {
        if (*p < ansii_max_value )
        {
            p++;
        }     
        else
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_exit_install
 * DESCRIPTION
 *  This function will end current install and return to IDLE screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_exit_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Priority of these rsp enum:
     *      ENDKEY > UPDATED > OK > SKIPPED > INVALID */

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__	
    /* When at leaset 1 profile is matched and updated successfully */
    if (g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_UPDATE_MASK)
    {
        mmi_syncml_cca_config_rsp(CCA_STATUS_ENDKEY_SETTING_UPDATED);
    }     
    /* When at lease 1 profile has been installed successfylly and no profile is updated */
    else if ((g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_INSTALL_MASK)
        || (g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_REPLACE_MASK))
#else   /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    if ((g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_INSTALL_MASK)
        || (g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_REPLACE_MASK))
#endif  /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    {
        mmi_syncml_cca_config_rsp(CCA_STATUS_ENDKEY_SETTING_INSTALLED);
    }
    /* When user skipped the installation of all profiles ,causing no profiles installed.*/
    else if (g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_SKIP_MASK)
    {
        mmi_syncml_cca_config_rsp(CCA_STATUS_ENDKEY_SETTING_SKIPPED);
    }
    else
    {
        mmi_syncml_cca_config_rsp(CCA_STATUS_ENDKEY_PRESSED);
    }      
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_display_skip_confirm
 * DESCRIPTION
 *  Display skip confirmation screen, but can goback history to this screen.
 * PARAMETERS
 *  strId           [IN]        Confirmation string.
 *  lskFuncs        [IN]        Left soft key function.
 *  rskFuns         [IN]        Right soft key function.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_display_skip_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_common_cancel_with_sg(GRP_ID_SYNC_OTAP_INSTALL, STR_ID_CCA_SKIP_PROFILE, mmi_syncml_skip_profile_yes);	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_skip_profile_yes
 * DESCRIPTION
 *  Display skip confirmation screen, but can goback history to this screen.
 * PARAMETERS
 *  strId           [IN]        Confirmation string.
 *  lskFuncs        [IN]        Left soft key function.
 *  rskFuns         [IN]        Right soft key function.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_skip_profile_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*	To confirm at least one profile was skipped */
    if (!(g_syncml_ota_context->opr_flag & SYNCML_OTA_OPR_SKIP_MASK))
	{
		g_syncml_ota_context->opr_flag |= SYNCML_OTA_OPR_SKIP_MASK;
	}
    
    mmi_syncml_next_profile();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_construct_cca_document_for_dm
 * DESCRIPTION
 *  This function construct cca document for DM.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_syncml_construct_cca_document_for_dm(void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_get_prof_ind_struct *get_prof;
    mmi_cca_app_get_prof_rsp_struct *data;
	
    S32 hconfig, hroot, hnode ,temnode,connect_type;
	S32 orgin_netid;
    mmi_syncml_account_struct *dm_account = NULL;    
	srv_dtcnt_sim_type_enum sim_id;
    U8 temp[MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH];
    CHAR temp_ip_addr[MAX_SYNCML_PROXY_IP_ADDR_LEN];
    CHAR tempint[10];
    U8 i;
    srv_dtcnt_prof_proxy_info_struct *proxy_info = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_CONSTRUCT_DOC_FOR_DM );
    get_prof = (mmi_cca_app_get_prof_ind_struct *)param;
    MMI_ASSERT(get_prof != NULL);
    
    dm_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
	
    mmi_syncml_read_account_from_nvram((U8)get_prof->prof_id, (void*)dm_account);
    
    hroot = mmi_cca_doc_new_rootnode();
    if (!hroot)
    {
        MMI_ASSERT(0);
    }
	
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PROXY, hroot);
    if (!hnode)
    {
        mmi_cca_docroot_release (hroot); 
        MMI_ASSERT(0);
    }
	
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_NODEID, "PROXY_1");
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PROXY_ID, "PROXY_1");
	temp_ip_addr[0] = 0;

    proxy_info = (srv_dtcnt_prof_proxy_info_struct*)OslMalloc(sizeof(srv_dtcnt_prof_proxy_info_struct));
    
	srv_dtcnt_get_sim_preference(&sim_id);
	if (sim_id == SRV_DTCNT_SIM_TYPE_NONE)
	{
		sim_id = SRV_DTCNT_SIM_TYPE_1;
	}
    srv_dtcnt_get_proxy_info(
        dm_account->net_id[sim_id - 1], 
        proxy_info, 
        SRV_DTCNT_ACCOUNT_PRIMARY);

    for (i = 0; i < 4; i++)
	{
		syncml_itoa((S32) proxy_info->px_addr[i], (CHAR*)tempint, 10);
		strcat(temp_ip_addr,tempint);
		if (i < 3)
		{     
			strcat(temp_ip_addr,".");
		}
	}        
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PXADDR, (CHAR*)temp_ip_addr);
	mmi_cca_doc_add_nodedata_int (hnode, CCA_NS_OMA_PXADDRTYPE, CCA_NS_VAL_IPV4);
	
	g_syncml_ota_use_proxy_flag = (MMI_BOOL)proxy_info->use_proxy;
				
	/* Get the original net id */
	orgin_netid = (S32)cbm_get_original_account(dm_account->net_id[sim_id - 1]);
	mmi_cca_doc_add_nodedata_int (hnode, CCA_NS_DATAACCTID, orgin_netid);   
	
    temnode = hnode;
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PORT, temnode);
	syncml_itoa((S32)proxy_info->px_port, (CHAR*)(tempint), (S32)10);
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PORTNBR, (CHAR*)tempint);
	connect_type = (dm_account->transport_type == SYNCML_TRANS_HTTP) ? CCA_NS_VAL_OTA_HTTP_TO : CCA_NS_VAL_CL_WSP;
	mmi_cca_doc_add_nodedata_int (hnode, CCA_NS_OMA_SERVICE, (S32)connect_type);    
	
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PXAUTHINFO, temnode);
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PXAUTH_ID, (CHAR*)proxy_info->px_authid);    
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PXAUTH_PW, (CHAR*)proxy_info->px_authpw); 
	 
    OslMfree(proxy_info);

    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_APPLICATION, hroot);
    if (!hnode)
    {
        mmi_cca_docroot_release (hroot); 
        MMI_ASSERT(0);
    }
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_NODEID , "APPLICATION_1");
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_APPID, "w5");
	
	mmi_chset_ucs2_to_utf8_string((U8*) temp,                        
		MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH, 
		(U8*)dm_account->account_name);
	
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_NAME ,(CHAR*)temp);
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_TO_PROXY , "PROXY_1");
    temnode = hnode;
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_APPADDR, temnode);  
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_ADDR , (CHAR*)dm_account->server_address);
	
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_APPAUTH, temnode);  
	mmi_cca_doc_add_nodedata_int (hnode,CCA_NS_OMA_AAUTHLEVEL , CCA_NS_VAL_CLIENT);
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_AAUTHNAME , (CHAR*)dm_account->server_username);
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_AAUTHSECRET , (CHAR*)dm_account->server_password);
	
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_RESOURCE, temnode);  
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AACCEPT, (CHAR *)"text/x-vcard");
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_URI, (CHAR*)dm_account->contact_address);
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHNAME, (CHAR*)dm_account->contact_username);
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHSECRET, (CHAR*)dm_account->contact_password);       
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_RESOURCE, temnode);  
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AACCEPT, (CHAR*)"text/x-vcalendar");
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_URI, (CHAR*)dm_account->calendar_address);
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHNAME, (CHAR*)dm_account->calendar_username);
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHSECRET, (CHAR*)dm_account->calendar_password);
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_RESOURCE, temnode);  
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AACCEPT, (CHAR*)"text/x-vtodo");
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_URI, (CHAR*)dm_account->task_address);
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHNAME, (CHAR*)dm_account->task_username);
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHSECRET, (CHAR*)dm_account->task_password);
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
	hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_RESOURCE, temnode);  
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AACCEPT, (CHAR*)"text/plain");
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_URI, (CHAR*)dm_account->note_address);
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHNAME, (CHAR*)dm_account->note_username);
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHSECRET, (CHAR*)dm_account->note_password);
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
	
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */
	
    hconfig = mmi_cca_doc_new (hroot);
	
    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_get_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_get_prof_rsp_struct));
	
    data->sim_id = (U16)syncml_ota_sim_cbm2cca(cbm_get_sim_id(dm_account->net_id[sim_id - 1]));
	
    data->app_id = get_prof->app_id;
    data->prof_id = get_prof->prof_id; 
    data->hConfig = hconfig;
    data->result = CCA_STATUS_OK;
	
    /* Send the response message. */
    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_GET_PROF_RSP, (oslParaType*) data, NULL);
    
    MMI_PRINT(
        MOD_MMI_CONN_APP, 
        MMI_CONN_TRC_G2_SYNCML, 
        "server_addr = %s, contact_addr = %s, calendar_addr = %s", 
        dm_account->server_address,
        dm_account->contact_address,
        dm_account->calendar_address);
	
    OslMfree(dm_account);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_install_cca_document_from_dm
 * DESCRIPTION
 *  This function install the new setting into NVRAM from DM.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_syncml_install_cca_document_from_dm(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_update_prof_ind_struct *update_prof;
    mmi_cca_app_update_prof_rsp_struct *data;
    mmi_syncml_account_struct* new_prof;
    mmi_syncml_account_struct *tmp_nvram = NULL;
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_INSTALL_DOC_FROM_DM);
    update_prof = (mmi_cca_app_update_prof_ind_struct *)param;
    MMI_ASSERT(update_prof != NULL);
    
    g_syncml_ota_context = mmi_syncml_new_ota_cntx(0, update_prof->hConfig); 
    
    data = (mmi_cca_app_update_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_update_prof_rsp_struct));
	/* set dm-update flag */
	g_syncml_ota_context->opr_flag |= SYNCML_OTA_OPR_DM_UPDATE_MASK;
		
    mmi_cca_doc_process(update_prof->hConfig, 
                        mmi_cca_syncml_map_tbl,
                        sizeof(mmi_cca_syncml_map_tbl) / sizeof(U16),
                        NULL, 
                        mmi_syncml_proc_cca_nodes, 
                        g_syncml_ota_context);

    if (mmi_syncml_get_valid_profile_num() == 0) 
    {
        data->result = CCA_STATUS_INVALID_SETTING;
    }
    else
    {   
        tmp_nvram = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));

        new_prof = g_syncml_ota_context->profile[0];
 
        MMI_PRINT(
            MOD_MMI_CONN_APP, 
            MMI_CONN_TRC_G2_SYNCML, 
            "mmi_syncml_install_cca_document_from_dm => server_addr = %s, contact_addr = %s, calendar_addr = %s", 
            new_prof->server_address,
            new_prof->contact_address,
            new_prof->calendar_address);
             
        new_prof->account_id = update_prof->prof_id; 
        
        mmi_syncml_read_account_from_nvram((U8)update_prof->prof_id, (void*)tmp_nvram);
		/*
		 * <1>
		 *     If the profile name has been changed, clear the PROVURL and ID hash buffer.
		 *     CCA spec 12.3.1
		 * <2>
		 *	   The three hash buffers won't be taken by cca doc construction for dm
		 * 		to avoid hash the buffer again.
		 */
		 
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
		if (mmi_ucs2cmp((CHAR*)new_prof->account_name, (CHAR*)tmp_nvram->account_name) != 0)
		{
			memcpy(new_prof->prov_url_hash, "\0", 1);
			memcpy(new_prof->proxy_id_hash, "\0", 1);
		}
		else
		{
			memcpy(new_prof->prov_url_hash, tmp_nvram->prov_url_hash, MAX_SYNCML_HASH_BUF_LEN);
			memcpy(new_prof->proxy_id_hash, tmp_nvram->proxy_id_hash, MAX_SYNCML_HASH_BUF_LEN);
		}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

        /* save old account setting */
        new_prof->app_to_sync = tmp_nvram->app_to_sync;  
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
        new_prof->sync_type = tmp_nvram->sync_type;   
#endif
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#endif
        new_prof->regular_sync = tmp_nvram->regular_sync;  
        
        new_prof->sync_report_status = tmp_nvram->sync_report_status; 

        /* update global variables */
        g_mmi_syncml_cntx.account_validation[update_prof->prof_id - 1] = new_prof->account_validation; 

        g_mmi_syncml_cntx.regular_sync_notify[update_prof->prof_id - 1] = 0;

        mmi_ucs2cpy((CHAR*)g_mmi_syncml_cntx.account_name_display[update_prof->prof_id - 1], (CHAR*)new_prof->account_name);

        OslMfree(tmp_nvram);

        WriteRecord(NVRAM_EF_SYNCML_ACCOUNT_LID,
                    (U8)(update_prof->prof_id), 
                    (void*)new_prof,
                    NVRAM_EF_SYNCML_ACCOUNT_SIZE, 
                    &error);
               
        if (error != NVRAM_WRITE_SUCCESS) 
        {
            MMI_ASSERT(0);
        }
        data->result = CCA_STATUS_OK;
    }

	mmi_syncml_free_syncml_ota_cntx();
    
	g_syncml_ota_use_proxy_flag = MMI_FALSE;

    data->sim_id = update_prof->sim_id;
    data->app_id = update_prof->app_id;
    data->prof_id = update_prof->prof_id;
    data->hConfig = update_prof->hConfig;
        
    /* Send the response message. */
    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_UPDATE_PROF_RSP, (oslParaType*) data, NULL);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_checking_for_dm
 * DESCRIPTION
 *  This function used to check whether hanset can receive the new setting from DM.
 * PARAMETERS
 *  void
 * RETURNS
 *  0,1
 *****************************************************************************/
S32 mmi_syncml_checking_for_dm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_SYNC_MAIN) || mmi_syncml_is_sync_now())
    {
        return 0x0;
    }
    else
    {
        return 0x1;
    }
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_cca_app_cfg_rsp
 * DESCRIPTION
 *  rsp to cca
 * PARAMETERS
 *  status  cca_status_enum
 * RETURNS
 *  void 
 *****************************************************************************/
static void mmi_syncml_cca_config_rsp(cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_configure_rsp_struct *data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_configure_rsp_struct *)OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));

    data->sim_id = (U16)syncml_ota_sim_cbm2cca((cbm_sim_id_enum)g_syncml_ota_context->sim_id);
    data->config_id = g_syncml_ota_context->conf_id;
    data->hConfig   = g_syncml_ota_context->doc_hdl;
    data->status    = status;  

    /* Send the response message. */
    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_CONFIGURE_RSP, (oslParaType*) data, NULL);
}


#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_update_match
 * DESCRIPTION
 *  Only update the first matched profile.
 * PARAMETERS
 *  mmi_syncml_account_struct		[IN]		new profile  
 * RETURNS
 *  U8 profile id 
 *****************************************************************************/
static U8 mmi_syncml_is_update_match(mmi_syncml_account_struct *new_prof, void* usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_ota_cntx_struct *cntx;
    mmi_syncml_account_struct *tmp_prof = NULL;
	MMI_BOOL match_flag = MMI_FALSE;
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(new_prof != NULL && usr_data != NULL);
	cntx = (mmi_syncml_ota_cntx_struct*)usr_data;
	
	if (strlen((CHAR*)cntx->prov_url_hash) == 0 &&
		strlen((CHAR*)new_prof->proxy_id_hash) == 0)
	{	
		return SYNCML_INVALID_IDX;
	}
    
	tmp_prof = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    
	/* Only update the first matched profile */
	for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
	{
		/* The old profile is empty */
		if (mmi_syncml_is_empty_profile(i))
		{
			continue;
		}

        mmi_syncml_read_account_from_nvram((U8)(i + 1), (void*)tmp_prof);
		
        /* Any one is empty, don't match */
		if (strlen((CHAR*)tmp_prof->prov_url_hash) == 0 || strlen((CHAR*)cntx->prov_url_hash) == 0)
		{
			continue;
		}
			
		/* check prov url */
		if (memcmp(tmp_prof->prov_url_hash, cntx->prov_url_hash, sizeof(U8) * MAX_SYNCML_HASH_BUF_LEN) != 0)
		{
			continue;
		}
		
		/* New ID is the same the old one and both are valid ? */
		if (strlen((CHAR*)tmp_prof->proxy_id_hash) > 0 && 
			strlen((CHAR*)new_prof->proxy_id_hash) > 0 && 
			memcmp(tmp_prof->proxy_id_hash, new_prof->proxy_id_hash, sizeof(U8) * MAX_SYNCML_HASH_BUF_LEN) == 0)
		{
			match_flag = MMI_TRUE;
		}
		/* Old ID is invalid? */
		else if ((strlen((CHAR*)tmp_prof->proxy_id_hash) > 0))
		{
			continue;
		}
		/* Name match? */
		else if (mmi_ucs2strlen((CHAR*)tmp_prof->account_name) > 0 &&
				 mmi_ucs2strlen((CHAR*)new_prof->account_name) > 0 &&
			     mmi_ucs2cmp((CHAR*)tmp_prof->account_name, (CHAR*)new_prof->account_name) == 0)
		{
			match_flag = MMI_TRUE;
		}
		else
		{
			/* nothing */
			continue;
		}
		
		if (match_flag)
		{
			if (tmp_prof->type != MMI_SYNCML_ACCOUNT_TYPE_FACTORY)
			{
                OslMfree(tmp_prof);
				return i;
			}
			/* factory preconfigured and the flag in prov_flag indicate the SEC type is USERNETWPIN */
			else if (g_syncml_ota_context->prov_flag & MMI_CCA_PROV_FLAG_FACTORY_PROFILE_UPDATABLE)
			{
			    if (tmp_prof != NULL)
                {
                    OslMfree(tmp_prof);
                }
				return i;
			}
			else
			{
				break;
			}
		}
	}
    
    if (tmp_prof != NULL)
    {
        OslMfree(tmp_prof);
    }

	return SYNCML_INVALID_IDX;
}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_db_type
 * DESCRIPTION
 *  Get data base name
 * PARAMETERS
 *  db_name		[IN]	  the incoming db name
 * RETURNS
 *  U8			db type		SYNCML_DB_CALENDAR or SYNCML_DB_TASK
 *****************************************************************************/
static U8 mmi_syncml_get_db_type(const CHAR* db_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
	for (i = 0; i < MMI_SYNCML_OTA_CAL_NAME_TOTAL; i++)
	{
		if (mmi_syncml_stristr(db_name, mmi_syncml_cal_dbname[i]) != NULL)
		{
		    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_GET_CALENDAR_TYPE);
			return SYNCML_DB_CALENDAR;
		}
	}
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
	for (i = 0; i < MMI_SYNCML_OTA_TASK_NAME_TOTAL; i++)
	{
		if (mmi_syncml_stristr(db_name, mmi_syncml_task_dbname[i]) != NULL)
		{
		    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_OTAP_GET_TASK_TYPE);
			return SYNCML_DB_TASK;
		}
	}
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

	return 0;	
}


/*****************************************************************************
 * FUNCTION
 *  syncml_stristr
 * DESCRIPTION
 *  This function performs strstr in case-insensitive way.
 * PARAMETERS
 *  src_str     [IN]        Source string
 *  tbf_str     [IN]        String to be found
 * RETURNS
 *  NULL: not found
 *  non-NULL: pointer of 1st found substring
 *****************************************************************************/
static CHAR* mmi_syncml_stristr(const CHAR *src_str, const CHAR *tbf_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 match_flag = 0;   /* reset */
    S32 i = 0;            /* reset */
    S32 j = 0;            /* reset */
    S32 reset_i = -1;     /* reset */
    S32 left, left_fixed;
    CHAR s1, s2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src_str || !tbf_str || !strlen(tbf_str) || !strlen(src_str) || strlen(tbf_str) > strlen(src_str))
    {
        return NULL;
    }

    left = left_fixed = strlen(tbf_str);

    while (*(src_str + i) && *(tbf_str + j) && left)
    {
        /* both convert to lower case */
        s1 = (CHAR) (islower((S32) * (src_str + i)) ? *(src_str + i) : tolower((S32) * (src_str + i)));
        s2 = (CHAR) (islower((S32) * (tbf_str + j)) ? *(tbf_str + j) : tolower((S32) * (tbf_str + j)));

        if (s1 != s2)
        {
            if (reset_i >= 0)
            {
                i = reset_i + 1;
                reset_i = -1;
            }
            else
            {
                i++;
            }

            j = 0;
            match_flag = 0;
            left = left_fixed;
        }
        else
        {
            if (match_flag == 0)
            {
                /* 1st matched */
                reset_i = i;
                match_flag = 1;
            }

            i++;
            j++;
            left--;
        }
    }

    if (left == 0)
    {
        /* return 1st matched substring */
        return (CHAR*) src_str + i - left_fixed;
    }

    return NULL;
}


#endif /* __MMI_SYNCML_CCA_SUPPORT__ */

